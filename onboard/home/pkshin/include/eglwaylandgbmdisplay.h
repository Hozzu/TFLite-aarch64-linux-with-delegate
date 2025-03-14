//******************************************************************************************************************************
// Copyright (c) 2014-2017, 2020 Qualcomm Technologies, Inc.
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
class EglGbmUtils;

struct gbm_device;      // NOWHINE NC004 <- Declared by libgbm

class EglWaylandGbmDisplay final : public EglWaylandDisplayBase
{
public:
    static EglWaylandGbmDisplay* Create(EGLVOID* pNativeDisplay);
    virtual EGLBOOL  Terminate(EGLBOOL cleanUpNativeObjects);
    virtual EGLBOOL  Initialize();
    virtual EGLBOOL  Destroy();
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
    EglGbmUtils*            m_pGbmUtils;                                ///< GbmUtils pointer
};

#endif // EGLWAYLANDGBMDISPLAY_H
