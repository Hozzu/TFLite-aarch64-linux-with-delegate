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

/// @file The DeterministicClient class provides the functionality for an Application
/// to run a deterministic environment.
#ifndef ARA_EXEC_DETERMINISTIC_CLIENT_H_
#define ARA_EXEC_DETERMINISTIC_CLIENT_H_

#include "ara/core/result.h"
#include "ara/core/steady_clock.h"
#include <cstdint>
#include <chrono>

namespace ara
{
namespace exec
{

///
/// @brief Defines the return codes for WaitForNextActivation operations. Scoped Enumeration of uint32_t.
///
/// @uptrace{SWS_EM_02201, 6e6fb0c238f5af1b902b64ab11f32046a904ba08}
///
enum class ActivationReturnType : std::uint32_t
{
    kRegisterServices = 0,  ///< application shall register communication services
                            ///< (this must be the only occasion for performing service registering)
    kServiceDiscovery = 1,  ///< application shall do communication service discovery
                            ///< (this must be the only occasion for performing service discovery)
    kInit = 2,  ///< application shall initialize its internal data structures (once)
    kRun = 3,  ///< application shall perform its normal operation
    kTerminate = 4,  ///< deterministic execution shall terminate
};

///
/// @brief Class to implement operations on Deterministic Client.
///
/// @uptrace{SWS_EM_02210}
///
class DeterministicClient final
{

public:
    /// @brief Time stamp of deterministic cycles
    ///
    /// @uptrace{SWS_EM_02203, 0d8c339348c98c4a705a3f2ea790bf3daf0b0554}
    using TimeStamp = std::chrono::time_point<ara::core::SteadyClock>;

    ///
    /// @brief Constructor for DeterministicClient which opens the Execution Management communication
    ///        channel (e.g. POSIX FIFO) to access a wait point for cyclic execution, a worker pool,
    ///        deterministic random numbers and time stamps.
    ///
    /// @uptrace{SWS_EM_02211, 5c4b1290d57420aefa749f65590b8f02ec498acc}
    ///
    DeterministicClient() noexcept;

    ///
    /// @brief Destructor of the Deterministic Client instance.
    ///
    /// @uptrace{SWS_EM_02215, ab7c44c64fc03a7b78253f8f7abc19ae2b939357}
    ///
    ~DeterministicClient() noexcept;

    ///
    /// @brief Blocks and returns with a process control value when the next activation is triggered by the
    ///        Runtime.
    ///
    /// @returns Process control value (or error)
    ///
    /// @error ara::exec::ExecErrc::kCycleOverrun The deterministic activation cycle time exceeded.
    ///
    /// @uptrace{SWS_EM_02217}
    /// @uptrace{SWS_EM_01301, 4cf55ef79da21d3bc271597d2d836d92a1cad769}
    ara::core::Result<ActivationReturnType> WaitForActivation() noexcept;

private:
    ActivationReturnType internalState_;
    int executedRunCycles_;
    int runCyclesToExecute_;
    const std::chrono::nanoseconds kInitCycleSleepTime_;
    const std::chrono::nanoseconds kRunCycleSleepTime_;
    void UpdateInternalState() noexcept;
    bool RemainInRunCycle() noexcept;
    void SleepUntilActivation();
};

}  // namespace exec
}  // namespace ara

#endif  // ARA_EXEC_DETERMINISTIC_CLIENT_H_
