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

#ifndef LIB_APDREST_INCLUDE_APD_REST_STRING_H_
#define LIB_APDREST_INCLUDE_APD_REST_STRING_H_

#include <cstdint>
#include <memory>
#include <string>
#if __cplusplus > 201103L
#    include <experimental/string_view>
#endif

#include "apd/rest/allocator.h"

namespace apd
{
namespace rest
{

/** \brief Equivalent of std::basic_string but with a custom apd::rest::Allocator adaptor
 *
 *  Detailed description
 *
 *  \param param
 *  \return return type
 *  \uptrace{SWS_REST_02356}
 */
template <typename CharT, typename TraitsT = std::char_traits<CharT>>
using BasicString = std::basic_string<CharT, TraitsT, std::allocator<CharT>>;

/**
 * \brief typedef for string.
 * \uptrace{SWS_REST_02357}
 */
using String = BasicString<char>;

// With C++14, the code does not compile, as the code assumes there to be
// a converting constructor from string_view to stringstream.
#if __cplusplus > 201402L

/**
 * \brief typedef for StringView.
 */
template <typename CharT, typename TraitsT = std::char_traits<CharT>>
using BasicStringView = std::experimental::basic_string_view<CharT, TraitsT>;

#else

/**
 * \brief typedef for StringView.
 */
template <typename CharT, typename TraitsT = std::char_traits<CharT>>
using BasicStringView = BasicString<CharT, TraitsT>;

#endif

/**
 * \brief typedef for StringView.
 * \uptrace{SWS_REST_02359}
 */
using StringView = BasicStringView<char>;

}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_STRING_H_
