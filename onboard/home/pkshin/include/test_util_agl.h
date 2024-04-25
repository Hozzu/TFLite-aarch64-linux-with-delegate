/* ===========================================================================
 * Copyright (c) 2017-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
=========================================================================== */

#ifndef _TEST_UTIL_AGL_H_
#define _TEST_UTIL_AGL_H_

#include <stdbool.h>
#include <stdlib.h>
#include <linux/ion.h>
#include <syslog.h>
#include <signal.h>


#include <drm/drm_fourcc.h>
#include <GLES2/gl2.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <EGL/eglwaylandext.h>

#include "gbm.h"
#include "gbm_priv.h"
//#include "msm_drm.h"

#include <wayland-client.h>

#include "xdg-shell-client-protocol.h"
#include "scaler-client-protocol.h"
#ifndef AIS_EARLYSERVICE
#include "gbm-buffer-backend-client-protocol.h"
#include "viewporter-client-protocol.h"
#else
#include "gbm-buffer-backend-client-protocol-rvc.h"
#include "viewporter-client-protocol-rvc.h"
#endif

#include "qcarcam.h"

#define KGSL_USER_MEM_TYPE_ION 3
#define IVI_SURFACE_ID 9000

typedef enum
{
    GBM_BUF_STATE_NON,
    GBM_BUF_STATE_INIT_BUF,
    GBM_BUF_STATE_INIT_WL,
}gbm_buffer_state_t;

struct display_wl
{
    struct wl_display *display;
    struct wl_registry *registry;
    struct wl_compositor *compositor;
    struct wl_subcompositor *subcompositor;
    struct wl_shell *shell;
    struct wl_shm *shm;
    uint32_t formats;
    uint32_t output_width;
    uint32_t output_height;

    int scaler_version;
    struct wl_scaler *scaler;
    struct wl_viewport *viewport;

    struct wp_viewporter *viewporter;

    struct wl_output *output;
    struct gbm_buffer_backend* gbmbuf;
    struct ivi_application *ivi_application;
};

struct gbm_buffer
{
    struct gbm_bo *bo;
    int     fd;
    void *p_data;
    uint32_t fbid;
    uint32_t buflen;

    uint32_t idx;
    struct test_util_window_t* p_window;

    struct wl_buffer *wl_buf;
    gbm_buffer_state_t state;
    unsigned int is_secure;
};

struct window_wl
{
    struct display_wl *display;
    int width, height, pos_x, pos_y;
    struct wl_surface *surface;
    struct wl_subsurface *subsurface;
    struct wl_shell_surface *shell_surface;
    struct wl_buffer *prev_buffer;
    struct wl_callback *callback;
    struct wl_viewport *subviewport;
    struct wp_viewport *viewport_wp;
    int fullscreen;
    int buffer_index;

    struct ivi_surface *ivi_surface;

    EGLDisplay egldpy;
};

typedef struct
{
    void * ptr;
    void * wl_ptr;
    uint32_t c2d_surface_id;
    boolean isdequeue;
}test_util_buffer_t;

struct test_util_ctxt_t
{
    test_util_ctxt_params_t params;

    struct display_wl *wl_display;
    EGLDisplay egldpy;
    struct gbm_device *gbm;
    int drm_fd;
    /* for parent_surface */
    int parent_set;
    struct wl_surface *parent_surface;
    struct gbm_buffer *parent_gbm_buf;
    struct wl_shell_surface *parent_shell_surface;
    struct ivi_surface *parent_ivi_surface;
    struct wl_callback *parent_callback;
    int parent_size[2];
};

struct src_rectangle
{
    int src_x;
    int src_y;
    int src_width;
    int src_height;
};

struct test_util_window_t
{
    char winid[64];
    struct window_wl *wl_window;

    unsigned int flags;

    /*buffers*/
    struct gbm_buffer *gbm_buf;            /* for store */
    struct gbm_buffer *gbm_buf_wl;        /* for display */
    struct src_rectangle src_rec;
    test_util_buffer_t* buffers;
    int buffer_size[2];
    int n_buffers;
    int stride;
    int format;
    int commit_frames;

    pthread_mutex_t m_mutex;
    std::list<uint32> *rel_buf_list;

    test_util_diag_t* diag;
};



#endif /* _TEST_UTIL_AGL_H_ */
