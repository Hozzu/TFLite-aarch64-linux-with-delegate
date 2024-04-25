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

#ifndef SRC_ARA_EXEC_LIBPLATFORM_INCLUDE_LIBPLATFORM_OPEN_PIPE_EXCEPTION_HPP_
#define SRC_ARA_EXEC_LIBPLATFORM_INCLUDE_LIBPLATFORM_OPEN_PIPE_EXCEPTION_HPP_

#include "errno_exception.h"
#include <string>

namespace ara
{
namespace phm
{
namespace internal
{

class OpenPipeException : public ErrnoException
{
    typedef ErrnoException Parent;

public:
    /// @brief Constructor.
    ///
    /// @param errorNo      The C errno that has occured.
    explicit OpenPipeException(int const errorNo)
        : Parent(errorNo)
        , errorMessage_()
    { }

    /// @brief Constructor.
    ///
    /// @param errorNo      The C errno that has occured.
    /// @param errorMessage The error message.
    OpenPipeException(int const errorNo, const ::std::string& errorMessage)
        : Parent(errorNo)
        , errorMessage_("ERRNO " + std::to_string(errorNo) + ": " + errorMessage)
    { }

    /// @brief Constructor.
    ///
    /// @param errorMessage The error message.
    explicit OpenPipeException(const ::std::string& errorMessage)
        : Parent(0)
        , errorMessage_(errorMessage)
    { }

    /// @brief Returns this exception string description.
    ///
    /// @returns exception description.
    const char* what() const noexcept override
    {
        const char* string;
        if (not errorMessage_.empty()) {
            string = errorMessage_.c_str();
        } else {
            string = Parent::what();
        }
        return string;
    }

private:
    /// @brief Error message string.
    std::string errorMessage_;
};

}  // namespace internal
}  // namespace phm
}  // namespace ara

#endif  // SRC_ARA_EXEC_LIBPLATFORM_INCLUDE_LIBPLATFORM_OPEN_PIPE_EXCEPTION_HPP_
