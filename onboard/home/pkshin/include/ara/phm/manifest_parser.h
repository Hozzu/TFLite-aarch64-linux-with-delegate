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

#ifndef ARA_PHM_MANIFEST_PARSER_H_
#define ARA_PHM_MANIFEST_PARSER_H_

#include <chrono>
#include "ara/core/map.h"
#include "ara/core/string.h"
#include "ara/core/vector.h"
#include "ara/phm/types.h"
#include "ara/log/logger.h"
#include "apd/manifestreader/manifest_reader.h"

namespace ara
{
namespace phm
{

/* LocalSupervisionIdentifier */
struct LocalSupervisionIdentifier
{
    using ShortName = std::uint32_t;
    LocalSupervisionType supervisionType_;
    ShortName shortName_;

    LocalSupervisionIdentifier()
    { }

    LocalSupervisionIdentifier(LocalSupervisionType supervisionType, ShortName shortName)
        : supervisionType_{supervisionType}
        , shortName_{shortName}
    { }

    bool operator==(const LocalSupervisionIdentifier& o) const
    {
        return supervisionType_ == o.supervisionType_ && shortName_ == o.shortName_;
    }
    bool operator<(const LocalSupervisionIdentifier& o) const
    {
        return supervisionType_ < o.supervisionType_
            || (supervisionType_ == o.supervisionType_ && shortName_ < o.shortName_);
    }
};

/*	AliveSupervisionData */
struct AliveSupervisionData
{
    LocalSupervisionIdentifier identifier_;
    std::chrono::milliseconds referenceCycle_;
    std::uint32_t expectedIndications_;
    std::uint32_t maxMargin_;
    std::uint32_t minMargin_;
    SupervisionCheckpoint checkpoint_;
};

struct DeadlineSupervisionData
{
    LocalSupervisionIdentifier identifier_;
    std::chrono::milliseconds maxTime_;
    std::chrono::milliseconds minTime_;
    SupervisionCheckpoint source_;
    SupervisionCheckpoint target_;
};

struct LogicalSupervisionData
{
    LocalSupervisionIdentifier identifier_;
    ara::core::Vector<SupervisionCheckpoint> initialCheckpoints_;
    ara::core::Vector<SupervisionCheckpoint> finalCheckpoints_;
    ara::core::Vector<std::pair<SupervisionCheckpoint, SupervisionCheckpoint>> transitions_;
};

/* Below structures are added to parse the related container from json file */
struct SupervisionCheckpointStruct
{
    ara::core::String shortName;
    ara::core::String supervisedEntityId;
    ara::core::String prototypeId;
    ara::core::String checkpointId;
};

struct AliveSupervisionStruct
{
    ara::core::String shortName;
    ara::core::String checkpointName;
    std::uint32_t expectedAliveIndications;
    std::uint32_t maxMargin;
    std::uint32_t minMargin;
    std::uint32_t aliveReferenceCycle;
};

struct DeadlinelinSupervisionStruct
{
    ara::core::String shortName;
    ara::core::Vector<ara::core::String> checkpointTransition;
    std::uint32_t maxDeadline;
    std::uint32_t minDeadline;
};

struct TransitionStruct
{
    ara::core::String shortName;
    ara::core::String sourceCheckpoint;
    ara::core::String targetCheckpoint;
};

struct LogicalSupervisionStruct
{
    ara::core::String shortName;
    ara::core::Vector<ara::core::String> initialCheckpoint;
    ara::core::Vector<ara::core::String> finalCheckpoint;
    ara::core::Vector<TransitionStruct> transition;
};

struct LocalSupervisionStruct
{
    ara::core::String shortName;
    std::uint32_t failedSupervisionCyclesTolerance;
    ara::core::Vector<ara::core::String> aliveSupervision;
    ara::core::Vector<ara::core::String> deadlineSupervision;
    ara::core::Vector<ara::core::String> logicalSupervision;
    ara::core::String supervisedEntityId;
};

struct GlobalSupervisionStruct
{
    ara::core::String shortName;
    std::uint32_t supervisionCycle;
    std::uint32_t expiredSupervisonCycleTolerance;
    ara::core::Vector<ara::core::String> localSupervision;
};

struct HealthChannelExternalStruct
{
    ara::core::String shortName;
    ara::core::String modeCondition;
    std::uint32_t status;
};

/**
 * @brief Parser represents an Application Manifest Parser
 *
 */
class ManifestParser
{
public:
    ManifestParser() = default;

    void DoParse(const char* file_name, ara::log::Logger& logger);

    ara::core::Vector<AliveSupervisionData>& GetAliveSupervisionData()
    {
        return alive_;
    }

    ara::core::Vector<DeadlineSupervisionData>& GetDeadlineSupervisionData()
    {
        return deadline_;
    }

    ara::core::Vector<LogicalSupervisionData>& GetLogicalSupervisionData()
    {
        return logical_;
    }

    ara::core::Map<ara::core::String, std::uint32_t>& GetLocalSupervisionTolerance()
    {
        return localSupervisionTolerance_;
    }

    std::uint32_t GetExpiredSupervisionTolerance()
    {
        return expiredSupervisionTolerance_;
    }

    std::uint32_t GetSupervisionCycle()
    {
        return supervisionCycle_;
    }

private:
    ara::core::Vector<AliveSupervisionData> alive_;
    ara::core::Vector<DeadlineSupervisionData> deadline_;
    ara::core::Vector<LogicalSupervisionData> logical_;
    ara::core::Map<ara::core::String, std::uint32_t> localSupervisionTolerance_;
    std::uint32_t expiredSupervisionTolerance_;
    std::uint32_t supervisionCycle_;
    ara::core::Map<ara::core::String, std::array<ara::core::String, 3>> supervisionCheckpointData_;

    void SupervisionCheckpointParsing(std::unique_ptr<apd::manifestreader::Manifest>&, ara::log::Logger&);
    void AliveSupervisionParsing(std::unique_ptr<apd::manifestreader::Manifest>&, ara::log::Logger&);
    void DeadlineSupervisionParsing(std::unique_ptr<apd::manifestreader::Manifest>&, ara::log::Logger&);
    void LogicalSupervisionParsing(std::unique_ptr<apd::manifestreader::Manifest>&, ara::log::Logger&);
    void LocalSupervisionParsing(std::unique_ptr<apd::manifestreader::Manifest>&, ara::log::Logger&);
    void GlobalSupervisionParsing(std::unique_ptr<apd::manifestreader::Manifest>&, ara::log::Logger&);
    void HealthChannelExternalParsing(std::unique_ptr<apd::manifestreader::Manifest>&, ara::log::Logger&);
};

} /* namespace phm */
} /* namespace ara */

#endif  // ARA_PHM_MANIFEST_PARSER_H_
