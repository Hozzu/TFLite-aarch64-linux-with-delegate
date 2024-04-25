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
/// @brief Interface to class ara::core::array

#ifndef APD_ARA_CORE_ARRAY_H_
#define APD_ARA_CORE_ARRAY_H_

#include <algorithm>
#include <iterator>
#include <utility>
#include <type_traits>
#include <tuple>
#include <cstddef>

namespace ara
{
namespace core
{

namespace internal
{

template <typename T, std::size_t N>
struct ArrayHolder final
{
    using Type = std::remove_cv_t<T>[N];

    static constexpr T const* ptr(Type const& data, std::size_t i) noexcept
    {
        return &data[i];
    }

    static constexpr T* ptr(Type& data, std::size_t i) noexcept
    {
        return &data[i];
    }
};

template <typename T>
struct ArrayHolder<T, 0> final
{
    struct Type final
    { };

    static constexpr T const* ptr(Type const&, std::size_t) noexcept
    {
        return nullptr;
    }

    static constexpr T* ptr(Type&, std::size_t) noexcept
    {
        return nullptr;
    }
};

// This helper namespace basically re-implements C++17's std::is_nothrow_swappable.
// The key to this is that ADL has to be used for the swap() call within noexcept.
namespace adl
{

using std::swap;

template <typename T>
struct is_nothrow_swappable : std::integral_constant<bool, noexcept(swap(std::declval<T&>(), std::declval<T&>()))>
{ };

}  // namespace adl
}  // namespace internal

/// @uptrace{SWS_CORE_01201, 3a43ac08a766ad0d1c38a063f116c2de09d099f4}
/// @uptrace{SWS_CORE_11200, 7c893095b5c1d033b92f4943cbff7e9f6ca25b81}
template <typename T, std::size_t N>
class Array final
{
public:
    /// @uptrace{SWS_CORE_01210, 2b96aa3ec78a19c877444f4c1693b8cdcaf71a88}
    using reference = T&;
    /// @uptrace{SWS_CORE_01211, e13c3b3f743f78b4f2beb1383a0a618e1d2d1fbc}
    using const_reference = T const&;
    /// @uptrace{SWS_CORE_01212, 708a7a89b5146812ebee475787fc90a40f7d9a41}
    using iterator = T*;
    /// @uptrace{SWS_CORE_01213, d3689932ade8f5cd095e5a838b32942f8230c9ba}
    using const_iterator = T const*;
    /// @uptrace{SWS_CORE_01214, ba87ba85c49747bc79a3d10d434a8154eb660284}
    using size_type = std::size_t;
    /// @uptrace{SWS_CORE_01215, 31340ce545e7d3d1b7a9a4c22c890ce59d054764}
    using difference_type = std::ptrdiff_t;
    /// @uptrace{SWS_CORE_01216, 35efb1ebd6deac5f36d135527d67a259812819a6}
    using value_type = T;
    /// @uptrace{SWS_CORE_01217, bc4d1cf4dc30dffef33c2375ecd1f51aa6c5486b}
    using pointer = T*;
    /// @uptrace{SWS_CORE_01218, af2f2da8b7df227ec1d5308aeff83102e70934d1}
    using const_pointer = T const*;
    /// @uptrace{SWS_CORE_01219, 30465af8e3fe1826b8192f6a6c3ee76aaae02ec9}
    using reverse_iterator = std::reverse_iterator<iterator>;
    /// @uptrace{SWS_CORE_01220, 395ef314bcca91593146500f5bbc88bb7a11412f}
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    // no explicit construct/copy/destroy for aggregate type

    // Need to support N==0, for which we have to introduce an indirection.
    using AH = internal::ArrayHolder<T, N>;
    typename AH::Type mData;

    /// @uptrace{SWS_CORE_01241, 32d12b05f9bb4f41b876e7af07e84d20bff4f3e3}
    void fill(T const& u)
    {
        std::fill(begin(), end(), u);
    }

    /// @uptrace{SWS_CORE_01242, 4bd1079624a0ae99d484df221280267d336be7e8}
    void swap(Array<T, N>& other) noexcept(internal::adl::is_nothrow_swappable<T>::value)
    {
        std::swap_ranges(begin(), end(), other.begin());
    }

    // iterators:

    /// @uptrace{SWS_CORE_01250, 8df8a3a89a7e099253ca631eb644e5ed8173f6e3}
    iterator begin() noexcept
    {
        return AH::ptr(mData, 0);
    }

    /// @uptrace{SWS_CORE_01251, 22874ecdde06c10c96d1ab2573d3c1c695bb545c}
    const_iterator begin() const noexcept
    {
        return AH::ptr(mData, 0);
    }

    /// @uptrace{SWS_CORE_01252, 51a03a7fb79c394384961e9db129c5f6b1185ec2}
    iterator end() noexcept
    {
        return AH::ptr(mData, N);
    }

    /// @uptrace{SWS_CORE_01253, 020a806ec9950b6711eae74c8ab5dae415fc30d0}
    const_iterator end() const noexcept
    {
        return AH::ptr(mData, N);
    }

    /// @uptrace{SWS_CORE_01254, cefe966d19c8d533886ced85348659293761b43e}
    reverse_iterator rbegin() noexcept
    {
        return reverse_iterator(end());
    }

    /// @uptrace{SWS_CORE_01255, d0728da18440762edc6eac33e9cd9b719c1355bc}
    const_reverse_iterator rbegin() const noexcept
    {
        return const_reverse_iterator(end());
    }

    /// @uptrace{SWS_CORE_01256, ac6d4200d18a88af432f22c77ee4636415194554}
    reverse_iterator rend() noexcept
    {
        return reverse_iterator(begin());
    }

    /// @uptrace{SWS_CORE_01257, a5f675527f071c7dab86b0cb8beae0a3eefd4a3c}
    const_reverse_iterator rend() const noexcept
    {
        return const_reverse_iterator(begin());
    }

    /// @uptrace{SWS_CORE_01258, 0c2fc51ef3219d81e35ccc7e9ceb5b6d6463ad80}
    const_iterator cbegin() const noexcept
    {
        return begin();
    }

    /// @uptrace{SWS_CORE_01259, 75f6f00ce393053856a3a2632409a5b755e634d5}
    const_iterator cend() const noexcept
    {
        return end();
    }

    /// @uptrace{SWS_CORE_01260, 132795e4eb9941977484b739b175e055e1df54ef}
    const_reverse_iterator crbegin() const noexcept
    {
        return rbegin();
    }

    /// @uptrace{SWS_CORE_01261, e7a5539da0746d66e14307ef46d556f9febcadac}
    const_reverse_iterator crend() const noexcept
    {
        return rend();
    }

    // capacity:

    /// @uptrace{SWS_CORE_01262, d9f65367a3eaa1b626e92f68b498938beccf6116}
    constexpr size_type size() const noexcept
    {
        return N;
    }

    /// @uptrace{SWS_CORE_01263, 71c192bcdaaa0701aedcd90f712817a4aec426c5}
    constexpr size_type max_size() const noexcept
    {
        return N;
    }

    /// @uptrace{SWS_CORE_01264, 0f57dc0f0e379698e64d6a7f64404d133bba6c84}
    constexpr bool empty() const noexcept
    {
        return N == 0;
    }

    // element access:

    /// @uptrace{SWS_CORE_01265, efcabcde97674d747331a1faa3ae5bda78a31f28}
    reference operator[](size_type n)
    {
        return *AH::ptr(mData, n);
    }

    /// @uptrace{SWS_CORE_01266, 24389a18c727f614358ab308de4961fe79ef4402}
    constexpr const_reference operator[](size_type n) const
    {
        return *AH::ptr(mData, n);
    }

    /// @uptrace{SWS_CORE_01267, 14e56d8ede1361861cd6f04d98b4fa915c749066}
    reference front()
    {
        return *AH::ptr(mData, 0);
    }

    /// @uptrace{SWS_CORE_01268, e94668e4fecab064aceefa43f2b4f671bd62d387}
    constexpr const_reference front() const
    {
        return *AH::ptr(mData, 0);
    }

    /// @uptrace{SWS_CORE_01269, 80d0154ce1ea6bba6e3aab1527556ddc10954d33}
    reference back()
    {
        return *AH::ptr(mData, N - 1);
    }

    /// @uptrace{SWS_CORE_01270, dac899325ea9b74529c869fc05ac2ae64a342a8d}
    constexpr const_reference back() const
    {
        return *AH::ptr(mData, N - 1);
    }

    /// @uptrace{SWS_CORE_01271}
    T* data() noexcept
    {
        return AH::ptr(mData, 0);
    }

    /// @uptrace{SWS_CORE_01272}
    T const* data() const noexcept
    {
        return AH::ptr(mData, 0);
    }
};

// comparison operators:

/// @uptrace{SWS_CORE_01290, fb876aad3ec8c257d4ff7cc846c9b413f2464923}
template <typename T, std::size_t N>
bool operator==(Array<T, N> const& lhs, Array<T, N> const& rhs)
{
    return std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

/// @uptrace{SWS_CORE_01291, 3597990e466ce557f8d066bc43115e3457eafffa}
template <typename T, std::size_t N>
bool operator!=(Array<T, N> const& lhs, Array<T, N> const& rhs)
{
    return !operator==(lhs, rhs);
}

/// @uptrace{SWS_CORE_01292, 7cb5eeec1030b17609dedda84b18707540825352}
template <typename T, std::size_t N>
bool operator<(Array<T, N> const& lhs, Array<T, N> const& rhs)
{
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

/// @uptrace{SWS_CORE_01293, cd127284ad4e76abe00534c2b5f1cbdfc93d35b5}
template <typename T, std::size_t N>
bool operator>(Array<T, N> const& lhs, Array<T, N> const& rhs)
{
    return rhs < lhs;
}

/// @uptrace{SWS_CORE_01294, 0c79206e04cc2ecddbe1cc177e581cc991832d9b}
template <typename T, std::size_t N>
bool operator<=(Array<T, N> const& lhs, Array<T, N> const& rhs)
{
    return !(rhs < lhs);
}

/// @uptrace{SWS_CORE_01295, 6d8dead452e0b3025b7143d0f4a2573d514637c6}
template <typename T, std::size_t N>
bool operator>=(Array<T, N> const& lhs, Array<T, N> const& rhs)
{
    return !(lhs < rhs);
}

/// @uptrace{SWS_CORE_01296, 72793ed1ea5d12b92fbcc2a335f382a148244e2a}
template <typename T, std::size_t N>
void swap(Array<T, N>& lhs, Array<T, N>& rhs) noexcept(noexcept(lhs.swap(rhs)))
{
    lhs.swap(rhs);
}

// tuple interface (1/2)
// The C++14 standard prohibits extension of the std namespace with new overloads,
// so we need to put them into our own namespace and rely on ADL to have them found.

/// @uptrace{SWS_CORE_01282, 94b83c4ad130a57755e6b8d306df65634c2a8112}
template <std::size_t I, typename T, std::size_t N>
constexpr T& get(Array<T, N>& a) noexcept
{
    static_assert(I < N, "index out of bounds");
    return a[I];
}

/// @uptrace{SWS_CORE_01283, 80c13b3d906a06041c2fad3c0f47a85b9bac6bdb}
template <std::size_t I, typename T, std::size_t N>
constexpr T&& get(Array<T, N>&& a) noexcept
{
    return std::move(get<I>(a));
}

/// @uptrace{SWS_CORE_01284, 9e21f0bf49b382aa50ede40d2e3992f098d6aeb4}
template <std::size_t I, typename T, std::size_t N>
constexpr T const& get(Array<T, N> const& a) noexcept
{
    static_assert(I < N, "index out of bounds");
    return a[I];
}

}  // namespace core
}  // namespace ara

// tuple interface (2/2)
// Specialization of these symbols in the std namespace is permitted in C++14 by 17.6.4.2.1 [namespace.std],
// because they depend on a user-defined type (i.e. ara::core::Array).

namespace std
{

/// @uptrace{SWS_CORE_01280}
template <typename T, size_t N>
struct tuple_size<ara::core::Array<T, N>> : integral_constant<size_t, N>
{ };

/// @uptrace{SWS_CORE_01281, ab17f19206c6385ccd4fa2494fdb3030e5d23478}
template <size_t I, typename T, size_t N>
struct tuple_element<I, ara::core::Array<T, N>>
{
    /// @uptrace{SWS_CORE_01285, 44063f2f21e50a1f890c9c581fc715aeb9a68da0}
    using type = T;
};

}  // namespace std

#endif  // APD_ARA_CORE_ARRAY_H_
