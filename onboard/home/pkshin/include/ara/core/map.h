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

/**
 * @file
 * @brief Interface to class ara::core::map
 */

#ifndef APD_ARA_CORE_MAP_H_
#define APD_ARA_CORE_MAP_H_

#include <map>
#include <memory>
#include <type_traits>
#include <utility>

namespace ara
{
namespace core
{

/**
 * @brief A container that contains key-value pairs with unique keys
 *
 * @tparam Key  the type of keys in this Map
 * @tparam T  the type of values in this Map
 * @tparam Compare  the type of comparison Callable
 * @tparam Allocator  the type of Allocator to use for this container
 *
 * @uptrace{SWS_CORE_01400, 94d9fe3a0689321d3baa39267872e0fc9f8499d1}
 */
template <typename Key,
    typename T,
    typename Compare = std::less<Key>,
    typename Allocator = std::allocator<std::pair<const Key, T>>>
using Map = std::map<Key, T, Compare, Allocator>;

/// @brief Add overload of std::swap for Map.
///
/// We actually don't need this overload at all, because our implementation is just
/// a type alias and thus can simply use the overload for the std:: type.
/// However, we need this symbol in order to provide uptracing.
///
/// @tparam Key  the type of keys in the Maps
/// @tparam T  the type of values in the Maps
/// @tparam Compare  the type of comparison Callables in the Maps
/// @tparam Allocator  the type of Allocators in the Maps
/// @param lhs  the first argument of the swap invocation
/// @param rhs  the second argument of the swap invocation
///
/// @uptrace{SWS_CORE_01496, e5d4643e01610322b791e64488f600651e44c93b}
template <typename Key,
    typename T,
    typename Compare,
    typename Allocator,
    typename = typename std::enable_if<
        !std::is_same<Map<Key, T, Compare, Allocator>, std::map<Key, T, Compare, Allocator>>::value>::type>
void swap(Map<Key, T, Compare, Allocator>& lhs, Map<Key, T, Compare, Allocator>& rhs)
{
    lhs.swap(rhs);
}

}  // namespace core
}  // namespace ara

#endif  // APD_ARA_CORE_MAP_H_
