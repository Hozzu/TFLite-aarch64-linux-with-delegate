/*==============================================================================
 *            Copyright (c) 2017-2018 Qualcomm Technologies, Inc.
 *            All Rights Reserved.
 *            Confidential and Proprietary - Qualcomm Technologies, Inc.
==============================================================================*/
#ifndef _VC1DECDSP_H
#define _VC1DECDSP_H
/// @file VC1DecDsp.idl
///
#include "AEEStdDef.h"
#ifndef __QAIC_HEADER
#define __QAIC_HEADER(ff) ff
#endif //__QAIC_HEADER

#ifndef __QAIC_HEADER_EXPORT
#define __QAIC_HEADER_EXPORT
#endif // __QAIC_HEADER_EXPORT

#ifndef __QAIC_HEADER_ATTRIBUTE
#define __QAIC_HEADER_ATTRIBUTE
#endif // __QAIC_HEADER_ATTRIBUTE

#ifndef __QAIC_IMPL
#define __QAIC_IMPL(ff) ff
#endif //__QAIC_IMPL

#ifndef __QAIC_IMPL_EXPORT
#define __QAIC_IMPL_EXPORT
#endif // __QAIC_IMPL_EXPORT

#ifndef __QAIC_IMPL_ATTRIBUTE
#define __QAIC_IMPL_ATTRIBUTE
#endif // __QAIC_IMPL_ATTRIBUTE
#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief Max Number of Reference frames
 */
#define VC1DecDsp_MAX_DPB_SIZE 4u
/**
    * Description:
    * Bitstream profile enumeration
    */
enum VC1DecDsp_eProfileT {
   vc1ProfileSimple,
   vc1ProfileMain,
   vc1ProfileReserved,
   vc1ProfileAdvanced,
   _32BIT_PLACEHOLDER_VC1DecDsp_eProfileT = 0x7fffffff
};
typedef enum VC1DecDsp_eProfileT VC1DecDsp_eProfileT;
/** Simple profile */
/** Main profile */
/** Reserved */
/** Advanced profile */
/**
    * @brief Enumeration of Color Formats
 */
enum VC1DecDsp_eOutputColorFormatT {
   COLOR_FORMAT_NV12,
   COLOR_FORMAT_NV21,
   _32BIT_PLACEHOLDER_VC1DecDsp_eOutputColorFormatT = 0x7fffffff
};
typedef enum VC1DecDsp_eOutputColorFormatT VC1DecDsp_eOutputColorFormatT;
/**
    * @struct  sequence_param_t
    *
    * @brief sequence parameters parsed from sequence header
    */
typedef struct VC1DecDsp_SequenceParamsT VC1DecDsp_SequenceParamsT;
struct VC1DecDsp_SequenceParamsT {
   VC1DecDsp_eProfileT profile;
   unsigned int nAllocFrameWidth;
   unsigned int nAllocFrameHeight;
   unsigned int nActualFrameWidth;
   unsigned int nActualFrameHeight;
};
/**
   * @struct  DecoderConfigurationT
   *
   * @brief sequence parameters parsed from sequence header
   */
typedef struct VC1DecDsp_FrameDimensionsT VC1DecDsp_FrameDimensionsT;
struct VC1DecDsp_FrameDimensionsT {
   VC1DecDsp_eProfileT profile;
   unsigned int FrameWidth;
   unsigned int FrameHeight;
   boolean bThumbNailMode;
};
/**
      * @brief Frame Constraints
    */
typedef struct VC1DecDsp_FrameOutPutConstraintsT VC1DecDsp_FrameOutPutConstraintsT;
struct VC1DecDsp_FrameOutPutConstraintsT {
   unsigned int nStrideMultiples; /**< The supported stride multiples
                                                    value. */
   unsigned int nMaxStride; /**< The maximum supported stride for
                                                    this plane. */
   unsigned int nMinPlaneBufferHeightMultiple; /**< The multiple to use to derive the
                                                    minimum plane height (number of
                                                    stride lines associated with the
                                                    plane within the buffer).  The
                                                    minimum plane height is derived by
                                                    rounding up the frame height to the
                                                    next nMinPlaneBufferHeightMultiple
                                                    value. */
   unsigned int nBufferAlignment; /**< The byte alignment requirement for
                                               this plane.  A value of zero denotes
                                               that the port does not have any
                                               alignment restrictions. */
};
/**
      * @brief Frame Attributes
    */
typedef struct VC1DecDsp_FrameOutPutAttributesT VC1DecDsp_FrameOutPutAttributesT;
struct VC1DecDsp_FrameOutPutAttributesT {
   VC1DecDsp_eOutputColorFormatT eFormat; /**< Uncompressed format type.  Refer
                                          HFI_COLOR_FORMAT_X for values */
   VC1DecDsp_FrameOutPutConstraintsT YPlaneFormat; /**< The plane
                                          format constraint information for Y
                                          plane. */
   VC1DecDsp_FrameOutPutConstraintsT UVPlaneFormat; /**< The plane
                                          format constraint information for Y
                                          plane. */
};
/**
     *@brief disbale deblock
      */
typedef struct VC1DecDsp_DeblockEnable VC1DecDsp_DeblockEnable;
struct VC1DecDsp_DeblockEnable {
   boolean bDeblockEnable;
};
/**
     * @brief Decoder Properties
    */
enum VC1DecDsp_VC1DecoderPropertyT {
   VC1DecPropertyFrameAttributes,
   VC1DecPropertyFrameOutPutAttributes,
   VC1DecPropertyDeblockEnable,
   _32BIT_PLACEHOLDER_VC1DecDsp_VC1DecoderPropertyT = 0x7fffffff
};
typedef enum VC1DecDsp_VC1DecoderPropertyT VC1DecDsp_VC1DecoderPropertyT;
/**
     * Internal buffer address
    */
typedef struct VC1DecDsp_InternalBufferAddrT VC1DecDsp_InternalBufferAddrT;
struct VC1DecDsp_InternalBufferAddrT {
   uint64 nInternalbufferAddr;
};
/**
    * Description:
    * Output buffer Flag
    */
enum VC1DecDsp_eOPBufferFlag {
   vc1FlagNone,
   vc1FlagDataCorrupt,
   vc1FlagEOS,
   _32BIT_PLACEHOLDER_VC1DecDsp_eOPBufferFlag = 0x7fffffff
};
typedef enum VC1DecDsp_eOPBufferFlag VC1DecDsp_eOPBufferFlag;
/**
     * Ouput buffer stucture
     */
typedef struct VC1DecDsp_OPBufferT VC1DecDsp_OPBufferT;
struct VC1DecDsp_OPBufferT {
   int FD; /**< pointer to the buffers data space */
   unsigned int RefCount; /**< reference count number on the buffer */
   VC1DecDsp_eOPBufferFlag nflag; /**< flag indicating output data status*/
};
/**
    * @brief    Initialize decoder
    *
     * @param[in][out]       Decoder context handle
    *
     * @return long
    */
__QAIC_HEADER_EXPORT int __QAIC_HEADER(VC1DecDsp_Init)(uint64* DecContextHandle, int DecContextHandleLen) __QAIC_HEADER_ATTRIBUTE;
/**
    * @brief    Deinitialize decoder
    *
     * @param[in][out]      Decoder context handle
     * @param[out]     nAvergeParseTime
     * @param[out]     nAvergeDecodeTime
    *
     * @return         long
    */
__QAIC_HEADER_EXPORT int __QAIC_HEADER(VC1DecDsp_Deinit)(uint64* DecContextHandle, int DecContextHandleLen, uint64* nAvergeParseTime, uint64* nAvergeDecodeTime) __QAIC_HEADER_ATTRIBUTE;
/**
    * @brief    Configure Decoder Parameters
    *
     * @param[in]   Decoder context
     * @param[in]   Decoder property enum
     * @param[in]   pPropertyValue
    *
     * @return  long
    */
__QAIC_HEADER_EXPORT int __QAIC_HEADER(VC1DecDsp_SetParamemter)(const uint64* DecContextHandle, int DecContextHandleLen, const VC1DecDsp_VC1DecoderPropertyT* nPropertyEnum, int nPropertyEnumLen, const uint8* pPropertyValue, int pPropertyValueLen) __QAIC_HEADER_ATTRIBUTE;
/**
    * @brief    Get Internal buffer requirement size
    *
     * @param[in]   DecContextHandle
     * @param[in][out] nTotalbuffsize
     * @param[in][out] nNumInternalBuffers
    *
     * @return long
    */
__QAIC_HEADER_EXPORT int __QAIC_HEADER(VC1DecDsp_GetInternalBufferRequirements)(const uint64* DecContextHandle, int DecContextHandleLen, unsigned int* nTotalbuffsize, int nTotalbuffsizeLen, unsigned int* nNumInternalBuffers, int nNumInternalBuffersLen) __QAIC_HEADER_ATTRIBUTE;
/**
    * @brief   Set the Internal buffer
    *
     * @param[in]   DecContextHandle
     * @param[in][out]   pInternalbufferbase
     * @param[in][out]   nInternalBufferAddrArray
    *
     * @return  long
    */
__QAIC_HEADER_EXPORT int __QAIC_HEADER(VC1DecDsp_SetInternalBufferPointers)(const uint64* DecContextHandle, int DecContextHandleLen, unsigned char* pInternalbufferbase, int pInternalbufferbaseLen, VC1DecDsp_InternalBufferAddrT* nInternalBufferAddrArray, int nInternalBufferAddrArrayLen) __QAIC_HEADER_ATTRIBUTE;
/**
    * @brief   Set the Internal buffer
    *
     * @param[in]   DecContextHandle
     * @param[in]   nInternalMemFD
     * @param[in]   nInternalMemSize
     * @param[in][out]   nInternalBufferAddrArray
    *
     * @return  long
    */
__QAIC_HEADER_EXPORT int __QAIC_HEADER(VC1DecDsp_SetIntermediateBuffers)(const uint64* DecContextHandle, int DecContextHandleLen, unsigned int InternalBufferVdsp, int nInternalMemSize, VC1DecDsp_InternalBufferAddrT* nInternalBufferAddrArray, int nInternalBufferAddrArrayLen) __QAIC_HEADER_ATTRIBUTE;
/**
    * @brief   Set the Internal buffer
    *
     * @param[in]   DecContextHandle
     * @param[in]   pInternalbufferbaseLen
     * @param[in][out]   nInternalBufferAddrArray
    *
     * @return  long
    */
__QAIC_HEADER_EXPORT int __QAIC_HEADER(VC1DecDsp_AllocateAndSetInternalBufferPointers)(const uint64* DecContextHandle, int DecContextHandleLen, unsigned int pInternalbufferbaseLen, VC1DecDsp_InternalBufferAddrT* nInternalBufferAddrArray, int nInternalBufferAddrArrayLen) __QAIC_HEADER_ATTRIBUTE;
/**
    * @brief   Load/Initialize Intermediate context resources
    *
     * @param[in]   DecContextHandle
    *
     * @return  long
    */
__QAIC_HEADER_EXPORT int __QAIC_HEADER(VC1DecDsp_LoadContextResources)(const uint64* DecContextHandle, int DecContextHandleLen) __QAIC_HEADER_ATTRIBUTE;
/**
    * @brief   Load/Initialize Intermediate context resources
    *
     * @param[in]   DecContextHandle
    *
     * @return  long
    */
__QAIC_HEADER_EXPORT int __QAIC_HEADER(VC1DecDsp_UnLoadContextResources)(const uint64* DecContextHandle, int DecContextHandleLen) __QAIC_HEADER_ATTRIBUTE;
/**
    *@brief    Decode Sequence Header
    *
     * @param[in]    pInputBitstream
     * @param[in][out]    pSequenceParams
     * @param[in][out]    bPortReconfigRequired
    *
     * @return   long
    */
__QAIC_HEADER_EXPORT int __QAIC_HEADER(VC1DecDsp_DecodeSequenceHeader)(const uint64* DecContextHandle, int DecContextHandleLen, const unsigned char* pInputBitstream, int pInputBitstreamLen, VC1DecDsp_SequenceParamsT* pSequenceParams, int pSequenceParamsLen, boolean* bPortReconfigRequired) __QAIC_HEADER_ATTRIBUTE;
/**
    *@brief    Parse Picture layer and lower layer and MB level info
    *
    * @param[in]    DecContextHandle
    * @param[in]    pInputBitstream
    * @param[in][out]    nIntermediateBufferAddr
    *
    * @return   long
    */
__QAIC_HEADER_EXPORT int __QAIC_HEADER(VC1DecDsp_ParseFrame)(const uint64* DecContextHandle, int DecContextHandleLen, const unsigned char* pInputBitstream, int pInputBitstreamLen, uint64* nIntermediateBufferAddr) __QAIC_HEADER_ATTRIBUTE;
/**
    * @brief   Decodes a frame and sends it to display
    *
    * @param[in]    DecContextHandle
    * @param[in][out]    nIntermediateBufferAddr
    * @param[in]    outputBufferVaDsp
    * @param[in]    outputBufferSize
    * @param[in][out]    pDPBQ
    * @param[in][out]    OPToDisplay
    *
    * @return long
    */
__QAIC_HEADER_EXPORT int __QAIC_HEADER(VC1DecDsp_DecodeFrameAndDoBufferMangement)(const uint64* DecContextHandle, int DecContextHandleLen, uint64* nIntermediateBufferAddr, int outputBufferFD, unsigned int outputBufferVaDsp, int outputBufferSize, VC1DecDsp_OPBufferT* pDPBQ, int pDPBQLen, VC1DecDsp_OPBufferT* OPToDisplay) __QAIC_HEADER_ATTRIBUTE;
/**
    * @brief   flush DPB
    *
     * @param[in]    DecContextHandle
    *
     * @return  long
     */
__QAIC_HEADER_EXPORT int __QAIC_HEADER(VC1DecDsp_flush)(const uint64* DecContextHandle, int DecContextHandleLen) __QAIC_HEADER_ATTRIBUTE;
/**
     * @brief   Handshake with DSP
    *
     * @param[in]   DecContextHandle
    *
     * @return  long
    */
__QAIC_HEADER_EXPORT int __QAIC_HEADER(VC1DecDsp_handshake)(const uint64* DecContextHandle, int DecContextHandleLen) __QAIC_HEADER_ATTRIBUTE;
#ifdef __cplusplus
}
#endif
#endif //_VC1DECDSP_H
