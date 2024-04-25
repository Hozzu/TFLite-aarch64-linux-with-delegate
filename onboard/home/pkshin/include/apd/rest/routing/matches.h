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

#ifndef LIB_APDREST_INCLUDE_APD_REST_ROUTING_MATCHES_H_
#define LIB_APDREST_INCLUDE_APD_REST_ROUTING_MATCHES_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include <stdexcept>
#include <type_traits>
#include <vector>

#include "apd/rest/routing/match.h"
#include "apd/rest/routing/route.h"
#include "apd/rest/string.h"

namespace apd
{
namespace rest
{

/**
 * \brief Represents the result of a pattern matching on a URI
 * \uptrace{SWS_REST_02027}
 */
class Matches
{
public:
    /**
     * \brief type
     */
    using ValueType = Match;

    /**
     * \brief Container type
     */
    using ContainerType = std::vector<Match>;

    /**
     * \brief  iterator
     */
    using Iterator = ContainerType::iterator;

    /**
     * \brief constant iterator
     */
    using ConstIterator = ContainerType::const_iterator;

    /**
     * \brief An IteratorRange of all pattern matches for this Route
     * \uptrace{SWS_REST_02028}
     */
    using MatchRange = IteratorRange<Iterator>;

    /**
     * \brief A constant IteratorRange of all pattern matches for this Route
     */
    using ConstMatchRange = IteratorRange<ConstIterator>;

    /**
     * \brief Constructors
     *
     * \param route
     * \param uri_pattern .
     */
    Matches(Route& route, Pattern& uri_pattern);

    /** \brief Provides the number of URI wildcard matches after applying a pattern to a route
     *
     *  After the router matched a given Request against this Route, then this
     *  function returns the number of (wildcard) matches.
     *  \return the number of URI matches
     *  \uptrace{SWS_REST_02029}
     */
    std::size_t Count() const noexcept;

    /** \brief Provides access to a specific URI match
     *
     *  \param i index to the i'th URI wildcard match
     *  \return return type
     *  \uptrace{SWS_REST_02030}
     */
    const Match Get(std::size_t i) const noexcept;

    /** \brief Provides access to the sequence of URI (wildcard) matches
     *
     *  After this route has been matched against a given request, all wildcard URI matches
     *  are accessible with this range.
     *
     *  \return a range of URI matches
     *  \uptrace{SWS_REST_02031}
     */
    MatchRange Get() noexcept;

    /** \brief Provides access to the sequence of URI (wildcard) matches
     *
     *  After this route has been matched against a given request, all wildcard URI matches
     *  are accessible with this range.
     *
     *  \return a range of URI matches
     */
    ConstMatchRange Get() const noexcept;

    /** \brief prepares the wildcard matches list
     */
    void CreateWildCardList();

    /** \brief Returns the route currently matched
     *  \return a reference to the currently matched route
     */
    const Route& GetRoute() const noexcept;

private:
    /** \brief instance of route class
     */
    Route* route_;

    /** \brief instance of route class
     */
    ContainerType values_;

    /** \brief container to store route pattern
     */
    std::vector<StringView> route_pattern_;

    /** \brief container to store uri pattern
     */
    std::vector<StringView> uri_pattern_;

    /** \brief container to store wild card matches from route pattern
     */
    std::vector<apd::rest::Match> wildcard_matches_;
};

}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_ROUTING_MATCHES_H_
