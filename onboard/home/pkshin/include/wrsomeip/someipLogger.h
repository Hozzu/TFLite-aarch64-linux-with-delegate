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

#ifndef __INCsomeipLoggerh
#define __INCsomeipLoggerh

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* includes */

#include <stdint.h>

/* defines */

#define SOMEIP_LOG(level, ...) someip_logger_wrapper(level, __VA_ARGS__)

typedef enum
{
    SOMEIP_LOG_DEFAULT = -1, /**< Default log level */
    SOMEIP_LOG_OFF = 0x00, /**< Log level off */
    SOMEIP_LOG_FATAL = 0x01, /**< fatal system error */
    SOMEIP_LOG_ERROR = 0x02, /**< error with impact to correct functionality */
    SOMEIP_LOG_WARN = 0x03, /**< warning, correct behaviour could not be ensured */
    SOMEIP_LOG_INFO = 0x04, /**< informational */
    SOMEIP_LOG_DEBUG = 0x05, /**< debug  */
    SOMEIP_LOG_VERBOSE = 0x06, /**< highest grade of information */
    SOMEIP_LOG_MAX /**< maximum value, used for range check */
} someipLogLevelType;

/* function declarations */

extern void someip_logger_wrapper(int priority, const char* message, ...);
extern void someipLoggerRegApp(uint32_t appId);
extern void someipLoggerUnregApp(uint32_t appId);
extern void someipLoggerRegCtx(uint32_t ctxId);
extern void someipLoggerUnregCtx(uint32_t ctxId);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __INCsomeipLoggerh */
