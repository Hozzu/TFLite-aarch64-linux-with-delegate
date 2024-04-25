#ifndef WV_OEMC_DASH_CLNT_H
#define WV_OEMC_DASH_CLNT_H

/** @file wv_oemc_dash_clnt.h
 * @brief
 * This file contains the definitions of the constants, data structures and
 * and interfaces to the OEM_Crypto
 */
/*===========================================================================
  Copyright (c) 2011-2019 Qualcomm Technologies, Inc. 
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif

#include "comdef.h"
#include "wv_oemc_dash_type.h"

#define MAX_PST_SIZE           (256)
#define MAX_PST_SIZE_V13       (255)
#define MAX_KEY_ID_SIZE        (32)
#define MAX_KEY_ID_SIZE_V13    (16)
#define AES128_IV_LENGTH       (16)
#define AES256_IV_LENGTH       (32)
#define AES256_BLOCK_LENGTH    (32)
#define SHA256_DIGEST_LENGTH   (32)

#define OEMCrypto_SESSION            uint32

#define OEMCrypto_Supports_RSA_2048bit 0x1
#define OEMCrypto_Supports_RSA_3072bit 0x2
#define OEMCrypto_Supports_RSA_CAST   0x10

typedef unsigned char       uint8;
typedef unsigned short      uint16;
typedef unsigned int        uint32;
typedef unsigned long long  uint64;

typedef signed char         int8;
typedef signed short        int16;
typedef signed int          int32;
typedef signed long long    int64;

typedef uint8               boolean;

/*
 * Return values from OEMCrypto_GetAnalogOutputFlags.
 */
#define OEMCrypto_No_Analog_Output            0x0
#define OEMCrypto_Supports_Analog_Output      0x1
#define OEMCrypto_Can_Disable_Analog_Ouptput  0x2
#define OEMCrypto_Supports_CGMS_A             0x4
// Unknown_Analog_Output is used only for backwards compatibility.
#define OEMCrypto_Unknown_Analog_Output       (1<<31)
#define STR(R)                               #R
#define OEMC_STR(R)                          STR(R)

#define OEMCrypto_Initialize               _oecc01
#define OEMCrypto_Terminate                _oecc02
#define OEMCrypto_InstallKeybox            _oecc03
#define OEMCrypto_GetKeyData               _oecc04
#define OEMCrypto_IsKeyboxValid            _oecc05
#define OEMCrypto_GetRandom                _oecc06
#define OEMCrypto_GetDeviceID              _oecc07
#define OEMCrypto_WrapKeybox               _oecc08
#define OEMCrypto_OpenSession              _oecc09
#define OEMCrypto_CloseSession             _oecc10
#define OEMCrypto_GenerateDerivedKeys      _oecc12
#define OEMCrypto_GenerateSignature        _oecc13
#define OEMCrypto_GenerateNonce            _oecc14
#define OEMCrypto_RefreshKeys              _oecc16
#define OEMCrypto_RewrapDeviceRSAKey       _oecc18
#define OEMCrypto_LoadDeviceRSAKey         _oecc19
#define OEMCrypto_DeriveKeysFromSessionKey _oecc21
#define OEMCrypto_APIVersion               _oecc22
#define OEMCrypto_SecurityLevel            _oecc23
#define OEMCrypto_Generic_Encrypt          _oecc24
#define OEMCrypto_Generic_Decrypt          _oecc25
#define OEMCrypto_Generic_Sign             _oecc26
#define OEMCrypto_Generic_Verify           _oecc27
#define OEMCrypto_SupportsUsageTable       _oecc29
#define OEMCrypto_UpdateUsageTable         _oecc30
#define OEMCrypto_ReportUsage              _oecc32
#define OEMCrypto_DeleteUsageEntry         _oecc33
#define OEMCrypto_DeleteUsageTable         _oecc34
#define OEMCrypto_GenerateRSASignature     _oecc36
#define OEMCrypto_GetMaxNumberOfSessions   _oecc37
#define OEMCrypto_GetNumberOfOpenSessions  _oecc38
#define OEMCrypto_IsAntiRollbackHwPresent  _oecc39
#define OEMCrypto_CopyBuffer               _oecc40
#define OEMCrypto_QueryKeyControl          _oecc41
#define OEMCrypto_ForceDeleteUsageEntry    _oecc43
#define OEMCrypto_GetHDCPCapability        _oecc44
#define OEMCrypto_LoadTestRSAKey           _oecc45
#define OEMCrypto_Security_Patch_Level     _oecc46
#define OEMCrypto_DecryptCENC              _oecc48
#define OEMCrypto_GetProvisioningMethod    _oecc49
#define OEMCrypto_GetOEMPublicCertificate  _oecc50
#define OEMCrypto_RewrapDeviceRSAKey30     _oecc51
#define OEMCrypto_SupportedCertificates    _oecc52
#define OEMCrypto_IsSRMUpdateSupported     _oecc53
#define OEMCrypto_GetCurrentSRMVersion     _oecc54
#define OEMCrypto_LoadSRM                  _oecc55
#define OEMCrypto_RemoveSRM                _oecc57
#define OEMCrypto_CreateUsageTableHeader   _oecc61
#define OEMCrypto_LoadUsageTableHeader     _oecc62
#define OEMCrypto_CreateNewUsageEntry      _oecc63
#define OEMCrypto_LoadUsageEntry           _oecc64
#define OEMCrypto_UpdateUsageEntry         _oecc65
#define OEMCrypto_DeactivateUsageEntry     _oecc66
#define OEMCrypto_ShrinkUsageTableHeader   _oecc67
#define OEMCrypto_MoveEntry                _oecc68
#define OEMCrypto_CopyOldUsageEntry        _oecc69
#define OEMCrypto_CreateOldUsageEntry      _oecc70
#define OEMCrypto_GetAnalogOutputFlags     _oecc71
#define OEMCrypto_LoadTestKeybox           _oecc78
#define OEMCrypto_LoadEntitledContentKeys  _oecc79
#define OEMCrypto_SelectKey                _oecc81
#define OEMCrypto_LoadKeys                 _oecc82

typedef enum {
    OEMCrypto_SUCCESS = 0,
    OEMCrypto_ERROR_INIT_FAILED                  = 1,
    OEMCrypto_ERROR_TERMINATE_FAILED             = 2,
    OEMCrypto_ERROR_OPEN_FAILURE                 = 3,
    OEMCrypto_ERROR_CLOSE_FAILURE                = 4,
    OEMCrypto_ERROR_ENTER_SECURE_PLAYBACK_FAILED = 5,
    OEMCrypto_ERROR_EXIT_SECURE_PLAYBACK_FAILED  = 6,
    OEMCrypto_ERROR_SHORT_BUFFER                 = 7,
    OEMCrypto_ERROR_NO_DEVICE_KEY                = 8,
    OEMCrypto_ERROR_NO_ASSET_KEY                 = 9,
    OEMCrypto_ERROR_KEYBOX_INVALID               = 10,
    OEMCrypto_ERROR_NO_KEYDATA                   = 11,
    OEMCrypto_ERROR_NO_CW                        = 12,
    OEMCrypto_ERROR_DECRYPT_FAILED               = 13,
    OEMCrypto_ERROR_WRITE_KEYBOX                 = 14,
    OEMCrypto_ERROR_WRAP_KEYBOX                  = 15,
    OEMCrypto_ERROR_BAD_MAGIC                    = 16,
    OEMCrypto_ERROR_BAD_CRC                      = 17,
    OEMCrypto_ERROR_NO_DEVICEID                  = 18,
    OEMCrypto_ERROR_RNG_FAILED                   = 19,
    OEMCrypto_ERROR_RNG_NOT_SUPPORTED            = 20,
    OEMCrypto_ERROR_SETUP                        = 21,
    OEMCrypto_ERROR_OPEN_SESSION_FAILED          = 22,
    OEMCrypto_ERROR_CLOSE_SESSION_FAILED         = 23,
    OEMCrypto_ERROR_INVALID_SESSION              = 24,
    OEMCrypto_ERROR_NOT_IMPLEMENTED              = 25,
    OEMCrypto_ERROR_NO_CONTENT_KEY               = 26,
    OEMCrypto_ERROR_CONTROL_INVALID              = 27,
    OEMCrypto_ERROR_UNKNOWN_FAILURE              = 28,
    OEMCrypto_ERROR_INVALID_CONTEXT              = 29,
    OEMCrypto_ERROR_SIGNATURE_FAILURE            = 30,
    OEMCrypto_ERROR_TOO_MANY_SESSIONS            = 31,
    OEMCrypto_ERROR_INVALID_NONCE                = 32,
    OEMCrypto_ERROR_TOO_MANY_KEYS                = 33,
    OEMCrypto_ERROR_DEVICE_NOT_RSA_PROVISIONED   = 34,
    OEMCrypto_ERROR_INVALID_RSA_KEY              = 35,
    OEMCrypto_ERROR_KEY_EXPIRED                  = 36,
    OEMCrypto_ERROR_INSUFFICIENT_RESOURCES       = 37,
    OEMCrypto_ERROR_INSUFFICIENT_HDCP            = 38,
    OEMCrypto_ERROR_BUFFER_TOO_LARGE             = 39,
    OEMCrypto_WARNING_GENERATION_SKEW            = 40,  // Warning, not an error.
    OEMCrypto_ERROR_GENERATION_SKEW              = 41,
    OEMCrypto_LOCAL_DISPLAY_ONLY                 = 42,  // Info, not an error.
    OEMCrypto_ERROR_ANALOG_OUTPUT                = 43,
    OEMCrypto_ERROR_WRONG_PST                    = 44,
    OEMCrypto_ERROR_WRONG_KEYS                   = 45,
    OEMCrypto_ERROR_MISSING_MASTER               = 46,
    OEMCrypto_ERROR_LICENSE_INACTIVE             = 47,
    OEMCrypto_ERROR_ENTRY_NEEDS_UPDATE           = 48,
    OEMCrypto_ERROR_ENTRY_IN_USE                 = 49,
    OEMCrypto_ERROR_USAGE_TABLE_UNRECOVERABLE    = 50,  // Reserved. Do not use.
    OEMCrypto_KEY_NOT_LOADED                     = 51,
    OEMCrypto_KEY_NOT_ENTITLED                   = 52,

    /* Above is Google's defined error codes */
    /* Below are QTI defined error codes */
    OEMCrypto_ERROR_INVALID_INPUT                = 10000,
    OEMCrypto_ERROR_DECRYPT_FAILURE              = 10001,
    OEMCrypto_ERROR_RSA_SIGN_FAILURE             = 10002,
    OEMCrypto_ERROR_CACHE_FLUSH                  = 10003,
    OEMCrypto_ERROR_PERMISSION_DENY              = 10004,
    OEMCrypto_ERROR_NAME_TOO_LONG                = 10005,
    OEMCrypto_ERROR_RPMB_ACCESS                  = 10006,
    OEMCrypto_ERROR_FILE_OPEN                    = 10007,
    OEMCrypto_ERROR_FILE_READ                    = 10008,
    OEMCrypto_ERROR_FILE_WRITE                   = 10009,
    OEMCrypto_ERROR_FILE_CLOSE                   = 10010,
    OEMCrypto_ERROR_FILE_REMOVE                  = 10011,
    OEMCrypto_ERROR_ROLL_BACK                    = 10012,
    OEMCrypto_ERROR_EXCEED_MAX_NUM               = 10013,
    OEMCrypto_ERROR_NO_MEMORY                    = 10014,
    OEMCrypto_ERROR_LOGIC_WRONG                  = 10015,
    OEMCrypto_ERROR_ENTRY_NOT_FOUND              = 10016,
    OEMCrypto_ERROR_MALLOC_FAILED                = 10017,
    OEMCrypto_ERROR_HMAC_SHA1_FAILED             = 10019,
    OEMCrypto_ERROR_WRITE_ENCAP_KEYBOX           = 10020,
    OEMCrypto_ERROR_INSTALL_OEM_WRAPPED_KEYBOX   = 10021,
    // Attempt to play back through insecure HDMI output path
    OEMCrypto_ERROR_HDCP_NON_SECURE              = 10022,
    // Failed to read HDMI Status
    OEMCrypto_ERROR_HDMI_READ_FAIL               = 10023,
    OEMCrypto_ERROR_NONCE_FLOOD                  = 10024,
    OEMCrypto_ERROR_NO_DX_SUPPORT                = 10025,
    OEMCrypto_ERROR_QSEECOM_SEND_CMD             = 10026,
    OEMCrypto_ERROR_DELETE_KEYBOX_FAILED         = 10027,
    OEMCrypto_ERROR_FILE_DOES_NOT_EXIST          = 10028,
    OEMCrypto_ERROR_GET_FILE_SIZE                = 10029,
    OEMCrypto_ERROR_USAGE_TABLE_CORRUPTED        = 10030,
    OEMCrypto_ERROR_SET_BANDWIDTH                = 10031,
    OEMCrypto_ERROR_CE_PRNG_DATA                 = 10032,
    OEMCrypto_ERROR_FUSE_ACCESS                  = 10033,
    OEMCrypto_ERROR_RPMB_WRITE                   = 10034,
    OEMCrypto_ERROR_RPMB_READ                    = 10035,
    OEMCrypto_ERROR_RPMB_OPEN_PARTITION          = 10036,
    OEMCrypto_ERROR_RPMB_BAD_MAGIC               = 10037,
    OEMCrypto_ERROR_SFS_GET_FILE_SIZE            = 10038,
    OEMCrypto_ERROR_SFS_FILE_SEEK                = 10039,
    OEMCrypto_ERROR_GEN_DEVKEY                   = 10040,
    OEMCrypto_ERROR_GEN_SEVERKEY                 = 10041,
    OEMCrypto_ERROR_TIMESAFE_MEMCOPY             = 10042,
    OEMCrypto_ERROR_CIPHER_SET_PARAM             = 10043,
    OEMCrypto_ERROR_KEYID_LENGTH_WRONG           = 10044,
    OEMCrypto_ERROR_KEYID_DATA_WRONG             = 10045,
    OEMCrypto_ERROR_AES_CBC_DECRYPT              = 10046,
    OEMCrypto_ERROR_INTEGER_UNDERFLOW            = 10047,
    OEMCrypto_ERROR_SECPKCS8_PARSE               = 10048,
    OEMCrypto_ERROR_CIPHER_CTX_NULL              = 10049,
    OEMCrypto_ERROR_CRYPTO_CIPHER_INIT           = 10050,
    OEMCrypto_ERROR_CRYPTO_CIPHER_DEINIT         = 10051,
    OEMCrypto_ERROR_PKCS1_V1_5_INVALID_INPUT     = 10052,
    OEMCrypto_ERROR_PKCS1_V1_5_RSAKEY_WRONG      = 10053,
    OEMCrypto_ERROR_PKCS1_V1_5_SIGN              = 10054,
    OEMCrypto_ERROR_DER_FORMAT_WRONG             = 10055,
    OEMCrypto_ERROR_COPY_BUFFER_SEC_MEMORY       = 10056,
    OEMCrypto_ERROR_COPY_CLR_BUF_FAILED          = 10057,
    OEMCrypto_ERROR_COPY_SEC_BUF_LEN_TOO_LARGE   = 10058,
    OEMCrypto_ERROR_COPY_SEC_BUF_INT_OVERFLOW    = 10059,
    OEMCrypto_ERROR_COPY_SEC_BUF_CHK_SZ_NUM      = 10060,
    OEMCrypto_ERROR_COPY_SEC_BUF_TZBUF_INT       = 10061,
    OEMCrypto_ERROR_COPY_SEC_BUF_CACHE_REG       = 10062,
    OEMCrypto_ERROR_COPY_SEC_BUF_CACHE_DEREG     = 10063,
    OEMCrypto_ERROR_COPY_SEC_BUF_TZBUF_MEMCPY    = 10064,
    OEMCrypto_ERROR_COPY_SEC_BUF_COPY_LEN        = 10065,
    OEMCrypto_ERROR_QUERY_CTRL_KEY_ID_LEN        = 10066,
    OEMCrypto_ERROR_QUERY_CTRL_KEY_DATA_LEN      = 10067,
    OEMCrypto_ERROR_QUERY_CTRL_KEY_LEN_MISMATCH  = 10068,
    OEMCrypto_ERROR_GET_DEVKEY_MEMSCPY           = 10069,
    OEMCrypto_ERROR_INSTALL_KEYBOX_MEMSCPY       = 10070,
    OEMCrypto_ERROR_GET_DEVICE_ID_MEMSCPY        = 10071,
    OEMCrypto_ERROR_FORCE_DEL_ENTRY_MEMSCPY      = 10072,
    OEMCrypto_ERROR_HDCP_INPUT_POINTER_NULL      = 10073,
    OEMCrypto_ERROR_SFS_ANTI_ROLLBACK_CHECK      = 10074,
    OEMCrypto_ERROR_ANTI_ROLLBACK_BIT_MISMATCH   = 10075,
    OEMCrypto_ERROR_RSA_KEY_LOAD_FAILED          = 10076,
    OEMCrypto_ERROR_GET_SIGNING_KEY              = 10077,
    OEMCrypto_ERROR_GET_ENCRYPTION_KEY           = 10078,
    OEMCrypto_ERROR_HMAC_FAILED                  = 10079,
    OEMCrypto_ERROR_REPLAY_CTRL_WITH_NULL_PST    = 10080,
    OEMCrypto_ERROR_UNKNOW_PADDING_TYPE          = 10081,
    OEMCrypto_ERROR_RSA_SSAPSS_SIGN_INPUT        = 10082,
    OEMCrypto_ERROR_RSA_SSAPSS_SIGN_PARSING      = 10083,
    OEMCrypto_ERROR_RSA_SSAPSS_SIGN_INIT         = 10084,
    OEMCrypto_ERROR_RSA_SSAPSS_SIG_LENGTH        = 10085,
    OEMCrypto_ERROR_RSA_SSAPSS_HASH              = 10086,
    OEMCrypto_ERROR_RSA_SSAPSS_SIGH_HASH         = 10087,
    OEMCrypto_ERROR_RSA_OAEP_INPUT               = 10088,
    OEMCrypto_ERROR_RSA_OAEP_PARSING             = 10089,
    OEMCrypto_ERROR_RSA_OAEP_INIT                = 10090,
    OEMCrypto_ERROR_RSA_OAEP_LENGTH              = 10091,
    OEMCrypto_ERROR_RSA_OAEP_DECRYPT             = 10092,

    /*  Below are error codes from HLOS  */
    OEMCrypto_ERROR_HLOS_INPUT_INVALID           = 80001,
    OEMCrypto_ERROR_ION_VIRTUAL_POINTER_NULL     = 80002,
    OEMCrypto_ERROR_DATA_LENGTH_TOO_LARGE        = 80003,
    OEMCrypto_ERROR_KEY_ID_LENGTH_TOO_LARGE      = 80004,
    OEMCrypto_ERROR_INIT_MDP_IDLE_POWER_COLLAPSE = 80005,
    OEMCrypto_ERROR_SET_MDP_IDLE_POWER_COLLAPSE  = 80006,

    /*  End of error codes  */
    OEMCrypto_FAILURE = 0x7FFFFFFF
} OEMCryptoResult;

typedef   unsigned char   OEMCrypto_UINT8;
typedef   uint32_t	      OEMCrypto_UINT32;

typedef enum {
    OEMCrypto_BufferType_Clear = 0,
    OEMCrypto_BufferType_Secure,
    OEMCrypto_BufferType_Direct,
    OEMCrypto_BufferType_Unknown = 0x7FFFFFFF
} __attribute__ ((packed)) OEMCryptoBufferType;

typedef struct
{
    OEMCryptoBufferType type;
    union
    {
        struct      /* type == OEMCrypto_BufferType_Clear */
        {
            uint8_t  *address;
            size_t  max_length;
        } clear;
        struct      /* type == OEMCrypto_BufferType_Secure */
        {
            void   *handle;
            size_t  max_length;
            size_t  offset;
        } secure;
        struct      /* type == OEMCrypto_BufferType_Direct */
        {
            bool is_video;
        } direct;
    } buffer;
} OEMCrypto_DestBufferDesc;

/** OEMCryptoCipherMode is used in LoadKeys to prepare a key for either CTR
 * decryption or CBC decryption.
 */
    typedef enum OEMCryptoCipherMode {
    OEMCrypto_CipherMode_CTR,
    OEMCrypto_CipherMode_CBC,
    OEMCrypto_CipherMode_Unknown = 0x7FFFFFFF
    } __attribute__ ((packed)) OEMCryptoCipherMode;

typedef enum OEMCrypto_LicenseType
{
    OEMCrypto_ContentLicense = 0,
    OEMCrypto_EntitlementLicense = 1
}__attribute__((packed))OEMCrypto_LicenseType;

typedef struct
{
    uint8  *key_id;
    size_t  key_id_length;
    uint8  *key_data_iv;
    uint8  *key_data;
    size_t  key_data_length;
    uint8  *key_control_iv;
    uint8  *key_control;
}  __attribute__ ((packed))OEMCrypto_KeyObject;

typedef enum {
    OEMCrypto_AES_CBC_128_NO_PADDING = 0,
    OEMCrypto_HMAC_SHA256            = 1,
    OEMCrypto_UNKNOWN                = 0x7FFFFFFF
} __attribute__ ((packed)) OEMCrypto_Algorithm;

typedef struct
{
    uint8 *key_id;
    size_t key_id_length;
    uint8 *key_control_iv;
    uint8 *key_control;
} OEMCrypto_KeyRefreshObject;

typedef struct
{
   const uint8_t* entitlement_key_id;
   size_t entitlement_key_id_length;
   const uint8_t* content_key_id;
   size_t content_key_id_length;
   const uint8_t* content_key_data_iv;
   const uint8_t* content_key_data;
   size_t content_key_data_length;
} OEMCrypto_EntitledContentKeyObject;

/* OEMCrypto_PatternDesc
 *  This is used in OEMCrypto_DecryptCENC to indicate the encrypt/skip pattern
 *  used, as specified in the CENC standard.
 */
typedef struct {
    size_t encrypt;  // number of 16 byte blocks to decrypt.
    size_t skip;     // number of 16 byte blocks to leave in clear.
    size_t offset;   // offset into the pattern in blocks for this call.
} OEMCrypto_CENCEncryptPatternDesc;


/* PST Report structure */
typedef struct
{
    uint8   signature[20]; //  -- HMAC SHA1 of the rest of the report.
    uint8   status;  // current status of entry. (OEMCrypto_Usage_Entry_Status)
    uint8   clock_security_level;
    uint8   pst_length;
    uint8   padding;                         // make int64's word aligned.
    int64   seconds_since_license_received;  // now - time_of_license_received
    int64   seconds_since_first_decrypt;     // now - time_of_first_decrypt
    int64   seconds_since_last_decrypt;      // now - time_of_last_decrypt
    uint8   pst[MAX_PST_SIZE];
} __attribute__((packed)) OEMCrypto_PST_Report;

typedef enum RSA_Padding_Scheme {
    kSign_RSASSA_PSS     = 0x1, // RSASSA-PSS with SHA1.
    kSign_PKCS1_Block1   = 0x2, // PKCS1 with block type 1 padding (only).
} __attribute__ ((packed)) OEMCrypto_RSA_Padding_Scheme;

typedef enum OEMCrypto_ProvisioningMethod {
     OEMCrypto_ProvisioningError = 0,  // Device cannot be provisioned.
     OEMCrypto_DrmCertificate = 1,     // Device has baked in DRM certificate
				// (level 3 only)
     OEMCrypto_Keybox = 2,        // Device has factory installed unique keybox.
     OEMCrypto_OEMCertificate = 3 // Device has factory installed OEM certificate.
} OEMCrypto_ProvisioningMethod;

/*
*  OEMCrypto_Usage_Entry_Status.
*  Valid values for status in the usage table.
*/
typedef enum OEMCrypto_Usage_Entry_Status {
    kUnused = 0,
    kActive = 1,
    kInactive = 2,  // Deprecated.  Used kInactiveUsed or kInactiveUnused.
    kInactiveUsed = 3,
    kInactiveUnused = 4,
} OEMCrypto_Usage_Entry_Status;

typedef struct {
    uint8_t verification[8]; // must be "HDCPDATA"
    uint32_t minimum_srm_version; // version number in network byte order.
} __attribute__ ((packed))SRM_Restriction_Data;

typedef struct  {
    uint8_t signature[SHA256_DIGEST_LENGTH];
    uint8_t iv[SHA256_DIGEST_LENGTH];
    uint8_t verification[8];
    int64_t master_generation;
    uint64_t count;
} __attribute__ ((packed))SignedHeaderBlock_t;

// This is the data we store offline.
typedef struct  {
    int64_t generation_number;
    int64_t time_of_license_received;
    int64_t time_of_first_decrypt;
    int64_t time_of_last_decrypt;
    enum OEMCrypto_Usage_Entry_Status status;
    uint8_t mac_key_server[32];
    uint8_t mac_key_client[32];
    uint32_t index;
    uint8_t pst[MAX_PST_SIZE_V13];
    uint8_t pst_length;
} __attribute__ ((packed))StoredUsageEntry_t;

// A structure that holds an usage entry and its signature.
typedef struct  {
    uint8_t signature[SHA256_DIGEST_LENGTH];
    uint8_t iv[SHA256_DIGEST_LENGTH];
    uint8_t verification[8];
    StoredUsageEntry_t data;
} __attribute__ ((packed))SignedEntryBlock_t;

/*
 * OEMCrypto_HDCP_Capability is used in the key control block to enforce HDCP
 * level, and in GetHDCPCapability for reporting.
 */
 typedef enum OEMCrypto_HDCP_Capability {
    HDCP_NONE  = 0,               // No HDCP supported, no secure data path.
    HDCP_V1    = 1,               // HDCP version 1.0
    HDCP_V2    = 2,               // HDCP version 2.0 Type 1.
    HDCP_V2_1  = 3,               // HDCP version 2.1 Type 1.
    HDCP_V2_2  = 4,               // HDCP version 2.2 Type 1.
    HDCP_NO_DIGITAL_OUTPUT = 0xff // No digital output.
 } OEMCrypto_HDCP_Capability;

/**

  Encrypt and store firewalled, encapsulated keybox data to persistent memory.
  This function is used once to save the keybox onto the device
  at provisioning time. This keybox cannot be retrieved after it
  has been stored.

  @return
  OEMCrypto_SUCCESS                    - Success.
  OEMCrypto_ERROR_WRITE_ENCAP_KEYBOX   - Failure.

  @param[in]      *encapKeybox     Pointer to encapsulated keybox data
  @param[in]       keyboxLength    Length of the encapsulated keybox data in bytes


  @dependencies
  The application that is used to encapsulate the keybox MUST be open and MUST
  be the same instance when using this function. I.E., you cannot close the
  application that encapsulated the key until this function is called, in order
  for the decapsulation to work.

  @sideeffects

  None
*/
OEMCryptoResult OEMCrypto_InstallEncapKeybox( OEMCrypto_UINT8 *encapKeybox, size_t keyboxLength );

/**

  Encrypt and store firewalled keybox data that has been wrapped
  by the OEM API to persistent memory. This function is used once
  to save the keybox onto the device at provisioning time.
  This keybox cannot be retrieved after it has been stored.

  @return
  OEMCrypto_SUCCESS              - Success.
  OEMCrypto_ERROR_WRITE_KEYBOX   - Failure.

  @param[in]    *wrappedKeybox     Pointer to clear keybox data
  @param[in]     keyboxLength    Length of the keybox data in bytes


  @dependencies
  None

  @sideeffects

  None
*/
OEMCryptoResult OEMCrypto_InstallOEMWrappedKeybox( OEMCrypto_UINT8 *wrappedKeybox, size_t keyboxLength );

/**
  Deletes previously installed keybox; This API is a utiliy provided by QC
  and not part of Widevine defined APIs

  @return
  OEMCrypto_SUCCESS   - Success.
  OEMCrypto_FAILURE   - Failure.

  @param
  None

  @dependencies
  None

  @sideeffects
  None
*/
OEMCryptoResult QC_OEMCrypto_Dash_Delete_Keybox(void);

OEMCryptoResult OEMCrypto_Initialize(void);

OEMCryptoResult OEMCrypto_Terminate(void);

OEMCryptoResult OEMCrypto_InstallKeybox( OEMCrypto_UINT8 *clearKeybox, size_t keyboxLength );

OEMCryptoResult OEMCrypto_GetKeyData( OEMCrypto_UINT8 *keyData, size_t *keyDataLength );

OEMCryptoResult OEMCrypto_IsKeyboxValid(void);

OEMCryptoResult OEMCrypto_GetRandom( OEMCrypto_UINT8 *randomData, size_t dataLength);

OEMCryptoResult OEMCrypto_GetDeviceID( OEMCrypto_UINT8 *deviceID, size_t *idLength );

OEMCryptoResult OEMCrypto_WrapKeybox(OEMCrypto_UINT8 *keybox,
                                     size_t keyBoxLength,
                                     OEMCrypto_UINT8 *wrappedKeybox,
                                     size_t *wrappedKeyBoxLength,
                                     OEMCrypto_UINT8 *transportKey,
                                     size_t transportKeyLength);

OEMCryptoResult OEMCrypto_OpenSession(OEMCrypto_SESSION   *session);

OEMCryptoResult OEMCrypto_CloseSession(OEMCrypto_SESSION  session);

OEMCryptoResult OEMCrypto_GenerateDerivedKeys(  OEMCrypto_SESSION session,
                                                uint8 *mac_key_context,
                                                uint32 mac_key_context_length,
                                                uint8 *enc_key_context,
                                                uint32 enc_key_context_length);

OEMCryptoResult OEMCrypto_GenerateSignature(OEMCrypto_SESSION  session,
                                            uint8  *message,
                                            size_t  message_length,
                                            uint8  *signature,
                                            size_t *signature_length);

OEMCryptoResult OEMCrypto_GenerateNonce(OEMCrypto_SESSION session,
                                        uint32 *nonce);

OEMCryptoResult OEMCrypto_RefreshKeys(	OEMCrypto_SESSION  session,
                                        uint8  *message,
                                        size_t  message_length,
                                        uint8  *signature,
                                        size_t  signature_length,
                                        size_t  num_keys,
                                        const OEMCrypto_KeyRefreshObject *key_control);

OEMCryptoResult OEMCrypto_RewrapDeviceRSAKey(   OEMCrypto_SESSION session,
                                                const uint8* message,
                                                size_t  message_length,
                                                const   uint8* signature,
                                                size_t  signature_length,
                                                uint32 *nonce,
                                                const uint8* enc_rsa_key,
                                                size_t  enc_rsa_key_length,
                                                const uint8* enc_rsa_key_iv,
                                                uint8  *wrapped_rsa_key,
                                                size_t *wrapped_rsa_key_length);

OEMCryptoResult OEMCrypto_LoadDeviceRSAKey(	OEMCrypto_SESSION session,
                                            const uint8 *wrapped_rsa_key,
                                            size_t wrapped_rsa_key_length);

OEMCryptoResult OEMCrypto_DeriveKeysFromSessionKey( OEMCrypto_SESSION session,
                                                    const uint8* enc_session_key,
                                                    size_t enc_session_key_length,
                                                    const uint8 *mac_key_context,
                                                    size_t mac_key_context_length,
                                                    const uint8 *enc_key_context,
                                                    size_t enc_key_context_length);

uint32 OEMCrypto_APIVersion();

const char* OEMCrypto_SecurityLevel();

OEMCryptoResult OEMCrypto_Generic_Encrypt(  OEMCrypto_SESSION session,
                                            const uint8 *in_buffer,
                                            size_t  buffer_length,
                                            const uint8 *iv,
                                            OEMCrypto_Algorithm algorithm,
                                            uint8 *out_buffer);

OEMCryptoResult OEMCrypto_Generic_Decrypt(  OEMCrypto_SESSION session,
                                            const uint8 *in_buffer,
                                            size_t  buffer_length,
                                            const uint8 *iv,
                                            OEMCrypto_Algorithm algorithm,
                                            uint8  *out_buffer);

OEMCryptoResult OEMCrypto_Generic_Sign(OEMCrypto_SESSION session,
                                       const uint8 *in_buffer,
                                       size_t buffer_length,
                                       OEMCrypto_Algorithm algorithm,
                                       uint8  *signature,
                                       size_t *signature_length);

OEMCryptoResult OEMCrypto_Generic_Verify(   OEMCrypto_SESSION session,
                                            const uint8 * in_buffer,
                                            size_t buffer_length,
                                            OEMCrypto_Algorithm algorithm,
                                            const uint8  *signature,
                                            size_t  signature_length);

bool OEMCrypto_SupportsUsageTable();

OEMCryptoResult OEMCrypto_UpdateUsageTable();

OEMCryptoResult OEMCrypto_ReportUsage(  OEMCrypto_SESSION session,
                                        const uint8 *pst,
                                        size_t pst_length,
                                        OEMCrypto_PST_Report *buffer,
                                        size_t *buffer_length);

OEMCryptoResult OEMCrypto_DeleteUsageEntry( OEMCrypto_SESSION session,
                                            const uint8 * pst,
                                            size_t pst_length,
                                            const uint8 *message,
                                            size_t message_length,
                                            const uint8 *signature,
                                            size_t signature_length);

OEMCryptoResult OEMCrypto_DeleteUsageTable();

OEMCryptoResult OEMCrypto_GenerateRSASignature( OEMCrypto_SESSION session,
                                                const uint8 *message,
                                                size_t  message_length,
                                                uint8  *signature,
                                                size_t *signature_length,
                                                OEMCrypto_RSA_Padding_Scheme  padding_scheme);

OEMCryptoResult OEMCrypto_GetMaxNumberOfSessions(size_t *max);

OEMCryptoResult OEMCrypto_GetNumberOfOpenSessions(size_t *count);

bool OEMCrypto_IsAntiRollbackHwPresent(void);

OEMCryptoResult OEMCrypto_CopyBuffer(const uint8_t *data_addr,
                                     size_t data_length,
                                     OEMCrypto_DestBufferDesc* out_buffer,
                                     uint8_t subsample_flags);

OEMCryptoResult OEMCrypto_QueryKeyControl(OEMCrypto_SESSION session,
                                          const uint8_t* key_id,
                                          size_t key_id_length,
                                          uint8_t* key_control_block,
                                          size_t* key_control_block_length);

OEMCryptoResult OEMCrypto_ForceDeleteUsageEntry(const uint8_t* pst,
                                                size_t pst_length);

OEMCryptoResult OEMCrypto_GetHDCPCapability(OEMCrypto_HDCP_Capability *current,
                                            OEMCrypto_HDCP_Capability *maximum);

OEMCryptoResult OEMCrypto_LoadTestRSAKey(void);

OEMCrypto_UINT8 OEMCrypto_Security_Patch_Level();

OEMCryptoResult OEMCrypto_DecryptCENC(  OEMCrypto_SESSION   session,
                                        uint8               *data_addr,
                                        size_t              data_length,
                                        bool                is_protected,
                                        uint8               *iv,
                                        size_t              block_offset,
                                        OEMCrypto_DestBufferDesc  *out_buffer,
                                        OEMCrypto_CENCEncryptPatternDesc *pattern,
                                        uint8               subsample_flags);

OEMCrypto_ProvisioningMethod OEMCrypto_GetProvisioningMethod();

OEMCryptoResult OEMCrypto_GetOEMPublicCertificate(OEMCrypto_SESSION session,
                                                  uint8_t* public_cert,
                                                  size_t* public_cert_length);

OEMCryptoResult OEMCrypto_RewrapDeviceRSAKey30( OEMCrypto_SESSION session,
                                                const uint32_t* nonce,
                                                const uint8_t* encrypted_message_key,
                                                size_t encrypted_message_key_length,
                                                const uint8_t* enc_rsa_key,
                                                size_t enc_rsa_key_length,
                                                const uint8_t* enc_rsa_key_iv,
                                                uint8_t* wrapped_rsa_key,
                                                size_t* wrapped_rsa_key_length);

uint32_t OEMCrypto_SupportedCertificates();

bool OEMCrypto_IsSRMUpdateSupported();

OEMCryptoResult OEMCrypto_GetCurrentSRMVersion(uint16_t* version);

OEMCryptoResult OEMCrypto_LoadSRM(const uint8_t* buffer, size_t buffer_length);

OEMCryptoResult OEMCrypto_RemoveSRM();

OEMCryptoResult OEMCrypto_CreateUsageTableHeader(   uint8_t* header_buffer,
                                                    size_t* header_buffer_length);

OEMCryptoResult OEMCrypto_LoadUsageTableHeader( const uint8_t* buffer,
                                                size_t buffer_length);

OEMCryptoResult OEMCrypto_CreateNewUsageEntry(  OEMCrypto_SESSION session,
                                                uint32_t* usage_entry_number);

OEMCryptoResult OEMCrypto_LoadUsageEntry(   OEMCrypto_SESSION session,
                                            uint32_t index,
                                            const uint8_t* buffer,
                                            uint32_t buffer_size);

OEMCryptoResult OEMCrypto_UpdateUsageEntry( OEMCrypto_SESSION session,
                                            uint8_t* header_buffer,
                                            size_t* header_buffer_length,
                                            uint8_t* entry_buffer,
                                            size_t* entry_buffer_length);

OEMCryptoResult OEMCrypto_DeactivateUsageEntry(OEMCrypto_SESSION session,
                                               const uint8_t* pst,
                                               size_t pst_length);

OEMCryptoResult OEMCrypto_ShrinkUsageTableHeader(uint32_t new_entry_count,
                                                 uint8_t* header_buffer,
                                                 size_t* header_buffer_length);

OEMCryptoResult OEMCrypto_MoveEntry(OEMCrypto_SESSION session,
                                    uint32_t new_index);

OEMCryptoResult OEMCrypto_CopyOldUsageEntry(OEMCrypto_SESSION session,
                                            const uint8_t*pst,
                                            size_t pst_length);

OEMCryptoResult OEMCrypto_CreateOldUsageEntry(uint64_t time_since_license_received,
                                              uint64_t time_since_first_decrypt,
                                              uint64_t time_since_last_decrypt,
                                              OEMCrypto_Usage_Entry_Status status,
                                              uint8_t *server_mac_key,
                                              uint8_t *client_mac_key,
                                              const uint8_t* pst,
                                              size_t pst_length);

OEMCryptoResult OEMCrypto_GetAnalogOutputFlags();

OEMCryptoResult OEMCrypto_LoadTestKeybox(const uint8 *buffer, size_t buffer_length);

OEMCryptoResult OEMCrypto_LoadEntitledContentKeys(OEMCrypto_SESSION session,
                                                  uint32 num_keys,
                                                  OEMCrypto_EntitledContentKeyObject* key_array);

OEMCryptoResult OEMCrypto_SelectKey(OEMCrypto_SESSION  session,
                                    uint8             *key_id,
                                    uint16             key_id_len,
                                    OEMCryptoCipherMode cipher_mode);

OEMCryptoResult OEMCrypto_LoadKeys (OEMCrypto_SESSION   session,
                                    const uint8         *message,
                                    size_t              message_length,
                                    const uint8         *signature,
                                    size_t              signature_length,
                                    const uint8         *enc_mac_key_iv,
                                    const uint8         *enc_mac_key,
                                    size_t              num_keys,
                                    OEMCrypto_KeyObject *key_array,
                                    const uint8         *pst,
                                    size_t              pst_length,
                                    const uint8_t*      srm_requirement,
                                    OEMCrypto_LicenseType license_type);

#ifdef __cplusplus
}
#endif

#endif //WV_OEMC_DASH_CLNT_H
