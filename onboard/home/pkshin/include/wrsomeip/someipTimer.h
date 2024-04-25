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

#include <signal.h>
#include <time.h>
#include <stdint.h>

#include "osal.h"

#ifndef __INCsomeipTimerh
#    define __INCsomeipTimerh

#    ifdef __cplusplus
extern "C" {
#    endif /* __cplusplus */

/* typedefs */

typedef struct someipTimer SOMEIP_TIMER;
typedef void (*SOMEIP_TIMER_CONNECT_FUNC)(SOMEIP_TIMER* pTimer, void* arg);

typedef enum timerState
{
    TIMER_STATE_INIT = 0,
    TIMER_STATE_RUNNING,
} TIMER_STATE;

typedef enum timerOp
{
    TIMER_OP_NOP = 0,
    TIMER_OP_SET,
    TIMER_OP_DESTROY
} TIMER_OP;

struct someipTimer
{
    pthread_t thread; /* background thread */
    pthread_mutex_t mutex; /* mutex */

    pthread_cond_t newOpCond; /* signal new op */
    pthread_cond_t ackOpCond; /* signal op completion */
    uint32_t opId; /* operation id, differentiate op */
    TIMER_OP op; /* operation (set, get, stop) */
    uint32_t msecTimeout; /* timeout in msec */

    pthread_cond_t threadCond; /* thread count condition */
    uint32_t threadCount; /* number of running threads */

    TIMER_STATE state; /* current state */
    struct timespec setTime; /* next calculated timeout */
    SOMEIP_TIMER_CONNECT_FUNC handler; /* handler */
    void* arg; /* handler arguments */
};

extern SOMEIP_TIMER* timerCreate(void);
extern int timerDelete(SOMEIP_TIMER* pTimer);
extern int timerSetTime(SOMEIP_TIMER* pTimer, uint32_t msecTimeout);
extern int timerGetTime(SOMEIP_TIMER* pTimer, uint32_t* msecRem);
extern void timerConnect(SOMEIP_TIMER* pTimer, SOMEIP_TIMER_CONNECT_FUNC routine, void* arg);
extern int timerCancel(SOMEIP_TIMER* pTimer);

#    ifdef __cplusplus
}
#    endif /* __cplusplus */

#endif /*!__INCsomeipTimerh */
