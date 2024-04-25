/**=============================================================================

@file
   cvpNcc.h

@brief
   API Definitions for Normalized Cross Correlation (NCC)

Copyright (c) 2017-2018 Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.

=============================================================================**/

//=============================================================================
///@details CVP NCC APIs using Computer Vision Processor acceleration
///@ingroup cvp_object_detection
//=============================================================================

#ifndef CVP_NCC_H
#define CVP_NCC_H

#include "cvpTypes.h"

#ifdef __cplusplus
extern "C"
{
#endif

//------------------------------------------------------------------------------
/// @brief
///    NCC mode
/// @param CVP_NCC_BEST_SCORE
///    Only give the best result output.
/// @param CVP_NCC_ALL_SCORE
///    Give all NCC score output.
///
/// @ingroup cvp_object_detection
//------------------------------------------------------------------------------
typedef enum
{
   CVP_NCC_BEST_SCORE,
   CVP_NCC_ALL_SCORE
} cvpNccScoreType;

//------------------------------------------------------------------------------
/// @brief
///    Packed structure for NCC search windows.
/// @details
///    NCC search windows can be accessible using either two 64 bit values or
///    a data structure containing all parameter of NCC search window.
///    Locations are in UQ13.2 format
/// @param nWindows
///    Represented by bit 1:0. Number of the last used windows. Possible value
///    is 0, 1, 2, 3. There must be at least one window for NCC search.
///    UQ13.2 means the x and y locations are in quad pixel precision (i.e. floating point
///    precision can be 0, 0.25, 0.5, 0.75).
/// @param nLocX_0
///    Represented by bit 16:2. Top left X position for windows 0.
/// @param nLocY_0
///    Represented by bit 31:17. Top left Y position for windows 0.
/// @param nLocX_1
///    Represented by bit 46:32. Top left X position for windows 1.
/// @param nReserved_0
///    Represented by bit 47. Unused reserved bit.
/// @param nLocY_1
///    Represented by bit 62:48. Top left Y position for windows 1.
/// @param nReserved_1
///    Represented by bit 63. Unused reserved bit.
/// @param nLocX_2
///    Represented by bit 78:64. Top left X position for windows 2.
/// @param nReserved_2
///    Represented by bit 79. Unused reserved bit.
/// @param nLocY_2
///    Represented by bit 94:80. Top left Y position for windows 2.
/// @param nReserved_3
///    Represented by bit 95. Unused reserved bit.
/// @param nLocX_3
///    Represented by bit 110:96. Top left X position for windows 3.
/// @param nReserved_4
///    Represented by bit 111. Unused reserved bit.
/// @param nLocY_3
///    Represented by bit 126:112. Top left Y position for windows 3.
/// @param nReserved_5
///    Represented by bit 127. Unused reserved bit.
/// @ingroup cvp_object_detection
//------------------------------------------------------------------------------
typedef struct _cvpNccWindows
{
   uint64_t nWindows    : 2;    //   1:  0
   uint64_t nLocX_0     : 15;   //  16:  2
   uint64_t nLocY_0     : 15;   //  31: 17
   uint64_t nLocX_1     : 15;   //  46: 32
   uint64_t nReserved_0 : 1;    //  47
   uint64_t nLocY_1     : 15;   //  62: 48
   uint64_t nReserved_1 : 1;    //  63
   uint64_t nLocX_2     : 15;   //  78: 64
   uint64_t nReserved_2 : 1;    //  79
   uint64_t nLocY_2     : 15;   //  94: 80
   uint64_t nReserved_3 : 1;    //  95
   uint64_t nLocX_3     : 15;   // 110: 96
   uint64_t nReserved_4 : 1;    // 111
   uint64_t nLocY_3     : 15;   // 126:112
   uint64_t nReserved_5 : 1;    // 127

   #ifdef __cplusplus
   INLINE _cvpNccWindows()
   {
      memset(this, 0, sizeof (*this));
   }
   #endif
} cvpNccWindows;

//------------------------------------------------------------------------------
/// @brief
///    Structure for NCC output.
/// @param pNccScore
///    Pointer to the NCC score. Min buffer size is nNccScoreSize * sizeof(uint32_t)
///    The score memory layout is depending on eScoreType.
///    If eScoreType == CVP_NCC_BEST_SCORE, then size of buffer is
///    nNccRequests * 4 * 2 bytes. Each template has 4*16 bit for max ref window =4.
///    If num of ref window is not 4, then 0 padding.
///    If eScoreType == CVP_NCC_ALL_SCORE, then size of buffer is
///    nNccRequests * 4 * 12 * 12 * 2 bytes. All score results will be saved as 4x1 pixels in
///    vertical raster scan order.
///    Refer to Programming Guide for details
/// @param pBestPosition
///    Pointer to the structure for the best position for each search window.
///    Min buffer size is nBestPositionSize * sizeof(cvpNccWindows) bytes.
/// @param nNccScoreSize
///    Number of pNccScore.
/// @param nBestPositionSize
///    Number of pBestPosition which is equal to nNccRequests.
///
/// @ingroup cvp_object_detection
//------------------------------------------------------------------------------
typedef struct cvpNccOutput
{
   int16_t        *pNccScore;
   cvpNccWindows  *pBestPosition;
   uint32_t        nNccScoreSize;
   uint32_t        nBestPositionSize;

   #ifdef __cplusplus
   INLINE cvpNccOutput() : pNccScore(NULL), pBestPosition(NULL),
                           nNccScoreSize(0), nBestPositionSize(0){}
   #endif

} cvpNccOutput;

//------------------------------------------------------------------------------
/// @brief
///    The NCC has been processed by the CVP system, and the
///    output is ready to be consumed. This callback is used to notify the
///    application. The application sends the image using the
///    cvpNcc_Async call.
///
/// @param eStatus
///    CVP status for the current process.
/// @param pOutput
///    Pointer to the NCC output structure.
/// @param hNcc
///    Handle for the NCC that was passed in the cvpNcc_Async function.
/// @param pSessionUserData
///    User-data that was set in the cvpInitNcc structure.
/// @param pTaskUserData
///    User-data that was passed in the cvpNcc_Async function
///    which corresponds to this callback.
///
/// @ingroup cvp_object_detection
//------------------------------------------------------------------------------
typedef void (*CvpNccCb)(cvpStatus     eStatus,
                         cvpNccOutput *pOutput,
                         cvpHandle     hNcc,
                         void         *pSessionUserData,
                         void         *pTaskUserData);

//------------------------------------------------------------------------------
/// @brief
///    Structure for NCC configuration.
/// @param sImageInfo
///    Structure for image information.
/// @param eScoreType
///    NCC output score type.
/// @param bSubPelEnable
///    Boolean value showing if NCC SubPel is enabled(True) or disabled(False).
///
/// @ingroup cvp_object_detection
//------------------------------------------------------------------------------
typedef struct _cvpConfigNcc
{
   cvpImageInfo    sImageInfo;
   cvpNccScoreType eScoreType;
   bool            bSubPelEnable;

   #ifdef __cplusplus
   INLINE _cvpConfigNcc() : eScoreType(CVP_NCC_BEST_SCORE), bSubPelEnable(true){}
   #endif

} cvpConfigNcc;

//------------------------------------------------------------------------------
/// @brief
///    Structure for NCC output buffer Requirement
/// @param nNccScoreBytes
///    The required size in bytes for NCC score buffer.
/// @param nBestPositionBytes
///    The required size in bytes for best position buffer.
///
/// @ingroup cvp_object_detection
//------------------------------------------------------------------------------
typedef struct _cvpNccOutBuffReq
{
   uint32_t nNccScoreBytes;
   uint32_t nBestPositionBytes;

   #ifdef __cplusplus
   INLINE _cvpNccOutBuffReq() : nNccScoreBytes(0), nBestPositionBytes(0){}
   #endif

} cvpNccOutBuffReq;

//------------------------------------------------------------------------------
/// @brief
///    Initialize CVP - NCC.
/// @param hSession
///    [Input] CVP session handle
/// @param pConfig
///    [Input] Pointer to the configuration.
/// @param pOutMemReq
///    [Output] Pointer to the output memory requirement.
/// @param nFps
///    [Input] CVP Frames per Second.
/// @param fnCb
///    [Input] Callback function for the asynchronous API
///    Setting to NULL will result in initializing for the synchronous API
/// @param pSessionUserData
///    [Input] A private pointer that user can set with this session, and this
///    pointer will be provided as parameter to all callback functions
///    originated from the current session. This could be used to associate a
///    callback to this session. This can only be set once while initializing
///    the handle. This value will not/cannot-be changed for life
///    of a session.
///
/// @retval CVP handle for NCC.
///    If successful.
/// @retval NULL
///    If initialization failed.
///
/// @ingroup cvp_object_detection
//------------------------------------------------------------------------------
CVP_API cvpHandle cvpInitNcc(cvpSession          hSession,
                             const cvpConfigNcc *pConfig,
                             cvpNccOutBuffReq   *pOutMemReq,
                             uint32_t            nFps,
                             CvpNccCb            fnCb,
                             void               *pSessionUserData);

//------------------------------------------------------------------------------
/// @brief
///    Deinitialize CVP - NCC.
/// @param hNcc
///    [Input] CVP handle for NCC.
///
/// @retval CVP_SUCCESS
///    If deinit is successful.
///
/// @ingroup cvp_object_detection
//------------------------------------------------------------------------------
CVP_API cvpStatus cvpDeInitNcc(cvpHandle hNcc);

//------------------------------------------------------------------------------
/// @brief
///    NCC.
/// @details
///    Synchronous (blocking) function that will do NCC.
/// @param hNcc
///    [Input] Handle for the NCC.
/// @param pReferenceImage
///    [Input] Pointer to the reference image. Max resolution is 1920x1080.
/// @param pTemplateBuffer
///    [Input] Pointer to 8x8 templates. It's 1 byte per pixel.
///    Size of buffer is nNccRequests * 8 * 8 bytes.
/// @param pSearchWindows
///    [Input] Pointer to the search windows structure.
///    Size of buffer is nNccRequests * sizeof(cvpNccWindows) bytes.
///    For each template and each search window, there will be 11*11 searches.
/// @param nNccRequests
///    [Input] Number of NCC requests. Max is 750.
/// @param pOutput
///    [Output] Pointer to the NCC ouput structure.
///
/// @retval CVP_SUCCESS
///    If the image is successfully pushed to the queue. It will be processed
///    immediately.
/// @retval CVP_EBADPARAM
///    If there is any bad parameter.
///
/// @ingroup cvp_object_detection
//------------------------------------------------------------------------------
CVP_API cvpStatus cvpNcc_Sync(cvpHandle       hNcc,
                              const cvpImage *pReferenceImage,
                              uint8_t        *pTemplateBuffer,
                              cvpNccWindows  *pSearchWindows,
                              uint32_t        nNccRequests,
                              cvpNccOutput   *pOutput);

//------------------------------------------------------------------------------
/// @brief
///    NCC.
/// @details
///    Asynchronous function that will queue the image and return almost
///    immediately. In the background, it will do NCC.
///    Once the output is ready, it will notify the user through the callback
///    function and user can queue another image using the same buffer.
/// @param hNcc
///    [Input] Handle for the NCC.
/// @param pReferenceImage
///    [Input] Pointer to the reference image. Max resolution is 1920x1080.
/// @param pTemplateBuffer
///    [Input] Pointer to 8x8 templates. It's 1 byte per pixel.
///    Size of buffer is nNccRequests * 8 * 8 bytes.
/// @param pSearchWindows
///    [Input] Pointer to the search windows structure.
///    Size of buffer is nNccRequests * sizeof(cvpNccWindows) bytes.
///    For each template and each search window, there will be 11*11 searches.
/// @param nNccRequests
///    [Input] Number of NCC requests. Max is 750.
/// @param pOutput
///    [Output] Pointer to the NCC ouput structure which  corresponds to
///    the callback.
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
/// @ingroup cvp_object_detection
//------------------------------------------------------------------------------
CVP_API cvpStatus cvpNcc_Async(cvpHandle       hNcc,
                               const cvpImage *pReferenceImage,
                               uint8_t        *pTemplateBuffer,
                               cvpNccWindows  *pSearchWindows,
                               uint32_t        nNccRequests,
                               cvpNccOutput   *pOutput,
                               const void     *pTaskUserData);

#ifdef __cplusplus
}//extern "C"
#endif

#endif
