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

#ifndef APD_PLATFORM_ERRNOEXCEPTION_H_
#define APD_PLATFORM_ERRNOEXCEPTION_H_

#include <exception>
#include <string>
#include <cstring>

namespace apd
{
namespace platform
{
namespace exception
{

/**
 * \brief Abstract base class for all exceptions related to calls that set the errno variable.
 */
class ErrnoException : public std::exception
{
private:
    int errorNumber_;
    std::string errorMessage_;

public:
    /**
     * \brief Gets the error number (errno) recorded in this exception.
     *
     * \returns the errno set in this exception.
     */
    int getErrorNumber() const
    {
        return errorNumber_;
    }

    /**
     * \brief Gets the clear-text error message
     *
     * The message is obtained using strerror(errorNumber)
     *
     * \returns A reference to a string object stored in this exception containing the error message.
     */
    const std::string& getErrorMessage() const
    {
        return errorMessage_;
    }

    /**
     * \brief Construct a new ErrnoExcpetion and record the error message for the given errno.
     *
     * \param errorNumber The C errno that has occured.
     *
     * \returns A reference to a string object stored in this exception containing the error message.
     */
    ErrnoException(int errorNumber)
        : errorNumber_(errorNumber)
    {
        errorMessage_ = strerror(errorNumber);
    }
    virtual ~ErrnoException()
    { }

    virtual const char* what() const noexcept override
    {
        return errorMessage_.c_str();
    }
};

} /* namespace exception */
} /* namespace platform */
} /* namespace apd */

#endif /* APD_PLATFORM_ERRNOEXCEPTION_H_ */
