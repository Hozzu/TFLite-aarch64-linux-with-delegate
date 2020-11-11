//******************************************************************************************************************************
// Copyright (c) 2014-2019 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//******************************************************************************************************************************

/**
********************************************************************************************************************************
* @file  eglwaylandgbmwindowsurface.h
* @brief Wayland GBM Surface class. This class is used by the compositor
********************************************************************************************************************************
*/

#ifndef EGLWAYLANDGBMWINDOWSURFACE_H
#define EGLWAYLANDGBMWINDOWSURFACE_H


#include "eglwaylandwindowsurfacebase.h"

struct gbm_bo;              // NOWHINE NC004 <- Declared by libgbm
struct gbm_surface;         // NOWHINE NC004 <- Declared by libgbm

class EglWaylandGbmWindowSurface final : public EglWaylandWindowSurfaceBase
{
public:
    static EglWaylandGbmWindowSurface* Create(EglNativeDisplay*   pNativeDisplay,
                                              EglWaylandConfig*   pNativeConfig,
                                              EGLNativeWindowType window,
                                              const EGLINT*       pAttribList);
    static EglWaylandGbmWindowSurface* Create64(EglNativeDisplay*   pNativeDisplay,
                                                EglWaylandConfig*   pNativeConfig,
                                                EGLNativeWindowType window,
                                                const EGLAttrib*    pAttribList);
    virtual EGLINT  SwapBuffers(EglResourceAccessInfo* pAccessInfo);
    virtual EGLINT  GetAttribute(EGLINT attribute, EGLINT* pValue);
    virtual EGLINT  GetBuffer(EglSubResource* pSubResource, EglMemoryDesc* pMemDesc);
    virtual EGLBOOL IsValidAttribute(EGLINT attribute);
    virtual EGLINT  Destroy();
    virtual EGLBOOL SetRuntimeAttribute(EGLINT attribute, EGLINT value);

protected:
    EglWaylandGbmWindowSurface(gbm_surface* pGbmSurface, EglWaylandDisplayBase* pDisplay, EglWaylandConfig* pConfig);
    virtual ~EglWaylandGbmWindowSurface();

    virtual EGLVOID HandlePreserveOnSwapEnabled();

private:
    /***************************************************************************************************************************
    *   @brief
            Structure to describe the EGL GBM BO information.
    ***************************************************************************************************************************/
    struct EglGbmBoMemDesc
    {
        gbm_bo*         pGbmBo;     ///< GBM BO
        EglMemoryDesc   memDesc;    ///< Egl Memory Desc
        EGLUINT         timestamp;  ///< Timestamp
        EGLUINT         context;    ///< ESX context
        EGLUINT         bufferAge;  ///< Buffer age
    };

    /***************************************************************************************************************************
    *   @brief
            Flags for the GBM window surface
    ***************************************************************************************************************************/
    union EglWaylandGbmWindowSurfaceFlags
    {
        EGLUINT32 value;               ///< Value of the bits

        struct
        {
            EGLBIT  isFrontBoAcquired     : 1;  ///< Flag to check if GetFrontBo was already called for this frame
            EGLUINT reserved              : 31; ///< Reserved bits
        };
    };

    EGLINT  SetAttributeList(const EGLINT* pAttribList);
    EGLINT  SetAttributeList64(const EGLAttrib* pAttribList);
    EglWaylandGbmWindowSurface(const EglWaylandGbmWindowSurface&);              ///< Disallow the copy constructor
    EglWaylandGbmWindowSurface& operator=(const EglWaylandGbmWindowSurface&);   ///< Disallow assignment operator

    EGLBOOL Init(EglWaylandConfig* pConfig, const EGLINT* pAttribList);
    EGLBOOL Init64(EglWaylandConfig* pConfig, const EGLAttrib* pAttribList);
    EGLINT  AcquireFrontBo();
    EGLINT  UpdateSubResourceAndMemDesc(EglSubResource* pSubResource, EglMemoryDesc* pMemDesc);
    EGLVOID UnmapGbmBo(EGLUINT index);
    EGLVOID UpdateBufferList(gbm_bo* pGbmBo);

    static const EGLUINT MaxBuffers = 3;                                        ///< Max. buffers in the buffer list

    gbm_surface*                    m_pGbmSurface;                              ///< Gbm surface
    EglMemoryDesc                   m_currentBoMemDesc;                         ///< Memory descriptor of the current BO
    EglGbmBoMemDesc*                m_pEglGbmBoMemDescList[MaxBuffers];         ///< Memory descriptors of all mapped BOs
    EglWaylandGbmWindowSurfaceFlags m_flags;                                    ///< Flags for the GBM Window Surface
};

#endif // EGLWAYLANDGBMWINDOWSURFACE_H
