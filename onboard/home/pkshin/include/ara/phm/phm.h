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

#ifndef ARA_PHM_PHM_H_
#define ARA_PHM_PHM_H_

#include "ara/log/logger.h"
#include "ara/core/map.h"
#include "ara/phm/types.h"
#include "ara/phm/local_supervision_status.h"
#include "ara/phm/local_supervision_status_state_machine.h"
#include "ara/phm/global_supervision_status.h"
#include "ara/phm/global_supervision_status_state_machine.h"

#include "ara/core/instance_specifier.h"
#include "ara/phm/local_supervision.h"
#include "ara/phm/alive_supervision.h"
#include "ara/phm/deadline_supervision.h"
#include "ara/phm/logical_supervision.h"
#include "ara/phm/manifest_parser.h"
#include "ara/phm/application_recovery_action.h"
#include "ara/phm/handler.h"

// non-generated code
namespace ara
{
namespace phm
{

class PHM
{
public:
    PHM();

    // created interface identifier enum for phm_wrapper and daemon code.
    enum Interface
    {
        registerHandler = 1,
        offer,
        stopOffer,
        instanceSpecifierSE,
        instanceSpecifierHC,
        reportCheckpoint,
        reportHealthStatus,
    };

    struct ProcessData
    {
        Interface processMethodId;
        char data[80];
        ProcessId pid;
        Checkpoint checkpointId;
    };

    // Interface to process InstanceSpecifier
    void SupervisedEntityInstance(const ara::core::InstanceSpecifier& instance);
    void HealthChannelInstance(const ara::core::InstanceSpecifier& instance);

    // Interface to process received ids.
    void ProcessCheckpoints(ProcessData readIds);
    void Run();

    ~PHM() = default;

    void ReportCheckpoint(Checkpoint checkpointId) noexcept;

    void ReportHealthStatus(HealthStatus healthStatusId) noexcept;

    ara::core::Result<LocalSupervisionStatus> GetLocalSupervisionStatus(
        ara::phm::InterfaceType const& supervisedEntityID) const;

    ara::core::Result<GlobalSupervisionStatus> GetGlobalSupervisionStatus() const;

private:
    ManifestParser parser_;
    Handler recObj_;

    ProcessId pid_;
    InterfaceType supervisedEntityId_;
    PrototypeType prototypeId_;
    InterfaceType healthChannelId_;

    ara::log::Logger& logger_ = ara::log::CreateLogger("PHM", "PHM context", ara::log::LogLevel::kVerbose);

    // shared map over all PHM instances
    // shared pointer to a LocalSupervision object
    // non-static causes a segmentation fault as PHM has to be copy constructible
    static ara::core::Map<LocalSupervisionIdentifier, std::shared_ptr<LocalSupervision> > localSupervisions_;

    // local supervision status of all supervised entities
    // supervisedEntityId -> supervisionStatus
    static ara::core::Map<InterfaceType, LocalSupervisionStatusStateMachine> localSupervisionStates_;

    // global supervision status of this software sub system
    static std::unique_ptr<GlobalSupervisionStatusStateMachine> globalSupervisionState_;
};

}  // namespace phm
}  // namespace ara

#endif  // ARA_PHM_PHM_H_
