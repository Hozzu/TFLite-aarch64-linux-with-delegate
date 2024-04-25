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
 * @brief Interface to class ara::core::Vector
 */

#ifndef APD_ARA_CORE_VECTOR_H_
#define APD_ARA_CORE_VECTOR_H_

#include <vector>
#include <memory>
#include <type_traits>

namespace ara
{
namespace core
{

/**
 * @brief A sequence container that encapsulates dynamically sized arrays
 *
 * @tparam T  the type of contained values
 * @tparam Allocator  the type of Allocator to use for this container
 *
 * @uptrace{SWS_CORE_01301, 63e6bf08d90ba1bed8caa2f71a1596679c9a17ad}
 */
template <typename T, typename Allocator = std::allocator<T>>
using Vector = std::vector<T, Allocator>;

/**
 * @brief Global operator== for Vector instances
 *
 * @uptrace{SWS_CORE_01390, e02aa3d390fc42d5687ffd92aead0f85088639b8}
 */
template <typename T,
    typename Allocator,
    typename = typename std::enable_if<!std::is_same<Vector<T, Allocator>, std::vector<T, Allocator>>::value>::type>
inline bool operator==(Vector<T, Allocator> const& lhs, Vector<T, Allocator> const& rhs)
{
    return std::operator==(lhs, rhs);
}

/**
 * @brief Global operator!= for Vector instances
 *
 * @uptrace{SWS_CORE_01391, df78a3a80201338d5ce34435f46139ee53083fee}
 */
template <typename T,
    typename Allocator,
    typename = typename std::enable_if<!std::is_same<Vector<T, Allocator>, std::vector<T, Allocator>>::value>::type>
inline bool operator!=(Vector<T, Allocator> const& lhs, Vector<T, Allocator> const& rhs)
{
    return std::operator!=(lhs, rhs);
}

/**
 * @brief Global operator< for Vector instances
 *
 * @uptrace{SWS_CORE_01392, fe0d98b1b74008afc070285835ab28447828b130}
 */
template <typename T,
    typename Allocator,
    typename = typename std::enable_if<!std::is_same<Vector<T, Allocator>, std::vector<T, Allocator>>::value>::type>
inline bool operator<(Vector<T, Allocator> const& lhs, Vector<T, Allocator> const& rhs)
{
    return std::operator<(lhs, rhs);
}

/**
 * @brief Global operator<= for Vector instances
 *
 * @uptrace{SWS_CORE_01393, c2a2f3ab26b884a0af68c73ad9c990e8991cf3d3}
 */
template <typename T,
    typename Allocator,
    typename = typename std::enable_if<!std::is_same<Vector<T, Allocator>, std::vector<T, Allocator>>::value>::type>
inline bool operator<=(Vector<T, Allocator> const& lhs, Vector<T, Allocator> const& rhs)
{
    return std::operator<=(lhs, rhs);
}

/**
 * @brief Global operator> for Vector instances
 *
 * @uptrace{SWS_CORE_01394, 119438b2f7f710f8cc8cef206ed6eecd67d5d551}
 */
template <typename T,
    typename Allocator,
    typename = typename std::enable_if<!std::is_same<Vector<T, Allocator>, std::vector<T, Allocator>>::value>::type>
inline bool operator>(Vector<T, Allocator> const& lhs, Vector<T, Allocator> const& rhs)
{
    return std::operator>(lhs, rhs);
}

/**
 * @brief Global operator>= for Vector instances
 *
 * @uptrace{SWS_CORE_01395, adb944bb5a2ceb3512956a9f70ab43e61e52c87d}
 */
template <typename T,
    typename Allocator,
    typename = typename std::enable_if<!std::is_same<Vector<T, Allocator>, std::vector<T, Allocator>>::value>::type>
inline bool operator>=(Vector<T, Allocator> const& lhs, Vector<T, Allocator> const& rhs)
{
    return std::operator>=(lhs, rhs);
}

/**
 * @brief Add overload of swap for ara::core::Vector
 *
 * We actually don't need this overload at all, because our implementation is just
 * a type alias and thus can simply use the overload for the std:: type.
 * However, we need this symbol in order to provide uptracing.
 *
 * @tparam T  the type of values in the Vectors
 * @tparam Allocator  the Allocator used by the Vectors
 * @param lhs  the first argument of the swap invocation
 * @param rhs  the second argument of the swap invocation
 *
 * @uptrace{SWS_CORE_01396, 87be53107398a0b8568411638e2297387545584f}
 */
template <typename T,
    typename Allocator,
    typename = typename std::enable_if<!std::is_same<Vector<T, Allocator>, std::vector<T, Allocator>>::value>::type>
void swap(Vector<T, Allocator>& lhs, Vector<T, Allocator>& rhs)
{
    lhs.swap(rhs);
}

}  // namespace core
}  // namespace ara

#endif  // APD_ARA_CORE_VECTOR_H_
