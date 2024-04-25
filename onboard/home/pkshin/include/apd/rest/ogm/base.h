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

#ifndef LIB_APDREST_INCLUDE_APD_REST_OGM_BASE_H_
#define LIB_APDREST_INCLUDE_APD_REST_OGM_BASE_H_

#include <memory>
#include <utility>

#include "apd/rest/allocator.h"
#include "apd/rest/pointer.h"

namespace apd
{

namespace rest
{

namespace ogm
{

namespace details
{

/**
 * Type-system support
 */

/** \brief function description
 *
 *  Detailed description
 *
 *  \param param
 *  \return return type
 */
template <typename To, typename From>
constexpr bool isa(From* u) noexcept
{
    return To::classof(u);
}

/** \brief function description
 *
 *  unchecked cast; non-const
 *
 *  \param param
 *  \return return type
 */
template <typename To, typename From>
constexpr To* cast(From* u) noexcept
{
    return static_cast<To*>(u);
}

/** \brief function description
 *
 *  unchecked cast, const
 *
 *  \param param
 *  \return return type
 */
template <typename To, typename From>
constexpr const To* cast(const From* u) noexcept
{
    return static_cast<const To*>(u);
}

}  // namespace details

/**
 * node type enumeration
 */
enum class NodeType : std::uint_least8_t
{
    // Special types
    Undefined,  //!< Undefined
    Field,  //!< Field

    // Value types
    ValueTypesStart,  //!< ValueTypesStart

    Int,  //!< Int
    Real,  //!< Real
    String,  //!< String
    Uri,  //!< Uri
    Uuid,  //!< Uuid
    Array,  //!< Array
    Object,  //!< Object

    ValueTypesEnd,  //!< ValueTypesEnd
};

/**
 * \brief CommonBase class
 */
class CommonBase
{
public:
    /**
     * \brief get allocator
     *
     * \return TODO
     */
    Allocator* GetAllocator()
    {
        return alloc_;
    }

    /**
     * \brief get allocator
     *
     * \return TODO
     */
    const Allocator* GetAllocator() const
    {
        return alloc_;
    }

protected:
    /**
     * \brief allocator constructor
     *
     * \param alloc TODO
     */
    explicit CommonBase(Allocator* alloc)
        : alloc_(alloc)
    { }

    /**
     * \brief destructor
     */
    virtual ~CommonBase()
    { }

private:
    /**
     * \brief pointer to allocator
     */
    Allocator* alloc_;
};

template <typename NodeT, typename ParentT, bool is_constructible = true>
class Base;

/**
 * \brief base class
 */
template <typename NodeT, typename ParentT>
class Base<NodeT, ParentT, true>
{
public:
    /**
     * needs documentation
     */
    using SelfType = NodeT;

    /**
     * needs documentation
     */
    using ParentType = ParentT;

    /**
     * \brief create object of SelfType
     */
    template <typename... Ts>
    static Pointer<SelfType> Make(Ts&&... ts)
    {
        return Pointer<SelfType>{new SelfType(std::forward<Ts>(ts)...)};
    }

    /**
     * \brief create object of SelfType
     */
    template <typename... Ts>
    static Pointer<SelfType> Make(Allocator* alloc, Ts&&... ts)
    {
        return Pointer<SelfType>{new SelfType(alloc, std::forward<Ts>(ts)...)};
    }

    /**
     * \brief get parent
     *
     * \return TODO
     */
    ParentType* GetParent()
    {
        return parent_;
    }

    /**
     * \brief get parent
     */
    const ParentType* GetParent() const
    {
        return parent_;
    }

    /**
     * \brief has parent
     */
    bool HasParent() const
    {
        return parent_ != nullptr;
    }

protected:
    /**
     * \brief pointer to parent node
     */
    Base() = default;

    /**
     * \brief pointer to parent node
     */
    ParentType* parent_ = nullptr;
};

/**
 * \brief base class
 */
template <typename NodeT, typename ParentT>
class Base<NodeT, ParentT, false>
{
public:
    /**
     * needs documentation
     */
    using SelfType = NodeT;

    /**
     * needs documentation
     */
    using ParentType = ParentT;

    /**
     * \brief get parent
     *
     * \return TODO
     */
    ParentType* GetParent()
    {
        return nullptr;
    }

    /**
     * \brief get parent
     */
    const ParentType* GetParent() const
    {
        return nullptr;
    }

    /**
     * \brief has parent
     */
    bool HasParent() const
    {
        return false;
    }
};

}  // namespace ogm

}  // namespace rest

}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_OGM_BASE_H_
