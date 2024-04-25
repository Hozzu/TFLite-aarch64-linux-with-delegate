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

#ifndef VSOMEIP_SKELETON_SERVICE_IMPL_BASE_H
#define VSOMEIP_SKELETON_SERVICE_IMPL_BASE_H

#include <deque>
#include <mutex>

#include <vsomeip/vsomeip.hpp>

#include "ara/com/types.h"
#include "ara/core/future.h"
#include "ara/core/promise.h"
#include "ara/core/error_code.h"
#include "ara/core/result.h"
#include "ara/com/illegal_state_exception.h"
#include "ara/com/internal/skeleton/service_impl_base.h"
#include "ara/com/internal/vsomeip/vsomeip_common.h"
#include "ara/com/internal/vsomeip/vsomeip_connection.h"
#include "ara/com/internal/vsomeip/vsomeip_marshalling.h"
#include "ara/com/internal/vsomeip/vsomeip_error.h"

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
 * \brief Service base implementation for Skeleton interface
 */
class ServiceImplBase : public internal::skeleton::ServiceImplBase
{
public:
    using testtype = void;

    ServiceImplBase(internal::skeleton::ServiceBase& service, ::vsomeip::instance_t instance)
        : internal::skeleton::ServiceImplBase(common::FromTransportIdentifier(instance))
        , service_(service)
        , instance_id_(instance)
    { }
    virtual ~ServiceImplBase()
    { }

    virtual void SetMethodCallProcessingMode(ara::com::MethodCallProcessingMode mode) override
    {
        // execute remaining requests in case we're switching away from kPoll
        std::lock_guard<std::mutex> guard(requests_mutex_);
        if ((request_processing_mode_ == MethodCallProcessingMode::kPoll)
            && (mode != MethodCallProcessingMode::kPoll)) {
            for (PendingRequest& request : pending_requests_) {
                request();
            }
            pending_requests_.clear();
        }

        request_processing_mode_ = mode;
    }

    virtual ara::core::Future<bool> ProcessNextMethodCall() override
    {
        PendingRequest request;
        {
            std::lock_guard<std::mutex> guard(requests_mutex_);

            if (request_processing_mode_ != MethodCallProcessingMode::kPoll) {
                throw IllegalStateException("ProcessNextMethodCall() called in non-polling mode!");
            }

            if (!pending_requests_.empty()) {
                request = std::move(pending_requests_.front());
                pending_requests_.pop_front();
            }
        }

        ara::core::Promise<bool> promise;
        if (request) {
            // TODO: Make this truly async
            request();
            promise.set_value(true);
        } else {
            promise.set_value(false);
        }

        return promise.get_future();
    }
    /**
     * \brief Register the method handler for dispatching
     * \param service_id Service id to register the method handler
     * \param dispatcher Is a callable that is called by the vsomeip daemon if a method call is arriving for this
     * skeleton
     */
    template <typename Dispatcher>
    void RegisterMethodDispatcher(types::ServiceId service_id, Dispatcher&& dispatcher)
    {
        common::registerMethodHandler(
            service_id, GetInstanceId(), ::vsomeip::ANY_METHOD, {std::forward<Dispatcher>(dispatcher)});
    }
    /**
     * \brief Unregister the callable for a method for this skeleton
     * \param service_id Service ID for this Service interface
     */
    void UnregisterMethodDispatcher(types::ServiceId service_id)
    {
        common::unregisterMethodHandler(service_id, GetInstanceId(), ::vsomeip::ANY_METHOD);
    }

    types::InstanceId GetInstanceId() const
    {
        return instance_id_;
    }
    /**
     * \brief Offer Service to consume
     * \param service_id Service ID of the service to offer
     * \param instance_id Instance ID of the service instance
     * \param service_version_major Major Service version of the service to offer
     * \param service_version_minor Minor service version of the service to offer
     */

    static void OfferService(types::ServiceId service_id,
        types::InstanceId instance_id,
        types::ServiceVersionMajor service_version_major,
        types::ServiceVersionMinor service_version_minor);
    /**
     * \brief Stop offering this service interface
     * \param service_id Service ID of this service interface
     * \param instance_id Instance ID of the service instance
     */
    static void StopOfferService(types::ServiceId service_id, types::InstanceId instance_id);
    /**
     * \brief Stop offering an Event
     * \param service_id Service ID of the event to offer
     * \param instance_id Instance ID of the event to offer
     * \param event_id Method ID of the event to offer
     */

    static void StopOfferEvent(types::ServiceId service_id, types::InstanceId instance_id, types::MethodId event_id);

    /**
     * \brief Stop offering a field
     * \param service_id Service ID the field to offer
     * \param instance_id Instance ID of the field to offer
     * \param event_id Method ID of the field to offer
     */
    static void StopOfferField(types::ServiceId service_id, types::InstanceId instance_id, types::MethodId event_id);

    template <std::size_t N>
    static void OfferEvent(types::ServiceId service_id,
        types::InstanceId instance_id,
        types::MethodId event_id,
        const ::vsomeip::eventgroup_t (&event_groups)[N])
    {
        OfferEvent<N>(service_id, instance_id, event_id, event_groups, false);
    }

    template <std::size_t N>
    static void OfferField(types::ServiceId service_id,
        types::InstanceId instance_id,
        types::MethodId event_id,
        const ::vsomeip::eventgroup_t (&event_groups)[N])
    {
        OfferEvent<N>(service_id, instance_id, event_id, event_groups, true);
    }
    /**
     * \brief Send a reply from Skeleton for a incomeing request
     * \param reply Make the reply message from skelton fot the proxy request
     * \param request Incoming request from the proxy
     */
    template <typename R>
    static void SendValueReply(R&& reply, std::shared_ptr<::vsomeip::message> request)
    {
        std::shared_ptr<::vsomeip::message> reply_message = MakeReplyMessage(std::forward<R>(reply), request);
        runtime::VSomeIPConnection::getInstance().getApplication().send(reply_message);
    }
    /**
     * \brief Send an error message after serialize
     * \param error Error message to send from server side
     * \param request Incoming request from the proxy
     */
    static void SendErrorReply(const ara::core::ErrorCode& error, std::shared_ptr<::vsomeip::message> request)
    {
        using runtime::VSomeIPConnection;
        using ara::com::internal::vsomeip::common::Marshaller;

        // This section calls serialize() method of a specific exception to serialize any
        // additional arguments + the ErrorCode

        VSomeIPConnection& vsomeip = VSomeIPConnection::getInstance();
        ::vsomeip::runtime& runtime = vsomeip.getRuntime();

        std::shared_ptr<::vsomeip::message> reply_message = runtime.create_response(request);

        /** @uptrace{SWS_CM_10312, 6e2c76ceb2f09f52f1b3c416aac2e0e6c086f14f} */
        reply_message->set_message_type(::vsomeip::message_type_e::MT_ERROR);
        reply_message->set_return_code(::vsomeip::return_code_e::E_NOT_OK);

        ara::core::Vector<::vsomeip::byte_t> data;
        Marshaller marshaller(data);
        marshaller.marshal(error);

        std::shared_ptr<::vsomeip::payload> payload = runtime.create_payload(data);
        reply_message->set_payload(payload);

        vsomeip.getApplication().send(reply_message);
    }

    /**
     * @brief Send Reply to the proxy
     *
     * Here no common shared memory is used to send the reply
     * @param request Incoming request from the proxy
     */
    static void SendValueReply(std::shared_ptr<::vsomeip::message> request)
    {
        using runtime::VSomeIPConnection;
        VSomeIPConnection& vsomeip = VSomeIPConnection::getInstance();
        std::shared_ptr<::vsomeip::message> reply_message = vsomeip.getRuntime().create_response(request);
        vsomeip.getApplication().send(reply_message);
    }

    template <typename T>
    static void SendReply(ara::core::Result<T> reply, std::shared_ptr<::vsomeip::message> request)
    {
        if (reply.HasValue()) {
            SendValueReply(reply.Value(), request);
        } else {
            SendErrorReply(reply.Error(), request);
        }
    }
    static void SendReply(ara::core::Result<void> reply, std::shared_ptr<::vsomeip::message> request)
    {
        if (reply.HasValue()) {
            SendValueReply(request);
        } else {
            SendErrorReply(reply.Error(), request);
        }
    }

    /**
     *\brief HandleCall for any functions
     */
    template <typename Class, typename R, typename... Args>
    void HandleCall(Class& c,
        ara::core::Future<R> (Class::*method)(Args...),
        std::shared_ptr<::vsomeip::message> request)
    {
        PendingRequest todo = [&c, method, request]() {
            ara::core::Future<R> future = UnmarshalAndCall(c, method, request, std::index_sequence_for<Args...>());
            auto result = future.GetResult();
            SendReply(result, request);
        };
        ExecuteCall(std::move(todo));
    }

    template <typename Class, typename... Args>
    void HandleCall(Class& c, void (Class::*method)(Args...), std::shared_ptr<::vsomeip::message> request)
    {
        ExecuteCall(
            [&c, method, request]() { UnmarshalAndCall(c, method, request, std::index_sequence_for<Args...>()); });
    }

protected:
    internal::skeleton::ServiceBase& service_;

private:
    using PendingRequest = std::function<void(void)>;
    using PendingRequestList = std::deque<PendingRequest>;

    template <std::size_t N>
    static void OfferEvent(types::ServiceId service_id,
        types::InstanceId instance_id,
        types::MethodId event_id,
        const ::vsomeip::eventgroup_t (&event_groups)[N],
        bool is_field)
    {
        if (common::isEventUndefined(event_id)) {
            common::logger().LogInfo() << "Skip offering undefined event";
            return;
        }

        runtime::VSomeIPConnection::getInstance().getApplication().offer_event(service_id,
            instance_id,
            event_id,
            std::set<::vsomeip::eventgroup_t>(std::begin(event_groups), std::end(event_groups)),
            is_field);
    }
    /**
     * \brief Unmarshall the request for void return-type
     * \param c Upcast to class
     * \param method Method requested from the proxy
     * \param request Requested mesage
     */
    template <typename Class, typename... Args, std::size_t... I>
    static void UnmarshalAndCall(Class& c,
        void (Class::*method)(Args...),
        std::shared_ptr<::vsomeip::message> request,
        std::index_sequence<I...>)
    {
        common::Unmarshaller<Args...> unmarshaller(*request);
        (c.*method)(unmarshaller.template unmarshal<I>()...);
    }
    /**
     * \brief Unmarshall the request received from Service consumer
     * \param c Upcast to class
     * \param method Method requested from the proxy
     * \param request Requested message
     * \return ???
     */
    template <typename Class, typename R, typename... Args, std::size_t... I>
    static R UnmarshalAndCall(Class& c,
        R (Class::*method)(Args...),
        std::shared_ptr<::vsomeip::message> request,
        std::index_sequence<I...>)
    {
        common::Unmarshaller<Args...> unmarshaller(*request);
        return (c.*method)(unmarshaller.template unmarshal<I>()...);
    }

    /**
     * \brief Serialize and make the reply for incoming proxy request
     * \param reply Message send to proxy from the skeleton
     * \param request Incoming mesage from the proxy
     * \return Serialized payload
     */
    template <typename R>
    static std::shared_ptr<::vsomeip::message> MakeReplyMessage(R&& reply, std::shared_ptr<::vsomeip::message> request)
    {
        using runtime::VSomeIPConnection;

        VSomeIPConnection& vsomeip = VSomeIPConnection::getInstance();
        std::shared_ptr<::vsomeip::message> reply_message = vsomeip.getRuntime().create_response(request);

        // Here we serialize all struct members one by one by using the functor 'SerializingEnumerator' on all struct
        // members via its 'enumerate' method, which is generated by aragen.
        ara::core::Vector<::vsomeip::byte_t> reply_data;
        common::Serializer<typename std::decay<R>::type> serializer(reply);
        serializer.pushbackTo(reply_data);

        std::shared_ptr<::vsomeip::payload> reply_payload = vsomeip.getRuntime().create_payload(std::move(reply_data));
        reply_message->set_payload(reply_payload);
        return reply_message;
    }
    /**
     * \brief Execute the processing mode
     * \param request Request pending to process on server side
     */

    void ExecuteCall(PendingRequest&& request)
    {
        std::unique_lock<std::mutex> lock(requests_mutex_);
        if (request_processing_mode_ == MethodCallProcessingMode::kEvent) {
            lock.unlock();
            auto t = std::thread(request);
            t.detach();
        } else if (request_processing_mode_ == MethodCallProcessingMode::kPoll) {
            pending_requests_.push_back(std::move(request));
        } else {
            lock.unlock();
            request();
        }
    }

    PendingRequestList pending_requests_;
    MethodCallProcessingMode request_processing_mode_{MethodCallProcessingMode::kEvent};
    std::mutex requests_mutex_;
    types::InstanceId instance_id_;
};
/**
 * @}
 */
}  // namespace skeleton
}  // namespace vsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // VSOMEIP_SKELETON_SERVICE_IMPL_BASE_H
