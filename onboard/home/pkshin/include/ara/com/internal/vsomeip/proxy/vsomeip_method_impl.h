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
 */

#ifndef VSOMEIP_PROXY_METHOD_IMPL_H
#define VSOMEIP_PROXY_METHOD_IMPL_H

#include <vsomeip/vsomeip.hpp>

#include "vsomeip_method_impl_delegate.h"

#include "ara/com/internal/proxy/method.h"
#include "ara/core/future.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace vsomeip
{
namespace proxy
{
/**
 * \addtogroup vsomeipproxyimpl
 *
 * @{
 */

/**
 * \brief Method implementation for vsomeip proxy binding
 */
// Declare the template MethodImpl without an implementation for the general case to force a compilation error if
// MethodImpl is used with anything else than a MethodDescriptor and a function signature
template <typename MethodDescriptor, typename T>
class MethodImpl;

// Template specialization for MethodImpl using a method descriptor and a function signature
template <typename MethodDescriptor, typename R, typename... Args>
class MethodImpl<MethodDescriptor, R(Args...)> : public internal::proxy::Method<R(Args...)>
{
public:
    using Base = internal::proxy::Method<R(Args...)>;
    using typename Base::result_type;

    /**
     * \param instance Instance used for creating the object
     */
    explicit MethodImpl(types::InstanceId instance)
        : delegate_(std::make_shared<DelegateType>(instance))
    {
        auto delegate = std::weak_ptr<DelegateType>(delegate_);
        common::registerMethodHandler(MethodDescriptor::service_id,
            delegate_->instance(),
            MethodDescriptor::method_id,
            [delegate](const std::shared_ptr<::vsomeip::message>& response) {
                if (auto p = delegate.lock()) {
                    p->handleCallResult(response);
                }
            });
    }

    ~MethodImpl() override
    {
        common::unregisterMethodHandler(
            MethodDescriptor::service_id, delegate_->instance(), MethodDescriptor::method_id);
    }

    virtual ara::core::Future<result_type> operator()(Args&&... args)
    {
        return delegate_->startCall(std::forward<Args>(args)...);
    }

private:
    using DelegateType = MethodImplDelegate<MethodDescriptor, result_type>;
    std::shared_ptr<DelegateType> delegate_;
};
/**
 * @}
 */
}  // namespace proxy
}  // namespace vsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // VSOMEIP_PROXY_METHOD_IMPL_H
