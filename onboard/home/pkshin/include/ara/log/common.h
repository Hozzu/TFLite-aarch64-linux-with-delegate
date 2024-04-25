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
 * @file
 * @brief This file contains common types definitions for the logging API.
 *
 * @attention Due to limitation of the C++ language, some internal implementation
 * (e.g. the function bodies) are coded directly into this header file.
 * Such code is NOT meant to be used or referred to by a user directly,
 * and is subject to CHANGE WITHOUT NOTICE.
 * Therefore DO NOT DEPEND ON any implementation details!
 */

#ifndef LOGCOMMON_H
#define LOGCOMMON_H

#include <cstdint>

namespace ara
{
namespace log
{

/**
 * @defgroup common Common Types
 * @brief Common type definitions for the logging API.
 */

/// @addtogroup common
/// @{

/**
 * @brief Log levels, in decreasing order of severity.
 *
 * Maps one-by-one to the values from DltLogLevelType.
 * @sa <dlt/dlt_types.h>
 *
 * @uptrace{SWS_LOG_00018, d6cc8ea90d84cb6066b82fc0e8fd055893b0c954}
 */
enum class LogLevel : std::uint8_t
{
    kOff = 0x00,  ///< No logging
    kFatal = 0x01,  ///< Fatal error, not recoverable
    kError = 0x02,  ///< Error with impact to correct functionality
    kWarn = 0x03,  ///< Warning if correct behavior cannot be ensured
    kInfo = 0x04,  ///< Informational, providing high level understanding
    kDebug = 0x05,  ///< Detailed information for programmers
    kVerbose = 0x06  ///< Extra-verbose debug messages (highest grade of information)
};

/**
 * @brief Log mode. Flags, used to configure the sink for log messages.
 * @note In order to combine flags, at least the OR and AND operators needs to be provided for this type.
 */
enum class LogMode : std::uint8_t
{
    kRemote = 0x01,  ///< Send remotely
    kFile = 0x02,  ///< Save to file
    kConsole = 0x04  ///< Forward to console
};

/**
 * @brief Client state representing the connection state of an external client.
 *
 * @uptrace{SWS_LOG_00098, eadda243b817aede5bf12e43005265f2464ec5cd}
 */
enum class ClientState : std::int8_t
{
    kUnknown = -1,  //< DLT back-end not up and running yet, state cannot be determined
    kNotConnected,  //< No remote client detected
    kConnected  //< Remote client is connected
};

namespace internal
{

/**
 * @brief LogReturn. Flags to define return values.
 * @note This is required to hide include/implementation of dlt on exported headers
 *
 * Maps one-by-one to the values from DltReturnValue.
 * @sa <dls/dlt_types.h>
 */
enum class LogReturnValue : std::int8_t
{
    kReturnLoggingDisabled = -7,
    kReturnUserBufferFull = -6,
    kReturnWrongParameter = -5,
    kReturnBufferFull = -4,
    kReturnPipeFull = -3,
    kReturnPipeError = -2,
    kReturnError = -1,
    kReturnOk = 0,
    kReturnTrue = 1
};

template <typename EnumT>
constexpr auto to_integral(const EnumT value) noexcept
{
    return static_cast<std::underlying_type_t<EnumT>>(value);
}

}  // namespace internal

inline auto operator|(LogMode lhs, LogMode rhs) noexcept
{
    return (static_cast<LogMode>(internal::to_integral(lhs) | internal::to_integral(rhs)));
}

inline auto operator&(LogMode lhs, LogMode rhs) noexcept
{
    return (internal::to_integral(lhs) & internal::to_integral(rhs));
}

/// @}
} /* namespace log */
} /* namespace ara */

#endif  // LOGCOMMON_H
