/* ===========================================================================
 * Copyright (c) 2017-2020 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
=========================================================================== */

#ifndef _QCARCAM_CLINENT_H
#define _QCARCAM_CLINENT_H

#include "qcarcam.h"
#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
/// @brief Event callback function definition
///
/// @param input_id    Input ID
/// @param buf_ptr     frame buffer ptr
/// @param buf_len     frame buffer length
///////////////////////////////////////////////////////////////////////////////
typedef void (*qcarcam_client_event_cb_t) (qcarcam_input_desc_t input_id, unsigned char* buf_ptr, size_t buf_len);

///////////////////////////////////////////////////////////////////////////////
/// qcarcam_client_start_preview
///
/// @brief Initialize QCarCam. And start preview
///
/// @param filename     config xml file
/// @param cbFunc       callback function to get new frame
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t qcarcam_client_start_preview(const char* filename, qcarcam_client_event_cb_t cb_func);

///////////////////////////////////////////////////////////////////////////////
/// qcarcam_client_stop_preview
///
/// @brief Stop preview. De-initialize QCarCam. Last call to library.
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t qcarcam_client_stop_preview(void);


#ifdef __cplusplus
}
#endif
#endif
