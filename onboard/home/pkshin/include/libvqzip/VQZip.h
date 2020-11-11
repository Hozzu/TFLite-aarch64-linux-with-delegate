/*
 * Copyright (c) 2014-2015 Qualcomm Technologies, Inc.  All Rights Reserved.
 * Qualcomm Technologies Proprietary and Confidential.
 */

#ifndef VQZIP_H_
#define VQZIP_H_

#include "sys/types.h"

#ifdef __LINUX__
#include <stdint.h>
#ifndef uint8_t
typedef uint8_t __u8;
#endif
#ifndef uint16_t
typedef uint16_t __u16;
#endif
#ifndef uint32_t
typedef uint32_t __u32;
#endif
#ifndef int8_t
typedef int8_t __s8;
#endif
#ifndef int16_t
typedef int16_t __s16;
#endif
#ifndef int32_t
typedef int32_t __s32;
#endif
#else
#include <OMX_IVCommon.h>
#endif

#define VQZIP_MAX_STAT_COUNT 16

typedef struct VQZipConfig
{
    uint32_t colorFormat;
    void*    pSEIPayload; // pointer to SEI payload
    uint16_t nWidth;
    uint16_t nHeight;
}VQZipConfig;

typedef struct VQZipStats
{
    uint32_t  nCount;
    uint32_t  stats[VQZIP_MAX_STAT_COUNT];
}VQZipStats;


typedef enum VQZipStatus
{
    VQZipStatusSuccess = 0,
    VQZipStatusFail = 1,
    VQZipStatusMax = 0xFFFFFFFF
}VQZipStatus;

/*!
   @detail  Creates a VQZip Handle.

   @param[in]  none

   @return    Pointer to VQZip instance.

   @note    It is expected that except pOputStream nothing should be NULL.
*/
void* VQZipInit();

/*!
   @detail  Calculates the stats on 'pBuf' buffer for 'hVz' VQZip instance based on
            input VQZip configuration 'pConfig'.

   @param[in]  hVz  - handle to VQZip Instance
   @param[in]  pBuf - pointer to input YUV buffer, on which YUV stats need to be calculated
   @param[in]  pConfig - pointer to VQZipConfig structure, should be valid for first frame
   @param[out] pStats  - pointer to VQZipStats structure

   @return    Pointer to VQZip instance.

   @note    It is expected that except pOputStream nothing should be NULL.
*/
VQZipStatus VQZipComputeStats(void* const hVz, const void * const pBuf, const VQZipConfig *pConfig, VQZipStats *pStats);

/*!
   @detail  Destroys VQZip Handle and clears internal memory.

   @param[in]  hVz  - handle to VQZip Instance

   @return    none

   @note    It is expected that except pOputStream nothing should be NULL.
*/
void VQZipDeInit(void* hVQ);

#endif //VQZIP_H_
