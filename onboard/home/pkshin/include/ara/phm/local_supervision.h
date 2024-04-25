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

#ifndef ARA_PHM_LOCAL_SUPERVISION_H_
#define ARA_PHM_LOCAL_SUPERVISION_H_

#include "ara/log/logger.h"

#include "ara/phm/types.h"

namespace ara
{
namespace phm
{

class LocalSupervision
{
public:
    enum class Status : std::uint32_t
    {
        CORRECT,
        INCORRECT
    };

    LocalSupervision() = delete;
    virtual ~LocalSupervision()
    { }

    /// @brief   GetLocalSupervisionStatus method definition
    ///
    /// intended call chain: SupervisedEntity -> PHM -> LocalSupervision
    Status GetSupervisionStatus() const
    {
        return supervisionStatus_;
    }

    /// @brief Reports a checkpoint to a local supervision
    ///
    /// I would prefer to use std::optional to return the supervision status
    /// if the checkpoint was relevant for the supervision
    /// but this is C++17
    ///
    /// @return false if the checkpoint was ignored
    virtual bool NextCheckpointReached(const SupervisionCheckpoint& checkpoint, const ProcessId pid) = 0;

    explicit LocalSupervision(ara::log::Logger& logger)
        : logger_{logger}
    { }

protected:
    ara::log::Logger& logger_;
    Status supervisionStatus_ = Status::CORRECT;
};

}  // namespace phm
}  // namespace ara

#endif  // ARA_PHM_LOCAL_SUPERVISION_H_
