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

#ifndef LIB_APDREST_INCLUDE_APD_REST_ROUTING_PATTERN_H_
#define LIB_APDREST_INCLUDE_APD_REST_ROUTING_PATTERN_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <vector>

#include "apd/rest/string.h"

namespace apd
{
namespace rest
{
namespace test
{
class PatternTestFixture_Test_Test; /**> forward declaration for testing */
}

/**
 * \brief The wildchard character for one segment.
 */
static constexpr char WILDCARD = '*';

/**
 * Order criteria:
 *   - lexicographical order with segments as digits (in left-to-right order)
 *     'car' < 'car/window'
 *   - then order: '**' < '*' < stuff
 *  \uptrace{SWS_REST_02159}
 */
class Pattern
{
public:
    friend class test::PatternTestFixture_Test_Test; /**> for testing */

    /**
     * \brief Constructor
     * \param pattern The pattern.
     * \uptrace{SWS_REST_02160}
     */
    explicit Pattern(StringView pattern)
        : pattern_()
    {
        pattern_.reserve(10);  // Reserve space for 10 segments
        std::stringstream buf(pattern);
        StringView segment;
        while (std::getline(buf, segment, '/')) {
            pattern_.push_back(std::move(segment));
        }
    }

    /**
     * \brief Lexicographical 'is equal' compare
     * \param left
     * \param right
     * \uptrace{SWS_REST_02161}
     */
    friend bool operator==(const Pattern& left, const Pattern& right)
    {
        bool equal{true};
        std::size_t i = 0;
        std::size_t j = 0;
        for (; i < left.pattern_.size(); i++) {
            // check if segments are equal
            if (i < left.pattern_.size() && j < right.pattern_.size()) {
                if ((left.pattern_.at(i).compare(right.pattern_.at(j))) != 0) {
                    if (left.pattern_.at(i).size() == 1 && left.pattern_.at(i).at(0) == WILDCARD) {
                        // single Wildcard left
                        // check if one of the patterns is at the end while another continues
                        if ((i + 1 >= left.pattern_.size() && j + 1 < right.pattern_.size())
                            || (j + 1 >= right.pattern_.size() && i + 1 < left.pattern_.size())) {
                            equal = false;
                            break;
                        }
                    } else if (left.pattern_.at(i).size() == 2 && left.pattern_.at(i).at(0) == WILDCARD
                        && left.pattern_.at(i).at(1) == WILDCARD) {
                        // double wildcard left
                        // check if left or right reached the last segment -> this leads to equal patterns
                        if ((!(j + 1 < right.pattern_.size())) || (!(i + 1 < left.pattern_.size()))) {
                            break;
                        } else {
                            // search next segment which is not equal to the double wildcard
                            while (i < left.pattern_.size() && left.pattern_.at(i).size() == 2
                                && left.pattern_.at(i).at(0) == WILDCARD && left.pattern_.at(i).at(1) == WILDCARD) {
                                i++;
                            }
                            // if the last segment of left is equal to the double wildcard left and right are equal
                            if (i >= left.pattern_.size()) {
                                i--;
                                break;
                            }
                            // serch next segment which isn't the double wildcard in the right pattern
                            while ((left.pattern_.at(i).compare(right.pattern_.at(j))) != 0) {
                                j++;
                                if (j >= right.pattern_.size()) {
                                    return false;
                                }
                            }
                        }
                    } else if (right.pattern_.at(i).size() == 1 && right.pattern_.at(i).at(0) == WILDCARD) {
                        // single Wildcard right
                        // check if one of left or right is at the end while another continues
                        if ((i + 1 >= left.pattern_.size() && j + 1 < right.pattern_.size())
                            || (j + 1 >= right.pattern_.size() && i + 1 < left.pattern_.size())) {
                            equal = false;
                            break;
                        }
                    } else if (right.pattern_.at(j).size() == 2 && right.pattern_.at(j).at(0) == WILDCARD
                        && right.pattern_.at(j).at(1) == WILDCARD) {
                        // double wildcard right
                        // check if left or right reached the last segment -> this leads to equal patterns
                        if ((!(j + 1 < right.pattern_.size())) || (!(i + 1 < left.pattern_.size()))) {
                            break;
                        } else {
                            // search next segment which is not equal to the double wildcard
                            while (j < right.pattern_.size() && right.pattern_.at(j).size() == 2
                                && right.pattern_.at(j).at(0) == WILDCARD && right.pattern_.at(j).at(1) == WILDCARD) {
                                j++;
                            }
                            // if the last segment of right is equal to the double wildcard left and right are equal
                            if (j >= right.pattern_.size()) {
                                j--;
                                break;
                            }
                            // search next segment which isn't the double wildcard in the left pattern
                            while ((left.pattern_.at(i).compare(right.pattern_.at(j))) != 0) {
                                i++;
                                if (i >= left.pattern_.size()) {
                                    return false;
                                }
                            }
                        }
                    } else {
                        // no wildcard leads to not equal
                        equal = false;
                        break;
                    }
                } else if ((left.pattern_.at(i).size() == 2 && left.pattern_.at(i).at(0) == WILDCARD
                               && left.pattern_.at(i).at(1) == WILDCARD)) {
                    // both contains an double wildcard at the same position
                    // check if both patterns are not at the last segment
                    //-> if one of them is at the end it leads to the result equal
                    if (left.pattern_.size() > i + 1 && right.pattern_.size() > j + 1) {
                        // check which pattern has more segments left -> if left loop through left and the other way
                        if (left.pattern_.size() - i > right.pattern_.size() - j) {
                            // search next segment which is not equal to the double wildcard
                            while (j < right.pattern_.size() && right.pattern_.at(j).size() == 2
                                && right.pattern_.at(j).at(0) == WILDCARD && right.pattern_.at(j).at(1) == WILDCARD) {
                                j++;
                            }
                            // if the last segment of right is equal to the double wildcard left and right are equal
                            if (j >= right.pattern_.size()) {
                                j--;
                                break;
                            }
                            // loop through the left pattern and search for the next equal segment
                            std::size_t x = i + 1;
                            for (; x < left.pattern_.size(); x++) {
                                if (right.pattern_.at(j).compare(left.pattern_.at(x)) == 0) {
                                    i = x;
                                    equal = true;
                                    break;
                                }
                                equal = false;
                            }
                        } else if (left.pattern_.size() - i < right.pattern_.size() - j) {
                            // search next segment which is not equal to the double wildcard
                            while (i < left.pattern_.size() && left.pattern_.at(i).size() == 2
                                && left.pattern_.at(i).at(0) == WILDCARD && left.pattern_.at(i).at(1) == WILDCARD) {
                                i++;
                            }
                            // if the last segment of left is equal to the double wildcard left and right are equal
                            if (i >= left.pattern_.size()) {
                                i--;
                                break;
                            }
                            std::size_t x = j + 1;
                            for (; x < right.pattern_.size(); x++) {
                                if (right.pattern_.at(x).compare(left.pattern_.at(i)) == 0) {
                                    j = x;
                                    equal = true;
                                    break;
                                }
                                equal = false;
                            }
                        }
                    } else {
                        return true;
                    }
                }
                j++;
            } else if (left.pattern_.size() > i && left.pattern_.at(i).compare(right.pattern_.at(j - 1)) != 0
                && (left.pattern_.at(i).size() < 2 || left.pattern_.at(i).at(0) != WILDCARD
                    || left.pattern_.at(i).at(1) != WILDCARD)) {
                equal = false;
                break;
            }
        }
        if (left.pattern_.size() <= i
            && (right.pattern_.size() > j
                && (right.pattern_.at(j).size() < 2 || right.pattern_.at(j).at(0) != WILDCARD
                    || right.pattern_.at(j).at(1) != WILDCARD))) {
            equal = false;
        }
        return equal;
    }

    /**
     * \brief Lexicographical 'is not equal' compare
     * \param left
     * \param right
     * \return
     * \uptrace{SWS_REST_02162}
     */
    friend bool operator!=(const Pattern& left, const Pattern& right)
    {
        return !(left == right);
    }

    /**
     * \brief Lexicographical 'is equal' compare
     * \param left
     * \param right
     * \return
     * \uptrace{SWS_REST_02163}
     */
    friend bool operator<(const Pattern& left, const Pattern& right)
    {
        std::size_t i = 0;
        std::size_t j = 0;
        for (; i < left.pattern_.size(); i++) {
            if (j >= right.pattern_.size()) {
                return false;
            }
            if (left.pattern_.at(i).compare(right.pattern_.at(j)) != 0) {
                if (left.pattern_.at(i).size() == 2 && left.pattern_.at(i).at(0) == WILDCARD
                    && left.pattern_.at(i).at(1) == WILDCARD) {
                    return true;
                } else if (left.pattern_.at(i).size() == 1 && left.pattern_.at(i).at(0) == WILDCARD) {
                    if (right.pattern_.at(j).size() == 2 && right.pattern_.at(j).at(0) == WILDCARD
                        && right.pattern_.at(j).at(1) == WILDCARD) {
                        return false;
                    } else {
                        return true;
                    }
                } else {
                    if (left.pattern_.at(i).compare(right.pattern_.at(j)) < 0) {
                        return true;
                    } else {
                        return false;
                    }
                }
            }
            j++;
        }
        if (left.pattern_.size() < right.pattern_.size()) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * \brief Function to get pattern
     *
     * \return pattern_string
     */
    const std::vector<StringView>& GetPatternString() const noexcept
    {
        return pattern_;
    }

private:
    /**
     * \brief Data of Pattern.
     */
    std::vector<StringView> pattern_;
};
}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_ROUTING_PATTERN_H_
