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

#ifndef ARA_INCLUDES_ARA_INTERNAL_RUNTIME_SERVICE_REGISTRY_H_
#define ARA_INCLUDES_ARA_INTERNAL_RUNTIME_SERVICE_REGISTRY_H_

#include "ara/com/internal/skeleton/ara_skeleton_base.h"
#include "ara/com/types.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace runtime
{

/**
 * \addtogroup runtime
 *
 * @{
 */

/**
 * \brief Defines the interface for the skeleton side of a binding.
 *
 * Instances of this class provide the functionality to offer a certain service via the binding that implements this
 * class. The service will only be offered if the binding provides server side code for the service. This is typically
 * only the case if there is deployment info for the binding. However, since this shall be transparent for the
 * application, no error is returned in case the service was in fact not offered.
 *
 * Thie interface itself is untyped so that all calls need a service ID as a type hint.
 *
 */
class ServiceRegistry
{
public:
    virtual ~ServiceRegistry()
    { }

    /**
     * \brief Make service available for the service consumer over this specific binding.
     *
     * \param service Service to offer.
     * \param service_id Internal service ID of the service to offer.
     * \param instance_id Internal instance ID of the instance that shall be offered.
     *
     * \return True if service registered successfully, otherwise false.
     */
    virtual bool registerService(skeleton::ServiceBase& service,
        ServiceId service_id,
        ara::com::InstanceIdentifier instance_id)
        = 0;

    /**
     * \brief Unregister (remove) service so that it's not offered to clients anymore.
     *
     * \param service Service interface to remove from ServiceRegistry
     * \param service_id Service ID of the service interface.
     */
    virtual void unregisterService(skeleton::ServiceBase& service, ServiceId service_id) = 0;
};

/**
 * @}
 */

}  // namespace runtime
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif /* ARA_INCLUDES_ARA_INTERNAL_RUNTIME_SERVICE_REGISTRY_H_ */
