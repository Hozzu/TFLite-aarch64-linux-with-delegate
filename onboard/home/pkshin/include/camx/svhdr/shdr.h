/****************************************************************************
* Copyright (c) 2016-2019 Qualcomm Technologies, Inc.                       *
* All Rights Reserved.                                                      *
* Confidential and Proprietary - Qualcomm Technologies, Inc.                *
****************************************************************************/

#ifndef __SHDR_H__
#define __SHDR_H__

#include <stdbool.h>
#include <stdint.h>

typedef unsigned short ushort;
#ifdef __cplusplus
extern "C" {
#endif

#if defined (_WIN32) || defined(__QNXNTO__) || defined(_PC) || defined(__AGL__)
#define ALOGE printf
#define __func__ __FUNCTION__
#endif
/***  constants and macros   ***/
#define MAX_EXP_ENTRIES 4
#define MAX_INPUT_HDR_FRAMES 4
#define MAX_OUTPUT_HDR_FRAMES 1
#define MAX_SHDR_BG_STATS_SIZE 1024
#define MAX_SHDR_BHIST_STATS_SIZE 256
#define STATS_BIT_DEPTH_BIN_HIST1 (10)
#define STATS_BIT_DEPTH_BIN_HIST2 (12)
#define MAX_SHDR_VHIST1_STATS_NONUNIFROM_SIZE (0x1 << STATS_BIT_DEPTH_BIN_HIST1)
#define MAX_SHDR_VHIST2_STATS_NONUNIFROM_SIZE (0x1 << STATS_BIT_DEPTH_BIN_HIST2)

#define MESH_X (12)
#define MESH_Y (8)
#define MESH_X_plus1 (MESH_X + 1)
#define MESH_Y_plus1 (MESH_Y + 1)
#define MESH_X_plus3 (MESH_X + 3)
#define MESH_Y_plus3 (MESH_Y + 3)

/**** shdr supported sensor layout formats ***/
typedef enum {
  SHDR_TWO_SEPARATE_FRAMES = 0,
  // One composite Frame
  SHDR_INTERLEAVED_WITH_STATUS = 1,
  SHDR_INTERLEAVED_NO_STATUS = 2,
  SHDR_INTERLEAVED_NO_STATUS_2LINES = 3,
  SHDR_INTERLEAVED_NO_STATUS_2LINES_NO_BLANK = 4,
  SHDR_INTERLEAVED_NO_STATUS_1LINES_NO_BLANK = 5,

  // multi-frame
  SHDR_THREE_SEPARATE_FRAMES = 6,
  SHDR_FOUR_SEPARATE_FRAMES = 7,
  SHDR_FUSED_FRAME = 8

} shdr_sensor_layout_t;

/**** shdr supported bayer input formats ***/
typedef enum {
  SHDR_BAYER_INPUT_PLAIN16 = 0,
  SHDR_BAYER_INPUT_MIPI10 = 1,
  SHDR_BAYER_INPUT_MIPI12 = 2,
  SHDR_BAYER_INPUT_MAX = 0xFF
} shdr_input_bayer_format_t;

/**** shdr supported bayer output formats ***/
typedef enum {
  SHDR_BAYER_OUTPUT_PLAIN16 = 0,
  SHDR_BAYER_OUTPUT_MIPI10 = 1,
  SHDR_BAYER_OUTPUT_MIPI12 = 2,
  SHDR_BAYER_OUTPUT_MIPI14 = 3,
  SHDR_BAYER_OUTPUT_MAX = 0xFF
} shdr_output_bayer_format_t;

/**** shdr supported bayer pattern ***/
typedef enum {
  SHDR_BAYER_GRBG = 0,
  SHDR_BAYER_RGGB = 1,
  SHDR_BAYER_BGGR = 2,
  SHDR_BAYER_GBRG = 3,
  SHDR_BAYER_MAX = 0xFF
} shdr_bayer_pattern_t;

/**** shdr performance voting levels for DCVS ***/
typedef enum {
  SHDR_PERF_HINT_LOW = 0,
  SHDR_PERF_HINT_NORMAL = 1,
  SHDR_PERF_HINT_HIGH = 2
} shdr_perf_hint_t;

/**** companding method, used by the specific sensor and sensor mode ***/
typedef enum {
    NO_COMPANDING                     = 0,
    LOGARITHMIC_LUT_20B_TO_12B = 1,
    PWL_OPTION_A              = 2
} sensor_companding_t;

/***  shdr buffer structure  ***/
typedef struct {
  int32_t width;
  int32_t height;
  int32_t stride;
  uint32_t buf_size;
  uint32_t offset;
  uint8_t *buf;
  int32_t fd;
} shdr_buffer_t;

typedef struct {
  float target_ratio;
  float gtm;
  float ltm_max_gain;
  float ltm_comp_target;
  float ltm_inverse;
} tm_tuning_table_t;

typedef struct {
  int ADC_BIT_DEPTH;
  int start_offset;
  int SVHDR_ADDITIONAL_LATENCY_Bayer_Proc;
  float EXPOSURE_RATIO_REAL[MAX_EXP_ENTRIES];
  float EXPOSURE_RATIO_SENSOR[MAX_EXP_ENTRIES];
  int TM_OUT_BIT_DEPTH;
  float BLACK_LEVEL;
  int HDR_MAX_WEIGHT;
  float TM_GAIN;

  int ma_en;  // motion adaption
  int debug_mode_en;
  int debug_pair;
  float ma_luma_th1_exp[MAX_INPUT_HDR_FRAMES];
  float ma_luma_th2_exp[MAX_INPUT_HDR_FRAMES];
  float ma_diff_th1_exp[MAX_INPUT_HDR_FRAMES];
  float ma_diff_th2_exp[MAX_INPUT_HDR_FRAMES];

} shdr_tuning_t;

typedef struct {
  int frame_id;
  int num_grid_w;
  int num_grid_h;
  float y_avg[MESH_X_plus1 * MESH_Y_plus1];
  float r_avg[MESH_X_plus1 * MESH_Y_plus1];
  float b_avg[MESH_X_plus1 * MESH_Y_plus1];
  uint16_t bin[MAX_SHDR_BHIST_STATS_SIZE];
  uint16_t
      bin_vhist1[MAX_SHDR_VHIST1_STATS_NONUNIFROM_SIZE];  // non-uniform hist,
                                                          // folow mobile
  uint16_t
      bin_vhist2[MAX_SHDR_VHIST2_STATS_NONUNIFROM_SIZE];  // non-uniform, iot
} shdr_stats_info_t;

/****  shdr process input params structure ***/
typedef struct {
  int32_t input_buf_count;
  int32_t *input_fd_list;
  float pregain_gb;
  float pregain_gr;
  int32_t offset[MAX_EXP_ENTRIES];
  int32_t num_exposure;
  shdr_tuning_t *tuning;
  shdr_stats_info_t *stats_info;
  uint8_t Dump_frame;
} shdr_input_param_t;

/**** shdr process output params ***/
typedef struct {
  int32_t data_size_3a;
  void *buf_3a;
  void *hdr_buf;
} shdr_output_params_t;

/*** shdr init parameters   ***/
typedef struct {
  shdr_sensor_layout_t sensor_layout;
  shdr_input_bayer_format_t input_bayer_format;
  shdr_output_bayer_format_t output_bayer_format;
  shdr_bayer_pattern_t bayer_pattern;  // GRBG, RGGB, BGGR, GBRG
  shdr_tuning_t tuning;
  int32_t input_buf_count;
  int32_t output_buf_count;
  shdr_buffer_t *input_buf;
  shdr_buffer_t *output_buf;
  shdr_perf_hint_t perf_hint;
  uint32_t enable_deinterlace;
  int32_t gpu_ltm_en;
  int32_t
      num_gpu_passes;  // Use 1 for best power(needs latest OpenCL driver: use
                       // build
                       // MSM8976.LA.1.0-00265-MSM8976.64.PM8952.SLD.GWL.INT-1
                       // or later), 2 for best performance.
  int32_t num_exposure;
  int32_t offset[MAX_EXP_ENTRIES];
  uint32_t src_stride;
  uint32_t dst_stride;

  tm_tuning_table_t *tm_tuning_table;
  uint32_t tm_tuning_table_size;
  sensor_companding_t companding;
} shdr_init_config_t;

/**** return status from shdr library interface ***/
typedef enum {
  SHDR_ERR_INVALID_INPUT = -3,
  SHDR_ERR_NOT_SUPPORTED = -2,
  SHDR_ERR_NO_MEMORY = -1,
  SHDR_FAIL = 0,
  SHDR_SUCCESS = 1,
  SHDR_ALREADY_MAPPED = 2,
  SHDR_STATUS_MAX = 0xFF
} shdr_status_t;

/**** shdr capabilities, to be filled by shdr lib ***/
typedef struct {
  float api_version;
  float lib_version;
  int32_t process_time; /* library processing time in ms */
  uint32_t width;
  uint32_t height;
  uint32_t row_pitch; /* required for ION buffer allocation*/
  uint32_t buf_padding;
} shdr_caps_t;

/**** shdr de-interleave input params ****/
typedef struct {
  int32_t width;
  /* to be filled */

} shdr_deinterleave_info_t;

/******************************************************/
/** shdr_lib_init
 *    @lib_handle: shdr library handle
 *    @params: configuration params for shdr
 *
 * Initializes shdr library
 *
 * return: SHDR_SUCCESS on success, SHDR_FAIL when fails
 **/
int32_t shdr_lib_init(void **handle, shdr_init_config_t *params);

/** shdr_lib_get_caps
 *    @caps: query capabilities data
 *
 * shdr lib fills it's capability and requirements
 *
 * return: SHDR_SUCCESS on success, SHDR_FAIL when fails
 **/
int32_t shdr_lib_get_caps(shdr_caps_t *caps);

/** shdr_lib_deinit
 *    @handle: shdr lib handle
 *
 * Deinitializes shdr module
 *
 * return: nothing
 **/
void shdr_lib_deinit(void *handle);

/** shdr_map_buffer
 *    @handle: shdr library handle
 *    @buffer: buffer descriptor
 *    @input: true if buffer is input and false if buffer is output
 *
 * Maps buffer
 *
 * return: SHDR_SUCCESS on success, SHDR_FAIL when fails
 **/
int32_t shdr_map_buffer(void *handle, shdr_buffer_t *buffer, bool input);

/** shdr_unmap_buffer
 *    @handle: shdr library handle
 *    @fd: buffer fd
 *    @input: true if buffer is input and false if buffer is output
 *
 * Unmaps buffer
 *
 * return: SHDR_SUCCESS on success, SHDR_FAIL when fails
 **/
int32_t shdr_unmap_buffer(void *handle, int32_t fd, bool input);

/** shdr_lib_process
 *	 @shdr_handle: handle to shdr lib
 *   @shdr_input_param_t: pointer to shdr input params
 *   @output_fd: fd handle to output frame
 *   @shdr_out_params: output pointer to shdr 3a stats
 *   @ user_data: any client data to be passed back from
 shdr_completion_callback
 *   @shdr_completion_callback: function pointer to be called back upon GPU shdr
 processing
 *   completion for non-blocking shdr_lib_process support use this for best
 performance/watt
 *   setting shdr_completion_callback to NULL will cause shdr_lib_process to
 block until GPU
 *   shdr processing is complete.

 * main shdr function to process image data
 *
 * return: SHDR_SUCCESS on success, SHDR_FAIL when fails
 **/
int32_t shdr_lib_process(
    void *handle, shdr_input_param_t *input_param, int32_t output_fd,
    shdr_output_params_t *buf_3a,
    void (*shdr_completion_callback)(
        void *handle, shdr_input_param_t *input_param, int32_t output_fd,
        shdr_output_params_t *buf_3a, void *user_data),
    void (*aec_stats_ready_callback)(shdr_stats_info_t *stats, void *user_data),
    void *user_data);

/** shdr_lib_util_frame_deinterlace
 *    @input: pointer to input buffer params
 @output: pointer to output buffer params
 @info : info on how the data is orgainzed in the frame
 *
 * de-interlace long and short exposure frames
 *
 * return: SHDR_SUCCESS on success, SHDR_FAIL when fails
 **/
int32_t shdr_lib_util_frame_deinterlace(shdr_buffer_t input,
                                        shdr_buffer_t output[2],
                                        shdr_deinterleave_info_t info);

/** shdr_lib_get_version
 *
 * Returns lib version
 *
 * return: lib version
 **/
const char *shdr_lib_get_version();

#ifdef __cplusplus
}
#endif

#endif /* __SHDR_H__ */
