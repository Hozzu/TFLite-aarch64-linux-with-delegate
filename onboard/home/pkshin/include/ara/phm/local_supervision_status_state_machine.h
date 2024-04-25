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

#ifndef ARA_PHM_LOCAL_SUPERVISION_STATUS_STATE_MACHINE_H_
#define ARA_PHM_LOCAL_SUPERVISION_STATUS_STATE_MACHINE_H_

#include "ara/phm/local_supervision_status.h"
#include "ara/phm/types.h"

#include "ara/phm/local_supervision.h"

namespace ara
{
namespace phm
{

class LocalSupervisionStatusStateMachine
{
public:
    /// @brief initializes state machine for local supervision status
    LocalSupervisionStatusStateMachine(InterfaceType supervisedEntityId,
        std::uint32_t failedSupervisionCyclesTolerance);

    LocalSupervisionStatus GetLocalSupervisionStatus() const
    {
        return status_;
    }

    std::uint32_t GetFailedSupervisionReferenceCycles() const
    {
        return failedSupervisionReferenceCycles_;
    }

    /// @brief pushes new supervision result to update status
    /// out of bounds is only required to specify whether alive supervision exceeds the tolerance value
    ///
    /// @return new status
    LocalSupervisionStatus UpdateLocalSupervisionStatus(LocalSupervisionType type, LocalSupervision::Status status);

private:
    /// @brief updates local supervision status according to previously set supervision results
    void StateMachineUpdate();

    /// @brief resets counters on state change
    /// TODO discuss when to reset the counters
    /// reset is necessary because the requirement state e.g. "all the results are correct"
    /// if we didn't reset, this would never happen after the first incorrect result
    /// result: stuck in state EXPIRED
    void ResetSupervisionResultCounters();

    InterfaceType supervisedEntityId_;
    std::uint32_t failedSupervisionCyclesTolerance_;

    LocalSupervisionStatus status_;
    std::uint32_t failedSupervisionReferenceCycles_;

    std::uint32_t aliveCorrect_;
    std::uint32_t aliveIncorrect_;

    std::uint32_t deadlineCorrect_;
    std::uint32_t deadlineIncorrect_;

    std::uint32_t logicalCorrect_;
    std::uint32_t logicalIncorrect_;
};

}  // namespace phm
}  // namespace ara

#endif  // ARA_PHM_LOCAL_SUPERVISION_STATUS_STATE_MACHINE_H_
