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

#ifndef LIB_APDREST_INCLUDE_APD_REST_SERVER_INTERFACE_H_
#define LIB_APDREST_INCLUDE_APD_REST_SERVER_INTERFACE_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apd/rest/server.h"
#include "apd/rest/server_types.h"

namespace apd
{
namespace rest
{

/**
 * Interface to make different kind of server bindings (e.g. HTTP) possible to be use by the server.h
 */
class ServerInterface
{
public:
    /**
     * \brief Default Constructor
     */
    ServerInterface() = default;

    explicit ServerInterface(const ServerInterface&) = delete;  ///< Server is non-copy-constructible
    ServerInterface& operator=(const ServerInterface&) = delete;  ///< Server is non-copy-assignable

    /**
     * \brief Destructor
     */
    virtual ~ServerInterface() = default;

    /**
     * \brief Start the Server Binding asynchronously
     * \param policy
     * \return
     */
    virtual Task<void> Start(StartupPolicy policy = StartupPolicy::kDetached) = 0;

    /**
     * \brief Stop the Server asynchronously
     * \param policy
     * \return
     */
    virtual Task<void> Stop(ShutdownPolicy policy = ShutdownPolicy::kGraceful) = 0;

    /**
     * \brief
     * @param shnd
     * @param sshnd
     */
    virtual void ObserveSubscriptions(const Function<SubscriptionHandlerType>& shnd,
        const Function<SubscriptionStateHandlerType>& sshnd)
        = 0;

    /** \brief Obtain server status
     * \return a reference to the server Status
     */
    virtual std::error_code GetError() const noexcept = 0;

    /** \brief Observe status changes
     *
     *  \param hnd user-defined handler function to to called on status changes
     */
    virtual void ObserveError(const Function<void(std::error_code)>& hnd) = 0;
};

}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_SERVER_INTERFACE_H_
