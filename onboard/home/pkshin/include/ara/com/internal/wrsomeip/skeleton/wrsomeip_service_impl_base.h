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
#include <deque>
#include <mutex>

#include "ara/com/types.h"
#include "ara/com/illegal_state_exception.h"
#include "ara/com/internal/skeleton/service_impl_base.h"
#include "ara/com/internal/wrsomeip/wrsomeip_common.h"
#include "ara/com/internal/wrsomeip/wrsomeip_connection.h"
#include "ara/com/internal/wrsomeip/wrsomeip_marshalling.h"
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

// Service base implementation for Skeleton interface
class ServiceImplBase : public internal::skeleton::ServiceImplBase
{
public:
    using testtype = void;

    ServiceImplBase(internal::skeleton::ServiceBase& service, types::InstanceId instance)
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
            request();
            promise.set_value(true);
        } else {
            promise.set_value(false);
        }

        return promise.get_future();
    }

    // Register the method handler for dispatching
    template <typename Dispatcher>
    void RegisterMethodDispatcher(types::ServiceId service_id, types::MethodId method_id, Dispatcher&& dispatcher)
    {
        runtime::WrSomeIPConnection& connection = runtime::WrSomeIPConnection::getInstance();
        common::registerMethodHandler(
            connection.pClientApp, service_id, GetInstanceId(), method_id, {std::forward<Dispatcher>(dispatcher)});
    }

    // Unregister the callable for a method for this skeleton
    void UnregisterMethodDispatcher(types::ServiceId service_id, types::MethodId method_id)
    {
        runtime::WrSomeIPConnection& connection = runtime::WrSomeIPConnection::getInstance();
        common::unregisterMethodHandler(connection.pClientApp, service_id, GetInstanceId(), method_id);
    }

    types::InstanceId GetInstanceId() const
    {
        return instance_id_;
    }

    // Offer Service to consume
    static STATUS OfferService(types::ServiceId _sd_service,
        types::InstanceId _instance,
        types::major_version_t _major,
        types::minor_version_t _minor);

    // Stop offering this service interface
    static STATUS StopOfferService(types::ServiceId _sd_service,
        types::InstanceId _instance,
        types::major_version_t _major,
        types::minor_version_t _minor);
    /**
     * \brief Send a reply from Skeleton for a incomeing request
     * \param reply Make the reply message from skelton fot the proxy request
     * \param request Incoming request from the proxy
     */
    template <typename R>
    static void SendValueReply(R&& reply, std::shared_ptr<wrapper::WrsomeipMessage> request)
    {
        runtime::WrSomeIPConnection& connection = runtime::WrSomeIPConnection::getInstance();
        std::shared_ptr<wrapper::WrsomeipMessage> reply_message = MakeReplyMessage(std::forward<R>(reply), request);
        connection.getApplication().send_response(connection.pClientApp, reply_message);
    }
    /**
     * @brief Send Reply to the proxy
     *
     * Here no common shared memory is used to send the reply
     * @param request Incoming request from the proxy
     */
    static void SendValueReply(std::shared_ptr<wrapper::WrsomeipMessage> request)
    {
        using runtime::WrSomeIPConnection;
        runtime::WrSomeIPConnection& connection = runtime::WrSomeIPConnection::getInstance();
        std::shared_ptr<wrapper::WrsomeipMessage> reply_message = connection.getRuntime().create_response(request);
        connection.getApplication().send_response(connection.pClientApp, reply_message);
    }

    // Send a reply from Skeleton for a incoming request
    template <typename T>
    static void SendReply(ara::core::Result<T> reply, std::shared_ptr<wrapper::WrsomeipMessage> request)
    {
        if (reply.HasValue()) {
            SendValueReply(reply.Value(), request);
        } else {
            SendErrorReply(reply.Error(), request);
        }
    }

    static void SendReply(ara::core::Result<void> reply, std::shared_ptr<wrapper::WrsomeipMessage> request)
    {
        if (reply.HasValue()) {
            SendValueReply(request);
        } else {
            SendErrorReply(reply.Error(), request);
        }
    }

    // Send an error message after serialize
    static void SendErrorReply(const ara::core::ErrorCode& error, std::shared_ptr<wrapper::WrsomeipMessage> request)
    {
        using ara::com::internal::wrsomeip::common::Marshaller;
        runtime::WrSomeIPConnection& connection = runtime::WrSomeIPConnection::getInstance();
        wrapper::WrsomeipRuntime& runtime = connection.getRuntime();

        std::shared_ptr<wrapper::WrsomeipMessage> reply_message = runtime.create_response(request);
        reply_message->set_return_code(E_NOT_OK);

        ara::core::Vector<types::byte_t> data;
        Marshaller marshaller(data);
        marshaller.marshal(error);

        std::shared_ptr<wrapper::WrsomeipPayload> payload = runtime.create_payload(data);
        reply_message->set_payload(payload);
        // reply with serialized error message
        connection.getApplication().send_response(connection.pClientApp, reply_message);
    }

    // Send Reply to the proxy
    static void SendReply(std::shared_ptr<wrapper::WrsomeipMessage> request)
    {
        runtime::WrSomeIPConnection& connection = runtime::WrSomeIPConnection::getInstance();
        std::shared_ptr<wrapper::WrsomeipMessage> reply_message = connection.getRuntime().create_response(request);
        connection.getApplication().send_response(connection.pClientApp, reply_message);
    }

    template <typename Class, typename R, typename... Args>
    void HandleCall(Class& c,
        ara::core::Future<R> (Class::*method)(Args...),
        std::shared_ptr<wrapper::WrsomeipMessage> request)
    {
        PendingRequest todo = [&c, method, request]() {
            ara::core::Future<R> future = UnmarshalAndCall(c, method, request, std::index_sequence_for<Args...>());
            auto result = future.GetResult();
            SendReply(result, request);
        };
        ExecuteCall(std::move(todo));
    }

    template <typename Class, typename... Args>
    void HandleCall(Class& c, void (Class::*method)(Args...), std::shared_ptr<wrapper::WrsomeipMessage> request)
    {
        ExecuteCall(
            [&c, method, request]() { UnmarshalAndCall(c, method, request, std::index_sequence_for<Args...>()); });
    }

protected:
    internal::skeleton::ServiceBase& service_;
    template <std::size_t N>
    static void OfferEvent(types::ServiceId service_id,
        types::InstanceId instance_id,
        types::EventId event_id,
        const types::EventGroup (&event_groups)[N])
    {
        OfferEventCaller<N>(service_id, instance_id, event_id, event_groups, false);
    }

    template <std::size_t N>
    static void OfferField(types::ServiceId service_id,
        types::InstanceId instance_id,
        types::EventId event_id,
        const types::EventGroup (&event_groups)[N])
    {
        OfferEventCaller<N>(service_id, instance_id, event_id, event_groups, true);
    }

    template <std::size_t N>
    static void StopOfferEvent(types::ServiceId service_id,
        types::InstanceId instance_id,
        types::event_t event_id,
        const types::EventGroup (&event_groups)[N])
    {
        using runtime::WrSomeIPConnection;
        WrSomeIPConnection& connection = WrSomeIPConnection::getInstance();

        if (event_id == types::UndefinedEventId) {
            return;
        }
        runtime::WrSomeIPConnection::getInstance().getApplication().stop_offer_event(connection.pClientApp,
            service_id,
            instance_id,
            event_id,
            std::set<types::EventGroup>(std::begin(event_groups), std::end(event_groups)));
    }

private:
    using PendingRequest = std::function<void(void)>;
    using PendingRequestList = std::deque<PendingRequest>;

    template <std::size_t N>
    static void OfferEventCaller(types::ServiceId service_id,
        types::InstanceId instance_id,
        types::EventId event_id,
        const types::EventGroup (&event_groups)[N],
        bool isField)
    {
        using runtime::WrSomeIPConnection;
        WrSomeIPConnection& connection = WrSomeIPConnection::getInstance();

        if (event_id == types::UndefinedEventId) {
            logger::log().LogDebug() << "Undefined event. Skip offering";
            return;
        }
        connection.getApplication().offer_event(connection.pClientApp,
            service_id,
            instance_id,
            event_id,
            std::set<types::EventGroup>(std::begin(event_groups), std::end(event_groups)),
            isField);
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
        std::shared_ptr<wrapper::WrsomeipMessage> request,
        std::index_sequence<I...>)
    {
        common::Unmarshaller<Args...> unmarshaller(request);
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
        std::shared_ptr<wrapper::WrsomeipMessage> request,
        std::index_sequence<I...>)
    {
        common::Unmarshaller<Args...> unmarshaller(request);
        return (c.*method)(unmarshaller.template unmarshal<I>()...);
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

    /**
     * \brief Serialize and make the reply for incoming proxy request
     * \param reply Message send to proxy from the skeleton
     * \param request Incoming mesage from the proxy
     * \return Serialized payload
     */
    template <typename R>
    static std::shared_ptr<wrapper::WrsomeipMessage> MakeReplyMessage(R&& reply,
        std::shared_ptr<wrapper::WrsomeipMessage> request)
    {
        runtime::WrSomeIPConnection& wrsomeip_instance = runtime::WrSomeIPConnection::getInstance();
        std::shared_ptr<wrapper::WrsomeipMessage> reply_message
            = wrsomeip_instance.getRuntime().create_response(request);
        // Here we serialize all struct members one by one by using 'SerializingEnumerator' on all struct
        // members via its 'enumerate' method, which is generated by aragen.
        std::vector<types::byte_t> reply_data;
        // Get rid of cv-qualifiers. Without this, an R that is "const T" won't match
        // the Serializer<ara::core::String> specialization.
        using S = typename std::decay<R>::type;
        common::Serializer<S> serializer(reply);
        serializer.pushbackTo(reply_data);

        std::shared_ptr<wrapper::WrsomeipPayload> reply_payload
            = wrsomeip_instance.getRuntime().create_payload(std::move(reply_data));
        reply_message->set_payload(reply_payload);
        return reply_message;
    }

    PendingRequestList pending_requests_;
    MethodCallProcessingMode request_processing_mode_{MethodCallProcessingMode::kEvent};
    std::mutex requests_mutex_;
    types::InstanceId instance_id_;
};

}  // namespace skeleton
}  // namespace wrsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara
