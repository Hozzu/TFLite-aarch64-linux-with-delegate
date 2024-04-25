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

#ifndef ARA_PHM_ALIVE_SUPERVISION_H_
#define ARA_PHM_ALIVE_SUPERVISION_H_

#include "ara/phm/temporal_supervision.h"

// non-generated code
namespace ara
{
namespace phm
{

// TODO ASWS_HM_00083: supervision modes
class AliveSupervision : public TemporalSupervision
{
public:
    AliveSupervision(ara::log::Logger& logger,
        DurationMillis aliveReferenceCycle,
        std::uint32_t expectedAliveIndications,
        std::uint32_t maxMargin,
        std::uint32_t minMargin,
        SupervisionCheckpoint checkpoint);

    bool IsNewInstance(const ProcessId pid);

    virtual ~AliveSupervision();

    /// @brief   count for alive indications (only configured checkpoint)
    ///
    /// @uptrace{ASWS_HM_00074, d2a413d90c88a55827bd267f4a16122e1215c559}
    bool NextCheckpointReached(const SupervisionCheckpoint& checkpoint, const ProcessId pid) override;

    void StartSupervision();

    // it might be desireable to supervise finite loops
    void StopSupervision();

    std::uint32_t GetAliveSupervisionCycles() const
    {
        return cyclesCounter_;
    }

protected:
    /// @brief   timer callback after aliveReferenceCycle expired
    ///
    /// @uptrace{ASWS_HM_00098, b345b95b50b6140d5a5b7da31de9993a3f5c630a}
    /// @uptrace{ASWS_HM_00074, d2a413d90c88a55827bd267f4a16122e1215c559}
    void TimerHandler(const boost::system::error_code& error) override;

private:
    const DurationMillis aliveReferenceCycle_;
    const std::uint32_t expectedAliveIndications_;
    const std::uint32_t maxMargin_;
    const std::uint32_t minMargin_;
    const SupervisionCheckpoint checkpoint_;
    std::uint32_t cyclesCounter_;
};

}  // namespace phm
}  // namespace ara

#endif  // ARA_PHM_ALIVE_SUPERVISION_H_
