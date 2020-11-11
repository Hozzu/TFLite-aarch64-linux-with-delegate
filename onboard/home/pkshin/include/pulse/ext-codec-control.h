#ifndef foopulseextcodeccontrolhfoo
#define foopulseextcodeccontrolhfoo

/***
Ext-codec-control.h -- PulseAudio Client API of Ext-codec-control headerfiles
Including message structures and API declarifications.

Copyright (c) 2016, The Linux Foundation. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
***/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdarg.h>

#include <pulse/context.h>
#include <pulse/format.h>
#include <pulse/version.h>

/** \file
 *
 * Routines for controlling module-codec-control
 */

PA_C_DECL_BEGIN

typedef struct codec_control_set_pp_volume {
    const char *media_role;
    uint8_t playback;
    uint32_t gain;
}codec_control_set_pp_volume_t;

typedef struct codec_control_set_pp_mute {
    const char *media_role;
    uint8_t playback;
    uint8_t mute;
}codec_control_set_pp_mute_t;

typedef struct codec_control_set_pp_fade {
    const char *media_role;
    uint8_t playback;
    int32_t fade;
}codec_control_set_pp_fade_t;

typedef struct codec_control_set_pp_balance {
    const char *media_role;
    uint8_t playback;
    int32_t balance;
}codec_control_set_pp_balance_t;

typedef enum
{
    PP_FILTER_TYPE_INVALID = 0,
    PP_FILTER_TYPE_BASS,
    PP_FILTER_TYPE_MID,
    PP_FILTER_TYPE_TREBLE,
    PP_FILTER_TYPE_MAX
} codec_control_pp_filter_type_t;

typedef struct codec_control_set_pp_bmt {
    const char *media_role;
    uint8_t playback;

    codec_control_pp_filter_type_t filter_type; /**< Requested filter type */
    uint8_t enable_flag; /**< Enable flag. 0 - Disable, 1 - Enable */
    int32_t value; /**< Requested value to be set */
}codec_control_set_pp_bmt_t;

typedef struct codec_control_pp_eq_subband
{
    uint32_t band_idx; /**< Band index. Supported value: 0 to (num_bands - 1) */
    uint32_t center_freq; /**< Filter band center frequency in millihertz */
    int32_t band_level; /**< Filter band gain in millibels */
} codec_control_pp_eq_subband_t;

typedef struct codec_control_set_pp_eq {
    const char *media_role;
    uint8_t playback;

    uint8_t enable_flag; /**< Enable flag. 0 - Disable, 1 - Enable */
    int32_t preset_id;
    uint32_t num_bands;
    codec_control_pp_eq_subband_t *bands;
}codec_control_set_pp_eq_t;

typedef struct codec_control_pp_get_uinfo
{
    uint32_t query_status_mask; /**< status of returned actual value */
    uint32_t value; /**< actual value */
    uint32_t min; /**< minimum for value */
    uint32_t max; /**< maximum for value */
} codec_control_pp_get_uinfo_t;

typedef struct codec_control_pp_get_info
{
    uint32_t query_status_mask; /**< status of returned actual value */
    int32_t value; /**< actual value */
    int32_t min; /**< minimum for value */
    int32_t max; /**< maximum for value */
} codec_control_pp_get_info_t;

typedef struct codec_control_get_pp_volume {
    const char *media_role;
    uint8_t playback;
    codec_control_pp_get_uinfo_t gain;
}codec_control_get_pp_volume_t;

typedef struct codec_control_get_pp_fade {
    const char *media_role;
    uint8_t playback;
    codec_control_pp_get_info_t fade;
}codec_control_get_pp_fade_t;

typedef struct codec_control_get_pp_balance {
    const char *media_role;
    uint8_t playback;
    codec_control_pp_get_info_t balance;
}codec_control_get_pp_balance_t;

typedef struct codec_control_get_pp_bmt {
    const char *media_role;
    uint8_t playback;
    codec_control_pp_filter_type_t filter_type; /**< Requested filter type */
    codec_control_pp_get_info_t bmt;
}codec_control_get_pp_bmt_t;

typedef struct codec_control_get_pp_eq{
    const char *media_role;
    uint8_t playback;
    codec_control_pp_get_info_t ret_preset_id; /**< Returned preset id
                                        -1      - custom equalizer speficied through 'bands' struct
                                        0 to N - pre-defined preset EQ index: ROCK/JAZZ/POP, etc */
    uint32_t ret_num_bands;/**< Returned number of EQ subbands supported
                                          when a custom preset_id is selected */
}codec_control_get_pp_eq_t;

/**
 * Eq_subband struct used in the following payload
 */
typedef struct  codec_control_pp_eq_subband_binfo
{
    codec_control_pp_get_uinfo_t ret_center_freq; /**< Returned band center frequency range
                                                                                            and value in millihertz */
    codec_control_pp_get_info_t ret_band_level; /**< Returned band gain range and value in millibels */
} codec_control_pp_eq_subband_binfo_t;


typedef struct codec_control_get_pp_eq_subbands{
    const char *media_role;
    uint8_t playback;
    uint32_t num_bands;/**< number of EQ subbands supported for custom eq
                                          returned from get_pp_eq query */
    codec_control_pp_eq_subband_binfo_t *bands;
}codec_control_get_pp_eq_subbands_t;

typedef struct codec_control_tunnel_cmd{
    uint8_t *input_data;
    uint32_t input_size;
    uint32_t expected_size;
    uint8_t *output_data;
    uint32_t output_size;
}codec_control_tunnel_cmd_t;

/** Callback prototype for pa_ext_codec_control_test(). \since 1.0 */
typedef void (*pa_ext_codec_control_test_cb_t)(
        pa_context *c,
        uint32_t version,
        void *userdata);

/** Callback prototype for pa_ext_device_restore_read_formats(). \since 1.0 */
typedef void (*pa_ext_codec_control_get_pp_volume_cb_t)(
        pa_context *c,
        const  codec_control_pp_get_uinfo_t *info,
        void *userdata);

typedef void (*pa_ext_codec_control_get_pp_fade_cb_t)(
        pa_context *c,
        const  codec_control_pp_get_info_t *info,
        void *userdata);

typedef void (*pa_ext_codec_control_get_pp_balance_cb_t)(
        pa_context *c,
        const  codec_control_pp_get_info_t *info,
        void *userdata);

typedef void (*pa_ext_codec_control_get_pp_bmt_cb_t)(
        pa_context *c,
        const  codec_control_pp_get_info_t *info,
        void *userdata);

typedef void (*pa_ext_codec_control_get_pp_eq_cb_t)(
        pa_context *c,
        const  codec_control_get_pp_eq_t *info,
        void *userdata);

typedef void (*pa_ext_codec_control_get_pp_eq_subbands_cb_t)(
        pa_context *c,
        const  codec_control_pp_eq_subband_binfo_t *info,
        void *userdata,
        int32_t eol);

typedef void (*pa_ext_codec_control_tunnel_cmd_cb_t)(
        pa_context *c,
        const  codec_control_tunnel_cmd_t *info,
        void *userdata);


/** Test if this extension module is available in the server. \since 1.0 */
pa_operation *pa_ext_codec_control_test(
        pa_context *c,
        pa_ext_codec_control_test_cb_t cb,
        void *userdata);

pa_operation *pa_ext_codec_control_set_pp_volume(
        pa_context *c,
        pa_context_success_cb_t cb,
        codec_control_set_pp_volume_t *info,
        void *userdata);

pa_operation *pa_ext_codec_control_set_pp_mute(
        pa_context *c,
        pa_context_success_cb_t cb,
        codec_control_set_pp_mute_t *info,
        void *userdata);

pa_operation *pa_ext_codec_control_set_pp_fade(
        pa_context *c,
        pa_context_success_cb_t cb,
        codec_control_set_pp_fade_t *info,
        void *userdata);

pa_operation *pa_ext_codec_control_set_pp_balance(
        pa_context *c,
        pa_context_success_cb_t cb,
        codec_control_set_pp_balance_t *info,
        void *userdata);

pa_operation *pa_ext_codec_control_set_pp_bmt(
        pa_context *c,
        pa_context_success_cb_t cb,
        codec_control_set_pp_bmt_t *info,
        void *userdata);

pa_operation *pa_ext_codec_control_set_pp_eq(
        pa_context *c,
        pa_context_success_cb_t cb,
        codec_control_set_pp_eq_t *info,
        void *userdata);

pa_operation *pa_ext_codec_control_get_pp_volume(
        pa_context *c,
        pa_ext_codec_control_get_pp_volume_cb_t cb,
        codec_control_get_pp_volume_t *info,
        void *userdata);

pa_operation *pa_ext_codec_control_get_pp_fade(
        pa_context *c,
        pa_ext_codec_control_get_pp_fade_cb_t cb,
        codec_control_get_pp_fade_t *info,
        void *userdata);

pa_operation *pa_ext_codec_control_get_pp_balance(
        pa_context *c,
        pa_ext_codec_control_get_pp_balance_cb_t cb,
        codec_control_get_pp_balance_t *info,
        void *userdata);

pa_operation *pa_ext_codec_control_get_pp_bmt(
        pa_context *c,
        pa_ext_codec_control_get_pp_bmt_cb_t cb,
        codec_control_get_pp_bmt_t *info,
        void *userdata);

pa_operation *pa_ext_codec_control_get_pp_eq(
        pa_context *c,
        pa_ext_codec_control_get_pp_eq_cb_t cb,
        codec_control_get_pp_eq_t *info,
        void *userdata);

pa_operation *pa_ext_codec_control_get_pp_eq_subbands(
        pa_context *c,
        pa_ext_codec_control_get_pp_eq_subbands_cb_t cb,
        codec_control_get_pp_eq_subbands_t *info,
        void *userdata);

pa_operation *pa_ext_codec_control_tunnel_cmd(
        pa_context *c,
        pa_ext_codec_control_tunnel_cmd_cb_t cb,
        codec_control_tunnel_cmd_t *info,
        void *userdata);

PA_C_DECL_END

#endif
