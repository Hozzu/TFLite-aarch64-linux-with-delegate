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

#ifndef ARA_COM_PROXY_PROXY_BASE_H
#define ARA_COM_PROXY_PROXY_BASE_H

#include <functional>
#include <memory>

#include "ara/com/types.h"
#include "ara/com/instance_identifier.h"
#include "ara/core/instance_specifier.h"
#include "ara/core/result.h"

#include "proxy_factory_wrapper.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace proxy
{

/**
 * @addtogroup frontendproxybase
 *
 * @{
 */

/**
 * \brief This is the base class that all proxies derive from.
 *
 * It provides all the methods that are common for service discovery. It also serves as the link from the user-visible
 * API to the binding. The template parameter designates the respective base class that has to provide getters for all
 * interface elements declared.
 *
 */
template <typename ProxyBinding>
class ProxyBase
{
public:
    /**
     * \brief Type of the handle that identifies one particular instance of the service.
     * @uptrace{SWS_CM_00312, 98c0354860b00d1dd80a4b202c5e16978e539f83}
     *
     * The underlying type is lightweight and can therefore be freely copied and stored by the application developer.
     */
    using HandleType = ProxyFactoryWrapper<ProxyBinding>;

    /**
     * \brief Creates a proxy using the instance information from the given handle. See \ref FindService() and
     * \ref StartFindService() for means to obtain a handle.
     *
     * \param proxy Instance the proxy shall be connected to.
     *
     * @uptrace{SWS_CM_00131, a4bb0196ec1ba17aed6d599f4dc3259f7b7ed02b}
     */
    ProxyBase(const HandleType& proxy)
        : proxy_base_(proxy.Create())
        , handle_(proxy)
    { }
    virtual ~ProxyBase()
    { }

    /**
     * \brief Returns the handle from which the Proxy instance has been created.
     *
     * \remark since the proxy may be "auto updated" during runtime, in case the (remote) service has been restarted
     * with a different transportlayer adressing, the handles returned at time t0 and t1 from the same proxy instance
     * need not be binary-equal!
     *
     * \return handle The handle that may be used to create another instance of a proxy for the same instance.
     *
     * @uptrace{SWS_CM_10383, 359592cac0599bd129bead506c184217bad02f6d}
     */
    HandleType GetHandle() const
    {
        return handle_;
    }

    /**
     *
     * \brief Retrieves a list of compatible instances for the service.
     *
     * Opposed to \ref StartFindService() this version is a "one-shot" find request, which is
     * - synchronous, i.e. it returns after the find has been done and a result list of matching service instances is
     *   available. (list may be empty, if no matching service instances currently exist)
     * - does reflect the availability at the time of the method call. No further (background) checks of availability
     *   are done.
     *
     * \param instance Instance of the service type that shall be searched/found. A wildcard may be given.
     *  Default value is wildcard.
     *
     * @uptrace{SWS_CM_00122, 43668e9c1540733ddcfc7e5b7d7f5e9fcae8d7ac}
     */
    static ara::core::Result<ServiceHandleContainer<HandleType>> FindService(InstanceIdentifier instance);

    /**
     *
     * \brief Retrieves a list of compatible instances for the service.
     *
     * Opposed to \ref StartFindService() this version is a "one-shot" find request, which is
     * - synchronous, i.e. it returns after the find has been done and a result list of matching service instances is
     *   available. (list may be empty, if no matching service instances currently exist)
     * - does reflect the availability at the time of the method call. No further (background) checks of availability
     *   are done.
     *
     * \param instance Instance Specifier qualifying the service instances that shall be searched/found.
     *
     * @uptrace{SWS_CM_00622, 2e6dd35244ab6ec8605533904caaf3b6553fc896}
     */
    static ara::core::Result<ServiceHandleContainer<HandleType>> FindService(ara::core::InstanceSpecifier instance);

    /**
     * \brief Installs a handler that is called whenever the set of offered instances for this service changes.
     *
     * If you use this method, the middleware will continuously monitor the availability of the services and call the
     * handler on any change. This means also that service instances that are not available anymore simply disappear
     * from the list that is given to the callback.
     *
     * StartFindService does not need an explicit version parameter as this is internally available in ProxyClass
     * That means only compatible services are returned.
     *
     * \param handler Handler that gets called any time the service availability of the services matching the given
     * instance criteria changes.
     *
     * \param instance Which instance of the service shall be searched/found. A wildcard may be given to
     * look for all compatible instances. Default value is wildcard.
     *
     * \return a handle for this search/find request, which shall be used to stop the availability monitoring and
     * related firing of the given handler. (\ref StopFindService())
     *
     * @uptrace{SWS_CM_00123, 0853fd03d090bb4c4cfa171bc6fa2de46199691e}
     **/
    static ara::core::Result<FindServiceHandle> StartFindService(FindServiceHandler<HandleType> handler,
        InstanceIdentifier instance);

    /**
     * \brief Installs a handler that is called whenever the set of offered instances for this service changes.
     *
     * If you use this method, the middleware will continuously monitor the availability of the services and call the
     * handler on any change. This means also that service instances that are not available anymore simply disappear
     * from the list that is given to the callback.
     *
     * StartFindService does not need an explicit version parameter as this is internally available in ProxyClass
     * That means only compatible services are returned.
     *
     * \param handler Handler that gets called any time the service availability of the services matching the given
     * instance criteria changes.
     *
     * \param instance Instance Specifier qualifying the service instances that shall be searched/found.
     *
     * \return a handle for this search/find request, which shall be used to stop the availability monitoring and
     * related firing of the given handler. (\ref StopFindService())
     *
     * @uptrace{SWS_CM_00623, 5b4f079ef78c9838d9d4fad69d24237ae525fa69}
     **/
    static ara::core::Result<FindServiceHandle> StartFindService(FindServiceHandler<HandleType> handler,
        ara::core::InstanceSpecifier instance);

    /**
     * \brief Unregisters the previously installed handler using the returned handle.
     *
     * \param handle
     *
     * @uptrace{SWS_CM_00125, 2e033d036b05c1d0b319ce22d69857c2dbfce421}
     */
    static void StopFindService(FindServiceHandle handle);

protected:
    std::unique_ptr<ProxyBinding>
        proxy_base_;  ///< Binding specific class that holds references to all interface elements.
    HandleType handle_;  ///< Handle that was used to create this instance.
};

}  // namespace proxy
}  // namespace internal
}  // namespace com
}  // namespace ara

#include "ara/com/internal/runtime.h"
#include "ara/com/illegal_state_exception.h"
#include "proxy_binding_base.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace proxy
{

template <typename ProxyBinding>
inline ara::core::Result<ServiceHandleContainer<typename ProxyBase<ProxyBinding>::HandleType>>
ProxyBase<ProxyBinding>::FindService(InstanceIdentifier instance)
{
    using ResultType = ara::core::Result<ServiceHandleContainer<typename ProxyBase<ProxyBinding>::HandleType>>;
    ara::core::Vector<std::shared_ptr<ProxyFactory>> bindings
        = Runtime::FindServicesByIDs(ProxyBinding::service_id, ara::com::InstanceIdentifierContainer{instance});
    ServiceHandleContainer<HandleType> result;
    for (auto& binding : bindings) {
        result.emplace_back(std::move(binding));
    }
    return ResultType::FromValue(std::move(result));
}

template <typename ProxyBinding>
inline ara::core::Result<ServiceHandleContainer<typename ProxyBase<ProxyBinding>::HandleType>>
ProxyBase<ProxyBinding>::FindService(ara::core::InstanceSpecifier instance)
{
    using ResultType = ara::core::Result<ServiceHandleContainer<typename ProxyBase<ProxyBinding>::HandleType>>;

    auto instanceIDs = ::ara::com::runtime::ResolveInstanceIDs(instance);

    // According to SWS_CM_00622 InstanceSpecifier validation errors are treated as Violations
    if (instanceIDs.empty()) {
        throw std::invalid_argument("Unable to find service, instance identifier container is empty");
    }

    ara::core::Vector<std::shared_ptr<ProxyFactory>> bindings
        = Runtime::FindServicesByIDs(ProxyBinding::service_id, instanceIDs);
    ServiceHandleContainer<HandleType> result;
    for (auto& binding : bindings) {
        result.emplace_back(std::move(binding));
    }
    return ResultType::FromValue(std::move(result));
}

template <typename ProxyBinding>
inline ara::core::Result<FindServiceHandle> ProxyBase<ProxyBinding>::StartFindService(
    FindServiceHandler<HandleType> handler,
    InstanceIdentifier instance)
{
    using ResultType = ara::core::Result<FindServiceHandle>;
    FindServiceHandle result = Runtime::StartFindServiceById(ProxyBinding::service_id,
        instance,
        [handler](ServiceHandleContainer<std::shared_ptr<ProxyFactory>> factories, FindServiceHandle handle) {
            ServiceHandleContainer<HandleType> handles;
            for (std::shared_ptr<ProxyFactory> factory : factories) {
                handles.push_back(factory);
            }
            handler(handles, handle);
        });
    return ResultType::FromValue(std::move(result));
}

template <typename ProxyBinding>
inline ara::core::Result<FindServiceHandle> ProxyBase<ProxyBinding>::StartFindService(
    FindServiceHandler<HandleType> handler,
    ara::core::InstanceSpecifier instance)
{
    auto instanceIDs = ::ara::com::runtime::ResolveInstanceIDs(instance);

    // According to SWS_CM_00623 InstanceSpecifier validation errors are treated as Violations
    if (instanceIDs.empty()) {
        throw std::invalid_argument("Unable to find service, instance identifier container is empty");
    }

    // Currently it's assumed that only one Service Instance mapped to the Port:
    // InstanceIdentifier Container contains only one element
    if (instanceIDs.size() != 1) {
        throw std::invalid_argument(
            "Implementation constraints: not able to handle multiple service instances mapped to r-port-prototype");
    }
    return StartFindService(std::move(handler), instanceIDs.front());
}

template <typename ProxyBinding>
inline void ProxyBase<ProxyBinding>::StopFindService(FindServiceHandle handle)
{
    Runtime::StopFindServiceById(handle);
}

/**
 * @}
 */

}  // namespace proxy
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_PROXY_PROXY_BASE_H
