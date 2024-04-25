// --------------------------------------------------------------------------
// |              _    _ _______     .----.      _____         _____        |
// |         /\  | |  | |__   __|  .  ____ .    / ____|  /\   |  __ \       |
// |        /  \ | |  | |  | |    .  / __ \ .  | (___   /  \  | |__) |      |
// |       / /\ \| |  | |  | |   .  / / / / v   \___ \ / /\ \ |  _  /       |
// |      / /__\ \ |__| |  | |   . / /_/ /  .   ____) / /__\ \| | \ \       |
// |     /________\____/   |_|   ^ \____/  .   |_____/________\_|  \_\      |
// |                              . _ _  .                                  |
// --------------------------------------------------------------------------
//
// All Rights Reserved.
// Any use of this source code is subject to a license agreement with the
// AUTOSAR development cooperation.
// More information is available at www.autosar.org.
//
// Disclaimer
//
// This work (specification and/or software implementation) and the material
// contained in it, as released by AUTOSAR, is for the purpose of information
// only. AUTOSAR and the companies that have contributed to it shall not be
// liable for any use of the work.
//
// The material contained in this work is protected by copyright and other
// types of intellectual property rights. The commercial exploitation of the
// material contained in this work requires a license to such intellectual
// property rights.
//
// This work may be utilized or reproduced without any modification, in any
// form or by any means, for informational purposes only. For any other
// purpose, no part of the work may be utilized or reproduced, in any form
// or by any means, without permission in writing from the publisher.
//
// The work has been developed for automotive applications only. It has
// neither been developed, nor tested for non-automotive applications.
//
// The word AUTOSAR and the AUTOSAR logo are registered trademarks.
// --------------------------------------------------------------------------

/**
 * \file
 */

#ifndef VSOMEIP_PROXY_EVENT_IMPL_H
#define VSOMEIP_PROXY_EVENT_IMPL_H

#include <mutex>
#include <deque>
#include <stdexcept>
#include <cstddef>
#include <algorithm>
#include <vsomeip/vsomeip.hpp>
#include <vsomeip/enumeration_types.hpp>

#include "vsomeip_method_impl.h"
#include "make_method_descriptor_from.h"

#include "ara/com/internal/proxy/event_data_container.h"
#include "ara/com/internal/proxy/field.h"
#include "ara/com/types.h"
#include "ara/com/internal/vsomeip/vsomeip_types.h"
#include "ara/com/internal/vsomeip/vsomeip_marshalling.h"

#include <ara/com/e2exf/status_handler.h>
#include "ara/com/e2e/e2e_types.h"

#include "ara/com/com_error_domain.h"
#include "ara/core/result.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace vsomeip
{
namespace proxy
{
/// \addtogroup vsomeipproxyimpl
///@{

/// \brief Event implementation for proxy interface
template <typename EventDescriptor, typename T>
class EventImpl : public virtual internal::proxy::Event<T>
{
public:
    using const_reference = typename internal::proxy::Event<T>::const_reference;
    using value_type = typename internal::proxy::Event<T>::value_type;
    using pointer_type = typename internal::proxy::Event<T>::pointer_type;  // SamplePtr<T>
    using container_value_type = typename internal::proxy::Event<T>::container_value_type;
    using new_samples_callback = typename internal::proxy::Event<T>::NewSamplesCallback;

    /// constructor
    explicit EventImpl(types::InstanceId instance_id)
        : instance_id_(instance_id)
        , checkResult_{}
        , checkSMState_{ara::com::e2e::SMState::kNoData}
        , subscriptionState_(ara::com::SubscriptionState::kNotSubscribed)
    { }

    /// virtual destructor
    virtual ~EventImpl()
    { }

    /// @uptrace{SWS_CM_00141, 3e130e46499d6d859ac16f82375bc20a1cd7d907}
    virtual ara::core::Result<void> Subscribe(std::size_t maxSampleCount) override
    {
        return DoSubscribe(maxSampleCount, false);
    }

    virtual bool IsSubscribed() const override
    {
        return subscriptionState_ == ara::com::SubscriptionState::kSubscribed;
    }

    /// @uptrace{SWS_CM_00316, d18cf84f0dce6bd2c850dafaa6aec7ff2d7bd649}
    virtual ara::com::SubscriptionState GetSubscriptionState() const override
    {
        return subscriptionState_;
    }

    /// @uptrace{SWS_CM_00151, 8c254acbfe32fd3de626f8203cbf01da37f6823c}
    virtual void Unsubscribe() override
    {
        common::abort(!common::isEventUndefined(EventDescriptor::event_id));

        runtime::VSomeIPConnection& connection = runtime::VSomeIPConnection::getInstance();
        ::vsomeip::application& app = connection.getApplication();
        app.unsubscribe(EventDescriptor::service_id, instance_id_, *std::begin(EventDescriptor::event_groups));
        app.release_event(EventDescriptor::service_id, instance_id_, EventDescriptor::event_id);
        app.unregister_message_handler(EventDescriptor::service_id, instance_id_, EventDescriptor::event_id);
        app.unregister_subscription_error_handler(
            EventDescriptor::service_id, instance_id_, *std::begin(EventDescriptor::event_groups));

        setSubscriptionState(ara::com::SubscriptionState::kNotSubscribed);

        // Clear caches to
        // 1. save memory and
        // 2. ensure that they're not bigger than cache_size on the next call of Subscribe.
        Cleanup();
    }

    /// @uptrace{SWS_CM_00181, c211a486c8d232b8959e6b9cc60583c4ba889b00}
    /// @uptrace{SWS_CM_00309, 8a0cb42b9da93e91a92c5276a6575d3cec747f17}
    virtual void SetReceiveHandler(ara::com::EventReceiveHandler handler) override
    {
        std::lock_guard<std::mutex> guard(lock_);
        receive_handler_ = handler;
    }

    /// @uptrace{SWS_CM_00183, 0cf46011bd4f414c25ba25add99c817d17423c6b}
    virtual void UnsetReceiveHandler() override
    {
        std::lock_guard<std::mutex> guard(lock_);
        receive_handler_ = nullptr;
    }

    virtual void SetSubscriptionStateChangeHandler(ara::com::SubscriptionStateChangeHandler handler) override
    {
        std::lock_guard<std::mutex> guard(lock_);
        state_change_handler_ = handler;
    }

    virtual void UnsetSubscriptionStateChangeHandler() override
    {
        std::lock_guard<std::mutex> guard(lock_);
        state_change_handler_ = nullptr;
    }

    /// \brief Update the event cache with the meanwhile received data samples
    /// @uptrace{SWS_CM_90406, 9ddc86d24fde6c43d90b9569ba1c2672e88909fa}
    /// @uptrace{SWS_CM_90407, c5aad7c500ce3e9a6cccfe2f7652c02f0930bbd4}
    /// @uptrace{SWS_CM_90408, a4611304e831017aaf1328d2a1712f427772a113}
    /// @uptrace{SWS_CM_90410, 347baacbdeafae48ac8747e91cce866646205f10}
    /// @uptrace{SWS_CM_90411, 9976d035dab40f3827aa7efa81621a6c10dd8b58}
    /// @uptrace{SWS_CM_90412, da4e4d5e848dfd91ad305ef357e77ebaccd0cbd9}
    /// @uptrace{SWS_CM_90413, 12c1b9d681f0a59436d7c3d8bd2e33a43a7a1072}
    /// @uptrace{SWS_CM_90415, 6e72c055adb3431d70170989163d6c036b667d69}
    /// @uptrace{SWS_CM_90417, 649f052f9e6eee3454fb8de9cf6a398ffbabdcd1}
    /// @uptrace{SWS_CM_00701, d32ab6ff0ba8ee038f6ee578fe05d666cde6e2c6}
    /// @uptrace{SWS_CM_00703, 96bc7af3a14d08864dac251fd3e2f8c1dc0d1cd2}
    /// @uptrace{SWS_CM_00704, 9155c846685608ed3dc0c62076d0b5d20ee81ef8}
    /// @uptrace{SWS_CM_00714, 1d5af3d0fa3679ef39999c0a7df89a29ff7578ff}
    ara::core::Result<size_t> GetNewSamples(new_samples_callback&& f,
        size_t maxNumberOfSamples = std::numeric_limits<size_t>::max()) override
    {
        common::abort(!common::isEventUndefined(EventDescriptor::event_id));

        if (working_set_.AvailableSize() == 0) {
            return ara::core::Result<size_t>::FromError(ara::com::ComErrorDomainErrc::kMaxSamplesExceeded);
        }

        // guard underlying receive buffer: queue_
        std::unique_lock<std::mutex> lock(lock_);

        if (queue_.empty()) {
            checkResult_ = e2exf::StatusHandler::HandleCheckStatus(EventDescriptor::service_id,
                instance_id_,
                EventDescriptor::event_id,
                ara::com::e2e::ProfileCheckStatus::kNoNewData);
        }

        size_t remainingNumberOfSamplesToProcess = std::min(queue_.size(), maxNumberOfSamples);
        size_t passedToUserSamplesNumber = 0;

        lock.unlock();

        while (remainingNumberOfSamplesToProcess > 0) {
            SamplePtr<const value_type> deserializedSample;
            // guard underlying receive buffer: queue_
            lock.lock();
            // check against emptiness of queue_ because unsunscribe could clear it
            // during the callback invocation
            if (!queue_.empty()) {
                // get next received event data sample from underlying receive buffers
                auto rawDataSample = queue_.front();
                // deserialize the data, if needed
                const auto checkResult = rawDataSample->is_valid_crc() ? ara::com::e2e::ProfileCheckStatus::kOk
                                                                       : ara::com::e2e::ProfileCheckStatus::kError;
                checkResult_ = e2exf::StatusHandler::HandleCheckStatus(
                    EventDescriptor::service_id, instance_id_, EventDescriptor::event_id, checkResult);
                checkSMState_ = checkResult_.smState;
                const ::vsomeip::payload& payload = *rawDataSample->get_payload();
                common::Deserializer<value_type> deserializer(payload.get_data(), payload.get_length());
                // place the deserialized data sample of type SampleType in the local cache
                deserializedSample = working_set_.Add(deserializer.getValue(), checkResult_.profileCheckStatus);
                // raw data sample is not needed anymore if deserialization and storing went well
                if (deserializedSample) {
                    queue_.pop_front();
                }
                // lock is not needed for the callback invocation
                // and could block possible data reception by onMessage method
            } else {
                // queue_ is empty
                break;
            }
            lock.unlock();
            // call user provided f with a SamplePtr (including ProfileCheckStatus)
            // referencing the data sample located in local cache
            if (deserializedSample) {
                f(std::move(deserializedSample));
                passedToUserSamplesNumber++;
                remainingNumberOfSamplesToProcess--;
            } else {
                // max number of samples has been reached
                break;
            }
        }

        return passedToUserSamplesNumber;
    }

    /// @uptrace{SWS_CM_00705, 0c4f947931c51b8f81d4eefa504425b336752ade}
    /// @uptrace{SWS_CM_00706, d1f8027ac08f37fac3c7ddfcff3beeb7ad271dd1}
    virtual size_t GetFreeSampleCount() override
    {
        return working_set_.AvailableSize();
    }

protected:
    /// \brief Subsribe events to vsomeip.
    /// \param cache_size Set the local cache size
    /// \param is_field If it is a field or not
    ara::core::Result<void> DoSubscribe(std::size_t cache_size, bool is_field)
    {
        if (common::isEventUndefined(EventDescriptor::event_id)) {
            common::logger().LogError() << "Undefined event_id";
            return ara::core::Result<void>::FromError({ara::com::ComErrorDomainErrc::kNetworkBindingFailure});
        }

        if (cache_size < 1) {
            common::logger().LogError() << "cache_size must be at least 1";
            return ara::core::Result<void>::FromError({ara::com::ComErrorDomainErrc::kBadArguments});
        }

        setSubscriptionState(ara::com::SubscriptionState::kSubscriptionPending);

        cache_size_ = cache_size;
        working_set_.Reserve(cache_size);

        runtime::VSomeIPConnection& connection = runtime::VSomeIPConnection::getInstance();
        ::vsomeip::application& app = connection.getApplication();
        app.request_event(EventDescriptor::service_id,
            instance_id_,
            EventDescriptor::event_id,
            {std::begin(EventDescriptor::event_groups), std::end(EventDescriptor::event_groups)},
            is_field);
        app.register_subscription_error_handler(EventDescriptor::service_id,
            instance_id_,
            *std::begin(EventDescriptor::event_groups),
            [this](const uint16_t status) { onSubscriptionStateHandler(status); });
        app.subscribe(EventDescriptor::service_id,
            instance_id_,
            *std::begin(EventDescriptor::event_groups),
            EventDescriptor::service_version_major,
            ::vsomeip::subscription_type_e::SU_RELIABLE_AND_UNRELIABLE,
            EventDescriptor::event_id);
        app.register_message_handler(EventDescriptor::service_id,
            instance_id_,
            EventDescriptor::event_id,
            [this](const std::shared_ptr<::vsomeip::message>& msg) { onMessage(msg); });

        return {};
    }

private:
    ara::com::e2e::Result DoCheckResult() const noexcept override
    {
        return checkResult_;
    }
    ara::com::e2e::SMState DoCheckSMState() const noexcept
    {
        return checkSMState_;
    }
    types::InstanceId instance_id_;

    ara::com::e2exf::StatusHandler e2e_status_handler_;
    ara::com::e2e::Result checkResult_;
    ara::com::e2e::SMState checkSMState_;

    using MessagePtr = std::shared_ptr<::vsomeip::message>;
    using MessageQueue = std::deque<MessagePtr>;

    MessageQueue queue_;
    internal::proxy::EventDataContainer<T> working_set_;
    std::mutex lock_;
    ara::com::EventReceiveHandler receive_handler_;
    ara::com::SubscriptionStateChangeHandler state_change_handler_;
    ara::com::SubscriptionState subscriptionState_;
    std::size_t cache_size_{1};
#ifndef ARA_COM_LEAN
    std::size_t num_overflow_{0};
#endif

    /// @uptrace{SWS_CM_10292, 381416fd4b92a354b9bab0de94a9626f33105a98}
    /// @uptrace{SWS_CM_10291, 97ac700f0c560844a92aaa8b450a2118bb371628}
    /// @uptrace{SWS_CM_10324, 07f7c57d4d178317db2b7a15961d4957534093d4}
    virtual bool validateMessage(const ::vsomeip::message& msg)
    {
        bool result = common::checkMessageMetaData(msg,
            EventDescriptor::service_id,
            EventDescriptor::event_id,
            EventDescriptor::service_version_major,
            ::ara::com::internal::vsomeip::types::MessageTypeEvent);

        if (msg.get_client() != types::EventClientID) {
            result = false;
            common::logger().LogWarn() << "Incorrect client id: '" << +uint8_t(msg.get_client()) << "', should be "
                                       << +uint8_t(types::EventClientID);
        }
        return result;
    }

    void onMessage(const std::shared_ptr<::vsomeip::message>& response)
    {
        ara::com::EventReceiveHandler receive_handler;
        {
            std::unique_lock<std::mutex> lock(lock_);

            if (validateMessage(*response)) {
                // this line prevents queue from growing beyond the configured cache size. If this is true, data will be
                // lost.
                if (queue_.size() > 0 && cache_size_ == queue_.size()) {
                    queue_.pop_front();
#ifndef ARA_COM_LEAN
                    ++num_overflow_;
#endif
                }
                queue_.push_back(response);

                // fetch the handler inside the lock to prevent a race when another thread changes the receive handler
                receive_handler = receive_handler_;
            } else {
                common::logger().LogWarn() << "Discarding invalid message";
            }
        }

        if (receive_handler) {
            receive_handler();
        }
    }

    void onSubscriptionStateHandler(const uint16_t status)
    {
        if (status == types::kEventSubscribeAck) {
            setSubscriptionState(ara::com::SubscriptionState::kSubscribed);
        } else {
            setSubscriptionState(ara::com::SubscriptionState::kNotSubscribed);
        }
    }

    void setSubscriptionState(ara::com::SubscriptionState state)
    {
        subscriptionState_ = state;
        std::unique_lock<std::mutex> lock(lock_);
        ara::com::SubscriptionStateChangeHandler state_change_handler = state_change_handler_;
        lock.unlock();
        if (state_change_handler) {
            state_change_handler(state);
        }
    }

    void Cleanup()
    {
        std::lock_guard<std::mutex> guard(lock_);
        queue_.clear();
    }
};

///@}

}  // namespace proxy
}  // namespace vsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // VSOMEIP_PROXY_EVENT_IMPL_H
