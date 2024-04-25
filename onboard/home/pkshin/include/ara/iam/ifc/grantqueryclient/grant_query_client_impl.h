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
/// @brief Implementation for the grant query client

#ifndef ARA_IAM_IFC_GRANTQUERYCLIENT_GRANT_GRANT_QUERY_CLIENT_IMPL_H_
#define ARA_IAM_IFC_GRANTQUERYCLIENT_GRANT_GRANT_QUERY_CLIENT_IMPL_H_

#include <memory>
#include <mutex>
#include "ara/log/logger.h"
#include "ara/iam/ifc/grantqueryclient/grant_query_client_interface.h"
#include "ara/iam/ifc/ipc/ipc_client_adapter_interface.h"
namespace ara
{
namespace iam
{
namespace ifc
{
namespace grantqueryclient
{

/// @brief Class to check from the client side if a grant has been given.
///
/// This class establishes a bidirectional communication channel for data exchange with the Access Manager.
class IAMGrantQueryClientImpl : public IAMGrantQueryClientInterface
{
public:
    /// @brief Construct a new IAMGrantQueryClientImpl object with the default IPCClientAdapterImpl
    IAMGrantQueryClientImpl();

    /// @brief Construct a new IAMGrantQueryClientImpl object
    ///
    /// @param ipc IPC implementation
    IAMGrantQueryClientImpl(std::unique_ptr<ara::iam::ifc::ipc::IPCClientAdapterInterface> ipc);

    /// @brief Destroy the IAMGrantQueryClientImpl object
    virtual ~IAMGrantQueryClientImpl() = default;

    /// @brief Checks if the given grant exists
    ///
    /// @param grant Grant
    /// @returns ara::core::Result<bool> true, if access has been granted. false if the access is forbidden.
    ///                                 In case of an error the appropriate error code GrantQueryClientErrc
    ///                                 is returned
    ara::core::Result<bool> HasGrant(const ara::iam::ifc::grant::Grant& grant) override;

private:
    ara::log::Logger& logger_;  ///< Logger
    std::mutex mutex;  ///< Mutex to access ipcClientAdapter
    std::unique_ptr<ara::iam::ifc::ipc::IPCClientAdapterInterface> ipcClientAdapter;  ///< IPCClientAdapterInterface
};

}  // namespace grantqueryclient
}  // namespace ifc
}  // namespace iam
}  // namespace ara

#endif  // ARA_IAM_IFC_GRANTQUERYCLIENT_GRANT_GRANT_QUERY_CLIENT_IMPL_H_
