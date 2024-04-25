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

#ifndef ARA_PHM_SUPERVISED_ENTITY_H_
#define ARA_PHM_SUPERVISED_ENTITY_H_

#include <cstdint>
#include <type_traits>
#include "ara/phm/phm.h"

namespace ara
{
namespace phm
{

/// @brief   SupervisedEntity Class Template
///
/// @uptrace{SWS_PHM_01132, d60137e6b7db4de6f75b7bc3617b3d8f131741b3}
template <typename EnumT>
class SupervisedEntity : public PHM
{
public:
    /// @brief   Creation of a SupervisedEntity
    ///
    /// @uptrace{SWS_PHM_01123, 6960d038e2baa04350925d50359f0ec1e1954a6d}
    explicit SupervisedEntity(const ara::core::InstanceSpecifier& instance);

    /// @brief   The copy constructor for SupervisedEntity shall not be used
    ///
    /// @uptrace{SWS_PHM_01212, 1192b2f2d70d47907ecb811880894452537c0e86}
    SupervisedEntity(const SupervisedEntity& se) = delete;

    /// @brief   Move constructor for SupervisedEntity
    ///
    /// @uptrace{SWS_PHM_01214, 1f21108f04d9a3a9bebf6cac43e8418c4d5d4ede}
    SupervisedEntity(SupervisedEntity&& se) noexcept = default;

    /// @brief   The copy assignment operator for SupervisedEntity shall not be used
    ///
    /// @uptrace{SWS_PHM_01213, 171c9fc69e9299df8d2d6e05317ffdcabd38e7ed}
    SupervisedEntity& operator=(const SupervisedEntity& se) = delete;

    /// @brief   Move assignment operator for SupervisedEntity
    ///
    /// @uptrace{SWS_PHM_01215, 4fed569f9f2cd19261b34059dd0924abbf1bb386}
    SupervisedEntity& operator=(SupervisedEntity&& se) noexcept = default;

    /// @brief   Destructor of a SupervisedEntity
    ///
    /// @uptrace{SWS_PHM_01211, fedec6a0678e090dada801cd0e68ae658802ff34}
    ~SupervisedEntity() noexcept = default;

    /// @brief   ReporyCheckpoint method declaration
    ///
    /// @uptrace{SWS_PHM_01127, 9e11b30c7d31bf920cdff0a28a24eceb8fa18c9c}
    void ReportCheckpoint(EnumT checkpointId) noexcept;
};

template <typename EnumT>
SupervisedEntity<EnumT>::SupervisedEntity(const ara::core::InstanceSpecifier& instance)
{
    PHM::SupervisedEntityInstance(instance);
}

template <typename EnumT>
void SupervisedEntity<EnumT>::ReportCheckpoint(EnumT checkpointId) noexcept
{
    PHM::ReportCheckpoint(static_cast<std::uint32_t>(checkpointId));
}
}  // namespace phm
}  // namespace ara

#endif  // ARA_PHM_SUPERVISED_ENTITY_H_
