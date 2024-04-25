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
 * @file
 */

#ifndef COMMUNICATIONMIDDLEWARE_VSOMEIP_PROXY_FACTORY_IMPL_H
#define COMMUNICATIONMIDDLEWARE_VSOMEIP_PROXY_FACTORY_IMPL_H

#include <memory>
#include "ara/com/types.h"
#include "ara/com/instance_identifier.h"
#include "ara/com/internal/proxy_factory_builder.h"
#include "ara/com/internal/proxy/proxy_factory.h"
#include "ara/com/internal/proxy/proxy_binding_base.h"
#include "ara/com/internal/vsomeip/vsomeip_connection.h"
#include "ara/com/internal/vsomeip/vsomeip_service_mapping.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace vsomeip
{
namespace runtime
{
/**
 * @addtogroup vsomeipcommon
 *
 * @{
 */

/**
 * \brief Creates instances of proxies that are compatible to a specific service interface.
 */
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

class VSomeIPProxyFactoryImpl : public internal::runtime::ProxyFactoryBuilder
{
public:
    VSomeIPProxyFactoryImpl();
    virtual ~VSomeIPProxyFactoryImpl()
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
        runtime::VSomeIPConnection::RequestedServiceInstance service_instance;
    };

    using FindServiceHandleList = std::multimap<FindServiceHandle, FindServiceInfo, FindServiceComparer>;
    using AvailableServicesList = std::set<common::ServiceInstance>;
    using StaticServiceRequestList
        = ara::core::Map<common::ServiceInstance, runtime::VSomeIPConnection::RequestedServiceInstance>;

    void AvailabilityHandler(::vsomeip::service_t service_id, ::vsomeip::instance_t instance_id, bool available);
    ServiceHandleContainer<std::shared_ptr<internal::proxy::ProxyFactory>> GenerateAnyFactoryList(
        const VSomeIPServiceMapping::Mapping& mapping);

    void EnableStaticServiceRequest(::vsomeip::service_t service_id,
        ::vsomeip::instance_t instance_id,
        ::vsomeip::major_version_t service_version_major,
        ::vsomeip::minor_version_t service_version_minor);

    FindServiceHandleList find_handles_;  ///< List of running StartFindService requests.
    AvailableServicesList available_services_;  ///< List of available services.
    /**
     * \brief List of static service requests.
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
};

/** @}*/
}  // namespace runtime
}  // namespace vsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // COMMUNICATIONMIDDLEWARE_VSOMEIP_PROXY_FACTORY_IMPL_H
