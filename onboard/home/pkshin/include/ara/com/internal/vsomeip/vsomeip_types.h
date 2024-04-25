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

/// \file
/// \brief General types used in vsomeip binding

#ifndef ARA_VSOMEIP_BINDING_INCLUDES_LIBARA_INTERNAL_COMMON_VSOMEIP_TYPES_H_
#define ARA_VSOMEIP_BINDING_INCLUDES_LIBARA_INTERNAL_COMMON_VSOMEIP_TYPES_H_

#include <cstdint>
#include <vsomeip/vsomeip.hpp>

namespace ara
{
namespace com
{
namespace internal
{
namespace vsomeip
{
namespace types
{

/// \addtogroup vsomeipcommon
///@{

/// \brief shortcut for ::vsomeip::service id
using ServiceId = ::vsomeip::service_t;

/// \brief shortcut for ::vsomeip::method id
using MethodId = ::vsomeip::method_t;

/// \brief shortcut for ::vsomeip::instance id
using InstanceId = ::vsomeip::instance_t;

/// \brief shortcut for ::vsomeip::major version number
using ServiceVersionMajor = ::vsomeip::major_version_t;

/// \brief shortcut for ::vsomeip::minor version number
using ServiceVersionMinor = ::vsomeip::minor_version_t;

/// \brief shortcut for ::vsomeip::request id
using RequestId = ::vsomeip::request_t;

/// \brief shortcut for ::vsomeip::eventgroup id
using EventGroupId = ::vsomeip::eventgroup_t;

/// \brief shortcut for ::vsomeip::event id
using EventId = ::vsomeip::event_t;

/// \brief shortcut for ::vsomeip::session_t
using SessionId = ::vsomeip::session_t;

/// \brief shortcut for ::vsomeip::client_t
using ClientId = ::vsomeip::client_t;

/// \brief shortcut for ::vsomeip::interface_version_t
using InterfaceVersion = ::vsomeip::interface_version_t;

/// \brief shortcut for ::vsomeip::message_type_e
using MessageType = ::vsomeip::message_type_e;

/// \brief Value to indicate undefined method
/// This value is disallowed for use
static constexpr MethodId UndefinedMethodId = (::vsomeip::ANY_METHOD - 1);

/// \brief Value to indicate undefined event
/// This value is disallowed for use
static constexpr EventId UndefinedEventId = (::vsomeip::ANY_EVENT - 1);

/// \brief Required protocol version for vsomeip messages
/// @uptrace{SWS_CM_10312, 6e2c76ceb2f09f52f1b3c416aac2e0e6c086f14f}
/// @uptrace{SWS_CM_10313, bab2988e7ab4b6c195deb763750aeb9eee9fe109}
/// @uptrace{SWS_CM_10292, 381416fd4b92a354b9bab0de94a9626f33105a98}
/// @uptrace{SWS_CM_10291, 97ac700f0c560844a92aaa8b450a2118bb371628}
/// @uptrace{SWS_CM_10302, 7a70b24bf07f9fa220a701d481b4db016279e01c}
/// @uptrace{SWS_CM_10334, 24bb65bb23b66d54b3ec622260b1dc77573c4e59}
static constexpr ::vsomeip::protocol_version_t ProtocolVersion{0x01};

/// \brief Required Client ID for vsomeip event messages
/// @uptrace{SWS_CM_10292, 381416fd4b92a354b9bab0de94a9626f33105a98}
/// @uptrace{SWS_CM_10291, 97ac700f0c560844a92aaa8b450a2118bb371628}
static constexpr ::vsomeip::client_t EventClientID{0x0000};

/// \brief Minimum message length
/// @uptrace{SWS_CM_10313, bab2988e7ab4b6c195deb763750aeb9eee9fe109}
/// @uptrace{SWS_CM_10292, 381416fd4b92a354b9bab0de94a9626f33105a98}
/// @uptrace{SWS_CM_10291, 97ac700f0c560844a92aaa8b450a2118bb371628}
/// @uptrace{SWS_CM_10312, 6e2c76ceb2f09f52f1b3c416aac2e0e6c086f14f}
/// @uptrace{SWS_CM_10302, 7a70b24bf07f9fa220a701d481b4db016279e01c}
/// @uptrace{SWS_CM_10334, 24bb65bb23b66d54b3ec622260b1dc77573c4e59}
static constexpr ::vsomeip::length_t MinMessageLength{8};

/// \brief Type of message is event
static constexpr ::vsomeip::message_type_e MessageTypeEvent = ::vsomeip::message_type_e::MT_NOTIFICATION;

/// \brief Type of message is request
static constexpr ::vsomeip::message_type_e MessageTypeRequest = ::vsomeip::message_type_e::MT_REQUEST;

/// \brief Type of message is request, no return
static constexpr ::vsomeip::message_type_e MessageTypeRequestNoReturn = ::vsomeip::message_type_e::MT_REQUEST_NO_RETURN;

/// \brief Type of message is response
static constexpr ::vsomeip::message_type_e MessageTypeResponse = ::vsomeip::message_type_e::MT_RESPONSE;

/// \brief Type of message is error
static constexpr ::vsomeip::message_type_e MessageTypeError = ::vsomeip::message_type_e::MT_ERROR;

/// \brief Value to indicate undefined blacklisted major service version
static constexpr ServiceVersionMajor UndefinedBlServiceVersionMajor = ::vsomeip::ANY_MAJOR;

/// \brief Type of blacklisted version
struct BlacklistedVersion
{
    const ServiceVersionMajor major;
    const ServiceVersionMinor minor;
};

/// \brief Status codes of event subscribe error handler
static constexpr uint16_t kEventSubscribeAck{0x0};
static constexpr uint16_t kEventSubscribeNack{0x7};

///@}
}  // namespace types
}  // namespace vsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_VSOMEIP_BINDING_INCLUDES_LIBARA_INTERNAL_COMMON_VSOMEIP_TYPES_H_
