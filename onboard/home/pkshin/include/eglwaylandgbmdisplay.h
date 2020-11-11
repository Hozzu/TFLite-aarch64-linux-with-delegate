//******************************************************************************************************************************
// Copyright (c) 2014-2017 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//******************************************************************************************************************************

/**
********************************************************************************************************************************
* @file  eglwaylandgbmdisplay.h
* @brief EGL Wayland GBM Display class. This is the display used by the compositor
********************************************************************************************************************************
*/

#ifndef EGLWAYLANDGBMDISPLAY_H
#define EGLWAYLANDGBMDISPLAY_H


#include "eglwaylanddisplaybase.h"

// Forward declaration
class WaylandBufferBackend;
class EglGbmUtils;

struct gbm_device;      // NOWHINE NC004 <- Declared by libgbm
struct wl_display;      // NOWHINE NC004 <- Declared by wayland

class EglWaylandGbmDisplay final : public EglWaylandDisplayBase
{
public:
    static EglWaylandGbmDisplay* Create(EGLVOID* pNativeDisplay);
    virtual EGLBOOL  Terminate(EGLBOOL cleanUpNativeObjects);
    virtual EGLBOOL  Initialize();
    virtual EGLBOOL  Destroy();
    virtual EGLBOOL  BindNativeDisplay(EGLVOID* pDisplayToBind);
    virtual EGLBOOL  UnbindNativeDisplay(EGLVOID* pDisplayToUnbind);
    /// Gets the native display
    virtual EGLVOID* GetNativeDisplay() { return m_pGbmDevice; }
    /// Gets the GbmUtils object
    EglGbmUtils*     GetGbmUtils()      { return m_pGbmUtils; }
    /// Is this the server stack
    virtual EGLBOOL IsServerStack()     { return EGL_TRUE; }

protected:
    virtual ~EglWaylandGbmDisplay();
    explicit EglWaylandGbmDisplay(gbm_device* pGbmDevice);

private:
    EglWaylandGbmDisplay();
    EglWaylandGbmDisplay(const EglWaylandGbmDisplay&);              ///< Disallow the copy constructor
    EglWaylandGbmDisplay& operator=(const EglWaylandGbmDisplay&);   ///< Disallow assignment operator

    EGLBOOL InitObj();

    gbm_device*             m_pGbmDevice;                               ///< GBM device
    wl_display*             m_pBoundWaylandDisplay;                     ///< Wayland display bound to the compositor
    WaylandBufferBackend*   m_pWaylandBufferBackend;                    ///< Wayland buffer backend implementation
    EglGbmUtils*            m_pGbmUtils;                                ///< GbmUtils pointer
};

#endif // EGLWAYLANDGBMDISPLAY_H
