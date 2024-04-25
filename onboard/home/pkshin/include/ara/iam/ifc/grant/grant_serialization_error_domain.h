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

/// @file
/// @brief Error domain for the grant implementations

#ifndef ARA_IAM_IFC_GRANT_GRANT_SERIALIZATION_ERROR_DOMAIN_H_
#define ARA_IAM_IFC_GRANT_GRANT_SERIALIZATION_ERROR_DOMAIN_H_

#include "ara/core/error_code.h"
#include "ara/core/error_domain.h"
#include "ara/core/exception.h"

namespace ara
{
namespace iam
{
namespace ifc
{
namespace grant
{

/// @brief Error codes of grant serialization
enum class GrantSerializationErrc : ara::core::ErrorDomain::CodeType
{
    kInvalidArgument = 1,  ///< Invalid argument
    kFileNotFound,  ///< File not found for binary serialization
    kOpenStreamFailed,  ///< Stream could not be opened binary serialization
    kValidationError,  ///< Failed to validate the read data
    kError  ///< Any other error
};

/// @brief Specialization of ara::core::Exception
class GrantSerializationException : public ara::core::Exception
{
public:
    /// @brief See ara::core::Exception
    ///
    /// @param err ErrorCode
    GrantSerializationException(ara::core::ErrorCode&& err)
        : ara::core::Exception(std::move(err))
    { }
};

#if defined(__GNUC__)
#    pragma GCC diagnostic push
#    pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#endif

/// @brief Specialization of ara::core::ErrorDomain
///
class GrantSerializationErrorDomain : public ara::core::ErrorDomain
{
    constexpr static ara::core::ErrorDomain::IdType kId = 0x8000000000000501;

public:
    using Errc = GrantSerializationErrc;  ///< Errc for this ErrorDomain
    using Exception = GrantSerializationException;  ///< Exception class for this ErrorDomain

    /// @brief Constructor
    ///
    constexpr GrantSerializationErrorDomain() noexcept
        : ara::core::ErrorDomain(kId)
    { }

    /// @brief See base class ara::core::ErrorDomain
    ///
    /// @returns GrantSerialization
    char const* Name() const noexcept override
    {
        return "GrantSerialization";
    }

    /// @brief See base class ara::core::ErrorDomain
    ///
    /// @param errorCode CodeType
    /// @returns String
    char const* Message(ara::core::ErrorDomain::CodeType errorCode) const noexcept override
    {
        GrantSerializationErrc const code = static_cast<GrantSerializationErrc>(errorCode);
        switch (code) {
        case GrantSerializationErrc::kInvalidArgument:
            return "InvalidArgument";
        case GrantSerializationErrc::kFileNotFound:
            return "FileNotFound";
        case GrantSerializationErrc::kOpenStreamFailed:
            return "OpenStreamFailed";
        case GrantSerializationErrc::kValidationError:
            return "ValidationError";
        case GrantSerializationErrc::kError:
            return "Error";
        default:
            return "Unknown error";
        }
    }

    /// @brief See base class ara::core::ErrorDomain
    ///
    /// @param errorCode ErrorCode
    void ThrowAsException(ara::core::ErrorCode const& errorCode) const noexcept(false) override
    {
        ara::core::ifc::ThrowOrTerminate<GrantSerializationException>(errorCode);
    }
};

#if defined(__GNUC__)
#    pragma GCC diagnostic pop
#endif

namespace internal
{
constexpr GrantSerializationErrorDomain
    g_GrantSerializationErrorDomain;  ///< Static instance of GrantSerializationErrorDomain
}

/// @brief Get the Grant Serialization Error Domain object
///
/// @returns GrantSerializationErrorDomain
inline constexpr ara::core::ErrorDomain const& GetGrantSerializationErrorDomain()
{
    return internal::g_GrantSerializationErrorDomain;
}
/// @brief Specialization of MakeErrorCode with GrantSerializationErrc
///
/// @param code GrantSerializationErrc
/// @param data SupportDataType
/// @returns constexpr ara::core::ErrorCode
inline constexpr ara::core::ErrorCode MakeErrorCode(GrantSerializationErrc code,
    ara::core::ErrorDomain::SupportDataType data)
{
    return ara::core::ErrorCode(
        static_cast<ara::core::ErrorDomain::CodeType>(code), GetGrantSerializationErrorDomain(), data);
}

}  // namespace grant
}  // namespace ifc
}  // namespace iam
}  // namespace ara

#endif  // ARA_IAM_IFC_GRANT_GRANT_SERIALIZATION_ERROR_DOMAIN_H_
