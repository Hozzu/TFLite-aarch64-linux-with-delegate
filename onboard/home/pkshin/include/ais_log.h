#ifndef _AIS_LOG_H_
#define _AIS_LOG_H_
/*
 * @file ais_log.h
 *
 * @brief defines all structures and definitions of logging.
 *
 * Copyright (c) 2016-2020 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#include <stdio.h>

#include "ais_module.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * ais log level
 * the smaller the value is, the severer the level is.
 * generally the levels above warning are used based on error severity
 * the levels below warning are used based on the frequence of logging printing
 * THE MAXIMUM VALUE IS 11 IN CURRENT DESIGN
 */
#define AIS_LOG_LVL_ALWAYS    0                    //always, ignore level setting, print always
#define AIS_LOG_LVL_FATAL     1                    //fatal, system may crash, highest severity level
#define AIS_LOG_LVL_CRIT      2                    //critical
#define AIS_LOG_LVL_ERROR     3                    //error
#define AIS_LOG_LVL_WARN      4                    //warning
#define AIS_LOG_LVL_HIGH      5                    //high
#define AIS_LOG_LVL_MED       6                    //medium
#define AIS_LOG_LVL_LOW       7                    //low
#define AIS_LOG_LVL_DBG       8                    //debug
#define AIS_LOG_LVL_DBG1      9                    //debug1
#define AIS_LOG_LVL_DBG2      10                   //debug2, lowest severity level


#define AIS_LOG_LVL_MAX_NUM   12                   //maximum number of log level

/**
 * string for ais log level for printing
 */
extern const char *AIS_LOG_LVL_STR[AIS_LOG_LVL_MAX_NUM];

/**
 * corrects log level
 */
#define AIS_LOG_LVL_CORR(lvl) (((lvl) < 0) ? 0 : (((lvl) >= AIS_LOG_LVL_MAX_NUM) ? (AIS_LOG_LVL_MAX_NUM - 1) : (lvl)))

/**
 * prints out log level string
 */
#define AIS_LOG_RAW(module, level, fmt, ...) ais_log((module), (level),  "%s " fmt "\n", AIS_LOG_LVL_STR[AIS_LOG_LVL_CORR(level)], ##__VA_ARGS__)

/**
 * prints out log level string, file name and file line
 */
#define AIS_LOG(module, level, fmt, ...) ais_log((AIS_MOD_ID_ ## module), (AIS_LOG_LVL_ ## level),  "%s:%d %s " fmt "\n", __FUNCTION__, __LINE__, AIS_LOG_LVL_STR[AIS_LOG_LVL_CORR((AIS_LOG_LVL_ ## level))], ##__VA_ARGS__)

#define AIS_LOG2(module, level, fmt, ...) ais_log((AIS_MOD_ID_ ## module), (level),  "%s:%d %s " fmt "\n", __FUNCTION__, __LINE__, AIS_LOG_LVL_STR[AIS_LOG_LVL_CORR((level))], ##__VA_ARGS__)

/**
 * prints out log level string and function name,
 * which is used for entering/exiting a function
 * one function should only include one entering and one exiting
 */
#define AIS_LOG_ENTER(module, level, fmt, ...) ais_log((AIS_MOD_ID_ ## module), (AIS_LOG_LVL_ ## level),  "%s E %s " fmt "\n", AIS_LOG_LVL_STR[AIS_LOG_LVL_CORR((AIS_LOG_LVL_ ## level))], __FUNCTION__, ##__VA_ARGS__)
#define AIS_LOG_EXIT(module, level, fmt, ...) ais_log((AIS_MOD_ID_ ## module), (AIS_LOG_LVL_ ## level),  "%s X %s " fmt "\n", AIS_LOG_LVL_STR[AIS_LOG_LVL_CORR((AIS_LOG_LVL_ ## level))], __FUNCTION__, ##__VA_ARGS__)


/**
 * a simulation of assert in libc
 */
#define AIS_LOG_ASSERT(x) ((void)((x) || ais_log(AIS_MOD_ID_RSRV, AIS_LOG_LVL_ALWAYS, "%s:%s:%d ASSERT %s\n\n", __FILE__, __FUNCTION__, __LINE__, #x)))
//#define AIS_LOG_ASSERT(x) ((void)(0))


#define AIS_LOG_ON_ERR(module, cond, ...)                                      \
    do                                                                         \
    {                                                                          \
        if (cond)                                                              \
            AIS_LOG(module, ERROR, ##__VA_ARGS__);                             \
    } while (0)


/**
 * locks logging module
 * @return 0: success, others: failed
 */
int ais_log_lock(void);

/**
 * unlocks logging module
 * @return 0: success, others: failed
 */
int ais_log_unlock(void);

/**
 * initializes log management, parses configuration file and allocates all resources
 * @param p_path points to the path of configuration file
 *               NULL means the default path is used
 * @param p_name points to the name of current program,
 *               which is used to compose the configuration file and os logging name
 *               NULL means the default name is used
 * @return 0: success, others: failed
 */
int ais_log_init(char *p_path, char *p_name);

/**
 * initializes log management and frees all resources
 * @return 0: success, others: failed
 */
int ais_log_uninit(void);

/**
 * sets level if one message can be printed out
 * @param id module id
 * @param level message level
 * @return 0: success, others: failed
 */
int ais_log_set_level(int id, int level);

/**
 * prints formatted log into buffer and is not thread-safe
 * generally is used in signal handlers when log mutex may be locked outside
 * @param id module id
 * @param level log level
 * @param fmt points to a format string
 * @return >0: success, others: failed
 */
int ais_log_unsafe(int id, int level, const char *fmt, ...);

/**
 * prints formatted log into buffer and is thread-safe
 * @param id module id
 * @param level log level
 * @param fmt points to a format string
 * @return >0: success, others: failed
 */
int ais_log(int id, int level, const char *fmt, ...);

/**
 * flushes all logs into buffer and is not thread-safe
 * generally is used in signal handlers when log mutex may be locked outside
 * @return 0: success, others: failed
 */
int ais_log_flush_unsafe(void);

/**
 * flushes all logs into buffer and is thread-safe
 * @return 0: success, others: failed
 */
int ais_log_flush(void);

typedef enum
{
    AIS_EVENT_KPI_SERVER_INIT,
    AIS_EVENT_KPI_SERVER_READY,
    AIS_EVENT_KPI_BE_SERVER_INIT,
    AIS_EVENT_KPI_BE_SERVER_READY,
    AIS_EVENT_KPI_CLIENT_START,
    AIS_EVENT_KPI_CLIENT_FIRST_FRAME,
    AIS_EVENT_KPI_SENSOR_PROG_START,
    AIS_EVENT_KPI_SENSOR_PROG_END,
    AIS_EVENT_KPI_DETECT_SENSORS_START,
    AIS_EVENT_KPI_DETECT_SENSORS_END,
    AIS_EVENT_KPI_CLIENT_FIRST_FRAME_POST_START,
    AIS_EVENT_KPI_CLIENT_FIRST_FRAME_POST_END,
    AIS_EVENT_KPI_MAX
} ais_event_kpi_t;

/**
 * boot KPI marker function
 * for AIS Server Ready
 * @return void
 */
void ais_log_kpi(ais_event_kpi_t event);

/**
 * INSTRUCTION TO ADD A NEW MODULE
 * 1, define module with an available id in ais_module.h
 * 2, add MODULE_xx=y in corresponding ais_log.conf
 * 3, redefine AIS_LOG in your module's c file just like those(AIS_LOG_SRV_xxx) in ais_server.c
 * 4, use the redefined AIS_LOG_xxx in your codes
 * 5, use the right log level based on error severity and message frequency.
 *    if a message is printed too often, use the lower severity level.
 */




/*
 * backward-compatible with old logging,
 * ALL CODES BELOW SHOULD BE REMOVED LATER
 */

#define CAM_MSG_ISR_LEVEL       AIS_LOG_LVL_DBG    // orginal value 0
#define CAM_MSG_LOW_LEVEL       AIS_LOG_LVL_LOW    // orginal value 1
#define CAM_MSG_MEDIUM_LEVEL    AIS_LOG_LVL_MED    // orginal value 2
#define CAM_MSG_HIGH_LEVEL      AIS_LOG_LVL_HIGH   // orginal value 3
#define CAM_MSG_ALWAYS_LEVEL    AIS_LOG_LVL_WARN   // orginal value 4
#define CAM_MSG_ERROR_LEVEL     AIS_LOG_LVL_ERROR  // orginal value 5
#define CAM_MSG_FATAL_LEVEL     AIS_LOG_LVL_CRIT   // orginal value 6
#define CAM_MSG_METRICS_LEVEL   AIS_LOG_LVL_FATAL  // orginal value 7
#define CAM_MSG_RESERVED_LEVEL  AIS_LOG_LVL_ALWAYS // orginal value 8


#define CAM_MSG(_level_, _fmt_, ...)                                           \
    do                                                                         \
    {                                                                          \
        int _lvl_ = CAM_MSG_ ## _level_ ## _LEVEL;                             \
        ais_log(AIS_MOD_ID_RSRV, _lvl_,  "%s:%d %s " _fmt_ "\n",               \
        __FUNCTION__, __LINE__, AIS_LOG_LVL_STR[_lvl_], ##__VA_ARGS__);        \
    } while (0)

#define CAM_MSG2(_level_, _mod_, _fmt_, ...)                                   \
    do                                                                         \
    {                                                                          \
        int _lvl_ = CAM_MSG_ ## _level_ ## _LEVEL;                             \
        ais_log(_mod_, _lvl_,  "%s:%d %s " _fmt_ "\n",                         \
        __FUNCTION__, __LINE__, AIS_LOG_LVL_STR[_lvl_], ##__VA_ARGS__);        \
    } while (0)

#define CAM_MSG_ON_ERR(cond, ...)                                              \
    do                                                                         \
    {                                                                          \
        if (cond)                                                              \
            CAM_MSG(ERROR, ##__VA_ARGS__);                                     \
    } while (0)



#ifdef __cplusplus
}
#endif


#endif //_AIS_LOG_H_
