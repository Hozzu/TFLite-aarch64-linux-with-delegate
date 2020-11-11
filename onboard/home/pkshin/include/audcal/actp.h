#ifndef ACTP_H
#define ACTP_H
/**
  \file **************************************************************************
 *
 *                                       A C T P   H E A D E R    F I L E
 *
 *DESCRIPTION
 * This header file contains all the definitions necessary for ACTP protocol
 * layer to initialize  ACTP diag dispatcher.
 * This actp works in both ARM9 and ARM11
 *
 * Copyright (c) 2010-2018 by Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *******************************************************************************
 */
/**
  \file ***************************************************************************
 *
 *                      EDIT HISTORY FOR FILE
 *
 *  This section contains comments describing changes made to this file.
 *  Notice that changes are listed in reverse chronological order.
 *
 *  $Header:
 *
 *when         who     what, where, why
 *--------   ---     ----------------------------------------------------------
 *05/28/10     ayin     initial draft
 ********************************************************************************
 */

/*
   --------------------
   |include files                |
   --------------------
   */
#ifdef ACDB_WIN32_SIM
#include "audtp.h"
#endif
/*
   --------------------
   |Macros                      |
   --------------------
   */
/*ACTP subsystem command ID Range (inclusive)*/

/**
 *ACTP subsystem command code range start ID
 */

#define ACTP_CMD_ID_START 2051
#define ACTP_CMD_ID_END 2100

#ifdef ACDB_WIN32_SIM
#define PACKED
#define word uint32_t
#endif

/*
   ---------------------
   | External functions |
   ---------------------
   */
/**
 * FUNCTION : actp_diag_init

 * DESCRIPTION :
 *Registers the subsystem diag dispathcer with diag dispathcer.<br>
 * Initializes the actp session.
 *
 * DEPENDENCIES : actp_diag_table[] should be initialized.<br>
 * And actp_diag_table should have proper sub system command.code range and
 pointer to the dispatcher function.
 * Diag Packet Service must be available.
 *
 * PARAMS:
 *   callback_function - the callback function for diag packet
 *
 * RETURN VALUE : None

 * SIDE EFFECTS : None
 */
extern void actp_diag_init(
        void (*callback_function)(uint8_t*, uint32_t, uint8_t**, uint32_t*)
        );

/**
 * FUNCTION : actp_diag_deinit

 * DESCRIPTION :
 *De-registers the subsystem with diag.<br>
 *
 * DEPENDENCIES : None
 *
 * PARAMS: None
 *
 * RETURN VALUE : None

 * SIDE EFFECTS : None
 */
extern void actp_diag_deinit(void);

/**
 * FUNCTION : avsACTP_diag_cmd
 *
 * DESCRIPTION :
 *This is the entry point to ACTP when seen from PC.
 *and is the sub system diag dispathcer for Audio Calibration Tranporter Protocol
 *Receives a diag packet meant for ACTP and passes to protocol layer and returns
 the response diag packet.
 *
 * DEPENDENCIES :
 *
 * PARAMS:
 *   request - the diag request packet (packed)
 *   length - the length of the diag request packet
 *
 * RETURN VALUE : returns response diag packet.
 *In case of error, returns diag packet with error code DIAG_BAD_CMD_F
 *
 * SIDE EFFECTS : None
 */
#ifndef ACDB_WIN32_SIM
extern PACKED void *  avsACTP_diag_cmd (
        PACKED void *request,
        word length
        );
#else
extern void avsACTP_diag_cmd(
                               /** pointer to the diag packet which contains the atp frame from request buffer*/
                               diag_pkt_req_struct *atp_diag_req_pkt_ptr,
                               /** pointer to the diag packet which contains the atp frame from response buffer*/
                               diag_pkt_resp_struct *atp_diag_rsp_pkt_ptr
                               );
#endif
#endif //ACTP_H

