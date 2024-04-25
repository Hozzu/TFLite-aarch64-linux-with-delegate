//******************************************************************************************************************************
// Copyright (c) 2014-2019 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//******************************************************************************************************************************

/**
********************************************************************************************************************************
* @file  eglwaylandwindowsurfacebase.h
* @brief Wayland Surface Base class
********************************************************************************************************************************
*/

#ifndef EGLWAYLANDWINDOWSURFACEBASE_H
#define EGLWAYLANDWINDOWSURFACEBASE_H

#include "eglnativewindowsurface.h"
#include "eglwaylanddisplaybase.h"
#include "eglwaylandtypes.h"

/**
********************************************************************************************************************************
* @brief Min swap Interval supported
********************************************************************************************************************************
*/
static const EGLINT EglMinSwapInterval = 0;

/**
********************************************************************************************************************************
* @brief Max  swap Interval supported
********************************************************************************************************************************
*/
static const EGLINT EglMaxSwapInterval = 1;


// Forward declaration
class EglWaylandConfig;

class EglWaylandWindowSurfaceBase : public EglNativeWindowSurface
{
public:
    virtual EGLINT  SwapBuffers(EglResourceAccessInfo* pAccessInfo) = 0;
    virtual EGLINT  GetBuffer(EglSubResource* pSubResource, EglMemoryDesc* pMemDesc) = 0;

    virtual EGLINT  SetSwapInterval(EGLINT interval);
    virtual EGLINT  SetAttribute(EGLINT attribute, EGLINT value);
    virtual EGLINT  SetAttribute64(EGLAttrib attribute, EGLAttrib value);
    virtual EGLBOOL SetRuntimeAttribute(EGLINT attribute, EGLINT value);
    virtual EGLINT  GetAttribute(EGLINT attribute, EGLINT* pValue);
    virtual EGLINT  Destroy();
    virtual EGLBOOL IsValidAttribute(EGLINT attribute);
    virtual EGLBOOL IsValidAttribute64(EGLAttrib attribute);

    /// Get the number of buffers backing the surface
    virtual EGLINT  GetBufferCount()    { return 0; }
    /// Base class implementation of the window surface resize callback
    virtual EGLINT  ResizeCallback(EGLINT x, EGLINT y, EGLINT width, EGLINT height) { return -1; }
    /// Base class implementation of get attached window surface size
    virtual EGLVOID GetAttachedDimensions(EGLINT* pWidth, EGLINT* pHeight) {}
    /// Perform cache operations
    virtual EGLVOID CacheOperation(EglCacheCommands cacheCommand, EGLVOID* pCpuAddress) {}
    /// Notify on flush complete
    virtual EGLVOID NotifyFlushComplete(EglResourceAccessInfo* pAccessInfo) {}

protected:
    /// Get the owning EGL wayland display
    EGL_INLINE EglWaylandDisplayBase* GetOwningDisplay()
    {
        return m_pEglWaylandDisplayBase;
    }

    /// Get GBM utils object of the display
    EGL_INLINE EglGbmUtils* GetGbmUtils()
    {
        return m_pEglWaylandDisplayBase->GetGbmUtils();
    }

    /// Get window surface's config
    EGL_INLINE EglWaylandConfig* GetSurfaceConfig()
    {
        return m_pEglWaylandConfig;
    }

    /// Get surface's swap interval
    EGL_INLINE EGLINT GetSwapInterval()
    {
        return m_swapInterval;
    }

    /// Is preserve on swap behavior enabled
    EGL_INLINE EGLBOOL IsPreserveEnabled()
    {
        return m_baseClassFlags.isPreserveEnabled;
    }

    /// Is window surface protected
    EGL_INLINE EGLBOOL IsProtectedSurface()
    {
        return m_baseClassFlags.isProtected;
    }

    /// Called when preserve on swap behavior is enabled
    virtual EGLVOID HandlePreserveOnSwapEnabled() {}

    /// Called when preserve on swap behavior is disabled
    virtual EGLVOID HandlePreserveOnSwapDisabled() {}

    EglWaylandWindowSurfaceBase() {}
    EglWaylandWindowSurfaceBase(EglWaylandDisplayBase* pEglWaylandDisplayBase,
                                EglWaylandConfig*      pEglWaylandConfig);
    virtual ~EglWaylandWindowSurfaceBase();
private:
    /***************************************************************************************************************************
    *   @brief
    *       Flags common to all Wayland window surfaces
    ***************************************************************************************************************************/
    union EglWaylandWindowSurfaceFlags
    {
        EGLUINT32 value;                           ///< Value of all the bits

        struct
        {
            EGLBIT  isPreserveEnabled        : 1;  ///< Flag to indicate if preserve-on-swap is enabled
            EGLBIT  isProtected              : 1;  ///< Flag to indicate if surface is protected
            EGLBIT  isSingleBufferMode       : 1;  ///< Flag to indicate if surface is in single buffer render mode
            ///@todo (ESX-10444) need to set the subresources internal format if gbm bo is in sRGB color space
            EGLBIT  isSRGBColorspace         : 1;  ///< TRUE if sRGB colorspace is used
            EGLUINT reserved                 : 28; ///< Reserved bits
        };
    };

    /// Set preserve on swap behavior
    EGL_INLINE EGLVOID SetPreserveOnSwapBehavior(EGLINT value)
    {
        m_baseClassFlags.isPreserveEnabled = (EGL_BUFFER_PRESERVED == value) ? EGL_TRUE : EGL_FALSE;
        if (EGL_TRUE == m_baseClassFlags.isPreserveEnabled)
        {
            HandlePreserveOnSwapEnabled();
        }
        else
        {
            HandlePreserveOnSwapDisabled();
        }
    }

    EglWaylandWindowSurfaceBase(const EglWaylandWindowSurfaceBase&);                ///< Disallow the copy constructor
    EglWaylandWindowSurfaceBase& operator=(const EglWaylandWindowSurfaceBase&);     ///< Disallow assignment operator

    EGLUINT                             m_swapInterval;                             ///< Swap interval for the surface
    EglWaylandConfig*                   m_pEglWaylandConfig;                        ///< The config for this window surface
    EglWaylandDisplayBase*              m_pEglWaylandDisplayBase;                   ///< The owning EGL wayland display base
    EglWaylandWindowSurfaceFlags        m_baseClassFlags;                           ///< Common flags for window surfaces
};

#endif // EGLWAYLANDWINDOWSURFACEBASE_H
