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

/// @file Errorcode and ErrorDomain fpr the find process API.

#ifndef ARA_EXEC_FIND_PROCESS_ERROR_DOMAIN_H_
#define ARA_EXEC_FIND_PROCESS_ERROR_DOMAIN_H_

#include "ara/core/error_code.h"
#include "ara/core/error_domain.h"
#include "ara/core/exception.h"

namespace ara
{
namespace exec
{

/// @brief Error codes for find process.
enum class FindProcessErrc : ara::core::ErrorDomain::CodeType
{
    kSharedMemoryAlreadyExists = 1,  ///< Shared memory should be created, but it already exists
    kSharedMemoryDoesNotExist,  ///< Shared memory should be opened, but it does not exist
    kAccessForbidden,  ///< Access to the shared memory has been forbidden
    kInvalidArgument,  ///< Invalid argument
    kNotInitialized,  ///< Shared Memory has not been created and/or opened
    kInternalError,  ///< Any other error
};

/// @brief Specialized exception class to be used in combination with FindProcessErrorDomain.
class FindProcessException : public ara::core::Exception
{
public:
    FindProcessException(ara::core::ErrorCode&& err)
        : ara::core::Exception(std::move(err))
    { }
};

#if defined(__GNUC__)
#    pragma GCC diagnostic push
#    pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#endif

/// @brief Specialized error domain for FindProcessErrc.
class FindProcessErrorDomain : public ara::core::ErrorDomain
{
    constexpr static ara::core::ErrorDomain::IdType kId = 0x80000000000003ffull;  ///< Error domain for FindProcessErrc

public:
    using Errc = FindProcessErrc;
    using Exception = FindProcessException;

    constexpr FindProcessErrorDomain() noexcept
        : ara::core::ErrorDomain(kId)
    { }
    char const* Name() const noexcept override
    {
        return "FindProcess";
    }
    char const* Message(ara::core::ErrorDomain::CodeType errorCode) const noexcept override
    {
        const FindProcessErrc code = static_cast<FindProcessErrc>(errorCode);
        switch (code) {
        case FindProcessErrc::kInternalError:
            return "InternalError";
        case FindProcessErrc::kSharedMemoryAlreadyExists:
            return "Shared memory already exits";
        case FindProcessErrc::kSharedMemoryDoesNotExist:
            return "Shared memory does not exist";
        case FindProcessErrc::kAccessForbidden:
            return "Access forbidden";
        case FindProcessErrc::kInvalidArgument:
            return "Invalid argument";
        case FindProcessErrc::kNotInitialized:
            return "Not initialized";
        default:
            return "Unknown error";
        }
    }

    void ThrowAsException(ara::core::ErrorCode const& errorCode) const noexcept(false) override
    {
        ara::core::ifc::ThrowOrTerminate<FindProcessException>(errorCode);
    }
};

#if defined(__GNUC__)
#    pragma GCC diagnostic pop
#endif

namespace internal
{
constexpr FindProcessErrorDomain
    g_findProcessErrorDomain;  ///< Static instance of FindProcessErrorDomain for MakeErrorCode
}

/// @brief Get the FindProcessErrorDomain object.
///
/// @return FindProcessErrorDomain
inline constexpr ara::core::ErrorDomain const& GetFindProcessErrorDomain() noexcept
{
    return internal::g_findProcessErrorDomain;
}

/// @brief Specialized MakeErrorCode.
///
/// @param code FindProcessErrc
/// @param data ErrorDomain
/// @return ErrorCode
inline constexpr ara::core::ErrorCode MakeErrorCode(FindProcessErrc code,
    ara::core::ErrorDomain::SupportDataType data) noexcept
{
    return ara::core::ErrorCode(static_cast<ara::core::ErrorDomain::CodeType>(code), GetFindProcessErrorDomain(), data);
}

}  // namespace exec
}  // namespace ara

#endif  // ARA_EXEC_FIND_PROCESS_ERROR_DOMAIN_H_
