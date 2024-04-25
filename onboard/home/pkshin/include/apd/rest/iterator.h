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

#ifndef LIB_APDREST_INCLUDE_APD_REST_ITERATOR_H_
#define LIB_APDREST_INCLUDE_APD_REST_ITERATOR_H_

#include <iterator>
#include <type_traits>
#include <utility>

/// @cond DISABLED
#include <vector>  // for documentation only
/// @endcond

namespace apd
{
namespace rest
{

/// @cond DISABLE_THIS
struct unspecified_iterator_type : std::vector<int>::iterator
{ };
struct unspecified_functor_type
{
    template <typename... Ts>
    void operator()(Ts&&...) const;
};
/// @endcond

/// @cond DISABLE_THIS
template <typename IterT, typename TransT>
class TransformIterator : private TransT
{
    template <typename T>
    struct proxy_type
    {
        operator T*() const
        {
            return &t;
        }

    private:
        T t;
    };

public:
    using iterator_category = std::forward_iterator_tag;
    using self_type = TransformIterator;
    using base_iterator_type = IterT;
    using transformer_type = TransT;
    using value_type = typename base_iterator_type::value_type;
    using reference = typename base_iterator_type::reference;
    using pointer = typename base_iterator_type::pointer;
    using difference_type = typename base_iterator_type::difference_type;

    explicit TransformIterator(base_iterator_type i, const transformer_type& x = {})
        : TransT{x}
        , mIter{i}
    { }

    self_type operator++(int)
    {
        auto cp = *this;
        mIter++;
        return cp;
    }
    self_type& operator++()
    {
        mIter++;
        return *this;
    }

    decltype(std::declval<TransT>()(std::declval<value_type>()))& operator*() const
    {
        return this->operator()(*mIter);
    }

    base_iterator_type base() const
    {
        return (*mIter).base();
    }

    base_iterator_type GetBaseIterator() const
    {
        return mIter;
    }

    friend bool operator==(const self_type& a, const self_type& b)
    {
        return a.mIter == b.mIter;
    }
    friend bool operator!=(const self_type& a, const self_type& b)
    {
        return !(a == b);
    }

private:
    base_iterator_type mIter;
};

template <typename IterT, typename TransT>
TransformIterator<IterT, TransT> MakeTransformIterator(IterT i, const TransT& t)
{
    return TransformIterator<IterT, TransT>(i, t);
}

/// @endcond

/** An iterator range
 *
 * IteratorRange is a simple wrapper for a pair of standard iterators. Usually an entire
 * sequence is accessed from first to its last element. Iterators are tedious since the user
 * is forced to pass around two objects. Wrapping in std::pair<> is even more tedious since
 * range-based for loops will expect functions begin()/end() to exist. Conceptually this type
 * is just a pair with accessors begin()/end(). This type also allows to conveniently access
 * different views of the same sequence. Otherwise a sequence would only have a single pair
 * of begin()/end().
 *
 *
 */
template <typename IterT>
struct IteratorRange
{
    using Iterator = IterT;  ///< Type of the underlying pair of iterators

    /**
     * \brief Constructs an IteratorRange from a pair of iterators
     *
     *  For convenient construction, see MakeIteratorRange().
     *
     *  \param first an iterator denoting the start of the sequence
     *  \param last an iterator denoting the end of the sequence
     */
    IteratorRange(Iterator first, Iterator last)
        : mBegin(first)
        , mEnd(last)
    { }

    /** \brief Returns the start of the sequence
     *
     *  \return an iterator
     */
    Iterator begin() const
    {
        return mBegin;
    }

    /** \brief Returns the end of the sequence
     *
     *  \return an iterator
     */
    Iterator end() const
    {
        return mEnd;
    }

    /** \brief Non-member equivalent of IteratorRange::begin()
     *  \param r an InteratorRange
     *  \return the start of the sequence
     */
    friend Iterator begin(const IteratorRange& r)
    {
        return r.mBegin;
    }

    /** \brief Non-member equivalent of IteratorRange::end()
     *  \param r an InteratorRange
     *  \return the end of the sequence
     */
    friend Iterator end(const IteratorRange& r)
    {
        return r.mEnd;
    }

private:
    Iterator mBegin;
    Iterator mEnd;
};

/** \brief Helper for type deduction to construct an IteratorRange
 *
 *  \param a iterator that denotes the start of the sequence
 *  \param b iterator that denotes the end of the sequence
 *  \return an IteratorRange
 */
template <typename IterT>
IteratorRange<IterT> MakeIteratorRange(IterT a, IterT b)
{
    return IteratorRange<IterT>{a, b};
}

}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_ITERATOR_H_
