// NOWHINE ENTIRE FILE 
//-------------------------------------------------------------------------
// Copyright (c) 2017-2018 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//------------------------------------------------------------------------


#ifndef __ANR_REGISTERS_H__
#define __ANR_REGISTERS_H__

#include <stdint.h>

#include "anr10regcmd.h"


// Validates the settings of the registers
// Returns 0 if success
// Else, returns the number of invalid settings
int32_t Validate_ANR(IPEANRRegCmd* reg, uint32_t mE);

// Set the default values of struct
// This function set the internal struct fields and not the packed register
// Therefore, the function PackREG should be called before using the final value of the registers
void SetDefaultVal_ANR(IPEANRRegCmd* reg, uint32_t mE);


#endif //__ANR_REGISTERS_H__

