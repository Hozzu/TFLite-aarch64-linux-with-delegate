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

#ifndef APD_ARA_CORE_STRING_VIEW_H_
#define APD_ARA_CORE_STRING_VIEW_H_

#include "ara/core/abort.h"

#include <string>
#include <limits>
#include <iterator>
#include <iostream>
#include <utility>
#include <limits>
#include <type_traits>
#include <stdexcept>
#include <cstddef>

namespace ara
{
namespace core
{
namespace internal
{

#ifdef __GNUC__
#    define APD_GCC_CONSTEXPR constexpr
#else
#    define APD_GCC_CONSTEXPR
#endif

template <typename CharT, typename Traits = std::char_traits<CharT>>
class basic_string_view
{
public:
    using traits_type = Traits;
    using value_type = CharT;
    using pointer = CharT*;
    using const_pointer = CharT const*;
    using reference = CharT&;
    using const_reference = CharT const&;
    using const_iterator = CharT const*;
    using iterator = const_iterator;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;
    using reverse_iterator = const_reverse_iterator;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    constexpr static size_type npos = size_type(-1);

    // Traits::length() only becomes 'constexpr' with C++17, so we use our own implementation
    // that is always 'constexpr' as long as gcc is being used.
    APD_GCC_CONSTEXPR static size_type length(CharT const* text) noexcept
    {
#ifdef __GNUC__
        return __builtin_strlen(text);
#else
        return Traits::length(text);
#endif
    }

    // Traits::compare() only becomes 'constexpr' with C++17, so we use our own implementation
    // that is always 'constexpr' as long as gcc is being used.
    APD_GCC_CONSTEXPR static int compare(CharT const* s1, CharT const* s2, size_t n) noexcept
    {
#ifdef __GNUC__
        return __builtin_strncmp(s1, s2, n);
#else
        return Traits::compare(s1, s2, n);
#endif
    }

public:
    // 24.4.2.1, construction and assignment
    constexpr basic_string_view() noexcept
        : basic_string_view(nullptr, 0)
    { }

    constexpr basic_string_view(const_pointer p, size_type count)
        : mPtr(p)
        , mSize(count)
    { }

    constexpr basic_string_view(const_pointer p)
        : basic_string_view(p, p == nullptr ? 0 : length(p))
    { }

    constexpr basic_string_view(basic_string_view const& other) noexcept = default;

    // Not "constexpr" because that would make it also "const" on C++11 compilers.
    basic_string_view& operator=(basic_string_view const& other) noexcept = default;

    // 24.4.2.2, iterator support
    constexpr const_iterator begin() const noexcept
    {
        return mPtr;
    }
    constexpr const_iterator cbegin() const noexcept
    {
        return mPtr;
    }
    constexpr const_iterator end() const noexcept
    {
        return mPtr + mSize;
    }
    constexpr const_iterator cend() const noexcept
    {
        return mPtr + mSize;
    }
    constexpr const_reverse_iterator rbegin() const noexcept
    {
        return const_reverse_iterator(end());
    }
    constexpr const_reverse_iterator crbegin() const noexcept
    {
        return const_reverse_iterator(end());
    }
    constexpr const_reverse_iterator rend() const noexcept
    {
        return const_reverse_iterator(begin());
    }
    constexpr const_reverse_iterator crend() const noexcept
    {
        return const_reverse_iterator(begin());
    }

    // 24.4.2.3, capacity
    constexpr size_type size() const noexcept
    {
        return mSize;
    }
    constexpr size_type length() const noexcept
    {
        return mSize;
    }
    constexpr size_type max_size() const noexcept
    {
        // TODO: not for wchar!
        return std::numeric_limits<size_type>::max();
    }
    constexpr bool empty() const noexcept
    {
        return mSize == 0;
    }

    // 24.4.2.4, element access
    constexpr const_reference operator[](size_type pos) const
    {
        return mPtr[pos];
    }
    constexpr const_reference at(size_type pos) const
    {
        if (pos >= mSize) {
#ifndef ARA_NO_EXCEPTIONS
            throw std::out_of_range("out of range");
#else
            Abort("StringView::at out of range");
#endif
        }
        return mPtr[pos];
    }
    constexpr const_reference front() const
    {
        return mPtr[0];
    }
    constexpr const_reference back() const
    {
        return mPtr[mSize - 1];
    }
    constexpr const_pointer data() const noexcept
    {
        return mPtr;
    }

    // 24.4.2.5, modifiers
    // Not "constexpr" because that would make it also "const" on C++11 compilers.
    void remove_prefix(size_type n)
    {
        mPtr += n;
        mSize -= n;
    }
    // Not "constexpr" because that would make it also "const" on C++11 compilers.
    void remove_suffix(size_type n)
    {
        mSize -= n;
    }
    // Not "constexpr" because that would make it also "const" on C++11 compilers.
    void swap(basic_string_view& other) noexcept
    {
        std::swap(mPtr, other.mPtr);
        std::swap(mSize, other.mSize);
    }

    // 24.4.2.6, operations
    size_type copy(CharT* dest, size_type count, size_type pos = 0) const
    {
        if (pos > mSize) {
#ifndef ARA_NO_EXCEPTIONS
            throw std::out_of_range("out of range");
#else
            Abort("StringView::copy out of range");
#endif
        }

        size_t const rcount = std::min(count, mSize - pos);
        std::copy(mPtr + pos, mPtr + pos + rcount, dest);
        return rcount;
    }
    constexpr basic_string_view substr(size_type pos = 0, size_type count = npos) const
    {
        if (pos > mSize) {
#ifndef ARA_NO_EXCEPTIONS
            throw std::out_of_range("out of range");
#else
            Abort("StringView::substr out of range");
#endif
        }

        size_t const rcount = std::min(count, mSize - pos);
        return basic_string_view(mPtr + pos, rcount);
    }
    constexpr int compare(basic_string_view v) const noexcept
    {
        int ret = compare(mPtr, v.mPtr, std::min(mSize, v.mSize));
        if (ret == 0) {
            return (mSize < v.mSize) ? -1 : (mSize > v.mSize);
        }
        return ret;
    }
    constexpr int compare(size_type pos1, size_type count1, basic_string_view v) const
    {
        return substr(pos1, count1).compare(v);
    }
    constexpr int compare(size_type pos1, size_type count1, basic_string_view v, size_type pos2, size_type count2) const
    {
        return substr(pos1, count1).compare(v.substr(pos2, count2));
    }
    constexpr int compare(const_pointer s) const
    {
        return compare(basic_string_view(s));
    }
    constexpr int compare(size_type pos1, size_type count1, const_pointer s) const
    {
        return substr(pos1, count1).compare(basic_string_view(s));
    }
    constexpr int compare(size_type pos1, size_type count1, const_pointer s, size_type count2) const
    {
        return substr(pos1, count1).compare(basic_string_view(s, count2));
    }

    size_type find(basic_string_view v, size_type pos = 0) const noexcept
    {
        return find(v.data(), pos, v.size());
    }
    size_type find(CharT ch, size_type pos = 0) const noexcept
    {
        return std::basic_string<CharT, Traits>(mPtr, mSize).find(ch, pos);
    }
    size_type find(const_pointer s, size_type pos, size_type count) const
    {
        return std::basic_string<CharT, Traits>(mPtr, mSize).find(s, pos, count);
    }
    size_type find(const_pointer s, size_type pos = 0) const
    {
        return find(s, pos, length(s));
    }

    size_type rfind(basic_string_view v, size_type pos = npos) const noexcept
    {
        return rfind(v.data(), pos, v.size());
    }
    size_type rfind(CharT c, size_type pos = npos) const noexcept
    {
        return std::basic_string<CharT, Traits>(mPtr, mSize).rfind(c, pos);
    }
    size_type rfind(const_pointer s, size_type pos, size_type count) const
    {
        return std::basic_string<CharT, Traits>(mPtr, mSize).rfind(s, pos, count);
    }
    size_type rfind(const_pointer s, size_type pos = npos) const
    {
        return rfind(s, pos, length(s));
    }

    size_type find_first_of(basic_string_view v, size_type pos = 0) const noexcept
    {
        return find_first_of(v.data(), pos, v.size());
    }
    size_type find_first_of(CharT c, size_type pos = 0) const noexcept
    {
        return std::basic_string<CharT, Traits>(mPtr, mSize).find_first_of(c, pos);
    }
    size_type find_first_of(const_pointer s, size_type pos, size_type count) const
    {
        return std::basic_string<CharT, Traits>(mPtr, mSize).find_first_of(s, pos, count);
    }
    size_type find_first_of(const_pointer s, size_type pos = 0) const
    {
        return find_first_of(s, pos, length(s));
    }

    size_type find_last_of(basic_string_view v, size_type pos = npos) const noexcept
    {
        return find_last_of(v.data(), pos, v.size());
    }
    size_type find_last_of(CharT c, size_type pos = npos) const noexcept
    {
        return std::basic_string<CharT, Traits>(mPtr, mSize).find_last_of(c, pos);
    }
    size_type find_last_of(const_pointer s, size_type pos, size_type count) const
    {
        return std::basic_string<CharT, Traits>(mPtr, mSize).find_last_of(s, pos, count);
    }
    size_type find_last_of(const_pointer s, size_type pos = npos) const
    {
        return find_last_of(s, pos, length(s));
    }

    size_type find_first_not_of(basic_string_view v, size_type pos = 0) const noexcept
    {
        return find_first_not_of(v.data(), pos, v.size());
    }
    size_type find_first_not_of(CharT c, size_type pos = 0) const noexcept
    {
        return std::basic_string<CharT, Traits>(mPtr, mSize).find_first_not_of(c, pos);
    }
    size_type find_first_not_of(const_pointer s, size_type pos, size_type count) const
    {
        return std::basic_string<CharT, Traits>(mPtr, mSize).find_first_not_of(s, pos, count);
    }
    size_type find_first_not_of(const_pointer s, size_type pos = 0) const
    {
        return find_first_not_of(s, pos, length(s));
    }

    size_type find_last_not_of(basic_string_view v, size_type pos = npos) const noexcept
    {
        return find_last_not_of(v.data(), pos, v.size());
    }
    size_type find_last_not_of(CharT c, size_type pos = npos) const noexcept
    {
        return std::basic_string<CharT, Traits>(mPtr, mSize).find_last_not_of(c, pos);
    }
    size_type find_last_not_of(const_pointer s, size_type pos, size_type count) const
    {
        return std::basic_string<CharT, Traits>(mPtr, mSize).find_last_not_of(s, pos, count);
    }
    size_type find_last_not_of(const_pointer s, size_type pos = npos) const
    {
        return find_last_not_of(s, pos, length(s));
    }

private:
    CharT const* mPtr;
    size_type mSize;
};

// 24.4.4, inserters and extractors
template <typename CharT, typename Traits>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os,
    basic_string_view<CharT, Traits> const& v)
{
    typename std::basic_ostream<CharT, Traits>::sentry s(os);
    if (s) {
        // In case the argument's width does not fit into a 'streamsize', truncate it.
        std::size_t const maxSize = static_cast<std::size_t>(std::numeric_limits<std::streamsize>::max());
        std::size_t const outputSize = (v.size() <= maxSize) ? v.size() : maxSize;

        std::streamsize const vsize = static_cast<std::streamsize>(outputSize);
        std::streamsize const width = os.width();
        if (width > vsize) {
            // Stream width is wider than text - must left- or right-align.
            auto fill = [&os](std::streamsize num) {
                CharT const ch = os.fill();
                auto rdbuf = os.rdbuf();
                while (num--) {
                    std::ostream::int_type const ret = rdbuf->sputc(ch);
                    if (Traits::eq_int_type(ret, Traits::eof())) {
                        os.setstate(std::ios_base::badbit);
                        break;
                    }
                }
            };

            bool const isLeft = ((os.flags() & std::ios_base::adjustfield) == std::ios_base::left);
            if (!isLeft) {
                fill(width - vsize);
            }

            if (os.good()) {
                os.write(v.data(), vsize);
            }

            if (isLeft && os.good()) {
                fill(width - vsize);
            }
        } else {
            // Text is as long or longer than the defined stream width - just output the whole thing.
            os.write(v.data(), vsize);
        }
    }
    return os;
}

// 24.4.3, non-member comparison functions,
//         incl. additional overloads

// Helper type for forcing template argument deduction to proceed based on
// only one of the arguments to a comparison operator. See n3766 for details.
template <typename T>
using Identity = typename std::decay<T>::type;

template <typename CharT, typename Traits>
constexpr bool operator==(basic_string_view<CharT, Traits> lhs, basic_string_view<CharT, Traits> rhs) noexcept
{
    return lhs.compare(rhs) == 0;
}
template <typename CharT, typename Traits>
constexpr bool operator==(basic_string_view<CharT, Traits> lhs, Identity<basic_string_view<CharT, Traits>> rhs) noexcept
{
    return lhs.compare(rhs) == 0;
}
template <typename CharT, typename Traits>
constexpr bool operator==(Identity<basic_string_view<CharT, Traits>> lhs, basic_string_view<CharT, Traits> rhs) noexcept
{
    return lhs.compare(rhs) == 0;
}

template <typename CharT, typename Traits>
constexpr bool operator!=(basic_string_view<CharT, Traits> lhs, basic_string_view<CharT, Traits> rhs) noexcept
{
    return lhs.compare(rhs) != 0;
}
template <typename CharT, typename Traits>
constexpr bool operator!=(basic_string_view<CharT, Traits> lhs, Identity<basic_string_view<CharT, Traits>> rhs) noexcept
{
    return lhs.compare(rhs) != 0;
}
template <typename CharT, typename Traits>
constexpr bool operator!=(Identity<basic_string_view<CharT, Traits>> lhs, basic_string_view<CharT, Traits> rhs) noexcept
{
    return lhs.compare(rhs) != 0;
}

template <typename CharT, typename Traits>
constexpr bool operator<(basic_string_view<CharT, Traits> lhs, basic_string_view<CharT, Traits> rhs) noexcept
{
    return lhs.compare(rhs) < 0;
}
template <typename CharT, typename Traits>
constexpr bool operator<(basic_string_view<CharT, Traits> lhs, Identity<basic_string_view<CharT, Traits>> rhs) noexcept
{
    return lhs.compare(rhs) < 0;
}
template <typename CharT, typename Traits>
constexpr bool operator<(Identity<basic_string_view<CharT, Traits>> lhs, basic_string_view<CharT, Traits> rhs) noexcept
{
    return lhs.compare(rhs) < 0;
}

template <typename CharT, typename Traits>
constexpr bool operator>(basic_string_view<CharT, Traits> lhs, basic_string_view<CharT, Traits> rhs) noexcept
{
    return lhs.compare(rhs) > 0;
}
template <typename CharT, typename Traits>
constexpr bool operator>(basic_string_view<CharT, Traits> lhs, Identity<basic_string_view<CharT, Traits>> rhs) noexcept
{
    return lhs.compare(rhs) > 0;
}
template <typename CharT, typename Traits>
constexpr bool operator>(Identity<basic_string_view<CharT, Traits>> lhs, basic_string_view<CharT, Traits> rhs) noexcept
{
    return lhs.compare(rhs) > 0;
}

template <typename CharT, typename Traits>
constexpr bool operator<=(basic_string_view<CharT, Traits> lhs, basic_string_view<CharT, Traits> rhs) noexcept
{
    return lhs.compare(rhs) <= 0;
}
template <typename CharT, typename Traits>
constexpr bool operator<=(basic_string_view<CharT, Traits> lhs, Identity<basic_string_view<CharT, Traits>> rhs) noexcept
{
    return lhs.compare(rhs) <= 0;
}
template <typename CharT, typename Traits>
constexpr bool operator<=(Identity<basic_string_view<CharT, Traits>> lhs, basic_string_view<CharT, Traits> rhs) noexcept
{
    return lhs.compare(rhs) <= 0;
}

template <typename CharT, typename Traits>
constexpr bool operator>=(basic_string_view<CharT, Traits> lhs, basic_string_view<CharT, Traits> rhs) noexcept
{
    return lhs.compare(rhs) >= 0;
}
template <typename CharT, typename Traits>
constexpr bool operator>=(basic_string_view<CharT, Traits> lhs, Identity<basic_string_view<CharT, Traits>> rhs) noexcept
{
    return lhs.compare(rhs) >= 0;
}
template <typename CharT, typename Traits>
constexpr bool operator>=(Identity<basic_string_view<CharT, Traits>> lhs, basic_string_view<CharT, Traits> rhs) noexcept
{
    return lhs.compare(rhs) >= 0;
}

#undef APD_GCC_CONSTEXPR

}  // namespace internal

/// @brief A read-only view over a contiguous sequence of characters.
///
/// @uptrace{SWS_CORE_02001, 8a65f3afe3952a094efba71590079c6132e7dff9}
using StringView = internal::basic_string_view<char>;

}  // namespace core
}  // namespace ara

#endif  // APD_ARA_CORE_STRING_VIEW_H_
