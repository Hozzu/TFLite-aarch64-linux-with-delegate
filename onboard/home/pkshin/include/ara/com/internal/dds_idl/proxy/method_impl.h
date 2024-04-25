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

#ifndef ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_PROXY_METHOD_IMPL_H_
#define ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_PROXY_METHOD_IMPL_H_

#include "ara/com/com_error_domain.h"
#include "ara/com/internal/proxy/method.h"
#include "ara/com/internal/dds_idl/common.h"
#include "ara/com/internal/dds_idl/domain_participant.h"

#include "ara/core/future.h"
#include "ara/core/promise.h"

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

// Declare the template MethodImpl without an implementation for the general case to force a compilation error if
// MethodImpl is used with anything else than a MethodDescriptor and a function signature
template <typename MethodDescriptor, typename MethodTypesInfo, typename Signature>
class MethodImpl;

template <typename MethodDescriptor, typename MethodTypesInfo, typename R, typename... Args>
class MethodImpl<MethodDescriptor, MethodTypesInfo, R(Args...)> : public ara::com::internal::proxy::Method<R(Args...)>
{
public:
    using Base = ara::com::internal::proxy::Method<R(Args...)>;
    using descriptor_type = MethodDescriptor;
    using Output = typename Base::result_type;

    /// @uptrace{SWS_CM_11100, 3ba1020380c8f2d97ca24d41147f61f30f6279f6}
    /// @uptrace{SWS_CM_11103, bd3a222c27b33c3943df845a681ddbbd76ec7ea1}
    /// @uptrace{SWS_CM_11104, 954559b281b0e947ce83210cd71dad713957116d}
    /// @uptrace{SWS_CM_11107, 9dbef0d043d82075db44e6c6e3427c7091d4e4c9}
    MethodImpl(types::InstanceId instanceId, common::HandleInfo handle)
        : instanceId_(instanceId)
        , handle_(handle)
    {
        /// @uptrace{SWS_CM_11100, 3ba1020380c8f2d97ca24d41147f61f30f6279f6}
        auto requestTopic
            = handle.participant->GetTopic<typename MethodTypesInfo::request_t>(descriptor_type::input_topic_name);
        if (!requestTopic) {
            common::logger().LogError() << "proxy::MethodImpl::MethodImpl(): Request topic get failed";
            return;
        }

        /// @uptrace{SWS_CM_11103, bd3a222c27b33c3943df845a681ddbbd76ec7ea1}
        writer_ = handle.publisher->GetDataWriter(requestTopic, descriptor_type::qos_profile);
        if (!writer_) {
            common::logger().LogError() << "proxy::MethodImpl::MethodImpl(): writer get failed";
            return;
        }

        /// @uptrace{SWS_CM_11100, 3ba1020380c8f2d97ca24d41147f61f30f6279f6}
        auto replyTopic
            = handle.participant->GetTopic<typename MethodTypesInfo::reply_t>(descriptor_type::output_topic_name);
        if (!replyTopic) {
            common::logger().LogError() << "proxy::MethodImpl::MethodImpl(): Reply topic get failed";
            return;
        }

        reader_ = handle.subscriber->GetMethodDataReader(replyTopic, descriptor_type::qos_profile);
        if (!reader_) {
            common::logger().LogError() << "proxy::MethodImpl::MethodImpl(): reader get failed";
            return;
        }

        reader_->AddMethodHandler(
            descriptor_type::kMethodHash, [this](auto& sample) { ReceiveRequestResults(sample); });
    }

    virtual ~MethodImpl()
    { }

    /// @uptrace{SWS_CM_11108, 6246a70b5b980ebeee2350ea7953f5169f32dc74}
    ara::core::Future<Output> operator()(Args&&... args) override
    {
        ara::core::Promise<Output> promise;
        auto future = promise.get_future();

        std::unique_lock<std::mutex> lock(pending_requests_lock_);
        auto requestIterator = pendingRequests_.find(lastRequestId_);
        if (requestIterator != pendingRequests_.end()) {
            lock.unlock();
            promise.SetError(ara::com::ComErrorDomainErrc::kNetworkBindingFailure);
            common::logger().LogError() << "Request Id is already used";
        } else {
            pendingRequests_.insert(std::make_pair(lastRequestId_, std::move(promise)));
            typename MethodTypesInfo::request_t request;
            request.header.requestId.sequence_number.low = lastRequestId_;
            ++lastRequestId_;
            request.header.instanceName = ConvertToIdl(ara::core::String(instanceId_.ToString()));
            lock.unlock();
            MethodTypesInfo::SetRequestData(request, {ConvertToIdl(args)...});
            writer_->Write(request);
        }

        return future;
    }

private:
    types::InstanceId instanceId_;
    common::HandleInfo handle_;
    types::RequestId lastRequestId_ = types::RequestId();

    using PendingRequests = std::unordered_map<types::RequestId, ara::core::Promise<Output>>;
    PendingRequests pendingRequests_;
    std::mutex pending_requests_lock_;

    std::shared_ptr<DataWriter<typename MethodTypesInfo::request_t>> writer_;
    std::shared_ptr<MethodDataReader<typename MethodTypesInfo::reply_t>> reader_;

    /// @uptrace{SWS_CM_11152, beadc17d368797a4fa83dd354c3bd9a99ada1e8e}
    void ReceiveRequestResults(typename MethodTypesInfo::reply_t& sample)
    {
        ara::core::Promise<Output> promise;
        std::unique_lock<std::mutex> lock(pending_requests_lock_);
        auto request = pendingRequests_.find(sample.header.relatedRequestId.sequence_number.low);
        /// @uptrace{SWS_CM_11108, 6246a70b5b980ebeee2350ea7953f5169f32dc74}
        if (request == pendingRequests_.end()) {
            lock.unlock();
            common::logger().LogError() << "MethodImpl::ReceiveRequestResults(): sample's header is missing";
        } else {
            promise = std::move(request->second);
            pendingRequests_.erase(request);
            lock.unlock();
            MethodTypesInfo::SetPromiseValue(promise, sample);
        }
    }
};

template <typename R, typename... Args>
class MethodImpl<ara::com::internal::dds::types::NullType, ara::com::internal::dds::types::NullType, R(Args...)>
    : public ara::com::internal::proxy::Method<R(Args...)>
{
public:
    using Base = ara::com::internal::proxy::Method<R(Args...)>;
    using Output = typename Base::result_type;

    MethodImpl(types::InstanceId instanceId, common::HandleInfo handle)
        : instanceId_(instanceId)
        , handle_(handle)
    { }

    virtual ~MethodImpl()
    { }

    /// @uptrace{SWS_CM_11108, 6246a70b5b980ebeee2350ea7953f5169f32dc74}
    ara::core::Future<Output> operator()(Args&&... args) override
    {
        ara::core::Promise<Output> promise;
        return promise.get_future();
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

#endif  // ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_PROXY_METHOD_IMPL_H_
