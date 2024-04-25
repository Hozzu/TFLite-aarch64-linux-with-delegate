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

#ifndef VSOMEIP_PROXY_MAKE_METHOD_DESCRIPTOR_FROM_H
#define VSOMEIP_PROXY_MAKE_METHOD_DESCRIPTOR_FROM_H

#include "ara/com/internal/vsomeip/vsomeip_types.h"

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

/**
 * \addtogroup vsomeipproxyimpl
 *
 * @{
 */

/**
 * \brief Creating Set and Get MethodDescriptor.
 *
 * Prepare the descriptor for setter or getter method for fields using specific service_id and corresponding method_id.
 * This is used to either get a field value using the get method call or to set a field value
 * using the set method from proxy side.
 */
template <typename FieldDescriptor>
struct MakeGetMethodDescriptorFrom
{
    static constexpr types::ServiceId service_id = FieldDescriptor::service_id;
    static constexpr types::ServiceVersionMajor service_version_major = FieldDescriptor::service_version_major;
    static constexpr types::MethodId method_id = FieldDescriptor::get_method_id;
    static constexpr bool is_reliable = FieldDescriptor::is_getter_reliable;
};

template <typename FieldDescriptor>
struct MakeSetMethodDescriptorFrom
{
    static constexpr types::ServiceId service_id = FieldDescriptor::service_id;
    static constexpr types::ServiceVersionMajor service_version_major = FieldDescriptor::service_version_major;
    static constexpr types::MethodId method_id = FieldDescriptor::set_method_id;
    static constexpr bool is_reliable = FieldDescriptor::is_setter_reliable;
};

/**
 * @}
 */
}  // namespace proxy
}  // namespace vsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // VSOMEIP_PROXY_MAKE_METHOD_DESCRIPTOR_FROM_H
