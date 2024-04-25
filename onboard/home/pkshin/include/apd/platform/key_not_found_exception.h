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

/**
 * \file
 */

#ifndef APD_PLATFORM_KEY_NOT_FOUND_EXCEPTION_H_
#define APD_PLATFORM_KEY_NOT_FOUND_EXCEPTION_H_

#include <string>

namespace apd
{
namespace platform
{
namespace exception
{

class KeyNotFoundException : public std::exception
{
private:
    const std::string message_;
    const std::string section_;
    const std::string key_;

public:
    KeyNotFoundException(const std::string& message, const std::string& section)
        : message_(message)
        , section_(section)
        , key_("")
    { }
    KeyNotFoundException(const std::string& message, const std::string& section, const std::string& key)
        : message_(message)
        , section_(section)
        , key_(key)
    { }
    virtual ~KeyNotFoundException()
    { }
    inline std::string what()
    {
        std::ostringstream stream;
        stream << message_ << ". Section: '" << section_ << "', Key: '" << key_ << "'";
        return stream.str();
    }
};

} /* namespace exception */
} /* namespace platform */
} /* namespace apd */

#endif /* APD_PLATFORM_KEY_NOT_FOUND_EXCEPTION_H_ */
