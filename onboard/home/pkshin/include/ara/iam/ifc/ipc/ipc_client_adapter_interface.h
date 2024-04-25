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
/// @brief Interface specification for the ipc client

#ifndef ARA_IAM_IFC_IPC_IPC_CLIENT_ADAPTER_INTERFACE_H_
#define ARA_IAM_IFC_IPC_IPC_CLIENT_ADAPTER_INTERFACE_H_

#include <sys/time.h>
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
/// @brief Interface specification for the ipc client adapter
class IPCClientAdapterInterface
{
public:
    /// @brief Destroy the IPCClientAdapterInterface object
    virtual ~IPCClientAdapterInterface() = default;

    /// @brief Establishes a connection to a server listening at the given path.
    ///
    /// @param serverIPCPath
    /// @param sendTimeout Send timeout
    /// @param recvTimeout Receive timeout
    /// @param type SOCK_STREAM or SOCK_SEQPACKET
    /// @returns ara::core::Result<void>
    virtual ara::core::Result<void> Connect(const ara::core::String& serverIPCPath,
        const timeval& sendTimeout,
        const timeval& recvTimeout,
        const int type)
        = 0;

    /// @brief Disconnect the existing connection
    virtual void Disconnect() noexcept = 0;

    /// @brief Send the credentials
    ///
    /// @returns ara::core::Result<void> Error in case of failure
    virtual ara::core::Result<void> SendCredentials() = 0;

    /// @brief Check if the an error is set for the connection
    ///
    /// @returns True if no error is set for a valid socket
    virtual bool CheckConnection() const = 0;

    /// @brief Attempt to receive a message via IPC. Returns after a timeout if no message could be received.
    ///
    /// @param buffer Pointer to the buffer
    /// @param buffer_size Length of the buffer
    /// @returns negative value on error or bytes read
    virtual ara::core::Result<ssize_t> Receive(void* buffer, const std::size_t buffer_size) const = 0;

    /// @brief Send data to another application
    ///
    /// @param message Data
    /// @param length Length of data to write
    /// @returns Error in case of failure
    virtual ara::core::Result<void> Send(const void* message, const std::size_t length) const = 0;
};
}  // namespace ipc
}  // namespace ifc
}  // namespace iam
}  // namespace ara

#endif  // ARA_IAM_IFC_IPC_IPC_CLIENT_ADAPTER_INTERFACE_H_
