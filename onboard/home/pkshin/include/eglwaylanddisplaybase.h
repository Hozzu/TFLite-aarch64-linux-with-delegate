//******************************************************************************************************************************
// Copyright (c) 2014-2017 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//******************************************************************************************************************************

/**
********************************************************************************************************************************
* @file  eglwaylanddisplaybase.h
* @brief EGL Wayland Display class
********************************************************************************************************************************
*/

#ifndef EGLWAYLANDDISPLAYBASE_H
#define EGLWAYLANDDISPLAYBASE_H


#include "eglnativedisplay.h"

// Forward declaration
class EglGbmUtils;
class EglNativeBufferManager;

class EglWaylandDisplayBase : public EglNativeDisplay
{
public:
    virtual EGLBOOL  Terminate(EGLBOOL cleanUpNativeObjects);
    virtual EGLBOOL  Initialize();
    virtual EGLBOOL  Destroy();
    /// Bind native display to EglDisplay. Not supported by default
    virtual EGLBOOL  BindNativeDisplay(EGLVOID* pDisplayToBind) { return EGL_FALSE; }
    /// Unbind native display to EglDisplay. Not supported by default
    virtual EGLBOOL  UnbindNativeDisplay(EGLVOID* pDisplayToUnbind) { return EGL_FALSE; }
    /// Gets the native display
    virtual EGLVOID* GetNativeDisplay() { return NULL; }
    /// Gets the GbmUtils object
    virtual EglGbmUtils* GetGbmUtils()  { return NULL; }
    /// Is this the server stack
    virtual EGLBOOL IsServerStack()     { return EGL_FALSE; }
    /// Is this the client stack
    virtual EGLBOOL IsClientStack()     { return EGL_FALSE; }

protected:
    virtual ~EglWaylandDisplayBase();
    EglWaylandDisplayBase();
    explicit EglWaylandDisplayBase(EGLVOID* pNativeDisplay);

private:
    EglWaylandDisplayBase(const EglWaylandDisplayBase&);                        ///< Disallow the copy constructor
    EglWaylandDisplayBase& operator=(const EglWaylandDisplayBase&);             ///< Disallow assignment operator
};

#endif // EGLWAYLANDDISPLAYBASE_H
