/* ===========================================================================
 * Copyright (c) 2016-2020 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
=========================================================================== */

#ifndef _TEST_UTIL_COMMON_H
#define _TEST_UTIL_COMMON_H

#include "qcarcam.h"
#include "CameraOSServices.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DE_INTERLACE_HEIGHT 480
#define SW_WEAVE_30FPS 1
#define SW_BOB_60FPS 2
#define SW_BOB_30FPS 3

// Thread priority for threads created by qcarcam_test
#define QCARCAM_THRD_PRIO CAMERA_THREAD_PRIO_DEFAULT

#if defined(__INTEGRITY)
// Object number 10 is defined in qcarcam_test_app INT file
#define QCARCAM_OBJ_NUM   10
#endif

enum
{
    TEST_CUR_BUFFER = 0 ,
    TEST_PREV_BUFFER = 1,
    TEST_DISPLAY_BUFFER_NUM = 2
};

/// @brief Trigger types
typedef enum
{
    TESTUTIL_GPIO_INTERRUPT_TRIGGER_DISABLE = 0,
    TESTUTIL_GPIO_INTERRUPT_TRIGGER_HIGH    = 1,
    TESTUTIL_GPIO_INTERRUPT_TRIGGER_LOW     = 2,
    TESTUTIL_GPIO_INTERRUPT_TRIGGER_RISING  = 3,
    TESTUTIL_GPIO_INTERRUPT_TRIGGER_FALLING = 4,
    TESTUTIL_GPIO_INTERRUPT_TRIGGER_EDGE    = 5
} test_util_trigger_type_t;

/// @brief  GPIO interrupt mode types
typedef enum
{
    TESTUTIL_GPIO_MODE_VISIBILITY,
    TESTUTIL_GPIO_MODE_PLAYPAUSE,
    TESTUTIL_GPIO_MODE_STARTSTOP
} test_util_gpio_interrupt_mode_t;

/// @brief Visiblity types
typedef enum
{
    TESTUTIL_HIDE = 0,
    TESTUTIL_VISIBLE = 1
} test_util_visibility_t;

/// @brief Color formats
typedef enum
{
    TESTUTIL_FMT_MIPIRAW_8,
    TESTUTIL_FMT_RGB_565,
    TESTUTIL_FMT_RGB_888,
    TESTUTIL_FMT_RGBX_8888,
    TESTUTIL_FMT_UYVY_8,
    TESTUTIL_FMT_NV12,

    TESTUTIL_FMT_MAX = 0x7FFFFFFF
} test_util_color_fmt_t;

typedef enum
{
    TEST_UTIL_DISPLAY_ID,
    TEST_UTIL_PIPELINE_ID,
    TEST_UTIL_WINDOW_SIZE,
    TEST_UTIL_WINDOW_POS,
    TEST_UTIL_WINDOW_SOURCE_SIZE,
    TEST_UTIL_WINDOW_SOURCE_POS,
    TEST_UTIL_ZORDER,
    TEST_UTIL_VISIBILITY,
    TEST_UTIL_BUFFER_SIZE,
    TEST_UTIL_IS_DISPLAYABLE,
    TEST_UTIL_FORMAT,
    TEST_UTIL_N_BUFFER_DISPLAY
} test_util_params_t;

typedef struct
{
    unsigned int buf_idx;
    unsigned char *p_va;
    unsigned int stride;
} test_util_buf_ptr_t;

typedef struct
{
    int disable_display;
    int enable_c2d;
    int enable_di;
    int enable_gpio_config;
} test_util_ctxt_params_t;

typedef struct
{
    uint32_t irq;
    void (*cb_func)(void);
} test_util_intr_thrd_args_t;

/// @brief Window properties
/// Parameters used to identify and define properties given to windows to be displayed.
typedef struct
{
    char debug_name[64];            ///< Debug name for window
    int display_id;                 ///< Specific display output ID
    int pipeline_id;                ///< Specific pipeline ID
    float window_size[2];           ///< Output window size [width, height]
    float window_pos[2];            ///< Output window position [x, y]
    float window_source_size[2];    ///< Source window size [width, height]
    float window_source_pos[2];     ///< Source window position [x, y]
    int zorder;                     ///< Window position in Z plane
    int visibility;                 ///< Window visibility (0 - not visible, else visible)

    int buffer_size[2];

    int is_offscreen;               ///< Is window to be displayed or offscreen
    test_util_color_fmt_t format;   ///< Displayable format if need to convert
    int n_buffers_display;          ///< Number of buffers if we need to convert to displayable format

    unsigned int flags;             ///< input flags
} test_util_window_param_t;

typedef struct
{
    unsigned long long frame_generate_time[TEST_DISPLAY_BUFFER_NUM];
    unsigned long long buf_commit_time[TEST_DISPLAY_BUFFER_NUM];
    unsigned long long buf_rel_time[TEST_DISPLAY_BUFFER_NUM];
    int bprint;
} test_util_diag_t;

#ifdef ENABLE_INJECTION_SUPPORT
typedef struct
{
    char filename[256];

    int buffer_size[2];
    int stride;             ///< Stride of input buffer in bytes
    int n_buffers;          ///< Number of buffers for injection

    qcarcam_color_pattern_t framedrop_pattern;
    qcarcam_color_bitdepth_t bitdepth;
    qcarcam_color_pack_t pack;
} test_util_injection_param_t;
#endif

typedef struct
{
    int width;          ///< Output buffer width
    int height;         ///< Output buffer height
    int stride;
    int n_buffers;      ///< Number of buffers for output of ISP

    qcarcam_frame_rate_t frame_rate_config;
    qcarcam_color_fmt_t format;
} test_util_output_param_t;

typedef struct
{
    qcarcam_input_desc_t qcarcam_input_id;  ///< Unique input descriptor.
    int use_event_callback;                 ///< Specifies if frames from input are get in a callback
    int frame_timeout;                      ///< Specifies timeout for qcarcam_get_frame
    qcarcam_opmode_type op_mode;            ///< Specifies operation mode
    uint64 subscribe_parameter_change;      ///< Specifies input events/settings to listen if any change
    uint32 delay_time;                      ///< Specifies if buffer delay, if yes, specifies delay time(ms)
} test_util_properties_t;

typedef struct
{
    float exposure_time;      ///< Exposure time.
    float gain;               ///< Gain
    int manual_exp;           ///< Enable manual exposure
} test_util_exp_properties_t;

/// @brief XML inputs
/// Defines general parameters for each input that are parsed from XML config files
typedef struct
{
    /*QCarCam properties*/
    test_util_properties_t properties;

    /*output buffer settings*/
    test_util_output_param_t output_params;

    /*display settings*/
    test_util_window_param_t window_params;     ///< Properties for window to be displayed

#ifdef ENABLE_INJECTION_SUPPORT
    /*injection params*/
    test_util_injection_param_t inject_params;
#endif

    /* Exposure params */
    test_util_exp_properties_t exp_params;

} test_util_xml_input_t;


#ifdef __cplusplus
}
#endif

#endif /* _TEST_UTIL_COMMON_H */
