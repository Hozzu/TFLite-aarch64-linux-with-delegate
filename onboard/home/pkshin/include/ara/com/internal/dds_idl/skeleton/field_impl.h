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

#ifndef ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SKELETON_FIELD_IMPL_H_
#define ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SKELETON_FIELD_IMPL_H_

#include "ara/com/types.h"
#include "ara/com/internal/skeleton/field.h"
#include "ara/com/internal/dds_idl/common.h"
#include "ara/core/result.h"

#include "service_impl_base.h"
#include "event_impl.h"
#include "method_impl.h"
#include "field_impl_base.h"

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

namespace detail
{
template <typename MethodType>
struct WrapHandler
{
    template <typename HandlerType>
    auto operator()(HandlerType handler)
    {
        return MethodType::WrapHandler(handler);
    }
};

template <>
struct WrapHandler<ara::com::internal::dds::types::NullType>
{
    template <typename HandlerType>
    auto operator()(HandlerType handler)
    {
        return nullptr;
    }
};
}  // namespace detail

template <typename FieldDescriptor>
class FieldImpl
    : public FieldImplBase
    , public virtual internal::skeleton::Field<typename FieldDescriptor::data_t>
{
public:
    using data_t = typename FieldDescriptor::data_t;
    using Base = internal::skeleton::Field<data_t>;
    using typename Base::const_reference;

    explicit FieldImpl(types::InstanceId instance)
        : event_(instance)
        , getter_(instance)
    { }

    virtual ~FieldImpl() = default;

    void Offer(ServiceImplBase* service) override
    {
        if (service == nullptr) {
            common::logger().LogError() << "Cannot offer field due to no service instance provided";
            return;
        }

        if (FieldDescriptor::has_notifier) {
            service->OfferEvent(event_);
        }

        if (FieldDescriptor::has_getter) {
            service->OfferMethod(getter_);
        }
    }

    void StopOffer(ServiceImplBase* service) override
    {
        if (service == nullptr) {
            common::logger().LogError() << "Cannot stop offer field due to no service instance provided";
            return;
        }

        if (FieldDescriptor::has_notifier) {
            service->StopOfferEvent(event_);
        }

        if (FieldDescriptor::has_getter) {
            service->StopOfferMethod(getter_);
        }
    }

    bool IsOffered() const override
    {
        bool offered = true;
        if (FieldDescriptor::has_notifier) {
            offered &= event_.IsOffered();
        }

        if (FieldDescriptor::has_getter) {
            offered &= getter_.IsOffered();
        }

        return offered;
    }

    void RegisterGetHandler(std::function<ara::core::Future<data_t>()> handler) override
    {
        if (FieldDescriptor::has_getter) {
            RegisterHandler(getter_, handler);
        }
    }

    /// @uptrace{SWS_CM_11132, fea2b57ea9916d57c7b0d741c4da6b4d26494419}
    ara::core::Result<void> Update(const_reference data) override
    {
        return Send(data);
    }

    ara::core::Result<ara::com::SampleAllocateePtr<data_t>> Allocate() override
    {
        using ReturnType = ara::core::Result<ara::com::SampleAllocateePtr<data_t>>;
        if (FieldDescriptor::has_notifier) {
            return event_.Allocate();
        }
        return ReturnType::FromError({ara::com::ComErrorDomainErrc::kNetworkBindingFailure});
    }

    /// @uptrace{SWS_CM_11132, fea2b57ea9916d57c7b0d741c4da6b4d26494419}
    ara::core::Result<void> Send(ara::com::SampleAllocateePtr<data_t> data) override
    {
        return event_.Send(*data);
    }

    ara::core::Result<void> Send(const_reference data) override
    {
        using ReturnType = ara::core::Result<void>;
        if (FieldDescriptor::has_notifier) {
            return event_.Send(data);
        }
        return ReturnType::FromError({ara::com::ComErrorDomainErrc::kNetworkBindingFailure});
    }

protected:
    template <typename MethodType, typename HandlerType>
    void RegisterHandler(MethodType& method, HandlerType handler)
    {
        if (handler) {
            method.SetInvoker(detail::WrapHandler<typename MethodType::types_info>()(handler));
        } else {
            method.SetInvoker(nullptr);
        }
    }

private:
    using event_t = EventImpl<data_t, typename FieldDescriptor::event_descriptor_t>;
    using getter_t = MethodImpl<typename FieldDescriptor::getter_t, typename FieldDescriptor::getter_descriptor_t>;

    event_t event_;
    /// @uptrace{SWS_CM_11149, 334214821ce0dd66bd464f754005f0d49fa6de47}
    /// @uptrace{SWS_CM_11150, 340566b903eb1bcff87b77d293b6e9fe5124b5ba}
    getter_t getter_;
};

}  // namespace skeleton
}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SKELETON_FIELD_IMPL_H_
