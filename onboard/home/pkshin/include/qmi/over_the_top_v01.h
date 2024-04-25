#ifndef OTT_SERVICE_01_H
#define OTT_SERVICE_01_H
/**
  @file over_the_top_v01.h

  @brief This is the public header file which defines the ott service Data structures.

  This header file defines the types and structures that were defined in
  ott. It contains the constant values defined, enums, structures,
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
  Copyright (c) 2018 Qualcomm Technologies, Inc.
  All rights reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.



  $Header: //commercial/MPSS.HE.1.0.c1.3/Main/modem_proc/qmimsgs/ott/api/over_the_top_v01.h#1 $
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
 *THIS IS AN AUTO GENERATED FILE. DO NOT ALTER IN ANY WAY
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/* This file was generated with Tool version 6.14.7 
   It was generated on: Tue Mar 20 2018 (Spin 0)
   From IDL File: over_the_top_v01.idl */

/** @defgroup ott_qmi_consts Constant values defined in the IDL */
/** @defgroup ott_qmi_msg_ids Constant values for QMI message IDs */
/** @defgroup ott_qmi_enums Enumerated types used in QMI messages */
/** @defgroup ott_qmi_messages Structures sent as QMI messages */
/** @defgroup ott_qmi_aggregates Aggregate types used in QMI messages */
/** @defgroup ott_qmi_accessor Accessor for QMI service object */
/** @defgroup ott_qmi_version Constant values for versioning information */

#include <stdint.h>
#include "qmi_idl_lib.h"
#include "common_v01.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup ott_qmi_version
    @{
  */
/** Major Version Number of the IDL used to generate this file */
#define OTT_V01_IDL_MAJOR_VERS 0x01
/** Revision Number of the IDL used to generate this file */
#define OTT_V01_IDL_MINOR_VERS 0x02
/** Major Version Number of the qmi_idl_compiler used to generate this file */
#define OTT_V01_IDL_TOOL_VERS 0x06
/** Maximum Defined Message ID */
#define OTT_V01_MAX_MESSAGE_ID 0x002D
/**
    @}
  */


/** @addtogroup ott_qmi_consts
    @{
  */
#define QMI_OTT_UL_THRESHOLD_LIST_LEN_V01 20
#define QMI_OTT_DL_THRESHOLD_LIST_LEN_V01 20
/**
    @}
  */

/** @addtogroup ott_qmi_enums
    @{
  */
typedef enum {
  OTT_BIND_SUBSCRIPTION_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  OTT_DEFAULT_SUBS_V01 = 0x0000, /**<  Default data subscription \n  */
  OTT_PRIMARY_SUBS_V01 = 0x0001, /**<  Primary \n  */
  OTT_SECONDARY_SUBS_V01 = 0x0002, /**<  Secondary \n  */
  OTT_TERTIARY_SUBS_V01 = 0x0003, /**<  Tertiary \n  */
  OTT_DONT_CARE_SUBS_V01 = 0x00FF, /**<  Default value used in the absence of
       explicit binding */
  OTT_BIND_SUBSCRIPTION_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}ott_bind_subscription_enum_v01;
/**
    @}
  */

/** @addtogroup ott_qmi_enums
    @{
  */
typedef enum {
  OTT_RAT_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  OTT_RAT_WCDMA_V01 = 0x01, 
  OTT_RAT_LTE_V01 = 0x02, 
  OTT_RAT_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}ott_rat_enum_type_v01;
/**
    @}
  */

/** @addtogroup ott_qmi_enums
    @{
  */
typedef enum {
  OTT_THRESHOLD_ACTION_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  OTT_THRESHOLD_ACTION_STOP_V01 = 0x01, 
  OTT_THRESHOLD_ACTION_START_V01 = 0x02, 
  OTT_THRESHOLD_ACTION_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}ott_threshold_action_type_v01;
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Request Message; Binds the control point to the specified subscription. */
typedef struct {

  /* Mandatory */
  /*  Subscription Identifier */
  ott_bind_subscription_enum_v01 subscription;
  /**<   Subscription to which the client is bound.
 Values: \n
      - OTT_DEFAULT_SUBS (0x0000) --  Default data subscription \n 
      - OTT_PRIMARY_SUBS (0x0001) --  Primary \n 
      - OTT_SECONDARY_SUBS (0x0002) --  Secondary \n 
      - OTT_TERTIARY_SUBS (0x0003) --  Tertiary \n 
      - OTT_DONT_CARE_SUBS (0x00FF) --  Default value used in the absence of
       explicit binding
 */
}ott_bind_subscription_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Response Message; Binds the control point to the specified subscription. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}ott_bind_subscription_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Request Message; Queries for the current subscription of the control point. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}ott_get_bind_subscription_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Response Message; Queries for the current subscription of the control point. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Subscription */
  uint8_t subscription_valid;  /**< Must be set to true if subscription is being passed */
  ott_bind_subscription_enum_v01 subscription;
  /**<   Subscription to which the client is bound.
 Values: \n
      - OTT_DEFAULT_SUBS (0x0000) --  Default data subscription \n 
      - OTT_PRIMARY_SUBS (0x0001) --  Primary \n 
      - OTT_SECONDARY_SUBS (0x0002) --  Secondary \n 
      - OTT_TERTIARY_SUBS (0x0003) --  Tertiary \n 
      - OTT_DONT_CARE_SUBS (0x00FF) --  Default value used in the absence of
       explicit binding
 */
}ott_get_bind_subscription_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Request Message; Sets the registration state for different QMI_OTT indications
           for the requesting control point. */
typedef struct {

  /* Optional */
  /*  Report UL Throughput Reporting Status Change */
  uint8_t report_ul_thrpt_reporting_status_change_valid;  /**< Must be set to true if report_ul_thrpt_reporting_status_change is being passed */
  uint8_t report_ul_thrpt_reporting_status_change;
  /**<   Values:  \n
       - 0 -- Do not report \n
       - 1 -- Report uplink throughput reporting status change
  */

  /* Optional */
  /*  Report UL Throughput Information */
  uint8_t report_ul_thrpt_info_valid;  /**< Must be set to true if report_ul_thrpt_info is being passed */
  uint8_t report_ul_thrpt_info;
  /**<   Values:  \n
       - 0 -- Do not report \n
       - 1 -- Report uplink throughput information
  */

  /* Optional */
  /*  Report DL Throughput Reporting Status Change */
  uint8_t report_dl_thrpt_reporting_status_change_valid;  /**< Must be set to true if report_dl_thrpt_reporting_status_change is being passed */
  uint8_t report_dl_thrpt_reporting_status_change;
  /**<   Values:  \n
       - 0 -- Do not report \n
       - 1 -- Report downlink throughput reporting status change
  */

  /* Optional */
  /*  Report Downlink Throughput Information */
  uint8_t report_dl_thrpt_info_valid;  /**< Must be set to true if report_dl_thrpt_info is being passed */
  uint8_t report_dl_thrpt_info;
  /**<   Values:  \n
       - 0 -- Do not report \n
       - 1 -- Report downlink throughput information
  */
}ott_indication_register_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Response Message; Sets the registration state for different QMI_OTT indications
           for the requesting control point. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}ott_indication_register_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Request Message; Configures the uplink throughput settings. */
typedef struct {

  /* Optional */
  /*  Uplink Throughput Reporting Period */
  uint8_t ul_throughput_report_period_valid;  /**< Must be set to true if ul_throughput_report_period is being passed */
  uint32_t ul_throughput_report_period;
  /**<   Period at which the uplink throughput information
       is calculated in milliseconds.
  */

  /* Optional */
  /*  Report Uplink Queue Size */
  uint8_t report_ul_queue_size_valid;  /**< Must be set to true if report_ul_queue_size is being passed */
  uint8_t report_ul_queue_size;
  /**<   Reports the uplink queue size and the uplink throughput.
  */

  /* Optional */
  /*  RAT Type */
  uint8_t rat_type_valid;  /**< Must be set to true if rat_type is being passed */
  ott_rat_enum_type_v01 rat_type;
  /**<   RAT Type. Must be present if one or more of Uplink Throughput 
 Hysteresis Time, Uplink Throughput Hysteresis Magnitude Change, 
 Uplink Throughput Threshold List TLVs are present.
 Values:\n
      - OTT_RAT_WCDMA (0x01) -- 
      - OTT_RAT_LTE (0x02) -- 
 */

  /* Optional */
  /*  Uplink Throughput Hysteresis Time */
  uint8_t ul_throughput_hyst_time_valid;  /**< Must be set to true if ul_throughput_hyst_time is being passed */
  uint32_t ul_throughput_hyst_time;
  /**<   Time in millisecs that will prevent reporting even if the 
       throughput value crosses the thresholds within the specified time.
       A zero value means modem excludes this TLV from the throughput 
       reporting calculation.
  */

  /* Optional */
  /*  Uplink Throughput Hysteresis Magnitude Change */
  uint8_t ul_throughput_hyst_mag_chng_size_valid;  /**< Must be set to true if ul_throughput_hyst_mag_chng_size is being passed */
  uint32_t ul_throughput_hyst_mag_chng_size;
  /**<   The difference in kbps which prevents reporting if the magnitude
       of change between two reports is less than the specified value.
       A zero value means modem excludes this TLV from the throughput
       reporting calculation. 
  */

  /* Optional */
  /*  Uplink Throughput Threshold List */
  uint8_t ul_throughput_threshold_list_valid;  /**< Must be set to true if ul_throughput_threshold_list is being passed */
  uint32_t ul_throughput_threshold_list_len;  /**< Must be set to # of elements in ul_throughput_threshold_list */
  uint32_t ul_throughput_threshold_list[QMI_OTT_UL_THRESHOLD_LIST_LEN_V01];
  /**<   List of threshold values in kbps that trigger uplink reporting.
       A zero value means modem excludes this TLV from the throughput 
       reporting calculation.
  */

  /* Optional */
  /*  Uplink Threshold Action */
  uint8_t ul_threshold_action_valid;  /**< Must be set to true if ul_threshold_action is being passed */
  ott_threshold_action_type_v01 ul_threshold_action;
  /**<   Action for uplink threshold reporting. Absence of this TLV means 
 modem continues with previously configured action.
 Values:\n
      - OTT_THRESHOLD_ACTION_STOP (0x01) -- 
      - OTT_THRESHOLD_ACTION_START (0x02) -- 
 */
}ott_configure_uplink_throughput_settings_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Response Message; Configures the uplink throughput settings. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}ott_configure_uplink_throughput_settings_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ott_qmi_enums
    @{
  */
typedef enum {
  OTT_THRPT_STATUS_REASON_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  OTT_THRPT_REPORT_ENABLED_V01 = 0, /**<  Throughput reporting enabled \n  */
  OTT_THRPT_REPORT_DISABLED_NO_DATA_CALL_V01 = 1, /**<  No data call \n  */
  OTT_THRPT_REPORT_DISABLED_ALL_CALLS_DORMANT_V01 = 2, /**<  All calls dormant \n  */
  OTT_THRPT_REPORT_DISABLED_UNSUPPORTED_RAT_V01 = 3, /**<  Unsupported RAT  */
  OTT_THRPT_REPORT_DISABLED_BY_CLIENT_V01 = 4, /**<  Report disabled by client  */
  OTT_THRPT_STATUS_REASON_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}ott_thrpt_status_reason_enum_v01;
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Indication Message; Indicates a change in uplink throughput reporting status. */
typedef struct {

  /* Optional */
  /*  Reporting Status  */
  uint8_t reporting_status_valid;  /**< Must be set to true if reporting_status is being passed */
  ott_thrpt_status_reason_enum_v01 reporting_status;
  /**<   Reporting status
      - OTT_THRPT_REPORT_ENABLED (0) --  Throughput reporting enabled \n 
      - OTT_THRPT_REPORT_DISABLED_NO_DATA_CALL (1) --  No data call \n 
      - OTT_THRPT_REPORT_DISABLED_ALL_CALLS_DORMANT (2) --  All calls dormant \n 
      - OTT_THRPT_REPORT_DISABLED_UNSUPPORTED_RAT (3) --  Unsupported RAT 
      - OTT_THRPT_REPORT_DISABLED_BY_CLIENT (4) --  Report disabled by client 
 */

  /* Optional */
  /*  Actual Interval */
  uint8_t actual_interval_valid;  /**< Must be set to true if actual_interval is being passed */
  uint32_t actual_interval;
  /**<   Uplink throughput interval in milliseconds.
  */

  /* Optional */
  /*  RAT Type */
  uint8_t rat_type_valid;  /**< Must be set to true if rat_type is being passed */
  ott_rat_enum_type_v01 rat_type;
  /**<   RAT Type.
 Values:\n
      - OTT_RAT_WCDMA (0x01) -- 
      - OTT_RAT_LTE (0x02) -- 
 */

  /* Optional */
  /*  Actual Uplink Throughput Hysteresis Time */
  uint8_t actual_ul_throughput_hyst_time_valid;  /**< Must be set to true if actual_ul_throughput_hyst_time is being passed */
  uint32_t actual_ul_throughput_hyst_time;
  /**<   Time in millisecs that will prevent reporting even if the 
       throughput value crosses the thresholds within the specified time.
       A zero value means modem excludes this TLV from the throughput
       reporting calculation.
  */

  /* Optional */
  /*  Actual Uplink Throughput Hysteresis Magnitude Change */
  uint8_t actual_ul_throughput_hyst_mag_chng_size_valid;  /**< Must be set to true if actual_ul_throughput_hyst_mag_chng_size is being passed */
  uint32_t actual_ul_throughput_hyst_mag_chng_size;
  /**<   The difference in kbps which prevents reporting if the magnitude
       of change between two reports is less than the specified value.
       A zero value means modem excludes this TLV from the throughput
       reporting calculation. 
  */

  /* Optional */
  /*  Actual Uplink Throughput Threshold List */
  uint8_t actual_ul_throughput_threshold_list_valid;  /**< Must be set to true if actual_ul_throughput_threshold_list is being passed */
  uint32_t actual_ul_throughput_threshold_list_len;  /**< Must be set to # of elements in actual_ul_throughput_threshold_list */
  uint32_t actual_ul_throughput_threshold_list[QMI_OTT_UL_THRESHOLD_LIST_LEN_V01];
  /**<   List of threshold values in kbps that trigger uplink reporting.
  */
}ott_uplink_throughput_reporting_status_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Request Message; Queries for the uplink throughout reporting status. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}ott_query_uplink_throughput_reporting_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Response Message; Queries for the uplink throughout reporting status. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Reporting Status  */
  uint8_t reporting_status_valid;  /**< Must be set to true if reporting_status is being passed */
  ott_thrpt_status_reason_enum_v01 reporting_status;
  /**<   Reporting status
      - OTT_THRPT_REPORT_ENABLED (0) --  Throughput reporting enabled \n 
      - OTT_THRPT_REPORT_DISABLED_NO_DATA_CALL (1) --  No data call \n 
      - OTT_THRPT_REPORT_DISABLED_ALL_CALLS_DORMANT (2) --  All calls dormant \n 
      - OTT_THRPT_REPORT_DISABLED_UNSUPPORTED_RAT (3) --  Unsupported RAT 
      - OTT_THRPT_REPORT_DISABLED_BY_CLIENT (4) --  Report disabled by client 
 */

  /* Optional */
  /*  Actual Interval */
  uint8_t actual_interval_valid;  /**< Must be set to true if actual_interval is being passed */
  uint32_t actual_interval;
  /**<   The actual interval at which throughput is generated.      
  */

  /* Optional */
  /*  RAT Type */
  uint8_t rat_type_valid;  /**< Must be set to true if rat_type is being passed */
  ott_rat_enum_type_v01 rat_type;
  /**<   RAT Type.
 Values:\n
      - OTT_RAT_WCDMA (0x01) -- 
      - OTT_RAT_LTE (0x02) -- 
 */

  /* Optional */
  /*  Actual Uplink Throughput Hysteresis Time */
  uint8_t actual_ul_throughput_hyst_time_valid;  /**< Must be set to true if actual_ul_throughput_hyst_time is being passed */
  uint32_t actual_ul_throughput_hyst_time;
  /**<   Time in millisecs that will prevent reporting even if the 
        throughput value crosses the thresholds within the specified time.
        A zero value means modem excludes this TLV from the throughput
       reporting calculation.
  */

  /* Optional */
  /*  Actual Uplink Throughput Hysteresis Magnitude Change */
  uint8_t actual_ul_throughput_hyst_mag_chng_size_valid;  /**< Must be set to true if actual_ul_throughput_hyst_mag_chng_size is being passed */
  uint32_t actual_ul_throughput_hyst_mag_chng_size;
  /**<   The difference in kbps which prevents reporting if the magnitude
       of change between two reports is less than the specified value.
       A zero value means modem excludes this TLV from the throughput
       reporting calculation. 
  */

  /* Optional */
  /*  Actual Uplink Throughput Threshold List */
  uint8_t actual_ul_throughput_threshold_list_valid;  /**< Must be set to true if actual_ul_throughput_threshold_list is being passed */
  uint32_t actual_ul_throughput_threshold_list_len;  /**< Must be set to # of elements in actual_ul_throughput_threshold_list */
  uint32_t actual_ul_throughput_threshold_list[QMI_OTT_UL_THRESHOLD_LIST_LEN_V01];
  /**<   List of threshold values in kbps that trigger uplink reporting.
  */
}ott_query_uplink_throughput_reporting_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Indication Message; Indicates the uplink throughput information.  */
typedef struct {

  /* Optional */
  /*  Uplink Rate */
  uint8_t uplink_rate_valid;  /**< Must be set to true if uplink_rate is being passed */
  uint32_t uplink_rate;
  /**<   The uplink rate per UE in kbps. The uplink rate is the sum of
       served and allowed rates.
  */

  /* Optional */
  /*  Confidence Level */
  uint8_t confidence_level_valid;  /**< Must be set to true if confidence_level is being passed */
  uint8_t confidence_level;
  /**<   Level of accuracy at which the throughput information
       is generated on a scale of 0 through 7. 0 indicates the least 
       reporting accuracy and 7 indicates the highest reporting accuracy.
  */

  /* Optional */
  /*  Uplink Queue Size */
  uint8_t uplink_queue_size_valid;  /**< Must be set to true if uplink_queue_size is being passed */
  uint32_t uplink_queue_size;
  /**<   The uplink queue size in bytes.
  */
}ott_uplink_throughput_info_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Request Message; Queries for the OTT uplink throughput information. */
typedef struct {

  /* Optional */
  /*  Report Uplink Queue Size */
  uint8_t report_ul_queue_size_valid;  /**< Must be set to true if report_ul_queue_size is being passed */
  uint8_t report_ul_queue_size;
  /**<   Reports the uplink queue size and the uplink throughput.
  */
}ott_query_uplink_throughput_info_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Response Message; Queries for the OTT uplink throughput information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Uplink Rate */
  uint8_t uplink_rate_valid;  /**< Must be set to true if uplink_rate is being passed */
  uint32_t uplink_rate;
  /**<   The uplink rate per UE in kbps. The uplink rate is the sum of
       served and allowed rates.
  */

  /* Optional */
  /*  Confidence Level */
  uint8_t confidence_level_valid;  /**< Must be set to true if confidence_level is being passed */
  uint8_t confidence_level;
  /**<   Level of accuracy at which the throughput information
       is generated on a scale of 0 through 7. 0 indicates the least 
       reporting accuracy and 7 indicates the highest reporting accuracy.
  */

  /* Optional */
  /*  Uplink Queue Size */
  uint8_t uplink_queue_size_valid;  /**< Must be set to true if uplink_queue_size is being passed */
  uint32_t uplink_queue_size;
  /**<   The uplink queue size in bytes.
  */
}ott_query_uplink_throughput_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Request Message; Configures the downlink throughput settings. */
typedef struct {

  /* Optional */
  /*  Downlink Throughput Reporting Period */
  uint8_t dl_throughput_report_period_valid;  /**< Must be set to true if dl_throughput_report_period is being passed */
  uint32_t dl_throughput_report_period;
  /**<   Period at which the downlink throughput information
       is calculated in milliseconds.
  */

  /* Optional */
  /*  RAT Type */
  uint8_t rat_type_valid;  /**< Must be set to true if rat_type is being passed */
  ott_rat_enum_type_v01 rat_type;
  /**<   RAT Type. Must be present if one or more of Downlink Throughput 
 Hysteresis Time, Downlink Throughput Hysteresis Magnitude Change, 
 Downlink Throughput Threshold List TLVs are present.
 Values:\n
      - OTT_RAT_WCDMA (0x01) -- 
      - OTT_RAT_LTE (0x02) -- 
 */

  /* Optional */
  /*  Downlink Throughput Hysteresis Time */
  uint8_t dl_throughput_hyst_time_valid;  /**< Must be set to true if dl_throughput_hyst_time is being passed */
  uint32_t dl_throughput_hyst_time;
  /**<   Time in millisecs that will prevent reporting even if the 
        throughput value crosses the thresholds within the specified time.
        A zero value means modem excludes this TLV from the throughput
       reporting calculation.
  */

  /* Optional */
  /*  Downlink Throughput Hysteresis Magnitude Change */
  uint8_t dl_throughput_hyst_mag_chng_size_valid;  /**< Must be set to true if dl_throughput_hyst_mag_chng_size is being passed */
  uint32_t dl_throughput_hyst_mag_chng_size;
  /**<   The difference in kbps which prevents reporting if the magnitude
       of change between two reports is less than the specified value.
       A zero value means modem excludes this TLV from the throughput
       reporting calculation. 
  */

  /* Optional */
  /*  Downlink Throughput Threshold List */
  uint8_t dl_throughput_threshold_list_valid;  /**< Must be set to true if dl_throughput_threshold_list is being passed */
  uint32_t dl_throughput_threshold_list_len;  /**< Must be set to # of elements in dl_throughput_threshold_list */
  uint32_t dl_throughput_threshold_list[QMI_OTT_DL_THRESHOLD_LIST_LEN_V01];
  /**<   List of threshold values in kbps that trigger uplink reporting.
  */

  /* Optional */
  /*  Downlink Threshold Action */
  uint8_t dl_threshold_action_valid;  /**< Must be set to true if dl_threshold_action is being passed */
  ott_threshold_action_type_v01 dl_threshold_action;
  /**<   Action for downlink threshold reporting. Absence of this TLV means 
 modem continues with previously configured action.
 Values:\n
      - OTT_THRESHOLD_ACTION_STOP (0x01) -- 
      - OTT_THRESHOLD_ACTION_START (0x02) -- 
 */
}ott_configure_downlink_throughput_settings_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Response Message; Configures the downlink throughput settings. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}ott_configure_downlink_throughput_settings_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Indication Message; Indicates downlink throughput reporting status. */
typedef struct {

  /* Optional */
  /*  Reporting Status  */
  uint8_t reporting_status_valid;  /**< Must be set to true if reporting_status is being passed */
  ott_thrpt_status_reason_enum_v01 reporting_status;
  /**<   Reporting status
      - OTT_THRPT_REPORT_ENABLED (0) --  Throughput reporting enabled \n 
      - OTT_THRPT_REPORT_DISABLED_NO_DATA_CALL (1) --  No data call \n 
      - OTT_THRPT_REPORT_DISABLED_ALL_CALLS_DORMANT (2) --  All calls dormant \n 
      - OTT_THRPT_REPORT_DISABLED_UNSUPPORTED_RAT (3) --  Unsupported RAT 
      - OTT_THRPT_REPORT_DISABLED_BY_CLIENT (4) --  Report disabled by client 
 */

  /* Optional */
  /*  Actual Interval */
  uint8_t actual_interval_valid;  /**< Must be set to true if actual_interval is being passed */
  uint32_t actual_interval;
  /**<   The actual interval at which throughput is generated.      
  */

  /* Optional */
  /*  RAT Type */
  uint8_t rat_type_valid;  /**< Must be set to true if rat_type is being passed */
  ott_rat_enum_type_v01 rat_type;
  /**<   RAT Type.
 Values:\n
      - OTT_RAT_WCDMA (0x01) -- 
      - OTT_RAT_LTE (0x02) -- 
 */

  /* Optional */
  /*  Actual Downlink Throughput Hysteresis Time */
  uint8_t actual_dl_throughput_hyst_time_valid;  /**< Must be set to true if actual_dl_throughput_hyst_time is being passed */
  uint32_t actual_dl_throughput_hyst_time;
  /**<   Time in millisecs that will prevent reporting even if the 
        throughput value crosses the thresholds within the specified time.
        A zero value means modem excludes this TLV from the throughput
       reporting calculation.
  */

  /* Optional */
  /*  Actual Downlink Throughput Hysteresis Magnitude Change */
  uint8_t actual_dl_throughput_hyst_mag_chng_size_valid;  /**< Must be set to true if actual_dl_throughput_hyst_mag_chng_size is being passed */
  uint32_t actual_dl_throughput_hyst_mag_chng_size;
  /**<   The difference in kbps which prevents reporting if the magnitude
       of change between two reports is less than the specified value.
       A zero value means modem excludes this TLV from the throughput
       reporting calculation. 
  */

  /* Optional */
  /*  Actual Downlink Throughput Threshold List */
  uint8_t actual_dl_throughput_threshold_list_valid;  /**< Must be set to true if actual_dl_throughput_threshold_list is being passed */
  uint32_t actual_dl_throughput_threshold_list_len;  /**< Must be set to # of elements in actual_dl_throughput_threshold_list */
  uint32_t actual_dl_throughput_threshold_list[QMI_OTT_DL_THRESHOLD_LIST_LEN_V01];
  /**<   List of threshold values in kbps that trigger downlink reporting.
  */
}ott_downlink_throughput_reporting_status_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Request Message; Queries for the downlink throughout reporting status. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}ott_query_downlink_throughput_reporting_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Response Message; Queries for the downlink throughout reporting status. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Reporting Status  */
  uint8_t reporting_status_valid;  /**< Must be set to true if reporting_status is being passed */
  ott_thrpt_status_reason_enum_v01 reporting_status;
  /**<   Reporting status
      - OTT_THRPT_REPORT_ENABLED (0) --  Throughput reporting enabled \n 
      - OTT_THRPT_REPORT_DISABLED_NO_DATA_CALL (1) --  No data call \n 
      - OTT_THRPT_REPORT_DISABLED_ALL_CALLS_DORMANT (2) --  All calls dormant \n 
      - OTT_THRPT_REPORT_DISABLED_UNSUPPORTED_RAT (3) --  Unsupported RAT 
      - OTT_THRPT_REPORT_DISABLED_BY_CLIENT (4) --  Report disabled by client 
 */

  /* Optional */
  /*  Actual Interval */
  uint8_t actual_interval_valid;  /**< Must be set to true if actual_interval is being passed */
  uint32_t actual_interval;
  /**<   The actual interval at which throughput is generated.      
  */

  /* Optional */
  /*  RAT Type */
  uint8_t rat_type_valid;  /**< Must be set to true if rat_type is being passed */
  ott_rat_enum_type_v01 rat_type;
  /**<   RAT Type.
 Values:\n
      - OTT_RAT_WCDMA (0x01) -- 
      - OTT_RAT_LTE (0x02) -- 
 */

  /* Optional */
  /*  Actual Downlink Throughput Hysteresis Time */
  uint8_t actual_dl_throughput_hyst_time_valid;  /**< Must be set to true if actual_dl_throughput_hyst_time is being passed */
  uint32_t actual_dl_throughput_hyst_time;
  /**<   Time in millisecs that will prevent reporting even if the 
        throughput value crosses the thresholds within the specified time.
        A zero value means modem excludes this TLV from the throughput
       reporting calculation.
  */

  /* Optional */
  /*  Actual Downlink Throughput Hysteresis Magnitude Change */
  uint8_t actual_dl_throughput_hyst_mag_chng_size_valid;  /**< Must be set to true if actual_dl_throughput_hyst_mag_chng_size is being passed */
  uint32_t actual_dl_throughput_hyst_mag_chng_size;
  /**<   The difference in kbps which prevents reporting if the magnitude
       of change between two reports is less than the specified value.
       A zero value means modem excludes this TLV from the throughput
       reporting calculation. 
  */

  /* Optional */
  /*  Actual Downlink Throughput Threshold List */
  uint8_t actual_dl_throughput_threshold_list_valid;  /**< Must be set to true if actual_dl_throughput_threshold_list is being passed */
  uint32_t actual_dl_throughput_threshold_list_len;  /**< Must be set to # of elements in actual_dl_throughput_threshold_list */
  uint32_t actual_dl_throughput_threshold_list[QMI_OTT_UL_THRESHOLD_LIST_LEN_V01];
  /**<   List of threshold values in kbps that trigger uplink reporting.
  */
}ott_query_downlink_throughput_reporting_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Indication Message; Indicates downlink throughput information. */
typedef struct {

  /* Optional */
  /*  Downlink Rate */
  uint8_t downlink_rate_valid;  /**< Must be set to true if downlink_rate is being passed */
  uint32_t downlink_rate;
  /**<   The downlink rate per UE in kbps. The downlink rate is the sum of
       served and allowed rates.
  */

  /* Optional */
  /*  Confidence Level */
  uint8_t confidence_level_valid;  /**< Must be set to true if confidence_level is being passed */
  uint8_t confidence_level;
  /**<   Level of accuracy at which the throughput information
       is generated on a scale of 0 through 7. 0 indicates the least 
       reporting accuracy and 7 indicates the highest reporting accuracy.
  */

  /* Optional */
  /*  Suspend Flag */
  uint8_t is_suspended_valid;  /**< Must be set to true if is_suspended is being passed */
  uint8_t is_suspended;
  /**<   Values: \n
       - 0 -- FALSE; downlink throughput reporting is enabled (default) \n       
       - 1 -- TRUE; flag indicating that downlink throughput reporting is suspended 
  */
}ott_downlink_throughput_info_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Request Message; Queries for the downlink throughout information. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}ott_get_downlink_throughput_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Response Message; Queries for the downlink throughout information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Downlink Rate */
  uint8_t downlink_rate_valid;  /**< Must be set to true if downlink_rate is being passed */
  uint32_t downlink_rate;
  /**<   The downlink rate per UE in kbps. The downlink rate is the sum of
       served and allowed rates.
  */

  /* Optional */
  /*  Confidence Level */
  uint8_t confidence_level_valid;  /**< Must be set to true if confidence_level is being passed */
  uint8_t confidence_level;
  /**<   Level of accuracy at which the throughput information
       is generated on a scale of 0 through 7. 0 indicates the least 
       reporting accuracy and 7 indicates the highest reporting accuracy.
  */
}ott_get_downlink_throughput_info_resp_msg_v01;  /* Message */
/**
    @}
  */

typedef uint64_t ott_capability_mask_v01;
#define OTT_MASK_UL_THROUGHPUT_REPORT_V01 ((ott_capability_mask_v01)0x01ull) 
#define OTT_MASK_DL_THROUGHPUT_REPORT_V01 ((ott_capability_mask_v01)0x02ull) 
typedef uint64_t ott_ul_capability_mask_v01;
#define OTT_UL_THROUGHPUT_REPORT_BY_THRESHOLD_V01 ((ott_ul_capability_mask_v01)0x01ull) 
typedef uint64_t ott_dl_capability_mask_v01;
#define OTT_DL_THROUGHPUT_REPORT_BY_THRESHOLD_V01 ((ott_dl_capability_mask_v01)0x01ull) 
/** @addtogroup ott_qmi_messages
    @{
  */
/** Request Message; Queries the modem capabilities. */
typedef struct {

  /* Mandatory */
  /*  Requested Capability */
  ott_capability_mask_v01 req_capability_mask;
  /**<   Capability. Values: \n
      - OTT_MASK_UL_THROUGHPUT_REPORT (0x01) -- 
      - OTT_MASK_DL_THROUGHPUT_REPORT (0x02) -- 
 */
}ott_get_capabilities_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup ott_qmi_messages
    @{
  */
/** Response Message; Queries the modem capabilities. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Uplink Throughput Capability */
  uint8_t ul_capability_valid;  /**< Must be set to true if ul_capability is being passed */
  ott_ul_capability_mask_v01 ul_capability;
  /**<   Uplink throughput capability. Values: \n
      - OTT_UL_THROUGHPUT_REPORT_BY_THRESHOLD (0x01) -- 
 */

  /* Optional */
  /*  Downlink Throughput Capability */
  uint8_t dl_capability_valid;  /**< Must be set to true if dl_capability is being passed */
  ott_dl_capability_mask_v01 dl_capability;
  /**<   Downlink throughput capability. Values: \n
      - OTT_DL_THROUGHPUT_REPORT_BY_THRESHOLD (0x01) -- 
 */
}ott_get_capabilities_resp_msg_v01;  /* Message */
/**
    @}
  */

/* Conditional compilation tags for message removal */ 
//#define REMOVE_QMI_OTT_BIND_SUBSCRIPTION_V01 
//#define REMOVE_QMI_OTT_CONFIGURE_DOWNLINK_THROUGHPUT_SETTINGS_V01 
//#define REMOVE_QMI_OTT_CONFIGURE_UPLINK_THROUGHPUT_SETTINGS_V01 
//#define REMOVE_QMI_OTT_DOWNLINK_THROUGHPUT_INFO_IND_V01 
//#define REMOVE_QMI_OTT_DOWNLINK_THROUGHPUT_REPORTING_STATUS_IND_V01 
//#define REMOVE_QMI_OTT_GET_BIND_SUBSCRIPTION_V01 
//#define REMOVE_QMI_OTT_GET_CAPABILITIES_V01 
//#define REMOVE_QMI_OTT_GET_DOWNLINK_THROUGHPUT_INFO_V01 
//#define REMOVE_QMI_OTT_INDICATION_REGISTER_V01 
//#define REMOVE_QMI_OTT_QUERY_DOWNLINK_THROUGHPUT_REPORTING_STATUS_V01 
//#define REMOVE_QMI_OTT_QUERY_UPLINK_THROUGHPUT_INFO_V01 
//#define REMOVE_QMI_OTT_QUERY_UPLINK_THROUGHPUT_REPORTING_STATUS_V01 
//#define REMOVE_QMI_OTT_UPLINK_THROUGHPUT_INFO_IND_V01 
//#define REMOVE_QMI_OTT_UPLINK_THROUGHPUT_REPORTING_STATUS_IND_V01 

/*Service Message Definition*/
/** @addtogroup ott_qmi_msg_ids
    @{
  */
#define QMI_OTT_BIND_SUBSCRIPTION_REQ_V01 0x0020
#define QMI_OTT_BIND_SUBSCRIPTION_RESP_V01 0x0020
#define QMI_OTT_GET_BIND_SUBSCRIPTION_REQ_V01 0x0021
#define QMI_OTT_GET_BIND_SUBSCRIPTION_RESP_V01 0x0021
#define QMI_OTT_INDICATION_REGISTER_REQ_V01 0x0022
#define QMI_OTT_INDICATION_REGISTER_RESP_V01 0x0022
#define QMI_OTT_CONFIGURE_UPLINK_THROUGHPUT_SETTINGS_REQ_V01 0x0023
#define QMI_OTT_CONFIGURE_UPLINK_THROUGHPUT_SETTINGS_RESP_V01 0x0023
#define QMI_OTT_UPLINK_THROUGHPUT_REPORTING_STATUS_IND_V01 0x0024
#define QMI_OTT_QUERY_UPLINK_THROUGHPUT_REPORTING_STATUS_REQ_V01 0x0025
#define QMI_OTT_QUERY_UPLINK_THROUGHPUT_REPORTING_STATUS_RESP_V01 0x0025
#define QMI_OTT_UPLINK_THROUGHPUT_INFO_IND_V01 0x0026
#define QMI_OTT_QUERY_UPLINK_THROUGHPUT_INFO_REQ_V01 0x0027
#define QMI_OTT_QUERY_UPLINK_THROUGHPUT_INFO_RESP_V01 0x0027
#define QMI_OTT_CONFIGURE_DOWNLINK_THROUGHPUT_SETTINGS_REQ_V01 0x0028
#define QMI_OTT_CONFIGURE_DOWNLINK_THROUGHPUT_SETTINGS_RESP_V01 0x0028
#define QMI_OTT_DOWNLINK_THROUGHPUT_REPORTING_STATUS_IND_V01 0x0029
#define QMI_OTT_QUERY_DOWNLINK_THROUGHPUT_REPORTING_STATUS_REQ_V01 0x002A
#define QMI_OTT_QUERY_DOWNLINK_THROUGHPUT_REPORTING_STATUS_RESP_V01 0x002A
#define QMI_OTT_DOWNLINK_THROUGHPUT_INFO_IND_V01 0x002B
#define QMI_OTT_GET_DOWNLINK_THROUGHPUT_INFO_REQ_V01 0x002C
#define QMI_OTT_GET_DOWNLINK_THROUGHPUT_INFO_RESP_V01 0x002C
#define QMI_OTT_GET_CAPABILITIES_REQ_V01 0x002D
#define QMI_OTT_GET_CAPABILITIES_RESP_V01 0x002D
/**
    @}
  */

/* Service Object Accessor */
/** @addtogroup wms_qmi_accessor
    @{
  */
/** This function is used internally by the autogenerated code.  Clients should use the
   macro ott_get_service_object_v01( ) that takes in no arguments. */
qmi_idl_service_object_type ott_get_service_object_internal_v01
 ( int32_t idl_maj_version, int32_t idl_min_version, int32_t library_version );

/** This macro should be used to get the service object */
#define ott_get_service_object_v01( ) \
          ott_get_service_object_internal_v01( \
            OTT_V01_IDL_MAJOR_VERS, OTT_V01_IDL_MINOR_VERS, \
            OTT_V01_IDL_TOOL_VERS )
/**
    @}
  */


#ifdef __cplusplus
}
#endif
#endif

