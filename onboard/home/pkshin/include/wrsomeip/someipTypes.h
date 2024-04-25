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

#ifndef __INCsomeipTypesh
#define __INCsomeipTypesh

/* includes */

#include <wrsomeip/osal.h>
#include "sys/queue.h"
#include "errno.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* defines */

#define SOMEIP_PING_PERIOD_MSEC 5000 /* value in milliseconds */
#define SOMEIP_PING_PERIOD_MULT 2
#define NSECS_PER_MSEC (1000 * 1000)
#define MSEC_PER_SEC (1000)
#define MSEC_TO_NSEC(ms) (((ms) % MSEC_PER_SEC) * NSECS_PER_MSEC)
#define MSEC_TO_SEC(ms) ((ms) / MSEC_PER_SEC)
#define SEC_NSEC_TO_MS(sec, nsec) (((sec)*MSEC_PER_SEC) + ((nsec) / NSECS_PER_MSEC))

#define SOMEIP_TP_TX_INIT_DELAY_DEF (100) /* default init tx delay (ms) */
#define SOMEIP_TP_TX_SEG_DELAY_DEF (100) /* default segment tx delay (ms) */
#define SOMEIP_TP_ALIGN_WORD_SIZE (16) /* alignment word size (bytes) */
#define SOMEIP_TP_MAX_WORDS (87) /* max number of words in seg */
#define SOMEIP_TP_MAX_SEG_PLD_SIZE (SOMEIP_TP_MAX_WORDS * SOMEIP_TP_ALIGN_WORD_SIZE)
#define SOMEIP_TP_MESSAGE_TYPE (0x20) /* TP flag in message type */
#define SOMEIP_TP_HDR_LEN (4) /* TP header length */
#define SOMEIP_TP_OFFSET_POS (4) /* 24 bits starting with pos 4 */
#define SOMEIP_TP_OFFSET_MASK (0xFFFFFFF0)
#define SOMEIP_TP_FLAG_MORE_SEG_OFF (0x00000000)
#define SOMEIP_TP_FLAG_MORE_SEG_ON (0x00000001)
#define SOMEIP_TP_MORE_POS (0)
#define SOMEIP_TP_MORE_MASK (0x00000001)
#define SOMEIP_TP_RX_BUF_SIZE (10) /* PRS_SOMEIP_00743 */
#define SOMEIP_TP_RX_TEMP_BUF_SIZE (4) /* PRS_SOMEIP_00748 */
#define SOMEIP_TP_RX_SEG_LEN_NA (-1)
#define SOMEIP_TP_RX_SEG_START_NA (-1)
#define SOMEIP_TP_PLD_POS (32 + 4) /* payload pos in TP msg */

#define SOMEIP_ROUTER_LOCAL_SOCKET_ID 0xFFFF
#define SOMEIP_DAEMON_APP_ID SOMEIP_ROUTER_LOCAL_SOCKET_ID
#define SOMEIP_CLIENT_INVALID 0x0000
#define SOMEIP_CLIENT_MAX 0xFFFF
#define SOMEIP_RES_LEN_MAX 0xFFFFFFFF
#define SOMEIP_EVGR_EMPTY 0x0000

#define SOMEIP_ADDR_IPV4_MCAST_MASK 0xF0000000
#define SOMEIP_ADDR_IPV4_MCAST_PREF 0xE0000000
#define SOMEIP_ADDR_IPV4_IS_MCAST(addr) ((addr & SOMEIP_ADDR_IPV4_MCAST_MASK) == SOMEIP_ADDR_IPV4_MCAST_PREF)

#define SOMEIP_SESSION_ID_INIT 0x0001 /* PRS_SOMEIPSD_00158 */
#define SOMEIP_SESSION_NA 0x0000 /* PRS_SOMEIP_00932 */
#define SOMEIP_SESSION_HND_DEF TRUE

#define SOMEIP_TP_EN TRUE

#define SOMEIP_IP_ADR_STR_LEN INET6_ADDRSTRLEN

/* message fields positions */

#define SOMEIP_SERVICE_POS_MIN 0
#define SOMEIP_SERVICE_POS_MAX 1
#define SOMEIP_METHOD_POS_MIN 2
#define SOMEIP_METHOD_POS_MAX 3
#define SOMEIP_EVENT_POS_MIN 2
#define SOMEIP_EVENT_POS_MAX 3
#define SOMEIP_LENGTH_POS_MIN 4
#define SOMEIP_LENGTH_POS_MAX 7
#define SOMEIP_CLIENT_POS_MIN 8
#define SOMEIP_CLIENT_POS_MAX 9
#define SOMEIP_SESSION_POS_MIN 10
#define SOMEIP_SESSION_POS_MAX 11
#define SOMEIP_PROTOCOL_VERSION_POS 12
#define SOMEIP_INTERFACE_VERSION_POS 13
#define SOMEIP_MESSAGE_TYPE_POS 14
#define SOMEIP_RETURN_CODE_POS 15
#define SOMEIP_PAYLOAD_POS 16

/* SOME/IP-SD */

#define SOMEIP_SD_SERVICE 0xFFFF /* PRS_SOMEIPSD_00151 */
#define SOMEIP_SD_METHOD 0x8100 /* PRS_SOMEIPSD_00152 */
#define SOMEIP_SD_INSTANCE 0x0000
#define SOMEIP_SD_CLIENT 0x0000 /* SIP_SD_1139 */
#define SOMEIP_SD_PING 0xA5A5 /* ping command */
#define SOMEIP_SD_PONG 0x5A5A /* pong command */
#define SOMEIP_SD_EV_HND 0xAAAA /* local event handling SA-RM */

#define SOMEIP_SD_FLAG_REBOOT 0x80
#define SOMEIP_SD_FLAG_UNICAST 0x40 /* PRS_SOMEIPSD_00259 */
#define SOMEIP_SD_FLAG_EIDC 0x20 /* PRS_SOMEIPSD_00700 */

#define SOMEIP_GET_REBOOT_FLAG(flags) ((flags & SOMEIP_SD_FLAG_REBOOT) == SOMEIP_SD_FLAG_REBOOT)

#define SOMEIP_SD_HEADER_SIZE 4
#define SOMEIP_SD_ENTRY_LENGTH_SIZE 4
#define SOMEIP_SD_ENTRY_SIZE 16
#define SOMEIP_SD_IPV4_OPTION_SIZE 12
#define SOMEIP_SD_IPV6_OPTION_SIZE 24
#define SOMEIP_SD_OPTION_LENGTH_SIZE 4
#define SOMEIP_SD_OPTION_HEADER_SIZE 3
#define SOMEIP_SD_CFG_OPTION_FMT_SIZE (2 + 1) /* length + type */
#define SOMEIP_IPV6_ADDR_SIZE 16 /* IPv6 address size */

#define SOMEIP_SD_NO_OP_SIZE 4 /* no of options size in bits */
#define SOMEIP_SD_NO_OP_MASK 0x0F /* no of options mask */

/* Configuration option */

#define SOMEIP_SD_OTHERSERV_STR "otherserv"
#define SOMEIP_SD_EQUAL_STR "="
#define SOMEIP_SD_EQUAL_SIGN_SIZE 1
#define SOMEIP_SD_NULL_STRING_SIZE 1

#define SOMEIP_SD_OPTION_FORMAT_SIZE (2 + 1) /* in bytes len + type */

/* PRS_SOMEIPSD_00274 */

#define SOMEIP_SD_OP_LOAD_BAL (1 + 2 + 2)

/* PRS_SOMEIPSD_00274 */

#define SOMEIP_SD_OP_IPv4_LEN (1 + 4 + 1 + 1 + 2)

/* PRS_SOMEIPSD_00274 */

#define SOMEIP_SD_OP_IPv6_LEN (1 + 16 + 1 + 1 + 2)

#define SOMEIP_SD_DEFAULT_ENABLED TRUE
#define SOMEIP_SD_DEFAULT_PROTOCOL SOMEIP_UDP
#define SOMEIP_SD_DEFAULT_MULTICAST "224.224.224.0"
#define SOMEIP_SD_DEFAULT_PORT 30490
#define PORT_BUFFER_SIZE 10
#define PORT_INVALID 0xFFFF

#define SOMEIP_SD_DEFAULT_INITIAL_DELAY_MIN 0
#define SOMEIP_SD_DEFAULT_INITIAL_DELAY_MAX 3000
#define SOMEIP_SD_DEFAULT_REPETITIONS_BASE_DELAY 10
#define SOMEIP_SD_DEFAULT_REPETITIONS_MAX 3
#define SOMEIP_SD_DEFAULT_TTL 3
#define SOMEIP_SD_TTL_EXP 0
#define SOMEIP_SD_DEFAULT_CYCLIC_OFFER_DELAY 1000
#define SOMEIP_SD_DEFAULT_REQUEST_RESPONSE_DELAY 2000
#define SOMEIP_SD_DEFAULT_OFFER_DEBOUNCE_TIME 500
#define SOMEIP_SD_DEFAULT_FIND_DEBOUNCE_TIME 500

/* byte ordering */

#define SOMEIP_DATA_LEN_BOOL 1
#define SOMEIP_DATA_LEN_UINT8 1
#define SOMEIP_DATA_LEN_UINT16 2
#define SOMEIP_DATA_LEN_UINT32 4
#define SOMEIP_BYTE_MASK 0xFF
#define SOMEIP_POS_BYTE0 0
#define SOMEIP_POS_BYTE1 8
#define SOMEIP_POS_BYTE2 16
#define SOMEIP_POS_BYTE3 24

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#    define SOMEIP_BYTES_TO_UINT16(b1, b0) ((uint16_t)((b1) << SOMEIP_POS_BYTE1 | (b0)))
#    define SOMEIP_BYTES_TO_UINT32(b3, b2, b1, b0) \
        ((uint32_t)((b3) << SOMEIP_POS_BYTE3 | (b2) << SOMEIP_POS_BYTE2 | (b1) << SOMEIP_POS_BYTE1 | (b0)))
#    define SOMEIP_UINT16_BYTE0(v) ((uint8_t)(((v) >> SOMEIP_POS_BYTE0) & SOMEIP_BYTE_MASK))
#    define SOMEIP_UINT16_BYTE1(v) ((uint8_t)(((v) >> SOMEIP_POS_BYTE1) & SOMEIP_BYTE_MASK))
#    define SOMEIP_UINT32_BYTE0(v) ((uint8_t)(((v) >> SOMEIP_POS_BYTE0) & SOMEIP_BYTE_MASK))
#    define SOMEIP_UINT32_BYTE1(v) ((uint8_t)(((v) >> SOMEIP_POS_BYTE1) & SOMEIP_BYTE_MASK))
#    define SOMEIP_UINT32_BYTE2(v) ((uint8_t)(((v) >> SOMEIP_POS_BYTE2) & SOMEIP_BYTE_MASK))
#    define SOMEIP_UINT32_BYTE3(v) ((uint8_t)(((v) >> SOMEIP_POS_BYTE3) & SOMEIP_BYTE_MASK))
#elif _BYTE_ORDER == _BIG_ENDIAN
#    define SOMEIP_BYTES_TO_UINT16(b0, b1) (uint16_t((b1) << SOMEIP_POS_BYTE1 | (b0)))
#    define SOMEIP_BYTES_TO_UINT32(b0, b1, b2, b3) \
        (uint32_t((b3) << SOMEIP_POS_BYTE3 | (b2) << SOMEIP_POS_BYTE2 | (b1) << SOMEIP_POS_BYTE1 | (b0)))
#    define SOMEIP_UINT16_BYTE0(v) ((uint8_t)(((v) >> SOMEIP_POS_BYTE1) & SOMEIP_BYTE_MASK))
#    define SOMEIP_UINT16_BYTE1(v) ((uint8_t)(((v) >> SOMEIP_POS_BYTE0) & SOMEIP_BYTE_MASK))
#    define SOMEIP_UINT32_BYTE0(v) ((uint8_t)(((v) >> SOMEIP_POS_BYTE3) & SOMEIP_BYTE_MASK))
#    define SOMEIP_UINT32_BYTE1(v) ((uint8_t)(((v) >> SOMEIP_POS_BYTE2) & SOMEIP_BYTE_MASK))
#    define SOMEIP_UINT32_BYTE2(v) ((uint8_t)(((v) >> SOMEIP_POS_BYTE1) & SOMEIP_BYTE_MASK))
#    define SOMEIP_UINT32_BYTE3(v) ((uint8_t)(((v) >> SOMEIP_POS_BYTE0) & SOMEIP_BYTE_MASK))
#else
#    error "Byte ordering not defined"
#endif

#define SL_INIT_NODE(node) (node).next = NULL;

/* SOMEIP message */

#define SOMEIP_SD_MAX_TCP_PAYLOAD 4075 /* Available for entries & options */
#define SOMEIP_SD_MAX_UDP_PAYLOAD 1380

#define SOMEIP_MAX_LOC_CMD_SIZE 200 /* local control message */
#define SOMEIP_MAX_LOC_MSG_SIZE 1400 /* req/resp/event */
#define SOMEIP_MAX_TCP_MSG_SIZE 0
#define SOMEIP_MAX_UDP_MSG_SIZE 1416
#define SOMEIP_MAX_UDP_TP_MSG_SIZE 32768

/* Message ID + Length */

#define SOMEIP_MSG_INIT_LEN (2 * SOMEIP_DATA_LEN_UINT32)
#define SOMEIP_HEADER_SIZE SOMEIP_MSG_INIT_LEN
#define SOMEIP_MSG_SD_INIT_LEN (SOMEIP_HEADER_SIZE + SOMEIP_SD_HEADER_SIZE)

#define SOMEIP_SERV_MAX_CLIENTS 255 /*used for TCP/IP sockets*/

/* local mqueue name pattern */

#define SOMEIP_MSG_LEN_MAX 1404
#define SOMEIP_MQ_NAME_PAT "/wrsomeip-0x"
#define SOMEIP_MQ_NAME_PAT_CLNT SOMEIP_MQ_NAME_PAT "%04X"
#define SOMEIP_MQ_COMMUNICATION_TIMEOUT_NS 20000000 /* used for timedsend and timedreceive */

#define SOMEIP_THREADS_NR 255

/* read and write FIFO permissions */

#define SOMEIP_FIFO_PERMISSIONS 0666

/* SOMEIP Default Values */

#define WRSOMEIP_ENV_CONFIG_PATH "WRSOMEIP_CONFIG_PATH"
#define WRSOMEIP_ENV_APP_NAME "WRSOMEIP_APP_NAME"

#define SOMEIP_MSG_TYPE_NAME_SIZE 20
#define SOMEIP_PTHREAD_NAME_LENGTH 30

#define SOMEIP_PROTOCOL_VERSION 0x1
#define SOMEIP_INTERFACE_VERSION 0x1

#define SOMEIP_HEADER_LEN 8
#define SOMEIP_HEADER_DEF_LENGTH 0x08

#define SOMEIP_HEADER_PAYLOAD_SIZE 1500

#define SOMEIP_ANY_SERVICE 0xFFFF
#define SOMEIP_ANY_INSTANCE 0xFFFF
#define SOMEIP_ANY_METHOD 0xFFFF
#define SOMEIP_ANY_MAJOR 0xFF
#define SOMEIP_ANY_MINOR 0xFFFFFFFF
#define SOMEIP_OTHER_SERV 0xFFFE

#define SRV_OFFER 0x1
#define SRV_FIND 0x2
#define SRV_UNKNOWN 0x4
#define SRV_ANY 0x3

/*
 * Flags for releasing pData memory for msg's that need to be send.
 * For received msg's pData memory is freed on rcvListen thread termination.
 */

#define NOT_RCV_MSG 0
#define RCV_MSG 1

#define SAVE_ADDR_INFO(dest, src)          \
    (dest)->family = (src)->ai_family;     \
    (dest)->protocol = (src)->ai_protocol; \
    (dest)->addrlen = (src)->ai_addrlen;   \
    (dest)->addr = *((src)->ai_addr);

#define FAMILY_TYPE 0
#define SOCK_ADDR_IN_PTR(sa) ((struct sockaddr_in*)(sa))
#define SOCK_ADDR_IN_ADDR(sa) SOCK_ADDR_IN_PTR(sa)->sin_addr
#define SOCK_ADDR_IN6_PTR(sa) ((struct sockaddr_in6*)(sa))
#define SOCK_ADDR_IN6_ADDR(sa) SOCK_ADDR_IN6_PTR(sa)->sin6_addr

#define IS_MY_OPTION(pEntry, idx)                                                                              \
    ((pEntry->noOp1 > 0) && (pEntry->idxOp1 >= idx) && ((uint8_t)(pEntry->idxOp1 + pEntry->noOp1 - 1) <= idx)) \
        || ((pEntry->noOp2 > 0) && (pEntry->idxOp2 >= idx) && ((uint8_t)(pEntry->idxOp2 + pEntry->noOp2 - 1) <= idx))

/* SLIST extension */

#define SLIST_INSERT_TAIL(head, listelem, elem, field)                           \
    if ((head)->slh_first == NULL) {                                             \
        SLIST_INSERT_HEAD(head, elem, field);                                    \
    } else {                                                                     \
        for ((listelem) = (head)->slh_first; (listelem)->field.sle_next != NULL; \
             (listelem) = (listelem)->field.sle_next)                            \
            ;                                                                    \
        SLIST_NEXT(elem, field) = NULL;                                          \
        SLIST_INSERT_AFTER(listelem, elem, field);                               \
    }

#define SOMEIP_BUF_FMT_SIZE 30
#define SOMEIP_BUF_PRINT_LINE_LEN 4 /* how many bytes per line */
#define SOMEIP_BUF_PRINT_HEX_4 "%02X:%02X:%02X:%02X"
#define SOMEIP_BUF_PRINT_HEX_3 "%02X:%02X:%02X:--"
#define SOMEIP_BUF_PRINT_HEX_2 "%02X:%02X:--:--"
#define SOMEIP_BUF_PRINT_HEX_1 "%02X:--:--:--"
#define SOMEIP_BUF_PRINT_DEC_4 "%02d:%02d:%02d:%02d"
#define SOMEIP_BUF_PRINT_DEC_3 "%02d:%02d:%02d:--"
#define SOMEIP_BUF_PRINT_DEC_2 "%02d:%02d:--:--"
#define SOMEIP_BUF_PRINT_DEC_1 "%02d:--:--:--"
#define SOMEIP_BUF_PRINT_ASC_4 "%c:%c:%c:%c"
#define SOMEIP_BUF_PRINT_ASC_3 "%c:%c:%c:--"
#define SOMEIP_BUF_PRINT_ASC_2 "%c:%c:--:--"
#define SOMEIP_BUF_PRINT_ASC_1 "%c:--:--:--"

/* typedefs */

typedef uint8_t SERVICE_TYPE;
typedef uint16_t SERVICE;
typedef uint16_t METHOD;
typedef uint32_t LENGTH;
typedef uint16_t CLIENT;
typedef uint16_t INSTANCE;
typedef uint16_t SESSION;
typedef uint16_t EVENT;
typedef uint16_t EVGR;
typedef uint8_t PROTOCOL_VERSION;
typedef uint8_t INTERFACE_VERSION;
typedef uint8_t MAJOR_VERSION;
typedef uint32_t MINOR_VERSION;
typedef uint8_t MESSAGE_TYPE;
typedef uint8_t RETURN_CODE;
typedef uint8_t FLAGS;
typedef uint8_t SOMEIP_ENTRY_TYPE;
typedef uint8_t SOMEIP_OPTION_TYPE;
typedef uint16_t SOMEIP_OPTION_LEN;
typedef uint32_t TP_HEADER;
typedef uint32_t TP_OFFSET;
typedef uint8_t TP_MORE;

typedef enum endpType
{
    ENDP_UDP,
    ENDP_TCP,
    ENDP_LOCAL,
    ENDP_PROXY
} ENDP_TYPE;

typedef enum messageTypeE
{
    E_REQUEST = 0x00,
    E_REQUEST_NO_RETURN = 0x01,
    E_NOTIFICATION = 0x02,
    E_RESPONSE = 0x80,
    E_ERROR = 0x81,
} MESSAGE_TYPE_E;

typedef enum returnCodeE
{
    E_OK = 0x00,
    E_NOT_OK = 0x01,
    E_UNKNOWN_SERVICE = 0x02,
    E_UNKNOWN_METHOD = 0x03,
    E_NOT_READY = 0x04,
    E_NOT_REACHABLE = 0x05,
    E_TIMEOUT = 0x06,
    E_WRONG_PROTOCOL_VERSION = 0x07,
    E_WRONG_INTERFACE_VERSION = 0x08,
    E_MALFORMED_MESSAGE = 0x09,
    E_WRONG_MESSAGE_TYPE = 0x0A,
    E_UNKNOWN = 0xFF
} RETURN_CODE_E;

typedef enum someipEntryType
{
    FIND_SERVICE = 0x00,
    OFFER_SERVICE = 0x01,
    STOP_OFFER_SERVICE = 0x01,
    REQUEST_SERVICE = 0x02,
    FIND_EVENT_GROUP = 0x04,
    PUBLISH_EVENTGROUP = 0x05,
    STOP_PUBLISH_EVENTGROUP = 0x05,
    SUBSCRIBE_EVENTGROUP = 0x06,
    STOP_SUBSCRIBE_EVENTGROUP = 0x06,
    SUBSCRIBE_EVENTGROUP_ACK = 0x07,
    STOP_SUBSCRIBE_EVENTGROUP_ACK = 0x07,
    UNKNOWN = 0xFF
} SOMEIP_ENTRY_TYPE_E;

typedef enum lclCmd
{
    /* service discovery group */

    LCL_CMD_OFFER = 1,
    LCL_CMD_OFFER_STOP = 2,
    LCL_CMD_FIND = 3,
    LCL_CMD_FIND_STOP = 4,
    LCL_CMD_SUB_EVGR = 5,
    LCL_CMD_SUB_EVGR_STOP = 6,
    LCL_CMD_SUB_EVGR_ACK = 7,
    LCL_CMD_SUB_EVGR_NACK = 8,

    /* local control */

    LCL_CMD_PING = 9,
    LCL_CMD_PONG = 10,

    LCL_CMD_REQ = 11,
    LCL_CMD_REQ_NR = 12,
    LCL_CMD_RESP = 13,
    LCL_CMD_NOTIF = 14,

    LCL_CMD_OFFER_EV = 15,
    LCL_CMD_STOP_OFFER_EV = 16,
    LCL_CMD_REQUEST_EV = 17,
    LCL_CMD_RELEASE_EV = 18,
    LCL_CMD_SUBSCRIBE_EV = 19,
    LCL_CMD_UNSUBSCRIBE_EV = 20,
    LCL_CMD_SET_EVENT = 21
} LCL_CMD;

typedef enum subsState /* subscription state */
{
    SUBS_STATE_NA = 0,
    SUBS_STATE_PENDING = 1,
    SUBS_STATE_OFFERED = 2,
    SUBS_STATE_IN_PROG = 3,
    SUBS_STATE_ACK = 4,
    SUBS_STATE_NACK = 5,
    SUBS_STATE_NEXIST = 6,
    SUBS_STATE_REMOVED = 7
} SUBS_STATE;

typedef enum printMode
{
    PRINT_MODE_HEX = 0,
    PRINT_MODE_DEC = 1,
    PRINT_MODE_ASC = 2,
    PRINT_MODE_MAX = 3
} PRINT_MODE;

typedef struct addrInfo
{
    int family; /* protocol family for socket */
    int protocol; /* protocol for socket */
    size_t addrlen; /* length of socket address.  */
    struct sockaddr addr; /* socket address for socket */
} ADDR_INFO;

typedef void* (*THR_FUNC_PTR)(void*); /* thread start function type */
#ifdef __cplusplus
}
#endif

#endif /*__INCsomeipTypesh */
