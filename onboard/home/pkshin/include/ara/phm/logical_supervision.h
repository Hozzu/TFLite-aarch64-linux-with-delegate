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

#ifndef ARA_PHM_LOGICAL_SUPERVISION_H_
#define ARA_PHM_LOGICAL_SUPERVISION_H_

#include "ara/core/map.h"
#include <set>
#include "ara/core/vector.h"
#include "ara/phm/local_supervision.h"

// non-generated code
namespace ara
{
namespace phm
{

class LogicalSupervision : public LocalSupervision
{
public:
    /// @brief initialization of logical supervision
    /// supervision graph initially inactive
    ///
    /// @uptrace{ASWS_HM_00296, 9f9a32bee6bc715e3bd0fa254fb5d0434c4704c8}
    LogicalSupervision(ara::log::Logger& logger,
        const ara::core::Vector<SupervisionCheckpoint>& initialCheckpoints,
        const ara::core::Vector<SupervisionCheckpoint>& finalCheckpoints,
        const ara::core::Vector<std::pair<SupervisionCheckpoint, SupervisionCheckpoint> >& transitions);

    virtual ~LogicalSupervision();

    /// @brief set supervision result to correct or incorrect
    ///
    /// @uptrace{ASWS_HM_00252, f090187bcf8c2184dc3192e342885b65c411d151}
    /// @uptrace{ASWS_HM_00331, 2901a87895d765e0966d85869cdb820178ce876c}
    /// @uptrace{ASWS_HM_00297, 3ae49083c76214a8507fcf601def22db9766c6e3}
    /// @uptrace{ASWS_HM_00273, ac45e7cc93d05552a931c7fe08801178fd31ab9f}
    bool NextCheckpointReached(const SupervisionCheckpoint& checkpoint, const ProcessId pid) override;

    /// @brief   activity status of supervision graph
    /// (currently only one graph per logical supervision)
    ///
    /// @uptrace{ASWS_HM_00271, 2176aceae4f35e0297047608d698ba61391f98e6}
    bool GetGraphActivityStatus() const
    {
        return supervisionActive_;
    }

private:
    enum class CheckpointTransitionState : std::uint32_t
    {
        NOT_IN_GRAPH,  // not found in supervision graph

        INACTIVE_INITIAL,  // start supervision with initial checkpoint
        INACTIVE_INCORRECT,  // non-initial checkpoint on supervision start

        ACTIVE_INVALID,  // checkpoint found, but no transition with this target
        ACTIVE_VALID,  // valid transition with this target
        ACTIVE_FINAL  // valid transition to final checkpoint
    };

    /// @brief check transition from previous checkpoint to new checkpoint
    ///
    /// @uptrace{ASWS_HM_00252, f090187bcf8c2184dc3192e342885b65c411d151}
    CheckpointTransitionState GetCheckpointTransitionState(const SupervisionCheckpoint& checkpoint);

    bool supervisionActive_ = false;
    const std::set<SupervisionCheckpoint> initialCheckpoints_;
    const std::set<SupervisionCheckpoint> finalCheckpoints_;
    // proposal: store a set containing transition hashes
    // 1) init: hash(pair<source, target>)
    // 2) transition: hash and check if the hash exists -> valid transition
    const std::multimap<SupervisionCheckpoint, SupervisionCheckpoint> transitions_;
    SupervisionCheckpoint currentCheckpoint_;
};

}  // namespace phm
}  // namespace ara

#endif  // ARA_PHM_LOGICAL_SUPERVISION_H_
