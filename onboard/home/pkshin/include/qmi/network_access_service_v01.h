#ifndef NAS_SERVICE_01_H
#define NAS_SERVICE_01_H
/**
  @file network_access_service_v01.h

  @brief This is the public header file which defines the nas service Data structures.

  This header file defines the types and structures that were defined in
  nas. It contains the constant values defined, enums, structures,
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
  Copyright (c) 2006-2019 Qualcomm Technologies, Inc.
  All rights reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.


  $Header$
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
 *THIS IS AN AUTO GENERATED FILE. DO NOT ALTER IN ANY WAY
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/* This file was generated with Tool version 6.14.7 
   It was generated on: Fri Feb 22 2019 (Spin 0)
   From IDL File: network_access_service_v01.idl */

/** @defgroup nas_qmi_consts Constant values defined in the IDL */
/** @defgroup nas_qmi_msg_ids Constant values for QMI message IDs */
/** @defgroup nas_qmi_enums Enumerated types used in QMI messages */
/** @defgroup nas_qmi_messages Structures sent as QMI messages */
/** @defgroup nas_qmi_aggregates Aggregate types used in QMI messages */
/** @defgroup nas_qmi_accessor Accessor for QMI service object */
/** @defgroup nas_qmi_version Constant values for versioning information */

#include <stdint.h>
#include "qmi_idl_lib.h"
#include "common_v01.h"
#include "network_access_service_common_v01.h"
#include "voice_nas_services_common_v01.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup nas_qmi_version
    @{
  */
/** Major Version Number of the IDL used to generate this file */
#define NAS_V01_IDL_MAJOR_VERS 0x01
/** Revision Number of the IDL used to generate this file */
#define NAS_V01_IDL_MINOR_VERS 0xEC
/** Major Version Number of the qmi_idl_compiler used to generate this file */
#define NAS_V01_IDL_TOOL_VERS 0x06
/** Maximum Defined Message ID */
#define NAS_V01_MAX_MESSAGE_ID 0x00E2
/**
    @}
  */


/** @addtogroup nas_qmi_consts
    @{
  */

/**  Constants used for various array max lengths */
#define NAS_SIG_STRENGTH_LIST_MAX_V01 2
#define NAS_SIG_STRENGTH_THRESHOLD_LIST_MAX_V01 5
#define NAS_ECIO_THRESHOLD_LIST_MAX_V01 10
#define NAS_SINR_THRESHOLD_LIST_MAX_V01 5
#define NAS_SPC_MAX_V01 6
#define NAS_MCC_MNC_MAX_V01 3
#define NAS_RSSI_LIST_MAX_V01 7
#define NAS_ECIO_LIST_MAX_V01 6
#define NAS_ERROR_RATE_LIST_MAX_V01 16
#define NAS_3GPP_NETWORK_INFO_LIST_MAX_V01 40
#define NAS_PCI_SCAN_LIST_MAX_V01 5
#define NAS_PCI_SCAN_MAX_NUM_PLMN_V01 6
#define NAS_3GPP_PREFERRED_NETWORKS_LIST_MAX_V01 85
#define NAS_STATIC_3GPP_PREFERRED_NETWORKS_LIST_MAX_V01 40
#define NAS_3GPP_FORBIDDEN_NETWORKS_LIST_MAX_V01 64
#define NAS_IS_856_MAX_LEN_V01 16
#define NAS_RF_BAND_INFO_LIST_MAX_V01 16
#define NAS_SO_LIST_MAX_V01 32
#define NAS_NETWORK_DESCRIPTION_MAX_V01 255
#define NAS_RADIO_IF_LIST_MAX_V01 255
#define NAS_DATA_CAPABILITIES_LIST_MAX_V01 10
#define NAS_ROAMING_INDICATOR_LIST_MAX_V01 2
#define NAS_ACQ_ORDER_LIST_MAX_V01 10
#define NAS_SERVICE_PROVIDER_NAME_MAX_V01 16
#define NAS_OPERATOR_PLMN_LIST_MAX_V01 255
#define NAS_PLMN_NETWORK_NAME_LIST_MAX_V01 64
#define NAS_LONG_NAME_MAX_V01 255
#define NAS_SHORT_NAME_MAX_V01 255
#define NAS_PLMN_NAME_MAX_V01 255
#define QMI_NAS_UATI_LENGTH_V01 16
#define NAS_CA_BAND_COMBO_MAX_LEN_V01 2304
#define NAS_WCDMA_ARFCN_LIST_MAX_V01 10
#define NAS_LTE_ARFCN_LIST_MAX_V01 10
#define NAS_NR5G_ARFCN_LIST_MAX_V01 10
#define NAS_PREFERRED_PLMN_LIST_MAX_V01 40
#define QMI_NAS_REQUEST_SIG_INFO_RSSI_BIT_V01 0
#define QMI_NAS_REQUEST_SIG_INFO_ECIO_BIT_V01 1
#define QMI_NAS_REQUEST_SIG_INFO_IO_BIT_V01 2
#define QMI_NAS_REQUEST_SIG_INFO_SINR_BIT_V01 3
#define QMI_NAS_REQUEST_SIG_INFO_ERROR_RATE_BIT_V01 4
#define QMI_NAS_REQUEST_SIG_INFO_RSRQ_BIT_V01 5
#define QMI_NAS_RAT_UMTS_BIT_V01 15
#define QMI_NAS_RAT_LTE_BIT_V01 14
#define QMI_NAS_RAT_GSM_BIT_V01 7
#define QMI_NAS_RAT_GSM_COMPACT_BIT_V01 6
#define QMI_NAS_RAT_NOT_AVAILABLE_V01 0
#define QMI_NAS_PROTOCOL_SUBTYPE_2_PHYSICAL_LAYER_BIT_V01 0
#define QMI_NAS_PROTOCOL_SUBTYPE_CCMAC_BIT_V01 1
#define QMI_NAS_PROTOCOL_SUBTYPE_ACMAC_BIT_V01 2
#define QMI_NAS_PROTOCOL_SUBTYPE_FTCMAC_BIT_V01 3
#define QMI_NAS_PROTOCOL_SUBTYPE_3_RTCMAC_BIT_V01 4
#define QMI_NAS_PROTOCOL_SUBTYPE_1_RTCMAC_BIT_V01 5
#define QMI_NAS_PROTOCOL_SUBTYPE_IDLE_BIT_V01 6
#define QMI_NAS_PROTOCOL_SUBTYPE_GEN_MULTI_DISC_PORT_BIT_V01 7
#define QMI_NAS_BROADCAST_SUBTYPE_GENERIC_BIT_V01 0
#define QMI_NAS_APP_SUBTYPE_MULTIFLOW_BIT_V01 0
#define QMI_NAS_APP_SUBTYPE_ENHANCED_MULTIFLOW_BIT_V01 1
#define QMI_NAS_AKEY_LEN_V01 26
#define NAS_MAX_LTE_NGBR_WCDMA_NUM_FREQS_V01 2
#define NAS_MAX_LTE_NGBR_WCDMA_NUM_CELLS_V01 8
#define NAS_MAX_LTE_NGBR_GSM_NUM_FREQS_V01 2
#define NAS_MAX_LTE_NGBR_GSM_NUM_CELLS_V01 8
#define NAS_MAX_LTE_NGBR_NUM_FREQS_V01 3
#define NAS_MAX_LTE_NGBR_NUM_CELLS_V01 8
#define QMI_NAS_RAT_MODE_PREF_CDMA2000_1X_BIT_V01 0
#define QMI_NAS_RAT_MODE_PREF_CDMA2000_HRPD_BIT_V01 1
#define QMI_NAS_RAT_MODE_PREF_GSM_BIT_V01 2
#define QMI_NAS_RAT_MODE_PREF_UMTS_BIT_V01 3
#define QMI_NAS_RAT_MODE_PREF_LTE_BIT_V01 4
#define QMI_NAS_RAT_MODE_PREF_TDSCDMA_BIT_V01 5
#define QMI_NAS_RAT_MODE_PREF_NR5G_BIT_V01 6
#define QMI_NAS_DDTM_ACTION_SUPPRESS_L2ACK_BIT_V01 0
#define QMI_NAS_DDTM_ACTION_SUPPRESS_REG_BIT_V01 1
#define QMI_NAS_DDTM_ACTION_IGNORE_SO_PAGES_BIT_V01 2
#define QMI_NAS_DDTM_ACTION_SUPPRESS_MO_DBM_BIT_V01 3
#define QMI_NAS_NETWORK_IN_USE_STATUS_BITS_V01 0x03
#define QMI_NAS_NETWORK_IN_USE_STATUS_UNKNOWN_V01 0
#define QMI_NAS_NETWORK_IN_USE_STATUS_CURRENT_SERVING_V01 1
#define QMI_NAS_NETWORK_IN_USE_STATUS_AVAILABLE_V01 2
#define QMI_NAS_NETWORK_ROAMING_STATUS_BITS_V01 0x0C
#define QMI_NAS_NETWORK_ROAMING_STATUS_UNKNOWN_V01 0
#define QMI_NAS_NETWORK_ROAMING_STATUS_HOME_V01 1
#define QMI_NAS_NETWORK_ROAMING_STATUS_ROAM_V01 2
#define QMI_NAS_NETWORK_FORBIDDEN_STATUS_BITS_V01 0x30
#define QMI_NAS_NETWORK_FORBIDDEN_STATUS_UNKNOWN_V01 0
#define QMI_NAS_NETWORK_FORBIDDEN_STATUS_FORBIDDEN_V01 1
#define QMI_NAS_NETWORK_FORBIDDEN_STATUS_NOT_FORBIDDEN_V01 2
#define QMI_NAS_NETWORK_PREFERRED_STATUS_BITS_V01 0xC0
#define QMI_NAS_NETWORK_PREFERRED_STATUS_UNKNOWN_V01 0
#define QMI_NAS_NETWORK_PREFERRED_STATUS_PREFERRED_V01 1
#define QMI_NAS_NETWORK_PREFERRED_STATUS_NOT_PREFERRED_V01 2
#define QMI_NAS_SCM_EXT_IND_BIT_V01 0x80
#define QMI_NAS_SCM_EXT_IND_BAND_CLASS_1_POINT_4_V01 1
#define QMI_NAS_SCM_EXT_IND_OTHER_BAND_V01 0
#define QMI_NAS_SCM_MODE_BIT_V01 0x40
#define QMI_NAS_SCM_MODE_DUAL_V01 1
#define QMI_NAS_SCM_MODE_CDMA_ONLY_V01 0
#define QMI_NAS_SCM_SLOTTED_BIT_V01 0x20
#define QMI_NAS_SCM_MEID_CONFIGURED_BIT_V01 0x10
#define QMI_NAS_SCM_25_MHZ_BANDWIDTH_BIT_V01 0x08
#define QMI_NAS_SCM_TRANSMISSION_BIT_V01 0x04
#define QMI_NAS_SCM_TRANSMISSION_DISCONTINUOUS_V01 1
#define QMI_NAS_SCM_TRANSMISSION_CONTINUOUS_V01 0
#define QMI_NAS_SCM_POWER_CLASS_BIT_V01 0x03
#define QMI_NAS_SCM_POWER_CLASS_I_V01 0
#define QMI_NAS_SCM_POWER_CLASS_II_V01 1
#define QMI_NAS_SCM_POWER_CLASS_III_V01 2
#define QMI_NAS_SCM_POWER_CLASS_RESERVED_V01 3
#define NAS_MAX_NAM_NAME_LEN_V01 12
#define NAS_MAX_3GPP2_SUBS_INFO_DIR_NUM_LEN_V01 10
#define MDN_MAX_LEN_V01 15
#define NAS_MAX_3GPP2_HOME_SID_NID_NUM_V01 20
#define NAS_MCC_LEN_V01 3
#define NAS_IMSI_11_12_LEN_V01 2
#define NAS_IMSI_MIN1_LEN_V01 7
#define NAS_IMSI_MIN2_LEN_V01 3
#define NAS_PLMN_LEN_V01 3
#define NAS_NMR_MAX_NUM_V01 6
#define NAS_UMTS_MAX_MONITORED_CELL_SET_NUM_V01 24
#define NAS_UMTS_GERAN_MAX_NBR_CELL_SET_NUM_V01 8
#define NAS_UMTS_LTE_MAX_NBR_CELL_SET_NUM_V01 32
#define NAS_UMTS_MAX_ACTIVE_CELL_SET_NUM_V01 10
#define NAS_SPN_LEN_MAX_V01 16
#define NAS_SPN_EXT_LEN_MAX_V01 64
#define NAS_MAX_SVC_STAT_V01 10
#define NAS_MAX_SVC_DOMAIN_V01 10
#define NAS_MAX_SVC_CAPA_V01 10
#define NAS_MAX_REG_REJ_V01 10
#define NAS_MAX_ROAM_V01 10
#define NAS_MAX_FORBIDDEN_SYS_V01 10
#define NAS_MAX_SYS_ID_V01 10
#define NAS_MAX_LAC_V01 10
#define NAS_MAX_TAC_V01 10
#define NAS_MAX_CELL_INFO_V01 10
#define NAS_MAX_BS_LOC_V01 10
#define NAS_MAX_PKT_ZONE_V01 10
#define NAS_SIG_STR_THRESHOLD_LIST_MAX_V01 16
#define NAS_SIG_STR_THRESHOLD_LIST_MAX2_V01 32
#define NAS_CDMA_POSITION_INFO_MAX_V01 10
#define NAS_TECHNOLOGY_PREF_BITMASK_3GPP2_V01 0x01
#define NAS_TECHNOLOGY_PREF_BITMASK_3GPP_V01 0x02
#define NAS_TECHNOLOGY_PREF_BITMASK_ANALOG_V01 0x04
#define NAS_TECHNOLOGY_PREF_BITMASK_DIGITAL_V01 0x08
#define NAS_TECHNOLOGY_PREF_BITMASK_HDR_V01 0x10
#define NAS_TECHNOLOGY_PREF_BITMASK_LTE_V01 0x20
#define NAS_GET_PLMN_ID_MAX_LEN_V01 32
#define NAS_TDS_MAX_NBR_CELL_NUM_V01 8
#define NAS_LTE_EMBMS_MAX_MBSFN_AREA_V01 8
#define NAS_CSG_NAME_MAX_V01 48
#define NAS_IMS_REG_STATUS_MAX_V01 64
#define NAS_MAX_CDMA_SYSTEMS_AVOIDED_V01 10
#define NAS_LTE_BAND_PRIORITY_LIST_MAX_V01 128
#define NAS_TMGI_IDENTIFIER_LEN_V01 6
#define NAS_TMGI_BEARER_INFO_MAX_V01 32
#define NAS_MAX_BUILTIN_OPLMN_ENTRIES_V01 500
#define NAS_ALT_LANG_NAME_LEN_MAX_V01 64
#define NAS_ALT_LANG_MAX_V01 10
#define NAS_CSG_RAT_LIST_MAX_LEN_V01 6
#define NAS_LTE_ACTIVE_PMCH_MAX_V01 8
#define NAS_LTE_EMBMS_MBSFN_AREAS_MAX_V01 8
#define NAS_LTE_PMCH_PER_MBSFN_AREA_MAX_V01 15
#define NAS_LTE_EMBMS_ACTIVE_SESSIONS_MAX_V01 8
#define NAS_LTE_MODULATIONS_MAX_V01 2
#define NAS_GET_SERV_CELL_SIB_MAX_V01 4096
#define NAS_HDRADDR_LENGTH_V01 16
#define NAS_MAX_CELL_LOCK_ENTRIES_V01 60
#define NAS_MAX_GERAN_CELL_ALLOCATION_V01 124
#define NAS_MAX_TARGET_FREQUENCIES_V01 8
#define NAS_MAX_SCELL_LIST_LEN_V01 4
#define NAS_BA_MAX_LEN_V01 32
#define NAS_MAX_NBR_ARFCN_LIST_V01 32
#define NAS_MAX_HOPPING_ARFCN_LIST_V01 64
#define NAS_MAX_WCDMA_NBR_UARFCN_LIST_V01 4
#define NAS_MAX_LTE_SERVING_CELL_V01 10
#define NAS_NR5G_TAC_LEN_V01 3
#define NAS_SMALL_BW_EARFCN_MAX_V01 10
#define NAS_V2X_RRC_MAX_TX_POOL_LIST_V01 2
#define NAS_V2X_RRC_MAX_RX_POOL_LIST_V01 4
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_TRI_STATE_BOOLEAN_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_TRI_FALSE_V01 = 0, /**<  Status: FALSE \n  */
  NAS_TRI_TRUE_V01 = 1, /**<  Status: TRUE  \n  */
  NAS_TRI_UNKNOWN_V01 = 2, /**<  Status: Unknown   */
  NAS_TRI_STATE_BOOLEAN_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_tri_state_boolean_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_EMM_STATE_E_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_EMM_NULL_V01 = 0, /**<  Null \n  */
  NAS_EMM_DEREGISTERED_V01 = 1, /**<  Deregistered \n  */
  NAS_EMM_REGISTERED_INITIATED_V01 = 2, /**<  Registered, initiated \n  */
  NAS_EMM_REGISTERED_V01 = 3, /**<  Registered \n  */
  NAS_EMM_TRACKING_AREA_UPDATING_INITIATED_V01 = 4, /**<  Tracking area update initiated \n  */
  NAS_EMM_SERVICE_REQUEST_INITIATED_V01 = 5, /**<  Service request initiated \n  */
  NAS_EMM_DEREGISTERED_INITIATED_V01 = 6, /**<  Deregistered, initiated  */
  NAS_EMM_STATE_E_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_emm_state_e_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_EMM_SUBSTATE_E_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_EMM_DEREGISTERED_NO_IMSI_V01 = 0, /**<  Deregistered, no IMSI \n  */
  NAS_EMM_DEREGISTERED_PLMN_SEARCH_V01 = 1, /**<  Deregistered, PLMN search \n  */
  NAS_EMM_DEREGISTERED_ATTACH_NEEDED_V01 = 2, /**<  Deregistered, attach needed \n  */
  NAS_EMM_DEREGISTERED_NO_CELL_AVAILABLE_V01 = 3, /**<  Deregistered, no cell is available \n  */
  NAS_EMM_DEREGISTERED_ATTEMPTING_TO_ATTACH_V01 = 4, /**<  Deregistered, attempting to attach \n  */
  NAS_EMM_DEREGISTERED_NORMAL_SERVICE_V01 = 5, /**<  Deregistered, normal service \n  */
  NAS_EMM_DEREGISTERED_LIMITED_SERVICE_V01 = 6, /**<  Deregistered, limited service \n  */
  NAS_EMM_REGISTERED_NORMAL_SERVICE_V01 = 7, /**<  Registered, normal service \n  */
  NAS_EMM_REGISTERED_UPDATE_NEEDED_V01 = 8, /**<  Registered, update needed \n  */
  NAS_EMM_REGISTERED_ATTEMPTING_TO_UPDATE_V01 = 9, /**<  Registered, attempting to update \n  */
  NAS_EMM_REGISTERED_NO_CELL_AVAILABLE_V01 = 10, /**<  Registered, no cell is available \n  */
  NAS_EMM_REGISTERED_PLMN_SEARCH_V01 = 11, /**<  Registered, PLMN search \n  */
  NAS_EMM_REGISTERED_LIMITED_SERVICE_V01 = 12, /**<  Registered, limited service \n  */
  NAS_EMM_REGISTERED_ATTEMPTING_TO_UPDATE_MM_V01 = 13, /**<  Registered, attemping to update MM \n  */
  NAS_EMM_REGISTERED_IMSI_DETACH_INITIATED_V01 = 14, /**<  Registered, IMSI detach initiated \n  */
  NAS_EMM_INTERNAL_SUBSTATE_V01 = 15, /**<  Internal substate  */
  NAS_EMM_SUBSTATE_E_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_emm_substate_e_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_RRC_STATE_E_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_RRC_IDLE_V01 = 0, /**<  Status: Idle \n  */
  NAS_RRC_CONNECTED_V01 = 1, /**<  Status: Connected   */
  NAS_RRC_STATE_E_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_rrc_state_e_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  LTE_RRC_STATE_EXT_E_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  LTE_RRC_STATE_EXT_NULL_V01 = 0, /**<  Null \n  */
  LTE_RRC_STATE_EXT_IDLE_CAMPED_ANYCELL_V01 = 1, /**<  Idle, Camped on Any Cell \n  */
  LTE_RRC_STATE_EXT_IDLE_CAMPED_NORMAL_V01 = 2, /**<  Idle, Camped Normal \n  */
  LTE_RRC_STATE_EXT_CONNECTING_V01 = 3, /**<  Connecting \n  */
  LTE_RRC_STATE_EXT_CONNECTED_V01 = 4, /**<  Connected \n  */
  LTE_RRC_STATE_EXT_CLOSING_V01 = 5, /**<  Releasing \n  */
  LTE_RRC_STATE_EXT_E_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}lte_rrc_state_ext_e_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_LTE_UE_CATEGORY_E_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  LTE_UE_CATEGORY_DEFAULT_V01 = 0, /**<  Default; return to power-up configuration \n  */
  LTE_UE_CATEGORY_1_V01 = 1, /**<  Type~1 \n  */
  LTE_UE_CATEGORY_2_V01 = 2, /**<  Type~2 \n  */
  LTE_UE_CATEGORY_3_V01 = 3, /**<  Type~3 \n  */
  LTE_UE_CATEGORY_4_V01 = 4, /**<  Type~4 \n  */
  LTE_UE_CATEGORY_5_V01 = 5, /**<  Type~5 \n  */
  LTE_UE_CATEGORY_6_V01 = 6, /**<  Type~6 \n  */
  LTE_UE_CATEGORY_7_V01 = 7, /**<  Type~7 \n  */
  LTE_UE_CATEGORY_8_V01 = 8, /**<  Type~8 \n  */
  LTE_UE_CATEGORY_9_V01 = 9, /**<  Type~9 \n  */
  LTE_UE_CATEGORY_10_V01 = 10, /**<  Type~10 \n  */
  LTE_UE_CATEGORY_11_V01 = 11, /**<  Type~11 \n  */
  LTE_UE_CATEGORY_12_V01 = 12, /**<  Type~12 \n  */
  LTE_UE_CATEGORY_13_V01 = 13, /**<  Type~13 \n  */
  LTE_UE_CATEGORY_INVALID_V01 = 14, /**<  Invalid~type  */
  NAS_LTE_UE_CATEGORY_E_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_lte_ue_category_e_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_PROC_TYPE_E_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_PROC_TYPE_NONE_V01 = 0, /**<  No procedure type \n  */
  NAS_PROC_TYPE_VOLTE_CALL_V01 = 1, /**<  VoLTE call (Deprecated, use VOIMS_CALL) \n  */
  NAS_PROC_TYPE_IMS_SMS_V01 = 2, /**<  IMS-based SMS \n  */
  NAS_PROC_TYPE_IMS_MMS_V01 = 3, /**<  IMS-based MMS \n  */
  NAS_PROC_TYPE_IMS_REGISTRATION_V01 = 4, /**<  IMS registration \n  */
  NAS_PROC_TYPE_IMS_UT_V01 = 5, /**<  IMS UT service  */
  NAS_PROC_TYPE_VOIMS_CALL_V01 = 6, /**<  IMS-based voice or VT call \n  */
  NAS_PROC_TYPE_E_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_proc_type_e_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_V2X_STATUS_E_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_V2X_STATUS_INACTIVE_V01 = 0, /**<  V2X Status is Inactive \n   */
  NAS_V2X_STATUS_ACTIVE_V01 = 1, /**<  V2X Status is Active \n   */
  NAS_V2X_STATUS_SUSPENDED_V01 = 2, /**<  V2X Status is Suspended  */
  NAS_V2X_STATUS_E_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_v2x_status_e_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_V2X_CAUSE_E_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_V2X_STATUS_CAUSE_TIMING_INVALID_V01 = 0, /**<  V2X timing is not valid at the modem \n  */
  NAS_V2X_STATUS_CAUSE_CONFIG_INVALID_V01 = 1, /**<  No valid V2X configuration at the modem \n  */
  NAS_V2X_STATUS_CAUSE_UE_MODE_INVALID_V01 = 2, /**<  V2X is not supported in current UE mode \n  */
  NAS_V2X_STATUS_CAUSE_OUT_OF_ALLOWED_GEOPOLYGON_V01 = 3, /**<  V2X is not supported in current UE location    */
  NAS_V2X_CAUSE_E_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_v2x_cause_e_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_BLOCK_PLMN_CAUSE_E_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_BLOCK_PLMN_CAUSE_OTHERS_V01 = 0, 
  NAS_BLOCK_PLMN_CAUSE_CALL_REDIAL_V01 = 1, 
  NAS_BLOCK_PLMN_CAUSE_E_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_block_plmn_cause_e_type_v01;
/**
    @}
  */

typedef uint64_t ciot_lte_op_mode_pref_mask_type_v01;
#define QMI_NAS_CIOT_LTE_OP_MODE_PREF_WB_V01 ((ciot_lte_op_mode_pref_mask_type_v01)0x01ull) /**<  Wideband LTE operational mode is supported \n  */
#define QMI_NAS_CIOT_LTE_OP_MODE_PREF_M1_V01 ((ciot_lte_op_mode_pref_mask_type_v01)0x02ull) /**<  LTE-M1 operational mode is supported \n  */
#define QMI_NAS_CIOT_LTE_OP_MODE_PREF_NB1_V01 ((ciot_lte_op_mode_pref_mask_type_v01)0x04ull) /**<  LTE-NB1 operational mode is supported  */
/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Resets the NAS service state variables of the requesting
              control point.  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_reset_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Resets the NAS service state variables of the requesting
              control point.  */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_reset_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Aborts a previously issued QMI_NAS command. */
typedef struct {

  /* Mandatory */
  /*  TX_ID */
  uint16_t tx_id;
  /**<   Transaction ID of the request to be aborted.
  */
}nas_abort_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Aborts a previously issued QMI_NAS command. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_abort_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t report_signal_strength;
  /**<   Values: \n
       - 0 -- Do not report \n
       - 1 -- Report
  */

  uint32_t report_signal_strength_threshold_list_len;  /**< Must be set to # of elements in report_signal_strength_threshold_list */
  int8_t report_signal_strength_threshold_list[NAS_SIG_STRENGTH_THRESHOLD_LIST_MAX_V01];
  /**<   A sequence of thresholds delimiting signal strength Var bands. 
       Each threshold specifies the signal strength (in dBm) at which
       an event report indication, including the current signal
       strength, will be sent to the requesting control point. 
       Threshold is a signed 1 byte value. Valid values: -128 dBm
       to +127 dBm.
  */
}nas_signal_stregth_indicator_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t report_rssi;
  /**<   Values: \n
       - 0 -- Do not report \n
       - 1 -- Report
  */

  uint8_t rssi_delta;
  /**<   RSSI delta (in dBm) at which an event report indication,
       including the current RSSI, will be sent to the requesting
       control point. RSSI delta is an unsigned 1 byte value.
  */
}nas_rssi_indicator_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t report_ecio;
  /**<   Values: \n
       - 0 -- Do not report \n
       - 1 -- Report
  */

  uint8_t ecio_delta;
  /**<   ECIO delta at which an event report indication,
       ecio_delta including the current ECIO, will be sent to the
       requesting control point. ECIO delta is an unsigned 1 byte
       value that increments in negative 0.5 dB, e.g., ecio_delta of
       2 means a change of -1 dB.
  */
}nas_ecio_indicator_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t report_io;
  /**<   Values: \n
       - 0 -- Do not report \n
       - 1 -- Report
  */

  uint8_t io_delta;
  /**<   IO delta (in dBm) at which an event report indication,
       io_delta including the current IO, will be sent to the
       requesting control point. IO delta is an unsigned 1 byte value.
  */
}nas_io_indicator_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t report_sinr;
  /**<   Values: \n
       - 0 -- Do not report \n
       - 1 -- Report
  */

  uint8_t sinr_delta;
  /**<   SINR delta level at which an event report indication,
       sinr_delta including the current SINR, will be sent to the
       requesting control point. SINR delta level is an unsigned
       1 byte value.
  */
}nas_sinr_indicator_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t report_rsrq;
  /**<   Values: \n
       - 0 -- Do not report \n
       - 1 -- Report
  */

  uint8_t rsrq_delta;
  /**<   RSRQ delta level at which an event report indication, including the
      current RSRQ, will be sent to the requesting control point. 
      RSRQ delta level is an unsigned 1 byte value.
  */
}nas_rsrq_indicator_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t report_ecio;
  /**<   Values: \n
       - 0 -- Do not report \n
       - 1 -- Report
  */

  uint32_t threshold_list_len;  /**< Must be set to # of elements in threshold_list */
  int16_t threshold_list[NAS_ECIO_THRESHOLD_LIST_MAX_V01];
  /**<  
      A sequence of thresholds delimiting ECIO event reporting bands.
      Every time a new ECIO value crosses a threshold value, an event
      report indication message with the new ECIO value is sent to the
      requesting control point. For this field: \n

      - Each threshold value is a signed 2 byte value \n
      - Maximum number of threshold values is 10           \n
      - At least one value must be specified (if report_ecio is set)
   */
}nas_ecio_indicator_threshold_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t report_sinr;
  /**<   Values: \n
       - 0 -- Do not report \n
       - 1 -- Report
  */

  /*  sinr threshold list */
  uint32_t threshold_list_len;  /**< Must be set to # of elements in threshold_list */
  uint8_t threshold_list[NAS_SINR_THRESHOLD_LIST_MAX_V01];
  /**<  
   A sequence of thresholds delimiting SINR event reporting bands.
   Every time a new SINR value crosses a threshold value, an event
   report indication message with the new SINR value is sent to the
   requesting control point. For this field: \n

   - Each threshold value will be an unsigned 1 byte value \n
   - Maximum number of threshold values is 5              \n
   - At least one value must be specified (if report_sinr is set)
 */
}nas_sinr_indicator_threshold_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t report_lte_rsrp;
  /**<   Values: \n
       - 0 -- Do not report \n
       - 1 -- Report
  */

  uint8_t lte_rsrp_delta;
  /**<   LTE RSRP delta level at which an event report indication, including the
       current RSRP, will be sent to the requesting control point. LTE RSRP 
       delta level is an unsigned 1 byte value, representing the delta in dB.
  */
}nas_rsrp_indicator_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t report_lte_snr;
  /**<   Values: \n
       - 0 -- Do not report \n
       - 1 -- Report
  */

  uint16_t lte_snr_delta;
  /**<   LTE SNR delta level at which an event report indication, including the
       current SNR, will be sent to the requesting control point. LTE SNR delta 
       level is an unsigned 2 byte value, representing the delta in units 
       of 0.1 dB, e.g., lte_snr_delta of 3 means a change 0.3 dB.
  */
}nas_snr_indicator_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t cp_ciot_supported;
  /**<   Whether control plane (CP) CIoT EPS optimization is supported by the network.
       Values: \n
       - 0 -- Not supported \n
       - 1 -- Supported 
  */

  uint8_t up_ciot_supported;
  /**<  Whether user plane CIoT EPS optimization is supported by the network.
      Values: \n
       - 0 -- Not supported \n
       - 1 -- Supported 
  */
}nas_supp_ciot_optimizations_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets the NAS state reporting conditions for the requesting
              control point. (Deprecated) */
typedef struct {

  /* Optional */
  /*  Signal Strength Indicator */
  uint8_t signal_strength_valid;  /**< Must be set to true if signal_strength is being passed */
  nas_signal_stregth_indicator_type_v01 signal_strength;

  /* Optional */
  /*  RF Band Information */
  uint8_t report_rf_band_info_valid;  /**< Must be set to true if report_rf_band_info is being passed */
  uint8_t report_rf_band_info;
  /**<   Values: \n
       - 0 -- Do not report \n
       - 1 -- Report
  */

  /* Optional */
  /*  Registration Reject Reason** */
  uint8_t report_reg_reject_valid;  /**< Must be set to true if report_reg_reject is being passed */
  uint8_t report_reg_reject;
  /**<   Values: \n
       - 0 -- Do not report \n
       - 1 -- Report
  */

  /* Optional */
  /*  RSSI Indicator */
  uint8_t rssi_indicator_valid;  /**< Must be set to true if rssi_indicator is being passed */
  nas_rssi_indicator_type_v01 rssi_indicator;

  /* Optional */
  /*  ECIO Indicator */
  uint8_t ecio_indicator_valid;  /**< Must be set to true if ecio_indicator is being passed */
  nas_ecio_indicator_type_v01 ecio_indicator;

  /* Optional */
  /*  IO Indicator* */
  uint8_t io_indicator_valid;  /**< Must be set to true if io_indicator is being passed */
  nas_io_indicator_type_v01 io_indicator;

  /* Optional */
  /*  SINR Indicator* */
  uint8_t sinr_indicator_valid;  /**< Must be set to true if sinr_indicator is being passed */
  nas_sinr_indicator_type_v01 sinr_indicator;

  /* Optional */
  /*  Error Rate Indicator */
  uint8_t report_error_rate_valid;  /**< Must be set to true if report_error_rate is being passed */
  uint8_t report_error_rate;
  /**<   Values: \n
       - 0 -- Do not report \n
       - 1 -- Report
  */

  /* Optional */
  /*  RSRQ Indicator* */
  uint8_t rsrq_indicator_valid;  /**< Must be set to true if rsrq_indicator is being passed */
  nas_rsrq_indicator_type_v01 rsrq_indicator;

  /* Optional */
  /*  ECIO Threshold */
  uint8_t ecio_threshold_indicator_valid;  /**< Must be set to true if ecio_threshold_indicator is being passed */
  nas_ecio_indicator_threshold_type_v01 ecio_threshold_indicator;

  /* Optional */
  /*  SINR Threshold */
  uint8_t sinr_threshold_indicator_valid;  /**< Must be set to true if sinr_threshold_indicator is being passed */
  nas_sinr_indicator_threshold_type_v01 sinr_threshold_indicator;

  /* Optional */
  /*  LTE SNR Delta */
  uint8_t lte_snr_delta_indicator_valid;  /**< Must be set to true if lte_snr_delta_indicator is being passed */
  nas_snr_indicator_type_v01 lte_snr_delta_indicator;

  /* Optional */
  /*  RSRP Delta */
  uint8_t lte_rsrp_delta_indicator_valid;  /**< Must be set to true if lte_rsrp_delta_indicator is being passed */
  nas_rsrp_indicator_type_v01 lte_rsrp_delta_indicator;
}nas_set_event_report_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets the NAS state reporting conditions for the requesting
              control point. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_event_report_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  int8_t sig_strength;
  /**<   Received signal strength in dBm:                           \n
       - For CDMA and UMTS, this indicates forward link pilot Ec  \n
       - For GSM, this indicates received signal strength \n
       - For LTE, this indicates the total received wideband power observed by the UE
    */

  nas_radio_if_enum_v01 radio_if;
  /**<   Radio interface technology of the signal being measured. Values: \n
       -0x00 -- RADIO_IF_NO_SVC      -- None (no service) \n
       -0x01 -- RADIO_IF_CDMA_1X     -- 
        cdma2000\textsuperscript{\textregistered} 1X             \n
       -0x02 -- RADIO_IF_CDMA_1XEVDO -- 
        cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n 
       -0x03 -- RADIO_IF_AMPS        -- AMPS \n
       -0x04 -- RADIO_IF_GSM         -- GSM \n
       -0x05 -- RADIO_IF_UMTS        -- UMTS \n
       -0x08 -- RADIO_IF_LTE         -- LTE
  */
}nas_signal_strength_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_ACTIVE_BAND_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_ACTIVE_BAND_BC_0_V01 = 0, 
  NAS_ACTIVE_BAND_BC_1_V01 = 1, 
  NAS_ACTIVE_BAND_BC_3_V01 = 3, 
  NAS_ACTIVE_BAND_BC_4_V01 = 4, 
  NAS_ACTIVE_BAND_BC_5_V01 = 5, 
  NAS_ACTIVE_BAND_BC_6_V01 = 6, 
  NAS_ACTIVE_BAND_BC_7_V01 = 7, 
  NAS_ACTIVE_BAND_BC_8_V01 = 8, 
  NAS_ACTIVE_BAND_BC_9_V01 = 9, 
  NAS_ACTIVE_BAND_BC_10_V01 = 10, 
  NAS_ACTIVE_BAND_BC_11_V01 = 11, 
  NAS_ACTIVE_BAND_BC_12_V01 = 12, 
  NAS_ACTIVE_BAND_BC_13_V01 = 13, 
  NAS_ACTIVE_BAND_BC_14_V01 = 14, 
  NAS_ACTIVE_BAND_BC_15_V01 = 15, 
  NAS_ACTIVE_BAND_BC_16_V01 = 16, 
  NAS_ACTIVE_BAND_BC_17_V01 = 17, 
  NAS_ACTIVE_BAND_BC_18_V01 = 18, 
  NAS_ACTIVE_BAND_BC_19_V01 = 19, 
  NAS_ACTIVE_BAND_GSM_450_V01 = 40, 
  NAS_ACTIVE_BAND_GSM_480_V01 = 41, 
  NAS_ACTIVE_BAND_GSM_750_V01 = 42, 
  NAS_ACTIVE_BAND_GSM_850_V01 = 43, 
  NAS_ACTIVE_BAND_GSM_900_EXTENDED_V01 = 44, 
  NAS_ACTIVE_BAND_GSM_900_PRIMARY_V01 = 45, 
  NAS_ACTIVE_BAND_GSM_900_RAILWAYS_V01 = 46, 
  NAS_ACTIVE_BAND_GSM_1800_V01 = 47, 
  NAS_ACTIVE_BAND_GSM_1900_V01 = 48, 
  NAS_ACTIVE_BAND_WCDMA_2100_V01 = 80, 
  NAS_ACTIVE_BAND_WCDMA_PCS_1900_V01 = 81, 
  NAS_ACTIVE_BAND_WCDMA_DCS_1800_V01 = 82, 
  NAS_ACTIVE_BAND_WCDMA_1700_US_V01 = 83, 
  NAS_ACTIVE_BAND_WCDMA_850_V01 = 84, 
  NAS_ACTIVE_BAND_WCDMA_800_V01 = 85, 
  NAS_ACTIVE_BAND_WCDMA_2600_V01 = 86, 
  NAS_ACTIVE_BAND_WCDMA_900_V01 = 87, 
  NAS_ACTIVE_BAND_WCDMA_1700_JAPAN_V01 = 88, 
  NAS_ACTIVE_BAND_WCDMA_1500_JAPAN_V01 = 90, 
  NAS_ACTIVE_BAND_WCDMA_850_JAPAN_V01 = 91, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_1_V01 = 120, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_2_V01 = 121, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_3_V01 = 122, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_4_V01 = 123, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_5_V01 = 124, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_6_V01 = 125, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_7_V01 = 126, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_8_V01 = 127, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_9_V01 = 128, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_10_V01 = 129, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_11_V01 = 130, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_12_V01 = 131, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_13_V01 = 132, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_14_V01 = 133, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_17_V01 = 134, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_33_V01 = 135, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_34_V01 = 136, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_35_V01 = 137, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_36_V01 = 138, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_37_V01 = 139, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_38_V01 = 140, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_39_V01 = 141, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_40_V01 = 142, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_18_V01 = 143, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_19_V01 = 144, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_20_V01 = 145, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_21_V01 = 146, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_24_V01 = 147, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_25_V01 = 148, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_41_V01 = 149, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_42_V01 = 150, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_43_V01 = 151, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_23_V01 = 152, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_26_V01 = 153, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_32_V01 = 154, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_125_V01 = 155, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_126_V01 = 156, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_127_V01 = 157, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_28_V01 = 158, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_29_V01 = 159, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_30_V01 = 160, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_66_V01 = 161, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_250_V01 = 162, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_46_V01 = 163, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_27_V01 = 164, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_31_V01 = 165, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_71_V01 = 166, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_47_V01 = 167, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_48_V01 = 168, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_67_V01 = 169, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_68_V01 = 170, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_49_V01 = 171, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_85_V01 = 172, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_72_V01 = 173, 
  NAS_ACTIVE_BAND_E_UTRA_OPERATING_BAND_73_V01 = 174, 
  NAS_ACTIVE_BAND_TDSCDMA_BAND_A_V01 = 200, 
  NAS_ACTIVE_BAND_TDSCDMA_BAND_B_V01 = 201, 
  NAS_ACTIVE_BAND_TDSCDMA_BAND_C_V01 = 202, 
  NAS_ACTIVE_BAND_TDSCDMA_BAND_D_V01 = 203, 
  NAS_ACTIVE_BAND_TDSCDMA_BAND_E_V01 = 204, 
  NAS_ACTIVE_BAND_TDSCDMA_BAND_F_V01 = 205, 
  NAS_ACTIVE_BAND_NR5G_BAND_1_V01 = 250, 
  NAS_ACTIVE_BAND_NR5G_BAND_2_V01 = 251, 
  NAS_ACTIVE_BAND_NR5G_BAND_3_V01 = 252, 
  NAS_ACTIVE_BAND_NR5G_BAND_5_V01 = 253, 
  NAS_ACTIVE_BAND_NR5G_BAND_7_V01 = 254, 
  NAS_ACTIVE_BAND_NR5G_BAND_8_V01 = 255, 
  NAS_ACTIVE_BAND_NR5G_BAND_20_V01 = 256, 
  NAS_ACTIVE_BAND_NR5G_BAND_28_V01 = 257, 
  NAS_ACTIVE_BAND_NR5G_BAND_38_V01 = 258, 
  NAS_ACTIVE_BAND_NR5G_BAND_41_V01 = 259, 
  NAS_ACTIVE_BAND_NR5G_BAND_50_V01 = 260, 
  NAS_ACTIVE_BAND_NR5G_BAND_51_V01 = 261, 
  NAS_ACTIVE_BAND_NR5G_BAND_66_V01 = 262, 
  NAS_ACTIVE_BAND_NR5G_BAND_70_V01 = 263, 
  NAS_ACTIVE_BAND_NR5G_BAND_71_V01 = 264, 
  NAS_ACTIVE_BAND_NR5G_BAND_74_V01 = 265, 
  NAS_ACTIVE_BAND_NR5G_BAND_75_V01 = 266, 
  NAS_ACTIVE_BAND_NR5G_BAND_76_V01 = 267, 
  NAS_ACTIVE_BAND_NR5G_BAND_77_V01 = 268, 
  NAS_ACTIVE_BAND_NR5G_BAND_78_V01 = 269, 
  NAS_ACTIVE_BAND_NR5G_BAND_79_V01 = 270, 
  NAS_ACTIVE_BAND_NR5G_BAND_80_V01 = 271, 
  NAS_ACTIVE_BAND_NR5G_BAND_81_V01 = 272, 
  NAS_ACTIVE_BAND_NR5G_BAND_82_V01 = 273, 
  NAS_ACTIVE_BAND_NR5G_BAND_83_V01 = 274, 
  NAS_ACTIVE_BAND_NR5G_BAND_84_V01 = 275, 
  NAS_ACTIVE_BAND_NR5G_BAND_85_V01 = 276, 
  NAS_ACTIVE_BAND_NR5G_BAND_257_V01 = 277, 
  NAS_ACTIVE_BAND_NR5G_BAND_258_V01 = 278, 
  NAS_ACTIVE_BAND_NR5G_BAND_259_V01 = 279, 
  NAS_ACTIVE_BAND_NR5G_BAND_260_V01 = 280, 
  NAS_ACTIVE_BAND_NR5G_BAND_261_V01 = 281, 
  NAS_ACTIVE_BAND_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_active_band_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_radio_if_enum_v01 radio_if;
  /**<   Radio interface currently in use. Values:  \n
       - 0x01 -- cdma2000\textsuperscript{\textregistered} 1X             \n
       - 0x02 -- cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
       - 0x03 -- AMPS \n
       - 0x04 -- GSM \n
       - 0x05 -- UMTS \n
       - 0x08 -- LTE \n
       - 0x09 -- TD-SCDMA \n
       - 0x0C -- NR5G
  */

  nas_active_band_enum_v01 active_band;
  /**<   Active band class (see Table @latexonly\ref{tbl:bandClass}@endlatexonly 
      for details). Values: \n
      - 00 to 39   -- CDMA band classes  \n
      - 40 to 79   -- GSM band classes   \n
      - 80 to 91   -- WCDMA band classes \n
      - 120 to 174 -- LTE band classes   \n
      - 200 to 205 -- TD-SCDMA band classes \n
      - 250 to 281 -- NR-5G band classes
  */

  uint16_t active_channel;
  /**<   Active channel. If the channel is not relevant to the
      technology, a value of 0 is returned.
 */
}nas_rf_band_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_radio_if_enum_v01 radio_if;
  /**<   Radio interface currently in use. Values:  \n
       - 0x01 -- cdma2000\textsuperscript{\textregistered} 1X             \n
       - 0x02 -- cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
       - 0x03 -- AMPS \n
       - 0x04 -- GSM \n
       - 0x05 -- UMTS \n
       - 0x08 -- LTE \n
       - 0x09 -- TD-SCDMA
  */

  nas_active_band_enum_v01 dedicated_band;
  /**<   Dedicated band class (see Table @latexonly\ref{tbl:bandClass}@endlatexonly 
      for details). Values: \n
      - 00 to 39   -- CDMA band classes  \n
      - 40 to 79   -- GSM band classes   \n
      - 80 to 91   -- WCDMA band classes \n
      - 120 to 174 -- LTE band classes   \n
      - 200 to 205 -- TD-SCDMA band classes \n
      - 0xFFFF is invalid; indicates that the UE moved out from the dedicated band
  */
}nas_rf_dedicated_band_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_BANDWIDTH_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_LTE_BW_NRB_6_V01 = 0, /**<  LTE 1.4 MHz bandwidth \n  */
  NAS_LTE_BW_NRB_15_V01 = 1, /**<  LTE 3 MHz bandwidth \n  */
  NAS_LTE_BW_NRB_25_V01 = 2, /**<  LTE 5 MHz bandwidth \n  */
  NAS_LTE_BW_NRB_50_V01 = 3, /**<  LTE 10 MHz bandwidth \n  */
  NAS_LTE_BW_NRB_75_V01 = 4, /**<  LTE 15 MHz bandwidth \n  */
  NAS_LTE_BW_NRB_100_V01 = 5, /**<  LTE 20 MHz bandwidth \n */
  NAS_NR5G_BW_NRB_5_V01 = 6, /**<  NR5G 5 MHz bandwidth \n */
  NAS_NR5G_BW_NRB_10_V01 = 7, /**<  NR5G 10 MHz bandwidth \n */
  NAS_NR5G_BW_NRB_15_V01 = 8, /**<  NR5G 15 MHz bandwidth \n */
  NAS_NR5G_BW_NRB_20_V01 = 9, /**<  NR5G 20 MHz bandwidth \n */
  NAS_NR5G_BW_NRB_25_V01 = 10, /**<  NR5G 25 MHz bandwidth \n */
  NAS_NR5G_BW_NRB_30_V01 = 11, /**<  NR5G 30 MHz bandwidth \n */
  NAS_NR5G_BW_NRB_40_V01 = 12, /**<  NR5G 40 MHz bandwidth \n */
  NAS_NR5G_BW_NRB_50_V01 = 13, /**<  NR5G 50 MHz bandwidth \n */
  NAS_NR5G_BW_NRB_60_V01 = 14, /**<  NR5G 60 MHz bandwidth \n */
  NAS_NR5G_BW_NRB_80_V01 = 15, /**<  NR5G 80 MHz bandwidth \n */
  NAS_NR5G_BW_NRB_90_V01 = 16, /**<  NR5G 90 MHz bandwidth \n */
  NAS_NR5G_BW_NRB_100_V01 = 17, /**<  NR5G 100 MHz bandwidth \n */
  NAS_NR5G_BW_NRB_200_V01 = 18, /**<  NR5G 200 MHz bandwidth \n */
  NAS_NR5G_BW_NRB_400_V01 = 19, /**<  NR5G 400 MHz bandwidth \n */
  NAS_GSM_BW_NRB_2_V01 = 20, /**<  GSM  0.2 MHz bandwidth \n */
  NAS_TDSCDMA_BW_NRB_2_V01 = 21, /**<  TDSCDMA 1.6 MHz bandwidth \n */
  NAS_WCDMA_BW_NRB_5_V01 = 22, /**<  WCDMA 5 MHz bandwidth \n */
  NAS_WCDMA_BW_NRB_10_V01 = 23, /**<  WCDMA 10 MHz bandwidth \n */
  NAS_BANDWIDTH_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_bandwidth_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_radio_if_enum_v01 radio_if;
  /**<   Radio interface currently in use. Values: \n
      - NAS_RADIO_IF_NO_SVC (0x00) --  None (no service) \n 
      - NAS_RADIO_IF_CDMA_1X (0x01) --  cdma2000\textsuperscript{\textregistered} 1X \n 
      - NAS_RADIO_IF_CDMA_1XEVDO (0x02) --  cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n 
      - NAS_RADIO_IF_AMPS (0x03) --  AMPS \n 
      - NAS_RADIO_IF_GSM (0x04) --  GSM \n 
      - NAS_RADIO_IF_UMTS (0x05) --  UMTS \n 
      - NAS_RADIO_IF_WLAN (0x06) --  WLAN \n 
      - NAS_RADIO_IF_GPS (0x07) --  GPS \n 
      - NAS_RADIO_IF_LTE (0x08) --  LTE \n 
      - NAS_RADIO_IF_TDSCDMA (0x09) --  TD-SCDMA \n 
      - NAS_RADIO_IF_NR5G (0x0C) --  NR5G \n 
      - NAS_RADIO_IF_NO_CHANGE (-1) --  No change 
 */

  nas_bandwidth_enum_type_v01 bandwidth;
  /**<   Bandwidth. Values: \n
      - NAS_LTE_BW_NRB_6 (0) --  LTE 1.4 MHz bandwidth \n 
      - NAS_LTE_BW_NRB_15 (1) --  LTE 3 MHz bandwidth \n 
      - NAS_LTE_BW_NRB_25 (2) --  LTE 5 MHz bandwidth \n 
      - NAS_LTE_BW_NRB_50 (3) --  LTE 10 MHz bandwidth \n 
      - NAS_LTE_BW_NRB_75 (4) --  LTE 15 MHz bandwidth \n 
      - NAS_LTE_BW_NRB_100 (5) --  LTE 20 MHz bandwidth \n
      - NAS_NR5G_BW_NRB_5 (6) --  NR5G 5 MHz bandwidth \n
      - NAS_NR5G_BW_NRB_10 (7) --  NR5G 10 MHz bandwidth \n
      - NAS_NR5G_BW_NRB_15 (8) --  NR5G 15 MHz bandwidth \n
      - NAS_NR5G_BW_NRB_20 (9) --  NR5G 20 MHz bandwidth \n
      - NAS_NR5G_BW_NRB_25 (10) --  NR5G 25 MHz bandwidth \n
      - NAS_NR5G_BW_NRB_30 (11) --  NR5G 30 MHz bandwidth \n
      - NAS_NR5G_BW_NRB_40 (12) --  NR5G 40 MHz bandwidth \n
      - NAS_NR5G_BW_NRB_50 (13) --  NR5G 50 MHz bandwidth \n
      - NAS_NR5G_BW_NRB_60 (14) --  NR5G 60 MHz bandwidth \n
      - NAS_NR5G_BW_NRB_80 (15) --  NR5G 80 MHz bandwidth \n
      - NAS_NR5G_BW_NRB_90 (16) --  NR5G 90 MHz bandwidth \n
      - NAS_NR5G_BW_NRB_100 (17) --  NR5G 100 MHz bandwidth \n
      - NAS_NR5G_BW_NRB_200 (18) --  NR5G 200 MHz bandwidth \n
      - NAS_NR5G_BW_NRB_400 (19) --  NR5G 400 MHz bandwidth \n
      - NAS_GSM_BW_NRB_2 (20) --  GSM  0.2 MHz bandwidth \n
      - NAS_TDSCDMA_BW_NRB_2 (21) --  TDSCDMA 1.6 MHz bandwidth \n
      - NAS_WCDMA_BW_NRB_5 (22) --  WCDMA 5 MHz bandwidth \n
      - NAS_WCDMA_BW_NRB_10 (23) --  WCDMA 10 MHz bandwidth \n
 */
}nas_rf_bandwidth_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_NETWORK_SERVICE_DOMAIN_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_CIRCUIT_SWITCHED_V01 = 0x01, 
  NAS_PACKET_SWITCHED_V01 = 0x02, 
  NAS_CIRCUIT_AND_PACKET_SWITCHED_V01 = 0x03, 
  NAS_NETWORK_SERVICE_DOMAIN_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_network_service_domain_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_network_service_domain_enum_v01 service_domain;
  /**<   Network service domain that was rejected. Possible values: \n
       - 1 -- CIRCUIT_SWITCHED \n
       - 2 -- PACKET_SWITCHED \n
       - 3 -- CIRCUIT_AND_PACKET_ SWITCHED
  */

  uint16_t reject_cause;
  /**<   Reject cause; refer to 
       \hyperref[STD-24008]{3GPP TS 24.008} Sections 10.5.3.6 and 10.5.5.14, and 
       \hyperref[STD-24301]{3GPP TS 24.301} Section 9.9.3.9.
  */
}nas_registration_reject_reason_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t rssi;
  /**<   RSSI represented as a positive value; control points need to
       convert this to negative to get actual value in dBm: \n
       - For CDMA and UMTS, this indicates forward link pilot Ec \n
       - For GSM, this indicates received signal strength
  */

  nas_radio_if_enum_v01 radio_if;
  /**<   Radio interface technology of the signal being measured. Values:  \n
       -0x00 -- RADIO_IF_NO_SVC      -- None (no service) \n
       -0x01 -- RADIO_IF_CDMA_1X     -- 
        cdma2000\textsuperscript{\textregistered} 1X             \n
       -0x02 -- RADIO_IF_CDMA_1XEVDO -- 
        cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
       -0x03 -- RADIO_IF_AMPS        -- AMPS \n
       -0x04 -- RADIO_IF_GSM         -- GSM \n
       -0x05 -- RADIO_IF_UMTS        -- UMTS \n
       -0x08 -- RADIO_IF_LTE         -- LTE
  */
}nas_rssi_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t ecio;
  /**<   ECIO value representing negative 0.5 dB increments, i.e., 
       2 means -1 dB (14 means -7 dB, 63 means -31.5 dB).
  */

  nas_radio_if_enum_v01 radio_if;
  /**<   Radio interface technology of the signal being measured. Values:  \n
       -0x00 -- RADIO_IF_NO_SVC      -- None (no service) \n
       -0x01 -- RADIO_IF_CDMA_1X     -- 
        cdma2000\textsuperscript{\textregistered} 1X             \n
       -0x02 -- RADIO_IF_CDMA_1XEVDO -- 
        cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
       -0x03 -- RADIO_IF_AMPS        -- AMPS \n
       -0x04 -- RADIO_IF_GSM         -- GSM \n
       -0x05 -- RADIO_IF_UMTS        -- UMTS 
  */
}nas_ecio_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t error_rate;
  /**<   Error rate value corresponds to the RAT that is currently registered. \n
         For CDMA, the error rate reported is Frame Error Rate: \n
         - Valid error rate values between 1 and 10000 are returned to indicate 
            percentage, e.g., a value of 300 means the error rate is 3% \n
         - A value of 0xFFFF indicates that the error rate is unknown or 
            unavailable \n
         For HDR, the error rate reported is Packet Error Rate: \n
         - Valid error rate values between 1 and 10000 are returned to indicate 
            percentage, e.g., a value of 300 means the error rate is 3% \n
         - A value of 0xFFFF indicates that the error rate is unknown or 
            unavailable \n
         For GSM, the error rate reported is Bit Error Rate: \n
         - Valid values are 0, 100, 200, 300, 400, 500, 600, and 700 \n
         - The reported value divided by 100 gives the error rate as an RxQual 
            value as defined in \hyperref[STD-45008]{3GPP TS 45.008} Section 8.2.4, 
            e.g., a value of 300 represents an RxQual value of 3 \n
         - A value of 25500 indicates No Data \n
         For WCDMA, the error rate reported is Block Error Rate (BLER): \n
         - Valid values are 1 to 10000 \n
         - The reported value divided by 100 provides the error rate in 
            percentages, e.g., a value of 300 represents a BLER of 3% \n
         - A value of 0 indicates No Data
  */

  nas_radio_if_enum_v01 radio_if;
  /**<   Radio interface technology of the signal being measured. Values:  \n
       -0x00 -- RADIO_IF_NO_SVC      -- None (no service) \n
       -0x01 -- RADIO_IF_CDMA_1X     -- 
        cdma2000\textsuperscript{\textregistered} 1X             \n
       -0x02 -- RADIO_IF_CDMA_1XEVDO -- 
        cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
       -0x03 -- RADIO_IF_AMPS        -- AMPS \n
       -0x04 -- RADIO_IF_GSM         -- GSM \n
       -0x05 -- RADIO_IF_UMTS        -- UMTS
  */
}nas_error_rate_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  int8_t rsrq;
  /**<   RSRQ value in dB (signed integer value).
       Range: -3 to -20 (-3 means -3 dB, -20 means -20 dB).
  */

  uint8_t radio_if;
  /**<   Radio interface technology of the signal being measured. Values: \n
       - 0x08 -- LTE
  */
}nas_rsrq_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_SINR_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_SINR_LEVEL_0_V01 = 0x00, 
  NAS_SINR_LEVEL_1_V01 = 0x01, 
  NAS_SINR_LEVEL_2_V01 = 0x02, 
  NAS_SINR_LEVEL_3_V01 = 0x03, 
  NAS_SINR_LEVEL_4_V01 = 0x04, 
  NAS_SINR_LEVEL_5_V01 = 0x05, 
  NAS_SINR_LEVEL_6_V01 = 0x06, 
  NAS_SINR_LEVEL_7_V01 = 0x07, 
  NAS_SINR_LEVEL_8_V01 = 0x08, 
  NAS_SINR_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_sinr_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates the NAS state change. (Deprecated) */
typedef struct {

  /* Optional */
  /*  Signal Strength */
  uint8_t signal_strength_valid;  /**< Must be set to true if signal_strength is being passed */
  nas_signal_strength_type_v01 signal_strength;

  /* Optional */
  /*  RF Band Information List */
  uint8_t rf_band_info_list_valid;  /**< Must be set to true if rf_band_info_list is being passed */
  uint32_t rf_band_info_list_len;  /**< Must be set to # of elements in rf_band_info_list */
  nas_rf_band_info_type_v01 rf_band_info_list[NAS_RADIO_IF_LIST_MAX_V01];

  /* Optional */
  /*  Registration Reject Reason** */
  uint8_t registration_reject_reason_valid;  /**< Must be set to true if registration_reject_reason is being passed */
  nas_registration_reject_reason_type_v01 registration_reject_reason;

  /* Optional */
  /*  RSSI */
  uint8_t rssi_valid;  /**< Must be set to true if rssi is being passed */
  nas_rssi_type_v01 rssi;

  /* Optional */
  /*  ECIO */
  uint8_t ecio_valid;  /**< Must be set to true if ecio is being passed */
  nas_ecio_type_v01 ecio;

  /* Optional */
  /*  IO* */
  uint8_t io_valid;  /**< Must be set to true if io is being passed */
  int32_t io;
  /**<   Received IO in dBm. IO is only applicable for 1xEV-DO.
  */

  /* Optional */
  /*  SINR* */
  uint8_t sinr_valid;  /**< Must be set to true if sinr is being passed */
  nas_sinr_enum_v01 sinr;
  /**<   SINR level. SINR is only applicable for 1xEV-DO. 
       Valid levels are 0 to 8, where the maximum value for:        \n
       - 0x00 -- SINR_LEVEL_0 is -9 dB     \n
       - 0x01 -- SINR_LEVEL_1 is -6 dB     \n
       - 0x02 -- SINR_LEVEL_2 is -4.5 dB   \n
       - 0x03 -- SINR_LEVEL_3 is -3 dB     \n
       - 0x04 -- SINR_LEVEL_4 is -2 dB     \n
       - 0x05 -- SINR_LEVEL_5 is +1 dB     \n
       - 0x06 -- SINR_LEVEL_6 is +3 dB     \n
       - 0x07 -- SINR_LEVEL_7 is +6 dB     \n
       - 0x08 -- SINR_LEVEL_8 is +9 dB
  */

  /* Optional */
  /*  Error Rate */
  uint8_t error_rate_valid;  /**< Must be set to true if error_rate is being passed */
  nas_error_rate_type_v01 error_rate;

  /* Optional */
  /*  RSRQ** */
  uint8_t rsrq_valid;  /**< Must be set to true if rsrq is being passed */
  nas_rsrq_type_v01 rsrq;

  /* Optional */
  /*  LTE SNR */
  uint8_t snr_valid;  /**< Must be set to true if snr is being passed */
  int16_t snr;
  /**<   
     LTE SNR level as a scaled integer in units of 0.1 dB; 
     e.g., -16 dB has a value of -160 and 24.6 dB has a value of 246.
      */

  /* Optional */
  /*  LTE RSRP */
  uint8_t rsrp_valid;  /**< Must be set to true if rsrp is being passed */
  int16_t rsrp;
  /**<  
     Current LTE RSRP in dBm as measured by L1. 
     Range: -44 to -140 (-44 means -44 dBm, -140 means -140 dBm).
  */
}nas_event_report_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t reg_network_reject;
  /**<   Controls the reporting of QMI_NAS_NETWORK_REJECT_IND. Values: \n
       - 0x00 -- Disable (default value) \n
       - 0x01 -- Enable
  */

  uint8_t suppress_sys_info;
  /**<   Controls the reporting of QMI_NAS_SYS_INFO_IND when only the reject_cause 
       field has changed. Values: \n
       - 0x00 -- Do not suppress (default value) \n
       - 0x01 -- Suppress
  */
}nas_reg_network_reject_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets the registration state for different
              QMI_NAS indications for the requesting control point.
              \label{idl:indicationRegister} */
typedef struct {

  /* Optional */
  /*  System Selection Preference */
  uint8_t reg_sys_sel_pref_valid;  /**< Must be set to true if reg_sys_sel_pref is being passed */
  uint8_t reg_sys_sel_pref;
  /**<   Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  DDTM Events */
  uint8_t reg_ddtm_events_valid;  /**< Must be set to true if reg_ddtm_events is being passed */
  uint8_t reg_ddtm_events;
  /**<   Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  Serving System Events */
  uint8_t req_serving_system_valid;  /**< Must be set to true if req_serving_system is being passed */
  uint8_t req_serving_system;
  /**<   Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  Dual Standby Preference */
  uint8_t dual_standby_pref_valid;  /**< Must be set to true if dual_standby_pref is being passed */
  uint8_t dual_standby_pref;
  /**<   Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  Subscription Info */
  uint8_t subscription_info_valid;  /**< Must be set to true if subscription_info is being passed */
  uint8_t subscription_info;
  /**<   Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable 
  */

  /* Optional */
  /*  Network Time */
  uint8_t reg_network_time_valid;  /**< Must be set to true if reg_network_time is being passed */
  uint8_t reg_network_time;
  /**<    Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable 
  */

  /* Optional */
  /*  Sys Info */
  uint8_t sys_info_valid;  /**< Must be set to true if sys_info is being passed */
  uint8_t sys_info;
  /**<    Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable 
  */

  /* Optional */
  /*  Signal Strength  */
  uint8_t sig_info_valid;  /**< Must be set to true if sig_info is being passed */
  uint8_t sig_info;
  /**<    Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable 
  */

  /* Optional */
  /*  Error Rate */
  uint8_t err_rate_valid;  /**< Must be set to true if err_rate is being passed */
  uint8_t err_rate;
  /**<    Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable 
  */

  /* Optional */
  /*  HDR New UATI Assigned  */
  uint8_t reg_hdr_uati_valid;  /**< Must be set to true if reg_hdr_uati is being passed */
  uint8_t reg_hdr_uati;
  /**<   Controls the reporting of QMI_NAS_HDR_UATI_UPDATE_IND. Values: \n
       - 0x00 -- Disable (default value) \n
       - 0x01 -- Enable 
  */

  /* Optional */
  /*  HDR Session Closed */
  uint8_t reg_hdr_session_close_valid;  /**< Must be set to true if reg_hdr_session_close is being passed */
  uint8_t reg_hdr_session_close;
  /**<   Controls the reporting of QMI_NAS_HDR_SESSION_CLOSE_IND. Values: \n  
       - 0x00 -- Disable (default value) \n
       - 0x01 -- Enable 
  */

  /* Optional */
  /*  Managed Roaming */
  uint8_t reg_managed_roaming_valid;  /**< Must be set to true if reg_managed_roaming is being passed */
  uint8_t reg_managed_roaming;
  /**<   Controls the reporting of QMI_NAS_MANAGED_ROAMING_IND. Values: \n
       - 0x00 -- Disable (default value) \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  Current PLMN Name */
  uint8_t reg_current_plmn_name_valid;  /**< Must be set to true if reg_current_plmn_name is being passed */
  uint8_t reg_current_plmn_name;
  /**<   Controls the reporting of QMI_NAS_CURRENT_PLMN_NAME_IND. Values: \n
       - 0x00 -- Disable (default value) \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  eMBMS Status */
  uint8_t reg_embms_status_valid;  /**< Must be set to true if reg_embms_status is being passed */
  uint8_t reg_embms_status;
  /**<   Controls the reporting of QMI_NAS_EMBMS_STATUS_IND. Values: \n
       - 0x00 -- Disable (default value) \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  RF Band Information */
  uint8_t reg_rf_band_info_valid;  /**< Must be set to true if reg_rf_band_info is being passed */
  uint8_t reg_rf_band_info;
  /**<   Controls the reporting of QMI_NAS_RF_BAND_INFO_IND. Values: \n
       - 0x00 -- Disable (default value) \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  Network Reject Information */
  uint8_t network_reject_valid;  /**< Must be set to true if network_reject is being passed */
  nas_reg_network_reject_v01 network_reject;

  /* Optional */
  /*  Operator Name Data */
  uint8_t reg_operator_name_data_valid;  /**< Must be set to true if reg_operator_name_data is being passed */
  uint8_t reg_operator_name_data;
  /**<   Controls the reporting of QMI_NAS_OPERATOR_NAME_DATA_IND. Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable (default value) 
  */

  /* Optional */
  /*  CSP PLMN Mode Bit */
  uint8_t reg_csp_plmn_mode_bit_valid;  /**< Must be set to true if reg_csp_plmn_mode_bit is being passed */
  uint8_t reg_csp_plmn_mode_bit;
  /**<   Controls the reporting of QMI_NAS_CSP_PLMN_MODE_BIT_IND. Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable (default value) 
  */

  /* Optional */
  /*  RTRE Configuration */
  uint8_t reg_rtre_cfg_valid;  /**< Must be set to true if reg_rtre_cfg is being passed */
  uint8_t reg_rtre_cfg;
  /**<   Controls the reporting of QMI_NAS_RTRE_CONFIG_IND. Values: \n
       - 0x00 -- Disable (default value) \n
       - 0x01 -- Enable
   */

  /* Optional */
  /*  IMS Preference Status */
  uint8_t reg_ims_pref_status_valid;  /**< Must be set to true if reg_ims_pref_status is being passed */
  uint8_t reg_ims_pref_status;
  /**<   Controls the reporting of QMI_NAS_IMS_PREF_STATUS_IND. Values: \n
       - 0x00 -- Disable (default value) \n
       - 0x01 -- Enable
   */

  /* Optional */
  /*  E911 State Ready Status */
  uint8_t reg_e911_state_ready_status_valid;  /**< Must be set to true if reg_e911_state_ready_status is being passed */
  uint8_t reg_e911_state_ready_status;
  /**<   Controls the reporting of QMI_NAS_E911_STATE_READY_IND. Values: \n
       - 0x00 -- Disable (default value) \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  LTE SIB16 Network Time */
  uint8_t reg_lte_sib16_network_time_valid;  /**< Must be set to true if reg_lte_sib16_network_time is being passed */
  uint8_t reg_lte_sib16_network_time;
  /**<   Controls the reporting of QMI_NAS_LTE_SIB16_NETWORK_TIME_IND. Values: \n
       - 0x00 -- Disable (default value) \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  LTE Physical Carrier Aggregation Information */
  uint8_t reg_lte_cphy_ca_valid;  /**< Must be set to true if reg_lte_cphy_ca is being passed */
  uint8_t reg_lte_cphy_ca;
  /**<   Controls the reporting of QMI_NAS_LTE_CPHY_CA_IND. Values: \n
       - 0x00 -- Disable (default value) \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  Subscription Change */
  uint8_t reg_subscription_change_valid;  /**< Must be set to true if reg_subscription_change is being passed */
  uint8_t reg_subscription_change;
  /**<   Controls the reporting of QMI_NAS_SUBSCRIPTION_CHANGE_IND. Values: \n
       - 0x00 -- Disable (default value) \n
       - 0x01 -- Enable
     */

  /* Optional */
  /*  Service-Specific Access Class Barring */
  uint8_t reg_ssac_info_valid;  /**< Must be set to true if reg_ssac_info is being passed */
  uint8_t reg_ssac_info;
  /**<   Controls the reporting of QMI_NAS_SSAC_INFO_IND. Values: \n
       - 0x00 -- Disable (default value) \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  T3402 Timer Value */
  uint8_t reg_emm_t3402_change_valid;  /**< Must be set to true if reg_emm_t3402_change is being passed */
  uint8_t reg_emm_t3402_change;
  /**<   Controls the reporting of QMI_NAS_EMM_T3402_CHANGED_IND. Values: \n
       - 0x00 -- Disable (default value) \n
       - 0x01 -- Enable
    */

  /* Optional */
  /*  Access Class Barring */
  uint8_t reg_acb_info_change_valid;  /**< Must be set to true if reg_acb_info_change is being passed */
  uint8_t reg_acb_info_change;
  /**<   Controls the reporting of QMI_NAS_ACB_INFO_IND. Values: \n
       - 0x00 -- Disable (default value) \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  Data Subscription Priority */
  uint8_t reg_data_subs_priority_change_valid;  /**< Must be set to true if reg_data_subs_priority_change is being passed */
  uint8_t reg_data_subs_priority_change;
  /**<   Controls the reporting of QMI_NAS_DATA_SUBS_PRIORITY_IND. Values: \n
       - 0x00 -- Disable (default value) \n
       - 0x01 -- Enable
     */

  /* Optional */
  /*  T3346 Timer Status Change */
  uint8_t reg_t3346_timer_status_change_valid;  /**< Must be set to true if reg_t3346_timer_status_change is being passed */
  uint8_t reg_t3346_timer_status_change;
  /**<   Controls the reporting of QMI_NAS_T3346_TIMER_STATUS_CHANGE_ IND. Values: \n
       - 0x00 -- Disable (default value) \n
       - 0x01 -- Enable
    */

  /* Optional */
  /*  Call Mode Status */
  uint8_t reg_call_mode_change_valid;  /**< Must be set to true if reg_call_mode_change is being passed */
  uint8_t reg_call_mode_change;
  /**<   Controls the reporting of QMI_NAS_CALL_MODE_IND. Values: \n
       - 0x00 -- Disable (default value) \n
       - 0x01 -- Enable
    */

  /* Optional */
  /*  Service-Specific Access Class Barring Ext */
  uint8_t reg_ssac_change_info_valid;  /**< Must be set to true if reg_ssac_change_info is being passed */
  uint8_t reg_ssac_change_info;
  /**<   Controls the reporting of QMI_NAS_SSAC_CHANGE_INFO_IND. Values: \n
       - 0x00 -- Disable (default value) \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  Manual Network Scan Failure */
  uint8_t reg_manual_scan_fail_valid;  /**< Must be set to true if reg_manual_scan_fail is being passed */
  uint8_t reg_manual_scan_fail;
  /**<   Controls the reporting of QMI_NAS_MANUAL_SCAN_FAIL_IND. Values: \n
       - 0x00 -- Disable (default value) \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  Timer Expiry */
  uint8_t reg_timer_expiry_ind_valid;  /**< Must be set to true if reg_timer_expiry_ind is being passed */
  uint8_t reg_timer_expiry_ind;
  /**<   Controls the reporting of QMI_NAS_TIMER_EXPIRY IND. Values: \n
      - 0x00 -- Disable (default value) \n
      - 0x01 -- Enable
  */

  /* Optional */
  /*  Emergency Mode Status */
  uint8_t reg_emergency_mode_status_ind_valid;  /**< Must be set to true if reg_emergency_mode_status_ind is being passed */
  uint8_t reg_emergency_mode_status_ind;
  /**<   Controls the reporting of QMI_NAS_EMERGENCY_MODE_STATUS_IND. Values: \n
      - 0x00 -- Disable (default value) \n
      - 0x01 -- Enable
  */

  /* Optional */
  /*  Gcell Info */
  uint8_t reg_gcell_info_ind_valid;  /**< Must be set to true if reg_gcell_info_ind is being passed */
  uint8_t reg_gcell_info_ind;
  /**<   Controls the reporting of QMI_NAS_GCELL_INFO_IND. Values: \n
      - 0x00 -- Disable (default value) \n
      - 0x01 -- Enable
  */

  /* Optional */
  /*  eDRX Change Info */
  uint8_t reg_edrx_change_info_ind_valid;  /**< Must be set to true if reg_edrx_change_info_ind is being passed */
  uint8_t reg_edrx_change_info_ind;
  /**<   Controls the reporting of QMI_NAS_EDRX_CHANGE_INFO_IND. Values: \n
      - 0x00 -- Disable (default value) \n
      - 0x01 -- Enable
  */

  /* Optional */
  /*  LTE RACH Failure Indication */
  uint8_t reg_lte_rach_fail_ind_valid;  /**< Must be set to true if reg_lte_rach_fail_ind is being passed */
  uint8_t reg_lte_rach_fail_ind;
  /**<   Controls the reporting of QMI_NAS_LTE_RACH_FAIL_IND. Values: \n
      - 0x00 -- Disable (default value) \n
      - 0x01 -- Enable
  */

  /* Optional */
  /*  LTE RRC Tx Info */
  uint8_t lte_rrc_tx_info_ind_valid;  /**< Must be set to true if lte_rrc_tx_info_ind is being passed */
  uint8_t lte_rrc_tx_info_ind;
  /**<   Controls the reporting of QMI_NAS_LTE_RRC_TX_INFO_IND. Values: \n
      - 0x00 -- Disable (default value) \n
      - 0x01 -- Enable
  */

  /* Optional */
  /*  SUB Blocked Status Info */
  uint8_t nas_sub_blocked_status_ind_valid;  /**< Must be set to true if nas_sub_blocked_status_ind is being passed */
  uint8_t nas_sub_blocked_status_ind;
  /**<   Controls the reporting of QMI_NAS_SUB_BLOCKED_STATUS_IND. Values: \n
      - 0x00 -- Disable (default value) \n
      - 0x01 -- Enable
  */

  /* Optional */
  /*  E911 Search Failure Indication */
  uint8_t reg_e911_search_fail_ind_valid;  /**< Must be set to true if reg_e911_search_fail_ind is being passed */
  uint8_t reg_e911_search_fail_ind;
  /**<   Controls the reporting of QMI_NAS_E911_SEARCH_FAIL_IND. Values: \n
      - 0x00 -- Disable (default value) \n
      - 0x01 -- Enable
  */

  /* Optional */
  /*  Reg V2X Status Info */
  uint8_t reg_v2x_status_ind_valid;  /**< Must be set to true if reg_v2x_status_ind is being passed */
  uint8_t reg_v2x_status_ind;
  /**<   Controls the reporting of QMI_NAS_V2X_STATUS_INFO_IND. Values: \n
      - 0x00 -- Disable (default value) \n
      - 0x01 -- Enable
  */

  /* Optional */
  /*  Reg ARFCN_List Indication */
  uint8_t reg_arfcn_list_ind_valid;  /**< Must be set to true if reg_arfcn_list_ind is being passed */
  uint8_t reg_arfcn_list_ind;
  /**<   Controls the reporting of QMI_NAS_ARFCN_LIST_IND. Values: \n
      - 0x00 -- Disable (default value) \n
      - 0x01 -- Enable
  */

  /* Optional */
  /*  Reg 5G Modem Vote Indication */
  uint8_t reg_5g_modem_vote_ind_valid;  /**< Must be set to true if reg_5g_modem_vote_ind is being passed */
  uint8_t reg_5g_modem_vote_ind;
  /**<   Controls the reporting of QMI_NAS_5G_MODEM_VOTE_IND. Values: \n
      - 0x00 -- Disable (default value) \n
      - 0x01 -- Enable
  */

  /* Optional */
  /*  Reg RF Availability Indication */
  uint8_t reg_rf_availability_ind_valid;  /**< Must be set to true if reg_rf_availability_ind is being passed */
  uint8_t reg_rf_availability_ind;
  /**<   Controls the reporting of QMI_NAS_RF_AVAILABILITY_IND. Values: \n
      - 0x00 -- Disable (default value) \n
      - 0x01 -- Enable
  */

  /* Optional */
  /*  T3502 Timer Value */
  uint8_t reg_mm5g_t3502_change_valid;  /**< Must be set to true if reg_mm5g_t3502_change is being passed */
  uint8_t reg_mm5g_t3502_change;
  /**<   Controls the reporting of QMI_NAS_MM5G_T3502_CHANGED_IND. Values: \n
       - 0x00 -- Disable (default value) \n
       - 0x01 -- Enable
    */

  /* Optional */
  /*  Reg Call Ready Indication */
  uint8_t reg_call_ready_ind_valid;  /**< Must be set to true if reg_call_ready_ind is being passed */
  uint8_t reg_call_ready_ind;
  /**<   Controls the reporting of QMI_NAS_CALL_READY_IND. Values: \n
      - 0x00 -- Disable (default value) \n
      - 0x01 -- Enable
  */

  /* Optional */
  /*  Reg UAC Result Notification Indication */
  uint8_t reg_uac_result_ind_valid;  /**< Must be set to true if reg_uac_result_ind is being passed */
  uint8_t reg_uac_result_ind;
  /**<   Controls the reporting of QMI_NAS_UAC_RESULT_NOTIFICATION_IND. Values: \n
      - 0x00 -- Disable (default value) \n
      - 0x01 -- Enable
  */
}nas_indication_register_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets the registration state for different
              QMI_NAS indications for the requesting control point.
              \label{idl:indicationRegister} */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_indication_register_resp_msg_v01;  /* Message */
/**
    @}
  */

typedef uint16_t nas_get_sig_str_req_mask_type_v01;
#define QMI_NAS_REQUEST_SIG_INFO_RSSI_MASK_V01 ((nas_get_sig_str_req_mask_type_v01)0x01) 
#define QMI_NAS_REQUEST_SIG_INFO_ECIO_MASk_V01 ((nas_get_sig_str_req_mask_type_v01)0x02) 
#define QMI_NAS_REQUEST_SIG_INFO_IO_MASK_V01 ((nas_get_sig_str_req_mask_type_v01)0x04) 
#define QMI_NAS_REQUEST_SIG_INFO_SINR_MASK_V01 ((nas_get_sig_str_req_mask_type_v01)0x08) 
#define QMI_NAS_REQUEST_SIG_INFO_ERROR_RATE_MASK_V01 ((nas_get_sig_str_req_mask_type_v01)0x10) 
#define QMI_NAS_REQUEST_SIG_INFO_RSRQ_MASK_V01 ((nas_get_sig_str_req_mask_type_v01)0x20) 
#define QMI_NAS_REQUEST_SIG_INFO_LTE_SNR_MASK_V01 ((nas_get_sig_str_req_mask_type_v01)0x40) 
#define QMI_NAS_REQUEST_SIG_INFO_LTE_RSRP_MASK_V01 ((nas_get_sig_str_req_mask_type_v01)0x80) 
/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Queries the current signal strength as measured by the device.
              (Deprecated) */
typedef struct {

  /* Optional */
  /*  Request Mask */
  uint8_t request_mask_valid;  /**< Must be set to true if request_mask is being passed */
  nas_get_sig_str_req_mask_type_v01 request_mask;
  /**<   Request additional signal information for: \n
       Bit 0 (0x01) -- QMI_NAS_REQUEST_SIG_INFO_ RSSI_MASK; values: \n
       - 0 -- Do not request additional information for RSSI \n
       - 1 -- Request additional information for RSSI

       Bit 1 (0x02) -- QMI_NAS_REQUEST_SIG_INFO_ ECIO_MASK; values: \n
       - 0 -- Do not request additional information for ECIO \n
       - 1 -- Request additional information for ECIO

       Bit 2 (0x04) -- QMI_NAS_REQUEST_SIG_INFO_ IO_MASK; values: \n
       - 0 -- Do not request additional information for IO \n
       - 1 -- Request additional information for IO

       Bit 3 (0x08) -- QMI_NAS_REQUEST_SIG_INFO_ SINR_MASK; values: \n
       - 0 -- Do not request additional information for SINR \n
       - 1 -- Request additional information for SINR
   
       Bit 4 (0x10) -- QMI_NAS_REQUEST_SIG_INFO_ ERROR_RATE_MASK; values: \n
       - 0 -- Do not request additional information for Error Rate \n
       - 1 -- Request additional information for Error Rate

       Bit 5 (0x20) -- QMI_NAS_REQUEST_SIG_INFO_ RSRQ_MASK; values: \n
       - 0 -- Do not request additional information for RSRQ \n
       - 1 -- Request additional information for RSRQ

       Bit 6 (0x40) -- QMI_NAS_REQUEST_SIG_INFO_ LTE_SNR_MASK; values: \n
       - 0 -- Do not request additional information for LTE SNR \n
       - 1 -- Request additional information for LTE SNR 

       Bit 7 (0x80) -- QMI_NAS_REQUEST_SIG_INFO_ LTE_RSRP_MASK; values: \n
       - 0 -- Do not request additional information for LTE RSRP \n
       - 1 -- Request additional information for LTE RSRP 
  */
}nas_get_signal_strength_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  int8_t sig_strength;
  /**<   Received signal strength in dBm:                            \n
       - For CDMA and UMTS, this indicates forward link pilot Ec   \n
       - For GSM, this indicates received signal strength
  */

  nas_radio_if_enum_v01 radio_if;
  /**<   Radio interface technology of the signal being measured. Values: \n
       -0x01 -- RADIO_IF_CDMA_1X         -- 
        cdma2000\textsuperscript{\textregistered} 1X                 \n
       -0x02 -- RADIO_IF_CDMA_1XEVDO     -- 
        cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO)
  */
}nas_signal_strength_list_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Queries the current signal strength as measured by the device.
              (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
   */

  /* Mandatory */
  /*  Signal Strength */
  nas_signal_strength_type_v01 signal_strength;

  /* Optional */
  /*  Signal Strength List */
  uint8_t signal_strength_list_valid;  /**< Must be set to true if signal_strength_list is being passed */
  uint32_t signal_strength_list_len;  /**< Must be set to # of elements in signal_strength_list */
  nas_signal_strength_list_type_v01 signal_strength_list[NAS_SIG_STRENGTH_LIST_MAX_V01];

  /* Optional */
  /*  RSSI List */
  uint8_t rssi_valid;  /**< Must be set to true if rssi is being passed */
  uint32_t rssi_len;  /**< Must be set to # of elements in rssi */
  nas_rssi_type_v01 rssi[NAS_RSSI_LIST_MAX_V01];

  /* Optional */
  /*  ECIO List */
  uint8_t ecio_valid;  /**< Must be set to true if ecio is being passed */
  uint32_t ecio_len;  /**< Must be set to # of elements in ecio */
  nas_ecio_type_v01 ecio[NAS_ECIO_LIST_MAX_V01];

  /* Optional */
  /*  IO */
  uint8_t io_valid;  /**< Must be set to true if io is being passed */
  uint32_t io;
  /**<   Received IO in dBm. IO is only applicable for 1xEV-DO.
  */

  /* Optional */
  /*  SINR */
  uint8_t sinr_valid;  /**< Must be set to true if sinr is being passed */
  nas_sinr_enum_v01 sinr;
  /**<   SINR level. SINR is only applicable for 1xEV-DO.
       Valid levels are 0 to 8, where the maximum value for:        \n
       - 0x00 -- SINR_LEVEL_0 is -9 dB     \n
       - 0x01 -- SINR_LEVEL_1 is -6 dB     \n
       - 0x02 -- SINR_LEVEL_2 is -4.5 dB   \n
       - 0x03 -- SINR_LEVEL_3 is -3 dB     \n
       - 0x04 -- SINR_LEVEL_4 is -2 dB     \n
       - 0x05 -- SINR_LEVEL_5 is +1 dB     \n
       - 0x06 -- SINR_LEVEL_6 is +3 dB     \n
       - 0x07 -- SINR_LEVEL_7 is +6 dB     \n
       - 0x08 -- SINR_LEVEL_8 is +9 dB
  */

  /* Optional */
  /*  Error Rate List */
  uint8_t error_rate_valid;  /**< Must be set to true if error_rate is being passed */
  uint32_t error_rate_len;  /**< Must be set to # of elements in error_rate */
  nas_error_rate_type_v01 error_rate[NAS_ERROR_RATE_LIST_MAX_V01];

  /* Optional */
  /*  RSRQ */
  uint8_t rsrq_valid;  /**< Must be set to true if rsrq is being passed */
  nas_rsrq_type_v01 rsrq;

  /* Optional */
  /*  LTE SNR */
  uint8_t snr_valid;  /**< Must be set to true if snr is being passed */
  int16_t snr;
  /**<   LTE SNR level as a scaled integer in units of 0.1 dB; 
       e.g., -16 dB has a value of -160 and 24.6 dB has a value of 246.
       LTE SNR is included only when the current serving system is LTE.
      */

  /* Optional */
  /*  LTE RSRP */
  uint8_t lte_rsrp_valid;  /**< Must be set to true if lte_rsrp is being passed */
  int16_t lte_rsrp;
  /**<   Current LTE RSRP in dBm as measured by L1. 
       Range: -44 to -140 (-44 means -44 dBm, -140 means -140 dBm).
       LTE RSRP is included only if the current serving system is LTE.
    */
}nas_get_signal_strength_resp_msg_v01;  /* Message */
/**
    @}
  */

typedef uint8_t nas_network_type_mask_type_v01;
#define NAS_NETWORK_TYPE_GSM_ONLY_V01 ((nas_network_type_mask_type_v01)0x01) 
#define NAS_NETWORK_TYPE_WCDMA_ONLY_V01 ((nas_network_type_mask_type_v01)0x02) 
#define NAS_NETWORK_TYPE_LTE_ONLY_V01 ((nas_network_type_mask_type_v01)0x04) 
#define NAS_NETWORK_TYPE_TDSCDMA_ONLY_V01 ((nas_network_type_mask_type_v01)0x08) 
#define NAS_NETWORK_TYPE_NR5G_ONLY_V01 ((nas_network_type_mask_type_v01)0x10) 
/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_NW_SCAN_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_SCAN_TYPE_PLMN_V01 = 0x00, /**<  PLMN (default) \n  */
  NAS_SCAN_TYPE_CSG_V01 = 0x01, /**<  Closed subscriber group \n  */
  NAS_SCAN_TYPE_MODE_PREF_V01 = 0x02, /**<  Mode preference \n  */
  NAS_SCAN_TYPE_PCI_V01 = 0x03, /**<  Physical cell ID  */
  NAS_NW_SCAN_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_nw_scan_type_enum_v01;
/**
    @}
  */

typedef uint64_t nas_band_pref_mask_type_v01;
#define QMI_NAS_BAND_CLASS_0_A_SYSTEM_V01 ((nas_band_pref_mask_type_v01)0x000000000000001ull) /**<  Bit  0  -- Band Class 0, A-System \n   */
#define QMI_NAS_BAND_CLASS_0_B_AB_GSM850_V01 ((nas_band_pref_mask_type_v01)0x000000000000002ull) /**<  Bit  1  -- Band Class 0, B-System, Band Class 0 AB, GSM 850 band \n   */
#define QMI_NAS_BAND_CLASS_1_ALL_BLOCKS_V01 ((nas_band_pref_mask_type_v01)0x000000000000004ull) /**<  Bit  2  -- Band Class 1, all blocks \n   */
#define QMI_NAS_BAND_CLASS_2_PLACEHOLDER_V01 ((nas_band_pref_mask_type_v01)0x000000000000008ull) /**<  Bit  3  -- Band Class 2 placeholder \n   */
#define QMI_NAS_BAND_CLASS_3_A_SYSTEM_V01 ((nas_band_pref_mask_type_v01)0x000000000000010ull) /**<  Bit  4  -- Band Class 3, A-System \n   */
#define QMI_NAS_BAND_CLASS_4_ALL_BLOCKS_V01 ((nas_band_pref_mask_type_v01)0x000000000000020ull) /**<  Bit  5  -- Band Class 4, all blocks \n   */
#define QMI_NAS_BAND_CLASS_5_ALL_BLOCKS_V01 ((nas_band_pref_mask_type_v01)0x000000000000040ull) /**<  Bit  6  -- Band Class 5, all blocks \n   */
#define QMI_NAS_GSM_DCS_1800_BAND_V01 ((nas_band_pref_mask_type_v01)0x000000000000080ull) /**<  Bit  7  -- GSM DCS 1800 band \n   */
#define QMI_NAS_E_GSM_900_BAND_V01 ((nas_band_pref_mask_type_v01)0x000000000000100ull) /**<  Bit  8  -- GSM Extended GSM (E-GSM) 900 band \n   */
#define QMI_NAS_P_GSM_900_BAND_V01 ((nas_band_pref_mask_type_v01)0x000000000000200ull) /**<  Bit  9  -- GSM Primary GSM (P-GSM) 900 band \n   */
#define QMI_NAS_BAND_CLASS_6_V01 ((nas_band_pref_mask_type_v01)0x000000000000400ull) /**<  Bit  10  -- Band Class 6 \n   */
#define QMI_NAS_BAND_CLASS_7_V01 ((nas_band_pref_mask_type_v01)0x000000000000800ull) /**<  Bit  11  -- Band Class 7 \n   */
#define QMI_NAS_BAND_CLASS_8_V01 ((nas_band_pref_mask_type_v01)0x000000000001000ull) /**<  Bit  12  -- Band Class 8 \n   */
#define QMI_NAS_BAND_CLASS_9_V01 ((nas_band_pref_mask_type_v01)0x000000000002000ull) /**<  Bit  13  -- Band Class 9 \n   */
#define QMI_NAS_BAND_CLASS_10_V01 ((nas_band_pref_mask_type_v01)0x000000000004000ull) /**<  Bit  14  -- Band Class 10 \n   */
#define QMI_NAS_BAND_CLASS_11_V01 ((nas_band_pref_mask_type_v01)0x000000000008000ull) /**<  Bit  15  -- Band Class 11 \n   */
#define QMI_NAS_GSM_BAND_450_V01 ((nas_band_pref_mask_type_v01)0x000000000010000ull) /**<  Bit  16  -- GSM 450 band \n   */
#define QMI_NAS_GSM_BAND_480_V01 ((nas_band_pref_mask_type_v01)0x000000000020000ull) /**<  Bit  17  -- GSM 480 band \n   */
#define QMI_NAS_GSM_BAND_750_V01 ((nas_band_pref_mask_type_v01)0x000000000040000ull) /**<  Bit  18  -- GSM 750 band \n   */
#define QMI_NAS_GSM_BAND_850_V01 ((nas_band_pref_mask_type_v01)0x000000000080000ull) /**<  Bit  19  -- GSM 850 band \n   */
#define QMI_NAS_GSM_BAND_RAILWAYS_900_BAND_V01 ((nas_band_pref_mask_type_v01)0x000000000100000ull) /**<  Bit  20  -- GSM Railways GSM 900 band \n   */
#define QMI_NAS_GSM_BAND_PCS_1900_BAND_V01 ((nas_band_pref_mask_type_v01)0x000000000200000ull) /**<  Bit  21  -- GSM PCS 1900 band \n   */
#define QMI_NAS_WCDMA_EU_J_CH_IMT_2100_BAND_V01 ((nas_band_pref_mask_type_v01)0x000000000400000ull) /**<  Bit  22  -- WCDMA Europe, Japan, and China IMT 2100 band \n   */
#define QMI_NAS_WCDMA_US_PCS_1900_BAND_V01 ((nas_band_pref_mask_type_v01)0x000000000800000ull) /**<  Bit  23  -- WCDMA U.S. PCS 1900 band \n   */
#define QMI_NAS_EU_CH_DCS_1800_BAND_V01 ((nas_band_pref_mask_type_v01)0x000000001000000ull) /**<  Bit  24  -- WCDMA Europe and China DCS 1800 band \n   */
#define QMI_NAS_WCDMA_US_1700_BAND_V01 ((nas_band_pref_mask_type_v01)0x000000002000000ull) /**<  Bit  25  -- WCDMA U.S. 1700 band \n   */
#define QMI_NAS_WCDMA_US_850_BAND_V01 ((nas_band_pref_mask_type_v01)0x000000004000000ull) /**<  Bit  26  -- WCDMA U.S. 850 band \n   */
#define QMI_NAS_WCDMA_JAPAN_800_BAND_V01 ((nas_band_pref_mask_type_v01)0x000000008000000ull) /**<  Bit  27  -- WCDMA Japan 800 band \n   */
#define QMI_NAS_BAND_CLASS_12_V01 ((nas_band_pref_mask_type_v01)0x000000010000000ull) /**<  Bit  28  -- Band Class 12 \n   */
#define QMI_NAS_BAND_CLASS_14_V01 ((nas_band_pref_mask_type_v01)0x000000020000000ull) /**<  Bit  29  -- Band Class 14 \n   */
#define QMI_NAS_RESERVED_V01 ((nas_band_pref_mask_type_v01)0x000000040000000ull) /**<  Bit  30  -- Reserved \n   */
#define QMI_NAS_BAND_CLASS_15_V01 ((nas_band_pref_mask_type_v01)0x000000080000000ull) /**<  Bit  31  -- Band Class 15 \n   */
#define QMI_NAS_WCDMA_EU_2600_BAND_V01 ((nas_band_pref_mask_type_v01)0x001000000000000ull) /**<  Bit  48  -- WCDMA Europe 2600 band \n   */
#define QMI_NAS_WCDMA_EU_J_900_BAND_V01 ((nas_band_pref_mask_type_v01)0x002000000000000ull) /**<  Bit  49  -- WCDMA Europe and Japan 900 band \n   */
#define QMI_NAS_WCDMA_J_1700_BAND_V01 ((nas_band_pref_mask_type_v01)0x004000000000000ull) /**<  Bit  50  -- WCDMA Japan 1700 band \n   */
#define QMI_NAS_BAND_CLASS_16_V01 ((nas_band_pref_mask_type_v01)0x100000000000000ull) /**<  Bit  56  -- Band Class 16 \n   */
#define QMI_NAS_BAND_CLASS_17_V01 ((nas_band_pref_mask_type_v01)0x200000000000000ull) /**<  Bit  57  -- Band Class 17 \n   */
#define QMI_NAS_BAND_CLASS_18_V01 ((nas_band_pref_mask_type_v01)0x400000000000000ull) /**<  Bit  58  -- Band Class 18 \n   */
#define QMI_NAS_BAND_CLASS_19_V01 ((nas_band_pref_mask_type_v01)0x800000000000000ull) /**<  Bit  59  -- Band Class 19   */
#define QMI_NAS_WCDMA_JAPAN_850_BAND_V01 ((nas_band_pref_mask_type_v01)0x1000000000000000ull) /**<  Bit  60  -- WCDMA Japan 850 band \n   */
#define QMI_NAS_WCDMA_JAPAN_1500_BAND_V01 ((nas_band_pref_mask_type_v01)0x2000000000000000ull) /**<  Bit  61  -- WCDMA Japan 1500 band \n   */
typedef uint64_t lte_band_pref_mask_type_v01;
#define E_UTRA_OPERATING_BAND_1_V01 ((lte_band_pref_mask_type_v01)0x000000000000001ull) /**<  Bit  0  -- E-UTRA Operating Band 1 \n  */
#define E_UTRA_OPERATING_BAND_2_V01 ((lte_band_pref_mask_type_v01)0x000000000000002ull) /**<  Bit  1  -- E-UTRA Operating Band 2 \n  */
#define E_UTRA_OPERATING_BAND_3_V01 ((lte_band_pref_mask_type_v01)0x000000000000004ull) /**<  Bit  2  -- E-UTRA Operating Band 3 \n  */
#define E_UTRA_OPERATING_BAND_4_V01 ((lte_band_pref_mask_type_v01)0x000000000000008ull) /**<  Bit  3  -- E-UTRA Operating Band 4 \n  */
#define E_UTRA_OPERATING_BAND_5_V01 ((lte_band_pref_mask_type_v01)0x000000000000010ull) /**<  Bit  4  -- E-UTRA Operating Band 5 \n  */
#define E_UTRA_OPERATING_BAND_6_V01 ((lte_band_pref_mask_type_v01)0x000000000000020ull) /**<  Bit  5  -- E-UTRA Operating Band 6 \n  */
#define E_UTRA_OPERATING_BAND_7_V01 ((lte_band_pref_mask_type_v01)0x000000000000040ull) /**<  Bit  6  -- E-UTRA Operating Band 7 \n  */
#define E_UTRA_OPERATING_BAND_8_V01 ((lte_band_pref_mask_type_v01)0x000000000000080ull) /**<  Bit  7  -- E-UTRA Operating Band 8 \n  */
#define E_UTRA_OPERATING_BAND_9_V01 ((lte_band_pref_mask_type_v01)0x000000000000100ull) /**<  Bit  8  -- E-UTRA Operating Band 9 \n  */
#define E_UTRA_OPERATING_BAND_10_V01 ((lte_band_pref_mask_type_v01)0x000000000000200ull) /**<  Bit  9  -- E-UTRA Operating Band 10 \n  */
#define E_UTRA_OPERATING_BAND_11_V01 ((lte_band_pref_mask_type_v01)0x000000000000400ull) /**<  Bit  10 -- E-UTRA Operating Band 11 \n  */
#define E_UTRA_OPERATING_BAND_12_V01 ((lte_band_pref_mask_type_v01)0x000000000000800ull) /**<  Bit  11 -- E-UTRA Operating Band 12 \n  */
#define E_UTRA_OPERATING_BAND_13_V01 ((lte_band_pref_mask_type_v01)0x000000000001000ull) /**<  Bit  12 -- E-UTRA Operating Band 13 \n  */
#define E_UTRA_OPERATING_BAND_14_V01 ((lte_band_pref_mask_type_v01)0x000000000002000ull) /**<  Bit  13 -- E-UTRA Operating Band 14 \n  */
#define E_UTRA_OPERATING_BAND_17_V01 ((lte_band_pref_mask_type_v01)0x000000000010000ull) /**<  Bit  16 -- E-UTRA Operating Band 17 \n  */
#define E_UTRA_OPERATING_BAND_18_V01 ((lte_band_pref_mask_type_v01)0x000000000020000ull) /**<  Bit  17 -- E-UTRA Operating Band 18 \n  */
#define E_UTRA_OPERATING_BAND_19_V01 ((lte_band_pref_mask_type_v01)0x000000000040000ull) /**<  Bit  18 -- E-UTRA Operating Band 19 \n  */
#define E_UTRA_OPERATING_BAND_20_V01 ((lte_band_pref_mask_type_v01)0x000000000080000ull) /**<  Bit  19 -- E-UTRA Operating Band 20 \n  */
#define E_UTRA_OPERATING_BAND_21_V01 ((lte_band_pref_mask_type_v01)0x000000000100000ull) /**<  Bit  20 -- E-UTRA Operating Band 21 \n  */
#define E_UTRA_OPERATING_BAND_23_V01 ((lte_band_pref_mask_type_v01)0x000000000400000ull) /**<  Bit  22 -- E-UTRA Operating Band 23 \n  */
#define E_UTRA_OPERATING_BAND_24_V01 ((lte_band_pref_mask_type_v01)0x000000000800000ull) /**<  Bit  23 -- E-UTRA Operating Band 24 \n  */
#define E_UTRA_OPERATING_BAND_25_V01 ((lte_band_pref_mask_type_v01)0x000000001000000ull) /**<  Bit  24 -- E-UTRA Operating Band 25 \n  */
#define E_UTRA_OPERATING_BAND_26_V01 ((lte_band_pref_mask_type_v01)0x000000002000000ull) /**<  Bit  25 -- E-UTRA Operating Band 26 \n  */
#define E_UTRA_OPERATING_BAND_28_V01 ((lte_band_pref_mask_type_v01)0x000000008000000ull) /**<  Bit  27 -- E-UTRA Operating Band 28 \n  */
#define E_UTRA_OPERATING_BAND_29_V01 ((lte_band_pref_mask_type_v01)0x000000010000000ull) /**<  Bit  28 -- E-UTRA Operating Band 29 \n  */
#define E_UTRA_OPERATING_BAND_32_V01 ((lte_band_pref_mask_type_v01)0x000000020000000ull) /**<  Bit  29 -- E-UTRA Operating Band 32 \n  */
#define E_UTRA_OPERATING_BAND_30_V01 ((lte_band_pref_mask_type_v01)0x000000080000000ull) /**<  Bit  31 -- E-UTRA Operating Band 30 \n  */
#define E_UTRA_OPERATING_BAND_33_V01 ((lte_band_pref_mask_type_v01)0x000000100000000ull) /**<  Bit  32 -- E-UTRA Operating Band 33 \n  */
#define E_UTRA_OPERATING_BAND_34_V01 ((lte_band_pref_mask_type_v01)0x000000200000000ull) /**<  Bit  33 -- E-UTRA Operating Band 34 \n  */
#define E_UTRA_OPERATING_BAND_35_V01 ((lte_band_pref_mask_type_v01)0x000000400000000ull) /**<  Bit  34 -- E-UTRA Operating Band 35 \n  */
#define E_UTRA_OPERATING_BAND_36_V01 ((lte_band_pref_mask_type_v01)0x000000800000000ull) /**<  Bit  35 -- E-UTRA Operating Band 36 \n  */
#define E_UTRA_OPERATING_BAND_37_V01 ((lte_band_pref_mask_type_v01)0x000001000000000ull) /**<  Bit  36 -- E-UTRA Operating Band 37 \n  */
#define E_UTRA_OPERATING_BAND_38_V01 ((lte_band_pref_mask_type_v01)0x000002000000000ull) /**<  Bit  37 -- E-UTRA Operating Band 38 \n  */
#define E_UTRA_OPERATING_BAND_39_V01 ((lte_band_pref_mask_type_v01)0x000004000000000ull) /**<  Bit  38 -- E-UTRA Operating Band 39 \n  */
#define E_UTRA_OPERATING_BAND_40_V01 ((lte_band_pref_mask_type_v01)0x000008000000000ull) /**<  Bit  39 -- E-UTRA Operating Band 40 \n  */
#define E_UTRA_OPERATING_BAND_41_V01 ((lte_band_pref_mask_type_v01)0x000010000000000ull) /**<  Bit  40 -- E-UTRA Operating Band 41 \n  */
#define E_UTRA_OPERATING_BAND_42_V01 ((lte_band_pref_mask_type_v01)0x000020000000000ull) /**<  Bit  41 -- E-UTRA Operating Band 42 \n  */
#define E_UTRA_OPERATING_BAND_43_V01 ((lte_band_pref_mask_type_v01)0x000040000000000ull) /**<  Bit  42 -- E-UTRA Operating Band 43 \n  */
#define E_UTRA_OPERATING_BAND_46_V01 ((lte_band_pref_mask_type_v01)0x000200000000000ull) /**<  Bit  45 -- E-UTRA Operating Band 46 \n   */
#define E_UTRA_OPERATING_BAND_47_V01 ((lte_band_pref_mask_type_v01)0x000400000000000ull) /**<  Bit  46 -- E-UTRA Operating Band 47 \n  */
#define E_UTRA_OPERATING_BAND_48_V01 ((lte_band_pref_mask_type_v01)0x000800000000000ull) /**<  Bit  47 -- E-UTRA Operating Band 48 \n  */
#define E_UTRA_OPERATING_BAND_49_V01 ((lte_band_pref_mask_type_v01)0x001000000000000ull) /**<  Bit  48 -- E-UTRA Operating Band 49 \n  */
#define E_UTRA_OPERATING_BAND_125_V01 ((lte_band_pref_mask_type_v01)0x1000000000000000ull) /**<  Bit  60 -- E-UTRA Operating Band 125 \n  */
#define E_UTRA_OPERATING_BAND_126_V01 ((lte_band_pref_mask_type_v01)0x2000000000000000ull) /**<  Bit  61 -- E-UTRA Operating Band 126 \n  */
#define E_UTRA_OPERATING_BAND_127_V01 ((lte_band_pref_mask_type_v01)0x4000000000000000ull) /**<  Bit  62 -- E-UTRA Operating Band 127   */
/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint64_t bits_1_64;
  /**<   Bits 1 to 64 of the NR5G Operating Band bitmask*/

  uint64_t bits_65_128;
  /**<   Bits 65 to 128 of the NR5G Operating Band bitmask*/

  uint64_t bits_129_192;
  /**<   Bits 129 to 192 of the NR5G Operating Band bitmask*/

  uint64_t bits_193_256;
  /**<   Bits 193 to 256 of the NR5G Operating Band bitmask*/

  uint64_t bits_257_320;
  /**<   Bits 257 to 320 of the NR5G Operating Band bitmask*/

  uint64_t bits_321_384;
  /**<   Bits 321 to 384 of the NR5G Operating Band bitmask*/

  uint64_t bits_385_448;
  /**<   Bits 385 to 448 of the NR5G Operating Band bitmask*/

  uint64_t bits_449_512;
  /**<   Bits 449 to 512 of the NR5G Operating Band bitmask*/
}nas_nr5g_band_pref_mask_type_v01;  /* Type */
/**
    @}
  */

typedef uint64_t nas_tdscdma_band_pref_mask_type_v01;
#define NAS_TDSCDMA_BAND_A_V01 ((nas_tdscdma_band_pref_mask_type_v01)0x01ull) /**<  TD-SCDMA Band A \n  */
#define NAS_TDSCDMA_BAND_B_V01 ((nas_tdscdma_band_pref_mask_type_v01)0x02ull) /**<  TD-SCDMA Band B \n  */
#define NAS_TDSCDMA_BAND_C_V01 ((nas_tdscdma_band_pref_mask_type_v01)0x04ull) /**<  TD-SCDMA Band C \n  */
#define NAS_TDSCDMA_BAND_D_V01 ((nas_tdscdma_band_pref_mask_type_v01)0x08ull) /**<  TD-SCDMA Band D \n  */
#define NAS_TDSCDMA_BAND_E_V01 ((nas_tdscdma_band_pref_mask_type_v01)0x10ull) /**<  TD-SCDMA Band E \n  */
#define NAS_TDSCDMA_BAND_F_V01 ((nas_tdscdma_band_pref_mask_type_v01)0x20ull) /**<  TD-SCDMA Band F  */
/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_CAMPED_CIOT_LTE_OP_MODE_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_CIOT_SYS_MODE_NO_SRV_V01 = 0x00, /**<  No service \n  */
  NAS_CIOT_SYS_MODE_LTE_WB_V01 = 0x01, /**<  Camped on LTE wideband \n  */
  NAS_CIOT_SYS_MODE_LTE_M1_V01 = 0x02, /**<  Camped on LTE M1 \n  */
  NAS_CIOT_SYS_MODE_LTE_NB1_V01 = 0x03, /**<  Camped on LTE NB1  */
  NAS_CAMPED_CIOT_LTE_OP_MODE_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_camped_ciot_lte_op_mode_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint64_t bits_1_64;
  /**<   Bits 1 to 64 of the 256-bit LTE E-UTRA Operating Band bitmask*/

  uint64_t bits_65_128;
  /**<   Bits 65 to 128 of the 256-bit LTE E-UTRA Operating Band bitmask*/

  uint64_t bits_129_192;
  /**<   Bits 129 to 192 of the 256-bit LTE E-UTRA Operating Band bitmask*/

  uint64_t bits_193_256;
  /**<   Bits 193 to 256 of the 256-bit LTE E-UTRA Operating Band bitmask*/
}lte_band_pref_mask_ext_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_SCAN_SCOPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_SCAN_SCOPE_FULL_BAND_V01 = 0x00, /**<  FULL BAND scan (default) \n  */
  NAS_SCAN_SCOPE_ACQ_DB_V01 = 0x01, /**<  ACQ DB scan  */
  NAS_SCAN_SCOPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_scan_scope_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Performs a scan for visible networks. */
typedef struct {

  /* Optional */
  /*  Network Type */
  uint8_t network_type_valid;  /**< Must be set to true if network_type is being passed */
  nas_network_type_mask_type_v01 network_type;
  /**<   Bitmask representing the network type to scan. Values: \n
       - Bit 0 -- GSM \n
       - Bit 1 -- UMTS \n
       - Bit 2 -- LTE \n
       - Bit 3 -- TD-SCDMA \n
       Any combination of the bit positions can be used. If the mask is
       sent with no bits set, the scan is performed using the currently 
       set preference.
    */

  /* Optional */
  /*  Scan Type */
  uint8_t scan_type_valid;  /**< Must be set to true if scan_type is being passed */
  nas_nw_scan_type_enum_v01 scan_type;
  /**<   Network scan type. Values: \n
      - NAS_SCAN_TYPE_PLMN (0x00) --  PLMN (default) \n 
      - NAS_SCAN_TYPE_CSG (0x01) --  Closed subscriber group \n 
      - NAS_SCAN_TYPE_MODE_PREF (0x02) --  Mode preference \n 
      - NAS_SCAN_TYPE_PCI (0x03) --  Physical cell ID 
 */

  /* Optional */
  /*  Band Preference */
  uint8_t band_pref_valid;  /**< Must be set to true if band_pref is being passed */
  nas_band_pref_mask_type_v01 band_pref;
  /**<   Bitmask representing the band preference to be scanned.  
       See Table @latexonly\ref{tbl:bandPreference}@endlatexonly 
       for details.   
  */

  /* Optional */
  /*  LTE Band Preference */
  uint8_t lte_band_pref_valid;  /**< Must be set to true if lte_band_pref is being passed */
  lte_band_pref_mask_type_v01 lte_band_pref;
  /**<   Bitmask representing the LTE band preference to be scanned. 
       See Table @latexonly\ref{tbl:lteBandPreference}@endlatexonly 
       for details.  
  */

  /* Optional */
  /*  TDSCDMA Band Preference */
  uint8_t tdscdma_band_pref_valid;  /**< Must be set to true if tdscdma_band_pref is being passed */
  nas_tdscdma_band_pref_mask_type_v01 tdscdma_band_pref;
  /**<   Bitmask representing the TD-SCDMA band preference to be scanned. Values: \n
      - NAS_TDSCDMA_BAND_A (0x01) --  TD-SCDMA Band A \n 
      - NAS_TDSCDMA_BAND_B (0x02) --  TD-SCDMA Band B \n 
      - NAS_TDSCDMA_BAND_C (0x04) --  TD-SCDMA Band C \n 
      - NAS_TDSCDMA_BAND_D (0x08) --  TD-SCDMA Band D \n 
      - NAS_TDSCDMA_BAND_E (0x10) --  TD-SCDMA Band E \n 
      - NAS_TDSCDMA_BAND_F (0x20) --  TD-SCDMA Band F 

 \vspace{3pt}
 All other bits are reserved and must be set to 0.
 */

  /* Optional */
  /*  CIOT LTE Operational Mode Preference */
  uint8_t ciot_lte_op_mode_pref_valid;  /**< Must be set to true if ciot_lte_op_mode_pref is being passed */
  ciot_lte_op_mode_pref_mask_type_v01 ciot_lte_op_mode_pref;
  /**<   Bitmask representing the Cellular Internet of Things (CIoT) LTE operational
       mode preference. Values: \n
       - Bit 0 (0x01) -- QMI_NAS_CIOT_LTE_OP_ MODE_PREF_WB   -- LTE wideband (legacy LTE) \n
       - Bit 1 (0x02) -- QMI_NAS_CIOT_LTE_OP_ MODE_PREF_M1   -- LTE M1 \n
       - Bit 2 (0x04) -- QMI_NAS_CIOT_LTE_OP_ MODE_PREF_NB1  -- LTE NB1

       \vspace{3pt}
       All unlisted bits are reserved for future use and the service point
       ignores them if used.
  */

  /* Optional */
  /*  LTE M1 Band Preference (Deprecated; use LTE M1 Band Preference Extended) */
  uint8_t lte_m1_band_pref_valid;  /**< Must be set to true if lte_m1_band_pref is being passed */
  lte_band_pref_mask_type_v01 lte_m1_band_pref;
  /**<   Bitmask representing the LTE M1 band preference.
       See Table @latexonly\ref{tbl:lteBandPreference}@endlatexonly 
       for details.  
  */

  /* Optional */
  /*  LTE NB1 Band Preference (Deprecated; use LTE NB1 Band Preference Extended) */
  uint8_t lte_nb1_band_pref_valid;  /**< Must be set to true if lte_nb1_band_pref is being passed */
  lte_band_pref_mask_type_v01 lte_nb1_band_pref;
  /**<   Bitmask representing the LTE NB1 band preference.
       See Table @latexonly\ref{tbl:lteBandPreference}@endlatexonly 
       for details.  
  */

  /* Optional */
  /*  LTE M1 Band Preference Extended */
  uint8_t lte_m1_band_pref_ext_valid;  /**< Must be set to true if lte_m1_band_pref_ext is being passed */
  lte_band_pref_mask_ext_type_v01 lte_m1_band_pref_ext;
  /**<   Bitmask representing the LTE M1 band preference.
       See Table @latexonly\ref{tbl:lteBandPreference}@endlatexonly 
       for details.  
  */

  /* Optional */
  /*  LTE NB1 Band Preference Extended */
  uint8_t lte_nb1_band_pref_ext_valid;  /**< Must be set to true if lte_nb1_band_pref_ext is being passed */
  lte_band_pref_mask_ext_type_v01 lte_nb1_band_pref_ext;
  /**<   Bitmask representing the LTE NB1 band preference.
       See Table @latexonly\ref{tbl:lteBandPreference}@endlatexonly 
       for details.  
  */

  /* Optional */
  /*  Scan Scope */
  uint8_t scan_scope_valid;  /**< Must be set to true if scan_scope is being passed */
  nas_scan_scope_enum_v01 scan_scope;
  /**<   Scan scope. Values: \n
      - NAS_SCAN_SCOPE_FULL_BAND (0x00) --  FULL BAND scan (default) \n 
      - NAS_SCAN_SCOPE_ACQ_DB (0x01) --  ACQ DB scan 
 */
}nas_perform_network_scan_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_SCAN_RESULT_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_SCAN_SUCCESS_V01 = 0x00, 
  NAS_SCAN_AS_ABORT_V01 = 0x01, 
  NAS_SCAN_REJ_IN_RLF_V01 = 0x02, 
  NAS_SCAN_RESULT_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_scan_result_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t mobile_country_code;
  /**<   A 16-bit integer representation of MCC. Range: 0 to 999.
  */

  uint16_t mobile_network_code;
  /**<   A 16-bit integer representation of MNC. Range: 0 to 999.
  */

  uint8_t network_status;
  /**<   Status of the network identified by MCC and MNC preceding it.
       The status is encoded in a bitmapped value as follows: \n
       Bits 0-1 -- QMI_NAS_NETWORK_IN_USE_ STATUS_BITS    -- In-use status       \n
       - 0 -- QMI_NAS_NETWORK_IN_USE_STATUS_ UNKNOWN          -- Unknown         \n
       - 1 -- QMI_NAS_NETWORK_IN_USE_STATUS_ CURRENT_SERVING  -- Current serving \n
       - 2 -- QMI_NAS_NETWORK_IN_USE_STATUS_ AVAILABLE        -- Available
       
       Bits 2-3 -- QMI_NAS_NETWORK_ROAMING_ STATUS_BITS   -- Roaming status      \n
       - 0 -- QMI_NAS_NETWORK_ROAMING_ STATUS_UNKNOWN         -- Unknown         \n
       - 1 -- QMI_NAS_NETWORK_ROAMING_ STATUS_HOME            -- Home            \n
       - 2 -- QMI_NAS_NETWORK_ROAMING_ STATUS_ROAM            -- Roam

       Bits 4-5 -- QMI_NAS_NETWORK_FORBIDDEN_ STATUS_BITS -- Forbidden status    \n
       - 0 -- QMI_NAS_NETWORK_FORBIDDEN_ STATUS_UNKNOWN       -- Unknown         \n
       - 1 -- QMI_NAS_NETWORK_FORBIDDEN_ STATUS_FORBIDDEN     -- Forbidden       \n
       - 2 -- QMI_NAS_NETWORK_FORBIDDEN_ STATUS_NOT_FORBIDDEN -- Not forbidden

       Bits 6-7 -- QMI_NAS_NETWORK_PREFERRED_ STATUS_BITS -- Preferred status    \n
       - 0 -- QMI_NAS_NETWORK_PREFERRED_ STATUS_UNKNOWN       -- Unknown         \n
       - 1 -- QMI_NAS_NETWORK_PREFERRED_ STATUS_PREFERRED     -- Preferred       \n
       - 2 -- QMI_NAS_NETWORK_PREFERRED_ STATUS_NOT_PREFERRED -- Not preferred
  */

  char network_description[NAS_NETWORK_DESCRIPTION_MAX_V01 + 1];
  /**<   An optional string containing the network name or description.
  */
}nas_3gpp_network_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t mcc;
  /**<   A 16-bit integer representation of MCC. Range: 0 to 999.
  */

  uint16_t mnc;
  /**<   A 16-bit integer representation of MNC. Range: 0 to 999.
  */

  uint8_t rat;
  /**<   Radio access technology. Values: \n
       - 0x04 -- GERAN \n
       - 0x05 -- UMTS \n
       - 0x08 -- LTE \n
       - 0x09 -- TD-SCDMA 
  */
}nas_network_radio_access_technology_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t mcc;
  /**<   A 16-bit integer representation of MCC. Range: 0 to 999.
  */

  uint16_t mnc;
  /**<   A 16-bit integer representation of MNC. Range: 0 to 999.
  */

  nas_camped_ciot_lte_op_mode_enum_type_v01 lte_op_mode;
  /**<   Indicates the LTE mode of operation. Values: \n
      - NAS_CIOT_SYS_MODE_NO_SRV (0x00) --  No service \n 
      - NAS_CIOT_SYS_MODE_LTE_WB (0x01) --  Camped on LTE wideband \n 
      - NAS_CIOT_SYS_MODE_LTE_M1 (0x02) --  Camped on LTE M1 \n 
      - NAS_CIOT_SYS_MODE_LTE_NB1 (0x03) --  Camped on LTE NB1 
 */
}nas_scanned_ciot_lte_op_mode_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t mcc;
  /**<   A 16-bit integer representation of MCC. Range: 0 to 999.
  */

  uint16_t mnc;
  /**<   A 16-bit integer representation of MNC. Range: 0 to 999.
  */

  /*  MNC PCS digit include status */
  uint8_t mnc_includes_pcs_digit;
  /**<   This field is used to interpret the length of the corresponding
       MNC reported in the TLVs (in this table) with an mnc or 
       mobile_network_code field. Values: \n

       - TRUE  -- MNC is a three-digit value; e.g., a reported value of 
                  90 corresponds to an MNC value of 090  \n
       - FALSE -- MNC is a two-digit value; e.g., a reported value of 
                  90 corresponds to an MNC value of 90
  */
}nas_mnc_pcs_digit_include_status_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t id;
  /**<   Closed subscriber group identifier.
  */

  uint32_t name_len;  /**< Must be set to # of elements in name */
  uint16_t name[NAS_CSG_NAME_MAX_V01];
  /**<   Home Node B (HNB) or Home eNode B (HeNB) name in UTF-16.
       The network name is not guaranteed to be NULL terminated.
  */
}nas_csg_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_CSG_LIST_CAT_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_CSG_LIST_CAT_UNKNOWN_V01 = 0, /**<  Unknown CSG list.  */
  NAS_CSG_LIST_CAT_ALLOWED_V01 = 1, /**<  Allowed CSG list.  */
  NAS_CSG_LIST_CAT_OPERATOR_V01 = 2, /**<  Operator CSG list.  */
  NAS_CSG_LIST_CAT_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_csg_list_cat_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t mcc;
  /**<   A 16-bit integer representation of MCC. Range: 0 to 999.
  */

  uint16_t mnc;
  /**<   A 16-bit integer representation of MNC. Range: 0 to 999.
  */

  nas_csg_list_cat_enum_v01 csg_list_cat;
  /**<   Closed subscriber group category. Values: \n
       - 0 -- NAS_CSG_LIST_CAT_UNKNOWN -- Unknown CSG list \n
       - 1 -- NAS_CSG_LIST_CAT_ALLOWED -- Allowed CSG list \n
       - 2 -- NAS_CSG_LIST_CAT_OPERATOR -- Operator CSG list
  */

  nas_csg_info_type_v01 csg_info;
  /**<   Closed subscriber group information.
  */
}nas_csg_nw_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t mcc;
  /**<   A 16-bit integer representation of MCC. Range: 0 to 999.
  */

  uint16_t mnc;
  /**<   A 16-bit integer representation of MNC. Range: 0 to 999.
  */

  uint32_t csg_id;
  /**<   Closed subscriber group identifier.
  */

  int32_t signal_strength;
  /**<   Signal strength information in dBm.
  */
}nas_csg_nw_signal_strength_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_NW_NAME_SOURCE_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_NW_NAME_SOURCE_UNKNOWN_V01 = 0x00, /**<  Unknown \n  */
  NAS_NW_NAME_SOURCE_OPL_PNN_V01 = 0x01, /**<  Operator PLMN list and PLMN network name \n  */
  NAS_NW_NAME_SOURCE_CPHS_ONS_V01 = 0x02, /**<  Common PCN handset specification and operator name string \n  */
  NAS_NW_NAME_SOURCE_NITZ_V01 = 0x03, /**<  Network identity and time zone \n  */
  NAS_NW_NAME_SOURCE_SE13_V01 = 0x04, /**<  GSMA SE13 table \n  */
  NAS_NW_NAME_SOURCE_MCC_MNC_V01 = 0x05, /**<  Mobile country code and mobile network code \n  */
  NAS_NW_NAME_SOURCE_SPN_V01 = 0x06, /**<  Service provider name  */
  NAS_NW_NAME_SOURCE_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_nw_name_source_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  MCC */
  uint16_t mcc;
  /**<   A 16-bit integer representation of MCC. Range: 0 to 999.
  */

  /*  MNC */
  uint16_t mnc;
  /**<   A 16-bit integer representation of MNC. Range: 0 to 999.
  */

  /*  MNC PCS digit include status */
  uint8_t mnc_includes_pcs_digit;
  /**<   This field is used to interpret the length of the corresponding
       MNC reported in this TLV. Values: \n

       - TRUE  -- MNC is a three-digit value; e.g., a reported value of 
                  90 corresponds to an MNC value of 090  \n
       - FALSE -- MNC is a two-digit value; e.g., a reported value of 
                  90 corresponds to an MNC value of 90
  */
}nas_plmn_id_ext_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Absolute cell's frequency */
  uint32_t freq;
  /**<   Absolute cell's frequency. Range: 0 to 65535.
  */

  /*   Cell ID */
  uint16_t cell_id;
  /**<   Cell ID
  */

  /*  Global cell ID */
  uint32_t global_cell_id;
  /**<   Global cell ID
  */

  /*  PLMN ID */
  uint32_t plmn_len;  /**< Must be set to # of elements in plmn */
  nas_plmn_id_ext_type_v01 plmn[NAS_PCI_SCAN_MAX_NUM_PLMN_V01];
}nas_pci_scan_cell_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*   RSRP */
  int16_t rsrp;
  /**<   Combined RSRP */

  /*   RX0 RSRP */
  int16_t rsrp_rx0;
  /**<   Rx0 RSRP */

  /*   RX1 RSRP */
  int16_t rsrp_rx1;
  /**<   Rx1 RSRP */

  /*   Combined RSRQ */
  int16_t rsrq;
  /**<   Combined RSRQ */

  /*   RX0 RSRQ */
  int16_t rsrq_rx0;
  /**<   Rx0 RSRQ */

  /*   RX1 RSRQ */
  int16_t rsrq_rx1;
  /**<   Rx1 RSRQ */
}nas_pci_scan_signal_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t pci_cell_info_len;  /**< Must be set to # of elements in pci_cell_info */
  nas_pci_scan_cell_info_type_v01 pci_cell_info[NAS_PCI_SCAN_LIST_MAX_V01];

  nas_pci_scan_signal_info_type_v01 signal_info;
}nas_pci_nw_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Performs a scan for visible networks. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. 
 Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */

  /* Optional */
  /*  3GPP Network Information** */
  uint8_t nas_3gpp_network_info_valid;  /**< Must be set to true if nas_3gpp_network_info is being passed */
  uint32_t nas_3gpp_network_info_len;  /**< Must be set to # of elements in nas_3gpp_network_info */
  nas_3gpp_network_info_type_v01 nas_3gpp_network_info[NAS_3GPP_NETWORK_INFO_LIST_MAX_V01];

  /* Optional */
  /*  Network Radio Access Technology** */
  uint8_t nas_network_radio_access_technology_valid;  /**< Must be set to true if nas_network_radio_access_technology is being passed */
  uint32_t nas_network_radio_access_technology_len;  /**< Must be set to # of elements in nas_network_radio_access_technology */
  nas_network_radio_access_technology_type_v01 nas_network_radio_access_technology[NAS_3GPP_NETWORK_INFO_LIST_MAX_V01];

  /* Optional */
  /*  MNC PCS Digit Include Status */
  uint8_t mnc_includes_pcs_digit_valid;  /**< Must be set to true if mnc_includes_pcs_digit is being passed */
  uint32_t mnc_includes_pcs_digit_len;  /**< Must be set to # of elements in mnc_includes_pcs_digit */
  nas_mnc_pcs_digit_include_status_type_v01 mnc_includes_pcs_digit[NAS_3GPP_NETWORK_INFO_LIST_MAX_V01];

  /* Optional */
  /*  Network Scan Result */
  uint8_t scan_result_valid;  /**< Must be set to true if scan_result is being passed */
  nas_scan_result_enum_v01 scan_result;
  /**<   Indicates the status of the network scan. Values: \n
       - 0x00 -- NAS_SCAN_SUCCESS -- Network scan was successful \n
       - 0x01 -- NAS_SCAN_AS_ABORT -- Network scan was aborted   \n
       - 0x02 -- NAS_SCAN_REJ_IN_RLF -- Network scan did not complete due 
                 to a radio link failure recovery in progress
  */

  /* Optional */
  /*  CSG Information */
  uint8_t csg_info_valid;  /**< Must be set to true if csg_info is being passed */
  uint32_t csg_info_len;  /**< Must be set to # of elements in csg_info */
  nas_csg_nw_info_type_v01 csg_info[NAS_3GPP_NETWORK_INFO_LIST_MAX_V01];

  /* Optional */
  /*  CSG Signal Strength Information */
  uint8_t csg_sig_info_valid;  /**< Must be set to true if csg_sig_info is being passed */
  uint32_t csg_sig_info_len;  /**< Must be set to # of elements in csg_sig_info */
  nas_csg_nw_signal_strength_info_type_v01 csg_sig_info[NAS_3GPP_NETWORK_INFO_LIST_MAX_V01];

  /* Optional */
  /*  Network Name Source */
  uint8_t nw_name_source_valid;  /**< Must be set to true if nw_name_source is being passed */
  uint32_t nw_name_source_len;  /**< Must be set to # of elements in nw_name_source */
  nas_nw_name_source_enum_type_v01 nw_name_source[NAS_3GPP_NETWORK_INFO_LIST_MAX_V01];
  /**<   Network name source. Values: \n
      - NAS_NW_NAME_SOURCE_UNKNOWN (0x00) --  Unknown \n 
      - NAS_NW_NAME_SOURCE_OPL_PNN (0x01) --  Operator PLMN list and PLMN network name \n 
      - NAS_NW_NAME_SOURCE_CPHS_ONS (0x02) --  Common PCN handset specification and operator name string \n 
      - NAS_NW_NAME_SOURCE_NITZ (0x03) --  Network identity and time zone \n 
      - NAS_NW_NAME_SOURCE_SE13 (0x04) --  GSMA SE13 table \n 
      - NAS_NW_NAME_SOURCE_MCC_MNC (0x05) --  Mobile country code and mobile network code \n 
      - NAS_NW_NAME_SOURCE_SPN (0x06) --  Service provider name 
 */

  /* Optional */
  /*  PCI Information */
  uint8_t pci_plmn_info_valid;  /**< Must be set to true if pci_plmn_info is being passed */
  nas_pci_nw_info_type_v01 pci_plmn_info;

  /* Optional */
  /*  LTE Operational Mode */
  uint8_t lte_op_mode_valid;  /**< Must be set to true if lte_op_mode is being passed */
  uint32_t lte_op_mode_len;  /**< Must be set to # of elements in lte_op_mode */
  nas_scanned_ciot_lte_op_mode_type_v01 lte_op_mode[NAS_3GPP_NETWORK_INFO_LIST_MAX_V01];
}nas_perform_network_scan_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t mobile_country_code;
  /**<   A 16-bit integer representation of MCC. Range: 0 to 999.
  */

  uint16_t mobile_network_code;
  /**<   A 16-bit integer representation of MNC. Range: 0 to 999.
  */

  nas_radio_if_enum_v01 radio_access_technology;
  /**<   Radio access technology for which to register. Values: \n
        -0x04 -- RADIO_IF_GSM -- GSM \n
        -0x05 -- RADIO_IF_UMTS -- UMTS \n 
        -0x08 -- RADIO_IF_LTE -- LTE \n
        -  -1 -- RADIO_IF_NO_CHANGE -- No change in the mode preference
  */
}nas_manual_network_register_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_REGISTER_ACTION_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_AUTO_REGISTER_V01 = 0x01, 
  NAS_MANUAL_REGISTER_V01 = 0x02, 
  NAS_REGISTER_ACTION_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_register_action_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_CHANGE_DURATION_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_POWER_CYCLE_V01 = 0x00, 
  NAS_PERMANENT_V01 = 0x01, 
  NAS_CHANGE_DURATION_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_change_duration_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Initiates a network registration. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Register Action */
  nas_register_action_enum_v01 register_action;
  /**<    Specifies one of the following actions: \n
        - 0x01 -- NAS_AUTO_REGISTER -- Device registers according
          to its provisioning; optional TLVs supplied with the command
          are ignored \n
        - 0x02 -- NAS_MANUAL_REGISTER -- Device registers to a specified
          network; the optional Manual Network Register Information TLV must also
          be included for the command to process successfully;
          supported only for 3GPP
  */

  /* Optional */
  /*  Manual Network Register Information** */
  uint8_t manual_network_register_info_valid;  /**< Must be set to true if manual_network_register_info is being passed */
  nas_manual_network_register_info_type_v01 manual_network_register_info;

  /* Optional */
  /*  Change Duration** */
  uint8_t change_duration_valid;  /**< Must be set to true if change_duration is being passed */
  nas_change_duration_enum_v01 change_duration;
  /**<    Duration of the change. Values: \n
        - 0x00 -- Power cycle -- Remains active until the next device power cycle \n
        - 0x01 -- Permanent -- Remains active through power cycles until changed by the client \n
        Note: The device will use "0x00 -- Power cycle" as the default value 
              if the TLV is omitted.
  */

  /* Optional */
  /*  MNC PCS Digit Include Status */
  uint8_t mnc_includes_pcs_digit_valid;  /**< Must be set to true if mnc_includes_pcs_digit is being passed */
  uint8_t mnc_includes_pcs_digit;
  /**<    This TLV applies to the MNC field of the manual_network_register_info 
        data structure. Values: \n
        - TRUE  -- MNC is a three-digit value \n
        - FALSE -- MNC is a two-digit value

        If this TLV is not included in the case of a manual register option, 
        the value of the MNC value specified in manual_network_register_info 
        is interpreted as follows: \n
        - If the MNC value is less than 100, the MNC value provided is 
          interpreted as a two-digit value. \n
        - If the MNC value is greater than or equal to 100, the MNC value 
          provided is interpreted as a three-digit value.
  */
}nas_initiate_network_register_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Initiates a network registration. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_initiate_network_register_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_PS_ATTACH_ACTION_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_PS_ACTION_ATTACH_V01 = 0x01, 
  NAS_PS_ACTION_DETACH_V01 = 0x02, 
  NAS_PS_ATTACH_ACTION_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_ps_attach_action_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Initiates a domain attach or detach action. (Deprecated) */
typedef struct {

  /* Optional */
  /*  PS Attach Action** */
  uint8_t ps_attach_action_valid;  /**< Must be set to true if ps_attach_action is being passed */
  nas_ps_attach_action_enum_v01 ps_attach_action;
  /**<   Initiates a packet domain attach or detach action. Values: \n
       - 0x01 -- PS_ACTION_ATTACH -- Initiates an immediate packet domain attach action \n
       - 0x02 -- PS_ACTION_DETACH -- Initiates an immediate packet domain detach action 
  */
}nas_initiate_attach_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Initiates a domain attach or detach action. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_initiate_attach_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Queries information regarding the system that currently 
              provides service. (Deprecated) */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_serving_system_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_REGISTRATION_STATE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_NOT_REGISTERED_V01 = 0x00, 
  NAS_REGISTERED_V01 = 0x01, 
  NAS_NOT_REGISTERED_SEARCHING_V01 = 0x02, 
  NAS_REGISTRATION_DENIED_V01 = 0x03, 
  NAS_REGISTRATION_UNKNOWN_V01 = 0x04, 
  NAS_REGISTRATION_STATE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_registration_state_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_CS_ATTACH_STATE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_CS_UNKNOWN_V01 = 0x00, 
  NAS_CS_ATTACHED_V01 = 0x01, 
  NAS_CS_DETACHED_V01 = 0x02, 
  NAS_CS_ATTACH_STATE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_cs_attach_state_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_PS_ATTACH_STATE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_PS_UNKNOWN_V01 = 0x00, 
  NAS_PS_ATTACHED_V01 = 0x01, 
  NAS_PS_DETACHED_V01 = 0x02, 
  NAS_PS_ATTACH_STATE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_ps_attach_state_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_SELECTED_NETWORK_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_SELECTED_NETWORK_UNKNOWN_V01 = 0x00, 
  NAS_SELECTED_NETWORK_3GPP2_V01 = 0x01, 
  NAS_SELECTED_NETWORK_3GPP_V01 = 0x02, 
  NAS_SELECTED_NETWORK_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_selected_network_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_registration_state_enum_v01 registration_state;
  /**<   Registration state of the mobile. Values: \n
       - 0x00 -- NOT_REGISTERED        -- Not registered; mobile is not currently 
                                          searching for a new network to provide 
                                          service \n
       - 0x01 -- REGISTERED            -- Registered with a network \n
       - 0x02 -- NOT_REGISTERED_SEARCHING -- Not registered, but mobile is currently 
                                             searching for a new network to provide 
                                             service \n
       - 0x03 -- REGISTRATION_DENIED   -- Registration denied by the visible 
                                          network \n
       - 0x04 -- REGISTRATION_UNKNOWN  -- Registration state is unknown
  */

  nas_cs_attach_state_enum_v01 cs_attach_state;
  /**<   Circuit-switched domain attach state of the mobile. Values: \n
       - 0x00 -- CS_UNKNOWN  -- Unknown or not applicable \n
       - 0x01 -- CS_ATTACHED -- Attached \n
       - 0x02 -- CS_DETACHED -- Detached
  */

  nas_ps_attach_state_enum_v01 ps_attach_state;
  /**<   Packet-switched domain attach state of the mobile. Values: \n
       - 0x00 -- PS_UNKNOWN  -- Unknown or not applicable \n
       - 0x01 -- PS_ATTACHED -- Attached \n
       - 0x02 -- PS_DETACHED -- Detached
  */

  nas_selected_network_enum_v01 selected_network;
  /**<   Type of selected radio access network. Values: \n
       - 0x00 -- SELECTED_NETWORK_UNKNOWN -- Unknown \n
       - 0x01 -- SELECTED_NETWORK_3GPP2   -- 3GPP2 network \n
       - 0x02 -- SELECTED_NETWORK_3GPP    -- 3GPP network
  */

  uint32_t radio_if_len;  /**< Must be set to # of elements in radio_if */
  nas_radio_if_enum_v01 radio_if[NAS_RADIO_IF_LIST_MAX_V01];
  /**<   Radio interface currently in use. Values: \n
       -0x00 -- RADIO_IF_NO_SVC      -- None (no service) \n
       -0x01 -- RADIO_IF_CDMA_1X     -- 
        cdma2000\textsuperscript{\textregistered} 1X             \n
       -0x02 -- RADIO_IF_CDMA_1XEVDO -- 
        cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
       -0x03 -- RADIO_IF_AMPS        -- AMPS \n
       -0x04 -- RADIO_IF_GSM         -- GSM \n
       -0x05 -- RADIO_IF_UMTS        -- UMTS \n
       -0x08 -- RADIO_IF_LTE         -- LTE 
  */
}nas_serving_system_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t mobile_country_code;
  /**<   A 16-bit integer representation of MCC. Range: 0 to 999.*/

  uint16_t mobile_network_code;
  /**<   A 16-bit integer representation of MNC. Range: 0 to 999.*/

  char network_description[NAS_NETWORK_DESCRIPTION_MAX_V01 + 1];
  /**<   An optional string containing the network name or description.*/
}nas_plmn_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t sid;
  /**<   System ID. */

  uint16_t nid;
  /**<   Network ID.*/
}nas_cdma_system_id_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t base_id;
  /**<   Base station identification number.*/

  int32_t base_lat;
  /**<   
    Base station latitude in units of 0.25 sec, expressed as a two's
    complement signed number with positive numbers signifying North
    latitudes.
  */

  int32_t base_long;
  /**<   
    Base station longitude in units of 0.25 sec, expressed as a two's
    complement signed number with positive numbers signifying East
    longitude.
  */
}nas_cdma_base_station_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_ROAMING_INDICATOR_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_ROAMING_IND_ON_V01 = 0x00, 
  NAS_ROAMING_IND_OFF_V01 = 0x01, 
  NAS_ROAMING_IND_FLASHING_V01 = 0x02, 
  NAS_ROAMING_INDICATOR_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_roaming_indicator_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_radio_if_enum_v01 radio_if;
  /**<   Radio interface currently in use. Values: \n
       -0x01 -- RADIO_IF_CDMA_1X     -- 
        cdma2000\textsuperscript{\textregistered} 1X             \n
       -0x02 -- RADIO_IF_CDMA_1XEVDO -- 
        cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
       -0x03 -- RADIO_IF_AMPS        -- AMPS \n
       -0x04 -- RADIO_IF_GSM         -- GSM \n
       -0x05 -- RADIO_IF_UMTS        -- UMTS \n
       -0x08 -- RADIO_IF_LTE         -- LTE
  */

  nas_roaming_indicator_enum_v01 roaming_indicator;
  /**<   
    Roaming indicator. Values: \n
    -0x00 -- ROAMING_IND_ON                       -- Roaming \n
    -0x01 -- ROAMING_IND_OFF                      -- Home

    Values from 2 onward are applicable only for 3GPP2. Refer to 
    \hyperref[STD-CR1001F]{3GPP2 C.R1001-F} for the meanings of these values.
  */
}nas_roaming_indicator_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t lp_sec;
  /**<   Number of leap seconds since the start of CDMA system time.
  */

  int8_t ltm_offset;
  /**<    Offset of local time from system time in units of 30 min. The value in
        this field conveys the offset as an 8-bit two's complement number.
  */

  uint8_t daylt_savings;
  /**<   Daylight saving indicator. Values: \n
       - 0x00 -- OFF (daylight saving not in effect) \n
       - 0x01 -- ON (daylight saving in effect)
  */
}nas_3gpp_time_zone_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_DATA_CAPABILITES_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_DATA_CAPABILITIES_GPRS_V01 = 0x01, 
  NAS_DATA_CAPABILITIES_EDGE_V01 = 0x02, 
  NAS_DATA_CAPABILITIES_HSDPA_V01 = 0x03, 
  NAS_DATA_CAPABILITIES_HSUPA_V01 = 0x04, 
  NAS_DATA_CAPABILITIES_WCDMA_V01 = 0x05, 
  NAS_DATA_CAPABILITIES_CDMA_V01 = 0x06, 
  NAS_DATA_CAPABILITIES_EVDO_REV_O_V01 = 0x07, 
  NAS_DATA_CAPABILITIES_EVDO_REV_A_V01 = 0x08, 
  NAS_DATA_CAPABILITIES_GSM_V01 = 0x09, 
  NAS_DATA_CAPABILITIES_EVDO_REV_B_V01 = 0x0A, 
  NAS_DATA_CAPABILITIES_LTE_V01 = 0x0B, 
  NAS_DATA_CAPABILITIES_HSDPA_PLUS_V01 = 0x0C, 
  NAS_DATA_CAPABILITIES_DC_HSDPA_PLUS_V01 = 0x0D, 
  NAS_DATA_CAPABILITES_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_data_capabilites_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t srv_status;
  /**<   Service status. Values: \n
       - 0x00 -- No service \n
       - 0x01 -- Limited service \n
       - 0x02 -- Service available \n
       - 0x03 -- Limited regional service \n
       - 0x04 -- MS in power save or deep sleep
  */

  uint8_t srv_capability;
  /**<   System's service capability. Values: \n
      - 0x00 -- No service \n
      - 0x01 -- Circuit-switched only \n
      - 0x02 -- Packet-switched only \n
      - 0x03 -- Circuit-switched and-packet switched \n
      - 0x04 -- MS found the right system but not yet registered/attached 
  */

  uint8_t hdr_srv_status;
  /**<   HDR service status. Values: \n
      - 0x00 -- No service \n
      - 0x01 -- Limited service \n
      - 0x02 -- Service available \n
      - 0x03 -- Limited regional service \n
      - 0x04 -- MS in power save or deep sleep
  */

  uint8_t hdr_hybrid;
  /**<   HDR hybrid information. Values: \n
      - 0x00 -- System is not hybrid \n
      - 0x01 -- System is hybrid
  */

  uint8_t is_sys_forbidden;
  /**<   Forbidden system information. Values: \n
      - 0x00 -- System is not a forbidden system \n
      - 0x01 -- System is a forbidden system
  */
}nas_ss_detailed_service_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  MCC */
  uint16_t mcc;
  /**<   Mobile country code. 
  */

  /*  imsi_11_12 */
  uint8_t imsi_11_12;
  /**<   IMSI_11_12. 
  */
}nas_cdma_system_id_ext_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_HDR_PERSONALITY_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_HDR_PERSONALITY_UNKNOWN_V01 = 0x00, 
  NAS_HDR_PERSONALITY_HRPD_V01 = 0x01, 
  NAS_HDR_PERSONALITY_EHRPD_V01 = 0x02, 
  NAS_HDR_PERSONALITY_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_hdr_personality_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_CELL_ACCESS_STATUS_E_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_CELL_ACCESS_NORMAL_ONLY_V01 = 0x00, /**<  Cell access is allowed for normal calls only \n   */
  NAS_CELL_ACCESS_EMERGENCY_ONLY_V01 = 0x01, /**<  Cell access is allowed for emergency calls only \n   */
  NAS_CELL_ACCESS_NO_CALLS_V01 = 0x02, /**<  Cell access is not allowed for any call type \n   */
  NAS_CELL_ACCESS_ALL_CALLS_V01 = 0x03, /**<  Cell access is allowed for all call types \n   */
  NAS_CELL_ACCESS_UNKNOWN_V01 = -1, /**<  Cell access type is unknown   */
  NAS_CELL_ACCESS_STATUS_E_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_cell_access_status_e_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_cell_access_status_e_type_v01 cs_bar_status;
  /**<   
     Call barring status for circuit-switched calls. Values: \n
    - 0x00 -- NAS_CELL_ACCESS_NORMAL_ONLY     -- Cell access is allowed for normal calls only \n
    - 0x01 -- NAS_CELL_ACCESS_EMERGENCY_ ONLY -- Cell access is allowed for emergency calls only \n
    - 0x02 -- NAS_CELL_ACCESS_NO_CALLS        -- Cell access is not allowed for any call type \n
    - 0x03 -- NAS_CELL_ACCESS_ALL_CALLS       -- Cell access is allowed for all call types \n
    -   -1 -- NAS_CELL_ACCESS_UNKNOWN         -- Cell access type is unknown
  */

  nas_cell_access_status_e_type_v01 ps_bar_status;
  /**<  
     Call barring status for packet-switched calls. Values: \n
    - 0x00 -- NAS_CELL_ACCESS_NORMAL_ONLY     -- Cell access is allowed for normal calls only \n
    - 0x01 -- NAS_CELL_ACCESS_EMERGENCY_ ONLY -- Cell access is allowed for emergency calls only \n
    - 0x02 -- NAS_CELL_ACCESS_NO_CALLS        -- Cell access is not allowed for any call type \n
    - 0x03 -- NAS_CELL_ACCESS_ALL_CALLS       -- Cell access is allowed for all call types \n
    -   -1 -- NAS_CELL_ACCESS_UNKNOWN         -- Cell access type is unknown
  */
}nas_gw_sys_info3_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_HS_SUPPORT_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  SYS_HS_IND_HSDPA_HSUPA_UNSUPP_CELL_V01 = 0x00, /**<  HSDPA and HSUPA are unsupported \n  */
  SYS_HS_IND_HSDPA_SUPP_CELL_V01 = 0x01, /**<  HSDPA is supported \n  */
  SYS_HS_IND_HSUPA_SUPP_CELL_V01 = 0x02, /**<  HSUPA is supported \n  */
  SYS_HS_IND_HSDPA_HSUPA_SUPP_CELL_V01 = 0x03, /**<  HSDPA and HSUPA are supported  \n  */
  SYS_HS_IND_HSDPAPLUS_SUPP_CELL_V01 = 0x04, /**<  HSDPA+ is supported \n  */
  SYS_HS_IND_HSDPAPLUS_HSUPA_SUPP_CELL_V01 = 0x05, /**<  HSDPA+ and HSUPA are supported \n  */
  SYS_HS_IND_DC_HSDPAPLUS_SUPP_CELL_V01 = 0x06, /**<  Dual-cell HSDPA+ is supported \n  */
  SYS_HS_IND_DC_HSDPAPLUS_HSUPA_SUPP_CELL_V01 = 0x07, /**<  Dual-cell HSDPA+ and HSUPA are supported \n   */
  SYS_HS_IND_HSDPAPLUS_64QAM_HSUPA_SUPP_CELL_V01 = 0x08, /**<  Dual-cell HSDPA+, 64 QAM, and HSUPA are supported \n  */
  SYS_HS_IND_HSDPAPLUS_64QAM_SUPP_CELL_V01 = 0x09, /**<  Dual-cell HSDPA+ and 64 QAM are supported \n  */
  SYS_HS_IND_DC_HSDPAPLUS_DC_HSUPA_SUPP_CELL_V01 = 0x0A, /**<  Dual-cell HSDPA+ and dual-cell HSUPA are supported  */
  NAS_HS_SUPPORT_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_hs_support_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_CP_SMS_SERVICE_STATUS_E_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_CP_SMS_SERVICE_STATUS_NOT_AVAILABLE_V01 = 0x00, /**<  SMS service status  over CP is not available \n   */
  NAS_CP_SMS_SERVICE_STATUS_TEMP_FAILURE_V01 = 0x01, /**<  SMS service status  over CP is not available temporarily \n   */
  NAS_CP_SMS_SERVICE_STATUS_AVAILABLE_V01 = 0x02, /**<  SMS service status  over CP is available \n   */
  NAS_CP_SMS_SERVICE_STATUS_E_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_cp_sms_service_status_e_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Queries information regarding the system that currently 
              provides service. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */

  /* Mandatory */
  /*  Serving System */
  nas_serving_system_type_v01 serving_system;

  /* Optional */
  /*  Roaming Indicator Value */
  uint8_t roaming_indicator_valid;  /**< Must be set to true if roaming_indicator is being passed */
  nas_roaming_indicator_enum_v01 roaming_indicator;
  /**<   
    Roaming indicator. Values: \n
    -0x00 -- ROAMING_IND_ON                       -- Roaming \n
    -0x01 -- ROAMING_IND_OFF                      -- Home    \n
    -0x02 and above -- Operator-defined values
  */

  /* Optional */
  /*  Data Service Capability */
  uint8_t data_capabilities_valid;  /**< Must be set to true if data_capabilities is being passed */
  uint32_t data_capabilities_len;  /**< Must be set to # of elements in data_capabilities */
  nas_data_capabilites_enum_v01 data_capabilities[NAS_DATA_CAPABILITIES_LIST_MAX_V01];
  /**<   List of data capabilities (each is 1 byte) of the current
       serving system. Possible values: \n
       -0x01 -- DATA_CAPABILITIES_GPRS       -- GPRS \n
       -0x02 -- DATA_CAPABILITIES_EDGE       -- EDGE \n
       -0x03 -- DATA_CAPABILITIES_HSDPA      -- HSDPA \n
       -0x04 -- DATA_CAPABILITIES_HSUPA      -- HSUPA \n
       -0x05 -- DATA_CAPABILITIES_WCDMA      -- WCDMA \n
       -0x06 -- DATA_CAPABILITIES_CDMA       -- CDMA \n
       -0x07 -- DATA_CAPABILITIES_EVDO_REV_O -- EV-DO REV 0  \n
       -0x08 -- DATA_CAPABILITIES_EVDO_REV_A -- EV-DO REV A  \n
       -0x09 -- DATA_CAPABILITIES_GSM        -- GSM          \n
       -0x0A -- DATA_CAPABILITIES_EVDO_REV_B -- EV-DO REV B  \n
       -0x0B -- DATA_CAPABILITIES_LTE        -- LTE          \n
       -0x0C -- DATA_CAPABILITIES_HSDPA_PLUS -- HSDPA+       \n
       -0x0D -- DATA_CAPABILITIES_DC_HSDPA_ PLUS -- DC-HSDPA+
  */

  /* Optional */
  /*  Current PLMN */
  uint8_t current_plmn_valid;  /**< Must be set to true if current_plmn is being passed */
  nas_plmn_type_v01 current_plmn;

  /* Optional */
  /*  CDMA System ID */
  uint8_t cdma_system_id_valid;  /**< Must be set to true if cdma_system_id is being passed */
  nas_cdma_system_id_type_v01 cdma_system_id;

  /* Optional */
  /*  CDMA Base Station Information */
  uint8_t cdma_base_station_info_valid;  /**< Must be set to true if cdma_base_station_info is being passed */
  nas_cdma_base_station_info_type_v01 cdma_base_station_info;

  /* Optional */
  /*  Roaming Indicator List */
  uint8_t roaming_indicator_list_valid;  /**< Must be set to true if roaming_indicator_list is being passed */
  uint32_t roaming_indicator_list_len;  /**< Must be set to # of elements in roaming_indicator_list */
  nas_roaming_indicator_type_v01 roaming_indicator_list[NAS_ROAMING_INDICATOR_LIST_MAX_V01];

  /* Optional */
  /*  Default Roaming Indicator */
  uint8_t def_roam_ind_valid;  /**< Must be set to true if def_roam_ind is being passed */
  nas_roaming_indicator_enum_v01 def_roam_ind;
  /**<   
    Roaming indicator. Values: \n
    -0x00 -- ROAMING_IND_ON                       -- Roaming \n
    -0x01 -- ROAMING_IND_OFF                      -- Home

    Values from 2 onward are applicable only for 3GPP2. Refer to 
    \hyperref[STD-CR1001F]{3GPP2 C.R1001-F} for the meanings of these values.
  */

  /* Optional */
  /*  3GGP2 Time Zone */
  uint8_t nas_3gpp_time_zone_valid;  /**< Must be set to true if nas_3gpp_time_zone is being passed */
  nas_3gpp_time_zone_type_v01 nas_3gpp_time_zone;

  /* Optional */
  /*  CDMA P_Rev in Use */
  uint8_t p_rev_in_use_valid;  /**< Must be set to true if p_rev_in_use is being passed */
  uint8_t p_rev_in_use;
  /**<   P_Rev that is currently in use.*/

  /* Optional */
  /*  3GPP Time Zone */
  uint8_t time_zone_valid;  /**< Must be set to true if time_zone is being passed */
  int8_t time_zone;
  /**<   Offset from Universal time, i.e., difference between local
       time and Universal time, in increments of 15 min (signed value).
  */

  /* Optional */
  /*   3GPP Network Daylight Saving Adjustment */
  uint8_t adj_valid;  /**< Must be set to true if adj is being passed */
  uint8_t adj;
  /**<   3GPP network daylight saving adjustment. Values: \n
       - 0x00 -- No adjustment for Daylight Saving Time \n
       - 0x01 -- 1 hr adjustment for Daylight Saving Time \n
       - 0x02 -- 2 hr adjustment for Daylight Saving Time
  */

  /* Optional */
  /*  3GPP Location Area Code */
  uint8_t lac_valid;  /**< Must be set to true if lac is being passed */
  uint16_t lac;
  /**<   Location area code.
  */

  /* Optional */
  /*  3GPP Cell ID */
  uint8_t cell_id_valid;  /**< Must be set to true if cell_id is being passed */
  uint32_t cell_id;
  /**<   3GPP cell ID.
  */

  /* Optional */
  /*  3GPP2 Concurrent Service Info */
  uint8_t ccs_valid;  /**< Must be set to true if ccs is being passed */
  uint8_t ccs;
  /**<   3GPP2 concurrent service information. Values: \n
        - 0x00 -- Concurrent service not available \n
        - 0x01 -- Concurrent service available
  */

  /* Optional */
  /*  3GPP2 PRL Indicator */
  uint8_t prl_ind_valid;  /**< Must be set to true if prl_ind is being passed */
  uint8_t prl_ind;
  /**<   3GPP2 PRL indicator. Values: \n
       - 0x00 -- System not in PRL \n
       - 0x01 -- System is in PRL
  */

  /* Optional */
  /*  Dual Transfer Mode Indication (GSM Only) */
  uint8_t dtm_ind_valid;  /**< Must be set to true if dtm_ind is being passed */
  uint8_t dtm_ind;
  /**<   Dual Transfer mode indication. Values: \n
      - 0x00 -- DTM not supported \n
      - 0x01 -- DTM supported 
  */

  /* Optional */
  /*  Detailed Service Information */
  uint8_t detailed_service_info_valid;  /**< Must be set to true if detailed_service_info is being passed */
  nas_ss_detailed_service_info_type_v01 detailed_service_info;

  /* Optional */
  /*  CDMA System Info */
  uint8_t cdma_system_id_ext_valid;  /**< Must be set to true if cdma_system_id_ext is being passed */
  nas_cdma_system_id_ext_type_v01 cdma_system_id_ext;

  /* Optional */
  /*  HDR Personality */
  uint8_t hdr_personality_valid;  /**< Must be set to true if hdr_personality is being passed */
  nas_hdr_personality_enum_v01 hdr_personality;
  /**<   HDR personality information. Values: \n
      - 0x00 -- Unknown \n
      - 0x01 -- HRPD \n
      - 0x02 -- eHRPD
  */

  /* Optional */
  /*  TAC Information for LTE */
  uint8_t tac_valid;  /**< Must be set to true if tac is being passed */
  uint16_t tac;
  /**<   Tracking area code information for LTE.
  */

  /* Optional */
  /*  Call Barring Status */
  uint8_t call_barring_status_valid;  /**< Must be set to true if call_barring_status is being passed */
  nas_gw_sys_info3_type_v01 call_barring_status;

  /* Optional */
  /*  UMTS Primary Scrambling Code */
  uint8_t umts_psc_valid;  /**< Must be set to true if umts_psc is being passed */
  uint16_t umts_psc;
  /**<   Primary scrambling code.
  */

  /* Optional */
  /*  MNC PCS Digit Include Status */
  uint8_t mnc_includes_pcs_digit_valid;  /**< Must be set to true if mnc_includes_pcs_digit is being passed */
  nas_mnc_pcs_digit_include_status_type_v01 mnc_includes_pcs_digit;

  /* Optional */
  /*  HS Call Status */
  uint8_t hs_call_status_valid;  /**< Must be set to true if hs_call_status is being passed */
  nas_hs_support_enum_type_v01 hs_call_status;
  /**<   Call status on high speed (only applicable for WCDMA). Values: \n
      - SYS_HS_IND_HSDPA_HSUPA_UNSUPP_CELL (0x00) --  HSDPA and HSUPA are unsupported \n 
      - SYS_HS_IND_HSDPA_SUPP_CELL (0x01) --  HSDPA is supported \n 
      - SYS_HS_IND_HSUPA_SUPP_CELL (0x02) --  HSUPA is supported \n 
      - SYS_HS_IND_HSDPA_HSUPA_SUPP_CELL (0x03) --  HSDPA and HSUPA are supported  \n 
      - SYS_HS_IND_HSDPAPLUS_SUPP_CELL (0x04) --  HSDPA+ is supported \n 
      - SYS_HS_IND_HSDPAPLUS_HSUPA_SUPP_CELL (0x05) --  HSDPA+ and HSUPA are supported \n 
      - SYS_HS_IND_DC_HSDPAPLUS_SUPP_CELL (0x06) --  Dual-cell HSDPA+ is supported \n 
      - SYS_HS_IND_DC_HSDPAPLUS_HSUPA_SUPP_CELL (0x07) --  Dual-cell HSDPA+ and HSUPA are supported \n  
      - SYS_HS_IND_HSDPAPLUS_64QAM_HSUPA_SUPP_CELL (0x08) --  Dual-cell HSDPA+, 64 QAM, and HSUPA are supported \n 
      - SYS_HS_IND_HSDPAPLUS_64QAM_SUPP_CELL (0x09) --  Dual-cell HSDPA+ and 64 QAM are supported \n 
      - SYS_HS_IND_DC_HSDPAPLUS_DC_HSUPA_SUPP_CELL (0x0A) --  Dual-cell HSDPA+ and dual-cell HSUPA are supported 
 */

  /* Optional */
  /*  3GPP Network Name Source */
  uint8_t nas_3gpp_nw_name_source_valid;  /**< Must be set to true if nas_3gpp_nw_name_source is being passed */
  nas_nw_name_source_enum_type_v01 nas_3gpp_nw_name_source;
  /**<   Network name source. Values: \n
      - NAS_NW_NAME_SOURCE_UNKNOWN (0x00) --  Unknown \n 
      - NAS_NW_NAME_SOURCE_OPL_PNN (0x01) --  Operator PLMN list and PLMN network name \n 
      - NAS_NW_NAME_SOURCE_CPHS_ONS (0x02) --  Common PCN handset specification and operator name string \n 
      - NAS_NW_NAME_SOURCE_NITZ (0x03) --  Network identity and time zone \n 
      - NAS_NW_NAME_SOURCE_SE13 (0x04) --  GSMA SE13 table \n 
      - NAS_NW_NAME_SOURCE_MCC_MNC (0x05) --  Mobile country code and mobile network code \n 
      - NAS_NW_NAME_SOURCE_SPN (0x06) --  Service provider name 
 */
}nas_get_serving_system_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t year;
  /**<   Year.*/

  uint8_t month;
  /**<   Month.*/

  uint8_t day;
  /**<   Day.*/

  uint8_t hour;
  /**<   Hour.*/

  uint8_t minute;
  /**<   Minute.*/

  uint8_t second;
  /**<   Second.*/

  int8_t time_zone;
  /**<   Offset from Universal time, i.e., difference between local time
       and Universal time, in increments of 15 min (signed value).
  */
}nas_universal_time_and_local_time_zone_3gpp_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates a change in the current serving system registration
              state and/or radio technology. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Serving System */
  nas_serving_system_type_v01 serving_system;

  /* Optional */
  /*  Roaming Indicator Value */
  uint8_t roaming_indicator_valid;  /**< Must be set to true if roaming_indicator is being passed */
  nas_roaming_indicator_enum_v01 roaming_indicator;
  /**<   
    Roaming indicator. Values: \n
    - 0x00 -- ROAMING_IND_ON       -- Roaming   \n
    - 0x01 -- ROAMING_IND_OFF      -- Home      \n
    - 0x02 -- ROAMING_IND_FLASHING -- Flashing  \n
    - 0x03 and above -- Operator-defined values
  */

  /* Optional */
  /*  Data Service Capability */
  uint8_t data_capabilities_valid;  /**< Must be set to true if data_capabilities is being passed */
  uint32_t data_capabilities_len;  /**< Must be set to # of elements in data_capabilities */
  nas_data_capabilites_enum_v01 data_capabilities[NAS_DATA_CAPABILITIES_LIST_MAX_V01];
  /**<   List of data capabilities (each is 1 byte) of the current
       serving system. Possible values: \n
       -0x01 -- DATA_CAPABILITIES_GPRS       -- GPRS \n
       -0x02 -- DATA_CAPABILITIES_EDGE       -- EDGE \n
       -0x03 -- DATA_CAPABILITIES_HSDPA      -- HSDPA \n
       -0x04 -- DATA_CAPABILITIES_HSUPA      -- HSUPA \n
       -0x05 -- DATA_CAPABILITIES_WCDMA      -- WCDMA \n
       -0x06 -- DATA_CAPABILITIES_CDMA       -- CDMA \n
       -0x07 -- DATA_CAPABILITIES_EVDO_REV_O -- EV-DO REV 0  \n
       -0x08 -- DATA_CAPABILITIES_EVDO_REV_A -- EV-DO REV A  \n
       -0x09 -- DATA_CAPABILITIES_GSM        -- GSM          \n
       -0x0A -- DATA_CAPABILITIES_EVDO_REV_B -- EV-DO REV B  \n
       -0x0B -- DATA_CAPABILITIES_LTE        -- LTE          \n
       -0x0C -- DATA_CAPABILITIES_HSDPA_PLUS -- HSDPA+       \n
       -0x0D -- DATA_CAPABILITIES_DC_HSDPA_ PLUS -- DC-HSDPA+
  */

  /* Optional */
  /*  Current PLMN */
  uint8_t current_plmn_valid;  /**< Must be set to true if current_plmn is being passed */
  nas_plmn_type_v01 current_plmn;

  /* Optional */
  /*  CDMA System ID */
  uint8_t cdma_system_id_valid;  /**< Must be set to true if cdma_system_id is being passed */
  nas_cdma_system_id_type_v01 cdma_system_id;

  /* Optional */
  /*  CDMA Base Station Information */
  uint8_t cdma_base_station_info_valid;  /**< Must be set to true if cdma_base_station_info is being passed */
  nas_cdma_base_station_info_type_v01 cdma_base_station_info;

  /* Optional */
  /*  Roaming Indicator List */
  uint8_t roaming_indicator_list_valid;  /**< Must be set to true if roaming_indicator_list is being passed */
  uint32_t roaming_indicator_list_len;  /**< Must be set to # of elements in roaming_indicator_list */
  nas_roaming_indicator_type_v01 roaming_indicator_list[NAS_ROAMING_INDICATOR_LIST_MAX_V01];

  /* Optional */
  /*  Default Roaming Indicator */
  uint8_t def_roam_ind_valid;  /**< Must be set to true if def_roam_ind is being passed */
  nas_roaming_indicator_enum_v01 def_roam_ind;
  /**<   
    Roaming indicator. Values: \n
    -0x00 -- ROAMING_IND_ON                       -- Roaming \n
    -0x01 -- ROAMING_IND_OFF                      -- Home

    Values from 2 onward are applicable only for 3GPP2. Refer to 
    \hyperref[STD-CR1001F]{3GPP2 C.R1001-F} for the meanings of these values.
  */

  /* Optional */
  /*  3GGP2 Time Zone */
  uint8_t nas_3gpp_time_zone_valid;  /**< Must be set to true if nas_3gpp_time_zone is being passed */
  nas_3gpp_time_zone_type_v01 nas_3gpp_time_zone;

  /* Optional */
  /*  CDMA P_Rev in Use */
  uint8_t p_rev_in_use_valid;  /**< Must be set to true if p_rev_in_use is being passed */
  uint8_t p_rev_in_use;
  /**<   P_Rev that is currently in use.
  */

  /* Optional */
  /*  3GPP PLMN Name Flag */
  uint8_t plmn_description_changed_valid;  /**< Must be set to true if plmn_description_changed is being passed */
  uint8_t plmn_description_changed;
  /**<  
       Flag indicating that the 3GPP EONS network description changed. Values: \n
       -0x01 -- PLMN name changed
  */

  /* Optional */
  /*  3GPP Time Zone */
  uint8_t time_zone_valid;  /**< Must be set to true if time_zone is being passed */
  int8_t time_zone;
  /**<   Offset from Universal time, i.e., difference between local
       time and Universal time, in increments of 15 min (signed value).
  */

  /* Optional */
  /*   3GPP Network Daylight Saving Adjustment */
  uint8_t adj_valid;  /**< Must be set to true if adj is being passed */
  uint8_t adj;
  /**<   3GPP network daylight saving adjustment. Values: \n
       - 0x00 -- No adjustment for Daylight Saving Time \n
       - 0x01 -- 1 hr adjustment for Daylight Saving Time \n
       - 0x02 -- 2 hr adjustment for Daylight Saving Time
  */

  /* Optional */
  /*  3GPP Universal Time and Local Time Zone */
  uint8_t universal_time_and_local_time_3gpp_zone_valid;  /**< Must be set to true if universal_time_and_local_time_3gpp_zone is being passed */
  nas_universal_time_and_local_time_zone_3gpp_type_v01 universal_time_and_local_time_3gpp_zone;

  /* Optional */
  /*  3GPP Location Area Code */
  uint8_t lac_valid;  /**< Must be set to true if lac is being passed */
  uint16_t lac;
  /**<   Location area code.
  */

  /* Optional */
  /*  3GPP Cell ID */
  uint8_t cell_id_valid;  /**< Must be set to true if cell_id is being passed */
  uint32_t cell_id;
  /**<   3GPP cell ID.
  */

  /* Optional */
  /*  3GPP2 Concurrent Service Info */
  uint8_t ccs_valid;  /**< Must be set to true if ccs is being passed */
  uint8_t ccs;
  /**<   3GPP2 concurrent service information. Values: \n
        - 0x00 -- Concurrent service not available \n
        - 0x01 -- Concurrent service available
  */

  /* Optional */
  /*  3GPP2 PRL Indicator */
  uint8_t prl_ind_valid;  /**< Must be set to true if prl_ind is being passed */
  uint8_t prl_ind;
  /**<   3GPP2 PRL indicator. Values: \n
       - 0x00 -- System not in PRL \n
       - 0x01 -- System is in PRL
  */

  /* Optional */
  /*  Dual Transfer Mode Indication (GSM Only) */
  uint8_t dtm_ind_valid;  /**< Must be set to true if dtm_ind is being passed */
  uint8_t dtm_ind;
  /**<   Dual Transfer mode indication. Values: \n
      - 0x00 -- DTM not supported \n
      - 0x01 -- DTM supported 
  */

  /* Optional */
  /*  Detailed Service Information */
  uint8_t detailed_service_info_valid;  /**< Must be set to true if detailed_service_info is being passed */
  nas_ss_detailed_service_info_type_v01 detailed_service_info;

  /* Optional */
  /*  CDMA System Info Ext */
  uint8_t cdma_system_id_ext_valid;  /**< Must be set to true if cdma_system_id_ext is being passed */
  nas_cdma_system_id_ext_type_v01 cdma_system_id_ext;

  /* Optional */
  /*  HDR Personality */
  uint8_t hdr_personality_valid;  /**< Must be set to true if hdr_personality is being passed */
  nas_hdr_personality_enum_v01 hdr_personality;
  /**<   HDR personality information. Values: \n
      - 0x00 -- Unknown \n
      - 0x01 -- HRPD \n
      - 0x02 -- eHRPD
  */

  /* Optional */
  /*  TAC Information for LTE */
  uint8_t tac_valid;  /**< Must be set to true if tac is being passed */
  uint16_t tac;
  /**<   Tracking area code information for LTE.
  */

  /* Optional */
  /*  Call Barring Status */
  uint8_t call_barring_status_valid;  /**< Must be set to true if call_barring_status is being passed */
  nas_gw_sys_info3_type_v01 call_barring_status;

  /* Optional */
  /*  PLMN Change Status */
  uint8_t srv_sys_no_change_valid;  /**< Must be set to true if srv_sys_no_change is being passed */
  uint8_t srv_sys_no_change;
  /**<   Flag used to notify clients that a request to select a network ended 
      with no change in the PLMN. Values: \n
      - 0x01 -- No change in serving system information
  */

  /* Optional */
  /*  UMTS Primary Scrambling Code */
  uint8_t umts_psc_valid;  /**< Must be set to true if umts_psc is being passed */
  uint16_t umts_psc;
  /**<   Primary scrambling code.
  */

  /* Optional */
  /*  MNC PCS Digit Include Status */
  uint8_t mnc_includes_pcs_digit_valid;  /**< Must be set to true if mnc_includes_pcs_digit is being passed */
  nas_mnc_pcs_digit_include_status_type_v01 mnc_includes_pcs_digit;

  /* Optional */
  /*  HS Call Status */
  uint8_t hs_call_status_valid;  /**< Must be set to true if hs_call_status is being passed */
  nas_hs_support_enum_type_v01 hs_call_status;
  /**<   Call status on high speed (only applicable for WCDMA). Values: \n
      - SYS_HS_IND_HSDPA_HSUPA_UNSUPP_CELL (0x00) --  HSDPA and HSUPA are unsupported \n 
      - SYS_HS_IND_HSDPA_SUPP_CELL (0x01) --  HSDPA is supported \n 
      - SYS_HS_IND_HSUPA_SUPP_CELL (0x02) --  HSUPA is supported \n 
      - SYS_HS_IND_HSDPA_HSUPA_SUPP_CELL (0x03) --  HSDPA and HSUPA are supported  \n 
      - SYS_HS_IND_HSDPAPLUS_SUPP_CELL (0x04) --  HSDPA+ is supported \n 
      - SYS_HS_IND_HSDPAPLUS_HSUPA_SUPP_CELL (0x05) --  HSDPA+ and HSUPA are supported \n 
      - SYS_HS_IND_DC_HSDPAPLUS_SUPP_CELL (0x06) --  Dual-cell HSDPA+ is supported \n 
      - SYS_HS_IND_DC_HSDPAPLUS_HSUPA_SUPP_CELL (0x07) --  Dual-cell HSDPA+ and HSUPA are supported \n  
      - SYS_HS_IND_HSDPAPLUS_64QAM_HSUPA_SUPP_CELL (0x08) --  Dual-cell HSDPA+, 64 QAM, and HSUPA are supported \n 
      - SYS_HS_IND_HSDPAPLUS_64QAM_SUPP_CELL (0x09) --  Dual-cell HSDPA+ and 64 QAM are supported \n 
      - SYS_HS_IND_DC_HSDPAPLUS_DC_HSUPA_SUPP_CELL (0x0A) --  Dual-cell HSDPA+ and dual-cell HSUPA are supported 
 */

  /* Optional */
  /*  3GPP Network Name Source */
  uint8_t nas_3gpp_nw_name_source_valid;  /**< Must be set to true if nas_3gpp_nw_name_source is being passed */
  nas_nw_name_source_enum_type_v01 nas_3gpp_nw_name_source;
  /**<   Network name source. Values: \n
      - NAS_NW_NAME_SOURCE_UNKNOWN (0x00) --  Unknown \n 
      - NAS_NW_NAME_SOURCE_OPL_PNN (0x01) --  Operator PLMN list and PLMN network name \n 
      - NAS_NW_NAME_SOURCE_CPHS_ONS (0x02) --  Common PCN handset specification and operator name string \n 
      - NAS_NW_NAME_SOURCE_NITZ (0x03) --  Network identity and time zone \n 
      - NAS_NW_NAME_SOURCE_SE13 (0x04) --  GSMA SE13 table \n 
      - NAS_NW_NAME_SOURCE_MCC_MNC (0x05) --  Mobile country code and mobile network code \n 
      - NAS_NW_NAME_SOURCE_SPN (0x06) --  Service provider name 
 */
}nas_serving_system_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves information about the home network of the device. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_home_network_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_NETWORK_DESC_DISPLAY_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_NETWORK_DESC_DISP_FALSE_V01 = 0x00, 
  NAS_NETWORK_DESC_DISP_TRUE_V01 = 0x01, 
  NAS_NETWORK_DESC_DISP_UNKOWN_V01 = 0xFF, 
  NAS_NETWORK_DESC_DISP_UNKNOWN_V01 = 0xFF, 
  NAS_NETWORK_DESC_DISPLAY_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_network_desc_display_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_NETWORK_DESC_ENCODING_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_NETWORK_DESC_ENCODING_OCTECT_UNSPECIFIED_V01 = 0x00, 
  NAS_NETWORK_DESC_ENCODING_7_BIT_ASCII_V01 = 0x02, 
  NAS_NETWORK_DESC_ENCODING_UNICODE_V01 = 0x04, 
  NAS_NETWORK_DESC_ENCODING_GSM_7_BIT_DEFAULT_V01 = 0x09, 
  NAS_NETWORK_DESC_ENCODING_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_network_desc_encoding_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  MCC and MNC */
  nas_plmn_id_type_v01 mcc_mnc;

  /*  Network name display status */
  nas_network_desc_display_enum_type_v01 network_desc_display;
  /**<   
      Whether the network name is to be conditionally displayed: \n
      - 0x00 -- Do not display \n
      - 0x01 -- Display \n
      - 0xFF -- Unknown \n
      Note: This value is ignored if the network_description_len
            is zero.
  */

  /*  Network description encoding */
  nas_network_desc_encoding_type_v01 network_desc_encoding;
  /**<   Encoding of the network description. 
      Refer to \hyperref[STD-CR1001F]{3GPP2 C.R1001-F} Table 9.1.1 for a list of 
      all defined values. Common (but not all) values include: \n
      - 0x00 -- Octet, unspecified \n
      - 0x02 -- 7-bit ASCII \n
      - 0x04 -- Unicode (refer to \hyperref[STD-ISO-IEC10646]{ISO/IEC 10646}) \n
      - 0x09 -- GSM 7-bit default (refer to \hyperref[STD-23038]{3GPP TS 23.038}) \n
      Note: This value is ignored if the network_description_len
            is zero. If the encoding type is not recognized the 
            network_description is ignored.
   */

  /*  Network description 
 Length of network description string that follows. 
      If the network name is unknown or not included, the length
      is 0.
   */
  uint32_t network_desc_len;  /**< Must be set to # of elements in network_desc */
  uint8_t network_desc[NAS_NETWORK_DESCRIPTION_MAX_V01];
  /**<   Length of network description string that follows. 
       If the network name is unknown or not included, the length
       is 0.
  */
}nas_3gpp2_home_network_ext_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t is_3gpp_network;
  /**<   TRUE if TLV 0x01 corresponds to a 3GPP network; otherwise FALSE. */

  uint8_t mnc_includes_pcs_digit;
  /**<   This field is used to interpret the length of the mobile_network_code 
       reported in TLV 0x01. Values: \n

       - TRUE  -- MNC is a three-digit value; e.g., a reported value of 
                  90 corresponds to an MNC value of 090  \n
       - FALSE -- MNC is a two-digit value; e.g., a reported value of 
                  90 corresponds to an MNC value of 90 \n
       Note: This value is ignored if is_3gpp_network is FALSE.
  */
}nas_3gpp_mcs_digit_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves information about the home network of the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. 
 Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */

  /* Mandatory */
  /*  Home Network */
  nas_plmn_type_v01 home_network;

  /* Optional */
  /*  Home System ID */
  uint8_t home_system_id_valid;  /**< Must be set to true if home_system_id is being passed */
  nas_cdma_system_id_type_v01 home_system_id;

  /* Optional */
  /*  3GPP2 Home Network Ext */
  uint8_t nas_3gpp2_home_network_ext_valid;  /**< Must be set to true if nas_3gpp2_home_network_ext is being passed */
  nas_3gpp2_home_network_ext_type_v01 nas_3gpp2_home_network_ext;

  /* Optional */
  /*  3GPP Home Network MNC (includes PCS digit status) */
  uint8_t nas_3gpp_mcs_include_digit_valid;  /**< Must be set to true if nas_3gpp_mcs_include_digit is being passed */
  nas_3gpp_mcs_digit_type_v01 nas_3gpp_mcs_include_digit;

  /* Optional */
  /*  3GPP Network Name Source */
  uint8_t nas_3gpp_nw_name_source_valid;  /**< Must be set to true if nas_3gpp_nw_name_source is being passed */
  nas_nw_name_source_enum_type_v01 nas_3gpp_nw_name_source;
  /**<   Network name source. Values: \n
      - NAS_NW_NAME_SOURCE_UNKNOWN (0x00) --  Unknown \n 
      - NAS_NW_NAME_SOURCE_OPL_PNN (0x01) --  Operator PLMN list and PLMN network name \n 
      - NAS_NW_NAME_SOURCE_CPHS_ONS (0x02) --  Common PCN handset specification and operator name string \n 
      - NAS_NW_NAME_SOURCE_NITZ (0x03) --  Network identity and time zone \n 
      - NAS_NW_NAME_SOURCE_SE13 (0x04) --  GSMA SE13 table \n 
      - NAS_NW_NAME_SOURCE_MCC_MNC (0x05) --  Mobile country code and mobile network code \n 
      - NAS_NW_NAME_SOURCE_SPN (0x06) --  Service provider name 
 */
}nas_get_home_network_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Queries the list of preferred networks from the device. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_preferred_networks_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t mobile_country_code;
  /**<   A 16-bit integer representation of MCC. Range: 0 to 999.
  */

  uint16_t mobile_network_code;
  /**<   A 16-bit integer representation of MNC. Range: 0 to 999.
  */

  uint16_t radio_access_technology;
  /**<    RAT as a bitmask (bit count begins from zero). Values: \n
        - Bit 15 -- UMTS \n
        - Bit 14 -- LTE \n
        - Bit 7 -- GSM \n
        - Bit 6 -- GSM compact \n
    	- Bit 4 -- NR5G \n
        - All bits set to 0 -- No access technology is available from the device
  */
}nas_3gpp_preferred_networks_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Queries the list of preferred networks from the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  3GPP Preferred Networks** */
  uint8_t nas_3gpp_preferred_networks_valid;  /**< Must be set to true if nas_3gpp_preferred_networks is being passed */
  uint32_t nas_3gpp_preferred_networks_len;  /**< Must be set to # of elements in nas_3gpp_preferred_networks */
  nas_3gpp_preferred_networks_type_v01 nas_3gpp_preferred_networks[NAS_3GPP_PREFERRED_NETWORKS_LIST_MAX_V01];

  /* Optional */
  /*  Static 3GPP Preferred Networks** */
  uint8_t static_3gpp_preferred_networks_valid;  /**< Must be set to true if static_3gpp_preferred_networks is being passed */
  uint32_t static_3gpp_preferred_networks_len;  /**< Must be set to # of elements in static_3gpp_preferred_networks */
  nas_3gpp_preferred_networks_type_v01 static_3gpp_preferred_networks[NAS_STATIC_3GPP_PREFERRED_NETWORKS_LIST_MAX_V01];

  /* Optional */
  /*  3GPP Preferred Networks MNC (includes PCS digit status) */
  uint8_t nas_3gpp_mnc_includes_pcs_digit_valid;  /**< Must be set to true if nas_3gpp_mnc_includes_pcs_digit is being passed */
  uint32_t nas_3gpp_mnc_includes_pcs_digit_len;  /**< Must be set to # of elements in nas_3gpp_mnc_includes_pcs_digit */
  nas_mnc_pcs_digit_include_status_type_v01 nas_3gpp_mnc_includes_pcs_digit[NAS_3GPP_PREFERRED_NETWORKS_LIST_MAX_V01];

  /* Optional */
  /*  Static 3GPP Preferred Networks MNC (includes PCS digit status) */
  uint8_t static_3gpp_mnc_includes_pcs_digit_valid;  /**< Must be set to true if static_3gpp_mnc_includes_pcs_digit is being passed */
  uint32_t static_3gpp_mnc_includes_pcs_digit_len;  /**< Must be set to # of elements in static_3gpp_mnc_includes_pcs_digit */
  nas_mnc_pcs_digit_include_status_type_v01 static_3gpp_mnc_includes_pcs_digit[NAS_3GPP_PREFERRED_NETWORKS_LIST_MAX_V01];
}nas_get_preferred_networks_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Writes the specified list of preferred networks to the device. */
typedef struct {

  /* Optional */
  /*  3GPP Preferred Networks** */
  uint8_t nas_3gpp_preferred_networks_valid;  /**< Must be set to true if nas_3gpp_preferred_networks is being passed */
  uint32_t nas_3gpp_preferred_networks_len;  /**< Must be set to # of elements in nas_3gpp_preferred_networks */
  nas_3gpp_preferred_networks_type_v01 nas_3gpp_preferred_networks[NAS_3GPP_PREFERRED_NETWORKS_LIST_MAX_V01];

  /* Optional */
  /*  3GPP Preferred Networks MNC (includes PCS digit status) */
  uint8_t nas_3gpp_mnc_includes_pcs_digit_valid;  /**< Must be set to true if nas_3gpp_mnc_includes_pcs_digit is being passed */
  uint32_t nas_3gpp_mnc_includes_pcs_digit_len;  /**< Must be set to # of elements in nas_3gpp_mnc_includes_pcs_digit */
  nas_mnc_pcs_digit_include_status_type_v01 nas_3gpp_mnc_includes_pcs_digit[NAS_3GPP_PREFERRED_NETWORKS_LIST_MAX_V01];

  /* Optional */
  /*  Clear Previous Preferred Networks List */
  uint8_t clear_prev_preferred_networks_valid;  /**< Must be set to true if clear_prev_preferred_networks is being passed */
  uint8_t clear_prev_preferred_networks;
  /**<   Indicates whether to add padding to the incoming preferred networks list 
       and to fully clear out the previous preferred networks list.
    */
}nas_set_preferred_networks_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Writes the specified list of preferred networks to the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_preferred_networks_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Queries the list of forbidden networks from the device. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_forbidden_networks_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t mobile_country_code;
  /**<   A 16-bit integer representation of MCC. Range: 0 to 999.
  */

  uint16_t mobile_network_code;
  /**<   A 16-bit integer representation of MNC. Range: 0 to 999.
  */
}nas_3gpp_forbidden_networks_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Queries the list of forbidden networks from the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  3GPP Forbidden Networks** */
  uint8_t nas_3gpp_forbidden_networks_valid;  /**< Must be set to true if nas_3gpp_forbidden_networks is being passed */
  uint32_t nas_3gpp_forbidden_networks_len;  /**< Must be set to # of elements in nas_3gpp_forbidden_networks */
  nas_3gpp_forbidden_networks_type_v01 nas_3gpp_forbidden_networks[NAS_3GPP_FORBIDDEN_NETWORKS_LIST_MAX_V01];
}nas_get_forbidden_networks_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Writes the specified list of forbidden networks to the device. */
typedef struct {

  /* Optional */
  /*  3GPP Forbidden Networks** */
  uint8_t nas_3gpp_forbidden_networks_valid;  /**< Must be set to true if nas_3gpp_forbidden_networks is being passed */
  uint32_t nas_3gpp_forbidden_networks_len;  /**< Must be set to # of elements in nas_3gpp_forbidden_networks */
  nas_3gpp_forbidden_networks_type_v01 nas_3gpp_forbidden_networks[NAS_3GPP_FORBIDDEN_NETWORKS_LIST_MAX_V01];

  /* Optional */
  /*  3GPP Forbidden Networks (includes PCS digit status) */
  uint8_t nas_3gpp_mnc_includes_pcs_digit_valid;  /**< Must be set to true if nas_3gpp_mnc_includes_pcs_digit is being passed */
  uint32_t nas_3gpp_mnc_includes_pcs_digit_len;  /**< Must be set to # of elements in nas_3gpp_mnc_includes_pcs_digit */
  uint8_t nas_3gpp_mnc_includes_pcs_digit[NAS_3GPP_FORBIDDEN_NETWORKS_LIST_MAX_V01];
  /**<   Flag to identify if PCS digit is included in MNC. Values: \n
    - 0x00 -- False \n
    - 0x01 -- True 
  */
}nas_set_forbidden_networks_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Writes the specified list of forbidden networks to the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_forbidden_networks_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Queries the Access Overload Class (ACCOLC) of the device. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_accolc_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Queries the Access Overload Class (ACCOLC) of the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Mandatory */
  /*  Access Overload Class */
  uint8_t accolc;
  /**<   An 8-bit integer representation of the ACCOLC. 
       Range: 0 to 15 (0x00 to 0x0F).
  */
}nas_get_accolc_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  char spc[NAS_SPC_MAX_V01];
  /**<   Service programming code in ASCII format (digits 0 to 9 only).*/

  uint8_t accolc;
  /**<   An 8-bit integer representation of the ACCOLC. 
       Range: 0 to 15 (0x00 to 0x0F).
  */
}nas_accolc_set_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets the ACCOLC of the device. */
typedef struct {

  /* Mandatory */
  /*  Access Overload Class */
  nas_accolc_set_type_v01 accolc_set;
}nas_set_accolc_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets the ACCOLC of the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_accolc_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Queries the network-related configuration setting of the 
              device. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_device_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t reg_home_sid;
  /**<   Register on home system. Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable
  */

  uint8_t reg_foreign_sid;
  /**<   Register on foreign system. Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable
  */

  uint8_t reg_foreign_nid;
  /**<   Register on foreign network. Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable
  */
}nas_registration_parameters_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t state;
  /**<   HDR custom configuration for session control protocol. Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable; enable may only be specified if Force HDR Revision 
                 is set to Disable
  */

  uint32_t protocol_mask;
  /**<   Protocol subtype bitmask. Values: \n
       - Bit 0 -- Subtype 2 physical layer \n
       - Bit 1 -- Enhanced CCMAC \n
       - Bit 2 -- Enhanced ACMAC \n
       - Bit 3 -- Enhanced FTCMAC \n
       - Bit 4 -- Subtype 3 RTCMAC \n
       - Bit 5 -- Subtype 1 RTCMAC \n
       - Bit 6 -- Enhanced idle \n
       - Bit 7 -- Generic multimode-capable disc port

       \vspace{3pt}
       All unlisted bits are reserved for future use and are ignored.
  */

  uint32_t broadcast_mask;
  /**<   Broadcast subtype bitmask. Values: \n
       - Bit 0 -- Generic broadcast enabled

       \vspace{3pt}
       All unlisted bits are reserved for future use and are ignored.
  */

  uint32_t application_mask;
  /**<   Application subtype bitmask. Values: \n
       - Bit 0 -- SN multiflow packet application \n
       - Bit 1 -- SN enhanced multiflow packet application

       \vspace{3pt}
       All unlisted bits are reserved for future use and are ignored.
  */
}nas_hdr_scp_config_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_ROAM_CONFIG_PREF_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_ROAM_CONFIG_PREF_AUTO_V01 = 0x00, 
  NAS_ROAM_CONFIG_PREF_HOME_ONLY_V01 = 0x01, 
  NAS_ROAM_CONFIG_PREF_ROAM_ONLY_V01 = 0x02, 
  NAS_ROAM_CONFIG_PREF_HOME_AND_AFFILIATE_V01 = 0x03, 
  NAS_ROAM_CONFIG_PREF_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_roam_config_pref_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_FORCE_HDRSCP_CONFIG_AT_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_HDR_REV0_PROTOCOLS_ONLY_V01 = 0x00, 
  NAS_HDR_REVA_PROTOCOLS_MFPA_V01 = 0x01, 
  NAS_HDR_REVA_PROTOCOLS_MFPA_EMPA_V01 = 0x02, 
  NAS_HDR_REVB_PROTOCOLS_MMPA_V01 = 0x03, 
  NAS_HDR_REVA_PROTOCOLS_EHRPD_V01 = 0x04, 
  NAS_HDR_REVB_PROTOCOLS_EHRPD_V01 = 0x05, 
  NAS_FORCE_HDRSCP_CONFIG_AT_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_force_hdrscp_config_at_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Queries the network-related configuration setting of the 
              device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. 
 Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */

  /* Optional */
  /*  Slot Cycle Index* */
  uint8_t sci_valid;  /**< Must be set to true if sci is being passed */
  uint8_t sci;
  /**<   Slot cycle index 
       (refer to \hyperref[STD-CR1001F]{3GPP2 C.R1001-F} Section 6.6.2.1).
  */

  /* Optional */
  /*  Station Class Mark* */
  uint8_t scm_valid;  /**< Must be set to true if scm is being passed */
  uint8_t scm;
  /**<   Station class mark 
       (refer to \hyperref[STD-CR1001F]{3GPP2 C.R1001-F} Section 6.3.3).
  */

  /* Optional */
  /*  Registration Parameters* */
  uint8_t registration_parameters_valid;  /**< Must be set to true if registration_parameters is being passed */
  nas_registration_parameters_type_v01 registration_parameters;

  /* Optional */
  /*  Force HDR Revision* */
  uint8_t force_rev0_valid;  /**< Must be set to true if force_rev0 is being passed */
  uint8_t force_rev0;
  /**<   Force Rev0. Values: \n
       - 0x00 -- Disabled \n
       - 0x01 -- Enabled \n
    Note: This TLV is now DISCONTINUED, and is present here as a
          placeholder only for existing clients referencing this TLV.
  */

  /* Optional */
  /*  HDR SCP Custom Config* */
  uint8_t hdr_scp_config_valid;  /**< Must be set to true if hdr_scp_config is being passed */
  nas_hdr_scp_config_type_v01 hdr_scp_config;
  /**<   \n
    Note: This TLV is now DISCONTINUED, and is present here as a
          placeholder only for existing clients referencing this TLV.
  */

  /* Optional */
  /*  Roam Preference* */
  uint8_t roam_pref_valid;  /**< Must be set to true if roam_pref is being passed */
  nas_roam_config_pref_enum_v01 roam_pref;
  /**<   Roaming preference. Values: \n
       - 0x00 -- ROAM_CONFIG_PREF_AUTO                -- Acquire systems regardless of roaming status \n
       - 0x01 -- ROAM_CONFIG_PREF_HOME_ONLY           -- Acquire home systems only \n
       - 0x02 -- ROAM_CONFIG_PREF_ROAM_ONLY           -- Acquire nonhome systems only \n
       - 0x03 -- ROAM_CONFIG_PREF_HOME_AND_ AFFILIATE -- Acquire home and affiliated roaming systems only
  */

  /* Optional */
  /*  Force HDR SCP AT Config */
  uint8_t force_hdrscp_config_at_valid;  /**< Must be set to true if force_hdrscp_config_at is being passed */
  nas_force_hdrscp_config_at_enum_type_v01 force_hdrscp_config_at;
  /**<   
      Values: \n
        -0x00 -- HDR Rev0 Protocols only  \n
        -0x01 -- HDR RevA Protocols with MFPA \n
        -0x02 -- HDR RevA Protocols with MFPA and EMPA \n
        -0x03 -- HDR RevB Protocols with MMPA \n
        -0x04 -- HDR RevA Protocols with eHRPD \n
        -0x05 -- HDR RevB Protocols with eHRPD
  */
}nas_get_device_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets network-related configuration settings of the device. */
typedef struct {

  /* Optional */
  /*  Service Programming Code* */
  uint8_t spc_valid;  /**< Must be set to true if spc is being passed */
  char spc[NAS_SPC_MAX_V01];
  /**<   Service programming code in ASCII format (digits 0 to 9 only).
  */

  /* Optional */
  /*  Force HDR Revision* */
  uint8_t force_hdr_rev0_valid;  /**< Must be set to true if force_hdr_rev0 is being passed */
  uint8_t force_hdr_rev0;
  /**<   Force Rev0. Values: \n
    - 0x00 -- Disable \n
    - 0x01 -- Enable; enable may only be specified if HDR SCP Custom Config
              state is set to Disable \n
    Note: This TLV is now DISCONTINUED, and is present here as a
          placeholder only for existing clients referencing this TLV.
  */

  /* Optional */
  /*  HDR SCP Custom Config* */
  uint8_t hdr_scp_config_valid;  /**< Must be set to true if hdr_scp_config is being passed */
  nas_hdr_scp_config_type_v01 hdr_scp_config;
  /**<   \n
    Note: This TLV is now DISCONTINUED, and is present here as a
          placeholder only for existing clients referencing this TLV.
  */

  /* Optional */
  /*  Roam Preference* */
  uint8_t roam_pref_valid;  /**< Must be set to true if roam_pref is being passed */
  nas_roam_config_pref_enum_v01 roam_pref;
  /**<   Roaming preference. Values: \n
       - 0x00 -- ROAM_CONFIG_PREF_AUTO                -- Acquire systems regardless of roaming status \n
       - 0x01 -- ROAM_CONFIG_PREF_HOME_ONLY           -- Acquire home systems only \n
       - 0x02 -- ROAM_CONFIG_PREF_ROAM_ONLY           -- Acquire nonhome systems only \n
       - 0x03 -- ROAM_CONFIG_PREF_HOME_AND_ AFFILIATE -- Acquire home and affiliated roaming systems only
  */
}nas_set_device_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets network-related configuration settings of the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_device_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Queries radio band/channel information regarding the
              system currently providing service.  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_rf_band_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_radio_if_enum_v01 radio_if;
  /**<   Radio interface currently in use. Values:  \n
        - 0x01 -- cdma2000\textsuperscript{\textregistered} 1X             \n
        - 0x02 -- cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
        - 0x03 -- AMPS \n
        - 0x04 -- GSM \n
        - 0x05 -- UMTS \n
        - 0x08 -- LTE \n
        - 0x09 -- TD-SCDMA \n
        - 0x0C -- NR5G
   */

  nas_active_band_enum_v01 active_band;
  /**<   Active band class (see Table @latexonly\ref{tbl:bandClass}@endlatexonly 
       for details). Values: \n
       - 00 to 39   -- CDMA band classes  \n
       - 40 to 79   -- GSM band classes   \n
       - 80 to 91   -- WCDMA band classes \n
       - 120 to 174 -- LTE band classes   \n
       - 200 to 205 -- TD-SCDMA band classes \n
       - 250 to 281 -- NR-5G band classes
   */

  uint32_t active_channel;
  /**<   Active channel. If the channel is not relevant to the
       technology, a value of 0 is returned.
  */
}nas_rf_band_info_ext_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Queries radio band/channel information regarding the
              system currently providing service.  */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Mandatory */
  /*  RF Band Information List */
  uint32_t rf_band_info_list_len;  /**< Must be set to # of elements in rf_band_info_list */
  nas_rf_band_info_type_v01 rf_band_info_list[NAS_RF_BAND_INFO_LIST_MAX_V01];

  /* Optional */
  /*  RF Dedicated Band Information List */
  uint8_t rf_dedicated_band_info_list_valid;  /**< Must be set to true if rf_dedicated_band_info_list is being passed */
  uint32_t rf_dedicated_band_info_list_len;  /**< Must be set to # of elements in rf_dedicated_band_info_list */
  nas_rf_dedicated_band_info_type_v01 rf_dedicated_band_info_list[NAS_RF_BAND_INFO_LIST_MAX_V01];

  /* Optional */
  /*  RF Band Information List, Extended Format */
  uint8_t rf_band_info_list_ext_valid;  /**< Must be set to true if rf_band_info_list_ext is being passed */
  uint32_t rf_band_info_list_ext_len;  /**< Must be set to # of elements in rf_band_info_list_ext */
  nas_rf_band_info_ext_type_v01 rf_band_info_list_ext[NAS_RF_BAND_INFO_LIST_MAX_V01];
  /**<   \n
       (Extended sizes to accommodate LTE.) 
  */

  /* Optional */
  /*  RF Bandwidth Information List */
  uint8_t nas_rf_bandwidth_info_valid;  /**< Must be set to true if nas_rf_bandwidth_info is being passed */
  uint32_t nas_rf_bandwidth_info_len;  /**< Must be set to # of elements in nas_rf_bandwidth_info */
  nas_rf_bandwidth_info_type_v01 nas_rf_bandwidth_info[NAS_RF_BAND_INFO_LIST_MAX_V01];

  /* Optional */
  /*  LTE Operational Mode */
  uint8_t ciot_lte_op_mode_valid;  /**< Must be set to true if ciot_lte_op_mode is being passed */
  nas_camped_ciot_lte_op_mode_enum_type_v01 ciot_lte_op_mode;
}nas_get_rf_band_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Queries the status of the last AN-AAA authentication
              request for the current 1xEV-DO session. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_an_aaa_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_AN_AAA_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_AAA_STATUS_FAILED_V01 = 0x00, 
  NAS_AAA_STATUS_SUCCESS_V01 = 0x01, 
  NAS_AAA_STATUS_NO_REQUEST_V01 = 0x02, 
  NAS_AN_AAA_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_an_aaa_status_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Queries the status of the last AN-AAA authentication
              request for the current 1xEV-DO session. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Mandatory */
  /*  AN-AAA Authentication Status */
  nas_an_aaa_status_enum_v01 an_aaa_status;
  /**<   Status of the last AN-AAA authentication request, if any, for
       the current 1xEV-DO session. Values: \n
       - 0 -- AAA_STATUS_FAILED     -- Authentication failed \n
       - 1 -- AAA_STATUS_SUCCESS    -- Authentication success \n
       - 2 -- AAA_STATUS_NO_REQUEST -- No authentication requested 
  */
}nas_get_an_aaa_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_PRL_PREF_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_PRL_PREF_A_SIDE_ONLY_V01 = 0x0001, 
  NAS_PRL_PREF_B_SIDE_ONLY_V01 = 0x0002, 
  NAS_PRL_PREF_ANY_V01 = 0x3FFF, 
  NAS_PRL_PREF_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_prl_pref_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_ROAM_PREF_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_ROAMING_PREF_OFF_V01 = 0x01, 
  NAS_ROAMING_PREF_NOT_OFF_V01 = 0x02, 
  NAS_ROAMING_PREF_NOT_FLASING_V01 = 0x03, 
  NAS_ROAMING_PREF_ANY_V01 = 0xFF, 
  NAS_ROAM_PREF_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_roam_pref_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_NET_SEL_PREF_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_NET_SEL_PREF_AUTOMATIC_V01 = 0x00, 
  NAS_NET_SEL_PREF_MANUAL_V01 = 0x01, 
  NAS_NET_SEL_PREF_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_net_sel_pref_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_SRV_DOMAIN_PREF_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QMI_SRV_DOMAIN_PREF_CS_ONLY_V01 = 0x00, /**<  Circuit-switched only \n  */
  QMI_SRV_DOMAIN_PREF_PS_ONLY_V01 = 0x01, /**<  Packet-switched only \n  */
  QMI_SRV_DOMAIN_PREF_CS_PS_V01 = 0x02, /**<  Circuit-switched and packet-switched \n  */
  QMI_SRV_DOMAIN_PREF_PS_ATTACH_V01 = 0x03, /**<  Packet-switched attach \n  */
  QMI_SRV_DOMAIN_PREF_PS_DETACH_V01 = 0x04, /**<  Packet-switched detach \n  */
  QMI_SRV_DOMAIN_PREF_PS_DETACH_NO_PREF_CHANGE_V01 = 0x05, /**<  Packet-switched \n  */
  QMI_SRV_DOMAIN_PREF_ON_DEMAND_PS_ATTACH_V01 = 0x06, /**<  Packet-switched detach with no change in the service domain preference \n  */
  QMI_SRV_DOMAIN_PREF_FORCE_PS_DETACH_V01 = 0x07, /**<  Packet-switched detach where PS service loss is done forcibly by the modem.    */
  NAS_SRV_DOMAIN_PREF_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_srv_domain_pref_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_GW_ACQ_ORDER_PREF_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_GW_ACQ_ORDER_PREF_AUTOMATIC_V01 = 0x00, 
  NAS_GW_ACQ_ORDER_PREF_GSM_WCDMA_V01 = 0x01, 
  NAS_GW_ACQ_ORDER_PREF_WCDMA_GSM_V01 = 0x02, 
  NAS_GW_ACQ_ORDER_PREF_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_gw_acq_order_pref_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_SRV_REG_RESTRICTION_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_SRV_REG_RESTRICTION_UNRESTRICTED_V01 = 0x00, 
  NAS_SRV_REG_RESTRICTION_CAMPED_ONLY_V01 = 0x01, 
  NAS_SRV_REG_RESTRICTION_LIMITED_V01 = 0x02, 
  NAS_SRV_REG_RESTRICTION_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_srv_reg_restriction_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_USAGE_PREF_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_USAGE_UNKNOWN_V01 = 0, /**<  Unknown \n  */
  NAS_USAGE_VOICE_CENTRIC_V01 = 1, /**<  Voice centric \n  */
  NAS_USAGE_DATA_CENTRIC_V01 = 2, /**<  Data centric  */
  NAS_USAGE_PREF_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_usage_pref_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_VOICE_DOMAIN_PREF_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_VOICE_DOMAIN_PREF_CS_ONLY_V01 = 0x00, /**<  Circuit-switched (CS) voice only \n  */
  NAS_VOICE_DOMAIN_PREF_PS_ONLY_V01 = 0x01, /**<  Packet-switched (PS) voice only \n  */
  NAS_VOICE_DOMAIN_PREF_CS_PREF_V01 = 0x02, /**<  CS is preferred; PS is secondary \n  */
  NAS_VOICE_DOMAIN_PREF_PS_PREF_V01 = 0x03, /**<  PS is preferred; CS is secondary  */
  NAS_VOICE_DOMAIN_PREF_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_voice_domain_pref_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_ACQ_ORDER_PREF_RADIO_IF_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_RADIO_NO_SVC_V01 = 0x00, /**<  None (no service) \n  */
  NAS_RADIO_CDMA_1X_V01 = 0x01, /**<  cdma2000\textsuperscript{\textregistered} 1X \n  */
  NAS_RADIO_CDMA_1XEVDO_V01 = 0x02, /**<  cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n  */
  NAS_RADIO_AMPS_V01 = 0x03, /**<  AMPS \n  */
  NAS_RADIO_GSM_V01 = 0x04, /**<  GSM \n  */
  NAS_RADIO_UMTS_V01 = 0x05, /**<  UMTS \n  */
  NAS_RADIO_WLAN_V01 = 0x06, /**<  WLAN \n  */
  NAS_RADIO_GPS_V01 = 0x07, /**<  GPS \n  */
  NAS_RADIO_LTE_V01 = 0x08, /**<  LTE \n  */
  NAS_RADIO_TDSCDMA_V01 = 0x09, /**<  TD-SCDMA \n  */
  NAS_RADIO_LTE_M1_V01 = 0x0a, /**<  LTE-M1 \n  */
  NAS_RADIO_LTE_NB1_V01 = 0x0b, /**<  LTE-M1 \n  */
  NAS_RADIO_NR5G_V01 = 0x0c, /**<  NR5G \n  */
  NAS_RADIO_NO_CHANGE_V01 = -1, /**<  No change  */
  NAS_ACQ_ORDER_PREF_RADIO_IF_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_acq_order_pref_radio_if_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_net_sel_pref_enum_v01 net_sel_pref;
  /**<   Specifies one of the following actions: \n
       - 0x00 -- NAS_NET_SEL_PREF_AUTOMATIC -- 
                 Device registers according to its provisioning; 
                 mcc and mnc fields must also contain valid values 
                 if Radio Access Technology (TLV 0x22) is present. 
                 Otherwise, mcc and mnc are ignored. \n
       - 0x01 -- NAS_NET_SEL_PREF_MANUAL -- 
                 Device registers to specified network; 
                 mcc and mnc fields must also contain valid values.
       
       \vspace{3pt}
       All other values are reserved.
  */

  uint16_t mcc;
  /**<   A 16-bit integer representation of MCC. Range: 0 to 999.
  */

  uint16_t mnc;
  /**<   A 16-bit integer representation of MNC. Range: 0 to 999.
  */
}nas_net_sel_pref_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t mcc;
  /**<   A 16-bit integer representation of CSG MCC. Range: 0 to 999.
  */

  uint16_t mnc;
  /**<   A 16-bit integer representation of CSG MNC. Range: 0 to 999.
  */

  uint8_t mnc_includes_pcs_digit;
  /**<   This field is used to interpret the length of the corresponding
       MNC reported in the TLVs (in this table) with an mnc or 
       mobile_network_code field. Values: \n

       - TRUE  -- MNC is a three-digit value; e.g., a reported value of 
                  90 corresponds to an MNC value of 090  \n
       - FALSE -- MNC is a two-digit value; e.g., a reported value of 
                  90 corresponds to an MNC value of 90
  */

  uint32_t id;
  /**<   Closed subscriber group identifier.
  */

  nas_radio_if_enum_v01 rat;
  /**<   Radio interface technology of the CSG network. Values: \n
       -0x04 -- RADIO_IF_GSM         -- GSM \n
       -0x05 -- RADIO_IF_UMTS        -- UMTS \n
       -0x08 -- RADIO_IF_LTE         -- LTE \n
       -0x09 -- RADIO_IF_TDSCDMA     -- TDS
  */
}nas_csg_nw_iden_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets the different system selection preferences of the device.
              \label{idl:setSysSelPref} */
typedef struct {

  /* Optional */
  /*  Emergency Mode */
  uint8_t emergency_mode_valid;  /**< Must be set to true if emergency_mode is being passed */
  uint8_t emergency_mode;
  /**<   Values: \n
       - 0x00 -- OFF (normal) \n
       - 0x01 -- ON (emergency)
  */

  /* Optional */
  /*  Mode Preference */
  uint8_t mode_pref_valid;  /**< Must be set to true if mode_pref is being passed */
  mode_pref_mask_type_v01 mode_pref;
  /**<   Bitmask representing the radio technology mode preference to be set. 
       Values: \n
       - Bit 0 (0x01) -- QMI_NAS_RAT_MODE_PREF_ CDMA2000_1X    -- 
         cdma2000\textsuperscript{\textregistered} 1X             \n
       - Bit 1 (0x02) -- QMI_NAS_RAT_MODE_PREF_ CDMA2000_HRPD  -- 
         cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
       - Bit 2 (0x04) -- QMI_NAS_RAT_MODE_PREF_ GSM            -- GSM \n
       - Bit 3 (0x08) -- QMI_NAS_RAT_MODE_PREF_ UMTS           -- UMTS \n
       - Bit 4 (0x10) -- QMI_NAS_RAT_MODE_PREF_ LTE            -- LTE \n
       - Bit 5 (0x20) -- QMI_NAS_RAT_MODE_PREF_ TDSCDMA        -- TD-SCDMA \n
       - Bit 6 (0x40) -- QMI_NAS_RAT_MODE_PREF_ NR5G           -- NR5G

       \vspace{3pt}
       All unlisted bits are reserved for future use and the service point
       ignores them if used.
  */

  /* Optional */
  /*  Band Preference */
  uint8_t band_pref_valid;  /**< Must be set to true if band_pref is being passed */
  nas_band_pref_mask_type_v01 band_pref;
  /**<   Bitmask representing the band preference to be set.  
       See Table @latexonly\ref{tbl:bandPreference}@endlatexonly 
       for details.   
  */

  /* Optional */
  /*  CDMA PRL Preference */
  uint8_t prl_pref_valid;  /**< Must be set to true if prl_pref is being passed */
  nas_prl_pref_enum_v01 prl_pref;
  /**<   PRL preference to be set for band class 0 (BC0) prl_pref. Values: \n
       - 0x0001 -- PRL_PREF_A_SIDE_ONLY -- Acquire available system only on the A side \n
       - 0x0002 -- PRL_PREF_B_SIDE_ONLY -- Acquire available system only on the B side \n
       - 0x3FFF -- PRL_PREF_ANY         -- Acquire any available systems
  */

  /* Optional */
  /*  Roaming Preference */
  uint8_t roam_pref_valid;  /**< Must be set to true if roam_pref is being passed */
  nas_roam_pref_enum_v01 roam_pref;
  /**<   Roaming preference to be set. Values: \n
       - 0x01 -- ROAMING_PREF_OFF         -- Acquire only systems for which the roaming indicator is off \n
       - 0x02 -- ROAMING_PREF_NOT_OFF     -- Acquire a system as long as its roaming indicator is not off \n
       - 0x03 -- ROAMING_PREF_NOT_FLASING -- Acquire only systems for which the roaming indicator is off or solid on, i.e., not flashing; CDMA only \n
       - 0xFF -- ROAMING_PREF_ANY         -- Acquire systems, regardless of their roaming indicator
  */

  /* Optional */
  /*  LTE Band Preference (Deprecated; use LTE Band Preference Extended) */
  uint8_t lte_band_pref_valid;  /**< Must be set to true if lte_band_pref is being passed */
  lte_band_pref_mask_type_v01 lte_band_pref;
  /**<   Bitmask representing the LTE band preference to be set. 
       See Table @latexonly\ref{tbl:lteBandPreference}@endlatexonly 
       for details.  
  */

  /* Optional */
  /*  Network Selection Preference */
  uint8_t net_sel_pref_valid;  /**< Must be set to true if net_sel_pref is being passed */
  nas_net_sel_pref_type_v01 net_sel_pref;

  /* Optional */
  /*  Change Duration */
  uint8_t change_duration_valid;  /**< Must be set to true if change_duration is being passed */
  nas_change_duration_enum_v01 change_duration;
  /**<    Duration of the change. Values: \n
        - 0x00 -- Power cycle -- Remains active until the next device power cycle \n
        - 0x01 -- Permanent -- Remains active through power cycles until changed by the client \n
        Note: The device will use "0x01 -- Permanent" as the default value 
              if the TLV is omitted.
  */

  /* Optional */
  /*  Service Domain */
  uint8_t srv_domain_pref_valid;  /**< Must be set to true if srv_domain_pref is being passed */
  nas_srv_domain_pref_enum_type_v01 srv_domain_pref;
  /**<   Service domain preference. Values: \n
      - QMI_SRV_DOMAIN_PREF_CS_ONLY (0x00) --  Circuit-switched only \n 
      - QMI_SRV_DOMAIN_PREF_PS_ONLY (0x01) --  Packet-switched only \n 
      - QMI_SRV_DOMAIN_PREF_CS_PS (0x02) --  Circuit-switched and packet-switched \n 
      - QMI_SRV_DOMAIN_PREF_PS_ATTACH (0x03) --  Packet-switched attach \n 
      - QMI_SRV_DOMAIN_PREF_PS_DETACH (0x04) --  Packet-switched detach \n 
      - QMI_SRV_DOMAIN_PREF_PS_DETACH_NO_PREF_CHANGE (0x05) --  Packet-switched \n 
      - QMI_SRV_DOMAIN_PREF_ON_DEMAND_PS_ATTACH (0x06) --  Packet-switched detach with no change in the service domain preference \n 
      - QMI_SRV_DOMAIN_PREF_FORCE_PS_DETACH (0x07) --  Packet-switched detach where PS service loss is done forcibly by the modem.   
 */

  /* Optional */
  /*  GSM/WCDMA Acquisition Order */
  uint8_t gw_acq_order_pref_valid;  /**< Must be set to true if gw_acq_order_pref is being passed */
  nas_gw_acq_order_pref_enum_type_v01 gw_acq_order_pref;
  /**<    GSM/WCDMA acquisition order preference. Values: \n
       - 0x00 -- NAS_GW_ACQ_ORDER_PREF_ AUTOMATIC -- Automatic \n
       - 0x01 -- NAS_GW_ACQ_ORDER_PREF_ GSM_WCDMA -- GSM then WCDMA \n
       - 0x02 -- NAS_GW_ACQ_ORDER_PREF_ WCDMA_GSM -- WCDMA then GSM
  */

  /* Optional */
  /* MNC PCS Digit Include Status */
  uint8_t mnc_includes_pcs_digit_valid;  /**< Must be set to true if mnc_includes_pcs_digit is being passed */
  uint8_t mnc_includes_pcs_digit;
  /**<   This field is used to interpret the length of the corresponding
       MNC reported in the Network Selection Preference TLV (0x16). Values: \n

       - TRUE  -- MNC is a three-digit value; e.g., a reported value of 
                  90 corresponds to an MNC value of 090  \n
       - FALSE -- MNC is a two-digit value; e.g., a reported value of 
                  90 corresponds to an MNC value of 90
  */

  /* Optional */
  /*  TDSCDMA Band Preference */
  uint8_t tdscdma_band_pref_valid;  /**< Must be set to true if tdscdma_band_pref is being passed */
  nas_tdscdma_band_pref_mask_type_v01 tdscdma_band_pref;
  /**<   Bitmask representing the TD-SCDMA band preference to be set. Values: \n
       - 0x01 -- NAS_TDSCDMA_BAND_A  -- TD-SCDMA Band A \n
       - 0x02 -- NAS_TDSCDMA_BAND_B  -- TD-SCDMA Band B \n
       - 0x04 -- NAS_TDSCDMA_BAND_C  -- TD-SCDMA Band C \n
       - 0x08 -- NAS_TDSCDMA_BAND_D  -- TD-SCDMA Band D \n
       - 0x10 -- NAS_TDSCDMA_BAND_E  -- TD-SCDMA Band E \n
       - 0x20 -- NAS_TDSCDMA_BAND_F  -- TD-SCDMA Band F

       \vspace{3pt}
       All other bits are reserved.
  */

  /* Optional */
  /*  Acquisition Order Preference */
  uint8_t acq_order_valid;  /**< Must be set to true if acq_order is being passed */
  uint32_t acq_order_len;  /**< Must be set to # of elements in acq_order */
  nas_radio_if_enum_v01 acq_order[NAS_ACQ_ORDER_LIST_MAX_V01];
  /**<   Acquisition order preference to be set. Values: \n
    - 0x01 -- NAS_RADIO_IF_CDMA_1X     -- 
      cdma2000\textsuperscript{\textregistered} 1X             \n
    - 0x02 -- NAS_RADIO_IF_CDMA_1XEVDO -- 
      cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
    - 0x04 -- NAS_RADIO_IF_GSM         -- GSM \n
    - 0x05 -- NAS_RADIO_IF_UMTS        -- UMTS \n
    - 0x08 -- NAS_RADIO_IF_LTE         -- LTE \n
    - 0x09 -- NAS_RADIO_IF_TDSCDMA     -- TD-SCDMA \n
    - 0x0C -- NAS_RADIO_IF_NR5G        -- NR5G
  */

  /* Optional */
  /*  Network Selection Registration Restriction Preference */
  uint8_t srv_reg_restriction_valid;  /**< Must be set to true if srv_reg_restriction is being passed */
  nas_srv_reg_restriction_enum_v01 srv_reg_restriction;
  /**<   Registration restriction preference. Specifies one of the following 
       modifiers to net_sel_pref: \n
    - 0x00 -- NAS_SRV_REG_RESTRICTION_ UNRESTRICTED -- Device follows the normal 
              registration process \n
    - 0x01 -- NAS_SRV_REG_RESTRICTION_ CAMPED_ONLY -- Device camps on the network 
              according to its provisioning, but does not register \n
    - 0x02 -- NAS_SRV_REG_RESTRICTION_ LIMITED -- Device selects the network for 
              limited service

    \vspace{3pt}
    All other values are reserved.
   */

  /* Optional */
  /*  CSG ID */
  uint8_t csg_info_valid;  /**< Must be set to true if csg_info is being passed */
  nas_csg_nw_iden_type_v01 csg_info;

  /* Optional */
  /*  Usage Preference */
  uint8_t usage_setting_valid;  /**< Must be set to true if usage_setting is being passed */
  nas_usage_pref_enum_v01 usage_setting;
  /**<   Modem usage preference to be set. Values: \n
      - NAS_USAGE_VOICE_CENTRIC (1) --  Voice centric \n 
      - NAS_USAGE_DATA_CENTRIC (2) --  Data centric 
 */

  /* Optional */
  /*  Radio Access Technology */
  uint8_t rat_valid;  /**< Must be set to true if rat is being passed */
  nas_radio_if_enum_v01 rat;
  /**<   Radio access technology for the corresponding PLMN ID in the Network 
       Selection Preference TLV (0x16). If this TLV is present and the 
       net_sel_pref field is set to automatic, the provided MCC, MNC, and RAT 
       are searched for first. If they are not found, the selection falls 
       back to automatic. This TLV can also be used with the net_sel_pref 
       field set to manual to indicate the RAT of the specified MCC and MNC. \n
       Values: \n
    - 0x04 -- NAS_RADIO_IF_GSM         -- GSM \n
    - 0x05 -- NAS_RADIO_IF_UMTS        -- UMTS \n
    - 0x08 -- NAS_RADIO_IF_LTE         -- LTE \n
    - 0x09 -- NAS_RADIO_IF_TDSCDMA     -- TD-SCDMA \n
    - 0x0A -- NAS_RADIO_IF_LTE_M1      -- LTE-M1 \n
    - 0x0B -- NAS_RADIO_IF_LTE_NB1     -- LTE-NB1 \n
    - 0x0C -- NAS_RADIO_IF_NR5G        -- NR5G
  */

  /* Optional */
  /*  Voice Domain Preference */
  uint8_t voice_domain_pref_valid;  /**< Must be set to true if voice_domain_pref is being passed */
  nas_voice_domain_pref_enum_type_v01 voice_domain_pref;
  /**<   Voice domain preference to be set. Values: \n
      - NAS_VOICE_DOMAIN_PREF_CS_ONLY (0x00) --  Circuit-switched (CS) voice only \n 
      - NAS_VOICE_DOMAIN_PREF_PS_ONLY (0x01) --  Packet-switched (PS) voice only \n 
      - NAS_VOICE_DOMAIN_PREF_CS_PREF (0x02) --  CS is preferred; PS is secondary \n 
      - NAS_VOICE_DOMAIN_PREF_PS_PREF (0x03) --  PS is preferred; CS is secondary 
 */

  /* Optional */
  /*  LTE Band Preference Extended */
  uint8_t lte_band_pref_ext_valid;  /**< Must be set to true if lte_band_pref_ext is being passed */
  lte_band_pref_mask_ext_type_v01 lte_band_pref_ext;

  /* Optional */
  /*  Force Preferences */
  uint8_t force_valid;  /**< Must be set to true if force is being passed */
  uint8_t force;
  /**<    When TRUE, indicates that the UE cannot process the 
       request due to an LPM transition, the lower layer is busy, etc.
       The request is buffered and processed as soon as possible instead of 
       returning an error. The default value is FALSE.
  */

  /* Optional */
  /*  CIOT LTE Operational Mode Preference */
  uint8_t ciot_lte_op_mode_pref_valid;  /**< Must be set to true if ciot_lte_op_mode_pref is being passed */
  ciot_lte_op_mode_pref_mask_type_v01 ciot_lte_op_mode_pref;
  /**<   Bitmask representing the CIoT LTE operational mode preference to be set.
       Values: \n
       - Bit 0 (0x01) -- QMI_NAS_CIOT_LTE_OP_ MODE_PREF_WB   -- LTE wideband \n
       - Bit 1 (0x02) -- QMI_NAS_CIOT_LTE_OP_ MODE_PREF_M1   -- LTE M1 \n
       - Bit 2 (0x04) -- QMI_NAS_CIOT_LTE_OP_ MODE_PREF_NB1  -- LTE NB1

       \vspace{3pt}
       All unlisted bits are reserved for future use and the service point
       ignores them if used. 

       \vspace{3pt}
       If this TLV is not present, the modem will use the value read from
       the NV during bootup.
  */

  /* Optional */
  /*  LTE M1 Band Preference (Deprecated; use LTE M1 Band Preference Extended) */
  uint8_t lte_m1_band_pref_valid;  /**< Must be set to true if lte_m1_band_pref is being passed */
  lte_band_pref_mask_type_v01 lte_m1_band_pref;
  /**<   Bitmask representing the LTE M1 band preference to be set.
       See Table @latexonly\ref{tbl:lteBandPreference}@endlatexonly 
       for details. 

       \vspace{3pt}
       If this field is not present, the modem will use the 
       M1 band preference value read from the NV.
  */

  /* Optional */
  /*  LTE NB1 Band Preference (Deprecated; use LTE NB1 Band Preference Extended) */
  uint8_t lte_nb1_band_pref_valid;  /**< Must be set to true if lte_nb1_band_pref is being passed */
  lte_band_pref_mask_type_v01 lte_nb1_band_pref;
  /**<   Bitmask representing the LTE NB1 band preference to be set.
       See Table @latexonly\ref{tbl:lteBandPreference}@endlatexonly 
       for details.
 
       \vspace{3pt}
       If this field is not present, the modem will use the 
       NB1 band preference value read from the NV.
  */

  /* Optional */
  /*  LTE Operational Mode */
  uint8_t man_ciot_lte_mode_valid;  /**< Must be set to true if man_ciot_lte_mode is being passed */
  nas_camped_ciot_lte_op_mode_enum_type_v01 man_ciot_lte_mode;
  /**<   This TLV is used when the net_sel_pref is MANUAL and RAT TLV is LTE.

 This TLV indicates the the operational mode to be used during the manual
 LTE PLMN selection. Values: \n
 
      - NAS_CIOT_SYS_MODE_NO_SRV (0x00) --  No service \n 
      - NAS_CIOT_SYS_MODE_LTE_WB (0x01) --  Camped on LTE wideband \n 
      - NAS_CIOT_SYS_MODE_LTE_M1 (0x02) --  Camped on LTE M1 \n 
      - NAS_CIOT_SYS_MODE_LTE_NB1 (0x03) --  Camped on LTE NB1  
 */

  /* Optional */
  /*  CIOT Acquisition Order Preference */
  uint8_t ciot_acq_order_valid;  /**< Must be set to true if ciot_acq_order is being passed */
  uint32_t ciot_acq_order_len;  /**< Must be set to # of elements in ciot_acq_order */
  nas_acq_order_pref_radio_if_enum_v01 ciot_acq_order[NAS_ACQ_ORDER_LIST_MAX_V01];
  /**<   CIOT Acquisition order preference to be set. Values: \n
    - 0x01 -- NAS_RADIO_CDMA_1X     -- 
      cdma2000\textsuperscript{\textregistered} 1X             \n
    - 0x02 -- NAS_RADIO_CDMA_1XEVDO -- 
      cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
    - 0x04 -- NAS_RADIO_GSM         -- GSM \n
    - 0x05 -- NAS_RADIO_UMTS        -- UMTS \n
    - 0x08 -- NAS_RADIO_LTE         -- LTE \n
    - 0x09 -- NAS_RADIO_TDSCDMA     -- TD-SCDMA\n
    - 0x0a -- NAS_RADIO_LTE_M1     -- LTE_M1\n
    - 0x0b -- NAS_RADIO_LTE_NB1     -- LTE_NB1
  */

  /* Optional */
  /*  NR5G Band Preference */
  uint8_t nr5g_band_pref_valid;  /**< Must be set to true if nr5g_band_pref is being passed */
  nas_nr5g_band_pref_mask_type_v01 nr5g_band_pref;

  /* Optional */
  /*  LTE M1 Band Preference Extended */
  uint8_t lte_m1_band_pref_ext_valid;  /**< Must be set to true if lte_m1_band_pref_ext is being passed */
  lte_band_pref_mask_ext_type_v01 lte_m1_band_pref_ext;
  /**<   Bitmask representing the LTE M1 band preference to be set.

       \vspace{3pt}
       If this field is not present, the modem will use the 
       M1 band preference value read from the NV.
  */

  /* Optional */
  /*  LTE NB1 Band Preference Extended */
  uint8_t lte_nb1_band_pref_ext_valid;  /**< Must be set to true if lte_nb1_band_pref_ext is being passed */
  lte_band_pref_mask_ext_type_v01 lte_nb1_band_pref_ext;
  /**<   Bitmask representing the LTE NB1 band preference to be set.
 
       \vspace{3pt}
       If this field is not present, the modem will use the 
       NB1 band preference value read from the NV.
  */

  /* Optional */
  /*  NR5G NSA Band Preference */
  uint8_t nsa_nr5g_band_pref_valid;  /**< Must be set to true if nsa_nr5g_band_pref is being passed */
  nas_nr5g_band_pref_mask_type_v01 nsa_nr5g_band_pref;
}nas_set_system_selection_preference_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets the different system selection preferences of the device.
              \label{idl:setSysSelPref} */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_system_selection_preference_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Queries the different system selection preferences of the 
              device.
              \label{idl:getSysSelPref} */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_system_selection_preference_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_LTE_DISABLE_CAUSE_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_LTE_DISABLE_CAUSE_NONE_V01 = 0x00, /**<  LTE is not disabled \n  */
  NAS_LTE_DISABLE_CAUSE_PERMANENT_DS_V01 = 0x01, /**<  LTE is disabled by DS permanently, e.g., T3316 expiry \n  */
  NAS_LTE_DISABLE_CAUSE_TEMP_DS_V01 = 0x02, /**<  LTE is disabled by DS temporarily \n  */
  NAS_LTE_DISABLE_CAUSE_DOM_SEL_V01 = 0x03, /**<  LTE disable procedure is called for domain selection purpose \n  */
  NAS_LTE_DISABLE_CAUSE_DAM_V01 = 0x04, /**<  LTE disable procedure is called for device aggression management recovery  */
  NAS_LTE_DISABLE_CAUSE_USER_V01 = 0x05, /**<  LTE disable procedure is called due to user action, 
       e.g., mode_pref change or PS_DETACH triggered by ATCOP/QMI \n  */
  NAS_LTE_DISABLE_CAUSE_NO_CHANGE_V01 = 0x06, /**<  No change in LTE disable cause  */
  NAS_LTE_DISABLE_CAUSE_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_lte_disable_cause_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Queries the different system selection preferences of the 
              device.
              \label{idl:getSysSelPref} */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  Emergency Mode */
  uint8_t emergency_mode_valid;  /**< Must be set to true if emergency_mode is being passed */
  uint8_t emergency_mode;
  /**<   Values: \n
       - 0x00 -- OFF (normal) \n
       - 0x01 -- ON (emergency)
  */

  /* Optional */
  /*  Mode Preference */
  uint8_t mode_pref_valid;  /**< Must be set to true if mode_pref is being passed */
  mode_pref_mask_type_v01 mode_pref;
  /**<   Bitmask representing the radio technology mode preference to be set. 
       Values: \n
       - Bit 0 (0x01) -- QMI_NAS_RAT_MODE_PREF_ CDMA2000_1X    -- 
         cdma2000\textsuperscript{\textregistered} 1X             \n
       - Bit 1 (0x02) -- QMI_NAS_RAT_MODE_PREF_ CDMA2000_HRPD  -- 
         cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
       - Bit 2 (0x04) -- QMI_NAS_RAT_MODE_PREF_ GSM            -- GSM \n
       - Bit 3 (0x08) -- QMI_NAS_RAT_MODE_PREF_ UMTS           -- UMTS \n
       - Bit 4 (0x10) -- QMI_NAS_RAT_MODE_PREF_ LTE            -- LTE \n
       - Bit 5 (0x20) -- QMI_NAS_RAT_MODE_PREF_ TDSCDMA        -- TD-SCDMA \n
       - Bit 6 (0x40) -- QMI_NAS_RAT_MODE_PREF_ NR5G           -- NR5G

       \vspace{3pt}
       All unlisted bits are reserved for future use and the service point
       ignores them if used.
  */

  /* Optional */
  /*  Band Preference */
  uint8_t band_pref_valid;  /**< Must be set to true if band_pref is being passed */
  nas_band_pref_mask_type_v01 band_pref;
  /**<   Bitmask representing the band preference to be set. 
       See Table @latexonly\ref{tbl:bandPreference}@endlatexonly 
       for details.   
  */

  /* Optional */
  /*  CDMA PRL Preference */
  uint8_t prl_pref_valid;  /**< Must be set to true if prl_pref is being passed */
  nas_prl_pref_enum_v01 prl_pref;
  /**<   PRL preference to be set for band class 0 (BC0) prl_pref. Values: \n
       - 0x0001 -- PRL_PREF_A_SIDE_ONLY -- Acquire available system only on the A side \n
       - 0x0002 -- PRL_PREF_B_SIDE_ONLY -- Acquire available system only on the B side \n
       - 0x3FFF -- PRL_PREF_ANY         -- Acquire any available systems
  */

  /* Optional */
  /*  Roaming Preference */
  uint8_t roam_pref_valid;  /**< Must be set to true if roam_pref is being passed */
  nas_roam_pref_enum_v01 roam_pref;
  /**<   Roaming preference to be set. Values: \n
       - 0x01 -- ROAMING_PREF_OFF         -- Acquire only systems for which the roaming indicator is off \n
       - 0x02 -- ROAMING_PREF_NOT_OFF     -- Acquire a system as long as its roaming indicator is not off \n
       - 0x03 -- ROAMING_PREF_NOT_FLASING -- Acquire only systems for which the roaming indicator is off or solid on, i.e., not flashing; CDMA only \n
       - 0xFF -- ROAMING_PREF_ANY         -- Acquire systems, regardless of their roaming indicator
  */

  /* Optional */
  /*  LTE Band Preference (Deprecated; use LTE Band Preference Extended) */
  uint8_t band_pref_ext_valid;  /**< Must be set to true if band_pref_ext is being passed */
  uint64_t band_pref_ext;
  /**<   Bitmask representing the LTE band preference to be set. Values: \n
         - Bit 0  -- E-UTRA Operating Band 1 \n
         - Bit 1  -- E-UTRA Operating Band 2 \n
         - Bit 2  -- E-UTRA Operating Band 3 \n
         - Bit 3  -- E-UTRA Operating Band 4 \n
         - Bit 4  -- E-UTRA Operating Band 5 \n
         - Bit 5  -- E-UTRA Operating Band 6 \n
         - Bit 6  -- E-UTRA Operating Band 7 \n
         - Bit 7  -- E-UTRA Operating Band 8 \n
         - Bit 8  -- E-UTRA Operating Band 9 \n
         - Bit 9  -- E-UTRA Operating Band 10 \n
         - Bit 10 -- E-UTRA Operating Band 11 \n
         - Bit 11 -- E-UTRA Operating Band 12 \n
         - Bit 12 -- E-UTRA Operating Band 13 \n
         - Bit 13 -- E-UTRA Operating Band 14 \n
         - Bit 16 -- E-UTRA Operating Band 17 \n
         - Bit 17 -- E-UTRA Operating Band 18 \n
         - Bit 18 -- E-UTRA Operating Band 19 \n
         - Bit 19 -- E-UTRA Operating Band 20 \n
         - Bit 20 -- E-UTRA Operating Band 21 \n
         - Bit 23 -- E-UTRA Operating Band 24 \n
         - Bit 24 -- E-UTRA Operating Band 25 \n
         - Bit 32 -- E-UTRA Operating Band 33 \n
         - Bit 33 -- E-UTRA Operating Band 34 \n
         - Bit 34 -- E-UTRA Operating Band 35 \n
         - Bit 35 -- E-UTRA Operating Band 36 \n
         - Bit 36 -- E-UTRA Operating Band 37 \n
         - Bit 37 -- E-UTRA Operating Band 38 \n
         - Bit 38 -- E-UTRA Operating Band 39 \n
         - Bit 39 -- E-UTRA Operating Band 40 \n
         - Bit 40 -- E-UTRA Operating Band 41 \n
         - Bit 41 -- E-UTRA Operating Band 42 \n
         - Bit 42 -- E-UTRA Operating Band 43

         \vspace{3pt}
         All other bits are reserved.
  */

  /* Optional */
  /*  Network Selection Preference */
  uint8_t net_sel_pref_valid;  /**< Must be set to true if net_sel_pref is being passed */
  nas_net_sel_pref_enum_v01 net_sel_pref;
  /**<   Network selection preference. Values: \n
       - 0x00 -- Automatic network selection \n
       - 0x01 -- Manual network selection
  */

  /* Optional */
  /*  Service Domain Preference */
  uint8_t srv_domain_pref_valid;  /**< Must be set to true if srv_domain_pref is being passed */
  nas_srv_domain_pref_enum_type_v01 srv_domain_pref;
  /**<   Service domain preference. Values: \n
       - 0x00  -- QMI_SRV_DOMAIN_PREF_CS_ONLY -- Circuit-switched only \n
       - 0x01  -- QMI_SRV_DOMAIN_PREF_PS_ONLY -- Packet-switched only  \n
       - 0x02  -- QMI_SRV_DOMAIN_PREF_CS_PS   -- Circuit-switched and packet-switched
  */

  /* Optional */
  /*  GSM/WCDMA Acquisition Order Preference */
  uint8_t gw_acq_order_pref_valid;  /**< Must be set to true if gw_acq_order_pref is being passed */
  nas_gw_acq_order_pref_enum_type_v01 gw_acq_order_pref;
  /**<   GSM/WCDMA acquisition order preference. Values: \n
       - 0x00 -- NAS_GW_ACQ_ORDER_PREF_ AUTOMATIC -- Automatic \n
       - 0x01 -- NAS_GW_ACQ_ORDER_PREF_ GSM_WCDMA -- GSM then WCDMA \n
       - 0x02 -- NAS_GW_ACQ_ORDER_PREF_ WCDMA_GSM -- WCDMA then GSM
    */

  /* Optional */
  /*  TDSCDMA Band Preference */
  uint8_t tdscdma_band_pref_valid;  /**< Must be set to true if tdscdma_band_pref is being passed */
  nas_tdscdma_band_pref_mask_type_v01 tdscdma_band_pref;
  /**<   Bitmask representing the TD-SCDMA band preference to be set. Values: \n
       - 0x01 -- NAS_TDSCDMA_BAND_A  -- TD-SCDMA Band A \n
       - 0x02 -- NAS_TDSCDMA_BAND_B  -- TD-SCDMA Band B \n
       - 0x04 -- NAS_TDSCDMA_BAND_C  -- TD-SCDMA Band C \n
       - 0x08 -- NAS_TDSCDMA_BAND_D  -- TD-SCDMA Band D \n
       - 0x10 -- NAS_TDSCDMA_BAND_E  -- TD-SCDMA Band E \n
       - 0x20 -- NAS_TDSCDMA_BAND_F  -- TD-SCDMA Band F

       \vspace{3pt}
       All other bits are reserved.
  */

  /* Optional */
  /*  Manual Network Selection PLMN */
  uint8_t manual_net_sel_plmn_valid;  /**< Must be set to true if manual_net_sel_plmn is being passed */
  nas_mnc_pcs_digit_include_status_type_v01 manual_net_sel_plmn;

  /* Optional */
  /*  Acquisition Order Preference */
  uint8_t acq_order_valid;  /**< Must be set to true if acq_order is being passed */
  uint32_t acq_order_len;  /**< Must be set to # of elements in acq_order */
  nas_radio_if_enum_v01 acq_order[NAS_ACQ_ORDER_LIST_MAX_V01];
  /**<   Acquisition order preference to be set. Values: \n
    - 0x01 -- NAS_RADIO_IF_CDMA_1X     -- 
      cdma2000\textsuperscript{\textregistered} 1X             \n
    - 0x02 -- NAS_RADIO_IF_CDMA_1XEVDO -- 
      cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
    - 0x04 -- NAS_RADIO_IF_GSM         -- GSM \n
    - 0x05 -- NAS_RADIO_IF_UMTS        -- UMTS \n
    - 0x08 -- NAS_RADIO_IF_LTE         -- LTE \n
    - 0x09 -- NAS_RADIO_IF_TDSCDMA     -- TD-SCDMA \n
    - 0x0C -- NAS_RADIO_IF_NR5G        -- NR5G
  */

  /* Optional */
  /*  Network Selection Registration Restriction Preference */
  uint8_t srv_reg_restriction_valid;  /**< Must be set to true if srv_reg_restriction is being passed */
  nas_srv_reg_restriction_enum_v01 srv_reg_restriction;
  /**<   Registration restriction preference. Specifies one of the following 
       modifiers to net_sel_pref: \n
    - 0x00 -- NAS_SRV_REG_RESTRICTION_ UNRESTRICTED -- Device follows the normal 
              registration process \n
    - 0x01 -- NAS_SRV_REG_RESTRICTION_ CAMPED_ONLY -- Device camps on the network 
              according to its provisioning, but does not register \n
    - 0x02 -- NAS_SRV_REG_RESTRICTION_ LIMITED -- Device selects the network for 
              limited service

    \vspace{3pt}
    All other values are reserved.
   */

  /* Optional */
  /*  CSG ID */
  uint8_t csg_info_valid;  /**< Must be set to true if csg_info is being passed */
  nas_csg_nw_iden_type_v01 csg_info;

  /* Optional */
  /*  Usage Preference */
  uint8_t usage_setting_valid;  /**< Must be set to true if usage_setting is being passed */
  nas_usage_pref_enum_v01 usage_setting;
  /**<   Modem usage preference to be set. Values: \n
      - NAS_USAGE_UNKNOWN (0) --  Unknown \n 
      - NAS_USAGE_VOICE_CENTRIC (1) --  Voice centric \n 
      - NAS_USAGE_DATA_CENTRIC (2) --  Data centric 
 */

  /* Optional */
  /*  Voice Domain Preference */
  uint8_t voice_domain_pref_valid;  /**< Must be set to true if voice_domain_pref is being passed */
  nas_voice_domain_pref_enum_type_v01 voice_domain_pref;
  /**<   Voice domain preference. Values: \n
      - NAS_VOICE_DOMAIN_PREF_CS_ONLY (0x00) --  Circuit-switched (CS) voice only \n 
      - NAS_VOICE_DOMAIN_PREF_PS_ONLY (0x01) --  Packet-switched (PS) voice only \n 
      - NAS_VOICE_DOMAIN_PREF_CS_PREF (0x02) --  CS is preferred; PS is secondary \n 
      - NAS_VOICE_DOMAIN_PREF_PS_PREF (0x03) --  PS is preferred; CS is secondary 
 */

  /* Optional */
  /*  LTE Disable Cause */
  uint8_t lte_disable_cause_valid;  /**< Must be set to true if lte_disable_cause is being passed */
  nas_lte_disable_cause_enum_type_v01 lte_disable_cause;
  /**<   LTE disable cause. Values: \n
      - NAS_LTE_DISABLE_CAUSE_NONE (0x00) --  LTE is not disabled \n 
      - NAS_LTE_DISABLE_CAUSE_PERMANENT_DS (0x01) --  LTE is disabled by DS permanently, e.g., T3316 expiry \n 
      - NAS_LTE_DISABLE_CAUSE_TEMP_DS (0x02) --  LTE is disabled by DS temporarily \n 
      - NAS_LTE_DISABLE_CAUSE_DOM_SEL (0x03) --  LTE disable procedure is called for domain selection purpose \n 
      - NAS_LTE_DISABLE_CAUSE_DAM (0x04) --  LTE disable procedure is called for device aggression management recovery 
      - NAS_LTE_DISABLE_CAUSE_USER (0x05) --  LTE disable procedure is called due to user action, 
       e.g., mode_pref change or PS_DETACH triggered by ATCOP/QMI \n 
      - NAS_LTE_DISABLE_CAUSE_NO_CHANGE (0x06) --  No change in LTE disable cause 
 */

  /* Optional */
  /*  Disabled RAT Bitmask */
  uint8_t rat_disabled_mask_valid;  /**< Must be set to true if rat_disabled_mask is being passed */
  mode_pref_mask_type_v01 rat_disabled_mask;
  /**<   Bitmask representing the radio technologies that are disabled. 
       Values: \n
       - Bit 0 (0x01) -- QMI_NAS_RAT_MODE_PREF_ CDMA2000_1X    -- 
         cdma2000\textsuperscript{\textregistered} 1X             \n
       - Bit 1 (0x02) -- QMI_NAS_RAT_MODE_PREF_ CDMA2000_HRPD  -- 
         cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
       - Bit 2 (0x04) -- QMI_NAS_RAT_MODE_PREF_ GSM            -- GSM \n
       - Bit 3 (0x08) -- QMI_NAS_RAT_MODE_PREF_ UMTS           -- UMTS \n
       - Bit 4 (0x10) -- QMI_NAS_RAT_MODE_PREF_ LTE            -- LTE \n
       - Bit 5 (0x20) -- QMI_NAS_RAT_MODE_PREF_ TDSCDMA        -- TD-SCDMA \n
       - Bit 6 (0x40) -- QMI_NAS_RAT_MODE_PREF_ NR5G           -- NR5G

       \vspace{3pt}
       All unlisted bits are reserved for future use and the service point
       ignores them if used.
  */

  /* Optional */
  /*  LTE Band Preference Extended */
  uint8_t lte_band_pref_ext_valid;  /**< Must be set to true if lte_band_pref_ext is being passed */
  lte_band_pref_mask_ext_type_v01 lte_band_pref_ext;

  /* Optional */
  /*  CIOT LTE Operational Mode Preference */
  uint8_t ciot_lte_op_mode_pref_valid;  /**< Must be set to true if ciot_lte_op_mode_pref is being passed */
  ciot_lte_op_mode_pref_mask_type_v01 ciot_lte_op_mode_pref;
  /**<   Bitmask representing the CIoT LTE operational mode preference.
       Values: \n
       - Bit 0 (0x01) -- QMI_NAS_CIOT_LTE_OP_ MODE_PREF_WB   -- LTE wideband \n
       - Bit 1 (0x02) -- QMI_NAS_CIOT_LTE_OP_ MODE_PREF_M1   -- LTE M1 \n
       - Bit 2 (0x04) -- QMI_NAS_CIOT_LTE_OP_ MODE_PREF_NB1  -- LTE NB1

       \vspace{3pt}
       All unlisted bits are reserved for future use and the service point
       ignores them if used.

  */

  /* Optional */
  /*  LTE M1 Band Preference (Deprecated; use LTE M1 Band Preference Extended) */
  uint8_t lte_m1_band_pref_valid;  /**< Must be set to true if lte_m1_band_pref is being passed */
  lte_band_pref_mask_type_v01 lte_m1_band_pref;
  /**<   Bitmask representing the LTE M1 band preference.
       See Table @latexonly\ref{tbl:lteBandPreference}@endlatexonly 
       for details.  
  */

  /* Optional */
  /*  LTE NB1 Band Preference (Deprecated; use LTE NB1 Band Preference Extended) */
  uint8_t lte_nb1_band_pref_valid;  /**< Must be set to true if lte_nb1_band_pref is being passed */
  lte_band_pref_mask_type_v01 lte_nb1_band_pref;
  /**<   Bitmask representing the LTE NB1 band preference.
       See Table @latexonly\ref{tbl:lteBandPreference}@endlatexonly 
       for details.  
  */

  /* Optional */
  /*  CIOT Acquisition Order Preference */
  uint8_t ciot_acq_order_valid;  /**< Must be set to true if ciot_acq_order is being passed */
  uint32_t ciot_acq_order_len;  /**< Must be set to # of elements in ciot_acq_order */
  nas_acq_order_pref_radio_if_enum_v01 ciot_acq_order[NAS_ACQ_ORDER_LIST_MAX_V01];
  /**<   CIOT Acquisition order preference to be set. Values: \n
    - 0x01 -- NAS_RADIO_IF_CDMA_1X     -- 
      cdma2000\textsuperscript{\textregistered} 1X             \n
    - 0x02 -- NAS_RADIO_IF_CDMA_1XEVDO -- 
      cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
    - 0x04 -- NAS_RADIO_IF_GSM         -- GSM \n
    - 0x05 -- NAS_RADIO_IF_UMTS        -- UMTS \n
    - 0x08 -- NAS_RADIO_IF_LTE         -- LTE \n
    - 0x09 -- NAS_RADIO_IF_TDSCDMA     -- TD-SCDMA\n
    - 0x0a -- NAS_RADIO_IF_LTE_M1     -- LTE_M1\n
    - 0x0b -- NAS_RADIO_IF_LTE_NB1     -- LTE_NB1
  */

  /* Optional */
  /*  NR5G Band Preference */
  uint8_t nr5g_band_pref_valid;  /**< Must be set to true if nr5g_band_pref is being passed */
  nas_nr5g_band_pref_mask_type_v01 nr5g_band_pref;

  /* Optional */
  /*  LTE M1 Band Preference Extended */
  uint8_t lte_m1_band_pref_ext_valid;  /**< Must be set to true if lte_m1_band_pref_ext is being passed */
  lte_band_pref_mask_ext_type_v01 lte_m1_band_pref_ext;
  /**<   Bitmask representing the LTE M1 band preference.
       See Table @latexonly\ref{tbl:lteBandPreference}@endlatexonly 
       for details.  
  */

  /* Optional */
  /*  LTE NB1 Band Preference Extended */
  uint8_t lte_nb1_band_pref_ext_valid;  /**< Must be set to true if lte_nb1_band_pref_ext is being passed */
  lte_band_pref_mask_ext_type_v01 lte_nb1_band_pref_ext;
  /**<   Bitmask representing the LTE NB1 band preference.
       See Table @latexonly\ref{tbl:lteBandPreference}@endlatexonly 
       for details.  
  */

  /* Optional */
  /*  NR5G NSA Band Preference */
  uint8_t nsa_nr5g_band_pref_valid;  /**< Must be set to true if nsa_nr5g_band_pref is being passed */
  nas_nr5g_band_pref_mask_type_v01 nsa_nr5g_band_pref;
}nas_get_system_selection_preference_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Queries the different system selection preferences of the 
              device.
              \label{idl:getSysSelPref} */
typedef struct {

  /* Optional */
  /*  Emergency Mode */
  uint8_t emergency_mode_valid;  /**< Must be set to true if emergency_mode is being passed */
  uint8_t emergency_mode;
  /**<   Values: \n
       - 0x00 -- OFF (normal) \n
       - 0x01 -- ON (emergency)
  */

  /* Optional */
  /*  Mode Preference */
  uint8_t mode_pref_valid;  /**< Must be set to true if mode_pref is being passed */
  mode_pref_mask_type_v01 mode_pref;
  /**<   Bitmask representing the radio technology mode preference to be set. 
       Values: \n
       - Bit 0 (0x01) -- QMI_NAS_RAT_MODE_PREF_ CDMA2000_1X    -- 
         cdma2000\textsuperscript{\textregistered} 1X \n
       - Bit 1 (0x02) -- QMI_NAS_RAT_MODE_PREF_ CDMA2000_HRPD  -- 
         cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
       - Bit 2 (0x04) -- QMI_NAS_RAT_MODE_PREF_ GSM            -- GSM \n
       - Bit 3 (0x08) -- QMI_NAS_RAT_MODE_PREF_ UMTS           -- UMTS \n
       - Bit 4 (0x10) -- QMI_NAS_RAT_MODE_PREF_ LTE            -- LTE \n
       - Bit 5 (0x20) -- QMI_NAS_RAT_MODE_PREF_ TDSCDMA        -- TD-SCDMA \n
       - Bit 6 (0x40) -- QMI_NAS_RAT_MODE_PREF_ NR5G           -- NR5G

       \vspace{3pt}
       All unlisted bits are reserved for future use.
  */

  /* Optional */
  /*  Band Preference */
  uint8_t band_pref_valid;  /**< Must be set to true if band_pref is being passed */
  nas_band_pref_mask_type_v01 band_pref;
  /**<   Bitmask representing the band preference to be set. 
       See Table @latexonly\ref{tbl:bandPreference}@endlatexonly 
       for details.   
  */

  /* Optional */
  /*  CDMA PRL Preference */
  uint8_t prl_pref_valid;  /**< Must be set to true if prl_pref is being passed */
  nas_prl_pref_enum_v01 prl_pref;
  /**<   PRL preference to be set for band class 0 (BC0) prl_pref. Values: \n
       - 0x0001 -- PRL_PREF_A_SIDE_ONLY -- Acquire available system only on the A side \n
       - 0x0002 -- PRL_PREF_B_SIDE_ONLY -- Acquire available system only on the B side \n
       - 0x3FFF -- PRL_PREF_ANY         -- Acquire any available systems
  */

  /* Optional */
  /*  Roaming Preference */
  uint8_t roam_pref_valid;  /**< Must be set to true if roam_pref is being passed */
  nas_roam_pref_enum_v01 roam_pref;
  /**<   Roaming preference to be set. Values: \n
       - 0x01 -- ROAMING_PREF_OFF         -- Acquire only systems for which the roaming indicator is off \n
       - 0x02 -- ROAMING_PREF_NOT_OFF     -- Acquire a system as long as its roaming indicator is not off \n
       - 0x03 -- ROAMING_PREF_NOT_FLASING -- Acquire only systems for which the roaming indicator is off or solid on, i.e., not flashing; CDMA only \n
       - 0xFF -- ROAMING_PREF_ANY         -- Acquire systems, regardless of their roaming indicator
  */

  /* Optional */
  /*  LTE Band Preference (Deprecated; use LTE Band Preference Extended) */
  uint8_t lte_band_pref_valid;  /**< Must be set to true if lte_band_pref is being passed */
  lte_band_pref_mask_type_v01 lte_band_pref;
  /**<   Bitmask representing the LTE band preference to be set. 
       See Table @latexonly\ref{tbl:lteBandPreference}@endlatexonly 
       for details.  
  */

  /* Optional */
  /*  Network Selection Preference */
  uint8_t net_sel_pref_valid;  /**< Must be set to true if net_sel_pref is being passed */
  nas_net_sel_pref_enum_v01 net_sel_pref;
  /**<   Network selection preference. Values: \n
       - 0x00 -- Automatic network selection \n
       - 0x01 -- Manual network selection
  */

  /* Optional */
  /*  Service Domain Preference */
  uint8_t srv_domain_pref_valid;  /**< Must be set to true if srv_domain_pref is being passed */
  nas_srv_domain_pref_enum_type_v01 srv_domain_pref;
  /**<   Service domain preference. Values: \n
       - 0x00  -- QMI_SRV_DOMAIN_PREF_CS_ONLY -- Circuit-switched only \n
       - 0x01  -- QMI_SRV_DOMAIN_PREF_PS_ONLY -- Packet-switched only  \n
       - 0x02  -- QMI_SRV_DOMAIN_PREF_CS_PS   -- Circuit-switched and packet-switched
  */

  /* Optional */
  /*  GSM/WCDMA Acquisition Order Preference */
  uint8_t gw_acq_order_pref_valid;  /**< Must be set to true if gw_acq_order_pref is being passed */
  nas_gw_acq_order_pref_enum_type_v01 gw_acq_order_pref;
  /**<   GSM/WCDMA acquisition order preference. Values: \n
       - 0x00 -- NAS_GW_ACQ_ORDER_PREF_ AUTOMATIC -- Automatic \n
       - 0x01 -- NAS_GW_ACQ_ORDER_PREF_ GSM_WCDMA -- GSM then WCDMA \n
       - 0x02 -- NAS_GW_ACQ_ORDER_PREF_ WCDMA_GSM -- WCDMA then GSM
   */

  /* Optional */
  /*  TDSCDMA Band Preference */
  uint8_t tdscdma_band_pref_valid;  /**< Must be set to true if tdscdma_band_pref is being passed */
  nas_tdscdma_band_pref_mask_type_v01 tdscdma_band_pref;
  /**<   Bitmask representing the TD-SCDMA band preference to be set. Values: \n
       - 0x01 -- NAS_TDSCDMA_BAND_A  -- TD-SCDMA Band A \n
       - 0x02 -- NAS_TDSCDMA_BAND_B  -- TD-SCDMA Band B \n
       - 0x04 -- NAS_TDSCDMA_BAND_C  -- TD-SCDMA Band C \n
       - 0x08 -- NAS_TDSCDMA_BAND_D  -- TD-SCDMA Band D \n
       - 0x10 -- NAS_TDSCDMA_BAND_E  -- TD-SCDMA Band E \n
       - 0x20 -- NAS_TDSCDMA_BAND_F  -- TD-SCDMA Band F

       \vspace{3pt}
       All other bits are reserved.
  */

  /* Optional */
  /*  Manual Network Selection PLMN */
  uint8_t manual_net_sel_plmn_valid;  /**< Must be set to true if manual_net_sel_plmn is being passed */
  nas_mnc_pcs_digit_include_status_type_v01 manual_net_sel_plmn;

  /* Optional */
  /*  Acquisition Order Preference */
  uint8_t acq_order_valid;  /**< Must be set to true if acq_order is being passed */
  uint32_t acq_order_len;  /**< Must be set to # of elements in acq_order */
  nas_radio_if_enum_v01 acq_order[NAS_ACQ_ORDER_LIST_MAX_V01];
  /**<   Acquisition order preference to be set. Values: \n
    - 0x01 -- NAS_RADIO_IF_CDMA_1X     -- 
      cdma2000\textsuperscript{\textregistered} 1X             \n
    - 0x02 -- NAS_RADIO_IF_CDMA_1XEVDO -- 
      cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
    - 0x04 -- NAS_RADIO_IF_GSM         -- GSM \n
    - 0x05 -- NAS_RADIO_IF_UMTS        -- UMTS \n
    - 0x08 -- NAS_RADIO_IF_LTE         -- LTE \n
    - 0x09 -- NAS_RADIO_IF_TDSCDMA     -- TD-SCDMA \n
    - 0x0C -- NAS_RADIO_IF_NR5G        -- NR5G
  */

  /* Optional */
  /*  Network Selection Registration Restriction Preference */
  uint8_t srv_reg_restriction_valid;  /**< Must be set to true if srv_reg_restriction is being passed */
  nas_srv_reg_restriction_enum_v01 srv_reg_restriction;
  /**<   Registration restriction preference. Specifies one of the following 
       modifiers to net_sel_pref: \n
    - 0x00 -- NAS_SRV_REG_RESTRICTION_ UNRESTRICTED -- Device follows the normal 
              registration process \n
    - 0x01 -- NAS_SRV_REG_RESTRICTION_ CAMPED_ONLY -- Device camps on the network 
              according to its provisioning, but does not register \n
    - 0x02 -- NAS_SRV_REG_RESTRICTION_ LIMITED -- Device selects the network for 
              limited service

    \vspace{3pt}
    All other values are reserved.
   */

  /* Optional */
  /*  CSG ID */
  uint8_t csg_info_valid;  /**< Must be set to true if csg_info is being passed */
  nas_csg_nw_iden_type_v01 csg_info;

  /* Optional */
  /*  Usage Preference */
  uint8_t usage_setting_valid;  /**< Must be set to true if usage_setting is being passed */
  nas_usage_pref_enum_v01 usage_setting;
  /**<   Usage preference to be set. Values: \n
      - NAS_USAGE_UNKNOWN (0) --  Unknown \n 
      - NAS_USAGE_VOICE_CENTRIC (1) --  Voice centric \n 
      - NAS_USAGE_DATA_CENTRIC (2) --  Data centric 
 */

  /* Optional */
  /*  Voice Domain Preference */
  uint8_t voice_domain_pref_valid;  /**< Must be set to true if voice_domain_pref is being passed */
  nas_voice_domain_pref_enum_type_v01 voice_domain_pref;
  /**<   Voice domain preference. Values: \n
      - NAS_VOICE_DOMAIN_PREF_CS_ONLY (0x00) --  Circuit-switched (CS) voice only \n 
      - NAS_VOICE_DOMAIN_PREF_PS_ONLY (0x01) --  Packet-switched (PS) voice only \n 
      - NAS_VOICE_DOMAIN_PREF_CS_PREF (0x02) --  CS is preferred; PS is secondary \n 
      - NAS_VOICE_DOMAIN_PREF_PS_PREF (0x03) --  PS is preferred; CS is secondary 
 */

  /* Optional */
  /*  LTE Disable Cause */
  uint8_t lte_disable_cause_valid;  /**< Must be set to true if lte_disable_cause is being passed */
  nas_lte_disable_cause_enum_type_v01 lte_disable_cause;
  /**<   LTE disable cause. Values: \n
      - NAS_LTE_DISABLE_CAUSE_NONE (0x00) --  LTE is not disabled \n 
      - NAS_LTE_DISABLE_CAUSE_PERMANENT_DS (0x01) --  LTE is disabled by DS permanently, e.g., T3316 expiry \n 
      - NAS_LTE_DISABLE_CAUSE_TEMP_DS (0x02) --  LTE is disabled by DS temporarily \n 
      - NAS_LTE_DISABLE_CAUSE_DOM_SEL (0x03) --  LTE disable procedure is called for domain selection purpose \n 
      - NAS_LTE_DISABLE_CAUSE_DAM (0x04) --  LTE disable procedure is called for device aggression management recovery 
      - NAS_LTE_DISABLE_CAUSE_USER (0x05) --  LTE disable procedure is called due to user action, 
       e.g., mode_pref change or PS_DETACH triggered by ATCOP/QMI \n 
      - NAS_LTE_DISABLE_CAUSE_NO_CHANGE (0x06) --  No change in LTE disable cause 
 */

  /* Optional */
  /*  Disabled RAT Bitmask */
  uint8_t rat_disabled_mask_valid;  /**< Must be set to true if rat_disabled_mask is being passed */
  mode_pref_mask_type_v01 rat_disabled_mask;
  /**<   Bitmask representing the radio technologies that are disabled. 
       Values: \n
       - Bit 0 (0x01) -- QMI_NAS_RAT_MODE_PREF_ CDMA2000_1X    -- 
         cdma2000\textsuperscript{\textregistered} 1X             \n
       - Bit 1 (0x02) -- QMI_NAS_RAT_MODE_PREF_ CDMA2000_HRPD  -- 
         cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
       - Bit 2 (0x04) -- QMI_NAS_RAT_MODE_PREF_ GSM            -- GSM \n
       - Bit 3 (0x08) -- QMI_NAS_RAT_MODE_PREF_ UMTS           -- UMTS \n
       - Bit 4 (0x10) -- QMI_NAS_RAT_MODE_PREF_ LTE            -- LTE \n
       - Bit 5 (0x20) -- QMI_NAS_RAT_MODE_PREF_ TDSCDMA        -- TD-SCDMA \n
       - Bit 6 (0x40) -- QMI_NAS_RAT_MODE_PREF_ NR5G           -- NR5G

       \vspace{3pt}
       All unlisted bits are reserved for future use and the service point
       ignores them if used.
  */

  /* Optional */
  /*  LTE Band Preference Extended */
  uint8_t lte_band_pref_ext_valid;  /**< Must be set to true if lte_band_pref_ext is being passed */
  lte_band_pref_mask_ext_type_v01 lte_band_pref_ext;

  /* Optional */
  /*  CIOT LTE Operational Mode Preference */
  uint8_t ciot_lte_op_mode_pref_valid;  /**< Must be set to true if ciot_lte_op_mode_pref is being passed */
  ciot_lte_op_mode_pref_mask_type_v01 ciot_lte_op_mode_pref;
  /**<   Bitmask representing the CIoT LTE operational mode preference. 
       Values: \n
       - Bit 0 (0x01) -- QMI_NAS_CIOT_LTE_OP_ MODE_PREF_WB   -- LTE wideband \n
       - Bit 1 (0x02) -- QMI_NAS_CIOT_LTE_OP_ MODE_PREF_M1   -- LTE M1 \n
       - Bit 2 (0x04) -- QMI_NAS_CIOT_LTE_OP_ MODE_PREF_NB1  -- LTE NB1

       \vspace{3pt}
       All unlisted bits are reserved for future use and the service point
       ignores them if used.
  */

  /* Optional */
  /*  LTE M1 Band Preference (Deprecated; use LTE M1 Band Preference Extended) */
  uint8_t lte_m1_band_pref_valid;  /**< Must be set to true if lte_m1_band_pref is being passed */
  lte_band_pref_mask_type_v01 lte_m1_band_pref;
  /**<   Bitmask representing the LTE M1 band preference.
       See Table @latexonly\ref{tbl:lteBandPreference}@endlatexonly 
       for details.  
  */

  /* Optional */
  /*  LTE NB1 Band Preference (Deprecated; use LTE NB1 Band Preference Extended) */
  uint8_t lte_nb1_band_pref_valid;  /**< Must be set to true if lte_nb1_band_pref is being passed */
  lte_band_pref_mask_type_v01 lte_nb1_band_pref;
  /**<   Bitmask representing the LTE NB1 band preference.
       See Table @latexonly\ref{tbl:lteBandPreference}@endlatexonly 
       for details.  
  */

  /* Optional */
  /*  CIOT Acquisition Order Preference */
  uint8_t ciot_acq_order_valid;  /**< Must be set to true if ciot_acq_order is being passed */
  uint32_t ciot_acq_order_len;  /**< Must be set to # of elements in ciot_acq_order */
  nas_acq_order_pref_radio_if_enum_v01 ciot_acq_order[NAS_ACQ_ORDER_LIST_MAX_V01];
  /**<   CIOT Acquisition order preference to be set. Values: \n
    - 0x01 -- NAS_RADIO_CDMA_1X     -- 
      cdma2000\textsuperscript{\textregistered} 1X             \n
    - 0x02 -- NAS_RADIO_CDMA_1XEVDO -- 
      cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
    - 0x04 -- NAS_RADIO_GSM         -- GSM \n
    - 0x05 -- NAS_RADIO_UMTS        -- UMTS \n
    - 0x08 -- NAS_RADIO_LTE         -- LTE \n
    - 0x09 -- NAS_RADIO_TDSCDMA     -- TD-SCDMA\n
    - 0x0a -- NAS_RADIO_LTE_M1     -- LTE_M1\n
    - 0x0b -- NAS_RADIO_LTE_NB1     -- LTE_NB1
  */

  /* Optional */
  /*  NR5G Band Preference */
  uint8_t nr5g_band_pref_valid;  /**< Must be set to true if nr5g_band_pref is being passed */
  nas_nr5g_band_pref_mask_type_v01 nr5g_band_pref;

  /* Optional */
  /*  LTE M1 Band Preference Extended */
  uint8_t lte_m1_band_pref_ext_valid;  /**< Must be set to true if lte_m1_band_pref_ext is being passed */
  lte_band_pref_mask_ext_type_v01 lte_m1_band_pref_ext;
  /**<   Bitmask representing the LTE M1 band preference.
       See Table @latexonly\ref{tbl:lteBandPreference}@endlatexonly 
       for details.  
  */

  /* Optional */
  /*  LTE NB1 Band Preference Extended */
  uint8_t lte_nb1_band_pref_ext_valid;  /**< Must be set to true if lte_nb1_band_pref_ext is being passed */
  lte_band_pref_mask_ext_type_v01 lte_nb1_band_pref_ext;
  /**<   Bitmask representing the LTE NB1 band preference.
       See Table @latexonly\ref{tbl:lteBandPreference}@endlatexonly 
       for details.  
  */

  /* Optional */
  /*  NR5G NSA Band Preference */
  uint8_t nsa_nr5g_band_pref_valid;  /**< Must be set to true if nsa_nr5g_band_pref is being passed */
  nas_nr5g_band_pref_mask_type_v01 nsa_nr5g_band_pref;
}nas_system_selection_preference_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_DDTM_PREF_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_DDTM_PREF_OFF_V01 = 0x00, 
  NAS_DDTM_PREF_ON_V01 = 0x01, 
  NAS_DDTM_PREF_NO_CHANGE_V01 = 0x02, 
  NAS_DDTM_PREF_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_ddtm_pref_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_SO_LIST_ACTION_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_SO_LIST_ACTION_ADD_V01 = 0x00, 
  NAS_SO_LIST_ACTION_REPLACE_V01 = 0x01, 
  NAS_SO_LIST_ACTION_DELETE_V01 = 0x02, 
  NAS_SO_LIST_ACTION_NO_CHANGE_V01 = 0x03, 
  NAS_SO_LIST_ACTION_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_so_list_action_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_ddtm_pref_enum_v01 ddtm_pref;
  /**<   DDTM preference setting. Values: \n
       - 0x00 -- DDTM_PREF_OFF       -- Disable DDTM \n
       - 0x01 -- DDTM_PREF_ON        -- Enable DDTM \n
       - 0x02 -- DDTM_PREF_NO_CHANGE -- Do not change DDTM preference
  */

  uint16_t ddtm_action;
  /**<   Bitmask (with each bit specifying action) representing what
       combined DDTM actions should take place. Values: \n
       - Bit 0 -- QMI_NAS_DDTM_ACTION_ SUPPRESS_L2ACK_BIT  -- Do not send L2 ACK on 1X \n
       - Bit 1 -- QMI_NAS_DDTM_ACTION_ SUPPRESS_REG_BIT    -- Suppress 1X registrations \n
       - Bit 2 -- QMI_NAS_DDTM_ACTION_IGNORE_ SO_PAGES_BIT -- Ignore 1X pages with specified service options \n
       - Bit 3 -- QMI_NAS_DDTM_ACTION_ SUPPRESS_MO_DBM_BIT -- Block MO SMS and DBM

  To enable all masks, a value of 0x3FFF must be sent in this field.
  */

  nas_so_list_action_enum_v01 so_list_action;
  /**<   Action to be taken with the specified SO list in the SO field. Values: \n
       - 0x00 -- SO_LIST_ACTION_ADD       -- Add the specified SOs to the current DDTM SO list \n
       - 0x01 -- SO_LIST_ACTION_REPLACE   -- Replace the current DDTM SO list \n
       - 0x02 -- SO_LIST_ACTION_DELETE    -- Delete the specified SOs from the DDTM SO list \n
       - 0x03 -- SO_LIST_ACTION_NO_CHANGE -- No change in the DDTM SO list
  */

  uint32_t so_len;  /**< Must be set to # of elements in so */
  uint16_t so[NAS_SO_LIST_MAX_V01];
  /**<   Service option for which SO pages are ignored
       when DDTM status is ON. Refer to 
       \hyperref[STD-CR1001F]{3GPP2 C.R1001-F} Table 3.1-1 for 
       standard SO number assignments. To ignore all SO pages, a value of 0xFFFF
       must be specified.
  */
}nas_ddtm_preference_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets the Data Dedicated Transmission Mode (DDTM) preference 
              for the device. */
typedef struct {

  /* Mandatory */
  /*  DDTM Preference */
  nas_ddtm_preference_type_v01 ddtm_preference;
}nas_set_ddtm_preference_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets the Data Dedicated Transmission Mode (DDTM) preference 
              for the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_ddtm_preference_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_CURR_DDTM_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_CURRENT_DDTM_STATUS_DISABLED_V01 = 0x00, 
  NAS_CURRENT_DDTM_STATUS_ENABLED_V01 = 0x01, 
  NAS_CURR_DDTM_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_curr_ddtm_status_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_curr_ddtm_status_enum_v01 curr_ddtm_status;
  /**<   Current DDTM status. Values: \n
       - 0x00 -- CURRENT_DDTM_STATUS_DISABLED \n
       - 0x01 -- CURRENT_DDTM_STATUS_ENABLED
  */

  nas_ddtm_pref_enum_v01 ddtm_pref;
  /**<   DDTM preference setting. Values: \n
       - 0x00 -- DDTM_PREF_OFF       -- Disable DDTM \n
       - 0x01 -- DDTM_PREF_ON        -- Enable DDTM
  */

  uint16_t ddtm_action;
  /**<   Bitmask (with each bit specifying action) representing what
       combined DDTM actions should take place. Values: \n
       - Bit 0 -- QMI_NAS_DDTM_ACTION_ SUPPRESS_ L2ACK_BIT  -- Do not send L2 ACK on 1X \n
       - Bit 1 -- QMI_NAS_DDTM_ACTION_ SUPPRESS_ REG_BIT    -- Suppress 1X registrations \n
       - Bit 2 -- QMI_NAS_DDTM_ACTION_IGNORE_ SO_ PAGES_BIT -- Ignore 1X pages with specified service options \n
       - Bit 3 -- QMI_NAS_DDTM_ACTION_ SUPPRESS_ MO_DBM_BIT -- Block MO SMS and DBM \n
       To enable all masks, a value of 0x3FFF must be sent in this field
  */

  nas_so_list_action_enum_v01 so_list_action;
  /**<   Action to be taken with the specified SO list in the SO field. Values: \n
       - 0x00 -- SO_LIST_ACTION_ADD       -- Add the specified SOs to the current DDTM SO list \n
       - 0x01 -- SO_LIST_ACTION_REPLACE   -- Replace the current DDTM SO list \n
       - 0x02 -- SO_LIST_ACTION_DELETE    -- Delete the specified SOs from the DDTM SO list \n
       - 0x03 -- SO_LIST_ACTION_NO_CHANGE -- No change in the DDTM SO list
  */

  uint32_t so_len;  /**< Must be set to # of elements in so */
  uint16_t so[NAS_SO_LIST_MAX_V01];
  /**<   Service option for which SO pages are ignored
       when DDTM status is ON. Refer to 
       \hyperref[STD-CR1001F]{3GPP2 C.R1001-F} Table 3.1-1 for 
       standard SO number assignments. To ignore all SO pages, a value of 0xFFFF
       must be specified.
  */
}nas_ddtm_settings_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Provides the DDTM status of the device. */
typedef struct {

  /* Mandatory */
  /*  DDTM Settings */
  nas_ddtm_settings_type_v01 ddtm_settings;
}nas_ddtm_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves operator name data from multiple sources. (Deprecated) */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_operator_name_data_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t display_cond;
  /**<   Display condition*/

  uint32_t spn_len;  /**< Must be set to # of elements in spn */
  uint8_t spn[NAS_SERVICE_PROVIDER_NAME_MAX_V01];
  /**<    Service provider name string must use: \n
        - The SMS default 7-bit coded alphabet as defined in 
          \hyperref[STD-23038]{3GPP TS 23.038} with bit 8 set to 9 \n
        - One UCS2 code option defined in \hyperref[STD-11-11]{3GPP TS 11.11} Annex B
  */
}nas_service_provider_name_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  char mcc[NAS_MCC_MNC_MAX_V01];
  /**<   MCC in ASCII string (a value of D in any of the digits is to be used
       to indicate a "wild" value for that corresponding digit).
  */

  char mnc[NAS_MCC_MNC_MAX_V01];
  /**<   MNC in ASCII string (a value of D in any of the digits is to be used
       to indicate a "wild" value for that corresponding digit; digit 3 in MNC
       is optional and when not present, will be set as ASCII F).
  */

  uint16_t lac1;
  /**<   Location area code 1.*/

  uint16_t lac2;
  /**<   Location area code 2.*/

  uint8_t pnn_rec_id;
  /**<   PLMN network name record identifier.*/
}nas_operator_plmn_list_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_CODING_SCHEME_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_CODING_SCHEME_CELL_BROADCAST_GSM_V01 = 0x00, 
  NAS_CODING_SCHEME_UCS2_V01 = 0x01, 
  NAS_CODING_SCHEME_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_coding_scheme_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_COUNTRY_INITIALS_ADD_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_COUNTRY_INITIALS_DO_NOT_ADD_V01 = 0x00, 
  NAS_COUNTRY_INITIALS_ADD_V01 = 0x01, 
  NAS_COUNTRY_INITIALS_UNSPEFICIED_V01 = 0xFF, 
  NAS_COUNTRY_INITIALS_ADD_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_country_initials_add_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_SPARE_BITS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_SPARE_BITS_8_V01 = 0x01, 
  NAS_SPARE_BITS_7_TO_8_V01 = 0x02, 
  NAS_SPARE_BITS_6_TO_8_V01 = 0x03, 
  NAS_SPARE_BITS_5_TO_8_V01 = 0x04, 
  NAS_SPARE_BITS_4_TO_8_V01 = 0x05, 
  NAS_SPARE_BITS_3_TO_8_V01 = 0x06, 
  NAS_SPARE_BITS_2_TO_8_V01 = 0x07, 
  NAS_SPARE_BITS_UNKNOWN_V01 = 0x00, 
  NAS_SPARE_BITS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_spare_bits_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_coding_scheme_enum_v01 coding_scheme;
  /**<   Coding scheme. Values: \n
       - 0x00 -- NAS_CODING_SCHEME_ CELL_BROADCAST_GSM -- Cell broadcast data 
                 coding scheme, GSM default alphabet, language unspecified; 
                 defined in \hyperref[STD-23038]{3GPP TS 23.038} \n
       - 0x01 -- NAS_CODING_SCHEME_ UCS2 -- UCS2 (16 bit) 
                 \hyperref[STD-ISO-IEC10646]{ISO/IEC 10646}
  */

  nas_country_initials_add_enum_v01 ci;
  /**<   Country's initials. Values: \n
       - 0x00 -- COUNTRY_INITIALS_ DO_NOT_ADD -- MS does not add the letters 
                 for the country's initials to the text string \n
       - 0x01 -- COUNTRY_INITIALS_ADD -- MS adds the letters for the 
                 country's initials and a separator, e.g., a space, to the text 
                 string
  */

  nas_spare_bits_enum_v01 long_name_spare_bits;
  /**<   Values: \n
       - 0x01 -- SPARE_BITS_8       -- Bit 8 is spare and set to 0 in octet n                       \n
       - 0x02 -- SPARE_BITS_7_TO_8  -- Bits 7 and 8 are spare and set to 0 in octet n               \n
       - 0x03 -- SPARE_BITS_6_TO_8  -- Bits 6 to 8 (inclusive) are spare and set to 0 in octet n    \n
       - 0x04 -- SPARE_BITS_5_TO_8  -- Bits 5 to 8 (inclusive) are spare and set to 0 in octet n    \n
       - 0x05 -- SPARE_BITS_4_TO_8  -- Bits 4 to 8 (inclusive) are spare and set to 0 in octet n    \n
       - 0x06 -- SPARE_BITS_3_TO_8  -- Bits 3 to 8 (inclusive) are spare and set to 0 in octet n    \n
       - 0x07 -- SPARE_BITS_2_TO_8  -- Bits 2 to 8 (inclusive) are spare and set to 0 in octet n    \n
       - 0x00 -- SPARE_BITS_UNKNOWN -- Carries no information about the number of spare bits in octet n
  */

  nas_spare_bits_enum_v01 short_name_spare_bits;
  /**<   Values: \n
       - 0x01 -- SPARE_BITS_8       -- Bit 8 is spare and set to 0 in octet n                       \n
       - 0x02 -- SPARE_BITS_7_TO_8  -- Bits 7 and 8 are spare and set to 0 in octet n               \n
       - 0x03 -- SPARE_BITS_6_TO_8  -- Bits 6 to 8 (inclusive) are spare and set to 0 in octet n    \n
       - 0x04 -- SPARE_BITS_5_TO_8  -- Bits 5 to 8 (inclusive) are spare and set to 0 in octet n    \n
       - 0x05 -- SPARE_BITS_4_TO_8  -- Bits 4 to 8 (inclusive) are spare and set to 0 in octet n    \n
       - 0x06 -- SPARE_BITS_3_TO_8  -- Bits 3 to 8 (inclusive) are spare and set to 0 in octet n    \n
       - 0x07 -- SPARE_BITS_2_TO_8  -- Bits 2 to 8 (inclusive) are spare and set to 0 in octet n    \n
       - 0x00 -- SPARE_BITS_UNKNOWN -- Carries no information about the number of spare bits in octet n
  */

  uint32_t long_name_len;  /**< Must be set to # of elements in long_name */
  uint8_t long_name[NAS_LONG_NAME_MAX_V01];
  /**<   Long name string in coding_scheme.*/

  uint32_t short_name_len;  /**< Must be set to # of elements in short_name */
  uint8_t short_name[NAS_SHORT_NAME_MAX_V01];
  /**<   Short name string in coding_scheme.*/
}nas_plmn_network_name_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves operator name data from multiple sources. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. 
 Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
   */

  /* Optional */
  /*  Service Provider Name (refer to \hyperref[STD-31102]{3GPP TS 31.102} Section 4.2.12) */
  uint8_t service_provider_name_valid;  /**< Must be set to true if service_provider_name is being passed */
  nas_service_provider_name_type_v01 service_provider_name;

  /* Optional */
  /*  Operator PLMN List (refer to \hyperref[STD-31102]{3GPP TS 31.102} Section 4.2.59) */
  uint8_t operator_plmn_list_valid;  /**< Must be set to true if operator_plmn_list is being passed */
  uint32_t operator_plmn_list_len;  /**< Must be set to # of elements in operator_plmn_list */
  nas_operator_plmn_list_type_v01 operator_plmn_list[NAS_OPERATOR_PLMN_LIST_MAX_V01];

  /* Optional */
  /*  PLMN Network Name (refer to \hyperref[STD-24008]{3GPP TS 24.008} Section 10.5.3.5a) */
  uint8_t plmn_network_name_valid;  /**< Must be set to true if plmn_network_name is being passed */
  uint32_t plmn_network_name_len;  /**< Must be set to # of elements in plmn_network_name */
  nas_plmn_network_name_type_v01 plmn_network_name[NAS_PLMN_NETWORK_NAME_LIST_MAX_V01];

  /* Optional */
  /*  Operator Name String (refer to \hyperref[STD-CPHS42WW6]{CPHS4_2.WW6} Section B.4.1.2) */
  uint8_t plmn_name_valid;  /**< Must be set to true if plmn_name is being passed */
  char plmn_name[NAS_PLMN_NAME_MAX_V01 + 1];
  /**<   PLMN name must be coded in a default 7-bit alphabet with b8 set to 0.*/

  /* Optional */
  /*  NITZ Information */
  uint8_t nitz_information_valid;  /**< Must be set to true if nitz_information is being passed */
  nas_plmn_network_name_type_v01 nitz_information;
}nas_get_operator_name_data_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates a change in operator name data, which is obtained 
              from multiple sources. (Deprecated) */
typedef struct {

  /* Optional */
  /*  Service Provider Name (refer to \hyperref[STD-31102]{3GPP TS 31.102} Section 4.2.12) */
  uint8_t service_provider_name_valid;  /**< Must be set to true if service_provider_name is being passed */
  nas_service_provider_name_type_v01 service_provider_name;

  /* Optional */
  /*  Operator PLMN List (refer to \hyperref[STD-31102]{3GPP TS 31.102} Section 4.2.59) */
  uint8_t operator_plmn_list_valid;  /**< Must be set to true if operator_plmn_list is being passed */
  uint32_t operator_plmn_list_len;  /**< Must be set to # of elements in operator_plmn_list */
  nas_operator_plmn_list_type_v01 operator_plmn_list[NAS_OPERATOR_PLMN_LIST_MAX_V01];

  /* Optional */
  /*  PLMN Network Name (refer to \hyperref[STD-24008]{3GPP TS 24.008} Section 10.5.3.5a) */
  uint8_t plmn_network_name_valid;  /**< Must be set to true if plmn_network_name is being passed */
  uint32_t plmn_network_name_len;  /**< Must be set to # of elements in plmn_network_name */
  nas_plmn_network_name_type_v01 plmn_network_name[NAS_PLMN_NETWORK_NAME_LIST_MAX_V01];

  /* Optional */
  /*  Operator Name String (refer to \hyperref[STD-CPHS42WW6]{CPHS4_2.WW6} Section B.4.1.2) */
  uint8_t plmn_name_valid;  /**< Must be set to true if plmn_name is being passed */
  char plmn_name[NAS_PLMN_NAME_MAX_V01 + 1];
  /**<   PLMN name must be coded in a default 7-bit alphabet with b8 set to 0*/

  /* Optional */
  /*  NITZ Information */
  uint8_t nitz_information_valid;  /**< Must be set to true if nitz_information is being passed */
  nas_plmn_network_name_type_v01 nitz_information;
}nas_operator_name_data_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the PLMN MODE bit data from the Customer Service 
              Profile (CSP). */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_csp_plmn_mode_bit_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_PLMN_MODE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_PLMN_MODE_DO_NOT_RESTRICT_V01 = 0x00, 
  NAS_PLMN_MODE_RESTRICT_V01 = 0x01, 
  NAS_PLMN_MODE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_plmn_mode_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the PLMN MODE bit data from the Customer Service 
              Profile (CSP). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  PLMN Mode (refer to \hyperref[STD-CPHS42WW6]{CPHS4_2.WW6} Section 4.7.1) */
  uint8_t plmn_mode_valid;  /**< Must be set to true if plmn_mode is being passed */
  nas_plmn_mode_enum_v01 plmn_mode;
  /**<   Values: \n
       - 0x00 -- PLMN_MODE_DO_NOT_RESTRICT -- Do not restrict menu options for manual PLMN selection \n
       - 0x01 -- PLMN_MODE_RESTRICT        -- Restrict menu options for manual PLMN selection
  */
}nas_get_csp_plmn_mode_bit_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Provides any change in the PLMN MODE bit in the CSP. */
typedef struct {

  /* Optional */
  /*  PLMN Mode (refer to \hyperref[STD-CPHS42WW6]{CPHS4_2.WW6} Section 4.7.1) */
  uint8_t plmn_mode_valid;  /**< Must be set to true if plmn_mode is being passed */
  nas_plmn_mode_enum_v01 plmn_mode;
  /**<   Values: \n
       - 0x00 -- PLMN_MODE_DO_NOT_RESTRICT -- Do not restrict menu options for manual PLMN selection \n
       - 0x01 -- PLMN_MODE_RESTRICT        -- Restrict menu options for manual PLMN selection
  */
}nas_csp_plmn_mode_bit_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Updates the A-KEY. (Discontinued) */
typedef struct {

  /* Mandatory */
  /*  AKEY */
  uint8_t akey[26];
  /**<   AKEY value + checksum value in ASCII (first 20 bytes are the AKEY value,
       last 6 bytes are the checksum).
  */
}nas_update_akey_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Updates the A-KEY. (Discontinued) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_update_akey_resp_msg_v01;  /* Message */
/**
    @}
  */

typedef uint32_t get_3gpp2_info_mask_enum_type_v01;
#define QMI_NAS_GET_3GPP2_SUBS_INFO_NAM_NAME_V01 ((get_3gpp2_info_mask_enum_type_v01)0x01) 
#define QMI_NAS_GET_3GPP2_SUBS_INFO_DIR_NUM_V01 ((get_3gpp2_info_mask_enum_type_v01)0x02) 
#define QMI_NAS_GET_3GPP2_SUBS_INFO_HOME_SID_IND_V01 ((get_3gpp2_info_mask_enum_type_v01)0x04) 
#define QMI_NAS_GET_3GPP2_SUBS_INFO_MIN_BASED_IMSI_V01 ((get_3gpp2_info_mask_enum_type_v01)0x08) 
#define QMI_NAS_GET_3GPP2_SUBS_INFO_TRUE_IMSI_V01 ((get_3gpp2_info_mask_enum_type_v01)0x10) 
#define QMI_NAS_GET_3GPP2_SUBS_INFO_CDMA_CHANNEL_V01 ((get_3gpp2_info_mask_enum_type_v01)0x20) 
#define QMI_NAS_GET_3GPP2_SUBS_INFO_MDN_V01 ((get_3gpp2_info_mask_enum_type_v01)0x40) 
/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves 3GPP2 subscription-related information. */
typedef struct {

  /* Mandatory */
  /*  NAM ID */
  uint8_t nam_id;
  /**<   NAM ID of the information to be retrieved. The index starts from 0. 
       A nam_id of 0xFF is used to retrieve information of current NAM.
  */

  /* Optional */
  /*  Get 3GPP2 Info Bitmask */
  uint8_t get_3gpp2_info_mask_valid;  /**< Must be set to true if get_3gpp2_info_mask is being passed */
  get_3gpp2_info_mask_enum_type_v01 get_3gpp2_info_mask;
  /**<   Bitmasks included in this field decide which optional TLVs are to be 
       included in the response message. If this TLV is not included, all 
       available information is sent as part of the response message. \n \vspace{-.12in}
       
       The bitmask enum value, bitmask enum member name, and TLV that is 
       included are: \n

       - 0x01 -- QMI_NAS_GET_3GPP2_SUBS_INFO_ NAM_NAME       -- NAM Name \n
       - 0x02 -- QMI_NAS_GET_3GPP2_SUBS_INFO_ DIR_NUM        -- Directory Number \n
       - 0x04 -- QMI_NAS_GET_3GPP2_SUBS_INFO_ HOME_SID_IND   -- Home SID/NID \n
       - 0x08 -- QMI_NAS_GET_3GPP2_SUBS_INFO_ MIN_BASED_IMSI -- MIN-based IMSI \n
       - 0x10 -- QMI_NAS_GET_3GPP2_SUBS_INFO_ TRUE_IMSI      -- True IMSI \n
       - 0x20 -- QMI_NAS_GET_3GPP2_SUBS_INFO_ CDMA_CHANNEL   -- CDMA Channel \n
       - 0x40 -- QMI_NAS_GET_3GPP2_SUBS_INFO_ MDN            -- Mobile Directory Number

       \vspace{3pt}
       All other bits are reserved for future use.
  */
}nas_get_3gpp2_subscription_info_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t sid;
  /**<   System ID. */

  uint16_t nid;
  /**<   Network ID. */
}nas_3gpp2_home_sid_nid_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  MCC_M */
  char mcc_m[NAS_MCC_LEN_V01];
  /**<   ASCII character representation of MCC_M; 
       example: 000, 123, etc.
  */

  /*  IMSI_M_11_12 */
  char imsi_m_11_12[NAS_IMSI_11_12_LEN_V01];
  /**<   ASCII character representation of IMSI_M_11_12 value;
       example: 00, 01, etc.
  */

  /*  IMSI_M_S1 */
  char imsi_m_s1[NAS_IMSI_MIN1_LEN_V01];
  /**<   ASCII character representation of IMSI_M_S1 value;
       example: 0123456.
  */

  /*  IMSI_M_S2 */
  char imsi_m_s2[NAS_IMSI_MIN2_LEN_V01];
  /**<   ASCII character representation of IMSI_M_S2 value;
       example: 012.
  */
}nas_3gpp2_min_based_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  MCC_T */
  char mcc_t[NAS_MCC_LEN_V01];
  /**<   ASCII character representation of MCC_T;
       example: 000, 123, etc.
  */

  /*  IMSI_T_11_12 */
  char imsi_t_11_12[NAS_IMSI_11_12_LEN_V01];
  /**<   ASCII character representation of IMSI_T_11_12 value;
       example: 00, 01, etc.
  */

  /*  IMSI_T_S1 */
  char imsi_t_s1[NAS_IMSI_MIN1_LEN_V01];
  /**<   ASCII character representation of IMSI_T_S1 value;
       example: 0123456.
  */

  /*  IMSI_T_S2 */
  char imsi_t_s2[NAS_IMSI_MIN2_LEN_V01];
  /**<   ASCII character representation of IMSI_T_S2 value;
       example: 012.
  */

  /*  IMSI_T_ADDR_NUM */
  uint8_t imsi_t_addr_num;
  /**<   Value of IMSI_T_ADDR_NUM.
  */
}nas_3gpp2_true_imsi_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t pri_ch_a;
  /**<   A Channel number for the primary carrier. */

  uint16_t pri_ch_b;
  /**<   B Channel number for the primary carrier. */

  uint16_t sec_ch_a;
  /**<   A Channel number for the secondary carrier. */

  uint16_t sec_ch_b;
  /**<   B Channel number for the secondary carrier. */
}nas_cdma_channel_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves 3GPP2 subscription-related information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  NAM Name (information retrieved from NV_NAME_NAM_I) */
  uint8_t nam_name_valid;  /**< Must be set to true if nam_name is being passed */
  uint32_t nam_name_len;  /**< Must be set to # of elements in nam_name */
  char nam_name[NAS_MAX_NAM_NAME_LEN_V01];
  /**<   Name information in ASCII. The maximum length of nam_name is 12.
  */

  /* Optional */
  /*  Directory Number (information retrieved from NV_DIR_NUMBER_I) */
  uint8_t dir_num_valid;  /**< Must be set to true if dir_num is being passed */
  uint32_t dir_num_len;  /**< Must be set to # of elements in dir_num */
  char dir_num[NAS_MAX_3GPP2_SUBS_INFO_DIR_NUM_LEN_V01];
  /**<   Directory number in ASCII characters.
  */

  /* Optional */
  /*  Home SID/NID (information retrieved from NV_HOME_SID_NID_I) */
  uint8_t cdma_sys_id_valid;  /**< Must be set to true if cdma_sys_id is being passed */
  uint32_t cdma_sys_id_len;  /**< Must be set to # of elements in cdma_sys_id */
  nas_3gpp2_home_sid_nid_info_type_v01 cdma_sys_id[NAS_MAX_3GPP2_HOME_SID_NID_NUM_V01];

  /* Optional */
  /*  MIN-based IMSI (information retrieved from NV_IMSI_MCC_I, NV_IMSI_11_12_I, NV_MIN1_I, and NV_MIN2_I) */
  uint8_t min_based_info_valid;  /**< Must be set to true if min_based_info is being passed */
  nas_3gpp2_min_based_info_type_v01 min_based_info;

  /* Optional */
  /*  True IMSI (information retrieved from NV_IMSI_T_MCC_I, NV_IMSI_T_11_12_I, NV_IMSI_T_S1_I, NV_IMSI_T_S2_I, and NV_IMSI_T_ADDR_NUM_I) */
  uint8_t true_imsi_valid;  /**< Must be set to true if true_imsi is being passed */
  nas_3gpp2_true_imsi_info_type_v01 true_imsi;

  /* Optional */
  /*  CDMA Channel (information retrieved from NV_PCDMACH_I and NV_SCDMACH_I) */
  uint8_t cdma_channel_info_valid;  /**< Must be set to true if cdma_channel_info is being passed */
  nas_cdma_channel_info_type_v01 cdma_channel_info;

  /* Optional */
  /*  Mobile Directory Number (information retrieved from NV_DIR_NUMBER_PCS_I) */
  uint8_t mdn_valid;  /**< Must be set to true if mdn is being passed */
  uint32_t mdn_len;  /**< Must be set to # of elements in mdn */
  char mdn[MDN_MAX_LEN_V01];
  /**<   Mobile directory number represented in ASCII format with a maximum 
       length of 15 characters. Valid values for individual characters in the 
       MDN are digits 0 through 9, and special characters * and #.
  */
}nas_get_3gpp2_subscription_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Writes 3GPP2 subscription-related information. */
typedef struct {

  /* Mandatory */
  /*  NAM ID */
  uint8_t nam_id;
  /**<   NAM ID of the information to be written. The index starts from 0. 
       A nam_id of 0xFF is used to write information to current NAM.
  */

  /* Optional */
  /*  Directory Number (information written to NV_DIR_NUMBER_I) */
  uint8_t dir_num_valid;  /**< Must be set to true if dir_num is being passed */
  uint32_t dir_num_len;  /**< Must be set to # of elements in dir_num */
  char dir_num[NAS_MAX_3GPP2_SUBS_INFO_DIR_NUM_LEN_V01];
  /**<   Directory number in ASCII characters.
  */

  /* Optional */
  /*  Home SID/NID (information written to NV_HOME_SID_NID_I) */
  uint8_t cdma_sys_id_valid;  /**< Must be set to true if cdma_sys_id is being passed */
  uint32_t cdma_sys_id_len;  /**< Must be set to # of elements in cdma_sys_id */
  nas_3gpp2_home_sid_nid_info_type_v01 cdma_sys_id[NAS_MAX_3GPP2_HOME_SID_NID_NUM_V01];

  /* Optional */
  /*  MIN-based IMSI (information written to NV_IMSI_MCC_I, NV_IMSI_11_12_I, NV_MIN1_I, and NV_MIN2_I) */
  uint8_t min_based_info_valid;  /**< Must be set to true if min_based_info is being passed */
  nas_3gpp2_min_based_info_type_v01 min_based_info;

  /* Optional */
  /*  True IMSI (information written to NV_IMSI_T_MCC_I, NV_IMSI_T_11_12_I, NV_IMSI_T_S1_I, NV_IMSI_T_S2_I, and NV_IMSI_T_ADDR_NUM_I) */
  uint8_t true_imsi_valid;  /**< Must be set to true if true_imsi is being passed */
  nas_3gpp2_true_imsi_info_type_v01 true_imsi;

  /* Optional */
  /*  CDMA Channel (information written to NV_PCDMACH_I and NV_SCDMACH_I) */
  uint8_t cdma_channel_info_valid;  /**< Must be set to true if cdma_channel_info is being passed */
  nas_cdma_channel_info_type_v01 cdma_channel_info;

  /* Optional */
  /*  NAM Name (information written to NV_NAME_NAM_I) */
  uint8_t nam_name_valid;  /**< Must be set to true if nam_name is being passed */
  uint32_t nam_name_len;  /**< Must be set to # of elements in nam_name */
  char nam_name[NAS_MAX_NAM_NAME_LEN_V01];
  /**<   Name information in ASCII. The maximum length of nam_name is 12.
  */

  /* Optional */
  /*  Mobile Directory Number (information written to NV_DIR_NUMBER_PCS_I) */
  uint8_t mdn_valid;  /**< Must be set to true if mdn is being passed */
  uint32_t mdn_len;  /**< Must be set to # of elements in mdn */
  char mdn[MDN_MAX_LEN_V01];
  /**<   Mobile directory number represented in ASCII format with a maximum 
       length of 15 characters. Valid values for individual characters in the 
       MDN are digits 0 through 9, and special characters * and #.
  */

  /* Optional */
  /*  Service Programming Code */
  uint8_t spc_valid;  /**< Must be set to true if spc is being passed */
  char spc[NAS_SPC_MAX_V01];
  /**<   Service programming code in ASCII format (digits 0 to 9 only). 
       This TLV is required when any of the following TLVs are present: 
       Directory Number, Home SID/NID, MIN-based IMSI, CDMA Channel, 
       or Mobile Directory.
  */
}nas_set_3gpp2_subscription_info_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Writes 3GPP2 subscription-related information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_3gpp2_subscription_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves Mobile CAI revision information. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_mob_cai_rev_req_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves Mobile CAI revision information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  CAI revision (information retrieved from NV_MOB_CAI_REV_I) */
  uint8_t cai_rev_valid;  /**< Must be set to true if cai_rev is being passed */
  uint8_t cai_rev;
  /**<   CAI revision. Values: \n
       - 0x01 -- P_REV_JSTD008 \n
       - 0x03 -- P_REV_IS95A \n
       - 0x04 -- P_REV_IS95B \n
       - 0x06 -- P_REV_IS2000 \n
       - 0x07 -- P_REV_IS2000_REL_A    \n
       - 0x08 -- P_REV_IS2000_REL_B    \n
       - 0x09 -- P_REV_IS2000_REL_C    \n
       - 0x0A -- P_REV_IS2000_REL_C_MI \n
       - 0x0B -- P_REV_IS2000_REL_D
  */
}nas_get_mob_cai_rev_resp_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves current RTRE configuration information. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_rtre_config_req_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_RTRE_CFG_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_RTRE_CFG_RUIM_ONLY_V01 = 0x01, 
  NAS_RTRE_CFG_INTERNAL_SETTINGS_ONLY_V01 = 0x02, 
  NAS_RTRE_CFG_RUIM_IF_AVAIL_V01 = 0x03, 
  NAS_RTRE_CFG_GSM_ON_1X_V01 = 0x04, 
  NAS_RTRE_CFG_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_rtre_cfg_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves current RTRE configuration information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  Current RTRE Configuration */
  uint8_t rtre_cfg_valid;  /**< Must be set to true if rtre_cfg is being passed */
  nas_rtre_cfg_enum_v01 rtre_cfg;
  /**<   Values: \n
       -0x01 -- R-UIM only \n
       -0x02 -- Internal settings only \n
       -0x04 -- GSM on 1X
  */

  /* Optional */
  /*  RTRE Configuration Preference */
  uint8_t rtre_cfg_pref_valid;  /**< Must be set to true if rtre_cfg_pref is being passed */
  nas_rtre_cfg_enum_v01 rtre_cfg_pref;
  /**<   Values: \n
       -0x01 -- R-UIM only \n
       -0x02 -- Internal settings only \n
       -0x03 -- Use R-UIM if available \n
       -0x04 -- GSM on 1X
  */
}nas_get_rtre_config_resp_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets RTRE configuration preference. */
typedef struct {

  /* Mandatory */
  /*  RTRE Configuration Preference */
  nas_rtre_cfg_enum_v01 rtre_cfg_pref;
  /**<   Values: \n
       -0x01 -- R-UIM only \n
       -0x02 -- Internal settings only \n
       -0x03 -- Use R-UIM if available \n
       -0x04 -- GSM on 1X (deprecated; will be converted to "Internal settings only" when used)
  */

  /* Optional */
  /*  Service Programming Code */
  uint8_t spc_valid;  /**< Must be set to true if spc is being passed */
  char spc[NAS_SPC_MAX_V01];
  /**<   Service programming code in ASCII format (digits 0 to 9 only). 
       This TLV is required when the RTRE Configuration Preference TLV 
       is present.
  */
}nas_set_rtre_config_req_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets RTRE configuration preference. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_rtre_config_resp_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves cell location-related information. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_cell_location_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Cell id */
  uint32_t nmr_cell_id;
  /**<   Cell ID (0xFFFFFFFF indicates cell ID information is not present).
  */

  /*  PLMN */
  char nmr_plmn[NAS_PLMN_LEN_V01];
  /**<   MCC/MNC information coded as octet 3, 4, and 5 in 
       \hyperref[STD-24008]{3GPP TS 24.008} Section 10.5.1.3. 
       (This field is ignored when nmr_cell_id is not present.)
  */

  /*  LAC */
  uint16_t nmr_lac;
  /**<   Location area code. (This field is ignored when nmr_cell_id is not present.)
  */

  /*  ARFCN */
  uint16_t nmr_arfcn;
  /**<   Absolute RF channel number.
  */

  /*  BSIC */
  uint8_t nmr_bsic;
  /**<   Base station identity code.
  */

  /*  Rx Lev */
  uint16_t nmr_rx_lev;
  /**<   Cell Rx measurement. Values range between 0 and 63, which is 
       mapped to a measured signal level: \n

       - Rxlev 0 is a signal strength less than -110 dBm \n
       - Rxlev 1 is -110 dBm to -109 dBm    \n
       - Rxlev 2 is -109 dBm to -108 dBm    \n
       - ...                                \n
       - Rxlev 62 is -49 dBm to -48 dBm     \n
       - Rxlev 63 is greater than -48 dBm
  */
}nas_nmr_cell_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Cell id */
  uint32_t cell_id;
  /**<   Cell ID (0xFFFFFFFF indicates cell ID information is not present).
  */

  /*  PLMN */
  char plmn[NAS_PLMN_LEN_V01];
  /**<   MCC/MNC information coded as octet 3, 4, and 5 in 
       \hyperref[STD-24008]{3GPP TS 24.008} Section 10.5.1.3. 
       (This field is ignored when cell_id is not present.)
  */

  /*  LAC */
  uint16_t lac;
  /**<   Location area code. (This field is ignored when cell_id is not present.)
  */

  /*  ARFCN */
  uint16_t arfcn;
  /**<   Absolute RF channel number.
  */

  /*  BSIC */
  uint8_t bsic;
  /**<   Base station identity code.
  */

  /*  Timing Advance */
  uint32_t timing_advance;
  /**<   Measured delay (in bit periods; 1 bit period = 48/13 microsecond) of 
       an access burst transmission on the RACH or PRACH to the expected signal 
       from an MS at zero distance under static channel conditions.
       (0xFFFFFFFF indicates timing advance information is not present.)
  */

  /*  Rx Lev */
  uint16_t rx_lev;
  /**<   Serving cell Rx measurement. Values range between 0 and 63, which is 
       mapped to a measured signal level: \n

       - Rxlev 0 is a signal strength less than -110 dBm \n
       - Rxlev 1 is -110 dBm to -109 dBm    \n
       - Rxlev 2 is -109 dBm to -108 dBm    \n
       - ...                               \n
       - Rxlev 62 is -49 dBm to -48 dBm     \n
       - Rxlev 63 is greater than -48 dBm
  */

  /*  Neighbor cell information  */
  uint32_t nmr_cell_info_len;  /**< Must be set to # of elements in nmr_cell_info */
  nas_nmr_cell_info_type_v01 nmr_cell_info[NAS_NMR_MAX_NUM_V01];
  /**<   Contains information only if neighbors are present; 
       includes: \n
       - nmr_cell_id \n
       - nmr_plmn \n
       - nmr_lac \n
       - nmr_arfcn \n
       - nmr_bsic \n
       - nmr_rx_lev
  */
}nas_geran_cell_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  UARFCN */
  uint16_t umts_uarfcn;
  /**<   UTRA absolute RF channel number.
  */

  /*  PSC */
  uint16_t umts_psc;
  /**<   Primary scrambling code.
  */

  /*  RSCP */
  int16_t umts_rscp;
  /**<   Received signal code power; the received power on one code measured in 
       dBm on the primary CPICH channel of the neighbor/monitored cell.
  */

  /*  Ec/Io */
  int16_t umts_ecio;
  /**<   ECIO; the received energy per chip divided by the power density in the 
       band measured in dBm on the primary CPICH channel of the 
       neighbor/monitored cell.
  */
}nas_umts_monitored_cell_set_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  UARFCN */
  uint16_t geran_arfcn;
  /**<   Absolute RF channel number.
  */

  /*  BSIC NCC */
  uint8_t geran_bsic_ncc;
  /**<   Base station identity code network color code
       (0xFF indicates information is not present).
  */

  /*  BSIC BCC */
  uint8_t geran_bsic_bcc;
  /**<   Base station identity code base station color code
       (0xFF indicates information is not present).
  */

  /*  GERAN RSSI */
  int16_t geran_rssi;
  /**<   Received signal strength indicator.
  */
}nas_umts_geran_nbr_cell_set_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  EARFCN */
  uint16_t earfcn;
  /**<   E-UTRA absolute RF channel number of the detected cell. 
    */

  /*  Physical Cell id */
  uint16_t pci;
  /**<   Physical cell ID of the detected cell. 
       Range is defined in \hyperref[STD-36211]{3GPP TS 36.211}. 
  */

  /*  RSRP */
  float rsrp;
  /**<   Current received signal strength indication (in dBm) of the detected 
       cell. 
  */

  /*  RSRQ */
  float rsrq;
  /**<   Current reference signal received quality (in dB) of the detected cell. 
  */

  /*  RX Level */
  int16_t srxlev;
  /**<   Cell selection Rx level (Srxlev) value of the detected cell in linear 
       scale. (This field is only valid when wcdma_rrc_state is not 
       NAS_WCDMA_RRC_STATE_CELL_FACH or NAS_WCDMA_RRC_STATE_CELL_DCH.) 
  */

  /*  Cell is TDD */
  uint8_t cell_is_tdd;
  /**<   TRUE if the cell is TDD; FALSE if the cell is FDD. 
  */
}nas_umts_lte_nbr_cell_set_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Cell id */
  uint16_t cell_id;
  /**<   Cell ID (0xFFFFFFFF indicates cell ID information is not present).
  */

  /*  PLMN */
  char plmn[NAS_PLMN_LEN_V01];
  /**<   MCC/MNC information coded as octet 3, 4, and 5 in 
       \hyperref[STD-24008]{3GPP TS 24.008} Section 10.5.1.3. 
  */

  /*  LAC */
  uint16_t lac;
  /**<   Location area code.
  */

  /*  UARFCN */
  uint16_t uarfcn;
  /**<   UTRA absolute RF channel number.
  */

  /*  PSC */
  uint16_t psc;
  /**<   Primary scrambling code.
  */

  /*  RSCP */
  int16_t rscp;
  /**<   Received signal code power; the received power on one code measured in
       dBm on the primary CPICH channel of the serving cell.
  */

  /*  Ec/Io */
  int16_t ecio;
  /**<   ECIO; the received energy per chip divided by the power density in the
       band measured in dBm on the primary CPICH channel of the serving cell.
  */

  /*  UMTS Monitored Cell info set */
  uint32_t umts_monitored_cell_len;  /**< Must be set to # of elements in umts_monitored_cell */
  nas_umts_monitored_cell_set_info_type_v01 umts_monitored_cell[NAS_UMTS_MAX_MONITORED_CELL_SET_NUM_V01];

  /*  GERAN Neighbor cell info set */
  uint32_t umts_geran_nbr_cell_len;  /**< Must be set to # of elements in umts_geran_nbr_cell */
  nas_umts_geran_nbr_cell_set_info_type_v01 umts_geran_nbr_cell[NAS_UMTS_GERAN_MAX_NBR_CELL_SET_NUM_V01];
}nas_umts_cell_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t sid;
  /**<   System ID. */

  uint16_t nid;
  /**<   Network ID. */

  uint16_t base_id;
  /**<   Base station ID. */

  uint16_t refpn;
  /**<   Reference PN. */

  uint32_t base_lat;
  /**<   Latitude of the current base station in units of 0.25 sec. */

  uint32_t base_long;
  /**<   Longitude of the current base station in units of 0.25 sec. */
}nas_cdma_cell_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t pci;
  /**<   Physical cell ID. Range: 0 to 503. */

  int16_t rsrq;
  /**<   Current RSRQ in 1/10 dB as measured by L1.  
    Range: -200 to -30 (e.g., -200 means -20.0 dB). */

  int16_t rsrp;
  /**<   Current RSRP in 1/10 dBm as measured by L1. 
    Range: -1400 to -440 (e.g., -440 means -44.0 dBm). */

  int16_t rssi;
  /**<   Current RSSI in 1/10 dBm as measured by L1.
    Range: -1200 to 0 (e.g., -440 means -44.0 dBm). */

  int16_t srxlev;
  /**<   Cell selection Rx level (Srxlev) value. Range: -128 to 128. 
    (This field is only valid when ue_in_idle is TRUE.) */
}nas_lte_ngbr_cell_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t ue_in_idle;
  /**<   TRUE if the UE is in Idle mode; otherwise FALSE. */

  uint8_t plmn[NAS_PLMN_LEN_V01];
  /**<   PLMN ID coded as octet 3, 4, and 5 in 
     \hyperref[STD-24008]{3GPP TS 24.008} Section 10.5.1.3. */

  uint16_t tac;
  /**<   Tracking area code. */

  uint32_t global_cell_id;
  /**<   Global cell ID in the system information block. */

  uint16_t earfcn;
  /**<   E-UTRA absolute radio frequency channel number of the serving cell. 
     Range: 0 to 65535. */

  uint16_t serving_cell_id;
  /**<   LTE serving cell ID. Range: 0 to 503. This is the cell ID of the 
    serving cell and can be found in the cell list. */

  uint8_t cell_resel_priority;
  /**<   Priority for serving frequency. Range: 0 to 7. (This field is only 
    valid when ue_in_idle is TRUE.) */

  uint8_t s_non_intra_search;
  /**<   S non-intra search threshold to control non-intrafrequency searches. 
    Range: 0 to 31. (This field is only valid when ue_in_idle is TRUE.) */

  uint8_t thresh_serving_low;
  /**<   Serving cell low threshold. Range: 0 to 31. (This field is only 
    valid when ue_in_idle is TRUE.) */

  uint8_t s_intra_search;
  /**<   S intra search threshold. Range: 0 to 31. The current cell 
    measurement must fall below this threshold to consider intrafrequency 
    for reselection. (This field is only valid when ue_in_idle is TRUE.) */

  uint32_t cells_len;  /**< Must be set to # of elements in cells */
  nas_lte_ngbr_cell_type_v01 cells[NAS_MAX_LTE_NGBR_NUM_CELLS_V01];
}nas_lte_intra_freq_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t earfcn;
  /**<   E-UTRA absolute radio frequency channel number. Range: 0 to 65535. */

  uint8_t threshX_low;
  /**<   Cell Srxlev low threshold. Range: 0 to 31.  
    When the serving cell does not exceed thresh_serving_low, 
    the value of an evaluated cell must be smaller than this value to be 
    considered for reselection. */

  uint8_t threshX_high;
  /**<   Cell Srxlev high threshold. Range: 0 to 31. 
    When the serving cell exceeds thresh_serving_low, 
    the value of an evaluated cell must be greater than this value to be 
    considered for reselection. */

  uint8_t cell_resel_priority;
  /**<   Cell reselection priority. Range: 0 to 7. (This field is only valid 
    when ue_in_idle is TRUE.) */

  uint32_t cells_len;  /**< Must be set to # of elements in cells */
  nas_lte_ngbr_cell_type_v01 cells[NAS_MAX_LTE_NGBR_NUM_CELLS_V01];
}nas_lte_inter_freq_freqs_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t ue_in_idle;
  /**<   TRUE if the UE is in Idle mode; otherwise FALSE. */

  uint32_t freqs_len;  /**< Must be set to # of elements in freqs */
  nas_lte_inter_freq_freqs_type_v01 freqs[NAS_MAX_LTE_NGBR_NUM_FREQS_V01];
}nas_lte_inter_freq_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t arfcn;
  /**<   GSM frequency being reported. Range: 0 to 1023. */

  uint8_t band_1900;
  /**<   Band indicator for the GSM ARFCN (this field is only valid if ARFCN 
    is in the overlapping region). If TRUE and the cell is in the overlapping 
    region, the ARFCN is on the 1900 band. If FALSE, it is on the 1800 band. */

  uint8_t cell_id_valid;
  /**<   Flag indicating whether the base station identity code ID is valid. */

  uint8_t bsic_id;
  /**<   Base station identity code ID, including base station color code and
    network color code. The lower 6 bits can be set to any value. */

  int16_t rssi;
  /**<   Measured RSSI value in 1/10 dB. 
    Range: -2000 to 0  (e.g., -800 means -80.0 dB). */

  int16_t srxlev;
  /**<   Cell selection Rx level (Srxlev) value. Range: -128 to 128. 
    (This field is only valid when ue_in_idle is TRUE.) */
}nas_lte_ngbr_gsm_cell_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t cell_resel_priority;
  /**<   Priority of this frequency group. Range: 0 to 7. (This field is only 
    valid when ue_in_idle is TRUE.) */

  uint8_t thresh_gsm_high;
  /**<   Reselection threshold for high priority layers. Range: 0 to 31. 
    (This field is only valid when ue_in_idle is TRUE.) */

  uint8_t thresh_gsm_low;
  /**<   Reselection threshold for low priority layers. Range: 0 to 31. 
    (This field is only valid when ue_in_idle is TRUE.) */

  uint8_t ncc_permitted;
  /**<    Bitmask specifying whether a neighbor with a specific network color
    code is to be reported. Range: 0 to 255. Bit n set to 1 means a neighbor 
    with NCC n must be included in the report. This flag is synonymous with a
    blacklist in other RATs. (This field is only valid when ue_in_idle is
    TRUE.) */

  uint32_t cells_len;  /**< Must be set to # of elements in cells */
  nas_lte_ngbr_gsm_cell_type_v01 cells[NAS_MAX_LTE_NGBR_GSM_NUM_CELLS_V01];
}nas_lte_ngbr_gsm_freq_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t ue_in_idle;
  /**<   TRUE if the UE is in Idle mode; otherwise FALSE. */

  uint32_t freqs_len;  /**< Must be set to # of elements in freqs */
  nas_lte_ngbr_gsm_freq_type_v01 freqs[NAS_MAX_LTE_NGBR_GSM_NUM_FREQS_V01];
}nas_lte_ngbr_gsm_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t psc;
  /**<   Primary scrambling code. Range: 0 to 511. */

  int16_t cpich_rscp;
  /**<   Absolute power level (in 1/10 dBm) of the common pilot channel as 
    received by the UE. Range: -1200 to -250 (e.g., -250 means -25.0 dBm). 
    Defined in \hyperref[STD-25304]{3GPP TS 25.304}. */

  int16_t cpich_ecno;
  /**<   CPICH Ec/No; ratio (in 1/10 dB) of the received energy per PN chip for 
    the CPICH to the total received power spectral density at the UE antenna 
    connector. Range: -500 to 0 (e.g., -25 means -2.5 dB). Defined in 
    \hyperref[STD-25304]{3GPP TS 25.304}. */

  int16_t srxlev;
  /**<   Cell selection Rx level (Srxlev) value. Range: -128 to 128. 
    (This field is only valid when ue_in_idle is TRUE.) */
}nas_lte_ngbr_wcdma_cell_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t uarfcn;
  /**<   WCDMA layer frequency. Range: 0 to 16383. */

  uint8_t cell_resel_priority;
  /**<   Cell reselection priority. Range: 0 to 7. (This field is only 
    valid when ue_in_idle is TRUE.) */

  uint16_t thresh_Xhigh;
  /**<   Reselection low threshold. Range: 0 to 31. (This field is only 
    valid when ue_in_idle is TRUE.) */

  uint16_t thresh_Xlow;
  /**<   Reselection high threshold. Range: 0 to 31. (This field is only 
    valid when ue_in_idle is TRUE.) */

  uint32_t cells_len;  /**< Must be set to # of elements in cells */
  nas_lte_ngbr_wcdma_cell_type_v01 cells[NAS_MAX_LTE_NGBR_WCDMA_NUM_CELLS_V01];
}nas_lte_ngbr_wcdma_freq_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t ue_in_idle;
  /**<   TRUE if the UE is in Idle mode; otherwise FALSE. */

  uint32_t freqs_len;  /**< Must be set to # of elements in freqs */
  nas_lte_ngbr_wcdma_freq_type_v01 freqs[NAS_MAX_LTE_NGBR_WCDMA_NUM_FREQS_V01];
}nas_lte_ngbr_wcdma_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_WCDMA_RRC_STATE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_WCDMA_RRC_STATE_DISCONNECTED_V01 = 0x00, 
  NAS_WCDMA_RRC_STATE_CELL_PCH_V01 = 0x01, 
  NAS_WCDMA_RRC_STATE_URA_PCH_V01 = 0x02, 
  NAS_WCDMA_RRC_STATE_CELL_FACH_V01 = 0x03, 
  NAS_WCDMA_RRC_STATE_CELL_DCH_V01 = 0x04, 
  NAS_WCDMA_RRC_STATE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_wcdma_rrc_state_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  WCDMA RRC state */
  nas_wcdma_rrc_state_enum_v01 wcdma_rrc_state;
  /**<   WCDMA RRC states. Values: \n
        -0x00 -- NAS_WCDMA_RRC_STATE_ DISCONNECTED -- WCDMA RRC state is IDLE
                defined in \hyperref[STD-25331]{3GPP TS 25.331} \n
        -0x01 -- NAS_WCDMA_RRC_STATE_CELL_ PCH -- WCDMA RRC state is CELL_PCH
                defined in \hyperref[STD-25331]{3GPP TS 25.331} \n
        -0x02 -- NAS_WCDMA_RRC_STATE_URA_PCH -- WCDMA RRC state is URA_PCH
                defined in \hyperref[STD-25331]{3GPP TS 25.331} \n
        -0x03 -- NAS_WCDMA_RRC_STATE_CELL_ FACH -- WCDMA RRC state is CELL_FACH
                defined in \hyperref[STD-25331]{3GPP TS 25.331} \n
        -0x04 -- NAS_WCDMA_RRC_STATE_CELL_ DCH -- WCDMA RRC state is CELL_DCH
                defined in \hyperref[STD-25331]{3GPP TS 25.331}
  */

  uint32_t umts_lte_nbr_cell_len;  /**< Must be set to # of elements in umts_lte_nbr_cell */
  nas_umts_lte_nbr_cell_set_info_type_v01 umts_lte_nbr_cell[NAS_UMTS_LTE_MAX_NBR_CELL_SET_NUM_V01];
}nas_wcdma_ngbr_lte_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  RX Power 0 */
  float rx0_agc;
  /**<   Rx power 0 in dB.
  */

  /*  RX Power 1 */
  float rx1_agc;
  /**<   Rx power 1 in dB.
  */
}nas_rx_power_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Timing Advance Value */
  uint16_t g_ta;
  /**<   Range of the UE from the base station in steps.
  */

  /*  Channel Frequency Number */
  uint16_t g_bcch;
  /**<   Channel number assigned to the frequency.
  */
}nas_gsm_cell_info_ext_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  WCDMA Power */
  float w_agc;
  /**<   Power in dB.
  */

  /*  WCDMA TX Power */
  float w_txagc;
  /**<   Tx power in dB.
  */

  /*  DL Bler */
  uint16_t w_dl_bler;
  /**<   Downlink block error rate percentage.
  */
}nas_wcdma_cell_info_ext_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  PSC */
  uint16_t psc;
  /**<   Primary scrambling code. */

  uint32_t cell_id;
  /**<   Cell ID. */

  /*  RSCP */
  int16_t rscp;
  /**<   Received signal code power; the received power on one code measured in
       dBm on the primary CPICH channel of the active set cell.
  */

  /*  Ec/Io */
  int16_t ecio;
  /**<   ECIO; the received energy per chip divided by the power density in the
       band measured in dBm on the primary CPICH channel of the active set 
       cell.
  */

  /*  UARFCN */
  uint16_t uarfcn;
  /**<   UTRA absolute RF channel number.
  */
}nas_wcdma_active_set_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Cell ID */
  uint32_t cell_id;
  /**<   Cell ID (0xFFFFFFFF indicates cell ID information is not present).
  */

  /*  PLMN */
  char plmn[NAS_PLMN_LEN_V01];
  /**<   MCC/MNC information coded as octet 3, 4, and 5 in 
       \hyperref[STD-24008]{3GPP TS 24.008} Section 10.5.1.3. 
  */

  /*  LAC */
  uint16_t lac;
  /**<   Location area code.
  */

  /*  UARFCN */
  uint16_t uarfcn;
  /**<   UTRA absolute RF channel number.
  */

  /*  PSC */
  uint16_t psc;
  /**<   Primary scrambling code.
  */

  /*  RAC   */
  uint16_t rac;
  /**<   Routing area code. */
}nas_wcdma_active_set_reference_rl_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  UARFCN */
  uint16_t umts_uarfcn;
  /**<   UTRA absolute RF channel number.
  */

  /*  PSC */
  uint16_t umts_psc;
  /**<   Primary scrambling code.
  */

  /*  RSCP */
  int16_t umts_rscp;
  /**<   Received signal code power; the received power on one code measured in 
       dBm on the primary CPICH channel of the neighbor/monitored cell.
  */

  /*  ECIO */
  int16_t umts_ecio;
  /**<   ECIO; the received energy per chip divided by the power density in the 
       band measured in dBm on the primary CPICH channel of the 
       neighbor/monitored cell.
  */

  /*  Squal */
  int16_t umts_squal;
  /**<   Squal; cell selection quality value in dB.
  */

  /*  Srxlev */
  int16_t umts_srxlev;
  /**<   Srxlev; cell selection Rx level value in dB.
  */

  /*  Rank */
  int16_t umts_rank;
  /**<   Rank of the cell. 
   */

  /*  Set */
  uint8_t umts_set;
  /**<   Set of the cell.
  */
}nas_umts_monitored_cell_set_ext_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_WCDMA_L1_SF_E_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_WCDMA_L1_SF_4_V01 = 0x00, 
  NAS_WCDMA_L1_SF_8_V01 = 0x01, 
  NAS_WCDMA_L1_SF_16_V01 = 0x02, 
  NAS_WCDMA_L1_SF_32_V01 = 0x03, 
  NAS_WCDMA_L1_SF_64_V01 = 0x04, 
  NAS_WCDMA_L1_SF_128_V01 = 0x05, 
  NAS_WCDMA_L1_SF_256_V01 = 0x06, 
  NAS_WCDMA_L1_SF_512_V01 = 0x07, 
  NAS_WCDMA_L1_NUM_SF_V01 = 0x08, 
  NAS_WCDMA_L1_SF_E_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_wcdma_l1_sf_e_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_WCDMA_L1_DL_PHYCHAN_E_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_WCDMA_L1_DL_PHYCHAN_PCCPCH_S_V01 = 0x00, 
  NAS_WCDMA_L1_DL_PHYCHAN_PCCPCH_N_V01 = 0x01, 
  NAS_WCDMA_L1_DL_PHYCHAN_SCCPCH0_V01 = 0x02, 
  NAS_WCDMA_L1_DL_PHYCHAN_SCCPCH1_V01 = 0x03, 
  NAS_WCDMA_L1_DL_PHYCHAN_PICH_V01 = 0x04, 
  NAS_WCDMA_L1_DL_PHYCHAN_AICH_V01 = 0x05, 
  NAS_WCDMA_L1_DL_PHYCHAN_HS_RACH_AICH_V01 = 0x06, 
  NAS_WCDMA_L1_DL_PHYCHAN_DPCH_V01 = 0x07, 
  NAS_WCDMA_L1_DL_PHYCHAN_HS_RACH_FDPCH_V01 = 0x08, 
  NAS_WCDMA_L1_DL_PHYCHAN_FDPCH_V01 = 0x09, 
  NAS_WCDMA_L1_DL_PHYCHAN_PDSCH_V01 = 0x0A, 
  NAS_WCDMA_L1_NUM_DL_PHYCHAN_V01 = 0x0B, 
  NAS_WCDMA_L1_DL_PHYCHAN_NOCHAN_V01 = 0x0C, 
  NAS_WCDMA_L1_DL_PHYCHAN_E_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_wcdma_l1_dl_phychan_e_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  UARFCN */
  uint16_t geran_arfcn;
  /**<   Absolute RF channel number.
  */

  /*  BSIC NCC */
  uint8_t geran_bsic_ncc;
  /**<   Base station identity code network color code
       (0xFF indicates information is not present).
  */

  /*  BSIC BCC */
  uint8_t geran_bsic_bcc;
  /**<   Base station identity code base station color code
       (0xFF indicates information is not present).
  */

  /*  GERAN RSSI */
  int16_t geran_rssi;
  /**<   Received signal strength indicator.
  */

  /*  GERAN_RANK */
  int16_t geran_rank;
  /**<   Rank of the cell. 
  */
}nas_umts_geran_nbr_cell_set_ext_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Cell ID */
  uint16_t cell_id;
  /**<   Cell ID (0xFFFFFFFF indicates cell ID information is not present).
  */

  /*  PLMN */
  char plmn[NAS_PLMN_LEN_V01];
  /**<   MCC/MNC information coded as octet 3, 4, and 5 in 
       \hyperref[STD-24008]{3GPP TS 24.008} Section 10.5.1.3. 
  */

  /*  LAC */
  uint16_t lac;
  /**<   Location area code.
  */

  /*  UARFCN */
  uint16_t uarfcn;
  /**<   UTRA absolute RF channel number.
  */

  /*  PSC */
  uint16_t psc;
  /**<   Primary scrambling code.
  */

  /*  RSCP */
  int16_t rscp;
  /**<   Received signal code power; the received power on one code measured in
       dBm on the primary CPICH channel of the serving cell.
  */

  /*  ECIO */
  int16_t ecio;
  /**<   ECIO; the received energy per chip divided by the power density in the
       band measured in dBm on the primary CPICH channel of the serving cell.
  */

  /*  Squal  */
  int16_t squal;
  /**<   Squal; cell selection quality value in dB.
  */

  /*  Srxlev */
  int16_t srxlev;
  /**<   Srxlev; cell selection Rx level value in dB.
  */

  /*  UMTS Monitored Cell Information Set */
  uint32_t umts_monitored_ext_ext_cell_len;  /**< Must be set to # of elements in umts_monitored_ext_ext_cell */
  nas_umts_monitored_cell_set_ext_info_type_v01 umts_monitored_ext_ext_cell[NAS_UMTS_MAX_MONITORED_CELL_SET_NUM_V01];

  /*  GERAN Neighbor Cell Information Set */
  uint32_t umts_geran_ext_nbr_cell_len;  /**< Must be set to # of elements in umts_geran_ext_nbr_cell */
  nas_umts_geran_nbr_cell_set_ext_info_type_v01 umts_geran_ext_nbr_cell[NAS_UMTS_GERAN_MAX_NBR_CELL_SET_NUM_V01];
}nas_umts_cell_ext_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  PSC */
  uint16_t psc;
  /**<   Primary scrambling code. */

  /*  Cell ID */
  uint32_t cell_id;
  /**<   Cell ID. */

  /*  RSCP */
  int16_t rscp;
  /**<   Received signal code power; the received power on one code measured in
       dBm on the primary CPICH channel of the active set cell.
  */

  /*  ECIO */
  int16_t ecio;
  /**<   ECIO; the received energy per chip divided by the power density in the
       band measured in dBm on the primary CPICH channel of the active set 
       cell.
  */

  /*  UARFCN */
  uint16_t uarfcn;
  /**<   UTRA absolute RF channel number.
  */

  /*  Spreading Factor of the Channel */
  nas_wcdma_l1_sf_e_type_v01 sf;
  /**<    Spreading factor of the channel. Values: \n
	   - 0x00 -- NAS_WCDMA_L1_SF_4 \n
	   - 0x01 -- NAS_WCDMA_L1_SF_8 \n
	   - 0x02 -- NAS_WCDMA_L1_SF_16 \n
	   - 0x03 -- NAS_WCDMA_L1_SF_32 \n
	   - 0x04 -- NAS_WCDMA_L1_SF_64 \n
	   - 0x05 -- NAS_WCDMA_L1_SF_128 \n
	   - 0x06 -- NAS_WCDMA_L1_SF_256 \n
	   - 0x07 -- NAS_WCDMA_L1_SF_512 \n
	   - 0x08 -- NAS_WCDMA_L1_NUM_SF
  */

  /*  Physical Channel Type FDPCH/DPCH */
  nas_wcdma_l1_dl_phychan_e_type_v01 phy_chan_type;
  /**<    Physical channel type. Values: \n
	   - 0x00 -- NAS_WCDMA_L1_DL_PHYCHAN_ PCCPCH_S \n
	   - 0x01 -- NAS_WCDMA_L1_DL_PHYCHAN_ PCCPCH_N \n
	   - 0x02 -- NAS_WCDMA_L1_DL_PHYCHAN_ SCCPCH0 \n
	   - 0x03 -- NAS_WCDMA_L1_DL_PHYCHAN_ SCCPCH1 \n
	   - 0x04 -- NAS_WCDMA_L1_DL_PHYCHAN_ PICH \n
	   - 0x05 -- NAS_WCDMA_L1_DL_PHYCHAN_ AICH \n
	   - 0x06 -- NAS_WCDMA_L1_DL_PHYCHAN_ HS_RACH_AICH \n
	   - 0x07 -- NAS_WCDMA_L1_DL_PHYCHAN_ DPCH \n
	   - 0x08 -- NAS_WCDMA_L1_DL_PHYCHAN_ HS_RACH_FDPCH \n
	   - 0x09 -- NAS_WCDMA_L1_DL_PHYCHAN_ FDPCH \n
	   - 0x0A -- NAS_WCDMA_L1_DL_PHYCHAN_ PDSCH \n
	   - 0x0B -- NAS_WCDMA_L1_NUM_DL_ PHYCHAN \n
	   - 0x0C -- NAS_WCDMA_L1_DL_PHYCHAN_ NOCHAN
  */

  /*  Slot Format for the Channel  */
  uint8_t slot_format;
  /**<   
      Indicates slot format. Values range between 0 and 6 
      per \hyperref[STD-25211]{3GPP TS 25.211}.
  */

  /*  Indicates CM On or Not */
  uint8_t is_compressed_mode_on;
  /**<   
      Indicates whether the compressed mode is ON or OFF. 
  */
}nas_wcdma_active_set_ext_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Cell ID */
  uint32_t nmr_cell_id;
  /**<   Cell ID (0xFFFFFFFF indicates cell ID information is not present).
  */

  /*  PLMN */
  char nmr_plmn[NAS_PLMN_LEN_V01];
  /**<   MCC/MNC information coded as octet 3, 4, and 5 in 
       \hyperref[STD-24008]{3GPP TS 24.008} Section 10.5.1.3. 
       (This field is ignored when nmr_cell_id is not present.)
  */

  /*  LAC */
  uint16_t nmr_lac;
  /**<   Location area code. (This field is ignored when nmr_cell_id is not present.)
  */

  /*  ARFCN */
  uint16_t nmr_arfcn;
  /**<   Absolute RF channel number.
  */

  /*  BSIC */
  uint8_t nmr_bsic;
  /**<   Base station identity code.
  */

  /*  Rx Lev */
  uint16_t nmr_rx_lev;
  /**<   Cell Rx measurement. Values range between 0 and 63, which is 
       mapped to a measured signal level: \n

       - Rxlev 0 is a signal strength less than -110 dBm \n
       - Rxlev 1 is -110 dBm to -109 dBm    \n
       - Rxlev 2 is -109 dBm to -108 dBm    \n
       - ...                                \n
       - Rxlev 62 is -49 dBm to -48 dBm     \n
       - Rxlev 63 is greater than -48 dBm
  */

  /*  Nmr_c1 */
  int32_t nmr_c1;
  /**<   C1 as defined in \hyperref[STD-45008]{3GPP TS 45.008} Section 6.4. Default: 0.
  */

  /*  Nmr_c2 */
  int32_t nmr_c2;
  /**<   C2 as defined in \hyperref[STD-45008]{3GPP TS 45.008} Section 6.4. Default: 0.
  */

  /*  Nmr_c31 */
  int32_t nmr_c31;
  /**<   C31 as defined in \hyperref[STD-45008]{3GPP TS 45.008} Section 10.1.2. Default: 0.
  */

  /*  Nmr_c32 */
  int32_t nmr_c32;
  /**<   C32 as defined in \hyperref[STD-45008]{3GPP TS 45.008} Section 10.1.2. Default: 0.
  */
}nas_nmr_cell_info_ext_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Cell ID */
  uint32_t cell_id;
  /**<   Cell ID (0xFFFFFFFF indicates cell ID information is not present).
  */

  /*  PLMN */
  char plmn[NAS_PLMN_LEN_V01];
  /**<   MCC/MNC information coded as octet 3, 4, and 5 in 
       \hyperref[STD-24008]{3GPP TS 24.008} Section 10.5.1.3. 
       (This field is ignored when cell_id is not present.)
  */

  /*  LAC */
  uint16_t lac;
  /**<   Location area code. (This field is ignored when cell_id is not present.)
  */

  /*  ARFCN */
  uint16_t arfcn;
  /**<   Absolute RF channel number.
  */

  /*  BSIC */
  uint8_t bsic;
  /**<   Base station identity code.
  */

  /*  Timing Advance */
  uint32_t timing_advance;
  /**<   Measured delay (in bit periods; 1 bit period = 48/13 microsecond) of 
       an access burst transmission on the RACH or PRACH to the expected signal 
       from an MS at zero distance under static channel conditions.
       (0xFFFFFFFF indicates timing advance information is not present.)
  */

  /*  Rx Lev */
  uint16_t rx_lev;
  /**<   Serving cell Rx measurement. Values range between 0 and 63, which is 
       mapped to a measured signal level: \n

       - Rxlev 0 is a signal strength less than -110 dBm \n
       - Rxlev 1 is -110 dBm to -109 dBm    \n
       - Rxlev 2 is -109 dBm to -108 dBm    \n
       - ...                               \n
       - Rxlev 62 is -49 dBm to -48 dBm     \n
       - Rxlev 63 is greater than -48 dBm
  */

  /*  Neighbor Cell Information  */
  uint32_t nmr_cell_info_len;  /**< Must be set to # of elements in nmr_cell_info */
  nas_nmr_cell_info_ext_type_v01 nmr_cell_info[NAS_NMR_MAX_NUM_V01];
  /**<   Contains information only if neighbors are present; 
       includes: \n
       - nmr_cell_id \n
       - nmr_plmn \n
       - nmr_lac \n
       - nmr_arfcn \n
       - nmr_bsic \n
       - nmr_rx_lev \n
       - nmr_c1 \n
       - nmr_c2 \n
       - nmr_c31 \n
       - nmr_c32
  */
}nas_geran_cell_info_ext_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t pbcch_present;
  /**<   Presence of PBCCH in the cell: \n
       - 0 -- No \n
       - 1 -- Yes \n
       - 0xff -- Invalid */

  uint8_t gprs_rxlev_access_min;
  /**<   Rx level access minimum. 
       Range: 0 to 63; 0xff is invalid; \hyperref[STD-45008]{3GPP TS 45.008}.
  */

  uint8_t gprs_ms_txpwr_max_cch;
  /**<   MS Tx power maximum CCH. 
      Range: 0 to 31; 0xff is invalid; \hyperref[STD-45008]{3GPP TS 45.008} and 
      \hyperref[STD-45005]{3GPP TS 45.005}.
  */
}nas_geran_eng_mode_scell_config_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves cell location-related information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  GERAN Info */
  uint8_t geran_info_valid;  /**< Must be set to true if geran_info is being passed */
  nas_geran_cell_info_type_v01 geran_info;

  /* Optional */
  /*  UMTS Info */
  uint8_t umts_info_valid;  /**< Must be set to true if umts_info is being passed */
  nas_umts_cell_info_type_v01 umts_info;

  /* Optional */
  /*  CDMA Info */
  uint8_t cdma_info_valid;  /**< Must be set to true if cdma_info is being passed */
  nas_cdma_cell_info_type_v01 cdma_info;

  /* Optional */
  /*  LTE Info - Intrafrequency */
  uint8_t lte_intra_valid;  /**< Must be set to true if lte_intra is being passed */
  nas_lte_intra_freq_type_v01 lte_intra;

  /* Optional */
  /*  LTE Info - Interfrequency */
  uint8_t lte_inter_valid;  /**< Must be set to true if lte_inter is being passed */
  nas_lte_inter_freq_type_v01 lte_inter;

  /* Optional */
  /*  LTE Info - Neighboring GSM */
  uint8_t lte_gsm_valid;  /**< Must be set to true if lte_gsm is being passed */
  nas_lte_ngbr_gsm_type_v01 lte_gsm;

  /* Optional */
  /*  LTE Info - Neighboring WCDMA */
  uint8_t lte_wcdma_valid;  /**< Must be set to true if lte_wcdma is being passed */
  nas_lte_ngbr_wcdma_type_v01 lte_wcdma;

  /* Optional */
  /*  UMTS Cell ID */
  uint8_t umts_cell_id_valid;  /**< Must be set to true if umts_cell_id is being passed */
  uint32_t umts_cell_id;
  /**<   Cell ID (0xFFFFFFFF indicates cell ID information is not present).
  */

  /* Optional */
  /*  WCDMA Info - LTE Neighbor Cell Info Set */
  uint8_t wcdma_lte_valid;  /**< Must be set to true if wcdma_lte is being passed */
  nas_wcdma_ngbr_lte_type_v01 wcdma_lte;

  /* Optional */
  /*  CDMA Rx Info */
  uint8_t cdma_rx_power_valid;  /**< Must be set to true if cdma_rx_power is being passed */
  nas_rx_power_type_v01 cdma_rx_power;

  /* Optional */
  /*  HDR Rx Info */
  uint8_t hdr_rx_power_valid;  /**< Must be set to true if hdr_rx_power is being passed */
  nas_rx_power_type_v01 hdr_rx_power;

  /* Optional */
  /*  GSM Cell Info Ext */
  uint8_t gsm_info_ext_valid;  /**< Must be set to true if gsm_info_ext is being passed */
  nas_gsm_cell_info_ext_type_v01 gsm_info_ext;

  /* Optional */
  /*  WCDMA Cell Info Ext */
  uint8_t wcdma_info_ext_valid;  /**< Must be set to true if wcdma_info_ext is being passed */
  nas_wcdma_cell_info_ext_type_v01 wcdma_info_ext;

  /* Optional */
  /*  WCDMA GSM Neighbor Cell Ext */
  uint8_t gncell_bcch_valid;  /**< Must be set to true if gncell_bcch is being passed */
  uint32_t gncell_bcch_len;  /**< Must be set to # of elements in gncell_bcch */
  uint16_t gncell_bcch[NAS_UMTS_GERAN_MAX_NBR_CELL_SET_NUM_V01];
  /**<   Channel number assigned to the frequency for the neighboring
       GSM cells.
  */

  /* Optional */
  /*  LTE Info - Timing Advance */
  uint8_t timing_advance_valid;  /**< Must be set to true if timing_advance is being passed */
  int32_t timing_advance;
  /**<   Timing advance of the LTE cell in microseconds. (0xFFFFFFFF indicates 
       timing advance information is not present.) */

  /* Optional */
  /*  WCDMA Info - Active Set */
  uint8_t cells_valid;  /**< Must be set to true if cells is being passed */
  uint32_t cells_len;  /**< Must be set to # of elements in cells */
  nas_wcdma_active_set_info_type_v01 cells[NAS_UMTS_MAX_ACTIVE_CELL_SET_NUM_V01];

  /* Optional */
  /*  WCDMA Info - Active Set Reference Radio Link */
  uint8_t wcdma_active_set_reference_rl_valid;  /**< Must be set to true if wcdma_active_set_reference_rl is being passed */
  nas_wcdma_active_set_reference_rl_type_v01 wcdma_active_set_reference_rl;

  /* Optional */
  /*  Extended GERAN Info */
  uint8_t geran_info_ext_valid;  /**< Must be set to true if geran_info_ext is being passed */
  nas_geran_cell_info_ext_type_v01 geran_info_ext;

  /* Optional */
  /*  UMTS Extended Info */
  uint8_t umts_ext_info_valid;  /**< Must be set to true if umts_ext_info is being passed */
  nas_umts_cell_ext_info_type_v01 umts_ext_info;

  /* Optional */
  /*  Extended WCDMA Info - Active Set */
  uint8_t wcdma_active_set_cells_valid;  /**< Must be set to true if wcdma_active_set_cells is being passed */
  uint32_t wcdma_active_set_cells_len;  /**< Must be set to # of elements in wcdma_active_set_cells */
  nas_wcdma_active_set_ext_info_type_v01 wcdma_active_set_cells[NAS_UMTS_MAX_ACTIVE_CELL_SET_NUM_V01];

  /* Optional */
  /*  Scell GERAN Config */
  uint8_t scell_geran_config_valid;  /**< Must be set to true if scell_geran_config is being passed */
  nas_geran_eng_mode_scell_config_type_v01 scell_geran_config;

  /* Optional */
  /*  Current L1 Timeslot */
  uint8_t current_l1_ts_valid;  /**< Must be set to true if current_l1_ts is being passed */
  uint8_t current_l1_ts;
  /**<   Timeslot number. Range: 0 to 7.
  */

  /* Optional */
  /*  Doppler Measurement */
  uint8_t doppler_measurement_valid;  /**< Must be set to true if doppler_measurement is being passed */
  uint16_t doppler_measurement;
  /**<   Doppler measurement in Hz. Range: 0 to 400. 
       Value 0xFFFF indicates that the measurement is yet to be done.
  */

  /* Optional */
  /*  LTE Info Extended - Intrafrequency EARFCN */
  uint8_t lte_intra_earfcn_valid;  /**< Must be set to true if lte_intra_earfcn is being passed */
  uint32_t lte_intra_earfcn;
  /**<   LTE intrafrequency EARFCN extended size.
  */

  /* Optional */
  /*  LTE Info Extended - Interfrequency EARFCN */
  uint8_t lte_inter_earfcn_valid;  /**< Must be set to true if lte_inter_earfcn is being passed */
  uint32_t lte_inter_earfcn_len;  /**< Must be set to # of elements in lte_inter_earfcn */
  uint32_t lte_inter_earfcn[NAS_MAX_LTE_NGBR_NUM_FREQS_V01];
  /**<   LTE interfrequency EARFCN extended size. 
  */

  /* Optional */
  /*  WCDMA Info Extended - LTE Neighbor Cell Info EARFCN */
  uint8_t lte_earfcn_valid;  /**< Must be set to true if lte_earfcn is being passed */
  uint32_t lte_earfcn_len;  /**< Must be set to # of elements in lte_earfcn */
  uint32_t lte_earfcn[NAS_UMTS_LTE_MAX_NBR_CELL_SET_NUM_V01];
  /**<   LTE neighbor cell information EARFCN. */

  /* Optional */
  /*  NAS Info - EMM State  */
  uint8_t emm_state_valid;  /**< Must be set to true if emm_state is being passed */
  nas_emm_state_e_type_v01 emm_state;
  /**<   NAS Extended Mobility Management (EMM) state. Values: \n
      - NAS_EMM_NULL (0) --  Null \n 
      - NAS_EMM_DEREGISTERED (1) --  Deregistered \n 
      - NAS_EMM_REGISTERED_INITIATED (2) --  Registered, initiated \n 
      - NAS_EMM_REGISTERED (3) --  Registered \n 
      - NAS_EMM_TRACKING_AREA_UPDATING_INITIATED (4) --  Tracking area update initiated \n 
      - NAS_EMM_SERVICE_REQUEST_INITIATED (5) --  Service request initiated \n 
      - NAS_EMM_DEREGISTERED_INITIATED (6) --  Deregistered, initiated 
 */

  /* Optional */
  /*  NAS Info - EMM Substate (Unused/Ignored) */
  uint8_t emm_substate_valid;  /**< Must be set to true if emm_substate is being passed */
  nas_emm_substate_e_type_v01 emm_substate;
  /**<   NAS EMM substate. Values: \n
      - NAS_EMM_DEREGISTERED_NO_IMSI (0) --  Deregistered, no IMSI \n 
      - NAS_EMM_DEREGISTERED_PLMN_SEARCH (1) --  Deregistered, PLMN search \n 
      - NAS_EMM_DEREGISTERED_ATTACH_NEEDED (2) --  Deregistered, attach needed \n 
      - NAS_EMM_DEREGISTERED_NO_CELL_AVAILABLE (3) --  Deregistered, no cell is available \n 
      - NAS_EMM_DEREGISTERED_ATTEMPTING_TO_ATTACH (4) --  Deregistered, attempting to attach \n 
      - NAS_EMM_DEREGISTERED_NORMAL_SERVICE (5) --  Deregistered, normal service \n 
      - NAS_EMM_DEREGISTERED_LIMITED_SERVICE (6) --  Deregistered, limited service \n 
      - NAS_EMM_REGISTERED_NORMAL_SERVICE (7) --  Registered, normal service \n 
      - NAS_EMM_REGISTERED_UPDATE_NEEDED (8) --  Registered, update needed \n 
      - NAS_EMM_REGISTERED_ATTEMPTING_TO_UPDATE (9) --  Registered, attempting to update \n 
      - NAS_EMM_REGISTERED_NO_CELL_AVAILABLE (10) --  Registered, no cell is available \n 
      - NAS_EMM_REGISTERED_PLMN_SEARCH (11) --  Registered, PLMN search \n 
      - NAS_EMM_REGISTERED_LIMITED_SERVICE (12) --  Registered, limited service \n 
      - NAS_EMM_REGISTERED_ATTEMPTING_TO_UPDATE_MM (13) --  Registered, attemping to update MM \n 
      - NAS_EMM_REGISTERED_IMSI_DETACH_INITIATED (14) --  Registered, IMSI detach initiated \n 
      - NAS_EMM_INTERNAL_SUBSTATE (15) --  Internal substate  
 */

  /* Optional */
  /*  NAS Info - RRC State */
  uint8_t emm_connection_state_valid;  /**< Must be set to true if emm_connection_state is being passed */
  nas_rrc_state_e_type_v01 emm_connection_state;
  /**<   NAS RRC state. Values: \n
      - NAS_RRC_IDLE (0) --  Status: Idle \n 
      - NAS_RRC_CONNECTED (1) --  Status: Connected  
 */

  /* Optional */
  /*  LTE Info Extended - RRC State */
  uint8_t lte_rrc_state_ext_valid;  /**< Must be set to true if lte_rrc_state_ext is being passed */
  lte_rrc_state_ext_e_type_v01 lte_rrc_state_ext;
  /**<   LTE RRC state. Values: \n
      - LTE_RRC_STATE_EXT_NULL (0) --  Null \n 
      - LTE_RRC_STATE_EXT_IDLE_CAMPED_ANYCELL (1) --  Idle, Camped on Any Cell \n 
      - LTE_RRC_STATE_EXT_IDLE_CAMPED_NORMAL (2) --  Idle, Camped Normal \n 
      - LTE_RRC_STATE_EXT_CONNECTING (3) --  Connecting \n 
      - LTE_RRC_STATE_EXT_CONNECTED (4) --  Connected \n 
      - LTE_RRC_STATE_EXT_CLOSING (5) --  Releasing \n 
 */
}nas_get_cell_location_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Queries the operator name for a specified network.
              \label{idl:getPlmnName} */
typedef struct {

  /* Mandatory */
  /*  PLMN  */
  nas_plmn_id_type_v01 plmn;

  /* Optional */
  /*  Suppress SIM Error */
  uint8_t suppress_sim_error_valid;  /**< Must be set to true if suppress_sim_error is being passed */
  uint8_t suppress_sim_error;
  /**<   Suppress the QMI_NAS_SIM_NOT_INITIALIZED error, so to allow network name 
       retrieval even when the SIM is not initialized. Values: \n
       - FALSE -- SIM initialization is checked; an error is returned if the SIM 
                  is not available (default value) \n
       - TRUE  -- SIM initialization is not checked; if the SIM is not available, 
                  retrieving the name from the SIM files is skipped
  */

  /* Optional */
  /*  MNC PCS Digit Include Status */
  uint8_t mnc_includes_pcs_digit_valid;  /**< Must be set to true if mnc_includes_pcs_digit is being passed */
  uint8_t mnc_includes_pcs_digit;
  /**<   This field is used to interpret the length of the corresponding 
       MNC reported in the PLMN TLV (0x01). Values: \n

       - TRUE  -- MNC is a three-digit value; e.g., a reported value of 
                  90 corresponds to an MNC value of 090  \n
       - FALSE -- MNC is a two-digit value; e.g., a reported value of 
                  90 corresponds to an MNC value of 90 \n \vspace{-.12in}

       If this TLV is not present, an MNC smaller than 100 is assumed to be 
       a two-digit value, and an MNC greater than or equal to 100 is 
       assumed to be a three-digit value.
  */

  /* Optional */
  /*  Always Send PLMN Name */
  uint8_t always_send_plmn_name_valid;  /**< Must be set to true if always_send_plmn_name is being passed */
  uint8_t always_send_plmn_name;
  /**<   Indicates that the client wants to receive the PLMN name regardless
       of the EF display condition. Values: \n

       - FALSE -- EF SPN PLMN display condition is looked at before attempting 
                  to retrieve the name \n
       - TRUE  -- PLMN name is returned regardless of the EF SPN PLMN display 
                  condition.
  */

  /* Optional */
  /*  Use Static Table Only */
  uint8_t use_static_table_only_valid;  /**< Must be set to true if use_static_table_only is being passed */
  uint8_t use_static_table_only;
  /**<   Indicates that the client wants to receive the network name only from 
       the SE.13 GSM Mobile Network Codes and Names Static Table. Values: \n

       - FALSE -- Normal procedure is followed when determining the network 
                  name (default value) \n
       - TRUE  -- SIM initialization state and the EF SPN PLMN display 
                  condition are ignored; the network name is read directly 
                  from the table
  */

  /* Optional */
  /*  CSG ID */
  uint8_t csg_id_valid;  /**< Must be set to true if csg_id is being passed */
  uint32_t csg_id;
  /**<   Closed subscriber group identifier.
  */

  /* Optional */
  /*  Radio Access Technology */
  uint8_t rat_valid;  /**< Must be set to true if rat is being passed */
  nas_radio_if_enum_v01 rat;
  /**<   Radio access technology. Values: \n
    - 0x04 -- NAS_RADIO_IF_GSM         -- GSM \n
    - 0x05 -- NAS_RADIO_IF_UMTS        -- UMTS \n
    - 0x08 -- NAS_RADIO_IF_LTE         -- LTE \n
    - 0x09 -- NAS_RADIO_IF_TDSCDMA     -- TD-SCDMA
  */

  /* Optional */
  /*  Send All Information */
  uint8_t send_all_information_valid;  /**< Must be set to true if send_all_information is being passed */
  uint8_t send_all_information;
  /**<   Indicates that the client wants to receive all available information, 
       including display byte information, without the modem influencing the 
       name sent. Values: \n       
       - FALSE -- Follow the normal procedure (default value) \n
       - TRUE  -- Send all available information 
  */
}nas_get_plmn_name_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  SPN coding scheme */
  nas_coding_scheme_enum_v01 spn_enc;
  /**<  
        Coding scheme for the service provider name. Values: \n
        -0x00 -- NAS_CODING_SCHEME_ CELL_BROADCAST_GSM -- SMS default 7-bit coded 
                 alphabet as defined in \hyperref[STD-23038]{3GPP TS 23.038} 
                 with bit 8 set to 0 \n
        -0x01 -- NAS_CODING_SCHEME_ UCS2 -- UCS2 (16 bit, little-endian) 
                 \hyperref[STD-23038]{3GPP TS 23.038} \n
        Note: This value is ignored if spn_len is zero.
  */

  /*  SPN */
  uint32_t spn_len;  /**< Must be set to # of elements in spn */
  char spn[NAS_SPN_LEN_MAX_V01];
  /**<  
     Service provider name string.
  */

  /*  PLMN short name encoding scheme */
  nas_coding_scheme_enum_v01 plmn_short_name_enc;
  /**<  
        Coding scheme for plmn_short_name. Values: \n
        -0x00 -- NAS_CODING_SCHEME_ CELL_BROADCAST_GSM -- SMS default 7-bit coded 
                 alphabet as defined in \hyperref[STD-23038]{3GPP TS 23.038} 
                 with bit 8 set to 0 \n
        -0x01 -- NAS_CODING_SCHEME_ UCS2 -- UCS2 (16 bit, little-endian) 
                 \hyperref[STD-23038]{3GPP TS 23.038} \n
        Note: This value is ignored if plmn_short_name_len is zero.
  */

  /*  PLMN short name country initial include status */
  nas_country_initials_add_enum_v01 plmn_short_name_ci;
  /**<  
        Indicates whether the country initials are to be added to the 
        plmn_short_name. Values: \n
        -0x00 -- Do not add the letters for the country's initials to the name \n
        -0x01 -- Add the country's initials and a text string to the name \n
        -0xFF -- Not specified \n
        Note: This value is ignored if plmn_short_name_len is zero.
  */

  /*  PLMN short spare bits */
  nas_spare_bits_enum_v01 plmn_short_spare_bits;
  /**<   Values: \n
       -0x01 -- Bit 8 is spare and set to 0 in octet n                       \n
       -0x02 -- Bits 7 and 8 are spare and set to 0 in octet n               \n
       -0x03 -- Bits 6 to 8 (inclusive) are spare and set to 0 in octet n    \n
       -0x04 -- Bits 5 to 8 (inclusive) are spare and set to 0 in octet n    \n
       -0x05 -- Bits 4 to 8 (inclusive) are spare and set to 0 in octet n    \n
       -0x06 -- Bits 3 to 8 (inclusive) are spare and set to 0 in octet n    \n
       -0x07 -- Bits 2 to 8 (inclusive) are spare and set to 0 in octet n    \n
       -0x00 -- Carries no information about the number of spare bits in octet n    \n
       Note: This value is ignored if plmn_short_name_len is zero.
  */

  /*  PLMN short name */
  uint32_t plmn_short_name_len;  /**< Must be set to # of elements in plmn_short_name */
  char plmn_short_name[NAS_PLMN_NAME_MAX_V01];
  /**<   PLMN short name. If no short name is available for the specified PLMN ID, 
       MCC and MNC values are included in ASCII format with the MCC followed
       by the MNC within double quotes. For example, for an MCC of 123 and an 
       MNC of 678, the ASCII string "123678" is returned when the short name 
       is not available.  
  */

  /*  PLMN long name encoding scheme */
  nas_coding_scheme_enum_v01 plmn_long_name_enc;
  /**<  
        Coding scheme for plmn_long_name. Values: \n
        -0x00 -- NAS_CODING_SCHEME_ CELL_BROADCAST_GSM -- SMS default 7-bit coded 
                 alphabet as defined in \hyperref[STD-23038]{3GPP TS 23.038} 
                 with bit 8 set to 0 \n
        -0x01 -- NAS_CODING_SCHEME_ UCS2 -- UCS2 (16 bit, little-endian) 
                 \hyperref[STD-23038]{3GPP TS 23.038} \n
        Note: This value is ignored if plmn_long_name_len is zero.
  */

  /*  PLMN long name country initial include status */
  nas_country_initials_add_enum_v01 plmn_long_name_ci;
  /**<  
        Indicates whether the country initials are to be added to the 
        plmn_long_name. Values: \n
        -0x00 -- Do not add the letters for the country's initials to the name \n
        -0x01 -- Add the country's initials and a text string to the name \n
        -0xFF -- Not specified \n
        Note: This value is ignored if plmn_long_name_len is zero.
  */

  /*  PLMN long spare bits  */
  nas_spare_bits_enum_v01 plmn_long_spare_bits;
  /**<   Values: \n
       -0x01 -- Bit 8 is spare and set to 0 in octet n                       \n
       -0x02 -- Bits 7 and 8 are spare and set to 0 in octet n               \n
       -0x03 -- Bits 6 to 8 (inclusive) are spare and set to 0 in octet n    \n
       -0x04 -- Bits 5 to 8 (inclusive) are spare and set to 0 in octet n    \n
       -0x05 -- Bits 4 to 8 (inclusive) are spare and set to 0 in octet n    \n
       -0x06 -- Bits 3 to 8 (inclusive) are spare and set to 0 in octet n    \n
       -0x07 -- Bits 2 to 8 (inclusive) are spare and set to 0 in octet n    \n
       -0x00 -- Carries no information about the number of spare bits in octet n    \n
       Note: This value is ignored if plmn_long_name_len is zero.
  */

  uint32_t plmn_long_name_len;  /**< Must be set to # of elements in plmn_long_name */
  char plmn_long_name[NAS_PLMN_NAME_MAX_V01];
  /**<   PLMN long name. If no long name is available for the specified PLMN ID, 
       MCC and MNC values are included in ASCII format with the MCC followed
       by the MNC within double quotes. For example, for an MCC of 123 and an 
       MNC of 678, the ASCII string "123678" is returned when the long name 
       is not available.  
  */
}nas_3gpp_eons_plmn_name_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_tri_state_boolean_type_v01 is_spn_set;
  /**<   Whether the SPN display bit is set. Values: \n
      - NAS_TRI_FALSE (0) --  Status: FALSE \n 
      - NAS_TRI_TRUE (1) --  Status: TRUE  \n 
      - NAS_TRI_UNKNOWN (2) --  Status: Unknown  
 */

  nas_tri_state_boolean_type_v01 is_plmn_set;
  /**<   Whether the PLMN display bit is set. Values: \n
      - NAS_TRI_FALSE (0) --  Status: FALSE \n 
      - NAS_TRI_TRUE (1) --  Status: TRUE  \n 
      - NAS_TRI_UNKNOWN (2) --  Status: Unknown  
 */
}nas_display_bit_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_LANG_ID_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_LANG_ID_UNKNOWN_V01 = 0x00, /**<  Unknown language ID \n  */
  NAS_LANG_ID_ZH_TRAD_V01 = 0x01, /**<  Traditional Chinese \n  */
  NAS_LANG_ID_ZH_SIMP_V01 = 0x02, /**<  Simplified Chinese  */
  NAS_LANG_ID_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_lang_id_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t plmn_long_name_len;  /**< Must be set to # of elements in plmn_long_name */
  uint16_t plmn_long_name[NAS_ALT_LANG_NAME_LEN_MAX_V01];
  /**<   PLMN long name, in UCS2 (16 bit, little-endian) encoded format.
  */

  uint32_t plmn_short_name_len;  /**< Must be set to # of elements in plmn_short_name */
  uint16_t plmn_short_name[NAS_ALT_LANG_NAME_LEN_MAX_V01];
  /**<   PLMN short name, in UCS2 (16 bit, little-endian) encoded format.
  */

  nas_lang_id_enum_v01 lang_id;
  /**<   Language ID for the PLMN long and short names. Values: \n
      - NAS_LANG_ID_UNKNOWN (0x00) --  Unknown language ID \n 
      - NAS_LANG_ID_ZH_TRAD (0x01) --  Traditional Chinese \n 
      - NAS_LANG_ID_ZH_SIMP (0x02) --  Simplified Chinese 
 */
}nas_lang_plmn_names_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Queries the operator name for a specified network.
              \label{idl:getPlmnName} */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  3GPP EONS PLMN Name  */
  uint8_t eons_plmn_name_3gpp_valid;  /**< Must be set to true if eons_plmn_name_3gpp is being passed */
  nas_3gpp_eons_plmn_name_type_v01 eons_plmn_name_3gpp;

  /* Optional */
  /*  Display Bit Information */
  uint8_t eons_display_bit_info_valid;  /**< Must be set to true if eons_display_bit_info is being passed */
  nas_display_bit_type_v01 eons_display_bit_info;

  /* Optional */
  /*  Network Information */
  uint8_t is_home_network_valid;  /**< Must be set to true if is_home_network is being passed */
  nas_tri_state_boolean_type_v01 is_home_network;
  /**<   Whether the network is the home network. Values: \n
      - NAS_TRI_FALSE (0) --  Status: FALSE \n 
      - NAS_TRI_TRUE (1) --  Status: TRUE  \n 
      - NAS_TRI_UNKNOWN (2) --  Status: Unknown  
 */

  /* Optional */
  /*  3GPP EONS PLMN Name with Language ID */
  uint8_t lang_plmn_names_valid;  /**< Must be set to true if lang_plmn_names is being passed */
  uint32_t lang_plmn_names_len;  /**< Must be set to # of elements in lang_plmn_names */
  nas_lang_plmn_names_type_v01 lang_plmn_names[NAS_ALT_LANG_MAX_V01];

  /* Optional */
  /*  Additional Information */
  uint8_t addl_info_valid;  /**< Must be set to true if addl_info is being passed */
  uint32_t addl_info_len;  /**< Must be set to # of elements in addl_info */
  uint16_t addl_info[NAS_PLMN_NAME_MAX_V01];
  /**<   Additional information provided for the PLMN, in UCS2 
       (16 bit little-endian) encoded format.
  */

  /* Optional */
  /*  Network Name Source */
  uint8_t nw_name_source_valid;  /**< Must be set to true if nw_name_source is being passed */
  nas_nw_name_source_enum_type_v01 nw_name_source;
  /**<   Network name source. Values: \n
      - NAS_NW_NAME_SOURCE_UNKNOWN (0x00) --  Unknown \n 
      - NAS_NW_NAME_SOURCE_OPL_PNN (0x01) --  Operator PLMN list and PLMN network name \n 
      - NAS_NW_NAME_SOURCE_CPHS_ONS (0x02) --  Common PCN handset specification and operator name string \n 
      - NAS_NW_NAME_SOURCE_NITZ (0x03) --  Network identity and time zone \n 
      - NAS_NW_NAME_SOURCE_SE13 (0x04) --  GSMA SE13 table \n 
      - NAS_NW_NAME_SOURCE_MCC_MNC (0x05) --  Mobile country code and mobile network code \n 
      - NAS_NW_NAME_SOURCE_SPN (0x06) --  Service provider name 
 */

  /* Optional */
  /*  Service Provider Name Ext */
  uint8_t spn_ext_valid;  /**< Must be set to true if spn_ext is being passed */
  uint16_t spn_ext[NAS_SPN_EXT_LEN_MAX_V01 + 1];
  /**<   Service provider name.
  */
}nas_get_plmn_name_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Binds the current control point to a specific subscription.  */
typedef struct {

  /* Mandatory */
  /*  Subscription Type */
  nas_subs_type_enum_v01 subs_type;
  /**<   Values: \n
      - NAS_PRIMARY_SUBSCRIPTION (0x00) --  Primary subscription \n 
      - NAS_SECONDARY_SUBSCRIPTION (0x01) --  Secondary subscription \n 
      - NAS_TERTIARY_SUBSCRIPTION (0x02) --  Tertiary subscription 
 */
}nas_bind_subscription_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Binds the current control point to a specific subscription.  */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_bind_subscription_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_DDS_DURATION_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_DDS_DURATION_PERMANANT_V01 = 0x00, /**<  Permanent  */
  NAS_DDS_DURATION_TEMPORARY_V01 = 0x01, /**<  Temporary  */
  NAS_DDS_DURATION_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_dds_duration_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_STANDBY_PREF_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_SINGLE_STANDBY_V01 = 0x01, 
  NAS_DUAL_STANDBY_WITH_TUNE_AWAY_V01 = 0x02, 
  NAS_DUAL_STANDBY_WITHOUT_TUNE_AWAY_V01 = 0x04, 
  NAS_AUTOMATIC_WITH_TUNE_AWAY_V01 = 0x05, 
  NAS_AUTOMATIC_WITHOUT_TUNE_AWAY_V01 = 0x06, 
  NAS_TRIPLE_STANDBY_V01 = 0x07, 
  NAS_STANDBY_PREF_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_standby_pref_enum_v01;
/**
    @}
  */

typedef uint64_t nas_active_subs_mask_type_v01;
#define QMI_NAS_ACTIVE_SUB_PRIMARY_V01 ((nas_active_subs_mask_type_v01)0x01ull) 
#define QMI_NAS_ACTIVE_SUB_SECONDARY_V01 ((nas_active_subs_mask_type_v01)0x02ull) 
#define QMI_NAS_ACTIVE_SUB_TERTIARY_V01 ((nas_active_subs_mask_type_v01)0x04ull) 
/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Configures dual standby preference. */
typedef struct {

  /* Optional */
  /*  Standby Preference */
  uint8_t standby_pref_valid;  /**< Must be set to true if standby_pref is being passed */
  nas_standby_pref_enum_v01 standby_pref;
  /**<  
        Values: \n
        -0x05 -- Automatic mode with tune away where applicable \n
        -0x06 -- Automatic mode without tune away

        \vspace{3pt}
        All other values are reserved.
  */

  /* Optional */
  /*  Priority Subs */
  uint8_t priority_subs_valid;  /**< Must be set to true if priority_subs is being passed */
  nas_subs_type_enum_v01 priority_subs;
  /**<   Subscription to give priority when listening to the paging channel during
 standby. Values: \n
      - NAS_PRIMARY_SUBSCRIPTION (0x00) --  Primary subscription \n 
      - NAS_SECONDARY_SUBSCRIPTION (0x01) --  Secondary subscription \n 
      - NAS_TERTIARY_SUBSCRIPTION (0x02) --  Tertiary subscription 

 \vspace{3pt}
 All other values are reserved.
 */

  /* Optional */
  /*  Default Data Subs */
  uint8_t default_data_subs_valid;  /**< Must be set to true if default_data_subs is being passed */
  nas_subs_type_enum_v01 default_data_subs;
  /**<    This TLV is no longer supported in this interface. \n
        If this TLV is provided, an error is returned in the response.
  */

  /* Optional */
  /*  Default Voice Subs */
  uint8_t default_voice_subs_valid;  /**< Must be set to true if default_voice_subs is being passed */
  nas_subs_type_enum_v01 default_voice_subs;
  /**<   Default voice subscription. Values: \n
      - NAS_PRIMARY_SUBSCRIPTION (0x00) --  Primary subscription \n 
      - NAS_SECONDARY_SUBSCRIPTION (0x01) --  Secondary subscription \n 
      - NAS_TERTIARY_SUBSCRIPTION (0x02) --  Tertiary subscription 

 \vspace{3pt}
 All other values are reserved.
 */

  /* Optional */
  /*  Active Subs Mask */
  uint8_t active_subs_mask_valid;  /**< Must be set to true if active_subs_mask is being passed */
  nas_active_subs_mask_type_v01 active_subs_mask;
  /**<   Bitmask representing the active subscriptions to be set. If a value 
       of 0 is sent, there are no active subscriptions.
       Values: \n
       - Bit 0 (0x01) -- QMI_NAS_ACTIVE_SUB_ PRIMARY   -- Primary subscription \n
       - Bit 1 (0x02) -- QMI_NAS_ACTIVE_SUB_ SECONDARY -- Secondary subscription \n
       - Bit 2 (0x04) -- QMI_NAS_ACTIVE_SUB_ TERTIARY  -- Tertiary subscription

       \vspace{3pt}
       All unlisted bits are reserved for future use and the service point
       ignores them if used.
  */

  /* Optional */
  /*  DDS Switch Cause */
  uint8_t dds_duration_valid;  /**< Must be set to true if dds_duration is being passed */
  nas_dds_duration_enum_v01 dds_duration;
  /**<    This TLV is no longer supported in this interface. \n
        If this TLV is provided, an error is returned in the response.
  */
}nas_set_dual_standby_pref_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Configures dual standby preference. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_dual_standby_pref_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Standby preference */
  nas_standby_pref_enum_v01 standby_pref;
  /**<   Values: \n
       -0x01 -- Single standby \n
       -0x02 -- Dual standby with tune away \n
       -0x04 -- Dual standby without tune away \n
       -0x05 -- Automatic mode with tune away where applicable \n
       -0x06 -- Automatic mode without tune away \n
       -0x07 -- Triple standby

       \vspace{3pt}
       All other values are reserved.
  */

  /*  Priority subs */
  nas_subs_type_enum_v01 priority_subs;
  /**<   Subscription to give priority when listening to the paging channel during
 dual standby. Values: \n
      - NAS_PRIMARY_SUBSCRIPTION (0x00) --  Primary subscription \n 
      - NAS_SECONDARY_SUBSCRIPTION (0x01) --  Secondary subscription \n 
      - NAS_TERTIARY_SUBSCRIPTION (0x02) --  Tertiary subscription 

 \vspace{3pt}
 All other values are reserved.
 */

  /*  Active subs */
  nas_subs_type_enum_v01 active_subs;
  /**<   Subscription to enable when "standby_pref is 0x01 -- Single standby". 
 Values: \n
      - NAS_PRIMARY_SUBSCRIPTION (0x00) --  Primary subscription \n 
      - NAS_SECONDARY_SUBSCRIPTION (0x01) --  Secondary subscription \n 
      - NAS_TERTIARY_SUBSCRIPTION (0x02) --  Tertiary subscription 

 \vspace{3pt}
 All other values are reserved.
 */

  /*  Default data subs (Deprecated; use QMI DSD service to determine default data subscription) */
  nas_subs_type_enum_v01 default_data_subs;
  /**<   Default data subscription. Values: \n
      - NAS_PRIMARY_SUBSCRIPTION (0x00) --  Primary subscription \n 
      - NAS_SECONDARY_SUBSCRIPTION (0x01) --  Secondary subscription \n 
      - NAS_TERTIARY_SUBSCRIPTION (0x02) --  Tertiary subscription 

 \vspace{3pt}
 All other values are reserved.
 */
}nas_standby_pref_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Informs the control point of any changes in dual standby
             subscription. */
typedef struct {

  /* Optional */
  /*  Standby Preference */
  uint8_t standby_pref_valid;  /**< Must be set to true if standby_pref is being passed */
  nas_standby_pref_type_v01 standby_pref;

  /* Optional */
  /*  Default Voice Subs */
  uint8_t default_voice_subs_valid;  /**< Must be set to true if default_voice_subs is being passed */
  nas_subs_type_enum_v01 default_voice_subs;
  /**<   Default voice subscription. Values: \n
      - NAS_PRIMARY_SUBSCRIPTION (0x00) --  Primary subscription \n 
      - NAS_SECONDARY_SUBSCRIPTION (0x01) --  Secondary subscription \n 
      - NAS_TERTIARY_SUBSCRIPTION (0x02) --  Tertiary subscription 

 \vspace{3pt}
 All other values are reserved.
 */

  /* Optional */
  /*  Active Subs Mask */
  uint8_t active_subs_mask_valid;  /**< Must be set to true if active_subs_mask is being passed */
  nas_active_subs_mask_type_v01 active_subs_mask;
  /**<   Bitmask representing the active subscriptions in the device. If a value 
       of 0 is sent, there are no active subscriptions.
       Values: \n
       - Bit 0 (0x01) -- QMI_NAS_ACTIVE_SUB_ PRIMARY   -- Primary subscription \n
       - Bit 1 (0x02) -- QMI_NAS_ACTIVE_SUB_ SECONDARY -- Secondary subscription \n
       - Bit 2 (0x04) -- QMI_NAS_ACTIVE_SUB_ TERTIARY  -- Tertiary subscription

       \vspace{3pt}
       All unlisted bits are reserved for future use and the service point
       ignores them if used.
  */
}nas_dual_standby_pref_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_IS_PRIORITY_SUBS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_PRIORITY_SUBSCRIPTION_FALSE_V01 = 0x00, 
  NAS_PRIORITY_SUBSCRIPTION_TRUE_V01 = 0x01, 
  NAS_IS_PRIORITY_SUBS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_is_priority_subs_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_ACTIVE_SUBS_INFO_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_SUBSCRIPTION_NOT_ACTIVE_V01 = 0x00, 
  NAS_SUBSCRIPTION_ACTIVE_V01 = 0x01, 
  NAS_ACTIVE_SUBS_INFO_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_active_subs_info_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_DDS_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_DDS_TYPE_PERMANENT_V01 = 0x00, 
  NAS_DDS_TYPE_TEMPORARY_V01 = 0x01, 
  NAS_DDS_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_dds_type_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates any change in the subscription information. */
typedef struct {

  /* Optional */
  /*  Priority Subscription Info */
  uint8_t is_priority_subs_valid;  /**< Must be set to true if is_priority_subs is being passed */
  nas_is_priority_subs_enum_v01 is_priority_subs;
  /**<  
      Information on whether the subscription is a priority subscription 
      in cases of dual standby. Values: \n
      -0x00 -- Not a priority subscription \n
      -0x01 -- Priority subscription
 */

  /* Optional */
  /*  Active Subscription Info */
  uint8_t is_active_valid;  /**< Must be set to true if is_active is being passed */
  nas_active_subs_info_enum_v01 is_active;
  /**<  
      Information on whether the subscription is active. Values: \n
      -0x00 -- Not active \n
      -0x01 -- Active
 */

  /* Optional */
  /*  Default Data Subscription Info (Deprecated; use QMI DSD service to determine default data subscription) */
  uint8_t is_default_data_subs_valid;  /**< Must be set to true if is_default_data_subs is being passed */
  uint8_t is_default_data_subs;
  /**<  
      Information on whether the subscription is the default data
      subscription in cases of dual standby. Values: \n
      -0x00 -- FALSE; not a default data subscription \n
      -0x01 -- TRUE; default data subscription
 */

  /* Optional */
  /*  Voice System ID */
  uint8_t voice_system_id_valid;  /**< Must be set to true if voice_system_id is being passed */
  uint32_t voice_system_id;
  /**<   Voice system ID.
 */

  /* Optional */
  /*  LTE Voice System ID */
  uint8_t lte_voice_system_id_valid;  /**< Must be set to true if lte_voice_system_id is being passed */
  uint32_t lte_voice_system_id;
  /**<   LTE voice system ID.
 */

  /* Optional */
  /*  WLAN Voice System ID */
  uint8_t wlan_voice_system_id_valid;  /**< Must be set to true if wlan_voice_system_id is being passed */
  uint32_t wlan_voice_system_id;
  /**<   WLAN voice system ID.
 */

  /* Optional */
  /*  Default Data Subscription Type (Deprecated; use QMI DSD service to determine DDS type) */
  uint8_t dds_type_valid;  /**< Must be set to true if dds_type is being passed */
  nas_dds_type_enum_v01 dds_type;
  /**<   This TLV is only sent when is_default_data_subs is set to TRUE.
 */

  /* Optional */
  /*  NR5G Voice System ID */
  uint8_t nr5g_voice_system_id_valid;  /**< Must be set to true if nr5g_voice_system_id is being passed */
  uint32_t nr5g_voice_system_id;
  /**<   NR5G voice system ID.
 */
}nas_subscription_info_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the mode preference. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_mode_pref_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the mode preference. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  Mode Preference for idx0 */
  uint8_t idx0_mode_pref_valid;  /**< Must be set to true if idx0_mode_pref is being passed */
  mode_pref_mask_type_v01 idx0_mode_pref;
  /**<   Bitmask representing the radio technology mode preference set in
      NV (idx0). Values: \n
       - Bit 0 (0x01) -- QMI_NAS_RAT_MODE_PREF_ CDMA2000_1X    -- 
         cdma2000\textsuperscript{\textregistered} 1X             \n
       - Bit 1 (0x02) -- QMI_NAS_RAT_MODE_PREF_ CDMA2000_HRPD  -- 
         cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
       - Bit 2 (0x04) -- QMI_NAS_RAT_MODE_PREF_ GSM            -- GSM \n
       - Bit 3 (0x08) -- QMI_NAS_RAT_MODE_PREF_ UMTS           -- UMTS \n
       - Bit 4 (0x10) -- QMI_NAS_RAT_MODE_PREF_ LTE            -- LTE \n
       - Bit 5 (0x20) -- QMI_NAS_RAT_MODE_PREF_ TDSCDMA        -- TD-SCDMA \n
       - Bit 6 (0x40) -- QMI_NAS_RAT_MODE_PREF_ NR5G           -- NR5G	   
  */

  /* Optional */
  /*  Mode Preference for idx1 */
  uint8_t idx1_mode_pref_valid;  /**< Must be set to true if idx1_mode_pref is being passed */
  mode_pref_mask_type_v01 idx1_mode_pref;
  /**<   Bitmask representing the radio technology mode preference set in 
      NV (idx1). Values: \n
       - Bit 0 (0x01) -- QMI_NAS_RAT_MODE_PREF_ CDMA2000_1X    -- 
         cdma2000\textsuperscript{\textregistered} 1X             \n
       - Bit 1 (0x02) -- QMI_NAS_RAT_MODE_PREF_ CDMA2000_HRPD  -- 
         cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
       - Bit 2 (0x04) -- QMI_NAS_RAT_MODE_PREF_ GSM            -- GSM \n
       - Bit 3 (0x08) -- QMI_NAS_RAT_MODE_PREF_ UMTS           -- UMTS \n
       - Bit 4 (0x10) -- QMI_NAS_RAT_MODE_PREF_ LTE            -- LTE \n
       - Bit 5 (0x20) -- QMI_NAS_RAT_MODE_PREF_ TDSCDMA        -- TD-SCDMA \n
       - Bit 6 (0x40) -- QMI_NAS_RAT_MODE_PREF_ NR5G           -- NR5G	   
 */

  /* Optional */
  /*  Mode Preference for idx2 */
  uint8_t idx2_mode_pref_valid;  /**< Must be set to true if idx2_mode_pref is being passed */
  mode_pref_mask_type_v01 idx2_mode_pref;
  /**<   Bitmask representing the radio technology mode preference set in 
      NV (idx2). Values: \n
       - Bit 0 (0x01) -- QMI_NAS_RAT_MODE_PREF_ CDMA2000_1X    -- 
         cdma2000\textsuperscript{\textregistered} 1X             \n
       - Bit 1 (0x02) -- QMI_NAS_RAT_MODE_PREF_ CDMA2000_HRPD  -- 
         cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
       - Bit 2 (0x04) -- QMI_NAS_RAT_MODE_PREF_ GSM            -- GSM \n
       - Bit 3 (0x08) -- QMI_NAS_RAT_MODE_PREF_ UMTS           -- UMTS \n
       - Bit 4 (0x10) -- QMI_NAS_RAT_MODE_PREF_ LTE            -- LTE \n
       - Bit 5 (0x20) -- QMI_NAS_RAT_MODE_PREF_ TDSCDMA        -- TD-SCDMA
 */
}nas_get_mode_pref_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_ACTIVE_TECHNOLOGY_DURATION_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_ACTIVE_TECHNOLOGY_DURATION_PERMANENT_V01 = 0x00, 
  NAS_ACTIVE_TECHNOLOGY_DURATION_PWR_CYCLE_V01 = 0x01, 
  NAS_ACTIVE_TECHNOLOGY_DURATION_1C_ENC_PC_V01 = 0x02, 
  NAS_ACTIVE_TECHNOLOGY_DURATION_1C_TUENC_ST_PC_V01 = 0x03, 
  NAS_ACTIVE_TECHNOLOGY_DURATION_1C_TUENC_INTERNAL1_V01 = 0x04, 
  NAS_ACTIVE_TECHNOLOGY_DURATION_1C_TUENC_INTERNAL2_V01 = 0x05, 
  NAS_ACTIVE_TECHNOLOGY_DURATION_1C_TUENC_INTERNAL3_V01 = 0x06, 
  NAS_ACTIVE_TECHNOLOGY_DURATION_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_active_technology_duration_enum_type_v01;
/**
    @}
  */

typedef uint16_t nas_persistent_technology_pref_mask_type_v01;
#define NAS_PERSISTENT_TECH_PREF_3GPP2_V01 ((nas_persistent_technology_pref_mask_type_v01)0x01) 
#define NAS_PERSISTENT_TECH_PREF_3GPP_V01 ((nas_persistent_technology_pref_mask_type_v01)0x02) 
#define NAS_PERSISTENT_TECH_PREF_ANALOG_V01 ((nas_persistent_technology_pref_mask_type_v01)0x04) 
#define NAS_PERSISTENT_TECH_PREF_DIGITAL_V01 ((nas_persistent_technology_pref_mask_type_v01)0x08) 
#define NAS_PERSISTENT_TECH_PREF_HDR_V01 ((nas_persistent_technology_pref_mask_type_v01)0x10) 
#define NAS_PERSISTENT_TECH_PREF_LTE_V01 ((nas_persistent_technology_pref_mask_type_v01)0x20) 
/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Technology preference */
  nas_persistent_technology_pref_mask_type_v01 technology_pref;
  /**<  
        Bitmask representing the radio technology preference set. 
        No bits set indicates to the device to automatically
        determine the technology to use. Values: \n
        - Bit 0 -- Technology is 3GPP2 \n
        - Bit 1 -- Technology is 3GPP

        Any combination of the following may be returned: \n
        - Bit 2 -- Analog -- AMPS if 3GPP2, GSM if 3GPP \n
        - Bit 3 -- Digital -- CDMA if 3GPP2, WCDMA if 3GPP \n
        - Bit 4 -- HDR \n
        - Bit 5 -- LTE \n
        - Bits 6 to 15 -- Reserved

        Note: Bits 0 and 1 are exclusive; only one may be set at a time.
              All unlisted bits are reserved for future use and are ignored.
  */

  /*  Duration */
  nas_active_technology_duration_enum_type_v01 duration;
  /**<  
      Preference duration. Values: \n
      -0x00 -- Permanent   -- Preference is used permanently \n
      -0x01 -- Power cycle -- Preference is used until the next device power cycle
  */
}nas_technology_pref_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets the technology preference. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Technology Preference */
  nas_technology_pref_type_v01 technology_pref;
}nas_set_technology_preference_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets the technology preference. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_technology_preference_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the technology preference. (Deprecated) */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_technology_preference_req_type_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Technology preference */
  nas_persistent_technology_pref_mask_type_v01 technology_pref;
  /**<  
        Bitmask representing the radio technology preference set. 
        No bits set indicates to the device to automatically
        determine the technology to use. Values: \n
        - Bit 0 -- Technology is 3GPP2 \n
        - Bit 1 -- Technology is 3GPP

        Any combination of the following may be returned: \n
        - Bit 2 -- Analog -- AMPS if 3GPP2, GSM if 3GPP \n
        - Bit 3 -- Digital -- CDMA if 3GPP2, WCDMA if 3GPP \n
        - Bit 4 -- HDR \n
        - Bit 5 -- LTE \n
        - Bits 6 to 15 -- Reserved

        Note: Bits 0 and 1 are exclusive; only one may be set at a time.
              All unlisted bits are reserved for future use and are ignored.
  */

  /*  Duration */
  nas_active_technology_duration_enum_type_v01 duration;
  /**<  
      Duration of the active preference. Values: \n
      -0x00 -- Permanent -- Preference is used permanently \n
      -0x01 -- Power cycle -- Preference is used until the next device power cycle \n
      -0x02 -- 1 call -- Until the end of the next call or a power cycle \n
      -0x03 -- 1 call or time -- Until the end of the next call, a specified time, 
                                 or a power cycle \n
      -0x04-0x06 -- Internal 1 call -- Until the end of the next call 

  */
}nas_active_technology_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the technology preference. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Mandatory */
  /*  Active Technology Preference */
  nas_active_technology_type_v01 active_technology_pref;

  /* Optional */
  /*  Persistent Technology Preference */
  uint8_t persistent_technology_pref_valid;  /**< Must be set to true if persistent_technology_pref is being passed */
  nas_persistent_technology_pref_mask_type_v01 persistent_technology_pref;
  /**<    Bitmask representing the radio technology preference set. 
        No bits set indicates to the device to automatically
        determine the technology to use. Values: \n
        - Bit 0 -- Technology is 3GPP2 \n
        - Bit 1 -- Technology is 3GPP

        Any combination of the following may be returned: \n
        - Bit 2 -- Analog -- AMPS if 3GPP2, GSM if 3GPP \n
        - Bit 3 -- Digital -- CDMA if 3GPP2, WCDMA if 3GPP \n
        - Bit 4 -- HDR \n
        - Bit 5 -- LTE \n
        - Bits 6 to 15 -- Reserved

        Note: Bits 0 and 1 are exclusive; only one may be set at a time.
              All unlisted bits are reserved for future use and are ignored.       
    */
}nas_get_technology_preference_resp_type_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the network system preference. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_network_system_preference_req_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NETWORK_SYS_PREF_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_NETWORK_SYSTEM_PREFERENCE_AUTOMATIC_V01 = 0x00, 
  NAS_NETWORK_SYSTEM_PREFERENCE_AUTO_A_V01 = 0x01, 
  NAS_NETWORK_SYSTEM_PREFERENCE_AUTO_B_V01 = 0x02, 
  NETWORK_SYS_PREF_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}network_sys_pref_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the network system preference. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Mandatory */
  /*  System Preference */
  network_sys_pref_enum_type_v01 system_pref;
  /**<  
      Duration of the active preference. Values: \n
      -0x00 -- Automatic \n
      -0x01 -- Auto A \n
      -0x02 -- Auto B
  */
}nas_get_network_system_preference_resp_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Year */
  uint16_t year;
  /**<   Year.
  */

  /*  Month */
  uint8_t month;
  /**<   Month. 1 is January and 12 is December.
  */

  /*  Day */
  uint8_t day;
  /**<   Day. Range: 1 to 31.
  */

  /*  Hour */
  uint8_t hour;
  /**<   Hour. Range: 0 to 23.
  */

  /*  Minute */
  uint8_t minute;
  /**<   Minute. Range: 0 to 59.
  */

  /*  Second */
  uint8_t second;
  /**<   Second. Range: 0 to 59.
  */

  /*  Day of the week */
  uint8_t day_of_week;
  /**<   Day of the week. 0 is Monday and 6 is Sunday.
  */
}nas_julian_time_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates a time change reported by the network. */
typedef struct {

  /* Mandatory */
  /*  Universal Time */
  nas_julian_time_type_v01 universal_time;

  /* Optional */
  /*  Time Zone */
  uint8_t time_zone_valid;  /**< Must be set to true if time_zone is being passed */
  int8_t time_zone;
  /**<   Offset from Universal time, i.e., the difference between local time
       and Universal time, in increments of 15 min (signed value).
  */

  /* Optional */
  /*  Daylight Saving Adjustment */
  uint8_t daylt_sav_adj_valid;  /**< Must be set to true if daylt_sav_adj is being passed */
  uint8_t daylt_sav_adj;
  /**<   Daylight saving adjustment in hours. Possible values: 0, 1, and 2. This 
       TLV is ignored if radio_if is NAS_RADIO_IF_CDMA_1XEVDO.
  */

  /* Optional */
  /*  Radio Interface */
  uint8_t radio_if_valid;  /**< Must be set to true if radio_if is being passed */
  nas_radio_if_enum_v01 radio_if;
  /**<  
    Radio interface from which to get the information. Values: \n
    - 0x01 -- NAS_RADIO_IF_CDMA_1X     -- 
      cdma2000\textsuperscript{\textregistered} 1X             \n
    - 0x02 -- NAS_RADIO_IF_CDMA_1XEVDO -- 
      cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
    - 0x04 -- NAS_RADIO_IF_GSM         -- GSM \n
    - 0x05 -- NAS_RADIO_IF_UMTS        -- UMTS \n
    - 0x08 -- NAS_RADIO_IF_LTE         -- LTE \n
    - 0x09 -- NAS_RADIO_IF_TDSCDMA     -- TD-SCDMA \n
    - 0x0C -- NAS_RADIO_IF_NR5G        -- NR5G
  */
}nas_network_time_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Provides the system information.
               \label{idl:getSysInfo} */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_sys_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_CUR_IDLE_DIGITAL_MODE_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_SYS_MODE_NO_SRV_V01 = 0x00, 
  NAS_SYS_MODE_AMPS_V01 = 0x01, 
  NAS_SYS_MODE_CDMA_V01 = 0x02, 
  NAS_SYS_MODE_GSM_V01 = 0x03, 
  NAS_SYS_MODE_HDR_V01 = 0x04, 
  NAS_SYS_MODE_WCDMA_V01 = 0x05, 
  NAS_SYS_MODE_GPS_V01 = 0x06, 
  NAS_SYS_MODE_GW_V01 = 0x07, 
  NAS_SYS_MODE_WLAN_V01 = 0x08, 
  NAS_SYS_MODE_LTE_V01 = 0x09, 
  NAS_SYS_MODE_GWL_V01 = 0x0A, 
  NAS_CUR_IDLE_DIGITAL_MODE_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_cur_idle_digital_mode_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_SERVICE_STATUS_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_SYS_SRV_STATUS_NO_SRV_V01 = 0, 
  NAS_SYS_SRV_STATUS_LIMITED_V01 = 1, 
  NAS_SYS_SRV_STATUS_SRV_V01 = 2, 
  NAS_SYS_SRV_STATUS_LIMITED_REGIONAL_V01 = 3, 
  NAS_SYS_SRV_STATUS_PWR_SAVE_V01 = 4, 
  NAS_SERVICE_STATUS_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_service_status_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_TRUE_SERVICE_STATUS_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  SYS_SRV_STATUS_NO_SRV_V01 = 0, 
  SYS_SRV_STATUS_LIMITED_V01 = 1, 
  SYS_SRV_STATUS_SRV_V01 = 2, 
  SYS_SRV_STATUS_LIMITED_REGIONAL_V01 = 3, 
  SYS_SRV_STATUS_PWR_SAVE_V01 = 4, 
  NAS_TRUE_SERVICE_STATUS_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_true_service_status_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_SERVICE_DOMAIN_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  SYS_SRV_DOMAIN_NO_SRV_V01 = 0, 
  SYS_SRV_DOMAIN_CS_ONLY_V01 = 1, 
  SYS_SRV_DOMAIN_PS_ONLY_V01 = 2, 
  SYS_SRV_DOMAIN_CS_PS_V01 = 3, 
  SYS_SRV_DOMAIN_CAMPED_V01 = 4, 
  NAS_SERVICE_DOMAIN_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_service_domain_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_HDR_PERSONALITY_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_SYS_PERSONALITY_NONE_V01 = 0x00, 
  NAS_SYS_PERSONALITY_HRPD_V01 = 0x02, 
  NAS_SYS_PERSONALITY_EHRPD_V01 = 0x03, 
  NAS_HDR_PERSONALITY_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_hdr_personality_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_HDR_ACTIVE_PROT_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_SYS_ACTIVE_PROT_NONE_V01 = 0x00, 
  NAS_SYS_ACTIVE_PROT_HDR_REL0_V01 = 0x02, 
  NAS_SYS_ACTIVE_PROT_HDR_RELA_V01 = 0x03, 
  NAS_SYS_ACTIVE_PROT_HDR_RELB_V01 = 0x04, 
  NAS_HDR_ACTIVE_PROT_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_hdr_active_prot_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_ROAM_STATUS_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_SYS_ROAM_STATUS_OFF_V01 = 0x00, 
  NAS_SYS_ROAM_STATUS_ON_V01 = 0x01, 
  NAS_SYS_ROAM_STATUS_BLINK_V01 = 0x02, 
  NAS_SYS_ROAM_STATUS_OUT_OF_NEIGHBORHOOD_V01 = 0x03, 
  NAS_SYS_ROAM_STATUS_OUT_OF_BLDG_V01 = 0x04, 
  NAS_SYS_ROAM_STATUS_PREF_SYS_V01 = 0x05, 
  NAS_SYS_ROAM_STATUS_AVAIL_SYS_V01 = 0x06, 
  NAS_SYS_ROAM_STATUS_ALLIANCE_PARTNER_V01 = 0x07, 
  NAS_SYS_ROAM_STATUS_PREMIUM_PARTNER_V01 = 0x08, 
  NAS_SYS_ROAM_STATUS_FULL_SVC_V01 = 0x09, 
  NAS_SYS_ROAM_STATUS_PARTIAL_SVC_V01 = 0x0A, 
  NAS_SYS_ROAM_STATUS_BANNER_ON_V01 = 0x0B, 
  NAS_SYS_ROAM_STATUS_BANNER_OFF_V01 = 0x0C, 
  NAS_ROAM_STATUS_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_roam_status_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_EUTRA_CELL_STATUS_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_EUTRA_CELL_PRESENT_V01 = 0x00, 
  NAS_EUTRA_CELL_NOT_PRESENT_V01 = 0x01, 
  NAS_EUTRA_CELL_PRESENCE_UNKNOWN_V01 = 0x02, 
  NAS_EUTRA_CELL_DETECTION_UNSUPPORTED_V01 = 0x03, 
  NAS_EUTRA_CELL_STATUS_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_eutra_cell_status_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Service Domain */
  nas_service_domain_enum_type_v01 reject_srv_domain;
  /**<  
      Type of service domain in which the registration is rejected. Values: \n
      - 0x00 -- SYS_SRV_DOMAIN_NO_SRV  -- No service \n
      - 0x01 -- SYS_SRV_DOMAIN_CS_ONLY -- Circuit-switched only \n
      - 0x02 -- SYS_SRV_DOMAIN_PS_ONLY -- Packet-switched only \n
      - 0x03 -- SYS_SRV_DOMAIN_CS_PS   -- Circuit-switched and packet-switched \n
      - 0x04 -- SYS_SRV_DOMAIN_CAMPED  -- Camped
      */

  /*  Registration Rejection Cause */
  uint8_t rej_cause;
  /**<  
      Reject cause values sent are specified in 
      \hyperref[STD-24008]{3GPP TS 24.008} Sections 10.5.3.6 and 10.5.5.14, and 
      \hyperref[STD-24301]{3GPP TS 24.301} Section 9.9.3.9.
  */
}nas_reg_reject_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Service Status of the System */
  nas_service_status_enum_type_v01 srv_status;
  /**<   
       Service status of the system. Values: \n
       - 0x00 -- SYS_SRV_STATUS_NO_SRV  -- No service \n
       - 0x01 -- SYS_SRV_STATUS_LIMITED -- Limited service \n
       - 0x02 -- SYS_SRV_STATUS_SRV     -- Service \n
       - 0x03 -- SYS_SRV_STATUS_LIMITED_ REGIONAL -- Limited regional service \n
       - 0x04 -- SYS_SRV_STATUS_PWR_SAVE          -- Power save
  */

  /*  Is this RAT the preferred data path */
  uint8_t is_pref_data_path;
  /**<  
       Whether the RAT is the preferred data path: \n
       - 0x00 -- Not preferred \n
       - 0x01 -- Preferred
  */
}nas_3gpp2_srv_status_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Service Status of the System */
  nas_service_status_enum_type_v01 srv_status;
  /**<   
       Service status of the system. Values: \n
       - 0x00 -- SYS_SRV_STATUS_NO_SRV  -- No service \n
       - 0x01 -- SYS_SRV_STATUS_LIMITED -- Limited service \n
       - 0x02 -- SYS_SRV_STATUS_SRV     -- Service \n
       - 0x03 -- SYS_SRV_STATUS_LIMITED_ REGIONAL -- Limited regional service \n
       - 0x04 -- SYS_SRV_STATUS_PWR_SAVE          -- Power save
  */

  /*  True Service Status of the System (not applicable to CDMA/HDR) */
  nas_true_service_status_enum_type_v01 true_srv_status;
  /**<  
      True service status of the system (not applicable to CDMA/HDR). Values: \n
      - 0x00 -- SYS_SRV_STATUS_NO_SRV  -- No service \n
      - 0x01 -- SYS_SRV_STATUS_LIMITED -- Limited service \n
      - 0x02 -- SYS_SRV_STATUS_SRV     -- Service \n
      - 0x03 -- SYS_SRV_STATUS_LIMITED_ REGIONAL -- Limited regional service \n
      - 0x04 -- SYS_SRV_STATUS_PWR_SAVE          -- Power save
  */

  /*  Is this RAT the Preferred Data Path */
  uint8_t is_pref_data_path;
  /**<  
       Whether the RAT is the preferred data path(not applicable to NR5G): \n
       - 0x00 -- Not preferred \n
       - 0x01 -- Preferred
    */
}nas_3gpp_srv_status_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_CELL_BROADCAST_CAP_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_CELL_BROADCAST_CAP_UNKNOWN_V01 = 0x00, /**<  CB capability information not known.  */
  NAS_CELL_BROADCAST_CAP_OFF_V01 = 0x01, /**<  CB capability OFF     */
  NAS_CELL_BROADCAST_CAP_ON_V01 = 0x02, /**<  CB capability ON     */
  NAS_CELL_BROADCAST_CAP_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_cell_broadcast_cap_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  MCC */
  char mcc[NAS_MCC_MNC_MAX_V01];
  /**<  
      MCC digits in ASCII characters. 

      For CDMA, the MCC wildcard value is returned as \{`3', 0xFF, 0xFF\}.
  */

  /*  MNC */
  char mnc[NAS_MCC_MNC_MAX_V01];
  /**<  
      MNC digits in ASCII characters. For this field: \n
      - Unused byte is set to 0xFF   \n
      - In the case of two-digit MNC values, the third (unused) digit 
        is set to 0xFF. For example, 15 (a two-digit MNC) is reported 
        using the byte stream 0x35 0x31 0xFF.

      For CDMA, the MNC wildcard value is returned as \{`7', 0xFF, 0xFF\}. 
  */
}nas_common_network_id_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Is the Service Domain Valid */
  uint8_t srv_domain_valid;
  /**<   
      Indicates whether the service domain is valid.
  */

  /*  Service Domain */
  nas_service_domain_enum_type_v01 srv_domain;
  /**<  
      Service domain registered on the system. Values:  \n
      - 0x00 -- SYS_SRV_DOMAIN_NO_SRV  -- No service \n
      - 0x01 -- SYS_SRV_DOMAIN_CS_ONLY -- Circuit-switched only \n
      - 0x02 -- SYS_SRV_DOMAIN_PS_ONLY -- Packet-switched only \n
      - 0x03 -- SYS_SRV_DOMAIN_CS_PS   -- Circuit-switched and packet-switched \n
      - 0x04 -- SYS_SRV_DOMAIN_CAMPED  -- Camped
      */

  /*  Is the Service Capability Valid */
  uint8_t srv_capability_valid;
  /**<   
      Indicates whether the service capability is valid. 
  */

  /*  Service Capability */
  nas_service_domain_enum_type_v01 srv_capability;
  /**<  
      Current system's service capability. Values: \n
      - 0x00 -- SYS_SRV_DOMAIN_NO_SRV  -- No service \n
      - 0x01 -- SYS_SRV_DOMAIN_CS_ONLY -- Circuit-switched only \n
      - 0x02 -- SYS_SRV_DOMAIN_PS_ONLY -- Packet-switched only \n
      - 0x03 -- SYS_SRV_DOMAIN_CS_PS   -- Circuit-switched and packet-switched \n
      - 0x04 -- SYS_SRV_DOMAIN_CAMPED  -- Camped
        */

  /*  Is the Roaming Status Valid */
  uint8_t roam_status_valid;
  /**<   
      Indicates whether the roaming status is valid. 
  */

  /*  Current Roaming Status */
  nas_roam_status_enum_type_v01 roam_status;
  /**<  
      Current roaming status. Values: \n
      - 0x00 -- SYS_ROAM_STATUS_OFF   -- Off \n
      - 0x01 -- SYS_ROAM_STATUS_ON    -- On  \n
      - 0x02 -- SYS_ROAM_STATUS_BLINK -- Blinking \n
      - 0x03 -- SYS_ROAM_STATUS_OUT_OF_ NEIGHBORHOOD -- Out of the neighborhood \n
      - 0x04 -- SYS_ROAM_STATUS_OUT_OF_BLDG          -- Out of the building \n
      - 0x05 -- SYS_ROAM_STATUS_PREF_SYS          -- Preferred system \n
      - 0x06 -- SYS_ROAM_STATUS_AVAIL_SYS         -- Available system \n
      - 0x07 -- SYS_ROAM_STATUS_ALLIANCE_ PARTNER -- Alliance partner \n
      - 0x08 -- SYS_ROAM_STATUS_PREMIUM_ PARTNER  -- Premium partner \n
      - 0x09 -- SYS_ROAM_STATUS_FULL_SVC          -- Full service \n
      - 0x0A -- SYS_ROAM_STATUS_PARTIAL_SVC       -- Partial service \n
      - 0x0B -- SYS_ROAM_STATUS_BANNER_ON         -- Banner is on \n
      - 0x0C -- SYS_ROAM_STATUS_BANNER_OFF        -- Banner is off \n
        Remainder of the values are per \hyperref[STD-CR1001F]{3GPP2 C.R1001-F}.

        Values from 0x02 onward are only applicable for 3GPP2.
  */

  /*  Is the Forbidden System Valid */
  uint8_t is_sys_forbidden_valid;
  /**<   
      Indicates whether the forbidden system is valid. 
  */

  /*  Indicates Whether the System is Forbidden */
  uint8_t is_sys_forbidden;
  /**<   
      Whether the system is forbidden(Not applicable for NR5G): \n
      - 0x00 -- Not forbidden \n
      - 0x01 -- Forbidden
  */
}nas_common_sys_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Is the P_Rev in Use Valid */
  uint8_t p_rev_in_use_valid;
  /**<   
      Indicates whether the P_Rev in use is valid. 
  */

  /*  P_Rev in Use */
  uint8_t p_rev_in_use;
  /**<  
     The lesser of the base station P_Rev and mobile P_Rev 
     (only applicable for CDMA).
  */

  /*  Is the Base Station P_Rev Valid */
  uint8_t bs_p_rev_valid;
  /**<   
      Indicates whether the base station P_Rev is valid. 
  */

  /*  bs_p_rev  */
  uint8_t bs_p_rev;
  /**<  
    Base station P_Rev (only applicable for CDMA).
  */

  /*  Is the Supported CCS Valid */
  uint8_t ccs_supported_valid;
  /**<   
      Indicates whether the supported concurrent service is valid. 
  */

  /*  Is CCS Supported  */
  uint8_t ccs_supported;
  /**<  
      Whether concurrent service is supported (only applicable for CDMA): \n
      - 0x00 -- Not supported \n
      - 0x01 -- Supported

  */

  /*  Is the CDMA System ID Valid */
  uint8_t cdma_sys_id_valid;
  /**<   
      Indicates whether the CDMA system ID is valid. 
  */

  /*  CDMA System ID */
  nas_cdma_system_id_type_v01 cdma_sys_id;
  /**<  
     CDMA system ID; includes: \n
     - SID -- System ID \n
     - NID -- Network ID 
  */

  /*  Is the Base Station Information Valid */
  uint8_t bs_info_valid;
  /**<   
      Indicates whether the base station information is valid. 
  */

  /*  Base Station Information */
  nas_cdma_base_station_info_type_v01 bs_info;
  /**<  
   Base station information; includes: \n
   - Base station ID \n
   - Base station latitude \n
   - Base station longitude
  */

  /*  Is the 3GPP2 Packet Zone Valid */
  uint8_t packet_zone_valid;
  /**<   
      Indicates whether the packet zone is valid. 
  */

  /*  3GPP2 Packet Zone */
  uint16_t packet_zone;
  /**<  
    Packet zone (8-bit). 0xFFFF indicates no packet zone. 
    (Only applicable for CDMA.)
  */

  /*  Is the Network ID Valid */
  uint8_t network_id_valid;
  /**<   
      Indicates whether the network ID is valid. 
  */

  /*  Network Name */
  nas_common_network_id_type_v01 network_id;
  /**<  
    Network ID consists of MCC and MNC.
  */
}nas_cdma_only_sys_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Is the HDR Personality Valid */
  uint8_t hdr_personality_valid;
  /**<   
      Indicates whether the HDR personality is valid. 
  */

  /*  HDR Personality */
  nas_hdr_personality_enum_type_v01 hdr_personality;
  /**<  
      HDR personality information (only applicable for HDR). Values: \n
      - 0x00 -- SYS_PERSONALITY_NONE -- None \n
      - 0x02 -- SYS_PERSONALITY_HRPD -- HRPD \n
      - 0x03 -- SYS_PERSONALITY_EHRPD -- eHRPD
  */

  /*  Is the HDR Active Protocol Revision Information Valid */
  uint8_t hdr_active_prot_valid;
  /**<   
      Indicates whether the HDR active protocol revision information is valid.
  */

  /*  HDR Active Protocol Revision Information  */
  nas_hdr_active_prot_enum_type_v01 hdr_active_prot;
  /**<  
      HDR active protocol revision information (only applicable for HDR). 
      Values: \n
      - 0x00 -- SYS_ACTIVE_PROT_NONE -- None           \n
      - 0x02 -- SYS_ACTIVE_PROT_HDR_REL0 -- HDR Rel 0  \n
      - 0x03 -- SYS_ACTIVE_PROT_HDR_RELA -- HDR Rel A  \n
      - 0x04 -- SYS_ACTIVE_PROT_HDR_RELB -- HDR Rel B
  */

  /*  Is the IS-856 System ID Valid */
  uint8_t is856_sys_id_valid;
  /**<   
      Indicates whether the IS-856 system ID is valid. 
  */

  /*  IS 856 */
  uint8_t is856_sys_id[NAS_IS_856_MAX_LEN_V01];
  /**<  
      IS-856 system ID (only applicable for HDR).
    */
}nas_hdr_only_sys_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Is the EGPRS Support Valid */
  uint8_t egprs_supp_valid;
  /**<   
      Indicates whether EGPRS support is valid. 
  */

  /*  EGPRS indication  */
  uint8_t egprs_supp;
  /**<  
      EGPRS support indication (only applicable for GSM). Values: \n
      - 0x00 -- SYS_EGPRS_SUPPORT_NOT_AVAIL -- Not available \n
      - 0x01 -- SYS_EGPRS_SUPPORT_AVAIL -- Available
  */

  /*  Is the DTM Support Valid */
  uint8_t dtm_supp_valid;
  /**<   
      Indicates whether Dual Transfer mode support is valid. 
  */

  /*  DTM support status */
  uint8_t dtm_supp;
  /**<  
      Dual Transfer mode support indication (only applicable for GSM). Values: \n
      - 0x00 -- SYS_DTM_SUPPORT_NOT_AVAIL -- Not available  \n
      - 0x01 -- SYS_DTM_SUPPORT_AVAIL -- Available
  */
}nas_gsm_only_sys_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Is the HS Call Status Valid */
  uint8_t hs_call_status_valid;
  /**<   
      Indicates whether the high-speed call status is valid. 
  */

  /*  HS Call Status */
  nas_hs_support_enum_type_v01 hs_call_status;
  /**<  
      Call status on high speed (only applicable for WCDMA). Values: \n
      - 0x00 -- SYS_HS_IND_HSDPA_HSUPA_ UNSUPP_CELL    -- HSDPA and HSUPA are unsupported \n
      - 0x01 -- SYS_HS_IND_HSDPA_SUPP_CELL             -- HSDPA is supported \n
      - 0x02 -- SYS_HS_IND_HSUPA_SUPP_CELL             -- HSUPA is supported \n
      - 0x03 -- SYS_HS_IND_HSDPA_HSUPA_SUPP_ CELL      -- HSDPA and HSUPA are supported \n
      - 0x04 -- SYS_HS_IND_HSDPAPLUS_SUPP_ CELL        -- HSDPA+ is supported \n
      - 0x05 -- SYS_HS_IND_HSDPAPLUS_HSUPA_ SUPP_CELL  -- HSDPA+ and HSUPA are supported \n
      - 0x06 -- SYS_HS_IND_DC_HSDPAPLUS_SUPP_ CELL     -- Dual-cell HSDPA+ is supported \n
      - 0x07 -- SYS_HS_IND_DC_HSDPAPLUS_ HSUPA_SUPP_CELL    -- Dual-cell HSDPA+ and HSUPA are supported \n 
      - 0x08 -- SYS_HS_IND_HSDPAPLUS_64QAM_ HSUPA_SUPP_CELL -- Dual-cell HSDPA+, 64 QAM, and HSUPA are supported \n
      - 0x09 -- SYS_HS_IND_HSDPAPLUS_64QAM_ SUPP_CELL       -- Dual-cell HSDPA+ and 64 QAM are supported \n
      - 0x0A -- SYS_HS_IND_DC_HSDPAPLUS_ DC_HSUPA_SUPP_CELL -- Dual-cell HSUPA is supported
  */

  /*  Is the HS Service Indication Valid */
  uint8_t hs_ind_valid;
  /**<   
      Indicates whether the high-speed service indication is valid. 
  */

  /*   HS service indication */
  nas_hs_support_enum_type_v01 hs_ind;
  /**<  
      High-speed service indication (only applicable for WCDMA). Values: \n
      - 0x00 -- SYS_HS_IND_HSDPA_HSUPA_ UNSUPP_CELL    -- HSDPA and HSUPA are unsupported \n
      - 0x01 -- SYS_HS_IND_HSDPA_SUPP_CELL             -- HSDPA is supported \n
      - 0x02 -- SYS_HS_IND_HSUPA_SUPP_CELL             -- HSUPA is supported \n
      - 0x03 -- SYS_HS_IND_HSDPA_HSUPA_SUPP_ CELL      -- HSDPA and HSUPA are supported \n
      - 0x04 -- SYS_HS_IND_HSDPAPLUS_SUPP_ CELL        -- HSDPA+ is supported \n
      - 0x05 -- SYS_HS_IND_HSDPAPLUS_HSUPA_ SUPP_CELL  -- HSDPA+ and HSUPA are supported \n
      - 0x06 -- SYS_HS_IND_DC_HSDPAPLUS_SUPP_ CELL     -- Dual-cell HSDPA+ is supported \n
      - 0x07 -- SYS_HS_IND_DC_HSDPAPLUS_ HSUPA_SUPP_CELL    -- Dual-cell HSDPA+ and HSUPA are supported \n 
      - 0x08 -- SYS_HS_IND_HSDPAPLUS_64QAM_ HSUPA_SUPP_CELL -- Dual-cell HSDPA+, 64 QAM, and HSUPA are supported \n
      - 0x09 -- SYS_HS_IND_HSDPAPLUS_64QAM_ SUPP_CELL       -- Dual-cell HSDPA+ and 64 QAM are supported \n
      - 0x0A -- SYS_HS_IND_DC_HSDPAPLUS_ DC_HSUPA_SUPP_CELL -- Dual-cell HSUPA is supported
  */

  /*  Is the PSC Valid */
  uint8_t psc_valid;
  /**<   
      Indicates whether the primary scrambling code is valid. 
  */

  /*  Primary Scrambling Code (PSC) */
  uint16_t psc;
  /**<  
    Primary scrambling code.
    */
}nas_wcdma_only_sys_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Is the TAC Valid */
  uint8_t tac_valid;
  /**<   
      Indicates whether the tracking area code is valid. 
  */

  /*  Tracking Area Code */
  uint16_t tac;
  /**<  
     Tracking area code (only applicable for LTE).
    */
}nas_lte_only_sys_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Is the TAC Valid */
  uint8_t tac_valid;
  /**<   
      Indicates whether the tracking area code is valid. 
  */

  /*  Tracking Area Code */
  uint16_t tac;
  /**<  
     Tracking area code (Deprecated; use NR5G Tracking Area Code instead).
    */
}nas_nr5g_only_sys_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Is the System PRL Match Valid */
  uint8_t is_sys_prl_match_valid;
  /**<   
      Indicates whether the system PRL match is valid. 
  */

  /*  Indicates if the system is in PRL  */
  uint8_t is_sys_prl_match;
  /**<  
    Indicates whether the system is in a PRL (only applies to CDMA/HDR). 
    Values: \n
    - 0x00 -- System is not in a PRL \n
    - 0x01 -- System is in a PRL

    If the system is not in a PRL, roam_status carries the value from the 
    default roaming indicator in the PRL. \n
    If the system is in a PRL, roam_status is set to the value based on the 
    standard specification.
  */
}nas_cdma_hdr_only_sys_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Is the LAC Valid */
  uint8_t lac_valid;
  /**<   
      Indicates whether the location area code is valid. 
  */

  /*  Location Area Code  */
  uint16_t lac;
  /**<  
    Location area code (only applicable for 3GPP).
  */

  /*  Is the Cell ID Valid */
  uint8_t cell_id_valid;
  /**<   
      Indicates whether the cell ID is valid. 
  */

  /*  Cell ID */
  uint32_t cell_id;
  /**<  
    Cell ID.
  */

  /*  Is the Registration Reject Information Valid */
  uint8_t reg_reject_info_valid;
  /**<   
      Indicates whether the registration reject information is valid. 
  */

  /*  Registration Reject Info */
  nas_reg_reject_info_type_v01 reg_reject_info;

  /*  Is the Network ID Valid */
  uint8_t network_id_valid;
  /**<   
      Indicates whether the network ID is valid. 
  */

  /*  Network name */
  nas_common_network_id_type_v01 network_id;
  /**<  
    Network ID consists of MCC and MNC.
  */
}nas_3gpp_only_sys_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_common_sys_info_type_v01 common_sys_info;

  nas_cdma_hdr_only_sys_info_type_v01 cdma_hdr_only_sys_info;

  nas_cdma_only_sys_info_type_v01 cdma_specific_sys_info;
}nas_cdma_sys_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_common_sys_info_type_v01 common_sys_info;

  nas_cdma_hdr_only_sys_info_type_v01 cdma_hdr_only_sys_info;

  nas_hdr_only_sys_info_type_v01 hdr_specific_sys_info;
}nas_hdr_sys_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_common_sys_info_type_v01 common_sys_info;

  nas_3gpp_only_sys_info_type_v01 threegpp_specific_sys_info;

  nas_gsm_only_sys_info_type_v01 gsm_specific_sys_info;
}nas_gsm_sys_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_common_sys_info_type_v01 common_sys_info;

  nas_3gpp_only_sys_info_type_v01 threegpp_specific_sys_info;

  nas_wcdma_only_sys_info_type_v01 wcdma_specific_sys_info;
}nas_wcdma_sys_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_common_sys_info_type_v01 common_sys_info;

  nas_3gpp_only_sys_info_type_v01 threegpp_specific_sys_info;

  nas_lte_only_sys_info_type_v01 lte_specific_sys_info;
}nas_lte_sys_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_common_sys_info_type_v01 common_sys_info;

  nas_3gpp_only_sys_info_type_v01 threegpp_specific_sys_info;

  nas_nr5g_only_sys_info_type_v01 nr5g_specific_sys_info;
}nas_nr5g_sys_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t tac[NAS_NR5G_TAC_LEN_V01];
  /**<   
    NR5G Tracking area code .This field has 3 bytes.
	-tac[0] is the most significant byte
	-tac[1]
	-tac[2] is the least significant byte
  */
}nas_nr5g_tac_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Is the HS Call Status Valid */
  uint8_t hs_call_status_valid;
  /**<   
    Indicates whether the high-speed call status is valid. 
  */

  /*  HS Call Status */
  nas_hs_support_enum_type_v01 hs_call_status;
  /**<  
    Call status on high speed (only applicable for WCDMA). Values: \n
    - 0x00 -- SYS_HS_IND_HSDPA_HSUPA_ UNSUPP_CELL    -- HSDPA and HSUPA are unsupported \n
    - 0x01 -- SYS_HS_IND_HSDPA_SUPP_CELL             -- HSDPA is supported \n
    - 0x02 -- SYS_HS_IND_HSUPA_SUPP_CELL             -- HSUPA is supported \n
    - 0x03 -- SYS_HS_IND_HSDPA_HSUPA_SUPP_ CELL      -- HSDPA and HSUPA are supported \n
    - 0x04 -- SYS_HS_IND_HSDPAPLUS_SUPP_ CELL        -- HSDPA+ is supported \n
    - 0x05 -- SYS_HS_IND_HSDPAPLUS_HSUPA_ SUPP_CELL  -- HSDPA+ and HSUPA are supported \n
    - 0x06 -- SYS_HS_IND_DC_HSDPAPLUS_SUPP_ CELL     -- Dual-cell HSDPA+ is supported \n
    - 0x07 -- SYS_HS_IND_DC_HSDPAPLUS_ HSUPA_SUPP_CELL    -- Dual-cell HSDPA+ and HSUPA are supported \n 
    - 0x08 -- SYS_HS_IND_HSDPAPLUS_64QAM_ HSUPA_SUPP_CELL -- Dual-cell HSDPA+, 64 QAM, and HSUPA are supported \n
    - 0x09 -- SYS_HS_IND_HSDPAPLUS_64QAM_ SUPP_CELL       -- Dual-cell HSDPA+ and 64 QAM are supported \n
    - 0x0A -- SYS_HS_IND_DC_HSDPAPLUS_ DC_HSUPA_SUPP_CELL -- Dual-cell HSUPA is supported
  */

  /*  Is the HS Service Indication Valid */
  uint8_t hs_ind_valid;
  /**<   
    Indicates whether the high-speed service indication is valid. 
  */

  /*   HS service indication */
  nas_hs_support_enum_type_v01 hs_ind;
  /**<  
    High-speed service indication (only applicable for WCDMA). Values: \n
    - 0x00 -- SYS_HS_IND_HSDPA_HSUPA_ UNSUPP_CELL    -- HSDPA and HSUPA are unsupported \n
    - 0x01 -- SYS_HS_IND_HSDPA_SUPP_CELL             -- HSDPA is supported \n
    - 0x02 -- SYS_HS_IND_HSUPA_SUPP_CELL             -- HSUPA is supported \n
    - 0x03 -- SYS_HS_IND_HSDPA_HSUPA_SUPP_ CELL      -- HSDPA and HSUPA are supported \n
    - 0x04 -- SYS_HS_IND_HSDPAPLUS_SUPP_ CELL        -- HSDPA+ is supported \n
    - 0x05 -- SYS_HS_IND_HSDPAPLUS_HSUPA_ SUPP_CELL  -- HSDPA+ and HSUPA are supported \n
    - 0x06 -- SYS_HS_IND_DC_HSDPAPLUS_SUPP_ CELL     -- Dual-cell HSDPA+ is supported \n
    - 0x07 -- SYS_HS_IND_DC_HSDPAPLUS_ HSUPA_SUPP_CELL    -- Dual-cell HSDPA+ and HSUPA are supported \n 
    - 0x08 -- SYS_HS_IND_HSDPAPLUS_64QAM_ HSUPA_SUPP_CELL -- Dual-cell HSDPA+, 64 QAM, and HSUPA are supported \n
    - 0x09 -- SYS_HS_IND_HSDPAPLUS_64QAM_ SUPP_CELL       -- Dual-cell HSDPA+ and 64 QAM are supported \n
    - 0x0A -- SYS_HS_IND_DC_HSDPAPLUS_ DC_HSUPA_SUPP_CELL -- Dual-cell HSUPA is supported
  */

  /*  Is the Cell Parameter ID Valid */
  uint8_t cell_parameter_id_valid;
  /**<   
    Indicates whether the cell parameter ID is valid. 
  */

  /*  Cell Parameter ID */
  uint16_t cell_parameter_id;
  /**<  
    Cell parameter ID.
    */

  /*  Is the Cell Broadcast Capability Valid */
  uint8_t cell_broadcast_cap_valid;
  /**<   
    Indicates whether the cell broadcast capability is valid. 
  */

  nas_cell_broadcast_cap_enum_type_v01 cell_broadcast_cap;
  /**<  
    Cell broadcast capability of the serving system. Values: \n
    - 0x00 -- NAS_CELL_BROADCAST_CAP_ UNKNOWN  -- Cell broadcast support is unknown \n
    - 0x01 -- NAS_CELL_BROADCAST_CAP_OFF       -- Cell broadcast is not supported \n
    - 0x02 -- NAS_CELL_BROADCAST_CAP_ON        -- Cell broadcast is supported
  */

  /*  Is the CS Bar Status Valid */
  uint8_t cs_bar_status_valid;
  /**<   
    Indicates whether the circuit-switched call barring status is valid. 
  */

  nas_cell_access_status_e_type_v01 cs_bar_status;
  /**<  
    Call barring status for circuit-switched calls. Values: \n
    - 0x00 -- NAS_CELL_ACCESS_NORMAL_ONLY     -- Cell access is allowed for normal calls only \n
    - 0x01 -- NAS_CELL_ACCESS_EMERGENCY_ ONLY -- Cell access is allowed for emergency calls only \n
    - 0x02 -- NAS_CELL_ACCESS_NO_CALLS        -- Cell access is not allowed for any call type \n
    - 0x03 -- NAS_CELL_ACCESS_ALL_CALLS       -- Cell access is allowed for all call types \n
    -   -1 -- NAS_CELL_ACCESS_UNKNOWN         -- Cell access type is unknown
  */

  /*  Is the PS Bar Status Valid */
  uint8_t ps_bar_status_valid;
  /**<   
    Indicates whether the packet-switched call barring status is valid. 
  */

  nas_cell_access_status_e_type_v01 ps_bar_status;
  /**<  
     Call barring status for packet-switched calls. Values: \n
    - 0x00 -- NAS_CELL_ACCESS_NORMAL_ONLY     -- Cell access is allowed for normal calls only \n
    - 0x01 -- NAS_CELL_ACCESS_EMERGENCY_ ONLY -- Cell access is allowed for emergency calls only \n
    - 0x02 -- NAS_CELL_ACCESS_NO_CALLS        -- Cell access is not allowed for any call type \n
    - 0x03 -- NAS_CELL_ACCESS_ALL_CALLS       -- Cell access is allowed for all call types \n
    -   -1 -- NAS_CELL_ACCESS_UNKNOWN         -- Cell access type is unknown
  */

  /*  Is the Cipher Domain Valid */
  uint8_t cipher_domain_valid;
  /**<   
    Indicates whether the cipher domain is valid. 
  */

  nas_service_domain_enum_type_v01 cipher_domain;
  /**<  
    Ciphering on the service domain. Values: \n
    - 0x00 -- SYS_SRV_DOMAIN_NO_SRV  -- No service \n
    - 0x01 -- SYS_SRV_DOMAIN_CS_ONLY -- Circuit-switched only \n
    - 0x02 -- SYS_SRV_DOMAIN_PS_ONLY -- Packet-switched only \n
    - 0x03 -- SYS_SRV_DOMAIN_CS_PS   -- Circuit-switched and packet-switched
  */
}nas_tdscdma_only_sys_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_common_sys_info_type_v01 common_sys_info;

  nas_3gpp_only_sys_info_type_v01 threegpp_specific_sys_info;

  nas_tdscdma_only_sys_info_type_v01 tdscdma_specific_sys_info;
}nas_tdscdma_sys_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t geo_sys_idx;
  /**<  
    System table index referencing the beginning of the geo in which
    the current serving system is present. When the system index 
    is not known, 0xFFFF is used.
  */

  uint16_t reg_prd;
  /**<  
    Registration period after the CDMA system is acquired. 
    When the CDMA registration period is not valid, 0xFFFF is used. 
  */
}nas_cdma_sys_info2_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t geo_sys_idx;
  /**<  
    System table index referencing the beginning of the geo in which
    the current serving system is present. When the system index
    is not known, 0xFFFF is used.
  */
}nas_hdr_sys_info2_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t geo_sys_idx;
  /**<  
    System table index referencing the beginning of the geo in which
    the current serving system is present. When the system index 
    is not known, 0xFFFF is used.
  */

  nas_cell_broadcast_cap_enum_type_v01 cell_broadcast_cap;
  /**<  
    Cell broadcast capability of the serving system. Values: \n
    - 0x00 -- NAS_CELL_BROADCAST_CAP_ UNKNOWN -- Cell broadcast support is unknown \n
    - 0x01 -- NAS_CELL_BROADCAST_CAP_OFF      -- Cell broadcast is not supported \n
    - 0x02 -- NAS_CELL_BROADCAST_CAP_ON       -- Cell broadcast is supported
  */
}nas_gsm_sys_info2_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t geo_sys_idx;
  /**<  
    System table index referencing the beginning of the geo in which
    the current serving system is present. When the system index 
    is not known, 0xFFFF is used.
  */

  nas_cell_broadcast_cap_enum_type_v01 cell_broadcast_cap;
  /**<  
    Cell broadcast capability of the serving system. Values: \n
    - 0x00 -- NAS_CELL_BROADCAST_CAP_ UNKNOWN  -- Cell broadcast support is unknown \n
    - 0x01 -- NAS_CELL_BROADCAST_CAP_OFF       -- Cell broadcast is not supported \n
    - 0x02 -- NAS_CELL_BROADCAST_CAP_ON        -- Cell broadcast is supported
  */
}nas_wcdma_sys_info2_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t geo_sys_idx;
  /**<  
    System table index referencing the beginning of the geo in which
    the current serving system is present. When the system index 
    is not known, 0xFFFF is used.
  */
}nas_lte_sys_info2_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_SIM_REJ_INFO_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_SIM_NOT_AVAILABLE_V01 = 0, /**<  SIM is not available.  */
  NAS_SIM_AVAILABLE_V01 = 1, /**<  SIM is available.  */
  NAS_SIM_CS_INVALID_V01 = 2, /**<  SIM has been marked by the network as invalid for CS services.  */
  NAS_SIM_PS_INVALID_V01 = 3, /**<  SIM has been marked by the network as invalid for PS services.  */
  NAS_SIM_CS_PS_INVALID_V01 = 4, /**<  SIM has been marked by the network as invalid for CS and PS services.  */
  NAS_SIM_REJ_INFO_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_sim_rej_info_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_LTE_VOICE_STATUS_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_LTE_VOICE_STATUS_NO_VOICE_V01 = 0, /**<  Data centric devices: No voice, stay on LTE  */
  NAS_LTE_VOICE_STATUS_IMS_V01 = 1, /**<  Voice is supported over IMS network  */
  NAS_LTE_VOICE_STATUS_1X_V01 = 2, /**<  Voice is supported over 1X network  */
  NAS_LTE_VOICE_STATUS_3GPP_V01 = 3, /**<  Voice is supported over 3GPP network  */
  NAS_LTE_VOICE_STATUS_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_lte_voice_status_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_POSSIBLE_REG_DOMAIN_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_POSSIBLE_REG_DOMAIN_NA_V01 = 0, 
  NAS_POSSIBLE_REG_DOMAIN_CS_ONLY_V01 = 1, 
  NAS_POSSIBLE_REG_DOMAIN_PS_ONLY_V01 = 2, 
  NAS_POSSIBLE_REG_DOMAIN_CS_PS_V01 = 3, 
  NAS_POSSIBLE_REG_DOMAIN_LIMITED_SERVICE_V01 = 4, 
  NAS_POSSIBLE_REG_DOMAIN_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_possible_reg_domain_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_SMS_STATUS_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_SMS_STATUS_NO_SMS_V01 = 0, /**<  Data centric devices: No sms, stay on network  */
  NAS_SMS_STATUS_IMS_V01 = 1, /**<  SMS is supported over IMS network  */
  NAS_SMS_STATUS_1X_V01 = 2, /**<  SMS is supported over 1X network  */
  NAS_SMS_STATUS_3GPP_V01 = 3, /**<  SMS is supported over 3GPP network  */
  NAS_SMS_STATUS_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_sms_status_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_LTE_RRC_EMBMS_COVERAGE_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_LTE_RRC_EMBMS_COVERAGE_STATUS_NOT_AVAILABLE_V01 = 0, /**<  Not available \n  */
  NAS_LTE_RRC_EMBMS_COVERAGE_STATUS_AVAILABLE_V01 = 1, /**<  Available \n  */
  NAS_LTE_RRC_EMBMS_COVERAGE_STATUS_NOT_AVAIL_DUE_TO_UEMODE_V01 = 2, /**<  Not available due to the UE mode \n  */
  NAS_LTE_RRC_EMBMS_COVERAGE_STATUS_NOT_AVAIL_DUE_TO_EMERGENCY_V01 = 3, /**<  Not available due to an emergency \n  */
  NAS_LTE_RRC_EMBMS_COVERAGE_STATUS_UNKNOWN_V01 = 4, /**<  Unknown  */
  NAS_LTE_RRC_EMBMS_COVERAGE_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_lte_rrc_embms_coverage_status_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_NR5G_VOICE_DOMAIN_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_NR5G_VOICE_DOMAIN_NO_VOICE_V01 = 0, /**<  Data centric devices: No voice, stay on NR5G  */
  NAS_NR5G_VOICE_DOMAIN_IMS_V01 = 1, /**<  Voice is supported over IMS network  */
  NAS_NR5G_VOICE_DOMAIN_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_nr5g_voice_domain_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_NR5G_VOPS_SUPPORT_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_NR5G_IMS_VOPS_NOT_SUPPORTED_V01 = 0, /**<  IMS voice over PS session not supported  */
  NAS_NR5G_IMS_VOPS_SUPPORTED_3GPP_V01 = 1, /**<  IMS voice over PS session supported over 3GPP access  */
  NAS_NR5G_IMS_VOPS_SUPPORTED_NON_3GPP_V01 = 2, /**<  IMS voice over PS session supported over non-3GPP access */
  NAS_NR5G_VOPS_SUPPORT_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_nr5g_vops_support_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Provides the system information.
               \label{idl:getSysInfo} */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  CDMA Service Status Info */
  uint8_t cdma_srv_status_info_valid;  /**< Must be set to true if cdma_srv_status_info is being passed */
  nas_3gpp2_srv_status_info_type_v01 cdma_srv_status_info;

  /* Optional */
  /*  HDR Service Status Info */
  uint8_t hdr_srv_status_info_valid;  /**< Must be set to true if hdr_srv_status_info is being passed */
  nas_3gpp2_srv_status_info_type_v01 hdr_srv_status_info;

  /* Optional */
  /*  GSM Service Status Info */
  uint8_t gsm_srv_status_info_valid;  /**< Must be set to true if gsm_srv_status_info is being passed */
  nas_3gpp_srv_status_info_type_v01 gsm_srv_status_info;

  /* Optional */
  /*  WCDMA Service Status Info */
  uint8_t wcdma_srv_status_info_valid;  /**< Must be set to true if wcdma_srv_status_info is being passed */
  nas_3gpp_srv_status_info_type_v01 wcdma_srv_status_info;

  /* Optional */
  /*  LTE Service Status Info */
  uint8_t lte_srv_status_info_valid;  /**< Must be set to true if lte_srv_status_info is being passed */
  nas_3gpp_srv_status_info_type_v01 lte_srv_status_info;

  /* Optional */
  /*  CDMA System Info */
  uint8_t cdma_sys_info_valid;  /**< Must be set to true if cdma_sys_info is being passed */
  nas_cdma_sys_info_type_v01 cdma_sys_info;

  /* Optional */
  /*  HDR System Info */
  uint8_t hdr_sys_info_valid;  /**< Must be set to true if hdr_sys_info is being passed */
  nas_hdr_sys_info_type_v01 hdr_sys_info;

  /* Optional */
  /*  GSM System Info */
  uint8_t gsm_sys_info_valid;  /**< Must be set to true if gsm_sys_info is being passed */
  nas_gsm_sys_info_type_v01 gsm_sys_info;

  /* Optional */
  /*  WCDMA System Info */
  uint8_t wcdma_sys_info_valid;  /**< Must be set to true if wcdma_sys_info is being passed */
  nas_wcdma_sys_info_type_v01 wcdma_sys_info;

  /* Optional */
  /*  LTE System Info */
  uint8_t lte_sys_info_valid;  /**< Must be set to true if lte_sys_info is being passed */
  nas_lte_sys_info_type_v01 lte_sys_info;

  /* Optional */
  /*  Additional CDMA System Info */
  uint8_t cdma_sys_info2_valid;  /**< Must be set to true if cdma_sys_info2 is being passed */
  nas_cdma_sys_info2_type_v01 cdma_sys_info2;

  /* Optional */
  /*  Additional HDR System Info */
  uint8_t hdr_sys_info2_valid;  /**< Must be set to true if hdr_sys_info2 is being passed */
  nas_hdr_sys_info2_type_v01 hdr_sys_info2;

  /* Optional */
  /*  Additional GSM System Info */
  uint8_t gsm_sys_info2_valid;  /**< Must be set to true if gsm_sys_info2 is being passed */
  nas_gsm_sys_info2_type_v01 gsm_sys_info2;

  /* Optional */
  /*  Additional WCDMA System Info */
  uint8_t wcdma_sys_info2_valid;  /**< Must be set to true if wcdma_sys_info2 is being passed */
  nas_wcdma_sys_info2_type_v01 wcdma_sys_info2;

  /* Optional */
  /*  Additional LTE System Info */
  uint8_t lte_sys_info2_valid;  /**< Must be set to true if lte_sys_info2 is being passed */
  nas_lte_sys_info2_type_v01 lte_sys_info2;

  /* Optional */
  /*  GSM Call Barring System Info */
  uint8_t gsm_sys_info3_valid;  /**< Must be set to true if gsm_sys_info3 is being passed */
  nas_gw_sys_info3_type_v01 gsm_sys_info3;

  /* Optional */
  /*  WCDMA Call Barring System Info */
  uint8_t wcdma_sys_info3_valid;  /**< Must be set to true if wcdma_sys_info3 is being passed */
  nas_gw_sys_info3_type_v01 wcdma_sys_info3;

  /* Optional */
  /*  LTE Voice Support Sys Info */
  uint8_t voice_support_on_lte_valid;  /**< Must be set to true if voice_support_on_lte is being passed */
  uint8_t voice_support_on_lte;
  /**<  
    Indicates voice support status on LTE. Values: \n
    - 0x00 -- Voice is not supported \n
    - 1x01 -- Voice is supported
   */

  /* Optional */
  /*  GSM Cipher Domain Sys Info */
  uint8_t gsm_cipher_domain_valid;  /**< Must be set to true if gsm_cipher_domain is being passed */
  nas_service_domain_enum_type_v01 gsm_cipher_domain;
  /**<  
    Ciphering on the service domain. Values: \n
    - 0x00 -- SYS_SRV_DOMAIN_NO_SRV  -- No service \n
    - 0x01 -- SYS_SRV_DOMAIN_CS_ONLY -- Circuit-switched only \n
    - 0x02 -- SYS_SRV_DOMAIN_PS_ONLY -- Packet-switched only \n
    - 0x03 -- SYS_SRV_DOMAIN_CS_PS   -- Circuit-switched and packet-switched
   */

  /* Optional */
  /*  WCDMA Cipher Domain Sys Info */
  uint8_t wcdma_cipher_domain_valid;  /**< Must be set to true if wcdma_cipher_domain is being passed */
  nas_service_domain_enum_type_v01 wcdma_cipher_domain;
  /**<  
    Ciphering on the service domain. Values: \n
    - 0x00 -- SYS_SRV_DOMAIN_NO_SRV  -- No service \n
    - 0x01 -- SYS_SRV_DOMAIN_CS_ONLY -- Circuit-switched only \n
    - 0x02 -- SYS_SRV_DOMAIN_PS_ONLY -- Packet-switched only \n
    - 0x03 -- SYS_SRV_DOMAIN_CS_PS   -- Circuit-switched and packet-switched
   */

  /* Optional */
  /*  TDSCDMA Service Status Info */
  uint8_t tdscdma_srv_status_info_valid;  /**< Must be set to true if tdscdma_srv_status_info is being passed */
  nas_3gpp_srv_status_info_type_v01 tdscdma_srv_status_info;

  /* Optional */
  /*  TDSCDMA System Info */
  uint8_t tdscdma_sys_info_valid;  /**< Must be set to true if tdscdma_sys_info is being passed */
  nas_tdscdma_sys_info_type_v01 tdscdma_sys_info;

  /* Optional */
  /*  LTE eMBMS Coverage Info (Deprecated; use LTE eMBMS Coverage Info Extended) */
  uint8_t lte_embms_coverage_valid;  /**< Must be set to true if lte_embms_coverage is being passed */
  uint8_t lte_embms_coverage;
  /**<  
    Values: \n
    - TRUE  -- Current LTE system supports eMBMS \n
    - FALSE -- Current LTE system does not support eMBMS
  */

  /* Optional */
  /*  SIM Reject Information */
  uint8_t sim_rej_info_valid;  /**< Must be set to true if sim_rej_info is being passed */
  nas_sim_rej_info_enum_type_v01 sim_rej_info;
  /**<  
    Current reject state information of the SIM. Values: \n
    - 0 -- NAS_SIM_NOT_AVAILABLE -- SIM is not available \n
    - 1 -- NAS_SIM_AVAILABLE     -- SIM is available     \n
    - 2 -- NAS_SIM_CS_INVALID    -- SIM has been marked by the network as 
                                    invalid for circuit-switched services \n
    - 3 -- NAS_SIM_PS_INVALID    -- SIM has been marked by the network as 
                                    invalid for packet-switched services  \n
    - 4 -- NAS_SIM_CS_PS_INVALID -- SIM has been marked by the network as 
                                    invalid for circuit-switched and 
                                    packet-switched services
  */

  /* Optional */
  /*  WCDMA EUTRA Status Information */
  uint8_t wcdma_eutra_status_valid;  /**< Must be set to true if wcdma_eutra_status is being passed */
  nas_eutra_cell_status_enum_type_v01 wcdma_eutra_status;
  /**<  
    E-UTRA detection status. Values: \n
    - 0 -- NAS_EUTRA_CELL_PRESENT           -- E-UTRA cell is detected            \n
    - 1 -- NAS_EUTRA_CELL_NOT_PRESENT       -- E-UTRA cell is not detected        \n
    - 2 -- NAS_EUTRA_CELL_PRESENCE_ UNKNOWN -- E-UTRA cell information is unknown 
                                               due to a state transition          \n
    - 3 -- NAS_EUTRA_CELL_DETECTION_ UNSUPPORTED -- E-UTRA detection is not supported
  */

  /* Optional */
  /*  IMS Voice Support Status on LTE */
  uint8_t lte_ims_voice_avail_valid;  /**< Must be set to true if lte_ims_voice_avail is being passed */
  uint8_t lte_ims_voice_avail;
  /**<   
    Values: \n
    - 0x00 -- Support is not available \n
    - 0x01 -- Support is available
    */

  /* Optional */
  /*  LTE Voice Domain */
  uint8_t lte_voice_status_valid;  /**< Must be set to true if lte_voice_status is being passed */
  nas_lte_voice_status_enum_type_v01 lte_voice_status;
  /**<  
    LTE voice domain. Values: \n
    - 0 -- NAS_DOMAIN_SEL_DOMAIN_NO_VOICE -- Data-centric devices: 
                                             No voice, stay on LTE \n
    - 1 -- NAS_DOMAIN_SEL_DOMAIN_IMS      -- Voice is supported over the IMS network \n
    - 2 -- NAS_DOMAIN_SEL_DOMAIN_1X       -- Voice is supported over the 1X network \n
    - 3 -- NAS_DOMAIN_SEL_DOMAIN_3GPP     -- Voice is supported over the 3GPP network 
  */

  /* Optional */
  /*  CDMA Reg Zone ID */
  uint8_t cdma_reg_zone_valid;  /**< Must be set to true if cdma_reg_zone is being passed */
  uint16_t cdma_reg_zone;
  /**<  
    CDMA registration zone ID.
  */

  /* Optional */
  /*  GSM RAC */
  uint8_t gsm_rac_valid;  /**< Must be set to true if gsm_rac is being passed */
  uint8_t gsm_rac;
  /**<  
    GSM routing area code.
  */

  /* Optional */
  /*  WCDMA RAC */
  uint8_t wcdma_rac_valid;  /**< Must be set to true if wcdma_rac is being passed */
  uint8_t wcdma_rac;
  /**<  
    WCDMA routing area code.
  */

  /* Optional */
  /*  CDMA Resolved Mobile Country Code */
  uint8_t cdma_mcc_resolved_via_sid_lookup_valid;  /**< Must be set to true if cdma_mcc_resolved_via_sid_lookup is being passed */
  uint16_t cdma_mcc_resolved_via_sid_lookup;
  /**<  
    MCC derived by looking up the IFAST SID conflict table and configured 
    SID-MCC table (static and NV) with the SID received from the network as the 
    key. If the lookup is not successful, 0xFFFF is used. \n
    Note: This MCC value is determined solely from the SID and may differ from 
    the MCC value sent by the network.
  */

  /* Optional */
  /*  Network Selection Registration Restriction */
  uint8_t srv_reg_restriction_valid;  /**< Must be set to true if srv_reg_restriction is being passed */
  nas_srv_reg_restriction_enum_v01 srv_reg_restriction;
  /**<  
    Registration restriction. Values: \n
    - 0x00 -- NAS_SRV_REG_RESTRICTION_ UNRESTRICTED -- Device follows the normal 
              registration process \n
    - 0x01 -- NAS_SRV_REG_RESTRICTION_ CAMPED_ONLY -- Device follows the camp-only 
              registration process

    \vspace{3pt}
    All other values are reserved.
   */

  /* Optional */
  /*  TDSCDMA Registration Domain */
  uint8_t tdscdma_reg_domain_valid;  /**< Must be set to true if tdscdma_reg_domain is being passed */
  nas_possible_reg_domain_enum_type_v01 tdscdma_reg_domain;
  /**<  
    TD-SCDMA registration domain. Values: \n
    - 0 -- NAS_POSSIBLE_REG_DOMAIN_NA        -- Not applicable because the UE 
           is not in Camp Only mode \n
    - 1 -- NAS_POSSIBLE_REG_DOMAIN_CS_ONLY   -- UE is in Camp Only mode and the 
           PLMN can provide CS service only \n
    - 2 -- NAS_POSSIBLE_REG_DOMAIN_PS_ONLY   -- UE is in Camp Only mode and the 
           PLMN can provide PS service only \n
    - 3 -- NAS_POSSIBLE_REG_DOMAIN_CS_PS     -- UE is in Camp Only mode and the 
           PLMN can provide CS and PS service \n
    - 4 -- NAS_POSSIBLE_REG_DOMAIN_ LIMITED_SERVICE -- UE is in Camp Only mode, but 
           the PLMN cannot provide any service
  */

  /* Optional */
  /*  LTE Registration Domain */
  uint8_t lte_reg_domain_valid;  /**< Must be set to true if lte_reg_domain is being passed */
  nas_possible_reg_domain_enum_type_v01 lte_reg_domain;
  /**<  
    LTE registration domain. Values: \n
    - 0 -- NAS_POSSIBLE_REG_DOMAIN_NA        -- Not applicable because the UE 
           is not in Camp Only mode \n
    - 1 -- NAS_POSSIBLE_REG_DOMAIN_CS_ONLY   -- UE is in Camp Only mode and the 
           PLMN can provide CS service only \n
    - 2 -- NAS_POSSIBLE_REG_DOMAIN_PS_ONLY   -- UE is in Camp Only mode and the 
           PLMN can provide PS service only \n
    - 3 -- NAS_POSSIBLE_REG_DOMAIN_CS_PS     -- UE is in Camp Only mode and the 
           PLMN can provide CS and PS service \n
    - 4 -- NAS_POSSIBLE_REG_DOMAIN_ LIMITED_SERVICE -- UE is in Camp Only mode, but 
           the PLMN cannot provide any service
  */

  /* Optional */
  /*  WCDMA Registration Domain */
  uint8_t wcdma_reg_domain_valid;  /**< Must be set to true if wcdma_reg_domain is being passed */
  nas_possible_reg_domain_enum_type_v01 wcdma_reg_domain;
  /**<  
    WCDMA registration domain. Values: \n
    - 0 -- NAS_POSSIBLE_REG_DOMAIN_NA        -- Not applicable because the UE 
           is not in Camp Only mode \n
    - 1 -- NAS_POSSIBLE_REG_DOMAIN_CS_ONLY   -- UE is in Camp Only mode and the 
           PLMN can provide CS service only \n
    - 2 -- NAS_POSSIBLE_REG_DOMAIN_PS_ONLY   -- UE is in Camp Only mode and the 
           PLMN can provide PS service only \n
    - 3 -- NAS_POSSIBLE_REG_DOMAIN_CS_PS     -- UE is in Camp Only mode and the 
           PLMN can provide CS and PS service \n
    - 4 -- NAS_POSSIBLE_REG_DOMAIN_ LIMITED_SERVICE -- UE is in Camp Only mode, but 
           the PLMN cannot provide any service
  */

  /* Optional */
  /*  GSM Registration Domain */
  uint8_t gsm_reg_domain_valid;  /**< Must be set to true if gsm_reg_domain is being passed */
  nas_possible_reg_domain_enum_type_v01 gsm_reg_domain;
  /**<  
    GSM registration domain. Values: \n
    - 0 -- NAS_POSSIBLE_REG_DOMAIN_NA        -- Not applicable because the UE 
           is not in Camp Only mode \n
    - 1 -- NAS_POSSIBLE_REG_DOMAIN_CS_ONLY   -- UE is in Camp Only mode and the 
           PLMN can provide CS service only \n
    - 2 -- NAS_POSSIBLE_REG_DOMAIN_PS_ONLY   -- UE is in Camp Only mode and the 
           PLMN can provide PS service only \n
    - 3 -- NAS_POSSIBLE_REG_DOMAIN_CS_PS     -- UE is in Camp Only mode and the 
           PLMN can provide CS and PS service \n
    - 4 -- NAS_POSSIBLE_REG_DOMAIN_ LIMITED_SERVICE -- UE is in Camp Only mode, but 
           the PLMN cannot provide any service
  */

  /* Optional */
  /*  LTE eMBMS Coverage Info Trace ID */
  uint8_t lte_embms_coverage_trace_id_valid;  /**< Must be set to true if lte_embms_coverage_trace_id is being passed */
  int16_t lte_embms_coverage_trace_id;
  /**<   
    LTE eMBMS coverage information trace ID. Values: \n
    - 0 to 32768 -- Valid trace ID \n
    - -1 -- Trace ID is not used
  */

  /* Optional */
  /*  WCDMA CSG Information */
  uint8_t wcdma_csg_info_valid;  /**< Must be set to true if wcdma_csg_info is being passed */
  nas_csg_info_type_v01 wcdma_csg_info;

  /* Optional */
  /*  HDR Voice Domain */
  uint8_t hdr_voice_status_valid;  /**< Must be set to true if hdr_voice_status is being passed */
  nas_lte_voice_status_enum_type_v01 hdr_voice_status;
  /**<  
    HDR voice domain. Values: \n
    - 0 -- NAS_DOMAIN_SEL_DOMAIN_NO_VOICE -- Data-centric devices: 
                                             No voice, stay on HDR \n
    - 1 -- NAS_DOMAIN_SEL_DOMAIN_IMS      -- Voice is supported over the IMS network \n
    - 2 -- NAS_DOMAIN_SEL_DOMAIN_1X       -- Voice is supported over the 1X network
  */

  /* Optional */
  /*  HDR SMS Domain */
  uint8_t hdr_sms_status_valid;  /**< Must be set to true if hdr_sms_status is being passed */
  nas_sms_status_enum_type_v01 hdr_sms_status;
  /**<  
    HDR SMS domain. Values: \n
    - 0 -- NAS_SMS_STATUS_NO_SMS -- Data-centric devices: 
                                    No SMS, stay on HDR \n
    - 1 -- NAS_SMS_STATUS_IMS    -- SMS is supported over the IMS network \n
    - 2 -- NAS_SMS_STATUS_1X     -- SMS is supported over the 1X network
  */

  /* Optional */
  /*  LTE SMS Domain */
  uint8_t lte_sms_status_valid;  /**< Must be set to true if lte_sms_status is being passed */
  nas_sms_status_enum_type_v01 lte_sms_status;
  /**<  
    LTE SMS domain. Values: \n
    - 0 -- NAS_SMS_STATUS_NO_SMS -- Data-centric devices: 
                                    No SMS, stay on LTE \n
    - 1 -- NAS_SMS_STATUS_IMS    -- SMS is supported over the IMS network \n
    - 2 -- NAS_SMS_STATUS_1X     -- SMS is supported over the 1X network \n
    - 3 -- NAS_SMS_STATUS_3GPP   -- SMS is supported over the 3GPP network 
  */

  /* Optional */
  /*  LTE Emergency Bearer Support */
  uint8_t lte_is_eb_supported_valid;  /**< Must be set to true if lte_is_eb_supported is being passed */
  nas_tri_state_boolean_type_v01 lte_is_eb_supported;
  /**<  
 Whether LTE emergency bearer is supported. Values: \n
      - NAS_TRI_FALSE (0) --  Status: FALSE \n 
      - NAS_TRI_TRUE (1) --  Status: TRUE  \n 
      - NAS_TRI_UNKNOWN (2) --  Status: Unknown  

 \vspace{3pt}
 The TLV status is NAS_TRI_UNKNOWN for scenarios where information is not 
 available from the lower layers; e.g., if the UE powers up while acquiring 
 service or in the middle of an attach procedure.
 */

  /* Optional */
  /*  GSM Voice Domain */
  uint8_t gsm_voice_status_valid;  /**< Must be set to true if gsm_voice_status is being passed */
  nas_lte_voice_status_enum_type_v01 gsm_voice_status;
  /**<  
    GSM voice domain. Values: \n
    - 0 -- NAS_DOMAIN_SEL_DOMAIN_NO_VOICE -- Data-centric devices: 
                                             No voice, stay on GSM \n
    - 1 -- NAS_DOMAIN_SEL_DOMAIN_IMS      -- Voice is supported over the IMS network \n
    - 2 -- NAS_DOMAIN_SEL_DOMAIN_1X       -- Voice is supported over the 1X network
  */

  /* Optional */
  /*  GSM SMS Domain */
  uint8_t gsm_sms_status_valid;  /**< Must be set to true if gsm_sms_status is being passed */
  nas_sms_status_enum_type_v01 gsm_sms_status;
  /**<  
    GSM SMS domain. Values: \n
    - 0 -- NAS_SMS_STATUS_NO_SMS -- Data-centric devices: 
                                    No SMS, stay on GSM \n
    - 1 -- NAS_SMS_STATUS_IMS    -- SMS is supported over the IMS network \n
    - 2 -- NAS_SMS_STATUS_1X     -- SMS is supported over the 1X network
  */

  /* Optional */
  /*  WCDMA Voice Domain */
  uint8_t wcdma_voice_status_valid;  /**< Must be set to true if wcdma_voice_status is being passed */
  nas_lte_voice_status_enum_type_v01 wcdma_voice_status;
  /**<  
    WCDMA voice domain. Values: \n
    - 0 -- NAS_DOMAIN_SEL_DOMAIN_NO_VOICE -- Data-centric devices: 
                                             No voice, stay on WCDMA \n
    - 1 -- NAS_DOMAIN_SEL_DOMAIN_IMS      -- Voice is supported over the IMS network \n
    - 2 -- NAS_DOMAIN_SEL_DOMAIN_1X       -- Voice is supported over the 1X network
  */

  /* Optional */
  /*  WCDMA SMS Domain */
  uint8_t wcdma_sms_status_valid;  /**< Must be set to true if wcdma_sms_status is being passed */
  nas_sms_status_enum_type_v01 wcdma_sms_status;
  /**<  
    WCDMA SMS domain. Values: \n
    - 0 -- NAS_SMS_STATUS_NO_SMS -- Data-centric devices: 
                                    No SMS, stay on WCDMA \n
    - 1 -- NAS_SMS_STATUS_IMS    -- SMS is supported over the IMS network \n
    - 2 -- NAS_SMS_STATUS_1X     -- SMS is supported over the 1X network
  */

  /* Optional */
  /*  LTE Emergency Access Barred */
  uint8_t emergency_access_barred_valid;  /**< Must be set to true if emergency_access_barred is being passed */
  nas_tri_state_boolean_type_v01 emergency_access_barred;
  /**<  
 Whether LTE emergency access is barred on the current system. Values: \n
      - NAS_TRI_FALSE (0) --  Status: FALSE \n 
      - NAS_TRI_TRUE (1) --  Status: TRUE  \n 
      - NAS_TRI_UNKNOWN (2) --  Status: Unknown  

 \vspace{3pt}
 The TLV status is NAS_TRI_UNKNOWN for scenarios where information is not 
 available from the lower layers; e.g., if the UE powers up while acquiring 
 service or in the middle of an attach procedure.
 */

  /* Optional */
  /*  CDMA Voice Domain */
  uint8_t cdma_voice_status_valid;  /**< Must be set to true if cdma_voice_status is being passed */
  nas_lte_voice_status_enum_type_v01 cdma_voice_status;
  /**<  
    CDMA voice domain. Values: \n
    - 0 -- NAS_DOMAIN_SEL_DOMAIN_NO_VOICE -- Data-centric devices: 
                                             No voice, stay on CDMA \n
    - 1 -- NAS_DOMAIN_SEL_DOMAIN_IMS      -- Voice is supported over the IMS network \n
    - 2 -- NAS_DOMAIN_SEL_DOMAIN_1X       -- Voice is supported over the 1X network
  */

  /* Optional */
  /*  CDMA SMS Domain */
  uint8_t cdma_sms_status_valid;  /**< Must be set to true if cdma_sms_status is being passed */
  nas_sms_status_enum_type_v01 cdma_sms_status;
  /**<  
    CDMA SMS domain. Values: \n
    - 0 -- NAS_SMS_STATUS_NO_SMS -- Data-centric devices: 
                                    No SMS, stay on CDMA \n
    - 1 -- NAS_SMS_STATUS_IMS    -- SMS is supported over the IMS network \n
    - 2 -- NAS_SMS_STATUS_1X     -- SMS is supported over the 1X network
  */

  /* Optional */
  /*  TDSCDMA Voice Domain */
  uint8_t tdscdma_voice_status_valid;  /**< Must be set to true if tdscdma_voice_status is being passed */
  nas_lte_voice_status_enum_type_v01 tdscdma_voice_status;
  /**<  
    TD-SCDMA voice domain. Values: \n
    - 0 -- NAS_DOMAIN_SEL_DOMAIN_NO_VOICE -- Data-centric devices: 
                                             No voice, stay on TD-SCDMA \n
    - 1 -- NAS_DOMAIN_SEL_DOMAIN_IMS      -- Voice is supported over the IMS network \n
    - 2 -- NAS_DOMAIN_SEL_DOMAIN_1X       -- Voice is supported over the 1X network
  */

  /* Optional */
  /*  TDSCDMA SMS Domain */
  uint8_t tdscdma_sms_status_valid;  /**< Must be set to true if tdscdma_sms_status is being passed */
  nas_sms_status_enum_type_v01 tdscdma_sms_status;
  /**<  
    TD-SCDMA SMS domain. Values: \n
    - 0 -- NAS_SMS_STATUS_NO_SMS -- Data-centric devices: 
                                    No SMS, stay on TD-SCDMA \n
    - 1 -- NAS_SMS_STATUS_IMS    -- SMS is supported over the IMS network \n
    - 2 -- NAS_SMS_STATUS_1X     -- SMS is supported over the 1X network
  */

  /* Optional */
  /*  LTE CSG Information */
  uint8_t lte_csg_info_valid;  /**< Must be set to true if lte_csg_info is being passed */
  nas_csg_info_type_v01 lte_csg_info;

  /* Optional */
  /*  LTE Cell Access Status Info */
  uint8_t lte_cell_status_valid;  /**< Must be set to true if lte_cell_status is being passed */
  nas_cell_access_status_e_type_v01 lte_cell_status;
  /**<  
 Cell access status for LTE calls. Values: \n
      - NAS_CELL_ACCESS_NORMAL_ONLY (0x00) --  Cell access is allowed for normal calls only \n  
      - NAS_CELL_ACCESS_EMERGENCY_ONLY (0x01) --  Cell access is allowed for emergency calls only \n  
      - NAS_CELL_ACCESS_NO_CALLS (0x02) --  Cell access is not allowed for any call type \n  
      - NAS_CELL_ACCESS_ALL_CALLS (0x03) --  Cell access is allowed for all call types \n  
      - NAS_CELL_ACCESS_UNKNOWN (-1) --  Cell access type is unknown  
 */

  /* Optional */
  /*  HDR Subnet Mask Length */
  uint8_t hdr_subnet_mask_len_valid;  /**< Must be set to true if hdr_subnet_mask_len is being passed */
  uint8_t hdr_subnet_mask_len;
  /**<  
      HDR subnet mask length.
  */

  /* Optional */
  /*  LTE eMBMS Coverage Info Extended */
  uint8_t embms_coverage_status_valid;  /**< Must be set to true if embms_coverage_status is being passed */
  nas_lte_rrc_embms_coverage_status_enum_v01 embms_coverage_status;
  /**<   eMBMS coverage status. Values: \n
      - NAS_LTE_RRC_EMBMS_COVERAGE_STATUS_NOT_AVAILABLE (0) --  Not available \n 
      - NAS_LTE_RRC_EMBMS_COVERAGE_STATUS_AVAILABLE (1) --  Available \n 
      - NAS_LTE_RRC_EMBMS_COVERAGE_STATUS_NOT_AVAIL_DUE_TO_UEMODE (2) --  Not available due to the UE mode \n 
      - NAS_LTE_RRC_EMBMS_COVERAGE_STATUS_NOT_AVAIL_DUE_TO_EMERGENCY (3) --  Not available due to an emergency \n 
      - NAS_LTE_RRC_EMBMS_COVERAGE_STATUS_UNKNOWN (4) --  Unknown 
 */

  /* Optional */
  /*  TDSCDMA RAC */
  uint8_t tds_rac_valid;  /**< Must be set to true if tds_rac is being passed */
  uint8_t tds_rac;
  /**<   TD-SCDMA routing area code.
  */

  /* Optional */
  /*  Accepted NW CIOT Capabilities */
  uint8_t nas_supp_ciot_optimizations_valid;  /**< Must be set to true if nas_supp_ciot_optimizations is being passed */
  nas_supp_ciot_optimizations_type_v01 nas_supp_ciot_optimizations;
  /**<   \n
       (Indicates the negotiated CIoT optimization between UE and NW. 
        This TLV is applicable when UE is camped on LTE.)
  */

  /* Optional */
  /*  Camped CIOT LTE Operational Mode */
  uint8_t nas_camped_ciot_lte_op_mode_valid;  /**< Must be set to true if nas_camped_ciot_lte_op_mode is being passed */
  nas_camped_ciot_lte_op_mode_enum_type_v01 nas_camped_ciot_lte_op_mode;
  /**<   Indicates the camped CIoT LTE mode of operation. Values: \n
      - NAS_CIOT_SYS_MODE_NO_SRV (0x00) --  No service \n 
      - NAS_CIOT_SYS_MODE_LTE_WB (0x01) --  Camped on LTE wideband \n 
      - NAS_CIOT_SYS_MODE_LTE_M1 (0x02) --  Camped on LTE M1 \n 
      - NAS_CIOT_SYS_MODE_LTE_NB1 (0x03) --  Camped on LTE NB1 
 */

  /* Optional */
  /*  NR5G Service Status Info */
  uint8_t nr5g_srv_status_info_valid;  /**< Must be set to true if nr5g_srv_status_info is being passed */
  nas_3gpp_srv_status_info_type_v01 nr5g_srv_status_info;

  /* Optional */
  /*  NR5G System Info */
  uint8_t nr5g_sys_info_valid;  /**< Must be set to true if nr5g_sys_info is being passed */
  nas_nr5g_sys_info_type_v01 nr5g_sys_info;

  /* Optional */
  /*  NR5G Cell Access Status Info */
  uint8_t nr5g_cell_status_valid;  /**< Must be set to true if nr5g_cell_status is being passed */
  nas_cell_access_status_e_type_v01 nr5g_cell_status;
  /**<  
 Cell access status for NR5G calls. Values: \n
      - NAS_CELL_ACCESS_NORMAL_ONLY (0x00) --  Cell access is allowed for normal calls only \n  
      - NAS_CELL_ACCESS_EMERGENCY_ONLY (0x01) --  Cell access is allowed for emergency calls only \n  
      - NAS_CELL_ACCESS_NO_CALLS (0x02) --  Cell access is not allowed for any call type \n  
      - NAS_CELL_ACCESS_ALL_CALLS (0x03) --  Cell access is allowed for all call types \n  
      - NAS_CELL_ACCESS_UNKNOWN (-1) --  Cell access type is unknown  
 */

  /* Optional */
  /*  CP SMS Service Status Info */
  uint8_t cp_sms_service_status_valid;  /**< Must be set to true if cp_sms_service_status is being passed */
  nas_cp_sms_service_status_e_type_v01 cp_sms_service_status;
  /**<  
 SMS service status over CP. Values: \n
      - NAS_CP_SMS_SERVICE_STATUS_NOT_AVAILABLE (0x00) --  SMS service status  over CP is not available \n  
      - NAS_CP_SMS_SERVICE_STATUS_TEMP_FAILURE (0x01) --  SMS service status  over CP is not available temporarily \n  
      - NAS_CP_SMS_SERVICE_STATUS_AVAILABLE (0x02) --  SMS service status  over CP is available \n  
 */

  /* Optional */
  /*  Additional LTE System Info - Availability of Dual connectivity of E-UTRA with NR5G */
  uint8_t endc_available_valid;  /**< Must be set to true if endc_available is being passed */
  uint8_t endc_available;
  /**<  
       Upper layer indication in LTE SIB2. Values: \n
       - 0x00 -- 5G Not available \n
       - 0x01 -- 5G Available
       
    */

  /* Optional */
  /*  Additional LTE System Info - DCNR restriction Info */
  uint8_t restrict_dcnr_valid;  /**< Must be set to true if restrict_dcnr is being passed */
  uint8_t restrict_dcnr;
  /**<  
       DCNR restriction in NAS attach/TAU accept. Values: \n
       - 0x00 -- Not restricted \n
       - 0x01 -- Restricted
    */

  /* Optional */
  /*  Additional NR5G System Info - NR5G Tracking Area Code */
  uint8_t nr5g_tac_info_valid;  /**< Must be set to true if nr5g_tac_info is being passed */
  nas_nr5g_tac_info_type_v01 nr5g_tac_info;

  /* Optional */
  /*  NR5G Service Area Restriction Info */
  uint8_t tracking_area_is_restricted_valid;  /**< Must be set to true if tracking_area_is_restricted is being passed */
  uint8_t tracking_area_is_restricted;
  /**<  
       Service area restriction in NAS attach/TAU accept. Values: \n
       - 0x00 -- UE registered on allowed Tracking Area \n
       - 0x01 -- UE registered on restricted Tracking Area
    */

  /* Optional */
  /*  5G SMS Registration Status Info */
  uint8_t n1_sms_is_registered_valid;  /**< Must be set to true if n1_sms_is_registered is being passed */
  uint8_t n1_sms_is_registered;
  /**<  
       SMS registration status: \n
       - 0x00 -- Not registered \n
       - 0x01 -- registered
    */

  /* Optional */
  /*  NR5G MPSI Valid Info */
  uint8_t mpsi_indicator_is_valid_valid;  /**< Must be set to true if mpsi_indicator_is_valid is being passed */
  uint8_t mpsi_indicator_is_valid;
  /**<  
       MPS indicator valid in RPLMN or equivalent PLMN: \n
       - 0x00 -- Not valid \n
       - 0x01 -- Valid
   */

  /* Optional */
  /*  Additional NR5G System Info */
  uint8_t nr5g_pci_valid;  /**< Must be set to true if nr5g_pci is being passed */
  uint16_t nr5g_pci;
  /**<  
       NR5G Physical Cell ID
     */

  /* Optional */
  /*  Additional LTE system Info - PLMN Info List R15 availability */
  uint8_t plmn_infolist_r15_available_valid;  /**< Must be set to true if plmn_infolist_r15_available is being passed */
  uint8_t plmn_infolist_r15_available;
  /**<  
       - 0x00 -- SIB2 doesn't have plmn-InfoList-r15 IE \n
       - 0x01 -- SIB2 has plmn-InfoList-r15 IE
    */

  /* Optional */
  /*  IMS Vops Support Status on NR5G */
  uint8_t nr5g_ims_voice_avail_valid;  /**< Must be set to true if nr5g_ims_voice_avail is being passed */
  nas_nr5g_vops_support_enum_type_v01 nr5g_ims_voice_avail;
  /**<   
 NR5G vops support. Values: \n
      - NAS_NR5G_IMS_VOPS_NOT_SUPPORTED (0) --  IMS voice over PS session not supported 
      - NAS_NR5G_IMS_VOPS_SUPPORTED_3GPP (1) --  IMS voice over PS session supported over 3GPP access 
      - NAS_NR5G_IMS_VOPS_SUPPORTED_NON_3GPP (2) --  IMS voice over PS session supported over non-3GPP access
 */

  /* Optional */
  /*  NR5G Voice Domain */
  uint8_t nr5g_voice_domain_valid;  /**< Must be set to true if nr5g_voice_domain is being passed */
  nas_nr5g_voice_domain_enum_type_v01 nr5g_voice_domain;
  /**<  
 NR5G voice domain. Values: \n
      - NAS_NR5G_VOICE_DOMAIN_NO_VOICE (0) --  Data centric devices: No voice, stay on NR5G 
      - NAS_NR5G_VOICE_DOMAIN_IMS (1) --  Voice is supported over IMS network 
 */

  /* Optional */
  /*  NR5G SMS Domain */
  uint8_t nr5g_sms_domain_valid;  /**< Must be set to true if nr5g_sms_domain is being passed */
  nas_sms_status_enum_type_v01 nr5g_sms_domain;
  /**<  
 NR5G SMS domain. Values: \n
      - NAS_SMS_STATUS_NO_SMS (0) --  Data centric devices: No sms, stay on network 
      - NAS_SMS_STATUS_IMS (1) --  SMS is supported over IMS network 
      - NAS_SMS_STATUS_1X (2) --  SMS is supported over 1X network 
      - NAS_SMS_STATUS_3GPP (3) --  SMS is supported over 3GPP network 
 */

  /* Optional */
  /*  NR5G Voice Support Sys Info */
  uint8_t voice_support_on_nr5g_valid;  /**< Must be set to true if voice_support_on_nr5g is being passed */
  uint8_t voice_support_on_nr5g;
  /**<  
    Indicates voice support status on NR5G. Values: \n
    - 0x00 -- Voice is not supported \n
    - 1x01 -- Voice is supported
   */
}nas_get_sys_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates a change in the system information.   
             \label{idl:sysInfoInd} */
typedef struct {

  /* Optional */
  /*  CDMA Service Status Info */
  uint8_t cdma_srv_status_info_valid;  /**< Must be set to true if cdma_srv_status_info is being passed */
  nas_3gpp2_srv_status_info_type_v01 cdma_srv_status_info;

  /* Optional */
  /*  HDR Service Status Info */
  uint8_t hdr_srv_status_info_valid;  /**< Must be set to true if hdr_srv_status_info is being passed */
  nas_3gpp2_srv_status_info_type_v01 hdr_srv_status_info;

  /* Optional */
  /*  GSM Service Status Info */
  uint8_t gsm_srv_status_info_valid;  /**< Must be set to true if gsm_srv_status_info is being passed */
  nas_3gpp_srv_status_info_type_v01 gsm_srv_status_info;

  /* Optional */
  /*  WCDMA Service Status Info */
  uint8_t wcdma_srv_status_info_valid;  /**< Must be set to true if wcdma_srv_status_info is being passed */
  nas_3gpp_srv_status_info_type_v01 wcdma_srv_status_info;

  /* Optional */
  /*  LTE Service Status Info */
  uint8_t lte_srv_status_info_valid;  /**< Must be set to true if lte_srv_status_info is being passed */
  nas_3gpp_srv_status_info_type_v01 lte_srv_status_info;

  /* Optional */
  /*  CDMA System Info */
  uint8_t cdma_sys_info_valid;  /**< Must be set to true if cdma_sys_info is being passed */
  nas_cdma_sys_info_type_v01 cdma_sys_info;

  /* Optional */
  /*  HDR System Info */
  uint8_t hdr_sys_info_valid;  /**< Must be set to true if hdr_sys_info is being passed */
  nas_hdr_sys_info_type_v01 hdr_sys_info;

  /* Optional */
  /*  GSM System Info */
  uint8_t gsm_sys_info_valid;  /**< Must be set to true if gsm_sys_info is being passed */
  nas_gsm_sys_info_type_v01 gsm_sys_info;

  /* Optional */
  /*  WCDMA System Info */
  uint8_t wcdma_sys_info_valid;  /**< Must be set to true if wcdma_sys_info is being passed */
  nas_wcdma_sys_info_type_v01 wcdma_sys_info;

  /* Optional */
  /*  LTE System Info */
  uint8_t lte_sys_info_valid;  /**< Must be set to true if lte_sys_info is being passed */
  nas_lte_sys_info_type_v01 lte_sys_info;

  /* Optional */
  /*  Additional CDMA System Info */
  uint8_t cdma_sys_info2_valid;  /**< Must be set to true if cdma_sys_info2 is being passed */
  nas_cdma_sys_info2_type_v01 cdma_sys_info2;

  /* Optional */
  /*  Additional HDR System Info */
  uint8_t hdr_sys_info2_valid;  /**< Must be set to true if hdr_sys_info2 is being passed */
  nas_hdr_sys_info2_type_v01 hdr_sys_info2;

  /* Optional */
  /*  Additional GSM System Info */
  uint8_t gsm_sys_info2_valid;  /**< Must be set to true if gsm_sys_info2 is being passed */
  nas_gsm_sys_info2_type_v01 gsm_sys_info2;

  /* Optional */
  /*  Additional WCDMA System Info */
  uint8_t wcdma_sys_info2_valid;  /**< Must be set to true if wcdma_sys_info2 is being passed */
  nas_wcdma_sys_info2_type_v01 wcdma_sys_info2;

  /* Optional */
  /*  Additional LTE System Info */
  uint8_t lte_sys_info2_valid;  /**< Must be set to true if lte_sys_info2 is being passed */
  nas_lte_sys_info2_type_v01 lte_sys_info2;

  /* Optional */
  /*  GSM Call Barring System Info */
  uint8_t gsm_sys_info3_valid;  /**< Must be set to true if gsm_sys_info3 is being passed */
  nas_gw_sys_info3_type_v01 gsm_sys_info3;

  /* Optional */
  /*  WCDMA Call Barring System Info */
  uint8_t wcdma_sys_info3_valid;  /**< Must be set to true if wcdma_sys_info3 is being passed */
  nas_gw_sys_info3_type_v01 wcdma_sys_info3;

  /* Optional */
  /*  LTE Voice Support Sys Info */
  uint8_t voice_support_on_lte_valid;  /**< Must be set to true if voice_support_on_lte is being passed */
  uint8_t voice_support_on_lte;
  /**<  
    Indicates voice support status on LTE. Values: \n
    - 0x00 -- Voice is not supported \n
    - 1x01 -- Voice is supported
   */

  /* Optional */
  /*  GSM Cipher Domain Sys Info */
  uint8_t gsm_cipher_domain_valid;  /**< Must be set to true if gsm_cipher_domain is being passed */
  nas_service_domain_enum_type_v01 gsm_cipher_domain;
  /**<  
    Ciphering on the service domain. Values: \n
    - 0x00 -- SYS_SRV_DOMAIN_NO_SRV  -- No service \n
    - 0x01 -- SYS_SRV_DOMAIN_CS_ONLY -- Circuit-switched only \n
    - 0x02 -- SYS_SRV_DOMAIN_PS_ONLY -- Packet-switched only \n
    - 0x03 -- SYS_SRV_DOMAIN_CS_PS   -- Circuit-switched and packet-switched
   */

  /* Optional */
  /*  WCDMA Cipher Domain Sys Info */
  uint8_t wcdma_cipher_domain_valid;  /**< Must be set to true if wcdma_cipher_domain is being passed */
  nas_service_domain_enum_type_v01 wcdma_cipher_domain;
  /**<  
    Ciphering on the service domain. Values: \n
    - 0x00 -- SYS_SRV_DOMAIN_NO_SRV  -- No service \n
    - 0x01 -- SYS_SRV_DOMAIN_CS_ONLY -- Circuit-switched only \n
    - 0x02 -- SYS_SRV_DOMAIN_PS_ONLY -- Packet-switched only \n
    - 0x03 -- SYS_SRV_DOMAIN_CS_PS   -- Circuit-switched and packet-switched
   */

  /* Optional */
  /*  System Info No Change */
  uint8_t sys_info_no_change_valid;  /**< Must be set to true if sys_info_no_change is being passed */
  uint8_t sys_info_no_change;
  /**<   
    Flag used to notify clients that a request to select a network ended 
    with no change in the PLMN. Values: \n
    - 0x01 -- No change in system information
  */

  /* Optional */
  /*  TDSCDMA Service Status Info */
  uint8_t tdscdma_srv_status_info_valid;  /**< Must be set to true if tdscdma_srv_status_info is being passed */
  nas_3gpp_srv_status_info_type_v01 tdscdma_srv_status_info;

  /* Optional */
  /*  TDSCDMA System Info */
  uint8_t tdscdma_sys_info_valid;  /**< Must be set to true if tdscdma_sys_info is being passed */
  nas_tdscdma_sys_info_type_v01 tdscdma_sys_info;

  /* Optional */
  /*  LTE eMBMS Coverage Info (Deprecated; use LTE eMBMS Coverage Info Extended) */
  uint8_t lte_embms_coverage_valid;  /**< Must be set to true if lte_embms_coverage is being passed */
  uint8_t lte_embms_coverage;
  /**<  
    Values: \n
    - TRUE  -- Current LTE system supports eMBMBS \n
    - FALSE -- Current LTE system does not support eMBMBS
 */

  /* Optional */
  /*  SIM Reject information */
  uint8_t sim_rej_info_valid;  /**< Must be set to true if sim_rej_info is being passed */
  nas_sim_rej_info_enum_type_v01 sim_rej_info;
  /**<  
    Current reject state information of the SIM. Values: \n
    - 0 -- NAS_SIM_NOT_AVAILABLE -- SIM is not available \n
    - 1 -- NAS_SIM_AVAILABLE     -- SIM is available     \n
    - 2 -- NAS_SIM_CS_INVALID    -- SIM has been marked by the network as 
                                    invalid for circuit-switched services \n
    - 3 -- NAS_SIM_PS_INVALID    -- SIM has been marked by the network as 
                                    invalid for packet-switched services  \n
    - 4 -- NAS_SIM_CS_PS_INVALID -- SIM has been marked by the network as 
                                    invalid for circuit-switched and 
                                    packet-switched services
  */

  /* Optional */
  /*  WCDMA EUTRA Status Information */
  uint8_t wcdma_eutra_status_valid;  /**< Must be set to true if wcdma_eutra_status is being passed */
  nas_eutra_cell_status_enum_type_v01 wcdma_eutra_status;
  /**<  
     E-UTRA detection status. Values: \n
    - 0 -- NAS_EUTRA_CELL_PRESENT           -- E-UTRA cell is detected            \n
    - 1 -- NAS_EUTRA_CELL_NOT_PRESENT       -- E-UTRA cell is not detected        \n
    - 2 -- NAS_EUTRA_CELL_PRESENCE_ UNKNOWN -- E-UTRA cell information is unknown 
                                               due to a state transition          \n
    - 3 -- NAS_EUTRA_CELL_DETECTION_ UNSUPPORTED -- E-UTRA detection is not supported
  */

  /* Optional */
  /*  IMS Voice Support Status on LTE */
  uint8_t lte_ims_voice_avail_valid;  /**< Must be set to true if lte_ims_voice_avail is being passed */
  uint8_t lte_ims_voice_avail;
  /**<  
    Values: \n
    - 0x00 -- Support is not available \n
    - 0x01 -- Support is available
  */

  /* Optional */
  /*  LTE Voice Domain */
  uint8_t lte_voice_status_valid;  /**< Must be set to true if lte_voice_status is being passed */
  nas_lte_voice_status_enum_type_v01 lte_voice_status;
  /**<  
    LTE voice domain. Values: \n
    - 0 -- NAS_DOMAIN_SEL_DOMAIN_NO_VOICE -- Data-centric devices: 
                                             No voice, stay on LTE \n
    - 1 -- NAS_DOMAIN_SEL_DOMAIN_IMS      -- Voice is supported over the IMS network \n
    - 2 -- NAS_DOMAIN_SEL_DOMAIN_1X       -- Voice is supported over the 1X network \n
    - 3 -- NAS_DOMAIN_SEL_DOMAIN_3GPP     -- Voice is supported over the 3GPP network 
  */

  /* Optional */
  /*  CDMA Reg Zone ID */
  uint8_t cdma_reg_zone_valid;  /**< Must be set to true if cdma_reg_zone is being passed */
  uint16_t cdma_reg_zone;
  /**<  
    CDMA registration zone ID.
  */

  /* Optional */
  /*  GSM RAC */
  uint8_t gsm_rac_valid;  /**< Must be set to true if gsm_rac is being passed */
  uint8_t gsm_rac;
  /**<  
    GSM routing area code.
  */

  /* Optional */
  /*  WCDMA RAC */
  uint8_t wcdma_rac_valid;  /**< Must be set to true if wcdma_rac is being passed */
  uint8_t wcdma_rac;
  /**<  
    WCDMA routing area code.
  */

  /* Optional */
  /*  CDMA Resolved Mobile Country Code */
  uint8_t cdma_mcc_resolved_via_sid_lookup_valid;  /**< Must be set to true if cdma_mcc_resolved_via_sid_lookup is being passed */
  uint16_t cdma_mcc_resolved_via_sid_lookup;
  /**<  
    MCC derived by looking up the IFAST SID conflict table and configured 
    SID-MCC table (static and NV) with the SID received from the network as the 
    key. If the lookup is not successful, 0xFFFF is used. \n
    Note: This MCC value is determined solely from the SID and may differ from 
    the MCC value sent by the network.

    (This field requires version 1.35 or later.)
  */

  /* Optional */
  /*  Network Selection Registration Restriction */
  uint8_t srv_reg_restriction_valid;  /**< Must be set to true if srv_reg_restriction is being passed */
  nas_srv_reg_restriction_enum_v01 srv_reg_restriction;
  /**<  
     Registration restriction. Values: \n
    - 0x00 -- NAS_SRV_REG_RESTRICTION_ UNRESTRICTED -- Device follows the normal 
              registration process \n
    - 0x01 -- NAS_SRV_REG_RESTRICTION_ CAMPED_ONLY -- Device follows the camp-only 
              registration process

    \vspace{3pt}
    All other values are reserved.

    (This field requires version 1.35 or later.)
  */

  /* Optional */
  /*  TDSCDMA Registration Domain */
  uint8_t tdscdma_reg_domain_valid;  /**< Must be set to true if tdscdma_reg_domain is being passed */
  nas_possible_reg_domain_enum_type_v01 tdscdma_reg_domain;
  /**<  
    TD-SCDMA registration domain. Values: \n
    - 0 -- NAS_POSSIBLE_REG_DOMAIN_NA        -- Not applicable because the UE 
           is not in Camp Only mode \n
    - 1 -- NAS_POSSIBLE_REG_DOMAIN_CS_ONLY   -- UE is in Camp Only mode and the 
           PLMN can provide CS service only \n
    - 2 -- NAS_POSSIBLE_REG_DOMAIN_PS_ONLY   -- UE is in Camp Only mode and the 
           PLMN can provide PS service only \n
    - 3 -- NAS_POSSIBLE_REG_DOMAIN_CS_PS     -- UE is in Camp Only mode and the 
           PLMN can provide CS and PS service \n
    - 4 -- NAS_POSSIBLE_REG_DOMAIN_ LIMITED_SERVICE -- UE is in Camp Only mode, but 
           the PLMN cannot provide any service

    \vspace{3pt}
   (This field requires version 1.35 or later.)
  */

  /* Optional */
  /*  LTE Registration Domain */
  uint8_t lte_reg_domain_valid;  /**< Must be set to true if lte_reg_domain is being passed */
  nas_possible_reg_domain_enum_type_v01 lte_reg_domain;
  /**<  
    LTE registration domain. Values: \n
    - 0 -- NAS_POSSIBLE_REG_DOMAIN_NA        -- Not applicable because the UE 
           is not in Camp Only mode \n
    - 1 -- NAS_POSSIBLE_REG_DOMAIN_CS_ONLY   -- UE is in Camp Only mode and the 
           PLMN can provide CS service only \n
    - 2 -- NAS_POSSIBLE_REG_DOMAIN_PS_ONLY   -- UE is in Camp Only mode and the 
           PLMN can provide PS service only \n
    - 3 -- NAS_POSSIBLE_REG_DOMAIN_CS_PS     -- UE is in Camp Only mode and the 
           PLMN can provide CS and PS service \n
    - 4 -- NAS_POSSIBLE_REG_DOMAIN_ LIMITED_SERVICE -- UE is in Camp Only mode, but 
           the PLMN cannot provide any service

    \vspace{3pt}
   (This field requires version 1.35 or later.)
  */

  /* Optional */
  /*  WCDMA Registration Domain */
  uint8_t wcdma_reg_domain_valid;  /**< Must be set to true if wcdma_reg_domain is being passed */
  nas_possible_reg_domain_enum_type_v01 wcdma_reg_domain;
  /**<  
    WCDMA registration domain. Values: \n
    - 0 -- NAS_POSSIBLE_REG_DOMAIN_NA        -- Not applicable because the UE 
           is not in Camp Only mode \n
    - 1 -- NAS_POSSIBLE_REG_DOMAIN_CS_ONLY   -- UE is in Camp Only mode and the 
           PLMN can provide CS service only \n
    - 2 -- NAS_POSSIBLE_REG_DOMAIN_PS_ONLY   -- UE is in Camp Only mode and the 
           PLMN can provide PS service only \n
    - 3 -- NAS_POSSIBLE_REG_DOMAIN_CS_PS     -- UE is in Camp Only mode and the 
           PLMN can provide CS and PS service \n
    - 4 -- NAS_POSSIBLE_REG_DOMAIN_ LIMITED_SERVICE -- UE is in Camp Only mode, but 
           the PLMN cannot provide any service

    \vspace{3pt}
   (This field requires version 1.35 or later.)
  */

  /* Optional */
  /*  GSM Registration Domain */
  uint8_t gsm_reg_domain_valid;  /**< Must be set to true if gsm_reg_domain is being passed */
  nas_possible_reg_domain_enum_type_v01 gsm_reg_domain;
  /**<  
    GSM registration domain. Values: \n
    - 0 -- NAS_POSSIBLE_REG_DOMAIN_NA        -- Not applicable because the UE 
           is not in Camp Only mode \n
    - 1 -- NAS_POSSIBLE_REG_DOMAIN_CS_ONLY   -- UE is in Camp Only mode and the 
           PLMN can provide CS service only \n
    - 2 -- NAS_POSSIBLE_REG_DOMAIN_PS_ONLY   -- UE is in Camp Only mode and the 
           PLMN can provide PS service only \n
    - 3 -- NAS_POSSIBLE_REG_DOMAIN_CS_PS     -- UE is in Camp Only mode and the 
           PLMN can provide CS and PS service \n
    - 4 -- NAS_POSSIBLE_REG_DOMAIN_ LIMITED_SERVICE -- UE is in Camp Only mode, but 
           the PLMN cannot provide any service

    \vspace{3pt}
   (This field requires version 1.35 or later.)
  */

  /* Optional */
  /*  LTE eMBMS Coverage Info Trace ID */
  uint8_t lte_embms_coverage_trace_id_valid;  /**< Must be set to true if lte_embms_coverage_trace_id is being passed */
  int16_t lte_embms_coverage_trace_id;
  /**<   
    LTE eMBMS coverage information trace ID. Values: \n 
    - 0 to 32768 -- Valid trace ID \n
    - -1 -- Trace ID is not used  
  */

  /* Optional */
  /*  WCDMA CSG Information */
  uint8_t wcdma_csg_info_valid;  /**< Must be set to true if wcdma_csg_info is being passed */
  nas_csg_info_type_v01 wcdma_csg_info;

  /* Optional */
  /*  HDR Voice Domain */
  uint8_t hdr_voice_status_valid;  /**< Must be set to true if hdr_voice_status is being passed */
  nas_lte_voice_status_enum_type_v01 hdr_voice_status;
  /**<  
    HDR voice domain. Values: \n
    - 0 -- NAS_DOMAIN_SEL_DOMAIN_NO_VOICE -- Data-centric devices: 
                                             No voice, stay on HDR \n
    - 1 -- NAS_DOMAIN_SEL_DOMAIN_IMS      -- Voice is supported over the IMS network \n
    - 2 -- NAS_DOMAIN_SEL_DOMAIN_1X       -- Voice is supported over the 1X network
  */

  /* Optional */
  /*  HDR SMS Domain */
  uint8_t hdr_sms_status_valid;  /**< Must be set to true if hdr_sms_status is being passed */
  nas_sms_status_enum_type_v01 hdr_sms_status;
  /**<  
    HDR SMS domain. Values: \n
    - 0 -- NAS_SMS_STATUS_NO_SMS -- Data-centric devices: 
                                    No SMS, stay on HDR \n
    - 1 -- NAS_SMS_STATUS_IMS    -- SMS is supported over the IMS network \n
    - 2 -- NAS_SMS_STATUS_1X     -- SMS is supported over the 1X network
  */

  /* Optional */
  /*  LTE SMS Domain */
  uint8_t lte_sms_status_valid;  /**< Must be set to true if lte_sms_status is being passed */
  nas_sms_status_enum_type_v01 lte_sms_status;
  /**<  
    LTE SMS domain. Values: \n
    - 0 -- NAS_SMS_STATUS_NO_SMS -- Data-centric devices: 
                                    No SMS, stay on LTE \n
    - 1 -- NAS_SMS_STATUS_IMS    -- SMS is supported over the IMS network \n
    - 2 -- NAS_SMS_STATUS_1X     -- SMS is supported over the 1X network \n
    - 3 -- NAS_SMS_STATUS_3GPP   -- SMS is supported over the 3GPP network 
  */

  /* Optional */
  /*  LTE Emergency Bearer Support */
  uint8_t lte_is_eb_supported_valid;  /**< Must be set to true if lte_is_eb_supported is being passed */
  nas_tri_state_boolean_type_v01 lte_is_eb_supported;
  /**<  
 Whether LTE emergency bearer is supported. Values: \n
      - NAS_TRI_FALSE (0) --  Status: FALSE \n 
      - NAS_TRI_TRUE (1) --  Status: TRUE  \n 
      - NAS_TRI_UNKNOWN (2) --  Status: Unknown  

 \vspace{3pt}
 The TLV status is NAS_TRI_UNKNOWN for scenarios where information is not 
 available from the lower layers; e.g., if the UE powers up while acquiring 
 service or in the middle of an attach procedure.
 */

  /* Optional */
  /*  GSM Voice Domain */
  uint8_t gsm_voice_status_valid;  /**< Must be set to true if gsm_voice_status is being passed */
  nas_lte_voice_status_enum_type_v01 gsm_voice_status;
  /**<  
    GSM voice domain. Values: \n
    - 0 -- NAS_DOMAIN_SEL_DOMAIN_NO_VOICE -- Data-centric devices: 
                                             No voice, stay on GSM \n
    - 1 -- NAS_DOMAIN_SEL_DOMAIN_IMS      -- Voice is supported over the IMS network \n
    - 2 -- NAS_DOMAIN_SEL_DOMAIN_1X       -- Voice is supported over the 1X network
  */

  /* Optional */
  /*  GSM SMS Domain */
  uint8_t gsm_sms_status_valid;  /**< Must be set to true if gsm_sms_status is being passed */
  nas_sms_status_enum_type_v01 gsm_sms_status;
  /**<  
    GSM SMS domain. Values: \n
    - 0 -- NAS_SMS_STATUS_NO_SMS -- Data-centric devices: 
                                    No SMS, stay on GSM \n
    - 1 -- NAS_SMS_STATUS_IMS    -- SMS is supported over the IMS network \n
    - 2 -- NAS_SMS_STATUS_1X     -- SMS is supported over the 1X network
  */

  /* Optional */
  /*  WCDMA Voice Domain */
  uint8_t wcdma_voice_status_valid;  /**< Must be set to true if wcdma_voice_status is being passed */
  nas_lte_voice_status_enum_type_v01 wcdma_voice_status;
  /**<  
    WCDMA voice domain. Values: \n
    - 0 -- NAS_DOMAIN_SEL_DOMAIN_NO_VOICE -- Data-centric devices: 
                                             No voice, stay on WCDMA \n
    - 1 -- NAS_DOMAIN_SEL_DOMAIN_IMS      -- Voice is supported over the IMS network \n
    - 2 -- NAS_DOMAIN_SEL_DOMAIN_1X       -- Voice is supported over the 1X network
  */

  /* Optional */
  /*  WCDMA SMS Domain */
  uint8_t wcdma_sms_status_valid;  /**< Must be set to true if wcdma_sms_status is being passed */
  nas_sms_status_enum_type_v01 wcdma_sms_status;
  /**<  
    WCDMA SMS domain. Values: \n
    - 0 -- NAS_SMS_STATUS_NO_SMS -- Data-centric devices: 
                                    No SMS, stay on WCDMA \n
    - 1 -- NAS_SMS_STATUS_IMS    -- SMS is supported over the IMS network \n
    - 2 -- NAS_SMS_STATUS_1X     -- SMS is supported over the 1X network
  */

  /* Optional */
  /*  LTE Emergency Access Barred */
  uint8_t emergency_access_barred_valid;  /**< Must be set to true if emergency_access_barred is being passed */
  nas_tri_state_boolean_type_v01 emergency_access_barred;
  /**<  
 Whether LTE emergency access is barred on the current system. Values: \n
      - NAS_TRI_FALSE (0) --  Status: FALSE \n 
      - NAS_TRI_TRUE (1) --  Status: TRUE  \n 
      - NAS_TRI_UNKNOWN (2) --  Status: Unknown  

 \vspace{3pt}
 The TLV status is NAS_TRI_UNKNOWN for scenarios where information is not 
 available from the lower layers; e.g., if the UE powers up while acquiring 
 service or in the middle of an attach procedure.
 */

  /* Optional */
  /*  CDMA Voice Domain */
  uint8_t cdma_voice_status_valid;  /**< Must be set to true if cdma_voice_status is being passed */
  nas_lte_voice_status_enum_type_v01 cdma_voice_status;
  /**<  
    CDMA voice domain. Values: \n
    - 0 -- NAS_DOMAIN_SEL_DOMAIN_NO_VOICE -- Data-centric devices: 
                                             No voice, stay on CDMA \n
    - 1 -- NAS_DOMAIN_SEL_DOMAIN_IMS      -- Voice is supported over the IMS network \n
    - 2 -- NAS_DOMAIN_SEL_DOMAIN_1X       -- Voice is supported over the 1X network
  */

  /* Optional */
  /*  CDMA SMS Domain */
  uint8_t cdma_sms_status_valid;  /**< Must be set to true if cdma_sms_status is being passed */
  nas_sms_status_enum_type_v01 cdma_sms_status;
  /**<  
    CDMA SMS domain. Values: \n
    - 0 -- NAS_SMS_STATUS_NO_SMS -- Data-centric devices: 
                                    No SMS, stay on CDMA \n
    - 1 -- NAS_SMS_STATUS_IMS    -- SMS is supported over the IMS network \n
    - 2 -- NAS_SMS_STATUS_1X     -- SMS is supported over the 1X network
  */

  /* Optional */
  /*  TDSCDMA Voice Domain */
  uint8_t tdscdma_voice_status_valid;  /**< Must be set to true if tdscdma_voice_status is being passed */
  nas_lte_voice_status_enum_type_v01 tdscdma_voice_status;
  /**<  
    TD-SCDMA voice domain. Values: \n
    - 0 -- NAS_DOMAIN_SEL_DOMAIN_NO_VOICE -- Data-centric devices: 
                                             No voice, stay on TD-SCDMA \n
    - 1 -- NAS_DOMAIN_SEL_DOMAIN_IMS      -- Voice is supported over the IMS network \n
    - 2 -- NAS_DOMAIN_SEL_DOMAIN_1X       -- Voice is supported over the 1X network
  */

  /* Optional */
  /*  TDSCDMA SMS Domain */
  uint8_t tdscdma_sms_status_valid;  /**< Must be set to true if tdscdma_sms_status is being passed */
  nas_sms_status_enum_type_v01 tdscdma_sms_status;
  /**<  
    TD-SCDMA SMS domain. Values: \n
    - 0 -- NAS_SMS_STATUS_NO_SMS -- Data-centric devices: 
                                    No SMS, stay on TD-SCDMA \n
    - 1 -- NAS_SMS_STATUS_IMS    -- SMS is supported over the IMS network \n
    - 2 -- NAS_SMS_STATUS_1X     -- SMS is supported over the 1X network
  */

  /* Optional */
  /*  LTE CSG Information */
  uint8_t lte_csg_info_valid;  /**< Must be set to true if lte_csg_info is being passed */
  nas_csg_info_type_v01 lte_csg_info;

  /* Optional */
  /*  LTE Cell Access Status Info */
  uint8_t lte_cell_status_valid;  /**< Must be set to true if lte_cell_status is being passed */
  nas_cell_access_status_e_type_v01 lte_cell_status;
  /**<  
 Cell access status for LTE calls. Values: \n
      - NAS_CELL_ACCESS_NORMAL_ONLY (0x00) --  Cell access is allowed for normal calls only \n  
      - NAS_CELL_ACCESS_EMERGENCY_ONLY (0x01) --  Cell access is allowed for emergency calls only \n  
      - NAS_CELL_ACCESS_NO_CALLS (0x02) --  Cell access is not allowed for any call type \n  
      - NAS_CELL_ACCESS_ALL_CALLS (0x03) --  Cell access is allowed for all call types \n  
      - NAS_CELL_ACCESS_UNKNOWN (-1) --  Cell access type is unknown  
 */

  /* Optional */
  /*  HDR Subnet Mask Length */
  uint8_t hdr_subnet_mask_len_valid;  /**< Must be set to true if hdr_subnet_mask_len is being passed */
  uint8_t hdr_subnet_mask_len;
  /**<  
      HDR subnet mask length.
  */

  /* Optional */
  /*  LTE eMBMS Coverage Info Extended */
  uint8_t embms_coverage_status_valid;  /**< Must be set to true if embms_coverage_status is being passed */
  nas_lte_rrc_embms_coverage_status_enum_v01 embms_coverage_status;
  /**<   eMBMS coverage status. Values: \n
      - NAS_LTE_RRC_EMBMS_COVERAGE_STATUS_NOT_AVAILABLE (0) --  Not available \n 
      - NAS_LTE_RRC_EMBMS_COVERAGE_STATUS_AVAILABLE (1) --  Available \n 
      - NAS_LTE_RRC_EMBMS_COVERAGE_STATUS_NOT_AVAIL_DUE_TO_UEMODE (2) --  Not available due to the UE mode \n 
      - NAS_LTE_RRC_EMBMS_COVERAGE_STATUS_NOT_AVAIL_DUE_TO_EMERGENCY (3) --  Not available due to an emergency \n 
      - NAS_LTE_RRC_EMBMS_COVERAGE_STATUS_UNKNOWN (4) --  Unknown 
 */

  /* Optional */
  /*  eDRX Support */
  uint8_t edrx_supported_valid;  /**< Must be set to true if edrx_supported is being passed */
  uint8_t edrx_supported;
  /**<   Status of the eDRX support in the current cell. Values: \n
       - TRUE -- eDRX is supported \n
       - FALSE -- eDRX is not supported
  */

  /* Optional */
  /*  TDSCDMA RAC */
  uint8_t tds_rac_valid;  /**< Must be set to true if tds_rac is being passed */
  uint8_t tds_rac;
  /**<   TD-SCDMA routing area code.
  */

  /* Optional */
  /*  Accepted NW CIOT Capabilities */
  uint8_t nas_supp_ciot_optimizations_valid;  /**< Must be set to true if nas_supp_ciot_optimizations is being passed */
  nas_supp_ciot_optimizations_type_v01 nas_supp_ciot_optimizations;
  /**<   \n
       (Indicates the negotiated CIoT optimization between UE and NW. 
        This TLV is applicable when UE is camped on LTE.)
  */

  /* Optional */
  /*  Camped CIOT LTE Operational Mode */
  uint8_t nas_camped_ciot_lte_op_mode_valid;  /**< Must be set to true if nas_camped_ciot_lte_op_mode is being passed */
  nas_camped_ciot_lte_op_mode_enum_type_v01 nas_camped_ciot_lte_op_mode;
  /**<   Indicates the camped CIoT LTE mode of operation. Values: \n
      - NAS_CIOT_SYS_MODE_NO_SRV (0x00) --  No service \n 
      - NAS_CIOT_SYS_MODE_LTE_WB (0x01) --  Camped on LTE wideband \n 
      - NAS_CIOT_SYS_MODE_LTE_M1 (0x02) --  Camped on LTE M1 \n 
      - NAS_CIOT_SYS_MODE_LTE_NB1 (0x03) --  Camped on LTE NB1 
 */

  /* Optional */
  /*  NR5G Service Status Info */
  uint8_t nr5g_srv_status_info_valid;  /**< Must be set to true if nr5g_srv_status_info is being passed */
  nas_3gpp_srv_status_info_type_v01 nr5g_srv_status_info;

  /* Optional */
  /*  NR5G System Info */
  uint8_t nr5g_sys_info_valid;  /**< Must be set to true if nr5g_sys_info is being passed */
  nas_nr5g_sys_info_type_v01 nr5g_sys_info;

  /* Optional */
  /*  NR5G Cell Access Status Info */
  uint8_t nr5g_cell_status_valid;  /**< Must be set to true if nr5g_cell_status is being passed */
  nas_cell_access_status_e_type_v01 nr5g_cell_status;
  /**<  
 Cell access status for NR5G calls. Values: \n
      - NAS_CELL_ACCESS_NORMAL_ONLY (0x00) --  Cell access is allowed for normal calls only \n  
      - NAS_CELL_ACCESS_EMERGENCY_ONLY (0x01) --  Cell access is allowed for emergency calls only \n  
      - NAS_CELL_ACCESS_NO_CALLS (0x02) --  Cell access is not allowed for any call type \n  
      - NAS_CELL_ACCESS_ALL_CALLS (0x03) --  Cell access is allowed for all call types \n  
      - NAS_CELL_ACCESS_UNKNOWN (-1) --  Cell access type is unknown  
 */

  /* Optional */
  /*  CP SMS Service Status Info */
  uint8_t cp_sms_service_status_valid;  /**< Must be set to true if cp_sms_service_status is being passed */
  nas_cp_sms_service_status_e_type_v01 cp_sms_service_status;
  /**<  
 SMS service status over Control Plane. Values: \n
      - NAS_CP_SMS_SERVICE_STATUS_NOT_AVAILABLE (0x00) --  SMS service status  over CP is not available \n  
      - NAS_CP_SMS_SERVICE_STATUS_TEMP_FAILURE (0x01) --  SMS service status  over CP is not available temporarily \n  
      - NAS_CP_SMS_SERVICE_STATUS_AVAILABLE (0x02) --  SMS service status  over CP is available \n  
 */

  /* Optional */
  /*  Additional LTE System Info - Availability of Dual connectivity of E-UTRA with NR5G */
  uint8_t endc_available_valid;  /**< Must be set to true if endc_available is being passed */
  uint8_t endc_available;
  /**<  
       Upper layer indication in LTE SIB2. Values: \n
       - 0x00 --  5G Not available \n
       - 0x01 --  5G Available
    */

  /* Optional */
  /*  Additional LTE System Info - DCNR restriction Info */
  uint8_t restrict_dcnr_valid;  /**< Must be set to true if restrict_dcnr is being passed */
  uint8_t restrict_dcnr;
  /**<  
       DCNR restriction in NAS attach/TAU accept: \n
       - 0x00 -- Not restricted \n
       - 0x01 -- Restricted
    */

  /* Optional */
  /*  Additional NR5G System Info - NR5G Tracking Area Code */
  uint8_t nr5g_tac_info_valid;  /**< Must be set to true if nr5g_tac_info is being passed */
  nas_nr5g_tac_info_type_v01 nr5g_tac_info;

  /* Optional */
  /*  NR5G Service Area Restriction Info */
  uint8_t tracking_area_is_restricted_valid;  /**< Must be set to true if tracking_area_is_restricted is being passed */
  uint8_t tracking_area_is_restricted;
  /**<  
       Service area restriction in NAS attach/TAU accept. Values: \n
       - 0x00 -- UE registered on allowed Tracking Area \n
       - 0x01 -- UE registered on restricted Tracking Area
    */

  /* Optional */
  /*  5G SMS Registration Status Info */
  uint8_t n1_sms_is_registered_valid;  /**< Must be set to true if n1_sms_is_registered is being passed */
  uint8_t n1_sms_is_registered;
  /**<  
       SMS registration status: \n
       - 0x00 -- Not registered \n
       - 0x01 -- registered
    */

  /* Optional */
  /*  NR5G MPSI Valid Info */
  uint8_t mpsi_indicator_is_valid_valid;  /**< Must be set to true if mpsi_indicator_is_valid is being passed */
  uint8_t mpsi_indicator_is_valid;
  /**<  
       MPS indicator valid in RPLMN or equivalent PLMN: \n
       - 0x00 -- Not valid \n
       - 0x01 -- Valid
     */

  /* Optional */
  /*  Additional NR5G System Info */
  uint8_t nr5g_pci_valid;  /**< Must be set to true if nr5g_pci is being passed */
  uint16_t nr5g_pci;
  /**<  
       NR5G Physical Cell ID
   */

  /* Optional */
  /*  Additional LTE system Info - PLMN Info List R15 availability */
  uint8_t plmn_infolist_r15_available_valid;  /**< Must be set to true if plmn_infolist_r15_available is being passed */
  uint8_t plmn_infolist_r15_available;
  /**<  
       - 0x00 -- SIB2 doesn't have plmn-InfoList-r15 IE \n
       - 0x01 -- SIB2 has plmn-InfoList-r15 IE
      */

  /* Optional */
  /*  IMS Vops Support Status on NR5G */
  uint8_t nr5g_ims_voice_avail_valid;  /**< Must be set to true if nr5g_ims_voice_avail is being passed */
  nas_nr5g_vops_support_enum_type_v01 nr5g_ims_voice_avail;
  /**<   
 NR5G vops support. Values: \n
      - NAS_NR5G_IMS_VOPS_NOT_SUPPORTED (0) --  IMS voice over PS session not supported 
      - NAS_NR5G_IMS_VOPS_SUPPORTED_3GPP (1) --  IMS voice over PS session supported over 3GPP access 
      - NAS_NR5G_IMS_VOPS_SUPPORTED_NON_3GPP (2) --  IMS voice over PS session supported over non-3GPP access
 */

  /* Optional */
  /*  NR5G Voice Domain */
  uint8_t nr5g_voice_domain_valid;  /**< Must be set to true if nr5g_voice_domain is being passed */
  nas_nr5g_voice_domain_enum_type_v01 nr5g_voice_domain;
  /**<  
 NR5G voice domain. Values: \n
      - NAS_NR5G_VOICE_DOMAIN_NO_VOICE (0) --  Data centric devices: No voice, stay on NR5G 
      - NAS_NR5G_VOICE_DOMAIN_IMS (1) --  Voice is supported over IMS network 
 */

  /* Optional */
  /*  NR5G SMS Domain */
  uint8_t nr5g_sms_domain_valid;  /**< Must be set to true if nr5g_sms_domain is being passed */
  nas_sms_status_enum_type_v01 nr5g_sms_domain;
  /**<  
 NR5G SMS domain. Values: \n
      - NAS_SMS_STATUS_NO_SMS (0) --  Data centric devices: No sms, stay on network 
      - NAS_SMS_STATUS_IMS (1) --  SMS is supported over IMS network 
      - NAS_SMS_STATUS_1X (2) --  SMS is supported over 1X network 
      - NAS_SMS_STATUS_3GPP (3) --  SMS is supported over 3GPP network 
 */

  /* Optional */
  /*  NR5G Voice Support Sys Info */
  uint8_t voice_support_on_nr5g_valid;  /**< Must be set to true if voice_support_on_nr5g is being passed */
  uint8_t voice_support_on_nr5g;
  /**<  
    Indicates voice support status on NR5G. Values: \n
    - 0x00 -- Voice is not supported \n
    - 1x01 -- Voice is supported
   */
}nas_sys_info_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Queries information regarding the signal strength.
               \label{idl:getSigInfo} */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_sig_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  RSSI */
  int8_t rssi;
  /**<  
      RSSI in dBm (signed value); a value of -125 dBm or lower is
      used to indicate No Signal: \n 
      - For CDMA, this indicates forward link pilot Power (AGC) + Ec/Io \n
      - For UMTS, this indicates forward link pilot Ec   \n
      - For GSM, this indicates received signal strength
  */

  /*  ECIO */
  int16_t ecio;
  /**<  
      ECIO value representing negative 0.5 dB increments, i.e., 
      2 means -1 dB (14 means -7 dB, 63 means -31.5 dB).
  */
}nas_common_sig_info_param_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_common_sig_info_param_type_v01 common_sig_str;

  /*  SINR */
  nas_sinr_enum_v01 sinr;
  /**<   
     SINR level. SINR is only applicable for 1xEV-DO. 
     Valid levels are 0 to 8, where the maximum value for:        \n
     - 0x00 -- SINR_LEVEL_0 is -9 dB     \n
     - 0x01 -- SINR_LEVEL_1 is -6 dB     \n
     - 0x02 -- SINR_LEVEL_2 is -4.5 dB   \n
     - 0x03 -- SINR_LEVEL_3 is -3 dB     \n
     - 0x04 -- SINR_LEVEL_4 is -2 dB     \n
     - 0x05 -- SINR_LEVEL_5 is +1 dB     \n
     - 0x06 -- SINR_LEVEL_6 is +3 dB     \n
     - 0x07 -- SINR_LEVEL_7 is +6 dB     \n
     - 0x08 -- SINR_LEVEL_8 is +9 dB
 */

  /*  IO */
  int32_t io;
  /**<  
     Received IO in dBm. IO is only applicable for 1xEV-DO. 
 */
}nas_hdr_sig_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  RSSI */
  int8_t rssi;
  /**<  
     RSSI in dBm (signed value); a value of -125 dBm or lower is
     used to indicate No Signal: \n 
     - For CDMA and UMTS, this indicates forward link pilot Ec   \n
     - For GSM, this indicates received signal strength
 */

  /*  RSRQ */
  int8_t rsrq;
  /**<  
     RSRQ value in dB (signed integer value) as measured by L1. 
     Range: -3 to -20 (-3 means -3 dB, -20 means -20 dB). 
 */

  /*  RSRP */
  int16_t rsrp;
  /**<  
     Current RSRP in dBm as measured by L1. 
     Range: -44 to -140 (-44 means -44 dBm, -140 means -140 dBm).
 */

  /*  SNR */
  int16_t snr;
  /**<   
     SNR level as a scaled integer in units of 0.1 dB; 
     e.g., -16 dB has a value of -160 and 24.6 dB has a value of 246.
 */
}nas_lte_sig_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  RSSI */
  float rssi;
  /**<  
      Measured RSSI in dBm. 
  */

  /*  RSCP */
  float rscp;
  /**<  
      Measured RSCP in dBm.  
  */

  /*  ECIO */
  float ecio;
  /**<  
      Measured ECIO in dB.
  */

  /*  SINR */
  float sinr;
  /**<   
      Measured SINR in dB. -15 dB is sent to clients if the actual SINR is 
      less than -15 dB.
  */
}nas_tdscdma_sig_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  RSRP */
  int16_t rsrp;
  /**<  
     Current RSRP in dBm as measured by L1. 
     Range: -44 to -140 (-44 means -44 dBm, -140 means -140 dBm).
	 Invalid value (-32768) indicates that modem is not in EN-DC connected mode.
 */

  /*  SNR */
  int16_t snr;
  /**<   
     SNR level as a scaled integer in units of 0.1 dB; 
     e.g., -16 dB has a value of -160 and 24.6 dB has a value of 246.
	 Invalid value (-32768) indicates that modem is not in EN-DC connected mode.
 */
}nas_nr5g_sig_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Queries information regarding the signal strength.
               \label{idl:getSigInfo} */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  CDMA Signal Strength Info */
  uint8_t cdma_sig_info_valid;  /**< Must be set to true if cdma_sig_info is being passed */
  nas_common_sig_info_param_type_v01 cdma_sig_info;

  /* Optional */
  /*  HDR Signal Strength Info */
  uint8_t hdr_sig_info_valid;  /**< Must be set to true if hdr_sig_info is being passed */
  nas_hdr_sig_info_type_v01 hdr_sig_info;

  /* Optional */
  /*  GSM Signal Strength Info */
  uint8_t gsm_sig_info_valid;  /**< Must be set to true if gsm_sig_info is being passed */
  int8_t gsm_sig_info;
  /**<  
    GSM signal strength is the RSSI in dBm (signed value). 
    A value of -125 dBm or lower is used to indicate No Signal.
  */

  /* Optional */
  /*  WCDMA Signal Strength Info */
  uint8_t wcdma_sig_info_valid;  /**< Must be set to true if wcdma_sig_info is being passed */
  nas_common_sig_info_param_type_v01 wcdma_sig_info;

  /* Optional */
  /*  LTE Signal Strength Info */
  uint8_t lte_sig_info_valid;  /**< Must be set to true if lte_sig_info is being passed */
  nas_lte_sig_info_type_v01 lte_sig_info;

  /* Optional */
  /*  TDSCDMA Signal Strength Info */
  uint8_t rscp_valid;  /**< Must be set to true if rscp is being passed */
  int8_t rscp;
  /**<  
    RSCP of the Primary Common Control Physical Channel (PCCPCH) in dBm. 
    Measurement range: -120 dBm to -25 dBm. 
  */

  /* Optional */
  /*  TDSCDMA Signal Strength Info Extended */
  uint8_t tdscdma_sig_info_valid;  /**< Must be set to true if tdscdma_sig_info is being passed */
  nas_tdscdma_sig_info_type_v01 tdscdma_sig_info;

  /* Optional */
  /*  5G Signal Strength Info */
  uint8_t nr5g_sig_info_valid;  /**< Must be set to true if nr5g_sig_info is being passed */
  nas_nr5g_sig_info_type_v01 nr5g_sig_info;

  /* Optional */
  /*  5G Signal Strength Info - Extended */
  uint8_t nr5g_rsrq_valid;  /**< Must be set to true if nr5g_rsrq is being passed */
  int16_t nr5g_rsrq;
  /**<  
     RSRQ value in dB (signed integer value) as measured by L1.       
	 Invalid value (-32768) indicates that modem is not in EN-DC connected mode.
 */
}nas_get_sig_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_LTE_SIG_RPT_RATE_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_LTE_SIG_RPT_RATE_DEFAULT_V01 = 0, 
  NAS_LTE_SIG_RPT_RATE_1_SEC_V01 = 1, 
  NAS_LTE_SIG_RPT_RATE_2_SEC_V01 = 2, 
  NAS_LTE_SIG_RPT_RATE_3_SEC_V01 = 3, 
  NAS_LTE_SIG_RPT_RATE_4_SEC_V01 = 4, 
  NAS_LTE_SIG_RPT_RATE_5_SEC_V01 = 5, 
  NAS_LTE_SIG_RPT_RATE_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_lte_sig_rpt_rate_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_LTE_SIG_AVG_PRD_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_LTE_SIG_AVG_PRD_DEFAULT_V01 = 0, 
  NAS_LTE_SIG_AVG_PRD_1_SEC_V01 = 1, 
  NAS_LTE_SIG_AVG_PRD_2_SEC_V01 = 2, 
  NAS_LTE_SIG_AVG_PRD_3_SEC_V01 = 3, 
  NAS_LTE_SIG_AVG_PRD_4_SEC_V01 = 4, 
  NAS_LTE_SIG_AVG_PRD_5_SEC_V01 = 5, 
  NAS_LTE_SIG_AVG_PRD_6_SEC_V01 = 6, 
  NAS_LTE_SIG_AVG_PRD_7_SEC_V01 = 7, 
  NAS_LTE_SIG_AVG_PRD_8_SEC_V01 = 8, 
  NAS_LTE_SIG_AVG_PRD_9_SEC_V01 = 9, 
  NAS_LTE_SIG_AVG_PRD_10_SEC_V01 = 10, 
  NAS_LTE_SIG_AVG_PRD_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_lte_sig_avg_prd_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Report rate */
  nas_lte_sig_rpt_rate_enum_type_v01 rpt_rate;
  /**<  
      Rate on how often the LTE signal must be checked for reporting. Values: \n
      - 0 -- Report using the default configuration \n
      - 1 -- Report every 1 sec \n
      - 2 -- Report every 2 sec \n
      - 3 -- Report every 3 sec \n
      - 4 -- Report every 4 sec \n
      - 5 -- Report every 5 sec 
   */

  /*  Averaging period */
  nas_lte_sig_avg_prd_enum_type_v01 avg_period;
  /**<  
      Averaging period to be used for the LTE signal. Values: \n
      - 0  -- Average using the default configuration \n
      - 1  -- Average over 1 sec \n
      - 2  -- Average over 2 sec \n
      - 3  -- Average over 3 sec \n
      - 4  -- Average over 4 sec \n
      - 5  -- Average over 5 sec \n
      - 6  -- Average over 6 sec \n
      - 7  -- Average over 7 sec \n
      - 8  -- Average over 8 sec \n
      - 9  -- Average over 9 sec \n
      - 10 -- Average over 10 sec
   */
}nas_lte_sig_rpt_config_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets the signal strength reporting thresholds. (Deprecated) */
typedef struct {

  /* Optional */
  /*  RSSI Threshold List  */
  uint8_t rssi_threshold_list_valid;  /**< Must be set to true if rssi_threshold_list is being passed */
  uint32_t rssi_threshold_list_len;  /**< Must be set to # of elements in rssi_threshold_list */
  int8_t rssi_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX_V01];
  /**<  
      RSSI in 1 dBm. A value of -125 dBm or lower is used to indicate 
      No Signal. RSSI values have the following ranges (in dBm): \n
      - CDMA:  -105 to -21 \n
      - HDR:   -118 to -13 \n
      - GSM:   -111 to -48 \n
      - WCDMA: -121 to 0   \n
      - LTE:   -120 to 0   \n
      The threshold values specified here are used for all RATs. The 
      maximum number of threshold values is 16, each a signed byte 
      value.                                                      \n \vspace{-.12in}

      For CDMA and UMTS, this threshold setting results in the 
      forward link pilot Ec values to be reported as part of the rssi
      field in TLV corresponding to the RAT in the QMI_NAS_SIG_INFO_IND
      indication.                                                 \n \vspace{-.12in}

      For GSM, this threshold setting results in the received 
      signal strength to be reported as part of the GSM Signal Strength Info 
      TLV in the QMI_NAS_SIG_INFO_IND indication.                 \n \vspace{-.12in}

      The range is based on the latest releases and may change over time.
 */

  /* Optional */
  /*  ECIO Threshold List */
  uint8_t ecio_threshold_list_valid;  /**< Must be set to true if ecio_threshold_list is being passed */
  uint32_t ecio_threshold_list_len;  /**< Must be set to # of elements in ecio_threshold_list */
  int16_t ecio_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX_V01];
  /**<  
      A sequence of thresholds delimiting ECIO event reporting bands.
      Every time a new ECIO value crosses a threshold value, an event
      report indication message with the new ECIO value is sent to the
      requesting control point. For this field: \n

      - Each ECIO threshold value is a signed 2 byte value \n
      - Each ECIO threshold value increments in negative 0.5 dB, 
        e.g., an ECIO threshold value of 2 means -1 dB. \n
      - Maximum number of threshold values is 16        \n
      - At least one value must be specified (if report_ecio is set) \n
      - Threshold values specified here are used for all RATs
  */

  /* Optional */
  /*  HDR SINR Threshold List */
  uint8_t hdr_sinr_threshold_list_valid;  /**< Must be set to true if hdr_sinr_threshold_list is being passed */
  uint32_t hdr_sinr_threshold_list_len;  /**< Must be set to # of elements in hdr_sinr_threshold_list */
  uint8_t hdr_sinr_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX_V01];
  /**<  
      A sequence of thresholds delimiting SINR event reporting bands.
      Every time a new SINR value crosses a threshold value, an event
      report indication message with the new SINR value is sent to the
      requesting control point. For this field: \n
      
      - SINR is reported only for HDR \n
      - Each SINR threshold value is an unsigned 1 byte value \n
      - Maximum number of threshold values is 16              \n
      - At least one value must be specified (if report_sinr is set)
   */

  /* Optional */
  /*  LTE SNR Threshold List */
  uint8_t lte_snr_threshold_list_valid;  /**< Must be set to true if lte_snr_threshold_list is being passed */
  uint32_t lte_snr_threshold_list_len;  /**< Must be set to # of elements in lte_snr_threshold_list */
  int16_t lte_snr_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX_V01];
  /**<  
      A sequence of thresholds delimiting SNR event reporting bands.
      Every time a new SNR value crosses a threshold value, an event
      report indication message with the new snr value is sent to the
      requesting control point. For this field: \n

      - For LTE, each SNR threshold value is a signed 2 byte value  \n
      - Maximum number of threshold values is 16                    \n 
      - At least one value must be specified (if report_snr is set) \n
      - SNR level as a scaled integer in units of 0.1 dB; 
        e.g., -16 dB has a value of -160 and 24.6 dB has a value of 246
  
   */

  /* Optional */
  /*  IO Threshold List */
  uint8_t io_threshold_list_valid;  /**< Must be set to true if io_threshold_list is being passed */
  uint32_t io_threshold_list_len;  /**< Must be set to # of elements in io_threshold_list */
  int32_t io_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX_V01];
  /**<  
      A sequence of thresholds delimiting IO event reporting bands.
      Every time a new IO value crosses a threshold value, an event
      report indication message with the new IO value is sent to the
      requesting control point. For this field: \n
      
      - IO is applicable only for HDR \n
      - Each IO threshold value is a signed 4 byte value \n
      - Maximum number of threshold values is 16         \n
      - At least one value must be specified
 */

  /* Optional */
  /*  RSRQ Threshold List */
  uint8_t lte_rsrq_threshold_list_valid;  /**< Must be set to true if lte_rsrq_threshold_list is being passed */
  uint32_t lte_rsrq_threshold_list_len;  /**< Must be set to # of elements in lte_rsrq_threshold_list */
  int8_t lte_rsrq_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX_V01];
  /**<  
      A sequence of thresholds delimiting current RSRQ event reporting bands.
      Every time a new RSRQ value crosses a specified threshold value, an
      event report indication message with the new RSRQ value is sent
      to the requesting control point. For this field: \n

      - RSRQ values are applicable only for LTE \n
      - RSRQ values are measured in dBm, with a range of -20 dBm to -3 dBm \n
      - Each RSRQ threshold value is a signed byte value \n
      - Maximum number of threshold values is 16         \n
      - At least one value must be specified
 */

  /* Optional */
  /*  RSRP Threshold List */
  uint8_t lte_rsrp_threshold_list_valid;  /**< Must be set to true if lte_rsrp_threshold_list is being passed */
  uint32_t lte_rsrp_threshold_list_len;  /**< Must be set to # of elements in lte_rsrp_threshold_list */
  int16_t lte_rsrp_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX_V01];
  /**<  
      A sequence of thresholds delimiting current RSRP event reporting bands.
      Every time a new RSRP value crosses a specified threshold value, an
      event report indication message with the new RSRP value is sent
      to the requesting control point. For this field: \n

      - RSRP values are applicable only for LTE \n
      - RSRP values are measured in dBm, with a range of -44 dBm to -140 dBm \n
      - Each RSRP threshold value is a signed 2 byte value \n
      - Maximum number of threshold values is 16           \n
      - At least one value must be specified
    */

  /* Optional */
  /*  LTE Signal Report Config */
  uint8_t lte_sig_rpt_config_valid;  /**< Must be set to true if lte_sig_rpt_config is being passed */
  nas_lte_sig_rpt_config_type_v01 lte_sig_rpt_config;

  /* Optional */
  /*  RSCP Threshold List  */
  uint8_t rscp_threshold_list_valid;  /**< Must be set to true if rscp_threshold_list is being passed */
  uint32_t rscp_threshold_list_len;  /**< Must be set to # of elements in rscp_threshold_list */
  int8_t rscp_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX_V01];
  /**<  
      RSCP in 1 dBm. The threshold values specified here are used for all RATs.
   */

  /* Optional */
  /*  TDSCDMA SINR Threshold List  */
  uint8_t tds_sinr_threshold_list_valid;  /**< Must be set to true if tds_sinr_threshold_list is being passed */
  uint32_t tds_sinr_threshold_list_len;  /**< Must be set to # of elements in tds_sinr_threshold_list */
  float tds_sinr_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX_V01];
  /**<  
      Array of SINR thresholds (in dB) used by TD-SCDMA; maximum of 16 values.
  */
}nas_config_sig_info_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets the signal strength reporting thresholds. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_config_sig_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Provides any change in signal strength status.
             \label{idl:sigInfoInd} */
typedef struct {

  /* Optional */
  /*  CDMA Signal Strength Info */
  uint8_t cdma_sig_info_valid;  /**< Must be set to true if cdma_sig_info is being passed */
  nas_common_sig_info_param_type_v01 cdma_sig_info;

  /* Optional */
  /*  HDR Signal Strength Info */
  uint8_t hdr_sig_info_valid;  /**< Must be set to true if hdr_sig_info is being passed */
  nas_hdr_sig_info_type_v01 hdr_sig_info;

  /* Optional */
  /*  GSM Signal Strength Info */
  uint8_t gsm_sig_info_valid;  /**< Must be set to true if gsm_sig_info is being passed */
  int8_t gsm_sig_info;
  /**<  
    GSM signal strength is the RSSI in dBm (signed value). 
    A value of -125 dBm or lower is used to indicate No Signal.
    */

  /* Optional */
  /*  WCDMA Signal Strength Info */
  uint8_t wcdma_sig_info_valid;  /**< Must be set to true if wcdma_sig_info is being passed */
  nas_common_sig_info_param_type_v01 wcdma_sig_info;

  /* Optional */
  /*  LTE Signal Strength Info */
  uint8_t lte_sig_info_valid;  /**< Must be set to true if lte_sig_info is being passed */
  nas_lte_sig_info_type_v01 lte_sig_info;

  /* Optional */
  /*  TDSCDMA Signal Strength Info */
  uint8_t rscp_valid;  /**< Must be set to true if rscp is being passed */
  int8_t rscp;
  /**<  
    RSCP of the PCCPCH in dBm. 
    Measurement range: -120 dBm to -25 dBm. 
  */

  /* Optional */
  /*  TDSCDMA Signal Strength Info Extended */
  uint8_t tdscdma_sig_info_valid;  /**< Must be set to true if tdscdma_sig_info is being passed */
  nas_tdscdma_sig_info_type_v01 tdscdma_sig_info;

  /* Optional */
  /*  5G Signal Strength Info */
  uint8_t nr5g_sig_info_valid;  /**< Must be set to true if nr5g_sig_info is being passed */
  nas_nr5g_sig_info_type_v01 nr5g_sig_info;

  /* Optional */
  /*  5G Signal Strength Info - Extended */
  uint8_t nr5g_rsrq_valid;  /**< Must be set to true if nr5g_rsrq is being passed */
  int16_t nr5g_rsrq;
  /**<  
     RSRQ value in dB (signed integer value) as measured by L1.       
	 Invalid value (-32768) indicates that modem is not in EN-DC connected mode.
 */
}nas_sig_info_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Queries the current error rate information. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_err_rate_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Queries the current error rate information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  CDMA Frame Error Rate */
  uint8_t cdma_frame_err_rate_valid;  /**< Must be set to true if cdma_frame_err_rate is being passed */
  uint16_t cdma_frame_err_rate;
  /**<  
      Valid error rate values between 1 and 10000 are returned to 
      indicate the percentage, e.g., a value of 300 means the error rate is 3%. 
      A value of 0xFFFF indicates that the error rate is unknown/unavailable.
  */

  /* Optional */
  /*  HDR Packet Error Rate */
  uint8_t hdr_packet_err_rate_valid;  /**< Must be set to true if hdr_packet_err_rate is being passed */
  uint16_t hdr_packet_err_rate;
  /**<  
      Valid error rate values between 1 and 10000 are returned to 
      indicate the percentage, e.g., a value of 300 means the error rate is 3%. 
      A value of 0xFFFF indicates that the error rate is unknown/unavailable. 
  */

  /* Optional */
  /*  GSM Bit Error Rate */
  uint8_t gsm_bit_err_rate_valid;  /**< Must be set to true if gsm_bit_err_rate is being passed */
  uint8_t gsm_bit_err_rate;
  /**<  
      GSM bit error rate represented as an RxQual metric as defined in 
      \hyperref[STD-45008]{3GPP TS 45.008} Section 8.2.4. Valid values: 0 to 7. 
      A value of 0xFF indicates No Data.
  */

  /* Optional */
  /*  WCDMA Block Error Rate */
  uint8_t wcdma_block_err_rate_valid;  /**< Must be set to true if wcdma_block_err_rate is being passed */
  uint8_t wcdma_block_err_rate;
  /**<  
      Valid error rate values between 1 and 100 are returned to 
      indicate the percentage value. A value of 0xFF indicates
      that the error rate is unknown/unavailable.
  */

  /* Optional */
  /*  TDSCDMA Block Error Rate */
  uint8_t tdscdma_block_err_rate_valid;  /**< Must be set to true if tdscdma_block_err_rate is being passed */
  uint8_t tdscdma_block_err_rate;
  /**<  
      Percentage of blocks that had errors. A value of 0xFF indicates 
      that the error rate is unknown/unavailable.
  */
}nas_get_err_rate_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Provides RAT-specific error rate information.
             \label{idl:errRateInd} */
typedef struct {

  /* Optional */
  /*  CDMA Frame Error Rate */
  uint8_t cdma_frame_err_rate_valid;  /**< Must be set to true if cdma_frame_err_rate is being passed */
  uint16_t cdma_frame_err_rate;
  /**<  
      Valid error rate values between 1 and 10000 are returned to 
      indicate the percentage, e.g., a value of 300 means the error rate is 3%. 
      A value of 0xFFFF indicates that the error rate is unknown/unavailable.
  */

  /* Optional */
  /*  HDR Packet Error Rate */
  uint8_t hdr_packet_err_rate_valid;  /**< Must be set to true if hdr_packet_err_rate is being passed */
  uint16_t hdr_packet_err_rate;
  /**<  
      Valid error rate values between 1 and 10000 are returned to 
      indicate the percentage, e.g., a value of 300 means the error rate is 3%. 
      A value of 0xFFFF indicates that the error rate is unknown/unavailable.
  */

  /* Optional */
  /*  GSM Bit Error Rate */
  uint8_t gsm_bit_err_rate_valid;  /**< Must be set to true if gsm_bit_err_rate is being passed */
  uint8_t gsm_bit_err_rate;
  /**<  
      GSM bit error rate represented as an RxQual metric as defined in 
      \hyperref[STD-45008]{3GPP TS 45.008} Section 8.2.4. Valid values: 0 to 7. 
      A value of 0xFF indicates No Data.
  */

  /* Optional */
  /*  WCDMA Block Error Rate */
  uint8_t wcdma_block_err_rate_valid;  /**< Must be set to true if wcdma_block_err_rate is being passed */
  uint8_t wcdma_block_err_rate;
  /**<  
      Valid error rate values between 1 and 100 are returned to 
      indicate the percentage value. A value of 0xFF indicates
      that the error rate is unknown/unavailable.
  */

  /* Optional */
  /*  TDSCDMA Block Error Rate */
  uint8_t tdscdma_block_err_rate_valid;  /**< Must be set to true if tdscdma_block_err_rate is being passed */
  uint8_t tdscdma_block_err_rate;
  /**<  
      Percentage of blocks that had errors. A value of 0xFF indicates 
      that the error rate is unknown/unavailable.
  */
}nas_err_rate_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_HDR_SESSION_CLOSE_REASON_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_HDR_CLOSE_REASON_NEW_NETWORK_V01 = 0x00, 
  NAS_HDR_CLOSE_REASON_UATI_FAIL_V01 = 0x01, 
  NAS_HDR_CLOSE_REASON_KA_EXP_V01 = 0x02, 
  NAS_HDR_CLOSE_REASON_DEACTIVATE_V01 = 0x03, 
  NAS_HDR_CLOSE_REASON_REPLY_V01 = 0x04, 
  NAS_HDR_CLOSE_REASON_CONN_OPEN_FAIL_V01 = 0x05, 
  NAS_HDR_CLOSE_REASON_CFG_MSG_FAIL_V01 = 0x06, 
  NAS_HDR_CLOSE_REASON_CFG_RSP_EXP_V01 = 0x07, 
  NAS_HDR_CLOSE_REASON_PROT_NEG_FAIL_V01 = 0x08, 
  NAS_HDR_CLOSE_REASON_AN_INIT_EXP_V01 = 0x09, 
  NAS_HDR_CLOSE_REASON_QUICK_FAILURE_V01 = 0x0A, 
  NAS_HDR_CLOSE_REASON_CONN_OPEN_DENY_V01 = 0x0B, 
  NAS_HDR_CLOSE_REASON_SILENT_DEACTIVATE_V01 = 0x0C, 
  NAS_HDR_CLOSE_REASON_NEW_ESN_V01 = 0x0D, 
  NAS_HDR_CLOSE_REASON_AN_GAUP_FAIL_V01 = 0x0E, 
  NAS_HDR_CLOSE_REASON_PERSONALITY_INDEX_INVALID_V01 = 0x0F, 
  NAS_HDR_CLOSE_REASON_NOT_MAINT_UATI_V01 = 0x10, 
  NAS_HDR_CLOSE_REASON_NEW_NAI_V01 = 0x11, 
  NAS_HDR_CLOSE_REASON_EHRPD_CREDENTIALS_CHANGED_V01 = 0x12, 
  NAS_HDR_SESSION_CLOSE_REASON_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_hdr_session_close_reason_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates when an HDR session has closed and returns a 
               close reason. */
typedef struct {

  /* Mandatory */
  /*  HDR Session Close Reason */
  nas_hdr_session_close_reason_type_v01 close_reason;
  /**<   HDR session close reason (see Table @latexonly\ref{tbl:closeReason}@endlatexonly 
       for details). */
}nas_hdr_session_close_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates when an HDR unique access terminal identifier has been 
             updated and returns its new value. */
typedef struct {

  /* Mandatory */
  /*  HDR UATI */
  uint8_t uati[QMI_NAS_UATI_LENGTH_V01];
  /**<  
      A 128-bit address that includes the access terminal identifier 
      and subnet ID.
    */
}nas_hdr_uati_update_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the current HDR protocol subtype. */
typedef struct {

  /* Mandatory */
  /*  Protocol */
  uint32_t protocol;
  /**<   HDR protocol for which the subtype is requested (refer to 
       \hyperref[STD-CS0024B]{3GPP2 C.S0024-B} Table 2.5.4-1).
  */
}nas_get_hdr_subtype_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the current HDR protocol subtype. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  Protocol Subtype */
  uint8_t subtype_valid;  /**< Must be set to true if subtype is being passed */
  uint16_t subtype;
  /**<   Current HDR protocol subtype (refer to 
       \hyperref[STD-CS0024B]{3GPP2 C.S0024-B} Table 6.4.7.1-1). Values: \n
       - 0x0000 -- Default \n
       - 0x0000 to 0XFFFD -- Protocol subtypes \n
       - 0xFFFE -- Hardlink \n
       - 0xFFFF -- Indicates that the input protocol ID is not valid
   */
}nas_get_hdr_subtype_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the HDR color code value. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_hdr_color_code_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the HDR color code value. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  Color Code Value */
  uint8_t color_code_valid;  /**< Must be set to true if color_code is being passed */
  uint8_t color_code;
  /**<   Color code corresponding to the sector to which the AT is sending the 
       access probe (refer to 
       \hyperref[STD-CS0024B]{3GPP2 C.S0024-B} Section 7.11.6.2.1).
  */
}nas_get_hdr_color_code_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the current acquisition system mode. (Deprecated) */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_current_acq_sys_mode_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_SYS_MODE_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_SYS_MODE_NO_SERVICE_V01 = 0x00, 
  NAS_SYS_MODE_ACQUIRING_V01 = 0x01, 
  NAS_SYS_MODE_INSERVICE_V01 = 0x02, 
  NAS_SYS_MODE_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_sys_mode_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the current acquisition system mode. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  Current System Mode for CDMA 1X */
  uint8_t cdma_valid;  /**< Must be set to true if cdma is being passed */
  nas_sys_mode_type_v01 cdma;
  /**<   Radio interface system mode. Values: \n
       - 0x00 -- NAS_SYS_MODE_NO_SERVICE -- No service \n
       - 0x01 -- NAS_SYS_MODE_ACQUIRING  -- Acquiring service \n
       - 0x02 -- NAS_SYS_MODE_INSERVICE  -- In service
  */

  /* Optional */
  /*  Current System Mode for CDMA 1xEV-DO */
  uint8_t cdma_evdo_valid;  /**< Must be set to true if cdma_evdo is being passed */
  nas_sys_mode_type_v01 cdma_evdo;
  /**<   Radio interface system mode. Values: \n
       - 0x00 -- NAS_SYS_MODE_NO_SERVICE -- No service \n
       - 0x01 -- NAS_SYS_MODE_ACQUIRING  -- Acquiring service \n
       - 0x02 -- NAS_SYS_MODE_INSERVICE  -- In service
  */

  /* Optional */
  /*  Current System Mode for GSM */
  uint8_t gsm_valid;  /**< Must be set to true if gsm is being passed */
  nas_sys_mode_type_v01 gsm;
  /**<   Radio interface system mode. Values: \n
       - 0x00 -- NAS_SYS_MODE_NO_SERVICE -- No service \n
       - 0x01 -- NAS_SYS_MODE_ACQUIRING  -- Acquiring service \n
       - 0x02 -- NAS_SYS_MODE_INSERVICE  -- In service
  */

  /* Optional */
  /*  Current System Mode for UMTS */
  uint8_t umts_valid;  /**< Must be set to true if umts is being passed */
  nas_sys_mode_type_v01 umts;
  /**<   Radio interface system mode. Values: \n
       - 0x00 -- NAS_SYS_MODE_NO_SERVICE -- No service \n
       - 0x01 -- NAS_SYS_MODE_ACQUIRING  -- Acquiring service \n
       - 0x02 -- NAS_SYS_MODE_INSERVICE  -- In service
  */

  /* Optional */
  /*  Current System Mode for LTE */
  uint8_t lte_valid;  /**< Must be set to true if lte is being passed */
  nas_sys_mode_type_v01 lte;
  /**<   Radio interface system mode. Values: \n
       - 0x00 -- NAS_SYS_MODE_NO_SERVICE -- No service \n
       - 0x01 -- NAS_SYS_MODE_ACQUIRING  -- Acquiring service \n
       - 0x02 -- NAS_SYS_MODE_INSERVICE  -- In service
  */

  /* Optional */
  /*  Current System Mode for TDSCDMA */
  uint8_t tdscdma_valid;  /**< Must be set to true if tdscdma is being passed */
  nas_sys_mode_type_v01 tdscdma;
  /**<   Radio interface system mode. Values: \n
       - 0x00 -- NAS_SYS_MODE_NO_SERVICE -- No service \n
       - 0x01 -- NAS_SYS_MODE_ACQUIRING  -- Acquiring service \n
       - 0x02 -- NAS_SYS_MODE_INSERVICE  -- In service
  */
}nas_get_current_acq_sys_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Radio interface */
  nas_radio_if_enum_v01 radio_if;
  /**<   Radio interface for which to set the Rx diversity. Values: \n
    - 0x01 -- NAS_RADIO_IF_CDMA_1X     -- 
      cdma2000\textsuperscript{\textregistered} 1X             \n
    - 0x02 -- NAS_RADIO_IF_CDMA_1XEVDO -- 
      cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
    - 0x04 -- NAS_RADIO_IF_GSM         -- GSM \n
    - 0x05 -- NAS_RADIO_IF_UMTS        -- UMTS \n
    - 0x08 -- NAS_RADIO_IF_LTE         -- LTE
  */

  /*  Rx chain setting bitmask */
  uint8_t rx_chain_bitmask;
  /**<   Rx chain setting bitmask. Values: \n
    - Bit 0 -- Rx chain 0 setting; 0 is disable, 1 is enable \n
    - Bit 1 -- Rx chain 1 setting; 0 is disable, 1 is enable \n
    - All other bits are set to zero
   */
}nas_set_rx_diversity_req_param_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets the Rx diversity. */
typedef struct {

  /* Mandatory */
  /*  Rx Diversity Setting */
  nas_set_rx_diversity_req_param_type_v01 req_param;
}nas_set_rx_diversity_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets the Rx diversity. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_rx_diversity_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the detailed Tx/Rx information. */
typedef struct {

  /* Mandatory */
  /*  Radio Interface */
  nas_radio_if_enum_v01 radio_if;
  /**<  
    Radio interface from which to get the information. Values: \n
    - 0x01 -- NAS_RADIO_IF_CDMA_1X     -- 
      cdma2000\textsuperscript{\textregistered} 1X             \n
    - 0x02 -- NAS_RADIO_IF_CDMA_1XEVDO -- 
      cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
    - 0x04 -- NAS_RADIO_IF_GSM         -- GSM \n
    - 0x05 -- NAS_RADIO_IF_UMTS        -- UMTS \n
    - 0x08 -- NAS_RADIO_IF_LTE         -- LTE \n
    - 0x09 -- NAS_RADIO_IF_TDSCDMA     -- TD-SCDMA
  */
}nas_get_tx_rx_info_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t is_radio_tuned;
  /**<   Whether Rx is tuned to a channel: \n
       - 0x00 -- Not tuned \n
       - 0x01 -- Tuned \n
       If the radio is tuned, instantaneous values are set for the signal 
       information fields below. If the radio is not tuned, or is delayed or 
       invalid, the values are set depending on each technology.
   */

  int32_t rx_pwr;
  /**<   Rx power value in 1/10 dbm resolution. */

  int32_t ecio;
  /**<   ECIO in 1/10 dB; valid for CDMA, HDR, GSM, WCDMA, and LTE. */

  int32_t rscp;
  /**<   Received signal code power in 1/10 dbm; valid for WCDMA. */

  int32_t rsrp;
  /**<   Current reference signal received power in 1/10 dbm; valid for LTE. */

  uint32_t phase;
  /**<   Phase in 1/100 degrees; valid for LTE. When the phase is unknown, 
       0xFFFFFFFF is used. 
  */
}nas_rx_chain_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_LTE_MODULATION_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  CMAPI_LTE_API_MODULATION_BPSK_V01 = 0x00, /**<  BPSK \n  */
  CMAPI_LTE_API_MODULATION_QPSK_V01 = 0x01, /**<  QPSK \n  */
  CMAPI_LTE_API_MODULATION_16QAM_V01 = 0x02, /**<  16-QAM \n  */
  CMAPI_LTE_API_MODULATION_64QAM_V01 = 0x03, /**<  64-QAM  */
  NAS_LTE_MODULATION_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_lte_modulation_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t is_in_traffic;
  /**<   Whether the device is in traffic. The tx_pwr field is only 
       meaningful when in the device is in traffic. If it is not in traffic, 
       tx_pwr is invalid.
   */

  int32_t tx_pwr;
  /**<   Tx power value in 1/10 dbm. */
}nas_tx_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the detailed Tx/Rx information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  Rx Chain 0 Info */
  uint8_t rx_chain_0_valid;  /**< Must be set to true if rx_chain_0 is being passed */
  nas_rx_chain_info_type_v01 rx_chain_0;

  /* Optional */
  /*  Rx Chain 1 Info */
  uint8_t rx_chain_1_valid;  /**< Must be set to true if rx_chain_1 is being passed */
  nas_rx_chain_info_type_v01 rx_chain_1;

  /* Optional */
  /*  Tx Info */
  uint8_t tx_valid;  /**< Must be set to true if tx is being passed */
  nas_tx_info_type_v01 tx;

  /* Optional */
  /*  LTE Downlink Modulation */
  uint8_t downlink_mod_valid;  /**< Must be set to true if downlink_mod is being passed */
  uint32_t downlink_mod_len;  /**< Must be set to # of elements in downlink_mod */
  nas_lte_modulation_enum_type_v01 downlink_mod[NAS_LTE_MODULATIONS_MAX_V01];
  /**<   LTE downlink modulation. Values: \n
      - CMAPI_LTE_API_MODULATION_BPSK (0x00) --  BPSK \n 
      - CMAPI_LTE_API_MODULATION_QPSK (0x01) --  QPSK \n 
      - CMAPI_LTE_API_MODULATION_16QAM (0x02) --  16-QAM \n 
      - CMAPI_LTE_API_MODULATION_64QAM (0x03) --  64-QAM 
 */

  /* Optional */
  /*  LTE Uplink Modulation */
  uint8_t uplink_mod_valid;  /**< Must be set to true if uplink_mod is being passed */
  uint32_t uplink_mod_len;  /**< Must be set to # of elements in uplink_mod */
  nas_lte_modulation_enum_type_v01 uplink_mod[NAS_LTE_MODULATIONS_MAX_V01];
  /**<   LTE uplink modulation. Values: \n
      - CMAPI_LTE_API_MODULATION_BPSK (0x00) --  BPSK \n 
      - CMAPI_LTE_API_MODULATION_QPSK (0x01) --  QPSK \n 
      - CMAPI_LTE_API_MODULATION_16QAM (0x02) --  16-QAM \n 
      - CMAPI_LTE_API_MODULATION_64QAM (0x03) --  64-QAM 
 */

  /* Optional */
  /*  Rx Chain 2 Info */
  uint8_t rx_chain_2_valid;  /**< Must be set to true if rx_chain_2 is being passed */
  nas_rx_chain_info_type_v01 rx_chain_2;

  /* Optional */
  /*  Rx Chain 3 Info */
  uint8_t rx_chain_3_valid;  /**< Must be set to true if rx_chain_3 is being passed */
  nas_rx_chain_info_type_v01 rx_chain_3;
}nas_get_tx_rx_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Service Programming Code */
  char spc[NAS_SPC_MAX_V01];
  /**<   Service programming code in ASCII format (digits 0 to 9 only).
  */

  /*  AKEY */
  uint8_t akey[QMI_NAS_AKEY_LEN_V01];
  /**<   AKEY value + checksum value in ASCII (first 20 bytes are the AKEY value,
       last 6 bytes are the checksum).
  */
}nas_akey_with_spc_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Updates the A-KEY (extended).
              \label{idl:updateAkeyExt} */
typedef struct {

  /* Mandatory */
  /*  AKEY with SPC */
  nas_akey_with_spc_type_v01 akey_with_spc;
}nas_update_akey_ext_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Updates the A-KEY (extended).
              \label{idl:updateAkeyExt} */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_update_akey_ext_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates whether managed roaming is enabled. */
typedef struct {

  /* Optional */
  /*  Radio Interface */
  uint8_t radio_if_valid;  /**< Must be set to true if radio_if is being passed */
  nas_radio_if_enum_v01 radio_if;
  /**<  
    Radio interface from which to get the information. Values: \n
    - 0x01 -- NAS_RADIO_IF_CDMA_1X     -- 
      cdma2000\textsuperscript{\textregistered} 1X             \n
    - 0x02 -- NAS_RADIO_IF_CDMA_1XEVDO -- 
      cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
    - 0x04 -- NAS_RADIO_IF_GSM         -- GSM \n
    - 0x05 -- NAS_RADIO_IF_UMTS        -- UMTS \n
    - 0x08 -- NAS_RADIO_IF_LTE         -- LTE \n
    - 0x09 -- NAS_RADIO_IF_TDSCDMA     -- TD-SCDMA
  */
}nas_managed_roaming_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves dual standby preference. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_dual_standby_pref_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves dual standby preference. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  Standby Preference */
  uint8_t standby_pref_valid;  /**< Must be set to true if standby_pref is being passed */
  nas_standby_pref_enum_v01 standby_pref;
  /**<   Values: \n
       -0x01 -- Single standby \n
       -0x02 -- Dual standby with tune away \n
       -0x04 -- Dual standby without tune away \n
       -0x05 -- Automatic mode with tune away where applicable \n
       -0x06 -- Automatic mode without tune away \n
       -0x07 -- Triple standby
  */

  /* Optional */
  /*  Priority Subs */
  uint8_t priority_subs_valid;  /**< Must be set to true if priority_subs is being passed */
  nas_subs_type_enum_v01 priority_subs;
  /**<   Subscription to give priority when listening to the paging channel during
 dual standby. Values: \n
      - NAS_PRIMARY_SUBSCRIPTION (0x00) --  Primary subscription \n 
      - NAS_SECONDARY_SUBSCRIPTION (0x01) --  Secondary subscription \n 
      - NAS_TERTIARY_SUBSCRIPTION (0x02) --  Tertiary subscription 
 */

  /* Optional */
  /*  Active Subs */
  uint8_t active_subs_valid;  /**< Must be set to true if active_subs is being passed */
  nas_subs_type_enum_v01 active_subs;
  /**<   Subscription to enable when "standby_pref is 0x01 -- Single standby". 
 Values: \n
      - NAS_PRIMARY_SUBSCRIPTION (0x00) --  Primary subscription \n 
      - NAS_SECONDARY_SUBSCRIPTION (0x01) --  Secondary subscription \n 
      - NAS_TERTIARY_SUBSCRIPTION (0x02) --  Tertiary subscription 
 */

  /* Optional */
  /*  Default Data Subs (Deprecated; use QMI DSD service to determine default data subscription) */
  uint8_t default_data_subs_valid;  /**< Must be set to true if default_data_subs is being passed */
  nas_subs_type_enum_v01 default_data_subs;
  /**<   Default data subscription. Values: \n
      - NAS_PRIMARY_SUBSCRIPTION (0x00) --  Primary subscription \n 
      - NAS_SECONDARY_SUBSCRIPTION (0x01) --  Secondary subscription \n 
      - NAS_TERTIARY_SUBSCRIPTION (0x02) --  Tertiary subscription 
 */

  /* Optional */
  /*  Default Voice Subs */
  uint8_t default_voice_subs_valid;  /**< Must be set to true if default_voice_subs is being passed */
  nas_subs_type_enum_v01 default_voice_subs;
  /**<   Default voice subscription. Values: \n
      - NAS_PRIMARY_SUBSCRIPTION (0x00) --  Primary subscription \n 
      - NAS_SECONDARY_SUBSCRIPTION (0x01) --  Secondary subscription \n 
      - NAS_TERTIARY_SUBSCRIPTION (0x02) --  Tertiary subscription 

 \vspace{3pt}
 All other values are reserved.
 */

  /* Optional */
  /*  Active Subs Mask */
  uint8_t active_subs_mask_valid;  /**< Must be set to true if active_subs_mask is being passed */
  nas_active_subs_mask_type_v01 active_subs_mask;
  /**<   Bitmask representing the active subscriptions in the device. If a value 
       of 0 is sent, there are no active subscriptions.
       Values: \n
       - Bit 0 (0x01) -- QMI_NAS_ACTIVE_SUB_ PRIMARY   -- Primary subscription \n
       - Bit 1 (0x02) -- QMI_NAS_ACTIVE_SUB_ SECONDARY -- Secondary subscription \n
       - Bit 2 (0x04) -- QMI_NAS_ACTIVE_SUB_ TERTIARY  -- Tertiary subscription

       \vspace{3pt}
       All unlisted bits are reserved for future use and the service point
       ignores them if used.
  */
}nas_get_dual_standby_pref_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Detaches the current LTE system. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_detach_lte_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Detaches the current LTE system. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_detach_lte_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Blocks the LTE PLMN. */
typedef struct {

  /* Mandatory */
  /*  PLMN */
  nas_plmn_id_ext_type_v01 plmn;

  /* Optional */
  /*  Blocking Interval Absolute Time */
  uint8_t blocking_interval_abs_valid;  /**< Must be set to true if blocking_interval_abs is being passed */
  uint32_t blocking_interval_abs;
  /**<   Blocking interval in absolute time (in milliseconds).
  */

  /* Optional */
  /*  Blocking Interval T3204 Multiplier */
  uint8_t blocking_interval_mult_valid;  /**< Must be set to true if blocking_interval_mult is being passed */
  float blocking_interval_mult;
  /**<   Blocking time as a multiplier of T3204.
  */

  /* Optional */
  /*  Blocking Cause */
  uint8_t blocking_cause_valid;  /**< Must be set to true if blocking_cause is being passed */
  nas_block_plmn_cause_e_type_v01 blocking_cause;
  /**<   
 PLMN Blocking Cause: \n
      - NAS_BLOCK_PLMN_CAUSE_OTHERS (0) -- 
      - NAS_BLOCK_PLMN_CAUSE_CALL_REDIAL (1) -- 
 */
}nas_block_lte_plmn_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Blocks the LTE PLMN. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_block_lte_plmn_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Unblocks the LTE PLMN. */
typedef struct {

  /* Mandatory */
  /*  PLMN */
  nas_plmn_id_ext_type_v01 plmn;

  /* Optional */
  /*  Blocking Cause */
  uint8_t blocking_cause_valid;  /**< Must be set to true if blocking_cause is being passed */
  nas_block_plmn_cause_e_type_v01 blocking_cause;
  /**<   
 PLMN Blocking Cause: \n
      - NAS_BLOCK_PLMN_CAUSE_OTHERS (0) -- 
      - NAS_BLOCK_PLMN_CAUSE_CALL_REDIAL (1) -- 
 */
}nas_unblock_lte_plmn_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Unblocks the LTE PLMN. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_unblock_lte_plmn_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Resets all previous LTE PLMN blocking operations. */
typedef struct {

  /* Optional */
  /*  Blocking Cause */
  uint8_t blocking_cause_valid;  /**< Must be set to true if blocking_cause is being passed */
  nas_block_plmn_cause_e_type_v01 blocking_cause;
  /**<   
 PLMN Blocking Cause: \n
      - NAS_BLOCK_PLMN_CAUSE_OTHERS (0) -- 
      - NAS_BLOCK_PLMN_CAUSE_CALL_REDIAL (1) -- 
 */
}nas_reset_lte_plmn_blocking_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Resets all previous LTE PLMN blocking operations. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_reset_lte_plmn_blocking_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  SPN coding scheme */
  nas_coding_scheme_enum_v01 spn_enc;
  /**<  
        Coding scheme for the service provider name. Values: \n
        - 0x00 -- NAS_CODING_SCHEME_ CELL_BROADCAST_GSM -- SMS default 7-bit coded 
                  alphabet as defined in \hyperref[STD-23038]{3GPP TS 23.038} 
                  with bit 8 set to 0 \n
        - 0x01 -- NAS_CODING_SCHEME_ UCS2 -- UCS2 (16 bit, little-endian) 
                  \hyperref[STD-23038]{3GPP TS 23.038} \n
        Note: This value is ignored if spn_len is zero.
  */

  /*  SPN */
  uint32_t spn_len;  /**< Must be set to # of elements in spn */
  uint8_t spn[NAS_SPN_LEN_MAX_V01];
  /**<  
     Service provider name string.
  */
}nas_spn_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  PLMN name encoding scheme */
  nas_coding_scheme_enum_v01 plmn_name_enc;
  /**<  
        Coding scheme for plmn_name. Values: \n
        - 0x00 -- NAS_CODING_SCHEME_ CELL_BROADCAST_GSM -- SMS default 7-bit coded 
                  alphabet as defined in \hyperref[STD-23038]{3GPP TS 23.038} 
                  with bit 8 set to 0 \n
        - 0x01 -- NAS_CODING_SCHEME_ UCS2 -- UCS2 (16 bit, little-endian) 
                  \hyperref[STD-23038]{3GPP TS 23.038} \n
        Note: This value is ignored if plmn_name_len is zero.
  */

  /*  PLMN name country initial include status */
  nas_country_initials_add_enum_v01 plmn_name_ci;
  /**<  
        Indicates whether the country initials are to be added to the plmn_name. 
        Values: \n
        - 0x00 -- Do not add the letters for the country's initials to the name \n
        - 0x01 -- Add the country's initials and a text string to the name \n
        - 0xFF -- Not specified \n
        Note: This value is ignored if plmn_name_len is zero.
  */

  /*  PLMN spare bits  */
  nas_spare_bits_enum_v01 plmn_spare_bits;
  /**<   Values: \n
       - 0x01 -- SPARE_BITS_8       -- Bit 8 is spare and set to 0 in octet n                       \n
       - 0x02 -- SPARE_BITS_7_TO_8  -- Bits 7 and 8 are spare and set to 0 in octet n               \n               
       - 0x03 -- SPARE_BITS_6_TO_8  -- Bits 6 to 8 (inclusive) are spare and set to 0 in octet n    \n
       - 0x04 -- SPARE_BITS_5_TO_8  -- Bits 5 to 8 (inclusive) are spare and set to 0 in octet n    \n
       - 0x05 -- SPARE_BITS_4_TO_8  -- Bits 4 to 8 (inclusive) are spare and set to 0 in octet n    \n
       - 0x06 -- SPARE_BITS_3_TO_8  -- Bits 3 to 8 (inclusive) are spare and set to 0 in octet n    \n
       - 0x07 -- SPARE_BITS_2_TO_8  -- Bits 2 to 8 (inclusive) are spare and set to 0 in octet n    \n
       - 0x00 -- SPARE_BITS_UNKNOWN -- Carries no information about the number of spare bits in octet n    \n
       Note: This value is ignored if plmn_name_len is zero.
  */

  uint32_t plmn_name_len;  /**< Must be set to # of elements in plmn_name */
  uint8_t plmn_name[NAS_PLMN_NAME_MAX_V01];
  /**<   PLMN name.
  */
}nas_plmn_name_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates the current SPN and PLMN name information.
             \label{idl:currPlmnNameInd} */
typedef struct {

  /* Optional */
  /*  PLMN ID */
  uint8_t plmn_id_valid;  /**< Must be set to true if plmn_id is being passed */
  nas_plmn_id_ext_type_v01 plmn_id;

  /* Optional */
  /*  Service Provider Name (Deprecated; use Service Provider Name Ext) */
  uint8_t spn_valid;  /**< Must be set to true if spn is being passed */
  nas_spn_type_v01 spn;

  /* Optional */
  /*  Short Name for Network */
  uint8_t short_name_valid;  /**< Must be set to true if short_name is being passed */
  nas_plmn_name_type_v01 short_name;

  /* Optional */
  /*  Long Name for Network */
  uint8_t long_name_valid;  /**< Must be set to true if long_name is being passed */
  nas_plmn_name_type_v01 long_name;

  /* Optional */
  /*  CSG ID for Network */
  uint8_t csg_id_valid;  /**< Must be set to true if csg_id is being passed */
  uint32_t csg_id;
  /**<   Closed subscriber group identifier; included only when the network 
       is a CSG network.
  */

  /* Optional */
  /*  Display Bit Information */
  uint8_t eons_display_bit_info_valid;  /**< Must be set to true if eons_display_bit_info is being passed */
  nas_display_bit_type_v01 eons_display_bit_info;

  /* Optional */
  /*  Network Information */
  uint8_t is_home_network_valid;  /**< Must be set to true if is_home_network is being passed */
  nas_tri_state_boolean_type_v01 is_home_network;
  /**<   Whether the network is the home network. Values: \n
      - NAS_TRI_FALSE (0) --  Status: FALSE \n 
      - NAS_TRI_TRUE (1) --  Status: TRUE  \n 
      - NAS_TRI_UNKNOWN (2) --  Status: Unknown  
 */

  /* Optional */
  /*  Radio Access Technology */
  uint8_t rat_valid;  /**< Must be set to true if rat is being passed */
  nas_radio_if_enum_v01 rat;
  /**<   Radio access technology. Values: \n
    - 0x04 -- NAS_RADIO_IF_GSM         -- GSM \n
    - 0x05 -- NAS_RADIO_IF_UMTS        -- UMTS \n
    - 0x08 -- NAS_RADIO_IF_LTE         -- LTE \n
    - 0x09 -- NAS_RADIO_IF_TDSCDMA     -- TD-SCDMA \n
    - 0x0C -- NAS_RADIO_IF_NR5G        -- NR5G
   */

  /* Optional */
  /*  3GPP EONS PLMN Name with Language ID */
  uint8_t lang_plmn_names_valid;  /**< Must be set to true if lang_plmn_names is being passed */
  uint32_t lang_plmn_names_len;  /**< Must be set to # of elements in lang_plmn_names */
  nas_lang_plmn_names_type_v01 lang_plmn_names[NAS_ALT_LANG_MAX_V01];

  /* Optional */
  /*  Additional Information */
  uint8_t addl_info_valid;  /**< Must be set to true if addl_info is being passed */
  uint32_t addl_info_len;  /**< Must be set to # of elements in addl_info */
  uint16_t addl_info[NAS_PLMN_NAME_MAX_V01];
  /**<   Additional information provided for the PLMN, in UCS2 
       (16 bit little-endian) encoded format.
  */

  /* Optional */
  /*  Network Name Source */
  uint8_t nw_name_source_valid;  /**< Must be set to true if nw_name_source is being passed */
  nas_nw_name_source_enum_type_v01 nw_name_source;
  /**<   Network name source. Values: \n
      - NAS_NW_NAME_SOURCE_UNKNOWN (0x00) --  Unknown \n 
      - NAS_NW_NAME_SOURCE_OPL_PNN (0x01) --  Operator PLMN list and PLMN network name \n 
      - NAS_NW_NAME_SOURCE_CPHS_ONS (0x02) --  Common PCN handset specification and operator name string \n 
      - NAS_NW_NAME_SOURCE_NITZ (0x03) --  Network identity and time zone \n 
      - NAS_NW_NAME_SOURCE_SE13 (0x04) --  GSMA SE13 table \n 
      - NAS_NW_NAME_SOURCE_MCC_MNC (0x05) --  Mobile country code and mobile network code \n 
      - NAS_NW_NAME_SOURCE_SPN (0x06) --  Service provider name 
 */

  /* Optional */
  /*  Service Provider Name Ext */
  uint8_t spn_ext_valid;  /**< Must be set to true if spn_ext is being passed */
  uint16_t spn_ext[NAS_SPN_EXT_LEN_MAX_V01 + 1];
  /**<   Service provider name.
  */
}nas_current_plmn_name_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Requests the UE to enable or disable eMBMS. */
typedef struct {

  /* Mandatory */
  /*  Config Request */
  uint8_t enable;
  /**<   Enable or disable eMBMS. Values: \n
       - TRUE  -- Enable \n
       - FALSE -- Disable
  */

  /* Optional */
  /*  Trace ID */
  uint8_t trace_id_valid;  /**< Must be set to true if trace_id is being passed */
  int16_t trace_id;
  /**<   Trace ID.  Values: \n
       - 0 to 32768 -- Valid trace ID \n
       - -1 -- Trace ID is not used
  */
}nas_config_embms_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Requests the UE to enable or disable eMBMS. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type.*/

  /* Optional */
  /*  Trace ID */
  uint8_t trace_id_valid;  /**< Must be set to true if trace_id is being passed */
  int16_t trace_id;
  /**<   Trace ID.  Values: \n
       - 0 to 32768 -- Valid trace ID \n
       - -1 -- Trace ID is not used
  */
}nas_config_embms_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Queries the eMBMS status. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_embms_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Queries the eMBMS status. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type.*/

  /* Optional */
  /*  eMBMS Status */
  uint8_t enabled_valid;  /**< Must be set to true if enabled is being passed */
  uint8_t enabled;
  /**<   eMBMS status. Values: \n
       - TRUE  -- Enabled \n
       - FALSE -- Disabled
  */

  /* Optional */
  /*  Trace ID */
  uint8_t trace_id_valid;  /**< Must be set to true if trace_id is being passed */
  int16_t trace_id;
  /**<   Trace ID.  Values: \n
       - 0 to 32768 -- Valid trace ID \n
       - -1 -- Trace ID is not used
  */
}nas_get_embms_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Reports the UE's current eMBMS status change. */
typedef struct {

  /* Mandatory */
  /*  eMBMS Status */
  uint8_t enabled;
  /**<   eMBMS status. Values: \n
       - TRUE  -- Enabled \n
       - FALSE -- Disabled
  */

  /* Optional */
  /*  Trace ID */
  uint8_t trace_id_valid;  /**< Must be set to true if trace_id is being passed */
  int16_t trace_id;
  /**<   Trace ID.  Values: \n
       - 0 to 32768 -- Valid trace ID \n
       - -1 -- Trace ID is not used
  */
}nas_embms_status_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Queries the current CDMA base station position information for
              active and neighbor's position information. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_cdma_position_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_CDMA_PILOT_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_CDMA_PILOT_CURR_ACT_PLT_V01 = 0x00, 
  NAS_CDMA_PILOT_NEIGHBOR_PLT_V01 = 0x01, 
  NAS_CDMA_PILOT_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_cdma_pilot_type_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_cdma_pilot_type_enum_v01 pilot_type;
  /**<   Pilot information type. Values: \n
       - 0x00 -- NAS_CDMA_PILOT_CURR_ACT_PLT -- Current active pilot information \n
       - 0x01 -- NAS_CDMA_PILOT_NEIGHBOR_PLT -- Neighbor pilot information
   */

  uint16_t sid;
  /**<   System ID. Range: 0 to 32767. 
   */

  uint16_t nid;
  /**<   Network ID. Range: 0 to 65535.
  */

  uint16_t base_id;
  /**<   Base station ID. */

  uint16_t pilot_pn;
  /**<   Pilot PN sequence offset index. Range: 0 to 511.
  */

  uint16_t pilot_strength;
  /**<   Strength of the pilot (in dB). Range: 0 to 64.
  */

  uint32_t base_lat;
  /**<   Latitude of the current base station in units of 0.25 sec.
  */

  uint32_t base_long;
  /**<   Longitude of the current base station in units of 0.25 sec.
  */

  uint64_t time_stamp;
  /**<   Time (in milliseconds) from the start of GPS time when the measurement 
       was taken.
  */
}nas_cdma_bs_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t ue_in_idle;
  /**<   CDMA Idle state. TRUE if the UE is in Idle mode; otherwise FALSE.
  */

  /*  CDMA base station info */
  uint32_t bs_len;  /**< Must be set to # of elements in bs */
  nas_cdma_bs_info_type_v01 bs[NAS_CDMA_POSITION_INFO_MAX_V01];
}nas_cdma_position_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Queries the current CDMA base station position information for
              active and neighbor's position information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type.*/

  /* Optional */
  /*  CDMA Position Info */
  uint8_t info_valid;  /**< Must be set to true if info is being passed */
  nas_cdma_position_info_type_v01 info;
}nas_get_cdma_position_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Reports current RF band information. */
typedef struct {

  /* Mandatory */
  /*  RF Band Information */
  nas_rf_band_info_type_v01 rf_band_info;

  /* Optional */
  /*  RF Dedicated Band Information List */
  uint8_t rf_dedicated_band_info_valid;  /**< Must be set to true if rf_dedicated_band_info is being passed */
  nas_rf_dedicated_band_info_type_v01 rf_dedicated_band_info;

  /* Optional */
  /*  RF Band Information List, Extended Format */
  uint8_t rf_band_info_list_ext_valid;  /**< Must be set to true if rf_band_info_list_ext is being passed */
  nas_rf_band_info_ext_type_v01 rf_band_info_list_ext;
  /**<   \n
       (Extended sizes to accommodate LTE.) 
  */

  /* Optional */
  /*  RF Bandwidth Information */
  uint8_t nas_rf_bandwidth_info_valid;  /**< Must be set to true if nas_rf_bandwidth_info is being passed */
  nas_rf_bandwidth_info_type_v01 nas_rf_bandwidth_info;

  /* Optional */
  /*  LTE Operational Mode */
  uint8_t ciot_lte_op_mode_valid;  /**< Must be set to true if ciot_lte_op_mode is being passed */
  nas_camped_ciot_lte_op_mode_enum_type_v01 ciot_lte_op_mode;
  /**<   CIOT LTE operational mode. Values: \n

      - NAS_CIOT_SYS_MODE_NO_SRV (0x00) --  No service \n 
      - NAS_CIOT_SYS_MODE_LTE_WB (0x01) --  Camped on LTE wideband \n 
      - NAS_CIOT_SYS_MODE_LTE_M1 (0x02) --  Camped on LTE M1 \n 
      - NAS_CIOT_SYS_MODE_LTE_NB1 (0x03) --  Camped on LTE NB1  
 */
}nas_rf_band_info_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Forces a network search procedure. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_force_network_search_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Forces a network search procedure. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type.*/
}nas_force_network_search_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Reports network reject information. */
typedef struct {

  /* Mandatory */
  /*  Radio Interface */
  nas_radio_if_enum_v01 radio_if;
  /**<  
    Radio interface from which to get the information. Values: \n
    - 0x04 -- NAS_RADIO_IF_GSM         -- GSM \n
    - 0x05 -- NAS_RADIO_IF_UMTS        -- UMTS \n
    - 0x08 -- NAS_RADIO_IF_LTE         -- LTE \n
    - 0x09 -- NAS_RADIO_IF_TDSCDMA     -- TD-SCDMA \n
    - 0x0C -- NAS_RADIO_IF_NR5G        -- NR5G
  */

  /* Mandatory */
  /*  Service Domain */
  nas_service_domain_enum_type_v01 reject_srv_domain;
  /**<  
    Type of service domain in which the registration is rejected. Values: \n
    - 0x00 -- SYS_SRV_DOMAIN_NO_SRV  -- No service \n
    - 0x01 -- SYS_SRV_DOMAIN_CS_ONLY -- Circuit-switched only \n
    - 0x02 -- SYS_SRV_DOMAIN_PS_ONLY -- Packet-switched only \n
    - 0x03 -- SYS_SRV_DOMAIN_CS_PS   -- Circuit-switched and packet-switched \n
    - 0x04 -- SYS_SRV_DOMAIN_CAMPED  -- Camped
      */

  /* Mandatory */
  /*  Registration Rejection Cause */
  uint8_t rej_cause;
  /**<  
    Reject cause values sent are specified in 
    \hyperref[STD-24008]{3GPP TS 24.008} Sections 10.5.3.6 and 10.5.5.14, and 
    \hyperref[STD-24301]{3GPP TS 24.301} Section 9.9.3.9.
  */

  /* Optional */
  /*  PLMN ID  */
  uint8_t plmn_id_valid;  /**< Must be set to true if plmn_id is being passed */
  nas_mnc_pcs_digit_include_status_type_v01 plmn_id;

  /* Optional */
  /*  CSG ID */
  uint8_t csg_id_valid;  /**< Must be set to true if csg_id is being passed */
  uint32_t csg_id;
  /**<   Closed subscriber group identifier.
  */

  /* Optional */
  /*  LTE Operational Mode */
  uint8_t ciot_lte_op_mode_valid;  /**< Must be set to true if ciot_lte_op_mode is being passed */
  nas_camped_ciot_lte_op_mode_enum_type_v01 ciot_lte_op_mode;
  /**<   CIOT LTE mode on which reject indication is received. Values: \n

      - NAS_CIOT_SYS_MODE_NO_SRV (0x00) --  No service \n 
      - NAS_CIOT_SYS_MODE_LTE_WB (0x01) --  Camped on LTE wideband \n 
      - NAS_CIOT_SYS_MODE_LTE_M1 (0x02) --  Camped on LTE M1 \n 
      - NAS_CIOT_SYS_MODE_LTE_NB1 (0x03) --  Camped on LTE NB1 
 */
}nas_network_reject_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Queries the current managed roaming configuration information. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_managed_roaming_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Queries the current managed roaming configuration information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type.*/

  /* Optional */
  /*  Managed Roaming Configuration */
  uint8_t managed_roaming_supported_valid;  /**< Must be set to true if managed_roaming_supported is being passed */
  uint8_t managed_roaming_supported;
  /**<   Managed roaming support status (corresponds to NV item 
       NV_MGRF_SUPPORTED_I). Values: \n
       - 0 -- Not supported \n
       - 1 -- Supported
  */
}nas_get_managed_roaming_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Reports a change in the RTRE configuration status.  */
typedef struct {

  /* Optional */
  /*  Current RTRE Configuration */
  uint8_t rtre_cfg_valid;  /**< Must be set to true if rtre_cfg is being passed */
  nas_rtre_cfg_enum_v01 rtre_cfg;
  /**<   Values: \n 
       - 0x01 -- R-UIM only \n 
       - 0x02 -- Internal settings only \n 
       - 0x04 -- GSM on 1X
  */

  /* Optional */
  /*  RTRE Configuration Preference */
  uint8_t rtre_cfg_pref_valid;  /**< Must be set to true if rtre_cfg_pref is being passed */
  nas_rtre_cfg_enum_v01 rtre_cfg_pref;
  /**<   Values: \n 
       - 0x01 -- R-UIM only \n 
       - 0x02 -- Internal settings only \n 
       - 0x03 -- Use R-UIM if available \n 
       - 0x04 -- GSM on 1X
  */
}nas_rtre_cfg_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Queries the modem support status for centralized EONS. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_centralized_eons_support_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Queries the modem support status for centralized EONS. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type.*/

  /* Optional */
  /*  Centralized EONS Support Status */
  uint8_t centralized_eons_supported_valid;  /**< Must be set to true if centralized_eons_supported is being passed */
  uint8_t centralized_eons_supported;
  /**<   Centralized EONS support status. Values: \n
       - 0 -- Not supported \n
       - 1 -- Supported
  */
}nas_get_centralized_eons_support_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_NR5G_COMMON_RSSI_REPORTING_RATE_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NR5G_COMMON_RSSI_REPORTING_RATE_DEFAULT_V01 = 0, /**<  Reports using the default
                                                     configuration.  */
  NR5G_COMMON_RSSI_REPORTING_RATE_1_SEC_V01 = 1, /**<  Reports every 1 sec.  */
  NR5G_COMMON_RSSI_REPORTING_RATE_2_SEC_V01 = 2, /**<  Reports every 2 sec.  */
  NR5G_COMMON_RSSI_REPORTING_RATE_3_SEC_V01 = 3, /**<  Reports every 3 sec.  */
  NR5G_COMMON_RSSI_REPORTING_RATE_4_SEC_V01 = 4, /**<  Reports every 4 sec.  */
  NR5G_COMMON_RSSI_REPORTING_RATE_5_SEC_V01 = 5, /**<  Reports every 5 sec.  */
  NR5G_COMMON_RSSI_REPORTING_RATE_10_SEC_V01 = 10, /**<  Reports every 10 sec.  */
  NR5G_COMMON_RSSI_REPORTING_RATE_20_SEC_V01 = 20, /**<  Reports every 20 sec.  */
  NR5G_COMMON_RSSI_REPORTING_RATE_30_SEC_V01 = 30, /**<  Reports every 30 sec.  */
  NAS_NR5G_COMMON_RSSI_REPORTING_RATE_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_nr5g_common_rssi_reporting_rate_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_NR5G_COMMON_RSSI_AVERAGING_PERIOD_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NR5G_COMMON_RSSI_AVERAGING_PERIOD_DEFAULT_V01 = 0, /**<  Averages using the default
                                                       configuration.  */
  NR5G_COMMON_RSSI_AVERAGING_PERIOD_1_SEC_V01 = 1, /**<  Averages every 1 sec.  */
  NR5G_COMMON_RSSI_AVERAGING_PERIOD_2_SEC_V01 = 2, /**<  Averages every 2 sec.  */
  NR5G_COMMON_RSSI_AVERAGING_PERIOD_3_SEC_V01 = 3, /**<  Averages every 3 sec.  */
  NR5G_COMMON_RSSI_AVERAGING_PERIOD_4_SEC_V01 = 4, /**<  Averages every 4 sec.  */
  NR5G_COMMON_RSSI_AVERAGING_PERIOD_5_SEC_V01 = 5, /**<  Averages every 5 sec.  */
  NR5G_COMMON_RSSI_AVERAGING_PERIOD_6_SEC_V01 = 6, /**<  Averages every 6 sec.  */
  NR5G_COMMON_RSSI_AVERAGING_PERIOD_7_SEC_V01 = 7, /**<  Averages every 7 sec.  */
  NR5G_COMMON_RSSI_AVERAGING_PERIOD_8_SEC_V01 = 8, /**<  Averages every 8 sec.  */
  NR5G_COMMON_RSSI_AVERAGING_PERIOD_9_SEC_V01 = 9, /**<  Averages every 9 sec.  */
  NR5G_COMMON_RSSI_AVERAGING_PERIOD_10_SEC_V01 = 10, /**<  Averages every 10 sec.  */
  NR5G_COMMON_RSSI_AVERAGING_PERIOD_20_SEC_V01 = 20, /**<  Averages every 20 sec.  */
  NR5G_COMMON_RSSI_AVERAGING_PERIOD_30_SEC_V01 = 30, /**<  Averages every 30 sec.  */
  NAS_NR5G_COMMON_RSSI_AVERAGING_PERIOD_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_nr5g_common_rssi_averaging_period_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Report rate */
  nas_nr5g_common_rssi_reporting_rate_enum_type_v01 rpt_rate;
  /**<  
      Rate on how often the NR5G signal must be checked for reporting. Values: \n
      - 0  -- Report using the default configuration \n
      - 1  -- Report every 1 sec \n
      - 2  -- Report every 2 sec \n
      - 3  -- Report every 3 sec \n
      - 4  -- Report every 4 sec \n
      - 5  -- Report every 5 sec \n
	  - 10 -- Report every 10 sec \n
	  - 20 -- Report every 20 sec \n
	  - 30 -- Report every 30 sec	  
   */

  /*  Averaging period */
  nas_nr5g_common_rssi_averaging_period_enum_type_v01 avg_period;
  /**<  
      Averaging period to be used for the NR5G signal. Values: \n
      - 0  -- Average using the default configuration \n
      - 1  -- Average over 1 sec \n
      - 2  -- Average over 2 sec \n
      - 3  -- Average over 3 sec \n
      - 4  -- Average over 4 sec \n
      - 5  -- Average over 5 sec \n
      - 6  -- Average over 6 sec \n
      - 7  -- Average over 7 sec \n
      - 8  -- Average over 8 sec \n
      - 9  -- Average over 9 sec \n
      - 10 -- Average over 10 sec \n
	  - 20 -- Average over 20 sec \n
	  - 30 -- Average over 30 sec
   */
}nas_nr5g_sig_rpt_config_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets the signal strength reporting thresholds. 
               \label{idl:configSigInfo2} */
typedef struct {

  /* Optional */
  /*  CDMA RSSI Threshold List  */
  uint8_t cdma_rssi_threshold_list_valid;  /**< Must be set to true if cdma_rssi_threshold_list is being passed */
  uint32_t cdma_rssi_threshold_list_len;  /**< Must be set to # of elements in cdma_rssi_threshold_list */
  int16_t cdma_rssi_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX2_V01];
  /**<  
      Array of RSSI thresholds (in units of 0.1 dBm); maximum of 32 values. 
      Range for RSSI values: -105 to -21 (in dBm). \n
      For example, to set thresholds at -95 dBm and -80 dBm, the threshold 
      list values are {-950, -800}. \n
      The range is based on the latest releases and may change over time.
 */

  /* Optional */
  /*  CDMA RSSI Delta  */
  uint8_t cdma_rssi_delta_valid;  /**< Must be set to true if cdma_rssi_delta is being passed */
  uint16_t cdma_rssi_delta;
  /**<  
      RSSI delta (in units of 0.1 dBm). \n
      For example, to set a delta of 10 dBm, the delta value must be set 
      to 100. A value of 0 is rejected with a QMI_ERR_INVALID_ARG error.
 */

  /* Optional */
  /*  CDMA ECIO Threshold List */
  uint8_t cdma_ecio_threshold_list_valid;  /**< Must be set to true if cdma_ecio_threshold_list is being passed */
  uint32_t cdma_ecio_threshold_list_len;  /**< Must be set to # of elements in cdma_ecio_threshold_list */
  int16_t cdma_ecio_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX2_V01];
  /**<  
      Array of ECIO thresholds (in units of 0.1 dB); maximum of 32 values. 
      Range for ECIO values: -31.5 to 0 (in dB). \n
      For example, to set thresholds at -20 dB and -15.5 dB, the threshold 
      list values are {-200, -155}. \n
      The range is based on the latest releases and may change over time.
 */

  /* Optional */
  /*  CDMA ECIO Delta */
  uint8_t cdma_ecio_delta_valid;  /**< Must be set to true if cdma_ecio_delta is being passed */
  uint16_t cdma_ecio_delta;
  /**<  
      ECIO delta (in units of 0.1 dB). \n
      For example, to set a delta of 10 dB, the delta value must be set 
      to 100. A value of 0 is rejected with a QMI_ERR_INVALID_ARG error.
 */

  /* Optional */
  /*  HDR RSSI Threshold List  */
  uint8_t hdr_rssi_threshold_list_valid;  /**< Must be set to true if hdr_rssi_threshold_list is being passed */
  uint32_t hdr_rssi_threshold_list_len;  /**< Must be set to # of elements in hdr_rssi_threshold_list */
  int16_t hdr_rssi_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX2_V01];
  /**<  
      Array of RSSI thresholds (in units of 0.1 dBm); maximum of 32 values. 
      Range for RSSI values: -118 to -13 (in dBm). \n
      For example, to set thresholds at -20 dBm and -15 dBm, the threshold 
      list values are {-200, -150}. \n
      The range is based on the latest releases and may change over time.
 */

  /* Optional */
  /*  HDR RSSI Delta  */
  uint8_t hdr_rssi_delta_valid;  /**< Must be set to true if hdr_rssi_delta is being passed */
  uint16_t hdr_rssi_delta;
  /**<  
      RSSI delta (in units of 0.1 dBm). \n
      For example, to set a delta of 10 dBm, the delta value must be set 
      to 100. A value of 0 is rejected with a QMI_ERR_INVALID_ARG error.
 */

  /* Optional */
  /*  HDR ECIO Threshold List */
  uint8_t hdr_ecio_threshold_list_valid;  /**< Must be set to true if hdr_ecio_threshold_list is being passed */
  uint32_t hdr_ecio_threshold_list_len;  /**< Must be set to # of elements in hdr_ecio_threshold_list */
  int16_t hdr_ecio_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX2_V01];
  /**<  
      Array of ECIO thresholds (in units of 0.1 dB); maximum of 32 values. 
      Range for ECIO values: -31.5 to 0 (in dB). \n
      For example, to set thresholds at -20 dB and -15.5 dB, the threshold 
      list values are {-200, -155}. \n
      The range is based on the latest releases and may change over time.
 */

  /* Optional */
  /*  HDR ECIO Delta */
  uint8_t hdr_ecio_delta_valid;  /**< Must be set to true if hdr_ecio_delta is being passed */
  uint16_t hdr_ecio_delta;
  /**<  
      ECIO delta (in units of 0.1 dB). \n
      For example, to set a delta of 10 dB, the delta value must be set 
      to 100. A value of 0 is rejected with a QMI_ERR_INVALID_ARG error.
 */

  /* Optional */
  /*  HDR SINR Threshold List */
  uint8_t hdr_sinr_threshold_list_valid;  /**< Must be set to true if hdr_sinr_threshold_list is being passed */
  uint32_t hdr_sinr_threshold_list_len;  /**< Must be set to # of elements in hdr_sinr_threshold_list */
  uint16_t hdr_sinr_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX2_V01];
  /**<  
      Array of SINR level thresholds (in units of 1); maximum of 32 values. 
      Valid levels are 0 to 8, where the maximum value for: \n
      - 0x00 -- SINR_LEVEL_0 is -9 dB   \n
      - 0x01 -- SINR_LEVEL_1 is -6 dB   \n
      - 0x02 -- SINR_LEVEL_2 is -4.5 dB \n
      - 0x03 -- SINR_LEVEL_3 is -3 dB   \n
      - 0x04 -- SINR_LEVEL_4 is -2 dB   \n
      - 0x05 -- SINR_LEVEL_5 is +1 dB   \n
      - 0x06 -- SINR_LEVEL_6 is +3 dB   \n
      - 0x07 -- SINR_LEVEL_7 is +6 dB   \n
      - 0x08 -- SINR_LEVEL_8 is +9 dB
 */

  /* Optional */
  /*  HDR SINR Delta */
  uint8_t hdr_sinr_delta_valid;  /**< Must be set to true if hdr_sinr_delta is being passed */
  uint16_t hdr_sinr_delta;
  /**<  
      SINR delta (in units of 1 SINR level). \n
      For example, to set a delta of 1 SINR level, the delta value must be 
      set to 1. A value of 0 is rejected with a QMI_ERR_INVALID_ARG error.
 */

  /* Optional */
  /*  HDR IO Threshold List */
  uint8_t hdr_io_threshold_list_valid;  /**< Must be set to true if hdr_io_threshold_list is being passed */
  uint32_t hdr_io_threshold_list_len;  /**< Must be set to # of elements in hdr_io_threshold_list */
  int16_t hdr_io_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX2_V01];
  /**<  
      Array of IO thresholds (in units of 0.1 dBm); maximum of 32 values. 
      Range for IO values: -128 to -13 (in dBm). \n
      For example, to set thresholds at -111 dBm and -73 dBm, the threshold 
      list values are {-1110, -730}. \n
      The range is based on the latest releases and may change over time.
 */

  /* Optional */
  /*  HDR IO Delta */
  uint8_t hdr_io_delta_valid;  /**< Must be set to true if hdr_io_delta is being passed */
  uint16_t hdr_io_delta;
  /**<  
      IO delta (in units of 0.1 dBm). \n
      For example, to set a delta of 10 dBm, the delta value must be set 
      to 100. A value of 0 is rejected with a QMI_ERR_INVALID_ARG error.
 */

  /* Optional */
  /*  GSM RSSI Threshold List  */
  uint8_t gsm_rssi_threshold_list_valid;  /**< Must be set to true if gsm_rssi_threshold_list is being passed */
  uint32_t gsm_rssi_threshold_list_len;  /**< Must be set to # of elements in gsm_rssi_threshold_list */
  int16_t gsm_rssi_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX2_V01];
  /**<  
      Array of RSSI thresholds (in units of 0.1 dBm); maximum of 32 values. 
      Range for RSSI values: -111 to -48 (in dBm). \n
      For example, to set thresholds at -95 dBm and -80 dBm, the threshold 
      list values are {-950, -800}. \n
      The range is based on the latest releases and may change over time.
 */

  /* Optional */
  /*  GSM RSSI Delta  */
  uint8_t gsm_rssi_delta_valid;  /**< Must be set to true if gsm_rssi_delta is being passed */
  uint16_t gsm_rssi_delta;
  /**<  
      RSSI delta (in units of 0.1 dBm). \n
      For example, to set a delta of 10 dBm, the delta value must be set 
      to 100. A value of 0 is rejected with a QMI_ERR_INVALID_ARG error.
 */

  /* Optional */
  /*  WCDMA RSSI Threshold List  */
  uint8_t wcdma_rssi_threshold_list_valid;  /**< Must be set to true if wcdma_rssi_threshold_list is being passed */
  uint32_t wcdma_rssi_threshold_list_len;  /**< Must be set to # of elements in wcdma_rssi_threshold_list */
  int16_t wcdma_rssi_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX2_V01];
  /**<  
      Array of RSSI thresholds (in units of 0.1 dBm); maximum of 32 values. 
      Range for RSSI values: -121 to 0 (in dBm). \n
      For example, to set thresholds at -20 dBm and -15 dBm, the threshold 
      list values are {-200, -150}. \n
      The range is based on the latest releases and may change over time.
 */

  /* Optional */
  /*  WCDMA RSSI Delta  */
  uint8_t wcdma_rssi_delta_valid;  /**< Must be set to true if wcdma_rssi_delta is being passed */
  uint16_t wcdma_rssi_delta;
  /**<  
      RSSI delta (in units of 0.1 dBm). \n
      For example, to set a delta of 10 dBm, the delta value must be set 
      to 100. A value of 0 is rejected with a QMI_ERR_INVALID_ARG error.
 */

  /* Optional */
  /*  WCDMA ECIO Threshold List */
  uint8_t wcdma_ecio_threshold_list_valid;  /**< Must be set to true if wcdma_ecio_threshold_list is being passed */
  uint32_t wcdma_ecio_threshold_list_len;  /**< Must be set to # of elements in wcdma_ecio_threshold_list */
  int16_t wcdma_ecio_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX2_V01];
  /**<  
      Array of ECIO thresholds (in units of 0.1 dB); maximum of 32 values. 
      Range for ECIO values: -31.5 to 0 (in dB). \n
      For example, to set thresholds at -20 dB and -15.5 dB, the threshold 
      list values are {-200, -155}. \n
      The range is based on the latest releases and may change over time.
 */

  /* Optional */
  /*  WCDMA ECIO Delta */
  uint8_t wcdma_ecio_delta_valid;  /**< Must be set to true if wcdma_ecio_delta is being passed */
  uint16_t wcdma_ecio_delta;
  /**<  
      ECIO delta (in units of 0.1 dB). \n
      For example, to set a delta of 10 dB, the delta value must be set 
      to 100. A value of 0 is rejected with a QMI_ERR_INVALID_ARG error.
 */

  /* Optional */
  /*  LTE RSSI Threshold List  */
  uint8_t lte_rssi_threshold_list_valid;  /**< Must be set to true if lte_rssi_threshold_list is being passed */
  uint32_t lte_rssi_threshold_list_len;  /**< Must be set to # of elements in lte_rssi_threshold_list */
  int16_t lte_rssi_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX2_V01];
  /**<  
      Array of RSSI thresholds (in units of 0.1 dBm); maximum of 32 values. 
      Range for RSSI values: -120 to 0 (in dBm). \n
      For example, to set thresholds at -20 dBm and -15 dBm, the threshold 
      list values are {-200, -150}. \n
      The range is based on the latest releases and may change over time.
 */

  /* Optional */
  /*  LTE RSSI Delta  */
  uint8_t lte_rssi_delta_valid;  /**< Must be set to true if lte_rssi_delta is being passed */
  uint16_t lte_rssi_delta;
  /**<  
      RSSI delta (in units of 0.1 dBm).
      For example, to set a delta of 10 dBm, the delta value must be set 
      to 100. A value of 0 is rejected with a QMI_ERR_INVALID_ARG error.
 */

  /* Optional */
  /*  LTE SNR Threshold List */
  uint8_t lte_snr_threshold_list_valid;  /**< Must be set to true if lte_snr_threshold_list is being passed */
  uint32_t lte_snr_threshold_list_len;  /**< Must be set to # of elements in lte_snr_threshold_list */
  int16_t lte_snr_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX2_V01];
  /**<  
      Array of SNR thresholds (in units of 0.1 dB); maximum of 32 values. 
      Range for SNR values: -20 to 30 (in dB). \n
      For example, to set thresholds at -19.8 dB and 23 dB, the threshold 
      list values are {-198, 230}. \n
      The range is based on the latest releases and may change over time.
 */

  /* Optional */
  /*  LTE SNR Delta */
  uint8_t lte_snr_delta_valid;  /**< Must be set to true if lte_snr_delta is being passed */
  uint16_t lte_snr_delta;
  /**<  
      SNR delta (in units of 0.1 dBm). \n
      For example, to set a delta of 10 dBm, the delta value must be set 
      to 100. A value of 0 is rejected with a QMI_ERR_INVALID_ARG error.
 */

  /* Optional */
  /*  LTE RSRQ Threshold List */
  uint8_t lte_rsrq_threshold_list_valid;  /**< Must be set to true if lte_rsrq_threshold_list is being passed */
  uint32_t lte_rsrq_threshold_list_len;  /**< Must be set to # of elements in lte_rsrq_threshold_list */
  int16_t lte_rsrq_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX2_V01];
  /**<  
      Array of RSRQ thresholds (in units of 0.1 dBm); maximum of 32 values. 
      Range for RSRQ values: -20 to -3 (in dBm). \n
      For example, to set thresholds at -11 dBm and -6 dBm, the threshold 
      list values are {-110, -60}. \n
      The range is based on the latest releases and may change over time.
 */

  /* Optional */
  /*  LTE RSRQ Delta */
  uint8_t lte_rsrq_delta_valid;  /**< Must be set to true if lte_rsrq_delta is being passed */
  uint16_t lte_rsrq_delta;
  /**<  
      RSRQ delta (in units of 0.1 dBm). \n
      For example, to set a delta of 10 dBm, the delta value must be set 
      to 100. A value of 0 is rejected with a QMI_ERR_INVALID_ARG error.
 */

  /* Optional */
  /*  LTE RSRP Threshold List */
  uint8_t lte_rsrp_threshold_list_valid;  /**< Must be set to true if lte_rsrp_threshold_list is being passed */
  uint32_t lte_rsrp_threshold_list_len;  /**< Must be set to # of elements in lte_rsrp_threshold_list */
  int16_t lte_rsrp_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX2_V01];
  /**<  
      Array of RSRP thresholds (in units of 0.1 dBm); maximum of 32 values. 
      Range for RSRP values: -140 to -44 (in dBm). \n
      For example, to set thresholds at -125 dBm and -64 dBm, the threshold 
      list values are {-1250, -640}. \n
      The range is based on the latest releases and may change over time.
 */

  /* Optional */
  /*  LTE RSRP Delta */
  uint8_t lte_rsrp_delta_valid;  /**< Must be set to true if lte_rsrp_delta is being passed */
  uint16_t lte_rsrp_delta;
  /**<  
      RSRP delta (in units of 0.1 dBm). \n
      For example, to set a delta of 10 dBm, the delta value must be set 
      to 100. A value of 0 is rejected with a QMI_ERR_INVALID_ARG error.
 */

  /* Optional */
  /*  LTE Signal Report Config */
  uint8_t lte_sig_rpt_config_valid;  /**< Must be set to true if lte_sig_rpt_config is being passed */
  nas_lte_sig_rpt_config_type_v01 lte_sig_rpt_config;

  /* Optional */
  /*  TDSCDMA RSCP Threshold List  */
  uint8_t tdscdma_rscp_threshold_list_valid;  /**< Must be set to true if tdscdma_rscp_threshold_list is being passed */
  uint32_t tdscdma_rscp_threshold_list_len;  /**< Must be set to # of elements in tdscdma_rscp_threshold_list */
  int16_t tdscdma_rscp_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX2_V01];
  /**<  
      Array of RSCP thresholds (in units of 0.1 dBm); maximum of 32 values. 
      Range for RSCP values: -120 to -25 (in dBm). \n
      For example, to set thresholds at -95 dBm and -80 dBm, the threshold 
      list values would be {-950, -800}. \n
      The range is based on the latest releases and may change over time.
 */

  /* Optional */
  /*  TDSCDMA RSCP Delta */
  uint8_t tdscdma_rscp_delta_valid;  /**< Must be set to true if tdscdma_rscp_delta is being passed */
  uint16_t tdscdma_rscp_delta;
  /**<  
      RSCP delta (in units of 0.1 dBm). \n
      For example, to set a delta of 10 dBm, the delta value must be set 
      to 100. A value of 0 is rejected with a QMI_ERR_INVALID_ARG error.
 */

  /* Optional */
  /*  TDSCDMA RSSI Threshold List  */
  uint8_t tds_rssi_threshold_list_valid;  /**< Must be set to true if tds_rssi_threshold_list is being passed */
  uint32_t tds_rssi_threshold_list_len;  /**< Must be set to # of elements in tds_rssi_threshold_list */
  float tds_rssi_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX2_V01];
  /**<  
      Array of RSSI thresholds (in dBm) used by TD-SCDMA; maximum of 32 values.
  */

  /* Optional */
  /*  TDSCDMA RSSI Delta */
  uint8_t tdscdma_rssi_delta_valid;  /**< Must be set to true if tdscdma_rssi_delta is being passed */
  float tdscdma_rssi_delta;
  /**<  
      RSSI delta (in dBm) used by TD-SCDMA.
 */

  /* Optional */
  /*  TDSCDMA ECIO Threshold List  */
  uint8_t tds_ecio_threshold_list_valid;  /**< Must be set to true if tds_ecio_threshold_list is being passed */
  uint32_t tds_ecio_threshold_list_len;  /**< Must be set to # of elements in tds_ecio_threshold_list */
  float tds_ecio_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX2_V01];
  /**<  
      Array of ECIO thresholds (in dB) used by TD-SCDMA; maximum of 32 values.
  */

  /* Optional */
  /*  TDSCDMA ECIO Delta */
  uint8_t tdscdma_ecio_delta_valid;  /**< Must be set to true if tdscdma_ecio_delta is being passed */
  float tdscdma_ecio_delta;
  /**<  
      ECIO delta (in dB) used by TD-SCDMA.
 */

  /* Optional */
  /*  TDSCDMA SINR Threshold List  */
  uint8_t tds_sinr_threshold_list_valid;  /**< Must be set to true if tds_sinr_threshold_list is being passed */
  uint32_t tds_sinr_threshold_list_len;  /**< Must be set to # of elements in tds_sinr_threshold_list */
  float tds_sinr_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX2_V01];
  /**<  
      Array of SINR thresholds (in dB) used by TD-SCDMA; maximum of 32 values.
 */

  /* Optional */
  /*  TDSCDMA SINR Delta */
  uint8_t tdscdma_sinr_delta_valid;  /**< Must be set to true if tdscdma_sinr_delta is being passed */
  float tdscdma_sinr_delta;
  /**<  
      SINR delta (in dB) used by TD-SCDMA.
 */

  /* Optional */
  /*  5G SNR Threshold List */
  uint8_t nr5g_snr_threshold_list_valid;  /**< Must be set to true if nr5g_snr_threshold_list is being passed */
  uint32_t nr5g_snr_threshold_list_len;  /**< Must be set to # of elements in nr5g_snr_threshold_list */
  int16_t nr5g_snr_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX2_V01];
  /**<  
      Array of SNR thresholds (in units of 0.1 dB); maximum of 32 values. 
      Range for SNR values: -20 to 30 (in dB).
 */

  /* Optional */
  /*  5G SNR Delta List */
  uint8_t nr5g_snr_delta_valid;  /**< Must be set to true if nr5g_snr_delta is being passed */
  uint16_t nr5g_snr_delta;
  /**<  
      SNR delta (in units of 0.1 dBm).
 */

  /* Optional */
  /*  5G RSRP Threshold List */
  uint8_t nr5g_rsrp_threshold_list_valid;  /**< Must be set to true if nr5g_rsrp_threshold_list is being passed */
  uint32_t nr5g_rsrp_threshold_list_len;  /**< Must be set to # of elements in nr5g_rsrp_threshold_list */
  int16_t nr5g_rsrp_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX2_V01];
  /**<  
      Array of RSRP thresholds (in units of 0.1 dBm); maximum of 32 values. 
      Range for RSRP values: -140 to -44 (in dBm).
 */

  /* Optional */
  /*  5G RSRP Delta List */
  uint8_t nr5g_rsrp_delta_valid;  /**< Must be set to true if nr5g_rsrp_delta is being passed */
  uint16_t nr5g_rsrp_delta;
  /**<  
      RSRP delta (in units of 0.1 dBm). 
 */

  /* Optional */
  /*  5G Signal Report Config */
  uint8_t nr5g_sig_rpt_config_valid;  /**< Must be set to true if nr5g_sig_rpt_config is being passed */
  nas_nr5g_sig_rpt_config_type_v01 nr5g_sig_rpt_config;

  /* Optional */
  /*  5G RSRQ Threshold List */
  uint8_t nr5g_rsrq_threshold_list_valid;  /**< Must be set to true if nr5g_rsrq_threshold_list is being passed */
  uint32_t nr5g_rsrq_threshold_list_len;  /**< Must be set to # of elements in nr5g_rsrq_threshold_list */
  int16_t nr5g_rsrq_threshold_list[NAS_SIG_STR_THRESHOLD_LIST_MAX2_V01];
  /**<  
      Array of RSRQ thresholds (in units of 0.1 dBm); maximum of 32 values.
 */

  /* Optional */
  /*  5G RSRQ Delta List */
  uint8_t nr5g_rsrq_delta_valid;  /**< Must be set to true if nr5g_rsrq_delta is being passed */
  uint16_t nr5g_rsrq_delta;
  /**<  
      RSRQ delta (in units of 0.1 dBm). 
 */
}nas_config_sig_info2_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets the signal strength reporting thresholds. 
               \label{idl:configSigInfo2} */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_config_sig_info2_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the cell information and neighbor cell information 
               for TD-SCDMA. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_tds_cell_and_position_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  PLMN ID */
  nas_plmn_id_ext_type_v01 plmn;

  /*  LAC */
  uint16_t lac;
  /**<   Location area code. (This field is ignored when cell_id is not present.)
  */

  /*  UARFCN */
  uint16_t uarfcn;
  /**<   Absolute RF channel number.
  */

  /*  Cell id */
  uint32_t cell_id;
  /**<   Cell ID (0xFFFFFFFF indicates cell ID information is not present).
  */

  /*  Cell parameter id */
  uint8_t cell_parameter_id;
  /**<   Cell parameter ID.
  */

  /*  Pathloss */
  uint8_t pathloss;
  /**<   Path loss in units of 1 dB.
  */

  /*  Timing advance */
  float timing_advance;
  /**<   Measured delay (in seconds) of an access burst transmission on the RACH 
       or PRACH to the expected signal from an MS at zero distance under static 
       channel conditions. 
  */

  /*  RSCP */
  float rscp;
  /**<   Received signal code power in dBm.
  */
}nas_tds_cell_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  UARFCN */
  uint16_t uarfcn;
  /**<   Absolute RF channel number.
  */

  /*  Cell parameter id */
  uint8_t cell_parameter_id;
  /**<   Cell parameter ID.
  */

  /*  RSCP */
  float rscp;
  /**<    Received signal code power in dBm.
  */
}nas_tds_nbr_cell_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the cell information and neighbor cell information 
               for TD-SCDMA. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  TDSCDMA Cell Info  */
  uint8_t tds_cell_info_valid;  /**< Must be set to true if tds_cell_info is being passed */
  nas_tds_cell_info_type_v01 tds_cell_info;

  /* Optional */
  /*  TDSCDMA Neighbor Cell Info  */
  uint8_t tds_nbr_cell_info_valid;  /**< Must be set to true if tds_nbr_cell_info is being passed */
  uint32_t tds_nbr_cell_info_len;  /**< Must be set to # of elements in tds_nbr_cell_info */
  nas_tds_nbr_cell_info_type_v01 tds_nbr_cell_info[NAS_TDS_MAX_NBR_CELL_NUM_V01];
}nas_get_tds_cell_and_position_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets the periodic search timer configuration for a 
              home operator-specific BPLMN search to LTE. */
typedef struct {

  /* Mandatory */
  /*  TDSCDMA Neighbor Cell Periodic Search Timer */
  uint16_t timer_value;
  /**<  
      TD-SCDMA search timer value (in minutes). \n
      0 indicates an immediate search and the timer is disabled. \n
      0xFFFF is used to disable the timer without any search.
 */
}nas_set_hplmn_irat_search_timer_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets the periodic search timer configuration for a 
              home operator-specific BPLMN search to LTE. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type.*/
}nas_set_hplmn_irat_search_timer_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the current signal quality at L1 for each MBSFN area. */
typedef struct {

  /* Optional */
  /*  Trace ID */
  uint8_t trace_id_valid;  /**< Must be set to true if trace_id is being passed */
  int16_t trace_id;
  /**<   Trace ID.  Values: \n
       - 0 to 32768 -- Valid trace ID \n
       - -1 -- Trace ID is not used
  */
}nas_get_embms_sig_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  MBSFN Area ID */
  uint8_t area_id;
  /**<   Multicast Broadcast Single Frequency Network (MBSFN) area ID. 
    Values: 0 to 255.
  */

  /*  SNR */
  float snr;
  /**<   Average SNR of the serving cell over the last measurement period in
    decibels.
   */

  /*  Signal Level (Deprecated) */
  int8_t signal_level;
  /**<   Signal level of the serving cell over the last measurement period. 
    Range: 0 to 5.
   */
}nas_lte_cphy_mbsfn_area_signal_strength_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the current signal quality at L1 for each MBSFN area. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type.*/

  /* Optional */
  /*  Trace ID */
  uint8_t trace_id_valid;  /**< Must be set to true if trace_id is being passed */
  int16_t trace_id;
  /**<   Trace ID.  Values: \n
       - 0 to 32768 -- Valid trace ID \n
       - -1 -- Trace ID is not used
  */

  /* Optional */
  /*  Signal Quality */
  uint8_t sig_list_valid;  /**< Must be set to true if sig_list is being passed */
  uint32_t sig_list_len;  /**< Must be set to # of elements in sig_list */
  nas_lte_cphy_mbsfn_area_signal_strength_type_v01 sig_list[NAS_LTE_EMBMS_MAX_MBSFN_AREA_V01];
}nas_get_embms_sig_resp_msg_v01;  /* Message */
/**
    @}
  */

typedef uint64_t nas_limit_sys_info_ind_mask_type_v01;
#define NAS_LIMIT_BY_SRV_STATUS_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x01ull) 
#define NAS_LIMIT_BY_SRV_DOMAIN_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x02ull) 
#define NAS_LIMIT_BY_PLMN_ID_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x04ull) 
#define NAS_LIMIT_BY_SID_NID_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x08ull) 
#define NAS_LIMIT_BY_ROAM_STATUS_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x10ull) 
#define NAS_LIMIT_BY_SRV_CAPABILITY_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x20ull) 
#define NAS_LIMIT_BY_PACKET_ZONE_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x40ull) 
#define NAS_LIMIT_BY_IS856_SYS_ID_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x80ull) 
#define NAS_LIMIT_BY_CELL_ID_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x100ull) 
#define NAS_LIMIT_BY_LAC_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x200ull) 
#define NAS_LIMIT_BY_RAC_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x400ull) 
#define NAS_LIMIT_BY_TAC_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x800ull) 
#define NAS_LIMIT_BY_HS_CALL_STATUS_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x1000ull) 
#define NAS_LIMIT_BY_HS_IND_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x2000ull) 
#define NAS_LIMIT_BY_HDR_ACTIVE_PROTOCOL_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x4000ull) 
#define NAS_LIMIT_BY_EGPRS_SUPPORT_IND_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x8000ull) 
#define NAS_LIMIT_BY_HDR_PERSONALITY_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x10000ull) 
#define NAS_LIMIT_BY_CCS_SUPPORTED_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x20000ull) 
#define NAS_LIMIT_BY_DTM_SUPPORTED_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x40000ull) 
#define NAS_LIMIT_BY_CS_BAR_STATUS_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x80000ull) 
#define NAS_LIMIT_BY_PS_BAR_STATUS_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x100000ull) 
#define NAS_LIMIT_BY_VOICE_SUPPORT_ON_LTE_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x200000ull) 
#define NAS_LIMIT_BY_SYS_INFO_NO_CHANGE_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x400000ull) 
#define NAS_LIMIT_BY_IS_SYS_FORBIDDEN_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x800000ull) 
#define NAS_LIMIT_BY_LTE_EMBMS_COVERAGE_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x1000000ull) 
#define NAS_LIMIT_BY_LTE_VOICE_STATUS_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x2000000ull) 
#define NAS_LIMIT_BY_LTE_SMS_STATUS_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x4000000ull) 
#define NAS_LIMIT_BY_IS_SYS_PRL_MATCH_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x8000000ull) 
#define NAS_LIMIT_BY_P_REV_IN_USE_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x10000000ull) 
#define NAS_LIMIT_BY_CDMA_SYS_ID_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x20000000ull) 
#define NAS_LIMIT_BY_PSC_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x40000000ull) 
#define NAS_LIMIT_BY_SIM_REJ_INFO_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x80000000ull) 
#define NAS_LIMIT_BY_WCDMA_EUTRA_STATUS_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x100000000ull) 
#define NAS_LIMIT_BY_WCDMA_CSG_INFO_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x200000000ull) 
#define NAS_LIMIT_BY_LTE_CSG_INFO_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x400000000ull) 
#define NAS_LIMIT_BY_SRV_STATUS_TOGGLE_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x800000000ull) 
#define NAS_LIMIT_BY_SRV_RAT_TECH_CHANGE_V01 ((nas_limit_sys_info_ind_mask_type_v01)0x1000000000ull) 
/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Limits the reporting of QMI_NAS_SYS_INFO_IND to only when 
              certain fields have changed. */
typedef struct {

  /* Mandatory */
  /*  Limit Sys Info Change Reporting */
  nas_limit_sys_info_ind_mask_type_v01 limit_sys_info_chg_rpt;
  /**<   Bitmasks included in this TLV limit the reporting of QMI_NAS_SYS_INFO_IND 
       to when those values change. If a value of 0 is sent, QMI_NAS_SYS_INFO_IND 
       reporting is as if no limit is set. Values: \n
      
       - 0x01 -- NAS_LIMIT_BY_SRV_STATUS  -- Limit by srv_status changes \n
       - 0x02 -- NAS_LIMIT_BY_SRV_DOMAIN  -- Limit by srv_domain changes \n
       - 0x04 -- NAS_LIMIT_BY_PLMN_ID     -- Limit by mcc/mnc \n
       - 0x08 -- NAS_LIMIT_BY_SID_NID     -- Limit by sid/nid \n
       - 0x10 -- NAS_LIMIT_BY_ROAM_STATUS -- Limit by roam_status \n
       - 0x20 -- NAS_LIMIT_BY_SRV_CAPABILITY -- Limit by srv_capability changes \n
       - 0x40 -- NAS_LIMIT_BY_PACKET_ZONE -- Limit by packet zone changes \n
       - 0x80 -- NAS_LIMIT_BY_IS856_SYS_ID -- Limit by IS856_sys_id changes \n
       - 0x100 -- NAS_LIMIT_BY_CELL_ID -- Limit by cell_id changes \n
       - 0x200 -- NAS_LIMIT_BY_LAC -- Limit by LAC changes \n
       - 0x400 -- NAS_LIMIT_BY_RAC -- Limit by RAC changes \n
       - 0x800 -- NAS_LIMIT_BY_TAC -- Limit by TAC changes \n
       - 0x1000 -- NAS_LIMIT_BY_HS_CALL_STATUS -- Limit by hs_call_status \n
       - 0x2000 -- NAS_LIMIT_BY_HS_IND -- Limit by hs_ind \n
       - 0x4000 -- NAS_LIMIT_BY_HDR_ACTIVE_ PROTOCOL -- Limit by hdr_active_prot \n
       - 0x8000 -- NAS_LIMIT_BY_EGPRS_SUPPORT_ IND -- Limit by Enhanced General 
                   Packet Radio Service (EGPRS) support \n
       - 0x10000 -- NAS_LIMIT_BY_HDR_ PERSONALITY -- Limit by hdr_personality \n
       - 0x20000 -- NAS_LIMIT_BY_CCS_SUPPORTED -- Limit by ccs_supported \n
       - 0x40000 -- NAS_LIMIT_BY_DTM_SUPPORTED -- Limit by Dual Transfer Mode (DTM) support \n
       - 0x80000 -- NAS_LIMIT_BY_CS_BAR_STATUS -- Limit by cs_bar_status \n
       - 0x100000 -- NAS_LIMIT_BY_PS_BAR_STATUS -- Limit by ps_bar_status \n
       - 0x200000 -- NAS_LIMIT_BY_VOICE_ SUPPORT_ON_LTE -- Limit by LTE voice support \n
       - 0x400000 -- NAS_LIMIT_BY_SYS_INFO_ NO_CHANGE -- Limit by no change \n
       - 0x800000 -- NAS_LIMIT_BY_IS_SYS_ FORBIDDEN -- Limit by is_sys_forbidden \n
       - 0x1000000 -- NAS_LIMIT_BY_LTE_EMBMS_ COVERAGE -- Limit by lte_embms_coverage \n
       - 0x2000000 -- NAS_LIMIT_BY_LTE_VOICE_ STATUS -- Limit by lte_voice_status \n
       - 0x4000000 -- NAS_LIMIT_BY_LTE_SMS_ STATUS -- Limit by lte_sms_status \n
       - 0x8000000 -- NAS_LIMIT_BY_IS_SYS_PRL_ MATCH -- Limit by is_sys_prl_match \n
       - 0x10000000 -- NAS_LIMIT_BY_P_REV_IN_USE -- Limit by p_rev_in_use \n
       - 0x20000000 -- NAS_LIMIT_BY_CDMA_SYS_ID -- Limit by cdma_sys_id \n
       - 0x40000000 -- NAS_LIMIT_BY_PSC -- Limit by PSC \n
       - 0x80000000 -- NAS_LIMIT_BY_SIM_REJ_INFO -- Limit by SIM rejection information \n
       - 0x100000000 -- NAS_LIMIT_BY_WCDMA_ EUTRA_STATUS -- Limit by wcdma_eutra_status \n
       - 0x200000000 -- NAS_LIMIT_BY_WCDMA_ CSG_INFO -- Limit by wcdma_csg_info \n
       - 0x400000000 -- NAS_LIMIT_BY_LTE_CSG_ INFO -- Limit by lte_csg_info \n
       - 0x800000000 -- NAS_LIMIT_BY_SRV_STATUS_ TOGGLE -- Limit by service status toggle \n
       - 0x1000000000 -- NAS_LIMIT_BY_SRV_RAT_TECH_ CHANGE -- Limit by service RAT Technology change

       \vspace{3pt}
       All other bits are reserved for future use.
  */
}nas_limit_sys_info_ind_reporting_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Limits the reporting of QMI_NAS_SYS_INFO_IND to only when 
              certain fields have changed. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type.*/
}nas_limit_sys_info_ind_reporting_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the limitations set on the reporting of 
              QMI_NAS_SYS_INFO_IND. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_sys_info_ind_reporting_limit_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the limitations set on the reporting of 
              QMI_NAS_SYS_INFO_IND. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type.*/

  /* Mandatory */
  /*  Limit Sys Info Change Reporting */
  nas_limit_sys_info_ind_mask_type_v01 limit_sys_info_chg_rpt;
  /**<   Bitmasks included in this TLV indicate the limits set on 
       QMI_NAS_SYS_INFO_IND reporting.  If a value of 0 is sent, 
       QMI_NAS_SYS_INFO_IND is reporting with no limitations. Values: \n

       - 0x01 -- NAS_LIMIT_BY_SRV_STATUS  -- Limit by srv_status changes \n
       - 0x02 -- NAS_LIMIT_BY_SRV_DOMAIN  -- Limit by srv_domain changes \n
       - 0x04 -- NAS_LIMIT_BY_PLMN_ID     -- Limit by mcc/mnc \n
       - 0x08 -- NAS_LIMIT_BY_SID_NID     -- Limit by sid/nid \n
       - 0x10 -- NAS_LIMIT_BY_ROAM_STATUS -- Limit by roam_status \n
       - 0x20 -- NAS_LIMIT_BY_SRV_CAPABILITY -- Limit by srv_capability changes \n
       - 0x40 -- NAS_LIMIT_BY_PACKET_ZONE -- Limit by packet zone changes \n
       - 0x80 -- NAS_LIMIT_BY_IS856_SYS_ID -- Limit by IS856_sys_id changes \n
       - 0x100 -- NAS_LIMIT_BY_CELL_ID -- Limit by cell_id changes \n
       - 0x200 -- NAS_LIMIT_BY_LAC -- Limit by LAC changes \n
       - 0x400 -- NAS_LIMIT_BY_RAC -- Limit by RAC changes \n
       - 0x800 -- NAS_LIMIT_BY_TAC -- Limit by TAC changes \n
       - 0x1000 -- NAS_LIMIT_BY_HS_CALL_STATUS -- Limit by hs_call_status \n
       - 0x2000 -- NAS_LIMIT_BY_HS_IND -- Limit by hs_ind \n
       - 0x4000 -- NAS_LIMIT_BY_HDR_ACTIVE_ PROTOCOL -- Limit by hdr_active_prot \n
       - 0x8000 -- NAS_LIMIT_BY_EGPRS_SUPPORT_ IND -- Limit by EGPRS support \n
       - 0x10000 -- NAS_LIMIT_BY_HDR_ PERSONALITY -- Limit by hdr_personality \n
       - 0x20000 -- NAS_LIMIT_BY_CCS_SUPPORTED -- Limit by ccs_supported \n
       - 0x40000 -- NAS_LIMIT_BY_DTM_SUPPORTED -- Limit by DTM support \n
       - 0x80000 -- NAS_LIMIT_BY_CS_BAR_STATUS -- Limit by cs_bar_status \n
       - 0x100000 -- NAS_LIMIT_BY_PS_BAR_STATUS -- Limit by ps_bar_status \n
       - 0x200000 -- NAS_LIMIT_BY_VOICE_SUPPORT_ON_LTE -- Limit by LTE voice support \n
       - 0x400000 -- NAS_LIMIT_BY_SYS_INFO_NO_CHANGE -- Limit by no change \n
       - 0x800000 -- NAS_LIMIT_BY_IS_SYS_FORBIDDEN -- Limit by is_sys_forbidden \n
       - 0x1000000 -- NAS_LIMIT_BY_LTE_EMBMS_COVERAGE -- Limit by lte_embms_coverage \n
       - 0x2000000 -- NAS_LIMIT_BY_LTE_VOICE_STATUS -- Limit by lte_voice_status \n
       - 0x4000000 -- NAS_LIMIT_BY_LTE_SMS_STATUS -- Limit by lte_sms_status \n
       - 0x8000000 -- NAS_LIMIT_BY_IS_SYS_PRL_MATCH -- Limit by is_sys_prl_match \n
       - 0x10000000 -- NAS_LIMIT_BY_P_REV_IN_USE -- Limit by p_rev_in_use \n
       - 0x20000000 -- NAS_LIMIT_BY_CDMA_SYS_ID -- Limit by cdma_sys_id \n
       - 0x40000000 -- NAS_LIMIT_BY_PSC -- Limit by PSC \n
       - 0x80000000 -- NAS_LIMIT_BY_SIM_REJ_INFO -- Limit by SIM rejection information \n
       - 0x100000000 -- NAS_LIMIT_BY_WCDMA_ EUTRA_STATUS -- Limit by wcdma_eutra_status \n
       - 0x200000000 -- NAS_LIMIT_BY_WCDMA_ CSG_INFO -- Limit by wcdma_csg_info \n
       - 0x400000000 -- NAS_LIMIT_BY_LTE_CSG_ INFO -- Limit by lte_csg_info \n
       - 0x800000000 -- NAS_LIMIT_BY_SRV_STATUS_ TOGGLE -- Limit by service status toggle \n
       - 0x1000000000 -- NAS_LIMIT_BY_SRV_RAT_TECH_ CHANGE -- Limit by service RAT Technology change

       \vspace{3pt}
       All other bits are reserved for future use.
  */
}nas_get_sys_info_ind_reporting_limit_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_CALL_TYPE_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_CALL_TYPE_E_VOICE_V01 = 0, 
  NAS_CALL_TYPE_E_SMS_V01 = 1, 
  NAS_CALL_TYPE_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_call_type_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  IMS Preferred Call Types */
  nas_call_type_enum_type_v01 call_type;
  /**<   Call type for which IMS is preferred. Values: \n 
       - 0x00 -- CALL_TYPE_E_VOICE -- Voice \n 
       - 0x01 -- CALL_TYPE_E_SMS -- SMS
  */

  /*  Is IMS Registered */
  uint8_t is_registered;
  /**<   Whether IMS is registered. Values: \n
       - 0 -- Not registered \n
       - 1 -- Registered
  */
}nas_ims_registration_state_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_IMS_REG_END_CAUSE_E_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_IMS_REG_END_CAUSE_NORMAL_V01 = 0, /**<  No failure to report \n  */
  NAS_IMS_REG_END_CAUSE_TEMPORARY_V01 = 1, /**<  Temporary failure from IMS \n  */
  NAS_IMS_REG_END_CAUSE_BLOCK_TILL_POWER_CYCLE_V01 = 2, /**<  Block PLMN until power cycle  */
  NAS_IMS_REG_END_CAUSE_E_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_ims_reg_end_cause_e_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Updates the IMS registration status. */
typedef struct {

  /* Mandatory */
  /*  Radio Access Technology */
  nas_radio_if_enum_v01 sys_mode;
  /**<   Radio interface system mode. Values: \n 
       - 0x02 -- RADIO_IF_CDMA_1XEVDO -- 
         cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
       - 0x04 -- RADIO_IF_GSM         -- GSM \n
       - 0x05 -- RADIO_IF_UMTS        -- UMTS \n
       - 0x06 -- RADIO_IF_WLAN        -- WLAN \n
       - 0x08 -- RADIO_IF_LTE         -- LTE
  */

  /* Mandatory */
  /*  IMS Registration State */
  uint32_t registration_state_len;  /**< Must be set to # of elements in registration_state */
  nas_ims_registration_state_type_v01 registration_state[NAS_IMS_REG_STATUS_MAX_V01];

  /* Optional */
  /*  IMS Registration End Cause */
  uint8_t registration_end_cause_valid;  /**< Must be set to true if registration_end_cause is being passed */
  nas_ims_reg_end_cause_e_type_v01 registration_end_cause;
  /**<   IMS registration end cause. Values: \n
      - NAS_IMS_REG_END_CAUSE_NORMAL (0) --  No failure to report \n 
      - NAS_IMS_REG_END_CAUSE_TEMPORARY (1) --  Temporary failure from IMS \n 
      - NAS_IMS_REG_END_CAUSE_BLOCK_TILL_POWER_CYCLE (2) --  Block PLMN until power cycle 
 */

  /* Optional */
  /*  IMS Registration Backoff Timer */
  uint8_t retry_timer_valid;  /**< Must be set to true if retry_timer is being passed */
  uint32_t retry_timer;
  /**<   IMS registration backoff timer (in seconds).
  */
}nas_update_ims_status_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Updates the IMS registration status. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type.*/
}nas_update_ims_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the IMS preference status. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_ims_pref_status_req_msg_v01;

  /* Message */
/**
    @}
  */

typedef uint64_t nas_call_type_mask_type_v01;
#define NAS_CALL_TYPE_B_VOICE_V01 ((nas_call_type_mask_type_v01)0x01ull) 
#define NAS_CALL_TYPE_B_SMS_V01 ((nas_call_type_mask_type_v01)0x02ull) 
/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Current radio access technology */
  nas_radio_if_enum_v01 sys_mode;
  /**<   Radio interface system mode. Values: \n 
       - 0x02 -- RADIO_IF_CDMA_1XEVDO -- 
         cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
       - 0x04 -- RADIO_IF_GSM         -- GSM \n
       - 0x05 -- RADIO_IF_UMTS        -- UMTS \n
       - 0x08 -- RADIO_IF_LTE         -- LTE
  */

  nas_call_type_mask_type_v01 ims_pref_call_type;
  /**<   Bitmask representing the IMS preferred call type. 
       Bits for call types preferring IMS must be set to 1.
       Otherwise, the bits must be set to 0. \n
       Values: \n
       - Bit 0 (0x01) -- NAS_CALL_TYPE_B_VOICE -- Voice \n
       - Bit 1 (0x02) -- NAS_CALL_TYPE_B_SMS   -- SMS
  */
}nas_ims_pref_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the IMS preference status. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type.*/

  /* Optional */
  /*  IMS Preference Information */
  uint8_t ims_pref_valid;  /**< Must be set to true if ims_pref is being passed */
  nas_ims_pref_type_v01 ims_pref;
}nas_get_ims_pref_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Reports a change in the IMS preference.  */
typedef struct {

  /* Mandatory */
  /*  IMS Preference Information */
  nas_ims_pref_type_v01 ims_pref;
}nas_ims_pref_status_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Configures whether QMI_NAS_CURRENT_PLMN_NAME_IND returns the 
              modem-determined name or all available information. */
typedef struct {

  /* Mandatory */
  /*  Current PLMN Name Ind Send All Information */
  uint8_t send_all_information;
  /**<   Indicates that QMI_NAS_CURRENT_PLMN_NAME_IND is to contain all available
       names, regardless of display condition. Values: \n
       - 0x00 -- FALSE (default value) \n
       - 0x01 -- TRUE
  */
}nas_config_plmn_name_ind_reporting_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Configures whether QMI_NAS_CURRENT_PLMN_NAME_IND returns the 
              modem-determined name or all available information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type.*/
}nas_config_plmn_name_ind_reporting_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_AVOID_SYS_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_AVOID_SYS_USERZONE_V01 = 0x00, /**<  Avoid an idle system if the mobile station has a user zone currently 
       selected \n   */
  NAS_AVOID_SYS_IDLE_V01 = 0x01, /**<  Avoid an idle system \n  */
  NAS_AVOID_SYS_CLR_LIST_V01 = 0x02, /**<  Clear all avoid system lists  */
  NAS_AVOID_SYS_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_avoid_sys_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Facilitates avoiding a CDMA system and clearing the avoided 
              systems list. */
typedef struct {

  /* Mandatory */
  /*  Avoid System Information */
  nas_avoid_sys_type_v01 avoid_type;
  /**<   Avoid system type. Values: \n 
      - NAS_AVOID_SYS_USERZONE (0x00) --  Avoid an idle system if the mobile station has a user zone currently 
       selected \n  
      - NAS_AVOID_SYS_IDLE (0x01) --  Avoid an idle system \n 
      - NAS_AVOID_SYS_CLR_LIST (0x02) --  Clear all avoid system lists 
 */
}nas_cdma_avoid_system_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Facilitates avoiding a CDMA system and clearing the avoided 
              systems list. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type.*/
}nas_cdma_avoid_system_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the list of previously avoided CDMA systems. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_cdma_avoid_system_list_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t sid;
  /**<   System ID. */

  uint16_t nid;
  /**<   Network ID. */

  uint16_t mnc;
  /**<   A 16-bit integer representation of MNC. Range: 0 to 999.
  */

  uint16_t mcc;
  /**<   A 16-bit integer representation of MCC. Range: 0 to 999.
  */
}nas_cdma_avoid_sys_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the list of previously avoided CDMA systems. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */

  /* Optional */
  /*  Avoided Systems List */
  uint8_t nam1_systems_valid;  /**< Must be set to true if nam1_systems is being passed */
  uint32_t nam1_systems_len;  /**< Must be set to # of elements in nam1_systems */
  nas_cdma_avoid_sys_info_type_v01 nam1_systems[NAS_MAX_CDMA_SYSTEMS_AVOIDED_V01];
}nas_get_cdma_avoid_system_list_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets the HPLMN search timer in the modem. */
typedef struct {

  /* Mandatory */
  /*  HPLMN Search Timer */
  uint32_t timer_value;
  /**<   HPLMN search timer (in minutes). 
       A timer value of 0xFFFFFFFF means use the SIM-defined timer.
  */
}nas_set_hplmn_search_timer_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets the HPLMN search timer in the modem. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */
}nas_set_hplmn_search_timer_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the HPLMN search timer. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_hplmn_search_timer_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the HPLMN search timer. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type.*/

  /* Optional */
  /*  HPLMN Search Timer */
  uint8_t timer_value_valid;  /**< Must be set to true if timer_value is being passed */
  uint32_t timer_value;
  /**<   HPLMN search timer (in minutes).
  */
}nas_get_hplmn_search_timer_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Queries the current subscription information. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_subscription_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Queries the current subscription information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */

  /* Optional */
  /*  Priority Subscription Info */
  uint8_t is_priority_subs_valid;  /**< Must be set to true if is_priority_subs is being passed */
  nas_is_priority_subs_enum_v01 is_priority_subs;
  /**<  
       Information on whether the subscription is a priority subscription 
       in cases of dual standby. Values: \n
       - 0x00 -- Not a priority subscription \n
       - 0x01 -- Priority subscription
  */

  /* Optional */
  /*  Active Subscription Info */
  uint8_t is_active_valid;  /**< Must be set to true if is_active is being passed */
  nas_active_subs_info_enum_v01 is_active;
  /**<  
       Information on whether the subscription is active. Values: \n
       - 0x00 -- Not active \n
       - 0x01 -- Active
  */

  /* Optional */
  /*  Default Data Subscription Info (Deprecated; use QMI DSD service to determine default data subscription) */
  uint8_t is_default_data_subs_valid;  /**< Must be set to true if is_default_data_subs is being passed */
  uint8_t is_default_data_subs;
  /**<  
       Information on whether the subscription is the default data
       subscription in cases of dual standby. Values: \n
       - 0x00 -- FALSE; not a default data subscription \n
       - 0x01 -- TRUE; default data subscription
  */

  /* Optional */
  /*  Voice System ID */
  uint8_t voice_system_id_valid;  /**< Must be set to true if voice_system_id is being passed */
  uint32_t voice_system_id;
  /**<   Voice system ID.
  */

  /* Optional */
  /*  LTE Voice System ID */
  uint8_t lte_voice_system_id_valid;  /**< Must be set to true if lte_voice_system_id is being passed */
  uint32_t lte_voice_system_id;
  /**<   LTE Voice system ID.
 */

  /* Optional */
  /*  WLAN Voice System ID */
  uint8_t wlan_voice_system_id_valid;  /**< Must be set to true if wlan_voice_system_id is being passed */
  uint32_t wlan_voice_system_id;
  /**<   WLAN Voice system ID.
 */

  /* Optional */
  /*  Default Data Subscription Type (Deprecated; use QMI DSD service to determine DDS type) */
  uint8_t dds_type_valid;  /**< Must be set to true if dds_type is being passed */
  nas_dds_type_enum_v01 dds_type;
  /**<   This TLV is only sent when is_default_data_subs is set to TRUE.
 */

  /* Optional */
  /*  NR5G Voice System ID */
  uint8_t nr5g_voice_system_id_valid;  /**< Must be set to true if nr5g_voice_system_id is being passed */
  uint32_t nr5g_voice_system_id;
  /**<   NR5G voice system ID.
 */
}nas_get_subscription_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the latest time change reported by the network. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_network_time_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_julian_time_type_v01 universal_time;
  /**<   Universal time. */

  int8_t time_zone;
  /**<   Offset from Universal time, i.e., the difference between local time
       and Universal time, in increments of 15 min (signed value).
  */

  uint8_t daylt_sav_adj;
  /**<   Daylight saving adjustment in hours. Possible values: 0, 1, and 2. This 
       field is ignored if radio_if is NAS_RADIO_IF_CDMA_1XEVDO.
  */

  /*  Radio Interface */
  nas_radio_if_enum_v01 radio_if;
  /**<  
    Radio interface from which the information comes. Values: \n
    - 0x01 -- NAS_RADIO_IF_CDMA_1X     -- 
      cdma2000\textsuperscript{\textregistered} 1X             \n
    - 0x02 -- NAS_RADIO_IF_CDMA_1XEVDO -- 
      cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
    - 0x04 -- NAS_RADIO_IF_GSM         -- GSM \n
    - 0x05 -- NAS_RADIO_IF_UMTS        -- UMTS \n
    - 0x08 -- NAS_RADIO_IF_LTE         -- LTE \n
    - 0x09 -- NAS_RADIO_IF_TDSCDMA     -- TD-SCDMA \n
    - 0x0C -- NAS_RADIO_IF_NR5G        -- NR5G
  */
}nas_network_time_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the latest time change reported by the network. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */

  /* Optional */
  /*  3GPP2 Time Information */
  uint8_t nas_3gpp2_time_valid;  /**< Must be set to true if nas_3gpp2_time is being passed */
  nas_network_time_type_v01 nas_3gpp2_time;

  /* Optional */
  /*  3GPP Time Information */
  uint8_t nas_3gpp_time_valid;  /**< Must be set to true if nas_3gpp_time is being passed */
  nas_network_time_type_v01 nas_3gpp_time;
}nas_get_network_time_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the LTE network time from the UE. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_lte_sib16_network_time_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Year */
  uint16_t year;
  /**<   Year.
  */

  /*  Month */
  uint8_t month;
  /**<   Month. 1 is January and 12 is December.
  */

  /*  Day */
  uint8_t day;
  /**<   Day. Range: 1 to 31.
  */

  /*  Hour */
  uint8_t hour;
  /**<   Hour. Range: 0 to 23.
  */

  /*  Minute */
  uint8_t minute;
  /**<   Minute. Range: 0 to 59.
  */

  /*  Second */
  uint8_t second;
  /**<   Second. Range: 0 to 59.
  */

  /*  MilliSecond */
  uint16_t millisecond;
  /**<   Millisecond. Range: 0 to 999.
  */

  /*  Day of the week */
  uint8_t day_of_week;
  /**<   Day of the week. 0 is Monday and 6 is Sunday.
  */
}nas_lte_sib16_julian_time_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the LTE network time from the UE. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */

  /* Optional */
  /*  LTE SIB16 Coverage Status */
  uint8_t lte_sib16_acquired_valid;  /**< Must be set to true if lte_sib16_acquired is being passed */
  nas_tri_state_boolean_type_v01 lte_sib16_acquired;
  /**<  
 Whether LTE SIB16 is acquired. Values: \n
      - NAS_TRI_FALSE (0) --  Status: FALSE \n 
      - NAS_TRI_TRUE (1) --  Status: TRUE  \n 
      - NAS_TRI_UNKNOWN (2) --  Status: Unknown  
 */

  /* Optional */
  /*  Universal Time */
  uint8_t universal_time_valid;  /**< Must be set to true if universal_time is being passed */
  nas_lte_sib16_julian_time_type_v01 universal_time;

  /* Optional */
  /*  Absolute Time */
  uint8_t abs_time_valid;  /**< Must be set to true if abs_time is being passed */
  uint64_t abs_time;
  /**<   Absolute time in milliseconds since \n
       Jan 6, 1980 00:00:00 hr.
  */

  /* Optional */
  /*  Leap Second */
  uint8_t leap_sec_valid;  /**< Must be set to true if leap_sec is being passed */
  int8_t leap_sec;
  /**<   Leap second.
  */

  /* Optional */
  /*  Time Zone */
  uint8_t time_zone_valid;  /**< Must be set to true if time_zone is being passed */
  int8_t time_zone;
  /**<   Offset from Universal time, i.e., the difference between local time
       and Universal time, in increments of 15 min (signed value).
  */

  /* Optional */
  /*  Daylight Saving Adjustment */
  uint8_t daylt_sav_adj_valid;  /**< Must be set to true if daylt_sav_adj is being passed */
  uint8_t daylt_sav_adj;
  /**<   Daylight saving adjustment in hours. Possible values: 0, 1, and 2.
  */
}nas_get_lte_sib16_network_time_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates an LTE time change reported by the network.  */
typedef struct {

  /* Optional */
  /*  LTE SIB16 Coverage Status */
  uint8_t lte_sib16_acquired_valid;  /**< Must be set to true if lte_sib16_acquired is being passed */
  nas_tri_state_boolean_type_v01 lte_sib16_acquired;
  /**<  
 Whether LTE SIB16 is acquired. Values: \n
      - NAS_TRI_FALSE (0) --  Status: FALSE \n 
      - NAS_TRI_TRUE (1) --  Status: TRUE  \n 
      - NAS_TRI_UNKNOWN (2) --  Status: Unknown  
 */

  /* Optional */
  /*  Universal Time */
  uint8_t universal_time_valid;  /**< Must be set to true if universal_time is being passed */
  nas_lte_sib16_julian_time_type_v01 universal_time;

  /* Optional */
  /*  Absolute Time */
  uint8_t abs_time_valid;  /**< Must be set to true if abs_time is being passed */
  uint64_t abs_time;
  /**<   Absolute time in milliseconds since \n
       Jan 6, 1980 00:00:00 hr.
  */

  /* Optional */
  /*  Leap Second */
  uint8_t leap_sec_valid;  /**< Must be set to true if leap_sec is being passed */
  int8_t leap_sec;
  /**<   Leap second.
  */

  /* Optional */
  /*  Time Zone */
  uint8_t time_zone_valid;  /**< Must be set to true if time_zone is being passed */
  int8_t time_zone;
  /**<   Offset from Universal time, i.e., the difference between local time
       and Universal time, in increments of 15 min (signed value).
  */

  /* Optional */
  /*  Daylight Saving Adjustment */
  uint8_t daylt_sav_adj_valid;  /**< Must be set to true if daylt_sav_adj is being passed */
  uint8_t daylt_sav_adj;
  /**<   Daylight saving adjustment in hours. Possible values: 0, 1, and 2.
  */
}nas_lte_sib16_network_time_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets the priority for LTE bands. */
typedef struct {

  /* Mandatory */
  /*  LTE Band Priority List */
  uint32_t band_priority_list_len;  /**< Must be set to # of elements in band_priority_list */
  nas_active_band_enum_v01 band_priority_list[NAS_LTE_BAND_PRIORITY_LIST_MAX_V01];
  /**<   Priority list for LTE bands 
       (see Table @latexonly\ref{tbl:bandClass}@endlatexonly for details). 
       Values: \n
       - 120 to 174 -- LTE band classes
  */
}nas_set_lte_band_priority_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets the priority for LTE bands. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */
}nas_set_lte_band_priority_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the current signal quality at L1 for each MBSFN area. */
typedef struct {

  /* Optional */
  /*  Trace ID */
  uint8_t trace_id_valid;  /**< Must be set to true if trace_id is being passed */
  int16_t trace_id;
  /**<   Trace ID.  Values: \n
       - 0 to 32768 -- Valid trace ID \n
       - -1 -- Trace ID is not used
  */
}nas_get_embms_sig_ext_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  MRB ID */
  uint8_t mrb_id;
  /**<   Multicast radio bearer ID for the session.
  */

  /*  Session ID Valid */
  uint8_t session_id_valid;
  /**<   Indicates whether session ID information is available.
  */

  /*  Session ID */
  uint8_t session_id;
  /**<   Session ID for the session; valid only when session_id_valid is TRUE.
  */

  /*  TMGI Identifier */
  uint8_t tmgi_identifier[NAS_TMGI_IDENTIFIER_LEN_V01];
  /**<   TMGI identifier, consisting of service ID + PLMN ID.
  */
}nas_embms_tmgi_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  MBSFN Area ID */
  uint8_t area_id;
  /**<   Multicast Broadcast Single Frequency Network (MBSFN) area ID. 
    Values: 0 to 255.
  */

  /*  SNR */
  float snr;
  /**<   Average SNR of the serving cell over the last measurement period in
    decibels.
   */

  /*  Excess SNR */
  float excess_snr;
  /**<   Excess SNR of the serving cell over the last measurement period in
       decibels.
   */

  /*  Active TMGI sessions */
  uint32_t tmgi_info_len;  /**< Must be set to # of elements in tmgi_info */
  nas_embms_tmgi_type_v01 tmgi_info[NAS_TMGI_BEARER_INFO_MAX_V01];
  /**<   Array of the active TMGI sessions.
  */
}nas_lte_embms_signal_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the current signal quality at L1 for each MBSFN area. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type.
 Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */

  /* Optional */
  /*  Trace ID */
  uint8_t trace_id_valid;  /**< Must be set to true if trace_id is being passed */
  int16_t trace_id;
  /**<   Trace ID.  Values: \n
       - 0 to 32768 -- Valid trace ID \n
       - -1 -- Trace ID is not used
  */

  /* Optional */
  /*  Signal Quality and TMGI */
  uint8_t snr_and_tmgi_list_valid;  /**< Must be set to true if snr_and_tmgi_list is being passed */
  uint32_t snr_and_tmgi_list_len;  /**< Must be set to # of elements in snr_and_tmgi_list */
  nas_lte_embms_signal_type_v01 snr_and_tmgi_list[NAS_LTE_EMBMS_MAX_MBSFN_AREA_V01];
}nas_get_embms_sig_ext_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_SCELL_STATE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_LTE_CPHY_SCELL_STATE_DECONFIGURED_V01 = 0x00, /**<  Deconfigured \n  */
  NAS_LTE_CPHY_SCELL_STATE_CONFIGURED_DEACTIVATED_V01 = 0x01, /**<  Configured and deactivated \n  */
  NAS_LTE_CPHY_SCELL_STATE_CONFIGURED_ACTIVATED_V01 = 0x02, /**<  Configured and activated  */
  NAS_SCELL_STATE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_scell_state_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_LTE_CPHY_CA_BANDWIDTH_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_LTE_CPHY_CA_BW_NRB_6_V01 = 0x00, /**<  1.4 MHz bandwidth \n  */
  NAS_LTE_CPHY_CA_BW_NRB_15_V01 = 0x01, /**<  3 MHz bandwidth \n  */
  NAS_LTE_CPHY_CA_BW_NRB_25_V01 = 0x02, /**<  5 MHz bandwidth \n  */
  NAS_LTE_CPHY_CA_BW_NRB_50_V01 = 0x03, /**<  10 MHz bandwidth \n  */
  NAS_LTE_CPHY_CA_BW_NRB_75_V01 = 0x04, /**<  15 MHz bandwidth \n  */
  NAS_LTE_CPHY_CA_BW_NRB_100_V01 = 0x05, /**<  20 MHz bandwidth  */
  NAS_LTE_CPHY_CA_BANDWIDTH_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_lte_cphy_ca_bandwidth_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t pci;
  /**<   Physical cell ID of the Scell. Range: 0 to 503.
  */

  uint16_t freq;
  /**<   Absolute cell's frequency. Range: 0 to 65535.
  */

  nas_scell_state_enum_v01 scell_state;
  /**<   Scell state. Values: \n
      - NAS_LTE_CPHY_SCELL_STATE_DECONFIGURED (0x00) --  Deconfigured \n 
      - NAS_LTE_CPHY_SCELL_STATE_CONFIGURED_DEACTIVATED (0x01) --  Configured and deactivated \n 
      - NAS_LTE_CPHY_SCELL_STATE_CONFIGURED_ACTIVATED (0x02) --  Configured and activated 

 \vspace{3pt}
 All other values are reserved.
 */
}nas_lte_cphy_ca_indicator_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t pci;
  /**<   Physical cell ID of the Scell. Range: 0 to 503.
  */

  uint16_t freq;
  /**<   Absolute cell's frequency. Range: 0 to 65535.
  */

  nas_lte_cphy_ca_bandwidth_enum_v01 cphy_ca_dl_bandwidth;
  /**<   Downlink bandwidth. Values: \n
      - NAS_LTE_CPHY_CA_BW_NRB_6 (0x00) --  1.4 MHz bandwidth \n 
      - NAS_LTE_CPHY_CA_BW_NRB_15 (0x01) --  3 MHz bandwidth \n 
      - NAS_LTE_CPHY_CA_BW_NRB_25 (0x02) --  5 MHz bandwidth \n 
      - NAS_LTE_CPHY_CA_BW_NRB_50 (0x03) --  10 MHz bandwidth \n 
      - NAS_LTE_CPHY_CA_BW_NRB_75 (0x04) --  15 MHz bandwidth \n 
      - NAS_LTE_CPHY_CA_BW_NRB_100 (0x05) --  20 MHz bandwidth 

 \vspace{3pt}
 All other values are reserved.
 */

  nas_active_band_enum_v01 band;
  /**<    Band. Values: \n
        - 120 to 174 -- LTE band classes
  */

  nas_scell_state_enum_v01 scell_state;
  /**<   Scell state. Values: \n
      - NAS_LTE_CPHY_SCELL_STATE_DECONFIGURED (0x00) --  Deconfigured \n 
      - NAS_LTE_CPHY_SCELL_STATE_CONFIGURED_DEACTIVATED (0x01) --  Configured and deactivated \n 
      - NAS_LTE_CPHY_SCELL_STATE_CONFIGURED_ACTIVATED (0x02) --  Configured and activated 

 \vspace{3pt}
 All other values are reserved.
 */
}nas_lte_cphy_scell_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_lte_cphy_scell_info_type_v01 scell_info;

  uint8_t scell_idx;
  /**<   Scell index. Range: 0 to 7.
  */
}nas_cphy_scell_info_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t pci;
  /**<   Physical cell ID of the Pcell. Range: 0 to 503.
  */

  uint16_t freq;
  /**<   Absolute cell's frequency. Range: 0 to 65535.
  */

  nas_lte_cphy_ca_bandwidth_enum_v01 cphy_ca_dl_bandwidth;
  /**<   Downlink bandwidth. Values: \n
      - NAS_LTE_CPHY_CA_BW_NRB_6 (0x00) --  1.4 MHz bandwidth \n 
      - NAS_LTE_CPHY_CA_BW_NRB_15 (0x01) --  3 MHz bandwidth \n 
      - NAS_LTE_CPHY_CA_BW_NRB_25 (0x02) --  5 MHz bandwidth \n 
      - NAS_LTE_CPHY_CA_BW_NRB_50 (0x03) --  10 MHz bandwidth \n 
      - NAS_LTE_CPHY_CA_BW_NRB_75 (0x04) --  15 MHz bandwidth \n 
      - NAS_LTE_CPHY_CA_BW_NRB_100 (0x05) --  20 MHz bandwidth 

 \vspace{3pt}
 All other values are reserved.
 */

  nas_active_band_enum_v01 band;
  /**<    Band. Values: \n
        - 120 to 174 -- LTE band classes
  */
}nas_lte_cphy_pcell_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates a carrier aggregation event has occurred. 
             \label{idl:lteCphyCAInd} */
typedef struct {

  /* Mandatory */
  /*  Physical Carrier Aggregation of Scell Indicator Type */
  nas_lte_cphy_ca_indicator_type_v01 cphy_ca;

  /* Optional */
  /*  Physical Carrier Aggregation Downlink Bandwidth for Scell */
  uint8_t cphy_ca_dl_bandwidth_valid;  /**< Must be set to true if cphy_ca_dl_bandwidth is being passed */
  nas_lte_cphy_ca_bandwidth_enum_v01 cphy_ca_dl_bandwidth;
  /**<   Downlink bandwidth. Values: \n
      - NAS_LTE_CPHY_CA_BW_NRB_6 (0x00) --  1.4 MHz bandwidth \n 
      - NAS_LTE_CPHY_CA_BW_NRB_15 (0x01) --  3 MHz bandwidth \n 
      - NAS_LTE_CPHY_CA_BW_NRB_25 (0x02) --  5 MHz bandwidth \n 
      - NAS_LTE_CPHY_CA_BW_NRB_50 (0x03) --  10 MHz bandwidth \n 
      - NAS_LTE_CPHY_CA_BW_NRB_75 (0x04) --  15 MHz bandwidth \n 
      - NAS_LTE_CPHY_CA_BW_NRB_100 (0x05) --  20 MHz bandwidth 

 \vspace{3pt}
 All other values are reserved.
 */

  /* Optional */
  /*  Scell Information */
  uint8_t scell_info_valid;  /**< Must be set to true if scell_info is being passed */
  nas_lte_cphy_scell_info_type_v01 scell_info;
  /**<   Contains the information for the Scell which has state change since last indication. /n
       If the frequency field is non-zero, it is the true frequency; if it is zero,
       the true frequency may be found in the 'Scell Extended Frequency' TLV. The
       'Scell Extended Frequency' TLV always holds the true frequency and can always
       be used regardless of the value in the frequency field of this TLV.
  */

  /* Optional */
  /*  Pcell Information */
  uint8_t pcell_info_valid;  /**< Must be set to true if pcell_info is being passed */
  nas_lte_cphy_pcell_info_type_v01 pcell_info;
  /**<   Contains all Pcell info. /n
       If the frequency field is non-zero, it is the true frequency; if it is zero,
       the true frequency may be found in the 'Pcell Extended Frequency' TLV. The
       'Pcell Extended Frequency' TLV always holds the true frequency and can always
       be used regardless of the value in the frequency field of this TLV.
  */

  /* Optional */
  /*  Scell Index */
  uint8_t scell_idx_valid;  /**< Must be set to true if scell_idx is being passed */
  uint8_t scell_idx;
  /**<   Scell index. */

  /* Optional */
  /*  Aggregated DL Bandwidth */
  uint8_t cphy_ca_aggregated_dl_bandwidth_valid;  /**< Must be set to true if cphy_ca_aggregated_dl_bandwidth is being passed */
  uint16_t cphy_ca_aggregated_dl_bandwidth;
  /**<   Aggregated DL bandwidth. \n
       Units: MHz
  */

  /* Optional */
  /*  Number of Scells Configured */
  uint8_t num_scells_configured_valid;  /**< Must be set to true if num_scells_configured is being passed */
  uint16_t num_scells_configured;
  /**<   Number of Scells configured.
  */

  /* Optional */
  /*  Unchanged Configured Scell Information Array */
  uint8_t unchanged_scell_info_list_valid;  /**< Must be set to true if unchanged_scell_info_list is being passed */
  uint32_t unchanged_scell_info_list_len;  /**< Must be set to # of elements in unchanged_scell_info_list */
  nas_cphy_scell_info_v01 unchanged_scell_info_list[NAS_MAX_SCELL_LIST_LEN_V01];
  /**<   If a Scell state is changed, it is not included in this array. \n
       If the frequency field is non-zero, it is the true frequency; if it is zero, the true
       frequency may be found in the 'Unchanged Configured Scell Extended Frequency Array'
       TLV. The 'Unchanged Configured Scell Extended Frequency Array' TLV always holds the
       true frequency and can always be used regardless of the value in the frequency field
       of this TLV.
  */

  /* Optional */
  /*  Scell Extended Frequency */
  uint8_t scell_freq_valid;  /**< Must be set to true if scell_freq is being passed */
  uint32_t scell_freq;
  /**<   Scell frequency - extended size \n
       This TLV should be used in place of the frequency field from the 'Scell Information' TLV
  */

  /* Optional */
  /*  Pcell Extended Frequency */
  uint8_t pcell_freq_valid;  /**< Must be set to true if pcell_freq is being passed */
  uint32_t pcell_freq;
  /**<   Pcell frequency - extended size \n
       This TLV should be used in place of the frequency field from the 'Pcell Information' TLV
  */

  /* Optional */
  /*  Unchanged Configured Scell Extended Frequency Array */
  uint8_t unchanged_scell_freq_list_valid;  /**< Must be set to true if unchanged_scell_freq_list is being passed */
  uint32_t unchanged_scell_freq_list_len;  /**< Must be set to # of elements in unchanged_scell_freq_list */
  uint32_t unchanged_scell_freq_list[NAS_MAX_SCELL_LIST_LEN_V01];
  /**<   Unchanged scell freqeuncy list - extended size \n
       This TLV should be used in place of the frequency field from
       the 'Unchanged Configured Scell Information Array' TLV
  */
}nas_lte_cphy_ca_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Gets the list of priority LTE bands. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_lte_band_priority_list_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Gets the list of priority LTE bands. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */

  /* Optional */
  /*  LTE Band Priority List */
  uint8_t configured_band_priority_list_valid;  /**< Must be set to true if configured_band_priority_list is being passed */
  uint32_t configured_band_priority_list_len;  /**< Must be set to # of elements in configured_band_priority_list */
  nas_active_band_enum_v01 configured_band_priority_list[NAS_LTE_BAND_PRIORITY_LIST_MAX_V01];
  /**<   List of the user-configured LTE bands, ordered by priority. The ordering 
       of this list overrides the ordering of any bands it shares with 
       supported_band_priority_list. Values: \n
       - 120 to 174 -- LTE band classes (see Table @latexonly\ref{tbl:bandClass}@endlatexonly for details)
  */

  /* Optional */
  /*  LTE Supported Band Priority List */
  uint8_t supported_band_priority_list_valid;  /**< Must be set to true if supported_band_priority_list is being passed */
  uint32_t supported_band_priority_list_len;  /**< Must be set to # of elements in supported_band_priority_list */
  nas_active_band_enum_v01 supported_band_priority_list[NAS_LTE_BAND_PRIORITY_LIST_MAX_V01];
  /**<   List of the LTE bands supported by the device, ordered by priority. 
	   Values: \n
	   - 120 to 174 -- LTE band classes (see Table @latexonly\ref{tbl:bandClass}@endlatexonly for details)
  */
}nas_get_lte_band_priority_list_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t plmn[3];
  /**<   PLMN. */

  uint16_t access_tech;
  /**<   Access technology identifier. */
}nas_oplmn_entry_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  List ID */
  uint32_t list_id;
  /**<   Unique ID for the OPLMN list.
  */

  /*  Total List Entries */
  uint32_t total_list_entries;
  /**<   Total number of OPLMN entries in the list. 
       For example, if the list is a total of 500 entries and is sent in 
	   multiple requests, total_list_entries is set to 500 in all requests.
  */

  uint32_t oplmn_len;  /**< Must be set to # of elements in oplmn */
  nas_oplmn_entry_type_v01 oplmn[NAS_MAX_BUILTIN_OPLMN_ENTRIES_V01];
  /**<   OPLMN list. Refer to 
       \hyperref[STD-31102]{3GPP TS 31.102} Section 4.2.53 for coding of PLMN 
       and access technology identifier.
  */
}nas_oplmn_list_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets the built-in PLMN list. */
typedef struct {

  /* Optional */
  /*  OPLMN List */
  uint8_t oplmn_list_valid;  /**< Must be set to true if oplmn_list is being passed */
  nas_oplmn_list_type_v01 oplmn_list;

  /* Optional */
  /*  Indication Token */
  uint8_t ind_token_valid;  /**< Must be set to true if ind_token is being passed */
  uint32_t ind_token;
  /**<   Token used to identify the indication sent when the request is complete.
  */
}nas_set_builtin_plmn_list_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets the built-in PLMN list. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */
}nas_set_builtin_plmn_list_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Sets the built-in PLMN list. */
typedef struct {

  /* Mandatory */
  /*  Indication Error Code */
  qmi_error_type_v01 error;
  /**<   Error code. Values: \n
       - 0x0000 -- QMI_ERR_NONE                -- Success \n
       - 0x0002 -- QMI_ERR_NO_MEMORY           -- Insufficient memory to store 
                                                  the list \n
       - 0x0003 -- QMI_ERR_INTERNAL            -- Internal error \n
       - 0x002D -- QMI_ERR_INVALID_DATA_FORMAT -- Invalid data format
  */

  /* Optional */
  /*  Indication Token */
  uint8_t ind_token_valid;  /**< Must be set to true if ind_token is being passed */
  uint32_t ind_token;
  /**<   Indication token.
  */

  /* Optional */
  /*  Received List Entry Count */
  uint8_t received_list_entry_count_valid;  /**< Must be set to true if received_list_entry_count is being passed */
  uint32_t received_list_entry_count;
  /**<   Total number of PLMN entries received currently.
  */

  /* Optional */
  /*  Remaining List Entry Count */
  uint8_t remaining_list_entry_count_valid;  /**< Must be set to true if remaining_list_entry_count is being passed */
  uint32_t remaining_list_entry_count;
  /**<   Total number of PLMN entries still expected to complete the list.
  */
}nas_set_builtin_plmn_list_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Performs the network scan and gives results incrementally. */
typedef struct {

  /* Optional */
  /*  Network Type */
  uint8_t network_type_valid;  /**< Must be set to true if network_type is being passed */
  nas_network_type_mask_type_v01 network_type;
  /**<   Bitmask representing the network type to scan. Values: \n
       - Bit 0 -- GSM \n
       - Bit 1 -- UMTS \n
       - Bit 2 -- LTE \n
       - Bit 3 -- TD-SCDMA \n
       - Bit 4 -- NR5G \n
       Any combination of the bit positions can be used.  If the mask is
       sent with no bits set, the scan is performed using the currently 
       set preference.
    */

  /* Optional */
  /*  Scan Type */
  uint8_t scan_type_valid;  /**< Must be set to true if scan_type is being passed */
  nas_nw_scan_type_enum_v01 scan_type;
  /**<   Network scan type. Values: \n
      - NAS_SCAN_TYPE_PLMN (0x00) --  PLMN (default) \n 
      - NAS_SCAN_TYPE_CSG (0x01) --  Closed subscriber group \n 
      - NAS_SCAN_TYPE_MODE_PREF (0x02) --  Mode preference \n 
      - NAS_SCAN_TYPE_PCI (0x03) --  Physical cell ID 
 */

  /* Optional */
  /*  Band Preference */
  uint8_t band_pref_valid;  /**< Must be set to true if band_pref is being passed */
  nas_band_pref_mask_type_v01 band_pref;
  /**<   Bitmask representing the band preference to be scanned.  
       See Table @latexonly\ref{tbl:bandPreference}@endlatexonly 
       for details.   
  */

  /* Optional */
  /*  LTE Band Preference */
  uint8_t lte_band_pref_valid;  /**< Must be set to true if lte_band_pref is being passed */
  lte_band_pref_mask_type_v01 lte_band_pref;
  /**<   Bitmask representing the LTE band preference to be scanned. 
       See Table @latexonly\ref{tbl:lteBandPreference}@endlatexonly 
       for details.  
  */

  /* Optional */
  /*  TDSCDMA Band Preference */
  uint8_t tdscdma_band_pref_valid;  /**< Must be set to true if tdscdma_band_pref is being passed */
  nas_tdscdma_band_pref_mask_type_v01 tdscdma_band_pref;
  /**<   Bitmask representing the TD-SCDMA band preference to be scanned. Values: \n
      - NAS_TDSCDMA_BAND_A (0x01) --  TD-SCDMA Band A \n 
      - NAS_TDSCDMA_BAND_B (0x02) --  TD-SCDMA Band B \n 
      - NAS_TDSCDMA_BAND_C (0x04) --  TD-SCDMA Band C \n 
      - NAS_TDSCDMA_BAND_D (0x08) --  TD-SCDMA Band D \n 
      - NAS_TDSCDMA_BAND_E (0x10) --  TD-SCDMA Band E \n 
      - NAS_TDSCDMA_BAND_F (0x20) --  TD-SCDMA Band F 

 \vspace{3pt}
 All other bits are reserved and must be set to 0.
 */

  /* Optional */
  /*  WCDMA ARFCN List ** */
  uint8_t wcdma_arfcn_valid;  /**< Must be set to true if wcdma_arfcn is being passed */
  uint32_t wcdma_arfcn_len;  /**< Must be set to # of elements in wcdma_arfcn */
  uint16_t wcdma_arfcn[NAS_WCDMA_ARFCN_LIST_MAX_V01];
  /**<   A list of WCDMA RF channel numbers to be scanned. If a list is not provided,
       all channels will be scanned for the specified WCDMA preference.

       \vspace{3pt}
       Only applicable to the following scan types: \n
       - NAS_SCAN_TYPE_PLMN 
       - NAS_SCAN_TYPE_MODE_PREF
       
       \vspace{3pt}
       If another scan type is provided, this TLV is ignored.
  */

  /* Optional */
  /*  LTE ARFCN List ** */
  uint8_t lte_arfcn_valid;  /**< Must be set to true if lte_arfcn is being passed */
  uint32_t lte_arfcn_len;  /**< Must be set to # of elements in lte_arfcn */
  uint32_t lte_arfcn[NAS_LTE_ARFCN_LIST_MAX_V01];
  /**<   A list of LTE RF channel numbers to be scanned. If a list is not provided,
       all channels will be scanned for the specified LTE preference.

       \vspace{3pt}
       Only applicable to the following scan types: \n
       - NAS_SCAN_TYPE_PLMN 
       - NAS_SCAN_TYPE_MODE_PREF
       
       \vspace{3pt}
       If another scan type is provided, this TLV is ignored.
  */

  /* Optional */
  /*  Search Periodicity ** */
  uint8_t search_periodicity_valid;  /**< Must be set to true if search_periodicity is being passed */
  uint8_t search_periodicity;
  /**<   Search periodicity (in seconds).

       If the search periodicity is not provided, or value 0 is provided, it means the 
       periodic search is disabled and only one scan will be performed.

       \vspace{3pt}
       Only applicable to the following scan types: \n
       - NAS_SCAN_TYPE_PLMN 
       - NAS_SCAN_TYPE_MODE_PREF
       
       \vspace{3pt}
       If another scan type is provided, this TLV is ignored.
  */

  /* Optional */
  /*  Max Search Time ** */
  uint8_t max_search_time_valid;  /**< Must be set to true if max_search_time is being passed */
  uint16_t max_search_time;
  /**<   Maximum duration of the periodic/regular search (in seconds). \n
       - If the search lasts this long, it must be terminated.
       - If the max search time is not provided, or if the value provided is longer than the modem's internal max duration value, the modem uses the internal max duration value as the maximum duration of the periodic/regular search. \n
       - Any non-zero value is accepted as valid if the search_periodicity is valid for periodic search.
       - For regular search max_search_time must be less than 255.

       \vspace{3pt}
       Only applicable to the following scan types: \n
       - NAS_SCAN_TYPE_PLMN 
       - NAS_SCAN_TYPE_MODE_PREF
       
       \vspace{3pt}
       If another scan type is provided, this TLV is ignored.
  */

  /* Optional */
  /*  Incremental Results ** */
  uint8_t incremental_results_valid;  /**< Must be set to true if incremental_results is being passed */
  uint8_t incremental_results;
  /**<   Indicates whether the modem reports incremental results of the network scan 
       to the client. \n
       - 0 -- Incremental results are not reported.
       - 1 (default) -- Incremental results are reported if one of the following is also true:     
       @latexonly
       \begin{itemize}[label=\textendash, leftmargin=.3in]
         \item incremental\_results\_periodicity is provided and valid (modem will use this) 
         \item incremental\_results\_periodicity is not provided but the periodicity NV item is valid (modem will use the NV item value).
       \end{itemize}
       @endlatexonly

       \vspace{3pt}
       Only applicable to the following scan types: \n
       - NAS_SCAN_TYPE_PLMN 
       - NAS_SCAN_TYPE_MODE_PREF
       
       \vspace{3pt}
       If another scan type is provided, this TLV is ignored.
  */

  /* Optional */
  /*  Incremental Results Periodicity ** */
  uint8_t incremental_results_periodicity_valid;  /**< Must be set to true if incremental_results_periodicity is being passed */
  uint8_t incremental_results_periodicity;
  /**<   Indicates the periodicity with which the modem should report incremental 
       results to the client (in seconds). \n
       - If not provided, modem will use the periodicity provided by the NV item value. \n

       - If the incremental_results flag is 0, this value and the NV item value are ignored (incremental results are not reported).

       \vspace{3pt}
       Only applicable to the following scan types: \n
       - NAS_SCAN_TYPE_PLMN 
       - NAS_SCAN_TYPE_MODE_PREF
       
       \vspace{3pt}
       If another scan type is provided, this TLV is ignored.
  */

  /* Optional */
  /*  Preferred PLMN List ** */
  uint8_t preferred_plmn_list_valid;  /**< Must be set to true if preferred_plmn_list is being passed */
  uint32_t preferred_plmn_list_len;  /**< Must be set to # of elements in preferred_plmn_list */
  nas_plmn_id_ext_type_v01 preferred_plmn_list[NAS_PREFERRED_PLMN_LIST_MAX_V01];
  /**<   
       @latexonly
       \newline
       Preferred PLMN list provided to the modem. \\
       \textbullet~~If any PLMN in this list is found, the search must end and all PLMNs found must be sent to the client.
       \textbullet~~If the list is not provided, the search runs to completion and all PLMNs found must be sent to the client.

       \vspace{3pt}
       Only applicable to the following scan types: \\
       \textbullet~~NAS\_SCAN\_TYPE\_PLMN 
       \textbullet~~NAS\_SCAN\_TYPE\_MODE\_PREF
       
       \vspace{3pt}
       If another scan type is provided, this TLV is ignored.
       @endlatexonly
  */

  /* Optional */
  /*  NR5G Band Preference */
  uint8_t nr5g_band_pref_valid;  /**< Must be set to true if nr5g_band_pref is being passed */
  nas_nr5g_band_pref_mask_type_v01 nr5g_band_pref;
  /**<   Bitmask representing the NR5G band preference to be scanned.
  */

  /* Optional */
  /*  NR5G ARFCN List ** */
  uint8_t nr5g_arfcn_valid;  /**< Must be set to true if nr5g_arfcn is being passed */
  uint32_t nr5g_arfcn_len;  /**< Must be set to # of elements in nr5g_arfcn */
  uint32_t nr5g_arfcn[NAS_NR5G_ARFCN_LIST_MAX_V01];
  /**<   A list of NR5G RF channel numbers to be scanned. If a list is not provided,
       all channels will be scanned for the specified NR5G preference.

       \vspace{3pt}
       Only applicable to the following scan types: \n
       - NAS_SCAN_TYPE_PLMN 
       - NAS_SCAN_TYPE_MODE_PREF
       
       \vspace{3pt}
       If another scan type is provided, this TLV is ignored.
  */
}nas_perform_incremental_network_scan_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Performs the network scan and gives results incrementally. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. 
 Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */
}nas_perform_incremental_network_scan_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_SCAN_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_SCAN_STATUS_COMPLETE_V01 = 0x00, /**<  Network scan was successful and complete \n  */
  NAS_SCAN_STATUS_PARTIAL_V01 = 0x01, /**<  Network scan was partial \n  */
  NAS_SCAN_STATUS_ABORT_V01 = 0x02, /**<  Network scan was aborted \n  */
  NAS_SCAN_STATUS_REJ_IN_RLF_V01 = 0x03, /**<   Network scan did not complete due to a radio link failure recovery in progress \n  */
  NAS_SCAN_STATUS_INCREMENT_ERROR_V01 = 0x04, /**<  Sending incremental network scan errors  */
  NAS_SCAN_STATUS_PARTIAL_PERIODIC_V01 = 0x05, /**<   Periodic network scan gave partial results \n  */
  NAS_SCAN_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_scan_status_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t mobile_country_code;
  /**<   A 16-bit integer representation of MCC. Range: 0 to 999.
  */

  uint16_t mobile_network_code;
  /**<   A 16-bit integer representation of MNC. Range: 0 to 999.
  */

  uint8_t network_status;
  /**<   Status of the network identified by MCC and MNC preceding it.
       The status is encoded in a bitmapped value as follows: \n
       Bits 0-1 -- QMI_NAS_NETWORK_IN_USE_ STATUS_BITS    -- In-use status       \n
       - 0 -- QMI_NAS_NETWORK_IN_USE_STATUS_ UNKNOWN          -- Unknown         \n
       - 1 -- QMI_NAS_NETWORK_IN_USE_STATUS_ CURRENT_SERVING  -- Current serving \n
       - 2 -- QMI_NAS_NETWORK_IN_USE_STATUS_ AVAILABLE        -- Available
       
       Bits 2-3 -- QMI_NAS_NETWORK_ROAMING_ STATUS_BITS   -- Roaming status      \n
       - 0 -- QMI_NAS_NETWORK_ROAMING_ STATUS_UNKNOWN         -- Unknown         \n
       - 1 -- QMI_NAS_NETWORK_ROAMING_ STATUS_HOME            -- Home            \n
       - 2 -- QMI_NAS_NETWORK_ROAMING_ STATUS_ROAM            -- Roam

       Bits 4-5 -- QMI_NAS_NETWORK_FORBIDDEN_ STATUS_BITS -- Forbidden status    \n
       - 0 -- QMI_NAS_NETWORK_FORBIDDEN_ STATUS_UNKNOWN       -- Unknown         \n
       - 1 -- QMI_NAS_NETWORK_FORBIDDEN_ STATUS_FORBIDDEN     -- Forbidden       \n
       - 2 -- QMI_NAS_NETWORK_FORBIDDEN_ STATUS_NOT_FORBIDDEN -- Not forbidden

       Bits 6-7 -- QMI_NAS_NETWORK_PREFERRED_ STATUS_BITS -- Preferred status    \n
       - 0 -- QMI_NAS_NETWORK_PREFERRED_ STATUS_UNKNOWN       -- Unknown         \n
       - 1 -- QMI_NAS_NETWORK_PREFERRED_ STATUS_PREFERRED     -- Preferred       \n
       - 2 -- QMI_NAS_NETWORK_PREFERRED_ STATUS_NOT_PREFERRED -- Not preferred
  */

  uint8_t rat;
  /**<   Radio access technology. Values: \n
       - 0x04 -- GERAN \n
       - 0x05 -- UMTS \n
       - 0x08 -- LTE \n
       - 0x09 -- TD-SCDMA 
  */

  /*  MNC PCS Digit Include Status */
  uint8_t mnc_includes_pcs_digit;
  /**<   This field is used to interpret the length of the corresponding
       MNC reported in the TLVs (in this table) with an mnc or 
       mobile_network_code field. Values: \n

       - TRUE  -- MNC is a three-digit value; e.g., a reported value of 
                  90 corresponds to an MNC value of 090  \n
       - FALSE -- MNC is a two-digit value; e.g., a reported value of 
                  90 corresponds to an MNC value of 90
  */

  char network_description[NAS_NETWORK_DESCRIPTION_MAX_V01 + 1];
  /**<   An optional string containing the network name or description.
  */
}nas_3gpp_network_scan_result_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_SIGNAL_QUALITY_E_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  SYS_SIGNAL_QUALITY_LOW_V01 = 0x00, /**<  Low-quality PLMN signal
   */
  SYS_SIGNAL_QUALITY_HIGH_V01 = 0x01, /**<  High-quality PLMN signal
   */
  NAS_SIGNAL_QUALITY_E_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_signal_quality_e_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Performs the network scan and gives results incrementally. */
typedef struct {

  /* Mandatory */
  /*  Network Scan Status */
  nas_scan_status_enum_v01 scan_status;
  /**<   Indicates the status of the network scan. Values: \n
      - NAS_SCAN_STATUS_COMPLETE (0x00) --  Network scan was successful and complete \n 
      - NAS_SCAN_STATUS_PARTIAL (0x01) --  Network scan was partial \n 
      - NAS_SCAN_STATUS_ABORT (0x02) --  Network scan was aborted \n 
      - NAS_SCAN_STATUS_REJ_IN_RLF (0x03) --   Network scan did not complete due to a radio link failure recovery in progress \n 
      - NAS_SCAN_STATUS_INCREMENT_ERROR (0x04) --  Sending incremental network scan errors 
      - NAS_SCAN_STATUS_PARTIAL_PERIODIC (0x05) --   Periodic network scan gave partial results \n 
 */

  /* Optional */
  /*  3GPP Network Scan Information */
  uint8_t nas_network_scan_info_valid;  /**< Must be set to true if nas_network_scan_info is being passed */
  uint32_t nas_network_scan_info_len;  /**< Must be set to # of elements in nas_network_scan_info */
  nas_3gpp_network_scan_result_type_v01 nas_network_scan_info[NAS_3GPP_NETWORK_INFO_LIST_MAX_V01];

  /* Optional */
  /*  CSG Information */
  uint8_t csg_info_valid;  /**< Must be set to true if csg_info is being passed */
  uint32_t csg_info_len;  /**< Must be set to # of elements in csg_info */
  nas_csg_nw_info_type_v01 csg_info[NAS_3GPP_NETWORK_INFO_LIST_MAX_V01];

  /* Optional */
  /*  Network Name Source */
  uint8_t nw_name_source_valid;  /**< Must be set to true if nw_name_source is being passed */
  uint32_t nw_name_source_len;  /**< Must be set to # of elements in nw_name_source */
  nas_nw_name_source_enum_type_v01 nw_name_source[NAS_3GPP_NETWORK_INFO_LIST_MAX_V01];
  /**<   Network name source. Values: \n
      - NAS_NW_NAME_SOURCE_UNKNOWN (0x00) --  Unknown \n 
      - NAS_NW_NAME_SOURCE_OPL_PNN (0x01) --  Operator PLMN list and PLMN network name \n 
      - NAS_NW_NAME_SOURCE_CPHS_ONS (0x02) --  Common PCN handset specification and operator name string \n 
      - NAS_NW_NAME_SOURCE_NITZ (0x03) --  Network identity and time zone \n 
      - NAS_NW_NAME_SOURCE_SE13 (0x04) --  GSMA SE13 table \n 
      - NAS_NW_NAME_SOURCE_MCC_MNC (0x05) --  Mobile country code and mobile network code \n 
      - NAS_NW_NAME_SOURCE_SPN (0x06) --  Service provider name 
 */

  /* Optional */
  /*  Signal Quality */
  uint8_t signal_quality_valid;  /**< Must be set to true if signal_quality is being passed */
  uint32_t signal_quality_len;  /**< Must be set to # of elements in signal_quality */
  nas_signal_quality_e_type_v01 signal_quality[NAS_3GPP_NETWORK_INFO_LIST_MAX_V01];
  /**<   PLMN signal quality.
      - SYS_SIGNAL_QUALITY_LOW (0x00) --  Low-quality PLMN signal
  
      - SYS_SIGNAL_QUALITY_HIGH (0x01) --  High-quality PLMN signal
  
 */

  /* Optional */
  /*  Signal Strength */
  uint8_t signal_strength_valid;  /**< Must be set to true if signal_strength is being passed */
  uint32_t signal_strength_len;  /**< Must be set to # of elements in signal_strength */
  int32_t signal_strength[NAS_3GPP_NETWORK_INFO_LIST_MAX_V01];
  /**<   PLMN's signal strength information (in dBm).
  */
}nas_perform_incremental_network_scan_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_DRX_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_DRX_UNKNOWN_V01 = 0x00, /**<  DRX is not specified \n  */
  NAS_DRX_CN6_T32_V01 = 0x06, /**<  \n CN = 6, T = 32 \n  */
  NAS_DRX_CN7_T64_V01 = 0x07, /**<  \n CN = 7, T = 64 \n  */
  NAS_DRX_CN8_T128_V01 = 0x08, /**<  \n CN = 8, T = 128 \n  */
  NAS_DRX_CN9_T256_V01 = 0x09, /**<  \n CN = 9, T = 256  */
  NAS_DRX_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_drx_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets the DRX for the device. */
typedef struct {

  /* Mandatory */
  /*  DRX */
  nas_drx_enum_v01 drx;
  /**<   DRX setting for the device. Values: \n
      - NAS_DRX_UNKNOWN (0x00) --  DRX is not specified \n 
      - NAS_DRX_CN6_T32 (0x06) --  \n CN = 6, T = 32 \n 
      - NAS_DRX_CN7_T64 (0x07) --  \n CN = 7, T = 64 \n 
      - NAS_DRX_CN8_T128 (0x08) --  \n CN = 8, T = 128 \n 
      - NAS_DRX_CN9_T256 (0x09) --  \n CN = 9, T = 256 
 */
}nas_set_drx_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets the DRX for the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */
}nas_set_drx_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the DRX for the device. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_drx_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the DRX for the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */

  /* Optional */
  /*  DRX */
  uint8_t drx_valid;  /**< Must be set to true if drx is being passed */
  nas_drx_enum_v01 drx;
  /**<   DRX setting for the device. Values: \n
      - NAS_DRX_UNKNOWN (0x00) --  DRX is not specified \n 
      - NAS_DRX_CN6_T32 (0x06) --  \n CN = 6, T = 32 \n 
      - NAS_DRX_CN7_T64 (0x07) --  \n CN = 7, T = 64 \n 
      - NAS_DRX_CN8_T128 (0x08) --  \n CN = 8, T = 128 \n 
      - NAS_DRX_CN9_T256 (0x09) --  \n CN = 9, T = 256 
 */
}nas_get_drx_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the network negotiated DRX level. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_negotiated_drx_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the network negotiated DRX level. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */

  /* Optional */
  /*  DRX Level */
  uint8_t drx_level_valid;  /**< Must be set to true if drx_level is being passed */
  uint8_t drx_level;
  /**<   DRX level.\n
  */
}nas_get_negotiated_drx_resp_msg_v01;  /* Message */
/**
    @}
  */

typedef uint64_t nas_csg_list_category_mask_type_v01;
#define NAS_CSG_LIST_CAT_OPERATOR_MASK_V01 ((nas_csg_list_category_mask_type_v01)0x01ull) /**<  Operator \n  */
#define NAS_CSG_LIST_CAT_ALLOWED_MASK_V01 ((nas_csg_list_category_mask_type_v01)0x02ull) /**<  Allowed \n  */
#define NAS_CSG_LIST_CAT_OTHERS_MASK_V01 ((nas_csg_list_category_mask_type_v01)0x04ull) /**<  Others  */
/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_CSG_SEARCH_TYPE_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_CSG_SEARCH_TYPE_HOME_ONLY_V01 = 0, /**<  Home only \n  */
  NAS_CSG_SEARCH_TYPE_ALL_V01 = 1, /**<  All  */
  NAS_CSG_SEARCH_TYPE_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_csg_search_type_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_CSG_SORT_PREFERENCE_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_CSG_SORT_PREF_RAT_ONLY_V01 = 0, /**<  RAT only \n  */
  NAS_CSG_SORT_PREF_SIGNAL_ONLY_V01 = 1, /**<  Signal only \n  */
  NAS_CSG_SORT_PREF_RAT_THEN_SIGNAL_V01 = 2, /**<  RAT then signal \n  */
  NAS_CSG_SORT_PREF_SIGNAL_THEN_RAT_V01 = 3, /**<  Signal then RAT  */
  NAS_CSG_SORT_PREFERENCE_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_csg_sort_preference_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_CSG_SORT_SIGNAL_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_CSG_SORT_SIGNAL_DEC_STRENGTH_V01 = 0, /**<  Decreasing strength \n  */
  NAS_CSG_SORT_SIGNAL_RANDOM_V01 = 1, /**<  Random  */
  NAS_CSG_SORT_SIGNAL_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_csg_sort_signal_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_CSG_SELECTION_CONFIG_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_CSG_SELECTION_CONFIG_1_V01 = 0, /**<  Configuration 1  */
  NAS_CSG_SELECTION_CONFIG_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_csg_selection_config_enum_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Configures the CSG search and selection parameters, and triggers 
              an immediate periodic search and selection based on the 
              configured parameters. */
typedef struct {

  /* Optional */
  /*  CSG Search RAT (Unused/Ignored) */
  uint8_t rat_valid;  /**< Must be set to true if rat is being passed */
  nas_radio_if_enum_v01 rat;
  /**<   Radio access technology. Values: \n
      - NAS_RADIO_IF_UMTS (0x05) --  UMTS \n 
      - NAS_RADIO_IF_LTE (0x08) --  LTE \n 
 */

  /* Optional */
  /*  Periodic Search Timer */
  uint8_t search_timer_valid;  /**< Must be set to true if search_timer is being passed */
  uint32_t search_timer;
  /**<   Periodic search timer (in minutes).
       Timer value 0 means the periodic search is disabled and no immediate search 
       is performed.
    */

  /* Optional */
  /*  Periodic Search is Performed When in Home/Home and Roaming (Unused/Ignored) */
  uint8_t search_type_valid;  /**< Must be set to true if search_type is being passed */
  nas_csg_search_type_enum_type_v01 search_type;
  /**<   Periodic search type. Values: \n
      - NAS_CSG_SEARCH_TYPE_HOME_ONLY (0) --  Home only \n 
      - NAS_CSG_SEARCH_TYPE_ALL (1) --  All 
 */

  /* Optional */
  /*  CSG Search UMTS Band Preference */
  uint8_t umts_band_pref_valid;  /**< Must be set to true if umts_band_pref is being passed */
  nas_band_pref_mask_type_v01 umts_band_pref;
  /**<   Bitmask representing the band preference to be scanned.  
       Values: \n 
       - Bit 22 to Bit 59 -- See Table @latexonly\ref{tbl:bandPreference}@endlatexonly 
       for details.   
  */

  /* Optional */
  /*  CSG Search LTE Band Preference */
  uint8_t lte_band_pref_valid;  /**< Must be set to true if lte_band_pref is being passed */
  lte_band_pref_mask_type_v01 lte_band_pref;
  /**<   Bitmask representing the LTE band preference to be scanned. 
       See Table @latexonly\ref{tbl:lteBandPreference}@endlatexonly 
       for details.  
  */

  /* Optional */
  /*  CSG Selection Category List (Unused/Ignored) */
  uint8_t csg_cat_list_valid;  /**< Must be set to true if csg_cat_list is being passed */
  nas_csg_list_category_mask_type_v01 csg_cat_list;
  /**<   Bitmask representing Operator CSG List (OCSGL), 
 Allowed CSG List (ACSGL), or others. Values: \n
      - NAS_CSG_LIST_CAT_OPERATOR_MASK (0x01) --  Operator \n 
      - NAS_CSG_LIST_CAT_ALLOWED_MASK (0x02) --  Allowed \n 
      - NAS_CSG_LIST_CAT_OTHERS_MASK (0x04) --  Others 
 */

  /* Optional */
  /*  CSG Sort Preference Type (Unused/Ignored) */
  uint8_t sort_type_valid;  /**< Must be set to true if sort_type is being passed */
  nas_csg_sort_preference_enum_type_v01 sort_type;
  /**<   CSG sort preference type. Values: \n
      - NAS_CSG_SORT_PREF_RAT_ONLY (0) --  RAT only \n 
      - NAS_CSG_SORT_PREF_SIGNAL_ONLY (1) --  Signal only \n 
      - NAS_CSG_SORT_PREF_RAT_THEN_SIGNAL (2) --  RAT then signal \n 
      - NAS_CSG_SORT_PREF_SIGNAL_THEN_RAT (3) --  Signal then RAT 
 */

  /* Optional */
  /*  Sort CSG Search Results Based on RAT List (Unused/Ignored) */
  uint8_t rat_list_valid;  /**< Must be set to true if rat_list is being passed */
  uint32_t rat_list_len;  /**< Must be set to # of elements in rat_list */
  nas_radio_if_enum_v01 rat_list[NAS_CSG_RAT_LIST_MAX_LEN_V01];
  /**<   Sort based on the RAT priority list. Values: \n
      - NAS_RADIO_IF_UMTS (0x05) --  UMTS \n 
      - NAS_RADIO_IF_LTE (0x08) --  LTE \n 
 */

  /* Optional */
  /*  Sort CSG Search Results Based on Signal Type (Unused/Ignored) */
  uint8_t sort_signal_type_valid;  /**< Must be set to true if sort_signal_type is being passed */
  nas_csg_sort_signal_enum_type_v01 sort_signal_type;
  /**<   Sort signal type. Values: \n
      - NAS_CSG_SORT_SIGNAL_DEC_STRENGTH (0) --  Decreasing strength \n 
      - NAS_CSG_SORT_SIGNAL_RANDOM (1) --  Random 
 */

  /* Optional */
  /*  Operator-Specific CSG Selection Configuration */
  uint8_t selection_config_type_valid;  /**< Must be set to true if selection_config_type is being passed */
  nas_csg_selection_config_enum_type_v01 selection_config_type;
  /**<   CSG selection configuration type. Values: \n
      - NAS_CSG_SELECTION_CONFIG_1 (0) --  Configuration 1 
 */

  /* Optional */
  /*  Network Type */
  uint8_t network_type_valid;  /**< Must be set to true if network_type is being passed */
  nas_network_type_mask_type_v01 network_type;
  /**<   Bitmask representing the network type to scan. Values: \n
	   - Bit 1 -- UMTS \n
	   - Bit 2 -- LTE
    */
}nas_csg_search_selection_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Configures the CSG search and selection parameters, and triggers 
              an immediate periodic search and selection based on the 
              configured parameters. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. 
 Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */
}nas_csg_search_selection_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Triggers an immediate CSG search and selection based on already 
              configured parameters. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_csg_immediate_search_selection_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Triggers an immediate CSG search and selection based on already 
              configured parameters. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. 
 Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */
}nas_csg_immediate_search_selection_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves configured CSG search and selection parameters. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_csg_search_selection_configuration_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves configured CSG search and selection parameters. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */

  /* Optional */
  /*  CSG Search RAT (Unused/Ignored) */
  uint8_t rat_valid;  /**< Must be set to true if rat is being passed */
  nas_radio_if_enum_v01 rat;
  /**<   Radio access technology. Values: \n
      - NAS_RADIO_IF_UMTS (0x05) --  UMTS \n 
      - NAS_RADIO_IF_LTE (0x08) --  LTE \n 
 */

  /* Optional */
  /*  Periodic Search Timer */
  uint8_t search_timer_valid;  /**< Must be set to true if search_timer is being passed */
  uint32_t search_timer;
  /**<   Periodic search timer (in minutes).
       Timer value 0 means the periodic search is disabled and no immediate search 
       is performed.
    */

  /* Optional */
  /*  Periodic Search is Performed When in Home/Home and Roaming (Unused/Ignored) */
  uint8_t search_type_valid;  /**< Must be set to true if search_type is being passed */
  nas_csg_search_type_enum_type_v01 search_type;
  /**<   Periodic search type. Values: \n
      - NAS_CSG_SEARCH_TYPE_HOME_ONLY (0) --  Home only \n 
      - NAS_CSG_SEARCH_TYPE_ALL (1) --  All 
 */

  /* Optional */
  /*  CSG Search UMTS Band Preference */
  uint8_t umts_band_pref_valid;  /**< Must be set to true if umts_band_pref is being passed */
  nas_band_pref_mask_type_v01 umts_band_pref;
  /**<   Bitmask representing the band preference to be scanned.  
       Values: \n
       - Bit 22 to Bit 59 -- See Table @latexonly\ref{tbl:bandPreference}@endlatexonly 
       for details.   
  */

  /* Optional */
  /*  CSG Search LTE Band Preference */
  uint8_t lte_band_pref_valid;  /**< Must be set to true if lte_band_pref is being passed */
  lte_band_pref_mask_type_v01 lte_band_pref;
  /**<   Bitmask representing the LTE band preference to be scanned. 
       See Table @latexonly\ref{tbl:lteBandPreference}@endlatexonly 
       for details.  
  */

  /* Optional */
  /*  CSG Selection Category List (Unused/Ignored) */
  uint8_t csg_cat_list_valid;  /**< Must be set to true if csg_cat_list is being passed */
  nas_csg_list_category_mask_type_v01 csg_cat_list;
  /**<   Bitmask representing OCSGL/ACSGL/OTHERS. Values: \n
      - NAS_CSG_LIST_CAT_OPERATOR_MASK (0x01) --  Operator \n 
      - NAS_CSG_LIST_CAT_ALLOWED_MASK (0x02) --  Allowed \n 
      - NAS_CSG_LIST_CAT_OTHERS_MASK (0x04) --  Others 
 */

  /* Optional */
  /*  CSG Sort Preference Type (Unused/Ignored) */
  uint8_t sort_type_valid;  /**< Must be set to true if sort_type is being passed */
  nas_csg_sort_preference_enum_type_v01 sort_type;
  /**<   Sort type. Values: \n
      - NAS_CSG_SORT_PREF_RAT_ONLY (0) --  RAT only \n 
      - NAS_CSG_SORT_PREF_SIGNAL_ONLY (1) --  Signal only \n 
      - NAS_CSG_SORT_PREF_RAT_THEN_SIGNAL (2) --  RAT then signal \n 
      - NAS_CSG_SORT_PREF_SIGNAL_THEN_RAT (3) --  Signal then RAT 
 */

  /* Optional */
  /*  Sort CSG Search Results Based on RAT List (Unused/Ignored) */
  uint8_t rat_list_valid;  /**< Must be set to true if rat_list is being passed */
  uint32_t rat_list_len;  /**< Must be set to # of elements in rat_list */
  nas_radio_if_enum_v01 rat_list[NAS_CSG_RAT_LIST_MAX_LEN_V01];
  /**<   Sort based on the RAT priority list. Values: \n
      - NAS_RADIO_IF_UMTS (0x05) --  UMTS \n 
      - NAS_RADIO_IF_LTE (0x08) --  LTE \n 
 */

  /* Optional */
  /*  Sort CSG Search Results Based on Signal Type (Unused/Ignored) */
  uint8_t sort_signal_type_valid;  /**< Must be set to true if sort_signal_type is being passed */
  nas_csg_sort_signal_enum_type_v01 sort_signal_type;
  /**<   Sort signal type. Values: \n
      - NAS_CSG_SORT_SIGNAL_DEC_STRENGTH (0) --  Decreasing strength \n 
      - NAS_CSG_SORT_SIGNAL_RANDOM (1) --  Random 
 */

  /* Optional */
  /*  Operator-Specific CSG Selection Configuration */
  uint8_t selection_config_type_valid;  /**< Must be set to true if selection_config_type is being passed */
  nas_csg_selection_config_enum_type_v01 selection_config_type;
  /**<   CSG selection configuration type. Values: \n
      - NAS_CSG_SELECTION_CONFIG_1 (0) --  Configuration 1 
 */

  /* Optional */
  /*  Network Type */
  uint8_t network_type_valid;  /**< Must be set to true if network_type is being passed */
  nas_network_type_mask_type_v01 network_type;
  /**<   Bitmask representing the network type to scan. Values: \n
	   - Bit 1 -- UMTS \n
	   - Bit 2 -- LTE
    */
}nas_get_csg_search_selection_configuration_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Access Barring Factor for MMTEL Voice Calls */
  uint8_t barring_factor_voice;
  /**<   Access barring factor for voice calls. Range: 0 to 100.
       Value 100 indicates Invalid. All values are per 
       \hyperref[STD-36331]{3GPP TS 36.331}.
  */

  /*  Access Barring Time for MMTEL Voice Calls */
  uint16_t barring_time_voice;
  /**<   Access barring time in seconds for voice calls. Range: 0 to 512.
  */

  /*  Access Barring Factor for MMTEL Video Calls */
  uint8_t barring_factor_video;
  /**<   Access barring factor for video calls. Range: 0 to 100.
       Value 100 indicates Invalid. All values are per 
       \hyperref[STD-36331]{3GPP TS 36.331}.
  */

  /*  Access Barring Time for MMTEL Video Calls */
  uint16_t barring_time_video;
  /**<   Access barring time in seconds for video calls. Range: 0 to 512.
  */
}nas_ssac_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates Service-Specific Access Class (SSAC) barring information 
             for MMTEL voice/video originating calls. (Deprecated) */
typedef struct {

  /* Optional */
  /*  Service-Specific Access Class Barring Information */
  uint8_t ssac_info_valid;  /**< Must be set to true if ssac_info is being passed */
  nas_ssac_info_type_v01 ssac_info;
}nas_ssac_info_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the LTE eMBMS statistics. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_lte_embms_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t mbsfn_area_id;
  /**<   Multicast broadcast single frequency network area ID from SIB13. 
       Values: 0 to 255.
  */

  uint8_t pmch_id;
  /**<   Physical multicast channel ID. 
       Values: 1 to 15.
  */

  uint8_t data_mcs;
  /**<   Data modulation and coding scheme for the physical multicast channel. */
}nas_pmch_datamcs_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
/**  Current signal strength information for a MBSFN (Multicast Broadcast 
  Single Frequency Network) area. 
 */
typedef struct {

  /*  MBSFN Area ID */
  uint8_t area_id;
  /**<   Multicast broadcast single frequency network area ID.
       Values: 0 to 255.
  */

  /*  SNR */
  int16_t snr;
  /**<   Average SNR of the serving cell over the last measurement period in 
       dB Q3[2^3] format.
       Values: -10 to 30.
  */

  /*  Excess SNR */
  int16_t excess_snr;
  /**<   Excess SNR of the serving cell over the last measurement period in 
       dB Q3[2^3] format.
       Values: -10 to 30 
  */

  /*  Signal level */
  int8_t signal_level;
  /**<   Signal level of the serving cell over the last measurement period.
       Range: 0 to 5. */
}nas_lte_mbsfn_area_signal_strength_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
/**  LTE PMCH (Physical Multicast Channel) BLER information 
 */
typedef struct {

  /*  PMCH ID */
  uint32_t pmch_id;
  /**<   Physical multicast channel ID. 
  */

  /*  Number of CRC passes */
  uint32_t num_crc_pass;
  /**<   Number of CRC passes. 
  */

  /* Number of CRC failures */
  uint32_t num_crc_fail;
  /**<   Number of CRC failures.
   */
}nas_lte_pmch_bler_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
/**  LTE PMCH information for an area. 
 */
typedef struct {

  uint16_t area_id;
  /**<   Area ID.
   */

  uint32_t pmch_bler_len;  /**< Must be set to # of elements in pmch_bler */
  nas_lte_pmch_bler_info_type_v01 pmch_bler[NAS_LTE_PMCH_PER_MBSFN_AREA_MAX_V01];
}nas_lte_ml1_pmch_bler_per_area_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
/**  MTCH (Multicast Traffic Channel) information 
 */
typedef struct {

  uint8_t area_id;
  /**<   Multicast broadcast single frequency network area ID.
  */

  uint8_t pmch_id;
  /**<   Physical multicast channel ID.
   */

  uint8_t lc_id;
  /**<   Logical channel ID. 
  */

  uint64_t num_mtch_tb_bytes;
  /**<   Number of received bytes for the multicast traffic channel transport block.
  */
}nas_mtch_info_s_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the LTE eMBMS statistics. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */

  /* Optional */
  /*  eMBMS Coverage Status */
  uint8_t coverage_status_valid;  /**< Must be set to true if coverage_status is being passed */
  uint8_t coverage_status;
  /**<   eMBMS coverage status. Values: \n
       - TRUE  -- Enabled \n
       - FALSE -- Disabled
  */

  /* Optional */
  /*  Physical Multicast Channel Data MCS Information */
  uint8_t pmch_data_mcs_valid;  /**< Must be set to true if pmch_data_mcs is being passed */
  uint32_t pmch_data_mcs_len;  /**< Must be set to # of elements in pmch_data_mcs */
  nas_pmch_datamcs_info_type_v01 pmch_data_mcs[NAS_LTE_ACTIVE_PMCH_MAX_V01];
  /**<   \n
       (PMCH data modulation and coding scheme of all PMCHs actively monitored)
    */

  /* Optional */
  /*  Temporary Mobile Group Identity Active Status */
  uint8_t is_active_tmgi_valid_valid;  /**< Must be set to true if is_active_tmgi_valid is being passed */
  uint8_t is_active_tmgi_valid;
  /**<   Indicates whether there is any activated temporary mobile group identity. 
       Values: \n
       - TRUE  -- Enabled \n
       - FALSE -- Disabled
  */

  /* Optional */
  /*  Signal Quality Information */
  uint8_t mbsfn_area_signal_data_valid;  /**< Must be set to true if mbsfn_area_signal_data is being passed */
  uint32_t mbsfn_area_signal_data_len;  /**< Must be set to # of elements in mbsfn_area_signal_data */
  nas_lte_mbsfn_area_signal_strength_info_type_v01 mbsfn_area_signal_data[NAS_LTE_EMBMS_MBSFN_AREAS_MAX_V01];

  /* Optional */
  /*  Physical Multicast Channel BLER Information */
  uint8_t pmch_bler_info_valid;  /**< Must be set to true if pmch_bler_info is being passed */
  uint32_t pmch_bler_info_len;  /**< Must be set to # of elements in pmch_bler_info */
  nas_lte_ml1_pmch_bler_per_area_info_type_v01 pmch_bler_info[NAS_LTE_EMBMS_MBSFN_AREAS_MAX_V01];

  /* Optional */
  /*  Multicast Traffic Channel Information */
  uint8_t mtch_info_valid;  /**< Must be set to true if mtch_info is being passed */
  uint32_t mtch_info_len;  /**< Must be set to # of elements in mtch_info */
  nas_mtch_info_s_v01 mtch_info[NAS_LTE_EMBMS_ACTIVE_SESSIONS_MAX_V01];
}nas_get_lte_embms_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Gets the serving cell SIB. */
typedef struct {

  /* Mandatory */
  /*  SIB Number */
  uint8_t sib_num;
  /**<   Serving cell SIB number for which to interrogate.
       Valid values may range from 1 to 16.
  */
}nas_get_serv_cell_sib_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Gets the serving cell SIB. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */

  /* Optional */
  /*  SIB Length */
  uint8_t total_size_valid;  /**< Must be set to true if total_size is being passed */
  uint16_t total_size;
  /**<   Total length (in bytes) of the interrogated serving cell SIB.
  */
}nas_get_serv_cell_sib_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Gets the serving cell SIB. */
typedef struct {

  /* Mandatory */
  /*  Sequence Number */
  uint8_t sequence;
  /**<   Sequence number of this indication. Sequence number 0 indicates that 
       this indication is the start of a new sequence. The sequence number 
       increments for each successive indication of a sequence.
  */

  /* Mandatory */
  /*  SIB Packet */
  uint32_t sib_pkt_len;  /**< Must be set to # of elements in sib_pkt */
  uint8_t sib_pkt[NAS_GET_SERV_CELL_SIB_MAX_V01];
  /**<   Packet of SIB data; may contain up to 4000 characters.
  */
}nas_get_serv_cell_sib_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Access Barring Factor for MMTEL Voice Calls */
  uint8_t barring_factor_voice;
  /**<   Access barring factor for voice calls. Range: 0 to 100.
       Value 100 is used when the UE goes to the LTE Connected state. 
       Value 0xFF indicates Invalid.
       All values are per \hyperref[STD-36331]{3GPP TS 36.331}.
  */

  /*  Access Barring Time for MMTEL Voice Calls */
  uint16_t barring_time_voice;
  /**<   Access barring time (in seconds) for voice calls. Range: 0 to 512.
       Value 0 is used when the UE goes to the LTE Connected state.
       Value 0xFFFF indicates Invalid.
  */
}nas_ssac_voice_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Access Barring Factor for MMTEL Voice Calls(sib2) */
  uint8_t sib2_barring_factor_voice;
  /**<   Access barring factor for voice calls. Range: 0 to 100.
       Indicates the network-sent barring factor received from the SIB2 RRC message.
       Value 0xFF indicates Invalid.
       All values are per \hyperref[STD-36331]{3GPP TS 36.331}.
  */

  /*  Access Barring Time for MMTEL Voice Calls(sib2) */
  uint16_t sib2_barring_time_voice;
  /**<   Access barring time (in seconds) for voice calls. Range: 0 to 512.
       Indicates the network-sent barring time received from the SIB2 RRC message.
       Value 0xFFFF indicates Invalid.
  */
}nas_sib2_ssac_voice_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Access Barring Factor for MMTEL Video Calls */
  uint8_t barring_factor_video;
  /**<   Access barring factor for video calls. Range: 0 to 100.
       Value 100 is used when the UE goes to the LTE Connected state. 
       Value 0xFF indicates Invalid. 
       All values are per \hyperref[STD-36331]{3GPP TS 36.331}.
  */

  /*  Access Barring Time for MMTEL Video Calls */
  uint16_t barring_time_video;
  /**<   Access barring time (in seconds) for video calls. Range: 0 to 512.
       Value 0 is used when the UE goes to the LTE Connected state.
       Value 0xFFFF indicates Invalid.
  */
}nas_ssac_video_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Access Barring Factor for MMTEL Video Calls(sib2) */
  uint8_t sib2_barring_factor_video;
  /**<   Access barring factor for video calls. Range: 0 to 100.
       Indicates the network-sent barring factor received from the SIB2 RRC message.
       Value 0xFF indicates Invalid. 
       All values are per \hyperref[STD-36331]{3GPP TS 36.331}.
  */

  /*  Access Barring Time for MMTEL Video Calls(sib2) */
  uint16_t sib2_barring_time_video;
  /**<   Access barring time (in seconds) for video calls. Range: 0 to 512.
       Indicates the network-sent barring time received from the SIB2 RRC message.
       Value 0xFFFF indicates Invalid.
  */
}nas_sib2_ssac_video_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates a change in SSAC class barring information for 
             MMTEL voice/video originating calls.
             \label{idl:ssacChangeInfo} */
typedef struct {

  /* Optional */
  /*  Service-Specific Access Class Barring Information for Voice Calls */
  uint8_t ssac_voice_info_valid;  /**< Must be set to true if ssac_voice_info is being passed */
  nas_ssac_voice_info_type_v01 ssac_voice_info;

  /* Optional */
  /*  Service-Specific Access Class Barring Information for Video Calls */
  uint8_t ssac_video_info_valid;  /**< Must be set to true if ssac_video_info is being passed */
  nas_ssac_video_info_type_v01 ssac_video_info;

  /* Optional */
  /*  Service-Specific Access Class Barring Information for Voice Calls -- SIB2 */
  uint8_t sib2_ssac_voice_info_valid;  /**< Must be set to true if sib2_ssac_voice_info is being passed */
  nas_sib2_ssac_voice_info_type_v01 sib2_ssac_voice_info;

  /* Optional */
  /*  Service-Specific Access Class Barring Information for Video Calls -- SIB2 */
  uint8_t sib2_ssac_video_info_valid;  /**< Must be set to true if sib2_ssac_video_info is being passed */
  nas_sib2_ssac_video_info_type_v01 sib2_ssac_video_info;

  /* Optional */
  /*  Special Access Class Barring for MMTEL Voice Calls */
  uint8_t special_ac_barring_voice_valid;  /**< Must be set to true if special_ac_barring_voice is being passed */
  uint8_t special_ac_barring_voice;
  /**<   Access class barring corresponding to Access Class 11-15 for MMTEL voice calls.
       All values are per \hyperref[STD-36331]{3GPP TS 36.331} Section 5.3.3.10.
  */

  /* Optional */
  /*  Special Access Class Barring for MMTEL Video Calls */
  uint8_t special_ac_barring_video_valid;  /**< Must be set to true if special_ac_barring_video is being passed */
  uint8_t special_ac_barring_video;
  /**<   Access class barring corresponding to Access Class 11-15 for MMTEL video calls.
       All values are per \hyperref[STD-36331]{3GPP TS 36.331} Section 5.3.3.10.
  */
}nas_ssac_change_info_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the SSAC barring information for MMTEL voice/video 
              originating calls. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_ssac_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the SSAC barring information for MMTEL voice/video 
              originating calls. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */

  /* Optional */
  /*  Service-Specific Access Class Barring Information for Voice Calls */
  uint8_t ssac_voice_info_valid;  /**< Must be set to true if ssac_voice_info is being passed */
  nas_ssac_voice_info_type_v01 ssac_voice_info;

  /* Optional */
  /*  Service-Specific Access Class Barring Information for Video Calls */
  uint8_t ssac_video_info_valid;  /**< Must be set to true if ssac_video_info is being passed */
  nas_ssac_video_info_type_v01 ssac_video_info;

  /* Optional */
  /*  Service-Specific Access Class Barring Information for Voice Calls -- SIB2 */
  uint8_t sib2_ssac_voice_info_valid;  /**< Must be set to true if sib2_ssac_voice_info is being passed */
  nas_sib2_ssac_voice_info_type_v01 sib2_ssac_voice_info;

  /* Optional */
  /*  Service-Specific Access Class Barring Information for Video Calls -- SIB2 */
  uint8_t sib2_ssac_video_info_valid;  /**< Must be set to true if sib2_ssac_video_info is being passed */
  nas_sib2_ssac_video_info_type_v01 sib2_ssac_video_info;

  /* Optional */
  /*  Special Access Class Barring for MMTEL Voice Calls */
  uint8_t special_ac_barring_voice_valid;  /**< Must be set to true if special_ac_barring_voice is being passed */
  uint8_t special_ac_barring_voice;
  /**<   Access class barring corresponding to Access Class 11-15 for MMTEL voice calls.
       All values are per \hyperref[STD-36331]{3GPP TS 36.331} Section 5.3.3.10.
  */

  /* Optional */
  /*  Special Access Class Barring for MMTEL Video Calls */
  uint8_t special_ac_barring_video_valid;  /**< Must be set to true if special_ac_barring_video is being passed */
  uint8_t special_ac_barring_video;
  /**<   Access class barring corresponding to Access Class 11-15 for MMTEL video calls.
       All values are per \hyperref[STD-36331]{3GPP TS 36.331} Section 5.3.3.10.
  */
}nas_get_ssac_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Enables or disables a periodic search. */
typedef struct {

  /* Mandatory */
  /*  Periodic Search Allowed */
  uint8_t allowed;
  /**<   Whether a periodic search is allowed. 
       Values: \n
       - TRUE  -- Enabled \n
       - FALSE -- Disabled
  */
}nas_set_periodic_search_allowed_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Enables or disables a periodic search. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */
}nas_set_periodic_search_allowed_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates a change in the T3402 timer value. */
typedef struct {

  /* Optional */
  /*  T3402 Timer Value */
  uint8_t t3402_timer_val_valid;  /**< Must be set to true if t3402_timer_val is being passed */
  uint32_t t3402_timer_val;
  /**<   T3402 timer value (in milliseconds).
  */
}nas_emm_t3402_changed_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the Access Class Barring (ACB) information. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_acb_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  Access Control Barring Factor */
  uint8_t ac_barring_factor;
  /**<   Access control barring factor multiplied by 100, i.e., 5 means 0.05 
       (50 means 0.50, 95 means 0.95). 
       0xFF indicates an invalid barring factor.
  */

  /*  Access Control Barring time */
  uint16_t ac_barring_time;
  /**<   Access barring time value (in seconds).
  */

  uint8_t ac_barring_for_special_ac;
  /**<   Access control barring factor for special access control. 
       Ignore this if the value is 0xFF, which indicates special barring 
       information is not available.
  */
}nas_lte_rrc_ac_barring_params_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the Access Class Barring (ACB) information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */

  /* Optional */
  /*  Access Barring for Emergency */
  uint8_t ac_barring_for_emergency_valid;  /**< Must be set to true if ac_barring_for_emergency is being passed */
  uint8_t ac_barring_for_emergency;
  /**<   Whether access barring for an emergency is present. 
       Values: \n
       - TRUE  -- Present \n
       - FALSE -- Not present
  */

  /* Optional */
  /*  Access Barring Info for MO Signaling */
  uint8_t ac_barring_mo_signalling_valid;  /**< Must be set to true if ac_barring_mo_signalling is being passed */
  nas_lte_rrc_ac_barring_params_type_v01 ac_barring_mo_signalling;

  /* Optional */
  /*  Access Barring Info for MO Data */
  uint8_t ac_barring_mo_data_valid;  /**< Must be set to true if ac_barring_mo_data is being passed */
  nas_lte_rrc_ac_barring_params_type_v01 ac_barring_mo_data;
}nas_get_acb_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Retrieves the Access Class Barring (ACB) information. */
typedef struct {

  /* Optional */
  /*  Access Barring for Emergency */
  uint8_t ac_barring_for_emergency_valid;  /**< Must be set to true if ac_barring_for_emergency is being passed */
  uint8_t ac_barring_for_emergency;
  /**<   Whether access barring for an emergency is present. 
       Values: \n
       - TRUE  -- Present \n
       - FALSE -- Not present
  */

  /* Optional */
  /*  Access Barring Info for MO Signaling */
  uint8_t ac_barring_mo_signalling_valid;  /**< Must be set to true if ac_barring_mo_signalling is being passed */
  nas_lte_rrc_ac_barring_params_type_v01 ac_barring_mo_signalling;

  /* Optional */
  /*  Access Barring Info for MO Data */
  uint8_t ac_barring_mo_data_valid;  /**< Must be set to true if ac_barring_mo_data is being passed */
  nas_lte_rrc_ac_barring_params_type_v01 ac_barring_mo_data;
}nas_acb_info_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_DATA_SUBS_PRIORITY_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_DATA_SUBS_PRIORITY_LOW_V01 = 0x00, /**<  Low \n  */
  NAS_DATA_SUBS_PRIORITY_HIGH_V01 = 0x01, /**<  High  */
  NAS_DATA_SUBS_PRIORITY_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_data_subs_priority_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Configures the data priority for a bound subscription. */
typedef struct {

  /* Mandatory */
  /*  Data Subscription Priority */
  nas_data_subs_priority_enum_v01 data_subs_priority;
  /**<   Data priority of the bound subscription.
 Values: \n
      - NAS_DATA_SUBS_PRIORITY_LOW (0x00) --  Low \n 
      - NAS_DATA_SUBS_PRIORITY_HIGH (0x01) --  High 

 \vspace{3pt}
 All other values are reserved.
 */
}nas_set_data_subs_priority_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Configures the data priority for a bound subscription. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_data_subs_priority_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the current data priority status of a subscription. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_data_subs_priority_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the current data priority status of a subscription. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  Data Subscription Priority */
  uint8_t data_subs_priority_valid;  /**< Must be set to true if data_subs_priority is being passed */
  nas_data_subs_priority_enum_v01 data_subs_priority;
  /**<   Data priority of the requested subscription.
 Values: \n
      - NAS_DATA_SUBS_PRIORITY_LOW (0x00) --  Low \n 
      - NAS_DATA_SUBS_PRIORITY_HIGH (0x01) --  High 

 \vspace{3pt}
 All other values are reserved.
 */
}nas_get_data_subs_priority_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Informs the control point of any changes in the data subscription
             priority. */
typedef struct {

  /* Optional */
  /*  Data Priority */
  uint8_t data_subs_priority_valid;  /**< Must be set to true if data_subs_priority is being passed */
  nas_data_subs_priority_enum_v01 data_subs_priority;
  /**<   Data priority for the bound subscription.
 Values: \n
      - NAS_DATA_SUBS_PRIORITY_LOW (0x00) --  Low \n 
      - NAS_DATA_SUBS_PRIORITY_HIGH (0x01) --  High 

 \vspace{3pt}
 All other values are reserved.
 */
}nas_data_subs_priority_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Raises or drops the Transceiver Resource Manager (TRM) priority 
               to block or unblock tune-aways. */
typedef struct {

  /* Mandatory */
  /*  TRM Priority */
  uint8_t trm_priority;
  /**<   TRM priority to be set. Values: \n
       - 0 -- TRM low priority; unblock the tune-away \n
       - 1 -- TRM high priority; block the tune-away

       \vspace{3pt}
       All other values are reserved.
  */
}nas_avoid_tuneaway_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Raises or drops the Transceiver Resource Manager (TRM) priority 
               to block or unblock tune-aways. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_avoid_tuneaway_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Indicates the current IMS procedure type so the modem can prioritize
               RF resources to accommodate the procedure. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Procedure Type */
  nas_proc_type_e_type_v01 proc_type;
  /**<   IMS procedure type. Values: \n
      - NAS_PROC_TYPE_NONE (0) --  No procedure type \n 
      - NAS_PROC_TYPE_VOLTE_CALL (1) --  VoLTE call (Deprecated, use VOIMS_CALL) \n 
      - NAS_PROC_TYPE_IMS_SMS (2) --  IMS-based SMS \n 
      - NAS_PROC_TYPE_IMS_MMS (3) --  IMS-based MMS \n 
      - NAS_PROC_TYPE_IMS_REGISTRATION (4) --  IMS registration \n 
      - NAS_PROC_TYPE_IMS_UT (5) --  IMS UT service 
      - NAS_PROC_TYPE_VOIMS_CALL (6) --  IMS-based voice or VT call \n 
 */
}nas_set_lte_proc_type_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Indicates the current IMS procedure type so the modem can prioritize
               RF resources to accommodate the procedure. (Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_lte_proc_type_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_MCC_CONFIDENCE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_MCC_CONFIDENCE_LOW_V01 = 0x00, /**<  Low \n  */
  NAS_MCC_CONFIDENCE_MEDIUM_LOW_V01 = 0x01, /**<  Medium low \n  */
  NAS_MCC_CONFIDENCE_MEDIUM_V01 = 0x02, /**<  Medium \n  */
  NAS_MCC_CONFIDENCE_MEDIUM_HIGH_V01 = 0x03, /**<  Medium high \n  */
  NAS_MCC_CONFIDENCE_HIGH_V01 = 0x04, /**<  High  */
  NAS_MCC_CONFIDENCE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_mcc_confidence_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_SET_MCC_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_SET_MCC_STATUS_SUCCESS_V01 = 0x00, /**<  Valid MCC was passed in the request \n  */
  NAS_SET_MCC_STATUS_DETECTION_DISABLED_V01 = 0x01, /**<  All mechanisms used to detect the MCC (Wi-Fi\regns, GPS, etc.) are 
       disabled by the user or control points \n  */
  NAS_SET_MCC_STATUS_NOT_DETECTED_V01 = 0x02, /**<  MCC detection is enabled but no MCC was found  */
  NAS_SET_MCC_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_set_mcc_status_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Informs the modem of an MCC discovered by the client. */
typedef struct {

  /* Optional */
  /*  MCC */
  uint8_t mcc_valid;  /**< Must be set to true if mcc is being passed */
  uint16_t mcc;
  /**<   A 16-bit integer representation of MCC. 
       Range: 0 to 999.
  */

  /* Optional */
  /*  Confidence */
  uint8_t confidence_valid;  /**< Must be set to true if confidence is being passed */
  nas_mcc_confidence_enum_v01 confidence;
  /**<   Confidence level. Values: \n
      - NAS_MCC_CONFIDENCE_LOW (0x00) --  Low \n 
      - NAS_MCC_CONFIDENCE_MEDIUM_LOW (0x01) --  Medium low \n 
      - NAS_MCC_CONFIDENCE_MEDIUM (0x02) --  Medium \n 
      - NAS_MCC_CONFIDENCE_MEDIUM_HIGH (0x03) --  Medium high \n 
      - NAS_MCC_CONFIDENCE_HIGH (0x04) --  High 

 \vspace{3pt}
 All other values are reserved.
 */

  /* Optional */
  /*  MCC Detection Status */
  uint8_t mcc_status_valid;  /**< Must be set to true if mcc_status is being passed */
  nas_set_mcc_status_enum_v01 mcc_status;
  /**<   MCC detection status. Values: \n
      - NAS_SET_MCC_STATUS_SUCCESS (0x00) --  Valid MCC was passed in the request \n 
      - NAS_SET_MCC_STATUS_DETECTION_DISABLED (0x01) --  All mechanisms used to detect the MCC (Wi-Fi\regns, GPS, etc.) are 
       disabled by the user or control points \n 
      - NAS_SET_MCC_STATUS_NOT_DETECTED (0x02) --  MCC detection is enabled but no MCC was found 

 \vspace{3pt}
 All other values are reserved.
 */
}nas_set_mcc_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Informs the modem of an MCC discovered by the client. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_mcc_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_DATA_ROAMING_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_DATA_ROAMING_ON_V01 = 0x00, /**<  Roaming is on \n  */
  NAS_DATA_ROAMING_INTERNATIONAL_OFF_V01 = 0x01, /**<  Roaming for international is off  \n  */
  NAS_DATA_ROAMING_OFF_V01 = 0x02, /**<  Roaming is off  */
  NAS_DATA_ROAMING_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_data_roaming_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Informs the modem about a change in the data roaming status. */
typedef struct {

  /* Mandatory */
  /*  Data Roaming Status */
  nas_data_roaming_enum_v01 data_roam_status;
  /**<   Configures the data roaming status. Values: \n
      - NAS_DATA_ROAMING_ON (0x00) --  Roaming is on \n 
      - NAS_DATA_ROAMING_INTERNATIONAL_OFF (0x01) --  Roaming for international is off  \n 
      - NAS_DATA_ROAMING_OFF (0x02) --  Roaming is off 

 \vspace{3pt}
 All other values are reserved.
 */
}nas_set_data_roaming_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Informs the modem about a change in the data roaming status. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  Device Reset Pending */
  uint8_t pending_device_reset_valid;  /**< Must be set to true if pending_device_reset is being passed */
  uint8_t pending_device_reset;
  /**<   Indicates whether a device reset is required for the configured values 
       to take effect. Values: \n
       - TRUE  -- Reset is required \n
       - FALSE -- Reset is not required
  */
}nas_set_data_roaming_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the data roaming status from the modem. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_data_roaming_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the data roaming status from the modem. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  Data Roaming Status */
  uint8_t data_roam_status_valid;  /**< Must be set to true if data_roam_status is being passed */
  nas_data_roaming_enum_v01 data_roam_status;
  /**<   Data roaming status. Values: \n
      - NAS_DATA_ROAMING_ON (0x00) --  Roaming is on \n 
      - NAS_DATA_ROAMING_INTERNATIONAL_OFF (0x01) --  Roaming for international is off  \n 
      - NAS_DATA_ROAMING_OFF (0x02) --  Roaming is off 

 \vspace{3pt}
 All other values are reserved.
 */

  /* Optional */
  /*  Device Reset */
  uint8_t pending_device_reset_valid;  /**< Must be set to true if pending_device_reset is being passed */
  uint8_t pending_device_reset;
  /**<   Indicates whether a device reset was required for the configured values 
       to take effect. Values: \n
       - TRUE  -- Reset was required \n
       - FALSE -- Reset was not required
  */
}nas_get_data_roaming_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Informs the modem about a change in the Single Radio Voice 
               Call Continuity (SRVCC) status. */
typedef struct {

  /* Mandatory */
  /*  Single Radio Voice Call Continuity Status */
  uint8_t srvcc_status;
  /**<   Configure the state of SRVCC. Values: \n
       - TRUE  -- Enable \n
       - FALSE -- Disable
  */
}nas_set_srvcc_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Informs the modem about a change in the Single Radio Voice 
               Call Continuity (SRVCC) status. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_srvcc_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Informs the modem about a change in the Better System 
               Reselection (BSR) timer value.  */
typedef struct {

  /* Mandatory */
  /*  Better System Reselection Timer */
  uint32_t bsr_value;
  /**<   BSR timer value (in seconds) written to NV_SD_CFG_ITEMS_I.
       Range: 180 to 600.
  */
}nas_set_bsr_timer_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Informs the modem about a change in the Better System 
               Reselection (BSR) timer value.  */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  Delayed Until Reset */
  uint8_t delayed_until_reset_valid;  /**< Must be set to true if delayed_until_reset is being passed */
  uint8_t delayed_until_reset;
  /**<   Indicates whether a device reset is required for the configured values 
       to take effect. Values: \n
       - TRUE  -- Reset is required \n
       - FALSE -- Reset is not required
  */
}nas_set_bsr_timer_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the BSR timer value from the modem. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_bsr_timer_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the BSR timer value from the modem. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  Better System Reselection Timer */
  uint8_t bsr_value_valid;  /**< Must be set to true if bsr_value is being passed */
  uint32_t bsr_value;
  /**<   BSR timer value (in seconds) from NV_SD_CFG_ITEMS_I.
       Range: 180 to 600.
  */

  /* Optional */
  /*  Delayed Until Reset */
  uint8_t delayed_until_reset_valid;  /**< Must be set to true if delayed_until_reset is being passed */
  uint8_t delayed_until_reset;
  /**<   Indicates whether a device reset was required for the configured values 
       to take effect. Values: \n
       - TRUE  -- Reset was required \n
       - FALSE -- Reset was not required
  */
}nas_get_bsr_timer_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t target_freq;
  /**<   Target frequency (in MHz). */

  nas_radio_if_enum_v01 target_rat;
  /**<   Radio access technology for which to register. Values: \n
       - 0x04 -- RADIO_IF_GSM -- GSM \n
       - 0x05 -- RADIO_IF_UMTS -- UMTS \n 
       - 0x08 -- RADIO_IF_LTE -- LTE \n
	   - 0x09 -- RADIO_IF_TDSCDMA -- TD-SCDMA
  */
}nas_target_frequency_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Scales the wake-up duration by controlling the idle DRX cycle; 
               also used to skip the Idle mode measurements. */
typedef struct {

  /* Mandatory */
  /*  Radio Access Technology */
  nas_radio_if_enum_v01 radio_access_technology;
  /**<   Radio access technology for which to register. Values: \n
       - 0x04 -- RADIO_IF_GSM -- GSM \n
       - 0x05 -- RADIO_IF_UMTS -- UMTS \n 
       - 0x08 -- RADIO_IF_LTE -- LTE
  */

  /* Optional */
  /*  DRX Scaling Factor */
  uint8_t drx_scaling_factor_valid;  /**< Must be set to true if drx_scaling_factor is being passed */
  uint8_t drx_scaling_factor;
  /**<    Sets the DRX scaling factor.
        Range: 1 (default) to 10.
  */

  /* Optional */
  /*  Skip Idle Mode Measurements */
  uint8_t skip_idle_meas_valid;  /**< Must be set to true if skip_idle_meas is being passed */
  uint8_t skip_idle_meas;
  /**<   Whether to skip the Idle mode measurements. Values: \n
      - 0x00 -- FALSE \n
      - 0x01 -- TRUE
  */

  /* Optional */
  /*  Skip Idle Mode Measurements for Target Frequency */
  uint8_t idle_meas_skip_freq_valid;  /**< Must be set to true if idle_meas_skip_freq is being passed */
  uint32_t idle_meas_skip_freq_len;  /**< Must be set to # of elements in idle_meas_skip_freq */
  nas_target_frequency_info_type_v01 idle_meas_skip_freq[NAS_MAX_TARGET_FREQUENCIES_V01];
}nas_set_drx_scaling_factor_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Scales the wake-up duration by controlling the idle DRX cycle; 
               also used to skip the Idle mode measurements. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_drx_scaling_factor_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets the SSAC hysteresis timer.  */
typedef struct {

  /* Mandatory */
  /*  Hysteresis Timer Value */
  uint16_t hysteresis_timer;
  /**<   Hysteresis timer value (in seconds).
  */
}nas_set_ssac_hysteresis_timer_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets the SSAC hysteresis timer.  */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_ssac_hysteresis_timer_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the last known SSAC hysteresis timer. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_ssac_hysteresis_timer_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the last known SSAC hysteresis timer. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  Hysteresis Timer Value */
  uint8_t hysteresis_timer_valid;  /**< Must be set to true if hysteresis_timer is being passed */
  uint16_t hysteresis_timer;
  /**<   Hysteresis timer value (in seconds).
  */
}nas_get_ssac_hysteresis_timer_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the HDR sector ID, pilot pseudorandom noise, 
               and MAC index. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_hdr_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the HDR sector ID, pilot pseudorandom noise, 
               and MAC index. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  Sector ID */
  uint8_t sector_id_valid;  /**< Must be set to true if sector_id is being passed */
  uint8_t sector_id[NAS_HDRADDR_LENGTH_V01];
  /**<   Sector ID value, as a 128-bit address.
  */

  /* Optional */
  /*  Pilot PN */
  uint8_t pilot_pn_valid;  /**< Must be set to true if pilot_pn is being passed */
  uint16_t pilot_pn;
  /**<   Pilot PN value.
  */

  /* Optional */
  /*  MAC Index */
  uint8_t mac_index_valid;  /**< Must be set to true if mac_index is being passed */
  uint16_t mac_index;
  /**<   MAC index value.
  */
}nas_get_hdr_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the HDR data rate control. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_hdr_drc_rate_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the HDR data rate control. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  DRC Rate */
  uint8_t drc_rate_valid;  /**< Must be set to true if drc_rate is being passed */
  uint8_t drc_rate;
  /**<   DRC rate value.
  */
}nas_get_hdr_drc_rate_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets the Radio Policy Manager (RPM) details if RPM is active. */
typedef struct {

  /* Mandatory */
  /*  Maximum Application Resets */
  uint8_t max_resets;
  /**<   Maximum number of allowed application resets. 
       Range: 1 to 16 (default is 3).
  */

  /* Mandatory */
  /*  Average Rejection Time */
  uint16_t avg_reject_time;
  /**<   Average rejection time (in seconds). 
       Range: 0 to 360 (default is 120).
  */
}nas_set_rpm_parameters_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets the Radio Policy Manager (RPM) details if RPM is active. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_rpm_parameters_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the RPM details if RPM is active. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_rpm_parameters_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the RPM details if RPM is active. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  Maximum Application Resets */
  uint8_t max_resets_valid;  /**< Must be set to true if max_resets is being passed */
  uint8_t max_resets;
  /**<   Maximum number of application resets. 
       Range: 1 to 16 (default is 3).
  */

  /* Optional */
  /*  Average Rejection Time */
  uint8_t avg_reject_time_valid;  /**< Must be set to true if avg_reject_time is being passed */
  uint16_t avg_reject_time;
  /**<   Average rejection time (in seconds). 
       Range 0 to 360 (default is 120).
  */

  /* Optional */
  /*  RPM State */
  uint8_t rpm_state_valid;  /**< Must be set to true if rpm_state is being passed */
  uint8_t rpm_state;
  /**<   Status of the RPM. Values: \n
       - 0x00 -- Disabled \n
       - 0x01 -- Enabled
  */

  /* Optional */
  /*  Maximum Event Counter */
  uint8_t max_event_counter_valid;  /**< Must be set to true if max_event_counter is being passed */
  uint8_t max_event_counter;
  /**<   Maximum number of EMM reject events. 
       Range: 1 to 16 (default is 5).
  */

  /* Optional */
  /*  Maximum Event Timer */
  uint8_t max_event_time_valid;  /**< Must be set to true if max_event_time is being passed */
  uint16_t max_event_time;
  /**<   Maximum tracking event time (in seconds). 
       Range 0 to 360 (default is 120).
  */
}nas_get_rpm_parameters_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets the RPM event details, if RPM is active. */
typedef struct {

  /* Optional */
  /*  Maximum Event Counter */
  uint8_t max_event_counter_valid;  /**< Must be set to true if max_event_counter is being passed */
  uint8_t max_event_counter;
  /**<   Maximum number of EMM Reject events. 
       Range: 1 to 16 (default is 5).
  */

  /* Optional */
  /*  Maximum Event Time */
  uint8_t max_event_time_valid;  /**< Must be set to true if max_event_time is being passed */
  uint16_t max_event_time;
  /**<   Maximum tracking event time (in seconds). 
       Range: 0 to 360 (default is 120).
  */
}nas_set_rpm_parameters_2_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets the RPM event details, if RPM is active. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_rpm_parameters_2_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Enables and disables RPM. */
typedef struct {

  /* Mandatory */
  /*  RPM State */
  uint8_t rpm_state;
  /**<   RPM preferred status. Values: \n
       - 0x00 -- Disabled \n
       - 0x01 -- Enabled
  */
}nas_set_rpm_state_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Enables and disables RPM. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_rpm_state_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the previous carrier aggregation event information.
               \label{idl:getLteCphyCaInfo} */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_lte_cphy_ca_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the previous carrier aggregation event information.
               \label{idl:getLteCphyCaInfo} */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  Physical Carrier Aggregation of Scell Indicator Type */
  uint8_t cphy_ca_valid;  /**< Must be set to true if cphy_ca is being passed */
  nas_lte_cphy_ca_indicator_type_v01 cphy_ca;

  /* Optional */
  /*  Physical Carrier Aggregation Downlink Bandwidth for Scell */
  uint8_t cphy_ca_dl_bandwidth_valid;  /**< Must be set to true if cphy_ca_dl_bandwidth is being passed */
  nas_lte_cphy_ca_bandwidth_enum_v01 cphy_ca_dl_bandwidth;
  /**<   Downlink bandwidth. Values: \n
      - NAS_LTE_CPHY_CA_BW_NRB_6 (0x00) --  1.4 MHz bandwidth \n 
      - NAS_LTE_CPHY_CA_BW_NRB_15 (0x01) --  3 MHz bandwidth \n 
      - NAS_LTE_CPHY_CA_BW_NRB_25 (0x02) --  5 MHz bandwidth \n 
      - NAS_LTE_CPHY_CA_BW_NRB_50 (0x03) --  10 MHz bandwidth \n 
      - NAS_LTE_CPHY_CA_BW_NRB_75 (0x04) --  15 MHz bandwidth \n 
      - NAS_LTE_CPHY_CA_BW_NRB_100 (0x05) --  20 MHz bandwidth 

 \vspace{3pt}
 All other values are reserved.
 */

  /* Optional */
  /*  Scell Information (Deprecated; use Scell Information Array) */
  uint8_t scell_info_valid;  /**< Must be set to true if scell_info is being passed */
  nas_lte_cphy_scell_info_type_v01 scell_info;

  /* Optional */
  /*  Pcell Information */
  uint8_t pcell_info_valid;  /**< Must be set to true if pcell_info is being passed */
  nas_lte_cphy_pcell_info_type_v01 pcell_info;
  /**<   Contains all Pcell info \n
       If the frequency field is non-zero, it is the true frequency; if it is zero,
       the true frequency may be found in the 'Pcell Extended Frequency' TLV. The
       'Pcell Extended Frequency' TLV always holds the true frequency and can always
       be used regardless of the value in the frequency field of this TLV.
  */

  /* Optional */
  /*  Scell Index (Deprecated; use Scell Information Array) */
  uint8_t scell_idx_valid;  /**< Must be set to true if scell_idx is being passed */
  uint8_t scell_idx;
  /**<   Scell index. */

  /* Optional */
  /*  Scell Information Array */
  uint8_t cphy_scell_info_list_valid;  /**< Must be set to true if cphy_scell_info_list is being passed */
  uint32_t cphy_scell_info_list_len;  /**< Must be set to # of elements in cphy_scell_info_list */
  nas_cphy_scell_info_v01 cphy_scell_info_list[NAS_MAX_SCELL_LIST_LEN_V01];
  /**<   Scell Information array \n
       If the frequency field is non-zero, it is the true frequency; if it is zero,
       the true frequency may be found in the 'Scell Extended Frequency Array' TLV.
       The 'Scell Extended Frequency Array' TLV always holds the true frequency and
       can always be used regardless of the value in the frequency field of this TLV.
  */

  /* Optional */
  /*  Pcell Extended Frequency */
  uint8_t pcell_freq_valid;  /**< Must be set to true if pcell_freq is being passed */
  uint32_t pcell_freq;
  /**<   Pcell frequency - extended size \n
       This TLV should be used in place of the frequency field from the 'Pcell Information' TLV
  */

  /* Optional */
  /*  Scell Extended Frequency Array */
  uint8_t cphy_scell_freq_list_valid;  /**< Must be set to true if cphy_scell_freq_list is being passed */
  uint32_t cphy_scell_freq_list_len;  /**< Must be set to # of elements in cphy_scell_freq_list */
  uint32_t cphy_scell_freq_list[NAS_MAX_SCELL_LIST_LEN_V01];
  /**<   Scell freqeuncy list - extended size \n
       This TLV should be used in place of the frequency field from the 'Scell Information Array' TLV
  */
}nas_get_lte_cphy_ca_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Informs the control point that the manual network search
             could not find any networks with the specified parameters. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_manual_scan_fail_ind_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t pci;
  /**<   Physical cell ID. */

  uint16_t freq;
  /**<   Cell frequency. */
}nas_cell_lock_entry_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Configures the cell list so that service 
              acquisition is limited only to the listed cells.(Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Cell List */
  uint32_t cell_list_len;  /**< Must be set to # of elements in cell_list */
  nas_cell_lock_entry_type_v01 cell_list[NAS_MAX_CELL_LOCK_ENTRIES_V01];
}nas_set_cell_lock_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Configures the cell list so that service 
              acquisition is limited only to the listed cells.(Deprecated) */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_cell_lock_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t pci;
  /**<   Physical cell ID. */

  uint32_t freq;
  /**<   Cell frequency. */
}nas_cell_lock_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Configures the cell list so that service 
              acquisition is limited only to the listed cells. */
typedef struct {

  /* Mandatory */
  /*  Cell List */
  uint32_t cell_list_len;  /**< Must be set to # of elements in cell_list */
  nas_cell_lock_info_type_v01 cell_list[NAS_MAX_CELL_LOCK_ENTRIES_V01];
  /**<   Cell list 
  */
}nas_set_cell_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Configures the cell list so that service 
              acquisition is limited only to the listed cells. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_cell_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Dynamically upgrades or downgrades an LTE UE category,
              enables or disables carrier aggregation, or both. */
typedef struct {

  /* Optional */
  /*  LTE UE Category */
  uint8_t lte_ue_category_valid;  /**< Must be set to true if lte_ue_category is being passed */
  nas_lte_ue_category_e_type_v01 lte_ue_category;
  /**<   LTE UE category. \n
      - LTE_UE_CATEGORY_DEFAULT (0) --  Default; return to power-up configuration \n 
      - LTE_UE_CATEGORY_1 (1) --  Type~1 \n 
      - LTE_UE_CATEGORY_2 (2) --  Type~2 \n 
      - LTE_UE_CATEGORY_3 (3) --  Type~3 \n 
      - LTE_UE_CATEGORY_4 (4) --  Type~4 \n 
      - LTE_UE_CATEGORY_5 (5) --  Type~5 \n 
      - LTE_UE_CATEGORY_6 (6) --  Type~6 \n 
      - LTE_UE_CATEGORY_7 (7) --  Type~7 \n 
      - LTE_UE_CATEGORY_8 (8) --  Type~8 \n 
      - LTE_UE_CATEGORY_9 (9) --  Type~9 \n 
      - LTE_UE_CATEGORY_10 (10) --  Type~10 \n 
      - LTE_UE_CATEGORY_11 (11) --  Type~11 \n 
      - LTE_UE_CATEGORY_12 (12) --  Type~12 \n 
      - LTE_UE_CATEGORY_13 (13) --  Type~13 \n 
      - LTE_UE_CATEGORY_INVALID (14) --  Invalid~type 
 */

  /* Optional */
  /*  Disable CA */
  uint8_t disable_ca_valid;  /**< Must be set to true if disable_ca is being passed */
  uint8_t disable_ca;
  /**<   Indicates whether carrier aggregation is disabled. 
       Values: \n
       - TRUE  -- Disabled \n
       - FALSE -- Enabled
  */
}nas_lte_ue_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Dynamically upgrades or downgrades an LTE UE category,
              enables or disables carrier aggregation, or both. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_lte_ue_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_TIMER_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_ECALL_T3242_TIMER_EXPIRED_V01 = 0x01, /**<  ECall timer T3242 has expired \n  */
  NAS_ECALL_T3243_TIMER_EXPIRED_V01 = 0x02, /**<  ECall timer T3243 has expired  */
  NAS_TIMER_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_timer_type_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates the ID for the timer that has expired. */
typedef struct {

  /* Mandatory */
  /*  Expired Timer ID */
  nas_timer_type_enum_v01 timer_id;
  /**<   Timer expired. Values: \n
      - NAS_ECALL_T3242_TIMER_EXPIRED (0x01) --  ECall timer T3242 has expired \n 
      - NAS_ECALL_T3243_TIMER_EXPIRED (0x02) --  ECall timer T3243 has expired 
 */
}nas_timer_expiry_ind_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_EMERGENCY_MODE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_EMERGENCY_MODE_STARTED_V01 = 0x01, /**<  Emergency mode has started \n  */
  NAS_EMERGENCY_MODE_ENDED_V01 = 0x02, /**<  Emergency mode has ended  */
  NAS_EMERGENCY_MODE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_emergency_mode_enum_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates the Emergency mode status. */
typedef struct {

  /* Mandatory */
  /*  Emergency Mode */
  nas_emergency_mode_enum_v01 emergency_mode;
  /**<   Emergency mode. Values: \n
      - NAS_EMERGENCY_MODE_STARTED (0x01) --  Emergency mode has started \n 
      - NAS_EMERGENCY_MODE_ENDED (0x02) --  Emergency mode has ended 
 */

  /* Optional */
  /*  ECBM Required on LTE */
  uint8_t is_ecbm_required_valid;  /**< Must be set to true if is_ecbm_required is being passed */
  uint8_t is_ecbm_required;
  /**<   Indicates whether LTE ECBM is required by an NV setting. Values: \n
       - TRUE  -- LTE ECBM is required \n
       - FALSE -- LTE ECBM is not required
    */
}nas_emergency_mode_status_ind_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Triggers a deregistration operation for an ECall. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_ecall_deregistration_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Triggers a deregistration operation for an ECall. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type.*/
}nas_ecall_deregistration_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Updates the specified carrier aggregation band combination string 
              for a PLMN. */
typedef struct {

  /* Mandatory */
  /*  PLMN */
  nas_plmn_id_ext_type_v01 plmn;

  /* Optional */
  /*  CA Band Combo String */
  uint8_t ca_band_combo_valid;  /**< Must be set to true if ca_band_combo is being passed */
  uint32_t ca_band_combo_len;  /**< Must be set to # of elements in ca_band_combo */
  char ca_band_combo[NAS_CA_BAND_COMBO_MAX_LEN_V01];
  /**<   CA band combination
  */
}nas_update_ca_band_combo_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Updates the specified carrier aggregation band combination string 
              for a PLMN. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_update_ca_band_combo_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the specified carrier aggregation band combination string 
              for a specific PLMN. */
typedef struct {

  /* Mandatory */
  /*  PLMN */
  nas_plmn_id_ext_type_v01 plmn;
}nas_get_ca_band_combo_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the specified carrier aggregation band combination string 
              for a specific PLMN. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  CA band combo string */
  uint8_t ca_band_combo_valid;  /**< Must be set to true if ca_band_combo is being passed */
  uint32_t ca_band_combo_len;  /**< Must be set to # of elements in ca_band_combo */
  char ca_band_combo[NAS_CA_BAND_COMBO_MAX_LEN_V01];
  /**<   CA band combination
  */
}nas_get_ca_band_combo_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  NAS_ECALL_TIMER_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NAS_ECALL_T3242_TIMER_V01 = 0x01, /**<  ECall timer T3242 \n  */
  NAS_ECALL_T3243_TIMER_V01 = 0x02, /**<  ECall timer T3243  */
  NAS_ECALL_TIMER_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nas_ecall_timer_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Allows apps to request the timer restart and give the 
              remaining time for the timer to run. */
typedef struct {

  /* Mandatory */
  /*  Timer ID */
  nas_ecall_timer_type_v01 timer_id;
  /**<   Timer ID. Values: \n
      - NAS_ECALL_T3242_TIMER (0x01) --  ECall timer T3242 \n 
      - NAS_ECALL_T3243_TIMER (0x02) --  ECall timer T3243 
 */

  /* Mandatory */
  /*  Duration */
  uint32_t duration;
  /**<   Number of seconds for the timer to run.
  */
}nas_ecall_timer_restart_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Allows apps to request the timer restart and give the 
              remaining time for the timer to run. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_ecall_timer_restart_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Allows apps to modify the phone's voice roaming settings. */
typedef struct {

  /* Mandatory */
  /*  International Voice Roaming Status */
  uint8_t international_voice_roaming_allowed;
  /**<   Configures the international voice roaming status. Values: \n
       - TRUE -- International roaming is enabled \n 
       - FALSE -- International roaming is disabled
  */

  /* Optional */
  /*  Domestic Voice Roaming Status */
  uint8_t domestic_voice_roaming_allowed_valid;  /**< Must be set to true if domestic_voice_roaming_allowed is being passed */
  uint8_t domestic_voice_roaming_allowed;
  /**<   Configures the domestic voice roaming status. Values: \n
       - TRUE -- Domestic roaming is enabled (default)\n 
       - FALSE -- Domestic roaming is disabled \n
  */
}nas_set_voice_roaming_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Allows apps to modify the phone's voice roaming settings. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_voice_roaming_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the voice roaming status from the modem. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_voice_roaming_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the voice roaming status from the modem. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  International Voice Roaming Status */
  uint8_t international_voice_roaming_allowed_valid;  /**< Must be set to true if international_voice_roaming_allowed is being passed */
  uint8_t international_voice_roaming_allowed;
  /**<   International voice roaming status. Values: \n
       - TRUE -- International roaming is enabled \n 
       - FALSE -- International roaming is disabled
  */

  /* Optional */
  /*  Domestic Voice Roaming Status */
  uint8_t domestic_voice_roaming_allowed_valid;  /**< Must be set to true if domestic_voice_roaming_allowed is being passed */
  uint8_t domestic_voice_roaming_allowed;
  /**<   Domestic voice roaming status. Values: \n
       - TRUE -- Domestic roaming is enabled \n 
       - FALSE -- Domestic roaming is disabled
  */
}nas_get_voice_roaming_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets the extended DRX (eDRX) for the device. */
typedef struct {

  /* Mandatory */
  /*  eDRX Setting */
  uint8_t edrx_params;
  /**<   eDRX setting for the device. Value to be set per 
       \hyperref[STD-24008]{3GPP TS 24.008 Rel-13} Section 10.5.5.32, 
       which includes the eDRX cycle length value and paging time window.
  */
}nas_set_edrx_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets the extended DRX (eDRX) for the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */
}nas_set_edrx_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets the eDRX parameters for the device. */
typedef struct {

  /* Optional */
  /*  eDRX Enable */
  uint8_t edrx_enabled_valid;  /**< Must be set to true if edrx_enabled is being passed */
  uint8_t edrx_enabled;
  /**<   Whether to enable eDRX. Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  Cycle Length */
  uint8_t edrx_cycle_length_valid;  /**< Must be set to true if edrx_cycle_length is being passed */
  uint8_t edrx_cycle_length;
  /**<   eDRX cycle length. Value to be set per 
       \hyperref[STD-24008]{3GPP TS 24.008 Rel-13} Section 10.5.5.32.
  */

  /* Optional */
  /*  Paging Time Window */
  uint8_t edrx_ptw_valid;  /**< Must be set to true if edrx_ptw is being passed */
  uint8_t edrx_ptw;
  /**<   eDRX paging time window. Value to be set per 
       \hyperref[STD-24008]{3GPP TS 24.008 Rel-13} Section 10.5.5.32.
  */

  /* Optional */
  /*  eDRX Radio Access Technology */
  uint8_t edrx_rat_type_valid;  /**< Must be set to true if edrx_rat_type is being passed */
  nas_radio_if_enum_v01 edrx_rat_type;
  /**<   Radio access technology. Values: \n
      - NAS_RADIO_IF_NO_SVC (0x00) --  None (no service) \n 
      - NAS_RADIO_IF_CDMA_1X (0x01) --  cdma2000\textsuperscript{\textregistered} 1X \n 
      - NAS_RADIO_IF_CDMA_1XEVDO (0x02) --  cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n 
      - NAS_RADIO_IF_AMPS (0x03) --  AMPS \n 
      - NAS_RADIO_IF_GSM (0x04) --  GSM \n 
      - NAS_RADIO_IF_UMTS (0x05) --  UMTS \n 
      - NAS_RADIO_IF_WLAN (0x06) --  WLAN \n 
      - NAS_RADIO_IF_GPS (0x07) --  GPS \n 
      - NAS_RADIO_IF_LTE (0x08) --  LTE \n 
      - NAS_RADIO_IF_TDSCDMA (0x09) --  TD-SCDMA \n 
      - NAS_RADIO_IF_NR5G (0x0C) --  NR5G \n 
      - NAS_RADIO_IF_NO_CHANGE (-1) --  No change 

 \vspace{3pt}
 Note: The device will use "0x08 -- NAS_RADIO_IF_LTE" as the default value 
 if the TLV is omitted.
 */

  /* Optional */
  /*  LTE Operational Mode */
  uint8_t edrx_ciot_lte_mode_valid;  /**< Must be set to true if edrx_ciot_lte_mode is being passed */
  nas_camped_ciot_lte_op_mode_enum_type_v01 edrx_ciot_lte_mode;
  /**<   CIOT LTE mode. Values: \n
      - NAS_CIOT_SYS_MODE_NO_SRV (0x00) --  No service \n 
      - NAS_CIOT_SYS_MODE_LTE_WB (0x01) --  Camped on LTE wideband \n 
      - NAS_CIOT_SYS_MODE_LTE_M1 (0x02) --  Camped on LTE M1 \n 
      - NAS_CIOT_SYS_MODE_LTE_NB1 (0x03) --  Camped on LTE NB1 

 Note: This TLV should be set when edrx_rat_type is LTE.
 */
}nas_set_edrx_params_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets the eDRX parameters for the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */
}nas_set_edrx_params_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the eDRX parameters for the device. */
typedef struct {

  /* Optional */
  /*  eDRX Radio Access Technology */
  uint8_t edrx_rat_type_valid;  /**< Must be set to true if edrx_rat_type is being passed */
  nas_radio_if_enum_v01 edrx_rat_type;
  /**<   Radio access technology. Values: \n
      - NAS_RADIO_IF_NO_SVC (0x00) --  None (no service) \n 
      - NAS_RADIO_IF_CDMA_1X (0x01) --  cdma2000\textsuperscript{\textregistered} 1X \n 
      - NAS_RADIO_IF_CDMA_1XEVDO (0x02) --  cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n 
      - NAS_RADIO_IF_AMPS (0x03) --  AMPS \n 
      - NAS_RADIO_IF_GSM (0x04) --  GSM \n 
      - NAS_RADIO_IF_UMTS (0x05) --  UMTS \n 
      - NAS_RADIO_IF_WLAN (0x06) --  WLAN \n 
      - NAS_RADIO_IF_GPS (0x07) --  GPS \n 
      - NAS_RADIO_IF_LTE (0x08) --  LTE \n 
      - NAS_RADIO_IF_TDSCDMA (0x09) --  TD-SCDMA \n 
      - NAS_RADIO_IF_NR5G (0x0C) --  NR5G \n 
      - NAS_RADIO_IF_NO_CHANGE (-1) --  No change 

 \vspace{3pt}
 Note: The device will use "0x08 -- NAS_RADIO_IF_LTE" as the default value 
 if the TLV is omitted.
 */

  /* Optional */
  /*  LTE Operational Mode */
  uint8_t edrx_ciot_lte_mode_valid;  /**< Must be set to true if edrx_ciot_lte_mode is being passed */
  nas_camped_ciot_lte_op_mode_enum_type_v01 edrx_ciot_lte_mode;
  /**<   CIOT LTE mode. Values: \n
      - NAS_CIOT_SYS_MODE_NO_SRV (0x00) --  No service \n 
      - NAS_CIOT_SYS_MODE_LTE_WB (0x01) --  Camped on LTE wideband \n 
      - NAS_CIOT_SYS_MODE_LTE_M1 (0x02) --  Camped on LTE M1 \n 
      - NAS_CIOT_SYS_MODE_LTE_NB1 (0x03) --  Camped on LTE NB1 

 Note: This TLV should be set when edrx_rat_type is LTE.
 */
}nas_get_edrx_params_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the eDRX parameters for the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */

  /* Optional */
  /*  Cycle Length */
  uint8_t edrx_cycle_length_valid;  /**< Must be set to true if edrx_cycle_length is being passed */
  uint8_t edrx_cycle_length;
  /**<   eDRX cycle length. Value is per 
       \hyperref[STD-24008]{3GPP TS 24.008 Rel-13} Section 10.5.5.32.
  */

  /* Optional */
  /*  Paging Time Window */
  uint8_t edrx_ptw_valid;  /**< Must be set to true if edrx_ptw is being passed */
  uint8_t edrx_ptw;
  /**<   eDRX paging time window. Value is per 
       \hyperref[STD-24008]{3GPP TS 24.008 Rel-13} Section 10.5.5.32.
  */

  /* Optional */
  /*  eDRX Enable */
  uint8_t edrx_enabled_valid;  /**< Must be set to true if edrx_enabled is being passed */
  uint8_t edrx_enabled;
  /**<   Whether eDRX is enabled. Values: \n
       - 0x00 -- Disabled \n
       - 0x01 -- Enabled
  */

  /* Optional */
  /*  eDRX Radio Access Technology */
  uint8_t edrx_rat_type_valid;  /**< Must be set to true if edrx_rat_type is being passed */
  nas_radio_if_enum_v01 edrx_rat_type;
  /**<   Radio access technology. Values: \n
      - NAS_RADIO_IF_NO_SVC (0x00) --  None (no service) \n 
      - NAS_RADIO_IF_CDMA_1X (0x01) --  cdma2000\textsuperscript{\textregistered} 1X \n 
      - NAS_RADIO_IF_CDMA_1XEVDO (0x02) --  cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n 
      - NAS_RADIO_IF_AMPS (0x03) --  AMPS \n 
      - NAS_RADIO_IF_GSM (0x04) --  GSM \n 
      - NAS_RADIO_IF_UMTS (0x05) --  UMTS \n 
      - NAS_RADIO_IF_WLAN (0x06) --  WLAN \n 
      - NAS_RADIO_IF_GPS (0x07) --  GPS \n 
      - NAS_RADIO_IF_LTE (0x08) --  LTE \n 
      - NAS_RADIO_IF_TDSCDMA (0x09) --  TD-SCDMA \n 
      - NAS_RADIO_IF_NR5G (0x0C) --  NR5G \n 
      - NAS_RADIO_IF_NO_CHANGE (-1) --  No change 
 */

  /* Optional */
  /*  LTE Operational Mode */
  uint8_t edrx_ciot_lte_mode_valid;  /**< Must be set to true if edrx_ciot_lte_mode is being passed */
  nas_camped_ciot_lte_op_mode_enum_type_v01 edrx_ciot_lte_mode;
  /**<   CIOT LTE mode. Values: \n
      - NAS_CIOT_SYS_MODE_NO_SRV (0x00) --  No service \n 
      - NAS_CIOT_SYS_MODE_LTE_WB (0x01) --  Camped on LTE wideband \n 
      - NAS_CIOT_SYS_MODE_LTE_M1 (0x02) --  Camped on LTE M1 \n 
      - NAS_CIOT_SYS_MODE_LTE_NB1 (0x03) --  Camped on LTE NB1 
 */
}nas_get_edrx_params_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the eDRX for the device. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_edrx_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the eDRX for the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */

  /* Optional */
  /*  eDRX Setting */
  uint8_t edrx_params_valid;  /**< Must be set to true if edrx_params is being passed */
  uint8_t edrx_params;
  /**<   eDRX setting for the device. Value is per 
       \hyperref[STD-24008]{3GPP TS 24.008 Rel-13} Section 10.5.5.32, 
       which includes the eDRX cycle length value and paging time window.
  */
}nas_get_edrx_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates a change in the eDRX value. */
typedef struct {

  /* Optional */
  /*  eDRX Enabled */
  uint8_t edrx_enabled_valid;  /**< Must be set to true if edrx_enabled is being passed */
  uint8_t edrx_enabled;
  /**<   Whether eDRX is enabled. Values: \n
       - 0x00 -- Disabled \n
       - 0x01 -- Enabled
  */

  /* Optional */
  /*  Cycle Length */
  uint8_t edrx_cycle_length_valid;  /**< Must be set to true if edrx_cycle_length is being passed */
  uint8_t edrx_cycle_length;
  /**<   eDRX cycle length. Value is per 
       \hyperref[STD-24008]{3GPP TS 24.008 Rel-13} Section 10.5.5.32.
  */

  /* Optional */
  /*  Paging Time Window */
  uint8_t edrx_ptw_valid;  /**< Must be set to true if edrx_ptw is being passed */
  uint8_t edrx_ptw;
  /**<   eDRX paging time window. Value is per 
       \hyperref[STD-24008]{3GPP TS 24.008 Rel-13} Section 10.5.5.32.
  */

  /* Optional */
  /*  eDRX Radio Access Technology */
  uint8_t edrx_rat_type_valid;  /**< Must be set to true if edrx_rat_type is being passed */
  nas_radio_if_enum_v01 edrx_rat_type;
  /**<   Radio access technology. Values: \n
      - NAS_RADIO_IF_NO_SVC (0x00) --  None (no service) \n 
      - NAS_RADIO_IF_CDMA_1X (0x01) --  cdma2000\textsuperscript{\textregistered} 1X \n 
      - NAS_RADIO_IF_CDMA_1XEVDO (0x02) --  cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n 
      - NAS_RADIO_IF_AMPS (0x03) --  AMPS \n 
      - NAS_RADIO_IF_GSM (0x04) --  GSM \n 
      - NAS_RADIO_IF_UMTS (0x05) --  UMTS \n 
      - NAS_RADIO_IF_WLAN (0x06) --  WLAN \n 
      - NAS_RADIO_IF_GPS (0x07) --  GPS \n 
      - NAS_RADIO_IF_LTE (0x08) --  LTE \n 
      - NAS_RADIO_IF_TDSCDMA (0x09) --  TD-SCDMA \n 
      - NAS_RADIO_IF_NR5G (0x0C) --  NR5G \n 
      - NAS_RADIO_IF_NO_CHANGE (-1) --  No change 
 */

  /* Optional */
  /*  LTE Operational Mode */
  uint8_t edrx_ciot_lte_mode_valid;  /**< Must be set to true if edrx_ciot_lte_mode is being passed */
  nas_camped_ciot_lte_op_mode_enum_type_v01 edrx_ciot_lte_mode;
  /**<   CIOT LTE mode. Values: \n
      - NAS_CIOT_SYS_MODE_NO_SRV (0x00) --  No service \n 
      - NAS_CIOT_SYS_MODE_LTE_WB (0x01) --  Camped on LTE wideband \n 
      - NAS_CIOT_SYS_MODE_LTE_M1 (0x02) --  Camped on LTE M1 \n 
      - NAS_CIOT_SYS_MODE_LTE_NB1 (0x03) --  Camped on LTE NB1 
 */
}nas_edrx_change_info_ind_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets the GNSS session status for the device. */
typedef struct {

  /* Mandatory */
  /*  GNSS Session Status */
  uint8_t gnss_session_active;
  /**<   Whether the GNSS session is active. Values: \n
       - 0x00 -- FALSE \n
       - 0x01 -- TRUE    
  */
}nas_set_gnss_session_status_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets the GNSS session status for the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */
}nas_set_gnss_session_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the LTE Tx activity and LTE Tx band information. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_lte_rrc_tx_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the LTE Tx activity and LTE Tx band information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */

  /* Optional */
  /*  LTE Tx is Active */
  uint8_t lte_tx_is_active_valid;  /**< Must be set to true if lte_tx_is_active is being passed */
  uint8_t lte_tx_is_active;
  /**<   Whether LTE Tx is active at RRC. Values: \n
       - 0x00 -- FALSE \n
       - 0x01 -- TRUE    
  */

  /* Optional */
  /*  Associated LTE Active Band (Applicable when LTE Tx is Active TLV is TRUE.) */
  uint8_t lte_tx_band_valid;  /**< Must be set to true if lte_tx_band is being passed */
  nas_active_band_enum_v01 lte_tx_band;
  /**<   LTE band information. Values: \n
       - 120 to 165 -- LTE band classes (see Table @latexonly\ref{tbl:bandClass}@endlatexonly for details)
  */
}nas_get_lte_rrc_tx_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates a change in the value of Tx activity of LTE RAT and 
              the associated LTE Tx band. */
typedef struct {

  /* Mandatory */
  /*  LTE Tx is Active */
  uint8_t lte_tx_is_active;
  /**<   Whether LTE Tx is active at CPHY. Values: \n
       - 0x00 -- FALSE  \n
       - 0x01 -- TRUE    
  */

  /* Optional */
  /*  Associated LTE Active Band (Applicable when LTE Tx is Active TLV is TRUE.)  */
  uint8_t lte_tx_band_valid;  /**< Must be set to true if lte_tx_band is being passed */
  nas_active_band_enum_v01 lte_tx_band;
  /**<   LTE band information. Values: \n
       - 120 to 165 -- LTE band classes (see Table @latexonly\ref{tbl:bandClass}@endlatexonly for details)
  */
}nas_lte_rrc_tx_info_ind_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t arfcn;
  /**<   Absolute RF channel number.
  */

  uint8_t bsic;
  /**<   Base station identity code.
  */

  uint8_t plmn_id[NAS_PLMN_LEN_V01];
  /**<    MCC/MNC information coded as octet 3, 4, and 5 in 
       \hyperref[STD-24008]{3GPP TS 24.008} Section 10.5.1.3. 
       (This field is ignored when cell_id is not present.)
  */

  uint16_t cell_id;
  /**<   Cell ID (0xFFFFFFFF indicates cell ID information is not present).
  */

  uint16_t location_area_code;
  /**<   Location area code. (This field is ignored when cell_id is not present.)
  */
}geran_grr_gcell_identifier_s_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates the GERAN cell information. */
typedef struct {

  /* Mandatory */
  /*  GERAN Cell Information */
  geran_grr_gcell_identifier_s_v01 uid_camped_cell;

  /* Optional */
  /*  System Information Mask */
  uint8_t broadcast_si_mask_valid;  /**< Must be set to true if broadcast_si_mask is being passed */
  uint16_t broadcast_si_mask;
  /**<   System information mask.
  */

  /* Optional */
  /*  System Information 1 Cell Allocation */
  uint8_t si1_cell_allocation_valid;  /**< Must be set to true if si1_cell_allocation is being passed */
  uint32_t si1_cell_allocation_len;  /**< Must be set to # of elements in si1_cell_allocation */
  uint16_t si1_cell_allocation[NAS_MAX_GERAN_CELL_ALLOCATION_V01];
  /**<   System information 1 cell allocation.
  */

  /* Optional */
  /*  RA Color */
  uint8_t ra_color_valid;  /**< Must be set to true if ra_color is being passed */
  uint8_t ra_color;
  /**<   Routing area color.
  */

  /* Optional */
  /*  Reselection Offset */
  uint8_t reselection_offset_valid;  /**< Must be set to true if reselection_offset is being passed */
  uint8_t reselection_offset;
  /**<   Reselection offset.
  */

  /* Optional */
  /*  Periodic Location Update Timer T3212 */
  uint8_t t3212_valid;  /**< Must be set to true if t3212 is being passed */
  uint8_t t3212;
  /**<   Periodic location update timer T3212.
  */

  /* Optional */
  /*  Rx Minimum Level */
  uint8_t rx_lev_min_valid;  /**< Must be set to true if rx_lev_min is being passed */
  uint8_t rx_lev_min;
  /**<   Rx minimum level.
  */

  /* Optional */
  /*  System Information 13 Position */
  uint8_t si13_position_valid;  /**< Must be set to true if si13_position is being passed */
  uint8_t si13_position;
  /**<   System information 13 position.
  */

  /* Optional */
  /*  Mobile Switching Center Revision Number */
  uint8_t MSCR_valid;  /**< Must be set to true if MSCR is being passed */
  uint8_t MSCR;
  /**<   Mobile switching center revision number.
  */

  /* Optional */
  /*  System Information Status */
  uint8_t mandatory_si_status_valid;  /**< Must be set to true if mandatory_si_status is being passed */
  uint8_t mandatory_si_status;
  /**<   System information status.
  */

  /* Optional */
  /*  Unique ARFCN List of Neighbor Cells */
  uint8_t gsm_neighbor_cell_unique_arfcn_list_valid;  /**< Must be set to true if gsm_neighbor_cell_unique_arfcn_list is being passed */
  uint32_t gsm_neighbor_cell_unique_arfcn_list_len;  /**< Must be set to # of elements in gsm_neighbor_cell_unique_arfcn_list */
  uint16_t gsm_neighbor_cell_unique_arfcn_list[NAS_BA_MAX_LEN_V01];
  /**<   Unique ARFCN list of neighbor cells.
  */

  /* Optional */
  /*  Cell Reselect Hysteresis */
  uint8_t cell_reselect_hysteresis_valid;  /**< Must be set to true if cell_reselect_hysteresis is being passed */
  uint8_t cell_reselect_hysteresis;
  /**<   Hysteresis for cell reselection used in the calculation of C2 parameter. 
       Refer to \hyperref[STD-45008]{3GPP TS 45.008} Chapter 9.
  */

  /* Optional */
  /*  MS Tx Pwr Max CCH */
  uint8_t ms_txpwr_max_cch_valid;  /**< Must be set to true if ms_txpwr_max_cch is being passed */
  uint8_t ms_txpwr_max_cch;
  /**<   Maximum Tx power level that a mobile station can use when accessing the system.       
  */

  /* Optional */
  /*  Temporary Offset */
  uint8_t temporary_offset_valid;  /**< Must be set to true if temporary_offset is being passed */
  uint8_t temporary_offset;
  /**<   Temporary offset used in the calculation of C2 parameter. 
       Refer to \hyperref[STD-45008]{3GPP TS 45.008} Chapter 9.
  */

  /* Optional */
  /*  Penalty Time */
  uint8_t penalty_time_valid;  /**< Must be set to true if penalty_time is being passed */
  uint8_t penalty_time;
  /**<   Penalty time used in the calculation of C2 parameter. 
       Refer to \hyperref[STD-45008]{3GPP TS 45.008} Chapter 9.
  */
}nas_gcell_info_ind_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Allows apps to query for GERAN cell information from the modem. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_gcell_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Allows apps to query for GERAN cell information from the modem. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type.*/

  /* Mandatory */
  /*  GERAN Cell Information */
  geran_grr_gcell_identifier_s_v01 uid_camped_cell;

  /* Optional */
  /*  System Information Mask */
  uint8_t broadcast_si_mask_valid;  /**< Must be set to true if broadcast_si_mask is being passed */
  uint16_t broadcast_si_mask;
  /**<   System information mask.
  */

  /* Optional */
  /*  System Information 1 Cell Allocation */
  uint8_t si1_cell_allocation_valid;  /**< Must be set to true if si1_cell_allocation is being passed */
  uint32_t si1_cell_allocation_len;  /**< Must be set to # of elements in si1_cell_allocation */
  uint16_t si1_cell_allocation[NAS_MAX_GERAN_CELL_ALLOCATION_V01];
  /**<   System information 1 cell allocation.
  */

  /* Optional */
  /*  RA Color */
  uint8_t ra_color_valid;  /**< Must be set to true if ra_color is being passed */
  uint8_t ra_color;
  /**<   Routing area color.
  */

  /* Optional */
  /*  Reselection Offset */
  uint8_t reselection_offset_valid;  /**< Must be set to true if reselection_offset is being passed */
  uint8_t reselection_offset;
  /**<   Reselection offset.
  */

  /* Optional */
  /*  Periodic Location Update Timer T3212 */
  uint8_t t3212_valid;  /**< Must be set to true if t3212 is being passed */
  uint8_t t3212;
  /**<   Periodic location update timer T3212.
  */

  /* Optional */
  /*  Rx Minimum Level */
  uint8_t rx_lev_min_valid;  /**< Must be set to true if rx_lev_min is being passed */
  uint8_t rx_lev_min;
  /**<   Rx minimum level.
  */

  /* Optional */
  /*  System Information 13 Position */
  uint8_t si13_position_valid;  /**< Must be set to true if si13_position is being passed */
  uint8_t si13_position;
  /**<   System information 13 position.
  */

  /* Optional */
  /*  Mobile Switching Center Revision Number */
  uint8_t MSCR_valid;  /**< Must be set to true if MSCR is being passed */
  uint8_t MSCR;
  /**<   Mobile switching center revision number.
  */

  /* Optional */
  /*  System Information Status */
  uint8_t mandatory_si_status_valid;  /**< Must be set to true if mandatory_si_status is being passed */
  uint8_t mandatory_si_status;
  /**<   System information status.
  */

  /* Optional */
  /*  Unique ARFCN List of Neighbor Cells */
  uint8_t gsm_neighbor_cell_unique_arfcn_list_valid;  /**< Must be set to true if gsm_neighbor_cell_unique_arfcn_list is being passed */
  uint32_t gsm_neighbor_cell_unique_arfcn_list_len;  /**< Must be set to # of elements in gsm_neighbor_cell_unique_arfcn_list */
  uint16_t gsm_neighbor_cell_unique_arfcn_list[NAS_BA_MAX_LEN_V01];
  /**<   Unique ARFCN list of neighbor cells.
  */

  /* Optional */
  /*  Cell Reselect Hysteresis */
  uint8_t cell_reselect_hysteresis_valid;  /**< Must be set to true if cell_reselect_hysteresis is being passed */
  uint8_t cell_reselect_hysteresis;
  /**<   Hysteresis for cell reselection used in the calculation of C2 parameter. 
       Refer to \hyperref[STD-45008]{3GPP TS 45.008} Chapter 9.
  */

  /* Optional */
  /*  MS Tx Pwr Max CCH */
  uint8_t ms_txpwr_max_cch_valid;  /**< Must be set to true if ms_txpwr_max_cch is being passed */
  uint8_t ms_txpwr_max_cch;
  /**<   Maximum Tx power level that a mobile station can use when accessing the system.       
  */

  /* Optional */
  /*  Temporary Offset */
  uint8_t temporary_offset_valid;  /**< Must be set to true if temporary_offset is being passed */
  uint8_t temporary_offset;
  /**<   Temporary offset used in the calculation of C2 parameter. 
       Refer to \hyperref[STD-45008]{3GPP TS 45.008} Chapter 9.
  */

  /* Optional */
  /*  Penalty Time */
  uint8_t penalty_time_valid;  /**< Must be set to true if penalty_time is being passed */
  uint8_t penalty_time;
  /**<   Penalty time used in the calculation of C2 parameter. 
       Refer to \hyperref[STD-45008]{3GPP TS 45.008} Chapter 9.
  */
}nas_gcell_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Allows apps to bar the specified GERAN cell for a specific time. */
typedef struct {

  /* Mandatory */
  /*  GERAN Cell Information */
  geran_grr_gcell_identifier_s_v01 uid_camped_cell;

  /* Mandatory */
  /*  Bar Time */
  uint32_t bar_time;
  /**<   Time (in minutes) for which the GERAN cell is to be barred.
  */
}nas_bar_gcell_req_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Allows apps to bar the specified GERAN cell for a specific time. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_bar_gcell_resp_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Tells the modem to abort any ongoing network scan. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_abort_scan_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Tells the modem to abort any ongoing network scan. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_abort_scan_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates the aggregated CA DL bandwidth information. (Deprecated) */
typedef struct {

  /* Optional */
  /*  Aggregated DL Bandwidth */
  uint8_t cphy_ca_aggregated_dl_bandwidth_valid;  /**< Must be set to true if cphy_ca_aggregated_dl_bandwidth is being passed */
  uint16_t cphy_ca_aggregated_dl_bandwidth;
  /**<   Aggregated DL bandwidth. \n
       Units: MHz
  */

  /* Optional */
  /*  Number of Scells Configured */
  uint8_t num_scells_configured_valid;  /**< Must be set to true if num_scells_configured is being passed */
  uint16_t num_scells_configured;
  /**<   Number of Scells configured.
  */
}nas_lte_cphy_ca_agg_dl_bw_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t phy_cell_id;
  /**<   Physical cell ID. */

  nas_active_band_enum_v01 band;
  /**<   LTE band. */

  uint16_t lte_dl_earfcn;
  /**<   LTE downlink frequency. */

  uint16_t lte_ul_earfcn;
  /**<   LTE uplink frequency. */
}nas_lte_rach_fail_ind_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates the LTE connection failure due to RACH failure. */
typedef struct {

  /* Mandatory */
  /*  RACH Failure Information */
  nas_lte_rach_fail_ind_type_v01 lte_rach_fail;
  /**<   RACH failure payload. \n
       If the frequency fields are non-zero, they are the true frequency; if they are zero,
       the true frequency may be found in the 'RACH Failure Extended Downlink Frequency' or
       'RACH Failure Extended Uplink Frequency' TLVs. The 'RACH Failure Extended Downlink Frequency'
       and 'RACH Failure Extended Uplink Frequency' TLVs always hold the true frequency and
       can always be used regardless of the value in the frequency fields of this TLV.
  */

  /* Optional */
  /*  RACH Failure Extended Downlink Frequency */
  uint8_t lte_rach_fail_dl_earfcn_valid;  /**< Must be set to true if lte_rach_fail_dl_earfcn is being passed */
  uint32_t lte_rach_fail_dl_earfcn;
  /**<   RACH failure downlink frequency - extended size \n
       This TLV should be used in place of the downlink frequency field from the 'RACH Failure Information' TLV
  */

  /* Optional */
  /*  RACH Failure Extended Uplink Frequency */
  uint8_t lte_rach_fail_ul_earfcn_valid;  /**< Must be set to true if lte_rach_fail_ul_earfcn is being passed */
  uint32_t lte_rach_fail_ul_earfcn;
  /**<   RACH failure uplink frequency - extended size \n
       This TLV should be used in place of the uplink frequency field from the 'RACH Failure Information' TLV
  */
}nas_lte_rach_fail_ind_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Dynamically enables or disables LTE enhanced cell ID (ECID)
               measurements. */
typedef struct {

  /* Optional */
  /*  ECID Measurement Status */
  uint8_t ecid_is_enabled_valid;  /**< Must be set to true if ecid_is_enabled is being passed */
  uint8_t ecid_is_enabled;
  /**<   Whether ECID measurement is enabled or disabled. Values: \n
       - TRUE -- Enabled \n
       - FALSE -- Disabled
  */
}nas_set_ecid_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Dynamically enables or disables LTE enhanced cell ID (ECID)
               measurements. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_ecid_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the LTE ECID measurement configuration. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_ecid_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the LTE ECID measurement configuration. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  ECID Measurement Configuration */
  uint8_t ecid_is_enabled_valid;  /**< Must be set to true if ecid_is_enabled is being passed */
  uint8_t ecid_is_enabled;
  /**<   ECID measurement configuration. Values: \n
       - TRUE -- Enabled \n
       - FALSE -- Disabled
  */
}nas_get_ecid_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets the V2X status for the device. */
typedef struct {

  /* Optional */
  /*  V2X Start Concurrent with WWAN */
  uint8_t concurrent_with_WWAN_valid;  /**< Must be set to true if concurrent_with_WWAN is being passed */
  uint8_t concurrent_with_WWAN;
  /**<   Configures V2X concurrent with WWAN mode. Values: \n
       - FALSE -- Non_concurrent with WWAN (default value) \n
       - TRUE -- Concurrent with WWAN
  */
}nas_v2x_start_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets the V2X status for the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */
}nas_v2x_start_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sets the V2X status for the device. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_v2x_stop_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sets the V2X status for the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */
}nas_v2x_stop_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  nas_v2x_status_e_type_v01 status;
  /**<   V2X Status. Values: 
      - NAS_V2X_STATUS_INACTIVE (0) --  V2X Status is Inactive \n  
      - NAS_V2X_STATUS_ACTIVE (1) --  V2X Status is Active \n  
      - NAS_V2X_STATUS_SUSPENDED (2) --  V2X Status is Suspended 
 */

  nas_v2x_cause_e_type_v01 cause;
  /**<   V2X Cause. Values: 
      - NAS_V2X_STATUS_CAUSE_TIMING_INVALID (0) --  V2X timing is not valid at the modem \n 
      - NAS_V2X_STATUS_CAUSE_CONFIG_INVALID (1) --  No valid V2X configuration at the modem \n 
      - NAS_V2X_STATUS_CAUSE_UE_MODE_INVALID (2) --  V2X is not supported in current UE mode \n 
      - NAS_V2X_STATUS_CAUSE_OUT_OF_ALLOWED_GEOPOLYGON (3) --  V2X is not supported in current UE location   
 */
}nas_v2x_multi_pool_status_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Gets the V2X status for the device. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_v2x_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Gets the V2X status for the device. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:
     - qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE \n
     - qmi_error_type  -- Error code. Possible error code values are described in
                          the error codes section of each message definition.
  */

  /* Optional */
  /*  V2X Tx Status */
  uint8_t tx_status_valid;  /**< Must be set to true if tx_status is being passed */
  nas_v2x_status_e_type_v01 tx_status;
  /**<   V2X Tx Status. Values: 
      - NAS_V2X_STATUS_INACTIVE (0) --  V2X Status is Inactive \n  
      - NAS_V2X_STATUS_ACTIVE (1) --  V2X Status is Active \n  
      - NAS_V2X_STATUS_SUSPENDED (2) --  V2X Status is Suspended 
 */

  /* Optional */
  /*  V2X Rx Status */
  uint8_t rx_status_valid;  /**< Must be set to true if rx_status is being passed */
  nas_v2x_status_e_type_v01 rx_status;
  /**<   V2X Rx Status. Values: 
      - NAS_V2X_STATUS_INACTIVE (0) --  V2X Status is Inactive \n  
      - NAS_V2X_STATUS_ACTIVE (1) --  V2X Status is Active \n  
      - NAS_V2X_STATUS_SUSPENDED (2) --  V2X Status is Suspended 
 */

  /* Optional */
  /*  V2X Tx Multi Pool Status */
  uint8_t tx_multi_pool_status_valid;  /**< Must be set to true if tx_multi_pool_status is being passed */
  uint32_t tx_multi_pool_status_len;  /**< Must be set to # of elements in tx_multi_pool_status */
  nas_v2x_multi_pool_status_type_v01 tx_multi_pool_status[NAS_V2X_RRC_MAX_TX_POOL_LIST_V01];
  /**<   
    V2X Tx Multi Pool Status
  */

  /* Optional */
  /*  V2X Rx Multi Pool Status */
  uint8_t rx_multi_pool_status_valid;  /**< Must be set to true if rx_multi_pool_status is being passed */
  uint32_t rx_multi_pool_status_len;  /**< Must be set to # of elements in rx_multi_pool_status */
  nas_v2x_multi_pool_status_type_v01 rx_multi_pool_status[NAS_V2X_RRC_MAX_RX_POOL_LIST_V01];
  /**<   
    V2X Rx Multi Pool Status    
    */
}nas_get_v2x_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates the V2X notification for the device. */
typedef struct {

  /* Optional */
  /*  V2X Tx Status */
  uint8_t tx_status_valid;  /**< Must be set to true if tx_status is being passed */
  nas_v2x_status_e_type_v01 tx_status;
  /**<   
 V2X Tx Status. Values: 
      - NAS_V2X_STATUS_INACTIVE (0) --  V2X Status is Inactive \n  
      - NAS_V2X_STATUS_ACTIVE (1) --  V2X Status is Active \n  
      - NAS_V2X_STATUS_SUSPENDED (2) --  V2X Status is Suspended 
 */

  /* Optional */
  /*  V2X Rx Status */
  uint8_t rx_status_valid;  /**< Must be set to true if rx_status is being passed */
  nas_v2x_status_e_type_v01 rx_status;
  /**<   
 V2X Rx Status. Values: 
      - NAS_V2X_STATUS_INACTIVE (0) --  V2X Status is Inactive \n  
      - NAS_V2X_STATUS_ACTIVE (1) --  V2X Status is Active \n  
      - NAS_V2X_STATUS_SUSPENDED (2) --  V2X Status is Suspended 
 */

  /* Optional */
  /*  V2X Tx Cause */
  uint8_t tx_cause_valid;  /**< Must be set to true if tx_cause is being passed */
  nas_v2x_cause_e_type_v01 tx_cause;
  /**<   
 V2X Tx Cause. Values: 
      - NAS_V2X_STATUS_CAUSE_TIMING_INVALID (0) --  V2X timing is not valid at the modem \n 
      - NAS_V2X_STATUS_CAUSE_CONFIG_INVALID (1) --  No valid V2X configuration at the modem \n 
      - NAS_V2X_STATUS_CAUSE_UE_MODE_INVALID (2) --  V2X is not supported in current UE mode \n 
      - NAS_V2X_STATUS_CAUSE_OUT_OF_ALLOWED_GEOPOLYGON (3) --  V2X is not supported in current UE location   
 */

  /* Optional */
  /*  V2X Rx Cause */
  uint8_t rx_cause_valid;  /**< Must be set to true if rx_cause is being passed */
  nas_v2x_cause_e_type_v01 rx_cause;
  /**<   
 V2X Rx Cause. Values: 
      - NAS_V2X_STATUS_CAUSE_TIMING_INVALID (0) --  V2X timing is not valid at the modem \n 
      - NAS_V2X_STATUS_CAUSE_CONFIG_INVALID (1) --  No valid V2X configuration at the modem \n 
      - NAS_V2X_STATUS_CAUSE_UE_MODE_INVALID (2) --  V2X is not supported in current UE mode \n 
      - NAS_V2X_STATUS_CAUSE_OUT_OF_ALLOWED_GEOPOLYGON (3) --  V2X is not supported in current UE location   
 */

  /* Optional */
  /*  V2X Channel Busy Ratio (CBR) */
  uint8_t cbr_value_valid;  /**< Must be set to true if cbr_value is being passed */
  uint8_t cbr_value;
  /**<  
    V2X channel busy ratio (CBR). CBR values are expressed as a percentage (e.g., CBR*100).
   */

  /* Optional */
  /*  V2X Tx Multi Pool Status */
  uint8_t tx_multi_pool_status_valid;  /**< Must be set to true if tx_multi_pool_status is being passed */
  uint32_t tx_multi_pool_status_len;  /**< Must be set to # of elements in tx_multi_pool_status */
  nas_v2x_multi_pool_status_type_v01 tx_multi_pool_status[NAS_V2X_RRC_MAX_TX_POOL_LIST_V01];
  /**<   
    V2X Tx Multi Pool Status
  */

  /* Optional */
  /*  V2X Rx Multi Pool Status */
  uint8_t rx_multi_pool_status_valid;  /**< Must be set to true if rx_multi_pool_status is being passed */
  uint32_t rx_multi_pool_status_len;  /**< Must be set to # of elements in rx_multi_pool_status */
  nas_v2x_multi_pool_status_type_v01 rx_multi_pool_status[NAS_V2X_RRC_MAX_RX_POOL_LIST_V01];
  /**<   
    V2X Rx Multi Pool Status    
  */

  /* Optional */
  /*  V2X Channel Busy Ratio (CBR) */
  uint8_t cbr_multi_pool_value_valid;  /**< Must be set to true if cbr_multi_pool_value is being passed */
  uint32_t cbr_multi_pool_value_len;  /**< Must be set to # of elements in cbr_multi_pool_value */
  uint8_t cbr_multi_pool_value[NAS_V2X_RRC_MAX_RX_POOL_LIST_V01];
  /**<  
    V2X channel busy ratio (CBR). 
	CBR values are expressed as a percentage (e.g., CBR*100).
  */

  /* Optional */
  /*  V2X Time Uncertainty */
  uint8_t time_uncertainty_valid;  /**< Must be set to true if time_uncertainty is being passed */
  float time_uncertainty;
  /**<  
    V2X Time_uncertainity in milliseconds
  */
}nas_v2x_notification_ind_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Informs whether the subscription is blocked. */
typedef struct {

  /* Mandatory */
  /*  Blocked Status */
  uint8_t is_blocked;
  /**<    Subscription blocked status.\n
  */
}nas_sub_blocked_status_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the current blocked status of the subscription. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_sub_blocked_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the current blocked status of the subscription. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  Blocked Status */
  uint8_t is_blocked_valid;  /**< Must be set to true if is_blocked is being passed */
  uint8_t is_blocked;
  /**<    Subscription blocked status.\n
  */
}nas_get_sub_blocked_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  LTE_B2_THRESHOLD_ADJ_CONFIG_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QMI_NAS_LTE_B2_THRESH_ADJ_DISABLE_V01 = 0x01, 
  QMI_NAS_LTE_B2_THRESH_ADJ_IF_EFS_PRESENT_V01 = 0x02, 
  QMI_NAS_LTE_B2_THRESH_ADJ_DISABLE_AND_UPDATE_EFS_V01 = 0x09, 
  QMI_NAS_LTE_B2_THRESH_ADJ_UPDATE_EFS_V01 = 0x0A, 
  LTE_B2_THRESHOLD_ADJ_CONFIG_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}lte_b2_threshold_adj_config_type_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  int32_t rsrq_thresh;

  int32_t rsrp_thresh;

  int32_t thresh1_adj;
}nas_lte_b2_thresh_adj_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Configures the modem with B2-adjusted threshold values. */
typedef struct {

  /* Mandatory */
  /*  LTE B2 Threshold Adjustment Info Type */
  lte_b2_threshold_adj_config_type_v01 config_type;
  /**<   
  Configuration type for the B2 threshold NV online update. Values: \n
  - QMI_NAS_LTE_B2_THRESH_ADJ_DISABLE (0x01) -- Disable threshold adjust if enabled by EFS or online update. The 
          updated value is not written to the EFS file. \n
  - QMI_NAS_LTE_B2_THRESH_ADJ_IF_EFS_PRESENT (0x02) -- Online updates of the threshold adjust only if the EFS file is present on the device and is read during bootup. 
          The updated value is not written to the EFS file. \n
  - QMI_NAS_LTE_B2_THRESH_ADJ_DISABLE_AND_UPDATE_EFS (0x09) -- Disable threshold adjust if enabled by the EFS or online update and write to the EFS file during LTE stop or power off.
          The updated value is picked on the next bootup. \n
  - QMI_NAS_LTE_B2_THRESH_ADJ_UPDATE_EFS (0x0A) -- Online updates of the threshold adjust only if the EFS file is present and write to the EFS file during LTE stop or power off. 
          The updated value is picked on the next bootup.
  */

  /* Optional */
  /*  LTE B2 Threshold Adjustment Info */
  uint8_t lte_b2_thresh_adj_info_valid;  /**< Must be set to true if lte_b2_thresh_adj_info is being passed */
  nas_lte_b2_thresh_adj_info_type_v01 lte_b2_thresh_adj_info;
}nas_lte_b2_thresh_adj_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_enums
    @{
  */
typedef enum {
  CONFIG_RSP_E_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  CONFIG_ERROR_UPDATE_REJECT_NO_EFS_V01 = 1, 
  CONFIG_ERROR_EFS_WRITE_REJECT_NO_EFS_V01 = 2, 
  CONFIG_INVALID_V01 = 3, 
  CONFIG_RSP_E_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}config_rsp_e_v01;
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Configures the modem with B2-adjusted threshold values. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  Config Response */
  uint8_t config_rsp_valid;  /**< Must be set to true if config_rsp is being passed */
  config_rsp_e_v01 config_rsp;
  /**<   
  - CONFIG_ERROR_UPDATE_ REJECT_NO_EFS (1) -- Update rejected because no EFS is on the phone. \n
  - CONFIG_ERROR_EFS_WRITE_REJECT_NO_EFS (2) -- Unable to write to the EFS file. \n
  - CONFIG_INVALID (3) --  Invalid configuration.
  */
}nas_lte_b2_thresh_adj_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Retrieves the current RATs related ARFCN list. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_arfcn_list_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  /*  ARFCN */
  uint16_t arfcn;
  /**<   Absolute RF channel number.
  */

  nas_active_band_enum_v01 band;
  /**<   Band indicator for the ARFCN provided. */
}nas_arfcn_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t downlink_only;
  /**<   Indicate LTE Cell direction. 
  * TRUE = Downlink only, FALSE = Downlink + Uplink */

  /*  ARFCN */
  uint32_t dl_earfcn;
  /**<   EUTRAN Absolute RF channel number.
  */

  /*  ARFCN */
  uint32_t ul_earfcn;
  /**<   EUTRAN Absolute RF channel number.
  */

  nas_lte_cphy_ca_bandwidth_enum_v01 bandwidth;
  /**<   Band indicator for the ARFCN provided. */
}nas_lte_earfcn_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Retrieves the current RATs related ARFCN list. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  GERAN Serving Cell ARFCN */
  uint8_t geran_scell_arfcn_valid;  /**< Must be set to true if geran_scell_arfcn is being passed */
  nas_arfcn_type_v01 geran_scell_arfcn;

  /* Optional */
  /*  Neighbor Cell ARFCN List */
  uint8_t geran_nbr_arfcn_valid;  /**< Must be set to true if geran_nbr_arfcn is being passed */
  uint32_t geran_nbr_arfcn_len;  /**< Must be set to # of elements in geran_nbr_arfcn */
  nas_arfcn_type_v01 geran_nbr_arfcn[NAS_MAX_NBR_ARFCN_LIST_V01];

  /* Optional */
  /*  Hopping Cell ARFCN List */
  uint8_t geran_hopping_arfcn_valid;  /**< Must be set to true if geran_hopping_arfcn is being passed */
  uint32_t geran_hopping_arfcn_len;  /**< Must be set to # of elements in geran_hopping_arfcn */
  nas_arfcn_type_v01 geran_hopping_arfcn[NAS_MAX_HOPPING_ARFCN_LIST_V01];

  /* Optional */
  /*  Dedicated PDCH ARFCN */
  uint8_t geran_dedicated_or_pdch_arfcn_valid;  /**< Must be set to true if geran_dedicated_or_pdch_arfcn is being passed */
  nas_arfcn_type_v01 geran_dedicated_or_pdch_arfcn;

  /* Optional */
  /*  WCDMA Serving Cell UARFCN */
  uint8_t wcdma_scell_uarfcn_valid;  /**< Must be set to true if wcdma_scell_uarfcn is being passed */
  uint16_t wcdma_scell_uarfcn;
  /**<   WCDMA Serving Cell UARFCN */

  /* Optional */
  /*  WCDMA Secondary Cell UARFCN */
  uint8_t wcdma_secondary_uarfcn_valid;  /**< Must be set to true if wcdma_secondary_uarfcn is being passed */
  uint16_t wcdma_secondary_uarfcn;
  /**<   WCDMA Secondary Cell UARFCN */

  /* Optional */
  /*  WCDMA RRC State */
  uint8_t wcdma_rrc_state_valid;  /**< Must be set to true if wcdma_rrc_state is being passed */
  nas_wcdma_rrc_state_enum_v01 wcdma_rrc_state;
  /**<   WCDMA RRC State */

  /* Optional */
  /*  WCDMA Inter Frequency Neighbor List UARFCNs */
  uint8_t wcdma_nbr_uarfcn_valid;  /**< Must be set to true if wcdma_nbr_uarfcn is being passed */
  uint32_t wcdma_nbr_uarfcn_len;  /**< Must be set to # of elements in wcdma_nbr_uarfcn */
  uint16_t wcdma_nbr_uarfcn[NAS_MAX_WCDMA_NBR_UARFCN_LIST_V01];

  /* Optional */
  /*  LTE Serving and Secondary Cells Information */
  uint8_t lte_scell_earfcn_valid;  /**< Must be set to true if lte_scell_earfcn is being passed */
  uint32_t lte_scell_earfcn_len;  /**< Must be set to # of elements in lte_scell_earfcn */
  nas_lte_earfcn_type_v01 lte_scell_earfcn[NAS_MAX_LTE_SERVING_CELL_V01];

  /* Optional */
  /*  LTE RRC State */
  uint8_t lte_rrc_state_valid;  /**< Must be set to true if lte_rrc_state is being passed */
  lte_rrc_state_ext_e_type_v01 lte_rrc_state;
  /**<   LTE RRC State */

  /* Optional */
  /*  LTE Inter Frequency Neighbor List */
  uint8_t lte_nbr_earfcn_valid;  /**< Must be set to true if lte_nbr_earfcn is being passed */
  uint32_t lte_nbr_earfcn_len;  /**< Must be set to # of elements in lte_nbr_earfcn */
  nas_lte_earfcn_type_v01 lte_nbr_earfcn[NAS_MAX_NBR_ARFCN_LIST_V01];
}nas_get_arfcn_list_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates the current RATs related ARFCN list. */
typedef struct {

  /* Optional */
  /*  GERAN Serving Cell ARFCN */
  uint8_t geran_scell_arfcn_valid;  /**< Must be set to true if geran_scell_arfcn is being passed */
  nas_arfcn_type_v01 geran_scell_arfcn;

  /* Optional */
  /*  Neighbor cell ARFCN List */
  uint8_t geran_nbr_arfcn_valid;  /**< Must be set to true if geran_nbr_arfcn is being passed */
  uint32_t geran_nbr_arfcn_len;  /**< Must be set to # of elements in geran_nbr_arfcn */
  nas_arfcn_type_v01 geran_nbr_arfcn[NAS_MAX_NBR_ARFCN_LIST_V01];

  /* Optional */
  /*  Hopping Cell ARFCN List */
  uint8_t geran_hopping_arfcn_valid;  /**< Must be set to true if geran_hopping_arfcn is being passed */
  uint32_t geran_hopping_arfcn_len;  /**< Must be set to # of elements in geran_hopping_arfcn */
  nas_arfcn_type_v01 geran_hopping_arfcn[NAS_MAX_HOPPING_ARFCN_LIST_V01];

  /* Optional */
  /*  Dedicated PDCH ARFCN */
  uint8_t geran_dedicated_or_pdch_arfcn_valid;  /**< Must be set to true if geran_dedicated_or_pdch_arfcn is being passed */
  nas_arfcn_type_v01 geran_dedicated_or_pdch_arfcn;

  /* Optional */
  /*  WCDMA Serving Cell UARFCN */
  uint8_t wcdma_scell_uarfcn_valid;  /**< Must be set to true if wcdma_scell_uarfcn is being passed */
  uint16_t wcdma_scell_uarfcn;
  /**<   WCDMA Serving Cell UARFCN */

  /* Optional */
  /*  WCDMA Secondary Cell UARFCN */
  uint8_t wcdma_secondary_uarfcn_valid;  /**< Must be set to true if wcdma_secondary_uarfcn is being passed */
  uint16_t wcdma_secondary_uarfcn;
  /**<   WCDMA Secondary Cell UARFCN */

  /* Optional */
  /*  WCDMA RRC State */
  uint8_t wcdma_rrc_state_valid;  /**< Must be set to true if wcdma_rrc_state is being passed */
  nas_wcdma_rrc_state_enum_v01 wcdma_rrc_state;
  /**<   WCDMA RRC State  */

  /* Optional */
  /*  WCDMA Inter Frequency Neighbor List UARFCNs */
  uint8_t wcdma_nbr_uarfcn_valid;  /**< Must be set to true if wcdma_nbr_uarfcn is being passed */
  uint32_t wcdma_nbr_uarfcn_len;  /**< Must be set to # of elements in wcdma_nbr_uarfcn */
  uint16_t wcdma_nbr_uarfcn[NAS_MAX_WCDMA_NBR_UARFCN_LIST_V01];
  /**<   WCDMA Inter Frequency Neighbor List UARFCNs */

  /* Optional */
  /*  LTE Serving and Secondary Cells Information */
  uint8_t lte_scell_earfcn_valid;  /**< Must be set to true if lte_scell_earfcn is being passed */
  uint32_t lte_scell_earfcn_len;  /**< Must be set to # of elements in lte_scell_earfcn */
  nas_lte_earfcn_type_v01 lte_scell_earfcn[NAS_MAX_LTE_SERVING_CELL_V01];
  /**<   LTE Serving and Secondary Cells Information */

  /* Optional */
  /*  LTE RRC State */
  uint8_t lte_rrc_state_valid;  /**< Must be set to true if lte_rrc_state is being passed */
  lte_rrc_state_ext_e_type_v01 lte_rrc_state;
  /**<   LTE RRC State */

  /* Optional */
  /*  LTE Inter Frequency Neighbor List */
  uint8_t lte_nbr_earfcn_valid;  /**< Must be set to true if lte_nbr_earfcn is being passed */
  uint32_t lte_nbr_earfcn_len;  /**< Must be set to # of elements in lte_nbr_earfcn */
  nas_lte_earfcn_type_v01 lte_nbr_earfcn[NAS_MAX_NBR_ARFCN_LIST_V01];
}nas_arfcn_list_ind_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indication to vote for powering up/down of the 5G modem. */
typedef struct {

  /* Mandatory */
  /*  Vote to Power up/down 5G Modem */
  uint8_t vote_ind_for_5g_modem;
  /**<   
        Values: \n
        0x00 - Power down
		0x01 - Power up
    */
}nas_5g_modem_vote_ind_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Queries the RF availability.  */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_rf_availability_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Queries the RF availability.  */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type.*/

  /* Optional */
  /*  3GPP RF Availability */
  uint8_t gpp_rf_available_valid;  /**< Must be set to true if gpp_rf_available is being passed */
  uint8_t gpp_rf_available;
  /**<   Values: \n
       - TRUE  -- 3GPP RF available \n
       - FALSE -- 3GPP RF not available
  */
}nas_get_rf_availability_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Reports the RF availability. */
typedef struct {

  /* Mandatory */
  /*  3GPP RF Availability */
  uint8_t gpp_rf_available;
  /**<   Values: \n
       - TRUE  -- 3GPP RF available \n
       - FALSE -- 3GPP RF not available
  */
}nas_rf_availability_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Queries the cell list on which the service 
              acquisition is limited only to the listed cells. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_cell_lock_config_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Queries the cell list on which the service 
              acquisition is limited only to the listed cells. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  Cell List */
  uint8_t cell_list_valid;  /**< Must be set to true if cell_list is being passed */
  uint32_t cell_list_len;  /**< Must be set to # of elements in cell_list */
  nas_cell_lock_entry_type_v01 cell_list[NAS_MAX_CELL_LOCK_ENTRIES_V01];
}nas_get_cell_lock_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Sends the small bw earfcns to LTE to avoid reselections to the corresponding bands. */
typedef struct {

  /* Optional */
  /*  small bandwidth earfcn  */
  uint8_t small_bw_earfcn_valid;  /**< Must be set to true if small_bw_earfcn is being passed */
  uint32_t small_bw_earfcn_len;  /**< Must be set to # of elements in small_bw_earfcn */
  uint32_t small_bw_earfcn[NAS_SMALL_BW_EARFCN_MAX_V01];
  /**<   Contains the small bw earfcns. 
       A set message without this TLV will be treated as a reset request.
   */
}nas_set_small_bw_earfcn_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Sends the small bw earfcns to LTE to avoid reselections to the corresponding bands. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_small_bw_earfcn_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Gets the configured small bw earfcns. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_get_small_bw_earfcn_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Gets the configured small bw earfcns. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */

  /* Optional */
  /*  small bandwidth earfcns  */
  uint8_t small_bw_earfcn_valid;  /**< Must be set to true if small_bw_earfcn is being passed */
  uint32_t small_bw_earfcn_len;  /**< Must be set to # of elements in small_bw_earfcn */
  uint32_t small_bw_earfcn[NAS_SMALL_BW_EARFCN_MAX_V01];
  /**<   Contains the small bw earfcns
   */
}nas_get_small_bw_earfcn_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Forces scan procedure to acquire LTE. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}nas_force_lte_scan_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Forces scan procedure to acquire LTE. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type.*/
}nas_force_lte_scan_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Blocks the NR5G PLMN. */
typedef struct {

  /* Mandatory */
  /*  PLMN */
  nas_plmn_id_ext_type_v01 plmn;

  /* Optional */
  /*  Blocking Interval Absolute Time */
  uint8_t blocking_interval_abs_valid;  /**< Must be set to true if blocking_interval_abs is being passed */
  uint32_t blocking_interval_abs;
  /**<   Blocking interval in absolute time (in milliseconds).
  */

  /* Optional */
  /*  Blocking Interval T3502 Multiplier */
  uint8_t blocking_interval_mult_valid;  /**< Must be set to true if blocking_interval_mult is being passed */
  float blocking_interval_mult;
  /**<   Blocking time as a multiplier of T3502.
  */

  /* Optional */
  /*  Blocking Cause */
  uint8_t blocking_cause_valid;  /**< Must be set to true if blocking_cause is being passed */
  nas_block_plmn_cause_e_type_v01 blocking_cause;
  /**<   
 PLMN Blocking Cause: \n
      - NAS_BLOCK_PLMN_CAUSE_OTHERS (0) -- 
      - NAS_BLOCK_PLMN_CAUSE_CALL_REDIAL (1) -- 
 */
}nas_block_nr5g_plmn_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Blocks the NR5G PLMN. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_block_nr5g_plmn_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Unblocks the NR5G PLMN. */
typedef struct {

  /* Mandatory */
  /*  PLMN */
  nas_plmn_id_ext_type_v01 plmn;

  /* Optional */
  /*  Blocking Cause */
  uint8_t blocking_cause_valid;  /**< Must be set to true if blocking_cause is being passed */
  nas_block_plmn_cause_e_type_v01 blocking_cause;
  /**<   
 PLMN Blocking Cause: \n
      - NAS_BLOCK_PLMN_CAUSE_OTHERS (0) -- 
      - NAS_BLOCK_PLMN_CAUSE_CALL_REDIAL (1) -- 
 */
}nas_unblock_nr5g_plmn_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Unblocks the NR5G PLMN. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_unblock_nr5g_plmn_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Resets all previous NR5G PLMN blocking operations. */
typedef struct {

  /* Optional */
  /*  Blocking Cause */
  uint8_t blocking_cause_valid;  /**< Must be set to true if blocking_cause is being passed */
  nas_block_plmn_cause_e_type_v01 blocking_cause;
  /**<   
 PLMN Blocking Cause: \n
      - NAS_BLOCK_PLMN_CAUSE_OTHERS (0) -- 
      - NAS_BLOCK_PLMN_CAUSE_CALL_REDIAL (1) -- 
 */
}nas_reset_nr5g_plmn_blocking_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Resets all previous NR5G PLMN blocking operations. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_reset_nr5g_plmn_blocking_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Indication Message; Indicates a change in the T3502 timer value. */
typedef struct {

  /* Optional */
  /*  T3502 Timer Value */
  uint8_t t3502_timer_val_valid;  /**< Must be set to true if t3502_timer_val is being passed */
  uint32_t t3502_timer_val;
  /**<   T3502 timer value (in milliseconds).
  */
}nas_mm5g_t3502_changed_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Request Message; Indicates the current IMS procedure type so the modem can prioritize
               RF resources to accommodate the procedure. */
typedef struct {

  /* Mandatory */
  /*  Procedure Type */
  nas_proc_type_e_type_v01 proc_type;
  /**<   IMS procedure type. Values: \n
      - NAS_PROC_TYPE_NONE (0) --  No procedure type \n 
      - NAS_PROC_TYPE_VOLTE_CALL (1) --  VoLTE call (Deprecated, use VOIMS_CALL) \n 
      - NAS_PROC_TYPE_IMS_SMS (2) --  IMS-based SMS \n 
      - NAS_PROC_TYPE_IMS_MMS (3) --  IMS-based MMS \n 
      - NAS_PROC_TYPE_IMS_REGISTRATION (4) --  IMS registration \n 
      - NAS_PROC_TYPE_IMS_UT (5) --  IMS UT service 
      - NAS_PROC_TYPE_VOIMS_CALL (6) --  IMS-based voice or VT call \n 
 */
}nas_set_ims_proc_type_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup nas_qmi_messages
    @{
  */
/** Response Message; Indicates the current IMS procedure type so the modem can prioritize
               RF resources to accommodate the procedure. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. */
}nas_set_ims_proc_type_resp_msg_v01;  /* Message */
/**
    @}
  */

/* Conditional compilation tags for message removal */ 
//#define REMOVE_QMI_NAS_5G_MODEM_VOTE_IND_V01 
//#define REMOVE_QMI_NAS_ABORT_V01 
//#define REMOVE_QMI_NAS_ABORT_SCAN_V01 
//#define REMOVE_QMI_NAS_ARFCN_LIST_IND_V01 
//#define REMOVE_QMI_NAS_AVOID_TUNEAWAY_V01 
//#define REMOVE_QMI_NAS_BAR_GCELL_V01 
//#define REMOVE_QMI_NAS_BIND_SUBSCRIPTION_V01 
//#define REMOVE_QMI_NAS_BLOCK_LTE_PLMN_V01 
//#define REMOVE_QMI_NAS_BLOCK_NR5G_PLMN_V01 
//#define REMOVE_QMI_NAS_CDMA_AVOID_SYSTEM_V01 
//#define REMOVE_QMI_NAS_CONFIG_EMBMS_V01 
//#define REMOVE_QMI_NAS_CONFIG_PLMN_NAME_IND_REPORTING_V01 
//#define REMOVE_QMI_NAS_CONFIG_SIG_INFO_V01 
//#define REMOVE_QMI_NAS_CONFIG_SIG_INFO2_V01 
//#define REMOVE_QMI_NAS_CSG_IMMEDIATE_SEARCH_SELECTION_V01 
//#define REMOVE_QMI_NAS_CSG_SEARCH_SELECTION_CONFIG_V01 
//#define REMOVE_QMI_NAS_CSP_PLMN_MODE_BIT_IND_V01 
//#define REMOVE_QMI_NAS_CURRENT_PLMN_NAME_IND_V01 
//#define REMOVE_QMI_NAS_DATA_SUBS_PRIORITY_IND_V01 
//#define REMOVE_QMI_NAS_DDTM_V01 
//#define REMOVE_QMI_NAS_DETACH_LTE_V01 
//#define REMOVE_QMI_NAS_DUAL_STANDBY_PREF_IND_V01 
//#define REMOVE_QMI_NAS_ECALL_DEREGISTRATION_V01 
//#define REMOVE_QMI_NAS_ECALL_TIMER_RESTART_MSG_V01 
//#define REMOVE_QMI_NAS_EDRX_CHANGE_INFO_IND_V01 
//#define REMOVE_QMI_NAS_EMBMS_STATUS_IND_V01 
//#define REMOVE_QMI_NAS_EMERGENCY_MODE_STATUS_IND_V01 
//#define REMOVE_QMI_NAS_EMM_T3402_CHANGED_IND_V01 
//#define REMOVE_QMI_NAS_ERR_RATE_IND_V01 
//#define REMOVE_QMI_NAS_EVENT_REPORT_IND_V01 
//#define REMOVE_QMI_NAS_FORCE_LTE_SCAN_V01 
//#define REMOVE_QMI_NAS_FORCE_NETWORK_SEARCH_V01 
//#define REMOVE_QMI_NAS_GCELL_INFO_V01 
//#define REMOVE_QMI_NAS_GCELL_INFO_IND_V01 
//#define REMOVE_QMI_NAS_GET_3GPP2_SUBSCRIPTION_INFO_V01 
//#define REMOVE_QMI_NAS_GET_ACB_INFO_V01 
//#define REMOVE_QMI_NAS_GET_ACCOLC_V01 
//#define REMOVE_QMI_NAS_GET_AN_AAA_STATUS_V01 
//#define REMOVE_QMI_NAS_GET_ARFCN_LIST_V01 
//#define REMOVE_QMI_NAS_GET_BSR_TIMER_V01 
//#define REMOVE_QMI_NAS_GET_CA_BAND_COMBO_MSG_V01 
//#define REMOVE_QMI_NAS_GET_CDMA_AVOID_SYSTEM_LIST_V01 
//#define REMOVE_QMI_NAS_GET_CDMA_POSITION_INFO_V01 
//#define REMOVE_QMI_NAS_GET_CELL_LOCATION_INFO_V01 
//#define REMOVE_QMI_NAS_GET_CELL_LOCK_CONFIG_V01 
//#define REMOVE_QMI_NAS_GET_CENTRALIZED_EONS_SUPPORT_STATUS_V01 
//#define REMOVE_QMI_NAS_GET_CSG_SEARCH_SELECTION_CONFIGURATION_V01 
//#define REMOVE_QMI_NAS_GET_CSP_PLMN_MODE_BIT_V01 
//#define REMOVE_QMI_NAS_GET_CURRENT_ACQ_SYS_MODE_V01 
//#define REMOVE_QMI_NAS_GET_DATA_ROAMING_V01 
//#define REMOVE_QMI_NAS_GET_DATA_SUBS_PRIORITY_V01 
//#define REMOVE_QMI_NAS_GET_DEVICE_CONFIG_V01 
//#define REMOVE_QMI_NAS_GET_DRX_V01 
//#define REMOVE_QMI_NAS_GET_DUAL_STANDBY_PREF_V01 
//#define REMOVE_QMI_NAS_GET_ECID_CONFIG_V01 
//#define REMOVE_QMI_NAS_GET_EDRX_V01 
//#define REMOVE_QMI_NAS_GET_EDRX_PARAMS_V01 
//#define REMOVE_QMI_NAS_GET_EMBMS_SIG_V01 
//#define REMOVE_QMI_NAS_GET_EMBMS_SIG_EXT_V01 
//#define REMOVE_QMI_NAS_GET_EMBMS_STATUS_V01 
//#define REMOVE_QMI_NAS_GET_ERR_RATE_V01 
//#define REMOVE_QMI_NAS_GET_FORBIDDEN_NETWORKS_V01 
//#define REMOVE_QMI_NAS_GET_HDR_COLOR_CODE_V01 
//#define REMOVE_QMI_NAS_GET_HDR_DRC_RATE_V01 
//#define REMOVE_QMI_NAS_GET_HDR_INFO_V01 
//#define REMOVE_QMI_NAS_GET_HDR_SUBTYPE_V01 
//#define REMOVE_QMI_NAS_GET_HOME_NETWORK_V01 
//#define REMOVE_QMI_NAS_GET_HPLMN_SEARCH_TIMER_V01 
//#define REMOVE_QMI_NAS_GET_IMS_PREF_STATUS_V01 
//#define REMOVE_QMI_NAS_GET_LTE_BAND_PRIORITY_LIST_V01 
//#define REMOVE_QMI_NAS_GET_LTE_CPHY_CA_INFO_V01 
//#define REMOVE_QMI_NAS_GET_LTE_EMBMS_INFO_V01 
//#define REMOVE_QMI_NAS_GET_LTE_RRC_TX_INFO_V01 
//#define REMOVE_QMI_NAS_GET_LTE_SIB16_NETWORK_TIME_V01 
//#define REMOVE_QMI_NAS_GET_MANAGED_ROAMING_CONFIG_V01 
//#define REMOVE_QMI_NAS_GET_MOB_CAI_REV_V01 
//#define REMOVE_QMI_NAS_GET_MODE_PREF_V01 
//#define REMOVE_QMI_NAS_GET_NEGOTIATED_DRX_V01 
//#define REMOVE_QMI_NAS_GET_NETWORK_SYSTEM_PREFERENCE_V01 
//#define REMOVE_QMI_NAS_GET_NETWORK_TIME_V01 
//#define REMOVE_QMI_NAS_GET_OPERATOR_NAME_DATA_V01 
//#define REMOVE_QMI_NAS_GET_PLMN_NAME_V01 
//#define REMOVE_QMI_NAS_GET_PREFERRED_NETWORKS_V01 
//#define REMOVE_QMI_NAS_GET_RF_AVAILABILITY_V01 
//#define REMOVE_QMI_NAS_GET_RF_BAND_INFO_V01 
//#define REMOVE_QMI_NAS_GET_RPM_PARAMETERS_V01 
//#define REMOVE_QMI_NAS_GET_RTRE_CONFIG_V01 
//#define REMOVE_QMI_NAS_GET_SERVING_SYSTEM_V01 
//#define REMOVE_QMI_NAS_GET_SERV_CELL_SIB_V01 
//#define REMOVE_QMI_NAS_GET_SIGNAL_STRENGTH_V01 
//#define REMOVE_QMI_NAS_GET_SIG_INFO_V01 
//#define REMOVE_QMI_NAS_GET_SMALL_BW_EARFCN_V01 
//#define REMOVE_QMI_NAS_GET_SSAC_HYSTERESIS_TIMER_V01 
//#define REMOVE_QMI_NAS_GET_SSAC_INFO_V01 
//#define REMOVE_QMI_NAS_GET_SUBSCRIPTION_INFO_V01 
//#define REMOVE_QMI_NAS_GET_SUB_BLOCKED_STATUS_V01 
//#define REMOVE_QMI_NAS_GET_SUPPORTED_FIELDS_V01 
//#define REMOVE_QMI_NAS_GET_SUPPORTED_MSGS_V01 
//#define REMOVE_QMI_NAS_GET_SYSTEM_SELECTION_PREFERENCE_V01 
//#define REMOVE_QMI_NAS_GET_SYS_INFO_V01 
//#define REMOVE_QMI_NAS_GET_SYS_INFO_IND_REPORTING_LIMIT_V01 
//#define REMOVE_QMI_NAS_GET_TDS_CELL_AND_POSITION_INFO_V01 
//#define REMOVE_QMI_NAS_GET_TECHNOLOGY_PREFERENCE_V01 
//#define REMOVE_QMI_NAS_GET_TX_RX_INFO_V01 
//#define REMOVE_QMI_NAS_GET_V2X_STATUS_V01 
//#define REMOVE_QMI_NAS_GET_VOICE_ROAMING_V01 
//#define REMOVE_QMI_NAS_HDR_SESSION_CLOSE_IND_V01 
//#define REMOVE_QMI_NAS_HDR_UATI_UPDATE_IND_V01 
//#define REMOVE_QMI_NAS_IMS_PREF_STATUS_IND_V01 
//#define REMOVE_QMI_NAS_INDICATION_REGISTER_V01 
//#define REMOVE_QMI_NAS_INITIATE_ATTACH_V01 
//#define REMOVE_QMI_NAS_INITIATE_NETWORK_REGISTER_V01 
//#define REMOVE_QMI_NAS_LIMIT_SYS_INFO_IND_REPORTING_V01 
//#define REMOVE_QMI_NAS_LTE_B2_THRESH_ADJ_CONFIG_V01 
//#define REMOVE_QMI_NAS_LTE_CPHY_CA_AGG_DL_BW_IND_V01 
//#define REMOVE_QMI_NAS_LTE_CPHY_CA_IND_V01 
//#define REMOVE_QMI_NAS_LTE_RACH_FAIL_IND_V01 
//#define REMOVE_QMI_NAS_LTE_RRC_TX_INFO_IND_V01 
//#define REMOVE_QMI_NAS_LTE_SIB16_NETWORK_TIME_IND_V01 
//#define REMOVE_QMI_NAS_LTE_UE_CONFIG_MSG_V01 
//#define REMOVE_QMI_NAS_MANAGED_ROAMING_V01 
//#define REMOVE_QMI_NAS_MANUAL_SCAN_FAIL_IND_V01 
//#define REMOVE_QMI_NAS_MM5G_T3502_CHANGED_IND_V01 
//#define REMOVE_QMI_NAS_NETWORK_REJECT_IND_V01 
//#define REMOVE_QMI_NAS_NETWORK_TIME_IND_V01 
//#define REMOVE_QMI_NAS_OPERATOR_NAME_DATA_IND_V01 
//#define REMOVE_QMI_NAS_PERFORM_INCREMENTAL_NETWORK_SCAN_V01 
//#define REMOVE_QMI_NAS_PERFORM_NETWORK_SCAN_V01 
//#define REMOVE_QMI_NAS_RESET_V01 
//#define REMOVE_QMI_NAS_RESET_LTE_PLMN_BLOCKING_V01 
//#define REMOVE_QMI_NAS_RESET_NR5G_PLMN_BLOCKING_V01 
//#define REMOVE_QMI_NAS_RF_AVAILABILITY_IND_V01 
//#define REMOVE_QMI_NAS_RF_BAND_INFO_IND_V01 
//#define REMOVE_QMI_NAS_RTRE_CONFIG_IND_V01 
//#define REMOVE_QMI_NAS_SERVING_SYSTEM_IND_V01 
//#define REMOVE_QMI_NAS_SET_3GPP2_SUBSCRIPTION_INFO_V01 
//#define REMOVE_QMI_NAS_SET_ACCOLC_V01 
//#define REMOVE_QMI_NAS_SET_BSR_TIMER_V01 
//#define REMOVE_QMI_NAS_SET_BUILTIN_PLMN_LIST_V01 
//#define REMOVE_QMI_NAS_SET_CELL_CONFIG_V01 
//#define REMOVE_QMI_NAS_SET_CELL_LOCK_CONFIG_V01 
//#define REMOVE_QMI_NAS_SET_DATA_ROAMING_V01 
//#define REMOVE_QMI_NAS_SET_DATA_SUBS_PRIORITY_V01 
//#define REMOVE_QMI_NAS_SET_DDTM_PREFERENCE_V01 
//#define REMOVE_QMI_NAS_SET_DEVICE_CONFIG_V01 
//#define REMOVE_QMI_NAS_SET_DRX_V01 
//#define REMOVE_QMI_NAS_SET_DRX_SCALING_FACTOR_V01 
//#define REMOVE_QMI_NAS_SET_DUAL_STANDBY_PREF_V01 
//#define REMOVE_QMI_NAS_SET_ECID_CONFIG_V01 
//#define REMOVE_QMI_NAS_SET_EDRX_V01 
//#define REMOVE_QMI_NAS_SET_EDRX_PARAMS_V01 
//#define REMOVE_QMI_NAS_SET_EVENT_REPORT_V01 
//#define REMOVE_QMI_NAS_SET_FORBIDDEN_NETWORKS_V01 
//#define REMOVE_QMI_NAS_SET_GNSS_SESSION_STATUS_V01 
//#define REMOVE_QMI_NAS_SET_HPLMN_IRAT_SEARCH_TIMER_V01 
//#define REMOVE_QMI_NAS_SET_HPLMN_SEARCH_TIMER_V01 
//#define REMOVE_QMI_NAS_SET_IMS_PROC_TYPE_V01 
//#define REMOVE_QMI_NAS_SET_LTE_BAND_PRIORITY_V01 
//#define REMOVE_QMI_NAS_SET_LTE_PROC_TYPE_V01 
//#define REMOVE_QMI_NAS_SET_MCC_V01 
//#define REMOVE_QMI_NAS_SET_PERIODIC_SEARCH_ALLOWED_V01 
//#define REMOVE_QMI_NAS_SET_PREFERRED_NETWORKS_V01 
//#define REMOVE_QMI_NAS_SET_RPM_PARAMETERS_V01 
//#define REMOVE_QMI_NAS_SET_RPM_PARAMETERS_2_V01 
//#define REMOVE_QMI_NAS_SET_RPM_STATE_V01 
//#define REMOVE_QMI_NAS_SET_RTRE_CONFIG_V01 
//#define REMOVE_QMI_NAS_SET_RX_DIVERSITY_V01 
//#define REMOVE_QMI_NAS_SET_SMALL_BW_EARFCN_V01 
//#define REMOVE_QMI_NAS_SET_SRVCC_V01 
//#define REMOVE_QMI_NAS_SET_SSAC_HYSTERESIS_TIMER_V01 
//#define REMOVE_QMI_NAS_SET_SYSTEM_SELECTION_PREFERENCE_V01 
//#define REMOVE_QMI_NAS_SET_TECHNOLOGY_PREFERENCE_V01 
//#define REMOVE_QMI_NAS_SET_VOICE_ROAMING_V01 
//#define REMOVE_QMI_NAS_SIG_INFO_IND_V01 
//#define REMOVE_QMI_NAS_SSAC_CHANGE_INFO_IND_V01 
//#define REMOVE_QMI_NAS_SSAC_INFO_IND_V01 
//#define REMOVE_QMI_NAS_SUBSCRIPTION_INFO_IND_V01 
//#define REMOVE_QMI_NAS_SUB_BLOCKED_STATUS_IND_V01 
//#define REMOVE_QMI_NAS_SYS_INFO_IND_V01 
//#define REMOVE_QMI_NAS_TIMER_EXPIRY_IND_V01 
//#define REMOVE_QMI_NAS_UNBLOCK_LTE_PLMN_V01 
//#define REMOVE_QMI_NAS_UNBLOCK_NR5G_PLMN_V01 
//#define REMOVE_QMI_NAS_UPDATE_AKEY_V01 
//#define REMOVE_QMI_NAS_UPDATE_AKEY_EXT_V01 
//#define REMOVE_QMI_NAS_UPDATE_CA_BAND_COMBO_MSG_V01 
//#define REMOVE_QMI_NAS_UPDATE_IMS_STATUS_V01 
//#define REMOVE_QMI_NAS_V2X_NOTIFICATION_IND_V01 
//#define REMOVE_QMI_NAS_V2X_START_V01 
//#define REMOVE_QMI_NAS_V2X_STOP_V01 

/*Service Message Definition*/
/** @addtogroup nas_qmi_msg_ids
    @{
  */
#define QMI_NAS_RESET_REQ_MSG_V01 0x0000
#define QMI_NAS_RESET_RESP_MSG_V01 0x0000
#define QMI_NAS_ABORT_REQ_MSG_V01 0x0001
#define QMI_NAS_ABORT_RESP_MSG_V01 0x0001
#define QMI_NAS_SET_EVENT_REPORT_REQ_MSG_V01 0x0002
#define QMI_NAS_SET_EVENT_REPORT_RESP_MSG_V01 0x0002
#define QMI_NAS_EVENT_REPORT_IND_MSG_V01 0x0002
#define QMI_NAS_INDICATION_REGISTER_REQ_MSG_V01 0x0003
#define QMI_NAS_INDICATION_REGISTER_RESP_MSG_V01 0x0003
#define QMI_NAS_GET_SUPPORTED_MSGS_REQ_V01 0x001E
#define QMI_NAS_GET_SUPPORTED_MSGS_RESP_V01 0x001E
#define QMI_NAS_GET_SUPPORTED_FIELDS_REQ_V01 0x001F
#define QMI_NAS_GET_SUPPORTED_FIELDS_RESP_V01 0x001F
#define QMI_NAS_GET_SIGNAL_STRENGTH_REQ_MSG_V01 0x0020
#define QMI_NAS_GET_SIGNAL_STRENGTH_RESP_MSG_V01 0x0020
#define QMI_NAS_PERFORM_NETWORK_SCAN_REQ_MSG_V01 0x0021
#define QMI_NAS_PERFORM_NETWORK_SCAN_RESP_MSG_V01 0x0021
#define QMI_NAS_INITIATE_NETWORK_REGISTER_REQ_MSG_V01 0x0022
#define QMI_NAS_INITIATE_NETWORK_REGISTER_RESP_MSG_V01 0x0022
#define QMI_NAS_INITIATE_ATTACH_REQ_MSG_V01 0x0023
#define QMI_NAS_INITIATE_ATTACH_RESP_MSG_V01 0x0023
#define QMI_NAS_GET_SERVING_SYSTEM_REQ_MSG_V01 0x0024
#define QMI_NAS_GET_SERVING_SYSTEM_RESP_MSG_V01 0x0024
#define QMI_NAS_SERVING_SYSTEM_IND_MSG_V01 0x0024
#define QMI_NAS_GET_HOME_NETWORK_REQ_MSG_V01 0x0025
#define QMI_NAS_GET_HOME_NETWORK_RESP_MSG_V01 0x0025
#define QMI_NAS_GET_PREFERRED_NETWORKS_REQ_MSG_V01 0x0026
#define QMI_NAS_GET_PREFERRED_NETWORKS_RESP_MSG_V01 0x0026
#define QMI_NAS_SET_PREFERRED_NETWORKS_REQ_MSG_V01 0x0027
#define QMI_NAS_SET_PREFERRED_NETWORKS_RESP_MSG_V01 0x0027
#define QMI_NAS_GET_FORBIDDEN_NETWORKS_REQ_MSG_V01 0x0028
#define QMI_NAS_GET_FORBIDDEN_NETWORKS_RESP_MSG_V01 0x0028
#define QMI_NAS_SET_FORBIDDEN_NETWORKS_REQ_MSG_V01 0x0029
#define QMI_NAS_SET_FORBIDDEN_NETWORKS_RESP_MSG_V01 0x0029
#define QMI_NAS_SET_TECHNOLOGY_PREFERENCE_REQ_V01 0x002A
#define QMI_NAS_SET_TECHNOLOGY_PREFERENCE_RESP_V01 0x002A
#define QMI_NAS_GET_TECHNOLOGY_PREFERENCE_REQ_V01 0x002B
#define QMI_NAS_GET_TECHNOLOGY_PREFERENCE_RESP_V01 0x002B
#define QMI_NAS_GET_ACCOLC_REQ_MSG_V01 0x002C
#define QMI_NAS_GET_ACCOLC_RESP_MSG_V01 0x002C
#define QMI_NAS_SET_ACCOLC_REQ_MSG_V01 0x002D
#define QMI_NAS_SET_ACCOLC_RESP_MSG_V01 0x002D
#define QMI_NAS_GET_NETWORK_SYSTEM_PREFERENCE_REQ_V01 0x002E
#define QMI_NAS_GET_NETWORK_SYSTEM_PREFERENCE_RESP_V01 0x002E
#define QMI_NAS_GET_DEVICE_CONFIG_REQ_MSG_V01 0x002F
#define QMI_NAS_GET_DEVICE_CONFIG_RESP_MSG_V01 0x002F
#define QMI_NAS_SET_DEVICE_CONFIG_REQ_MSG_V01 0x0030
#define QMI_NAS_SET_DEVICE_CONFIG_RESP_MSG_V01 0x0030
#define QMI_NAS_GET_RF_BAND_INFO_REQ_MSG_V01 0x0031
#define QMI_NAS_GET_RF_BAND_INFO_RESP_MSG_V01 0x0031
#define QMI_NAS_GET_AN_AAA_STATUS_REQ_MSG_V01 0x0032
#define QMI_NAS_GET_AN_AAA_STATUS_RESP_MSG_V01 0x0032
#define QMI_NAS_SET_SYSTEM_SELECTION_PREFERENCE_REQ_MSG_V01 0x0033
#define QMI_NAS_SET_SYSTEM_SELECTION_PREFERENCE_RESP_MSG_V01 0x0033
#define QMI_NAS_GET_SYSTEM_SELECTION_PREFERENCE_REQ_MSG_V01 0x0034
#define QMI_NAS_GET_SYSTEM_SELECTION_PREFERENCE_RESP_MSG_V01 0x0034
#define QMI_NAS_SYSTEM_SELECTION_PREFERENCE_IND_MSG_V01 0x0034
#define QMI_NAS_SET_DDTM_PREFERENCE_REQ_MSG_V01 0x0037
#define QMI_NAS_SET_DDTM_PREFERENCE_RESP_MSG_V01 0x0037
#define QMI_NAS_DDTM_IND_MSG_V01 0x0038
#define QMI_NAS_GET_OPERATOR_NAME_DATA_REQ_MSG_V01 0x0039
#define QMI_NAS_GET_OPERATOR_NAME_DATA_RESP_MSG_V01 0x0039
#define QMI_NAS_OPERATOR_NAME_DATA_IND_MSG_V01 0x003A
#define QMI_NAS_GET_CSP_PLMN_MODE_BIT_REQ_MSG_V01 0x003B
#define QMI_NAS_GET_CSP_PLMN_MODE_BIT_RESP_MSG_V01 0x003B
#define QMI_NAS_CSP_PLMN_MODE_BIT_IND_MSG_V01 0x003C
#define QMI_NAS_UPDATE_AKEY_REQ_MSG_V01 0x003D
#define QMI_NAS_UPDATE_AKEY_RESP_MSG_V01 0x003D
#define QMI_NAS_GET_3GPP2_SUBSCRIPTION_INFO_REQ_MSG_V01 0x003E
#define QMI_NAS_GET_3GPP2_SUBSCRIPTION_INFO_RESP_MSG_V01 0x003E
#define QMI_NAS_SET_3GPP2_SUBSCRIPTION_INFO_REQ_MSG_V01 0x003F
#define QMI_NAS_SET_3GPP2_SUBSCRIPTION_INFO_RESP_MSG_V01 0x003F
#define QMI_NAS_GET_MOB_CAI_REV_REQ_MSG_V01 0x0040
#define QMI_NAS_GET_MOB_CAI_REV_RESP_MSG_V01 0x0040
#define QMI_NAS_GET_RTRE_CONFIG_REQ_MSG_V01 0x0041
#define QMI_NAS_GET_RTRE_CONFIG_RESP_MSG_V01 0x0041
#define QMI_NAS_SET_RTRE_CONFIG_REQ_MSG_V01 0x0042
#define QMI_NAS_SET_RTRE_CONFIG_RESP_MSG_V01 0x0042
#define QMI_NAS_GET_CELL_LOCATION_INFO_REQ_MSG_V01 0x0043
#define QMI_NAS_GET_CELL_LOCATION_INFO_RESP_MSG_V01 0x0043
#define QMI_NAS_GET_PLMN_NAME_REQ_MSG_V01 0x0044
#define QMI_NAS_GET_PLMN_NAME_RESP_MSG_V01 0x0044
#define QMI_NAS_BIND_SUBSCRIPTION_REQ_MSG_V01 0x0045
#define QMI_NAS_BIND_SUBSCRIPTION_RESP_MSG_V01 0x0045
#define QMI_NAS_MANAGED_ROAMING_IND_MSG_V01 0x0046
#define QMI_NAS_DUAL_STANDBY_PREF_IND_MSG_V01 0x0047
#define QMI_NAS_SUBSCRIPTION_INFO_IND_MSG_V01 0x0048
#define QMI_NAS_GET_MODE_PREF_REQ_MSG_V01 0x0049
#define QMI_NAS_GET_MODE_PREF_RESP_MSG_V01 0x0049
#define QMI_NAS_DUAL_STANDBY_PREF_REQ_MSG_V01 0x004B
#define QMI_NAS_DUAL_STANDBY_PREF_RESP_MSG_V01 0x004B
#define QMI_NAS_NETWORK_TIME_IND_MSG_V01 0x004C
#define QMI_NAS_GET_SYS_INFO_REQ_MSG_V01 0x004D
#define QMI_NAS_GET_SYS_INFO_RESP_MSG_V01 0x004D
#define QMI_NAS_SYS_INFO_IND_MSG_V01 0x004E
#define QMI_NAS_GET_SIG_INFO_REQ_MSG_V01 0x004F
#define QMI_NAS_GET_SIG_INFO_RESP_MSG_V01 0x004F
#define QMI_NAS_CONFIG_SIG_INFO_REQ_MSG_V01 0x0050
#define QMI_NAS_CONFIG_SIG_INFO_RESP_MSG_V01 0x0050
#define QMI_NAS_SIG_INFO_IND_MSG_V01 0x0051
#define QMI_NAS_GET_ERR_RATE_REQ_MSG_V01 0x0052
#define QMI_NAS_GET_ERR_RATE_RESP_MSG_V01 0x0052
#define QMI_NAS_ERR_RATE_IND_MSG_V01 0x0053
#define QMI_NAS_HDR_SESSION_CLOSE_IND_MSG_V01 0x0054
#define QMI_NAS_HDR_UATI_UPDATE_IND_MSG_V01 0x0055
#define QMI_NAS_GET_HDR_SUBTYPE_REQ_MSG_V01 0x0056
#define QMI_NAS_GET_HDR_SUBTYPE_RESP_MSG_V01 0x0056
#define QMI_NAS_GET_HDR_COLOR_CODE_REQ_MSG_V01 0x0057
#define QMI_NAS_GET_HDR_COLOR_CODE_RESP_MSG_V01 0x0057
#define QMI_NAS_GET_CURRENT_ACQ_SYS_MODE_REQ_MSG_V01 0x0058
#define QMI_NAS_GET_CURRENT_ACQ_SYS_MODE_RESP_MSG_V01 0x0058
#define QMI_NAS_SET_RX_DIVERSITY_REQ_MSG_V01 0x0059
#define QMI_NAS_SET_RX_DIVERSITY_RESP_MSG_V01 0x0059
#define QMI_NAS_GET_TX_RX_INFO_REQ_MSG_V01 0x005A
#define QMI_NAS_GET_TX_RX_INFO_RESP_MSG_V01 0x005A
#define QMI_NAS_UPDATE_AKEY_EXT_REQ_MSG_V01 0x005B
#define QMI_NAS_UPDATE_AKEY_EXT_RESP_V01 0x005B
#define QMI_NAS_GET_DUAL_STANDBY_PREF_REQ_MSG_V01 0x005C
#define QMI_NAS_GET_DUAL_STANDBY_PREF_RESP_MSG_V01 0x005C
#define QMI_NAS_DETACH_LTE_REQ_MSG_V01 0x005D
#define QMI_NAS_DETACH_LTE_RESP_MSG_V01 0x005D
#define QMI_NAS_BLOCK_LTE_PLMN_REQ_MSG_V01 0x005E
#define QMI_NAS_BLOCK_LTE_PLMN_RESP_MSG_V01 0x005E
#define QMI_NAS_UNBLOCK_LTE_PLMN_REQ_MSG_V01 0x005F
#define QMI_NAS_UNBLOCK_LTE_PLMN_RESP_MSG_V01 0x005F
#define QMI_NAS_RESET_LTE_PLMN_BLOCKING_REQ_MSG_V01 0x0060
#define QMI_NAS_RESET_LTE_PLMN_BLOCKING_RESP_MSG_V01 0x0060
#define QMI_NAS_CURRENT_PLMN_NAME_IND_V01 0x0061
#define QMI_NAS_CONFIG_EMBMS_REQ_MSG_V01 0x0062
#define QMI_NAS_CONFIG_EMBMS_RESP_MSG_V01 0x0062
#define QMI_NAS_GET_EMBMS_STATUS_REQ_MSG_V01 0x0063
#define QMI_NAS_GET_EMBMS_STATUS_RESP_MSG_V01 0x0063
#define QMI_NAS_EMBMS_STATUS_IND_V01 0x0064
#define QMI_NAS_GET_CDMA_POSITION_INFO_REQ_MSG_V01 0x0065
#define QMI_NAS_GET_CDMA_POSITION_INFO_RESP_MSG_V01 0x0065
#define QMI_NAS_RF_BAND_INFO_IND_V01 0x0066
#define QMI_NAS_FORCE_NETWORK_SEARCH_REQ_MSG_V01 0x0067
#define QMI_NAS_FORCE_NETWORK_SEARCH_RESP_MSG_V01 0x0067
#define QMI_NAS_NETWORK_REJECT_IND_V01 0x0068
#define QMI_NAS_GET_MANAGED_ROAMING_CONFIG_REQ_MSG_V01 0x0069
#define QMI_NAS_GET_MANAGED_ROAMING_CONFIG_RESP_MSG_V01 0x0069
#define QMI_NAS_RTRE_CONFIG_IND_V01 0x006A
#define QMI_NAS_GET_CENTRALIZED_EONS_SUPPORT_STATUS_REQ_MSG_V01 0x006B
#define QMI_NAS_GET_CENTRALIZED_EONS_SUPPORT_STATUS_RESP_MSG_V01 0x006B
#define QMI_NAS_CONFIG_SIG_INFO2_REQ_MSG_V01 0x006C
#define QMI_NAS_CONFIG_SIG_INFO2_RESP_MSG_V01 0x006C
#define QMI_NAS_GET_TDS_CELL_AND_POSITION_INFO_REQ_MSG_V01 0x006D
#define QMI_NAS_GET_TDS_CELL_AND_POSITION_INFO_RESP_MSG_V01 0x006D
#define QMI_NAS_SET_HPLMN_IRAT_SEARCH_TIMER_REQ_MSG_V01 0x006E
#define QMI_NAS_SET_HPLMN_IRAT_SEARCH_TIMER_RESP_MSG_V01 0x006E
#define QMI_NAS_GET_EMBMS_SIG_REQ_MSG_V01 0x006F
#define QMI_NAS_GET_EMBMS_SIG_RESP_MSG_V01 0x006F
#define QMI_NAS_LIMIT_SYS_INFO_IND_REPORTING_REQ_MSG_V01 0x0070
#define QMI_NAS_LIMIT_SYS_INFO_IND_REPORTING_RESP_MSG_V01 0x0070
#define QMI_NAS_GET_SYS_INFO_IND_REPORTING_LIMIT_REQ_MSG_V01 0x0071
#define QMI_NAS_GET_SYS_INFO_IND_REPORTING_LIMIT_RESP_MSG_V01 0x0071
#define QMI_NAS_UPDATE_IMS_STATUS_REQ_MSG_V01 0x0072
#define QMI_NAS_UPDATE_IMS_STATUS_RESP_MSG_V01 0x0072
#define QMI_NAS_GET_IMS_PREF_STATUS_REQ_MSG_V01 0x0073
#define QMI_NAS_GET_IMS_PREF_STATUS_RESP_MSG_V01 0x0073
#define QMI_NAS_IMS_PREF_STATUS_IND_V01 0x0074
#define QMI_NAS_CONFIG_PLMN_NAME_IND_REPORTING_REQ_MSG_V01 0x0075
#define QMI_NAS_CONFIG_PLMN_NAME_IND_REPORTING_RESP_MSG_V01 0x0075
#define QMI_NAS_CDMA_AVOID_SYSTEM_REQ_MSG_V01 0x0076
#define QMI_NAS_CDMA_AVOID_SYSTEM_RESP_MSG_V01 0x0076
#define QMI_NAS_GET_CDMA_AVOID_SYSTEM_LIST_REQ_MSG_V01 0x0077
#define QMI_NAS_GET_CDMA_AVOID_SYSTEM_LIST_RESP_MSG_V01 0x0077
#define QMI_NAS_SET_HPLMN_SEARCH_TIME_REQ_MSG_V01 0x0078
#define QMI_NAS_SET_HPLMN_SEARCH_TIME_RESP_MSG_V01 0x0078
#define QMI_NAS_GET_HPLMN_SEARCH_TIME_REQ_MSG_V01 0x0079
#define QMI_NAS_GET_HPLMN_SEARCH_TIME_RESP_MSG_V01 0x0079
#define QMI_NAS_GET_SUBSCRIPTION_INFO_REQ_MSG_V01 0x007C
#define QMI_NAS_GET_SUBSCRIPTION_INFO_RESP_MSG_V01 0x007C
#define QMI_NAS_GET_NETWORK_TIME_REQ_MSG_V01 0x007D
#define QMI_NAS_GET_NETWORK_TIME_RESP_MSG_V01 0x007D
#define QMI_NAS_GET_LTE_SIB16_NETWORK_TIME_REQ_MSG_V01 0x007E
#define QMI_NAS_GET_LTE_SIB16_NETWORK_TIME_RESP_MSG_V01 0x007E
#define QMI_NAS_LTE_SIB16_NETWORK_TIME_IND_V01 0x007F
#define QMI_NAS_SET_LTE_BAND_PRIORITY_REQ_MSG_V01 0x0080
#define QMI_NAS_SET_LTE_BAND_PRIORITY_RESP_MSG_V01 0x0080
#define QMI_NAS_GET_EMBMS_SIG_EXT_REQ_MSG_V01 0x0081
#define QMI_NAS_GET_EMBMS_SIG_EXT_RESP_MSG_V01 0x0081
#define QMI_NAS_LTE_CPHY_CA_IND_V01 0x0082
#define QMI_NAS_GET_LTE_BAND_PRIORITY_LIST_REQ_MSG_V01 0x0083
#define QMI_NAS_GET_LTE_BAND_PRIORITY_LIST_RESP_MSG_V01 0x0083
#define QMI_NAS_SET_BUILTIN_PLMN_LIST_REQ_MSG_V01 0x0084
#define QMI_NAS_SET_BUILTIN_PLMN_LIST_RESP_MSG_V01 0x0084
#define QMI_NAS_SET_BUILTIN_PLMN_LIST_IND_MSG_V01 0x0084
#define QMI_NAS_PERFORM_INCREMENTAL_NETWORK_SCAN_REQ_MSG_V01 0x0085
#define QMI_NAS_PERFORM_INCREMENTAL_NETWORK_SCAN_RESP_MSG_V01 0x0085
#define QMI_NAS_PERFORM_INCREMENTAL_NETWORK_SCAN_IND_MSG_V01 0x0085
#define QMI_NAS_SET_DRX_REQ_MSG_V01 0x0088
#define QMI_NAS_SET_DRX_RESP_MSG_V01 0x0088
#define QMI_NAS_GET_DRX_REQ_MSG_V01 0x0089
#define QMI_NAS_GET_DRX_RESP_MSG_V01 0x0089
#define QMI_NAS_CSG_SEARCH_SELECTION_CONFIG_REQ_MSG_V01 0x008A
#define QMI_NAS_CSG_SEARCH_SELECTION_CONFIG_RESP_MSG_V01 0x008A
#define QMI_NAS_CSG_IMMEDIATE_SEARCH_SELECTION_REQ_MSG_V01 0x008B
#define QMI_NAS_CSG_IMMEDIATE_SEARCH_SELECTION_RESP_MSG_V01 0x008B
#define QMI_NAS_GET_CSG_SEARCH_SELECTION_CONFIGURATION_REQ_MSG_V01 0x008C
#define QMI_NAS_GET_CSG_SEARCH_SELECTION_CONFIGURATION_RESP_MSG_V01 0x008C
#define QMI_NAS_SSAC_INFO_IND_V01 0x008D
#define QMI_NAS_GET_LTE_EMBMS_INFO_REQ_MSG_V01 0x008E
#define QMI_NAS_GET_LTE_EMBMS_INFO_RESP_MSG_V01 0x008E
#define QMI_NAS_GET_SERV_CELL_SIB_REQ_MSG_V01 0x008F
#define QMI_NAS_GET_SERV_CELL_SIB_RESP_MSG_V01 0x008F
#define QMI_NAS_GET_SERV_CELL_SIB_IND_MSG_V01 0x008F
#define QMI_NAS_SSAC_CHANGE_INFO_IND_V01 0x0090
#define QMI_NAS_GET_SSAC_INFO_REQ_MSG_V01 0x0091
#define QMI_NAS_GET_SSAC_INFO_RESP_MSG_V01 0x0091
#define QMI_NAS_SET_PERIODIC_SEARCH_ALLOWED_REQ_MSG_V01 0x0092
#define QMI_NAS_SET_PERIODIC_SEARCH_ALLOWED_RESP_MSG_V01 0x0092
#define QMI_NAS_EMM_T3402_CHANGED_IND_V01 0x0093
#define QMI_NAS_GET_ACB_INFO_REQ_MSG_V01 0x0094
#define QMI_NAS_GET_ACB_INFO_RESP_MSG_V01 0x0094
#define QMI_NAS_ACB_INFO_IND_V01 0x0094
#define QMI_NAS_SET_DATA_SUBS_PRIORITY_REQ_MSG_V01 0x0095
#define QMI_NAS_SET_DATA_SUBS_PRIORITY_RESP_MSG_V01 0x0095
#define QMI_NAS_GET_DATA_SUBS_PRIORITY_REQ_MSG_V01 0x0096
#define QMI_NAS_GET_DATA_SUBS_PRIORITY_RESP_MSG_V01 0x0096
#define QMI_NAS_DATA_SUBS_PRIORITY_IND_MSG_V01 0x0097
#define QMI_NAS_AVOID_TUNEAWAY_REQ_MSG_V01 0x0098
#define QMI_NAS_AVOID_TUNEAWAY_RESP_MSG_V01 0x0098
#define QMI_NAS_SET_MCC_REQ_MSG_V01 0x0099
#define QMI_NAS_SET_MCC_RESP_MSG_V01 0x0099
#define QMI_NAS_SET_DATA_ROAMING_REQ_MSG_V01 0x009A
#define QMI_NAS_SET_DATA_ROAMING_RESP_MSG_V01 0x009A
#define QMI_NAS_GET_DATA_ROAMING_REQ_MSG_V01 0x009B
#define QMI_NAS_GET_DATA_ROAMING_RESP_MSG_V01 0x009B
#define QMI_NAS_SET_SRVCC_REQ_MSG_V01 0x009C
#define QMI_NAS_SET_SRVCC_RESP_MSG_V01 0x009C
#define QMI_NAS_SET_BSR_TIMER_REQ_MSG_V01 0x009D
#define QMI_NAS_SET_BSR_TIMER_RESP_MSG_V01 0x009D
#define QMI_NAS_GET_BSR_REQ_MSG_V01 0x009E
#define QMI_NAS_GET_BSR_RESP_MSG_V01 0x009E
#define QMI_NAS_SET_DRX_SCALING_FACTOR_REQ_MSG_V01 0x009F
#define QMI_NAS_SET_DRX_SCALING_FACTOR_RESP_MSG_V01 0x009F
#define QMI_NAS_SET_SSAC_HYSTERESIS_TIMER_REQ_MSG_V01 0x00A5
#define QMI_NAS_SET_SSAC_HYSTERESIS_TIMER_RESP_MSG_V01 0x00A5
#define QMI_NAS_GET_SSAC_HYSTERESIS_TIMER_REQ_MSG_V01 0x00A6
#define QMI_NAS_GET_SSAC_HYSTERESIS_TIMER_RESP_MSG_V01 0x00A6
#define QMI_NAS_GET_HDR_INFO_REQ_MSG_V01 0x00A7
#define QMI_NAS_GET_HDR_INFO_RESP_MSG_V01 0x00A7
#define QMI_NAS_GET_HDR_DRC_RATE_REQ_MSG_V01 0x00A8
#define QMI_NAS_GET_HDR_DRC_RATE_RESP_MSG_V01 0x00A8
#define QMI_NAS_SET_RPM_PARAMETERS_REQ_MSG_V01 0x00A9
#define QMI_NAS_SET_RPM_PARAMETERS_RESP_MSG_V01 0x00A9
#define QMI_NAS_GET_RPM_PARAMETERS_REQ_MSG_V01 0x00AA
#define QMI_NAS_GET_RPM_PARAMETERS_RESP_MSG_V01 0x00AA
#define QMI_NAS_SET_RPM_STATE_REQ_MSG_V01 0x00AB
#define QMI_NAS_SET_RPM_STATE_RESP_MSG_V01 0x00AB
#define QMI_NAS_GET_LTE_CPHY_CA_INFO_REQ_MSG_V01 0x00AC
#define QMI_NAS_GET_LTE_CPHY_CA_INFO_RESP_MSG_V01 0x00AC
#define QMI_NAS_MANUAL_SCAN_FAIL_IND_MSG_V01 0x00AD
#define QMI_NAS_GET_NEGOTIATED_DRX_REQ_MSG_V01 0x00AE
#define QMI_NAS_GET_NEGOTIATED_DRX_RESP_MSG_V01 0x00AE
#define QMI_NAS_SET_CELL_LOCK_CONFIG_REQ_MSG_V01 0x00AF
#define QMI_NAS_SET_CELL_LOCK_CONFIG_RESP_MSG_V01 0x00AF
#define QMI_NAS_LTE_UE_CONFIG_REQ_MSG_V01 0x00B0
#define QMI_NAS_LTE_UE_CONFIG_RESP_MSG_V01 0x00B0
#define QMI_NAS_TIMER_EXPIRY_IND_V01 0x00B1
#define QMI_NAS_EMERGENCY_MODE_STATUS_IND_V01 0x00B2
#define QMI_NAS_ECALL_DEREGISTRATION_REQ_MSG_V01 0x00B3
#define QMI_NAS_ECALL_DEREGISTRATION_RESP_MSG_V01 0x00B3
#define QMI_NAS_UPDATE_CA_BAND_COMBO_REQ_MSG_V01 0x00B4
#define QMI_NAS_UPDATE_CA_BAND_COMBO_RESP_MSG_V01 0x00B4
#define QMI_NAS_GET_CA_BAND_COMBO_REQ_MSG_V01 0x00B5
#define QMI_NAS_GET_CA_BAND_COMBO_RESP_MSG_V01 0x00B5
#define QMI_NAS_ECALL_TIMER_RESTART_REQ_MSG_V01 0x00B6
#define QMI_NAS_ECALL_TIMER_RESTART_RESP_MSG_V01 0x00B6
#define QMI_NAS_SET_VOICE_ROAMING_REQ_MSG_V01 0x00B7
#define QMI_NAS_SET_VOICE_ROAMING_RESP_MSG_V01 0x00B7
#define QMI_NAS_GET_VOICE_ROAMING_REQ_MSG_V01 0x00B8
#define QMI_NAS_GET_VOICE_ROAMING_RESP_MSG_V01 0x00B8
#define QMI_NAS_SET_RPM_PARAMETERS_2_REQ_MSG_V01 0x00B9
#define QMI_NAS_SET_RPM_PARAMETERS_2_RESP_MSG_V01 0x00B9
#define QMI_NAS_SET_EDRX_REQ_MSG_V01 0x00BA
#define QMI_NAS_SET_EDRX_RESP_MSG_V01 0x00BA
#define QMI_NAS_GET_EDRX_REQ_MSG_V01 0x00BB
#define QMI_NAS_GET_EDRX_RESP_MSG_V01 0x00BB
#define QMI_NAS_GCELL_INFO_IND_V01 0x00BC
#define QMI_NAS_GCELL_INFO_REQ_V01 0x00BD
#define QMI_NAS_GCELL_INFO_RESP_V01 0x00BD
#define QMI_NAS_BAR_GCELL_REQ_V01 0x00BE
#define QMI_NAS_BAR_GCELL_RESP_V01 0x00BE
#define QMI_NAS_EDRX_CHANGE_INFO_IND_V01 0x00BF
#define QMI_NAS_SET_EDRX_PARAMS_REQ_MSG_V01 0x00C0
#define QMI_NAS_SET_EDRX_PARAMS_RESP_MSG_V01 0x00C0
#define QMI_NAS_GET_EDRX_PARAMS_REQ_MSG_V01 0x00C1
#define QMI_NAS_GET_EDRX_PARAMS_RESP_MSG_V01 0x00C1
#define QMI_NAS_ABORT_SCAN_REQ_V01 0x00C2
#define QMI_NAS_ABORT_SCAN_RESP_V01 0x00C2
#define QMI_NAS_LTE_CPHY_CA_AGG_DL_BW_IND_V01 0x00C3
#define QMI_NAS_SET_LTE_PROC_TYPE_REQ_MSG_V01 0x00C4
#define QMI_NAS_SET_LTE_PROC_TYPE_RESP_MSG_V01 0x00C4
#define QMI_NAS_LTE_RACH_FAIL_IND_V01 0x00C5
#define QMI_NAS_LTE_RRC_TX_INFO_IND_V01 0x00C6
#define QMI_NAS_GET_LTE_RRC_TX_INFO_REQ_MSG_V01 0x00C7
#define QMI_NAS_GET_LTE_RRC_TX_INFO_RESP_MSG_V01 0x00C7
#define QMI_NAS_SET_GNSS_SESSION_STATUS_REQ_MSG_V01 0x00C8
#define QMI_NAS_SET_GNSS_SESSION_STATUS_RESP_MSG_V01 0x00C8
#define QMI_NAS_SET_ECID_CONFIG_REQ_MSG_V01 0x00C9
#define QMI_NAS_SET_ECID_CONFIG_RESP_MSG_V01 0x00C9
#define QMI_NAS_GET_ECID_CONFIG_REQ_MSG_V01 0x00CA
#define QMI_NAS_GET_ECID_CONFIG_RESP_MSG_V01 0x00CA
#define QMI_NAS_SUB_BLOCKED_STATUS_IND_V01 0x00CB
#define QMI_NAS_GET_SUB_BLOCKED_STATUS_REQ_MSG_V01 0x00CC
#define QMI_NAS_GET_SUB_BLOCKED_STATUS_RESP_MSG_V01 0x00CC
#define QMI_NAS_LTE_B2_THRESH_ADJ_CONFIG_REQ_MSG_V01 0x00CD
#define QMI_NAS_LTE_B2_THRESH_ADJ_CONFIG_RESP_MSG_V01 0x00CD
#define QMI_NAS_V2X_START_REQ_MSG_V01 0x00CE
#define QMI_NAS_V2X_START_RESP_MSG_V01 0x00CE
#define QMI_NAS_V2X_STOP_REQ_MSG_V01 0x00CF
#define QMI_NAS_V2X_STOP_RESP_MSG_V01 0x00CF
#define QMI_NAS_GET_V2X_STATUS_REQ_MSG_V01 0x00D0
#define QMI_NAS_GET_V2X_STATUS_RESP_MSG_V01 0x00D0
#define QMI_NAS_V2X_NOTIFICATION_IND_V01 0x00D1
#define QMI_NAS_GET_ARFCN_LIST_REQ_MSG_V01 0x00D2
#define QMI_NAS_GET_ARFCN_LIST_RESP_MSG_V01 0x00D2
#define QMI_NAS_ARFCN_LIST_IND_V01 0x00D3
#define QMI_NAS_5G_MODEM_VOTE_IND_V01 0x00D4
#define QMI_NAS_GET_RF_AVAILABILITY_REQ_MSG_V01 0x00D5
#define QMI_NAS_GET_RF_AVAILABILITY_RESP_MSG_V01 0x00D5
#define QMI_NAS_RF_AVAILABILITY_IND_V01 0x00D6
#define QMI_NAS_GET_CELL_LOCK_CONFIG_REQ_V01 0x00D7
#define QMI_NAS_GET_CELL_LOCK_CONFIG_RESP_V01 0x00D7
#define QMI_NAS_SET_CELL_CONFIG_REQ_MSG_V01 0x00D8
#define QMI_NAS_SET_CELL_CONFIG_RESP_MSG_V01 0x00D8
#define QMI_NAS_SET_SMALL_BW_EARFCN_REQ_MSG_V01 0x00D9
#define QMI_NAS_SET_SMALL_BW_EARFCN_RESP_MSG_V01 0x00D9
#define QMI_NAS_GET_SMALL_BW_EARFCN_REQ_MSG_V01 0x00DA
#define QMI_NAS_GET_SMALL_BW_EARFCN_RESP_MSG_V01 0x00DA
#define QMI_NAS_FORCE_LTE_SCAN_REQ_MSG_V01 0x00DB
#define QMI_NAS_FORCE_LTE_SCAN_RESP_MSG_V01 0x00DB
#define QMI_NAS_BLOCK_NR5G_PLMN_REQ_MSG_V01 0x00DE
#define QMI_NAS_BLOCK_NR5G_PLMN_RESP_MSG_V01 0x00DE
#define QMI_NAS_UNBLOCK_NR5G_PLMN_REQ_MSG_V01 0x00DF
#define QMI_NAS_UNBLOCK_NR5G_PLMN_RESP_MSG_V01 0x00DF
#define QMI_NAS_RESET_NR5G_PLMN_BLOCKING_REQ_MSG_V01 0x00E0
#define QMI_NAS_RESET_NR5G_PLMN_BLOCKING_RESP_MSG_V01 0x00E0
#define QMI_NAS_MM5G_T3502_CHANGED_IND_V01 0x00E1
#define QMI_NAS_SET_IMS_PROC_TYPE_REQ_MSG_V01 0x00E2
#define QMI_NAS_SET_IMS_PROC_TYPE_RESP_MSG_V01 0x00E2
/**
    @}
  */

/* Service Object Accessor */
/** @addtogroup wms_qmi_accessor
    @{
  */
/** This function is used internally by the autogenerated code.  Clients should use the
   macro nas_get_service_object_v01( ) that takes in no arguments. */
qmi_idl_service_object_type nas_get_service_object_internal_v01
 ( int32_t idl_maj_version, int32_t idl_min_version, int32_t library_version );

/** This macro should be used to get the service object */
#define nas_get_service_object_v01( ) \
          nas_get_service_object_internal_v01( \
            NAS_V01_IDL_MAJOR_VERS, NAS_V01_IDL_MINOR_VERS, \
            NAS_V01_IDL_TOOL_VERS )
/**
    @}
  */


#ifdef __cplusplus
}
#endif
#endif

