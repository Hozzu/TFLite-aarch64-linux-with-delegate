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

#pragma once
#include <cstdint>
#include <wrsomeip/wrsomeip.h>

namespace ara
{
namespace com
{
namespace internal
{
namespace wrsomeip
{
namespace types
{

// basic data types wrapper
#define DEFAULT_MAJOR 0x01
#define DEFAULT_MINOR 0x00000000
#define ANY_EVENT 0xFFFF
#define ANY_SERV_ID 0x1234
#define ANY_INST_ID 0x5678
typedef uint32_t request_t;
typedef uint16_t eventgroup_t;
typedef uint8_t byte_t;
using length_t = LENGTH;
using method_t = METHOD;
using message_t = MESSAGE_TYPE;

using message_size_t = uint32_t;
using message_serial_t = SOMEIP_SERIAL;
using service_t = SERVICE_TYPE;
using instance_t = INSTANCE;
using event_t = EVENT;
using client_t = CLIENT;
using session_t = SESSION;
using interface_version_t = INTERFACE_VERSION;
using protocol_version_t = PROTOCOL_VERSION;
using message_type_e = MESSAGE_TYPE;
using return_code_e = RETURN_CODE;
using return_code_t = RETURN_CODE;
using minor_version_t = MINOR_VERSION;
using major_version_t = MAJOR_VERSION;

/**
 * \brief shortcut for wrsomeip Service type
 */
using ServiceId = SERVICE;
/**
 * \brief shortcut for wrsomeip Instance type
 */
using InstanceId = INSTANCE;

using SomeIPMessage = SOMEIP_MESSAGE;
/**
 * \brief shortcut for wrsomeip standard Service Discovery message type
 */
using TypeId = SD_TYPE;
/**
 * \brief shortcut for typical wrsomeip service application container
 */
using ServiceApplication = SERVICE_APPLICATION;

using pServiceApplication = SERVICE_APPLICATION*;
/**
 * \brief shortcut for SomeIP specific service data type which is defined in someIpTypes.h
 */
using SomeIpService = SD_SERVICE;
/**
 * \brief shortcut for SomeIP specific instance data type which is defined in someIpTypes.h
 */
using SomeIpInstance = INSTANCE;

using SDInstance = SD_INSTANCE;
/**
 * \brief shortcut for SomeIP specific method ID which is defined in someIpTypes.h
 */
using SomeIpMethod = METHOD;

using MethodId = METHOD;
/**
 * \brief shortcut for SD_MAJOR_VERSION version number
 */
using ServiceVersionMajor = SD_MAJOR_VERSION;
/**
 * \brief shortcut for SD_MINOR_VERSION version number
 */
using ServiceVersionMinor = SD_MINOR_VERSION;
/**
 * \brief shortcut for EVENT located in someipTypes.h
 */
using EventId = EVENT;
/**
 * \brief shortcut for SD_EVENT_GROUP id
 */
using EventGroupId = SD_EVENT_GROUP;

using EventGroup = EVGR;
/**
 * \brief shortcut for SomeIP message header
 */
using SomeIpHeader = SOMEIP_HEADER*;
/**
 * \brief shortcut for SomeIP message payload
 */
using SomeIpPayload = SOMEIP_PAYLOAD*;

/**
 * \brief shortcut for subscription state
 */
using SubscriptionState = SUBS_STATE;

/**
 * \brief Value to indicate undefined event
 * This value is for event validation only
 */
static constexpr event_t UndefinedEventId = (ANY_EVENT - 1);
static constexpr event_t UndefinedMethodId = (SOMEIP_ANY_METHOD - 1);
static constexpr message_t MessageTypeRequestNoReturn = E_REQUEST_NO_RETURN;

}  // namespace types
}  // namespace wrsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara
