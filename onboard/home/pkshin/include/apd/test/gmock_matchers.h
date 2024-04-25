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

/// @file
/// @brief Useful matchers for GMock

#ifndef APD_TEST_GMOCK_MATCHERS_H_
#define APD_TEST_GMOCK_MATCHERS_H_

#include "gmock/gmock.h"

#include <string>
#include <cstddef>

namespace apd
{
namespace test
{

// Check whether an AUTOSAR ValueOrError or ValueOrNone type has no value.
MATCHER(ArNoValue, "has " + std::string(negation ? "a" : "no") + " value")
{
    if (arg.HasValue()) {
        *result_listener << "that has a value which is " << ::testing::PrintToString(arg.Value());
        return false;
    }

    *result_listener << "that has no value";

    return true;
}

// Check whether an AUTOSAR ValueOrError or ValueOrNone type has a value, and whether it is the expected one.
MATCHER_P(ArHasValue, expected,
        "has " + std::string(negation ? "no" : "a") + " value "
        "which is " + ::testing::PrintToString(expected))
{
    if (!arg.HasValue()) {
        *result_listener << "that has no value";
        return false;
    }

    *result_listener << "that has a value which is " << ::testing::PrintToString(arg.Value());

    return arg.Value() == expected;
}

}  // namespace test
}  // namespace apd

#endif  // APD_TEST_GMOCK_MATCHERS_H_
