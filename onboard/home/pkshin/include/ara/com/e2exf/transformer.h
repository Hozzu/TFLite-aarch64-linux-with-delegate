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

#ifndef ARA_COM_E2EXF_TRANSFORMER_H
#define ARA_COM_E2EXF_TRANSFORMER_H

#include "ara/core/string.h"
#include <apd/crc/buffer.h>

#include "ara/com/e2exf/types.h"
#include "ara/com/e2e/e2e_types.h"
#include <ara/com/e2exf/config.h>

namespace ara
{

namespace com
{

namespace e2exf
{

/// @brief E2E transformer - performs protect and check operations
///        on given data using rules defined in E2E profiles
///
/// @uptrace{SWS_CM_90433, 129abc2d0d864fcbb8657d42025c018bd4f59d72}
class Transformer
{
public:
    /// @brief Represents correct result of E2E check (machine state is "kValid", check status is "Ok")
    static const ara::com::e2e::Result correctResult;

    /// @brief Constructs transformer with empty configuration
    Transformer();

    /// @brief Constructs transformer with given configuration
    ///
    /// @param cfg    transformer configuration
    explicit Transformer(Config&& cfg);

    /// @brief Constructs transformer with configuration provided as a file on flesystem
    ///
    /// @param filePath               valid path to the confguration file
    /// @param configurationFormat    format of configuration file (JSON or XML)
    explicit Transformer(const ara::core::String& filePath,
        ConfigurationFormat configurationFormat = ConfigurationFormat::JSON);

    /// @brief Default copy constructor
    Transformer(const Transformer&) = default;

    /// @brief Default move constructor
    Transformer(Transformer&&) = default;

    /// @brief Default assignment operator
    Transformer& operator=(const Transformer&) = default;

    /// @brief Default move-assign operator
    Transformer& operator=(Transformer&&) = default;

    /// @brief performs E2E check on given buffer, removes E2E header from given buffer and store the result to output
    /// buffer
    ///
    /// @param id           unique data identifier associated with given data
    /// @param inputBuffer  data to be E2E checked
    /// @param outputBuffer inputBuffer with E2E header removed after check
    ///
    /// @throw std::out_of_range is thrown if given buffer size is less than length of SOME/IP header
    ///
    /// @return ara::com::e2e::Result object containing state and check status
    ara::com::e2e::Result CheckOutOfPlace(const DataIdentifier id,
        const apd::crc::Buffer& inputBuffer,
        apd::crc::Buffer& outputBuffer);

    /// @brief perform E2E protect on given buffer , adds E2E header to input buffer and store them to outputBuffer
    ///
    /// @param id           unique data identifier associated with given data
    /// @param inputBuffer  data to be E2E protected
    /// @param outputBuffer inputBuffer with E2E header added after protection
    ///
    /// @throw std::out_of_range is thrown if given buffer size is less than sum of SOME/IP header length and E2E
    /// Profile Header length
    void ProtectOutOfPlace(const DataIdentifier id,
        const apd::crc::Buffer& inputBuffer,
        apd::crc::Buffer& outputBuffer);

    /// @brief perform E2E check on given buffer
    ///
    /// @param id      unique data identifier associated with given data
    /// @param buffer  data to be E2E checked
    ///
    /// @return ara::com::e2e::Result object containing state and check status
    ara::com::e2e::Result Check(const DataIdentifier id, const apd::crc::Buffer& buffer);

    /// @brief perform E2E protect on given buffer, adds E2E header to input buffer
    ///
    /// @param id           unique data identifier associated with given data
    /// @param buffer  data to be E2E protected
    ///
    /// @throw std::invalid_argument is thrown if there is no protector for given data identifier
    /// @throw std::out_of_range is thrown if given buffer size is less than sum of SOME/IP header length and E2E
    /// Profile Header length
    void Protect(const DataIdentifier id, apd::crc::Buffer& buffer);

    /// @brief check if E2E check can be performed for given data identifier
    ///
    /// @param id - unique data identifier associated with given data
    ///
    /// @throw std::invalid-argument is thrown if either profile checker or state machine are not assotiated with given
    /// data identifier
    /// @throw std::out_of_range is thrown if given buffer size is less than sum of SOME/IP header length and E2E
    /// Profile Header length
    ///
    /// @return returns true if for given data ID checker and state machine instances are registered
    bool IsProtected(const DataIdentifier id) const;

#ifdef E2E_DEVELOPMENT
    apd::crc::Buffer lastValidBuffer;
#endif

private:
    Config config;
};

}  // namespace e2exf
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_E2EXF_TRANSFORMER_H
