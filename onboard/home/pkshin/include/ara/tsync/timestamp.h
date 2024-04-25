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

#ifndef ARA_TSYNC_TIMESTAMP_H
#define ARA_TSYNC_TIMESTAMP_H

#include <chrono>
#include <cstdint>

namespace ara
{
namespace tsync
{

/// @brief The class TimeBase is a pseudo-clock.
///
/// The class TimeBase is a pseudo-clock that is used as the first template argument to std::chrono::time_point to
/// indicate that the time point represents local time with respect of a not-yet specified timeBaseResource.
/// @uptrace{SWS_TS_01260, 95336a57f0e2329c25dc1457fef7ef9849463764}
struct TimeBase
{
    /// @brief required type declaration to fulfill the C++ Clock requirements representing the number of ticks
    /// @uptrace{SWS_TS_01261, 45beeaa42505be8356b87a4669cd28681bd6ec25}
    using rep = std::int64_t;

    /// @brief required type declaration to fulfill the C++ Clock requirements representing the tick period the the
    /// duration.
    /// @uptrace{SWS_TS_01262, bc6057b40b75e4ee6b3c9045f4222e5d8e4f58b6}
    using period = std::nano;

    /// @brief required type declaration to fullfill the C++ Clock requirements used to measure the time since epoch
    /// @uptrace{SWS_TS_01263, 922189a4895559fd8c908b7440d56381d109c5fc}
    using duration = std::chrono::duration<rep, period>;

    /// @brief represents a point in time
    /// @uptrace{SWS_TS_01264, 73bff8856fbbf5eb1d8ed02897e6e3755e0d2726}
    using time_point = std::chrono::time_point<TimeBase>;

    /// @brief required constant to fullfill the C++ Clock requirements as steady clock
    /// @uptrace{SWS_TS_01265, 8d27aa499a5f40efc3502a74d0acdeac84975952}
    constexpr static bool is_steady = false;
};

/// @brief Standard timestamp type as alias of a generic time_point
/// @note Uptrace is not yet set as spec item is not implemented properly.
using Timestamp = std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds>;

}  // namespace tsync
}  // namespace ara

#endif  // ARA_TSYNC_TIMESTAMP_H
