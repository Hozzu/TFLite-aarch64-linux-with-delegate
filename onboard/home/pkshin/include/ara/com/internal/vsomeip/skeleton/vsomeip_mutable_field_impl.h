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

#ifndef COMMUNICATIONMIDDLEWARE_SKELETON_VSOMEIP_MUTABLE_FIELD_IMPL_H
#define COMMUNICATIONMIDDLEWARE_SKELETON_VSOMEIP_MUTABLE_FIELD_IMPL_H

#include <functional>

#include "ara/com/internal/skeleton/mutable_field.h"
#include "ara/com/illegal_state_exception.h"
#include "ara/com/internal/vsomeip/vsomeip_types.h"
#include "ara/com/internal/vsomeip/vsomeip_common.h"

#include "vsomeip_field_impl.h"

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

/// \brief Mutable field implementation for Skeleton service interface
template <typename T, typename FieldDescriptor>
class MutableFieldImpl
    : public internal::skeleton::MutableField<T>
    , public FieldImpl<T, FieldDescriptor>
{
public:
    using Base = FieldImpl<T, FieldDescriptor>;
    using typename internal::skeleton::MutableField<T>::SetMethodSignature;

    /// \brief constructor
    explicit MutableFieldImpl(types::InstanceId instance)
        : FieldImpl<T, FieldDescriptor>(instance)
    {
        common::registerMethodHandler(FieldDescriptor::service_id,
            EventImpl<T, FieldDescriptor>::instance_,
            FieldDescriptor::set_method_id,
            [this](const std::shared_ptr<::vsomeip::message>& msg) { handleSet(msg); });
    }

    /// @uptrace{SWS_CM_00116, be99f767b7c29efc5dc14d9359b96181596c7b56}
    virtual void RegisterSetHandler(std::function<SetMethodSignature> handler) override
    {
        Base::PutHandler(set_handler_, std::move(handler));
    }

private:
    std::function<SetMethodSignature> set_handler_;

    /// \brief  This function handles a Set() call from the client.
    /// \param msg The message contains the data the value of the field shall be set to.
    /// @uptrace{SWS_CM_10302, 7a70b24bf07f9fa220a701d481b4db016279e01c}
    /// @uptrace{SWS_CM_10334, 24bb65bb23b66d54b3ec622260b1dc77573c4e59}
    void handleSet(const std::shared_ptr<::vsomeip::message>& msg)
    {
        bool isValidMessage = common::checkMessageMetaData(*msg,
            FieldDescriptor::service_id,
            FieldDescriptor::set_method_id,
            FieldDescriptor::service_version_major,
            ::ara::com::internal::vsomeip::types::MessageTypeRequest,
            ::ara::com::internal::vsomeip::types::MessageTypeRequestNoReturn,
            true,
            true);

        if (isValidMessage) {
            std::function<SetMethodSignature> set_handler = Base::RetrieveHandler(set_handler_);
            if (set_handler) {
                common::Unmarshaller<T> unmarshaller(*msg);
                T value_to_set = unmarshaller.template unmarshal<0>();
                auto reply = set_handler(value_to_set).GetResult();
                ServiceImplBase::SendReply(reply, msg);
            } else {
                throw IllegalStateException("No Set handler registered!");
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

#endif  // COMMUNICATIONMIDDLEWARE_SKELETON_VSOMEIP_MUTABLE_FIELD_IMPL_H
