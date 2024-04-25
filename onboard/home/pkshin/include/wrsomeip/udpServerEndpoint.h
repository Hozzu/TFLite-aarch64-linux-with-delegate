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
 * Header file of UDP server endpoint:
 * - define server endpoint data types
 * - publish APIs
 */

#ifndef __INCudpServerEndpointh
#define __INCudpServerEndpointh

/* includes */

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <netdb.h>

#include "someipTypes.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* typedefs */

typedef struct udpSrvEpoint UDP_SRV_EPOINT;
typedef void (*UDP_SRV_EP_RCV_CBK)(UDP_SRV_EPOINT* pSrvEp, uint8_t* pBuf, int len);

struct udpSrvEpoint
{
    uint16_t id;
    void* pItsApp;
    UDP_SRV_EP_RCV_CBK pRcvCbk; /* receive callback */
    int sockFd; /* UDP socket */
    BOOL mcast;
    const char* pUnicast;
    const char* pMulticast;
    ADDR_INFO mAddr; /* multicast address */
    ADDR_INFO lAddr; /* local address */
    ADDR_INFO* pToAddr; /* destination address */
    ADDR_INFO fromAddr; /* sender address */
    uint16_t lPort; /* local port */
    uint16_t toPort; /* destination port */
    uint16_t fromPort; /* sender port */
    volatile BOOL receiver_running; /* receiver thread running */
};

/* function declarations */

IMPORT UDP_SRV_EPOINT* udpServerEndpointNew(void);
IMPORT void udpServerEndpointDelete(UDP_SRV_EPOINT* pUdpSEp);
IMPORT STATUS udpServerEndpointCreate(UDP_SRV_EPOINT* pUdpSEp);
IMPORT void udpServerEndpointListen(UDP_SRV_EPOINT* pUdpSEp);
IMPORT void* udpSrvEpLstnThrd(void* pUserArgs);
IMPORT void udpServerEndpointStop(UDP_SRV_EPOINT* pUdpSEp);
IMPORT STATUS udpServerEndpointSend(UDP_SRV_EPOINT* pUdpSEp, uint8_t* pData, uint32_t length);

#ifdef __cplusplus
}
#endif

#endif /*!defined(__INCudpServerEndpointh)*/
