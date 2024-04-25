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

#ifndef ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SERVICE_REGISTRY_H_
#define ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SERVICE_REGISTRY_H_

#include "ara/com/internal/dds_idl/service_instance_manifest.h"
#include "ara/com/internal/service_registry.h"

#include <unordered_map>

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

class DdsServiceRegistryImpl : public internal::runtime::ServiceRegistry
{
public:
    DdsServiceRegistryImpl(ServiceInstanceManifest& manifest);

    bool registerService(internal::skeleton::ServiceBase& service,
        ServiceId service_id,
        ara::com::InstanceIdentifier instance_id) override;

    void unregisterService(internal::skeleton::ServiceBase& service, ServiceId service_id) override;

private:
    struct RegisteredObject
    {
        std::unique_ptr<internal::skeleton::ServiceBase> service_;
        ServiceId service_id_;
        ara::com::InstanceIdentifier instance_id_;
    };

    using RegisteredObjectsMap = std::unordered_map<internal::skeleton::ServiceBase*, RegisteredObject>;
    RegisteredObjectsMap registered_objects_;
    ServiceInstanceManifest& manifest_;
};

}  // namespace runtime
}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SERVICE_REGISTRY_H_
