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

#ifndef VSOMEIP_PROXY_PROXY_IMPL_BASE_H
#define VSOMEIP_PROXY_PROXY_IMPL_BASE_H

#include "ara/com/internal/vsomeip/vsomeip_types.h"
#include "ara/com/internal/vsomeip/vsomeip_connection.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace vsomeip
{
namespace proxy
{
/**
 * \addtogroup vsomeipproxyimpl
 *
 * @{
 */
/**
 * \brief Proxy base implementation for vsomeip proxy interface
 */

class ProxyImplBase
{
public:
    /**
     * \brief Construct a specific ProxyImplBase
     * \param service_id Service id used to construct the object
     * \param instance_id Instance id used to construct the object
     * \param service_version_major Major Service version used to construct the object
     * \param service_version_minor Minor service version used to construct the object
     */
    ProxyImplBase(ServiceId service_id,
        types::InstanceId instance_id,
        types::ServiceVersionMajor service_version_major,
        types::ServiceVersionMinor service_version_minor)
        : requested_service_instance_(
            common::ServiceInstance(service_id, instance_id, service_version_major, service_version_minor))
    { }

protected:
    ~ProxyImplBase()
    { }

    /**
     * \brief Return the service instance id
     * \return Instance id
     */
    types::InstanceId getInstanceId() const
    {
        return requested_service_instance_.GetServiceInstanceId();
    }

private:
    runtime::VSomeIPConnection::RequestedServiceInstance requested_service_instance_;
};
/**
 * @}
 */
}  // namespace proxy
}  // namespace vsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // VSOMEIP_PROXY_PROXY_IMPL_BASE_H
