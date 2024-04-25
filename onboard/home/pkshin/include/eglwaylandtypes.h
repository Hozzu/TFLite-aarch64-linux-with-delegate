//******************************************************************************************************************************
// Copyright (c) 2017-2018 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//******************************************************************************************************************************

/**
********************************************************************************************************************************
* @file  eglwaylandtypes.h
* @brief EGL wayland types header file
********************************************************************************************************************************
*/

#ifndef EGLWAYLANDTYPES_H
#define EGLWAYLANDTYPES_H

// NOWHINE PR002: Compiler generated define
#if defined(QTI_INTEGRATED_BUILD)
#include "eglmacros.h"
#else
#if defined(_LINUX)
#include <malloc.h>
#include <string.h>

///@note Every macro defined in this file must have a corresponding macro defined in eglmacros.h using ESX functionality

#define EGL_SUBDRIVER_ENTRYPOINT_INFO_AUTO()    (void)0
#define EGL_INLINE                              __inline
///@note Use of EGL_MEM* macros will be a performance hit as opposed to using the optimized ESX_MEM* macros
#define EGL_MEMCPY(dst, src, numBytes)          memcpy(dst, src, numBytes)
#define EGL_MEMSET(dst, setVal, numBytes)       memset(dst, setVal, numBytes)
#define EGL_NEW                                 new                 // NOWHINE CP040 <- use C/C++ defaults
#define EGL_DELETE                              delete              // NOWHINE CP040 <- use C/C++ defaults
#define EGL_CALLOC(size)                        calloc(1, size)     // NOWHINE CP040 <- use C/C++ defaults
#define EGL_FREE(ptr)                           free(ptr)           // NOWHINE CP040 <- use C/C++ defaults
#define EGL_LOG_SYSTEM_OUT(s, ...)              fprintf(stdout, s, ##__VA_ARGS__)
#define EGL_STRLEN(s)                           strlen(s)
#define EGL_STRNCMP(s1, s2, len)                strncmp(s1, s2, len)
#define EGL_ASSERT(c)                           (void)0
#define EGL_ASSERT_ALWAYS()                     (void)0
///@note This is essentially a ceil function
#define EGL_UINT_UNITS(val, unitSize)           ((((val) + (unitSize)) > (val)) ? \
                                                 (((val) + ((unitSize) - 1)) / (unitSize)) : \
                                                 (((val) / (unitSize)) + ((((val) % (unitSize)) > 0) ? 1 : 0)))
#define EGL_ATOMIC_DEC(var)                     __sync_sub_and_fetch(var, 1)
#define EGL_ATOMIC_INC(var)                     __sync_add_and_fetch(var, 1)
#define EGL_BYTE_ALIGN_POW2(val, alignment)     (((val) + (alignment) - 1) & ~(static_cast<EGLSIZE_T>(alignment) - 1))
#define EGL_DBG_ERR_PRINT(s, ...)               EGL_LOG_SYSTEM_OUT(s, ##__VA_ARGS__)
#define EGL_NOT_IMPLEMENTED()                   EGL_ASSERT_ALWAYS()
#define EGL_OFFSETOF(s, m)                      offsetof(s, m)

#endif // _LINUX
#endif // QTI_INTEGRATED_BUILD

#endif // EGLWAYLANDTYPES_H
