//******************************************************************************************************************************
// Copyright (c) 2014-2018 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//******************************************************************************************************************************

/**
********************************************************************************************************************************
* @file  eglwaylandconfig.h
* @brief Config class for the EGL wayland subdriver
********************************************************************************************************************************
*/

#ifndef EGLWAYLANDCONFIG_H
#define EGLWAYLANDCONFIG_H


#include "eglnativeconfig.h"
#include "eglwaylandtypes.h"


class EglWaylandConfig final : public EglNativeConfig
{
public:
    static EglWaylandConfig* Create(EGLPIXELFORMAT eglFormat);
    virtual EGLBOOL ObjGetAttribute(EGLINT attribute, EGLINT* pValue) const;
    virtual EGLBOOL ObjSetAttribute(EGLINT attribute, EGLINT value);
    virtual EGLBOOL ObjSelect(const EglNativeConfig* pConfig) const;
    virtual EGLBOOL ObjDestroy();

    /// Get the EGLPIXELFORMAT
    EGL_INLINE EGLPIXELFORMAT GetEglFormat() { return m_eglFormat; }

    /// Get the native(GBM) format
    EGL_INLINE EGLUINT GetNativeFormat() { return m_nativeVisualId; }

protected:

private:
    EGLBOOL Init();

    /// Matches the selectVal and configVal. Returns EGL_TRUE on success, EGL_FALSE on failure
    static EGL_INLINE EGLBOOL MatchExact(EGLINT selectVal, const EglNativeConfig* pNativeConfig, EGLINT attribute)
    {
        EGLINT configVal;
        EglNativeConfig::GetAttribute(pNativeConfig, attribute, &configVal);
        return (EGL_DONT_CARE != selectVal) ? (configVal == selectVal) : EGL_TRUE;
    }

    EglWaylandConfig(const EglWaylandConfig& );             ///< Disallow the copy constructor
    EglWaylandConfig& operator=(const EglWaylandConfig&);   ///< Disallow assignment operator

    explicit EglWaylandConfig(EGLPIXELFORMAT eglFormat);
    EglWaylandConfig();
    virtual ~EglWaylandConfig();

    EGLINT              m_nativeRenderable;             ///< Value of EGL_NATIVE_RENDERABLE
    EGLINT              m_nativeVisualId;               ///< Value of EGL_NATIVE_VISUAL_ID
    EGLINT              m_nativeVisualType;             ///< Value of EGL_NATIVE_VISUAL_TYPE
    EGLINT              m_matchNativePixmap;            ///< Value of EGL_MATCH_NATIVE_PIXMAP
    EGLPIXELFORMAT      m_eglFormat;                    ///< EGL Pixel format
};

#endif // EGLWAYLANDCONFIG_H
