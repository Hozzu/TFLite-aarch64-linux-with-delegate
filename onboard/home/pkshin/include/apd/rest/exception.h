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

#ifndef LIB_APDREST_INCLUDE_APD_REST_EXCEPTION_H_
#define LIB_APDREST_INCLUDE_APD_REST_EXCEPTION_H_

#include <stdexcept>
#include <string>

namespace apd
{
namespace rest
{

/**
 * \brief Exception thrown when Uri format is invalid.
 */
class IllegalUriFormatException : std::runtime_error
{
public:
    /**
     * \brief Constructor.
     * \param what_arg explanatory string.
     */
    explicit IllegalUriFormatException(const std::string& what_arg)
        : std::runtime_error(what_arg)
    { }
    /**
     * \brief Constructor.
     * \param what_arg explanatory string.
     */
    explicit IllegalUriFormatException(const char* what_arg)
        : std::runtime_error(what_arg)
    { }
};

/** \brief Indicates a illegally formed UUID
 *
 *  This is typically thrown if a UUID in string format cannot be parsed.
 */
class IllformedUuidException : std::invalid_argument
{
public:
    /**
     * \brief Constructor.
     * \param what_arg explanatory string.
     */
    explicit IllformedUuidException(const std::string& what_arg)
        : std::invalid_argument(what_arg)
    { }
    /**
     * \brief Constructor.
     * \param what_arg explanatory string.
     */
    explicit IllformedUuidException(const char* what_arg)
        : std::invalid_argument(what_arg)
    { }
};

}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_EXCEPTION_H_
