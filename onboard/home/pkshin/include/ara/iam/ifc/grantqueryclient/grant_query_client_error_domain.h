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
/// @brief Implementation for the grant query client

#ifndef ARA_IAM_IFC_GRANTQUERYCLIENT_GRANT_QUERY_CLIENT_ERROR_DOMAIN_H_
#define ARA_IAM_IFC_GRANTQUERYCLIENT_GRANT_QUERY_CLIENT_ERROR_DOMAIN_H_

#include "ara/core/error_code.h"
#include "ara/core/error_domain.h"
#include "ara/core/exception.h"

namespace ara
{
namespace iam
{
namespace ifc
{
namespace grantqueryclient
{

/// @brief Error cordes for the IPC communication
enum class GrantQueryClientErrc : ara::core::ErrorDomain::CodeType
{
    kTimeout = 1,  ///< A timout occurred during the processing of the query
    kNotConnected,  ///< The access manger could not be reached
    kInvalidArgument,  ///< The argument could not be processed
    kMessageSize,  ///< The size of the request is to large to be processed.
    kError  ///< An unspecified error occurred
};

/// @brief Specialization of ara::core::Exception
class GrantQueryClientException : public ara::core::Exception
{
public:
    /// @brief Construct a new GrantQueryClientException
    ///
    /// @param err ErrorCode
    GrantQueryClientException(ara::core::ErrorCode&& err)
        : ara::core::Exception(std::move(err))
    { }
};

#if defined(__GNUC__)
#    pragma GCC diagnostic push
#    pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#endif
/// @brief Specialization of ara::core::ErrorDomain
///
class GrantQueryClientErrorDomain : public ara::core::ErrorDomain
{
    constexpr static ara::core::ErrorDomain::IdType kId = 0x8000000000000500;

public:
    using Errc = GrantQueryClientErrc;  ///< Errc for this ErrorDomain
    using Exception = GrantQueryClientException;  ///< Exception class for this ErrorDomain

    /// @brief Constructor of GrantQueryClientErrorDomain
    constexpr GrantQueryClientErrorDomain() noexcept
        : ara::core::ErrorDomain(kId)
    { }

    /// @brief See base class ara::core::ErrorDomain
    ///
    /// @returns IAMGrantQueryClient
    char const* Name() const noexcept override
    {
        return "IAMGrantQueryClient";
    }

    /// @brief See base class ara::core::ErrorDomain
    ///
    /// @param errorCode CodeType
    /// @returns Message
    char const* Message(ara::core::ErrorDomain::CodeType errorCode) const noexcept override
    {
        GrantQueryClientErrc const code = static_cast<GrantQueryClientErrc>(errorCode);
        switch (code) {
        case GrantQueryClientErrc::kTimeout:
            return "Timeout";
        case GrantQueryClientErrc::kNotConnected:
            return "NotConnected";
        case GrantQueryClientErrc::kInvalidArgument:
            return "InvalidArgument";
        case GrantQueryClientErrc::kMessageSize:
            return "MessageSize";
        case GrantQueryClientErrc::kError:
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
        ara::core::ifc::ThrowOrTerminate<GrantQueryClientException>(errorCode);
    }
};

#if defined(__GNUC__)
#    pragma GCC diagnostic pop
#endif

namespace internal
{
constexpr GrantQueryClientErrorDomain
    g_GrantQueryClientErrorDomain;  ///< Static instance of GrantQueryClientErrorDomain
}

/// @brief Obtain the GrantQueryClientErrorDomain instance
///
/// @returns GrantQueryClientErrorDomain
inline constexpr ara::core::ErrorDomain const& GetGrantQueryClientErrorDomain()
{
    return internal::g_GrantQueryClientErrorDomain;
}

/// @brief Specialization of MakeErrorCode with GrantQueryClientErrc
///
/// @param code GrantQueryClientErrc
/// @param data SupportDataType
/// @returns constexpr ara::core::ErrorCode
inline constexpr ara::core::ErrorCode MakeErrorCode(GrantQueryClientErrc code,
    ara::core::ErrorDomain::SupportDataType data)
{
    return ara::core::ErrorCode(
        static_cast<ara::core::ErrorDomain::CodeType>(code), GetGrantQueryClientErrorDomain(), data);
}

}  // namespace grantqueryclient
}  // namespace ifc
}  // namespace iam
}  // namespace ara

#endif  // ARA_IAM_IFC_GRANTQUERYCLIENT_GRANT_QUERY_CLIENT_ERROR_DOMAIN_H_
