#ifndef __CAMERARESULT_H_
#define __CAMERARESULT_H_

/**
 * @file CameraResult.h
 *
 * @brief This header file defines error codes for the camera subsystem
 *
 * Copyright (c) 2009-2012, 2017 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 */

/* ===========================================================================
                        INCLUDE FILES FOR MODULE
=========================================================================== */
#include "CameraTypes.h"

/* ===========================================================================
                        DATA DECLARATIONS
=========================================================================== */
/* ---------------------------------------------------------------------------
** Constant / Define Declarations
** ------------------------------------------------------------------------ */
#define CAMERA_SUCCESS              0  ///< No error
#define CAMERA_EFAILED              1  ///< General failure
#define CAMERA_ENOMEMORY            2  ///< Insufficient RAM
#define CAMERA_ECLASSNOTSUPPORT     3  ///< Specified class unsupported
#define CAMERA_EVERSIONNOTSUPPORT   4  ///< Version not supported
#define CAMERA_EALREADYLOADED       5  ///< Object already loaded
#define CAMERA_EUNABLETOLOAD        6  ///< Unable to load object/applet
#define CAMERA_EUNABLETOUNLOAD      7  ///< Unable to unload object/applet
#define CAMERA_EALARMPENDING        8  ///< Alarm is pending
#define CAMERA_EINVALIDTIME         9  ///< Invalid time
#define CAMERA_EBADCLASS            10 ///< NULL class object
#define CAMERA_EBADMETRIC           11 ///< Invalid metric specified
#define CAMERA_EEXPIRED             12 ///< App/Component Expired
#define CAMERA_EBADSTATE            13 ///< Invalid state
#define CAMERA_EBADPARM             14 ///< Invalid parameter
#define CAMERA_ESCHEMENOTSUPPORTED  15 ///< Invalid URL scheme
#define CAMERA_EBADITEM             16 ///< Invalid item
#define CAMERA_EINVALIDFORMAT       17 ///< Invalid format
#define CAMERA_EINCOMPLETEITEM      18 ///< Incomplete item
#define CAMERA_ENOPERSISTMEMORY     19 ///< Insufficient flash
#define CAMERA_EUNSUPPORTED         20 ///< API is not supported
#define CAMERA_EPRIVLEVEL           21 ///< Privileges are insufficient for this operation
#define CAMERA_ERESOURCENOTFOUND    22 ///< Unable to find specified resource
#define CAMERA_EREENTERED           23 ///< Non re-entrant API re-entered
#define CAMERA_EBADTASK             24 ///< API called in wrong task context
#define CAMERA_EALLOCATED           25 ///< App/Module left memory allocated when released
#define CAMERA_EALREADY             26 ///< Operation is already in progress
#define CAMERA_EADSAUTHBAD          27 ///< ADS mutual authorization failed
#define CAMERA_ENEEDSERVICEPROG     28 ///< Need service programming
#define CAMERA_EMEMPTR              29 ///< Bad memory pointer
#define CAMERA_EHEAP                30 ///< Heap corruption
#define CAMERA_EIDLE                31 ///< Context (system, interface, etc.) is idle
#define CAMERA_EITEMBUSY            32 ///< Context (system, interface, etc.) is busy
#define CAMERA_EBADSID              33 ///< Invalid subscriber ID
#define CAMERA_ENOTYPE              34 ///< No type detected/found
#define CAMERA_ENEEDMORE            35 ///< Need more data/info
#define CAMERA_EADSCAPS             36 ///< ADS Capabilities do not match those required for phone
#define CAMERA_EBADSHUTDOWN         37 ///< App failed to close properly
#define CAMERA_EBUFFERTOOSMALL      38 ///< Destination buffer given is too small
#define CAMERA_ENOSUCH              39 ///< No such name/port/socket/service exists or valid
#define CAMERA_EACKPENDING          40 ///< ACK pending on application
#define CAMERA_ENOTOWNER            41 ///< Not an owner authorized to perform the operation
#define CAMERA_EINVALIDITEM         42 ///< Current item is invalid
#define CAMERA_ENOTALLOWED          43 ///< Not allowed to perform the operation
#define CAMERA_EBADHANDLE           44 ///< Invalid handle
#define CAMERA_EOUTOFHANDLES        45 ///< Out of handles
#define CAMERA_EINTERRUPTED         46 ///< Waitable call is interrupted
#define CAMERA_ENOMORE              47 ///< No more items available -- reached end
#define CAMERA_ECPUEXCEPTION        48 ///< A CPU exception occurred
#define CAMERA_EREADONLY            49 ///< Cannot change read-only object or parameter
#define CAMERA_EWOULDBLOCK          50 ///< Operation would block if not non-blocking; wait and try again
#define CAMERA_EOUTOFBOUND          51 ///< Out of bound

/* Description:
* _fcn_ will always be called. _err_ will be updated by
* return value of _fcn_ only if _err_ is CAMERA_SUCCESS.
* So, as soon as an error occurs in a sequence of use, the
* first error won't be overwritten.
*
* Param:
* _fcn_ - the function which will always be called;
*         return value of the function must be CameraResult
* _err_ - running CameraResult.
* _tmp_ - a scratch CameraResult.
*
*/
#define CAMERA_LOG_FIRST_ERROR(_fcn_, _err_, _tmp_) \
    (_tmp_) = (_fcn_); \
    if ((CAMERA_SUCCESS == (_err_)) && \
        (CAMERA_SUCCESS != (_tmp_))) \
    { \
        (_err_) = (_tmp_); \
    } \

/* ---------------------------------------------------------------------------
** Type Declarations
** ------------------------------------------------------------------------ */
/// Camera error code type
typedef int CameraResult;

/* ===========================================================================
                        MACRO DEFINITIONS
=========================================================================== */
#ifdef CAMERA_SUCCEEDED
#undef CAMERA_SUCCEEDED
#endif
#ifdef CAMERA_FAILED
#undef CAMERA_FAILED
#endif

#ifdef __cplusplus
namespace Camera
{

namespace Core
{

/// Check if CameraResult value is a success value.
/// @param[in] result The CameraResult value.
/// @return TRUE if success value.
static inline bool CAMERA_SUCCEEDED (CameraResult result)
{
    return (CAMERA_SUCCESS == result);
}

/// Check if CameraResult value is not a success value.
/// @param[in] result The CameraResult value.
/// @return TRUE if not a success value.
static inline bool CAMERA_FAILED (CameraResult result)
{
    return (CAMERA_SUCCESS != result);
}

}

}
#else

/// Check if CameraResult value is a success value.
/// @param[in] result The CameraResult value.
/// @return TRUE if success value.
#define CAMERA_SUCCEEDED(result) (CAMERA_SUCCESS == (result))

/// Check if CameraResult value is not a success value.
/// @param[in] result The CameraResult value.
/// @return TRUE if not a success value.
#define CAMERA_FAILED(result) (CAMERA_SUCCESS != (result))

#endif /* __cplusplus */

#endif // __CAMERARESULT_H_
