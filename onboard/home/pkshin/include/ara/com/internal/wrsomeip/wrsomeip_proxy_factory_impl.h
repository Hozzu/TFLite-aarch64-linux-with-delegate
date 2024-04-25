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
#include <memory>
#include "ara/core/vector.h"
#include "ara/com/types.h"
#include "ara/com/instance_identifier.h"
#include "ara/com/internal/proxy_factory_builder.h"
#include "ara/com/internal/proxy/proxy_factory.h"
#include "ara/com/internal/proxy/proxy_binding_base.h"
#include "ara/com/internal/wrsomeip/wrsomeip_connection.h"
#include "ara/com/internal/wrsomeip/wrsomeip_service_mapping.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace wrsomeip
{
namespace runtime
{

// Creates instances of proxies that are compatible to a specific service interface.
template <typename ProxyImpl>
class ProxyFactoryImpl : public internal::proxy::ProxyFactory
{
public:
    /**
     * \brief Creates a factory instance by binding it to the instance for which proxies shall be created.
     * \param instance The instance the created proxies shall be bound to.
     */
    ProxyFactoryImpl(ara::com::InstanceIdentifier instance)
        : ProxyFactory(instance)
    { }

    std::unique_ptr<internal::proxy::ProxyBindingBase> Create() const override
    {
        auto optionalId = common::ToTransportIdentifier(instance_);
        if (!optionalId) {
            return nullptr;
        }

        return std::make_unique<ProxyImpl>(*optionalId);
    }
};

class WrSomeIPProxyFactoryImpl : public internal::runtime::ProxyFactoryBuilder
{
public:
    WrSomeIPProxyFactoryImpl();
    virtual ~WrSomeIPProxyFactoryImpl()
    { }

    virtual ara::core::Vector<std::shared_ptr<internal::proxy::ProxyFactory>> createInstance(ServiceId service_id,
        ara::com::InstanceIdentifier instance_id) override;
    virtual void RegisterFindServiceHandle(FindServiceHandle handle, ProxyFactoryCallback callback) override;
    virtual void UnregisterFindServiceHandle(FindServiceHandle handle) override;

protected:
    struct FindServiceComparer
    {
        bool operator()(const FindServiceHandle& lhs, const FindServiceHandle& rhs) const;
    };

    struct FindServiceInfo
    {
        ProxyFactoryCallback callback;
        wrsomeip::runtime::WrSomeIPConnection::RequestedServiceInstance service_instance;
    };

    using FindServiceHandleList = std::multimap<FindServiceHandle, FindServiceInfo, FindServiceComparer>;
    using AvailableServicesList = std::set<common::ServiceInstance>;
    using StaticServiceRequestList
        = ara::core::Map<common::ServiceInstance, runtime::WrSomeIPConnection::RequestedServiceInstance>;

    void AvailabilityHandler(types::ServiceId service_id, types::InstanceId instance_id, bool available);
    ServiceHandleContainer<std::shared_ptr<internal::proxy::ProxyFactory>> GenerateAnyFactoryList(
        const WrSomeIPServiceMapping::Mapping& mapping);
    void UpdateServiceAvailability(types::ServiceId service_id, types::InstanceId instance_id, bool available);
    void EnableStaticServiceRequest(types::ServiceId service_id, types::InstanceId instance_id);

    FindServiceHandleList find_handles_;  // List of running StartFindService requests.
    AvailableServicesList available_services_;  // List of available services.
    /**
     * @brief List of static service requests.
     *
     * A static service request happens if the application polls for a service using FindService. In this case there is
     * no
     * service request end until the application terminates.
     */
    StaticServiceRequestList static_service_requests_;

    // We need a recursive mutex as the handlers aren't thread safe AND may call any method of ara::com during callback
    // processing.
    using Mutex = std::recursive_mutex;
    Mutex mutex_;

private:
    static void onAvailability(types::ServiceApplication* a, types::ServiceId b, types::InstanceId c, bool d);
    typedef std::function<void(types::ServiceId, types::InstanceId, bool)> availability_handler_t;
};

}  // namespace runtime
}  // namespace wrsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara
