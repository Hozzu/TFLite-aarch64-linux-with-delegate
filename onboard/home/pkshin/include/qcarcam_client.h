/* ===========================================================================
 * Copyright (c) 2017-2020 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
=========================================================================== */

#ifndef _QCARCAM_CLINENT_H
#define _QCARCAM_CLINENT_H

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




typedef enum{
    QCARCAM_STATE_INVALID = 0,
    QCARCAM_STATE_INIT,
    QCARCAM_STATE_OPEN,
    QCARCAM_STATE_START,
    QCARCAM_STATE_STOP,
    QCARCAM_STATE_PAUSE,
    QCARCAM_STATE_ERROR,
    QCARCAM_STATE_PAUSE_STOP_PENDING,
    QCARCAM_STATE_OK,
    QCARCAM_STATE_FREEZE,
    QACRCAM_STATE_UNKNOW

}qcarcam_status;

typedef void (*qcarcam_client_event_cb_t) (int input_id, unsigned char* buf_ptr, size_t buf_len);



///////////////////////////////////////////////////////////////////////////////
/// qcarcam_client_getCamStatus
///
/// @brief get camera status
///
/// @param index     camera index
///
/// @return qcarcam_status
///////////////////////////////////////////////////////////////////////////////

qcarcam_status qcarcam_client_getCamStatus(int index);

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
int qcarcam_client_start_preview(const char* filename, qcarcam_client_event_cb_t cb_func);


///////////////////////////////////////////////////////////////////////////////
/// qcarcam_client_start_preview
///
/// @brief Initialize QCarCam. And start preview
///
/// @param filename     config xml file
/// @param cbFunc       callback function to get new frame
/// @param option       bitfield ( QCARCAM_OPT_NODISPLAY, QCARCAM_OPT_FATAL_COVER)
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
#define QCARCAM_OPT_NODISPLAY       (1<<0)
#define QCARCAM_OPT_FATAL_COVER     (1<<1)
int qcarcam_client_start(const char* filename, qcarcam_client_event_cb_t cb_func, unsigned int option);

///////////////////////////////////////////////////////////////////////////////
/// qcarcam_client_stop_preview
///
/// @brief Stop preview. De-initialize QCarCam. Last call to library.
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
int qcarcam_client_stop_preview(void);

unsigned char * qcarcam_client_get_buffer(int camera_id);

#ifdef __cplusplus
}
#endif
#endif
