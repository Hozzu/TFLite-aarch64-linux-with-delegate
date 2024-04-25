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
 * Header file of service list implementation:
 * - define service list data types
 * - publish APIs
 */

#ifndef __INCserviceListh
#define __INCserviceListh

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* includes */

#include "someipTypes.h"
#include "serviceEntryType.h"
#include "eventGroupEntryType.h"
#include "someipService.h"

#define MAX_EVGR_PER_SERV 10
#define MAX_CLT_PER_EVGR 100

#define EV_GROUP_ID_POS 0
#define NR_CLIENTS_POS 1

#define PRINT_OPTION_INFO_LEN 40

/* typedefs */

typedef struct subEvgr
{
    EVGR evgr;
    SUBS_STATE state;
} SUB_EVGR;

typedef struct rmSubsClnt
{
    CLIENT clnt;
    OP_IPV4_6 ipOp;
    SD_COUNTER cnt;
} RM_SUBS_CLNT;

typedef struct rmSubsInfo
{
    SUB_EVGR evgr;
    RM_SUBS_CLNT clnt;
} RM_SUBS_INFO;

typedef struct rmSubsNode
{
    RM_SUBS_INFO info;
    SLIST_ENTRY(rmSubsNode) node;
} RM_SUBS_NODE;

typedef SLIST_HEAD(rmSubsLst, rmSubsNode) RM_SUBS_LST;

typedef struct _serviceNode
{
    SERV_ENTRY s;
    CLIENT c;
    OPT_LST sdOptLst;
    BOOL isLocal;
    BOOL isMainPhase;
    uint8_t nrEventGroups;
    RM_SUBS_LST subsLst;
    uint32_t noSub; /* number of total subscriptions */
    uint32_t noSubPend; /* number of pending subscriptions */
    SRVC_NODE* pSn; /* service node */
    SLIST_ENTRY(_serviceNode) node;
} serviceNode;

typedef SLIST_HEAD(_serviceList, _serviceNode) serviceList;

/* function declarations */

IMPORT serviceList* serviceListNew(void);
IMPORT void serviceListDestroy(serviceList* pList);
IMPORT serviceNode* serviceListSortInsert(serviceList* pList,
    SERV_ENTRY* pSe,
    CLIENT clientId,
    OPT_LST* pOptLst,
    BOOL isLocal);
IMPORT STATUS serviceListDeleteService(serviceList* pList, SERV_ENTRY* pSe);
IMPORT serviceNode* serviceListFindServiceInstance(serviceList* pList, SERV_ENTRY* pSe, CLIENT clnt);
IMPORT serviceList* serviceListFindAllServiceInstances(serviceList* pList, SERV_ENTRY* pSe);
IMPORT serviceNode* serviceListEventGroupSearch(serviceList* pList, SD_EVENT_GROUP event);
IMPORT CLIENT serviceListClientFind(serviceList* pList, SD_SERVICE service);
IMPORT serviceList* serviceListGetLocalOfferServices(serviceList* pList,
    SD_SERVICE service,
    SD_INSTANCE instance,
    SD_MAJOR_VERSION majorV,
    SD_MINOR_VERSION minorV);
IMPORT OPT_LST* serviceListDuplicateOptionsList(OPT_LST* pOptLst);

#ifdef SOMEIP_SERV_LIST_DEBUG
IMPORT void serviceListPrint(serviceList* pList);
#endif

#ifdef __cplusplus
}
#endif

#endif /*!defined(__INCserviceListh)*/
