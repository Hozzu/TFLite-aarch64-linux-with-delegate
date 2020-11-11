/**=============================================================================

@file
   cvpDfs.h

@brief
   API Definitions for Depth From Stereo (DFS)

Copyright (c) 2017-2018 Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.

=============================================================================**/

//=============================================================================
///@details CVP DFS APIs using Computer Vision Processor acceleration
///@ingroup cvp_3D_reconstruction
//=============================================================================

#ifndef CVP_DFS_H
#define CVP_DFS_H

#include "cvpTypes.h"

#ifdef __cplusplus
extern "C"
{
#endif

//------------------------------------------------------------------------------
/// @brief
///    Structure representing DFS output
/// @param pDisparityMap
///    Pointer to the Disparity Map.
/// @param pOcclusionMask
///    Pointer to the occlusion mask. This will be NULL if bOcclusionMaskEnable
///    is set to false. One bit per occlusion mask.
/// @param nDisparityMapSize
///    Number of pDisparityMap
/// @param nOcclusionMaskSize
///    Number of pOcclusionMask
/// @ingroup cvp_3D_reconstruction
//------------------------------------------------------------------------------
typedef struct _cvpDfsOutput
{
   uint8_t *pDisparityMap;
   uint8_t *pOcclusionMask;
   uint32_t nDisparityMapSize;
   uint32_t nOcclusionMaskSize;

   #ifdef __cplusplus
   INLINE _cvpDfsOutput() : pDisparityMap(NULL), pOcclusionMask(NULL),
                            nDisparityMapSize(0), nOcclusionMaskSize(0){}
   #endif
} cvpDfsOutput;

//------------------------------------------------------------------------------
/// @brief
///    The DFS has been processed by the CVP system, and the
///    output is ready to be consumed. This callback is used to notify the
///    application. The application sends the image using the
///    cvpDfs_Async call.
///
/// @param eStatus
///    CVP status for the current process.
/// @param pOutput
///    Pointer to the DFS ouput structure.
/// @param hDfs
///    Handle for the DFS that was passed in the cvpDfs_Async function.
/// @param pSessionUserData
///    User-data that was set in the cvpInitDfs structure.
/// @param pTaskUserData
///    User-data that was passed in the cvpDfs_Async function
///    which corresponds to this callback.
///
/// @ingroup cvp_3D_reconstruction
//------------------------------------------------------------------------------
typedef void (*CvpDfsCb)(cvpStatus     eStatus,
                         cvpDfsOutput *pOutput,
                         cvpHandle     hDfs,
                         void         *pSessionUserData,
                         void         *pTaskUserData);


//------------------------------------------------------------------------------
/// @brief
///    Structure for depth from stereo (DFS) configuration.
/// @param sLeftImageInfo
///    Structure for the left image information.
/// @param sRightImageInfo
///    Structure for the right image information.
/// @param nMaxDisparity
///    [Input] Max disparity in integer precision. Range: 4-64. Numbers outside this range
///    are not supported.
/// @param nDisparityOffset
///    Valid range is [0, 254-nMaxDisparity]
///    Default value is 0 depending on camera calibration.
/// @param bOcclusionMaskEnable
///    Flag to enable occlusion mask
///    When enabled, occlusion mask output will be available. Otherwise, occlusion mask
///    output will be skipped
/// @param bMedianFilterEnable
///    Flag to enable median filter
/// @param bOcclusionFillingEnable
///    Flag to enable filling
///
/// @ingroup cvp_3D_reconstruction
//------------------------------------------------------------------------------
typedef struct _cvpConfigDfs
{
   cvpImageInfo sLeftImageInfo;
   cvpImageInfo sRightImageInfo;
   uint32_t     nMaxDisparity;
   uint32_t     nDisparityOffset;
   bool         bOcclusionMaskEnable;
   bool         bMedianFilterEnable;
   bool         bOcclusionFillingEnable;

   #ifdef __cplusplus
   INLINE _cvpConfigDfs() : nMaxDisparity(0), nDisparityOffset(0),
                            bOcclusionMaskEnable(false), bMedianFilterEnable(false),
                            bOcclusionFillingEnable(false){}
   #endif
} cvpConfigDfs;

//------------------------------------------------------------------------------
/// @brief
///    Structure for DFS output buffer requirement
/// @param nDisparityMapBytes
///    The required size in bytes for disparity map.
/// @param nOcclusionMaskBytes
///    The required size in bytes for occlusion mask.
///
/// @ingroup cvp_3D_reconstruction
//------------------------------------------------------------------------------
typedef struct _cvpDfsOutBuffReq
{
   uint32_t nDisparityMapBytes;
   uint32_t nOcclusionMaskBytes;

   #ifdef __cplusplus
   INLINE _cvpDfsOutBuffReq() : nDisparityMapBytes(0), nOcclusionMaskBytes(0){}
   #endif
} cvpDfsOutBuffReq;

//------------------------------------------------------------------------------
/// @brief
///    Initialize CVP - Depth From Stereo (DFS).
/// @param hSession
///    [Input] CVP session handle
/// @param pConfig
///    [Input] Pointer to the DFS configuration.
/// @param pOutMemReq
///    [Output] Pointer to the output memory requirement.
/// @param nFps
///    [Input] CVP Frames per Second.
/// @param fnCb
///    [Input] Callback function for the asynchronous API
///    Setting to NULL will result in initializing for synchronous API
/// @param pSessionUserData
///    [Input] A private pointer the user can set with this session, and this
///    pointer will be provided as parameter to all callback functions
///    originated from the current session. This could be used to associate a
///    callback to this session. This can only be set once while initializing
///    the handle. This value will not/cannot-be changed for life
///    of a session.
///
/// @retval CVP handle for DFS.
///    If successful.
/// @retval NULL
///    If initialization failed.
///
/// @ingroup cvp_3D_reconstruction
//------------------------------------------------------------------------------
CVP_API cvpHandle cvpInitDfs(cvpSession          hSession,
                             const cvpConfigDfs *pConfig,
                             cvpDfsOutBuffReq   *pOutMemReq,
                             uint32_t            nFps,
                             CvpDfsCb            fnCb,
                             void               *pSessionUserData);

//------------------------------------------------------------------------------
/// @brief
///    Deinitialize CVP - Depth From Stereo (DFS).
/// @param hDfs
///    [Input] CVP handle for DFS.
///
/// @retval CVP_SUCCESS
///    If deinit is successful.
///
/// @ingroup cvp_3D_reconstruction
//------------------------------------------------------------------------------
CVP_API cvpStatus cvpDeInitDfs(cvpHandle hDfs);

//------------------------------------------------------------------------------
/// @brief
///    Depth From Stereo (DFS).
/// @details
///    Synchronous (blocking) function that will do DFS.
/// @param hDfs
///    [Input] Handle for the DFS.
/// @param pLeftImage
///    [Input] Pointer to the left image. The width and height for both left and
///    right images must be the same.
/// @param pRightImage
///    [Input] Pointer to the right image. The width and height for both left and
///    right images must be the same.
/// @param nOcclusionMinThreshold
///    [Input] Lower bound for adjusting Occlusion cost threshold, range [0-100],
///     recommended range 50-75. nOcclusionMinThreshold <= nOcclusionThreshold
/// @param nOcclusionThreshold
///    [Input] Occlusion cost threshold, range [0-100], recommended range 50-75.
/// @param pOutput
///    [Output] Pointer to the DFS ouput structure.
///
/// @retval CVP_SUCCESS
///    If the image is successfully pushed to the queue. It will be processed
///    immediately.
/// @retval CVP_EBADPARAM
///    If there is any bad parameter.
///
/// @ingroup cvp_3D_reconstruction
//------------------------------------------------------------------------------
CVP_API cvpStatus cvpDfs_Sync(cvpHandle       hDfs,
                              const cvpImage *pLeftImage,
                              const cvpImage *pRightImage,
                              uint32_t        nOcclusionMinThreshold,
                              uint32_t        nOcclusionThreshold,
                              cvpDfsOutput   *pOutput);

//------------------------------------------------------------------------------
/// @brief
///    Depth From Stereo (DFS).
/// @details
///    Asynchronous function that will queue the image and return almost
///    immediately. In the background, it will do DFS.
///    Once the output is ready, it will notify the user through the callback
///    function and user can queue another image using the same buffer.
/// @param hDfs
///    [Input] Handle for the DFS.
/// @param pLeftImage
///    [Input] Pointer to the left image. The width and height for both left and
///    right images must be the same.
/// @param pRightImage
///    [Input] Pointer to the right image. The width and height for both left and
///    right images must be the same.
/// @param nOcclusionMinThreshold
///    [Input] Lower bound for adjusting Occlusion cost threshold, range [0-100],
///     recommended range 50-75. nOcclusionMinThreshold <= nOcclusionThreshold
/// @param nOcclusionThreshold
///    [Input] Occlusion cost threshold, range [0-100], recommended range 50-75.
/// @param pOutput
///    [Output] Pointer to the DFS ouput structure which corresponds to the
///    callback.
/// @param pTaskUserData
///    [Input] Pointer to user-data buffer which corresponds to the callback.
///
/// @retval CVP_SUCCESS
///    If the image is successfully pushed to the queue. It will be processed
///    immediately.
/// @retval CVP_EBADPARAM
///    If there is any bad parameter.
/// @retval CVP_EUNSUPPORTED
///    If the handle is initialized for the synchronous API.
///
/// @ingroup cvp_3D_reconstruction
//------------------------------------------------------------------------------
CVP_API cvpStatus cvpDfs_Async(cvpHandle       hDfs,
                               const cvpImage *pLeftImage,
                               const cvpImage *pRightImage,
                               uint32_t        nOcclusionMinThreshold,
                               uint32_t        nOcclusionThreshold,
                               cvpDfsOutput   *pOutput,
                               const void     *pTaskUserData);

#ifdef __cplusplus
}//extern "C"
#endif

#endif
