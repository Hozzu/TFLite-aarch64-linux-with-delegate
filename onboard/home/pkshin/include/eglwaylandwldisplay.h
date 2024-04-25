//******************************************************************************************************************************
// Copyright (c) 2014-2018 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//******************************************************************************************************************************

/**
********************************************************************************************************************************
* @file  eglwaylandwldisplay.h
* @brief EGL Wayland WL Display class. This is the display used by the Wayland clients
********************************************************************************************************************************
*/

#ifndef EGLWAYLANDWLDISPLAY_H
#define EGLWAYLANDWLDISPLAY_H

#include "eglwaylanddisplaybase.h"
#include "eglwaylandtypes.h"

// Forward declarations
class EglWaylandUtils;

struct wl_registry;                       // NOWHINE NC004 <- Declared by wayland
struct wl_registry_listener;              // NOWHINE NC004 <- Declared by wayland
struct wl_event_queue;                    // NOWHINE NC004 <- Declared by wayland
struct wayland_buffer_backend;            // NOWHINE NC004 <- Declared by waylandbufferbackend protocol
struct wayland_buffer_backend_listener;   // NOWHINE NC004 <- Declared by waylandbufferbackend protocol

class EglWaylandWlDisplay final : public EglWaylandDisplayBase
{
public:
    static EglWaylandWlDisplay* Create(EGLVOID* pNativeDisplay);
    EGLBOOL Init();
    virtual EGLBOOL  Terminate(EGLBOOL cleanUpNativeObjects);
    virtual EGLBOOL  Initialize();
    virtual EGLBOOL  Destroy();
    /// Gets the native display
    virtual EGLVOID* GetNativeDisplay() { return m_pWlDisplay; }

    /// Get the underlying wayland display
    EGL_INLINE wl_display* GetWlDisplay()
    {
        return m_pWlDisplay;
    }

    /// Get the underlying wayland queue
    EGL_INLINE wl_event_queue* GetWlQueue()
    {
        return m_pWlEventQueue;
    }

    /// Get the wayland_buffer_backend member
    EGL_INLINE wayland_buffer_backend* GetWaylandBufferBackend()
    {
        return m_pWaylandBufferBackend;
    }

    /// Set the wayland_buffer_backend member
    EGL_INLINE EGLVOID SetWaylandBufferBackend(wayland_buffer_backend* pWaylandBufferBackend)
    {
        m_pWaylandBufferBackend = pWaylandBufferBackend;
    }

    /// Get the wayland_buffer_backend_listener handler
    EGL_INLINE wayland_buffer_backend_listener* GetWaylandBufferBackendHandler()
    {
        return m_pWaylandBufferBackendListener;
    }

    /// Get the GbmUtils object
    EGL_INLINE EglGbmUtils* GetGbmUtils()
    {
        return reinterpret_cast<EglGbmUtils*>(m_pEglWaylandUtils);
    }

    /// Set the EglWaylandUtils member
    EGL_INLINE EGLVOID SetEglWaylandUtils(EglWaylandUtils* pEglWaylandUtils)
    {
        m_pEglWaylandUtils = pEglWaylandUtils;
    }

    /// Set the initialization complete flag
    EGL_INLINE EGLVOID Initialized() { m_initialized = EGL_TRUE; }

    /// Is this the client stack
    virtual EGLBOOL IsClientStack()  { return EGL_TRUE; }

protected:
    virtual ~EglWaylandWlDisplay();
    explicit EglWaylandWlDisplay(EGLVOID* pNativeDisplay);

private:
    // wl_registry_listener handlers
    static EGLVOID Global(EGLVOID* pData, wl_registry* pWlRegistry, EGLUINT name, const EGLCHAR* pInterface, EGLUINT version);
    static EGLVOID GlobalRemove(EGLVOID* pData, wl_registry* pWlRegistry, EGLUINT name);

    // wayland_buffer_backend listener handlers
    static EGLVOID Device(EGLVOID* pData, wayland_buffer_backend* pWaylandBufferBackend);
    static EGLVOID Format(EGLVOID* pData, wayland_buffer_backend* pWaylandBufferBackend, EGLUINT format);
    static EGLVOID Authenticated(EGLVOID* pData, wayland_buffer_backend* pWaylandBufferBackend);

    EglWaylandWlDisplay();
    EglWaylandWlDisplay(const EglWaylandWlDisplay&);                  ///< Disallow the copy constructor
    EglWaylandWlDisplay& operator=(const EglWaylandWlDisplay&);       ///< Disallow assignment operator

    EGLBOOL                          m_initialized;                   ///< Initialization flag
    wl_display*                      m_pWlDisplay;                    ///< The wayland native display object
    wl_event_queue*                  m_pWlEventQueue;                 ///< The wayland event queue for wl_proxy objects
    wl_registry*                     m_pWlRegistry;                   ///< The wayland registry wl_proxy object
    wl_registry_listener*            m_pRegistryListener;             ///< The wl_registry listener handlers
    wayland_buffer_backend*          m_pWaylandBufferBackend;         ///< The wayland_buffer_backend wl_proxy object
    wayland_buffer_backend_listener* m_pWaylandBufferBackendListener; ///< The wayland_buffer_backend listener handlers
    EglWaylandUtils*                 m_pEglWaylandUtils;              ///< The module providing Wayland and GBM utils
};

#endif // EGLWAYLANDWLDISPLAY_H
