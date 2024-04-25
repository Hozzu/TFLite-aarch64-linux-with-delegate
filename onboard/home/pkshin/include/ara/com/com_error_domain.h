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

#ifndef ARA_COM_COM_ERROR_DOMAIN_H
#define ARA_COM_COM_ERROR_DOMAIN_H

#include "ara/core/error_code.h"
#include "ara/core/error_domain.h"
#include "ara/core/exception.h"

/** @uptrace{SWS_CM_11264, 3cdf4c5bda5d8680c445c1c4ab0d310fe4e40590} */
namespace ara
{
namespace com
{

enum class ComErrorDomainErrc : ara::core::ErrorDomain::CodeType
{
    kServiceNotAvailable = 1,  ///< Service is not available.
    kMaxSamplesExceeded = 2,  ///< Application holds more SamplePtrs than commited in Subscribe().
    kNetworkBindingFailure = 3,  ///< Local failure has been detected by the network binding.
    kBadArguments = 4,  ///< Invalid arguments were provided
    kUnknownError = 5  ///< Placeholder for investigation
};

class ComErrorDomainException : public ara::core::Exception
{
public:
    explicit ComErrorDomainException(ara::core::ErrorCode err) noexcept
        : ara::core::Exception(err)
    { }
};

class ComErrorDomain final : public ara::core::ErrorDomain
{
    /** @uptrace{SWS_CM_11267, 5be4f18c3efc009d8ae8ef23ba06adc3c5d6325d} */
    constexpr static ara::core::ErrorDomain::IdType kId = 0x8000000000001267;

public:
    using Errc = ComErrorDomainErrc;

    using Exception = ComErrorDomainException;

    /// @brief Default constructor
    // [SWS_CORE_00241]
    // [SWS_CORE_00012]
    constexpr ComErrorDomain() noexcept
        : ara::core::ErrorDomain(kId)
    { }

    /// @brief Return the "shortname" of this error domain.
    char const* Name() const noexcept override
    {
        return "Com";
    }

    char const* Message(ara::core::ErrorDomain::CodeType errorCode) const noexcept override
    {
        Errc const code = static_cast<Errc>(errorCode);
        switch (code) {
        case Errc::kServiceNotAvailable:
            return "Service is not available.";
        case Errc::kMaxSamplesExceeded:
            return "Application holds more SamplePtrs than commited in Subscribe().";
        case Errc::kNetworkBindingFailure:
            return "Local failure has been detected by the network binding.";
        case Errc::kBadArguments:
            return "Invalid arguments were provided.";
        case Errc::kUnknownError:
            return "Placeholder for investigation.";
        default:
            return "Unknown error code";
        }
    }

    void ThrowAsException(ara::core::ErrorCode const& errorCode) const noexcept(false) override
    {
        ara::core::ifc::ThrowOrTerminate<Exception>(errorCode);
    }
};

namespace internal
{
constexpr ComErrorDomain g_ComErrorDomain;
}

inline constexpr ara::core::ErrorDomain const& GetComErrorDomain() noexcept
{
    return internal::g_ComErrorDomain;
}

inline constexpr ara::core::ErrorCode MakeErrorCode(ComErrorDomainErrc code,
    ara::core::ErrorDomain::SupportDataType data) noexcept
{
    return ara::core::ErrorCode(static_cast<ara::core::ErrorDomain::CodeType>(code), GetComErrorDomain(), data);
}

}  // namespace com
}  // namespace ara

#endif  // ARA_COM_COM_ERROR_DOMAIN_H
