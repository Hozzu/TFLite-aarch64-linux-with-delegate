//******************************************************************************************************************************
// Copyright (c) 2014-2018 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//******************************************************************************************************************************

/**
********************************************************************************************************************************
* @file  eglwaylandsubdriver.h
* @brief Wayland subdriver class
********************************************************************************************************************************
*/

#ifndef EGLWAYLANDSUBDRIVER_H
#define EGLWAYLANDSUBDRIVER_H


#include "eglsubdriver.h"


// Forward declaration
class EglWaylandSubDriver final : public EglSubDriver
{
public:
    static EglWaylandSubDriver* Create();
    virtual EGLINT GetNativeDisplay(EGLNativeDisplayType hNativeDisplayType, EglNativeDisplay** ppNativeDisplay);
    virtual EGLINT CreateNativeWindowSurface(EglNativeDisplay*        pNativeDisplay,
                                             EglNativeConfig*         pNativeConfig,
                                             EGLNativeWindowType      window,
                                             const EGLINT*            pAttribList,
                                             EglNativeWindowSurface** ppNewNativeWindowSurface);
    virtual EGLINT CreateNativeWindowSurface64(EglNativeDisplay*        pNativeDisplay,
                                               EglNativeConfig*         pNativeConfig,
                                               EGLNativeWindowType      window,
                                               const EGLAttrib*         pAttribList,
                                               EglNativeWindowSurface** ppNewNativeWindowSurface);
    virtual const EGLCHAR* GetExtensionsString();
    virtual EGLINT Destroy();
    virtual EGLINT CreateNativeImage(EglNativeDisplay* pNativeDisplay,
                                     EGLenum           eTarget,
                                     EGLBOOL           hasContext,
                                     EGLClientBuffer   pBuffer,
                                     const EGLINT*     pAttribList,
                                     EglNativeImage**  ppNewNativeImage);
    virtual EGLINT CreateNativeImage64(EglNativeDisplay*  pNativeDisplay,
                                       EGLenum            eTarget,
                                       EGLBOOL            hasContext,
                                       EGLClientBuffer    pBuffer,
                                       const EGLINTPTR_T* pAttribList,
                                       EglNativeImage**   ppNewNativeImage);
    virtual EGLINT CreateNativeConfig(EglNativeDisplay* pNativeDisplay,
                                      EGLPIXELFORMAT    eglFormat,
                                      EGLUINT           numSamples,
                                      EglNativeConfig** ppNativeConfig);
    virtual EGLINT CreateNativeSync(EglNativeDisplay* pNativeDisplay,
                                      EGLenum         syncType,
                                      const EGLINT*   pAttribList,
                                      EglNativeSync** ppNewNativeSync);
    virtual EGLINT CreateNativePixmapSurface(EglNativeDisplay*        pNativeDisplay,
                                             EglNativeConfig*         pNativeConfig,
                                             EGLNativePixmapType      hNativePixmap,
                                             const EGLINT*            pAttribList,
                                             EglNativePixmapSurface** ppNewNativePixmapSurface);
    virtual EGLINT CreateNativePixmapSurface64(EglNativeDisplay*        pNativeDisplay,
                                               EglNativeConfig*         pNativeConfig,
                                               EGLNativePixmapType      hNativePixmap,
                                               const EGLAttrib*         pAttribList,
                                               EglNativePixmapSurface** ppNewNativePixmapSurface);
    virtual EGLINT CopyBuffers(const EGLVOID*        pSourceHostPtr,
                               const EglSubResource* pSubResource,
                               EGLNativePixmapType   hNativePixmap);
    virtual EGLBOOL QueryNativeBuffer(EGLVOID* pResourceToQuery, EGLINT attribute, EGLINT* pValue);

protected:
    EglWaylandSubDriver();
    virtual ~EglWaylandSubDriver();

private:
    EglWaylandSubDriver(const EglWaylandSubDriver&);                ///< Disallow the copy constructor
    EglWaylandSubDriver& operator=(const EglWaylandSubDriver&);     ///< Disallow assignment operator

};

#endif // EGLWAYLANDSUBDRIVER_H
