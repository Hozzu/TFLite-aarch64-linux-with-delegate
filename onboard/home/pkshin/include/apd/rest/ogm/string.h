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

#ifndef LIB_APDREST_INCLUDE_APD_REST_OGM_STRING_H_
#define LIB_APDREST_INCLUDE_APD_REST_OGM_STRING_H_

#include "apd/rest/allocator.h"
#include "apd/rest/ogm/base.h"
#include "apd/rest/ogm/value.h"
#include "apd/rest/string.h"

namespace apd
{

namespace rest
{

namespace ogm
{

/**
 * \brief Represents textual value Nodes in the OGM
 * apd::rest::String::ValueType denotes its corresponding C++ data type.
 * Note that string encoding is ignored by apd::rest. A string is just a dynamic array.
 * The interpretation of encoding specific characters is not subject to the apd::rest specification.
 *
 * Internal static buffer size is implementation defined
 * 'String' does not get an allocator: either it's std::string, then its game over
 * or its a REST string, then that once carries its own allocator.
 * \uptrace{SWS_REST_02139}
 */
class String
    : public Value
    , public Base<String, Value>
{
    friend class Base<String, Value>;

public:
    /**
     * needs documentation
     */
    using ValueType = StringView;

    /**
     * \brief get value
     */
    ValueType GetValue() const
    {
        return value_;
    }

    /**
     * \brief set value
     *
     * \param v
     */
    void SetValue(const ValueType& v)
    {
        value_ = v;
    }

    /**
     * Check if types of nodes are matching
     * \param o
     * \return true if type of o matches this class type
     */
    static bool classof(const Node* o)
    {
        return o->type() == NodeType::String;
    }

protected:
    /**
     * \brief constructor with ValueType parameter
     *
     * must be std::string compatible
     *
     * \param value TODO
     */
    explicit String(ValueType value = ValueType{})
        : Value(NodeType::String)
        , value_(value)
    { }

    /**
     * \brief constructor with allocator and value parameter
     *
     * must be std::string compatible
     *
     * \param alloc TODO
     * \param value TODO
     */
    explicit String(Allocator* alloc, ValueType value = ValueType{})
        : Value(NodeType::String)
        , value_(value)
    {
        (void)alloc;
    }

private:
    /**
     * \brief value
     */
    ValueType value_;
};

}  // namespace ogm

}  // namespace rest

}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_OGM_STRING_H_
