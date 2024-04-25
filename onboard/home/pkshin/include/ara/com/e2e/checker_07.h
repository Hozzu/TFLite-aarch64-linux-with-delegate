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

#ifndef ARA_COM_E2E_CHECKER07_H
#define ARA_COM_E2E_CHECKER07_H

#include <ara/com/e2e/profile_07.h>
#include <ara/com/e2e/checker_interface.h>
#include <cstdint>
#include <mutex>

namespace ara
{

namespace com
{

namespace profile
{

namespace profile07
{

/// @brief Checker class for E2E Profile 07
class Checker final : public ara::com::profile::profile_interface::CheckerInterface
{
public:
    /// @brief Creates checker instance
    ///
    /// @param config Configuration of Profile 07
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
        return Profile07::headerLength;
    }
    uint32_t GetHeaderOffset() const noexcept override
    {
        return config.offset;
    }

private:
    uint32_t ReadLength(const apd::crc::Buffer& buffer) const noexcept;
    uint32_t ReadCounter(const apd::crc::Buffer& buffer) const noexcept;
    uint32_t ReadDataId(const apd::crc::Buffer& buffer) const noexcept;
    uint64_t ReadCrc(const apd::crc::Buffer& buffer) const noexcept;

    ProfileCheckStatus DoChecks(uint32_t length,
        uint32_t receivedLength,
        uint32_t counter,
        uint32_t receivedCounter,
        uint32_t dataId,
        uint32_t receivedDataId,
        uint64_t computedCRC,
        uint64_t receivedCRC) noexcept;

    ProfileCheckStatus CheckCounter(uint32_t receivedCounter, uint32_t currentCounter) noexcept;

    const Config config;
    uint32_t counter;
    std::mutex checkMutex;
};

}  // namespace profile07
}  // namespace profile
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_E2E_CHECKER07_H
