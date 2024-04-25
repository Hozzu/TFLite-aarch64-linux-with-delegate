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

#ifndef __INClocalClientEndpointh
#define __INClocalClientEndpointh

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <wrsomeip/someipTypes.h>
#include <mqueue.h>

/* defines */

#define SOMEIP_MQ_NAME_LEN 17
#define SOMEIP_MAX_MSG_NR 5

/* typedefs */

typedef struct lclClntEpoint
{
    uint16_t id;
    mqd_t mqd;
} LCL_CLNT_EPOINT;

/* function declarations */

IMPORT LCL_CLNT_EPOINT* localClientEndpointNew(void);
IMPORT void localClientEndpointDelete(LCL_CLNT_EPOINT* pLclClntEndp);
IMPORT STATUS localClientEndpointCreate(LCL_CLNT_EPOINT* pLclClntEndp);
IMPORT STATUS localClientEndpointSend(LCL_CLNT_EPOINT* pLclClntEndp, uint8_t* pData, uint32_t length);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __INClocalClientEndpointh */
