// --------------------------------------------------------------------------
// |              _    _ _______     .----.      _____         _____        |
// |         /\  | |  | |__   __|  .  ____ .    / ____|  /\   |  __ \       |
// |        /  \ | |  | |  | |    .  / __ \ .  | (___   /  \  | |__) |      |
// |       / /\ \| |  | |  | |   .  / / / / v   \___ \ / /\ \ |  _  /       |
// |      / /__\ \ |__| |  | |   . / /_/ /  .   ____) / /__\ \| | \ \       |
// |     /________\____/   |_|   ^ \____/  .   |_____/________\_|  \_\      |
// |                              . _ _  .                                  |
// --------------------------------------------------------------------------
//
// All Rights Reserved.
// Any use of this source code is subject to a license agreement with the
// AUTOSAR development cooperation.
// More information is available at www.autosar.org.
//
// Disclaimer
//
// This work (specification and/or software implementation) and the material
// contained in it, as released by AUTOSAR, is for the purpose of information
// only. AUTOSAR and the companies that have contributed to it shall not be
// liable for any use of the work.
//
// The material contained in this work is protected by copyright and other
// types of intellectual property rights. The commercial exploitation of the
// material contained in this work requires a license to such intellectual
// property rights.
//
// This work may be utilized or reproduced without any modification, in any
// form or by any means, for informational purposes only. For any other
// purpose, no part of the work may be utilized or reproduced, in any form
// or by any means, without permission in writing from the publisher.
//
// The work has been developed for automotive applications only. It has
// neither been developed, nor tested for non-automotive applications.
//
// The word AUTOSAR and the AUTOSAR logo are registered trademarks.
// --------------------------------------------------------------------------

#ifndef __INCsomeipSerialh
#define __INCsomeipSerialh

#include <stdlib.h>

#include "someipTypes.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
 * someipSerial is used to serialize data into the payload of the SOMEIP
 * message to be sent.
 */

/* typedefs */

typedef struct someipSerial SOMEIP_SERIAL;

struct someipSerial
{
    uint32_t size; /* data buffer size */
    uint32_t pos; /* data buffer position during serialization */
    uint8_t* pData;

    void (*pReset)(SOMEIP_SERIAL*); /* reset handler */

    /* serializer handlers */

    BOOL (*pSerBool)(SOMEIP_SERIAL*, const BOOL*, uint32_t);
    BOOL (*pSer8)(SOMEIP_SERIAL*, const uint8_t*, uint32_t);
    BOOL (*pSer16)(SOMEIP_SERIAL*, const uint16_t*, uint32_t);
    BOOL (*pSer32)(SOMEIP_SERIAL*, const uint32_t*, uint32_t, BOOL);
    BOOL (*pSerStr)(SOMEIP_SERIAL*, uint8_t*, uint32_t);

    /* deserializer handlers */

    BOOL (*pDesBool)(SOMEIP_SERIAL*, BOOL*, uint32_t);
    BOOL (*pDes8)(SOMEIP_SERIAL*, uint8_t*, uint32_t);
    BOOL (*pDes16)(SOMEIP_SERIAL*, uint16_t*, uint32_t);
    BOOL (*pDes32)(SOMEIP_SERIAL*, uint32_t*, uint32_t, BOOL);
    BOOL (*pDesStr)(SOMEIP_SERIAL*, uint8_t*, uint32_t);
};

/* function declarations */

IMPORT SOMEIP_SERIAL* someipSerialNew(uint8_t* pData, uint32_t size);
IMPORT void someipSerialDelete(SOMEIP_SERIAL* pSer);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __INCsomeipSerialh */
