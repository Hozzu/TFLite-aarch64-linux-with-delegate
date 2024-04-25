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

#ifndef ARA_PER_TRAITS_WRAPPER_H_
#define ARA_PER_TRAITS_WRAPPER_H_

// This header abstracts the http://en.cppreference.com/w/cpp/string/char_traits
// implementation so that the ara-fileaccess functions do not depend eg. on the
// fstream implementation, and the implementation can be done in platform specific
// way.

#include <fstream>

namespace ara
{
namespace per
{
/// @brief Position in a file or number of characters, used in file storage operations. Unsigned type similar to
/// std::char_traits::pos_type.
///
using pos_type = std::fstream::pos_type;

/// @brief Offset in a file, used in file storage operations. Signed type similar to std::char_traits::off_type.
///
using off_type = std::fstream::off_type;

/// @brief Character value read from a file, used in file storage operations. Signed type similar
/// std::char_traits::int_type.
///
using int_type = std::fstream::int_type;
}  // namespace per
}  // namespace ara

#endif  // ARA_PER_TRAITS_WRAPPER_H_
