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

#ifndef ARA_COM_E2E_PROFILE11_H
#define ARA_COM_E2E_PROFILE11_H

#include <cstdint>
#include <apd/crc/buffer.h>

namespace ara
{

namespace com
{

namespace profile
{

namespace profile11
{

/// @brief Supported inclusion modes to include the implicit two-byte Data ID in the one-byte CRC
///
/// @uptrace{SWS_CM_90403, 840d798c53ac10f399cb4acf6bd0c483417e5277}
enum class DataIdMode : uint8_t
{
    ALL_16_BIT,  ///< Two bytes are included in the CRC (double ID configuration).
    LOWER_12_BIT  ///< The low byte is included in the implicit CRC calculation, the low nibble of the high byte is
    /// transmitted along with the data (i.e. it is explicitly included), the high nibble of the high byte
    /// is not used. This is applicable for the IDs up to 12 bits.
};

/// @brief Configuration of transmitted Data for E2E Profile 11
struct Config
{
    /// @brief Bit offset of Counter in MSB first order
    uint16_t counterOffset;

    /// @brief Bit offset of CRC (i.e. since *Data) in MSB first order
    uint16_t crcOffset;

    /// @brief A unique numerical identifier for the referenced event or field notifier that is included in the CRC
    /// calculation
    uint16_t dataId;

    /// @brief the inclusion mode that is used to include the implicit two-byte Data ID in the one-byte CRC
    DataIdMode dataIdMode;

    /// @brief Bit offset of the low nibble of the high byte of Data ID. This parameter is used only if dataIdMode =
    /// LOWER_12_BIT (otherwise it is ignored)
    uint16_t dataIdNibbleOffset;

    /// @brief Length of data, in bits
    uint16_t dataLength;

    /// @brief Maximum allowed difference between two counter values of two consecutively received valid messages.
    uint8_t maxDeltaCounter;

    Config() = delete;

    /// @brief Constructs configuration object for E2E profile from supplied parameters
    Config(uint16_t counterOffset,
        uint16_t crcOffset,
        uint16_t dataId,
        DataIdMode dataIdMode,
        uint16_t dataIdNibbleOffset,
        uint16_t dataLength,
        uint8_t maxDeltaCounter);

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

/// @brief Specific values and routines for profile 11
class Profile11
{
public:
    /// @brief length of E2E header
    static constexpr uint16_t headerLength{2};

    /// @brief maximum value of counter
    static constexpr uint8_t maxCounterValue{0x0E};

    /// @brief default data length supported by profile
    static constexpr uint16_t dataLength{8};

    // Constants below defined according PRS_E2EProtocol_00540 and PRS_E2EProtocol_00541

    /// @brief Default bit offset of CRC
    static constexpr uint16_t crcOffset{0};

    /// @brief Default offset of Counter
    static constexpr uint16_t counterOffset{8};

    /// @brief Default offset of the low nibble of the high byte of Data ID
    static constexpr uint16_t dataIdNibbleOffset{12};

    /// @brief Compute CRC over buffer using configuration values provided in config
    ///
    /// @param config profile configuration
    /// @param buffer CRC is calculated done over this data
    ///
    /// @return computed CRC as uint8_t value
    ///
    /// @uptrace{SWS_CM_90402, ac5c9760109c5970a8359b1980fca28cbbd233e3}
    static uint8_t ComputeCrc(const Config& config, const apd::crc::Buffer& buffer) noexcept;

    /// @brief Extracts nibble from Data ID
    ///
    /// @param dataId A unique numerical identifier for the referenced event or field notifier
    ///
    /// @return nibble value
    static uint8_t CalculateDataIdNibble(uint16_t dataId) noexcept;

    /// @brief Checks if buffer length is in range (minDataLength...maxDataLength)
    ///
    /// @return true if data is in range, false - otherwise
    static bool IsBufferLengthValid(const Config& config, const apd::crc::Buffer& buffer) noexcept;
};

}  // namespace profile11
}  // namespace profile
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_E2E_PROFILE11_H
