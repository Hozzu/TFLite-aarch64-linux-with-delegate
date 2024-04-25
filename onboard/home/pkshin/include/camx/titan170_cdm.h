/*==============================================================================
 Copyright (c) 2015-2018 Qualcomm Technologies, Inc.
 All Rights Reserved.
 Confidential and Proprietary - Qualcomm Technologies, Inc.
==============================================================================*/
#ifndef TITAN170_CDM_H
#define TITAN170_CDM_H

/*----------------------------------------------------------------------
        Offset and Mask
----------------------------------------------------------------------*/

#define CDM_REGS_FIRST 0x0

#define CDM_REGS_LAST  0x200

#define CDM_REGS_COUNT 0x30

#define regCDM_CPAS_CDM_HW_VERSION 0x0  /*register offset*/
#define CDM_CPAS_CDM_HW_VERSION_REVISION_MASK 0xffff
#define CDM_CPAS_CDM_HW_VERSION_REVISION_SHIFT 0x0
#define CDM_CPAS_CDM_HW_VERSION_MINOR_VERSION_MASK 0xfff0000
#define CDM_CPAS_CDM_HW_VERSION_MINOR_VERSION_SHIFT 0x10
#define CDM_CPAS_CDM_HW_VERSION_MAJOR_VERSION_MASK 0xf0000000
#define CDM_CPAS_CDM_HW_VERSION_MAJOR_VERSION_SHIFT 0x1c

#define regCDM_CPAS_CDM_TITAN_VERSION 0x4  /*register offset*/
#define CDM_CPAS_CDM_TITAN_VERSION_STEP_MASK 0xff
#define CDM_CPAS_CDM_TITAN_VERSION_STEP_SHIFT 0x0
#define CDM_CPAS_CDM_TITAN_VERSION_TIER_MASK 0xff00
#define CDM_CPAS_CDM_TITAN_VERSION_TIER_SHIFT 0x8
#define CDM_CPAS_CDM_TITAN_VERSION_GENERATION_MASK 0xff0000
#define CDM_CPAS_CDM_TITAN_VERSION_GENERATION_SHIFT 0x10
#define CDM_CPAS_CDM_TITAN_VERSION_UNUSED0_MASK 0xff000000
#define CDM_CPAS_CDM_TITAN_VERSION_UNUSED0_SHIFT 0x18

#define regCDM_CPAS_CDM_RST_CMD 0x10  /*register offset*/
#define CDM_CPAS_CDM_RST_CMD_CORE_RST_STB_MASK 0x1
#define CDM_CPAS_CDM_RST_CMD_CORE_RST_STB_SHIFT 0x0
#define CDM_CPAS_CDM_RST_CMD_PERF_MON_RST_STB_MASK 0x2
#define CDM_CPAS_CDM_RST_CMD_PERF_MON_RST_STB_SHIFT 0x1
#define CDM_CPAS_CDM_RST_CMD_MISR_RST_STB_MASK 0x4
#define CDM_CPAS_CDM_RST_CMD_MISR_RST_STB_SHIFT 0x2
#define CDM_CPAS_CDM_RST_CMD_BL_FIFO_RST_STB_MASK 0x8
#define CDM_CPAS_CDM_RST_CMD_BL_FIFO_RST_STB_SHIFT 0x3
#define CDM_CPAS_CDM_RST_CMD_UNUSED0_MASK 0xfffffff0
#define CDM_CPAS_CDM_RST_CMD_UNUSED0_SHIFT 0x4

#define regCDM_CPAS_CDM_CGC_CFG 0x14  /*register offset*/
#define CDM_CPAS_CDM_CGC_CFG_CDM_CGC_OVERRIDE_MASK 0x1
#define CDM_CPAS_CDM_CGC_CFG_CDM_CGC_OVERRIDE_SHIFT 0x0
#define CDM_CPAS_CDM_CGC_CFG_AHB_CGC_OVERRIDE_MASK 0x2
#define CDM_CPAS_CDM_CGC_CFG_AHB_CGC_OVERRIDE_SHIFT 0x1
#define CDM_CPAS_CDM_CGC_CFG_RIF_CGC_OVERRIDE_MASK 0x4
#define CDM_CPAS_CDM_CGC_CFG_RIF_CGC_OVERRIDE_SHIFT 0x2
#define CDM_CPAS_CDM_CGC_CFG_UNUSED0_MASK 0xfffffff8
#define CDM_CPAS_CDM_CGC_CFG_UNUSED0_SHIFT 0x3

#define regCDM_CPAS_CDM_CORE_CFG 0x18  /*register offset*/
#define CDM_CPAS_CDM_CORE_CFG_AHB_BURST_LEN_MASK 0xf
#define CDM_CPAS_CDM_CORE_CFG_AHB_BURST_LEN_SHIFT 0x0
#define CDM_CPAS_CDM_CORE_CFG_AHB_BURST_EN_MASK 0x10
#define CDM_CPAS_CDM_CORE_CFG_AHB_BURST_EN_SHIFT 0x4
#define CDM_CPAS_CDM_CORE_CFG_UNUSED0_MASK 0xe0
#define CDM_CPAS_CDM_CORE_CFG_UNUSED0_SHIFT 0x5
#define CDM_CPAS_CDM_CORE_CFG_AHB_STOP_ON_ERROR_MASK 0x100
#define CDM_CPAS_CDM_CORE_CFG_AHB_STOP_ON_ERROR_SHIFT 0x8
#define CDM_CPAS_CDM_CORE_CFG_UNUSED1_MASK 0xfffffe00
#define CDM_CPAS_CDM_CORE_CFG_UNUSED1_SHIFT 0x9

#define regCDM_CPAS_CDM_CORE_EN 0x1c  /*register offset*/
#define CDM_CPAS_CDM_CORE_EN_CDM_EN_MASK 0x1
#define CDM_CPAS_CDM_CORE_EN_CDM_EN_SHIFT 0x0
#define CDM_CPAS_CDM_CORE_EN_CDM_PAUSE_MASK 0x2
#define CDM_CPAS_CDM_CORE_EN_CDM_PAUSE_SHIFT 0x1
#define CDM_CPAS_CDM_CORE_EN_UNUSED0_MASK 0xfffffffc
#define CDM_CPAS_CDM_CORE_EN_UNUSED0_SHIFT 0x2

#define regCDM_CPAS_CDM_FE_CFG 0x20  /*register offset*/
#define CDM_CPAS_CDM_FE_CFG_AXI_BURST_LEN_MASK 0xf
#define CDM_CPAS_CDM_FE_CFG_AXI_BURST_LEN_SHIFT 0x0
#define CDM_CPAS_CDM_FE_CFG_UNUSED0_MASK 0xfff0
#define CDM_CPAS_CDM_FE_CFG_UNUSED0_SHIFT 0x4
#define CDM_CPAS_CDM_FE_CFG_BUS_RD_CLIENT_REQ_DATA_CNTR_MAX_MASK 0xffff0000
#define CDM_CPAS_CDM_FE_CFG_BUS_RD_CLIENT_REQ_DATA_CNTR_MAX_SHIFT 0x10

#define regCDM_CPAS_CDM_IRQ_MASK 0x30  /*register offset*/
#define CDM_CPAS_CDM_IRQ_MASK_INFO_RST_DONE_MASK 0x1
#define CDM_CPAS_CDM_IRQ_MASK_INFO_RST_DONE_SHIFT 0x0
#define CDM_CPAS_CDM_IRQ_MASK_INFO_INLINE_IRQ_MASK 0x2
#define CDM_CPAS_CDM_IRQ_MASK_INFO_INLINE_IRQ_SHIFT 0x1
#define CDM_CPAS_CDM_IRQ_MASK_INFO_BL_DONE_MASK 0x4
#define CDM_CPAS_CDM_IRQ_MASK_INFO_BL_DONE_SHIFT 0x2
#define CDM_CPAS_CDM_IRQ_MASK_UNUSED0_MASK 0xfff8
#define CDM_CPAS_CDM_IRQ_MASK_UNUSED0_SHIFT 0x3
#define CDM_CPAS_CDM_IRQ_MASK_ERROR_INV_CMD_MASK 0x10000
#define CDM_CPAS_CDM_IRQ_MASK_ERROR_INV_CMD_SHIFT 0x10
#define CDM_CPAS_CDM_IRQ_MASK_ERROR_OVER_FLOW_MASK 0x20000
#define CDM_CPAS_CDM_IRQ_MASK_ERROR_OVER_FLOW_SHIFT 0x11
#define CDM_CPAS_CDM_IRQ_MASK_ERROR_AHB_BUS_MASK 0x40000
#define CDM_CPAS_CDM_IRQ_MASK_ERROR_AHB_BUS_SHIFT 0x12
#define CDM_CPAS_CDM_IRQ_MASK_UNUSED1_MASK 0xfff80000
#define CDM_CPAS_CDM_IRQ_MASK_UNUSED1_SHIFT 0x13

#define regCDM_CPAS_CDM_IRQ_CLEAR 0x34  /*register offset*/
#define CDM_CPAS_CDM_IRQ_CLEAR_INFO_RST_DONE_MASK 0x1
#define CDM_CPAS_CDM_IRQ_CLEAR_INFO_RST_DONE_SHIFT 0x0
#define CDM_CPAS_CDM_IRQ_CLEAR_INFO_INLINE_IRQ_MASK 0x2
#define CDM_CPAS_CDM_IRQ_CLEAR_INFO_INLINE_IRQ_SHIFT 0x1
#define CDM_CPAS_CDM_IRQ_CLEAR_INFO_BL_DONE_MASK 0x4
#define CDM_CPAS_CDM_IRQ_CLEAR_INFO_BL_DONE_SHIFT 0x2
#define CDM_CPAS_CDM_IRQ_CLEAR_UNUSED0_MASK 0xfff8
#define CDM_CPAS_CDM_IRQ_CLEAR_UNUSED0_SHIFT 0x3
#define CDM_CPAS_CDM_IRQ_CLEAR_ERROR_INV_CMD_MASK 0x10000
#define CDM_CPAS_CDM_IRQ_CLEAR_ERROR_INV_CMD_SHIFT 0x10
#define CDM_CPAS_CDM_IRQ_CLEAR_ERROR_OVER_FLOW_MASK 0x20000
#define CDM_CPAS_CDM_IRQ_CLEAR_ERROR_OVER_FLOW_SHIFT 0x11
#define CDM_CPAS_CDM_IRQ_CLEAR_ERROR_AHB_BUS_MASK 0x40000
#define CDM_CPAS_CDM_IRQ_CLEAR_ERROR_AHB_BUS_SHIFT 0x12
#define CDM_CPAS_CDM_IRQ_CLEAR_UNUSED1_MASK 0xfff80000
#define CDM_CPAS_CDM_IRQ_CLEAR_UNUSED1_SHIFT 0x13

#define regCDM_CPAS_CDM_IRQ_CLEAR_CMD 0x38  /*register offset*/
#define CDM_CPAS_CDM_IRQ_CLEAR_CMD_IRQ_CLEAR_CMD_MASK 0x1
#define CDM_CPAS_CDM_IRQ_CLEAR_CMD_IRQ_CLEAR_CMD_SHIFT 0x0
#define CDM_CPAS_CDM_IRQ_CLEAR_CMD_UNUSED0_MASK 0xfffffffe
#define CDM_CPAS_CDM_IRQ_CLEAR_CMD_UNUSED0_SHIFT 0x1

#define regCDM_CPAS_CDM_IRQ_SET 0x3c  /*register offset*/
#define CDM_CPAS_CDM_IRQ_SET_INFO_RST_DONE_MASK 0x1
#define CDM_CPAS_CDM_IRQ_SET_INFO_RST_DONE_SHIFT 0x0
#define CDM_CPAS_CDM_IRQ_SET_INFO_INLINE_IRQ_MASK 0x2
#define CDM_CPAS_CDM_IRQ_SET_INFO_INLINE_IRQ_SHIFT 0x1
#define CDM_CPAS_CDM_IRQ_SET_INFO_BL_DONE_MASK 0x4
#define CDM_CPAS_CDM_IRQ_SET_INFO_BL_DONE_SHIFT 0x2
#define CDM_CPAS_CDM_IRQ_SET_UNUSED0_MASK 0xfff8
#define CDM_CPAS_CDM_IRQ_SET_UNUSED0_SHIFT 0x3
#define CDM_CPAS_CDM_IRQ_SET_ERROR_INV_CMD_MASK 0x10000
#define CDM_CPAS_CDM_IRQ_SET_ERROR_INV_CMD_SHIFT 0x10
#define CDM_CPAS_CDM_IRQ_SET_ERROR_OVER_FLOW_MASK 0x20000
#define CDM_CPAS_CDM_IRQ_SET_ERROR_OVER_FLOW_SHIFT 0x11
#define CDM_CPAS_CDM_IRQ_SET_ERROR_AHB_BUS_MASK 0x40000
#define CDM_CPAS_CDM_IRQ_SET_ERROR_AHB_BUS_SHIFT 0x12
#define CDM_CPAS_CDM_IRQ_SET_UNUSED1_MASK 0xfff80000
#define CDM_CPAS_CDM_IRQ_SET_UNUSED1_SHIFT 0x13

#define regCDM_CPAS_CDM_IRQ_SET_CMD 0x40  /*register offset*/
#define CDM_CPAS_CDM_IRQ_SET_CMD_IRQ_SET_CMD_MASK 0x1
#define CDM_CPAS_CDM_IRQ_SET_CMD_IRQ_SET_CMD_SHIFT 0x0
#define CDM_CPAS_CDM_IRQ_SET_CMD_UNUSED0_MASK 0xfffffffe
#define CDM_CPAS_CDM_IRQ_SET_CMD_UNUSED0_SHIFT 0x1

#define regCDM_CPAS_CDM_IRQ_STATUS 0x44  /*register offset*/
#define CDM_CPAS_CDM_IRQ_STATUS_INFO_RST_DONE_MASK 0x1
#define CDM_CPAS_CDM_IRQ_STATUS_INFO_RST_DONE_SHIFT 0x0
#define CDM_CPAS_CDM_IRQ_STATUS_INFO_INLINE_IRQ_MASK 0x2
#define CDM_CPAS_CDM_IRQ_STATUS_INFO_INLINE_IRQ_SHIFT 0x1
#define CDM_CPAS_CDM_IRQ_STATUS_INFO_BL_DONE_MASK 0x4
#define CDM_CPAS_CDM_IRQ_STATUS_INFO_BL_DONE_SHIFT 0x2
#define CDM_CPAS_CDM_IRQ_STATUS_UNUSED0_MASK 0xfff8
#define CDM_CPAS_CDM_IRQ_STATUS_UNUSED0_SHIFT 0x3
#define CDM_CPAS_CDM_IRQ_STATUS_ERROR_INV_CMD_MASK 0x10000
#define CDM_CPAS_CDM_IRQ_STATUS_ERROR_INV_CMD_SHIFT 0x10
#define CDM_CPAS_CDM_IRQ_STATUS_ERROR_OVER_FLOW_MASK 0x20000
#define CDM_CPAS_CDM_IRQ_STATUS_ERROR_OVER_FLOW_SHIFT 0x11
#define CDM_CPAS_CDM_IRQ_STATUS_ERROR_AHB_BUS_MASK 0x40000
#define CDM_CPAS_CDM_IRQ_STATUS_ERROR_AHB_BUS_SHIFT 0x12
#define CDM_CPAS_CDM_IRQ_STATUS_UNUSED1_MASK 0xfff80000
#define CDM_CPAS_CDM_IRQ_STATUS_UNUSED1_SHIFT 0x13

#define regCDM_CPAS_CDM_BL_FIFO_BASE_REG 0x50  /*register offset*/
#define CDM_CPAS_CDM_BL_FIFO_BASE_REG_BASE_MASK 0xffffffff
#define CDM_CPAS_CDM_BL_FIFO_BASE_REG_BASE_SHIFT 0x0

#define regCDM_CPAS_CDM_BL_FIFO_LEN_REG 0x54  /*register offset*/
#define CDM_CPAS_CDM_BL_FIFO_LEN_REG_LEN_MASK 0xfffff
#define CDM_CPAS_CDM_BL_FIFO_LEN_REG_LEN_SHIFT 0x0
#define CDM_CPAS_CDM_BL_FIFO_LEN_REG_UNUSED0_MASK 0xf00000
#define CDM_CPAS_CDM_BL_FIFO_LEN_REG_UNUSED0_SHIFT 0x14
#define CDM_CPAS_CDM_BL_FIFO_LEN_REG_TAG_MASK 0xff000000
#define CDM_CPAS_CDM_BL_FIFO_LEN_REG_TAG_SHIFT 0x18

#define regCDM_CPAS_CDM_BL_FIFO_STORE_REG 0x58  /*register offset*/
#define CDM_CPAS_CDM_BL_FIFO_STORE_REG_COMMIT_MASK 0x1
#define CDM_CPAS_CDM_BL_FIFO_STORE_REG_COMMIT_SHIFT 0x0
#define CDM_CPAS_CDM_BL_FIFO_STORE_REG_UNUSED0_MASK 0xfffffffe
#define CDM_CPAS_CDM_BL_FIFO_STORE_REG_UNUSED0_SHIFT 0x1

#define regCDM_CPAS_CDM_BL_FIFO_CFG 0x5c  /*register offset*/
#define CDM_CPAS_CDM_BL_FIFO_CFG_REQ_SIZE_MASK 0x3
#define CDM_CPAS_CDM_BL_FIFO_CFG_REQ_SIZE_SHIFT 0x0
#define CDM_CPAS_CDM_BL_FIFO_CFG_UNUSED0_MASK 0xfffffffc
#define CDM_CPAS_CDM_BL_FIFO_CFG_UNUSED0_SHIFT 0x2

#define regCDM_CPAS_CDM_BL_FIFO_RB 0x60  /*register offset*/
#define CDM_CPAS_CDM_BL_FIFO_RB_FIFO_OFFSET_MASK 0x3f
#define CDM_CPAS_CDM_BL_FIFO_RB_FIFO_OFFSET_SHIFT 0x0
#define CDM_CPAS_CDM_BL_FIFO_RB_UNUSED0_MASK 0xffffffc0
#define CDM_CPAS_CDM_BL_FIFO_RB_UNUSED0_SHIFT 0x6

#define regCDM_CPAS_CDM_BL_FIFO_BASE_RB 0x64  /*register offset*/
#define CDM_CPAS_CDM_BL_FIFO_BASE_RB_BASE_MASK 0xffffffff
#define CDM_CPAS_CDM_BL_FIFO_BASE_RB_BASE_SHIFT 0x0

#define regCDM_CPAS_CDM_BL_FIFO_LEN_RB 0x68  /*register offset*/
#define CDM_CPAS_CDM_BL_FIFO_LEN_RB_LEN_MASK 0xfffff
#define CDM_CPAS_CDM_BL_FIFO_LEN_RB_LEN_SHIFT 0x0
#define CDM_CPAS_CDM_BL_FIFO_LEN_RB_UNUSED0_MASK 0xf00000
#define CDM_CPAS_CDM_BL_FIFO_LEN_RB_UNUSED0_SHIFT 0x14
#define CDM_CPAS_CDM_BL_FIFO_LEN_RB_TAG_MASK 0xff000000
#define CDM_CPAS_CDM_BL_FIFO_LEN_RB_TAG_SHIFT 0x18

#define regCDM_CPAS_CDM_BL_FIFO_PENDING_REQ_RB 0x6c  /*register offset*/
#define CDM_CPAS_CDM_BL_FIFO_PENDING_REQ_RB_PENDING_REQ_MASK 0x7f
#define CDM_CPAS_CDM_BL_FIFO_PENDING_REQ_RB_PENDING_REQ_SHIFT 0x0
#define CDM_CPAS_CDM_BL_FIFO_PENDING_REQ_RB_UNUSED0_MASK 0xffffff80
#define CDM_CPAS_CDM_BL_FIFO_PENDING_REQ_RB_UNUSED0_SHIFT 0x7

#define regCDM_CPAS_CDM_IRQ_USR_DATA 0x80  /*register offset*/
#define CDM_CPAS_CDM_IRQ_USR_DATA_VALUE_MASK 0xffffffff
#define CDM_CPAS_CDM_IRQ_USR_DATA_VALUE_SHIFT 0x0

#define regCDM_CPAS_CDM_WAIT_STATUS 0x84  /*register offset*/
#define CDM_CPAS_CDM_WAIT_STATUS_MASK_MASK 0xff
#define CDM_CPAS_CDM_WAIT_STATUS_MASK_SHIFT 0x0
#define CDM_CPAS_CDM_WAIT_STATUS_ID_MASK 0xff00
#define CDM_CPAS_CDM_WAIT_STATUS_ID_SHIFT 0x8
#define CDM_CPAS_CDM_WAIT_STATUS_WAITING_MASK 0x10000
#define CDM_CPAS_CDM_WAIT_STATUS_WAITING_SHIFT 0x10
#define CDM_CPAS_CDM_WAIT_STATUS_UNUSED0_MASK 0xfffe0000
#define CDM_CPAS_CDM_WAIT_STATUS_UNUSED0_SHIFT 0x11

#define regCDM_CPAS_CDM_SCRATCH_0_REG 0x90  /*register offset*/
#define CDM_CPAS_CDM_SCRATCH_0_REG_GP_REG_MASK 0xffffffff
#define CDM_CPAS_CDM_SCRATCH_0_REG_GP_REG_SHIFT 0x0

#define regCDM_CPAS_CDM_SCRATCH_1_REG 0x94  /*register offset*/
#define CDM_CPAS_CDM_SCRATCH_1_REG_GP_REG_MASK 0xffffffff
#define CDM_CPAS_CDM_SCRATCH_1_REG_GP_REG_SHIFT 0x0

#define regCDM_CPAS_CDM_SCRATCH_2_REG 0x98  /*register offset*/
#define CDM_CPAS_CDM_SCRATCH_2_REG_GP_REG_MASK 0xffffffff
#define CDM_CPAS_CDM_SCRATCH_2_REG_GP_REG_SHIFT 0x0

#define regCDM_CPAS_CDM_SCRATCH_3_REG 0x9c  /*register offset*/
#define CDM_CPAS_CDM_SCRATCH_3_REG_GP_REG_MASK 0xffffffff
#define CDM_CPAS_CDM_SCRATCH_3_REG_GP_REG_SHIFT 0x0

#define regCDM_CPAS_CDM_SCRATCH_4_REG 0xa0  /*register offset*/
#define CDM_CPAS_CDM_SCRATCH_4_REG_GP_REG_MASK 0xffffffff
#define CDM_CPAS_CDM_SCRATCH_4_REG_GP_REG_SHIFT 0x0

#define regCDM_CPAS_CDM_SCRATCH_5_REG 0xa4  /*register offset*/
#define CDM_CPAS_CDM_SCRATCH_5_REG_GP_REG_MASK 0xffffffff
#define CDM_CPAS_CDM_SCRATCH_5_REG_GP_REG_SHIFT 0x0

#define regCDM_CPAS_CDM_SCRATCH_6_REG 0xa8  /*register offset*/
#define CDM_CPAS_CDM_SCRATCH_6_REG_GP_REG_MASK 0xffffffff
#define CDM_CPAS_CDM_SCRATCH_6_REG_GP_REG_SHIFT 0x0

#define regCDM_CPAS_CDM_SCRATCH_7_REG 0xac  /*register offset*/
#define CDM_CPAS_CDM_SCRATCH_7_REG_GP_REG_MASK 0xffffffff
#define CDM_CPAS_CDM_SCRATCH_7_REG_GP_REG_SHIFT 0x0

#define regCDM_CPAS_CDM_LAST_AHB_ADDR 0xd0  /*register offset*/
#define CDM_CPAS_CDM_LAST_AHB_ADDR_ADDR_MASK 0xffffffff
#define CDM_CPAS_CDM_LAST_AHB_ADDR_ADDR_SHIFT 0x0

#define regCDM_CPAS_CDM_LAST_AHB_DATA 0xd4  /*register offset*/
#define CDM_CPAS_CDM_LAST_AHB_DATA_DATA_MASK 0xffffffff
#define CDM_CPAS_CDM_LAST_AHB_DATA_DATA_SHIFT 0x0

#define regCDM_CPAS_CDM_CORE_DBUG 0xd8  /*register offset*/
#define CDM_CPAS_CDM_CORE_DBUG_TEST_BUS_EN_MASK 0x1
#define CDM_CPAS_CDM_CORE_DBUG_TEST_BUS_EN_SHIFT 0x0
#define CDM_CPAS_CDM_CORE_DBUG_UNUSED0_MASK 0xe
#define CDM_CPAS_CDM_CORE_DBUG_UNUSED0_SHIFT 0x1
#define CDM_CPAS_CDM_CORE_DBUG_TEST_BUS_SEL_MASK 0xf0
#define CDM_CPAS_CDM_CORE_DBUG_TEST_BUS_SEL_SHIFT 0x4
#define CDM_CPAS_CDM_CORE_DBUG_LOG_AHB_MASK 0x100
#define CDM_CPAS_CDM_CORE_DBUG_LOG_AHB_SHIFT 0x8
#define CDM_CPAS_CDM_CORE_DBUG_UNUSED1_MASK 0xfe00
#define CDM_CPAS_CDM_CORE_DBUG_UNUSED1_SHIFT 0x9
#define CDM_CPAS_CDM_CORE_DBUG_BL_FIFO_RD_EN_MASK 0x10000
#define CDM_CPAS_CDM_CORE_DBUG_BL_FIFO_RD_EN_SHIFT 0x10
#define CDM_CPAS_CDM_CORE_DBUG_UNUSED2_MASK 0xfffe0000
#define CDM_CPAS_CDM_CORE_DBUG_UNUSED2_SHIFT 0x11

#define regCDM_CPAS_CDM_LAST_AHB_ERR_ADDR 0xe0  /*register offset*/
#define CDM_CPAS_CDM_LAST_AHB_ERR_ADDR_ADDR_MASK 0xffffffff
#define CDM_CPAS_CDM_LAST_AHB_ERR_ADDR_ADDR_SHIFT 0x0

#define regCDM_CPAS_CDM_LAST_AHB_ERR_DATA 0xe4  /*register offset*/
#define CDM_CPAS_CDM_LAST_AHB_ERR_DATA_DATA_MASK 0xffffffff
#define CDM_CPAS_CDM_LAST_AHB_ERR_DATA_DATA_SHIFT 0x0

#define regCDM_CPAS_CDM_CURRENT_BL_BASE 0xe8  /*register offset*/
#define CDM_CPAS_CDM_CURRENT_BL_BASE_BASE_MASK 0xffffffff
#define CDM_CPAS_CDM_CURRENT_BL_BASE_BASE_SHIFT 0x0

#define regCDM_CPAS_CDM_CURRENT_BL_LEN 0xec  /*register offset*/
#define CDM_CPAS_CDM_CURRENT_BL_LEN_LEN_MASK 0xfffff
#define CDM_CPAS_CDM_CURRENT_BL_LEN_LEN_SHIFT 0x0
#define CDM_CPAS_CDM_CURRENT_BL_LEN_UNUSED0_MASK 0xf00000
#define CDM_CPAS_CDM_CURRENT_BL_LEN_UNUSED0_SHIFT 0x14
#define CDM_CPAS_CDM_CURRENT_BL_LEN_TAG_MASK 0xff000000
#define CDM_CPAS_CDM_CURRENT_BL_LEN_TAG_SHIFT 0x18

#define regCDM_CPAS_CDM_CURRENT_USED_AHB_BASE 0xf0  /*register offset*/
#define CDM_CPAS_CDM_CURRENT_USED_AHB_BASE_VALUE_MASK 0xffffff
#define CDM_CPAS_CDM_CURRENT_USED_AHB_BASE_VALUE_SHIFT 0x0
#define CDM_CPAS_CDM_CURRENT_USED_AHB_BASE_UNUSED0_MASK 0xff000000
#define CDM_CPAS_CDM_CURRENT_USED_AHB_BASE_UNUSED0_SHIFT 0x18

#define regCDM_CPAS_CDM_DEBUG_STATUS 0xf4  /*register offset*/
#define CDM_CPAS_CDM_DEBUG_STATUS_VALUE_MASK 0xffffffff
#define CDM_CPAS_CDM_DEBUG_STATUS_VALUE_SHIFT 0x0

#define regCDM_CPAS_CDM_BUS_MISR_CFG_0 0x100  /*register offset*/
#define CDM_CPAS_CDM_BUS_MISR_CFG_0_FE_SAMP_MODE_MASK 0x3
#define CDM_CPAS_CDM_BUS_MISR_CFG_0_FE_SAMP_MODE_SHIFT 0x0
#define CDM_CPAS_CDM_BUS_MISR_CFG_0_FE_ENABLE_MASK 0x4
#define CDM_CPAS_CDM_BUS_MISR_CFG_0_FE_ENABLE_SHIFT 0x2
#define CDM_CPAS_CDM_BUS_MISR_CFG_0_UNUSED0_MASK 0xfffffff8
#define CDM_CPAS_CDM_BUS_MISR_CFG_0_UNUSED0_SHIFT 0x3

#define regCDM_CPAS_CDM_BUS_MISR_CFG_1 0x104  /*register offset*/
#define CDM_CPAS_CDM_BUS_MISR_CFG_1_MISR_RD_WORD_SEL_MASK 0x3
#define CDM_CPAS_CDM_BUS_MISR_CFG_1_MISR_RD_WORD_SEL_SHIFT 0x0
#define CDM_CPAS_CDM_BUS_MISR_CFG_1_UNUSED0_MASK 0xfffffffc
#define CDM_CPAS_CDM_BUS_MISR_CFG_1_UNUSED0_SHIFT 0x2

#define regCDM_CPAS_CDM_BUS_MISR_RD_VAL 0x108  /*register offset*/
#define CDM_CPAS_CDM_BUS_MISR_RD_VAL_MISR_VAL_MASK 0xffffffff
#define CDM_CPAS_CDM_BUS_MISR_RD_VAL_MISR_VAL_SHIFT 0x0

#define regCDM_CPAS_CDM_PERF_MON_CTRL 0x110  /*register offset*/
#define CDM_CPAS_CDM_PERF_MON_CTRL_PERF_MON_EN_MASK 0x1
#define CDM_CPAS_CDM_PERF_MON_CTRL_PERF_MON_EN_SHIFT 0x0
#define CDM_CPAS_CDM_PERF_MON_CTRL_UNUSED0_MASK 0xfffffffe
#define CDM_CPAS_CDM_PERF_MON_CTRL_UNUSED0_SHIFT 0x1

#define regCDM_CPAS_CDM_PERF_MON_0 0x114  /*register offset*/
#define CDM_CPAS_CDM_PERF_MON_0_TOTAL_CYCLES_MASK 0xffffffff
#define CDM_CPAS_CDM_PERF_MON_0_TOTAL_CYCLES_SHIFT 0x0

#define regCDM_CPAS_CDM_PERF_MON_1 0x118  /*register offset*/
#define CDM_CPAS_CDM_PERF_MON_1_TOTAL_CYCLES_MASK 0xffffffff
#define CDM_CPAS_CDM_PERF_MON_1_TOTAL_CYCLES_SHIFT 0x0

#define regCDM_CPAS_CDM_PERF_MON_2 0x11c  /*register offset*/
#define CDM_CPAS_CDM_PERF_MON_2_TOTAL_CYCLES_MASK 0xffffffff
#define CDM_CPAS_CDM_PERF_MON_2_TOTAL_CYCLES_SHIFT 0x0

#define regCDM_CPAS_CDM_SPARE 0x200  /*register offset*/
#define CDM_CPAS_CDM_SPARE_SPARE_MASK 0x1
#define CDM_CPAS_CDM_SPARE_SPARE_SHIFT 0x0
#define CDM_CPAS_CDM_SPARE_UNUSED0_MASK 0xfffffffe
#define CDM_CPAS_CDM_SPARE_UNUSED0_SHIFT 0x1

/*----------------------------------------------------------------------
        Register Data Structures
----------------------------------------------------------------------*/

typedef struct{
    unsigned  REVISION : 16; /* 15:0 */
    unsigned  MINOR_VERSION : 12; /* 27:16 */
    unsigned  MAJOR_VERSION : 4; /* 31:28 */
} _cdm_cpas_cdm_hw_version;

typedef union{
    _cdm_cpas_cdm_hw_version bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_HW_VERSION;

typedef struct{
    unsigned  STEP : 8; /* 7:0 */
    unsigned  TIER : 8; /* 15:8 */
    unsigned  GENERATION : 8; /* 23:16 */
    unsigned  UNUSED0 : 8; /* 31:24 */
} _cdm_cpas_cdm_titan_version;

typedef union{
    _cdm_cpas_cdm_titan_version bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_TITAN_VERSION;

typedef struct{
    unsigned  CORE_RST_STB : 1; /* 0:0 */
    unsigned  PERF_MON_RST_STB : 1; /* 1:1 */
    unsigned  MISR_RST_STB : 1; /* 2:2 */
    unsigned  BL_FIFO_RST_STB : 1; /* 3:3 */
    unsigned  UNUSED0 : 28; /* 31:4 */
} _cdm_cpas_cdm_rst_cmd;

typedef union{
    _cdm_cpas_cdm_rst_cmd bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_RST_CMD;

typedef struct{
    unsigned  CDM_CGC_OVERRIDE : 1; /* 0:0 */
    unsigned  AHB_CGC_OVERRIDE : 1; /* 1:1 */
    unsigned  RIF_CGC_OVERRIDE : 1; /* 2:2 */
    unsigned  UNUSED0 : 29; /* 31:3 */
} _cdm_cpas_cdm_cgc_cfg;

typedef union{
    _cdm_cpas_cdm_cgc_cfg bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_CGC_CFG;

typedef struct{
    unsigned  AHB_BURST_LEN : 4; /* 3:0 */
    unsigned  AHB_BURST_EN : 1; /* 4:4 */
    unsigned  UNUSED0 : 3; /* 7:5 */
    unsigned  AHB_STOP_ON_ERROR : 1; /* 8:8 */
    unsigned  UNUSED1 : 23; /* 31:9 */
} _cdm_cpas_cdm_core_cfg;

typedef union{
    _cdm_cpas_cdm_core_cfg bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_CORE_CFG;

typedef struct{
    unsigned  CDM_EN : 1; /* 0:0 */
    unsigned  CDM_PAUSE : 1; /* 1:1 */
    unsigned  UNUSED0 : 30; /* 31:2 */
} _cdm_cpas_cdm_core_en;

typedef union{
    _cdm_cpas_cdm_core_en bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_CORE_EN;

typedef struct{
    unsigned  AXI_BURST_LEN : 4; /* 3:0 */
    unsigned  UNUSED0 : 12; /* 15:4 */
    unsigned  BUS_RD_CLIENT_REQ_DATA_CNTR_MAX : 16; /* 31:16 */
} _cdm_cpas_cdm_fe_cfg;

typedef union{
    _cdm_cpas_cdm_fe_cfg bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_FE_CFG;

typedef struct{
    unsigned  INFO_RST_DONE : 1; /* 0:0 */
    unsigned  INFO_INLINE_IRQ : 1; /* 1:1 */
    unsigned  INFO_BL_DONE : 1; /* 2:2 */
    unsigned  UNUSED0 : 13; /* 15:3 */
    unsigned  ERROR_INV_CMD : 1; /* 16:16 */
    unsigned  ERROR_OVER_FLOW : 1; /* 17:17 */
    unsigned  ERROR_AHB_BUS : 1; /* 18:18 */
    unsigned  UNUSED1 : 13; /* 31:19 */
} _cdm_cpas_cdm_irq_mask;

typedef union{
    _cdm_cpas_cdm_irq_mask bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_IRQ_MASK;

typedef struct{
    unsigned  INFO_RST_DONE : 1; /* 0:0 */
    unsigned  INFO_INLINE_IRQ : 1; /* 1:1 */
    unsigned  INFO_BL_DONE : 1; /* 2:2 */
    unsigned  UNUSED0 : 13; /* 15:3 */
    unsigned  ERROR_INV_CMD : 1; /* 16:16 */
    unsigned  ERROR_OVER_FLOW : 1; /* 17:17 */
    unsigned  ERROR_AHB_BUS : 1; /* 18:18 */
    unsigned  UNUSED1 : 13; /* 31:19 */
} _cdm_cpas_cdm_irq_clear;

typedef union{
    _cdm_cpas_cdm_irq_clear bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_IRQ_CLEAR;

typedef struct{
    unsigned  IRQ_CLEAR_CMD : 1; /* 0:0 */
    unsigned  UNUSED0 : 31; /* 31:1 */
} _cdm_cpas_cdm_irq_clear_cmd;

typedef union{
    _cdm_cpas_cdm_irq_clear_cmd bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_IRQ_CLEAR_CMD;

typedef struct{
    unsigned  INFO_RST_DONE : 1; /* 0:0 */
    unsigned  INFO_INLINE_IRQ : 1; /* 1:1 */
    unsigned  INFO_BL_DONE : 1; /* 2:2 */
    unsigned  UNUSED0 : 13; /* 15:3 */
    unsigned  ERROR_INV_CMD : 1; /* 16:16 */
    unsigned  ERROR_OVER_FLOW : 1; /* 17:17 */
    unsigned  ERROR_AHB_BUS : 1; /* 18:18 */
    unsigned  UNUSED1 : 13; /* 31:19 */
} _cdm_cpas_cdm_irq_set;

typedef union{
    _cdm_cpas_cdm_irq_set bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_IRQ_SET;

typedef struct{
    unsigned  IRQ_SET_CMD : 1; /* 0:0 */
    unsigned  UNUSED0 : 31; /* 31:1 */
} _cdm_cpas_cdm_irq_set_cmd;

typedef union{
    _cdm_cpas_cdm_irq_set_cmd bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_IRQ_SET_CMD;

typedef struct{
    unsigned  INFO_RST_DONE : 1; /* 0:0 */
    unsigned  INFO_INLINE_IRQ : 1; /* 1:1 */
    unsigned  INFO_BL_DONE : 1; /* 2:2 */
    unsigned  UNUSED0 : 13; /* 15:3 */
    unsigned  ERROR_INV_CMD : 1; /* 16:16 */
    unsigned  ERROR_OVER_FLOW : 1; /* 17:17 */
    unsigned  ERROR_AHB_BUS : 1; /* 18:18 */
    unsigned  UNUSED1 : 13; /* 31:19 */
} _cdm_cpas_cdm_irq_status;

typedef union{
    _cdm_cpas_cdm_irq_status bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_IRQ_STATUS;

typedef struct{
    unsigned  BASE : 32; /* 31:0 */
} _cdm_cpas_cdm_bl_fifo_base_reg;

typedef union{
    _cdm_cpas_cdm_bl_fifo_base_reg bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_BL_FIFO_BASE_REG;

typedef struct{
    unsigned  LEN : 20; /* 19:0 */
    unsigned  UNUSED0 : 4; /* 23:20 */
    unsigned  TAG : 8; /* 31:24 */
} _cdm_cpas_cdm_bl_fifo_len_reg;

typedef union{
    _cdm_cpas_cdm_bl_fifo_len_reg bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_BL_FIFO_LEN_REG;

typedef struct{
    unsigned  COMMIT : 1; /* 0:0 */
    unsigned  UNUSED0 : 31; /* 31:1 */
} _cdm_cpas_cdm_bl_fifo_store_reg;

typedef union{
    _cdm_cpas_cdm_bl_fifo_store_reg bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_BL_FIFO_STORE_REG;

typedef struct{
    unsigned  REQ_SIZE : 2; /* 1:0 */
    unsigned  UNUSED0 : 30; /* 31:2 */
} _cdm_cpas_cdm_bl_fifo_cfg;

typedef union{
    _cdm_cpas_cdm_bl_fifo_cfg bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_BL_FIFO_CFG;

typedef struct{
    unsigned  FIFO_OFFSET : 6; /* 5:0 */
    unsigned  UNUSED0 : 26; /* 31:6 */
} _cdm_cpas_cdm_bl_fifo_rb;

typedef union{
    _cdm_cpas_cdm_bl_fifo_rb bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_BL_FIFO_RB;

typedef struct{
    unsigned  BASE : 32; /* 31:0 */
} _cdm_cpas_cdm_bl_fifo_base_rb;

typedef union{
    _cdm_cpas_cdm_bl_fifo_base_rb bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_BL_FIFO_BASE_RB;

typedef struct{
    unsigned  LEN : 20; /* 19:0 */
    unsigned  UNUSED0 : 4; /* 23:20 */
    unsigned  TAG : 8; /* 31:24 */
} _cdm_cpas_cdm_bl_fifo_len_rb;

typedef union{
    _cdm_cpas_cdm_bl_fifo_len_rb bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_BL_FIFO_LEN_RB;

typedef struct{
    unsigned  PENDING_REQ : 7; /* 6:0 */
    unsigned  UNUSED0 : 25; /* 31:7 */
} _cdm_cpas_cdm_bl_fifo_pending_req_rb;

typedef union{
    _cdm_cpas_cdm_bl_fifo_pending_req_rb bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_BL_FIFO_PENDING_REQ_RB;

typedef struct{
    unsigned  VALUE : 32; /* 31:0 */
} _cdm_cpas_cdm_irq_usr_data;

typedef union{
    _cdm_cpas_cdm_irq_usr_data bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_IRQ_USR_DATA;

typedef struct{
    unsigned  MASK : 8; /* 7:0 */
    unsigned  ID : 8; /* 15:8 */
    unsigned  WAITING : 1; /* 16:16 */
    unsigned  UNUSED0 : 15; /* 31:17 */
} _cdm_cpas_cdm_wait_status;

typedef union{
    _cdm_cpas_cdm_wait_status bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_WAIT_STATUS;

typedef struct{
    unsigned  GP_REG : 32; /* 31:0 */
} _cdm_cpas_cdm_scratch_0_reg;

typedef union{
    _cdm_cpas_cdm_scratch_0_reg bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_SCRATCH_0_REG;

typedef struct{
    unsigned  GP_REG : 32; /* 31:0 */
} _cdm_cpas_cdm_scratch_1_reg;

typedef union{
    _cdm_cpas_cdm_scratch_1_reg bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_SCRATCH_1_REG;

typedef struct{
    unsigned  GP_REG : 32; /* 31:0 */
} _cdm_cpas_cdm_scratch_2_reg;

typedef union{
    _cdm_cpas_cdm_scratch_2_reg bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_SCRATCH_2_REG;

typedef struct{
    unsigned  GP_REG : 32; /* 31:0 */
} _cdm_cpas_cdm_scratch_3_reg;

typedef union{
    _cdm_cpas_cdm_scratch_3_reg bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_SCRATCH_3_REG;

typedef struct{
    unsigned  GP_REG : 32; /* 31:0 */
} _cdm_cpas_cdm_scratch_4_reg;

typedef union{
    _cdm_cpas_cdm_scratch_4_reg bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_SCRATCH_4_REG;

typedef struct{
    unsigned  GP_REG : 32; /* 31:0 */
} _cdm_cpas_cdm_scratch_5_reg;

typedef union{
    _cdm_cpas_cdm_scratch_5_reg bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_SCRATCH_5_REG;

typedef struct{
    unsigned  GP_REG : 32; /* 31:0 */
} _cdm_cpas_cdm_scratch_6_reg;

typedef union{
    _cdm_cpas_cdm_scratch_6_reg bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_SCRATCH_6_REG;

typedef struct{
    unsigned  GP_REG : 32; /* 31:0 */
} _cdm_cpas_cdm_scratch_7_reg;

typedef union{
    _cdm_cpas_cdm_scratch_7_reg bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_SCRATCH_7_REG;

typedef struct{
    unsigned  ADDR : 32; /* 31:0 */
} _cdm_cpas_cdm_last_ahb_addr;

typedef union{
    _cdm_cpas_cdm_last_ahb_addr bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_LAST_AHB_ADDR;

typedef struct{
    unsigned  DATA : 32; /* 31:0 */
} _cdm_cpas_cdm_last_ahb_data;

typedef union{
    _cdm_cpas_cdm_last_ahb_data bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_LAST_AHB_DATA;

typedef struct{
    unsigned  TEST_BUS_EN : 1; /* 0:0 */
    unsigned  UNUSED0 : 3; /* 3:1 */
    unsigned  TEST_BUS_SEL : 4; /* 7:4 */
    unsigned  LOG_AHB : 1; /* 8:8 */
    unsigned  UNUSED1 : 7; /* 15:9 */
    unsigned  BL_FIFO_RD_EN : 1; /* 16:16 */
    unsigned  UNUSED2 : 15; /* 31:17 */
} _cdm_cpas_cdm_core_dbug;

typedef union{
    _cdm_cpas_cdm_core_dbug bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_CORE_DBUG;

typedef struct{
    unsigned  ADDR : 32; /* 31:0 */
} _cdm_cpas_cdm_last_ahb_err_addr;

typedef union{
    _cdm_cpas_cdm_last_ahb_err_addr bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_LAST_AHB_ERR_ADDR;

typedef struct{
    unsigned  DATA : 32; /* 31:0 */
} _cdm_cpas_cdm_last_ahb_err_data;

typedef union{
    _cdm_cpas_cdm_last_ahb_err_data bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_LAST_AHB_ERR_DATA;

typedef struct{
    unsigned  BASE : 32; /* 31:0 */
} _cdm_cpas_cdm_current_bl_base;

typedef union{
    _cdm_cpas_cdm_current_bl_base bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_CURRENT_BL_BASE;

typedef struct{
    unsigned  LEN : 20; /* 19:0 */
    unsigned  UNUSED0 : 4; /* 23:20 */
    unsigned  TAG : 8; /* 31:24 */
} _cdm_cpas_cdm_current_bl_len;

typedef union{
    _cdm_cpas_cdm_current_bl_len bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_CURRENT_BL_LEN;

typedef struct{
    unsigned  VALUE : 24; /* 23:0 */
    unsigned  UNUSED0 : 8; /* 31:24 */
} _cdm_cpas_cdm_current_used_ahb_base;

typedef union{
    _cdm_cpas_cdm_current_used_ahb_base bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_CURRENT_USED_AHB_BASE;

typedef struct{
    unsigned  VALUE : 32; /* 31:0 */
} _cdm_cpas_cdm_debug_status;

typedef union{
    _cdm_cpas_cdm_debug_status bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_DEBUG_STATUS;

typedef struct{
    unsigned  FE_SAMP_MODE : 2; /* 1:0 */
    unsigned  FE_ENABLE : 1; /* 2:2 */
    unsigned  UNUSED0 : 29; /* 31:3 */
} _cdm_cpas_cdm_bus_misr_cfg_0;

typedef union{
    _cdm_cpas_cdm_bus_misr_cfg_0 bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_BUS_MISR_CFG_0;

typedef struct{
    unsigned  MISR_RD_WORD_SEL : 2; /* 1:0 */
    unsigned  UNUSED0 : 30; /* 31:2 */
} _cdm_cpas_cdm_bus_misr_cfg_1;

typedef union{
    _cdm_cpas_cdm_bus_misr_cfg_1 bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_BUS_MISR_CFG_1;

typedef struct{
    unsigned  MISR_VAL : 32; /* 31:0 */
} _cdm_cpas_cdm_bus_misr_rd_val;

typedef union{
    _cdm_cpas_cdm_bus_misr_rd_val bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_BUS_MISR_RD_VAL;

typedef struct{
    unsigned  PERF_MON_EN : 1; /* 0:0 */
    unsigned  UNUSED0 : 31; /* 31:1 */
} _cdm_cpas_cdm_perf_mon_ctrl;

typedef union{
    _cdm_cpas_cdm_perf_mon_ctrl bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_PERF_MON_CTRL;

typedef struct{
    unsigned  TOTAL_CYCLES : 32; /* 31:0 */
} _cdm_cpas_cdm_perf_mon_0;

typedef union{
    _cdm_cpas_cdm_perf_mon_0 bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_PERF_MON_0;

typedef struct{
    unsigned  TOTAL_CYCLES : 32; /* 31:0 */
} _cdm_cpas_cdm_perf_mon_1;

typedef union{
    _cdm_cpas_cdm_perf_mon_1 bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_PERF_MON_1;

typedef struct{
    unsigned  TOTAL_CYCLES : 32; /* 31:0 */
} _cdm_cpas_cdm_perf_mon_2;

typedef union{
    _cdm_cpas_cdm_perf_mon_2 bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_PERF_MON_2;

typedef struct{
    unsigned  SPARE : 1; /* 0:0 */
    unsigned  UNUSED0 : 31; /* 31:1 */
} _cdm_cpas_cdm_spare;

typedef union{
    _cdm_cpas_cdm_spare bitfields,bits;
    unsigned int u32All;

} CDM_CPAS_CDM_SPARE;

/*----------------------------------------------------------------------
        ENUM Data Structures
----------------------------------------------------------------------*/

typedef enum{
    CDM_CPAS_CDM_BL_FIFO_CFG_REQ_SIZE_MAXSIZE  = 0x0,
    CDM_CPAS_CDM_BL_FIFO_CFG_REQ_SIZE_MAXSIZE_DIV2  = 0x1,
    CDM_CPAS_CDM_BL_FIFO_CFG_REQ_SIZE_MAXSIZE_DIV4  = 0x2,
    CDM_CPAS_CDM_BL_FIFO_CFG_REQ_SIZE_MAXSIZE_DIV8  = 0x3
} CDM_CPAS_CDM_BL_FIFO_CFG_REQ_SIZE_ENUM;


typedef enum{
    CDM_CPAS_CDM_BUS_MISR_CFG_1_MISR_RD_WORD_SEL_BITS_0_31  = 0x0,
    CDM_CPAS_CDM_BUS_MISR_CFG_1_MISR_RD_WORD_SEL_BITS_32_63  = 0x1,
    CDM_CPAS_CDM_BUS_MISR_CFG_1_MISR_RD_WORD_SEL_BITS_64_95  = 0x2,
    CDM_CPAS_CDM_BUS_MISR_CFG_1_MISR_RD_WORD_SEL_BITS_96_127  = 0x3
} CDM_CPAS_CDM_BUS_MISR_CFG_1_MISR_RD_WORD_SEL_ENUM;

#endif // TITAN170_CDM_H
