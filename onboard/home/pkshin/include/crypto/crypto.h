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

#ifndef ARA_UCM_LIBS_CRYPTO_H_
#define ARA_UCM_LIBS_CRYPTO_H_

#include "ara/core/string.h"

namespace ara
{
namespace ucm
{
namespace libs
{

/// @brief This class contains UCM crypto functions
class Crypto
{
public:
    virtual ~Crypto();
    /// @brief Checks validity of a signature
    ///
    /// @param certificate certificate that contains a public key
    /// @param filePath The absolute path to a file to check
    /// @param signaturePath The absolute path to a signature
    ///
    /// @return true if signature is valid, false otherwise
    virtual bool CheckSignature(const ara::core::String& certificate,
        const ara::core::String& filePath,
        const ara::core::String& signaturePath) const;

    /// @brief Returns the SHA-256 hash of the file
    ///
    /// @param path The absolute path to a file.
    ///
    /// @return SHA-256 hash in ara::core::String
    virtual ara::core::String GetFileHash(const ara::core::String& filePath) const;
};

}  // namespace libs
}  // namespace ucm
}  // namespace ara

#endif  // ARA_UCM_LIBS_CRYPTO_H_
