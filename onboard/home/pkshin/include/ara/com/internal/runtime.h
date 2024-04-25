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

 mainpage ara::com reference implementation

 section Overview

 This document describes the reference implementation of the ara::com AUTOSAR specification. It is a central part of the
 Adaptive AUTOSAR ecosystem and enables Adaptive AUTOSAR Applications to use and offer services inside and outside of a
 system in a fast and type safe manner.

 The main codebase consists of a central library that provides base services to custom interfaces that are based on a
 model that adheres to the AUTOSAR metamodel specification. The included code generator can then be used to generate
 proxy and skeleton classes that can then be used by the application developer to talk to the outside world.

 The current implementation also provides a so called binding that connects the generated proxy and skeleton classes to
 a communications technology, namely the [vsomeipd](https://github.com/GENIVI/vsomeip). If an interface has a SOMEIP
 deployment, the generator will also generate binding classes so that the vsomeipd can be used as an IPC mechanism to
 exchange data between the application and other applications on the same or a different system.

 section build Build and install

 The ara::com reference implementation uses cmake as its build system. Therefore, just create a new directory, change to
 it and run cmake + make (or whatever build tool you created config files for):

 ```
 cd <someplace>
 mkdir <builddirname>
 cd <builddirname>
 cmake <sourcedir>
 make
 ```

 section further Further readings

 Besides this documentation, there also is an Enterprise Architect model that shows the class relations and an overview
 over the whole system. Unter "Related pages" you will also find a white paper (implementation_details.md) that
 describes
 the design decisions and their rationales.

*/

/**
 * @file
 * API interfaces defined for the runtime are used for functionality of cross-cutting middleware concerns, which can not
 * assigned to proxy or skeleton side clearly.
 */

#ifndef ARA_INCLUDES_LIBARA_RUNTIME_RUNTIME_H_
#define ARA_INCLUDES_LIBARA_RUNTIME_RUNTIME_H_

#include <algorithm>
#include "ara/core/vector.h"
#include "ara/core/string.h"

#include "ara/com/types.h"
#include "ara/com/internal/proxy/proxy_binding_base.h"
#include "ara/com/internal/proxy/proxy_factory.h"
#include "skeleton/service_base.h"

namespace ara
{
namespace com
{
namespace internal
{

/**
 * \defgroup runtime ara::com::internal runtime
 *
 * @brief Central module that manages bindings and service discovery.
 *
 * The so-called runtime is the central hub where binding implementations from all bindings are connected to the proxy
 * and skeleton classes used by the application developer. Although this isn't seen directly by the developer. the
 * generated classes delegate all duties regarding service discovery to the runtime which in turn dispatches the
 * requests to the registered bindings.
 *
 * @{
 */

/**
 *  @brief Interfaces an ARA::COM runtime implementation has to provide
 */
class Runtime
{
public:
    Runtime(Runtime&&) = default;
    Runtime(const Runtime&) = default;

    Runtime& operator=(Runtime&&) = default;
    Runtime& operator=(const Runtime&) = default;

    virtual ~Runtime()
    { }

    template <typename Service>
    /**
     * @brief Offer the service instance.
     *
     * method is idempotent - could be called repeatedly.
     * @param service service to offer
     **/
    inline static void OfferService(Service& service)
    {
        static_assert(std::is_base_of<internal::skeleton::ServiceBase, Service>::value,
            "OfferService only accepts classes derived from generated service skeletons");
        Init();
        for (const auto& instanceId : service.GetInstanceIDs()) {
            OfferService(service, Service::service_id, instanceId);
        }
    }

    template <typename Service>
    /**
     * @brief Stop Offering the service instance.
     *
     * method is idempotent - could be called repeatedly.
     * if service instance gets destroyed - it is expected that the middleware implementation
     * calls StopOfferService() internally.
     * @param service service to stop offering
     **/
    static void StopOfferService(Service& service)
    {
        static_assert(std::is_base_of<internal::skeleton::ServiceBase, Service>::value,
            "StopOfferService only accepts classes derived from generated service skeletons");
        StopOfferService(service, Service::service_id);
    }

    /**
     * @brief Opposed to StartFindServiceById(service_id, instance_id,handler, instance) this version is a "one-shot"
     * find request by Id,
     *  which is synchronous, i.e. it returns after the find has been done and a result list of matching service
     * instances is
     * available. (list may be empty, if no matching service instances currently exist)
     * - does reflect the availability at the time of the method call. No further (background) checks of availability
     * are done.
     *
     * @param service_id service id to be searched
     * @param instance_id instance id to be searched
     * @return service instance
     */
    inline static ara::core::Vector<std::shared_ptr<ara::com::internal::proxy::ProxyFactory>> FindServicesByIDs(
        internal::ServiceId service_id,
        ara::com::InstanceIdentifierContainer instance_ids)
    {
        Init();
        return DoFindServicesByIDs(service_id, instance_ids);
    }

    /**
     * @brief StartFindServiceById does not need an explicit version parameter as this is internally available in
     * ProxyClass
     * That means only compatible services are returned.
     *
     * @param service_id service id to be searched
     * @param instance_id instance id to be searched
     * @param handler this handler gets called any time the service availability of the services matching the given
     * instance criteria changes. It includes the FindServiceHandle that can be used to stop finding services.
     * If you use this variant of FindService, the middleware has to continuously monitor
     * the availability of the services and call the handler on any change.
     * @return a handle for this search/find request, which shall be used to stop the availability monitoring and
     * related
     * firing of the given handler.
     */
    inline static FindServiceHandle StartFindServiceById(internal::ServiceId service_id,
        ara::com::InstanceIdentifier instance_id,
        std::function<void(ServiceHandleContainer<std::shared_ptr<internal::proxy::ProxyFactory>>, FindServiceHandle)>
            handler)
    {
        Init();
        return DoStartFindServiceById(service_id, instance_id, handler);
    }

    /**
     * @brief Method to stop finding service request which registered for a handle before
     * @param handle Handle for which the the method stop finding the service
     */
    static void StopFindServiceById(FindServiceHandle handle);

    static void SetDefaultInstanceName(ara::core::String name);
    static const ara::core::String& GetInstanceName()
    {
        return GetInstance().DoGetInstanceName();
    }

protected:
    Runtime()
    { }

    static Runtime& GetInstance();
    static bool GetInstanceNameFromManifest(ara::core::String& name);

    virtual const ara::core::String& DoGetInstanceName() const;
    virtual void DoSetInstanceName(ara::core::String name);

private:
    /**
     * @brief Offer the Service instance
     * @param service Service to offer
     * @param service_id Service id of the service to offer
     * @param instance_id Instance id of the service to offer
     */
    static void OfferService(internal::skeleton::ServiceBase& service,
        internal::ServiceId service_id,
        ara::com::InstanceIdentifier instance_id);
    /**
     * @brief Stop offering a specific service
     * @param service service instance to stop offering
     * @param service_id service id of the offered service
     */
    static void StopOfferService(internal::skeleton::ServiceBase& service, internal::ServiceId service_id);

    static void Init();

    static ara::core::Vector<std::shared_ptr<ara::com::internal::proxy::ProxyFactory>> DoFindServicesById(
        internal::ServiceId service_id,
        ara::com::InstanceIdentifier instance_id);

    static ara::core::Vector<std::shared_ptr<ara::com::internal::proxy::ProxyFactory>> DoFindServicesByIDs(
        internal::ServiceId service_id,
        ara::com::InstanceIdentifierContainer instance_ids);

    static FindServiceHandle DoStartFindServiceById(internal::ServiceId service_id,
        ara::com::InstanceIdentifier instance_id,
        std::function<void(ServiceHandleContainer<std::shared_ptr<internal::proxy::ProxyFactory>>, FindServiceHandle)>
            handler);

    ara::core::String instance_name_;
};

/**
 * @}
 */

}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_INCLUDES_LIBARA_RUNTIME_RUNTIME_H_
