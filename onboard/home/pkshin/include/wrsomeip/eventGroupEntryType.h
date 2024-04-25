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

#ifndef __INCeventGroupEntryTypeh
#define __INCeventGroupEntryTypeh

#include "someipSdTypes.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * \requirement  PRS_SOMEIPSD_00270
 */

/* typedefs */

typedef struct evgrEntry
{
    SD_TYPE type; /* subscribe or subscribeAck */
    SD_INDEX_FIRST_OPTION idxOp1; /* first option index */
    SD_INDEX_SECOND_OPTION idxOp2; /* second option index */
    SD_NUMBER_OPTION_1 noOp1; /* first options number */
    SD_NUMBER_OPTION_2 noOp2; /* second options number */
    SD_SERVICE service; /* service id */
    SD_INSTANCE instance; /* instance id */
    SD_MAJOR_VERSION majVer; /* major version */
    SD_TTL ttl; /* lifetime of the entry (sec) */
    SD_RESERVED res; /* reserved */
    SD_INITIAL_FLAG init; /* initial request flag */
    SD_RESERVED_2 res2; /* reserved 2 */
    SD_COUNTER cnt; /* counter */
    SD_EVENT_GROUP evgr; /* event group id */
} EVGR_ENTRY;

/* function declarations */

EVGR_ENTRY* eventGroupEntryTypeNew(void);
void eventGroupEntryTypeDelete(EVGR_ENTRY* pEvGrp);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __INCeventGroupEntryTypeh */
