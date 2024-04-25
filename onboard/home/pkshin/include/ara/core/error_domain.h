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

#ifndef APD_ARA_CORE_ERROR_DOMAIN_H_
#define APD_ARA_CORE_ERROR_DOMAIN_H_

#include <cstdint>
#include <exception>

namespace ara
{
namespace core
{

#if defined(__GNUC__)
#    pragma GCC diagnostic push
#    pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#endif

// forward declaration
class ErrorCode;

/// @uptrace{SWS_CORE_00110, 30e491a1861b21d30f643955f425d640303e8260}
/// @uptrace{SWS_CORE_10400, 37dd96fccb6ec29c27edfdef56264c85fff0e3a4}
class ErrorDomain
{
public:
    /// @uptrace{SWS_CORE_00121, 6fb87ac38486ec0e3430fad116dfba04bb173d96}
    using IdType = std::uint64_t;
    /// @uptrace{SWS_CORE_00122, 0bbe39c7f715a6d0ceb5b4fcc58327324ed55400}
    using CodeType = std::int32_t;
    /// @uptrace{SWS_CORE_00123, 88f7c7160654be30478bb3f1013d038c7d8e01f8}
    using SupportDataType = std::int32_t;

    /// @uptrace{SWS_CORE_00131, 5e119ede9829cbb4eeba1e75d02eda30e5b45504}
    ErrorDomain(ErrorDomain const&) = delete;
    /// @uptrace{SWS_CORE_00132, db782e2c1732852d17e59e2cc35fd6630360b47c}
    ErrorDomain(ErrorDomain&&) = delete;
    /// @uptrace{SWS_CORE_00133, 07bdf97703aa5209ea50d0cc9c501e26ba20c8a3}
    ErrorDomain& operator=(ErrorDomain const&) = delete;
    /// @uptrace{SWS_CORE_00134, cb8653b3e2ae99d17144a8e706b551d0b0b8d24f}
    ErrorDomain& operator=(ErrorDomain&&) = delete;

    /// @uptrace{SWS_CORE_00152, 6bc13d16609926f2b8ca763bf33a4b8c95a1bb66}
    virtual char const* Name() const noexcept = 0;

    /// @uptrace{SWS_CORE_00153, 58e4862784e7582417e563c2483684a252366525}
    virtual char const* Message(CodeType errorCode) const noexcept = 0;

    /**
     * @brief Throws the given errorCode as Exception
     * @param errorCode error code to be thrown
     * @remark if ARA_NO_EXCEPTIONS is defined, this function call will terminate.
     * @uptrace{SWS_CORE_00154, 4feb7c86c417edf715405c131335ab4e94900701}
     */
    [[noreturn]] virtual void ThrowAsException(ErrorCode const& errorCode) const noexcept(false) = 0;

    /// @uptrace{SWS_CORE_00151, 4eecd59f1e5ddc710f2d0483f34821b1526bb109}
    /// @uptrace{SWS_CORE_10952, 3ebc0e9e7c39613eb7ac8a79918fa3520acbe867}
    constexpr IdType Id() const noexcept
    {
        return mId;
    }

    /// @uptrace{SWS_CORE_00137, 4658534d6cb18ef02ddcc99b5fa4a28bf7d3707e}
    constexpr bool operator==(ErrorDomain const& other) const noexcept
    {
        return mId == other.mId;
    }

    /// @uptrace{SWS_CORE_00138, fb17e712e11dff92c5de9bf78be6bfe80db08def}
    constexpr bool operator!=(ErrorDomain const& other) const noexcept
    {
        return mId != other.mId;
    }

protected:
    /// @uptrace{SWS_CORE_00135, 18ad276405b3e67f06b5c84b7b47a7b700556d54}
    constexpr explicit ErrorDomain(IdType id) noexcept
        : mId(id)
    { }

    /// @brief Destructor
    ///
    /// This dtor is non-virtual (and trivial) so that this class is a literal type.
    /// While we do have virtual functions, we never need polymorphic destruction.
    ///
    /// @uptrace{SWS_CORE_00136}
    ~ErrorDomain() = default;

private:
    IdType const mId;
};

#if defined(__GNUC__)
#    pragma GCC diagnostic pop
#endif

}  // namespace core
}  // namespace ara

#endif  // APD_ARA_CORE_ERROR_DOMAIN_H_
