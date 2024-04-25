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

#ifndef ARA_COM_E2E_PROFILE_INTERFACE_H
#define ARA_COM_E2E_PROFILE_INTERFACE_H

#include <cstdint>

namespace ara
{

namespace com
{

namespace profile
{

/// @brief Supported E2E profile types
enum class ProfileName : uint8_t
{
    PROFILE_01,
    PROFILE_02,
    PROFILE_04,
    PROFILE_05,
    PROFILE_06,
    PROFILE_07,
    PROFILE_11,
    PROFILE_22
};

namespace profile_interface
{

/// @brief Generic Interface of a profile
class ProfileInterface
{
public:
    /// @brief Default destructor
    virtual ~ProfileInterface() noexcept = default;
    /// @brief Returns offset of the E2E header
    ///
    /// @return offset of E2E header
    virtual uint32_t GetHeaderOffset() const noexcept = 0;
    /// @brief Returns E2E header length
    ///
    /// @return length of E2E header
    virtual uint32_t GetHeaderLength() const noexcept = 0;
};

}  // namespace profile_interface
}  // namespace profile
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_E2E_PROFILE_INTERFACE_H
