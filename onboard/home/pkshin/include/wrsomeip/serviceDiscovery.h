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

#ifndef __INCserviceDiscoveryh
#define __INCserviceDiscoveryh

#include <sys/queue.h>

#include "someipMessage.h"
#include "serviceEntryType.h"
#include "serviceList.h"
#include "eventGroupEntryType.h"
#include "localServerEndpoint.h"
#include "localClientEndpoint.h"
#include "udpServerEndpoint.h"
#include "udpClientEndpoint.h"
#include "someipConfiguration.h"
#include "someipTimer.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
 * This module will care about routing different messages
 */

/* typedefs */

typedef struct serviceDiscovery SERVICE_DISCOVERY;

typedef struct sdServiceNode
{
    SLIST_ENTRY(sdServiceNode) node;
    serviceNode* pSn; /* service node from Router Manager */
} SD_SERVICE_NODE;

typedef SLIST_HEAD(servLst, sdServiceNode) SERV_LST;

/* node in the repetition phase timers list */

typedef struct repTimerNode
{
    SLIST_ENTRY(repTimerNode) node;
    SERVICE_DISCOVERY* pSd; /* parent */
    SOMEIP_TIMER* tmr; /* timer */
    uint32_t rep; /* current repetition */
    uint32_t del; /* delay between 2 repetitions */
    SERV_LST servEntLst; /* repetition phase entries */
    pthread_mutex_t mutex; /* mutex */
    pthread_cond_t cond; /* signal node delete */
} REP_TIMER_NODE;

typedef SLIST_HEAD(RepTmrLst, repTimerNode) REP_TMR_LST;

/* transmission session */

typedef struct sesTx
{
    SESSION session;
    BOOL reboot;
    struct addrinfo toAddr;
} SES_TX;

/* received session */

typedef struct sesRx
{
    SESSION uSession; /* unicast */
    BOOL uRebootFlag;
    SESSION mSession; /* multicast */
    BOOL mRebootFlag;
    ADDR_INFO addr; /* sender */
} SES_OP;

/* node in the received sessions list*/

typedef struct sesNode
{
    SLIST_ENTRY(sesNode) node;
    SES_OP ses;
} SES_NODE;

typedef SLIST_HEAD(sesLst, sesNode) SES_LST;

struct serviceDiscovery
{
    void* pItsApp;
    SOMEIP_CONFIGURATION* pCfg;

    uint32_t initDel; /* initial_delay       (ms) */
    uint32_t repBaseDel; /* repetion_base_delay (ms) */
    uint32_t repMax; /* repetion_max        (-) */
    uint32_t cycOffDel; /* cyclic_offer_delay  (ms) */
    uint32_t ttl; /* time_to_live        (ms) */
    uint32_t offerDebTime;
    uint32_t findDebTime;
    uint32_t ttlTime;
    uint32_t rcvTimeout;

    ADDR_INFO* curFromAddr; /* current msg remote address */

    SOMEIP_TIMER* mainPhaseTimer;
    SOMEIP_TIMER* findTimer;
    SOMEIP_TIMER* offerTimer;
    SOMEIP_TIMER* ttlTimer;
    SOMEIP_TIMER* rcvTimer;

    uint32_t maxMsgSz; /* max message size */
    uint16_t session; /* session ID */

    SES_LST sesTxLst; /* sent sessions list */
    SES_LST sesRxLst; /* received session list */

    SERV_LST colOffLst; /* collected offers list */
    SERV_LST colReqLst; /* collected requests list */
    REP_TMR_LST offRepTmrLst; /* offer rep phase timers */
    REP_TMR_LST findRepTmrLst; /* find rep phase timers */
    SERV_LST mPhOffLst; /* main phase offers list */
    pthread_mutex_t colOffLstMutex; /* mutex for collected offers list */
    pthread_mutex_t colReqLstMutex; /* mutex for collected requests list */
    pthread_mutex_t mPhOffSerListMutex; /* mutex for main phase list */
    pthread_mutex_t findRepTmrLstMutex; /* mutex for find rep phase timers */
    pthread_mutex_t offRepTmrLstMutex; /* mutex for offer rep phase timers */
};

/* event group entry specific */

typedef struct someipSdMessage
{
    void* pSd;
    SOMEIP_MESSAGE* pMsg; /* SOME/IP message */

    FLAGS flags;

    BOOL toSend; /* is used for tx or rx */

    int entCnt; /* number of entries in the list */
    ENTRY_LST entLst; /* message entries list */
    int optCnt; /* number of options in the list */
    OPT_LST optLst; /* message options list */
} SOMEIP_SD_MESSAGE;

/* function declarations */

IMPORT SERVICE_DISCOVERY* servDiscNew(void* itsApp);
IMPORT void servDiscDelete(SERVICE_DISCOVERY* pThis);
IMPORT STATUS servDiscInit(SERVICE_DISCOVERY* pThis);
IMPORT STATUS servDiscStart(SERVICE_DISCOVERY* pThis);
IMPORT STATUS
servDiscOnMessage(SERVICE_DISCOVERY* pSd, uint8_t* data, LENGTH len, ADDR_INFO* pToAddr, ADDR_INFO* pFromAddr);
IMPORT STATUS servDiscServiceOffer(SERVICE_DISCOVERY* pSd, SERVICE serv, INSTANCE inst, serviceNode* pSn);
IMPORT STATUS servDiscServiceStopOffer(SERVICE_DISCOVERY* pSd, SERVICE serv, INSTANCE inst, serviceNode* pSn);
IMPORT STATUS servDiscServiceRequest(SERVICE_DISCOVERY* pSd, SERVICE serv, INSTANCE inst, serviceNode* pSn);
IMPORT STATUS servDiscServiceStopRequest(SERVICE_DISCOVERY* pSd, SERVICE serv, INSTANCE inst);
IMPORT STATUS servDiscEvgrSubscribe(SERVICE_DISCOVERY* pSd, EVGR_ENTRY* pEe, OPT_LST* pOptLst, serviceNode* pSnOff);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __INCserviceDiscoveryh */
