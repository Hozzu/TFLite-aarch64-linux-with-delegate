#ifndef VOICE_SERVICE_02_H
#define VOICE_SERVICE_02_H
/**
  @file voice_service_v02.h

  @brief This is the public header file which defines the voice service Data structures.

  This header file defines the types and structures that were defined in
  voice. It contains the constant values defined, enums, structures,
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
  Copyright (c) 2010-2018 Qualcomm Technologies, Inc.
  All rights reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.


  $Header: //commercial/MPSS.HE.1.0.c1.3/Main/modem_proc/qmimsgs/voice/api/voice_service_v02.h#1 $
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
 *THIS IS AN AUTO GENERATED FILE. DO NOT ALTER IN ANY WAY
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/* This file was generated with Tool version 6.14.7 
   It was generated on: Tue Jul 17 2018 (Spin 0)
   From IDL File: voice_service_v02.idl */

/** @defgroup voice_qmi_consts Constant values defined in the IDL */
/** @defgroup voice_qmi_msg_ids Constant values for QMI message IDs */
/** @defgroup voice_qmi_enums Enumerated types used in QMI messages */
/** @defgroup voice_qmi_messages Structures sent as QMI messages */
/** @defgroup voice_qmi_aggregates Aggregate types used in QMI messages */
/** @defgroup voice_qmi_accessor Accessor for QMI service object */
/** @defgroup voice_qmi_version Constant values for versioning information */

#include <stdint.h>
#include "qmi_idl_lib.h"
#include "common_v01.h"
#include "voice_service_common_v02.h"
#include "voice_nas_services_common_v01.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup voice_qmi_version
    @{
  */
/** Major Version Number of the IDL used to generate this file */
#define VOICE_V02_IDL_MAJOR_VERS 0x02
/** Revision Number of the IDL used to generate this file */
#define VOICE_V02_IDL_MINOR_VERS 0x6A
/** Major Version Number of the qmi_idl_compiler used to generate this file */
#define VOICE_V02_IDL_TOOL_VERS 0x06
/** Maximum Defined Message ID */
#define VOICE_V02_MAX_MESSAGE_ID 0x0074
/**
    @}
  */


/** @addtogroup voice_qmi_consts
    @{
  */
#define QMI_VOICE_NUMBER_MAX_V02 81
#define QMI_VOICE_UUS_DATA_MAX_V02 128
#define QMI_VOICE_CALLER_ID_MAX_V02 81
#define QMI_VOICE_DISPLAY_BUFFER_MAX_V02 182
#define QMI_VOICE_CALLER_NAME_MAX_V02 182
#define QMI_VOICE_FLASH_PAYLOAD_MAX_V02 81
#define QMI_VOICE_DIGIT_BUFFER_MAX_V02 32
#define QMI_VOICE_DIALED_DIGIT_BUFFER_MAX_V02 64
#define QMI_VOICE_DIAGNOSTIC_INFO_MAX_V02 27
#define QMI_VOICE_SUBADDRESS_LEN_MAX_V02 21
#define QMI_VOICE_EXT_DISPLAY_RECORD_LEN_MAX_V02 64
#define QMI_VOICE_SIP_URI_OVERFLOW_MAX_V02 47
#define QMI_VOICE_SIP_URI_MAX_V02 128
#define QMI_VOICE_DISPLAY_TEXT_MAX_LEN_V02 98
#define QMI_VOICE_IP_CALLER_NAME_MAX_LEN_V02 128
#define QMI_VOICE_FAILURE_CAUSE_DESC_MAX_LEN_V02 256
#define QMI_VOICE_END_REASON_TEXT_MAX_LEN_V02 128
#define QMI_VOICE_IP_FORWARD_HIST_INFO_MAX_LEN_V02 512
#define QMI_VOICE_ECALL_MSD_MAX_LEN_V02 140
#define QMI_VOICE_IP_HIST_INFO_MAX_LEN_V02 512
#define QMI_VOICE_IP_ALERT_INFO_MAX_LEN_V02 512
#define QMI_VOICE_CONF_URI_MAX_LEN_V02 128
#define QMI_VOICE_CONF_DISPLAY_TEXT_MAX_LEN_V02 64
#define QMI_VOICE_CONF_XML_MAX_LEN_V02 2048
#define QMI_VOICE_ADDITIONAL_INFO_MAX_LEN_V02 2048
#define QMI_VOICE_CONF_URI_LIST_MAX_LEN_V02 1024
#define QMI_VOICE_VS_FILE_ATTRIBUTES_MAX_V02 500
#define QMI_VOICE_CC_ALPHA_TEXT_MAX_V02 255
#define QMI_VOICE_REASON_FWD_UNCONDITIONAL_V02 0x01
#define QMI_VOICE_REASON_FWD_MOBILEBUSY_V02 0x02
#define QMI_VOICE_REASON_FWD_NOREPLY_V02 0x03
#define QMI_VOICE_REASON_FWD_UNREACHABLE_V02 0x04
#define QMI_VOICE_REASON_FWD_ALLFORWARDING_V02 0x05
#define QMI_VOICE_REASON_FWD_ALLCONDITIONAL_V02 0x06
#define QMI_VOICE_REASON_BARR_ALLOUTGOING_V02 0x07
#define QMI_VOICE_REASON_BARR_OUTGOINGINT_V02 0x08
#define QMI_VOICE_REASON_BARR_OUTGOINGINTEXTOHOME_V02 0x09
#define QMI_VOICE_REASON_BARR_ALLINCOMING_V02 0x0A
#define QMI_VOICE_REASON_BARR_INCOMINGROAMING_V02 0x0B
#define QMI_VOICE_REASON_BARR_ALLBARRING_V02 0x0C
#define QMI_VOICE_REASON_BARR_ALLOUTGOINGBARRING_V02 0x0D
#define QMI_VOICE_REASON_BARR_ALLINCOMINGBARRING_V02 0x0E
#define QMI_VOICE_REASON_CALLWAITING_V02 0x0F
#define QMI_VOICE_REASON_CLIP_V02 0x10
#define QMI_VOICE_REASON_CLIR_V02 0x11
#define QMI_VOICE_REASON_COLP_V02 0x12
#define QMI_VOICE_REASON_COLR_V02 0x13
#define QMI_VOICE_REASON_CNAP_V02 0x14
#define QMI_VOICE_WCDMA_AMR_STATUS_NOT_SUPPORTED_BIT_V02 0
#define QMI_VOICE_WCDMA_AMR_STATUS_WCDMA_AMR_WB_BIT_V02 1
#define QMI_VOICE_WCDMA_AMR_STATUS_GSM_HR_AMR_BIT_V02 2
#define QMI_VOICE_WCDMA_AMR_STATUS_GSM_AMR_WB_BIT_V02 3
#define QMI_VOICE_WCDMA_AMR_STATUS_GSM_AMR_NB_BIT_V02 4
#define QMI_VOICE_WCDMA_AMR_STATUS_GSM_AWR_WB_BIT_V02 3
#define QMI_VOICE_CONF_PARTICIPANT_INFO_ARRAY_MAX_V02 10
#define QMI_VOICE_SERVICE_CLASS_LIST_MAX_V02 5
#define QMI_VOICE_VICE_DIALOG_XML_LEN_V02 2048
#define QMI_VOICE_AVOID_PLMN_LIST_MAX_LENGTH_V02 10
#define VOICE_EMER_CAT_POLICE_BIT_V02 0
#define VOICE_EMER_CAT_AMBULANCE_BIT_V02 1
#define VOICE_EMER_CAT_FIRE_BRIGADE_BIT_V02 2
#define VOICE_EMER_CAT_MARINE_GUARD_BIT_V02 3
#define VOICE_EMER_CAT_MOUNTAIN_RESCUE_BIT_V02 4
#define VOICE_EMER_CAT_MANUAL_ECALL_BIT_V02 5
#define VOICE_EMER_CAT_AUTO_ECALL_BIT_V02 6
#define VOICE_EMER_CAT_SPARE_BIT_V02 7
#define QMI_VOICE_ALPHA_TEXT_MAX_V02 182
#define QMI_VOICE_CALL_INFO_MAX_V02 7
#define QMI_VOICE_REMOTE_PARTY_NUMBER_ARRAY_MAX_V02 7
#define QMI_VOICE_REMOTE_PARTY_NAME_ARRAY_MAX_V02 7
#define QMI_VOICE_ALERTING_TYPE_ARRAY_MAX_V02 7
#define QMI_VOICE_SRV_OPT_ARRAY_MAX_V02 2
#define QMI_VOICE_CALL_END_REASON_ARRAY_MAX_V02 7
#define QMI_VOICE_ALPHA_IDENT_ARRAY_MAX_V02 7
#define QMI_VOICE_CONNECTED_PARTY_ARRAY_MAX_V02 6
#define QMI_VOICE_DIAGNOSTIC_INFO_ARRAY_MAX_V02 7
#define QMI_VOICE_UUS_ARRAY_MAX_V02 7
#define QMI_VOICE_CALLED_PARTY_ARRAY_MAX_V02 7
#define QMI_VOICE_REDIRECTING_PARTY_ARRAY_MAX_V02 7
#define QMI_VOICE_ALERTING_PATTERN_ARRAY_MAX_V02 7
#define QMI_VOICE_CALL_ATTRIBUTES_ARRAY_MAX_V02 7
#define QMI_VOICE_VS_CALL_VARIANT_ARRAY_MAX_V02 7
#define QMI_VOICE_IS_SRVCC_CALL_ARRAY_MAX_V02 7
#define QMI_VOICE_SRVCC_PARENT_CALL_ARRAY_MAX_V02 7
#define QMI_VOICE_CALL_CAPABILITIES_ARRAY_MAX_V02 7
#define QMI_VOICE_CHILD_NUMBER_ARRAY_MAX_V02 7
#define QMI_VOICE_DISPLAY_TEXT_ARRAY_MAX_V02 7
#define QMI_VOICE_IP_CALLER_NAME_ARRAY_MAX_V02 7
#define QMI_VOICE_IP_END_REASON_TEXT_ARRAY_MAX_V02 7
#define QMI_VOICE_CALLED_PARTY_SUBADDRESS_ARRAY_MAX_V02 7
#define QMI_VOICE_IP_END_SIP_CODE_ARRAY_MAX_V02 7
#define QMI_VOICE_IP_HIST_INFO_ARRAY_MAX_V02 7
#define QMI_VOICE_REMOTE_PARTY_CONF_CAP_ARRAY_MAX_V02 7
#define QMI_VOICE_RTT_MODE_ARRAY_MAX_V02 7
#define QMI_VOICE_ALTERNATE_SIP_URI_ARRAY_MAX_V02 7
#define QMI_VOICE_IP_ALERT_INFO_ARRAY_MAX_V02 7
#define QMI_VOICE_TERMINATING_ARRAY_MAX_V02 7
#define QMI_VOICE_EMERG_SRV_CATEG_ARRAY_MAX_V02 7
#define QMI_VOICE_MAX_BARRED_NUMBERS_LIST_V02 50
#define GET_CALL_FORWARDING_INFO_MAX_V02 13
#define QMI_VOICE_USS_DATA_MAX_V02 182
#define QMI_VOICE_AOC_CALL_METER_INFO_ACM_BIT_V02 0
#define QMI_VOICE_AOC_CALL_METER_INFO_ACMMAX_BIT_V02 1
#define QMI_VOICE_AOC_CALL_METER_INFO_CCM_BIT_V02 2
#define QMI_VOICE_SET_SUPS_SERVICE_RSEP_V02 0x0033
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Sets the registration state for different QMI_VOICE indications
             for the requesting control point. */
typedef struct {

  /* Optional */
  /*  DTMF Events */
  uint8_t reg_dtmf_events_valid;  /**< Must be set to true if reg_dtmf_events is being passed */
  uint8_t reg_dtmf_events;
  /**<   Values: \n
       - 0x00 -- Disable (default) \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  Voice Privacy Events */
  uint8_t reg_voice_privacy_events_valid;  /**< Must be set to true if reg_voice_privacy_events is being passed */
  uint8_t reg_voice_privacy_events;
  /**<   Values: \n
       - 0x00 -- Disable (default) \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  Supplementary Service Notification Events** */
  uint8_t supps_notification_events_valid;  /**< Must be set to true if supps_notification_events is being passed */
  uint8_t supps_notification_events;
  /**<   Values: \n
       - 0x00 -- Disable (default) \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  Call Notification Events */
  uint8_t call_events_valid;  /**< Must be set to true if call_events is being passed */
  uint8_t call_events;
  /**<   Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable (default)
  */

  /* Optional */
  /*  Handover Events */
  uint8_t handover_events_valid;  /**< Must be set to true if handover_events is being passed */
  uint8_t handover_events;
  /**<   Values: \n
       - 0x00 -- Disable (default) \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  Speech Codec Events */
  uint8_t speech_events_valid;  /**< Must be set to true if speech_events is being passed */
  uint8_t speech_events;
  /**<   Values: \n
       - 0x00 -- Disable (default) \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  USSD Notification Events */
  uint8_t ussd_notification_events_valid;  /**< Must be set to true if ussd_notification_events is being passed */
  uint8_t ussd_notification_events;
  /**<   Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable (default)
  */

  /* Optional */
  /*  Sups Events */
  uint8_t sups_events_valid;  /**< Must be set to true if sups_events is being passed */
  uint8_t sups_events;
  /**<   Reserved for future use.
  */

  /* Optional */
  /*  Modification Events */
  uint8_t modification_events_valid;  /**< Must be set to true if modification_events is being passed */
  uint8_t modification_events;
  /**<   Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable (default)
  */

  /* Optional */
  /*  UUS Events */
  uint8_t uus_events_valid;  /**< Must be set to true if uus_events is being passed */
  uint8_t uus_events;
  /**<   Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable (default)
  */

  /* Optional */
  /*  AOC Events */
  uint8_t aoc_events_valid;  /**< Must be set to true if aoc_events is being passed */
  uint8_t aoc_events;
  /**<   Values: \n
       - 0x00 -- Disable (default) \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  Conference Events */
  uint8_t conference_events_valid;  /**< Must be set to true if conference_events is being passed */
  uint8_t conference_events;
  /**<   Values: \n
       - 0x00 -- Disable (default) \n
       - 0x01 -- Enable 
  */

  /* Optional */
  /*  Extended Burst Type International Information Events */
  uint8_t ext_brst_intl_events_valid;  /**< Must be set to true if ext_brst_intl_events is being passed */
  uint8_t ext_brst_intl_events;
  /**<   Values: \n
       - 0x00 -- Disable (default) \n
       - 0x01 -- Enable 
  */

  /* Optional */
  /*  MT Page Miss Information Event */
  uint8_t page_miss_events_valid;  /**< Must be set to true if page_miss_events is being passed */
  uint8_t page_miss_events;
  /**<   Values: \n
       - 0x00 -- Disable (default) \n
       - 0x01 -- Enable 
  */

  /* Optional */
  /*  Call Control Result Information Event */
  uint8_t cc_result_events_valid;  /**< Must be set to true if cc_result_events is being passed */
  uint8_t cc_result_events;
  /**<   Values: \n
       - 0x00 -- Disable (default) \n
       - 0x01 -- Enable 
  */

  /* Optional */
  /*  Conference Participants Event */
  uint8_t conf_participants_events_valid;  /**< Must be set to true if conf_participants_events is being passed */
  uint8_t conf_participants_events;
  /**<   Values: \n
       - 0x00 -- Disable (default) \n
       - 0x01 -- Enable 
  */

  /* Optional */
  /*  TTY Info Events */
  uint8_t tty_info_events_valid;  /**< Must be set to true if tty_info_events is being passed */
  uint8_t tty_info_events;
  /**<   Values: \n
       - 0x00 -- Disable (default) \n
       - 0x01 -- Enable 
  */

  /* Optional */
  /*  E911 Call Origination Failure Events */
  uint8_t orig_fail_events_valid;  /**< Must be set to true if orig_fail_events is being passed */
  uint8_t orig_fail_events;
  /**<   Values: \n
       - 0x00 -- Disable (default) \n
       - 0x01 -- Enable 
  */

  /* Optional */
  /*  Videoshare Status Events */
  uint8_t vs_status_events_valid;  /**< Must be set to true if vs_status_events is being passed */
  uint8_t vs_status_events;
  /**<   Values: \n
       - 0x00 -- Disable (default) \n
       - 0x01 -- Enable 
  */

  /* Optional */
  /*  Audio RAT Change Events */
  uint8_t audio_rat_change_events_valid;  /**< Must be set to true if audio_rat_change_events is being passed */
  uint8_t audio_rat_change_events;
  /**<   Values: \n
       - 0x00 -- Disable (default) \n
       - 0x01 -- Enable 
  */

  /* Optional */
  /*  Additional Call Information Events */
  uint8_t additional_call_info_events_valid;  /**< Must be set to true if additional_call_info_events is being passed */
  uint8_t additional_call_info_events;
  /**<   Values: \n
       - 0x00 -- Disable (default) \n
       - 0x01 -- Enable 
  */

  /* Optional */
  /*  eCall Status Events */
  uint8_t ecall_status_events_valid;  /**< Must be set to true if ecall_status_events is being passed */
  uint8_t ecall_status_events;
  /**<   Values: \n
       - 0x00 -- Disable (default) \n
       - 0x01 -- Enable 
  */

  /* Optional */
  /*  Call Reestablishment Status */
  uint8_t call_reestab_status_events_valid;  /**< Must be set to true if call_reestab_status_events is being passed */
  uint8_t call_reestab_status_events;
  /**<   Values: \n
       - 0x00 -- Disable (default) \n
       - 0x01 -- Enable 
  */

  /* Optional */
  /*  VICE (VoLTE over Internet Connected Endpoint) Dialog Info */
  uint8_t vice_dialog_event_valid;  /**< Must be set to true if vice_dialog_event is being passed */
  uint8_t vice_dialog_event;
  /**<   Values: \n
       - 0x00 -- Disable (default) \n
       - 0x01 -- Enable 
  */

  /* Optional */
  /*  eCall Operating Mode Events */
  uint8_t ecall_oprt_mode_events_valid;  /**< Must be set to true if ecall_oprt_mode_events is being passed */
  uint8_t ecall_oprt_mode_events;
  /**<   Values: \n
       - 0x00 -- Disable (default) \n
       - 0x01 -- Enable 
  */

  /* Optional */
  /*  Auto Rejected Incoming Call End  */
  uint8_t auto_rejected_incoming_call_end_event_valid;  /**< Must be set to true if auto_rejected_incoming_call_end_event is being passed */
  uint8_t auto_rejected_incoming_call_end_event;
  /**<   Values: \n
	   - 0x00 -- Disable (default) \n
	   - 0x01 -- Enable
    */
}voice_indication_register_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Sets the registration state for different QMI_VOICE indications
             for the requesting control point. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}voice_indication_register_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  IP_PI_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  IP_PRESENTATION_NUM_ALLOWED_V02 = 0x00, 
  IP_PRESENTATION_NUM_RESTRICTED_V02 = 0x01, 
  IP_PI_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}ip_pi_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  UUS_TYPE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UUS_TYPE_DATA_V02 = 0x00, 
  UUS_TYPE1_IMPLICIT_V02 = 0x01, 
  UUS_TYPE1_REQUIRED_V02 = 0x02, 
  UUS_TYPE1_NOT_REQUIRED_V02 = 0x03, 
  UUS_TYPE2_REQUIRED_V02 = 0x04, 
  UUS_TYPE2_NOT_REQUIRED_V02 = 0x05, 
  UUS_TYPE3_REQUIRED_V02 = 0x06, 
  UUS_TYPE3_NOT_REQUIRED_V02 = 0x07, 
  UUS_TYPE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uus_type_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  UUS_DCS_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UUS_DCS_USP_V02 = 0x01, 
  UUS_DCS_OHLP_V02 = 0x02, 
  UUS_DCS_X244_V02 = 0x03, 
  UUS_DCS_SMCF_V02 = 0x04, 
  UUS_DCS_IA5_V02 = 0x05, 
  UUS_DCS_RV12RD_V02 = 0x06, 
  UUS_DCS_Q931UNCCM_V02 = 0x07, 
  UUS_DCS_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uus_dcs_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uus_type_enum_v02 uus_type;
  /**<   UUS type. Values: \n
       - 0x00 -- UUS_TYPE_DATA -- Data \n
       - 0x01 -- UUS_TYPE1_IMPLICIT -- Type 1 implicit \n
       - 0x02 -- UUS_TYPE1_REQUIRED -- Type 1 required \n
       - 0x03 -- UUS_TYPE1_NOT_REQUIRED -- Type 1 not required \n
       - 0x04 -- UUS_TYPE2_REQUIRED -- Type 2 required \n
       - 0x05 -- UUS_TYPE2_NOT_REQUIRED -- Type 2 not required \n
       - 0x06 -- UUS_TYPE3_REQUIRED -- Type 3 required \n
       - 0x07 -- UUS_TYPE3_NOT_REQUIRED -- Type 3 not required
  */

  uus_dcs_enum_v02 uus_dcs;
  /**<   UUS data coding scheme. Values: \n
       - 0x01 -- UUS_DCS_USP -- USP \n
       - 0x02 -- UUS_DCS_OHLP -- OHLP \n
       - 0x03 -- UUS_DCS_X244 -- X244 \n
       - 0x04 -- UUS_DCS_SMCF -- SMCF \n
       - 0x05 -- UUS_DCS_IA5 -- IA5 \n
       - 0x06 -- UUS_DCS_RV12RD -- RV12RD \n
       - 0x07 -- UUS_DCS_Q931UNCCM -- Q931UNCCM
  */

  uint32_t uus_data_len;  /**< Must be set to # of elements in uus_data */
  uint8_t uus_data[QMI_VOICE_UUS_DATA_MAX_V02];
  /**<   UUS data encoded per the coding scheme.
  */
}voice_uus_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t cug_index;
  /**<   CUG index. Range: 0x00 to 0x7FFF.
  */

  uint8_t suppress_pref_cug;
  /**<   Suppress preferential CUG. Values: \n
       - 0x00 -- FALSE \n
       - 0x01 -- TRUE
  */

  uint8_t suppress_oa;
  /**<   Suppress OA subscription option. Values: \n
       - 0x00 -- FALSE \n
       - 0x01 -- TRUE
  */
}voice_cug_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  CLIR_TYPE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  CLIR_SUPPRESSION_V02 = 0x01, 
  CLIR_INVOCATION_V02 = 0x02, 
  CLIR_TYPE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}clir_type_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  SUBADDRESS_TYPE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  SUBADDRESS_TYPE_NSAP_V02 = 0x00, 
  SUBADDRESS_TYPE_USER_V02 = 0x01, 
  SUBADDRESS_TYPE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}subaddress_type_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t extension_bit;
  /**<   Extension bit.
  */

  subaddress_type_enum_v02 subaddress_type;
  /**<   Subaddress type. Values: \n
       - 0x00 -- NSAP \n
       - 0x01 -- USER
  */

  uint8_t odd_even_ind;
  /**<   Even/odd indicator. Values: \n
       - 0x00 -- Even number of address signals \n
       - 0x01 -- Odd number of address signals
  */

  uint32_t subaddress_len;  /**< Must be set to # of elements in subaddress */
  uint8_t subaddress[QMI_VOICE_SUBADDRESS_LEN_MAX_V02];
  /**<   Array of the subaddress in BCD number format; refer to 
       \hyperref[STD-24008]{3GPP TS 24.008} Table 10.5.119 for valid data.
  */
}voice_subaddress_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique identifier for the call.
  */

  voice_subaddress_type_v02 subaddress_info;
  /**<   Subaddress information for the call.
  */
}voice_subaddress_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_DIAL_CALL_SERVICE_TYPE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_DIAL_CALL_SRV_TYPE_AUTOMATIC_V02 = 0x01, 
  VOICE_DIAL_CALL_SRV_TYPE_GSM_V02 = 0x02, 
  VOICE_DIAL_CALL_SRV_TYPE_WCDMA_V02 = 0x03, 
  VOICE_DIAL_CALL_SRV_TYPE_CDMA_AUTOMATIC_V02 = 0x04, 
  VOICE_DIAL_CALL_SRV_TYPE_GSM_WCDMA_V02 = 0x05, 
  VOICE_DIAL_CALL_SRV_TYPE_LTE_V02 = 0x06, 
  VOICE_DIAL_CALL_SRV_TYPE_TDSCDMA_V02 = 0x07, 
  VOICE_DIAL_CALL_SRV_TYPE_GSM_WCDMA_TDSCDMA_V02 = 0x08, 
  VOICE_DIAL_CALL_SRV_TYPE_CS_ONLY_V02 = 0x09, 
  VOICE_DIAL_CALL_SERVICE_TYPE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_dial_call_service_type_enum_v02;
/**
    @}
  */

typedef uint64_t voice_call_attribute_type_mask_v02;
#define VOICE_CALL_ATTRIB_TX_V02 ((voice_call_attribute_type_mask_v02)0x01ull) /**<  Transmission \n  */
#define VOICE_CALL_ATTRIB_RX_V02 ((voice_call_attribute_type_mask_v02)0x02ull) /**<  Receiving \n  */
#define VOICE_CALL_ATTRIB_NO_CHANGE_V02 ((voice_call_attribute_type_mask_v02)0x80ull) /**<  No change  */
/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VS_VARIANT_TYPE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VS_VARIANT_RCS_E_V02 = 0x01, /**<  RCSe \n  */
  VS_VARIANT_RCS_V5_V02 = 0x02, /**<  RCSv5  */
  VS_VARIANT_TYPE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}vs_variant_type_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  vs_variant_type_enum_v02 vs_variant;
  /**<   Call variant. Values: \n
      - VS_VARIANT_RCS_E (0x01) --  RCSe \n 
      - VS_VARIANT_RCS_V5 (0x02) --  RCSv5 
 */

  char file_attributes[QMI_VOICE_VS_FILE_ATTRIBUTES_MAX_V02 + 1];
  /**<   File attributes as an ASCII string. 
       Length range: 0 to 500.       
   */
}voice_videoshare_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  ECALL_VARIANT_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  ECALL_TEST_V02 = 0x01, /**<  Test eCall \n  */
  ECALL_EMERGENCY_V02 = 0x02, /**<  Emergency eCall \n  */
  ECALL_RECONFIG_V02 = 0x03, /**<  Reconfig eCall  */
  ECALL_VOICE_V02 = 0x04, /**<  Voice eCall  */
  ECALL_VARIANT_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}ecall_variant_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique identifier for the call.
  */

  uint8_t is_secure_call;
  /**<   Whether the call is a secure call; boolean value.
  */
}voice_volte_is_secure_call_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique identifier for the call.
  */

  uint8_t is_called_party_ringing;
  /**<   True if the called party is being alerted and ringing.
  */
}voice_volte_is_called_party_ringing_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  RTT_MODE_TYPE_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  RTT_MODE_DISABLED_V02 = 0, /**<  non-RTT call \n  */
  RTT_MODE_FULL_V02 = 1, /**<  RTT call with RTT being used from both sides  */
  RTT_MODE_TYPE_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}rtt_mode_type_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Originates a voice call (MO call). */
typedef struct {

  /* Mandatory */
  /*  Calling Number or SIP URI */
  char calling_number[QMI_VOICE_NUMBER_MAX_V02 + 1];
  /**<   Number to be dialed in ASCII string. 
       Length range: 1 to 81.
  */

  /* Optional */
  /*  Call Type */
  uint8_t call_type_valid;  /**< Must be set to true if call_type is being passed */
  call_type_enum_v02 call_type;
  /**<   Call type. Values: \n
       - 0x00 -- CALL_TYPE_VOICE         -- Voice (automatic selection) \n
       - 0x01 -- CALL_TYPE_VOICE_FORCED  -- Avoid modem call classification \n
       - 0x02 -- CALL_TYPE_VOICE_IP      -- Voice call over IP \n
       - 0x03 -- CALL_TYPE_VT            -- Videotelephony call over IP \n
       - 0x04 -- CALL_TYPE_VIDEOSHARE    -- Videoshare \n
       - 0x08 -- CALL_TYPE_NON_STD_OTASP -- Nonstandard OTASP* \n
       - 0x09 -- CALL_TYPE_EMERGENCY     -- Emergency \n
       - 0x0C -- CALL_TYPE_ECALL         -- eCall \n
       - 0x0D -- CALL_TYPE_EMERGENCY_VT  -- Emergency videotelephony call over IP
  */

  /* Optional */
  /*  CLIR in Temporary Mode** */
  uint8_t clir_type_valid;  /**< Must be set to true if clir_type is being passed */
  clir_type_enum_v02 clir_type;
  /**<   CLIR type. Values: \n
       - 0x01 -- CLIR_SUPPRESSION -- Suppression \n
       - 0x02 -- CLIR_INVOCATION -- Invocation
  */

  /* Optional */
  /*  UUS** */
  uint8_t uus_valid;  /**< Must be set to true if uus is being passed */
  voice_uus_type_v02 uus;

  /* Optional */
  /*  CUG** */
  uint8_t cug_valid;  /**< Must be set to true if cug is being passed */
  voice_cug_type_v02 cug;

  /* Optional */
  /*  Emergency Category */
  uint8_t emer_cat_valid;  /**< Must be set to true if emer_cat is being passed */
  uint8_t emer_cat;
  /**<   Bitmask of emergency number categories. Values: \n
       - Bit 0 -- VOICE_EMER_CAT_POLICE_BIT -- Police \n
       - Bit 1 -- VOICE_EMER_CAT_AMBULANCE_ BIT -- Ambulance \n
       - Bit 2 -- VOICE_EMER_CAT_FIRE_ BRIGADE_BIT -- Fire brigade \n
       - Bit 3 -- VOICE_EMER_CAT_MARINE_ GUARD_ BIT -- Marine guard \n
       - Bit 4 -- VOICE_EMER_CAT_ MOUNTAIN_ RESCUE_BIT -- Mountain rescue \n
       - Bit 5 -- VOICE_EMER_CAT_MANUAL_ ECALL_BIT -- Manual emergency call \n
       - Bit 6 -- VOICE_EMER_CAT_AUTO_ECALL_ BIT -- Automatic emergency call \n
       - Bit 7 -- VOICE_EMER_CAT_SPARE_BIT -- Spare bit
  */

  /* Optional */
  /*  Called Party Subaddress */
  uint8_t called_party_subaddress_valid;  /**< Must be set to true if called_party_subaddress is being passed */
  voice_subaddress_type_v02 called_party_subaddress;

  /* Optional */
  /*  Service Type */
  uint8_t service_type_valid;  /**< Must be set to true if service_type is being passed */
  voice_dial_call_service_type_enum_v02 service_type;
  /**<   Service type. Values: \n
       - 0x01 -- VOICE_DIAL_CALL_SRV_TYPE_ AUTOMATIC -- Automatic \n
       - 0x02 -- VOICE_DIAL_CALL_SRV_TYPE_ GSM -- GSM \n
       - 0x03 -- VOICE_DIAL_CALL_SRV_TYPE_ WCDMA -- WCDMA \n
       - 0x04 -- VOICE_DIAL_CALL_SRV_TYPE_ CDMA_AUTOMATIC -- CDMA automatic \n
       - 0x05 -- VOICE_DIAL_CALL_SRV_TYPE_ GSM_WCDMA -- GSM or WCDMA \n
       - 0x06 -- VOICE_DIAL_CALL_SRV_TYPE_ LTE -- LTE \n
       - 0x07 -- VOICE_DIAL_CALL_SRV_TYPE_ TDSCDMA -- TD-SCDMA \n
       - 0x08 -- VOICE_DIAL_CALL_SRV_TYPE_ GSM_WCDMA_TDSCDMA -- GSM or WCDMA or TD-SCDMA \n
       - 0x09 -- VOICE_DIAL_CALL_SRV_TYPE_ CS_ONLY -- Circuit-switched domain
  */

  /* Optional */
  /*  SIP URI Overflow  */
  uint8_t sip_uri_overflow_valid;  /**< Must be set to true if sip_uri_overflow is being passed */
  char sip_uri_overflow[QMI_VOICE_SIP_URI_OVERFLOW_MAX_V02 + 1];
  /**<   When dialing an SIP URI number, if the length exceeds 81 ASCII characters,
       this holds the additional overflow SIP URI number as an ASCII string. 
       Length range: 1 to 47.
  */

  /* Optional */
  /*  Audio Attribute for VT or VOIP Call */
  uint8_t audio_attrib_valid;  /**< Must be set to true if audio_attrib is being passed */
  voice_call_attribute_type_mask_v02 audio_attrib;
  /**<   Bitmask of call attributes. Values: \n
       - Bit 0 (0x01) -- VOICE_CALL_ATTRIB_TX -- Transmission \n
       - Bit 1 (0x02) -- VOICE_CALL_ATTRIB_RX -- Receiving
  */

  /* Optional */
  /*  Video Attribute for VT or VOIP Call */
  uint8_t video_attrib_valid;  /**< Must be set to true if video_attrib is being passed */
  voice_call_attribute_type_mask_v02 video_attrib;
  /**<   Bitmask of call attributes. Values: \n
       - Bit 0 (0x01) -- VOICE_CALL_ATTRIB_TX -- Transmission \n
       - Bit 1 (0x02) -- VOICE_CALL_ATTRIB_RX -- Receiving
  */

  /* Optional */
  /*  Presentation Indicator for VT or VOIP Call */
  uint8_t pi_valid;  /**< Must be set to true if pi is being passed */
  ip_pi_enum_v02 pi;
  /**<   Presentation indicator for a VT or VoIP call. Values: \n
       - 0x00 -- IP_PRESENTATION_NUM_ ALLOWED -- Allowed \n
       - 0x01 -- IP_PRESENTATION_NUM_ RESTRICTED -- Restricted
  */

  /* Optional */
  /*  Call Attributes for Videoshare Call */
  uint8_t videoshare_call_attribs_valid;  /**< Must be set to true if videoshare_call_attribs is being passed */
  voice_videoshare_type_v02 videoshare_call_attribs;

  /* Optional */
  /*  eCall Variant */
  uint8_t ecall_variant_valid;  /**< Must be set to true if ecall_variant is being passed */
  ecall_variant_enum_v02 ecall_variant;
  /**<   eCall variant. Values: \n
      - ECALL_TEST (0x01) --  Test eCall \n 
      - ECALL_EMERGENCY (0x02) --  Emergency eCall \n 
      - ECALL_RECONFIG (0x03) --  Reconfig eCall 
      - ECALL_VOICE (0x04) --  Voice eCall 
 */

  /* Optional */
  /*  Conference URI List */
  uint8_t conf_uri_list_valid;  /**< Must be set to true if conf_uri_list is being passed */
  char conf_uri_list[QMI_VOICE_CONF_URI_LIST_MAX_LEN_V02 + 1];
  /**<   Participants' URI list for initiating a conference call; ASCII string.
       Length range: 1 to 1024.
  */

  /* Optional */
  /*  Display Text */
  uint8_t display_text_valid;  /**< Must be set to true if display_text is being passed */
  uint32_t display_text_len;  /**< Must be set to # of elements in display_text */
  uint16_t display_text[QMI_VOICE_DISPLAY_TEXT_MAX_LEN_V02];
  /**<   Display text. This text can contain up to 98 UTF-16 characters
       and it is not guaranteed to be NULL terminated.
       Length range: 0 to 98.
  */

  /* Optional */
  /*  eCall MSD */
  uint8_t ecall_msd_valid;  /**< Must be set to true if ecall_msd is being passed */
  uint32_t ecall_msd_len;  /**< Must be set to # of elements in ecall_msd */
  uint8_t ecall_msd[QMI_VOICE_ECALL_MSD_MAX_LEN_V02];
  /**<   eCall Minimum Set of Data (MSD) can contain up to 140-byte
       ASN.1 unaligned PER data as described in 
       \hyperref[CEN-EN-15722]{CEN EN 15722}.
       Length range: 1 to 140.
  */

  /* Optional */
  /*  Call Pulled from Secondary Device to Primary */
  uint8_t call_pull_valid;  /**< Must be set to true if call_pull is being passed */
  uint8_t call_pull;
  /**<   Call is pulled from a secondary device. Values: \n
       - 0x00 -- FALSE \n
       - 0x01 -- TRUE
  */

  /* Optional */
  /*  Codec Profile */
  uint8_t codec_profile_valid;  /**< Must be set to true if codec_profile is being passed */
  uint8_t codec_profile;
  /**<   Codec profile number of the IP call.
  */

  /* Optional */
  /*  Is Secure Call */
  uint8_t is_secure_call_valid;  /**< Must be set to true if is_secure_call is being passed */
  uint8_t is_secure_call;
  /**<   Whether the call is a secure call; boolean value.
  */

  /* Optional */
  /*  RTT Attribute for VT or VOIP Call */
  uint8_t rtt_mode_valid;  /**< Must be set to true if rtt_mode is being passed */
  rtt_mode_type_v02 rtt_mode;
  /**<   Whether the current call is an RTT call. Values: \n
      - RTT_MODE_DISABLED (0) --  non-RTT call \n 
      - RTT_MODE_FULL (1) --  RTT call with RTT being used from both sides 
 */

  /* Optional */
  /*  Origination Number */
  uint8_t origination_number_valid;  /**< Must be set to true if origination_number is being passed */
  char origination_number[QMI_VOICE_NUMBER_MAX_V02 + 1];
  /**<   Secondary number of the calling party in ASCII string. \n
       Length range is 1 to 81.
  */

  /* Optional */
  /*  Is Secondary	  */
  uint8_t is_secondary_valid;  /**< Must be set to true if is_secondary is being passed */
  uint8_t is_secondary;
  /**<   Whether the call is being originated on a secondary line. \n
       Set to FALSE by default.
  */

  /* Optional */
  /*  Is TRN Available  */
  uint8_t is_trn_avail_valid;  /**< Must be set to true if is_trn_avail is being passed */
  uint8_t is_trn_avail;
  /**<   Whether the temporary reference number (TRN) is avaialble for the secondary line. \n
       Set to FALSE by default.
  */
}voice_dial_call_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  ALPHA_DCS_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  ALPHA_DCS_GSM_V02 = 0x01, 
  ALPHA_DCS_UCS2_V02 = 0x02, 
  ALPHA_DCS_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}alpha_dcs_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  alpha_dcs_enum_v02 alpha_dcs;
  /**<   Alpha coding scheme. Values: \n
       - 0x01 -- ALPHA_DCS_GSM  -- SMS default 7-bit coded alphabet as defined 
                 in \hyperref[STD-23038]{3GPP TS 23.038} with bit 8 set to 0 \n
       - 0x02 -- ALPHA_DCS_UCS2 -- UCS2
  */

  uint32_t alpha_text_len;  /**< Must be set to # of elements in alpha_text */
  uint8_t alpha_text[QMI_VOICE_ALPHA_TEXT_MAX_V02];
  /**<   Data encoded per alpha_dcs.
  */
}voice_alpha_ident_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_CC_SUPS_RESULT_SERVICE_TYPE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_CC_SUPS_RESULT_SERVICE_TYPE_ACTIVATE_V02 = 0x01, 
  VOICE_CC_SUPS_RESULT_SERVICE_TYPE_DEACTIVATE_V02 = 0x02, 
  VOICE_CC_SUPS_RESULT_SERVICE_TYPE_REGISTER_V02 = 0x03, 
  VOICE_CC_SUPS_RESULT_SERVICE_TYPE_ERASE_V02 = 0x04, 
  VOICE_CC_SUPS_RESULT_SERVICE_TYPE_INTERROGATE_V02 = 0x05, 
  VOICE_CC_SUPS_RESULT_SERVICE_TYPE_REGISTER_PASSWORD_V02 = 0x06, 
  VOICE_CC_SUPS_RESULT_SERVICE_TYPE_USSD_V02 = 0x07, 
  VOICE_CC_SUPS_RESULT_SERVICE_TYPE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_cc_sups_result_service_type_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_CC_SUPS_RESULT_REASON_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_CC_SUPS_RESULT_REASON_NONE_V02 = 0x00, 
  VOICE_CC_SUPS_RESULT_REASON_FWD_UNCONDITIONAL_V02 = 0x01, 
  VOICE_CC_SUPS_RESULT_REASON_FWD_MOBILEBUSY_V02 = 0x02, 
  VOICE_CC_SUPS_RESULT_REASON_FWD_NOREPLY_V02 = 0x03, 
  VOICE_CC_SUPS_RESULT_REASON_FWD_UNREACHABLE_V02 = 0x04, 
  VOICE_CC_SUPS_RESULT_REASON_FWD_ALLFORWARDING_V02 = 0x05, 
  VOICE_CC_SUPS_RESULT_REASON_FWD_ALLCONDITIONAL_V02 = 0x06, 
  VOICE_CC_SUPS_RESULT_REASON_BARR_ALLOUTGOING_V02 = 0x07, 
  VOICE_CC_SUPS_RESULT_REASON_BARR_OUTGOINGINT_V02 = 0x08, 
  VOICE_CC_SUPS_RESULT_REASON_BARR_OUTGOINGINTEXTOHOME_V02 = 0x09, 
  VOICE_CC_SUPS_RESULT_REASON_BARR_ALLINCOMING_V02 = 0x0A, 
  VOICE_CC_SUPS_RESULT_REASON_BARR_INCOMINGROAMING_V02 = 0x0B, 
  VOICE_CC_SUPS_RESULT_REASON_BARR_ALLBARRING_V02 = 0x0C, 
  VOICE_CC_SUPS_RESULT_REASON_BARR_ALLOUTGOINGBARRING_V02 = 0x0D, 
  VOICE_CC_SUPS_RESULT_REASON_BARR_ALLINCOMINGBARRING_V02 = 0x0E, 
  VOICE_CC_SUPS_RESULT_REASON_CALLWAITING_V02 = 0x0F, 
  VOICE_CC_SUPS_RESULT_REASON_CLIP_V02 = 0x10, 
  VOICE_CC_SUPS_RESULT_REASON_CLIR_V02 = 0x11, 
  VOICE_CC_SUPS_RESULT_REASON_COLP_V02 = 0x12, 
  VOICE_CC_SUPS_RESULT_REASON_COLR_V02 = 0x13, 
  VOICE_CC_SUPS_RESULT_REASON_CNAP_V02 = 0x14, 
  VOICE_CC_SUPS_RESULT_REASON_BARR_INCOMING_NUMBER_V02 = 0x15, 
  VOICE_CC_SUPS_RESULT_REASON_BARR_INCOMING_ANONYMOUS_V02 = 0x16, 
  VOICE_CC_SUPS_RESULT_REASON_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_cc_sups_result_reason_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  voice_cc_sups_result_service_type_enum_v02 service_type;
  /**<   Service type. Values: \n 
       - 0x01 -- VOICE_CC_SUPS_RESULT_ SERVICE_TYPE_ACTIVATE -- Activate \n
       - 0x02 -- VOICE_CC_SUPS_RESULT_ SERVICE_TYPE_DEACTIVATE -- Deactivate \n
       - 0x03 -- VOICE_CC_SUPS_RESULT_ SERVICE_TYPE_REGISTER -- Register \n
       - 0x04 -- VOICE_CC_SUPS_RESULT_ SERVICE_TYPE_ERASE -- Erase \n
       - 0x05 -- VOICE_CC_SUPS_RESULT_ SERVICE_TYPE_INTERROGATE -- Interrogate \n
       - 0x06 -- VOICE_CC_SUPS_RESULT_ SERVICE_TYPE_REGISTER_PASSWORD -- Register password \n
       - 0x07 -- VOICE_CC_SUPS_RESULT_ SERVICE_TYPE_USSD -- USSD
  */

  voice_cc_sups_result_reason_enum_v02 reason;
  /**<   Call control supplementary service result reason;
       see Table @latexonly\ref{tbl:ccSupsResultReason}@endlatexonly 
       for more information.
  */
}voice_cc_sups_result_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_CC_RESULT_TYPE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_CC_RESULT_TYPE_VOICE_V02 = 0x00, /**<  VOICE \n  */
  VOICE_CC_RESULT_TYPE_SUPS_V02 = 0x01, /**<  SUPS \n  */
  VOICE_CC_RESULT_TYPE_USSD_V02 = 0x02, /**<  USSD \n  */
  VOICE_CC_RESULT_TYPE_VT_V02 = 0x03, /**<  VT  */
  VOICE_CC_RESULT_TYPE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_cc_result_type_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Originates a voice call (MO call). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Call ID */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Unique call identifier for the dialed call
  */

  /* Optional */
  /*  Alpha Identifier */
  uint8_t alpha_ident_valid;  /**< Must be set to true if alpha_ident is being passed */
  voice_alpha_ident_type_v02 alpha_ident;

  /* Optional */
  /*  Call Control Result Type */
  uint8_t cc_result_type_valid;  /**< Must be set to true if cc_result_type is being passed */
  voice_cc_result_type_enum_v02 cc_result_type;
  /**<   Values: \n
      - VOICE_CC_RESULT_TYPE_VOICE (0x00) --  VOICE \n 
      - VOICE_CC_RESULT_TYPE_SUPS (0x01) --  SUPS \n 
      - VOICE_CC_RESULT_TYPE_USSD (0x02) --  USSD \n 
      - VOICE_CC_RESULT_TYPE_VT (0x03) --  VT 
 */

  /* Optional */
  /*  Call Control Supplementary Service Type */
  uint8_t cc_sups_result_valid;  /**< Must be set to true if cc_sups_result is being passed */
  voice_cc_sups_result_type_v02 cc_sups_result;
  /**<   (Supplementary service data that resulted from call control;
       data is present when cc_result_type is present and is other than Voice.)
  */

  /* Optional */
  /*  End Reason  */
  uint8_t end_reason_valid;  /**< Must be set to true if end_reason is being passed */
  call_end_reason_enum_v02 end_reason;
  /**<   Call end reason; 
       see @latexonly Table~\ref{tbl:endReasons}@endlatexonly for a list of 
       valid voice-related call end reasons. 
  */

  /* Optional */
  /*  Media ID  */
  uint8_t media_id_valid;  /**< Must be set to true if media_id is being passed */
  uint8_t media_id;
  /**<   Media ID. 
  */
}voice_dial_call_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_REJECT_CAUSE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_REJECT_CAUSE_USER_BUSY_V02 = 0x01, /**<  User is busy \n  */
  VOICE_REJECT_CAUSE_USER_REJECT_V02 = 0x02, /**<  User has rejected the call \n  */
  VOICE_REJECT_CAUSE_LOW_BATTERY_V02 = 0x03, /**<  Call was rejected due to a low battery \n  */
  VOICE_REJECT_CAUSE_BLACKLISTED_CALL_ID_V02 = 0x04, /**<  Call was rejected because the number was blacklisted \n  */
  VOICE_REJECT_CAUSE_DEAD_BATTERY_V02 = 0x05, /**<  Call was rejected due to a dead battery  */
  VOICE_REJECT_CAUSE_UNWANTED_CALL_V02 = 0x06, /**<  Call was rejected because the call was an unwanted robo call  */
  VOICE_REJECT_CAUSE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_reject_cause_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Ends a voice call. */
typedef struct {

  /* Mandatory */
  /*  Call ID */
  uint8_t call_id;
  /**<   Unique call identifier for the call that must be ended.
  */

  /* Optional */
  /*  End Cause */
  uint8_t end_cause_valid;  /**< Must be set to true if end_cause is being passed */
  voice_reject_cause_enum_v02 end_cause;
  /**<   Cause for ending the call. Values: \n
      - VOICE_REJECT_CAUSE_USER_BUSY (0x01) --  User is busy \n 
      - VOICE_REJECT_CAUSE_USER_REJECT (0x02) --  User has rejected the call \n 
      - VOICE_REJECT_CAUSE_LOW_BATTERY (0x03) --  Call was rejected due to a low battery \n 
      - VOICE_REJECT_CAUSE_BLACKLISTED_CALL_ID (0x04) --  Call was rejected because the number was blacklisted \n 
      - VOICE_REJECT_CAUSE_DEAD_BATTERY (0x05) --  Call was rejected due to a dead battery 
      - VOICE_REJECT_CAUSE_UNWANTED_CALL (0x06) --  Call was rejected because the call was an unwanted robo call  
 */
}voice_end_call_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Ends a voice call. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Call ID */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Unique call identifier for the call that must be ended.
  */
}voice_end_call_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Answers an incoming voice call. */
typedef struct {

  /* Mandatory */
  /*  Call ID */
  uint8_t call_id;
  /**<   Unique call identifier for the call that must be answered.
  */

  /* Optional */
  /*  Call Type */
  uint8_t call_type_valid;  /**< Must be set to true if call_type is being passed */
  call_type_enum_v02 call_type;
  /**<   Call type. Values: \n
       - 0x02 -- CALL_TYPE_VOICE_IP      -- Voice call over IP \n
       - 0x03 -- CALL_TYPE_VT            -- Videotelephony call over IP
  */

  /* Optional */
  /*  Audio Attribute for VT or VOIP Call */
  uint8_t audio_attrib_valid;  /**< Must be set to true if audio_attrib is being passed */
  voice_call_attribute_type_mask_v02 audio_attrib;
  /**<   Bitmask of call attributes. Values: \n
       - Bit 0 (0x01) -- VOICE_CALL_ATTRIB_TX -- Transmission \n
       - Bit 1 (0x02) -- VOICE_CALL_ATTRIB_RX -- Receiving
  */

  /* Optional */
  /*  Video Attribute for VT or VOIP Call */
  uint8_t video_attrib_valid;  /**< Must be set to true if video_attrib is being passed */
  voice_call_attribute_type_mask_v02 video_attrib;
  /**<   Bitmask of call attributes. Values: \n
       - Bit 0 (0x01) -- VOICE_CALL_ATTRIB_TX -- Transmission \n
       - Bit 1 (0x02) -- VOICE_CALL_ATTRIB_RX -- Receiving
  */

  /* Optional */
  /*  Presentation Indicator for VT or VOIP Call */
  uint8_t pi_valid;  /**< Must be set to true if pi is being passed */
  ip_pi_enum_v02 pi;
  /**<   Presentation indicator for a VT or VoIP call. Values: \n
       - 0x00 -- IP_PRESENTATION_NUM_ ALLOWED -- Allowed \n
       - 0x01 -- IP_PRESENTATION_NUM_ RESTRICTED -- Restricted
  */

  /* Optional */
  /*  File Attributes for Videoshare Call */
  uint8_t file_attributes_valid;  /**< Must be set to true if file_attributes is being passed */
  char file_attributes[QMI_VOICE_VS_FILE_ATTRIBUTES_MAX_V02 + 1];
  /**<   File attributes as an ASCII string.
       Length range: 0 to 500.       
   */

  /* Optional */
  /*  Reject Incoming Call */
  uint8_t reject_call_valid;  /**< Must be set to true if reject_call is being passed */
  uint8_t reject_call;
  /**<   Values: \n       
       - 0x01 -- Reject the call
  */

  /* Optional */
  /*  Reject Cause */
  uint8_t reject_cause_valid;  /**< Must be set to true if reject_cause is being passed */
  voice_reject_cause_enum_v02 reject_cause;
  /**<   Cause for rejecting the incoming call. Values: \n
      - VOICE_REJECT_CAUSE_USER_BUSY (0x01) --  User is busy \n 
      - VOICE_REJECT_CAUSE_USER_REJECT (0x02) --  User has rejected the call \n 
      - VOICE_REJECT_CAUSE_LOW_BATTERY (0x03) --  Call was rejected due to a low battery \n 
      - VOICE_REJECT_CAUSE_BLACKLISTED_CALL_ID (0x04) --  Call was rejected because the number was blacklisted \n 
      - VOICE_REJECT_CAUSE_DEAD_BATTERY (0x05) --  Call was rejected due to a dead battery 
      - VOICE_REJECT_CAUSE_UNWANTED_CALL (0x06) --  Call was rejected because the call was an unwanted robo call  
 */

  /* Optional */
  /*  SIP Reject Cause */
  uint8_t sip_reject_cause_valid;  /**< Must be set to true if sip_reject_cause is being passed */
  uint16_t sip_reject_cause;
  /**<   Cause for rejecting the incoming call.
       The SIP error code is as defined in \hyperref[RFC3261]{RFC3261}.
  */

  /* Optional */
  /*  Codec Profile */
  uint8_t codec_profile_valid;  /**< Must be set to true if codec_profile is being passed */
  uint8_t codec_profile;
  /**<   Codec profile number of the IP call.
  */

  /* Optional */
  /*  RTT Attribute for VT or VOIP Call */
  uint8_t rtt_mode_valid;  /**< Must be set to true if rtt_mode is being passed */
  rtt_mode_type_v02 rtt_mode;
  /**<   Whether the current call is an RTT call. Values: \n
      - RTT_MODE_DISABLED (0) --  non-RTT call \n 
      - RTT_MODE_FULL (1) --  RTT call with RTT being used from both sides 
 */
}voice_answer_call_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Answers an incoming voice call. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Call ID */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Unique call identifier for the call that must be answered
  */
}voice_answer_call_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Queries the information associated with a call. */
typedef struct {

  /* Mandatory */
  /*  Call ID */
  uint8_t call_id;
  /**<   Call identifier for the call to be queried for information.
  */
}voice_get_call_info_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  CALL_MODE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  CALL_MODE_NO_SRV_V02 = 0x00, /**<  No service \n  */
  CALL_MODE_CDMA_V02 = 0x01, /**<  CDMA \n  */
  CALL_MODE_GSM_V02 = 0x02, /**<  GSM \n  */
  CALL_MODE_UMTS_V02 = 0x03, /**<  UMTS \n  */
  CALL_MODE_LTE_V02 = 0x04, /**<  LTE \n  */
  CALL_MODE_TDS_V02 = 0x05, /**<  TD-SCDMA \n  */
  CALL_MODE_UNKNOWN_V02 = 0x06, /**<  Unknown \n  */
  CALL_MODE_WLAN_V02 = 0x07, /**<  WLAN  */
  CALL_MODE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}call_mode_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Call identifier for the call queried for information.
  */

  call_state_enum_v02 call_state;
  /**<   Call state. Values: \n
       - 0x01 -- CALL_STATE_ORIGINATION    -- Origination \n
       - 0x02 -- CALL_STATE_INCOMING       -- Incoming \n
       - 0x03 -- CALL_STATE_CONVERSATION   -- Conversation \n
       - 0x04 -- CALL_STATE_CC_IN_PROGRESS -- Call is originating but waiting \n
                                              for call control to complete \n
       - 0x05 -- CALL_STATE_ALERTING       -- Alerting \n
       - 0x06 -- CALL_STATE_HOLD           -- Hold \n
       - 0x07 -- CALL_STATE_WAITING        -- Waiting \n
       - 0x08 -- CALL_STATE_DISCONNECTING  -- Disconnecting \n
       - 0x09 -- CALL_STATE_END            -- End \n
       - 0x0A -- CALL_STATE_SETUP          -- MT call is in Setup state in 3GPP
  */

  call_type_enum_v02 call_type;
  /**<   Call type. Values: \n
       - 0x00 -- CALL_TYPE_VOICE         -- Voice \n
       - 0x02 -- CALL_TYPE_VOICE_IP      -- Voice over IP \n
       - 0x03 -- CALL_TYPE_VT            -- Videotelephony call over IP \n
       - 0x04 -- CALL_TYPE_VIDEOSHARE    -- Videoshare \n
       - 0x05 -- CALL_TYPE_TEST          -- Test call type \n
       - 0x06 -- CALL_TYPE_OTAPA         -- OTAPA \n
       - 0x07 -- CALL_TYPE_STD_OTASP     -- Standard OTASP \n
       - 0x08 -- CALL_TYPE_NON_STD_OTASP -- Nonstandard OTASP \n
       - 0x09 -- CALL_TYPE_EMERGENCY     -- Emergency \n       
       - 0x0B -- CALL_TYPE_EMERGENCY_IP  -- Emergency VoIP \n
       - 0x0D -- CALL_TYPE_EMERGENCY_VT  -- Emergency videotelephony call over IP
  */

  call_direction_enum_v02 direction;
  /**<   Direction. Values: \n
       - 0x01 -- CALL_DIRECTION_MO -- MO call \n
       - 0x02 -- CALL_DIRECTION_MT -- MT call
  */

  call_mode_enum_v02 mode;
  /**<   Mode. Values: \n
      - CALL_MODE_NO_SRV (0x00) --  No service \n 
      - CALL_MODE_CDMA (0x01) --  CDMA \n 
      - CALL_MODE_GSM (0x02) --  GSM \n 
      - CALL_MODE_UMTS (0x03) --  UMTS \n 
      - CALL_MODE_LTE (0x04) --  LTE \n 
      - CALL_MODE_TDS (0x05) --  TD-SCDMA \n 
      - CALL_MODE_UNKNOWN (0x06) --  Unknown \n 
      - CALL_MODE_WLAN (0x07) --  WLAN 
 */
}voice_call_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  pi_num_enum_v02 pi;
  /**<   Presentation indicator. Values: \n
       - 0x00 -- PRESENTATION_ALLOWED -- Allowed presentation \n
       - 0x01 -- PRESENTATION_RESTRICTED -- Restricted presentation \n
       - 0x02 -- PRESENTATION_NUM_ UNAVAILABLE -- Unavailable presentation \n
       - 0x04 -- PRESENTATION_PAYPHONE -- Payphone presentation (GSM/UMTS specific)
  */

  uint32_t number_len;  /**< Must be set to # of elements in number */
  char number[QMI_VOICE_NUMBER_MAX_V02];
  /**<   Number in ASCII characters.
  */
}voice_remote_party_number_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  pi_name_enum_v02 name_pi;
  /**<   Name presentation indicator. Values: \n
       - 0x00 -- PRESENTATION_NAME_ PRESENTATION_ALLOWED -- Allowed presentation \n
       - 0x01 -- PRESENTATION_NAME_ PRESENTATION_RESTRICTED -- Restricted presentation \n
       - 0x02 -- PRESENTATION_NAME_ UNAVAILABLE -- Unavailable presentation \n
       - 0x03 -- PRESENTATION_NAME_NAME_ PRESENTATION_RESTRICTED -- Restricted name presentation
  */

  uint8_t coding_scheme;
  /**<   Refer to \hyperref[STD-23038]{3GPP TS 23.038} Section 5 for coding schemes.
  */

  uint32_t caller_name_len;  /**< Must be set to # of elements in caller_name */
  char caller_name[QMI_VOICE_CALLER_NAME_MAX_V02];
  /**<   Caller name per the coding scheme.
  */
}voice_remote_party_name_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  SRV_OPT_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  SRV_OPT_BASIC_VAR_RATE_VOICE_SERV_V02 = 0x0001, 
  SRV_OPT_MOBILE_STATION_LOOPBACK_8_KBPS_V02 = 0x0002, 
  SRV_OPT_ENHANCED_VAR_RATE_VOICE_SERV_V02 = 0x0003, 
  SRV_OPT_ASYNCH_DATA_SERV_9_KBPS_V02 = 0x0004, 
  SRV_OPT_GROUP_3_FACSIMILE_9_KBPS_V02 = 0x0005, 
  SRV_OPT_SMS_RATE_SET_1_V02 = 0x0006, 
  SRV_OPT_PDS_INTERNET_OR_ISO_PROTOCOL_9_KBPS_V02 = 0x0007, 
  SRV_OPT_PDS_CDPD_PROTOCOL_9_KBPS_V02 = 0x0008, 
  SRV_OPT_MOBILE_STATION_LOOPBACK_13_KBPS_V02 = 0x0009, 
  SRV_OPT_STU_III_TRANSPARENT_SERV_V02 = 0x000A, 
  SRV_OPT_STU_III_NON_TRANSPARENT_SERV_V02 = 0x000B, 
  SRV_OPT_ASYNCH_DATA_SERV_9_OR_14_KBPS_V02 = 0x000C, 
  SRV_OPT_GROUP_3_FACSIMILE_9_OR_14_KBPS_V02 = 0x000D, 
  SRV_OPT_SMS_RATE_SET_2_V02 = 0x000E, 
  SRV_OPT_PDS_INTERNET_OR_ISO_PROTOCOL_14_KBPS_V02 = 0x000F, 
  SRV_OPT_PDS_CDPD_PROTOCOL_14_KBPS_V02 = 0x0010, 
  SRV_OPT_HIGH_RATE_VOICE_SERV_13_KBPS_V02 = 0x0011, 
  SRV_OPT_OTA_PARAM_ADMIN_RATE_SET_1_V02 = 0x0012, 
  SRV_OPT_OTA_PARAM_ADMIN_RATE_SET_2_V02 = 0x0013, 
  SRV_OPT_GROUP_3_ANALOG_FACSIMILE_RATE_SET_1_V02 = 0x0014, 
  SRV_OPT_GROUP_3_ANALOG_FACSIMILE_RATE_SET_2_V02 = 0x0015, 
  SRV_OPT_HSPDS_INTERNET_OR_ISO_PROTOCOL_RS1F_RS1R_V02 = 0x0016, 
  SRV_OPT_HSPDS_INTERNET_OR_ISO_PROTOCOL_RS1F_RS2R_V02 = 0x0017, 
  SRV_OPT_HSPDS_INTERNET_OR_ISO_PROTOCOL_RS2F_RS1R_V02 = 0x0018, 
  SRV_OPT_HSPDS_INTERNET_OR_ISO_PROTOCOL_RS2F_RS2R_V02 = 0x0019, 
  SRV_OPT_HSPDS_CDPD_PROTOCOL_RS1F_RS1R_V02 = 0x001A, 
  SRV_OPT_HSPDS_CDPD_PROTOCOL_RS1F_RS2R_V02 = 0x001B, 
  SRV_OPT_HSPDS_CDPD_PROTOCOL_RS2F_RS1R_V02 = 0x001C, 
  SRV_OPT_HSPDS_CDPD_PROTOCOL_RS2F_RS2R_V02 = 0x001D, 
  SRV_OPT_SUPP_CHANNEL_LOOPBACK_TEST_RATE_SET_1_V02 = 0x001E, 
  SRV_OPT_SUPP_CHANNEL_LOOPBACK_TEST_RATE_SET_2_V02 = 0x001F, 
  SRV_OPT_TDSO_V02 = 0x0020, 
  SRV_OPT_CDMA2000_HSPDS_INTERNET_OR_ISO_PROTOCOL_SO_33_V02 = 0x0021, 
  SRV_OPT_CDMA2000_HSPDS_CDPD_PROTOCOL_V02 = 0x0022, 
  SRV_OPT_LOCATION_SERV_RATE_SET_1_V02 = 0x0023, 
  SRV_OPT_LOCATION_SERV_RATE_SET_2_V02 = 0x0024, 
  SRV_OPT_ISDN_INTERWORKING_SERV_V02 = 0x0025, 
  SRV_OPT_GSM_VOICE_V02 = 0x0026, 
  SRV_OPT_GSM_CIRCUIT_DATA_V02 = 0x0027, 
  SRV_OPT_GSM_PACKET_DATA_V02 = 0x0028, 
  SRV_OPT_GSM_SMS_V02 = 0x0029, 
  SRV_OPT_MSO_V02 = 0x0036, 
  SRV_OPT_LSO_V02 = 0x0037, 
  SRV_OPT_SELECTABLE_MODE_VOCODER_V02 = 0x0038, 
  SRV_OPT_32_KBPS_CIRCUIT_VID_CONFERENCING_V02 = 0x0039, 
  SRV_OPT_64_KBPS_CIRCUIT_VID_CONFERENCING_V02 = 0x003A, 
  SRV_OPT_HRPD_PDS_PAGING_NOT_REQ_V02 = 0x003B, 
  SRV_OPT_LLA_ROHC_HEADER_REMOVAL_V02 = 0x003C, 
  SRV_OPT_LLA_ROHC_HEADER_COMPRESSION_V02 = 0x003D, 
  SRV_OPT_VMR_WB_RATE_SET_2_V02 = 0x003E, 
  SRV_OPT_VMR_WB_RATE_SET_1_V02 = 0x003F, 
  SRV_OPT_HRPD_AUX_PDS_INSTANCE_V02 = 0x0040, 
  SRV_OPT_CDMA2000_GPRS_INTERWORKING_V02 = 0x0041, 
  SRV_OPT_CDMA2000_HSPDS_INTERNET_OR_ISO_PROTOCOL_SO_66_V02 = 0x0042, 
  SRV_OPT_HRPD_PDS_IP_OR_ROHC_V02 = 0x0043, 
  SRV_OPT_EVRC_B_V02 = 0x0044, 
  SRV_OPT_HRPD_PDS_PAGING_REQ_V02 = 0x0045, 
  SRV_OPT_EVRC_WB_V02 = 0x0046, 
  SRV_OPT_ASYNCH_DATA_SERV_REV_1_9_OR_14_KBPS_V02 = 0x1004, 
  SRV_OPT_GROUP_3_FACSIMILE_REV_1_9_OR_14_KBPS_V02 = 0x1005, 
  SRV_OPT_PDS_INTERNET_OR_ISO_PROTOCOL_REV_1_9_OR_14_KBPS_V02 = 0x1007, 
  SRV_OPT_PDS_CDPD_PROTOCOL_REV_1_9_OR_14_KBPS_V02 = 0x1008, 
  SRV_OPT_ID_0_V02 = 0x7FF8, 
  SRV_OPT_ID_1_V02 = 0x7FF9, 
  SRV_OPT_ID_2_V02 = 0x7FFA, 
  SRV_OPT_ID_3_V02 = 0x7FFB, 
  SRV_OPT_ID_4_V02 = 0x7FFC, 
  SRV_OPT_ID_5_V02 = 0x7FFD, 
  SRV_OPT_ID_6_V02 = 0x7FFE, 
  SRV_OPT_ID_7_V02 = 0x7FFF, 
  SRV_OPT_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}srv_opt_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_PRIVACY_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_PRIVACY_STANDARD_V02 = 0x00, 
  VOICE_PRIVACY_ENHANCED_V02 = 0x01, 
  VOICE_PRIVACY_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_privacy_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  OTASP_STATUS_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  OTASP_STATUS_SPL_UNLOCKED_V02 = 0x00, 
  OTASP_STATUS_SPRC_RETRIES_EXCEEDED_V02 = 0x01, 
  OTASP_STATUS_AKEY_EXCHANGED_V02 = 0x02, 
  OTASP_STATUS_SSD_UPDATED_V02 = 0x03, 
  OTASP_STATUS_NAM_DOWNLOADED_V02 = 0x04, 
  OTASP_STATUS_MDN_DOWNLOADED_V02 = 0x05, 
  OTASP_STATUS_IMSI_DOWNLOADED_V02 = 0x06, 
  OTASP_STATUS_PRL_DOWNLOADED_V02 = 0x07, 
  OTASP_STATUS_COMMITTED_V02 = 0x08, 
  OTASP_STATUS_OTAPA_STARTED_V02 = 0x09, 
  OTASP_STATUS_OTAPA_STOPPED_V02 = 0x0A, 
  OTASP_STATUS_OTAPA_ABORTED_V02 = 0x0B, 
  OTASP_STATUS_OTAPA_COMMITTED_V02 = 0x0C, 
  OTASP_STATUS_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}otasp_status_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_NUM_TYPE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QMI_VOICE_NUM_TYPE_UNKNOWN_V02 = 0x00, /**<  Unknown \n  */
  QMI_VOICE_NUM_TYPE_INTERNATIONAL_V02 = 0x01, /**<  International \n  */
  QMI_VOICE_NUM_TYPE_NATIONAL_V02 = 0x02, /**<  National \n  */
  QMI_VOICE_NUM_TYPE_NETWORK_SPECIFIC_V02 = 0x03, /**<  Network-specific \n  */
  QMI_VOICE_NUM_TYPE_SUBSCRIBER_V02 = 0x04, /**<  Subscriber \n  */
  QMI_VOICE_NUM_TYPE_RESERVED_V02 = 0x05, /**<  Reserved \n  */
  QMI_VOICE_NUM_TYPE_ABBREVIATED_V02 = 0x06, /**<  Abbreviated \n  */
  QMI_VOICE_NUM_TYPE_RESERVED_EXTENSION_V02 = 0x07, /**<  Reserved extension  */
  VOICE_NUM_TYPE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_num_type_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_NUM_PLAN_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QMI_VOICE_NUM_PLAN_UNKNOWN_V02 = 0x00, /**<  Unknown \n  */
  QMI_VOICE_NUM_PLAN_ISDN_V02 = 0x01, /**<  ISDN \n  */
  QMI_VOICE_NUM_PLAN_DATA_V02 = 0x03, /**<  Data \n  */
  QMI_VOICE_NUM_PLAN_TELEX_V02 = 0x04, /**<  Telex \n  */
  QMI_VOICE_NUM_PLAN_NATIONAL_V02 = 0x08, /**<  National \n  */
  QMI_VOICE_NUM_PLAN_PRIVATE_V02 = 0x09, /**<  Private \n  */
  QMI_VOICE_NUM_PLAN_RESERVED_CTS_V02 = 0x0B, /**<  Reserved cordless telephony system \n  */
  QMI_VOICE_NUM_PLAN_RESERVED_EXTENSION_V02 = 0x0F, /**<  Reserved extension  */
  VOICE_NUM_PLAN_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_num_plan_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_SI_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QMI_VOICE_SI_USER_PROVIDED_NOT_SCREENED_V02 = 0x00, /**<  Provided user is not screened \n  */
  QMI_VOICE_SI_USER_PROVIDED_VERIFIED_PASSED_V02 = 0x01, /**<  Provided user passed verification \n  */
  QMI_VOICE_SI_USER_PROVIDED_VERIFIED_FAILED_V02 = 0x02, /**<  Provided user failed verification \n  */
  QMI_VOICE_SI_NETWORK_PROVIDED_V02 = 0x03, /**<  Provided network  */
  VOICE_SI_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_si_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_REDIRECTING_REASON_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QMI_VOICE_REDIRECT_REASON_UNKNOWN_V02 = 0x00, 
  QMI_VOICE_REDIRECT_REASON_CFW_OR_CALLED_DTE_BUSY_V02 = 0x01, 
  QMI_VOICE_REDIRECT_REASON_CFW_NOREPLY_V02 = 0x02, 
  QMI_VOICE_REDIRECT_REASON_CALLED_DTE_OUT_OF_ORDER_V02 = 0x09, 
  QMI_VOICE_REDIRECT_REASON_CFW_BY_CALLED_DTE_V02 = 0x0A, 
  QMI_VOICE_REDIRECT_REASON_CFW_UNCOND_OR_CALL_REDIRECT_V02 = 0x0F, 
  VOICE_REDIRECTING_REASON_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_redirecting_reason_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  ALERTING_PATTERN_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QMI_VOICE_ALERTING_PATTERN_1_V02 = 0x00, 
  QMI_VOICE_ALERTING_PATTERN_2_V02 = 0x01, 
  QMI_VOICE_ALERTING_PATTERN_3_V02 = 0x02, 
  QMI_VOICE_ALERTING_PATTERN_5_V02 = 0x04, 
  QMI_VOICE_ALERTING_PATTERN_6_V02 = 0x05, 
  QMI_VOICE_ALERTING_PATTERN_7_V02 = 0x06, 
  QMI_VOICE_ALERTING_PATTERN_8_V02 = 0x07, 
  QMI_VOICE_ALERTING_PATTERN_9_V02 = 0x08, 
  ALERTING_PATTERN_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}alerting_pattern_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  pi_num_enum_v02 pi;
  /**<   Presentation indicator; refer to 
       \hyperref[STD-CS0005D]{3GPP2 C.S0005-D} Table 2.7.4.4-1 
       for valid values.
  */

  voice_si_enum_v02 si;
  /**<   Screening indicator. Values: \n
       - 0x00 -- QMI_VOICE_SI_USER_PROVIDED_ NOT_SCREENED -- Provided user is not screened \n
       - 0x01 -- QMI_VOICE_SI_USER_PROVIDED_ VERIFIED_PASSED -- Provided user passed verification \n
       - 0x02 -- QMI_VOICE_SI_USER_PROVIDED_ VERIFIED_FAILED -- Provided user failed verification \n
       - 0x03 -- QMI_VOICE_SI_NETWORK_ PROVIDED -- Provided network
  */

  voice_num_type_enum_v02 num_type;
  /**<   Number type. Values: \n
       - 0x00 -- QMI_VOICE_NUM_TYPE_ UNKNOWN -- Unknown \n
       - 0x01 -- QMI_VOICE_NUM_TYPE_ INTERNATIONAL -- International \n
       - 0x02 -- QMI_VOICE_NUM_TYPE_ NATIONAL -- National \n
       - 0x03 -- QMI_VOICE_NUM_TYPE_ NETWORK_ SPECIFIC -- Network-specific \n
       - 0x04 -- QMI_VOICE_NUM_TYPE_ SUBSCRIBER -- Subscriber \n
       - 0x05 -- QMI_VOICE_NUM_TYPE_ RESERVED -- Reserved \n
       - 0x06 -- QMI_VOICE_NUM_TYPE_ ABBREVIATED -- Abbreviated \n
       - 0x07 -- QMI_VOICE_NUM_TYPE_ RESERVED_EXTENSION -- Reserved extension
  */

  voice_num_plan_enum_v02 num_plan;
  /**<   Number plan. Values: \n
       - 0x00 -- QMI_VOICE_NUM_PLAN_ UNKNOWN -- Unknown \n
       - 0x01 -- QMI_VOICE_NUM_PLAN_ISDN -- ISDN \n
       - 0x03 -- QMI_VOICE_NUM_PLAN_DATA -- Data \n
       - 0x04 -- QMI_VOICE_NUM_PLAN_TELEX -- Telex \n
       - 0x08 -- QMI_VOICE_NUM_PLAN_ NATIONAL -- National \n
       - 0x09 -- QMI_VOICE_NUM_PLAN_ PRIVATE -- Private \n
       - 0x0B -- QMI_VOICE_NUM_PLAN_ RESERVED_CTS -- Reserved cordless telephony system \n
       - 0x0F -- QMI_VOICE_NUM_PLAN_ RESERVED_EXTENSION -- Reserved extension
  */

  uint32_t num_len;  /**< Must be set to # of elements in num */
  char num[QMI_VOICE_CALLER_ID_MAX_V02];
  /**<   Caller ID in ASCII string.
  */
}voice_num_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  pi_num_enum_v02 num_pi;
  /**<   Presentation indicator. Values: \n
      - PRESENTATION_NUM_ALLOWED (0x00) --  Allowed presentation \n 
      - PRESENTATION_NUM_RESTRICTED (0x01) --  Restricted presentation \n 
      - PRESENTATION_NUM_NUM_UNAVAILABLE (0x02) --  Unavailable presentation \n 
      - PRESENTATION_NUM_RESERVED (0x03) --  Reserved presentation \n 
      - PRESENTATION_NUM_PAYPHONE (0x04) --  Payphone presentation (GSM/UMTS specific) 
 */

  voice_si_enum_v02 num_si;
  /**<   Screening indicator. Values: \n
      - QMI_VOICE_SI_USER_PROVIDED_NOT_SCREENED (0x00) --  Provided user is not screened \n 
      - QMI_VOICE_SI_USER_PROVIDED_VERIFIED_PASSED (0x01) --  Provided user passed verification \n 
      - QMI_VOICE_SI_USER_PROVIDED_VERIFIED_FAILED (0x02) --  Provided user failed verification \n 
      - QMI_VOICE_SI_NETWORK_PROVIDED (0x03) --  Provided network 
 */

  voice_num_type_enum_v02 num_type;
  /**<   Number type. Values: \n
      - QMI_VOICE_NUM_TYPE_UNKNOWN (0x00) --  Unknown \n 
      - QMI_VOICE_NUM_TYPE_INTERNATIONAL (0x01) --  International \n 
      - QMI_VOICE_NUM_TYPE_NATIONAL (0x02) --  National \n 
      - QMI_VOICE_NUM_TYPE_NETWORK_SPECIFIC (0x03) --  Network-specific \n 
      - QMI_VOICE_NUM_TYPE_SUBSCRIBER (0x04) --  Subscriber \n 
      - QMI_VOICE_NUM_TYPE_RESERVED (0x05) --  Reserved \n 
      - QMI_VOICE_NUM_TYPE_ABBREVIATED (0x06) --  Abbreviated \n 
      - QMI_VOICE_NUM_TYPE_RESERVED_EXTENSION (0x07) --  Reserved extension 
 */

  voice_num_plan_enum_v02 num_plan;
  /**<   Number plan. Values: \n
      - QMI_VOICE_NUM_PLAN_UNKNOWN (0x00) --  Unknown \n 
      - QMI_VOICE_NUM_PLAN_ISDN (0x01) --  ISDN \n 
      - QMI_VOICE_NUM_PLAN_DATA (0x03) --  Data \n 
      - QMI_VOICE_NUM_PLAN_TELEX (0x04) --  Telex \n 
      - QMI_VOICE_NUM_PLAN_NATIONAL (0x08) --  National \n 
      - QMI_VOICE_NUM_PLAN_PRIVATE (0x09) --  Private \n 
      - QMI_VOICE_NUM_PLAN_RESERVED_CTS (0x0B) --  Reserved cordless telephony system \n 
      - QMI_VOICE_NUM_PLAN_RESERVED_EXTENSION (0x0F) --  Reserved extension 
 */

  char num[QMI_VOICE_SIP_URI_MAX_V02 + 1];
  /**<   Number in ASCII characters.
  */
}voice_remote_party_number_ext_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  uint32_t ip_caller_name_len;  /**< Must be set to # of elements in ip_caller_name */
  uint16_t ip_caller_name[QMI_VOICE_IP_CALLER_NAME_MAX_LEN_V02];
  /**<   Caller name. This text can contain up to 128 UTF-16 characters
       and it is not guaranteed to be NULL terminated.
       Length range: 0 to 128.
  */
}voice_ip_caller_name_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  uint32_t end_reason_text_len;  /**< Must be set to # of elements in end_reason_text */
  uint16_t end_reason_text[QMI_VOICE_END_REASON_TEXT_MAX_LEN_V02];
  /**<   End reason text. This text can contain up to 128 UTF-16 
       characters and it is not guaranteed to be NULL terminated.
  */
}voice_ip_end_reason_text_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  uint16_t sip_error_code;
  /**<   SIP error code for IP call.    
  */
}voice_ip_end_sip_code_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Queries the information associated with a call. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Call Information */
  uint8_t call_info_valid;  /**< Must be set to true if call_info is being passed */
  voice_call_info_type_v02 call_info;

  /* Optional */
  /*  Remote Party Number */
  uint8_t remote_party_number_valid;  /**< Must be set to true if remote_party_number is being passed */
  voice_remote_party_number_type_v02 remote_party_number;

  /* Optional */
  /*  Service Option* */
  uint8_t srv_opt_valid;  /**< Must be set to true if srv_opt is being passed */
  srv_opt_enum_v02 srv_opt;
  /**<   Service option per \hyperref[STD-CR1001F]{3GPP2 C.R1001-F} Table 3.1-1; see 
       Table @latexonly\ref{tbl:serviceOption}@endlatexonly for standard
       service option number assignments. 
  */

  /* Optional */
  /*  Voice Privacy* */
  uint8_t voice_privacy_valid;  /**< Must be set to true if voice_privacy is being passed */
  voice_privacy_enum_v02 voice_privacy;
  /**<   Values: \n 
       - 0x00 -- VOICE_PRIVACY_STANDARD -- Standard privacy \n
       - 0x01 -- VOICE_PRIVACY_ENHANCED -- Enhanced privacy
  */

  /* Optional */
  /*  OTASP Status* */
  uint8_t otasp_status_valid;  /**< Must be set to true if otasp_status is being passed */
  otasp_status_enum_v02 otasp_status;
  /**<   OTASP status for the OTASP call. Values: \n
       - 0x00 -- OTASP_STATUS_SPL_UNLOCKED -- SPL unlocked; 
                 only for user-initiated OTASP \n
       - 0x01 -- OTASP_STATUS_SPRC_RETRIES_ EXCEEDED -- SPC retries exceeded; 
                 only for user-initiated OTASP \n
       - 0x02 -- OTASP_STATUS_AKEY_ EXCHANGED -- A-key exchanged; 
                 only for user-initiated OTASP \n
       - 0x03 -- OTASP_STATUS_SSD_UPDATED -- SSD updated; for both 
                 user-initiated OTASP and network-initiated OTASP (OTAPA) \n
       - 0x04 -- OTASP_STATUS_NAM_ DOWNLOADED -- NAM downloaded; 
                 only for user-initiated OTASP \n
       - 0x05 -- OTASP_STATUS_MDN_ DOWNLOADED -- MDN downloaded; 
                 only for user-initiated OTASP \n
       - 0x06 -- OTASP_STATUS_IMSI_ DOWNLOADED -- IMSI downloaded; 
                 only for user-initiated OTASP \n
       - 0x07 -- OTASP_STATUS_PRL_ DOWNLOADED -- PRL downloaded; 
                 only for user-initiated OTASP \n
       - 0x08 -- OTASP_STATUS_COMMITTED -- Commit successful; 
                 only for user-initiated OTASP \n
       - 0x09 -- OTASP_STATUS_OTAPA_STARTED -- OTAPA started; 
                 only for network-initiated OTASP (OTAPA) \n
       - 0x0A -- OTASP_STATUS_OTAPA_STOPPED -- OTAPA stopped; 
                 only for network-initiated OTASP (OTAPA) \n
       - 0x0B -- OTASP_STATUS_OTAPA_ABORTED -- OTAPA aborted; 
                 only for network-initiated OTASP (OTAPA) \n
       - 0x0C -- OTASP_STATUS_OTAPA_ COMMITTED -- OTAPA committed; 
                 only for network-initiated OTASP (OTAPA)
  */

  /* Optional */
  /*  Remote Party Name** */
  uint8_t remote_party_name_valid;  /**< Must be set to true if remote_party_name is being passed */
  voice_remote_party_name_type_v02 remote_party_name;

  /* Optional */
  /*  UUS Information** */
  uint8_t uus_valid;  /**< Must be set to true if uus is being passed */
  voice_uus_type_v02 uus;

  /* Optional */
  /*  Alerting Type** */
  uint8_t alerting_type_valid;  /**< Must be set to true if alerting_type is being passed */
  alerting_type_enum_v02 alerting_type;
  /**<   Alerting type. Values: \n
       - 0x00 -- ALERTING_LOCAL -- Local \n
       - 0x01 -- ALERTING_REMOTE -- Remote
  */

  /* Optional */
  /*  Alpha Identifier** */
  uint8_t alpha_ident_valid;  /**< Must be set to true if alpha_ident is being passed */
  voice_alpha_ident_type_v02 alpha_ident;

  /* Optional */
  /*  Connected Number Information */
  uint8_t conn_num_info_valid;  /**< Must be set to true if conn_num_info is being passed */
  voice_num_info_type_v02 conn_num_info;

  /* Optional */
  /*  Diagnostic Information */
  uint8_t diagnostic_info_valid;  /**< Must be set to true if diagnostic_info is being passed */
  uint32_t diagnostic_info_len;  /**< Must be set to # of elements in diagnostic_info */
  uint8_t diagnostic_info[QMI_VOICE_DIAGNOSTIC_INFO_MAX_V02];
  /**<   Diagnostic information.
  */

  /* Optional */
  /*  Alerting Pattern** */
  uint8_t alerting_pattern_valid;  /**< Must be set to true if alerting_pattern is being passed */
  alerting_pattern_enum_v02 alerting_pattern;
  /**<   Alerting pattern. Values: \n
       - 0x00 -- QMI_VOICE_ALERTING_ PATTERN_1 -- Pattern 1 \n
       - 0x01 -- QMI_VOICE_ALERTING_ PATTERN_2 -- Pattern 2 \n
       - 0x02 -- QMI_VOICE_ALERTING_ PATTERN_3 -- Pattern 3 \n
       - 0x04 -- QMI_VOICE_ALERTING_ PATTERN_5 -- Pattern 5 \n
       - 0x05 -- QMI_VOICE_ALERTING_ PATTERN_6 -- Pattern 6 \n
       - 0x06 -- QMI_VOICE_ALERTING_ PATTERN_7 -- Pattern 7 \n
       - 0x07 -- QMI_VOICE_ALERTING_ PATTERN_8 -- Pattern 8 \n
       - 0x08 -- QMI_VOICE_ALERTING_ PATTERN_9 -- Pattern 9
  */

  /* Optional */
  /*  Audio Attribute for VT or VOIP Call */
  uint8_t audio_attrib_valid;  /**< Must be set to true if audio_attrib is being passed */
  voice_call_attribute_type_mask_v02 audio_attrib;
  /**<   Bitmask of call attributes. Values: \n
       - Bit 0 (0x01) -- VOICE_CALL_ATTRIB_TX -- Transmission \n
       - Bit 1 (0x02) -- VOICE_CALL_ATTRIB_RX -- Receiving
  */

  /* Optional */
  /*  Video Attribute for VT or VOIP Call */
  uint8_t video_attrib_valid;  /**< Must be set to true if video_attrib is being passed */
  voice_call_attribute_type_mask_v02 video_attrib;
  /**<   Bitmask of call attributes. Values: \n
       - Bit 0 (0x01) -- VOICE_CALL_ATTRIB_TX -- Transmission \n
       - Bit 1 (0x02) -- VOICE_CALL_ATTRIB_RX -- Receiving
  */

  /* Optional */
  /*  Variant Information for Videoshare Call */
  uint8_t vs_variant_valid;  /**< Must be set to true if vs_variant is being passed */
  vs_variant_type_enum_v02 vs_variant;
  /**<   Call variant. Values: \n
      - VS_VARIANT_RCS_E (0x01) --  RCSe \n 
      - VS_VARIANT_RCS_V5 (0x02) --  RCSv5 
 */

  /* Optional */
  /*  SIP URI for IP Call */
  uint8_t sip_uri_valid;  /**< Must be set to true if sip_uri is being passed */
  char sip_uri[QMI_VOICE_SIP_URI_MAX_V02 + 1];
  /**<   SIP URI number as an ASCII string. Length range: 1 to 128.
  */

  /* Optional */
  /*  Is SRVCC Call */
  uint8_t is_srvcc_call_valid;  /**< Must be set to true if is_srvcc_call is being passed */
  uint8_t is_srvcc_call;
  /**<   Indicates whether the call is Single Radio Voice Call Continuity 
       (SRVCC). Values: \n
       - 0x00 -- Not an SRVCC call \n
       - 0x01 -- SRVCC call
  */

  /* Optional */
  /*  Remote Party Number Extension */
  uint8_t remote_party_number_ext_valid;  /**< Must be set to true if remote_party_number_ext is being passed */
  voice_remote_party_number_ext_type_v02 remote_party_number_ext;

  /* Optional */
  /*  Second Alpha Identifier** */
  uint8_t second_alpha_ident_valid;  /**< Must be set to true if second_alpha_ident is being passed */
  voice_alpha_ident_type_v02 second_alpha_ident;

  /* Optional */
  /*  Caller Name for IP Call */
  uint8_t ip_caller_name_valid;  /**< Must be set to true if ip_caller_name is being passed */
  uint32_t ip_caller_name_len;  /**< Must be set to # of elements in ip_caller_name */
  uint16_t ip_caller_name[QMI_VOICE_IP_CALLER_NAME_MAX_LEN_V02];
  /**<   Caller name. This text can contain up to 128 UTF-16 characters
       and it is not guaranteed to be NULL terminated.
       Length range: 0 to 128.
  */

  /* Optional */
  /*  End Reason Text for IP Call */
  uint8_t end_reason_text_valid;  /**< Must be set to true if end_reason_text is being passed */
  uint32_t end_reason_text_len;  /**< Must be set to # of elements in end_reason_text */
  uint16_t end_reason_text[QMI_VOICE_END_REASON_TEXT_MAX_LEN_V02];
  /**<   End reason text. This text can contain up to 128 UTF-16 
       characters and it is not guaranteed to be NULL terminated.
  */

  /* Optional */
  /*  Called Party Subaddress */
  uint8_t called_party_subaddress_valid;  /**< Must be set to true if called_party_subaddress is being passed */
  voice_subaddress_type_v02 called_party_subaddress;

  /* Optional */
  /*  SIP Error Code for IP Call */
  uint8_t sip_error_code_valid;  /**< Must be set to true if sip_error_code is being passed */
  uint16_t sip_error_code;
  /**<   SIP failure code for IMS calls.
  */

  /* Optional */
  /*  IP History Information */
  uint8_t ip_hist_info_valid;  /**< Must be set to true if ip_hist_info is being passed */
  uint32_t ip_hist_info_len;  /**< Must be set to # of elements in ip_hist_info */
  uint16_t ip_hist_info[QMI_VOICE_IP_HIST_INFO_MAX_LEN_V02];
  /**<   IP history information. This field contains history-info fields from 
       the SIP header in the order in which they occur in the header.  
       Successive fields are separated by 
       @latexonly\textbackslash r\textbackslash n.@endlatexonly
       If a field does not fit into the remaining space in a buffer, neither
       it nor any subsequent field is added.
  */

  /* Optional */
  /*  RTT Attribute for VT or VOIP Call */
  uint8_t rtt_mode_valid;  /**< Must be set to true if rtt_mode is being passed */
  rtt_mode_type_v02 rtt_mode;
  /**<   Whether the current call is an RTT call. Values: \n
      - RTT_MODE_DISABLED (0) --  non-RTT call \n 
      - RTT_MODE_FULL (1) --  RTT call with RTT being used from both sides 
 */

  /* Optional */
  /*  Alternate SIP URI for IP Call */
  uint8_t alternate_sip_uri_valid;  /**< Must be set to true if alternate_sip_uri is being passed */
  char alternate_sip_uri[QMI_VOICE_SIP_URI_MAX_V02 + 1];
  /**<   Alternate SIP URI number as an ASCII string.
  */
}voice_get_call_info_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Call identifier for the call.
  */

  otasp_status_enum_v02 otasp_status;
  /**<   OTASP status for the OTASP call. Values: \n
       - 0x00 - OTASP_STATUS_SPL_UNLOCKED -- SPL unlocked;
                only for user-initiated OTASP \n
       - 0x01 - OTASP_STATUS_SPRC_RETRIES_ EXCEEDED -- SPC retries exceeded;
                only for user-initiated OTASP \n
       - 0x02 - OTASP_STATUS_AKEY_ EXCHANGED -- A-key exchanged;
                only for user-initiated OTASP \n
       - 0x03 - OTASP_STATUS_SSD_UPDATED -- SSD updated; for both user-initiated
                OTASP and network-initiated OTASP (OTAPA) \n
       - 0x04 - OTASP_STATUS_NAM_ DOWNLOADED -- NAM downloaded;
                only for user-initiated OTASP \n
       - 0x05 - OTASP_STATUS_MDN_ DOWNLOADED -- MDN downloaded;
                only for user-initiated OTASP \n
       - 0x06 - OTASP_STATUS_IMSI_ DOWNLOADED -- IMSI downloaded; 
                only for user-initiated OTASP \n
       - 0x07 - OTASP_STATUS_PRL_ DOWNLOADED -- PRL downloaded;
                only for user-initiated OTASP \n
       - 0x08 - OTASP_STATUS_COMMITTED -- Commit successful;
                only for user-initiated OTASP \n
       - 0x09 - OTASP_STATUS_OTAPA_STARTED -- OTAPA started;
                only for network-initiated OTASP (OTAPA) \n
       - 0x0A - OTASP_STATUS_OTAPA_STOPPED -- OTAPA stopped;
                only for network-initiated OTASP (OTAPA) \n
       - 0x0B - OTASP_STATUS_OTAPA_ABORTED -- OTAPA aborted;
                only for network-initiated OTASP (OTAPA) \n
       - 0x0C - OTASP_STATUS_OTAPA_ COMMITTED -- OTAPA committed; 
                only for network-initiated OTASP (OTAPA)
  */
}voice_otasp_status_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Indicates the occurrence of an OTASP or OTAPA event 
             (applicable only for 3GPP2). */
typedef struct {

  /* Mandatory */
  /*  OTASP Status Information */
  voice_otasp_status_info_type_v02 otasp_status_info;
}voice_otasp_status_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  SIGNAL_TYPE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  SIGNAL_TYPE_TONE_V02 = 0x00, 
  SIGNAL_TYPE_ISDN_ALERTING_V02 = 0x01, 
  SIGNAL_TYPE_IS54B_ALERTING_V02 = 0x02, 
  SIGNAL_TYPE_RESERVED_V02 = 0x03, 
  SIGNAL_TYPE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}signal_type_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  ALERT_PITCH_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  ALERT_PITCH_MED_V02 = 0x00, 
  ALERT_PITCH_HIGH_V02 = 0x01, 
  ALERT_PITCH_LOW_V02 = 0x02, 
  ALERT_PITCH_RESERVED_V02 = 0x03, 
  ALERT_PITCH_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}alert_pitch_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  signal_type_enum_v02 signal_type;
  /**<   Signal type; refer to 
       \hyperref[STD-CS0005D]{3GPP2 C.S0005-D} Table 3.7.5.5-1 for valid 
       signal type values.
  */

  alert_pitch_enum_v02 alert_pitch;
  /**<   Alert pitch; refer to 
       \hyperref[STD-CS0005D]{3GPP2 C.S0005-D} Table 3.7.5.5-2 for valid 
       alert pitch values.
  */

  uint8_t signal;
  /**<   Signal tone; refer to 
       \hyperref[STD-CS0005D]{3GPP2 C.S0005-D} Tables 3.7.5.5-3, 3.7.5.5-4, 
       and 3.7.5.5-5 for valid signal tones.
  */
}voice_signal_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  pi_num_enum_v02 pi;
  /**<   Presentation indicator; refer to 
       \hyperref[STD-CS0005D]{3GPP2 C.S0005-D} Table 2.7.4.4-1 
       for valid values.
  */

  uint32_t caller_id_len;  /**< Must be set to # of elements in caller_id */
  char caller_id[QMI_VOICE_CALLER_ID_MAX_V02];
  /**<   Caller ID in ASCII string.
  */
}voice_caller_id_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  CALL_WAITING_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  CALL_WAITING_NEW_CALL_V02 = 0x01, 
  CALL_WAITING_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}call_waiting_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_NSS_CLIR_CAUSE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QMI_VOICE_CLIR_CAUSE_NO_CAUSE_V02 = 0x00, 
  QMI_VOICE_CLIR_CAUSE_REJECTED_BY_USER_V02 = 0x01, 
  QMI_VOICE_CLIR_CAUSE_INTERACTION_WITH_OTHER_SERVICES_V02 = 0x02, 
  QMI_VOICE_CLIR_CAUSE_COIN_LINE_V02 = 0x03, 
  QMI_VOICE_CLIR_CAUSE_SERVICE_NOT_AVAILABLE_V02 = 0x04, 
  QMI_VOICE_CLIR_CAUSE_RESERVED_V02 = 0x05, 
  VOICE_NSS_CLIR_CAUSE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_nss_clir_cause_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_NSS_RELEASE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QMI_VOICE_NSS_RELEASE_FINISHED_V02 = 0x01, 
  VOICE_NSS_RELEASE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_nss_release_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  pi_num_enum_v02 pi;
  /**<   Presentation indicator; refer to 
       \hyperref[STD-CS0005D]{3GPP2 C.S0005-D} Table 2.7.4.4-1 
       for valid values.
  */

  voice_si_enum_v02 si;
  /**<   Screening indicator. Values: \n
       - 0x00 -- QMI_VOICE_SI_USER_PROVIDED_ NOT_SCREENED -- Provided user is not screened \n
       - 0x01 -- QMI_VOICE_SI_USER_PROVIDED_ VERIFIED_PASSED -- Provided user passed verification \n
       - 0x02 -- QMI_VOICE_SI_USER_PROVIDED_ VERIFIED_FAILED -- Provided user failed verification \n
       - 0x03 -- QMI_VOICE_SI_NETWORK_ PROVIDED -- Provided network
  */

  voice_num_type_enum_v02 num_type;
  /**<   Number type. Values: \n
       - 0x00 -- QMI_VOICE_NUM_TYPE_ UNKNOWN -- Unknown \n
       - 0x01 -- QMI_VOICE_NUM_TYPE_ INTERNATIONAL -- International \n
       - 0x02 -- QMI_VOICE_NUM_TYPE_ NATIONAL -- National \n
       - 0x03 -- QMI_VOICE_NUM_TYPE_ NETWORK_ SPECIFIC -- Network-specific \n
       - 0x04 -- QMI_VOICE_NUM_TYPE_ SUBSCRIBER -- Subscriber \n
       - 0x05 -- QMI_VOICE_NUM_TYPE_ RESERVED -- Reserved \n
       - 0x06 -- QMI_VOICE_NUM_TYPE_ ABBREVIATED -- Abbreviated \n
       - 0x07 -- QMI_VOICE_NUM_TYPE_ RESERVED_EXTENSION -- Reserved extension
  */

  voice_num_plan_enum_v02 num_plan;
  /**<   Number plan. Values: \n
       - 0x00 -- QMI_VOICE_NUM_PLAN_ UNKNOWN -- Unknown \n
       - 0x01 -- QMI_VOICE_NUM_PLAN_ISDN -- ISDN \n
       - 0x03 -- QMI_VOICE_NUM_PLAN_DATA -- Data \n
       - 0x04 -- QMI_VOICE_NUM_PLAN_TELEX -- Telex \n
       - 0x08 -- QMI_VOICE_NUM_PLAN_ NATIONAL -- National \n
       - 0x09 -- QMI_VOICE_NUM_PLAN_ PRIVATE -- Private \n
       - 0x0B -- QMI_VOICE_NUM_PLAN_ RESERVED_CTS -- Reserved cordless telephony system \n
       - 0x0F -- QMI_VOICE_NUM_PLAN_ RESERVED_EXTENSION -- Reserved extension
  */

  voice_redirecting_reason_enum_v02 reason;
  /**<   Redirecting reason; refer to 
       \hyperref[STD-CS0005D]{3GPP2 C.S0005-D} Table 3.7.5.11-1 for 
       valid values.
  */

  uint32_t num_len;  /**< Must be set to # of elements in num */
  char num[QMI_VOICE_CALLER_ID_MAX_V02];
  /**<   Caller ID in ASCII string.
  */
}voice_redirecting_num_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t up_link;
  /**<   Values are per \hyperref[STD-1X-Air-JCDMA]{1X Air JCDMA} 
       4.10 Reservation Response. 
  */

  uint8_t down_link;
  /**<   Values are per \hyperref[STD-1X-Air-JCDMA]{1X Air JCDMA} 
       4.10 Reservation Response. 
  */
}voice_nss_audio_control_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t polarity_included;
  /**<   Included polarity; boolean value.
  */

  uint8_t toggle_mode;
  /**<   Toggle mode; boolean value.
  */

  uint8_t reverse_polarity;
  /**<   Reverse polarity; boolean value.
  */

  uint8_t power_denial_time;
  /**<   	Power denial time; refer to 
        \hyperref[STD-CS0005D]{3GPP2 C.S0005-D} Section 3.7.5.15 Line Control 
        for valid values. 
  */
}voice_line_control_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t display_type;
  /**<   Values are per \hyperref[STD-CS0005D]{3GPP2 C.S0005-D} Table 3.7.5.16-1. 
  */

  uint32_t ext_display_info_len;  /**< Must be set to # of elements in ext_display_info */
  uint8_t ext_display_info[QMI_VOICE_EXT_DISPLAY_RECORD_LEN_MAX_V02];
  /**<   Extended display information buffer containing the display
       record; refer to 
       \hyperref[STD-CS0005D]{3GPP2 C.S0005-D} Section 3.7.5.16 for the
       format information of the buffer contents.
  */
}voice_ext_display_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_NETWORK_MESSAGE_TYPE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_NETWORK_MSG_TYPE_FNM_V02 = 0, /**<  Feature Notification message \n  */
  VOICE_NETWORK_MSG_TYPE_AWIM_V02 = 1, /**<  Alert with Information message \n  */
  VOICE_NETWORK_MSG_TYPE_EAWIM_V02 = 2, /**<  Extended Alert with Information message \n  */
  VOICE_NETWORK_MSG_TYPE_FWIM_V02 = 3, /**<  Forward Flash with Information message \n  */
  VOICE_NETWORK_MSG_TYPE_EFWIM_V02 = 4, /**<  Extended Flash with Information message \n  */
  VOICE_NETWORK_MSG_TYPE_OTHER_V02 = 0xFF, /**<  Any other message types   */
  VOICE_NETWORK_MESSAGE_TYPE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_network_message_type_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Indicates that a new information record is available from the
             network (applicable only for 3GPP2). */
typedef struct {

  /* Mandatory */
  /*  Call ID */
  uint8_t call_id;
  /**<   Call identifier for the call.
  */

  /* Optional */
  /*  Signal Information */
  uint8_t signal_info_valid;  /**< Must be set to true if signal_info is being passed */
  voice_signal_info_type_v02 signal_info;

  /* Optional */
  /*  Caller ID Information */
  uint8_t caller_id_info_valid;  /**< Must be set to true if caller_id_info is being passed */
  voice_caller_id_info_type_v02 caller_id_info;

  /* Optional */
  /*  Display Information */
  uint8_t display_buffer_valid;  /**< Must be set to true if display_buffer is being passed */
  char display_buffer[QMI_VOICE_DISPLAY_BUFFER_MAX_V02 + 1];
  /**<   Display buffer containing the display ASCII string.
  */

  /* Optional */
  /*  Extended Display Information */
  uint8_t ext_display_buffer_valid;  /**< Must be set to true if ext_display_buffer is being passed */
  char ext_display_buffer[QMI_VOICE_DISPLAY_BUFFER_MAX_V02 + 1];
  /**<   Extended display buffer containing the display
       text; refer to 
       \hyperref[STD-CS0005D]{3GPP2 C.S0005-D} Section 3.7.5.16 for the
       format information of the buffer contents.
  */

  /* Optional */
  /*  Caller Name Information */
  uint8_t caller_name_valid;  /**< Must be set to true if caller_name is being passed */
  char caller_name[QMI_VOICE_CALLER_NAME_MAX_V02 + 1];
  /**<   Caller name in ASCII string.
  */

  /* Optional */
  /*  Call Waiting Indicator */
  uint8_t call_waiting_valid;  /**< Must be set to true if call_waiting is being passed */
  call_waiting_enum_v02 call_waiting;
  /**<   Value: \n
       - 0x01 -- CALL_WAITING_NEW_CALL -- New call waiting
  */

  /* Optional */
  /*  Connected Number Information */
  uint8_t conn_num_info_valid;  /**< Must be set to true if conn_num_info is being passed */
  voice_num_info_type_v02 conn_num_info;

  /* Optional */
  /*  Calling Party Number Information */
  uint8_t calling_party_info_valid;  /**< Must be set to true if calling_party_info is being passed */
  voice_num_info_type_v02 calling_party_info;

  /* Optional */
  /*  Called Party Number Information */
  uint8_t called_party_info_valid;  /**< Must be set to true if called_party_info is being passed */
  voice_num_info_type_v02 called_party_info;

  /* Optional */
  /*  Redirecting Number Information */
  uint8_t redirecting_num_info_valid;  /**< Must be set to true if redirecting_num_info is being passed */
  voice_redirecting_num_info_type_v02 redirecting_num_info;

  /* Optional */
  /*  National Supplementary Services - CLIR */
  uint8_t clir_cause_valid;  /**< Must be set to true if clir_cause is being passed */
  voice_nss_clir_cause_enum_v02 clir_cause;
  /**<   CLIR cause. Values: \n 
       - 0x00 -- QMI_VOICE_CLIR_CAUSE_ NO_CAUSE -- None \n
       - 0x01 -- QMI_VOICE_CLIR_CAUSE_ REJECTED_ BY_USER -- Rejected by user \n
       - 0x02 -- QMI_VOICE_CLIR_CAUSE_ INTERACTION_WITH_OTHER_SERVICES -- Interaction with other services \n
       - 0x03 -- QMI_VOICE_CLIR_CAUSE_COIN_ LINE -- Coin line \n
       - 0x04 -- QMI_VOICE_CLIR_CAUSE_ SERVICE_NOT_AVAILABLE -- Service is not available \n
       - 0x05 -- QMI_VOICE_CLIR_CAUSE_ RESERVED -- Reserved
  */

  /* Optional */
  /*  National Supplementary Services - Audio Control */
  uint8_t audio_control_valid;  /**< Must be set to true if audio_control is being passed */
  voice_nss_audio_control_info_type_v02 audio_control;

  /* Optional */
  /*  National Supplementary Services - Release */
  uint8_t nss_release_valid;  /**< Must be set to true if nss_release is being passed */
  voice_nss_release_enum_v02 nss_release;
  /**<   NSS release. Values: \n
       - 0x01 -- QMI_VOICE_NSS_RELEASE_ FINISHED -- Finished
  */

  /* Optional */
  /*  Line Control Information */
  uint8_t line_control_valid;  /**< Must be set to true if line_control is being passed */
  voice_line_control_info_type_v02 line_control;

  /* Optional */
  /*  Extended Display Record Information */
  uint8_t ext_display_record_valid;  /**< Must be set to true if ext_display_record is being passed */
  voice_ext_display_info_type_v02 ext_display_record;

  /* Optional */
  /*  Network Message Type */
  uint8_t network_message_type_valid;  /**< Must be set to true if network_message_type is being passed */
  voice_network_message_type_enum_v02 network_message_type;
  /**<   Network message type. Values: \n
      - VOICE_NETWORK_MSG_TYPE_FNM (0) --  Feature Notification message \n 
      - VOICE_NETWORK_MSG_TYPE_AWIM (1) --  Alert with Information message \n 
      - VOICE_NETWORK_MSG_TYPE_EAWIM (2) --  Extended Alert with Information message \n 
      - VOICE_NETWORK_MSG_TYPE_FWIM (3) --  Forward Flash with Information message \n 
      - VOICE_NETWORK_MSG_TYPE_EFWIM (4) --  Extended Flash with Information message \n 
      - VOICE_NETWORK_MSG_TYPE_OTHER (0xFF) --  Any other message types   
 */
}voice_info_rec_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_SEND_FLASH_TYPE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QMI_VOICE_FLASH_TYPE_SIMPLE_FLASH_V02 = 0, 
  QMI_VOICE_FLASH_TYPE_ACT_ANSWER_HOLD_V02 = 1, 
  QMI_VOICE_FLASH_TYPE_DEACT_ANSWER_HOLD_V02 = 2, 
  VOICE_SEND_FLASH_TYPE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_send_flash_type_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Sends a simple Flash (applicable only for 3GPP2). */
typedef struct {

  /* Mandatory */
  /*  Call ID */
  uint8_t call_id;
  /**<   Call ID associated with the current call.
  */

  /* Optional */
  /*  Flash Payload */
  uint8_t flash_payload_valid;  /**< Must be set to true if flash_payload is being passed */
  char flash_payload[QMI_VOICE_FLASH_PAYLOAD_MAX_V02 + 1];
  /**<   Payload in ASCII to be sent in the Flash.
  */

  /* Optional */
  /*  Flash Type */
  uint8_t flash_type_valid;  /**< Must be set to true if flash_type is being passed */
  voice_send_flash_type_enum_v02 flash_type;
  /**<   Flash type. Values: \n
      - 0 -- QMI_VOICE_FLASH_TYPE_SIMPLE_ FLASH -- Simple Flash \n
      - 1 -- QMI_VOICE_FLASH_TYPE_ACT_ ANSWER_ HOLD -- Activate answer hold \n
      - 2 -- QMI_VOICE_FLASH_TYPE_DEACT_ ANSWER_HOLD -- Deactivate answer hold
  */
}voice_send_flash_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Sends a simple Flash (applicable only for 3GPP2). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Call ID */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Call ID associated with the current call.
  */
}voice_send_flash_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Call ID associated with the current call.
  */

  uint32_t digit_buffer_len;  /**< Must be set to # of elements in digit_buffer */
  char digit_buffer[QMI_VOICE_DIGIT_BUFFER_MAX_V02];
  /**<   DTMF digit buffer in ASCII string.
  */
}voice_burst_dtmf_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  DTMF_ONLENGTH_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DTMF_ONLENGTH_95MS_V02 = 0x00, 
  DTMF_ONLENGTH_150MS_V02 = 0x01, 
  DTMF_ONLENGTH_200MS_V02 = 0x02, 
  DTMF_ONLENGTH_250MS_V02 = 0x03, 
  DTMF_ONLENGTH_300MS_V02 = 0x04, 
  DTMF_ONLENGTH_350MS_V02 = 0x05, 
  DTMF_ONLENGTH_SMS_V02 = 0x06, 
  DTMF_ONLENGTH_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dtmf_onlength_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  DTMF_OFFLENGTH_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DTMF_OFFLENGTH_60MS_V02 = 0x00, 
  DTMF_OFFLENGTH_100MS_V02 = 0x01, 
  DTMF_OFFLENGTH_150MS_V02 = 0x02, 
  DTMF_OFFLENGTH_200MS_V02 = 0x03, 
  DTMF_OFFLENGTH_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dtmf_offlength_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  dtmf_onlength_enum_v02 dtmf_onlength;
  /**<   DTMF pulse width. Values: \n
       - 0x00 -- DTMF_ONLENGTH_95MS  -- 95 ms \n
       - 0x01 -- DTMF_ONLENGTH_150MS -- 150 ms \n
       - 0x02 -- DTMF_ONLENGTH_200MS -- 200 ms \n
       - 0x03 -- DTMF_ONLENGTH_250MS -- 250 ms \n
       - 0x04 -- DTMF_ONLENGTH_300MS -- 300 ms \n
       - 0x05 -- DTMF_ONLENGTH_350MS -- 350 ms \n
       - 0x06 -- DTMF_ONLENGTH_SMS   -- SMS Tx special pulse width
  */

  dtmf_offlength_enum_v02 dtmf_offlength;
  /**<   DTMF interdigit interval. Values: \n
       - 0x00 -- DTMF_OFFLENGTH_60MS  -- \n 60 ms \n
       - 0x01 -- DTMF_OFFLENGTH_100MS -- \n 100 ms \n
       - 0x02 -- DTMF_OFFLENGTH_150MS -- \n 150 ms \n
       - 0x03 -- DTMF_OFFLENGTH_200MS -- \n 200 ms
  */
}voice_dtmf_lengths_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Sends a burst Dual-Tone Multifrequency (DTMF) 
             (applicable only for 3GPP2). */
typedef struct {

  /* Mandatory */
  /*  Burst DTMF Information */
  voice_burst_dtmf_info_type_v02 burst_dtmf_info;

  /* Optional */
  /*  DTMF Lengths */
  uint8_t dtmf_lengths_valid;  /**< Must be set to true if dtmf_lengths is being passed */
  voice_dtmf_lengths_type_v02 dtmf_lengths;
}voice_burst_dtmf_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Sends a burst Dual-Tone Multifrequency (DTMF) 
             (applicable only for 3GPP2). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Call ID */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Call ID associated with the current call.
  */
}voice_burst_dtmf_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Call ID associated with the current call.
  */

  uint8_t digit;
  /**<   DTMF digit in ASCII.
  */
}voice_cont_dtmf_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Starts a continuous DTMF. */
typedef struct {

  /* Mandatory */
  /*  Continuous DTMF Information */
  voice_cont_dtmf_info_type_v02 cont_dtmf_info;
}voice_start_cont_dtmf_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Starts a continuous DTMF. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Call ID */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Call ID associated with the current call.
  */
}voice_start_cont_dtmf_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Stops a continuous DTMF. */
typedef struct {

  /* Mandatory */
  /*  Call ID */
  uint8_t call_id;
  /**<   Call ID associated with the current call.
  */
}voice_stop_cont_dtmf_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Stops a continuous DTMF. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Call ID */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Call ID associated with the current call.
  */
}voice_stop_cont_dtmf_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  DTMF_EVENT_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DTMF_EVENT_REV_BURST_V02 = 0x00, /**<  Sends a CDMA-burst DTMF \n  */
  DTMF_EVENT_REV_START_CONT_V02 = 0x01, /**<  Starts a continuous DTMF tone \n  */
  DTMF_EVENT_REV_STOP_CONT_V02 = 0x03, /**<  Stops a continuous DTMF tone \n  */
  DTMF_EVENT_FWD_BURST_V02 = 0x05, /**<  Received a CDMA-burst DTMF message \n  */
  DTMF_EVENT_FWD_START_CONT_V02 = 0x06, /**<  Received a start-continuous DTMF tone order \n  */
  DTMF_EVENT_FWD_STOP_CONT_V02 = 0x07, /**<  Received a stop-continuous DTMF tone order \n  */
  DTMF_EVENT_IP_INCOMING_DTMF_START_V02 = 0x08, /**<  Received an IP-start continuous DTMF message \n  */
  DTMF_EVENT_IP_INCOMING_DTMF_STOP_V02 = 0x09, /**<  Received an IP-stop continuous DTMF message  */
  DTMF_EVENT_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}dtmf_event_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Call identifier for the current call.
  */

  dtmf_event_enum_v02 dtmf_event;
  /**<   DTMF event. Values: \n
      - DTMF_EVENT_REV_BURST (0x00) --  Sends a CDMA-burst DTMF \n 
      - DTMF_EVENT_REV_START_CONT (0x01) --  Starts a continuous DTMF tone \n 
      - DTMF_EVENT_REV_STOP_CONT (0x03) --  Stops a continuous DTMF tone \n 
      - DTMF_EVENT_FWD_BURST (0x05) --  Received a CDMA-burst DTMF message \n 
      - DTMF_EVENT_FWD_START_CONT (0x06) --  Received a start-continuous DTMF tone order \n 
      - DTMF_EVENT_FWD_STOP_CONT (0x07) --  Received a stop-continuous DTMF tone order \n 
      - DTMF_EVENT_IP_INCOMING_DTMF_START (0x08) --  Received an IP-start continuous DTMF message \n 
      - DTMF_EVENT_IP_INCOMING_DTMF_STOP (0x09) --  Received an IP-stop continuous DTMF message  
 */

  uint32_t digit_buffer_len;  /**< Must be set to # of elements in digit_buffer */
  char digit_buffer[QMI_VOICE_DIALED_DIGIT_BUFFER_MAX_V02];
  /**<   DTMF digit buffer in ASCII string.
  */
}voice_dtmf_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Indicates that a DTMF event has been received. */
typedef struct {

  /* Mandatory */
  /*  DTMF Information */
  voice_dtmf_info_type_v02 dtmf_info;

  /* Optional */
  /*  DTMF Pulse Width */
  uint8_t on_length_valid;  /**< Must be set to true if on_length is being passed */
  dtmf_onlength_enum_v02 on_length;
  /**<   Values: \n 
       - 0x00 -- DTMF_ONLENGTH_95MS  -- 95 ms \n
       - 0x01 -- DTMF_ONLENGTH_150MS -- 150 ms \n
       - 0x02 -- DTMF_ONLENGTH_200MS -- 200 ms \n
       - 0x03 -- DTMF_ONLENGTH_250MS -- 250 ms \n
       - 0x04 -- DTMF_ONLENGTH_300MS -- 300 ms \n
       - 0x05 -- DTMF_ONLENGTH_350MS -- 350 ms \n
       - 0x06 -- DTMF_ONLENGTH_SMS   -- SMS Tx special pulse width
  */

  /* Optional */
  /*  DTMF Interdigit Interval */
  uint8_t off_length_valid;  /**< Must be set to true if off_length is being passed */
  dtmf_offlength_enum_v02 off_length;
  /**<   Values: \n 
       - 0x00 -- DTMF_OFFLENGTH_60MS  -- \n 60 ms \n
       - 0x01 -- DTMF_OFFLENGTH_100MS -- \n 100 ms \n
       - 0x02 -- DTMF_OFFLENGTH_150MS -- \n 150 ms \n
       - 0x03 -- DTMF_OFFLENGTH_200MS -- \n 200 ms
  */

  /* Optional */
  /*  IP Incoming DTMF Tone Volume */
  uint8_t volume_valid;  /**< Must be set to true if volume is being passed */
  uint16_t volume;
  /**<   DTMF tone power level as described in \hyperref[RFC4733]{RFC4733}.
  */
}voice_dtmf_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Sets the voice privacy preference (applicable only for 3GPP2). */
typedef struct {

  /* Mandatory */
  /*  Voice Privacy Preference */
  voice_privacy_enum_v02 privacy_pref;
  /**<   Values: \n 
       - 0x00 -- VOICE_PRIVACY_STANDARD -- Standard privacy \n
       - 0x01 -- VOICE_PRIVACY_ENHANCED -- Enhanced privacy
  */
}voice_set_preferred_privacy_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Sets the voice privacy preference (applicable only for 3GPP2). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}voice_set_preferred_privacy_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Call identifier for the call.
  */

  voice_privacy_enum_v02 voice_privacy;
  /**<   Voice privacy. Values: \n 
       - 0x00 -- VOICE_PRIVACY_STANDARD -- Standard privacy \n
       - 0x01 -- VOICE_PRIVACY_ENHANCED -- Enhanced privacy
  */
}voice_privacy_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Indicates a change in the voice privacy of a call 
             (applicable only for 3GPP2). */
typedef struct {

  /* Mandatory */
  /*  Voice Privacy Information */
  voice_privacy_info_type_v02 voice_privacy_info;
}voice_privacy_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  ALS_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  ALS_LINE1_V02 = 0x00, 
  ALS_LINE2_V02 = 0x01, 
  ALS_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}als_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_CAPABILITY_RESTRICT_CAUSE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_RESTRICT_CAUSE_NONE_V02 = 0x00, /**<  No call restriction \n  */
  VOICE_RESTRICT_CAUSE_DISABLED_V02 = 0x01, /**<  Corresponding call attribute is disabled \n  */
  VOICE_RESTRICT_CAUSE_RAT_V02 = 0x02, /**<  Call attribute is not supported by the RAT  */
  VOICE_RESTRICT_CAUSE_HD_V02 = 0x03, /**<  Call attribute is not supported because there is no HD support  */
  VOICE_CAPABILITY_RESTRICT_CAUSE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_capability_restrict_cause_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  voice_call_attribute_type_mask_v02 audio_attrib;
  /**<   Call's audio capabilities; 
       bitmask of call attributes. Values: \n
       - Bit 0 (0x01) -- VOICE_CALL_ATTRIB_TX -- Transmission \n
       - Bit 1 (0x02) -- VOICE_CALL_ATTRIB_RX -- Receiving
  */

  voice_capability_restrict_cause_enum_v02 audio_cause;
  /**<   Call audio capability restriction cause. Values: \n
      - VOICE_RESTRICT_CAUSE_NONE (0x00) --  No call restriction \n 
      - VOICE_RESTRICT_CAUSE_DISABLED (0x01) --  Corresponding call attribute is disabled \n 
      - VOICE_RESTRICT_CAUSE_RAT (0x02) --  Call attribute is not supported by the RAT 
      - VOICE_RESTRICT_CAUSE_HD (0x03) --  Call attribute is not supported because there is no HD support 
 */

  voice_call_attribute_type_mask_v02 video_attrib;
  /**<   Call's video capabilities; 
       bitmask of call attributes. Values: \n
       - Bit 0 (0x01) -- VOICE_CALL_ATTRIB_TX -- Transmission \n
       - Bit 1 (0x02) -- VOICE_CALL_ATTRIB_RX -- Receiving
  */

  voice_capability_restrict_cause_enum_v02 video_cause;
  /**<   Call video capability restriction cause. Values: \n
      - VOICE_RESTRICT_CAUSE_NONE (0x00) --  No call restriction \n 
      - VOICE_RESTRICT_CAUSE_DISABLED (0x01) --  Corresponding call attribute is disabled \n 
      - VOICE_RESTRICT_CAUSE_RAT (0x02) --  Call attribute is not supported by the RAT 
      - VOICE_RESTRICT_CAUSE_HD (0x03) --  Call attribute is not supported because there is no HD support 
 */
}voice_ip_call_capabilities_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  voice_call_attribute_type_mask_v02 audio_attrib;
  /**<   Call's audio capabilities; 
       bitmask of call attributes. Values: \n
       - Bit 0 (0x01) -- VOICE_CALL_ATTRIB_TX -- Transmission \n
       - Bit 1 (0x02) -- VOICE_CALL_ATTRIB_RX -- Receiving
  */

  voice_capability_restrict_cause_enum_v02 audio_cause;
  /**<   Call audio capability restriction cause. Values: \n
      - VOICE_RESTRICT_CAUSE_NONE (0x00) --  No call restriction \n 
      - VOICE_RESTRICT_CAUSE_DISABLED (0x01) --  Corresponding call attribute is disabled \n 
      - VOICE_RESTRICT_CAUSE_RAT (0x02) --  Call attribute is not supported by the RAT 
      - VOICE_RESTRICT_CAUSE_HD (0x03) --  Call attribute is not supported because there is no HD support 
 */

  voice_call_attribute_type_mask_v02 video_attrib;
  /**<   Call's video capabilities; 
       bitmask of call attributes. Values: \n
       - Bit 0 (0x01) -- VOICE_CALL_ATTRIB_TX -- Transmission \n
       - Bit 1 (0x02) -- VOICE_CALL_ATTRIB_RX -- Receiving
  */

  voice_capability_restrict_cause_enum_v02 video_cause;
  /**<   Call video capability restriction cause. Values: \n
      - VOICE_RESTRICT_CAUSE_NONE (0x00) --  No call restriction \n 
      - VOICE_RESTRICT_CAUSE_DISABLED (0x01) --  Corresponding call attribute is disabled \n 
      - VOICE_RESTRICT_CAUSE_RAT (0x02) --  Call attribute is not supported by the RAT 
      - VOICE_RESTRICT_CAUSE_HD (0x03) --  Call attribute is not supported because there is no HD support 
 */
}voice_ip_call_capabilities_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  uint32_t number_len;  /**< Must be set to # of elements in number */
  char number[QMI_VOICE_SIP_URI_MAX_V02];
  /**<   Child number. This number can contain up to 128 ASCII characters.
       Length range: 0 to 128.
  */
}voice_child_number_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  uint32_t display_text_len;  /**< Must be set to # of elements in display_text */
  uint16_t display_text[QMI_VOICE_DISPLAY_TEXT_MAX_LEN_V02];
  /**<   Display text. This text can contain up to 98 UTF-16 characters
       and it is not guaranteed to be NULL terminated.
       Length range: 0 to 98.
  */
}voice_display_text_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  call_state_enum_v02 call_state;
  /**<   Call state. Values: \n
       - 0x01 -- CALL_STATE_ORIGINATION    -- Origination \n
       - 0x02 -- CALL_STATE_INCOMING       -- Incoming \n
       - 0x03 -- CALL_STATE_CONVERSATION   -- Conversation \n
       - 0x04 -- CALL_STATE_CC_IN_PROGRESS -- Call is originating but waiting \n
                                              for call control to complete \n
       - 0x05 -- CALL_STATE_ALERTING       -- Alerting \n
       - 0x06 -- CALL_STATE_HOLD           -- Hold \n
       - 0x07 -- CALL_STATE_WAITING        -- Waiting \n
       - 0x08 -- CALL_STATE_DISCONNECTING  -- Disconnecting \n
       - 0x09 -- CALL_STATE_END            -- End \n
       - 0x0A -- CALL_STATE_SETUP          -- MT call is in Setup state in 3GPP
  */

  call_type_enum_v02 call_type;
  /**<   Call type. Values: \n
       - 0x00 -- CALL_TYPE_VOICE         -- Voice \n
       - 0x02 -- CALL_TYPE_VOICE_IP      -- Voice over IP \n
       - 0x03 -- CALL_TYPE_VT            -- Videotelephony call over IP \n
       - 0x04 -- CALL_TYPE_VIDEOSHARE    -- Videoshare \n
       - 0x05 -- CALL_TYPE_TEST          -- Test call type \n       
       - 0x06 -- CALL_TYPE_OTAPA         -- OTAPA \n
       - 0x07 -- CALL_TYPE_STD_OTASP     -- Standard OTASP \n
       - 0x08 -- CALL_TYPE_NON_STD_OTASP -- Nonstandard OTASP \n
       - 0x09 -- CALL_TYPE_EMERGENCY     -- Emergency \n
       - 0x0A -- CALL_TYPE_SUPS          -- Supplementary service \n
       - 0x0B -- CALL_TYPE_EMERGENCY_IP  -- Emergency VoIP \n
       - 0x0D -- CALL_TYPE_EMERGENCY_VT  -- Emergency videotelephony call over IP
  */

  call_direction_enum_v02 direction;
  /**<   Direction. Values: \n
       - 0x01 -- CALL_DIRECTION_MO -- MO call \n
       - 0x02 -- CALL_DIRECTION_MT -- MT call
  */

  call_mode_enum_v02 mode;
  /**<   Mode. Values: \n
      - CALL_MODE_NO_SRV (0x00) --  No service \n 
      - CALL_MODE_CDMA (0x01) --  CDMA \n 
      - CALL_MODE_GSM (0x02) --  GSM \n 
      - CALL_MODE_UMTS (0x03) --  UMTS \n 
      - CALL_MODE_LTE (0x04) --  LTE \n 
      - CALL_MODE_TDS (0x05) --  TD-SCDMA \n 
      - CALL_MODE_UNKNOWN (0x06) --  Unknown \n 
      - CALL_MODE_WLAN (0x07) --  WLAN 
 */

  uint8_t is_mpty;
  /**<   Multiparty indicator. Values: \n
       - 0x00 -- FALSE \n
       - 0x01 -- TRUE
  */

  als_enum_v02 als;
  /**<   ALS line indicator. Values: \n
       - 0x00 -- ALS_LINE1 -- Line 1 (default) \n
       - 0x01 -- ALS_LINE2 -- Line 2
  */
}voice_call_info2_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  pi_num_enum_v02 number_pi;
  /**<   Presentation indicator. Values: \n
       - 0x00 -- PRESENTATION_ALLOWED -- Allowed presentation \n
       - 0x01 -- PRESENTATION_RESTRICTED -- Restricted presentation \n
       - 0x02 -- PRESENTATION_NUM_ UNAVAILABLE -- Unavailable presentation \n
       - 0x04 -- PRESENTATION_PAYPHONE -- Payphone presentation (GSM/UMTS specific)
  */

  uint32_t number_len;  /**< Must be set to # of elements in number */
  char number[QMI_VOICE_NUMBER_MAX_V02];
  /**<   Remote party number in ASCII characters.
  */
}voice_remote_party_number2_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  pi_name_enum_v02 name_pi;
  /**<   Name presentation indicator. Values: \n
       - 0x00 -- PRESENTATION_NAME_ PRESENTATION_ALLOWED -- Allowed presentation \n
       - 0x01 -- PRESENTATION_NAME_ PRESENTATION_RESTRICTED -- Restricted presentation \n
       - 0x02 -- PRESENTATION_NAME_ UNAVAILABLE -- Unavailable presentation \n
       - 0x03 -- PRESENTATION_NAME_NAME_ PRESENTATION_RESTRICTED -- Restricted name presentation
  */

  uint8_t coding_scheme;
  /**<   Refer to \hyperref[STD-23038]{3GPP TS 23.038} Section 5 for coding schemes.
  */

  uint32_t name_len;  /**< Must be set to # of elements in name */
  char name[QMI_VOICE_CALLER_NAME_MAX_V02];
  /**<   Caller name per the coding scheme.
  */
}voice_remote_party_name2_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  alerting_type_enum_v02 alerting_type;
  /**<   Alerting type. Values: \n
       - 0x00 -- ALERTING_LOCAL -- Local \n
       - 0x01 -- ALERTING_REMOTE -- Remote
  */
}voice_alerting_type_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  uus_type_enum_v02 uus_type;
  /**<   UUS type. Values: \n
       - 0x00 -- UUS_TYPE_DATA -- Data \n
       - 0x01 -- UUS_TYPE1_IMPLICIT -- Type 1 implicit \n
       - 0x02 -- UUS_TYPE1_REQUIRED -- Type 1 required \n
       - 0x03 -- UUS_TYPE1_NOT_REQUIRED -- Type 1 not required \n
       - 0x04 -- UUS_TYPE2_REQUIRED -- Type 2 required \n
       - 0x05 -- UUS_TYPE2_NOT_REQUIRED -- Type 2 not required \n
       - 0x06 -- UUS_TYPE3_REQUIRED -- Type 3 required \n
       - 0x07 -- UUS_TYPE3_NOT_REQUIRED -- Type 3 not required
  */

  uus_dcs_enum_v02 uus_dcs;
  /**<   UUS data coding scheme. Values: \n
       - 0x01 -- UUS_DCS_USP -- USP \n
       - 0x02 -- UUS_DCS_OHLP -- OHLP \n
       - 0x03 -- UUS_DCS_X244 -- X244 \n
       - 0x04 -- UUS_DCS_SMCF -- SMCF \n
       - 0x05 -- UUS_DCS_IA5 -- IA5 \n
       - 0x06 -- UUS_DCS_RV12RD -- RV12RD \n
       - 0x07 -- UUS_DCS_Q931UNCCM -- Q931UNCCM
  */

  uint32_t uus_data_len;  /**< Must be set to # of elements in uus_data */
  uint8_t uus_data[QMI_VOICE_UUS_DATA_MAX_V02];
  /**<   UUS data encoded as per coding scheme.
  */
}voice_uus_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  uint16_t srv_opt;
  /**<   Service option per \hyperref[STD-CR1001F]{3GPP2 C.R1001-F} Table 3.1-1; see 
       Table @latexonly\ref{tbl:serviceOption}@endlatexonly for standard
       service option number assignments. 
  */
}voice_srv_opt_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  alpha_dcs_enum_v02 alpha_dcs;
  /**<   Alpha coding scheme. Values: \n
       - 0x01 -- ALPHA_DCS_GSM  -- SMS default 7-bit coded alphabet as defined 
                 in \hyperref[STD-23038]{3GPP TS 23.038} with bit 8 set to 0 \n
       - 0x02 -- ALPHA_DCS_UCS2 -- UCS2
  */

  uint32_t alpha_text_len;  /**< Must be set to # of elements in alpha_text */
  uint8_t alpha_text[QMI_VOICE_ALPHA_TEXT_MAX_V02];
  /**<   Data encoded per alpha_dcs.
  */
}voice_alpha_ident_with_id_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  pi_num_enum_v02 conn_num_pi;
  /**<   Presentation indicator; refer to 
       \hyperref[STD-CS0005D]{3GPP2 C.S0005-D} Table 2.7.4.4-1 
       for valid values.
  */

  voice_si_enum_v02 conn_num_si;
  /**<   Connected number screening indicator. Values: \n
       - 0x00 -- QMI_VOICE_SI_USER_PROVIDED_ NOT_SCREENED -- Provided user is not screened \n
       - 0x01 -- QMI_VOICE_SI_USER_PROVIDED_ VERIFIED_PASSED -- Provided user passed verification \n
       - 0x02 -- QMI_VOICE_SI_USER_PROVIDED_ VERIFIED_FAILED -- Provided user failed verification \n
       - 0x03 -- QMI_VOICE_SI_NETWORK_ PROVIDED -- Provided network
  */

  voice_num_type_enum_v02 conn_num_type;
  /**<   Connected number type. Values: \n
       - 0x00 -- QMI_VOICE_NUM_TYPE_ UNKNOWN -- Unknown \n
       - 0x01 -- QMI_VOICE_NUM_TYPE_ INTERNATIONAL -- International \n
       - 0x02 -- QMI_VOICE_NUM_TYPE_ NATIONAL -- National \n
       - 0x03 -- QMI_VOICE_NUM_TYPE_ NETWORK_ SPECIFIC -- Network-specific \n
       - 0x04 -- QMI_VOICE_NUM_TYPE_ SUBSCRIBER -- Subscriber \n
       - 0x05 -- QMI_VOICE_NUM_TYPE_ RESERVED -- Reserved \n
       - 0x06 -- QMI_VOICE_NUM_TYPE_ ABBREVIATED -- Abbreviated \n
       - 0x07 -- QMI_VOICE_NUM_TYPE_ RESERVED_EXTENSION -- Reserved extension
  */

  voice_num_plan_enum_v02 conn_num_plan;
  /**<   Connected number plan. Values: \n
       - 0x00 -- QMI_VOICE_NUM_PLAN_ UNKNOWN -- Unknown \n
       - 0x01 -- QMI_VOICE_NUM_PLAN_ISDN -- ISDN \n
       - 0x03 -- QMI_VOICE_NUM_PLAN_DATA -- Data \n
       - 0x04 -- QMI_VOICE_NUM_PLAN_TELEX -- Telex \n
       - 0x08 -- QMI_VOICE_NUM_PLAN_ NATIONAL -- National \n
       - 0x09 -- QMI_VOICE_NUM_PLAN_ PRIVATE -- Private \n
       - 0x0B -- QMI_VOICE_NUM_PLAN_ RESERVED_CTS -- Reserved cordless telephony system \n
       - 0x0F -- QMI_VOICE_NUM_PLAN_ RESERVED_EXTENSION -- Reserved extension
  */

  uint32_t conn_num_len;  /**< Must be set to # of elements in conn_num */
  char conn_num[QMI_VOICE_CALLER_ID_MAX_V02];
  /**<   Connected number in ASCII characters.
  */
}voice_conn_num_with_id_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  uint32_t diagnostic_info_len;  /**< Must be set to # of elements in diagnostic_info */
  uint8_t diagnostic_info[QMI_VOICE_DIAGNOSTIC_INFO_MAX_V02];
  /**<   Diagnostic information.
  */
}voice_diagnostic_info_with_id_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  pi_num_enum_v02 num_pi;
  /**<   Presentation indicator. Values: \n
       - 0x00 -- PRESENTATION_ALLOWED -- Allowed presentation \n
       - 0x01 -- PRESENTATION_RESTRICTED -- Restricted presentation \n
       - 0x02 -- PRESENTATION_NUM_ UNAVAILABLE -- Unavailable presentation \n
       - 0x04 -- PRESENTATION_PAYPHONE -- Payphone presentation (GSM/UMTS specific)
  */

  voice_si_enum_v02 num_si;
  /**<   Number screening indicator. Values: \n
       - 0x00 -- QMI_VOICE_SI_USER_PROVIDED_ NOT_SCREENED -- Provided user is not screened \n
       - 0x01 -- QMI_VOICE_SI_USER_PROVIDED_ VERIFIED_PASSED -- Provided user passed verification \n
       - 0x02 -- QMI_VOICE_SI_USER_PROVIDED_ VERIFIED_FAILED -- Provided user failed verification \n
       - 0x03 -- QMI_VOICE_SI_NETWORK_ PROVIDED -- Provided network
  */

  voice_num_type_enum_v02 num_type;
  /**<   Number type. Values: \n
       - 0x00 -- QMI_VOICE_NUM_TYPE_ UNKNOWN -- Unknown \n
       - 0x01 -- QMI_VOICE_NUM_TYPE_ INTERNATIONAL -- International \n
       - 0x02 -- QMI_VOICE_NUM_TYPE_ NATIONAL -- National \n
       - 0x03 -- QMI_VOICE_NUM_TYPE_ NETWORK_ SPECIFIC -- Network-specific \n
       - 0x04 -- QMI_VOICE_NUM_TYPE_ SUBSCRIBER -- Subscriber \n
       - 0x05 -- QMI_VOICE_NUM_TYPE_ RESERVED -- Reserved \n
       - 0x06 -- QMI_VOICE_NUM_TYPE_ ABBREVIATED -- Abbreviated \n
       - 0x07 -- QMI_VOICE_NUM_TYPE_ RESERVED_EXTENSION -- Reserved extension
  */

  voice_num_plan_enum_v02 num_plan;
  /**<   Number plan. Values: \n
       - 0x00 -- QMI_VOICE_NUM_PLAN_ UNKNOWN -- Unknown \n
       - 0x01 -- QMI_VOICE_NUM_PLAN_ISDN -- ISDN \n
       - 0x03 -- QMI_VOICE_NUM_PLAN_DATA -- Data \n
       - 0x04 -- QMI_VOICE_NUM_PLAN_TELEX -- Telex \n
       - 0x08 -- QMI_VOICE_NUM_PLAN_ NATIONAL -- National \n
       - 0x09 -- QMI_VOICE_NUM_PLAN_ PRIVATE -- Private \n
       - 0x0B -- QMI_VOICE_NUM_PLAN_ RESERVED_CTS -- Reserved cordless telephony system \n
       - 0x0F -- QMI_VOICE_NUM_PLAN_ RESERVED_EXTENSION -- Reserved extension
  */

  uint32_t num_len;  /**< Must be set to # of elements in num */
  char num[QMI_VOICE_NUMBER_MAX_V02];
  /**<   Number in ASCII characters.
  */
}voice_num_with_id_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  alerting_pattern_enum_v02 alerting_pattern;
  /**<   Alerting pattern. Values: \n
       - 0x00 -- QMI_VOICE_ALERTING_ PATTERN_1 -- Pattern 1 \n
       - 0x01 -- QMI_VOICE_ALERTING_ PATTERN_2 -- Pattern 2 \n
       - 0x02 -- QMI_VOICE_ALERTING_ PATTERN_3 -- Pattern 3 \n
       - 0x04 -- QMI_VOICE_ALERTING_ PATTERN_5 -- Pattern 5 \n
       - 0x05 -- QMI_VOICE_ALERTING_ PATTERN_6 -- Pattern 6 \n
       - 0x06 -- QMI_VOICE_ALERTING_ PATTERN_7 -- Pattern 7 \n
       - 0x07 -- QMI_VOICE_ALERTING_ PATTERN_8 -- Pattern 8 \n
       - 0x08 -- QMI_VOICE_ALERTING_ PATTERN_9 -- Pattern 9
  */
}voice_alerting_pattern_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  voice_call_attribute_type_mask_v02 call_attributes;
  /**<   Bitmask of call attributes. Values: \n
       - Bit 0 (0x01) -- VOICE_CALL_ATTRIB_TX -- Transmission \n
       - Bit 1 (0x02) -- VOICE_CALL_ATTRIB_RX -- Receiving
  */
}voice_call_attributes_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  vs_variant_type_enum_v02 vs_variant;
  /**<   Call variant. Values: \n
      - VS_VARIANT_RCS_E (0x01) --  RCSe \n 
      - VS_VARIANT_RCS_V5 (0x02) --  RCSv5 
 */
}voice_vs_variant_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  char sip_uri[QMI_VOICE_SIP_URI_MAX_V02 + 1];
  /**<   SIP URI number as an ASCII string. Length range: 1 to 128.
  */
}voice_sip_uri_with_id_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  uint8_t is_srvcc_call;
  /**<   Whether the call is an SRVCC call; boolean value.
  */
}voice_is_srvcc_call_with_id_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  uint8_t is_add_info_present;
  /**<   Whether the call has additional information; boolean value.
  */

  uint16_t num_indications;
  /**<   Number of indications in which the additional call information 
       is sent.
  */
}voice_is_add_info_present_with_id_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_CALL_ATTRIB_STATUS_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_CALL_ATTRIB_STATUS_OK_V02 = 0, /**<  No additional information \n  */
  VOICE_CALL_ATTRIB_STATUS_RETRY_NEEDED_V02 = 1, /**<  Retry for the media is needed \n  */
  VOICE_CALL_ATTRIB_STATUS_MEDIA_PAUSED_V02 = 2, /**<  Media is paused \n  */
  VOICE_CALL_ATTRIB_STATUS_MEDIA_NOT_READY_V02 = 3, /**<  Media is not ready due to the quality of service  */
  VOICE_CALL_ATTRIB_STATUS_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_call_attrib_status_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_CALL_MODIFIED_CAUSE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_CALL_MODIFIED_CAUSE_NONE_V02 = 0x00, /**<  No call modify cause information \n  */
  VOICE_CALL_MODIFIED_CAUSE_UPGRADE_DUE_TO_LOCAL_REQ_V02 = 0x01, /**<  Upgrade due to a local request \n  */
  VOICE_CALL_MODIFIED_CAUSE_UPGRADE_DUE_TO_REMOTE_REQ_V02 = 0x02, /**<  Upgrade due to a remote request \n  */
  VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_LOCAL_REQ_V02 = 0x03, /**<  Downgrade due to a local request \n  */
  VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_REMOTE_REQ_V02 = 0x04, /**<  Downgrade due to a remote request \n  */
  VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_RTP_TIMEOUT_V02 = 0x05, /**<  Downgrade due to an RTP timeout \n  */
  VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_QOS_V02 = 0x06, /**<  Downgrade due to QOS \n  */
  VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_PACKET_LOSS_V02 = 0x07, /**<  Downgrade due to a packet loss \n  */
  VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_LOW_THRPUT_V02 = 0x08, /**<  Downgrade due to low throughput \n  */
  VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_THERM_MITIGATION_V02 = 0x09, /**<  Downgrade due to thermal mitigation \n  */
  VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_GENERIC_ERROR_V02 = 0x0A, /**<  Downgrade due to a general error \n  */
  VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_LIPSYNC_V02 = 0x0B, /**<  Downgrade due to lipsync  */
  VOICE_CALL_MODIFIED_CAUSE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_call_modified_cause_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call
  */

  voice_call_attrib_status_enum_v02 call_attrib_status;
  /**<   Call attribute status. Values: \n
      - VOICE_CALL_ATTRIB_STATUS_OK (0) --  No additional information \n 
      - VOICE_CALL_ATTRIB_STATUS_RETRY_NEEDED (1) --  Retry for the media is needed \n 
      - VOICE_CALL_ATTRIB_STATUS_MEDIA_PAUSED (2) --  Media is paused \n 
      - VOICE_CALL_ATTRIB_STATUS_MEDIA_NOT_READY (3) --  Media is not ready due to the quality of service 
 */
}voice_call_attrib_status_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  uint8_t parent_call_id;
  /**<   Unique identifier of the call that was transitioned (SRVCC) into 
       the new call (call_id).
  */

  uint8_t is_parent_id_cleared;
  /**<   Informs the clients whether the parent call instance was cleared 
       in the SRVCC process; boolean value.
  */
}voice_srvcc_parent_call_id_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  pi_num_enum_v02 ip_num_pi;
  /**<   Presentation indicator. Values: \n
       - 0x00 -- PRESENTATION_ALLOWED -- Allowed presentation \n
       - 0x01 -- PRESENTATION_RESTRICTED -- Restricted presentation       
  */

  char ip_num[QMI_VOICE_SIP_URI_MAX_V02 + 1];
  /**<   Number as an ASCII string. Length range: 1 to 128.
  */
}voice_ip_num_id_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  pi_num_enum_v02 conn_ip_num_pi;
  /**<   Presentation indicator. Values: \n
       - 0x00 -- PRESENTATION_ALLOWED -- Allowed presentation \n
       - 0x01 -- PRESENTATION_RESTRICTED -- Restricted presentation       
  */

  char conn_ip_num[QMI_VOICE_SIP_URI_MAX_V02 + 1];
  /**<   Connected number in ASCII characters. Length range: 1 to 128.
  */
}voice_conn_ip_num_with_id_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  uint8_t media_id;
  /**<   Media ID.
  */
}voice_media_id_with_id_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  call_end_reason_enum_v02 orig_fail_reason;
  /**<   Call origination failure reason; 
       see @latexonly Table~\ref{tbl:endReasons}@endlatexonly for a list of 
       valid voice-related call end reasons.  
  */
}voice_orig_fail_reason_with_id_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  voice_remote_party_number_ext_type_v02 rp_num_info;
  /**<   Remote party number information for the call.
  */
}voice_remote_party_number_ext_with_id_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique identifier for the call set by the client.
  */

  pi_name_enum_v02 caller_name_pi;
  /**<   Name presentation indicator. Values: \n
       - 0x00 -- PRESENTATION_NAME_ PRESENTATION_ALLOWED -- Allowed presentation \n
       - 0x01 -- PRESENTATION_NAME_ PRESENTATION_RESTRICTED -- Restricted presentation \n
       - 0x02 -- PRESENTATION_NAME_ UNAVAILABLE -- Unavailable presentation \n
       - 0x03 -- PRESENTATION_NAME_NAME_ PRESENTATION_RESTRICTED -- Restricted name presentation
  */
}voice_caller_name_pi_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique identifier for the call set by the client.
  */

  uint8_t is_connected_number_ECT;
  /**<   Whether the connected number occurred as a result of an ECT. Values: \n
       - 0x00 -- Connected number is not a result of an ECT \n
       - 0x01 -- Connected number is a result of an ECT
  */
}voice_ect_connected_num_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  uint8_t raw_call_end_cause_code;
  /**<   Values: \n
       - 26 -- Non-selected user clearing \n
       - 31 -- Normal, unspecified \n
       Refer to Annex H of \hyperref[STD-24008]{3GPP TS 24.008} for 
       detailed cause code information.
    */
}voice_raw_call_end_cause_code_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique identifier for the call set by the client.
  */

  uint32_t ip_hist_info_len;  /**< Must be set to # of elements in ip_hist_info */
  uint16_t ip_hist_info[QMI_VOICE_IP_HIST_INFO_MAX_LEN_V02];
  /**<   IP history information. This field contains history-info fields from 
       the SIP header in the order in which they occur in the header.  
       Successive fields are separated by 
       @latexonly\textbackslash r\textbackslash n.@endlatexonly
       If a field does not fit into the remaining space in a buffer, neither
       it nor any subsequent field is be added.
  */
}voice_ip_hist_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique identifier for the call set by the client.
	*/

  uint8_t conf_is_enabled;
  /**<   Remote party conference capabilities. Values: \n
          TRUE -- Conference capability is enabled in the remote party \n
          FALSE -- Conference capability is disabled in the remote party
         */
}voice_remote_party_conf_cap_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  rtt_mode_type_v02 rtt_mode;
  /**<   Whether the current call is an RTT call. Values: \n
      - RTT_MODE_DISABLED (0) --  non-RTT call \n 
      - RTT_MODE_FULL (1) --  RTT call with RTT being used from both sides 
 */
}voice_call_rtt_mode_status_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  rtt_mode_type_v02 local_rtt_cap;
  /**<   Local RTT capability. Values: \n
      - RTT_MODE_DISABLED (0) --  non-RTT call \n 
      - RTT_MODE_FULL (1) --  RTT call with RTT being used from both sides 
 */

  rtt_mode_type_v02 peer_rtt_cap;
  /**<   Peer's RTT capability. Values: \n
      - RTT_MODE_DISABLED (0) --  non-RTT call \n 
      - RTT_MODE_FULL (1) --  RTT call with RTT being used from both sides 
 */
}voice_call_rtt_capabilities_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  voice_call_rtt_capabilities_type_v02 rtt_capabilities;
  /**<   Local and Peer RTT capability.
  */
}voice_call_rtt_capabilities_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique identifier for the call set by the client.
  */

  uint32_t ip_alert_info_len;  /**< Must be set to # of elements in ip_alert_info */
  uint8_t ip_alert_info[QMI_VOICE_IP_ALERT_INFO_MAX_LEN_V02];
  /**<   IP alert information in UTF-8 characters. This field contains alert information fields from 
       the SIP header in the order in which they occur in the header.  
       If a field does not fit into the remaining space in a buffer, neither
       it nor any subsequent field is be added.
  */
}voice_ip_alert_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t network_supports_unwanted_call;
  /**<   Indicates if the network supports the unwanted call feature. This value is obtained from the
       network, if it is set to TRUE, then the user gets the option on UI to reject or end the received
       call by selecting the unwanted call option.
  */

  mt_ims_verstat_enum_v02 mt_call_verstat_info;
  /**<   Validation index of the received call. \n
      - MT_IMS_TN_VALIDATION_NONE (0) --  No telephone number validation obtained from the network \n 
      - MT_IMS_TN_VALIDATION_PASS (1) --  Telephone number validation from the network PASSED \n 
      - MT_IMS_TN_VALIDATION_FAIL (2) --  Telephone number validation from the network FAILED \n 
 */
}voice_MT_call_received_verstat_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  voice_MT_call_received_verstat_type_v02 verstat_info;
  /**<   Verstat info for the received call.
   */
}voice_MT_call_verstat_with_id_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  uint32_t emerg_srv_categ;
  /**<   emergency service category received from IMS.
   */
}voice_emerg_srv_categ_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Indicates a change in the call information. */
typedef struct {

  /* Mandatory */
  /*  Array of Call Information */
  uint32_t call_info_len;  /**< Must be set to # of elements in call_info */
  voice_call_info2_type_v02 call_info[QMI_VOICE_CALL_INFO_MAX_V02];

  /* Optional */
  /*  Array of Remote Party Number */
  uint8_t remote_party_number_valid;  /**< Must be set to true if remote_party_number is being passed */
  uint32_t remote_party_number_len;  /**< Must be set to # of elements in remote_party_number */
  voice_remote_party_number2_type_v02 remote_party_number[QMI_VOICE_REMOTE_PARTY_NUMBER_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Remote Party Name** */
  uint8_t remote_party_name_valid;  /**< Must be set to true if remote_party_name is being passed */
  uint32_t remote_party_name_len;  /**< Must be set to # of elements in remote_party_name */
  voice_remote_party_name2_type_v02 remote_party_name[QMI_VOICE_REMOTE_PARTY_NAME_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Alerting Type** */
  uint8_t alerting_type_valid;  /**< Must be set to true if alerting_type is being passed */
  uint32_t alerting_type_len;  /**< Must be set to # of elements in alerting_type */
  voice_alerting_type_type_v02 alerting_type[QMI_VOICE_ALERTING_TYPE_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Service Option** */
  uint8_t srv_opt_valid;  /**< Must be set to true if srv_opt is being passed */
  uint32_t srv_opt_len;  /**< Must be set to # of elements in srv_opt */
  voice_srv_opt_type_v02 srv_opt[QMI_VOICE_SRV_OPT_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Call End Reason** */
  uint8_t call_end_reason_valid;  /**< Must be set to true if call_end_reason is being passed */
  uint32_t call_end_reason_len;  /**< Must be set to # of elements in call_end_reason */
  voice_call_end_reason_type_v02 call_end_reason[QMI_VOICE_CALL_END_REASON_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Alpha Identifier** */
  uint8_t alpha_id_valid;  /**< Must be set to true if alpha_id is being passed */
  uint32_t alpha_id_len;  /**< Must be set to # of elements in alpha_id */
  voice_alpha_ident_with_id_type_v02 alpha_id[QMI_VOICE_ALPHA_IDENT_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Connected Party Number */
  uint8_t conn_party_num_valid;  /**< Must be set to true if conn_party_num is being passed */
  uint32_t conn_party_num_len;  /**< Must be set to # of elements in conn_party_num */
  voice_conn_num_with_id_type_v02 conn_party_num[QMI_VOICE_CONNECTED_PARTY_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Diagnostic Information** */
  uint8_t diagnostic_info_valid;  /**< Must be set to true if diagnostic_info is being passed */
  uint32_t diagnostic_info_len;  /**< Must be set to # of elements in diagnostic_info */
  voice_diagnostic_info_with_id_type_v02 diagnostic_info[QMI_VOICE_DIAGNOSTIC_INFO_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Called Party Number** */
  uint8_t called_party_num_valid;  /**< Must be set to true if called_party_num is being passed */
  uint32_t called_party_num_len;  /**< Must be set to # of elements in called_party_num */
  voice_num_with_id_type_v02 called_party_num[QMI_VOICE_CALLED_PARTY_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Redirecting Party Number** */
  uint8_t redirecting_party_num_valid;  /**< Must be set to true if redirecting_party_num is being passed */
  uint32_t redirecting_party_num_len;  /**< Must be set to # of elements in redirecting_party_num */
  voice_num_with_id_type_v02 redirecting_party_num[QMI_VOICE_REDIRECTING_PARTY_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Alerting Pattern** */
  uint8_t alerting_pattern_valid;  /**< Must be set to true if alerting_pattern is being passed */
  uint32_t alerting_pattern_len;  /**< Must be set to # of elements in alerting_pattern */
  voice_alerting_pattern_type_v02 alerting_pattern[QMI_VOICE_ALERTING_PATTERN_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Audio Attributes for VT Call over IP */
  uint8_t audio_attrib_valid;  /**< Must be set to true if audio_attrib is being passed */
  uint32_t audio_attrib_len;  /**< Must be set to # of elements in audio_attrib */
  voice_call_attributes_type_v02 audio_attrib[QMI_VOICE_CALL_ATTRIBUTES_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Video Attributes for VT Call over IP */
  uint8_t video_attrib_valid;  /**< Must be set to true if video_attrib is being passed */
  uint32_t video_attrib_len;  /**< Must be set to # of elements in video_attrib */
  voice_call_attributes_type_v02 video_attrib[QMI_VOICE_CALL_ATTRIBUTES_ARRAY_MAX_V02];

  /* Optional */
  /*  Variant Information for Videoshare Call */
  uint8_t vs_variant_valid;  /**< Must be set to true if vs_variant is being passed */
  uint32_t vs_variant_len;  /**< Must be set to # of elements in vs_variant */
  voice_vs_variant_type_v02 vs_variant[QMI_VOICE_VS_CALL_VARIANT_ARRAY_MAX_V02];

  /* Optional */
  /*  SIP URI for IP Call */
  uint8_t sip_uri_valid;  /**< Must be set to true if sip_uri is being passed */
  uint32_t sip_uri_len;  /**< Must be set to # of elements in sip_uri */
  voice_sip_uri_with_id_type_v02 sip_uri[QMI_VOICE_VS_CALL_VARIANT_ARRAY_MAX_V02];

  /* Optional */
  /*  Is SRVCC call */
  uint8_t is_srvcc_valid;  /**< Must be set to true if is_srvcc is being passed */
  uint32_t is_srvcc_len;  /**< Must be set to # of elements in is_srvcc */
  voice_is_srvcc_call_with_id_type_v02 is_srvcc[QMI_VOICE_IS_SRVCC_CALL_ARRAY_MAX_V02];

  /* Optional */
  /*  Parent Call Info */
  uint8_t srvcc_parent_call_info_valid;  /**< Must be set to true if srvcc_parent_call_info is being passed */
  uint32_t srvcc_parent_call_info_len;  /**< Must be set to # of elements in srvcc_parent_call_info */
  voice_srvcc_parent_call_id_type_v02 srvcc_parent_call_info[QMI_VOICE_SRVCC_PARENT_CALL_ARRAY_MAX_V02];

  /* Optional */
  /*  Local Call Capabilities Information */
  uint8_t local_call_capabilities_info_valid;  /**< Must be set to true if local_call_capabilities_info is being passed */
  uint32_t local_call_capabilities_info_len;  /**< Must be set to # of elements in local_call_capabilities_info */
  voice_ip_call_capabilities_info_type_v02 local_call_capabilities_info[QMI_VOICE_CALL_CAPABILITIES_ARRAY_MAX_V02];

  /* Optional */
  /*  Peer Call Capabilities Information */
  uint8_t peer_call_capabilities_info_valid;  /**< Must be set to true if peer_call_capabilities_info is being passed */
  uint32_t peer_call_capabilities_info_len;  /**< Must be set to # of elements in peer_call_capabilities_info */
  voice_ip_call_capabilities_info_type_v02 peer_call_capabilities_info[QMI_VOICE_CALL_CAPABILITIES_ARRAY_MAX_V02];

  /* Optional */
  /*  Child Number Information */
  uint8_t child_number_valid;  /**< Must be set to true if child_number is being passed */
  uint32_t child_number_len;  /**< Must be set to # of elements in child_number */
  voice_child_number_info_type_v02 child_number[QMI_VOICE_CHILD_NUMBER_ARRAY_MAX_V02];

  /* Optional */
  /*  Display Text */
  uint8_t display_text_valid;  /**< Must be set to true if display_text is being passed */
  uint32_t display_text_len;  /**< Must be set to # of elements in display_text */
  voice_display_text_info_type_v02 display_text[QMI_VOICE_DISPLAY_TEXT_ARRAY_MAX_V02];

  /* Optional */
  /*  Remote Party Number Extension */
  uint8_t ip_num_info_valid;  /**< Must be set to true if ip_num_info is being passed */
  uint32_t ip_num_info_len;  /**< Must be set to # of elements in ip_num_info */
  voice_ip_num_id_type_v02 ip_num_info[QMI_VOICE_REMOTE_PARTY_NUMBER_ARRAY_MAX_V02];

  /* Optional */
  /*  Connected Party Number Extension */
  uint8_t conn_ip_num_info_valid;  /**< Must be set to true if conn_ip_num_info is being passed */
  uint32_t conn_ip_num_info_len;  /**< Must be set to # of elements in conn_ip_num_info */
  voice_conn_ip_num_with_id_type_v02 conn_ip_num_info[QMI_VOICE_CONNECTED_PARTY_ARRAY_MAX_V02];

  /* Optional */
  /*  Media ID */
  uint8_t media_id_valid;  /**< Must be set to true if media_id is being passed */
  uint32_t media_id_len;  /**< Must be set to # of elements in media_id */
  voice_media_id_with_id_type_v02 media_id[QMI_VOICE_CALL_INFO_MAX_V02];

  /* Optional */
  /*  Additional Call Information */
  uint8_t is_add_info_present_valid;  /**< Must be set to true if is_add_info_present is being passed */
  uint32_t is_add_info_present_len;  /**< Must be set to # of elements in is_add_info_present */
  voice_is_add_info_present_with_id_type_v02 is_add_info_present[QMI_VOICE_CALL_INFO_MAX_V02];

  /* Optional */
  /*  Call Attribute Status */
  uint8_t call_attrib_status_valid;  /**< Must be set to true if call_attrib_status is being passed */
  uint32_t call_attrib_status_len;  /**< Must be set to # of elements in call_attrib_status */
  voice_call_attrib_status_type_v02 call_attrib_status[QMI_VOICE_CALL_INFO_MAX_V02];

  /* Optional */
  /*  Origination Failure Reason */
  uint8_t orig_fail_reason_valid;  /**< Must be set to true if orig_fail_reason is being passed */
  uint32_t orig_fail_reason_len;  /**< Must be set to # of elements in orig_fail_reason */
  voice_orig_fail_reason_with_id_type_v02 orig_fail_reason[QMI_VOICE_CALL_INFO_MAX_V02];

  /* Optional */
  /*  Remote Party Number Extension 2 */
  uint8_t remote_party_number_ext2_valid;  /**< Must be set to true if remote_party_number_ext2 is being passed */
  uint32_t remote_party_number_ext2_len;  /**< Must be set to # of elements in remote_party_number_ext2 */
  voice_remote_party_number_ext_with_id_type_v02 remote_party_number_ext2[QMI_VOICE_REMOTE_PARTY_NUMBER_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Second Alpha Identifier** */
  uint8_t second_alpha_ident_valid;  /**< Must be set to true if second_alpha_ident is being passed */
  uint32_t second_alpha_ident_len;  /**< Must be set to # of elements in second_alpha_ident */
  voice_alpha_ident_with_id_type_v02 second_alpha_ident[QMI_VOICE_ALPHA_IDENT_ARRAY_MAX_V02];

  /* Optional */
  /*  Caller Name for IP Call */
  uint8_t ip_caller_name_valid;  /**< Must be set to true if ip_caller_name is being passed */
  uint32_t ip_caller_name_len;  /**< Must be set to # of elements in ip_caller_name */
  voice_ip_caller_name_info_type_v02 ip_caller_name[QMI_VOICE_IP_CALLER_NAME_ARRAY_MAX_V02];

  /* Optional */
  /*  End Reason Text for IP Call */
  uint8_t end_reason_text_valid;  /**< Must be set to true if end_reason_text is being passed */
  uint32_t end_reason_text_len;  /**< Must be set to # of elements in end_reason_text */
  voice_ip_end_reason_text_type_v02 end_reason_text[QMI_VOICE_IP_END_REASON_TEXT_ARRAY_MAX_V02];

  /* Optional */
  /*  Caller Name PI */
  uint8_t caller_name_pi_valid;  /**< Must be set to true if caller_name_pi is being passed */
  uint32_t caller_name_pi_len;  /**< Must be set to # of elements in caller_name_pi */
  voice_caller_name_pi_type_v02 caller_name_pi[QMI_VOICE_IP_CALLER_NAME_ARRAY_MAX_V02];

  /* Optional */
  /*  Called Party Subaddress */
  uint8_t called_party_subaddress_valid;  /**< Must be set to true if called_party_subaddress is being passed */
  uint32_t called_party_subaddress_len;  /**< Must be set to # of elements in called_party_subaddress */
  voice_subaddress_info_type_v02 called_party_subaddress[QMI_VOICE_CALLED_PARTY_SUBADDRESS_ARRAY_MAX_V02];

  /* Optional */
  /*  Is Connected Number ECT */
  uint8_t is_connected_number_ECT_valid;  /**< Must be set to true if is_connected_number_ECT is being passed */
  uint32_t is_connected_number_ECT_len;  /**< Must be set to # of elements in is_connected_number_ECT */
  voice_ect_connected_num_type_v02 is_connected_number_ECT[QMI_VOICE_CALL_INFO_MAX_V02];

  /* Optional */
  /*  Is Secure Call */
  uint8_t is_secure_call_valid;  /**< Must be set to true if is_secure_call is being passed */
  uint32_t is_secure_call_len;  /**< Must be set to # of elements in is_secure_call */
  voice_volte_is_secure_call_type_v02 is_secure_call[QMI_VOICE_CALL_INFO_MAX_V02];

  /* Optional */
  /*  SIP Error Code for IP Call */
  uint8_t sip_error_code_valid;  /**< Must be set to true if sip_error_code is being passed */
  uint32_t sip_error_code_len;  /**< Must be set to # of elements in sip_error_code */
  voice_ip_end_sip_code_type_v02 sip_error_code[QMI_VOICE_IP_END_SIP_CODE_ARRAY_MAX_V02];

  /* Optional */
  /*  Is Called Party Ringing at Remote End */
  uint8_t is_called_party_ringing_valid;  /**< Must be set to true if is_called_party_ringing is being passed */
  uint32_t is_called_party_ringing_len;  /**< Must be set to # of elements in is_called_party_ringing */
  voice_volte_is_called_party_ringing_type_v02 is_called_party_ringing[QMI_VOICE_CALL_INFO_MAX_V02];

  /* Optional */
  /*  Raw Call End Cause Code */
  uint8_t raw_call_end_cause_code_valid;  /**< Must be set to true if raw_call_end_cause_code is being passed */
  uint32_t raw_call_end_cause_code_len;  /**< Must be set to # of elements in raw_call_end_cause_code */
  voice_raw_call_end_cause_code_type_v02 raw_call_end_cause_code[QMI_VOICE_CALL_END_REASON_ARRAY_MAX_V02];

  /* Optional */
  /*  IP History Information */
  uint8_t ip_hist_info_valid;  /**< Must be set to true if ip_hist_info is being passed */
  uint32_t ip_hist_info_len;  /**< Must be set to # of elements in ip_hist_info */
  voice_ip_hist_info_type_v02 ip_hist_info[QMI_VOICE_IP_HIST_INFO_ARRAY_MAX_V02];

  /* Optional */
  /*  Remote Party Conf Capability */
  uint8_t remote_party_conf_capability_valid;  /**< Must be set to true if remote_party_conf_capability is being passed */
  uint32_t remote_party_conf_capability_len;  /**< Must be set to # of elements in remote_party_conf_capability */
  voice_remote_party_conf_cap_type_v02 remote_party_conf_capability[QMI_VOICE_REMOTE_PARTY_CONF_CAP_ARRAY_MAX_V02];

  /* Optional */
  /*  RTT Attribute for VT or VOIP Call */
  uint8_t rtt_mode_valid;  /**< Must be set to true if rtt_mode is being passed */
  uint32_t rtt_mode_len;  /**< Must be set to # of elements in rtt_mode */
  voice_call_rtt_mode_status_type_v02 rtt_mode[QMI_VOICE_RTT_MODE_ARRAY_MAX_V02];

  /* Optional */
  /*  Local and Peer RTT Capabilities Information */
  uint8_t rtt_capabilities_info_valid;  /**< Must be set to true if rtt_capabilities_info is being passed */
  uint32_t rtt_capabilities_info_len;  /**< Must be set to # of elements in rtt_capabilities_info */
  voice_call_rtt_capabilities_info_type_v02 rtt_capabilities_info[QMI_VOICE_RTT_MODE_ARRAY_MAX_V02];

  /* Optional */
  /*  Alternate SIP URI for IP Call */
  uint8_t alternate_sip_uris_valid;  /**< Must be set to true if alternate_sip_uris is being passed */
  uint32_t alternate_sip_uris_len;  /**< Must be set to # of elements in alternate_sip_uris */
  voice_sip_uri_with_id_type_v02 alternate_sip_uris[QMI_VOICE_ALTERNATE_SIP_URI_ARRAY_MAX_V02];

  /* Optional */
  /*  IP Alert Information */
  uint8_t ip_alert_info_valid;  /**< Must be set to true if ip_alert_info is being passed */
  uint32_t ip_alert_info_len;  /**< Must be set to # of elements in ip_alert_info */
  voice_ip_alert_info_type_v02 ip_alert_info[QMI_VOICE_IP_ALERT_INFO_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Terminating Number** */
  uint8_t terminating_num_valid;  /**< Must be set to true if terminating_num is being passed */
  uint32_t terminating_num_len;  /**< Must be set to # of elements in terminating_num */
  voice_num_with_id_type_v02 terminating_num[QMI_VOICE_TERMINATING_ARRAY_MAX_V02];
  /**<   \nTerminating number of the calling party in ASCII string. \n
        Length range is 1 to 81.
  */

  /* Optional */
  /*  Is Secondary */
  uint8_t is_secondary_valid;  /**< Must be set to true if is_secondary is being passed */
  uint8_t is_secondary;
  /**<   Whether the call is on a secondary line. \n 
       Set to FALSE by default.
  */

  /* Optional */
  /*  Array of MT Call Verstat Information** */
  uint8_t mt_call_verstat_valid;  /**< Must be set to true if mt_call_verstat is being passed */
  uint32_t mt_call_verstat_len;  /**< Must be set to # of elements in mt_call_verstat */
  voice_MT_call_verstat_with_id_type_v02 mt_call_verstat[QMI_VOICE_CALL_INFO_MAX_V02];
  /**<   \nVerstat information of the MT call receiving number. Depending on the value of the 
       is_unwanted_call flag, the user can either accept or reject the MT call.
  */

  /* Optional */
  /*  Array of emergency service category ** */
  uint8_t emerg_srv_categ_valid;  /**< Must be set to true if emerg_srv_categ is being passed */
  uint32_t emerg_srv_categ_len;  /**< Must be set to # of elements in emerg_srv_categ */
  voice_emerg_srv_categ_type_v02 emerg_srv_categ[QMI_VOICE_EMERG_SRV_CATEG_ARRAY_MAX_V02];
  /**<   \nEmergency service category received from IMS when call gets ended with cause code 380
        Table 10.5.135d/3GPP TS 24.008: Service Category information element
  */
}voice_all_call_status_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Queries the information of all the calls. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}voice_get_all_call_info_req_msg_v02;

  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Queries the information of all the calls. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Array of Call Information */
  uint8_t call_info_valid;  /**< Must be set to true if call_info is being passed */
  uint32_t call_info_len;  /**< Must be set to # of elements in call_info */
  voice_call_info2_type_v02 call_info[QMI_VOICE_CALL_INFO_MAX_V02];

  /* Optional */
  /*  Array of Remote Party Number */
  uint8_t remote_party_number_valid;  /**< Must be set to true if remote_party_number is being passed */
  uint32_t remote_party_number_len;  /**< Must be set to # of elements in remote_party_number */
  voice_remote_party_number2_type_v02 remote_party_number[QMI_VOICE_REMOTE_PARTY_NUMBER_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Remote Party Name** */
  uint8_t remote_party_name_valid;  /**< Must be set to true if remote_party_name is being passed */
  uint32_t remote_party_name_len;  /**< Must be set to # of elements in remote_party_name */
  voice_remote_party_name2_type_v02 remote_party_name[QMI_VOICE_REMOTE_PARTY_NAME_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Alerting Type** */
  uint8_t alerting_type_valid;  /**< Must be set to true if alerting_type is being passed */
  uint32_t alerting_type_len;  /**< Must be set to # of elements in alerting_type */
  voice_alerting_type_type_v02 alerting_type[QMI_VOICE_ALERTING_TYPE_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of UUS Information** */
  uint8_t uus_info_valid;  /**< Must be set to true if uus_info is being passed */
  uint32_t uus_info_len;  /**< Must be set to # of elements in uus_info */
  voice_uus_info_type_v02 uus_info[QMI_VOICE_UUS_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Service Option* */
  uint8_t srv_opt_valid;  /**< Must be set to true if srv_opt is being passed */
  uint32_t srv_opt_len;  /**< Must be set to # of elements in srv_opt */
  voice_srv_opt_type_v02 srv_opt[QMI_VOICE_SRV_OPT_ARRAY_MAX_V02];

  /* Optional */
  /*  OTASP Status* */
  uint8_t otasp_status_valid;  /**< Must be set to true if otasp_status is being passed */
  otasp_status_enum_v02 otasp_status;
  /**<   OTASP status for the OTASP call. Values: \n
       - 0x00 -- OTASP_STATUS_SPL_UNLOCKED -- SPL unlocked;
                 only for user-initiated OTASP \n
       - 0x01 -- OTASP_STATUS_SPRC_RETRIES_ EXCEEDED -- SPC retries exceeded;
                 only for user-initiated OTASP \n
       - 0x02 -- OTASP_STATUS_AKEY_ EXCHANGED -- A-key exchanged;
                 only for user-initiated OTASP \n
       - 0x03 -- OTASP_STATUS_SSD_UPDATED -- SSD updated; for both user-initiated
                 OTASP and network-initiated OTASP (OTAPA) \n
       - 0x04 -- OTASP_STATUS_NAM_ DOWNLOADED -- NAM downloaded;
                 only for user-initiated OTASP \n
       - 0x05 -- OTASP_STATUS_MDN_ DOWNLOADED -- MDN downloaded;
                 only for user-initiated OTASP \n
       - 0x06 -- OTASP_STATUS_IMSI_ DOWNLOADED -- IMSI downloaded; 
                 only for user-initiated OTASP \n
       - 0x07 -- OTASP_STATUS_PRL_ DOWNLOADED -- PRL downloaded;
                 only for user-initiated OTASP \n
       - 0x08 -- OTASP_STATUS_COMMITTED -- Commit successful;
                 only for user-initiated OTASP \n
       - 0x09 -- OTASP_STATUS_OTAPA_STARTED -- OTAPA started;
                 only for network-initiated OTASP (OTAPA) \n
       - 0x0A -- OTASP_STATUS_OTAPA_STOPPED -- OTAPA stopped;
                 only for network-initiated OTASP (OTAPA) \n
       - 0x0B -- OTASP_STATUS_OTAPA_ABORTED -- OTAPA aborted;
                 only for network-initiated OTASP (OTAPA) \n
       - 0x0C -- OTASP_STATUS_OTAPA_ COMMITTED -- OTAPA committed; 
                 only for network-initiated OTASP (OTAPA)
  */

  /* Optional */
  /*  Voice Privacy* */
  uint8_t voice_privacy_valid;  /**< Must be set to true if voice_privacy is being passed */
  voice_privacy_enum_v02 voice_privacy;
  /**<   Values: \n 
       - 0x00 -- VOICE_PRIVACY_STANDARD -- Standard privacy \n
       - 0x01 -- VOICE_PRIVACY_ENHANCED -- Enhanced privacy
  */

  /* Optional */
  /*  Array of Call End Reason** */
  uint8_t call_end_reason_valid;  /**< Must be set to true if call_end_reason is being passed */
  uint32_t call_end_reason_len;  /**< Must be set to # of elements in call_end_reason */
  voice_call_end_reason_type_v02 call_end_reason[QMI_VOICE_CALL_END_REASON_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Alpha Identifier** */
  uint8_t alpha_id_valid;  /**< Must be set to true if alpha_id is being passed */
  uint32_t alpha_id_len;  /**< Must be set to # of elements in alpha_id */
  voice_alpha_ident_with_id_type_v02 alpha_id[QMI_VOICE_ALPHA_IDENT_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Connected Party Number */
  uint8_t conn_party_num_valid;  /**< Must be set to true if conn_party_num is being passed */
  uint32_t conn_party_num_len;  /**< Must be set to # of elements in conn_party_num */
  voice_conn_num_with_id_type_v02 conn_party_num[QMI_VOICE_CONNECTED_PARTY_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Diagnostic Information */
  uint8_t diagnostic_info_valid;  /**< Must be set to true if diagnostic_info is being passed */
  uint32_t diagnostic_info_len;  /**< Must be set to # of elements in diagnostic_info */
  voice_diagnostic_info_with_id_type_v02 diagnostic_info[QMI_VOICE_DIAGNOSTIC_INFO_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Called Party Number** */
  uint8_t called_party_num_valid;  /**< Must be set to true if called_party_num is being passed */
  uint32_t called_party_num_len;  /**< Must be set to # of elements in called_party_num */
  voice_num_with_id_type_v02 called_party_num[QMI_VOICE_CALLED_PARTY_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Redirecting Party Number** */
  uint8_t redirecting_party_num_valid;  /**< Must be set to true if redirecting_party_num is being passed */
  uint32_t redirecting_party_num_len;  /**< Must be set to # of elements in redirecting_party_num */
  voice_num_with_id_type_v02 redirecting_party_num[QMI_VOICE_REDIRECTING_PARTY_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Alerting Pattern** */
  uint8_t alerting_pattern_valid;  /**< Must be set to true if alerting_pattern is being passed */
  uint32_t alerting_pattern_len;  /**< Must be set to # of elements in alerting_pattern */
  voice_alerting_pattern_type_v02 alerting_pattern[QMI_VOICE_ALERTING_PATTERN_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Audio Attributes for VT Call over IP */
  uint8_t audio_attrib_valid;  /**< Must be set to true if audio_attrib is being passed */
  uint32_t audio_attrib_len;  /**< Must be set to # of elements in audio_attrib */
  voice_call_attributes_type_v02 audio_attrib[QMI_VOICE_CALL_ATTRIBUTES_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Video Attributes for VT Call over IP */
  uint8_t video_attrib_valid;  /**< Must be set to true if video_attrib is being passed */
  uint32_t video_attrib_len;  /**< Must be set to # of elements in video_attrib */
  voice_call_attributes_type_v02 video_attrib[QMI_VOICE_CALL_ATTRIBUTES_ARRAY_MAX_V02];

  /* Optional */
  /*  Variant Information for Videoshare Call */
  uint8_t vs_variant_valid;  /**< Must be set to true if vs_variant is being passed */
  uint32_t vs_variant_len;  /**< Must be set to # of elements in vs_variant */
  voice_vs_variant_type_v02 vs_variant[QMI_VOICE_VS_CALL_VARIANT_ARRAY_MAX_V02];

  /* Optional */
  /*  SIP URI for IP Call */
  uint8_t sip_uri_valid;  /**< Must be set to true if sip_uri is being passed */
  uint32_t sip_uri_len;  /**< Must be set to # of elements in sip_uri */
  voice_sip_uri_with_id_type_v02 sip_uri[QMI_VOICE_VS_CALL_VARIANT_ARRAY_MAX_V02];

  /* Optional */
  /*  Is SRVCC call */
  uint8_t is_srvcc_valid;  /**< Must be set to true if is_srvcc is being passed */
  uint32_t is_srvcc_len;  /**< Must be set to # of elements in is_srvcc */
  voice_is_srvcc_call_with_id_type_v02 is_srvcc[QMI_VOICE_IS_SRVCC_CALL_ARRAY_MAX_V02];

  /* Optional */
  /*  Call Attribute Status */
  uint8_t call_attrib_status_valid;  /**< Must be set to true if call_attrib_status is being passed */
  uint32_t call_attrib_status_len;  /**< Must be set to # of elements in call_attrib_status */
  voice_call_attrib_status_type_v02 call_attrib_status[QMI_VOICE_CALL_INFO_MAX_V02];

  /* Optional */
  /*  Remote Party Number Extension */
  uint8_t remote_party_number_ext_valid;  /**< Must be set to true if remote_party_number_ext is being passed */
  uint32_t remote_party_number_ext_len;  /**< Must be set to # of elements in remote_party_number_ext */
  voice_remote_party_number_ext_with_id_type_v02 remote_party_number_ext[QMI_VOICE_REMOTE_PARTY_NUMBER_ARRAY_MAX_V02];

  /* Optional */
  /*  Array of Second Alpha Identifier** */
  uint8_t second_alpha_ident_valid;  /**< Must be set to true if second_alpha_ident is being passed */
  uint32_t second_alpha_ident_len;  /**< Must be set to # of elements in second_alpha_ident */
  voice_alpha_ident_with_id_type_v02 second_alpha_ident[QMI_VOICE_ALPHA_IDENT_ARRAY_MAX_V02];

  /* Optional */
  /*  Caller Name for IP Call */
  uint8_t ip_caller_name_valid;  /**< Must be set to true if ip_caller_name is being passed */
  uint32_t ip_caller_name_len;  /**< Must be set to # of elements in ip_caller_name */
  voice_ip_caller_name_info_type_v02 ip_caller_name[QMI_VOICE_IP_CALLER_NAME_ARRAY_MAX_V02];

  /* Optional */
  /*  End Reason Text for IP Call */
  uint8_t end_reason_text_valid;  /**< Must be set to true if end_reason_text is being passed */
  uint32_t end_reason_text_len;  /**< Must be set to # of elements in end_reason_text */
  voice_ip_end_reason_text_type_v02 end_reason_text[QMI_VOICE_IP_END_REASON_TEXT_ARRAY_MAX_V02];

  /* Optional */
  /*  Called Party Subaddress */
  uint8_t called_party_subaddress_valid;  /**< Must be set to true if called_party_subaddress is being passed */
  uint32_t called_party_subaddress_len;  /**< Must be set to # of elements in called_party_subaddress */
  voice_subaddress_info_type_v02 called_party_subaddress[QMI_VOICE_CALLED_PARTY_SUBADDRESS_ARRAY_MAX_V02];

  /* Optional */
  /*  SIP Error Code for IP Call */
  uint8_t sip_error_code_valid;  /**< Must be set to true if sip_error_code is being passed */
  uint32_t sip_error_code_len;  /**< Must be set to # of elements in sip_error_code */
  voice_ip_end_sip_code_type_v02 sip_error_code[QMI_VOICE_IP_END_SIP_CODE_ARRAY_MAX_V02];

  /* Optional */
  /*  Raw Call End Cause Code */
  uint8_t raw_call_end_cause_code_valid;  /**< Must be set to true if raw_call_end_cause_code is being passed */
  uint32_t raw_call_end_cause_code_len;  /**< Must be set to # of elements in raw_call_end_cause_code */
  voice_raw_call_end_cause_code_type_v02 raw_call_end_cause_code[QMI_VOICE_CALL_END_REASON_ARRAY_MAX_V02];

  /* Optional */
  /*  IP History Information */
  uint8_t ip_hist_info_valid;  /**< Must be set to true if ip_hist_info is being passed */
  uint32_t ip_hist_info_len;  /**< Must be set to # of elements in ip_hist_info */
  voice_ip_hist_info_type_v02 ip_hist_info[QMI_VOICE_IP_HIST_INFO_ARRAY_MAX_V02];

  /* Optional */
  /*  Remote Party Conf Capability */
  uint8_t remote_party_conf_capability_valid;  /**< Must be set to true if remote_party_conf_capability is being passed */
  uint32_t remote_party_conf_capability_len;  /**< Must be set to # of elements in remote_party_conf_capability */
  voice_remote_party_conf_cap_type_v02 remote_party_conf_capability[QMI_VOICE_REMOTE_PARTY_CONF_CAP_ARRAY_MAX_V02];

  /* Optional */
  /*  RTT Attribute for VT or VOIP Call */
  uint8_t rtt_mode_valid;  /**< Must be set to true if rtt_mode is being passed */
  uint32_t rtt_mode_len;  /**< Must be set to # of elements in rtt_mode */
  voice_call_rtt_mode_status_type_v02 rtt_mode[QMI_VOICE_RTT_MODE_ARRAY_MAX_V02];

  /* Optional */
  /*  Local and Peer RTT Capabilities Information */
  uint8_t rtt_capabilities_info_valid;  /**< Must be set to true if rtt_capabilities_info is being passed */
  uint32_t rtt_capabilities_info_len;  /**< Must be set to # of elements in rtt_capabilities_info */
  voice_call_rtt_capabilities_info_type_v02 rtt_capabilities_info[QMI_VOICE_RTT_MODE_ARRAY_MAX_V02];

  /* Optional */
  /*  Alternate SIP URI for IP Call */
  uint8_t alternate_sip_uris_valid;  /**< Must be set to true if alternate_sip_uris is being passed */
  uint32_t alternate_sip_uris_len;  /**< Must be set to # of elements in alternate_sip_uris */
  voice_sip_uri_with_id_type_v02 alternate_sip_uris[QMI_VOICE_ALTERNATE_SIP_URI_ARRAY_MAX_V02];
}voice_get_all_call_info_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  SUPS_TYPE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  SUPS_TYPE_RELEASE_HELD_OR_WAITING_V02 = 0x01, 
  SUPS_TYPE_RELEASE_ACTIVE_ACCEPT_HELD_OR_WAITING_V02 = 0x02, 
  SUPS_TYPE_HOLD_ACTIVE_ACCEPT_WAITING_OR_HELD_V02 = 0x03, 
  SUPS_TYPE_HOLD_ALL_EXCEPT_SPECIFIED_CALL_V02 = 0x04, 
  SUPS_TYPE_MAKE_CONFERENCE_CALL_V02 = 0x05, 
  SUPS_TYPE_EXPLICIT_CALL_TRANSFER_V02 = 0x06, 
  SUPS_TYPE_CCBS_ACTIVATION_V02 = 0x07, 
  SUPS_TYPE_END_ALL_CALLS_V02 = 0x08, 
  SUPS_TYPE_RELEASE_SPECIFIED_CALL_V02 = 0x09, 
  SUPS_TYPE_LOCAL_HOLD_V02 = 0x0A, 
  SUPS_TYPE_LOCAL_UNHOLD_V02 = 0x0B, 
  SUPS_TYPE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}sups_type_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Manages the calls by using the supplementary service applicable 
             during the call (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Manage Calls Information */
  sups_type_enum_v02 sups_type;
  /**<   Supplementary service type during the call. Values: \n
       - 0x01 -- SUPS_TYPE_RELEASE_HELD_OR_ WAITING -- 
                 Release is held or waiting \n
       - 0x02 -- SUPS_TYPE_RELEASE_ACTIVE_ ACCEPT_HELD_OR_WAITING -- 
                 Release is active and accepting held or waiting \n
       - 0x03 -- SUPS_TYPE_HOLD_ACTIVE_ ACCEPT_WAITING_OR_HELD -- 
                 Hold is active and accepting waiting or held \n
       - 0x04 -- SUPS_TYPE_HOLD_ALL_EXCEPT_ SPECIFIED_CALL -- 
                 Hold all calls except a specified one \n
       - 0x05 -- SUPS_TYPE_MAKE_ CONFERENCE_CALL -- 
                 Make a conference call \n
       - 0x06 -- SUPS_TYPE_EXPLICIT_CALL_ TRANSFER -- 
                 Explicit call transfer \n
       - 0x07 -- SUPS_TYPE_CCBS_ACTIVATION -- 
                 Activate completion of calls to busy subscriber \n
       - 0x08 -- SUPS_TYPE_END_ALL_CALLS -- 
                 End all calls \n
       - 0x09 -- SUPS_TYPE_RELEASE_ SPECIFIED_CALL -- 
                 Release a specified call \n
       - 0x0A -- SUPS_TYPE_LOCAL_HOLD -- 
                 Put all active calls on local hold \n
       - 0x0B -- SUPS_TYPE_LOCAL_UNHOLD --  
                 Retrieve locally held calls
  */

  /* Optional */
  /*  Call ID */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Applicable only for sups_type 0x04, 0x07, and 0x09.
  */

  /* Optional */
  /*  Reject Cause */
  uint8_t reject_cause_valid;  /**< Must be set to true if reject_cause is being passed */
  voice_reject_cause_enum_v02 reject_cause;
  /**<   Cause for rejecting the call. Values: \n
      - VOICE_REJECT_CAUSE_USER_BUSY (0x01) --  User is busy \n 
      - VOICE_REJECT_CAUSE_USER_REJECT (0x02) --  User has rejected the call \n 
      - VOICE_REJECT_CAUSE_LOW_BATTERY (0x03) --  Call was rejected due to a low battery \n 
      - VOICE_REJECT_CAUSE_BLACKLISTED_CALL_ID (0x04) --  Call was rejected because the number was blacklisted \n 
      - VOICE_REJECT_CAUSE_DEAD_BATTERY (0x05) --  Call was rejected due to a dead battery 
      - VOICE_REJECT_CAUSE_UNWANTED_CALL (0x06) --  Call was rejected because the call was an unwanted robo call  
 */
}voice_manage_calls_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  QMI_SUPS_ERRORS_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QMI_FAILURE_CAUSE_OFFLINE_V02 = 0x00, 
  QMI_FAILURE_CAUSE_CDMA_LOCK_V02 = 0x14, 
  QMI_FAILURE_CAUSE_NO_SRV_V02 = 0x15, 
  QMI_FAILURE_CAUSE_FADE_V02 = 0x16, 
  QMI_FAILURE_CAUSE_INTERCEPT_V02 = 0x17, 
  QMI_FAILURE_CAUSE_REORDER_V02 = 0x18, 
  QMI_FAILURE_CAUSE_REL_NORMAL_V02 = 0x19, 
  QMI_FAILURE_CAUSE_REL_SO_REJ_V02 = 0x1A, 
  QMI_FAILURE_CAUSE_INCOM_CALL_V02 = 0x1B, 
  QMI_FAILURE_CAUSE_ALERT_STOP_V02 = 0x1C, 
  QMI_FAILURE_CAUSE_CLIENT_END_V02 = 0x1D, 
  QMI_FAILURE_CAUSE_ACTIVATION_V02 = 0x1E, 
  QMI_FAILURE_CAUSE_MC_ABORT_V02 = 0x1F, 
  QMI_FAILURE_CAUSE_MAX_ACCESS_PROBE_V02 = 0x20, 
  QMI_FAILURE_CAUSE_PSIST_N_V02 = 0x21, 
  QMI_FAILURE_CAUSE_UIM_NOT_PRESENT_V02 = 0x22, 
  QMI_FAILURE_CAUSE_ACC_IN_PROG_V02 = 0x23, 
  QMI_FAILURE_CAUSE_ACC_FAIL_V02 = 0x24, 
  QMI_FAILURE_CAUSE_RETRY_ORDER_V02 = 0x25, 
  QMI_FAILURE_CAUSE_CCS_NOT_SUPPORTED_BY_BS_V02 = 0x26, 
  QMI_FAILURE_CAUSE_NO_RESPONSE_FROM_BS_V02 = 0x27, 
  QMI_FAILURE_CAUSE_REJECTED_BY_BS_V02 = 0x28, 
  QMI_FAILURE_CAUSE_INCOMPATIBLE_V02 = 0x29, 
  QMI_FAILURE_CAUSE_ACCESS_BLOCK_V02 = 0x2A, 
  QMI_FAILURE_CAUSE_ALREADY_IN_TC_V02 = 0x2B, 
  QMI_FAILURE_CAUSE_EMERGENCY_FLASHED_V02 = 0x2C, 
  QMI_FAILURE_CAUSE_USER_CALL_ORIG_DURING_GPS_V02 = 0x2D, 
  QMI_FAILURE_CAUSE_USER_CALL_ORIG_DURING_SMS_V02 = 0x2E, 
  QMI_FAILURE_CAUSE_USER_CALL_ORIG_DURING_DATA_V02 = 0x2F, 
  QMI_FAILURE_CAUSE_REDIR_OR_HANDOFF_V02 = 0x30, 
  QMI_FAILURE_CAUSE_ACCESS_BLOCK_ALL_V02 = 0x31, 
  QMI_FAILURE_CAUSE_OTASP_SPC_ERR_V02 = 0x32, 
  QMI_FAILURE_CAUSE_IS707B_MAX_ACC_V02 = 0x33, 
  QMI_FAILURE_CAUSE_ACC_FAIL_REJ_ORD_V02 = 0x34, 
  QMI_FAILURE_CAUSE_ACC_FAIL_RETRY_ORD_V02 = 0x35, 
  QMI_FAILURE_CAUSE_TIMEOUT_T42_V02 = 0x36, 
  QMI_FAILURE_CAUSE_TIMEOUT_T40_V02 = 0x37, 
  QMI_FAILURE_CAUSE_SRV_INIT_FAIL_V02 = 0x38, 
  QMI_FAILURE_CAUSE_T50_EXP_V02 = 0x39, 
  QMI_FAILURE_CAUSE_T51_EXP_V02 = 0x3A, 
  QMI_FAILURE_CAUSE_RL_ACK_TIMEOUT_V02 = 0x3B, 
  QMI_FAILURE_CAUSE_BAD_FL_V02 = 0x3C, 
  QMI_FAILURE_CAUSE_TRM_REQ_FAIL_V02 = 0x3D, 
  QMI_FAILURE_CAUSE_TIMEOUT_T41_V02 = 0x3E, 
  QMI_FAILURE_CAUSE_INCOM_REJ_V02 = 0x66, 
  QMI_FAILURE_CAUSE_SETUP_REJ_V02 = 0x67, 
  QMI_FAILURE_CAUSE_NETWORK_END_V02 = 0x68, 
  QMI_FAILURE_CAUSE_NO_FUNDS_V02 = 0x69, 
  QMI_FAILURE_CAUSE_NO_GW_SRV_V02 = 0x6A, 
  QMI_FAILURE_CAUSE_NO_CDMA_SRV_V02 = 0x6B, 
  QMI_FAILURE_CAUSE_NO_FULL_SRV_V02 = 0x6C, 
  QMI_FAILURE_CAUSE_MAX_PS_CALLS_V02 = 0x6D, 
  QMI_FAILURE_CAUSE_UNKNOWN_SUBSCRIBER_V02 = 0x6E, 
  QMI_FAILURE_CAUSE_ILLEGAL_SUBSCRIBER_V02 = 0x6F, 
  QMI_FAILURE_CAUSE_BEARER_SERVICE_NOT_PROVISIONED_V02 = 0x70, 
  QMI_FAILURE_CAUSE_TELE_SERVICE_NOT_PROVISIONED_V02 = 0x71, 
  QMI_FAILURE_CAUSE_ILLEGAL_EQUIPMENT_V02 = 0x72, 
  QMI_FAILURE_CAUSE_CALL_BARRED_V02 = 0x73, 
  QMI_FAILURE_CAUSE_ILLEGAL_SS_OPERATION_V02 = 0x74, 
  QMI_FAILURE_CAUSE_SS_ERROR_STATUS_V02 = 0x75, 
  QMI_FAILURE_CAUSE_SS_NOT_AVAILABLE_V02 = 0x76, 
  QMI_FAILURE_CAUSE_SS_SUBSCRIPTION_VIOLATION_V02 = 0x77, 
  QMI_FAILURE_CAUSE_SS_INCOMPATIBILITY_V02 = 0x78, 
  QMI_FAILURE_CAUSE_FACILITY_NOT_SUPPORTED_V02 = 0x79, 
  QMI_FAILURE_CAUSE_ABSENT_SUBSCRIBER_V02 = 0x7A, 
  QMI_FAILURE_CAUSE_SHORT_TERM_DENIAL_V02 = 0x7B, 
  QMI_FAILURE_CAUSE_LONG_TERM_DENIAL_V02 = 0x7C, 
  QMI_FAILURE_CAUSE_SYSTEM_FAILURE_V02 = 0x7D, 
  QMI_FAILURE_CAUSE_DATA_MISSING_V02 = 0x7E, 
  QMI_FAILURE_CAUSE_UNEXPECTED_DATA_VALUE_V02 = 0x7F, 
  QMI_FAILURE_CAUSE_PWD_REGISTRATION_FAILURE_V02 = 0x80, 
  QMI_FAILURE_CAUSE_NEGATIVE_PWD_CHECK_V02 = 0x81, 
  QMI_FAILURE_CAUSE_NUM_OF_PWD_ATTEMPTS_VIOLATION_V02 = 0x82, 
  QMI_FAILURE_CAUSE_POSITION_METHOD_FAILURE_V02 = 0x83, 
  QMI_FAILURE_CAUSE_UNKNOWN_ALPHABET_V02 = 0x84, 
  QMI_FAILURE_CAUSE_USSD_BUSY_V02 = 0x85, 
  QMI_FAILURE_CAUSE_REJECTED_BY_USER_V02 = 0x86, 
  QMI_FAILURE_CAUSE_REJECTED_BY_NETWORK_V02 = 0x87, 
  QMI_FAILURE_CAUSE_DEFLECTION_TO_SERVED_SUBSCRIBER_V02 = 0x88, 
  QMI_FAILURE_CAUSE_SPECIAL_SERVICE_CODE_V02 = 0x89, 
  QMI_FAILURE_CAUSE_INVALID_DEFLECTED_TO_NUMBER_V02 = 0x8A, 
  QMI_FAILURE_CAUSE_MPTY_PARTICIPANTS_EXCEEDED_V02 = 0x8B, 
  QMI_FAILURE_CAUSE_RESOURCES_NOT_AVAILABLE_V02 = 0x8C, 
  QMI_FAILURE_CAUSE_UNASSIGNED_NUMBER_V02 = 0x8D, 
  QMI_FAILURE_CAUSE_NO_ROUTE_TO_DESTINATION_V02 = 0x8E, 
  QMI_FAILURE_CAUSE_CHANNEL_UNACCEPTABLE_V02 = 0x8F, 
  QMI_FAILURE_CAUSE_OPERATOR_DETERMINED_BARRING_V02 = 0x90, 
  QMI_FAILURE_CAUSE_NORMAL_CALL_CLEARING_V02 = 0x91, 
  QMI_FAILURE_CAUSE_USER_BUSY_V02 = 0x92, 
  QMI_FAILURE_CAUSE_NO_USER_RESPONDING_V02 = 0x93, 
  QMI_FAILURE_CAUSE_USER_ALERTING_NO_ANSWER_V02 = 0x94, 
  QMI_FAILURE_CAUSE_CALL_REJECTED_V02 = 0x95, 
  QMI_FAILURE_CAUSE_NUMBER_CHANGED_V02 = 0x96, 
  QMI_FAILURE_CAUSE_PREEMPTION_V02 = 0x97, 
  QMI_FAILURE_CAUSE_DESTINATION_OUT_OF_ORDER_V02 = 0x98, 
  QMI_FAILURE_CAUSE_INVALID_NUMBER_FORMAT_V02 = 0x99, 
  QMI_FAILURE_CAUSE_FACILITY_REJECTED_V02 = 0x9A, 
  QMI_FAILURE_CAUSE_RESP_TO_STATUS_ENQUIRY_V02 = 0x9B, 
  QMI_FAILURE_CAUSE_NORMAL_UNSPECIFIED_V02 = 0x9C, 
  QMI_FAILURE_CAUSE_NO_CIRCUIT_OR_CHANNEL_AVAILABLE_V02 = 0x9D, 
  QMI_FAILURE_CAUSE_NETWORK_OUT_OF_ORDER_V02 = 0x9E, 
  QMI_FAILURE_CAUSE_TEMPORARY_FAILURE_V02 = 0x9F, 
  QMI_FAILURE_CAUSE_SWITCHING_EQUIPMENT_CONGESTION_V02 = 0xA0, 
  QMI_FAILURE_CAUSE_ACCESS_INFORMATION_DISCARDED_V02 = 0xA1, 
  QMI_FAILURE_CAUSE_REQUESTED_CIRCUIT_OR_CHANNEL_NOT_AVAILABLE_V02 = 0xA2, 
  QMI_FAILURE_CAUSE_RESOURCES_UNAVAILABLE_OR_UNSPECIFIED_V02 = 0xA3, 
  QMI_FAILURE_CAUSE_QOS_UNAVAILABLE_V02 = 0xA4, 
  QMI_FAILURE_CAUSE_REQUESTED_FACILITY_NOT_SUBSCRIBED_V02 = 0xA5, 
  QMI_FAILURE_CAUSE_INCOMING_CALLS_BARRED_WITHIN_CUG_V02 = 0xA6, 
  QMI_FAILURE_CAUSE_BEARER_CAPABILITY_NOT_AUTH_V02 = 0xA7, 
  QMI_FAILURE_CAUSE_BEARER_CAPABILITY_UNAVAILABLE_V02 = 0xA8, 
  QMI_FAILURE_CAUSE_SERVICE_OPTION_NOT_AVAILABLE_V02 = 0xA9, 
  QMI_FAILURE_CAUSE_ACM_LIMIT_EXCEEDED_V02 = 0xAA, 
  QMI_FAILURE_CAUSE_BEARER_SERVICE_NOT_IMPLEMENTED_V02 = 0xAB, 
  QMI_FAILURE_CAUSE_REQUESTED_FACILITY_NOT_IMPLEMENTED_V02 = 0xAC, 
  QMI_FAILURE_CAUSE_ONLY_DIGITAL_INFORMATION_BEARER_AVAILABLE_V02 = 0xAD, 
  QMI_FAILURE_CAUSE_SERVICE_OR_OPTION_NOT_IMPLEMENTED_V02 = 0xAE, 
  QMI_FAILURE_CAUSE_INVALID_TRANSACTION_IDENTIFIER_V02 = 0xAF, 
  QMI_FAILURE_CAUSE_USER_NOT_MEMBER_OF_CUG_V02 = 0xB0, 
  QMI_FAILURE_CAUSE_INCOMPATIBLE_DESTINATION_V02 = 0xB1, 
  QMI_FAILURE_CAUSE_INVALID_TRANSIT_NW_SELECTION_V02 = 0xB2, 
  QMI_FAILURE_CAUSE_SEMANTICALLY_INCORRECT_MESSAGE_V02 = 0xB3, 
  QMI_FAILURE_CAUSE_INVALID_MANDATORY_INFORMATION_V02 = 0xB4, 
  QMI_FAILURE_CAUSE_MESSAGE_TYPE_NON_IMPLEMENTED_V02 = 0xB5, 
  QMI_FAILURE_CAUSE_MESSAGE_TYPE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE_V02 = 0xB6, 
  QMI_FAILURE_CAUSE_INFORMATION_ELEMENT_NON_EXISTENT_V02 = 0xB7, 
  QMI_FAILURE_CAUSE_CONDITONAL_IE_ERROR_V02 = 0xB8, 
  QMI_FAILURE_CAUSE_MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE_V02 = 0xB9, 
  QMI_FAILURE_CAUSE_RECOVERY_ON_TIMER_EXPIRED_V02 = 0xBA, 
  QMI_FAILURE_CAUSE_PROTOCOL_ERROR_UNSPECIFIED_V02 = 0xBB, 
  QMI_FAILURE_CAUSE_INTERWORKING_UNSPECIFIED_V02 = 0xBC, 
  QMI_FAILURE_CAUSE_OUTGOING_CALLS_BARRED_WITHIN_CUG_V02 = 0xBD, 
  QMI_FAILURE_CAUSE_NO_CUG_SELECTION_V02 = 0xBE, 
  QMI_FAILURE_CAUSE_UNKNOWN_CUG_INDEX_V02 = 0xBF, 
  QMI_FAILURE_CAUSE_CUG_INDEX_INCOMPATIBLE_V02 = 0xC0, 
  QMI_FAILURE_CAUSE_CUG_CALL_FAILURE_UNSPECIFIED_V02 = 0xC1, 
  QMI_FAILURE_CAUSE_CLIR_NOT_SUBSCRIBED_V02 = 0xC2, 
  QMI_FAILURE_CAUSE_CCBS_POSSIBLE_V02 = 0xC3, 
  QMI_FAILURE_CAUSE_CCBS_NOT_POSSIBLE_V02 = 0xC4, 
  QMI_FAILURE_CAUSE_IMSI_UNKNOWN_IN_HLR_V02 = 0xC5, 
  QMI_FAILURE_CAUSE_ILLEGAL_MS_V02 = 0xC6, 
  QMI_FAILURE_CAUSE_IMSI_UNKNOWN_IN_VLR_V02 = 0xC7, 
  QMI_FAILURE_CAUSE_IMEI_NOT_ACCEPTED_V02 = 0xC8, 
  QMI_FAILURE_CAUSE_ILLEGAL_ME_V02 = 0xC9, 
  QMI_FAILURE_CAUSE_PLMN_NOT_ALLOWED_V02 = 0xCA, 
  QMI_FAILURE_CAUSE_LOCATION_AREA_NOT_ALLOWED_V02 = 0xCB, 
  QMI_FAILURE_CAUSE_ROAMING_NOT_ALLOWED_IN_THIS_LOCATION_AREA_V02 = 0xCC, 
  QMI_FAILURE_CAUSE_NO_SUITABLE_CELLS_IN_LOCATION_AREA_V02 = 0xCD, 
  QMI_FAILURE_CAUSE_NETWORK_FAILURE_V02 = 0xCE, 
  QMI_FAILURE_CAUSE_MAC_FAILURE_V02 = 0xCF, 
  QMI_FAILURE_CAUSE_SYNCH_FAILURE_V02 = 0xD0, 
  QMI_FAILURE_CAUSE_NETWORK_CONGESTION_V02 = 0xD1, 
  QMI_FAILURE_CAUSE_GSM_AUTHENTICATION_UNACCEPTABLE_V02 = 0xD2, 
  QMI_FAILURE_CAUSE_SERVICE_NOT_SUBSCRIBED_V02 = 0xD3, 
  QMI_FAILURE_CAUSE_SERVICE_TEMPORARILY_OUT_OF_ORDER_V02 = 0xD4, 
  QMI_FAILURE_CAUSE_CALL_CANNOT_BE_IDENTIFIED_V02 = 0xD5, 
  QMI_FAILURE_CAUSE_INCORRECT_SEMANTICS_IN_MESSAGE_V02 = 0xD6, 
  QMI_FAILURE_CAUSE_MANDATORY_INFORMATION_INVALID_V02 = 0xD7, 
  QMI_FAILURE_CAUSE_ACCESS_STRATUM_FAILURE_V02 = 0xD8, 
  QMI_FAILURE_CAUSE_INVALID_SIM_V02 = 0xD9, 
  QMI_FAILURE_CAUSE_WRONG_STATE_V02 = 0xDA, 
  QMI_FAILURE_CAUSE_ACCESS_CLASS_BLOCKED_V02 = 0xDB, 
  QMI_FAILURE_CAUSE_NO_RESOURCES_V02 = 0xDC, 
  QMI_FAILURE_CAUSE_INVALID_USER_DATA_V02 = 0xDD, 
  QMI_FAILURE_CAUSE_TIMER_T3230_EXPIRED_V02 = 0xDE, 
  QMI_FAILURE_CAUSE_NO_CELL_AVAILABLE_V02 = 0xDF, 
  QMI_FAILURE_CAUSE_ABORT_MSG_RECEIVED_V02 = 0xE0, 
  QMI_FAILURE_CAUSE_RADIO_LINK_LOST_V02 = 0xE1, 
  QMI_FAILURE_CAUSE_TIMER_T303_EXPIRED_V02 = 0xE2, 
  QMI_FAILURE_CAUSE_CNM_MM_REL_PENDING_V02 = 0xE3, 
  QMI_FAILURE_CAUSE_ACCESS_STRATUM_REJ_RR_REL_IND_V02 = 0xE4, 
  QMI_FAILURE_CAUSE_ACCESS_STRATUM_REJ_RR_RANDOM_ACCESS_FAILURE_V02 = 0xE5, 
  QMI_FAILURE_CAUSE_ACCESS_STRATUM_REJ_RRC_REL_IND_V02 = 0xE6, 
  QMI_FAILURE_CAUSE_ACCESS_STRATUM_REJ_RRC_CLOSE_SESSION_IND_V02 = 0xE7, 
  QMI_FAILURE_CAUSE_ACCESS_STRATUM_REJ_RRC_OPEN_SESSION_FAILURE_V02 = 0xE8, 
  QMI_FAILURE_CAUSE_ACCESS_STRATUM_REJ_LOW_LEVEL_FAIL_V02 = 0xE9, 
  QMI_FAILURE_CAUSE_ACCESS_STRATUM_REJ_LOW_LEVEL_FAIL_REDIAL_NOT_ALLOWED_V02 = 0xEA, 
  QMI_FAILURE_CAUSE_ACCESS_STRATUM_REJ_LOW_LEVEL_IMMED_RETRY_V02 = 0xEB, 
  QMI_FAILURE_CAUSE_ACCESS_STRATUM_REJ_ABORT_RADIO_UNAVAILABLE_V02 = 0xEC, 
  QMI_FAILURE_CAUSE_SERVICE_OPTION_NOT_SUPPORTED_V02 = 0xED, 
  QMI_FAILURE_CAUSE_ACCESS_STRATUM_REJ_CONN_EST_FAILURE_ACCESS_BARRED_V02 = 0xEE, 
  QMI_FAILURE_CAUSE_ACCESS_STRATUM_REJ_CONN_REL_NORMAL_V02 = 0xEF, 
  QMI_FAILURE_CAUSE_ACCESS_STRATUM_REJ_UL_DATA_CNF_FAILURE_CONN_REL_V02 = 0xF0, 
  QMI_FAILURE_CAUSE_BAD_REQ_WAIT_INVITE_V02 = 0x12C, 
  QMI_FAILURE_CAUSE_BAD_REQ_WAIT_REINVITE_V02 = 0x12D, 
  QMI_FAILURE_CAUSE_INVALID_REMOTE_URI_V02 = 0x12E, 
  QMI_FAILURE_CAUSE_REMOTE_UNSUPP_MEDIA_TYPE_V02 = 0x12F, 
  QMI_FAILURE_CAUSE_PEER_NOT_REACHABLE_V02 = 0x130, 
  QMI_FAILURE_CAUSE_NETWORK_NO_RESP_TIME_OUT_V02 = 0x131, 
  QMI_FAILURE_CAUSE_NETWORK_NO_RESP_HOLD_FAIL_V02 = 0x132, 
  QMI_FAILURE_CAUSE_DATA_CONNECTION_LOST_V02 = 0x133, 
  QMI_FAILURE_CAUSE_UPGRADE_DOWNGRADE_REJ_V02 = 0x134, 
  QMI_FAILURE_CAUSE_SIP_403_FORBIDDEN_V02 = 0x135, 
  QMI_FAILURE_CAUSE_NO_NETWORK_RESP_V02 = 0x136, 
  QMI_FAILURE_CAUSE_UPGRADE_DOWNGRADE_FAILED_V02 = 0x137, 
  QMI_FAILURE_CAUSE_UPGRADE_DOWNGRADE_CANCELLED_V02 = 0x138, 
  QMI_FAILURE_CAUSE_SSAC_REJECT_V02 = 0x139, 
  QMI_FAILURE_CAUSE_THERMAL_EMERGENCY_V02 = 0x13A, 
  QMI_FAILURE_CAUSE_1XCSFB_SOFT_FAILURE_V02 = 0x13B, 
  QMI_FAILURE_CAUSE_1XCSFB_HARD_FAILURE_V02 = 0x13C, 
  QMI_FAILURE_CAUSE_CONNECTION_EST_FAILURE_V02 = 0x13D, 
  QMI_FAILURE_CAUSE_CONNECTION_FAILURE_V02 = 0x13E, 
  QMI_FAILURE_CAUSE_RRC_CONN_REL_NO_MT_SETUP_V02 = 0x13F, 
  QMI_FAILURE_CAUSE_ESR_FAILURE_V02 = 0x140, 
  QMI_FAILURE_CAUSE_MT_CSFB_NO_RESPONSE_FROM_NW_V02 = 0x141, 
  QMI_FAILURE_CAUSE_BUSY_EVERYWHERE_V02 = 0x142, 
  QMI_FAILURE_CAUSE_ANSWERED_ELSEWHERE_V02 = 0x143, 
  QMI_FAILURE_CAUSE_RLF_DURING_CC_DISCONNECT_V02 = 0x144, 
  QMI_FAILURE_CAUSE_TEMP_REDIAL_ALLOWED_V02 = 0x145, 
  QMI_FAILURE_CAUSE_PERM_REDIAL_NOT_NEEDED_V02 = 0x146, 
  QMI_FAILURE_CAUSE_MERGED_TO_CONFERENCE_V02 = 0x147, 
  QMI_FAILURE_CAUSE_LOW_BATTERY_V02 = 0x148, 
  QMI_FAILURE_CAUSE_CALL_DEFLECTED_V02 = 0x149, 
  QMI_FAILURE_CAUSE_RTP_RTCP_TIMEOUT_V02 = 0x14A, 
  QMI_FAILURE_CAUSE_RINGING_RINGBACK_TIMEOUT_V02 = 0x14B, 
  QMI_FAILURE_CAUSE_REG_RESTORATION_V02 = 0x14C, 
  QMI_FAILURE_CAUSE_CODEC_ERROR_V02 = 0x14D, 
  QMI_FAILURE_CAUSE_UNSUPPORTED_SDP_V02 = 0x14E, 
  QMI_FAILURE_CAUSE_RTP_FAILURE_V02 = 0x14F, 
  QMI_FAILURE_CAUSE_QoS_FAILURE_V02 = 0x150, 
  QMI_FAILURE_CAUSE_MULTIPLE_CHOICES_V02 = 0x151, 
  QMI_FAILURE_CAUSE_MOVED_PERMANENTLY_V02 = 0x152, 
  QMI_FAILURE_CAUSE_MOVED_TEMPORARILY_V02 = 0x153, 
  QMI_FAILURE_CAUSE_USE_PROXY_V02 = 0x154, 
  QMI_FAILURE_CAUSE_ALTERNATE_SERVICE_V02 = 0x155, 
  QMI_FAILURE_CAUSE_ALTERNATE_EMERGENCY_CALL_V02 = 0x156, 
  QMI_FAILURE_CAUSE_UNAUTHORIZED_V02 = 0x157, 
  QMI_FAILURE_CAUSE_PAYMENT_REQUIRED_V02 = 0x158, 
  QMI_FAILURE_CAUSE_METHOD_NOT_ALLOWED_V02 = 0x159, 
  QMI_FAILURE_CAUSE_NOT_ACCEPTABLE_V02 = 0x15A, 
  QMI_FAILURE_CAUSE_PROXY_AUTHENTICATION_REQUIRED_V02 = 0x15B, 
  QMI_FAILURE_CAUSE_GONE_V02 = 0x15C, 
  QMI_FAILURE_CAUSE_REQUEST_ENTITY_TOO_LARGE_V02 = 0x15D, 
  QMI_FAILURE_CAUSE_REQUEST_URI_TOO_LARGE_V02 = 0x15E, 
  QMI_FAILURE_CAUSE_UNSUPPORTED_URI_SCHEME_V02 = 0x15F, 
  QMI_FAILURE_CAUSE_BAD_EXTENSION_V02 = 0x160, 
  QMI_FAILURE_CAUSE_EXTENSION_REQUIRED_V02 = 0x161, 
  QMI_FAILURE_CAUSE_INTERVAL_TOO_BRIEF_V02 = 0x162, 
  QMI_FAILURE_CAUSE_CALL_OR_TRANS_DOES_NOT_EXIST_V02 = 0x163, 
  QMI_FAILURE_CAUSE_LOOP_DETECTED_V02 = 0x164, 
  QMI_FAILURE_CAUSE_TOO_MANY_HOPS_V02 = 0x165, 
  QMI_FAILURE_CAUSE_ADDRESS_INCOMPLETE_V02 = 0x166, 
  QMI_FAILURE_CAUSE_AMBIGUOUS_V02 = 0x167, 
  QMI_FAILURE_CAUSE_REQUEST_TERMINATED_V02 = 0x168, 
  QMI_FAILURE_CAUSE_NOT_ACCEPTABLE_HERE_V02 = 0x169, 
  QMI_FAILURE_CAUSE_REQUEST_PENDING_V02 = 0x16A, 
  QMI_FAILURE_CAUSE_UNDECIPHERABLE_V02 = 0x16B, 
  QMI_FAILURE_CAUSE_SERVER_INTERNAL_ERROR_V02 = 0x16C, 
  QMI_FAILURE_CAUSE_NOT_IMPLEMENTED_V02 = 0x16D, 
  QMI_FAILURE_CAUSE_BAD_GATEWAY_V02 = 0x16E, 
  QMI_FAILURE_CAUSE_SERVER_TIME_OUT_V02 = 0x16F, 
  QMI_FAILURE_CAUSE_VERSION_NOT_SUPPORTED_V02 = 0x170, 
  QMI_FAILURE_CAUSE_MESSAGE_TOO_LARGE_V02 = 0x171, 
  QMI_FAILURE_CAUSE_DOES_NOT_EXIST_ANYWHERE_V02 = 0x172, 
  QMI_FAILURE_CAUSE_SESS_DESCR_NOT_ACCEPTABLE_V02 = 0x173, 
  QMI_FAILURE_CAUSE_SRVCC_END_CALL_V02 = 0x174, 
  QMI_FAILURE_CAUSE_INTERNAL_ERROR_V02 = 0x175, 
  QMI_FAILURE_CAUSE_SERVER_UNAVAILABLE_V02 = 0x176, 
  QMI_FAILURE_CAUSE_PRECONDITION_FAILURE_V02 = 0x177, 
  QMI_FAILURE_CAUSE_DRVCC_IN_PROG_V02 = 0x178, 
  QMI_FAILURE_CAUSE_DRVCC_END_CALL_V02 = 0x179, 
  QMI_FAILURE_CAUSE_CS_HARD_FAILURE_V02 = 0x17A, 
  QMI_FAILURE_CAUSE_CS_ACQ_FAILURE_V02 = 0x17B, 
  QMI_FAILURE_CAUSE_REJECTED_ELSEWHERE_V02 = 0x180, 
  QMI_FAILURE_CAUSE_CALL_PULLED_V02 = 0x181, 
  QMI_FAILURE_CAUSE_CALL_PULL_OUT_OF_SYNC_V02 = 0x182, 
  QMI_FAILURE_CAUSE_HOLD_RESUME_FAILED_V02 = 0x183, 
  QMI_FAILURE_CAUSE_HOLD_RESUME_CANCELED_V02 = 0x184, 
  QMI_FAILURE_CAUSE_REINVITE_COLLISION_V02 = 0x185, 
  QMI_FAILURE_CAUSE_REDIAL_SECONDARY_LINE_CS_V02 = 0x186, 
  QMI_FAILURE_CAUSE_REDIAL_SECONDARY_LINE_PS_V02 = 0x187, 
  QMI_FAILURE_CAUSE_REDIAL_SECONDARY_LINE_CS_AUTO_V02 = 0x188, 
  QMI_FAILURE_CAUSE_REDIAL_SECONDARY_LINE_PS_AUTO_V02 = 0x189, 
  QMI_SUPS_ERRORS_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qmi_sups_errors_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Manages the calls by using the supplementary service applicable 
             during the call (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Failure Cause  */
  uint8_t failure_cause_valid;  /**< Must be set to true if failure_cause is being passed */
  qmi_sups_errors_enum_v02 failure_cause;
  /**<   Supplementary services failure cause; 
       see @latexonly Table~\ref{tbl:endReasons}@endlatexonly for more information. 
  */
}voice_manage_calls_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  NOTIFICATION_TYPE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NOTIFICATION_TYPE_OUTGOING_CALL_IS_FORWARDED_V02 = 0x01, 
  NOTIFICATION_TYPE_OUTGOING_CALL_IS_WAITING_V02 = 0x02, 
  NOTIFICATION_TYPE_OUTGOING_CUG_CALL_V02 = 0x03, 
  NOTIFICATION_TYPE_OUTGOING_CALLS_BARRED_V02 = 0x04, 
  NOTIFICATION_TYPE_OUTGOING_CALL_IS_DEFLECTED_V02 = 0x05, 
  NOTIFICATION_TYPE_INCOMING_CUG_CALL_V02 = 0x06, 
  NOTIFICATION_TYPE_INCOMING_CALLS_BARRED_V02 = 0x07, 
  NOTIFICATION_TYPE_INCOMING_FORWARDED_CALL_V02 = 0x08, 
  NOTIFICATION_TYPE_INCOMING_DEFLECTED_CALL_V02 = 0x09, 
  NOTIFICATION_TYPE_INCOMING_CALL_IS_FORWARDED_V02 = 0x0A, 
  NOTIFICATION_TYPE_UNCOND_CALL_FORWARD_ACTIVE_V02 = 0x0B, 
  NOTIFICATION_TYPE_COND_CALL_FORWARD_ACTIVE_V02 = 0x0C, 
  NOTIFICATION_TYPE_CLIR_SUPPRESSION_REJECTED_V02 = 0x0D, 
  NOTIFICATION_TYPE_CLIR_SUPPRSESION_REJECTED_V02 = 0x0D, 
  NOTIFICATION_TYPE_CALL_IS_ON_HOLD_V02 = 0x0E, 
  NOTIFICATION_TYPE_CALL_IS_RETRIEVED_V02 = 0x0F, 
  NOTIFICATION_TYPE_CALL_IS_IN_MPTY_V02 = 0x10, 
  NOTIFICATION_TYPE_INCOMING_CALL_IS_ECT_V02 = 0x11, 
  NOTIFICATION_TYPE_OUTGOING_CALL_PROGRESS_MSG_QUEUED_V02 = 0x12, 
  NOTIFICATION_TYPE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}notification_type_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t call_id;
  /**<   Unique identifier of the call for which the notification is
       applicable.
  */

  notification_type_enum_v02 notification_type;
  /**<   Notification type; 
       see Section @latexonly\ref{sec:suppServiceNotifications}@endlatexonly
       for descriptions. Values: \n
       - 0x01 -- NOTIFICATION_TYPE_ OUTGOING_CALL_IS_FORWARDED \n
       - 0x02 -- NOTIFICATION_TYPE_ OUTGOING_CALL_IS_WAITING \n
       - 0x03 -- NOTIFICATION_TYPE_ OUTGOING_CUG_CALL \n
       - 0x04 -- NOTIFICATION_TYPE_ OUTGOING_CALLS_BARRED \n
       - 0x05 -- NOTIFICATION_TYPE_ OUTGOING_CALL_IS_DEFLECTED \n
       - 0x06 -- NOTIFICATION_TYPE_INCOMING_ CUG_CALL \n
       - 0x07 -- NOTIFICATION_TYPE_INCOMING_ CALLS_BARRED \n
       - 0x08 -- NOTIFICATION_TYPE_INCOMING_ FORWARDED_CALL \n
       - 0x09 -- NOTIFICATION_TYPE_INCOMING_ DEFLECTED_CALL \n
       - 0x0A -- NOTIFICATION_TYPE_ INCOMING_CALL_IS_FORWARDED \n
       - 0x0B -- NOTIFICATION_TYPE_UNCOND_ CALL_FORWARD_ACTIVE \n
       - 0x0C -- NOTIFICATION_TYPE_COND_ CALL_FORWARD_ACTIVE \n
       - 0x0D -- NOTIFICATION_TYPE_CLIR_ SUPPRESSION_REJECTED \n
       - 0x0E -- NOTIFICATION_TYPE_CALL_IS_ ON_HOLD \n
       - 0x0F -- NOTIFICATION_TYPE_CALL_IS_ RETRIEVED \n
       - 0x10 -- NOTIFICATION_TYPE_CALL_IS_ IN_MPTY \n
       - 0x11 -- NOTIFICATION_TYPE_INCOMING_ CALL_IS_ECT \n
       - 0x12 -- NOTIFICATION_TYPE_ OUTGOING_CALL_PROGRESS_MSG_QUEUED
  */
}voice_notification_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  ECT_CALL_STATE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  ECT_CALL_STATE_NONE_V02 = 0x00, 
  ECT_CALL_STATE_ALERTING_V02 = 0x01, 
  ECT_CALL_STATE_ACTIVE_V02 = 0x02, 
  ECT_CALL_STATE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}ect_call_state_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_SUPS_NOTIFY_REASON_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_SUPS_NOTIFY_REASON_FWD_UNCONDITIONAL_V02 = 0x01, /**<  Unconditional \n  */
  VOICE_SUPS_NOTIFY_REASON_FWD_MOBILEBUSY_V02 = 0x02, /**<  Mobile busy \n  */
  VOICE_SUPS_NOTIFY_REASON_FWD_NOREPLY_V02 = 0x03, /**<  No reply \n  */
  VOICE_SUPS_NOTIFY_REASON_FWD_UNREACHABLE_V02 = 0x04, /**<  Unreachable \n  */
  VOICE_SUPS_NOTIFY_REASON_FWD_ALLFORWARDING_V02 = 0x05, /**<  All forwarding \n  */
  VOICE_SUPS_NOTIFY_REASON_FWD_ALLCONDITIONAL_V02 = 0x06, /**<  All conditional  */
  VOICE_SUPS_NOTIFY_REASON_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_sups_notify_reason_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  ect_call_state_enum_v02 ect_call_state;
  /**<   ECT call state. Values: \n
       - 0x00 -- ECT_CALL_STATE_NONE     -- None \n
       - 0x01 -- ECT_CALL_STATE_ALERTING -- Alerting \n
       - 0x02 -- ECT_CALL_STATE_ACTIVE   -- Active
  */

  pi_num_enum_v02 pi;
  /**<   Presentation indicator; refer to 
       \hyperref[STD-CS0005D]{3GPP2 C.S0005-D} Table 2.7.4.4-1 
       for valid values. Supported values: \n
       - 0x00 -- presentationAllowedAddress \n
       - 0x01 -- presentationRestricted \n
       - 0x02 -- numberNotAvailable \n
       - 0x04 -- presentationRestrictedAddress
  */

  uint32_t number_len;  /**< Must be set to # of elements in number */
  char number[QMI_VOICE_NUMBER_MAX_V02];
  /**<   Number in ASCII characters.
  */
}voice_ect_number_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Used for supplementary service notifications to the control 
             points (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Notification Information */
  voice_notification_info_type_v02 notification_info;

  /* Optional */
  /*  CUG Index */
  uint8_t index_valid;  /**< Must be set to true if index is being passed */
  uint16_t index;
  /**<   Index of the CUG call. Range: 0x00 to 0x7FFF.
  */

  /* Optional */
  /*  ECT Number */
  uint8_t ect_number_valid;  /**< Must be set to true if ect_number is being passed */
  voice_ect_number_type_v02 ect_number;

  /* Optional */
  /*  Supplementary Service Code */
  uint8_t ss_code_valid;  /**< Must be set to true if ss_code is being passed */
  voice_sups_notify_reason_enum_v02 ss_code;
  /**<   Supplementary service code. Values: \n 
      - VOICE_SUPS_NOTIFY_REASON_FWD_UNCONDITIONAL (0x01) --  Unconditional \n 
      - VOICE_SUPS_NOTIFY_REASON_FWD_MOBILEBUSY (0x02) --  Mobile busy \n 
      - VOICE_SUPS_NOTIFY_REASON_FWD_NOREPLY (0x03) --  No reply \n 
      - VOICE_SUPS_NOTIFY_REASON_FWD_UNREACHABLE (0x04) --  Unreachable \n 
      - VOICE_SUPS_NOTIFY_REASON_FWD_ALLFORWARDING (0x05) --  All forwarding \n 
      - VOICE_SUPS_NOTIFY_REASON_FWD_ALLCONDITIONAL (0x06) --  All conditional 
 */

  /* Optional */
  /*  IP Forward History Info */
  uint8_t ip_forward_hist_info_valid;  /**< Must be set to true if ip_forward_hist_info is being passed */
  uint32_t ip_forward_hist_info_len;  /**< Must be set to # of elements in ip_forward_hist_info */
  uint16_t ip_forward_hist_info[QMI_VOICE_IP_FORWARD_HIST_INFO_MAX_LEN_V02];
  /**<   IP forward history information. This text can contain up to 512 UTF-16 
       characters and it is not guaranteed to be NULL terminated.
  */

  /* Optional */
  /*  Media Direction of Call on Hold */
  uint8_t media_direction_hold_valid;  /**< Must be set to true if media_direction_hold is being passed */
  voice_call_attribute_type_mask_v02 media_direction_hold;
  /**<   Bitmask of call attributes. Values: \n
       - Bit 0 (0x01) -- VOICE_CALL_ATTRIB_TX -- Transmission \n
       - Bit 1 (0x02) -- VOICE_CALL_ATTRIB_RX -- Receiving
  */
}voice_sups_notification_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_SERVICE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_SERVICE_ACTIVATE_V02 = 0x01, 
  VOICE_SERVICE_DEACTIVATE_V02 = 0x02, 
  VOICE_SERVICE_REGISTER_V02 = 0x03, 
  VOICE_SERVICE_ERASE_V02 = 0x04, 
  VOICE_SERVICE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_service_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_REASON_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_REASON_FWD_UNCONDITIONAL_V02 = 0x01, 
  VOICE_REASON_FWD_MOBILEBUSY_V02 = 0x02, 
  VOICE_REASON_FWD_NOREPLY_V02 = 0x03, 
  VOICE_REASON_FWD_UNREACHABLE_V02 = 0x04, 
  VOICE_REASON_FWD_ALLFORWARDING_V02 = 0x05, 
  VOICE_REASON_FWD_ALLCONDITIONAL_V02 = 0x06, 
  VOICE_REASON_BARR_ALLOUTGOING_V02 = 0x07, 
  VOICE_REASON_BARR_OUTGOINGINT_V02 = 0x08, 
  VOICE_REASON_BARR_OUTGOINGINTEXTOHOME_V02 = 0x09, 
  VOICE_REASON_BARR_ALLINCOMING_V02 = 0x0A, 
  VOICE_REASON_BARR_INCOMINGROAMING_V02 = 0x0B, 
  VOICE_REASON_BARR_ALLBARRING_V02 = 0x0C, 
  VOICE_REASON_BARR_ALLOUTGOINGBARRING_V02 = 0x0D, 
  VOICE_REASON_BARR_ALLINCOMINGBARRING_V02 = 0x0E, 
  VOICE_REASON_CALLWAITING_V02 = 0x0F, 
  VOICE_REASON_CLIP_V02 = 0x10, 
  VOICE_REASON_CLIR_V02 = 0x11, 
  VOICE_REASON_COLP_V02 = 0x12, 
  VOICE_REASON_COLR_V02 = 0x13, 
  VOICE_REASON_CNAP_V02 = 0x14, 
  VOICE_REASON_BARR_INCOMING_NUMBER_V02 = 0x15, 
  VOICE_REASON_BARR_INCOMING_ANONYMOUS_V02 = 0x16, 
  VOICE_REASON_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_reason_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_SERVICE_CLASS_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_SUPS_CLASS_VOICE_V02 = 0x0001, 
  VOICE_SUPS_CLASS_DATA_V02 = 0x0002, 
  VOICE_SUPS_CLASS_FAX_V02 = 0x0004, 
  VOICE_SUPS_ALL_TELE_SERV_EX_SMS_V02 = 0x0005, 
  VOICE_SUPS_CLASS_SMS_V02 = 0x0008, 
  VOICE_SUPS_CLASS_ALL_TS_DATA_V02 = 0x000c, 
  VOICE_SUPS_ALL_TELE_SERV_V02 = 0x000d, 
  VOICE_SUPS_CLASS_DATA_SYNC_V02 = 0x0010, 
  VOICE_SUPS_CLASS_ALL_DATA_PDS_V02 = 0x0011, 
  VOICE_SUPS_CLASS_DATA_ASYNC_V02 = 0x0020, 
  VOICE_SUPS_CLASS_ALL_DATA_SYNC_ASYNC_V02 = 0x0030, 
  VOICE_SUPS_CLASS_DATA_PKT_V02 = 0x0040, 
  VOICE_SUPS_CLASS_ALL_DATA_SYNC_V02 = 0x0050, 
  VOICE_SUPS_CLASS_DATA_PAD_V02 = 0x0080, 
  VOICE_SUPS_CLASS_ALL_DATA_ASYNC_V02 = 0x00a0, 
  VOICE_SUPS_CLASS_TS_GROUP_CALL_V02 = 0x0100, 
  VOICE_SUPS_CLASS_TS_BROADCAST_CALL_V02 = 0x0200, 
  VOICE_SUPS_CLASS_TS_ALL_GROUP_CALL_V02 = 0x0300, 
  VOICE_PLMN_SPECIFIC_TS_ALL_V02 = 0xd000, 
  VOICE_PLMN_SPECIFIC_TS_1_V02 = 0xd100, 
  VOICE_PLMN_SPECIFIC_TS_2_V02 = 0xd200, 
  VOICE_PLMN_SPECIFIC_TS_3_V02 = 0xd300, 
  VOICE_PLMN_SPECIFIC_TS_4_V02 = 0xd400, 
  VOICE_PLMN_SPECIFIC_TS_5_V02 = 0xd500, 
  VOICE_PLMN_SPECIFIC_TS_6_V02 = 0xd600, 
  VOICE_PLMN_SPECIFIC_TS_7_V02 = 0xd700, 
  VOICE_PLMN_SPECIFIC_TS_8_V02 = 0xd800, 
  VOICE_PLMN_SPECIFIC_TS_9_V02 = 0xd900, 
  VOICE_PLMN_SPECIFIC_TS_A_V02 = 0xda00, 
  VOICE_PLMN_SPECIFIC_TS_B_V02 = 0xdb00, 
  VOICE_PLMN_SPECIFIC_TS_C_V02 = 0xdc00, 
  VOICE_PLMN_SPECIFIC_TS_D_V02 = 0xdd00, 
  VOICE_PLMN_SPECIFIC_TS_E_V02 = 0xde00, 
  VOICE_PLMN_SPECIFIC_TS_F_V02 = 0xdf00, 
  VOICE_SERVICE_CLASS_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_service_class_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  voice_service_enum_v02 voice_service;
  /**<   Service. Values: \n
       - 0x01 -- VOICE_SERVICE_ACTIVATE   -- Activate \n
       - 0x02 -- VOICE_SERVICE_DEACTIVATE -- Deactivate \n
       - 0x03 -- VOICE_SERVICE_REGISTER   -- Register \n
       - 0x04 -- VOICE_SERVICE_ERASE      -- Erase
  */

  voice_reason_enum_v02 reason;
  /**<   Reason. Values: \n
       - 0x01 -- VOICE_REASON_FWD_ UNCONDITIONAL -- 
                 Unconditional call forwarding \n
       - 0x02 -- VOICE_REASON_FWD_ MOBILEBUSY -- 
                 Forward when the mobile is busy \n
       - 0x03 -- VOICE_REASON_FWD_NOREPLY -- 
                 Forward when there is no reply \n
       - 0x04 -- VOICE_REASON_FWD_ UNREACHABLE -- 
                 Forward when the call is unreachable \n
       - 0x05 -- VOICE_REASON_FWD_ ALLFORWARDING -- 
                 All forwarding \n
       - 0x06 -- VOICE_REASON_FWD_ ALLCONDITIONAL -- 
                 All conditional forwarding \n
       - 0x07 -- VOICE_REASON_BARR_ ALLOUTGOING -- 
                 All outgoing \n
       - 0x08 -- VOICE_REASON_BARR_ OUTGOINGINT -- 
                 Outgoing internal \n
       - 0x09 -- VOICE_REASON_BARR_ OUTGOINGINTEXTOHOME -- 
                 Outgoing external to home \n
       - 0x0A -- VOICE_REASON_BARR_ ALLINCOMING -- 
                 All incoming \n
       - 0x0B -- VOICE_REASON_BARR_ INCOMINGROAMING -- 
                 Roaming incoming \n
       - 0x0C -- VOICE_REASON_BARR_ ALLBARRING -- 
                 All calls are barred \n
       - 0x0D -- VOICE_REASON_BARR_ ALLOUTGOINGBARRING -- 
                 All outgoing calls are barred \n
       - 0x0E -- VOICE_REASON_BARR_ ALLINCOMINGBARRING -- 
                 All incoming calls are barred \n
       - 0x0F -- VOICE_REASON_CALLWAITING -- Call waiting \n
       - 0x10 -- VOICE_REASON_CLIP -- 
                 Calling line identification presentation \n
       - 0x12 -- VOICE_REASON_COLP -- 
                 Connected line identification presentation \n
       - 0x13 -- VOICE_REASON_COLR --
                 Connected line identification restriction \n
       - 0x14 -- VOICE_REASON_CNAP -- 
                 Calling name presentation \n
       - 0x15 -- VOICE_REASON_BARR_ INCOMINGNUMBER -- 
                 Incoming calls from registered and activated numbers are barred \n
       - 0x16 -- VOICE_REASON_BARR_ INCOMINGANONYMOUS -- 
                 Incoming calls from anonymous numbers are barred
  */
}voice_supplementary_service_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  voice_num_type_enum_v02 num_type;
  /**<   Number type. Values: \n
       - 0x00 -- QMI_VOICE_NUM_TYPE_ UNKNOWN -- Unknown \n
       - 0x01 -- QMI_VOICE_NUM_TYPE_ INTERNATIONAL -- International \n
       - 0x02 -- QMI_VOICE_NUM_TYPE_ NATIONAL -- National \n
       - 0x03 -- QMI_VOICE_NUM_TYPE_ NETWORK_ SPECIFIC -- Network-specific \n
       - 0x04 -- QMI_VOICE_NUM_TYPE_ SUBSCRIBER -- Subscriber \n
       - 0x05 -- QMI_VOICE_NUM_TYPE_ RESERVED -- Reserved \n
       - 0x06 -- QMI_VOICE_NUM_TYPE_ ABBREVIATED -- Abbreviated \n
       - 0x07 -- QMI_VOICE_NUM_TYPE_ RESERVED_EXTENSION -- Reserved extension
  */

  voice_num_plan_enum_v02 num_plan;
  /**<   Number plan. Values: \n
       - 0x00 -- QMI_VOICE_NUM_PLAN_ UNKNOWN -- Unknown \n
       - 0x01 -- QMI_VOICE_NUM_PLAN_ISDN -- ISDN \n
       - 0x03 -- QMI_VOICE_NUM_PLAN_DATA -- Data \n
       - 0x04 -- QMI_VOICE_NUM_PLAN_TELEX -- Telex \n
       - 0x08 -- QMI_VOICE_NUM_PLAN_ NATIONAL -- National \n
       - 0x09 -- QMI_VOICE_NUM_PLAN_ PRIVATE -- Private \n
       - 0x0B -- QMI_VOICE_NUM_PLAN_ RESERVED_CTS -- Reserved cordless telephony system \n
       - 0x0F -- QMI_VOICE_NUM_PLAN_ RESERVED_EXTENSION -- Reserved extension
  */
}voice_num_type_plan_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  ACTIVE_STATUS_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  ACTIVE_STATUS_INACTIVE_V02 = 0x00, /**<  Inactive \n  */
  ACTIVE_STATUS_ACTIVE_V02 = 0x01, /**<  Active  */
  ACTIVE_STATUS_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}active_status_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  PROVISION_STATUS_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  PROVISION_STATUS_NOT_PROVISIONED_V02 = 0x00, 
  PROVISION_STATUS_PROVISIONED_PERMANENT_V02 = 0x01, 
  PROVISION_STATUS_PRESENTATION_RESTRICTED_V02 = 0x02, 
  PROVISION_STATUS_PRESENTATION_ALLOWED_V02 = 0x03, 
  PROVISION_STATUS_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}provision_status_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  active_status_enum_v02 active_status;
  /**<   Active status. Values: \n
       - 0x00 -- ACTIVE_STATUS_INACTIVE -- Inactive \n
       - 0x01 -- ACTIVE_STATUS_ACTIVE -- Active
  */

  provision_status_enum_v02 provision_status;
  /**<   Provisioned status. Values: \n
       - 0x00 -- PROVISION_STATUS_ NOT_PROVISIONED -- Not provisioned \n
       - 0x01 -- PROVISION_STATUS_ PROVISIONED_PERMANENT -- Provisioned \n
       All other values are not used
  */
}voice_ss_status_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  PI_COLR_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  COLR_PRESENTATION_NOT_RESTRICTED_V02 = 0x00, /**<  COLR presentation is not restricted  */
  COLR_PRESENTATION_RESTRICTED_V02 = 0x01, /**<  COLR presentation is restricted  */
  PI_COLR_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}pi_colr_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  char barred_number[QMI_VOICE_NUMBER_MAX_V02 + 1];
  /**<   Call barring number as an ASCII string. 
       Length range: 1 to 81.
  */
}voice_barred_number_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t year;
  /**<   Year.
  */

  uint8_t month;
  /**<   Month.
       Range: 1 to 12. 1 is January and 12 is December.
  */

  uint8_t day;
  /**<   Day. 
       Range: 1 to 31.
  */

  uint8_t hour;
  /**<   Hour.
       Range: 0 to 23.
  */

  uint8_t minute;
  /**<   Minute.
       Range: 0 to 59.
  */

  uint8_t second;
  /**<   Second.
       Range: 0 to 59.
  */

  int8_t time_zone;
  /**<   Time zone. Offset from Universal time, i.e., the difference between 
       local time and Universal time, in increments of 15 min (signed value).
  */
}voice_time_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  active_status_enum_v02 active_status;
  /**<   Active status. Values: \n
      - ACTIVE_STATUS_INACTIVE (0x00) --  Inactive \n 
      - ACTIVE_STATUS_ACTIVE (0x01) --  Active  
 */

  char barred_number[QMI_VOICE_NUMBER_MAX_V02 + 1];
  /**<   Call barring number as an ASCII string. 
       Length range: 1 to 81.
  */
}voice_barred_number_status_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Manages all call-independent supplementary services, such as 
             activation, deactivation, registration, and erasure. */
typedef struct {

  /* Mandatory */
  /*  Supplementary Service Information */
  voice_supplementary_service_info_type_v02 supplementary_service_info;

  /* Optional */
  /*  Service Class */
  uint8_t service_class_valid;  /**< Must be set to true if service_class is being passed */
  uint8_t service_class;
  /**<   Service class is a combination (sum) of information class constants
       (information class constants are described in 
       Table @latexonly\ref{tbl:suppServiceInfoClass}@endlatexonly).
  */

  /* Optional */
  /*  Call Barring Password */
  uint8_t password_valid;  /**< Must be set to true if password is being passed */
  char password[4];
  /**<   Password is required if call barring is provisioned using a password. 
       Password consists of 4 ASCII digits. Range: 0000 to 9999.
  */

  /* Optional */
  /*  Call Forwarding Number */
  uint8_t number_valid;  /**< Must be set to true if number is being passed */
  char number[QMI_VOICE_NUMBER_MAX_V02 + 1];
  /**<   Call forwarding number to be registered with the network; ASCII string.*/

  /* Optional */
  /*  Call Forwarding No Reply Timer */
  uint8_t timer_value_valid;  /**< Must be set to true if timer_value is being passed */
  uint8_t timer_value;
  /**<   Timer value in seconds. 
  */

  /* Optional */
  /*  Call Forwarding Number Type and Plan */
  uint8_t num_type_plan_valid;  /**< Must be set to true if num_type_plan is being passed */
  voice_num_type_plan_type_v02 num_type_plan;

  /* Optional */
  /*  Extended Service Class */
  uint8_t service_class_ext_valid;  /**< Must be set to true if service_class_ext is being passed */
  voice_service_class_enum_v02 service_class_ext;
  /**<   Extended service class; see Table @latexonly\ref{tbl:extServiceClass}@endlatexonly 
       for more information.
  */

  /* Optional */
  /*  Call Barring Numbers List */
  uint8_t call_barring_numbers_list_valid;  /**< Must be set to true if call_barring_numbers_list is being passed */
  uint32_t call_barring_numbers_list_len;  /**< Must be set to # of elements in call_barring_numbers_list */
  voice_barred_number_type_v02 call_barring_numbers_list[QMI_VOICE_MAX_BARRED_NUMBERS_LIST_V02];
  /**<   \n
       List of call barring numbers to be activated/deactivated 
       or registered with/erased from the network.
  */

  /* Optional */
  /*  COLR Presentation Information */
  uint8_t colr_pi_valid;  /**< Must be set to true if colr_pi is being passed */
  pi_colr_enum_v02 colr_pi;
  /**<   COLR presentation information. Values: \n
      - COLR_PRESENTATION_NOT_RESTRICTED (0x00) --  COLR presentation is not restricted 
      - COLR_PRESENTATION_RESTRICTED (0x01) --  COLR presentation is restricted  
 */

  /* Optional */
  /*  Call Forwarding Start Time */
  uint8_t call_fwd_start_time_valid;  /**< Must be set to true if call_fwd_start_time is being passed */
  voice_time_type_v02 call_fwd_start_time;

  /* Optional */
  /*  Call Forwarding End Time */
  uint8_t call_fwd_end_time_valid;  /**< Must be set to true if call_fwd_end_time is being passed */
  voice_time_type_v02 call_fwd_end_time;
}voice_set_sups_service_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Manages all call-independent supplementary services, such as 
             activation, deactivation, registration, and erasure. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Failure Cause  */
  uint8_t failure_cause_valid;  /**< Must be set to true if failure_cause is being passed */
  qmi_sups_errors_enum_v02 failure_cause;
  /**<   Supplementary services failure cause; 
       see @latexonly Table~\ref{tbl:endReasons}@endlatexonly for more information.
  */

  /* Optional */
  /*  Alpha Identifier */
  uint8_t alpha_ident_valid;  /**< Must be set to true if alpha_ident is being passed */
  voice_alpha_ident_type_v02 alpha_ident;

  /* Optional */
  /*  Call Control Result Type */
  uint8_t cc_result_type_valid;  /**< Must be set to true if cc_result_type is being passed */
  voice_cc_result_type_enum_v02 cc_result_type;
  /**<   Values: \n
      - VOICE_CC_RESULT_TYPE_VOICE (0x00) --  VOICE \n 
      - VOICE_CC_RESULT_TYPE_SUPS (0x01) --  SUPS \n 
      - VOICE_CC_RESULT_TYPE_USSD (0x02) --  USSD \n 
      - VOICE_CC_RESULT_TYPE_VT (0x03) --  VT 
 */

  /* Optional */
  /*  Call ID */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Call ID of the voice call that resulted from call control;  
       ID is present when cc_result_type is present and is Voice.
  */

  /* Optional */
  /*  Call Control Supplementary Service Type */
  uint8_t cc_sups_result_valid;  /**< Must be set to true if cc_sups_result is being passed */
  voice_cc_sups_result_type_v02 cc_sups_result;
  /**<   (Supplementary service data that resulted from call control;
       data is present when cc_result_type is present and is other than Voice.)
  */

  /* Optional */
  /*  Service Status */
  uint8_t service_status_valid;  /**< Must be set to true if service_status is being passed */
  voice_ss_status_type_v02 service_status;

  /* Optional */
  /*  Failure Cause Description  */
  uint8_t failure_cause_description_valid;  /**< Must be set to true if failure_cause_description is being passed */
  uint32_t failure_cause_description_len;  /**< Must be set to # of elements in failure_cause_description */
  uint16_t failure_cause_description[QMI_VOICE_FAILURE_CAUSE_DESC_MAX_LEN_V02];
  /**<   Failure cause description received from the network. This text can contain 
       up to 256 UTF-16 characters and it is not guaranteed to be NULL terminated.
       Length range: 0 to 256.
  */

  /* Optional */
  /*  Retry Duration */
  uint8_t retry_duration_valid;  /**< Must be set to true if retry_duration is being passed */
  uint16_t retry_duration;
  /**<   Retry duration in seconds.
  */

  /* Optional */
  /*  SIP Error Code */
  uint8_t sip_error_code_valid;  /**< Must be set to true if sip_error_code is being passed */
  uint16_t sip_error_code;
  /**<   SIP error code for supplementary service failure.
  */
}voice_set_sups_service_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Queries the status of call waiting supplementary service 
             (applicable only for 3GPP). */
typedef struct {

  /* Optional */
  /*  Service Class */
  uint8_t service_class_valid;  /**< Must be set to true if service_class is being passed */
  uint8_t service_class;
  /**<   Service class is a combination (sum) of information class constants
       (information class constants are described in 
       Table @latexonly\ref{tbl:suppServiceInfoClass}@endlatexonly).
  */

  /* Optional */
  /*  Extended Service Class */
  uint8_t service_class_ext_valid;  /**< Must be set to true if service_class_ext is being passed */
  voice_service_class_enum_v02 service_class_ext;
  /**<   Extended service class; see Table @latexonly\ref{tbl:extServiceClass}@endlatexonly 
       for more information.
  */
}voice_get_call_waiting_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  active_status_enum_v02 active_status;
  /**<   Active status. Values: \n
       - 0x00 -- ACTIVE_STATUS_INACTIVE -- Inactive \n
       - 0x01 -- ACTIVE_STATUS_ACTIVE -- Active
  */

  provision_status_enum_v02 provision_status;
  /**<   Provisioned status. Values: \n
       - 0x00 -- PROVISION_STATUS_ NOT_PROVISIONED -- Not provisioned \n
       - 0x01 -- PROVISION_STATUS_ PROVISIONED_PERMANENT -- Provisioned \n
       All other values are not used
  */
}voice_cw_response_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Queries the status of call waiting supplementary service 
             (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Service Class */
  uint8_t service_class_valid;  /**< Must be set to true if service_class is being passed */
  uint8_t service_class;
  /**<   Service Class is a combination (sum) of information class constants
       (information class constants are described in 
       Table @latexonly\ref{tbl:suppServiceInfoClass}@endlatexonly), which
       indicates that call waiting is active for those information classes. 
       Service Class is set to 0 if call waiting is not active for any of
       the information classes.
  */

  /* Optional */
  /*  Failure Cause  */
  uint8_t failure_cause_valid;  /**< Must be set to true if failure_cause is being passed */
  qmi_sups_errors_enum_v02 failure_cause;
  /**<   Supplementary services failure cause; 
       see @latexonly Table~\ref{tbl:endReasons}@endlatexonly for more information.
  */

  /* Optional */
  /*  Alpha Identifier */
  uint8_t alpha_id_valid;  /**< Must be set to true if alpha_id is being passed */
  voice_alpha_ident_type_v02 alpha_id;

  /* Optional */
  /*  Call Control Result Type */
  uint8_t cc_result_type_valid;  /**< Must be set to true if cc_result_type is being passed */
  voice_cc_result_type_enum_v02 cc_result_type;
  /**<   Values: \n
      - VOICE_CC_RESULT_TYPE_VOICE (0x00) --  VOICE \n 
      - VOICE_CC_RESULT_TYPE_SUPS (0x01) --  SUPS \n 
      - VOICE_CC_RESULT_TYPE_USSD (0x02) --  USSD \n 
      - VOICE_CC_RESULT_TYPE_VT (0x03) --  VT 
 */

  /* Optional */
  /*  Call ID */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Call ID of the voice call that resulted from call control;  
       ID is present when cc_result_type is present and is Voice.
  */

  /* Optional */
  /*  Call Control Supplementary Service Type */
  uint8_t cc_sups_result_valid;  /**< Must be set to true if cc_sups_result is being passed */
  voice_cc_sups_result_type_v02 cc_sups_result;
  /**<   (Supplementary service data that resulted from call control;
       data is present when cc_result_type is present and is other than Voice.)
  */

  /* Optional */
  /*  Extended Service Class */
  uint8_t service_class_ext_valid;  /**< Must be set to true if service_class_ext is being passed */
  voice_service_class_enum_v02 service_class_ext;
  /**<   Extended service class; see Table @latexonly\ref{tbl:extServiceClass}@endlatexonly 
       for more information.
  */

  /* Optional */
  /*  Retry Duration */
  uint8_t retry_duration_valid;  /**< Must be set to true if retry_duration is being passed */
  uint16_t retry_duration;
  /**<   Retry duration in seconds.
  */

  /* Optional */
  /*  Failure Cause Description  */
  uint8_t failure_cause_description_valid;  /**< Must be set to true if failure_cause_description is being passed */
  uint32_t failure_cause_description_len;  /**< Must be set to # of elements in failure_cause_description */
  uint16_t failure_cause_description[QMI_VOICE_FAILURE_CAUSE_DESC_MAX_LEN_V02];
  /**<   Failure cause description received from the network. This text can contain 
       up to 256 UTF-16 characters and it is not guaranteed to be NULL terminated.
       Length range: 0 to 256.
  */

  /* Optional */
  /*  SIP Error Code */
  uint8_t sip_error_code_valid;  /**< Must be set to true if sip_error_code is being passed */
  uint16_t sip_error_code;
  /**<   SIP error code for supplemental service failure.
  */

  /* Optional */
  /*  Call Waiting Response */
  uint8_t cw_response_valid;  /**< Must be set to true if cw_response is being passed */
  voice_cw_response_type_v02 cw_response;
  /**<   (response type for call waiting; contains the active_status and provision_status data members)
  */
}voice_get_call_waiting_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  voice_service_class_enum_v02 service_class_ext;
  /**<   Extended service class; see Table @latexonly\ref{tbl:extServiceClass}@endlatexonly 
       for more information.
  */

  uint32_t call_barring_numbers_list_len;  /**< Must be set to # of elements in call_barring_numbers_list */
  voice_barred_number_status_type_v02 call_barring_numbers_list[QMI_VOICE_MAX_BARRED_NUMBERS_LIST_V02];
}voice_serviceclass_barred_number_list_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Queries the status of call barring supplementary service 
             (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Call Barring Reason */
  voice_reason_enum_v02 reason;
  /**<   Reason. Values: \n
       - 0x07 -- QMI_VOICE_REASON_BARR_ ALLOUTGOING -- 
                 All outgoing \n
       - 0x08 -- QMI_VOICE_REASON_BARR_ OUTGOINGINT -- 
                 Outgoing internal \n
       - 0x09 -- QMI_VOICE_REASON_BARR_ OUTGOINGINTEXTOHOME -- 
                 Outgoing external to home \n
       - 0x0A -- QMI_VOICE_REASON_BARR_ ALLINCOMING -- 
                 All incoming \n
       - 0x0B -- QMI_VOICE_REASON_BARR_ INCOMINGROAMING -- 
                 Roaming incoming \n
       - 0x0C -- QMI_VOICE_REASON_BARR_ ALLBARRING -- 
                 All calls are barred \n
       - 0x0D -- QMI_VOICE_REASON_BARR_ ALLOUTGOINGBARRING -- 
                 All outgoing calls are barred \n
       - 0x0E -- QMI_VOICE_REASON_BARR_ ALLINCOMINGBARRING -- 
                 All incoming calls are barred \n
       - 0x15 -- QMI_VOICE_REASON_BARR_ INCOMINGNUMBER -- 
                 Incoming calls from registered and activated numbers are barred \n
       - 0x16 -- QMI_VOICE_REASON_BARR_ INCOMINGANONYMOUS -- 
                 Incoming calls from anonymous numbers are barred
  */

  /* Optional */
  /*  Service Class */
  uint8_t service_class_valid;  /**< Must be set to true if service_class is being passed */
  uint8_t service_class;
  /**<   Service Class is a combination (sum) of information class constants
       (information class constants are described in 
       Table @latexonly\ref{tbl:suppServiceInfoClass}@endlatexonly).
  */

  /* Optional */
  /*  Extended Service Class */
  uint8_t service_class_ext_valid;  /**< Must be set to true if service_class_ext is being passed */
  voice_service_class_enum_v02 service_class_ext;
  /**<   Extended service class; see Table @latexonly\ref{tbl:extServiceClass}@endlatexonly 
       for more information.
  */
}voice_get_call_barring_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Queries the status of call barring supplementary service 
             (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Service Class */
  uint8_t service_class_valid;  /**< Must be set to true if service_class is being passed */
  uint8_t service_class;
  /**<   Service Class is a combination (sum) of information class constants
       (information class constants are described in 
       Table @latexonly\ref{tbl:suppServiceInfoClass}@endlatexonly), which
       indicates that call barring is active for those information classes. 
       Service Class is set to 0 if call barring is not active for any of
       the information classes.
  */

  /* Optional */
  /*  Failure Cause  */
  uint8_t failure_cause_valid;  /**< Must be set to true if failure_cause is being passed */
  qmi_sups_errors_enum_v02 failure_cause;
  /**<   Supplementary services failure cause; 
       see @latexonly Table~\ref{tbl:endReasons}@endlatexonly for more information.
  */

  /* Optional */
  /*  Alpha Identifier */
  uint8_t alpha_id_valid;  /**< Must be set to true if alpha_id is being passed */
  voice_alpha_ident_type_v02 alpha_id;

  /* Optional */
  /*  Call Control Result Type */
  uint8_t cc_result_type_valid;  /**< Must be set to true if cc_result_type is being passed */
  voice_cc_result_type_enum_v02 cc_result_type;
  /**<   Values: \n
      - VOICE_CC_RESULT_TYPE_VOICE (0x00) --  VOICE \n 
      - VOICE_CC_RESULT_TYPE_SUPS (0x01) --  SUPS \n 
      - VOICE_CC_RESULT_TYPE_USSD (0x02) --  USSD \n 
      - VOICE_CC_RESULT_TYPE_VT (0x03) --  VT 
 */

  /* Optional */
  /*  Call ID */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Call ID of the voice call that resulted from call control;  
       ID is present when cc_result_type is present and is Voice.
  */

  /* Optional */
  /*  Call Control Supplementary Service Type */
  uint8_t cc_sups_result_valid;  /**< Must be set to true if cc_sups_result is being passed */
  voice_cc_sups_result_type_v02 cc_sups_result;
  /**<   (Supplementary service data that resulted from call control;
       data is present when cc_result_type is present and is other than Voice.)
  */

  /* Optional */
  /*  Extended Service Class */
  uint8_t service_class_ext_valid;  /**< Must be set to true if service_class_ext is being passed */
  voice_service_class_enum_v02 service_class_ext;
  /**<   Extended service class; see Table @latexonly\ref{tbl:extServiceClass}@endlatexonly 
       for more information.
  */

  /* Optional */
  /*  Barred Number List */
  uint8_t sc_barred_numbers_status_list_valid;  /**< Must be set to true if sc_barred_numbers_status_list is being passed */
  uint32_t sc_barred_numbers_status_list_len;  /**< Must be set to # of elements in sc_barred_numbers_status_list */
  voice_serviceclass_barred_number_list_type_v02 sc_barred_numbers_status_list[QMI_VOICE_SERVICE_CLASS_LIST_MAX_V02];
  /**<   \n
       List of barred numbers with the service class and activation status.
  */

  /* Optional */
  /*  Retry Duration */
  uint8_t retry_duration_valid;  /**< Must be set to true if retry_duration is being passed */
  uint16_t retry_duration;
  /**<   Retry duration in seconds.
  */

  /* Optional */
  /*  Failure Cause Description  */
  uint8_t failure_cause_description_valid;  /**< Must be set to true if failure_cause_description is being passed */
  uint32_t failure_cause_description_len;  /**< Must be set to # of elements in failure_cause_description */
  uint16_t failure_cause_description[QMI_VOICE_FAILURE_CAUSE_DESC_MAX_LEN_V02];
  /**<   Failure cause description received from the network. This text can contain 
       up to 256 UTF-16 characters and it is not guaranteed to be NULL terminated.
       Length range: 0 to 256.
  */

  /* Optional */
  /*  SIP Error Code */
  uint8_t sip_error_code_valid;  /**< Must be set to true if sip_error_code is being passed */
  uint16_t sip_error_code;
  /**<   SIP error code for supplemental service failure.
  */
}voice_get_call_barring_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Queries the status of the Calling Line Identification
             Presentation (CLIP) supplementary service.               */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}voice_get_clip_req_msg_v02;

  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  active_status_enum_v02 active_status;
  /**<   Active status. Values: \n
       - 0x00 -- ACTIVE_STATUS_INACTIVE -- Inactive \n
       - 0x01 -- ACTIVE_STATUS_ACTIVE -- Active
  */

  provision_status_enum_v02 provision_status;
  /**<   Provisioned status. Values: \n
       - 0x00 -- PROVISION_STATUS_ NOT_PROVISIONED -- Not provisioned \n
       - 0x01 -- PROVISION_STATUS_ PROVISIONED_PERMANENT -- Provisioned \n
       All other values are not used
  */
}voice_clip_response_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Queries the status of the Calling Line Identification
             Presentation (CLIP) supplementary service.               */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  CLIP Response */
  uint8_t clip_response_valid;  /**< Must be set to true if clip_response is being passed */
  voice_clip_response_type_v02 clip_response;

  /* Optional */
  /*  Failure Cause  */
  uint8_t failure_cause_valid;  /**< Must be set to true if failure_cause is being passed */
  qmi_sups_errors_enum_v02 failure_cause;
  /**<   Supplementary services failure cause; 
       see @latexonly Table~\ref{tbl:endReasons}@endlatexonly for more information.
  */

  /* Optional */
  /*  Alpha Identifier */
  uint8_t alpha_id_valid;  /**< Must be set to true if alpha_id is being passed */
  voice_alpha_ident_type_v02 alpha_id;

  /* Optional */
  /*  Call Control Result Type */
  uint8_t cc_result_type_valid;  /**< Must be set to true if cc_result_type is being passed */
  voice_cc_result_type_enum_v02 cc_result_type;
  /**<   Values: \n
      - VOICE_CC_RESULT_TYPE_VOICE (0x00) --  VOICE \n 
      - VOICE_CC_RESULT_TYPE_SUPS (0x01) --  SUPS \n 
      - VOICE_CC_RESULT_TYPE_USSD (0x02) --  USSD \n 
      - VOICE_CC_RESULT_TYPE_VT (0x03) --  VT 
 */

  /* Optional */
  /*  Call ID */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Call ID of the voice call that resulted from call control;  
       ID is present when cc_result_type is present and is Voice.
  */

  /* Optional */
  /*  Call Control Supplementary Service Type */
  uint8_t cc_sups_result_valid;  /**< Must be set to true if cc_sups_result is being passed */
  voice_cc_sups_result_type_v02 cc_sups_result;
  /**<   (Supplementary service data that resulted from call control;
       data is present when cc_result_type is present and is other than Voice.)
  */

  /* Optional */
  /*  Retry Duration */
  uint8_t retry_duration_valid;  /**< Must be set to true if retry_duration is being passed */
  uint16_t retry_duration;
  /**<   Retry duration in seconds.
  */

  /* Optional */
  /*  Failure Cause Description  */
  uint8_t failure_cause_description_valid;  /**< Must be set to true if failure_cause_description is being passed */
  uint32_t failure_cause_description_len;  /**< Must be set to # of elements in failure_cause_description */
  uint16_t failure_cause_description[QMI_VOICE_FAILURE_CAUSE_DESC_MAX_LEN_V02];
  /**<   Failure cause description received from the network. This text can contain 
       up to 256 UTF-16 characters and it is not guaranteed to be NULL terminated.
       Length range: 0 to 256.
  */

  /* Optional */
  /*  SIP Error Code */
  uint8_t sip_error_code_valid;  /**< Must be set to true if sip_error_code is being passed */
  uint16_t sip_error_code;
  /**<   SIP error code for supplemental service failure.
  */
}voice_get_clip_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Queries the status of the Calling Line Identification
             Restriction (CLIR) supplementary service 
             (applicable only for 3GPP). */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}voice_get_clir_req_msg_v02;

  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  active_status_enum_v02 active_status;
  /**<   Active status. Values: \n
       - 0x00 -- ACTIVE_STATUS_INACTIVE -- Inactive \n
       - 0x01 -- ACTIVE_STATUS_ACTIVE -- Active
  */

  provision_status_enum_v02 provision_status;
  /**<   Provisioned status. Values: \n
       - 0x00 -- PROVISION_STATUS_ NOT_PROVISIONED -- Not provisioned \n
       - 0x01 -- PROVISION_STATUS_ PROVISIONED_PERMANENT -- Permanently provisioned \n
       - 0x02 -- PROVISION_STATUS_ PRESENTATION_RESTRICTED -- Restricted presentation \n
       - 0x03 -- PROVISION_STATUS_ PRESENTATION_ALLOWED -- Allowed presentation
  */
}voice_clir_response_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Queries the status of the Calling Line Identification
             Restriction (CLIR) supplementary service 
             (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  CLIR Response */
  uint8_t clir_response_valid;  /**< Must be set to true if clir_response is being passed */
  voice_clir_response_type_v02 clir_response;

  /* Optional */
  /*  Failure Cause  */
  uint8_t failure_cause_valid;  /**< Must be set to true if failure_cause is being passed */
  qmi_sups_errors_enum_v02 failure_cause;
  /**<   Supplementary services failure cause; 
       see @latexonly Table~\ref{tbl:endReasons}@endlatexonly for more information.
  */

  /* Optional */
  /*  Alpha Identifier */
  uint8_t alpha_id_valid;  /**< Must be set to true if alpha_id is being passed */
  voice_alpha_ident_type_v02 alpha_id;

  /* Optional */
  /*  Call Control Result Type */
  uint8_t cc_result_type_valid;  /**< Must be set to true if cc_result_type is being passed */
  voice_cc_result_type_enum_v02 cc_result_type;
  /**<   Values: \n
      - VOICE_CC_RESULT_TYPE_VOICE (0x00) --  VOICE \n 
      - VOICE_CC_RESULT_TYPE_SUPS (0x01) --  SUPS \n 
      - VOICE_CC_RESULT_TYPE_USSD (0x02) --  USSD \n 
      - VOICE_CC_RESULT_TYPE_VT (0x03) --  VT 
 */

  /* Optional */
  /*  Call ID */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Call ID of the voice call that resulted from call control;  
       ID is present when cc_result_type is present and is Voice.
  */

  /* Optional */
  /*  Call Control Supplementary Service Type */
  uint8_t cc_sups_result_valid;  /**< Must be set to true if cc_sups_result is being passed */
  voice_cc_sups_result_type_v02 cc_sups_result;
  /**<   (Supplementary service data that resulted from call control;
       data is present when cc_result_type is present and is other than Voice.)
  */

  /* Optional */
  /*  Retry Duration */
  uint8_t retry_duration_valid;  /**< Must be set to true if retry_duration is being passed */
  uint16_t retry_duration;
  /**<   Retry duration in seconds.
  */

  /* Optional */
  /*  Failure Cause Description  */
  uint8_t failure_cause_description_valid;  /**< Must be set to true if failure_cause_description is being passed */
  uint32_t failure_cause_description_len;  /**< Must be set to # of elements in failure_cause_description */
  uint16_t failure_cause_description[QMI_VOICE_FAILURE_CAUSE_DESC_MAX_LEN_V02];
  /**<   Failure cause description received from the network. This text can contain 
       up to 256 UTF-16 characters and it is not guaranteed to be NULL terminated.
       Length range: 0 to 256.
  */

  /* Optional */
  /*  SIP Error Code */
  uint8_t sip_error_code_valid;  /**< Must be set to true if sip_error_code is being passed */
  uint16_t sip_error_code;
  /**<   SIP error code for supplemental service failure.
  */
}voice_get_clir_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Queries the status of call forwarding supplementary service 
             (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Call Forwarding Reason */
  voice_reason_enum_v02 reason;
  /**<   Reason. Values: \n
       - 0x01 -- QMI_VOICE_REASON_ FWDREASON_UNCONDITIONAL -- 
                 Unconditional call forwarding \n
       - 0x02 -- QMI_VOICE_REASON_ FWDREASON_MOBILEBUSY -- 
                 Forward when the mobile is busy \n
       - 0x03 -- QMI_VOICE_REASON_ FWDREASON_NOREPLY -- 
                 Forward when there is no reply \n
       - 0x04 -- QMI_VOICE_REASON_ FWDREASON_UNREACHABLE -- 
                 Forward when the call is unreachable \n
       - 0x05 -- QMI_VOICE_REASON_ FWDREASON_ALLFORWARDING -- 
                 All forwarding \n
       - 0x06 -- QMI_VOICE_REASON_ FWDREASON_ALLCONDITIONAL -- 
                 All conditional forwarding
  */

  /* Optional */
  /*  Service Class */
  uint8_t service_class_valid;  /**< Must be set to true if service_class is being passed */
  uint8_t service_class;
  /**<   Service Class is a combination (sum) of information class constants
       (information class constants are described in 
       Table @latexonly\ref{tbl:suppServiceInfoClass}@endlatexonly).
  */

  /* Optional */
  /*  Extended Service Class */
  uint8_t service_class_ext_valid;  /**< Must be set to true if service_class_ext is being passed */
  voice_service_class_enum_v02 service_class_ext;
  /**<   Extended service class; see Table @latexonly\ref{tbl:extServiceClass}@endlatexonly 
       for more information.
  */
}voice_get_call_forwarding_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  SERVICE_STATUS_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  SERVICE_STATUS_INACTIVE_V02 = 0x00, 
  SERVICE_STATUS_ACTIVE_V02 = 0x01, 
  SERVICE_STATUS_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}service_status_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  service_status_enum_v02 service_status;
  /**<   Service status. Values: \n
       - 0x00 -- SERVICE_STATUS_INACTIVE -- Inactive \n
       - 0x01 -- SERVICE_STATUS_ACTIVE -- Active
  */

  uint8_t service_class;
  /**<   Service Class is a combination (sum) of information class constants
       (information class constants are described in 
       Table @latexonly\ref{tbl:suppServiceInfoClass}@endlatexonly).
  */

  uint32_t number_len;  /**< Must be set to # of elements in number */
  char number[QMI_VOICE_NUMBER_MAX_V02];
  /**<   Call forwarding number in ASCII characters.*/

  uint8_t no_reply_timer;
  /**<   No reply timer value in seconds; a value of 0 indicates that 
       no_reply_timer is ignored.
  */
}voice_get_call_forwarding_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  service_status_enum_v02 service_status;
  /**<   Service status. Values: \n
       - 0x00 -- SERVICE_STATUS_INACTIVE -- Inactive \n
       - 0x01 -- SERVICE_STATUS_ACTIVE -- Active
  */

  uint8_t service_class;
  /**<   Service Class is a combination (sum) of information class constants
       (information class constants are described in 
       Table @latexonly\ref{tbl:suppServiceInfoClass}@endlatexonly).
  */

  uint8_t no_reply_timer;
  /**<   No reply timer value in seconds; a value of 0 indicates that 
	   no_reply_timer is ignored.
  */

  voice_num_info_type_v02 cfw_num_info;
}voice_get_call_forwarding_info_exten_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  service_status_enum_v02 service_status;
  /**<   Service status. Values: \n
       - 0x00 -- SERVICE_STATUS_INACTIVE -- Inactive \n
       - 0x01 -- SERVICE_STATUS_ACTIVE -- Active
  */

  voice_service_class_enum_v02 service_class_ext;
  /**<   Extended service class; see Table @latexonly\ref{tbl:extServiceClass}@endlatexonly 
       for more information.
  */

  uint8_t no_reply_timer;
  /**<   No reply timer value in seconds; a value of 0 indicates that 
       no_reply_timer is ignored.
  */

  voice_num_info_type_v02 cfw_num_info;
}voice_get_call_forwarding_info_exten2_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Queries the status of call forwarding supplementary service 
             (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Get Call Forwarding Info */
  uint8_t get_call_forwarding_info_valid;  /**< Must be set to true if get_call_forwarding_info is being passed */
  uint32_t get_call_forwarding_info_len;  /**< Must be set to # of elements in get_call_forwarding_info */
  voice_get_call_forwarding_info_type_v02 get_call_forwarding_info[GET_CALL_FORWARDING_INFO_MAX_V02];

  /* Optional */
  /*  Failure Cause  */
  uint8_t failure_cause_valid;  /**< Must be set to true if failure_cause is being passed */
  qmi_sups_errors_enum_v02 failure_cause;
  /**<   Supplementary services failure cause; 
       see @latexonly Table~\ref{tbl:endReasons}@endlatexonly for more information.
  */

  /* Optional */
  /*  Alpha Identifier */
  uint8_t alpha_id_valid;  /**< Must be set to true if alpha_id is being passed */
  voice_alpha_ident_type_v02 alpha_id;

  /* Optional */
  /*  Call Control Result Type */
  uint8_t cc_result_type_valid;  /**< Must be set to true if cc_result_type is being passed */
  voice_cc_result_type_enum_v02 cc_result_type;
  /**<   Values: \n
      - VOICE_CC_RESULT_TYPE_VOICE (0x00) --  VOICE \n 
      - VOICE_CC_RESULT_TYPE_SUPS (0x01) --  SUPS \n 
      - VOICE_CC_RESULT_TYPE_USSD (0x02) --  USSD \n 
      - VOICE_CC_RESULT_TYPE_VT (0x03) --  VT 
 */

  /* Optional */
  /*  Call ID */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Call ID of the voice call that resulted from call control;  
       ID is present when cc_result_type is present and is Voice.
  */

  /* Optional */
  /*  Call Control Supplementary Service Type */
  uint8_t cc_sups_result_valid;  /**< Must be set to true if cc_sups_result is being passed */
  voice_cc_sups_result_type_v02 cc_sups_result;
  /**<   (Supplementary service data that resulted from call control;
       data is present when cc_result_type is present and is other than Voice.)
  */

  /* Optional */
  /*  Get Call Forwarding Extended Info */
  uint8_t get_call_forwarding_exten_info_valid;  /**< Must be set to true if get_call_forwarding_exten_info is being passed */
  uint32_t get_call_forwarding_exten_info_len;  /**< Must be set to # of elements in get_call_forwarding_exten_info */
  voice_get_call_forwarding_info_exten_type_v02 get_call_forwarding_exten_info[GET_CALL_FORWARDING_INFO_MAX_V02];

  /* Optional */
  /*  Get Call Forwarding Extended Info 2 */
  uint8_t get_call_forwarding_exten2_info_valid;  /**< Must be set to true if get_call_forwarding_exten2_info is being passed */
  uint32_t get_call_forwarding_exten2_info_len;  /**< Must be set to # of elements in get_call_forwarding_exten2_info */
  voice_get_call_forwarding_info_exten2_type_v02 get_call_forwarding_exten2_info[GET_CALL_FORWARDING_INFO_MAX_V02];

  /* Optional */
  /*  Retry Duration */
  uint8_t retry_duration_valid;  /**< Must be set to true if retry_duration is being passed */
  uint16_t retry_duration;
  /**<   Retry duration in seconds.
  */

  /* Optional */
  /*  Provision Status */
  uint8_t provision_status_valid;  /**< Must be set to true if provision_status is being passed */
  provision_status_enum_v02 provision_status;
  /**<   Values: \n
       - 0x00 -- PROVISION_STATUS_ NOT_PROVISIONED -- Not provisioned \n
       - 0x01 -- PROVISION_STATUS_ PROVISIONED_PERMANENT -- Provisioned \n
       All other values are not used
  */

  /* Optional */
  /*  Call Forwarding Start Time */
  uint8_t call_fwd_start_time_valid;  /**< Must be set to true if call_fwd_start_time is being passed */
  voice_time_type_v02 call_fwd_start_time;

  /* Optional */
  /*  Call Forwarding End Time */
  uint8_t call_fwd_end_time_valid;  /**< Must be set to true if call_fwd_end_time is being passed */
  voice_time_type_v02 call_fwd_end_time;

  /* Optional */
  /*  Failure Cause Description  */
  uint8_t failure_cause_description_valid;  /**< Must be set to true if failure_cause_description is being passed */
  uint32_t failure_cause_description_len;  /**< Must be set to # of elements in failure_cause_description */
  uint16_t failure_cause_description[QMI_VOICE_FAILURE_CAUSE_DESC_MAX_LEN_V02];
  /**<   Failure cause description received from the network. This text can contain 
       up to 256 UTF-16 characters and it is not guaranteed to be NULL terminated.
       Length range: 0 to 256.
  */

  /* Optional */
  /*  SIP Error Code */
  uint8_t sip_error_code_valid;  /**< Must be set to true if sip_error_code is being passed */
  uint16_t sip_error_code;
  /**<   SIP error code for supplemental service failure.
  */
}voice_get_call_forwarding_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  voice_reason_enum_v02 reason;
  /**<   Reason. Values: \n
       - 0x07 -- VOICE_REASON_BARR_ ALLOUTGOING -- 
                 All outgoing \n
       - 0x08 -- VOICE_REASON_BARR_ OUTGOINGINT -- 
                 Outgoing internal \n
       - 0x09 -- VOICE_REASON_BARR_ OUTGOINGINTEXTOHOME -- 
                 Outgoing external to home \n
       - 0x0A -- VOICE_REASON_BARR_ ALLINCOMING -- 
                 All incoming \n
       - 0x0B -- VOICE_REASON_BARR_ INCOMINGROAMING -- 
                 Roaming incoming \n
       - 0x0C -- VOICE_REASON_BARR_ ALLBARRING -- 
                 All calls are barred \n
       - 0x0D -- VOICE_REASON_BARR_ ALLOUTGOINGBARRING -- 
                 All outgoing calls are barred \n
       - 0x0E -- VOICE_REASON_BARR_ ALLINCOMINGBARRING -- 
                 All incoming calls are barred \n
       - 0x15 -- VOICE_REASON_BARR_ INCOMINGNUMBER -- 
                 Incoming calls from registered and activated numbers are barred \n
       - 0x16 -- VOICE_REASON_BARR_ INCOMINGANONYMOUS -- 
                 Incoming calls from anonymous numbers are barred
  */

  char old_password[4];
  /**<   Old password. Password consists of 4 ASCII digits. Range: 0000 to 9999.
  */

  char new_password[4];
  /**<   New password. Password consists of 4 ASCII digits. Range: 0000 to 9999.
  */

  char new_password_again[4];
  /**<   New password again. Password consists of 4 ASCII digits. 
       Range: 0000 to 9999.
  */
}voice_call_barring_password_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Sets a call barring password (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Call Barring Password Information */
  voice_call_barring_password_info_type_v02 call_barring_password_info;
}voice_set_call_barring_password_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Sets a call barring password (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Failure Cause  */
  uint8_t failure_cause_valid;  /**< Must be set to true if failure_cause is being passed */
  qmi_sups_errors_enum_v02 failure_cause;
  /**<   Supplementary services failure cause; 
       see @latexonly Table~\ref{tbl:endReasons}@endlatexonly for more information.
  */

  /* Optional */
  /*  Alpha Identifier */
  uint8_t alpha_id_valid;  /**< Must be set to true if alpha_id is being passed */
  voice_alpha_ident_type_v02 alpha_id;

  /* Optional */
  /*  Call Control Result Type */
  uint8_t cc_result_type_valid;  /**< Must be set to true if cc_result_type is being passed */
  voice_cc_result_type_enum_v02 cc_result_type;
  /**<   Values: \n
      - VOICE_CC_RESULT_TYPE_VOICE (0x00) --  VOICE \n 
      - VOICE_CC_RESULT_TYPE_SUPS (0x01) --  SUPS \n 
      - VOICE_CC_RESULT_TYPE_USSD (0x02) --  USSD \n 
      - VOICE_CC_RESULT_TYPE_VT (0x03) --  VT 
 */

  /* Optional */
  /*  Call ID */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Call ID of the voice call that resulted from call control;  
       ID is present when cc_result_type is present and is Voice.
  */

  /* Optional */
  /*  Call Control Supplementary Service Type */
  uint8_t cc_sups_result_valid;  /**< Must be set to true if cc_sups_result is being passed */
  voice_cc_sups_result_type_v02 cc_sups_result;
  /**<   (Supplementary service data that resulted from call control;
       data is present when cc_result_type is present and is other than Voice.)
  */

  /* Optional */
  /*  Retry Duration */
  uint8_t retry_duration_valid;  /**< Must be set to true if retry_duration is being passed */
  uint16_t retry_duration;
  /**<   Retry duration in seconds.
  */

  /* Optional */
  /*  Failure Cause Description  */
  uint8_t failure_cause_description_valid;  /**< Must be set to true if failure_cause_description is being passed */
  uint32_t failure_cause_description_len;  /**< Must be set to # of elements in failure_cause_description */
  uint16_t failure_cause_description[QMI_VOICE_FAILURE_CAUSE_DESC_MAX_LEN_V02];
  /**<   Failure cause description received from the network. This text can contain 
       up to 256 UTF-16 characters and it is not guaranteed to be NULL terminated.
       Length range: 0 to 256.
  */

  /* Optional */
  /*  SIP Error Code */
  uint8_t sip_error_code_valid;  /**< Must be set to true if sip_error_code is being passed */
  uint16_t sip_error_code;
  /**<   SIP error code for supplemental service failure
  */
}voice_set_call_barring_password_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  USS_DCS_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  USS_DCS_ASCII_V02 = 0x01, 
  USS_DCS_8BIT_V02 = 0x02, 
  USS_DCS_UCS2_V02 = 0x03, 
  USS_DCS_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uss_dcs_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uss_dcs_enum_v02 uss_dcs;
  /**<   Unstructured supplementary service data coding scheme. Values: \n
       - 0x01 -- USS_DCS_ASCII -- ASCII coding scheme \n
       - 0x02 -- USS_DCS_8BIT  -- 8-bit coding scheme per \hyperref[STD-23038]{3GPP TS 23.038} \n
       - 0x03 -- USS_DCS_UCS2  -- UCS2
  */

  uint32_t uss_data_len;  /**< Must be set to # of elements in uss_data */
  uint8_t uss_data[QMI_VOICE_USS_DATA_MAX_V02];
  /**<   USS data per the coding scheme.
  */
}voice_uss_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Initiates an Unstructured Supplementary Service Data (USSD) 
             operation (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  USS Information */
  voice_uss_info_type_v02 uss_info;

  /* Optional */
  /*  Secondary Line Number */
  uint8_t secondary_number_valid;  /**< Must be set to true if secondary_number is being passed */
  char secondary_number[QMI_VOICE_NUMBER_MAX_V02 + 1];
  /**<   Secondary number of the originating party in ASCII string. \n
       Length range is 1 to 81.
  */

  /* Optional */
  /*  Is Secondary */
  uint8_t is_secondary_valid;  /**< Must be set to true if is_secondary is being passed */
  uint8_t is_secondary;
  /**<   Whether the USSD is originated on a secondary line. \n 
       Set to FALSE by default.
   */
}voice_orig_ussd_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Initiates an Unstructured Supplementary Service Data (USSD) 
             operation (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Failure Cause  */
  uint8_t failure_cause_valid;  /**< Must be set to true if failure_cause is being passed */
  qmi_sups_errors_enum_v02 failure_cause;
  /**<   Supplementary services failure cause; 
       see @latexonly Table~\ref{tbl:endReasons}@endlatexonly for more information.
  */

  /* Optional */
  /*  Alpha Identifier */
  uint8_t alpha_id_valid;  /**< Must be set to true if alpha_id is being passed */
  voice_alpha_ident_type_v02 alpha_id;

  /* Optional */
  /*  USS Data from Network */
  uint8_t uss_info_valid;  /**< Must be set to true if uss_info is being passed */
  voice_uss_info_type_v02 uss_info;

  /* Optional */
  /*  Call Control Result Type */
  uint8_t cc_result_type_valid;  /**< Must be set to true if cc_result_type is being passed */
  voice_cc_result_type_enum_v02 cc_result_type;
  /**<   Values: \n
      - VOICE_CC_RESULT_TYPE_VOICE (0x00) --  VOICE \n 
      - VOICE_CC_RESULT_TYPE_SUPS (0x01) --  SUPS \n 
      - VOICE_CC_RESULT_TYPE_USSD (0x02) --  USSD \n 
      - VOICE_CC_RESULT_TYPE_VT (0x03) --  VT 
 */

  /* Optional */
  /*  Call ID */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Call ID of the voice call that resulted from call control;  
       ID is present when cc_result_type is present and is Voice.
  */

  /* Optional */
  /*  Call Control Supplementary Service Type */
  uint8_t cc_sups_result_valid;  /**< Must be set to true if cc_sups_result is being passed */
  voice_cc_sups_result_type_v02 cc_sups_result;
  /**<   (Supplementary service data that resulted from call control;
       data is present when cc_result_type is present and is other than Voice.)
  */

  /* Optional */
  /*  USS Data from Network in UTF-16 Encoding */
  uint8_t uss_info_utf16_valid;  /**< Must be set to true if uss_info_utf16 is being passed */
  uint32_t uss_info_utf16_len;  /**< Must be set to # of elements in uss_info_utf16 */
  uint16_t uss_info_utf16[QMI_VOICE_USS_DATA_MAX_V02];
  /**<   Unstructured supplementary service information in UTF-16 encoding. 
  */

  /* Optional */
  /*  Failure Cause Description  */
  uint8_t failure_cause_description_valid;  /**< Must be set to true if failure_cause_description is being passed */
  uint32_t failure_cause_description_len;  /**< Must be set to # of elements in failure_cause_description */
  uint16_t failure_cause_description[QMI_VOICE_FAILURE_CAUSE_DESC_MAX_LEN_V02];
  /**<   Failure cause description received from the network. This text can contain 
       up to 256 UTF-16 characters and it is not guaranteed to be NULL terminated.
       Length range: 0 to 256.
  */

  /* Optional */
  /*  SIP Error Code */
  uint8_t sip_error_code_valid;  /**< Must be set to true if sip_error_code is being passed */
  uint16_t sip_error_code;
  /**<   SIP error code for supplemental service failure.
  */

  /* Optional */
  /*  Secondary line number */
  uint8_t secondary_number_valid;  /**< Must be set to true if secondary_number is being passed */
  char secondary_number[QMI_VOICE_NUMBER_MAX_V02 + 1];
  /**<   Secondary number of the originating party in ASCII string. \n
       Length range is 1 to 81.
  */

  /* Optional */
  /*  Is Secondary */
  uint8_t is_secondary_valid;  /**< Must be set to true if is_secondary is being passed */
  uint8_t is_secondary;
  /**<   Whether the USSD is originated on a secondary line. \n 
       Set to FALSE by default.
  */
}voice_orig_ussd_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Responds to the USSD request from the network 
             (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  USS Information */
  voice_uss_info_type_v02 uss_info;
}voice_answer_ussd_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Responds to the USSD request from the network 
             (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}voice_answer_ussd_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Aborts an ongoing USSD operation (applicable only for 3GPP). */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}voice_cancel_ussd_req_msg_v02;

  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Aborts an ongoing USSD operation (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}voice_cancel_ussd_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Notifies clients that the USSD session is terminated by the
             network (applicable only for 3GPP). */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}voice_ussd_release_ind_msg_v02;

  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  FURTHER_USER_ACTION_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  FURTHER_USER_ACTION_NOT_REQUIRED_V02 = 0x01, 
  FURTHER_USER_ACTION_REQUIRED_V02 = 0x02, 
  FURTHER_USER_ACTION_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}further_user_action_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Notifies clients about any USSD requests or notifications from
             the network (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Notification Type */
  further_user_action_enum_v02 notification_type;
  /**<   Notification type. Values: \n
       - 0x01 -- FURTHER_USER_ACTION_NOT_ REQUIRED -- No further action is required \n
       - 0x02 -- FURTHER_USER_ACTION_ REQUIRED -- Further action is required
  */

  /* Optional */
  /*  USS Data from Network */
  uint8_t uss_info_valid;  /**< Must be set to true if uss_info is being passed */
  voice_uss_info_type_v02 uss_info;

  /* Optional */
  /*  USS Data from Network in UTF-16 Encoding */
  uint8_t uss_info_utf16_valid;  /**< Must be set to true if uss_info_utf16 is being passed */
  uint32_t uss_info_utf16_len;  /**< Must be set to # of elements in uss_info_utf16 */
  uint16_t uss_info_utf16[QMI_VOICE_USS_DATA_MAX_V02];
  /**<   Unstructured supplementary service information in UTF-16 encoding. 
  */

  /* Optional */
  /*  Failure Cause Description  */
  uint8_t failure_cause_description_valid;  /**< Must be set to true if failure_cause_description is being passed */
  uint32_t failure_cause_description_len;  /**< Must be set to # of elements in failure_cause_description */
  uint16_t failure_cause_description[QMI_VOICE_FAILURE_CAUSE_DESC_MAX_LEN_V02];
  /**<   Failure cause description received from the network. This text can contain 
       up to 256 UTF-16 characters and it is not guaranteed to be NULL terminated.
       Length range: 0 to 256.
  */

  /* Optional */
  /*  SIP Error Code */
  uint8_t sip_error_code_valid;  /**< Must be set to true if sip_error_code is being passed */
  uint16_t sip_error_code;
  /**<   SIP error code for supplemental service failure.
  */
}voice_ussd_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Indicates a notification of User-to-User Signaling (UUS) 
             information from the network (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  UUS Information** */
  voice_uus_info_type_v02 uus_information;
}voice_uus_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t nam_id;
  /**<   Index of the NAM (CDMA subscription) to be configured. 
       Range: 0 to 3. Note that some modems support only 1 or 2 NAMs.
  */

  uint32_t air_timer;
  /**<   Time in minutes; cumulative air time is slammed.
  */
}voice_air_timer_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t nam_id;
  /**<   Index of the NAM (CDMA subscription) to be configured. 
       Range: 0 to 3. Note that some modems support only 1 or 2 NAMs.
  */

  uint32_t roam_timer;
  /**<   Time in minutes; cumulative air time is slammed.
  */
}voice_roam_timer_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_SO_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_SO_WILD_V02 = 0x0000, /**<  Any service option \n  */
  VOICE_SO_IS_96A_V02 = 0x0001, /**<  IS-96A \n  */
  VOICE_SO_EVRC_V02 = 0x0003, /**<  EVRC \n  */
  VOICE_SO_13K_IS733_V02 = 0x0011, /**<  13K_IS733 \n  */
  VOICE_SO_SELECTABLE_MODE_VOCODER_V02 = 0x0038, /**<  Selectable mode vocoder \n  */
  VOICE_SO_4GV_NARR0W_BAND_V02 = 0x0044, /**<  4GV narrowband \n  */
  VOICE_SO_4GV_WIDE_BAND_V02 = 0x0046, /**<  4GV wideband \n  */
  VOICE_SO_EVRC_SO73_V02 = 0x0049, /**<  EVRC-SO73 \n  */
  VOICE_SO_13K_V02 = 0x8000, /**<  13K \n  */
  VOICE_SO_IS_96_V02 = 0x8001, /**<  IS-96A \n  */
  VOICE_SO_WVRC_V02 = 0x8023, /**<  WVRC  */
  VOICE_SO_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_so_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t nam_id;
  /**<   Index of the NAM (CDMA subscription) to be configured. 
       Range: 0 to 3. Note that some modems support only 1 or 2 NAMs.
  */

  uint8_t evrc_capability;
  /**<   EVRC capability. Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable
  */

  voice_so_enum_v02 home_page_voice_so;
  /**<   Home page voice SO; most preferred CDMA SO to be requested from the 
 network when receiving an incoming (MT) voice call within the home 
 network. Values: \n
      - VOICE_SO_WILD (0x0000) --  Any service option \n 
      - VOICE_SO_IS_96A (0x0001) --  IS-96A \n 
      - VOICE_SO_EVRC (0x0003) --  EVRC \n 
      - VOICE_SO_13K_IS733 (0x0011) --  13K_IS733 \n 
      - VOICE_SO_SELECTABLE_MODE_VOCODER (0x0038) --  Selectable mode vocoder \n 
      - VOICE_SO_4GV_NARR0W_BAND (0x0044) --  4GV narrowband \n 
      - VOICE_SO_4GV_WIDE_BAND (0x0046) --  4GV wideband \n 
      - VOICE_SO_EVRC_SO73 (0x0049) --  EVRC-SO73 \n 
      - VOICE_SO_13K (0x8000) --  13K \n 
      - VOICE_SO_IS_96 (0x8001) --  IS-96A \n 
      - VOICE_SO_WVRC (0x8023) --  WVRC 
 */

  voice_so_enum_v02 home_orig_voice_so;
  /**<   Home origination voice SO; most preferred CDMA SO to be requested 
 from the network when initiating an MO voice call within the home 
 network. Values: \n
      - VOICE_SO_WILD (0x0000) --  Any service option \n 
      - VOICE_SO_IS_96A (0x0001) --  IS-96A \n 
      - VOICE_SO_EVRC (0x0003) --  EVRC \n 
      - VOICE_SO_13K_IS733 (0x0011) --  13K_IS733 \n 
      - VOICE_SO_SELECTABLE_MODE_VOCODER (0x0038) --  Selectable mode vocoder \n 
      - VOICE_SO_4GV_NARR0W_BAND (0x0044) --  4GV narrowband \n 
      - VOICE_SO_4GV_WIDE_BAND (0x0046) --  4GV wideband \n 
      - VOICE_SO_EVRC_SO73 (0x0049) --  EVRC-SO73 \n 
      - VOICE_SO_13K (0x8000) --  13K \n 
      - VOICE_SO_IS_96 (0x8001) --  IS-96A \n 
      - VOICE_SO_WVRC (0x8023) --  WVRC 
 */

  voice_so_enum_v02 roam_orig_voice_so;
  /**<   Roaming origination voice SO; most preferred CDMA SO to be requested 
 from the network when initiating an MO voice call outside the home 
 network. Values: \n
      - VOICE_SO_WILD (0x0000) --  Any service option \n 
      - VOICE_SO_IS_96A (0x0001) --  IS-96A \n 
      - VOICE_SO_EVRC (0x0003) --  EVRC \n 
      - VOICE_SO_13K_IS733 (0x0011) --  13K_IS733 \n 
      - VOICE_SO_SELECTABLE_MODE_VOCODER (0x0038) --  Selectable mode vocoder \n 
      - VOICE_SO_4GV_NARR0W_BAND (0x0044) --  4GV narrowband \n 
      - VOICE_SO_4GV_WIDE_BAND (0x0046) --  4GV wideband \n 
      - VOICE_SO_EVRC_SO73 (0x0049) --  EVRC-SO73 \n 
      - VOICE_SO_13K (0x8000) --  13K \n 
      - VOICE_SO_IS_96 (0x8001) --  IS-96A \n 
      - VOICE_SO_WVRC (0x8023) --  WVRC 
 */
}voice_preferred_voice_so_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  TTY_MODE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  TTY_MODE_FULL_V02 = 0x00, /**<  Full \n  */
  TTY_MODE_VCO_V02 = 0x01, /**<  Voice carry over \n  */
  TTY_MODE_HCO_V02 = 0x02, /**<  Hearing carry over \n  */
  TTY_MODE_OFF_V02 = 0x03, /**<  Off  */
  TTY_MODE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}tty_mode_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_DOMAIN_PREF_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_DOMAIN_PREF_CS_ONLY_V02 = 0x00, 
  VOICE_DOMAIN_PREF_PS_ONLY_V02 = 0x01, 
  VOICE_DOMAIN_PREF_CS_PREF_V02 = 0x02, 
  VOICE_DOMAIN_PREF_PS_PREF_V02 = 0x03, 
  VOICE_DOMAIN_PREF_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_domain_pref_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Sets various configuration parameters that control the modem
             behavior related to circuit-switched services. */
typedef struct {

  /* Optional */
  /*  Auto Answer (value specified is written to NV_AUTO_ANSWER_I) */
  uint8_t auto_answer_valid;  /**< Must be set to true if auto_answer is being passed */
  uint8_t auto_answer;
  /**<   Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable
  */

  /* Optional */
  /*  Air Timer (value specified is written to NV_AIR_CNT_I) */
  uint8_t air_timer_valid;  /**< Must be set to true if air_timer is being passed */
  voice_air_timer_type_v02 air_timer;

  /* Optional */
  /*  Roam Timer (value specified is written to NV_ROAM_CNT_I) */
  uint8_t roam_timer_valid;  /**< Must be set to true if roam_timer is being passed */
  voice_roam_timer_type_v02 roam_timer;

  /* Optional */
  /*  TTY mode (value specified is written to NV_TTY_I) */
  uint8_t tty_mode_valid;  /**< Must be set to true if tty_mode is being passed */
  tty_mode_enum_v02 tty_mode;
  /**<   Values: \n
       - 0x00 -- TTY_MODE_FULL -- Full \n
       - 0x01 -- TTY_MODE_VCO  -- Voice carry over \n
       - 0x02 -- TTY_MODE_HCO  -- Hearing carry over \n
       - 0x03 -- TTY_MODE_OFF  -- Off
  */

  /* Optional */
  /*  Preferred Voice SO (EVRC capability and preferred voice service options for the given NAM; value specified is written to NV_PREF_VOICE_SO_I) */
  uint8_t preferred_voice_so_valid;  /**< Must be set to true if preferred_voice_so is being passed */
  voice_preferred_voice_so_type_v02 preferred_voice_so;

  /* Optional */
  /*  Preferred Voice Domain */
  uint8_t voice_domain_valid;  /**< Must be set to true if voice_domain is being passed */
  voice_domain_pref_enum_v02 voice_domain;
  /**<   Values: \n
       - 0x00 -- VOICE_DOMAIN_PREF_CS_ONLY  -- Circuit-switched (CS) only \n
       - 0x01 -- VOICE_DOMAIN_PREF_PS_ONLY  -- Packet-switched (PS) only \n
       - 0x02 -- VOICE_DOMAIN_PREF_CS_PREF  -- CS is preferred; PS is secondary \n
       - 0x03 -- VOICE_DOMAIN_PREF_PS_PREF  -- PS is preferred; CS is secondary
  */

  /* Optional */
  /*  UI TTY Setting */
  uint8_t ui_tty_setting_valid;  /**< Must be set to true if ui_tty_setting is being passed */
  tty_mode_enum_v02 ui_tty_setting;
  /**<   Values: \n
       - 0x00 -- TTY_MODE_FULL -- Full \n
       - 0x01 -- TTY_MODE_VCO  -- Voice carry over \n
       - 0x02 -- TTY_MODE_HCO  -- Hearing carry over \n
       - 0x03 -- TTY_MODE_OFF  -- Off (default)
  */

  /* Optional */
  /*  eCall MSD */
  uint8_t ecall_msd_valid;  /**< Must be set to true if ecall_msd is being passed */
  uint32_t ecall_msd_len;  /**< Must be set to # of elements in ecall_msd */
  uint8_t ecall_msd[QMI_VOICE_ECALL_MSD_MAX_LEN_V02];
  /**<   eCall MSD can contain up to 140-byte
       ASN.1 unaligned PER data as described in 
       \hyperref[CEN-EN-15722]{CEN EN 15722}.
       Length range: 0 to 140. Set the length to 0 to disable this feature.
  */

  /* Optional */
  /*  Secure Call Enabled */
  uint8_t secure_call_functionality_available_valid;  /**< Must be set to true if secure_call_functionality_available is being passed */
  uint8_t secure_call_functionality_available;
  /**<   Whether the secure call feature is enabled. Values: \n
       - 0x00 -- Not enabled \n
       - 0x01 -- Enabled
  */
}voice_set_config_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Sets various configuration parameters that control the modem
             behavior related to circuit-switched services. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Auto Answer Status */
  uint8_t auto_answer_outcome_valid;  /**< Must be set to true if auto_answer_outcome is being passed */
  uint8_t auto_answer_outcome;
  /**<   Values: \n
       - 0x00 -- Information was written successfully \n
       - 0x01 -- Information write failed
  */

  /* Optional */
  /*  Air Timer Status */
  uint8_t air_timer_outcome_valid;  /**< Must be set to true if air_timer_outcome is being passed */
  uint8_t air_timer_outcome;
  /**<   Values: \n
       - 0x00 -- Information was written successfully \n
       - 0x01 -- Information write failed
  */

  /* Optional */
  /*  Roam Timer Status */
  uint8_t roam_timer_outcome_valid;  /**< Must be set to true if roam_timer_outcome is being passed */
  uint8_t roam_timer_outcome;
  /**<   Values: \n
       - 0x00 -- Information was written successfully \n
       - 0x01 -- Information write failed
  */

  /* Optional */
  /*  TTY Config Status */
  uint8_t tty_mode_outcome_valid;  /**< Must be set to true if tty_mode_outcome is being passed */
  uint8_t tty_mode_outcome;
  /**<   Values: \n
       - 0x00 -- Information was written successfully \n
       - 0x01 -- Information write failed
  */

  /* Optional */
  /*  Preferred Voice SO Status */
  uint8_t pref_voice_so_outcome_valid;  /**< Must be set to true if pref_voice_so_outcome is being passed */
  uint8_t pref_voice_so_outcome;
  /**<   Values: \n
       - 0x00 -- Information was written successfully \n
       - 0x01 -- Information write failed
  */

  /* Optional */
  /*  Voice Domain Preference Status */
  uint8_t voice_domain_pref_outcome_valid;  /**< Must be set to true if voice_domain_pref_outcome is being passed */
  uint8_t voice_domain_pref_outcome;
  /**<   Values: \n
       - 0x00 -- Information was written successfully \n
       - 0x01 -- Information write failed
  */

  /* Optional */
  /*  UI TTY Config Status */
  uint8_t ui_tty_setting_outcome_valid;  /**< Must be set to true if ui_tty_setting_outcome is being passed */
  uint8_t ui_tty_setting_outcome;
  /**<   Values: \n
       - 0x00 -- Information was written successfully \n
       - 0x01 -- Information write failed
  */

  /* Optional */
  /*  eCall MSD Config Status */
  uint8_t ecall_msd_outcome_valid;  /**< Must be set to true if ecall_msd_outcome is being passed */
  uint8_t ecall_msd_outcome;
  /**<   Values: \n
       - 0x00 -- Information was written successfully \n
       - 0x01 -- Information write failed
  */
}voice_set_config_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Retrieves various configuration parameters that control the modem
             behavior related to circuit switched services. */
typedef struct {

  /* Optional */
  /*  Auto Answer Status */
  uint8_t auto_answer_valid;  /**< Must be set to true if auto_answer is being passed */
  uint8_t auto_answer;
  /**<   Value: \n 
       - 0x01 -- Include auto answer information in the response message
  */

  /* Optional */
  /*  Air Timer */
  uint8_t air_timer_valid;  /**< Must be set to true if air_timer is being passed */
  uint8_t air_timer;
  /**<   Value: \n 
       - 0x01 -- Include air calls timer count information in the response message
  */

  /* Optional */
  /*  Roam Timer */
  uint8_t roam_timer_valid;  /**< Must be set to true if roam_timer is being passed */
  uint8_t roam_timer;
  /**<   Value: \n 
       - 0x01 -- Include roam calls timer information in the response message
  */

  /* Optional */
  /*  TTY Mode */
  uint8_t tty_mode_valid;  /**< Must be set to true if tty_mode is being passed */
  uint8_t tty_mode;
  /**<   Value: \n 
       - 0x01 -- Include TTY configuration status information in the response 
                 message
  */

  /* Optional */
  /*  Preferred Voice SO */
  uint8_t pref_voice_so_valid;  /**< Must be set to true if pref_voice_so is being passed */
  uint8_t pref_voice_so;
  /**<   Value: \n 
       - 0x01 -- Include preferred voice configuration status information in
                 the response message
  */

  /* Optional */
  /*  AMR Status */
  uint8_t amr_status_valid;  /**< Must be set to true if amr_status is being passed */
  uint8_t amr_status;
  /**<   Value: \n 
       - 0x01 -- Include AMR status information in the response message
  */

  /* Optional */
  /*  Preferred Voice Privacy */
  uint8_t voice_privacy_valid;  /**< Must be set to true if voice_privacy is being passed */
  uint8_t voice_privacy;
  /**<   Value: \n 
       - 0x01 -- Include preferred voice privacy status information in the 
                 response message
  */

  /* Optional */
  /*  Number Assignment Module Index */
  uint8_t nam_id_valid;  /**< Must be set to true if nam_id is being passed */
  uint8_t nam_id;
  /**<   Index of the NAM (CDMA subscription) to be configured. 
       Range: 0 to 3. Note that some modems support only 1 or 2 NAMs.
   */

  /* Optional */
  /*  Voice Domain Preference */
  uint8_t voice_domain_pref_valid;  /**< Must be set to true if voice_domain_pref is being passed */
  uint8_t voice_domain_pref;
  /**<   Value: \n 
       - 0x01 -- Include voice domain preference information in the response
                 message
  */

  /* Optional */
  /*  UI TTY Setting */
  uint8_t ui_tty_setting_valid;  /**< Must be set to true if ui_tty_setting is being passed */
  uint8_t ui_tty_setting;
  /**<   Value: \n 
       - 0x01 -- Include UI TTY configuration status information in the response 
                 message
  */
}voice_get_config_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t gsm_amr_status;
  /**<   Values: \n 
       - 0x00 -- Disable \n
       - 0x01 -- Enable 
  */

  uint8_t wcdma_amr_status;
  /**<   One or a combination of the following bitmask values: \n
       - Bit 0 -- QMI_VOICE_WCDMA_AMR_ STATUS_NOT_SUPPORTED_BIT -- 
                  AMR codec advertised is not supported \n
       - Bit 1 -- QMI_VOICE_WCDMA_AMR_ STATUS_WCDMA_AMR_WB_BIT -- 
                  Controls WCDMA AMR wideband \n
       - Bit 2 -- QMI_VOICE_WCDMA_AMR_ STATUS_GSM_HR_AMR_BIT -- 
                  Controls GSM half rate AMR \n
       - Bit 3 -- QMI_VOICE_WCDMA_AMR_ STATUS_GSM_AMR_WB_BIT -- 
                  Controls GSM AMR wideband \n
       - Bit 4 -- QMI_VOICE_WCDMA_AMR_ STATUS_GSM_AMR_NB_BIT -- 
                  Controls GSM AMR narrowband
  */
}voice_arm_config_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Retrieves various configuration parameters that control the modem
             behavior related to circuit switched services. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Auto Answer Status (value returned is read from NV_AUTO_ANSWER_I) */
  uint8_t auto_answer_status_valid;  /**< Must be set to true if auto_answer_status is being passed */
  uint8_t auto_answer_status;
  /**<   Values: \n
       - 0x00 -- Disabled \n
       - 0x01 -- Enabled
  */

  /* Optional */
  /*  Air Timer Count (value returned is read from NV_AIR_CNT_I) */
  uint8_t air_timer_count_valid;  /**< Must be set to true if air_timer_count is being passed */
  voice_air_timer_type_v02 air_timer_count;

  /* Optional */
  /*  Roam Timer Count (value returned is read from NV_ROAM_CNT_I) */
  uint8_t roam_timer_count_valid;  /**< Must be set to true if roam_timer_count is being passed */
  voice_roam_timer_type_v02 roam_timer_count;

  /* Optional */
  /*  Current TTY Mode (value returned is read from NV_TTY_I) */
  uint8_t current_tty_mode_valid;  /**< Must be set to true if current_tty_mode is being passed */
  tty_mode_enum_v02 current_tty_mode;
  /**<   Values: \n
       - 0x00 -- TTY_MODE_FULL -- Full \n
       - 0x01 -- TTY_MODE_VCO  -- Voice carry over \n
       - 0x02 -- TTY_MODE_HCO  -- Hearing carry over \n
       - 0x03 -- TTY_MODE_OFF  -- Off
  */

  /* Optional */
  /*  Current Preferred Voice SO (EVRC capability and preferred service options; value returned is read from NV_PREF_VOICE_SO_I) */
  uint8_t current_preferred_voice_so_valid;  /**< Must be set to true if current_preferred_voice_so is being passed */
  voice_preferred_voice_so_type_v02 current_preferred_voice_so;

  /* Optional */
  /*  Current AMR Configuration (values returned are read from NV_GSM_ARM_CALL_CONFIG_I and NV_UMTS_AMR_CODEC_ PREFERENCE_CONFIG_I) */
  uint8_t current_arm_config_valid;  /**< Must be set to true if current_arm_config is being passed */
  voice_arm_config_type_v02 current_arm_config;

  /* Optional */
  /*  Current Voice Privacy Preference (value returned is read from NV_VOICE_PRIV_I) */
  uint8_t current_voice_privacy_pref_valid;  /**< Must be set to true if current_voice_privacy_pref is being passed */
  voice_privacy_enum_v02 current_voice_privacy_pref;
  /**<   Values: \n 
       - 0x00 -- VOICE_PRIVACY_STANDARD -- Standard privacy \n
       - 0x01 -- VOICE_PRIVACY_ENHANCED -- Enhanced privacy
  */

  /* Optional */
  /*  Current Voice Domain Preference */
  uint8_t voice_domain_valid;  /**< Must be set to true if voice_domain is being passed */
  voice_domain_pref_enum_v02 voice_domain;
  /**<   Values: \n
       - 0x00 -- VOICE_DOMAIN_PREF_CS_ONLY  -- Circuit-switched (CS) only \n
       - 0x01 -- VOICE_DOMAIN_PREF_PS_ONLY  -- Packet-switched (PS) only \n
       - 0x02 -- VOICE_DOMAIN_PREF_CS_PREF  -- CS is preferred; PS is secondary \n
       - 0x03 -- VOICE_DOMAIN_PREF_PS_PREF  -- PS is preferred; CS is secondary
  */

  /* Optional */
  /*  Current UI TTY Setting */
  uint8_t current_ui_tty_setting_valid;  /**< Must be set to true if current_ui_tty_setting is being passed */
  tty_mode_enum_v02 current_ui_tty_setting;
  /**<   Values: \n
       - 0x00 -- TTY_MODE_FULL -- Full \n
       - 0x01 -- TTY_MODE_VCO  -- Voice carry over \n
       - 0x02 -- TTY_MODE_HCO  -- Hearing carry over \n
       - 0x03 -- TTY_MODE_OFF  -- Off
  */
}voice_get_config_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  SERVICE_TYPE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  SERVICE_TYPE_ACTIVATE_V02 = 0x01, 
  SERVICE_TYPE_DEACTIVATE_V02 = 0x02, 
  SERVICE_TYPE_REGISTER_V02 = 0x03, 
  SERVICE_TYPE_ERASE_V02 = 0x04, 
  SERVICE_TYPE_INTERROGATE_V02 = 0x05, 
  SERVICE_TYPE_REGISTER_PASSWORD_V02 = 0x06, 
  SERVICE_TYPE_USSD_V02 = 0x07, 
  SERVICE_TYPE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}service_type_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_SUPS_IND_REASON_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_SUPS_IND_REASON_FWD_UNCONDITIONAL_V02 = 0x01, /**<  Unconditional call forwarding \n  */
  VOICE_SUPS_IND_REASON_FWD_MOBILEBUSY_V02 = 0x02, /**<  Forward when the mobile is busy \n  */
  VOICE_SUPS_IND_REASON_FWD_NOREPLY_V02 = 0x03, /**<  Forward when there is no reply \n  */
  VOICE_SUPS_IND_REASON_FWD_UNREACHABLE_V02 = 0x04, /**<  Forward when the call is unreachable \n  */
  VOICE_SUPS_IND_REASON_FWD_ALLFORWARDING_V02 = 0x05, /**<  All forwarding \n  */
  VOICE_SUPS_IND_REASON_FWD_ALLCONDITIONAL_V02 = 0x06, /**<  All conditional forwarding \n  */
  VOICE_SUPS_IND_REASON_BARR_ALLOUTGOING_V02 = 0x07, /**<  All outgoing \n  */
  VOICE_SUPS_IND_REASON_BARR_OUTGOINGINT_V02 = 0x08, /**<  Outgoing internal \n  */
  VOICE_SUPS_IND_REASON_BARR_OUTGOINGINTEXTOHOME_V02 = 0x09, /**<  Outgoing external to home \n  */
  VOICE_SUPS_IND_REASON_BARR_ALLINCOMING_V02 = 0x0A, /**<  All incoming \n  */
  VOICE_SUPS_IND_REASON_BARR_INCOMINGROAMING_V02 = 0x0B, /**<  Roaming incoming \n  */
  VOICE_SUPS_IND_REASON_BARR_ALLBARRING_V02 = 0x0C, /**<  All calls are barred \n  */
  VOICE_SUPS_IND_REASON_BARR_ALLOUTGOINGBARRING_V02 = 0x0D, /**<  All outgoing calls are barred \n  */
  VOICE_SUPS_IND_REASON_BARR_ALLINCOMINGBARRING_V02 = 0x0E, /**<  All incoming calls are barred \n  */
  VOICE_SUPS_IND_REASON_CALLWAITING_V02 = 0x0F, /**<  Call waiting \n  */
  VOICE_SUPS_IND_REASON_CLIP_V02 = 0x10, /**<  Calling line identification presentation \n  */
  VOICE_SUPS_IND_REASON_CLIR_V02 = 0x11, /**<  Calling line identification restriction \n  */
  VOICE_SUPS_IND_REASON_COLP_V02 = 0x12, /**<  Connected line identification presentation \n  */
  VOICE_SUPS_IND_REASON_COLR_V02 = 0x13, /**<  Connected line identification restriction \n  */
  VOICE_SUPS_IND_REASON_CNAP_V02 = 0x14, /**<  Calling name presentation \n  */
  VOICE_SUPS_IND_REASON_BARR_INCOMINGNUMBER_V02 = 0x15, /**<  Incoming calls from registered and activated numbers are barred \n  */
  VOICE_SUPS_IND_REASON_BARR_INCOMINGANONYMOUS_V02 = 0x16, /**<  All incoming anonymous calls are barred  */
  VOICE_SUPS_IND_REASON_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_sups_ind_reason_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  service_type_enum_v02 service_type;
  /**<   Service type. Values: \n
       - 0x01 -- SERVICE_TYPE_ACTIVATE -- Activate \n
       - 0x02 -- SERVICE_TYPE_DEACTIVATE -- Deactivate \n
       - 0x03 -- SERVICE_TYPE_REGISTER -- Register \n
       - 0x04 -- SERVICE_TYPE_ERASE -- Erase \n
       - 0x05 -- SERVICE_TYPE_INTERROGATE -- Interrogate \n
       - 0x06 -- SERVICE_TYPE_REGISTER_ PASSWORD -- Register password \n
       - 0x07 -- SERVICE_TYPE_USSD -- USSD
  */

  uint8_t is_modified_by_call_control;
  /**<   Indicates whether the supplementary service data is modified by
       the card (SIM/USIM) as part of the call control: \n
         - 0 -- FALSE \n
         - 1 -- TRUE
  */
}voice_supp_service_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  char new_password[4];
  /**<   New password. Password consists of 4 ASCII digits. 
       Range: 0000 to 9999.
  */

  char new_password_again[4];
  /**<   New password again. Password consists of 4 ASCII digits. 
       Range: 0000 to 9999.
  */
}voice_new_password_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_SUPS_DATA_SOURCE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_SUPS_DATA_SOURCE_MS_V02 = 0x00, 
  VOICE_SUPS_DATA_SOURCE_NETWORK_V02 = 0x01, 
  VOICE_SUPS_DATA_SOURCE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_sups_data_source_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Notifies clients about the modem-originated supplementary
             service requests and the responses received from the network 
             (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Supplementary Service Info */
  voice_supp_service_info_type_v02 supplementary_service_info;

  /* Optional */
  /*  Service Class */
  uint8_t service_class_valid;  /**< Must be set to true if service_class is being passed */
  uint8_t service_class;
  /**<   Service class is a combination (sum) of information class constants
       (information class constants are defined in 
       Table @latexonly\ref{tbl:suppServiceInfoClass}@endlatexonly).
  */

  /* Optional */
  /*  Reason */
  uint8_t reason_valid;  /**< Must be set to true if reason is being passed */
  voice_sups_ind_reason_enum_v02 reason;
  /**<   Reason. Values: \n
      - VOICE_SUPS_IND_REASON_FWD_UNCONDITIONAL (0x01) --  Unconditional call forwarding \n 
      - VOICE_SUPS_IND_REASON_FWD_MOBILEBUSY (0x02) --  Forward when the mobile is busy \n 
      - VOICE_SUPS_IND_REASON_FWD_NOREPLY (0x03) --  Forward when there is no reply \n 
      - VOICE_SUPS_IND_REASON_FWD_UNREACHABLE (0x04) --  Forward when the call is unreachable \n 
      - VOICE_SUPS_IND_REASON_FWD_ALLFORWARDING (0x05) --  All forwarding \n 
      - VOICE_SUPS_IND_REASON_FWD_ALLCONDITIONAL (0x06) --  All conditional forwarding \n 
      - VOICE_SUPS_IND_REASON_BARR_ALLOUTGOING (0x07) --  All outgoing \n 
      - VOICE_SUPS_IND_REASON_BARR_OUTGOINGINT (0x08) --  Outgoing internal \n 
      - VOICE_SUPS_IND_REASON_BARR_OUTGOINGINTEXTOHOME (0x09) --  Outgoing external to home \n 
      - VOICE_SUPS_IND_REASON_BARR_ALLINCOMING (0x0A) --  All incoming \n 
      - VOICE_SUPS_IND_REASON_BARR_INCOMINGROAMING (0x0B) --  Roaming incoming \n 
      - VOICE_SUPS_IND_REASON_BARR_ALLBARRING (0x0C) --  All calls are barred \n 
      - VOICE_SUPS_IND_REASON_BARR_ALLOUTGOINGBARRING (0x0D) --  All outgoing calls are barred \n 
      - VOICE_SUPS_IND_REASON_BARR_ALLINCOMINGBARRING (0x0E) --  All incoming calls are barred \n 
      - VOICE_SUPS_IND_REASON_CALLWAITING (0x0F) --  Call waiting \n 
      - VOICE_SUPS_IND_REASON_CLIP (0x10) --  Calling line identification presentation \n 
      - VOICE_SUPS_IND_REASON_CLIR (0x11) --  Calling line identification restriction \n 
      - VOICE_SUPS_IND_REASON_COLP (0x12) --  Connected line identification presentation \n 
      - VOICE_SUPS_IND_REASON_COLR (0x13) --  Connected line identification restriction \n 
      - VOICE_SUPS_IND_REASON_CNAP (0x14) --  Calling name presentation \n 
      - VOICE_SUPS_IND_REASON_BARR_INCOMINGNUMBER (0x15) --  Incoming calls from registered and activated numbers are barred \n 
      - VOICE_SUPS_IND_REASON_BARR_INCOMINGANONYMOUS (0x16) --  All incoming anonymous calls are barred  
 */

  /* Optional */
  /*  Call Forwarding Number */
  uint8_t number_valid;  /**< Must be set to true if number is being passed */
  char number[QMI_VOICE_NUMBER_MAX_V02 + 1];
  /**<   Call forwarding number to be registered with the network; ASCII string.*/

  /* Optional */
  /*  Call Forwarding No Reply Timer */
  uint8_t timer_value_valid;  /**< Must be set to true if timer_value is being passed */
  uint8_t timer_value;
  /**<   Timer value in seconds (range: 5 to 30 in steps of 5) per 
       \hyperref[STD-22030]{3GPP TS 22.030} Annex B.
  */

  /* Optional */
  /*  USS Information */
  uint8_t uss_info_valid;  /**< Must be set to true if uss_info is being passed */
  voice_uss_info_type_v02 uss_info;

  /* Optional */
  /*  Call ID */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Call identifier of the voice call that has been modified to a
       supplementary service as a result of call control.
  */

  /* Optional */
  /*  Alpha Identifier */
  uint8_t alpha_ident_valid;  /**< Must be set to true if alpha_ident is being passed */
  voice_alpha_ident_type_v02 alpha_ident;

  /* Optional */
  /*  Call Barring Password */
  uint8_t password_valid;  /**< Must be set to true if password is being passed */
  char password[4];
  /**<   Password is required if call barring is provisioned using a password.
       Password consists of 4 ASCII digits. Range: 0000 to 9999. This also
       serves as the old password in the register password scenario.
  */

  /* Optional */
  /*  New Password Data */
  uint8_t new_password_valid;  /**< Must be set to true if new_password is being passed */
  voice_new_password_type_v02 new_password;

  /* Optional */
  /*  Sups Data Source */
  uint8_t data_source_valid;  /**< Must be set to true if data_source is being passed */
  voice_sups_data_source_enum_v02 data_source;
  /**<   Used to distinguish between the supplementary service data sent to the 
       network and the response received from the network. In the absence of 
       this TLV, the supplementary service data in this indication can be 
       assumed as a request sent to the network.
  */

  /* Optional */
  /*  Failure Cause  */
  uint8_t failure_cause_valid;  /**< Must be set to true if failure_cause is being passed */
  qmi_sups_errors_enum_v02 failure_cause;
  /**<   Supplementary services failure cause; 
       see @latexonly Table~\ref{tbl:endReasons}@endlatexonly for more information.
  */

  /* Optional */
  /*  Call Forwarding Data from Network */
  uint8_t call_forwarding_info_valid;  /**< Must be set to true if call_forwarding_info is being passed */
  uint32_t call_forwarding_info_len;  /**< Must be set to # of elements in call_forwarding_info */
  voice_get_call_forwarding_info_type_v02 call_forwarding_info[GET_CALL_FORWARDING_INFO_MAX_V02];

  /* Optional */
  /*  CLIR Status from Network */
  uint8_t clir_status_valid;  /**< Must be set to true if clir_status is being passed */
  voice_clir_response_type_v02 clir_status;

  /* Optional */
  /*  CLIP Status from Network */
  uint8_t clip_status_valid;  /**< Must be set to true if clip_status is being passed */
  voice_clip_response_type_v02 clip_status;

  /* Optional */
  /*  COLP Status from Network */
  uint8_t colp_status_valid;  /**< Must be set to true if colp_status is being passed */
  voice_ss_status_type_v02 colp_status;

  /* Optional */
  /*  COLR Status from Network */
  uint8_t colr_status_valid;  /**< Must be set to true if colr_status is being passed */
  voice_ss_status_type_v02 colr_status;

  /* Optional */
  /*  CNAP Status from Network */
  uint8_t cnap_status_valid;  /**< Must be set to true if cnap_status is being passed */
  voice_ss_status_type_v02 cnap_status;

  /* Optional */
  /*  USS Data from Network in UTF-16 Encoding */
  uint8_t uss_info_utf16_valid;  /**< Must be set to true if uss_info_utf16 is being passed */
  uint32_t uss_info_utf16_len;  /**< Must be set to # of elements in uss_info_utf16 */
  uint16_t uss_info_utf16[QMI_VOICE_USS_DATA_MAX_V02];
  /**<   Unstructured supplementary service information in UTF-16 encoding. 
  */

  /* Optional */
  /*  Extended Service Class */
  uint8_t service_class_ext_valid;  /**< Must be set to true if service_class_ext is being passed */
  voice_service_class_enum_v02 service_class_ext;
  /**<   Extended service class; see Table @latexonly\ref{tbl:extServiceClass}@endlatexonly 
       for more information.
  */

  /* Optional */
  /*  Barred Number List */
  uint8_t barred_numbers_list_valid;  /**< Must be set to true if barred_numbers_list is being passed */
  uint32_t barred_numbers_list_len;  /**< Must be set to # of elements in barred_numbers_list */
  voice_barred_number_type_v02 barred_numbers_list[QMI_VOICE_MAX_BARRED_NUMBERS_LIST_V02];
  /**<   \n
       List of barred numbers activated/deactivated 
       or registered with/erased from the network.
  */
}voice_sups_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Initiates a USSD operation such that the response for this 
             request is returned immediately and the data is returned via an 
             indication (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  USS Information */
  voice_uss_info_type_v02 uss_info;
}voice_orig_ussd_no_wait_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Initiates a USSD operation such that the response for this 
             request is returned immediately and the data is returned via an 
             indication (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}voice_orig_ussd_no_wait_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Notifies clients about the USSD responses received from the 
             QMI_VOICE_ORIG_USSD_NO_WAIT_REQ request (applicable only for 3GPP). */
typedef struct {

  /* Optional */
  /*  Error */
  uint8_t error_valid;  /**< Must be set to true if error is being passed */
  qmi_error_type_v01 error;
  /**<   Type of error (if any).
  */

  /* Optional */
  /*  Failure Cause  */
  uint8_t failure_cause_valid;  /**< Must be set to true if failure_cause is being passed */
  qmi_sups_errors_enum_v02 failure_cause;
  /**<   Supplementary services failure cause; 
       see @latexonly Table~\ref{tbl:endReasons}@endlatexonly for more information.
  */

  /* Optional */
  /*  USS Data from Network */
  uint8_t uss_info_valid;  /**< Must be set to true if uss_info is being passed */
  voice_uss_info_type_v02 uss_info;

  /* Optional */
  /*  Alpha Identifier */
  uint8_t alpha_id_valid;  /**< Must be set to true if alpha_id is being passed */
  voice_alpha_ident_type_v02 alpha_id;

  /* Optional */
  /*  USS Data from Network in UTF-16 Encoding */
  uint8_t uss_info_utf16_valid;  /**< Must be set to true if uss_info_utf16 is being passed */
  uint32_t uss_info_utf16_len;  /**< Must be set to # of elements in uss_info_utf16 */
  uint16_t uss_info_utf16[QMI_VOICE_USS_DATA_MAX_V02];
  /**<   Unstructured supplementary service information in UTF-16 encoding. 
  */

  /* Optional */
  /*  Failure Cause Description  */
  uint8_t failure_cause_description_valid;  /**< Must be set to true if failure_cause_description is being passed */
  uint32_t failure_cause_description_len;  /**< Must be set to # of elements in failure_cause_description */
  uint16_t failure_cause_description[QMI_VOICE_FAILURE_CAUSE_DESC_MAX_LEN_V02];
  /**<   Failure cause description received from the network. This text can contain 
       up to 256 UTF-16 characters and it is not guaranteed to be NULL terminated.
       Length range: 0 to 256.
  */

  /* Optional */
  /*  SIP Error Code */
  uint8_t sip_error_code_valid;  /**< Must be set to true if sip_error_code is being passed */
  uint16_t sip_error_code;
  /**<   SIP error code for supplemental service failure.
  */
}voice_orig_ussd_no_wait_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_SUBS_TYPE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_SUBS_TYPE_PRIMARY_V02 = 0x00, 
  VOICE_SUBS_TYPE_SECONDARY_V02 = 0x01, 
  VOICE_SUBS_TYPE_TERTIARY_V02 = 0x02, 
  VOICE_SUBS_TYPE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_subs_type_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Binds a subscription type to a specific voice client ID. */
typedef struct {

  /* Mandatory */
  /*  Subscription Type */
  voice_subs_type_enum_v02 subs_type;
  /**<   Values: \n
       - 0x00 -- VOICE_SUBS_TYPE_PRIMARY -- Primary \n
       - 0x01 -- VOICE_SUBS_TYPE_SECONDARY -- Secondary \n
       - 0x02 -- VOICE_SUBS_TYPE_TERTIARY -- Tertiary
  */
}voice_bind_subscription_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Binds a subscription type to a specific voice client ID. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}voice_bind_subscription_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_LINE_SWITCHING_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_LINE_SWITCHING_NOT_ALLOWED_V02 = 0x00, 
  VOICE_LINE_SWITCHING_ALLOWED_V02 = 0x01, 
  VOICE_LINE_SWITCHING_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_line_switching_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Sets the line switch setting on the card 
             (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Voice Privacy Preference */
  voice_line_switching_enum_v02 switch_option;
  /**<   Values: \n
       - 0x00 -- VOICE_LINE_SWITCHING_NOT_ ALLOWED - Line switching is not allowed \n
       - 0x01 -- VOICE_LINE_SWITCHING_ ALLOWED - Line switching is allowed
  */
}voice_als_set_line_switching_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Sets the line switch setting on the card 
             (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}voice_als_set_line_switching_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Allows the user to select the preferred line 
             (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  ALS Line Value */
  als_enum_v02 line_value;
  /**<   ALS line. Values: \n
       - 0x00 -- ALS_LINE1 -- Line 1 (default) \n
       - 0x01 -- ALS_LINE2 -- Line 2
  */
}voice_als_select_line_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Allows the user to select the preferred line 
             (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}voice_als_select_line_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Resets the Accumulated Call Meter (ACM) value to 0
             (applicable only for 3GPP). */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}voice_aoc_reset_acm_req_msg_v02;

  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Resets the Accumulated Call Meter (ACM) value to 0
             (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}voice_aoc_reset_acm_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Sets a maximum value for ACM (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Maximum Value for Accumulated Call Meter */
  uint32_t acmmax;
  /**<   Maximum value for accumulated call meter. Range: 0 to 0xFFFFFF.
      ACMMAX value is in charging units; refer to 
      \hyperref[STD-22096]{3GPP TS 22.096} for information on charging units.
  */
}voice_aoc_set_acmmax_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Sets a maximum value for ACM (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}voice_aoc_set_acmmax_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Retrieves the ACMMAX, Current Call Meter (CCM), and ACM values
             (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Call Meter Info Mask */
  uint16_t info_mask;
  /**<   Bitmask of the following items to be fetched. Values: \n
       - Bit 0 -- QMI_VOICE_AOC_CALL_METER_ INFO_ACM_BIT -- ACM \n
       - Bit 1 -- QMI_VOICE_AOC_CALL_METER_ INFO_ACMMAX_BIT -- ACMMAX \n
       - Bit 2 -- QMI_VOICE_AOC_CALL_METER_ INFO_CCM_BIT -- CCM
  */
}voice_aoc_get_call_meter_info_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Retrieves the ACMMAX, Current Call Meter (CCM), and ACM values
             (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Accumulated Call Meter */
  uint8_t acm_valid;  /**< Must be set to true if acm is being passed */
  uint32_t acm;
  /**<   ACM value is in charging units; 
       refer to \hyperref[STD-22096]{3GPP TS 22.096} for information on 
       charging units.
  */

  /* Optional */
  /*  Maximum Accumulated Call Meter */
  uint8_t acmmax_valid;  /**< Must be set to true if acmmax is being passed */
  uint32_t acmmax;
  /**<   ACMMAX value is in charging units; 
       refer to \hyperref[STD-22096]{3GPP TS 22.096} for information on 
       charging units.
  */

  /* Optional */
  /*  Current Call Meter */
  uint8_t ccm_valid;  /**< Must be set to true if ccm is being passed */
  uint32_t ccm;
  /**<   CCM value is in charging units; 
       refer to \hyperref[STD-22096]{3GPP TS 22.096} for information on 
       charging units.
  */
}voice_aoc_get_call_meter_info_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Indicates that the phone is out of funds. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}voice_aoc_low_funds_ind_msg_v02;

  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Queries the status of the Connected Line identification 
             Presentation (COLP) supplementary service.               */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}voice_get_colp_req_msg_v02;

  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Queries the status of the Connected Line identification 
             Presentation (COLP) supplementary service.               */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  COLP Response */
  uint8_t colp_response_valid;  /**< Must be set to true if colp_response is being passed */
  voice_ss_status_type_v02 colp_response;

  /* Optional */
  /*  Failure Cause  */
  uint8_t failure_cause_valid;  /**< Must be set to true if failure_cause is being passed */
  qmi_sups_errors_enum_v02 failure_cause;
  /**<   Supplementary services failure cause; 
       see @latexonly Table~\ref{tbl:endReasons}@endlatexonly for more information.
  */

  /* Optional */
  /*  Alpha Identifier */
  uint8_t alpha_id_valid;  /**< Must be set to true if alpha_id is being passed */
  voice_alpha_ident_type_v02 alpha_id;

  /* Optional */
  /*  Call Control Result Type */
  uint8_t cc_result_type_valid;  /**< Must be set to true if cc_result_type is being passed */
  voice_cc_result_type_enum_v02 cc_result_type;
  /**<   Values: \n
      - VOICE_CC_RESULT_TYPE_VOICE (0x00) --  VOICE \n 
      - VOICE_CC_RESULT_TYPE_SUPS (0x01) --  SUPS \n 
      - VOICE_CC_RESULT_TYPE_USSD (0x02) --  USSD \n 
      - VOICE_CC_RESULT_TYPE_VT (0x03) --  VT 
 */

  /* Optional */
  /*  Call ID  */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Call ID of the voice call that resulted from call control.
  */

  /* Optional */
  /*  Call Control Supplementary Service Type */
  uint8_t cc_sups_result_valid;  /**< Must be set to true if cc_sups_result is being passed */
  voice_cc_sups_result_type_v02 cc_sups_result;

  /* Optional */
  /*  Retry Duration */
  uint8_t retry_duration_valid;  /**< Must be set to true if retry_duration is being passed */
  uint16_t retry_duration;
  /**<   Retry duration in seconds.
  */

  /* Optional */
  /*  Failure Cause Description  */
  uint8_t failure_cause_description_valid;  /**< Must be set to true if failure_cause_description is being passed */
  uint32_t failure_cause_description_len;  /**< Must be set to # of elements in failure_cause_description */
  uint16_t failure_cause_description[QMI_VOICE_FAILURE_CAUSE_DESC_MAX_LEN_V02];
  /**<   Failure cause description received from the network. This text can contain 
       up to 256 UTF-16 characters and it is not guaranteed to be NULL terminated.
       Length range: 0 to 256.
  */

  /* Optional */
  /*  SIP Error Code */
  uint8_t sip_error_code_valid;  /**< Must be set to true if sip_error_code is being passed */
  uint16_t sip_error_code;
  /**<   SIP error code for supplemental service failure.
  */
}voice_get_colp_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Queries the status of the Connected Line identification 
             Restriction (COLR) supplementary service
             (applicable only for 3GPP). */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}voice_get_colr_req_msg_v02;

  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Queries the status of the Connected Line identification 
             Restriction (COLR) supplementary service
             (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  COLR Response */
  uint8_t colr_response_valid;  /**< Must be set to true if colr_response is being passed */
  voice_ss_status_type_v02 colr_response;

  /* Optional */
  /*  Failure Cause  */
  uint8_t failure_cause_valid;  /**< Must be set to true if failure_cause is being passed */
  qmi_sups_errors_enum_v02 failure_cause;
  /**<   Supplementary services failure cause; 
       see @latexonly Table~\ref{tbl:endReasons}@endlatexonly for more information.
  */

  /* Optional */
  /*  Alpha Identifier */
  uint8_t alpha_id_valid;  /**< Must be set to true if alpha_id is being passed */
  voice_alpha_ident_type_v02 alpha_id;

  /* Optional */
  /*  Call Control Result Type */
  uint8_t cc_result_type_valid;  /**< Must be set to true if cc_result_type is being passed */
  voice_cc_result_type_enum_v02 cc_result_type;
  /**<   Values: \n
      - VOICE_CC_RESULT_TYPE_VOICE (0x00) --  VOICE \n 
      - VOICE_CC_RESULT_TYPE_SUPS (0x01) --  SUPS \n 
      - VOICE_CC_RESULT_TYPE_USSD (0x02) --  USSD \n 
      - VOICE_CC_RESULT_TYPE_VT (0x03) --  VT 
 */

  /* Optional */
  /*  Call ID  */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Call ID of the voice call that resulted from call control.
  */

  /* Optional */
  /*  Call Control Supplementary Service Type */
  uint8_t cc_sups_result_valid;  /**< Must be set to true if cc_sups_result is being passed */
  voice_cc_sups_result_type_v02 cc_sups_result;

  /* Optional */
  /*  COLR Presentation Information */
  uint8_t colr_pi_valid;  /**< Must be set to true if colr_pi is being passed */
  pi_colr_enum_v02 colr_pi;
  /**<   COLR presentation information. Values: \n
      - COLR_PRESENTATION_NOT_RESTRICTED (0x00) --  COLR presentation is not restricted 
      - COLR_PRESENTATION_RESTRICTED (0x01) --  COLR presentation is restricted  
 */

  /* Optional */
  /*  Retry Duration */
  uint8_t retry_duration_valid;  /**< Must be set to true if retry_duration is being passed */
  uint16_t retry_duration;
  /**<   Retry duration in seconds.
  */

  /* Optional */
  /*  Failure Cause Description  */
  uint8_t failure_cause_description_valid;  /**< Must be set to true if failure_cause_description is being passed */
  uint32_t failure_cause_description_len;  /**< Must be set to # of elements in failure_cause_description */
  uint16_t failure_cause_description[QMI_VOICE_FAILURE_CAUSE_DESC_MAX_LEN_V02];
  /**<   Failure cause description received from the network. This text can contain 
       up to 256 UTF-16 characters and it is not guaranteed to be NULL terminated.
       Length range: 0 to 256.
  */

  /* Optional */
  /*  SIP Error Code */
  uint8_t sip_error_code_valid;  /**< Must be set to true if sip_error_code is being passed */
  uint16_t sip_error_code;
  /**<   SIP error code for supplemental service failure.
  */
}voice_get_colr_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Queries the status of the Calling Name Presentation (CNAP) 
             supplementary service (applicable only for 3GPP). */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}voice_get_cnap_req_msg_v02;

  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Queries the status of the Calling Name Presentation (CNAP) 
             supplementary service (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  CNAP Response */
  uint8_t cnap_response_valid;  /**< Must be set to true if cnap_response is being passed */
  voice_ss_status_type_v02 cnap_response;

  /* Optional */
  /*  Failure Cause  */
  uint8_t failure_cause_valid;  /**< Must be set to true if failure_cause is being passed */
  qmi_sups_errors_enum_v02 failure_cause;
  /**<   Supplementary services failure cause; 
       see @latexonly Table~\ref{tbl:endReasons}@endlatexonly for more information.
  */

  /* Optional */
  /*  Alpha Identifier */
  uint8_t alpha_id_valid;  /**< Must be set to true if alpha_id is being passed */
  voice_alpha_ident_type_v02 alpha_id;

  /* Optional */
  /*  Call Control Result Type */
  uint8_t cc_result_type_valid;  /**< Must be set to true if cc_result_type is being passed */
  voice_cc_result_type_enum_v02 cc_result_type;
  /**<   Values: \n
      - VOICE_CC_RESULT_TYPE_VOICE (0x00) --  VOICE \n 
      - VOICE_CC_RESULT_TYPE_SUPS (0x01) --  SUPS \n 
      - VOICE_CC_RESULT_TYPE_USSD (0x02) --  USSD \n 
      - VOICE_CC_RESULT_TYPE_VT (0x03) --  VT 
 */

  /* Optional */
  /*  Call ID  */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Call ID of the voice call that resulted from call control.
  */

  /* Optional */
  /*  Call Control Supplementary Service Type */
  uint8_t cc_sups_result_valid;  /**< Must be set to true if cc_sups_result is being passed */
  voice_cc_sups_result_type_v02 cc_sups_result;

  /* Optional */
  /*  Retry Duration */
  uint8_t retry_duration_valid;  /**< Must be set to true if retry_duration is being passed */
  uint16_t retry_duration;
  /**<   Retry duration in seconds.
  */

  /* Optional */
  /*  Failure Cause Description  */
  uint8_t failure_cause_description_valid;  /**< Must be set to true if failure_cause_description is being passed */
  uint32_t failure_cause_description_len;  /**< Must be set to # of elements in failure_cause_description */
  uint16_t failure_cause_description[QMI_VOICE_FAILURE_CAUSE_DESC_MAX_LEN_V02];
  /**<   Failure cause description received from the network. This text can contain 
       up to 256 UTF-16 characters and it is not guaranteed to be NULL terminated.
       Length range: 0 to 256.
  */

  /* Optional */
  /*  SIP Error Code */
  uint8_t sip_error_code_valid;  /**< Must be set to true if sip_error_code is being passed */
  uint16_t sip_error_code;
  /**<   SIP error code for supplemental service failure.
  */
}voice_get_cnap_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_SPEECH_CODEC_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_SPEECH_CODEC_NONE_V02 = 0x0000, /**<  None \n  */
  VOICE_SPEECH_CODEC_QCELP13K_V02 = 0x0001, /**<  QCELP-13K \n  */
  VOICE_SPEECH_CODEC_EVRC_V02 = 0x0002, /**<  EVRC \n  */
  VOICE_SPEECH_CODEC_EVRC_B_V02 = 0x0003, /**<  EVRC-B \n  */
  VOICE_SPEECH_CODEC_EVRC_WB_V02 = 0x0004, /**<  EVRC wideband \n  */
  VOICE_SPEECH_CODEC_EVRC_NW_V02 = 0x0005, /**<  EVRC narrowband-wideband \n  */
  VOICE_SPEECH_CODEC_AMR_NB_V02 = 0x0006, /**<  AMR narrowband \n  */
  VOICE_SPEECH_CODEC_AMR_WB_V02 = 0x0007, /**<  AMR wideband \n  */
  VOICE_SPEECH_CODEC_GSM_EFR_V02 = 0x0008, /**<  GSM enhanced full rate \n  */
  VOICE_SPEECH_CODEC_GSM_FR_V02 = 0x0009, /**<  GSM full rate \n  */
  VOICE_SPEECH_CODEC_GSM_HR_V02 = 0x000A, /**<  GSM half rate \n  */
  VOICE_SPEECH_CODEC_G711U_V02 = 0x000B, /**<  G711U \n  */
  VOICE_SPEECH_CODEC_G723_V02 = 0x000C, /**<  G723 \n  */
  VOICE_SPEECH_CODEC_G711A_V02 = 0x000D, /**<  G711A \n  */
  VOICE_SPEECH_CODEC_G722_V02 = 0x000E, /**<  G722 \n  */
  VOICE_SPEECH_CODEC_G711AB_V02 = 0x000F, /**<  G711AB \n  */
  VOICE_SPEECH_CODEC_G729_V02 = 0x0010, /**<  G729 \n  */
  VOICE_SPEECH_CODEC_EVS_NB_V02 = 0x0011, /**<  EVS narrowband \n  */
  VOICE_SPEECH_CODEC_EVS_WB_V02 = 0x0012, /**<  EVS_WB wideband \n  */
  VOICE_SPEECH_CODEC_EVS_SWB_V02 = 0x0013, /**<  EVS super-wideband \n  */
  VOICE_SPEECH_CODEC_EVS_FB_V02 = 0x0014, /**<  EVS fullband  */
  VOICE_SPEECH_CODEC_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_speech_codec_enum_v02;
/**
    @}
  */

typedef uint64_t voice_speech_codec_mask_v02;
#define VOICE_SPEECH_CODEC_NONE_MASK_V02 ((voice_speech_codec_mask_v02)0x000001ull) /**<  None \n  */
#define VOICE_SPEECH_CODEC_QCELP13K_MASK_V02 ((voice_speech_codec_mask_v02)0x000002ull) /**<  QCELP-13K \n  */
#define VOICE_SPEECH_CODEC_EVRC_MASK_V02 ((voice_speech_codec_mask_v02)0x000004ull) /**<  EVRC \n  */
#define VOICE_SPEECH_CODEC_EVRC_B_MASK_V02 ((voice_speech_codec_mask_v02)0x000008ull) /**<  EVRC-B \n  */
#define VOICE_SPEECH_CODEC_EVRC_WB_MASK_V02 ((voice_speech_codec_mask_v02)0x000010ull) /**<  EVRC wideband \n  */
#define VOICE_SPEECH_CODEC_EVRC_NW_MASK_V02 ((voice_speech_codec_mask_v02)0x000020ull) /**<  EVRC narrowband-wideband \n  */
#define VOICE_SPEECH_CODEC_AMR_NB_MASK_V02 ((voice_speech_codec_mask_v02)0x000040ull) /**<  AMR narrowband \n  */
#define VOICE_SPEECH_CODEC_AMR_WB_MASK_V02 ((voice_speech_codec_mask_v02)0x000080ull) /**<  AMR wideband \n  */
#define VOICE_SPEECH_CODEC_GSM_EFR_MASK_V02 ((voice_speech_codec_mask_v02)0x000100ull) /**<  GSM enhanced full rate \n  */
#define VOICE_SPEECH_CODEC_GSM_FR_MASK_V02 ((voice_speech_codec_mask_v02)0x000200ull) /**<  GSM full rate \n  */
#define VOICE_SPEECH_CODEC_GSM_HR_MASK_V02 ((voice_speech_codec_mask_v02)0x000400ull) /**<  GSM half rate \n  */
#define VOICE_SPEECH_CODEC_G711U_MASK_V02 ((voice_speech_codec_mask_v02)0x000800ull) /**<  G711U \n  */
#define VOICE_SPEECH_CODEC_G723_MASK_V02 ((voice_speech_codec_mask_v02)0x001000ull) /**<  G723 \n  */
#define VOICE_SPEECH_CODEC_G711A_MASK_V02 ((voice_speech_codec_mask_v02)0x002000ull) /**<  G711A \n  */
#define VOICE_SPEECH_CODEC_G722_MASK_V02 ((voice_speech_codec_mask_v02)0x004000ull) /**<  G722 \n  */
#define VOICE_SPEECH_CODEC_G711AB_MASK_V02 ((voice_speech_codec_mask_v02)0x008000ull) /**<  G711AB \n  */
#define VOICE_SPEECH_CODEC_G729_MASK_V02 ((voice_speech_codec_mask_v02)0x010000ull) /**<  G729 \n  */
#define VOICE_SPEECH_CODEC_EVS_NB_MASK_V02 ((voice_speech_codec_mask_v02)0x020000ull) /**<  EVS narrowband \n  */
#define VOICE_SPEECH_CODEC_EVS_WB_MASK_V02 ((voice_speech_codec_mask_v02)0x040000ull) /**<  EVS_WB wideband \n  */
#define VOICE_SPEECH_CODEC_EVS_SWB_MASK_V02 ((voice_speech_codec_mask_v02)0x080000ull) /**<  EVS super-wideband \n  */
#define VOICE_SPEECH_CODEC_EVS_FB_MASK_V02 ((voice_speech_codec_mask_v02)0x100000ull) /**<  EVS fullband  */
/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOIP_SUPS_TYPE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOIP_SUPS_TYPE_RELEASE_HELD_OR_WAITING_V02 = 0x01, /**<  Release the held or waiting call \n  */
  VOIP_SUPS_TYPE_RELEASE_ACTIVE_ACCEPT_HELD_OR_WAITING_V02 = 0x02, /**<  Release the active call and accept the held or waiting call \n  */
  VOIP_SUPS_TYPE_HOLD_ACTIVE_ACCEPT_WAITING_OR_HELD_V02 = 0x03, /**<  Hold the active call and accept the waiting or held call \n  */
  VOIP_SUPS_TYPE_MAKE_CONFERENCE_CALL_V02 = 0x04, /**<  Make a conference call \n  */
  VOIP_SUPS_TYPE_END_ALL_CALLS_V02 = 0x05, /**<  End all existing calls \n  */
  VOIP_SUPS_TYPE_MODIFY_CALL_V02 = 0x06, /**<  Downgrade/upgrade of existing VT/IP calls \n  */
  VOIP_SUPS_TYPE_MODIFY_ACCEPT_V02 = 0x07, /**<  Accept the call upgrade of existing IP calls \n  */
  VOIP_SUPS_TYPE_MODIFY_REJECT_V02 = 0x08, /**<  Reject the call upgrade of existing IP calls \n  */
  VOIP_SUPS_TYPE_RELEASE_SPECIFIED_CALL_FROM_CONFERENCE_V02 = 0x09, /**<  Release a party from a conference call \n  */
  VOIP_SUPS_TYPE_ADD_PARTICIPANT_V02 = 0x0A, /**<  Add a participant to a call \n  */
  VOIP_SUPS_TYPE_CALL_DEFLECTION_V02 = 0x0B, /**<  Deflect the call \n  */
  VOIP_SUPS_TYPE_CALL_HOLD_V02 = 0x0C, /**<  Hold the call with a specific call ID \n  */
  VOIP_SUPS_TYPE_CALL_RESUME_V02 = 0x0D, /**<  Resume the call with a specific call ID \n  */
  VOIP_SUPS_TYPE_MODIFY_SPEECH_CODEC_V02 = 0x0E, /**<  Modify the speech codec with a specific call ID  */
  VOIP_SUPS_TYPE_EXPLICIT_CALL_TRANSFER_V02 = 0x0F, /**<  Transfer the call to a new UE  */
  VOIP_SUPS_TYPE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voip_sups_type_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOIP_ECT_TYPE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  ECT_TYPE_BLIND_TRANSFER_V02 = 0x0000, /**<  Blind transfer \n  */
  ECT_TYPE_ASSURED_TRANSFER_V02 = 0x0001, /**<  Assured transfer \n  */
  ECT_TYPE_CONSULTATIVE_TRANSFER_V02 = 0x0002, /**<  Consultative  */
  ECT_TYPE_CALL_PUSH_V02 = 0x0003, /**<  Call push  */
  VOIP_ECT_TYPE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voip_ect_type_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t uri_name_len;  /**< Must be set to # of elements in uri_name */
  uint16_t uri_name[QMI_VOICE_CONF_URI_MAX_LEN_V02];
  /**<   URI name, which consists of up to 128 UTF-16 characters. 
   This string is not guaranteed to be NULL terminated. 
   Length range: 0 to 128.
  */

  uint32_t uri_description_len;  /**< Must be set to # of elements in uri_description */
  uint16_t uri_description[QMI_VOICE_CONF_DISPLAY_TEXT_MAX_LEN_V02];
  /**<   URI description, which consists of up to 64 UTF-16 characters. 
   This string is not guaranteed to be NULL terminated. 
   Length range: 0 to 64.
  */
}voice_usr_uri_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Manages Voice over IP (VoIP) calls by using the supplementary 
             service applicable during the call. */
typedef struct {

  /* Mandatory */
  /*  Manage IP Calls Information */
  voip_sups_type_enum_v02 sups_type;
  /**<   Supplementary service type during the call. Values: \n
      - VOIP_SUPS_TYPE_RELEASE_HELD_OR_WAITING (0x01) --  Release the held or waiting call \n 
      - VOIP_SUPS_TYPE_RELEASE_ACTIVE_ACCEPT_HELD_OR_WAITING (0x02) --  Release the active call and accept the held or waiting call \n 
      - VOIP_SUPS_TYPE_HOLD_ACTIVE_ACCEPT_WAITING_OR_HELD (0x03) --  Hold the active call and accept the waiting or held call \n 
      - VOIP_SUPS_TYPE_MAKE_CONFERENCE_CALL (0x04) --  Make a conference call \n 
      - VOIP_SUPS_TYPE_END_ALL_CALLS (0x05) --  End all existing calls \n 
      - VOIP_SUPS_TYPE_MODIFY_CALL (0x06) --  Downgrade/upgrade of existing VT/IP calls \n 
      - VOIP_SUPS_TYPE_MODIFY_ACCEPT (0x07) --  Accept the call upgrade of existing IP calls \n 
      - VOIP_SUPS_TYPE_MODIFY_REJECT (0x08) --  Reject the call upgrade of existing IP calls \n 
      - VOIP_SUPS_TYPE_RELEASE_SPECIFIED_CALL_FROM_CONFERENCE (0x09) --  Release a party from a conference call \n 
      - VOIP_SUPS_TYPE_ADD_PARTICIPANT (0x0A) --  Add a participant to a call \n 
      - VOIP_SUPS_TYPE_CALL_DEFLECTION (0x0B) --  Deflect the call \n 
      - VOIP_SUPS_TYPE_CALL_HOLD (0x0C) --  Hold the call with a specific call ID \n 
      - VOIP_SUPS_TYPE_CALL_RESUME (0x0D) --  Resume the call with a specific call ID \n 
      - VOIP_SUPS_TYPE_MODIFY_SPEECH_CODEC (0x0E) --  Modify the speech codec with a specific call ID 
      - VOIP_SUPS_TYPE_EXPLICIT_CALL_TRANSFER (0x0F) --  Transfer the call to a new UE  
 */

  /* Optional */
  /*  Call ID  */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Call ID of the VoIP or VT call. This TLV is mandatory for 
       sups_type = HOLD or RESUME or ECT.
  */

  /* Optional */
  /*  Call Type */
  uint8_t call_type_valid;  /**< Must be set to true if call_type is being passed */
  call_type_enum_v02 call_type;
  /**<   Call type expected on completion of the request. Values: \n
       - 0x02 -- CALL_TYPE_VOICE_IP      -- Voice call over IP \n
       - 0x03 -- CALL_TYPE_VT            -- Videotelephony call over IP
       - 0x0B -- CALL_TYPE_EMERGENCY_IP  -- Emergency VoIP \n
       - 0x0D -- CALL_TYPE_EMERGENCY_VT  -- Emergency videotelephony call over IP
  */

  /* Optional */
  /*  Audio Attribute for VT or VOIP Call */
  uint8_t audio_attrib_valid;  /**< Must be set to true if audio_attrib is being passed */
  voice_call_attribute_type_mask_v02 audio_attrib;
  /**<   Bitmask of call attributes. Values: \n
       - Bit 0 (0x01) -- VOICE_CALL_ATTRIB_TX -- Transmission \n
       - Bit 1 (0x02) -- VOICE_CALL_ATTRIB_RX -- Receiving
  */

  /* Optional */
  /*  Video Attribute for VT or VOIP Call */
  uint8_t video_attrib_valid;  /**< Must be set to true if video_attrib is being passed */
  voice_call_attribute_type_mask_v02 video_attrib;
  /**<   Bitmask of call attributes. Values: \n
       - Bit 0 (0x01) -- VOICE_CALL_ATTRIB_TX -- Transmission \n
       - Bit 1 (0x02) -- VOICE_CALL_ATTRIB_RX -- Receiving
  */

  /* Optional */
  /*  SIP URI  */
  uint8_t sip_uri_valid;  /**< Must be set to true if sip_uri is being passed */
  char sip_uri[QMI_VOICE_SIP_URI_MAX_V02 + 1];
  /**<   SIP URI number in ASCII string. Length range: 1 to 128.
  */

  /* Optional */
  /*  Reject Cause */
  uint8_t reject_cause_valid;  /**< Must be set to true if reject_cause is being passed */
  voice_reject_cause_enum_v02 reject_cause;
  /**<   Cause for rejecting the call. Values: \n
      - VOICE_REJECT_CAUSE_USER_BUSY (0x01) --  User is busy \n 
      - VOICE_REJECT_CAUSE_USER_REJECT (0x02) --  User has rejected the call \n 
      - VOICE_REJECT_CAUSE_LOW_BATTERY (0x03) --  Call was rejected due to a low battery \n 
      - VOICE_REJECT_CAUSE_BLACKLISTED_CALL_ID (0x04) --  Call was rejected because the number was blacklisted \n 
      - VOICE_REJECT_CAUSE_DEAD_BATTERY (0x05) --  Call was rejected due to a dead battery 
      - VOICE_REJECT_CAUSE_UNWANTED_CALL (0x06) --  Call was rejected because the call was an unwanted robo call  
 */

  /* Optional */
  /*  SIP Reject Cause */
  uint8_t sip_reject_cause_valid;  /**< Must be set to true if sip_reject_cause is being passed */
  uint16_t sip_reject_cause;
  /**<   Cause for rejecting the incoming call.
       The SIP error code is as defined in \hyperref[RFC3261]{RFC3261}.
  */

  /* Optional */
  /*  Speech Codec Type (Deprecated: Use speech_codec_mask in place of this but not both) */
  uint8_t speech_codec_valid;  /**< Must be set to true if speech_codec is being passed */
  voice_speech_codec_enum_v02 speech_codec;
  /**<   Speech codec type. Values: \n
      - VOICE_SPEECH_CODEC_NONE (0x0000) --  None \n 
      - VOICE_SPEECH_CODEC_QCELP13K (0x0001) --  QCELP-13K \n 
      - VOICE_SPEECH_CODEC_EVRC (0x0002) --  EVRC \n 
      - VOICE_SPEECH_CODEC_EVRC_B (0x0003) --  EVRC-B \n 
      - VOICE_SPEECH_CODEC_EVRC_WB (0x0004) --  EVRC wideband \n 
      - VOICE_SPEECH_CODEC_EVRC_NW (0x0005) --  EVRC narrowband-wideband \n 
      - VOICE_SPEECH_CODEC_AMR_NB (0x0006) --  AMR narrowband \n 
      - VOICE_SPEECH_CODEC_AMR_WB (0x0007) --  AMR wideband \n 
      - VOICE_SPEECH_CODEC_GSM_EFR (0x0008) --  GSM enhanced full rate \n 
      - VOICE_SPEECH_CODEC_GSM_FR (0x0009) --  GSM full rate \n 
      - VOICE_SPEECH_CODEC_GSM_HR (0x000A) --  GSM half rate \n 
      - VOICE_SPEECH_CODEC_G711U (0x000B) --  G711U \n 
      - VOICE_SPEECH_CODEC_G723 (0x000C) --  G723 \n 
      - VOICE_SPEECH_CODEC_G711A (0x000D) --  G711A \n 
      - VOICE_SPEECH_CODEC_G722 (0x000E) --  G722 \n 
      - VOICE_SPEECH_CODEC_G711AB (0x000F) --  G711AB \n 
      - VOICE_SPEECH_CODEC_G729 (0x0010) --  G729 \n 
      - VOICE_SPEECH_CODEC_EVS_NB (0x0011) --  EVS narrowband \n 
      - VOICE_SPEECH_CODEC_EVS_WB (0x0012) --  EVS_WB wideband \n 
      - VOICE_SPEECH_CODEC_EVS_SWB (0x0013) --  EVS super-wideband \n 
      - VOICE_SPEECH_CODEC_EVS_FB (0x0014) --  EVS fullband 
 */

  /* Optional */
  /*  ECT Type */
  uint8_t ect_type_valid;  /**< Must be set to true if ect_type is being passed */
  voip_ect_type_enum_v02 ect_type;
  /**<   ECT type. Values: \n
      - ECT_TYPE_BLIND_TRANSFER (0x0000) --  Blind transfer \n 
      - ECT_TYPE_ASSURED_TRANSFER (0x0001) --  Assured transfer \n 
      - ECT_TYPE_CONSULTATIVE_TRANSFER (0x0002) --  Consultative 
      - ECT_TYPE_CALL_PUSH (0x0003) --  Call push 
 */

  /* Optional */
  /*  ECT Consultative Call ID */
  uint8_t transfer_target_call_id_valid;  /**< Must be set to true if transfer_target_call_id is being passed */
  uint8_t transfer_target_call_id;
  /**<   ECT consultative call ID.
       This is used only for a consultative transfer.
  */

  /* Optional */
  /*  RTT Attribute for VT or VOIP Call */
  uint8_t rtt_mode_valid;  /**< Must be set to true if rtt_mode is being passed */
  rtt_mode_type_v02 rtt_mode;
  /**<   Whether the current call is an RTT call. Values: \n
      - RTT_MODE_DISABLED (0) --  non-RTT call \n 
      - RTT_MODE_FULL (1) --  RTT call with RTT being used from both sides 
 */

  /* Optional */
  /*  Flag for Upgrading VoLTE Calls to Secure */
  uint8_t is_secure_call_valid;  /**< Must be set to true if is_secure_call is being passed */
  uint8_t is_secure_call;
  /**<   TRUE - Requests that the call be upgraded to a secure call \n
       FALSE - Requests a nonsecure call
  */

  /* Optional */
  /*  Speech Codec Mask Type  */
  uint8_t speech_codec_mask_valid;  /**< Must be set to true if speech_codec_mask is being passed */
  voice_speech_codec_mask_v02 speech_codec_mask;
  /**<   Speech codec Mask consisting of all speech codec values in request.
 Only one of speech_codec and speech_codec_mask TLVs should be used.
 If both are included, error is thrown.
 Values: \n
      - VOICE_SPEECH_CODEC_NONE_MASK (0x000001) --  None \n 
      - VOICE_SPEECH_CODEC_QCELP13K_MASK (0x000002) --  QCELP-13K \n 
      - VOICE_SPEECH_CODEC_EVRC_MASK (0x000004) --  EVRC \n 
      - VOICE_SPEECH_CODEC_EVRC_B_MASK (0x000008) --  EVRC-B \n 
      - VOICE_SPEECH_CODEC_EVRC_WB_MASK (0x000010) --  EVRC wideband \n 
      - VOICE_SPEECH_CODEC_EVRC_NW_MASK (0x000020) --  EVRC narrowband-wideband \n 
      - VOICE_SPEECH_CODEC_AMR_NB_MASK (0x000040) --  AMR narrowband \n 
      - VOICE_SPEECH_CODEC_AMR_WB_MASK (0x000080) --  AMR wideband \n 
      - VOICE_SPEECH_CODEC_GSM_EFR_MASK (0x000100) --  GSM enhanced full rate \n 
      - VOICE_SPEECH_CODEC_GSM_FR_MASK (0x000200) --  GSM full rate \n 
      - VOICE_SPEECH_CODEC_GSM_HR_MASK (0x000400) --  GSM half rate \n 
      - VOICE_SPEECH_CODEC_G711U_MASK (0x000800) --  G711U \n 
      - VOICE_SPEECH_CODEC_G723_MASK (0x001000) --  G723 \n 
      - VOICE_SPEECH_CODEC_G711A_MASK (0x002000) --  G711A \n 
      - VOICE_SPEECH_CODEC_G722_MASK (0x004000) --  G722 \n 
      - VOICE_SPEECH_CODEC_G711AB_MASK (0x008000) --  G711AB \n 
      - VOICE_SPEECH_CODEC_G729_MASK (0x010000) --  G729 \n 
      - VOICE_SPEECH_CODEC_EVS_NB_MASK (0x020000) --  EVS narrowband \n 
      - VOICE_SPEECH_CODEC_EVS_WB_MASK (0x040000) --  EVS_WB wideband \n 
      - VOICE_SPEECH_CODEC_EVS_SWB_MASK (0x080000) --  EVS super-wideband \n 
      - VOICE_SPEECH_CODEC_EVS_FB_MASK (0x100000) --  EVS fullband 
 */

  /* Optional */
  /*  Priority Speech Codec Type */
  uint8_t priority_speech_codec_valid;  /**< Must be set to true if priority_speech_codec is being passed */
  voice_speech_codec_enum_v02 priority_speech_codec;
  /**<   Specifies most priority speech codec. If not given
 1.And speech_codec is present , it is highest priority
 2.if speech_codec_mask is present, least significant bit set is highest priority.
 Values: \n
      - VOICE_SPEECH_CODEC_NONE (0x0000) --  None \n 
      - VOICE_SPEECH_CODEC_QCELP13K (0x0001) --  QCELP-13K \n 
      - VOICE_SPEECH_CODEC_EVRC (0x0002) --  EVRC \n 
      - VOICE_SPEECH_CODEC_EVRC_B (0x0003) --  EVRC-B \n 
      - VOICE_SPEECH_CODEC_EVRC_WB (0x0004) --  EVRC wideband \n 
      - VOICE_SPEECH_CODEC_EVRC_NW (0x0005) --  EVRC narrowband-wideband \n 
      - VOICE_SPEECH_CODEC_AMR_NB (0x0006) --  AMR narrowband \n 
      - VOICE_SPEECH_CODEC_AMR_WB (0x0007) --  AMR wideband \n 
      - VOICE_SPEECH_CODEC_GSM_EFR (0x0008) --  GSM enhanced full rate \n 
      - VOICE_SPEECH_CODEC_GSM_FR (0x0009) --  GSM full rate \n 
      - VOICE_SPEECH_CODEC_GSM_HR (0x000A) --  GSM half rate \n 
      - VOICE_SPEECH_CODEC_G711U (0x000B) --  G711U \n 
      - VOICE_SPEECH_CODEC_G723 (0x000C) --  G723 \n 
      - VOICE_SPEECH_CODEC_G711A (0x000D) --  G711A \n 
      - VOICE_SPEECH_CODEC_G722 (0x000E) --  G722 \n 
      - VOICE_SPEECH_CODEC_G711AB (0x000F) --  G711AB \n 
      - VOICE_SPEECH_CODEC_G729 (0x0010) --  G729 \n 
      - VOICE_SPEECH_CODEC_EVS_NB (0x0011) --  EVS narrowband \n 
      - VOICE_SPEECH_CODEC_EVS_WB (0x0012) --  EVS_WB wideband \n 
      - VOICE_SPEECH_CODEC_EVS_SWB (0x0013) --  EVS super-wideband \n 
      - VOICE_SPEECH_CODEC_EVS_FB (0x0014) --  EVS fullband 
 */
}voice_manage_ip_calls_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Manages Voice over IP (VoIP) calls by using the supplementary 
             service applicable during the call. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Call ID */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Applicable for a conference call request (sups_type 0x04).
  */

  /* Optional */
  /*  Failure Cause  */
  uint8_t failure_cause_valid;  /**< Must be set to true if failure_cause is being passed */
  qmi_sups_errors_enum_v02 failure_cause;
  /**<   Supplementary services failure cause; 
       see @latexonly Table~\ref{tbl:endReasons}@endlatexonly for more information.
  */

  /* Optional */
  /*  Number of Participants  */
  uint8_t num_participants_valid;  /**< Must be set to true if num_participants is being passed */
  uint8_t num_participants;
  /**<   Number of participants in the conference call.
  */

  /* Optional */
  /*  Call Modified Cause */
  uint8_t call_modified_cause_valid;  /**< Must be set to true if call_modified_cause is being passed */
  voice_call_modified_cause_enum_v02 call_modified_cause;
  /**<   Call modified cause. Values: \n
      - VOICE_CALL_MODIFIED_CAUSE_NONE (0x00) --  No call modify cause information \n 
      - VOICE_CALL_MODIFIED_CAUSE_UPGRADE_DUE_TO_LOCAL_REQ (0x01) --  Upgrade due to a local request \n 
      - VOICE_CALL_MODIFIED_CAUSE_UPGRADE_DUE_TO_REMOTE_REQ (0x02) --  Upgrade due to a remote request \n 
      - VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_LOCAL_REQ (0x03) --  Downgrade due to a local request \n 
      - VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_REMOTE_REQ (0x04) --  Downgrade due to a remote request \n 
      - VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_RTP_TIMEOUT (0x05) --  Downgrade due to an RTP timeout \n 
      - VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_QOS (0x06) --  Downgrade due to QOS \n 
      - VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_PACKET_LOSS (0x07) --  Downgrade due to a packet loss \n 
      - VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_LOW_THRPUT (0x08) --  Downgrade due to low throughput \n 
      - VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_THERM_MITIGATION (0x09) --  Downgrade due to thermal mitigation \n 
      - VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_GENERIC_ERROR (0x0A) --  Downgrade due to a general error \n 
      - VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_LIPSYNC (0x0B) --  Downgrade due to lipsync 
 */

  /* Optional */
  /*  End Reason Text for IP Call */
  uint8_t end_reason_text_valid;  /**< Must be set to true if end_reason_text is being passed */
  uint32_t end_reason_text_len;  /**< Must be set to # of elements in end_reason_text */
  voice_ip_end_reason_text_type_v02 end_reason_text[QMI_VOICE_IP_END_REASON_TEXT_ARRAY_MAX_V02];

  /* Optional */
  /*  SIP Error Code for IP Call */
  uint8_t sip_error_code_valid;  /**< Must be set to true if sip_error_code is being passed */
  uint16_t sip_error_code;
}voice_manage_ip_calls_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Retrieves the line switch setting on the card 
             (applicable only for 3GPP). */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}voice_als_get_line_switching_status_req_msg_v02;

  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Retrieves the line switch setting on the card 
             (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Switch Value */
  uint8_t switch_value_valid;  /**< Must be set to true if switch_value is being passed */
  voice_line_switching_enum_v02 switch_value;
  /**<   Values: \n
       - 0x00 -- VOICE_LINE_SWITCHING_ NOT_ALLOWED -- Line switching is not allowed \n
       - 0x01 -- VOICE_LINE_SWITCHING_ ALLOWED -- Line switching is allowed       
  */
}voice_als_get_line_switching_status_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Allows the user to get the line preference 
             (applicable only for 3GPP). */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}voice_als_get_selected_line_req_msg_v02;

  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Allows the user to get the line preference 
             (applicable only for 3GPP). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  ALS Line Value */
  uint8_t line_value_valid;  /**< Must be set to true if line_value is being passed */
  als_enum_v02 line_value;
  /**<   ALS line. Values: \n
       - 0x00 -- ALS_LINE1 -- Line 1 (default) \n
       - 0x01 -- ALS_LINE2 -- Line 2
  */
}voice_als_get_selected_line_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Notifies clients that a VoIP or VT call was upgraded/downgraded. */
typedef struct {

  /* Mandatory */
  /*  Call ID */
  uint8_t call_id;
  /**<   Call ID of the modified call.
  */

  /* Optional */
  /*  Call Type */
  uint8_t call_type_valid;  /**< Must be set to true if call_type is being passed */
  call_type_enum_v02 call_type;
  /**<   Call type. Values: \n
       - 0x02 -- CALL_TYPE_VOICE_IP      -- Voice call over IP \n
       - 0x03 -- CALL_TYPE_VT            -- Videotelephony call over IP \n
       - 0x0B -- CALL_TYPE_EMERGENCY_IP  -- Emergency VoIP \n
       - 0x0D -- CALL_TYPE_EMERGENCY_VT  -- Emergency Videotelephony call over IP
  */

  /* Optional */
  /*  Audio Attribute for VT or VOIP Call */
  uint8_t audio_attrib_valid;  /**< Must be set to true if audio_attrib is being passed */
  voice_call_attribute_type_mask_v02 audio_attrib;
  /**<   Bitmask of call attributes. Values: \n
       - Bit 0 (0x01) -- VOICE_CALL_ATTRIB_TX -- Transmission \n
       - Bit 1 (0x02) -- VOICE_CALL_ATTRIB_RX -- Receiving
  */

  /* Optional */
  /*  Video Attribute for VT or VOIP Call */
  uint8_t video_attrib_valid;  /**< Must be set to true if video_attrib is being passed */
  voice_call_attribute_type_mask_v02 video_attrib;
  /**<   Bitmask of call attributes. Values: \n
       - Bit 0 (0x01) -- VOICE_CALL_ATTRIB_TX -- Transmission \n
       - Bit 1 (0x02) -- VOICE_CALL_ATTRIB_RX -- Receiving
  */

  /* Optional */
  /*  Failure Cause */
  uint8_t failure_cause_valid;  /**< Must be set to true if failure_cause is being passed */
  qmi_sups_errors_enum_v02 failure_cause;
  /**<   Call modification failure cause; 
       see @latexonly Table~\ref{tbl:endReasons}@endlatexonly for more information. 
  */

  /* Optional */
  /*  Media ID  */
  uint8_t media_id_valid;  /**< Must be set to true if media_id is being passed */
  uint8_t media_id;
  /**<   Media ID. 
  */

  /* Optional */
  /*  Call Attribute Status */
  uint8_t call_attrib_status_valid;  /**< Must be set to true if call_attrib_status is being passed */
  voice_call_attrib_status_enum_v02 call_attrib_status;
  /**<   Call attribute status. Values: \n
      - VOICE_CALL_ATTRIB_STATUS_OK (0) --  No additional information \n 
      - VOICE_CALL_ATTRIB_STATUS_RETRY_NEEDED (1) --  Retry for the media is needed \n 
      - VOICE_CALL_ATTRIB_STATUS_MEDIA_PAUSED (2) --  Media is paused \n 
      - VOICE_CALL_ATTRIB_STATUS_MEDIA_NOT_READY (3) --  Media is not ready due to the quality of service 
 */

  /* Optional */
  /*  Call Modified Cause */
  uint8_t call_modified_cause_valid;  /**< Must be set to true if call_modified_cause is being passed */
  voice_call_modified_cause_enum_v02 call_modified_cause;
  /**<   Call modified cause. Values: \n
      - VOICE_CALL_MODIFIED_CAUSE_NONE (0x00) --  No call modify cause information \n 
      - VOICE_CALL_MODIFIED_CAUSE_UPGRADE_DUE_TO_LOCAL_REQ (0x01) --  Upgrade due to a local request \n 
      - VOICE_CALL_MODIFIED_CAUSE_UPGRADE_DUE_TO_REMOTE_REQ (0x02) --  Upgrade due to a remote request \n 
      - VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_LOCAL_REQ (0x03) --  Downgrade due to a local request \n 
      - VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_REMOTE_REQ (0x04) --  Downgrade due to a remote request \n 
      - VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_RTP_TIMEOUT (0x05) --  Downgrade due to an RTP timeout \n 
      - VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_QOS (0x06) --  Downgrade due to QOS \n 
      - VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_PACKET_LOSS (0x07) --  Downgrade due to a packet loss \n 
      - VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_LOW_THRPUT (0x08) --  Downgrade due to low throughput \n 
      - VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_THERM_MITIGATION (0x09) --  Downgrade due to thermal mitigation \n 
      - VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_GENERIC_ERROR (0x0A) --  Downgrade due to a general error \n 
      - VOICE_CALL_MODIFIED_CAUSE_DOWNGRADE_DUE_TO_LIPSYNC (0x0B) --  Downgrade due to lipsync 
 */

  /* Optional */
  /*  Local Call Capabilities Information */
  uint8_t local_call_capabilities_valid;  /**< Must be set to true if local_call_capabilities is being passed */
  voice_ip_call_capabilities_type_v02 local_call_capabilities;

  /* Optional */
  /*  Peer Call Capabilities Information */
  uint8_t peer_call_capabilities_valid;  /**< Must be set to true if peer_call_capabilities is being passed */
  voice_ip_call_capabilities_type_v02 peer_call_capabilities;

  /* Optional */
  /*  RTT Attribute for VT or VOIP Call */
  uint8_t rtt_mode_valid;  /**< Must be set to true if rtt_mode is being passed */
  rtt_mode_type_v02 rtt_mode;
  /**<   Whether the current call is an RTT call. Values: \n
      - RTT_MODE_DISABLED (0) --  non-RTT call \n 
      - RTT_MODE_FULL (1) --  RTT call with RTT being used from both sides 
 */

  /* Optional */
  /*  Local and Peer RTT Capabilities Information */
  uint8_t rtt_capabilities_valid;  /**< Must be set to true if rtt_capabilities is being passed */
  voice_call_rtt_capabilities_type_v02 rtt_capabilities;

  /* Optional */
  /*  Is Secure Call  */
  uint8_t is_secure_call_valid;  /**< Must be set to true if is_secure_call is being passed */
  uint8_t is_secure_call;
  /**<   Whether the current call is a secure call.
  */
}voice_modified_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Notifies clients that an upgrade of a call was triggered from 
             a remote party. */
typedef struct {

  /* Mandatory */
  /*  Call ID */
  uint8_t call_id;
  /**<   Call ID for which upgrade was requested.
  */

  /* Optional */
  /*  Call Type */
  uint8_t call_type_valid;  /**< Must be set to true if call_type is being passed */
  call_type_enum_v02 call_type;
  /**<   Call type. Values: \n
       - 0x02 -- CALL_TYPE_VOICE_IP      -- Voice call over IP \n
       - 0x03 -- CALL_TYPE_VT            -- Videotelephony call over IP \n
       - 0x0B -- CALL_TYPE_EMERGENCY_IP  -- Emergency VoIP \n
       - 0x0D -- CALL_TYPE_EMERGENCY_VT  -- Emergency videotelephony call over IP
  */

  /* Optional */
  /*  Audio Attribute of a Call */
  uint8_t audio_attrib_valid;  /**< Must be set to true if audio_attrib is being passed */
  voice_call_attribute_type_mask_v02 audio_attrib;
  /**<   Bitmask of call attributes. Values: \n
       - Bit 0 (0x01) -- VOICE_CALL_ATTRIB_TX -- Transmission \n
       - Bit 1 (0x02) -- VOICE_CALL_ATTRIB_RX -- Receiving
  */

  /* Optional */
  /*  Video Attribute of a Call */
  uint8_t video_attrib_valid;  /**< Must be set to true if video_attrib is being passed */
  voice_call_attribute_type_mask_v02 video_attrib;
  /**<   Bitmask of call attributes. Values: \n
       - Bit 0 (0x01) -- VOICE_CALL_ATTRIB_TX -- Transmission \n
       - Bit 1 (0x02) -- VOICE_CALL_ATTRIB_RX -- Receiving
  */

  /* Optional */
  /*  RTT Attribute for VT or VOIP Call */
  uint8_t rtt_mode_valid;  /**< Must be set to true if rtt_mode is being passed */
  rtt_mode_type_v02 rtt_mode;
  /**<   Whether the current call is an RTT call. Values: \n
      - RTT_MODE_DISABLED (0) --  non-RTT call \n 
      - RTT_MODE_FULL (1) --  RTT call with RTT being used from both sides 
 */

  /* Optional */
  /*  Is Secure Call */
  uint8_t is_secure_call_valid;  /**< Must be set to true if is_secure_call is being passed */
  uint8_t is_secure_call;
  /**<   Whether the current call is a secure call. 
  */
}voice_modify_accept_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_NETWORK_MODE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_NETWORK_MODE_NONE_V02 = 0x00, /**<  None \n  */
  VOICE_NETWORK_MODE_GSM_V02 = 0x01, /**<  GSM \n  */
  VOICE_NETWORK_MODE_WCDMA_V02 = 0x02, /**<  WCDMA \n  */
  VOICE_NETWORK_MODE_CDMA_V02 = 0x03, /**<  CDMA \n  */
  VOICE_NETWORK_MODE_LTE_V02 = 0x04, /**<  LTE \n  */
  VOICE_NETWORK_MODE_TDSCDMA_V02 = 0x05, /**<  TDSCDMA \n  */
  VOICE_NETWORK_MODE_WLAN_V02 = 0x06, /**<  WLAN \n  */
  VOICE_NETWORK_MODE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_network_mode_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Notifies clients about speech codec information. */
typedef struct {

  /* Optional */
  /*  Network Mode */
  uint8_t network_mode_valid;  /**< Must be set to true if network_mode is being passed */
  voice_network_mode_enum_v02 network_mode;
  /**<   Network mode. Values: \n
      - VOICE_NETWORK_MODE_NONE (0x00) --  None \n 
      - VOICE_NETWORK_MODE_GSM (0x01) --  GSM \n 
      - VOICE_NETWORK_MODE_WCDMA (0x02) --  WCDMA \n 
      - VOICE_NETWORK_MODE_CDMA (0x03) --  CDMA \n 
      - VOICE_NETWORK_MODE_LTE (0x04) --  LTE \n 
      - VOICE_NETWORK_MODE_TDSCDMA (0x05) --  TDSCDMA \n 
      - VOICE_NETWORK_MODE_WLAN (0x06) --  WLAN \n 
 */

  /* Optional */
  /*  Speech Codec Type */
  uint8_t speech_codec_valid;  /**< Must be set to true if speech_codec is being passed */
  voice_speech_codec_enum_v02 speech_codec;
  /**<   Speech codec type. Values: \n
      - VOICE_SPEECH_CODEC_NONE (0x0000) --  None \n 
      - VOICE_SPEECH_CODEC_QCELP13K (0x0001) --  QCELP-13K \n 
      - VOICE_SPEECH_CODEC_EVRC (0x0002) --  EVRC \n 
      - VOICE_SPEECH_CODEC_EVRC_B (0x0003) --  EVRC-B \n 
      - VOICE_SPEECH_CODEC_EVRC_WB (0x0004) --  EVRC wideband \n 
      - VOICE_SPEECH_CODEC_EVRC_NW (0x0005) --  EVRC narrowband-wideband \n 
      - VOICE_SPEECH_CODEC_AMR_NB (0x0006) --  AMR narrowband \n 
      - VOICE_SPEECH_CODEC_AMR_WB (0x0007) --  AMR wideband \n 
      - VOICE_SPEECH_CODEC_GSM_EFR (0x0008) --  GSM enhanced full rate \n 
      - VOICE_SPEECH_CODEC_GSM_FR (0x0009) --  GSM full rate \n 
      - VOICE_SPEECH_CODEC_GSM_HR (0x000A) --  GSM half rate \n 
      - VOICE_SPEECH_CODEC_G711U (0x000B) --  G711U \n 
      - VOICE_SPEECH_CODEC_G723 (0x000C) --  G723 \n 
      - VOICE_SPEECH_CODEC_G711A (0x000D) --  G711A \n 
      - VOICE_SPEECH_CODEC_G722 (0x000E) --  G722 \n 
      - VOICE_SPEECH_CODEC_G711AB (0x000F) --  G711AB \n 
      - VOICE_SPEECH_CODEC_G729 (0x0010) --  G729 \n 
      - VOICE_SPEECH_CODEC_EVS_NB (0x0011) --  EVS narrowband \n 
      - VOICE_SPEECH_CODEC_EVS_WB (0x0012) --  EVS_WB wideband \n 
      - VOICE_SPEECH_CODEC_EVS_SWB (0x0013) --  EVS super-wideband \n 
      - VOICE_SPEECH_CODEC_EVS_FB (0x0014) --  EVS fullband 
 */

  /* Optional */
  /*  Speech Encoder Sampling Rate */
  uint8_t speech_enc_samp_freq_valid;  /**< Must be set to true if speech_enc_samp_freq is being passed */
  uint32_t speech_enc_samp_freq;
  /**<   Speech encoder sampling rate instructed by the network in Hz.
  */

  /* Optional */
  /*  Call ID  */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Call ID of the call for which the speech codec information is sent.
  */
}voice_speech_codec_info_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_HANDOVER_STATE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_HANDOVER_START_V02 = 0x01, /**<  Start \n  */
  VOICE_HANDOVER_FAIL_V02 = 0x02, /**<  Fail \n  */
  VOICE_HANDOVER_COMPLETE_V02 = 0x03, /**<  Complete \n  */
  VOICE_HANDOVER_CANCEL_V02 = 0x04, /**<  Cancel  */
  VOICE_HANDOVER_STATE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_handover_state_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_HANDOVER_TYPE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_HO_G_2_G_V02 = 0x01, /**<  Handover from GSM to GSM \n  */
  VOICE_HO_G_2_W_V02 = 0x02, /**<  Handover from GSM to WCDMA \n  */
  VOICE_HO_W_2_W_V02 = 0x03, /**<  Handover from WCDMA to WCDMA \n  */
  VOICE_HO_W_2_G_V02 = 0x04, /**<  Handover from WCDMA to GSM \n  */
  VOICE_HO_SRVCC_L_2_G_V02 = 0x05, /**<  Handover from LTE to GSM due to SRVCC \n  */
  VOICE_HO_SRVCC_L_2_W_V02 = 0x06, /**<  Handover from LTE to WCDMA due to SRVCC \n  */
  VOICE_HO_DRVCC_WIFI_2_C_V02 = 0x07, /**<  Handover from Wi-Fi\reg to CDMA, either native 1X or 1XCSFB, due to 
        Dual Receiver Voice Call Continuity (DRVCC) \n  */
  VOICE_HO_DRVCC_WIFI_2_GW_V02 = 0x08, /**<  Handover from Wi-Fi to G/W, either native G/W or PPCSFB, due to DRVCC  */
  VOICE_HANDOVER_TYPE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_handover_type_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Notifies clients about handover information. */
typedef struct {

  /* Mandatory */
  /*  Handover State */
  voice_handover_state_enum_v02 ho_state;
  /**<   Handover state. Values: \n
      - VOICE_HANDOVER_START (0x01) --  Start \n 
      - VOICE_HANDOVER_FAIL (0x02) --  Fail \n 
      - VOICE_HANDOVER_COMPLETE (0x03) --  Complete \n 
      - VOICE_HANDOVER_CANCEL (0x04) --  Cancel 
 */

  /* Optional */
  /*  Handover Type */
  uint8_t ho_type_valid;  /**< Must be set to true if ho_type is being passed */
  voice_handover_type_enum_v02 ho_type;
  /**<   Handover type. Values: \n
      - VOICE_HO_G_2_G (0x01) --  Handover from GSM to GSM \n 
      - VOICE_HO_G_2_W (0x02) --  Handover from GSM to WCDMA \n 
      - VOICE_HO_W_2_W (0x03) --  Handover from WCDMA to WCDMA \n 
      - VOICE_HO_W_2_G (0x04) --  Handover from WCDMA to GSM \n 
      - VOICE_HO_SRVCC_L_2_G (0x05) --  Handover from LTE to GSM due to SRVCC \n 
      - VOICE_HO_SRVCC_L_2_W (0x06) --  Handover from LTE to WCDMA due to SRVCC \n 
      - VOICE_HO_DRVCC_WIFI_2_C (0x07) --  Handover from Wi-Fi\reg to CDMA, either native 1X or 1XCSFB, due to 
        Dual Receiver Voice Call Continuity (DRVCC) \n 
      - VOICE_HO_DRVCC_WIFI_2_GW (0x08) --  Handover from Wi-Fi to G/W, either native G/W or PPCSFB, due to DRVCC 
 */
}voice_handover_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Notifies clients about conference information. */
typedef struct {

  /* Mandatory */
  /*  Conference XML */
  uint32_t conference_xml_len;  /**< Must be set to # of elements in conference_xml */
  uint8_t conference_xml[QMI_VOICE_CONF_XML_MAX_LEN_V02];
  /**<   Conference XML is a part of an XML file that is passed as a UTF-8 
       string. The conference description consists of up to 2048 UTF-8 
       characters. Length range: 1 to 2048.
  */

  /* Mandatory */
  /*  Sequence Number */
  uint32_t sequence;
  /**<   Sequence number of this indication. Sequence number 0 indicates that 
       this indication is the start of a new update. The sequence number 
       increments for each successive indication of an update.
  */

  /* Optional */
  /*  Total Size */
  uint8_t total_size_valid;  /**< Must be set to true if total_size is being passed */
  uint32_t total_size;
  /**<   Total size of the document being passed. This is included in the 
       first indication of an update, i.e., the indication with sequence 
       number 0. The client has received the last indication of an update 
       when the received size is equal to the total size.
  */

  /* Optional */
  /*  Call ID  */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Call ID of the call for which the conference info indication is sent.
  */
}voice_conference_info_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Notifies clients about a new join in a conference. */
typedef struct {

  /* Mandatory */
  /*  Join Info */
  uint8_t call_id;
  /**<   Call ID of the conference. 
  */

  /* Mandatory */
  /*  Participant Info */
  voice_usr_uri_type_v02 participant_uri;
}voice_conference_join_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Notifies clients about updated participants in a conference. */
typedef struct {

  /* Mandatory */
  /*  Participant Info */
  voice_usr_uri_type_v02 participant_uri;
}voice_conference_participant_update_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t mcc;
  /**<   Mobile country code. 
  */

  uint8_t db_subtype;
  /**<   Data burst subtype. 
  */

  uint8_t chg_ind;
  /**<   Charge indication. 
  */

  uint8_t sub_unit;
  /**<   Unit call time in 1/10 second.
  */

  uint8_t unit;
  /**<   Unit call time in seconds.
  */
}voice_ext_brst_intl_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Notifies clients of an extended burst type international message 
             (only applicable for 3GPP2). */
typedef struct {

  /* Mandatory */
  /*  Extended Burst Type International Info */
  voice_ext_brst_intl_type_v02 ext_burst_data;
}voice_ext_brst_intl_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Relays page miss information to clients. */
typedef struct {

  /* Mandatory */
  /*  Reason for MT Page Miss */
  call_end_reason_enum_v02 page_miss_reason;
  /**<   Page miss reason; 
       see @latexonly Table~\ref{tbl:endReasons}@endlatexonly for a list of 
       valid voice-related call end reasons. 
  */
}voice_mt_page_miss_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_CC_RESULT_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_CC_RESULT_ALLOW_NO_MOD_V02 = 0x00, /**<  Call is allowed; call control did not make any modifications \n  */
  VOICE_CC_RESULT_NOT_ALLOWED_V02 = 0x01, /**<  Call is not allowed \n  */
  VOICE_CC_RESULT_ALLOWED_BUT_MOD_V02 = 0x02, /**<  Call is allowed, but there were modifications \n  */
  VOICE_CC_RESULT_ALLOWED_BUT_MOD_TO_VOICE_V02 = 0x03, /**<  Call is allowed; the call type was changed to voice \n  */
  VOICE_CC_RESULT_ALLOWED_BUT_MOD_TO_SS_V02 = 0x04, /**<  Call is allowed; the call type was changed to SS \n  */
  VOICE_CC_RESULT_ALLOWED_BUT_MOD_TO_USSD_V02 = 0x05, /**<  Call is allowed; the call type was changed to USSD  */
  VOICE_CC_RESULT_ALLOWED_BUT_MOD_TO_VT_V02 = 0x06, /**<  Call is allowed; the call type was changed to VT  */
  VOICE_CC_RESULT_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_cc_result_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_ALPHA_PRESENCE_INFO_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_CC_ALPHA_NOT_PRESENT_V02 = 0x00, /**<  Alpha is absent in the call control result \n  */
  VOICE_CC_ALPHA_PRESENT_V02 = 0x01, /**<  Alpha is present and the length is nonzero \n  */
  VOICE_CC_ALPHA_NULL_V02 = 0x02, /**<  Alpha is present, but the length is zero  */
  VOICE_ALPHA_PRESENCE_INFO_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_alpha_presence_info_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Relays call control result information to clients. */
typedef struct {

  /* Mandatory */
  /*  Call Control Result */
  voice_cc_result_enum_v02 cc_result;
  /**<   Call control result. Values: \n
      - VOICE_CC_RESULT_ALLOW_NO_MOD (0x00) --  Call is allowed; call control did not make any modifications \n 
      - VOICE_CC_RESULT_NOT_ALLOWED (0x01) --  Call is not allowed \n 
      - VOICE_CC_RESULT_ALLOWED_BUT_MOD (0x02) --  Call is allowed, but there were modifications \n 
      - VOICE_CC_RESULT_ALLOWED_BUT_MOD_TO_VOICE (0x03) --  Call is allowed; the call type was changed to voice \n 
      - VOICE_CC_RESULT_ALLOWED_BUT_MOD_TO_SS (0x04) --  Call is allowed; the call type was changed to SS \n 
      - VOICE_CC_RESULT_ALLOWED_BUT_MOD_TO_USSD (0x05) --  Call is allowed; the call type was changed to USSD 
      - VOICE_CC_RESULT_ALLOWED_BUT_MOD_TO_VT (0x06) --  Call is allowed; the call type was changed to VT  
 */

  /* Mandatory */
  /*  Alpha Presence Info */
  voice_alpha_presence_info_enum_v02 alpha_presence;
  /**<   Call control alpha presence information. Values: \n
      - VOICE_CC_ALPHA_NOT_PRESENT (0x00) --  Alpha is absent in the call control result \n 
      - VOICE_CC_ALPHA_PRESENT (0x01) --  Alpha is present and the length is nonzero \n 
      - VOICE_CC_ALPHA_NULL (0x02) --  Alpha is present, but the length is zero  
 */

  /* Optional */
  /*  Call Control Alpha Data */
  uint8_t alpha_text_gsm8_valid;  /**< Must be set to true if alpha_text_gsm8 is being passed */
  uint32_t alpha_text_gsm8_len;  /**< Must be set to # of elements in alpha_text_gsm8 */
  uint8_t alpha_text_gsm8[QMI_VOICE_CC_ALPHA_TEXT_MAX_V02];
  /**<   Call control alpha data in SMS default 7-bit coded 
       alphabet as defined in \hyperref[STD-23038]{3GPP TS 23.038} with bit 8 set to 0.
  */

  /* Optional */
  /*  Call Control Alpha Data in UTF-16 Format */
  uint8_t alpha_text_utf16_valid;  /**< Must be set to true if alpha_text_utf16 is being passed */
  uint32_t alpha_text_utf16_len;  /**< Must be set to # of elements in alpha_text_utf16 */
  uint16_t alpha_text_utf16[QMI_VOICE_CC_ALPHA_TEXT_MAX_V02];
  /**<   Call control alpha data in UTF-16 format.
  */
}voice_call_control_result_info_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_UPDATE_TYPE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_UPDATE_TYPE_FULL_V02 = 0x00, /**<  Full \n  */
  VOICE_UPDATE_TYPE_PARTIAL_V02 = 0x01, /**<  Partial  */
  VOICE_UPDATE_TYPE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_update_type_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_CONF_PART_CALL_STATUS_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_PARTICIPANT_NO_CHANGE_V02 = 0x00, /**<  No change \n  */
  VOICE_PARTICIPANT_PENDING_V02 = 0x01, /**<  Pending \n  */
  VOICE_PARTICIPANT_DIALING_OUT_V02 = 0x02, /**<  Dialing out \n  */
  VOICE_PARTICIPANT_DIALING_IN_V02 = 0x03, /**<  Dialing in \n  */
  VOICE_PARTICIPANT_ALERTING_V02 = 0x04, /**<  Alerting \n  */
  VOICE_PARTICIPANT_ON_HOLD_V02 = 0x05, /**<  On hold \n  */
  VOICE_PARTICIPANT_CONNECTED_V02 = 0x06, /**<  Connected \n  */
  VOICE_PARTICIPANT_MUTED_VIA_FOCUS_V02 = 0x07, /**<  Muted via Focus \n  */
  VOICE_PARTICIPANT_DISCONNECTING_V02 = 0x08, /**<  Disconnecting \n  */
  VOICE_PARTICIPANT_DISCONNECTED_V02 = 0x09, /**<  Disconnected  */
  VOICE_CONF_PART_CALL_STATUS_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_conf_part_call_status_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOICE_CONF_PART_DISCONNECTION_METHOD_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_DISC_NO_CHANGE_V02 = 0x00, /**<  No change \n  */
  VOICE_DISC_DEPARTED_V02 = 0x01, /**<  Departed \n  */
  VOICE_DISC_BOOTED_V02 = 0x02, /**<  Booted \n  */
  VOICE_DISC_FAILED_V02 = 0x03, /**<  Failed \n  */
  VOICE_DISC_BUSY_V02 = 0x04, /**<  Busy  */
  VOICE_CONF_PART_DISCONNECTION_METHOD_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voice_conf_part_disconnection_method_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t user_uri_len;  /**< Must be set to # of elements in user_uri */
  uint16_t user_uri[QMI_VOICE_CONF_URI_MAX_LEN_V02];
  /**<   URI of the participant. This is unique to each user 
       and consists of UTF-16 characters. The string is not guaranteed 
       to be NULL terminated. Length range in bytes: 0 to 128.
  */

  voice_conf_part_call_status_enum_v02 status;
  /**<   Call status. Values: \n
      - VOICE_PARTICIPANT_NO_CHANGE (0x00) --  No change \n 
      - VOICE_PARTICIPANT_PENDING (0x01) --  Pending \n 
      - VOICE_PARTICIPANT_DIALING_OUT (0x02) --  Dialing out \n 
      - VOICE_PARTICIPANT_DIALING_IN (0x03) --  Dialing in \n 
      - VOICE_PARTICIPANT_ALERTING (0x04) --  Alerting \n 
      - VOICE_PARTICIPANT_ON_HOLD (0x05) --  On hold \n 
      - VOICE_PARTICIPANT_CONNECTED (0x06) --  Connected \n 
      - VOICE_PARTICIPANT_MUTED_VIA_FOCUS (0x07) --  Muted via Focus \n 
      - VOICE_PARTICIPANT_DISCONNECTING (0x08) --  Disconnecting \n 
      - VOICE_PARTICIPANT_DISCONNECTED (0x09) --  Disconnected  
 */

  voice_call_attribute_type_mask_v02 audio_attributes;
  /**<   Audio attributes of the participant. Values: \n
      - VOICE_CALL_ATTRIB_TX (0x01) --  Transmission \n 
      - VOICE_CALL_ATTRIB_RX (0x02) --  Receiving \n 
      - VOICE_CALL_ATTRIB_NO_CHANGE (0x80) --  No change  
 */

  voice_call_attribute_type_mask_v02 video_attributes;
  /**<   Video attributes of the participant. Values: \n
      - VOICE_CALL_ATTRIB_TX (0x01) --  Transmission \n 
      - VOICE_CALL_ATTRIB_RX (0x02) --  Receiving \n 
      - VOICE_CALL_ATTRIB_NO_CHANGE (0x80) --  No change  
 */

  voice_conf_part_disconnection_method_enum_v02 disconnection_method;
  /**<   Disconnection method. Values: \n
      - VOICE_DISC_NO_CHANGE (0x00) --  No change \n 
      - VOICE_DISC_DEPARTED (0x01) --  Departed \n 
      - VOICE_DISC_BOOTED (0x02) --  Booted \n 
      - VOICE_DISC_FAILED (0x03) --  Failed \n 
      - VOICE_DISC_BUSY (0x04) --  Busy  
 */

  uint32_t disconnection_info_len;  /**< Must be set to # of elements in disconnection_info */
  char disconnection_info[QMI_VOICE_CONF_DISPLAY_TEXT_MAX_LEN_V02];
  /**<   Disconnection information.
       This is an ASCII string and it is not guaranteed 
       to be NULL terminated. Length range in bytes: 0 to 64.
  */
}voice_conf_participant_call_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  voice_update_type_enum_v02 update_type;
  /**<   Update type. Values: \n
      - VOICE_UPDATE_TYPE_FULL (0x00) --  Full \n 
      - VOICE_UPDATE_TYPE_PARTIAL (0x01) --  Partial  
 */

  uint32_t conf_participant_info_len;  /**< Must be set to # of elements in conf_participant_info */
  voice_conf_participant_call_info_type_v02 conf_participant_info[QMI_VOICE_CONF_PARTICIPANT_INFO_ARRAY_MAX_V02];
  /**<   Array of call info of conference participants.
    */
}voice_conference_call_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Relays conference call information to clients. */
typedef struct {

  /* Mandatory */
  /*  Conference Call Info */
  voice_conference_call_info_type_v02 conf_call_info;
}voice_conf_participants_info_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Allows the client to respond to the MT voice call setup. */
typedef struct {

  /* Mandatory */
  /*  Call ID */
  uint8_t call_id;
  /**<   Unique call identifier for the call that needs a setup response.
  */

  /* Optional */
  /*  Reject Setup of Incoming Call */
  uint8_t reject_setup_valid;  /**< Must be set to true if reject_setup is being passed */
  uint8_t reject_setup;
  /**<   Values: \n       
       - 0x00 -- Accept the call setup \n
       - 0x01 -- Reject the call setup
  */

  /* Optional */
  /*  Reject Cause */
  uint8_t reject_cause_valid;  /**< Must be set to true if reject_cause is being passed */
  voice_reject_cause_enum_v02 reject_cause;
  /**<   Cause for rejecting the call setup. Values: \n
      - VOICE_REJECT_CAUSE_USER_BUSY (0x01) --  User is busy \n 
      - VOICE_REJECT_CAUSE_USER_REJECT (0x02) --  User has rejected the call \n 
      - VOICE_REJECT_CAUSE_LOW_BATTERY (0x03) --  Call was rejected due to a low battery \n 
      - VOICE_REJECT_CAUSE_BLACKLISTED_CALL_ID (0x04) --  Call was rejected because the number was blacklisted \n 
      - VOICE_REJECT_CAUSE_DEAD_BATTERY (0x05) --  Call was rejected due to a dead battery 
      - VOICE_REJECT_CAUSE_UNWANTED_CALL (0x06) --  Call was rejected because the call was an unwanted robo call  
 */
}voice_setup_answer_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Allows the client to respond to the MT voice call setup. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Call ID */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Unique call identifier for the call whose setup was responded.
  */
}voice_setup_answer_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Informs clients about information related to TTY. */
typedef struct {

  /* Mandatory */
  /*  TTY Mode  */
  tty_mode_enum_v02 tty_mode;
  /**<   TTY mode. Values: \n
      - TTY_MODE_FULL (0x00) --  Full \n 
      - TTY_MODE_VCO (0x01) --  Voice carry over \n 
      - TTY_MODE_HCO (0x02) --  Hearing carry over \n 
      - TTY_MODE_OFF (0x03) --  Off  
 */
}voice_tty_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Allows the client to start videosharing. */
typedef struct {

  /* Mandatory */
  /*  Call ID */
  uint8_t call_id;
  /**<   Unique call identifier for the call for which videosharing is requested.
  */
}voice_vs_start_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Allows the client to start videosharing. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Call ID */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Unique call identifier for the call for which videosharing was requested.
  */
}voice_vs_start_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Allows the client to answer a videosharing request. */
typedef struct {

  /* Mandatory */
  /*  Call ID */
  uint8_t call_id;
  /**<   Unique call identifier of the call for which videosharing is to be 
       answered (accepted).
  */
}voice_vs_answer_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Allows the client to answer a videosharing request. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Call ID */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Unique call identifier for the call for which videosharing was answered.
  */
}voice_vs_answer_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Allows the client to end videosharing for a call. */
typedef struct {

  /* Mandatory */
  /*  Call ID */
  uint8_t call_id;
  /**<   Unique call identifier of the call for which videosharing is ending.
  */
}voice_vs_end_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Allows the client to end videosharing for a call. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Call ID */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Unique call identifier for the call for which videosharing ended.
  */
}voice_vs_end_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VIDEOSHARE_STATUS_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_VS_IDLE_V02 = 0x00, /**<  Idle \n  */
  VOICE_VS_ACTIVE_V02 = 0x01, /**<  Active \n  */
  VOICE_VS_DIALING_V02 = 0x02, /**<  Dialing \n  */
  VOICE_VS_ALERTING_V02 = 0x03, /**<  Alerting \n  */
  VOICE_VS_INCOMING_V02 = 0x04, /**<  Incoming \n  */
  VOICE_VS_DISCONNECTING_V02 = 0x05, /**<  Disconnecting \n  */
  VOICE_VS_DISCONNECTED_V02 = 0x06, /**<  Disconnected  */
  VIDEOSHARE_STATUS_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}videoshare_status_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Informs clients about information related to videosharing. */
typedef struct {

  /* Mandatory */
  /*  Call ID */
  uint8_t call_id;
  /**<   Unique identifier for the call for which the videosharing status is sent.
  */

  /* Mandatory */
  /*  Videoshare Status */
  videoshare_status_enum_v02 status;
  /**<   Videosharing status. Values: \n
      - VOICE_VS_IDLE (0x00) --  Idle \n 
      - VOICE_VS_ACTIVE (0x01) --  Active \n 
      - VOICE_VS_DIALING (0x02) --  Dialing \n 
      - VOICE_VS_ALERTING (0x03) --  Alerting \n 
      - VOICE_VS_INCOMING (0x04) --  Incoming \n 
      - VOICE_VS_DISCONNECTING (0x05) --  Disconnecting \n 
      - VOICE_VS_DISCONNECTED (0x06) --  Disconnected 
 */
}voice_videoshare_status_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t sequence;
  /**<   Sequence number of this indication. Sequence number 0 indicates that 
       this indication is the start of a new update. The sequence number 
       increments for each successive indication of an update.
  */

  uint32_t additional_call_info_len;  /**< Must be set to # of elements in additional_call_info */
  uint8_t additional_call_info[QMI_VOICE_ADDITIONAL_INFO_MAX_LEN_V02];
  /**<   Additional call information is a part of the complete update and is 
       passed as a UTF-8 string. The additional information consists of
       up to 2048 UTF-8 characters. Length range: 1 to 2048.
  */

  uint32_t total_size;
  /**<   Total size of the update to be passed. The client has received the 
       last indication of an update when the received size is equal to the 
       total size.
  */
}voice_additional_call_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Informs clients about additional information related to calls. */
typedef struct {

  /* Mandatory */
  /*  Call ID */
  uint8_t call_id;
  /**<   Unique identifier for the call.
  */

  /* Optional */
  /*  Extension Header Info */
  uint8_t extension_header_info_valid;  /**< Must be set to true if extension_header_info is being passed */
  voice_additional_call_info_type_v02 extension_header_info;
}voice_additional_call_info_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  AUDIO_SESSION_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_AUDIO_PASSIVE_SESSION_START_V02 = 0x00, /**<  Start \n  */
  VOICE_AUDIO_PASSIVE_SESSION_STOP_V02 = 0x01, /**<  Stop  */
  AUDIO_SESSION_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}audio_session_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Informs clients about audio RAT changes. */
typedef struct {

  /* Optional */
  /*  Audio Session Information */
  uint8_t audio_session_info_valid;  /**< Must be set to true if audio_session_info is being passed */
  audio_session_enum_v02 audio_session_info;
  /**<   Audio passive session information. Values: \n
      - VOICE_AUDIO_PASSIVE_SESSION_START (0x00) --  Start \n 
      - VOICE_AUDIO_PASSIVE_SESSION_STOP (0x01) --  Stop  
 */

  /* Optional */
  /*  RAT Information */
  uint8_t rat_info_valid;  /**< Must be set to true if rat_info is being passed */
  call_mode_enum_v02 rat_info;
  /**<   Rat information. Values: \n
       - 0x04 -- CALL_MODE_LTE -- LTE \n
       - 0x07 -- CALL_MODE_WLAN -- WLAN
  */
}voice_audio_rat_change_info_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  CONF_PARTICIPANT_OPERATION_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_CONF_PARTICIPANT_ADD_V02 = 0x00, /**<  Add \n  */
  VOICE_CONF_PARTICIPANT_REMOVE_V02 = 0x01, /**<  Remove  */
  CONF_PARTICIPANT_OPERATION_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}conf_participant_operation_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_aggregates
    @{
  */
typedef struct {

  conf_participant_operation_enum_v02 operation;
  /**<   Operation on the participant. Values: \n
      - VOICE_CONF_PARTICIPANT_ADD (0x00) --  Add \n 
      - VOICE_CONF_PARTICIPANT_REMOVE (0x01) --  Remove 
 */

  uint16_t sip_status;
  /**<   SIP code indicating the participant's status.
       The SIP code is as defined in \hyperref[RFC3261]{RFC3261}.
  */
}voice_participant_operation_info_type_v02;  /* Type */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Informs clients about the status of operations on a participant 
             in a conference call. */
typedef struct {

  /* Mandatory */
  /*  Call ID */
  uint8_t call_id;
  /**<   Call ID of the conference call.
  */

  /* Mandatory */
  /*  Participant URI */
  char participant_uri[QMI_VOICE_SIP_URI_MAX_V02 + 1];
  /**<   SIP URI number in ASCII string. Length range: 1 to 128.
  */

  /* Optional */
  /*  Participant Operation Status Information */
  uint8_t op_status_valid;  /**< Must be set to true if op_status is being passed */
  voice_participant_operation_info_type_v02 op_status;

  /* Optional */
  /*  Is QMI Voice Transfer */
  uint8_t is_qmi_voice_transfer_valid;  /**< Must be set to true if is_qmi_voice_transfer is being passed */
  uint8_t is_qmi_voice_transfer;
  /**<   Whether this is an Explicit Call Transfer; boolean value.
  */
}voice_conf_participant_status_info_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Allows the client to modify the secure call mode. */
typedef struct {

  /* Mandatory */
  /*  Secure Call Mode */
  uint8_t enable;
  /**<   Values: \n
       - 0x00 -- Disable \n
       - 0x01 -- Enable
  */

  /* Mandatory */
  /*  Call Direction */
  call_direction_enum_v02 direction;
  /**<   Direction. Values: \n
       - 0x01 -- CALL_DIRECTION_MO -- MO call \n
       - 0x02 -- CALL_DIRECTION_MT -- MT call
  */
}voice_secure_call_mode_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Allows the client to modify the secure call mode. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}voice_secure_call_mode_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Tells the modem whether the secure call feature is enabled. */
typedef struct {

  /* Mandatory */
  /*  Call ID */
  uint8_t call_id;
  /**<   Unique identifier for the call.
  */

  /* Mandatory */
  /*  Secure Call Established */
  uint8_t secure_context_established;
  /**<   Whether the secure call context is established. Values: \n
       - 0x00 -- Not established \n
       - 0x01 -- Established
  */
}voice_call_encryption_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Tells the modem whether the secure call feature is enabled. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}voice_call_encryption_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Sets the WWAN_911 Timer value.  */
typedef struct {

  /* Mandatory */
  /*  WWAN-911 Timer Value */
  uint16_t wwan_911_timer;
  /**<   WWAN-911 Timer value in seconds.
  */
}voice_set_wwan_911_timer_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Sets the WWAN_911 Timer value.  */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}voice_set_wwan_911_timer_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Gets the last known WWAN-911 Timer value. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}voice_get_wwan_911_timer_req_msg_v02;

  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Gets the last known WWAN-911 Timer value. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  WWAN-911 Timer Value */
  uint8_t wwan_911_timer_valid;  /**< Must be set to true if wwan_911_timer is being passed */
  uint16_t wwan_911_timer;
  /**<   WWAN-911 Timer value in seconds.
  */
}voice_get_wwan_911_timer_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Notifies clients about which PLMNs to avoid.  */
typedef struct {

  /* Mandatory */
  /*  Avoid PLMN List Sent by AP */
  uint32_t list_to_avoid_len;  /**< Must be set to # of elements in list_to_avoid */
  nas_plmn_id_type_v01 list_to_avoid[QMI_VOICE_AVOID_PLMN_LIST_MAX_LENGTH_V02];
  /**<   (list of PLMNs to avoid)
  */
}voice_avoid_plmn_list_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Notifies clients about which PLMNs to avoid.  */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}voice_avoid_plmn_list_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  ECALL_MSD_TRANSMISSION_STATUS_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_ECALL_MSD_TRANSMISSION_STATUS_SUCCESS_V02 = 0x00, /**<  Success \n  */
  VOICE_ECALL_MSD_TRANSMISSION_STATUS_FAILURE_V02 = 0x01, /**<  Generic failure \n  */
  VOICE_ECALL_MSD_TRANSMISSION_STARTED_V02 = 0x02, /**<  MSD transmission started  */
  VOICE_ECALL_MSD_NACK_OUT_OF_ORDER_V02 = 0x03, /**<  Out of order NACK message detected  */
  VOICE_ECALL_MSD_ACK_OUT_OF_ORDER_V02 = 0x04, /**<  Out of order ACK message detected  */
  ECALL_MSD_TRANSMISSION_STATUS_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}ecall_msd_transmission_status_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Informs clients about the eCall status. */
typedef struct {

  /* Mandatory */
  /*  Call ID */
  uint8_t call_id;
  /**<   Call ID of the eCall.
  */

  /* Optional */
  /*  Minimum Set of Data Transmission Status */
  uint8_t msd_transmission_status_valid;  /**< Must be set to true if msd_transmission_status is being passed */
  ecall_msd_transmission_status_enum_v02 msd_transmission_status;
  /**<   Minimum set of data transmission status. Values: \n
      - VOICE_ECALL_MSD_TRANSMISSION_STATUS_SUCCESS (0x00) --  Success \n 
      - VOICE_ECALL_MSD_TRANSMISSION_STATUS_FAILURE (0x01) --  Generic failure \n 
      - VOICE_ECALL_MSD_TRANSMISSION_STARTED (0x02) --  MSD transmission started 
      - VOICE_ECALL_MSD_NACK_OUT_OF_ORDER (0x03) --  Out of order NACK message detected 
      - VOICE_ECALL_MSD_ACK_OUT_OF_ORDER (0x04) --  Out of order ACK message detected 
 */
}voice_ecall_status_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  ECALL_OPRT_MODE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_ECALL_OPRT_MODE_ECALL_NORMAL_V02 = 0x00, /**<  eCall Normal mode \n  */
  VOICE_ECALL_OPRT_MODE_ECALL_ONLY_V02 = 0x01, /**<  eCall Only mode  */
  VOICE_ECALL_OPRT_MODE_NONE_V02 = 0x02, /**<  eCall operating mode none  */
  ECALL_OPRT_MODE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}ecall_oprt_mode_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Sets the eCall operating mode. */
typedef struct {

  /* Mandatory */
  /*  New eCall Operating Mode */
  ecall_oprt_mode_enum_v02 oprt_mode;
  /**<   New eCall operating mode. Values: \n
      - VOICE_ECALL_OPRT_MODE_ECALL_NORMAL (0x00) --  eCall Normal mode \n 
      - VOICE_ECALL_OPRT_MODE_ECALL_ONLY (0x01) --  eCall Only mode 
      - VOICE_ECALL_OPRT_MODE_NONE (0x02) --  eCall operating mode none 
 */
}voice_set_ecall_oprt_mode_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Sets the eCall operating mode. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}voice_set_ecall_oprt_mode_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  ECALL_OPRT_MODE_CHANGE_REASON_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_ECALL_OPRT_MODE_CHANGE_REASON_NORMAL_V02 = 0x00, /**<  eCall operating mode changed due to normal operation \n  */
  VOICE_ECALL_OPRT_MODE_CHANGE_REASON_ERA_GLONASS_V02 = 0x01, /**<  eCall operating mode changed due to ERA-GLONASS operation  */
  ECALL_OPRT_MODE_CHANGE_REASON_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}ecall_oprt_mode_change_reason_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Informs clients about eCall operating mode changes. */
typedef struct {

  /* Mandatory */
  /*  eCall Operating Mode */
  ecall_oprt_mode_enum_v02 oprt_mode;
  /**<   eCall operating mode. Values: \n
      - VOICE_ECALL_OPRT_MODE_ECALL_NORMAL (0x00) --  eCall Normal mode \n 
      - VOICE_ECALL_OPRT_MODE_ECALL_ONLY (0x01) --  eCall Only mode 
      - VOICE_ECALL_OPRT_MODE_NONE (0x02) --  eCall operating mode none 
 */

  /* Mandatory */
  /*  eCall Operating Mode Change Reason */
  ecall_oprt_mode_change_reason_enum_v02 reason;
  /**<   eCall operating mode change reason. Values: \n
      - VOICE_ECALL_OPRT_MODE_CHANGE_REASON_NORMAL (0x00) --  eCall operating mode changed due to normal operation \n 
      - VOICE_ECALL_OPRT_MODE_CHANGE_REASON_ERA_GLONASS (0x01) --  eCall operating mode changed due to ERA-GLONASS operation 
 */
}voice_ecall_oprt_mode_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Queries the eCall operating mode. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}voice_get_ecall_oprt_mode_req_msg_v02;

  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Queries the eCall operating mode. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  eCall Operating Mode */
  uint8_t oprt_mode_valid;  /**< Must be set to true if oprt_mode is being passed */
  ecall_oprt_mode_enum_v02 oprt_mode;
  /**<   eCall operating mode. Values: \n
      - VOICE_ECALL_OPRT_MODE_ECALL_NORMAL (0x00) --  eCall Normal mode \n 
      - VOICE_ECALL_OPRT_MODE_ECALL_ONLY (0x01) --  eCall Only mode 
      - VOICE_ECALL_OPRT_MODE_NONE (0x02) --  eCall operating mode none 
 */
}voice_get_ecall_oprt_mode_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  CALL_REESTAB_STATUS_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOICE_CALL_REESTABLISHMENT_STATUS_STARTED_V02 = 0x00, /**<  Started \n  */
  VOICE_CALL_REESTABLISHMENT_STATUS_SUCCESS_V02 = 0x01, /**<  Success  */
  CALL_REESTAB_STATUS_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}call_reestab_status_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Informs clients about the call reestablishment status. */
typedef struct {

  /* Mandatory */
  /*  Call Reestablishment Status */
  call_reestab_status_enum_v02 status;
  /**<   Status of the call re-establishment. Values: \n
      - VOICE_CALL_REESTABLISHMENT_STATUS_STARTED (0x00) --  Started \n 
      - VOICE_CALL_REESTABLISHMENT_STATUS_SUCCESS (0x01) --  Success 
 */
}voice_call_reestablishment_status_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Informs clients about a VoLTE over Internet Connected Endpoint (VICE) 
             dialog event. */
typedef struct {

  /* Mandatory */
  /*  VICE Dialog XML */
  uint32_t vice_dialog_xml_len;  /**< Must be set to # of elements in vice_dialog_xml */
  uint8_t vice_dialog_xml[QMI_VOICE_VICE_DIALOG_XML_LEN_V02];
  /**<   VICE XML is a part of an XML file that is passed as a UTF-8 
       string. The dialog description consists of up to 2048 UTF-8
       characters. Length range: 1 to 2048.
  */

  /* Mandatory */
  /*  Sequence Number */
  uint32_t sequence;
  /**<   Sequence number of this indication. Sequence number 0 indicates that 
       this indication is the start of a new update. The sequence number 
       increments for each successive indication of an update.
  */

  /* Optional */
  /*  Total Size */
  uint8_t total_size_valid;  /**< Must be set to true if total_size is being passed */
  uint32_t total_size;
  /**<   Total size of the document being passed. This is included in the 
       first indication of an update, i.e., the indication with sequence 
       number 0. The client has received the last indication of an update 
       when the received size is equal to the total size.
  */
}vice_dialog_info_ind_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Allows applicatons to query for speech_codec when they have not
             registered for speech codec indications. */
typedef struct {

  /* Mandatory */
  /*  Call ID */
  uint8_t call_id;
  /**<   Call ID of the call for which the speech codec information is required.
  */
}voice_get_speech_codec_info_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Allows applicatons to query for speech_codec when they have not
             registered for speech codec indications. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Call ID  */
  uint8_t call_id_valid;  /**< Must be set to true if call_id is being passed */
  uint8_t call_id;
  /**<   Call ID of the call for which the speech codec information is sent.
  */

  /* Optional */
  /*  Network Mode */
  uint8_t network_mode_valid;  /**< Must be set to true if network_mode is being passed */
  voice_network_mode_enum_v02 network_mode;
  /**<   Network mode. Values: \n
      - VOICE_NETWORK_MODE_NONE (0x00) --  None \n 
      - VOICE_NETWORK_MODE_GSM (0x01) --  GSM \n 
      - VOICE_NETWORK_MODE_WCDMA (0x02) --  WCDMA \n 
      - VOICE_NETWORK_MODE_CDMA (0x03) --  CDMA \n 
      - VOICE_NETWORK_MODE_LTE (0x04) --  LTE \n 
      - VOICE_NETWORK_MODE_TDSCDMA (0x05) --  TDSCDMA \n 
      - VOICE_NETWORK_MODE_WLAN (0x06) --  WLAN \n 
 */

  /* Optional */
  /*  Speech Codec Type */
  uint8_t speech_codec_valid;  /**< Must be set to true if speech_codec is being passed */
  voice_speech_codec_enum_v02 speech_codec;
  /**<   Speech codec type. Values: \n
      - VOICE_SPEECH_CODEC_NONE (0x0000) --  None \n 
      - VOICE_SPEECH_CODEC_QCELP13K (0x0001) --  QCELP-13K \n 
      - VOICE_SPEECH_CODEC_EVRC (0x0002) --  EVRC \n 
      - VOICE_SPEECH_CODEC_EVRC_B (0x0003) --  EVRC-B \n 
      - VOICE_SPEECH_CODEC_EVRC_WB (0x0004) --  EVRC wideband \n 
      - VOICE_SPEECH_CODEC_EVRC_NW (0x0005) --  EVRC narrowband-wideband \n 
      - VOICE_SPEECH_CODEC_AMR_NB (0x0006) --  AMR narrowband \n 
      - VOICE_SPEECH_CODEC_AMR_WB (0x0007) --  AMR wideband \n 
      - VOICE_SPEECH_CODEC_GSM_EFR (0x0008) --  GSM enhanced full rate \n 
      - VOICE_SPEECH_CODEC_GSM_FR (0x0009) --  GSM full rate \n 
      - VOICE_SPEECH_CODEC_GSM_HR (0x000A) --  GSM half rate \n 
      - VOICE_SPEECH_CODEC_G711U (0x000B) --  G711U \n 
      - VOICE_SPEECH_CODEC_G723 (0x000C) --  G723 \n 
      - VOICE_SPEECH_CODEC_G711A (0x000D) --  G711A \n 
      - VOICE_SPEECH_CODEC_G722 (0x000E) --  G722 \n 
      - VOICE_SPEECH_CODEC_G711AB (0x000F) --  G711AB \n 
      - VOICE_SPEECH_CODEC_G729 (0x0010) --  G729 \n 
      - VOICE_SPEECH_CODEC_EVS_NB (0x0011) --  EVS narrowband \n 
      - VOICE_SPEECH_CODEC_EVS_WB (0x0012) --  EVS_WB wideband \n 
      - VOICE_SPEECH_CODEC_EVS_SWB (0x0013) --  EVS super-wideband \n 
      - VOICE_SPEECH_CODEC_EVS_FB (0x0014) --  EVS fullband 
 */

  /* Optional */
  /*  Speech Encoder Sampling Rate */
  uint8_t speech_enc_samp_freq_valid;  /**< Must be set to true if speech_enc_samp_freq is being passed */
  uint32_t speech_enc_samp_freq;
  /**<   Speech encoder sampling rate instructed by the network in Hz.
  */
}voice_get_speech_codec_info_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_enums
    @{
  */
typedef enum {
  VOIP_CANCEL_TYPE_ENUM_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  VOIP_CANCEL_TYPE_CANCEL_CALL_UPGRADE_V02 = 0x1, /**<  Cancel call upgrade from voice to video for a specific call ID  */
  VOIP_CANCEL_TYPE_CANCEL_CALL_DOWNGRADE_V02 = 0x2, /**<  Cancel call downgrade from video to voice for a specific call ID  */
  VOIP_CANCEL_TYPE_CANCEL_CALL_HOLD_V02 = 0x3, /**<  Cancel call hold operation for a specific call ID  */
  VOIP_CANCEL_TYPE_CANCEL_CALL_RESUME_V02 = 0x4, /**<  Cancel call resume operation for a specific call ID  */
  VOIP_CANCEL_TYPE_ENUM_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}voip_cancel_type_enum_v02;
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Request Message; Allows the client to cancel ongoing upgrade, downgrade, hold, or
           resume operations during a call.  */
typedef struct {

  /* Mandatory */
  /*  Call ID */
  uint8_t call_id;
  /**<   Unique identifier for the call. Applicable for all cancel types.
  */

  /* Mandatory */
  /*  Call Cancel Type */
  voip_cancel_type_enum_v02 cancel_type;
  /**<   Cancel service type during the call. \n
      - VOIP_CANCEL_TYPE_CANCEL_CALL_UPGRADE (0x1) --  Cancel call upgrade from voice to video for a specific call ID 
      - VOIP_CANCEL_TYPE_CANCEL_CALL_DOWNGRADE (0x2) --  Cancel call downgrade from video to voice for a specific call ID 
      - VOIP_CANCEL_TYPE_CANCEL_CALL_HOLD (0x3) --  Cancel call hold operation for a specific call ID 
      - VOIP_CANCEL_TYPE_CANCEL_CALL_RESUME (0x4) --  Cancel call resume operation for a specific call ID 
 */
}voice_ims_call_cancel_req_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Response Message; Allows the client to cancel ongoing upgrade, downgrade, hold, or
           resume operations during a call.  */
typedef struct {

  /* Mandatory */
  /*  Result  */
  qmi_response_type_v01 resp;

  /* Mandatory */
  /*  Call ID */
  uint8_t call_id;
  /**<   Unique identifier for the call. Applicable for all cancel types.
  */

  /* Mandatory */
  /*  Call Cancel Type */
  voip_cancel_type_enum_v02 cancel_type;
  /**<   Cancel service type during the call. \n
      - VOIP_CANCEL_TYPE_CANCEL_CALL_UPGRADE (0x1) --  Cancel call upgrade from voice to video for a specific call ID 
      - VOIP_CANCEL_TYPE_CANCEL_CALL_DOWNGRADE (0x2) --  Cancel call downgrade from video to voice for a specific call ID 
      - VOIP_CANCEL_TYPE_CANCEL_CALL_HOLD (0x3) --  Cancel call hold operation for a specific call ID 
      - VOIP_CANCEL_TYPE_CANCEL_CALL_RESUME (0x4) --  Cancel call resume operation for a specific call ID 
 */
}voice_ims_call_cancel_resp_msg_v02;  /* Message */
/**
    @}
  */

/** @addtogroup voice_qmi_messages
    @{
  */
/** Indication Message; Notifies clients about a MT call being automatically rejected by
             the modem. */
typedef struct {

  /* Mandatory */
  /*  Call Type */
  call_type_enum_v02 call_type;
  /**<   Type of call rejected by the modem. 
  */

  /* Mandatory */
  /*  Call End Reason */
  call_end_reason_enum_v02 call_end_reason;
  /**<   Call end reason for which the call was ended. 
  */

  /* Mandatory */
  /*  Error Code */
  uint16_t sip_error_code;
  /**<   SIP error code for IP call.   
  */

  /* Optional */
  /*  Calling Party Number */
  uint8_t num_valid;  /**< Must be set to true if num is being passed */
  uint32_t num_len;  /**< Must be set to # of elements in num */
  char num[QMI_VOICE_CALLER_ID_MAX_V02];
  /**<   Calling party number in ASCII string.
  */
}auto_rejected_incoming_call_end_ind_msg_v02;  /* Message */
/**
    @}
  */

/* Conditional compilation tags for message removal */ 
//#define REMOVE_QMI_AUTO_REJECTED_INCOMING_CALL_END_IND_V02 
//#define REMOVE_QMI_VOICE_ADDITIONAL_CALL_INFO_IND_V02 
//#define REMOVE_QMI_VOICE_ALL_CALL_STATUS_IND_V02 
//#define REMOVE_QMI_VOICE_ALS_GET_LINE_SWITCHING_STATUS_V02 
//#define REMOVE_QMI_VOICE_ALS_GET_SELECTED_LINE_V02 
//#define REMOVE_QMI_VOICE_ALS_SELECT_LINE_V02 
//#define REMOVE_QMI_VOICE_ALS_SET_LINE_SWITCHING_V02 
//#define REMOVE_QMI_VOICE_ANSWER_CALL_V02 
//#define REMOVE_QMI_VOICE_ANSWER_USSD_V02 
//#define REMOVE_QMI_VOICE_AOC_GET_CALL_METER_INFO_V02 
//#define REMOVE_QMI_VOICE_AOC_LOW_FUNDS_IND_V02 
//#define REMOVE_QMI_VOICE_AOC_RESET_ACM_V02 
//#define REMOVE_QMI_VOICE_AOC_SET_ACMMAX_V02 
//#define REMOVE_QMI_VOICE_AUDIO_RAT_CHANGE_INFO_IND_V02 
//#define REMOVE_QMI_VOICE_AVOID_PLMN_LIST_V02 
//#define REMOVE_QMI_VOICE_BIND_SUBSCRIPTION_V02 
//#define REMOVE_QMI_VOICE_BURST_DTMF_V02 
//#define REMOVE_QMI_VOICE_CALL_CONTROL_RESULT_INFO_IND_V02 
//#define REMOVE_QMI_VOICE_CALL_ENCRYPTION_V02 
//#define REMOVE_QMI_VOICE_CALL_REESTABLISHMENT_STATUS_IND_V02 
//#define REMOVE_QMI_VOICE_CANCEL_USSD_V02 
//#define REMOVE_QMI_VOICE_CONFERENCE_INFO_IND_V02 
//#define REMOVE_QMI_VOICE_CONFERENCE_JOIN_IND_V02 
//#define REMOVE_QMI_VOICE_CONFERENCE_PARTICIPANTS_INFO_IND_V02 
//#define REMOVE_QMI_VOICE_CONFERENCE_PARTICIPANT_UPDATE_IND_V02 
//#define REMOVE_QMI_VOICE_CONF_PARTICIPANT_STATUS_INFO_IND_V02 
//#define REMOVE_QMI_VOICE_DIAL_CALL_V02 
//#define REMOVE_QMI_VOICE_DTMF_IND_V02 
//#define REMOVE_QMI_VOICE_ECALL_OPRT_MODE_IND_V02 
//#define REMOVE_QMI_VOICE_ECALL_STATUS_IND_V02 
//#define REMOVE_QMI_VOICE_END_CALL_V02 
//#define REMOVE_QMI_VOICE_EXT_BRST_INTL_IND_V02 
//#define REMOVE_QMI_VOICE_GET_ALL_CALL_INFO_V02 
//#define REMOVE_QMI_VOICE_GET_CALL_BARRING_V02 
//#define REMOVE_QMI_VOICE_GET_CALL_FORWARDING_V02 
//#define REMOVE_QMI_VOICE_GET_CALL_INFO_V02 
//#define REMOVE_QMI_VOICE_GET_CALL_WAITING_V02 
//#define REMOVE_QMI_VOICE_GET_CLIP_V02 
//#define REMOVE_QMI_VOICE_GET_CLIR_V02 
//#define REMOVE_QMI_VOICE_GET_CNAP_V02 
//#define REMOVE_QMI_VOICE_GET_COLP_V02 
//#define REMOVE_QMI_VOICE_GET_COLR_V02 
//#define REMOVE_QMI_VOICE_GET_CONFIG_V02 
//#define REMOVE_QMI_VOICE_GET_ECALL_OPRT_MODE_V02 
//#define REMOVE_QMI_VOICE_GET_SPEECH_CODEC_INFO_V02 
//#define REMOVE_QMI_VOICE_GET_SUPPORTED_FIELDS_V02 
//#define REMOVE_QMI_VOICE_GET_SUPPORTED_MSGS_V02 
//#define REMOVE_QMI_VOICE_GET_WWAN_911_TIMER_V02 
//#define REMOVE_QMI_VOICE_HANDOVER_IND_V02 
//#define REMOVE_QMI_VOICE_IMS_CALL_CANCEL_V02 
//#define REMOVE_QMI_VOICE_INDICATION_REGISTER_V02 
//#define REMOVE_QMI_VOICE_INFO_REC_IND_V02 
//#define REMOVE_QMI_VOICE_MANAGE_CALLS_V02 
//#define REMOVE_QMI_VOICE_MANAGE_IP_CALLS_V02 
//#define REMOVE_QMI_VOICE_MODIFIED_IND_V02 
//#define REMOVE_QMI_VOICE_MODIFY_ACCEPT_IND_V02 
//#define REMOVE_QMI_VOICE_MT_PAGE_MISS_IND_V02 
//#define REMOVE_QMI_VOICE_ORIG_USSD_V02 
//#define REMOVE_QMI_VOICE_ORIG_USSD_NO_WAIT_V02 
//#define REMOVE_QMI_VOICE_ORIG_USSD_NO_WAIT_IND_V02 
//#define REMOVE_QMI_VOICE_OTASP_STATUS_IND_V02 
//#define REMOVE_QMI_VOICE_PRIVACY_IND_V02 
//#define REMOVE_QMI_VOICE_SECURE_CALL_MODE_V02 
//#define REMOVE_QMI_VOICE_SEND_FLASH_V02 
//#define REMOVE_QMI_VOICE_SETUP_ANSWER_V02 
//#define REMOVE_QMI_VOICE_SET_CALL_BARRING_PASSWORD_V02 
//#define REMOVE_QMI_VOICE_SET_CONFIG_V02 
//#define REMOVE_QMI_VOICE_SET_ECALL_OPRT_MODE_V02 
//#define REMOVE_QMI_VOICE_SET_PREFERRED_PRIVACY_V02 
//#define REMOVE_QMI_VOICE_SET_SUPS_SERVICE_V02 
//#define REMOVE_QMI_VOICE_SET_WWAN_911_TIMER_V02 
//#define REMOVE_QMI_VOICE_SPEECH_CODEC_INFO_IND_V02 
//#define REMOVE_QMI_VOICE_START_CONT_DTMF_V02 
//#define REMOVE_QMI_VOICE_STOP_CONT_DTMF_V02 
//#define REMOVE_QMI_VOICE_SUPS_IND_V02 
//#define REMOVE_QMI_VOICE_SUPS_NOTIFICATION_IND_V02 
//#define REMOVE_QMI_VOICE_TTY_IND_V02 
//#define REMOVE_QMI_VOICE_USSD_IND_V02 
//#define REMOVE_QMI_VOICE_USSD_RELEASE_IND_V02 
//#define REMOVE_QMI_VOICE_UUS_IND_V02 
//#define REMOVE_QMI_VOICE_VICE_DIALOG_INFO_IND_V02 
//#define REMOVE_QMI_VOICE_VIDEOSHARE_ANSWER_V02 
//#define REMOVE_QMI_VOICE_VIDEOSHARE_END_V02 
//#define REMOVE_QMI_VOICE_VIDEOSHARE_START_V02 
//#define REMOVE_QMI_VOICE_VIDEOSHARE_STATUS_IND_V02 

/*Service Message Definition*/
/** @addtogroup voice_qmi_msg_ids
    @{
  */
#define QMI_VOICE_INDICATION_REGISTER_REQ_V02 0x0003
#define QMI_VOICE_INDICATION_REGISTER_RESP_V02 0x0003
#define QMI_VOICE_GET_SUPPORTED_MSGS_REQ_V02 0x001E
#define QMI_VOICE_GET_SUPPORTED_MSGS_RESP_V02 0x001E
#define QMI_VOICE_GET_SUPPORTED_FIELDS_REQ_V02 0x001F
#define QMI_VOICE_GET_SUPPORTED_FIELDS_RESP_V02 0x001F
#define QMI_VOICE_DIAL_CALL_REQ_V02 0x0020
#define QMI_VOICE_DIAL_CALL_RESP_V02 0x0020
#define QMI_VOICE_END_CALL_REQ_V02 0x0021
#define QMI_VOICE_END_CALL_RESP_V02 0x0021
#define QMI_VOICE_ANSWER_CALL_REQ_V02 0x0022
#define QMI_VOICE_ANSWER_CALL_RESP_V02 0x0022
#define QMI_VOICE_GET_CALL_INFO_REQ_V02 0x0024
#define QMI_VOICE_GET_CALL_INFO_RESP_V02 0x0024
#define QMI_VOICE_OTASP_STATUS_IND_V02 0x0025
#define QMI_VOICE_INFO_REC_IND_V02 0x0026
#define QMI_VOICE_SEND_FLASH_REQ_V02 0x0027
#define QMI_VOICE_SEND_FLASH_RESP_V02 0x0027
#define QMI_VOICE_BURST_DTMF_REQ_V02 0x0028
#define QMI_VOICE_BURST_DTMF_RESP_V02 0x0028
#define QMI_VOICE_START_CONT_DTMF_REQ_V02 0x0029
#define QMI_VOICE_START_CONT_DTMF_RESP_V02 0x0029
#define QMI_VOICE_STOP_CONT_DTMF_REQ_V02 0x002A
#define QMI_VOICE_STOP_CONT_DTMF_RESP_V02 0x002A
#define QMI_VOICE_DTMF_IND_V02 0x002B
#define QMI_VOICE_SET_PREFERRED_PRIVACY_REQ_V02 0x002C
#define QMI_VOICE_SET_PREFERRED_PRIVACY_RESP_V02 0x002C
#define QMI_VOICE_PRIVACY_IND_V02 0x002D
#define QMI_VOICE_ALL_CALL_STATUS_IND_V02 0x002E
#define QMI_VOICE_GET_ALL_CALL_INFO_REQ_V02 0x002F
#define QMI_VOICE_GET_ALL_CALL_INFO_RESP_V02 0x002F
#define QMI_VOICE_MANAGE_CALLS_REQ_V02 0x0031
#define QMI_VOICE_MANAGE_CALLS_RESP_V02 0x0031
#define QMI_VOICE_SUPS_NOTIFICATION_IND_V02 0x0032
#define QMI_VOICE_SET_SUPS_SERVICE_REQ_V02 0x0033
#define QMI_VOICE_SET_SUPS_SERVICE_RESP_V02 0x0033
#define QMI_VOICE_GET_CALL_WAITING_REQ_V02 0x0034
#define QMI_VOICE_GET_CALL_WAITING_RESP_V02 0x0034
#define QMI_VOICE_GET_CALL_BARRING_REQ_V02 0x0035
#define QMI_VOICE_GET_CALL_BARRING_RESP_V02 0x0035
#define QMI_VOICE_GET_CLIP_REQ_V02 0x0036
#define QMI_VOICE_GET_CLIP_RESP_V02 0x0036
#define QMI_VOICE_GET_CLIR_REQ_V02 0x0037
#define QMI_VOICE_GET_CLIR_RESP_V02 0x0037
#define QMI_VOICE_GET_CALL_FORWARDING_REQ_V02 0x0038
#define QMI_VOICE_GET_CALL_FORWARDING_RESP_V02 0x0038
#define QMI_VOICE_SET_CALL_BARRING_PASSWORD_REQ_V02 0x0039
#define QMI_VOICE_SET_CALL_BARRING_PASSWORD_RESP_V02 0x0039
#define QMI_VOICE_ORIG_USSD_REQ_V02 0x003A
#define QMI_VOICE_ORIG_USSD_RESP_V02 0x003A
#define QMI_VOICE_ANSWER_USSD_REQ_V02 0x003B
#define QMI_VOICE_ANSWER_USSD_RESP_V02 0x003B
#define QMI_VOICE_CANCEL_USSD_REQ_V02 0x003C
#define QMI_VOICE_CANCEL_USSD_RESP_V02 0x003C
#define QMI_VOICE_USSD_RELEASE_IND_V02 0x003D
#define QMI_VOICE_USSD_IND_V02 0x003E
#define QMI_VOICE_UUS_IND_V02 0x003F
#define QMI_VOICE_SET_CONFIG_REQ_V02 0x0040
#define QMI_VOICE_SET_CONFIG_RESP_V02 0x0040
#define QMI_VOICE_GET_CONFIG_REQ_V02 0x0041
#define QMI_VOICE_GET_CONFIG_RESP_V02 0x0041
#define QMI_VOICE_SUPS_IND_V02 0x0042
#define QMI_VOICE_ORIG_USSD_NO_WAIT_REQ_V02 0x0043
#define QMI_VOICE_ORIG_USSD_NO_WAIT_RESP_V02 0x0043
#define QMI_VOICE_ORIG_USSD_NO_WAIT_IND_V02 0x0043
#define QMI_VOICE_BIND_SUBSCRIPTION_REQ_V02 0x0044
#define QMI_VOICE_BIND_SUBSCRIPTION_RESP_V02 0x0044
#define QMI_VOICE_ALS_SET_LINE_SWITCHING_REQ_V02 0x0045
#define QMI_VOICE_ALS_SET_LINE_SWITCHING_RESP_V02 0x0045
#define QMI_VOICE_ALS_SELECT_LINE_REQ_V02 0x0046
#define QMI_VOICE_ALS_SELECT_LINE_RESP_V02 0x0046
#define QMI_VOICE_AOC_RESET_ACM_REQ_V02 0x0047
#define QMI_VOICE_AOC_RESET_ACM_RESP_V02 0x0047
#define QMI_VOICE_AOC_SET_ACMMAX_REQ_V02 0x0048
#define QMI_VOICE_AOC_SET_ACMMAX_RESP_V02 0x0048
#define QMI_VOICE_AOC_GET_CALL_METER_INFO_REQ_V02 0x0049
#define QMI_VOICE_AOC_GET_CALL_METER_INFO_RESP_V02 0x0049
#define QMI_VOICE_AOC_LOW_FUNDS_IND_V02 0x004A
#define QMI_VOICE_GET_COLP_REQ_V02 0x004B
#define QMI_VOICE_GET_COLP_RESP_V02 0x004B
#define QMI_VOICE_GET_COLR_REQ_V02 0x004C
#define QMI_VOICE_GET_COLR_RESP_V02 0x004C
#define QMI_VOICE_GET_CNAP_REQ_V02 0x004D
#define QMI_VOICE_GET_CNAP_RESP_V02 0x004D
#define QMI_VOICE_MANAGE_IP_CALLS_REQ_V02 0x004E
#define QMI_VOICE_MANAGE_IP_CALLS_RESP_V02 0x004E
#define QMI_VOICE_ALS_GET_LINE_SWITCHING_STATUS_REQ_V02 0x004F
#define QMI_VOICE_ALS_GET_LINE_SWITCHING_STATUS_RESP_V02 0x004F
#define QMI_VOICE_ALS_GET_SELECTED_LINE_REQ_V02 0x0050
#define QMI_VOICE_ALS_GET_SELECTED_LINE_RESP_V02 0x0050
#define QMI_VOICE_MODIFIED_IND_V02 0x0051
#define QMI_VOICE_MODIFY_ACCEPT_IND_V02 0x0052
#define QMI_VOICE_SPEECH_CODEC_INFO_IND_V02 0x0053
#define QMI_VOICE_HANDOVER_IND_V02 0x0054
#define QMI_VOICE_CONFERENCE_INFO_IND_V02 0x0055
#define QMI_VOICE_CONFERENCE_JOIN_IND_V02 0x0056
#define QMI_VOICE_CONFERENCE_PARTICIPANT_UPDATE_IND_V02 0x0057
#define QMI_VOICE_EXT_BRST_INTL_IND_V02 0x0058
#define QMI_VOICE_MT_PAGE_MISS_IND_V02 0x0059
#define QMI_VOICE_CALL_CONTROL_RESULT_INFO_IND_V02 0x005A
#define QMI_VOICE_CONFERENCE_PARTICIPANTS_INFO_IND_V02 0x005B
#define QMI_VOICE_SETUP_ANSWER_REQ_V02 0x005C
#define QMI_VOICE_SETUP_ANSWER_RESP_V02 0x005C
#define QMI_VOICE_TTY_IND_V02 0x005D
#define QMI_VOICE_VIDEOSHARE_START_REQ_V02 0x005E
#define QMI_VOICE_VIDEOSHARE_START_RESP_V02 0x005E
#define QMI_VOICE_VIDEOSHARE_ANSWER_REQ_V02 0x005F
#define QMI_VOICE_VIDEOSHARE_ANSWER_RESP_V02 0x005F
#define QMI_VOICE_VIDEOSHARE_END_REQ_V02 0x0060
#define QMI_VOICE_VIDEOSHARE_END_RESP_V02 0x0060
#define QMI_VOICE_VIDEOSHARE_STATUS_IND_V02 0x0061
#define QMI_VOICE_ADDITIONAL_CALL_INFO_IND_V02 0x0062
#define QMI_VOICE_AUDIO_RAT_CHANGE_INFO_IND_V02 0x0063
#define QMI_VOICE_CONF_PARTICIPANT_STATUS_INFO_IND_V02 0x0066
#define QMI_VOICE_SECURE_CALL_MODE_REQ_V02 0x0067
#define QMI_VOICE_SECURE_CALL_MODE_RESP_V02 0x0067
#define QMI_VOICE_SET_WWAN_911_TIMER_REQ_V02 0x0068
#define QMI_VOICE_SET_WWAN_911_TIMER_RESP_V02 0x0068
#define QMI_VOICE_GET_WWAN_911_TIMER_REQ_V02 0x0069
#define QMI_VOICE_GET_WWAN_911_TIMER_RESP_V02 0x0069
#define QMI_VOICE_ECALL_STATUS_IND_V02 0x006A
#define QMI_VOICE_CALL_REESTABLISHMENT_STATUS_IND_V02 0x006B
#define QMI_VOICE_VICE_DIALOG_INFO_IND_V02 0x006C
#define QMI_VOICE_CALL_ENCRYPTION_REQ_V02 0x006D
#define QMI_VOICE_CALL_ENCRYPTION_RESP_V02 0x006D
#define QMI_VOICE_GET_SPEECH_CODEC_INFO_REQ_V02 0x006E
#define QMI_VOICE_GET_SPEECH_CODEC_INFO_RESP_V02 0x006E
#define QMI_VOICE_IMS_CALL_CANCEL_REQ_V02 0x006F
#define QMI_VOICE_IMS_CALL_CANCEL_RESP_V02 0x006F
#define QMI_VOICE_AVOID_PLMN_LIST_REQ_V02 0x0070
#define QMI_VOICE_AVOID_PLMN_LIST_RESP_V02 0x0070
#define QMI_VOICE_SET_ECALL_OPRT_MODE_REQ_V02 0x0071
#define QMI_VOICE_SET_ECALL_OPRT_MODE_RESP_V02 0x0071
#define QMI_VOICE_GET_ECALL_OPRT_MODE_REQ_V02 0x0072
#define QMI_VOICE_GET_ECALL_OPRT_MODE_RESP_V02 0x0072
#define QMI_VOICE_ECALL_OPRT_MODE_IND_V02 0x0073
#define QMI_AUTO_REJECTED_INCOMING_CALL_END_IND_V02 0x0074
/**
    @}
  */

/* Service Object Accessor */
/** @addtogroup wms_qmi_accessor
    @{
  */
/** This function is used internally by the autogenerated code.  Clients should use the
   macro voice_get_service_object_v02( ) that takes in no arguments. */
qmi_idl_service_object_type voice_get_service_object_internal_v02
 ( int32_t idl_maj_version, int32_t idl_min_version, int32_t library_version );

/** This macro should be used to get the service object */
#define voice_get_service_object_v02( ) \
          voice_get_service_object_internal_v02( \
            VOICE_V02_IDL_MAJOR_VERS, VOICE_V02_IDL_MINOR_VERS, \
            VOICE_V02_IDL_TOOL_VERS )
/**
    @}
  */


#ifdef __cplusplus
}
#endif
#endif

