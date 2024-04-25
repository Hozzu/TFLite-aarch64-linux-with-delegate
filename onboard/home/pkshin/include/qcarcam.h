#ifndef _QCARCAM_H_
#define _QCARCAM_H_

/* ===========================================================================
 * Copyright (c) 2016-2020 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 * @file qcarcam.h
 * @brief QCarCam API - QTI Automotive Imaging System Proprietary API
 *
=========================================================================== */

#include "qcarcam_types.h"

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
//                   DEFINITIONS AND DECLARATIONS
///////////////////////////////////////////////////////////////////////////////
#define QCARCAM_VERSION_MAJOR              4
#define QCARCAM_VERSION_MINOR              7
#define QCARCAM_VERSION_MINOR_COMPATIBLE   7
#define QCARCAM_VERSION                    ((QCARCAM_VERSION_MAJOR << 8) | QCARCAM_VERSION_MINOR)
#define QCARCAM_VERSION_MINIMUM_COMPATIBLE ((QCARCAM_VERSION_MAJOR << 8) | QCARCAM_VERSION_MINOR_COMPATIBLE)

///////////////////////////////////////////////////////////////////////////////
// Constant and Macros
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// API Definition
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// qcarcam_initialize
///
/// @brief Initialize QCarCam. Must be first call to library.
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t qcarcam_initialize(qcarcam_init_t* p_init_params);

///////////////////////////////////////////////////////////////////////////////
/// qcarcam_uninitialize
///
/// @brief De-initialize QCarCam. Last call to library.
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t qcarcam_uninitialize(void);

///////////////////////////////////////////////////////////////////////////////
/// qcarcam_query_inputs
///
/// @brief Queries available inputs. To get the number of available inputs to query, call with p_inputs set to NULL.
///
/// @param p_inputs   Pointer to array inputs. If NULL, then ret_size returns number of available inputs to query
/// @param size       Number of elements in array
/// @param ret_size   If p_inputs is set, number of elements in array that were filled
///                   If p_inputs is NULL, number of available inputs to query
///
/// @return QCARCAM_RET_OK if successful.
///         QCARCAM_RET_BUSY if engine has not finished detection of all available inputs. Will only return available
///                          inputs up to this point in time.
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t qcarcam_query_inputs(qcarcam_input_t* p_inputs, unsigned int size, unsigned int* ret_size);

///////////////////////////////////////////////////////////////////////////////
/// qcarcam_open
///
/// @brief Opens handle to input
///
/// @param desc   Unique identifier of input to be opened
///
/// @return NOT NULL if successful; NULL on failure
///////////////////////////////////////////////////////////////////////////////
qcarcam_hndl_t qcarcam_open(qcarcam_input_desc_t desc);

///////////////////////////////////////////////////////////////////////////////
/// qcarcam_close
///
/// @brief Closes handle to input
///
/// @param hndl   Handle of input that was opened
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t qcarcam_close(qcarcam_hndl_t hndl);

///////////////////////////////////////////////////////////////////////////////
/// qcarcam_g_param
///
/// @brief Get parameter value
///
/// @param hndl     Handle of input
/// @param param    Parameter to get
/// @param p_value  Pointer to structure of value that will be retrieved
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t qcarcam_g_param(qcarcam_hndl_t hndl, qcarcam_param_t param, qcarcam_param_value_t* p_value);

///////////////////////////////////////////////////////////////////////////////
/// qcarcam_s_param
///
/// @brief Set parameter
///
/// @param hndl     Handle of input
/// @param param    Parameter to set
/// @param p_value  Pointer to structure of value that will be set
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t qcarcam_s_param(qcarcam_hndl_t hndl, qcarcam_param_t param, const qcarcam_param_value_t* p_value);

///////////////////////////////////////////////////////////////////////////////
/// qcarcam_s_buffers
///
/// @brief Set buffers
///
/// @param hndl       Handle of input
/// @param p_buffers  Pointer to set buffers structure
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t qcarcam_s_buffers(qcarcam_hndl_t hndl, qcarcam_buffers_t* p_buffers);

///////////////////////////////////////////////////////////////////////////////
/// qcarcam_s_input_buffers
///
/// @brief Set buffers for injection
///
/// @param hndl       Handle of input
/// @param p_buffers  Pointer to set buffers structure
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t qcarcam_s_input_buffers(qcarcam_hndl_t hndl, qcarcam_buffers_t* p_buffers);

///////////////////////////////////////////////////////////////////////////////
/// qcarcam_start
///
/// @brief Start input
///
/// @param hndl       Handle of input
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t qcarcam_start(qcarcam_hndl_t hndl);

///////////////////////////////////////////////////////////////////////////////
/// qcarcam_stop
///
/// @brief Stop input that was started
///
/// @param hndl       Handle of input
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t qcarcam_stop(qcarcam_hndl_t hndl);

///////////////////////////////////////////////////////////////////////////////
/// qcarcam_pause
///
/// @brief Pause input that was started. Does not relinquish resource
///
/// @param hndl       Handle of input
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t qcarcam_pause(qcarcam_hndl_t hndl);

///////////////////////////////////////////////////////////////////////////////
/// qcarcam_resume
///
/// @brief Resumes input that was paused
///
/// @param hndl       Handle of input
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t qcarcam_resume(qcarcam_hndl_t hndl);

///////////////////////////////////////////////////////////////////////////////
/// qcarcam_get_frame
///
/// @brief Get available frame
///
/// @param hndl          Handle of input
/// @param p_frame_info  Pointer to frame information that will be filled
/// @param timeout       Max wait time in ns for frame to be available before timeout
/// @param flags         Flags
///
/// @return QCARCAM_RET_OK if successful; QCARCAM_RET_TIMEOUT if timeout
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t qcarcam_get_frame(qcarcam_hndl_t hndl, qcarcam_frame_info_t* p_frame_info,
        unsigned long long int timeout, unsigned int flags);

///////////////////////////////////////////////////////////////////////////////
/// qcarcam_release_frame
///
/// @brief Re-enqueue frame buffers
///
/// @param hndl       Handle of input
/// @param idx        Index into the qcarcam_buffers_t buffers table to reenqueue
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t qcarcam_release_frame(qcarcam_hndl_t hndl, unsigned int idx);

#ifdef __cplusplus
}
#endif

#endif

