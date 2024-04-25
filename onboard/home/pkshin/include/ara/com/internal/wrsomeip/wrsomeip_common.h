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

#pragma once
#include "ara/com/types.h"
#include "ara/com/instance_identifier.h"
#include "ara/core/optional.h"
#include "ara/com/internal/wrsomeip/wrsomeip_types.h"
#include "ara/com/internal/wrsomeip/wrapper/wrsomeip_logger_wrapper.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace wrsomeip
{
namespace common
{

// Register a Callback for a method
typedef void (*onMsg)(SERVICE_APPLICATION*, SOMEIP_MESSAGE*);
void registerMethodHandler(types::ServiceApplication* pSrvApp,
    types::ServiceId service,
    types::InstanceId instance,
    types::MethodId method,
    onMsg OnMsgHandler);

// Unregister a method callback. Not yet implemented inside wrsomeip
void unregisterMethodHandler(types::ServiceApplication* pSrvApp,
    types::ServiceId service,
    types::InstanceId instance,
    types::MethodId method);

// Perform std::abort in case condition is false
void abort(bool condition);

class ServiceInstance
{

public:
    constexpr ServiceInstance(types::ServiceId service_id, types::SomeIpInstance instance_id)
        : service_id_(service_id)
        , instance_id_(instance_id)
    { }
    // Copy constructor.
    ServiceInstance(const ServiceInstance&) = default;
    // Copy assignment. Returns *this
    ServiceInstance& operator=(const ServiceInstance&) = default;

    // Overload comparison operator
    bool operator==(const ServiceInstance& other) const;

    // Overload inequality operator
    bool operator!=(const ServiceInstance& other) const
    {
        return !operator==(other);
    }

    // Overload less than operator
    bool operator<(const ServiceInstance& other) const;

    // Retrieves the SOMEIP service ID.
    types::ServiceId GetService() const
    {
        return service_id_;
    }

    // Retrieves the SOMEIP instance ID.
    types::SomeIpInstance GetInstance() const
    {
        return instance_id_;
    }

private:
    types::ServiceId service_id_;  // SOMEIP service ID.
    types::SomeIpInstance instance_id_;  // SOMEIP instance ID.
};

// This value represents an unknown or uninitialized service instance.
static constexpr const ServiceInstance NullServiceInstance{0xFFFF, 0xFFFF};
ara::com::InstanceIdentifier FromTransportIdentifier(const types::InstanceId& id);
ara::core::Optional<types::InstanceId> ToTransportIdentifier(const ara::com::InstanceIdentifier& id);

}  // namespace common
}  // namespace wrsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara
