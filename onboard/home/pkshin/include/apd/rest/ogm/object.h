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

#ifndef LIB_APDREST_INCLUDE_APD_REST_OGM_OBJECT_H_
#define LIB_APDREST_INCLUDE_APD_REST_OGM_OBJECT_H_

#include <utility>
#include <vector>

#include "apd/rest/allocator.h"
#include "apd/rest/iterator.h"
#include "apd/rest/ogm/base.h"
#include "apd/rest/ogm/field.h"
#include "apd/rest/ogm/value.h"
#include "apd/rest/pointer.h"

namespace apd
{

namespace rest
{

namespace ogm
{

/**
 * \brief This class represents Object nodes in the OGM
 *  Represents a record. All apd::rest payloads must have an Object as their top-level type.
 *  A record may only be composed of "named" Value instances, by means of Field.
 *  As opposed to Array: unordered but random access.
 * \uptrace{SWS_REST_02101}
 */
class Object
    : public Value
    , public Base<Object, Value>
{
    friend class Base<Object, Value>;

public:
    /**
     * \brief field type
     */
    using FieldType = Pointer<Field>;

    /**
     * \brief fields type
     */
    using FieldContainerType = std::vector<FieldType>;

    /**
     * \brief TransformOperator
     */
    struct TransformOperator
    {
        /**
         * \brief operator for transformation
         * \param arg input of transformation, a value_type of Fieldstype
         * \return output of transformation, a dereferenced unique ptr
         */
        Field& operator()(const FieldContainerType::value_type& arg) const noexcept
        {
            return *arg;
        }
    };

    /**
     * \brief Value iterator
     *
     *  Iterator::value_type must of type Value*.
     */
    using Iterator = TransformIterator<FieldContainerType::iterator, TransformOperator>;

    /**
     * \brief Value iterator
     *
     *  Iterator::value_type must of type Value*.
     */
    using ConstIterator = TransformIterator<FieldContainerType::const_iterator, TransformOperator>;

    /**
     * needs documentation
     */
    using FieldRange = IteratorRange<Iterator>;

    /**
     * needs documentation
     */
    using ConstFieldRange = IteratorRange<ConstIterator>;

    /**
     * \brief get size
     *
     * \return TODO
     */
    std::size_t GetSize() const
    {
        return fields_.size();
    }

    /**
     * \brief is empty
     *
     * \return true if set is empty otherwise false
     */
    bool IsEmpty() const
    {
        return fields_.size() == 0;
    }

    /**
     * \brief get fields
     */
    FieldRange GetFields()
    {
        return FieldRange{Iterator{fields_.begin()}, Iterator{fields_.end()}};
    }

    /**
     * \brief get fields
     */
    ConstFieldRange GetFields() const
    {
        return ConstFieldRange{ConstIterator{fields_.begin()}, ConstIterator{fields_.end()}};
    }

    /**
     * \brief has field
     *
     * \param str_view TODO
     * \return true if field is available otherwise false
     */
    bool HasField(StringView str_view) const
    {
        auto it = Find(str_view);
        return it != GetFields().end();
    }

    /**
     * \brief find
     *
     * \param str_view TODO
     * \return an iterator
     */
    Iterator Find(StringView str_view)
    {
        for (auto i(fields_.begin()), ie(fields_.end()); i != ie; ++i) {
            if (str_view == (*i).get()->GetName()) {
                return Iterator{i};
            }
        }
        return Iterator{fields_.end()};
    }

    /**
     * \brief find
     *
     * \param str_view TODO
     * \return an iterator
     */
    ConstIterator Find(StringView str_view) const
    {
        for (auto i(fields_.begin()), ie(fields_.end()); i != ie; ++i) {
            if (str_view == (*i).get()->GetName()) {
                return ConstIterator{i};
            }
        }
        return ConstIterator{fields_.end()};
    }

    /**
     * \brief find
     *
     * \param field TODO
     */
    void Insert(Pointer<Field>&& field)
    {
        fields_.emplace_back(std::move(field));
    }

    /**
     * \brief Removes value from the set
     *
     *  Removes an element from the set. Removal invalidates all iterators referencing
     *  the respective element.
     *
     *  \param iter an iterator pointing to an element.
     *  \return an iterator pointing to the element following the one just removed.
     */
    Iterator Remove(Iterator iter)
    {
        if (iter != GetFields().end()) {
            /* remove the element from the fields_ list */
            return Iterator{fields_.erase(iter.GetBaseIterator())};
        }
        return iter;
    }

    /**
     * \brief release
     *
     * \param iter an iterator pointing to an element
     * \return a pair of iterator and pointer to a field
     */
    std::pair<Iterator, Pointer<Field>> Release(Iterator iter)
    {
        Pointer<Field> tmp = std::move(*(iter.GetBaseIterator()));
        auto it = fields_.erase(iter.GetBaseIterator());
        return {Iterator{it}, std::move(tmp)};
    }

    /**
     * \brief replace
     *
     * \param iter an iterator pointing to an element.
     * \param field TODO
     * \return TODO
     */
    Pointer<Field> Replace(Iterator iter, Pointer<Field>&& field)
    {
        /* store the current element temporary */
        auto tmp{iter.GetBaseIterator()->release()};
        /* update value */
        iter.GetBaseIterator()->reset(field.release());
        /* return the old element */
        return Pointer<Field>{tmp};
    }

    /**
     * \brief clear - remove all fields from the set
     */
    void Clear()
    {
        fields_.clear();
    }

    /**
     * Check if types of nodes are matching
     * \param o
     * \return true if type of o matches this class type
     */
    static bool classof(const Node* o)
    {
        return o->type() == NodeType::Object;
    }

protected:
    /**
     * \brief constructor with allocator parameter
     *
     * \param alloc TODO
     */
    explicit Object(Allocator* alloc = GetDefaultAllocator())
        : Value(NodeType::Object)
    {
        (void)alloc;
    }

    /**
     * \brief templated constructor with pointer parameter
     *
     * cannot use initializer_list
     *
     * \param ts_args TODO
     */
    template <typename... Ts>
    explicit Object(Pointer<Ts>&&... ts_args)
        : Value(NodeType::Object)
    {
        // We expand the parameter pack in a brace-enclosed initialized list
        int dummy[] = {0, (Insert(std::move(ts_args)), 0)...};
        ignore(dummy);
    }

    /**
     * \brief templated constructor with allocator and pointer parameter
     *
     * cannot use initializer_list

     * \param alloc TODO
     * \param ts_args TODO
     */
    template <typename... Ts>
    explicit Object(Allocator* alloc, Pointer<Ts>&... ts_args)
        : Value(NodeType::Object)
    {
        (void)alloc;
        Object(std::forward<Ts>(ts_args)...);  // NOLINT // due to explicit warning, somehow cpplint got confused here
    }

private:
    FieldContainerType fields_;

    template <typename T>
    void ignore(T&&) const noexcept
    { }
};

}  // namespace ogm

}  // namespace rest

}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_OGM_OBJECT_H_
