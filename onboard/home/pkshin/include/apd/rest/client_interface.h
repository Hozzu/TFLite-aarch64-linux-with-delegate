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

#ifndef LIB_APDREST_INCLUDE_APD_REST_CLIENT_INTERFACE_H_
#define LIB_APDREST_INCLUDE_APD_REST_CLIENT_INTERFACE_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apd/rest/client_types.h"
#include "apd/rest/endpoint.h"
#include "apd/rest/function.h"
#include "apd/rest/pointer.h"
#include "apd/rest/task.h"
#include "apd/rest/uri.h"

namespace apd
{
namespace rest
{

/**
 * Interface for Client binding implementation
 */
class ClientInterface
{
public:
    /**
     * TODO
     */
    ClientInterface() = default;

    explicit ClientInterface(const ClientInterface&) = delete;  ///< Client is non-copy-constructible
    ClientInterface& operator=(const ClientInterface&) = delete;  ///< Client is non-copy-assignable

    /**
     * Destructor
     */
    virtual ~ClientInterface() = default;

    /**
     * TODO
     * @param req
     * @return
     */
    virtual Task<Pointer<Reply>> Send(const Request& req) = 0;

    /**
     * TODO
     * @param policy
     * @return
     */
    virtual Task<void> Stop(ShutdownPolicy policy = ShutdownPolicy::kGraceful) = 0;

    /**
     * \brief Performs an event subscription
     *
     *  \param uri the event to subscribe to
     *  \param policy the notification policy
     *  \param time time bound as a parameter of the notification policy
     *  \param notify user-defined event notification handler function
     *  \param state user-define subscription state observer function
     *  \return a task waiting for the Event construction and subscription Reply.
     */
    virtual Task<Event> Subscribe(const Uri& uri,
        EventPolicy policy,
        duration_t time,
        const Function<client::NotificationHandlerType>& notify,
        const Function<client::SubscriptionStateHandlerType>& state = {})
        = 0;
};

}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_CLIENT_INTERFACE_H_
