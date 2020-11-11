#ifndef __ACDB_API_H__
#define __ACDB_API_H__
/*===========================================================================*/
/**
    @file   acdb.h

    This file contains the public interface to the Audio Calibration Database
    (ACDB) module.

    The public interface of the Audio Calibration Database (ACDB) module,
    providing calibration storage for the audio and the voice path. The ACDB
    module is coupled with QACT.
    Qualcomm Technologies Inc recommends to always use the latest version of QACT for
    necessary fixes and compatibility.
*/
/*===========================================================================
      NOTE: The description above does not appear in the PDF.

      The acdb_mainpage.dox file contains all file/group descriptions that are
      in the output PDF generated using Doxygen and Latex. To edit or update
      any of the file/group text in the PDF, edit the acdb_mainpage.dox file
      (contact Tech Pubs).
===========================================================================*/

/*===========================================================================
	Copyright (c) 2010-2018 Qualcomm Technologies, Inc.
	All Rights Reserved.
	Confidential and Proprietary - Qualcomm Technologies, Inc.
========================================================================== */
/* $Header: //source/qcom/qct/multimedia2/Audio/audcal4/
			acdb_sw/main/latest/acdb/inc/acdb.h#24 $ */

/*===========================================================================

EDIT HISTORY FOR FILE

This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.

when       who      what, where, why
--------   ---      ----------------------------------------------------------
1/24/2017 mahadev   Removed ACDB S/W warnings and updated copyright year to 2017.
1/24/2017 mahadev   Added AFE_Sidetone commands.
09/14/2016 San      Added new Codec Path ID for WCD9340.
12/24/2015 San      Added new Codec Path ID for MSM8X53 (Diangu).
09/14/2015 San      Added support for ACDB_CMD_GET_ACDB_SW_VERSION_V3 command.
08/14/2015 naveenv  Added support for VBAT.
06/30/2015 bhargav  Added new Codec Path ID for WCD9326 Codec.
06/29/2015 mahadev  Added support for AVCS custom topology
06/15/2015 mahadev  Updated WCD9335 ANC structure to reflect name change
06/12/2015 mahadev  Updated WCD9335 ANC structure to include new fields
04/06/15	San		Added new Codec Path ID for MSM8X52(Cajon) and WCD9335(Tasha) Codec.
08/05/14   avi      Support commands for AFE/LSM custom topologies.
05/28/14	mh		Updated some structure as a packed structure to avoid alignment issues
04/16/14   San      Added New ACDB Tuning Parameters for TomTom and TomBak for Windows.
04/04/14   San      Added ACDB_CMD_GET_META_INFO_SIZE and ACDB_CMD_GET_META_INFO commands.
03/14/14   Ram      Added new param ID for MSM8X16 Codec and Tomtom
02/17/14   Ram      Added new param ID for MBHC module and support for MSM8X16 Codec
02/14/14   avi      Support ACDB_CMD_SET_AUDPROC_COMMON_TABLE and ACDB_CMD_SET_AUDPROC_STREAM_TABLE_V2 commands.
09/30/13   avi      Added new API for querying ACDB SW version from 3.x package onwards.
09/30/13   avi      Support Fluence VP3 interfaces
09/11/13   mh       Added new param IDs for MBHC module
07/18/13   mh       Added new commands for getting device property and its size
06/07/13   avi      Support Voice Volume boost feature
06/07/13   mh       Corrected checkpatch errors
05/24/13   mh       Added support for WCD9302 codec
05/13/13   mh       Added support for MSM8x10 codec
04/03/13   avi      Added support for WCD9306 codec
01/14/13   leo      (Tech Pubs) Edited/added Doxygen comments and markup.
06/27/12   naveenv  1. Deleted voice API's which no longer hold good.
					2. Deprecated unused API's
					3. Introduced new voice ACDB API's and few other API's.
===========================================================================*/

/* ---------------------------------------------------------------------------
 * Include Files
 *--------------------------------------------------------------------------- */

#include "acdb_os_includes.h"

/* ---------------------------------------------------------------------------
 * Preprocessor Definitions and Constants
 *--------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------
 * Type Declarations
 *--------------------------------------------------------------------------- */

#define ACDB_FILENAME_MAX_CHARS 256

/** @addtogroup acdb_datatypes
@{ */

/** Return codes from the ACDB commands. Each command returns a specific set of
    these return codes. Refer to the documentation for each command's possible
    return codes.
 */
typedef enum AcdbReturnCodes {
   ACDB_SUCCESS = 0,                   /**< General success. */
   ACDB_ERROR = -1,                    /**< General failure. */
   ACDB_BADPARM = -2,                  /**< Bad parameter was given. */
   ACDB_BADSTATE = -3,                 /**< ACDB is in a bad state. */
   ACDB_DEVICENOTFOUND = -4,           /**< Device ID was not found. */
   ACDB_SAMPLERATENOTFOUND = -5,       /**< Sample rate ID was not found. */
   ACDB_NETWORKNOTFOUND = -6,          /**< Network ID was not found. */
   ACDB_MODULENOTFOUND = -7,           /**< Module ID was not found. */
   ACDB_PARMNOTFOUND = -8,             /**< Parameter ID was not found. */
   ACDB_APPLICATIONTYPENOTFOUND = -9,  /**< Application type ID was not found. */
   ACDB_CODECPATHNOTFOUND = -10,       /**< Codec path ID was not found. */
   ACDB_CODECSAMPLERATENOTFOUND = -11, /**< Codec sample rate ID was not found. */
   ACDB_INSUFFICIENTMEMORY = -12,      /**< Insufficient memory was allocated
											for this operation. */
   ACDB_NOTSUPPORTED = -13,            /**< Command is not supported. */
   ACDB_NULLPOINTER = -14,             /**< NULL pointer was encountered. */
   ACDB_MISMATCH_TARGET_VERSION = -15, /**< Target version in AcdbData and Acdb
										are mismatched. Occurs only at
										initialization. */
   ACDB_MISMATCH_DATA_SW_VERSION = -16,/**< AcdbData Data Structure version in
										AcdbData and Acdb are mismatched.
										Occurs only at initialization. */
   ACDB_VOLUME_STEP_NOT_FOUND = -17,   /**< Volume step is not available. */
   ACDB_DATA_NOT_FOUND = -18,            /**< Data was not found for the specified
										set of input parameters. */
   ACDB_INPUT_PARAMS_NOT_FOUND = -19,   /**< Provided input parameters were not
										found. */
   ACDB_DATA_INTERFACE_NOT_FOUND = -20, /**< Specific data not available in ACDB files
											found. */
}AcdbReturnCodesType;

/** Application type IDs expected to query the audio table.
 */
typedef enum AcdbApplicationTypeIds {
   ACDB_APPTYPE_GENERAL_PLAYBACK  = 0x00011130,
     /**< Queries for general audio playback calibration for Rx audio devices. */
   ACDB_APPTYPE_SYSTEM_SOUNDS     = 0x00011131,
     /**< Queries for system sounds calibration for Rx audio devices. */
   ACDB_APPTYPE_GENERAL_RECORDING = 0x00011132,
     /**< Queries for general audio recording calibration for Tx audio devices. */
   ACDB_APPTYPE_VOICE_RECOGNITION = 0x00011133,
     /**< Queries for voice recognition calibration for Tx audio devices. */
}AcdbApplicationTypeIdsType;

/** Possible sample rates for a specific device.
 */
typedef enum AcdbSampleRateMask {
   ACDB_SAMPLERATE_8000Hz  = 0x0001,
     /**< Used if the AFE supports running at 8000 Hz. */
   ACDB_SAMPLERATE_11025Hz = 0x0002,
     /**< Used if the AFE supports running at 11025 Hz. */
   ACDB_SAMPLERATE_12000Hz = 0x0004,
     /**< Used if the AFE supports running at 12000 Hz. */
   ACDB_SAMPLERATE_16000Hz = 0x0008,
     /**< Used if the AFE supports running at 16000 Hz. */
   ACDB_SAMPLERATE_22050Hz = 0x0010,
     /**< Used if the AFE supports running at 22050 Hz. */
   ACDB_SAMPLERATE_24000Hz = 0x0020,
     /**< Used if the AFE supports running at 24000 Hz. */
   ACDB_SAMPLERATE_32000Hz = 0x0040,
     /**< Used if the AFE supports running at 32000 Hz. */
   ACDB_SAMPLERATE_44100Hz = 0x0080,
     /**< Used if the AFE supports running at 44100 Hz. */
   ACDB_SAMPLERATE_48000Hz = 0x0100,
     /**< Used if the AFE supports running at 48000 Hz. */
   ACDB_SAMPLERATE_96000Hz  = 0x0200,
     /**< Used if the AFE supports running at 96000 Hz. */
	ACDB_SAMPLERATE_192000Hz = 0x0400,
     /**< Used if the AFE supports running at 192000 Hz. */
	ACDB_SAMPLERATE_88200Hz = 0x0800,
     /**< Used if the AFE supports running at 88200 Hz. */
   ACDB_SAMPLERATE_176400Hz = 0x1000,
     /**< Used if the AFE supports running at 176400 Hz. */
	 ACDB_SAMPLERATE_352800Hz = 0x2000,
     /**< Used if the AFE supports running at 352800 Hz. */
	 ACDB_SAMPLERATE_384000Hz = 0x4000,
     /**< Used if the AFE supports running at 384000 Hz. */
}AcdbSampleRateMaskType;

/** Possible channel configuration choices.
 */
typedef enum AcdbChannelConfig {
   ACDB_CHANNEL_NONE       = 0x00,        /**< Channel = 0. */
   ACDB_CHANNEL_MONO       = 0x01,        /**< Mono. */
   ACDB_CHANNEL_STEREO     = 0x02,        /**< Stereo. */
   ACDB_CHANNEL_3CHANNELS  = 0x03,        /**< 3 channels. */
   ACDB_CHANNEL_4CHANNELS  = 0x04,        /**< 4 channels. */
   ACDB_CHANNEL_5CHANNELS  = 0x05,        /**< 5 channels. */
   ACDB_CHANNEL_6CHANNELS  = 0x06,        /**< 6 channels. */
   ACDB_CHANNEL_7CHANNELS  = 0x07,        /**< 7 channels. */
   ACDB_CHANNEL_8CHANNELS  = 0x08,        /**< 8 channels. */
   ACDB_CHANNEL_9CHANNELS  = 0x09,        /**< 9 channels. */
   ACDB_CHANNEL_10CHANNELS = 0x0A,        /**< 10 channels. */
   ACDB_CHANNEL_11CHANNELS = 0x0B,        /**< 11 channels. */
   ACDB_CHANNEL_12CHANNELS = 0x0C,        /**< 12 channels. */
   ACDB_CHANNEL_13CHANNELS = 0x0D,        /**< 13 channels. */
   ACDB_CHANNEL_14CHANNELS = 0x0E,        /**< 14 channels. */
   ACDB_CHANNEL_15CHANNELS = 0x0F,        /**< 15 channels. */
   ACDB_CHANNEL_16CHANNELS = 0x10,        /**< 16 channels. */
   ACDB_CHANNEL_17CHANNELS = 0x11,        /**< 17 channels. */
   ACDB_CHANNEL_18CHANNELS = 0x12,        /**< 18 channels. */
   ACDB_CHANNEL_19CHANNELS = 0x13,        /**< 19 channels. */
   ACDB_CHANNEL_20CHANNELS = 0x14,        /**< 20 channels. */
   ACDB_CHANNEL_21CHANNELS = 0x15,        /**< 21 channels. */
   ACDB_CHANNEL_22CHANNELS = 0x16,        /**< 22 channels. */
   ACDB_CHANNEL_23CHANNELS = 0x17,        /**< 23 channels. */
   ACDB_CHANNEL_24CHANNELS = 0x18,        /**< 24 channels. */
   ACDB_CHANNEL_25CHANNELS = 0x19,        /**< 25 channels. */
   ACDB_CHANNEL_26CHANNELS = 0x1A,        /**< 26 channels. */
   ACDB_CHANNEL_27CHANNELS = 0x1B,        /**< 27 channels. */
   ACDB_CHANNEL_28CHANNELS = 0x1C,        /**< 28 channels. */
   ACDB_CHANNEL_29CHANNELS = 0x1D,        /**< 29 channels. */
   ACDB_CHANNEL_30CHANNELS = 0x1E,        /**< 30 channels. */
   ACDB_CHANNEL_31CHANNELS = 0x1F,        /**< 31 channels. */
   ACDB_CHANNEL_32CHANNELS = 0x20,        /**< 32 channels. */
}AcdbChannelConfigType;

/** Possible directions to expect in the ACDB device information's
   ulDirectionMask field.
 */
typedef enum AcdbDirectionMask {
   ACDB_DIRECTION_RX       = 0x01,        /**< Determines if a device is an
                                               Rx device. */
   ACDB_DIRECTION_TX       = 0x02,        /**< Determines if a device is a
                                               Tx device. */
   ACDB_DIRECTION_AUXPGA   = 0x04,        /**< Determines if a device is an
                                               AUXPGA device. */
}AcdbDirectionMaskType;

/** Possible I2S clock configuration choices.
 */
typedef enum AcdbI2sMClkMode {
   ACDB_I2SMSMODE_MLCK_MSTR    = 0x0,        /**< Master clock master. */
   ACDB_I2SMSMODE_MLCK_SLAVE   = 0x01,       /**< Master clock slave. */
}AcdbI2sMClkModeType;

/** Enumeration for the AFE bytes per sample.
 */
typedef enum AcdbAfeBytesPerSample {
   ACDB_BPS_16BIT_PCM   = 0x00000001, /**< 16-bit PCM. */
   ACDB_BPS_24BIT_PCM   = 0x00000002, /**< 24-bit PCM. */
   ACDB_BPS_32BIT_PCM   = 0x00000004, /**< 32-bit PCM. */
}AcdbAfeBytesPerSampleType;

/** AFE channel modes available for HDMI ports.
 */
typedef enum AcdbAfeChannelModeHDMI {
   ACDB_CHMODE_HDMI_STEREO    = 0x00000000, /**< Stereo. */
   ACDB_CHMODE_HDMI_3_1       = 0x00000001, /**< 3.1 speakers. */
   ACDB_CHMODE_HDMI_5_1       = 0x00000002, /**< 5.1 speakers. */
   ACDB_CHMODE_HDMI_7_1       = 0x00000003, /**< 7.1 speakers. */
}AcdbAfeChannelModeHDMIType;

/** Enumeration of voice table types.
 */
typedef enum AcdbVoiceTblType {
   ACDB_VOC_PROC_TABLE = 0x00000001,        /**< VocProc table. */
   ACDB_VOC_PROC_VOL_TABLE =0x00000002,     /**< VocProc gain-dependent volume table. */
   ACDB_VOC_STREAM_TABLE = 0x00000003,      /**< Voice stream table. */
} AcdbVoiceTblType;
/** Enumeration of voice table types.
*/
typedef enum AcdbVoiceTblType_v2 {
	ACDB_VOC_PROC_TABLE_V2 = 0x00000001, /**< VocProc table. */
	ACDB_VOC_PROC_VOL_TABLE_V2 =0x00000002, /**< VocProc gain-dependent volume table. */
	ACDB_VOC_STREAM_TABLE_V2 = 0x00000003, /**< Voice stream table. */
	ACDB_VOC_PROC_DYN_TABLE_V2 = 0x00000004, /**< VocProc Dynamic table. */
	ACDB_VOC_PROC_STAT_TABLE_V2 =0x00000005, /**< VocProc static table */
	ACDB_VOC_STREAM2_TABLE_V2 = 0x00000006, /**< Voice stream2 table. */
	ACDB_VOC_PROC_DYN_ISNTANCE_TABLE = 0x00000007, /**< Voice instance dynamic table */
	ACDB_VOC_PROC_STAT_INSTANCE_TABLE = 0x00000008, /**< Voice instance static table */
	ACDB_VOC_PROC_STREAM_INSTANCE_TABLE = 0x00000009, /**< Voice stream instance table */
} AcdbVoiceTblType_v2;
/** Enumeration of the features that are supported by the devices.
 */
typedef enum _AcdbDevSupportedFeatureType {
   ACDB_FEEDBACK_SPEAKERPROTECTION_RX = 0x00000001,
     /**< The Rx device supports the feedback speaker protection feature. */
   ACDB_FEEDBACK_SPEAKERPROTECTION_TX = 0x00000002,
     /**< The Tx device supports the feedback speaker protection feature. */
   ACDB_ADAPTIVE_ANC_RX = 0x00000003,
     /**< The Rx device which supports the Adaptive ANC feature. */
   ACDB_LOW_POWER_LISTEN = 0x00000004,
     /**< The device supports the low power listen feature. */
   ACDB_HIGH_POWER_LISTEN = 0x00000005,
     /**< The device supports the high power listen feature. */
} AcdbDevSupportedFeatureType;

/** Enumeration of the types of device pairs.
 */
typedef enum _AcdbDevPairListType {
   ACDB_FEEDBACK_SPEAKERPROTECTION_RX2TX_LIST = 0x00000001,
     /**< Feedback speaker protection device pairs (Rx-Tx). */
   ACDB_VOICE_TX2RX_LIST = 0x00000002,
     /**< Voice device pairs (Tx-Rx). */
   ACDB_ANC_RX2TX_LIST = 0x00000003,
     /**< ANC device pairs (Rx-Tx). */
   ACDB_NATIVE_REMOTE_MAP_LIST = 0x00000004,
     /**< Compatible device pairs across the applications and MDM devices (Rx-Rx or Tx-Tx). */
   ACDB_AUDIO_RECORD_TX2RX_LIST = 0x00000005,
     /**< Device pairs for audio record using Echo Cancellation (EC) (Tx-Rx). */
   ACDB_ADAPTIVE_ANC_RX2TX_LIST = 0x00000006,
     /**< Adaptive ANC device pairs (Rx-Tx). */
   ACDB_AUDIOEC_TX2ANY_LIST = 0x00000007,
   /**< Audio EC TX to any device pair. */

} AcdbDevPairListType;

/** Specifies the feature based on the codec type.
 */
typedef enum _AcdbCodecFeatureType {
   ACDB_WCD9320_MAD = 0x00012E13,    /**< MAD feature on codec WCD9320. */
} AcdbCodecFeatureType;

/** MUX type options available for a PCM device type.
 */
typedef enum _AcdbPCMMuxType {
   ACDB_MUX1    = 0x00000001,        /**< MUX type 1. */
   ACDB_MUX2    = 0x00000002,        /**< MUX type 2. */
   ACDB_MUX3    = 0x00000003,        /**< MUX type 3. */
   ACDB_MUX4    = 0x00000004         /**< MUX type 4. */
}AcdbPCMMuxType;

/** Enumeration of the types of device properties.
 */
typedef enum _AcdbDevPropertyType {
   ACDB_AVSYNC_INFO = 0x00000001,
   /**< Device property which provides AV Sync delay info.\n
   The expected data format for this property is: \n
   @code
    struct AVSyncDelay
    {
       uint32_t nNoOfEntries;    // Number of entries
       DelayEntry *pInfo;       // Array of DelayEntry structure of size nNoOfEntries
    }
    struct DelayEntry
    {
       uint32_t        nSampleRate;
       uint32_t        nDelayInMicroSec;
    }
   @endcode
   */
   ACDB_CHANNEL_MAPPING_CONFIG = 0x00000002,
   /**< Device property which provides Channel mapping config info.\n
   The expected data format for this property is: \n
   @code
    struct ChannelTypeConfig
    {
       uint32_t channelTypeConfig[8];    // channel type config.
    }
   @endcode
   */

	ACDB_CHANNEL_MAPPING_CONFIG_V2 = 0x00000003,
   /**< Device property which provides 32-Channel mapping config info.\n
   The expected data format for this property is: \n
   @code
    struct ChannelTypeConfig
    {
       uint32_t channelTypeConfig[32];    // channel type config.
    }
   @endcode
   */


	ACDB_DEVICE_TYPE_TDM_SLOT_CONFIG_V2_PARAM = 0x0001319F,
	/**
	@ ACDB_DEVICE_TYPE_TDM_SLOT_CONFIG_V2_PARAM
	TDMA SLOT configuration param Version 2 to assign a slot to TDM device types sync support.
	please refer to the afe header afe_param_id_slot_mapping_cfg_t for payload format
	*/


	ACDB_DEVICE_TYPE_GROUP_TDM_CONFIG_PARAM = 0x000131EA,
	/**
	@ ACDB_DEVICE_TYPE_GROUP_TDM_CONFIG_PARAM
	Group tdm config param type used to group tdm device types , please refer to the afe header afe_param_id_group_device_tdm_cfg_t for payload format
	*/

	ACDB_DEVICE_TYPE_TDM_SLOT_CONFIG_V2_PARAM_V2 = 0x00013337,
	/**
	@ ACDB_DEVICE_TYPE_TDM_SLOT_CONFIG_V2_PARAM_V2
	TDMA SLOT configuration param Version 2 to assign a slot to TDM device types sync support.
	please refer to the afe header afe_param_id_slot_mapping_cfg_t for payload format
	*/

	ACDB_DEVICE_TYPE_GROUP_I2S_CONFIG_PARAM = 0x00013344,
	/**
	@ ACDB_DEVICE_TYPE_GROUP_I2S_CONFIG_PARAM
	Group I2S config param type used to group I2S device types , please refer to the afe header afe_param_id_group_device_i2s_cfg_v1_t for payload format
	*/

	ACDB_DEVICE_TYPE_I2S_SLOT_CONFIG = 0x0001333F,
   /**
	@ ACDB_DEVICE_TYPE_I2S_SLOT_CONFIG
	I2S SLOT configuration param  to assign a slot to I2S device types sync support.
	please refer to the afe header afe_param_id_slot_mapping_cfg_t for payload format
	*/
} AcdbDevPropertyType;

typedef struct _AcdbQueryCmdType AcdbQueryCmdType;
#include "acdb_begin_pack.h"

/** Generic query structure.
*/
struct _AcdbQueryCmdType {
   uint32_t nBufferLength;           /**< Buffer length. */
   uint8_t* pBufferPointer;          /**< Point to the query buffer. */
}
#include "acdb_end_pack.h"
;

/** Generic query command response structure.
 */
typedef struct _AcdbQueryResponseType {
   uint32_t nBytesUsedInBuffer;      /**< Bytes used in the output buffer
                                          initially provided in the command
                                          structure. */
} AcdbQueryResponseType;

/** Generic size query command response structure for the size
    of any table or data command.
*/
typedef struct _AcdbSizeResponseType {
   uint32_t nSize;                   /**< Size of the table or data command.
                                          @newpagetable */
} AcdbSizeResponseType;

/** Specifies the default feature id value of the voice volume table.
 */
typedef enum _AcdbVocVolFeatureID {
   ACDB_VOCVOL_FID_DEFAULT = 0x0,    /**< This is the default feature ID value of the voice volume table. */
} AcdbVocVolFeatureID;

/** Specifies the use case id value of the VP3 table.
 */
typedef enum _AcdbVP3UseCaseID {
   ACDB_VP3_VOICE_USECASE = 0x1,    /**< Voice use case. */
   ACDB_VP3_AUDIO_REC_USECASE = 0x2,    /**< Audio Rec use case. */
   ACDB_VP3_AUDIO_WITH_EC_USECASE = 0x3,    /**< Audio Rec with EC use case. */
} AcdbVP3UseCaseID;

/**
@Enum AcdbCodecGainType
@brief This is a enum to list different kind of codec gain entries, used to get step size of the particular item.
*/
typedef enum _AcdbCodecGainType {
	VOLUME_GAIN_TYPE = 0x00013142,
	BASS_GAIN_TYPE = 0x00013143,
	TREBLE_GAIN_TYPE = 0x00013144,
	MID_GAIN_TYPE = 0x00013145,
	BALANCE_GAIN_TYPE = 0x00013146,
	FADER_GAIN_TYPE = 0x00013147,
	EQ_GAIN_TYPE = 0x00013148,
	MUTE_GAIN_TYPE =0x00013149
}AcdbCodecGainType;

/** @} */ /* end_addtogroup acdb_datatypes */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_RESET Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @ingroup acdb_reset

   Resets the ACDB software to the default state.

   This command deinitializes the ACDB.

   @param[in] nCommandId
         Command ID is ACDB_CMD_RESET.
   @param[in] pCommandStruct
         There is no input structure; set this to NULL.
   @param[in] nCommandStructLength
         There is no input structure; set this to 0.
   @param[out] pResponseStruct
         There is no output structure; set this to NULL.
   @param[in] nResponseStructLength
         There is no output structure; set this to 0.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- Invalid input parameters were provided.

   @sa
   acdb_ioctl
*/
#define ACDB_CMD_RESET                       0x00011111

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_DEVICE_CAPABILITIES Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_dev_cap
@{ */

/**
   Queries the device capabilities of every device ID stored in the ACDB.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_DEVICE_CAPABILITIES.
   @param[in] pCommandStruct
         Pointer to AcdbDeviceCapabilitiesCmdType.
   @param[in] nCommandStructLength
         This must equal the size of AcdbDeviceCapabilitiesCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         This must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.

   @sa
   acdb_ioctl \n
   _AcdbDeviceCapabilitiesCmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_DEVICE_CAPABILITIES     0x00011114

/**
   Query command structure for the device capabilities.

   @sa
   AcdbDeviceCapabilityType
*/
typedef struct _AcdbDeviceCapabilitiesCmdType {
   uint32_t nParamId;
     /**< Parameter ID identifying the payload format contained in the buffer. */
   uint32_t nBufferLength;
     /**< Length of the buffer. This must be large enough to hold the entire
          device information structure identified by nParamId. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to the memory region into which the
          ACDB is to copy the device information. */
} AcdbDeviceCapabilitiesCmdType;

/**
   Parameter ID identifying the format of the device capabilities structure.

   The format of the device capabilities parameter is a packed structure:
@code
    struct AcdbDeviceCapabilityType {
       uint32_t nDeviceId;
       uint32_t ulSampleRateMask;
       uint32_t ulBytesPerSampleMask;
       };
    struct DeviceCapabilities {
       uint32_t nDeviceCount;
       AcdbDeviceCapabilityType entries [nDeviceCount];
    };

@endcode

   This structure requires parsing, since it is packed and there are no
   padding bytes contained in the structure. C compilers compile
   the above structure in a padded fashion.

   @sa
   _AcdbDeviceCapabilityType
*/
#define ACDB_DEVICE_CAPABILITY_PARAM                     0x0001117E

/**
   Response structure for the device capabilities.
*/
typedef struct AcdbDeviceCapabilityType {
   uint32_t nDeviceId;
     /**< Device ID with which the next two capability information items are
          associated. */
   uint32_t ulSampleRateMask;
     /**< Sample rate mask (see the device information structure for bit
          meanings). */
   uint32_t ulBytesPerSampleMask;
     /**< Bytes per samples mask (see the device information structure for bit
          meanings). */
}AcdbDeviceCapabilityType;

/** @} */ /* end_addtogroup get_dev_cap */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_IS_DEVICE_PAIRED Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup is_dev_paired
@{ */

/**
   Queries as to whether two device IDs are paired.

   @param[in] nCommandId
         Command ID is ACDB_CMD_IS_DEVICE_PAIRED.
   @param[in] pCommandStruct
         Pointer to AcdbDevicePairType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbDevicePairType.
   @param[out] pResponseStruct
         Pointer to AcdbDevicePairingResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbDevicePairingResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
                     If the call is successful, the AcdbDevicePairingResponseType
                     response is filled with one of the following results: \n
                     0x00000001 -- Pair is valid. \n
                     0x00000000 -- Pair is not valid.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- Tx device was not found in the loaded ACDB files.

   @sa
   acdb_ioctl \n
   _AcdbDevicePairType \n
   _AcdbDevicePairingResponseType
*/
#define ACDB_CMD_IS_DEVICE_PAIRED            0x00011115

/**
   Query command structure for determing valid device pairs.

   Call this query prior to attempting to obtain calibration data
   for voice calls. This command lets interested callers know
   which paired devices are acceptable for use in a voice call.
*/
typedef struct _AcdbDevicePairType {
   uint32_t nTxDeviceId;               /**< Tx device ID. */
   uint32_t nRxDeviceId;               /**< Rx device ID. */
} AcdbDevicePairType;

/**
   Identifies whether the queried device pairing is valid.
*/
typedef struct _AcdbDevicePairingResponseType {
   uint32_t ulIsDevicePairValid;
     /**< Identifies whether the queried device pair is valid. Expected
         values: \n
         0x00000001 -- Pair is valid. \n
         0x00000000 -- Pair is not valid. */
} AcdbDevicePairingResponseType;

/**
   ACDB device pair parameter.
*/
#define ACDB_DEVICE_PAIR_PARAM                           0x00011184

/** @} */ /* end_addtogroup is_dev_paired */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDPROC_COMMON_DATA and ACDB_CMD_SET_AUDPROC_COMMON_DATA
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_audproc_com_data
@{ */

/**
   Queries for specific AudProc common calibration data.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDPROC_COMMON_DATA.
   @param[in] pCommandStruct
         Pointer to AcdbAudProcCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudProcCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_PARMNOTFOUND -- Parameter data was not found.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbAudProcCmdType \n
   _AcdbQueryResponseType
   @newpage
*/
#define ACDB_CMD_GET_AUDPROC_COMMON_DATA     0x0001111E

/** @} */ /* end_addtogroup get_audproc_com_data */

/** @ingroup set_audproc_com_data

   Changes individual calibration data in the ACDB.

   This command allows the overriding of AudProc common calibration
   data stored in the database.

   @param[in] nCommandId
         Command ID is ACDB_CMD_SET_AUDPROC_COMMON_DATA.
   @param[in] pCommandStruct
         Pointer to AcdbAudProcCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudProcCmdType.
   @param[out] pResponseStruct
         There is no output structure; set this to NULL.
   @param[in] nResponseStructLength
         There is no output structure; set this to 0.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.

   @sa
   acdb_ioctl \n
   _AcdbAudProcCmdType
*/
#define ACDB_CMD_SET_AUDPROC_COMMON_DATA     0x0001111F

/** @addtogroup get_audproc_com_data
@{ */

/**
   Query command structure for getting the AudProc common calibration data
   tables.
*/
typedef struct _AcdbAudProcCmdType {
   uint32_t nDeviceId;
     /**< Device ID. */
   uint32_t nDeviceSampleRateId;
     /**< Actual sample rate at which the device is operating, in Hz. */
   uint32_t nApplicationType;
     /**< Application type ID. */
   uint32_t nModuleId;
     /**< Module ID. */
   uint32_t nParamId;
     /**< Parameter ID of the module for which to query. */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the parameters identified by the nParamId identifier. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to a memory region containing the
          payload (or receiving the payload) identified by nParamId. */
} AcdbAudProcCmdType;

/** @} */ /* end_addtogroup get_audproc_com_data */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDPROC_COMMON_TABLE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_audproc_com_tbl
@{ */

/**
   Queries for specific calibration data for the AudProc common table in the
   Hexagon@tm table format.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDPROC_COMMON_TABLE.
   @param[in] pCommandStruct
         Pointer to AcdbAudProcTableCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudProcTableCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.
   @vertspace{-10}
   @sa
   acdb_ioctl \n
   _AcdbAudProcTableCmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_AUDPROC_COMMON_TABLE    0x00011120

/**
   Query command structure for getting
   calibration data in the AudProc data tables.

   The format of the table matches the table format in the Hexagon API:
@code
   struct AudProcTableEntry {
      uint32_t nModuleId;
      uint32_t nParamId;
      uint16_t nParamSize; //multiple of 4
      uint16_t nReserved; // Must be 0
      uint8 aParamData [multiple of 4];
   }

@endcode
*/
typedef struct _AcdbAudProcTableCmdType {
   uint32_t nDeviceId;
     /**< Device ID. */
   uint32_t nDeviceSampleRateId;
     /**< Actual sample rate at which the device is operating, in Hz. */
   uint32_t nApplicationType;
     /**< Application type ID. */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the entire table. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to the memory region into which the
          ACDB is to copy the table. */
} AcdbAudProcTableCmdType;

/** @} */ /* end_addtogroup get_audproc_com_tbl */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_SET_AUDPROC_COMMON_TABLE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup set_audproc_com_tbl
@{ */

/**
   Queries for specific calibration data for the AudProc common table in the
   Hexagon table format.

   This command allows the overriding of AudProc common calibration
   table stored in the database.

   Note: Caller should take care of making the data base consistent in case
   ACDB_BADPARM is returned.

   @param[in] nCommandId
         Command ID is ACDB_CMD_SET_AUDPROC_COMMON_TABLE.
   @param[in] pCommandStruct
         Pointer to AcdbAudProcTableCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudProcTableCmdType.
   @param[out] pResponseStruct
         There is no output structure; set this to NULL.
   @param[in] nResponseStructLength
         There is no output structure; set this to 0.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.

   @vertspace{-10}
   @sa
   acdb_ioctl \n
   _AcdbAudProcTableCmdType \n
*/
#define ACDB_CMD_SET_AUDPROC_COMMON_TABLE    0x0001305D

/** @} */ /* end_addtogroup set_audproc_com_tbl */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_VOL_TABLE_STEP_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_vol_tbl_step_size
@{ */

/**
   Queries for the generic AudProc and VocProc volume table step size.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_VOL_TABLE_STEP_SIZE.
   @param[in] pCommandStruct
         There is no iutput command structure; set this to NULL.
   @param[in] nCommandStructLength
         There is no iutput structure; set this to 0.
   @param[out] pResponseStruct
         Pointer to the struct AcdbVolTblStepSizeRspType.
   @param[out] nResponseStructLength
         Length of AcdbVolTblStepSizeRspType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- The global ACDB file was not loaded, or an invalid global
                   ACDB file was provided. @vertspace{-4}

   @sa
   acdb_ioctl \n
   _AcdbVolTblStepSizeRspType
*/
#define ACDB_CMD_GET_VOL_TABLE_STEP_SIZE                        0x0001112C

/**
   Query response structure for the RX volume table step size.

   This structure provides the number of audio and voice volume steps
   information.
*/
typedef struct _AcdbVolTblStepSizeRspType {
   uint32_t VocProcVolTblStepSize;
     /**< Number of steps in the VocProc volume table. */
   uint32_t AudProcVolTblStepSize;
     /**< Number of steps in the AudProc volume table. */
} AcdbVolTblStepSizeRspType;

/**
   Query command structure for the gain-dependent audio volume calibration
   table.
*/
typedef struct _AcdbAudProcGainDepVolTblStepCmdType {
   uint32_t nDeviceId;
     /**< Device ID. */
   uint32_t nApplicationType;
     /**< Application type ID. */
   uint32_t nVolumeIndex;
     /**< Volume index. */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the entire gain-dependent calibration table. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to the memory region into which the
          ACDB is to copy the gain-dependent calibration table. The format of
          the table matches the expected table format in the Hexagon API. In
          this case, the table format is the same as in this structure:
@code
    struct AudProcVolTableEntry {
      uint32_t nModuleId;
      uint32_t nParamId;
      uint16_t nParamSize; // multiple of 4
      uint16_t nReserved;  // must be 0
      uint8 aParamData [multiple of 4];
    }
@endcode
*/
} AcdbAudProcGainDepVolTblStepCmdType;

/**
   ID to use for a specific calibration module ID for AudProc mono volume gain.
*/
#define ACDB_MID_AUDIO_VOLUME_MONO                                        0x000111D2

/**
   ID to use for a specific calibration module ID for AudProc stereo volume gain.
*/
#define ACDB_MID_AUDIO_VOLUME_STEREO                                      0x000111D3

/**
   ID to use for a specific calibration module ID for AudProc stereo volume gain.
*/
#define ACDB_MID_AUDIO_VOLUME_MULTICHAN                                   0x00013250

/**
   ID to use for a specific calibration parameter ID for AudProc mono volume gain.
*/
#define ACDB_PID_AUDIO_VOLUME_MONO                                        0x000111D5

/**
   ID to use for a specific calibration parameter ID for AudProc stereo volume gain.
*/
#define ACDB_PID_AUDIO_VOLUME_STEREO                                      0x000111D4

/**
   ID to use for a specific calibration parameter ID for AudProc multi channel volume gain.

   struct multichannel_volume_pid
   {
      uint32_t num_channels;
      channel_type_gain  gain_data[8];
   }

   struct channel_type_gain
   {
      uint8_t channel_type;
	  uint8_t reserved1;
	  uint8_t reserved2;
	  uint8_t reserved3;
	  uint32_t gain;
	}
*/
#define ACDB_PID_AUDIO_VOLUME_MULTICHAN                                   0x00013251

/**
  This module ID is to query for a specific calibration data from AudprocVolTable. This MID is introduced to support any number of channels instead of hardcoding the number of channels.
*/

#define ACDB_MID_AUDIO_VOLUME_MULTICHAN_V2                                   0x00013333

/**
   This param ID is to query for a specific calibration data from AudprocVolTable. The data for this param ID will be as follows

   struct multichannel_volume_pid
   {
      uint32_t num_channels;
      channel_type_gain  gain_data[num_channels];
   }

   struct channel_type_gain
   {
      uint8_t channel_type;
	  uint8_t reserved1;
	  uint8_t reserved2;
	  uint8_t reserved3;
	  uint32_t gain;
	}
*/
#define ACDB_PID_AUDIO_VOLUME_MULTICHAN_V2                               0x00013334

/** @} */ /* end_addtogroup get_vol_tbl_step_size */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_ADIE_CODEC_PATH_PROFILE_V2 Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_adie_path_profile
@{ */

/**
   Queries for ADIE path profile calibration data.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_ADIE_CODEC_PATH_PROFILE_V2.
   @param[in] pCommandStruct
         Pointer to AcdbAdiePathProfileV2CmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAdiePathProfileV2CmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.

   @sa
   acdb_ioctl \n
   _AcdbAdiePathProfileV2CmdStruct \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_ADIE_CODEC_PATH_PROFILE_V2                        0x00012A13

typedef struct _AcdbAdiePathProfileV2CmdStruct AcdbAdiePathProfileV2CmdType;
#include "acdb_begin_pack.h"
/**
   Query command structure to get the ADIE path profile.
*/
struct _AcdbAdiePathProfileV2CmdStruct {
   uint32_t ulCodecPathId;
     /**< Codec path ID. */
   uint32_t nParamId;
     /**< Parameter ID controlling the data structure versioning. Currently,
          following PIDs are supported for the command ACDB_CMD_GET_ADIE_CODEC_PATH_PROFILE_V2.
        ACDB_PID_ADIE_CODEC_PATH_WCD9320,
        ACDB_PID_ADIE_CODEC_PATH_WCD9306,
        ACDB_PID_ADIE_CODEC_PATH_MSM8X10,
        ACDB_PID_ADIE_CODEC_PATH_WCD9302,
	     ACDB_PID_ADIE_CODEC_PATH_MSM8X16,
	     ACDB_PID_ADIE_CODEC_PATH_WCD9330,
        ACDB_PID_ADIE_CODEC_PATH_MSM8X09,
        ACDB_PID_ADIE_CODEC_PATH_MSM8X52,
        ACDB_PID_ADIE_CODEC_PATH_WCD9335,
		ACDB_PID_ADIE_CODEC_PATH_WCD9326,
		ACDB_PID_ADIE_CODEC_PATH_MSM8X53,
        ACDB_PID_ADIE_CODEC_PATH_WCD934X,
ACDB_PID_ADIE_CODEC_PATH_DIRANA
     */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the parameters identified by the nParamId identifier. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to the memory region containing the
          payload (or receiving the payload) identified by nParamId. */
}

#include "acdb_end_pack.h"
;

/** PID ADIE codec path for WCD9320.
    @newpage
*/
#define ACDB_PID_ADIE_CODEC_PATH_WCD9320                         0x00012A01

/** PID ADIE codec path for WCD9306.
    @newpage
*/
#define ACDB_PID_ADIE_CODEC_PATH_WCD9306                         0x00012E68

/** PID ADIE codec path for CODEC_MSM8X10.
    @newpage
*/
#define ACDB_PID_ADIE_CODEC_PATH_MSM8X10                         0x00012ECA

/** PID ADIE codec path for CODEC_WCD9302.
    @newpage
*/
#define ACDB_PID_ADIE_CODEC_PATH_WCD9302                         0x00012ED7

/** PID ADIE codec path for CODEC_MSM8X16.
    @newpage
*/
#define ACDB_PID_ADIE_CODEC_PATH_MSM8X16                         0x00013076

/** PID ADIE codec path for CODEC_WCD9330.
    @newpage
*/
#define ACDB_PID_ADIE_CODEC_PATH_WCD9330                         0x00013078

/** PID ADIE codec path for CODEC_MSM8X09.
@newpage
*/
#define ACDB_PID_ADIE_CODEC_PATH_MSM8X09                         0x000130FC

/** PID ADIE codec path for CODEC_MSM8X52.
@newpage
*/
#define ACDB_PID_ADIE_CODEC_PATH_MSM8X52                         0x00013197

/** PID ADIE codec path for CODEC_WCD9335.
    @newpage
*/
#define ACDB_PID_ADIE_CODEC_PATH_WCD9335                         0x0001319E

/** PID ADIE codec path for CODEC_WCD9326.
    @newpage
*/
#define ACDB_PID_ADIE_CODEC_PATH_WCD9326                         0x000131AF

/** PID ADIE codec path for CODEC_MSM8X53.
@newpage
*/
#define ACDB_PID_ADIE_CODEC_PATH_MSM8X53                         0x000131EC

/** PID ADIE codec path for CODEC_WCD9340/CODEC_WCD9341.
@newpage
*/
#define ACDB_PID_ADIE_CODEC_PATH_WCD934X                         0x00013252

/**
@def ACDB_PID_ADIE_CODEC_PATH_DIRANA
@brief This is the Parameter ID identifying the format of the Adie Codec
path profile structure for Dirana.
@see This structure is associate with Adie codec path
*/
#define ACDB_PID_ADIE_CODEC_PATH_DIRANA 0x000130FB 
/* Struct format for DIRANA profile
typedef struct acdb_dirana_cdc_analog_input_config_type
{
uint32_t type;
uint32_t num_of_channels;
uint32_t input_mode;
}acdb_dirana_cdc_analog_input_config_type_t;

typedef struct acdb_dirana_cdc_analog_output_config_type
{
uint32_t type;
uint32_t num_of_channels;
uint32_t dc_shift_mode;
}acdb_dirana_cdc_analog_output_config_type_t;

typedef struct acdb_dirana_cdc_i2s_input_config_type
{
uint32_t type;
uint32_t num_of_channels;
uint32_t mode;
uint32_t format;
}acdb_dirana_cdc_i2s_input_config_type_t;

typedef struct acdb_dirana_cdc_i2s_output_config_type
{
uint32_t type;
uint32_t num_of_channels;
uint32_t mode;
uint32_t format;
uint32_t pad;
}acdb_dirana_cdc_i2s_output_config_type_t;

typedef struct acdb_dirana_cdc_internal_codec_input_config
{
uint32_t type;
uint32_t num_of_channels;
}acdb_dirana_cdc_internal_codec_input_config_t;

typedef struct acdb_dirana_cdc_cfg_data
{
uint32_t connection_type; // acdb_dirana_cdc_connection_type
uint32_t size; //length of the data

//Payload Follows -- can be one of the below structure/
//
//void data[];
//Can be one of the following structure as per
{
//Input Config Type
acdb_dirana_cdc_analog_input_config_type_t adc_cfg;
acdb_dirana_cdc_i2s_input_config_type_t i2s_in_cfg;
//OutPut Config Type
acdb_dirana_cdc_analog_output_config_type_t dac_cfg;
acdb_dirana_cdc_i2s_output_config_type_t i2s_out_cfg
};//
}acdb_dirana_cdc_cfg_data_t;

typedef struct acdb_dirana_cdc_profile_header
{
uint32_t size; //Size of this Structure
uint32_t version; //Version Details
uint32_t profile_id; //Should Be Unique
uint32_t options; //Reserved Fill Zero
uint32_t gateway; //acdb_dirana_cdc_gateway_type_e
uint32_t input; //acdb_dirana_cdc_connection_type
uint32_t output; //acdb_dirana_cdc_connection_type
}acdb_dirana_cdc_profile_header_t;

typedef struct acdb_dirana_cdc_profile
{
acdb_dirana_cdc_profile_header_t header;
acdb_dirana_cdc_cfg_data_t input_cfg;
acdb_dirana_cdc_cfg_data_t output_cfg;
}AcdbAdieDIRANACodecDbProfile;
*/

/** @} */ /* end_addtogroup get_adie_path_profile */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_ADIE_CODEC_PATH_PROFILE_V2_SIZE Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_adie_path_profile_size
@{ */

/**
   Queries for ADIE path profile calibration data.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_ADIE_CODEC_PATH_PROFILE_V2_SIZE.
   @param[in] pCommandStruct
         Pointer to AcdbAdiePathProfileV2CmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAdiePathProfileV2SizeCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.

   @sa
   acdb_ioctl \n
   _AcdbAdiePathProfileV2SizeCmdStruct \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_ADIE_CODEC_PATH_PROFILE_V2_SIZE                        0x00013276

typedef struct _AcdbAdiePathProfileV2SizeCmdStruct AcdbAdiePathProfileV2SizeCmdType;
#include "acdb_begin_pack.h"
/**
   Query command structure to get the ADIE codec profile size.
*/
struct _AcdbAdiePathProfileV2SizeCmdStruct {
     uint32_t codecPathId;
     /**< Codec path ID. */
     uint32_t nParamId;
     /**< Currently, following PIDs are supported for the command ACDB_CMD_GET_ADIE_CODEC_PATH_PROFILE_V2_SIZE.
        ACDB_PID_ADIE_CODEC_PATH_WCD9320,
        ACDB_PID_ADIE_CODEC_PATH_WCD9306,
        ACDB_PID_ADIE_CODEC_PATH_MSM8X10,
        ACDB_PID_ADIE_CODEC_PATH_WCD9302,
	     ACDB_PID_ADIE_CODEC_PATH_MSM8X16,
	     ACDB_PID_ADIE_CODEC_PATH_WCD9330,
        ACDB_PID_ADIE_CODEC_PATH_MSM8X09,
        ACDB_PID_ADIE_CODEC_PATH_MSM8X52,
        ACDB_PID_ADIE_CODEC_PATH_WCD9335,
		  ACDB_PID_ADIE_CODEC_PATH_WCD9326,
		  ACDB_PID_ADIE_CODEC_PATH_MSM8X53,
        ACDB_PID_ADIE_CODEC_PATH_WCD934X
     */
}

#include "acdb_end_pack.h"
;
/** @} */ /* end_addtogroup get_adie_path_profile_size */

/*
struct _AcdbAdieWCD93XX_B_CodecACDBHeader
{
  uint32_t   size;
  uint32_t   version;
  uint32_t   profile_id;
  uint32_t   number_of_paths;
  uint32_t   profile_direction;
  uint32_t   num_actions;
  uint32_t   sources[8];
  uint32_t   sinks[8];
  uint32_t   connection_type[8];
} AcdbAdieWCD93XX_B_CodecACDBHeader;

struct _AdieWCD93xx_B_CodecCommand
{
   uint32 parameter_one;
   uint32 parameter_two;
} AdieWCD93xx_B_CodecCommand;

struct _Acdb_WCD93xx_B_CodecProfile
{
   AcdbAdieWCD93XX_BCodecACDBHeader header;
   AdieWCD93xx_B_CodecCommand command[numActions];
} Acdb_WCD93xx_B_CodecProfile;
*/

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_ANC_TX_DEVICE Declarations and Documentation
 * --------------------------------------------------------------------------- */

/** @addtogroup get_anc_tx_dev
@{ */

/**
   Queries for the Tx device ID with a corresponding ANC device-paired Rx
   device ID.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_ANC_TX_DEVICE.
   @param[in] pCommandStruct
         Pointer to AcdbAncDevicePairCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAncDevicePairCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbAncDevicePairRspType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbAncDevicePairRspType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- ANC Tx device for the specified Rx device was not found, or
                   the ACDB files were not loaded.

   @sa
   acdb_ioctl \n
   _AcdbAncDevicePairCmdType \n
   _AcdbAncDevicePairRspType
*/
#define ACDB_CMD_GET_ANC_TX_DEVICE                       0x000111DE

/**
   Query command structure for the ANC device-paired Tx device.
*/
typedef struct _AcdbAncDevicePairCmdType {
   uint32_t nRxDeviceId;               /**< Rx device ID.
                                            @newpagetable */
} AcdbAncDevicePairCmdType;

/**
   Response structure for querying an ANC device-paired Tx device. If the
   Rx device is not found, the Tx device is returned as 0x00000000.
*/
typedef struct _AcdbAncDevicePairRspType {
   uint32_t nTxAncDeviceId;            /**< Tx ANC device ID. */
} AcdbAncDevicePairRspType;

/** @} */ /* end_addtogroup get_anc_tx_dev */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_CODEC_ANC_SETTING Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_codec_anc_setting
@{ */

/**
   Queries for ANC setting calibration data for codec
   WCD9320, WCD9306 and beyond.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_CODEC_ANC_SETTING.
   @param[in] pCommandStruct
         Pointer to AcdbCodecANCSettingCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbCodecANCSettingCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.

   @sa
   acdb_ioctl \n
   _AcdbCodecANCSettingCmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_CODEC_ANC_SETTING                       0x00012A5B

typedef struct _AcdbCodecANCSettingCmdType AcdbCodecANCSettingCmdType;
#include "acdb_begin_pack.h"

/**
   Query command structure for getting the ADIE ANC configuration
   data for codec WCD9320, WCD9306 and beyond.
*/
struct _AcdbCodecANCSettingCmdType {
   uint32_t nRxDeviceId;
     /**< Rx device ID. */
   uint32_t nParamId;
     /**< Parameter ID controlling the data structure versioning.
          ACDB_PID_CODEC_ANC_DATA_WCD9320 and ACDB_PID_CODEC_ANC_DATA_WCD9306
          PIDs are supported for this command. */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the parameters identified by the nParamId identifier. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to the memory region containing the
          payload (or receiving the payload) identified by nParamId. */
}

#include "acdb_end_pack.h"
;

/** PID codec ANC data for WCD9320. @newpage
*/
#define ACDB_PID_CODEC_ANC_DATA_WCD9320                     0x00012A5C

/** PID codec ANC data for WCD9306. @newpage
*/
#define ACDB_PID_CODEC_ANC_DATA_WCD9306                     ACDB_PID_CODEC_ANC_DATA_WCD9320

/** @} */ /* end_addtogroup get_codec_anc_setting */

/*
//ANC WCD9320 and WCD9306 Config data structure format
typedef struct
{
  uint8_t   default_enable;                   //check if the anc channel is enabled or not
  uint8_t   anc_feedback_enable;              //CDC_CLK_ANC_CLK_EN_CTL
  uint8_t   anc_lr_mix_enable;                //CDC_ANC_CTL  -- used with anc_lr_mix_output_channel, if true and 1, set it for CDC_ANC1_CTL, if true and 2, set it for CDC_ANC2_CTL, if false, set to false
  uint8_t   smlpf_enable;                     //CDC_ANC_CTL
  uint8_t   ff_in_enable;                     //CDC_ANC_CTL
  uint8_t   hybrid_enable;                    //CDC_ANC_CTL
  uint8_t   ff_out_enable;                    //CDC_ANC_CTL
  uint8_t   dcflt_enable;                     //CDC_ANC_CTL
  uint8_t   adaptive;                         //not sure
  uint8_t   adaptive_gain_enable;             //CDC_ANC_B1_CTL
  uint8_t   flex_enable;                      //CDC_ANC_B2_CTL
  uint8_t   dmic_x2_enable;                   //CDC_ANC_B2_CTL
  uint8_t   anc_lr_mix_output_channel;        //only used if anc_lr_mix_enable = true  1 = channel 1, 2 = channel 2
  int8_t    anc_ff_shift;                     //CDC_ANC_SHIFT // -4 -> 6
  int8_t    anc_fb_shift;                     //CDC_ANC_SHIFT // -4 -> 6
  uint8_t   padding;
  int32_t   anc_ff_coeff[15];                 //CDC_ANC_IIR_B3_CTL // IIR coeffs: A[2 - 8] B[1-8] - Q3.13 (signed)
  int32_t   anc_gain;                         //iir coefficient calculation
  int32_t   anc_ff_lpf_shift[2];              //CDC_ANC_LPF_B1_CTL // 0 -> 12
  int32_t   anc_fb_coeff[13];                 //CDC_ANC_IIR_B3_CTL // IIR coeffs: A[2 - 7] B[1-7] - Q3.13 (signed)
  int32_t   anc_gain_default;                 //not sure what this is for..
  int32_t   anc_fb_lpf_shift[2];              //CDC_ANC_LPF_B1_CTL // 0 -> 12
  uint32_t  input_device;                     //CDC_ANC_CTL_ADC_DMIC_SEL & CDC_CONN_ANC_B1_CTL
  uint32_t  smlpf_shift;                      //CDC_ANC_SMLPF_CTL
  uint32_t  dcflt_shift;                      //CDC_ANC_DCFLT_CTL
  int32_t   adaptive_gain;                    //CDC_ANC_GAIN_CTL
} wcd_adie_codec_db_anc_config;
*/

/** PID codec ANC data for WCD9335. @newpage
*/
#define ACDB_PID_CODEC_ANC_DATA_HW_V4          0x000131A4

/*
The structure format of the above PID is

typedef struct anc_config
{
                anc_wcd9335_acdb_cfg_t left;
                anc_wcd9335_acdb_cfg_t right;
};

typedef struct anc_wcd9335_acdb_cfg_t {
   uint32_t ff_a_enable;
   uint32_t ff_b_enable;
   uint32_t fb_enable;
   uint32_t ff_a_in_enable;
   uint32_t ff_b_in_enable;
   uint32_t ff_a_input_device;
   uint32_t ff_b_input_device;
   uint32_t ff_out_enable;
   uint32_t smlpf_enable;
   uint32_t ff_flex_enable;
   uint32_t ff_a_gain_enable;
   uint32_t ff_b_gain_enable;
   uint32_t fb_gain_enable;
   uint32_t ff_a_dcflt_enable;
   uint32_t ff_b_dcflt_enable;
   uint32_t dmic_x2_ff_a_enable;
   uint32_t dmic_x2_ff_b_enable;
   int32_t anc_ff_a_shift;
   int32_t anc_ff_b_shift;
   int32_t anc_fb_shift;
   int32_t anc_ff_a_den_coeff[7];
   int32_t anc_ff_a_num_coeff[8];
   int32_t anc_ff_a_gain_scale;
   int32_t anc_ff_a_gain_scale_default;
   int32_t anc_ff_a_gain;
   int32_t anc_ff_b_den_coeff[7];
   int32_t anc_ff_b_num_coeff[8];
   int32_t anc_ff_b_gain_scale;
   int32_t anc_ff_b_gain_scale_default;
   int32_t anc_ff_b_gain;
   int32_t anc_fb_den_coeff[7];
   int32_t anc_fb_num_coeff[8];
   int32_t anc_fb_gain_scale;
   int32_t anc_fb_gain_scale_default;
   int32_t anc_fb_gain;
   uint32_t anc_ff_a_lpf_shift[2];
   uint32_t anc_ff_b_lpf_shift[2];
   uint32_t anc_fb_lpf_shift[2];
   uint32_t ff_a_dcflt_shift;
   uint32_t ff_b_dcflt_shift;
   uint32_t smlpf_shift; //WCD9335_CDC_ANC0_SMLPF_CTL___SHIFT
}anc_wcd9335_acdb_cfg_t;

*/

/** PID codec ANC data for WCD9340. @newpage
*/
#define ACDB_PID_CODEC_ANC_DATA_HW_V5 0x000131ED

/*
The structure of the above PID is

struct	struct_0x000131ED_ANC_CONFIG{
	struct struct_wcd9340_adie_codec_db_anc_config	left;
	struct struct_wcd9340_adie_codec_db_anc_config	right;
}

struct	struct_wcd9340_adie_codec_db_anc_config{
	uint32 anc_usecase; // Range: 0-2, 0: SmartLnQ Headset, 1: Handset, 2: Headset
	int32 ff_a_mic_sensitivity; // unit dBVRMS/Pa
	int32 ff_b_mic_sensitivity; // unit dBVRMS/Pa
	int32 ff_a_fe_gain; // unit dB - not valid for SmartLnQ Headset since mic_sensitivity covers the mic amp/fe_gain
	int32 ff_b_fe_gain; // unit dB - not valid for SmartLnQ Headset since mic_sensitivity covers the mic amp/fe_gain
	int32 spkr_rcvr_sensitivity; // unit dBSPL/mW - spkr sensitivity for Headset usecases and rcvr for Handset usecase
	int32 spkr_rcvr_impedance; // unit ohms - spkr impedance for Headset usecases and rcvr for Handset usecase
	int32 spkr_rcvr_pa_gain; // unit dB - spkr pa gain for Headset usecases and rcvr for Handset usecase
	uint32 ff_a_enable; // WCD9340_CDC_ANC0_CLK_RESET_CTL___FFA_CLK_EN && WCD9340_CDC_ANC0_CLK_RESET_CTL___FB_CLK_EN
	uint32 ff_b_enable; // WCD9340_CDC_ANC0_CLK_RESET_CTL___FFB_CLK_EN && WCD9340_CDC_ANC0_CLK_RESET_CTL___FFB_CLK_EN
	uint32 fb_enable;   // WCD9340_CDC_ANC0_CLK_RESET_CTL___FB_CLK_EN && WCD9340_CDC_ANC0_CLK_RESET_CTL___FB_CLK_EN
	uint32 ff_a_in_enable; // WCD9340_CDC_ANC0_MODE_1_CTL___FFA_IN_EN
	uint32 ff_b_in_enable; // WCD9340_CDC_ANC0_MODE_1_CTL___FFB_IN_EN
	uint32 ff_a_input_type; // WCD9340_CDC_ANC0_MODE_1_CTL___ANC_ADC_DMIC_A_SEL && WCD9340_CDC_ANC0_CLK_RESET_CTL___SMARTLNQ_A_EN // defined by enum codec_anc_input_type
	uint32 ff_b_input_type; // WCD9340_CDC_ANC0_MODE_1_CTL___ANC_ADC_DMIC_B_SEL && WCD9340_CDC_ANC0_CLK_RESET_CTL___SMARTLNQ_B_EN// defined by enum codec_anc_input_type
	int32 fb_mon; // WCD9340_CDC_ANC0_MODE_1_CTL___FB_ON_FBMON_IS_TRUE - 0 (legacy) : Ffa path IIR input goes to FB mon , 1(Adaptive Signal out) : FB path IIR input goes to FB mon
	uint32 ff_out_enable;   // WCD9340_CDC_ANC0_MODE_1_CTL___ANC_OUT_EN
	uint32 smlpf_enable; // WCD9340_CDC_ANC0_MODE_1_CTL___ANC_SMLPF_EN
	uint32 ff_flex_enable; // WCD9340_CDC_ANC0_MODE_2_CTL___ANC_FFLE_EN
	uint32 ff_a_gain_enable; // WCD9340_CDC_ANC0_MODE_2_CTL___ANC_FFGAIN_A_EN
	uint32 ff_b_gain_enable; // WCD9340_CDC_ANC0_MODE_2_CTL___ANC_FFGAIN_B_EN
	uint32 fb_gain_enable; // WCD9340_CDC_ANC0_MODE_2_CTL___ANC_FBGAIN_EN
	uint32 ff_a_dcflt_enable; // WCD9340_CDC_ANC0_MODE_2_CTL___ANC_DCFILT_A_EN
	uint32 ff_b_dcflt_enable; // WCD9340_CDC_ANC0_MODE_2_CTL___ANC_DCFILT_B_EN
	uint32 dmic_x2_ff_a_enable; // WCD9340_CDC_ANC0_MODE_2_CTL___ANC_DMIC_X2_A_SEL
	uint32 dmic_x2_ff_b_enable; // WCD9340_CDC_ANC0_MODE_2_CTL___ANC_DMIC_X2_B_SEL
	int32 anc_ff_a_shift; // WCD9340_CDC_ANC0_FF_SHIFT___FFA_SHIFT
	int32 anc_ff_b_shift; // WCD9340_CDC_ANC0_FF_SHIFT___FFB_SHIFT
	int32 anc_fb_shift; // WCD9340_CDC_ANC0_FB_SHIFT___FB_SHIFT
	int32 anc_ff_a_den_coeff[7]; // WCD9340_CDC_ANC0_IIR_COEFF_1_CTL___COEF_PTR && WCD9340_CDC_ANC0_IIR_COEFF_2_CTL___COEF
	int32 anc_ff_a_num_coeff[8]; // WCD9340_CDC_ANC0_IIR_COEFF_1_CTL___COEF_PTR && WCD9340_CDC_ANC0_IIR_COEFF_2_CTL___COEF
	int32 anc_ff_a_gain_scale;
	int32 anc_ff_a_gain_scale_default;
	int32 anc_ff_a_gain; // WCD9340_CDC_ANC0_FF_A_GAIN_CTL___GAIN
	int32 anc_ff_b_den_coeff[7]; // WCD9340_CDC_ANC0_IIR_COEFF_1_CTL___COEF_PTR && WCD9340_CDC_ANC0_IIR_COEFF_2_CTL___COEF
	int32 anc_ff_b_num_coeff[8]; // WCD9340_CDC_ANC0_IIR_COEFF_1_CTL___COEF_PTR && WCD9340_CDC_ANC0_IIR_COEFF_2_CTL___COEF
	int32 anc_ff_b_gain_scale;
	int32 anc_ff_b_gain_scale_default;
	int32 anc_ff_b_gain; // WCD9340_CDC_ANC0_FF_B_GAIN_CTL___GAIN
	int32 anc_fb_den_coeff[7]; // WCD9340_CDC_ANC0_IIR_COEFF_1_CTL___COEF_PTR && WCD9340_CDC_ANC0_IIR_COEFF_2_CTL___COEF
	int32 anc_fb_num_coeff[8]; // WCD9340_CDC_ANC0_IIR_COEFF_1_CTL___COEF_PTR && WCD9340_CDC_ANC0_IIR_COEFF_2_CTL___COEF
	int32 anc_fb_gain_scale;
	int32 anc_fb_gain_scale_default;
	int32 anc_fb_gain; // WCD9340_CDC_ANC0_FB_GAIN_CTL___GAIN
	uint32 anc_ff_a_lpf_shift[2]; // WCD9340_CDC_ANC0_LPF_FF_A_CTL___LPF_FFA_S2 && WCD9340_CDC_ANC0_LPF_FF_A_CTL___LPF_FFA_S1
	uint32 anc_ff_b_lpf_shift[2]; // WCD9340_CDC_ANC0_LPF_FF_B_CTL___LPF_FFB_S2 && WCD9340_CDC_ANC0_LPF_FF_B_CTL___LPF_FFB_S1
	uint32 anc_fb_lpf_shift[2]; // WCD9340_CDC_ANC0_LPF_FB_CTL___LPF_FB_S2 && WCD9340_CDC_ANC0_LPF_FB_CTL___LPF_FB_S1
	uint32 ff_a_dcflt_shift; // WCD9340_CDC_ANC0_DCFLT_SHIFT_CTL___A_SHIFT
	uint32 ff_b_dcflt_shift; // WCD9340_CDC_ANC0_DCFLT_SHIFT_CTL___B_SHIFT
	uint32 smlpf_shift; // WCD9340_CDC_ANC0_SMLPF_CTL___SHIFT
}

*/

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDPROC_COMMON_TOPOLOGY_ID Declarations and Documentation
 * --------------------------------------------------------------------------- */

/** @addtogroup get_audproc_com_topol_id
@{ */

/**
   Queries for the specified AudProc COPP topology ID.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDPROC_COMMON_TOPOLOGY_ID.
   @param[in] pCommandStruct
         Pointer to AcdbGetAudProcTopIdCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbGetAudProcTopIdCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbGetTopologyIdRspType.
   @param[out] nResponseStructLength
         Length must equal the size of AcdbGetTopologyIdRspType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_PARMNOTFOUND -- Data for the specified device ID and application
                          type ID were not found.

   @sa
   acdb_ioctl \n
   _AcdbGetAudProcTopIdCmdType \n
   _AcdbGetTopologyIdRspType
*/
#define ACDB_CMD_GET_AUDPROC_COMMON_TOPOLOGY_ID                 0x0001122D

/**
   Query command structure for getting the AudProc COPP topology ID.
*/
typedef struct _AcdbGetAudProcTopIdCmdType {
   uint32_t nDeviceId;                 /**< Device ID. */
   uint32_t nApplicationType;          /**< Application type ID. */
} AcdbGetAudProcTopIdCmdType;

/** @} */ /* end_addtogroup get_audproc_com_topol_id */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDPROC_STREAM_TOPOLOGY_ID Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_audproc_strm_topol_id
@{ */

/**
   Queries for the AudProc stream POPP topology ID.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDPROC_STREAM_TOPOLOGY_ID.
   @param[in] pCommandStruct
         Pointer to AcdbGetAudProcStrmTopIdCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbGetAudProcStrmTopIdCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbGetTopologyIdRspType.
   @param[out] nResponseStructLength
         Length must equal the size of AcdbGetTopologyIdRspType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_PARMNOTFOUND -- Data for the specified and application type ID were
                          not found.

   @sa
   acdb_ioctl \n
   _AcdbGetAudProcStrmTopIdCmdType \n
   _AcdbGetTopologyIdRspType
*/
#define ACDB_CMD_GET_AUDPROC_STREAM_TOPOLOGY_ID                 0x0001122E

/**
   Query command structure for getting AudProc stream POPP topology ID.
*/
typedef struct _AcdbGetAudProcStrmTopIdCmdType {
   uint32_t nApplicationType;          /**< Application type ID. */
} AcdbGetAudProcStrmTopIdCmdType;

/**
   Response structure for the ACDB_CMD_GET_AUDPROC_STREAM_TOPOLOGY_ID
   command.
*/
typedef struct _AcdbGetTopologyIdRspType {
   uint32_t nTopologyId;               /**< Topology ID. */
} AcdbGetTopologyIdRspType;

/** @} */ /* end_addtogroup get_audproc_strm_topol_id */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AFE_TOPOLOGY_ID Declarations and Documentation
 * --------------------------------------------------------------------------- */

/** @addtogroup get_afe_topol_id
@{ */

/**
   Queries for the specified AFE topology ID.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AFE_TOPOLOGY_ID.
   @param[in] pCommandStruct
         Pointer to AcdbGetAfeTopIdCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbGetAfeTopIdCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbGetTopologyIdRspType.
   @param[out] nResponseStructLength
         Length must equal the size of AcdbGetTopologyIdRspType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_PARMNOTFOUND -- Data for the specified device ID and application
                          type ID were not found.

   @sa
   acdb_ioctl \n
   _AcdbGetAfeTopIdCmdType \n
   _AcdbGetTopologyIdRspType
*/
#define ACDB_CMD_GET_AFE_TOPOLOGY_ID                 0x000130D8

/**
   Query command structure for getting the AFE topology ID.
*/
typedef struct _AcdbGetAfeTopIdCmdType {
   uint32_t nDeviceId;                 /**< Device ID. */
} AcdbGetAfeTopIdCmdType;

/** @} */ /* end_addtogroup get_afe_topol_id */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_LSM_TOPOLOGY_ID Declarations and Documentation
 * --------------------------------------------------------------------------- */

/** @addtogroup get_lsm_topol_id
@{ */

/**
   Queries for the specified LSM topology ID.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_LSM_TOPOLOGY_ID.
   @param[in] pCommandStruct
         Pointer to AcdbGetLsmTopIdCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbGetLsmTopIdCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbGetTopologyIdRspType.
   @param[out] nResponseStructLength
         Length must equal the size of AcdbGetTopologyIdRspType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_PARMNOTFOUND -- Data for the specified device ID and application
                          type ID were not found.

   @sa
   acdb_ioctl \n
   _AcdbGetLsmTopIdCmdType \n
   _AcdbGetTopologyIdRspType
*/
#define ACDB_CMD_GET_LSM_TOPOLOGY_ID                 0x000130D9

/**
   Query command structure for getting the LSM topology ID.
*/
typedef struct _AcdbGetLsmTopIdCmdType {
   uint32_t nDeviceId;                 /**< Device ID. */
   uint32_t nLsmApplicationType;          /**< LSM Application type ID. */
} AcdbGetLsmTopIdCmdType;

/** @} */ /* end_addtogroup get_lsm_topol_id */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AFE_DATA
 * Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_afe_data
@{ */

/**
   Queries for specific AFE calibration data.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AFE_DATA.
   @param[in] pCommandStruct
         Pointer to AcdbAfeDataCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAfeDataCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_PARMNOTFOUND -- Parameter data not found.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbAfeDataCmdType \n
   _AcdbQueryResponseType
*/
/**
   Module identifier that identifies the module to query.
*/
#define ACDB_MID_SIDETONE_IIR_FILTER                              0x00010202

/**
   ID to use for a specific calibration parameter ID associated
   with a sidetone IIR data structure.
*/

#define ACDB_PID_SIDETONE_IIR_FILTER_CONFIG                       0x00010204

#define ACDB_PID_SIDETONE_IIR_ENABLE                              0x00010203

#define ACDB_CMD_GET_AFE_DATA                                     0x0001124E

/**
   Module identifier that identifies the module to query.
*/
#define ACDB_MID_SIDETONE                                          0x0001270E

/**
   ID to use for a specific calibration parameter ID associated
   with a sidetone data structure.
*/
#define ACDB_PID_SIDETONE                                          0x0001270F

typedef struct _AcdbAfeDataCmdType AcdbAfeDataCmdType;
#include "acdb_begin_pack.h"

/**
   Query command structure for getting calibration data in the AFE data tables.

   The format of the data is as follows:
@code
   struct AFESideToneStruct {
      uint16_t nEnableFlag;
      uint16_t nGain; //Linear gain
   }

@endcode
*/
struct _AcdbAfeDataCmdType {
   uint32_t nTxDeviceId;
     /**< Tx path device ID. */
   uint32_t nRxDeviceId;
     /**< Rx path device ID. */
   uint32_t nModuleId;
     /**< Module ID. */
   uint32_t nParamId;
     /**< Parameter ID of the module for which to query. */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the parameters identified by the nParamId identifier. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to a memory region containing the
          payload (or receiving the payload) identified by nParamId. */
}

#include "acdb_end_pack.h"
;
/** @} */ /* end_addtogroup get_afe_data */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_GLBTBL_DATA
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_glbtbl_data
@{ */

/**
   Queries for specific global table calibration data.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_GLBTBL_DATA.
   @param[in] pCommandStruct
         Pointer to AcdbGblTblCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbGblTblCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.

   @sa
   acdb_ioct \n
   _AcdbGblTblCmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_GLBTBL_DATA                                     0x0001126B

typedef struct _AcdbGblTblCmdType AcdbGblTblCmdType;
#include "acdb_begin_pack.h"

/**
   Query command structure for retrieving calibration data in the global
   calibration tables.

   The return buffer format is determined by the parameter ID as one of the
   keys to access the ACDB. The format of the data is:
@code
   // Existing pause/resume volume stepping structure is formatted as:
   struct VolumeStepStruct {
      uint32_t nEnableFlag; //Enable flag
      uint32_t nPeriod; //duration
      uint32_t nStep;   //number of step
      uint32_t ramping_curve; //Ramping curve
   }

@endcode
*/
struct _AcdbGblTblCmdType {
   uint32_t nModuleId;
     /**< Module ID. */
   uint32_t nParamId;
     /**< Parameter ID of the module for which to query. */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the parameters identified by the nParamId identifier. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to a memory region containing the
          payload (or receiving the payload) identified by nParamId. */
}

#include "acdb_end_pack.h"
;

/** @} */ /* end_addtogroup get_glbtbl_data */

/** @addtogroup acdb_datatypes
@{ */

/**
   @vertspace{-3}
   Module identifier that identifies the module to query.
*/
#define ACDB_MID_PAUSE_RESUME_VOLUME_CONTROL                      0x0001127B

/** @} */ /* end_addtogroup acdb_datatypes */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_COMMON_DEVICE_INFO Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_com_dev_info
@{ */

/**
   Queries for the common device information describing
   the device properties of a specified device ID.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_DEVICE_INFO.
   @param[in] pCommandStruct
         Pointer to AcdbDeviceInfoCmnCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbDeviceInfoCmnCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.

   @sa
   acdb_ioctl \n
   _AcdbDeviceInfoCmnCmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_COMMON_DEVICE_INFO                           0x00011290

/**
   Query command structure for the device information.
*/
typedef struct _AcdbDeviceInfoCmnCmdType {
   uint32_t nDeviceId;
     /**< Device ID to be looked up. */
   uint32_t nBufferLength;
     /**< Length of the buffer. This must be large enough to hold the entire
          device information structure identified by nParamId. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to the memory region into which the
          ACDB is to copy the device information. */
} AcdbDeviceInfoCmnCmdType;

/** @} */ /* end_addtogroup get_com_dev_info */

/*
   Common device information return structure containing common device
   metadata for the audio driver.

   struct _AcdbDeviceInfoCommonRspType
   {
      uint32_t headerVersion: The version of the common device info type structure format
                              ACDB_COMMON_DEVICE_INFO_HDR_PARAM - 0x000112A7
                              - First Common device info header version ID
      uint8_t payload[payloadsize]; - payloadsize is identified by the common device info
                                      structure size.
   } AcdbDeviceInfoCommonRspType

   struct {
            uint32_t ulDeviceType: The device type.
                                   (0x00012A50) - ACDB_DEVICE_TYPE_I2S_PARAM
                                                 :I2S type ParamId
                                   (0x00012A51) - ACDB_DEVICE_TYPE_PCM_PARAM
                                                 :PCM type ParamId
                                   (0x00012A52) - ACDB_DEVICE_TYPE_SLIMBUS_PARAM
                                                 :Slimbus type ParamId
                                   (0x00012A53) - ACDB_DEVICE_TYPE_DIGITAL_MIC_PARAM
                                                 :DigitalMic Type ParamId
                                   (0x00012A54) - ACDB_DEVICE_TYPE_HDMI_PARAM
                                                 :HDMI type ParamId
                                   (0x00012A55) - ACDB_DEVICE_TYPE_VIRTUAL_PARAM
                                                 :Virtual Device Type ParamId
                                   (0x00012A56) - ACDB_DEVICE_TYPE_INT_BTFM_PARAM
                                                 :Internal B/T and F/M config type ParamId
                                   (0x00012A57) - ACDB_DEVICE_TYPE_RT_PROXY_PARAM
                                                 :RT Proxy device type ParamId
                                   (0x00012A58) - ACDB_DEVICE_TYPE_SIMPLE_PARAM
                                                 :Simple device type ParamId
                                   (0x000102A4) - ACDB_DEVICE_TYPE_USB_PARAM
                                                 :USB device type ParamId
								   (0x00011328) - ACDB_DEVICE_TYPE_SIMPLE_PARAM_V2
                                                 :Simple device type ParamId v2
								   (0x00013338) - ACDB_DEVICE_TYPE_PCIE_PARAM
                                                 :PCIE device type ParamId
           }
*/

/** @addtogroup get_com_dev_info
@{ */

/**
   Parameter ID identifying the format of the common device information
   structure.

   @sa
   AcdbCommonDeviceInfoType
*/
#define ACDB_COMMON_DEVICE_INFO_HDR_PARAM                          0x000112A7

/**
   Parameter ID identifying an I2S device type.
*/
#define ACDB_DEVICE_TYPE_I2S_PARAM                           0x00012A50
/**
   Parameter ID identifying a PCM device type.
*/
#define ACDB_DEVICE_TYPE_PCM_PARAM                           0x00012A51
/**
   Parameter ID identifying a Slimbus device type.
*/
#define ACDB_DEVICE_TYPE_SLIMBUS_PARAM                       0x00012A52
/**
   Parameter ID identifying a digital microphone (mic) device type.
*/
#define ACDB_DEVICE_TYPE_DIGITAL_MIC_PARAM                   0x00012A53
/**
   Parameter ID identifying an HDMI device type.
*/
#define ACDB_DEVICE_TYPE_HDMI_PARAM                          0x00012A54
/**
   Parameter ID identifying a virtual device type.
*/
#define ACDB_DEVICE_TYPE_VIRTUAL_PARAM                       0x00012A55
/**
   Parameter ID identifying interal Bluetooth and FM device types.
*/
#define ACDB_DEVICE_TYPE_INT_BTFM_PARAM                      0x00012A56
/**
   Parameter ID identifying an RT proxy device type.
*/
#define ACDB_DEVICE_TYPE_RT_PROXY_PARAM                      0x00012A57
/**
   Parameter ID identifying a simple device type.
*/
#define ACDB_DEVICE_TYPE_SIMPLE_PARAM                      0x00012A58

/**
   Parameter ID identifying a TDM device type. 
*/
#define ACDB_DEVICE_TYPE_TDM_PARAM                            0x000131E9

/**
	Parameter ID identifying a USB device type.
*/
#define ACDB_DEVICE_TYPE_USB_PARAM                            0x000102A4
/**
   Parameter ID identifying a simple device type V2.
*/
#define ACDB_DEVICE_TYPE_SIMPLE_PARAM_V2                            0x00011328

/**
	Parameter ID identifying a PCIE device type.
*/
#define ACDB_DEVICE_TYPE_PCIE_PARAM                            0x00013338

/** @} */ /* end_addtogroup get_com_dev_info */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_TARGET_SPECIFIC_DEVICE_INFO Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_tgt_spec_dev_info
@{ */

/**
   Queries for the target-specific device information describing
   the device properties of a specified device ID.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_TARGET_SPECIFIC_DEVICE_INFO.
   @param[in] pCommandStruct
         Pointer to AcdbDeviceInfoTargetSpecificCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbDeviceInfoTargetSpecificCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   @vertspace{-10}
   @sa
   acdb_ioctl \n
   _AcdbDeviceInfoTargetSpecificCmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_TARGET_SPECIFIC_DEVICE_INFO               0x00011291

/**
   Query command structure for target-specific device information. The return
   buffer format is determined by the parameter ID as one of the keys to
   accessing the ACDB.
@code
   struct _AcdbDeviceInfoTargetSpecificRspType
   {
      uint16_t   ulPayloadMajorVersion;
      uint16_t   ulPayloadMinorVersion;
      uint8_t payload[payloadsize];   // Payload size is identified by the
                                      target-specific device structure size.
   } AcdbDeviceInfoTargetSpecificRspType

   // I2S Device Type
        ulPayloadMajorVersion = 0x0001
        ulPayloadMinorVersion = 0x0000
          This is the parameter ID identifying the format of the I2S device
          information structure.
   struct
   {
      uint32_t   ulCodecPathId;
      uint32_t   ulAfePortId;            // Refer to the AFE interface for
                                           valid/supported values
      uint32_t   ulAfeChannelMode;       // Refer to the AFE interface for
                                           valid/supported values
      uint32_t   ulAfeMonoStereo;        // Refer to the AFE interface for
                                           valid/supported values
      uint32_t   ulAfeWordSyncSrcSelect; // Refer to the AFE interface for
                                           valid/supported values
      uint32_t   ulBitsPerSampleMask;    // Refer to enum
                                           AcdbAfeBytesPerSampleType for
                                           supported values
      uint32_t   ulChannelConfig;        // Refer to enum AcdbChannelConfigType
                                           for supported values
      uint32_t   ulI2SMClkMode;          // Refer to enum AcdbI2sMClkModeType
                                           for supported values
      uint32_t   ulSampleRateMask;       // Refer to enum AcdbSampleRateMaskType
                                           for supported values
      uint32_t  ulDirectionMask;        // Refer to enum AcdbDirectionMaskType
                                           for supported values
      uint32_t  ulAfeDataType;          // Refer to the AFE interface for
                                           valid/supported values
   }

   // PCM Device Type
        ulPayloadMajorVersion = 0x0001
        ulPayloadMinorVersion = 0x0000
          This is the parameter ID identifying the format of the PCM device
          information structure.
   struct
   {
      uint32_t   ulAfePortId;                // Refer to the AFE interface for
                                               valid/supported values
      uint32_t   ulAfeAuxMode;               // Refer to the AFE interface for
                                               valid/supported values
      uint32_t   ulAfeSyncSrcSelect;         // Refer to the AFE interface for
                                               valid/supported values
      uint32_t   ulAfeFrameSetting;          // Refer to the AFE interface for
                                               valid/supported values
      uint32_t   ulAfeQuantType;             // Refer to the AFE interface for
                                               valid/supported values
      uint32_t   ulAfeDataOutEnableCtrl;     // Refer to the AFE interface for
                                               valid/supported values
      uint32_t  ulBitsPerSampleMask;        // Refer to enum
                                               AcdbAfeBytesPerSampleType for
                                               supported values
      uint32_t  ulChannelConfig;            // Refer to enum
                                               AcdbChannelConfigType for
                                               supported values
      uint32_t   ulSampleRateMask;           // Refer to enum
                                               AcdbSampleRateMaskType for
                                               supported values
      uint32_t   ulDirectionMask;            // Refer to enum
                                               AcdbDirectionMaskType for
                                               supported values
      uint16_t  uwAfeSlotNumberMapping[4];  // Refer to the AFE interface for
                                               valid/supported values
   }

        ulPayloadMajorVersion = 0x0001
        ulPayloadMinorVersion = 0x0001
          This is the parameter ID identifying the format of the PCM device
          information structure.
   struct
   {
      uint32_t   ulAfePortId;                // Refer to the AFE interface for
                                               valid/supported values
      uint32_t   ulAfeAuxMode;               // Refer to the AFE interface for
                                               valid/supported values
      uint32_t   ulAfeSyncSrcSelect;         // Refer to the AFE interface for
                                               valid/supported values
      uint32_t   ulAfeFrameSetting;          // Refer to the AFE interface for
                                               valid/supported values
      uint32_t   ulAfeQuantType;             // Refer to the AFE interface for
                                               valid/supported values
      uint32_t   ulAfeDataOutEnableCtrl;     // Refer to the AFE interface for
                                               valid/supported values
      uint32_t  ulBitsPerSampleMask;        // Refer to enum
                                               AcdbAfeBytesPerSampleType for
                                               supported values
      uint32_t  ulChannelConfig;            // Refer to enum
                                               AcdbChannelConfigType for
                                               supported values
      uint32_t   ulSampleRateMask;           // Refer to enum
                                               AcdbSampleRateMaskType for
                                               supported values
      uint32_t   ulDirectionMask;            // Refer to enum
                                               AcdbDirectionMaskType for
                                               supported values
      uint16_t  uwAfeSlotNumberMapping[4];  // Refer to the AFE interface for
                                               valid/supported values
      // The following param is the addition for the major=1, minor=1 revision
      uint32_t  ulMuxSel;                   // Refer to enum AcdbPCMMuxType for
                                               supported values
   }

   // Slimbus Device Type
        ulPayloadMajorVersion = 0x0001
        ulPayloadMinorVersion = 0x0000
          This is the parameter ID identifying the format of the
          SlimBus device information structure.
   #define AFE_PORT_MAX_AUDIO_CHAN_CNT 8
   struct {
      uint32_t ulCodecPathId;
      uint32_t ulBitsPerSampleMask;  // Refer to enum AcdbAfeBytesPerSampleType
                                        for supported values
      uint32_t ulChannelConfig       // Refer to enum AcdbChannelConfigType
                                        for supported values
      uint32_t ulSampleRateMask;     // Refer to enum AcdbSampleRateMaskType
                                        for supported values
      uint32_t ulDirectionMask;      // Refer to enum AcdbDirectionMaskType
                                        for supported values
      uint32_t ulAfePortId;          // Refer to the AFE interface for
                                        valid/supported values
      uint32_t ulAfeSlimbusDevID;    // Refer to the AFE interface for
                                        valid/supported values
      uint32_t ulAfeDataFormat;      // Refer to the AFE interface for
                                        valid/supported values
      uint8_t ulAfeSharedChannel[AFE_PORT_MAX_AUDIO_CHAN_CNT ]; // Refer to the
                                       AFE interface for valid/supported values
    }

   // Digital Mic Device Type
        ulPayloadMajorVersion = 0x0001
        ulPayloadMinorVersion = 0x0000
          This is the parameter ID identifying the format of the digital mic
          device information structure.
   struct
   {
      uint32_t   ulAfePortId;         // Refer to the AFE interface for
                                        valid/supported values
      uint32_t   ulAfeChannelMode;    // Refer to the AFE interface for
                                        valid/supported values
      uint32_t   ulBitsPerSampleMask; // Refer to enum AcdbAfeBytesPerSampleType
                                        for supported values
      uint32_t ulChannelConfig;      // Refer to enum AcdbChannelConfigType
                                        for supported values
      uint32_t   ulMasterClkMode;     // Refer to enum AcdbI2sMClkModeType
                                        for supported values
      uint32_t   ulSampleRateMask;    // Refer to enum AcdbSampleRateMaskType
                                        for supported values
      uint32_t ulDirectionMask;      // Refer to enum AcdbDirectionMaskType
                                        for supported values
   }

   // HDMI Device Type
        ulPayloadMajorVersion = 0x0001
        ulPayloadMinorVersion = 0x0000
          This is the parameter ID identifying the format of the HDMI device
          information structure.
   struct
   {
      uint32_t   ulAfePortId;         // Refer to the AFE interface for
                                        valid/supported values
      uint32_t   ulAfeChannelMode;    // Refer to enum
                                        AcdbAfeChannelModeHDMIType for
                                        supported values
      uint32_t   ulAfeDataType        // Refer to the AFE interface for
                                        valid/supported values
      uint32_t   ulBitsPerSampleMask; // Refer to enum AcdbAfeBytesPerSampleType
                                        for supported values
      uint32_t ulChannelConfig;      // Refer to enum AcdbChannelConfigType
                                        for supported values
      uint32_t ulSampleRateMask;     // Refer to enum AcdbSampleRateMaskType
                                        for supported values
      uint32_t ulDirectionMask;      // Refer to enum AcdbDirectionMaskType
                                        for supported values
   }

   // Virtual Device Type
        ulPayloadMajorVersion = 0x0001
        ulPayloadMinorVersion = 0x0000
         This is the parameter ID identifying the format of the virtual device
         information structure.
   struct
   {
      uint32_t  ulAfePortId;         // Refer to the AFE interface for
                                        valid/supported values
      uint32_t  ulBitsPerSampleMask; // Refer to enum AcdbAfeBytesPerSampleType
                                        for supported values
      uint32_t  ulChannelConfig;     // Refer to enum AcdbChannelConfigType
                                        for supported values
      uint32_t  ulAfeTimingMode;     // Refer to the AFE interface for
                                        valid/supported values
      uint32_t  ulSampleRateMask;    // Refer to enum AcdbSampleRateMaskType
                                        for supported values
      uint32_t  ulDirectionMask;     // Refer to enum AcdbDirectionMaskType
                                        for supported values
      uint32_t  ulAfeDataType;       // Refer to the AFE interface for
                                        valid/supported values
   }

   // INT BTFM Device Type
        ulPayloadMajorVersion = 0x0001
        ulPayloadMinorVersion = 0x0000
          This is the parameter ID identifying the format of the INT BTFM
          device information structure.
   struct
   {
      uint32_t   ulAfePortId;         // Refer to the AFE interface for
                                        valid/supported values
      uint32_t   ulBitsPerSampleMask; // Refer to enum AcdbAfeBytesPerSampleType
                                        for supported values
      uint32_t   ulChannelConfig;     // Refer to enum AcdbChannelConfigType
                                        for supported values
      uint32_t   ulSampleRateMask;    // Refer to enum AcdbSampleRateMaskType
                                        for supported values
      uint32_t   ulDirectionMask;     // Refer to enum AcdbDirectionMaskType
                                        for supported values
   }

   // RT Proxy Device Type
        ulPayloadMajorVersion = 0x0001
        ulPayloadMinorVersion = 0x0000
          This is the parameter ID identifying the format of the RT proxy
          device information structure.
   struct
   {
      uint32_t  ulSampleRateMask;       // Refer to enum AcdbSampleRateMaskType
                                           for supported values
      uint32_t  ulChannelConfig;        // Refer to enum AcdbChannelConfigType
                                           for supported values
      uint32_t  ulDirectionMask;        // Refer to enum AcdbDirectionMaskType
                                           for supported values
      uint32_t  ulAfePortId;            // Refer to the AFE interface for
                                           valid/supported values
      uint32_t  ulAfeBitsPerSampleMask;   // Refer to enum
                                           AcdbAfeBytesPerSampleType for
                                           supported values
   }

   // Simple Device Type
        ulPayloadMajorVersion = 0x0001
        ulPayloadMinorVersion = 0x0000
          This is the parameter ID identifying the format of the simple
          device information structure.
   struct
   {
      uint32_t  ulSampleRateMask;    // Refer to enum AcdbSampleRateMaskType
                                        for supported values
      uint32_t  ulChannelConfig;     // Refer to enum AcdbChannelConfigType
                                        for supported values
      uint32_t  ulDirectionMask;     // Refer to enum AcdbDirectionMaskType
                                        for supported values
      uint32_t  ulBitsPerSampleMask; // Refer to enum AcdbAfeBytesPerSampleType
                                        for supported values
   }
   //TDM device type paramID -0x000131E9

    ulPayloadMajorVersion = 0x0001
        ulPayloadMinorVersion = 0x0000
          This is the parameter ID identifying the format of the TDM device
          information structure.
   struct 
	{
      uint32_t   ulCodecPathId;
      uint32_t   ulAfePortId;            // Refer to the AFE interface for afeportid
                                           valid/supported values
    uint32_t  ulSampleRateMask;    // Refer to enum AcdbSampleRateMaskType
                                        for supported values
    uint32_t  ulChannelConfig;     // Refer to enum AcdbChannelConfigType
                                        for supported values
    uint32_t  ulDirectionMask;     // Refer to enum AcdbDirectionMaskType
                                        for supported values
    uint32_t  ulBitsPerSampleMask; // Refer to enum AcdbAfeBytesPerSampleType
                                        for supported values
    uint16_t  ulAfeDataFormat;     // Refer to enum AFE interface for supported values, Data format: linear and compressed
    uint16_t  uwSyncMode;        // Refer to enum AFE_PORT_TDM_SHORT_SYN interface for supported values ,TDM synchronization setting 

    uint16_t  uwSyncSrc;         // Refer to enum AFE_PORT_TDM_SYNC_SRC_ interface for supported values,  Synchronization source

    uint16_t uwSlotsPerFrame;     // Refer to  AFE interface for supported values  values 1 - 32 

    uint16_t  uwCtrlDataOutEnable;    // Refer to enum AFE_PORT_TDM_CTRL_DATA interface for supported values  
    uint16_t  uwCtrlInvertSyncPulse;   // Refer to enum AFE_PORT_TDM_SYNC interface for supported values  

    uint16_t  uwCtrlSyncDataDelay;    // Refer to enum AFE_PORT_TDM_DATA_DELAY interface for supported values  

    uint16_t  uwSlotWidth;           // Refer to  AFE interface for supported values ,Slot width of the slot in a TDM frame 16,24,32

    uint32_t  uwSlotMask;            // Refer to  AFE interface for supported values ,Position of active slots values 1 to 2^32 ? 1 
	}

	// USB Device Type
        ulPayloadMajorVersion = 0x0001
        ulPayloadMinorVersion = 0x0000
          This is the parameter ID identifying the format of the USB
          device information structure.
   struct
   {
      uint32_t  ulAfeBitsPerSampleMask;    // Refer to enum AcdbSampleRateMaskType
                                        for supported values
      uint32_t  ulChannelConfig;     // Refer to enum AcdbChannelConfigType
                                        for supported values
	  uint32_t  ulSampleRateMask;    // Refer to enum AcdbSampleRateMaskType
                                        for supported values
      uint32_t  ulDirectionMask;     // Refer to enum AcdbDirectionMaskType
                                        for supported values
      uint32_t   ulAfePortId;            // Refer to the AFE interface for afeportid
                                           valid/supported values
	 uint32_t  ulAfeDataFormat;     // Refer to enum AFE interface for supported values, Data format: linear and compressed
   }

   // PCIE Device Type
        ulPayloadMajorVersion = 0x0001
        ulPayloadMinorVersion = 0x0000
          This is the parameter ID identifying the format of the PCIE
          device information structure.
   struct
   {
      uint32_t   ulAfePortId;            // Refer to the AFE interface for afeportid
                                           valid/supported values

	  uint32_t  ulSampleRateMask;    // Refer to enum AcdbSampleRateMaskType
                                        for supported values

      uint16_t  ulBitsPerSampleMask; // Refer to enum AcdbAfeBytesPerSampleType
                                        for supported values

      uint16_t  ulChannelConfig;     // Refer to enum AcdbChannelConfigType
                                        for supported values

	  uint32_t  ulAfeDataFormat;     // Refer to AFE interface for valid/supported values

	  uint32_t  frame_size;         // Refer to the AFE interface for frame size valid/supported values.

	  uint32_t  timer_source;        //Refer to the AFE interface for timer_source valid/supported values.
	  
	  uint32_t  ulDirectionMask;     // Refer to enum AcdbDirectionMaskType.
   }
@endcode
 */

typedef struct _AcdbDeviceInfoTargetSpecificCmdType AcdbDeviceInfoTargetSpecificCmdType;
#include "acdb_begin_pack.h"

struct _AcdbDeviceInfoTargetSpecificCmdType {
   uint32_t nDeviceId;
     /**< Device ID. */
   uint32_t nDeviceType;
     /**< Device type ID query from the common device information. */
   uint32_t nBufferLength;
     /**< Length of the buffer. This must be large enough to hold the entire
          device information structure identified by nParamId. */
   uint8_t *pBufferPointer;
     /**< Virtual memory pointer to the memory region into which the
          ACDB is to copy the device information. */
}

#include "acdb_end_pack.h"
;
/** @} */ /* end_addtogroup get_tgt_spec_dev_info */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_VOCPROC_COMMON_TOPOLOGY_ID Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_vocproc_com_topol_id
@{ */

/**
   Queries for the VocProc COPP topology ID.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_VOCPROC_COMMON_TOPOLOGY_ID.
   @param[in] pCommandStruct
         Pointer to AcdbGetVocProcTopIdCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbGetVocProcTopIdCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbGetTopologyIdRspType.
   @param[out] nResponseStructLength
         Length must equal the size of AcdbGetTopologyIdRspType.

   @return
   - ACDB_SUCCESS Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_PARMNOTFOUND -- Parameter data not found for the specified device ID.

   @sa
   acdb_ioctl \n
   _AcdbGetVocProcTopIdCmdType \n
   _AcdbGetTopologyIdRspType
*/
#define ACDB_CMD_GET_VOCPROC_COMMON_TOPOLOGY_ID                 0x00011292

/**
   Query command structure for getting the VocProc COPP topology ID.
*/
typedef struct _AcdbGetVocProcTopIdCmdType {
   uint32_t nDeviceId;                 /**< Device ID. */
} AcdbGetVocProcTopIdCmdType;

/** @} */ /* end_addtogroup get_vocproc_com_topol_id */

/** @addtogroup acdb_datatypes
@{ */

/**
   @vertspace{-3}
   ID for a specific calibration module for Multi-button Headset Controller
   (MBHC).
*/
#define ACDB_MID_MBHC                                 0x000112E5

/**
   @vertspace{-3}
   ID for the calibration parameter GENERAL_CONFIG in the MBHC module.
   The ACDB_CMD_GET_GLBTBL_DATA IOCTL call must be used to get the data for
   this PID.

   The output of the ACDB_CMD_GET_GLBTBL_DATA IOCTL call for this PID is in
   the following structure format:
@code
   struct gen_config
   {
      uint8_t     MBHC_Tldoh;
      uint8_t     MBHC_TbgFastSettle;
      uint8_t     MBHC_TshutDownPlugRem;
      uint8_t     MBHC_NSA;
      uint8_t     MBHC_Navg;
      uint8_t     MBHC_VmicBiasL;
      uint8_t     MBHC_VmicBias;
      uint8_t     reserve;
      uint16_t    MBHC_SettleWait;
      uint16_t    TmicbiasRampup;
      uint16_t    TmicbiasRampdown;
      uint16_t    MBHC_TsupplyBringup;
   };

@endcode
*/
#define ACDB_PID_GENERAL_CONFIG                                 0x000112E6

/**
   @vertspace{-2}
   ID for the calibration parameter PLUG_REMOVAL_DETECTION in the MBHC module.
   The ACDB_CMD_GET_GLBTBL_DATA IOCTL call must be used to get the data for
   this PID.

   The output of the ACDB_CMD_GET_GLBTBL_DATA IOCTL call for this
   PID is in the following structure format:
@code
    struct removal_detect
   {
      uint32_t    MBHC_Current_MIC_MBHC_PIDmicCurrent;
      uint32_t    MBHC_Current_HPH_MBHC_PIDhphCurrent;
      uint16_t    MBHC_TmicPid;
      uint16_t    MBHC_TinsCompl;
      uint16_t    MBHC_TinsRetry;
      uint16_t    MBHC_VremovalDelta;
      uint8_t     MBHC_micbiasSlowRamp;
      uint8_t     reserve;
      uint8_t     reserve1;
      uint8_t     reserve2;
   };

@endcode
*/
#define ACDB_PID_PLUG_REMOVAL_DETECTION                     0x000112E7

/**
   @vertspace{-2}
   ID for the calibration parameter PLUG_TYPE_DETECTION in the MBHC module.
   The ACDB_CMD_GET_GLBTBL_DATA IOCTL call must be used to get the data for
   this PID.

   The output of the ACDB_CMD_GET_GLBTBL_DATA IOCTL call for this PID is in
   the following structure format:
@code
   struct type_detection
   {
      uint8_t    MBHC_AVdetect;
      uint8_t    MBHC_MonoDetect;
      uint8_t    MBHC_NinsTries;
      uint8_t    reserve;
      int16_t    MBHC_VnoMic;
      int16_t    MBHC_VavMin;
      int16_t    MBHC_VavMax;
      int16_t    MBHC_VHSMin;
      int16_t    MBHC_VHSMax;
      uint16_t   reserve2;
   };

@endcode
*/
#define ACDB_PID_PLUG_TYPE_DETECTION                     0x000112E8

/**
   ID for the specific calibration parameter BUTTON_PRESS_DETECTION in the MBHC
   module. The ACDB_CMD_GET_GLBTBL_DATA IOCTL call must be used to get the data
   for this PID.

   The output of the ACDB_CMD_GET_GLBTBL_DATA IOCTL call for this PID is in the
   following structure format:
@code
    struct press_detection
   {
      int8_t      MBHC_coeff[8];
      uint8_t     MBHC_Ncoeff;
      uint8_t     MBHC_Nmeas;
      uint8_t     MBHC_NSC;
      uint8_t     MBHC_NbutMeas;
      uint8_t     MBHC_NbutCon;
      uint8_t     MBHC_NumBut;
      uint8_t     reserve;
      uint8_t     reserve2;
      uint16_t    MBHC_Tpoll;
      uint16_t   MBHC_TBounceWait;
      uint16_t   MBHC_RelTimeOut;
      int16_t    MBHC_VButPressDeltaSTA;
      int16_t    MBHC_VButPressDeltaCIC;
      uint16_t    Tbutton0TimeOut;
      int16_t    MBHC_VButLow[MBHC_NumBut];
      int16_t    MBHC_VButHigh[MBHC_NumBut];
      uint8_t     MBHC_Nready[MBHC_NbutCon] ;
      uint8_t     MBHC_NCIC[MBHC_NbutCon];
      uint8_t     MBHC_Gain[MBHC_NbutCon];
   };

@endcode
*/
#define ACDB_PID_BUTTON_PRESS_DETECTION                     0x000112E9

/**
ID for the specific calibration parameter BUTTON_PRESS_DETECTION_CURRENT_SOURCE in the MBHC
module. The ACDB_CMD_GET_GLBTBL_DATA IOCTL call must be used to get the data
for this PID.

The output of the ACDB_CMD_GET_GLBTBL_DATA IOCTL call for this PID is in the
following structure format:
@code
struct press_detection_current_source
{
int8_t MBHC_coeff[8];
uint8_t MBHC_Ncoeff;
uint8_t MBHC_Nmeas;
uint8_t MBHC_NSC;
uint8_t MBHC_NbutMeas;
uint8_t MBHC_NbutCon;
uint8_t MBHC_NumBut;
uint8_t reserve;
uint8_t reserve2;
uint16_t MBHC_Tpoll;
uint16_t MBHC_TBounceWait;
uint16_t MBHC_RelTimeOut;
int16_t MBHC_VButPressDeltaSTA;
int16_t MBHC_VButPressDeltaCIC;
uint16_t Tbutton0TimeOut;
int16_t MBHC_VButLow[MBHC_NumBut];
int16_t MBHC_VButHigh[MBHC_NumBut];
uint8_t MBHC_Nready[MBHC_NbutCon] ;
uint8_t MBHC_NCIC[MBHC_NbutCon];
uint8_t MBHC_Gain[MBHC_NbutCon];
};

@endcode
*/
#define ACDB_PID_BUTTON_PRESS_DETECTION_CURRENT_SOURCE 0x000130FE

/**
ID for the specific calibration parameter BUTTON_PRESS_DETECTION_DEBUG_MODE in the MBHC
module. The ACDB_CMD_GET_GLBTBL_DATA IOCTL call must be used to get the data
for this PID.

The output of the ACDB_CMD_GET_GLBTBL_DATA IOCTL call for this PID is in the
following structure format:
@code
struct press_detection_debug_mode
{
uint16_t Button_press_debug_mode_enable;
uint16_t reserve1;
uint16_t reserve2;
uint16_t reserve3;
};

@endcode
*/
#define ACDB_PID_BUTTON_PRESS_DETECTION_DEBUG_MODE 0x000130FF

/**
   ID for the calibration parameter IMPEDANCE_DETECTION in the MBHC module.
   The ACDB_CMD_GET_GLBTBL_DATA IOCTL call must be used to get the data for
   this PID.

   The output of the ACDB_CMD_GET_GLBTBL_DATA IOCTL call for this PID is in
   the following structure format:
@code
    struct impedance_detection
   {
      int8_t      MBHC_HeadSetImpDet;
      uint8_t     MBHC_NumRload;
      int8_t      MBHC_HPHkeepon;
      uint8_t     MBHC_RepeatRloadCalc;
      uint16_t    MBHC_DacRampTime;
      uint16_t    MBHC_RhphHigh;
      uint16_t    MBHC_Rhphlow;
      uint16_t    MBHC_rload[MBHC_NumRload];
      uint16_t    MBHC_alpha[MBHC_NumRload];
      uint16_t    MBHC_beta[3];
   };

@endcode
*/
#define ACDB_PID_IMPEDANCE_DETECTION                     0x000112EA

/**
   This ID is to use for a specific calibration param Id MBHC_ADVANCED_CONFIG in MBHC module.
   ACDB_CMD_GET_GLBTBL_DATA IOCTL call should be used to get the data for this PID
   The output of ACDB_CMD_GET_GLBTBL_DATA IOCTL call for this PID results in the below structure format.
@code
   struct advance_config
   {
      uint16_t    MBHC_ACDB_STATE;
      uint16_t    Headset_micbias_no;
      uint16_t    Headset_cfilt_no;
      uint16_t    Headset_micbias_voltage;
      uint8_t     HPHL_mechanical_switch;
      uint8_t     Ground_detect_switch;
      uint8_t     HPHL_det_normally_open_closed_sel;
      uint8_t     Ground_det_normally_open_closed_sel;
      uint8_t     Headset_micbias_pulldown_switch;
      uint8_t     Ext_byp_cap_mode_enabled;
      uint8_t     Anc_headset_detection_enabled;
      uint8_t     Detection_polling_support;
      uint32_t    Insertion_polling_interval;
      uint32_t    Removal_polling_interval;
      uint16_t    Detection_state_reconfirm_delay;
      uint16_t    Successive_detection_measurement_delay;
      uint16_t    Impedance_detect_delay_1;
      uint16_t    Impedance_detect_delay_2;
      uint16_t    Reserved1;
      uint16_t    Reserved2;
      uint16_t    Reserved3;
      uint16_t    Reserved4;
   };
*/
#define ACDB_PID_MBHC_ADVANCED_CONFIG                          0x00012EFF

/**
   This ID is to use for a specific calibration param Id MBHC_CURRENT_SOURCE_CONFIG in MBHC module.
   ACDB_CMD_GET_GLBTBL_DATA IOCTL call should be used to get the data for this PID
   The output of ACDB_CMD_GET_GLBTBL_DATA IOCTL call for this PID results in the below structure format.
@code
   struct current_source_config
   {
      uint16_t    MBHC_CS_VnoMic;
      uint16_t    MBHC_CS_VHSMax;
      uint16_t    MBHC_CS_InvalidRangeLow_mv;
      uint16_t    MBHC_CS_InvalidRangeHigh_mv;
      uint16_t    Reserved1;
      uint16_t    Reserved2;
      uint16_t    Reserved3;
      uint16_t    Reserved4;
   };
*/
#define ACDB_PID_MBHC_CURRENT_SOURCE_CONFIG                    0x00012F00

/**
   This ID is to use for a specific calibration param Id MBHC_ADVANCED_CONFIG2 in MBHC module.
   ACDB_CMD_GET_GLBTBL_DATA IOCTL call should be used to get the data for this PID
   The output of ACDB_CMD_GET_GLBTBL_DATA IOCTL call for this PID results in the below structure format.
@code
   struct advance_config2
   {
      uint16_t    Secondary_anc_mic_detection_state;
      uint16_t    Secondary_anc_mic_use_default_primary;
      uint16_t    Headset_jack_type;
      uint16_t    Secondary_anc_mic_use_current_source_for_detection;
      uint16_t    Secondary_anc_mic_headset_micbias_no;
      uint16_t    Secondary_anc_mic_headset_cfilt_no;
      uint16_t    Secondary_anc_mic_headset_micbias_voltage;
      uint16_t    Secondary_anc_mic_ext_byp_cap_mode_enabled;
      uint16_t    Secondary_anc_mic_detection_no_of_attempts;
      uint16_t    Secondary_anc_mic_successive_measurement_delay;
      uint16_t    Secondary_anc_mic_invalid_range_low_mv;
      uint16_t    Secondary_anc_mic_invalid_range_high_mv;
      uint16_t    Secondary_anc_mic_enable_polling_after_detection;
      uint16_t    Reserved1;
      uint16_t    Reserved2;
      uint16_t    Reserved3;
   };
*/
#define ACDB_PID_MBHC_ADVANCED_CONFIG2                          0x00013075

/**
   @vertspace{-3}
   ID for a specific calibration module for VBAT Monitor feature
   (VBAT).
*/
#define ACDB_MID_VBAT_MONITOR  0x000131D1

/**
   @vertspace{-3}
   ID for the calibration parameter ADC_CAL in the VBAT Monitor module.
   The ACDB_CMD_GET_GLBTBL_DATA IOCTL call must be used to get the data for
   this PID.

   The output of the ACDB_CMD_GET_GLBTBL_DATA IOCTL call for this PID is in
   the following structure format:
@code
   struct gen_config
   {
      uint16_t     version;
      uint16_t     Auto_Cal_Enable;
      uint16_t     D_Slope;
      int16_t      D_Bias;
   };

@endcode
*/
#define ACDB_PID_ADC_CAL  0x000131D2

/**
   @vertspace{-2}
   ID for the calibration parameter GAIN_PROC in the VBAT Monitor module.
   The ACDB_CMD_GET_GLBTBL_DATA IOCTL call must be used to get the data for
   this PID.

   The output of the ACDB_CMD_GET_GLBTBL_DATA IOCTL call for this
   PID is in the following structure format:
@code
    struct removal_detect
   {
      uint16_t    version;
      uint16_t    Vbat_Mode;
      uint16_t    Vbat_Alpha_Select;
      uint16_t    Vbat_Rx_Peak_Block_Select;
      int16_t     Vbat_Rx_Signal_Threshold;
      uint16_t    Vbat_RF_Vbat_Down;
      uint16_t    Vbat_RF_Vbat_Trip_Point;
      uint16_t    Vbat_Trip_Point;
      uint16_t    Vbat_Max_Attenuation;
      int16_t     Vbat_Max_Limiter_Level;
	  uint16_t    Vbat_Slope_Select;
	  uint16_t    Vbat_Attack_Time;
	  uint16_t    Vbat_Release_Time;
	  uint16_t    Vbat_dBStep;
   };

@endcode
*/
#define ACDB_PID_GAIN_PROC  0x000131D3

/** @} */ /* end_addtogroup acdb_datatypes */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AFE_COMMON_TABLE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_afe_com_tbl
@{ */

/**
   Queries for an AFE common calibration table in the Hexagon table format.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AFE_COMMON_TABLE.
   @param[in] pCommandStruct
         Pointer to AcdbAfeCommonTableCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAfeCommonTableCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.
   @vertspace{-10}
   @sa
   acdb_ioctl \n
   _AcdbAfeCommonTableCmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_AFE_COMMON_TABLE    0x000112EF

/**
   Query command structure for getting
   calibration data in the AFE VocProc data tables.

   The format of the table matches the Hexagon API table format:
@code
      struct AfeCommonTableEntry {
         uint32_t nModuleId;
         uint32_t nParamId;
         uint16_t nParamSize; //multiple of 4
         uint16_t nReserved; // Must be 0
         uint8 aParamData [multiple of 4)];
     }

@endcode
*/
typedef struct _AcdbAfeCommonTableCmdType AcdbAfeCommonTableCmdType;
#include "acdb_begin_pack.h"

struct _AcdbAfeCommonTableCmdType {
   uint32_t nDeviceId;
     /**< Tx/Rx device ID. */
   uint32_t nSampleRateId;
     /**< AFE sample rate ID in Hz. */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the entire table. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to the memory region into which the
          ACDB is to copy the table. */
}

#include "acdb_end_pack.h"
;

/** @} */ /* end_addtogroup get_afe_com_tbl */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AFE_COMMON_DATA
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_afe_com_data
@{ */

/**
   Queries for specific AFE common calibration data.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AFE_COMMON_DATA.
   @param[in] pCommandStruct
         Pointer to AcdbAfeCmnDataCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAfeCmnDataCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_PARMNOTFOUND -- Parameter data not found.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.
   @vertspace{-10}
   @sa
   acdb_ioctl \n
   _AcdbAfeCmnDataCmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_AFE_COMMON_DATA                                     0x000112FD

/**
   Query command structure for getting
   calibration data in the AFE common data tables.
*/
typedef struct _AcdbAfeCmnDataCmdType AcdbAfeCmnDataCmdType;
#include "acdb_begin_pack.h"

struct _AcdbAfeCmnDataCmdType {
   uint32_t nDeviceId;
     /**< Device ID. */
   uint32_t nAfeSampleRateId;
     /**< AFE sample rate ID in Hz. */
   uint32_t nModuleId;
     /**< Module ID. */
   uint32_t nParamId;
     /**< Parameter ID of the module for which to query. */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the parameters identified by the  nParamId identifier. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to a memory region containing the
          payload (or receiving the payload) identified by nParamId. */
}

#include "acdb_end_pack.h"
;

/** @} */ /* end_addtogroup get_afe_com_data */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_COMPATIBLE_REMOTE_DEVICE_ID Declarations and Documentation
 * --------------------------------------------------------------------------- */

/** @addtogroup get_comp_remote_dev_id
@{ */

/**
   Queries for a compatible device ID on the remote processor for a specified
   device ID on the local processor.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_COMPATIBLE_REMOTE_DEVICE_ID.
   @param[in] pCommandStruct
         Pointer to AcdbGetRmtCompDevIdCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbGetRmtCompDevIdCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbGetRmtCompDevIdRspType.
   @param[out] nResponseStructLength
         Length must equal the size of AcdbGetRmtCompDevIdRspType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_PARMNOTFOUND -- Parameter data not found for the specified device ID.

   @sa
   acdb_ioctl \n
   _AcdbGetRmtCompDevIdCmdType \n
   _AcdbGetRmtCompDevIdRspType
*/
#define ACDB_CMD_GET_COMPATIBLE_REMOTE_DEVICE_ID                 0x00011331

/**
   Query command structure for getting the compatible remote device ID.
*/
typedef struct _AcdbGetRmtCompDevIdCmdType {
   uint32_t nNativeDeviceId;           /**< Device ID on the local proc. */
} AcdbGetRmtCompDevIdCmdType;

/**
   Response structure for getting the compatible remote device ID.
*/
typedef struct _AcdbGetRmtCompDevIdRspType {
   uint32_t nRmtDeviceId;            /**< Device ID on the remote processor. */
} AcdbGetRmtCompDevIdRspType;

/** @} */ /* end_addtogroup get_comp_remote_dev_id */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDIO_RECORD_RX_DEVICE_LIST Declarations and Documentation
 * --------------------------------------------------------------------------- */

/** @addtogroup get_audio_rec_rx_dev_list
@{ */

/**
   Queries for a list of valid Rx device IDs that are paired with a specified
   Tx device ID for the audio record use case using echo cancellation.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDIO_RECORD_RX_DEVICE_LIST.
   @param[in] pCommandStruct
         Pointer to AcdbAudioRecRxListCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudioRecRxListCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbAudioRecRxListRspType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbAudioRecRxListRspType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_PARMNOTFOUND -- Rx devices for the specified Tx device were not found.

   @sa
   acdb_ioctl \n
   _AcdbAudioRecRxListCmdType \n
   _AcdbAudioRecRxListRspType
*/
#define ACDB_CMD_GET_AUDIO_RECORD_RX_DEVICE_LIST                   0x0001134D

/**
   Query command structure for the list of Rx devices paired
   with the specified Tx device.
*/
typedef struct _AcdbAudioRecRxListCmdType {
   uint32_t nTxDeviceId;               /**< Tx device ID. */
} AcdbAudioRecRxListCmdType;

typedef struct _AcdbAudioRecRxListRspType AcdbAudioRecRxListRspType;
#include "acdb_begin_pack.h"

/**
   Response command structure for the list of Rx devices paired
   with the specified Tx device.
*/
struct _AcdbAudioRecRxListRspType {
   uint32_t nNoOfRxDevs;
     /**< Number of Rx devices paired with the specified input Tx device. If
          the specified Tx device is not paired with any of the Rx devcies,
          the value returned is 0. */
   uint32_t *pRxDevs;
     /**< Points to the array of Rx devices, each of which is type uint32_t. */
}

#include "acdb_end_pack.h"
;

/** @} */ /* end_addtogroup get_audio_rec_rx_dev_list */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_INITIALIZE_V2 Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup acdb_init
@{ */

/**
   Initializes the ACDB software with the list of ACDB files provided by the
   caller.

   @param[in] nCommandId
         Command ID is ACDB_CMD_INITIALIZE_V2.
   @param[in] pCommandStruct
         Pointer to the AcdbInitCmdType structure.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbInitCmdType.
   @param[out] pResponseStruct
         There is no output structure; set this to NULL.
   @param[in] nResponseStructLength
         There is no input structure; set this to 0.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- Initializaton failed.

   @sa
   acdb_ioctl
*/
#define ACDB_CMD_INITIALIZE_V2               0x0001138C

typedef struct _AcdbFileName AcdbFileName;
#include "acdb_begin_pack.h"

/**
   Structure to hold an individual ACDB file name and path.
*/
struct _AcdbFileName{
   uint32_t fileNameLen;
     /**< Full file path name length. */
   char fileName[ACDB_FILENAME_MAX_CHARS];
     /**< Array that holds the ACDB file path and name. The file size cannot
          exceed 256 characters, including the NULL-termiated character.
          @newpagetable */
}

#include "acdb_end_pack.h"
;

typedef struct _AcdbInitCmdType AcdbInitCmdType;
#include "acdb_begin_pack.h"

/**
   Query command structure for the command ACDB_CMD_INITIALIZE_V2.
*/
struct _AcdbInitCmdType {
   uint32_t nNoOfFiles;
     /**< Number of ACDB files to read from the acdbFiles array. */
   AcdbFileName acdbFiles[20];
     /**< Array of ACDB file names. A maximum of 20 ACDB files can be
          provided at one time to be initialized. */
}

#include "acdb_end_pack.h"
;
/** @} */ /* end_addtogroup acdb_init */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_ACDB_SW_VERSION Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_acdb_sw_ver
@{ */

/**
   Queries for the ACDB software version. Clients are to use this version
   to determine how best to interact with the ACDB software module.

   Rules governing the versioning of the API interface: \n
   - Major -- Incremented whenever there is a major adjustment to the ACDB that
              affects ACDB clients. This includes but is not limited to
              backward-incompatible API changes or drastic changes in memory
              usage.

    - Minor -- Incremented whenever there is a minor adjustment to the ACDB that
               does not affect existing ACDB clients. This incldues but is not
               limited to backward-compatible API changes, new capabilties, or
               new calibration structures.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_ACDB_SW_VERSION.
   @param[in] pCommandStruct
         There is no input structure; set this to NULL.
   @param[in] nCommandStructLength
         There is no input structure; set this to 0.
   @param[out] pResponseStruct
         Pointer to AcdbModuleVersionType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbModuleVersionType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   @vertspace{-6}

   @sa
   acdb_ioctl \n
   _AcdbModuleVersionType
   @newpage
*/
#define ACDB_CMD_GET_ACDB_SW_VERSION            0x0001138D

/**
   Response structure for the ACDB_CMD_GET_ACDB_SW_VERSION command, which
   enables the client to determine the ACDB API capabilities.
*/
typedef struct _AcdbModuleVersionType {
   uint16_t major;
     /**< Major version describing the capabilities of the ACDB API. */
   uint16_t minor;
     /**< Minor version describing the capabilities of the ACDB API. */
} AcdbModuleVersionType;

/** @} */ /* end_addtogroup get_acdb_sw_ver */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_VOC_PROC_DEVICE_CFG_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_vocproc_dev_cfg_size
@{ */

/**
   Queries for the size of the VocProc metadata associated with the specified
   voice device pair.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_VOC_PROC_DEVICE_CFG_SIZE.
   @param[in] pCommandStruct
         Pointer to AcdbVocProcDevCfgSizeCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbVocProcDevCfgSizeCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbVocProcDevCfgSizeCmdType \n
   _AcdbSizeResponseType
*/
#define ACDB_CMD_GET_VOC_PROC_DEVICE_CFG_SIZE    0x000113A3

/**
   Query command structure for getting the size of a device pair's metadata.
*/
typedef struct _AcdbVocProcDevCfgSizeCmdType {
   uint32_t nTxDeviceId;               /**< Tx device ID. */
   uint32_t nRxDeviceId;               /**< Rx device ID. */
} AcdbVocProcDevCfgSizeCmdType;

/** @} */ /* end_addtogroup get_vocproc_dev_cfg_size */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_VOC_PROC_DEVICE_CFG
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_vocproc_dev_cfg
@{ */

/**
   Queries for the voice device pair's specified VocProc configuration data.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_VOC_PROC_DEVICE_CFG.
   @param[in] pCommandStruct
         Pointer to AcdbVocProcDevCfgCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbVocProcDevCfgCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

       When the call is successful, the pBuff member of the AcdbVocProcDevCfgCmdType
       is filled with the configuration data in the following format:
   @code

        -----------32 Bit---------
       | mod_id                  |
       ---------------------------
       | param_id                |
        -------------------------
       | param_size | reserved   |
       ---------------------------
       | param_data              |
       |                         |
       | ...                     |
       ---------------------------
       | mod_id                  |
       .                         .
       .                         .
       .                         .

   @endcode

   @sa
   acdb_ioctl \n
   _AcdbVocProcDevCfgCmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_VOC_PROC_DEVICE_CFG    0x00011397

typedef struct _AcdbVocProcDevCfgCmdType AcdbVocProcDevCfgCmdType;
#include "acdb_begin_pack.h"

/**
   Query command structure for getting the voice device pair's specified
   VocProc configuration data.
*/
struct _AcdbVocProcDevCfgCmdType {
   uint32_t nTxDeviceId;
     /**< Tx device ID. */
   uint32_t nRxDeviceId;
     /**< Rx device ID. */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. */
   uint8_t *pBuff;
     /**< Virtual memory pointer to a memory region in which to fill
          the device pair metadata in the CVD format. */
}

#include "acdb_end_pack.h"
;

/** @} */ /* end_addtogroup get_vocproc_dev_cfg */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDIO_COPP_TOPOLOGIES  Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @ingroup get_audio_copp_topol

   Queries for the supported custom added topologies to set to the Audio Device
   Manager (ADM) custom table.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDIO_COPP_TOPOLOGIES.
   @param[in] pCommandStruct
         Pointer to AcdbQueryCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbQueryCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @vertspace{-12}
   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_DATA_NOT_FOUND -- COPP custom topologies data was not found.

   @vertspace{-8}
   If the command is successful, the pBufferPointer of the struct
   AcdbQueryCmdType is filled in the following format:
@code

  struct TopoInfo
  {
   uint32_t noOfTopologies;
   TopoDef pTopDefs[];
  };

  struct TopoDef
  {
   uint32_t topId;
   uint32_t noOfModules;
   ModuleInfo pModDefs[];
  };

  struct ModuleInfo
  {
   uint32_t modId;
   uint32_t useLpm;
   uint8_t init_params[16];
  };

@endcode
   @vertspace{-5}
   @sa
   acdb_ioctl
*/
#define ACDB_CMD_GET_AUDIO_COPP_TOPOLOGIES                0x00011394

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDIO_COPP_TOPOLOGIES_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @ingroup get_audio_copp_topol_size

   Queries for the size of the supported custom added topologies to set to
   the ADM common table.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDIO_COPP_TOPOLOGIES_SIZE.
   @param[in] pCommandStruct
         There is no input structure; set this to NULL.
   @param[in] nCommandStructLength
         There is no input structure; set this to 0.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- COPP custom topology information was not found.

   @sa
   acdb_ioctl \n
   _AcdbSizeResponseType
*/
#define ACDB_CMD_GET_AUDIO_COPP_TOPOLOGIES_SIZE    0x00012E07

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDIO_POPP_TOPOLOGIES  Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @ingroup get_audio_popp_topol

   Queries for the supported custom added POPP topologies to set to the ASM
   custom table.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDIO_POPP_TOPOLOGIES.
   @param[in] pCommandStruct
         Pointer to AcdbQueryCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbQueryCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_DATA_NOT_FOUND -- POPP custom topologies data was not found.

@vertspace{-4}
  If the command is successful, the pBufferPointer of the struct
  AcdbQueryCmdType is filled in the following format:
@code

  struct TopoInfo
  {
   uint32_t noOfTopologies;
   TopoDef pTopDefs[];
  };

  struct TopoDef
  {
   uint32_t topId;
   uint32_t noOfModules;
   ModuleInfo pModDefs[];
  };

  struct ModuleInfo
  {
   uint32_t modId;
   uint32_t useLpm;
   uint8_t init_params[16];
  };

@endcode
@vertspace{-2}
   @sa
   acdb_ioctl
*/
#define ACDB_CMD_GET_AUDIO_POPP_TOPOLOGIES                0x00012E01

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDIO_POPP_TOPOLOGIES_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @ingroup get_audio_popp_topol_size

   Queries for the size of the supported custom added POPP topologies.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDIO_POPP_TOPOLOGIES_SIZE.
   @param[in] pCommandStruct
         There is no input structure; set this to NULL.
   @param[in] nCommandStructLength
         There is no input structure; set this to 0.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- POPP custom topology information was not found.

   @sa
   acdb_ioctl \n
   _AcdbSizeResponseType
*/
#define ACDB_CMD_GET_AUDIO_POPP_TOPOLOGIES_SIZE    0x00012E08

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AFE_TOPOLOGIES  Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @ingroup get_afe_topol

   Queries for the supported custom added topologies to set to the Audio Front
   End (AFE) custom table.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AFE_TOPOLOGIES.
   @param[in] pCommandStruct
         Pointer to AcdbQueryCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbQueryCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @vertspace{-12}
   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_DATA_NOT_FOUND -- COPP custom topologies data was not found.

   @vertspace{-8}
   If the command is successful, the pBufferPointer of the struct
   AcdbQueryCmdType is filled in the following format:
@code

  struct TopoInfo
  {
   uint32_t noOfTopologies;
   TopoDef pTopDefs[];
  };

  struct TopoDef
  {
   uint32_t topId;
   uint32_t noOfModules;
   ModuleInfo pModDefs[];
  };

  struct ModuleInfo
  {
   uint32_t modId;
   uint32_t useLpm;
   uint8_t init_params[16];
  };

@endcode
   @vertspace{-5}
   @sa
   acdb_ioctl
*/
#define ACDB_CMD_GET_AFE_TOPOLOGIES                0x000130DA

/** @} */ /* end_addtogroup get_afe_topol */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AFE_TOPOLOGIES_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @ingroup get_afe_topol_size

   Queries for the size of the supported custom added topologies to set to
   the AFE common table.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AFE_TOPOLOGIES_SIZE.
   @param[in] pCommandStruct
         There is no input structure; set this to NULL.
   @param[in] nCommandStructLength
         There is no input structure; set this to 0.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- COPP custom topology information was not found.

   @sa
   acdb_ioctl \n
   _AcdbSizeResponseType
*/
#define ACDB_CMD_GET_AFE_TOPOLOGIES_SIZE    0x000130DB

/** @} */ /* end_addtogroup get_afe_topol_size */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_LSM_TOPOLOGIES  Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @ingroup get_lsm_topol

   Queries for the supported custom added LSM topologies to set to the LSM
   custom table.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_LSM_TOPOLOGIES.
   @param[in] pCommandStruct
         Pointer to AcdbQueryCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbQueryCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_DATA_NOT_FOUND -- POPP custom topologies data was not found.

@vertspace{-4}
  If the command is successful, the pBufferPointer of the struct
  AcdbQueryCmdType is filled in the following format:
@code

  struct TopoInfo
  {
   uint32_t noOfTopologies;
   TopoDef pTopDefs[];
  };

  struct TopoDef
  {
   uint32_t topId;
   uint32_t noOfModules;
   ModuleInfo pModDefs[];
  };

  struct ModuleInfo
  {
   uint32_t modId;
   uint32_t useLpm;
   uint8_t init_params[16];
  };

@endcode
@vertspace{-2}
   @sa
   acdb_ioctl
*/
#define ACDB_CMD_GET_LSM_TOPOLOGIES                0x000130DC

/** @} */ /* end_addtogroup get_lsm_topol */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_LSM_TOPOLOGIES_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @ingroup get_lsm_topol_size

   Queries for the size of the supported custom added LSM topologies.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_LSM_TOPOLOGIES_SIZE.
   @param[in] pCommandStruct
         There is no input structure; set this to NULL.
   @param[in] nCommandStructLength
         There is no input structure; set this to 0.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- POPP custom topology information was not found.

   @sa
   acdb_ioctl \n
   _AcdbSizeResponseType
*/
#define ACDB_CMD_GET_LSM_TOPOLOGIES_SIZE    0x000130DD

/** @} */ /* end_addtogroup get_lsm_topol_size */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDPROC_STREAM_TABLE_V2
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_audproc_strm_tbl
@{ */

/**
   Queries for an AudProc stream calibration table in the Hexagon table
   format.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDPROC_STREAM_TABLE_V2.
   @param[in] pCommandStruct
         Pointer to AcdbAudStrmTableV2CmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudStrmTableV2CmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.
   @vertspace{-10}
   @sa
   acdb_ioctl \n
   _AcdbAudStrmTableV2CmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_AUDPROC_STREAM_TABLE_V2    0x00011399

/**
   Query command structure for getting calibration data in the AudProc stream
   data tables.

   The format of the table matches the Hexagon table format:
@code
      struct AudStrmTableEntry {
         uint32_t nModuleId;
         uint32_t nParamId;
         uint16_t nParamSize; //multiple of 4
         uint16_t nReserved; // Must be 0
         uint8 aParamData [multiple of 4];
     }

@endcode
*/

typedef struct _AcdbAudStrmTableV2CmdType AcdbAudStrmTableV2CmdType;
#include "acdb_begin_pack.h"

struct _AcdbAudStrmTableV2CmdType {
   uint32_t nApplicationTypeId;
     /**< Application type ID. */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the entire table. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to the memory region into which the
          ACDB is to copy the table. */
}

#include "acdb_end_pack.h"
;

/** @} */ /* end_addtogroup get_audproc_strm_tbl */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_SET_AUDPROC_STREAM_TABLE_V2
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup set_audproc_strm_tbl
@{ */

/**
   Queries for an setting AudProc stream calibration table in the Hexagon table
   format.

   This command allows the overriding of AudProc stream calibration
   table stored in the database.

   Note: Caller should take care of making the data base consistent in case
   ACDB_BADPARM is returned.

   @param[in] nCommandId
         Command ID is ACDB_CMD_SET_AUDPROC_STREAM_TABLE_V2.
   @param[in] pCommandStruct
         Pointer to AcdbAudStrmTableV2CmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudStrmTableV2CmdType.
   @param[out] pResponseStruct
         There is no output structure; set this to NULL.
   @param[in] nResponseStructLength
         There is no output structure; set this to 0.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.

   @vertspace{-10}
   @sa
   acdb_ioctl \n
   _AcdbAudStrmTableV2CmdType \n
*/
#define ACDB_CMD_SET_AUDPROC_STREAM_TABLE_V2    0x0001305E

/** @} */ /* end_addtogroup set_audproc_strm_tbl */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDPROC_STREAM_DATA_V2 and ACDB_CMD_SET_AUDPROC_STREAM_DATA_V2
 *    Declarations and Documentation
 *-------------------------------------------------------------------------- */

/** @addtogroup get_audproc_strm_data
@{ */

/**
   Queries for the specified AudProc stream calibration data.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDPROC_STREAM_DATA_V2.
   @param[in] pCommandStruct
         Pointer to AcdbAudStrmV2CmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudStrmV2CmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_PARMNOTFOUND -- Parameter data not found.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.
   - ACDB_DATA_NOT_FOUND -- Data for the specified input parameterd was not found
                            in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbAudStrmV2CmdType \n
   _AcdbQueryResponseType
   @newpage
*/
#define ACDB_CMD_GET_AUDPROC_STREAM_DATA_V2     0x0001139A

/** @} */ /* end_addtogroup get_audproc_strm_data */

/** @ingroup set_audproc_strm_data

   Changes individual calibration data in the database.

   This command enables the overriding of AudProc stream calibration data
   stored in the database.

   @param[in] nCommandId
         Command ID is ACDB_CMD_SET_AUDPROC_STREAM_DATA_V2.
   @param[in] pCommandStruct
         Pointer to AcdbAudStrmV2CmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudStrmV2CmdType.
   @param[out] pResponseStruct
         There is no output structure; set this to NULL.
   @param[in] nResponseStructLength
         There is no output structure; set this to 0.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbAudStrmV2CmdType
*/
#define ACDB_CMD_SET_AUDPROC_STREAM_DATA_V2      0x0001139B

/** @addtogroup get_audproc_strm_data
@{ */

/**
   Query command structure for getting the AudProc stream data tables.
*/
typedef struct _AcdbAudStrmV2CmdType {
   uint32_t nApplicationTypeId;
     /**< Application type ID. */
   uint32_t nModuleId;
     /**< Module ID. */
   uint32_t nParamId;
     /**< Parameter ID of the module for which to query. */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the parameters identified by the nParamId identifier. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to a memory region containing the
          payload (or receiving the payload) identified by nParamId. */
} AcdbAudStrmV2CmdType;

/** @} */ /* end_addtogroup get_audproc_strm_data */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDPROC_GAIN_DEP_STEP_TABLE
 *    Declarations and Documentation
 *-------------------------------------------------------------------------- */

/** @ingroup get_audproc_gain_dep_step_tbl

   Queries for the audio volume gain-dependent COPP calibration per the specified
   volume step table.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDPROC_GAIN_DEP_STEP_TABLE.
   @param[in] pCommandStruct
         Pointer to AcdbAudProcGainDepVolTblStepCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudProcGainDepVolTblStepCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbAudProcGainDepVolTblStepCmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_AUDPROC_GAIN_DEP_STEP_TABLE             0x00011395

/** @ingroup get_audproc_vol_step_tbl

   Queries for the audio volume calibration step data and softstep data.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDPROC_VOL_STEP_TABLE.
   @param[in] pCommandStruct
         Pointer to AcdbAudProcGainDepVolTblStepCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudProcGainDepVolTblStepCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbAudProcGainDepVolTblStepCmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_AUDPROC_VOL_STEP_TABLE              0x00011396

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDPROC_STREAM_TABLE_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_audproc_strm_tbl_size
@{ */

/**
   Queries for the size of an AudProc stream calibration table.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDPROC_STREAM_TABLE_SIZE.
   @param[in] pCommandStruct
         Pointer to AcdbAudStrmTblSizeCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudStrmTblSizeCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbAudStrmTableV2SizeCmdType \n
   _AcdbSizeResponseType
*/
#define ACDB_CMD_GET_AUDPROC_STREAM_TABLE_SIZE    0x0001139C

/**
   Query command structure for getting the size of an audio stream
   calibration table.
*/
typedef struct _AcdbAudStrmTableV2SizeCmdType {
   uint32_t nApplicationTypeId;        /**< Application type ID. */
} AcdbAudStrmTblSizeCmdType;

/** @} */ /* end_addtogroup get_audproc_strm_tbl_size */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDPROC_COMMON_TABLE_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_audproc_com_tbl_size
@{ */

/**
   Queries for the size of an AudProc common calibration table.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDPROC_COMMON_TABLE_SIZE.
   @param[in] pCommandStruct
         Pointer to AcdbAudProcTableSizeCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudProcTableSizeCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return  The return values of this function are:
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbAudProcTableSizeCmdType \n
   _AcdbSizeResponseType
*/
#define ACDB_CMD_GET_AUDPROC_COMMON_TABLE_SIZE    0x0001139D

/**
   Query command structure for getting the size of the
   AudProc common calibration table.
*/
typedef struct _AcdbAudProcTableSizeCmdType {
   uint32_t nDeviceId;
     /**< Device ID. */
   uint32_t nDeviceSampleRateId;
     /**< Actual sample rate at which the device is operating, in Hz. */
   uint32_t nApplicationType;
     /**< Application type ID. */
} AcdbAudProcTableSizeCmdType;

/** @} */ /* end_addtogroup get_audproc_com_tbl_size */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AFE_COMMON_TABLE_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_afe_com_tbl_size
@{ */

/**
   Queries for the size of an AFE common calibration table.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AFE_COMMON_TABLE_SIZE.
   @param[in] pCommandStruct
         Pointer to AcdbAfeCommonTableSizeCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAfeCommonTableSizeCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbAfeCommonTableSizeCmdType \n
   _AcdbSizeResponseType
*/
#define ACDB_CMD_GET_AFE_COMMON_TABLE_SIZE    0x0001139E

/**
   Query command structure for getting the size an AFE common calibration
   table.
*/
typedef struct _AcdbAfeCommonTableSizeCmdType {
   uint32_t nDeviceId;                 /**< Tx/Rx device ID. */
   uint32_t nSampleRateId;             /**< AFE sample rate ID in Hz. */
} AcdbAfeCommonTableSizeCmdType ;

/** @} */ /* end_addtogroup get_afe_com_tbl_size */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDPROC_GAIN_DEP_STEP_TABLE_SIZE and ACDB_CMD_GET_AUDPROC_VOL_STEP_TABLE_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_audproc_gain_dep_step_tbl_size
@{ */

/**
   Queries for the size of an AudProc gain-dependent table for the specified
   volume step size.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDPROC_GAIN_DEP_STEP_TABLE_SIZE.
   @param[in] pCommandStruct
         Pointer to AcdbAudProcGainDepVolTblStepSizeCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudProcGainDepVolTblStepSizeCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbAudProcGainDepVolTblStepSizeCmdType \n
   _AcdbSizeResponseType
   @newpage
*/
#define ACDB_CMD_GET_AUDPROC_GAIN_DEP_STEP_TABLE_SIZE    0x0001139F

/** @} */ /* end_addtogroup get_audproc_gain_dep_step_tbl_size */

/** @ingroup get_audproc_vol_step_tbl_size

   Queries for the size of an AudProc volume table for the specified
   volume step size.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDPROC_VOL_STEP_TABLE_SIZE.
   @param[in] pCommandStruct
         Pointer to AcdbAudProcGainDepVolTblStepSizeCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudProcGainDepVolTblStepSizeCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbAudProcGainDepVolTblStepSizeCmdType \n
   _AcdbSizeResponseType
*/
#define ACDB_CMD_GET_AUDPROC_VOL_STEP_TABLE_SIZE    0x000113A0

/** @addtogroup get_audproc_gain_dep_step_tbl_size
@{ */

/**
   Query command structure for getting the size of the AudProc gain-dependent
   step table or the AudProc volume step table.
*/
typedef struct _AcdbAudProcGainDepVolTblStepSizeCmdType {
   uint32_t nDeviceId;                 /**< Device ID. */
   uint32_t nApplicationType;          /**< Application type ID. */
   uint32_t nVolumeIndex;              /**< Volume index. */
} AcdbAudProcGainDepVolTblStepSizeCmdType;

/** @} */ /* end_addtogroup get_audproc_gain_dep_step_tbl_size */

/** @addtogroup get_feat_supp_dev_list
@{ */

/**
    Queries for the list of devices that support the specified feature.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_FEATURE_SUPPORTED_DEVICE_LIST.
   @param[in] pCommandStruct
         Pointer to AcdbFeatureSupportedDevListCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbFeatureSupportedDevListCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.

   @sa
   acdb_ioctl \n
   _AcdbFeatureSupportedDevListCmdType \n
   _AcdbQueryResponseType \n
   _AcdbDevSupportedFeatureType
   @newpage
*/
#define ACDB_CMD_GET_FEATURE_SUPPORTED_DEVICE_LIST    0x00012E02

/**
   Query command structure for getting the list of devices that support
   a specified feature.
*/
typedef struct _AcdbFeatureSupportedDevListCmdType {
   uint32_t nFeatureID;
     /**< Feature ID of the enum AcdbDevSupportedFeatureType. */
   uint32_t nBufferLength;
     /**< Length of the buffer pointed to by the parameter pBufferPointer. */
   uint8_t *pBufferPointer;
     /**< Memory location into which the response is to be copied. The response
          to the query ACDB_CMD_GET_FEATURE_SUPPORTED_DEVICE_LIST is in the
          following format:
@code
    struct
      {
         uint32_t   noofdevs;
         uint32_t   *devList; // array of devices
                                 of type uint32
      }
@endcode
*/
} AcdbFeatureSupportedDevListCmdType;

/** @} */ /* end_addtogroup get_feat_supp_dev_list */

/** @addtogroup get_dev_pair_list
@{ */

/**
   Queries for the list of devices for a specified device and for a specified device
   pair type.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_DEVICE_PAIR_LIST.
   @param[in] pCommandStruct
         Pointer to AcdbDevicePairListCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbDevicePairListCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.

   @sa
   acdb_ioctl \n
   _AcdbDevicePairListCmdType \n
   _AcdbQueryResponseType \n
   _AcdbDevPairListType
*/
#define ACDB_CMD_GET_DEVICE_PAIR_LIST    0x00012E03

typedef struct _AcdbDevicePairListCmdType AcdbDevicePairListCmdType;
#include "acdb_begin_pack.h"

/**
   Query command structure for getting the list of devices with which
   the specified device ID and the specified device pair type are paired.
*/
struct _AcdbDevicePairListCmdType {
   uint32_t nDevPairType;
     /**< Device pair type parameter of the enum AcdbDevPairListType. */
   uint32_t nDeviceID;
     /**< Device ID for which the specified pair information is needed. */
   uint32_t nBufferLength;
     /**< Length of the buffer pointed to by the parameter pBufferPointer. */
   uint8_t *pBufferPointer;
     /**< Memory location in which to copy the response. The response to the
          query ACDB_CMD_GET_DEVICE_PAIR_LIST is in the following format:
@code
    struct
    {
        uint32_t   noofdevs;
        uint32_t  *devList; // array of device
                            // IDs of type uint32
    }
@endcode
*/
}

#include "acdb_end_pack.h"
;

/** @} */ /* end_addtogroup get_dev_pair_list */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_LSM_TABLE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_lsm_tbl
@{ */

/**
   Queries for an Listen Stream Manager (LSM) calibration table in the Hexagon
   table format.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_LSM_TABLE.
   @param[in] pCommandStruct
         Pointer to AcdbLsmTableCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbLsmTableCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.
   @vertspace{-10}
   @sa
   acdb_ioctl \n
   _AcdbLsmTableCmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_LSM_TABLE    0x00012E04

/**
   Query command structure for getting calibration data in the LSM tables for
   the specified device ID and the Mic Activity Detection (MAD) application
   type.

   The format of the table matches the table format in the AFE API:
@code
      struct LsmTableEntry {
         uint32_t nModuleId;
         uint32_t nParamId;
         uint16_t nParamSize; // Multiple of 4
         uint16_t nReserved;  // Must be 0
         uint8 aParamData [multiple of 4];
     }

@endcode
*/

typedef struct _AcdbLsmTableCmdType AcdbLsmTableCmdType;
#include "acdb_begin_pack.h"

struct _AcdbLsmTableCmdType {
   uint32_t nDeviceId;
     /**< Device ID. */
   uint32_t nMadApplicationType;
     /**< MAD application type ID. */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the entire table. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to the memory region into which the
          ACDB is to copy the table. */
}

#include "acdb_end_pack.h"
;

/** @} */ /* end_addtogroup get_lsm_tbl */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_LSM_TABLE_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_lsm_tbl_size
@{ */

/**
   Queries for the size of an LSM table for the specified device ID and the
   MAD application type ID.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_LSM_TABLE_SIZE.
   @param[in] pCommandStruct
         Pointer to AcdbLsmTableSizeCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbLsmTableSizeCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbLsmTableSizeCmdType \n
   _AcdbSizeResponseType
*/
#define ACDB_CMD_GET_LSM_TABLE_SIZE    0x00012E05

/**
   Query command structure for getting the memory size of an LSM table.
*/
typedef struct _AcdbLsmTableSizeCmdType {
   uint32_t nDeviceId;                 /**< Device ID. */
   uint32_t nMadApplicationType;       /**< MAD application type ID. */
} AcdbLsmTableSizeCmdType;

/** @} */ /* end_addtogroup get_lsm_tbl_size */

/** @addtogroup get_codec_cal_data
@{ */

/**
   Queries for the codec calibration data based on the requested feature.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_CODEC_CAL_DATA.
   @param[in] pCommandStruct
         Pointer to AcdbCodecCalDataCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbCodecCalDataCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbCodecCalDataCmdType \n
   _AcdbQueryResponseType \n
   _AcdbCodecFeatureType
*/
#define ACDB_CMD_GET_CODEC_CAL_DATA    0x00012E06

typedef struct _AcdbCodecCalDataCmdType AcdbCodecCalDataCmdType;
#include "acdb_begin_pack.h"

/**
   Query command structure for getting the calibration data associated with
   the codec for a specified feature.
*/
struct _AcdbCodecCalDataCmdType {
   uint32_t nDeviceID;
     /**< Device ID for which the specified pair information is needed. */
   uint32_t nCodecFeatureType;
     /**< Codec feature type parameter of enum AcdbCodecFeatureType. */
   uint32_t nBufferLength;
     /**< Length of the buffer pointed to by the parameter pBufferPointer. */
   uint8_t *pBufferPointer;
     /**< Memory location where the response is to be filled in. */
}

#include "acdb_end_pack.h"
;

/** @} */ /* end_addtogroup get_codec_cal_data */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_ADIE_SIDETONE_TABLE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_adie_sidetone_tbl
@{ */

/**
   Queries for the calibration data in the ADIE sidetone table.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_ADIE_SIDETONE_TABLE.
   @param[in] pCommandStruct
         Pointer to AcdbAdieSidetoneTableCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAdieSidetoneTableCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType).

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbAdieSidetoneTableCmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_ADIE_SIDETONE_TABLE    0x00012E49

/**
   Query command structure to get calibration data in the ADIE sidetone table.

   Currently, this table contains the codec sidetone IIR filter data.
   The memory format of the table is as follows:
@code
   struct AdieSideToneEntry {
         uint32_t nModuleId;
         uint32_t nParamId;
         uint16_t nParamSize; // Multiple of 4
         uint16_t nReserved;  // Must be 0
         uint8 aParamData [multiple of 4)];
     }
@endcode
*/

typedef struct _AcdbAdieSidetoneTableCmdType AcdbAdieSidetoneTableCmdType;
#include "acdb_begin_pack.h"

struct _AcdbAdieSidetoneTableCmdType {
   uint32_t nTxDeviceId;
     /**< Tx device ID. */
   uint32_t nRxDeviceId;
     /**< Rx device ID. */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the entire table. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to the memory region into which the
          ACDB is to copy the table. */
}

#include "acdb_end_pack.h"
;

/** @} */ /* end_addtogroup get_adie_sidetone_tbl */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_DEVICE_PROPERTY
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_device_property
@{ */

/**
   Queries for specific device property

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_DEVICE_PROPERTY .
   @param[in] pCommandStruct
         Pointer to AcdbDevPropCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbDevPropCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- Data not found.
   @vertspace{-10}
   @sa
   acdb_ioctl \n
   _AcdbDevPropCmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_DEVICE_PROPERTY                                      0x00012EEB

typedef struct _AcdbDevPropCmdType AcdbDevPropCmdType;
#include "acdb_begin_pack.h"

/**
   Query command structure for getting device property
*/
struct _AcdbDevPropCmdType {
   uint32_t nDeviceId;
     /**< Device ID. */
   uint32_t nPropID;
     /**< Property ID of the enum AcdbDevPropertyType. */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the parameters identified by the  nParamId identifier. */
   uint8_t *pBufferPointer;
     /**< Virtual memory pointer to a memory region containing the
          payload (or receiving the payload) identified by nParamId.\n
          This buffer will be filled based on the nPropID being queried for.*/
}

#include "acdb_end_pack.h"
;

/** @} */ /* end_addtogroup get_device_property */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_DEVICE_PROPERTY_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_device_property_size
@{ */

/**
   Queries for the size of specific device property

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_DEVICE_PROPERTY_SIZE .
   @param[in] pCommandStruct
         Pointer to AcdbDevPropSizeCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbDevPropSizeCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- Data not found.
   @vertspace{-10}
   @sa
   acdb_ioctl \n
   _AcdbDevPropSizeCmdType \n
   _AcdbSizeResponseType
*/
#define ACDB_CMD_GET_DEVICE_PROPERTY_SIZE                                      0x00012EEC

/**
   Query command structure for getting device property
*/
typedef struct _AcdbDevPropSizeCmdType {
   uint32_t nDeviceId;
     /**< Device ID. */
   uint32_t nPropID;
     /**< Property ID of the enum AcdbDevPropertyType. */
} AcdbDevPropSizeCmdType;

/** @} */ /* end_addtogroup get_device_property_size */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_ACDB_SW_VERSION_V2 Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_acdb_sw_ver_v2
@{ */

/**
   Queries for the ACDB software version. Clients are to use this version
   to determine how best to interact with the ACDB software module.

   Rules governing the versioning of the API interface: \n
   - Major -- Represents ACDB package version number.

    - Minor -- Represents branch version number.

   - Revision -- Represents API changes or bug fixes.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_ACDB_SW_VERSION_V2.
   @param[in] pCommandStruct
         There is no input structure; set this to NULL.
   @param[in] nCommandStructLength
         There is no input structure; set this to 0.
   @param[out] pResponseStruct
         Pointer to AcdbModuleVersionTypeV2.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbModuleVersionTypeV2.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   @vertspace{-6}

   @sa
   acdb_ioctl \n
   _AcdbModuleVersionTypeV2
   @newpage
*/
#define ACDB_CMD_GET_ACDB_SW_VERSION_V2   0x00012F04

/**
   Response structure for the ACDB_CMD_GET_ACDB_SW_VERSION_V2 command, which
   enables the client to determine the ACDB API capabilities.
*/
typedef struct _AcdbModuleVersionTypeV2 {
   uint32_t major;
     /**< Major version describing the capabilities of the ACDB API. */
   uint32_t minor;
     /**< Minor version describing the capabilities of the ACDB API. */
   uint32_t revision;
     /**< Revision version describing the capabilities of the ACDB API. */
} AcdbModuleVersionTypeV2;

/** @} */ /* end_addtogroup get_acdb_sw_ver_v2 */

/* ---------------------------------------------------------------------------
* ACDB_CMD_GET_ACDB_SW_VERSION_V3 Declarations and Documentation
*--------------------------------------------------------------------------- */

/** @addtogroup get_acdb_sw_ver_v3
@{ */

/**
   Queries for the ACDB software version. Clients are to use this version
   to determine how best to interact with the ACDB software module.

   Rules governing the versioning of the API interface: \n
   - Major -- Represents ACDB package version number.

    - Minor -- Represents branch version number.

   - Revision -- Represents API changes or bug fixes.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_ACDB_SW_VERSION_V3.
   @param[in] pCommandStruct
         There is no input structure; set this to NULL.
   @param[in] nCommandStructLength
         There is no input structure; set this to 0.
   @param[out] pResponseStruct
         Pointer to AcdbModuleVersionTypeV3.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbModuleVersionTypeV3.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_DATA_INTERFACE_NOT_FOUND -- ACDB files do not contain this data.
   @vertspace{-6}

   @sa
   acdb_ioctl \n
   _AcdbModuleVersionTypeV3
   @newpage
*/
#define ACDB_CMD_GET_ACDB_SW_VERSION_V3   0x000131DE

/**
   Response structure for the ACDB_CMD_GET_ACDB_SW_VERSION_V3 command, which
   enables the client to determine the ACDB API capabilities.
*/
typedef struct _AcdbModuleVersionTypeV3 {
   uint32_t major;
     /**< Major version describing the capabilities of the ACDB API. */
   uint32_t minor;
     /**< Minor version describing the capabilities of the ACDB API. */
   uint32_t revision;
     /**< Revision version describing the capabilities of the ACDB API. */
   uint32_t cplInfo;
   /**< Cpl number describing the capabilities of the ACDB API. */
} AcdbModuleVersionTypeV3;

/** @} */ /* end_addtogroup get_acdb_sw_ver_v3 */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_VP3_MIDPID_LIST
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_vp3_midpid_list
@{ */

/**
   Queries for list of VP3 modules/param IDs info in VP3 table.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_VP3_MIDPID_LIST.
   @param[in] pCommandStruct
         Pointer to AcdbVP3MidPidListCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbVP3MidPidListCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbVP3MidPidListCmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_VP3_MIDPID_LIST    0x00012EFB

/**
   Query command structure for getting the list of Mid/Pid from VP3
   table.

   The format of the response will be of following format:
@code
   struct VP3MidPidListResponse
    {
       uint32_t nNoOfEntries;    // Number of entries
       MidPidStruct nMidPidList[nNoOfEntries];       // Array of MidPidStruct structure of size nNoOfEntries
    }
    struct MidPidStruct
    {
       uint32_t        nModuleId;
       uint32_t        nParamId;
       uint32_t        nMaxParamLen;
    }

@endcode
*/
typedef struct _AcdbVP3MidPidListCmdType {
   uint32_t nTxDeviceId;
    /**< Tx device ID. */
   uint32_t nRxDeviceId;
    /**< Rx device ID. */
   uint32_t nUseCaseId;
    /**< Use Case ID, value of type AcdbVP3UseCaseID. */
   uint32_t nBufferLength;
     /**< Length of the buffer. This must be large enough to hold the entire
          Mid/Pid list structure identified by nUseCaseId. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to the memory region into which the
          ACDB is to copy the Mid/Pid list. */
} AcdbVP3MidPidListCmdType ;

/** @} */ /* end_addtogroup get_vp3_midpid_list */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_VP3_DATA and ACDB_CMD_SET_VP3_DATA
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_vp3_data
@{ */

/**
   Queries for specific VP3 calibration data.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_VP3_DATA.
   @param[in] pCommandStruct
         Pointer to AcdbVP3CmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbVP3CmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_PARMNOTFOUND -- Parameter data was not found.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbVP3CmdType \n
   _AcdbQueryResponseType
   @newpage
*/
#define ACDB_CMD_GET_VP3_DATA     0x00012EFC

/** @} */ /* end_addtogroup get_vp3_data */

/** @ingroup set_vp3_data

   Changes individual calibration data in the ACDB.

   This command allows the overriding of VP3 calibration
   data stored in the database.

   @param[in] nCommandId
         Command ID is ACDB_CMD_SET_VP3_DATA.
   @param[in] pCommandStruct
         Pointer to AcdbVP3CmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbVP3CmdType.
   @param[out] pResponseStruct
         There is no output structure; set this to NULL.
   @param[in] nResponseStructLength
         There is no output structure; set this to 0.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbVP3CmdType
*/
#define ACDB_CMD_SET_VP3_DATA     0x00012EFD

/** @addtogroup get_vp3_data
@{ */

/**
   Query command structure for getting the VP3 calibration data
   tables.
*/
typedef struct _AcdbVP3CmdType {
   uint32_t nTxDeviceId;
     /**< Tx Device ID. */
   uint32_t nRxDeviceId;
     /**< Rx Device ID. */
   uint32_t nUseCaseId;
     /**< Use Case ID value of type enum AcdbVP3UseCaseID. */
   uint32_t nModuleId;
     /**< Module ID. */
   uint32_t nParamId;
     /**< Parameter ID of the module for which to query. */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the parameters identified by the nParamId identifier. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to a memory region containing the
          payload (or receiving the payload) identified by nParamId. */
} AcdbVP3CmdType;

/** @} */ /* end_addtogroup get_vp3_data */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_META_INFO_SIZE Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_meta_info_size
@{ */

/**
   Queries for meta info size given a key value.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_META_INFO_SIZE.
   @param[in] pCommandStruct
         Pointer to AcdbGetMetaInfoSizeCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbGetMetaInfoSizeCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[out] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_PARMNOTFOUND -- Data for the specified key value were
                          not found.

   @sa
   acdb_ioctl \n
   _AcdbGetMetaInfoSizeCmdType \n
   _AcdbSizeResponseType
*/

#define ACDB_CMD_GET_META_INFO_SIZE                 0x00013090

typedef struct _AcdbGetMetaInfoSizeCmdType AcdbGetMetaInfoSizeCmdType;
#include "acdb_begin_pack.h"

/**
   Querry command structure for getting Meta Info Size for the given Key Value.
*/

struct _AcdbGetMetaInfoSizeCmdType {
   uint32_t nKey;          /**< Key Value. */
}

#include "acdb_end_pack.h"
;

/** @} */ /* end_addtogroup get_meta_info_size */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_META_INFO Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_meta_info
@{ */

/**
   Queries for Meta Info given a key value.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_META_INFO.
   @param[in] pCommandStruct
         Pointer to AcdbGetMetaInfoCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbGetMetaInfoCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[out] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_PARMNOTFOUND -- Data for the specified and Key value were
                          not found.
   - ACDB_INSUFFICIENTMEMORY -- Insufficient memory was allocated
                      for this operation.

   @sa
   acdb_ioctl \n
   _AcdbGetMetaInfoCmdType \n
   _AcdbQueryResponseType
*/

#define ACDB_CMD_GET_META_INFO                 0x00013091

typedef struct _AcdbGetMetaInfoCmdType AcdbGetMetaInfoCmdType;
#include "acdb_begin_pack.h"

/**
   Querry command structure for getting Meta Info for the given Key Value.
*/

struct _AcdbGetMetaInfoCmdType {
   uint32_t nKey;          /**< Key Value. */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the entire meta info data. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to the memory region into which the
          ACDB is to copy the meta info data. */
}

#include "acdb_end_pack.h"
;

/** @} */ /* end_addtogroup get_meta_info */

/**
   This ID is to use for a specific calibration param Id MBHC_ADVANCED_CONFIG3 in MBHC module.
   ACDB_CMD_GET_GLBTBL_DATA IOCTL call should be used to get the data for this PID
   The output of ACDB_CMD_GET_GLBTBL_DATA IOCTL call for this PID results in the below structure format.
@code
   struct advance_config3
   {
      uint16_t	  Headset_external_bias_resistor;
      uint16_t	  Use_mic_pulldown_fet_switch;
      uint16_t	  Enable_internal_hph_pulldown_switch;
      uint16_t	  Use_micbias_for_detection_polling;
      uint16_t    Allow_sta_gnd_recalibration_for_buttons;
      uint16_t    Allow_dce_gnd_recalibration_for_buttons;
      uint16_t    Reserved1;
      uint16_t    Reserved2;
      uint16_t    Reserved3;
      uint16_t    Reserved4;
      uint16_t    Reserved5;
      uint16_t    Reserved6;
   };
*/
#define ACDB_PID_MBHC_ADVANCED_CONFIG3                          0x00013092

//pervocoder calibration task declarations

/* ---------------------------------------------------------------------------
* ACDB_CMD_GET_VOC_PROC_DYNAMIC_TABLE
* Declarations and Documentation
*--------------------------------------------------------------------------- */

/** @addtogroup get_vocproc_dynamic_tbl
@{ */

/**
Queries for a VocProc dynamic calibration table in the Core Voice Driver
(CVD) table format.

@param[in] nCommandId
Command ID is ACDB_CMD_GET_VOC_PROC_DYNAMIC_TABLE.
@param[in] pCommandStruct
Pointer to AcdbVocProcGainDepVolTblV2CmdType.
@param[in] nCommandStructLength
Length must equal the size of AcdbVocProcGainDepVolTblV2CmdType.
@param[out] pResponseStruct
Pointer to AcdbQueryResponseType.
@param[in] nResponseStructLength
Length must equal the size of AcdbQueryResponseType.

@return
- ACDB_SUCCESS -- Command executed successfully.
- ACDB_BADPARM -- One or more invalid parameters were provided.
- ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
- ACDB_ERROR -- No or incorrect ACDB files were loaded.
- ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
in the ACDB.
- ACDB_DATA_INTERFACE_NOT_FOUND -- ACDB files does not contain this interface.

If the command is successful, the nBufferPointer member of the command
structure AcdbVocProcGainDepVolTblSizeV2CmdType is filled in the CVD format
as follows:

@code
|    major version     | --> major version is 32-bit
--------------------------
|   minor version      | --> minor version is 32-bit. If minor version is 0.
---------------------------- --> LUT start
| Size of LUT in bytes | --> This field is 32-bit.
----------------------------
| Number of LUT entries | --> This field is 32-bit.
---------------------------- --> Entry 1 start
| column_1 | --> eg. network_id
----------------------------
| column_2 | --> eg. tx_pp_sampling_rate
----------------------------
| . |
| . |
----------------------------
| column_n |
----------------------------
| CDFT OFFSET | --> Byte offset from the beginning of the CDFT. This field is 32-bit.
----------------------------
| CDOT OFFSET | --> Byte offset from the beginning of CDOT. This field is 32-bit.
---------------------------- --> Entry 2 start
| column_1 |
----------------------------
| column_2 |
| . |
| . |
| ... |
---------------------------- --> CDFT start
| Size of CDFT in bytes | --> This field is 32-bit.
---------------------------- --> Entry 1 start
| Number of <mid, pid> pairs| --> This field is 32-bit.
----------------------------
| mod_id | --> This field is 32-bit.
----------------------------
| param_id | --> This field is 32-bit.
----------------------------
| mod_id |
----------------------------
| param_id |
| |
| |
| ... |
---------------------------- --> Entry 2 start
| Number of <mid, pid> pairs|
----------------------------
| mod_id |
----------------------------
| param_id |
----------------------------
| mod_id |
----------------------------
| param_id |
| |
| |
| ... |
---------------------------- --> CDOT start
| Size of CDOT in bytes | --> This field is 32-bit.
---------------------------- --> Entry 1 start
| Number of data offset | --> This field is 32-bit.
| entries |
----------------------------
| data table offset | --> This field is 32-bit.
----------------------------
| data table offset |
----------------------------
| |
| |
| ... |
---------------------------- --> Entry 2 start
| Number of data offset |
| entries |
----------------------------
| data table offset |
----------------------------
| data table offset |
----------------------------
| |
| |
| ... |
---------------------------- --> Data table start
| Size of data table in | --> This field is 32-bit.
| bytes |
---------------------------- --> Entry 1 start
| data_size | --> Size of the calibration data in bytes for a particular <mid, pid> pair. This field is 32-bit.
----------------------------
| data | --> Calibration data for a particular <mid, pid> pair. This field is a multiple of 4 bytes.
| |
| |
| ... |
---------------------------- --> Entry 2 start
| data_size |
----------------------------
| data |
| |
| |
| ... |

if minor version is 1:
|    major version     | --> major version is 32-bit
--------------------------
|   minor version      | --> minor version is 32-bit. If minor version is 1.
---------------------------- --> LUT start
| Size of LUT in bytes | --> This field is 32-bit.
----------------------------
| Number of LUT entries | --> This field is 32-bit.
---------------------------- --> Entry 1 start
| column_1 | --> eg. network_id
----------------------------
| column_2 | --> eg. tx_pp_sampling_rate
----------------------------
| . |
| . |
----------------------------
| column_n |
----------------------------
| CDFT OFFSET | --> Byte offset from the beginning of the CDFT. This field is 32-bit.
----------------------------
| CDOT OFFSET | --> Byte offset from the beginning of CDOT. This field is 32-bit.
---------------------------- --> Entry 2 start
| column_1 |
----------------------------
| column_2 |
| . |
| . |
| ... |
---------------------------- --> CDFT start
| Size of CDFT in bytes | --> This field is 32-bit.
---------------------------- --> Entry 1 start
| Number of <mid, iid, pid> pairs| --> This field is 32-bit.
----------------------------
| mod_id | --> This field is 32-bit.
----------------------------
|instance_id | Reserved | --> This field is 32-bit (instance ID 16 bit, reserved 16 bit).
----------------------------
| param_id | --> This field is 32-bit.
----------------------------
| mod_id |
----------------------------
|instance_id | Reserved | --> This field is 32-bit (instance ID 16 bit, reserved 16 bit).
----------------------------
| param_id |
| |
| |
| ... |
---------------------------- --> Entry 2 start
| Number of <mid, iid, pid> pairs|
----------------------------
| mod_id |
----------------------------
|instance_id | Reserved | --> This field is 32-bit (instance ID 16 bit, reserved 16 bit).
----------------------------
| param_id |
----------------------------
| mod_id |
----------------------------
|instance_id | Reserved | --> This field is 32-bit (instance ID 16 bit, reserved 16 bit).
----------------------------
| param_id |
| |
| |
| ... |
---------------------------- --> CDOT start
| Size of CDOT in bytes | --> This field is 32-bit.
---------------------------- --> Entry 1 start
| Number of data offset | --> This field is 32-bit.
| entries |
----------------------------
| data table offset | --> This field is 32-bit.
----------------------------
| data table offset |
----------------------------
| |
| |
| ... |
---------------------------- --> Entry 2 start
| Number of data offset |
| entries |
----------------------------
| data table offset |
----------------------------
| data table offset |
----------------------------
| |
| |
| ... |
---------------------------- --> Data table start
| Size of data table in | --> This field is 32-bit.
| bytes |
---------------------------- --> Entry 1 start
| data_size | --> Size of the calibration data in bytes for a particular <mid, pid> pair. This field is 32-bit.
----------------------------
| data | --> Calibration data for a particular <mid, pid> pair. This field is a multiple of 4 bytes.
| |
| |
| ... |
---------------------------- --> Entry 2 start
| data_size |
----------------------------
| data |
| |
| |
| ... |

@endcode

@sa
acdb_ioctl \n
AcdbVocProcGainDepVolTblV2CmdType \n
_AcdbQueryResponseType
*/
#define ACDB_CMD_GET_VOC_PROC_DYNAMIC_TABLE 0x00013094

/**
   Query command structure for the VocProc gain-dependent volume table.
*/

typedef struct _AcdbVocProcGainDepVolTblV2CmdType AcdbVocProcGainDepVolTblV2CmdType;

#include "acdb_begin_pack.h"
struct _AcdbVocProcGainDepVolTblV2CmdType {
   uint32_t nTxDeviceId;
     /**< Tx device ID. */
   uint32_t nRxDeviceId;
     /**< Rx device ID. */
   uint32_t nFeatureId;
     /**< Feature ID defined by the OEM or the default feature ID defined by ACDB of type AcdbVocVolFeatureID. */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the entire VocProc gain-dependent calibration table. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to the memory region into which the
          ACDB is to copy the VocProc gain-dependent calibration table. */
}
#include "acdb_end_pack.h"
;
/** @} */ /* end_addtogroup get_vocproc_dyn_tbl */

/* ---------------------------------------------------------------------------
* ACDB_CMD_GET_VOC_PROC_DYNAMIC_TABLE_SIZE
* Declarations and Documentation
*--------------------------------------------------------------------------- */

/** @addtogroup get_vocproc_dyn_tbl_size
@{ */

/**
Queries for the size of a VocProc dynamic calibration table in the
CVD table format.

@param[in] nCommandId
Command ID is ACDB_CMD_GET_VOC_PROC_DYNAMIC_TABLE_SIZE.
@param[in] pCommandStruct
Pointer to AcdbVocProcGainDepVolTblSizeV2CmdType.
@param[in] nCommandStructLength
Length must equal the size of AcdbVocProcGainDepVolTblSizeV2CmdType.
@param[out] pResponseStruct
Pointer to AcdbSizeResponseType.
@param[in] nResponseStructLength
Length must equal the size of AcdbSizeResponseType.

@return
- ACDB_SUCCESS -- Command executed successfully.
- ACDB_BADPARM -- One or more invalid parameters were provided.
- ACDB_ERROR -- No or incorrect ACDB files were loaded.
- ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
in the ACDB.
- ACDB_DATA_INTERFACE_NOT_FOUND -- ACDB files does not contain this interface.

@sa
acdb_ioctl \n
AcdbVocProcGainDepVolTblSizeV2CmdType \n
_AcdbSizeResponseType
*/
#define ACDB_CMD_GET_VOC_PROC_DYNAMIC_TABLE_SIZE 0x00013095

/**
   Query command structure for getting the size of the
   VocProc gain-dependent volume calibration table.
*/
typedef struct _AcdbVocProcGainDepVolTblSizeV2CmdType AcdbVocProcGainDepVolTblSizeV2CmdType;

#include "acdb_begin_pack.h"
struct _AcdbVocProcGainDepVolTblSizeV2CmdType {
   uint32_t nTxDeviceId;               /**< Tx device ID. */
   uint32_t nRxDeviceId;               /**< Rx device ID. */
   uint32_t nFeatureId;
   /**< Feature ID defined by the OEM or the default feature ID defined by ACDB of type AcdbVocVolFeatureID. */
}
#include "acdb_end_pack.h"
;
/** @} */ /* end_addtogroup get_vocproc_dyn_tbl_size */

/* ---------------------------------------------------------------------------
* ACDB_CMD_GET_VOC_PROC_STATIC_TABLE
* Declarations and Documentation
*--------------------------------------------------------------------------- */

/** @addtogroup get_vocproc_stat_tbl
@{ */

/**
Queries for a VocProc static calibration table in the Core Voice Driver
(CVD) table format.

@param[in] nCommandId
Command ID is ACDB_CMD_GET_VOC_PROC_STATIC_TABLE.
@param[in] pCommandStruct
Pointer to AcdbVocProcCmnTblCmdType.
@param[in] nCommandStructLength
Length must equal the size of AcdbVocProcCmnTblCmdType.
@param[out] pResponseStruct
Pointer to AcdbQueryResponseType.
@param[in] nResponseStructLength
Length must equal the size of AcdbQueryResponseType.

@return
- ACDB_SUCCESS -- Command executed successfully.
- ACDB_BADPARM -- One or more invalid parameters were provided.
- ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
- ACDB_ERROR -- No or incorrect ACDB files were loaded.
- ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
in the ACDB.
- ACDB_DATA_INTERFACE_NOT_FOUND -- ACDB files does not contain this interface.

If the command is successful, the nBufferPointer member of the command
structure AcdbVocProcCmnTblCmdType is filled in the CVD format
as follows:

@code
|    major version     | --> major version is 32-bit.
--------------------------
|   minor version      | --> minor version is 32-bit. If minor version is 0.
---------------------------- --> LUT start
| Size of LUT in bytes | --> This field is 32-bit.
----------------------------
| Number of LUT entries | --> This field is 32-bit.
---------------------------- --> Entry 1 start
| column_1 | --> eg. network_id
----------------------------
| column_2 | --> eg. tx_pp_sampling_rate
----------------------------
| . |
| . |
----------------------------
| column_n |
----------------------------
| CDFT OFFSET | --> Byte offset from the beginning of the CDFT. This field is 32-bit.
----------------------------
| CDOT OFFSET | --> Byte offset from the beginning of CDOT. This field is 32-bit.
---------------------------- --> Entry 2 start
| column_1 |
----------------------------
| column_2 |
| . |
| . |
| ... |
---------------------------- --> CDFT start
| Size of CDFT in bytes | --> This field is 32-bit.
---------------------------- --> Entry 1 start
| Number of <mid, pid> pairs| --> This field is 32-bit.
----------------------------
| mod_id | --> This field is 32-bit.
----------------------------
| param_id | --> This field is 32-bit.
----------------------------
| mod_id |
----------------------------
| param_id |
| |
| |
| ... |
---------------------------- --> Entry 2 start
| Number of <mid, pid> pairs|
----------------------------
| mod_id |
----------------------------
| param_id |
----------------------------
| mod_id |
----------------------------
| param_id |
| |
| |
| ... |
---------------------------- --> CDOT start
| Size of CDOT in bytes | --> This field is 32-bit.
---------------------------- --> Entry 1 start
| Number of data offset | --> This field is 32-bit.
| entries |
----------------------------
| data table offset | --> This field is 32-bit.
----------------------------
| data table offset |
----------------------------
| |
| |
| ... |
---------------------------- --> Entry 2 start
| Number of data offset |
| entries |
----------------------------
| data table offset |
----------------------------
| data table offset |
----------------------------
| |
| |
| ... |
---------------------------- --> Data table start
| Size of data table in | --> This field is 32-bit.
| bytes |
---------------------------- --> Entry 1 start
| data_size | --> Size of the calibration data in bytes for a particular <mid, pid> pair. This field is 32-bit.
----------------------------
| data | --> Calibration data for a particular <mid, pid> pair. This field is a multiple of 4 bytes.
| |
| |
| ... |
---------------------------- --> Entry 2 start
| data_size |
----------------------------
| data |
| |
| |
| ... |

If minor version is 1:

|    major version     | --> major version
--------------------------
|   minor version      | --> minor version is 1.
---------------------------- --> LUT start
| Size of LUT in bytes | --> This field is 32-bit.
----------------------------
| Number of LUT entries | --> This field is 32-bit.
---------------------------- --> Entry 1 start
| column_1 | --> eg. network_id
----------------------------
| column_2 | --> eg. tx_pp_sampling_rate
----------------------------
| . |
| . |
----------------------------
| column_n |
----------------------------
| CDFT OFFSET | --> Byte offset from the beginning of the CDFT. This field is 32-bit.
----------------------------
| CDOT OFFSET | --> Byte offset from the beginning of CDOT. This field is 32-bit.
---------------------------- --> Entry 2 start
| column_1 |
----------------------------
| column_2 |
| . |
| . |
| ... |
---------------------------- --> CDFT start
| Size of CDFT in bytes | --> This field is 32-bit.
---------------------------- --> Entry 1 start
| Number of <mid, iid, pid> pairs| --> This field is 32-bit.
----------------------------
| mod_id | --> This field is 32-bit.
----------------------------
|instance_id | Reserved | --> This field is 32-bit (instance ID 16 bit, reserved 16 bit).
----------------------------
| param_id | --> This field is 32-bit.
----------------------------
| mod_id |
----------------------------
|instance_id | Reserved | --> This field is 32-bit (instance ID 16 bit, reserved 16 bit).
----------------------------
| param_id |
| |
| |
| ... |
---------------------------- --> Entry 2 start
| Number of <mid, iid, pid> pairs|
----------------------------
| mod_id |
----------------------------
|instance_id | Reserved | --> This field is 32-bit (instance ID 16 bit, reserved 16 bit).
----------------------------
| param_id |
----------------------------
| mod_id |
----------------------------
|instance_id | Reserved | --> This field is 32-bit (instance ID 16 bit, reserved 16 bit).
----------------------------
| param_id |
| |
| |
| ... |
---------------------------- --> CDOT start
| Size of CDOT in bytes | --> This field is 32-bit.
---------------------------- --> Entry 1 start
| Number of data offset | --> This field is 32-bit.
| entries |
----------------------------
| data table offset | --> This field is 32-bit.
----------------------------
| data table offset |
----------------------------
| |
| |
| ... |
---------------------------- --> Entry 2 start
| Number of data offset |
| entries |
----------------------------
| data table offset |
----------------------------
| data table offset |
----------------------------
| |
| |
| ... |
---------------------------- --> Data table start
| Size of data table in | --> This field is 32-bit.
| bytes |
---------------------------- --> Entry 1 start
| data_size | --> Size of the calibration data in bytes for a particular <mid, pid> pair. This field is 32-bit.
----------------------------
| data | --> Calibration data for a particular <mid, pid> pair. This field is a multiple of 4 bytes.
| |
| |
| ... |
---------------------------- --> Entry 2 start
| data_size |
----------------------------
| data |
| |
| |
| ... |

@endcode

@sa
acdb_ioctl \n
AcdbVocProcCmnTblCmdType \n
_AcdbQueryResponseType
*/

#define ACDB_CMD_GET_VOC_PROC_STATIC_TABLE 0x00013096

typedef struct _AcdbVocProcCmnTblCmdType AcdbVocProcCmnTblCmdType;
#include "acdb_begin_pack.h"

/**
   Query command structure for the command ACDB_CMD_GET_VOC_PROC_COMMON_TABLE.
*/
struct _AcdbVocProcCmnTblCmdType {
   uint32_t nTxDeviceId;
     /**< Tx device ID. */
   uint32_t nRxDeviceId;
     /**< Rx device ID. */
   uint32_t nTxDeviceSampleRateId;
     /**< Operating sample rate for the Tx device in Hz. */
   uint32_t nRxDeviceSampleRateId;
     /**< Operating sample rate for the Rx device in Hz. */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the entire table. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to the memory region into which the
          ACDB is to copy the table. */
}

#include "acdb_end_pack.h"
;
/** @} */ /* end_addtogroup get_vocproc_stat_tbl */

/* ---------------------------------------------------------------------------
* ACDB_CMD_GET_VOC_PROC_STATIC_TABLE_SIZE
* Declarations and Documentation
*--------------------------------------------------------------------------- */

/** @addtogroup get_vocproc_stat_tbl_size
@{ */

/**
Queries for the size of a VocProc static calibration table in the
CVD table format.

@param[in] nCommandId
Command ID is ACDB_CMD_GET_VOC_PROC_STATIC_TABLE_SIZE.
@param[in] pCommandStruct
Pointer to AcdbVocProcCmnTblSizeCmdType.
@param[in] nCommandStructLength
Length must equal the size of AcdbVocProcCmnTblSizeCmdType.
@param[out] pResponseStruct
Pointer to AcdbSizeResponseType.
@param[in] nResponseStructLength
Length must equal the size of AcdbSizeResponseType.

@return
- ACDB_SUCCESS -- Command executed successfully.
- ACDB_BADPARM -- One or more invalid parameters were provided.
- ACDB_ERROR -- No or incorrect ACDB files were loaded.
- ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
in the ACDB.
- ACDB_DATA_INTERFACE_NOT_FOUND -- ACDB files does not contain this interface.

@sa
acdb_ioctl \n
AcdbVocProcCmnTblSizeCmdType \n
_AcdbSizeResponseType
*/
#define ACDB_CMD_GET_VOC_PROC_STATIC_TABLE_SIZE 0x00013097

/**
   Query command structure for getting the size of the
   VocProc common table.
*/
typedef struct _AcdbVocProcCmnTblSizeCmdType AcdbVocProcCmnTblSizeCmdType;

#include "acdb_begin_pack.h"
struct _AcdbVocProcCmnTblSizeCmdType {
   uint32_t nTxDeviceId;
     /**< Tx device ID. */
   uint32_t nRxDeviceId;
     /**< Rx device ID. */
   uint32_t nTxDeviceSampleRateId;
     /**< Operating sample rate for the Tx device in Hz. */
   uint32_t nRxDeviceSampleRateId;
     /**< Operating sample rate for the Rx device in Hz. */
}
#include "acdb_end_pack.h"
;
/** @} */ /* end_addtogroup get_vocproc_stat_tbl_size */

/* ---------------------------------------------------------------------------
* ACDB_CMD_GET_VOC_STREAM_STATIC_TABLE
* Declarations and Documentation
*--------------------------------------------------------------------------- */

/** @addtogroup get_voc_strm2_com_tbl
@{ */

/**
Queries for a voice stream common calibration table in the CVD table format.

@param[in] nCommandId
Command ID is ACDB_CMD_GET_VOC_STREAM_STATIC_TABLE.
@param[in] pCommandStruct
Pointer to AcdbQueryCmdType.
@param[in] nCommandStructLength
Length must equal the size of AcdbQueryCmdType.
@param[out] pResponseStruct
Pointer to AcdbQueryResponseType.
@param[in] nResponseStructLength
Length must equal the size of AcdbQueryResponseType.

@return
- ACDB_SUCCESS -- Command executed successfully.
- ACDB_BADPARM -- One or more invalid parameters were provided.
- ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
- ACDB_ERROR -- No or incorrect ACDB files were loaded.
- ACDB_DATA_INTERFACE_NOT_FOUND -- ACDB files does not contain this interface.

When the command is successful, the pBufferPointer member of the
AcdbQueryCmdType structure is filled in the CVD format as follows:
@code
|    major version     | --> major version
--------------------------
|   minor version      | --> minor version is 0.
---------------------------- --> LUT start
| Size of LUT in bytes | --> This field is 32-bit.
----------------------------
| Number of LUT entries | --> This field is 32-bit.
---------------------------- --> Entry 1 start
| column_1 | --> eg. network_id
----------------------------
| column_2 | --> eg. tx_pp_sampling_rate
----------------------------
| . |
| . |
----------------------------
| column_n |
----------------------------
| CDFT OFFSET | --> Byte offset from the beginning of the CDFT. This field is 32-bit.
----------------------------
| CDOT OFFSET | --> Byte offset from the beginning of CDOT. This field is 32-bit.
---------------------------- --> Entry 2 start
| column_1 |
----------------------------
| column_2 |
| . |
| . |
| ... |
---------------------------- --> CDFT start
| Size of CDFT in bytes | --> This field is 32-bit.
---------------------------- --> Entry 1 start
| Number of <mid, pid> pairs| --> This field is 32-bit.
----------------------------
| mod_id | --> This field is 32-bit.
----------------------------
| param_id | --> This field is 32-bit.
----------------------------
| mod_id |
----------------------------
| param_id |
| |
| |
| ... |
---------------------------- --> Entry 2 start
| Number of <mid, pid> pairs|
----------------------------
| mod_id |
----------------------------
| param_id |
----------------------------
| mod_id |
----------------------------
| param_id |
| |
| |
| ... |
---------------------------- --> CDOT start
| Size of CDOT in bytes | --> This field is 32-bit.
---------------------------- --> Entry 1 start
| Number of data offset | --> This field is 32-bit.
| entries |
----------------------------
| data table offset | --> This field is 32-bit.
----------------------------
| data table offset |
----------------------------
| |
| |
| ... |
---------------------------- --> Entry 2 start
| Number of data offset |
| entries |
----------------------------
| data table offset |
----------------------------
| data table offset |
----------------------------
| |
| |
| ... |
---------------------------- --> Data table start
| Size of data table in | --> This field is 32-bit.
| bytes |
---------------------------- --> Entry 1 start
| data_size | --> Size of the calibration data in bytes for a particular <mid, pid> pair. This field is 32-bit.
----------------------------
| data | --> Calibration data for a particular <mid, pid> pair. This field is a multiple of 4 bytes.
| |
| |
| ... |
---------------------------- --> Entry 2 start
| data_size |
----------------------------
| data |
| |
| |
| ... |

if minor version is 1:
|    major version     | --> major version
--------------------------
|   minor version      | --> minor version is 1.
---------------------------- --> LUT start
| Size of LUT in bytes | --> This field is 32-bit.
----------------------------
| Number of LUT entries | --> This field is 32-bit.
---------------------------- --> Entry 1 start
| column_1 | --> eg. network_id
----------------------------
| column_2 | --> eg. tx_pp_sampling_rate
----------------------------
| . |
| . |
----------------------------
| column_n |
----------------------------
| CDFT OFFSET | --> Byte offset from the beginning of the CDFT. This field is 32-bit.
----------------------------
| CDOT OFFSET | --> Byte offset from the beginning of CDOT. This field is 32-bit.
---------------------------- --> Entry 2 start
| column_1 |
----------------------------
| column_2 |
| . |
| . |
| ... |
---------------------------- --> CDFT start
| Size of CDFT in bytes | --> This field is 32-bit.
---------------------------- --> Entry 1 start
| Number of <mid, iid, pid> pairs| --> This field is 32-bit.
----------------------------
| mod_id | --> This field is 32-bit.
----------------------------
|instance_id | Reserved | --> This field is 32-bit (instance ID 16 bit, reserved 16 bit).
----------------------------
| param_id | --> This field is 32-bit.
----------------------------
| mod_id |
----------------------------
|instance_id | Reserved | --> This field is 32-bit (instance ID 16 bit, reserved 16 bit).
----------------------------
| param_id |
| |
| |
| ... |
---------------------------- --> Entry 2 start
| Number of <mid, iid, pid> pairs|
----------------------------
| mod_id |
----------------------------
|instance_id | Reserved | --> This field is 32-bit (instance ID 16 bit, reserved 16 bit).
----------------------------
| param_id |
----------------------------
| mod_id |
----------------------------
|instance_id | Reserved | --> This field is 32-bit (instance ID 16 bit, reserved 16 bit).
----------------------------
| param_id |
| |
| |
| ... |
---------------------------- --> CDOT start
| Size of CDOT in bytes | --> This field is 32-bit.
---------------------------- --> Entry 1 start
| Number of data offset | --> This field is 32-bit.
| entries |
----------------------------
| data table offset | --> This field is 32-bit.
----------------------------
| data table offset |
----------------------------
| |
| |
| ... |
---------------------------- --> Entry 2 start
| Number of data offset |
| entries |
----------------------------
| data table offset |
----------------------------
| data table offset |
----------------------------
| |
| |
| ... |
---------------------------- --> Data table start
| Size of data table in | --> This field is 32-bit.
| bytes |
---------------------------- --> Entry 1 start
| data_size | --> Size of the calibration data in bytes for a particular <mid, pid> pair. This field is 32-bit.
----------------------------
| data | --> Calibration data for a particular <mid, pid> pair. This field is a multiple of 4 bytes.
| |
| |
| ... |
---------------------------- --> Entry 2 start
| data_size |
----------------------------
| data |
| |
| |
| ... |

@endcode

@endcode

@sa
acdb_ioctl \n
_AcdbQueryCmdType \n
_AcdbQueryResponseType
*/
#define ACDB_CMD_GET_VOC_STREAM_STATIC_TABLE 0x00013098

/** @} */ /* end_addtogroup get_voc_strm2_com_tbl */

/* ---------------------------------------------------------------------------
* ACDB_CMD_GET_VOC_STREAM_STATIC_TABLE_SIZE
* Declarations and Documentation
*--------------------------------------------------------------------------- */

/** @addtogroup get_voc_strm2_com_tbl_size
@{ */

/**
Queries for the size of a voice stream2 common calibration table in
the CVD table format.

@param[in] nCommandId
Command ID is ACDB_CMD_GET_VOC_STREAM_STATIC_TABLE_SIZE.
@param[in] pCommandStruct
There is no input structure; set this to NULL.
@param[in] nCommandStructLength
There is no input structure; set this to 0.
@param[out] pResponseStruct
Pointer to AcdbSizeResponseType.
@param[in] nResponseStructLength
Length must equal the size of AcdbSizeResponseType.

@return
- ACDB_SUCCESS -- Command executed successfully.
- ACDB_BADPARM -- One or more invalid parameters were provided.
- ACDB_ERROR -- No or incorrect ACDB files were loaded.
- ACDB_DATA_INTERFACE_NOT_FOUND -- ACDB files does not contain this interface.

@sa
acdb_ioctl \n
_AcdbSizeResponseType
*/
#define ACDB_CMD_GET_VOC_STREAM_STATIC_TABLE_SIZE 0x00013099

/** @} */ /* end_addtogroup get_voc_strm2_com_tbl_size */

/* ---------------------------------------------------------------------------
* ACDB_CMD_GET_VOC_COLUMNS_INFO_SIZE_V2
* Declarations and Documentation
*--------------------------------------------------------------------------- */

/** @addtogroup get_voc_columns_info_size
@{ */

/**
Queries for size the size of VocProc, VocProc volume, or VocProc stream
table columns and column types information.

@param[in] nCommandId
Command ID is ACDB_CMD_GET_VOC_COLUMNS_INFO_SIZE_V2.
@param[in] pCommandStruct
Pointer to AcdbVocColumnsInfoSizeCmdType_v2.
@param[in] nCommandStructLength
Length must equal the size of AcdbVocColumnsInfoSizeCmdType_v2.
@param[out] pResponseStruct
Pointer to AcdbSizeResponseType.
@param[in] nResponseStructLength
Length must equal the size of AcdbSizeResponseType.

@return
- ACDB_SUCCESS -- Command executed successfully.
- ACDB_BADPARM -- One or more invalid parameters were provided.
- ACDB_DATA_INTERFACE_NOT_FOUND -- ACDB files does not contain this interface.

@sa
acdb_ioctl \n
_AcdbVocColumnsInfoSizeCmdType_v2 \n
AcdbVoiceTblType_v2 \n
_AcdbSizeResponseType
*/
#define ACDB_CMD_GET_VOC_COLUMNS_INFO_SIZE_V2 0x000130A0

/**
Query command structure for getting the size of columns information data
for the specified voice table ID.

@sa
AcdbVoiceTblType
*/
typedef struct _AcdbVocColumnsInfoSizeCmdType_V2 {
	uint32_t nTableId;
	/**< Supported value in enum AcdbVoiceTblType_v2. */
	uint32_t nTxDeviceId;
	/**< Tx device ID. *///IF the table id is vocstrm or vocstrmstatic this value is a don't care value
	uint32_t nRxDeviceId;
	/**< Rx device ID. *///IF the table id is vocstrm or vocstrmstatic this value is a don't care value
} AcdbVocColumnsInfoSizeCmdType_v2;

/** @} */ /* end_addtogroup get_voc_columns_info_size_v2 */

/* ---------------------------------------------------------------------------
* ACDB_CMD_GET_VOC_COLUMNS_INFO_v2
* Declarations and Documentation
*--------------------------------------------------------------------------- */

/** @addtogroup get_voc_columns_info
@{ */

/**
Queries for VocProc, VocProc gain-dependent, or voice stream table columns
and column types information.

@param[in] nCommandId Command ID is ACDB_CMD_GET_VOC_COLUMNS_INFO_v2.
@param[in] pCommandStruct Pointer to AcdbVocColumnsInfoCmdType_v2.
@param[in] nCommandStructLength Length must equal the size of
AcdbVocColumnsInfoCmdType_v2.
@param[out] pResponseStruct Pointer to AcdbQueryResponseType.
@param[in] nResponseStructLength Length must equal the size of
AcdbQueryResponseType.

@return
- ACDB_SUCCESS -- Command executed successfully.
- ACDB_BADPARM -- One or more invalid parameters were provided.
- ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
- ACDB_DATA_INTERFACE_NOT_FOUND - ACDB files does not contain this interface.

When the command is successful, the pBufferPointer member of the
AcdbQueryCmdType structure is filled in the CVD table format (in the
structure format of ColumnsInfoResponse):
@code
struct ColumnsInfoResponse
{
uint32_t noOfColumns; // Number of columns
ColumnInfo *pInfo; // Array of ColumnInfo structure of size
noOfColumns
}

struct ColumnInfo
{
uint32_t nColId;
uint32_t nColType;
na_val_type nColNAValue; // The nColDummyValue parameters value is
associated with this nColId and nColType
}

union na_val_type
{
uint8_t uint8_t_val;
uint16_t uint16_t_val;
uint32_t uint32_t_val;
uint64_t uint64_t_val;
}
@endcode

@sa
acdb_ioctl \n
_AcdbVocColumnsInfoCmdType_v2 \n
AcdbVoiceTblType_v2 \n
_AcdbQueryResponseType
*/
#define ACDB_CMD_GET_VOC_COLUMNS_INFO_V2 0x0001309A

/**
Query command structure for getting the columns information associated with
various voice tables.
*/
typedef struct _AcdbVocColumnsInfoCmdType_v2 {
	uint32_t nTableId;
	/**< Supported value in the AcdbVoiceTblType_v2 enum. */
	uint32_t nTxDeviceId;
	/**< Tx device ID. *///IF the table id is vocstrm or vocstrmstatic this value is a don't care value
	uint32_t nRxDeviceId;
	/**< Rx device ID. *///IF the table id is vocstrm or vocstrmstatic this value is a don't care value
	uint32_t nBufferLength;
	/**< Length of the calibration buffer. */
	uint8_t *pBuff;
	/**< Virtual memory pointer to a memory region in which to fill
	the device pair metadata in the CVD format. */
} AcdbVocColumnsInfoCmdType_v2;

/** @} */ /* end_addtogroup get_voc_columns_info_v2 */

/* ---------------------------------------------------------------------------
* ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_avcs_custom_topo_info_size
@{ */

/**
   Queries for the size of all the avcs custom added topologies to be registered

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO_SIZE.
   @param[in] pCommandStruct
		 There is no input structure; set this to NULL.
   @param[in] nCommandStructLength
		 There is no input structure; set this to 0.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_DATA_NOT_FOUND --custom topologies data was not found.

@sa
acdb_ioctl \n
_AcdbSizeResponseType
*/
#define ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO_SIZE    0x0001316D

/** @} */ /* end_addtogroup get_avcs_custom_topo_info_size */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

 /** @addtogroup get_avcs_custom_topo_info
@{ */

/**
   Queries for all the avcs custom added topologies to be registered

     @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO.
   @param[in] pCommandStruct
         Pointer to AcdbQueryCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbQueryCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @vertspace{-12}
   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_DATA_NOT_FOUND --  custom topologies data was not found.

   @vertspace{-8}
   If the command is successful, the pBufferPointer of the struct
   AcdbQueryCmdType is filled in the following format:
@code

  struct avcs_topology_buffer_t
 {
   uint32_t num_topologies;  // Specifies the number of topologies in this command
   avcs_topology_definition_t pTopDefs[];
 };

 struct avcs_topology_definition_t
 {
   uint32_t version;
   uint32_t topology_id;
   uint32_t topo_config;   //Config data related to this topology
   uint32_t num_modules;
   avcs_module_info_t pModDefs[];
 };

 struct avcs_module_info_t
 {
   uint32_t module_id; //
 };

@endcode
   @vertspace{-5}
   @sa
   acdb_ioctl
*/
#define ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO    0x000131A3

/** @} */ /* end_addtogroup get_avcs_custom_topo_info */

/* ---------------------------------------------------------------------------
 * ACDB_WDSP_CMD_GET_SUBGRAPH_LIST_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_wdsp_subgraph_list_size
@{ */

/**
   Queries for the size of the subgraph list associated with the specified
   device and usecase.

   @param[in] nCommandId
         Command ID is ACDB_WDSP_CMD_GET_SUBGRAPH_LIST_SIZE.
   @param[in] pCommandStruct
         Pointer to WdspSubgraphListSizeCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of WdspSubgraphListSizeCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _WdspSubgraphListSizeCmdType \n
   _AcdbSizeResponseType
*/
#define ACDB_WDSP_CMD_GET_SUBGRAPH_LIST_SIZE    0x00014001

/**
   Query command structure for getting the size of a subgraph list.
*/
typedef struct _WdspSubgraphListSizeCmdType {
   uint32_t nDeviceId;               /**< Tx device ID. */
   uint32_t nUsecaseId;                /**< Usecase ID. */
} WdspSubgraphListSizeCmdType;

/** @} */ /* end_addtogroup get_wdsp_subgraph_list_size */

/* ---------------------------------------------------------------------------
 * ACDB_WDSP_CMD_GET_SUBGRAPH_LIST
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_wdsp_subgraph_list
@{ */

/**
   Queries for the subgraph list for a given device and usecase.

   @param[in] nCommandId
         Command ID is ACDB_WDSP_CMD_GET_SUBGRAPH_LIST.
   @param[in] pCommandStruct
         Pointer to WdspSubgraphListCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of WdspSubgraphListCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

       When the call is successful, the nBufferPointer member of the WdspSubgraphListCmdType
       is filled in the following format:
   @code
        ----------32 Bit---------
       | nNumOfSubGraphIDs       |
       | subGraphID[0]           |
       | subGraphID[1]           |
       | ...

   @endcode

   @sa
   acdb_ioctl \n
   _WdspSubgraphListCmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_WDSP_CMD_GET_SUBGRAPH_LIST    0x00014002

/**
   Query command structure for getting the subgraph list.
*/
typedef struct _WdspSubgraphListCmdType {
   uint32_t nDeviceId;               /**< Tx device ID. */
   uint32_t nUsecaseId;                /**< Usecase ID. */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the complete subgraph list. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to a memory region containing the
          payload (or receiving the payload) */
} WdspSubgraphListCmdType;

/** @} */ /* end_addtogroup get_wdsp_subgraph_list */

/* ---------------------------------------------------------------------------
 * ACDB_WDSP_CMD_GET_SUBGRAPH_MODULE_INFO_LIST_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_wdsp_subgraph_module_info_list_size
@{ */

/**
   Queries for the size of all modules and module info for one subgraph under a given deviceID and usecase ID.

   @param[in] nCommandId
         Command ID is ACDB_WDSP_CMD_GET_SUBGRAPH_MODULE_INFO_LIST_SIZE.
   @param[in] pCommandStruct
         Pointer to WdspDidUcidSubGraphIDSizeCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of WdspDidUcidSubGraphIDSizeCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _WdspDidUcidSubGraphIDSizeCmdType \n
   _AcdbSizeResponseType
*/
#define ACDB_WDSP_CMD_GET_SUBGRAPH_MODULE_INFO_LIST_SIZE    0x00014003

/**
   Query command structure for getting the size of a subgraph module info list.
*/
typedef struct _WdspDidUcidSubGraphIDSizeCmdType {
   uint32_t nDeviceId;               /**< Tx device ID. */
   uint32_t nUsecaseId;                /**< Usecase ID. */
   uint32_t nSubGraphId;               /**< Subgraph ID. */
} WdspDidUcidSubGraphIDSizeCmdType;

/** @} */ /* end_addtogroup get_wdsp_subgraph_module_info_list_size */

/* ---------------------------------------------------------------------------
 * ACDB_WDSP_CMD_GET_SUBGRAPH_MODULE_INFO_LIST
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_wdsp_subgraph_module_info_list
@{ */

/**
   Queries for all modules and module info for one subgraph under a given deviceID and usecase ID.

   @param[in] nCommandId
         Command ID is ACDB_WDSP_CMD_GET_SUBGRAPH_MODULE_INFO_LIST.
   @param[in] pCommandStruct
         Pointer to AcdbWdspDidUcidSubGraphIDType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbWdspDidUcidSubGraphIDType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

       When the call is successful, the nBufferPointer member of the AcdbWdspDidUcidSubGraphIDType
       is filled with the module information data in the following format:
   @code
        ----------32 Bit---------
       | mod_id_fwk              |
       | I_id_fwk(0)| reserved   |
	   | param_id_fwk_mod_list   |
       | param_size | reserved   |
       ---------------------------
       | MID                     |
       | IID        | meta_data  |
       |i_pin|o_pin | reserved   |
       | MID                     |
       | IID        | meta_data  |
       |i_pin|o_pin | reserved   |
	      ...

   @endcode

   @sa
   acdb_ioctl \n
   _AcdbWdspDidUcidSubGraphIDType \n
   _AcdbQueryResponseType
*/
#define ACDB_WDSP_CMD_GET_SUBGRAPH_MODULE_INFO_LIST    0x00014004

/**
   Query command structure for getting the size of a subgraph list.
*/
typedef struct _AcdbWdspDidUcidSubGraphIDType {
   uint32_t nDeviceId;               /**< Tx device ID. */
   uint32_t nUsecaseId;                /**< Usecase ID. */
   uint32_t nSubGraphId;               /**< Subgraph ID. */
   uint32_t nBufferLength;     /**< Length of the calibration buffer. This must be large enough to hold
          the entire table. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to the memory region into which the
          ACDB is to copy the table. */
} AcdbWdspDidUcidSubGraphIDType;

/** @} */ /* end_addtogroup get_wdsp_subgraph_module_info_list */

/* ---------------------------------------------------------------------------
 * ACDB_WDSP_CMD_GET_SUBGRAPH_MODULE_CONNECTION_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_wdsp_subgraph_module_connection_size
@{ */

/**
   Queries for the size of all module connection for one subgraph under a given deviceID and usecase ID.

   @param[in] nCommandId
         Command ID is ACDB_WDSP_CMD_GET_SUBGRAPH_MODULE_CONNECTION_SIZE.
   @param[in] pCommandStruct
         Pointer to WdspDidUcidSubGraphIDSizeCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of WdspDidUcidSubGraphIDSizeCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbWdspDidUcidSubGraphIDType \n
   _AcdbSizeResponseType
*/
#define ACDB_WDSP_CMD_GET_SUBGRAPH_MODULE_CONNECTION_SIZE    0x00014005

/** @} */ /* end_addtogroup get_wdsp_subgraph_module_connection_size */

/* ---------------------------------------------------------------------------
 * ACDB_WDSP_CMD_GET_SUBGRAPH_MODULE_CONNECTION
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_wdsp_subgraph_module_connection
@{ */

/**
   Queries for the module connections for one subgraph under a given deviceID and usecase ID.

   @param[in] nCommandId
         Command ID is ACDB_WDSP_CMD_GET_SUBGRAPH_MODULE_CONNECTION.
   @param[in] pCommandStruct
         Pointer to AcdbWdspDidUcidSubGraphIDType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbWdspDidUcidSubGraphIDType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

       When the call is successful, the nBufferPointer member of the AcdbWdspDidUcidSubGraphIDType
       is filled with the module information data in the following format:
   @code
        -----------32 Bit----------
       | mod_id_fwk                |
       | I_id_fwk(0) | reserved    |
       | param_id_fwk_connect      |
       | param_size  | reserved    |
        ---------------------------
       | MID_src1                  |
       | IID_src1    | num_dst_mods|
        ---------------------------
       | MID_dst1                  |
       | IID_dst1    | num_edges   |
        ---------------------------
	   | pin_src1    | pin_dst1    |
	   | pin_src2    | pin_dst2    |

	   | MID_dst2                  |
	   | IID_dst2    | num_edges   |
	   | pin_src1    | pin_dst1    |
	   | pin_src2    | pin_dst2    |
	     ...
	   | MID_src2                  |
       | IID_src2    | num_dst_mods|
	     ...

   @endcode

   @sa
   acdb_ioctl \n
   _AcdbWdspDidUcidSubGraphIDType \n
   _AcdbQueryResponseType
*/
#define ACDB_WDSP_CMD_GET_SUBGRAPH_MODULE_CONNECTION    0x00014006

/** @} */ /* end_addtogroup get_wdsp_subgraph_module_connection */

/* ---------------------------------------------------------------------------
 * ACDB_WDSP_CMD_GET_SUBGRAPH_CONNECTIONS_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_wdsp_subgraphs_connection_size
@{ */

/**
Queries for the size of subgraphs connections for two subgraphs under a given deviceID and usecase ID

   @param[in] nCommandId
         Command ID is ACDB_WDSP_CMD_GET_SUBGRAPH_CONNECTIONS_SIZE.
   @param[in] pCommandStruct
         Pointer to WdspSubgraphConnectionsSizeCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of WdspSubgraphConnectionsSizeCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _WdspSubgraphConnectionsSizeCmdType \n
   _AcdbSizeResponseType
*/
#define ACDB_WDSP_CMD_GET_SUBGRAPH_CONNECTIONS_SIZE    0x00014007

/**ACDB_WDSP_CMD_GET_MODULE_LOADING_META_INFO_SIZE
   Query command structure for getting the size of a subgraph list.
*/
typedef struct _WdspSubgraphConnectionsSizeCmdType {
   uint32_t nDeviceId;               /**< Tx device ID. */
   uint32_t nUsecaseId;                /**< Usecase ID. */
   uint32_t nSubGraphIdSrc;               /**< Source Subgraph ID. */
   uint32_t nSubGraphIdDst;               /**< Destination Subgraph ID. */
} WdspSubgraphConnectionsSizeCmdType;

/** @} */ /* end_addtogroup get_wdsp_subgraphs_connection_size */

/* ---------------------------------------------------------------------------
 * ACDB_WDSP_CMD_GET_SUBGRAPHS_CONNECTION
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_wdsp_subgraph_subgraphs_connection
@{ */

/**
   Queries for the subgraphs connections for two subgraphs under a given deviceID and usecase ID

   @param[in] nCommandId
         Command ID is ACDB_WDSP_CMD_GET_SUBGRAPHS_CONNECTION.
   @param[in] pCommandStruct
         Pointer to AcdbWdspDidUcidSubGraphIDPairType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbWdspDidUcidSubGraphIDPairType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

       When the call is successful, the nBufferPointer member of the AcdbWdspDidUcidSubGraphIDPairType
       is filled with the module information data in the following format:
   @code
        -----------32 Bit----------
       | mod_id_fwk                |
       | I_id_fwk(0) | reserved    |
	   | param_id_fwk_connect      |
       | param_size  | reserved    |
        ---------------------------
       | MID_src1                  |
       | IID_src1    | num_dst_mods|
        ---------------------------
       | MID_dst1                  |
       | IID_dst1    | num_edges   |
        ---------------------------
	   | pin_src1    | pin_dst1    |
	   | pin_src2    | pin_dst2    |

	   | MID_dst2                  |
       | IID_dst2    | num_edges   |
	   | pin_src1    | pin_dst1    |
	   | pin_src2    | pin_dst2    |
	     ...
	   | MID_src2                  |
       | IID_src2    | num_dst_mods|
	     ...

   @endcode

   @sa
   acdb_ioctl \n
   _AcdbWdspDidUcidSubGraphIDPairType \n
   _AcdbQueryResponseType
*/
#define ACDB_WDSP_CMD_GET_SUBGRAPHS_CONNECTION    0x00014008

/**
   Query command structure for getting the size of a subgraph list.
*/
typedef struct _AcdbWdspDidUcidSubGraphIDPairType {
   uint32_t nDeviceId;               /**< Tx device ID. */
   uint32_t nUsecaseId;                /**< Usecase ID. */
   uint32_t nSubGraphIdSrc;               /**< Source Subgraph ID. */
   uint32_t nSubGraphIdDst;               /**< Destination Subgraph ID. */
   uint32_t nBufferLength;     /**< Length of the calibration buffer. This must be large enough to hold
          the entire table. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to the memory region into which the
          ACDB is to copy the table. */
} AcdbWdspDidUcidSubGraphIDPairType;

/** @} */ /* end_addtogroup get_wdsp_subgraph_subgraphs_connection */

/* ---------------------------------------------------------------------------
 * ACDB_WDSP_CMD_GET_SUBGRAPH_MODULE_CALIBRATION_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_wdsp_subgraph_module_calibration_size
@{ */

/**
   Queries for the size of calibration data of all modules for one subgraph under a given deviceID and usecase ID.

   @param[in] nCommandId
         Command ID is ACDB_WDSP_CMD_GET_SUBGRAPH_MODULE_CALIBRATION_SIZE.
   @param[in] pCommandStruct
         Pointer to WdspDidUcidSubGraphIDSizeCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of WdspDidUcidSubGraphIDSizeCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbWdspDidUcidSubGraphIDType \n
   _AcdbSizeResponseType
*/
#define ACDB_WDSP_CMD_GET_SUBGRAPH_MODULE_CALIBRATION_SIZE    0x00014009

/** @} */ /* end_addtogroup get_wdsp_subgraph_module_calibration_size */

/* ---------------------------------------------------------------------------
 * ACDB_WDSP_CMD_GET_SUBGRAPH_MODULE_CALIBRATION
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_wdsp_subgraph_module_calibration
@{ */

/**
   Queries all modules calibration data in one subgraph for a given deviceID and usecase ID

   @param[in] nCommandId
         Command ID is ACDB_WDSP_CMD_GET_SUBGRAPH_MODULE_CALIBRATION.
   @param[in] pCommandStruct
         Pointer to AcdbWdspDidUcidSubGraphIDType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbWdspDidUcidSubGraphIDType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

       When the call is successful, the nBufferPointer member of the AcdbWdspDidUcidSubGraphIDType
       is filled with the module information data in the following format:
   @code
       -----------32 Bit----------
       | mod_id                    |
       | I_id        | reserved    |
	   | param_id    |
       | param_size  | reserved    |
        ---------------------------
       | cal data                  |
	    ---------------------------
	   | mod_id                    |
       | I_id        | reserved    |
	   | param_id                  |
       | param_size  | reserved    |
        ---------------------------
       | cal data                  |
	     ...

   @endcode

   @sa
   acdb_ioctl \n
   _AcdbWdspDidUcidSubGraphIDType \n
   _AcdbQueryResponseType
*/
#define ACDB_WDSP_CMD_GET_SUBGRAPH_MODULE_CALIBRATION    0x0001400A

/** @} */ /* end_addtogroup get_wdsp_subgraph_module_calibration */

/* ---------------------------------------------------------------------------
 * ACDB_WDSP_CMD_GET_BOOT_TIME_MODULE_LIST_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_wdsp_boottime_module_list_size
@{ */

/**
Queries the size of all boot time module list.

   @param[in] nCommandId
         Command ID is ACDB_WDSP_CMD_GET_BOOT_TIME_MODULE_LIST_SIZE.
   @param[in] pCommandStruct
         There is no input structure; set this to NULL.
   @param[in] nCommandStructLength
         There is no input structure; set this to 0.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   None \n
   _AcdbSizeResponseType
*/
#define ACDB_WDSP_CMD_GET_BOOT_TIME_MODULE_LIST_SIZE    0x0001400B

/** @} */ /* end_addtogroup get_wdsp_boottime_module_list_size */

/* ---------------------------------------------------------------------------
 * ACDB_WDSP_CMD_GET_BOOT_TIME_MODULE_LIST
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_wdsp_boottime_module_list
@{ */

/**
   Queries all boot time module list.

   @param[in] nCommandId
         Command ID is ACDB_WDSP_CMD_GET_BOOT_TIME_MODULE_LIST.
   @param[in] pCommandStruct
         Pointer to AcdbWdspBootTimeModuleReqType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbWdspBootTimeModuleReqType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

       When the call is successful, the nBufferPointer member of the AcdbWdspBootTimeModuleReqType
       is filled with the module information data in the following format:

	   @code
        ------32 Bit------
       | nNumOfModules    |
       | MID[0]           |
       | MID[1]           |
       | ...

   @endcode

   @sa
   acdb_ioctl \n
   _AcdbWdspBootTimeModuleReqType \n
   _AcdbQueryResponseType
*/
#define ACDB_WDSP_CMD_GET_BOOT_TIME_MODULE_LIST    0x0001400C

/**
   Query command structure for getting the size of a subgraph list.
*/
typedef struct _AcdbWdspBootTimeModuleReqType {
   uint32_t nBufferLength;     /**< Length of the calibration buffer. This must be large enough to hold
          the entire table. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to the memory region into which the
          ACDB is to copy the table. */
} AcdbWdspBootTimeModuleReqType;

/** @} */ /* end_addtogroup get_wdsp_boottime_module_list */

/* ---------------------------------------------------------------------------
 * ACDB_WDSP_CMD_GET_MODULE_LOADING_META_INFO_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_wdsp_module_loading_meta_info_size
@{ */

/**
   Queries for the size of meta information for boot time modules or dynamic modules.

   @param[in] nCommandId
         Command ID is ACDB_WDSP_CMD_GET_MODULE_LOADING_META_INFO_SIZE.
   @param[in] pCommandStruct
         Pointer to WdspGetDynamicModuleInfoSizeCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of WdspGetDynamicModuleInfoSizeCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _WdspGetDynamicModuleInfoSizeCmdType \n
   _AcdbSizeResponseType
*/
#define ACDB_WDSP_CMD_GET_MODULE_LOADING_META_INFO_SIZE    0x0001400D

typedef struct _WdspGetDynamicModuleInfoSizeCmdType WdspGetDynamicModuleInfoSizeCmdType;
#include "acdb_begin_pack.h"

/**
   Request command structure for module metainfo list.
*/
struct _WdspGetDynamicModuleInfoSizeCmdType {
	uint32_t nModuleType;	/**< 0 - boottime module
						  1 - dynamic module
						  2 - static module
						  Other values are not supported.
						  */
	uint32_t nNumOfModules;	/**< Number of module IDs. */
	uint8_t *pBuff;	/**< Virtual memory pointer to a memory region where module IDS are there. */
}

#include "acdb_end_pack.h"
;

/** @} */ /* end_addtogroup get_wdsp_module_loading_meta_info_size */

/* ---------------------------------------------------------------------------
 * ACDB_WDSP_CMD_GET_MODULE_LOADING_META_INFO
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_wdsp_module_loading_meta_info
@{ */

/**
   Queries all modules calibration data in one subgraph for a given deviceID and usecase ID

   @param[in] nCommandId
         Command ID is ACDB_WDSP_CMD_GET_MODULE_LOADING_META_INFO.
   @param[in] pCommandStruct
         Pointer to AcdbWdspGetDynamicModuleReqType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbWdspGetDynamicModuleReqType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

       When the call is successful, the nBufferPointer member of the AcdbWdspGetDynamicModuleReqType
       is filled with the module information data in the following format:
   @code
    struct AcdbWdspDynamicLoadingModuleInfoRspType
 {
   uint32_t nNumOfModules;  // Number of modules
   AcdbWdspDynamicLoadingModuleInfoType modMetaData[nNumOfModules];
 };

 struct AcdbWdspDynamicLoadingModuleInfoType
 {
   uint32_t mid;	//module ID
   uint32_t nMetaInfo;    //Bit 0: downloading the module to island or non-island heap. All other bits should be always 0.If bit 0 is set to 0, then this indicates that the module needs to be downloaded into Non-island heap. If set to 1 it needs to be downloaded to island heap.
   uint32_t nLibFilePathSize;     //Library file path size
   uint8_t pLibDFilePath[nLibFilePathSize];   //Library file path bytes
   Padding bytes should be added to make the structure 4-byte aligned
 };

       |--------32 Bit-------|
       | nNumOfModules       |
       | ModuleInfoType[0]   |
	   | ModuleInfoType[1]   |

	   Structure of  ModuleInfoType is:

	    -----------32 Bit----------
       | nMetaInfo                 |
       | nLibFilePathSize          |
	   |pLibDFilePath bytes        |
       |  ...                      |

	   Padding bytes should be added to make the structure 4-byte aligned.

   @endcode

   @sa
   acdb_ioctl \n
   _AcdbWdspGetDynamicModuleReqType \n
   _AcdbWdspDynamicLoadingModuleInfoRspType
*/
#define ACDB_WDSP_CMD_GET_MODULE_LOADING_META_INFO    0x0001400E

typedef struct _AcdbWdspGetDynamicModuleReqType AcdbWdspGetDynamicModuleReqType;
#include "acdb_begin_pack.h"

/**
   Request command structure for module metainfo list.
*/
struct _AcdbWdspGetDynamicModuleReqType {
	uint32_t nModuleType; /**< 0 - boottime module
						  1 - dynamic module
						  2 - static module
						  Other values are not supported.
						  */
	uint32_t nNumOfModules;
	/**< Number of module IDs. */
	uint8_t *pBuff;
	/**< Virtual memory pointer to a memory region where module IDS are there. */
	uint32_t nBufferLength;     /**< Length of the calibration buffer. This must be large enough to hold
          the entire table. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to the memory region into which the
          ACDB is to copy the table. */
}

#include "acdb_end_pack.h"
;

/** @} */ /* end_addtogroup get_wdsp_module_loading_meta_info */

/*----------------------------------------------------------------------------
 * ACDB_CMD_GET_ADSP_INSTANCE_ID_SUPPORT_INFO declarations and documentation
 *---------------------------------------------------------------------------- */

 /** @addtogroup get_adsp_instance_id_support_info
@{ */

/**
   Queries for ADSP instance ID support in ACDB files.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_ADSP_INSTANCE_ID_SUPPORT_INFO.
   @param[in] pCommandStruct
         Pointer to AcdbQueryCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbQueryCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[out] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_PARMNOTFOUND -- Data for the specified and Key value were
                          not found.
   - ACDB_INSUFFICIENTMEMORY -- Insufficient memory was allocated
                      for this operation.

   @sa
   acdb_ioctl \n
    _AcdbQueryCmdType\n
   _AcdbQueryResponseType

   If this command is successful, the pBufferPointer member of the command
   structure AcdbQueryCmdType is filled with uint32 value. Supported values are
    0 when ADSP instance ID is not supported.
	1 when ADSP instance ID is supported.

*/

#define ACDB_CMD_GET_ADSP_INSTANCE_ID_SUPPORT_INFO                 0x00013262

/** @} */ /* end_addtogroup get_adsp_instance_id_support_info */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDPROC_INSTANCE_COMMON_DATA and ACDB_CMD_SET_AUDPROC_INSTANCE_COMMON_DATA
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_audproc_instance_com_data
@{ */

/**
   Queries for specific AudProc instance common calibration data.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDPROC_INSTANCE_COMMON_DATA.
   @param[in] pCommandStruct
         Pointer to AcdbAudProcInstanceCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudProcInstanceCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_PARMNOTFOUND -- Parameter data was not found.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbAudProcInstanceCmdType \n
   _AcdbQueryResponseType
   @newpage
*/
#define ACDB_CMD_GET_AUDPROC_INSTANCE_COMMON_DATA     0x00013263

/** @} */ /* end_addtogroup get_audproc_instance_com_data */

/** @ingroup set_audproc_instance_com_data

   Changes individual calibration data in the ACDB.

   This command allows the overriding of AudProc instance common calibration
   data stored in the database.

   @param[in] nCommandId
         Command ID is ACDB_CMD_SET_AUDPROC_INSTANCE_COMMON_DATA.
   @param[in] pCommandStruct
         Pointer to AcdbAudProcInstanceCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudProcInstanceCmdType.
   @param[out] pResponseStruct
         There is no output structure; set this to NULL.
   @param[in] nResponseStructLength
         There is no output structure; set this to 0.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.

   @sa
   acdb_ioctl \n
   _AcdbAudProcInstanceCmdType
*/
#define ACDB_CMD_SET_AUDPROC_INSTANCE_COMMON_DATA     0x00013264

/** @addtogroup get_audproc_instance_com_data
@{ */

/**
   Query command structure for getting the AudProc common calibration data
   tables.
*/
typedef struct _AcdbAudProcInstanceCmdType AcdbAudProcInstanceCmdType;

#include "acdb_begin_pack.h"
struct _AcdbAudProcInstanceCmdType {
   uint32_t nDeviceId;
     /**< Device ID. */
   uint32_t nDeviceSampleRateId;
     /**< Actual sample rate at which the device is operating, in Hz. */
   uint32_t nApplicationType;
     /**< Application type ID. */
   uint32_t nModuleId;
     /**< Module ID. */
   uint16_t nInstanceId;
   /**< Instance ID. */
   uint16_t nReserved1;
   /** < reserved parameter. */
   uint32_t nParamId;
     /**< Parameter ID of the module for which to query. */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the parameters identified by the nParamId identifier. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to a memory region containing the
          payload (or receiving the payload) identified by nParamId. */
}
#include "acdb_end_pack.h"
;
/** @} */ /* end_addtogroup get_audproc_instance_com_data */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDPROC_INSTANCE_COMMON_TABLE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_audproc_instance_com_tbl
@{ */

/**
   Queries for specific calibration data for the AudProc instance common table in the
   Hexagon@tm table format.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDPROC_INSTANCE_COMMON_TABLE.
   @param[in] pCommandStruct
         Pointer to AcdbAudProcTableCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudProcTableCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.
   @vertspace{-10}
   @sa
   acdb_ioctl \n
   _AcdbAudProcTableCmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_AUDPROC_INSTANCE_COMMON_TABLE    0x00013265

/**
   Query command structure for getting
   calibration data in the AudProc instance data tables.

   The format of the table matches the table format in the Hexagon API:
@code
   struct AudProcInstanceTableEntry {
      uint32_t nModuleId;
	  uint16_t nInstanceId;
	  uint16_t nReserved1;
      uint32_t nParamId;
	  uint16_t nParamSize; //multiple of 4
      uint16_t nReserved; // Must be 0
      uint8 aParamData [multiple of 4];
   }

@endcode
*/

/** @} */ /* end_addtogroup get_audproc_instance_com_tbl */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_SET_AUDPROC_INSTANCE_COMMON_TABLE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup set_audproc_instance_com_tbl
@{ */

/**
   Queries for specific calibration data for the AudProc instance common table in the
   Hexagon table format.

   This command allows the overriding of AudProc instance common calibration
   table stored in the database.

   Note: Caller should take care of making the data base consistent in case
   ACDB_BADPARM is returned.

   @param[in] nCommandId
         Command ID is ACDB_CMD_SET_AUDPROC_INSTANCE_COMMON_TABLE.
   @param[in] pCommandStruct
         Pointer to AcdbAudProcTableCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudProcTableCmdType.
   @param[out] pResponseStruct
         There is no output structure; set this to NULL.
   @param[in] nResponseStructLength
         There is no output structure; set this to 0.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.

   @vertspace{-10}
   @sa
   acdb_ioctl \n
   _AcdbAudProcTableCmdType \n
*/
#define ACDB_CMD_SET_AUDPROC_INSTANCE_COMMON_TABLE    0x00013266

/** @} */ /* end_addtogroup set_audproc_instance_com_tbl */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDPROC_INSTANCE_COMMON_TABLE_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_audproc_instance_com_tbl_size
@{ */

/**
   Queries for the size of an AudProc instance common calibration table.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDPROC_INSTANCE_COMMON_TABLE_SIZE.
   @param[in] pCommandStruct
         Pointer to AcdbAudProcTableSizeCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudProcTableSizeCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return  The return values of this function are:
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbAudProcTableSizeCmdType \n
   _AcdbSizeResponseType
*/
#define ACDB_CMD_GET_AUDPROC_INSTANCE_COMMON_TABLE_SIZE    0x00013267

/** @} */ /* end_addtogroup get_audproc_instance_com_tbl_size */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDPROC_INSTANCE_STREAM_TABLE_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_audproc_instance_strm_tbl_size
@{ */

/**
   Queries for the size of an AudProc insatance stream calibration table.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDPROC_INSTANCE_STREAM_TABLE_SIZE.
   @param[in] pCommandStruct
         Pointer to AcdbAudStrmTblSizeCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudStrmTblSizeCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbAudStrmTableV2SizeCmdType \n
   _AcdbSizeResponseType
*/
#define ACDB_CMD_GET_AUDPROC_INSTANCE_STREAM_TABLE_SIZE    0x00013268

/** @} */ /* end_addtogroup get_audproc_instance_strm_tbl_size */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDPROC_INSTANCE_STREAM_TABLE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_audproc_instance_strm_tbl
@{ */

/**
   Queries for an AudProc instance stream calibration table in the Hexagon table
   format.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDPROC_INSTANCE_STREAM_TABLE.
   @param[in] pCommandStruct
         Pointer to AcdbAudStrmTableV2CmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudStrmTableV2CmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.
   @vertspace{-10}
   @sa
   acdb_ioctl \n
   _AcdbAudStrmTableV2CmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_AUDPROC_INSTANCE_STREAM_TABLE    0x00013269

/**
   Query command structure for getting calibration data in the AudProc insatnce stream
   data tables.

   The format of the table matches the Hexagon table format:
@code
      struct AudStrmInstanceTableEntry {
         uint32_t nModuleId;
		 uint16_t nInstanceId;
		 uint16_t nReserved;
         uint32_t nParamId;
         uint16_t nParamSize; //multiple of 4
         uint16_t nReserved; // Must be 0
         uint8 aParamData [multiple of 4];
     }

@endcode
*/

/** @} */ /* end_addtogroup get_audproc_instance_strm_tbl */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_SET_AUDPROC_INSTANCE_STREAM_TABLE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup set_audproc_instance_strm_tbl
@{ */

/**
   Queries for an setting AudProc insatnce stream calibration table in the Hexagon table
   format.

   This command allows the overriding of AudProc insatnce stream calibration
   table stored in the database.

   Note: Caller should take care of making the data base consistent in case
   ACDB_BADPARM is returned.

   @param[in] nCommandId
         Command ID is ACDB_CMD_SET_AUDPROC_INSTANCE_STREAM_TABLE.
   @param[in] pCommandStruct
         Pointer to AcdbAudStrmTableV2CmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudStrmTableV2CmdType.
   @param[out] pResponseStruct
         There is no output structure; set this to NULL.
   @param[in] nResponseStructLength
         There is no output structure; set this to 0.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.

   @vertspace{-10}
   @sa
   acdb_ioctl \n
   _AcdbAudStrmTableV2CmdType \n
*/
#define ACDB_CMD_SET_AUDPROC_INSTANCE_STREAM_TABLE    0x0001326A

/** @} */ /* end_addtogroup set_audproc_instance_strm_tbl */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDPROC_INSTANCE_STREAM_DATA and ACDB_CMD_SET_AUDPROC_INSTANCE_STREAM_DATA
 *    Declarations and Documentation
 *-------------------------------------------------------------------------- */

/** @addtogroup get_audproc_instance_strm_data
@{ */

/**
   Queries for the specified AudProc instance stream calibration data.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDPROC_INSTANCE_STREAM_DATA.
   @param[in] pCommandStruct
         Pointer to AcdbAudStrmInstanceCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudStrmInstanceCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_PARMNOTFOUND -- Parameter data not found.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.
   - ACDB_DATA_NOT_FOUND -- Data for the specified input parameterd was not found
                            in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbAudStrmInstanceCmdType \n
   _AcdbQueryResponseType
   @newpage
*/
#define ACDB_CMD_GET_AUDPROC_INSTANCE_STREAM_DATA     0x0001326B

/** @} */ /* end_addtogroup get_audproc_instance_strm_data */

/** @ingroup set_audproc_instance_strm_data

   Changes individual calibration data in the database.

   This command enables the overriding of AudProc instance stream calibration data
   stored in the database.

   @param[in] nCommandId
         Command ID is ACDB_CMD_SET_AUDPROC_INSTANCE_STREAM_DATA.
   @param[in] pCommandStruct
         Pointer to AcdbAudStrmInstanceCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudStrmInstanceCmdType.
   @param[out] pResponseStruct
         There is no output structure; set this to NULL.
   @param[in] nResponseStructLength
         There is no output structure; set this to 0.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbAudStrmInstanceCmdType
*/
#define ACDB_CMD_SET_AUDPROC_INSTANCE_STREAM_DATA      0x0001326C

/** @addtogroup get_audproc_instance_strm_data
@{ */

/**
   Query command structure for getting the AudProc stream data tables.
*/

typedef struct _AcdbAudStrmInstanceCmdType AcdbAudStrmInstanceCmdType;

#include "acdb_begin_pack.h"
struct _AcdbAudStrmInstanceCmdType {
   uint32_t nApplicationTypeId;
     /**< Application type ID. */
   uint32_t nModuleId;
     /**< Module ID. */
   uint16_t nInstanceId;
   /** < Instance ID. */
   uint16_t nReserved1;
   /**< Reserved. */
   uint32_t nParamId;
     /**< Parameter ID of the module for which to query. */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the parameters identified by the nParamId identifier. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to a memory region containing the
          payload (or receiving the payload) identified by nParamId. */
}
#include "acdb_end_pack.h"
;
/** @} */ /* end_addtogroup get_audproc_instance_strm_data */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDPROC_INSTANCE_GAIN_DEP_STEP_TABLE_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_audproc_instance_gain_dep_step_tbl_size
@{ */

/**
   Queries for the size of an AudProc gain-dependent table for the specified
   volume step size.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDPROC_INSTANCE_GAIN_DEP_STEP_TABLE_SIZE.
   @param[in] pCommandStruct
         Pointer to AcdbAudProcGainDepVolTblStepSizeCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudProcGainDepVolTblStepSizeCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbAudProcGainDepVolTblStepSizeCmdType \n
   _AcdbSizeResponseType
   @newpage
*/
#define ACDB_CMD_GET_AUDPROC_INSTANCE_GAIN_DEP_STEP_TABLE_SIZE    0x0001326D

/** @} */ /* end_addtogroup get_audproc_instance_gain_dep_step_tbl_size */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AUDPROC_INSTANCE_GAIN_DEP_STEP_TABLE
 *    Declarations and Documentation
 *-------------------------------------------------------------------------- */

/** @ingroup get_audproc_instance_gain_dep_step_tbl

   Queries for the audio volume gain-dependent instance COPP calibration per the specified
   volume step table.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AUDPROC_INSTANCE_GAIN_DEP_STEP_TABLE.
   @param[in] pCommandStruct
         Pointer to AcdbAudProcGainDepVolTblStepCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAudProcGainDepVolTblStepCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbAudProcGainDepVolTblStepCmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_AUDPROC_INSTANCE_GAIN_DEP_STEP_TABLE             0x0001326E

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AFE_INSTANCE_COMMON_TABLE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_afe_instance_com_tbl
@{ */

/**
   Queries for an AFE instance common calibration table in the Hexagon table format.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AFE_INSTANCE_COMMON_TABLE.
   @param[in] pCommandStruct
         Pointer to AcdbAfeCommonTableCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAfeCommonTableCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.
   @vertspace{-10}
   @sa
   acdb_ioctl \n
   _AcdbAfeCommonTableCmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_AFE_INSTANCE_COMMON_TABLE    0x0001326F

/**
   Query command structure for getting
   calibration data in the AFE instance data tables.

   The format of the table matches the Hexagon API table format:
@code
      struct AfeInstanceCommonTableEntry {
         uint32_t nModuleId;
		 uint16_t nInstanceId;
		 uint16_t nReserved;
         uint32_t nParamId;
         uint16_t nParamSize; //multiple of 4
         uint16_t nReserved; // Must be 0
         uint8 aParamData [multiple of 4)];
     }

@endcode
*/

/** @} */ /* end_addtogroup get_afe_instance_com_tbl */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AFE_INSTANCE_COMMON_DATA
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_afe_insatnce_com_data
@{ */

/**
   Queries for specific AFE instance common calibration data.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AFE_INSTANCE_COMMON_DATA.
   @param[in] pCommandStruct
         Pointer to AcdbAfeInstanceCmnDataCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAfeInstanceCmnDataCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_PARMNOTFOUND -- Parameter data not found.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.
   @vertspace{-10}
   @sa
   acdb_ioctl \n
   _AcdbAfeInstanceCmnDataCmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_AFE_INSTANCE_COMMON_DATA                                     0x00013270

/**
   Query command structure for getting
   calibration data in the AFE instance common data tables.
*/
typedef struct _AcdbAfeInstanceCmnDataCmdType AcdbAfeInstanceCmnDataCmdType;
#include "acdb_begin_pack.h"

struct _AcdbAfeInstanceCmnDataCmdType {
   uint32_t nDeviceId;
     /**< Device ID. */
   uint32_t nAfeSampleRateId;
     /**< AFE sample rate ID in Hz. */
   uint32_t nModuleId;
     /**< Module ID. */
   uint16_t nInstanceId;
     /**< Instance ID. */
   uint16_t nReserved1;
     /**< Reserved. */
   uint32_t nParamId;
     /**< Parameter ID of the module for which to query. */
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the parameters identified by the  nParamId identifier. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to a memory region containing the
          payload (or receiving the payload) identified by nParamId. */
}

#include "acdb_end_pack.h"
;

/** @} */ /* end_addtogroup get_afe_insatnce_com_data */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AFE_INSTANCE_COMMON_TABLE_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_afe_instance_com_tbl_size
@{ */

/**
   Queries for the size of an AFE instance common calibration table.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AFE_INSTANCE_COMMON_TABLE_SIZE.
   @param[in] pCommandStruct
         Pointer to AcdbAfeCommonTableSizeCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbAfeCommonTableSizeCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbAfeCommonTableSizeCmdType \n
   _AcdbSizeResponseType
*/
#define ACDB_CMD_GET_AFE_INSTANCE_COMMON_TABLE_SIZE    0x00013271

/** @} */ /* end_addtogroup get_afe_instance_com_tbl_size */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_LSM_INSTANCE_TABLE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_lsm_instance_tbl
@{ */

/**
   Queries for an Listen Stream Manager (LSM) instance calibration table in the Hexagon
   table format.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_LSM_INSTANCE_TABLE.
   @param[in] pCommandStruct
         Pointer to AcdbLsmTableCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbLsmTableCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.
   @vertspace{-10}
   @sa
   acdb_ioctl \n
   _AcdbLsmTableCmdType \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_LSM_INSTANCE_TABLE    0x00013272

/**
   Query command structure for getting calibration data in the LSM instance tables for
   the specified device ID and the Mic Activity Detection (MAD) application
   type.

   The format of the table matches the table format in the AFE Instance API:
@code
      struct LsmTableEntry {
         uint32_t nModuleId;
		 uint16_t nInstanceId;
		 uint16_t nReserved1;
         uint32_t nParamId;
         uint16_t nParamSize; // Multiple of 4
         uint16_t nReserved;  // Must be 0
         uint8 aParamData [multiple of 4];
     }

@endcode
*/

/** @} */ /* end_addtogroup get_lsm_instance_tbl */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_LSM_INSTANCE_TABLE_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_lsm_instance_tbl_size
@{ */

/**
   Queries for the size of an LSM table for the specified device ID and the
   MAD application type ID.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_LSM_INSTANCE_TABLE_SIZE.
   @param[in] pCommandStruct
         Pointer to AcdbLsmTableSizeCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbLsmTableSizeCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INPUT_PARAMS_NOT_FOUND -- Provided input parameters were not found
                                    in the ACDB.

   @sa
   acdb_ioctl \n
   _AcdbLsmTableSizeCmdType \n
   _AcdbSizeResponseType
*/
#define ACDB_CMD_GET_LSM_INSTANCE_TABLE_SIZE    0x00013273

/** @} */ /* end_addtogroup get_lsm_instance_tbl_size */

/* ---------------------------------------------------------------------------
* o	ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO_WITH_INSTANCEID_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_avcs_custom_topo_info_with_instance_size
@{ */

/**
   Queries for the size of all the avcs custom added topologies with instance IDs to be registered

   @param[in] nCommandId
         Command ID is o	ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO_WITH_INSTANCEID_SIZE.
   @param[in] pCommandStruct
		 There is no input structure; set this to NULL.
   @param[in] nCommandStructLength
		 There is no input structure; set this to 0.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_DATA_NOT_FOUND --custom topologies data was not found.

@sa
acdb_ioctl \n
_AcdbSizeResponseType
*/
#define ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO_WITH_INSTANCEID_SIZE			0x00013274

/** @} */ /* end_addtogroup get_avcs_custom_topo_info_with_instance_size */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO_WITH_INSTANCEID
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

 /** @addtogroup get_avcs_custom_topo_info_with_insance
@{ */

/**
   Queries for all the avcs custom added topologies with instance IDs to be registered

     @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO_WITH_INSTANCEID.
   @param[in] pCommandStruct
         Pointer to AcdbQueryCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbQueryCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @vertspace{-12}
   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_DATA_NOT_FOUND --  custom topologies data was not found.

   @vertspace{-8}
   If the command is successful, the pBufferPointer of the struct
   AcdbQueryCmdType is filled in the following format:
@code

  struct avcs_topology_buffer_t
 {
   uint32_t num_topologies;  // Specifies the number of topologies in this command
   avcs_topology_definition_t pTopDefs[];
 };

 struct avcs_topology_definition_t
 {
   uint32_t version;
   uint32_t topology_id;
   uint32_t topo_config;   //Config data related to this topology
   uint32_t num_modules;
   avcs_module_info_t pModDefs[];
 };

 struct avcs_module_info_t
 {
   uint32_t module_id; //Module ID
   uint16_t instance_id; //instance ID
   uint16_t reserved1; //Reserved
 };

@endcode
   @vertspace{-5}
   @sa
   acdb_ioctl
*/
#define ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO_WITH_INSTANCEID			0x00013275

/** @} */ /* end_addtogroup get_avcs_custom_topo_info_with_insance */


/* ---------------------------------------------------------------------------
* ACDB_CMD_GET_PP_SEQUENCE_SIZE Declarations and Documentation
* --------------------------------------------------------------------------- */

/** @addtogroup get_pp_sequence_size
@{ */

/**
This command will query for the size needed for the list of modules which needs to be constructed for a device use case.

@param[in] nCommandId:
The command id is ACDB_CMD_GET_PP_SEQUENCE_SIZE.
@param[in] pCommandStruct:
This should be a pointer to GetPPSequenceCmdType representing the
Device ID and Post Processing topology type.
@param[in] nCommandStructLength: This should be equal to sizeof
GetPPSequenceCmdType.
@param[out] pResponseStruct:
This should be a pointer to AcdbSizeResponseType, when return the
uint32 is set to the value of
sizeof(uint32_t)+sizeof(uint32_t)*nNoOfModules for this
device, refer to PPSequenceType structure.
@param[in] nResponseStructLength: This should equal to sizeof
AcdbSizeResponseType.

@see acdb_ioctl
@see GetPPSequenceCmdType
@see PPSequenceType

@return The return values of this function are:
ACDB_SUCCESS -- When the command executes without problem.
ACDB_ERROR -- No or incorrect ACDB files were loaded.
ACDB_BADPARM -- One or more invalid parameters were provided.
ACDB_PARMNOTFOUND -- Parameter data was not found.
*/
#define ACDB_CMD_GET_PP_SEQUENCE_SIZE 0x0001313F

/** @enum AcdbPostProcessingTopologyType
* These are the choices to identify the topology type of Post
* Processing, such as CODEC, AFE or AUDIO_COPP, VOICE_COPP,
* AUDIO_POPP, VOICE_POPP, etc.
*/
typedef enum AcdbPostProcessing {
	ACDB_POST_PROCESSING_CODEC = 0, /**< CODEC topology */
	ACDB_POST_PROCESSING_MAX = 0xFFFFFFFF
}AcdbPostProcessingTopologyType;
/**
@struct GetPPSequenceCmdType

@brief This is a command structure for
ACDB_CMD_GET_PP_SEQUENCE_SIZE 
@param nDeviceId: Device ID.
@param nPPType: Identify location of topology of the PP.

*/
typedef struct _GetPPSequenceCmdType {
	uint32_t nDeviceId;
	AcdbPostProcessingTopologyType nPPType;
} GetPPSequenceCmdType;

typedef struct _GetPPSequenceDataType {
	uint32_t nDeviceId;
	AcdbPostProcessingTopologyType nPPType;
	uint32_t nBufferLength;
	uint8_t *nBufferPointer;
} GetPPSequenceDataType;
/** @} */ /* end_addtogroup get_pp_sequence_size */


/* ---------------------------------------------------------------------------
* ACDB_CMD_GET_PP_SEQUENCE Declarations and Documentation
* --------------------------------------------------------------------------- */

/** @addtogroup get_pp_sequence
@{ */

/**
@fn acdb_ioctl (ACDB_CMD_GET_PP_SEQUENCE, ...)
@brief API to query for the list of modules which needs to be
constructed for a device and Post Processing topology use case.

This command will query for the list of modules which needs
to be constructed for a device and Post Processing topology use case.

@param[in] nCommandId:
The command id is ACDB_CMD_GET_PP_SEQUENCE.
@param[in] pCommandStruct:
This should be a pointer to GetPPSequenceDataType representing the
Device ID and Post Porcessing type.
@param[in] nCommandStructLength:
This should equal to sizeof (GetPPSequenceDataType).
@param[out] pResponseStruct:
This should be a pointer to a buffer of structure AcdbQueryResponseType.
for this device, note that GetPPSequenceDataType is dynamic and its size
should be determined by calling ACDB_CMD_GET_PP_SEQUENCE_SIZE command.
On return, the buffer is filled with data in a format of structure of PPSequenceType.
@param[in] nResponseStructLength:
This should be equal to the size of AcdbQueryResponseType, which is dynamic
and should be determined by calling ACDB_CMD_GET_PP_SEQUENCE_SIZE command.

@see acdb_ioctl
@see PPSequenceType


@return The return values of this function are:
ACDB_SUCCESS: When the command executes without problem.
ACDB_ERROR -- No or incorrect ACDB files were loaded.
ACDB_BADPARM -- One or more invalid parameters were provided.
ACDB_PARMNOTFOUND: When the device is not found.
*/
#define ACDB_CMD_GET_PP_SEQUENCE 0x0001313E


/**
@struct PPSequenceType

@brief This is a structure for a list of modules for a device
and Post Processing topology type.
@param nNoOfModules: The number of modules in the list.
@param pModuleIds: the array of ModuleIds of type uint32_t
each.
//below is the payload for ppsequence buffer
structure PPSequenceType {
uint32_t nNoOfModules;
uint32_t pModuleIds[nNoOfModules]; //array length is dynamic
//equals to nNoOfModules.
} PPSequenceType;

*/

/** @} */ /* end_addtogroup get_pp_sequence */

/* ---------------------------------------------------------------------------
* ACDB_CMD_GET_CODEC_PP_GAIN_DEP_STEP_DATA_SIZE Declarations and Documentation
* --------------------------------------------------------------------------- */

/** @addtogroup get_codec_pp_gain_dep_step_data_size
@{ */

/**
@fn acdb_ioctl(ACDB_CMD_GET_CODEC_PP_GAIN_DEP_STEP_DATA_SIZE, ...)
@brief API to query for a specific calibration entry size contained in the
gain-dependent codec PP table.

This command will obtain the specific calibration entry(gain step) size contianed in the
gain-dependent CODEC table.

@param[in] nCommandId:
The command id is ACDB_CMD_GET_CODEC_PP_GAIN_DEP_STEP_DATA_SIZE.
@param[in] pCommandStruct:
This should be a pointer to AcdbCodecGainSizeCmdType.
@param[in] nCommandStructLength:
This should equal sizeof (AcdbCodecGainSizeCmdType).
@param[out] pResponseStruct:
This should be a pointer to AcdbSizeResponseType.
@param[in] nResponseStructLength:
This should equal sizeof (AcdbSizeResponseType).

@see acdb_ioctl
@see AcdbCodecGainSizeCmdType
@see AcdbSizeResponseType

@return The return values of this function are:
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_PARMNOTFOUND -- Parameter data was not found.
*/
#define ACDB_CMD_GET_CODEC_PP_GAIN_DEP_STEP_DATA_SIZE 0x00013140

/**
@struct AcdbCodecGainSizeCmdType
@brief This is a query command structure for the codec gain-dependent calibration data size.

@param nDeviceId: The Device ID
@param nGainStep: The gain Index
@param nModuleId: The Module ID
@param nParamId: The Parameter ID of the Module to query for.

This is a query command structure for the codec gain-dependent calibration data size.
*/
typedef struct _AcdbCodecGainSizeCmdType {
	uint32_t nDeviceId;
	int32_t nGainStep;
	uint32_t nModuleId;
	uint32_t nParamId;
} AcdbCodecGainSizeCmdType;

/** @} */ /* end_addtogroup get_codec_pp_gain_dep_step_data_size */

/* ---------------------------------------------------------------------------
* ACDB_CMD_GET_CODEC_PP_GAIN_DEP_STEP_DATA Declarations and Documentation
* --------------------------------------------------------------------------- */

/** @addtogroup get_codec_pp_gain_dep_step_data
@{ */

/**
@fn acdb_ioctl(ACDB_CMD_GET_CODEC_PP_GAIN_DEP_STEP_DATA, ...)
@brief API to query for a specific calibration entry contained in the
gain-dependent codec PP table.

This command will obtain the specific calibration entry(gain step) contianed in the
gain-dependent CODEC table.

@param[in] nCommandId:
The command id is ACDB_CMD_GET_CODEC_PP_GAIN_DEP_STEP_DATA.
@param[in] pCommandStruct:
This should be a pointer to AcdbCodecGainCmdType.
@param[in] nCommandStructLength:
This should equal sizeof (AcdbCodecGainCmdType).
@param[out] pResponseStruct:
This should be a pointer to AcdbQueryResponseType.
@param[in] nResponseStructLength:
This should equal sizeof (AcdbQueryResponseType).

@see acdb_ioctl
@see AcdbCodecGainCmdType
@see AcdbQueryResponseType

@return The return values of this function are:
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_PARMNOTFOUND -- Parameter data was not found.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
*/
#define ACDB_CMD_GET_CODEC_PP_GAIN_DEP_STEP_DATA 0x000130F9
/**
@struct AcdbCodecGainCmdType
@brief This is a query command structure for the codec gain table
gain-dependent calibration data.

@param nDeviceId: The Device ID
@param nGainStep: The gain Index
@param nModuleId: The Module ID
@param nParamId: The Parameter ID of the Module to query for.
@param nBufferLength: The length of the calibration buffer. This should be
large enough to hold the parameters identified by the
nParamId identifier.
@param nBufferPointer: A virtual memory pointer pointing to a memory region
containing the payload (or receiving the payload)
identified by nParamId.

This is a query command structure for the codec gain-dependent calibration data.
*/
typedef struct _AcdbCodecGainCmdType {
	uint32_t nDeviceId;
	int32_t nGainStep;
	uint32_t nModuleId;
	uint32_t nParamId;
	uint32_t nBufferLength;
	uint8_t *nBufferPointer;
} AcdbCodecGainCmdType;

/** @} */ /* end_addtogroup get_codec_pp_gain_dep_step_data */

/* ---------------------------------------------------------------------------
* ACDB_CMD_GET_CODEC_PP_GAIN_DEP_TABLE_SIZE Declarations and Documentation
* --------------------------------------------------------------------------- */

/** @addtogroup get_codec_pp_gain_dep_table_size
@{ */

/**
@fn acdb_ioctl(ACDB_CMD_GET_CODEC_PP_GAIN_DEP_TABLE_SIZE, ...)
@brief API to query for calibration data size from Codec gain dependent PP table for specific gain type.

@param[in] nCommandId:
The command id is ACDB_CMD_GET_CODEC_PP_GAIN_DEP_TABLE_SIZE.
@param[in] pCommandStruct:
This should be a pointer to AcdbCodecGainTableSizeCmdType.
@param[in] nCommandStructLength:
This should equal sizeof (AcdbCodecGainTableSizeCmdType).
@param[out] pResponseStruct:
This should be a pointer to AcdbSizeResponseType.
@param[in] nResponseStructLength:
This should equal sizeof (AcdbSizeResponseType).

@see acdb_ioctl
@see AcdbCodecGainTableSizeCmdType
@see AcdbSizeResponseType

@return The return values of this function are:
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_PARMNOTFOUND -- Parameter data was not found.
*/
#define ACDB_CMD_GET_CODEC_PP_GAIN_DEP_TABLE_SIZE 0x0001313B


/**
@struct AcdbCodecGainTableSizeCmdType
@brief This is a query command structure for the codec gain table size

@param nDeviceId: The Device ID
@param nGainType: The gain Type(from AcdbCodecGainType enum)
@param nGainStep: The gain Index


This is a query command structure for the codec gain-dependent calibration table data Size.
*/
typedef struct _AcdbCodecGainTableSizeCmdType {
	uint32_t nDeviceId;
	uint32_t nGainType;
	int32_t nGainStep;
} AcdbCodecGainTableSizeCmdType;

/** @} */ /* end_addtogroup get_codec_pp_gain_dep_table_size */

/* ---------------------------------------------------------------------------
* ACDB_CMD_GET_CODEC_PP_GAIN_DEP_TABLE Declarations and Documentation
* --------------------------------------------------------------------------- */

/** @addtogroup get_codec_pp_gain_dep_table
@{ */

/**
@fn acdb_ioctl(ACDB_CMD_GET_CODEC_PP_GAIN_DEP_TABLE, ...)
@brief API to query for calibration data from Codec gain dependent PP table for specific gain type.

@param[in] nCommandId:
The command id is ACDB_CMD_GET_CODEC_PP_GAIN_DEP_TABLE.
@param[in] pCommandStruct:
This should be a pointer to AcdbCodecGainTableCmdType.
@param[in] nCommandStructLength:
This should equal sizeof (AcdbCodecGainTableCmdType).
@param[out] pResponseStruct:
This should be a pointer to AcdbQueryResponseType.
@param[in] nResponseStructLength:
This should equal sizeof (AcdbQueryResponseType).

@see acdb_ioctl
@see AcdbCodecGainCmdType
@see AcdbQueryResponseType

@return The return values of this function are:
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_PARMNOTFOUND -- Parameter data was not found.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
*/
#define ACDB_CMD_GET_CODEC_PP_GAIN_DEP_TABLE 0x0001313A

/**
@struct AcdbCodecGainTableCmdType
@brief This is a query command structure for the codec gain table

@param nDeviceId: The Device ID
@param nGainType: The gain Type(from AcdbCodecGainType enum)
@param nGainStep: The gain Index
@param nBufferLength: The length of the calibration buffer. This should be
large enough to hold the parameters identified by the
nParamId identifier.
@param nBufferPointer: A virtual memory pointer pointing to a memory region
containing the payload (or receiving the payload)
identified by nParamId.

This is a query command structure for the codec gain-dependent calibration table data.
*/
typedef struct _AcdbCodecGainTableCmdType {
	uint32_t nDeviceId;
	uint32_t nGainType;
	int32_t nGainStep;
	uint32_t nBufferLength;
	uint8_t *nBufferPointer;
} AcdbCodecGainTableCmdType;

/** @} */ /* end_addtogroup get_codec_pp_gain_dep_table */

/* ---------------------------------------------------------------------------
* ACDB_CMD_GET_CODEC_PP_COMMON_TABLE_SIZE Declarations and Documentation
* --------------------------------------------------------------------------- */

/** @addtogroup get_codec_pp_common_table_size
@{ */

/**
@fn acdb_ioctl(ACDB_CMD_GET_CODEC_PP_COMMON_TABLE_SIZE, ...)
@brief API to query for calibration data from Codec gain independent PP table Size for specific sample rate.

@param[in] nCommandId:
The command id is ACDB_CMD_GET_CODEC_PP_COMMON_TABLE_SIZE.
@param[in] pCommandStruct:
This should be a pointer to AcdbCodecCommonTableSizeCmdType.
@param[in] nCommandStructLength:
This should equal sizeof (AcdbCodecCommonTableSizeCmdType).
@param[out] pResponseStruct:
This should be a pointer to AcdbSizeResponseType.
@param[in] nResponseStructLength:
This should equal sizeof (AcdbSizeResponseType).

@see acdb_ioctl
@see AcdbCodecCommonTableSizeCmdType
@see AcdbSizeResponseType

@return The return values of this function are:
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_PARMNOTFOUND -- Parameter data was not found.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
*/
#define ACDB_CMD_GET_CODEC_PP_COMMON_TABLE_SIZE 0x0001313D


/**
@struct AcdbCodecCommonTableCmdType
@brief This is a query command structure for the codec common table Size

@param nDeviceId: The Device ID
@param nDeviceSampleRateId: The sample rate of the device


This is a query command structure for the codec gain-independent calibration table Size.
*/
typedef struct _AcdbCodecCommonTableSizeCmdType {
	uint32_t nDeviceId;
	uint32_t nDeviceSampleRateId;
} AcdbCodecCommonTableSizeCmdType;

/** @} */ /* end_addtogroup get_codec_pp_common_table_size */

/* ---------------------------------------------------------------------------
* ACDB_CMD_GET_CODEC_PP_COMMON_TABLE Declarations and Documentation
* --------------------------------------------------------------------------- */

/** @addtogroup get_codec_pp_common_table
@{ */

/**
@fn acdb_ioctl(ACDB_CMD_GET_CODEC_PP_COMMON_TABLE, ...)
@brief API to query for calibration data from Codec gain independent PP table for specific sample rate.

@param[in] nCommandId:
The command id is ACDB_CMD_GET_CODEC_PP_COMMON_TABLE.
@param[in] pCommandStruct:
This should be a pointer to AcdbCodecCommonTableCmdType.
@param[in] nCommandStructLength:
This should equal sizeof (AcdbCodecCommonTableCmdType).
@param[out] pResponseStruct:
This should be a pointer to AcdbQueryResponseType.
@param[in] nResponseStructLength:
This should equal sizeof (AcdbQueryResponseType).

@see acdb_ioctl
@see AcdbCodecCommonTableCmdType
@see AcdbQueryResponseType

@return The return values of this function are:
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_PARMNOTFOUND -- Parameter data was not found.
*/
#define ACDB_CMD_GET_CODEC_PP_COMMON_TABLE 0x0001313C


/**
@struct AcdbCodecCommonTableCmdType
@brief This is a query command structure for the codec common table

@param nDeviceId: The Device ID
@param nDeviceSampleRateId: The sample rate of the device
@param nBufferLength: The length of the calibration buffer. This should be
large enough to hold the parameters identified by the
nParamId identifier.
@param nBufferPointer: A virtual memory pointer pointing to a memory region
containing the payload (or receiving the payload)
identified by nParamId.

This is a query command structure for the codec gain-independent calibration table data.
*/
typedef struct _AcdbCodecCommonTableCmdType {
	uint32_t nDeviceId;
	uint32_t nDeviceSampleRateId;
	uint32_t nBufferLength;
	uint8_t *nBufferPointer;
} AcdbCodecCommonTableCmdType;

/** @} */ /* end_addtogroup get_codec_pp_common_table */

/*
* ---------------------------------------------------------------------------
* ACDB_CMD_GET_CODEC_GAIN_LEVELS_SIZE
* Declarations and Documentation
*--------------------------------------------------------------------------- */

/** @addtogroup get_codec_pp_codec_gain_levels_size
@{ */


/**
@fn acdb_ioctl(ACDB_CMD_GET_CODEC_GAIN_LEVELS_SIZE , ...)
@brief API to query for a codec volume table step size.

This command will obtain the generic gain steps size for volume,bass,treble and mid modules.
queried for.

@param[in] nCommandId:
The command id is ACDB_CMD_GET_CODEC_GAIN_LEVELS_SIZE.
@param[in] pCommandStruct:
There is no inutput command structure so this should be NULL.
@param[in] nCommandStructLength:
There is no inutput structure so this should be 0.
@param[out] pResponseStruct:
Pointer to the struct AcdbSizeResponseType
@param[out] nResponseStructLength:
Length of the AcdbSizeResponseType

@see acdb_ioctl
@see AcdbSizeResponseType

@return The return values of this function are:
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_PARMNOTFOUND -- Parameter data was not found.
*/
#define ACDB_CMD_GET_CODEC_GAIN_LEVELS_SIZE 0x00013141

/** @} */ /* end_addtogroup get_codec_pp_codec_gain_levels_size */

/*
* ---------------------------------------------------------------------------
* ACDB_CMD_GET_CODEC_GAIN_LEVELS
* Declarations and Documentation
*--------------------------------------------------------------------------- */

/** @addtogroup get_codec_gain_levels
@{ */

/**
@fn acdb_ioctl(ACDB_CMD_GET_CODEC_GAIN_LEVELS , ...)
@brief API to query for a codec volume table step size.

This command will obtain the generic gain steps for volume,bass,treble and mid modules.
queried for.

@param[in] nCommandId:
The command id is ACDB_CMD_GET_CODEC_GAIN_LEVELS.
@param[in] pCommandStruct:
There is no iutput command structure so this should be NULL.
@param[in] nCommandStructLength:
There is no iutput structure so this should be 0.
@param[out] pResponseStruct:
Pointer to the struct AcdbCodecGainLevelsRspType
@param[out] nResponseStructLength:
Length of the AcdbCodecGainLevelsRspType

@see acdb_ioctl
@see AcdbCodecGainLevelsRspType

@return The return values of this function are:
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_PARMNOTFOUND -- Parameter data was not found.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
*/
#define ACDB_CMD_GET_CODEC_GAIN_LEVELS 0x000130F8

/**
@struct AcdbCodecGainLevelsRspType
@brief This is a query response structure for the RX volume table step size.

@param[out] NoOfentries:
Number of entries(no of different types of gains) in payload
@param[out] Payload:
Range Data for each gain step

This is a response structure for the codec gain table step size. Number
of gain step size represent the calibration levels in the codec table.

AcdbCodecGainLevelsRspType- The payload format for this structer is

----------------------------------------------------
ENUM1(uint32) |minvalue(int32) |maxvalue(int32)| ENUM2(uint32) |minvalue(int32)| maxvalue(int32)| …N
------------------------------------------------------*/


typedef struct _AcdbCodecGainLevelsRspType {
	uint32_t NoOfentries;
	uint8_t* Payload;
} AcdbCodecGainLevelsRspType;



/** @} */ /* end_addtogroup get_codec_gain_levels */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_CODEC_PARAM_ID Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_codec_param_id
@{ */

/**
   Queries for supported codec param ID for particular Codec Path/Profile ID.

   @param[in] nCommandId
         Command ID is ACDB_CMD_GET_CODEC_PARAM_ID.
   @param[in] pCommandStruct
         Pointer to AcdbCodecParamIDCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbCodecParamIDCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_PARMNOTFOUND -- Parameter data was not found.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.

   @sa
   acdb_ioctl \n
   _AcdbCodecParamIDCmdStruct \n
   _AcdbQueryResponseType
*/
#define ACDB_CMD_GET_CODEC_PARAM_ID                        0x000131DF

typedef struct _AcdbCodecParamIDCmdStruct AcdbCodecParamIDCmdType;
#include "acdb_begin_pack.h"
/**
   Query command structure to get the Codec param ID.
*/
struct _AcdbCodecParamIDCmdStruct {
   uint32_t ulCodecPathId;
     /**< Codec path ID. */  
   uint32_t nBufferLength;
     /**< Length of the calibration buffer. This must be large enough to hold
          the codec param id list. */
   uint8_t *nBufferPointer;
     /**< Virtual memory pointer to the memory region containing the
          payload for codec pid*/
}

#include "acdb_end_pack.h"
;

/*
@ACDB_COMMON_DEVICE_INFO_HDR_PARAM_V2
New Header type for TDM device common information
This is used in ACDB_CMD_GET_COMMON_DEVICE_INFO function, input is a device id to query common device information.
New header format contains group ID, tdm slot config id.
-----------------------------------------------------------------------------
New Header Type ID (0x000130F5)|TDM ID(0x000131E9) |NoofInterfaces Supported (2)|Group TDM Cfg ID (0x000131EA)| Slot Info Cfg ID(0x0001319F)|
--------------------------------------------------------------------------------
*/
#define ACDB_COMMON_DEVICE_INFO_HDR_PARAM_V2 0x000130F5




/**
   Parameter ID identifying a TDM device type. please refer to the ACDB_CMD_GET_TARGET_SPECIFIC_DEVICE_INFO API documentation for payload format
*/
#define ACDB_DEVICE_TYPE_TDM_PARAM                            0x000131E9


/**
@fn acdb_ioctl(ACDB_CMD_GET_GROUP_DEVICE_LIST_SIZE, ...)
@brief API to query Device list size which are grouped.

This command will obtain the all the device ids which are grouped.


@param[in] nCommandId:
The command id is ACDB_CMD_GET_GROUP_DEVICE_LIST_SIZE.
@param[in] Nothing
@param[out] pResponseStruct:
This should be a pointer to AcdbSizeResponseType.
@param[in] Length of responce:
This should equal sizeof (AcdbSizeResponseType).

@see acdb_ioctl_automotive
@see AcdbSizeResponseType

@return The return values of this function are:
ACDB_RES_SUCCESS: When the command executes without problem.
ACDB_RES_BADPARM: When any parameter is not as specified as above.


*/
#define ACDB_CMD_GET_GROUP_DEVICE_LIST_SIZE 0x0001314A


/**
@fn acdb_ioctl(ACDB_CMD_GET_GROUP_DEVICE_LIST, ...)
@brief API to query Device list which are grouped.

This command will obtain the all the device ids which are grouped.


@param[in] nCommandId:
The command id is ACDB_CMD_GET_GROUP_DEVICE_LIST.
@param[in] Nothing
@param[out] pResponseStruct:
This should be a pointer to AcdbSizeResponseType.
@param[in] Length of responce:
This should equal sizeof (AcdbSizeResponseType).

@see acdb_ioctl_automotive
@see AcdbSizeResponseType

@return The return values of this function are:
ACDB_RES_SUCCESS: When the command executes without problem.
ACDB_RES_BADPARM: When any parameter is not as specified as above.


*/
#define ACDB_CMD_GET_GROUP_DEVICE_LIST 0x000130FA
/*
@struct AcdbGroupDeviceListRspType
@brief This is a query response structure to return device list which are grouped.

@param[out] NoOfentries:
Number of entries in payload
@param[out] Payload:
Device ids list which are grouped


AcdbGroupDeviceListRspType - The payload format this structure is
----------------------------------------------------
PAYLOAD SIZE(uint32)| DEVICE ID(uint32)|DEVICE ID(uint32)||DEVICE ID(uint32)| �N
------------------------------------------------------
*/

typedef struct _AcdbGroupDeviceListRspType {
	uint32_t NoOfentries;
	uint8_t* Payload;
} AcdbGroupDeviceListRspType;

/** @} */ /* end_addtogroup get_codec_param_id */

/* ---------------------------------------------------------------------------
* o	ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO_SIZE_V3
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

/** @addtogroup get_avcs_custom_topo_info_size_v3
@{ */

/**
   Queries for the size of all the avcs custom added topologies with Processor IDs(InstanceID also) to be registered

   @param[in] nCommandId
         Command ID is o	ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO_SIZE_V3.
   @param[in] pCommandStruct
		 There is no input structure; set this to NULL.
   @param[in] nCommandStructLength
		 There is no input structure; set this to 0.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_DATA_NOT_FOUND --custom topologies data was not found.

@sa
acdb_ioctl \n
_AcdbSizeResponseType
*/
#define ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO_SIZE_V3			0x00013297

/** @} */ /* end_addtogroup get_avcs_custom_topo_info_size_v3 */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO_V3
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

 /** @addtogroup get_avcs_custom_topo_info_v3
@{ */
/**
   Queries for all the avcs custom added topologies with Processor IDs to be registered

     @param[in] nCommandId
         Command ID is ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO_V3.
   @param[in] pCommandStruct
         Pointer to AcdbQueryCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbQueryCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @vertspace{-12}
   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_DATA_NOT_FOUND --  custom topologies data was not found.

   @vertspace{-8}
   If the command is successful, the pBufferPointer of the struct
   AcdbQueryCmdType is filled in the following format:
@code

  struct avcs_topology_buffer_v3
 {
   uint32_t num_topologies;  // Specifies the number of topologies in this command
   avcs_topology_definition_v3 pTopDefs[];
 };

 struct avcs_topology_definition_v3
 {
   uint32_t version;
   uint32_t topology_id;
   uint32_t topo_config;   //Config data related to this topology
   uint32_t num_modules;
   avcs_module_info_v3 pModDefs[];
 };

 struct avcs_module_info_v3
 {
   uint32_t module_id; //Module ID
   uint16_t instance_id; //instance ID
   uint16_t proc_id; //processor ID
 };

@endcode
   @vertspace{-5}
   @sa
   acdb_ioctl
*/
#define ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO_V3			0x00013296

/** @} */ /* end_addtogroup get_avcs_custom_topo_info_v3 */

/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_TDM_MULTI_LANE_CONFIG_SIZE
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

 /** @addtogroup get_tdm_lane_config
@{ */
/**
   Queries for the lane config of a group ID

     @param[in] nCommandId
         Command ID is ACDB_CMD_GET_TDM_MULTI_LANE_CONFIG_SIZE.
   @param[in] pCommandStruct
         Pointer to AcdbTdmLaneConfigQueryCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbTdmLaneConfigQueryCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbSizeResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbSizeResponseType.

   @vertspace{-12}
   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_DATA_NOT_FOUND --  custom topologies data was not found.
*/
#define ACDB_CMD_GET_TDM_MULTI_LANE_CONFIG_SIZE			0x00013365

/** @} */ /* end_addtogroup get_tdm_lane_config */


/* ---------------------------------------------------------------------------
 * ACDB_CMD_GET_TDM_MULTI_LANE_CONFIG
 *    Declarations and Documentation
 *--------------------------------------------------------------------------- */

 /** @addtogroup get_tdm_lane_config
@{ */
/**
   Queries for the lane config of a group ID

     @param[in] nCommandId
         Command ID is ACDB_CMD_GET_TDM_MULTI_LANE_CONFIG.
   @param[in] pCommandStruct
         Pointer to AcdbTdmLaneConfigQueryCmdType.
   @param[in] nCommandStructLength
         Length must equal the size of AcdbTdmLaneConfigQueryCmdType.
   @param[out] pResponseStruct
         Pointer to AcdbQueryResponseType.
   @param[in] nResponseStructLength
         Length must equal the size of AcdbQueryResponseType.

   @vertspace{-12}
   @return
   - ACDB_SUCCESS -- Command executed successfully.
   - ACDB_BADPARM -- One or more invalid parameters were provided.
   - ACDB_ERROR -- No or incorrect ACDB files were loaded.
   - ACDB_INSUFFICIENTMEMORY -- Buffer size provided is not sufficient.
   - ACDB_DATA_NOT_FOUND --  custom topologies data was not found.

   @vertspace{-8}
   If the command is successful, the pBufferPointer of the struct
   AcdbTdmLaneConfigQueryCmdType is filled in the following format:
@code

  struct multiLaneConfigData
 {
   uint16_t enable;  // Multi lane config enable or not
   uint16_t lane_mask; // Position of the active lanes. Bits 0 to N-1 correspond to lanes 0 to N-1
 };

@endcode
   @vertspace{-5}
   @sa
   acdb_ioctl

*/
#define ACDB_CMD_GET_TDM_MULTI_LANE_CONFIG			0x00013366

/** @} */ /* end_addtogroup get_tdm_lane_config */

typedef struct _AcdbTdmLaneConfigQueryCmdType AcdbTdmLaneConfigQueryCmdType;
#include "acdb_begin_pack.h"

struct _AcdbTdmLaneConfigQueryCmdType {
	uint16_t nGroupID; /**Group ID for which Lane config is queried */
	uint16_t nReserved; // Must be 0
	uint32_t nBufferLength;           /**< Buffer length. */
	uint8_t* pBufferPointer;          /**< Point to the query buffer. */
}
#include "acdb_end_pack.h"
;

/* ---------------------------------------------------------------------------
 * Function Declarations and Documentation
 *--------------------------------------------------------------------------- */
/*============================================================================
    For the ACDB IOCTL function below:

    Supported commands are:
   -----------------------
   ACDB_CMD_RESET
   ACDB_CMD_GET_DEVICE_CAPABILITIES
   ACDB_CMD_IS_DEVICE_PAIRED
   ACDB_CMD_GET_AUDPROC_COMMON_DATA
   ACDB_CMD_SET_AUDPROC_COMMON_DATA
   ACDB_CMD_GET_AUDPROC_COMMON_TABLE
   ACDB_CMD_GET_VOL_TABLE_STEP_SIZE
   ACDB_CMD_GET_ADIE_CODEC_PATH_PROFILE_V2
   ACDB_CMD_GET_ANC_TX_DEVICE
   ACDB_CMD_GET_CODEC_ANC_SETTING
   ACDB_CMD_GET_AUDPROC_COMMON_TOPOLOGY_ID
   ACDB_CMD_GET_AUDPROC_STREAM_TOPOLOGY_ID
   ACDB_CMD_GET_AFE_DATA
   ACDB_CMD_GET_GLBTBL_DATA
   ACDB_CMD_GET_COMMON_DEVICE_INFO
   ACDB_CMD_GET_TARGET_SPECIFIC_DEVICE_INFO
   ACDB_CMD_GET_VOCPROC_COMMON_TOPOLOGY_ID
   ACDB_CMD_GET_AFE_COMMON_TABLE
   ACDB_CMD_GET_AFE_COMMON_DATA
   ACDB_CMD_GET_COMPATIBLE_REMOTE_DEVICE_ID
   ACDB_CMD_GET_AUDIO_RECORD_RX_DEVICE_LIST
   ACDB_CMD_INITIALIZE_V2
   ACDB_CMD_GET_ACDB_SW_VERSION
   ACDB_CMD_GET_AUDPROC_GAIN_DEP_STEP_TABLE
   ACDB_CMD_GET_AUDPROC_VOL_STEP_TABLE
   ACDB_CMD_GET_VOC_PROC_DEVICE_CFG
   ACDB_CMD_GET_VOC_PROC_DEVICE_CFG_SIZE
   ACDB_CMD_GET_AUDPROC_STREAM_TABLE_V2
   ACDB_CMD_GET_AUDPROC_STREAM_DATA_V2
   ACDB_CMD_SET_AUDPROC_STREAM_DATA_V2
   ACDB_CMD_GET_AUDPROC_STREAM_TABLE_SIZE
   ACDB_CMD_GET_AUDPROC_COMMON_TABLE_SIZE
   ACDB_CMD_GET_AFE_COMMON_TABLE_SIZE
   ACDB_CMD_GET_AUDPROC_GAIN_DEP_STEP_TABLE_SIZE
   ACDB_CMD_GET_AUDPROC_VOL_STEP_TABLE_SIZE
   ACDB_CMD_GET_VOC_PROC_DEVICE_CFG_SIZE

   ACDB_CMD_GET_FEATURE_SUPPORTED_DEVICE_LIST
   ACDB_CMD_GET_DEVICE_PAIR_LIST
   ACDB_CMD_GET_LSM_TABLE
   ACDB_CMD_GET_LSM_TABLE_SIZE
   ACDB_CMD_GET_CODEC_CAL_DATA
   ACDB_CMD_GET_AUDIO_COPP_TOPOLOGIES
   ACDB_CMD_GET_AUDIO_COPP_TOPOLOGIES_SIZE
   ACDB_CMD_GET_AUDIO_POPP_TOPOLOGIES
   ACDB_CMD_GET_AUDIO_POPP_TOPOLOGIES_SIZE

   ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO_SIZE
   ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO
   ACDB_CMD_GET_ADIE_SIDETONE_TABLE

   ACDB_CMD_GET_DEVICE_PROPERTY
   ACDB_CMD_GET_DEVICE_PROPERTY_SIZE

   ACDB_CMD_GET_VP3_MIDPID_LIST
   ACDB_CMD_GET_VP3_DATA
   ACDB_CMD_SET_VP3_DATA
   ACDB_CMD_GET_ACDB_SW_VERSION_V2

   ACDB_CMD_SET_AUDPROC_COMMON_TABLE
   ACDB_CMD_SET_AUDPROC_STREAM_TABLE_V2

   ACDB_CMD_GET_META_INFO_SIZE
   ACDB_CMD_GET_META_INFO

   ACDB_CMD_GET_AFE_TOPOLOGY_ID
   ACDB_CMD_GET_LSM_TOPOLOGY_ID
   ACDB_CMD_GET_AFE_TOPOLOGIES
   ACDB_CMD_GET_AFE_TOPOLOGIES_SIZE
   ACDB_CMD_GET_LSM_TOPOLOGIES
   ACDB_CMD_GET_LSM_TOPOLOGIES_SIZE

   ACDB_CMD_GET_ACDB_SW_VERSION_V3

	ACDB_CMD_GET_ADSP_INSTANCE_ID_SUPPORT_INFO
	ACDB_CMD_GET_AUDPROC_INSTANCE_COMMON_DATA
	ACDB_CMD_SET_AUDPROC_INSTANCE_COMMON_DATA
	ACDB_CMD_GET_AUDPROC_INSTANCE_COMMON_TABLE
	ACDB_CMD_SET_AUDPROC_INSTANCE_COMMON_TABLE
	ACDB_CMD_GET_AUDPROC_INSTANCE_STREAM_TABLE
	ACDB_CMD_SET_AUDPROC_INSTANCE_STREAM_TABLE
	ACDB_CMD_GET_AUDPROC_INSTANCE_STREAM_DATA
	ACDB_CMD_SET_AUDPROC_INSTANCE_STREAM_DATA
	ACDB_CMD_GET_AUDPROC_INSTANCE_GAIN_DEP_STEP_TABLE
	ACDB_CMD_GET_AUDPROC_INSTANCE_STREAM_TABLE_SIZE
	ACDB_CMD_GET_AUDPROC_INSTANCE_COMMON_TABLE_SIZE
	ACDB_CMD_GET_AUDPROC_INSTANCE_GAIN_DEP_STEP_TABLE_SIZE
	ACDB_CMD_GET_AFE_INSTANCE_COMMON_TABLE
	ACDB_CMD_GET_AFE_INSTANCE_COMMON_DATA
	ACDB_CMD_GET_AFE_INSTANCE_COMMON_TABLE_SIZE
	ACDB_CMD_GET_LSM_INSTANCE_TABLE
	ACDB_CMD_GET_LSM_INSTANCE_TABLE_SIZE
	ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO_WITH_INSTANCEID_SIZE
	ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO_WITH_INSTANCEID
	ACDB_CMD_GET_ADIE_CODEC_PATH_PROFILE_V2_SIZE

   Deprecated Commands are:
   -------------------------
   ACDB_CMD_GET_ACDB_SW_VERSION
   ACDB_CMD_GET_ACDB_SW_VERSION_V2
   ACDB_CMD_GET_AUDIO_COPP_TOPOLOGIES
   ACDB_CMD_GET_AUDIO_COPP_TOPOLOGIES_SIZE
   ACDB_CMD_GET_AUDIO_POPP_TOPOLOGIES
   ACDB_CMD_GET_AUDIO_POPP_TOPOLOGIES_SIZE
   ACDB_CMD_GET_AFE_TOPOLOGIES
   ACDB_CMD_GET_AFE_TOPOLOGIES_SIZE
   ACDB_CMD_GET_LSM_TOPOLOGIES
   ACDB_CMD_GET_LSM_TOPOLOGIES_SIZE

   Deleted Commands are:
   ----------------------
   ACDB_CMD_INITIALIZE
   ACDB_CMD_GET_ACDB_VERSION
   ACDB_CMD_GET_TARGET_VERSION
   ACDB_CMD_ESTIMATE_MEMORY_USE
   ACDB_CMD_GET_VOCPROC_COMMON_DATA
   ACDB_CMD_SET_VOCPROC_COMMON_DATA
   ACDB_CMD_GET_VOCPROC_COMMON_TABLE
   ACDB_CMD_SET_VOCPROC_COMMON_TABLE
   ACDB_CMD_GET_VOCPROC_STREAM_DATA
   ACDB_CMD_SET_VOCPROC_STREAM_DATA
   ACDB_CMD_GET_VOCPROC_STREAM_TABLE
   ACDB_CMD_SET_VOCPROC_STREAM_TABLE
   ACDB_CMD_GET_AUDPROC_STREAM_DATA
   ACDB_CMD_SET_AUDPROC_STREAM_DATA
   ACDB_CMD_GET_AUDPROC_STREAM_TABLE
   ACDB_CMD_SET_AUDPROC_STREAM_TABLE
   ACDB_CMD_GET_VOCPROC_GAIN_DEP_VOLTBL
   ACDB_CMD_GET_VOCPROC_GAIN_DEP_VOLTBL_STEP_DATA
   ACDB_CMD_SET_VOCPROC_GAIN_DEP_VOLTBL_STEP_DATA

   ACDB_CMD_GET_AUDPROC_GAIN_DEP_VOLTBL_STEP_COPP
   ACDB_CMD_GET_AUDPROC_GAIN_DEP_VOLTBL_STEP_POPP
   ACDB_CMD_GET_AUDPROC_GAIN_DEP_VOLTBL_STEP_DATA
   ACDB_CMD_SET_AUDPROC_GAIN_DEP_VOLTBL_STEP_DATA
   ACDB_CMD_SET_ADIE_CODEC_PATH_PROFILE
   ACDB_CMD_SET_ANC_SETTING
   ACDB_CMD_SET_AFE_DATA
   ACDB_CMD_SET_GLBTBL_DATA
   ACDB_CMD_SET_AFE_COMMON_TABLE
   ACDB_CMD_SET_AFE_COMMON_DATA
   ACDB_CMD_GET_AFE_TOPOLOGY_LIST

   ACDB_CMD_GET_SUPPORTED_HAP_AUDIO_TOPOLOGIES_INFO

   ACDB_CMD_GET_VOC_COLUMNS_INFO_SIZE
   ACDB_CMD_GET_VOC_COLUMNS_INFO
   ACDB_CMD_GET_VOC_PROC_COMMON_TABLE_SIZE
   ACDB_CMD_GET_VOC_PROC_COMMON_TABLE
   ACDB_CMD_GET_VOC_STREAM_COMMON_TABLE_SIZE
   ACDB_CMD_GET_VOC_STREAM_COMMON_TABLE
   ACDB_CMD_GET_VOC_PROC_GAIN_DEP_VOLTBL_SIZE
   ACDB_CMD_GET_VOC_PROC_GAIN_DEP_VOLTBL
   ACDB_CMD_GET_VOC_PROC_GAIN_DEP_VOLTBL_SIZE_V2
   ACDB_CMD_GET_VOC_PROC_GAIN_DEP_VOLTBL_V2
   ACDB_CMD_GET_ADAPTIVE_ANC_CONFIG_TABLE
   ACDB_CMD_GET_ADAPTIVE_ANC_CONFIG_TABLE_SIZE
   ACDB_CMD_GET_ADAPTIVE_ANC_CONFIG_DATA

ACDB_CMD_GET_CODEC_GAIN_LEVELS_SIZE
   ACDB_CMD_GET_CODEC_GAIN_LEVELS
   ACDB_CMD_GET_CODEC_PP_GAIN_DEP_STEP_DATA_SIZE
   ACDB_CMD_GET_CODEC_PP_GAIN_DEP_STEP_DATA
   ACDB_CMD_GET_CODEC_PP_GAIN_DEP_TABLE_SIZE
   ACDB_CMD_GET_CODEC_PP_GAIN_DEP_TABLE
   ACDB_CMD_GET_CODEC_PP_COMMON_TABLE_SIZE
   ACDB_CMD_GET_CODEC_PP_COMMON_TABLE
   ACDB_CMD_GET_PP_SEQUENCE_SIZE
   ACDB_CMD_GET_PP_SEQUENCE
   ACDB_CMD_GET_CODEC_PARAM_ID
   ACDB_CMD_GET_GROUP_DEVICE_LIST_SIZE
   ACDB_CMD_GET_GROUP_DEVICE_LIST
   ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO_V3
   ACDB_CMD_GET_AVCS_CUSTOM_TOPO_INFO_SIZE_V3
============================================================================*/

/**
   @ingroup acdb_ioctl

   Main entry function to the ACDB. This entry function takes any
   supported ACDB IOCTL and provides the appropriate response.

   See the individual command documentation for more details on the
   expectations of the command.

   @param[in] nCommandId
         Command ID to execute on the Audio Calibration Database. The
         pCommandStruct and the pResponseStruct must match the expected
         structures for that command. If not, the command fails.
   @param[in] pCommandStruct
         Pointer to the command structure.
   @param[in] nCommandStructLength
         Size of the command structure.
   @param[out] pResponseStruct
         Pointer to the response structure.
   @param[in] nResponseStructLength
         Size of the response structure.

   @return
   The result of the call as defined by the command.

   @dependencies
   None

*/
int32_t acdb_ioctl(uint32_t nCommandId,
                    const uint8_t *pCommandStruct,
                    uint32_t nCommandStructLength,
                    uint8_t *pResponseStruct,
                    uint32_t nResponseStructLength);

#endif /* __ACDB_API_H__ */
