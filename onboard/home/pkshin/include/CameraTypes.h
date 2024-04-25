#ifndef __CAMERATYPES_H_
#define __CAMERATYPES_H_

/**
 * @file CameraTypes.h
 *
 * Copyright (c) 2017-2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#include "AEEStdDef.h"
#include "AEEstd.h"
#include <stdint.h>

#ifndef CAM_ALIGN_SIZE
#define CAM_ALIGN_SIZE(x, y) (((x) + ((y)-1)) & ~((y)-1))
#endif

#if defined(__INTEGRITY)

#include <string.h>

#define STD_ZEROAT(p)  std_memset((p), 0, sizeof(*p))

#define CLOCK_MONOTONIC CLOCK_REALTIME

typedef unsigned int useconds_t;

#endif

#endif /* __CAMERATYPES_H_ */
