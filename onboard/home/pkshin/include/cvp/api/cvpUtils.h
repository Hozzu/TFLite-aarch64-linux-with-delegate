/**=============================================================================

@file
   cvpUtils.h

@brief
   API Definition for Computer Vision Processor.

Copyright (c) 2017-2018 Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.

=============================================================================**/

//=============================================================================
///@details CVP Utility API that use Computer Vision Processor acceleration
///@ingroup cvp_utils
//=============================================================================

#ifndef CVP_UTILS_H
#define CVP_UTILS_H

#include "cvpTypes.h"

#ifdef __cplusplus
extern "C"
{
#endif

//------------------------------------------------------------------------------
/// @brief
///    Float to fix point conversion.
/// @param nIn
///    [Input] A floating point number.
/// @param pOut
///    [Output] A pointer to Q format fixed point number that has the fractional bit
///    specified by nQFracBit. If there is loss of precision, it will round to
///    the closest possible value. E.g. nIn = 4.5, nQFracBit = 0, then nOut = 5.
/// @param nQFracBit
///    [Input] Q fractional bit. For example, if the Q format is Q13.2 that has
///    13 integer bit and 2 fractional bit, the nQFracBit is equal to 2.
///
/// @retval CVP_SUCCESS
///    If successfully.
/// @retval CVP_EBADPARAM
///    If there is any bad parameter.
///
/// @ingroup cvp_utils
//------------------------------------------------------------------------------
CVP_API cvpStatus cvpFloatToFixf32u16(float32_t  nIn,
                                      uint16_t  *pOut,
                                      uint8_t    nQFracBit);

//------------------------------------------------------------------------------
/// @brief
///    Float to fix point conversion.
/// @param nIn
///    [Input] A pointer to Q format fixed point number that has the fractional bit
///    specified by nQFracBit.
/// @param pOut
///    [Output] Pointer to a floating point number.
/// @param nQFracBit
///    [Input] Q fractional bit. For example, if the Q format is Q13.2 that has
///    13 integer bit and 2 fractional bit, the nQFracBit is equal to 2.
///
/// @retval CVP_SUCCESS
///    If successfully.
/// @retval CVP_EBADPARAM
///    If there is any bad parameter.
///
/// @ingroup cvp_utils
//------------------------------------------------------------------------------
CVP_API cvpStatus cvpFixToFloatu16f32(uint16_t   nIn,
                                      float32_t *pOut,
                                      uint8_t    nQFracBit);

//------------------------------------------------------------------------------
/// @brief
///    Query image information based on the color format, width, and height.
/// @param eFormat
///    [Input] Enum representing the color format of the image.
/// @param nWidth
///    [Input] Width of the Image.
/// @param nHeight
///    [Input] Height of the Image.
/// @param sImageInfo
///    [Output] Pointer to the image information structure.
///
/// @retval CVP_SUCCESS
///    If successfully.
/// @retval CVP_EBADPARAM
///    If there is any bad parameter.
///
/// @ingroup cvp_utils
//------------------------------------------------------------------------------
CVP_API cvpStatus cvpQueryImageInfo(cvpColorFormat eFormat,
                                    uint32_t       nWidth,
                                    uint32_t       nHeight,
                                    cvpImageInfo  *pImageInfo);



//------------------------------------------------------------------------------
/// @brief
///    Convert UBWC to Linear (OR) Linear to UBWC.
/// @param imgSrc
///    Input pointer of source buffer.
///        NOTE: data should be 4096-bytes aligned.
///              And, DMA HW processing happens in tiles of 32x8.
///              So, allocate memory for source buffer with size of 'srcStride x height' in multiples of 32x8 respectively.
/// @param width
///    Frame Width of the Image.
/// @param height
///    Frame Height of the Image.
/// @param srcStride
///    Frame stride of the Image.
///        NOTE: Frame Stride should be multiple of 32-bytes.
/// @param srcFormat
///    Source data Format CVP_COLORFORMAT_GRAY_8BIT or CVP_COLORFORMAT_GRAY_UBWC. Refer to enum 'cvpColorFormat'.

/// @param imgDst
///    Output pointer of destination buffer.
///        NOTE: data should be 4096-bytes aligned.
///              And, DMA HW processing happens in tiles of 32x8.
///              So, allocate memory for destination buffer with size of 'dstStride x height' in multiples of 32x8 respectively.
/// @param dstStride
///    Destination stride. Frame Stride should be multiple of 32-bytes.
///        NOTE: Currently, make sure dstStride equal to srcStride.
/// @param dstFormat
///    Destination data Format CVP_COLORFORMAT_GRAY_8BIT or CVP_COLORFORMAT_GRAY_UBWC. Refer to enum 'cvpColorFormat'.

///
/// @retval CVP_SUCCESS
///    If successful.
/// @retval CVP_EBADPARAM
///    If there is any bad parameter.
/// @retval CVP_EFAIL
///    If failed.
///
/// @ingroup cvp_utils
//------------------------------------------------------------------------------
CVP_API cvpStatus cvpImgConvert(const uint8_t* imgSrc,
                           uint32_t width,
                           uint32_t height,
                           uint32_t srcStride,
                           cvpColorFormat srcFormat,
                           uint8_t* imgDst,
                           uint32_t dstStride,
                           cvpColorFormat dstFormat);

#ifdef __cplusplus
}//extern "C"
#endif
#endif
