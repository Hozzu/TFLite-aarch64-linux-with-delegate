/**=============================================================================

@file
   cvpFeaturePoint.h

@brief
   API Definitions for Feature Point Extraction (FPX)

Copyright (c) 2018 Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.

=============================================================================**/

//=============================================================================
///@details CVP Feature Point Extraction (FPX) APIs using Computer Vision Processor acceleration
///@ingroup cvp_feature_detection
//=============================================================================

#ifndef CVP_FEATURE_POINT_H
#define CVP_FEATURE_POINT_H

#include "cvpTypes.h"

#ifdef __cplusplus
extern "C"
{
#endif

//------------------------------------------------------------------------------
/// @brief
///    Feature Point Extraction (FPX) mode
/// @param CVP_FPX_PEAK_8x8
///    One feature point is detected in each 8x8 block.
/// @param CVP_FPX_ZONE
///    Top 8 feature points per zone are written out.
///
/// @ingroup cvp_feature_detection
//------------------------------------------------------------------------------
typedef enum
{
   CVP_FPX_PEAK_8x8,
   CVP_FPX_ZONE
} cvpFpxMode;

//------------------------------------------------------------------------------
/// @brief
///    Configuration structure for Feature Point Extraction specific to Zone mode.
///    The zone width and height are defined as the number of 8x8 blocks.
/// @param nZoneWidth
///    Zone width. This should be an even number. Min is 2 and max is 30.
/// @param nZoneHeight
///    Zone height. This should be an even number. Min is 2 and max is 30.
///
/// @ingroup cvp_feature_detection
//------------------------------------------------------------------------------
typedef struct _cvpConfigFpxZone
{
   uint32_t nZoneWidth;
   uint32_t nZoneHeight;

   #ifdef __cplusplus
   INLINE _cvpConfigFpxZone() : nZoneWidth(2), nZoneHeight(2){}
   #endif

} cvpConfigFpxZone;

//------------------------------------------------------------------------------
/// @brief
///    Structure for feature point extraction (FPX) configuration.
/// @param sImageInfo
///    Structure for the image information.
/// @param eMode
///    Enum representing the FPX mode.
/// @param nRobustness
///    This parameter controls the robustness of the feature point detector.
///    Lower robustness setting produces more candidate feature points and vice versa.
///    Valid range is 0 to 127. Default value is 10.
/// @param sZoneConfig
///    Configuration for Zone mode. It will be used only if eMode is
///    CVP_FPX_ZONE.
///
/// @ingroup cvp_feature_detection
//------------------------------------------------------------------------------
typedef struct _cvpConfigFpx
{
   cvpImageInfo     sImageInfo;
   cvpFpxMode       eMode;
   uint8_t          nRobustness;
   cvpConfigFpxZone sZoneConfig;

   #ifdef __cplusplus
   INLINE _cvpConfigFpx() : eMode(CVP_FPX_PEAK_8x8), nRobustness(10){}
   #endif

} cvpConfigFpx;

//------------------------------------------------------------------------------
/// @brief
///    Structure for FPX output buffer requirement.
/// @param nFeaturePointBytes
///    The required size in bytes for feature point output.
/// @param eMode
///    Enum representing the FPX mode.
///
/// @ingroup cvp_object_detection
//------------------------------------------------------------------------------
typedef struct _cvpFeaturePointOutBuffReq
{
   uint32_t   nFeaturePointBytes;
   cvpFpxMode eMode;

   #ifdef __cplusplus
   INLINE _cvpFeaturePointOutBuffReq() : nFeaturePointBytes(0), eMode(CVP_FPX_PEAK_8x8){}
   #endif

} cvpFeaturePointOutBuffReq;

//------------------------------------------------------------------------------
/// @brief
///    Structure representing feature point extraction (FPX) 64-bit data point.
/// @param nLocX
///    The x coordinate.
/// @param nLocY
///    The y coordinate.
/// @param nScore
///    The score.
/// @param nPadding
///    Unused, for padding.
///
/// @ingroup cvp_feature_detection
//------------------------------------------------------------------------------
typedef struct _cvpFeaturePointData
{
   uint16_t nLocX;
   uint16_t nLocY;
   uint16_t nScore;
   uint16_t nPadding;

   #ifdef __cplusplus
   INLINE _cvpFeaturePointData() : nLocX(0), nLocY(0),
                                   nScore(0), nPadding(0){}
   #endif

} cvpFeaturePointData;

//------------------------------------------------------------------------------
/// @brief
///    Struct representing feature point extraction (FPX) output depending on the chosen
///    mode.
/// @param pFeaturePoints
///    Pointer to the output depending on the chosen mode.
/// @param pPeak8x8
///    Pointer to the 64-bit data point if CVP_FPX_PEAK_8x8 was chosen.
///    In raster scan order, within 16x16, vertical raster scan order. Refer to Programming Guide.
/// @param pZone
///    Pointer to the 64-bit data point if CVP_FPX_ZONE was chosen.
///    In zone raster scan order, top 8 for each zone.
/// @param nWidth
///    If CVP_FPX_PEAK_8x8 was chosen, it is the number of 8x8 blocks along the image width.
///    If CVP_FPX_ZONE was chosen, it is the number of zones along the image width.
/// @param nHeight
///    If CVP_FPX_PEAK_8x8 was chosen, it is the number of 8x8 blocks along the image height.
///    If CVP_FPX_ZONE was chosen, it is the number of zones along the image height.
/// @param nSize
///    Number of pFeaturePoints data.
/// @param nMaxFpxScore
///    Maximum FPX score. This value is used to calculate the next feature point
///    score shift using cvpGetFpxScoreShift().
///
/// @ingroup cvp_feature_detection
//------------------------------------------------------------------------------
typedef struct _cvpFeaturePointOutput
{
   union
   {
      cvpFeaturePointData  *pPeak8x8;
      cvpFeaturePointData  *pZone;
   } pFeaturePoints;
   uint32_t nWidth;
   uint32_t nHeight;
   uint32_t nSize;
   uint32_t nMaxFpxScore;

   #ifdef __cplusplus
   INLINE _cvpFeaturePointOutput() : nWidth(0), nHeight(0),
                                     nSize(0), nMaxFpxScore(0)
   {
      pFeaturePoints.pPeak8x8 = NULL;
   }
   #endif

} cvpFeaturePointOutput;

//------------------------------------------------------------------------------
/// @brief
///    The feature point has been processed by the CVP system, and the
///    output is ready to be consumed. This callback is used to notify the
///    application. The application sends the image using the
///    cvpFeaturePoint_Async call.
///
/// @param eStatus
///    CVP status for the current process.
/// @param pOutput
///    Pointer to the feature point ouput structure.
/// @param hFpx
///    Handle for the feature point extraction that was passed in the
///    cvpFeaturePoint_Async function.
/// @param pSessionUserData
///    User-data that was set in the cvpInitFeaturePoint structure.
/// @param pTaskUserData
///    User-data that was passed in the cvpFeaturePoint_Async function
///    which corresponds to this callback.
///
/// @ingroup cvp_feature_detection
//------------------------------------------------------------------------------
typedef void (*CvpFpxCb)(cvpStatus              eStatus,
                         cvpFeaturePointOutput *pOutput,
                         cvpHandle              hFpx,
                         void                  *pSessionUserData,
                         void                  *pTaskUserData);

//------------------------------------------------------------------------------
/// @brief
///    Initialize CVP - Feature Point Extraction (FPX).
/// @param hSession
///    [Input] CVP session handle
/// @param pConfig
///    [Input] Pointer to the configuration structure
///    [Output] sZoneConfig (nZoneWidth and nZoneHeight) will be adjusted based
///    on the valid range.
/// @param pOutMemReq
///    [Output] Pointer to the output memory requirement structure
/// @param nFps
///    [Input] CVP Frames per Second.
/// @param fnCb
///    [Input] Callback function for the asynchronous API
///    Setting to NULL will result in initializing for synchronous API
/// @param pSessionUserData
///    [Input] A private pointer that user can set with this session, and this
///    pointer will be provided as parameter to all callback functions
///    originated from the current session. This could be used to associate a
///    callback to this session. This can only be set once while initializing
///    the FPX handle. This value will not/cannot-be changed for life
///    of a session.
///
/// @retval CVP handle for Feature Point Extraction (FPX).
///    If successful.
/// @retval NULL
///    If initialization failed.
///
/// @ingroup cvp_feature_detection
//------------------------------------------------------------------------------
CVP_API cvpHandle cvpInitFeaturePoint(cvpSession                  hSession,
                                      cvpConfigFpx               *pConfig,
                                      cvpFeaturePointOutBuffReq  *pOutMemReq,
                                      uint32_t                    nFps,
                                      CvpFpxCb                    fnCb,
                                      void                       *pSessionUserData);

//------------------------------------------------------------------------------
/// @brief
///    Deinitialize CVP - Feature Point Extraction (FPX).
/// @param hFpx
///    [Input] CVP handle for Feature Point Extraction (FPX).
///
/// @retval CVP_SUCCESS
///    If deinit is successful.
///
/// @ingroup cvp_feature_detection
//------------------------------------------------------------------------------
CVP_API cvpStatus cvpDeInitFeaturePoint(cvpHandle hFpx);

//------------------------------------------------------------------------------
/// @brief
///    Feature Point Extraction (FPX).
/// @details
///    Synchronous (blocking) function that will do Feature Point Extraction (FPX).
/// @param hFpx
///    [Input] Handle for the Feature Point Extraction (FPX).
/// @param pImage
///    [Input] Pointer to the CVP image.
/// @param nFpxScoreShift
///    [Input] FPX score shift value. This value can be calculated by calling
///    cvpGetFpxScoreShift() using the previous result in
///    pOutput->nMaxFpxScore. It's suggested to set to 8 for the first call.
/// @param nThreshold
///    [Input] Threshold to filter the feature point extraction score.
/// @param pOutput
///    [Output] Pointer to the Feature Point Extraction (FPX) output structure.
///
/// @retval CVP_SUCCESS
///    If the image is successfully pushed to the queue. It will be processed
///    immediately.
/// @retval CVP_EBADPARAM
///    If there is any bad parameter.
///
/// @ingroup cvp_feature_detection
//------------------------------------------------------------------------------
CVP_API cvpStatus cvpFeaturePoint_Sync(cvpHandle              hFpx,
                                       const cvpImage        *pImage,
                                       uint32_t               nFpxScoreShift,
                                       uint32_t               nThreshold,
                                       cvpFeaturePointOutput *pOutput);

//------------------------------------------------------------------------------
/// @brief
///    Feature Point Extraction (FPX).
/// @details
///    Asynchronous function that will queue the image and returns almost
///    immediately. In the background, it will do Feature Point Extraction (FPX).
///    Once the output is ready, it will notify the user through the callback
///    function and user can queue another image using the same buffer.
/// @param hFpx
///    [Input] Handle for the Feature Point Extraction (FPX).
/// @param pImage
///    [Input] Pointer to the CVP image.
/// @param nFpxScoreShift
///    [Input] FPX score shift value. This value can be calculated by calling
///    cvpGetFpxScoreShift() using the previous result in
///    pOutput->nMaxFpxScore. It's suggested to set to 8 for the first call.
/// @param nThreshold
///    [Input] Threshold to filter the feature point extraction score.
/// @param pOutput
///    [Output] Pointer to the Feature Point Extraction (FPX) ouput structure
///    which corresponds to the callback.
/// @param pTaskUserData
///    [Input] User-data which corresponds to the callback.
///
/// @retval CVP_SUCCESS
///    If the image is successfully pushed to the queue. It will be processed
///    immediately.
/// @retval CVP_EBADPARAM
///    If there is any bad parameter.
/// @retval CVP_EUNSUPPORTED
///    If the handle is initialized for the synchronous API.
///
/// @ingroup cvp_feature_detection
//------------------------------------------------------------------------------
CVP_API cvpStatus cvpFeaturePoint_Async(cvpHandle              hFpx,
                                        const cvpImage        *pImage,
                                        uint32_t               nFpxScoreShift,
                                        uint32_t               nThreshold,
                                        cvpFeaturePointOutput *pOutput,
                                        const void            *pTaskUserData);

//------------------------------------------------------------------------------
/// @brief
///    Calculate feature point score shift based on maximum FPX score from
///    previous frame.
/// @param nMaxFpxScore
///    [Input] Previous maximum FPX score.
///
/// @retval nFpxScoreShift
///
/// @ingroup cvp_feature_detection
//------------------------------------------------------------------------------
CVP_API uint32_t cvpGetFpxScoreShift(uint32_t nMaxFpxScore);
//------------------------------------------------------------------------------
/// @brief
///    Calculate the adjusted zone width and zone height based on CVP Hardware
///    requirements.
/// @param pZoneConfig
///    [Input] / [Output] User to set initial values for ConfigFpxZone.
///    These will be adjusted based on CVP Hardware requirements.
/// @param nFrameWidthIn
///    [Input] Frame Width.
/// @param nFrameHeightIn
///    [Input] Frame Height.
///
/// @retval CVP_SUCCESS
///    If the operation is successful
/// @retval CVP_EBADPARAM
///    If there is any bad parameter.
///
/// @ingroup cvp_feature_detection
//------------------------------------------------------------------------------
CVP_API cvpStatus cvpFpxAdjustZoneDim(cvpConfigFpxZone  *pZoneConfig,
                                      uint32_t           nFrameWidthIn,
                                      uint32_t           nFrameHeightIn);
#ifdef __cplusplus
}//extern "C"
#endif
#endif
