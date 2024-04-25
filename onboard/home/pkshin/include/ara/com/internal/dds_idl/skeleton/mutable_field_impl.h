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

#ifndef ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SKELETON_MUTABLE_FIELD_IMPL_H_
#define ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SKELETON_MUTABLE_FIELD_IMPL_H_

#include "ara/com/types.h"
#include "ara/com/internal/skeleton/field.h"
#include "ara/com/internal/skeleton/mutable_field.h"
#include "ara/com/internal/dds_idl/common.h"

#include "field_impl.h"

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

template <typename FieldDescriptor>
class MutableFieldImpl
    : public internal::skeleton::MutableField<typename FieldDescriptor::data_t>
    , public FieldImpl<FieldDescriptor>
{
public:
    using data_t = typename FieldDescriptor::data_t;
    using Base = FieldImpl<FieldDescriptor>;
    using typename internal::skeleton::MutableField<data_t>::SetMethodSignature;

    explicit MutableFieldImpl(types::InstanceId instance)
        : Base(instance)
        , setter_(instance)
    { }

    void Offer(ServiceImplBase* service) override
    {
        if (service == nullptr) {
            common::logger().LogError() << "Cannot offer field due to no service instance provided";
            return;
        }

        Base::Offer(service);
        if (FieldDescriptor::has_setter) {
            service->OfferMethod(setter_);
        }
    }

    void StopOffer(ServiceImplBase* service) override
    {
        if (service == nullptr) {
            common::logger().LogError() << "Cannot stop offer field due to no service instance provided";
            return;
        }

        if (FieldDescriptor::has_setter) {
            service->StopOfferMethod(setter_);
        }
        Base::StopOffer(service);
    }

    bool IsOffered() const override
    {
        if (!Base::IsOffered()) {
            return false;
        }

        return FieldDescriptor::has_setter ? setter_.IsOffered() : true;
    }

    void RegisterSetHandler(std::function<SetMethodSignature> handler) override
    {
        if (FieldDescriptor::has_setter) {
            Base::RegisterHandler(setter_, handler);
        }
    }

private:
    /// @uptrace{SWS_CM_11149, 334214821ce0dd66bd464f754005f0d49fa6de47}
    /// @uptrace{SWS_CM_11150, 340566b903eb1bcff87b77d293b6e9fe5124b5ba}
    using setter_t = MethodImpl<typename FieldDescriptor::setter_t, typename FieldDescriptor::setter_descriptor_t>;
    setter_t setter_;
};

}  // namespace skeleton
}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SKELETON_MUTABLE_FIELD_IMPL_H_
