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

#ifndef ARA_PHM_HEALTH_CHANNEL_H_
#define ARA_PHM_HEALTH_CHANNEL_H_

#include <cstdint>
#include <type_traits>
#include "ara/phm/phm.h"

namespace ara
{
namespace phm
{

/// @brief   HealthChannel Class
///
/// @uptrace{SWS_PHM_01122, 63e1fca5341efe260616403611040cdc3fe0e39c}
template <typename EnumT>
class HealthChannel : public PHM
{
public:
    /// @brief   Creation of a HealthChannel
    ///
    /// @uptrace{SWS_PHM_00457, bef20aafbd6d84ae0967cd70abd316a990811d54}
    explicit HealthChannel(const ara::core::InstanceSpecifier& instance);

    /// @brief   The copy constructor for SupervisedEntity shall not be used
    ///
    /// @uptrace{SWS_PHM_01222, 4beaf0b7559986b3b97790d12e97e94696da1100}
    HealthChannel(const HealthChannel& channel) = delete;

    /// @brief   Move constructor for HealthChannel
    ///
    /// @uptrace{SWS_PHM_01224, 5025f4c56ff45291fd4fce1cbbe06b1f2a6e8912}
    HealthChannel(HealthChannel&& channel) noexcept = default;

    /// @brief   The copy assignment operator for HealthChannel shall not be used
    ///
    /// @uptrace{SWS_PHM_01223, 1c7dacad268b6c0cc88aaac7e5127b1585bb09f1}
    HealthChannel& operator=(const HealthChannel& channel) = delete;

    /// @brief   Move assignment operator for HealthChannel
    ///
    /// @uptrace{SWS_PHM_01225, ec2ed2122bd38861ed5536f310accb84a9d13b58}
    HealthChannel& operator=(HealthChannel&& channel) noexcept = default;

    /// @brief   Destructor of a HealthChannel
    ///
    /// @uptrace{SWS_PHM_01221, ed236990e21aa765fc1bbb1a4f37749452e7b2c7}
    ~HealthChannel() noexcept = default;

    /// @brief   ReportHealthStatus method declaration
    ///
    /// @uptrace{SWS_PHM_01128, 50cc18861242bacf9d3a8bbdcde98c28d4c49f7f}
    void ReportHealthStatus(EnumT healthStatusId) noexcept;
};

template <typename EnumT>
HealthChannel<EnumT>::HealthChannel(const ara::core::InstanceSpecifier& instance)
{
    PHM::HealthChannelInstance(instance);
}

template <typename EnumT>
void HealthChannel<EnumT>::ReportHealthStatus(EnumT healthStatusId) noexcept
{
    PHM::ReportCheckpoint(static_cast<std::uint32_t>(healthStatusId));
}

}  // namespace phm
}  // namespace ara

#endif  // ARA_PHM_HEALTH_CHANNEL_H_
