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

#ifndef ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_PROXY_EVENT_IMPL_H_
#define ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_PROXY_EVENT_IMPL_H_

#include <mutex>
#include <numeric>
#include <deque>

#include "ara/core/result.h"
#include "ara/core/vector.h"

#include "ara/com/com_error_domain.h"
#include "ara/com/internal/proxy/event.h"
#include "ara/com/internal/proxy/event_data_container.h"
#include "ara/com/internal/dds_idl/common.h"
#include "ara/com/internal/dds_idl/domain_participant.h"
#include "ara/com/e2e/e2e_types.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace dds
{
namespace proxy
{

/// \brief Event implementation for proxy interface
template <typename EventDescriptor, typename T>
class EventImpl : public virtual internal::proxy::Event<T>
{
public:
    using const_reference = typename internal::proxy::Event<T>::const_reference;
    using value_type = typename internal::proxy::Event<T>::value_type;
    using const_value_type = typename internal::proxy::Event<T>::const_value_type;
    using pointer_type = typename internal::proxy::Event<T>::pointer_type;
    using container_value_type = typename internal::proxy::Event<T>::container_value_type;
    using descriptor_type = EventDescriptor;
    using new_samples_callback = typename internal::proxy::Event<T>::NewSamplesCallback;

    /// \brief constructor
    EventImpl(types::InstanceId instanceId, common::HandleInfo handle)
        : instanceId_(instanceId)
        , handle_(handle)
    { }

    /// \brief virtual destructor
    virtual ~EventImpl()
    {
        Unsubscribe();
    }

    /// @uptrace{SWS_CM_11027, db2edee7bdda78e559b0f03630d43c9043072521}
    void SetSubscriptionStateChangeHandler(ara::com::SubscriptionStateChangeHandler handler) override
    {
        subscriptionChangeHandler_ = handler;
        std::lock_guard<std::mutex> lock(readerLock_);
        if (reader_) {
            reader_->SetSubscriptionStateChangeHandler(subscriptionChangeHandler_);
        }
    }

    /// @uptrace{SWS_CM_11028, c2646d40f77cc2f1bf1eb4007ad8314ab8e1ca14}
    void UnsetSubscriptionStateChangeHandler() override
    {
        subscriptionChangeHandler_ = ara::com::SubscriptionStateChangeHandler();
        std::lock_guard<std::mutex> lock(readerLock_);
        if (reader_) {
            reader_->UnsetSubscriptionStateChangeHandler();
        }
    }

    /// @uptrace{SWS_CM_00181, c211a486c8d232b8959e6b9cc60583c4ba889b00}
    /// @uptrace{SWS_CM_00309, 8a0cb42b9da93e91a92c5276a6575d3cec747f17}
    /// @uptrace{SWS_CM_11025, 94101a3268db53f00b0e8579d4e5fd5f12baf611}
    void SetReceiveHandler(ara::com::EventReceiveHandler handler) override
    {
        receiveHandler_ = handler;
        std::lock_guard<std::mutex> lock(readerLock_);
        if (reader_) {
            reader_->SetReceiveHandler(receiveHandler_);
        }
    }

    /// @uptrace{SWS_CM_00183, 0cf46011bd4f414c25ba25add99c817d17423c6b}
    /// @uptrace{SWS_CM_11026, c2ca349f9acbb2f515f602d6c9c3bbcc1bfd781f}
    void UnsetReceiveHandler() override
    {
        receiveHandler_ = ara::com::EventReceiveHandler();
        std::lock_guard<std::mutex> lock(readerLock_);
        if (reader_) {
            reader_->UnsetReceiveHandler();
        }
    }

    /// @uptrace{SWS_CM_00316, d18cf84f0dce6bd2c850dafaa6aec7ff2d7bd649}
    /// @uptrace{SWS_CM_11022, aa9a167c515f70c64ad0b156224cd61486c3f8cd}
    ara::com::SubscriptionState GetSubscriptionState() const override
    {
        std::lock_guard<std::mutex> lock(readerLock_);
        if (!reader_) {
            return ara::com::SubscriptionState::kNotSubscribed;
        }

        return reader_->GetSubscriptionState();
    }

    bool IsSubscribed() const override
    {
        return GetSubscriptionState() == ara::com::SubscriptionState::kSubscribed;
    }

    /// @uptrace{SWS_CM_00141, 3e130e46499d6d859ac16f82375bc20a1cd7d907}
    /// @uptrace{SWS_CM_00700, debe480717cbc9931093b01bf00e2a5891a535dd}
    /// @uptrace{SWS_CM_11018, 05a187b5e8bcee8f1c7e619e9902325cdf6107fd}
    /// @uptrace{SWS_CM_11019, 5d377bd8ec9f9c428df6d19ea3b9f60630cf911c}
    /// @uptrace{SWS_CM_11133, 88570f6fed97ef5b5766a1183aaa6f144d3012c6}
    /// @uptrace{SWS_CM_11134, 072ea83e588c838be190e3df3e42a6f9ff3bade7}
    virtual ara::core::Result<void> Subscribe(std::size_t maxSampleCount) override
    {
        if (maxSampleCount < 1) {
            common::logger().LogError() << "cache_size must be at least 1";
            return ara::core::Result<void>::FromError({ara::com::ComErrorDomainErrc::kBadArguments});
        }
        samplesCache_.Reserve(maxSampleCount);

        auto topic = handle_.participant->GetTopic<value_type>(descriptor_type::topic_name);
        if (!topic) {
            common::logger().LogError() << "proxy::EventImpl::Subscribe(): topic get failed";
            return ara::core::Result<void>::FromError({ara::com::ComErrorDomainErrc::kNetworkBindingFailure});
        }

        std::lock_guard<std::mutex> lock(readerLock_);
        reader_ = handle_.subscriber->GetEventDataReader(topic, descriptor_type::qos_profile, maxSampleCount);
        if (!reader_) {
            common::logger().LogError() << "proxy::EventImpl::Subscribe(): reader get failed";
            return ara::core::Result<void>::FromError({ara::com::ComErrorDomainErrc::kNetworkBindingFailure});
        }

        if (subscriptionChangeHandler_) {
            reader_->SetSubscriptionStateChangeHandler(subscriptionChangeHandler_);
        }

        if (receiveHandler_) {
            reader_->SetReceiveHandler(receiveHandler_);
        }
        return {};
    }

    /// @uptrace{SWS_CM_00151, 8c254acbfe32fd3de626f8203cbf01da37f6823c}
    /// @uptrace{SWS_CM_11021, 1c898aa7f2db7d98a9102ec639595c3a48f2f557}
    void Unsubscribe() override
    {
        std::lock_guard<std::mutex> lock(readerLock_);
        reader_ = nullptr;
    }

    /// @uptrace{SWS_CM_00701, d32ab6ff0ba8ee038f6ee578fe05d666cde6e2c6}
    /// @uptrace{SWS_CM_00703, 96bc7af3a14d08864dac251fd3e2f8c1dc0d1cd2}
    /// @uptrace{SWS_CM_00704, 9155c846685608ed3dc0c62076d0b5d20ee81ef8}
    /// @uptrace{SWS_CM_11023, 491ddca91e9f3b48ee575f7cb0ab12e6112f31ee}
    /// @uptrace{SWS_CM_11138, f04e0b4942887b12d8946a9493db01c356b4ea34}
    ara::core::Result<size_t> GetNewSamples(new_samples_callback&& f,
        size_t maxNumberOfSamples = std::numeric_limits<size_t>::max()) override
    {
        if (!samplesCache_.AvailableSize()) {
            return ara::core::Result<size_t>::FromError(ara::com::ComErrorDomainErrc::kMaxSamplesExceeded);
        }

        size_t toReadNumber = std::min(samplesCache_.AvailableSize(), maxNumberOfSamples);
        size_t passedToUserSamplesNumber = 0;

        std::unique_lock<std::mutex> lock(readerLock_);
        if (reader_) {
            auto samples = reader_->Read(toReadNumber);
            lock.unlock();
            for (auto& sample : samples) {
                auto data = ConvertFromIdl(sample.data);
                auto dataPtr = samplesCache_.Add(data, ara::com::e2e::ProfileCheckStatus::kCheckDisabled);
                if (dataPtr) {
                    f(std::move(dataPtr));
                    passedToUserSamplesNumber++;
                }
            }
        } else {
            lock.unlock();
        }

        return passedToUserSamplesNumber;
    }

    /// @uptrace{SWS_CM_00705, 0c4f947931c51b8f81d4eefa504425b336752ade}
    /// @uptrace{SWS_CM_00706, d1f8027ac08f37fac3c7ddfcff3beeb7ad271dd1}
    /// @uptrace{SWS_CM_00707, 4b2f0ab663f533d8c96336bf1d6b69b9ebe85866}
    /// @uptrace{SWS_CM_11024, 12a44e6ea67f12da64edc5210e94d3c5ee51cfa3}
    /// @uptrace{SWS_CM_11139, 9cca31b2ed63e517e79fff273a7606df73a03c6e}
    virtual size_t GetFreeSampleCount() override
    {
        return samplesCache_.AvailableSize();
    }

private:
    types::InstanceId instanceId_;

    internal::proxy::EventDataContainer<T> samplesCache_;
    mutable std::mutex readerLock_;
    common::HandleInfo handle_;
    std::shared_ptr<EventDataReader<value_type>> reader_;
    ara::com::SubscriptionStateChangeHandler subscriptionChangeHandler_;
    ara::com::EventReceiveHandler receiveHandler_;
};

template <typename T>
class EventImpl<ara::com::internal::dds::types::NullType, T> : public virtual internal::proxy::Event<T>
{
public:
    using container_value_type = typename internal::proxy::Event<T>::container_value_type;
    using new_samples_callback = typename internal::proxy::Event<T>::NewSamplesCallback;

    EventImpl(types::InstanceId instanceId, common::HandleInfo handle)
        : instanceId_(instanceId)
        , handle_(handle)
    { }

    ~EventImpl() override
    { }

    void SetSubscriptionStateChangeHandler(ara::com::SubscriptionStateChangeHandler handler) override
    {
        static_cast<void>(handler);
    }

    void UnsetSubscriptionStateChangeHandler() override
    { }

    void SetReceiveHandler(ara::com::EventReceiveHandler handler) override
    {
        static_cast<void>(handler);
    }

    void UnsetReceiveHandler() override
    { }

    ara::com::SubscriptionState GetSubscriptionState() const override
    {
        return ara::com::SubscriptionState::kNotSubscribed;
    }

    bool IsSubscribed() const override
    {
        return false;
    }

    virtual ara::core::Result<void> Subscribe(std::size_t maxSampleCount) override
    {
        static_cast<void>(maxSampleCount);
        return {};
    }

    void Unsubscribe() override
    { }

    ara::core::Result<size_t> GetNewSamples(new_samples_callback&& f,
        size_t maxNumberOfSamples = std::numeric_limits<size_t>::max()) override
    {
        return ara::core::Result<size_t>::FromError(ara::com::ComErrorDomainErrc::kMaxSamplesExceeded);
    }

    virtual size_t GetFreeSampleCount() override
    {
        return 0;
    }

private:
    types::InstanceId instanceId_;
    common::HandleInfo handle_;
};

}  // namespace proxy
}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_PROXY_EVENT_IMPL_H_
