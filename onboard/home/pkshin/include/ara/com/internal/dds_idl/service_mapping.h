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

#ifndef ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SERVICE_MAPPING_H_
#define ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SERVICE_MAPPING_H_

#include <memory>
#include <unordered_map>

#include "ara/com/types.h"
#include "ara/com/internal/proxy/proxy_factory.h"
#include "proxy/proxy_base.h"
#include "skeleton/skeleton_base.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace dds
{
namespace runtime
{

/// @brief The DdsServiceMapping class
///
/// @todo Figure out if it is possible to have only one class for multiple transports (VSOMEIP, OpenDDS)
class DdsServiceMapping
{
public:
    class Mapping
    {
    public:
        virtual ~Mapping()
        { }

        virtual ServiceId GetServiceId() const = 0;

        virtual types::ServiceId GetDeploymentId() const = 0;

        virtual types::ServiceVersionMajor GetServiceVersionMajor() const = 0;

        virtual types::ServiceVersionMinor GetServiceVersionMinor() const = 0;

        virtual uint32_t GetNumberOfBlacklistedVersions() const = 0;

        virtual const types::BlacklistedVersion* GetBlacklistedVersions() const = 0;

        virtual std::shared_ptr<internal::proxy::ProxyFactory> GetProxy(InstanceIdentifier instance_id,
            common::HandleInfo handle) const = 0;

        virtual std::unique_ptr<internal::skeleton::ServiceBase> GetSkeleton(internal::skeleton::ServiceBase& service,
            InstanceIdentifier instance_id,
            common::HandleInfo handle) const = 0;
    };

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

    static const Mapping* GetMappingForServiceId(ServiceId service_id);
    static MultiMapping GetMappingForOpenDdsServiceId(dds::types::ServiceId service_id);
};

}  // namespace runtime
}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SERVICE_MAPPING_H_
