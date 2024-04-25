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

#ifndef APD_ARA_CORE_ABORT_H_
#define APD_ARA_CORE_ABORT_H_

namespace ara
{
namespace core
{

/// @uptrace{SWS_CORE_00053, 53461e5139811c3283cf5bb8e4452320800a5ee1}
void AbortHandlerPrototype() noexcept;

/// @uptrace{SWS_CORE_00050, 4d1108b3e08cf3dc61a2ececbb2975dda011c402}
using AbortHandler = decltype(&AbortHandlerPrototype);

/// @uptrace{SWS_CORE_00051, 53ebeb137b8f3d624dcedb61d5fabd83006be914}
AbortHandler SetAbortHandler(AbortHandler handler) noexcept;

/// @uptrace{SWS_CORE_00052, c9a1c5f36b660d23602f6f956241ea43ca94e12a}
[[noreturn]] void Abort(char const* text) noexcept;

}  // namespace core
}  // namespace ara

#endif  // APD_ARA_CORE_ABORT_H_
