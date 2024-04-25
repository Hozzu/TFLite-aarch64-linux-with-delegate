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
/// @brief Implementation of the ipc server

#ifndef ARA_IAM_IFC_IPC_IPC_SERVER_ADAPTER_IMPL_H_
#define ARA_IAM_IFC_IPC_IPC_SERVER_ADAPTER_IMPL_H_

#include <atomic>
#include <string>
#include <memory>
#include <type_traits>
#include <sys/socket.h>
#include <sys/un.h>

#include "ara/iam/ifc/ipc/ipc_server_adapter_interface.h"

namespace ara
{
namespace iam
{
namespace ifc
{
namespace ipc
{

/// \brief Class to handle requests coming in on a socket.
class IPCServerAdapterImpl : public IPCServerAdapterInterface
{
public:
    /// @brief Construct a new IPCServerAdapterImpl object
    IPCServerAdapterImpl();

    /// @brief Remove copy constructor
    IPCServerAdapterImpl(const IPCServerAdapterImpl&) = delete;

    /// @brief Construct a new IPCServerAdapterImpl object
    ///
    /// @param other IPCServerAdapterImpl IPCServerAdapterImpl to be moved
    IPCServerAdapterImpl(IPCServerAdapterImpl&& other);

    /// @brief Destroy the IPCServerAdapterImpl object
    virtual ~IPCServerAdapterImpl() override;

    /// @brief deleted
    ///
    /// @return deleted
    IPCServerAdapterImpl& operator=(const IPCServerAdapterImpl&) = delete;

    /// @brief Move assignment
    ///
    /// @param other IPCServerAdapterImpl
    /// @returns *this
    IPCServerAdapterImpl& operator=(IPCServerAdapterImpl&& other);

    /// @brief Open a socket and start listening on it.
    ///
    /// @param serverIPCPath Filesystem path where the new socket should be found.
    /// @param sendTimeout   send timeout
    /// @param recvTimeout   receive timeout
    /// @param type          SOCK_STREAM or SOCK_SEQPACKET
    /// @param block          true if blocking
    /// @returns True if successful
    bool ConnectServerSocket(const ara::core::String& serverIPCPath,
        const timeval& sendTimeout,
        const timeval& recvTimeout,
        int type,
        bool block) override;

    /// @brief Terminate the connection to the server socket.
    void CloseServerConnection() override;

    /// @brief Terminate a socket connection to a client.
    ///
    /// @param clientSocketDescriptor The descriptor for the socket connection to be closed.
    void CloseClientConnection(const int clientSocketDescriptor) override;

    /// @brief Check if the an error is set for the connection
    ///
    /// @param clientSocketDescriptor The descriptor for the socket connection
    /// @returns True if no error is set for a valid clientSocketDescriptor
    bool CheckConnection(const int clientSocketDescriptor) const noexcept override;

    /// @brief Wait for a client to connect and establish the connection, or return after a fixed timeout.
    ///
    /// @param selectTimeout Timeout
    /// @returns The file descriptor of the new socket connection, or -1 in case of errors or a timeout.
    int EstablishNewClientConnection(const timeval& selectTimeout) override;

    /// @brief Receive the process ID of a client.
    ///
    /// @param clientSocketDescriptor The descriptor for the socket connection to be read from.
    /// @returns ara::core::Result<pid_t> pid or error
    ara::core::Result<pid_t> ReceiveClientPID(const int clientSocketDescriptor) const override;

    /// @brief Obtain the process ID of a client which was in effect at the time of the connect call
    ///
    /// @param clientSocketDescriptor The descriptor for the socket connection to be read from.
    /// @returns ara::core::Result<pid_t> pid or error
    ara::core::Result<pid_t> GetPeerPID(const int clientSocketDescriptor) const override;

    /// @brief Attempt to receive a message via IPC. Returns after a timeout if no message could be received.
    ///
    /// @param buffer Pointer to the buffer
    /// @param buffer_size Length of the buffer
    /// @param clientSocketDescriptor The descriptor for the socket connection to be read from.
    /// @returns negative value on error or bytes read
    ara::core::Result<ssize_t> Receive(void* buffer,
        const std::size_t buffer_size,
        const int clientSocketDescriptor) const override;

    /// @brief Send data to another application
    ///
    /// @param message Data
    /// @param length Length of data to write
    /// @param clientSocketDescriptor The descriptor for the socket connection to be written to.
    /// @returns Error in case of failure
    ara::core::Result<void> Send(const void* message,
        const std::size_t length,
        const int clientSocketDescriptor) const override;

private:
    /// @brief Wait for a connection attempt by a client, or return after a fixed timeout.
    ///
    /// @param selectTimeout
    /// @returns -1 error,  0 timeout, >0 connection attempt
    int WaitForConnectionAttempt(const timeval& selectTimeout) const noexcept;

    /// @brief Set the timeouts for read/write operations on a given socket descriptor.
    ///
    /// @param socketDescriptor The file descriptor of the socket to be modified.
    void AdjustSocketTimeouts(const int socketDescriptor) const noexcept;

    std::atomic<int> serverSocketDescriptor_;  ///< File descriptor of the socket used to listen for new connections.
    timeval sendTimeout_;  ///< Send Timeout
    timeval recvTimeout_;  ///< Receive Timeout

    /// Internal constant
    static constexpr int kNoConnectionAttempt = 0;
};

}  // namespace ipc
}  // namespace ifc
}  // namespace iam
}  // namespace ara

#endif  // ARA_IAM_IFC_IPC_IPC_SERVER_ADAPTER_IMPL_H_
