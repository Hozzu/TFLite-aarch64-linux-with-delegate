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
#include "ara/com/internal/wrsomeip/wrsomeip_service_mapping.h"
#include "ara/com/internal/wrsomeip/wrsomeip_proxy_factory_impl.h"

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

// Tag struct that is used whenever there is no proxy for a specific service as the SWC does not require the service.
struct NoProxy
{ };

// Tag struct that is used whenever there is no adapter (skeleton) for a specific service as the SWC does not provide
// the service.
struct NoAdapter
{ };

// Helper class to build the adapter specified in the template parameter list.
template <typename Adapter>
struct AdapterBuilder
{
    /**
     * \brief Creates the adapter.
     *
     * This method may fail and throw IllegalStateException in case the adapter specified in the template argument list
     * doesn't fit to the service given in the parameter list.
     *
     * \param service Service the binding shall export.
     * \param instance_id SOMEIP instance ID that shall be used to export the service.
     * \return Pointer to the adapter that contains the binding instance.
     */
    std::unique_ptr<Adapter> make(internal::skeleton::ServiceBase& service, types::InstanceId instance_id)
    {
        try {
            typename Adapter::ServiceInterface& interface = dynamic_cast<typename Adapter::ServiceInterface&>(service);
            std::unique_ptr<Adapter> adapter = std::make_unique<Adapter>(interface, instance_id);
            return adapter;
        } catch (std::bad_cast& e) {
            throw IllegalStateException("Given service interface does not fit to the binding adapter!");
        }
    }
};

/**
 * \brief Specialization for the \ref NoAdapter tag struct that indicates that there is no adapter available.
 *
 */
template <>
struct AdapterBuilder<NoAdapter>
{
    std::unique_ptr<internal::skeleton::ServiceBase> make(internal::skeleton::ServiceBase&, types::InstanceId)
    {
        return nullptr;
    }
};

/**
 * \brief Helper class to create a proxy factory that creates proxies for the given service.
 */
template <typename ProxyType>
struct ProxyBuilder
{
    /**
     * \brief Creates a proxy factory that creates proxies for the given service ID and instance ID.
     * \param instance_id Instance ID the proxies shall talk to.
     * \return Proxy factory that can be used to create proxies.
     */
    std::shared_ptr<internal::proxy::ProxyFactory> make(types::InstanceId instance_id)
    {
        return std::make_shared<ProxyFactoryImpl<ProxyType>>(common::FromTransportIdentifier(instance_id));
    }
};

/**
 * \brief Class specialization in case the NoProxy tag struct is used to indicate that there is no proxy available for
 * the given service.
 */
template <>
struct ProxyBuilder<NoProxy>
{
    /**
     * \brief Returns nullptr as there are no proxies available.
     */
    std::shared_ptr<internal::proxy::ProxyFactory> make(types::InstanceId)
    {
        return nullptr;
    }
};

/**
 * \brief Will be used by the ara::com generator to create the mapping for one specific service.
 *
 * A service mapping consists of
 * * The *internal* service ID
 * * The *SOMEIP* service ID
 * * A getter for the proxy factory that creates proxies for the given service
 * * A getter for a skeleton binding class instance for the given service
 */
template <types::ServiceId ARACOMServiceId,
    types::ServiceId WrSomeIPServiceId,
    typename ProxyType,
    typename SkeletonType>

class ServiceMappingImpl : public WrSomeIPServiceMapping::Mapping
{
public:
    /**
     * \brief Get the service ID for the service the mapping represents.
     * \return Service ID
     */
    types::ServiceId GetServiceId() const override
    {
        return ARACOMServiceId;
    }

    /**
     * \brief Get the SOMEIP service ID for the service the mapping represents.
     * \return SOMEIP service ID.
     */
    types::ServiceId GetWrSomeIPService() const override
    {
        return WrSomeIPServiceId;
    }

    types::pServiceApplication GetWrSomeIPServiceApp() const override
    {
        runtime::WrSomeIPConnection& connection = runtime::WrSomeIPConnection::getInstance();

        return connection.pClientApp;
    }

    /**
     * \brief Get the proxy factory that creates proxies for the given service instance.
     * \param instance_id Instance ID of the service
     * \return Proxy factory
     */
    std::shared_ptr<internal::proxy::ProxyFactory> GetProxy(types::InstanceId instance_id) const override
    {
        return ProxyBuilder<ProxyType>().make(instance_id);
    }

    /**
     * \brief Get the skeleton binding class for the given service instance.
     * \param service Service implementation from the application layer that shall be exported using the wrsomeip
     * binding.
     * \param instance_id Instance ID of the service
     * \return Binding instance.
     */
    std::unique_ptr<internal::skeleton::ServiceBase> GetSkeleton(internal::skeleton::ServiceBase& service,
        types::InstanceId instance_id) const override
    {
        return AdapterBuilder<SkeletonType>().make(service, instance_id);
    }
};
}  // namespace runtime
}  // namespace wrsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara
