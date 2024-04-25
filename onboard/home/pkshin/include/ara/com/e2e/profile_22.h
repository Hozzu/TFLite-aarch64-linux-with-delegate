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

#ifndef ARA_COM_E2E_PROFILE22_H
#define ARA_COM_E2E_PROFILE22_H

#include <cstdint>
#include "ara/core/array.h"
#include <apd/crc/buffer.h>

namespace ara
{

namespace com
{

namespace profile
{

namespace profile22
{

/// @brief Configuration of transmitted Data for E2E Profile 22
struct Config
{
    /// @brief A system-unique identifier of the Data
    uint16_t dataId;

    /// @brief An array of appropriately chosen Data IDs for protection against masquerading
    ara::core::Array<std::uint8_t, 16> dataIdList;

    /// @brief Length of Data, in bits
    uint16_t dataLength;

    /// @brief Maximum allowed gap between two counter values of two consecutively received valid Data
    uint8_t maxDeltaCounter;

    /// @brief Bit offset of the first bit of the E2E header from the beginning of the Data (bit numbering: bit 0 is the
    /// least important).
    uint16_t offset;

    Config() = delete;

    /// @brief Constructs configuration object for E2E profile from supplied parameters
    Config(uint16_t dataId,
        const ara::core::Array<std::uint8_t, 16>& dataIdList,
        uint16_t dataLength,
        uint8_t maxDeltaCounter,
        uint16_t offset);

    /// @brief Default copy constructor
    Config(const Config& config) = default;

    /// @brief Default move constructor
    Config(Config&& config) noexcept = default;

    /// @brief Default assignment operator
    Config& operator=(const Config& config) = default;

    /// @brief Default move-assignment operator
    Config& operator=(Config&& config) noexcept = default;

    /// @brief Default destructor
    ~Config() noexcept = default;
};

/// @brief Specific values and routines for profile 22
class Profile22
{
public:
    /// @brief length of E2E header
    static constexpr uint16_t headerLength{2U};

    /// @brief maximum value of counter
    static constexpr uint8_t maxCounterValue{0x0FU};

    /// @brief default data length supported by profile
    static constexpr uint16_t dataLength{8};

    /// @brief Compute CRC over buffer using configuration values provided in config
    ///
    /// @param config profile configuration
    /// @param buffer CRC is calculated done over this data
    /// @param counter Counter to be used for protecting the Data
    ///
    /// @return computed CRC as uint8_t value
    ///
    /// @uptrace{SWS_CM_90402, ac5c9760109c5970a8359b1980fca28cbbd233e3}
    static uint8_t ComputeCrc(const Config& config, const apd::crc::Buffer& buffer, uint8_t counter) noexcept;

    /// @brief Checks if buffer length is in range (minDataLength...maxDataLength)
    ///
    /// @return true if data is in range, false - otherwise
    static bool IsBufferLengthValid(const Config& config, const apd::crc::Buffer& buffer) noexcept;
};

}  // namespace profile22
}  // namespace profile
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_E2E_PROFILE22_H
