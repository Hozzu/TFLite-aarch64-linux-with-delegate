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
 * Header file of TCP server endpoint:
 * - define server endpoint data types
 * - publish APIs
 */

#ifndef __INCtcpServerEndpointh
#define __INCtcpServerEndpointh

/* includes */

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/queue.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* typedefs */

typedef struct tcpSrvEpoint TCP_SRV_EPOINT;

typedef struct tcpRmtEpInfo
{
    TCP_SRV_EPOINT* pSrvEp;
    int sockFd;
    ADDR_INFO rAddr;
    uint16_t rPort;
    pthread_t thrId;
} TCP_RMT_EP_INFO;

typedef struct tcpRmtEpNode
{
    TCP_RMT_EP_INFO info;
    SLIST_ENTRY(tcpRmtEpNode) node;
} TCP_RMT_EP_NODE;

typedef SLIST_HEAD(tcpRmtEpList_s, tcpRmtEpNode) TCP_RMT_EP_LIST;

typedef void (*TCP_SRV_EP_RCV_CBK)(TCP_RMT_EP_NODE* pRmtEpN, uint8_t* pBuf, int len);
typedef void (*TCP_SRV_EP_ACK_CBK)(TCP_RMT_EP_NODE* pRmtEpN);

struct tcpSrvEpoint
{
    uint16_t id;
    VOID* pItsApp; /* reference to owner application */
    TCP_SRV_EP_RCV_CBK pRcvCbk; /* receive callback */
    TCP_SRV_EP_ACK_CBK pAcceptCbk; /* accept callback */
    int sockFd; /* socket file descriptor */
    int sockFdCl; /* client socket */
    const char* pUnicast; /* local unicast string address */
    ADDR_INFO lAddr; /* local address */
    uint16_t lPort; /* local port */
    TCP_RMT_EP_LIST rmtEpLst; /* remote endpoints list */
    volatile BOOL isConnectionClosed;
    pthread_mutex_t tcpMutex;
};

typedef struct tcpSrvEpRcvArg
{
    TCP_SRV_EPOINT* pTcpSrvEp; /* reference to server endpoint */
    int sock; /* socket status */
} TCP_SRV_EP_RCV_ARG;

/* function declarations */

IMPORT TCP_SRV_EPOINT* tcpServerEndpointNew(void);
IMPORT void tcpServerEndpointDelete(TCP_SRV_EPOINT* pTcpSEp);
IMPORT STATUS tcpServerEndpointCreate(TCP_SRV_EPOINT* pTcpSEp);
IMPORT void tcpServerEndpointListen(TCP_SRV_EPOINT* pTcpSEp);
IMPORT void* tcpSrvEpLstnThrd(void* userArgs);
IMPORT STATUS tcpServerEndpointSend(TCP_RMT_EP_NODE* pRmtEpN, uint8_t* data, uint32_t length);
IMPORT void tcpServerEndpointStop(TCP_SRV_EPOINT* pTcpSEp);
IMPORT TCP_RMT_EP_NODE* tcpServerGetRmtEpByAddr(TCP_SRV_EPOINT* pTcpSEp, ADDR_INFO* pAddrInfo);

#ifdef __cplusplus
}
#endif

#endif /*!defined(__INCtcpServerEndpointh)*/
