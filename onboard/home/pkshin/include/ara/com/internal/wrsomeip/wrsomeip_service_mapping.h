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
#include <unordered_map>
#include "ara/com/types.h"
#include "ara/com/internal/proxy/proxy_factory.h"
#include "ara/com/internal/wrsomeip/wrsomeip_types.h"
#include "ara/com/internal/wrsomeip/proxy/wrsomeip_proxy_base.h"
#include "ara/com/internal/wrsomeip/skeleton/wrsomeip_skeleton_base.h"

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

/**
 * This class provides a means to turn internal service IDs into SOMEIP proxies, skeletons and IDs. An implementation
 * for this class is generated on a per-application basis by the ara::com generator.
 */
class WrSomeIPServiceMapping
{
public:
    // Represents the mapping of one single service.
    class Mapping
    {
    public:
        virtual ~Mapping()
        { }

        /**
         * \brief Returns a proxy factory for the service that is represented by the mapping and the specified instance
         * ID.
         * \param instance_id Instance ID the proxy factory shall be bound to.
         * \return Proxy factory for the specified instance ID.
         */
        virtual std::shared_ptr<internal::proxy::ProxyFactory> GetProxy(
            ara::com::internal::wrsomeip::types::InstanceId instance_id) const = 0;

        /**
         * \brief Returns the internal service ID for the service.
         * \return Internal service ID for the service.
         */
        virtual types::ServiceId GetServiceId() const = 0;

        /**
         * \brief Returns the SOMEIP service ID for the service.
         * \return SOMEIP service ID for the service.
         */
        virtual types::ServiceId GetWrSomeIPService() const = 0;

        virtual types::ServiceApplication* GetWrSomeIPServiceApp() const = 0;

        virtual std::unique_ptr<internal::skeleton::ServiceBase> GetSkeleton(internal::skeleton::ServiceBase& service,
            ara::com::internal::wrsomeip::types::InstanceId instance_id) const = 0;
    };

    /**
     * \brief Represents all internal services that are mapped to one external SOMEIP service.
     *
     * Since we support the mapping of multiple ara::com interfaces to one SOMEIP service, we need to be able to return
     * multiple services in case the developer queries the mappings for one wrsomeip service ID.
     */
    class MultiMapping : public std::unordered_map<ServiceId, std::reference_wrapper<const Mapping>>
    {
    public:
        MultiMapping(std::initializer_list<const Mapping*> mappings)
        {
            for (const Mapping* mapping : mappings) {
                InsertMapping(mapping);
            }
        }
        void InsertMapping(const Mapping* mapping)
        {
            emplace(mapping->GetServiceId(), std::cref(*mapping));
        }
    };

    /**
     * \brief Returns the service mapping for the given internal service ID.
     *
     * \param service_id Service ID of the requested mapping.
     * \return Pointer to the service mapping or nullptr of no wrsomeip deployment exists for the given service ID.
     */
    static const Mapping* GetMappingForServiceId(ServiceId service_id);

    /**
     * \brief Returns all services that are part of the specified SOMEIP service ID.
     * \param service_id SOMEIP service ID of the requested mapping.
     * \return SOMEIP service mapping. It might be empty if there is no known service that is deployed to this SOMEIP
     * service.
     */
    static MultiMapping GetMappingForWrSomeIPServiceId(ServiceId service_id);
};
}  // namespace runtime
}  // namespace wrsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara
