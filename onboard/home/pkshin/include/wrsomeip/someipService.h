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

#ifndef __INCsomeipServiceh
#define __INCsomeipServiceh

/* includes */

#include "someipMessage.h"
#include "someipPayload.h"
#include "localServerEndpoint.h"
#include "localClientEndpoint.h"
#include "serviceEntryType.h"
#include "eventGroupEntryType.h"

#include "appSrvList.h"
#include "someipConfiguration.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* typedefs */

typedef struct saUsedPort /* used port */
{
    SERVICE serv;
    INSTANCE inst;
    uint16_t port;
    BOOL rel;
} SA_USED_PORT;

typedef struct saUsedPortNode /* used port list node */
{
    SLIST_ENTRY(saUsedPortNode) node;
    SA_USED_PORT info;
} SA_USED_PORT_NODE;

typedef SLIST_HEAD(saUsedPortLst, saUsedPortNode) SA_USED_PORT_LST;

typedef struct endpNode
{
    pthread_t threadID;
    ENDP_TYPE type;
    uint16_t port; /* endpoint port */
    ADDR_INFO lAddr; /* local address */
    uint16_t cnt; /* use counter */
    void* pEP; /* generic endpoint */
    SLIST_ENTRY(endpNode) node;
} ENDP_NODE;

/*
 * Event Node
 * contains details about events (taken from the json configuration)
 */

typedef struct evInfo
{
    EVENT id;
    SOMEIP_EVENT* pCfg;
    BOOL isOff; /* offered/requested event */
    BOOL isFld;
    SOMEIP_MESSAGE* pMsgLoc; /* for local notifications */
    SOMEIP_MESSAGE* pMsgNet; /* for network notifications */
} EV_INFO;

typedef struct evNode
{
    EV_INFO* pInfo;
    SLIST_ENTRY(evNode) node;
} EV_NODE;

typedef SLIST_HEAD(evList_s, evNode) evList_t;

/*
 * Event Group Node
 * contains details about eventgroups (taken from the json configuration)
 */

typedef struct evgrInfo
{
    EVGR id;
    SOMEIP_EVENTGROUP* pCfg;
    ENDP_TYPE epType;
    void* pMcEp; /* multicast event group */
    evList_t evList; /* list of events */
    SUBS_LST subsList; /* list of subscribers */
    SUBS_CLNT subInfo; /* for client case */
    SUBS_STATE state; /* subscriber event group */
} EVGR_INFO;

typedef struct evgrNode
{
    EVGR_INFO* pInfo;
    SLIST_ENTRY(evgrNode) node;
} EVGR_NODE;

typedef SLIST_HEAD(evgrList_s, evgrNode) evgrList_t;

/* remote clients list */

typedef struct remClnt
{
    CLIENT clnt;
    ADDR_INFO addr;
    uint16_t port;
    TCP_RMT_EP_NODE* pRmtEpN;
} REM_CLNT;

typedef struct remClntNode
{
    REM_CLNT info;
    SLIST_ENTRY(remClntNode) node;
} REM_CLNT_NODE;

typedef SLIST_HEAD(remClntList_s, remClntNode) remClntList_t;

/* ServiceApplication - RouterManager local event handling */

typedef struct lclEvHnd
{
    LCL_CMD cmd;
    SERVICE serv;
    INSTANCE inst;
    EVENT ev;
    EVGR evgr;
    BOOL isField;
} LCL_EV_HND;

typedef struct someipSvc SOMEIP_SVC;

typedef struct srvcNode
{
    SOMEIP_SVC* pSvc; /* parent services structure */
    SERVICE serv;
    INSTANCE inst;
    SD_MAJOR_VERSION majVer;
    SD_MINOR_VERSION minVer;
    SERVICE_TYPE srvType;
    BOOL avail;
    int protocol; /* endpoint protocol */
    ENDP_NODE* pEpn; /* reference in srv/clnt ep list */
    evgrList_t evGrList; /* list of eventgroups */
    evList_t evList; /* list of events */
    SOMEIP_SERVICE* pCfg;
    CLIENT clntId;
    SESSION session;
    remClntList_t remClnt; /* remote clients */
    SLIST_ENTRY(srvcNode) node;
} SRVC_NODE;

typedef SLIST_HEAD(endpList_s, endpNode) endpList_t;
typedef SLIST_HEAD(srvList_s, srvcNode) srvList_t;

typedef void (*SVC_CBK_MSG)(SRVC_NODE* pSn, SOMEIP_MESSAGE* pMsg);

/* segment temp buffer segments */

typedef struct servAppTpRxBufMeta
{
    int32_t start;
    int32_t len;
} SERV_APP_TP_RX_BUF_META;

typedef struct servAppTpRxBuf
{
    BOOL inUse;
    BOOL lastSegRx; /* last segment received */
    SOMEIP_MESSAGE* pMsg;
    uint32_t posH; /* highest desegmented pos */
    uint32_t szH; /* highest reached size */
    SERV_APP_TP_RX_BUF_META tmpBuf[SOMEIP_TP_RX_TEMP_BUF_SIZE];
} SERV_APP_TP_RX_BUF;

struct someipSvc /* someip services */
{
    void* pParent; /* service application or router manager */
    SOMEIP_CONFIGURATION cfg;
    CLIENT clntId;
    BOOL bSesHnd; /* session handling: PRS_SOMEIP_00932 */
    SESSION session;
    pthread_mutex_t srvLstMtx; /* mutex for services list */
    srvList_t srvLst; /* service list */
    endpList_t servEPLst; /* server endpoints list */
    endpList_t clntEPLst; /* client endpoints list */
    SA_USED_PORT_LST usedPortList; /* client used ports lists */
    SERV_APP_TP_RX_BUF tpRxBuf[SOMEIP_TP_RX_BUF_SIZE];
    SVC_CBK_MSG pCbkMsg;
    BOOL isApp; /* ServiceApplication or RouterManager */
    BOOL bEvEp; /* events endpoint handling */
};

/* function declarations */

IMPORT SOMEIP_SVC* someipSvcNew(BOOL isApp);
IMPORT void someipSvcDelete(SOMEIP_SVC* pSvc);
IMPORT SRVC_NODE* svcServNodeCreate(SOMEIP_SVC* pSvc,
    SERVICE serv,
    INSTANCE inst,
    MAJOR_VERSION majVer,
    MINOR_VERSION minVer);
void svcServNodeDelete(SRVC_NODE* pSn);
IMPORT void svcServNodeRemove(SRVC_NODE* pSrvNode);
IMPORT SRVC_NODE* svcFindService(SOMEIP_SVC* pSvc, SERVICE serv, INSTANCE inst, SERVICE_TYPE svcType);
IMPORT SRVC_NODE* svcFindServiceByEp(SOMEIP_SVC* pSvc, SERVICE serv, void* pEp);
IMPORT ENDP_NODE* svcFindEndp(endpList_t* list, uint16_t port, ENDP_TYPE endpType);
IMPORT EV_NODE* svcCreateEvNode(SRVC_NODE* pSn, EVENT ev, BOOL isFld);
IMPORT EVGR_NODE* svcCreateEvgrNode(SRVC_NODE* pSn, EVGR evgr);
IMPORT STATUS svcRegisterEv(SRVC_NODE* pSn, EV_NODE* pEvN, EVGR_NODE* pEvgrN);
IMPORT STATUS svcUnregisterEv(SRVC_NODE* pSn, EV_NODE* pEvN, EVGR_NODE* pEvgrN);
IMPORT EVGR_NODE* svcFindEvgrNode(evgrList_t* pEvgrLst, SD_EVENT_GROUP evgr);
IMPORT EV_NODE* svcFindEvInSn(SRVC_NODE* pSn, EVENT ev);
IMPORT EVGR_NODE* svcFindEvGrInSn(SRVC_NODE* pSn, EVGR evgr);
IMPORT EV_NODE* svcFindEvInEvgrN(EVGR_NODE* pEvGrN, EVENT ev);
IMPORT SUBS_NODE* svcSrvFindEvgrSub(SUBS_LST* pSubsList, SUBS_CLNT* pSubInfo);
IMPORT SUBS_NODE* svcSrvAddSubs(SRVC_NODE* pSn, EVGR_NODE* pEgn, SUBS_CLNT* pSubInfo);
IMPORT void svcSrvRemSubs(SRVC_NODE* pSn, EVGR_NODE* pEgn, SUBS_NODE* pSbn);
IMPORT void svcSessionTxInc(SRVC_NODE* pSn);
IMPORT STATUS svcServNodeSrvEpAttach(SRVC_NODE* pSn);
IMPORT STATUS svcServNodeSrvEpDettach(SRVC_NODE* pSn);
IMPORT STATUS svcServNodeClntEpAttach(SRVC_NODE* pSn, ADDR_INFO* pSrvAddr, CLIENT clnt, ENDP_TYPE endpType);
IMPORT STATUS svcServNodeClntEpDettach(SRVC_NODE* pSn);
IMPORT STATUS svcTpTxStart(SOMEIP_SVC* pSvc, SRVC_NODE* pSn, SOMEIP_MESSAGE* pMsg);
IMPORT STATUS svcSdGetEpAddr(SOMEIP_SVC* pSvc, OP_IPV4_6* pSrvEndp, ADDR_INFO* pAddr, ENDP_TYPE* pEpType);
IMPORT STATUS svcRemClntGet(SRVC_NODE* pSn, CLIENT clnt, REM_CLNT* pRemClnt);
IMPORT SRVC_NODE* svcFindReqServiceByClnt(SOMEIP_SVC* pSvc, SERVICE serv, INSTANCE inst, CLIENT clnt);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __INCsomeipServiceh */
