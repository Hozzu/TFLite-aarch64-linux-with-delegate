// NOWHINE ENTIRE FILE
//-------------------------------------------------------------------------
// Copyright (c) 2017-2018 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//------------------------------------------------------------------------


#ifndef __TF_REGISTERS_H__
#define __TF_REGISTERS_H__

#include <stdint.h>
#include "tf10regcmd.h"

// Validates the settings of the registers
// Returns 0 if success
// Else, returns the number of invalid settings
int32_t ValidatePacked_TF_REG( IPETFRegCmd* regStruct, int hwVersion );
// Set the default values of struct
// This function set the internal struct fields and not the packed register
// Therefore, the function PackREG should be called before using the final value of the registers
void SetDefaultValPacked_TF_REG( IPETFRegCmd* regStruct, int hwVersion );

#endif //__TF_REGISTERS_H__

