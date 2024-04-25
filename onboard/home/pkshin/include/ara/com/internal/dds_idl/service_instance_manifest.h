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

#ifndef ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SERVICEINSTANCEMANIFEST_H_
#define ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SERVICEINSTANCEMANIFEST_H_

#include "ara/core/result.h"
#include "ara/core/vector.h"
#include "ara/core/string.h"
#include "rapidjson/document.h"
#include "rapidjson/pointer.h"
#include "rapidjson/filereadstream.h"
#include "ara/com/internal/dds_idl/common.h"
#include "ara/com/internal/dds_idl/types.h"
#include "ara/com/com_error_domain.h"

#include "ara/com/instance_identifier.h"

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

struct DdsServiceInstanceProperties
{
    DdsServiceInstanceProperties() = delete;

    explicit DdsServiceInstanceProperties(const ara::com::InstanceIdentifier instanceId, const ServiceId serviceId)
        : domainId_()
        , qosProfile_()
        , instanceId_(instanceId)
        , serviceId_(serviceId)
    { }

    bool operator<(const DdsServiceInstanceProperties& other) const
    {
        return instanceId_ < other.instanceId_;
    }

    types::DomainId domainId_;
    ara::core::String qosProfile_;
    ara::com::InstanceIdentifier instanceId_;
    ServiceId serviceId_;
};

class ServiceInstanceManifest
{
public:
    ServiceInstanceManifest() = default;

    /// @brief Parse JSON file of service instances manifest.
    ///
    /// @param path JSON file path.
    /// @return  number of founded instances.
    uint32_t parseJsonFile(ara::core::StringView path);

    /// @brief Get properties of provided instance.
    ///
    /// @param id Service instance ID.
    /// @return  Properties of selected instance.
    ara::core::Result<const DdsServiceInstanceProperties*> getPrividedInstanceProperties(
        const ara::com::InstanceIdentifier id)
    {
        return getInstanceProperties(domainProvidedServiceProperties_, id);
    }

    /// @brief Get properties of required instance.
    ///
    /// @param id Service instance ID.
    /// @return  Properties of selected instance.
    ara::core::Result<const DdsServiceInstanceProperties*> getRequiredInstanceProperties(
        const ara::com::InstanceIdentifier id)
    {
        return getInstanceProperties(domainReqiredServiceProperties_, id);
    }

    /// @brief Get properties of any instances of service.
    ///
    /// @param id Service ID.
    /// @return  List of properties of required instances for selected service.
    ara::core::Vector<DdsServiceInstanceProperties> getRequiredServiceProperties(const ServiceId id);

private:
    ara::core::Result<const DdsServiceInstanceProperties*> getInstanceProperties(
        ara::core::Vector<DdsServiceInstanceProperties>& props,
        const ara::com::InstanceIdentifier& id);
    bool checkConsistency(const rapidjson::Value& doc) const;
    uint32_t LoadInstanceProperties(ara::core::Vector<DdsServiceInstanceProperties>& props,
        const rapidjson::Value& doc);

    ara::core::Vector<DdsServiceInstanceProperties> domainReqiredServiceProperties_;
    ara::core::Vector<DdsServiceInstanceProperties> domainProvidedServiceProperties_;
};

}  // namespace runtime
}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SERVICEINSTANCEMANIFEST_H_
