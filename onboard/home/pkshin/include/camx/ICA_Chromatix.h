// NOWHINE ENTIRE FILE 
//-------------------------------------------------------------------------
// Copyright (c) 2017-2018 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//------------------------------------------------------------------------


#ifndef __ICA_CHROMATIX_H__
#define __ICA_CHROMATIX_H__

#include "CommonDefs.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ICA_TOP_TAG
{
    // 0: 4x4 kernel
    // 1: Bi-linear (2x2)
    // format: 1u
    PARAM_UINT y_interpolation_type;

} ICA_TOP;

typedef struct ICA_CTC_TAG
{
    // 0: Disabled, 1: Enabled  
    // format: 1u
    PARAM_UINT ctc_transform_grid_enable;

    // 0: 35x27 samples; 1: 67x51
    // format: 2u
    PARAM_UINT ctc_grid_transform_geometry;

    // Grid value for x
    // format: 18sQ4
    PARAM_INT ctc_grid_x[3417];

    // Grid value for y
    // format: 18sQ4
    PARAM_INT ctc_grid_y[3417];

} ICA_CTC;

typedef struct ICA_OPG_TAG
{
    // 0: Out-of-frame pixel is populated with a predefined value.
    // 1: Out-of-frame pixel is populated using duplication.
    // format: 1u
    PARAM_UINT opg_invalid_output_treatment_calculate;

    // Y Output sample values for out-of-input-frame pixels, in case calculate (bit 0) is equal to 0
    // format: 10u
    PARAM_UINT opg_invalid_output_treatment_y;

    // Cb Output sample values for out-of-input-frame pixels, in case calculate (bit 0) is equal to 0
    // format: 10u
    PARAM_UINT opg_invalid_output_treatment_cb;

    // Cr Output sample values for out-of-input-frame pixels, in case calculate (bit 0) is equal to 0
    // format: 10u
    PARAM_UINT opg_invalid_output_treatment_cr;

    // LUT(0)
    // format: 14s
    PARAM_INT opg_interpolation_lut_0[16];

    // LUT(1)
    // format: 14s
    PARAM_INT opg_interpolation_lut_1[16];

    // LUT(2) 
    // format: 14s
    PARAM_INT opg_interpolation_lut_2[16];

} ICA_OPG;

typedef struct ICA_Chromatix_TAG
{
    ICA_TOP top;
    ICA_CTC ctc;
    ICA_OPG opg;
    // Local Motion Compensation Enable bit
    // format: 1u
    PARAM_UINT lmc_enable;

    // Threshold on LMC-refinement difference
    // format: 5uQ4
    PARAM_UINT lmc_mv_diff_thr_full;

    // Threshold on LMC-refinement difference
    // format: 5uQ4
    PARAM_UINT lmc_mv_diff_thr_dc4;

    // DISTORTED_INPUT_TO_UNDISTORTED_LDC_GRID: Grid value for x
    // format: 18sQ3
    PARAM_INT distorted_input_to_undistorted_ldc_grid_x[3417];

    // DISTORTED_INPUT_TO_UNDISTORTED_LDC_GRID: Grid value for y
    // format: 18sQ3
    PARAM_INT distorted_input_to_undistorted_ldc_grid_y[3417];

    // UNDISTORTED_TO_LENS_DISTORTED_OUTPUT_LD_GRID: Grid value for x
    // format: 18sQ3
    PARAM_INT undistorted_to_lens_distorted_output_ld_grid_x[3417];

    // UNDISTORTED_TO_LENS_DISTORTED_OUTPUT_LD_GRID: Grid value for y
    // format: 18sQ3
    PARAM_INT undistorted_to_lens_distorted_output_ld_grid_y[3417];

    // DISTORTED_INPUT_TO_UNDISTORTED_LDC_GRID: is grid valid
    // format: 1u
    PARAM_UINT distorted_input_to_undistorted_ldc_grid_valid;

    // UNDISTORTED_TO_LENS_DISTORTED_OUTPUT_LD_GRID: is grid valid
    // format: 1u
    PARAM_UINT undistorted_to_lens_distorted_output_ld_grid_valid;

    // Reserved parameter 1
    // format: float
    PARAM_FLOAT res_param_1;

    // Reserved parameter 2
    // format: float
    PARAM_FLOAT res_param_2;

    // Reserved parameter 3
    // format: float
    PARAM_FLOAT res_param_3;

    // Reserved parameter 4
    // format: float
    PARAM_FLOAT res_param_4;

    // Reserved parameter 5
    // format: float
    PARAM_FLOAT res_param_5;

    // Reserved parameter 6
    // format: float
    PARAM_FLOAT res_param_6;

    // Reserved parameter 7
    // format: float
    PARAM_FLOAT res_param_7;

    // Reserved parameter 8
    // format: float
    PARAM_FLOAT res_param_8;

    // Reserved parameter 9
    // format: float
    PARAM_FLOAT res_param_9;

    // Reserved parameter 10
    // format: float
    PARAM_FLOAT res_param_10;

    // Reserved Lut parameter 1
    // format: float
    PARAM_FLOAT res_lut_param_1[32];

    // Reserved Lut parameter 2
    // format: float
    PARAM_FLOAT res_lut_param_2[32];

} ICA_Chromatix;

// ############ Functions ############
int32_t Validate_ICA_Chromatix( ICA_Chromatix* regStruct, int hwVersion );
void SetDefaultVal_ICA_Chromatix( ICA_Chromatix* regStruct );
// ###################################
#ifdef __cplusplus
}
#endif


#endif //__ICA_CHROMATIX_H__

