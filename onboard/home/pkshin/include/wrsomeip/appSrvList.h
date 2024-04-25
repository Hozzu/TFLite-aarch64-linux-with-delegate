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

/*
 * Header file of application service list implementation:
 * - define service list data types
 * - publish APIs
 */

#ifndef __INCAppSrvListh
#define __INCAppSrvListh

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* includes */

#include "someipTypes.h"
#include "serviceEntryType.h"
#include "eventGroupEntryType.h"
#include "tcpServerEndpoint.h"
#include "udpServerEndpoint.h"

/* typedefs */

typedef struct appSrvNode
{
    void* appSrv;
    struct appSrvNode* next;
} APP_SRV_NODE;

typedef struct appSrvList
{
    APP_SRV_NODE* headOff; /* offered services */
    APP_SRV_NODE* headReg; /* registered services */
    int lenOff; /* length of the offered services list */
    int lenReg; /* length of the requested services list */
} APP_SRV_LIST;

typedef struct appClntNode
{
    APP_CLNT* clnt;
    struct appClntNode* next;
} APP_CLNT_NODE;

typedef struct appClntList
{
    APP_CLNT_NODE* head;
    APP_CLNT_NODE* tail;
    int len;
} APP_CLNT_LIST;

/* function declarations */

IMPORT APP_SRV_LIST* appSrvListNew(void);
IMPORT APP_CLNT_LIST* appSrvClntListNew(void);
IMPORT void appSrvListDestroy(APP_SRV_LIST* list);
IMPORT void appSrvListOffInsertClient(APP_SRV_OFF* appSrv, APP_CLNT* clnt);
IMPORT void appSrvListOffSortInsert(APP_SRV_LIST* list, APP_SRV_OFF* appSrv);
IMPORT void appSrvListRegSortInsert(APP_SRV_LIST* list, APP_SRV_REG* appSrv);
IMPORT STATUS appSrvListDeleteService(APP_SRV_LIST* list, APP_SRV_OFF* appSrv);
IMPORT APP_SRV_NODE* appSrvListOffFindServiceInstance(APP_SRV_LIST* list, SERV_ENTRY* service);
APP_CLNT_NODE* appSrvListOffFindClient(APP_SRV_OFF* appSrv, struct sockaddr_in* cAddr);
IMPORT APP_SRV_NODE* appSrvListRegFindServiceInstance(APP_SRV_LIST* list, SERV_ENTRY* service);
IMPORT APP_SRV_LIST* appSrvListFindAllServiceInstances(APP_SRV_LIST* list, APP_SRV_OFF* appSrv);
IMPORT int appSrvListOffGetSize(APP_SRV_LIST* list);
IMPORT int appSrvListRegGetSize(APP_SRV_LIST* list);

#ifdef SOMEIP_SERV_LIST_DEBUG
IMPORT void appSrvListPrint(APP_SRV_LIST* list);
#endif /* SOMEIP_SERV_LIST_DEBUG */

#ifdef __cplusplus
}
#endif

#endif /*!defined(__INCAppSrvListh)*/
