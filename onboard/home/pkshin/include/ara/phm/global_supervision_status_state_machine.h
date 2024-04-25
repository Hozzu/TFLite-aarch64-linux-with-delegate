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

#ifndef ARA_PHM_GLOBAL_SUPERVISION_STATUS_STATE_MACHINE_H_
#define ARA_PHM_GLOBAL_SUPERVISION_STATUS_STATE_MACHINE_H_

#include "ara/phm/types.h"
#include "ara/core/result.h"
#include "ara/phm/global_supervision_status.h"

namespace ara
{
namespace phm
{

class GlobalSupervisionStatusStateMachine
{
public:
    // @brief initializes state machine for global supervision status
    GlobalSupervisionStatusStateMachine(std::uint32_t supervisionCycle,
        std::uint32_t expiredSupervisionCyclesTolerance);
    ara::core::Result<GlobalSupervisionStatus> UpdateGlobalSupervisionStatus(std::uint32_t localStatusCounterFAILED,
        std::uint32_t localStatusCounterEXPIRED);

private:
    void ResetExpiredSupervisionCycleCounter();
    std::uint32_t supervisionCycle_;
    std::uint32_t expiredSupervisionCyclesTolerance_;
    std::uint32_t expiredSupervisionCyclesCounter_;
    GlobalSupervisionStatus status_;
};

}  // namespace phm
}  // namespace ara

#endif  // ARA_PHM_GLOBAL_SUPERVISION_STATUS_STATE_MACHINE_H_
