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

#ifndef APD_ARA_CORE_SCALE_LINEAR_AND_TEXTTABLE_H
#define APD_ARA_CORE_SCALE_LINEAR_AND_TEXTTABLE_H

#include <type_traits>
#include <functional>
#include <cstddef>

namespace ara
{
namespace core
{

/// @uptrace{SWS_CORE_08101, e981be8770690f8acb6bebcbba299a0c850f3165}
template <typename T>
class ScaleLinearAndTexttable final
{
    static_assert(std::is_enum<T>::value, "Type T has to be an enum");

public:
    // Declaration of the underlying_type
    /// @uptrace{SWS_CORE_08111, 373670a68aece5bfec3baae7b9c5779d9774af21}
    using UnderlyingType = typename std::underlying_type<T>::type;

    /// @brief Default constructor
    /// @uptrace{SWS_CORE_08121}
    ScaleLinearAndTexttable() noexcept = default;

    /// @brief Destructor
    /// @uptrace{SWS_CORE_08122, 94e4ee64641b2f82130757f04a5edcb2422b5a57}
    ~ScaleLinearAndTexttable() noexcept = default;

    /// @brief Copy constructor
    /// @uptrace{SWS_CORE_08123, 60f6850fe288df8a50b618376de2997e10cbe5e9}
    constexpr ScaleLinearAndTexttable(ScaleLinearAndTexttable const& other) noexcept = default;

    /// @brief Move constructor
    /// @uptrace{SWS_CORE_08124, cffe418644b70dccf020bd57295248e0c67eff8c}
    constexpr ScaleLinearAndTexttable(ScaleLinearAndTexttable&& other) noexcept = default;

    /// @brief Create an instance of a value of the enum
    /// @uptrace{SWS_CORE_08127, 2dd63290ddd0b5c19ed52685ec7eed4d15a0ec8c}
    constexpr ScaleLinearAndTexttable(T const& v) noexcept
        : mValue(static_cast<UnderlyingType>(v))
    { }

    /// @brief Create an instance of a value of the enum's underlying type
    /// @uptrace{SWS_CORE_08128, 17073932784bd6e45df5f0fc47fa566d7c8524c6}
    constexpr explicit ScaleLinearAndTexttable(UnderlyingType const& v) noexcept
        : mValue(v)
    { }

    // Copy assignment operator
    /// @uptrace{SWS_CORE_08125, 95af4cceddaccb1be60ac543a304af5e901b8282}
    constexpr ScaleLinearAndTexttable& operator=(ScaleLinearAndTexttable const& other) noexcept = default;

    // Move assignment operator
    /// @uptrace{SWS_CORE_08126, e3cebcbe587496cde9eb07e071e4fedd09d2b451}
    constexpr ScaleLinearAndTexttable& operator=(ScaleLinearAndTexttable&& other) noexcept = default;

    // Assignment operator from an enum
    /// @uptrace{SWS_CORE_08129, 3d72e3cea378a485846781199316018dbcc717c4}
    constexpr ScaleLinearAndTexttable& operator=(T const& v) noexcept
    {
        mValue = static_cast<UnderlyingType>(v);
        return *this;
    }

    // Casting operator to the UnderlyingType
    /// @uptrace{SWS_CORE_08141, 9f252a6b54cb09c75c4b68e81bd317301923d02d}
    constexpr explicit operator UnderlyingType() const noexcept
    {
        return static_cast<UnderlyingType>(mValue);
    }

private:
    UnderlyingType mValue;
};

/// @uptrace{SWS_CORE_08180, aefe31572aa26dde6b8829b4b73d64f031cb3b41}
template <typename T>
constexpr bool operator==(ScaleLinearAndTexttable<T> const& lhs, ScaleLinearAndTexttable<T> const& rhs) noexcept
{
    using U = typename std::underlying_type<T>::type;
    return static_cast<U>(lhs) == static_cast<U>(rhs);
}

/// @uptrace{SWS_CORE_08181, c669d37402109d94fd590ae8d016900f9dc80e9f}
template <typename T>
constexpr bool operator==(ScaleLinearAndTexttable<T> const& lhs, T const& rhs) noexcept
{
    using U = typename std::underlying_type<T>::type;
    return static_cast<U>(lhs) == static_cast<U>(rhs);
}

/// @uptrace{SWS_CORE_08182, 8953092bbb3685884b105880011f4ac4422cf4fb}
template <typename T>
constexpr bool operator==(T const& lhs, ScaleLinearAndTexttable<T> const& rhs) noexcept
{
    using U = typename std::underlying_type<T>::type;
    return static_cast<U>(lhs) == static_cast<U>(rhs);
}

/// @uptrace{SWS_CORE_08183, d005ff67089ce05d8de79fb325b4b450d5b42fb4}
template <typename T>
constexpr bool operator!=(ScaleLinearAndTexttable<T> const& lhs, ScaleLinearAndTexttable<T> const& rhs) noexcept
{
    using U = typename std::underlying_type<T>::type;
    return static_cast<U>(lhs) != static_cast<U>(rhs);
}

/// @uptrace{SWS_CORE_08184, 8d1057c63c935f601be014a82ad576b7cfb78d18}
template <typename T>
constexpr bool operator!=(ScaleLinearAndTexttable<T> const& lhs, T const& rhs) noexcept
{
    using U = typename std::underlying_type<T>::type;
    return static_cast<U>(lhs) != static_cast<U>(rhs);
}

/// @uptrace{SWS_CORE_08185, 5f6804879e7fa8912cc3b622c34048031b908a56}
template <typename T>
constexpr bool operator!=(T const& lhs, ScaleLinearAndTexttable<T> const& rhs) noexcept
{
    using U = typename std::underlying_type<T>::type;
    return static_cast<U>(lhs) != static_cast<U>(rhs);
}

/// @uptrace{SWS_CORE_08186, f8bf8de49f3190ab6bfc7cca549e03eb420f9fb0}
template <typename T>
constexpr bool operator<(ScaleLinearAndTexttable<T> const& lhs, ScaleLinearAndTexttable<T> const& rhs) noexcept
{
    using U = typename std::underlying_type<T>::type;
    return static_cast<U>(lhs) < static_cast<U>(rhs);
}

/// @uptrace{SWS_CORE_08187, 88bdb8adcc8af0f4e7211c443fef59e1e2140692}
template <typename T>
constexpr bool operator<(ScaleLinearAndTexttable<T> const& lhs, T const& rhs) noexcept
{
    using U = typename std::underlying_type<T>::type;
    return static_cast<U>(lhs) < static_cast<U>(rhs);
}

/// @uptrace{SWS_CORE_08188, b338595a1bb4f5c5d69a7610620233e86997d542}
template <typename T>
constexpr bool operator<(T const& lhs, ScaleLinearAndTexttable<T> const& rhs) noexcept
{
    using U = typename std::underlying_type<T>::type;
    return static_cast<U>(lhs) < static_cast<U>(rhs);
}

/// @uptrace{SWS_CORE_08189, 2533d645e91763c5052564fee23a45f734f25e87}
template <typename T>
constexpr bool operator<=(ScaleLinearAndTexttable<T> const& lhs, ScaleLinearAndTexttable<T> const& rhs) noexcept
{
    using U = typename std::underlying_type<T>::type;
    return static_cast<U>(lhs) <= static_cast<U>(rhs);
}

/// @uptrace{SWS_CORE_08190, 7c5dee6b9284bb70ade2384d6218359cf238148a}
template <typename T>
constexpr bool operator<=(ScaleLinearAndTexttable<T> const& lhs, T const& rhs) noexcept
{
    using U = typename std::underlying_type<T>::type;
    return static_cast<U>(lhs) <= static_cast<U>(rhs);
}

/// @uptrace{SWS_CORE_08191, 8d91766ad1096b7aecbaf91046379c9187cfd24d}
template <typename T>
constexpr bool operator<=(T const& lhs, ScaleLinearAndTexttable<T> const& rhs) noexcept
{
    using U = typename std::underlying_type<T>::type;
    return static_cast<U>(lhs) <= static_cast<U>(rhs);
}

/// @uptrace{SWS_CORE_08192, c993c7d198aa787ad837a17977c5891bdf621095}
template <typename T>
constexpr bool operator>(ScaleLinearAndTexttable<T> const& lhs, ScaleLinearAndTexttable<T> const& rhs) noexcept
{
    using U = typename std::underlying_type<T>::type;
    return static_cast<U>(lhs) > static_cast<U>(rhs);
}

/// @uptrace{SWS_CORE_08193, 77aa7b7e8827165dc3f79558db38475ee7a8907d}
template <typename T>
constexpr bool operator>(ScaleLinearAndTexttable<T> const& lhs, T const& rhs) noexcept
{
    using U = typename std::underlying_type<T>::type;
    return static_cast<U>(lhs) > static_cast<U>(rhs);
}

/// @uptrace{SWS_CORE_08194, d1844f1975a78ba73866463be8a39fe83a3517a5}
template <typename T>
constexpr bool operator>(T const& lhs, ScaleLinearAndTexttable<T> const& rhs) noexcept
{
    using U = typename std::underlying_type<T>::type;
    return static_cast<U>(lhs) > static_cast<U>(rhs);
}

/// @uptrace{SWS_CORE_08195, cf72ca8f08ef9fa08d7b3fc708287cca9c6af00f}
template <typename T>
constexpr bool operator>=(ScaleLinearAndTexttable<T> const& lhs, ScaleLinearAndTexttable<T> const& rhs) noexcept
{
    using U = typename std::underlying_type<T>::type;
    return static_cast<U>(lhs) >= static_cast<U>(rhs);
}

/// @uptrace{SWS_CORE_08196, a76c65613c42225e88e6a50e5a80abc7d3f07bda}
template <typename T>
constexpr bool operator>=(ScaleLinearAndTexttable<T> const& lhs, T const& rhs) noexcept
{
    using U = typename std::underlying_type<T>::type;
    return static_cast<U>(lhs) >= static_cast<U>(rhs);
}

/// @uptrace{SWS_CORE_08197, aacc3465726cf97eaca87eee15d15c067d8cecb7}
template <typename T>
constexpr bool operator>=(T const& lhs, ScaleLinearAndTexttable<T> const& rhs) noexcept
{
    using U = typename std::underlying_type<T>::type;
    return static_cast<U>(lhs) >= static_cast<U>(rhs);
}

}  // namespace core
}  // namespace ara

namespace std
{

/// @uptrace{SWS_CORE_08198, 4267aca480b710de06099644f701cd4895b68748}
template <typename T>
struct hash<ara::core::ScaleLinearAndTexttable<T>>
{
    /// @uptrace{SWS_CORE_08199, 220ef615ca4b7cf8c390101bbb6d2042cd00af0a}
    size_t operator()(ara::core::ScaleLinearAndTexttable<T> const& v) const noexcept
    {
        using U = typename std::underlying_type<T>::type;
        return hash<U>()(static_cast<U>(v));
    }
};

}  // namespace std

#endif  // APD_ARA_CORE_SCALE_LINEAR_AND_TEXTTABLE_H
