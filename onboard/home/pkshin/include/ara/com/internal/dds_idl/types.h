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

#ifndef ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_TYPES_H_
#define ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_TYPES_H_

#include <dds/DCPS/PublisherImpl.h>

#include "ara/com/instance_identifier.h"

#include <cstdint>
#include <string>
#include <memory>

namespace dds_idl
{

typedef std::string service_t;
typedef uint16_t method_t;
typedef uint16_t eventgroup_t;
typedef uint8_t major_version_t;
typedef uint32_t minor_version_t;
typedef uint32_t request_t;

}  // namespace dds_idl

namespace ara
{
namespace com
{
namespace internal
{
namespace dds
{
namespace types
{

/// \brief shortcut for domain id
// using DomainId = int32_t;
using DomainId = ::DDS::DomainId_t;

/// \brief shortcut for service id
using ServiceId = ::dds_idl::service_t;

/// \brief shortcut for method id
using MethodId = ::dds_idl::method_t;

/// \brief shortcut for instance id
using InstanceId = InstanceIdentifier;

/// \brief shortcut for major version number
using ServiceVersionMajor = ::dds_idl::major_version_t;

/// \brief shortcut for minor version number
using ServiceVersionMinor = ::dds_idl::minor_version_t;

/// \brief shortcut for request id
using RequestId = ::dds_idl::request_t;

/// \brief shortcut for eventgroup id
using EventGroupId = ::dds_idl::eventgroup_t;

/// \brief shortcut for event id
using EventId = uint32_t;

struct NullType final
{ };

struct BlacklistedVersion
{
    const ServiceVersionMajor major;
    const ServiceVersionMinor minor;
};

}  // namespace types
}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_TYPES_H_
