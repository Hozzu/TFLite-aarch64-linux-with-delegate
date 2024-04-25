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
#include <memory>
#include "ara/com/types.h"
#include "ara/com/internal/skeleton/event.h"
#include "ara/com/internal/wrsomeip/wrsomeip_types.h"
#include "ara/com/internal/wrsomeip/wrsomeip_connection.h"
#include "ara/com/internal/wrsomeip/wrsomeip_marshalling.h"
// #include "ara/com/internal/e2e/e2e_binding.h"
#include "ara/core/result.h"
#include "ara/com/com_error_domain.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace wrsomeip
{
namespace skeleton
{

// Event implementation for Skeleton interface
template <typename T, typename EventDescriptor>
class SkeletonEventImpl : public virtual internal::skeleton::Event<T>
{
public:
    using Base = internal::skeleton::Event<T>;
    using typename Base::const_reference;

    explicit SkeletonEventImpl(types::InstanceId instance)
        : instance_(instance)
    { }

    virtual ~SkeletonEventImpl()
    { }

    virtual ara::core::Result<void> Send(const_reference data) override
    {
        using ReturnType = ara::core::Result<void>;
        try {
            WrSomeIPConnection& connection = WrSomeIPConnection::getInstance();
            common::Serializer<typename std::decay<T>::type> marshaller(data);
            ara::core::Vector<std::uint8_t> bytes;
            marshaller.pushbackTo(bytes);
            SOMEIP_PAYLOAD* wrsomeip_payload;
            wrsomeip_payload = someipPayloadNew(bytes.data(), bytes.size());
            wrapper::WrsomeipApplication& app = connection.getApplication();
            // Notify event
            STATUS ret = app.notify(connection.pClientApp,
                EventDescriptor::service_id,
                instance_,
                EventDescriptor::event_id,
                wrsomeip_payload);
            if (ret != OK) {
                logger::log().LogError() << "[BINDING][" << __FUNCTION__ << "] cannot notify event "
                                         << EventDescriptor::event_id;
                return ReturnType::FromError({ara::com::ComErrorDomainErrc::kNetworkBindingFailure});
            }
            return {};
        } catch (...) {
            logger::log().LogError() << "Send failed";
            return ReturnType::FromError({ara::com::ComErrorDomainErrc::kNetworkBindingFailure});
        }
    }

    virtual ara::core::Result<ara::com::SampleAllocateePtr<T>> Allocate() override
    {
        using ReturnType = ara::core::Result<ara::com::SampleAllocateePtr<T>>;
        try {
            return ReturnType::FromValue(std::make_unique<T>());
        } catch (...) {
            logger::log().LogError() << "Allocate failed";
            // TODO: use more appropriate error when available
            return ReturnType::FromError({ara::com::ComErrorDomainErrc::kNetworkBindingFailure});
        }
    }

    virtual ara::core::Result<void> Send(ara::com::SampleAllocateePtr<T> data) override
    {
        return Send(*data);
    }

protected:
    types::InstanceId instance_;

private:
    using WrSomeIPConnection = runtime::WrSomeIPConnection;
};

}  // namespace skeleton
}  // namespace wrsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara
