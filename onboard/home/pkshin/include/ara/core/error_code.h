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

#ifndef APD_ARA_CORE_ERROR_CODE_H_
#define APD_ARA_CORE_ERROR_CODE_H_

#include "ara/core/error_domain.h"
#include "ara/core/string_view.h"
#include "ara/core/abort.h"

#include <ostream>
#include <utility>
#include <exception>
#include <type_traits>

namespace ara
{
namespace core
{

/// @uptrace{SWS_CORE_00501}
/// @uptrace{SWS_CORE_10300, dd173e1373079ca890cd0f2990ce0d424b850099}
class ErrorCode
{
    friend std::ostream& operator<<(std::ostream& out, ErrorCode const& e)
    {
        return (out << e.mDomain->Name() << ":" << e.mValue << ":" << e.mSupportData);
    }

    using CodeType = ErrorDomain::CodeType;
    using SupportDataType = ErrorDomain::SupportDataType;

public:
    /// @uptrace{SWS_CORE_00512}
    template <typename EnumT, typename = typename std::enable_if<std::is_enum<EnumT>::value>::type>
    constexpr ErrorCode(EnumT e, SupportDataType data = 0) noexcept
        // Call MakeErrorCode() unqualified, so the correct overload is found via ADL.
        : ErrorCode(MakeErrorCode(e, data))
    { }

    /// @uptrace{SWS_CORE_00513}
    constexpr ErrorCode(CodeType value, ErrorDomain const& domain, SupportDataType data = 0) noexcept
        : mValue(value)
        , mSupportData(data)
        , mDomain(&domain)
    { }

    /// @uptrace{SWS_CORE_00514, 409a9db3544b1e78c7859e898cadfc16ee20460c}
    constexpr CodeType Value() const noexcept
    {
        return mValue;
    }

    /// @uptrace{SWS_CORE_00516, 96ef3fed1b34893426f73741262122adc654ada0}
    constexpr SupportDataType SupportData() const noexcept
    {
        return mSupportData;
    }

    /// @uptrace{SWS_CORE_00515, 23764b0e14068b004f77d3f682369512ea7d7bc6}
    constexpr ErrorDomain const& Domain() const noexcept
    {
        return *mDomain;
    }

    /// @uptrace{SWS_CORE_00518, d9fada5aa8dca7f70d39309ee8227c90b7d1ebba}
    StringView Message() const noexcept
    {
        return Domain().Message(Value());
    }

    /// @uptrace{SWS_CORE_00519, 70e35e082718811803291f1138499241e659b4ba}
    [[noreturn]] void ThrowAsException() const noexcept(false)
    {
        Domain().ThrowAsException(*this);

        // Never reached, but apparently needed to avoid warnings from certain compilers (such as 5.4.0).
        Abort("ErrorCode::ThrowAsException returned");
    }

private:
    CodeType mValue;
    SupportDataType mSupportData;
    ErrorDomain const* mDomain;  // non-owning pointer to the associated ErrorDomain
};

/// @uptrace{SWS_CORE_00571}
constexpr inline bool operator==(ErrorCode const& lhs, ErrorCode const& rhs)
{
    return lhs.Domain() == rhs.Domain() && lhs.Value() == rhs.Value();
}

/// @uptrace{SWS_CORE_00572}
constexpr inline bool operator!=(ErrorCode const& lhs, ErrorCode const& rhs)
{
    return lhs.Domain() != rhs.Domain() || lhs.Value() != rhs.Value();
}

namespace ifc
{

// Helper function for other Functional Clusters' error domains.
template <typename ExceptionType>
[[noreturn]] void ThrowOrTerminate(ErrorCode errorCode)
{
#ifndef ARA_NO_EXCEPTIONS
    throw ExceptionType(std::move(errorCode));
#else
    (void)errorCode;
    std::terminate();
#endif
}

}  // namespace ifc

}  // namespace core
}  // namespace ara

#endif  // APD_ARA_CORE_ERROR_CODE_H_
