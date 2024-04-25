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

#ifndef LIB_APDREST_INCLUDE_APD_REST_ROUTING_ROUTER_H_
#define LIB_APDREST_INCLUDE_APD_REST_ROUTING_ROUTER_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include <functional>
#include <initializer_list>
#include <vector>

#include "apd/rest/allocator.h"
#include "apd/rest/iterator.h"
#include "apd/rest/routing/route.h"
#include "apd/rest/server.h"
#include "apd/rest/server_types.h"
#include "apd/rest/string.h"
#include "apd/rest/types.h"

namespace apd
{
namespace rest
{
namespace test
{
class RouterTest_Match_Test; /**< forward declaration for testing */
}  // namespace test

/** \brief ServerRequest handler for gine-grained message de-multiplexing
 *
 * This data structure maps requests to user-defined handler functions.
 * Per-default a Server only supports a single user-defined request handler
 * function. Router serves as a de-multiplexer to route requests to
 * a set of specific user-defined handler functions. The mapping is performed
 * by pattern matching against RequestMethod and Uri of a ServerRequest.
 *
 * Router maintains a (multi)set of routes. A request is matched against this set
 * until the first element matches. Each route is associated with a user-defined
 * request handler that is invoked with the Route object that matched the request
 * and the original ServerRequest/Reply objects.
 *
 * When matched, a route contains contextual information of this match (such as wildcard matches).
 * The user-defined "route handler" causes three different actions when returned from, which can
 * be controlled through the Route object itself:
 * - no action: If a route handler returns without further action, the router considers processing
 *              complete and returns control to the server
 * - default: A route may request that once the current handler is left, a router default handler is matched next - if
 * set.
 * - yield: A route may request that once the current handler is left, the next matching route is selected - if one
 * exists.
 * \uptrace{SWS_REST_02189}
 */
class Router
{
    /**< friend declaration for testing */
    friend class test::RouterTest_Match_Test;

public:
    /**
     * User-define route handler function type
     * \uptrace{SWS_REST_02190}
     */
    using RouteHandlerType = Route::RouteHandlerType;

    /**
     * Iterator range of routes
     * \uptrace{SWS_REST_02191}
     */
    using RouteRange = IteratorRange<unspecified_iterator_type>;

    /**
     * Const iterator range of routes
     * \uptrace{SWS_REST_02192}
     */
    using ConstRouteRange = IteratorRange<unspecified_iterator_type>;

    /** \brief Constructs an empty Router
     *
     *  \param alloc an allocator for all internal dynamic memory requirements
     *  \uptrace{SWS_REST_02193}
     */
    explicit Router(Allocator* alloc = GetDefaultAllocator());

    /** \brief Constructs a router from a given list of routes
     *
     *  \param routes a list of routes
     *  \param alloc an allocator for all internal dynamic memory requirements
     *  \uptrace{SWS_REST_02194}
     */
    Router(std::initializer_list<Route>, Allocator* = GetDefaultAllocator());

    /** \brief Request handler function
     *
     *  This function serves as the user-defined request handler function passed to Server
     *
     *  \param req a request
     *  \param rep a reply
     *  \uptrace{SWS_REST_02195}
     */
    void operator()(const ServerRequest&, ServerReply&) const;

    // We also need iterator variants

    /** \brief Inserts a route into the set of potential matches
     *
     *  If a route already exists nothing is inserted.
     *
     *  \param route a route
     *  \return a reference to this
     *  \uptrace{SWS_REST_02196}
     */
    Router& InsertRoute(const Route&);  // returns Router& (!)

    /** \brief Constructs a route in-place
     *  Similar to Insert except that the route is constructed in-place. The given
     *  arguments are forwarded to the internal Route. If such a route already exists
     *  nothing is inserted.
     *  \param met a set of request methods
     *  \param pat a URI Pattern
     *  \param hdl a user-defined routing handler
     *  \return a reference to this
     *  \uptrace{SWS_REST_02197}
     */
    Router& EmplaceRoute(RequestMethod met, Pattern pat, const Function<RouteHandlerType>& hdl);

    /** \brief Enables a user to set a default request handler
     * The given handler is called if none of the routes matched of it at least once of the routes
     * called Route::Default().
     * \param hdl a user-defined request handler
     * \return a reference to this.
     * \uptrace{SWS_REST_02198}
     */
    Router& SetDefaultHandler(const Function<RequestHandlerType>& hdl);

    // optionals
    /** \brief Returns the number of routes
     *
     *  Returns the number of specified routes, exclusive of the default route.
     *
     *  \return the number of user-defined routes
     *  \uptrace{SWS_REST_02199}
     */
    std::size_t RouteCount();
    /** \brief Provides direc access to the set of routes
     *
     *  \return an iterator range of routes
     *  \uptrace{SWS_REST_02200}
     */
    RouteRange Routes();
    /** \brief Provides direc access to the set of routes
     *
     *  \return an iterator range of routes
     *  \uptrace{SWS_REST_02201}
     */
    ConstRouteRange Routes() const;
    /** \brief Removes a route from the set
     * \uptrace{SWS_REST_02202}
     */
    void RemoveRoute(RouteRange::Iterator);
    /** \brief Searches for a given route
     *
     *  \param route route to search for
     *  \return an iterator to the route if it exists in the set or Routes.end() if no such route was found.
     *  \uptrace{SWS_REST_02203}
     */
    RouteRange::Iterator FindRoute(const Route& route);
    /**
     * Remove a route
     * \param route the Route instance to be removed
     * \return true if success otherwise false.
     */
    bool RemoveRoute(Route& route);

    /** \brief Removes all routes
     * \uptrace{SWS_REST_02204}
     */
    void Clear();

    /**
     * \brief The preallocated memory for routes_ to prevent reallocations.
     */
    static constexpr int kReservedRouteMemory = 10;

private:
    /**
     * \brief Does a Route match with the ServerRequest
     * \param route
     * \param req
     * \returns True if match otherwise false
     */
    bool Match(const Route& route, const ServerRequest& req) const;

    /**
     * \brief The routes of the Router
     */
    std::vector<Route> routes_;

    /**
     * \brief The default request handler function.
     */
    Function<RequestHandlerType> handler_default_;
};

}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_ROUTING_ROUTER_H_
