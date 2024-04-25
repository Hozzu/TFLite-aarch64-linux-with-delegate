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

#ifndef __INCsomeipSdTypesh
#define __INCsomeipSdTypesh

/* includes */

#include <netinet/in.h>
#include <sys/queue.h>

#include "someipTypes.h"
#include "someipTimer.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* defines */

#define SD_CFGOP_KEY_LEN 20
#define SD_CFGOP_VALUE_LEN 20
#define SD_CFG_STR_LEN 50

#define SD_EVGR_INIT_DATA_POS 23
#define SD_EVGR_CNT_POS 16
#define SD_EVGR_ID_POS 0
#define SD_EVGR_INIT_DATA_MASK 0x01
#define SD_EVGR_CNT_MASK 0x0F
#define SD_EVGR_ID_MASK 0xFFFF

#define SD_GET_EVGR_INIT_DATA(data) ((data >> SD_EVGR_INIT_DATA_POS) & SD_EVGR_INIT_DATA_MASK)
#define SD_SET_EVGR_INIT_DATA(data) (data << SD_EVGR_INIT_DATA_POS)
#define SD_GET_EVGR_CNT(data) ((data >> SD_EVGR_CNT_POS) & SD_EVGR_CNT_MASK)
#define SD_SET_EVGR_CNT(data) (data << SD_EVGR_CNT_POS)
#define SD_GET_EVGR_ID(data) ((data >> SD_EVGR_ID_POS) & SD_EVGR_ID_MASK)
#define SD_SET_EVGR_ID(data) (data << SD_EVGR_ID_POS)

/* typedefs */

typedef uint8_t SD_TYPE;
typedef uint8_t SD_OP_IDX;
typedef SD_OP_IDX SD_INDEX_FIRST_OPTION;
typedef SD_OP_IDX SD_INDEX_SECOND_OPTION;
typedef uint8_t SD_OP_NO;
typedef SD_OP_NO SD_NUMBER_OPTION_1; /* uint4 */
typedef SD_OP_NO SD_NUMBER_OPTION_2; /* uint4 */
typedef uint16_t SD_SERVICE;
typedef uint16_t SD_INSTANCE;
typedef uint8_t SD_MAJOR_VERSION;
typedef uint32_t SD_TTL; /* uint24 */
typedef uint32_t SD_MINOR_VERSION;

/* For EventGroup Attributes */

typedef uint8_t SD_RESERVED; /* uint24 */
typedef uint8_t SD_INITIAL_FLAG; /* one bit */
typedef uint8_t SD_RESERVED_2; /* 3 bits */
typedef uint8_t SD_COUNTER; /* uint4 */
typedef uint16_t SD_EVENT_GROUP;

typedef uint8_t SD_OPTION_TYPE;
typedef uint16_t SD_OPTION_LEN;
typedef uint32_t SD_OPTION_IPV4;
typedef uint8_t SD_OPTION_PROTO;
typedef uint16_t SD_OPTION_PORT;

typedef uint16_t SD_CFG_OPTION_LENGTH;

typedef enum sdEntryType_e
{
    SD_EN_FIND_SERV = 0x00,
    SD_EN_OFFER_SERV = 0x01,
    SD_EN_STOP_OFFER_SERV = 0x01,
    SD_EN_REQ_SERV = 0x02,
    SD_EN_FIND_EVGRP = 0x04,
    SD_EN_PUB_EVGRP = 0x05,
    SD_EN_STOP_PUB_EVGRP = 0x05,
    SD_EN_SUB_EVGRP = 0x06,
    SD_EN_STOP_SUB_EVGRP = 0x06,
    SD_EN_SUB_EVGRP_ACK = 0x07,
    SD_EN_STOP_SUB_EVGRP_ACK = 0x07,
    SD_EN_UNKNOWN = 0xFF
} SD_ENTRY_TYPE;

typedef enum sdOption_e
{
    SD_OP_LOCAL = 0x00,
    SD_OP_CONFIGURATION = 0x01,
    SD_OP_LOAD_BALANCING = 0x02,
    SD_OP_PROTECTION = 0x03,
    SD_OP_IP4_ENDPOINT = 0x04,
    SD_OP_IP6_ENDPOINT = 0x06,
    SD_OP_IP4_MULTICAST = 0x14,
    SD_OP_IP6_MULTICAST = 0x16,
    SD_OP_UNKNOWN = 0xFF
} SD_OPTION;

typedef enum someipSrvLoc
{
    SRV_LOC_NA = 0,
    SRV_LOC_LOCAL = 1,
    SRV_LOC_REMOTE = 2,
    SRV_LOC_MAX = 3
} SOMEIP_SRV_LOC;

typedef enum someipSrvState
{
    SRV_STATE_NA = 0,
    SRV_STATE_OFFERED = 1,
    SRV_STATE_REQUESTED = 2,
    SRV_STATE_CONNECTED = 3
} SOMEIP_SRV_STATE;

typedef enum sdOptL4Proto_e
{
    SD_L4PROTO_LOCAL = 0x00,
    SD_L4PROTO_TCP = 0x06,
    SD_L4PROTO_UDP = 0x11,
    SD_L4PROTO_UNKNONW = 0xFF
} SD_OPT_L4PROTO;

/* event group entry specific */

typedef struct entryEvgr
{
    uint8_t init;
    uint8_t cnt;
    EVGR evgr;
} ENTRY_EVGR;

/* service entry specific */

typedef struct entry_serv
{
    SD_MINOR_VERSION minVer;
} ENTRY_SERV;

typedef union entry_spec
{
    ENTRY_SERV serv;
    ENTRY_EVGR evgr;
} ENTRY_SPEC;

/* entry common */

typedef struct entry
{
    SD_TYPE type;
    SD_SERVICE service;
    SD_INSTANCE instance;
    SD_MAJOR_VERSION majVer;
    SD_TTL ttl;
    SD_INDEX_FIRST_OPTION idxOp1;
    SD_INDEX_SECOND_OPTION idxOp2;
    SD_NUMBER_OPTION_1 noOp1;
    SD_NUMBER_OPTION_2 noOp2;
    ENTRY_SPEC spec;
} ENTRY;

/* node in the entries list */

typedef struct entryNode
{
    SLIST_ENTRY(entryNode) node;
    ENTRY* pEntry;
} ENTRY_NODE;

typedef SLIST_HEAD(entryLst, entryNode) ENTRY_LST;

/* IPv4_6 endpoint specific option */

typedef union ipAddr4_6
{
    struct in_addr v4;
    struct in6_addr v6;
} IP_ADDR_4_6;

typedef struct opIpv4_6
{
    SD_TYPE type;
    IP_ADDR_4_6 addr4_6;
    SD_OPTION_PROTO proto;
    SD_OPTION_PORT port;
} OP_IPV4_6;

/* Configuration option specific option */

typedef struct opConfig
{
    char key[SD_CFGOP_KEY_LEN];
    char value[SD_CFGOP_VALUE_LEN];
} OP_CONFIG;

typedef struct option
{
    SD_OPTION_LEN length;
    SD_OPTION_TYPE type;
    void* pSpec; /* type specific option fields */
} OPTION;

/* node in the options list */

typedef struct optionNode
{
    SLIST_ENTRY(optionNode) node;
    OPTION* pOption;
} OPTION_NODE;

typedef SLIST_HEAD(optLst, optionNode) OPT_LST;

typedef struct pingNode
{
    SLIST_ENTRY(pingNode) node;
    CLIENT client;
    SOMEIP_TIMER* pingTmr;
    SD_SERVICE sdService;
    SD_INSTANCE sdInstance;
    BOOL isLcl;
    void* pRm;
} PING_NODE;

typedef SLIST_HEAD(pingLst, pingNode) PING_LST;
/*
 * Subscriber Node,
 * contains each type of endpoint of where the subscriber can be found
 */

typedef struct subsClnt
{
    CLIENT clnt;
    ENDP_TYPE loc;
    ADDR_INFO addr;
    SD_OPTION_PROTO proto;
    SD_OPTION_PORT port;
} SUBS_CLNT;

typedef struct subsInfo
{
    SUBS_CLNT clntInfo;
    void* pEp;
} SUBS_INFO;

typedef struct subsNode
{
    SUBS_INFO info;
    SLIST_ENTRY(subsNode) node;
} SUBS_NODE;

typedef SLIST_HEAD(subsList, subsNode) SUBS_LST;

#ifdef __cplusplus
}
#endif

#endif /*__INCsomeipSdTypesh */
