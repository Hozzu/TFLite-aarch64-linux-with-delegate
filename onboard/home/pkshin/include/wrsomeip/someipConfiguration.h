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

#ifndef __INCsomeipConfigurationh
#define __INCsomeipConfigurationh

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* includes */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <wrsomeip/someipTypes.h>

/* defines */

#define SOMEIP_CFG_FILE_DEF "wrsomeip.json"
#define SOMEIP_CFG_FILE_PATH_DEF SOMEIP_RUNTIME_CFG_PATH SOMEIP_CFG_FILE_DEF

#define SOMEIP_CFG_DEF_LOG_LEVEL SOMEIP_DEBUG
#define SOMEIP_CFG_DEF_LOG_DLT TRUE
#define SOMEIP_CFG_DEF_LOG_FILE FALSE
#define SOMEIP_CFG_DEF_UCAST_ADDR "127.0.0.1"
#define SOMEIP_CFG_DEF_LOG_PATH "/tmp"

/* typedefs */

typedef enum someipLoggingLevel
{
    SOMEIP_TRACE = 0x00,
    SOMEIP_DEBUG = 0x01,
    SOMEIP_INFO = 0x02,
    SOMEIP_WARNING = 0x03,
    SOMEIP_ERROR = 0x04,
    SOMEIP_FATAL = 0x05
} SOMEIP_LOGGING_LEVEL;

typedef enum someipProtocol
{
    SOMEIP_UDP = 0x00,
    SOMEIP_TCP = 0x01
} SOMEIP_PROTOCOL;

typedef struct someipPort
{
    uint16_t port;
} SOMEIP_PORT;

typedef struct someipAction
{
    uint32_t service;
    uint32_t instance;
} SOMEIP_ACTION;

typedef struct someipEvent
{
    EVENT event;
    BOOL isField;
    BOOL isReliable;
    uint32_t updateCycle;
} SOMEIP_EVENT;

typedef struct someipEventgroup
{
    size_t nrEvents;
    uint32_t evgr;
    SOMEIP_EVENT* pEvents;
    BOOL isMcast;
    const char* pMcastAddr;
    uint16_t mcastPort;
} SOMEIP_EVENTGROUP;

typedef struct someipPolicies
{
    size_t nrOffers;
    size_t nrRequests;
    uint32_t clntId;
    uint32_t clntFirst;
    uint32_t clntLast;
    uint32_t credUid;
    uint32_t credGid;
    SOMEIP_ACTION* pAllowOff;
    SOMEIP_ACTION* pAllowReq;
} SOMEIP_POLICIES;

typedef struct someipService
{
    size_t nrEvents;
    size_t nrEvgr;
    uint32_t service;
    uint32_t instance;
    const char* pUnicast;
    uint16_t relPort;
    BOOL relMagCook;
    uint16_t unrelPort;
    const char* pMcastAddr;
    uint16_t mcastPort;
    SOMEIP_EVENT* pEvents;
    SOMEIP_EVENTGROUP* pEvgr;
    const char* pOtherServ;
} SOMEIP_SERVICE;

typedef struct someipClient
{
    size_t nrReliable;
    size_t nrUnreliable;
    uint32_t service;
    uint32_t instance;
    SOMEIP_PORT* pReliable;
    SOMEIP_PORT* pUnreliable;
} SOMEIP_CLIENT;

typedef struct someipApplication
{
    const char* pName;
    uint16_t id;
} SOMEIP_APPLICATION;

typedef struct someipConfiguration
{
    size_t nrApps;
    size_t nrClients;
    size_t nrServices;
    size_t nrSecPol;

    const char* pUnicast;
    ADDR_INFO uniAddr;
    char* pNetmask;
    BOOL tracEn;

    /* Logging */

    SOMEIP_LOGGING_LEVEL logLevel;
    BOOL logConsole;
    BOOL logFileEn;
    const char* pLogFilePath;
    BOOL logDlt;

    SOMEIP_APPLICATION* pApplications;
    SOMEIP_CLIENT* pClients;
    SOMEIP_SERVICE* pServices;

    BOOL secCheckCred;
    SOMEIP_POLICIES* pSecPol;

    char* pRouting;

    /* Service discovery */

    BOOL sdEn; /* Service Discovery enabled */
    const char* pSdMcast;
    ADDR_INFO mAddr;
    uint16_t sdPort;
    SOMEIP_PROTOCOL sdProt;
    uint32_t sdInitDelayMin;
    uint32_t sdInitDelayMax;
    uint32_t sdRepBaseDelay;
    uint32_t sdRepMax;
    uint32_t sdTtl;
    uint32_t sdCycOffDelay;
    uint32_t sdReqResDelay;
    uint32_t sdOffDebTime;
    uint32_t sdFindDebTime;
} SOMEIP_CONFIGURATION;

/* function declarations */

IMPORT STATUS someipLoadConfiguration(SOMEIP_CONFIGURATION* pSomeipCfg, const char* pConfigPath);
IMPORT STATUS someipLoadApplicationConfiguration(SOMEIP_APPLICATION* pSomeipApp, const char* pConfigPath);
IMPORT SOMEIP_SERVICE* someipCfgFindServ(const SOMEIP_CONFIGURATION* pSomeipCfg, uint16_t service, uint16_t client);
IMPORT SOMEIP_CLIENT* someipCfgFindClient(const SOMEIP_CONFIGURATION* pSomeipCfg, uint16_t service, uint16_t client);
IMPORT void someipConfigCleanup(SOMEIP_CONFIGURATION* pWrsomeipConfig);

#ifdef __cplusplus
}
#endif

#endif /* __INCsomeipConfigurationh */
