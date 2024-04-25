/* ===========================================================================
 * Copyright (c) 2016-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
=========================================================================== */

#ifndef _TEST_UTIL_DEBUG_H
#define _TEST_UTIL_DEBUG_H

#include <stdio.h>

#include "ais_log.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__ANDROID__)
#define DEFAULT_DUMP_LOCATION "/data/vendor/camera/"
#elif defined(__INTEGRITY)
#define DEFAULT_DUMP_LOCATION "/ghs_test/Camera/frameDump/"
#else
#define DEFAULT_DUMP_LOCATION "/tmp/"
#endif

#define QCARCAM_PERFMSG(cond, _fmt_, ...) \
do { \
    if(cond){ \
        ais_log(AIS_MOD_ID_QCARCAM_TEST, AIS_LOG_LVL_HIGH,  "QCARCAM %s:%d %s " _fmt_ "\n", __FUNCTION__, __LINE__, AIS_LOG_LVL_STR[AIS_LOG_LVL_HIGH], ##__VA_ARGS__); \
    } \
} while (0)

#define QCARCAM_DBGMSG(_fmt_, ...) \
    ais_log(AIS_MOD_ID_QCARCAM_TEST, AIS_LOG_LVL_DBG,  "QCARCAM %s:%d %s " _fmt_ "\n", __FUNCTION__, __LINE__, AIS_LOG_LVL_STR[AIS_LOG_LVL_DBG], ##__VA_ARGS__)

#define QCARCAM_INFOMSG(_fmt_, ...) \
    ais_log(AIS_MOD_ID_QCARCAM_TEST, AIS_LOG_LVL_MED,  "QCARCAM %s:%d %s " _fmt_ "\n", __FUNCTION__, __LINE__, AIS_LOG_LVL_STR[AIS_LOG_LVL_MED], ##__VA_ARGS__)

#define QCARCAM_ERRORMSG(_fmt_, ...) \
    ais_log(AIS_MOD_ID_QCARCAM_TEST, AIS_LOG_LVL_ERROR,  "QCARCAM %s:%d %s " _fmt_ "\n", __FUNCTION__, __LINE__, AIS_LOG_LVL_STR[AIS_LOG_LVL_ERROR], ##__VA_ARGS__)

#define QCARCAM_ALWZMSG(_fmt_, ...) \
    ais_log(AIS_MOD_ID_QCARCAM_TEST, AIS_LOG_LVL_ALWAYS,  "QCARCAM %s:%d %s " _fmt_ "\n", __FUNCTION__, __LINE__, AIS_LOG_LVL_STR[AIS_LOG_LVL_ALWAYS], ##__VA_ARGS__)


#ifdef __cplusplus
}
#endif

#endif /* _TEST_UTIL_DEBUG_H */
