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
/// @brief Implementation of the ipc client

#ifndef ARA_IAM_IFC_IPC_CLIENT_ADAPTER_IMPL_H_
#define ARA_IAM_IFC_IPC_CLIENT_ADAPTER_IMPL_H_

#include <type_traits>
#include <sys/socket.h>
#include <sys/un.h>

#include "ara/iam/ifc/ipc/ipc_client_adapter_interface.h"

namespace ara
{
namespace iam
{
namespace ifc
{
namespace ipc
{
/// @brief Implementation of the interface IPCClientAdapterInterface
class IPCClientAdapterImpl : public IPCClientAdapterInterface
{
public:
    /// @brief Construct a new IPCClientAdapterImpl object
    IPCClientAdapterImpl();

    /// @brief deleted
    IPCClientAdapterImpl(const IPCClientAdapterImpl&) = delete;

    /// @brief Destroy the IPCClientAdapterImpl object
    virtual ~IPCClientAdapterImpl();

    /// @brief Establishes a connection to a server listening at the given path.
    ///
    /// @param serverIPCPath IPS Server path
    /// @param sendTimeout Send timeout
    /// @param recvTimeout Receive timeout
    /// @param type SOCK_STREAM or SOCK_SEQPACKET
    /// @returns ara::core::Result<void>
    ara::core::Result<void> Connect(const ara::core::String& serverIPCPath,
        const timeval& sendTimeout,
        const timeval& recvTimeout,
        const int type) override;

    /// @brief Disconnect the existing connection
    void Disconnect() noexcept override;

    /// @brief Send the credentials
    ///
    /// @returns ara::core::Result<void> Error in case of failure
    ara::core::Result<void> SendCredentials() override;

    /// @brief Check if the an error is set for the connection
    ///
    /// @returns True if no error is set for a valid socket
    bool CheckConnection() const override;

    /// @brief Attempt to receive a message via IPC. Returns after a timeout if no message could be received.
    ///
    /// @param buffer Pointer to the buffer
    /// @param buffer_size Length of the buffer
    /// @returns negative value on error or bytes read
    ara::core::Result<ssize_t> Receive(void* buffer, const std::size_t buffer_size) const override;

    /// @brief Send data to another application
    ///
    /// @param message Data
    /// @param length Length of data to write
    /// @returns Error in case of failure
    ara::core::Result<void> Send(const void* message, const std::size_t length) const override;

private:
    /// @brief Establishes a connection to a server listening at the given path.
    ///
    /// @param serverIPCPath The path to the socket of the server.
    /// @returns ara::core::Result<void> Error in case connection fails
    ara::core::Result<void> ConnectSocketToServer(const ara::core::String& serverIPCPath) const;

    /// @brief Set the timeouts for read/write operations on the current socket descriptor.
    ///
    /// @param sendTimeout Send timeout
    /// @param recvTimeout Receive timeout
    void AdjustSocketTimeouts(const timeval& sendTimeout, const timeval& recvTimeout) const noexcept;

    /// @brief File descriptor associated with the socket connection to the server.
    int socketDescriptor_;
};

}  // namespace ipc
}  // namespace ifc
}  // namespace iam
}  // namespace ara

#endif /* ARA_IAM_IPC_IPC_CLIENT_ADAPTER_IMPL_H_ */
