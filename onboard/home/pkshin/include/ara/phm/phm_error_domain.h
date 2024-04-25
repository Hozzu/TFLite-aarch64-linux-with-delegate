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

#ifndef ARA_PHM_PHM_ERROR_DOMAIN_H_
#define ARA_PHM_PHM_ERROR_DOMAIN_H_

#include "ara/core/error_domain.h"
#include "ara/core/error_code.h"
#include "ara/core/exception.h"

namespace ara
{
namespace phm
{

/// @brief Defines the errors for PHM.
///
/// @uptrace{SWS_PHM_01240,1c7d1a61ddb720168b816a766fc169e70863cf58}
enum class PhmErrc : ara::core::ErrorDomain::CodeType
{
    kServiceNotAvailable = 1,
    kOfferFailed = 2
};

///
/// @brief Exception type thrown by phm classes
///
class PhmException : public ara::core::Exception
{
public:
    ///
    /// @brief Construct a new phm exception object containing an Error object.
    ///
    explicit PhmException(ara::core::ErrorCode errorCode) noexcept
        : ara::core::Exception(std::move(errorCode))
    { }
};

/// @brief Defines the error domain for Phm.
///
/// @uptrace{SWS_PHM_01241, e0145af9ea3f48d3f210631b320804a3b02f78cd}
class PhmErrorDomain final : public ara::core::ErrorDomain
{
    /**
     * @brief Key ID for PHM error domain.
     *
     * @note The PHM error domain should have Id-s in range 0x8000000000000600...06ff
     */
    static const ErrorDomain::IdType kId{0x8000000000000602};

public:
    /// @brief Defines an alias for the error code value enumeration.
    using Errc = PhmErrc;

    /// @brief Defines an alias for the exception base class.
    using Exception = PhmException;

    /// @brief Creates a PhmErrorDomain instance.
    ///
    constexpr PhmErrorDomain() noexcept
        : ErrorDomain(kId)
    { }

    /// @brief Returns the name of the error domain
    ///
    /// @returns The name of the error domain
    char const* Name() const noexcept override
    {
        return "Phm";
    }

    /// @brief Returns the message associated with the error code.
    ///
    /// @param[in] errorCode The error code number
    /// @returns the error message associated with the respective error code.
    char const* Message(CodeType errorCode) const noexcept override
    {
        Errc const code = static_cast<Errc>(errorCode);
        switch (code) {
        case PhmErrc::kServiceNotAvailable:
            return "PHM is initialized but application is not able to communicate with PHM Daemon";
        case PhmErrc::kOfferFailed:
            return "RecoveryAction service could not be offered due to failure of communication with PHM Daemon";
        default:
            return "Unknown error";
        }
    }

    /// @brief Throws the exception associated with the error code.
    ///
    void ThrowAsException(ara::core::ErrorCode const& errorCode) const noexcept(false) override
    {
        ara::core::ifc::ThrowOrTerminate<Exception>(errorCode);
    }
};

#if defined(__GNUC__)
#    pragma GCC diagnostic pop
#endif

namespace internal
{
constexpr PhmErrorDomain g_phmErrorDomain;
}

/// @brief Returns the global PhmErrorDomain object.
///
inline constexpr ara::core::ErrorDomain const& GetPhmDomain() noexcept
{
    return internal::g_phmErrorDomain;
}

/// @brief Creates an error code.
///
inline constexpr ara::core::ErrorCode MakeErrorCode(PhmErrc code, ara::core::ErrorDomain::SupportDataType data) noexcept
{
    return ara::core::ErrorCode(static_cast<ara::core::ErrorDomain::CodeType>(code), GetPhmDomain(), data);
}

}  // namespace phm
}  // namespace ara

#endif  // ARA_PHM_PHM_ERROR_DOMAIN_H_
