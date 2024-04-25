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

#ifndef ARA_COM_PROXY_FIRE_AND_FORGET_METHOD_H
#define ARA_COM_PROXY_FIRE_AND_FORGET_METHOD_H

#include "method_base.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace proxy
{

/// \addtogroup frontendproxybase
/// @{

/// \brief Defines the typed interface of all fire and forget method elements on proxy side.
/// A template argument list is not allowed in a declaration of a primary template.
template <typename T>
class FireAndForgetMethod;

template <typename... Args>
class FireAndForgetMethod<void(Args...)> : public virtual bits::MethodBase
{
public:
    using signature_type = void(Args...);
    using result_type = void;

    /// \brief Call the method at the server side.
    /// \param args Arguments that are passed to the method. It depends on the generated code what types they have and
    /// how many they are.
    /// \return void
    /// @uptrace{SWS_CM_90435, bba13147a6f63a2044003be53bee57228a135218}
    virtual void operator()(Args&&... args) = 0;
};

/// @}

}  // namespace proxy
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_PROXY_FIRE_AND_FORGET_METHOD_H
