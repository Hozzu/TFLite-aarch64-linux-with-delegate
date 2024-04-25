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

#ifndef LIB_APDREST_INCLUDE_APD_REST_OGM_VISIT_H_
#define LIB_APDREST_INCLUDE_APD_REST_OGM_VISIT_H_

#include <cassert>
#include <memory>
#include <type_traits>
#include <utility>

#include "apd/rest/allocator.h"
#include "apd/rest/pointer.h"

#include "apd/rest/ogm/base.h"
// needed for visitation; inheritance relation must be known.
#include "apd/rest/ogm/array.h"
#include "apd/rest/ogm/field.h"
#include "apd/rest/ogm/int.h"
#include "apd/rest/ogm/object.h"
#include "apd/rest/ogm/real.h"
#include "apd/rest/ogm/string.h"
#include "apd/rest/ogm/uri.h"
#include "apd/rest/ogm/uuid.h"

namespace apd
{

namespace rest
{

namespace ogm
{

namespace details
{

/**
 * Overload
 * \brief inherit (linearly) from functors F
 */
template <typename F, typename... Fs>
struct overload /** @cond */
    : F
    , overload<Fs...> /** @endcond */
{
    using F::operator();
    using overload<Fs...>::operator();
    /**
     * overload
     * \brief TODO
     * \param f TODO
     * \param fs TODO
     */
    constexpr overload(F&& f, Fs&&... fs) noexcept
        : F(std::forward<F>(f))
        , overload<Fs...>(std::forward<Fs>(fs)...)
    { }
};

/**
 * Overload
 * \brief TODO
 */
template <typename F>
struct overload<F> : F
{
    using F::operator();
    /**
     * overload
     * \brief TODO
     * \param f TODO
     */
    constexpr explicit overload(F&& f) noexcept
        : F(std::forward<F>(f))
    { }
};

/**
 * make_overload
 * \brief TODO
 */
template <typename... Fs>
static constexpr auto make_overload(Fs&&... fs) noexcept -> overload<Fs...>
{
    return overload<Fs...>(std::forward<Fs>(fs)...);
}

/** \brief function description
 *
 *  Detailed description
 *
 *  \param param
 *  \return return type
 */
template <typename T, typename... Fs>
void VisitImpl(T* u, Fs&&... fs)
{
    auto visitor = details::make_overload(std::forward<Fs>(fs)..., [](...) {});

    switch (u->type()) {
    case NodeType::Field:
        visitor(details::cast<Field>(u));
        break;
    case NodeType::Int:
        visitor(details::cast<Int>(u));
        break;
    case NodeType::String:
        visitor(details::cast<String>(u));
        break;
    case NodeType::Real:
        visitor(details::cast<Real>(u));
        break;
    case NodeType::Array:
        visitor(details::cast<Array>(u));
        break;
    case NodeType::Uuid:
        visitor(details::cast<Uuid>(u));
        break;
    case NodeType::Uri:
        visitor(details::cast<Uri>(u));
        break;

    default:
        if (details::isa<Object>(u)) {
            visitor(details::cast<Object>(u));
        } else {
            assert(0 && "Unknown NodeType");
        }
    }
}

}  // namespace details

// trampolines for the *Impl versions in ::details

template <typename... Fs>
void Visit(Node* u, Fs&&... fs)
{
    details::VisitImpl(u, std::forward<Fs>(fs)...);
}

template <typename... Fs>
void Visit(const Node* u, Fs&&... fs)
{
    details::VisitImpl(u, std::forward<Fs>(fs)...);
}

template <typename T, typename... Fs>
void Visit(const apd::rest::Pointer<T>& u, Fs&&... fs)
{
    Visit(u.get(), std::forward<Fs>(fs)...);
}

}  // namespace ogm

}  // namespace rest

}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_OGM_VISIT_H_
