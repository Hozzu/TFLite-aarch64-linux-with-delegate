/*-------------------------------------------------------------------
Copyright (c) 2014-2017 Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.
--------------------------------------------------------------------*/

#ifndef   _UBWC_H
#define   _UBWC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <VideoComDef.h>
#include <msm_media_info.h>
#include <VideoStreamParser.h>

    //typedef unsigned char               Boolean;
    //typedef unsigned int                UInt32;
    //typedef int                         Int32;
    //typedef unsigned short              UInt16;
    //typedef short                       Int16;
    //typedef unsigned char               UInt8;
    //typedef char                        Int8;
    typedef float                       Float;
    typedef double                      Double;

typedef struct UBWCConfig
{
    UInt8 * rec_frame_y;
    UInt8 * rec_frame_uv;
    UInt8 * rec_luma_meta_frame;
    UInt8 * rec_chroma_meta_frame;
    UInt8 * linear_frame_y;
    UInt8 * linear_frame_uv;
    UInt32 FrameWidth;
    UInt32 FrameHeight;
    UInt32 bitdepth;
    UInt32 LinearMode;
    UInt32 m_alignedWidth;
    UInt32 m_alignedHeight;
    UInt32 m_ystride;
    UInt32 m_chromaoffset;
    UInt32 Chroma_format;
    UInt32 bank_spreading;
    UInt32 swizzle_en;
    UInt32 highest_bank_bit;
    UInt8 DecoderORNOT;
}UBWCConfig;

void* UBWCConvertInit();
void* UBWCConfigInit();
void* UBWCConvertInitZero(void *hU);
void  UBWCConvertDeInit(void* hUBWC);
void UBWCConvertConfigure(void *hUBWC, UInt32 ubwc_video_format);
VidcStatus ConvertFromNV12toUBWC8(VideoStreamParser* pParser, ParserFrameInfoType *pFrameInfo);

//For Encoder Mem(Compressed)
UInt32 MacroTile_UBWCE_FianlCompressed(void *hUBWC, UBWCConfig *pConfig);
//For Decoder .yuv Output (DeCompressed)
VidcStatus ConvertUBWCToNV12(void *hUBWC, UBWCConfig *pConfig, uint8 *pData, uint8 **bufNV12, VideoResolution* res);

#ifdef __cplusplus
}
#endif

#endif /* _UBWC_H */
