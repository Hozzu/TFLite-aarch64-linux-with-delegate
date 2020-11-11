/****************************************************************************
* Copyright (c) 2017-2019 Qualcomm Technologies, Inc.                            *
* All Rights Reserved.                                                      *
* Confidential and Proprietary - Qualcomm Technologies, Inc.                *
****************************************************************************/

#ifndef __AUTOLTM2_H__
#define __AUTOLTM2_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  float max_gain_limit;
  float gsn_luma_target;
  float gsn_sigma;
  float k2_8bit_pre_weight;
  int flat_hist_en;
} autoltm2_tuning_t;

/** shdr_autoltm2_unity_gain
 *    @bhist: shdr library handle
 *    @bin_size: configuration params for shdr
 *    @auto_ltm: auto ltm tuning
 *    @k2_8bit: k2 8bit
 *
 * Calculates k2
 *
 * return: 0 on success
 **/
int shdr_autoltm2_unity_gain(unsigned short *bhist, int bhist_size,
                             autoltm2_tuning_t *auto_ltm, float *k2_8bit);

#ifdef __cplusplus
}
#endif

#endif /* __AUTOLTM2_H__ */
