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
 * Header file of UDP client endpoint:
 * - define client endpoint data types
 * - publish APIs
 */

#ifndef __INCudpClientEndpointh
#define __INCudpClientEndpointh

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

typedef struct udpClntEpoint UDP_CLNT_EPOINT;
typedef void (*UDP_CLNT_EP_RCV_CBK)(UDP_CLNT_EPOINT* pSrvEp, uint8_t* pBuf, int len);

struct udpClntEpoint
{
    uint16_t id;
    void* pItsApp; /* reference to owner application */
    UDP_CLNT_EP_RCV_CBK pRcvCbk; /* receive callback */
    int sockFd; /* UDP socket */
    const char* pUnicast; /* local unicast string address */
    ADDR_INFO lAddr; /* local address */
    ADDR_INFO sAddr; /* server address */
    ADDR_INFO fromAddr; /* sender address */
    uint16_t lPort; /* local port */
    uint16_t toPort; /* destination port */
    uint16_t fromPort; /* sender port */
    volatile BOOL receiver_running; /* receiver thread running */
};

/* function declarations */

IMPORT UDP_CLNT_EPOINT* udpClientEndpointNew(void);
IMPORT void udpClientEndpointDelete(UDP_CLNT_EPOINT* pUdpCEp);
IMPORT STATUS udpClientEndpointCreate(UDP_CLNT_EPOINT* pUdpCEp);
IMPORT void udpClientEndpointListen(UDP_CLNT_EPOINT* pUdpCEp);
IMPORT void* udpClientEndpointListenPThread(void* userArgs);
IMPORT void udpClientEndpointStop(UDP_CLNT_EPOINT* pUdpCEp);
IMPORT STATUS udpClientEndpointSend(UDP_CLNT_EPOINT* pUdpCEp, uint8_t* data, uint32_t length);

#ifdef __cplusplus
}
#endif

#endif /* __INCudpClientEndpointh */
