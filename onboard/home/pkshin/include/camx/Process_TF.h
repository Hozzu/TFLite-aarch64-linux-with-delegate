// NOWHINE ENTIRE FILE 
//-------------------------------------------------------------------------
// Copyright (c) 2017-2018 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//------------------------------------------------------------------------

#ifndef __PROCESS_TF_H__
#define __PROCESS_TF_H__

#include "TF_Chromatix.h"
#include "TF_Registers.h"
#include "NcLibContext.h"

#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------------------------------------------------
*       API Functions
* ----------------------------------------------------------------------- */

/**
*  @brief   Calculate TF, Refinement and LMC FW structs and TF registers for all passes
*           Calls TF_ProcessNcLib, TF_ConcludeFrameLevelRegistersConfiguration and TF_CalcWarpDependedParams
*           for each pass that do almost all the work.
*
*
*  @param [in]      chromatixStruct           Array of TF Chromatix structs with at least numOfPasses elements
*  @param [in]      context                   Contains SW information which is relevant for activation
*  @param [in]      numOfPasses               Defines how many passes are used
*  @param [in]      transformConfidenceVal    Defines mapping function from calculated transform
*                                             confidence to actually used transform confidence.
*                                             The calculated confidence range is 0:256 (8 bit fraction). format: 9uQ8
*                                             If transformConfidenceVal is set to 256 confidence has no effect.
*  @param [out]     regStruct                 Output array of TF register structs with at least numOfPasses elements
*  @param [out]     fwRefinementParameters    Output Refinement FW struct
*  @param [out]     fwTfParameters            Output TF FW struct
*  @param [out]     fwLmcParameters           Output LMC FW struct
*
*  @return NC_LIB_SUCCESS in case of success, otherwise failed.
*/
int32_t TF_ProcessNcLibFull(
    TF_Chromatix          chromatixStruct[],
    NCLIB_CONTEXT_TF*     context,
    uint32_t              numOfPasses,
    uint32_t              transformConfidenceVal,
    IPETFRegCmd     regStruct[],
    RefinementParameters* fwRefinementParameters,
    TfParameters*         fwTfParameters,
    LmcParameters*        fwLmcParameters);

/**
*  @brief   Validate TF SW Context
*
*
*  @param [in]      nclibContext              Contains SW information which is relevant for activation
*  @param [in]      curPassScalingRatioLog4   Define which pass is used
*                                             0 - full pass
*                                             1 - DC4  pass
*                                             2 - DC16 pass
*                                             3 - DC64 pass
*
*  @return NC_LIB_SUCCESS in case of success, otherwise failed.
*/
int32_t ValidateTfContext(NCLIB_CONTEXT_TF* nclibContext, uint32_t curPassScalingRatioLog4);

/**
*  @brief   Validate TF Refinement calculation result
*
*
*  @param [in]      fwStructTf                TF FW struct
*  @param [in]      fwStructRefinement        Refinement FW struct
*  @param [in]      curPassScalingRatioLog4   Define which pass is used
*                                             0 - full pass
*                                             1 - DC4  pass
*                                             2 - DC16 pass
*                                             3 - DC64 pass
*
*  @return NC_LIB_SUCCESS in case of success, otherwise failed.
*/
int32_t ValidateTfCalc(TfPassParameters* fwStructTf, RefinementPassParameters* fwStructRefinement, uint32_t curPassScalingRatioLog4);

/**
*  @brief   Set default FW structs settings
*           Should be called immediately after TfPassParameters, RefinementPassParameters and LmcPassParameters creation
*
*  @param [out]     fwStructTf                TF FW struct
*  @param [out]     fwStructRefinement        Refinement FW struct
*  @param [out]     fwStructLmc               LMC FW struct
*/
void SetDefaultsForTFStructs(TfPassParameters* fwStructTf, RefinementPassParameters* fwStructRefinement, LmcPassParameters* fwStructLmc);

/**
*  @brief   Function that validates that relationship between different Chromatix settings are valid.
*
*
*  @param [in]      chromatixStruct           TF Chromatix struct
*  @param [in]      nclibContext              Contains SW information which is relevant for activation
*  @param [in]      curPassScalingRatioLog4   Define which pass is used
*                                             0 - full pass
*                                             1 - DC4  pass
*                                             2 - DC16 pass
*                                             3 - DC64 pass
*
*  @return NC_LIB_SUCCESS in case of success, otherwise failed.
*/
int32_t Validate_TF_ChromatixParamRelations(
    TF_Chromatix* chromatixStruct,
    NCLIB_CONTEXT_TF* nclibContext,
    uint32_t curPassScalingRatioLog4);

/**
*  @brief   Copy settings from FW struct to RegCmd struct, concentrating on fields set by NcLib
*
*  @param [in]      pFwStructTf               TF FW struct
*  @param [in]      pFwStructRefinement       Refinement FW struct
*  @param [out]     pRegStruct                Output TF register struct
*  @param [in]      passType                  Define which pass is copied: from 0 = full pass to 3 = DC64 pass
*
*  @return void
*/
void NcLibPopulateRegCmdFromFwStruct(
    TfPassParameters*         pFwStructTf,
    RefinementPassParameters* pFwStructRefinement,
    IPETFRegCmd*        pRegStruct,
    uint32_t                  passType);

/**
*  @brief   Clear (set to 0) the register struct for all the passes
*
*  @param [in]      registerStruct      Array of TF register structures
*  @param [in]      numOfPasses         Number of passes to be cleared, typically 4
*
*  @return void
*/
void Clear_TF(IPETFRegCmd* registerStruct, uint32_t numOfPasses);

#ifdef __cplusplus
}
#endif


#endif //__PROCESS_TF_H__

