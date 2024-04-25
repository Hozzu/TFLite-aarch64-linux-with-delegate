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

#ifndef LIB_APDREST_INCLUDE_APD_REST_OGM_NODE_H_
#define LIB_APDREST_INCLUDE_APD_REST_OGM_NODE_H_

#include "apd/rest/allocator.h"
#include "apd/rest/ogm/base.h"
#include "apd/rest/pointer.h"

namespace apd
{

namespace rest
{

namespace ogm
{

/**
 * A Node serves as a base type for runtime polymorphic operations only. It also restricts
 * C++ semantics. The default constructor of Node must be protected and all other constructors and copy- or
 * move-assignment operators must be deleted. A Node must have public virtual destructor.
 * non-copyable (there is Node::Copy)
 * \uptrace{SWS_REST_02089}
 */
class Node
    : public CommonBase
    , public Base<Node, void, false>
{
public:
    /**
     * \brief destructor
     */
    virtual ~Node() = default;

    /**
     * \brief delete copy constructor
     */
    Node(const Node&) = delete;

    /**
     * \brief delete assign constructor
     */
    Node& operator=(const Node&) = delete;

    /**
     * \brief move constructor
     */
    Node(Node&&) = default;

    /**
     * \brief move constructor
     */
    Node& operator=(Node&&) = default;

    /**
     * Check if types of nodes are matching
     * \return true
     */
    static bool classof(const Node*)
    {
        return true;
    }

    /**
     * \brief get the node's type
     * @return
     */
    NodeType type() const
    {
        return node_type_;
    }

protected:
    /**
     * \brief constructor
     * \param node_type type of node
     * non-user-constructible
     */
    explicit Node(NodeType node_type) noexcept
        : CommonBase(nullptr)
        , node_type_(node_type)
    { }

    /**
     * \brief constructor
     * \param alloc allocator
     * \param node_type type of node
     * non-user-constructible
     */
    Node(Allocator* alloc, NodeType node_type) noexcept
        : CommonBase(alloc)
        , node_type_(node_type)
    { }

private:
    /**
     * \brief the type of the node
     */
    NodeType node_type_;
};

}  // namespace ogm

}  // namespace rest

}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_OGM_NODE_H_
