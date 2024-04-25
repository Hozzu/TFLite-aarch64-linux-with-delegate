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

#ifndef ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SKELETON_METHOD_IMPL_H_
#define ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SKELETON_METHOD_IMPL_H_

#include "ara/com/internal/proxy/method.h"
#include "ara/com/internal/dds_idl/common.h"
#include "ara/com/internal/dds_idl/skeleton/method_impl_base.h"

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
namespace skeleton
{

template <typename MethodTypesInfo, typename MethodDescriptor>
class MethodImpl : public MethodImplBase
{
public:
    using descriptor_type = MethodDescriptor;
    using types_info = MethodTypesInfo;

    explicit MethodImpl(types::InstanceId instanceId)
        : instanceId_(instanceId)
    { }

    virtual ~MethodImpl()
    {
        StopOffer();
    }

    /// @uptrace{SWS_CM_11100, 3ba1020380c8f2d97ca24d41147f61f30f6279f6}
    /// @uptrace{SWS_CM_11105, ec72a3bb51a5b2e68cb6f074a09d31fb62bf9de5}
    /// @uptrace{SWS_CM_11106, 410995645790eda5bfbac84d8988d8888bc2a1c5}
    /// @uptrace{SWS_CM_11153, df174f77bc928bcdce722f620e417383ed8c4e4a}
    void Offer(common::HandleInfo handle, OnRequestType onRequest) override
    {
        onRequest_ = onRequest;
        /// @uptrace{SWS_CM_11100, 3ba1020380c8f2d97ca24d41147f61f30f6279f6}
        auto replyTopic
            = handle.participant->GetTopic<typename MethodTypesInfo::reply_t>(descriptor_type::output_topic_name);
        if (!replyTopic) {
            common::logger().LogError() << "skeleton::MethodImpl::Offer(): Reply topic get failed";
            return;
        }

        /// @uptrace{SWS_CM_11106, 410995645790eda5bfbac84d8988d8888bc2a1c5}
        {
            std::unique_lock<std::mutex> lock(writer_lock_);
            writer_ = handle.publisher->GetDataWriter(replyTopic, descriptor_type::qos_profile);
            if (!writer_) {
                common::logger().LogError() << "skeleton::MethodImpl::Offer(): writer get failed";
                return;
            }
        }

        /// @uptrace{SWS_CM_11100, 3ba1020380c8f2d97ca24d41147f61f30f6279f6}
        auto requestTopic
            = handle.participant->GetTopic<typename MethodTypesInfo::request_t>(descriptor_type::input_topic_name);
        if (!requestTopic) {
            common::logger().LogError() << "skeleton::MethodImpl::Offer(): Request topic get failed";
            return;
        }

        reader_ = handle.subscriber->GetMethodDataReader(requestTopic, descriptor_type::qos_profile);
        if (!reader_) {
            common::logger().LogError() << "skeleton::MethodImpl::Offer(): reader get failed";
            return;
        }

        reader_->AddMethodHandler(descriptor_type::kMethodHash, [this](auto& sample) { EnqueueRequest(sample); });
    }

    void StopOffer() override
    {
        std::unique_lock<std::mutex> lock(writer_lock_);
        reader_ = nullptr;
        writer_ = nullptr;
    }

    bool IsOffered() const override
    {
        return writer_ != nullptr && reader_ != nullptr;
    }

    void SetInvoker(typename MethodTypesInfo::invoker_t invoker)
    {
        invoker_ = invoker;
    }

protected:
    /// @uptrace{SWS_CM_11109, 2760d5803e844f9f1957caeeee0254595ecf501e}
    /// @uptrace{SWS_CM_11111, 8b041812e6d247bf5ecb260cb9a9aa4b4a4d9103}
    /// @uptrace{SWS_CM_11112, 8333b7bcc1c505f3e5544511723341e9d33061f5}
    /// @uptrace{SWS_CM_11155, e4a512444fe4c660598f90c4543f23d358c1ad13}
    /// @uptrace{SWS_CM_11156, d4f1cf39e2d3ee90cdb0feeab0edf6800ee2d2cd}
    bool ProcessRequest(requestId_t id) override
    {
        if (!invoker_) {
            common::logger().LogError() << "skeleton::MethodImpl::ProcessRequest(): invoker_ is nullptr";
            return false;
        }

        std::unique_lock<std::mutex> lock(pending_requests_lock_);
        /// @uptrace{SWS_CM_11111, 8b041812e6d247bf5ecb260cb9a9aa4b4a4d9103}
        auto it = pendingRequests_.find(id);
        if (it == pendingRequests_.end()) {
            lock.unlock();
            common::logger().LogError()
                << "skeleton::MethodImpl::ProcessRequest(): pendingRequests_ doesn't contain target id";
            return false;
        }

        auto request = std::move(it->second);
        pendingRequests_.erase(it);
        lock.unlock();

        auto result = invoker_(request).GetResult();
        typename MethodTypesInfo::reply_t reply;
        /// @uptrace{SWS_CM_11112, 8333b7bcc1c505f3e5544511723341e9d33061f5}
        reply.header.relatedRequestId.sequence_number.low = request.header.requestId.sequence_number.low;
        MethodTypesInfo::SetReplyData(reply, result);
        std::unique_lock<std::mutex> writerLock(writer_lock_);
        if (writer_) {
            writer_->Write(reply);
        }
        return true;
    }

    ara::core::Vector<requestId_t> GetPendingRequestsIds() override
    {
        ara::core::Vector<requestId_t> result;
        std::lock_guard<std::mutex> lock(pending_requests_lock_);
        for (auto const& request : pendingRequests_) {
            result.push_back(request.first);
        }

        return result;
    }

private:
    types::InstanceId instanceId_;

    typename MethodTypesInfo::invoker_t invoker_;
    std::shared_ptr<DataWriter<typename MethodTypesInfo::reply_t>> writer_;
    std::shared_ptr<MethodDataReader<typename MethodTypesInfo::request_t>> reader_;
    ara::core::Map<requestId_t, typename MethodTypesInfo::request_t> pendingRequests_;
    OnRequestType onRequest_;
    std::mutex pending_requests_lock_;
    std::mutex writer_lock_;

    void EnqueueRequest(typename MethodTypesInfo::request_t& sample)
    {
        std::unique_lock<std::mutex> lock(pending_requests_lock_);
        auto nextId = GetNextId();
        pendingRequests_[nextId] = std::move(sample);
        lock.unlock();
        onRequest_(this, nextId);
    }
};

template <>
class MethodImpl<ara::com::internal::dds::types::NullType, ara::com::internal::dds::types::NullType>
    : public MethodImplBase
{
public:
    using descriptor_type = ara::com::internal::dds::types::NullType;
    using types_info = ara::com::internal::dds::types::NullType;

    explicit MethodImpl(types::InstanceId instanceId)
        : instanceId_(instanceId)
    { }

    virtual ~MethodImpl()
    { }

    /// @uptrace{SWS_CM_11100, 3ba1020380c8f2d97ca24d41147f61f30f6279f6}
    /// @uptrace{SWS_CM_11105, ec72a3bb51a5b2e68cb6f074a09d31fb62bf9de5}
    /// @uptrace{SWS_CM_11106, 410995645790eda5bfbac84d8988d8888bc2a1c5}
    void Offer(common::HandleInfo handle, OnRequestType onRequest) override
    {
        static_cast<void>(handle);
        static_cast<void>(onRequest);
    }

    void StopOffer() override
    { }

    bool IsOffered() const override
    {
        return false;
    }

    template <typename Invoker>
    void SetInvoker(Invoker invoker)
    {
        static_cast<void>(invoker);
    }

protected:
    /// @uptrace{SWS_CM_11109, 2760d5803e844f9f1957caeeee0254595ecf501e}
    /// @uptrace{SWS_CM_11111, 8b041812e6d247bf5ecb260cb9a9aa4b4a4d9103}
    /// @uptrace{SWS_CM_11112, 8333b7bcc1c505f3e5544511723341e9d33061f5}
    bool ProcessRequest(requestId_t id) override
    {
        static_cast<void>(id);
        return false;
    }

    ara::core::Vector<requestId_t> GetPendingRequestsIds() override
    {
        return {};
    }

private:
    types::InstanceId instanceId_;
};

}  // namespace skeleton
}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SKELETON_METHOD_IMPL_H_
