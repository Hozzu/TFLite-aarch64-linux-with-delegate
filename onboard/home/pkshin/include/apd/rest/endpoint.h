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

#ifndef LIB_APDREST_INCLUDE_APD_REST_ENDPOINT_H_
#define LIB_APDREST_INCLUDE_APD_REST_ENDPOINT_H_

#include <limits>
#include <system_error>

#include "apd/rest/allocator.h"
#include "apd/rest/string.h"
#include "apd/rest/types.h"

namespace apd
{
namespace rest
{

/** \brief Specifies a set possible API access methods
 *
 * RequestMethod largely corresponds to typical RESTful API access methods.
 * RequestMethod::kOptions is a "meta" method in that it does not specify a data access
 * but for the API description of a particular service.
 * RequestMethid::kEvent indicates a "replayed" GET request.
 *
 * An apd::rest server is unaware of transport protocols or concrete service types. In case of
 * events it only provides the necessary infrastructure. Technically, it provides infrastructure to
 * "record" and "replays" a particular read request. To an application, it is not directly apparent
 * that a request serves an event mechanism except for the fact that the request method is set to
 * RequestMethod::kEvent. This enables an application to apply special semantics for these
 * kinds of requests
 * \uptrace{SWS_REST_02349}
 */
enum class RequestMethod : std::uint32_t
{
    kGet = 1 << 0,  ///< Indicated a request to read an item
    kPost = 1 << 1,  ///< Indicates a request to create an item
    kPut = 1 << 2,  ///< Indicates a request to create or update an item
    kDelete = 1 << 3,  ///< Indidicates a request to erase an item
    kOptions = 1 << 4,  ///< Usually indicates a request for a listing API capabilities
    kAny = ~std::underlying_type<RequestMethod>::type{0}
};
/** \brief Returns a set of enumerators
 *
 * Conceptually, this lifts the concept of "enum" from singleton sets to general sets.
 * This is still type safe, standard compliant and expressions like 'kGet|kPost' are conceptually
 * fully valid compile-time "literals". That means that things like "switch (m) {  case kGet|kPost:  }"
 * just works.
 *  \param a a set of RequestMethod enumerators
 *  \param b a set of RequestMethod enumerators
 *  \return  a set of RequestMethods
 */
constexpr RequestMethod operator|(RequestMethod a, RequestMethod b) noexcept
{
    return a | b;
}

/** \brief Does a bitwise AND of the RequestMethods
 *  \param a a set of RequestMethod enumerators
 *  \param b a set of RequestMethod enumerators
 *  \return  a set of RequestMethods
 */
constexpr std::underlying_type<RequestMethod>::type operator&(RequestMethod a, RequestMethod b) noexcept
{
    return std::underlying_type<RequestMethod>::type(a) & std::underlying_type<RequestMethod>::type(b);
}

/** \brief Denotes the state of the subscription relation represented by an Event
 *
 *  The enumerators have the following meaning:
 *  - kSubscribed: A logical notification channel has been established by mutual consent (handshake)
 *      of the respective peers.
 *  - kCanceled: A channel has been termimnated by mutual consent.
 *      A client is allowed to resubscribe to reestablish a subscription.
 *  - kInvalid: A channel has been terminated without mututal consent.
 *      A client is allowed to resubscribe to reestablish the connection.
 * \uptrace{SWS_REST_02350}
 */
enum class SubscriptionState
{
    kSubscribed,  ///< Subscription is established
    kCanceled,  ///< Subscription has been cancelled
    kInvalid  ///< Subscription is invalid
};

/** \brief Mode of operation for event subscriptions
 *
 * Defines the mode of operation for event subscriptions.
 * The modes have the following semantics:
 *
 * - EventPolicy::kTriggered An event is only trigger upon explicit request through Event::Trigger()
 *   A given time bound limits the number of requests per time frame to at most once.
 *
 * - EventPolicy::kPeriodic: An event is triggered in constant time frames. Calls to
 *    Event::Trigger() have no effect.
 *
 * - EventPolicy::kPeriodic | EventPolicy::kPeriodic: An event is triggered the end of each given
 *   time frame, if and only if Event::Trigger() has been invoked within this frame at least
 *   once. Additional invocations of Event::Notify() must be ignored.
 * \uptrace{SWS_REST_02351}
 */
enum class EventPolicy : std::uint32_t
{
    kTriggered = 1u << 0,
    kPeriodic = 1u << 1
};
/** \brief Computes a set of EventPolicy enumerators
 */
constexpr EventPolicy operator|(EventPolicy, EventPolicy) noexcept;

/** \brief Specifies shutdown behavior of endpoints
 *
 *  Endpoints can shut down "gracefully", which allows all oongoing transactions to finish while
 *  blocking the caller. A forced shutdown must cancel or terminate all transations as fast as
 *  possible does not block the caller for "unreasonably" long period of time. During a forced
 *  shutdown I/O is not allowed.  Precise semantics of these policies are implementation defined.
 * \uptrace{SWS_REST_02352}
 */
enum class ShutdownPolicy : std::uint32_t
{
    kForced,  //< Forces all transactions to cancel or terminate immediately
    kGraceful  //< Allows peers to finish on-going transations and close connnections in mutual consent
};

/** \brief Specifies whether a server will detach itself from its owning context
 *
 *  If a server is started "detached" then are::rest::Server::Start() does not block.
 *  Effecticely it will request a separate exection context (such as a thread) from apd::rest.
 *  If started "attached" then are::rest::Server::Start() blocks
 *  Effecively the server executes in the contect of the caller.
 * \uptrace{SWS_REST_02353}
 */
enum class StartupPolicy : std::uint32_t
{
    kDetached,  //< Starts a server in a separate execution context
    kAttached  //< Starts a server in the execution context of the endpoint owner
};
}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_ENDPOINT_H_
