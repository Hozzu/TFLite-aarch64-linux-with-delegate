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

#ifndef LIB_APDREST_INCLUDE_APD_REST_ROUTING_MATCH_H_
#define LIB_APDREST_INCLUDE_APD_REST_ROUTING_MATCH_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include <stdexcept>
#include <type_traits>

#include "apd/rest/string.h"

namespace apd
{
namespace rest
{

/** \brief Represents the result of a pattern matching on a URI
 *
 * Matches are handles to the pattern matching results and also
 * provide an API for type conversion of such pattern. Pattern wildcard '*'
 * matches exactly one URI path segments while wildcard '**' matches any number of segments.
 * \uptrace{SWS_REST_02033}
 */
class Match
{
public:
    /**
     * \brief Constructor
     */
    explicit Match(const StringView& match)
        : match_(match)
    { }

    /** \brief Returns a path segment as a string
     *
     *  \return a string of the matches path segment
     *  \uptrace{SWS_REST_02034}
     */
    StringView Get() const noexcept(std::is_nothrow_constructible<StringView>::value)
    {
        return match_;
    }

    /** \brief Returns a type-converted path segment
     *
     *  Applies a type conversion on the matched path segment.
     *  If conversion fails, then std::invalid_argument is thrown.
     *
     *  \tparam T type to convert to. Type T must be input-streamble.
     *  \return
     */
    template <typename T>
    T GetAs()
    {
        T ret_val;
        ret_val << match_;
        if (ret_val.good()) {
            return ret_val;
        } else {
            throw std::invalid_argument("Conversion failed, missing operator<<");
        }
    }

    /** \brief Returns a type-converted path segment
     *
     *  Applies a type conversion on the matched path segment.
     *  If conversion fails the function argument is returned.
     *
     *  \tparam T type to convert to. Type T must be input-streamble.
     *  \param def if conversion fails,
     *  \return The converted value of conversion succeeded, otherwise it returns the function argument.
     *  \uptrace{SWS_REST_02035}
     */
    template <typename T>
    T GetAs(T&& def) noexcept
    {
        T ret_val;
        try {
            ret_val << match_;
        } catch (...) {  // nothing to do in here
        }

        if (ret_val.good()) {
            return ret_val;
        } else {
            return def;
        }
    }

private:
    /**
     * \brief The match
     */
    const StringView match_;
};

}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_ROUTING_MATCH_H_
