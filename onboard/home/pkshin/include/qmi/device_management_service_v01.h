#ifndef DMS_SERVICE_01_H
#define DMS_SERVICE_01_H
/**
  @file device_management_service_v01.h

  @brief This is the public header file which defines the dms service Data structures.

  This header file defines the types and structures that were defined in
  dms. It contains the constant values defined, enums, structures,
  messages, and service message IDs (in that order) Structures that were
  defined in the IDL as messages contain mandatory elements, optional
  elements, a combination of mandatory and optional elements (mandatory
  always come before optionals in the structure), or nothing (null message)

  An optional element in a message is preceded by a uint8_t value that must be
  set to true if the element is going to be included. When decoding a received
  message, the uint8_t values will be set to true or false by the decode
  routine, and should be checked before accessing the values that they
  correspond to.

  Variable sized arrays are defined as static sized arrays with an unsigned
  integer (32 bit) preceding it that must be set to the number of elements
  in the array that are valid. For Example:

  uint32_t test_opaque_len;
  uint8_t test_opaque[16];

  If only 4 elements are added to test_opaque[] then test_opaque_len must be
  set to 4 before sending the message.  When decoding, the _len value is set
  by the decode routine and should be checked so that the correct number of
  elements in the array will be accessed.

*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  Copyright (c) 2006-2018 Qualcomm Technologies, Inc.
  All rights reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.



  $Header: //commercial/MPSS.HE.1.0.c1.3/Main/modem_proc/qmimsgs/dms/api/device_management_service_v01.h#1 $
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
 *THIS IS AN AUTO GENERATED FILE. DO NOT ALTER IN ANY WAY
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/* This file was generated with Tool version 6.14.7 
   It was generated on: Tue Sep 25 2018 (Spin 0)
   From IDL File: device_management_service_v01.idl */

/** @defgroup dms_qmi_consts Constant values defined in the IDL */
/** @defgroup dms_qmi_msg_ids Constant values for QMI message IDs */
/** @defgroup dms_qmi_enums Enumerated types used in QMI messages */
/** @defgroup dms_qmi_messages Structures sent as QMI messages */
/** @defgroup dms_qmi_aggregates Aggregate types used in QMI messages */
/** @defgroup dms_qmi_accessor Accessor for QMI service object */
/** @defgroup dms_qmi_version Constant values for versioning information */

#include <stdint.h>
#include "qmi_idl_lib.h"
#include "common_v01.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup dms_qmi_version
    @{
  */
/** Major Version Number of the IDL used to generate this file */
#define DMS_V01_IDL_MAJOR_VERS 0x01
/** Revision Number of the IDL used to generate this file */
#define DMS_V01_IDL_MINOR_VERS 0x3C
/** Major Version Number of the qmi_idl_compiler used to generate this file */
#define DMS_V01_IDL_TOOL_VERS 0x06
/** Maximum Defined Message ID */
#define DMS_V01_MAX_MESSAGE_ID 0x0069
/**
    @}
  */


/** @addtogroup dms_qmi_consts
    @{
  */
#define QMI_DMS_POWER_SOURCE_BATTERY_V01 0
#define QMI_DMS_POWER_SOURCE_EXT_SOURCE_V01 1
#define QMI_DMS_RADIO_IF_LIST_MAX_V01 20
#define QMI_DMS_DEVICE_MANUFACTURER_MAX_V01 128
#define QMI_DMS_DEVICE_MODEL_ID_MAX_V01 256
#define QMI_DMS_DEVICE_REV_ID_MAX_V01 256
#define QMI_DMS_VOICE_NUMBER_MAX_V01 32
#define QMI_DMS_MOBILE_ID_NUMBER_MAX_V01 32
#define QMI_DMS_ESN_MAX_V01 32
#define QMI_DMS_IMEI_MAX_V01 32
#define QMI_DMS_MEID_MAX_V01 32
#define QMI_DMS_ENCRYPTED_ESN_MAX_V01 255
#define QMI_DMS_ENCRYPTED_IMEI_MAX_V01 255
#define QMI_DMS_ENCRYPTED_MEID_MAX_V01 255
#define QMI_DMS_ENCRYPTED_IMEISV_MAX_V01 255
#define QMI_DMS_PUK_VALUE_MAX_V01 16
#define QMI_DMS_PIN_VALUE_MAX_V01 16
#define QMI_DMS_HARDWARE_REV_MAX_V01 256
#define QMI_DMS_UIM_ID_MAX_V01 20
#define QMI_DMS_FACILITY_CK_MAX_V01 8
#define QMI_DMS_FACILITY_UNBLOCK_CK_MAX_V01 8
#define QMI_DMS_IMSI_MAX_V01 32
#define QMI_DMS_BOOT_CODE_REV_MAX_V01 255
#define QMI_DMS_PRI_REV_MAX_V01 16
#define QMI_DMS_IMEISV_MAX_V01 255
#define QMI_DMS_SW_VERSION_MAX_V01 32
#define QMI_DMS_SW_VERSION_MAX_EXT_V01 128
#define QMI_DMS_SPC_LEN_V01 6
#define QMI_DMS_LOCK_CODE_LEN_V01 4
#define QMI_DMS_MDN_MAX_V01 15
#define QMI_DMS_MIN_MAX_V01 15
#define QMI_DMS_HA_KEY_MAX_V01 16
#define QMI_DMS_AAA_KEY_MAX_V01 16
#define QMI_DMS_USER_DATA_MAX_V01 512
#define QMI_DMS_ERI_DATA_MAX_V01 1024
#define QMI_DMS_PRL_DATA_MAX_V01 1536
#define QMI_DMS_FACTORY_SN_MAX_V01 128
#define QMI_DMS_ACTIVATION_CODE_MAX_V01 81
#define QMI_DMS_MAX_CONFIG_LIST_LEN_V01 32
#define QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01 6
#define QMI_DMS_MAC_ADDR_MAX_V01 8
#define QMI_DMS_IMAGE_VER_MAX_V01 32
#define QMI_DMS_IMAGE_VER_LEN_MAX_V01 128
#define QMI_DMS_MAX_SUPPORTED_LTE_BANDS_V01 256
#define QMI_DMS_TX_MODEM_LEVEL_MAX_V01 100
#define QMI_DMS_AP_OS_VERSION_MAX_V01 60
#define QMI_DMS_AP_SW_VERSION_MAX_V01 60
/**
    @}
  */

typedef uint8_t dms_power_status_mask_v01;
#define QMI_DMS_MASK_POWER_SOURCE_V01 ((dms_power_status_mask_v01)0x01) 
#define QMI_DMS_MASK_BATTERY_CONNECTED_V01 ((dms_power_status_mask_v01)0x02) 
#define QMI_DMS_MASK_BATTERY_CHARGING_V01 ((dms_power_status_mask_v01)0x04) 
#define QMI_DMS_MASK_POWER_FAULT_V01 ((dms_power_status_mask_v01)0x08) 
typedef uint16_t dms_offline_reason_mask_v01;
#define QMI_DMS_MASK_OFFLINE_REASON_HOST_IMAGE_V01 ((dms_offline_reason_mask_v01)0x0001) 
#define QMI_DMS_MASK_OFFLINE_REASON_PRI_IMAGE_V01 ((dms_offline_reason_mask_v01)0x0002) 
#define QMI_DMS_MASK_OFFLINE_REASON_PRI_VERSION_V01 ((dms_offline_reason_mask_v01)0x0004) 
#define QMI_DMS_MASK_OFFLINE_REASON_DEVICE_MEMORY_V01 ((dms_offline_reason_mask_v01)0x0008) 
typedef uint64_t dms_band_capability_mask_v01;
#define QMI_DMS_MASK_BAND_PREF_BC0_A_V01 ((dms_band_capability_mask_v01)0x0000000000000001ull) 
#define QMI_DMS_MASK_BAND_PREF_BC0_B_V01 ((dms_band_capability_mask_v01)0x0000000000000002ull) 
#define QMI_DMS_MASK_BAND_PREF_BC1_V01 ((dms_band_capability_mask_v01)0x0000000000000004ull) 
#define QMI_DMS_MASK_BAND_PREF_BC2_V01 ((dms_band_capability_mask_v01)0x0000000000000008ull) 
#define QMI_DMS_MASK_BAND_PREF_BC3_V01 ((dms_band_capability_mask_v01)0x0000000000000010ull) 
#define QMI_DMS_MASK_BAND_PREF_BC4_V01 ((dms_band_capability_mask_v01)0x0000000000000020ull) 
#define QMI_DMS_MASK_BAND_PREF_BC5_V01 ((dms_band_capability_mask_v01)0x0000000000000040ull) 
#define QMI_DMS_MASK_BAND_PREF_GSM_DCS_1800_V01 ((dms_band_capability_mask_v01)0x0000000000000080ull) 
#define QMI_DMS_MASK_BAND_PREF_GSM_EGSM_900_V01 ((dms_band_capability_mask_v01)0x0000000000000100ull) 
#define QMI_DMS_MASK_BAND_PREF_GSM_PGSM_900_V01 ((dms_band_capability_mask_v01)0x0000000000000200ull) 
#define QMI_DMS_MASK_BAND_PREF_BC6_V01 ((dms_band_capability_mask_v01)0x0000000000000400ull) 
#define QMI_DMS_MASK_BAND_PREF_BC7_V01 ((dms_band_capability_mask_v01)0x0000000000000800ull) 
#define QMI_DMS_MASK_BAND_PREF_BC8_V01 ((dms_band_capability_mask_v01)0x0000000000001000ull) 
#define QMI_DMS_MASK_BAND_PREF_BC9_V01 ((dms_band_capability_mask_v01)0x0000000000002000ull) 
#define QMI_DMS_MASK_BAND_PREF_BC10_V01 ((dms_band_capability_mask_v01)0x0000000000004000ull) 
#define QMI_DMS_MASK_BAND_PREF_BC11_V01 ((dms_band_capability_mask_v01)0x0000000000008000ull) 
#define QMI_DMS_MASK_BAND_PREF_GSM_450_V01 ((dms_band_capability_mask_v01)0x0000000000010000ull) 
#define QMI_DMS_MASK_BAND_PREF_GSM_480_V01 ((dms_band_capability_mask_v01)0x0000000000020000ull) 
#define QMI_DMS_MASK_BAND_PREF_GSM_750_V01 ((dms_band_capability_mask_v01)0x0000000000040000ull) 
#define QMI_DMS_MASK_BAND_PREF_GSM_850_V01 ((dms_band_capability_mask_v01)0x0000000000080000ull) 
#define QMI_DMS_MASK_BAND_PREF_GSM_RGSM_900_V01 ((dms_band_capability_mask_v01)0x0000000000100000ull) 
#define QMI_DMS_MASK_BAND_PREF_GSM_PCS_1900_V01 ((dms_band_capability_mask_v01)0x0000000000200000ull) 
#define QMI_DMS_MASK_BAND_PREF_WCDMA_IMT_2100_V01 ((dms_band_capability_mask_v01)0x0000000000400000ull) 
#define QMI_DMS_MASK_BAND_PREF_WCDMA_PCS_1900_V01 ((dms_band_capability_mask_v01)0x0000000000800000ull) 
#define QMI_DMS_MASK_BAND_PREF_WCDMA_1800_V01 ((dms_band_capability_mask_v01)0x0000000001000000ull) 
#define QMI_DMS_MASK_BAND_PREF_WCDMA_1700_US_V01 ((dms_band_capability_mask_v01)0x0000000002000000ull) 
#define QMI_DMS_MASK_BAND_PREF_WCDMA_850_V01 ((dms_band_capability_mask_v01)0x0000000004000000ull) 
#define QMI_DMS_MASK_BAND_PREF_WCDMA_800_V01 ((dms_band_capability_mask_v01)0x0000000008000000ull) 
#define QMI_DMS_MASK_BAND_PREF_BC12_V01 ((dms_band_capability_mask_v01)0x0000000010000000ull) 
#define QMI_DMS_MASK_BAND_PREF_B14_V01 ((dms_band_capability_mask_v01)0x0000000020000000ull) 
#define QMI_DMS_MASK_BAND_PREF_B15_V01 ((dms_band_capability_mask_v01)0x0000000080000000ull) 
#define QMI_DMS_MASK_BAND_PREF_WCDMA_2600_V01 ((dms_band_capability_mask_v01)0x0001000000000000ull) 
#define QMI_DMS_MASK_BAND_PREF_WCDMA_900_V01 ((dms_band_capability_mask_v01)0x0002000000000000ull) 
#define QMI_DMS_MASK_BAND_PREF_WCDMA_1700_JPN_V01 ((dms_band_capability_mask_v01)0x0004000000000000ull) 
#define QMI_DMS_MASK_BAND_PREF_BC16_V01 ((dms_band_capability_mask_v01)0x0100000000000000ull) 
#define QMI_DMS_MASK_BAND_PREF_BC17_V01 ((dms_band_capability_mask_v01)0x0200000000000000ull) 
#define QMI_DMS_MASK_BAND_PREF_BC18_V01 ((dms_band_capability_mask_v01)0x0400000000000000ull) 
#define QMI_DMS_MASK_BAND_PREF_BC19_V01 ((dms_band_capability_mask_v01)0x0800000000000000ull) 
#define QMI_DMS_MASK_BAND_PREF_WCDMA_XIX_850_V01 ((dms_band_capability_mask_v01)0x1000000000000000ull) 
#define QMI_DMS_MASK_BAND_PREF_WCDMA_XI_1500_V01 ((dms_band_capability_mask_v01)0x2000000000000000ull) 
typedef uint64_t dms_lte_band_capability_mask_v01;
#define QMI_DMS_MASK_BAND_PREF_LTE_EB1_V01 ((dms_lte_band_capability_mask_v01)0x0000000000000001ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB2_V01 ((dms_lte_band_capability_mask_v01)0x0000000000000002ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB3_V01 ((dms_lte_band_capability_mask_v01)0x0000000000000004ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB4_V01 ((dms_lte_band_capability_mask_v01)0x0000000000000008ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB5_V01 ((dms_lte_band_capability_mask_v01)0x0000000000000010ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB6_V01 ((dms_lte_band_capability_mask_v01)0x0000000000000020ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB7_V01 ((dms_lte_band_capability_mask_v01)0x0000000000000040ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB8_V01 ((dms_lte_band_capability_mask_v01)0x0000000000000080ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB9_V01 ((dms_lte_band_capability_mask_v01)0x0000000000000100ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB10_V01 ((dms_lte_band_capability_mask_v01)0x0000000000000200ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB11_V01 ((dms_lte_band_capability_mask_v01)0x0000000000000400ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB12_V01 ((dms_lte_band_capability_mask_v01)0x0000000000000800ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB13_V01 ((dms_lte_band_capability_mask_v01)0x0000000000001000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB14_V01 ((dms_lte_band_capability_mask_v01)0x0000000000002000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB17_V01 ((dms_lte_band_capability_mask_v01)0x0000000000010000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB18_V01 ((dms_lte_band_capability_mask_v01)0x0000000000020000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB19_V01 ((dms_lte_band_capability_mask_v01)0x0000000000040000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB20_V01 ((dms_lte_band_capability_mask_v01)0x0000000000080000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB21_V01 ((dms_lte_band_capability_mask_v01)0x0000000000100000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB23_V01 ((dms_lte_band_capability_mask_v01)0x0000000000400000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB24_V01 ((dms_lte_band_capability_mask_v01)0x0000000000800000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB25_V01 ((dms_lte_band_capability_mask_v01)0x0000000001000000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB26_V01 ((dms_lte_band_capability_mask_v01)0x0000000002000000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB28_V01 ((dms_lte_band_capability_mask_v01)0x0000000008000000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB29_V01 ((dms_lte_band_capability_mask_v01)0x0000000010000000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB30_V01 ((dms_lte_band_capability_mask_v01)0x0000000020000000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB32_V01 ((dms_lte_band_capability_mask_v01)0x0000000080000000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB33_V01 ((dms_lte_band_capability_mask_v01)0x0000000100000000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB34_V01 ((dms_lte_band_capability_mask_v01)0x0000000200000000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB35_V01 ((dms_lte_band_capability_mask_v01)0x0000000400000000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB36_V01 ((dms_lte_band_capability_mask_v01)0x0000000800000000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB37_V01 ((dms_lte_band_capability_mask_v01)0x0000001000000000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB38_V01 ((dms_lte_band_capability_mask_v01)0x0000002000000000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB39_V01 ((dms_lte_band_capability_mask_v01)0x0000004000000000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB40_V01 ((dms_lte_band_capability_mask_v01)0x0000008000000000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB41_V01 ((dms_lte_band_capability_mask_v01)0x0000010000000000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB42_V01 ((dms_lte_band_capability_mask_v01)0x0000020000000000ull) 
#define QMI_DMS_MASK_BAND_PREF_LTE_EB43_V01 ((dms_lte_band_capability_mask_v01)0x0000040000000000ull) 
typedef uint64_t dms_tds_band_capability_mask_v01;
#define QMI_DMS_MASK_BAND_PREF_TDS_BANDA_V01 ((dms_tds_band_capability_mask_v01)0x0000000000000001ull) 
#define QMI_DMS_MASK_BAND_PREF_TDS_BANDB_V01 ((dms_tds_band_capability_mask_v01)0x0000000000000002ull) 
#define QMI_DMS_MASK_BAND_PREF_TDS_BANDC_V01 ((dms_tds_band_capability_mask_v01)0x0000000000000004ull) 
#define QMI_DMS_MASK_BAND_PREF_TDS_BANDD_V01 ((dms_tds_band_capability_mask_v01)0x0000000000000008ull) 
#define QMI_DMS_MASK_BAND_PREF_TDS_BANDE_V01 ((dms_tds_band_capability_mask_v01)0x0000000000000010ull) 
#define QMI_DMS_MASK_BAND_PREF_TDS_BANDF_V01 ((dms_tds_band_capability_mask_v01)0x0000000000000020ull) 
/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_BIND_SUBSCRIPTION_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_PRIMARY_SUBS_V01 = 0x0001, /**<  Primary \n  */
  DMS_SECONDARY_SUBS_V01 = 0x0002, /**<  Secondary \n  */
  DMS_TERTIARY_SUBS_V01 = 0x0003, /**<  Tertiary   */
  DMS_BIND_SUBSCRIPTION_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_bind_subscription_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  dms_bind_subscription_enum_v01 subscription;
  /**<   Subscription to which to bind. Values: \n
      - DMS_PRIMARY_SUBS (0x0001) --  Primary \n 
      - DMS_SECONDARY_SUBS (0x0002) --  Secondary \n 
      - DMS_TERTIARY_SUBS (0x0003) --  Tertiary  
 */

  uint8_t enabled;
  /**<   IMS capability of the device. Values:\n
        - 1 - IMS is enabled \n 
        - 0 - IMS is disabled  
   */
}dms_ims_capability_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Resets the DMS state variables of the requesting
           control point. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_reset_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Resets the DMS state variables of the requesting
           control point. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_reset_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t battery_lvl_lower_limit;
  /**<   The battery level is reported to the control point if the battery
       level falls below this lower limit (specified as percentage of
       remaining battery power from 0 to 100).
  */

  uint8_t battery_lvl_upper_limit;
  /**<   The battery level is reported to the control point if the battery
       level rises above the upper limit (specified as percentage of
       remaining battery power from 0 to 100).
   */
}dms_battery_lvl_limits_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Sets the device management state reporting conditions
           for the requesting control point. */
typedef struct {

  /* Optional */
  /*  Power State Reporting  */
  uint8_t report_power_state_valid;  /**< Must be set to true if report_power_state is being passed */
  uint8_t report_power_state;
  /**<   Values: \n
       - 0 -- Do not report \n
       - 1 -- Report on change in power state
  */

  /* Optional */
  /*  Battery Level Report Limits */
  uint8_t lvl_limits_valid;  /**< Must be set to true if lvl_limits is being passed */
  dms_battery_lvl_limits_type_v01 lvl_limits;

  /* Optional */
  /*  PIN State Reporting (Deprecated)  */
  uint8_t report_pin_state_valid;  /**< Must be set to true if report_pin_state is being passed */
  uint8_t report_pin_state;
  /**<   Values: \n
       - 0 -- Do not report \n
       - 1 -- Report on change in PIN state
  */

  /* Optional */
  /*  Activation State Reporting */
  uint8_t report_activation_state_valid;  /**< Must be set to true if report_activation_state is being passed */
  uint8_t report_activation_state;
  /**<   Values: \n
       - 0 -- Do not report \n
       - 1 -- Report activation state changes
  */

  /* Optional */
  /*  Operating Mode Reporting */
  uint8_t report_oprt_mode_state_valid;  /**< Must be set to true if report_oprt_mode_state is being passed */
  uint8_t report_oprt_mode_state;
  /**<   Values: \n
       - 0 -- Do not report \n
       - 1 -- Report operating mode changes     
  */

  /* Optional */
  /*  UIM State Reporting (Deprecated)  */
  uint8_t report_uim_state_valid;  /**< Must be set to true if report_uim_state is being passed */
  uint8_t report_uim_state;
  /**<   Values: \n
       - 0 -- Do not report \n
       - 1 -- Report UIM state changes
  */

  /* Optional */
  /*  Wireless Disable State Reporting */
  uint8_t report_wireless_disable_state_valid;  /**< Must be set to true if report_wireless_disable_state is being passed */
  uint8_t report_wireless_disable_state;
  /**<   Values: \n
       - 0 -- Do not report \n
       - 1 -- Report wireless disable state changes
  */

  /* Optional */
  /*  PRL Init Reporting */
  uint8_t report_prl_init_valid;  /**< Must be set to true if report_prl_init is being passed */
  uint8_t report_prl_init;
  /**<   Values: \n
       - 0 -- Do not report \n
       - 1 -- Report PRL initialized notification
  */

  /* Optional */
  /*  CDMA Lock Mode Reporting */
  uint8_t report_cdma_lock_mode_valid;  /**< Must be set to true if report_cdma_lock_mode is being passed */
  uint8_t report_cdma_lock_mode;
  /**<   Values: \n
       - 0 -- Do not report (default value) \n
       - 1 -- Report CDMA Lock mode state changes
  */

  /* Optional */
  /*  Device Multisim Information */
  uint8_t report_device_multisim_info_valid;  /**< Must be set to true if report_device_multisim_info is being passed */
  uint8_t report_device_multisim_info;
  /**<   Values: \n
       - 0 -- Do not report (default value) \n
       - 1 -- Report device multisim changes
  */
}dms_set_event_report_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Sets the device management state reporting conditions
           for the requesting control point. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_set_event_report_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  dms_power_status_mask_v01 power_status;
  /**<   Power status flags. Values:  \n
       Bit 0 -- Power source  \n
       - 0 -- Powered by battery \n
       - 1 -- Powered by external source \n

       Bit 1 -- Battery connected \n
       - 0 -- Not connected \n
       - 1 -- Connected \n

       Bit 2 -- Battery charging \n
       - 0 -- Not charging \n
       - 1 -- Charging \n

       Bit 3 -- Power fault \n
       - 0 -- No power fault \n
       - 1 -- Recognized power fault, calls inhibited
  */

  uint8_t battery_lvl;
  /**<   Level of the battery. Values: \n
       - 0x00 -- Battery is exhausted or the mobile device does not have a
                battery connected \n
       - 1 through 100 (0x64) -- Percentage of battery capacity remaining
  */
}dms_power_state_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_PIN_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_PIN_STATUS_NOT_INITIALIZED_V01 = 0x00, /**<  PIN is not initialized \n  */
  DMS_PIN_STATUS_ENABLED_NOT_VERIFIED_V01 = 0x01, /**<  PIN is enabled, not verified \n  */
  DMS_PIN_STATUS_ENABLED_VERIFIED_V01 = 0x02, /**<  PIN is enabled, verified \n  */
  DMS_PIN_STATUS_DISABLED_V01 = 0x03, /**<  PIN is disabled \n  */
  DMS_PIN_STATUS_BLOCKED_V01 = 0x04, /**<  PIN is blocked \n  */
  DMS_PIN_STATUS_PERMANENTLY_BLOCKED_V01 = 0x05, /**<  PIN is permanently blocked \n  */
  DMS_PIN_STATUS_UNBLOCKED_V01 = 0x06, /**<  PIN is unblocked \n   */
  DMS_PIN_STATUS_CHANGED_V01 = 0x07, /**<   PIN is changed  */
  DMS_PIN_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_pin_status_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  dms_pin_status_enum_v01 status;
  /**<   Current status of the PIN. Values: \n
      - DMS_PIN_STATUS_NOT_INITIALIZED (0x00) --  PIN is not initialized \n 
      - DMS_PIN_STATUS_ENABLED_NOT_VERIFIED (0x01) --  PIN is enabled, not verified \n 
      - DMS_PIN_STATUS_ENABLED_VERIFIED (0x02) --  PIN is enabled, verified \n 
      - DMS_PIN_STATUS_DISABLED (0x03) --  PIN is disabled \n 
      - DMS_PIN_STATUS_BLOCKED (0x04) --  PIN is blocked \n 
      - DMS_PIN_STATUS_PERMANENTLY_BLOCKED (0x05) --  PIN is permanently blocked \n 
      - DMS_PIN_STATUS_UNBLOCKED (0x06) --  PIN is unblocked \n  
      - DMS_PIN_STATUS_CHANGED (0x07) --   PIN is changed 
 */

  uint8_t verify_retries_left;
  /**<   Number of retries left, after which the PIN is blocked. */

  uint8_t unblock_retries_left;
  /**<   Number of unblock retries left, after which the PIN is
       permanently blocked and the UIM is unusable.
  */
}dms_pin_status_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_OPERATING_MODE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_OP_MODE_ONLINE_V01 = 0x00, /**<  Online \n */
  DMS_OP_MODE_LOW_POWER_V01 = 0x01, /**<  Low power \n   */
  DMS_OP_MODE_FACTORY_TEST_MODE_V01 = 0x02, /**<  Factory Test mode \n  */
  DMS_OP_MODE_OFFLINE_V01 = 0x03, /**<  Offline \n  */
  DMS_OP_MODE_RESETTING_V01 = 0x04, /**<  Resetting \n  */
  DMS_OP_MODE_SHUTTING_DOWN_V01 = 0x05, /**<  Shutting down \n  */
  DMS_OP_MODE_PERSISTENT_LOW_POWER_V01 = 0x06, /**<  Persistent low power \n  */
  DMS_OP_MODE_MODE_ONLY_LOW_POWER_V01 = 0x07, /**<  Mode-only low power \n  */
  DMS_OP_MODE_NET_TEST_GW_V01 = 0x08, /**<  Conducting network test for GSM/WCDMA  */
  DMS_OPERATING_MODE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_operating_mode_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_UIM_STATE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_UIM_INITIALIZATION_COMPLETED_V01 = 0x00, /**<  UIM initialization has completed \n  */
  DMS_UIM_INITIALIZATION_FAILED_V01 = 0x01, /**<  UIM has failed \n */
  DMS_UIM_NOT_PRESENT_V01 = 0x02, /**<  UIM is not present \n  */
  DMS_UIM_STATE_UNAVAILABLE_V01 = -1, /**<  UIM state is unavailable  */
  DMS_UIM_STATE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_uim_state_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_ACTIVATION_STATE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_ACTIVATION_NOT_ACTIVATED_V01 = 0x00, /**<  Service is not activated \n */
  DMS_ACTIVATION_ACTIVATED_V01 = 0x01, /**<  Service is activated \n */
  DMS_ACTIVATION_CONNECTING_V01 = 0x02, /**<  Activation connecting -- Network
                connection is in progress for automatic activation of service \n  */
  DMS_ACTIVATION_CONNECTED_V01 = 0x03, 
  DMS_ACTIVATION_OTASP_SEC_AUTHENTICATED_V01 = 0x4, /**<  OTASP security is authenticated \n  */
  DMS_ACTIVATION_OTASP_NAM_DOWNLOADED_V01 = 0x05, /**<  OTASP NAM is downloaded \n  */
  DMS_ACTIVATION_OTASP_MDN_DOWNLOADED_V01 = 0x06, /**<  OTASP MDN is downloaded  \n  */
  DMS_ACTIVATION_OTASP_IMSI_DOWNLOADED_V01 = 0x07, /**<  OTASP IMSI downloaded \n  */
  DMS_ACTIVATION_OTASP_PRL_DOWNLOADED_V01 = 0x08, /**<  OTASP PRL is downloaded \n  */
  DMS_ACTIVATION_OTASP_SPC_DOWNLOADED_V01 = 0x09, /**<  OTASP SPC is downloaded \n  */
  DMS_ACTIVATION_OTASP_SETTINGS_COMMITTED_V01 = 0x0A, /**<  OTASP settings are committed  */
  DMS_ACTIVATION_STATE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_activation_state_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_WIRELESS_DISABLE_STATE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_WIRELESS_DISABLE_OFF_V01 = 0x00, /**<  Wireless disable switch is
turned off \n  */
  DMS_WIRELESS_DISABLE_ON_V01 = 0x01, /**<  Wireless disable switch is
turned on  */
  DMS_WIRELESS_DISABLE_STATE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_wireless_disable_state_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_PRL_INIT_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_PRL_INIT_COMPLETED_V01 = 0x01, /**<  PRL is completely loaded into
the device (could be the default PRL)  */
  DMS_PRL_INIT_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_prl_init_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_CDMA_LOCK_MODE_STATE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_CDMA_LOCK_MODE_OFF_V01 = 0, /**<  Phone is not CDMA locked \n  */
  DMS_CDMA_LOCK_MODE_ON_V01 = 1, /**<  Phone is CDMA locked  */
  DMS_CDMA_LOCK_MODE_STATE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_cdma_lock_mode_state_enum_v01;
/**
    @}
  */

/**  Activation connected -- Network
                connection is connected for automatic activation of service \n  */
typedef uint64_t dms_subs_capability_mask_type_v01;
#define DMS_SUBS_CAPABILITY_AMPS_V01 ((dms_subs_capability_mask_type_v01)0x00000001ull) /**<  AMPS  */
#define DMS_SUBS_CAPABILITY_CDMA_V01 ((dms_subs_capability_mask_type_v01)0x00000002ull) /**<  CDMA  */
#define DMS_SUBS_CAPABILITY_HDR_V01 ((dms_subs_capability_mask_type_v01)0x00000004ull) /**<  HDR  */
#define DMS_SUBS_CAPABILITY_GSM_V01 ((dms_subs_capability_mask_type_v01)0x00000008ull) /**<  GSM  */
#define DMS_SUBS_CAPABILITY_WCDMA_V01 ((dms_subs_capability_mask_type_v01)0x00000010ull) /**<  WCDMA  */
#define DMS_SUBS_CAPABILITY_LTE_V01 ((dms_subs_capability_mask_type_v01)0x00000020ull) /**<  LTE  */
#define DMS_SUBS_CAPABILITY_TDS_V01 ((dms_subs_capability_mask_type_v01)0x00000040ull) /**<  TDS  */
/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_SUBS_VOICE_DATA_CAPABILITY_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_SUBS_VOICE_DATA_CAPABILITY_NORMAL_V01 = 0x01, /**<  Normal \n  */
  DMS_SUBS_VOICE_DATA_CAPABILITY_SGLTE_V01 = 0x02, /**<  SGLTE \n  */
  DMS_SUBS_VOICE_DATA_CAPABILITY_CSFB_V01 = 0x03, /**<  CSFB \n  */
  DMS_SUBS_VOICE_DATA_CAPABILITY_SVLTE_V01 = 0x04, /**<  SVLTE \n  */
  DMS_SUBS_VOICE_DATA_CAPABILITY_SRLTE_V01 = 0x05, /**<  SRLTE  */
  DMS_SUBS_VOICE_DATA_CAPABILITY_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_subs_voice_data_capability_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_PRL_SOURCE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_PRL_SOURCE_INFO_UNDETERMINED_V01 = 0, /**<  PRL is not loaded \n */
  DMS_PRL_SOURCE_INFO_DEFAULT_V01 = 1, /**<  PRL source is the default PRL \n  */
  DMS_PRL_SOURCE_INFO_NV_V01 = 2, /**<  PRL source is the nonvolatile memory \n */
  DMS_PRL_SOURCE_INFO_CARD_V01 = 3, /**<  PRL source is the card  */
  DMS_PRL_SOURCE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_prl_source_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t max_active;
  /**<   Maximum number of subscriptions listed in this configuration that can be 
       simultaneously active. If this number is less than max_subscriptions, it implies
       that any combination of the subscriptions in this configuration can be active 
       and the remaining can be in standby. */

  uint32_t subscription_list_len;  /**< Must be set to # of elements in subscription_list */
  dms_subs_capability_mask_type_v01 subscription_list[QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01];
  /**<   Array of max_subscriptions entries where each entry is a mask of capabilities.
 The client ignores any bits in the mask that it does not recognize. Values: 
      - DMS_SUBS_CAPABILITY_AMPS (0x00000001) --  AMPS 
      - DMS_SUBS_CAPABILITY_CDMA (0x00000002) --  CDMA 
      - DMS_SUBS_CAPABILITY_HDR (0x00000004) --  HDR 
      - DMS_SUBS_CAPABILITY_GSM (0x00000008) --  GSM 
      - DMS_SUBS_CAPABILITY_WCDMA (0x00000010) --  WCDMA 
      - DMS_SUBS_CAPABILITY_LTE (0x00000020) --  LTE 
      - DMS_SUBS_CAPABILITY_TDS (0x00000040) --  TDS  */
}dms_subs_config_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t max_subscriptions;
  /**<   Maximum number of subscriptions that can be supported simultaneously. */

  uint32_t subscription_config_list_len;  /**< Must be set to # of elements in subscription_config_list */
  dms_subs_config_type_v01 subscription_config_list[QMI_DMS_MAX_CONFIG_LIST_LEN_V01];
  /**<   List of supported multi-SIM configurations. */
}dms_multisim_capability_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  dms_subs_voice_data_capability_enum_v01 subs_voice_data_capability;
  /**<   The simultaneous voice and data capability type of a subscription. 
 Values: 
      - DMS_SUBS_VOICE_DATA_CAPABILITY_NORMAL (0x01) --  Normal \n 
      - DMS_SUBS_VOICE_DATA_CAPABILITY_SGLTE (0x02) --  SGLTE \n 
      - DMS_SUBS_VOICE_DATA_CAPABILITY_CSFB (0x03) --  CSFB \n 
      - DMS_SUBS_VOICE_DATA_CAPABILITY_SVLTE (0x04) --  SVLTE \n 
      - DMS_SUBS_VOICE_DATA_CAPABILITY_SRLTE (0x05) --  SRLTE  */

  uint8_t simul_voice_data_capable;
  /**<   The simultaneous voice and data capability of a subscription. 
  */
}dms_subs_voice_data_capability_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t max_subscriptions;
  /**<   The maximum number of subscriptions that can be supported simultaneously.   */

  uint8_t max_active;
  /**<   The maximum number of subscriptions that can be simultaneously active. 
       If this number is less than max_subscriptions, it implies that any combination 
       of the subscriptions in this configuration can be active 
       and the remaining can be in standby. */
}dms_current_multisim_capability_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t prl_version;
  /**<   PRL version. */

  uint8_t prl_only;
  /**<   Values: \n
       - 0 -- Unset \n
       - 1 -- Set
  */

  dms_prl_source_enum_v01 prl_source;
  /**<   Values: \n
      - DMS_PRL_SOURCE_INFO_UNDETERMINED (0) --  PRL is not loaded \n
      - DMS_PRL_SOURCE_INFO_DEFAULT (1) --  PRL source is the default PRL \n 
      - DMS_PRL_SOURCE_INFO_NV (2) --  PRL source is the nonvolatile memory \n
      - DMS_PRL_SOURCE_INFO_CARD (3) --  PRL source is the card 
 */
}dms_prl_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t subs_cfg_list_len;  /**< Must be set to # of elements in subs_cfg_list */
  dms_subs_capability_mask_type_v01 subs_cfg_list[QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01];
  /**<   Array of max_subscriptions entries where each entry is a mask of capabilities.
 The client ignores any bits in the mask that it does not recognize. Values: 
      - DMS_SUBS_CAPABILITY_AMPS (0x00000001) --  AMPS 
      - DMS_SUBS_CAPABILITY_CDMA (0x00000002) --  CDMA 
      - DMS_SUBS_CAPABILITY_HDR (0x00000004) --  HDR 
      - DMS_SUBS_CAPABILITY_GSM (0x00000008) --  GSM 
      - DMS_SUBS_CAPABILITY_WCDMA (0x00000010) --  WCDMA 
      - DMS_SUBS_CAPABILITY_LTE (0x00000020) --  LTE 
      - DMS_SUBS_CAPABILITY_TDS (0x00000040) --  TDS  */
}dms_device_config_list_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t max_subscriptions;
  /**<   The maximum number of subscriptions that can be supported simultaneously. */

  uint8_t max_active;
  /**<   The maximum number of subscriptions that can be simultaneously active out of 
       all listed configurations. If this number is less than max_subscriptions, it 
       implies that any combination of the subscriptions in these configurations 
       can be active and the remaining can be in standby. */

  uint32_t device_cfg_list_len;  /**< Must be set to # of elements in device_cfg_list */
  dms_device_config_list_type_v01 device_cfg_list[QMI_DMS_MAX_CONFIG_LIST_LEN_V01];
  /**<   List of supported multi-SIM configurations. */

  uint8_t current_config_index;
  /**<   The current device configuration is pointed by the configuration at this
       index from the list in device_cfg_list. */
}dms_device_config_capability_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Indication Message; Sets the device management state reporting conditions
           for the requesting control point. */
typedef struct {

  /* Optional */
  /*  Power State */
  uint8_t power_state_valid;  /**< Must be set to true if power_state is being passed */
  dms_power_state_type_v01 power_state;

  /* Optional */
  /*  PIN 1 Status (Deprecated)  */
  uint8_t pin1_status_valid;  /**< Must be set to true if pin1_status is being passed */
  dms_pin_status_type_v01 pin1_status;

  /* Optional */
  /*  PIN 2 Status (Deprecated)  */
  uint8_t pin2_status_valid;  /**< Must be set to true if pin2_status is being passed */
  dms_pin_status_type_v01 pin2_status;

  /* Optional */
  /*  Activation State  */
  uint8_t activation_state_valid;  /**< Must be set to true if activation_state is being passed */
  dms_activation_state_enum_v01 activation_state;
  /**<   Service activation state. Values: \n
      - DMS_ACTIVATION_NOT_ACTIVATED (0x00) --  Service is not activated \n
      - DMS_ACTIVATION_ACTIVATED (0x01) --  Service is activated \n
      - DMS_ACTIVATION_CONNECTING (0x02) --  Activation connecting -- Network
                connection is in progress for automatic activation of service \n 
      - DMS_ACTIVATION_CONNECTED (0x03) -- 
      - DMS_ACTIVATION_OTASP_SEC_AUTHENTICATED (0x4) --  OTASP security is authenticated \n 
      - DMS_ACTIVATION_OTASP_NAM_DOWNLOADED (0x05) --  OTASP NAM is downloaded \n 
      - DMS_ACTIVATION_OTASP_MDN_DOWNLOADED (0x06) --  OTASP MDN is downloaded  \n 
      - DMS_ACTIVATION_OTASP_IMSI_DOWNLOADED (0x07) --  OTASP IMSI downloaded \n 
      - DMS_ACTIVATION_OTASP_PRL_DOWNLOADED (0x08) --  OTASP PRL is downloaded \n 
      - DMS_ACTIVATION_OTASP_SPC_DOWNLOADED (0x09) --  OTASP SPC is downloaded \n 
      - DMS_ACTIVATION_OTASP_SETTINGS_COMMITTED (0x0A) --  OTASP settings are committed  
 */

  /* Optional */
  /*  Operating Mode */
  uint8_t operating_mode_valid;  /**< Must be set to true if operating_mode is being passed */
  dms_operating_mode_enum_v01 operating_mode;
  /**<   Current operating mode. Values: \n
      - DMS_OP_MODE_ONLINE (0x00) --  Online \n
      - DMS_OP_MODE_LOW_POWER (0x01) --  Low power \n  
      - DMS_OP_MODE_FACTORY_TEST_MODE (0x02) --  Factory Test mode \n 
      - DMS_OP_MODE_OFFLINE (0x03) --  Offline \n 
      - DMS_OP_MODE_RESETTING (0x04) --  Resetting \n 
      - DMS_OP_MODE_SHUTTING_DOWN (0x05) --  Shutting down \n 
      - DMS_OP_MODE_PERSISTENT_LOW_POWER (0x06) --  Persistent low power \n 
      - DMS_OP_MODE_MODE_ONLY_LOW_POWER (0x07) --  Mode-only low power \n 
      - DMS_OP_MODE_NET_TEST_GW (0x08) --  Conducting network test for GSM/WCDMA 
 */

  /* Optional */
  /*  UIM State (Deprecated)  */
  uint8_t uim_state_valid;  /**< Must be set to true if uim_state is being passed */
  dms_uim_state_enum_v01 uim_state;
  /**<   UIM state. Values: \n
      - DMS_UIM_INITIALIZATION_COMPLETED (0x00) --  UIM initialization has completed \n 
      - DMS_UIM_INITIALIZATION_FAILED (0x01) --  UIM has failed \n
      - DMS_UIM_NOT_PRESENT (0x02) --  UIM is not present \n 
      - DMS_UIM_STATE_UNAVAILABLE (-1) --  UIM state is unavailable 
 */

  /* Optional */
  /*  Wireless Disable State */
  uint8_t wireless_disable_state_valid;  /**< Must be set to true if wireless_disable_state is being passed */
  dms_wireless_disable_state_enum_v01 wireless_disable_state;
  /**<   Wireless disable state. Values: \n
      - DMS_WIRELESS_DISABLE_OFF (0x00) --  Wireless disable switch is
turned off \n 
      - DMS_WIRELESS_DISABLE_ON (0x01) --  Wireless disable switch is
turned on 
 */

  /* Optional */
  /*  PRL Init Notification */
  uint8_t prl_init_valid;  /**< Must be set to true if prl_init is being passed */
  dms_prl_init_enum_v01 prl_init;
  /**<   PRL initialized. Values: \n
      - DMS_PRL_INIT_COMPLETED (0x01) --  PRL is completely loaded into
the device (could be the default PRL)  
 */

  /* Optional */
  /*  CDMA Lock Mode State */
  uint8_t cdma_lock_mode_state_valid;  /**< Must be set to true if cdma_lock_mode_state is being passed */
  dms_cdma_lock_mode_state_enum_v01 cdma_lock_mode_state;
  /**<   CDMA Lock mode state. Values: \n
      - DMS_CDMA_LOCK_MODE_OFF (0) --  Phone is not CDMA locked \n 
      - DMS_CDMA_LOCK_MODE_ON (1) --  Phone is CDMA locked  
 */

  /* Optional */
  /*  Device Multisim Capability (Deprecated) */
  uint8_t multisim_capability_valid;  /**< Must be set to true if multisim_capability is being passed */
  dms_multisim_capability_type_v01 multisim_capability;
  /**<   \n This TLV is deprecated. Use Device Multisim Voice Data Capability to support
       multiple simultaneously active radio interfaces.
  */

  /* Optional */
  /*  Device Multisim Voice Data Capability */
  uint8_t current_multisim_capability_valid;  /**< Must be set to true if current_multisim_capability is being passed */
  dms_current_multisim_capability_type_v01 current_multisim_capability;
  /**<   \n Device voice and data capability for supporting multiple simultaneously 
        active radio interfaces.
  */

  /* Optional */
  /*  Current Subscription Capability */
  uint8_t current_subscription_capability_valid;  /**< Must be set to true if current_subscription_capability is being passed */
  uint32_t current_subscription_capability_len;  /**< Must be set to # of elements in current_subscription_capability */
  dms_subs_capability_mask_type_v01 current_subscription_capability[QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01];
  /**<   An array of max_subscriptions entries where each entry is a mask of capabilities.
 The client ignores any bits in the mask that it does not recognize. Values: 
      - DMS_SUBS_CAPABILITY_AMPS (0x00000001) --  AMPS 
      - DMS_SUBS_CAPABILITY_CDMA (0x00000002) --  CDMA 
      - DMS_SUBS_CAPABILITY_HDR (0x00000004) --  HDR 
      - DMS_SUBS_CAPABILITY_GSM (0x00000008) --  GSM 
      - DMS_SUBS_CAPABILITY_WCDMA (0x00000010) --  WCDMA 
      - DMS_SUBS_CAPABILITY_LTE (0x00000020) --  LTE 
      - DMS_SUBS_CAPABILITY_TDS (0x00000040) --  TDS  
 */

  /* Optional */
  /*  Subscription Voice Data Capability of the Device */
  uint8_t subs_voice_data_capability_valid;  /**< Must be set to true if subs_voice_data_capability is being passed */
  uint32_t subs_voice_data_capability_len;  /**< Must be set to # of elements in subs_voice_data_capability */
  dms_subs_voice_data_capability_type_v01 subs_voice_data_capability[QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01];
  /**<   \n Voice and data capability of each subscription of the device.
  */

  /* Optional */
  /*  Maximum Active Data Subscriptions */
  uint8_t max_active_data_subscriptions_valid;  /**< Must be set to true if max_active_data_subscriptions is being passed */
  uint8_t max_active_data_subscriptions;
  /**<   The maximum number of subscriptions that can be simultaneously active for data activity. 
       If this value is less than max_subscriptions, it implies that any combination 
       of the subscriptions in this configuration can be active and the remaining can be in standby.
  */

  /* Optional */
  /*  PRL Information */
  uint8_t prl_info_valid;  /**< Must be set to true if prl_info is being passed */
  dms_prl_info_type_v01 prl_info;
  /**<   \n This TLV contains prl_version, prl_source, and prl_pref_only information.
  */

  /* Optional */
  /*  Maximum Device Configuration List */
  uint8_t device_config_list_valid;  /**< Must be set to true if device_config_list is being passed */
  dms_device_config_capability_type_v01 device_config_list;
  /**<   List of maximum configurations and the current configuration of the device.
  */

  /* Optional */
  /*  Explicit Configuration Index */
  uint8_t explicit_config_index_valid;  /**< Must be set to true if explicit_config_index is being passed */
  int16_t explicit_config_index;
  /**<    Indicates whether the current configuration is modem selected or HLOS specified.
        Values:\n
             - -1 -- Modem controlled configuration \n 
             - Any other valid value -- HLOS selected the static configuration and 
               points to an index in device_cfg_list of the Maximum 
			   Device Configuration List TLV.
   */
}dms_event_report_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Registers the requesting control point for various indications. */
typedef struct {

  /* Optional */
  /*  Power Save Mode Status */
  uint8_t report_psm_status_valid;  /**< Must be set to true if report_psm_status is being passed */
  uint8_t report_psm_status;
  /**<   Values: \n
	  - 0 -- Do not report \n
	  - 1 -- Report PSM status 
  */

  /* Optional */
  /*  Power Save Mode Configuration Change Information  */
  uint8_t report_psm_cfg_change_valid;  /**< Must be set to true if report_psm_cfg_change is being passed */
  uint8_t report_psm_cfg_change;
  /**<   Values: \n
	  - 0 -- Do not report \n
	  - 1 -- Report Power Save Mode configuration changes 
  */

  /* Optional */
  /*  Report IMS Capability  */
  uint8_t report_ims_capability_valid;  /**< Must be set to true if report_ims_capability is being passed */
  uint8_t report_ims_capability;
  /**<   Values: \n
	  - 0 -- Do not report \n
	  - 1 -- Report IMS capability 
  */
}dms_indication_register_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Registers the requesting control point for various indications. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_indication_register_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Requests the device capabilities. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_device_cap_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_DATA_SERVICE_CAPABILITY_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_DATA_CAP_NONE_V01 = 0x00, /**<  No data services supported \n  */
  DMS_DATA_CAP_CS_ONLY_V01 = 0x01, /**<  Only circuit-switched (CS) services
are supported \n  */
  DMS_DATA_CAP_PS_ONLY_V01 = 0x02, /**<  Only packet-switched (PS) services
are supported \n  */
  DMS_DATA_CAP_SIMUL_CS_AND_PS_V01 = 0x03, /**<  Simultaneous CS and PS \n  */
  DMS_DATA_CAP_NONSIMUL_CS_AND_PS_V01 = 0x04, /**<  Nonsimultaneous CS and PS  */
  DMS_DATA_SERVICE_CAPABILITY_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_data_service_capability_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_SIM_CAPABILITY_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_SIM_NOT_SUPPORTED_V01 = 0x01, /**<  SIM is not supported \n */
  DMS_SIM_SUPPORTED_V01 = 0x02, /**<  SIM is supported  */
  DMS_SIM_CAPABILITY_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_sim_capability_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_RADIO_IF_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_RADIO_IF_1X_V01 = 0x01, /**<  CDMA2000 1X \n */
  DMS_RADIO_IF_1X_EVDO_V01 = 0x02, /**<  CDMA2000 HRPD (1xEV-DO) \n */
  DMS_RADIO_IF_GSM_V01 = 0x04, /**<  GSM \n */
  DMS_RADIO_IF_UMTS_V01 = 0x05, /**<  UMTS \n  */
  DMS_RADIO_IF_LTE_V01 = 0x08, /**<  LTE \n */
  DMS_RADIO_IF_TDS_V01 = 0x09, /**<  TDS  */
  DMS_RADIO_IF_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_radio_if_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_DEVICE_SERVICE_CAPABILITY_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_DEVICE_CAP_DATA_ONLY_V01 = 0x01, /**<  Only data services are supported \n  */
  DMS_DEVICE_CAP_VOICE_ONLY_V01 = 0x02, /**<   Only voice services are supported \n */
  DMS_DEVICE_CAP_SIMUL_VOICE_AND_DATA_V01 = 0x03, /**<  Simultaneous voice and data \n  */
  DMS_DEVICE_CAP_NONSIMUL_VOICE_AND_DATA_V01 = 0x04, /**<  Nonsimultaneous voice and data  */
  DMS_DEVICE_SERVICE_CAPABILITY_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_device_service_capability_enum_v01;
/**
    @}
  */

typedef uint64_t dms_voice_support_capability_mask_v01;
#define QMI_DMS_MASK_VOICE_SUPPORT_GW_CSFB_CAPABLE_V01 ((dms_voice_support_capability_mask_v01)0x0001ull) /**<    */
#define QMI_DMS_MASK_VOICE_SUPPORT_1x_CSFB_CAPABLE_V01 ((dms_voice_support_capability_mask_v01)0x0002ull) /**<    */
#define QMI_DMS_MASK_VOICE_SUPPORT_VOLTE_CAPABLE_V01 ((dms_voice_support_capability_mask_v01)0x0004ull) /**<    */
typedef uint64_t dms_simul_voice_and_data_capability_mask_v01;
#define QMI_DMS_MASK_SVLTE_CAPABLE_V01 ((dms_simul_voice_and_data_capability_mask_v01)0x0001ull) 
#define QMI_DMS_MASK_SVDO_CAPABLE_V01 ((dms_simul_voice_and_data_capability_mask_v01)0x0002ull) 
#define QMI_DMS_MASK_SGLTE_CAPABLE_V01 ((dms_simul_voice_and_data_capability_mask_v01)0x0004ull) 
/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_DEVICE_SUBS_FEATURE_MODE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_DEVICE_SUBS_FEATURE_MODE_NORMAL_V01 = 0, /**<  Normal \n  */
  DMS_DEVICE_SUBS_FEATURE_MODE_SGLTE_V01 = 1, /**<  SGLTE \n  */
  DMS_DEVICE_SUBS_FEATURE_MODE_SVLTE_V01 = 2, /**<  SVLTE \n  */
  DMS_DEVICE_SUBS_FEATURE_MODE_SRLTE_V01 = 3, /**<  SRLTE \n  */
  DMS_DEVICE_SUBS_FEATURE_MODE_DUAL_MULTIMODE_V01 = 4, /**<  Dual multimode  */
  DMS_DEVICE_SUBS_FEATURE_MODE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_device_subs_feature_mode_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_DEVICE_CDMA_1X_REL_INFO_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_REV_JSTD008_V01 = 0x01, /**<  JSTD008 \n  */
  DMS_REV_IS95A_V01 = 0x02, /**<  IS95A \n  */
  DMS_REV_IS95B_V01 = 0x03, /**<  IS95B \n  */
  DMS_REV_IS2000_V01 = 0x04, /**<  IS2000 \n  */
  DMS_REV_IS2000_REL_A_V01 = 0x05, /**<  IS2000_REL_A\n  */
  DMS_REV_IS2000_REL_B_V01 = 0x06, /**<  IS2000_REL_B \n  */
  DMS_REV_IS2000_REL_C_V01 = 0x07, /**<  IS2000_REL_C \n  */
  DMS_REV_IS2000_REL_C_MI_V01 = 0x08, /**<  IS2000_REL_C_MI \n  */
  DMS_REV_IS2000_REL_D_V01 = 0x09, /**<  IS2000_REL_D \n  */
  DMS_REV_UNAVAILABLE_V01 = 0xFF, 
  DMS_DEVICE_CDMA_1X_REL_INFO_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_device_cdma_1x_rel_info_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_DEVICE_GSM_REL_INFO_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_GSM_RELEASE_VERSION_9_V01 = 0x01, /**<  GSM_REL \n  */
  DMS_GSM_REV_UNAVAILABLE_V01 = 0xFF, 
  DMS_DEVICE_GSM_REL_INFO_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_device_gsm_rel_info_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_DEVICE_WCDMA_REL_INFO_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_WCDMA_REL_99_V01 = 0x01, /**<  REL_99 \n  */
  DMS_WCDMA_REL_5_V01 = 0x02, /**<  REL_5 \n  */
  DMS_WCDMA_REL_6_V01 = 0x03, /**<  REL_6 \n  */
  DMS_WCDMA_REL_7_V01 = 0x04, /**<  REL_7 \n  */
  DMS_WCDMA_REL_8_V01 = 0x05, /**<  REL_8 \n  */
  DMS_WCDMA_REL_9_V01 = 0x06, /**<  REL_9 \n  */
  DMS_WCDMA_REL_10_V01 = 0x07, /**<  REL_10 \n  */
  DMS_WCDMA_REL_11_V01 = 0x08, /**<  REL_11 \n  */
  DMS_WCDMA_REL_12_V01 = 0x09, /**<  REL_12 \n  */
  DMS_WCDMA_REV_UNAVAILABLE_V01 = 0xFF, 
  DMS_DEVICE_WCDMA_REL_INFO_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_device_wcdma_rel_info_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_DEVICE_LTE_RAT_REL_INFO_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_LTE_3GPP_REL_8_V01 = 0x01, 
  DMS_LTE_3GPP_REL8_DEC_08_V01 = 0x02, 
  DMS_LTE_3GPP_REL8_MAR_09_V01 = 0x03, 
  DMS_LTE_3GPP_REL8_JUN_09_V01 = 0x04, 
  DMS_LTE_3GPP_REL8_SEP_09_V01 = 0x05, 
  DMS_LTE_3GPP_REL8_DEC_09_V01 = 0x06, 
  DMS_LTE_3GPP_REL8_MAR_10_V01 = 0x07, 
  DMS_LTE_3GPP_REL8_JUN_10_V01 = 0x08, 
  DMS_LTE_3GPP_REL8_SEP_10_V01 = 0x09, 
  DMS_LTE_3GPP_REL8_DEC_10_V01 = 0x0A, 
  DMS_LTE_3GPP_REL_9_V01 = 0x0B, 
  DMS_LTE_3GPP_REL9_MAR_10_V01 = 0x0C, 
  DMS_LTE_3GPP_REL9_JUN_10_V01 = 0x0D, 
  DMS_LTE_3GPP_REL9_SEP_10_V01 = 0x0E, 
  DMS_LTE_3GPP_REL_10_V01 = 0x0F, 
  DMS_LTE_3GPP_REL10_SEP_11_V01 = 0x10, 
  DMS_LTE_3GPP_REL10_DEC_11_V01 = 0x11, 
  DMS_LTE_3GPP_REL10_MAR_12_V01 = 0x12, 
  DMS_LTE_3GPP_REL10_JUN_12_V01 = 0x13, 
  DMS_LTE_3GPP_REL10_SEP_12_V01 = 0x14, 
  DMS_LTE_3GPP_REL10_DEC_12_V01 = 0x15, 
  DMS_LTE_3GPP_REL10_MAR_13_V01 = 0x16, 
  DMS_LTE_3GPP_REL10_JUN_13_V01 = 0x17, 
  DMS_LTE_3GPP_REL_11_V01 = 0x18, 
  DMS_LTE_3GPP_REL11_JUN_13_V01 = 0x19, 
  DMS_LTE_3GPP_REL11_MAR_14_V01 = 0x1A, 
  DMS_LTE_3GPP_REL_12_V01 = 0x1B, 
  DMS_LTE_3GPP_REL_13_V01 = 0x1C, 
  DMS_LTE_3GPP_REL_14_V01 = 0x1D, 
  DMS_LTE_3GPP_REL_15_V01 = 0x1E, 
  DMS_LTE_REV_UNAVAILABLE_V01 = 0xFF, 
  DMS_DEVICE_LTE_RAT_REL_INFO_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_device_lte_rat_rel_info_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_DEVICE_HDR_RAT_REL_INFO_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_HDR_EVDO_REL_0_V01 = 0x01, 
  DMS_HDR_EVDO_REL_A_V01 = 0x02, 
  DMS_HDR_EVDO_REL_B_V01 = 0x03, 
  DMS_HDR_EVDO_REL_C_V01 = 0x04, 
  DMS_HDR_REV_UNAVAILABLE_V01 = 0xFF, 
  DMS_DEVICE_HDR_RAT_REL_INFO_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_device_hdr_rat_rel_info_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_DEVICE_TDSCDMA_REL_INFO_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_TDSRRC_REL_VERSION_4_V01 = 0x01, /**<  Rel version 4 \n  */
  DMS_TDSRRC_REL_VERSION_5_V01 = 0x02, /**<  Rel version 5 \n  */
  DMS_TDSRRC_REL_VERSION_6_V01 = 0x03, /**<  Rel version 6 \n  */
  DMS_TDSRRC_REL_VERSION_7_V01 = 0x04, /**<  Rel version 7 \n  */
  DMS_TDSRRC_REL_VERSION_8_V01 = 0x05, /**<  Rel version 8\n  */
  DMS_TDSRRC_REL_VERSION_9_V01 = 0x06, /**<  Rel version 9 \n  */
  DMS_TDSCDMA_REV_UNAVAILABLE_V01 = 0xFF, 
  DMS_DEVICE_TDSCDMA_REL_INFO_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_device_tdscdma_rel_info_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
/** RAT not supported on the device 
                                                     or rel info is not available \n 
RAT not supported on the device 
                                                      or rel info is not available \n 
RAT not supported on the device 
                                                      or rel info is not available \n 
Rel8 versions
Rel8 versions
Rel8 versions
Rel8 versions
Rel8 versions
Rel8 versions
Rel8 versions
Rel8 versions
Rel8 versions
Rel8 versions
Rel 9 versions
Rel 9 versions
Rel 9 versions
Rel 9 versions
Rel 10 version June 2011 release
Rel 10 versions 
Rel 10 versions
Rel 10 versions
Rel 10 versions 
Rel 10 versions
Rel 10 versions v10.8.0 
Rel 10 versions v10.9.0 
Rel 10 versions v10.10.0 
Rel 11 versions Dec 2012 release
Rel 11 versions
Rel 11 versions                 
Rel 12 versions
Rel 13 versions
Rel 14 versions
Rel 15 versions
RAT not supported on the device 
                                                      or rel info is not available \n 
HDR REL 0 
HDR REL A 
HDR REL B  
HDR REL C 
RAT not supported on the device 
                                                   or rel info is not available \n 
RAT not supported on the device 
                                                       or rel info is not available \n  
 */
typedef struct {

  uint32_t max_tx_channel_rate;
  /**<   Maximum Tx transmission rate in bits per second (bps) supported
       by the device. The value 0xFFFFFFFF implies a rate greater than 
       or equal to 0xFFFFFFFF (4 Gbps). In multitechnology devices, this 
       value is the greatest rate among all supported technologies.
  */

  uint32_t max_rx_channel_rate;
  /**<   Maximum Rx transmission rate in bits per second (bps) supported
       by the device. The value 0xFFFFFFFF implies rate greater than or 
       equal to 0xFFFFFFFF (4 Gbps). In multitechnology devices, this
       value is the greatest rate among all supported technologies.
  */

  /*  Note: Below data item is deprecated from QMI DMS version 1.11 in favor of device_service_capability TLV */
  dms_data_service_capability_enum_v01 data_service_capability;
  /**<   Values: \n
      - DMS_DATA_CAP_NONE (0x00) --  No data services supported \n 
      - DMS_DATA_CAP_CS_ONLY (0x01) --  Only circuit-switched (CS) services
are supported \n 
      - DMS_DATA_CAP_PS_ONLY (0x02) --  Only packet-switched (PS) services
are supported \n 
      - DMS_DATA_CAP_SIMUL_CS_AND_PS (0x03) --  Simultaneous CS and PS \n 
      - DMS_DATA_CAP_NONSIMUL_CS_AND_PS (0x04) --  Nonsimultaneous CS and PS 
 */

  dms_sim_capability_enum_v01 sim_capability;
  /**<   Values: \n
      - DMS_SIM_NOT_SUPPORTED (0x01) --  SIM is not supported \n
      - DMS_SIM_SUPPORTED (0x02) --  SIM is supported 
 */

  uint32_t radio_if_list_len;  /**< Must be set to # of elements in radio_if_list */
  dms_radio_if_enum_v01 radio_if_list[QMI_DMS_RADIO_IF_LIST_MAX_V01];
  /**<   List of N one-byte elements describing the radio interfaces
 supported by the device. Values: \n
      - DMS_RADIO_IF_1X (0x01) --  CDMA2000 1X \n
      - DMS_RADIO_IF_1X_EVDO (0x02) --  CDMA2000 HRPD (1xEV-DO) \n
      - DMS_RADIO_IF_GSM (0x04) --  GSM \n
      - DMS_RADIO_IF_UMTS (0x05) --  UMTS \n 
      - DMS_RADIO_IF_LTE (0x08) --  LTE \n
      - DMS_RADIO_IF_TDS (0x09) --  TDS 
 */
}dms_device_capabilities_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  dms_bind_subscription_enum_v01 subscription;
  /**<   Subscription for which the release information applies Values: \n 
      - DMS_PRIMARY_SUBS (0x0001) --  Primary \n 
      - DMS_SECONDARY_SUBS (0x0002) --  Secondary \n 
      - DMS_TERTIARY_SUBS (0x0003) --  Tertiary  
 */

  dms_device_gsm_rel_info_v01 geran_rel_info;
  /**<   The highest supported release info for the GERAN RAT 
       by the device.
  */

  dms_device_wcdma_rel_info_v01 wcdma_rel_info;
  /**<   The highest supported release info for the WCDMA RAT
       by the device.
  */

  dms_device_lte_rat_rel_info_v01 lte_rel_info;
  /**<   The highest supported release info for the LTE RAT
       by the device.
  */

  dms_device_hdr_rat_rel_info_v01 hdrcp_rel_info;
  /**<   The highest supported release info for the HDR RAT
       by the device.
  */

  dms_device_cdma_1x_rel_info_v01 cdma1x_rel_info;
  /**<   The highest supported release info for the CDMA2000 RAT
       by the device.
  */

  dms_device_tdscdma_rel_info_v01 tdscdma_rel_info;
  /**<   The highest supported release info for the TDSCDMA RAT
       by the device.
  */
}dms_device_rat_rel_info_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Requests the device capabilities. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  Device Capabilities */
  dms_device_capabilities_type_v01 device_capabilities;

  /* Optional */
  /*  Device Service Capability */
  uint8_t device_service_capability_valid;  /**< Must be set to true if device_service_capability is being passed */
  dms_device_service_capability_enum_v01 device_service_capability;
  /**<   Values: \n
      - DMS_DEVICE_CAP_DATA_ONLY (0x01) --  Only data services are supported \n 
      - DMS_DEVICE_CAP_VOICE_ONLY (0x02) --   Only voice services are supported \n
      - DMS_DEVICE_CAP_SIMUL_VOICE_AND_DATA (0x03) --  Simultaneous voice and data \n 
      - DMS_DEVICE_CAP_NONSIMUL_VOICE_AND_DATA (0x04) --  Nonsimultaneous voice and data 
 */

  /* Optional */
  /*  Voice Support Capability */
  uint8_t voice_support_capability_valid;  /**< Must be set to true if voice_support_capability is being passed */
  dms_voice_support_capability_mask_v01 voice_support_capability;
  /**<   Bitmask of voice support available on device. Values: \n
       Bit 0 -- GW CSFB        \n
       - 0 -- Not capable      \n
       - 1 -- Capable          \n
       Bit 1 -- 1x CSFB        \n
       - 0 -- Not capable      \n
       - 1 -- Capable          \n
       Bit 2 -- VoLTE          \n
       - 0 -- Not capable      \n
       - 1 -- Capable          
  */

  /* Optional */
  /*  Simultaneous Voice and Data Capability */
  uint8_t simul_voice_and_data_capability_valid;  /**< Must be set to true if simul_voice_and_data_capability is being passed */
  dms_simul_voice_and_data_capability_mask_v01 simul_voice_and_data_capability;
  /**<   Bitmask of simultaneous voice and data support available on the device. Values: \n
       - Bit 0 -- SVLTE capability \n
       - Bit 1 -- SVDO capability  \n
       - Bit 2 -- SGLTE capability  \n
       Note: Zero bits set means that none of the defined capabilities are supported.
  */

  /* Optional */
  /*  Device Multisim Capability (Deprecated) */
  uint8_t multisim_capability_valid;  /**< Must be set to true if multisim_capability is being passed */
  dms_multisim_capability_type_v01 multisim_capability;
  /**<   \n This TLV is deprecated. Use Device Multisim Voice Data Capability to support
        multiple simultaneously active radio interfaces.
   */

  /* Optional */
  /*  Device Multisim Voice Data Capability */
  uint8_t current_multisim_capability_valid;  /**< Must be set to true if current_multisim_capability is being passed */
  dms_current_multisim_capability_type_v01 current_multisim_capability;
  /**<   \n Device voice and data capability for supporting multiple simultaneously 
        active radio interfaces.
  */

  /* Optional */
  /*  Current Subscription Capability */
  uint8_t current_subscription_capability_valid;  /**< Must be set to true if current_subscription_capability is being passed */
  uint32_t current_subscription_capability_len;  /**< Must be set to # of elements in current_subscription_capability */
  dms_subs_capability_mask_type_v01 current_subscription_capability[QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01];
  /**<   An array of max_subscriptions entries where each entry is a mask of capabilities.
 The client ignores any bits in the mask that it does not recognize. Values: 
      - DMS_SUBS_CAPABILITY_AMPS (0x00000001) --  AMPS 
      - DMS_SUBS_CAPABILITY_CDMA (0x00000002) --  CDMA 
      - DMS_SUBS_CAPABILITY_HDR (0x00000004) --  HDR 
      - DMS_SUBS_CAPABILITY_GSM (0x00000008) --  GSM 
      - DMS_SUBS_CAPABILITY_WCDMA (0x00000010) --  WCDMA 
      - DMS_SUBS_CAPABILITY_LTE (0x00000020) --  LTE 
      - DMS_SUBS_CAPABILITY_TDS (0x00000040) --  TDS  
 */

  /* Optional */
  /*  Subscription Voice Data Capability of the Device */
  uint8_t subs_voice_data_capability_valid;  /**< Must be set to true if subs_voice_data_capability is being passed */
  uint32_t subs_voice_data_capability_len;  /**< Must be set to # of elements in subs_voice_data_capability */
  dms_subs_voice_data_capability_type_v01 subs_voice_data_capability[QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01];
  /**<   \n Voice and data capability of each subscription of the device
  */

  /* Optional */
  /*  Subscription Feature Mode of the Device */
  uint8_t subs_device_feature_mode_valid;  /**< Must be set to true if subs_device_feature_mode is being passed */
  uint32_t subs_device_feature_mode_len;  /**< Must be set to # of elements in subs_device_feature_mode */
  dms_device_subs_feature_mode_enum_v01 subs_device_feature_mode[QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01];
  /**<   Device feature mode of each subscription. Values: \n
      - DMS_DEVICE_SUBS_FEATURE_MODE_NORMAL (0) --  Normal \n 
      - DMS_DEVICE_SUBS_FEATURE_MODE_SGLTE (1) --  SGLTE \n 
      - DMS_DEVICE_SUBS_FEATURE_MODE_SVLTE (2) --  SVLTE \n 
      - DMS_DEVICE_SUBS_FEATURE_MODE_SRLTE (3) --  SRLTE \n 
      - DMS_DEVICE_SUBS_FEATURE_MODE_DUAL_MULTIMODE (4) --  Dual multimode 
 */

  /* Optional */
  /*  Maximum Active Data Subscriptions */
  uint8_t max_active_data_subscriptions_valid;  /**< Must be set to true if max_active_data_subscriptions is being passed */
  uint8_t max_active_data_subscriptions;
  /**<   The maximum number of subscriptions that can be simultaneously active for data activity. 
       If this value is less than max_subscriptions, it implies that any combination 
       of the subscriptions in this configuration can be active and the remaining can be in standby.
  */

  /* Optional */
  /*  Maximum Subscription Capability */
  uint8_t device_max_subscription_static_capability_valid;  /**< Must be set to true if device_max_subscription_static_capability is being passed */
  uint32_t device_max_subscription_static_capability_len;  /**< Must be set to # of elements in device_max_subscription_static_capability */
  dms_subs_capability_mask_type_v01 device_max_subscription_static_capability[QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01];
  /**<   Array of max_subscriptions entries where each entry is a mask of capabilities. 
 This TLV gives the static maximum RAT capability for the device configuration
 supported by hardware per each subscription.
 The client ignores any bits in the mask that it does not recognize. Values: 
      - DMS_SUBS_CAPABILITY_AMPS (0x00000001) --  AMPS 
      - DMS_SUBS_CAPABILITY_CDMA (0x00000002) --  CDMA 
      - DMS_SUBS_CAPABILITY_HDR (0x00000004) --  HDR 
      - DMS_SUBS_CAPABILITY_GSM (0x00000008) --  GSM 
      - DMS_SUBS_CAPABILITY_WCDMA (0x00000010) --  WCDMA 
      - DMS_SUBS_CAPABILITY_LTE (0x00000020) --  LTE 
      - DMS_SUBS_CAPABILITY_TDS (0x00000040) --  TDS  
 */

  /* Optional */
  /*  Maximum Device Configuration List */
  uint8_t device_config_list_valid;  /**< Must be set to true if device_config_list is being passed */
  dms_device_config_capability_type_v01 device_config_list;
  /**<   List of maximum configurations and the current configuration of the device.
  */

  /* Optional */
  /*  Explicit Configuration Index */
  uint8_t explicit_config_index_valid;  /**< Must be set to true if explicit_config_index is being passed */
  int16_t explicit_config_index;
  /**<    Indicates whether the current configuration is modem selected or HLOS specified.
        Values:\n
             - -1 -- Modem controlled configuration \n 
             - Any other valid value -- HLOS selected the static configuration and 
              points to an index in device_cfg_list of the Maximum Device
              Configuration List TLV.

	*/

  /* Optional */
  /*  IMS Capability of the Device */
  uint8_t ims_capability_valid;  /**< Must be set to true if ims_capability is being passed */
  uint32_t ims_capability_len;  /**< Must be set to # of elements in ims_capability */
  dms_ims_capability_type_v01 ims_capability[QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01];

  /* Optional */
  /*  Maximum IMS Instances Supported (Static capability) */
  uint8_t max_ims_instances_valid;  /**< Must be set to true if max_ims_instances is being passed */
  uint8_t max_ims_instances;
  /**<   Maximum instances of IMS supported by the device 
          (static capability)
  */

  /* Optional */
  /*  Highest RAT release Info Supported in device(Static capability) */
  uint8_t rat_rel_info_valid;  /**< Must be set to true if rat_rel_info is being passed */
  uint32_t rat_rel_info_len;  /**< Must be set to # of elements in rat_rel_info */
  dms_device_rat_rel_info_v01 rat_rel_info[QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01];
  /**<   Indicates the highest RAT release information of various RAT supported in the 
       device (static capability)
  */
}dms_get_device_cap_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Requests the device the manufacturer information. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_device_mfr_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Requests the device the manufacturer information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  Device Manufacturer */
  char device_manufacturer[QMI_DMS_DEVICE_MANUFACTURER_MAX_V01 + 1];
  /**<   String identifying the device manufacturer. */
}dms_get_device_mfr_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Requests the device model identification. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_device_model_id_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Requests the device model identification. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  Device Model */
  char device_model_id[QMI_DMS_DEVICE_MODEL_ID_MAX_V01 + 1];
  /**<   String identifying the device model. */
}dms_get_device_model_id_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Requests the device firmware revision identification. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_device_rev_id_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Requests the device firmware revision identification. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  Revision ID   */
  char device_rev_id[QMI_DMS_DEVICE_REV_ID_MAX_V01 + 1];
  /**<   String containing the device revision ID. */

  /* Optional */
  /*  Boot Code Revision */
  uint8_t boot_code_rev_valid;  /**< Must be set to true if boot_code_rev is being passed */
  char boot_code_rev[QMI_DMS_BOOT_CODE_REV_MAX_V01 + 1];
  /**<   String containing the boot code revision.
  */

  /* Optional */
  /*  PRI Revision */
  uint8_t pri_rev_valid;  /**< Must be set to true if pri_rev is being passed */
  char pri_rev[QMI_DMS_PRI_REV_MAX_V01 + 1];
  /**<   String containing the device PRI revision.
  */
}dms_get_device_rev_id_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Requests the assigned voice number. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_msisdn_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Requests the assigned voice number. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  Voice Number */
  char voice_number[QMI_DMS_VOICE_NUMBER_MAX_V01 + 1];
  /**<   String containing the voice number in use by the device. */

  /* Optional */
  /*  Mobile ID */
  uint8_t mobile_id_number_valid;  /**< Must be set to true if mobile_id_number is being passed */
  char mobile_id_number[QMI_DMS_MOBILE_ID_NUMBER_MAX_V01 + 1];
  /**<   String containing the mobile ID number of the device. */

  /* Optional */
  /*  International Mobile Subscriber ID */
  uint8_t imsi_valid;  /**< Must be set to true if imsi is being passed */
  char imsi[QMI_DMS_IMSI_MAX_V01 + 1];
  /**<   String containing the international mobile subscriber ID of the device.
  */
}dms_get_msisdn_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Requests the serial numbers of the device. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_device_serial_numbers_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Requests the serial numbers of the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  ESN */
  uint8_t esn_valid;  /**< Must be set to true if esn is being passed */
  char esn[QMI_DMS_ESN_MAX_V01 + 1];
  /**<   String containing the ESN of the device. */

  /* Optional */
  /*  IMEI */
  uint8_t imei_valid;  /**< Must be set to true if imei is being passed */
  char imei[QMI_DMS_IMEI_MAX_V01 + 1];
  /**<   String containing the IMEI of the device.
  */

  /* Optional */
  /*  MEID */
  uint8_t meid_valid;  /**< Must be set to true if meid is being passed */
  char meid[QMI_DMS_MEID_MAX_V01 + 1];
  /**<   String containing the MEID of the device. */

  /* Optional */
  /*  IMEI SVN */
  uint8_t imeisv_svn_valid;  /**< Must be set to true if imeisv_svn is being passed */
  char imeisv_svn[QMI_DMS_IMEISV_MAX_V01 + 1];
  /**<   IMEI software version number
  */
}dms_get_device_serial_numbers_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Requests the encrypted serial numbers of the device. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_encrypted_device_serial_numbers_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Requests the encrypted serial numbers of the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  ESN */
  uint8_t esn_valid;  /**< Must be set to true if esn is being passed */
  uint32_t esn_len;  /**< Must be set to # of elements in esn */
  uint8_t esn[QMI_DMS_ENCRYPTED_ESN_MAX_V01];
  /**<   Encrypted ESN of the device. */

  /* Optional */
  /*  IMEI */
  uint8_t imei_valid;  /**< Must be set to true if imei is being passed */
  uint32_t imei_len;  /**< Must be set to # of elements in imei */
  uint8_t imei[QMI_DMS_ENCRYPTED_IMEI_MAX_V01];
  /**<   Encrypted IMEI of the device.
  */

  /* Optional */
  /*  MEID */
  uint8_t meid_valid;  /**< Must be set to true if meid is being passed */
  uint32_t meid_len;  /**< Must be set to # of elements in meid */
  uint8_t meid[QMI_DMS_ENCRYPTED_MEID_MAX_V01];
  /**<   Encrypted MEID of the device. */

  /* Optional */
  /*  IMEI SVN */
  uint8_t imeisv_svn_valid;  /**< Must be set to true if imeisv_svn is being passed */
  uint32_t imeisv_svn_len;  /**< Must be set to # of elements in imeisv_svn */
  uint8_t imeisv_svn[QMI_DMS_ENCRYPTED_IMEISV_MAX_V01];
  /**<   Encrypted IMEI software version number.
  */
}dms_get_encrypted_device_serial_numbers_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Requests the power status of the device. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_power_state_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Requests the power status of the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  Power State */
  dms_power_state_type_v01 power_state;
}dms_get_power_state_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_PIN_ID_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_QMI_PIN_ID_PIN_1_V01 = 0x01, /**<  PIN1 (also called PIN) \n  */
  DMS_QMI_PIN_ID_PIN_2_V01 = 0x02, /**<  PIN2  */
  DMS_PIN_ID_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_pin_id_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  dms_pin_id_enum_v01 pin_id;
  /**<   Specifies the ID of the PIN to be enabled or disabled. Values: \n
      - DMS_QMI_PIN_ID_PIN_1 (0x01) --  PIN1 (also called PIN) \n 
      - DMS_QMI_PIN_ID_PIN_2 (0x02) --  PIN2 
 */

  uint8_t protection_setting_enabled;
  /**<   Specifies whether the PIN is enabled. Values: \n 
     - 0 -- Disable PIN \n
     - 1 -- Enable PIN
  */

  uint32_t pin_value_len;  /**< Must be set to # of elements in pin_value */
  uint8_t pin_value[QMI_DMS_PIN_VALUE_MAX_V01];
  /**<   Specifies the PIN value of the PIN to be enabled/disabled. The
       protection setting is only changed if the SIM
       successfully verifies this value.
  */
}dms_pin_protection_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Enables or disables protection of UIM contents by a
           specified PIN. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  PIN Protection Information */
  dms_pin_protection_info_type_v01 pin_protection_info;
}dms_uim_set_pin_protection_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t verify_retries_left;
  /**<   Number of retries left, after which the PIN is blocked. */

  uint8_t unblock_retries_left;
  /**<   Number of unblock retries left, after which the PIN is
       permanently blocked and the UIM is unusable.
  */
}dms_pin_retries_status_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Enables or disables protection of UIM contents by a
           specified PIN. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Pin Retries Status */
  uint8_t pin_retries_status_valid;  /**< Must be set to true if pin_retries_status is being passed */
  dms_pin_retries_status_type_v01 pin_retries_status;
}dms_uim_set_pin_protection_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  dms_pin_id_enum_v01 pin_id;
  /**<   Specifies the ID of the PIN to be enabled or disabled. Values: \n
      - DMS_QMI_PIN_ID_PIN_1 (0x01) --  PIN1 (also called PIN) \n 
      - DMS_QMI_PIN_ID_PIN_2 (0x02) --  PIN2 
 */

  uint32_t pin_value_len;  /**< Must be set to # of elements in pin_value */
  uint8_t pin_value[QMI_DMS_PIN_VALUE_MAX_V01];
  /**<   Specifies the PIN value of the PIN to be verified; the
       protection setting is only changed if this value is
       successfully verified by the SIM.
  */
}dms_pin_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Verifies the PIN before accessing the UIM contents. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  PIN Value */
  dms_pin_info_type_v01 pin_info;
}dms_uim_verify_pin_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Verifies the PIN before accessing the UIM contents. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  PIN Retries Status */
  uint8_t pin_retries_status_valid;  /**< Must be set to true if pin_retries_status is being passed */
  dms_pin_retries_status_type_v01 pin_retries_status;
}dms_uim_verify_pin_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  dms_pin_id_enum_v01 unblock_pin_id;
  /**<   Specifies the ID of the PIN to be unblocked. Values: \n
      - DMS_QMI_PIN_ID_PIN_1 (0x01) --  PIN1 (also called PIN) \n 
      - DMS_QMI_PIN_ID_PIN_2 (0x02) --  PIN2 
 */

  uint32_t puk_value_len;  /**< Must be set to # of elements in puk_value */
  uint8_t puk_value[QMI_DMS_PUK_VALUE_MAX_V01];
  /**<   Specifies the PUK value (password) of the PIN to be unblocked. */

  uint32_t new_pin_value_len;  /**< Must be set to # of elements in new_pin_value */
  uint8_t new_pin_value[QMI_DMS_PUK_VALUE_MAX_V01];
  /**<   Specifies the new PIN value (password) for the PIN to be unblocked. */
}dms_pin_unblock_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Unblocks a blocked PIN. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  PIN Unblock Information */
  dms_pin_unblock_info_type_v01 pin_unblock_info;
}dms_uim_unblock_pin_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Unblocks a blocked PIN. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  PIN Retries Status */
  uint8_t pin_retries_status_valid;  /**< Must be set to true if pin_retries_status is being passed */
  dms_pin_retries_status_type_v01 pin_retries_status;
}dms_uim_unblock_pin_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  dms_pin_id_enum_v01 pin_id;
  /**<   Specifies the ID of the PIN to be changed. Values: \n
      - DMS_QMI_PIN_ID_PIN_1 (0x01) --  PIN1 (also called PIN) \n 
      - DMS_QMI_PIN_ID_PIN_2 (0x02) --  PIN2 
 */

  uint32_t old_pin_value_len;  /**< Must be set to # of elements in old_pin_value */
  uint8_t old_pin_value[QMI_DMS_PIN_VALUE_MAX_V01];
  /**<   Specifies the old PIN value (old password) of the PIN. */

  uint32_t new_pin_value_len;  /**< Must be set to # of elements in new_pin_value */
  uint8_t new_pin_value[QMI_DMS_PIN_VALUE_MAX_V01];
  /**<   Specifies the new PIN value (new password) of the PIN. */
}dms_pin_change_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Changes the PIN value. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  PIN Change Information */
  dms_pin_change_info_type_v01 pin_change_info;
}dms_uim_change_pin_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Changes the PIN value. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  PIN Retries Status */
  uint8_t pin_retries_status_valid;  /**< Must be set to true if pin_retries_status is being passed */
  dms_pin_retries_status_type_v01 pin_retries_status;
}dms_uim_change_pin_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Gets the status of a PIN. (Deprecated) */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_uim_get_pin_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Gets the status of a PIN. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  PIN 1 Status */
  uint8_t pin1_status_valid;  /**< Must be set to true if pin1_status is being passed */
  dms_pin_status_type_v01 pin1_status;

  /* Optional */
  /*  PIN 2 Status */
  uint8_t pin2_status_valid;  /**< Must be set to true if pin2_status is being passed */
  dms_pin_status_type_v01 pin2_status;
}dms_uim_get_pin_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Queries the hardware revision of the device. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_device_hardware_rev_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Queries the hardware revision of the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  Hardware Revision */
  char hardware_rev[QMI_DMS_HARDWARE_REV_MAX_V01 + 1];
  /**<   String containing the hardware revision of the device. */
}dms_get_device_hardware_rev_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Queries the current operating mode of the device. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_operating_mode_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Queries the current operating mode of the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  Operating Mode */
  dms_operating_mode_enum_v01 operating_mode;
  /**<   Selected operating mode. Values: \n
      - DMS_OP_MODE_ONLINE (0x00) --  Online \n
      - DMS_OP_MODE_LOW_POWER (0x01) --  Low power \n  
      - DMS_OP_MODE_FACTORY_TEST_MODE (0x02) --  Factory Test mode \n 
      - DMS_OP_MODE_OFFLINE (0x03) --  Offline \n 
      - DMS_OP_MODE_RESETTING (0x04) --  Resetting \n 
      - DMS_OP_MODE_SHUTTING_DOWN (0x05) --  Shutting down \n 
      - DMS_OP_MODE_PERSISTENT_LOW_POWER (0x06) --  Persistent low power \n 
      - DMS_OP_MODE_MODE_ONLY_LOW_POWER (0x07) --  Mode-only low power \n 
      - DMS_OP_MODE_NET_TEST_GW (0x08) --  Conducting network test for GSM/WCDMA 
 */

  /* Optional */
  /*  Offline Reason */
  uint8_t offline_reason_valid;  /**< Must be set to true if offline_reason is being passed */
  dms_offline_reason_mask_v01 offline_reason;
  /**<   Offline reason bitmask. All unlisted bits are reserved for 
       future use and are ignored. Values: \n
       - 0x0001 -- Host image misconfiguration \n
       - 0x0002 -- PRI image misconfiguration \n
       - 0x0004 -- PRI version incompatible \n
       - 0x0008 -- Device memory is full, cannot copy PRI information
       
  */

  /* Optional */
  /*  Hardware-Restricted Mode */
  uint8_t hardware_controlled_mode_valid;  /**< Must be set to true if hardware_controlled_mode is being passed */
  uint8_t hardware_controlled_mode;
  /**<   Hardware-Restricted mode. Values: \n
       - 0x01 -- TRUE 
  */
}dms_get_operating_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Sets the operating mode of the device. */
typedef struct {

  /* Mandatory */
  /*  Operating Mode */
  dms_operating_mode_enum_v01 operating_mode;
  /**<   Selected operating mode. Values: \n
      - DMS_OP_MODE_ONLINE (0x00) --  Online \n
      - DMS_OP_MODE_LOW_POWER (0x01) --  Low power \n  
      - DMS_OP_MODE_FACTORY_TEST_MODE (0x02) --  Factory Test mode \n 
      - DMS_OP_MODE_OFFLINE (0x03) --  Offline \n 
      - DMS_OP_MODE_RESETTING (0x04) --  Resetting \n 
      - DMS_OP_MODE_SHUTTING_DOWN (0x05) --  Shutting down \n 
      - DMS_OP_MODE_PERSISTENT_LOW_POWER (0x06) --  Persistent low power \n 
      - DMS_OP_MODE_MODE_ONLY_LOW_POWER (0x07) --  Mode-only low power \n 
      - DMS_OP_MODE_NET_TEST_GW (0x08) --  Conducting network test for GSM/WCDMA 
 */
}dms_set_operating_mode_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Sets the operating mode of the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_set_operating_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Queries the current time of the device. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_time_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_TIME_SOURCE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_TIME_SOURCE_DEVICE_CLOCK_V01 = 0x00, /**<  32 kHz device clock \n  */
  DMS_TIME_SOURCE_CDMA_V01 = 0x01, /**<  CDMA network \n  */
  DMS_TIME_SOURCE_HDR_V01 = 0x02, /**<  HDR network  */
  DMS_TIME_SOURCE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_time_source_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t time_count[6];
  /**<   Count of 1.25 ms that have elapsed from the start of GPS Epoch 
       time (January 6, 1980). A 6-byte integer in little-endian format.
  */

  dms_time_source_enum_v01 time_source;
  /**<   Source of the timestamp. Values: \n 
      - DMS_TIME_SOURCE_DEVICE_CLOCK (0x00) --  32 kHz device clock \n 
      - DMS_TIME_SOURCE_CDMA (0x01) --  CDMA network \n 
      - DMS_TIME_SOURCE_HDR (0x02) --  HDR network 
 */
}dms_device_time_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Queries the current time of the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  Device Time */
  dms_device_time_type_v01 device_time;

  /* Optional */
  /*  System Time in Milliseconds */
  uint8_t sys_time_in_ms_valid;  /**< Must be set to true if sys_time_in_ms is being passed */
  uint64_t sys_time_in_ms;
  /**<   Count of system time in milliseconds that have
       elapsed from the start of GPS Epoch time
       (Jan 6, 1980).
  */

  /* Optional */
  /*  User Time in Milliseconds */
  uint8_t user_time_in_ms_valid;  /**< Must be set to true if user_time_in_ms is being passed */
  uint64_t user_time_in_ms;
  /**<   Count of user time in milliseconds that have
       elapsed from the start of GPS Epoch time
       (Jan 6, 1980).
  */
}dms_get_time_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Queries the version of the active Preferred Roaming
           List (PRL) of the device. (Deprecated) */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_prl_ver_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Queries the version of the active Preferred Roaming
           List (PRL) of the device. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  PRL Version */
  uint16_t prl_version;
  /**<   PRL version.*/

  /* Optional */
  /*  PRL-Only Preference */
  uint8_t prl_only_valid;  /**< Must be set to true if prl_only is being passed */
  uint8_t prl_only;
  /**<   Values: \n
       - 0 -- Unset \n
       - 1 -- Set
  */
}dms_get_prl_ver_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Queries the activation state of the device. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_activation_state_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Queries the activation state of the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  Activation State */
  dms_activation_state_enum_v01 activation_state;
  /**<   Service activation state. Values: \n
      - DMS_ACTIVATION_NOT_ACTIVATED (0x00) --  Service is not activated \n
      - DMS_ACTIVATION_ACTIVATED (0x01) --  Service is activated \n
      - DMS_ACTIVATION_CONNECTING (0x02) --  Activation connecting -- Network
                connection is in progress for automatic activation of service \n 
      - DMS_ACTIVATION_CONNECTED (0x03) -- 
      - DMS_ACTIVATION_OTASP_SEC_AUTHENTICATED (0x4) --  OTASP security is authenticated \n 
      - DMS_ACTIVATION_OTASP_NAM_DOWNLOADED (0x05) --  OTASP NAM is downloaded \n 
      - DMS_ACTIVATION_OTASP_MDN_DOWNLOADED (0x06) --  OTASP MDN is downloaded  \n 
      - DMS_ACTIVATION_OTASP_IMSI_DOWNLOADED (0x07) --  OTASP IMSI downloaded \n 
      - DMS_ACTIVATION_OTASP_PRL_DOWNLOADED (0x08) --  OTASP PRL is downloaded \n 
      - DMS_ACTIVATION_OTASP_SPC_DOWNLOADED (0x09) --  OTASP SPC is downloaded \n 
      - DMS_ACTIVATION_OTASP_SETTINGS_COMMITTED (0x0A) --  OTASP settings are committed  
 */
}dms_get_activation_state_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  char act_code[QMI_DMS_ACTIVATION_CODE_MAX_V01 + 1];
  /**<   Activation code to be used by the default activation type
       for the device in ASCII format (maximum 81 bytes).
  */
}dms_activation_code_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Requests that the device perform automatic
           service activation. */
typedef struct {

  /* Mandatory */
  /*  Activation Code */
  dms_activation_code_type_v01 activation_code;
}dms_activate_automatic_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Requests that the device perform automatic
           service activation. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_activate_automatic_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  char spc[QMI_DMS_SPC_LEN_V01];
  /**<   Service programming code in ASCII format (digits 0 to 9 only).
  */

  uint16_t sid;
  /**<   System identification number
  */

  char mdn[QMI_DMS_MDN_MAX_V01 + 1];
  /**<   String containing the mobile directory number (maximum 15 bytes).
  */

  char min[QMI_DMS_MIN_MAX_V01 + 1];
  /**<   String containing the mobile identification number (maximum 15 bytes).
  */
}dms_manual_act_data_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  char mn_ha_key[QMI_DMS_HA_KEY_MAX_V01 + 1];
  /**<   String containing the MN-HA key (maximum 16 bytes).*/
}dms_mn_ha_key_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  char mn_aaa_key[QMI_DMS_AAA_KEY_MAX_V01 + 1];
  /**<   String containing the MN-AAA key (maximum 16 bytes).*/
}dms_mn_aaa_key_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t prl_total_len;
  /**<    PRL total length (maximum 16384)*/

  uint8_t prl_seg_num;
  /**<   PRL segment sequence number*/

  uint32_t prl_len;  /**< Must be set to # of elements in prl */
  uint8_t prl[QMI_DMS_PRL_DATA_MAX_V01];
  /**<   PRL segment data*/
}dms_pref_roaming_list_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Requests that the device perform manual service activation. */
typedef struct {

  /* Mandatory */
  /*  Manual Activation Data */
  dms_manual_act_data_type_v01 activation_data;

  /* Optional */
  /*  MN-HA Key */
  uint8_t mn_ha_key_valid;  /**< Must be set to true if mn_ha_key is being passed */
  dms_mn_ha_key_type_v01 mn_ha_key;

  /* Optional */
  /*  MN-AAA Key */
  uint8_t mn_aaa_key_valid;  /**< Must be set to true if mn_aaa_key is being passed */
  dms_mn_aaa_key_type_v01 mn_aaa_key;

  /* Optional */
  /*  Preferred Roaming List */
  uint8_t pref_roaming_list_valid;  /**< Must be set to true if pref_roaming_list is being passed */
  dms_pref_roaming_list_type_v01 pref_roaming_list;
}dms_activate_manual_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Requests that the device perform manual service activation. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_activate_manual_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Queries the state of the user lock maintained by the
           device. (Deprecated) */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_user_lock_state_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Queries the state of the user lock maintained by the
           device. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  User Lock State */
  uint8_t lock_enabled;
  /**<   Current state of the lock. Values: \n
       - 0 -- Disabled \n
       - 1 -- Enabled
  */
}dms_get_user_lock_state_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_LOCK_STATE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_LOCK_DISABLED_V01 = 0x00, /**<  Disabled \n  */
  DMS_LOCK_ENABLED_V01 = 0x01, /**<  Enabled  */
  DMS_LOCK_STATE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_lock_state_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  dms_lock_state_enum_v01 lock_state;
  /**<   Current state of the lock. Values: \n
      - DMS_LOCK_DISABLED (0x00) --  Disabled \n 
      - DMS_LOCK_ENABLED (0x01) --  Enabled 
 */

  char lock_code[QMI_DMS_LOCK_CODE_LEN_V01];
  /**<   4-byte code set for the lock in ASCII format (digits 0 to 9 only). */
}dms_user_lock_state_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Sets the user lock state maintained by the device. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  User Lock State */
  dms_user_lock_state_info_type_v01 lock_info;
}dms_set_user_lock_state_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Sets the user lock state maintained by the device. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_set_user_lock_state_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  char cur_code[QMI_DMS_LOCK_CODE_LEN_V01];
  /**<   Current 4-byte code to use for the lock in ASCII format (digits 0 to
       9 only).
  */

  char new_code[QMI_DMS_LOCK_CODE_LEN_V01];
  /**<   New 4-byte code to use for the lock in ASCII format (digits 0 to
       9 only).
  */
}dms_user_lock_set_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Sets the user lock code maintained by the device. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  User Lock Code */
  dms_user_lock_set_info_type_v01 lock_info;
}dms_set_user_lock_code_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Sets the user lock code maintained by the device. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_set_user_lock_code_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Queries the user data maintained by the device. (Deprecated) */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_read_user_data_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t data_len;  /**< Must be set to # of elements in data */
  uint8_t data[QMI_DMS_USER_DATA_MAX_V01];
  /**<   User data from/to persistent storage (maximum 512).*/
}dms_user_data_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Queries the user data maintained by the device. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  User Data */
  dms_user_data_type_v01 user_data;
}dms_read_user_data_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Writes user data maintained by the device. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  User Data */
  dms_user_data_type_v01 user_data;
}dms_write_user_data_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Writes user data maintained by the device. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_write_user_data_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Queries the Extended Roaming Indicator (ERI) file stored on the device. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_read_eri_file_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t eri_data_len;  /**< Must be set to # of elements in eri_data */
  uint8_t eri_data[QMI_DMS_ERI_DATA_MAX_V01];
  /**<   ERI data read from persistent storage (maximum 1024).*/
}dms_eri_data_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Queries the Extended Roaming Indicator (ERI) file stored on the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  ERI File */
  dms_eri_data_type_v01 eri_file;
}dms_read_eri_file_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Requests that the device reset all settings to
           factory defined values. */
typedef struct {

  /* Mandatory */
  /*  Service Programming Code */
  char spc[QMI_DMS_SPC_LEN_V01];
  /**<   Service programming code in ASCII format (digits 0 to 9 only).
  */
}dms_restore_factory_defaults_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Requests that the device reset all settings to
           factory defined values. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_restore_factory_defaults_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Requests the device to validate a specified service
           programming code. */
typedef struct {

  /* Mandatory */
  /*  Programming Code */
  char spc[QMI_DMS_SPC_LEN_V01];
  /**<   Service programming code in ASCII format (digits 0 to 9 only). */
}dms_validate_service_programming_code_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Requests the device to validate a specified service
           programming code. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_validate_service_programming_code_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Queries the Integrated Circuit Card ID (ICCID) of the UIM for the device. (Deprecated) */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_uim_get_iccid_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Queries the Integrated Circuit Card ID (ICCID) of the UIM for the device. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  UIM ICCID */
  char uim_id[QMI_DMS_UIM_ID_MAX_V01 + 1];
  /**<   String containing the UIM ICCID. */
}dms_uim_get_iccid_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_GSM_PERSO_FACILITY_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_PERSO_FACILITY_NETWORK_V01 = 0x00, /**<  Network personalization (PN) \n  */
  DMS_PERSO_FACILITY_NETWORK_SUBSET_V01 = 0x01, /**<  Network subset personalization (PU) \n  */
  DMS_PERSO_FACILITY_SERVICE_PROVIDER_V01 = 0x02, /**<  Service provider personalization (PP) \n  */
  DMS_PERSO_FACILITY_CORPORATE_V01 = 0x03, /**<  Corporate personalization (PC)\n  */
  DMS_PERSO_FACILITY_UIM_V01 = 0x04, /**<  UIM personalization (PF)  */
  DMS_GSM_PERSO_FACILITY_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_gsm_perso_facility_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Queries the status of a UIM facility control key. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  UIM Personalization Facility */
  dms_gsm_perso_facility_enum_v01 facility;
  /**<   MT or network facility (corresponding AT+CLCK value). Values: \n
      - DMS_PERSO_FACILITY_NETWORK (0x00) --  Network personalization (PN) \n 
      - DMS_PERSO_FACILITY_NETWORK_SUBSET (0x01) --  Network subset personalization (PU) \n 
      - DMS_PERSO_FACILITY_SERVICE_PROVIDER (0x02) --  Service provider personalization (PP) \n 
      - DMS_PERSO_FACILITY_CORPORATE (0x03) --  Corporate personalization (PC)\n 
      - DMS_PERSO_FACILITY_UIM (0x04) --  UIM personalization (PF) 
 */
}dms_uim_get_ck_status_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_FACILITY_STATE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_FACILITY_DEACTIVATED_V01 = 0x00, /**<  Deactivated \n */
  DMS_FACILITY_ACTIVATED_V01 = 0x01, /**<  Activated \n  */
  DMS_FACILITY_BLOCKED_V01 = 0x02, /**<  Blocked  */
  DMS_FACILITY_STATE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_facility_state_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  dms_facility_state_enum_v01 facility_state;
  /**<   UIM facility state. Values: \n
      - DMS_FACILITY_DEACTIVATED (0x00) --  Deactivated \n
      - DMS_FACILITY_ACTIVATED (0x01) --  Activated \n 
      - DMS_FACILITY_BLOCKED (0x02) --  Blocked 
 */

  uint8_t verify_reties_left;
  /**<   Indicates the number of retries left, after which the CK is blocked. */

  uint8_t unblock_retries_left;
  /**<   Number of unblock retries left, after which the CK is permanently blocked.
   */
}dms_facility_state_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Queries the status of a UIM facility control key. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  Facility CK Status */
  dms_facility_state_info_type_v01 facility_info;

  /* Optional */
  /*  Operation Blocking Facility */
  uint8_t operation_blocking_valid;  /**< Must be set to true if operation_blocking is being passed */
  uint8_t operation_blocking;
  /**<   Presence of this TLV indicates that this facility is 
       blocking normal operation of the device. This value can be
       returned only if the facility_state is not 0 (deactivated).

       Note: This value is set to 1 when the TLV is provided.
  */
}dms_uim_get_ck_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  dms_gsm_perso_facility_enum_v01 facility;
  /**<   UIM Personalization facility (corresponding AT+CLCK value). Values: \n
      - DMS_PERSO_FACILITY_NETWORK (0x00) --  Network personalization (PN) \n 
      - DMS_PERSO_FACILITY_NETWORK_SUBSET (0x01) --  Network subset personalization (PU) \n 
      - DMS_PERSO_FACILITY_SERVICE_PROVIDER (0x02) --  Service provider personalization (PP) \n 
      - DMS_PERSO_FACILITY_CORPORATE (0x03) --  Corporate personalization (PC)\n 
      - DMS_PERSO_FACILITY_UIM (0x04) --  UIM personalization (PF) 
 */

  dms_facility_state_enum_v01 facility_state;
  /**<   UIM facility state. Values: \n
      - DMS_FACILITY_DEACTIVATED (0x00) --  Deactivated \n
      - DMS_FACILITY_ACTIVATED (0x01) --  Activated \n 
      - DMS_FACILITY_BLOCKED (0x02) --  Blocked 
 */

  char facility_ck[QMI_DMS_FACILITY_CK_MAX_V01 + 1];
  /**<   Facility depersonalization control key string in ASCII text
       (maximum 8 bytes).
   */
}dms_facility_set_ck_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Sets the protection of a UIM facility control key. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  UIM Personalization Facility */
  dms_facility_set_ck_info_type_v01 facility_set_ck_info;
}dms_uim_set_ck_protection_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Sets the protection of a UIM facility control key. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Facility CK Retry Status */
  uint8_t verify_retries_left_valid;  /**< Must be set to true if verify_retries_left is being passed */
  uint8_t verify_retries_left;
  /**<   Number of retries left, after which the CK is blocked.
   */
}dms_uim_set_ck_protection_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  dms_gsm_perso_facility_enum_v01 facility;
  /**<   UIM personalization facility (corresponding AT+CLCK value). Values:\n
      - DMS_PERSO_FACILITY_NETWORK (0x00) --  Network personalization (PN) \n 
      - DMS_PERSO_FACILITY_NETWORK_SUBSET (0x01) --  Network subset personalization (PU) \n 
      - DMS_PERSO_FACILITY_SERVICE_PROVIDER (0x02) --  Service provider personalization (PP) \n 
      - DMS_PERSO_FACILITY_CORPORATE (0x03) --  Corporate personalization (PC)\n 
      - DMS_PERSO_FACILITY_UIM (0x04) --  UIM personalization (PF) 
 */

  char facility_unblock_ck[QMI_DMS_FACILITY_UNBLOCK_CK_MAX_V01 + 1];
  /**<   Facility control key string in ASCII text (maximum 8 bytes). */
}dms_facility_unblock_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Unblocks a UIM facility control key. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  UIM Personalization Facility */
  dms_facility_unblock_info_type_v01 facility_unblock_info;
}dms_uim_unblock_ck_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Unblocks a UIM facility control key. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Facility CK Retry Status */
  uint8_t unblock_retries_left_valid;  /**< Must be set to true if unblock_retries_left is being passed */
  uint8_t unblock_retries_left;
  /**<   Number of unblock retries left, after which the CK is
       permanently blocked.
   */
}dms_uim_unblock_ck_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Queries the International Mobile Station Identity (IMSI) 
           of the UIM for the device. (Deprecated) */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_uim_get_imsi_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Queries the International Mobile Station Identity (IMSI) 
           of the UIM for the device. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  International Mobile Subscriber ID */
  char imsi[QMI_DMS_IMSI_MAX_V01 + 1];
  /**<   String containing the international mobile subscriber ID. */
}dms_uim_get_imsi_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Queries the state of the UIM. (Deprecated) */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_uim_get_state_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Queries the state of the UIM. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  UIM State */
  dms_uim_state_enum_v01 uim_state;
  /**<   UIM state. Values: \n
      - DMS_UIM_INITIALIZATION_COMPLETED (0x00) --  UIM initialization has completed \n 
      - DMS_UIM_INITIALIZATION_FAILED (0x01) --  UIM has failed \n
      - DMS_UIM_NOT_PRESENT (0x02) --  UIM is not present \n 
      - DMS_UIM_STATE_UNAVAILABLE (-1) --  UIM state is unavailable 
 */
}dms_uim_get_state_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Queries the band capability of the device. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_band_capability_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Queries the band capability of the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  Band Capability */
  dms_band_capability_mask_v01 band_capability;
  /**<   Bitmask of bands supported by the device; see Appendix  
       \ref{app:BandCapability} for the definition of these 
       values.
  */

  /* Optional */
  /*  LTE Band Capability (Deprecated) */
  uint8_t lte_band_capability_valid;  /**< Must be set to true if lte_band_capability is being passed */
  dms_lte_band_capability_mask_v01 lte_band_capability;
  /**<   This TLV is deprecated; instead use the Supported LTE Bands TLV. 
       This TLV is present on devices that support LTE bands.
       Bitmask of LTE bands supported by the device; see Appendix  
       \ref{app:LTEBandCapability} for the definition of these 
       values. 
  */

  /* Optional */
  /*  TDS Band Capability */
  uint8_t tds_band_capability_valid;  /**< Must be set to true if tds_band_capability is being passed */
  dms_tds_band_capability_mask_v01 tds_band_capability;
  /**<   This TLV is present on devices that support TDS bands.
       Bitmask of TDS bands supported by the device.        
       Values: \n
       - Bit 0 -- TDS Band A 1900 to 1920 MHz, 2010 to 2020 MHz \n
       - Bit 1 -- TDS Band B 1850 to 1910 MHz, 1930 to 1990 MHz \n
       - Bit 2 -- TDS Band C 1910 to 1930 MHz \n
       - Bit 3 -- TDS Band D 2570 to 2620 MHz \n
       - Bit 4 -- TDS Band E 2300 to 2400 MHz \n
       - Bit 5 -- TDS Band F 1880 to 1920 MHz
  */

  /* Optional */
  /*  Supported LTE Bands */
  uint8_t supported_lte_bands_valid;  /**< Must be set to true if supported_lte_bands is being passed */
  uint32_t supported_lte_bands_len;  /**< Must be set to # of elements in supported_lte_bands */
  uint16_t supported_lte_bands[QMI_DMS_MAX_SUPPORTED_LTE_BANDS_V01];
  /**<   Array of supported LTE bands where each entry is a 
       decimal representation of the LTE band number supported. 
  */
}dms_get_band_capability_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Queries the factory provisioned Stock Keeping
           Unit (SKU). */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_factory_sku_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Queries the factory provisioned Stock Keeping
           Unit (SKU). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  Factory SKU */
  char factory_serial_number[QMI_DMS_FACTORY_SN_MAX_V01 + 1];
  /**<   Factory serial number string in ASCII format (maximum 128 bytes).
  */
}dms_get_factory_sku_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_TIME_REF_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_TIME_REF_TYPE_USER_V01 = 0x00000000, /**<  User time  */
  DMS_TIME_REF_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_time_ref_type_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Sets the time on the device. */
typedef struct {

  /* Mandatory */
  /*  Time */
  uint64_t time_in_ms;
  /**<   Count of time in milliseconds that have elapsed
         from the start of GPS Epoch time (Jan 6, 1980).
   */

  /* Optional */
  /*  Time Reference Type */
  uint8_t time_reference_type_valid;  /**< Must be set to true if time_reference_type is being passed */
  dms_time_ref_type_enum_v01 time_reference_type;
  /**<   Time reference used while setting the time. Values: \n
      - DMS_TIME_REF_TYPE_USER (0x00000000) --  User time  \n
 - 0x00000001 to 0xFFFFFFFF -- Reserved for
 future extension
 */
}dms_set_time_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Sets the time on the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}dms_set_time_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Queries the alternative network interface configuration 
           used for the device. (Deprecated) */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_alt_net_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Queries the alternative network interface configuration 
           used for the device. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  Alternative Net Configuration */
  uint8_t alt_net_config;
  /**<   Alternative network interface configuration. If not provisioned, the 
       Disabled setting is used by the device as default. Values: \n
       - 0 -- Disabled \n
       - 1 -- Enabled 
    */
}dms_get_alt_net_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Sets the alternative network interface configuration
           used for the device. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Alternative Net Configuration */
  uint8_t alt_net_config;
  /**<   Alternative network interface configuration. Values: \n
       - 0 -- Disabled \n
       - 1 -- Enabled 
  */
}dms_set_alt_net_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Sets the alternative network interface configuration
           used for the device. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_set_alt_net_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_IMAGE_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_IMAGE_UNKNOWN_V01 = 0, /**<  Unknown \n  */
  DMS_IMAGE_SBL_V01 = 1, /**<  SBL \n  */
  DMS_IMAGE_TZ_V01 = 2, /**<  TZ \n  */
  DMS_IMAGE_TZSECAPP_V01 = 3, /**<  TZSECAPP \n  */
  DMS_IMAGE_RPM_V01 = 4, /**<  RPM \n  */
  DMS_IMAGE_SDI_V01 = 5, /**<  SDI \n  */
  DMS_IMAGE_HYPERVISOR_V01 = 6, /**<  Hypervisor \n  */
  DMS_IMAGE_APPSBL_V01 = 7, /**<  APPSBL \n  */
  DMS_IMAGE_APPS_V01 = 8, /**<  Applications \n  */
  DMS_IMAGE_MPSS_V01 = 9, /**<  MPSS \n  */
  DMS_IMAGE_ADSP_V01 = 10, /**<  ADSP \n  */
  DMS_IMAGE_WCNS_V01 = 11, /**<  WCNS \n  */
  DMS_IMAGE_VENUS_V01 = 12, /**<  Venus  */
  DMS_IMAGE_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_image_type_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  dms_image_type_enum_v01 image_type;
  /**<   Image type. Values: \n
      - DMS_IMAGE_UNKNOWN (0) --  Unknown \n 
      - DMS_IMAGE_SBL (1) --  SBL \n 
      - DMS_IMAGE_TZ (2) --  TZ \n 
      - DMS_IMAGE_TZSECAPP (3) --  TZSECAPP \n 
      - DMS_IMAGE_RPM (4) --  RPM \n 
      - DMS_IMAGE_SDI (5) --  SDI \n 
      - DMS_IMAGE_HYPERVISOR (6) --  Hypervisor \n 
      - DMS_IMAGE_APPSBL (7) --  APPSBL \n 
      - DMS_IMAGE_APPS (8) --  Applications \n 
      - DMS_IMAGE_MPSS (9) --  MPSS \n 
      - DMS_IMAGE_ADSP (10) --  ADSP \n 
      - DMS_IMAGE_WCNS (11) --  WCNS \n 
      - DMS_IMAGE_VENUS (12) --  Venus 
 */

  char image_ver[QMI_DMS_IMAGE_VER_LEN_MAX_V01 + 1];
  /**<   Image version string. The format of the string is 
       [QC version]:[Variant]:[OEM version]
  */
}dms_image_ver_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Queries the software version from the device. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_sw_version_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Queries the software version from the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  Software Version Information */
  char sw_version[QMI_DMS_SW_VERSION_MAX_V01 + 1];
  /**<   String representing the software version information.
  */

  /* Optional */
  /*  Image Versions */
  uint8_t image_versions_valid;  /**< Must be set to true if image_versions is being passed */
  uint32_t image_versions_len;  /**< Must be set to # of elements in image_versions */
  dms_image_ver_type_v01 image_versions[QMI_DMS_IMAGE_VER_MAX_V01];
  /**<   \n Image versions of the builds loaded on the device.
  */

  /* Optional */
  /*  Extended Software Version Information */
  uint8_t sw_version_ext_valid;  /**< Must be set to true if sw_version_ext is being passed */
  char sw_version_ext[QMI_DMS_SW_VERSION_MAX_EXT_V01 + 1];
  /**<   String representing the software version information.
  */
}dms_get_sw_version_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Changes the service programming code of the device
           after authentication. */
typedef struct {

  /* Mandatory */
  /*  Current SPC */
  char curr_spc[QMI_DMS_SPC_LEN_V01];
  /**<   SPC for authentication in ASCII format (digits 0 to 9 only).
  */

  /* Mandatory */
  /*  New SPC */
  char new_spc[QMI_DMS_SPC_LEN_V01];
  /**<   New SPC in ASCII format (digits 0 to 9 only).
  */
}dms_set_spc_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Changes the service programming code of the device
           after authentication. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_set_spc_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Queries the active PRL information of the device. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_current_prl_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Queries the active PRL information of the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  PRL Version */
  uint8_t prl_version_valid;  /**< Must be set to true if prl_version is being passed */
  uint16_t prl_version;
  /**<   PRL version */

  /* Optional */
  /*  PRL Only Preference */
  uint8_t prl_only_valid;  /**< Must be set to true if prl_only is being passed */
  uint8_t prl_only;
  /**<   Values: \n
       - 0 -- Unset \n
       - 1 -- Set
  */

  /* Optional */
  /*  PRL Source */
  uint8_t prl_source_valid;  /**< Must be set to true if prl_source is being passed */
  dms_prl_source_enum_v01 prl_source;
  /**<   Values: \n
      - DMS_PRL_SOURCE_INFO_UNDETERMINED (0) --  PRL is not loaded \n
      - DMS_PRL_SOURCE_INFO_DEFAULT (1) --  PRL source is the default PRL \n 
      - DMS_PRL_SOURCE_INFO_NV (2) --  PRL source is the nonvolatile memory \n
      - DMS_PRL_SOURCE_INFO_CARD (3) --  PRL source is the card 
 */
}dms_get_current_prl_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Associates the requesting control point with the requested subscription. */
typedef struct {

  /* Mandatory */
  /*  Bind Subscription */
  dms_bind_subscription_enum_v01 bind_subs;
  /**<   Subscription to which to bind. Values: \n
      - DMS_PRIMARY_SUBS (0x0001) --  Primary \n 
      - DMS_SECONDARY_SUBS (0x0002) --  Secondary \n 
      - DMS_TERTIARY_SUBS (0x0003) --  Tertiary  
 */
}dms_bind_subscription_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Associates the requesting control point with the requested subscription. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_bind_subscription_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Queries the subscription associated with the control point. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_bind_subscription_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Queries the subscription associated with the control point. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Bound Subscription */
  uint8_t bind_subscription_valid;  /**< Must be set to true if bind_subscription is being passed */
  dms_bind_subscription_enum_v01 bind_subscription;
  /**<   Values: \n
      - DMS_PRIMARY_SUBS (0x0001) --  Primary \n 
      - DMS_SECONDARY_SUBS (0x0002) --  Secondary \n 
      - DMS_TERTIARY_SUBS (0x0003) --  Tertiary  
 */
}dms_get_bind_subscription_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Sets the AP software version on the modem required for an
           Auto Register Short message. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  AP Software Version */
  char ap_sw_version[QMI_DMS_SW_VERSION_MAX_V01 + 1];
  /**<   String representing the AP software version information. 
  */
}dms_set_ap_sw_version_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Sets the AP software version on the modem required for an
           Auto Register Short message. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_set_ap_sw_version_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Requests the CDMA Lock mode status. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_cdma_lock_mode_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Requests the CDMA Lock mode status. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  CDMA Lock Mode */
  uint8_t cdma_lock_mode_status_valid;  /**< Must be set to true if cdma_lock_mode_status is being passed */
  dms_cdma_lock_mode_state_enum_v01 cdma_lock_mode_status;
  /**<   CDMA Lock mode status. Values: \n
      - DMS_CDMA_LOCK_MODE_OFF (0) --  Phone is not CDMA locked \n 
      - DMS_CDMA_LOCK_MODE_ON (1) --  Phone is CDMA locked  
 */
}dms_get_cdma_lock_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_TEST_CONFIG_TDS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_TEST_CONFIG_TDS_PRODUCTION_V01 = 0, /**<  Use the configuration applicable in production 
                                       (in the field) \n  */
  DMS_TEST_CONFIG_TDS_LAB_V01 = 1, /**<  Use the configuration applicable in the 
                                  lab \n  */
  DMS_TEST_CONFIG_TDS_USER_V01 = 2, /**<  Use the user-defined configuration   */
  DMS_TEST_CONFIG_TDS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_test_config_tds_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Sets the configuration type used while testing. */
typedef struct {

  /* Optional */
  /*  TDS CDMA Configuration */
  uint8_t tds_config_valid;  /**< Must be set to true if tds_config is being passed */
  dms_test_config_tds_enum_v01 tds_config;
  /**<   Configuration parameters to be used for TDS CDMA. Values: \n
      - DMS_TEST_CONFIG_TDS_PRODUCTION (0) --  Use the configuration applicable in production 
                                       (in the field) \n 
      - DMS_TEST_CONFIG_TDS_LAB (1) --  Use the configuration applicable in the 
                                  lab \n 
      - DMS_TEST_CONFIG_TDS_USER (2) --  Use the user-defined configuration  
 */
}dms_set_test_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Sets the configuration type used while testing. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_set_test_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Retrieves the configuration type used for testing. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_test_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Retrieves the configuration type used for testing. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Active TDS CDMA Configuration */
  uint8_t active_tds_config_valid;  /**< Must be set to true if active_tds_config is being passed */
  dms_test_config_tds_enum_v01 active_tds_config;
  /**<   Configuration parameters used for TDS CDMA. Values: \n
      - DMS_TEST_CONFIG_TDS_PRODUCTION (0) --  Use the configuration applicable in production 
                                       (in the field) \n 
      - DMS_TEST_CONFIG_TDS_LAB (1) --  Use the configuration applicable in the 
                                  lab \n 
      - DMS_TEST_CONFIG_TDS_USER (2) --  Use the user-defined configuration  
 */

  /* Optional */
  /*  Desired TDS CDMA Configuration */
  uint8_t desired_tds_config_valid;  /**< Must be set to true if desired_tds_config is being passed */
  dms_test_config_tds_enum_v01 desired_tds_config;
  /**<   Configuration parameters for TDS CDMA that were set using the last 
 QMI_DMS_SET_TEST_CONFIG command. Values: \n
      - DMS_TEST_CONFIG_TDS_PRODUCTION (0) --  Use the configuration applicable in production 
                                       (in the field) \n 
      - DMS_TEST_CONFIG_TDS_LAB (1) --  Use the configuration applicable in the 
                                  lab \n 
      - DMS_TEST_CONFIG_TDS_USER (2) --  Use the user-defined configuration  
 */
}dms_get_test_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Resets the modem configuration to production values. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_clear_test_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Resets the modem configuration to production values. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_clear_test_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_OEM_CHINA_OPERATOR_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_OPERATOR_CT_V01 = 0, /**<  CT \n  */
  DMS_OPERATOR_CU_V01 = 1, /**<  CU \n  */
  DMS_OPERATOR_CMCC_V01 = 2, /**<  CMCC   */
  DMS_OEM_CHINA_OPERATOR_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_oem_china_operator_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Retrieves the China production configuration values. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_oem_china_operator_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Retrieves the China production configuration values. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Operator Information */
  uint8_t operator_info_valid;  /**< Must be set to true if operator_info is being passed */
  dms_oem_china_operator_enum_v01 operator_info;
  /**<   Mobile operator to be used. Values: \n
      - DMS_OPERATOR_CT (0) --  CT \n 
      - DMS_OPERATOR_CU (1) --  CU \n 
      - DMS_OPERATOR_CMCC (2) --  CMCC  
 */
}dms_oem_china_operator_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_DEVICE_MAC_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_DEVICE_MAC_WLAN_V01 = 0, /**<  WLAN device \n  */
  DMS_DEVICE_MAC_BT_V01 = 1, /**<  Bluetooth\reg device  */
  DMS_DEVICE_MAC_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_device_mac_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Retrieves the default MAC address. */
typedef struct {

  /* Mandatory */
  /*  Device Information */
  dms_device_mac_enum_v01 device;
  /**<   Device for which the MAC address is retrieved. Values: \n
      - DMS_DEVICE_MAC_WLAN (0) --  WLAN device \n 
      - DMS_DEVICE_MAC_BT (1) --  Bluetooth\reg device  
 */
}dms_get_mac_address_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Retrieves the default MAC address. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Device MAC Address */
  uint8_t mac_address_valid;  /**< Must be set to true if mac_address is being passed */
  uint32_t mac_address_len;  /**< Must be set to # of elements in mac_address */
  uint8_t mac_address[QMI_DMS_MAC_ADDR_MAX_V01];
  /**<   Device MAC address. */
}dms_get_mac_address_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Triggers the modem activity information calculation. */
typedef struct {

  /* Optional */
  /*  Device Information */
  uint8_t enable_statistics_valid;  /**< Must be set to true if enable_statistics is being passed */
  uint8_t enable_statistics;
  /**<   Values: \n
       - 0 -- Disable modem activity statistics calculation \n
       - 1 -- Enable modem activity statistics calculation    
  */
}dms_config_modem_activity_info_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Triggers the modem activity information calculation. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_config_modem_activity_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Queries for the modem activity statistics. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_modem_activity_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Queries for the modem activity statistics. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_get_modem_activity_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_TX_MODE_LEVEL_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_TX_MODE_LEVEL_ONE_V01 = 0, /**<  Level 1 */
  DMS_TX_MODE_LEVEL_TWO_V01 = 1, /**<  Level 2 */
  DMS_TX_MODE_LEVEL_THREE_V01 = 2, /**<  Level 3  */
  DMS_TX_MODE_LEVEL_FOUR_V01 = 3, /**<  Level 4  */
  DMS_TX_MODE_LEVEL_FIVE_V01 = 4, /**<  Level 5  */
  DMS_TX_MODE_LEVEL_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_tx_mode_level_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_aggregates
    @{
  */
typedef struct {

  dms_tx_mode_level_enum_v01 tx_mode_level;
  /**<   Power levels used by the modem in
 Tx (Transmitter) mode. Values: 
      - DMS_TX_MODE_LEVEL_ONE (0) --  Level 1
      - DMS_TX_MODE_LEVEL_TWO (1) --  Level 2
      - DMS_TX_MODE_LEVEL_THREE (2) --  Level 3 
      - DMS_TX_MODE_LEVEL_FOUR (3) --  Level 4 
      - DMS_TX_MODE_LEVEL_FIVE (4) --  Level 5  */

  uint32_t tx_mode_duration;
  /**<   Duration that the modem was active on Tx mode 
       (Transmitter mode) (in milliseconds).
  */
}tx_mode_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Indication Message; Indicates the modem activity information statistics. */
typedef struct {

  /* Optional */
  /*  Idle Mode Duration */
  uint8_t idle_mode_duration_valid;  /**< Must be set to true if idle_mode_duration is being passed */
  uint32_t idle_mode_duration;
  /**<   Duration that the modem was awake but the traffic channel
       was released (in milliseconds).
  */

  /* Optional */
  /*  Sleep Mode Duration */
  uint8_t sleep_mode_duration_valid;  /**< Must be set to true if sleep_mode_duration is being passed */
  uint32_t sleep_mode_duration;
  /**<   Duration that the modem was in power collapse (in milliseconds).
  */

  /* Optional */
  /*  Rx Mode Duration */
  uint8_t rx_mode_duration_valid;  /**< Must be set to true if rx_mode_duration is being passed */
  uint32_t rx_mode_duration;
  /**<   Duration that the modem was active on Rx mode (Receiver mode
       from the network to the modem) (in milliseconds).
  */

  /* Optional */
  /*  Tx Mode Duration */
  uint8_t tx_mode_duration_valid;  /**< Must be set to true if tx_mode_duration is being passed */
  uint32_t tx_mode_duration_len;  /**< Must be set to # of elements in tx_mode_duration */
  tx_mode_type_v01 tx_mode_duration[QMI_DMS_TX_MODEM_LEVEL_MAX_V01];
  /**<   \n Duration that the modem was active on Tx mode (Transmitter mode
       from the modem to the network) for each level (in milliseconds).
  */

  /* Optional */
  /*  Is Newly Calculated Values */
  uint8_t is_newly_calculated_values_valid;  /**< Must be set to true if is_newly_calculated_values is being passed */
  uint8_t is_newly_calculated_values;
  /**<    This notifies the TE whether the current set of activity information
        is the newly calculated information or the values 
        computed previously following a
        QMI_DMS_GET_MODEM_ACTIVITY_ INFO_REQ request */
}dms_activity_info_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Queries the Power Save Mode (PSM) configuration parameters. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_psm_get_cfg_params_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Queries the Power Save Mode (PSM) configuration parameters. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Power Save Mode Enable State  */
  uint8_t psm_enabled_valid;  /**< Must be set to true if psm_enabled is being passed */
  uint8_t psm_enabled;
  /**<   Values: \n
       - 0 -- PSM is not enabled \n
       - 1 -- PSM is enabled
  */

  /* Optional */
  /*  Duration Threshold */
  uint8_t duration_threshold_valid;  /**< Must be set to true if duration_threshold is being passed */
  uint32_t duration_threshold;
  /**<   Minimum duration for the device to benefit by entering PSM (in seconds).
  */

  /* Optional */
  /*  Duration Due to OOS */
  uint8_t duration_due_to_oos_valid;  /**< Must be set to true if duration_due_to_oos is being passed */
  uint32_t duration_due_to_oos;
  /**<   Power Save Mode duration due to an outage (in seconds). 
  */

  /* Optional */
  /*  Randomization Window */
  uint8_t randomization_window_valid;  /**< Must be set to true if randomization_window is being passed */
  uint32_t randomization_window;
  /**<   Power Save Mode wakeup randomization window (in seconds). 
  */

  /* Optional */
  /*  Active Timer */
  uint8_t active_timer_valid;  /**< Must be set to true if active_timer is being passed */
  uint32_t active_timer;
  /**<   Power Save Mode active timer value (in seconds). 
  */

  /* Optional */
  /*  Periodic Update Timer */
  uint8_t periodic_update_timer_valid;  /**< Must be set to true if periodic_update_timer is being passed */
  uint32_t periodic_update_timer;
  /**<   Power Save Mode periodic update timer value (in seconds). 
  */

  /* Optional */
  /*  Early Wakeup Time */
  uint8_t early_wakeup_time_valid;  /**< Must be set to true if early_wakeup_time is being passed */
  uint32_t early_wakeup_time;
  /**<   Power Save Mode early wakeup time (in seconds) indicating
       how early the device should exit PSM to offset for bootup and 
       acquisition delay.
  */
}dms_psm_get_cfg_params_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Requests to enter Power Save Mode (PSM). */
typedef struct {

  /* Optional */
  /*  Duration in PSM */
  uint8_t duration_in_psm_valid;  /**< Must be set to true if duration_in_psm is being passed */
  uint32_t duration_in_psm;
  /**<   Duration to stay in PSM (in seconds).
  */
}dms_psm_enter_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Requests to enter Power Save Mode (PSM). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_psm_enter_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_PSM_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_PSM_STATUS_COMPLETED_V01 = 0, /**<  Entering into PSM is complete.  */
  DMS_PSM_STATUS_REJECTED_V01 = 1, /**<  Entering PSM is rejected.  */
  DMS_PSM_STATUS_READY_V01 = 2, /**<  Modem is ready to enter PSM.   */
  DMS_PSM_STATUS_OOS_V01 = 3, /**<  UE is unable to acquire service, even after a few full scans.  */
  DMS_PSM_STATUS_LIMITED_SERVICE_V01 = 4, /**<  UE has acquired limited service but not full service.  */
  DMS_PSM_STATUS_AUTO_READY_V01 = 5, /**<  Modem is autonomously ready to enter into PSM.  */
  DMS_PSM_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_psm_status_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_enums
    @{
  */
typedef enum {
  DMS_PSM_REJECT_REASON_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DMS_PSM_REJECT_REASON_NO_ERROR_V01 = 0, /**<  No error.  */
  DMS_PSM_REJECT_REASON_NOT_ENABLED_V01 = 1, /**<  PSM is not enabled.  */
  DMS_PSM_REJECT_REASON_MODEM_NOT_READY_V01 = 2, /**<  Modem is not in a ready state; for example, an MT call is in progress.  */
  DMS_PSM_REJECT_REASON_DURATION_TOO_SHORT_V01 = 3, /**<  Duration set by the control point is less than the PSM threshold.  */
  DMS_PSM_REJECT_REASON_PSM_DURATION_CHANGED_V01 = 4, /**<  Duration set by the control point is greater than the PSM timer duration 
       on the modem; the control point can retry with a shorter duration.
   */
  DMS_PSM_REJECT_REASON_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dms_psm_reject_reason_enum_v01;
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Indication Message; Indicates PSM status. */
typedef struct {

  /* Mandatory */
  /*  PSM Status */
  dms_psm_status_enum_v01 psm_status;
  /**<   PSM status. Values: \n
      - DMS_PSM_STATUS_COMPLETED (0) --  Entering into PSM is complete. 
      - DMS_PSM_STATUS_REJECTED (1) --  Entering PSM is rejected. 
      - DMS_PSM_STATUS_READY (2) --  Modem is ready to enter PSM.  
      - DMS_PSM_STATUS_OOS (3) --  UE is unable to acquire service, even after a few full scans. 
      - DMS_PSM_STATUS_LIMITED_SERVICE (4) --  UE has acquired limited service but not full service. 
      - DMS_PSM_STATUS_AUTO_READY (5) --  Modem is autonomously ready to enter into PSM. 
 */

  /* Optional */
  /*  PSM Reject Reason */
  uint8_t reject_reason_valid;  /**< Must be set to true if reject_reason is being passed */
  dms_psm_reject_reason_enum_v01 reject_reason;
  /**<   PSM reject status. Values: \n
      - DMS_PSM_REJECT_REASON_NO_ERROR (0) --  No error. 
      - DMS_PSM_REJECT_REASON_NOT_ENABLED (1) --  PSM is not enabled. 
      - DMS_PSM_REJECT_REASON_MODEM_NOT_READY (2) --  Modem is not in a ready state; for example, an MT call is in progress. 
      - DMS_PSM_REJECT_REASON_DURATION_TOO_SHORT (3) --  Duration set by the control point is less than the PSM threshold. 
      - DMS_PSM_REJECT_REASON_PSM_DURATION_CHANGED (4) --  Duration set by the control point is greater than the PSM timer duration 
       on the modem; the control point can retry with a shorter duration.
  
 */

  /* Optional */
  /*  Periodic Update Timer */
  uint8_t periodic_update_timer_valid;  /**< Must be set to true if periodic_update_timer is being passed */
  uint32_t periodic_update_timer;
  /**<   PSM periodic update timer value (in seconds). 
  */
}dms_psm_status_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Queries for the UI status information of the application processor at the modem. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}dms_get_ui_status_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Queries for the UI status information of the application processor at the modem. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  UI Status */
  uint8_t ui_ready_status_valid;  /**< Must be set to true if ui_ready_status is being passed */
  uint8_t ui_ready_status;
  /**<   UI status of the application processor at the modem. \n
        Values: \n
          - 0 -- UI is not ready \n
          - 1 -- UI is ready
    */
}dms_get_ui_status_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Sets the UI status information of the application processor at the modem. */
typedef struct {

  /* Optional */
  /*  UI Status */
  uint8_t ui_ready_status_valid;  /**< Must be set to true if ui_ready_status is being passed */
  uint8_t ui_ready_status;
  /**<   UI status of the application processor at the modem. \n
        Values: \n
          - 0 -- UI is not ready \n
          - 1 -- UI is ready
    */
}dms_set_ui_status_info_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Sets the UI status information of the application processor at the modem. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_set_ui_status_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Sets the device configuration out of device capabilities. */
typedef struct {

  /* Optional */
  /*  Explicit Configuration Index */
  uint8_t explicit_config_index_valid;  /**< Must be set to true if explicit_config_index is being passed */
  int16_t explicit_config_index;
  /**<   Specifies the configuration index on which the modem should act.
        Values:\n
             - -1 -- Modem controlled configuration \n 
             - Any other valid value -- HLOS selects the static configuration and points to an 
               index in device_cfg_list in the Maximum Device Configuration List TLV of
			   the QMI_DMS_GET_DEVICE_CAP_RESP response or QMI_DMS_SET_EVENT_REPORT_IND 
			   indication, whichever was last sent to the control point.			   
            */
}dms_set_device_cap_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Sets the device configuration out of device capabilities. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_set_device_cap_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Sets PSM (Power Save Mode) configuration parameters */
typedef struct {

  /* Optional */
  /*  PSM Enable State  */
  uint8_t psm_enabled_valid;  /**< Must be set to true if psm_enabled is being passed */
  uint8_t psm_enabled;
  /**<   Values: \n
       - 0 -- PSM is not enabled \n
       - 1 -- PSM is enabled
  */

  /* Optional */
  /*  Active Timer */
  uint8_t active_timer_valid;  /**< Must be set to true if active_timer is being passed */
  uint32_t active_timer;
  /**<   PSM active timer value (in seconds).
  */

  /* Optional */
  /*  Periodic Update Timer */
  uint8_t periodic_update_timer_valid;  /**< Must be set to true if periodic_update_timer is being passed */
  uint32_t periodic_update_timer;
  /**<   PSM periodic update timer value (in seconds). 
  */
}dms_psm_set_cfg_params_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Sets PSM (Power Save Mode) configuration parameters */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_psm_set_cfg_params_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Indication Message; Indicates PSM status. */
typedef struct {

  /* Optional */
  /*  PSM Enable State  */
  uint8_t psm_enabled_valid;  /**< Must be set to true if psm_enabled is being passed */
  uint8_t psm_enabled;
  /**<   Values: \n
       - 0 -- PSM is not enabled \n
       - 1 -- PSM is enabled
  */

  /* Optional */
  /*  Active Timer */
  uint8_t active_timer_valid;  /**< Must be set to true if active_timer is being passed */
  uint32_t active_timer;
  /**<   PSM active timer value (in seconds). 
  */

  /* Optional */
  /*  Periodic Update Timer */
  uint8_t periodic_update_timer_valid;  /**< Must be set to true if periodic_update_timer is being passed */
  uint32_t periodic_update_timer;
  /**<   PSM periodic update timer value (in seconds). 
  */
}dms_psm_cfg_params_change_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Indication Message; Indicates the IMS capability of the device. */
typedef struct {

  /* Mandatory */
  /*  IMS Capability of the Device */
  uint32_t ims_capability_len;  /**< Must be set to # of elements in ims_capability */
  dms_ims_capability_type_v01 ims_capability[QMI_DMS_MAX_SUBSCRIPTION_LIST_LEN_V01];
}dms_ims_capability_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Request Message; Sets the AP version information on the modem required for an
           Auto Register Short message. */
typedef struct {

  /* Optional */
  /*  AP Operating System Version */
  uint8_t ap_os_version_valid;  /**< Must be set to true if ap_os_version is being passed */
  char ap_os_version[QMI_DMS_AP_OS_VERSION_MAX_V01 + 1];
  /**<   String representing the AP operating system version information. 
  */

  /* Optional */
  /*  AP Software Version */
  uint8_t ap_sw_version_valid;  /**< Must be set to true if ap_sw_version is being passed */
  char ap_sw_version[QMI_DMS_AP_SW_VERSION_MAX_V01 + 1];
  /**<   String representing the AP software version information. 
  */
}dms_set_ap_version_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup dms_qmi_messages
    @{
  */
/** Response Message; Sets the AP version information on the modem required for an
           Auto Register Short message. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}dms_set_ap_version_resp_msg_v01;  /* Message */
/**
    @}
  */

/* Conditional compilation tags for message removal */ 
//#define REMOVE_QMI_DMS_ACTIVATE_AUTOMATIC_V01 
//#define REMOVE_QMI_DMS_ACTIVATE_MANUAL_V01 
//#define REMOVE_QMI_DMS_BIND_SUBSCRIPTION_V01 
//#define REMOVE_QMI_DMS_CLEAR_TEST_CONFIG_V01 
//#define REMOVE_QMI_DMS_GET_ACTIVATION_STATE_V01 
//#define REMOVE_QMI_DMS_GET_ALT_NET_CONFIG_V01 
//#define REMOVE_QMI_DMS_GET_BAND_CAPABILITY_V01 
//#define REMOVE_QMI_DMS_GET_BIND_SUBSCRIPTION_V01 
//#define REMOVE_QMI_DMS_GET_CDMA_LOCK_MODE_V01 
//#define REMOVE_QMI_DMS_GET_CURRENT_PRL_INFO_V01 
//#define REMOVE_QMI_DMS_GET_DEVICE_CAP_V01 
//#define REMOVE_QMI_DMS_GET_DEVICE_HARDWARE_REV_V01 
//#define REMOVE_QMI_DMS_GET_DEVICE_MFR_V01 
//#define REMOVE_QMI_DMS_GET_DEVICE_MODEL_ID_V01 
//#define REMOVE_QMI_DMS_GET_DEVICE_REV_ID_V01 
//#define REMOVE_QMI_DMS_GET_DEVICE_SERIAL_NUMBERS_V01 
//#define REMOVE_QMI_DMS_GET_ENCRYPTED_DEVICE_SERIAL_NUMBERS_V01 
//#define REMOVE_QMI_DMS_GET_FACTORY_SKU_V01 
//#define REMOVE_QMI_DMS_GET_MAC_ADDRESS_V01 
//#define REMOVE_QMI_DMS_GET_MODEM_ACTIVITY_INFO_V01 
//#define REMOVE_QMI_DMS_GET_MSISDN_V01 
//#define REMOVE_QMI_DMS_GET_OPERATING_MODE_V01 
//#define REMOVE_QMI_DMS_GET_POWER_STATE_V01 
//#define REMOVE_QMI_DMS_GET_PRL_VER_V01 
//#define REMOVE_QMI_DMS_GET_SUPPORTED_FIELDS_V01 
//#define REMOVE_QMI_DMS_GET_SUPPORTED_MSGS_V01 
//#define REMOVE_QMI_DMS_GET_SW_VERSION_V01 
//#define REMOVE_QMI_DMS_GET_TEST_CONFIG_V01 
//#define REMOVE_QMI_DMS_GET_TIME_V01 
//#define REMOVE_QMI_DMS_GET_UI_STATUS_INFO_V01 
//#define REMOVE_QMI_DMS_GET_USER_LOCK_STATE_V01 
//#define REMOVE_QMI_DMS_IMS_CAPABILITY_IND_V01 
//#define REMOVE_QMI_DMS_INDICATION_REGISTER_V01 
//#define REMOVE_QMI_DMS_MODEM_ACTIVITY_INFO_IND_V01 
//#define REMOVE_QMI_DMS_OEM_CHINA_OPERATOR_V01 
//#define REMOVE_QMI_DMS_PSM_CFG_PARAMS_CHANGE_IND_V01 
//#define REMOVE_QMI_DMS_PSM_ENTER_V01 
//#define REMOVE_QMI_DMS_PSM_GET_CFG_PARAMS_V01 
//#define REMOVE_QMI_DMS_PSM_SET_CFG_PARAMS_V01 
//#define REMOVE_QMI_DMS_PSM_STATUS_IND_V01 
//#define REMOVE_QMI_DMS_READ_ERI_FILE_V01 
//#define REMOVE_QMI_DMS_READ_USER_DATA_V01 
//#define REMOVE_QMI_DMS_RESET_V01 
//#define REMOVE_QMI_DMS_RESTORE_FACTORY_DEFAULTS_V01 
//#define REMOVE_QMI_DMS_SET_ALT_NET_CONFIG_V01 
//#define REMOVE_QMI_DMS_SET_AP_SW_VERSION_V01 
//#define REMOVE_QMI_DMS_SET_AP_VERSION_V01 
//#define REMOVE_QMI_DMS_SET_DEVICE_CAP_CONFIG_V01 
//#define REMOVE_QMI_DMS_SET_EVENT_REPORT_V01 
//#define REMOVE_QMI_DMS_SET_OPERATING_MODE_V01 
//#define REMOVE_QMI_DMS_SET_SPC_V01 
//#define REMOVE_QMI_DMS_SET_TEST_CONFIG_V01 
//#define REMOVE_QMI_DMS_SET_TIME_V01 
//#define REMOVE_QMI_DMS_SET_UI_STATUS_INFO_V01 
//#define REMOVE_QMI_DMS_SET_USER_LOCK_CODE_V01 
//#define REMOVE_QMI_DMS_SET_USER_LOCK_STATE_V01 
//#define REMOVE_QMI_DMS_TRIGGER_MODEM_ACTIVITY_INFO_CALCULATION_V01 
//#define REMOVE_QMI_DMS_UIM_CHANGE_PIN_V01 
//#define REMOVE_QMI_DMS_UIM_GET_CK_STATUS_V01 
//#define REMOVE_QMI_DMS_UIM_GET_ICCID_V01 
//#define REMOVE_QMI_DMS_UIM_GET_IMSI_V01 
//#define REMOVE_QMI_DMS_UIM_GET_PIN_STATUS_V01 
//#define REMOVE_QMI_DMS_UIM_GET_STATE_V01 
//#define REMOVE_QMI_DMS_UIM_SET_CK_PROTECTION_V01 
//#define REMOVE_QMI_DMS_UIM_SET_PIN_PROTECTION_V01 
//#define REMOVE_QMI_DMS_UIM_UNBLOCK_CK_V01 
//#define REMOVE_QMI_DMS_UIM_UNBLOCK_PIN_V01 
//#define REMOVE_QMI_DMS_UIM_VERIFY_PIN_V01 
//#define REMOVE_QMI_DMS_VALIDATE_SERVICE_PROGRAMMING_CODE_V01 
//#define REMOVE_QMI_DMS_WRITE_USER_DATA_V01 

/*Service Message Definition*/
/** @addtogroup dms_qmi_msg_ids
    @{
  */
#define QMI_DMS_RESET_REQ_V01 0x0000
#define QMI_DMS_RESET_RESP_V01 0x0000
#define QMI_DMS_SET_EVENT_REPORT_REQ_V01 0x0001
#define QMI_DMS_SET_EVENT_REPORT_RESP_V01 0x0001
#define QMI_DMS_EVENT_REPORT_IND_V01 0x0001
#define QMI_DMS_INDICATION_REGISTER_REQ_V01 0x0003
#define QMI_DMS_INDICATION_REGISTER_RESP_V01 0x0003
#define QMI_DMS_GET_SUPPORTED_MSGS_REQ_V01 0x001E
#define QMI_DMS_GET_SUPPORTED_MSGS_RESP_V01 0x001E
#define QMI_DMS_GET_SUPPORTED_FIELDS_REQ_V01 0x001F
#define QMI_DMS_GET_SUPPORTED_FIELDS_RESP_V01 0x001F
#define QMI_DMS_GET_DEVICE_CAP_REQ_V01 0x0020
#define QMI_DMS_GET_DEVICE_CAP_RESP_V01 0x0020
#define QMI_DMS_GET_DEVICE_MFR_REQ_V01 0x0021
#define QMI_DMS_GET_DEVICE_MFR_RESP_V01 0x0021
#define QMI_DMS_GET_DEVICE_MODEL_ID_REQ_V01 0x0022
#define QMI_DMS_GET_DEVICE_MODEL_ID_RESP_V01 0x0022
#define QMI_DMS_GET_DEVICE_REV_ID_REQ_V01 0x0023
#define QMI_DMS_GET_DEVICE_REV_ID_RESP_V01 0x0023
#define QMI_DMS_GET_MSISDN_REQ_V01 0x0024
#define QMI_DMS_GET_MSISDN_RESP_V01 0x0024
#define QMI_DMS_GET_DEVICE_SERIAL_NUMBERS_REQ_V01 0x0025
#define QMI_DMS_GET_DEVICE_SERIAL_NUMBERS_RESP_V01 0x0025
#define QMI_DMS_GET_POWER_STATE_REQ_V01 0x0026
#define QMI_DMS_GET_POWER_STATE_RESP_V01 0x0026
#define QMI_DMS_UIM_SET_PIN_PROTECTION_REQ_V01 0x0027
#define QMI_DMS_UIM_SET_PIN_PROTECTION_RESP_V01 0x0027
#define QMI_DMS_UIM_VERIFY_PIN_REQ_V01 0x0028
#define QMI_DMS_UIM_VERIFY_PIN_RESP_V01 0x0028
#define QMI_DMS_UIM_UNBLOCK_PIN_REQ_V01 0x0029
#define QMI_DMS_UIM_UNBLOCK_PIN_RESP_V01 0x0029
#define QMI_DMS_UIM_CHANGE_PIN_REQ_V01 0x002A
#define QMI_DMS_UIM_CHANGE_PIN_RESP_V01 0x002A
#define QMI_DMS_UIM_GET_PIN_STATUS_REQ_V01 0x002B
#define QMI_DMS_UIM_GET_PIN_STATUS_RESP_V01 0x002B
#define QMI_DMS_GET_DEVICE_HARDWARE_REV_REQ_V01 0x002C
#define QMI_DMS_GET_DEVICE_HARDWARE_REV_RESP_V01 0x002C
#define QMI_DMS_GET_OPERATING_MODE_REQ_V01 0x002D
#define QMI_DMS_GET_OPERATING_MODE_RESP_V01 0x002D
#define QMI_DMS_SET_OPERATING_MODE_REQ_V01 0x002E
#define QMI_DMS_SET_OPERATING_MODE_RESP_V01 0x002E
#define QMI_DMS_GET_TIME_REQ_V01 0x002F
#define QMI_DMS_GET_TIME_RESP_V01 0x002F
#define QMI_DMS_GET_PRL_VER_REQ_V01 0x0030
#define QMI_DMS_GET_PRL_VER_RESP_V01 0x0030
#define QMI_DMS_GET_ACTIVATION_STATE_REQ_V01 0x0031
#define QMI_DMS_GET_ACTIVATION_STATE_RESP_V01 0x0031
#define QMI_DMS_ACTIVATE_AUTOMATIC_REQ_V01 0x0032
#define QMI_DMS_ACTIVATE_AUTOMATIC_RESP_V01 0x0032
#define QMI_DMS_ACTIVATE_MANUAL_REQ_V01 0x0033
#define QMI_DMS_ACTIVATE_MANUAL_RESP_V01 0x0033
#define QMI_DMS_GET_USER_LOCK_STATE_REQ_V01 0x0034
#define QMI_DMS_GET_USER_LOCK_STATE_RESP_V01 0x0034
#define QMI_DMS_SET_USER_LOCK_STATE_REQ_V01 0x0035
#define QMI_DMS_SET_USER_LOCK_STATE_RESP_V01 0x0035
#define QMI_DMS_SET_USER_LOCK_CODE_REQ_V01 0x0036
#define QMI_DMS_SET_USER_LOCK_CODE_RESP_V01 0x0036
#define QMI_DMS_READ_USER_DATA_REQ_V01 0x0037
#define QMI_DMS_READ_USER_DATA_RESP_V01 0x0037
#define QMI_DMS_WRITE_USER_DATA_REQ_V01 0x0038
#define QMI_DMS_WRITE_USER_DATA_RESP_V01 0x0038
#define QMI_DMS_READ_ERI_FILE_REQ_V01 0x0039
#define QMI_DMS_READ_ERI_FILE_RESP_V01 0x0039
#define QMI_DMS_RESTORE_FACTORY_DEFAULTS_REQ_V01 0x003A
#define QMI_DMS_RESTORE_FACTORY_DEFAULTS_RESP_V01 0x003A
#define QMI_DMS_VALIDATE_SERVICE_PROGRAMMING_CODE_REQ_V01 0x003B
#define QMI_DMS_VALIDATE_SERVICE_PROGRAMMING_CODE_RESP_V01 0x003B
#define QMI_DMS_UIM_GET_ICCID_REQ_V01 0x003C
#define QMI_DMS_UIM_GET_ICCID_RESP_V01 0x003C
#define QMI_DMS_UIM_GET_CK_STATUS_REQ_V01 0x0040
#define QMI_DMS_UIM_GET_CK_STATUS_RESP_V01 0x0040
#define QMI_DMS_UIM_SET_CK_PROTECTION_REQ_V01 0x0041
#define QMI_DMS_UIM_SET_CK_PROTECTION_RESP_V01 0x0041
#define QMI_DMS_UIM_UNBLOCK_CK_REQ_V01 0x0042
#define QMI_DMS_UIM_UNBLOCK_CK_RESP_V01 0x0042
#define QMI_DMS_UIM_GET_IMSI_REQ_V01 0x0043
#define QMI_DMS_UIM_GET_IMSI_RESP_V01 0x0043
#define QMI_DMS_UIM_GET_STATE_REQ_V01 0x0044
#define QMI_DMS_UIM_GET_STATE_RESP_V01 0x0044
#define QMI_DMS_GET_BAND_CAPABILITY_REQ_V01 0x0045
#define QMI_DMS_GET_BAND_CAPABILITY_RESP_V01 0x0045
#define QMI_DMS_GET_FACTORY_SKU_REQ_V01 0x0046
#define QMI_DMS_GET_FACTORY_SKU_RESP_V01 0x0046
#define QMI_DMS_SET_TIME_REQ_V01 0x004B
#define QMI_DMS_SET_TIME_RESP_V01 0x004B
#define QMI_DMS_GET_ALT_NET_CONFIG_REQ_V01 0x004D
#define QMI_DMS_GET_ALT_NET_CONFIG_RESP_V01 0x004D
#define QMI_DMS_SET_ALT_NET_CONFIG_REQ_V01 0x004E
#define QMI_DMS_SET_ALT_NET_CONFIG_RESP_V01 0x004E
#define QMI_DMS_GET_SW_VERSION_REQ_V01 0x0051
#define QMI_DMS_GET_SW_VERSION_RESP_V01 0x0051
#define QMI_DMS_SET_SPC_REQ_V01 0x0052
#define QMI_DMS_SET_SPC_RESP_V01 0x0052
#define QMI_DMS_GET_CURRENT_PRL_INFO_REQ_V01 0x0053
#define QMI_DMS_GET_CURRENT_PRL_INFO_RESP_V01 0x0053
#define QMI_DMS_BIND_SUBSCRIPTION_REQ_V01 0x0054
#define QMI_DMS_BIND_SUBSCRIPTION_RESP_V01 0x0054
#define QMI_DMS_GET_BIND_SUBSCRIPTION_REQ_V01 0x0055
#define QMI_DMS_GET_BIND_SUBSCRIPTION_RESP_V01 0x0055
#define QMI_DMS_SET_AP_SW_VERSION_REQ_V01 0x0056
#define QMI_DMS_SET_AP_SW_VERSION_RESP_V01 0x0056
#define QMI_DMS_GET_CDMA_LOCK_MODE_REQ_V01 0x0057
#define QMI_DMS_GET_CDMA_LOCK_MODE_RESP_V01 0x0057
#define QMI_DMS_SET_TEST_CONFIG_REQ_V01 0x0058
#define QMI_DMS_SET_TEST_CONFIG_RESP_V01 0x0058
#define QMI_DMS_GET_TEST_CONFIG_REQ_V01 0x0059
#define QMI_DMS_GET_TEST_CONFIG_RESP_V01 0x0059
#define QMI_DMS_CLEAR_TEST_CONFIG_REQ_V01 0x005A
#define QMI_DMS_CLEAR_TEST_CONFIG_RESP_V01 0x005A
#define QMI_DMS_OEM_CHINA_OPERATOR_REQ_V01 0x005B
#define QMI_DMS_OEM_CHINA_OPERATOR_RESP_V01 0x005B
#define QMI_DMS_GET_MAC_ADDRESS_REQ_V01 0x005C
#define QMI_DMS_GET_MAC_ADDRESS_RESP_V01 0x005C
#define QMI_DMS_GET_ENCRYPTED_DEVICE_SERIAL_NUMBERS_REQ_V01 0x005D
#define QMI_DMS_GET_ENCRYPTED_DEVICE_SERIAL_NUMBERS_RESP_V01 0x005D
#define QMI_DMS_TRIGGER_MODEM_ACTIVITY_INFO_CALCULATION_REQ_V01 0x005E
#define QMI_DMS_TRIGGER_MODEM_ACTIVITY_INFO_CALCULATION_RESP_V01 0x005E
#define QMI_DMS_GET_MODEM_ACTIVITY_INFO_REQ_V01 0x005F
#define QMI_DMS_GET_MODEM_ACTIVITY_INFO_RESP_V01 0x005F
#define QMI_DMS_MODEM_ACTIVITY_INFO_IND_V01 0x005F
#define QMI_DMS_PSM_GET_CFG_PARAMS_REQ_V01 0x0060
#define QMI_DMS_PSM_GET_CFG_PARAMS_RESP_V01 0x0060
#define QMI_DMS_PSM_ENTER_REQ_V01 0x0061
#define QMI_DMS_PSM_ENTER_RESP_V01 0x0061
#define QMI_DMS_PSM_STATUS_IND_V01 0x0062
#define QMI_DMS_GET_UI_STATUS_INFO_REQ_V01 0x0063
#define QMI_DMS_GET_UI_STATUS_INFO_RESP_V01 0x0063
#define QMI_DMS_SET_UI_STATUS_INFO_REQ_V01 0x0064
#define QMI_DMS_SET_UI_STATUS_INFO_RESP_V01 0x0064
#define QMI_DMS_SET_DEVICE_CAP_CONFIG_REQ_V01 0x0065
#define QMI_DMS_SET_DEVICE_CAP_CONFIG_RESP_V01 0x0065
#define QMI_DMS_PSM_SET_CFG_PARAMS_REQ_V01 0x0066
#define QMI_DMS_PSM_SET_CFG_PARAMS_RESP_V01 0x0066
#define QMI_DMS_PSM_CFG_PARAMS_CHANGE_IND_V01 0x0067
#define QMI_DMS_IMS_CAPABILITY_IND_V01 0x0068
#define QMI_DMS_SET_AP_VERSION_REQ_V01 0x0069
#define QMI_DMS_SET_AP_VERSION_RESP_V01 0x0069
/**
    @}
  */

/* Service Object Accessor */
/** @addtogroup wms_qmi_accessor
    @{
  */
/** This function is used internally by the autogenerated code.  Clients should use the
   macro dms_get_service_object_v01( ) that takes in no arguments. */
qmi_idl_service_object_type dms_get_service_object_internal_v01
 ( int32_t idl_maj_version, int32_t idl_min_version, int32_t library_version );

/** This macro should be used to get the service object */
#define dms_get_service_object_v01( ) \
          dms_get_service_object_internal_v01( \
            DMS_V01_IDL_MAJOR_VERS, DMS_V01_IDL_MINOR_VERS, \
            DMS_V01_IDL_TOOL_VERS )
/**
    @}
  */


#ifdef __cplusplus
}
#endif
#endif

