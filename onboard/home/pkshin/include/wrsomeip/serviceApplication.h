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

#ifndef __INCserviceApplicationh
#define __INCserviceApplicationh

/* includes */

#include "someipMessage.h"
#include "someipPayload.h"
#include "localServerEndpoint.h"
#include "localClientEndpoint.h"
#include "serviceEntryType.h"
#include "eventGroupEntryType.h"

#include "appSrvList.h"
#include "someipConfiguration.h"
#include "someipService.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* typedefs */

typedef struct serviceApplication SERVICE_APPLICATION;

/* message callback */

typedef void (*SA_CBK_MSG)(SERVICE_APPLICATION* pSrvApp, SOMEIP_MESSAGE* pMsg);

typedef struct saMSgCbk /* callback info */
{
    SERVICE serv;
    INSTANCE inst;
    METHOD meth;
    SA_CBK_MSG pCbk;
} SA_MSG_CBK;

typedef struct saMsgCbkNode /* callback list node */
{
    SLIST_ENTRY(saMsgCbkNode) node;
    SA_MSG_CBK info;
} SA_MSG_CBK_NODE;

typedef SLIST_HEAD(saMsgCbkLst, saMsgCbkNode) SA_MSG_CBK_LST;

/* availability */

typedef void (*SA_CBK_AVL)(SERVICE_APPLICATION* pSrvApp, SERVICE srv, INSTANCE inst, BOOL avl);

typedef struct saAvlCbk /* callback info */
{
    SERVICE serv;
    INSTANCE inst;
    SA_CBK_AVL pCbk;
} SA_AVL_CBK;

typedef struct saAvlCbkNode /* callback list node */
{
    SLIST_ENTRY(saAvlCbkNode) node;
    SA_AVL_CBK info;
} SA_AVL_CBK_NODE;

typedef SLIST_HEAD(saAvlCbkLst, saAvlCbkNode) SA_AVL_CBK_LST;

/* subscription */

typedef void (*SA_CBK_SUB)(SERVICE_APPLICATION* pSrvApp, SERVICE srv, INSTANCE inst, EVGR evgr, SUBS_STATE subSt);

typedef struct saSubCbk /* callback info */
{
    SERVICE serv;
    INSTANCE inst;
    EVGR evgr;
    SA_CBK_SUB pCbk;
} SA_SUB_CBK;

typedef struct saSubCbkNode /* callback list node */
{
    SLIST_ENTRY(saSubCbkNode) node;
    SA_SUB_CBK info;
} SA_SUB_CBK_NODE;

typedef SLIST_HEAD(saSubCbkLst, saSubCbkNode) SA_SUB_CBK_LST;

struct serviceApplication
{
    LCL_SRV_EPOINT* pLclSrvEndp;
    LCL_CLNT_EPOINT* pLclClntRMEndp;
    pthread_t threadID;
    SA_AVL_CBK_LST cbkListAvail; /* availability callbacks */
    SA_MSG_CBK_LST cbkListMsg; /* message callbacks */
    SA_SUB_CBK_LST cbkListSub; /* subscription callbacks */
    SOMEIP_TIMER* tmrPing;
    uint8_t pingCount;

    SOMEIP_SVC* pSvc; /* services */
};

/* function declarations */

IMPORT SERVICE_APPLICATION* servAppNew(const char* pAppName);
IMPORT void servAppDelete(SERVICE_APPLICATION* pSa);
IMPORT STATUS servAppCreate(SERVICE_APPLICATION* pSa);
IMPORT STATUS servAppStart(SERVICE_APPLICATION* pSa);
IMPORT void servAppStop(SERVICE_APPLICATION* pSa);
IMPORT STATUS servAppOfferServ(SERVICE_APPLICATION* pSa,
    SERVICE service,
    INSTANCE instance,
    MAJOR_VERSION majVer,
    MINOR_VERSION minVer);
IMPORT STATUS servAppStopOfferServ(SERVICE_APPLICATION* pSa,
    SERVICE service,
    INSTANCE instance,
    MAJOR_VERSION majVer,
    MINOR_VERSION minVer);
IMPORT STATUS servAppRequestServ(SERVICE_APPLICATION* pSa,
    SERVICE service,
    INSTANCE instance,
    MAJOR_VERSION majVer,
    MINOR_VERSION minVer);
IMPORT STATUS servAppReleaseServ(SERVICE_APPLICATION* pSa,
    SERVICE service,
    INSTANCE instance,
    MAJOR_VERSION majVer,
    MINOR_VERSION minVer);
IMPORT STATUS servAppSend(SERVICE_APPLICATION* pSa, SOMEIP_MESSAGE* pMsg);
IMPORT STATUS servAppOfferEvent(SERVICE_APPLICATION* pSa,
    SERVICE service,
    INSTANCE instance,
    EVENT evnt,
    EVGR eventGroup,
    BOOL isField);
IMPORT STATUS
servAppStopOfferEvent(SERVICE_APPLICATION* pSa, SERVICE service, INSTANCE instance, EVENT event, EVGR evGroup);
IMPORT STATUS servAppRequestEvent(SERVICE_APPLICATION* pSa,
    SERVICE service,
    INSTANCE instance,
    EVENT event,
    EVGR eventGroup,
    BOOL isField);
IMPORT STATUS
servAppReleaseEvent(SERVICE_APPLICATION* pSa, SERVICE service, INSTANCE instance, EVENT event, EVGR eventGroup);
IMPORT STATUS servAppSubscribe(SERVICE_APPLICATION* pSa,
    SERVICE service,
    INSTANCE instance,
    EVGR evgr,
    MAJOR_VERSION majVer,
    EVENT event);
IMPORT STATUS servAppUnsubscribe(SERVICE_APPLICATION* pSa, SERVICE service, INSTANCE instance, EVGR eventGroup);
IMPORT STATUS
servAppNotify(SERVICE_APPLICATION* pSa, SERVICE service, INSTANCE instance, EVENT ev, SOMEIP_PAYLOAD* pPld);
IMPORT void servAppRegMsgHnd(SERVICE_APPLICATION* pSa,
    SERVICE service,
    INSTANCE instance,
    METHOD method,
    SA_CBK_MSG pMsgCbk);
IMPORT void servAppUnregMsgHnd(SERVICE_APPLICATION* pSa, SERVICE service, INSTANCE instance, METHOD meth);
IMPORT void servAppRegAvailHnd(SERVICE_APPLICATION* pSa, SERVICE service, INSTANCE instance, SA_CBK_AVL pAvlCbk);
IMPORT void servAppUnregAvailHnd(SERVICE_APPLICATION* pSa, SERVICE service, INSTANCE instance);
IMPORT void servAppRegSubHnd(SERVICE_APPLICATION* pSa,
    SERVICE service,
    INSTANCE instance,
    EVGR eventGroup,
    SA_CBK_SUB pSubCbk);
IMPORT void servAppUnregSubHnd(SERVICE_APPLICATION* pSa, SERVICE service, INSTANCE instance, EVGR evgr);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __INCserviceApplicationh */
