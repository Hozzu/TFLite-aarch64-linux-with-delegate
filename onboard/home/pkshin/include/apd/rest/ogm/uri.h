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

#ifndef LIB_APDREST_INCLUDE_APD_REST_OGM_URI_H_
#define LIB_APDREST_INCLUDE_APD_REST_OGM_URI_H_

#include <utility>

#include "apd/rest/allocator.h"
#include "apd/rest/ogm/base.h"
#include "apd/rest/ogm/value.h"
#include "apd/rest/uri.h"

namespace apd
{

namespace rest
{

namespace ogm
{

/**
 * \brief This class represents Uri nodes in the OGM
 */
class Uri
    : public Value
    , public Base<Uri, Value>
{
    friend class Base<Uri, Value>;

public:
    /**
     * needs documentation
     */
    using ValueType = apd::rest::Uri;

    /**
     * \brief get
     *
     * \return uri object
     */
    const ValueType& GetValue() const noexcept
    {
        return uri_;
    }

    /**
     * \brief set
     *
     * \param value uri object
     */
    void SetValue(ValueType& value)
    {
        uri_ = value;
    }

    /**
     * \brief set
     *
     * \param value uri object
     */
    void SetValue(ValueType&& value)
    {
        uri_ = std::move(value);
    }

    /**
     * Check if types of nodes are matching
     * \param o
     * \return true if type of o matches this class type
     */
    static bool classof(const Node* o)
    {
        return o->type() == NodeType::Uri;
    }

protected:
    /**
     * \brief function description
     * Detailed description
     *
     * \param u TODO
     * \return return type
     */
    explicit Uri(const apd::rest::Uri& u)
        : Value(NodeType::Uri)
        , uri_(u)
    { }

    /**
     * \brief function description
     * Detailed description
     *
     * \param u TODO
     * \return return type
     */
    explicit Uri(apd::rest::Uri&& u)
        : Value(NodeType::Uri)
        , uri_(std::move(u))
    { }

private:
    /**
     * \brief uri object
     */
    ValueType uri_;
};

}  // namespace ogm

}  // namespace rest

}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_OGM_URI_H_
