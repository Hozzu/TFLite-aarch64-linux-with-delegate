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

#ifndef __INCsomeipUtilh
#define __INCsomeipUtilh

/* includes */

#include <arpa/inet.h>
#include <wrsomeip/someipTypes.h>
#include <string.h>
#include <netdb.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* defines */

#define SOMEIP_IP_AF_NA "Unknown AF"

#ifdef SOMEIP_COM_RM
#    define SOMEIP_USE_RM_COM TRUE
#else
#    define SOMEIP_USE_RM_COM FALSE
#endif

#ifndef AR_UNUSED
#    if defined(__GNUC__) && (__GNUC__ >= 3)
#        define AR_UNUSED __attribute__((__unused__))
#    else
#        define AR_UNUSED /* ignore */
#    endif
#endif

// A static assertion emulation
// The second macro argument must only contain characters that are valid as part of a C identifier.
#define STATIC_ASSERT(COND, MSG) typedef char static_assertion_##MSG[(COND) ? 1 : -1] AR_UNUSED

/* function declarations */

IMPORT STATUS someipGetAddrInfo(const char* pAddrStr, uint16_t port, int socktype, ADDR_INFO* pAddrInfo);
IMPORT char* someipGetIpStr(const struct sockaddr* pSa, char* pStr, size_t maxlen);
IMPORT void someipBufferPrint(const char* pName, uint8_t* pBuf, uint32_t sz, PRINT_MODE mode);
IMPORT const char* someipGetEpType(ENDP_TYPE ep);
IMPORT void someipGetMsgTypeStr(MESSAGE_TYPE msgType, char* msgStr);

IMPORT int someipThreadCreate(pthread_t* thread, void* (*startRoutine)(void*), void* arg, const char* name);

IMPORT int timespec_add_ms(struct timespec* ts, long milliseconds);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /*!__INCsomeipUtilh */
