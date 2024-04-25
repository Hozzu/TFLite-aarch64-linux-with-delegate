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

#ifndef LIB_APDREST_INCLUDE_APD_REST_OGM_FIELD_H_
#define LIB_APDREST_INCLUDE_APD_REST_OGM_FIELD_H_

#include <climits>
#include <utility>

#include "apd/rest/allocator.h"
#include "apd/rest/ogm/base.h"
#include "apd/rest/ogm/node.h"
#include "apd/rest/ogm/value.h"
#include "apd/rest/pointer.h"
#include "apd/rest/string.h"

namespace apd
{

namespace rest
{

namespace ogm
{

/**
 * \brief This class represents Field nodes in the OGM
 *
 * Represents a "named" Value instance and is only used in conjunction with Object.
 * Effectively a Field is a pair of a name and a handle to a Value type.
 * At some later time, we need to figure out how to configure this
 * to have non-string keys.
 *
 * Note that field keys could be cached as well a ViWi-specific keyword cache.
 *
 * Ideally, keys are integral IDs of course. At some point, we need to figure
 * out how to provide those.
 * \uptrace{SWS_REST_02062}
 */
class Field
    : public Node
    , public Base<Field, Node>
{
public:
    friend class Base<Field, Node>;

    /**
     * \brief constructor
     *
     * \param name TODO
     * \param value TODO
     */
    Field(const apd::rest::String& name, Pointer<Value>&& value)
        : Node(NodeType::Field)
        , name_(name)
        , value_(std::move(value))
    { }

    /**
     * \brief constructor
     *
     * \param alloc TODO
     * \param name TODO
     * \param value TODO
     */
    Field(Allocator* alloc, const apd::rest::String& name, Pointer<Value>&& value)
        : Node(NodeType::Field)
        , name_(name)
        , value_(std::move(value))
    {
        (void)alloc;
    }

    /**
     * \brief get name
     *
     * \return TODO
     */
    const apd::rest::String& GetName() const
    {
        return name_;
    }

    /**
     * \brief set name
     *
     * \param name TODO
     */
    void SetName(const apd::rest::String& name)
    {
        name_ = name;
    }

    /**
     * \brief get value
     *
     * \return TODO
     */
    const Value& GetValue() const
    {
        return *value_;
    }

    /**
     * \brief get value
     *
     * \return TODO
     */
    Value& GetValue()
    {
        return *value_;
    }

    /**
     * \brief set value
     *
     * \param v TODO
     */
    void SetValue(Pointer<Value>&& v)
    {
        value_.reset(v.release());
    }

    /**
     * \brief replace value
     *
     * a field can never be without a value
     *
     * \param v TODO
     * \return TODO
     */
    Pointer<Value> ReplaceValue(Pointer<Value>&& v)
    {
        /* store the current element temporary */
        auto tmp{value_.release()};
        /* update value */
        value_.reset(v.release());
        /* return the old element */
        return Pointer<Value>{tmp};
    }

    /**
     * Check if types of nodes are matching
     * \param o
     * \return true if type of o matches this class type
     */
    static bool classof(const Node* o)
    {
        return o->type() == NodeType::Field;
    }

private:
    /**
     * \brief name
     */
    apd::rest::String name_;

    /**
     * \brief unique pointer to value
     */
    Pointer<Value> value_;
};

}  // namespace ogm

}  // namespace rest

}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_OGM_FIELD_H_
