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

#ifndef ARA_COM_E2E_PROTECTOR05_H
#define ARA_COM_E2E_PROTECTOR05_H

#include <ara/com/e2e/profile_05.h>
#include <ara/com/e2e/protector_interface.h>
#include <mutex>

namespace ara
{

namespace com
{

namespace profile
{

namespace profile05
{

/// @brief Implementation of Protector Interface for E2E profile 05
class Protector final : public ara::com::profile::profile_interface::ProtectorInterface
{
public:
    Protector() = delete;

    /// @brief Creates Protector instance using given profile configuration
    ///
    /// @param config Profile configuration
    ///
    /// @uptrace{SWS_CM_90433, 129abc2d0d864fcbb8657d42025c018bd4f59d72}
    explicit Protector(Config config);
    ~Protector() noexcept override = default;

    Protector(const Protector& oth) = delete;
    Protector(Protector&& oth) noexcept = delete;
    Protector& operator=(const Protector& oth) = delete;
    Protector& operator=(Protector&& oth) noexcept = delete;

    void Protect(apd::crc::Buffer& buffer) override;

    uint32_t GetHeaderLength() const noexcept override
    {
        return Profile05::headerLength;
    }
    uint32_t GetHeaderOffset() const noexcept override
    {
        return config.offset;
    }

private:
    void WriteCounter(apd::crc::Buffer& buffer, uint8_t currentCounter) noexcept;
    void WriteCrc(apd::crc::Buffer& buffer, uint16_t computedCRC) noexcept;
    void IncrementCounter() noexcept;

private:
    const Config config;
    uint8_t counter;
    std::mutex protectMutex;
};

}  // namespace profile05
}  // namespace profile
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_E2E_PROTECTOR05_H
