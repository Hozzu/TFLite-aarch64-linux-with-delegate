#ifndef __CAMERACOMMONTYPES_H__
#define __CAMERACOMMONTYPES_H__

/**
 * @file CameraCommonTypes.h
 *
 * @brief This file contains the common type declarations for Camera
 *
 * Copyright (c) 2009-2020 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 */

#include "CameraTypes.h"

#include "qcarcam_types.h"

/* ---------------------------------------------------------------------------
** Constant / Define Declarations
** ------------------------------------------------------------------------ */
/// This is maximum size for sensor name
#define MAX_DEVICENAME_STR_SIZE (64)

/// This is the maximum number of sensor modes supported
#define MAX_NUMBER_OF_SENSOR_MODES 7

/// This is the maximum number of output formats supported
#define MAX_NUMBER_OF_OUTPUT_FORMATS 10

/// This is the maximum number of face ROIs supported
#define MAX_NUM_FACE_ROI 32

/// This is the maximum number of user ROIs supported
#define MAX_NUM_USER_ROI 32

/// This is the maximum ROI priority supported
#define MAX_ROI_PRIORITY 100

/// This is the maximum size of the circular buffer that holds the gyro samples
#define MAX_GYRO_SAMPLE_Q_SIZE 15


#define CAMERA_BUFFER_ALIGN_4K              (1 << 12)

#define CAMERA_BUFFER_FLAG_CACHED           0x00000001
#define CAMERA_BUFFER_FLAG_SECURE           0x00000002
#define CAMERA_BUFFER_FLAG_FIXEDMAP         0x00000004
#define CAMERA_BUFFER_FLAG_CONTIGOUS        0x00000008
#define CAMERA_BUFFER_FLAG_READ             0x00000010
#define CAMERA_BUFFER_FLAG_WRITE            0x00000020
#define CAMERA_BUFFER_FLAG_PRIV_READ_WRITE  0x00000040

#define CAMERA_BUFFER_FLAG_HNDL             0x10000000 /*used if pmem hndl is used*/
#define CAMERA_BUFFER_FLAG_EXTERNAL         0x80000000

#define MAX_CHANNEL_INPUT_SRCS 2

#define ABS_DIFF(a, b) ((a > b) ? (a - b) : (b - a))


/*****************************************************************************
 ** Structured Data Types
 ****************************************************************************/
/**
 * This enum describes camera hw daughter cards
 */
typedef enum {
    CAMERA_HW_BOARD_NONE = 0,
    CAMERA_HW_BOARD_ADPAIR_V1_PJ254,
    CAMERA_HW_BOARD_ADPAIR_V2_PL195,
    CAMERA_HW_BOARD_ADPAIR_V3_PM731,
    CAMERA_HW_BOARD_ADPSTAR_V1_W4944,
    CAMERA_HW_BOARD_ADPSTAR_V2_PK901,
    CAMERA_HW_BOARD_TI9702_V1,
    CAMERA_HW_BOARD_CUSTOM = 100
} CameraHwBoardType;

/**
 * This enum describes camer power event types
 */
typedef enum
{
    CAMERA_POWER_DOWN,
    CAMERA_POWER_UP,
    CAMERA_POWER_SUSPEND,
    CAMERA_POWER_RESUME,
    CAMERA_POWER_STATES_MAX
} CameraPowerEventType;

/**
 * This structure defines the mapping of unique qcarcam descriptor to
 * input sources as well as the default operation mode.
 */
typedef struct
{
    /**
     * unique qcarcam inputId that maps to <devId, srcId>
     */
    uint32 aisInputId;

    /**
     * unique <devId, srcId> of input id and default operation mode
     */
    struct
    {
        uint32 devId;
        uint32 srcId;
    }inputSrc[MAX_CHANNEL_INPUT_SRCS];

    qcarcam_opmode_type opMode;

} CameraChannelInfoType;

/**
 * This structure defines the width and height of an object in two-dimensional
 * space.
 */
typedef struct
{
    uint32 width;
    uint32 height;
} Camera_Size;


/**
 * This structure defines a rational number, where the numerator and
 * denominator are both signed integers.
 */
typedef struct
{
   /// The numerator of the fraction
   int32 num;

   /// The denominator of the fraction
   int32 denom;
} Camera_SRational;


/**
 * This structure defines a rational number, where the numerator and
 * denominator are both unsigned integers.
 */
typedef struct
{
   /// The numerator of the fraction
   uint32 num;

   /// The denominator of the fraction
   uint32 denom;
} Camera_URational;

/**
 * This structure defines a rectangle type. A rectangle with a width and
 * height of 10 is specified as {0, 0, 10, 10}, where the top left
 * corner is (0, 0) and the bottom right corner is (9, 9).
 */
typedef struct
{
   /// The x coordinate of the top left corner of the rectangle
   int32 left;
   /// The y coordinate of the top left corner of the rectangle
   int32 top;
   /// The x coordinate of the bottom right corner that lies 1 pixel outside
   /// of the rectangle
   int32 right;
   /// The y coordinate of the bottom right corner that lies 1 pixel outside
   /// of the rectangle
   int32 bottom;
} Camera_Rectangle;

/**
 * This structures defines a string type including its size.
 */
typedef struct
{
    /// The null-terminated string
    char* data;

    /// The length of the string in characters including null terminator
    int dataLen;

    /// Upon successful return this will indicate the number of characters,
    /// including the null terminator, which would have been required to store
    /// the entire result. If, upon successful return, the value is less than
    /// or equal to dataLen, then data contains the entire result; otherwise,
    /// data contains the truncated result.
    int dataLenReq;
} Camera_String;

/**
 * This structure contains information for an available camera sensor device.
 * The information can be used to differentiate between available camera
 * sensor devices.
 */
typedef struct
{
   /// This is the UID of the device driver.
   AEECLSID idCameraDeviceID;

   /// This is the device name in the format [manufacturer] [model]
   char pszDeviceName[MAX_DEVICENAME_STR_SIZE];

   /// This is the length of the device name.
   int pszDeviceNameLen;

   /// This is the required length of the device name.
   int pszDeviceNameLenReq;

   /// This is the maximum resolution output by the device.
   Camera_Size nMaximumResolution;

   /// This indicates the minimum frame interval of the device in microseconds.
   uint32 nMinimumFrameInterval;

   /// This property defines how many degrees the currently selected sensor
   /// has been panned in its installed orientation relative to a 0.0 degree
   /// default orientation, when looking at the sensor from the top.
   ///
   /// Valid values range from -180.0 to +180.0. Negative values indicate
   /// counterclockwise rotation, and positive values indicate clockwise
   /// rotation from 0.0. The 0.0 degree default orientation corresponds to
   /// the sensor's imaging plane being parallel to the plane of the display
   /// and facing the opposite direction, which is consistent with the
   /// position in the majority of digital still camera designs. +90.0
   /// degrees indicates that the sensor's imaging plane is perpendicular to
   /// the plane of the display and that it faces right (if originally
   /// looking at the back). -90.0 degrees indicates that the sensor's
   /// imaging plane is perpendicular to the plane of the display and that
   /// it faces left (if originally looking at the back).
   ///
   /// The axis of rotation is analogous to one's head looking left and right
   /// with eyes facing forward. This is a static value indicating one axis
   /// of the sensor's orientation relative to the device it is installed in.
   /// The value does not change if the orientation of the entire device
   /// changes. Any other rolling movement must be determined by an external
   /// source.
   float fPanAngle;

   /// This property defines how many degrees the currently selected sensor
   /// has been rolled in its installed orientation relative to a 0.0 degree
   /// default orientation, when looking at the sensor from the back.
   ///
   /// Valid values range from -180.0 to +180.0. Negative values indicate
   /// counterclockwise rotation, and positive values indicate clockwise
   /// rotation from 0.0. The 0.0 degree default orientation corresponds to
   /// the top edge of the sensor facing the top of the display, which is
   /// consistent with the position in the majority of digital still camera
   /// designs. +90.0 degrees indicates that the sensor has been rotated
   /// clockwise (from the back) such that its left side is facing the top of
   /// the display. -90.0 degrees indicates that the sensor has been rotated
   /// counterclockwise (from the back) such that its right side is facing
   /// the top of the display.
   ///
   /// The axis of rotation is analogous to one's left ear touching the left
   /// shoulder or one's right ear touching the right shoulder. This is a
   /// static value indicating one axis of the sensor's orientation relative
   /// to the device it is installed in. The value does not change if the
   /// orientation of the entire device changes. Any other rolling movement
   /// must be determined by an external source.

   float fRollAngle;
   /// This property defines how many degrees the currently selected sensor
   /// has been tilted in its installed orientation relative to a 0.0 degree
   /// default orientation, when looking at the sensor from the right side
   /// (if originally looking at the back).
   ///
   /// Valid values range from -180.0 to +180.0. Negative values indicate
   /// counterclockwise rotation, and positive values indicate clockwise
   /// rotation from 0.0. The 0.0 degree default orientation corresponds to
   /// the sensor's imaging plane being parallel to the plane of the display
   /// and facing the opposite direction, which is consistent with the
   /// majority of digital still camera designs. +90.0 degrees indicates that
   /// the sensor's imaging plane is perpendicular to the plane of the
   /// display and faces upward. -90.0 degrees indicates that the sensor's
   /// imaging plane is perpendicular to the plane of the display and faces
   /// downward.
   ///
   /// The axis of rotation is analogous to one's head looking up and down
   /// with eyes facing forward. This is a static value indicating one axis
   /// of the sensor's orientation relative to the device it is installed
   /// in. The value does not change if the orientation of the entire device
   /// changes. Any other rolling movement must be determined by an external
   /// source.
   float fTiltAngle;

   /// This shows whether the device supports auto focus
   boolean bAutoFocus;


   /// Flag to indicate touch focus support of the device.
   boolean bTouchFocus;

   /// Flag to indicate continuous focus support of the device.
   boolean bContinuousFocus;
} Camera_CameraSensorDeviceInfoType;

/**
 * This enumerates the possible flash device types.
 */
typedef enum
{
   Camera_FLASH_DEVICE_TYPE_INVALID,           ///< Uninitialized value
   Camera_FLASH_DEVICE_TYPE_NONE,              ///< No flash
   Camera_FLASH_DEVICE_TYPE_LED,               ///< LED flash
   Camera_FLASH_DEVICE_TYPE_STROBE,            ///< Strobe flash
   Camera_FLASH_DEVICE_TYPE_LED_AND_STROBE     ///< LED and strobe flash
} Camera_FlashDeviceType;

/**
 * This structure contains information for an available flash device. The
 * information can be used to differentiate between available flash devices.
 */
typedef struct
{
    /// This is the type of flash device that is available.
   Camera_FlashDeviceType deviceType;
   /// This is the UID of the flash device driver.
   AEECLSID idFlashDeviceID;
} Camera_FlashDeviceInfoType;

/// This property defines the best-shot mode, e.g., beach, flower, landscape.
/// These modes adjust camera settings to preset values, overriding other
/// camera properties.
/// @par Default Value:
///   BEST_SHOT_MODE_OFF
typedef enum
{
    /// Do not use best-shot mode or autoscene scene detection
    Camera_BEST_SHOT_MODE_OFF,
    /// Auto scene detection only
    Camera_BEST_SHOT_MODE_AUTO,
    /// Antishake best-shot mode
    Camera_BEST_SHOT_MODE_ANTISHAKE,
    /// Backlight best-shot mode
    Camera_BEST_SHOT_MODE_BACKLIGHT,
    /// Beach best-shot mode
    Camera_BEST_SHOT_MODE_BEACH,
    /// Candle-light best-shot mode
    Camera_BEST_SHOT_MODE_CANDLELIGHT,
    /// Flower best-shot mode
    Camera_BEST_SHOT_MODE_FLOWER,
    /// Landscape best-shot mode
    Camera_BEST_SHOT_MODE_LANDSCAPE,
    /// Night best-shot mode
    Camera_BEST_SHOT_MODE_NIGHT,
    /// Portrait best-shot mode
    Camera_BEST_SHOT_MODE_PORTRAIT,
    /// Snow best-shot mode
    Camera_BEST_SHOT_MODE_SNOW,
    /// Sports best-shot mode
    Camera_BEST_SHOT_MODE_SPORTS,
    /// Sunset best-shot mode
    Camera_BEST_SHOT_MODE_SUNSET,
    /// Whiteboard best-shot mode
    Camera_BEST_SHOT_MODE_WHITEBOARD,
    /// Barcode best-shot mode
    Camera_BEST_SHOT_MODE_BARCODE
} Camera_BestShotMode;

/// This enumerates the operational modes
typedef enum
{
    /// Video preview operational mode
    Camera_OPERATIONAL_MODE_VIDEO_PREVIEW,

    /// Video capture operational mode
    Camera_OPERATIONAL_MODE_VIDEO_CAPTURE,

    /// Still operational mode
    Camera_OPERATIONAL_MODE_STILL,

    /// Offline operational mode
    Camera_OPERATIONAL_MODE_OFFLINE,

    /// Invalid mode
    Camera_OPERATIONAL_MODE_INVALID
} Camera_OperationalMode;

/// This property is used to inform the core camera if the camera is expected
/// to operate in preview mode or video capture mode when OnStartVideo is
/// called. While it is not necessary to set this property to be able to
/// encode frames or take snapshots, by setting this property the camera can
/// optimize its performance for the given use case.
/// @par Default Value:
///   VIDEO_MODE_PREVIEW
typedef enum
{
    /// Preview (aka viewfinder) video mode
    Camera_VIDEO_MODE_PREVIEW,
    /// Capture (aka, camcorder or video record) video mode
    Camera_VIDEO_MODE_CAPTURE
} Camera_VideoMode;

/// This property defines the status of the connection between the camera
/// and ADSP sensor sub-system
typedef enum
{
    /// No connection has been made yet
    Camera_ADSPSENSOR_NOT_CONNECTED = 0,

    /// Connection established and is active
    Camera_ADSPSENSOR_CONNECTED,

    /// Connection broken
    Camera_ADSPSENSOR_CONNECTION_BROKEN
} Camera_ADSPSensor_Connection_Status;

/// This property defines a gyro sample as obtained from the ADSP
/// sensor sub-system
typedef struct
{
    // Index 0 -> X, Index 1 -> Y, Index 2 -> Z
    int32 nGyroData[3];

    // Timestamp value expressed in nanoseconds
    uint64  nTimeStamp;
} Camera_GyroSample;

/// This property defines a time interval as specified by the start
/// and end time values
typedef struct
{
    // Start time
    uint64 nStartTime;

    // End time
    uint64 nEndTime;
} Camera_TimeInterval;

typedef enum
{
    CAMERA_CHROMATIX_PARAMS = 0,
    CAMERA_CHROMATIX_VFE_COMMON_PARAMS,
    CAMERA_CHROMATIX_3A_PARAMS,
    CAMERA_CHROMATIX_ALL,
    CAMERA_CHROMATIX_MAX
}Camera_ChromatixType;

/// Define max number of CSI phy cores
typedef uint32 CsiphyCoreType;
#define CSIPHY_CORE_MAX 4

/// Define max number of IFE cores
typedef uint32 IfeCoreType;
#define IFE_CORE_MAX 8

typedef enum
{
    IFE_OUTPUT_PATH_RDI0 = 0,
    IFE_OUTPUT_PATH_RDI1,
    IFE_OUTPUT_PATH_RDI2,
    IFE_OUTPUT_PATH_RDI3,
    IFE_OUTPUT_PATH_MAX,
    IFE_OUTPUT_PATH_INVALID = 0X7FFFFFFF
}IfeOutputPathType;

typedef enum
{
    IFE_INTF_RDI0 = 0,
    IFE_INTF_RDI1,
    IFE_INTF_RDI2,
    IFE_INTF_RDI3,
    IFE_INTF_MAX
}IfeInterfaceType;


typedef enum
{
    AIS_BUFFER_UNITIALIZED = 0,       /**< Buffer entry is uninitialized */
    AIS_BUFFER_INITIALIZED,           /**< Buffer is initialized but not queued */
    AIS_IFE_OUTPUT_QUEUE,             /**< Buffer enqueued to IFE output queue  */
    AIS_IFE_INPUT_QUEUE,              /**< Buffer enqueued to IFE input queue */
    AIS_ISP_SCHEDULER_INPUT,          /**< Buffer enqueued to isp scheduler */
    AIS_ISP_SCHEDULER_INPUT_AVAIL,    /**< Buffer enqueued to isp scheduler */
    AIS_ISP_SCHEDULER_OUTPUT,         /**< Buffer enqueued to isp scheduler */
    AIS_ISP_SCHEDULER_OUTPUT_AVAIL,   /**< Buffer enqueued to isp scheduler */
    AIS_EXTERNAL_PP_QUEUE,            /**< Buffer is being processed by external library*/
    AIS_DELIVERY_QUEUE,               /**< Buffer is on queue waiting for user acquire */
    AIS_USER_ACQUIRED,                /**< Buffer acquired by the user */
} AisBufferStateType;

/**
 * AIS Buffer Definition
 */
typedef struct
{
    uint32 idx;   /**< index of buffer */

    qcarcam_buffer_t bufferInfo;
    qcarcam_color_fmt_t colorFmt;

    void* pMemHndl;     /**< memory handle */
    void* pVa;          /**< virtual addr */
    uint64 pDa;         /**< mapped device addr */

    uint32 size;        /**< overall size */
    uint32 flags;
    boolean isInternal; /**< user passed buffer or internally allocated */

    AisBufferStateType state; /**< current buffer state*/
}AisBuffer;

#endif /* __CAMERACOMMONTYPES_H__ */
