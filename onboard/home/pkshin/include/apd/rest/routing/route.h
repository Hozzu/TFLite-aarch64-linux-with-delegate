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

#ifndef LIB_APDREST_INCLUDE_APD_REST_ROUTING_ROUTE_H_
#define LIB_APDREST_INCLUDE_APD_REST_ROUTING_ROUTE_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include <gtest/gtest.h>
#include <functional>
#include <initializer_list>

#include "apd/rest/allocator.h"
#include "apd/rest/iterator.h"
#include "apd/rest/routing/match.h"
#include "apd/rest/routing/pattern.h"
#include "apd/rest/server.h"
#include "apd/rest/types.h"

namespace apd
{
namespace rest
{

/** \brief Represents a URI route
 *
 * A route is a conditional mapping from a pair of RequestMethod and URI to a user-defined handler
 * function.  A given request is matched against a pattern, if it matches a user-defined handler
 * function is called. In addition to the usual pair of Request and Replay objects the user-defined
 * handler is passed the matching Route itself to enable processing of pattern matches.
 *
 * Routes also define a partial order for route machting. Both RequestMethod and Pattern order
 * must be taken into consideration. Similar to Pattern lexicographic order appplies.
 * A route A compares less-than to a route B (A < B) if and only if RequestMethod compares less-than.
 * Otherwise A < B if and only if Pattern of A compares less-than Pattern of B.
 *
 * RequestMethod S compares less-then RequestMethod T (S < T) according to the following rules:
 * Conceptually, the order of request methods is lexicographic with each enumerator representing a character of a
 * string concatenated by operator '|'. Therefore, for single "digits" it holds that kGET < kPOST < .. etc according to
 * their underlying numeric values. For multiple "digits" it holds that - for example -
 * kGET < kGET|kPOST < kGET|kPUT < ... < kAny. But note that kGET|kPUT == kPUT|kGET.
 * In words, the most precise specifiers (singleton request methods) have precedence over the less precise
 * specificiation over sets of enumerators.
 *
 * Note that also request methods and Uri Pattern also form a lexicographical order with Uri being
 * the "most significant digit" and request method the "least significant digit" of a two-character string.
 * For example "/foo/bar" GET < "/foo/bar" POST|GET.
 * \uptrace{SWS_REST_02205}
 */
class Route
{
public:
    /**! friend declaration for test */
    FRIEND_TEST(Route, Test);

    /** \brief Instructions for a Router on how to proceed after a route handler functions returns
     *  A route handler function must return one of these values to instruct the router how to
     *  proceed after executing the current handler. The values have the following semantics:
     *  - Accept: Router shall not search for further matches
     *  - Yield: Router shall select the next matching route
     *  - Default: Router shall execute its default handler function
     * \uptrace{SWS_REST_02206}
     */
    enum class Upshot
    {
        Accept,  ///< Finish matching. No further actions
        Yield,  ///< Search for next matching route and execute its handler
        Default  ///< Finish matching and instantly execute the default request handler.
    };

    /**
     * \brief The type of the user-define handler function to be invoked if this Route matches the Pattern
     * \uptrace{SWS_REST_02207}
     */
    using RouteHandlerType = Upshot(const Route&, const ServerRequest&, ServerReply&);

    /**
     * \brief An IteratorRange of all pattern matches for this Route
     */
    using MatchRange = IteratorRange<unspecified_iterator_type>;

    /** \brief Constructs a route
     *
     *  For details see detailed description of Route.
     *
     *  \param met a disjunction (logical OR) of RequestMethods to match against
     *  \param pattern a URI Pattern to match against
     *  \param handler a user-defined handler
     *  \uptrace{SWS_REST_02208}
     */
    Route(RequestMethod met, const Pattern& pattern, const Function<RouteHandlerType>& handler);

    /** \brief apd::rest::Server compliant handler function
     *
     *  This function is invoked by the Router to test the current Route for a match
     *
     * \param req a request
     * \param rep a reply
     * \return the upshot value
     * \uptrace{SWS_REST_02209}
     */
    Upshot operator()(const ServerRequest& req, ServerReply& rep) const noexcept;

    /**
     * \brief Compare two routes on equalness.
     * \param left
     * \param right
     * \uptrace{SWS_REST_02212}
     */
    friend bool operator==(const Route& left, const Route& right)
    {
        return ((left.GetPattern() == right.GetPattern()) && (left.GetMethod() == right.GetMethod()));
    }

    /**
     * \brief Compare two routes for diversity.
     * \param left
     * \param right
     * \uptrace{SWS_REST_02213}
     */
    friend bool operator!=(const Route& left, const Route& right)
    {
        return !(left == right);
    }

    /** \brief Provides access to the underlying Pattern object
     *
     *  \return reference to a Pattern
     *  \uptrace{SWS_REST_02211}
     */
    const Pattern& GetPattern() const;

    /**
     * \brief Get the Request Method.
     * \uptrace{SWS_REST_02210}
     */
    RequestMethod GetMethod() const
    {
        return request_method_;
    }

    /** \brief Provides the number of URI wildcard matches after applying a pattern to a route
     *
     *  After the router matched a given Request against this Route, then this
     *  function returns the number of (wildcard) matches.
     *  \return the number of URI matches
     */
    std::size_t MatchCount() const;

    /** \brief Provides access to a specific URI match
     *
     *  \param i index to the i'th URI wildcard match
     *  \return return type
     */
    Match GetMatch(std::size_t i) const;

    /** \brief Provides access to the sequence of URI (wildcard) matches
     *
     *  After this route has been matched against a given request, all wildcard URI matches
     *  are accessible with this range.
     *
     *  \return a range of URI matches
     */
    MatchRange Matches() const;

private:
    /**
     * The user defined request handler.
     */
    Function<RouteHandlerType> handler_;

    /**
     * The requested method type for this route.
     */
    RequestMethod request_method_;

    /**
     * The URI Pattern to match against
     */
    Pattern pattern_;
};

}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_ROUTING_ROUTE_H_
