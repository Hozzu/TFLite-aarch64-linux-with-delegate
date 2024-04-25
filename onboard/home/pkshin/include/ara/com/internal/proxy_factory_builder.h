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
 * @brief Provides functionality to manage proxy instances.
 */

#ifndef EXAMPLE_ARA_INCLUDES_ARA_RUNTIME_PROXY_FACTORY_H_
#define EXAMPLE_ARA_INCLUDES_ARA_RUNTIME_PROXY_FACTORY_H_

#include "ara/core/vector.h"

#include "ara/com/types.h"
#include "ara/com/internal/proxy/proxy_factory.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace runtime
{

/**
 * @addtogroup runtime
 *
 * @{
 */

/**
 * @brief Defines the interface for a binding on proxy side.
 *
 * This class shall be implemented by any binding to get proxy factories for all compatible services that fit to a
 * combination of service ID (which resembles the interface type) and an instance ID.
 *
 * The returned factories can then be used to create instances of the proxy bindings for this particular instance.
 *
 */

class ProxyFactoryBuilder
{
public:
    virtual ~ProxyFactoryBuilder()
    { }
    /**
     *@brief Creates proxy factories for this particular combination of service ID and instance ID.
     *
     * If instance ID is "Any", the returned vector will consist 0..N entries. If the instance ID is given, then 0..1
     * factories is returned to the caller, depending on th eavailability of this particular instance.
     *
     * @param service_id Service ID of the service interface.
     * @param instance_id Instance ID of the service instance.
     * @return Vector of factories for each service instance that matched the given parameters.
     *
     */
    virtual ara::core::Vector<std::shared_ptr<proxy::ProxyFactory>> createInstance(internal::ServiceId service_id,
        ara::com::InstanceIdentifier instance_id)
        = 0;
    /**
     * @brief Register a function to be called whenever a given search query changes.
     *
     * @param handle Search query to be registered. @see FindServiceHandle for a detailed description.
     * @param callback Callback function to be called with the result of the query whenever it changes.
     *
     */
    virtual void RegisterFindServiceHandle(FindServiceHandle handle, ProxyFactoryCallback callback) = 0;
    /**
     * @brief Unregister a search query.
     *
     * @param handle Handle to unregister
     */
    virtual void UnregisterFindServiceHandle(FindServiceHandle handle) = 0;
};

/**
 * @brief Register a ProxyFactoryBuilder instance for a certain binding.
 *
 * After this method has been called, subsequent calls to @see FindService() / @see StartFundService() will also be
 * dispatched to this instance (== a new binding has been registered).
 *
 * @param factory Proxy binding factory to be registered with the middleware core.
 */
void registerProxyFactoryBuilder(ProxyFactoryBuilder& factory);

/**
 * @}
 */

}  // namespace runtime
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif /* EXAMPLE_ARA_INCLUDES_ARA_RUNTIME_PROXY_FACTORY_H_ */
