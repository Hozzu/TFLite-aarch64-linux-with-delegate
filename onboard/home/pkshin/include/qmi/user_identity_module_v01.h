#ifndef UIM_SERVICE_01_H
#define UIM_SERVICE_01_H
/**
  @file user_identity_module_v01.h

  @brief This is the public header file which defines the uim service Data structures.

  This header file defines the types and structures that were defined in
  uim. It contains the constant values defined, enums, structures,
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


  $Header$
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
 *THIS IS AN AUTO GENERATED FILE. DO NOT ALTER IN ANY WAY
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/* This file was generated with Tool version 6.14.7
   It was generated on: Tue Oct 16 2018 (Spin 0)
   From IDL File: user_identity_module_v01.idl */

/** @defgroup uim_qmi_consts Constant values defined in the IDL */
/** @defgroup uim_qmi_msg_ids Constant values for QMI message IDs */
/** @defgroup uim_qmi_enums Enumerated types used in QMI messages */
/** @defgroup uim_qmi_messages Structures sent as QMI messages */
/** @defgroup uim_qmi_aggregates Aggregate types used in QMI messages */
/** @defgroup uim_qmi_accessor Accessor for QMI service object */
/** @defgroup uim_qmi_version Constant values for versioning information */

#include <stdint.h>
#include "qmi_idl_lib.h"
#include "common_v01.h"


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup uim_qmi_version
    @{
  */
/** Major Version Number of the IDL used to generate this file */
#define UIM_V01_IDL_MAJOR_VERS 0x01
/** Revision Number of the IDL used to generate this file */
#define UIM_V01_IDL_MINOR_VERS 0x57
/** Major Version Number of the qmi_idl_compiler used to generate this file */
#define UIM_V01_IDL_TOOL_VERS 0x06
/** Maximum Defined Message ID */
#define UIM_V01_MAX_MESSAGE_ID 0x0071
/**
    @}
  */


/** @addtogroup uim_qmi_consts
    @{
  */
#define QMI_UIM_CARDS_MAX_V01 2
#define QMI_UIM_EXTENDED_CARDS_MAX_V01 5
#define QMI_UIM_APPS_MAX_V01 8
#define QMI_UIM_EXTENDED_APPS_MAX_V01 20
#define QMI_UIM_AID_MAX_V01 32
#define QMI_UIM_LABEL_MAX_V01 255
#define QMI_UIM_PATH_MAX_V01 10
#define QMI_UIM_PIN_MAX_V01 8
#define QMI_UIM_ENCRYPTED_PIN_MAX_V01 255
#define QMI_UIM_CK_MAX_V01 16
#define QMI_UIM_CONTENT_TRANSPARENT_MAX_V01 4096
#define QMI_UIM_CONTENT_RECORD_MAX_V01 255
#define QMI_UIM_FILE_ATTR_RAW_VALUE_MAX_V01 1024
#define QMI_UIM_REFRESH_FILES_MAX_V01 100
#define QMI_UIM_AUTHENTICATE_DATA_MAX_V01 1024
#define QMI_UIM_AUTHENTICATE_RESULT_MAX_V01 1024
#define QMI_UIM_APDU_DATA_MAX_V01 1024
#define QMI_UIM_PERSO_FEATURE_MAX_V01 20
#define QMI_UIM_ATR_DATA_MAX_V01 255
#define QMI_UIM_CARD_READER_DATA_MAX_V01 255
#define QMI_UIM_CONTENT_ADDITIONAL_RECORD_MAX_V01 4096
#define QMI_UIM_SELECT_RESPONSE_MAX_V01 255
#define QMI_UIM_ATR_MAX_V01 33
#define QMI_UIM_ENCRYPTED_IMSI_MAX_V01 255
#define QMI_UIM_PHYSICAL_SLOTS_MAX_V01 5
#define QMI_UIM_ICCID_LEN_MAX_V01 10
#define QMI_UIM_MCC_LEN_V01 3
#define QMI_UIM_MNC_MAX_V01 3
#define QMI_UIM_PLMN_NUM_MAX_V01 85
#define QMI_UIM_IRM_CODE_LEN_V01 4
#define QMI_UIM_MSIN_MAX_V01 10
#define QMI_UIM_GW_SPN_LEN_V01 16
#define QMI_UIM_ICCID_DIGIT_MAX_V01 20
#define QMI_UIM_PERSO_NUM_NW_MAX_V01 85
#define QMI_UIM_PERSO_NUM_NS_MAX_V01 64
#define QMI_UIM_PERSO_NUM_GW_SP_MAX_V01 64
#define QMI_UIM_PERSO_NUM_GW_CP_MAX_V01 51
#define QMI_UIM_PERSO_NUM_SIM_MAX_V01 32
#define QMI_UIM_PERSO_NUM_1X_NW2_MAX_V01 128
#define QMI_UIM_PERSO_NUM_GW_SPN_MAX_V01 32
#define QMI_UIM_PERSO_NUM_GW_ICCID_MAX_V01 32
#define QMI_UIM_INCREASE_DATA_MAX_V01 127
#define QMI_UIM_PROFILES_MAX_V01 8
#define QMI_UIM_ENCRYPTED_REQUEST_MAX_V01 1024
#define QMI_UIM_ENCRYPTED_RESPONSE_MAX_V01 1024
#define QMI_UIM_FQDN_MAX_V01 255
#define QMI_UIM_SECURITY_PROTOCOL_LEN_V01 5
#define QMI_UIM_KS_NAF_LEN_V01 32
#define QMI_UIM_ENCRYPTED_KS_NAF_MAX_V01 1024
#define QMI_UIM_BTID_MAX_V01 255
#define QMI_UIM_KS_LIFETIME_MAX_V01 255
#define QMI_UIM_IMPI_MAX_V01 255
#define QMI_UIM_ENCRYPTED_IMPI_MAX_V01 1024
#define QMI_UIM_NUM_RECORD_MAX_V01 254
#define QMI_UIM_APN_NAME_MAX_V01 100
#define QMI_UIM_ENCRYPTED_KEY_MAX_V01 512
#define QMI_UIM_SIMLOCK_DATA_MAX_V01 1024
#define QMI_UIM_HMAC_MAX_V01 128
#define QMI_UIM_IMSI_LEN_MAX_V01 10
#define QMI_UIM_EXTENDED_PERSO_FEATURE_MAX_V01 100
#define QMI_UIM_GID_MAX_V01 5
#define QMI_UIM_GID_EXT_MAX_V01 8
#define QMI_UIM_EID_LEN_V01 16
#define QMI_UIM_EUICC_DOWNLOAD_CODE_MAX_V01 256
#define QMI_UIM_EUICC_NICKNAME_MAX_V01 64
#define QMI_UIM_EUICC_PROFILE_NAME_MAX_V01 64
#define QMI_UIM_EUICC_SPN_MAX_V01 32
#define QMI_UIM_EUICC_ICON_MAX_V01 1024
#define QMI_UIM_TERMINAL_CAPABILITY_VALUE_MAX_V01 32
#define QMI_UIM_TERMINAL_CAPABILITY_TLVS_MAX_V01 16
#define QMI_UIM_BER_TLV_CONTENT_MAX_V01 4096
#define QMI_UIM_LONG_SELECT_RESPONSE_MAX_V01 1024
#define QMI_UIM_SIMLOCK_DATA_EXT_MAX_V01 4096
#define QMI_UIM_SEC_ATTRIBUTE_PIN1_BIT_V01 0
#define QMI_UIM_SEC_ATTRIBUTE_PIN2_BIT_V01 1
#define QMI_UIM_SEC_ATTRIBUTE_UPIN_BIT_V01 2
#define QMI_UIM_SEC_ATTRIBUTE_ADM_BIT_V01 3
#define QMI_UIM_CAP_FDN_BIT_V01 0
#define QMI_UIM_CAP_HIDDEN_PIN_BIT_V01 1
#define QMI_UIM_CAP_EF_DIR_INDEX_BIT_V01 2
#define QMI_UIM_EVENT_CARD_STATUS_BIT_V01 0
#define QMI_UIM_EVENT_SAP_CONNECTION_BIT_V01 1
#define QMI_UIM_EVENT_EXTENDED_CARD_STATUS_BIT_V01 2
#define QMI_UIM_EVENT_PROV_SESSION_CLOSE_BIT_V01 3
#define QMI_UIM_EVENT_PHYSICAL_SLOT_STATUS_BIT_V01 4
#define QMI_UIM_EVENT_SIM_BUSY_STATUS_BIT_V01 5
#define QMI_UIM_EVENT_REDUCED_CARD_STATUS_BIT_V01 6
#define QMI_UIM_EVENT_RECOVERY_COMPLETE_BIT_V01 7
#define QMI_UIM_EVENT_SUPPLY_VOLTAGE_STATUS_BIT_V01 8
#define QMI_UIM_EVENT_CARD_ACTIVATION_STATUS_BIT_V01 9
#define QMI_UIM_EVENT_REMOTE_SIMLOCK_BIT_V01 10
#define QMI_UIM_EVENT_SIMLOCK_TEMPORARY_UNLOCK_STATUS_BIT_V01 11
#define QMI_UIM_FILE_ID_ICCID_V01 0x2FE2
#define QMI_UIM_FILE_ID_3GPP_LANGUAGE_V01 0x6F05
#define QMI_UIM_FILE_ID_3GPP_IMSI_V01 0x6F07
#define QMI_UIM_FILE_ID_3GPP_KEYS_V01 0x6F08
#define QMI_UIM_FILE_ID_3GPP_KEYSPS_V01 0x6F09
#define QMI_UIM_FILE_ID_3GPP_GSM_KC_V01 0x6F20
#define QMI_UIM_FILE_ID_3GPP_PLMNSEL_V01 0x6F30
#define QMI_UIM_FILE_ID_3GPP_HPPLMN_V01 0x6F31
#define QMI_UIM_FILE_ID_3GPP_ACM_MAX_V01 0x6F37
#define QMI_UIM_FILE_ID_3GPP_SERVICE_TABLE_V01 0x6F38
#define QMI_UIM_FILE_ID_3GPP_ACM_V01 0x6F39
#define QMI_UIM_FILE_ID_3GPP_GID1_V01 0x6F3E
#define QMI_UIM_FILE_ID_3GPP_GID2_V01 0x6F3F
#define QMI_UIM_FILE_ID_3GPP_PUCT_V01 0x6F41
#define QMI_UIM_FILE_ID_3GPP_SPN_V01 0x6F46
#define QMI_UIM_FILE_ID_3GPP_CBMID_V01 0x6F48
#define QMI_UIM_FILE_ID_3GPP_GSM_KCGPRS_V01 0x6F52
#define QMI_UIM_FILE_ID_3GPP_GSM_LOCIGPRS_V01 0x6F53
#define QMI_UIM_FILE_ID_3GPP_EST_V01 0x6F56
#define QMI_UIM_FILE_ID_3GPP_START_HFN_V01 0x6F5B
#define QMI_UIM_FILE_ID_3GPP_THRESHOLD_V01 0x6F5C
#define QMI_UIM_FILE_ID_3GPP_PLMNWACT_V01 0x6F60
#define QMI_UIM_FILE_ID_3GPP_OPLMNWACT_V01 0x6F61
#define QMI_UIM_FILE_ID_3GPP_HPLMNWACT_V01 0x6F62
#define QMI_UIM_FILE_ID_3GPP_RPLMNACT_V01 0x6F65
#define QMI_UIM_FILE_ID_3GPP_PSLOCI_V01 0x6F73
#define QMI_UIM_FILE_ID_3GPP_GSM_BCCH_V01 0x6F74
#define QMI_UIM_FILE_ID_3GPP_ACC_V01 0x6F78
#define QMI_UIM_FILE_ID_3GPP_FPLMN_V01 0x6F7B
#define QMI_UIM_FILE_ID_3GPP_LOCI_V01 0x6F7E
#define QMI_UIM_FILE_ID_3GPP_AD_V01 0x6FAD
#define QMI_UIM_FILE_ID_3GPP_PHASE_V01 0x6FAE
#define QMI_UIM_FILE_ID_3GPP_EMLPP_V01 0x6FB5
#define QMI_UIM_FILE_ID_3GPP_AAEM_V01 0x6FB6
#define QMI_UIM_FILE_ID_3GPP_ECC_V01 0x6FB7
#define QMI_UIM_FILE_ID_3GPP_HIDDENKEY_V01 0x6FC3
#define QMI_UIM_FILE_ID_3GPP_PNN_V01 0x6FC5
#define QMI_UIM_FILE_ID_3GPP_OPL_V01 0x6FC6
#define QMI_UIM_FILE_ID_3GPP_SPDI_V01 0x6FCD
#define QMI_UIM_FILE_ID_3GPP_EHPLMN_V01 0x6FD9
#define QMI_UIM_FILE_ID_3GPP_EHPLMNPI_V01 0x6FDB
#define QMI_UIM_FILE_ID_3GPP_LRPLMNSI_V01 0x6FDC
#define QMI_UIM_FILE_ID_3GPP_EPSLOCI_V01 0x6FE3
#define QMI_UIM_FILE_ID_3GPP_EPSNSC_V01 0x6FE4
#define QMI_UIM_FILE_ID_3GPP_NASCONFIG_V01 0x6FE8
#define QMI_UIM_FILE_ID_3GPP2_IMSI_M_V01 0x6F22
#define QMI_UIM_FILE_ID_3GPP2_IMSI_T_V01 0x6F23
#define QMI_UIM_FILE_ID_3GPP2_CDMA_HOME_SID_NID_V01 0x6F28
#define QMI_UIM_FILE_ID_3GPP2_CDMA_ZONE_BASED_REGN_IND_V01 0x6F29
#define QMI_UIM_FILE_ID_3GPP2_CDMA_SYS_REGN_IND_V01 0x6F2A
#define QMI_UIM_FILE_ID_3GPP2_CDMA_DIST_BASED_REGN_IND_V01 0x6F2B
#define QMI_UIM_FILE_ID_3GPP2_ACCOLC_V01 0x6F2C
#define QMI_UIM_FILE_ID_3GPP2_CALL_TERM_MODE_PREF_V01 0x6F2D
#define QMI_UIM_FILE_ID_3GPP2_PRL_V01 0x6F30
#define QMI_UIM_FILE_ID_3GPP2_RUIM_ID_V01 0x6F31
#define QMI_UIM_FILE_ID_3GPP2_SERVICE_TABLE_V01 0x6F32
#define QMI_UIM_FILE_ID_3GPP2_OTAPA_SPC_ENABLE_V01 0x6F34
#define QMI_UIM_FILE_ID_3GPP2_NAM_LOCK_V01 0x6F35
#define QMI_UIM_FILE_ID_3GPP2_SERVICE_PREF_V01 0x6F37
#define QMI_UIM_FILE_ID_3GPP2_LANG_IND_V01 0x6F3A
#define QMI_UIM_FILE_ID_3GPP2_SVC_PVDR_NAME_V01 0x6F41
#define QMI_UIM_FILE_ID_3GPP2_AD_V01 0x6F43
#define QMI_UIM_FILE_ID_3GPP2_MSISDN_V01 0x6F44
#define QMI_UIM_FILE_ID_3GPP2_MAXIMUM_PRL_V01 0x6F45
#define QMI_UIM_FILE_ID_3GPP2_ECC_V01 0x6F47
#define QMI_UIM_FILE_ID_3GPP2_3GPD_3GPDOPM_V01 0x6F49
#define QMI_UIM_FILE_ID_3GPP2_3GPD_SIPUPP_V01 0x6F4C
#define QMI_UIM_FILE_ID_3GPP2_3GPD_MIPUPP_V01 0x6F4D
#define QMI_UIM_FILE_ID_3GPP2_3GPD_MIPSP_V01 0x6F4F
#define QMI_UIM_FILE_ID_3GPP2_3GPD_SIPPAPSS_V01 0x6F50
#define QMI_UIM_FILE_ID_3GPP2_HRPDUPP_V01 0x6F57
#define QMI_UIM_FILE_ID_3GPP2_EPRL_V01 0x6F5A
#define QMI_UIM_FILE_ID_3GPP2_GID1_V01 0x6F6D
#define QMI_UIM_FILE_ID_3GPP2_GID2_V01 0x6F6E
#define QMI_UIM_FILE_ID_3GPP2_SF_EUIM_ID_V01 0x6F74
#define QMI_UIM_FILE_ID_3GPP2_EST_V01 0x6F75
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Resets the state of the issuing control point kept by the service. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}uim_reset_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Resets the state of the issuing control point kept by the service. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message definition.
  */
}uim_reset_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_SESSION_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_SESSION_TYPE_PRIMARY_GW_V01 = 0x00,
  UIM_SESSION_TYPE_PRIMARY_1X_V01 = 0x01,
  UIM_SESSION_TYPE_SECONDARY_GW_V01 = 0x02,
  UIM_SESSION_TYPE_SECONDARY_1X_V01 = 0x03,
  UIM_SESSION_TYPE_NONPROVISIONING_SLOT_1_V01 = 0x04,
  UIM_SESSION_TYPE_NONPROVISIONING_SLOT_2_V01 = 0x05,
  UIM_SESSION_TYPE_CARD_ON_SLOT_1_V01 = 0x06,
  UIM_SESSION_TYPE_CARD_ON_SLOT_2_V01 = 0x07,
  UIM_SESSION_TYPE_CHANNEL_ID_SLOT_1_V01 = 0x08,
  UIM_SESSION_TYPE_CHANNEL_ID_SLOT_2_V01 = 0x09,
  UIM_SESSION_TYPE_TERTIARY_GW_V01 = 0x0A,
  UIM_SESSION_TYPE_TERTIARY_1X_V01 = 0x0B,
  UIM_SESSION_TYPE_QUATERNARY_GW_V01 = 0x0C,
  UIM_SESSION_TYPE_QUATERNARY_1X_V01 = 0x0D,
  UIM_SESSION_TYPE_QUINARY_GW_V01 = 0x0E,
  UIM_SESSION_TYPE_QUINARY_1X_V01 = 0x0F,
  UIM_SESSION_TYPE_NONPROVISIONING_SLOT_3_V01 = 0x10,
  UIM_SESSION_TYPE_NONPROVISIONING_SLOT_4_V01 = 0x11,
  UIM_SESSION_TYPE_NONPROVISIONING_SLOT_5_V01 = 0x12,
  UIM_SESSION_TYPE_CARD_ON_SLOT_3_V01 = 0x13,
  UIM_SESSION_TYPE_CARD_ON_SLOT_4_V01 = 0x14,
  UIM_SESSION_TYPE_CARD_ON_SLOT_5_V01 = 0x15,
  UIM_SESSION_TYPE_CHANNEL_ID_SLOT_3_V01 = 0x16,
  UIM_SESSION_TYPE_CHANNEL_ID_SLOT_4_V01 = 0x17,
  UIM_SESSION_TYPE_CHANNEL_ID_SLOT_5_V01 = 0x18,
  UIM_SESSION_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_session_type_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_session_type_enum_v01 session_type;
  /**<   Indicates the session type. \n Valid values -- 0 to 24.
       \n See Table \ref{tbl:sessions} for available session types.
  */

  uint32_t aid_len;  /**< Must be set to # of elements in aid */
  uint8_t aid[QMI_UIM_AID_MAX_V01];
  /**<   Application identifier value or channel ID. This value is required
       for nonprovisioning and logical channel session types. It is
       ignored in all other cases.
  */
}uim_session_information_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t file_id;
  /**<   File ID.*/

  uint32_t path_len;  /**< Must be set to # of elements in path */
  uint8_t path[QMI_UIM_PATH_MAX_V01];
  /**<   File path. This value must be the complete path of the file, which
       is a sequence block of two bytes (e.g., 0x3F00 0x7FFF).
       If the path is empty, the service can try to compose it automatically
       based on the card type, the session type, and the file ID.
  */
}uim_file_id_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t offset;
  /**<   Offset for the Read operation.*/

  uint16_t length;
  /**<   Length of the content to be read. The value 0 is used to read the
       complete file.
  */
}uim_read_transparent_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Provides read access to any transparent file in the card and
    provides access by the path. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  File ID */
  uim_file_id_type_v01 file_id;

  /* Mandatory */
  /*  Read Transparent */
  uim_read_transparent_type_v01 read_transparent;

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result must be provided
       in a subsequent indication.
  */

  /* Optional */
  /*  Encrypt Data */
  uint8_t encryption_valid;  /**< Must be set to true if encryption is being passed */
  uint8_t encryption;
  /**<   Indicates whether the data read from the card is to be encrypted.*/

  /* Optional */
  /*  Encrypt Request Data */
  uint8_t encryption_ext_valid;  /**< Must be set to true if encryption_ext is being passed */
  uint8_t encryption_ext;
  /**<   Indicates whether the session information, file ID, and data read
       from the card are to be encrypted.
  */
}uim_read_transparent_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t sw1;
  /**<   SW1 status code received from the card.*/

  uint8_t sw2;
  /**<   SW2 status code received from the card.*/
}uim_card_result_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t content_len;  /**< Must be set to # of elements in content */
  uint8_t content[QMI_UIM_CONTENT_TRANSPARENT_MAX_V01];
  /**<   Read content; sequence of bytes as read from the card.*/
}uim_read_transparent_result_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  char mcc[QMI_UIM_MCC_LEN_V01];
  /**<   MCC value in ASCII characters. */

  uint32_t mnc_len;  /**< Must be set to # of elements in mnc */
  char mnc[QMI_UIM_MNC_MAX_V01];
  /**<   MNC value in ASCII characters. */
}uim_plmn_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t plmn_data_len;  /**< Must be set to # of elements in plmn_data */
  uim_plmn_type_v01 plmn_data[QMI_UIM_PLMN_NUM_MAX_V01];
  /**<   PLMN data. */
}uim_plmn_list_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  char mcc[QMI_UIM_MCC_LEN_V01];
  /**<   MCC value in ASCII characters. */

  uint32_t mnc_len;  /**< Must be set to # of elements in mnc */
  char mnc[QMI_UIM_MNC_MAX_V01];
  /**<   MNC value in ASCII characters. */

  uint32_t msin_len;  /**< Must be set to # of elements in msin */
  char msin[QMI_UIM_MSIN_MAX_V01];
  /**<   MSIN value in ASCII characters. */
}uim_imsi_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Provides read access to any transparent file in the card and
    provides access by the path. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message definition.
  */

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;

  /* Optional */
  /*  Read Result */
  uint8_t read_result_valid;  /**< Must be set to true if read_result is being passed */
  uim_read_transparent_result_type_v01 read_result;

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result is provided
       in a subsequent indication.
  */

  /* Optional */
  /*  Encrypted Data */
  uint8_t encryption_valid;  /**< Must be set to true if encryption is being passed */
  uint8_t encryption;
  /**<   Indicates whether the data from the card passed in read_result is
       encrypted.
  */

  /* Optional */
  /*  Requested Length */
  uint8_t file_length_valid;  /**< Must be set to true if file_length is being passed */
  uint16_t file_length;
  /**<   When this TLV is present, the requested length exceeds the maximum size
       supported by the QMI UIM. QMI_ERR_INSUFFICIENT_RESOURCES is returned to
       the client and this value indicates the total length.
  */

  /* Optional */
  /*  Long Data Token */
  uint8_t long_data_token_valid;  /**< Must be set to true if long_data_token is being passed */
  uint32_t long_data_token;
  /**<   When this TLV is present, the requested length exceeds the maximum size
       supported by QMI UIM. QMI_ERR_INSUFFICIENT_ RESOURCES is returned to
       the client, and the result is provided in subsequent indications.
       Long data token is used to reconstruct the entire read response,
       possibly spanning multiple indications.
  */

  /* Optional */
  /*  Read Result With Request Information */
  uint8_t read_result_ext_valid;  /**< Must be set to true if read_result_ext is being passed */
  uint32_t read_result_ext_len;  /**< Must be set to # of elements in read_result_ext */
  uint8_t read_result_ext[QMI_UIM_ENCRYPTED_RESPONSE_MAX_V01];
  /**<   Read request information and content. Includes session information,
       file ID as provided in the read request, and the sequence of bytes as
       read from the card.

       See Section \ref{sec:readResultResp} for the result format.
  */

  /* Optional */
  /*  Parsed PLMN List */
  uint8_t parsed_plmn_list_valid;  /**< Must be set to true if parsed_plmn_list is being passed */
  uim_plmn_list_type_v01 parsed_plmn_list;
  /**<   \n Indicates parsed PLMN data from the card passed in read_result for the
       EF-FPLMN and EF-EHPLMN.
  */

  /* Optional */
  /*  Parsed IMSI */
  uint8_t parsed_imsi_valid;  /**< Must be set to true if parsed_imsi is being passed */
  uim_imsi_type_v01 parsed_imsi;
  /**<   \n Indicates parsed IMSI data from the card passed in read_result for
       EF-IMSI.
  */
}uim_read_transparent_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indication with a read transparent command result. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Mandatory */
  /*  Token of the Original Request */
  uint32_t indication_token;
  /**<   Indicates the token of the original request.*/

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;

  /* Optional */
  /*  Read Result */
  uint8_t read_result_valid;  /**< Must be set to true if read_result is being passed */
  uim_read_transparent_result_type_v01 read_result;

  /* Optional */
  /*  Encrypted Data */
  uint8_t encryption_valid;  /**< Must be set to true if encryption is being passed */
  uint8_t encryption;
  /**<   Indicates whether the data from the card passed in the read_result is
       encrypted.
  */

  /* Optional */
  /*  Requested Length */
  uint8_t file_length_valid;  /**< Must be set to true if file_length is being passed */
  uint16_t file_length;
  /**<   When this TLV is present, the requested length exceeds the maximum size
       supported by the QMI UIM. QMI_ERR_INSUFFICIENT_RESOURCES is returned to
       the client, and this value indicates the total length.
  */

  /* Optional */
  /*  Long Data Token */
  uint8_t long_data_token_valid;  /**< Must be set to true if long_data_token is being passed */
  uint32_t long_data_token;
  /**<   When this TLV is present, the read result exceeds the maximum size
       supported by Read result TLV, and the result is provided in subsequent
       QMI_UIM_READ_TRANSPARENT_ LONG_IND messages. Long data token is used to
       reconstruct the entire read response, possibly spanning multiple
       indications.
  */

  /* Optional */
  /*  Read Result With Request Information */
  uint8_t read_result_ext_valid;  /**< Must be set to true if read_result_ext is being passed */
  uint32_t read_result_ext_len;  /**< Must be set to # of elements in read_result_ext */
  uint8_t read_result_ext[QMI_UIM_ENCRYPTED_RESPONSE_MAX_V01];
  /**<   Read request information and content. Includes session information,
       file ID as provided in the read request, and the sequence of bytes as
       read from the card.

       See Section \ref{sec:readResultResp} for the result format.
  */

  /* Optional */
  /*  Parsed PLMN List */
  uint8_t parsed_plmn_list_valid;  /**< Must be set to true if parsed_plmn_list is being passed */
  uim_plmn_list_type_v01 parsed_plmn_list;
  /**<   \n Indicates parsed PLMN data from the card passed in read_result for the
       EF-FPLMN and EF-EHPLMN.
  */

  /* Optional */
  /*  Parsed IMSI */
  uint8_t parsed_imsi_valid;  /**< Must be set to true if parsed_imsi is being passed */
  uim_imsi_type_v01 parsed_imsi;
  /**<   \n Indicates parsed IMSI data from the card passed in read_result for
       EF-IMSI.
  */
}uim_read_transparent_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t record;
  /**<   Record number (starting from 1).*/

  uint16_t length;
  /**<   Length of the content to be read. The value 0 is used to read the
       complete record.
  */
}uim_read_record_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Provides read access to a specific record in a linear
           fixed or cyclic file in the card and provides access by the path. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  File ID */
  uim_file_id_type_v01 file_id;

  /* Mandatory */
  /*  Read Record */
  uim_read_record_type_v01 read_record;

  /* Optional */
  /*  Last Record */
  uint8_t last_record_valid;  /**< Must be set to true if last_record is being passed */
  uint16_t last_record;
  /**<   Last record. This value is used to read multiple records at the same time.*/

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result must be provided
       in a subsequent indication.
  */
}uim_read_record_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t content_len;  /**< Must be set to # of elements in content */
  uint8_t content[QMI_UIM_CONTENT_RECORD_MAX_V01];
  /**<   Read content. The content is the sequence of bytes as read from the card.*/
}uim_read_record_result_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t additional_record_len;  /**< Must be set to # of elements in additional_record */
  uint8_t additional_record[QMI_UIM_CONTENT_ADDITIONAL_RECORD_MAX_V01];
  /**<   Read content of all the additional records. Each record has
       the same size as the first record.
  */
}uim_read_additional_record_result_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Provides read access to a specific record in a linear
           fixed or cyclic file in the card and provides access by the path. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;

  /* Optional */
  /*  Read Result */
  uint8_t read_result_valid;  /**< Must be set to true if read_result is being passed */
  uim_read_record_result_type_v01 read_result;

  /* Optional */
  /*  Additional Read Result */
  uint8_t additional_read_result_valid;  /**< Must be set to true if additional_read_result is being passed */
  uim_read_additional_record_result_type_v01 additional_read_result;

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result is provided
       in a subsequent indication.
  */
}uim_read_record_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indication with a read record command result. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Mandatory */
  /*  Token of the Original Request */
  uint32_t indication_token;
  /**<   Indicates the token of the original request.*/

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;

  /* Optional */
  /*  Read Result */
  uint8_t read_result_valid;  /**< Must be set to true if read_result is being passed */
  uim_read_record_result_type_v01 read_result;

  /* Optional */
  /*  Additional Read Result */
  uint8_t additional_read_result_valid;  /**< Must be set to true if additional_read_result is being passed */
  uim_read_additional_record_result_type_v01 additional_read_result;
}uim_read_record_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t offset;
  /**<   Offset for the Write operation.*/

  uint32_t data_len;  /**< Must be set to # of elements in data */
  uint8_t data[QMI_UIM_CONTENT_TRANSPARENT_MAX_V01];
  /**<   Content to write.*/
}uim_write_transparent_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Provides write access to any transparent
           file in the card and provides access by the path. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  File ID */
  uim_file_id_type_v01 file_id;

  /* Mandatory */
  /*  Write Transparent */
  uim_write_transparent_type_v01 write_transparent;

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result must be provided
       in a subsequent indication.
  */
}uim_write_transparent_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Provides write access to any transparent
           file in the card and provides access by the path. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result is provided
       in a subsequent indication.
  */
}uim_write_transparent_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indication with a write transparent command result. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Mandatory */
  /*  Token of the Original Request */
  uint32_t indication_token;
  /**<   Indicates the token of the original request.*/

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;
}uim_write_transparent_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t record;
  /**<   Record number (starting from 1). This field is ignored for cyclic files.*/

  uint32_t data_len;  /**< Must be set to # of elements in data */
  uint8_t data[QMI_UIM_CONTENT_RECORD_MAX_V01];
  /**<   Content to write.*/
}uim_write_record_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Provides write access to a specific record in a
             linear fixed or cyclic file in the card and provides access by
             the path. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  File ID */
  uim_file_id_type_v01 file_id;

  /* Mandatory */
  /*  Write Record */
  uim_write_record_type_v01 write_record;

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result must be provided
       in a subsequent indication.
  */
}uim_write_record_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Provides write access to a specific record in a
             linear fixed or cyclic file in the card and provides access by
             the path. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result is provided
       in a subsequent indication.
  */
}uim_write_record_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indication with a write record command result. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Mandatory */
  /*  Token of the Original Request */
  uint32_t indication_token;
  /**<   Indicates the token of the original request.*/

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;
}uim_write_record_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Retrieves the file attributes for any EF or DF in
             the card and provides access by the path. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  File ID */
  uim_file_id_type_v01 file_id;

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result must be provided
       in a subsequent indication.
  */

  /* Optional */
  /*  UICC Security Attributes */
  uint8_t uicc_security_attributes_valid;  /**< Must be set to true if uicc_security_attributes is being passed */
  uint8_t uicc_security_attributes;
  /**<   Indicates whether the security attributes are required by the client.
       Valid values:\n
         - 0 -- Skip security attributes of the file for the UICC card\n
         - 1 -- Return security attributes of the file for the UICC card\n
       If the UICC Security Attributes TLV is missing, security attributes are
       returned. This TLV is ignored for ICC cards.
  */
}uim_get_file_attributes_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_FILE_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_FILE_TYPE_TRANSPARENT_V01 = 0x00, /**<  Transparent \n  */
  UIM_FILE_TYPE_CYCLIC_V01 = 0x01, /**<  Cyclic \n  */
  UIM_FILE_TYPE_LINEAR_FIXED_V01 = 0x02, /**<  Linear fixed \n  */
  UIM_FILE_TYPE_DEDICATED_FILE_V01 = 0x03, /**<  Dedicated file \n  */
  UIM_FILE_TYPE_MASTER_FILE_V01 = 0x04, /**<  Master file \n  */
  UIM_FILE_TYPE_BER_TLV_FILE_V01 = 0x05, /**<  BER-TLV file  */
  UIM_FILE_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_file_type_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_SEC_CONDITION_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_SEC_CONDITION_ALWAYS_V01 = 0x00, /**<  Always \n  */
  UIM_SEC_CONDITION_NEVER_V01 = 0x01, /**<  Never  \n */
  UIM_SEC_CONDITION_AND_COND_V01 = 0x02, /**<  AND condition \n  */
  UIM_SEC_CONDITION_OR_COND_V01 = 0x03, /**<  OR condition \n  */
  UIM_SEC_CONDITION_SINGLE_COND_V01 = 0x04, /**<  Single condition  */
  UIM_SEC_CONDITION_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_sec_condition_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t file_size;
  /**<   File size.*/

  uint16_t file_id;
  /**<   File ID.*/

  uim_file_type_enum_v01 file_type;
  /**<   File type. Valid values:\n
      - UIM_FILE_TYPE_TRANSPARENT (0x00) --  Transparent \n
      - UIM_FILE_TYPE_CYCLIC (0x01) --  Cyclic \n
      - UIM_FILE_TYPE_LINEAR_FIXED (0x02) --  Linear fixed \n
      - UIM_FILE_TYPE_DEDICATED_FILE (0x03) --  Dedicated file \n
      - UIM_FILE_TYPE_MASTER_FILE (0x04) --  Master file \n
      - UIM_FILE_TYPE_BER_TLV_FILE (0x05) --  BER-TLV file
 */

  uint16_t rec_size;
  /**<   Size of the records (only for cyclic and linear fixed files).*/

  uint16_t rec_count;
  /**<   Total number of records (only for linear fixed files).*/

  uim_sec_condition_enum_v01 sec_read;
  /**<   Read security attributes. Valid values:\n
      - UIM_SEC_CONDITION_ALWAYS (0x00) --  Always \n
      - UIM_SEC_CONDITION_NEVER (0x01) --  Never  \n
      - UIM_SEC_CONDITION_AND_COND (0x02) --  AND condition \n
      - UIM_SEC_CONDITION_OR_COND (0x03) --  OR condition \n
      - UIM_SEC_CONDITION_SINGLE_COND (0x04) --  Single condition
 */

  uint16_t sec_read_mask;
  /**<   Mask with read security attributes. This field is valid only when
       required by security attributes. Valid values:\n
         - Bit 0 -- PIN1\n
         - Bit 1 -- PIN2\n
         - Bit 2 -- UPIN\n
         - Bit 3 -- ADM
  */

  uim_sec_condition_enum_v01 sec_write;
  /**<   Write security attributes. Valid values:\n
      - UIM_SEC_CONDITION_ALWAYS (0x00) --  Always \n
      - UIM_SEC_CONDITION_NEVER (0x01) --  Never  \n
      - UIM_SEC_CONDITION_AND_COND (0x02) --  AND condition \n
      - UIM_SEC_CONDITION_OR_COND (0x03) --  OR condition \n
      - UIM_SEC_CONDITION_SINGLE_COND (0x04) --  Single condition
 */

  uint16_t sec_write_mask;
  /**<   Mask with write security attributes. This field is valid only when
       required by security attributes. Valid values:\n
         - Bit 0 -- PIN1\n
         - Bit 1 -- PIN2\n
         - Bit 2 -- UPIN\n
         - Bit 3 -- ADM
  */

  uim_sec_condition_enum_v01 sec_increase;
  /**<   Increase security attributes. Valid values:\n
      - UIM_SEC_CONDITION_ALWAYS (0x00) --  Always \n
      - UIM_SEC_CONDITION_NEVER (0x01) --  Never  \n
      - UIM_SEC_CONDITION_AND_COND (0x02) --  AND condition \n
      - UIM_SEC_CONDITION_OR_COND (0x03) --  OR condition \n
      - UIM_SEC_CONDITION_SINGLE_COND (0x04) --  Single condition
 */

  uint16_t sec_increase_mask;
  /**<   Mask with increase security attributes. This field is valid only when
       required by security attributes. Valid values:\n
         - Bit 0 -- PIN1\n
         - Bit 1 -- PIN2\n
         - Bit 2 -- UPIN\n
         - Bit 3 -- ADM
  */

  uim_sec_condition_enum_v01 sec_deactivate;
  /**<   Deactivate security attributes. Valid values:\n
      - UIM_SEC_CONDITION_ALWAYS (0x00) --  Always \n
      - UIM_SEC_CONDITION_NEVER (0x01) --  Never  \n
      - UIM_SEC_CONDITION_AND_COND (0x02) --  AND condition \n
      - UIM_SEC_CONDITION_OR_COND (0x03) --  OR condition \n
      - UIM_SEC_CONDITION_SINGLE_COND (0x04) --  Single condition
 */

  uint16_t sec_deactivate_mask;
  /**<   Mask with deactivate security attributes. This field is valid only when
       required by security attributes. Valid values:\n
         - Bit 0 -- PIN1\n
         - Bit 1 -- PIN2\n
         - Bit 2 -- UPIN\n
         - Bit 3 -- ADM
  */

  uim_sec_condition_enum_v01 sec_activate;
  /**<   Activate security attributes. Valid values:\n
      - UIM_SEC_CONDITION_ALWAYS (0x00) --  Always \n
      - UIM_SEC_CONDITION_NEVER (0x01) --  Never  \n
      - UIM_SEC_CONDITION_AND_COND (0x02) --  AND condition \n
      - UIM_SEC_CONDITION_OR_COND (0x03) --  OR condition \n
      - UIM_SEC_CONDITION_SINGLE_COND (0x04) --  Single condition
 */

  uint16_t sec_activate_mask;
  /**<   Mask with Activate security attributes. This field is valid only when
       required by security attributes. Valid values:\n
         - Bit 0 -- PIN1\n
         - Bit 1 -- PIN2\n
         - Bit 2 -- UPIN\n
         - Bit 3 -- ADM
  */

  uint32_t raw_value_len;  /**< Must be set to # of elements in raw_value */
  uint8_t raw_value[QMI_UIM_FILE_ATTR_RAW_VALUE_MAX_V01];
  /**<   Raw value of file attributes.*/
}uim_file_attributes_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_FILE_STATUS_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_FILE_STATUS_DEACTIVATED_V01 = 0x00, /**<  File is deactivated. \n  */
  UIM_FILE_STATUS_ACTIVATED_V01 = 0x01, /**<  File is activated.  */
  UIM_FILE_STATUS_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_file_status_type_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Retrieves the file attributes for any EF or DF in
             the card and provides access by the path. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;

  /* Optional */
  /*  File Attributes */
  uint8_t file_attributes_valid;  /**< Must be set to true if file_attributes is being passed */
  uim_file_attributes_type_v01 file_attributes;

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result is provided
       in a subsequent indication.
  */

  /* Optional */
  /*  File Status */
  uint8_t file_status_valid;  /**< Must be set to true if file_status is being passed */
  uim_file_status_type_v01 file_status;
  /**<   Indicates the status of the file. Valid values: \n
      - UIM_FILE_STATUS_DEACTIVATED (0x00) --  File is deactivated. \n
      - UIM_FILE_STATUS_ACTIVATED (0x01) --  File is activated.
 \n
 Other values are reserved for future use and are to be ignored by
 the client.
 */
}uim_get_file_attributes_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indication with a get file attributes command result. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Mandatory */
  /*  Token of the Original Request */
  uint32_t indication_token;
  /**<   Indicates the token of the original request.*/

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;

  /* Optional */
  /*  File Attributes */
  uint8_t file_attributes_valid;  /**< Must be set to true if file_attributes is being passed */
  uim_file_attributes_type_v01 file_attributes;

  /* Optional */
  /*  File Status */
  uint8_t file_status_valid;  /**< Must be set to true if file_status is being passed */
  uim_file_status_type_v01 file_status;
  /**<   Indicates the status of the file. Valid values: \n
      - UIM_FILE_STATUS_DEACTIVATED (0x00) --  File is deactivated. \n
      - UIM_FILE_STATUS_ACTIVATED (0x01) --  File is activated.
 \n
 Other values are reserved for future use and are to be ignored by
 the client.
 */
}uim_get_file_attributes_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t file_id;
  /**<   File ID.*/

  uint32_t path_len;  /**< Must be set to # of elements in path */
  uint8_t path[QMI_UIM_PATH_MAX_V01];
  /**<   Path value. This value must be the complete path of the file, which
       is a sequence block of 2 bytes (e.g., 0x3F00 0x7FFF).
  */
}uim_register_refresh_file_id_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t register_flag;
  /**<   Flag that indicates whether to register or deregister for refresh
       indications. Valid values:\n
         - 0 -- Deregister\n
         - 1 -- Register
  */

  uint8_t vote_for_init;
  /**<   Flag that indicates whether to vote for the init when there is a
       refresh. Valid values:\n
         - 0 -- Client does not vote for initialization\n
         - 1 -- Client votes for initialization
  */

  uint32_t files_len;  /**< Must be set to # of elements in files */
  uim_register_refresh_file_id_type_v01 files[QMI_UIM_REFRESH_FILES_MAX_V01];
  /**<   List of files to register for refresh.*/
}uim_register_refresh_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Registers for file change notifications triggered by the card. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  Register Refresh */
  uim_register_refresh_type_v01 register_refresh;
}uim_refresh_register_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Registers for file change notifications triggered by the card. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_refresh_register_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Enables the client to indicate whether it is OK to start
    the Refresh procedure. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  OK for Refresh */
  uint8_t ok_to_refresh;
  /**<   Indicates whether a refresh is OK. Valid values:\n
         - 0 -- Not OK to refresh\n
         - 1 -- OK to refresh
  */
}uim_refresh_ok_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Enables the client to indicate whether it is OK to start
    the Refresh procedure. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_refresh_ok_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Invoked when the client has finished the Refresh procedure. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  Refresh Complete */
  uint8_t refresh_success;
  /**<   Indicates whether the refresh was successful. Valid values:\n
         - 0 -- Refresh was not completed successfully\n
         - 1 -- Refresh was completed successfully
  */
}uim_refresh_complete_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Invoked when the client has finished the Refresh procedure. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_refresh_complete_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Provides the ability to retrieve the last refresh event. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;
}uim_refresh_get_last_event_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_REFRESH_STAGE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_REFRESH_STAGE_WAIT_FOR_OK_V01 = 0x00, /**<  Waiting for OK to refresh \n  */
  UIM_REFRESH_STAGE_START_V01 = 0x01, /**<  Refresh started \n  */
  UIM_REFRESH_STAGE_END_WITH_SUCCESS_V01 = 0x02, /**<  Refresh ended successfully \n  */
  UIM_REFRESH_STAGE_END_WITH_FAILURE_V01 = 0x03, /**<  Refresh failed  */
  UIM_REFRESH_STAGE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_refresh_stage_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_REFRESH_MODE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_REFRESH_MODE_RESET_V01 = 0x00, /**<  Reset \n  */
  UIM_REFRESH_MODE_INIT_V01 = 0x01, /**<  Init \n  */
  UIM_REFRESH_MODE_INIT_FCN_V01 = 0x02, /**<  Init and FCN \n  */
  UIM_REFRESH_MODE_FCN_V01 = 0x03, /**<  FCN \n  */
  UIM_REFRESH_MODE_INIT_FULL_FCN_V01 = 0x04, /**<  Init and Full FCN \n  */
  UIM_REFRESH_MODE_APP_RESET_V01 = 0x05, /**<  Application reset \n  */
  UIM_REFRESH_MODE_3G_RESET_V01 = 0x06, /**<  3G session reset  */
  UIM_REFRESH_MODE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_refresh_mode_enum_v01;
/**
    @}
  */

typedef uint64_t uim_refresh_enforcement_policy_mask_v01;
#define UIM_REFRESH_ENFORCEMENT_POLICY_NAVIGATING_MENU_V01 ((uim_refresh_enforcement_policy_mask_v01)0x0001ull) /**<  Force immediate refresh when navigating the menu  */
#define UIM_REFRESH_ENFORCEMENT_POLICY_DATA_CALL_V01 ((uim_refresh_enforcement_policy_mask_v01)0x0002ull) /**<  Force immediate refresh when a data call is in progress  */
#define UIM_REFRESH_ENFORCEMENT_POLICY_VOICE_CALL_V01 ((uim_refresh_enforcement_policy_mask_v01)0x0004ull) /**<  Force immediate refresh when a voice call is in progress  */
/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_refresh_stage_enum_v01 stage;
  /**<   Indicates the stage of the refresh procedure. Valid values:\n
      - UIM_REFRESH_STAGE_WAIT_FOR_OK (0x00) --  Waiting for OK to refresh \n
      - UIM_REFRESH_STAGE_START (0x01) --  Refresh started \n
      - UIM_REFRESH_STAGE_END_WITH_SUCCESS (0x02) --  Refresh ended successfully \n
      - UIM_REFRESH_STAGE_END_WITH_FAILURE (0x03) --  Refresh failed
 */

  uim_refresh_mode_enum_v01 mode;
  /**<   Indicates the Refresh mode. Valid values:\n
      - UIM_REFRESH_MODE_RESET (0x00) --  Reset \n
      - UIM_REFRESH_MODE_INIT (0x01) --  Init \n
      - UIM_REFRESH_MODE_INIT_FCN (0x02) --  Init and FCN \n
      - UIM_REFRESH_MODE_FCN (0x03) --  FCN \n
      - UIM_REFRESH_MODE_INIT_FULL_FCN (0x04) --  Init and Full FCN \n
      - UIM_REFRESH_MODE_APP_RESET (0x05) --  Application reset \n
      - UIM_REFRESH_MODE_3G_RESET (0x06) --  3G session reset
 */

  uim_session_type_enum_v01 session_type;
  /**<   Indicates the session type. Valid values: 0 through 7 and 10 through 21.
       See Table \ref{tbl:sessions} for the list of available session types
       with their values and descriptions.
  */

  uint32_t aid_len;  /**< Must be set to # of elements in aid */
  uint8_t aid[QMI_UIM_AID_MAX_V01];
  /**<   Application identifier value. This value is required only for a
       nonprovisioning session type and is ignored in all other cases.
  */

  uint32_t files_len;  /**< Must be set to # of elements in files */
  uim_register_refresh_file_id_type_v01 files[QMI_UIM_REFRESH_FILES_MAX_V01];
  /**<   List of files refreshed.*/
}uim_refresh_event_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Provides the ability to retrieve the last refresh event. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Refresh Event */
  uint8_t refresh_event_valid;  /**< Must be set to true if refresh_event is being passed */
  uim_refresh_event_type_v01 refresh_event;

  /* Optional */
  /*  Refresh Enforcement */
  uint8_t refresh_enforcement_policy_mask_valid;  /**< Must be set to true if refresh_enforcement_policy_mask is being passed */
  uim_refresh_enforcement_policy_mask_v01 refresh_enforcement_policy_mask;
  /**<   Refresh enforcement policy. Values:\n
      - UIM_REFRESH_ENFORCEMENT_POLICY_NAVIGATING_MENU (0x0001) --  Force immediate refresh when navigating the menu
      - UIM_REFRESH_ENFORCEMENT_POLICY_DATA_CALL (0x0002) --  Force immediate refresh when a data call is in progress
      - UIM_REFRESH_ENFORCEMENT_POLICY_VOICE_CALL (0x0004) --  Force immediate refresh when a voice call is in progress
 \n
 All other bits are reserved for future use.
 */
}uim_refresh_get_last_event_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_PIN_OPERATION_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_PIN_OPERATION_DISABLE_V01 = 0x00, /**<  Disable the PIN \n  */
  UIM_PIN_OPERATION_ENABLE_V01 = 0x01, /**<  Enable the PIN  */
  UIM_PIN_OPERATION_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_pin_operation_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_PIN_ID_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_PIN_ID_PIN_1_V01 = 0x01, /**<  PIN1 (also called PIN) \n  */
  UIM_PIN_ID_PIN_2_V01 = 0x02, /**<  PIN2 \n  */
  UIM_PIN_ID_UNIVERSAL_V01 = 0x03, /**<  Universal PIN \n  */
  UIM_PIN_ID_HIDDEN_KEY_V01 = 0x04, /**<  Hidden key  */
  UIM_PIN_ID_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_pin_id_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_pin_id_enum_v01 pin_id;
  /**<   Indicates the PIN ID to be enabled or disabled. Valid values:\n
      - UIM_PIN_ID_PIN_1 (0x01) --  PIN1 (also called PIN) \n
      - UIM_PIN_ID_PIN_2 (0x02) --  PIN2 \n
      - UIM_PIN_ID_UNIVERSAL (0x03) --  Universal PIN \n
      - UIM_PIN_ID_HIDDEN_KEY (0x04) --  Hidden key
 */

  uim_pin_operation_enum_v01 pin_operation;
  /**<   Indicates whether the PIN is enabled or disabled. Valid values:\n
      - UIM_PIN_OPERATION_DISABLE (0x00) --  Disable the PIN \n
      - UIM_PIN_OPERATION_ENABLE (0x01) --  Enable the PIN
 */

  uint32_t pin_value_len;  /**< Must be set to # of elements in pin_value */
  char pin_value[QMI_UIM_PIN_MAX_V01];
  /**<   PIN value. This value is a sequence of ASCII characters.*/
}uim_set_pin_protection_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_PIN_KEY_REF_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_PIN_KEY_REF_APPL_1_V01 = 0x01,
  UIM_PIN_KEY_REF_APPL_2_V01 = 0x02,
  UIM_PIN_KEY_REF_APPL_3_V01 = 0x03,
  UIM_PIN_KEY_REF_APPL_4_V01 = 0x04,
  UIM_PIN_KEY_REF_APPL_5_V01 = 0x05,
  UIM_PIN_KEY_REF_APPL_6_V01 = 0x06,
  UIM_PIN_KEY_REF_APPL_7_V01 = 0x07,
  UIM_PIN_KEY_REF_APPL_8_V01 = 0x08,
  UIM_PIN_KEY_REF_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_pin_key_ref_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Enables or disables the protection of the UIM contents by a
    specific PIN. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  Set PIN Protection */
  uim_set_pin_protection_type_v01 set_pin_protection;

  /* Optional */
  /*  Key Reference ID */
  uint8_t pin_key_ref_id_valid;  /**< Must be set to true if pin_key_ref_id is being passed */
  uim_pin_key_ref_enum_v01 pin_key_ref_id;
  /**<   Indicates the PIN key reference ID. Valid values are from 1 to 8,
       respectively, for application 1 to application 8, as specified in
       \hyperref[E102221]{ETSI TS 102 221}. This TLV is used only for PIN1 and PIN2 and
       is ignored in all other cases.
  */

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result must be provided
       in a subsequent indication.
  */
}uim_set_pin_protection_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t verify_left;
  /**<   Number of remaining attempts to verify the PIN.*/

  uint8_t unblock_left;
  /**<   Number of remaining attempts to unblock the PIN.*/
}uim_pin_retries_left_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t enc_pin1_value_len;  /**< Must be set to # of elements in enc_pin1_value */
  uint8_t enc_pin1_value[QMI_UIM_ENCRYPTED_PIN_MAX_V01];
  /**<   Encrypted PIN1 value.*/
}uim_encrypted_pin_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Enables or disables the protection of the UIM contents by a
    specific PIN. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Retries Remaining (This value is returned only when the enable/disable
      operation has failed.)
   */
  uint8_t retries_left_valid;  /**< Must be set to true if retries_left is being passed */
  uim_pin_retries_left_type_v01 retries_left;

  /* Optional */
  /*  Encrypted PIN1 (This value is returned only when PIN1 is enabled
      successfully and the feature is supported.)
   */
  uint8_t encrypted_pin1_valid;  /**< Must be set to true if encrypted_pin1 is being passed */
  uim_encrypted_pin_type_v01 encrypted_pin1;

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result is provided
       in a subsequent indication.
  */

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;
}uim_set_pin_protection_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indication with a set PIN protection command result. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message definition.
  */

  /* Mandatory */
  /*  Token of the Original Request */
  uint32_t indication_token;
  /**<   Indicates the token of the original request.*/

  /* Optional */
  /*  Retries Remaining (This value is returned only when the PIN operation
      has failed.)
   */
  uint8_t retries_left_valid;  /**< Must be set to true if retries_left is being passed */
  uim_pin_retries_left_type_v01 retries_left;

  /* Optional */
  /*  Encrypted PIN1 (This value is returned only when PIN1 operation is
      completed successfully and the feature is supported.)
   */
  uint8_t encrypted_pin1_valid;  /**< Must be set to true if encrypted_pin1 is being passed */
  uim_encrypted_pin_type_v01 encrypted_pin1;

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;
}uim_set_pin_protection_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_pin_id_enum_v01 pin_id;
  /**<   Indicates the PIN ID to be verified. Valid values:\n
      - UIM_PIN_ID_PIN_1 (0x01) --  PIN1 (also called PIN) \n
      - UIM_PIN_ID_PIN_2 (0x02) --  PIN2 \n
      - UIM_PIN_ID_UNIVERSAL (0x03) --  Universal PIN \n
      - UIM_PIN_ID_HIDDEN_KEY (0x04) --  Hidden key
 */

  uint32_t pin_value_len;  /**< Must be set to # of elements in pin_value */
  char pin_value[QMI_UIM_PIN_MAX_V01];
  /**<   PIN value. This value is a sequence of ASCII characters.*/
}uim_verify_pin_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Verifies the PIN before the card content is accessed. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  Verify PIN */
  uim_verify_pin_type_v01 verify_pin;

  /* Optional */
  /*  Encrypted Value of PIN1 (This field can be used only when the PIN type is
      PIN1.)
   */
  uint8_t encrypted_pin1_valid;  /**< Must be set to true if encrypted_pin1 is being passed */
  uim_encrypted_pin_type_v01 encrypted_pin1;

  /* Optional */
  /*  Key Reference ID */
  uint8_t pin_key_ref_id_valid;  /**< Must be set to true if pin_key_ref_id is being passed */
  uim_pin_key_ref_enum_v01 pin_key_ref_id;
  /**<   Indicates the PIN key reference ID. Valid values are from 1 to 8,
       respectively, for application 1 to application 8, as specified in
       \hyperref[E102221]{ETSI TS 102 221}. This TLV is used only for PIN1 and PIN2 and is
       ignored in all other cases.
  */

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result must be provided
       in a subsequent indication.
  */
}uim_verify_pin_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Verifies the PIN before the card content is accessed. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Retries Remaining (This value is returned only when the verify operation
      fails.)
   */
  uint8_t retries_left_valid;  /**< Must be set to true if retries_left is being passed */
  uim_pin_retries_left_type_v01 retries_left;

  /* Optional */
  /*  Encrypted PIN1 (This value is returned only when PIN1 is verified
      successfully and the feature is supported.)
   */
  uint8_t encrypted_pin1_valid;  /**< Must be set to true if encrypted_pin1 is being passed */
  uim_encrypted_pin_type_v01 encrypted_pin1;

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result is provided
       in a subsequent indication.
  */

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;
}uim_verify_pin_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indication with a verify PIN command result. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Mandatory */
  /*  Token of the Original Request */
  uint32_t indication_token;
  /**<   Indicates the token of the original request.*/

  /* Optional */
  /*  Retries Remaining (This value is returned only when the PIN operation
      has failed.)
   */
  uint8_t retries_left_valid;  /**< Must be set to true if retries_left is being passed */
  uim_pin_retries_left_type_v01 retries_left;

  /* Optional */
  /*  Encrypted PIN1 (This value is returned only when PIN1 operation is
      completed successfully and the feature is supported.)
   */
  uint8_t encrypted_pin1_valid;  /**< Must be set to true if encrypted_pin1 is being passed */
  uim_encrypted_pin_type_v01 encrypted_pin1;

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;
}uim_verify_pin_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_pin_id_enum_v01 pin_id;
  /**<   Indicates the PIN ID to be unblocked. Valid values:\n
      - UIM_PIN_ID_PIN_1 (0x01) --  PIN1 (also called PIN) \n
      - UIM_PIN_ID_PIN_2 (0x02) --  PIN2 \n
      - UIM_PIN_ID_UNIVERSAL (0x03) --  Universal PIN \n
 */

  uint32_t puk_value_len;  /**< Must be set to # of elements in puk_value */
  char puk_value[QMI_UIM_PIN_MAX_V01];
  /**<   PIN unlock key value. This value is a sequence of ASCII characters.*/

  uint32_t new_pin_value_len;  /**< Must be set to # of elements in new_pin_value */
  char new_pin_value[QMI_UIM_PIN_MAX_V01];
  /**<   New PIN value. This value is a sequence of ASCII characters.*/
}uim_unblock_pin_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Unblocks a blocked PIN using the PUK code. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  Unblock PIN */
  uim_unblock_pin_type_v01 unblock_pin;

  /* Optional */
  /*  Key Reference ID */
  uint8_t pin_key_ref_id_valid;  /**< Must be set to true if pin_key_ref_id is being passed */
  uim_pin_key_ref_enum_v01 pin_key_ref_id;
  /**<   Indicates the PIN key reference ID. Valid values are from 1 to 8,
       respectively, for application 1 to application 8, as specified in
       \hyperref[E102221]{ETSI TS 102 221}. This TLV is used only for PIN1 and PIN2 and is
       ignored in all other cases.
  */

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result must be provided
       in a subsequent indication.
  */
}uim_unblock_pin_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Unblocks a blocked PIN using the PUK code. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Retries Remaining (This value is returned only when the unblock operation
      fails.)
   */
  uint8_t retries_left_valid;  /**< Must be set to true if retries_left is being passed */
  uim_pin_retries_left_type_v01 retries_left;

  /* Optional */
  /*  Encrypted PIN1 (This value is returned only when PIN1 is unblocked
      successfully and the feature is supported.)
   */
  uint8_t encrypted_pin1_valid;  /**< Must be set to true if encrypted_pin1 is being passed */
  uim_encrypted_pin_type_v01 encrypted_pin1;

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result is provided
       in a subsequent indication.
  */

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;
}uim_unblock_pin_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indication with an unblock PIN command result. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Mandatory */
  /*  Token of the Original Request */
  uint32_t indication_token;
  /**<   Indicates the token of the original request.*/

  /* Optional */
  /*  Retries Remaining (This value is returned only when the PIN operation
      has failed.)
   */
  uint8_t retries_left_valid;  /**< Must be set to true if retries_left is being passed */
  uim_pin_retries_left_type_v01 retries_left;

  /* Optional */
  /*  Encrypted PIN1 (This value is returned only when PIN1 operation is
      completed successfully and the feature is supported.)
   */
  uint8_t encrypted_pin1_valid;  /**< Must be set to true if encrypted_pin1 is being passed */
  uim_encrypted_pin_type_v01 encrypted_pin1;

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;
}uim_unblock_pin_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_pin_id_enum_v01 pin_id;
  /**<   Indicates the PIN ID to be changed. Valid values:\n
      - UIM_PIN_ID_PIN_1 (0x01) --  PIN1 (also called PIN) \n
      - UIM_PIN_ID_PIN_2 (0x02) --  PIN2 \n
      - UIM_PIN_ID_UNIVERSAL (0x03) --  Universal PIN \n
      - UIM_PIN_ID_HIDDEN_KEY (0x04) --  Hidden key
 */

  uint32_t old_pin_value_len;  /**< Must be set to # of elements in old_pin_value */
  char old_pin_value[QMI_UIM_PIN_MAX_V01];
  /**<   Old PIN value. The value is a sequence of ASCII characters.*/

  uint32_t new_pin_value_len;  /**< Must be set to # of elements in new_pin_value */
  char new_pin_value[QMI_UIM_PIN_MAX_V01];
  /**<   New PIN value. This value is a sequence of ASCII characters.*/
}uim_change_pin_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Changes the value of the specified PIN. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  Change PIN */
  uim_change_pin_type_v01 change_pin;

  /* Optional */
  /*  Key Reference ID */
  uint8_t pin_key_ref_id_valid;  /**< Must be set to true if pin_key_ref_id is being passed */
  uim_pin_key_ref_enum_v01 pin_key_ref_id;
  /**<   Indicates the PIN key reference ID. Valid values are from 1 to 8,
       respectively,  for application 1 to application 8, as specified in
       \hyperref[E102221]{ETSI TS 102 221}. This TLV is used only for PIN1 and PIN2 and
       ignored in all other cases.
  */

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result must be provided
       in a subsequent indication.
  */
}uim_change_pin_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Changes the value of the specified PIN. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Retries Remaining (This value is returned only when the change PIN
      operation fails.)
   */
  uint8_t retries_left_valid;  /**< Must be set to true if retries_left is being passed */
  uim_pin_retries_left_type_v01 retries_left;

  /* Optional */
  /*  Encrypted PIN1 (This value is returned only when PIN1 is changed
      successfully and the feature is supported.)
   */
  uint8_t encrypted_pin1_valid;  /**< Must be set to true if encrypted_pin1 is being passed */
  uim_encrypted_pin_type_v01 encrypted_pin1;

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result is provided
       in a subsequent indication.
  */

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;
}uim_change_pin_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indication with a change PIN command result. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Mandatory */
  /*  Token of the Original Request */
  uint32_t indication_token;
  /**<   Indicates the token of the original request.*/

  /* Optional */
  /*  Retries Remaining (This value is returned only when the PIN operation
      has failed.)
   */
  uint8_t retries_left_valid;  /**< Must be set to true if retries_left is being passed */
  uim_pin_retries_left_type_v01 retries_left;

  /* Optional */
  /*  Encrypted PIN1 (This value is returned only when PIN1 operation is
      completed successfully and the feature is supported.)
   */
  uint8_t encrypted_pin1_valid;  /**< Must be set to true if encrypted_pin1 is being passed */
  uim_encrypted_pin_type_v01 encrypted_pin1;

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;
}uim_change_pin_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_PERSO_FEATURE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_PERSO_FEATURE_GW_NETWORK_V01 = 0x00, /**<  GW network personalization \n  */
  UIM_PERSO_FEATURE_GW_NETWORK_SUBSET_V01 = 0x01, /**<  GW network subset personalization \n  */
  UIM_PERSO_FEATURE_GW_SERVICE_PROVIDER_V01 = 0x02, /**<  GW service provider personalization \n  */
  UIM_PERSO_FEATURE_GW_CORPORATE_V01 = 0x03, /**<  GW corporate personalization \n  */
  UIM_PERSO_FEATURE_GW_UIM_V01 = 0x04, /**<  GW UIM personalization \n  */
  UIM_PERSO_FEATURE_1X_NETWORK_TYPE_1_V01 = 0x05, /**<  1X network type 1 personalization \n  */
  UIM_PERSO_FEATURE_1X_NETWORK_TYPE_2_V01 = 0x06, /**<  1X network type 2 personalization \n  */
  UIM_PERSO_FEATURE_1X_HRPD_V01 = 0x07, /**<  1X HRPD personalization \n  */
  UIM_PERSO_FEATURE_1X_SERVICE_PROVIDER_V01 = 0x08, /**<  1X service provider personalization \n  */
  UIM_PERSO_FEATURE_1X_CORPORATE_V01 = 0x09, /**<  1X corporate personalization \n  */
  UIM_PERSO_FEATURE_1X_RUIM_V01 = 0x0A, /**<  1X RUIM personalization \n  */
  UIM_PERSO_FEATURE_GW_SPN_V01 = 0x0B, /**<  GW SPN personalization \n  */
  UIM_PERSO_FEATURE_GW_SP_EHPLMN_V01 = 0x0C, /**<  GW SP + EHPLMN personalization \n  */
  UIM_PERSO_FEATURE_GW_ICCID_V01 = 0x0D, /**<  GW ICCID personalization \n  */
  UIM_PERSO_FEATURE_GW_IMPI_V01 = 0x0E, /**<  GW IMPI personalization \n  */
  UIM_PERSO_FEATURE_GW_NETWORK_SUBSET_SERVICE_PROVIDER_V01 = 0x0F, /**<  GW network subset and service provider personalization  */
  UIM_PERSO_FEATURE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_perso_feature_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_PERSO_OPERATION_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_PERSO_OPERATION_DEACTIVATE_V01 = 0x00, /**<  Deactivate personalization \n  */
  UIM_PERSO_OPERATION_UNBLOCK_V01 = 0x01, /**<  Unblock personalization  */
  UIM_PERSO_OPERATION_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_perso_operation_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_perso_feature_enum_v01 feature;
  /**<   Indicates the personalization feature to deactivate or unblock.
 Valid values:\n
      - UIM_PERSO_FEATURE_GW_NETWORK (0x00) --  GW network personalization \n
      - UIM_PERSO_FEATURE_GW_NETWORK_SUBSET (0x01) --  GW network subset personalization \n
      - UIM_PERSO_FEATURE_GW_SERVICE_PROVIDER (0x02) --  GW service provider personalization \n
      - UIM_PERSO_FEATURE_GW_CORPORATE (0x03) --  GW corporate personalization \n
      - UIM_PERSO_FEATURE_GW_UIM (0x04) --  GW UIM personalization \n
      - UIM_PERSO_FEATURE_1X_NETWORK_TYPE_1 (0x05) --  1X network type 1 personalization \n
      - UIM_PERSO_FEATURE_1X_NETWORK_TYPE_2 (0x06) --  1X network type 2 personalization \n
      - UIM_PERSO_FEATURE_1X_HRPD (0x07) --  1X HRPD personalization \n
      - UIM_PERSO_FEATURE_1X_SERVICE_PROVIDER (0x08) --  1X service provider personalization \n
      - UIM_PERSO_FEATURE_1X_CORPORATE (0x09) --  1X corporate personalization \n
      - UIM_PERSO_FEATURE_1X_RUIM (0x0A) --  1X RUIM personalization \n
      - UIM_PERSO_FEATURE_GW_SPN (0x0B) --  GW SPN personalization \n
      - UIM_PERSO_FEATURE_GW_SP_EHPLMN (0x0C) --  GW SP + EHPLMN personalization \n
      - UIM_PERSO_FEATURE_GW_ICCID (0x0D) --  GW ICCID personalization \n
      - UIM_PERSO_FEATURE_GW_IMPI (0x0E) --  GW IMPI personalization \n
      - UIM_PERSO_FEATURE_GW_NETWORK_SUBSET_SERVICE_PROVIDER (0x0F) --  GW network subset and service provider personalization
 */

  uim_perso_operation_enum_v01 operation;
  /**<   Indicates the operation to perform. Valid values:\n
      - UIM_PERSO_OPERATION_DEACTIVATE (0x00) --  Deactivate personalization \n
      - UIM_PERSO_OPERATION_UNBLOCK (0x01) --  Unblock personalization
 */

  uint32_t ck_value_len;  /**< Must be set to # of elements in ck_value */
  char ck_value[QMI_UIM_CK_MAX_V01];
  /**<   Control key value. This value is a sequence of ASCII characters.*/
}uim_depersonalization_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_SLOT_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_SLOT_1_V01 = 0x01, /**<  Slot 1 \n  */
  UIM_SLOT_2_V01 = 0x02, /**<  Slot 2 \n  */
  UIM_SLOT_3_V01 = 0x03, /**<  Slot 3 \n  */
  UIM_SLOT_4_V01 = 0x04, /**<  Slot 4 \n  */
  UIM_SLOT_5_V01 = 0x05, /**<  Slot 5  */
  UIM_SLOT_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_slot_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Deactivates or unblocks the personalization on the phone. */
typedef struct {

  /* Mandatory */
  /*  Depersonalization */
  uim_depersonalization_type_v01 depersonalization;

  /* Optional */
  /*  Slot */
  uint8_t slot_valid;  /**< Must be set to true if slot is being passed */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot to be used. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */
}uim_depersonalization_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t verify_left;
  /**<   Number of the remaining attempts to verify the personalization. */

  uint8_t unblock_left;
  /**<   Number of the remaining attempts to unblock the personalization. */
}uim_perso_retries_left_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Deactivates or unblocks the personalization on the phone. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Retries Remaining */
  uint8_t retries_left_valid;  /**< Must be set to true if retries_left is being passed */
  uim_perso_retries_left_type_v01 retries_left;
  /**<   \n
       This value is returned only when deactivation or unblock fails.
  */
}uim_depersonalization_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Powers down the card. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot to be used. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */
}uim_power_down_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Powers down the card. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_power_down_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_CARD_MODE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_CARD_MODE_TELECOM_CARD_V01 = 0x00, /**<  Telecom card (default) \n  */
  UIM_CARD_MODE_NON_TELECOM_CARD_V01 = 0x01, /**<  Non-telecom card  */
  UIM_CARD_MODE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_card_mode_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Powers up the card. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot to be used. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Optional */
  /*  Ignore Hot-Swap Switch */
  uint8_t ignore_hotswap_switch_valid;  /**< Must be set to true if ignore_hotswap_switch is being passed */
  uint8_t ignore_hotswap_switch;
  /**<   Indicates if the hot-swap switch is to be ignored during the
       initialization of the card. Valid values:\n
        - 0 -- Checks the hot-swap switch status\n
        - 1 -- Ignores the hot-swap switch status
  */

  /* Optional */
  /*  Card Mode */
  uint8_t card_mode_valid;  /**< Must be set to true if card_mode is being passed */
  uim_card_mode_enum_v01 card_mode;
  /**<   Indicates the mode to be used to initialize the card.
 Valid values:\n
      - UIM_CARD_MODE_TELECOM_CARD (0x00) --  Telecom card (default) \n
      - UIM_CARD_MODE_NON_TELECOM_CARD (0x01) --  Non-telecom card
 \n
 Other values are possible and reserved for future use.
 */
}uim_power_up_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Powers up the card. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_power_up_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Retrieves the current status of the card. */
typedef struct {

  /* Optional */
  /*  Extended Card Status */
  uint8_t extended_card_status_valid;  /**< Must be set to true if extended_card_status is being passed */
  uint8_t extended_card_status;
  /**<   Indicates whether the extended card status is requested. Valid values:\n
         - 0 -- Legacy card status (up to 2 cards)\n
         - 1 -- Extended card status\n
       If the Extended Card Status TLV is missing, the legacy card status with
       support for only 2 cards is returned.
  */
}uim_get_card_status_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_CARD_STATE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_CARD_STATE_ABSENT_V01 = 0x00, /**<  Absent \n  */
  UIM_CARD_STATE_PRESENT_V01 = 0x01, /**<  Present \n  */
  UIM_CARD_STATE_ERROR_V01 = 0x02, /**<  Error  */
  UIM_CARD_STATE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_card_state_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_EXTENDED_CARD_STATE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_EXTENDED_CARD_STATE_ABSENT_V01 = 0x00, /**<  Absent \n  */
  UIM_EXTENDED_CARD_STATE_PRESENT_V01 = 0x01, /**<  Present \n  */
  UIM_EXTENDED_CARD_STATE_ERROR_V01 = 0x02, /**<  Error \n  */
  UIM_EXTENDED_CARD_STATE_UNKNOWN_V01 = 0x03, /**<  Unknown  */
  UIM_EXTENDED_CARD_STATE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_extended_card_state_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_PIN_STATE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_PIN_STATE_UNKNOWN_V01 = 0x00, /**<  Unknown \n  */
  UIM_PIN_STATE_ENABLED_NOT_VERIFIED_V01 = 0x01, /**<  Enabled and not verified \n  */
  UIM_PIN_STATE_ENABLED_VERIFIED_V01 = 0x02, /**<  Enabled and verified \n  */
  UIM_PIN_STATE_DISABLED_V01 = 0x03, /**<  Disabled \n  */
  UIM_PIN_STATE_BLOCKED_V01 = 0x04, /**<  Blocked \n  */
  UIM_PIN_STATE_PERMANENTLY_BLOCKED_V01 = 0x05, /**<  Permanently blocked  */
  UIM_PIN_STATE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_pin_state_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_CARD_ERROR_CODE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_CARD_ERROR_CODE_UNKNOWN_V01 = 0x00, /**<  Unknown\n  */
  UIM_CARD_ERROR_CODE_POWER_DOWN_V01 = 0x01, /**<  Power down\n  */
  UIM_CARD_ERROR_CODE_POLL_ERROR_V01 = 0x02, /**<  Poll error\n  */
  UIM_CARD_ERROR_CODE_NO_ATR_RECEIVED_V01 = 0x03, /**<  No ATR received\n  */
  UIM_CARD_ERROR_CODE_VOLT_MISMATCH_V01 = 0x04, /**<  Volt mismatch\n  */
  UIM_CARD_ERROR_CODE_PARITY_ERROR_V01 = 0x05, /**<  Parity error\n  */
  UIM_CARD_ERROR_CODE_POSSIBLY_REMOVED_V01 = 0x06, /**<  Unknown, possibly removed\n  */
  UIM_CARD_ERROR_CODE_SIM_TECHNICAL_PROBLEMS_V01 = 0x07, /**<  Card returned technical problems\n  */
  UIM_CARD_ERROR_CODE_NULL_BYTES_V01 = 0x08, /**<  Card returned NULL bytes\n  */
  UIM_CARD_ERROR_CODE_SAP_CONNECTED_V01 = 0x09, /**<  Terminal in SAP mode  */
  UIM_CARD_ERROR_CODE_CMD_TIMEOUT_V01 = 0x0A, /**<  Command Timeout error  */
  UIM_CARD_ERROR_CODE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_card_error_code_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_APP_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_APP_TYPE_UNKNOWN_V01 = 0x00, /**<  Unknown \n  */
  UIM_APP_TYPE_SIM_V01 = 0x01, /**<  SIM card \n  */
  UIM_APP_TYPE_USIM_V01 = 0x02, /**<  USIM application \n  */
  UIM_APP_TYPE_RUIM_V01 = 0x03, /**<  RUIM card \n  */
  UIM_APP_TYPE_CSIM_V01 = 0x04, /**<  CSIM application \n  */
  UIM_APP_TYPE_ISIM_V01 = 0x05, /**<  ISIM application  */
  UIM_APP_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_app_type_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_APP_STATE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_APP_STATE_UNKNOWN_V01 = 0x00, /**<  Unknown \n  */
  UIM_APP_STATE_DETECTED_V01 = 0x01, /**<  Detected \n  */
  UIM_APP_STATE_PIN1_OR_UPIN_REQ_V01 = 0x02, /**<  PIN1 or UPIN is required \n  */
  UIM_APP_STATE_PUK1_OR_PUK_REQ_V01 = 0x03, /**<  PUK1 or PUK for UPIN is required \n  */
  UIM_APP_STATE_PERSON_CHECK_REQ_V01 = 0x04, /**<  Personalization state must be checked \n  */
  UIM_APP_STATE_PIN1_PERM_BLOCKED_V01 = 0x05, /**<  PIN1 is blocked \n  */
  UIM_APP_STATE_ILLEGAL_V01 = 0x06, /**<  Illegal \n  */
  UIM_APP_STATE_READY_V01 = 0x07, /**<  Ready  */
  UIM_APP_STATE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_app_state_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_PERSO_STATE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_PERSO_STATE_UNKNOWN_V01 = 0x00, /**<  Unknown \n  */
  UIM_PERSO_STATE_IN_PROGRESS_V01 = 0x01, /**<  Personalization operation is in progress \n  */
  UIM_PERSO_STATE_READY_V01 = 0x02, /**<  Ready \n  */
  UIM_PERSO_STATE_CODE_REQ_V01 = 0x03, /**<  Personalization code is required \n  */
  UIM_PERSO_STATE_PUK_REQ_V01 = 0x04, /**<  PUK for personalization code is required \n  */
  UIM_PERSO_STATE_PERMANENTLY_BLOCKED_V01 = 0x05, /**<  Permanently blocked  */
  UIM_PERSO_STATE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_perso_state_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_UNIV_PIN_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_UNIV_PIN_PIN1_USED_V01 = 0x00, /**<  PIN1 is used \n  */
  UIM_UNIV_PIN_UPIN_REPLACES_PIN1_V01 = 0x01, /**<  UPIN replaces PIN1  */
  UIM_UNIV_PIN_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_univ_pin_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_PERSO_FEATURE_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_PERSO_FEATURE_STATUS_GW_NETWORK_V01 = 0x00, /**<  GW network personalization \n  */
  UIM_PERSO_FEATURE_STATUS_GW_NETWORK_SUBSET_V01 = 0x01, /**<  GW network subset personalization \n  */
  UIM_PERSO_FEATURE_STATUS_GW_SERVICE_PROVIDER_V01 = 0x02, /**<  GW service provider personalization \n  */
  UIM_PERSO_FEATURE_STATUS_GW_CORPORATE_V01 = 0x03, /**<  GW corporate personalization \n  */
  UIM_PERSO_FEATURE_STATUS_GW_UIM_V01 = 0x04, /**<  GW UIM personalization \n  */
  UIM_PERSO_FEATURE_STATUS_1X_NETWORK_TYPE_1_V01 = 0x05, /**<  1X network type 1 personalization \n  */
  UIM_PERSO_FEATURE_STATUS_1X_NETWORK_TYPE_2_V01 = 0x06, /**<  1X network type 2 personalization \n  */
  UIM_PERSO_FEATURE_STATUS_1X_HRPD_V01 = 0x07, /**<  1X HRPD personalization \n  */
  UIM_PERSO_FEATURE_STATUS_1X_SERVICE_PROVIDER_V01 = 0x08, /**<  1X service provider personalization \n  */
  UIM_PERSO_FEATURE_STATUS_1X_CORPORATE_V01 = 0x09, /**<  1X corporate personalization \n  */
  UIM_PERSO_FEATURE_STATUS_1X_RUIM_V01 = 0x0A, /**<  1X RUIM personalization \n  */
  UIM_PERSO_FEATURE_STATUS_UNKNOWN_V01 = 0x0B, /**<  Unknown \n  */
  UIM_PERSO_FEATURE_STATUS_GW_SERVICE_PROVIDER_NAME_V01 = 0x0C, /**<  GW service provider name personalization \n  */
  UIM_PERSO_FEATURE_STATUS_GW_SP_EHPLMN_V01 = 0x0D, /**<  GW service provider with equivalent HPLMN personalization \n  */
  UIM_PERSO_FEATURE_STATUS_GW_ICCID_V01 = 0x0E, /**<  GW ICCID personalization \n  */
  UIM_PERSO_FEATURE_STATUS_GW_IMPI_V01 = 0x0F, /**<  GW IMPI personalization \n  */
  UIM_PERSO_FEATURE_STATUS_GW_NETWORK_SUBSET_SERVICE_PROVIDER_V01 = 0x10, /**<  GW network subset and service provider personalization  */
  UIM_PERSO_FEATURE_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_perso_feature_status_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_pin_state_enum_v01 pin_state;
  /**<   Indicates the state of PIN. Valid values:\n
      - UIM_PIN_STATE_UNKNOWN (0x00) --  Unknown \n
      - UIM_PIN_STATE_ENABLED_NOT_VERIFIED (0x01) --  Enabled and not verified \n
      - UIM_PIN_STATE_ENABLED_VERIFIED (0x02) --  Enabled and verified \n
      - UIM_PIN_STATE_DISABLED (0x03) --  Disabled \n
      - UIM_PIN_STATE_BLOCKED (0x04) --  Blocked \n
      - UIM_PIN_STATE_PERMANENTLY_BLOCKED (0x05) --  Permanently blocked
 */

  uint8_t pin_retries;
  /**<   Indicates the number of retries remaining to verify this PIN.*/

  uint8_t puk_retries;
  /**<   Indicates the number of retries remaining to unblock this PIN.*/
}uim_pin_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_app_type_enum_v01 app_type;
  /**<   Indicates the type of the application. Valid values:\n
      - UIM_APP_TYPE_UNKNOWN (0x00) --  Unknown \n
      - UIM_APP_TYPE_SIM (0x01) --  SIM card \n
      - UIM_APP_TYPE_USIM (0x02) --  USIM application \n
      - UIM_APP_TYPE_RUIM (0x03) --  RUIM card \n
      - UIM_APP_TYPE_CSIM (0x04) --  CSIM application \n
      - UIM_APP_TYPE_ISIM (0x05) --  ISIM application
 \n
 Other values are reserved for the future and are to be handled as
 ``Unknown''.
 */

  uim_app_state_enum_v01 app_state;
  /**<   Indicates the state of the application. Valid values:\n
      - UIM_APP_STATE_UNKNOWN (0x00) --  Unknown \n
      - UIM_APP_STATE_DETECTED (0x01) --  Detected \n
      - UIM_APP_STATE_PIN1_OR_UPIN_REQ (0x02) --  PIN1 or UPIN is required \n
      - UIM_APP_STATE_PUK1_OR_PUK_REQ (0x03) --  PUK1 or PUK for UPIN is required \n
      - UIM_APP_STATE_PERSON_CHECK_REQ (0x04) --  Personalization state must be checked \n
      - UIM_APP_STATE_PIN1_PERM_BLOCKED (0x05) --  PIN1 is blocked \n
      - UIM_APP_STATE_ILLEGAL (0x06) --  Illegal \n
      - UIM_APP_STATE_READY (0x07) --  Ready
 */

  uim_perso_state_enum_v01 perso_state;
  /**<   Indicates the state of the personalization for the application.
 Valid values:\n
      - UIM_PERSO_STATE_UNKNOWN (0x00) --  Unknown \n
      - UIM_PERSO_STATE_IN_PROGRESS (0x01) --  Personalization operation is in progress \n
      - UIM_PERSO_STATE_READY (0x02) --  Ready \n
      - UIM_PERSO_STATE_CODE_REQ (0x03) --  Personalization code is required \n
      - UIM_PERSO_STATE_PUK_REQ (0x04) --  PUK for personalization code is required \n
      - UIM_PERSO_STATE_PERMANENTLY_BLOCKED (0x05) --  Permanently blocked
 */

  uim_perso_feature_status_enum_v01 perso_feature;
  /**<   Indicates the personalization feature. This applies only when a
 personalization code is required to deactivate or unblock
 personalization. Valid values:\n
      - UIM_PERSO_FEATURE_STATUS_GW_NETWORK (0x00) --  GW network personalization \n
      - UIM_PERSO_FEATURE_STATUS_GW_NETWORK_SUBSET (0x01) --  GW network subset personalization \n
      - UIM_PERSO_FEATURE_STATUS_GW_SERVICE_PROVIDER (0x02) --  GW service provider personalization \n
      - UIM_PERSO_FEATURE_STATUS_GW_CORPORATE (0x03) --  GW corporate personalization \n
      - UIM_PERSO_FEATURE_STATUS_GW_UIM (0x04) --  GW UIM personalization \n
      - UIM_PERSO_FEATURE_STATUS_1X_NETWORK_TYPE_1 (0x05) --  1X network type 1 personalization \n
      - UIM_PERSO_FEATURE_STATUS_1X_NETWORK_TYPE_2 (0x06) --  1X network type 2 personalization \n
      - UIM_PERSO_FEATURE_STATUS_1X_HRPD (0x07) --  1X HRPD personalization \n
      - UIM_PERSO_FEATURE_STATUS_1X_SERVICE_PROVIDER (0x08) --  1X service provider personalization \n
      - UIM_PERSO_FEATURE_STATUS_1X_CORPORATE (0x09) --  1X corporate personalization \n
      - UIM_PERSO_FEATURE_STATUS_1X_RUIM (0x0A) --  1X RUIM personalization \n
      - UIM_PERSO_FEATURE_STATUS_UNKNOWN (0x0B) --  Unknown \n
      - UIM_PERSO_FEATURE_STATUS_GW_SERVICE_PROVIDER_NAME (0x0C) --  GW service provider name personalization \n
      - UIM_PERSO_FEATURE_STATUS_GW_SP_EHPLMN (0x0D) --  GW service provider with equivalent HPLMN personalization \n
      - UIM_PERSO_FEATURE_STATUS_GW_ICCID (0x0E) --  GW ICCID personalization \n
      - UIM_PERSO_FEATURE_STATUS_GW_IMPI (0x0F) --  GW IMPI personalization \n
      - UIM_PERSO_FEATURE_STATUS_GW_NETWORK_SUBSET_SERVICE_PROVIDER (0x10) --  GW network subset and service provider personalization
 */

  uint8_t perso_retries;
  /**<   Indicates the number of retries remaining to disable the personalization.

       \vspace{3pt}
       This value is set to 0xFF if the modem configuration allows unlimited
       retries.
  */

  uint8_t perso_unblock_retries;
  /**<   Indicates the number of retries remaining to unblock the personalization.*/

  uint32_t aid_value_len;  /**< Must be set to # of elements in aid_value */
  uint8_t aid_value[QMI_UIM_AID_MAX_V01];
  /**<   Application identifier value.*/

  uim_univ_pin_enum_v01 univ_pin;
  /**<   Indicates whether UPIN replaces PIN1. Valid values:\n
      - UIM_UNIV_PIN_PIN1_USED (0x00) --  PIN1 is used \n
      - UIM_UNIV_PIN_UPIN_REPLACES_PIN1 (0x01) --  UPIN replaces PIN1
 */

  uim_pin_info_type_v01 pin1;
  /**<   Contains information about PIN1.*/

  uim_pin_info_type_v01 pin2;
  /**<   Contains information about PIN2.*/
}app_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_card_state_enum_v01 card_state;
  /**<   Indicates the state of the card. Valid values:\n
      - UIM_CARD_STATE_ABSENT (0x00) --  Absent \n
      - UIM_CARD_STATE_PRESENT (0x01) --  Present \n
      - UIM_CARD_STATE_ERROR (0x02) --  Error
 */

  uim_pin_info_type_v01 upin;
  /**<   Contains information about the universal PIN.*/

  uim_card_error_code_enum_v01 error_code;
  /**<   Indicates the reason for the card error, and is valid only when the card
 state is Error. Valid values:\n
      - UIM_CARD_ERROR_CODE_UNKNOWN (0x00) --  Unknown\n
      - UIM_CARD_ERROR_CODE_POWER_DOWN (0x01) --  Power down\n
      - UIM_CARD_ERROR_CODE_POLL_ERROR (0x02) --  Poll error\n
      - UIM_CARD_ERROR_CODE_NO_ATR_RECEIVED (0x03) --  No ATR received\n
      - UIM_CARD_ERROR_CODE_VOLT_MISMATCH (0x04) --  Volt mismatch\n
      - UIM_CARD_ERROR_CODE_PARITY_ERROR (0x05) --  Parity error\n
      - UIM_CARD_ERROR_CODE_POSSIBLY_REMOVED (0x06) --  Unknown, possibly removed\n
      - UIM_CARD_ERROR_CODE_SIM_TECHNICAL_PROBLEMS (0x07) --  Card returned technical problems\n
      - UIM_CARD_ERROR_CODE_NULL_BYTES (0x08) --  Card returned NULL bytes\n
      - UIM_CARD_ERROR_CODE_SAP_CONNECTED (0x09) --  Terminal in SAP mode
      - UIM_CARD_ERROR_CODE_CMD_TIMEOUT (0x0A) --  Command Timeout error
 \n
 Other values are possible and reserved for future use. When an
 unknown value is received, it is to be handled as ``Unknown''.
 */

  uint32_t app_info_len;  /**< Must be set to # of elements in app_info */
  app_info_type_v01 app_info[QMI_UIM_APPS_MAX_V01];
  /**<   Contains the application information.*/
}card_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t index_gw_pri;
  /**<   Index of the primary GW provisioning application. The most significant
       byte indicates the slot (starting from 0), while the least significant
       byte indicates the application for that slot (starting from 0). The
       value 0xFFFF identifies that the session does not exist.
  */

  uint16_t index_1x_pri;
  /**<   Index of the primary 1X provisioning application. The most significant
       byte indicates the slot (starting from 0), while the least significant
       byte indicates the application for that slot (starting from 0). The
       value 0xFFFF identifies that the session does not exist.
    */

  uint16_t index_gw_sec;
  /**<   Index of the secondary GW provisioning application. The most significant
       byte indicates the slot (starting from 0), while the least significant
       byte indicates the application for that slot (starting from 0). The
       value 0xFFFF identifies that the session does not exist.
  */

  uint16_t index_1x_sec;
  /**<   Index of the secondary 1X provisioning application. The most significant
       byte indicates the slot (starting from 0), while the least significant
       byte indicates the application for that slot (starting from 0). The
       value 0xFFFF identifies that the session does not exist.
  */

  uint32_t card_info_len;  /**< Must be set to # of elements in card_info */
  card_info_type_v01 card_info[QMI_UIM_CARDS_MAX_V01];
  /**<   Contains the card information.*/
}uim_card_status_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_extended_card_state_enum_v01 card_state;
  /**<   Indicates the state of the card. Valid values:\n
      - UIM_EXTENDED_CARD_STATE_ABSENT (0x00) --  Absent \n
      - UIM_EXTENDED_CARD_STATE_PRESENT (0x01) --  Present \n
      - UIM_EXTENDED_CARD_STATE_ERROR (0x02) --  Error \n
      - UIM_EXTENDED_CARD_STATE_UNKNOWN (0x03) --  Unknown
 */

  uim_pin_info_type_v01 upin;
  /**<   Contains information about the universal PIN.*/

  uim_card_error_code_enum_v01 error_code;
  /**<   Indicates the reason for the card error, and is valid only when the card
 state is Error. Valid values:\n
      - UIM_CARD_ERROR_CODE_UNKNOWN (0x00) --  Unknown\n
      - UIM_CARD_ERROR_CODE_POWER_DOWN (0x01) --  Power down\n
      - UIM_CARD_ERROR_CODE_POLL_ERROR (0x02) --  Poll error\n
      - UIM_CARD_ERROR_CODE_NO_ATR_RECEIVED (0x03) --  No ATR received\n
      - UIM_CARD_ERROR_CODE_VOLT_MISMATCH (0x04) --  Volt mismatch\n
      - UIM_CARD_ERROR_CODE_PARITY_ERROR (0x05) --  Parity error\n
      - UIM_CARD_ERROR_CODE_POSSIBLY_REMOVED (0x06) --  Unknown, possibly removed\n
      - UIM_CARD_ERROR_CODE_SIM_TECHNICAL_PROBLEMS (0x07) --  Card returned technical problems\n
      - UIM_CARD_ERROR_CODE_NULL_BYTES (0x08) --  Card returned NULL bytes\n
      - UIM_CARD_ERROR_CODE_SAP_CONNECTED (0x09) --  Terminal in SAP mode
      - UIM_CARD_ERROR_CODE_CMD_TIMEOUT (0x0A) --  Command Timeout error
 \n
 Other values are possible and reserved for future use. When an
 unknown value is received, it is to be handled as ``Unknown''.
 */

  uint32_t app_info_len;  /**< Must be set to # of elements in app_info */
  app_info_type_v01 app_info[QMI_UIM_EXTENDED_APPS_MAX_V01];
  /**<   Contains the application information.*/
}extended_card_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t index_gw_len;  /**< Must be set to # of elements in index_gw */
  uint16_t index_gw[QMI_UIM_EXTENDED_CARDS_MAX_V01];
  /**<   Index of the GW provisioning applications. The most significant
       byte indicates the slot (starting from 0), while the least significant
       byte indicates the application for that slot (starting from 0). The
       value 0xFFFF identifies that the session does not exist.
  */

  uint32_t index_1x_len;  /**< Must be set to # of elements in index_1x */
  uint16_t index_1x[QMI_UIM_EXTENDED_CARDS_MAX_V01];
  /**<   Index of the 1X provisioning applications. The most significant
       byte indicates the slot (starting from 0), while the least significant
       byte indicates the application for that slot (starting from 0). The
       value 0xFFFF identifies that the session does not exist.
    */

  uint32_t card_info_len;  /**< Must be set to # of elements in card_info */
  extended_card_info_type_v01 card_info[QMI_UIM_EXTENDED_CARDS_MAX_V01];
  /**<   Contains the card information.*/
}uim_extended_card_status_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_HOT_SWAP_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_HOT_SWAP_NOT_SUPPORTED_V01 = 0x00, /**<  Hot-swap is not supported \n  */
  UIM_HOT_SWAP_STATUS_NOT_SUPPORTED_V01 = 0x01, /**<  Hot-swap is supported, but the status of the switch is not
       supported \n  */
  UIM_HOT_SWAP_STATUS_PRESENT_V01 = 0x02, /**<  Switch indicates that the card is present \n  */
  UIM_HOT_SWAP_STATUS_NOT_PRESENT_V01 = 0x03, /**<  Switch indicates that the card is not present  */
  UIM_HOT_SWAP_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_hot_swap_status_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Retrieves the current status of the card. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Card Status */
  uint8_t card_status_valid;  /**< Must be set to true if card_status is being passed */
  uim_card_status_type_v01 card_status;

  /* Optional */
  /*  Hot-Swap Status */
  uint8_t hot_swap_valid;  /**< Must be set to true if hot_swap is being passed */
  uint32_t hot_swap_len;  /**< Must be set to # of elements in hot_swap */
  uim_hot_swap_status_enum_v01 hot_swap[QMI_UIM_CARDS_MAX_V01];
  /**<   Indicates the status of the hot-swap switch. Valid values:\n
      - UIM_HOT_SWAP_NOT_SUPPORTED (0x00) --  Hot-swap is not supported \n
      - UIM_HOT_SWAP_STATUS_NOT_SUPPORTED (0x01) --  Hot-swap is supported, but the status of the switch is not
       supported \n
      - UIM_HOT_SWAP_STATUS_PRESENT (0x02) --  Switch indicates that the card is present \n
      - UIM_HOT_SWAP_STATUS_NOT_PRESENT (0x03) --  Switch indicates that the card is not present
 */

  /* Optional */
  /*  Valid Card Status */
  uint8_t card_status_validity_valid;  /**< Must be set to true if card_status_validity is being passed */
  uint32_t card_status_validity_len;  /**< Must be set to # of elements in card_status_validity */
  uint8_t card_status_validity[QMI_UIM_CARDS_MAX_V01];
  /**<   Indicates whether the reported status of the card on the corresponding
       slot is valid. Valid values:\n
        - 0 -- Status of the card is unknown (even when reported as absent)\n
        - 1 -- Status of the card is valid
  */

  /* Optional */
  /*  Extended Card Status */
  uint8_t extended_card_status_valid;  /**< Must be set to true if extended_card_status is being passed */
  uim_extended_card_status_type_v01 extended_card_status;

  /* Optional */
  /*  Extended Hot-Swap Status */
  uint8_t extended_hot_swap_valid;  /**< Must be set to true if extended_hot_swap is being passed */
  uint32_t extended_hot_swap_len;  /**< Must be set to # of elements in extended_hot_swap */
  uim_hot_swap_status_enum_v01 extended_hot_swap[QMI_UIM_EXTENDED_CARDS_MAX_V01];
  /**<   Indicates the status of the hot-swap switch. Valid values:\n
      - UIM_HOT_SWAP_NOT_SUPPORTED (0x00) --  Hot-swap is not supported \n
      - UIM_HOT_SWAP_STATUS_NOT_SUPPORTED (0x01) --  Hot-swap is supported, but the status of the switch is not
       supported \n
      - UIM_HOT_SWAP_STATUS_PRESENT (0x02) --  Switch indicates that the card is present \n
      - UIM_HOT_SWAP_STATUS_NOT_PRESENT (0x03) --  Switch indicates that the card is not present
 */

  /* Optional */
  /*  SIM Busy Status */
  uint8_t sim_busy_status_valid;  /**< Must be set to true if sim_busy_status is being passed */
  uint32_t sim_busy_status_len;  /**< Must be set to # of elements in sim_busy_status */
  uint8_t sim_busy_status[QMI_UIM_EXTENDED_CARDS_MAX_V01];
  /**<   Indicates whether the card on the corresponding slot is busy. Valid
       values:\n
        - 0 -- SIM card is not busy \n
        - 1 -- SIM card is busy
  */

  /* Optional */
  /*  Card Mode */
  uint8_t card_mode_valid;  /**< Must be set to true if card_mode is being passed */
  uint32_t card_mode_len;  /**< Must be set to # of elements in card_mode */
  uim_card_mode_enum_v01 card_mode[QMI_UIM_EXTENDED_CARDS_MAX_V01];
  /**<   Indicates the card mode. Valid values:\n
      - UIM_CARD_MODE_TELECOM_CARD (0x00) --  Telecom card (default) \n
      - UIM_CARD_MODE_NON_TELECOM_CARD (0x01) --  Non-telecom card
 \n
 Other values are possible and reserved for future use.
 */
}uim_get_card_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Registers for event notifications from the card. */
typedef struct {

  /* Mandatory */
  /*  Event Mask */
  uint32_t event_mask;
  /**<   Bitmask of the events to be received by the client. Additional
       bits are reserved for future use and must be set to zero by the caller.\n
        - Bit 0 -- Card status\n
        - Bit 1 -- SAP connection\n
        - Bit 2 -- Extended card status\n
        - Bit 3 -- Close of provisioning sessions\n
        - Bit 4 -- Physical slot status\n
        - Bit 5 -- SIM busy status\n
        - Bit 6 -- Reduced card status\n
        - Bit 7 -- Recovery complete\n
        - Bit 8 -- Supply voltage Vcc status\n
        - Bit 9 -- Card activation status\n
        - Bit 10 -- Remote SimLock configuration\n
        - Bit 11 -- SimLock temporary unlock status
  */
}uim_event_reg_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Registers for event notifications from the card. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Event Registration Result */
  uint8_t event_mask_valid;  /**< Must be set to true if event_mask is being passed */
  uint32_t event_mask;
  /**<   Bitmask of the events that were successfully enabled. This result
       can be different from the mask used in the request when
       notifications are not supported. Additional bits are reserved for
       future use and can be ignored by the caller.\n
        - Bit 0 -- Card status\n
        - Bit 1 -- SAP connection\n
        - Bit 2 -- Extended card status\n
        - Bit 3 -- Close of provisioning sessions\n
        - Bit 4 -- Physical slot status\n
        - Bit 5 -- SIM busy status\n
        - Bit 6 -- Reduced card status\n
        - Bit 7 -- Recovery complete\n
        - Bit 8 -- Supply voltage Vcc status\n
        - Bit 9 -- Card activation status\n
        - Bit 10 -- Remote SimLock configuration\n
        - Bit 11 -- SimLock temporary unlock status
  */
}uim_event_reg_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indicates that the status of the card has changed. */
typedef struct {

  /* Optional */
  /*  Card Status */
  uint8_t card_status_valid;  /**< Must be set to true if card_status is being passed */
  uim_card_status_type_v01 card_status;

  /* Optional */
  /*  Valid Card Status */
  uint8_t card_status_validity_valid;  /**< Must be set to true if card_status_validity is being passed */
  uint32_t card_status_validity_len;  /**< Must be set to # of elements in card_status_validity */
  uint8_t card_status_validity[QMI_UIM_CARDS_MAX_V01];
  /**<   Indicates whether the reported status of the card on the corresponding
       slot is valid. Valid values: \n
        - 0 -- Status of the card is unknown (even if reported as absent)\n
        - 1 -- Status of the card is valid
  */

  /* Optional */
  /*  Extended Card Status */
  uint8_t extended_card_status_valid;  /**< Must be set to true if extended_card_status is being passed */
  uim_extended_card_status_type_v01 extended_card_status;

  /* Optional */
  /*  Card Mode */
  uint8_t card_mode_valid;  /**< Must be set to true if card_mode is being passed */
  uint32_t card_mode_len;  /**< Must be set to # of elements in card_mode */
  uim_card_mode_enum_v01 card_mode[QMI_UIM_EXTENDED_CARDS_MAX_V01];
  /**<   Indicates the card mode. Valid values:\n
      - UIM_CARD_MODE_TELECOM_CARD (0x00) --  Telecom card (default) \n
      - UIM_CARD_MODE_NON_TELECOM_CARD (0x01) --  Non-telecom card
 \n
 Other values are possible and reserved for future use.
 */
}uim_status_change_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Received when a refresh command comes from the card. */
typedef struct {

  /* Optional */
  /*  Refresh Event */
  uint8_t refresh_event_valid;  /**< Must be set to true if refresh_event is being passed */
  uim_refresh_event_type_v01 refresh_event;

  /* Optional */
  /*  Refresh Enforcement */
  uint8_t refresh_enforcement_policy_mask_valid;  /**< Must be set to true if refresh_enforcement_policy_mask is being passed */
  uim_refresh_enforcement_policy_mask_v01 refresh_enforcement_policy_mask;
  /**<   Refresh enforcement policy. Values:\n
      - UIM_REFRESH_ENFORCEMENT_POLICY_NAVIGATING_MENU (0x0001) --  Force immediate refresh when navigating the menu
      - UIM_REFRESH_ENFORCEMENT_POLICY_DATA_CALL (0x0002) --  Force immediate refresh when a data call is in progress
      - UIM_REFRESH_ENFORCEMENT_POLICY_VOICE_CALL (0x0004) --  Force immediate refresh when a voice call is in progress
 \n
 All other bits are reserved for future use.
 */
}uim_refresh_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_AUTH_CONTEXT_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_AUTH_CONTEXT_RUN_GSM_ALG_V01 = 0x00, /**<  Runs the GSM alogrithm (valid only on a 2G SIM card, as specified in
       \hyperref[3G51011]{3GPP TS 51.011})\n */
  UIM_AUTH_CONTEXT_RUN_CAVE_ALG_V01 = 0x01, /**<  Runs the CAVE algorithm (valid only on a RUIM card, as specified in
       \hyperref[CS0023D]{C.S0023-D})\n  */
  UIM_AUTH_CONTEXT_GSM_SEC_V01 = 0x02, /**<  GSM security context (valid only on a USIM application, as
       specified in \hyperref[3G31102]{3GPP TS 31.102})\n  */
  UIM_AUTH_CONTEXT_3G_SEC_V01 = 0x03, /**<  3G security context (valid only on a USIM application, as
       specified in \hyperref[3G31102]{3GPP TS 31.102})\n  */
  UIM_AUTH_CONTEXT_VGCS_VBS_SEC_V01 = 0x04, /**<  VGCS/VBS security context (valid only on a USIM application, as
       specified in \hyperref[3G31102]{3GPP TS 31.102})\n  */
  UIM_AUTH_CONTEXT_GBA_SEC_BOOTSTRAPPING_V01 = 0x05, /**<  GBA security context, Bootstrapping mode (valid only on
       a USIM or ISIM application, as specified in \hyperref[3G31102]{3GPP TS 31.102}
       and \hyperref[3G31103]{3GPP TS 31.103})\n   */
  UIM_AUTH_CONTEXT_GBA_SEC_NAF_DERIVATION_V01 = 0x06, /**<  GBA security context, NAF Derivation mode (valid only on a USIM or ISIM
       application, as specified in \hyperref[3G31102]{3GPP TS 31.102} and
       \hyperref[3G31103]{3GPP TS 31.103})\n  */
  UIM_AUTH_CONTEXT_MBMS_SEC_MSK_UPDATE_V01 = 0x07, /**<  MBMS security context, MSK Update mode (valid only on a USIM application,
       as specified in \hyperref[3G31102]{3GPP TS 31.102})\n  */
  UIM_AUTH_CONTEXT_MBMS_SEC_MTK_GENERATION_V01 = 0x08, /**<  MBMS security context, MTK Generation mode (valid only on a USIM
       application, as specified in \hyperref[3G31102]{3GPP TS 31.102})\n  */
  UIM_AUTH_CONTEXT_MBMS_SEC_MSK_DELETION_V01 = 0x09, /**<  MBMS security context, MSK Deletion mode (valid only on a USIM application,
       as specified in \hyperref[3G31102]{3GPP TS 31.102})\n  */
  UIM_AUTH_CONTEXT_MBMS_SEC_MUK_DELETION_V01 = 0x0A, /**<  MBMS security context, MUK Deletion mode (valid only on a USIM
       application, as specified in \hyperref[3G31102]{3GPP TS 31.102})\n  */
  UIM_AUTH_CONTEXT_IMS_AKA_SEC_V01 = 0x0B, /**<  IMS AKA security context (valid only on a ISIM application, as
       specified in \hyperref[3G31103]{3GPP TS 31.103})\n  */
  UIM_AUTH_CONTEXT_HTTP_DIGEST_SEC_V01 = 0x0C, /**<  HTTP-digest security context (valid only on an ISIM application, as
      specified in \hyperref[3G31103]{3GPP TS 31.103})\n  */
  UIM_AUTH_CONTEXT_COMPUTE_IP_CHAP_V01 = 0x0D, /**<  Compute IP authentication, CHAP (valid only on RUIM or CSIM, as
       specified in \hyperref[CS0023D]{C.S0023-D} and \hyperref[CS00650]{C.S0065-0})\n  */
  UIM_AUTH_CONTEXT_COMPUTE_IP_MN_HA_V01 = 0x0E, /**<  Compute IP authentication, MN-HA authenticator (valid only on RUIM or
       CSIM, as specified in \hyperref[CS0023D]{C.S0023-D} and
       \hyperref[CS00650]{C.S0065-0})\n  */
  UIM_AUTH_CONTEXT_COMPUTE_IP_MIP_RRQ_HASH_V01 = 0x0F, /**<  Compute IP authentication, MIP-RRQ hash (valid only on RUIM or CSIM, as
       specified in \hyperref[CS0023D]{C.S0023-D} and \hyperref[CS00650]{C.S0065-0})\n  */
  UIM_AUTH_CONTEXT_COMPUTE_IP_MN_AAA_V01 = 0x10, /**<  Compute IP authentication, MN-AAA authenticator (valid only on RUIM or
       CSIM, as specified in  \hyperref[CS0023D]{C.S0023-D} and
       \hyperref[CS00650]{C.S0065-0})\n  */
  UIM_AUTH_CONTEXT_COMPUTE_IP_HRPD_ACCESS_V01 = 0x11, /**<  Compute IP authentication, HRPD access authenticator (valid only on RUIM
       or CSIM, as specified in \hyperref[CS0023D]{C.S0023-D} and
       \hyperref[CS00650]{C.S0065-0})  */
  UIM_AUTH_CONTEXT_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_auth_context_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_auth_context_enum_v01 context;
  /**<   Authenticate context. Valid values:\n
      - UIM_AUTH_CONTEXT_RUN_GSM_ALG (0x00) --  Runs the GSM alogrithm (valid only on a 2G SIM card, as specified in
       \hyperref[3G51011]{3GPP TS 51.011})\n
      - UIM_AUTH_CONTEXT_RUN_CAVE_ALG (0x01) --  Runs the CAVE algorithm (valid only on a RUIM card, as specified in
       \hyperref[CS0023D]{C.S0023-D})\n
      - UIM_AUTH_CONTEXT_GSM_SEC (0x02) --  GSM security context (valid only on a USIM application, as
       specified in \hyperref[3G31102]{3GPP TS 31.102})\n
      - UIM_AUTH_CONTEXT_3G_SEC (0x03) --  3G security context (valid only on a USIM application, as
       specified in \hyperref[3G31102]{3GPP TS 31.102})\n
      - UIM_AUTH_CONTEXT_VGCS_VBS_SEC (0x04) --  VGCS/VBS security context (valid only on a USIM application, as
       specified in \hyperref[3G31102]{3GPP TS 31.102})\n
      - UIM_AUTH_CONTEXT_GBA_SEC_BOOTSTRAPPING (0x05) --  GBA security context, Bootstrapping mode (valid only on
       a USIM or ISIM application, as specified in \hyperref[3G31102]{3GPP TS 31.102}
       and \hyperref[3G31103]{3GPP TS 31.103})\n
      - UIM_AUTH_CONTEXT_GBA_SEC_NAF_DERIVATION (0x06) --  GBA security context, NAF Derivation mode (valid only on a USIM or ISIM
       application, as specified in \hyperref[3G31102]{3GPP TS 31.102} and
       \hyperref[3G31103]{3GPP TS 31.103})\n
      - UIM_AUTH_CONTEXT_MBMS_SEC_MSK_UPDATE (0x07) --  MBMS security context, MSK Update mode (valid only on a USIM application,
       as specified in \hyperref[3G31102]{3GPP TS 31.102})\n
      - UIM_AUTH_CONTEXT_MBMS_SEC_MTK_GENERATION (0x08) --  MBMS security context, MTK Generation mode (valid only on a USIM
       application, as specified in \hyperref[3G31102]{3GPP TS 31.102})\n
      - UIM_AUTH_CONTEXT_MBMS_SEC_MSK_DELETION (0x09) --  MBMS security context, MSK Deletion mode (valid only on a USIM application,
       as specified in \hyperref[3G31102]{3GPP TS 31.102})\n
      - UIM_AUTH_CONTEXT_MBMS_SEC_MUK_DELETION (0x0A) --  MBMS security context, MUK Deletion mode (valid only on a USIM
       application, as specified in \hyperref[3G31102]{3GPP TS 31.102})\n
      - UIM_AUTH_CONTEXT_IMS_AKA_SEC (0x0B) --  IMS AKA security context (valid only on a ISIM application, as
       specified in \hyperref[3G31103]{3GPP TS 31.103})\n
      - UIM_AUTH_CONTEXT_HTTP_DIGEST_SEC (0x0C) --  HTTP-digest security context (valid only on an ISIM application, as
      specified in \hyperref[3G31103]{3GPP TS 31.103})\n
      - UIM_AUTH_CONTEXT_COMPUTE_IP_CHAP (0x0D) --  Compute IP authentication, CHAP (valid only on RUIM or CSIM, as
       specified in \hyperref[CS0023D]{C.S0023-D} and \hyperref[CS00650]{C.S0065-0})\n
      - UIM_AUTH_CONTEXT_COMPUTE_IP_MN_HA (0x0E) --  Compute IP authentication, MN-HA authenticator (valid only on RUIM or
       CSIM, as specified in \hyperref[CS0023D]{C.S0023-D} and
       \hyperref[CS00650]{C.S0065-0})\n
      - UIM_AUTH_CONTEXT_COMPUTE_IP_MIP_RRQ_HASH (0x0F) --  Compute IP authentication, MIP-RRQ hash (valid only on RUIM or CSIM, as
       specified in \hyperref[CS0023D]{C.S0023-D} and \hyperref[CS00650]{C.S0065-0})\n
      - UIM_AUTH_CONTEXT_COMPUTE_IP_MN_AAA (0x10) --  Compute IP authentication, MN-AAA authenticator (valid only on RUIM or
       CSIM, as specified in  \hyperref[CS0023D]{C.S0023-D} and
       \hyperref[CS00650]{C.S0065-0})\n
      - UIM_AUTH_CONTEXT_COMPUTE_IP_HRPD_ACCESS (0x11) --  Compute IP authentication, HRPD access authenticator (valid only on RUIM
       or CSIM, as specified in \hyperref[CS0023D]{C.S0023-D} and
       \hyperref[CS00650]{C.S0065-0})
 \n
 Other values are possible and reserved for future use.
 */

  uint32_t data_len;  /**< Must be set to # of elements in data */
  uint8_t data[QMI_UIM_AUTHENTICATE_DATA_MAX_V01];
  /**<   Authenticate data.*/
}uim_authentication_data_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Executes the authentication algorithm on the card. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  Authentication Data */
  uim_authentication_data_type_v01 authentication_data;

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result must be provided
       in a subsequent indication.
  */
}uim_authenticate_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Executes the authentication algorithm on the card. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message definition.
  */

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;

  /* Optional */
  /*  Authenticate Result */
  uint8_t content_valid;  /**< Must be set to true if content is being passed */
  uint32_t content_len;  /**< Must be set to # of elements in content */
  uint8_t content[QMI_UIM_AUTHENTICATE_RESULT_MAX_V01];
  /**<   Authenticate data. This value is a sequence of bytes returned from the card.*/

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result is provided
       in a subsequent indication.
  */
}uim_authenticate_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indication with an authenticate command result. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message definition.
  */

  /* Mandatory */
  /*  Token of the Original Request */
  uint32_t indication_token;
  /**<   Indicates the token of the original request.*/

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;

  /* Optional */
  /*  Authenticate Result */
  uint8_t content_valid;  /**< Must be set to true if content is being passed */
  uint32_t content_len;  /**< Must be set to # of elements in content */
  uint8_t content[QMI_UIM_AUTHENTICATE_RESULT_MAX_V01];
  /**<   Authenticate data. This value is a sequence of bytes returned from the card.*/
}uim_authenticate_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Forcibly closes a session to a nonprovisioning application. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Optional */
  /*  Termination of Application */
  uint8_t terminate_application_valid;  /**< Must be set to true if terminate_application is being passed */
  uint8_t terminate_application;
  /**<   Indicates whether the application is terminated with a STATUS command
       before closing the associated logical channel. If the Termination of
       Application TLV is missing, the default behavior is TRUE, which
       terminates the application only for USIM, CSIM, ISIM, or 2G applications.
  */
}uim_close_session_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Forcibly closes a session to a nonprovisioning application. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type - QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  - Error code. Possible error code values are described
                         in the error codes section of each message definition.
  */
}uim_close_session_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Retrieves the status of a service on the card. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  Capabilities Mask */
  uint32_t mask;
  /**<   Bitmask of the capabilities that the client retrieves from the card.
       Additional bits are reserved for future use and are to be set to zero.\n
        - Bit 0 -- FDN status\n
        - Bit 1 -- Hidden key PIN status (for USIM cards only)\n
        - Bit 2 -- Index in the EF-DIR (for UICC cards only)\n
        - Bit 3 -- ESN status (for 1X sessions only)\n
        - Bit 4 -- ACL status (for USIM cards only)\n
        - Bit 5 -- Service status as indicated in the service table
  */

  /* Optional */
  /*  Service Number */
  uint8_t service_number_valid;  /**< Must be set to true if service_number is being passed */
  uint8_t service_number;
  /**<   This TLV must be present if the service status bit is enabled in the mask.
       When present, this TLV must contain a valid service number as indicated
       in the service table per the following specifications:\n
       - For CSIM, as specified in \hyperref[CS00650]{C.S0065-0} Section 5.2.80\n
       - For USIM, as specified in \hyperref[3G31102]{3GPP TS 31.102} Section 4.2.8\n
       - For RUIM, as specified in \hyperref[CS0023D]{C.S0023-D} Section 3.4.18\n
       - For GSM, as specified in \hyperref[3G51011]{3GPP TS 51.011} Section 10.3.7
  */
}uim_get_service_status_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_FDN_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_FDN_STATUS_NOT_AVAILABLE_V01 = 0x00, /**<  FDN is not available \n  */
  UIM_FDN_STATUS_AVAILABLE_DISABLED_V01 = 0x01, /**<  FDN is available and disabled \n   */
  UIM_FDN_STATUS_AVAILABLE_ENABLED_V01 = 0x02, /**<  FDN is available and enabled  */
  UIM_FDN_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_fdn_status_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_HIDDEN_KEY_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_HIDDEN_KEY_STATUS_NOT_SUPPORTED_V01 = 0x00, /**<  Not supported \n   */
  UIM_HIDDEN_KEY_STATUS_ENABLED_NOT_VERIFIED_V01 = 0x01, /**<  Enabled and not verified \n   */
  UIM_HIDDEN_KEY_STATUS_ENABLED_VERIFIED_V01 = 0x02, /**<  Enabled and verified \n   */
  UIM_HIDDEN_KEY_STATUS_DISABLED_V01 = 0x03, /**<  Disabled  */
  UIM_HIDDEN_KEY_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_hidden_key_status_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_ESN_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_ESN_STATUS_NO_CHANGE_V01 = 0x00, /**<  ESN is not changed \n   */
  UIM_ESN_STATUS_CHANGED_V01 = 0x01, /**<  ESN is changed  */
  UIM_ESN_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_esn_status_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_ACL_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_ACL_STATUS_NOT_AVAILABLE_V01 = 0x00, /**<  ACL is not available \n   */
  UIM_ACL_STATUS_AVAILABLE_DISABLED_V01 = 0x01, /**<  ACL is available and disabled \n   */
  UIM_ACL_STATUS_AVAILABLE_ENABLED_V01 = 0x02, /**<  ACL is available and enabled  */
  UIM_ACL_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_acl_status_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Retrieves the status of a service on the card. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  FDN Status */
  uint8_t fdn_status_valid;  /**< Must be set to true if fdn_status is being passed */
  uim_fdn_status_enum_v01 fdn_status;
  /**<   Fixed dialing number status. Valid values:\n
      - UIM_FDN_STATUS_NOT_AVAILABLE (0x00) --  FDN is not available \n
      - UIM_FDN_STATUS_AVAILABLE_DISABLED (0x01) --  FDN is available and disabled \n
      - UIM_FDN_STATUS_AVAILABLE_ENABLED (0x02) --  FDN is available and enabled
 */

  /* Optional */
  /*  Hidden Key Status */
  uint8_t hidden_key_status_valid;  /**< Must be set to true if hidden_key_status is being passed */
  uim_hidden_key_status_enum_v01 hidden_key_status;
  /**<   Status of the hidden key PIN. Valid values:\n
      - UIM_HIDDEN_KEY_STATUS_NOT_SUPPORTED (0x00) --  Not supported \n
      - UIM_HIDDEN_KEY_STATUS_ENABLED_NOT_VERIFIED (0x01) --  Enabled and not verified \n
      - UIM_HIDDEN_KEY_STATUS_ENABLED_VERIFIED (0x02) --  Enabled and verified \n
      - UIM_HIDDEN_KEY_STATUS_DISABLED (0x03) --  Disabled
 */

  /* Optional */
  /*  Index */
  uint8_t index_valid;  /**< Must be set to true if index is being passed */
  uint8_t index;
  /**<   Index of the application in the EF_DIR file, starting from 1.*/

  /* Optional */
  /*  ESN Status */
  uint8_t esn_status_valid;  /**< Must be set to true if esn_status is being passed */
  uim_esn_status_enum_v01 esn_status;
  /**<   ESN status. Valid values:\n
      - UIM_ESN_STATUS_NO_CHANGE (0x00) --  ESN is not changed \n
      - UIM_ESN_STATUS_CHANGED (0x01) --  ESN is changed
 */

  /* Optional */
  /*  ACL Status */
  uint8_t acl_status_valid;  /**< Must be set to true if acl_status is being passed */
  uim_acl_status_enum_v01 acl_status;
  /**<   Access point name control list service status. Valid values:\n
      - UIM_ACL_STATUS_NOT_AVAILABLE (0x00) --  ACL is not available \n
      - UIM_ACL_STATUS_AVAILABLE_DISABLED (0x01) --  ACL is available and disabled \n
      - UIM_ACL_STATUS_AVAILABLE_ENABLED (0x02) --  ACL is available and enabled
 */

  /* Optional */
  /*  Service Status */
  uint8_t service_status_valid;  /**< Must be set to true if service_status is being passed */
  uint8_t service_status;
  /**<   Service status. Valid values:\n
        - 0 -- Service is not available\n
        - 1 -- Service is available
  */
}uim_get_service_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Changes the status of a service on the card. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Optional */
  /*  FDN Service Enable/Disable */
  uint8_t fdn_status_valid;  /**< Must be set to true if fdn_status is being passed */
  uint8_t fdn_status;
  /**<   Enables or disables the FDN service. Valid values:\n
        - 0 -- Disables the FDN service\n
        - 1 -- Enables the FDN service
  */

  /* Optional */
  /*  ACL Service Enable/Disable */
  uint8_t enable_acl_valid;  /**< Must be set to true if enable_acl is being passed */
  uint8_t enable_acl;
  /**<   Enables or disables the ACL service. Valid values:\n
        - 0 -- Disables the ACL service\n
        - 1 -- Enables the ACL service
  */
}uim_set_service_status_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Changes the status of a service on the card. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_set_service_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_session_type_enum_v01 session_type;
  /**<   Indicates the session type. Only provisioning sessions can be used.
       Valid values: 0 through 3 and 10 through 15.
       See Table \ref{tbl:sessions} for the list of available session types
       with their values and descriptions.
  */

  uint8_t activate;
  /**<   Indicates whether to deactivate or activate the provisioning session.
       Valid values:\n
        - 0 -- Deactivate\n
        - 1 -- Activate
  */
}uim_session_change_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_slot_enum_v01 slot;
  /**<   Indicates the slot to be used. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  uint32_t aid_len;  /**< Must be set to # of elements in aid */
  uint8_t aid[QMI_UIM_AID_MAX_V01];
}uim_application_information_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Changes the provisioning session. */
typedef struct {

  /* Mandatory */
  /*  Session Change */
  uim_session_change_type_v01 session_change;

  /* Optional */
  /*  Application Information */
  uint8_t application_information_valid;  /**< Must be set to true if application_information is being passed */
  uim_application_information_type_v01 application_information;
}uim_change_provisioning_session_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Changes the provisioning session. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_change_provisioning_session_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Gets the label of an application on a UICC card. */
typedef struct {

  /* Mandatory */
  /*  Application Information */
  uim_application_information_type_v01 application_information;
}uim_get_label_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Gets the label of an application on a UICC card. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Application Label */
  uint8_t label_valid;  /**< Must be set to true if label is being passed */
  uint32_t label_len;  /**< Must be set to # of elements in label */
  char label[QMI_UIM_LABEL_MAX_V01];
  /**<   Value of the label in ASCII characters.*/
}uim_get_label_resp_msg_v01;  /* Message */
/**
    @}
  */

typedef uint32_t uim_get_configuration_mask_v01;
#define UIM_GET_CONFIGURATION_AUTOMATIC_SELECTION_V01 ((uim_get_configuration_mask_v01)0x0001) /**<  Automatic selection  */
#define UIM_GET_CONFIGURATION_PERSONALIZATION_STATUS_V01 ((uim_get_configuration_mask_v01)0x0002) /**<  Personalization status  */
#define UIM_GET_CONFIGURATION_HALT_SUBSCRIPTION_V01 ((uim_get_configuration_mask_v01)0x0004) /**<  Halt subscription  */
#define UIM_GET_CONFIGURATION_USB_UICC_SUPPORTED_V01 ((uim_get_configuration_mask_v01)0x0008) /**<  USB UICC is supported  */
#define UIM_GET_CONFIGURATION_SAP_CLIENT_SUPPORTED_V01 ((uim_get_configuration_mask_v01)0x0010) /**<  SAP in client mode is supported  */
#define UIM_GET_CONFIGURATION_PERSO_REACTIVATION_STATUS_V01 ((uim_get_configuration_mask_v01)0x0020) /**<  Personalization reactivation status  */
#define UIM_GET_CONFIGURATION_REMOTE_SIMLOCK_STORAGE_V01 ((uim_get_configuration_mask_v01)0x0040) /**<  Remote SimLock storage  */
#define UIM_GET_CONFIGURATION_EMERGENCY_ONLY_V01 ((uim_get_configuration_mask_v01)0x0080) /**<  Emergency Only mode status  */
#define UIM_GET_CONFIGURATION_EXTENDED_APDU_V01 ((uim_get_configuration_mask_v01)0x0100) /**<  Extended length APDUs are supported  */
/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Gets the modem configuration for the UIM module. */
typedef struct {

  /* Optional */
  /*  Configuration Mask */
  uint8_t configuration_mask_valid;  /**< Must be set to true if configuration_mask is being passed */
  uim_get_configuration_mask_v01 configuration_mask;
  /**<   Requested configurations:\n
      - UIM_GET_CONFIGURATION_AUTOMATIC_SELECTION (0x0001) --  Automatic selection
      - UIM_GET_CONFIGURATION_PERSONALIZATION_STATUS (0x0002) --  Personalization status
      - UIM_GET_CONFIGURATION_HALT_SUBSCRIPTION (0x0004) --  Halt subscription
      - UIM_GET_CONFIGURATION_USB_UICC_SUPPORTED (0x0008) --  USB UICC is supported
      - UIM_GET_CONFIGURATION_SAP_CLIENT_SUPPORTED (0x0010) --  SAP in client mode is supported
      - UIM_GET_CONFIGURATION_PERSO_REACTIVATION_STATUS (0x0020) --  Personalization reactivation status
      - UIM_GET_CONFIGURATION_REMOTE_SIMLOCK_STORAGE (0x0040) --  Remote SimLock storage
      - UIM_GET_CONFIGURATION_EMERGENCY_ONLY (0x0080) --  Emergency Only mode status
      - UIM_GET_CONFIGURATION_EXTENDED_APDU (0x0100) --  Extended length APDUs are supported
 \n
 All other bits are reserved for future use; if the TLV is missing,
 the service returns all configuration items in the response.
 */
}uim_get_configuration_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_perso_feature_enum_v01 feature;
  /**<   Indicates the personalization feature to deactivate or unblock.
 Valid values:\n
      - UIM_PERSO_FEATURE_GW_NETWORK (0x00) --  GW network personalization \n
      - UIM_PERSO_FEATURE_GW_NETWORK_SUBSET (0x01) --  GW network subset personalization \n
      - UIM_PERSO_FEATURE_GW_SERVICE_PROVIDER (0x02) --  GW service provider personalization \n
      - UIM_PERSO_FEATURE_GW_CORPORATE (0x03) --  GW corporate personalization \n
      - UIM_PERSO_FEATURE_GW_UIM (0x04) --  GW UIM personalization \n
      - UIM_PERSO_FEATURE_1X_NETWORK_TYPE_1 (0x05) --  1X network type 1 personalization \n
      - UIM_PERSO_FEATURE_1X_NETWORK_TYPE_2 (0x06) --  1X network type 2 personalization \n
      - UIM_PERSO_FEATURE_1X_HRPD (0x07) --  1X HRPD personalization \n
      - UIM_PERSO_FEATURE_1X_SERVICE_PROVIDER (0x08) --  1X service provider personalization \n
      - UIM_PERSO_FEATURE_1X_CORPORATE (0x09) --  1X corporate personalization \n
      - UIM_PERSO_FEATURE_1X_RUIM (0x0A) --  1X RUIM personalization \n
      - UIM_PERSO_FEATURE_GW_SPN (0x0B) --  GW SPN personalization \n
      - UIM_PERSO_FEATURE_GW_SP_EHPLMN (0x0C) --  GW SP + EHPLMN personalization \n
      - UIM_PERSO_FEATURE_GW_ICCID (0x0D) --  GW ICCID personalization \n
      - UIM_PERSO_FEATURE_GW_IMPI (0x0E) --  GW IMPI personalization \n
      - UIM_PERSO_FEATURE_GW_NETWORK_SUBSET_SERVICE_PROVIDER (0x0F) --  GW network subset and service provider personalization
 \n
 Other values are reserved for future use and are to be handled
 as unknown personalization features by the client.
 */

  uint8_t verify_left;
  /**<   Number of the remaining attempts to verify the personalization feature.*/

  uint8_t unblock_left;
  /**<   Number of the remaining attempts to unblock the personalization feature.*/
}uim_personalization_status_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  /*  Personalization Status */
  uint32_t personalization_status_len;  /**< Must be set to # of elements in personalization_status */
  uim_personalization_status_type_v01 personalization_status[QMI_UIM_PERSO_FEATURE_MAX_V01];
}uim_personalization_status_other_slots_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_perso_feature_enum_v01 feature;
  /**<   Indicates the personalization feature that is temporarily deactivated.
 Valid values:\n
      - UIM_PERSO_FEATURE_GW_NETWORK (0x00) --  GW network personalization \n
      - UIM_PERSO_FEATURE_GW_NETWORK_SUBSET (0x01) --  GW network subset personalization \n
      - UIM_PERSO_FEATURE_GW_SERVICE_PROVIDER (0x02) --  GW service provider personalization \n
      - UIM_PERSO_FEATURE_GW_CORPORATE (0x03) --  GW corporate personalization \n
      - UIM_PERSO_FEATURE_GW_UIM (0x04) --  GW UIM personalization \n
      - UIM_PERSO_FEATURE_1X_NETWORK_TYPE_1 (0x05) --  1X network type 1 personalization \n
      - UIM_PERSO_FEATURE_1X_NETWORK_TYPE_2 (0x06) --  1X network type 2 personalization \n
      - UIM_PERSO_FEATURE_1X_HRPD (0x07) --  1X HRPD personalization \n
      - UIM_PERSO_FEATURE_1X_SERVICE_PROVIDER (0x08) --  1X service provider personalization \n
      - UIM_PERSO_FEATURE_1X_CORPORATE (0x09) --  1X corporate personalization \n
      - UIM_PERSO_FEATURE_1X_RUIM (0x0A) --  1X RUIM personalization \n
      - UIM_PERSO_FEATURE_GW_SPN (0x0B) --  GW SPN personalization \n
      - UIM_PERSO_FEATURE_GW_SP_EHPLMN (0x0C) --  GW SP + EHPLMN personalization \n
      - UIM_PERSO_FEATURE_GW_ICCID (0x0D) --  GW ICCID personalization \n
      - UIM_PERSO_FEATURE_GW_IMPI (0x0E) --  GW IMPI personalization \n
      - UIM_PERSO_FEATURE_GW_NETWORK_SUBSET_SERVICE_PROVIDER (0x0F) --  GW network subset and service provider personalization
 \n
 Other values are reserved for future use and are to be handled
 as unknown personalization features by the client.
 */

  uint32_t temporary_unlock_time_left;
  /**<   Number of seconds remaining before the personalization feature gets
       reactivated. */
}uim_temporary_unlock_status_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  /*  Temporary Unlock Status */
  uint32_t temporary_unlock_status_len;  /**< Must be set to # of elements in temporary_unlock_status */
  uim_temporary_unlock_status_type_v01 temporary_unlock_status[QMI_UIM_PERSO_FEATURE_MAX_V01];
}uim_temporary_depersonalization_status_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_slot_enum_v01 slot;
  /**<   Indicates the slot to be used. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /*  Personalization Status */
  uim_personalization_status_type_v01 personalization_status;
}uim_perso_reactivation_status_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_perso_feature_enum_v01 feature;
  /**<   Indicates the personalization feature.
 Valid values:\n
      - UIM_PERSO_FEATURE_GW_NETWORK (0x00) --  GW network personalization \n
      - UIM_PERSO_FEATURE_GW_NETWORK_SUBSET (0x01) --  GW network subset personalization \n
      - UIM_PERSO_FEATURE_GW_SERVICE_PROVIDER (0x02) --  GW service provider personalization \n
      - UIM_PERSO_FEATURE_GW_CORPORATE (0x03) --  GW corporate personalization \n
      - UIM_PERSO_FEATURE_GW_UIM (0x04) --  GW UIM personalization \n
      - UIM_PERSO_FEATURE_1X_NETWORK_TYPE_1 (0x05) --  1X network type 1 personalization \n
      - UIM_PERSO_FEATURE_1X_NETWORK_TYPE_2 (0x06) --  1X network type 2 personalization \n
      - UIM_PERSO_FEATURE_1X_HRPD (0x07) --  1X HRPD personalization \n
      - UIM_PERSO_FEATURE_1X_SERVICE_PROVIDER (0x08) --  1X service provider personalization \n
      - UIM_PERSO_FEATURE_1X_CORPORATE (0x09) --  1X corporate personalization \n
      - UIM_PERSO_FEATURE_1X_RUIM (0x0A) --  1X RUIM personalization \n
      - UIM_PERSO_FEATURE_GW_SPN (0x0B) --  GW SPN personalization \n
      - UIM_PERSO_FEATURE_GW_SP_EHPLMN (0x0C) --  GW SP + EHPLMN personalization \n
      - UIM_PERSO_FEATURE_GW_ICCID (0x0D) --  GW ICCID personalization \n
      - UIM_PERSO_FEATURE_GW_IMPI (0x0E) --  GW IMPI personalization \n
      - UIM_PERSO_FEATURE_GW_NETWORK_SUBSET_SERVICE_PROVIDER (0x0F) --  GW network subset and service provider personalization
 \n
 Other values are reserved for future use and are to be handled
 as unknown personalization features by the client.
 */

  uint8_t ck_present;
  /**<   Indicates whether the control key is present. */
}uim_perso_feature_control_key_present_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  /*  Feature Control Key Present */
  uint32_t feature_control_key_present_len;  /**< Must be set to # of elements in feature_control_key_present */
  uim_perso_feature_control_key_present_type_v01 feature_control_key_present[QMI_UIM_PERSO_FEATURE_MAX_V01];
}uim_perso_control_key_present_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Gets the modem configuration for the UIM module. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Automatic Selection */
  uint8_t automatic_selection_valid;  /**< Must be set to true if automatic_selection is being passed */
  uint8_t automatic_selection;
  /**<   Indicates whether the modem is configured to automatically select
       the provisioning sessions at powerup. Valid values:\n
         - 0 -- Automatic provisioning is off\n
         - 1 -- Automatic provisioning is on
  */

  /* Optional */
  /*  Personalization Status */
  uint8_t personalization_status_valid;  /**< Must be set to true if personalization_status is being passed */
  uint32_t personalization_status_len;  /**< Must be set to # of elements in personalization_status */
  uim_personalization_status_type_v01 personalization_status[QMI_UIM_PERSO_FEATURE_MAX_V01];

  /* Optional */
  /*  Halt Subscription Publication */
  uint8_t halt_subscription_valid;  /**< Must be set to true if halt_subscription is being passed */
  uint8_t halt_subscription;
  /**<   Indicates if the modem is configured to publish the subscription
       after successful initialization. Valid values:\n
         - 0 -- Modem proceeds with publishing the subscription\n
         - 1 -- Modem does not publish the subscription
  */

  /* Optional */
  /*  Personalization Status of Other Slots */
  uint8_t extended_personalization_status_valid;  /**< Must be set to true if extended_personalization_status is being passed */
  uint32_t extended_personalization_status_len;  /**< Must be set to # of elements in extended_personalization_status */
  uim_personalization_status_other_slots_type_v01 extended_personalization_status[QMI_UIM_EXTENDED_CARDS_MAX_V01];

  /* Optional */
  /*  USB UICC supported flag */
  uint8_t usb_uicc_supported_valid;  /**< Must be set to true if usb_uicc_supported is being passed */
  uint8_t usb_uicc_supported;
  /**<   Indicates if the modem is configured to support the USB UICC feature.
       Valid values:\n
         - 0 -- Modem does not support the USB UICC feature\n
         - 1 -- Modem supports the USB UICC feature
  */

  /* Optional */
  /*  Support for SAP in client mode */
  uint8_t sap_client_supported_valid;  /**< Must be set to true if sap_client_supported is being passed */
  uint8_t sap_client_supported;
  /**<   Indicates if the modem is configured to support for SAP in client mode.
       Valid values:\n
         - 0 -- Modem does not support SAP in client mode\n
         - 1 -- Modem supports SAP in client mode
  */

  /* Optional */
  /*  Temporary Depersonalization Status */
  uint8_t temporary_depersonalization_status_valid;  /**< Must be set to true if temporary_depersonalization_status is being passed */
  uint32_t temporary_depersonalization_status_len;  /**< Must be set to # of elements in temporary_depersonalization_status */
  uim_temporary_depersonalization_status_type_v01 temporary_depersonalization_status[QMI_UIM_EXTENDED_CARDS_MAX_V01];

  /* Optional */
  /*  Personalization Reactivation Status */
  uint8_t perso_reactivation_status_valid;  /**< Must be set to true if perso_reactivation_status is being passed */
  uint32_t perso_reactivation_status_len;  /**< Must be set to # of elements in perso_reactivation_status */
  uim_perso_reactivation_status_type_v01 perso_reactivation_status[QMI_UIM_EXTENDED_PERSO_FEATURE_MAX_V01];

  /* Optional */
  /*  Personalization Control Key Present */
  uint8_t perso_control_key_present_valid;  /**< Must be set to true if perso_control_key_present is being passed */
  uint32_t perso_control_key_present_len;  /**< Must be set to # of elements in perso_control_key_present */
  uim_perso_control_key_present_type_v01 perso_control_key_present[QMI_UIM_EXTENDED_CARDS_MAX_V01];

  /* Optional */
  /*  Remote SimLock Storage */
  uint8_t remote_simlock_storage_valid;  /**< Must be set to true if remote_simlock_storage is being passed */
  uint8_t remote_simlock_storage;
  /**<   Indicates whether the modem stores the SimLock configuration on the local
       file system or on a remote storage. Valid values:\n
         - 0 -- Local SimLock configuration storage \n
         - 1 -- Remote SimLock configuration storage
  */

  /* Optional */
  /*  Emergency Only Mode */
  uint8_t emergency_only_mode_valid;  /**< Must be set to true if emergency_only_mode is being passed */
  uint8_t emergency_only_mode;
  /**<   Indicates whether the modem is restricted to emergency calls only.
       Valid values:\n
         - 0 -- Modem is not in Emergency Only mode\n
         - 1 -- Modem is in Emergency Only mode
  */

  /* Optional */
  /*  Support for Extended Length APDU */
  uint8_t extended_apdu_valid;  /**< Must be set to true if extended_apdu is being passed */
  uint8_t extended_apdu;
  /**<   Indicates whether the modem supports extended length APDUs.
       Valid values:\n
         - 0 -- Modem does not support extended length APDUs \n
         - 1 -- Modem supports extended length APDUs
  */
}uim_get_configuration_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_APDU_PROCEDURE_BYTES_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_APDU_RETURN_PROCEDURE_BYTES_V01 = 0x00, /**<  Return intermediate procedure bytes (Default)\n  */
  UIM_APDU_SKIP_PROCEDURE_BYTES_V01 = 0x01, /**<  Return final result and status words  */
  UIM_APDU_PROCEDURE_BYTES_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_apdu_procedure_bytes_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t total_length;
  /**<   Indicates the total length of the request APDU to the card.*/

  uint32_t token;
  /**<   Token used in the subsequent APDU requests.*/

  uint16_t offset;
  /**<   Offset of the current chunk, starting from 0.*/
}uim_send_apdu_long_request_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Sends an APDU to the card. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot to be used. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Mandatory */
  /*  APDU */
  uint32_t apdu_len;  /**< Must be set to # of elements in apdu */
  uint8_t apdu[QMI_UIM_APDU_DATA_MAX_V01];
  /**<   Content of the APDU.*/

  /* Optional */
  /*  Logical Channel */
  uint8_t channel_id_valid;  /**< Must be set to true if channel_id is being passed */
  uint8_t channel_id;
  /**<   ID of the logical channel to be used.*/

  /* Optional */
  /*  Intermediate Procedure Bytes */
  uint8_t procedure_bytes_valid;  /**< Must be set to true if procedure_bytes is being passed */
  uim_apdu_procedure_bytes_enum_v01 procedure_bytes;
  /**<   Indicates whether the client is expecting the intermediate procedure
 bytes or the final result from the card. Valid values:\n
      - UIM_APDU_RETURN_PROCEDURE_BYTES (0x00) --  Return intermediate procedure bytes (Default)\n
      - UIM_APDU_SKIP_PROCEDURE_BYTES (0x01) --  Return final result and status words
 */

  /* Optional */
  /*  Long Request */
  uint8_t long_request_valid;  /**< Must be set to true if long_request is being passed */
  uim_send_apdu_long_request_type_v01 long_request;
  /**<   \n Total length, token, and offset used to reconstruct the APDU request
       from the control point.
  */
}uim_send_apdu_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint16_t total_length;
  /**<   Indicates the total length of the response APDU from the card*/

  uint32_t token;
  /**<   Token used in the subsequent indications with APDU response*/
}uim_send_apdu_long_response_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Sends an APDU to the card. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  APDU Response */
  uint8_t apdu_valid;  /**< Must be set to true if apdu is being passed */
  uint32_t apdu_len;  /**< Must be set to # of elements in apdu */
  uint8_t apdu[QMI_UIM_APDU_DATA_MAX_V01];
  /**<   Content of the application protocol data unit response from the card.*/

  /* Optional */
  /*  Long APDU Response */
  uint8_t long_response_valid;  /**< Must be set to true if long_response is being passed */
  uim_send_apdu_long_response_type_v01 long_response;
  /**<   \n
       Token and total length to reconstruct the APDU response from the card.
  */
}uim_send_apdu_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t token;
  /**<   Unique token used in the previous QMI_UIM_SEND_APDU response.*/

  uint16_t total_length;
  /**<   Total length of the response APDU from the card.*/

  uint16_t offset;
  /**<   Offset of the current chunk, starting from 0.*/

  uint32_t apdu_len;  /**< Must be set to # of elements in apdu */
  uint8_t apdu[QMI_UIM_APDU_DATA_MAX_V01];
  /**<   Content of the data chunk of the APDU response from the card.*/
}uim_send_apdu_long_response_chunk_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indication with a Send APDU command result. */
typedef struct {

  /* Mandatory */
  /*  Chunk of APDU Response */
  uim_send_apdu_long_response_chunk_type_v01 long_response_chunk;
}uim_send_apdu_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_SAP_CONNECT_OP_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_SAP_OP_DISCONNECT_V01 = 0x00, /**<  Disconnect \n  */
  UIM_SAP_OP_CONNECT_V01 = 0x01, /**<  Connect \n  */
  UIM_SAP_OP_CHECK_STATUS_V01 = 0x02, /**<  Check status  */
  UIM_SAP_CONNECT_OP_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_sap_connect_op_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_sap_connect_op_enum_v01 connect;
  /**<   Indicates the operation to perform. Valid values:\n
      - UIM_SAP_OP_DISCONNECT (0x00) --  Disconnect \n
      - UIM_SAP_OP_CONNECT (0x01) --  Connect \n
      - UIM_SAP_OP_CHECK_STATUS (0x02) --  Check status
 */

  uim_slot_enum_v01 slot;
  /**<   Indicates the slot to be used. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */
}uim_sap_connect_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_SAP_DISCONNECT_MODE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_SAP_DISCONNECT_IMMEDIATE_V01 = 0x00, /**<  Immediate disconnect \n  */
  UIM_SAP_DISCONNECT_GRACEFULL_V01 = 0x01, /**<  Graceful shutdown of the connection  */
  UIM_SAP_DISCONNECT_MODE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_sap_disconnect_mode_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_SAP_CONNECTION_CONDITION_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_SAP_CONNECTION_COND_BLOCK_VOICE_OR_DATA_V01 = 0x00, /**<  Block a SAP connection when a voice or data call is active (Default) \n  */
  UIM_SAP_CONNECTION_COND_BLOCK_DATA_V01 = 0x01, /**<  Block a SAP connection when a data call is active \n  */
  UIM_SAP_CONNECTION_COND_BLOCK_VOICE_V01 = 0x02, /**<  Block a SAP connection when a voice call is active \n  */
  UIM_SAP_CONNECTION_COND_BLOCK_NONE_V01 = 0x03, /**<  Allow a SAP connection in all cases  */
  UIM_SAP_CONNECTION_CONDITION_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_sap_connection_condition_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Establishes and releases a connection to the UIM module as a SAP
    client. */
typedef struct {

  /* Mandatory */
  /*  SAP Connect */
  uim_sap_connect_type_v01 sap_connect;

  /* Optional */
  /*  Disconnect Mode (This TLV is used only for disconnection and is ignored
      in other cases.)
   */
  uint8_t disconnect_mode_valid;  /**< Must be set to true if disconnect_mode is being passed */
  uim_sap_disconnect_mode_enum_v01 disconnect_mode;
  /**<   Indicates the type of disconnection to perform. Valid values:\n
      - UIM_SAP_DISCONNECT_IMMEDIATE (0x00) --  Immediate disconnect \n
      - UIM_SAP_DISCONNECT_GRACEFULL (0x01) --  Graceful shutdown of the connection
 */

  /* Optional */
  /*  Intermediate GET RESPONSE */
  uint8_t intermediate_get_response_valid;  /**< Must be set to true if intermediate_get_response is being passed */
  uint8_t intermediate_get_response;
  /**<   Indicates whether the client is expecting the intermediate GET RESPONSE
       procedure bytes or the final result from the card. Valid values:\n
        - 0 -- Return final result and status words\n
        - 1 -- Return intermediate GET RESPONSE procedure bytes
  */

  /* Optional */
  /*  Condition to Enable a SAP Connection */
  uint8_t connection_condition_valid;  /**< Must be set to true if connection_condition is being passed */
  uim_sap_connection_condition_enum_v01 connection_condition;
  /**<   Indicates the type of condition to apply during a connection request.
 When this TLV is missing, the default behavior is to block a SAP
 connection when a voice or data call is active. Valid
 values:\n
      - UIM_SAP_CONNECTION_COND_BLOCK_VOICE_OR_DATA (0x00) --  Block a SAP connection when a voice or data call is active (Default) \n
      - UIM_SAP_CONNECTION_COND_BLOCK_DATA (0x01) --  Block a SAP connection when a data call is active \n
      - UIM_SAP_CONNECTION_COND_BLOCK_VOICE (0x02) --  Block a SAP connection when a voice call is active \n
      - UIM_SAP_CONNECTION_COND_BLOCK_NONE (0x03) --  Allow a SAP connection in all cases
 */
}uim_sap_connection_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_SAP_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_SAP_STATE_NOT_ENABLED_V01 = 0x00, /**<  Not enabled \n  */
  UIM_SAP_STATE_CONNECTING_V01 = 0x01, /**<  Connecting \n  */
  UIM_SAP_STATE_CONNECTED_SUCCESSFULLY_V01 = 0x02, /**<  Connected successfully \n  */
  UIM_SAP_STATE_CONNECTION_ERROR_V01 = 0x03, /**<  Connection error \n  */
  UIM_SAP_STATE_DISCONNECTING_V01 = 0x04, /**<  Disconnecting \n  */
  UIM_SAP_STATE_DISCONNECTED_SUCCESSFULLY_V01 = 0x05, /**<  Disconnected successfully  */
  UIM_SAP_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_sap_status_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Establishes and releases a connection to the UIM module as a SAP
    client. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  SAP State (This TLV is returned only when the client requested the SAP
      state.)
   */
  uint8_t sap_state_valid;  /**< Must be set to true if sap_state is being passed */
  uim_sap_status_enum_v01 sap_state;
  /**<   Indicates the SAP connection status. Valid values:\n
      - UIM_SAP_STATE_NOT_ENABLED (0x00) --  Not enabled \n
      - UIM_SAP_STATE_CONNECTING (0x01) --  Connecting \n
      - UIM_SAP_STATE_CONNECTED_SUCCESSFULLY (0x02) --  Connected successfully \n
      - UIM_SAP_STATE_CONNECTION_ERROR (0x03) --  Connection error \n
      - UIM_SAP_STATE_DISCONNECTING (0x04) --  Disconnecting \n
      - UIM_SAP_STATE_DISCONNECTED_SUCCESSFULLY (0x05) --  Disconnected successfully
 */
}uim_sap_connection_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_SAP_REQUEST_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_SAP_REQUEST_GET_ATR_V01 = 0x00, /**<  Gets the ATR \n  */
  UIM_SAP_REQUEST_SEND_APDU_V01 = 0x01, /**<  Sends the APDU \n  */
  UIM_SAP_REQUEST_POWER_SIM_OFF_V01 = 0x02, /**<  Powers off the SIM \n  */
  UIM_SAP_REQUEST_POWER_SIM_ON_V01 = 0x03, /**<  Powers on the SIM \n  */
  UIM_SAP_REQUEST_RESET_SIM_V01 = 0x04, /**<  Resets the SIM \n  */
  UIM_SAP_REQUEST_CARD_READER_STATUS_V01 = 0x05, /**<  Indicates the card reader status  */
  UIM_SAP_REQUEST_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_sap_request_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_sap_request_enum_v01 sap_request;
  /**<   Indicates the SAP request. Valid values:\n
      - UIM_SAP_REQUEST_GET_ATR (0x00) --  Gets the ATR \n
      - UIM_SAP_REQUEST_SEND_APDU (0x01) --  Sends the APDU \n
      - UIM_SAP_REQUEST_POWER_SIM_OFF (0x02) --  Powers off the SIM \n
      - UIM_SAP_REQUEST_POWER_SIM_ON (0x03) --  Powers on the SIM \n
      - UIM_SAP_REQUEST_RESET_SIM (0x04) --  Resets the SIM \n
      - UIM_SAP_REQUEST_CARD_READER_STATUS (0x05) --  Indicates the card reader status
 */

  uim_slot_enum_v01 slot;
  /**<   Indicates the slot to be used. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */
}uim_sap_request_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Executes a SAP request. */
typedef struct {

  /* Mandatory */
  /*  SAP Request */
  uim_sap_request_type_v01 sap_request;

  /* Optional */
  /*  APDU Data (This TLV must be present for the Send APDU request. For all
      other cases, if present, the TLV is ignored.)
   */
  uint8_t apdu_valid;  /**< Must be set to true if apdu is being passed */
  uint32_t apdu_len;  /**< Must be set to # of elements in apdu */
  uint8_t apdu[QMI_UIM_APDU_DATA_MAX_V01];
  /**<   APDU value.*/
}uim_sap_request_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Executes a SAP request. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  ATR Value (This TLV is present only for the Get ATR request.) */
  uint8_t ATR_value_valid;  /**< Must be set to true if ATR_value is being passed */
  uint32_t ATR_value_len;  /**< Must be set to # of elements in ATR_value */
  uint8_t ATR_value[QMI_UIM_ATR_DATA_MAX_V01];
  /**<   Value of the ATR from the card.*/

  /* Optional */
  /*  APDU Result (This TLV is present only for the Send APDU request.) */
  uint8_t apdu_valid;  /**< Must be set to true if apdu is being passed */
  uint32_t apdu_len;  /**< Must be set to # of elements in apdu */
  uint8_t apdu[QMI_UIM_APDU_DATA_MAX_V01];
  /**<   APDU response.*/

  /* Optional */
  /*  Card Reader Status (This TLV is present only for a card reader status
      request.)
   */
  uint8_t status_valid;  /**< Must be set to true if status is being passed */
  uint32_t status_len;  /**< Must be set to # of elements in status */
  uint8_t status[QMI_UIM_CARD_READER_DATA_MAX_V01];
  /**<   Value of the card reader status.*/
}uim_sap_request_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_sap_status_enum_v01 sap_state;
  /**<   Indicates the SAP connection status. Valid values:\n
      - UIM_SAP_STATE_NOT_ENABLED (0x00) --  Not enabled \n
      - UIM_SAP_STATE_CONNECTING (0x01) --  Connecting \n
      - UIM_SAP_STATE_CONNECTED_SUCCESSFULLY (0x02) --  Connected successfully \n
      - UIM_SAP_STATE_CONNECTION_ERROR (0x03) --  Connection error \n
      - UIM_SAP_STATE_DISCONNECTING (0x04) --  Disconnecting \n
      - UIM_SAP_STATE_DISCONNECTED_SUCCESSFULLY (0x05) --  Disconnected successfully
 */

  uim_slot_enum_v01 slot;
  /**<   Indicates the slot in use. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */
}uim_sap_indication_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indicates a change in the status of the SAP connection. */
typedef struct {

  /* Optional */
  /*  Sap Connection Event */
  uint8_t sap_connection_event_valid;  /**< Must be set to true if sap_connection_event is being passed */
  uim_sap_indication_type_v01 sap_connection_event;
}uim_sap_connection_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_FILE_CONTROL_INFORMATION_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_FILE_CONTROL_INFORMATION_NO_DATA_V01 = 0x00, /**<  No data \n  */
  UIM_FILE_CONTROL_INFORMATION_FCP_V01 = 0x01, /**<  FCP \n  */
  UIM_FILE_CONTROL_INFORMATION_FCI_V01 = 0x02, /**<  FCI \n  */
  UIM_FILE_CONTROL_INFORMATION_FCI_WITH_INTERFACES_V01 = 0x03, /**<  FCI with interfaces \n  */
  UIM_FILE_CONTROL_INFORMATION_FMD_V01 = 0x04, /**<  FMD  */
  UIM_FILE_CONTROL_INFORMATION_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_file_control_information_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Opens and closes a logical channel to an application on a UICC card. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot to be used. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Optional */
  /*  Open the Logical Channel */
  uint8_t aid_valid;  /**< Must be set to true if aid is being passed */
  uint32_t aid_len;  /**< Must be set to # of elements in aid */
  uint8_t aid[QMI_UIM_AID_MAX_V01];
  /**<   Application identifier value.*/

  /* Optional */
  /*  Close the Logical Channel */
  uint8_t channel_id_valid;  /**< Must be set to true if channel_id is being passed */
  uint8_t channel_id;
  /**<   ID of the logical channel to be closed.*/

  /* Optional */
  /*  Template Requested from the Card in SELECT */
  uint8_t file_control_information_valid;  /**< Must be set to true if file_control_information is being passed */
  uim_file_control_information_enum_v01 file_control_information;
  /**<   Template requested from the card in the SELECT command when the
 application is selected. When this TLV is missing, FCP is requested
 by default. Valid values:\n
      - UIM_FILE_CONTROL_INFORMATION_NO_DATA (0x00) --  No data \n
      - UIM_FILE_CONTROL_INFORMATION_FCP (0x01) --  FCP \n
      - UIM_FILE_CONTROL_INFORMATION_FCI (0x02) --  FCI \n
      - UIM_FILE_CONTROL_INFORMATION_FCI_WITH_INTERFACES (0x03) --  FCI with interfaces \n
      - UIM_FILE_CONTROL_INFORMATION_FMD (0x04) --  FMD
 */

  /* Optional */
  /*  Termination of Application */
  uint8_t terminate_application_valid;  /**< Must be set to true if terminate_application is being passed */
  uint8_t terminate_application;
  /**<   Indicates whether the application is terminated with a SELECT request
       before closing the associated logical channel. When the Termination of
       Application TLV is missing, the default behavior is TRUE to
       terminate the application.
  */
}uim_logical_channel_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Opens and closes a logical channel to an application on a UICC card. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Channel ID */
  uint8_t channel_id_valid;  /**< Must be set to true if channel_id is being passed */
  uint8_t channel_id;
  /**<   ID of the logical channel that was opened.*/

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;

  /* Optional */
  /*  Response to SELECT */
  uint8_t select_response_valid;  /**< Must be set to true if select_response is being passed */
  uint32_t select_response_len;  /**< Must be set to # of elements in select_response */
  uint8_t select_response[QMI_UIM_SELECT_RESPONSE_MAX_V01];
  /**<   Raw value of the response sent by the card to the initial SELECT
       command. This is for responses of size less than or equal to 255 bytes.
  */

  /* Optional */
  /*  Long Response to SELECT */
  uint8_t long_select_response_valid;  /**< Must be set to true if long_select_response is being passed */
  uint32_t long_select_response_len;  /**< Must be set to # of elements in long_select_response */
  uint8_t long_select_response[QMI_UIM_LONG_SELECT_RESPONSE_MAX_V01];
  /**<   Raw value of the response sent by the card to the SELECT command.
       This is for responses of size greater than 255 bytes.
  */
}uim_logical_channel_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Enables the client to indicate whether it is OK to
    proceed with publishing the subscription. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  OK for Subscription */
  uint8_t ok_for_subscription;
  /**<   Indicates whether it is OK to publish the subscription. Valid values:\n
        - 0 -- Not OK to publish the subscription\n
        - 1 -- OK to publish the subscription
  */

  /* Optional */
  /*  Encrypted IMSI */
  uint8_t encrypted_imsi_valid;  /**< Must be set to true if encrypted_imsi is being passed */
  uint32_t encrypted_imsi_len;  /**< Must be set to # of elements in encrypted_imsi */
  uint8_t encrypted_imsi[QMI_UIM_ENCRYPTED_IMSI_MAX_V01];
  /**<   Encrypted value of the IMSI of the session. The decrypted value is checked
       against the IMSI of the card, and the command is executed only if it matches.
  */
}uim_subscription_ok_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Enables the client to indicate whether it is OK to
    proceed with publishing the subscription. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_subscription_ok_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Retrieves the Answer to Reset of a specific card. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot to be used. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */
}uim_get_atr_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Retrieves the Answer to Reset of a specific card. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  ATR Value */
  uint8_t atr_value_valid;  /**< Must be set to true if atr_value is being passed */
  uint32_t atr_value_len;  /**< Must be set to # of elements in atr_value */
  uint8_t atr_value[QMI_UIM_ATR_MAX_V01];
  /**<   Raw value of the ATR sent by the card during the initialization.*/

  /* Optional */
  /*  eUICC-related Functions Supported */
  uint8_t euicc_supported_valid;  /**< Must be set to true if euicc_supported is being passed */
  uint8_t euicc_supported;
  /**<   Indicates whether support for eUICC-related functions is enabled. Values: \n
        0 - eUICC functions not supported \n
        1 - eUICC functions supported
  */
}uim_get_atr_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Opens a logical channel on a UICC card. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot to be used. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Optional */
  /*  AID */
  uint8_t aid_valid;  /**< Must be set to true if aid is being passed */
  uint32_t aid_len;  /**< Must be set to # of elements in aid */
  uint8_t aid[QMI_UIM_AID_MAX_V01];
  /**<   Application identifier value.*/

  /* Optional */
  /*  Template Requested from the Card in SELECT */
  uint8_t file_control_information_valid;  /**< Must be set to true if file_control_information is being passed */
  uim_file_control_information_enum_v01 file_control_information;
  /**<   Template requested from the card in the SELECT command when the
 application is selected. When this TLV is missing, FCP is requested
 by default. Valid values:\n
      - UIM_FILE_CONTROL_INFORMATION_NO_DATA (0x00) --  No data \n
      - UIM_FILE_CONTROL_INFORMATION_FCP (0x01) --  FCP \n
      - UIM_FILE_CONTROL_INFORMATION_FCI (0x02) --  FCI \n
      - UIM_FILE_CONTROL_INFORMATION_FCI_WITH_INTERFACES (0x03) --  FCI with interfaces \n
      - UIM_FILE_CONTROL_INFORMATION_FMD (0x04) --  FMD
 */
}uim_open_logical_channel_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Opens a logical channel on a UICC card. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Channel ID */
  uint8_t channel_id_valid;  /**< Must be set to true if channel_id is being passed */
  uint8_t channel_id;
  /**<   ID of the logical channel that was opened.*/

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;

  /* Optional */
  /*  Response to SELECT */
  uint8_t select_response_valid;  /**< Must be set to true if select_response is being passed */
  uint32_t select_response_len;  /**< Must be set to # of elements in select_response */
  uint8_t select_response[QMI_UIM_SELECT_RESPONSE_MAX_V01];
  /**<   Raw value of the response sent by the card to the initial SELECT
       command. This is for responses of size less than or equal to 255 bytes.
  */

  /* Optional */
  /*  Long Response to SELECT */
  uint8_t long_select_response_valid;  /**< Must be set to true if long_select_response is being passed */
  uint32_t long_select_response_len;  /**< Must be set to # of elements in long_select_response */
  uint8_t long_select_response[QMI_UIM_LONG_SELECT_RESPONSE_MAX_V01];
  /**<   Raw value of the response sent by the card to the SELECT command.
       This is for responses of size greater than 255 bytes.
  */
}uim_open_logical_channel_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_SESSION_CLOSE_CAUSE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_SESSION_CLOSED_CAUSE_UNKNOWN_V01 = 0x00, /**<  Unknown cause \n  */
  UIM_SESSION_CLOSED_CAUSE_CLIENT_REQUEST_V01 = 0x01, /**<  Client requested to deactivate the session \n  */
  UIM_SESSION_CLOSED_CAUSE_CARD_ERROR_V01 = 0x02, /**<  Card error \n  */
  UIM_SESSION_CLOSED_CAUSE_CARD_POWER_DOWN_V01 = 0x03, /**<  SIM card is powered down \n  */
  UIM_SESSION_CLOSED_CAUSE_CARD_REMOVED_V01 = 0x04, /**<  SIM card is removed \n  */
  UIM_SESSION_CLOSED_CAUSE_REFRESH_V01 = 0x05, /**<  Session is deactivated as a part of a Refresh procedure \n  */
  UIM_SESSION_CLOSED_CAUSE_PIN_STATUS_FAIL_V01 = 0x06, /**<  Status of the PIN cannot be retrieved from the SIM \n  */
  UIM_SESSION_CLOSED_CAUSE_RECOVERY_V01 = 0x07, /**<  Internal card recovery \n  */
  UIM_SESSION_CLOSED_CAUSE_FDN_SRV_ENABLED_WITH_NO_FDN_SUPPORT_V01 = 0x08, /**<  FDN service is enabled on the SIM, but the terminal does not support
       it \n  */
  UIM_SESSION_CLOSED_CAUSE_PERSO_OPERATION_FAIL_V01 = 0x09, /**<  Personalization failure \n  */
  UIM_SESSION_CLOSED_CAUSE_FILE_CONTENT_INVALID_V01 = 0x0A, /**<  Content of the file is invalid \n  */
  UIM_SESSION_CLOSED_CAUSE_MANDATORY_FILE_MISSING_V01 = 0x0B, /**<  Mandatory file is missing  */
  UIM_SESSION_CLOSE_CAUSE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_session_close_cause_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indicates either a provisioning or a nonprovisioning session is
             closed by the modem. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot to be used. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Optional */
  /*  Application ID */
  uint8_t aid_valid;  /**< Must be set to true if aid is being passed */
  uint32_t aid_len;  /**< Must be set to # of elements in aid */
  uint8_t aid[QMI_UIM_AID_MAX_V01];
  /**<   Application identifier value.*/

  /* Optional */
  /*  Logical Channel */
  uint8_t channel_id_valid;  /**< Must be set to true if channel_id is being passed */
  uint8_t channel_id;
  /**<   ID of the logical channel being closed.*/

  /* Optional */
  /*  Provisioning Session */
  uint8_t provisioning_session_valid;  /**< Must be set to true if provisioning_session is being passed */
  uim_session_type_enum_v01 provisioning_session;
  /**<   Indicates the provisioning session type that is closed.
       Valid values: 0 to 3 and 10 to 15. See Table \ref{tbl:sessions} for
       the list of available session types with their values and descriptions.
  */

  /* Optional */
  /*  Session Closure Cause */
  uint8_t cause_valid;  /**< Must be set to true if cause is being passed */
  uim_session_close_cause_enum_v01 cause;
  /**<   Indicates the cause of a session closure. See
       Table \ref{tbl:sessionClosures} for the causes of session closures with
       their values and descriptions.

       Other values are reserved for the future use and are to be handled
       as an unknown cause by the client.
  */

  /* Optional */
  /*  File ID */
  uint8_t file_id_valid;  /**< Must be set to true if file_id is being passed */
  uint16_t file_id;
  /**<   Indicates the file ID of the mandatory file that is missing, or is
       present but contains invalid content. */
}uim_session_closed_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Registers for file change notifications triggered by the card for
             all files. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  Register for Refresh */
  uint8_t register_for_refresh;
  /**<   Indicates whether to register or deregister for refresh indications.
       Valid values:\n
        - 0 -- Deregister\n
        - 1 -- Register
  */

  /* Optional */
  /*  Vote for Initialization */
  uint8_t vote_for_init_valid;  /**< Must be set to true if vote_for_init is being passed */
  uint8_t vote_for_init;
  /**<   Indicates whether to vote for initialization when there is a
       refresh. When the Vote for Initialization TLV is missing, the default
       behavior is to not wait for the client vote. Valid values:\n
        - 0 -- Client does not vote for initialization (Default)\n
        - 1 -- Client votes for initialization
  */
}uim_refresh_register_all_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Registers for file change notifications triggered by the card for
             all files. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_refresh_register_all_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Changes the activation status of the file on the card. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  File ID */
  uim_file_id_type_v01 file_id;

  /* Mandatory */
  /*  File Status */
  uim_file_status_type_v01 file_status;
  /**<   Activates or deactivates the file. Valid values:\n
      - UIM_FILE_STATUS_DEACTIVATED (0x00) --  File is deactivated. \n
      - UIM_FILE_STATUS_ACTIVATED (0x01) --  File is activated.
 */
}uim_set_file_status_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Changes the activation status of the file on the card. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_set_file_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_PHYSICAL_SLOT_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_PHY_SLOT_1_V01 = 0x01, /**<  Slot 1 \n  */
  UIM_PHY_SLOT_2_V01 = 0x02, /**<  Slot 2 \n  */
  UIM_PHY_SLOT_3_V01 = 0x03, /**<  Slot 3 \n  */
  UIM_PHY_SLOT_4_V01 = 0x04, /**<  Slot 4 \n  */
  UIM_PHY_SLOT_5_V01 = 0x05, /**<  Slot 5  */
  UIM_PHYSICAL_SLOT_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_physical_slot_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Switches the binding between a logical slot and a physical slot. */
typedef struct {

  /* Mandatory */
  /*  Logical Slot */
  uim_slot_enum_v01 logical_slot;
  /**<   Logical slot that is switched to the physical slot. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Mandatory */
  /*  Physical Slot */
  uim_physical_slot_enum_v01 physical_slot;
  /**<   Physical slot that the logical slot is to be switched to. Valid values:\n
      - UIM_PHY_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_PHY_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_PHY_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_PHY_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_PHY_SLOT_5 (0x05) --  Slot 5
 */
}uim_switch_slot_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Switches the binding between a logical slot and a physical slot. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_switch_slot_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Retrieves the current status of the physical and logical slots. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}uim_get_slots_status_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_PHYSICAL_SLOT_STATE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_PHYSICAL_SLOT_STATE_INACTIVE_V01 = 0x00, /**<  Inactive \n  */
  UIM_PHYSICAL_SLOT_STATE_ACTIVE_V01 = 0x01, /**<  Active  */
  UIM_PHYSICAL_SLOT_STATE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_physical_slot_state_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_PHYSICAL_CARD_STATE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_PHYSICAL_CARD_STATE_UNKNOWN_V01 = 0x00, /**<  Unknown \n  */
  UIM_PHYSICAL_CARD_STATE_ABSENT_V01 = 0x01, /**<  Absent \n  */
  UIM_PHYSICAL_CARD_STATE_PRESENT_V01 = 0x02, /**<  Present  */
  UIM_PHYSICAL_CARD_STATE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_physical_card_state_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_CARD_PROTOCOL_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_CARD_PROTOCOL_UNKNOWN_V01 = 0x00, /**<  Unknown \n  */
  UIM_CARD_PROTOCOL_ICC_V01 = 0x01, /**<  ICC Protocol \n  */
  UIM_CARD_PROTOCOL_UICC_V01 = 0x02, /**<  UICC Protocol  */
  UIM_CARD_PROTOCOL_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_card_protocol_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_physical_card_state_enum_v01 physical_card_status;
  /**<   Status of the card in the physical slot. Valid values:\n
      - UIM_PHYSICAL_CARD_STATE_UNKNOWN (0x00) --  Unknown \n
      - UIM_PHYSICAL_CARD_STATE_ABSENT (0x01) --  Absent \n
      - UIM_PHYSICAL_CARD_STATE_PRESENT (0x02) --  Present
 */

  uim_physical_slot_state_enum_v01 physical_slot_state;
  /**<   State of the physical slot. Valid values:\n
      - UIM_PHYSICAL_SLOT_STATE_INACTIVE (0x00) --  Inactive \n
      - UIM_PHYSICAL_SLOT_STATE_ACTIVE (0x01) --  Active
 */

  uim_slot_enum_v01 logical_slot;
  /**<   Logical slot associated with this physical slot. This is
 valid only if the physical slot is active. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  uint32_t iccid_len;  /**< Must be set to # of elements in iccid */
  uint8_t iccid[QMI_UIM_ICCID_LEN_MAX_V01];
  /**<   Contains the ICCID of the card in the physical slot.*/
}uim_physical_slot_status_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_card_protocol_enum_v01 card_protocol;
  /**<   Protocol of the card. Valid values:\n
      - UIM_CARD_PROTOCOL_UNKNOWN (0x00) --  Unknown \n
      - UIM_CARD_PROTOCOL_ICC (0x01) --  ICC Protocol \n
      - UIM_CARD_PROTOCOL_UICC (0x02) --  UICC Protocol
 */

  uint8_t num_app;
  /**<   Number of valid applications present in the EF-DIR of card.  */

  uint32_t atr_value_len;  /**< Must be set to # of elements in atr_value */
  uint8_t atr_value[QMI_UIM_ATR_MAX_V01];
  /**<   Raw value of the ATR sent by the card during the initialization.*/

  uint8_t is_euicc;
  /**<   Indicates whether the card is an eUICC card based on the ATR. Values: \n
        0 - Not an eUICC card \n
        1 - eUICC card
   */
}uim_physical_slot_information_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Retrieves the current status of the physical and logical slots. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Physical Slot Status */
  uint8_t physical_slot_status_valid;  /**< Must be set to true if physical_slot_status is being passed */
  uint32_t physical_slot_status_len;  /**< Must be set to # of elements in physical_slot_status */
  uim_physical_slot_status_type_v01 physical_slot_status[QMI_UIM_PHYSICAL_SLOTS_MAX_V01];
  /**<   \n
       Information regarding the various physical slots on the device.\n
       The number of elements correspond with the number of physical slots
       on the device.
  */

  /* Optional */
  /*  Physical Slot Information */
  uint8_t physical_slot_information_valid;  /**< Must be set to true if physical_slot_information is being passed */
  uint32_t physical_slot_information_len;  /**< Must be set to # of elements in physical_slot_information */
  uim_physical_slot_information_type_v01 physical_slot_information[QMI_UIM_PHYSICAL_SLOTS_MAX_V01];
  /**<   \n Additional information of the physical slots on the device.\n
       The number of elements corresponds with the number of physical slots
       on the device.
    */
}uim_get_slots_status_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indicates that the status of the physical slot has changed. */
typedef struct {

  /* Optional */
  /*  Physical Slot Status */
  uint8_t physical_slot_status_valid;  /**< Must be set to true if physical_slot_status is being passed */
  uint32_t physical_slot_status_len;  /**< Must be set to # of elements in physical_slot_status */
  uim_physical_slot_status_type_v01 physical_slot_status[QMI_UIM_PHYSICAL_SLOTS_MAX_V01];

  /* Optional */
  /*  Physical Slot Information */
  uint8_t physical_slot_information_valid;  /**< Must be set to true if physical_slot_information is being passed */
  uint32_t physical_slot_information_len;  /**< Must be set to # of elements in physical_slot_information */
  uim_physical_slot_information_type_v01 physical_slot_information[QMI_UIM_PHYSICAL_SLOTS_MAX_V01];
  /**<   \n Additional information of the physical slots on the device.\n
       The number of elements corresponds with the number of physical slots
       on the device.
      */
}uim_slot_status_change_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t long_data_token;
  /**<   Unique long data token used in the previous QMI_UIM_READ_TRANSPARENT
       response or indication.
  */

  uint16_t total_length;
  /**<   Total length of the read data. */

  uint16_t offset;
  /**<   Offset of the current chunk (starting from 0). */

  uim_read_transparent_result_type_v01 read_result;
  /**<   Content of the read data chunk. */
}uim_read_transparent_long_response_chunk_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indication with a read transparent command result. */
typedef struct {

  /* Mandatory */
  /*  Chunk of Read Transparent Data */
  uim_read_transparent_long_response_chunk_type_v01 long_response_chunk;

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;

  /* Optional */
  /*  Encrypted Data */
  uint8_t encryption_valid;  /**< Must be set to true if encryption is being passed */
  uint8_t encryption;
  /**<   Indicates whether the data from the card passed in read_result is
       encrypted. Valid values:\n
        - 0 -- Data in read_result is unencrypted \n
        - 1 -- Data in read_result is encrypted \n
       If the Encrypted Data TLV is missing, the read_result data is in
       unencrypted format.
  */
}uim_read_transparent_long_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indicates the busy status of a SIM card. */
typedef struct {

  /* Optional */
  /*  SIM Busy Status */
  uint8_t sim_busy_status_valid;  /**< Must be set to true if sim_busy_status is being passed */
  uint32_t sim_busy_status_len;  /**< Must be set to # of elements in sim_busy_status */
  uint8_t sim_busy_status[QMI_UIM_EXTENDED_CARDS_MAX_V01];
  /**<   Indicates whether the card on the corresponding slot is busy. Valid
       values:\n
        - 0 -- SIM card is not busy \n
        - 1 -- SIM card is busy
  */
}uim_sim_busy_status_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Retrieves information about the SE.13 table used by the modem. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}uim_get_plmn_name_table_info_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_PLMN_NAME_TABLE_SOURCE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_PLMN_NAME_TABLE_SOURCE_HARDCODED_V01 = 0x01, /**<  Table is hardcoded in the modem source code \n  */
  UIM_PLMN_NAME_TABLE_SOURCE_EFS_V01 = 0x02, /**<  Table is fetched from the modem file system  */
  UIM_PLMN_NAME_TABLE_SOURCE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_plmn_name_table_source_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t month;
  /**<   Month. */

  uint8_t day;
  /**<   Day of the month. */

  uint16_t year;
  /**<   Year. */
}uim_plmn_name_release_date_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Retrieves information about the SE.13 table used by the modem. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Release Date */
  uint8_t release_date_valid;  /**< Must be set to true if release_date is being passed */
  uim_plmn_name_release_date_info_type_v01 release_date;
  /**<   \n
       Information regarding the release date of the SE.13 table database
       used by the modem.
  */

  /* Optional */
  /*  Table Source */
  uint8_t table_source_valid;  /**< Must be set to true if table_source is being passed */
  uim_plmn_name_table_source_enum_v01 table_source;
  /**<   Information regarding the source of the used SE.13 table database.\n
 Valid values:\n
      - UIM_PLMN_NAME_TABLE_SOURCE_HARDCODED (0x01) --  Table is hardcoded in the modem source code \n
      - UIM_PLMN_NAME_TABLE_SOURCE_EFS (0x02) --  Table is fetched from the modem file system
 \n
 Other values are reserved for future use and are to be ignored by
 the client.
 */
}uim_get_plmn_name_table_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  char mcc[QMI_UIM_MCC_LEN_V01];
  /**<   MCC value in ASCII characters. */

  uint32_t mnc_len;  /**< Must be set to # of elements in mnc */
  char mnc[QMI_UIM_MNC_MAX_V01];
  /**<   MNC value in ASCII characters. */
}uim_network_perso_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_network_perso_type_v01 network;
  /**<   MCC and MNC network information.*/

  char digit6;
  /**<   Digit 6 of the IMSI in ASCII characters. */

  char digit7;
  /**<   Digit 7 of the IMSI in ASCII characters. */
}uim_gw_network_subset_perso_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_network_perso_type_v01 network;
  /**<   MCC and MNC network information.*/

  uint8_t gid1;
  /**<   Service provider code found in GID1. */
}uim_gw_sp_perso_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_network_perso_type_v01 network;
  /**<   MCC and MNC network information.*/

  uint32_t gid1_len;  /**< Must be set to # of elements in gid1 */
  uint8_t gid1[QMI_UIM_GID_MAX_V01];
  /**<   Service provider code found in GID1. */
}uim_gw_sp_ext_perso_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_network_perso_type_v01 network;
  /**<   MCC and MNC network information.*/

  uint32_t gid1_len;  /**< Must be set to # of elements in gid1 */
  uint8_t gid1[QMI_UIM_GID_EXT_MAX_V01];
  /**<   Service provider code found in GID1. */
}uim_gw_sp_ext2_perso_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_network_perso_type_v01 network;
  /**<   MCC and MNC network information.*/

  uint8_t gid1;
  /**<   Service provider code found in GID1. */

  uint8_t gid2;
  /**<   Corporate customer code found in GID2. */
}uim_gw_corporate_perso_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_network_perso_type_v01 network;
  /**<   MCC and MNC network information.*/

  uint32_t gid1_len;  /**< Must be set to # of elements in gid1 */
  uint8_t gid1[QMI_UIM_GID_MAX_V01];
  /**<   Service provider code found in GID1. */

  uint32_t gid2_len;  /**< Must be set to # of elements in gid2 */
  uint8_t gid2[QMI_UIM_GID_MAX_V01];
  /**<   Corporate customer code found in GID2. */
}uim_gw_corporate_ext_perso_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_network_perso_type_v01 network;
  /**<    MCC and MNC network information.*/

  uint32_t gid1_len;  /**< Must be set to # of elements in gid1 */
  uint8_t gid1[QMI_UIM_GID_EXT_MAX_V01];
  /**<   Service provider code found in GID1. */

  uint32_t gid2_len;  /**< Must be set to # of elements in gid2 */
  uint8_t gid2[QMI_UIM_GID_EXT_MAX_V01];
  /**<   Corporate customer code found in GID2. */
}uim_gw_corporate_ext2_perso_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_network_perso_type_v01 network;
  /**<    MCC and MNC network information.*/

  uint32_t msin_len;  /**< Must be set to # of elements in msin */
  char msin[QMI_UIM_MSIN_MAX_V01];
  /**<   MSIN value stored on the card in ASCII characters.
  */
}uim_sim_perso_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  char irm_code[QMI_UIM_IRM_CODE_LEN_V01];
  /**<   First four digits of the IRM-based MIN of IMSI_M in ASCII characters. */
}uim_1x_network_type2_perso_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_network_perso_type_v01 network;
  /**<    MCC and MNC network information.*/

  uint8_t spn[QMI_UIM_GW_SPN_LEN_V01];
  /**<   Service provider name value stored with the same coding used for the EF-SPN in the card. */
}uim_gw_spn_perso_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_network_perso_type_v01 network;
  /**<   Network MCC and MNC information.*/

  uint32_t gid1_len;  /**< Must be set to # of elements in gid1 */
  uint8_t gid1[QMI_UIM_GID_EXT_MAX_V01];
  /**<   Service provider code found in GID1. */

  uim_network_perso_type_v01 ehplmn;
  /**<   MCC and MNC information that must be
       present in the EHPLMN file of the card. */
}uim_gw_sp_ehplmn_perso_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_network_perso_type_v01 network;
  /**<   Network MCC and MNC information.*/

  uint32_t iccid_len;  /**< Must be set to # of elements in iccid */
  char iccid[QMI_UIM_ICCID_DIGIT_MAX_V01];
  /**<   ICCID digits in ASCII characters. */
}uim_gw_iccid_perso_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Activates and sets the personalization data on the phone. */
typedef struct {

  /* Mandatory */
  /*  Control Key */
  uint32_t ck_value_len;  /**< Must be set to # of elements in ck_value */
  char ck_value[QMI_UIM_CK_MAX_V01];
  /**<   Control key value. This value is a sequence of ASCII characters.
  */

  /* Optional */
  /*  GW Network Personalization */
  uint8_t feature_gw_network_perso_valid;  /**< Must be set to true if feature_gw_network_perso is being passed */
  uint32_t feature_gw_network_perso_len;  /**< Must be set to # of elements in feature_gw_network_perso */
  uim_network_perso_type_v01 feature_gw_network_perso[QMI_UIM_PERSO_NUM_NW_MAX_V01];

  /* Optional */
  /*  GW Network Subset Personalization */
  uint8_t feature_gw_network_subset_perso_valid;  /**< Must be set to true if feature_gw_network_subset_perso is being passed */
  uint32_t feature_gw_network_subset_perso_len;  /**< Must be set to # of elements in feature_gw_network_subset_perso */
  uim_gw_network_subset_perso_type_v01 feature_gw_network_subset_perso[QMI_UIM_PERSO_NUM_NS_MAX_V01];

  /* Optional */
  /*  GW Service Provider Personalization */
  uint8_t feature_gw_sp_perso_valid;  /**< Must be set to true if feature_gw_sp_perso is being passed */
  uint32_t feature_gw_sp_perso_len;  /**< Must be set to # of elements in feature_gw_sp_perso */
  uim_gw_sp_perso_type_v01 feature_gw_sp_perso[QMI_UIM_PERSO_NUM_GW_SP_MAX_V01];

  /* Optional */
  /*  GW Corporate Personalization */
  uint8_t feature_gw_corporate_perso_valid;  /**< Must be set to true if feature_gw_corporate_perso is being passed */
  uint32_t feature_gw_corporate_perso_len;  /**< Must be set to # of elements in feature_gw_corporate_perso */
  uim_gw_corporate_perso_type_v01 feature_gw_corporate_perso[QMI_UIM_PERSO_NUM_GW_CP_MAX_V01];

  /* Optional */
  /*  GW SIM Personalization */
  uint8_t feature_gw_sim_perso_valid;  /**< Must be set to true if feature_gw_sim_perso is being passed */
  uint32_t feature_gw_sim_perso_len;  /**< Must be set to # of elements in feature_gw_sim_perso */
  uim_sim_perso_type_v01 feature_gw_sim_perso[QMI_UIM_PERSO_NUM_SIM_MAX_V01];

  /* Optional */
  /*  1X Network Type 1 Personalization */
  uint8_t feature_1x_network1_perso_valid;  /**< Must be set to true if feature_1x_network1_perso is being passed */
  uint32_t feature_1x_network1_perso_len;  /**< Must be set to # of elements in feature_1x_network1_perso */
  uim_network_perso_type_v01 feature_1x_network1_perso[QMI_UIM_PERSO_NUM_NW_MAX_V01];

  /* Optional */
  /*  1X Network Type 2 Personalization */
  uint8_t feature_1x_network2_perso_valid;  /**< Must be set to true if feature_1x_network2_perso is being passed */
  uint32_t feature_1x_network2_perso_len;  /**< Must be set to # of elements in feature_1x_network2_perso */
  uim_1x_network_type2_perso_type_v01 feature_1x_network2_perso[QMI_UIM_PERSO_NUM_1X_NW2_MAX_V01];

  /* Optional */
  /*  1X RUIM Personalization */
  uint8_t feature_1x_ruim_perso_valid;  /**< Must be set to true if feature_1x_ruim_perso is being passed */
  uint32_t feature_1x_ruim_perso_len;  /**< Must be set to # of elements in feature_1x_ruim_perso */
  uim_sim_perso_type_v01 feature_1x_ruim_perso[QMI_UIM_PERSO_NUM_SIM_MAX_V01];

  /* Optional */
  /*  Slot */
  uint8_t slot_valid;  /**< Must be set to true if slot is being passed */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot to be used. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Optional */
  /*  Number of Iterations */
  uint8_t num_iterations_valid;  /**< Must be set to true if num_iterations is being passed */
  uint32_t num_iterations;
  /**<   The number of iterations to be used in the personalization algorithm.
  */

  /* Optional */
  /*  Number of Retries */
  uint8_t num_retries_valid;  /**< Must be set to true if num_retries is being passed */
  uint32_t num_retries;
  /**<   The number of retries allowed for depersonalization.
       Setting the value to 0 allows unlimited retries.
  */

  /* Optional */
  /*  Reactivate Personalization Feature */
  uint8_t reactivate_feature_valid;  /**< Must be set to true if reactivate_feature is being passed */
  uim_perso_feature_enum_v01 reactivate_feature;
  /**<   Indicates the personalization feature to reactivate.
 Valid values:\n
      - UIM_PERSO_FEATURE_GW_NETWORK (0x00) --  GW network personalization \n
      - UIM_PERSO_FEATURE_GW_NETWORK_SUBSET (0x01) --  GW network subset personalization \n
      - UIM_PERSO_FEATURE_GW_SERVICE_PROVIDER (0x02) --  GW service provider personalization \n
      - UIM_PERSO_FEATURE_GW_CORPORATE (0x03) --  GW corporate personalization \n
      - UIM_PERSO_FEATURE_GW_UIM (0x04) --  GW UIM personalization \n
      - UIM_PERSO_FEATURE_1X_NETWORK_TYPE_1 (0x05) --  1X network type 1 personalization \n
      - UIM_PERSO_FEATURE_1X_NETWORK_TYPE_2 (0x06) --  1X network type 2 personalization \n
      - UIM_PERSO_FEATURE_1X_HRPD (0x07) --  1X HRPD personalization \n
      - UIM_PERSO_FEATURE_1X_SERVICE_PROVIDER (0x08) --  1X service provider personalization \n
      - UIM_PERSO_FEATURE_1X_CORPORATE (0x09) --  1X corporate personalization \n
      - UIM_PERSO_FEATURE_1X_RUIM (0x0A) --  1X RUIM personalization \n
      - UIM_PERSO_FEATURE_GW_SPN (0x0B) --  GW SPN personalization \n
      - UIM_PERSO_FEATURE_GW_SP_EHPLMN (0x0C) --  GW SP + EHPLMN personalization \n
      - UIM_PERSO_FEATURE_GW_ICCID (0x0D) --  GW ICCID personalization \n
      - UIM_PERSO_FEATURE_GW_IMPI (0x0E) --  GW IMPI personalization \n
      - UIM_PERSO_FEATURE_GW_NETWORK_SUBSET_SERVICE_PROVIDER (0x0F) --  GW network subset and service provider personalization
 \n
 Other values are reserved for future use and are to be ignored by
 the client.
 */

  /* Optional */
  /*  Reuse Personalization Code for Feature */
  uint8_t reuse_code_for_feature_valid;  /**< Must be set to true if reuse_code_for_feature is being passed */
  uim_perso_feature_enum_v01 reuse_code_for_feature;
  /**<   Indicates the personalization feature for which code data is reused.
 Valid values:\n
      - UIM_PERSO_FEATURE_GW_NETWORK (0x00) --  GW network personalization \n
      - UIM_PERSO_FEATURE_GW_NETWORK_SUBSET (0x01) --  GW network subset personalization \n
      - UIM_PERSO_FEATURE_GW_SERVICE_PROVIDER (0x02) --  GW service provider personalization \n
      - UIM_PERSO_FEATURE_GW_CORPORATE (0x03) --  GW corporate personalization \n
      - UIM_PERSO_FEATURE_GW_UIM (0x04) --  GW UIM personalization \n
      - UIM_PERSO_FEATURE_1X_NETWORK_TYPE_1 (0x05) --  1X network type 1 personalization \n
      - UIM_PERSO_FEATURE_1X_NETWORK_TYPE_2 (0x06) --  1X network type 2 personalization \n
      - UIM_PERSO_FEATURE_1X_HRPD (0x07) --  1X HRPD personalization \n
      - UIM_PERSO_FEATURE_1X_SERVICE_PROVIDER (0x08) --  1X service provider personalization \n
      - UIM_PERSO_FEATURE_1X_CORPORATE (0x09) --  1X corporate personalization \n
      - UIM_PERSO_FEATURE_1X_RUIM (0x0A) --  1X RUIM personalization \n
      - UIM_PERSO_FEATURE_GW_SPN (0x0B) --  GW SPN personalization \n
      - UIM_PERSO_FEATURE_GW_SP_EHPLMN (0x0C) --  GW SP + EHPLMN personalization \n
      - UIM_PERSO_FEATURE_GW_ICCID (0x0D) --  GW ICCID personalization \n
      - UIM_PERSO_FEATURE_GW_IMPI (0x0E) --  GW IMPI personalization \n
      - UIM_PERSO_FEATURE_GW_NETWORK_SUBSET_SERVICE_PROVIDER (0x0F) --  GW network subset and service provider personalization
 \n
 Other values are reserved for future use and are to be ignored by
 the client.
 */

  /* Optional */
  /*  GW Service Provider Personalization with Multi-byte GID */
  uint8_t feature_gw_sp_ext_perso_valid;  /**< Must be set to true if feature_gw_sp_ext_perso is being passed */
  uint32_t feature_gw_sp_ext_perso_len;  /**< Must be set to # of elements in feature_gw_sp_ext_perso */
  uim_gw_sp_ext_perso_type_v01 feature_gw_sp_ext_perso[QMI_UIM_PERSO_NUM_GW_SP_MAX_V01];

  /* Optional */
  /*  GW Corporate Provider Personalization with Multi-byte GID */
  uint8_t feature_gw_corporate_ext_perso_valid;  /**< Must be set to true if feature_gw_corporate_ext_perso is being passed */
  uint32_t feature_gw_corporate_ext_perso_len;  /**< Must be set to # of elements in feature_gw_corporate_ext_perso */
  uim_gw_corporate_ext_perso_type_v01 feature_gw_corporate_ext_perso[QMI_UIM_PERSO_NUM_GW_CP_MAX_V01];

  /* Optional */
  /*  GW Service Provider Name Personalization */
  uint8_t feature_gw_spn_perso_valid;  /**< Must be set to true if feature_gw_spn_perso is being passed */
  uint32_t feature_gw_spn_perso_len;  /**< Must be set to # of elements in feature_gw_spn_perso */
  uim_gw_spn_perso_type_v01 feature_gw_spn_perso[QMI_UIM_PERSO_NUM_GW_SPN_MAX_V01];

  /* Optional */
  /*  GW Service Provider Personalization with 8 bytes GID */
  uint8_t feature_gw_sp_ext_v4_perso_valid;  /**< Must be set to true if feature_gw_sp_ext_v4_perso is being passed */
  uint32_t feature_gw_sp_ext_v4_perso_len;  /**< Must be set to # of elements in feature_gw_sp_ext_v4_perso */
  uim_gw_sp_ext2_perso_type_v01 feature_gw_sp_ext_v4_perso[QMI_UIM_PERSO_NUM_GW_SP_MAX_V01];

  /* Optional */
  /*  GW Corporate Provider Personalization with 8 bytes GID */
  uint8_t feature_gw_corporate_ext_v4_perso_valid;  /**< Must be set to true if feature_gw_corporate_ext_v4_perso is being passed */
  uint32_t feature_gw_corporate_ext_v4_perso_len;  /**< Must be set to # of elements in feature_gw_corporate_ext_v4_perso */
  uim_gw_corporate_ext2_perso_type_v01 feature_gw_corporate_ext_v4_perso[QMI_UIM_PERSO_NUM_GW_CP_MAX_V01];

  /* Optional */
  /*  GW Service Provider with Equivalent HPLMN Personalization */
  uint8_t feature_gw_sp_ehplmn_perso_valid;  /**< Must be set to true if feature_gw_sp_ehplmn_perso is being passed */
  uint32_t feature_gw_sp_ehplmn_perso_len;  /**< Must be set to # of elements in feature_gw_sp_ehplmn_perso */
  uim_gw_sp_ehplmn_perso_type_v01 feature_gw_sp_ehplmn_perso[QMI_UIM_PERSO_NUM_GW_SP_MAX_V01];

  /* Optional */
  /*  GW ICCID Personalization */
  uint8_t feature_gw_iccid_perso_valid;  /**< Must be set to true if feature_gw_iccid_perso is being passed */
  uint32_t feature_gw_iccid_perso_len;  /**< Must be set to # of elements in feature_gw_iccid_perso */
  uim_gw_iccid_perso_type_v01 feature_gw_iccid_perso[QMI_UIM_PERSO_NUM_GW_ICCID_MAX_V01];
}uim_personalization_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Activates and sets the personalization data on the phone. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Retries Remaining */
  uint8_t retries_left_valid;  /**< Must be set to true if retries_left is being passed */
  uim_perso_retries_left_type_v01 retries_left;
  /**<   \n
       This value is returned only when re-activating the personalization
       feature.
  */
}uim_personalization_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Performs an increase operation for any file on the card and
             provides access by the path. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  File ID */
  uim_file_id_type_v01 file_id;

  /* Mandatory */
  /*  Value to be Added */
  uint32_t increase_data_len;  /**< Must be set to # of elements in increase_data */
  uint8_t increase_data[QMI_UIM_INCREASE_DATA_MAX_V01];
  /**<   Increase data.
  */

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result must be provided
       in a subsequent indication.
  */
}uim_increase_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Performs an increase operation for any file on the card and
             provides access by the path. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;

  /* Optional */
  /*  Value of Increase Record */
  uint8_t increase_result_valid;  /**< Must be set to true if increase_result is being passed */
  uint32_t increase_result_len;  /**< Must be set to # of elements in increase_result */
  uint8_t increase_result[QMI_UIM_INCREASE_DATA_MAX_V01];
  /**<   Value of the increased record result and the value that has been added.
  */

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result is provided
       in a subsequent indication.
  */
}uim_increase_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indicates the clients with an increase confirmation. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Mandatory */
  /*  Token of the Original Request */
  uint32_t indication_token;
  /**<   Indicates the token of the original request.
  */

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;

  /* Optional */
  /*  Value of Increase Record */
  uint8_t increase_result_valid;  /**< Must be set to true if increase_result is being passed */
  uint32_t increase_result_len;  /**< Must be set to # of elements in increase_result */
  uint8_t increase_result[QMI_UIM_INCREASE_DATA_MAX_V01];
  /**<   Value of the increased record result and the value that has been added.
  */
}uim_increase_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Performs recovery on an identified slot. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot to be used. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */
}uim_recovery_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Performs recovery on an identified slot. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_recovery_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_SELECT_MODE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_SELECT_MODE_FIRST_OR_ONLY_V01 = 0x00, /**<  First or only occurrence of the AID \n  */
  UIM_SELECT_MODE_LAST_V01 = 0x01, /**<  Last occurrence of the AID \n  */
  UIM_SELECT_MODE_NEXT_V01 = 0x02, /**<  Next occurrence of the AID \n  */
  UIM_SELECT_MODE_PREVIOUS_V01 = 0x03, /**<  Previous occurrence of the AID  */
  UIM_SELECT_MODE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_select_mode_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Performs a SELECT of an application on the specified logical channel. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot to be used. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Mandatory */
  /*  Channel ID */
  uint8_t channel_id;
  /**<   ID of the logical channel on which to perform the SELECT.*/

  /* Mandatory */
  /*  Selection Mode */
  uim_select_mode_enum_v01 select_mode;
  /**<   SELECT command mode. Valid values:\n
      - UIM_SELECT_MODE_FIRST_OR_ONLY (0x00) --  First or only occurrence of the AID \n
      - UIM_SELECT_MODE_LAST (0x01) --  Last occurrence of the AID \n
      - UIM_SELECT_MODE_NEXT (0x02) --  Next occurrence of the AID \n
      - UIM_SELECT_MODE_PREVIOUS (0x03) --  Previous occurrence of the AID
 */
}uim_reselect_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Performs a SELECT of an application on the specified logical channel. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;

  /* Optional */
  /*  Response to SELECT */
  uint8_t select_response_valid;  /**< Must be set to true if select_response is being passed */
  uint32_t select_response_len;  /**< Must be set to # of elements in select_response */
  uint8_t select_response[QMI_UIM_SELECT_RESPONSE_MAX_V01];
  /**<   Raw value of the response sent by the card to the SELECT command.
       This is for responses of size less than or equal to 255 bytes.
  */

  /* Optional */
  /*  Long Response to SELECT */
  uint8_t long_select_response_valid;  /**< Must be set to true if long_select_response is being passed */
  uint32_t long_select_response_len;  /**< Must be set to # of elements in long_select_response */
  uint8_t long_select_response[QMI_UIM_LONG_SELECT_RESPONSE_MAX_V01];
  /**<   Raw value of the response sent by the card to the SELECT command.
       This is for responses of size greater than 255 bytes.
  */
}uim_reselect_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indicates that a SIM recovery completed successfully. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the recovered slot. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */
}uim_recovery_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_STATUS_CMD_MODE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_STATUS_CMD_NO_INDICATION_V01 = 0x00, /**<  No indication \n  */
  UIM_STATUS_CMD_APP_INITIALIZED_V01 = 0x01, /**<  Current application is initialized in the terminal \n  */
  UIM_STATUS_CMD_WILL_TERMNATE_APP_V01 = 0x02, /**<  Terminal initiates the termination of the current application  */
  UIM_STATUS_CMD_MODE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_status_cmd_mode_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_STATUS_CMD_RESP_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_STATUS_CMD_FCP_RESP_V01 = 0x00, /**<  Response is identical to the SELECT command, i.e., FCP \n  */
  UIM_STATUS_CMD_AID_RESP_V01 = 0x01, /**<  DF name TLV-object (AID) of the current application is returned \n  */
  UIM_STATUS_CMD_NO_DATA_RESP_V01 = 0x02, /**<  No data is returned  */
  UIM_STATUS_CMD_RESP_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_status_cmd_resp_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Sends a STATUS command. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Optional */
  /*  Status Command Mode */
  uint8_t status_cmd_mode_valid;  /**< Must be set to true if status_cmd_mode is being passed */
  uim_status_cmd_mode_enum_v01 status_cmd_mode;
  /**<   Mode for the STATUS command. Valid values:\n
      - UIM_STATUS_CMD_NO_INDICATION (0x00) --  No indication \n
      - UIM_STATUS_CMD_APP_INITIALIZED (0x01) --  Current application is initialized in the terminal \n
      - UIM_STATUS_CMD_WILL_TERMNATE_APP (0x02) --  Terminal initiates the termination of the current application

 \vspace{3pt}
 This value defaults to UIM_STATUS_CMD_NO_INDICATION if the TLV is missing.
 */

  /* Optional */
  /*  Response Requested */
  uint8_t status_cmd_resp_valid;  /**< Must be set to true if status_cmd_resp is being passed */
  uim_status_cmd_resp_enum_v01 status_cmd_resp;
  /**<   Response required for the STATUS command. Valid values:\n
      - UIM_STATUS_CMD_FCP_RESP (0x00) --  Response is identical to the SELECT command, i.e., FCP \n
      - UIM_STATUS_CMD_AID_RESP (0x01) --  DF name TLV-object (AID) of the current application is returned \n
      - UIM_STATUS_CMD_NO_DATA_RESP (0x02) --  No data is returned

 \vspace{3pt}
 This value defaults to UIM_STATUS_CMD_NO_DATA_RESP if the TLV is missing.
 */
}uim_send_status_cmd_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Sends a STATUS command. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  STATUS Response */
  uint8_t status_response_valid;  /**< Must be set to true if status_response is being passed */
  uint32_t status_response_len;  /**< Must be set to # of elements in status_response */
  uint8_t status_response[QMI_UIM_SELECT_RESPONSE_MAX_V01];
  /**<   Depending on the parameters in the request, this value is either
       identical to the SELECT command response with size less than 256 bytes
       or it is the AID.
  */

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;

  /* Optional */
  /*  Long STATUS Response */
  uint8_t long_status_response_valid;  /**< Must be set to true if long_status_response is being passed */
  uint32_t long_status_response_len;  /**< Must be set to # of elements in long_status_response */
  uint8_t long_status_response[QMI_UIM_LONG_SELECT_RESPONSE_MAX_V01];
  /**<   Raw value of the response sent by the card to the SELECT command.
       This is for responses of size greater than 255 bytes.
  */
}uim_send_status_cmd_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Queries the profile information from the card. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the recovered slot. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */
}uim_get_sim_profile_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_PROFILE_ID_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_PROFILE_ID_1_V01 = 0x01, /**<   \n Profile 1 \n  */
  UIM_PROFILE_ID_2_V01 = 0x02, /**<   \n Profile 2 \n  */
  UIM_PROFILE_ID_3_V01 = 0x03, /**<   \n Profile 3 \n  */
  UIM_PROFILE_ID_4_V01 = 0x04, /**<   \n Profile 4 \n  */
  UIM_PROFILE_ID_5_V01 = 0x05, /**<   \n Profile 5 \n  */
  UIM_PROFILE_ID_6_V01 = 0x06, /**<  \n Profile 6 \n  */
  UIM_PROFILE_ID_7_V01 = 0x07, /**<  \n Profile 7 \n  */
  UIM_PROFILE_ID_8_V01 = 0x08, /**<  \n Profile 8  */
  UIM_PROFILE_ID_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_profile_id_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_PROFILE_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_PROFILE_TYPE_REGULAR_V01 = 0x00, /**<  Regular \n */
  UIM_PROFILE_TYPE_EMERGENCY_V01 = 0x01, /**<  Emergency  */
  UIM_PROFILE_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_profile_type_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_profile_id_enum_v01 profile_id;
  /**<   Indicates the profile ID of the card. Valid values: \n
      - UIM_PROFILE_ID_1 (0x01) --   \n Profile 1 \n
      - UIM_PROFILE_ID_2 (0x02) --   \n Profile 2 \n
      - UIM_PROFILE_ID_3 (0x03) --   \n Profile 3 \n
      - UIM_PROFILE_ID_4 (0x04) --   \n Profile 4 \n
      - UIM_PROFILE_ID_5 (0x05) --   \n Profile 5 \n
      - UIM_PROFILE_ID_6 (0x06) --  \n Profile 6 \n
      - UIM_PROFILE_ID_7 (0x07) --  \n Profile 7 \n
      - UIM_PROFILE_ID_8 (0x08) --  \n Profile 8
 */

  uim_profile_type_enum_v01 profile_type;
  /**<   Indicates the profile type of the card. Valid values: \n
      - UIM_PROFILE_TYPE_REGULAR (0x00) --  Regular \n
      - UIM_PROFILE_TYPE_EMERGENCY (0x01) --  Emergency
 */
}profile_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Queries the profile information from the card. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members: \n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE. \n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Profile information */
  uint8_t profile_info_valid;  /**< Must be set to true if profile_info is being passed */
  uint32_t profile_info_len;  /**< Must be set to # of elements in profile_info */
  profile_info_type_v01 profile_info[QMI_UIM_PROFILES_MAX_V01];

  /* Optional */
  /*  Present active profile information */
  uint8_t active_profile_info_valid;  /**< Must be set to true if active_profile_info is being passed */
  profile_info_type_v01 active_profile_info;
}uim_get_sim_profile_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Switches the profile on the SIM card. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the recovered slot. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Mandatory */
  /*  Profile ID */
  uim_profile_id_enum_v01 profile_id;
  /**<   Indicates the profile ID to switch. Valid values:\n
      - UIM_PROFILE_ID_1 (0x01) --   \n Profile 1 \n
      - UIM_PROFILE_ID_2 (0x02) --   \n Profile 2 \n
      - UIM_PROFILE_ID_3 (0x03) --   \n Profile 3 \n
      - UIM_PROFILE_ID_4 (0x04) --   \n Profile 4 \n
      - UIM_PROFILE_ID_5 (0x05) --   \n Profile 5 \n
      - UIM_PROFILE_ID_6 (0x06) --  \n Profile 6 \n
      - UIM_PROFILE_ID_7 (0x07) --  \n Profile 7 \n
      - UIM_PROFILE_ID_8 (0x08) --  \n Profile 8
 */

  /* Optional */
  /*  Enable/Disable Profile */
  uint8_t enable_profile_valid;  /**< Must be set to true if enable_profile is being passed */
  uint8_t enable_profile;
  /**<   Indicates whether a profile must be enabled or disabled.
       If the TLV is missing, the request is used to enable the profile. \n
       Valid values: \n
       - 0 -- Disable the profile \n
       - 1 -- Enable the profile
  */
}uim_set_sim_profile_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Switches the profile on the SIM card. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_set_sim_profile_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Informs the modem to proceed with the supply voltage Vcc deactivation. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot where the supply voltage Vcc is to be deactivated. Valid
 values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */
}uim_supply_voltage_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Informs the modem to proceed with the supply voltage Vcc deactivation. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message definition.
  */
}uim_supply_voltage_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_VCC_COMMAND_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_SUPPLY_VOLTAGE_ACTIVATE_V01 = 0x00, /**<  Supply voltage Vcc is activated \n  */
  UIM_SUPPLY_VOLTAGE_DEACTIVATE_V01 = 0x01, /**<  Supply voltage Vcc must be deactivated \n  */
  UIM_VCC_COMMAND_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_vcc_command_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indicates that the modem must deactivate or activate the supply
             voltage Vcc line of the UICC. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot where the supply voltage Vcc line must be activated
 or deactivated.
 Valid values: \n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Mandatory */
  /*  Vcc Command Type */
  uim_vcc_command_enum_v01 vcc_command;
  /**<   Indicates whether supply voltage Vcc is to be deactivated or activated.
 Valid values:\n
      - UIM_SUPPLY_VOLTAGE_ACTIVATE (0x00) --  Supply voltage Vcc is activated \n
      - UIM_SUPPLY_VOLTAGE_DEACTIVATE (0x01) --  Supply voltage Vcc must be deactivated \n
 */
}uim_supply_voltage_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  CARD_ACTIVATION_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  CARD_ACTIVATION_START_V01 = 0x00, /**<  Card activation started\n  */
  CARD_ACTIVATION_END_WITH_SUCCESS_V01 = 0x01, /**<  Card activation ended successfully\n  */
  CARD_ACTIVATION_END_WITH_FAILURE_V01 = 0x02, /**<  Card activation failed\n  */
  CARD_ACTIVATION_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}card_activation_status_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indicates the card activation status. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot where card activation has started or ended.
 Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Mandatory */
  /*  Card Activation Status */
  card_activation_status_enum_v01 card_activation_status;
  /**<   Indicates the card activation status on the corresponding slot.
 Valid values:\n
      - CARD_ACTIVATION_START (0x00) --  Card activation started\n
      - CARD_ACTIVATION_END_WITH_SUCCESS (0x01) --  Card activation ended successfully\n
      - CARD_ACTIVATION_END_WITH_FAILURE (0x02) --  Card activation failed\n
 */
}uim_card_activation_status_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Performs a temporary unlock or unlock without the control key. */
typedef struct {

  /* Mandatory */
  /*  Encrypted Depersonalization Request Data */
  uint32_t encrypted_depersonalization_data_len;  /**< Must be set to # of elements in encrypted_depersonalization_data */
  uint8_t encrypted_depersonalization_data[QMI_UIM_ENCRYPTED_REQUEST_MAX_V01];
  /**<   See Section \ref{sec:depersoSecPayload} for the request format. */
}uim_depersonalization_secure_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Performs a temporary unlock or unlock without the control key. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Encrypted Result Code */
  uint8_t encrypted_resp_valid;  /**< Must be set to true if encrypted_resp is being passed */
  uint32_t encrypted_resp_len;  /**< Must be set to # of elements in encrypted_resp */
  uint8_t encrypted_resp[QMI_UIM_ENCRYPTED_RESPONSE_MAX_V01];
  /**<   See Section \ref{sec:encryptResMsg} for the response format. */
}uim_depersonalization_secure_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Activates and locks the device to SimLock codes. */
typedef struct {

  /* Mandatory */
  /*  Encrypted Personalization Data */
  uint32_t encrypted_personalization_data_len;  /**< Must be set to # of elements in encrypted_personalization_data */
  uint8_t encrypted_personalization_data[QMI_UIM_ENCRYPTED_REQUEST_MAX_V01];
  /**<   See Section \ref{sec:persoSecPayload} for the request format. */
}uim_personalization_secure_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Activates and locks the device to SimLock codes. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Encrypted Result Code */
  uint8_t encrypted_resp_valid;  /**< Must be set to true if encrypted_resp is being passed */
  uint32_t encrypted_resp_len;  /**< Must be set to # of elements in encrypted_resp */
  uint8_t encrypted_resp[QMI_UIM_ENCRYPTED_RESPONSE_MAX_V01];
  /**<   See Section \ref{sec:encryptResMsg} for the response format. */
}uim_personalization_secure_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Sets the phone in Emergency Only mode. */
typedef struct {

  /* Mandatory */
  /*  Encrypted Emergency Only Request Data */
  uint32_t encrypted_emergency_data_len;  /**< Must be set to # of elements in encrypted_emergency_data */
  uint8_t encrypted_emergency_data[QMI_UIM_ENCRYPTED_REQUEST_MAX_V01];
  /**<   See Section \ref{sec:emrgncyReqPay} for the request format. */
}uim_emergency_only_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Sets the phone in Emergency Only mode. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Encrypted Result Code */
  uint8_t encrypted_resp_valid;  /**< Must be set to true if encrypted_resp is being passed */
  uint32_t encrypted_resp_len;  /**< Must be set to # of elements in encrypted_resp */
  uint8_t encrypted_resp[QMI_UIM_ENCRYPTED_RESPONSE_MAX_V01];
  /**<   See Section \ref{sec:encryptResMsg} for the response format. */
}uim_emergency_only_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Provides access to the SimLock configuration data. */
typedef struct {

  /* Mandatory */
  /*  Encrypted SimLock Configuration Request Data */
  uint32_t encrypted_simlock_config_data_len;  /**< Must be set to # of elements in encrypted_simlock_config_data */
  uint8_t encrypted_simlock_config_data[QMI_UIM_ENCRYPTED_REQUEST_MAX_V01];
  /**<   See Section \ref{sec:simConfigReq} for the request format. */
}uim_simlock_configuration_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Provides access to the SimLock configuration data. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Encrypted Result Code */
  uint8_t encrypted_resp_valid;  /**< Must be set to true if encrypted_resp is being passed */
  uint32_t encrypted_resp_len;  /**< Must be set to # of elements in encrypted_resp */
  uint8_t encrypted_resp[QMI_UIM_ENCRYPTED_RESPONSE_MAX_V01];
  /**<   See Section \ref{sec:encryptResMsg} for the response format. */
}uim_simlock_configuration_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indication with the SimLock configuration data access request. */
typedef struct {

  /* Mandatory */
  /*  Encrypted Value: SimLock Configuration Request */
  uint32_t encrypted_simlock_config_ind_len;  /**< Must be set to # of elements in encrypted_simlock_config_ind */
  uint8_t encrypted_simlock_config_ind[QMI_UIM_ENCRYPTED_REQUEST_MAX_V01];
  /**<   See Section \ref{sec:simConfigInd} for the indication format. */
}uim_simlock_configuration_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t fqdn_len;  /**< Must be set to # of elements in fqdn */
  char fqdn[QMI_UIM_FQDN_MAX_V01];
  /**<   FQDN of the NAF. */

  uint8_t security_protocol_id[QMI_UIM_SECURITY_PROTOCOL_LEN_V01];
  /**<   Identifies the security protocol of the bootstrapping application
       per \hyperref[3G33220]{3GPP TS 33.220} Annex H.
  */
}uim_naf_id_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_ADDRESS_PROTOCOL_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_ADDRESS_PROTOCOL_HTTP_V01 = 0x00, /**<  HTTP\n  */
  UIM_ADDRESS_PROTOCOL_HTTPS_V01 = 0x01, /**<  HTTPS\n  */
  UIM_ADDRESS_PROTOCOL_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_address_protocol_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_address_protocol_enum_v01 protocol;
  /**<   Protocol type for the BSF. */

  uint16_t port;
  /**<   Port number for the BSF. */

  uint32_t address_len;  /**< Must be set to # of elements in address */
  char address[QMI_UIM_FQDN_MAX_V01];
  /**<   Identifies the address of the bootstrapping server function. */
}uim_bsf_information_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Initializes the GBA and generates a key that is shared with a NAF. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  NAF ID */
  uim_naf_id_type_v01 naf_id;

  /* Optional */
  /*  Force Bootstrapping */
  uint8_t force_bootstrapping_valid;  /**< Must be set to true if force_bootstrapping is being passed */
  uint8_t force_bootstrapping;
  /**<   Indicates whether bootstrapping is required even if the key is still valid.
       Valid values: \n
       - 0 -- Do not force bootstrap and reuse Ks if it is still valid \n
       - 1 -- Force bootstrapping even if the Ks is still valid
  */

  /* Optional */
  /*  Indication Token */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result must be provided
       in a subsequent indication.
  */

  /* Optional */
  /*  APN Name */
  uint8_t apn_name_valid;  /**< Must be set to true if apn_name is being passed */
  uint32_t apn_name_len;  /**< Must be set to # of elements in apn_name */
  char apn_name[QMI_UIM_APN_NAME_MAX_V01];
  /**<   Identifies the APN name required for bootstrapping.
  */

  /* Optional */
  /*  BSF Information */
  uint8_t bsf_information_valid;  /**< Must be set to true if bsf_information is being passed */
  uim_bsf_information_type_v01 bsf_information;
  /**<   \n
       Identifies the BSF information required for bootstrapping. If this TLV is
       absent, the default BSF address derived from IMPI is used.
  */

  /* Optional */
  /*  Register for Key Status Indication */
  uint8_t key_status_ind_reg_valid;  /**< Must be set to true if key_status_ind_reg is being passed */
  uint8_t key_status_ind_reg;
  /**<   Indicates whether the client is to receive key status indications.
       Valid values: \n
       - 0 -- Do not register for key status indications (Default)\n
       - 1 -- Register for key status indications
  */
}uim_gba_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Initializes the GBA and generates a key that is shared with a NAF. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Ks(_ext)_NAF */
  uint8_t ks_naf_valid;  /**< Must be set to true if ks_naf is being passed */
  uint8_t ks_naf[QMI_UIM_KS_NAF_LEN_V01];
  /**<   Key shared between the NAF and the UE. Derivation of the key
       is specified in \hyperref[3G33220]{3GPP TS 33.220}.
  */

  /* Optional */
  /*  Encrypted Ks(_ext)_NAF */
  uint8_t encrypted_ks_naf_valid;  /**< Must be set to true if encrypted_ks_naf is being passed */
  uint32_t encrypted_ks_naf_len;  /**< Must be set to # of elements in encrypted_ks_naf */
  uint8_t encrypted_ks_naf[QMI_UIM_ENCRYPTED_KS_NAF_MAX_V01];
  /**<   Encrypted value of Ks(_ext)_NAF, as specified in \hyperref[3G33220]{3GPP TS 33.220}. */

  /* Optional */
  /*  Bootstrapping Transaction ID */
  uint8_t btid_valid;  /**< Must be set to true if btid is being passed */
  uint32_t btid_len;  /**< Must be set to # of elements in btid */
  char btid[QMI_UIM_BTID_MAX_V01];
  /**<   ID that binds the subscriber identity to the keying material.
       For B-TID formatting, refer to \hyperref[3G33220]{3GPP TS 33.220}.
  */

  /* Optional */
  /*  Key material lifetime */
  uint8_t lifetime_valid;  /**< Must be set to true if lifetime is being passed */
  uint32_t lifetime_len;  /**< Must be set to # of elements in lifetime */
  char lifetime[QMI_UIM_KS_LIFETIME_MAX_V01];
  /**<   Lifetime of the BSF-generated key material. The lifetime is expressed
       in UTC format with the trailing character indicating the timezone.
       For time formatting, refer to \hyperref[ISO8601]{ISO 8601}.
  */

  /* Optional */
  /*  IMPI */
  uint8_t impi_valid;  /**< Must be set to true if impi is being passed */
  uint32_t impi_len;  /**< Must be set to # of elements in impi */
  char impi[QMI_UIM_IMPI_MAX_V01];
  /**<   Private user identity used for the GBA procedure specified in \hyperref[3G33220]{3GPP TS 33.220}.*/

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result is provided
       in a subsequent indication.
  */
}uim_gba_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Delayed response indication containing status and shared key related information. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Mandatory */
  /*  Token of the Original Request */
  uint32_t indication_token;
  /**<   Indicates the token of the original request.*/

  /* Optional */
  /*  Ks(_ext)_NAF */
  uint8_t ks_naf_valid;  /**< Must be set to true if ks_naf is being passed */
  uint8_t ks_naf[QMI_UIM_KS_NAF_LEN_V01];
  /**<   Key shared between the NAF and the ME. Key derivation is specified in
       \hyperref[3G33220]{3GPP TS 33.220}.
  */

  /* Optional */
  /*  Encrypted Ks(_ext)_NAF */
  uint8_t encrypted_ks_naf_valid;  /**< Must be set to true if encrypted_ks_naf is being passed */
  uint32_t encrypted_ks_naf_len;  /**< Must be set to # of elements in encrypted_ks_naf */
  uint8_t encrypted_ks_naf[QMI_UIM_ENCRYPTED_KS_NAF_MAX_V01];
  /**<   Encrypted value of Ks(_ext)_NAF, as specified in
       \hyperref[3G33220]{3GPP TS 33.220}.
  */

  /* Optional */
  /*  Bootstrapping Transaction ID */
  uint8_t btid_valid;  /**< Must be set to true if btid is being passed */
  uint32_t btid_len;  /**< Must be set to # of elements in btid */
  char btid[QMI_UIM_BTID_MAX_V01];
  /**<   ID that binds the subscriber identity to the keying material.
       For B-TID formatting, refer to \hyperref[3G33220]{3GPP TS 33.220}.
  */

  /* Optional */
  /*  Key material lifetime */
  uint8_t lifetime_valid;  /**< Must be set to true if lifetime is being passed */
  uint32_t lifetime_len;  /**< Must be set to # of elements in lifetime */
  char lifetime[QMI_UIM_KS_LIFETIME_MAX_V01];
  /**<   The lifetime of the BSF-generated key material. Lifetime is expressed
       in UTC form with the trailing character indicating the timezone.
       For time formatting, refer to \hyperref[ISO8601]{ISO 8601}.
  */

  /* Optional */
  /*  IMPI */
  uint8_t impi_valid;  /**< Must be set to true if impi is being passed */
  uint32_t impi_len;  /**< Must be set to # of elements in impi */
  char impi[QMI_UIM_IMPI_MAX_V01];
  /**<   Private user identity used for the GBA procedure specified in \hyperref[3G33220]{3GPP TS 33.220}.*/
}uim_gba_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Retrieves the IMPI used for the GBA corresponding to the session. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Optional */
  /*  Encrypt Data */
  uint8_t encrypt_data_valid;  /**< Must be set to true if encrypt_data is being passed */
  uint8_t encrypt_data;
  /**<   Indicates whether the data read from the card is to be encrypted.*/
}uim_get_gba_impi_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Retrieves the IMPI used for the GBA corresponding to the session. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message definition.
  */

  /* Optional */
  /*  IMPI */
  uint8_t impi_valid;  /**< Must be set to true if impi is being passed */
  uint32_t impi_len;  /**< Must be set to # of elements in impi */
  char impi[QMI_UIM_IMPI_MAX_V01];
  /**<   Private user identity used for the GBA procedure specified in \hyperref[3G33220]{3GPP TS 33.220}.*/

  /* Optional */
  /*  Encrypted IMPI */
  uint8_t encrypted_impi_valid;  /**< Must be set to true if encrypted_impi is being passed */
  uint32_t encrypted_impi_len;  /**< Must be set to # of elements in encrypted_impi */
  uint8_t encrypted_impi[QMI_UIM_ENCRYPTED_IMPI_MAX_V01];
  /**<   Encrypted version of the IMPI.*/
}uim_get_gba_impi_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_SEARCH_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_SEARCH_FORWARD_V01 = 0x00, /**<  Forward search (default if the TLV is not present)\n  */
  UIM_SEARCH_BACKWARD_V01 = 0x01, /**<  Backward search  */
  UIM_SEARCH_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_search_type_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_search_type_enum_v01 search_type;
  /**<   Indicates the direction in which the pattern search starts from record.
 Valid values:\n
      - UIM_SEARCH_FORWARD (0x00) --  Forward search (default if the TLV is not present)\n
      - UIM_SEARCH_BACKWARD (0x01) --  Backward search
 \n
 Other values are reserved for future use.
 */

  uint8_t first_record;
  /**<   First record number in the search. The default value is 1 if the TLV is not
       present.
  */
}uim_additional_search_data_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Provides access to search for records in the card using a given pattern. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  File ID */
  uim_file_id_type_v01 file_id;

  /* Mandatory */
  /*  Search Pattern */
  uint32_t pattern_len;  /**< Must be set to # of elements in pattern */
  uint8_t pattern[QMI_UIM_CONTENT_RECORD_MAX_V01];
  /**<   Pattern used to search a file for all possible records.*/

  /* Optional */
  /*  Search Data */
  uint8_t search_data_valid;  /**< Must be set to true if search_data is being passed */
  uim_additional_search_data_type_v01 search_data;
  /**<   \n
       When this TLV is absent, use default values for search_type
       and first_record.
  */

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result must be provided
       in a subsequent indication.
  */
}uim_search_record_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Provides access to search for records in the card using a given pattern. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;

  /* Optional */
  /*  Search Result */
  uint8_t records_valid;  /**< Must be set to true if records is being passed */
  uint32_t records_len;  /**< Must be set to # of elements in records */
  uint8_t records[QMI_UIM_NUM_RECORD_MAX_V01];
  /**<   List of the number of records matching the pattern provided in the request.
  */

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result is provided
       in a subsequent indication.
  */
}uim_search_record_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indication with a search record command result. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Mandatory */
  /*  Token of the Original Request */
  uint32_t indication_token;
  /**<   Indicates the token of the original request.*/

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;

  /* Optional */
  /*  Search Result */
  uint8_t records_valid;  /**< Must be set to true if records is being passed */
  uint32_t records_len;  /**< Must be set to # of elements in records */
  uint8_t records[QMI_UIM_NUM_RECORD_MAX_V01];
  /**<   List of the number of records matching the pattern given in the request.
  */
}uim_search_record_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_REMOTE_UNLOCK_OPERATION_TYPE_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_REMOTE_UNLOCK_RETRIEVE_ENCRYPTED_KEY_V01 = 0x00, /**<  Return encrypted key  */
  UIM_REMOTE_UNLOCK_PROCESS_SIMLOCK_DATA_V01 = 0x01, /**<  Perform remote lock/unlock using the SimLock data  */
  UIM_REMOTE_UNLOCK_GENERATE_MAC_V01 = 0x02, /**<  Generate HMAC on the SimLock data  */
  UIM_REMOTE_UNLOCK_GET_MAX_SUPPORTED_VERSION_V01 = 0x03, /**<  Retrieve the highest major and minor version of the incoming blob supported
       by SimLock  */
  UIM_REMOTE_UNLOCK_BLOB_REQUEST_V01 = 0x04, /**<  Generate SimLock blob request  */
  UIM_REMOTE_UNLOCK_START_DELAY_TIMER_V01 = 0x05, /**<  Trigger to start delay timer by the SimLock  */
  UIM_REMOTE_UNLOCK_STOP_DELAY_TIMER_V01 = 0x06, /**<  Trigger to stop delay timer by the SimLock  */
  UIM_REMOTE_UNLOCK_OPERATION_TYPE_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_remote_unlock_operation_type_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Performs operations related to remote unlock. */
typedef struct {

  /* Optional */
  /*  SimLock Data */
  uint8_t simlock_data_valid;  /**< Must be set to true if simlock_data is being passed */
  uint32_t simlock_data_len;  /**< Must be set to # of elements in simlock_data */
  uint8_t simlock_data[QMI_UIM_SIMLOCK_DATA_MAX_V01];
  /**<   SimLock data used when data is less than or equal to 1024 bytes*/

  /* Optional */
  /*  Remote Unlock Operation */
  uint8_t operation_valid;  /**< Must be set to true if operation is being passed */
  uim_remote_unlock_operation_type_enum_v01 operation;
  /**<   Indicates the operation to be performed. Valid values:\n
      - UIM_REMOTE_UNLOCK_RETRIEVE_ENCRYPTED_KEY (0x00) --  Return encrypted key
      - UIM_REMOTE_UNLOCK_PROCESS_SIMLOCK_DATA (0x01) --  Perform remote lock/unlock using the SimLock data
      - UIM_REMOTE_UNLOCK_GENERATE_MAC (0x02) --  Generate HMAC on the SimLock data
      - UIM_REMOTE_UNLOCK_GET_MAX_SUPPORTED_VERSION (0x03) --  Retrieve the highest major and minor version of the incoming blob supported
       by SimLock
      - UIM_REMOTE_UNLOCK_BLOB_REQUEST (0x04) --  Generate SimLock blob request
      - UIM_REMOTE_UNLOCK_START_DELAY_TIMER (0x05) --  Trigger to start delay timer by the SimLock
      - UIM_REMOTE_UNLOCK_STOP_DELAY_TIMER (0x06) --  Trigger to stop delay timer by the SimLock  */

  /* Optional */
  /*  SimLock Extended Data */
  uint8_t simlock_data_ext_valid;  /**< Must be set to true if simlock_data_ext is being passed */
  uint32_t simlock_data_ext_len;  /**< Must be set to # of elements in simlock_data_ext */
  uint8_t simlock_data_ext[QMI_UIM_SIMLOCK_DATA_EXT_MAX_V01];
  /**<   SimLock Extended data used when data is greater than 1024 bytes*/
}uim_remote_unlock_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t major_version;
  /**<   Highest major version of the blob that is supported by SimLock */

  uint8_t minor_version;
  /**<   Highest minor version of the blob that is supported by SimLock */
}uim_remote_unlock_version_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Performs operations related to remote unlock. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message definition.
  */

  /* Optional */
  /*  Encrypted Key */
  uint8_t encrypted_key_valid;  /**< Must be set to true if encrypted_key is being passed */
  uint32_t encrypted_key_len;  /**< Must be set to # of elements in encrypted_key */
  uint8_t encrypted_key[QMI_UIM_ENCRYPTED_KEY_MAX_V01];
  /**<   Encrypted value of the key.*/

  /* Optional */
  /*  SimLock Remote Lock/Unlock Response */
  uint8_t simlock_data_valid;  /**< Must be set to true if simlock_data is being passed */
  uint32_t simlock_data_len;  /**< Must be set to # of elements in simlock_data */
  uint8_t simlock_data[QMI_UIM_SIMLOCK_DATA_MAX_V01];
  /**<   Integrity protected response of the remote lock/unlock operation.*/

  /* Optional */
  /*  Generated HMAC */
  uint8_t hmac_data_valid;  /**< Must be set to true if hmac_data is being passed */
  uint32_t hmac_data_len;  /**< Must be set to # of elements in hmac_data */
  uint8_t hmac_data[QMI_UIM_HMAC_MAX_V01];
  /**<   HMAC generated on the input data.*/

  /* Optional */
  /*  Highest Major and Minor Version of Incoming Blob */
  uint8_t maximum_version_valid;  /**< Must be set to true if maximum_version is being passed */
  uim_remote_unlock_version_type_v01 maximum_version;
  /**<   \n Highest major and minor version of incoming blob that is supported by SimLock.*/

  /* Optional */
  /*  SimLock Blob request generated */
  uint8_t blob_request_valid;  /**< Must be set to true if blob_request is being passed */
  uint32_t blob_request_len;  /**< Must be set to # of elements in blob_request */
  uint8_t blob_request[QMI_UIM_SIMLOCK_DATA_MAX_V01];
  /**<   Blob request generated.*/

  /* Optional */
  /*  delay timer value in seconds */
  uint8_t delay_timer_value_valid;  /**< Must be set to true if delay_timer_value is being passed */
  uint16_t delay_timer_value;
}uim_remote_unlock_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Verifies whether a subscription related to IMSI is validated by SimLock. */
typedef struct {

  /* Optional */
  /*  IMSI */
  uint8_t imsi_valid;  /**< Must be set to true if imsi is being passed */
  uint32_t imsi_len;  /**< Must be set to # of elements in imsi */
  uint8_t imsi[QMI_UIM_IMSI_LEN_MAX_V01];
  /**<   Content of the IMSI, in the same format as it is stored in the SIM card.*/
}uim_verify_imsi_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Verifies whether a subscription related to IMSI is validated by SimLock. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message definition.
  */
}uim_verify_imsi_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_perso_feature_enum_v01 feature;
  /**<   Indicates the personalization feature
 Valid values: \n
      - UIM_PERSO_FEATURE_GW_NETWORK (0x00) --  GW network personalization \n
      - UIM_PERSO_FEATURE_GW_NETWORK_SUBSET (0x01) --  GW network subset personalization \n
      - UIM_PERSO_FEATURE_GW_SERVICE_PROVIDER (0x02) --  GW service provider personalization \n
      - UIM_PERSO_FEATURE_GW_CORPORATE (0x03) --  GW corporate personalization \n
      - UIM_PERSO_FEATURE_GW_UIM (0x04) --  GW UIM personalization \n
      - UIM_PERSO_FEATURE_1X_NETWORK_TYPE_1 (0x05) --  1X network type 1 personalization \n
      - UIM_PERSO_FEATURE_1X_NETWORK_TYPE_2 (0x06) --  1X network type 2 personalization \n
      - UIM_PERSO_FEATURE_1X_HRPD (0x07) --  1X HRPD personalization \n
      - UIM_PERSO_FEATURE_1X_SERVICE_PROVIDER (0x08) --  1X service provider personalization \n
      - UIM_PERSO_FEATURE_1X_CORPORATE (0x09) --  1X corporate personalization \n
      - UIM_PERSO_FEATURE_1X_RUIM (0x0A) --  1X RUIM personalization \n
      - UIM_PERSO_FEATURE_GW_SPN (0x0B) --  GW SPN personalization \n
      - UIM_PERSO_FEATURE_GW_SP_EHPLMN (0x0C) --  GW SP + EHPLMN personalization \n
      - UIM_PERSO_FEATURE_GW_ICCID (0x0D) --  GW ICCID personalization \n
      - UIM_PERSO_FEATURE_GW_IMPI (0x0E) --  GW IMPI personalization \n
      - UIM_PERSO_FEATURE_GW_NETWORK_SUBSET_SERVICE_PROVIDER (0x0F) --  GW network subset and service provider personalization
 */

  uint32_t duration;
  /**<   Time before the temporary unlock expires, in seconds.
  */
}uim_temporary_unlock_feature_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_slot_enum_v01 slot_id;
  /**<   Indicates the slot on which the temporary unlock indication is received.
 Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  uint32_t feature_info_len;  /**< Must be set to # of elements in feature_info */
  uim_temporary_unlock_feature_type_v01 feature_info[QMI_UIM_PERSO_FEATURE_MAX_V01];
}uim_temporary_unlock_slot_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indicates the temporary unlock status of the modem. */
typedef struct {

  /* Mandatory */
  /*  Temporary Unlock Status */
  uint32_t temporary_unlock_status_len;  /**< Must be set to # of elements in temporary_unlock_status */
  uim_temporary_unlock_slot_info_type_v01 temporary_unlock_status[QMI_UIM_EXTENDED_CARDS_MAX_V01];
}uim_temporary_unlock_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_GBA_KEY_STATUS_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_GBA_KEY_EXPIRED_V01 = 0x00, /**<  The key has expired\n  */
  UIM_GBA_KEY_REPLACED_V01 = 0x01, /**<  The key was replaced as a result of another bootstrapping procedure\n  */
  UIM_GBA_KEY_DISCARDED_V01 = 0x02, /**<  The key was discarded by the GBA module\n  */
  UIM_GBA_KEY_STATUS_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_gba_key_status_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indication containing the GBA key status requested by the client via QMI_UIM_GBA_REQ. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  Key Status */
  uim_gba_key_status_enum_v01 key_status;
  /**<   Key status previously received by the client.
  */

  /* Mandatory */
  /*  Bootstrapping Transaction ID */
  uint32_t btid_len;  /**< Must be set to # of elements in btid */
  char btid[QMI_UIM_BTID_MAX_V01];
  /**<   ID that binds the subscriber identity to the keying material. This is
       same as the B-TID sent in QMI_UIM_GBA_RESP or QMI_UIM_GBA_IND.
       For B-TID formatting, refer to \hyperref[3G33220]{3GPP TS 33.220}.
  */
}uim_gba_key_status_ind_msg_v01;  /* Message */
/**
    @}
  */

typedef uint32_t uim_purge_temporary_identity_mask_v01;
#define UIM_PURGE_TEMPORARY_IDENTITY_REQ_GUTI_MASK_V01 ((uim_purge_temporary_identity_mask_v01)0x01) /**<  GUTI  */
/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Purges temporary identity information stored in UICC or non-volatile memory. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  Purge Temporary Identity Request */
  uim_purge_temporary_identity_mask_v01 purge_temporary_identity_req_mask;
  /**<   Bitmask of the temporary identity to be purged:
      - UIM_PURGE_TEMPORARY_IDENTITY_REQ_GUTI_MASK (0x01) --  GUTI
 \vspace{3pt} \n
 Each bit set indicates a request made to QMI_UIM to purge the
 corresponding temporary identity. All unlisted bits are reserved
 for future use and must be set to zero.
 */
}uim_purge_temporary_identity_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Purges temporary identity information stored in UICC or non-volatile memory. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_purge_temporary_identity_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indicates the clients with a purge confirmation. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Mandatory */
  /*  Session Type */
  uim_session_type_enum_v01 session_type;
  /**<   Indicates the session type. \n
       Valid values -- 0 to 3 and 10 to 15. \n
       See Table \ref{tbl:sessions} for available session types.
  */

  /* Mandatory */
  /*  Purge Temporary Identity Request */
  uim_purge_temporary_identity_mask_v01 purge_temporary_identity_req_mask;
  /**<   Bitmask of the temporary identity to be purged:
      - UIM_PURGE_TEMPORARY_IDENTITY_REQ_GUTI_MASK (0x01) --  GUTI
 \vspace{3pt} \n
 Each bit set indicates a request made to QMI_UIM to purge the
 corresponding temporary identity. All unlisted bits are reserved
 for future use and must be set to zero.
 */
}uim_purge_temporary_identity_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Maps the logical slots to the physical slots. */
typedef struct {

  /* Mandatory */
  /*  Physical Slots */
  uint32_t logical_slot_len;  /**< Must be set to # of elements in logical_slot */
  uim_physical_slot_enum_v01 logical_slot[QMI_UIM_EXTENDED_CARDS_MAX_V01];
  /**<   Physical slots. Valid values:\n
      - UIM_PHY_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_PHY_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_PHY_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_PHY_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_PHY_SLOT_5 (0x05) --  Slot 5
 */
}uim_switch_slot_ext_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Maps the logical slots to the physical slots. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_switch_slot_ext_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Provides the existing physical slot to logical slot mapping. */
typedef struct {
  /* This element is a placeholder to prevent the declaration of
     an empty struct.  DO NOT USE THIS FIELD UNDER ANY CIRCUMSTANCE */
  char __placeholder;
}uim_get_physical_slot_mapping_req_msg_v01;

  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Provides the existing physical slot to logical slot mapping. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Physical Slots */
  uint8_t logical_slot_valid;  /**< Must be set to true if logical_slot is being passed */
  uint32_t logical_slot_len;  /**< Must be set to # of elements in logical_slot */
  uim_physical_slot_enum_v01 logical_slot[QMI_UIM_EXTENDED_CARDS_MAX_V01];
  /**<   Physical slots. Valid values:\n
      - UIM_PHY_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_PHY_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_PHY_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_PHY_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_PHY_SLOT_5 (0x05) --  Slot 5
 */
}uim_get_physical_slot_mapping_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Queries the profile information from the card. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the recovered slot. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Mandatory */
  /*  Profile ID */
  uim_profile_id_enum_v01 profile_id;
  /**<   Indicates the profile ID to switch. Valid values:\n
      - UIM_PROFILE_ID_1 (0x01) --   \n Profile 1 \n
      - UIM_PROFILE_ID_2 (0x02) --   \n Profile 2 \n
      - UIM_PROFILE_ID_3 (0x03) --   \n Profile 3 \n
      - UIM_PROFILE_ID_4 (0x04) --   \n Profile 4 \n
      - UIM_PROFILE_ID_5 (0x05) --   \n Profile 5 \n
      - UIM_PROFILE_ID_6 (0x06) --  \n Profile 6 \n
      - UIM_PROFILE_ID_7 (0x07) --  \n Profile 7 \n
      - UIM_PROFILE_ID_8 (0x08) --  \n Profile 8
 */
}uim_get_profile_info_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_PROFILE_ICON_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_PROFILE_ICON_TYPE_NONE_V01 = 0x00, /**<  No icon information \n */
  UIM_PROFILE_ICON_TYPE_JPEG_V01 = 0x01, /**<  JPEG icon \n */
  UIM_PROFILE_ICON_TYPE_PNG_V01 = 0x02, /**<  PNG icon  */
  UIM_PROFILE_ICON_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_profile_icon_type_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_PROFILE_STATE_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_PROFILE_STATE_INACTIVE_V01 = 0x00, /**<  Inactive profile \n */
  UIM_PROFILE_STATE_ACTIVE_V01 = 0x01, /**<  Active profile  */
  UIM_PROFILE_STATE_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_profile_state_type_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_PROFILE_CLASS_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_PROFILE_CLASS_TEST_V01 = 0x00, /**<  Test profile \n */
  UIM_PROFILE_CLASS_PROVISIONING_V01 = 0x01, /**<  Provisioning profile \n  */
  UIM_PROFILE_CLASS_OPERATIONAL_V01 = 0x02, /**<  Operational profile  */
  UIM_PROFILE_CLASS_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_profile_class_type_v01;
/**
    @}
  */

typedef uint64_t uim_profile_ppr_mask_v01;
#define UIM_PPR_PROFILE_DISABLE_NOT_ALLOWED_V01 ((uim_profile_ppr_mask_v01)0x01ull) /**<  Disabling of this profile is not allowed \n */
#define UIM_PPR_PROFILE_DELETE_NOT_ALLOWED_V01 ((uim_profile_ppr_mask_v01)0x02ull) /**<  Deletion of this profile is not allowed \n  */
#define UIM_PPR_PROFILE_DELETE_ON_DISABLE_V01 ((uim_profile_ppr_mask_v01)0x04ull) /**<  Deletion of this profile is required upon its successful disabling  */
/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Queries the profile information from the card. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members: \n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE. \n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Profile ICCID */
  uint8_t profile_iccid_valid;  /**< Must be set to true if profile_iccid is being passed */
  uint32_t profile_iccid_len;  /**< Must be set to # of elements in profile_iccid */
  uint8_t profile_iccid[QMI_UIM_ICCID_LEN_MAX_V01];
  /**<   Indicates the profile ICCID coded as in EF-ICCID
  */

  /* Optional */
  /*  Profile State */
  uint8_t profile_state_valid;  /**< Must be set to true if profile_state is being passed */
  uim_profile_state_type_v01 profile_state;
  /**<   Indicates the profile state. Valid values: \n
      - UIM_PROFILE_STATE_INACTIVE (0x00) --  Inactive profile \n
      - UIM_PROFILE_STATE_ACTIVE (0x01) --  Active profile
 \n Other values are reserved for future and should
 be handled as if the profile is inactive.
 */

  /* Optional */
  /*  Profile Nickname */
  uint8_t profile_nickname_valid;  /**< Must be set to true if profile_nickname is being passed */
  uint32_t profile_nickname_len;  /**< Must be set to # of elements in profile_nickname */
  char profile_nickname[QMI_UIM_EUICC_NICKNAME_MAX_V01];
  /**<   Indicates the profile nickname.
  */

  /* Optional */
  /*  Profile Service Provider Name */
  uint8_t profile_spn_valid;  /**< Must be set to true if profile_spn is being passed */
  uint32_t profile_spn_len;  /**< Must be set to # of elements in profile_spn */
  char profile_spn[QMI_UIM_EUICC_SPN_MAX_V01];
  /**<   Indicates the profile service provider name.
  */

  /* Optional */
  /*  Profile Name */
  uint8_t profile_name_valid;  /**< Must be set to true if profile_name is being passed */
  uint32_t profile_name_len;  /**< Must be set to # of elements in profile_name */
  char profile_name[QMI_UIM_EUICC_PROFILE_NAME_MAX_V01];
  /**<   Indicates the profile name.
  */

  /* Optional */
  /*  Profile Icon Type */
  uint8_t profile_icon_type_valid;  /**< Must be set to true if profile_icon_type is being passed */
  uim_profile_icon_type_v01 profile_icon_type;
  /**<   Indicates the profile icon type. Valid values: \n
      - UIM_PROFILE_ICON_TYPE_NONE (0x00) --  No icon information \n
      - UIM_PROFILE_ICON_TYPE_JPEG (0x01) --  JPEG icon \n
      - UIM_PROFILE_ICON_TYPE_PNG (0x02) --  PNG icon
 \n Other values are reserved for future use
 and should be handled as NONE.
 */

  /* Optional */
  /*  Profile Icon */
  uint8_t profile_icon_data_valid;  /**< Must be set to true if profile_icon_data is being passed */
  uint32_t profile_icon_data_len;  /**< Must be set to # of elements in profile_icon_data */
  uint8_t profile_icon_data[QMI_UIM_EUICC_ICON_MAX_V01];
  /**<   Indicates the profile icon.
  */

  /* Optional */
  /*  Profile Class */
  uint8_t profile_class_valid;  /**< Must be set to true if profile_class is being passed */
  uim_profile_class_type_v01 profile_class;
  /**<   Indicates the profile class. Valid values: \n
      - UIM_PROFILE_CLASS_TEST (0x00) --  Test profile \n
      - UIM_PROFILE_CLASS_PROVISIONING (0x01) --  Provisioning profile \n
      - UIM_PROFILE_CLASS_OPERATIONAL (0x02) --  Operational profile
 \n Other values are reserved for future use and should be handled
 as operational. If the TLV is missing, the profile should be
 handled as operational.
 */

  /* Optional */
  /*  Profile Policy Rules */
  uint8_t profile_policy_rules_valid;  /**< Must be set to true if profile_policy_rules is being passed */
  uim_profile_ppr_mask_v01 profile_policy_rules;
  /**<   Indicates the profile policy rules applicable for this profile.
       If the TLV is missing, it indicates there is no profile policy rule
       associated with this profile. Other bits are reserved for future
       use and shall be ignored by the client.
  */
}uim_get_profile_info_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Provides the eUICC ID for the given slot. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot for which the EID is requested. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */
}uim_get_eid_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Provides the eUICC ID for the given slot. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  EID */
  uint8_t eid_value_valid;  /**< Must be set to true if eid_value is being passed */
  uint32_t eid_value_len;  /**< Must be set to # of elements in eid_value */
  uint8_t eid_value[QMI_UIM_EID_LEN_V01];
  /**<   eUICC ID value */
}uim_get_eid_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Deletes the profile from the card. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot for delete profile. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Mandatory */
  /*  Profile ID */
  uim_profile_id_enum_v01 profile_id;
  /**<   Indicates the profile ID to delete. Valid values:\n
      - UIM_PROFILE_ID_1 (0x01) --   \n Profile 1 \n
      - UIM_PROFILE_ID_2 (0x02) --   \n Profile 2 \n
      - UIM_PROFILE_ID_3 (0x03) --   \n Profile 3 \n
      - UIM_PROFILE_ID_4 (0x04) --   \n Profile 4 \n
      - UIM_PROFILE_ID_5 (0x05) --   \n Profile 5 \n
      - UIM_PROFILE_ID_6 (0x06) --  \n Profile 6 \n
      - UIM_PROFILE_ID_7 (0x07) --  \n Profile 7 \n
      - UIM_PROFILE_ID_8 (0x08) --  \n Profile 8
 */
}uim_delete_profile_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Deletes the profile from the card. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_delete_profile_resp_msg_v01;  /* Message */
/**
    @}
  */

typedef uint64_t uim_reset_option_mask_v01;
#define UIM_RESET_TEST_PROFILES_V01 ((uim_reset_option_mask_v01)0x01ull) /**<  Delete all the test profiles \n */
#define UIM_RESET_OPERATIONAL_PROFILES_V01 ((uim_reset_option_mask_v01)0x02ull) /**<  Delete all operational profiles  */
#define UIM_RESET_TO_DEFAULT_SMDP_ADDRESS_V01 ((uim_reset_option_mask_v01)0x04ull) /**<  Reset the default SM-DP+ address  */
/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Resets the memory of the eUICC card. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot to reset. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Optional */
  /*  Reset Option */
  uint8_t reset_option_valid;  /**< Must be set to true if reset_option is being passed */
  uim_reset_option_mask_v01 reset_option;
  /**<   Indicates the reset option for eUICC. Valid values: \n
      - UIM_RESET_TEST_PROFILES (0x01) --  Delete all the test profiles \n
      - UIM_RESET_OPERATIONAL_PROFILES (0x02) --  Delete all operational profiles
      - UIM_RESET_TO_DEFAULT_SMDP_ADDRESS (0x04) --  Reset the default SM-DP+ address
 All other bits are reserved for future use; if the TLV is missing,
 complete eUICC card will be reset.
 */
}uim_euicc_memory_reset_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Resets the memory of the eUICC card. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_euicc_memory_reset_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Adds a new profile to the eUICC card. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot where the profile is added. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Mandatory */
  /*  Activation Code */
  uint32_t activation_code_len;  /**< Must be set to # of elements in activation_code */
  char activation_code[QMI_UIM_EUICC_DOWNLOAD_CODE_MAX_V01];
  /**<   Indicates the activation code required for downloading a profile.
  */

  /* Optional */
  /*  Confirmation Code */
  uint8_t confirmation_code_valid;  /**< Must be set to true if confirmation_code is being passed */
  uint32_t confirmation_code_len;  /**< Must be set to # of elements in confirmation_code */
  char confirmation_code[QMI_UIM_EUICC_DOWNLOAD_CODE_MAX_V01];
  /**<   Indicates the confirmation code required for downloading
       the profile.
  */

  /* Optional */
  /*  User Consent Support */
  uint8_t user_consent_supported_valid;  /**< Must be set to true if user_consent_supported is being passed */
  uint8_t user_consent_supported;
  /**<   Indicates whether the control point is able to support a request for consent
       from the user. If the TLV is missing, the control
       point does not support user consent. Valid values:\n
         - 0 -- User consent not supported \n
         - 1 -- User consent supported */
}uim_add_profile_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Adds a new profile to the eUICC card. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_add_profile_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_PROFILE_DOWNLOAD_STATUS_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_PROFILE_DOWNLOAD_ERROR_V01 = 0x01, /**<  Profile download error \n
   */
  UIM_PROFILE_DOWNLOAD_IN_PROGRESS_V01 = 0x02, /**<  Profile download in progress with download percentage \n
   */
  UIM_PROFILE_DOWNLOAD_COMPLETE_INSTALLATION_IN_PROGRESS_V01 = 0x03, /**<  Profile download is complete and installation is in progress \n
   */
  UIM_PROFILE_INSTALLATION_COMPLETE_V01 = 0x04, /**<  Profile installation is complete \n
   */
  UIM_PROFILE_USER_CONSENT_REQUIRED_V01 = 0x05, /**<  User consent is required for proceeding
       with download/installation of profile.
   */
  UIM_PROFILE_DOWNLOAD_STATUS_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_profile_download_status_enum_type_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_DOWNLOAD_ERROR_CAUSE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_DOWNLOAD_ERROR_CAUSE_GENERIC_V01 = 0x01, /**<  Profile download generic error \n
   */
  UIM_DOWNLOAD_ERROR_CAUSE_SIM_V01 = 0x02, /**<  Profile download error from the SIM card \n
   */
  UIM_DOWNLOAD_ERROR_CAUSE_NETWORK_V01 = 0x03, /**<  Profile download error from the network \n
   */
  UIM_DOWNLOAD_ERROR_CAUSE_MEMORY_V01 = 0x04, /**<  Profile download error no memory on terminal \n
   */
  UIM_DOWNLOAD_ERROR_CAUSE_UNSUPPORTED_PROFILE_CLASS_V01 = 0x05, /**<  Profile download error unsupported profile class \n
   */
  UIM_DOWNLOAD_ERROR_CAUSE_PPR_NOT_ALLOWED_V01 = 0x06, /**<  Profile download error profile policy rules not allowed
   */
  UIM_DOWNLOAD_ERROR_CAUSE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_download_error_cause_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uim_profile_ppr_mask_v01 profile_policy_mask;
  /**<   Indicates the profile policy rules for this profile */

  uint8_t user_consent_needed;
  /**<   Indicates whether user consent is required or not */
}profile_policy_info_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indicates the progress of the new profile. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot for download profile progress. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Mandatory */
  /*  Profile Download Status */
  uim_profile_download_status_enum_type_v01 profile_download_status;
  /**<   Indicates the stage of profile download and install. Valid values:\n
      - UIM_PROFILE_DOWNLOAD_ERROR (0x01) --  Profile download error \n

      - UIM_PROFILE_DOWNLOAD_IN_PROGRESS (0x02) --  Profile download in progress with download percentage \n

      - UIM_PROFILE_DOWNLOAD_COMPLETE_INSTALLATION_IN_PROGRESS (0x03) --  Profile download is complete and installation is in progress \n

      - UIM_PROFILE_INSTALLATION_COMPLETE (0x04) --  Profile installation is complete \n

      - UIM_PROFILE_USER_CONSENT_REQUIRED (0x05) --  User consent is required for proceeding
       with download/installation of profile.

 Other values are reserved for future use and should be
 ignored by the control point.
 */

  /* Optional */
  /*  Profile Download Error Cause */
  uint8_t error_cause_valid;  /**< Must be set to true if error_cause is being passed */
  uim_download_error_cause_v01 error_cause;
  /**<   Indicates the cause of the download error. Valid values:\n
      - UIM_DOWNLOAD_ERROR_CAUSE_GENERIC (0x01) --  Profile download generic error \n

      - UIM_DOWNLOAD_ERROR_CAUSE_SIM (0x02) --  Profile download error from the SIM card \n

      - UIM_DOWNLOAD_ERROR_CAUSE_NETWORK (0x03) --  Profile download error from the network \n

      - UIM_DOWNLOAD_ERROR_CAUSE_MEMORY (0x04) --  Profile download error no memory on terminal \n

      - UIM_DOWNLOAD_ERROR_CAUSE_UNSUPPORTED_PROFILE_CLASS (0x05) --  Profile download error unsupported profile class \n

      - UIM_DOWNLOAD_ERROR_CAUSE_PPR_NOT_ALLOWED (0x06) --  Profile download error profile policy rules not allowed

 Other values are reserved for future use and should be handled
 as generic error cause.
 */

  /* Optional */
  /*  Percentage */
  uint8_t percentage_valid;  /**< Must be set to true if percentage is being passed */
  uint8_t percentage;
  /**<   Percentage of download/installation done.
  */

  /* Optional */
  /*  Profile Policy Rules */
  uint8_t profile_policy_rules_valid;  /**< Must be set to true if profile_policy_rules is being passed */
  profile_policy_info_v01 profile_policy_rules;
  /**<   \n Indicates the profile policy rules and user consent for this profile.
       This TLV is only required when user consent and PPR needs to be sent to
     the control point, with Profile Download Status set as UIM_PROFILE_USER_CONSENT_REQUIRED.
  */
}uim_add_profile_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Updates the profile nickname. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot to update nickname. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Mandatory */
  /*  Profile ID */
  uim_profile_id_enum_v01 profile_id;
  /**<   Indicates the profile ID whose nickname needs to update. Valid values:\n
      - UIM_PROFILE_ID_1 (0x01) --   \n Profile 1 \n
      - UIM_PROFILE_ID_2 (0x02) --   \n Profile 2 \n
      - UIM_PROFILE_ID_3 (0x03) --   \n Profile 3 \n
      - UIM_PROFILE_ID_4 (0x04) --   \n Profile 4 \n
      - UIM_PROFILE_ID_5 (0x05) --   \n Profile 5 \n
      - UIM_PROFILE_ID_6 (0x06) --  \n Profile 6 \n
      - UIM_PROFILE_ID_7 (0x07) --  \n Profile 7 \n
      - UIM_PROFILE_ID_8 (0x08) --  \n Profile 8
 */

  /* Optional */
  /*  Nickname */
  uint8_t nickname_valid;  /**< Must be set to true if nickname is being passed */
  uint32_t nickname_len;  /**< Must be set to # of elements in nickname */
  char nickname[QMI_UIM_EUICC_NICKNAME_MAX_V01];
  /**<   Indicates the new nickname that needs to be updated. If the Nickname
       TLV is missing, the nickname is removed from the profile.
  */
}uim_update_profile_nickname_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Updates the profile nickname. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_update_profile_nickname_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t tag;
  /**<   Terminal capability tag, according to \hyperref[E102221]{ETSI TS 102 221}.
       The service allows the client to update only certain tags including
       the following:\n
         - 0x82 -- Additional interface support \n
         - 0x83 -- Local Profile Assistant support
  */

  uint32_t value_len;  /**< Must be set to # of elements in value */
  uint8_t value[QMI_UIM_TERMINAL_CAPABILITY_VALUE_MAX_V01];
  /**<   Value of the terminal capability.
  */

  uint8_t remove_tlv;
  /**<   Indicates whether this TLV should be removed from the terminal
       capability that is sent to the card. When this is set to TRUE, the value
       field is ignored.
  */
}uim_terminal_capability_tlv_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t tag;
  /**<   Terminal capability tag, according to \hyperref[E102221]{ETSI TS 102 221},
       that was sent to the card during current card initialization or is sent
     to the card upon power up.
  */

  uint32_t value_len;  /**< Must be set to # of elements in value */
  uint8_t value[QMI_UIM_TERMINAL_CAPABILITY_VALUE_MAX_V01];
  /**<   Value of the terminal capability.
  */
}uim_terminal_capability_tlv_resp_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Sets or gets the terminal capability. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot to which the terminal capability applies.
 Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Optional */
  /*  Terminal Capability */
  uint8_t terminal_capability_tlv_valid;  /**< Must be set to true if terminal_capability_tlv is being passed */
  uint32_t terminal_capability_tlv_len;  /**< Must be set to # of elements in terminal_capability_tlv */
  uim_terminal_capability_tlv_type_v01 terminal_capability_tlv[QMI_UIM_TERMINAL_CAPABILITY_TLVS_MAX_V01];
}uim_terminal_capability_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Sets or gets the terminal capability. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code; possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Terminal Capability */
  uint8_t terminal_capability_tlv_valid;  /**< Must be set to true if terminal_capability_tlv is being passed */
  uint32_t terminal_capability_tlv_len;  /**< Must be set to # of elements in terminal_capability_tlv */
  uim_terminal_capability_tlv_resp_type_v01 terminal_capability_tlv[QMI_UIM_TERMINAL_CAPABILITY_TLVS_MAX_V01];
}uim_terminal_capability_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_APDU_BEHAVIOR_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_APDU_BEHAVIOR_NO_GET_RESPONSE_FOR_WARNING_V01 = 0x01, /**<  APDU behavior is not to issue an automatic GET RESPONSE
       command for warning status words 62XX/63XX. \n
   */
  UIM_APDU_BEHAVIOR_AUTOMATIC_GET_RESPONSE_FOR_WARNING_V01 = 0x02, /**<  APDU behavior is to issue an automatic GET RESPONSE
       command for warning status words 62XX/63XX. \n
   */
  UIM_APDU_BEHAVIOR_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_apdu_behavior_type_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Sets the APDU behavior of the modem for 62XX/63XX warning status words. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot to be used. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Mandatory */
  /*  Logical Channel */
  uint8_t channel_id;
  /**<   ID of the logical channel to be used.*/

  /* Optional */
  /*  Transmit Behavior Flag */
  uint8_t apdu_behavior_valid;  /**< Must be set to true if apdu_behavior is being passed */
  uim_apdu_behavior_type_v01 apdu_behavior;
  /**<   Sets the behavior of the modem for warning status words. Valid values:\n
      - UIM_APDU_BEHAVIOR_NO_GET_RESPONSE_FOR_WARNING (0x01) --  APDU behavior is not to issue an automatic GET RESPONSE
       command for warning status words 62XX/63XX. \n

      - UIM_APDU_BEHAVIOR_AUTOMATIC_GET_RESPONSE_FOR_WARNING (0x02) --  APDU behavior is to issue an automatic GET RESPONSE
       command for warning status words 62XX/63XX. \n

 Other values are ignored by the service and the
 QMI_ERR_INVALID_ARG error is returned.
 */
}uim_set_apdu_behavior_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Sets the APDU behavior of the modem for 62XX/63XX warning status words. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_set_apdu_behavior_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Provides the user consent for the profile management operation. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot for consent. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Mandatory */
  /*  User Consent */
  uint8_t user_ok;
  /**<   Control point indicates consent for profile management operation. Valid values:\n
         - 0 -- Not OK for profile operation\n
         - 1 -- OK for profile operation
  */
}uim_profile_user_consent_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Provides the user consent for the profile management operation. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_profile_user_consent_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Configures the default SM-DP+ address on the eUICC and
             retrieves the default SM-DS address and/or the default SM-DP+
             address from the eUICC. */
typedef struct {

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Optional */
  /*  Default SM-DP+ Address */
  uint8_t default_smdp_address_valid;  /**< Must be set to true if default_smdp_address is being passed */
  uint32_t default_smdp_address_len;  /**< Must be set to # of elements in default_smdp_address */
  char default_smdp_address[QMI_UIM_FQDN_MAX_V01];
  /**<   Indicates the address that must be configured on the eUICC as
       the default SM-DP+ address. If default_smdp_address_len
	   is set to zero, the existing SM-DP+ address on the eUICC is removed.
	   If this TLV is missing, the default SM-DS address configured on the eUICC and the default
       SM-DP+ address, if configured on the eUICC, are returned in the response.
  */
}uim_euicc_default_server_address_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Configures the default SM-DP+ address on the eUICC and
             retrieves the default SM-DS address and/or the default SM-DP+
             address from the eUICC. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Optional */
  /*  Default SM-DS Address */
  uint8_t default_smds_address_valid;  /**< Must be set to true if default_smds_address is being passed */
  uint32_t default_smds_address_len;  /**< Must be set to # of elements in default_smds_address */
  char default_smds_address[QMI_UIM_FQDN_MAX_V01];
  /**<   The default SM-DS address configured on the eUICC.
  */

  /* Optional */
  /*  Default SM-DP+ Address */
  uint8_t default_smdp_address_valid;  /**< Must be set to true if default_smdp_address is being passed */
  uint32_t default_smdp_address_len;  /**< Must be set to # of elements in default_smdp_address */
  char default_smdp_address[QMI_UIM_FQDN_MAX_V01];
  /**<   The default SM-DP+ address, if configured on the eUICC.
  */
}uim_euicc_default_server_address_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Maps the provisioning sessions to the slots. */
typedef struct {

  /* Optional */
  /*  Primary Slot */
  uint8_t primary_slot_valid;  /**< Must be set to true if primary_slot is being passed */
  uim_slot_enum_v01 primary_slot;
  /**<   Indicates the slot used for primary sessions. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Optional */
  /*  Secondary Slot */
  uint8_t secondary_slot_valid;  /**< Must be set to true if secondary_slot is being passed */
  uim_slot_enum_v01 secondary_slot;
  /**<   Indicates the slot used for secondary sessions. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Optional */
  /*  Tertiary Slot */
  uint8_t tertiary_slot_valid;  /**< Must be set to true if tertiary_slot is being passed */
  uim_slot_enum_v01 tertiary_slot;
  /**<   Indicates the slot used for tertiary sessions. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Optional */
  /*  Quaternary Slot */
  uint8_t quaternary_slot_valid;  /**< Must be set to true if quaternary_slot is being passed */
  uim_slot_enum_v01 quaternary_slot;
  /**<   Indicates the slot used for quaternary sessions. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */

  /* Optional */
  /*  Quinary Slot */
  uint8_t quinary_slot_valid;  /**< Must be set to true if quinary_slot is being passed */
  uim_slot_enum_v01 quinary_slot;
  /**<   Indicates the slot used for quinary sessions. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */
}uim_map_provisioning_sessions_to_slots_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Maps the provisioning sessions to the slots. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_map_provisioning_sessions_to_slots_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Provides read access to any BER-TLV file in the card and
    provides access by the path. */
typedef struct {

  /* Mandatory */
  /*  Session Information */
  uim_session_information_type_v01 session_information;

  /* Mandatory */
  /*  File ID */
  uim_file_id_type_v01 file_id;

  /* Mandatory */
  /*  Tag */
  uint32_t tag;
  /**<   Indicates the tag in the file to read.
  */

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result must be provided
       in a subsequent indication.
  */
}uim_read_ber_tlv_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t content_len;  /**< Must be set to # of elements in content */
  uint8_t content[QMI_UIM_BER_TLV_CONTENT_MAX_V01];
  /**<   Read content; sequence of bytes as read from the card.*/
}uim_read_ber_tlv_result_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Provides read access to any BER-TLV file in the card and
    provides access by the path. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message definition.
  */

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;

  /* Optional */
  /*  Read Result */
  uint8_t read_result_valid;  /**< Must be set to true if read_result is being passed */
  uim_read_ber_tlv_result_type_v01 read_result;

  /* Optional */
  /*  Response in Indication */
  uint8_t indication_token_valid;  /**< Must be set to true if indication_token is being passed */
  uint32_t indication_token;
  /**<   When this TLV is present, it indicates that the result is provided
       in a subsequent indication.
  */

  /* Optional */
  /*  Requested Length */
  uint8_t file_length_valid;  /**< Must be set to true if file_length is being passed */
  uint32_t file_length;
  /**<   When this TLV is present, the BER-TLV length exceeds the maximum size
       supported by QMI UIM. QMI_ERR_INSUFFICIENT_RESOURCES is returned to
       the client and this value indicates the total length.
  */

  /* Optional */
  /*  Long Data Token */
  uint8_t long_data_token_valid;  /**< Must be set to true if long_data_token is being passed */
  uint32_t long_data_token;
  /**<   When this TLV is present, the BER-TLV length exceeds the maximum size
       supported by QMI UIM. QMI_ERR_INSUFFICIENT_RESOURCES is returned to
       the client, and the result is provided in subsequent indications.
       Long data token is used to reconstruct the entire read response,
       possibly spanning multiple indications.
  */
}uim_read_ber_tlv_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indicates a read BER-TLV command result. */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */

  /* Mandatory */
  /*  Token of the Original Request */
  uint32_t indication_token;
  /**<   Indicates the token of the original request.*/

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;

  /* Optional */
  /*  Read Result */
  uint8_t read_result_valid;  /**< Must be set to true if read_result is being passed */
  uim_read_ber_tlv_result_type_v01 read_result;

  /* Optional */
  /*  Requested Length */
  uint8_t file_length_valid;  /**< Must be set to true if file_length is being passed */
  uint16_t file_length;
  /**<   When this TLV is present, the BER-TLV length exceeds the maximum size
       supported by the QMI UIM. QMI_ERR_INSUFFICIENT_RESOURCES is returned to
       the client, and this value indicates the total length.
  */

  /* Optional */
  /*  Long Data Token */
  uint8_t long_data_token_valid;  /**< Must be set to true if long_data_token is being passed */
  uint32_t long_data_token;
  /**<   When this TLV is present, the read result exceeds the maximum size
       supported by the Read Result TLV, and the result is provided in subsequent
       QMI_UIM_READ_BER_TLV_LONG_IND messages. Long data token is used to
       reconstruct the entire read response, possibly spanning multiple
       indications.
  */
}uim_read_ber_tlv_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_aggregates
    @{
  */
typedef struct {

  uint32_t long_data_token;
  /**<   Unique long data token used in the previous QMI_UIM_READ_BER_TLV
       response or indication.
  */

  uint16_t total_length;
  /**<   Total length of the read data. */

  uint16_t offset;
  /**<   Offset of the current chunk (starting from 0). */

  uim_read_ber_tlv_result_type_v01 read_result;
  /**<   Content of the read data chunk. */
}uim_read_ber_tlv_long_response_chunk_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Indication Message; Indicates the read BER-TLV command result. */
typedef struct {

  /* Mandatory */
  /*  Chunk of Read BER-TLV Data */
  uim_read_ber_tlv_long_response_chunk_type_v01 long_response_chunk;

  /* Optional */
  /*  Card Result */
  uint8_t card_result_valid;  /**< Must be set to true if card_result is being passed */
  uim_card_result_type_v01 card_result;
}uim_read_ber_tlv_long_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_enums
    @{
  */
typedef enum {
  UIM_SIM_PROFILE_SWITCH_LOCK_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  UIM_SIM_PROFILE_SWITCH_LOCK_DISABLE_V01 = 0x00, /**<  Disable SIM profile switch lock in the card \n  */
  UIM_SIM_PROFILE_SWITCH_LOCK_ENABLE_V01 = 0x01, /**<  Enable SIM profile switch lock in the card  */
  UIM_SIM_PROFILE_SWITCH_LOCK_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}uim_sim_profile_switch_lock_enum_v01;
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Request Message; Sends command to the card that enables or disables regular SIM
           profiles switch by the card */
typedef struct {

  /* Mandatory */
  /*  Profile switch lock */
  uim_sim_profile_switch_lock_enum_v01 lock;
  /**<   Valid values:\n
      - UIM_SIM_PROFILE_SWITCH_LOCK_DISABLE (0x00) --  Disable SIM profile switch lock in the card \n
      - UIM_SIM_PROFILE_SWITCH_LOCK_ENABLE (0x01) --  Enable SIM profile switch lock in the card
 */

  /* Mandatory */
  /*  Slot */
  uim_slot_enum_v01 slot;
  /**<   Indicates the slot to be used. Valid values:\n
      - UIM_SLOT_1 (0x01) --  Slot 1 \n
      - UIM_SLOT_2 (0x02) --  Slot 2 \n
      - UIM_SLOT_3 (0x03) --  Slot 3 \n
      - UIM_SLOT_4 (0x04) --  Slot 4 \n
      - UIM_SLOT_5 (0x05) --  Slot 5
 */
}uim_sim_profile_switch_lock_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup uim_qmi_messages
    @{
  */
/** Response Message; Sends command to the card that enables or disables regular SIM
           profiles switch by the card */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qmi_response_type_v01 resp;
  /**<   Standard response type. Contains the following data members:\n
       qmi_result_type -- QMI_RESULT_SUCCESS or QMI_RESULT_FAILURE.\n
       qmi_error_type  -- Error code. Possible error code values are described
                          in the error codes section of each message
                          definition.
  */
}uim_sim_profile_switch_lock_resp_msg_v01;  /* Message */
/**
    @}
  */

/* Conditional compilation tags for message removal */
//#define REMOVE_QMI_UIM_ADD_PROFILE_V01
//#define REMOVE_QMI_UIM_AUTHENTICATE_V01
//#define REMOVE_QMI_UIM_AUTHENTICATE_IND_V01
//#define REMOVE_QMI_UIM_CARD_ACTIVATION_STATUS_IND_V01
//#define REMOVE_QMI_UIM_CHANGE_PIN_V01
//#define REMOVE_QMI_UIM_CHANGE_PIN_IND_V01
//#define REMOVE_QMI_UIM_CHANGE_PROVISIONING_SESSION_V01
//#define REMOVE_QMI_UIM_CLOSE_SESSION_V01
//#define REMOVE_QMI_UIM_DELETE_PROFILE_V01
//#define REMOVE_QMI_UIM_DEPERSONALIZATION_V01
//#define REMOVE_QMI_UIM_DEPERSONALIZATION_SECURE_V01
//#define REMOVE_QMI_UIM_EMERGENCY_ONLY_V01
//#define REMOVE_QMI_UIM_EUICC_DEFAULT_SERVER_ADDRESS_V01
//#define REMOVE_QMI_UIM_EUICC_MEMORY_RESET_V01
//#define REMOVE_QMI_UIM_EVENT_REG_V01
//#define REMOVE_QMI_UIM_GBA_V01
//#define REMOVE_QMI_UIM_GBA_IND_V01
//#define REMOVE_QMI_UIM_GBA_KEY_STATUS_IND_V01
//#define REMOVE_QMI_UIM_GET_ATR_V01
//#define REMOVE_QMI_UIM_GET_CARD_STATUS_V01
//#define REMOVE_QMI_UIM_GET_CONFIGURATION_V01
//#define REMOVE_QMI_UIM_GET_EID_V01
//#define REMOVE_QMI_UIM_GET_FILE_ATTRIBUTES_V01
//#define REMOVE_QMI_UIM_GET_FILE_ATTRIBUTES_IND_V01
//#define REMOVE_QMI_UIM_GET_GBA_IMPI_V01
//#define REMOVE_QMI_UIM_GET_LABEL_V01
//#define REMOVE_QMI_UIM_GET_PHYSICAL_SLOT_MAPPING_V01
//#define REMOVE_QMI_UIM_GET_PLMN_NAME_TABLE_INFO_V01
//#define REMOVE_QMI_UIM_GET_PROFILE_INFO_V01
//#define REMOVE_QMI_UIM_GET_SERVICE_STATUS_V01
//#define REMOVE_QMI_UIM_GET_SIM_PROFILE_V01
//#define REMOVE_QMI_UIM_GET_SLOTS_STATUS_V01
//#define REMOVE_QMI_UIM_GET_SUPPORTED_FIELDS_V01
//#define REMOVE_QMI_UIM_GET_SUPPORTED_MSGS_V01
//#define REMOVE_QMI_UIM_INCREASE_V01
//#define REMOVE_QMI_UIM_INCREASE_IND_V01
//#define REMOVE_QMI_UIM_LOGICAL_CHANNEL_V01
//#define REMOVE_QMI_UIM_MAP_PROVISIONING_SESSIONS_TO_SLOTS_V01
//#define REMOVE_QMI_UIM_OPEN_LOGICAL_CHANNEL_V01
//#define REMOVE_QMI_UIM_PERSONALIZATION_V01
//#define REMOVE_QMI_UIM_PERSONALIZATION_SECURE_V01
//#define REMOVE_QMI_UIM_POWER_DOWN_V01
//#define REMOVE_QMI_UIM_POWER_UP_V01
//#define REMOVE_QMI_UIM_PROFILE_USER_CONSENT_V01
//#define REMOVE_QMI_UIM_PURGE_TEMPORARY_IDENTITY_V01
//#define REMOVE_QMI_UIM_PURGE_TEMPORARY_IDENTITY_IND_V01
//#define REMOVE_QMI_UIM_READ_BER_TLV_V01
//#define REMOVE_QMI_UIM_READ_BER_TLV_IND_V01
//#define REMOVE_QMI_UIM_READ_BER_TLV_LONG_IND_V01
//#define REMOVE_QMI_UIM_READ_RECORD_V01
//#define REMOVE_QMI_UIM_READ_RECORD_IND_V01
//#define REMOVE_QMI_UIM_READ_TRANSPARENT_V01
//#define REMOVE_QMI_UIM_READ_TRANSPARENT_IND_V01
//#define REMOVE_QMI_UIM_READ_TRANSPARENT_LONG_IND_V01
//#define REMOVE_QMI_UIM_RECOVERY_V01
//#define REMOVE_QMI_UIM_RECOVERY_IND_V01
//#define REMOVE_QMI_UIM_REFRESH_COMPLETE_V01
//#define REMOVE_QMI_UIM_REFRESH_GET_LAST_EVENT_V01
//#define REMOVE_QMI_UIM_REFRESH_IND_V01
//#define REMOVE_QMI_UIM_REFRESH_OK_V01
//#define REMOVE_QMI_UIM_REFRESH_REGISTER_V01
//#define REMOVE_QMI_UIM_REFRESH_REGISTER_ALL_V01
//#define REMOVE_QMI_UIM_REMOTE_UNLOCK_V01
//#define REMOVE_QMI_UIM_RESELECT_V01
//#define REMOVE_QMI_UIM_RESET_V01
//#define REMOVE_QMI_UIM_SAP_CONNECTION_V01
//#define REMOVE_QMI_UIM_SAP_CONNECTION_IND_V01
//#define REMOVE_QMI_UIM_SAP_REQUEST_V01
//#define REMOVE_QMI_UIM_SEARCH_RECORD_V01
//#define REMOVE_QMI_UIM_SEARCH_RECORD_IND_V01
//#define REMOVE_QMI_UIM_SEND_APDU_V01
//#define REMOVE_QMI_UIM_SEND_APDU_IND_V01
//#define REMOVE_QMI_UIM_SEND_STATUS_V01
//#define REMOVE_QMI_UIM_SESSION_CLOSED_IND_V01
//#define REMOVE_QMI_UIM_SET_APDU_BEHAVIOR_V01
//#define REMOVE_QMI_UIM_SET_FILE_STATUS_V01
//#define REMOVE_QMI_UIM_SET_PIN_PROTECTION_V01
//#define REMOVE_QMI_UIM_SET_PIN_PROTECTION_IND_V01
//#define REMOVE_QMI_UIM_SET_SERVICE_STATUS_V01
//#define REMOVE_QMI_UIM_SET_SIM_PROFILE_V01
//#define REMOVE_QMI_UIM_SIMLOCK_CONFIGURATION_V01
//#define REMOVE_QMI_UIM_SIMLOCK_CONFIGURATION_IND_V01
//#define REMOVE_QMI_UIM_SIM_BUSY_STATUS_IND_V01
//#define REMOVE_QMI_UIM_SIM_PROFILE_SWITCH_LOCK_V01
//#define REMOVE_QMI_UIM_SLOT_STATUS_CHANGE_IND_V01
//#define REMOVE_QMI_UIM_STATUS_CHANGE_IND_V01
//#define REMOVE_QMI_UIM_SUBSCRIPTION_OK_V01
//#define REMOVE_QMI_UIM_SUPPLY_VOLTAGE_V01
//#define REMOVE_QMI_UIM_SUPPLY_VOLTAGE_IND_V01
//#define REMOVE_QMI_UIM_SWITCH_SLOT_V01
//#define REMOVE_QMI_UIM_SWITCH_SLOT_EXT_V01
//#define REMOVE_QMI_UIM_TEMPORARY_UNLOCK_STATUS_IND_V01
//#define REMOVE_QMI_UIM_TERMINAL_CAPABILITY_V01
//#define REMOVE_QMI_UIM_UNBLOCK_PIN_V01
//#define REMOVE_QMI_UIM_UNBLOCK_PIN_IND_V01
//#define REMOVE_QMI_UIM_UPDATE_PROFILE_NICKNAME_V01
//#define REMOVE_QMI_UIM_VERIFY_IMSI_V01
//#define REMOVE_QMI_UIM_VERIFY_PIN_V01
//#define REMOVE_QMI_UIM_VERIFY_PIN_IND_V01
//#define REMOVE_QMI_UIM_WRITE_RECORD_V01
//#define REMOVE_QMI_UIM_WRITE_RECORD_IND_V01
//#define REMOVE_QMI_UIM_WRITE_TRANSPARENT_V01
//#define REMOVE_QMI_UIM_WRITE_TRANSPARENT_IND_V01

/*Service Message Definition*/
/** @addtogroup uim_qmi_msg_ids
    @{
  */
#define QMI_UIM_RESET_REQ_V01 0x0000
#define QMI_UIM_RESET_RESP_V01 0x0000
#define QMI_UIM_GET_SUPPORTED_MSGS_REQ_V01 0x001E
#define QMI_UIM_GET_SUPPORTED_MSGS_RESP_V01 0x001E
#define QMI_UIM_GET_SUPPORTED_FIELDS_REQ_V01 0x001F
#define QMI_UIM_GET_SUPPORTED_FIELDS_RESP_V01 0x001F
#define QMI_UIM_READ_TRANSPARENT_REQ_V01 0x0020
#define QMI_UIM_READ_TRANSPARENT_RESP_V01 0x0020
#define QMI_UIM_READ_TRANSPARENT_IND_V01 0x0020
#define QMI_UIM_READ_RECORD_REQ_V01 0x0021
#define QMI_UIM_READ_RECORD_RESP_V01 0x0021
#define QMI_UIM_READ_RECORD_IND_V01 0x0021
#define QMI_UIM_WRITE_TRANSPARENT_REQ_V01 0x0022
#define QMI_UIM_WRITE_TRANSPARENT_RESP_V01 0x0022
#define QMI_UIM_WRITE_TRANSPARENT_IND_V01 0x0022
#define QMI_UIM_WRITE_RECORD_REQ_V01 0x0023
#define QMI_UIM_WRITE_RECORD_RESP_V01 0x0023
#define QMI_UIM_WRITE_RECORD_IND_V01 0x0023
#define QMI_UIM_GET_FILE_ATTRIBUTES_REQ_V01 0x0024
#define QMI_UIM_GET_FILE_ATTRIBUTES_RESP_V01 0x0024
#define QMI_UIM_GET_FILE_ATTRIBUTES_IND_V01 0x0024
#define QMI_UIM_SET_PIN_PROTECTION_REQ_V01 0x0025
#define QMI_UIM_SET_PIN_PROTECTION_RESP_V01 0x0025
#define QMI_UIM_SET_PIN_PROTECTION_IND_V01 0x0025
#define QMI_UIM_VERIFY_PIN_REQ_V01 0x0026
#define QMI_UIM_VERIFY_PIN_RESP_V01 0x0026
#define QMI_UIM_VERIFY_PIN_IND_V01 0x0026
#define QMI_UIM_UNBLOCK_PIN_REQ_V01 0x0027
#define QMI_UIM_UNBLOCK_PIN_RESP_V01 0x0027
#define QMI_UIM_UNBLOCK_PIN_IND_V01 0x0027
#define QMI_UIM_CHANGE_PIN_REQ_V01 0x0028
#define QMI_UIM_CHANGE_PIN_RESP_V01 0x0028
#define QMI_UIM_CHANGE_PIN_IND_V01 0x0028
#define QMI_UIM_DEPERSONALIZATION_REQ_V01 0x0029
#define QMI_UIM_DEPERSONALIZATION_RESP_V01 0x0029
#define QMI_UIM_REFRESH_REGISTER_REQ_V01 0x002A
#define QMI_UIM_REFRESH_REGISTER_RESP_V01 0x002A
#define QMI_UIM_REFRESH_OK_REQ_V01 0x002B
#define QMI_UIM_REFRESH_OK_RESP_V01 0x002B
#define QMI_UIM_REFRESH_COMPLETE_REQ_V01 0x002C
#define QMI_UIM_REFRESH_COMPLETE_RESP_V01 0x002C
#define QMI_UIM_REFRESH_GET_LAST_EVENT_REQ_V01 0x002D
#define QMI_UIM_REFRESH_GET_LAST_EVENT_RESP_V01 0x002D
#define QMI_UIM_EVENT_REG_REQ_V01 0x002E
#define QMI_UIM_EVENT_REG_RESP_V01 0x002E
#define QMI_UIM_GET_CARD_STATUS_REQ_V01 0x002F
#define QMI_UIM_GET_CARD_STATUS_RESP_V01 0x002F
#define QMI_UIM_POWER_DOWN_REQ_V01 0x0030
#define QMI_UIM_POWER_DOWN_RESP_V01 0x0030
#define QMI_UIM_POWER_UP_REQ_V01 0x0031
#define QMI_UIM_POWER_UP_RESP_V01 0x0031
#define QMI_UIM_STATUS_CHANGE_IND_V01 0x0032
#define QMI_UIM_REFRESH_IND_V01 0x0033
#define QMI_UIM_AUTHENTICATE_REQ_V01 0x0034
#define QMI_UIM_AUTHENTICATE_RESP_V01 0x0034
#define QMI_UIM_AUTHENTICATE_IND_V01 0x0034
#define QMI_UIM_CLOSE_SESSION_REQ_V01 0x0035
#define QMI_UIM_CLOSE_SESSION_RESP_V01 0x0035
#define QMI_UIM_GET_SERVICE_STATUS_REQ_V01 0x0036
#define QMI_UIM_GET_SERVICE_STATUS_RESP_V01 0x0036
#define QMI_UIM_SET_SERVICE_STATUS_REQ_V01 0x0037
#define QMI_UIM_SET_SERVICE_STATUS_RESP_V01 0x0037
#define QMI_UIM_CHANGE_PROVISIONING_SESSION_REQ_V01 0x0038
#define QMI_UIM_CHANGE_PROVISIONING_SESSION_RESP_V01 0x0038
#define QMI_UIM_GET_LABEL_REQ_V01 0x0039
#define QMI_UIM_GET_LABEL_RESP_V01 0x0039
#define QMI_UIM_GET_CONFIGURATION_REQ_V01 0x003A
#define QMI_UIM_GET_CONFIGURATION_RESP_V01 0x003A
#define QMI_UIM_SEND_APDU_REQ_V01 0x003B
#define QMI_UIM_SEND_APDU_RESP_V01 0x003B
#define QMI_UIM_SEND_APDU_IND_V01 0x003B
#define QMI_UIM_SAP_CONNECTION_REQ_V01 0x003C
#define QMI_UIM_SAP_CONNECTION_RESP_V01 0x003C
#define QMI_UIM_SAP_REQUEST_REQ_V01 0x003D
#define QMI_UIM_SAP_REQUEST_RESP_V01 0x003D
#define QMI_UIM_SAP_CONNECTION_IND_V01 0x003E
#define QMI_UIM_LOGICAL_CHANNEL_REQ_V01 0x003F
#define QMI_UIM_LOGICAL_CHANNEL_RESP_V01 0x003F
#define QMI_UIM_SUBSCRIPTION_OK_REQ_V01 0x0040
#define QMI_UIM_SUBSCRIPTION_OK_RESP_V01 0x0040
#define QMI_UIM_GET_ATR_REQ_V01 0x0041
#define QMI_UIM_GET_ATR_RESP_V01 0x0041
#define QMI_UIM_OPEN_LOGICAL_CHANNEL_REQ_V01 0x0042
#define QMI_UIM_OPEN_LOGICAL_CHANNEL_RESP_V01 0x0042
#define QMI_UIM_SESSION_CLOSED_IND_V01 0x0043
#define QMI_UIM_REFRESH_REGISTER_ALL_REQ_V01 0x0044
#define QMI_UIM_REFRESH_REGISTER_ALL_RESP_V01 0x0044
#define QMI_UIM_SET_FILE_STATUS_REQ_V01 0x0045
#define QMI_UIM_SET_FILE_STATUS_RESP_V01 0x0045
#define QMI_UIM_SWITCH_SLOT_REQ_V01 0x0046
#define QMI_UIM_SWITCH_SLOT_RESP_V01 0x0046
#define QMI_UIM_GET_SLOTS_STATUS_REQ_V01 0x0047
#define QMI_UIM_GET_SLOTS_STATUS_RESP_V01 0x0047
#define QMI_UIM_SLOT_STATUS_CHANGE_IND_V01 0x0048
#define QMI_UIM_READ_TRANSPARENT_LONG_IND_V01 0x0049
#define QMI_UIM_SIM_BUSY_STATUS_IND_V01 0x004A
#define QMI_UIM_GET_PLMN_NAME_TABLE_INFO_REQ_V01 0x004B
#define QMI_UIM_GET_PLMN_NAME_TABLE_INFO_RESP_V01 0x004B
#define QMI_UIM_PERSONALIZATION_REQ_V01 0x004C
#define QMI_UIM_PERSONALIZATION_RESP_V01 0x004C
#define QMI_UIM_INCREASE_REQ_V01 0x004D
#define QMI_UIM_INCREASE_RESP_V01 0x004D
#define QMI_UIM_INCREASE_IND_V01 0x004D
#define QMI_UIM_RECOVERY_REQ_V01 0x004E
#define QMI_UIM_RECOVERY_RESP_V01 0x004E
#define QMI_UIM_RESELECT_REQ_V01 0x004F
#define QMI_UIM_RESELECT_RESP_V01 0x004F
#define QMI_UIM_RECOVERY_IND_V01 0x0050
#define QMI_UIM_SEND_STATUS_REQ_V01 0x0051
#define QMI_UIM_SEND_STATUS_RESP_V01 0x0051
#define QMI_UIM_GET_SIM_PROFILE_REQ_V01 0x0052
#define QMI_UIM_GET_SIM_PROFILE_RESP_V01 0x0052
#define QMI_UIM_SET_SIM_PROFILE_REQ_V01 0x0053
#define QMI_UIM_SET_SIM_PROFILE_RESP_V01 0x0053
#define QMI_UIM_SUPPLY_VOLTAGE_REQ_V01 0x0054
#define QMI_UIM_SUPPLY_VOLTAGE_RESP_V01 0x0054
#define QMI_UIM_SUPPLY_VOLTAGE_IND_V01 0x0054
#define QMI_UIM_CARD_ACTIVATION_STATUS_IND_V01 0x0055
#define QMI_UIM_DEPERSONALIZATION_SECURE_REQ_V01 0x0056
#define QMI_UIM_DEPERSONALIZATION_SECURE_RESP_V01 0x0056
#define QMI_UIM_PERSONALIZATION_SECURE_REQ_V01 0x0057
#define QMI_UIM_PERSONALIZATION_SECURE_RESP_V01 0x0057
#define QMI_UIM_EMERGENCY_ONLY_REQ_V01 0x0058
#define QMI_UIM_EMERGENCY_ONLY_RESP_V01 0x0058
#define QMI_UIM_SIMLOCK_CONFIGURATION_REQ_V01 0x0059
#define QMI_UIM_SIMLOCK_CONFIGURATION_RESP_V01 0x0059
#define QMI_UIM_SIMLOCK_CONFIGURATION_IND_V01 0x0059
#define QMI_UIM_GBA_REQ_V01 0x005A
#define QMI_UIM_GBA_RESP_V01 0x005A
#define QMI_UIM_GBA_IND_V01 0x005A
#define QMI_UIM_GET_GBA_IMPI_REQ_V01 0x005B
#define QMI_UIM_GET_GBA_IMPI_RESP_V01 0x005B
#define QMI_UIM_SEARCH_RECORD_REQ_V01 0x005C
#define QMI_UIM_SEARCH_RECORD_RESP_V01 0x005C
#define QMI_UIM_SEARCH_RECORD_IND_V01 0x005C
#define QMI_UIM_REMOTE_UNLOCK_REQ_V01 0x005D
#define QMI_UIM_REMOTE_UNLOCK_RESP_V01 0x005D
#define QMI_UIM_VERIFY_IMSI_REQ_V01 0x005E
#define QMI_UIM_VERIFY_IMSI_RESP_V01 0x005E
#define QMI_UIM_TEMPORARY_UNLOCK_STATUS_IND_V01 0x005F
#define QMI_UIM_GBA_KEY_STATUS_IND_V01 0x0060
#define QMI_UIM_PURGE_TEMPORARY_IDENTITY_REQ_V01 0x0061
#define QMI_UIM_PURGE_TEMPORARY_IDENTITY_RESP_V01 0x0061
#define QMI_UIM_PURGE_TEMPORARY_IDENTITY_IND_V01 0x0061
#define QMI_UIM_SWITCH_SLOT_EXT_REQ_V01 0x0062
#define QMI_UIM_SWITCH_SLOT_EXT_RESP_V01 0x0062
#define QMI_UIM_GET_PHYSICAL_SLOT_MAPPING_REQ_V01 0x0063
#define QMI_UIM_GET_PHYSICAL_SLOT_MAPPING_RESP_V01 0x0063
#define QMI_UIM_GET_PROFILE_INFO_REQ_V01 0x0064
#define QMI_UIM_GET_PROFILE_INFO_RESP_V01 0x0064
#define QMI_UIM_GET_EID_REQ_V01 0x0065
#define QMI_UIM_GET_EID_RESP_V01 0x0065
#define QMI_UIM_DELETE_PROFILE_REQ_V01 0x0066
#define QMI_UIM_DELETE_PROFILE_RESP_V01 0x0066
#define QMI_UIM_EUICC_MEMORY_RESET_REQ_V01 0x0067
#define QMI_UIM_EUICC_MEMORY_RESET_RESP_V01 0x0067
#define QMI_UIM_ADD_PROFILE_REQ_V01 0x0068
#define QMI_UIM_ADD_PROFILE_RESP_V01 0x0068
#define QMI_UIM_ADD_PROFILE_IND_V01 0x0068
#define QMI_UIM_UPDATE_PROFILE_NICKNAME_REQ_V01 0x0069
#define QMI_UIM_UPDATE_PROFILE_NICKNAME_RESP_V01 0x0069
#define QMI_UIM_TERMINAL_CAPABILITY_REQ_V01 0x006A
#define QMI_UIM_TERMINAL_CAPABILITY_RESP_V01 0x006A
#define QMI_UIM_SET_APDU_BEHAVIOR_REQ_V01 0x006B
#define QMI_UIM_SET_APDU_BEHAVIOR_RESP_V01 0x006B
#define QMI_UIM_PROFILE_USER_CONSENT_REQ_V01 0x006C
#define QMI_UIM_PROFILE_USER_CONSENT_RESP_V01 0x006C
#define QMI_UIM_EUICC_DEFAULT_SERVER_ADDRESS_REQ_V01 0x006D
#define QMI_UIM_EUICC_DEFAULT_SERVER_ADDRESS_RESP_V01 0x006D
#define QMI_UIM_MAP_PROVISIONING_SESSIONS_TO_SLOTS_REQ_V01 0x006E
#define QMI_UIM_MAP_PROVISIONING_SESSIONS_TO_SLOTS_RESP_V01 0x006E
#define QMI_UIM_READ_BER_TLV_REQ_V01 0x006F
#define QMI_UIM_READ_BER_TLV_RESP_V01 0x006F
#define QMI_UIM_READ_BER_TLV_IND_V01 0x006F
#define QMI_UIM_READ_BER_TLV_LONG_IND_V01 0x0070
#define QMI_UIM_SIM_PROFILE_SWITCH_LOCK_REQ_V01 0x0071
#define QMI_UIM_SIM_PROFILE_SWITCH_LOCK_RESP_V01 0x0071
/**
    @}
  */

/* Service Object Accessor */
/** @addtogroup wms_qmi_accessor
    @{
  */
/** This function is used internally by the autogenerated code.  Clients should use the
   macro uim_get_service_object_v01( ) that takes in no arguments. */
qmi_idl_service_object_type uim_get_service_object_internal_v01
 ( int32_t idl_maj_version, int32_t idl_min_version, int32_t library_version );

/** This macro should be used to get the service object */
#define uim_get_service_object_v01( ) \
          uim_get_service_object_internal_v01( \
            UIM_V01_IDL_MAJOR_VERS, UIM_V01_IDL_MINOR_VERS, \
            UIM_V01_IDL_TOOL_VERS )
/**
    @}
  */


#ifdef __cplusplus
}
#endif
#endif

