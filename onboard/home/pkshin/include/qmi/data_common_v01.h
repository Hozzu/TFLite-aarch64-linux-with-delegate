#ifndef DATA_COMMON_SERVICE_01_H
#define DATA_COMMON_SERVICE_01_H
/**
  @file data_common_v01.h

  @brief This is the public header file which defines the data_common service Data structures.

  This header file defines the types and structures that were defined in
  data_common. It contains the constant values defined, enums, structures,
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
   It was generated on: Thu Feb 28 2019 (Spin 0)
   From IDL File: data_common_v01.idl */

/** @defgroup data_common_qmi_consts Constant values defined in the IDL */
/** @defgroup data_common_qmi_msg_ids Constant values for QMI message IDs */
/** @defgroup data_common_qmi_enums Enumerated types used in QMI messages */
/** @defgroup data_common_qmi_messages Structures sent as QMI messages */
/** @defgroup data_common_qmi_aggregates Aggregate types used in QMI messages */
/** @defgroup data_common_qmi_accessor Accessor for QMI service object */
/** @defgroup data_common_qmi_version Constant values for versioning information */

#include <stdint.h>
#include "qmi_idl_lib.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup data_common_qmi_version
    @{
  */
/** Major Version Number of the IDL used to generate this file */
#define DATA_COMMON_V01_IDL_MAJOR_VERS 0x01
/** Revision Number of the IDL used to generate this file */
#define DATA_COMMON_V01_IDL_MINOR_VERS 0x02
/** Major Version Number of the qmi_idl_compiler used to generate this file */
#define DATA_COMMON_V01_IDL_TOOL_VERS 0x06

/**
    @}
  */

/** @addtogroup data_common_qmi_enums
    @{
  */
typedef enum {
  DATA_EP_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  DATA_EP_TYPE_RESERVED_V01 = 0x00, /**<  Reserved \n  */
  DATA_EP_TYPE_HSIC_V01 = 0x01, /**<  High-speed inter-chip interface \n  */
  DATA_EP_TYPE_HSUSB_V01 = 0x02, /**<  High-speed universal serial bus \n  */
  DATA_EP_TYPE_PCIE_V01 = 0x03, /**<  Peripheral component interconnect express \n  */
  DATA_EP_TYPE_EMBEDDED_V01 = 0x04, /**<  Embedded \n  */
  DATA_EP_TYPE_BAM_DMUX_V01 = 0x05, /**<  BAM demux \n  */
  DATA_EP_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}data_ep_type_enum_v01;
/**
    @}
  */

/** @addtogroup data_common_qmi_aggregates
    @{
  */
/** 
 */
typedef struct {

  data_ep_type_enum_v01 ep_type;
  /**<   Peripheral endpoint type. Values: \n
      - DATA_EP_TYPE_RESERVED (0x00) --  Reserved \n 
      - DATA_EP_TYPE_HSIC (0x01) --  High-speed inter-chip interface \n 
      - DATA_EP_TYPE_HSUSB (0x02) --  High-speed universal serial bus \n 
      - DATA_EP_TYPE_PCIE (0x03) --  Peripheral component interconnect express \n 
      - DATA_EP_TYPE_EMBEDDED (0x04) --  Embedded \n 
      - DATA_EP_TYPE_BAM_DMUX (0x05) --  BAM demux \n 
 All other values are reserved and are ignored.
 */

  uint32_t iface_id;
  /**<   Peripheral interface number. \n
  */
}data_ep_id_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup data_common_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t tcp_coalescing;
  /**<   Specifies if TCP coalescing is enabled or disabled on the modem.
       Values:\n
       - FALSE: Disable TCP coalecsing. (Default)
       - TRUE : Enable TCP coalescing
  */

  uint8_t udp_coalescing;
  /**<   Specifies if UDP coalescing is enabled or disabled on the modem.
       Values:\n
       - FALSE: Disable UDP coalecsing. (Default)
       - TRUE : Enable UDP coalescing
  */
}data_coalescing_info_type_v01;  /* Type */
/**
    @}
  */

/* Conditional compilation tags for message removal */ 

/*Extern Definition of Type Table Object*/
/*THIS IS AN INTERNAL OBJECT AND SHOULD ONLY*/
/*BE ACCESSED BY AUTOGENERATED FILES*/
extern const qmi_idl_type_table_object data_common_qmi_idl_type_table_object_v01;


#ifdef __cplusplus
}
#endif
#endif

