#ifndef _QSOCKET_IPCR_H_
#define _QSOCKET_IPCR_H_
/******************************************************************************
  @file    qsocket_ipcr.h
  @brief   IPC Router protocol specific definitions

  DESCRIPTION

  IPC Router:
  IPC Router is a connection-less datagram protocol covering the Network
  and Transport layers of the OSI model. It provides a packet delimited
  end-to-end flow control. Any streaming functionalities provided by
  IPC Router are implemented on top of the datagram methods. IPC Router
  also provides a reliable transport to users as it expects reliability
  from it's link layer.

  IPC Router provides a control endpoint to allow services/clients to
  listen on events from the distributed name service.

  IPC Router also provides a distributed name service in order to provide
  location transparency to it's clients

  This header provides a set of socket-like API to to communicate
  over IPC Router.

  Certain Operating systems might need special setup. Please refer
  to qsocket_<os>.h if it exists

  ---------------------------------------------------------------------------
  Copyright (c) 2014, 2018 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------

 *******************************************************************************/
#include "qsocket.h"
#include "msm_ipc.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================
                          SOCKET OPTION DEFINES
============================================================================*/

/* IPC Router specific socket options */
#define QSOL_IPC_ROUTER 0

/* Sets the current socket as a control port so it
 * may receive events from the name service */
#define QSO_IPCR_SET_CONTROL_PORT 1

/* This option is valid only if the QSO_IPCR_SET_CONTROL_PORT
* option is set on the socket. This will limit the name server
* events such as NEW_NAME and REMOVE_NAME to a specific type.
* The option value is a 32 bit integer (uint32_t) which will
* specify the 'type' field of the name we are interested in */
#define QSO_IPCR_SET_TYPE_PREF 2

/*============================================================================
                         SOCKET GETADDRINFO FLAGS
============================================================================*/

/* Flags to ipcr_getaddrinfo which asks the interface
 * to ignore the provided instance field of the name to lookup */
#define IPCR_FLAGS_ANY_INSTANCE 1

/*============================================================================
                             TYPES
============================================================================*/
#define AF_IPC_ROUTER AF_MSM_IPC

typedef struct msm_ipc_port_addr ipcr_port_t;
typedef struct msm_ipc_port_name ipcr_name_t;

#define IPCR_ADDR_PORT MSM_IPC_ADDR_ID
#define IPCR_ADDR_NAME MSM_IPC_ADDR_NAME

#define qsockaddr_ipcr sockaddr_msm_ipc

/* Type returned by name lookups */
typedef struct
{
  ipcr_name_t name;
  ipcr_port_t port;
} ipcr_addrinfo_t;

/* Types of events which can be received
 * from the CTRL socket */
typedef enum
{
  IPCR_CTRL_INVALID = 0,
  IPCR_CTRL_NEW_NAME,
  IPCR_CTRL_REMOVE_NAME,
  IPCR_CTRL_REMOVE_PORT,
} ipcr_ctrl_type;

/* Control message format received from
 * the control socket */
typedef struct
{
  ipcr_ctrl_type type;
  ipcr_port_t port;
  ipcr_name_t name;
} ipcr_ctrl_msg;

/*============================================================================
               PROTOCOL SPECIFIC HELPER METHODS
============================================================================*/

/*===========================================================================
  FUNCTION  ipcr_find_name
===========================================================================*/
/*!
@brief

 Finds all ports with the associated name

@param[in]   fd        Caller's file descriptor
@param[in]   name      Name of the port
@param[out]  addrs     Pointer to array of addresses to store
                       the address of found ports with matching
                       name.
@param[out]  instances (Optional, can be NULL) Pointer to array of
                       instance IDs of the names found (Useful if
                       IPCR_FLAGS_ANY_INSTANCE is used to get the
                       instance ID of the found address). Note, the
                       array must allow the same number of entries
                       as 'addrs'
@param[inout]num_entires Input the size of the array 'addrs' and
                         if provided, 'instances'.
                         Output, the number of entries filled.
@param[in]   flags     0 for an exact match on the provided
                       TYPE and INSTANCE pair.
                       IPCR_FLAGS_ANY_INSTANCE to match just
                       the TYPE.

@return
  Number of services found upon success, negative error code on failure.

@note

  - Dependencies
    - The user must hold a valid file descriptor toward IPC Router.
      (return of qsocket(AF_IPC_ROUTER, *, *)

  - Side Effects
    - None
*/
/*=========================================================================*/
int ipcr_find_name(int fd, ipcr_name_t *name, struct qsockaddr_ipcr *addrs,
                   unsigned int *instances, unsigned int *num_entries,
                   unsigned int flags);

#ifdef __cplusplus
}
#endif

#endif
