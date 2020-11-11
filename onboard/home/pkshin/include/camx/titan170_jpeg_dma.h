/*==============================================================================
 Copyright (c) 2015-2018 Qualcomm Technologies, Inc.
 All Rights Reserved.
 Confidential and Proprietary - Qualcomm Technologies, Inc.
==============================================================================*/
#ifndef TITAN170_JPEG_DMA_H
#define TITAN170_JPEG_DMA_H

/*----------------------------------------------------------------------
        Offset and Mask
----------------------------------------------------------------------*/

#define JPEG_DMA_REGS_FIRST 0x0

#define JPEG_DMA_REGS_LAST  0x1b0

#define JPEG_DMA_REGS_COUNT 0x2f

#define regJPEG_DMA_JPEG_3_HW_VERSION 0x0  /*register offset*/
#define JPEG_DMA_JPEG_3_HW_VERSION_REVISION_MASK 0xffff
#define JPEG_DMA_JPEG_3_HW_VERSION_REVISION_SHIFT 0x0
#define JPEG_DMA_JPEG_3_HW_VERSION_MINOR_VERSION_MASK 0xfff0000
#define JPEG_DMA_JPEG_3_HW_VERSION_MINOR_VERSION_SHIFT 0x10
#define JPEG_DMA_JPEG_3_HW_VERSION_MAJOR_VERSION_MASK 0xf0000000
#define JPEG_DMA_JPEG_3_HW_VERSION_MAJOR_VERSION_SHIFT 0x1c

#define regJPEG_DMA_JPEG_3_HW_CAPABILITY 0x4  /*register offset*/
#define JPEG_DMA_JPEG_3_HW_CAPABILITY_SCALE_MASK 0x1
#define JPEG_DMA_JPEG_3_HW_CAPABILITY_SCALE_SHIFT 0x0
#define JPEG_DMA_JPEG_3_HW_CAPABILITY_NUM_PROCESSING_PIPES_MASK 0x6
#define JPEG_DMA_JPEG_3_HW_CAPABILITY_NUM_PROCESSING_PIPES_SHIFT 0x1
#define JPEG_DMA_JPEG_3_HW_CAPABILITY_UNUSED0_MASK 0xfffffff8
#define JPEG_DMA_JPEG_3_HW_CAPABILITY_UNUSED0_SHIFT 0x3

#define regJPEG_DMA_JPEG_3_RESET_CMD 0x8  /*register offset*/
#define JPEG_DMA_JPEG_3_RESET_CMD_FE_RESET_MASK 0x1
#define JPEG_DMA_JPEG_3_RESET_CMD_FE_RESET_SHIFT 0x0
#define JPEG_DMA_JPEG_3_RESET_CMD_WE_RESET_MASK 0x2
#define JPEG_DMA_JPEG_3_RESET_CMD_WE_RESET_SHIFT 0x1
#define JPEG_DMA_JPEG_3_RESET_CMD_UNUSED0_MASK 0x7c
#define JPEG_DMA_JPEG_3_RESET_CMD_UNUSED0_SHIFT 0x2
#define JPEG_DMA_JPEG_3_RESET_CMD_SCALE_RESET_MASK 0x80
#define JPEG_DMA_JPEG_3_RESET_CMD_SCALE_RESET_SHIFT 0x7
#define JPEG_DMA_JPEG_3_RESET_CMD_UNUSED1_MASK 0x1f00
#define JPEG_DMA_JPEG_3_RESET_CMD_UNUSED1_SHIFT 0x8
#define JPEG_DMA_JPEG_3_RESET_CMD_REGISTER_RESET_MASK 0x2000
#define JPEG_DMA_JPEG_3_RESET_CMD_REGISTER_RESET_SHIFT 0xd
#define JPEG_DMA_JPEG_3_RESET_CMD_UNUSED2_MASK 0xc000
#define JPEG_DMA_JPEG_3_RESET_CMD_UNUSED2_SHIFT 0xe
#define JPEG_DMA_JPEG_3_RESET_CMD_MISR_RESET_MASK 0x10000
#define JPEG_DMA_JPEG_3_RESET_CMD_MISR_RESET_SHIFT 0x10
#define JPEG_DMA_JPEG_3_RESET_CMD_CORE_RESET_MASK 0x20000
#define JPEG_DMA_JPEG_3_RESET_CMD_CORE_RESET_SHIFT 0x11
#define JPEG_DMA_JPEG_3_RESET_CMD_UNUSED3_MASK 0x1ffc0000
#define JPEG_DMA_JPEG_3_RESET_CMD_UNUSED3_SHIFT 0x12
#define JPEG_DMA_JPEG_3_RESET_CMD_JPEG_DOMAIN_RESET_MASK 0x20000000
#define JPEG_DMA_JPEG_3_RESET_CMD_JPEG_DOMAIN_RESET_SHIFT 0x1d
#define JPEG_DMA_JPEG_3_RESET_CMD_UNUSED4_MASK 0x40000000
#define JPEG_DMA_JPEG_3_RESET_CMD_UNUSED4_SHIFT 0x1e
#define JPEG_DMA_JPEG_3_RESET_CMD_RESET_BYPASS_MASK 0x80000000
#define JPEG_DMA_JPEG_3_RESET_CMD_RESET_BYPASS_SHIFT 0x1f

#define regJPEG_DMA_JPEG_3_IRQ_MASK 0xc  /*register offset*/
#define JPEG_DMA_JPEG_3_IRQ_MASK_INFO_SESSION_DONE_MASK 0x1
#define JPEG_DMA_JPEG_3_IRQ_MASK_INFO_SESSION_DONE_SHIFT 0x0
#define JPEG_DMA_JPEG_3_IRQ_MASK_INFO_FE_0_RD_BUF_DONE_MASK 0x2
#define JPEG_DMA_JPEG_3_IRQ_MASK_INFO_FE_0_RD_BUF_DONE_SHIFT 0x1
#define JPEG_DMA_JPEG_3_IRQ_MASK_UNUSED0_MASK 0x4
#define JPEG_DMA_JPEG_3_IRQ_MASK_UNUSED0_SHIFT 0x2
#define JPEG_DMA_JPEG_3_IRQ_MASK_INFO_FE_0_RD_BUF_REQ_ATTN_MASK 0x8
#define JPEG_DMA_JPEG_3_IRQ_MASK_INFO_FE_0_RD_BUF_REQ_ATTN_SHIFT 0x3
#define JPEG_DMA_JPEG_3_IRQ_MASK_UNUSED1_MASK 0x10
#define JPEG_DMA_JPEG_3_IRQ_MASK_UNUSED1_SHIFT 0x4
#define JPEG_DMA_JPEG_3_IRQ_MASK_INFO_WE_0_WR_BUF_DONE_MASK 0x20
#define JPEG_DMA_JPEG_3_IRQ_MASK_INFO_WE_0_WR_BUF_DONE_SHIFT 0x5
#define JPEG_DMA_JPEG_3_IRQ_MASK_UNUSED2_MASK 0x40
#define JPEG_DMA_JPEG_3_IRQ_MASK_UNUSED2_SHIFT 0x6
#define JPEG_DMA_JPEG_3_IRQ_MASK_INFO_WE_0_WR_BUF_REQ_ATTN_MASK 0x80
#define JPEG_DMA_JPEG_3_IRQ_MASK_INFO_WE_0_WR_BUF_REQ_ATTN_SHIFT 0x7
#define JPEG_DMA_JPEG_3_IRQ_MASK_UNUSED3_MASK 0x100
#define JPEG_DMA_JPEG_3_IRQ_MASK_UNUSED3_SHIFT 0x8
#define JPEG_DMA_JPEG_3_IRQ_MASK_INFO_AXI_HALT_ACK_DONE_MASK 0x200
#define JPEG_DMA_JPEG_3_IRQ_MASK_INFO_AXI_HALT_ACK_DONE_SHIFT 0x9
#define JPEG_DMA_JPEG_3_IRQ_MASK_INFO_RST_DONE_MASK 0x400
#define JPEG_DMA_JPEG_3_IRQ_MASK_INFO_RST_DONE_SHIFT 0xa
#define JPEG_DMA_JPEG_3_IRQ_MASK_INFO_PP_0_DONE_MASK 0x800
#define JPEG_DMA_JPEG_3_IRQ_MASK_INFO_PP_0_DONE_SHIFT 0xb
#define JPEG_DMA_JPEG_3_IRQ_MASK_UNUSED4_MASK 0xfffff000
#define JPEG_DMA_JPEG_3_IRQ_MASK_UNUSED4_SHIFT 0xc

#define regJPEG_DMA_JPEG_3_IRQ_STATUS 0x10  /*register offset*/
#define JPEG_DMA_JPEG_3_IRQ_STATUS_INFO_SESSION_DONE_MASK 0x1
#define JPEG_DMA_JPEG_3_IRQ_STATUS_INFO_SESSION_DONE_SHIFT 0x0
#define JPEG_DMA_JPEG_3_IRQ_STATUS_INFO_FE_0_RD_BUF_DONE_MASK 0x2
#define JPEG_DMA_JPEG_3_IRQ_STATUS_INFO_FE_0_RD_BUF_DONE_SHIFT 0x1
#define JPEG_DMA_JPEG_3_IRQ_STATUS_UNUSED0_MASK 0x4
#define JPEG_DMA_JPEG_3_IRQ_STATUS_UNUSED0_SHIFT 0x2
#define JPEG_DMA_JPEG_3_IRQ_STATUS_INFO_FE_0_RD_BUF_REQ_ATTN_MASK 0x8
#define JPEG_DMA_JPEG_3_IRQ_STATUS_INFO_FE_0_RD_BUF_REQ_ATTN_SHIFT 0x3
#define JPEG_DMA_JPEG_3_IRQ_STATUS_UNUSED1_MASK 0x10
#define JPEG_DMA_JPEG_3_IRQ_STATUS_UNUSED1_SHIFT 0x4
#define JPEG_DMA_JPEG_3_IRQ_STATUS_INFO_WE_0_WR_BUF_DONE_MASK 0x20
#define JPEG_DMA_JPEG_3_IRQ_STATUS_INFO_WE_0_WR_BUF_DONE_SHIFT 0x5
#define JPEG_DMA_JPEG_3_IRQ_STATUS_UNUSED2_MASK 0x40
#define JPEG_DMA_JPEG_3_IRQ_STATUS_UNUSED2_SHIFT 0x6
#define JPEG_DMA_JPEG_3_IRQ_STATUS_INFO_WE_0_WR_BUF_REQ_ATTN_MASK 0x80
#define JPEG_DMA_JPEG_3_IRQ_STATUS_INFO_WE_0_WR_BUF_REQ_ATTN_SHIFT 0x7
#define JPEG_DMA_JPEG_3_IRQ_STATUS_UNUSED3_MASK 0x100
#define JPEG_DMA_JPEG_3_IRQ_STATUS_UNUSED3_SHIFT 0x8
#define JPEG_DMA_JPEG_3_IRQ_STATUS_INFO_AXI_HALT_ACK_DONE_MASK 0x200
#define JPEG_DMA_JPEG_3_IRQ_STATUS_INFO_AXI_HALT_ACK_DONE_SHIFT 0x9
#define JPEG_DMA_JPEG_3_IRQ_STATUS_INFO_RST_DONE_MASK 0x400
#define JPEG_DMA_JPEG_3_IRQ_STATUS_INFO_RST_DONE_SHIFT 0xa
#define JPEG_DMA_JPEG_3_IRQ_STATUS_INFO_PP_0_DONE_MASK 0x800
#define JPEG_DMA_JPEG_3_IRQ_STATUS_INFO_PP_0_DONE_SHIFT 0xb
#define JPEG_DMA_JPEG_3_IRQ_STATUS_UNUSED4_MASK 0xfffff000
#define JPEG_DMA_JPEG_3_IRQ_STATUS_UNUSED4_SHIFT 0xc

#define regJPEG_DMA_JPEG_3_IRQ_CLEAR_CMD 0x14  /*register offset*/
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_INFO_SESSION_DONE_MASK 0x1
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_INFO_SESSION_DONE_SHIFT 0x0
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_INFO_FE_0_RD_BUF_DONE_MASK 0x2
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_INFO_FE_0_RD_BUF_DONE_SHIFT 0x1
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_UNUSED0_MASK 0x4
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_UNUSED0_SHIFT 0x2
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_INFO_FE_0_RD_BUF_REQ_ATTN_MASK 0x8
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_INFO_FE_0_RD_BUF_REQ_ATTN_SHIFT 0x3
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_UNUSED1_MASK 0x10
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_UNUSED1_SHIFT 0x4
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_INFO_WE_0_WR_BUF_DONE_MASK 0x20
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_INFO_WE_0_WR_BUF_DONE_SHIFT 0x5
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_UNUSED2_MASK 0x40
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_UNUSED2_SHIFT 0x6
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_INFO_WE_0_WR_BUF_REQ_ATTN_MASK 0x80
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_INFO_WE_0_WR_BUF_REQ_ATTN_SHIFT 0x7
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_UNUSED3_MASK 0x100
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_UNUSED3_SHIFT 0x8
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_INFO_AXI_HALT_ACK_DONE_MASK 0x200
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_INFO_AXI_HALT_ACK_DONE_SHIFT 0x9
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_INFO_RST_DONE_MASK 0x400
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_INFO_RST_DONE_SHIFT 0xa
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_INFO_PP_0_DONE_MASK 0x800
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_INFO_PP_0_DONE_SHIFT 0xb
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_UNUSED4_MASK 0xfffff000
#define JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD_UNUSED4_SHIFT 0xc

#define regJPEG_DMA_JPEG_3_CORE_CFG 0x18  /*register offset*/
#define JPEG_DMA_JPEG_3_CORE_CFG_FE_0_EN_MASK 0x1
#define JPEG_DMA_JPEG_3_CORE_CFG_FE_0_EN_SHIFT 0x0
#define JPEG_DMA_JPEG_3_CORE_CFG_UNUSED0_MASK 0x2
#define JPEG_DMA_JPEG_3_CORE_CFG_UNUSED0_SHIFT 0x1
#define JPEG_DMA_JPEG_3_CORE_CFG_WE_0_EN_MASK 0x4
#define JPEG_DMA_JPEG_3_CORE_CFG_WE_0_EN_SHIFT 0x2
#define JPEG_DMA_JPEG_3_CORE_CFG_UNUSED1_MASK 0x8
#define JPEG_DMA_JPEG_3_CORE_CFG_UNUSED1_SHIFT 0x3
#define JPEG_DMA_JPEG_3_CORE_CFG_SCALE_0_EN_MASK 0x10
#define JPEG_DMA_JPEG_3_CORE_CFG_SCALE_0_EN_SHIFT 0x4
#define JPEG_DMA_JPEG_3_CORE_CFG_UNUSED2_MASK 0x60
#define JPEG_DMA_JPEG_3_CORE_CFG_UNUSED2_SHIFT 0x5
#define JPEG_DMA_JPEG_3_CORE_CFG_BUS_MISR_EN_MASK 0x80
#define JPEG_DMA_JPEG_3_CORE_CFG_BUS_MISR_EN_SHIFT 0x7
#define JPEG_DMA_JPEG_3_CORE_CFG_UNUSED3_MASK 0x7ff00
#define JPEG_DMA_JPEG_3_CORE_CFG_UNUSED3_SHIFT 0x8
#define JPEG_DMA_JPEG_3_CORE_CFG_TEST_BUS_EN_MASK 0x80000
#define JPEG_DMA_JPEG_3_CORE_CFG_TEST_BUS_EN_SHIFT 0x13
#define JPEG_DMA_JPEG_3_CORE_CFG_UNUSED4_MASK 0x7ff00000
#define JPEG_DMA_JPEG_3_CORE_CFG_UNUSED4_SHIFT 0x14
#define JPEG_DMA_JPEG_3_CORE_CFG_CGC_DISABLE_MASK 0x80000000
#define JPEG_DMA_JPEG_3_CORE_CFG_CGC_DISABLE_SHIFT 0x1f

#define regJPEG_DMA_JPEG_3_CMD 0x1c  /*register offset*/
#define JPEG_DMA_JPEG_3_CMD_HW_START_MASK 0x1
#define JPEG_DMA_JPEG_3_CMD_HW_START_SHIFT 0x0
#define JPEG_DMA_JPEG_3_CMD_UNUSED0_MASK 0x2
#define JPEG_DMA_JPEG_3_CMD_UNUSED0_SHIFT 0x1
#define JPEG_DMA_JPEG_3_CMD_HW_STOP_MASK 0x4
#define JPEG_DMA_JPEG_3_CMD_HW_STOP_SHIFT 0x2
#define JPEG_DMA_JPEG_3_CMD_UNUSED1_MASK 0x8
#define JPEG_DMA_JPEG_3_CMD_UNUSED1_SHIFT 0x3
#define JPEG_DMA_JPEG_3_CMD_CLEAR_FE_0_QUEUE_MASK 0x10
#define JPEG_DMA_JPEG_3_CMD_CLEAR_FE_0_QUEUE_SHIFT 0x4
#define JPEG_DMA_JPEG_3_CMD_UNUSED2_MASK 0xe0
#define JPEG_DMA_JPEG_3_CMD_UNUSED2_SHIFT 0x5
#define JPEG_DMA_JPEG_3_CMD_CLEAR_WE_0_QUEUE_MASK 0x100
#define JPEG_DMA_JPEG_3_CMD_CLEAR_WE_0_QUEUE_SHIFT 0x8
#define JPEG_DMA_JPEG_3_CMD_UNUSED3_MASK 0xfffffe00
#define JPEG_DMA_JPEG_3_CMD_UNUSED3_SHIFT 0x9

#define regJPEG_DMA_JPEG_3_FE_0_CFG 0x2c  /*register offset*/
#define JPEG_DMA_JPEG_3_FE_0_CFG_BURST_LENGTH_MAX_MASK 0xf
#define JPEG_DMA_JPEG_3_FE_0_CFG_BURST_LENGTH_MAX_SHIFT 0x0
#define JPEG_DMA_JPEG_3_FE_0_CFG_BLOCK_WIDTH_SEL_MASK 0x70
#define JPEG_DMA_JPEG_3_FE_0_CFG_BLOCK_WIDTH_SEL_SHIFT 0x4
#define JPEG_DMA_JPEG_3_FE_0_CFG_UNUSED0_MASK 0x80
#define JPEG_DMA_JPEG_3_FE_0_CFG_UNUSED0_SHIFT 0x7
#define JPEG_DMA_JPEG_3_FE_0_CFG_BOTTOM_VPAD_EN_MASK 0x100
#define JPEG_DMA_JPEG_3_FE_0_CFG_BOTTOM_VPAD_EN_SHIFT 0x8
#define JPEG_DMA_JPEG_3_FE_0_CFG_UNUSED1_MASK 0xe00
#define JPEG_DMA_JPEG_3_FE_0_CFG_UNUSED1_SHIFT 0x9
#define JPEG_DMA_JPEG_3_FE_0_CFG_CBCR_ORDER_MASK 0x1000
#define JPEG_DMA_JPEG_3_FE_0_CFG_CBCR_ORDER_SHIFT 0xc
#define JPEG_DMA_JPEG_3_FE_0_CFG_UNUSED2_MASK 0x7e000
#define JPEG_DMA_JPEG_3_FE_0_CFG_UNUSED2_SHIFT 0xd
#define JPEG_DMA_JPEG_3_FE_0_CFG_PLN_BLOCK_TYPE_MASK 0x180000
#define JPEG_DMA_JPEG_3_FE_0_CFG_PLN_BLOCK_TYPE_SHIFT 0x13
#define JPEG_DMA_JPEG_3_FE_0_CFG_MAL_EN_MASK 0x200000
#define JPEG_DMA_JPEG_3_FE_0_CFG_MAL_EN_SHIFT 0x15
#define JPEG_DMA_JPEG_3_FE_0_CFG_UNUSED3_MASK 0x1c00000
#define JPEG_DMA_JPEG_3_FE_0_CFG_UNUSED3_SHIFT 0x16
#define JPEG_DMA_JPEG_3_FE_0_CFG_MAL_BOUNDARY_MASK 0xe000000
#define JPEG_DMA_JPEG_3_FE_0_CFG_MAL_BOUNDARY_SHIFT 0x19
#define JPEG_DMA_JPEG_3_FE_0_CFG_UNUSED4_MASK 0xf0000000
#define JPEG_DMA_JPEG_3_FE_0_CFG_UNUSED4_SHIFT 0x1c

#define regJPEG_DMA_JPEG_3_FE_0_RD_PNTR 0x34  /*register offset*/
#define JPEG_DMA_JPEG_3_FE_0_RD_PNTR_PNTR_MASK 0xffffffff
#define JPEG_DMA_JPEG_3_FE_0_RD_PNTR_PNTR_SHIFT 0x0

#define regJPEG_DMA_JPEG_3_FE_0_RD_PNTR_CNSMD 0x3c  /*register offset*/
#define JPEG_DMA_JPEG_3_FE_0_RD_PNTR_CNSMD_PNTR_CNSMD_MASK 0xffffffff
#define JPEG_DMA_JPEG_3_FE_0_RD_PNTR_CNSMD_PNTR_CNSMD_SHIFT 0x0

#define regJPEG_DMA_JPEG_3_FE_0_RD_PNTR_CNT 0x40  /*register offset*/
#define JPEG_DMA_JPEG_3_FE_0_RD_PNTR_CNT_PNTR_CNT_MASK 0x7
#define JPEG_DMA_JPEG_3_FE_0_RD_PNTR_CNT_PNTR_CNT_SHIFT 0x0
#define JPEG_DMA_JPEG_3_FE_0_RD_PNTR_CNT_UNUSED0_MASK 0xfffffff8
#define JPEG_DMA_JPEG_3_FE_0_RD_PNTR_CNT_UNUSED0_SHIFT 0x3

#define regJPEG_DMA_JPEG_3_FE_0_RD_BUFFER_SIZE 0x44  /*register offset*/
#define JPEG_DMA_JPEG_3_FE_0_RD_BUFFER_SIZE_WIDTH_MASK 0xffff
#define JPEG_DMA_JPEG_3_FE_0_RD_BUFFER_SIZE_WIDTH_SHIFT 0x0
#define JPEG_DMA_JPEG_3_FE_0_RD_BUFFER_SIZE_HEIGHT_MASK 0xffff0000
#define JPEG_DMA_JPEG_3_FE_0_RD_BUFFER_SIZE_HEIGHT_SHIFT 0x10

#define regJPEG_DMA_JPEG_3_FE_0_RD_STRIDE 0x48  /*register offset*/
#define JPEG_DMA_JPEG_3_FE_0_RD_STRIDE_STRIDE_MASK 0xffff
#define JPEG_DMA_JPEG_3_FE_0_RD_STRIDE_STRIDE_SHIFT 0x0
#define JPEG_DMA_JPEG_3_FE_0_RD_STRIDE_UNUSED0_MASK 0xffff0000
#define JPEG_DMA_JPEG_3_FE_0_RD_STRIDE_UNUSED0_SHIFT 0x10

#define regJPEG_DMA_JPEG_3_FE_0_RD_HINIT 0x4c  /*register offset*/
#define JPEG_DMA_JPEG_3_FE_0_RD_HINIT_FRACTIONAL_MASK 0x1fffff
#define JPEG_DMA_JPEG_3_FE_0_RD_HINIT_FRACTIONAL_SHIFT 0x0
#define JPEG_DMA_JPEG_3_FE_0_RD_HINIT_UNUSED0_MASK 0xffe00000
#define JPEG_DMA_JPEG_3_FE_0_RD_HINIT_UNUSED0_SHIFT 0x15

#define regJPEG_DMA_JPEG_3_FE_0_RD_HINIT_INT 0x50  /*register offset*/
#define JPEG_DMA_JPEG_3_FE_0_RD_HINIT_INT_INTEGER_MASK 0x1ffff
#define JPEG_DMA_JPEG_3_FE_0_RD_HINIT_INT_INTEGER_SHIFT 0x0
#define JPEG_DMA_JPEG_3_FE_0_RD_HINIT_INT_UNUSED0_MASK 0xfffe0000
#define JPEG_DMA_JPEG_3_FE_0_RD_HINIT_INT_UNUSED0_SHIFT 0x11

#define regJPEG_DMA_JPEG_3_FE_0_RD_VINIT 0x54  /*register offset*/
#define JPEG_DMA_JPEG_3_FE_0_RD_VINIT_FRACTIONAL_MASK 0x1fffff
#define JPEG_DMA_JPEG_3_FE_0_RD_VINIT_FRACTIONAL_SHIFT 0x0
#define JPEG_DMA_JPEG_3_FE_0_RD_VINIT_UNUSED0_MASK 0xffe00000
#define JPEG_DMA_JPEG_3_FE_0_RD_VINIT_UNUSED0_SHIFT 0x15

#define regJPEG_DMA_JPEG_3_FE_0_RD_VINIT_INT 0x58  /*register offset*/
#define JPEG_DMA_JPEG_3_FE_0_RD_VINIT_INT_INTEGER_MASK 0x1ffff
#define JPEG_DMA_JPEG_3_FE_0_RD_VINIT_INT_INTEGER_SHIFT 0x0
#define JPEG_DMA_JPEG_3_FE_0_RD_VINIT_INT_UNUSED0_MASK 0xfffe0000
#define JPEG_DMA_JPEG_3_FE_0_RD_VINIT_INT_UNUSED0_SHIFT 0x11

#define regJPEG_DMA_JPEG_3_FE_0_VBPAD_CFG 0x5c  /*register offset*/
#define JPEG_DMA_JPEG_3_FE_0_VBPAD_CFG_BLOCK_ROW_MASK 0x1fff
#define JPEG_DMA_JPEG_3_FE_0_VBPAD_CFG_BLOCK_ROW_SHIFT 0x0
#define JPEG_DMA_JPEG_3_FE_0_VBPAD_CFG_UNUSED0_MASK 0xffffe000
#define JPEG_DMA_JPEG_3_FE_0_VBPAD_CFG_UNUSED0_SHIFT 0xd

#define regJPEG_DMA_JPEG_3_FE_QOS_CFG 0x60  /*register offset*/
#define JPEG_DMA_JPEG_3_FE_QOS_CFG_PRIORITY_MASK 0xf
#define JPEG_DMA_JPEG_3_FE_QOS_CFG_PRIORITY_SHIFT 0x0
#define JPEG_DMA_JPEG_3_FE_QOS_CFG_UNUSED0_MASK 0xfffffff0
#define JPEG_DMA_JPEG_3_FE_QOS_CFG_UNUSED0_SHIFT 0x4

#define regJPEG_DMA_JPEG_3_WE_CFG 0xb8  /*register offset*/
#define JPEG_DMA_JPEG_3_WE_CFG_BURST_LENGTH_MAX_MASK 0xf
#define JPEG_DMA_JPEG_3_WE_CFG_BURST_LENGTH_MAX_SHIFT 0x0
#define JPEG_DMA_JPEG_3_WE_CFG_UNUSED0_MASK 0x70
#define JPEG_DMA_JPEG_3_WE_CFG_UNUSED0_SHIFT 0x4
#define JPEG_DMA_JPEG_3_WE_CFG_MAL_EN_MASK 0x80
#define JPEG_DMA_JPEG_3_WE_CFG_MAL_EN_SHIFT 0x7
#define JPEG_DMA_JPEG_3_WE_CFG_MAL_BOUNDARY_MASK 0x700
#define JPEG_DMA_JPEG_3_WE_CFG_MAL_BOUNDARY_SHIFT 0x8
#define JPEG_DMA_JPEG_3_WE_CFG_UNUSED1_MASK 0xfffff800
#define JPEG_DMA_JPEG_3_WE_CFG_UNUSED1_SHIFT 0xb

#define regJPEG_DMA_JPEG_3_WE_PLN_0_WR_PNTR 0xbc  /*register offset*/
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_PNTR_WR_PNTR_MASK 0xffffffff
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_PNTR_WR_PNTR_SHIFT 0x0

#define regJPEG_DMA_JPEG_3_WE_PLN_0_WR_PNTR_CNSMD 0xc0  /*register offset*/
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_PNTR_CNSMD_WR_PNTR_MASK 0xffffffff
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_PNTR_CNSMD_WR_PNTR_SHIFT 0x0

#define regJPEG_DMA_JPEG_3_WE_PLN_0_WR_BUFFER_SIZE 0xc4  /*register offset*/
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_BUFFER_SIZE_WIDTH_MASK 0xffff
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_BUFFER_SIZE_WIDTH_SHIFT 0x0
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_BUFFER_SIZE_HEIGHT_MASK 0xffff0000
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_BUFFER_SIZE_HEIGHT_SHIFT 0x10

#define regJPEG_DMA_JPEG_3_WE_PLN_0_WR_STRIDE 0xc8  /*register offset*/
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_STRIDE_WR_STRIDE_MASK 0xffff
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_STRIDE_WR_STRIDE_SHIFT 0x0
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_STRIDE_UNUSED0_MASK 0xffff0000
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_STRIDE_UNUSED0_SHIFT 0x10

#define regJPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_0 0xcc  /*register offset*/
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_0_BLOCKS_PER_COL_MASK 0xffff
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_0_BLOCKS_PER_COL_SHIFT 0x0
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_0_BLOCKS_PER_ROW_MASK 0xffff0000
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_0_BLOCKS_PER_ROW_SHIFT 0x10

#define regJPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_1 0xd0  /*register offset*/
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_1_H_STEP_MASK 0xffff
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_1_H_STEP_SHIFT 0x0
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_1_LAST_H_STEP_MASK 0x1ff0000
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_1_LAST_H_STEP_SHIFT 0x10
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_1_UNUSED0_MASK 0xfe000000
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_1_UNUSED0_SHIFT 0x19

#define regJPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_2 0xd4  /*register offset*/
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_2_V_STEP_MASK 0xffff
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_2_V_STEP_SHIFT 0x0
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_2_LAST_V_STEP_MASK 0xffff0000
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_2_LAST_V_STEP_SHIFT 0x10

#define regJPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_3 0xd8  /*register offset*/
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_3_V_INIT_MASK 0xffff
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_3_V_INIT_SHIFT 0x0
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_3_H_INIT_MASK 0xffff0000
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_3_H_INIT_SHIFT 0x10

#define regJPEG_DMA_JPEG_3_WE_QOS_CFG 0x144  /*register offset*/
#define JPEG_DMA_JPEG_3_WE_QOS_CFG_BUFFER_LVL_000_PRIORITY_MASK 0xf
#define JPEG_DMA_JPEG_3_WE_QOS_CFG_BUFFER_LVL_000_PRIORITY_SHIFT 0x0
#define JPEG_DMA_JPEG_3_WE_QOS_CFG_BUFFER_LVL_001_PRIORITY_MASK 0xf0
#define JPEG_DMA_JPEG_3_WE_QOS_CFG_BUFFER_LVL_001_PRIORITY_SHIFT 0x4
#define JPEG_DMA_JPEG_3_WE_QOS_CFG_BUFFER_LVL_010_PRIORITY_MASK 0xf00
#define JPEG_DMA_JPEG_3_WE_QOS_CFG_BUFFER_LVL_010_PRIORITY_SHIFT 0x8
#define JPEG_DMA_JPEG_3_WE_QOS_CFG_BUFFER_LVL_011_PRIORITY_MASK 0xf000
#define JPEG_DMA_JPEG_3_WE_QOS_CFG_BUFFER_LVL_011_PRIORITY_SHIFT 0xc
#define JPEG_DMA_JPEG_3_WE_QOS_CFG_BUFFER_LVL_100_PRIORITY_MASK 0xf0000
#define JPEG_DMA_JPEG_3_WE_QOS_CFG_BUFFER_LVL_100_PRIORITY_SHIFT 0x10
#define JPEG_DMA_JPEG_3_WE_QOS_CFG_BUFFER_LVL_101_PRIORITY_MASK 0xf00000
#define JPEG_DMA_JPEG_3_WE_QOS_CFG_BUFFER_LVL_101_PRIORITY_SHIFT 0x14
#define JPEG_DMA_JPEG_3_WE_QOS_CFG_BUFFER_LVL_110_PRIORITY_MASK 0xf000000
#define JPEG_DMA_JPEG_3_WE_QOS_CFG_BUFFER_LVL_110_PRIORITY_SHIFT 0x18
#define JPEG_DMA_JPEG_3_WE_QOS_CFG_BUFFER_LVL_111_PRIORITY_MASK 0xf0000000
#define JPEG_DMA_JPEG_3_WE_QOS_CFG_BUFFER_LVL_111_PRIORITY_SHIFT 0x1c

#define regJPEG_DMA_JPEG_3_WE_PLN_0_WR_PNTR_CNT 0x148  /*register offset*/
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_PNTR_CNT_WR_PNTR_CNT_MASK 0x7
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_PNTR_CNT_WR_PNTR_CNT_SHIFT 0x0
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_PNTR_CNT_UNUSED0_MASK 0xfffffff8
#define JPEG_DMA_JPEG_3_WE_PLN_0_WR_PNTR_CNT_UNUSED0_SHIFT 0x3

#define regJPEG_DMA_JPEG_3_TEST_BUS_CTRL 0x158  /*register offset*/
#define JPEG_DMA_JPEG_3_TEST_BUS_CTRL_TEST_BUS_SEL_MASK 0x3f
#define JPEG_DMA_JPEG_3_TEST_BUS_CTRL_TEST_BUS_SEL_SHIFT 0x0
#define JPEG_DMA_JPEG_3_TEST_BUS_CTRL_UNUSED0_MASK 0xffffffc0
#define JPEG_DMA_JPEG_3_TEST_BUS_CTRL_UNUSED0_SHIFT 0x6

#define regJPEG_DMA_JPEG_3_SPARE 0x15c  /*register offset*/
#define JPEG_DMA_JPEG_3_SPARE_TEMP_MASK 0xffffffff
#define JPEG_DMA_JPEG_3_SPARE_TEMP_SHIFT 0x0

#define regJPEG_DMA_JPEG_3_BUS_MISR_CFG_0 0x160  /*register offset*/
#define JPEG_DMA_JPEG_3_BUS_MISR_CFG_0_FE_0_SAMP_MODE_MASK 0x3
#define JPEG_DMA_JPEG_3_BUS_MISR_CFG_0_FE_0_SAMP_MODE_SHIFT 0x0
#define JPEG_DMA_JPEG_3_BUS_MISR_CFG_0_FE_0_ENABLE_MASK 0x4
#define JPEG_DMA_JPEG_3_BUS_MISR_CFG_0_FE_0_ENABLE_SHIFT 0x2
#define JPEG_DMA_JPEG_3_BUS_MISR_CFG_0_UNUSED0_MASK 0xf8
#define JPEG_DMA_JPEG_3_BUS_MISR_CFG_0_UNUSED0_SHIFT 0x3
#define JPEG_DMA_JPEG_3_BUS_MISR_CFG_0_WE_0_SAMP_MODE_MASK 0x300
#define JPEG_DMA_JPEG_3_BUS_MISR_CFG_0_WE_0_SAMP_MODE_SHIFT 0x8
#define JPEG_DMA_JPEG_3_BUS_MISR_CFG_0_WE_0_ENABLE_MASK 0x400
#define JPEG_DMA_JPEG_3_BUS_MISR_CFG_0_WE_0_ENABLE_SHIFT 0xa
#define JPEG_DMA_JPEG_3_BUS_MISR_CFG_0_UNUSED1_MASK 0xfffff800
#define JPEG_DMA_JPEG_3_BUS_MISR_CFG_0_UNUSED1_SHIFT 0xb

#define regJPEG_DMA_JPEG_3_BUS_MISR_CFG_1 0x164  /*register offset*/
#define JPEG_DMA_JPEG_3_BUS_MISR_CFG_1_MISR_MAST_SEL_MASK 0x3
#define JPEG_DMA_JPEG_3_BUS_MISR_CFG_1_MISR_MAST_SEL_SHIFT 0x0
#define JPEG_DMA_JPEG_3_BUS_MISR_CFG_1_UNUSED0_MASK 0xc
#define JPEG_DMA_JPEG_3_BUS_MISR_CFG_1_UNUSED0_SHIFT 0x2
#define JPEG_DMA_JPEG_3_BUS_MISR_CFG_1_MISR_RD_WORD_SEL_MASK 0x30
#define JPEG_DMA_JPEG_3_BUS_MISR_CFG_1_MISR_RD_WORD_SEL_SHIFT 0x4
#define JPEG_DMA_JPEG_3_BUS_MISR_CFG_1_UNUSED1_MASK 0xffffffc0
#define JPEG_DMA_JPEG_3_BUS_MISR_CFG_1_UNUSED1_SHIFT 0x6

#define regJPEG_DMA_JPEG_3_BUS_MISR_RD_VAL 0x168  /*register offset*/
#define JPEG_DMA_JPEG_3_BUS_MISR_RD_VAL_MISR_VAL_MASK 0xffffffff
#define JPEG_DMA_JPEG_3_BUS_MISR_RD_VAL_MISR_VAL_SHIFT 0x0

#define regJPEG_DMA_JPEG_3_CORE_STATUS 0x170  /*register offset*/
#define JPEG_DMA_JPEG_3_CORE_STATUS_BUS_ACTIVE_MASK 0x1
#define JPEG_DMA_JPEG_3_CORE_STATUS_BUS_ACTIVE_SHIFT 0x0
#define JPEG_DMA_JPEG_3_CORE_STATUS_SCALE_ACTIVE_MASK 0x2
#define JPEG_DMA_JPEG_3_CORE_STATUS_SCALE_ACTIVE_SHIFT 0x1
#define JPEG_DMA_JPEG_3_CORE_STATUS_JPEG_CLK_CGC_EN_MASK 0x4
#define JPEG_DMA_JPEG_3_CORE_STATUS_JPEG_CLK_CGC_EN_SHIFT 0x2
#define JPEG_DMA_JPEG_3_CORE_STATUS_UNUSED0_MASK 0xfffffff8
#define JPEG_DMA_JPEG_3_CORE_STATUS_UNUSED0_SHIFT 0x3

#define regJPEG_DMA_JPEG_3_PP_0_SCALE_CFG 0x188  /*register offset*/
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_UNUSED0_MASK 0xf
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_UNUSED0_SHIFT 0x0
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_HSCALE_ENABLE_MASK 0x10
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_HSCALE_ENABLE_SHIFT 0x4
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_VSCALE_ENABLE_MASK 0x20
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_VSCALE_ENABLE_SHIFT 0x5
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_UPSAMPLE_EN_MASK 0x40
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_UPSAMPLE_EN_SHIFT 0x6
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_SUBSAMPLE_EN_MASK 0x80
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_SUBSAMPLE_EN_SHIFT 0x7
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_HSCALE_ALGORITHM_MASK 0x100
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_HSCALE_ALGORITHM_SHIFT 0x8
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_VSCALE_ALGORITHM_MASK 0x200
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_VSCALE_ALGORITHM_SHIFT 0x9
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_UNUSED1_MASK 0xc00
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_UNUSED1_SHIFT 0xa
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_H_SCALE_FIR_ALGORITHM_MASK 0x3000
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_H_SCALE_FIR_ALGORITHM_SHIFT 0xc
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_UNUSED2_MASK 0xc000
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_UNUSED2_SHIFT 0xe
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_V_SCALE_FIR_ALGORITHM_MASK 0x30000
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_V_SCALE_FIR_ALGORITHM_SHIFT 0x10
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_UNUSED3_MASK 0xfffc0000
#define JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_UNUSED3_SHIFT 0x12

#define regJPEG_DMA_JPEG_3_S0_S1_MMU_PF_CNTL 0x18c  /*register offset*/
#define JPEG_DMA_JPEG_3_S0_S1_MMU_PF_CNTL_S0_L1_MMU_PREFETCH_EN_MASK 0x1
#define JPEG_DMA_JPEG_3_S0_S1_MMU_PF_CNTL_S0_L1_MMU_PREFETCH_EN_SHIFT 0x0
#define JPEG_DMA_JPEG_3_S0_S1_MMU_PF_CNTL_S0_L1_PERIOD_MASK 0x2
#define JPEG_DMA_JPEG_3_S0_S1_MMU_PF_CNTL_S0_L1_PERIOD_SHIFT 0x1
#define JPEG_DMA_JPEG_3_S0_S1_MMU_PF_CNTL_S0_L1_DIRECTION_MASK 0x4
#define JPEG_DMA_JPEG_3_S0_S1_MMU_PF_CNTL_S0_L1_DIRECTION_SHIFT 0x2
#define JPEG_DMA_JPEG_3_S0_S1_MMU_PF_CNTL_UNUSED0_MASK 0x8
#define JPEG_DMA_JPEG_3_S0_S1_MMU_PF_CNTL_UNUSED0_SHIFT 0x3
#define JPEG_DMA_JPEG_3_S0_S1_MMU_PF_CNTL_S1_L1_MMU_PREFETCH_EN_MASK 0x10
#define JPEG_DMA_JPEG_3_S0_S1_MMU_PF_CNTL_S1_L1_MMU_PREFETCH_EN_SHIFT 0x4
#define JPEG_DMA_JPEG_3_S0_S1_MMU_PF_CNTL_S1_L1_PERIOD_MASK 0x20
#define JPEG_DMA_JPEG_3_S0_S1_MMU_PF_CNTL_S1_L1_PERIOD_SHIFT 0x5
#define JPEG_DMA_JPEG_3_S0_S1_MMU_PF_CNTL_S1_L1_DIRECTION_MASK 0x40
#define JPEG_DMA_JPEG_3_S0_S1_MMU_PF_CNTL_S1_L1_DIRECTION_SHIFT 0x6
#define JPEG_DMA_JPEG_3_S0_S1_MMU_PF_CNTL_UNUSED1_MASK 0xffffff80
#define JPEG_DMA_JPEG_3_S0_S1_MMU_PF_CNTL_UNUSED1_SHIFT 0x7

#define regJPEG_DMA_JPEG_3_S0_MMU_PF_ADDR_MIN 0x190  /*register offset*/
#define JPEG_DMA_JPEG_3_S0_MMU_PF_ADDR_MIN_PF_ADDR_MIN_MASK 0xffffffff
#define JPEG_DMA_JPEG_3_S0_MMU_PF_ADDR_MIN_PF_ADDR_MIN_SHIFT 0x0

#define regJPEG_DMA_JPEG_3_PP_0_SCALE_PHASEH_STEP 0x194  /*register offset*/
#define JPEG_DMA_JPEG_3_PP_0_SCALE_PHASEH_STEP_FRACTIONAL_MASK 0x1fffff
#define JPEG_DMA_JPEG_3_PP_0_SCALE_PHASEH_STEP_FRACTIONAL_SHIFT 0x0
#define JPEG_DMA_JPEG_3_PP_0_SCALE_PHASEH_STEP_INTEGER_MASK 0x1fe00000
#define JPEG_DMA_JPEG_3_PP_0_SCALE_PHASEH_STEP_INTEGER_SHIFT 0x15
#define JPEG_DMA_JPEG_3_PP_0_SCALE_PHASEH_STEP_UNUSED0_MASK 0xe0000000
#define JPEG_DMA_JPEG_3_PP_0_SCALE_PHASEH_STEP_UNUSED0_SHIFT 0x1d

#define regJPEG_DMA_JPEG_3_S0_MMU_PF_ADDR_MAX 0x198  /*register offset*/
#define JPEG_DMA_JPEG_3_S0_MMU_PF_ADDR_MAX_PF_ADDR_MAX_MASK 0xffffffff
#define JPEG_DMA_JPEG_3_S0_MMU_PF_ADDR_MAX_PF_ADDR_MAX_SHIFT 0x0

#define regJPEG_DMA_JPEG_3_PP_0_SCALE_PHASEV_STEP 0x19c  /*register offset*/
#define JPEG_DMA_JPEG_3_PP_0_SCALE_PHASEV_STEP_FRACTIONAL_MASK 0x1fffff
#define JPEG_DMA_JPEG_3_PP_0_SCALE_PHASEV_STEP_FRACTIONAL_SHIFT 0x0
#define JPEG_DMA_JPEG_3_PP_0_SCALE_PHASEV_STEP_INTEGER_MASK 0x1fe00000
#define JPEG_DMA_JPEG_3_PP_0_SCALE_PHASEV_STEP_INTEGER_SHIFT 0x15
#define JPEG_DMA_JPEG_3_PP_0_SCALE_PHASEV_STEP_UNUSED0_MASK 0xe0000000
#define JPEG_DMA_JPEG_3_PP_0_SCALE_PHASEV_STEP_UNUSED0_SHIFT 0x1d

#define regJPEG_DMA_JPEG_3_S0_MMU_PF_CTL_L1_FILTER 0x1a0  /*register offset*/
#define JPEG_DMA_JPEG_3_S0_MMU_PF_CTL_L1_FILTER_L1_FILTER_EN_MASK 0x1
#define JPEG_DMA_JPEG_3_S0_MMU_PF_CTL_L1_FILTER_L1_FILTER_EN_SHIFT 0x0
#define JPEG_DMA_JPEG_3_S0_MMU_PF_CTL_L1_FILTER_UNUSED0_MASK 0xe
#define JPEG_DMA_JPEG_3_S0_MMU_PF_CTL_L1_FILTER_UNUSED0_SHIFT 0x1
#define JPEG_DMA_JPEG_3_S0_MMU_PF_CTL_L1_FILTER_L1_FILTER_DEPTH_MASK 0x70
#define JPEG_DMA_JPEG_3_S0_MMU_PF_CTL_L1_FILTER_L1_FILTER_DEPTH_SHIFT 0x4
#define JPEG_DMA_JPEG_3_S0_MMU_PF_CTL_L1_FILTER_UNUSED1_MASK 0xffffff80
#define JPEG_DMA_JPEG_3_S0_MMU_PF_CTL_L1_FILTER_UNUSED1_SHIFT 0x7

#define regJPEG_DMA_JPEG_3_S1_MMU_PF_ADDR_MIN 0x1a4  /*register offset*/
#define JPEG_DMA_JPEG_3_S1_MMU_PF_ADDR_MIN_PF_ADDR_MIN_MASK 0xffffffff
#define JPEG_DMA_JPEG_3_S1_MMU_PF_ADDR_MIN_PF_ADDR_MIN_SHIFT 0x0

#define regJPEG_DMA_JPEG_3_S1_MMU_PF_ADDR_MAX 0x1ac  /*register offset*/
#define JPEG_DMA_JPEG_3_S1_MMU_PF_ADDR_MAX_PF_ADDR_MAX_MASK 0xffffffff
#define JPEG_DMA_JPEG_3_S1_MMU_PF_ADDR_MAX_PF_ADDR_MAX_SHIFT 0x0

#define regJPEG_DMA_JPEG_3_S1_MMU_PF_CTL_L1_FILTER 0x1b0  /*register offset*/
#define JPEG_DMA_JPEG_3_S1_MMU_PF_CTL_L1_FILTER_L1_FILTER_EN_MASK 0x1
#define JPEG_DMA_JPEG_3_S1_MMU_PF_CTL_L1_FILTER_L1_FILTER_EN_SHIFT 0x0
#define JPEG_DMA_JPEG_3_S1_MMU_PF_CTL_L1_FILTER_UNUSED0_MASK 0xe
#define JPEG_DMA_JPEG_3_S1_MMU_PF_CTL_L1_FILTER_UNUSED0_SHIFT 0x1
#define JPEG_DMA_JPEG_3_S1_MMU_PF_CTL_L1_FILTER_L1_FILTER_DEPTH_MASK 0x70
#define JPEG_DMA_JPEG_3_S1_MMU_PF_CTL_L1_FILTER_L1_FILTER_DEPTH_SHIFT 0x4
#define JPEG_DMA_JPEG_3_S1_MMU_PF_CTL_L1_FILTER_UNUSED1_MASK 0xffffff80
#define JPEG_DMA_JPEG_3_S1_MMU_PF_CTL_L1_FILTER_UNUSED1_SHIFT 0x7

/*----------------------------------------------------------------------
        Register Data Structures
----------------------------------------------------------------------*/

typedef struct{
    unsigned  REVISION : 16; /* 15:0 */
    unsigned  MINOR_VERSION : 12; /* 27:16 */
    unsigned  MAJOR_VERSION : 4; /* 31:28 */
} _jpeg_dma_jpeg_3_hw_version;

typedef union{
    _jpeg_dma_jpeg_3_hw_version bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_HW_VERSION;

typedef struct{
    unsigned  SCALE : 1; /* 0:0 */
    unsigned  NUM_PROCESSING_PIPES : 2; /* 2:1 */
    unsigned  UNUSED0 : 29; /* 31:3 */
} _jpeg_dma_jpeg_3_hw_capability;

typedef union{
    _jpeg_dma_jpeg_3_hw_capability bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_HW_CAPABILITY;

typedef struct{
    unsigned  FE_RESET : 1; /* 0:0 */
    unsigned  WE_RESET : 1; /* 1:1 */
    unsigned  UNUSED0 : 5; /* 6:2 */
    unsigned  SCALE_RESET : 1; /* 7:7 */
    unsigned  UNUSED1 : 5; /* 12:8 */
    unsigned  REGISTER_RESET : 1; /* 13:13 */
    unsigned  UNUSED2 : 2; /* 15:14 */
    unsigned  MISR_RESET : 1; /* 16:16 */
    unsigned  CORE_RESET : 1; /* 17:17 */
    unsigned  UNUSED3 : 11; /* 28:18 */
    unsigned  JPEG_DOMAIN_RESET : 1; /* 29:29 */
    unsigned  UNUSED4 : 1; /* 30:30 */
    unsigned  RESET_BYPASS : 1; /* 31:31 */
} _jpeg_dma_jpeg_3_reset_cmd;

typedef union{
    _jpeg_dma_jpeg_3_reset_cmd bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_RESET_CMD;

typedef struct{
    unsigned  INFO_SESSION_DONE : 1; /* 0:0 */
    unsigned  INFO_FE_0_RD_BUF_DONE : 1; /* 1:1 */
    unsigned  UNUSED0 : 1; /* 2:2 */
    unsigned  INFO_FE_0_RD_BUF_REQ_ATTN : 1; /* 3:3 */
    unsigned  UNUSED1 : 1; /* 4:4 */
    unsigned  INFO_WE_0_WR_BUF_DONE : 1; /* 5:5 */
    unsigned  UNUSED2 : 1; /* 6:6 */
    unsigned  INFO_WE_0_WR_BUF_REQ_ATTN : 1; /* 7:7 */
    unsigned  UNUSED3 : 1; /* 8:8 */
    unsigned  INFO_AXI_HALT_ACK_DONE : 1; /* 9:9 */
    unsigned  INFO_RST_DONE : 1; /* 10:10 */
    unsigned  INFO_PP_0_DONE : 1; /* 11:11 */
    unsigned  UNUSED4 : 20; /* 31:12 */
} _jpeg_dma_jpeg_3_irq_mask;

typedef union{
    _jpeg_dma_jpeg_3_irq_mask bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_IRQ_MASK;

typedef struct{
    unsigned  INFO_SESSION_DONE : 1; /* 0:0 */
    unsigned  INFO_FE_0_RD_BUF_DONE : 1; /* 1:1 */
    unsigned  UNUSED0 : 1; /* 2:2 */
    unsigned  INFO_FE_0_RD_BUF_REQ_ATTN : 1; /* 3:3 */
    unsigned  UNUSED1 : 1; /* 4:4 */
    unsigned  INFO_WE_0_WR_BUF_DONE : 1; /* 5:5 */
    unsigned  UNUSED2 : 1; /* 6:6 */
    unsigned  INFO_WE_0_WR_BUF_REQ_ATTN : 1; /* 7:7 */
    unsigned  UNUSED3 : 1; /* 8:8 */
    unsigned  INFO_AXI_HALT_ACK_DONE : 1; /* 9:9 */
    unsigned  INFO_RST_DONE : 1; /* 10:10 */
    unsigned  INFO_PP_0_DONE : 1; /* 11:11 */
    unsigned  UNUSED4 : 20; /* 31:12 */
} _jpeg_dma_jpeg_3_irq_status;

typedef union{
    _jpeg_dma_jpeg_3_irq_status bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_IRQ_STATUS;

typedef struct{
    unsigned  INFO_SESSION_DONE : 1; /* 0:0 */
    unsigned  INFO_FE_0_RD_BUF_DONE : 1; /* 1:1 */
    unsigned  UNUSED0 : 1; /* 2:2 */
    unsigned  INFO_FE_0_RD_BUF_REQ_ATTN : 1; /* 3:3 */
    unsigned  UNUSED1 : 1; /* 4:4 */
    unsigned  INFO_WE_0_WR_BUF_DONE : 1; /* 5:5 */
    unsigned  UNUSED2 : 1; /* 6:6 */
    unsigned  INFO_WE_0_WR_BUF_REQ_ATTN : 1; /* 7:7 */
    unsigned  UNUSED3 : 1; /* 8:8 */
    unsigned  INFO_AXI_HALT_ACK_DONE : 1; /* 9:9 */
    unsigned  INFO_RST_DONE : 1; /* 10:10 */
    unsigned  INFO_PP_0_DONE : 1; /* 11:11 */
    unsigned  UNUSED4 : 20; /* 31:12 */
} _jpeg_dma_jpeg_3_irq_clear_cmd;

typedef union{
    _jpeg_dma_jpeg_3_irq_clear_cmd bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_IRQ_CLEAR_CMD;

typedef struct{
    unsigned  FE_0_EN : 1; /* 0:0 */
    unsigned  UNUSED0 : 1; /* 1:1 */
    unsigned  WE_0_EN : 1; /* 2:2 */
    unsigned  UNUSED1 : 1; /* 3:3 */
    unsigned  SCALE_0_EN : 1; /* 4:4 */
    unsigned  UNUSED2 : 2; /* 6:5 */
    unsigned  BUS_MISR_EN : 1; /* 7:7 */
    unsigned  UNUSED3 : 11; /* 18:8 */
    unsigned  TEST_BUS_EN : 1; /* 19:19 */
    unsigned  UNUSED4 : 11; /* 30:20 */
    unsigned  CGC_DISABLE : 1; /* 31:31 */
} _jpeg_dma_jpeg_3_core_cfg;

typedef union{
    _jpeg_dma_jpeg_3_core_cfg bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_CORE_CFG;

typedef struct{
    unsigned  HW_START : 1; /* 0:0 */
    unsigned  UNUSED0 : 1; /* 1:1 */
    unsigned  HW_STOP : 1; /* 2:2 */
    unsigned  UNUSED1 : 1; /* 3:3 */
    unsigned  CLEAR_FE_0_QUEUE : 1; /* 4:4 */
    unsigned  UNUSED2 : 3; /* 7:5 */
    unsigned  CLEAR_WE_0_QUEUE : 1; /* 8:8 */
    unsigned  UNUSED3 : 23; /* 31:9 */
} _jpeg_dma_jpeg_3_cmd;

typedef union{
    _jpeg_dma_jpeg_3_cmd bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_CMD;

typedef struct{
    unsigned  BURST_LENGTH_MAX : 4; /* 3:0 */
    unsigned  BLOCK_WIDTH_SEL : 3; /* 6:4 */
    unsigned  UNUSED0 : 1; /* 7:7 */
    unsigned  BOTTOM_VPAD_EN : 1; /* 8:8 */
    unsigned  UNUSED1 : 3; /* 11:9 */
    unsigned  CBCR_ORDER : 1; /* 12:12 */
    unsigned  UNUSED2 : 6; /* 18:13 */
    unsigned  PLN_BLOCK_TYPE : 2; /* 20:19 */
    unsigned  MAL_EN : 1; /* 21:21 */
    unsigned  UNUSED3 : 3; /* 24:22 */
    unsigned  MAL_BOUNDARY : 3; /* 27:25 */
    unsigned  UNUSED4 : 4; /* 31:28 */
} _jpeg_dma_jpeg_3_fe_0_cfg;

typedef union{
    _jpeg_dma_jpeg_3_fe_0_cfg bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_FE_0_CFG;

typedef struct{
    unsigned  PNTR : 32; /* 31:0 */
} _jpeg_dma_jpeg_3_fe_0_rd_pntr;

typedef union{
    _jpeg_dma_jpeg_3_fe_0_rd_pntr bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_FE_0_RD_PNTR;

typedef struct{
    unsigned  PNTR_CNSMD : 32; /* 31:0 */
} _jpeg_dma_jpeg_3_fe_0_rd_pntr_cnsmd;

typedef union{
    _jpeg_dma_jpeg_3_fe_0_rd_pntr_cnsmd bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_FE_0_RD_PNTR_CNSMD;

typedef struct{
    unsigned  PNTR_CNT : 3; /* 2:0 */
    unsigned  UNUSED0 : 29; /* 31:3 */
} _jpeg_dma_jpeg_3_fe_0_rd_pntr_cnt;

typedef union{
    _jpeg_dma_jpeg_3_fe_0_rd_pntr_cnt bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_FE_0_RD_PNTR_CNT;

typedef struct{
    unsigned  WIDTH : 16; /* 15:0 */
    unsigned  HEIGHT : 16; /* 31:16 */
} _jpeg_dma_jpeg_3_fe_0_rd_buffer_size;

typedef union{
    _jpeg_dma_jpeg_3_fe_0_rd_buffer_size bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_FE_0_RD_BUFFER_SIZE;

typedef struct{
    unsigned  STRIDE : 16; /* 15:0 */
    unsigned  UNUSED0 : 16; /* 31:16 */
} _jpeg_dma_jpeg_3_fe_0_rd_stride;

typedef union{
    _jpeg_dma_jpeg_3_fe_0_rd_stride bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_FE_0_RD_STRIDE;

typedef struct{
    unsigned  FRACTIONAL : 21; /* 20:0 */
    unsigned  UNUSED0 : 11; /* 31:21 */
} _jpeg_dma_jpeg_3_fe_0_rd_hinit;

typedef union{
    _jpeg_dma_jpeg_3_fe_0_rd_hinit bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_FE_0_RD_HINIT;

typedef struct{
    unsigned  INTEGER : 17; /* 16:0 */
    unsigned  UNUSED0 : 15; /* 31:17 */
} _jpeg_dma_jpeg_3_fe_0_rd_hinit_int;

typedef union{
    _jpeg_dma_jpeg_3_fe_0_rd_hinit_int bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_FE_0_RD_HINIT_INT;

typedef struct{
    unsigned  FRACTIONAL : 21; /* 20:0 */
    unsigned  UNUSED0 : 11; /* 31:21 */
} _jpeg_dma_jpeg_3_fe_0_rd_vinit;

typedef union{
    _jpeg_dma_jpeg_3_fe_0_rd_vinit bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_FE_0_RD_VINIT;

typedef struct{
    unsigned  INTEGER : 17; /* 16:0 */
    unsigned  UNUSED0 : 15; /* 31:17 */
} _jpeg_dma_jpeg_3_fe_0_rd_vinit_int;

typedef union{
    _jpeg_dma_jpeg_3_fe_0_rd_vinit_int bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_FE_0_RD_VINIT_INT;

typedef struct{
    unsigned  BLOCK_ROW : 13; /* 12:0 */
    unsigned  UNUSED0 : 19; /* 31:13 */
} _jpeg_dma_jpeg_3_fe_0_vbpad_cfg;

typedef union{
    _jpeg_dma_jpeg_3_fe_0_vbpad_cfg bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_FE_0_VBPAD_CFG;

typedef struct{
    unsigned  PRIORITY : 4; /* 3:0 */
    unsigned  UNUSED0 : 28; /* 31:4 */
} _jpeg_dma_jpeg_3_fe_qos_cfg;

typedef union{
    _jpeg_dma_jpeg_3_fe_qos_cfg bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_FE_QOS_CFG;

typedef struct{
    unsigned  BURST_LENGTH_MAX : 4; /* 3:0 */
    unsigned  UNUSED0 : 3; /* 6:4 */
    unsigned  MAL_EN : 1; /* 7:7 */
    unsigned  MAL_BOUNDARY : 3; /* 10:8 */
    unsigned  UNUSED1 : 21; /* 31:11 */
} _jpeg_dma_jpeg_3_we_cfg;

typedef union{
    _jpeg_dma_jpeg_3_we_cfg bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_WE_CFG;

typedef struct{
    unsigned  WR_PNTR : 32; /* 31:0 */
} _jpeg_dma_jpeg_3_we_pln_0_wr_pntr;

typedef union{
    _jpeg_dma_jpeg_3_we_pln_0_wr_pntr bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_WE_PLN_0_WR_PNTR;

typedef struct{
    unsigned  WR_PNTR : 32; /* 31:0 */
} _jpeg_dma_jpeg_3_we_pln_0_wr_pntr_cnsmd;

typedef union{
    _jpeg_dma_jpeg_3_we_pln_0_wr_pntr_cnsmd bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_WE_PLN_0_WR_PNTR_CNSMD;

typedef struct{
    unsigned  WIDTH : 16; /* 15:0 */
    unsigned  HEIGHT : 16; /* 31:16 */
} _jpeg_dma_jpeg_3_we_pln_0_wr_buffer_size;

typedef union{
    _jpeg_dma_jpeg_3_we_pln_0_wr_buffer_size bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_WE_PLN_0_WR_BUFFER_SIZE;

typedef struct{
    unsigned  WR_STRIDE : 16; /* 15:0 */
    unsigned  UNUSED0 : 16; /* 31:16 */
} _jpeg_dma_jpeg_3_we_pln_0_wr_stride;

typedef union{
    _jpeg_dma_jpeg_3_we_pln_0_wr_stride bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_WE_PLN_0_WR_STRIDE;

typedef struct{
    unsigned  BLOCKS_PER_COL : 16; /* 15:0 */
    unsigned  BLOCKS_PER_ROW : 16; /* 31:16 */
} _jpeg_dma_jpeg_3_we_pln_0_wr_cfg_0;

typedef union{
    _jpeg_dma_jpeg_3_we_pln_0_wr_cfg_0 bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_0;

typedef struct{
    unsigned  H_STEP : 16; /* 15:0 */
    unsigned  LAST_H_STEP : 9; /* 24:16 */
    unsigned  UNUSED0 : 7; /* 31:25 */
} _jpeg_dma_jpeg_3_we_pln_0_wr_cfg_1;

typedef union{
    _jpeg_dma_jpeg_3_we_pln_0_wr_cfg_1 bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_1;

typedef struct{
    unsigned  V_STEP : 16; /* 15:0 */
    unsigned  LAST_V_STEP : 16; /* 31:16 */
} _jpeg_dma_jpeg_3_we_pln_0_wr_cfg_2;

typedef union{
    _jpeg_dma_jpeg_3_we_pln_0_wr_cfg_2 bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_2;

typedef struct{
    unsigned  V_INIT : 16; /* 15:0 */
    unsigned  H_INIT : 16; /* 31:16 */
} _jpeg_dma_jpeg_3_we_pln_0_wr_cfg_3;

typedef union{
    _jpeg_dma_jpeg_3_we_pln_0_wr_cfg_3 bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_WE_PLN_0_WR_CFG_3;

typedef struct{
    unsigned  BUFFER_LVL_000_PRIORITY : 4; /* 3:0 */
    unsigned  BUFFER_LVL_001_PRIORITY : 4; /* 7:4 */
    unsigned  BUFFER_LVL_010_PRIORITY : 4; /* 11:8 */
    unsigned  BUFFER_LVL_011_PRIORITY : 4; /* 15:12 */
    unsigned  BUFFER_LVL_100_PRIORITY : 4; /* 19:16 */
    unsigned  BUFFER_LVL_101_PRIORITY : 4; /* 23:20 */
    unsigned  BUFFER_LVL_110_PRIORITY : 4; /* 27:24 */
    unsigned  BUFFER_LVL_111_PRIORITY : 4; /* 31:28 */
} _jpeg_dma_jpeg_3_we_qos_cfg;

typedef union{
    _jpeg_dma_jpeg_3_we_qos_cfg bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_WE_QOS_CFG;

typedef struct{
    unsigned  WR_PNTR_CNT : 3; /* 2:0 */
    unsigned  UNUSED0 : 29; /* 31:3 */
} _jpeg_dma_jpeg_3_we_pln_0_wr_pntr_cnt;

typedef union{
    _jpeg_dma_jpeg_3_we_pln_0_wr_pntr_cnt bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_WE_PLN_0_WR_PNTR_CNT;

typedef struct{
    unsigned  TEST_BUS_SEL : 6; /* 5:0 */
    unsigned  UNUSED0 : 26; /* 31:6 */
} _jpeg_dma_jpeg_3_test_bus_ctrl;

typedef union{
    _jpeg_dma_jpeg_3_test_bus_ctrl bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_TEST_BUS_CTRL;

typedef struct{
    unsigned  TEMP : 32; /* 31:0 */
} _jpeg_dma_jpeg_3_spare;

typedef union{
    _jpeg_dma_jpeg_3_spare bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_SPARE;

typedef struct{
    unsigned  FE_0_SAMP_MODE : 2; /* 1:0 */
    unsigned  FE_0_ENABLE : 1; /* 2:2 */
    unsigned  UNUSED0 : 5; /* 7:3 */
    unsigned  WE_0_SAMP_MODE : 2; /* 9:8 */
    unsigned  WE_0_ENABLE : 1; /* 10:10 */
    unsigned  UNUSED1 : 21; /* 31:11 */
} _jpeg_dma_jpeg_3_bus_misr_cfg_0;

typedef union{
    _jpeg_dma_jpeg_3_bus_misr_cfg_0 bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_BUS_MISR_CFG_0;

typedef struct{
    unsigned  MISR_MAST_SEL : 2; /* 1:0 */
    unsigned  UNUSED0 : 2; /* 3:2 */
    unsigned  MISR_RD_WORD_SEL : 2; /* 5:4 */
    unsigned  UNUSED1 : 26; /* 31:6 */
} _jpeg_dma_jpeg_3_bus_misr_cfg_1;

typedef union{
    _jpeg_dma_jpeg_3_bus_misr_cfg_1 bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_BUS_MISR_CFG_1;

typedef struct{
    unsigned  MISR_VAL : 32; /* 31:0 */
} _jpeg_dma_jpeg_3_bus_misr_rd_val;

typedef union{
    _jpeg_dma_jpeg_3_bus_misr_rd_val bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_BUS_MISR_RD_VAL;

typedef struct{
    unsigned  BUS_ACTIVE : 1; /* 0:0 */
    unsigned  SCALE_ACTIVE : 1; /* 1:1 */
    unsigned  JPEG_CLK_CGC_EN : 1; /* 2:2 */
    unsigned  UNUSED0 : 29; /* 31:3 */
} _jpeg_dma_jpeg_3_core_status;

typedef union{
    _jpeg_dma_jpeg_3_core_status bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_CORE_STATUS;

typedef struct{
    unsigned  UNUSED0 : 4; /* 3:0 */
    unsigned  HSCALE_ENABLE : 1; /* 4:4 */
    unsigned  VSCALE_ENABLE : 1; /* 5:5 */
    unsigned  UPSAMPLE_EN : 1; /* 6:6 */
    unsigned  SUBSAMPLE_EN : 1; /* 7:7 */
    unsigned  HSCALE_ALGORITHM : 1; /* 8:8 */
    unsigned  VSCALE_ALGORITHM : 1; /* 9:9 */
    unsigned  UNUSED1 : 2; /* 11:10 */
    unsigned  H_SCALE_FIR_ALGORITHM : 2; /* 13:12 */
    unsigned  UNUSED2 : 2; /* 15:14 */
    unsigned  V_SCALE_FIR_ALGORITHM : 2; /* 17:16 */
    unsigned  UNUSED3 : 14; /* 31:18 */
} _jpeg_dma_jpeg_3_pp_0_scale_cfg;

typedef union{
    _jpeg_dma_jpeg_3_pp_0_scale_cfg bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_PP_0_SCALE_CFG;

typedef struct{
    unsigned  S0_L1_MMU_PREFETCH_EN : 1; /* 0:0 */
    unsigned  S0_L1_PERIOD : 1; /* 1:1 */
    unsigned  S0_L1_DIRECTION : 1; /* 2:2 */
    unsigned  UNUSED0 : 1; /* 3:3 */
    unsigned  S1_L1_MMU_PREFETCH_EN : 1; /* 4:4 */
    unsigned  S1_L1_PERIOD : 1; /* 5:5 */
    unsigned  S1_L1_DIRECTION : 1; /* 6:6 */
    unsigned  UNUSED1 : 25; /* 31:7 */
} _jpeg_dma_jpeg_3_s0_s1_mmu_pf_cntl;

typedef union{
    _jpeg_dma_jpeg_3_s0_s1_mmu_pf_cntl bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_S0_S1_MMU_PF_CNTL;

typedef struct{
    unsigned  PF_ADDR_MIN : 32; /* 31:0 */
} _jpeg_dma_jpeg_3_s0_mmu_pf_addr_min;

typedef union{
    _jpeg_dma_jpeg_3_s0_mmu_pf_addr_min bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_S0_MMU_PF_ADDR_MIN;

typedef struct{
    unsigned  FRACTIONAL : 21; /* 20:0 */
    unsigned  INTEGER : 8; /* 28:21 */
    unsigned  UNUSED0 : 3; /* 31:29 */
} _jpeg_dma_jpeg_3_pp_0_scale_phaseh_step;

typedef union{
    _jpeg_dma_jpeg_3_pp_0_scale_phaseh_step bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_PP_0_SCALE_PHASEH_STEP;

typedef struct{
    unsigned  PF_ADDR_MAX : 32; /* 31:0 */
} _jpeg_dma_jpeg_3_s0_mmu_pf_addr_max;

typedef union{
    _jpeg_dma_jpeg_3_s0_mmu_pf_addr_max bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_S0_MMU_PF_ADDR_MAX;

typedef struct{
    unsigned  FRACTIONAL : 21; /* 20:0 */
    unsigned  INTEGER : 8; /* 28:21 */
    unsigned  UNUSED0 : 3; /* 31:29 */
} _jpeg_dma_jpeg_3_pp_0_scale_phasev_step;

typedef union{
    _jpeg_dma_jpeg_3_pp_0_scale_phasev_step bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_PP_0_SCALE_PHASEV_STEP;

typedef struct{
    unsigned  L1_FILTER_EN : 1; /* 0:0 */
    unsigned  UNUSED0 : 3; /* 3:1 */
    unsigned  L1_FILTER_DEPTH : 3; /* 6:4 */
    unsigned  UNUSED1 : 25; /* 31:7 */
} _jpeg_dma_jpeg_3_s0_mmu_pf_ctl_l1_filter;

typedef union{
    _jpeg_dma_jpeg_3_s0_mmu_pf_ctl_l1_filter bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_S0_MMU_PF_CTL_L1_FILTER;

typedef struct{
    unsigned  PF_ADDR_MIN : 32; /* 31:0 */
} _jpeg_dma_jpeg_3_s1_mmu_pf_addr_min;

typedef union{
    _jpeg_dma_jpeg_3_s1_mmu_pf_addr_min bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_S1_MMU_PF_ADDR_MIN;

typedef struct{
    unsigned  PF_ADDR_MAX : 32; /* 31:0 */
} _jpeg_dma_jpeg_3_s1_mmu_pf_addr_max;

typedef union{
    _jpeg_dma_jpeg_3_s1_mmu_pf_addr_max bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_S1_MMU_PF_ADDR_MAX;

typedef struct{
    unsigned  L1_FILTER_EN : 1; /* 0:0 */
    unsigned  UNUSED0 : 3; /* 3:1 */
    unsigned  L1_FILTER_DEPTH : 3; /* 6:4 */
    unsigned  UNUSED1 : 25; /* 31:7 */
} _jpeg_dma_jpeg_3_s1_mmu_pf_ctl_l1_filter;

typedef union{
    _jpeg_dma_jpeg_3_s1_mmu_pf_ctl_l1_filter bitfields,bits;
    unsigned int u32All;

} JPEG_DMA_JPEG_3_S1_MMU_PF_CTL_L1_FILTER;

/*----------------------------------------------------------------------
        ENUM Data Structures
----------------------------------------------------------------------*/

typedef enum{
    JPEG_DMA_JPEG_3_CORE_CFG_CGC_DISABLE_CGC_ENABLED  = 0x0,
    JPEG_DMA_JPEG_3_CORE_CFG_CGC_DISABLE_CGC_DISABLED  = 0x1
} JPEG_DMA_JPEG_3_CORE_CFG_CGC_DISABLE_ENUM;


typedef enum{
    JPEG_DMA_JPEG_3_FE_0_CFG_PLN_BLOCK_TYPE_Y_PLANE  = 0x0,
    JPEG_DMA_JPEG_3_FE_0_CFG_PLN_BLOCK_TYPE_CB_PLANE  = 0x1,
    JPEG_DMA_JPEG_3_FE_0_CFG_PLN_BLOCK_TYPE_CR_PLANE  = 0x2,
    JPEG_DMA_JPEG_3_FE_0_CFG_PLN_BLOCK_TYPE_CBCR_PLANE  = 0x3
} JPEG_DMA_JPEG_3_FE_0_CFG_PLN_BLOCK_TYPE_ENUM;


typedef enum{
    JPEG_DMA_JPEG_3_FE_0_CFG_MAL_BOUNDARY_MAL_32_BYTES  = 0x0,
    JPEG_DMA_JPEG_3_FE_0_CFG_MAL_BOUNDARY_MAL_64_BYTES  = 0x1,
    JPEG_DMA_JPEG_3_FE_0_CFG_MAL_BOUNDARY_MAL_128_BYTES  = 0x2,
    JPEG_DMA_JPEG_3_FE_0_CFG_MAL_BOUNDARY_MAL_256_BYTES  = 0x3,
    JPEG_DMA_JPEG_3_FE_0_CFG_MAL_BOUNDARY_MAL_512_BYTES  = 0x4,
    JPEG_DMA_JPEG_3_FE_0_CFG_MAL_BOUNDARY_MAL_1024_BYTES  = 0x5,
    JPEG_DMA_JPEG_3_FE_0_CFG_MAL_BOUNDARY_MAL_2048_BYTES  = 0x6
} JPEG_DMA_JPEG_3_FE_0_CFG_MAL_BOUNDARY_ENUM;


typedef enum{
    JPEG_DMA_JPEG_3_WE_CFG_MAL_BOUNDARY_MAL_32_BYTES  = 0x0,
    JPEG_DMA_JPEG_3_WE_CFG_MAL_BOUNDARY_MAL_64_BYTES  = 0x1,
    JPEG_DMA_JPEG_3_WE_CFG_MAL_BOUNDARY_MAL_128_BYTES  = 0x2,
    JPEG_DMA_JPEG_3_WE_CFG_MAL_BOUNDARY_MAL_256_BYTES  = 0x3,
    JPEG_DMA_JPEG_3_WE_CFG_MAL_BOUNDARY_MAL_512_BYTES  = 0x4,
    JPEG_DMA_JPEG_3_WE_CFG_MAL_BOUNDARY_MAL_1024_BYTES  = 0x5,
    JPEG_DMA_JPEG_3_WE_CFG_MAL_BOUNDARY_MAL_2048_BYTES  = 0x6
} JPEG_DMA_JPEG_3_WE_CFG_MAL_BOUNDARY_ENUM;


typedef enum{
    JPEG_DMA_JPEG_3_BUS_MISR_CFG_1_MISR_MAST_SEL_FE_0  = 0x0,
    JPEG_DMA_JPEG_3_BUS_MISR_CFG_1_MISR_MAST_SEL_WE_0  = 0x2
} JPEG_DMA_JPEG_3_BUS_MISR_CFG_1_MISR_MAST_SEL_ENUM;


typedef enum{
    JPEG_DMA_JPEG_3_BUS_MISR_CFG_1_MISR_RD_WORD_SEL_BITS_0_31  = 0x0,
    JPEG_DMA_JPEG_3_BUS_MISR_CFG_1_MISR_RD_WORD_SEL_BITS_32_63  = 0x1,
    JPEG_DMA_JPEG_3_BUS_MISR_CFG_1_MISR_RD_WORD_SEL_BITS_64_95  = 0x2,
    JPEG_DMA_JPEG_3_BUS_MISR_CFG_1_MISR_RD_WORD_SEL_BITS_96_127  = 0x3
} JPEG_DMA_JPEG_3_BUS_MISR_CFG_1_MISR_RD_WORD_SEL_ENUM;


typedef enum{
    JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_UPSAMPLE_EN_UPSAMPLE_DISABLED  = 0x0,
    JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_UPSAMPLE_EN_UPSAMPLE_ENABLED  = 0x1
} JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_UPSAMPLE_EN_ENUM;


typedef enum{
    JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_SUBSAMPLE_EN_SUBSAMPLE_DISABLED  = 0x0,
    JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_SUBSAMPLE_EN_SUBSAMPLE_ENABLED  = 0x1
} JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_SUBSAMPLE_EN_ENUM;


typedef enum{
    JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_HSCALE_ALGORITHM_MN_DOWNSCALE  = 0x0,
    JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_HSCALE_ALGORITHM_FIR_UPSCALE  = 0x1
} JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_HSCALE_ALGORITHM_ENUM;


typedef enum{
    JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_VSCALE_ALGORITHM_MN_DOWNSCALE  = 0x0,
    JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_VSCALE_ALGORITHM_FIR_UPSCALE  = 0x1
} JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_VSCALE_ALGORITHM_ENUM;


typedef enum{
    JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_H_SCALE_FIR_ALGORITHM_BI_LINEAR  = 0x0,
    JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_H_SCALE_FIR_ALGORITHM_BI_CUBIC  = 0x1,
    JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_H_SCALE_FIR_ALGORITHM_NEAREST_NEIGHBORHOOD  = 0x2
} JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_H_SCALE_FIR_ALGORITHM_ENUM;


typedef enum{
    JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_V_SCALE_FIR_ALGORITHM_BI_LINEAR  = 0x0,
    JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_V_SCALE_FIR_ALGORITHM_BI_CUBIC  = 0x1,
    JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_V_SCALE_FIR_ALGORITHM_NEAREST_NEIGHBORHOOD  = 0x2
} JPEG_DMA_JPEG_3_PP_0_SCALE_CFG_V_SCALE_FIR_ALGORITHM_ENUM;

#endif // TITAN170_JPEG_DMA_H
