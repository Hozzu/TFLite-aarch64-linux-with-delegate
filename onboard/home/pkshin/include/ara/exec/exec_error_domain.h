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
 * @file
 */

#ifndef ARA_EXEC_EXEC_ERROR_DOMAIN_H_
#define ARA_EXEC_EXEC_ERROR_DOMAIN_H_

#include "ara/core/error_domain.h"
#include "ara/core/error_code.h"
#include "ara/core/exception.h"

namespace ara
{
namespace exec
{

/**
 * @brief Defines an enumeration class for the Execution Management error codes.
 *
 * @uptrace{SWS_EM_02281, 82dc9058e6fc013f1df496f5dd13713e1ceb3e0a}
 */
enum class ExecErrc : ara::core::ErrorDomain::CodeType
{
    kGeneralError = 1,  ///< Some unspecified error occurred
    kCommunicationError = 3,  ///< Communication error occurred
    kMetaModelError = 4,  ///< Wrong meta model identifier passed to a function
    kCancelled = 5,  ///< Transition to the requested Function Group state was cancelled by a newer request
    kFailed = 6,  ///< Requested operation could not be performed
    kFailedUnexpectedTerminationOnEnter = 8,  ///< Unexpected Termination during transition in Process of
                                              ///< target Function Group State happened
    kInvalidTransition = 9,  ///<  Transition invalid (e.g. to Terminating when already in Terminating state)
    kAlreadyInState = 10,  ///< Transition to the requested Function Group state failed
                           ///< because it is already in requested state
    kInTransitionToSameState = 11,  ///< Transition to the requested Function Group state failed because transition to
                                    ///< requested state is already in progress
    kNoTimeStamp = 12,  ///< DeterministicClient time stamp information is not available
    kCycleOverrun = 13,  ///< Deterministic activation cycle time exceeded
    kIntegrityOrAuthenticityCheckFailed = 14  ///< Integrity or authenticity check for a Process to be spawned
                                              ///< in the requested FunctionGroup state failed
};

/**
 * @brief Defines a class for exceptions to be thrown by the Execution Management.
 *
 * @uptrace{SWS_EM_02282, c1d1bc50d06d6841f879fe20eaf3c4b40df9e140}
 */
class ExecException : public ara::core::Exception
{
public:
    /**
     * @brief Constructs a new ExecException object containing an error code
     * @param[in] errorCode The error code.
     *
     * @uptrace{SWS_EM_02283, 95c9374f09e7a1a73ebc79630612bed1976dbac9}
     */
    explicit ExecException(ara::core::ErrorCode errorCode) noexcept;
};

/**
 * @brief Defines a class representing the Execution Management error domain.
 *
 * @uptrace{SWS_EM_02284, 6bdb944b23d069ce5ad22ef2c23535ffc2a8c7cb}
 * @domainid{0x8000'0000'0000'0202ULL}
 */
class ExecErrorDomain final : public ara::core::ErrorDomain
{
    /**
     * @brief Key ID for Execution Management error domain.
     */
    static constexpr ErrorDomain::IdType kId{0x8000000000000202ULL};

public:
    using Errc = ExecErrc;
    using Exception = ExecException;

    /**
     * @brief Constructs a new ExecErrorDomain object
     *
     * @uptrace{SWS_EM_02286, 0f42b50f48c57d632f38685c996f4d7d5226a943}
     */
    ExecErrorDomain() noexcept;

    /**
     * @brief Returns a string constant associated with ExecErrorDomain
     * @returns "Exec".
     *
     * @uptrace{SWS_EM_02287, a458423abed4785922c504b015d1f5d7a4c47c1d}
     */
    const char* Name() const noexcept override;

    /**
     * @brief Returns the message associated with errorCode.
     * @param[in] errorCode The error code number.
     * @returns The message associated with the error code.
     *
     * @uptrace{SWS_EM_02288, 71713895ace4270bb107c87db2645bfe7be61fa1}
     */
    const char* Message(CodeType errorCode) const noexcept override;

    /**
     * @brief Creates a new instance of ExecException from errorCode and throws it as a C++ exception.
     * @param[in] errorCode The error to throw.
     *
     * @uptrace{SWS_EM_02289, 4b801e4e8788819f896281c132a863355c718779}
     */
    [[noreturn]] void ThrowAsException(const ara::core::ErrorCode& errorCode) const noexcept(false) override;
};

/**
 * @brief Returns a reference to the global ExecErrorDomain object.
 * @returns Return a reference to the global ExecErrorDomain object.
 *
 * @uptrace{SWS_EM_02290, 428829dbe3450d81413f4a50dad92d260214c867}
 */
const ara::core::ErrorDomain& GetExecErrorDomain() noexcept;

/**
 * @brief Creates an instance of ErrorCode.
 *
 * @param[in] code Error code number.
 * @param[in] data Vendor defined data associated with the error.
 * @returns An ErrorCode object.
 *
 * @uptrace{SWS_EM_02291, 9ec3438c1f6da327e2f0c6e4f1fc081ecf2f6b02}
 * @uptrace{SWS_EM_02547, 5a7d846a4ebf904f5cbc5c91d322c8beec00dcbc}
 * @uptrace{SWS_EM_02548, 4224c6fcbe2b71c29470b8ef9d439c11876107c0}
 */
ara::core::ErrorCode MakeErrorCode(ara::exec::ExecErrc code, ara::core::ErrorDomain::SupportDataType data) noexcept;

}  // namespace exec
}  // namespace ara

#endif  // ARA_EXEC_EXEC_ERROR_DOMAIN_H_
