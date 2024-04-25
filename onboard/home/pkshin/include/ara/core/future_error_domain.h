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

#ifndef APD_ARA_CORE_FUTURE_ERROR_DOMAIN_H_
#define APD_ARA_CORE_FUTURE_ERROR_DOMAIN_H_

#include "ara/core/error_domain.h"
#include "ara/core/error_code.h"
#include "ara/core/exception.h"

#include <cstdint>

namespace ara
{
namespace core
{

/**
 * @brief Specifies the types of internal errors that can occur upon calling Future::get or Future::GetResult.
 *
 * These definitions are equivalent to the ones from std::future_errc.
 *
 * @uptrace{SWS_CORE_00400, c884f22acc08072f4683cc723612ea508726af69}
 * @uptrace{SWS_CORE_10900, 2040a821cb76e93760bbacab71e261a3aa67ac41}
 * @uptrace{SWS_CORE_10902, 3206b99297e020953896b4ea3b4a1aba4db9634f}
 * @uptrace{SWS_CORE_10903, ca601089d121cf3a8fe7a3bb01d50320f9cfa5f5}
 * @uptrace{SWS_CORE_10999, 03ea5be5aeda9fb30030741b6a417f0aef9666ac}
 */
enum class future_errc : int32_t
{
    broken_promise = 101,  ///< the asynchronous task abandoned its shared state
    future_already_retrieved = 102,  ///< the contents of the shared state were already accessed
    promise_already_satisfied = 103,  ///< attempt to store a value into the shared state twice
    no_state = 104,  ///< attempt to access Promise or Future without an associated state
};

/**
 * @brief Exception type thrown by Future and Promise classes.
 *
 * @uptrace{SWS_CORE_00411, b4707c9ed86c50e222df63765b30e64d616d1567}
 * @uptrace{SWS_CORE_10910, df0ba5f5dd6cc757f119625f9ffbf52405bc0d0c}
 * @uptrace{SWS_CORE_10911, 3a93c936f031ea1f550b4c8ec48e96d7e1c926e2}
 * @uptrace{SWS_CORE_10999, 03ea5be5aeda9fb30030741b6a417f0aef9666ac}
 */
class FutureException : public Exception
{
public:
    /**
     * @brief Construct a new FutureException from an ErrorCode.
     * @param err  the ErrorCode
     *
     * @uptrace{SWS_CORE_00412, cbf7318becb2ef240d14fbe98b7a08bcdb6184b7}
     */
    explicit FutureException(ErrorCode err) noexcept
        : Exception(std::move(err))
    { }
};

/**
 * @brief Error domain for errors originating from classes Future and Promise.
 *
 * @uptrace{SWS_CORE_00011, 05b959274a76443a409e87b918bbcda823a9abb1}
 * @uptrace{SWS_CORE_00421, 6af690825f2bf7b36b62a28cdcf89f151aabdead}
 * @uptrace{SWS_CORE_10400, 37dd96fccb6ec29c27edfdef56264c85fff0e3a4}
 * @uptrace{SWS_CORE_10930, 2631a22b06d9325c17f28a45dfa2a6f75de38733}
 * @uptrace{SWS_CORE_10931, 4ed1a6571dee86b6d8ea1058d7bb0fc18eb61555}
 * @uptrace{SWS_CORE_10932, 07e777e503ff81f2f55e74f4cb0e7b3a7484aab2}
 * @uptrace{SWS_CORE_10950, 59745e4be95aa29386c0d6e1bca4b8c44e066504}
 * @uptrace{SWS_CORE_10999, 03ea5be5aeda9fb30030741b6a417f0aef9666ac}
 */
class FutureErrorDomain final : public ErrorDomain
{
    constexpr static ErrorDomain::IdType kId = 0x8000000000000013;

public:
    /// @brief Alias for the error code value enumeration
    ///
    /// @uptrace{SWS_CORE_00431, 88ab9c1c57084b064ad0f5af21cd9342725821ac}
    /// @uptrace{SWS_CORE_10933, 63c13d9d886755111f28d3d4afca863d5fe1901c}
    using Errc = future_errc;

    /// @brief Alias for the exception base class
    ///
    /// @uptrace{SWS_CORE_00432, 41ed1690238c780556dd5ae841a44e1d61ab0387}
    /// @uptrace{SWS_CORE_10934, 616475416fea36da731d250594094e4d6231f24e}
    using Exception = FutureException;

    /// @brief Default constructor
    ///
    /// @uptrace{SWS_CORE_00441, 1e9e1dfd15650b73756542ee46f0873bceddb6e4}
    /// @uptrace{SWS_CORE_00013, e83dd9353cfd3d962d2d25f890bbcefa650a5d95}
    constexpr FutureErrorDomain() noexcept
        : ErrorDomain(kId)
    { }

    /// @brief Return the "shortname" ApApplicationErrorDomain.SN of this error domain.
    /// @returns "Future"
    ///
    /// @uptrace{SWS_CORE_00442, bc6acac54715c9519c49a759dc7bcf919aa5df2a}
    /// @uptrace{SWS_CORE_00013, e83dd9353cfd3d962d2d25f890bbcefa650a5d95}
    /// @uptrace{SWS_CORE_10951, 1f0e7635fa04c4e79e90b3fc9f8a268927f36b41}
    char const* Name() const noexcept override
    {
        return "Future";
    }

    /// @brief Translate an error code value into a text message.
    /// @param errorCode  the error code value
    /// @returns the text message, never nullptr
    ///
    /// @uptrace{SWS_CORE_00443, 05f29707487433a7b1d721fbf71aa7cc67d8c900}
    char const* Message(ErrorDomain::CodeType errorCode) const noexcept override
    {
        Errc const code = static_cast<Errc>(errorCode);
        switch (code) {
        case Errc::broken_promise:
            return "broken promise";
        case Errc::future_already_retrieved:
            return "future already retrieved";
        case Errc::promise_already_satisfied:
            return "promise already satisfied";
        case Errc::no_state:
            return "no state associated with this future";
        default:
            return "unknown future error";
        }
    }

    /// @brief Throw the exception type corresponding to the given ErrorCode.
    /// @param errorCode  the ErrorCode instance
    ///
    /// @uptrace{SWS_CORE_00444, 6cc10acb0aef103df7c7e1b4d4c0e8c30cf49ddf}
    void ThrowAsException(ErrorCode const& errorCode) const noexcept(false) override
    {
        /// @uptrace{SWS_CORE_10953, 21934125939b860dd15a27bdd8afc3139521f031}
        ifc::ThrowOrTerminate<Exception>(errorCode);
    }
};

namespace internal
{
constexpr FutureErrorDomain g_futureErrorDomain;
}

/**
 * @brief Obtain the reference to the single global FutureErrorDomain instance.
 * @returns reference to the FutureErrorDomain instance
 *
 * @uptrace{SWS_CORE_00480, a1914280429b73400a01014cd04f232c0bbed248}
 * @uptrace{SWS_CORE_10980, 2b25bd452243af3d0958589a1e49783e0aef6231}
 * @uptrace{SWS_CORE_10981, de44b6e44ca19fe4f91ffd4b572e278f108df6f2}
 * @uptrace{SWS_CORE_10982, ce6d60c496f417dc830e9b40b11967700a340bd5}
 * @uptrace{SWS_CORE_10999, 03ea5be5aeda9fb30030741b6a417f0aef9666ac}
 */
inline constexpr ErrorDomain const& GetFutureErrorDomain() noexcept
{
    return internal::g_futureErrorDomain;
}

/**
 * @brief Create a new ErrorCode for FutureErrorDomain with the given support data type and message.
 *
 * @param code  an enumeration value from future_errc
 * @param data  a vendor-defined supplementary value
 * @returns the new ErrorCode instance
 *
 * @uptrace{SWS_CORE_00490, 2d63d85c0d8b0cd3bab151dc442f3cc8ccd96318}
 * @uptrace{SWS_CORE_10990, ef2c3335af07172d08d07100b6aff23ab6e6b524}
 * @uptrace{SWS_CORE_10991, d2ea0ca50e1cc8a7221771eabefd424e322b2c44}
 * @uptrace{SWS_CORE_10999, 03ea5be5aeda9fb30030741b6a417f0aef9666ac}
 */
inline constexpr ErrorCode MakeErrorCode(future_errc code, ErrorDomain::SupportDataType data) noexcept
{
    return ErrorCode(static_cast<ErrorDomain::CodeType>(code), GetFutureErrorDomain(), data);
}

}  // namespace core
}  // namespace ara

#endif  // APD_ARA_CORE_FUTURE_ERROR_DOMAIN_H_
