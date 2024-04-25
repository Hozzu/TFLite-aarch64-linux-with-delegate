// NOWHINE ENTIRE FILE
//-------------------------------------------------------------------------
// Copyright (c) 2017-2018 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//------------------------------------------------------------------------

#ifndef __PROCESS_ICA_H__
#define __PROCESS_ICA_H__

#include "ICA_Chromatix.h"
#include "ICA_Registers_v30.h"
#include "NcLibContext.h"
#include "NcLibWarpCommonDef.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
*  @brief   Calculate ICA registers and FW struct which are set directly by Chromatix.
*
*  @param [in]      chromatixStruct             pointer to the pass Chromatix struct
*  @param [in]      icaIsGridEnabledByFlow      indication if Grid is set by Chromatix or SW.
*                                               if it is set to 0, it is taken from Chromatix
*                                               else it is set by SW (ICA_ProcessNonChromatixParams).
*  @param [out]     regStruct                   pointer to the pass register struct
*  @param [out]     fwStruct                    FW struct that is filled by the function.
*
*  @return NC_LIB_SUCCESS in case of success, otherwise failed.
*/
int32_t ICA_ProcessNcLib(
    const ICA_Chromatix* chromatixStruct,
    uint8_t icaIsGridEnabledByFlow,
    ICA_REG_v30* regStruct,
    IcaParameters* fwStruct);

/**
*  @brief   Calculate ICA non Chromatix registers and FW structs .
*
*  @param [in]      inGridFlow                  pointer to grid.
*                                               if chip is Napali:
*                                                   inGridFlow has to be grid of exact size of ICA v10 : 
*                                                   ICA_GRID_TRANSFORM_WIDTH_V10 = 33, ICA_V10_GRID_TRANSFORM_HEIGHT = 25
*                                               if chip is Hana:
*                                                   inGridFlow has to be grid of exact size of ICA v20 :
*                                                   ICA_V20_GRID_TRANSFORM_WIDTH = 35, ICA_V20_GRID_TRANSFORM_HEIGHT = 27
*                                               if chip is Kona:
*                                                   inGridFlow has to be grid of exact size of ICA v30, which is one of :
*                                                   ICA_V30_GRID_TRANSFORM_LORES_WIDTH = 35, ICA_V30_GRID_TRANSFORM_LORES_HEIGHT = 27
*                                                   ICA_V30_GRID_TRANSFORM_HIRES_WIDTH = 67, ICA_V30_GRID_TRANSFORM_HIRES_HEIGHT = 51
*  @param [in]      persp                       pointer to perspective transform matrices.
*                                               There are up to be max 9 matrices.
*  @param [in]      icaIsGridEnabledByFlow      indication if Grid is set by Chromatix or SW.
*                                               if it is set to 0, it is taken from Chromatix (ICA_ProcessNcLib)
*                                               else it is set by SW (this function).
*  @param [in]      icaIsRefinementEnabled      indication if Refinement is enabled.
*  @param [in]      icaVersion                  ICA HW version: 10 for Napali, 20 for Hana, 20 or 30 for Kona.
*  @param [out]     regStruct                   pointer to the pass register struct
*  @param [out]     fwStruct                    FW struct that is filled by the function.
*
*  @return NC_LIB_SUCCESS in case of success, otherwise failed.
*/
int32_t ICA_ProcessNonChromatixParams(
    const NcLibWarpGrid* inGridFlow,
    const NcLibWarpMatrices* persp,
    uint8_t icaIsGridEnabledByFlow,
    uint32_t icaIsRefinementEnabled,
    uint32_t icaVersion,
    ICA_REG_v30* regStruct,
    IcaParameters* fwStruct);

/**
*  @brief   Gets the inputs of ICA_ProcessNonChromatixParams and return true or false if they are valid for ICA
*
*  @param [in]      inGridFlow                  pointer to grid.
*                                               if chip is Napali:
*                                                   inGridFlow has to be grid of exact size of ICA v10 :
*                                                   ICA_GRID_TRANSFORM_WIDTH_V10 = 33, ICA_V10_GRID_TRANSFORM_HEIGHT = 25
*                                               if chip is Hana:
*                                                   inGridFlow has to be grid of exact size of ICA v20 :
*                                                   ICA_V20_GRID_TRANSFORM_WIDTH = 35, ICA_V20_GRID_TRANSFORM_HEIGHT = 27
*                                               if chip is Kona:
*                                                   inGridFlow has to be grid of exact size of ICA v30, which is one of :
*                                                   ICA_V30_GRID_TRANSFORM_LORES_WIDTH = 35, ICA_V30_GRID_TRANSFORM_LORES_HEIGHT = 27
*                                                   ICA_V30_GRID_TRANSFORM_HIRES_WIDTH = 67, ICA_V30_GRID_TRANSFORM_HIRES_HEIGHT = 51
*  @param [in]      persp                       pointer to perspective transform matrices.
*                                               There are up to be max 9 matrices.
*  @param [in]      icaIsGridEnabledByFlow      indication if Grid is set by Chromatix or SW.
*                                               if it is set to 0, it is taken from Chromatix (ICA_ProcessNcLib)
*                                               else it is set by SW (this function).
*  @param [in]      icaIsRefinementEnabled      indication if Refinement is enabled.
*  @param [in]      icaVersion                  ICA HW version: 10 for Napali, 20 for Hana, 20 or 30 for Kona.
*
*  @return NC_LIB_SUCCESS in case of success, otherwise failed.
*/
int32_t ValidateIcaNonChromatixParams(
    const NcLibWarpGrid* inGridFlow,
    const NcLibWarpMatrices* persp,
    uint8_t  icaIsGridEnabledByFlow,
    uint32_t icaIsRefinementEnabled,
    uint32_t icaVersion);


/**
*  @brief   Set default values for ICA FW struct
*
*  @param [in]      fwStruct               The FW struct that is set.
*
*  @return void
*/
void SetDefaultsForIcaStruct(IcaParameters* fwStruct);

/**
*  @brief   Get ICA version typical for current chip
*
*  @return 10 for Napali, 20 for Hana, 30 for Kona.
*/
uint32_t NcLibGetTypicalIcaVersion();

#ifdef __cplusplus
}
#endif


#endif //__PROCESS_ICA_H__

