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

#ifndef LIB_APDREST_INCLUDE_APD_REST_OGM_ARRAY_H_
#define LIB_APDREST_INCLUDE_APD_REST_OGM_ARRAY_H_

#include <cstring>
#include <initializer_list>
#include <iterator>
#include <utility>
#include <vector>

#include "apd/rest/allocator.h"
#include "apd/rest/iterator.h"
#include "apd/rest/ogm/base.h"
#include "apd/rest/ogm/node.h"
#include "apd/rest/ogm/value.h"
#include "apd/rest/pointer.h"

namespace apd
{

namespace rest
{

namespace ogm
{

/**
 * \brief This class represents Array nodes in the OGM
 *
 * This type is similar to an Object except that it represents a set of "unnamed" Value
 * instances. Hence Field is not allowed to be attached to Array objects.
 * \uptrace{SWS_REST_02036}
 */
class Array
    : public Value
    , public Base<Array, Value>
{
    friend class Base<Array, Value>;

public:
    /**
     * \brief field type
     */
    using ValueType = Pointer<Value>;

    /**
     * \brief fields type
     */
    using ValueContainerType = std::vector<ValueType>;

    /**
     * \brief TransformOperator
     */
    struct TransformOperator
    {
        /**
         * \brief operator for transformation
         * \param arg input of transformation, a value_type of ValuesType
         * \return output of transformation, a dereferenced unique ptr
         */
        Value& operator()(const ValueContainerType::value_type& arg) const noexcept
        {
            return *arg;
        }
    };

    /**
     * \brief Value iterator
     *
     *  Iterator::value_type must of type Value*.
     */
    using Iterator = TransformIterator<ValueContainerType::iterator, TransformOperator>;

    /**
     * \brief Value iterator
     *
     *  Iterator::value_type must of type Value*.
     */
    using ConstIterator = TransformIterator<ValueContainerType::const_iterator, TransformOperator>;

    /**
     * needs documentation
     */
    using ValueRange = IteratorRange<Iterator>;

    /**
     * needs documentation
     */
    using ConstValueRange = IteratorRange<ConstIterator>;

    /**
     * \brief get size
     *
     * \return std::size_t TODO
     */
    std::size_t GetSize() const
    {
        return values_.size();
    }

    /**
     * \brief is empty
     *
     * \return bool TODO
     */
    bool IsEmpty() const
    {
        return values_.size() == 0;
    }

    /**
     * \brief get value
     *
     * \param size TODO
     * \return TODO
     */
    Value& GetValue(std::size_t size)
    {
        return *(values_.at(size));
    }

    /**
     * \brief get value
     *
     * \param size TODO
     * \return TODO
     */
    const Value& GetValue(std::size_t size) const
    {
        return *(values_.at(size));
    }

    /**
     * \brief get values
     */
    ValueRange GetValues()
    {
        return ValueRange{Iterator{values_.begin()}, Iterator{values_.end()}};
    }

    /**
     * \brief get values
     */
    ConstValueRange GetValues() const
    {
        return ConstValueRange{ConstIterator{values_.begin()}, ConstIterator{values_.end()}};
    }

    /**
     * \brief append value to array
     *
     * \see http://scottmeyers.blogspot.de/2014/07/should-move-only-types-ever-be-passed.html
     * \param value pointer TODO
     */
    void Append(Pointer<Value>&& value)
    {
        values_.emplace_back(std::move(value));
    }

    /**
     * \brief insert value to array at specific index
     *
     * \param iter TODO
     * \param value TODO
     */
    void Insert(Iterator iter, Pointer<Value>&& value)
    {
        values_.insert(iter.GetBaseIterator(), std::move(value));
    }

    /**
     * \brief Removes value from the set
     *
     * Removes an element from the set. Removal invalidates all iterators referencing
     * the respective element.
     *
     * \param iter an iterator pointing to an element.
     * \return an iterator pointing to the element following the one just removed.
     */
    Iterator Remove(Iterator iter)
    {
        if (iter != GetValues().end()) {
            /* remove the element from the values_ list */
            return Iterator{values_.erase(iter.GetBaseIterator())};
        }
        return iter;
    }

    /**
     * \brief release
     *
     * \param iter an iterator pointing to an element
     * \return a pair of iterator and pointer to a value
     */
    std::pair<Iterator, Pointer<Value>> Release(Iterator iter)
    {
        Pointer<Value> tmp = std::move(*(iter.GetBaseIterator()));
        auto it = values_.erase(iter.GetBaseIterator());
        return {Iterator{it}, std::move(tmp)};
    }

    /**
     * \brief replace
     *
     * \param iter an iterator pointing to an element.
     * \param value TODO
     * \return TODO
     */
    Pointer<Value> Replace(Iterator iter, Pointer<Value>&& value)
    {
        /* store the current element temporary */
        auto tmp{iter.GetBaseIterator()->release()};
        /* update value */
        iter.GetBaseIterator()->reset(value.release());
        /* return the old element */
        return Pointer<Value>{tmp};
    }

    /**
     * \brief clear - remove all values from the set
     */
    void Clear()
    {
        values_.clear();
    }

    /**
     * Check if types of nodes are matching
     * \param o
     * \return true if type of o matches this class type
     */
    static bool classof(const Node* o)
    {
        return o->type() == NodeType::Array;
    }

protected:
    /**
     * \brief constructor with allocator parameter
     */
    explicit Array(Allocator* alloc = GetDefaultAllocator())
        : Value(alloc, NodeType::Array)
    { }

    /**
     * \brief templated constructor with pointer parameter
     *
     * cannot use initializer_list
     *
     * \param ptr_args TODO
     */
    template <typename... Ts>
    explicit Array(Pointer<Ts>&&... ptr_args)
        : Value(NodeType::Array)
    {
        // We expand the parameter pack in a brace-enclosed initialized list
        int dummy[] = {0, (values_.emplace_back(std::move(ptr_args)), 0)...};
        ignore(dummy);
    }

    /**
     * \brief templated constructor with allocator and pointer parameter
     *
     * cannot use initializer_list
     * \param alloc TODO
     * \param ptr_args TODO
     */
    template <typename... Ts>
    Array(Allocator* alloc, Pointer<Ts>&&... ptr_args)
        : Value(alloc, NodeType::Array)
    {
        Object(std::forward<Ts>(ptr_args)...);
    }

private:
    ValueContainerType values_;

    template <typename T>
    void ignore(T&&) const
    { }
};

}  // namespace ogm

}  // namespace rest

}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_OGM_ARRAY_H_
