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

#ifndef ARA_PHM_DEADLINE_SUPERVISION_H_
#define ARA_PHM_DEADLINE_SUPERVISION_H_

#include "ara/phm/temporal_supervision.h"

// non-generated code
namespace ara
{
namespace phm
{

// TODO supervision modes
class DeadlineSupervision : public TemporalSupervision
{
public:
    DeadlineSupervision(ara::log::Logger& logger,
        DurationMillis maxDelay,
        DurationMillis minDelay,
        SupervisionCheckpoint sourceCheckpoint,
        SupervisionCheckpoint targetCheckpoint);

    virtual ~DeadlineSupervision();

    /// @brief   time difference between target and source checkpoint
    ///
    /// @uptrace{ASWS_HM_00294, 4014c0c9cd761f3e772bcb84124f3eaf2fe47bf1}
    /// @uptrace{ASWS_HM_00228, e34f9acc1bbd515ccadba809525214c3b50b09de}
    /// @uptrace{ASWS_HM_00229, 77b4cdc0f1ec2ac792932f02b61de492c40bf30d}
    /// @uptrace{ASWS_HM_00354, 9545bbfd0c5c2222beace9e7a13346c93ff919e3}
    /// @uptrace{ASWS_HM_00299, ab9249960f78eccc1f7489e74681ff012b7ac7df}
    bool NextCheckpointReached(const SupervisionCheckpoint& checkpoint, const ProcessId pid) override;

protected:
    /// @brief   expiry of MaxDeadline
    ///
    /// @uptrace{ASWS_HM_00294, 4014c0c9cd761f3e772bcb84124f3eaf2fe47bf1}
    void TimerHandler(const boost::system::error_code& error) override;

private:
    std::uint32_t supervisionActiveCounter_;
    const DurationMillis maxDelay_;
    const DurationMillis minDelay_;
    const SupervisionCheckpoint sourceCheckpoint_;
    const SupervisionCheckpoint targetCheckpoint_;
};

}  // namespace phm
}  // namespace ara

#endif  // ARA_PHM_DEADLINE_SUPERVISION_H_
