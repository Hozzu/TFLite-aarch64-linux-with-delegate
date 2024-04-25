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

#ifndef ARA_COM_E2E_CHECKER04_H
#define ARA_COM_E2E_CHECKER04_H

#include <ara/com/e2e/profile_04.h>
#include <ara/com/e2e/checker_interface.h>

#include <cstdint>
#include <mutex>

namespace ara
{

namespace com
{

namespace profile
{

namespace profile04
{
/// @brief Checker class for E2E Profile 04
class Checker final : public ara::com::profile::profile_interface::CheckerInterface
{
public:
    /// @brief Creates checker instance
    ///
    /// @param config Configuration of Profile 04
    explicit Checker(Config config);
    ~Checker() noexcept override = default;

    Checker() = delete;
    Checker(const Checker& oth) = delete;
    Checker(Checker&& oth) noexcept = delete;
    Checker& operator=(const Checker& oth) = delete;
    Checker& operator=(Checker&& oth) noexcept = delete;

    void Check(const apd::crc::Buffer& buffer,
        com::e2e::ProfileCheckStatus& genericProfileCheckStatus) noexcept override;
    uint32_t GetHeaderLength() const noexcept override
    {
        return Profile04::headerLength;
    }
    uint32_t GetHeaderOffset() const noexcept override
    {
        return config.headerOffset;
    }

private:
    uint16_t ReadLength(const apd::crc::Buffer& buffer) const noexcept;
    uint16_t ReadCounter(const apd::crc::Buffer& buffer) const noexcept;
    uint32_t ReaddataId(const apd::crc::Buffer& buffer) const noexcept;
    uint32_t ReadCrc(const apd::crc::Buffer& buffer) const noexcept;

    ProfileCheckStatus DoChecks(uint16_t length,
        uint16_t receivedLength,
        uint16_t counter,
        uint16_t receivedCounter,
        uint32_t dataId,
        uint32_t receivedDataId,
        uint32_t computedCRC,
        uint32_t receivedCRC) noexcept;

    ProfileCheckStatus CheckCounter(uint16_t receivedCounter, uint16_t currentCounter) noexcept;

    const Config config;
    uint16_t counter;
    std::mutex checkMutex;
};

}  // namespace profile04
}  // namespace profile
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_E2E_CHECKER04_H
