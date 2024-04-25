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

#ifndef COMMUNICATIONMIDDLEWARE_ARA_COM_INTERNAL_E2E_SHARED_PTR_H
#define COMMUNICATIONMIDDLEWARE_ARA_COM_INTERNAL_E2E_SHARED_PTR_H

#include <memory>
#include "ara/com/e2e/e2e_types.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace e2e
{

/// @brief Wrapper of std::shared_ptr that holds E2E check status and have getter function for its retrieval
///
/// This wrapper is intended tu be used as SamplePtr if E2E is enabled.
template <typename T>
class e2e_shared_ptr
{
public:
    using ProfileCheckStatus = ara::com::e2e::ProfileCheckStatus;

    /// @brief Constructs e2e_shared_ptr object by forwarding all supplied arguments to internal std::shared_ptr
    ///
    /// @param args arguments for std::shared_ptr construction
    template <typename... Args, std::enable_if_t<(sizeof...(Args) != 1), bool> = true>
    e2e_shared_ptr(Args&&... args)
        : ptr{std::make_shared<T>(std::forward<Args>(args)...)}
        , status{}
    { }

    /// @brief Constructs e2e_shared_ptr object from smart pointer-like object
    ///
    /// @param u smart pointer-like object
    template <class U, std::enable_if_t<std::is_base_of<e2e_shared_ptr, std::decay_t<U>>::value == false, bool> = true>
    e2e_shared_ptr(U&& u)
        : ptr{std::forward<U>(u)}
        , status{}
    { }

    /// @brief forward accsess to the object held by internal std::shared_ptr
    decltype(auto) operator*() const noexcept
    {
        return ptr.operator*();
    }

    /// @brief forward accsess to the object held by internal std::shared_ptr
    decltype(auto) operator->() const noexcept
    {
        return ptr.operator->();
    }

    /// @brief Get access to E2E CheckStatus information of the sample
    ///
    /// @return E2E check status of sample
    ///
    /// @uptrace{SWS_CM_90420, a67daf995037c552e445e380e10c5c7deb09db63}
    ProfileCheckStatus GetProfileCheckStatus() const noexcept
    {
        return status;
    }

private:
    std::shared_ptr<T> ptr;
    ProfileCheckStatus status;
};

}  // namespace e2e
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // COMMUNICATIONMIDDLEWARE_ARA_COM_INTERNAL_E2E_SHARED_PTR_HPP
