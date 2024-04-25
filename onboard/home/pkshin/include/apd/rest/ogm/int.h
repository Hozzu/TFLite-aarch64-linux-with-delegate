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

#ifndef LIB_APDREST_INCLUDE_APD_REST_OGM_INT_H_
#define LIB_APDREST_INCLUDE_APD_REST_OGM_INT_H_

#include "apd/rest/ogm/base.h"
#include "apd/rest/ogm/value.h"

namespace apd
{

namespace rest
{

namespace ogm
{

/**
 * \brief This class represents Int nodes in the OGM
 * \uptrace{SWS_REST_02077}
 */
class Int
    : public Value
    , public Base<Int, Value>
{
    friend class Base<Int, Value>;

public:
    /**
     * needs documentation
     */
    using ValueType = std::int64_t;

    /**
     * \brief get value
     *
     * \return value
     */
    ValueType GetValue() const
    {
        return value_;
    }

    /**
     * \brief set value
     *
     * \param v TODO
     */
    void SetValue(ValueType v)
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
        return o->type() == NodeType::Int;
    }

protected:
    /**
     * \brief provide allocator constructor
     *
     * \param value TODO
     */
    explicit Int(ValueType value = ValueType{})
        : Value(NodeType::Int)
        , value_(value)
    { }

private:
    /**
     * \brief value
     */
    ValueType value_;
};

}  // namespace ogm

}  // namespace rest

}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_OGM_INT_H_
