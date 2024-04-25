//******************************************************************************************************************************
// Copyright (c) 2014-2018, 2020 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//******************************************************************************************************************************


/**
********************************************************************************************************************************
* @file  eglwlresourceimage.h
* @brief EGL Wayland Image class
********************************************************************************************************************************
*/

#ifndef EGLWLRESOURCEIMAGE_H
#define EGLWLRESOURCEIMAGE_H

#include "eglwaylandimagebase.h"

class EglWlResourceImage final : public EglWaylandImageBase
{
public:
    static EGLINT Create(EGLINT                target,
                         EGLVOID*              pClientBuffer,
                         const EGLINT*         pAttribList,
                         EglNativeDisplay*     pNativeDisplay,
                         EglWlResourceImage**  ppNewNativeImage);
    static EGLINT Create64(EGLINT                target,
                           EGLVOID*              pClientBuffer,
                           const EGLINTPTR_T*    pAttribList,
                           EglNativeDisplay*     pNativeDisplay,
                           EglWlResourceImage**  ppNewNativeImage);

    EGLINT GetBuffer(EglSubResource* pSubResource, EglMemoryDesc* pMemDesc);
    EGLINT GetNativeBufferFromImage(EGLVOID** ppWlBuffer);

protected:
    virtual ~EglWlResourceImage();
    explicit EglWlResourceImage(EglWaylandDisplayBase* pEglWaylandDisplayBase);
    EGLBOOL ObjSetAttribute(EGLINT attribute, EGLINT value);

private:
    EglWlResourceImage(const EglWlResourceImage&);                ///< Disallow the copy constructor.
    EglWlResourceImage& operator=(const EglWlResourceImage&);     ///< Disallow assignment operator.
    EGLBOOL SetAttributeList(const EGLINT* pAttribList);
    EGLBOOL SetAttributeList64(const EGLINTPTR_T* pAttribList);

    EGLINT  Init(EGLVOID* pClientBuffer);
    EGLVOID UpdateSubSampledInfo(EGLPIXELFORMAT eglFormat, EGLUINT planeIdx, EglSubResource* pSubResource);
    EGLVOID UpdateSubResourceInfoForSubSampledPackedBuffers(EGLPIXELFORMAT eglFormat, EglSubResource* pSubResource);
    EGLINT  GetWLBufferFromImage(EGLVOID** ppWlBuffer);

    EGLUINT                  m_planeId;                           ///< YUV plane id
};

#endif // EGLWLRESOURCEIMAGE_H
