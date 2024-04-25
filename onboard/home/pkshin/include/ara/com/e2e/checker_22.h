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

#ifndef ARA_COM_E2E_CHECKER22_H
#define ARA_COM_E2E_CHECKER22_H

#include <ara/com/e2e/profile_22.h>
#include <ara/com/e2e/checker_interface.h>
#include <mutex>

namespace ara
{

namespace com
{

namespace profile
{

namespace profile22
{

/// @brief Checker class for E2E Profile 22
class Checker final : public ara::com::profile::profile_interface::CheckerInterface
{
public:
    Checker() = delete;

    /// @brief Creates checker instance
    ///
    /// @param config Configuration of Profile 22
    explicit Checker(Config config);
    Checker(const Checker&) = delete;
    Checker(Checker&&) noexcept = delete;
    Checker& operator=(const Checker&) = delete;
    Checker& operator=(Checker&&) noexcept = delete;
    ~Checker() noexcept override = default;

    void Check(const apd::crc::Buffer& buffer,
        com::e2e::ProfileCheckStatus& genericProfileCheckStatus) noexcept override;

    uint32_t GetHeaderLength() const noexcept override
    {
        return Profile22::headerLength;
    }
    uint32_t GetHeaderOffset() const noexcept override
    {
        return 0U;
    }

private:
    uint8_t ReadCounter(const apd::crc::Buffer& buffer) const noexcept;
    uint8_t ReadCrc(const apd::crc::Buffer& buffer) const noexcept;

    ProfileCheckStatus DoChecks(uint8_t currentCounter,
        uint8_t receivedCounter,
        uint8_t computedCrc,
        uint8_t receivedCrc) const;

    uint8_t CalculateCounterDelta(uint8_t receivedCounter, uint8_t currentCounter) const noexcept;

    const Config config;
    uint8_t counter : 4;
    std::mutex checkMutex;
};

}  // namespace profile22
}  // namespace profile
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_E2E_CHECKER22_H
