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

/// \file

#ifndef VSOMEIP_SKELETON_FIELD_IMPL_H
#define VSOMEIP_SKELETON_FIELD_IMPL_H

#include <functional>
#include <mutex>
#include <vsomeip/vsomeip.hpp>

#include "vsomeip_event_impl.h"
#include "vsomeip_service_impl_base.h"
#include "ara/com/illegal_state_exception.h"
#include "ara/com/types.h"
#include "ara/com/internal/skeleton/field.h"
#include "ara/com/internal/vsomeip/vsomeip_types.h"
#include "ara/com/internal/vsomeip/vsomeip_common.h"
#include "ara/core/future.h"
#include "ara/core/result.h"

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
/// \addtogroup vsomeipskeletonimpl
/// @{

/// \brief Field implementation for Skeleton interface
template <typename T, typename FieldDescriptor>
class FieldImpl
    : public virtual internal::skeleton::Field<T>
    , protected EventImpl<T, FieldDescriptor>
{
public:
    explicit FieldImpl(types::InstanceId instance)
        : EventImpl<T, FieldDescriptor>(instance)
    {
        common::registerMethodHandler(FieldDescriptor::service_id,
            EventImpl<T, FieldDescriptor>::instance_,
            FieldDescriptor::get_method_id,
            [this](const std::shared_ptr<::vsomeip::message>& msg) { handleGet(msg); });
    }

    virtual ~FieldImpl()
    {
        RegisterGetHandler(nullptr);
    }

    using Base = internal::skeleton::Field<T>;
    using typename Base::const_reference;
    using typename Base::reference;

    /// @uptrace{SWS_CM_00114, 248dfdc41f6ada4f341c2d8d789c79f7f5e9ad9b}
    virtual void RegisterGetHandler(std::function<ara::core::Future<T>()> handler) override
    {
        PutHandler(get_handler_, std::move(handler));
    }

    /// @uptrace{SWS_CM_00116, be99f767b7c29efc5dc14d9359b96181596c7b56}
    virtual ara::core::Result<void> Update(const_reference data) override
    {
        return this->Send(data);
    }

protected:
    mutable std::mutex lock_;

    /// \brief Retreive the Callback that is previously set
    /// \param source Placeholder for the Callback
    /// \return Return the Callback
    template <typename Signature>
    std::function<Signature> RetrieveHandler(const std::function<Signature>& source) const
    {
        std::lock_guard<std::mutex> guard(lock_);
        return source;
    }

    /// \brief Add the Callback to server side for future processing
    /// \param target Target Callback
    /// \param source Source Callback
    template <typename Signature>
    void PutHandler(std::function<Signature>& target, std::function<Signature> source)
    {
        std::lock_guard<std::mutex> guard(lock_);
        target = std::move(source);
    }

private:
    std::function<ara::core::Future<T>()> get_handler_;
    /// \brief This function handles a Get() call from the client to the server.
    /// \param msg Get message sent by the client.
    /// @uptrace{SWS_CM_10302, 7a70b24bf07f9fa220a701d481b4db016279e01c}
    /// @uptrace{SWS_CM_10334, 24bb65bb23b66d54b3ec622260b1dc77573c4e59}
    void handleGet(const std::shared_ptr<::vsomeip::message>& msg) const
    {
        bool isValidMessage = common::checkMessageMetaData(*msg,
            FieldDescriptor::service_id,
            FieldDescriptor::get_method_id,
            FieldDescriptor::service_version_major,
            ::ara::com::internal::vsomeip::types::MessageTypeRequest,
            ::ara::com::internal::vsomeip::types::MessageTypeRequestNoReturn,
            true,
            true);

        if (isValidMessage) {
            std::function<ara::core::Future<T>()> get_handler = RetrieveHandler(get_handler_);
            if (get_handler) {
                auto reply = get_handler().GetResult();
                ServiceImplBase::SendReply(reply, msg);
            } else {
                throw IllegalStateException("No Get handler registered!");
            }
        } else {
            common::logger().LogWarn() << "Discarding invalid message";
        }
    }
};
/// @}
}  // namespace skeleton
}  // namespace vsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // COMMUNICATIONMIDDLEWARE_FIELD_IMPL_H
