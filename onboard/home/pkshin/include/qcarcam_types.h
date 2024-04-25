#ifndef _QCARCAM_TYPES_H_
#define _QCARCAM_TYPES_H_

/* ===========================================================================
 * Copyright (c) 2016-2020 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 * @file qcarcam_types.h
 * @brief QCarCam API types - QTI Automotive Imaging System Proprietary API
 *
=========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
//                   DEFINITIONS AND DECLARATIONS
///////////////////////////////////////////////////////////////////////////////

/// @brief Maximum number of planes in buffer
#define QCARCAM_MAX_NUM_PLANES 3

#define QCARCAM_MAX_NUM_BUFFERS 20

#define QCARCAM_INPUT_NAME_LEN 80
#define QCARCAM_MAX_NUM_RESOLUTIONS 10
#define QCARCAM_MAX_NUM_COLOR_FMTS   5

#define QCARCAM_TIMEOUT_INIFINITE (-1ULL)
#define QCARCAM_TIMEOUT_NO_WAIT   (0)

#define QCARCAM_HDR_NUM_EXPOSURES 4

#define QCARCAM_MAX_GAMMA_TABLE 128

#define QCARCAM_MAX_PAYLOAD_SIZE 64
#define QCARCAM_MAX_VENDOR_PAYLOAD_SIZE QCARCAM_MAX_PAYLOAD_SIZE

///////////////////////////////////////////////////////////////////////////////
// Constant and Macros
///////////////////////////////////////////////////////////////////////////////
#define QCARCAM_COLOR_FMT(_pattern_, _bitdepth_, _pack_) \
    (((_pack_ & 0xff) << 24) | ((_bitdepth_ & 0xff) << 16) | (_pattern_ & 0xffff))

#define QCARCAM_COLOR_GET_PATTERN(_color_) \
    ((qcarcam_color_pattern_t)(_color_ & 0xffff))

#define QCARCAM_COLOR_GET_BITDEPTH(_color_) \
    ((qcarcam_color_bitdepth_t)((_color_ & 0xff0000) >> 16))

#define QCARCAM_COLOR_GET_PACK(_color_) \
    ((qcarcam_color_pack_t)((_color_ & 0xff000000) >> 24))


///////////////////////////////////////////////////////////////////////////////
// Typedefs
///////////////////////////////////////////////////////////////////////////////

/// @brief Handle type
typedef void* qcarcam_hndl_t;

/// @brief Return codes
typedef enum
{
    QCARCAM_RET_OK = 0,
    QCARCAM_RET_FAILED,
    QCARCAM_RET_BADPARAM,
    QCARCAM_RET_BADSTATE,
    QCARCAM_RET_NOMEM,
    QCARCAM_RET_UNSUPPORTED,
    QCARCAM_RET_TIMEOUT,
    QCARCAM_RET_BUSY,
} qcarcam_ret_t;

/// @brief Unique input descriptors. Mapped to physical HW in configuration file.
typedef enum
{
    QCARCAM_INPUT_TYPE_EXT_REAR      = 0,   ///< Rearview
    QCARCAM_INPUT_TYPE_EXT_FRONT     = 1,   ///< Exterior Front
    QCARCAM_INPUT_TYPE_EXT_LEFT      = 2,
    QCARCAM_INPUT_TYPE_EXT_RIGHT     = 3,
    QCARCAM_INPUT_TYPE_DRIVER        = 4,   ///< Driver monitor
    QCARCAM_INPUT_TYPE_LANE_WATCH    = 5,
    QCARCAM_INPUT_TYPE_DIGITAL_MEDIA = 6,
    QCARCAM_INPUT_TYPE_ANALOG_MEDIA  = 7,
    QCARCAM_INPUT_TYPE_GESTURE       = 8,
    QCARCAM_INPUT_TYPE_IRIS          = 9,
    QCARCAM_INPUT_TYPE_FINGERPRINT   = 10,
    QCARCAM_INPUT_TYPE_TUNER         = 11,
    QCARCAM_INPUT_TYPE_TESTPATTERN   = 255,
    QCARCAM_INPUT_TYPE_USER_DEFINED_START= 256,  ///< User defined IDs may start at this index
    QCARCAM_INPUT_MAX = 0x7FFFFFFF
} qcarcam_input_desc_t;

/// @brief Color type
typedef enum
{
    QCARCAM_RAW = 0,

    QCARCAM_YUV_YUYV = 0x100,
    QCARCAM_YUV_YVYU,
    QCARCAM_YUV_UYVY,
    QCARCAM_YUV_VYUY,

    QCARCAM_YUV_NV12,
    QCARCAM_YUV_NV21,

    QCARCAM_BAYER_GBRG = 0x200,
    QCARCAM_BAYER_GRBG,
    QCARCAM_BAYER_RGGB,
    QCARCAM_BAYER_BGGR,

    QCARCAM_RGB = 0x300,

}qcarcam_color_pattern_t;

/// @brief Bitdepth per color channel
typedef enum
{
    QCARCAM_BITDEPTH_8 = 8,
    QCARCAM_BITDEPTH_10 = 10,
    QCARCAM_BITDEPTH_12 = 12,
    QCARCAM_BITDEPTH_14 = 14,
    QCARCAM_BITDEPTH_16 = 16,
    QCARCAM_BITDEPTH_20 = 20
}qcarcam_color_bitdepth_t;

/// @brief Packing type
typedef enum
{
    QCARCAM_PACK_QTI = 0,
    QCARCAM_PACK_MIPI,
    QCARCAM_PACK_DPCM6,
    QCARCAM_PACK_DPCM8,
    QCARCAM_PACK_PLAIN8,
    QCARCAM_PACK_PLAIN16,
    QCARCAM_PACK_PLAIN32,
    QCARCAM_PACK_FOURCC
}qcarcam_color_pack_t;

/// @brief Color formats
typedef enum
{
    QCARCAM_FMT_MIPIRAW_8 = QCARCAM_COLOR_FMT(QCARCAM_RAW, QCARCAM_BITDEPTH_8, QCARCAM_PACK_MIPI), ///< MIPI packed RAW 8bit
    QCARCAM_FMT_MIPIRAW_10 = QCARCAM_COLOR_FMT(QCARCAM_RAW, QCARCAM_BITDEPTH_10, QCARCAM_PACK_MIPI),
    QCARCAM_FMT_MIPIRAW_12 = QCARCAM_COLOR_FMT(QCARCAM_RAW, QCARCAM_BITDEPTH_12, QCARCAM_PACK_MIPI),
    QCARCAM_FMT_MIPIRAW_14 = QCARCAM_COLOR_FMT(QCARCAM_RAW, QCARCAM_BITDEPTH_14, QCARCAM_PACK_MIPI),
    QCARCAM_FMT_MIPIRAW_16 = QCARCAM_COLOR_FMT(QCARCAM_RAW, QCARCAM_BITDEPTH_16, QCARCAM_PACK_MIPI),
    QCARCAM_FMT_MIPIRAW_20 = QCARCAM_COLOR_FMT(QCARCAM_RAW, QCARCAM_BITDEPTH_20, QCARCAM_PACK_MIPI),
    QCARCAM_FMT_PLAIN16_10 = QCARCAM_COLOR_FMT(QCARCAM_RAW, QCARCAM_BITDEPTH_10, QCARCAM_PACK_PLAIN16),
    QCARCAM_FMT_PLAIN16_12 = QCARCAM_COLOR_FMT(QCARCAM_RAW, QCARCAM_BITDEPTH_12, QCARCAM_PACK_PLAIN16),
    QCARCAM_FMT_PLAIN16_14 = QCARCAM_COLOR_FMT(QCARCAM_RAW, QCARCAM_BITDEPTH_14, QCARCAM_PACK_PLAIN16),
    QCARCAM_FMT_PLAIN16_16 = QCARCAM_COLOR_FMT(QCARCAM_RAW, QCARCAM_BITDEPTH_16, QCARCAM_PACK_PLAIN16),
    QCARCAM_FMT_PLAIN32_20 = QCARCAM_COLOR_FMT(QCARCAM_RAW, QCARCAM_BITDEPTH_20, QCARCAM_PACK_PLAIN32),
    QCARCAM_FMT_RGB_888 = QCARCAM_COLOR_FMT(QCARCAM_RGB, QCARCAM_BITDEPTH_8, QCARCAM_PACK_FOURCC),

    QCARCAM_FMT_UYVY_8 = QCARCAM_COLOR_FMT(QCARCAM_YUV_UYVY, QCARCAM_BITDEPTH_8, QCARCAM_PACK_FOURCC),
    QCARCAM_FMT_UYVY_10 = QCARCAM_COLOR_FMT(QCARCAM_YUV_UYVY, QCARCAM_BITDEPTH_10, QCARCAM_PACK_FOURCC),
    QCARCAM_FMT_UYVY_12 = QCARCAM_COLOR_FMT(QCARCAM_YUV_UYVY, QCARCAM_BITDEPTH_12, QCARCAM_PACK_FOURCC),
    QCARCAM_FMT_YUYV_8 = QCARCAM_COLOR_FMT(QCARCAM_YUV_YUYV, QCARCAM_BITDEPTH_8, QCARCAM_PACK_FOURCC),
    QCARCAM_FMT_YUYV_10 = QCARCAM_COLOR_FMT(QCARCAM_YUV_YUYV, QCARCAM_BITDEPTH_10, QCARCAM_PACK_FOURCC),
    QCARCAM_FMT_YUYV_12 = QCARCAM_COLOR_FMT(QCARCAM_YUV_YUYV, QCARCAM_BITDEPTH_12, QCARCAM_PACK_FOURCC),

    QCARCAM_FMT_NV12 = QCARCAM_COLOR_FMT(QCARCAM_YUV_NV12, QCARCAM_BITDEPTH_8, QCARCAM_PACK_FOURCC),
    QCARCAM_FMT_NV21 = QCARCAM_COLOR_FMT(QCARCAM_YUV_NV21, QCARCAM_BITDEPTH_8, QCARCAM_PACK_FOURCC),

    QCARCAM_FMT_MAX = 0x7FFFFFFF
} qcarcam_color_fmt_t;

///////////////////////////////////////////////////////////////////////////////
/// Expected p_value type for qcarcam_g_param/qcarcam_s_param
///
///        PARAMETER                      |       TYPE               |    NOTE
/// -----------------------------------------------------------------------------
/// QCARCAM_PARAM_EVENT_CB                |  ptr_value               | event callback function
/// QCARCAM_PARAM_EVENT_MASK              |  uint_value              | bitmask of qcarcam_event_t
/// QCARCAM_PARAM_COLOR_FMT               |  color_value             |
/// QCARCAM_PARAM_RESOLUTION              |  res_value               |
/// QCARCAM_PARAM_BRIGHTNESS              |  uint_value              |
/// QCARCAM_PARAM_CONTRAST                |  uint_value              |
/// QCARCAM_PARAM_MIRROR_H                |  uint_value              | 1 to enable
/// QCARCAM_PARAM_MIRROR_V                |  uint_value              | 1 to enable
/// QCARCAM_PARAM_FRAME_RATE              |  uint_value              |
/// QCARCAM_PARAM_VID_STD                 |  uint_value              |
/// QCARCAM_PARAM_CURRENT_VID_STD         |  uint_value              |
/// QCARCAM_PARAM_STATUS                  |  -                       |
/// QCARCAM_PARAM_LATENCY_MAX             |  uint_value              |
/// QCARCAM_PARAM_LATENCY_REDUCE_RATE     |  uint_value              |
/// QCARCAM_PARAM_PRIVATE_DATA            |  ptr_value               |
/// QCARCAM_PARAM_INJECTION_START         |  uint_value              |
/// QCARCAM_PARAM_EXPOSURE                |  exposure_config         |
/// QCARCAM_PARAM_HUE                     |  float_value             |
/// QCARCAM_PARAM_SATURATION              |  float_value             |
/// QCARCAM_PARAM_HDR_EXPOSURE            |  hdr_exposure_config     |
/// QCARCAM_PARAM_GAMMA                   |  gamma_config            |
/// QCARCAM_PARAM_OPMODE                  |  uint_value              | qcarcam_opmode_type
/// QCARCAM_PARAM_ISP_CTRLS               |  isp_ctrls               |
/// QCARCAM_PARAM_VENDOR                  |  vendor_param            |
/// QCARCAM_PARAM_INPUT_MODE              |  Input device mode       |
/// QCARCAM_PARAM_MASTER                  |  boolean                 | 1 to set and 0 to release
/// QCARCAM_PARAM_EVENT_CHANGE_SUBSCRIBE  |  uint_value              | Bitmask of qcarcam_param_t
/// QCARCAM_PARAM_EVENT_CHANGE_UNSUBSCRIBE|  uint_value              | Bitmask of qcarcam_param_t

/// @brief Parameter settings
typedef enum
{
    QCARCAM_PARAM_EVENT_CB = 0x1,       ///< Event callback function.
    QCARCAM_PARAM_EVENT_MASK,           ///< Mask of events
    QCARCAM_PARAM_COLOR_FMT,            ///< Output color format.
    QCARCAM_PARAM_RESOLUTION,           ///< Input dev resolution.
    QCARCAM_PARAM_BRIGHTNESS,
    QCARCAM_PARAM_CONTRAST,
    QCARCAM_PARAM_MIRROR_H,             ///< Horizontal mirror.
    QCARCAM_PARAM_MIRROR_V,             ///< Vertical mirror.
    QCARCAM_PARAM_FRAME_RATE,
    QCARCAM_PARAM_VID_STD,              ///< Video standard
    QCARCAM_PARAM_CURRENT_VID_STD,      ///< Video standard
    QCARCAM_PARAM_STATUS,               ///< Video lock status
    QCARCAM_PARAM_LATENCY_MAX,          ///< Max buffer latency in frame done Q
    QCARCAM_PARAM_LATENCY_REDUCE_RATE,  ///< Number of buffers to drop when max latency reached
    QCARCAM_PARAM_PRIVATE_DATA,
    QCARCAM_PARAM_INJECTION_START,
    QCARCAM_PARAM_EXPOSURE,             ///< exposure setting
    QCARCAM_PARAM_HUE,                  ///< hue setting
    QCARCAM_PARAM_SATURATION,           ///< saturation setting
    QCARCAM_PARAM_HDR_EXPOSURE,
    QCARCAM_PARAM_GAMMA,                ///< gamma setting
    QCARCAM_PARAM_OPMODE,               ///< operation mode
    QCARCAM_PARAM_ISP_CTRLS,            ///< ISP controls
    QCARCAM_PARAM_VENDOR,               ///< vendor param
    QCARCAM_PARAM_INPUT_MODE,           ///< Input device mode.
    QCARCAM_PARAM_MASTER,               ///< Set the client as master
    QCARCAM_PARAM_EVENT_CHANGE_SUBSCRIBE,      ///< Event subscription
    QCARCAM_PARAM_EVENT_CHANGE_UNSUBSCRIBE,    ///< Event unsubscribe
    QCARCAM_PARAM_NUM,                  ///< total number of valid parameters.

    QCARCAM_PARAM_MAX = 0x7FFFFFFF
} qcarcam_param_t;

typedef enum {
    QCARCAM_FIELD_UNKNOWN = 0,
    QCARCAM_FIELD_ODD,
    QCARCAM_FIELD_EVEN,
    QCARCAM_FIELD_ODD_EVEN,
    QCARCAM_FIELD_EVEN_ODD
} qcarcam_field_t;

typedef enum  {
    QCARCAM_EXPOSURE_AUTO,
    QCARCAM_EXPOSURE_MANUAL,
    QCARCAM_EXPOSURE_SEMI_AUTO,
    QCARCAM_EXPOSURE_LUX_IDX
} qcarcam_exposure_mode_t;

/// @brief Gamma parameter type
typedef enum  {
    QCARCAM_GAMMA_EXPONENT,         /// set gamma value in a float
    QCARCAM_GAMMA_KNEEPOINTS,       /// set array of gamma values
} qcarcam_gamma_type_t;

/// @brief Frame drop modes
typedef enum  {
    QCARCAM_KEEP_ALL_FRAMES,    ///< Max fps
    QCARCAM_KEEP_EVERY_2FRAMES, ///< 1/2 Max fps
    QCARCAM_KEEP_EVERY_3FRAMES, ///< 1/3 Max fps
    QCARCAM_KEEP_EVERY_4FRAMES, ///< 1/4 Max fps
    QCARCAM_DROP_ALL_FRAMES,    ///< 0 fps
    QCARCAM_FRAMEDROP_MANUAL    /// Set period/pattern manually
} qcarcam_frame_drop_mode_t;

/// @brief Input operation modes
typedef enum {
    QCARCAM_OPMODE_RAW_DUMP,
    QCARCAM_OPMODE_SHDR,
    QCARCAM_OPMODE_INJECT,
    QCARCAM_OPMODE_PAIRED_INPUT,
    QCARCAM_OPMODE_DEINTERLACE,
    QCARCAM_OPMODE_TRANSFORMER,

    QCARCAM_OPMODE_MAX
} qcarcam_opmode_type;

/// @brief Initialization parameters
typedef struct
{
    unsigned int flags;
    unsigned int version;
    const char* debug_tag;
    unsigned int reserved[4];
} qcarcam_init_t;

/// @brief Resolution
typedef struct
{
    unsigned int width;
    unsigned int height;
    float fps;
} qcarcam_res_t;

/// @brief Input Mode
typedef struct {
    qcarcam_color_fmt_t fmt;
    qcarcam_res_t res;
} qcarcam_mode_t;

/// @brief Input description flags
typedef enum
{
    QCARCAM_INPUT_FLAG_CONTENT_PROTECTED = 1 << 0,  ///< Content protection enabled
    QCARCAM_INPUT_FLAG_PAIRED            = 1 << 1   ///< Paired input stream
} qcarcam_input_flag_t;

/// @brief Input description
typedef struct
{
    qcarcam_input_desc_t desc;            ///< Unique input identifier

    char name[QCARCAM_INPUT_NAME_LEN];        ///< Input name. May be NULL
    char parent_name[QCARCAM_INPUT_NAME_LEN]; ///< Parent name. May be NULL

    qcarcam_res_t res[QCARCAM_MAX_NUM_RESOLUTIONS]; ///< Array of supported resolutions in pixels
    unsigned int num_res;                           ///< Number of supported resolutions

    qcarcam_color_fmt_t color_fmt[QCARCAM_MAX_NUM_COLOR_FMTS]; ///< Array of supported color formats
    unsigned int num_color_fmt;                                ///< Number of supported color formats

    unsigned int flags; ///< bitmask of qcarcam_input_flag_t
} qcarcam_input_t;

/// @brief Buffer plane definition
typedef struct
{
    unsigned int width;  ///< width in pixels
    unsigned int height; ///< height in pixels
    unsigned int stride; ///< stride in bytes
    unsigned int size;   ///< size in bytes
    void*        p_buf;
} qcarcam_plane_t;

/// @brief Buffer definition
typedef struct
{
    qcarcam_plane_t planes[QCARCAM_MAX_NUM_PLANES];
    unsigned int n_planes;
} qcarcam_buffer_t;

/// @brief Buffer flag bits
typedef enum
{
    QCARCAM_BUFFER_FLAG_SECURE  = 1 << 0,   ///< buffer is secured
    QCARCAM_BUFFER_FLAG_CACHE   = 1 << 1,   ///< buffer is cached
    QCARCAM_BUFFER_FLAG_OS_HNDL = 1 << 4,   ///< buffer pointer refers to an OS memory handle
} qcarcam_buffer_flag_t;

/// @brief Set buffer definition
typedef struct
{
    qcarcam_color_fmt_t color_fmt;

    qcarcam_buffer_t* buffers; ///< Array of buffers
    unsigned int n_buffers;    ///< Number of buffers in list

    unsigned int flags; ///< bitmask of qcarcam_buffer_flag_t
} qcarcam_buffers_t;

/// @brief Frame done payload
typedef struct
{
    int idx; ///< index into the qcarcam_buffers_t buffers table
    unsigned int flags;
    unsigned int seq_no;
    unsigned long long timestamp;        ///monotonic timestamp
    unsigned long long timestamp_system; ///system timestamp
    unsigned long long sof_qtimestamp;   //sof qtimer timestamp
    qcarcam_field_t field_type;
} qcarcam_frame_info_t;

/// @brief structure to hold vendor param
typedef struct
{
    unsigned int data[QCARCAM_MAX_VENDOR_PAYLOAD_SIZE];
}qcarcam_vendor_param_t;


/// @brief Event type definition
typedef enum
{
    QCARCAM_EVENT_FRAME_READY = 1 << 0,  ///< Frame ready to be dequeued using get_frame API
    QCARCAM_EVENT_INPUT_SIGNAL = 1 << 1, ///< Payload will contain qcarcam_input_signal_t
    QCARCAM_EVENT_ERROR = 1 << 2,        ///< Error event
    QCARCAM_EVENT_VENDOR = 1 << 3,       ///< Vendor event
    QCARCAM_PROPERTY_NOTIFY = 1<< 4,     ///< Property events
} qcarcam_event_t;

/// @brief Input Event payload definition
typedef enum
{
    QCARCAM_INPUT_SIGNAL_VALID = 0,
    QCARCAM_INPUT_SIGNAL_LOST
} qcarcam_input_signal_t;

/// @brief Error event payload definition
typedef enum
{
    QCARCAM_FATAL_ERROR = 0,
    QCARCAM_CONN_ERROR,
    QCARCAM_IFE_OVERFLOW_ERROR,
    QCARCAM_FRAMESYNC_ERROR
} qcarcam_event_error_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Union to hold possible values to p_payload in qcarcam_event_cb_t
///
///        EVENT ID                      |       TYPE               |    NOTE
/// ---------------------------------------------------------------------------
/// QCARCAM_EVENT_FRAME_READY            |                          | no payload
/// QCARCAM_EVENT_INPUT_SIGNAL           | uint_payload             | flags
/// QCARCAM_EVENT_VENDOR                 | uint array               |
///
///////////////////////////////////////////////////////////////////////////////
typedef union
{
    unsigned int uint_payload; ///< unsigned int type
    unsigned int array[QCARCAM_MAX_PAYLOAD_SIZE]; ///< vendor event payload
} qcarcam_event_payload_t;

/// @brief structure to hold manual exposure parameters
typedef struct
{
    qcarcam_exposure_mode_t exposure_mode_type;
    float exposure_time;   ///< time in ms
    float gain;            ///< 1.0 to Max supported in sensor
    float target;          ///< for SEMI_AUTO mode
    float lux_index;       ///< for LUX_IDX mode
    unsigned int reserved[4];    ///< extra params that may be needed
}qcarcam_exposure_config_t;

/// @brief structure to hold manual exposure parameters
typedef struct
{
    qcarcam_exposure_mode_t exposure_mode_type;
    unsigned int hdr_mode;
    unsigned int num_exposures;
    float exposure_time[QCARCAM_HDR_NUM_EXPOSURES];  ///< time in ms
    float exposure_ratio[QCARCAM_HDR_NUM_EXPOSURES];
    float gain[QCARCAM_HDR_NUM_EXPOSURES];           ///< 1.0 to Max supported in sensor
    float target;           ///< for SEMI_AUTO mode
    float lux_index;        ///< for LUX_IDX mode
}qcarcam_hdr_exposure_config_t;

/// @brief structure to hold manual gamma parameters
typedef struct
{
    qcarcam_gamma_type_t config_type;  /// gamma configure mode
    union {
        float f_value;
        struct {
            unsigned int length;
            unsigned int *p_value;
        } table;
    } gamma;
}qcarcam_gamma_config_t;

/// @brief structure to hold frame rate parameters
typedef struct
{
    qcarcam_frame_drop_mode_t frame_drop_mode;
    unsigned char frame_drop_period;   ///< only effective when frame_drop_mode = QCARCAM_FRAMEDROP_MANUAL, max value 31
    unsigned int frame_drop_pattern;   ///< only effective when frame_drop_mode = QCARCAM_FRAMEDROP_MANUAL
}qcarcam_frame_rate_t;

typedef enum
{
    QCARCAM_CONTROL_AE_LOCK = 0x0,
    QCARCAM_CONTROL_AE_MODE,
    QCARCAM_CONTROL_AWB_LOCK,
    QCARCAM_CONTROL_AWB_MODE,
    QCARCAM_CONTROL_EFFECT_MODE,
    QCARCAM_CONTROL_MODE,
    QCARCAM_CONTROL_SCENE_MODE,
    QCARCAM_CONTROL_AE_ANTIBANDING_MODE,
    QCARCAM_CONTROL_DUMP_FRAME,

    QCARCAM_ISP_PARAM_NUM /// total number of valid parameters.
}qcarcam_isp_param_t;

// CONTROL_AE_LOCK
typedef enum qcarcam_ctrl_ae_lock {
    QCARCAM_CONTROL_AE_LOCK_OFF,
    QCARCAM_CONTROL_AE_LOCK_ON,
} qcarcam_ctrl_ae_lock_t;

// CONTROL_AE_MODE
typedef enum qcarcam_ctrl_ae_mode {
    QCARCAM_CONTROL_AE_MODE_MANUAL,
    QCARCAM_CONTROL_AE_MODE_AUTO,
} qcarcam_ctrl_ae_mode_t;

// CONTROL_AWB_LOCK
typedef enum qcarcam_ctrl_awb_lock {
    QCARCAM_CONTROL_AWB_LOCK_OFF,
    QCARCAM_CONTROL_AWB_LOCK_ON,
} qcarcam_ctrl_awb_lock_t;

// CONTROL_AWB_MODE
typedef enum qcarcam_ctrl_awb_mode {
    QCARCAM_CONTROL_AWB_MODE_OFF,
    QCARCAM_CONTROL_AWB_MODE_AUTO,
    QCARCAM_CONTROL_AWB_MODE_INCANDESCENT,
    QCARCAM_CONTROL_AWB_MODE_FLUORESCENT,
    QCARCAM_CONTROL_AWB_MODE_WARM_FLUORESCENT,
    QCARCAM_CONTROL_AWB_MODE_DAYLIGHT,
    QCARCAM_CONTROL_AWB_MODE_CLOUDY_DAYLIGHT,
    QCARCAM_CONTROL_AWB_MODE_TWILIGHT,
    QCARCAM_CONTROL_AWB_MODE_SHADE,
} qcarcam_ctrl_awb_mode_t;

// CONTROL_EFFECT_MODE
typedef enum qcarcam_ctrl_control_effect_mode {
    QCARCAM_CONTROL_EFFECT_MODE_OFF,
    QCARCAM_CONTROL_EFFECT_MODE_MONO,
    QCARCAM_CONTROL_EFFECT_MODE_NEGATIVE,
    QCARCAM_CONTROL_EFFECT_MODE_SOLARIZE,
    QCARCAM_CONTROL_EFFECT_MODE_SEPIA,
    QCARCAM_CONTROL_EFFECT_MODE_POSTERIZE,
    QCARCAM_CONTROL_EFFECT_MODE_WHITEBOARD,
    QCARCAM_CONTROL_EFFECT_MODE_BLACKBOARD,
    QCARCAM_CONTROL_EFFECT_MODE_AQUA,
} qcarcam_ctrl_control_effect_mode_t;

// CONTROL_MODE
typedef enum qcarcam_ctrl_control_mode {
    QCARCAM_CONTROL_MODE_OFF,
    QCARCAM_CONTROL_MODE_AUTO,
    QCARCAM_CONTROL_MODE_USE_SCENE_MODE,
    QCARCAM_CONTROL_MODE_OFF_KEEP_STATE,
} qcarcam_ctrl_control_mode_t;

// CONTROL_SCENE_MODE
typedef enum qcarcam_ctrl_control_scene_mode {
    QCARCAM_CONTROL_SCENE_MODE_DISABLED                         = 0,
    QCARCAM_CONTROL_SCENE_MODE_FACE_PRIORITY,
    QCARCAM_CONTROL_SCENE_MODE_ACTION,
    QCARCAM_CONTROL_SCENE_MODE_PORTRAIT,
    QCARCAM_CONTROL_SCENE_MODE_LANDSCAPE,
    QCARCAM_CONTROL_SCENE_MODE_NIGHT,
    QCARCAM_CONTROL_SCENE_MODE_NIGHT_PORTRAIT,
    QCARCAM_CONTROL_SCENE_MODE_THEATRE,
    QCARCAM_CONTROL_SCENE_MODE_BEACH,
    QCARCAM_CONTROL_SCENE_MODE_SNOW,
    QCARCAM_CONTROL_SCENE_MODE_SUNSET,
    QCARCAM_CONTROL_SCENE_MODE_STEADYPHOTO,
    QCARCAM_CONTROL_SCENE_MODE_FIREWORKS,
    QCARCAM_CONTROL_SCENE_MODE_SPORTS,
    QCARCAM_CONTROL_SCENE_MODE_PARTY,
    QCARCAM_CONTROL_SCENE_MODE_CANDLELIGHT,
    QCARCAM_CONTROL_SCENE_MODE_BARCODE,
    QCARCAM_CONTROL_SCENE_MODE_HIGH_SPEED_VIDEO,
    QCARCAM_CONTROL_SCENE_MODE_HDR,
    QCARCAM_CONTROL_SCENE_MODE_FACE_PRIORITY_LOW_LIGHT,
    QCARCAM_CONTROL_SCENE_MODE_DEVICE_CUSTOM_START              = 100,
    QCARCAM_CONTROL_SCENE_MODE_DEVICE_CUSTOM_END                = 127,
} qcarcam_ctrl_control_scene_mode_t;

// CONTROL_AE_ANTIBANDING_MODE
typedef enum qcarcam_ctrl_ae_antibanding_mode {
    QCARCAM_CONTROL_AE_ANTIBANDING_MODE_OFF,
    QCARCAM_CONTROL_AE_ANTIBANDING_MODE_50HZ,
    QCARCAM_CONTROL_AE_ANTIBANDING_MODE_60HZ,
    QCARCAM_CONTROL_AE_ANTIBANDING_MODE_AUTO,
} qcarcam_ctrl_ae_antibanding_mode_t;

typedef struct
{
    unsigned long long int param_mask;  ///< Mask to indicate setting qcarcam_isp_param_t
    qcarcam_ctrl_ae_lock_t ae_lock;
    qcarcam_ctrl_ae_mode_t ae_mode;
    qcarcam_ctrl_awb_lock_t awb_lock;
    qcarcam_ctrl_awb_mode_t awb_mode;
    qcarcam_ctrl_control_effect_mode_t effect_mode;
    qcarcam_ctrl_control_mode_t ctrl_mode;
    qcarcam_ctrl_control_scene_mode_t scene_mode;
    qcarcam_ctrl_ae_antibanding_mode_t ae_antibanding_mode;
}qcarcam_param_isp_ctrls_t;

/// @brief Union to hold possible values to p_value in qcarcam_s_param and qcarcam_g_param
typedef union
{
    void* ptr_value;                                 ///< pointer type
    float float_value;                               ///< float type
    unsigned int uint_value;                         ///< unsigned int type
    qcarcam_res_t res_value;                         ///< resolution type
    qcarcam_color_fmt_t color_value;                 ///< color type
    qcarcam_exposure_config_t exposure_config;       ///< Exposure settings
    qcarcam_hdr_exposure_config_t hdr_exposure_config; ///< HDR Exposure settings
    qcarcam_gamma_config_t gamma_config;             ///< Gamma settings
    qcarcam_frame_rate_t frame_rate_config;          ///< Frame rate settings
    qcarcam_param_isp_ctrls_t isp_ctrls;             ///< Used to control isp sensor settings
    qcarcam_vendor_param_t vendor_param;             ///< vendor param
    unsigned long long uint64_value;                 ///< unsigned uint64 value
    int arr_padding[QCARCAM_MAX_PAYLOAD_SIZE];       ///< Used to ensure union size won't change
}qcarcam_param_value_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Event callback function definition
///
/// @param hndl       Handle of input that was opened
/// @param event_id   Event ID
/// @param p_payload  Payload particular to that event. Refer to table above for payload type.
///////////////////////////////////////////////////////////////////////////////
typedef void (*qcarcam_event_cb_t) (qcarcam_hndl_t hndl, qcarcam_event_t event_id, qcarcam_event_payload_t* p_payload);

#ifdef __cplusplus
}
#endif

#endif /* _QCARCAM_TYPES_H_ */

