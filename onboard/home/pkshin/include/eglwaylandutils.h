//******************************************************************************************************************************
// Copyright (c) 2014-2020 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//******************************************************************************************************************************

/**
********************************************************************************************************************************
* @file  eglwaylandutils.h
* @brief Utility class for the wayland subdriver to interact with wayland buffers and libgbm
********************************************************************************************************************************
*/

#ifndef EGLWAYLANDUTILS_H
#define EGLWAYLANDUTILS_H

// NOWHINE PR007b: External wayland file
#include <wayland-client.h>

#include "eglgbmutils.h"

// Forward declaration
// NOWHINE NC004: wl_egl_window is declared externally by Wayland
struct wl_egl_window;

/*******************************************************************************************************************************
*   @brief
*       wl_egl_window.driver_private field points to this structure, memory allocated by calloc/free
*******************************************************************************************************************************/
struct WlEglWindowPrivateData
{
    EGLVOID*        pEglSurface;    ///< Weak reference to EglWaylandWindowSurfaceBase*
};

// NOWHINE GR017 {} the callback prototype is defined in wayland-egl-backend.h
// NOWHINE CP029 {} the callback prototype is defined in wayland-egl-backend.h
// NOWHINE CF001 {} the callback prototype is defined in wayland-egl-backend.h
class EglWaylandUtils final : public EglGbmUtils
{
public:
    static EglWaylandUtils* Create(EGLINT* pDrmNodeType);
#if ESX_WAYLAND_EGL
    static EGLINT WlEglWindowResizeCallback(wl_egl_window* pWindow,
                                            EGLVOID*       pEglSurface,
                                            EGLINT         x,
                                            EGLINT         y,
                                            EGLINT         width,
                                            EGLINT         height);
#else
    static void WlEglWindowResizeCallback(wl_egl_window* pWindow, void* driver_private);
    static void WlEglWindowDestroyCallback(void *driver_private);
#endif // ESX_WAYLAND_EGL

    static EGLBOOL WlDisplayRoundTrip(wl_display* pWlDisplay, wl_event_queue* pWlQueue);
    static EGLVOID WlSyncCallback(EGLVOID* pData, wl_callback* pWlCallback, EGLUINT callbackData);

    gbm_bo* GetGbmBoFromWlBuffer(wl_buffer* pWlBuffer);
    virtual EGLVOID Destroy();

    /// Get GBM device's magic
    EGL_INLINE EGLINT GetGbmDeviceMagic()
    {
        return EglGbmUtils::GetGbmDeviceMagic(m_pGbmDevice);
    }

protected:

private:
    EglWaylandUtils(const EglWaylandUtils&);            ///< Disallow the copy constructor
    EglWaylandUtils& operator=(const EglWaylandUtils&); ///< Disallow assignment operator

    explicit EglWaylandUtils(gbm_device* pGbmDevice, EGLUINT gslDevHandle, EGLINT gbmDeviceFD);

    /// Default Constructor
    EglWaylandUtils();
    virtual ~EglWaylandUtils();

    static wl_callback_listener s_callbackListener;           ///< The callback listener handlers
    EGLUINT                     m_gslDevHandle;               ///< Gsl device handle
    EGLINT                      m_gbmDeviceFD;                ///< Gbm device FD
};

#endif // EGLWAYLANDUTILS_H
