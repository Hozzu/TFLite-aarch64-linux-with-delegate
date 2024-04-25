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

#ifndef ARA_PHM_TYPES_H_
#define ARA_PHM_TYPES_H_
#include "ara/core/string.h"

// non-generated code
namespace ara
{
namespace phm
{

using InterfaceType = ara::core::String;
using PrototypeType = ara::core::String;
using InstanceType = std::int32_t;
using Checkpoint = std::uint32_t;
using HealthStatus = std::uint32_t;
using ProcessId = std::uint32_t;

enum class LocalSupervisionType
{
    ALIVE,
    DEADLINE,
    LOGICAL
};

struct SupervisionCheckpoint
{
    InterfaceType supervisedEntityId_;
    PrototypeType prototypeId_;
    Checkpoint phmCheckpointId_;

    SupervisionCheckpoint(InterfaceType supervisedEntityId, PrototypeType prototypeId, Checkpoint phmCheckpointId)
        : supervisedEntityId_{supervisedEntityId}
        , prototypeId_(prototypeId)
        , phmCheckpointId_(phmCheckpointId)
    { }

    bool operator==(const SupervisionCheckpoint& o) const
    {
        return supervisedEntityId_ == o.supervisedEntityId_ && prototypeId_ == o.prototypeId_
            && phmCheckpointId_ == o.phmCheckpointId_;
    }
    bool operator<(const SupervisionCheckpoint& o) const
    {
        return supervisedEntityId_ < o.supervisedEntityId_
            || (supervisedEntityId_ == o.supervisedEntityId_ && prototypeId_ < o.prototypeId_)
            || (supervisedEntityId_ == o.supervisedEntityId_ && prototypeId_ == o.prototypeId_
                && phmCheckpointId_ < o.phmCheckpointId_);
    }
};

}  // namespace phm
}  // namespace ara

#endif  // ARA_PHM_TYPES_H_
