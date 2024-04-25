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

#ifndef LIB_APDREST_INCLUDE_APD_REST_OGM_UUID_H_
#define LIB_APDREST_INCLUDE_APD_REST_OGM_UUID_H_

#include <cstdint>
#include <utility>

#include "apd/rest/allocator.h"
#include "apd/rest/ogm/base.h"
#include "apd/rest/ogm/value.h"
#include "apd/rest/string.h"
#include "apd/rest/uuid.h"

namespace apd
{

namespace rest
{

namespace ogm
{

/**
 * \brief This class represents Uuid nodes in the OGM
 */
class Uuid
    : public Value
    , public Base<Uuid, Value>
{
    friend Base<Uuid, Value>;

public:
    /**
     * needs documentation
     */
    using ValueType = apd::rest::Uuid;

    /**
     * \brief get
     *
     * \return uuid object
     */
    const ValueType& GetValue() const noexcept
    {
        return uuid_;
    }

    /**
     * \brief set
     *
     * \param value uuid object
     */
    void SetValue(const ValueType& value)
    {
        uuid_ = value;
    }

    /**
     * \brief function description
     * Detailed description
     *
     * \param value
     * \return return type
     */
    void SetValue(ValueType&& value)
    {
        uuid_ = std::move(value);
    }

    /**
     * Check if types of nodes are matching
     * \param o
     * \return true if type of o matches this class type
     */
    static bool classof(const Node* o)
    {
        return o->type() == NodeType::Uuid;
    }

protected:
    /**
     * \brief function description
     * Detailed description
     *
     * \param u TODO
     * \return return type
     */
    explicit Uuid(const apd::rest::Uuid& u)
        : Value(NodeType::Uuid)
        , uuid_(u)
    { }

    /**
     * \brief function description
     * Detailed description
     *
     * \param u TODO
     * \return return type
     */
    explicit Uuid(apd::rest::Uuid&& u)
        : Value(NodeType::Uuid)
        , uuid_(std::move(u))
    { }

private:
    /**
     * \brief uuid object
     */
    ValueType uuid_;
};

}  // namespace ogm

}  // namespace rest

}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_OGM_UUID_H_
