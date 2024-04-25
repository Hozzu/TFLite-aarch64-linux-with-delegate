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

#ifndef VSOMEIP_SKELETON_EVENT_IMPL_H
#define VSOMEIP_SKELETON_EVENT_IMPL_H

#include <memory>
#include <vsomeip/vsomeip.hpp>

#include "ara/com/types.h"
#include "ara/com/internal/skeleton/event.h"
#include "ara/com/internal/vsomeip/vsomeip_types.h"
#include "ara/com/internal/vsomeip/vsomeip_connection.h"
#include "ara/com/internal/vsomeip/vsomeip_marshalling.h"
#include "ara/core/result.h"
#include "ara/com/com_error_domain.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace vsomeip
{
namespace skeleton
{
/**
 * \addtogroup vsomeipskeletonimpl
 *
 * @{
 */

/**
 *  \brief Event implementation for Skeleton interface
 */
template <typename T, typename EventDescriptor>
class EventImpl : public virtual internal::skeleton::Event<T>
{
public:
    using Base = internal::skeleton::Event<T>;
    using typename Base::const_reference;

    explicit EventImpl(types::InstanceId instance)
        : instance_(instance)
    { }

    virtual ~EventImpl()
    { }

    /// @uptrace{SWS_CM_00162, 85c935c302eecc4040caa642553e9a83e606a28a}
    /// @uptrace{SWS_CM_10291, 97ac700f0c560844a92aaa8b450a2118bb371628}
    virtual ara::core::Result<void> Send(const_reference data) override
    {
        using ReturnType = ara::core::Result<void>;
        if (common::isEventUndefined(EventDescriptor::event_id)) {
            common::logger().LogError() << "Undefined event_id";
            return ReturnType::FromError({ara::com::ComErrorDomainErrc::kNetworkBindingFailure});
        }

        try {
            using runtime::VSomeIPConnection;
            VSomeIPConnection& connection = VSomeIPConnection::getInstance();
            common::Serializer<typename std::decay<T>::type> marshaller(data);
            ara::core::Vector<std::uint8_t> bytes;
            marshaller.pushbackTo(bytes);
            std::shared_ptr<::vsomeip::payload> payload = connection.getRuntime().create_payload(bytes);
            ::vsomeip::application& app = connection.getApplication();
            app.notify(EventDescriptor::service_id, instance_, EventDescriptor::event_id, payload);
            return {};
        } catch (...) {
            common::logger().LogError() << "Send failed";
            return ReturnType::FromError({ara::com::ComErrorDomainErrc::kNetworkBindingFailure});
        }
    }

    /// @uptrace{SWS_CM_90438, bdf7f8e57972dd9a11697f9031071855dd3b1b3d}
    /// @uptrace{SWS_CM_00308, da5eb18dc5a888434ea0b882750c7261e2dd1eca}
    virtual ara::core::Result<ara::com::SampleAllocateePtr<T>> Allocate() override
    {
        using ReturnType = ara::core::Result<ara::com::SampleAllocateePtr<T>>;
        try {
            return ReturnType::FromValue(std::make_unique<T>());
        } catch (...) {
            common::logger().LogError() << "Allocate failed";
            // TODO: use more appropriate error when available
            return ReturnType::FromError({ara::com::ComErrorDomainErrc::kNetworkBindingFailure});
        }
    }

    /// @uptrace{SWS_CM_90437, 02436e182657f9f2fb53cdb7b92a2ea63219981f}
    virtual ara::core::Result<void> Send(ara::com::SampleAllocateePtr<T> data) override
    {
        return Send(*data);
    }

protected:
    types::InstanceId instance_;
};
/**
 * @}
 */
}  // namespace skeleton
}  // namespace vsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // VSOMEIP_SKELETON_EVENT_IMPL_H
