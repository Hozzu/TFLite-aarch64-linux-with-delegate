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

#ifndef COMMUNICATIONMIDDLEWARE_EXCEPTION_H
#define COMMUNICATIONMIDDLEWARE_EXCEPTION_H

#include <cstdint>
#include <stdexcept>

namespace ara
{
namespace com
{

/*
 * \brief Base class for all exceptions used in the ara::com context.
 * TODO: Delete Exception. SWS_CM_10354 has been removed from the spec.
 */
class Exception : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
};

/*
 * \brief Indicates errors that shall be delivered to the client in case an application error happens during method
 * call.
 *
 * Application errors are compatible to classic AUTOSAR errors and thus consist of a single byte value that indicates
 * the error. A server method may throw this exception to deliver this error code to the calling site. Currently this is
 * the only exception that is guaranteed to be transmitted to the calling site. All other exceptions may lead to
 * uncaught exceptions on server side and thus cause a terminate().
 *
 * TODO: Delete ApplicationErrorException. SWS_CM_10354 has been removed from the spec.
 */
class ApplicationErrorException : public Exception
{

public:
    /**
     * \brief Default constructor that deliberately leaves the exception in an undefined state.
     *
     * This constructor may only be called if the error code is set to a meaningful value afterwards, e.g. during
     * deserialization.
     *
     */
    ApplicationErrorException()
        : Exception("Application error")
    { }

    /**
     * \brief All subclassess of ApplicationErrorException shall override this method.
     * The string returned by the overriden method shall have the following format:
     * "<error> in <service interface> with ErrorCode: <error code>"
     * where:
     * <error> is the short name of the ApplicationError element within the ARXML model
     * <service interface> is the fullyy qualified short name (short name path) of the service interface wherein
     * the Application Error has been declared.
     * <error code> the 6 bit error code defined within the ApplicationError element in decimal format.
     * \return string representation of this ApplicationError (see above).
     */
    virtual const char* what() const noexcept override = 0;
};

}  // namespace com
}  // namespace ara

#endif  // COMMUNICATIONMIDDLEWARE_EXCEPTION_H
