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

#ifndef VSOMEIP_PROXY_FIRE_AND_FORGET_METHOD_IMPL_H
#define VSOMEIP_PROXY_FIRE_AND_FORGET_METHOD_IMPL_H

#include <vsomeip/vsomeip.hpp>

#include "vsomeip_method_impl_delegate.h"

#include "ara/com/internal/proxy/fire_and_forget_method.h"
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

/// \addtogroup vsomeipproxyimpl
/// @{

/// \brief Method implementation for vsomeip proxy binding
// Declare the template FireAndForgetMethodImpl without an implementation for the general case to force a compilation
// error if FireAndForgetMethodImpl is used with anything else than a MethodDescriptor and a function signature
template <typename MethodDescriptor, typename T>
class FireAndForgetMethodImpl;

// Template specialization for FireAndForgetMethodImpl using a method descriptor and a void function signature
template <typename MethodDescriptor, typename... Args>
class FireAndForgetMethodImpl<MethodDescriptor, void(Args...)>
    : public internal::proxy::FireAndForgetMethod<void(Args...)>
{
public:
    /// \param instance Instance used for creating the object
    explicit FireAndForgetMethodImpl(types::InstanceId instance)
        : instance_(instance)
        , sessionId_(0)
    { }

    /// @uptrace{SWS_CM_90435, bba13147a6f63a2044003be53bee57228a135218}
    /// @uptrace{SWS_CM_10301, 20b56d9d3c371c0fdc4ce76aa3b0cad4433bde85}
    virtual void operator()(Args&&... args)
    {
        common::abort(!common::isMethodUndefined(MethodDescriptor::method_id));

        using internal::vsomeip::runtime::VSomeIPConnection;
        VSomeIPConnection& connection = VSomeIPConnection::getInstance();

        std::shared_ptr<::vsomeip::message> request
            = connection.getRuntime().create_request(MethodDescriptor::is_reliable);

        request->set_service(MethodDescriptor::service_id);
        request->set_instance(instance_);
        request->set_method(MethodDescriptor::method_id);
        request->set_interface_version(MethodDescriptor::service_version_major);
        request->set_session(++sessionId_);
        request->set_message_type(types::MessageTypeRequestNoReturn);

        detail::AddPayload(connection, request, std::forward<Args>(args)...);

        connection.getApplication().send(request, true);
    }

private:
    types::InstanceId instance_;
    types::SessionId sessionId_;
};

/// @}

}  // namespace proxy
}  // namespace vsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // VSOMEIP_PROXY_FIRE_AND_FORGET_METHOD_IMPL_H
