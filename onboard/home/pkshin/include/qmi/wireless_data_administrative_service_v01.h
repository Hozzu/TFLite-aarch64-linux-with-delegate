#ifndef WDA_SERVICE_01_H
#define WDA_SERVICE_01_H
/**
  @file wireless_data_administrative_service_v01.h

  @brief This is the public header file which defines the wda service Data structures.

  This header file defines the types and structures that were defined in
  wda. It contains the constant values defined, enums, structures,
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
  Copyright (c) 2011-2014, 2018 Qualcomm Technologies, Inc.
  All rights reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.


  $Header: //commercial/MPSS.HE.1.0.c1.3/Main/modem_proc/qmimsgs/wda/api/wireless_data_administrative_service_v01.h#1 $
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
 *THIS IS AN AUTO GENERATED FILE. DO NOT ALTER IN ANY WAY
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/* This file was generated with Tool version 6.14.7 
   It was generated on: Tue Jul 17 2018 (Spin 0)
   From IDL File: wireless_data_administrative_service_v01.idl */

/** @defgroup wda_qmi_consts Constant values defined in the IDL */
/** @defgroup wda_qmi_msg_ids Constant values for QMI message IDs */
/** @defgroup wda_qmi_enums Enumerated types used in QMI messages */
/** @defgroup wda_qmi_messages Structures sent as QMI messages */
/** @defgroup wda_qmi_aggregates Aggregate types used in QMI messages */
/** @defgroup wda_qmi_accessor Accessor for QMI service object */
/** @defgroup wda_qmi_version Constant values for versioning information */

#include <stdint.h>
#include "qmi_idl_lib.h"
#include "common_v01.h"
#include "data_common_v01.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup wda_qmi_version
    @{
  */
/** Major Version Number of the IDL used to generate this file */
#define WDA_V01_IDL_MAJOR_VERS 0x01
/** Revision Number of the IDL used to generate this file */
#define WDA_V01_IDL_MINOR_VERS 0x14
/** Major Version Number of the qmi_idl_compiler used to generate this file */
#define WDA_V01_IDL_TOOL_VERS 0x06
/** Maximum Defined Message ID */
#define WDA_V01_MAX_MESSAGE_ID 0x002E
/**
    @}
  */


/** @addtogroup wda_qmi_consts
    @{
  */
#define QMI_WDA_PACKET_FILTER_NUM_MAX_V01 32
#define QMI_WDA_PACKET_FILTER_SIZE_MAX_V01 192
/**
    @}
  */

/** @addtogroup wda_qmi_enums
    @{
  */
typedef enum {
  WDA_LINK_LAYER_PROTOCOL_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  WDA_LINK_LAYER_ETHERNET_MODE_V01 = 0x01, 
  WDA_LINK_LAYER_IP_MODE_V01 = 0x02, 
  WDA_LINK_LAYER_PROTOCOL_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}wda_link_layer_protocol_enum_v01;
/**
    @}
  */

/** @addtogroup wda_qmi_enums
    @{
  */
typedef enum {
  WDA_UL_DATA_AGG_PROTOCOL_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  WDA_UL_DATA_AGG_DISABLED_V01 = 0x00, 
  WDA_UL_DATA_AGG_TLP_ENABLED_V01 = 0x01, 
  WDA_UL_DATA_AGG_QC_NCM_ENABLED_V01 = 0x02, 
  WDA_UL_DATA_AGG_MBIM_ENABLED_V01 = 0x03, 
  WDA_UL_DATA_AGG_RNDIS_ENABLED_V01 = 0x04, 
  WDS_UL_DATA_AGG_QMAP_ENABLED_V01 = 0x05, 
  WDA_UL_DATA_AGG_QMAP_ENABLED_V01 = 0x05, 
  WDS_UL_DATA_AGG_QMAP_V2_ENABLED_V01 = 0x06, 
  WDA_UL_DATA_AGG_QMAP_V2_ENABLED_V01 = 0x06, 
  WDA_UL_DATA_AGG_QMAP_V3_ENABLED_V01 = 0x07, 
  WDA_UL_DATA_AGG_QMAP_V4_ENABLED_V01 = 0x08, 
  WDA_UL_DATA_AGG_PROTOCOL_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}wda_ul_data_agg_protocol_enum_v01;
/**
    @}
  */

/** @addtogroup wda_qmi_enums
    @{
  */
typedef enum {
  WDA_DL_DATA_AGG_PROTOCOL_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  WDA_DL_DATA_AGG_DISABLED_V01 = 0x00, 
  WDA_DL_DATA_AGG_TLP_ENABLED_V01 = 0x01, 
  WDA_DL_DATA_AGG_QC_NCM_ENABLED_V01 = 0x02, 
  WDA_DL_DATA_AGG_MBIM_ENABLED_V01 = 0x03, 
  WDA_DL_DATA_AGG_RNDIS_ENABLED_V01 = 0x04, 
  WDS_DL_DATA_AGG_QMAP_ENABLED_V01 = 0x05, 
  WDA_DL_DATA_AGG_QMAP_ENABLED_V01 = 0x05, 
  WDS_DL_DATA_AGG_QMAP_V2_ENABLED_V01 = 0x06, 
  WDA_DL_DATA_AGG_QMAP_V2_ENABLED_V01 = 0x06, 
  WDA_DL_DATA_AGG_QMAP_V3_ENABLED_V01 = 0x07, 
  WDA_DL_DATA_AGG_QMAP_V4_ENABLED_V01 = 0x08, 
  WDA_DL_DATA_AGG_PROTOCOL_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}wda_dl_data_agg_protocol_enum_v01;
/**
    @}
  */

/** @addtogroup wda_qmi_enums
    @{
  */
typedef enum {
  WDA_QOS_HEADER_FORMAT_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  WDA_QOS_HDR_FORMAT_RESERVED_V01 = 0x00, /**<  Reserved \n                          */
  WDA_QOS_HDR_FORMAT_6_BYTE_V01 = 0x01, /**<  QOS 6 byte Default header \n  */
  WDA_QOS_HDR_FORMAT_8_BYTE_V01 = 0x02, /**<  QOS 8 byte header   */
  WDA_QOS_HEADER_FORMAT_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}wda_qos_header_format_enum_v01;
/**
    @}
  */

/** @addtogroup wda_qmi_enums
    @{
  */
typedef enum {
  WDA_DATA_POWERSAVE_CONFIG_MASK_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  WDA_DATA_POWERSAVE_CONFIG_NOT_SUPPORTED_V01 = 0x00, /**<  Not supported mask \n  */
  WDA_DATA_POWERSAVE_CONFIG_DL_MARKER_V01 = 0x01, /**<  Control downlink marker notification to TE \n  */
  WDA_DATA_POWERSAVE_CONFIG_FLOW_CTL_V01 = 0x02, /**<  Control Flow enable/disable indication \n  */
  WDA_DATA_POWERSAVE_CONFIG_ALL_MASK_V01 = 0x7FFFFFFF, /**<  Control all notifications supported in this mask \n  */
  WDA_DATA_POWERSAVE_CONFIG_MASK_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}wda_data_powersave_config_mask_enum_v01;
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Request Message; Indicates to the service the data format used by the client. */
typedef struct {

  /* Optional */
  /*  QOS Data Format */
  uint8_t qos_format_valid;  /**< Must be set to true if qos_format is being passed */
  uint8_t qos_format;
  /**<   Indicates whether the Quality of Service (QOS) data format is used by 
       the client. Values:\n
       - 0 -- QOS flow header is not present (Default)\n
       - 1 -- QOS flow header is present
  */

  /* Optional */
  /*  Underlying Link Layer Protocol */
  uint8_t link_prot_valid;  /**< Must be set to true if link_prot is being passed */
  wda_link_layer_protocol_enum_v01 link_prot;
  /**<   Link protocol used by the client:\n
       - 0x01 -- 802.3 Ethernet mode (Default)\n
       - 0x02 -- IP mode
  */

  /* Optional */
  /*  Uplink Data Aggregation Protocol */
  uint8_t ul_data_aggregation_protocol_valid;  /**< Must be set to true if ul_data_aggregation_protocol is being passed */
  wda_ul_data_agg_protocol_enum_v01 ul_data_aggregation_protocol;
  /**<   Uplink (UL) data aggregation protocol to be used for uplink data 
       transfer. Values:\n
       - 0x00 -- UL data aggregation is disabled (Default)\n
       - 0x01 -- UL TLP is enabled\n
       - 0x02 -- UL QC_NCM is enabled\n
       - 0x03 -- UL MBIM is enabled\n
       - 0x04 -- UL RNDIS is enabled \n
       - 0x05 -- UL QMAP is enabled
  */

  /* Optional */
  /*  Downlink Data Aggregation Protocol */
  uint8_t dl_data_aggregation_protocol_valid;  /**< Must be set to true if dl_data_aggregation_protocol is being passed */
  wda_dl_data_agg_protocol_enum_v01 dl_data_aggregation_protocol;
  /**<   Downlink (DL) data aggregation protocol to be used for downlink data 
       transfer. Values:\n
       - 0x00 -- DL data aggregation is disabled (Default)\n
       - 0x01 -- DL TLP is enabled\n
       - 0x02 -- DL QC_NCM is enabled\n
       - 0x03 -- DL MBIM is enabled\n
       - 0x04 -- DL RNDIS is enabled \n
       - 0x05 -- DL QMAP is enabled
  */

  /* Optional */
  /*  NDP Signature */
  uint8_t ndp_signature_valid;  /**< Must be set to true if ndp_signature is being passed */
  uint32_t ndp_signature;
  /**<   NCM Datagram Pointers (NDP) signature.
  */

  /* Optional */
  /*  Downlink Data Aggregation Max Datagrams */
  uint8_t dl_data_aggregation_max_datagrams_valid;  /**< Must be set to true if dl_data_aggregation_max_datagrams is being passed */
  uint32_t dl_data_aggregation_max_datagrams;
  /**<   Maximum number of datagrams in a single aggregated packet on downlink.
       The value applies to all downlink data aggregation protocols when 
       downlink data aggregation is enabled. Zero means no limit.
  */

  /* Optional */
  /*  Downlink Data Aggregation Max Size */
  uint8_t dl_data_aggregation_max_size_valid;  /**< Must be set to true if dl_data_aggregation_max_size is being passed */
  uint32_t dl_data_aggregation_max_size;
  /**<   Maximum size in bytes of a single aggregated packet allowed on downlink.
       The value applies to all downlink data aggregation protocols when 
       downlink data aggregation is enabled.
  */

  /* Optional */
  /*  Peripheral End Point ID */
  uint8_t ep_id_valid;  /**< Must be set to true if ep_id is being passed */
  data_ep_id_type_v01 ep_id;
  /**<   (Peripheral end point on which the data format is set.
       Default value is the default data channel associated with the
       QMI control channel from which the request is received.)
  */

  /* Optional */
  /*  QOS Header Format  */
  uint8_t qos_header_format_valid;  /**< Must be set to true if qos_header_format is being passed */
  wda_qos_header_format_enum_v01 qos_header_format;
  /**<   QOS header format to be used on the uplink, on all the protocols,
 if QOS is enabled. Values:\n
      - WDA_QOS_HDR_FORMAT_RESERVED (0x00) --  Reserved \n                         
      - WDA_QOS_HDR_FORMAT_6_BYTE (0x01) --  QOS 6 byte Default header \n 
      - WDA_QOS_HDR_FORMAT_8_BYTE (0x02) --  QOS 8 byte header  
 */

  /* Optional */
  /*  QMAP Downlink Minimum Padding */
  uint8_t dl_minimum_padding_valid;  /**< Must be set to true if dl_minimum_padding is being passed */
  uint32_t dl_minimum_padding;
  /**<   Specifies the minimum padding bytes to be added in between
       aggregated downlink QMAP packets. Valid values: 0 to 64 bytes;
       must be 4-byte aligned. Default is 0.
  */

  /* Optional */
  /*  Flow Control */
  uint8_t flow_control_valid;  /**< Must be set to true if flow_control is being passed */
  uint8_t flow_control;
  /**<   Indicates whether flow control will be done by the TE. Values:\n 
       - 0 -- Flow control will not be done by the TE (Default)\n
       - 1 -- Flow control will be done by the TE
  */

  /* Optional */
  /*  Uplink Data Aggregation Max Datagrams */
  uint8_t ul_data_aggregation_max_datagrams_valid;  /**< Must be set to true if ul_data_aggregation_max_datagrams is being passed */
  uint32_t ul_data_aggregation_max_datagrams;
  /**<   Maximum number of datagrams in a single aggregated packet allowed on 
       uplink. The value applies only to QMAP uplink data aggregation 
       protocol when it is enabled. Zero means no limit.
  */

  /* Optional */
  /*  Uplink Data Aggregation Max Size */
  uint8_t ul_data_aggregation_max_size_valid;  /**< Must be set to true if ul_data_aggregation_max_size is being passed */
  uint32_t ul_data_aggregation_max_size;
  /**<   Maximum size in bytes of a single aggregated packet allowed on uplink.
       The value applies only to QMAP uplink data aggregation protocol when it 
       is enabled.
  */
}wda_set_data_format_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Response Message; Indicates to the service the data format used by the client. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Configured QOS Data Format */
  uint8_t qos_format_valid;  /**< Must be set to true if qos_format is being passed */
  uint8_t qos_format;
  /**<   Configured QOS data format. Values:\n
       - 0 -- QOS flow header is not present (Default)\n
       - 1 -- QOS flow header is present
  */

  /* Optional */
  /*  Underlying Link Layer Protocol */
  uint8_t link_prot_valid;  /**< Must be set to true if link_prot is being passed */
  wda_link_layer_protocol_enum_v01 link_prot;
  /**<   Configured link layer protocol. Values:\n
      - 0x01 -- 802.3 Ethernet mode (Default)\n
      - 0x02 -- IP mode
  */

  /* Optional */
  /*  Uplink Data Aggregation Protocol */
  uint8_t ul_data_aggregation_protocol_valid;  /**< Must be set to true if ul_data_aggregation_protocol is being passed */
  wda_ul_data_agg_protocol_enum_v01 ul_data_aggregation_protocol;
  /**<   Configured uplink data aggregation protocol. Values:\n
       - 0x00 -- UL data aggregation is disabled (Default)\n
       - 0x01 -- UL TLP is enabled\n
       - 0x02 -- UL QC_NCM is enabled\n
       - 0x03 -- UL MBIM is enabled\n
       - 0x04 -- UL RNDIS is enabled \n
       - 0x05 -- UL QMAP is enabled
  */

  /* Optional */
  /*  Downlink Data Aggregation Protocol */
  uint8_t dl_data_aggregation_protocol_valid;  /**< Must be set to true if dl_data_aggregation_protocol is being passed */
  wda_dl_data_agg_protocol_enum_v01 dl_data_aggregation_protocol;
  /**<   Configured downlink data aggregation protocol. Values:\n
       - 0x00 -- DL data aggregation is disabled (Default)\n
       - 0x01 -- DL TLP is enabled\n
       - 0x02 -- DL QC_NCM is enabled\n
       - 0x03 -- DL MBIM is enabled\n
       - 0x04 -- DL RNDIS is enabled \n
       - 0x05 -- DL QMAP is enabled
  */

  /* Optional */
  /*  NDP Signature */
  uint8_t ndp_signature_valid;  /**< Must be set to true if ndp_signature is being passed */
  uint32_t ndp_signature;
  /**<   NDP signature. The default value based on the data aggregation protocol 
       is used.
  */

  /* Optional */
  /*  Downlink Data Aggregation Max Datagrams */
  uint8_t dl_data_aggregation_max_datagrams_valid;  /**< Must be set to true if dl_data_aggregation_max_datagrams is being passed */
  uint32_t dl_data_aggregation_max_datagrams;
  /**<   Maximum number of datagrams in a single aggregated packet on downlink.
       The value applies to all downlink data aggregation protocols when 
       downlink data aggregation is enabled. Zero means no limit.
  */

  /* Optional */
  /*  Downlink Data Aggregation Max Size */
  uint8_t dl_data_aggregation_max_size_valid;  /**< Must be set to true if dl_data_aggregation_max_size is being passed */
  uint32_t dl_data_aggregation_max_size;
  /**<   Maximum size in bytes of a single aggregated packet allowed on downlink.
       The value applies to all downlink data aggregation protocols when 
       downlink data aggregation is enabled.
  */

  /* Optional */
  /*  Uplink Data Aggregation Max Datagrams */
  uint8_t ul_data_aggregation_max_datagrams_valid;  /**< Must be set to true if ul_data_aggregation_max_datagrams is being passed */
  uint32_t ul_data_aggregation_max_datagrams;
  /**<   Maximum number of datagrams supported in the modem in a single 
       aggregated packet on uplink for the currently configured aggregation 
       mode. Zero means there is no limit.
  */

  /* Optional */
  /*  Uplink Data Aggregation Max Size */
  uint8_t ul_data_aggregation_max_size_valid;  /**< Must be set to true if ul_data_aggregation_max_size is being passed */
  uint32_t ul_data_aggregation_max_size;
  /**<   Maximum size in bytes of a single aggregated packet allowed on uplink.
  */

  /* Optional */
  /*  QOS Header Format  */
  uint8_t qos_header_format_valid;  /**< Must be set to true if qos_header_format is being passed */
  wda_qos_header_format_enum_v01 qos_header_format;
  /**<   Configured QOS header format used on the uplink, on all the protocols,
 if QOS is enabled. Values:\n
      - WDA_QOS_HDR_FORMAT_RESERVED (0x00) --  Reserved \n                         
      - WDA_QOS_HDR_FORMAT_6_BYTE (0x01) --  QOS 6 byte Default header \n 
      - WDA_QOS_HDR_FORMAT_8_BYTE (0x02) --  QOS 8 byte header  
 */

  /* Optional */
  /*  QMAP Downlink Minimum Padding */
  uint8_t dl_minimum_padding_valid;  /**< Must be set to true if dl_minimum_padding is being passed */
  uint32_t dl_minimum_padding;
  /**<   Indicates the minimum padding bytes added in between
       aggregated downlink QMAP packets.
  */

  /* Optional */
  /*  Flow Control */
  uint8_t flow_control_valid;  /**< Must be set to true if flow_control is being passed */
  uint8_t flow_control;
  /**<   Configured flow control. Values:\n 
       - 0 -- Flow control will not be done by the TE (Default)\n
       - 1 -- Flow control will be done by the TE
  */
}wda_set_data_format_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Request Message; Gets the current data format settings of the client. */
typedef struct {

  /* Optional */
  /*  Peripheral End Point ID */
  uint8_t ep_id_valid;  /**< Must be set to true if ep_id is being passed */
  data_ep_id_type_v01 ep_id;
  /**<   The peripheral end point on which the data format is queried.
       The default value is the default data channel associated with the
       QMI control channel from which the request is received.
  */
}wda_get_data_format_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Response Message; Gets the current data format settings of the client. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Configured QOS Data Format */
  uint8_t qos_format_valid;  /**< Must be set to true if qos_format is being passed */
  uint8_t qos_format;
  /**<   Configured QOS data format. Values:\n
       - 0 -- QOS flow header is not present (Default)\n
       - 1 -- QOS flow header is present
  */

  /* Optional */
  /*  Underlying Link Layer Protocol */
  uint8_t link_prot_valid;  /**< Must be set to true if link_prot is being passed */
  wda_link_layer_protocol_enum_v01 link_prot;
  /**<   Configured link layer protocol. Values:\n
      - 0x01 -- 802.3 Ethernet mode (Default)\n
      - 0x02 -- IP mode
  */

  /* Optional */
  /*  Uplink Data Aggregation Protocol */
  uint8_t ul_data_aggregation_protocol_valid;  /**< Must be set to true if ul_data_aggregation_protocol is being passed */
  wda_ul_data_agg_protocol_enum_v01 ul_data_aggregation_protocol;
  /**<   Configured uplink data aggregation protocol. Values:\n
       - 0x00 -- UL data aggregation is disabled (Default)\n
       - 0x01 -- UL TLP is enabled\n
       - 0x02 -- UL QC_NCM is enabled\n
       - 0x03 -- UL MBIM is enabled\n
       - 0x04 -- UL RNDIS is enabled \n
       - 0x05 -- UL QMAP is enabled
  */

  /* Optional */
  /*  Downlink Data Aggregation Protocol */
  uint8_t dl_data_aggregation_protocol_valid;  /**< Must be set to true if dl_data_aggregation_protocol is being passed */
  wda_dl_data_agg_protocol_enum_v01 dl_data_aggregation_protocol;
  /**<   Configured downlink data aggregation protocol. Values:\n
       - 0x00 -- DL data aggregation is disabled (Default)\n
       - 0x01 -- DL TLP is enabled\n
       - 0x02 -- DL QC_NCM is enabled\n
       - 0x03 -- DL MBIM is enabled\n
       - 0x04 -- DL RNDIS is enabled \n
       - 0x05 -- DL QMAP is enabled
  */

  /* Optional */
  /*  NDP Signature */
  uint8_t ndp_signature_valid;  /**< Must be set to true if ndp_signature is being passed */
  uint32_t ndp_signature;
  /**<   NDP signature. The default value based on the data aggregation protocol 
       is used.
  */

  /* Optional */
  /*  Downlink Data Aggregation Max Datagrams */
  uint8_t dl_data_aggregation_max_datagrams_valid;  /**< Must be set to true if dl_data_aggregation_max_datagrams is being passed */
  uint32_t dl_data_aggregation_max_datagrams;
  /**<   Maximum number of datagrams in a single aggregated packet on downlink.
       The value applies to all downlink data aggregation protocols when 
       downlink data aggregation is enabled. Zero means no limit.
  */

  /* Optional */
  /*  Downlink Data Aggregation Max Size */
  uint8_t dl_data_aggregation_max_size_valid;  /**< Must be set to true if dl_data_aggregation_max_size is being passed */
  uint32_t dl_data_aggregation_max_size;
  /**<   Maximum size in bytes of a single aggregated packet allowed on downlink.
       The value applies to all downlink data aggregation protocols when 
       downlink data aggregation is enabled.
  */

  /* Optional */
  /*  Uplink Data Aggregation Max Datagrams */
  uint8_t ul_data_aggregation_max_datagrams_valid;  /**< Must be set to true if ul_data_aggregation_max_datagrams is being passed */
  uint32_t ul_data_aggregation_max_datagrams;
  /**<   Maximum number of datagrams supported in the modem in a single 
       aggregated packet on uplink for the currently configured aggregation 
       mode. Zero means there is no limit.
  */

  /* Optional */
  /*  Uplink Data Aggregation Max Size */
  uint8_t ul_data_aggregation_max_size_valid;  /**< Must be set to true if ul_data_aggregation_max_size is being passed */
  uint32_t ul_data_aggregation_max_size;
  /**<   Maximum size in bytes of a single aggregated packet allowed on uplink.
  */

  /* Optional */
  /*  QOS Header Format  */
  uint8_t qos_header_format_valid;  /**< Must be set to true if qos_header_format is being passed */
  wda_qos_header_format_enum_v01 qos_header_format;
  /**<   Configured QOS header format used on the uplink, on all the protocols,
 if QOS is enabled. Values:\n
      - WDA_QOS_HDR_FORMAT_RESERVED (0x00) --  Reserved \n                         
      - WDA_QOS_HDR_FORMAT_6_BYTE (0x01) --  QOS 6 byte Default header \n 
      - WDA_QOS_HDR_FORMAT_8_BYTE (0x02) --  QOS 8 byte header  
 */

  /* Optional */
  /*  QMAP Downlink Minimum Padding */
  uint8_t dl_minimum_padding_valid;  /**< Must be set to true if dl_minimum_padding is being passed */
  uint32_t dl_minimum_padding;
  /**<   Indicates the minimum padding bytes added in between
       aggregated downlink QMAP packets.
  */

  /* Optional */
  /*  Flow Control */
  uint8_t flow_control_valid;  /**< Must be set to true if flow_control is being passed */
  uint8_t flow_control;
  /**<   Configured flow control. Values:\n 
       - 0 -- Flow control will not be done by the TE (Default)\n
       - 1 -- Flow control will be done by the TE
  */
}wda_get_data_format_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Request Message; Enables packet filtering. */
typedef struct {

  /* Mandatory */
  /*  Filter Configuration  */
  uint8_t filter_is_restrictive;
  /**<   Configured packet filtering rule. Values: \n
         
       - TRUE  -- Filter is restrictive; rules are treated as a "white 
                      list" (i.e., only packets matching a filter rule are 
                      permitted and all others are dropped) \n
       - FALSE -- Filter is permissive; rules are treated as a "black list"
                      (i.e., packets matching any filter rule are dropped)
         
  */

  /* Optional */
  /*  IP Stream ID */
  uint8_t ips_id_valid;  /**< Must be set to true if ips_id is being passed */
  uint8_t ips_id;
  /**<   IP stream ID associated with the filter.
  */
}wda_packet_filter_enable_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Response Message; Enables packet filtering. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}wda_packet_filter_enable_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Request Message; Disables packet filtering. */
typedef struct {

  /* Optional */
  /*  IP Stream ID */
  uint8_t ips_id_valid;  /**< Must be set to true if ips_id is being passed */
  uint8_t ips_id;
  /**<   IP stream ID associated with the filter.
  */
}wda_packet_filter_disable_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Response Message; Disables packet filtering. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}wda_packet_filter_disable_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Request Message; Gets the packet filter state (enabled/disabled). */
typedef struct {

  /* Optional */
  /*  IP Stream ID */
  uint8_t ips_id_valid;  /**< Must be set to true if ips_id is being passed */
  uint8_t ips_id;
  /**<   IP stream ID associated with the filter.
  */
}wda_packet_filter_get_state_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Response Message; Gets the packet filter state (enabled/disabled). */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Packet Filter State (enabled or disabled) */
  uint8_t filtering_is_enabled_valid;  /**< Must be set to true if filtering_is_enabled is being passed */
  uint8_t filtering_is_enabled;
  /**<   Configured packet filter state. Values:\n
       - TRUE  -- Filter is enabled\n
       - FALSE -- Filter is disabled
  */

  /* Optional */
  /*  Filter Configuration  */
  uint8_t filter_is_restrictive_valid;  /**< Must be set to true if filter_is_restrictive is being passed */
  uint8_t filter_is_restrictive;
  /**<   Configured packet filtering rule. Values: \n

       - TRUE  -- Filter is restrictive; rules are treated as a "white 
                      list" (i.e., only packets matching a filter rule are 
                      permitted and all others are dropped)
       - FALSE -- Filter is permissive; rules are treated as a "black list"
                      (i.e., packets matching any filter rule are dropped)
    
  */
}wda_packet_filter_get_state_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t pattern_len;  /**< Must be set to # of elements in pattern */
  uint8_t pattern[QMI_WDA_PACKET_FILTER_SIZE_MAX_V01];
  /**<   Filter pattern. The byte array to compare against the IP Header.
  */

  uint32_t mask_len;  /**< Must be set to # of elements in mask */
  uint8_t mask[QMI_WDA_PACKET_FILTER_SIZE_MAX_V01];
  /**<   Filter mask. The bits in the filter pattern to compare against.
  */
}wda_packet_filter_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Request Message; Adds one packet filter rule. */
typedef struct {

  /* Mandatory */
  /*  Filter Rule */
  wda_packet_filter_type_v01 rule;

  /* Optional */
  /*  IP Stream ID */
  uint8_t ips_id_valid;  /**< Must be set to true if ips_id is being passed */
  uint8_t ips_id;
  /**<   IP stream ID associated with the filter.
  */
}wda_packet_filter_add_rule_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Response Message; Adds one packet filter rule. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Filter Handle */
  uint8_t handle_valid;  /**< Must be set to true if handle is being passed */
  uint32_t handle;
  /**<   Handle identifying the packet filter rule added.*/

  /* Optional */
  /*  Filter Rule  */
  uint8_t rule_valid;  /**< Must be set to true if rule is being passed */
  wda_packet_filter_type_v01 rule;
}wda_packet_filter_add_rule_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Request Message; Deletes one packet filter rule or all rules. */
typedef struct {

  /* Optional */
  /*  Filter Handle	  */
  uint8_t handle_valid;  /**< Must be set to true if handle is being passed */
  uint32_t handle;
  /**<   Handle identifying the packet filter entry.
       The value must be the handle previously returned by
       QMI_WDA_PACKET_FILTER_ADD_RULE_RESP.
   */

  /* Optional */
  /*  IP Stream ID */
  uint8_t ips_id_valid;  /**< Must be set to true if ips_id is being passed */
  uint8_t ips_id;
  /**<   IP stream ID associated with the filter.
  */
}wda_packet_filter_delete_rule_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Response Message; Deletes one packet filter rule or all rules. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Filter Handle	 */
  uint8_t handle_valid;  /**< Must be set to true if handle is being passed */
  uint32_t handle;
  /**<   Handle identifying the packet filter entry.
       The value must be the handle previously returned by
       QMI_WDA_PACKET_FILTER_ADD_RULE_RESP.
   */
}wda_packet_filter_delete_rule_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Request Message; Gets the list of handles to currently installed rules. */
typedef struct {

  /* Optional */
  /*  IP Stream ID */
  uint8_t ips_id_valid;  /**< Must be set to true if ips_id is being passed */
  uint8_t ips_id;
  /**<   IP stream ID associated with the filter.
  */
}wda_packet_filter_get_rule_handles_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Response Message; Gets the list of handles to currently installed rules. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Filter Handle List  */
  uint8_t handle_valid;  /**< Must be set to true if handle is being passed */
  uint32_t handle_len;  /**< Must be set to # of elements in handle */
  uint32_t handle[QMI_WDA_PACKET_FILTER_NUM_MAX_V01];
  /**<   List of handles identifying all of the currently installed packet filter
       rule entries. The value of each handle must be the handle previously 
       returned by QMI_WDA_PACKET_FILTER_ADD_RULE_RESP.
  */
}wda_packet_filter_get_rule_handles_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Request Message; Looks up and returns a filter rule given its handle. */
typedef struct {

  /* Mandatory */
  /*  Filter Handle	 */
  uint32_t handle;
  /**<   Handle identifying the packet filter instance.
       The value must be the handle previously returned by
       QMI_WDA_PACKET_FILTER_ENABLE_RESP.
   */

  /* Optional */
  /*  IP Stream ID */
  uint8_t ips_id_valid;  /**< Must be set to true if ips_id is being passed */
  uint8_t ips_id;
  /**<   IP stream ID associated with the filter.
  */
}wda_packet_filter_get_rule_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Response Message; Looks up and returns a filter rule given its handle. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Filter Handle	  */
  uint8_t handle_valid;  /**< Must be set to true if handle is being passed */
  uint32_t handle;
  /**<   Handle identifying the packet filter instance.
       The value must be the handle previously returned by
       QMI_WDA_PACKET_FILTER_ENABLE_RESP.
   */

  /* Optional */
  /*  Filter Rule   */
  uint8_t rule_valid;  /**< Must be set to true if rule is being passed */
  wda_packet_filter_type_v01 rule;
}wda_packet_filter_get_rule_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Request Message; Sets the loopback state. */
typedef struct {

  /* Mandatory */
  /*  Filter Configuration  */
  uint8_t loopback_state;
  /**<   Configures the loopback state. Values:\n
       - TRUE  -- Enable the loopback state\n
       - FALSE -- Disable the loopback state
  */
}wda_set_loopback_state_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Response Message; Sets the loopback state. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}wda_set_loopback_state_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Request Message; Gets the loopback state. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}wda_get_loopback_state_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Response Message; Gets the loopback state. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Loopback State */
  uint8_t loopback_state_is_enabled_valid;  /**< Must be set to true if loopback_state_is_enabled is being passed */
  uint8_t loopback_state_is_enabled;
  /**<   Configures the loopback state. Values:\n
       - TRUE  -- Loopback state is enabled\n
       - FALSE -- Loopback state is disabled
  */
}wda_get_loopback_state_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Request Message; Sets the QMAP settings. */
typedef struct {

  /* Optional */
  /*  QMAP In-Band Flow Control */
  uint8_t in_band_flow_control_valid;  /**< Must be set to true if in_band_flow_control is being passed */
  uint8_t in_band_flow_control;
  /**<   Configures the in-band flow control. Values:\n
       - 0 -- Disables in-band flow control \n
       - 1 -- Enables in-band flow control
  */

  /* Optional */
  /*  Peripheral End Point ID */
  uint8_t ep_id_valid;  /**< Must be set to true if ep_id is being passed */
  data_ep_id_type_v01 ep_id;
  /**<   The peripheral end point on which the QMAP settings are set.
       The default value is the default data channel associated with the
       QMI control channel from which the request is received.
  */
}wda_set_qmap_settings_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Response Message; Sets the QMAP settings. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  QMAP In-Band Flow Control */
  uint8_t in_band_flow_control_valid;  /**< Must be set to true if in_band_flow_control is being passed */
  uint8_t in_band_flow_control;
  /**<   Indicates whether the in-band flow control is enabled/disabled. 
       Values:\n
       - 0 -- Disabled \n
       - 1 -- Enabled
  */
}wda_set_qmap_settings_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Request Message; Gets the QMAP settings. */
typedef struct {

  /* Optional */
  /*  Peripheral End Point ID */
  uint8_t ep_id_valid;  /**< Must be set to true if ep_id is being passed */
  data_ep_id_type_v01 ep_id;
  /**<   The peripheral end point on which QMAP settings are queried.
       The default value is the default data channel associated with the
       QMI control channel from which the request is received.
  */
}wda_get_qmap_settings_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Response Message; Gets the QMAP settings. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  QMAP In-Band Flow Control */
  uint8_t in_band_flow_control_valid;  /**< Must be set to true if in_band_flow_control is being passed */
  uint8_t in_band_flow_control;
  /**<   Indicates whether the in-band flow control is enabled/disabled. 
       Values:\n
       - 0 -- Disabled \n
       - 1 -- Enabled
  */
}wda_get_qmap_settings_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Request Message; Sets the powersave configuration for the specified end point */
typedef struct {

  /* Mandatory */
  /*  Peripheral Endpoint ID */
  data_ep_id_type_v01 ep_id;
  /**<   \n The peripheral endpoint (physical data channel) for which
       the power mode should apply.
  */

  /* Optional */
  /*  Requested Data Powersave Configuration */
  uint8_t req_data_cfg_valid;  /**< Must be set to true if req_data_cfg is being passed */
  wda_data_powersave_config_mask_enum_v01 req_data_cfg;
  /**<   Requested powersave configuration mask. Values:\n
       @MASK 
  */
}wda_set_powersave_config_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Response Message; Sets the powersave configuration for the specified end point */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;

  /* Optional */
  /*  Data Powersave Configuration */
  uint8_t data_cfg_valid;  /**< Must be set to true if data_cfg is being passed */
  wda_data_powersave_config_mask_enum_v01 data_cfg;
  /**<   Supported powersave configuration mask. Values: \n
       @MASK
  */
}wda_set_powersave_config_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Request Message; Sets the powersave mode of the TE */
typedef struct {

  /* Mandatory */
  /*  Powersave control flag */
  uint8_t powersave_control_flag;
  /**<   Indicates enable/disable powersave. 
       Values:\n
       - 0 -- Disable(Default) \n
       - 1 -- Enable
  */
}wda_set_powersave_mode_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup wda_qmi_messages
    @{
  */
/** Response Message; Sets the powersave mode of the TE */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
}wda_set_powersave_mode_resp_msg_v01;  /* Message */
/**
    @}
  */

/* Conditional compilation tags for message removal */ 
//#define REMOVE_QMI_WDA_GET_DATA_FORMAT_V01 
//#define REMOVE_QMI_WDA_GET_LOOPBACK_STATE_V01 
//#define REMOVE_QMI_WDA_GET_QMAP_SETTINGS_V01 
//#define REMOVE_QMI_WDA_GET_SUPPORTED_FIELDS_V01 
//#define REMOVE_QMI_WDA_GET_SUPPORTED_MSGS_V01 
//#define REMOVE_QMI_WDA_PACKET_FILTER_ADD_RULE_V01 
//#define REMOVE_QMI_WDA_PACKET_FILTER_DELETE_RULE_V01 
//#define REMOVE_QMI_WDA_PACKET_FILTER_DISABLE_V01 
//#define REMOVE_QMI_WDA_PACKET_FILTER_ENABLE_V01 
//#define REMOVE_QMI_WDA_PACKET_FILTER_GET_RULE_V01 
//#define REMOVE_QMI_WDA_PACKET_FILTER_GET_RULE_HANDLES_V01 
//#define REMOVE_QMI_WDA_PACKET_FILTER_GET_STATE_V01 
//#define REMOVE_QMI_WDA_SET_DATA_FORMAT_V01 
//#define REMOVE_QMI_WDA_SET_LOOPBACK_STATE_V01 
//#define REMOVE_QMI_WDA_SET_POWERSAVE_CONFIG_V01 
//#define REMOVE_QMI_WDA_SET_POWERSAVE_MODE_V01 
//#define REMOVE_QMI_WDA_SET_QMAP_SETTINGS_V01 

/*Service Message Definition*/
/** @addtogroup wda_qmi_msg_ids
    @{
  */
#define QMI_WDA_GET_SUPPORTED_MSGS_REQ_V01 0x001E
#define QMI_WDA_GET_SUPPORTED_MSGS_RESP_V01 0x001E
#define QMI_WDA_GET_SUPPORTED_FIELDS_REQ_V01 0x001F
#define QMI_WDA_GET_SUPPORTED_FIELDS_RESP_V01 0x001F
#define QMI_WDA_SET_DATA_FORMAT_REQ_V01 0x0020
#define QMI_WDA_SET_DATA_FORMAT_RESP_V01 0x0020
#define QMI_WDA_GET_DATA_FORMAT_REQ_V01 0x0021
#define QMI_WDA_GET_DATA_FORMAT_RESP_V01 0x0021
#define QMI_WDA_PACKET_FILTER_ENABLE_REQ_V01 0x0022
#define QMI_WDA_PACKET_FILTER_ENABLE_RESP_V01 0x0022
#define QMI_WDA_PACKET_FILTER_DISABLE_REQ_V01 0x0023
#define QMI_WDA_PACKET_FILTER_DISABLE_RESP_V01 0x0023
#define QMI_WDA_PACKET_FILTER_GET_STATE_REQ_V01 0x0024
#define QMI_WDA_PACKET_FILTER_GET_STATE_RESP_V01 0x0024
#define QMI_WDA_PACKET_FILTER_ADD_RULE_REQ_V01 0x0025
#define QMI_WDA_PACKET_FILTER_ADD_RULE_RESP_V01 0x0025
#define QMI_WDA_PACKET_FILTER_DELETE_RULE_REQ_V01 0x0026
#define QMI_WDA_PACKET_FILTER_DELETE_RULE_RESP_V01 0x0026
#define QMI_WDA_PACKET_FILTER_GET_RULE_HANDLES_REQ_V01 0x0027
#define QMI_WDA_PACKET_FILTER_GET_RULE_HANDLES_RESP_V01 0x0027
#define QMI_WDA_PACKET_FILTER_GET_RULE_REQ_V01 0x0028
#define QMI_WDA_PACKET_FILTER_GET_RULE_RESP_V01 0x0028
#define QMI_WDA_SET_LOOPBACK_STATE_REQ_V01 0x0029
#define QMI_WDA_SET_LOOPBACK_STATE_RESP_V01 0x0029
#define QMI_WDA_GET_LOOPBACK_STATE_REQ_V01 0x002A
#define QMI_WDA_GET_LOOPBACK_STATE_RESP_V01 0x002A
#define QMI_WDA_SET_QMAP_SETTINGS_REQ_V01 0x002B
#define QMI_WDA_SET_QMAP_SETTINGS_RESP_V01 0x002B
#define QMI_WDA_GET_QMAP_SETTINGS_REQ_V01 0x002C
#define QMI_WDA_GET_QMAP_SETTINGS_RESP_V01 0x002C
#define QMI_WDA_SET_POWERSAVE_CONFIG_REQ_V01 0x002D
#define QMI_WDA_SET_POWERSAVE_CONFIG_RESP_V01 0x002D
#define QMI_WDA_SET_POWERSAVE_MODE_REQ_V01 0x002E
#define QMI_WDA_SET_POWERSAVE_MODE_RESP_V01 0x002E
/**
    @}
  */

/* Service Object Accessor */
/** @addtogroup wms_qmi_accessor
    @{
  */
/** This function is used internally by the autogenerated code.  Clients should use the
   macro wda_get_service_object_v01( ) that takes in no arguments. */
qmi_idl_service_object_type wda_get_service_object_internal_v01
 ( int32_t idl_maj_version, int32_t idl_min_version, int32_t library_version );

/** This macro should be used to get the service object */
#define wda_get_service_object_v01( ) \
          wda_get_service_object_internal_v01( \
            WDA_V01_IDL_MAJOR_VERS, WDA_V01_IDL_MINOR_VERS, \
            WDA_V01_IDL_TOOL_VERS )
/**
    @}
  */


#ifdef __cplusplus
}
#endif
#endif

