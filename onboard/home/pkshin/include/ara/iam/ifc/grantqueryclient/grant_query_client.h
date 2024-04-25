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

/// @file
/// @brief Implementation for the grant query client with an async call

#ifndef ARA_IAM_IFC_GRANTQUERYCLIENT_GRANT_GRANT_QUERY_CLIENT_H_
#define ARA_IAM_IFC_GRANTQUERYCLIENT_GRANT_GRANT_QUERY_CLIENT_H_

#include <type_traits>
#include <thread>
#include "ara/core/promise.h"
#include "ara/core/future.h"
#include "ara/iam/ifc/grant/grant.h"
#include "ara/iam/ifc/grantqueryclient/grant_query_client_error_domain.h"
#include "ara/iam/ifc/grantqueryclient/grant_query_client_impl.h"

namespace ara
{
namespace iam
{
namespace ifc
{
namespace grantqueryclient
{
namespace internal
{
/// @brief Checks if a grant has been given
///
/// @tparam TGRANT Type T must be a child class of ara::iam::ifc::grant::Grant which is copy constructable.
/// @tparam TQUERYCLIENT Queryclient (usually ara::iam::ifc::grantqueryclient::IAMGrantQueryClientImpl) but may be
/// replaced for testing purposes.
/// @param grant Grant
/// @return true, if the grant has been given.
///         false if not. In case of an error
///         of type GrantQueryClientErrc is returned.
template <typename TGRANT, typename TQUERYCLIENT>
inline ara::core::Future<bool> HasGrantInternal(const TGRANT& grant)
{
    // Check the type of T to get a more detailed error
    // message instead of a normal compiler error if T is not
    // allowed.

    // A real copy of T is needed. A copy can only exists for
    // instances other than ara::iam::ifc::grant::Grant since
    // this type has no copy constructor.
    static_assert(std::is_copy_constructible<TGRANT>::value, "Type TGRANT shall be copy constructable");

    // T must be a child class of ara::iam::ifc::grant::Grant
    static_assert(std::is_base_of<ara::iam::ifc::grant::Grant, TGRANT>::value,
        "Type TGRANT shall be a child class of ara::iam::ifc::grant::Grant");

    ara::core::Promise<bool> promise;
    ara::core::Future<bool> future = promise.get_future();
    std::thread(
        [](ara::core::Promise<bool>&& p, const TGRANT grant_) {
            ara::core::Result<bool> res = TQUERYCLIENT().HasGrant(grant_);
            if (res.HasValue()) {
                p.set_value(std::move(res.Value()));
            } else {
                p.SetError(std::move(res.Error()));
            }
        },
        std::move(promise),
        grant)
        .detach();

    return future;
}
}  // namespace internal

/// @brief HasGrant cannot be called with base type ara::iam::ifc::grant::Grant
///
/// @param grant deleted
/// @return deleted
ara::core::Future<bool> HasGrant(const ara::iam::ifc::grant::Grant& grant) = delete;

/// @brief Checks if a grant has been given
///
/// @tparam T Type T must be a child class of ara::iam::ifc::grant::Grant
///         which is copy constructable.
/// @param grant Grant
/// @return true, if the grant has been given.
///         false if not. In case of an error
///         of type GrantQueryClientErrc is returned.
template <typename T>
inline ara::core::Future<bool> HasGrant(const T& grant)
{
    return internal::HasGrantInternal<T, ara::iam::ifc::grantqueryclient::IAMGrantQueryClientImpl>(grant);
}

}  // namespace grantqueryclient
}  // namespace ifc
}  // namespace iam
}  // namespace ara

#endif  // ARA_IAM_IFC_GRANTQUERYCLIENT_GRANT_GRANT_QUERY_CLIENT_H_
