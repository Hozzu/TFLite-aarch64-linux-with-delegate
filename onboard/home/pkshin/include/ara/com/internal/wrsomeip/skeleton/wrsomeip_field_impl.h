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
#include <functional>
#include <mutex>
#include "ara/core/future.h"
#include "ara/com/types.h"
#include "ara/com/illegal_state_exception.h"
#include "ara/com/internal/skeleton/mutable_field.h"
#include "ara/com/internal/skeleton/field.h"
#include "ara/com/internal/wrsomeip/wrsomeip_types.h"
#include "ara/com/internal/wrsomeip/wrsomeip_common.h"
#include "ara/com/internal/wrsomeip/wrapper/wrsomeip_runtime_wrapper.h"
#include "ara/com/internal/wrsomeip/skeleton/wrsomeip_event_impl.h"
#include "ara/com/internal/wrsomeip/skeleton/wrsomeip_service_impl_base.h"
#include "ara/core/result.h"

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

// Field implementation for Skeleton interface
template <typename T, typename FieldDescriptor>

class FieldImpl
    : public virtual internal::skeleton::Field<T>
    , protected SkeletonEventImpl<T, FieldDescriptor>
{
public:
    explicit FieldImpl(types::InstanceId instance)
        : SkeletonEventImpl<T, FieldDescriptor>(instance)
    {
        runtime::WrSomeIPConnection& connection = runtime::WrSomeIPConnection::getInstance();
        auto lam = [this](SERVICE_APPLICATION* srvApp, SOMEIP_MESSAGE* msg) { handleGet(srvApp, msg); };
        static auto s_lam = lam;
        common::registerMethodHandler(connection.pClientApp,
            FieldDescriptor::service_id,
            instance,
            FieldDescriptor::get_method_id,
            [](SERVICE_APPLICATION* srvApp, SOMEIP_MESSAGE* msg) { s_lam(srvApp, msg); });
    }
    virtual ~FieldImpl()
    {
        RegisterGetHandler(nullptr);
    }

    using Base = internal::skeleton::Field<T>;
    using typename Base::const_reference;
    using typename Base::reference;

    virtual void RegisterGetHandler(std::function<ara::core::Future<T>()> handler) override
    {
        PutHandler(get_handler_, std::move(handler));
    }

    virtual ara::core::Result<void> Update(const_reference data) override
    {
        return this->Send(data);
    }

protected:
    mutable std::mutex lock_;
    /**
     * \brief Retreive the Callback that is previously set
     * \param source Placeholder for the Callback
     * \return Return the Callback
     */
    template <typename Signature>
    std::function<Signature> RetrieveHandler(const std::function<Signature>& source) const
    {
        std::lock_guard<std::mutex> guard(lock_);
        return source;
    }
    /**
     * \brief Add the Callback to server side for future processing
     * \param target Target Callback
     * \param source Source Callback
     */
    template <typename Signature>
    void PutHandler(std::function<Signature>& target, std::function<Signature> source)
    {
        std::lock_guard<std::mutex> guard(lock_);
        target = std::move(source);
    }

private:
    std::function<ara::core::Future<T>()> get_handler_;
    /**
     * \brief This function handles a Get() call from the client to the server.
     * \param msg Get message sent by the client.
     */
    void handleGet(SERVICE_APPLICATION* srvApp, SOMEIP_MESSAGE* msg) const
    {
        std::function<ara::core::Future<T>()> get_handler = RetrieveHandler(get_handler_);
        if (get_handler) {
            auto reply = get_handler().GetResult();

            std::shared_ptr<wrapper::WrsomeipPayload> payload = std::make_shared<wrapper::WrsomeipPayload>();
            payload->set_data(msg->pPld->pData, msg->pPld->size);
            std::shared_ptr<wrapper::WrsomeipMessage> response = std::make_shared<wrapper::WrsomeipMessage>();
            response->set_payload(payload);
            response->set_method(msg->pHdr->method);
            response->set_client(msg->pHdr->client);
            response->set_service(msg->pHdr->service);
            response->set_instance(msg->pHdr->instance);
            response->set_reliable(msg->isLoc);
            response->set_session(msg->pHdr->session);
            response->set_interface_version(msg->pHdr->ifaceVer);
            response->set_message_type(msg->pHdr->msgType);
            response->set_return_code(msg->pHdr->retCode);

            ServiceImplBase::SendReply(reply, response);
        } else {
            throw IllegalStateException("No Get handler registered!");
        }
    }
};

// Mutable field implementation for Skeleton service interface
template <typename T, typename FieldDescriptor>
class MutableFieldImpl
    : public internal::skeleton::MutableField<T>
    , public FieldImpl<T, FieldDescriptor>
{
public:
    using Base = FieldImpl<T, FieldDescriptor>;
    using typename internal::skeleton::MutableField<T>::SetMethodSignature;

    explicit MutableFieldImpl(types::InstanceId instance)
        : FieldImpl<T, FieldDescriptor>(instance)
    {
        runtime::WrSomeIPConnection& connection = runtime::WrSomeIPConnection::getInstance();
        auto lam = [this](SERVICE_APPLICATION* srvApp, SOMEIP_MESSAGE* msg) { handleSet(srvApp, msg); };
        static auto s_lam = lam;
        common::registerMethodHandler(connection.pClientApp,
            FieldDescriptor::service_id,
            instance,
            FieldDescriptor::set_method_id,
            [](SERVICE_APPLICATION* srvApp, SOMEIP_MESSAGE* msg) { s_lam(srvApp, msg); });
    }

    virtual void RegisterSetHandler(std::function<SetMethodSignature> handler) override
    {
        Base::PutHandler(set_handler_, std::move(handler));
    }

private:
    std::function<SetMethodSignature> set_handler_;
    /**
     * \brief  This function handles a Set() call from the client.
     * \param msg The message contains the data the value of the field shall be set to.
     */
    void handleSet(SERVICE_APPLICATION* srvApp, SOMEIP_MESSAGE* msg)
    {
        std::function<SetMethodSignature> set_handler = Base::RetrieveHandler(set_handler_);
        if (set_handler) {
            std::shared_ptr<wrapper::WrsomeipPayload> payload = std::make_shared<wrapper::WrsomeipPayload>();
            payload->set_data(msg->pPld->pData, msg->pPld->size);
            std::shared_ptr<wrapper::WrsomeipMessage> response = std::make_shared<wrapper::WrsomeipMessage>();
            response->set_payload(payload);
            response->set_method(msg->pHdr->method);
            response->set_client(msg->pHdr->client);
            response->set_service(msg->pHdr->service);
            response->set_instance(msg->pHdr->instance);
            response->set_reliable(msg->isLoc);
            response->set_session(msg->pHdr->session);
            response->set_interface_version(msg->pHdr->ifaceVer);
            response->set_message_type(msg->pHdr->msgType);
            response->set_return_code(msg->pHdr->retCode);

            common::Unmarshaller<T> unmarshaller(response);
            T value_to_set = unmarshaller.template unmarshal<0>();
            auto reply = set_handler(value_to_set).GetResult();
            ServiceImplBase::SendReply(reply, response);

        } else {
            throw IllegalStateException("No Set handler registered!");
        }
    }
};

}  // namespace skeleton
}  // namespace wrsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara
