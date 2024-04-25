//******************************************************************************************************************************
// Copyright (c) 2017, 2019 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//******************************************************************************************************************************

/**
********************************************************************************************************************************
* @file  eglwaylandimagebase.h
* @brief EGL Wayland image base class
********************************************************************************************************************************
*/

#ifndef EGLWAYLANDIMAGEBASE_H
#define EGLWAYLANDIMAGEBASE_H

#include "eglnativeimage.h"
#include "eglwaylanddisplaybase.h"
#include "eglwaylandtypes.h"

// Forward declaration
struct gbm_bo;                  // NOWHINE NC004 <- Declared by libgbm
class  EglWaylandDisplayBase;
class  EglGbmUtils;

class EglWaylandImageBase : public EglNativeImage
{
public:
    virtual EGLBOOL Destroy();
    virtual EGLINT  GetBuffer(EglSubResource* pSubResource, EglMemoryDesc* pMemDesc) = 0;
    virtual EGLVOID CacheOperation(EglCacheCommands cacheCommand, EGLVOID* pCpuAddress);
    virtual EGLBOOL IsProtected();

    /// Get the native buffer backing the image
    virtual EGLINT GetNativeBufferFromImage(EGLVOID** ppNativeBuffer)
    {
        // Default return value
        return EGL_BAD_MATCH;
    };
    /// Retrieve the pixel format of the buffer
    virtual EGLBOOL ExportDMABUFImageQueryMESA(EGLINT* pFourcc, EGLINT* pNum_planes, EGLuint64KHR* pModifiers)
    {
        return EGL_FALSE;
    };
    /// Retrieves the dma_buf file descriptors, strides and offsets for the image
    virtual EGLBOOL ExportDMABUFImageMESA(EGLINT* pFds, EGLint* pStrides, EGLint* pOffsets)
    {
        return EGL_FALSE;
    };

protected:
    virtual ~EglWaylandImageBase();
    explicit EglWaylandImageBase(EglWaylandDisplayBase* pEglWaylandDisplayBase);
    virtual EGLBOOL ObjSetAttribute(EGLINT attribute, EGLINT value);
    virtual EGLBOOL IsProtectedStatusIncompatible();
    virtual EGLBOOL DoNotMap();

    /// Get the owning EGL wayland display
    EGL_INLINE EglWaylandDisplayBase* GetOwningDisplay()
    {
        return m_pEglWaylandDisplayBase;
    }

    /// Get native display of the EGL wayland display
    EGL_INLINE EGLVOID* GetNativeDisplay()
    {
        return m_pEglWaylandDisplayBase->GetNativeDisplay();
    }

    /// Get GBM utils object of the display
    EGL_INLINE EglGbmUtils* GetGbmUtils()
    {
        return m_pEglWaylandDisplayBase->GetGbmUtils();
    }

    /// Is access to protected content requested?
    EGL_INLINE EGLBOOL IsProtectedContentAccessRequested()
    {
        return m_accessProtectedContent;
    }

    gbm_bo*                m_pNativeBuffer;                         ///< The backing GBM BO
    EglMemoryDesc          m_memoryDesc;                            ///< Memory descriptor of the resource

private:
    EglWaylandImageBase(const EglWaylandImageBase&);                ///< Disallow the copy constructor.
    EglWaylandImageBase& operator=(const EglWaylandImageBase&);     ///< Disallow assignment operator.

    EglWaylandDisplayBase* m_pEglWaylandDisplayBase;                ///< The owning EGL display base
    EGLBOOL                m_accessProtectedContent;                ///< Value for EGL_PROTECTED_CONTENT_EXT attribute
};

#endif // EGLWAYLANDIMAGEBASE_H
