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

#ifndef __INCsomeipMessageh
#define __INCsomeipMessageh

#include <wrsomeip/someipTypes.h>
#include <wrsomeip/someipSerial.h>
#include <wrsomeip/someipPayload.h>
#include <wrsomeip/someipTimer.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define SOMEIP_MSG_TYPE_IS_REQ_ANY(type) (((type) == E_REQUEST) || ((type) == E_REQUEST_NO_RETURN))
#define SOMEIP_MSG_TYPE_IS_REQ(type) ((type) == E_REQUEST)
#define SOMEIP_MSG_TYPE_IS_REQ_NR(type) ((type) == E_REQUEST_NO_RETURN)
#define SOMEIP_MSG_TYPE_IS_RESP(type) ((type) == E_RESPONSE)
#define SOMEIP_MSG_TYPE_IS_NOTIF(type) ((type) == E_NOTIFICATION)
#define SOMEIP_MSG_IS_REQ_ANY(pMsg) SOMEIP_MSG_TYPE_IS_REQ_ANY(pMsg->pHdr->msgType)
#define SOMEIP_MSG_IS_REQ(pMsg) SOMEIP_MSG_TYPE_IS_REQ(pMsg->pHdr->msgType)
#define SOMEIP_MSG_IS_REQ_NR(pMsg) SOMEIP_MSG_TYPE_IS_REQ_NR(pMsg->pHdr->msgType)
#define SOMEIP_MSG_IS_RESP(pMsg) SOMEIP_MSG_TYPE_IS_RESP(pMsg->pHdr->msgType)
#define SOMEIP_MSG_IS_NOTIF(pMsg) SOMEIP_MSG_TYPE_IS_NOTIF(pMsg->pHdr->msgType)
#define SOMEIP_MSG_TYPE_IS_TP(type) (((type)&SOMEIP_TP_MESSAGE_TYPE) == SOMEIP_TP_MESSAGE_TYPE)
#define SOMEIP_MSG_IS_TP(pMsg) SOMEIP_MSG_TYPE_IS_TP(pMsg->pHdr->msgType)
#define SOMEIP_MSG_TP_HDR_TO_OFFSET(tpHdr) ((TP_OFFSET)(tpHdr & SOMEIP_TP_OFFSET_MASK))
#define SOMEIP_MSG_TP_HDR_TO_MORE(tpHdr) ((TP_MORE)((tpHdr >> SOMEIP_TP_MORE_POS) & SOMEIP_TP_MORE_MASK))

/* typedefs */

typedef struct someipHeader
{
    void* pItsMsg;
    SERVICE service;
    METHOD method;
    LENGTH length;
    CLIENT client;
    CLIENT clientFrom;
    SESSION session;
    PROTOCOL_VERSION protVer;
    INTERFACE_VERSION ifaceVer;
    MESSAGE_TYPE msgType;
    RETURN_CODE retCode;
    INSTANCE instance;
} SOMEIP_HEADER;

typedef struct someipMessage
{
    void* pParent; /* parent container */
    uint8_t* pData; /* output data */
    uint8_t* pLData; /* local data */
    uint32_t sz; /* message allocated size */
    uint32_t len; /* message actual length */
    BOOL reliable; /* connection type */
    BOOL isLoc; /* local message */
    SOMEIP_HEADER* pHdr; /* message header */
    SOMEIP_SERIAL* pSer; /* serializer */
    SOMEIP_PAYLOAD* pPld; /* payload */
} SOMEIP_MESSAGE;

typedef struct someipMessageTp
{
    SOMEIP_PAYLOAD* pPld; /* original message payload */
    SOMEIP_MESSAGE* pMsgSeg; /* segment message on the network */
    uint32_t initDel; /* initial send delay (ms) */
    uint32_t segDel; /* delay between 2 sent segments (ms) */
    uint32_t segPldMaxSize; /* maximum segment payload size (bytes) */
    uint32_t segCnt; /* segments to be sent */
    uint32_t curSeg; /* current segment */
    uint32_t pos; /* current position in TP payload */
    uint32_t pldSize; /* original payload size */
    SOMEIP_TIMER* pTmr;
} SOMEIP_MESSAGE_TP;

/* function declarations */

IMPORT SOMEIP_HEADER* someipHeaderNew(void);
IMPORT void someipHeaderDelete(SOMEIP_HEADER* pHdr);
IMPORT SOMEIP_MESSAGE* someipMessageNew(void);
IMPORT void someipMessageDelete(SOMEIP_MESSAGE* pMsg, BOOL is_rcv_msg);
IMPORT STATUS someipMessageInit(SOMEIP_MESSAGE* pMsg);
IMPORT BOOL someipMessageHeaderSerial(SOMEIP_MESSAGE* pMsg);
IMPORT BOOL someipMessageHeaderDeserial(SOMEIP_MESSAGE* pMsg);
IMPORT SOMEIP_MESSAGE* someipCreateRequest(BOOL reliable);
IMPORT SOMEIP_MESSAGE* someipCreateResponse(SOMEIP_MESSAGE* pMsgReq);
IMPORT SOMEIP_MESSAGE* someipCreateNotifMsg(BOOL reliable);
IMPORT SOMEIP_MESSAGE* someipCreateRecvMsg(uint8_t* pData, uint32_t len);
IMPORT SOMEIP_MESSAGE_TP* someipMsgTpNew(void);
IMPORT void someipMsgTpDelete(SOMEIP_MESSAGE_TP* pMsgTp);
IMPORT SOMEIP_MESSAGE_TP* someipMsgTpTxCreate(SOMEIP_MESSAGE* pMsgTx);
IMPORT STATUS someipMsgTpTxStart(SOMEIP_MESSAGE_TP* pMsgTp, SOMEIP_TIMER_CONNECT_FUNC handler);
IMPORT STATUS someipMsgTpTxNext(SOMEIP_MESSAGE_TP* pMsgTp, uint32_t delay);
IMPORT void someipMsgTpTxStop(SOMEIP_MESSAGE_TP* pMsgTp);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __INCsomeipMessageh */
