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

#ifndef ARA_COM_E2E_PROTECTOR_INTERFACE_H
#define ARA_COM_E2E_PROTECTOR_INTERFACE_H

#include <apd/crc/buffer.h>
#include <ara/com/e2e/profile_interface.h>

namespace ara
{

namespace com
{

namespace profile
{

namespace profile_interface
{

/// @brief Interface of E2E protector
class ProtectorInterface : public ProfileInterface
{
public:
    /// @brief Default destructor
    ~ProtectorInterface() noexcept override = default;

    /// @brief Protect routine embed E2E header to given buffer
    ///
    /// @param buffer data to be protected
    virtual void Protect(apd::crc::Buffer& buffer) noexcept(false) = 0;
};

}  // namespace profile_interface
}  // namespace profile
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_E2E_PROTECTOR_INTERFACE_H
