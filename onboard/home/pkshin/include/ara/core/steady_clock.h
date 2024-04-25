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

#ifndef APD_ARA_CORE_STEADY_CLOCK_H_
#define APD_ARA_CORE_STEADY_CLOCK_H_

#include <chrono>
#include <cstdint>

namespace ara
{
namespace core
{

/// @brief This clock represents a monotonic clock.
///
/// The time points of this clock cannot decrease as physical time moves forward and the time between ticks of this
/// clock is constant.
///
/// @uptrace{SWS_CORE_06401, e84c48ee40fa9ee371ee1030b7f81a428c17c4c2}
/// @uptrace{SWS_CORE_11800, a4a7bece7b845c908574c73edd9276eff6436074}
class SteadyClock final
{
public:
    /// @uptrace{SWS_CORE_06412, 50842aec732ef6f6f488612fb56c4392937ea2f9}
    using rep = std::int64_t;

    /// @uptrace{SWS_CORE_06413, 3e95ad14f5a8ae1e28cce96f28ab175395d63a98}
    using period = std::nano;

    /// @uptrace{SWS_CORE_06411, 1d035bf3175f8fc406b00f248c939b4618ed868d}
    using duration = std::chrono::duration<rep, period>;

    /// @uptrace{SWS_CORE_06414, 56df2f14430ee2448a9facdb2488ff929d2ca0a5}
    using time_point = std::chrono::time_point<SteadyClock, duration>;

    /// @uptrace{SWS_CORE_06431, a468673f8003135e0c6f6066669213e98b991c6f}
    static constexpr bool is_steady = true;

    /// @uptrace{SWS_CORE_06432, 0746ae8c90ad739983a0a215f4c8eb4424f5c04d}
    /// @uptrace{SWS_CORE_11801, f4d4b59fbce736e1e484d886f46dfc1b801ec5fc}
    static time_point now() noexcept
    {
        duration dur(std::chrono::steady_clock::now().time_since_epoch());
        time_point tp(dur);
        return tp;
    }
};

}  // namespace core
}  // namespace ara

#endif  // APD_ARA_CORE_STEADY_CLOCK_H_
