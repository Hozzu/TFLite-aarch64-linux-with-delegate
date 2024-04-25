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

#ifndef ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_SKELETON_EVENT_IMPL_H_
#define ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_SKELETON_EVENT_IMPL_H_

#include "ara/core/result.h"
#include "ara/com/types.h"
#include "ara/com/com_error_domain.h"
#include "ara/com/internal/skeleton/event.h"
#include "ara/com/internal/dds_idl/types.h"
#include "ara/com/internal/dds_idl/common.h"
#include "ara/com/internal/dds_idl/data_writer.h"
#include "ara/com/internal/dds_idl/dds_idl_types_binding.h"
#include "ara/com/internal/dds_idl/domain_participant.h"
#include "ara/com/internal/dds_idl/publisher.h"

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

class EventImplBase
{
public:
    virtual ~EventImplBase() = default;

    virtual bool IsOffered() const = 0;
    virtual ara::core::Result<void> Offer(common::HandleInfo handle) = 0;
    virtual void StopOffer() = 0;
};

/// \brief Event implementation for Skeleton interface
template <typename T, typename EventDescriptor>
class EventImpl
    : public virtual internal::skeleton::Event<T>
    , public EventImplBase
{
public:
    using Base = internal::skeleton::Event<T>;
    using typename Base::const_reference;
    using typename Base::value_type;
    using descriptor_type = EventDescriptor;

    /// \brief constructor
    explicit EventImpl(types::InstanceId instance_id)
        : instanceId_(instance_id)
    { }

    /// \brief virtual destructor
    virtual ~EventImpl()
    { }

    /// @uptrace{SWS_CM_11017, f9b1a84d30ae3fa961b627f6fc730a8d63941926}
    ara::core::Result<void> Send(const_reference data) override
    {
        using ReturnType = ara::core::Result<void>;
        try {
            if (IsOffered()) {
                ara::core::Optional<uint16_t> optionalId = common::ToTransportIdentifier(instanceId_);
                if (optionalId) {
                    std::lock_guard<std::mutex> lock(writerLock_);
                    writer_->Write({*optionalId, ConvertToIdl(data)});
                    return {};
                }
            }
        } catch (...) {
        }
        return ReturnType::FromError({ara::com::ComErrorDomainErrc::kNetworkBindingFailure});
    }

    /// @uptrace{SWS_CM_90438, bdf7f8e57972dd9a11697f9031071855dd3b1b3d}
    /// @uptrace{SWS_CM_00308, da5eb18dc5a888434ea0b882750c7261e2dd1eca}
    ara::core::Result<ara::com::SampleAllocateePtr<T>> Allocate() override
    {
        using ReturnType = ara::core::Result<ara::com::SampleAllocateePtr<T>>;
        try {
            return ReturnType::FromValue(std::make_unique<T>());
        } catch (...) {
            // TODO: use more appropriate error when available
            return ReturnType::FromError({ara::com::ComErrorDomainErrc::kNetworkBindingFailure});
        }
    }

    /// @uptrace{SWS_CM_11017, f9b1a84d30ae3fa961b627f6fc730a8d63941926}
    ara::core::Result<void> Send(ara::com::SampleAllocateePtr<T> data) override
    {
        return Send(*data);
    }

    bool IsOffered() const override
    {
        std::lock_guard<std::mutex> lock(writerLock_);
        return writer_ && writer_->IsValid();
    }

    ara::core::Result<void> Offer(common::HandleInfo handle) override
    {
        if (!handle.participant || !handle.publisher) {
            return ara::core::Result<void>::FromError(ara::com::ComErrorDomainErrc::kBadArguments);
        }

        auto topic = handle.participant->GetTopic<typename EventImpl::value_type>(descriptor_type::topic_name);
        if (!topic) {
            return ara::core::Result<void>::FromError(ara::com::ComErrorDomainErrc::kUnknownError);
        }

        std::lock_guard<std::mutex> lock(writerLock_);
        writer_ = handle.publisher->GetDataWriter(topic, descriptor_type::qos_profile);
        if (!writer_) {
            return ara::core::Result<void>::FromError(ara::com::ComErrorDomainErrc::kUnknownError);
        }

        return {};
    }

    void StopOffer() override
    {
        std::lock_guard<std::mutex> lock(writerLock_);
        writer_ = nullptr;
    }

private:
    types::InstanceId instanceId_;
    std::shared_ptr<DataWriter<value_type>> writer_;
    mutable std::mutex writerLock_;
};

/// \brief Specialization for empty Event: EventImpl<NullType>
template <typename T>
class EventImpl<T, ara::com::internal::dds::types::NullType>
    : public virtual internal::skeleton::Event<T>
    , public EventImplBase
{
public:
    using Base = internal::skeleton::Event<T>;
    using typename Base::const_reference;
    using typename Base::value_type;

    explicit EventImpl(types::InstanceId instance_id)
    {
        static_cast<void>(instance_id);
    }

    virtual ~EventImpl()
    { }

    ara::core::Result<void> Send(const_reference data) override
    {
        static_cast<void>(data);
        return {};
    }

    ara::core::Result<ara::com::SampleAllocateePtr<T>> Allocate() override
    {
        using ReturnType = ara::core::Result<ara::com::SampleAllocateePtr<T>>;
        try {
            return ReturnType::FromValue(std::make_unique<T>());
        } catch (...) {
            // TODO: use more appropriate error when available
            return ReturnType::FromError({ara::com::ComErrorDomainErrc::kNetworkBindingFailure});
        }
    }

    ara::core::Result<void> Send(ara::com::SampleAllocateePtr<T> data) override
    {
        return Send(*data);
    }

    bool IsOffered() const override
    {
        return false;
    }

    ara::core::Result<void> Offer(common::HandleInfo handle) override
    {
        static_cast<void>(handle);
        return ara::core::Result<void>::FromError(ara::com::ComErrorDomainErrc::kUnknownError);
    }

    void StopOffer() override
    { }
};

}  // namespace skeleton
}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_SKELETON_EVENT_IMPL_H_
