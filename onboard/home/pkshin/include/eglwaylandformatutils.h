//******************************************************************************************************************************
// Copyright (c) 2014-2019 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//******************************************************************************************************************************

/**
********************************************************************************************************************************
* @file  eglwaylandformatutils.h
* @brief Wayland format related utility function declarations
********************************************************************************************************************************
*/

#ifndef EGLWAYLANDFORMATUTILS_H
#define EGLWAYLANDFORMATUTILS_H

#include "egltypes.h"

class EglWaylandFormatUtils final
{
public:
    static EGLUINT        GetGbmFormatFromEglFormatRenderable(EGLPIXELFORMAT eglFormat);
    static EGLUINT        GetGbmFormatFromEglFormat(EGLPIXELFORMAT eglFormat);
    static EGLUINT        GetGbmFormatFromWaylandBackendFormat(EGLUINT waylandBackendFormat);
    static EGLPIXELFORMAT GetEglFormatFromGbmFormat(EGLUINT gbmFormat);
    static EGLPIXELFORMAT GetEglFormatFromWaylandBackendFormat(EGLUINT waylandBackendFormat);
    static EGLUINT        GetWaylandBackendFormatFromEglFormat(EGLPIXELFORMAT eglFormat);
    static EGLBOOL        IsFormatSupported(EGLUINT waylandBufferBackendFormat);
    static EGLPIXELFORMAT GetEglFormatFromDrmFormat(EGLUINT drmFormat);
    static EGLUINT        GetDrmFormatFromEglFormat(EGLPIXELFORMAT eglFormat);

private:
    EglWaylandFormatUtils();
    ~EglWaylandFormatUtils();
    EglWaylandFormatUtils(const EglWaylandFormatUtils&);                    ///< Disallow the copy constructor
    EglWaylandFormatUtils& operator=(const EglWaylandFormatUtils&);         ///< Disallow assignment operator

};


#endif // EGLWAYLANDFORMATUTILS_H
