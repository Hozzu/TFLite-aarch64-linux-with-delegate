//******************************************************************************************************************************
// Copyright (c) 2014-2018 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//******************************************************************************************************************************

/**
********************************************************************************************************************************
* @file  waylandbufferbackend.h
* @brief Declaration of the Wayland buffer backend class that provides wl_buffer protocol objects
********************************************************************************************************************************
*/

#ifndef WAYLANDBUFFERBACKEND_H
#define WAYLANDBUFFERBACKEND_H

#include "eglgbmutils.h"

// Forward declaration
struct wayland_buffer_backend_interface;    // NOWHINE NC004 <- declared by WaylandBufferBackend protocol
struct wl_buffer_interface;                 // NOWHINE NC004 <- wl_buffer_interface externally declared by Wayland
struct wl_client;                           // NOWHINE NC004 <- wl_client externally declared by Wayland
struct wl_display;                          // NOWHINE NC004 <- wl_display externally declared by Wayland
struct wl_global;                           // NOWHINE NC004 <- wl_global externally declared by Wayland
struct wl_resource;                         // NOWHINE NC004 <- wl_resource externally declared by Wayland

class WaylandBufferBackend
{
public:
    static WaylandBufferBackend* Create(wl_display*  pWlDisplay,
                                        EglGbmUtils* pEglGbmUtils);
    virtual EGLVOID Destroy();
    static  gbm_buf_info* GetBufferResourceUserData(EGLVOID* pWlBufferResource);

private:
    static EGLVOID BindToBufferBackend(wl_client*   pWlClient,
                                       EGLVOID*     pData,
                                       EGLUINT      version,
                                       EGLUINT      id);

    static EGLVOID AuthenticateClient(wl_client*      pWlClient,
                                      wl_resource*    pWlResource,
                                      EGLUINT         id);

    static EGLVOID CreateBuffer(wl_client*   pWlClient,
                                wl_resource* pWlResource,
                                EGLUINT      id,
                                EGLINT       fd,
                                EGLINT       metadataFd,
                                EGLUINT      width,
                                EGLUINT      height,
                                EGLUINT      format,
                                EGLUINT      stride);

    static EGLVOID CreatePlanarBuffer(wl_client*   pWlClient,
                                      wl_resource* pWlResource,
                                      EGLUINT      id,
                                      EGLINT       fd,
                                      EGLINT       metadataFd,
                                      EGLUINT      width,
                                      EGLUINT      height,
                                      EGLUINT      format,
                                      EGLUINT      offset0,
                                      EGLUINT      stride0,
                                      EGLUINT      offset1,
                                      EGLUINT      stride1,
                                      EGLUINT      offset2,
                                      EGLUINT      stride2);

    static EGLVOID BufferResourceDestroy(wl_client* pWlClient, wl_resource* pWlResource);
    static EGLVOID BufferDestroy(wl_resource* pWlResource);

    WaylandBufferBackend(wl_display* pWlDisplay, EglGbmUtils* pEglGbmUtils);
    EGLBOOL Init();
    EGLVOID CreateWaylandEglBuffer(wl_client*   pWlClient,
                                   wl_resource* pWlResource,
                                   EGLUINT      id,
                                   EGLINT       fd,
                                   EGLINT       metadataFd,
                                   EGLUINT      width,
                                   EGLUINT      height,
                                   EGLUINT      format,
                                   EGLUINT      offset0,
                                   EGLUINT      stride0,
                                   EGLUINT      offset1,
                                   EGLUINT      stride1,
                                   EGLUINT      offset2,
                                   EGLUINT      stride2);


    /// Get the request interface handler of the buffer backend
    EGL_INLINE EGLVOID* GetRequestHandler() { return static_cast<EGLVOID*>(m_pBufferBackendInterface); }

    /// Authenticate a magic with the underlying buffer backend device
    EGL_INLINE EGLBOOL AuthenticateMagic(EGLUINT magic)
    {
        return m_pEglGbmUtils->AuthenticateMagic(magic);
    }

    WaylandBufferBackend();
    virtual ~WaylandBufferBackend();

    WaylandBufferBackend(const WaylandBufferBackend&);                      ///< Disallow the copy constructor
    WaylandBufferBackend& operator=(const WaylandBufferBackend&);           ///< Disallow assignment operator

    wl_display*                              m_pWlDisplay;                   ///< Owning wayland display object
    wl_global*                               m_pWaylandBufferBackendGlobal;  ///< The corresponding wayland global object
    EglGbmUtils*                             m_pEglGbmUtils;                 ///< The module providing GBM utility functions
    // NOWHINE NC004: wayland_buffer_backend_interface is an auto generated structure name
    struct wayland_buffer_backend_interface* m_pBufferBackendInterface;      ///< The Wayland buffer backend request handler
    // NOWHINE NC004: wl_buffer_interface is declared externally by Wayland
    static struct wl_buffer_interface*       s_pBufferInterface;             ///< The Wayland EGL buffer request handler
};

#endif // WAYLANDBUFFERBACKEND_H
