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

#ifndef __INCserviceEntryTypeh
#define __INCserviceEntryTypeh

#include "someipSdTypes.h"
#include "someipConfiguration.h"
#include "tcpServerEndpoint.h"
#include "udpServerEndpoint.h"
#include "tcpClientEndpoint.h"
#include "udpClientEndpoint.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
 * requirement  PRS_SOMEIPSD_00268
 */

/* typedefs */

typedef struct serviceEntryType
{
    SD_TYPE type; /* offer or find */
    SD_INDEX_FIRST_OPTION idxOp1; /* first option index */
    SD_INDEX_SECOND_OPTION idxOp2; /* second option index */
    SD_NUMBER_OPTION_1 noOp1; /* first options number */
    SD_NUMBER_OPTION_2 noOp2; /* second options number */
    SD_SERVICE service; /* service id */
    SD_INSTANCE instance; /* instance id */
    SD_MAJOR_VERSION majVer; /* major version */
    SD_TTL ttl; /* lifetime of the entry (sec) */
    SD_MINOR_VERSION minVer; /* minor version */
} SERV_ENTRY;

typedef struct sdServOp
{
    SD_OPTION_LEN length;
    SD_OPTION type;
    uint8_t* pData;
} SD_SERV_OP;

typedef struct sdServOpIpv4
{
    SD_OPTION_IPV4 addr;
    SD_OPT_L4PROTO proto;
    SD_OPTION_PORT port;
} SD_SERV_OP_IPV4;

typedef struct appSrvOff /*offered service list element */
{
    void* pItsApp; /* parent application */
    SERV_ENTRY* pSe; /* service entry */
    SOMEIP_SERVICE* pCfg; /* service specific configuration */
    SOMEIP_SRV_LOC loc; /* service location */
    SOMEIP_SRV_STATE state; /* service state */
    SD_OPT_L4PROTO proto; /* reliable connection */
    UDP_SRV_EPOINT* pUdpSrvEp; /* UDP client endpoint */
    TCP_SRV_EPOINT* pTcpSrvEp; /* TCP client endpoint */
    void* pClntList; /* TCP registered clients */
    TASK_ID listenTask; /* socket listening task */
} APP_SRV_OFF;

typedef struct appSrvReg /* requested service list element */
{
    void* pItsApp; /* parent application */
    SERV_ENTRY* pSe; /* service entry */
    SOMEIP_SRV_LOC loc; /* service location */
    SOMEIP_SRV_STATE state; /* service state */
    SD_OPT_L4PROTO proto; /* reliable connection */
    SD_SERV_OP_IPV4 sdOp;
    UDP_CLNT_EPOINT* pUdpClntEp; /* UDP client endpoint */
    TCP_CLNT_EPOINT* pTcpClntEp; /* TCP client endpoint */
    TASK_ID listenTask; /* socket listening task */
} APP_SRV_REG;

typedef struct appClnt /* registered client list element */
{
    void* pItsApp; /* parent application */
    int cSock; /* socket to the client */
    struct sockaddr_in cAddr; /* client address */
    TASK_ID listenTask; /* client listening task */
} APP_CLNT;

/* function declarations */

IMPORT SERV_ENTRY* serviceEntryNew(void);
IMPORT void serviceEntryTypeDelete(SERV_ENTRY* pSe);
IMPORT APP_CLNT* appClntNew(void);
IMPORT void appClntDelete(APP_CLNT* pAc);
IMPORT APP_SRV_OFF* appSrvOffNew(void);
IMPORT void appSrvOffDelete(APP_SRV_OFF* pAs);
IMPORT APP_SRV_REG* appSrvRegNew(void);
IMPORT void appSrvRegDelete(APP_SRV_REG* pAs);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __INCserviceEntryTypeh */
