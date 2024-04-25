//******************************************************************************************************************************
// Copyright (c) 2014-2018 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//******************************************************************************************************************************

/**
********************************************************************************************************************************
* @file  eglgbmutils.h
* @brief Utility class for the wayland subdriver to interact with libgbm
********************************************************************************************************************************
*/

#ifndef EGLGBMUTILS_H
#define EGLGBMUTILS_H

// NOWHINE PR007b: External Generic Buffer Manager file
#include <gbm_priv.h>
#include "egltypes.h"
#include "eglwaylandtypes.h"

// Forward declarations
struct gbm_bo;              // NOWHINE NC004 <- Declared by libgbm
struct gbm_buf_info;        // NOWHINE NC004 <- Declared by libgbm
struct gbm_device;          // NOWHINE NC004 <- Declared by libgbm
struct gbm_surface;         // NOWHINE NC004 <- Declared by libgbm

#if defined(ENABLE_DYNAMIC_SYMBOL_LOADING)
typedef EGLINT (*EGLGETGBMBUFFINFOFP)(struct wl_resource* pWlResource, gbm_buf_info* pGbmBufInfo);
#endif // ENABLE_DYNAMIC_SYMBOL_LOADING

/**
********************************************************************************************************************************
* @brief Max length for the GBM device name
********************************************************************************************************************************
*/
static const EGLINT MaxDeviceNameLength = 64;

/**
********************************************************************************************************************************
* @brief Gbm value for TRUE
********************************************************************************************************************************
*/
static const EGLINT GbmTrue = 1;

/**
********************************************************************************************************************************
* @brief Gbm value for FALSE
********************************************************************************************************************************
*/
static const EGLINT GbmFalse = 0;

/**
********************************************************************************************************************************
* @brief Gbm value for Success
********************************************************************************************************************************
*/
static const EGLINT GbmSuccess = 0;

/**
********************************************************************************************************************************
* @brief Gbm value for Failure
********************************************************************************************************************************
*/
static const EGLINT GbmFailure = -1;

/**
********************************************************************************************************************************
* @brief Bitfield flags indicating requested usage flags
********************************************************************************************************************************
*/
union EglGbmBoUsageFlags
{
    EGLUINT32 value;                    ///< Value
    struct
    {
        EGLBIT  reqProtected   :  1;    ///< Request a protected buffer
        EGLBIT  reqUbwc        :  1;    ///< Request UBWC
        EGLUINT reserved       : 30;    ///< Reserved
    };
};

/**
********************************************************************************************************************************
* @brief Structure to contain the requested data when creating a GBM BO
********************************************************************************************************************************
*/
struct EglGbmBoCreateData
{
    EGLUINT            width;      ///< Requested width
    EGLUINT            height;     ///< Requested height
    EGLUINT            format;     ///< Requested format
    EglGbmBoUsageFlags flags;      ///< Requested flags
};

class EglGbmUtils
{
public:
    static EglGbmUtils*       Create(gbm_device* pGbmDevice);

    static EGLINT             GetGbmDeviceMagic(gbm_device* pGbmDevice);
    static EGLBOOL            IsValidGbmDevice(gbm_device* pGbmDevice);
    static EGLBOOL            IsValidGbmSurface(gbm_surface* pGbmSurface);
    static gbm_bo*            GetFreeGbmBo(gbm_surface* pGbmSurface);
    static EGLINT             SetFrontGbmBo(gbm_surface* pGbmSurface, gbm_bo* pGbmBo);

    static EGLUINT            GetGbmSurfaceFormat(gbm_surface* pGbmSurface);
    static EGLUINT            GetGbmSurfaceWidth(gbm_surface* pGbmSurface);
    static EGLUINT            GetGbmSurfaceHeight(gbm_surface* pGbmSurface);

    static EGLBOOL            IsGbmBoProtected(gbm_bo* pGbmBo);
    static EGLBOOL            IsGbmBoUbwcEnabled(gbm_bo* pGbmBo);
    static EGLUINT            GetGbmBoGlobalName(gbm_bo* pGbmBo);
    static EGLUINT            GetGbmBoFormat(gbm_bo* pGbmBo);
    static EGLUINT            GetGbmBoWidth(gbm_bo* pGbmBo);
    static EGLUINT            GetGbmBoHeight(gbm_bo* pGbmBo);
    static EGLUINT            GetGbmBoAlignedWidth(gbm_bo* pGbmBo);
    static EGLUINT            GetGbmBoAlignedHeight(gbm_bo* pGbmBo);
    static EGLUINT            GetGbmBoStride(gbm_bo* pGbmBo);
    static EGLSIZE_T          GetGbmBoSize(gbm_bo* pGbmBo);
    static EGLVOID*           GetGbmBoCpuAddress(gbm_bo* pGbmBo);
    static EGLUINT64          GetGbmBoRgbDataOffset(gbm_bo* pGbmBo);
    static EGLUINT64          GetGbmBoGpuAddress(gbm_bo* pGbmBo);
    static EGLVOID            SetGbmBoGpuAddress(gbm_bo* pGbmBo, EglMemoryDesc* pMemoryDesc);
    static EGLINT             GetGbmBoIonFd(gbm_bo* pGbmBo);
    static EGLINT             GetGbmBoMetadataFd(gbm_bo* pGbmBo);
    static EglFormatQualifier GetGbmBoEglFormatQualifier(gbm_bo* pGbmBo);
    static EGLUINT            GetGbmBufInfoWidth(gbm_buf_info* pGbmBufInfo);
    static EGLUINT            GetGbmBufInfoHeight(gbm_buf_info* pGbmBufInfo);
    static EGLUINT            GetGbmBufInfoFormat(gbm_buf_info* pGbmBufInfo);
    static EGLBOOL            GetGbmBufInfoFromWlResource(EGLVOID* pWlResource, gbm_buf_info* pGbmBufInfo);
    static EGLUINT64          GetGbmBoPlaneOffset(gbm_bo* pGbmBo, EGLUINT planeId);
    static EGLUINT            GetGbmBoPlaneStride(gbm_bo* pGbmBo, EGLUINT planeId);
    static EGLVOID            DestroyGbmBufInfo(gbm_buf_info* pGbmBufInfo);
    static gbm_device*        CreateGbmDeviceForDefaultDisplay();
    static EGLINT             GpuUnmapMemory(EGLVOID* data, EGLUINT32 data_size);

    virtual EGLVOID           Destroy();

    gbm_buf_info*             CreateGbmBufInfo(EGLINT  fd,
                                               EGLINT  metadataFd,
                                               EGLUINT width,
                                               EGLUINT height,
                                               EGLUINT gbmFormat);
    gbm_bo*                   CreateGbmBo(EglGbmBoCreateData* pCreateData);
    gbm_bo*                   ImportGbmBo(EGLUINT globalName);
    gbm_bo*                   ImportGbmBoFromFD(EGLVOID* fd);
    gbm_bo*                   ImportGbmBoFromGbmBufInfo(gbm_buf_info* pGbmBufferInfo);
    EGLVOID                   DestroyGbmBo(gbm_bo* pGbmBo);
    EGLVOID                   PerformGbmBoCacheInvalidate(gbm_bo* pGbmBo);
    EGLVOID                   PerformGbmBoCacheFlush(gbm_bo* pGbmBo);
    EGLBOOL                   AuthenticateMagic(EGLUINT magic);

    /// Returns the primary device name
    EGL_INLINE const EGLCHAR* GetDeviceName() { return m_deviceName; }

    /// Returns the fallback device name
    EGL_INLINE const EGLCHAR* GetFallbackDeviceName() { return m_fallbackdeviceName; }

protected:
    static gbm_device* CreateGbmDevice(const EGLINT   gbmDeviceName);
    static gbm_device* CreateGbmDevice(const EGLCHAR* pPath);
    static gbm_device* CreateGbmDeviceFromFd(EGLINT gbmDeviceFD);
    static EGLVOID     DestroyGbmDevice(gbm_device* pGbmDevice);

    explicit EglGbmUtils(gbm_device* pGbmDevice);
    /// Default Constructor
    EglGbmUtils()
    {
#if defined(ENABLE_DYNAMIC_SYMBOL_LOADING)
        m_pGbmBufferBackend = NULL;
#endif // ENABLE_DYNAMIC_SYMBOL_LOADING
    }

    virtual ~EglGbmUtils();

    gbm_device*     m_pGbmDevice;               ///< Gbm device
    EGLCHAR         m_deviceName[MaxDeviceNameLength];                  ///< Device name
    EGLCHAR         m_fallbackdeviceName[MaxDeviceNameLength];          ///< Fallback Device name

private:

///@todo (ESX-10437) Avoid the Dynamic Linking
#if defined(ENABLE_DYNAMIC_SYMBOL_LOADING)
    // Handle for the symbolic link
    void*                      m_pGbmBufferBackend;        ///< Gbm Buffer Backend
#endif // ENABLE_DYNAMIC_SYMBOL_LOADING

    EglGbmUtils(const EglGbmUtils&);            ///< Disallow the copy constructor
    EglGbmUtils& operator=(const EglGbmUtils&); ///< Disallow assignment operator
    EGLBOOL Init();
};

#endif // EGLGBMUTILS_H
