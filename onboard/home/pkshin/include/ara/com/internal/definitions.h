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
 * \file
 * \brief Contains type definition used in ARA::COM reference implementation.
 */
#ifndef COMMUNICATIONMIDDLEWARE_DEFINITIONS_H
#define COMMUNICATIONMIDDLEWARE_DEFINITIONS_H

#include <cstdint>
#include <type_traits>

namespace ara
{
namespace com
{
namespace internal
{

template <typename T>
/**
 * \brief Shortcut to get base type of a template type (removing const/reference etc).
 */
using BaseType = typename std::decay<T>::type;

template <typename T>
struct MakeConstBaseRef
{
    /**
     * \brief Shortcut to get a const reference to the base type.
     */
    using type = const BaseType<T>&;
};

// Specialization for void as it is a syntax error to say "const void&"
template <>
struct MakeConstBaseRef<void>
{
    using type = void;
};

// Shortcut to use the MakeConstBaseRef struct to deduce the const reference to the base type of the given type.
template <typename T>
using ConstBaseRef = typename MakeConstBaseRef<T>::type;
/**
 * \brief Definition of service version type
 */
using ServiceVersion = std::uint32_t;

/**
 * \brief Definition of internal service ID type that should be binding agnostic.
 */
using ServiceId = std::uint16_t;

}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // COMMUNICATIONMIDDLEWARE_DEFINITIONS_H
