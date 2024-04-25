#ifndef _AIS_MODULE_H_
#define _AIS_MODULE_H_
/*
 * @file ais_module.h
 *
 * @brief defines all modules id.
 *
 * Copyright (c) 2018-2020 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#ifdef __cplusplus
extern "C" {
#endif


#define AIS_MOD_ID_RSRV                     0            //reserved
#define AIS_MOD_ID_CAMERA_PLATFORM          1
#define AIS_MOD_ID_CAMERAQ                  2


#define AIS_MOD_ID_CLIENT                   10            //ais client
#define AIS_MOD_ID_SERVER                   11            //ais server

#define AIS_MOD_ID_CONN_HYPERVISOR          12            //hypervisor mmhab
#define AIS_MOD_ID_CONN_INTEGRITY           13            //integrity connection
#define AIS_MOD_ID_CONN_LINUX               14            //linux socket
#define AIS_MOD_ID_CONN_QNX                 15            //qnx socket

#define AIS_MOD_ID_EVENT_QUEUE              16            //event queue


#define AIS_MOD_ID_ENGINE                   20            //ais engine
#define AIS_MOD_ID_PPROC_MGR                21
#define AIS_MOD_ID_PPROC_ISP                22
#define AIS_MOD_ID_PPROC_GPU                23


#define AIS_MOD_ID_CCI_DRV                  30            //cci driver
#define AIS_MOD_ID_IFE_DRV                  31
#define AIS_MOD_ID_CSID_DRV                 32
#define AIS_MOD_ID_CSIPHY_DRV               33
#define AIS_MOD_ID_ICP_DRV                  34


#define AIS_MOD_ID_SENSOR_DEV               40            //sensor device
#define AIS_MOD_ID_SENSOR_PLATFORM          41            //sensor platform
#define AIS_MOD_ID_SENSOR_LIB               45            //sensor lib

//STATS
#define AIS_MOD_ID_AEC                      50
#define AIS_MOD_ID_AWB                      51
#define AIS_MOD_ID_AF                       52
#define AIS_MOD_ID_Q3A                      53
#define AIS_MOD_ID_ASD                      54
#define AIS_MOD_ID_AFD                      55

#define AIS_MOD_ID_QCARCAM_TEST             100          //qcarcam test


#define AIS_MOD_ID_DIAG_SERVER              120          // diagnostic server
#define AIS_MOD_ID_DIAG_CLIENT              121          // diagnostic client

#define AIS_MOD_ID_HIDL_SERVICE             150          //hidl client and server
#define AIS_MOD_ID_EVS_PROXY                151
#define AIS_MOD_ID_V4L2_PROXY               152

#define AIS_MOD_ID_EXT_CUST                 200          //Can extend custom ID beyond this point

#define AIS_MOD_ID_MAX_NUM                  256          //maximum number of module id

#ifdef __cplusplus
}
#endif

#endif //_AIS_MODULE_H_
