// NOWHINE ENTIRE FILE 
//-------------------------------------------------------------------------
// Copyright (c) 2018 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//------------------------------------------------------------------------

#ifndef __NCLIB_INTERNAL_H__
#define __NCLIB_INTERNAL_H__
    
#include "ANR_Chromatix.h"
#include "ANR_Registers.h"
#include "NcLibContext.h"

#include "TF_Chromatix.h"
#include "TF_Registers.h"

enum EICAGridBitDepth {
    ICA20_GRID_BIT_DEPTH_MINUS_1 = 16,
    ICA30_GRID_BIT_DEPTH_MINUS_1 = 17
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ANR structures and functions
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct ANR_PASS_CONFIGURATION_TAG
{
    uint32_t imageWidthPixels;                     /**< Input image with no grid or matrices applied */
    uint32_t imageHeightPixels;
    uint32_t fullPassImageWidthPixels;
    uint32_t fullPassImageHeightPixels;

    uint32_t imageWidthPixelsWithMargins;
    uint32_t imageHeightPixelsWithMargins;
    uint32_t fullPassImageWidthPixelsWithMargins;
    uint32_t fullPassImageHeightPixelsWithMargins;

    uint32_t imageScale;
    uint32_t imageScaleInBitShifts;

    uint32_t hwBitsNumber;
    // need it in order to enable dcblend with lower pass and inter-length usage. ( if lower pass is disabled then LowerPassAvailable = False )
    NCLIB_BOOLEAN yLowerScaleAvailable;
    // need it in order to enable dcblend with lower pass and inter-length usage. ( if lower pass is disabled then LowerPassAvailable = False )
    NCLIB_BOOLEAN cLowerScaleAvailable;
    // need it in order to enable pdi packing for higher pass
    NCLIB_BOOLEAN higherPassAvailable;

    void *pFullPassLnr; // a pointer to the Full pass LNR Chromatix parameters for the case of use_luts_from_full_pass_configuration in the current pass, should be treated as ANR_LNR* type

} ANR_PASS_CONFIGURATION;

int32_t ANR_ConcludeFrameLevelRegistersConfiguration(
    ANR_Chromatix* chromatixStruct,
    NCLIB_CONTEXT_ANR* context,
    IPEANRRegCmd* regStruct,
    ANR_PASS_CONFIGURATION* passConfiguration,
    AnrPassParameters* fwStruct);

int32_t ANR_CalcWarpDependedParams(
    ANR_Chromatix* chromatixStruct,
    NCLIB_CONTEXT_ANR* context,
    IPEANRRegCmd* regStruct,
    ANR_PASS_CONFIGURATION* passConfiguration,
    AnrPassParameters* fwPassStruct);

void ANR_ProcessNcLibPass(
    ANR_Chromatix* chromatixPassParams,
    IPEANRRegCmd* registerStruct,
    ANR_PASS_CONFIGURATION* passConfiguration);

// modules configuration
void ANR_Process_DcUpscaler(
    ANR_Chromatix* Chromatix,
    IPEANRRegCmd* registerStruct,
    ANR_PASS_CONFIGURATION* passConfiguration);
void ANR_Process_DCBlend1(ANR_Chromatix* Chromatix, IPEANRRegCmd* registerStruct, ANR_PASS_CONFIGURATION* passConfiguration);
void ANR_Process_CNR(ANR_Chromatix* Chromatix, IPEANRRegCmd* registerStruct, ANR_PASS_CONFIGURATION* passConfiguration);

void ANR_Process_CYLPF(
    ANR_Chromatix* Chromatix,
    IPEANRRegCmd* registerStruct,
    ANR_PASS_CONFIGURATION* passConfiguration);

/* ANR_Process_Lnr:
Config Internal Registers that control LNR
ANR_Process_Lnr uses optical_center_x, optical_center_y as the optical center.
they should be arbitrated with Chromatix before entering.
*/
int32_t ANR_Process_Lnr(
    ANR_Chromatix* Chromatix,
    IPEANRRegCmd* regPass,
    PARAM_UINT optical_center_x,
    PARAM_UINT optical_center_y,
    ANR_PASS_CONFIGURATION* passConfiguration,
    AnrPassParameters* fwPassStruct);

void ANR_Process_CYLPF_Filter2(ANR_Chromatix* Chromatix, IPEANRRegCmd* registerStruct);
void ANR_Process_DCBlend2(ANR_Chromatix* Chromatix, IPEANRRegCmd* registerStruct, ANR_PASS_CONFIGURATION* passConfiguration);
void ANR_Process_RNF(ANR_Chromatix* Chromatix, IPEANRRegCmd* registerStruct, ANR_PASS_CONFIGURATION* passConfiguration);
void ANR_Process_PDI_PACK(ANR_Chromatix* Chromatix, IPEANRRegCmd* registerStruct, ANR_PASS_CONFIGURATION* passConfiguration);

//general functions
void ANR_IsCnrEnabled(ANR_Chromatix* Chromatix, NCLIB_BOOLEAN* isCnrEnabled);
FIELD_UINT ANR_IsDcb2GreyChromeModificationEnable(ANR_Chromatix* Chromatix);
void ANR_IsDcb2Bypassed(ANR_PASS_CONFIGURATION* passConfiguration, ANR_Chromatix* Chromatix, uint32_t* DCB2_Y_Bypass, uint32_t* DCB2_C_Bypass);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ICA functions
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool NcLibIsGridSizeMatchesIcaHw(uint32_t numRows, uint32_t numColumns); // RTODO: remove once Warp fully support dual ICA version
bool NcLibIsGridSizeMatchesIcaHw(uint32_t numRows, uint32_t numColumns, uint32_t icaVersion);

uint32_t Get_ICA_OutputWidth(NCLIB_CONTEXT_TF* context, uint32_t curPassScalingRatioLog4);
uint32_t Get_ICA_OutputHeight(NCLIB_CONTEXT_TF* context, uint32_t curPassScalingRatioLog4);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TF functions
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
*  @brief   Function that helps to set frame level registers (non geometric) according to flow settings.
*           There is assumption that this function is called after TF_ProcessNcLib
*
*
*  @param [in]      chromatixStruct           TF Chromatix struct
*  @param [in]      context                   Contains SW information which is relevant for activation
*  @param [in]      curPassScalingRatioLog4   Define which pass is used
*                                             0 - full pass
*                                             1 - DC4  pass
*                                             2 - DC16 pass
*                                             3 - DC64 pass
*  @param [in]      numOfPasses               Defines how many passes are used
*  @param [in,out]  regStruct                 Output TF register struct
*  @param [in,out]  fwStructRefinement        Output Refinement FW struct
*  @param [in,out]  fwStructTf                Output TF FW struct
*  @param [out]     fwStructLmc               Output LMC FW struct
*
*  @return void
*/
void TF_ConcludeFrameLevelRegistersConfiguration(
    TF_Chromatix* chromatixStruct,
    NCLIB_CONTEXT_TF* context,
    uint32_t curPassScalingRatioLog4,
    uint32_t numOfPasses,
    IPETFRegCmd* regStruct,
    RefinementPassParameters* fwStructRefinement,
    TfPassParameters* fwStructTf,
    LmcPassParameters* fwStructLmc);

/**
*  @brief   Function that help to convert Chromatix settings into register and FW structs
*
*
*  @param [in]      chromatixStruct           TF Chromatix struct
*  @param [in]      flow                      Define in which flow mode TF is activated
*  @param [in]      curPassScalingRatioLog4   Define which pass is used
*                                             0 - full pass
*                                             1 - DC4  pass
*                                             2 - DC16 pass
*                                             3 - DC64 pass
*  @param [in,out]  regStruct                 Output TF register struct
*  @param [in,out]  fwStructTf                Output TF FW struct
*  @param [out]     fwStructRefinement        Output Refinement FW struct
*
*  @return void
*/
void TF_ProcessNcLib(
    TF_Chromatix* chromatixStruct,
    EIPEConfigOption flow,
    uint32_t curPassScalingRatioLog4,
    IPETFRegCmd* regStruct,
    TfPassParameters* fwStructTf,
    RefinementPassParameters* fwStructRefinement);


/**
*  @brief   Function that calculate some parameters which are related to warp results (e.g. update
*           geometric registers and registers which are related to LRME results).
*           There is assumption that this function is called after TF_ProcessNcLib and
*           TF_ConcludeFrameLevelRegistersConfiguration
*
*
*  @param [in]      chromatixStruct           TF Chromatix struct
*  @param [in]      context                   Contains SW information which is relevant for activation
*  @param [in]      curPassScalingRatioLog4   Define which pass is used
*                                             0 - full pass
*                                             1 - DC4  pass
*                                             2 - DC16 pass
*                                             3 - DC64 pass
*  @param [in]      transformConfidenceVal    Defines mapping function from calculated transform
*                                             confidence to actually used transform confidence.
*                                             The calculated confidence is in the
*                                             range 0:256 (8 bit fraction). format: 9uQ8
*                                             In case transformConfidenceVal is set to 256, the
*                                             confidence has no effect
*  @param [in,out]  regStruct                 Output TF register struct
*  @param [in,out]  fwStructTf                Output TF FW struct
*
*  @return NC_LIB_SUCCESS in case of success, otherwise failed.
*/
int32_t TF_CalcWarpDependedParams(
    TF_Chromatix* chromatixStruct,
    NCLIB_CONTEXT_TF* context,
    uint32_t curPassScalingRatioLog4,
    uint32_t transformConfidenceVal,
    IPETFRegCmd* regStruct,
    TfPassParameters* fwStructTf);

#endif //__NCLIB_INTERNAL_H__
