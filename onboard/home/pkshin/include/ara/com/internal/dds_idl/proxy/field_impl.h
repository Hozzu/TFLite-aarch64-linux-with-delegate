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

#ifndef ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_PROXY_FIELD_IMPL_H_
#define ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_PROXY_FIELD_IMPL_H_

#include "ara/com/internal/dds_idl/types.h"
#include "ara/com/internal/proxy/field.h"

#include "event_impl.h"
#include "method_impl.h"

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
namespace detail
{

template <typename FieldType, typename MethodType>
struct FieldGetterSignature
{
    using type = typename MethodType::signature_t;
};

template <typename FieldType>
struct FieldGetterSignature<FieldType, ara::com::internal::dds::types::NullType>
{
    using type = FieldType();
};

template <typename FieldDescriptor>
struct FieldGetterType
{
    using data_t = typename FieldDescriptor::data_t;
    using descriptor_t = typename FieldDescriptor::getter_descriptor_t;
    using method_t = typename FieldDescriptor::getter_t;
    using signature_t = typename FieldGetterSignature<data_t, method_t>::type;

    using type = ara::com::internal::dds::proxy::MethodImpl<descriptor_t, method_t, signature_t>;
};

}  // namespace detail

/// @uptrace{SWS_CM_11140, a51b7cbebc969f9fcbde447c17b5f803b732d481}
/// @uptrace{SWS_CM_11141, 30b730e2eb66849acb69ba8f891f2c1839be7c14}
/// @uptrace{SWS_CM_11142, 7e5b9e891a5d73489e5dda5914d6cb87ab6daad9}
/// @uptrace{SWS_CM_11143, b004eee0eb9cc0755cb4cf6b899c644fe2aa5e87}
template <typename FieldDescriptor>
class FieldImpl
    : public virtual ara::com::internal::proxy::Field<typename FieldDescriptor::data_t>
    , public EventImpl<typename FieldDescriptor::event_descriptor_t, typename FieldDescriptor::data_t>
{
public:
    using FieldBase = ara::com::internal::proxy::Field<typename FieldDescriptor::data_t>;
    using EventBase = EventImpl<typename FieldDescriptor::event_descriptor_t, typename FieldDescriptor::data_t>;
    using MethodGet = typename FieldBase::MethodGet;

    FieldImpl(types::InstanceId instance_id, common::HandleInfo handle)
        : FieldBase(getter_)
        , EventBase(instance_id, handle)
        , getter_(instance_id, handle)
    { }

    virtual ~FieldImpl()
    { }

protected:
    /// @uptrace{SWS_CM_11147, 417bc4a2fd31ea99adfad64e8db6b788efe2a99c}
    /// @uptrace{SWS_CM_11148, e6ae47080af5a884eaf39e0f7228ddc7028cead6}
    typename detail::FieldGetterType<FieldDescriptor>::type getter_;
};

}  // namespace proxy
}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_PROXY_FIELD_IMPL_H_
