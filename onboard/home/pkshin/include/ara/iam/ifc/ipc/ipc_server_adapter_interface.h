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

/// @file
/// @brief Interface specification for the ipc server

#ifndef ARA_IAM_IFC_IPC_SERVER_INTERFACE_H_
#define ARA_IAM_IFC_IPC_SERVER_INTERFACE_H_

#include <cstdint>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>

#include "ara/core/string.h"
#include "ara/core/result.h"
#include "ara/iam/ifc/ipc/ipc_adapter_error_domain.h"

namespace ara
{
namespace iam
{
namespace ifc
{
namespace ipc
{

/// @brief Interface class for IPC implementations that are to be used by the Access Manager.
class IPCServerAdapterInterface
{
public:
    /// @brief Destroy the IPCServerAdapterInterface object
    virtual ~IPCServerAdapterInterface() = default;

    /// @brief Open a socket and start listening on it.
    ///
    /// @param serverIPCPath Filesystem path where the new socket should be found.
    /// @param sendTimeout   send timeout
    /// @param recvTimeout   receive timeout
    /// @param type          SOCK_STREAM or SOCK_SEQPACKET
    /// @param block          true if blocking
    /// @returns True if successful
    virtual bool ConnectServerSocket(const ara::core::String& serverIPCPath,
        const timeval& sendTimeout,
        const timeval& recvTimeout,
        int type,
        bool block)
        = 0;

    /// @brief Terminate the connection to the server socket.
    virtual void CloseServerConnection() = 0;

    /// @brief Terminate a socket connection to a client.
    ///
    /// @param clientSocketDescriptor The descriptor for the socket connection to be closed.
    virtual void CloseClientConnection(const int clientSocketDescriptor) = 0;

    /// @brief Check if the an error is set for the connection
    ///
    /// @param clientSocketDescriptor The descriptor for the socket connection
    /// @returns True if no error is set for a valid clientSocketDescriptor
    virtual bool CheckConnection(const int clientSocketDescriptor) const noexcept = 0;

    /// @brief Wait for a client to connect and establish the connection, or return after a fixed timeout.
    ///
    /// @param selectTimeout Timeout
    /// @returns The file descriptor of the new socket connection, or -1 in case of errors or a timeout.
    virtual int EstablishNewClientConnection(const timeval& selectTimeout) = 0;

    /// @brief Receive the process ID of a client.
    ///
    /// @param clientSocketDescriptor The descriptor for the socket connection to be read from.
    /// @returns ara::core::Result<pid_t> pid or error
    virtual ara::core::Result<pid_t> ReceiveClientPID(const int clientSocketDescriptor) const = 0;

    /// @brief Obtain the process ID of a client which was in effect at the time of the connect call
    ///
    /// @param clientSocketDescriptor The descriptor for the socket connection to be read from.
    /// @returns ara::core::Result<pid_t> pid or error
    virtual ara::core::Result<pid_t> GetPeerPID(const int clientSocketDescriptor) const = 0;

    /// @brief Attempt to receive a message via IPC. Returns after a timeout if no message could be received.
    ///
    /// @param buffer Pointer to the buffer
    /// @param buffer_size Length of the buffer
    /// @param clientSocketDescriptor The descriptor for the socket connection to be read from.
    /// @returns negative value on error or bytes read
    virtual ara::core::Result<ssize_t> Receive(void* buffer,
        const std::size_t buffer_size,
        const int clientSocketDescriptor) const = 0;

    /// @brief Send data to another application
    ///
    /// @param message Data
    /// @param length Length of data to write
    /// @param clientSocketDescriptor The descriptor for the socket connection to be written to.
    /// @returns Error in case of failure
    virtual ara::core::Result<void> Send(const void* message,
        const std::size_t length,
        const int clientSocketDescriptor) const = 0;
};

}  // namespace ipc
}  // namespace ifc
}  // namespace iam
}  // namespace ara

#endif  // ARA_IAM_IFC_IPC_SERVER_INTERFACE_H_
