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

#ifndef ARA_PHM_APPLICATION_RECOVERY_ACTION_H_
#define ARA_PHM_APPLICATION_RECOVERY_ACTION_H_
#include "ara/core/result.h"

namespace ara
{
namespace phm
{

class ApplicationRecoveryAction
{
public:
    ApplicationRecoveryAction() = default;

    /// @brief The copy constructor for ApplicationRecoveryAction.
    ApplicationRecoveryAction(const ApplicationRecoveryAction& other) = delete;

    /// @brief Move constructor for ApplicationRecoveryAction.
    ApplicationRecoveryAction(ApplicationRecoveryAction&& other) = default;

    /// @brief The copy assignment operator for ApplicationRecoveryAction.
    ApplicationRecoveryAction& operator=(const ApplicationRecoveryAction& other) = delete;

    /// @brief Move assignment operator for ApplicationRecoveryAction.
    ApplicationRecoveryAction& operator=(ApplicationRecoveryAction&& other) & = default;

    /// @brief ApplicationRecoveryAction constructor
    // explicit ApplicationRecoveryAction (ara::core::InstanceSpecifier const &instance); TODO

    virtual void RegisterHandler(const std::string& rHandler) = 0;

    /// @brief RecoveryHandler method definition
    void RecoveryHandler();

    /// @brief Offer method definition
    ara::core::Result<void> Offer();

    /// @brief StopOffer method definition
    void StopOffer();

    virtual ~ApplicationRecoveryAction() = default;
};

}  // namespace phm
}  // namespace ara

#endif  // ARA_PHM_APPLICATION_RECOVERY_ACTION_H_
