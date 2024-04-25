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

#ifndef LIB_APDREST_INCLUDE_APD_REST_CLIENT_H_
#define LIB_APDREST_INCLUDE_APD_REST_CLIENT_H_

#include <memory>
#include <system_error>

#include "apd/rest/allocator.h"

#include "apd/rest/client_interface.h"
#include "apd/rest/client_types.h"
#include "apd/rest/endpoint.h"
#include "apd/rest/function.h"
#include "apd/rest/header.h"
#include "apd/rest/pointer.h"
#include "apd/rest/task.h"
#include "apd/rest/uri.h"

namespace apd
{
namespace rest
{

/** \brief Represents a client session with a particular server
 *
 *  A client represents all resources related to communication. By configuration a
 *  client is bound to one particular transport binding. Although the configuration
 *  may bind a client to one particular server by default, a client may connect
 *  to arbitrary servers of the same transport protocol.
 *  A client manages the request/reply cycles to servers but also manages event subscriptions.
 *  How requests and replies are delivered, or the handling of events is depended on the
 *  capabilities and constraints of the transport protocol.
 *  \uptrace{SWS_REST_02006}
 */
class Client
{
public:
    /** \brief Denotes a callback function for notifications
     * \uptrace{SWS_REST_02007}
     * */
    using NotificationHandlerType = client::NotificationHandlerType;
    /** \brief Denotes a callback to call if subscription status changes
     * \uptrace{SWS_REST_02008}
     */
    using SubscriptionStateHandlerType = client::SubscriptionStateHandlerType;

    /** \brief Constructs a client
     *
     *  \param conf_id identifier for a corresponding configuration record
     *  \param alloc allocator for dynamic memory
     *  \uptrace{SWS_REST_02009}
     */
    explicit Client(const String& conf_id, Allocator* alloc = GetDefaultAllocator());

    Client(const Client&) = delete;  ///< non-copy-constructible \uptrace{SWS_REST_02010}
    Client& operator=(const Client&) = delete;  ///< non-copy-assignable \uptrace{SWS_REST_02011}

    /** \brief Requests a client shutdown
     *
     * If shutting down gracefully, the client waits for all transactions to finish.
     * If not, then all connections must be terminated instantly.
     *
     * Note that Stop() does not switch Client() into an invalid state. It only
     * terminates all ongoing transmissions. Events are unaffected by this and
     * remain valid until explicitly invalidated by subscription cancellation or
     * destruction.
     *
     *  \param policy shutdown policy
     *  \return a task waiting for shutdown to complete
     *  \uptrace{SWS_REST_02012}
     */
    Task<void> Stop(ShutdownPolicy policy = ShutdownPolicy::kGraceful);

    // The reply lives as long as the client lives.
    // Whether client maintains an internal buffer or objects
    // are allocated globally and therefore persistent is implementation defined.

    /** \brief Issues a request to a peer
     *
     *  Issues a request to the peer either specified in the client configuration record or the URI of
     *  the request. The configuration record is identified by the id specified in the Client
     *  constructor. If Uri::Authority is set, it overwrites the configuration record.
     *
     *  \param req a request message
     *  \return a task waiting for the corresponding reply
     *  \uptrace{SWS_REST_02013}
     */
    Task<Pointer<Reply>> Send(const Request& req);

    /** \brief Performs an event subscription
     *
     * An event is uniquely identified by its Uri. A subscription to an event means
     * that if preconditions are met a notification is issued whose message payload
     * is identical to the result set obtained by issuing a GET request on the Uri.
     *
     * Different notification policies
     *
     *  \param uri the event to subscribe to
     *  \param policy the notification policy
     *  \param time time bound as a parameter of the notification policy
     *  \param notify user-defined event notification handler function
     *  \param state user-define subscription state observer function
     *  \return a task waiting for the Event construction and subscription Reply.
     *  \uptrace{SWS_REST_02014}
     */
    Task<Event> Subscribe(const Uri& uri,
        EventPolicy policy,
        duration_t time,
        const Function<NotificationHandlerType>& notify,
        const Function<SubscriptionStateHandlerType>& state = {});

    /** \brief Obtain client status
     *
     * \return status of the client
     * \uptrace{SWS_REST_02015}
     */
    std::error_code GetError() const noexcept;

    /** \brief Observe status changes
     *
     *  \param hnd user-defined handler function to called on status changes
     *  \uptrace{SWS_REST_02016}
     */
    void ObserveError(const Function<void(std::error_code)>& hnd);

private:
    /**
     * \brief The underlying binding instance.
     */
    Pointer<ClientInterface> client_;

    /**
     * \brief Client error
     */
    std::error_code error_;

    /**
     * \brief Sets the client status and calls the observer function
     */
    void SetError(std::error_code error);

    /**
     * \brief Error observer function
     */
    Function<void(std::error_code)> error_observer_;
};
}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_CLIENT_H_
