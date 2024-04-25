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
 * Header file of TCP client endpoint:
 * - define client endpoint data types
 * - publish APIs
 */

#ifndef __INCtcpClientEndpointh
#define __INCtcpClientEndpointh

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* includes */

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "someipTypes.h"

/* typedefs */

typedef struct tcpClntEpoint TCP_CLNT_EPOINT;
typedef void (*TCP_CLNT_EP_RCV_CBK)(TCP_CLNT_EPOINT* pSrvEp, uint8_t* pBuf, int len);

struct tcpClntEpoint
{
    uint16_t id;
    void* pItsApp; /* reference to owner application */
    TCP_CLNT_EP_RCV_CBK pRcvCbk; /* receive callback */
    int sockFd; /* socket file descriptor */
    const char* pUnicast; /* local unicast string address */
    ADDR_INFO lAddr; /* local address */
    ADDR_INFO sAddr; /* server address */
    uint16_t lPort; /* local port */
    uint16_t sPort; /* server port */
    volatile BOOL isConnected; /* connection established */
    volatile BOOL isConnectionClosed; /* connection closed by server*/
    pthread_mutex_t tcpMutex; /* sync the access to isCon flag */
};

/* function declarations */

IMPORT TCP_CLNT_EPOINT* tcpClientEndpointNew(void);
IMPORT void tcpClientEndpointDelete(TCP_CLNT_EPOINT* pTcpCEp);
IMPORT STATUS tcpClientEndpointCreate(TCP_CLNT_EPOINT* pTcpCEp);
IMPORT STATUS tcpClientEndpointSend(TCP_CLNT_EPOINT* pTcpCEp, uint8_t* data, uint32_t length);
IMPORT void tcpClientEndpointListen(TCP_CLNT_EPOINT* pTcpCEp);
IMPORT void tcpClientEndpointStop(TCP_CLNT_EPOINT* pTcpCEp);
IMPORT void* tcpClientEndpointListenPThread(void* userArgs);

#ifdef __cplusplus
}
#endif

#endif /* __INCtcpClientEndpointh */
