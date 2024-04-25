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

#ifndef APD_ARA_CORE_SPAN_H_
#define APD_ARA_CORE_SPAN_H_

#include "ara/core/array.h"
#include "ara/core/utility.h"

#include <iostream>
#include <type_traits>
#include <iterator>
#include <limits>
#include <algorithm>
#include <array>
#include <cstddef>
#include <cassert>

namespace ara
{
namespace core
{

namespace
{
//*/
constexpr static bool DEBUG_SPAN = false;
/*/
constexpr static bool DEBUG_SPAN = true;
//*/

template <typename... Args>
static inline void xtrace(Args const&... args)
{
    if (DEBUG_SPAN) {
        using expander = int[];
        static_cast<void>(expander{0, (static_cast<void>(std::cerr << args), 0)...});
    }
}
}  // namespace

/// @uptrace{SWS_CORE_01901, 5a0c96366db49d8e4ac58beb6f3bb982f964974f}
constexpr std::size_t dynamic_extent = std::numeric_limits<std::size_t>::max();

template <typename T, std::size_t Extent>
class Span;

namespace internal
{

// Re-implementation of std::remove_cvref from C++20.
template <typename T>
struct remove_cvref
{
    using type = std::remove_cv_t<std::remove_reference_t<T>>;
};

// Re-implementation of std::remove_cvref_t from C++20.
template <typename T>
using remove_cvref_t = typename remove_cvref<T>::type;

template <typename T>
struct is_ara_core_span_checker : public std::false_type
{ };

template <typename T, std::size_t Extent>
struct is_ara_core_span_checker<core::Span<T, Extent>> : public std::true_type
{ };

template <typename T>
struct is_ara_core_span : public is_ara_core_span_checker<remove_cvref_t<T>>
{ };

template <typename T>
struct is_ara_core_array_checker : public std::false_type
{ };

template <typename T, std::size_t N>
struct is_ara_core_array_checker<core::Array<T, N>> : public std::true_type
{ };

template <typename T>
struct is_ara_core_array : public is_ara_core_array_checker<remove_cvref_t<T>>
{ };

template <typename T>
struct is_std_array_checker : public std::false_type
{ };

template <typename T, std::size_t N>
struct is_std_array_checker<std::array<T, N>> : public std::true_type
{ };

template <typename T>
struct is_std_array : public is_std_array_checker<remove_cvref_t<T>>
{ };

template <typename, typename = size_t>
struct is_complete : std::false_type
{ };

template <typename T>
struct is_complete<T, decltype(sizeof(T))> : std::true_type
{ };

// Re-implementation of std::void_t from C++20.
// We assume that the compiler implements CWG defect 1558.
template <typename...>
using void_t = void;

template <typename, typename, typename, typename = void>
struct is_suitable_container : public std::false_type
{ };

template <typename C, typename ArgT, typename ElementType>
struct is_suitable_container<C,
    ArgT,
    ElementType,
    void_t<  //
        std::enable_if_t<!internal::is_ara_core_span<C>::value>,  //
        std::enable_if_t<!internal::is_ara_core_array<C>::value>,  //
        std::enable_if_t<!internal::is_std_array<C>::value>,  //
        std::enable_if_t<!std::is_array<C>::value>,  //
        decltype(core::data(std::declval<ArgT>())),  //
        decltype(core::size(std::declval<ArgT>())),  //
        std::enable_if_t<std::is_convertible<std::remove_pointer_t<decltype(core::data(std::declval<ArgT>()))> (*)[],
            ElementType (*)[]>::value>  //
        >  //
    > : public std::true_type
{ };

}  // namespace internal

/// @uptrace{SWS_CORE_01900, 6781f9a138a94643d8bef21f7f12d93351dd4849}
template <typename T, std::size_t Extent = dynamic_extent>
class Span
{
    /// @uptrace{SWS_CORE_01900, 6781f9a138a94643d8bef21f7f12d93351dd4849}
    static_assert(std::is_object<T>::value, "Span cannot contain reference or void types");
    /// @uptrace{SWS_CORE_01900, 6781f9a138a94643d8bef21f7f12d93351dd4849}
    static_assert(!std::is_abstract<T>::value, "Span cannot contain abstract types");
    /// @uptrace{SWS_CORE_01900, 6781f9a138a94643d8bef21f7f12d93351dd4849}
    static_assert(internal::is_complete<T>::value, "Span cannot contain incomplete types");

    template <typename U>
    using type_of_data = decltype(ara::core::data(std::declval<U>()));

public:
    /// @uptrace{SWS_CORE_01911, a79a8d9a04d5812d8505ed5214f1f2d4b02f5f61}
    using element_type = T;
    /// @uptrace{SWS_CORE_01912, d5f87ac355fc45ad964f916815eb20717ef239bf}
    using value_type = typename std::remove_cv<element_type>::type;
    /// @uptrace{SWS_CORE_01921, 087567acd601b67b2ec8f5267a2893ecc2895c5e}
    using size_type = std::size_t;
    /// @uptrace{SWS_CORE_01914, a06855a09b42fe8821b90224e88c5413ddec514e}
    using difference_type = std::ptrdiff_t;
    /// @uptrace{SWS_CORE_01915, b5010261e748a3995a171833fcaf3993246aac0c}
    using pointer = element_type*;
    /// @uptrace{SWS_CORE_01922, 775a575cd16ef5ddd0651fcf9914ccce0898d135}
    using const_pointer = element_type const*;
    /// @uptrace{SWS_CORE_01916, 529a85d656f6a64c0db59f6d07baa5f2e79981a4}
    using reference = element_type&;
    /// @uptrace{SWS_CORE_01923, f3c9d008db518214773ed315258c8abda379280d}
    using const_reference = element_type const&;
    /// @uptrace{SWS_CORE_01917, 1564e9e3b1c3fe0fe18c778b8fedca207b86fc50}
    using iterator = element_type*;
    /// @uptrace{SWS_CORE_01918, fa035f8fadb9f6ee10875b00a164a38ba9ac9906}
    using const_iterator = element_type const*;
    /// @uptrace{SWS_CORE_01919, 917536a34b3d27dd632bb3de10382d45dac6224f}
    using reverse_iterator = std::reverse_iterator<iterator>;
    /// @uptrace{SWS_CORE_01920, 33b0327190ccba9b88fdb097f4fd5b77fe010deb}
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    /// @uptrace{SWS_CORE_01931, c7a15021c3b6f9873f8236cae340a60723ddfa5a}
    static constexpr size_type extent = Extent;

    // 21.7.3.2, constructors, copy, and assignment

    /// @uptrace{SWS_CORE_01941, a5ae05fa5b87cfc2c268380949dd8d62e1be4114}
    template <typename U = void, typename = typename std::enable_if<Extent == dynamic_extent || Extent == 0, U>::type>
    constexpr Span() noexcept
        : mData(nullptr)
        , mExtent(0)
    {
        xtrace("__ Span()\n");
    }

    /// @uptrace{SWS_CORE_01942, 17ec6fb33dda50ff823da9b9b5eb0532bf7b7c05}
    constexpr Span(pointer ptr, size_type count)
        : mData(ptr)
        , mExtent(count)
    {
        xtrace("__ Span(T*, size_t)\n");
        xtrace("____ ptr = ", ptr, ", count = ", count, " (ex = ", Extent, ")\n");
        if (Extent != dynamic_extent && count != Extent) {
            assert(!"inconsistent extent");
        }
    }

    /// @uptrace{SWS_CORE_01943, f18136ffaab3d410c68081231a71b9ae7d9f80e9}
    constexpr Span(pointer firstElem, pointer lastElem)
        : Span(firstElem, static_cast<std::size_t>(lastElem - firstElem))
    {
        xtrace("__ Span(T*, T*)\n");
        assert(std::distance(firstElem, lastElem) >= 0);
    }

    /// @uptrace{SWS_CORE_01944, 4d286f1c6b27ff35cfa04eca6feb880c9bbfe0dc}
    template <std::size_t N,
        typename = typename std::enable_if<(extent == dynamic_extent || extent == N)
            && std::is_convertible<std::remove_pointer_t<type_of_data<element_type (&)[N]>> (*)[],
                element_type (*)[]>::value>::type>
    constexpr Span(element_type (&arr)[N]) noexcept
        : Span(std::addressof(arr[0]), N)
    {
        xtrace("__ Span(raw)\n");
    }

    /// @uptrace{SWS_CORE_01953, 0f580b18955b490a90711bebdee98a874b53e63e}
    template <typename U,
        std::size_t N,
        typename = typename std::enable_if<(extent == dynamic_extent || extent == N)
            && std::is_convertible<
                typename std::remove_pointer_t<decltype(std::declval<std::array<U, N>>().data())> (*)[],
                element_type (*)[]>::value>::type>
    constexpr Span(std::array<U, N>& arr) noexcept
        : Span(arr.data(), N)
    {
        xtrace("__ Span(std::array&)\n");
    }

    /// @uptrace{SWS_CORE_01954, 6b84fae2abce53925624cabcd4fe2d00de8b0429}
    template <typename U,
        std::size_t N,
        typename = typename std::enable_if<(extent == dynamic_extent || extent == N)
            && std::is_convertible<
                typename std::remove_pointer_t<decltype(std::declval<std::array<U, N>>().data())> (*)[],
                element_type (*)[]>::value>::type>
    constexpr Span(const std::array<U, N>& arr) noexcept
        : Span(arr.data(), N)
    {
        xtrace("__ Span(std::array const&)\n");
    }

    /// @uptrace{SWS_CORE_01945, fdc3027cc728bdd694ec817d21baa2f7d5ddf2e9}
    template <typename U,
        std::size_t N,
        typename = typename std::enable_if<(extent == dynamic_extent || extent == N)
            && std::is_convertible<typename std::remove_pointer_t<decltype(std::declval<Array<U, N>>().data())> (*)[],
                element_type (*)[]>::value>::type>
    constexpr Span(Array<U, N>& arr) noexcept
        : Span(arr.data(), N)
    {
        xtrace("__ Span(Array&)\n");
    }

    /// @uptrace{SWS_CORE_01946, d9bd279905bbc265746da79b0f91abced366fbc3}
    template <typename U,
        std::size_t N,
        typename = typename std::enable_if<(extent == dynamic_extent || extent == N)
            && std::is_convertible<
                typename std::remove_pointer_t<decltype(std::declval<Array<U, N> const>().data())> (*)[],
                element_type (*)[]>::value>::type>
    constexpr Span(Array<U, N> const& arr) noexcept
        : Span(arr.data(), N)
    {
        xtrace("__ Span(Array const&)\n");
    }

    /// @uptrace{SWS_CORE_01947, d99375acf2b83a9d361bc254e67e9ac14127cfe8}
    template <typename Container,
        typename = typename std::enable_if<(extent == dynamic_extent)
            && internal::is_suitable_container<Container, Container&, element_type>::value>::type>
    constexpr Span(Container& cont)
        : Span(core::data(cont), core::size(cont))
    {
        xtrace("__ Span(Container&)\n");
    }

    /// @uptrace{SWS_CORE_01948, 24d2a3a7f5b51770f3837320f8e4a62b27f21e49}
    template <typename Container,
        typename = typename std::enable_if<(extent == dynamic_extent)
            && internal::is_suitable_container<Container, Container const&, element_type>::value>::type>
    constexpr Span(Container const& cont)
        : Span(core::data(cont), core::size(cont))
    {
        xtrace("__ Span(Container const&)\n");
    }

    /// @uptrace{SWS_CORE_01949, c3ba4108b0f97fa4a6c29f06d1b82f64c922cb8a}
    constexpr Span(Span const& other) noexcept = default;

    /// @brief Converting constructor
    ///
    /// This ctor allows assignment of a cv-Span<> from a normal Span<>,
    /// and also of a dynamic_extent-Span<> from a static extent-one.
    ///
    /// @uptrace{SWS_CORE_01950, edc90e4963365acab366cd574b4375f5f7291021}
    template <typename U,
        std::size_t N,
        typename = typename std::enable_if<(Extent == dynamic_extent || Extent == N)
            && std::is_convertible<U (*)[], element_type (*)[]>::value>::type*>
    constexpr Span(Span<U, N> const& s) noexcept
        : Span(s.data(), s.size())
    {
        xtrace("__ converting ctor from N ", N, "\n");
    }

    /// @uptrace{SWS_CORE_01951, bdf8b8c98db0a6679f2810e7805308c251cc5525}
    ~Span() noexcept = default;

    /// @uptrace{SWS_CORE_01952, fc009f4b08a666661f13710112036b75730f04e7}
    constexpr Span& operator=(Span const& other) noexcept = default;

    // 21.7.3.3, subviews

    /// @uptrace{SWS_CORE_01961, db606c4837c85dcb2493533f811b5c7d781a63e7}
    template <std::size_t Count>
    constexpr Span<element_type, Count> first() const
    {
        static_assert(Count <= Extent, "Span::first out of bounds");
        assert(Count <= size());

        return {mData, Count};
    }

    /// @uptrace{SWS_CORE_01962, 7f2090bb290039a1e98ba6a180803dbf56d360ef}
    constexpr Span<element_type, dynamic_extent> first(size_type count) const
    {
        assert(count <= size());

        return {mData, count};
    }

    /// @uptrace{SWS_CORE_01963, 7d9c69b34bb7aba95b186061cc7a6e11a2ea9642}
    template <std::size_t Count>
    constexpr Span<element_type, Count> last() const
    {
        static_assert(Count <= Extent, "Span::last out of bounds");
        assert(Count <= size());

        return {mData + (size() - Count), Count};
    }

    /// @uptrace{SWS_CORE_01964, f35eec15c1d23385bcf3b542c25499ec6e88c871}
    constexpr Span<element_type, dynamic_extent> last(size_type count) const
    {
        assert(count <= size());

        return {mData + (size() - count), count};
    }

    /// @uptrace{SWS_CORE_01965, 587e377caf21da820d809a43262e95e654c8d503}
    template <std::size_t Offset, std::size_t Count = dynamic_extent>
    constexpr auto subspan() const -> Span<element_type,
        (Count != dynamic_extent) ? Count : (Extent != dynamic_extent ? Extent - Offset : dynamic_extent)>
    {
        static_assert(
            Offset <= Extent && (Count == dynamic_extent || Count <= Extent - Offset), "Span::subspan out of bounds");
        assert(Offset <= size());
        assert(Count == dynamic_extent || (Count <= size() - Offset));

        constexpr size_type E
            = (Count != dynamic_extent) ? Count : (Extent != dynamic_extent ? Extent - Offset : dynamic_extent);

        return Span<element_type, E>(mData + Offset, Count != dynamic_extent ? Count : size() - Offset);
    }

    /// @uptrace{SWS_CORE_01966, 6d49da72e655e058876c721229a329f7f19a67e8}
    constexpr Span<element_type, dynamic_extent> subspan(size_type offset, size_type count = dynamic_extent) const
    {
        assert(offset <= size());
        assert(count == dynamic_extent || (count <= size() - offset));

        return {mData + offset, count == dynamic_extent ? size() - offset : count};
    }

    // 21.7.3.4, observers

    /// @uptrace{SWS_CORE_01967, 04f36c20c6c244e55ea2ee3e82bb9ce89f7672fe}
    constexpr size_type size() const noexcept
    {
        return mExtent;
    }

    /// @uptrace{SWS_CORE_01968, d625f3d1233c47f05229e032b8f56f00c660dd54}
    constexpr size_type size_bytes() const noexcept
    {
        return mExtent * sizeof(T);
    }

    /// @uptrace{SWS_CORE_01969, ec32828e81beadcc07a4054dd5b5463a7a3dbcfd}
    constexpr bool empty() const noexcept
    {
        return mExtent == 0;
    }

    // 21.7.3.5, element access

    /// @uptrace{SWS_CORE_01970, 7a793f2a9f57e3fb114503520f9dbeaeeb9a8649}
    constexpr reference operator[](size_type idx) const
    {
        return mData[idx];
    }

    /// @uptrace{SWS_CORE_01959, 9711bcbe7bcbefb343d6b9abd6a6039a40d4dfb9}
    constexpr reference front() const
    {
        return mData[0];
    }

    /// @uptrace{SWS_CORE_01960, abdba4521b99b03600ffd09e0c80d391168d38ca}
    constexpr reference back() const
    {
        return mData[size() - 1];
    }

    /// @uptrace{SWS_CORE_01971, bc2f7550d99e1e5546c24e16e65e3df1fa1367e4}
    constexpr pointer data() const noexcept
    {
        return mData;
    }

    // 21.7.3.6, iterator support

    /// @uptrace{SWS_CORE_01972, d7be4e0aebc251f7143e0232e2cdce6180cab5c7}
    constexpr iterator begin() const noexcept
    {
        return &mData[0];
    }

    /// @uptrace{SWS_CORE_01973, 7a4f6a6ba0f955efd7d6edc01898ac6942839e57}
    constexpr iterator end() const noexcept
    {
        return &mData[mExtent];
    }

    /// @uptrace{SWS_CORE_01974, 649b93a62b7ed1b1787290de41b4639be98abee7}
    constexpr const_iterator cbegin() const noexcept
    {
        return &mData[0];
    }

    /// @uptrace{SWS_CORE_01975, e5820f115dfb6ab2599ed9bcef718d1596ce959e}
    constexpr const_iterator cend() const noexcept
    {
        return &mData[mExtent];
    }

    /// @uptrace{SWS_CORE_01976, add5fbb0350bea6f6eddae0a8cce1ceff2c29dd8}
    constexpr reverse_iterator rbegin() const noexcept
    {
        return reverse_iterator(end());
    }

    /// @uptrace{SWS_CORE_01977, 38ed0990b8ff0ff0472da6c23216a4137a143f52}
    constexpr reverse_iterator rend() const noexcept
    {
        return reverse_iterator(begin());
    }

    /// @uptrace{SWS_CORE_01978, f429fba841211d41024870a2fec302a036980d3e}
    constexpr const_reverse_iterator crbegin() const noexcept
    {
        return const_reverse_iterator(end());
    }

    /// @uptrace{SWS_CORE_01979, da26f35e4d0f5d2a335b6dfcda59c3528bf4e6a5}
    constexpr const_reverse_iterator crend() const noexcept
    {
        return const_reverse_iterator(begin());
    }

private:
    pointer mData;
    size_type mExtent;
};

#if defined(__cpp_deduction_guides) && (__cpp_deduction_guides - 0) >= 201703L
template <typename T, std::size_t N>
Span(T (&)[N]) -> Span<T, N>;

template <typename T, std::size_t N>
Span(Array<T, N>&) -> Span<T, N>;

template <typename T, std::size_t N>
Span(Array<T, N> const&) -> Span<T const, N>;

template <typename Container>
Span(Container&) -> Span<typename Container::value_type>;

template <typename Container>
Span(Container const&) -> Span<const typename Container::value_type>;
#endif  // C++17 deduction guides

/// @uptrace{SWS_CORE_01980, dc3709014b6ce20ccd1d8e30023e326c694c82d3}
template <typename ElementType, std::size_t Extent>
Span<Byte const, Extent == dynamic_extent ? dynamic_extent : sizeof(ElementType) * Extent>  //
as_bytes(Span<ElementType, Extent> s) noexcept
{
    return {reinterpret_cast<Byte const*>(s.data()), s.size_bytes()};
}

/// @uptrace{SWS_CORE_01981, 9f6d892c419666cbbf211605094e6b06394fed13}
template <typename ElementType, std::size_t Extent>
Span<Byte, Extent == dynamic_extent ? dynamic_extent : sizeof(ElementType) * Extent>  //
as_writable_bytes(Span<ElementType, Extent> s) noexcept
{
    return {reinterpret_cast<Byte*>(s.data()), s.size_bytes()};
}

/// @uptrace{SWS_CORE_01990, 3b57b4ba049a397236eae0152a39d258534e022b}
template <typename T>
constexpr Span<T> MakeSpan(T* ptr, typename Span<T>::size_type count)
{
    return Span<T>(ptr, count);
}

/// @uptrace{SWS_CORE_01991, fc9f232e8af1c0152b46851f611100ac4dc75acd}
template <typename T>
constexpr Span<T> MakeSpan(T* firstElem, T* lastElem)
{
    return Span<T>(firstElem, lastElem);
}

/// @uptrace{SWS_CORE_01992, a1747452dbeb507a65f224b88aa29583e0d0b334}
template <typename T, std::size_t N>
constexpr Span<T, N> MakeSpan(T (&arr)[N]) noexcept
{
    return Span<T, N>(arr);
}

/// @uptrace{SWS_CORE_01993, 320d07f8e35477628f7a67c3fad4dfb42531fe3a}
template <typename Container>
constexpr Span<typename Container::value_type> MakeSpan(Container& cont)
{
    return Span<typename Container::value_type>(cont);
}

/// @uptrace{SWS_CORE_01994, c193df3da54cc83c0c42cca9d449c36f535ae230}
template <typename Container>
constexpr Span<typename Container::value_type const> MakeSpan(Container const& cont)
{
    return Span<typename Container::value_type const>(cont);
}

}  // namespace core
}  // namespace ara

#endif  // APD_ARA_CORE_SPAN_H_
