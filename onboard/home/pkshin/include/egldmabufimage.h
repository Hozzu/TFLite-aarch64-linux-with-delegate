//******************************************************************************************************************************
// Copyright (c) 2017-2019 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//******************************************************************************************************************************

/**
********************************************************************************************************************************
* @file  egldmabufimage.h
* @brief EglDmaBufImage, this implements extension EGL_EXT_image_dma_buf_import
********************************************************************************************************************************
*/

#ifndef EGLDMABUFIMAGE_H
#define EGLDMABUFIMAGE_H

// NOWHINE PR007b: External wayland file
#include <wayland-client.h>

#include "eglwaylandimagebase.h"

class EglDmaBufImage final : public EglWaylandImageBase
{
public:
    static EGLINT Create(EGLINT            target,
                         EGLVOID*          pClientBuffer,
                         const EGLINT*     pAttribList,
                         EglNativeDisplay* pNativeDisplay,
                         EglDmaBufImage**  ppNewNativeImage);
    static EGLINT Create64(EGLINT             target,
                           EGLVOID*           pClientBuffer,
                           const EGLINTPTR_T* pAttribList,
                           EglNativeDisplay*  pNativeDisplay,
                           EglDmaBufImage**   ppNewNativeImage);
    EGLINT  GetBuffer(EglSubResource* pSubResource, EglMemoryDesc* pMemDesc);
    EGLINT  GetNativeBufferFromImage(EGLVOID** ppWlBuffer);
    EGLBOOL ExportDMABUFImageQueryMESA(EGLINT* pFourcc, EGLINT* pNum_planes, EGLuint64KHR* pModifiers);
    EGLBOOL ExportDMABUFImageMESA(EGLINT* pFds, EGLint* pStrides, EGLint* pOffsets);

protected:
    EGLBOOL ObjGetAttribute(EGLINT attribute, EGLINT* pValue) const;
    EGLBOOL ObjSetAttribute(EGLINT attribute, EGLINT value);

private:
    explicit EglDmaBufImage(EglWaylandDisplayBase* pEglDisplay);
    virtual ~EglDmaBufImage();
    EglDmaBufImage(const EglDmaBufImage&);                ///< Disallow the copy constructor.
    EglDmaBufImage& operator=(const EglDmaBufImage&);     ///< Disallow assignment operator.

    EGLINT          Init();
    EGLVOID         UpdateFormatQualifier();
    EGLBOOL         CalculateAndVerifyAttributes();
    EGLBOOL         SetAttributeList(const EGLINT* pAttribList);
    EGLBOOL         SetAttributeList64(const EGLINTPTR_T* pAttribList);
    EGLINT          GetWLBufferFromImage(EGLVOID** ppWlBuffer);

    EglSubResource         m_subRes;                        ///< Description of the Image
    EGLUINT                m_planeFd[EglResourceMaxPlanes]; ///< File descriptors of image planes
    EGLUINT                m_yuvColorSpaceHint;             ///< Color space, only relevant for yuv format images
    EGLUINT                m_yuvChromaHorizontalSitingHint; ///< Horizontal chroma siting relative to luma samples
    EGLUINT                m_yuvChromaVerticalSitingHint;   ///< Vertical chroma siting relative to luma samples
    EGLUINT                m_sampleRangeHint;               ///< Numerical range of samples, only relevant for yuv format images
};

#endif  // EGLDMABUFIMAGE_H
