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

#ifndef COMMUNICATIONMIDDLEWARE_VSOMEIP_SERVICE_DESCRIPTOR_H_H
#define COMMUNICATIONMIDDLEWARE_VSOMEIP_SERVICE_DESCRIPTOR_H_H

#include "ara/com/types.h"
#include "ara/com/internal/proxy/proxy_factory.h"
#include "proxy/vsomeip_proxy_base.h"
#include "skeleton/vsomeip_skeleton_base.h"
#include "vsomeip_types.h"

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
 * \addtogroup vsomeipcommon
 *
 * @{
 */
/**
 * \brief Represents a mapping between internal services and VSOMEIP service bindings.
 *
 * This class provides a means to turn internal service IDs into SOMEIP proxies, skeletons and IDs. An implementation
 * for this class is generated on a per-application basis by the ara::com generator.
 */
class VSomeIPServiceMapping
{
public:
    /**
     * \brief Represents the mapping of one single service.
     */
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
            ara::com::internal::vsomeip::types::InstanceId instance_id) const = 0;

        /**
         * \brief Returns the internal service ID for the service.
         * \return Internal service ID for the service.
         */
        virtual ServiceId GetServiceId() const = 0;

        /**
         * \brief Returns the SOMEIP service ID for the service.
         * \return SOMEIP service ID for the service.
         */
        virtual ::vsomeip::service_t GetVSomeIPService() const = 0;

        /**
         * \brief Creates a skeleton for the service that is represented by the mapping and the specified instance ID.
         * \param service
         * \parblock
         *  Service that shall be exported via SOMEIP.
         *
         *  The class instance has to be of the appropriate type. GetSkeleton will downcast the parameter to the type
         *the
         *  mapping represents. It is therefore expected that the internal service ID of the given class instance
         *matches
         *  \ref GetServiceId(). Otherwise, the downcast will fail and throw an \ref IllegalStateException.
         *
         *  The service itself will be bound to the returned binding class. This means that calls coming from the remote
         *end
         *  will be dispatched to the given service and using any
         *\endparblock
         *
         * \param instance_id Bind the skeleton binding to this instance ID.
         * \return Instance of the binding specific skeleton code containing deserializers and call dispatchers.
         */
        virtual std::unique_ptr<internal::skeleton::ServiceBase> GetSkeleton(internal::skeleton::ServiceBase& service,
            ara::com::internal::vsomeip::types::InstanceId instance_id) const = 0;

        /// \brief Returns the SOMEIP service major version.
        /// \return SOMEIP service major version.
        virtual types::ServiceVersionMajor GetVSomeIPServiceVersionMajor() const = 0;

        /// \brief Returns the SOMEIP service minor version.
        /// \return SOMEIP service minor version.
        virtual types::ServiceVersionMinor GetVSomeIPServiceVersionMinor() const = 0;

        /// \brief Returns the SOMEIP service required minor version.
        /// \return SOMEIP service required minor version.
        virtual types::ServiceVersionMinor GetVSomeIPRequiredServiceVersionMinor() const = 0;

        /// \brief Returns the SOMEIP version driven find behavior.
        /// \return SOMEIP version driven find behavior.
        virtual bool IsMinimumMinorPolicyEnabled() const = 0;

        /// \brief Returns the number of SOMEIP blacklisted service versions.
        /// \return Number of SOMEIP blacklisted service versions.
        virtual uint32_t GetNumberOfBlacklistedVersions() const = 0;

        /// \brief Returns the SOMEIP blacklisted versions.
        /// \return SOMEIP blacklisted versions.
        virtual const types::BlacklistedVersion* GetBlacklistedVersions() const = 0;
    };

    /**
     * \brief Represents all internal services that are mapped to one external SOMEIP service.
     *
     * Since we support the mapping of multiple ara::com interfaces to one SOMEIP service, we need to be able to return
     * multiple services in case the developer queries the mappings for one VSOMEIP service ID.
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
     * \return Pointer to the service mapping or nullptr of no VSOMEIP deployment exists for the given service ID.
     */
    static const Mapping* GetMappingForServiceId(ServiceId service_id);

    /**
     * \brief Returns all services that are part of the specified SOMEIP service ID.
     * \param service_id SOMEIP service ID of the requested mapping.
     * \return SOMEIP service mapping. It might be empty if there is no known service that is deployed to this SOMEIP
     * service.
     */
    static MultiMapping GetMappingForVSomeIPServiceId(::vsomeip::service_t service_id);
};
/** @}*/
}  // namespace runtime
}  // namespace vsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // COMMUNICATIONMIDDLEWARE_VSOMEIP_SERVICE_DESCRIPTOR_H_H
