#ifndef __CAMERAOSSERVICES_H_
#define __CAMERAOSSERVICES_H_

/**
 * @file CameraOSServices.h
 *
 * @brief This file contains the declarations needed for abstracting the host
 *   operating system.
 *
 * Copyright (c) 2009-2020 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 */

/* ===========================================================================
**                      INCLUDE FILES
** ======================================================================== */
#include <stdarg.h>
#include "CameraTypes.h"
#include "CameraResult.h"

#include "ais_log.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/* ===========================================================================
**                      DATA DECLARATIONS
** ======================================================================== */

/* ---------------------------------------------------------------------------
** Constant / Define Declarations
** ------------------------------------------------------------------------ */
#if (defined (__GNUC__) && !defined(__INTEGRITY))
#define CAM_API_EXPORT __attribute__ ((visibility ("default")))
#define CAM_API_LOCAL

#define CAM_API CAM_API_EXPORT
#else
#define CAM_API
#endif


#ifndef CAM_MODULETAG
#define CAM_MODULETAG 0x4E4F4E45 // 'NONE'
#endif

#ifndef EOK
#define EOK 0
#endif

// This defines no timeout mode for CameraWaitOnSignal
#define CAM_SIGNAL_WAIT_NO_TIMEOUT 0xFFFFFFFF

#define CAM_UNUSED(x) (void)(x)

// Specify 8KB as minimum stack size for threads
#define CAM_THREAD_STACK_MIN 8192

#if defined (__INTEGRITY)
// Used to set priority of posix server
// This is required to be the maximum value allowed (231)
#define CAM_POSIXSERVER_PRIORITY 231
#endif

/* ---------------------------------------------------------------------------
** Type Definitions
** ------------------------------------------------------------------------ */
typedef enum
{
    CAMERA_ALLOCATE_ID_UNASSIGNED = 0,

    CAMERA_ALLOCATE_ID_AIS_CTXT,
    CAMERA_ALLOCATE_ID_AIS_USR_CTXT,
    CAMERA_ALLOCATE_ID_AIS_MODULE_CTXT,

    CAMERA_ALLOCATE_ID_DEVICE_MANAGER,

    CAMERA_ALLOCATE_ID_CAMERA_QUEUE_CTXT,
    CAMERA_ALLOCATE_ID_CAMERA_QUEUE_ARRAY,

    CAMERA_ALLOCATE_ID_PLATFORM,

    CAMERA_ALLOCATE_ID_OS_MUTEX,
    CAMERA_ALLOCATE_ID_OS_SIGNAL,
    CAMERA_ALLOCATE_ID_OS_SPIN_LOCK,

    CAMERA_ALLOCATE_ID_SENSOR_DEVICE,
    CAMERA_ALLOCATE_ID_SENSOR_DRIVER_CTXT,
    CAMERA_ALLOCATE_ID_SENSOR_PLATFORM_CTXT,

    CAMERA_ALLOCATE_ID_VFE_DEVICE,
    CAMERA_ALLOCATE_ID_VFE_DRIVER_CTXT,

    CAMERA_ALLOCATE_ID_ISPIF_DEVICE,
    CAMERA_ALLOCATE_ID_ISPIF_DRIVER_CTXT,

    CAMERA_ALLOCATE_ID_CSI_DEVICE,
    CAMERA_ALLOCATE_ID_CSI_DRIVER_CTXT,

    CAMERA_ALLOCATE_ID_CCI_DRIVER_CTXT,

    CAMERA_ALLOCATE_ID_ICP_DEVICE,

    CAMERA_ALLOCATE_ID_ENGINE_EVENT,
    CAMERA_ALLOCATE_ID_ISP_EVENT,

    CAMERA_ALLOCATE_ID_MAX
} CameraAllocateID;

typedef enum
{
    CAMERA_THREAD_PRIO_DEFAULT = 0,
    CAMERA_THREAD_PRIO_NORMAL,
    CAMERA_THREAD_PRIO_BACKEND,
    CAMERA_THREAD_PRIO_HIGH_REALTIME,
    CAMERA_THREAD_PRIO_IST,
    CAMERA_THREAD_PRIO_MAX
} CameraThreadPriorityType;

/* spin lock abstraction */
typedef void* CameraSpinLock;

/* mutex abstraction */
typedef void* CameraMutex;

/// signal abstraction
typedef void* CameraSignal;

/// thread abstraction
typedef void* CameraThread;

/// timer abstraction
typedef void* CameraTimer;

/// Callback function type
typedef void (*CameraOSServicesTimerCBType) (CameraResult cbResult);



/* ===========================================================================
**                      MACROS
** ======================================================================== */



/* ===========================================================================
**                      FUNCTION DECLARATIONS
** ======================================================================== */

/**
 * Initialize dynamic objects in the OS services. Should be called
 * during camera initialization.
 *
 * @param[in] pParam1 Custom param to be passed, passing NULL is valid.
 *
 * @return CAMERA_SUCCESS - if successful
 */
CameraResult CameraOSServicesInitialize(void* pParam1);

/**
 * Uninitialize dynamic objects in the OS services. Should be called
 * during camera uninitialization.
 *
 * @return CAMERA_SUCCESS - if successful
 */
CameraResult CameraOSServicesUninitialize(void);



/**
 * This function returns the time in nanoseconds since phone boot.
 *
 * @param[out] currentTime The current time in nanoseconds since
 *                         phone boot.
 *
 * @return TRUE - if successful
 *         FALSE - if failed
 */
CAM_API boolean CameraGetTime(uint64* pnCurrentTime);

/**
* This function returns the system time in nanosecond intervals
* elapsed since January 1, 1970
*
* @param[out] currentTime nanosecond intervals elapsed since January 1, 1970
*                         phone boot.
*/
void CameraGetSystemTime(uint64* pnCurrentTime);

/**
 * This function causes a debug break, halting execution.
 */
void CameraDebugBreak(void);

/**
 * This function waits without relinquishing control of the processor (busy
 * wait) for the specified number of nanoseconds.
 *
 * @param[in] nNanosecondsToWait The number of nanoseconds to wait.
 */
void CameraBusyWait(uint32 nNanosecondsToWait);

/**
 * This function suspends the execution of the current thread for the
 * specified interval.
 *
 * @param[in] nMillisecondsToSleep The number of milliseconds to suspend
 *                                  the current thread.
 */
CAM_API void CameraSleep(uint32 nMillisecondsToSleep);

/**
 * This function is used to wait for the specified number of microseconds.
 *
 * @param[in] nMicroSec The number of microseconds to wait.
 */
CAM_API void CameraMicroSleep(uint32 nMicroSec);

/**
 * This function creates a spinlock and returns it to the caller.
 *
 * @param[out] pSpinLock This is populated with a generic spinlock object.
 *
 * @return CAMERA_SUCCESS - if successful
 */
CameraResult CameraCreateSpinLock(CameraSpinLock* pSpinLock);

/**
 * This function locks the spinlock passed in, blocking if the spinlock is already
 * locked.
 *
 * @param[in] spinLock This is the generic spinlock object to lock.
 */

void CameraAcquireSpinLock(CameraSpinLock spinLock);

/**
 * This function unlocks the spinlock passed in, allowing other threads waiting
 * on the spinlock to proceed.
 *
 * @param[in] spinLock This is the generic spinlock object to release.
 */
void CameraReleaseSpinLock(CameraSpinLock spinLock);

/**
 * This function destroys the spinlock passed in.
 *
 * @param[in] pSpinLock This is the generic spinlock object to destroy.
 */
void CameraDestroySpinLock(CameraSpinLock* pSpinLock);


/**
 * This function creates a mutex and returns it to the caller.
 *
 * @param[out] pMutex This is populated with a generic mutex object.
 *
 * @return CAMERA_SUCCESS - if successful
 */
CAM_API CameraResult CameraCreateMutex(CameraMutex* pMutex);

/**
 * This function locks the mutex passed in, blocking if the mutex is already
 * locked.
 *
 * @param[in] Mutex This is the generic mutex object to lock.
 */
CAM_API void CameraLockMutex(CameraMutex Mutex);

/**
 * This function unlocks the mutex passed in, allowing other threads waiting
 * on the mutex to proceed.
 *
 * @param[in] Mutex This is the generic mutex object to unlock.
 */
CAM_API void CameraUnlockMutex(CameraMutex Mutex);

/**
 * This function destroys the mutex passed in.
 *
 * @param[in] Mutex This is the generic mutex object to destroy.
 */
CAM_API void CameraDestroyMutex(CameraMutex Mutex);

/**
 * This function creates a signal and returns it to the caller.
 *
 * @param[out] pSignal This is populated with a generic signal object.
 *
 * @return CAMERA_SUCCESS - if successful
 */
CAM_API CameraResult CameraCreateSignal(CameraSignal* ppSignal);

/**
 * This function resets the signal to its unset (unsignaled) state.
 *
 * @param[in] pSignal This is the generic signal object to reset.
 * @return CAMERA_SUCCESS - if successful
 *         CAMERA_EFAILED - if failed
 */
CAM_API CameraResult CameraResetSignal(CameraSignal pSignal);

/**
 * This function waits on the signal until the signal is set (signaled).
 * If the signal is not set by calling CameraSetSignal, the timer will expire
 * and set the signal.  A tie goes to the the non-timeout signal.
 *
 * @param[in] pSignal This is the generic signal object to wait on.
 * @param[in] nTimeoutMilliseconds This is the number of milliseconds to wait
 *                                 on the signal before timing out.
 * @return CAMERA_SUCCESS - if successful
 *         CAMERA_EEXPIRED - if timeout occured
 *         CAMERA_EFAILED - if failed
 */
CAM_API CameraResult CameraWaitOnSignal(CameraSignal pSignal,
            uint32 nTimeoutMilliseconds);

/**
 * This function sets (signals) the signal.
 *
 * @param[in] pSignal This is the generic signal object to set.
 * @return CAMERA_SUCCESS - if successful
 *         CAMERA_EFAILED - if failed
 */
CAM_API CameraResult CameraSetSignal(CameraSignal pSignal);

/**
 * This function destroys the signal.
 *
 * @param[in] pSignal This is the generic signal object to destroy.
 */
CAM_API void CameraDestroySignal(CameraSignal pSignal);

/**
 * This function performs an atomic increment (increase by 1) operation.
 *
 * @param[inout] pnAddend This is the number to add 1 to
 *
 * @return The addend plus 1.
 */
uint32 CameraAtomicIncrement(uint32* pnAddend);

/**
 * This function performs an atomic decrement (decrease by 1) operation.
 *
 * @param[inout] pnAddend This is the number to subract 1 from
 *
 * @return The addend minus 1.
 */
uint32 CameraAtomicDecrement(uint32* pnAddend);

#ifdef CAMERA_UNITTEST
#define CameraAllocate(_id_,_size_) CameraAllocate_debug(_id_, _size_, 0, __FUNCTION__, __LINE__)
#define CameraAllocateAlign(_id_,_size_, _align_) CameraAllocate_debug(_id_, _size_, _align_, __FUNCTION__, __LINE__)
#define CameraFree(_id_, _ptr_) CameraFree_debug(_id_, _ptr_, __FUNCTION__, __LINE__)

/**
 * This function allocates a buffer of the specified size on the heap.
 *
 * @param[in] allocateID This is the unique identifier for the allocation.
 * @param[in] numBytes This is the number of bytes to be allocated.
 *
 * @return A pointer to the allocated buffer if successful; NULL otherwise.
 */
void* CameraAllocate_debug(CameraAllocateID allocateID, uint32 numBytes, uint32 align, const char* function, unsigned int line);


/**
 * This function frees the specified buffer on the heap. Buffers will be
 * checked for NULL before freeing.
 *
 * @param[in] allocateID This is the unique identifier for the allocation.
 * @param[in] pBuffer This is the pointer to the buffer to be freed. A NULL
 *                    check is performed.
 */
void CameraFree_debug(CameraAllocateID allocateID, void* pBuffer, const char* function, unsigned int line);
#else
/**
 * This function allocates a buffer of the specified size on the heap.
 *
 * @param[in] allocateID This is the unique identifier for the allocation.
 * @param[in] numBytes This is the number of bytes to be allocated.
 *
 * @return A pointer to the allocated buffer if successful; NULL otherwise.
 */
CAM_API void* CameraAllocate(CameraAllocateID allocateID, uint32 numBytes);


/**
 * This function frees the specified buffer on the heap. Buffers will be
 * checked for NULL before freeing.
 *
 * @param[in] allocateID This is the unique identifier for the allocation.
 * @param[in] pBuffer This is the pointer to the buffer to be freed. A NULL
 *                    check is performed.
 */
CAM_API void CameraFree(CameraAllocateID allocateID, void* pBuffer);
#endif
/**
 * This function calls the callback function once timer is expired.
 *
 * @param[in] pfnCallback callback function
 * @param[in] nTimeDelay time delay
 *
 * @return CAMERA_SUCCESS - if successful
 *         CAMERA_EMEMPTR - if callback is NULL
 *         CAMERA_EFAILED - if failed
 *         CAMERA_ENOMORE - if timer is not available
 */
CameraResult CameraNotifyOnTimer(CameraOSServicesTimerCBType pfnCallback, uint32 nTimeDelay);

/**
 * This function is used to deregister the callback function
 * If timer is running and callback function is deregister then client callback
 * function will not called
 *
 * @param[in] pfnCallback callback function
 *
 * @return CAMERA_SUCCESS - if successful
 *         CAMERA_EFAILED - if failed
 */
CameraResult CameraCancelTimer(CameraOSServicesTimerCBType pfnCallback);

/**
 * This function creates a kernel thread.
 */
CAM_API CameraResult CameraCreateThread(CameraThreadPriorityType nPriority,
    int nSuspend,
    int(*pfnStart)(void*),
    void* pvStartArg,
    unsigned int nStackSize,
    char* pstrName,
    CameraThread* ppHandle);

/**
 * This function releases a thread.
 */
CAM_API CameraResult CameraReleaseThread(CameraThread pHandle);

/**
 * This function detaches a thread.
 */
CAM_API CameraResult CameraDetachThread(CameraThread pHandle);

/**
 * This function terminates a thread
 */
CAM_API CameraResult CameraExitThread(CameraThread pHandle, int nExitCode);

/**
 * This function joins a thread
 */
CAM_API CameraResult CameraJoinThread(CameraThread pHandle, void* pExitCode);

/**
 * This function sets priority to a thread
 */
CAM_API CameraResult CameraSetThreadPriority(CameraThread pHandle, CameraThreadPriorityType nPriority);

/**
 * This function returns priority defined by CameraOSServices
 */
CAM_API unsigned int CameraTranslateThreadPriority(CameraThreadPriorityType nPriority);

/**
 * This structure contains opaque fields for managing OS-specific file operations.
 */
typedef struct _CameraOSServicesFileHandle
{
    void *pFileHandle; /* opaque field to be used by OS-specific implementation */
    int   nFileHandle; /* opaque field to be used by OS-specific implementation */

    unsigned long fileSize; /* opaque field to be used by OS-specific implementation */

} CameraOSFileHandle_t;

/**
 * This function builds a system-specific absolute file name from a base file name.
 *
 * @return Whether or not the output string was clipped
 */
boolean CameraBuildAbsPathName(char *pOutputBuffer, uint32 bufferSize, const char *pBaseFileName);

CameraResult CameraOpenFile(CameraOSFileHandle_t *handle, const char *pFileName, const char *mode);

CameraResult CameraCloseFile(CameraOSFileHandle_t *handle);

CameraResult CameraReadFileSegment(CameraOSFileHandle_t *handle,
                                   unsigned char        *pBuffer,
                                   unsigned int         *pBufferSize);

/**
 * This function read the file in from IO.
 *
 * @param[in] pFileName Pointer to the file name
 * @param[in/out] ppBuff Pointer to buffer to read data into
 * @param[in] nMaxSize  max size of buffer
 *
 * @return CameraResult
 */
CameraResult CameraReadFile(char * pFileName, void ** ppBuff, int nMaxSize);


/**
 * This function write to out to a file.
 *
 * @param[in] pFileName Pointer to the file name
 * @param[in] pBuff     Pointer to data written
 * @param[in] nMaxSize  Size to write out
 */
CameraResult CameraWriteFile(char * pFileName, void * pBuff, int nMaxSize);

CAM_API CameraResult CameraCreateTimer(int nTimeOut, int nPeriodic, void (*pfnTimerHandler)(void* ), void *pvUserArg, CameraTimer *ppTimer);

CAM_API CameraResult CameraUpdateTimer(CameraTimer pTimer, int nTimeOut);

CAM_API CameraResult CameraStopTimer(CameraTimer pTimer);

CAM_API CameraResult CameraReleaseTimer(CameraTimer pTimer);

#ifdef __cplusplus
} // extern "C"
#endif  // __cplusplus

#endif // __CAMERAOSSERVICES_H_
