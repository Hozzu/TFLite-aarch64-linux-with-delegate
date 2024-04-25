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

#ifndef __INCrouterManagerh
#define __INCrouterManagerh

/* includes */

#include "someipMessage.h"
#include "serviceEntryType.h"
#include "eventGroupEntryType.h"
#include "localServerEndpoint.h"
#include "localClientEndpoint.h"
#include "udpServerEndpoint.h"
#include "udpClientEndpoint.h"
#include "someipConfiguration.h"
#include "someipService.h"
#include "serviceDiscovery.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
 * This module will care about routing different messages
 */

/* typedefs */

typedef struct routerManager
{
    CLIENT id;
    SESSION ses;
    LCL_SRV_EPOINT* pLclSrvEp;
    SERVICE_DISCOVERY* pSd;
    void* pLclClntEp[SOMEIP_CLIENT_MAX];
    UDP_SRV_EPOINT* pSdSrvEpM; /* multicast endpoint */
    UDP_SRV_EPOINT* pSdSrvEpU; /* unicast endpoint */
    pthread_t thrIdLocalEpRcv;
    pthread_t thrIdUdpEpRcvM;
    pthread_t thrIdUdpEpRcvU;
    serviceList* pOffServ; /* offered services */
    serviceList* pReqServ; /* requested services */
    PING_LST pngLst;
    pthread_mutex_t offServMutex; /* mutex for offerd services list */
    pthread_mutex_t reqServMutex; /* mutex for requested services list */

    SOMEIP_SVC* pSvc; /* services */
} ROUTER_MANAGER;

/* function declarations */

IMPORT ROUTER_MANAGER* routerManagerNew(void);
IMPORT void routerManagerDelete(ROUTER_MANAGER* pRm);
IMPORT STATUS routerManagerCreate(ROUTER_MANAGER* pRm);
IMPORT STATUS routerManagerStart(ROUTER_MANAGER* pRm);
IMPORT serviceList* routerManagerGetOfferService(ROUTER_MANAGER* pRm,
    SD_SERVICE service,
    SD_INSTANCE instance,
    SD_MAJOR_VERSION majorV,
    SD_MINOR_VERSION minorV);
IMPORT STATUS routerManagerSdProcEntryOffer(ROUTER_MANAGER* pRm, SERV_ENTRY* pEntry, OPT_LST* pOptLst, CLIENT clnt);
IMPORT SUBS_STATE routerManagerSdProcEvgrSub(ROUTER_MANAGER* pRm, EVGR_ENTRY* pEe, OPT_LST* pOptLst);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __INCrouterManagerh */
