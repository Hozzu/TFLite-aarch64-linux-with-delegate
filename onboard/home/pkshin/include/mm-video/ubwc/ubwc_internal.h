/*-------------------------------------------------------------------
Copyright (c) 2014-2017 Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.
--------------------------------------------------------------------*/

#ifndef   _UBWC_INTERNAL_H
#define   _UBWC_INTERNAL_H

//#include "global_typedef.h"
#include "ubwc.h"

#define MMCORE_UBWC_CROSSCHAIN_TEST 0
#define BANK_SPREADING 0
#define BANK_SPREADING_EN_IN 0
#define MacroTile_SWIZZLING 0
#define META_PITCH_ALIGNMENT 1
#define BANK_SPREADING_BASEIMAGE 0
#define FORCE_BANKSPREADING_1 0
/*  Debug Macros. Cross checks encoded UWBC frame, by decoding it internally.
    Will result in a slowdown. Default: Disabled */
//#define MACROTILING_UBWC_CrossCheck

#define MACROTILE_WIDTH_8b            128                        //Format T1 (128x32)
#define MACROTILE_WIDTH_10b            192                        //Format T1 (192x16)
#define MACROTILE_HEIGHT_8b            32                        //Format T1 (128x32)
#define MACROTILE_HEIGHT_10b        16                        //Format T1 (192x16)

    //Begin: dedicated for UBWC//////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////
#define DECODER_ENCODER_CROSS_CHECK  1
#define PARTIAL_TILE_SUPPORT 1
#define UBWC_RW_LSB_FIRST 1
#define SHOW_BLOCK 0
#define TILE_COL_NUM_CHECK  0
#define TILE_ROW_NUM_CHECK  0

    // GPU internal formats
#define FORMAT_D24S8          101
#define FORMAT_GPU_INTERNAL_FORMAT_16BPS  102
#define FORMAT_GPU_INTERNAL_FORMAT_32BPS  103
#define FORMAT_GPU_INTERNAL_FORMAT_64BPS  104
#define FORMAT_GPU_INTERNAL_FORMAT_128BPS 105
    // MSAA
#define FORMAT_2XMSAA_BASE  0x100
#define FORMAT_4XMSAA_BASE  0x200
#define FORMAT_8xMSAA_BASE  0x300
    // Others
#define FORMAT_BAYER_RAW8     150
#define FORMAT_BAYER_RAW10    151
#define FORMAT_BAYER_RAW12    152
#define FORMAT_YUYV_ORIGINAL  153
#define FORMAT_8N 888

    // MAX SIZE
#define MAX_WIDTH                                4096
#define MAX_PLANE_TILE_SIZE         256
#define MAX_BITSBUFFER_SIZE                8*MAX_WIDTH
#define MAX_BLOCK_SIZE              32
#define MAX_NUM_PLANES              2
#define MAX_NUM_COMPS               4
#define MAX_NUM_COMPRESSED_SIZE_LEVELS 16
    // fast configuration
#define FAST_CONFIGURATION_MANUAL 0
#define FAST_CONFIGURATION_SIMPLE_UBWC_WITH_SUBTILE 1
#define FAST_CONFIGURATION_FULL_VERSION_UBWC 2
    // Color space operated
#define COLOR_SPACE_OPERATED_ORIGINAL 0
#define COLOR_SPACE_OPERATED_YCoCg    1
    // Color Trasform Method
#define COLOR_XFORM_METHOD_ORIGINAL   0
#define COLOR_XFORM_METHOD_YCoCg      1
#define COLOR_XFORM_METHOD_ADAPTIVE   2
    // Prediction method
#define PREDICTION_METHOD_2D_PARALLEGRAM 0
#define PREDICTION_METHOD_2D_MAP      1
#define PREDICTION_METHOD_1D          2
    // Coding method
#define CODING_METHOD_ORIG_BFLC             0
#define CODING_METHOD_BFLC_WITH_SAME_LENGTH_FLAG  1
    //YUV subtile
#define MAX_NUM_SUBTILES     4
#define SUBTILE_NO           0
#define SUBTILE_H2V1         1
#define SUBTILE_H1V2         2
#define SUBTILE_H2V2         3
#define SUBTILE_H4V1         4
#define SUBTILE_H1V4         5
    // MSAA
#define MSAA_BLK_4x4_OR_BIGGER   0
#define MSAA_BLK_4x2             1
#define MSAA_BLK_2x2             2
#define MSAA_2X              1
#define MSAA_4X              2
#define MSAA_8X              3

#define BITSBUFFER_LOW_THREASHOLD_IN_BITS    256

    //TILE FORMAT
#define FORMAT_YTile          101  // for NV12, NV21, P010, P016 tile
#define FORMAT_UVTile         102  // for NV12, NV21, P010, P016 tile
#define FORMAT_YUVTIle        103  // for YUYV, Y210, Y216, Y410; interleaved
#define FORMAT_YUVATile       104  // for AYUV interleaved

#define MacroTile2LinearMapSize_X 2100
#define MacroTile2LinearMapSize_Y 2100
#define LumaMetaDataTile2Linear_X 2100
#define LumaMetaDataTile2Linear_Y 2100

/*HFI MACROS required for UBWC*/

/* HFI Header Source :
//components/rel/video.ve/4.0/venus_proc/venus/drivers/inc/hfivcore_common.h#1 $
*/

#define DEFAULT_STRIDE_MULTIPLE_IN_PELS (128)
#define DEFAULT_HEIGHT_MULTIPLE (32)
#define DEFAULT_NV12_UBWC_UV_HEIGHT_MULTIPLE (16)


typedef unsigned /*long*/int HFI_U32; /**< HFI_U32 is a 32 bit unsigned quantity that
                               HFI_U32 can not be defined as long because in 64 bit env, long is 64 bit
                               *   is 32 bit word aligned.
                               */
#define HFI_ALIGN(a, b) (((a) + (b) - 1) & (~((b) - 1))) /**< Macro to align a to b. b should
                               *   be a power of 2
                               */
/**
Default ubwc metadata buffer stride and height alignment values
*/
#define HFI_DEFAULT_METADATA_STRIDE_MULTIPLE (64)
#define HFI_DEFAULT_METADATA_BUFFERHEIGHT_MULTIPLE (16)

/**
Level 2 Comment: "Tile dimensions(in pixels) macros for different color formats"

@datatypes

@sa
*/
#define HFI_COLOR_FORMAT_YUV420_NV12_UBWC_Y_TILE_HEIGHT (8)
#define HFI_COLOR_FORMAT_YUV420_NV12_UBWC_Y_TILE_WIDTH (32)
#define HFI_COLOR_FORMAT_YUV420_NV12_UBWC_UV_TILE_HEIGHT (8)
#define HFI_COLOR_FORMAT_YUV420_NV12_UBWC_UV_TILE_WIDTH (16)
#define HFI_COLOR_FORMAT_YUV420_TP10_UBWC_Y_TILE_HEIGHT (4)
#define HFI_COLOR_FORMAT_YUV420_TP10_UBWC_Y_TILE_WIDTH (48)
#define HFI_COLOR_FORMAT_YUV420_TP10_UBWC_UV_TILE_HEIGHT (4)
#define HFI_COLOR_FORMAT_YUV420_TP10_UBWC_UV_TILE_WIDTH (24)
#define HFI_COLOR_FORMAT_RGBA8888_UBWC_TILE_HEIGHT (4)
#define HFI_COLOR_FORMAT_RGBA8888_UBWC_TILE_WIDTH (16)

/**
Minimum metadata buffer size that needs to be allocated for
current frame dimensions for each metadata plane. This macro applies to all UBWC color format
*/
#define HFI_UBWC_METADATA_PLANE_BUFFER_SIZE(bufferSize, MetadataStride, MetadataBufHeight) \
    bufferSize = HFI_ALIGN(MetadataStride * MetadataBufHeight, 4096)

/**
Luma stride calculation for YUV420, NV12/NV21, NV12_UBWC color format
Stride arrived at here is the minimum required stride. Host may
set a stride higher than the one calculated here, till the stride
is a multiple of "nStrideMultiples" in
HFI_UNCOMPRESSED_PLANE_CONSTRAINTS_TYPE
*/
#define HFI_NV12_IL_CALC_Y_STRIDE(stride, frameWidth, strideMultiple) \
    stride = HFI_ALIGN(frameWidth, strideMultiple)

/**
Luma plane height calculation for YUV420 NV12/NV21, NV12_UBWC color format
Luma plane height used by the host needs to be either equal
to higher than the value calculated here
*/
#define HFI_NV12_IL_CALC_Y_BUFHEIGHT(bufHeight, frameHeight, minBufHeightMultiple) \
    bufHeight = HFI_ALIGN(frameHeight, minBufHeightMultiple)

/**
Chroma stride calculation for NV12/NV21, NV12_UBWC color format
*/
#define HFI_NV12_IL_CALC_UV_STRIDE(stride, frameWidth, strideMultiple) \
    stride = HFI_ALIGN(frameWidth, strideMultiple)

/**
Chroma plane height calculation for NV12/NV21, NV12_UBWC color format
*/
#define HFI_NV12_IL_CALC_UV_BUFHEIGHT(bufHeight, frameHeight, minBufHeightMultiple) \
    bufHeight = HFI_ALIGN(((frameHeight + 1) >> 1), minBufHeightMultiple)

/**
Minimum buffer size that needs to be allocated for current
frame dimensions for NV12/N21 Linear format
(calcualtion includes both luma and chroma plane)
*/
#define HFI_NV12_IL_CALC_BUF_SIZE(bufSize, yBufSize, yStride, yBufHeight, uvBufSize, uvStride, uvBufHeight, uvAlignment) \
    yBufSize = (yStride * yBufHeight); \
    uvBufSize = (uvStride * uvBufHeight) + uvAlignment; \
    bufSize = yBufSize + uvBufSize

/**
Minimum Luma buffer size that needs to be allocated for current
frame dimensions NV12_UBWC format

*/
#define HFI_NV12_UBWC_IL_CALC_Y_BUF_SIZE(yBufSize, yStride, yBufHeight) \
    yBufSize = HFI_ALIGN(yStride * yBufHeight, 4096)

/**
Minimum chroma buffer size that needs to be allocated for current
frame dimensions NV12_UBWC format
*/
#define HFI_NV12_UBWC_IL_CALC_UV_BUF_SIZE(uvBufSize, uvStride, uvBufHeight) \
    uvBufSize = HFI_ALIGN(uvStride * uvBufHeight, 4096)

/**
Minimum buffer size that needs to be allocated for current
frame dimensions NV12_UBWC format
(calculation includes all data & metadata planes)
*/
#define HFI_NV12_UBWC_IL_CALC_BUF_SIZE(bufSize, yStride, yBufHeight, uvStride, uvBufHeight, yMdStride, yMdHeight, uvMdStride, uvMdHeight) \
do \
{  \
    HFI_U32 yDataSize, uvDataSize, yMdSize, uvMdSize; \
    HFI_NV12_UBWC_IL_CALC_Y_BUF_SIZE(yDataSize, yStride, yBufHeight); \
    HFI_NV12_UBWC_IL_CALC_UV_BUF_SIZE(uvDataSize, uvStride, uvBufHeight); \
    HFI_UBWC_METADATA_PLANE_BUFFER_SIZE(yMdSize, yMdStride, yMdHeight); \
    HFI_UBWC_METADATA_PLANE_BUFFER_SIZE(uvMdSize, uvMdStride, uvMdHeight); \
    bufSize = yDataSize + uvDataSize + yMdSize + uvMdSize; \
} while (0)

typedef struct ubwc_plane_tile_sta_s
{
        Int32 tile_row_num;
        Int32 tile_col_num;
        Int32 num_compressed_bits_with_padding;
        Int32 num_compressed_bits_no_padding;
}ubwc_plane_tile_sta_t;

typedef struct ubwc_sta_s
{
        Int32 num_compressed_bits_with_padding;
        Int32 num_compressed_bits_no_padding;
        Int32 compressed_tile_size_frm_sta[MAX_NUM_COMPRESSED_SIZE_LEVELS+1];
        Int32 compressed_tile_size_sum_all_frms_sta[MAX_NUM_COMPRESSED_SIZE_LEVELS+1];
}ubwc_sta_t;

typedef struct ubwc_alg_params_s
{
    Int32 pred_method;
    Int32 color_xform_method;
    Int32 coding_method;
    Int32 bflc_blk_len;
    Int32 bflc_blk_len_num_bits;
    Int32 compressed_size_basic_unit_in_bits_in_num_bits;
} ubwc_alg_params_t;

typedef struct ubwc_plane_tile_comp_params_s
{
    Int32 tile_comp_width;
    Int32 tile_comp_height;
    Int32 subtile_comp_width;
    Int32 subtile_comp_height;
    Int32 num_blks_for_a_subtile_comp;
    Int32 bit_depth;
    Int32 op_bit_depth;
    Int32 bits_for_bflc_blk_len_field;
    Int32 num_bits_thd_for_PCM;
} ubwc_plane_tile_comp_params_t;

typedef struct ubwc_plane_tile_params_s
{
    Int32 num_comps;
    Int32 num_subtiles;
    Int32 alpha_valid_flg;
    Int32 color_xform_allowed;
    Int32 num_bits_per_pixel;
    Int32 tile_width;
    Int32 tile_width_in_bytes;
    Int32 tile_height;
    Int32 tile_size_in_bytes;
    Int32 subtile_type;
    Int32 subtile_width;
    Int32 subtile_width_in_bytes;
    Int32 subtile_height;
    Int32 op_color_space;
    Int32 num_bits_thd_for_plane_tile_PCM;
    Int32 format;
    Int32 comp_order;
    Int32 mini_tile_flg;
    Int32 mini_tile_basic_unit_num_bytes_in_num_bits;
    Int32 lsb_msb_sep_segs;
    Int32 nx_msaa_n_in_num_bits;
    Int32 msaa_4x2_2x2_blk_mode;
    ubwc_alg_params_t ubwc_alg_params;
    ubwc_plane_tile_comp_params_t ubwc_plane_tile_comp_params[MAX_NUM_COMPS];
    ubwc_plane_tile_sta_t ubwc_plane_tile_sta;
}ubwc_plane_tile_params_t;

typedef struct ubwc_plane_params_s
{
    ubwc_plane_tile_params_t ubwc_plane_tile_params;
    Int32 plane_width;
    Int32 plane_width_in_bytes;
    Int32 plane_height;
    Int32 num_bits_per_comp[MAX_NUM_COMPS];
}ubwc_plane_params_t;

typedef struct ubwc_dump_tile_s
{
    Int32 dump_tile_data_flg;
    Int32 dump_tile_data_x_start;
    Int32 dump_tile_data_x_end;
    Int32 dump_tile_data_y_start;
    Int32 dump_tile_data_y_end;
    Int32 frame_num;
}ubwc_dump_tile_t;

typedef struct ubwc_params_s
{
    ubwc_plane_params_t ubwc_plane_params[MAX_NUM_PLANES];
    Int32 width;
    Int32 height;
    Int32 num_planes;
    Int32 format;
    Int32 mini_tile_flg;
    Int32 uncompressed_tile_size_in_bits;
    Int32 compressed_size_basic_unit_in_bits_in_num_bits;
    Int32 num_segs_for_compressed_size;
    Int32 comp_order;
    Int32 color_xform_method;
    Int32 pred_method;
    Int32 coding_method;
    Int32 bflc_blk_len;
    Int32 bflc_blk_len_num_bits;
    Int32 num_bits_original_frame;
    Int32 io_tile_width;
    Int32 io_tile_width_in_bytes;
    Int32 io_tile_height;
    //statistics
    ubwc_sta_t ubwc_sta;
    //Dump tile data
    ubwc_dump_tile_t dump_tile;
} ubwc_params_t;
typedef struct bitsbuffer_params_s
{
    UInt8 *buf;
    UInt8 *curr_buf_ptr;
    UInt32 byte_location;
    UInt8 bit_location;
    UInt32 num_bits;
} bitsbuffer_params_t;
//////////////////////////////////////////////////////////
//End:    dedicated for UBWC//////////////////////////////////////////////////////////////////////

typedef struct
{
    UInt32 m_LinearAddressHeight;
    UInt32 m_LinearAddressWidth;
    UInt32 m_LinearAddressOffset;

    UInt32 m_L2LinearAddressHeight;
    UInt32 m_L2LinearAddressWidth;
    UInt32 m_L2LinearAddressOffset;

    UInt32 m_L1LinearAddressHeight;
    UInt32 m_L1LinearAddressWidth;
    UInt32 m_L1LinearAddressOffset;

    UInt32 FrameHeight;
    UInt32 FrameWidth;
    UInt32 FrameStride;
}LinAddressDef;

#define MAX_MT_HEIGHT                       32
#define MAX_MT_WIDTH                       256
#define SYSTEM_LAL                    256                //Longest access length per transaction for current Tier
#define SYSTEM_PAGEINTRL_SIZE        2048            //Page size across 2 interleaved banks (PageSize * 2)
#define SYSTEM_HEIGHT                32
#define SYSTEM_META_SIZE_DIV                256


#endif /* _UBWC_INTERNAL_H */
