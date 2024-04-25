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

#ifndef WRSOMEIP_PROXY_METHOD_IMPL_DELEGATE_H
#define WRSOMEIP_PROXY_METHOD_IMPL_DELEGATE_H

#include <exception>
#include <mutex>
#include <utility>
#include <unordered_map>
#include <type_traits>

#include "ara/com/internal/proxy/method.h"
#include "ara/core/future.h"
#include "ara/core/promise.h"
#include "ara/com/com_error_domain.h"
#include "ara/com/internal/wrsomeip/wrsomeip_connection.h"
#include "ara/com/internal/wrsomeip/wrsomeip_common.h"
#include "ara/com/internal/wrsomeip/wrsomeip_marshalling.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace wrsomeip
{
namespace proxy
{

namespace detail
{

/// \brief Call the method when response is an excepton
///
/// If the response status code is an exception rather a valid result
/// then it deserialize the exception and set it.
/// \param result Result set for ara::com::Promise
/// \param response Response recieved from wrsomeip daemon
template <typename R>
void SetError(ara::core::Promise<R>&& result, const std::shared_ptr<wrapper::WrsomeipMessage>& response)
{
    wrapper::WrsomeipPayload& wrPayload = *response->get_payload();
    common::Deserializer<ara::core::ErrorCode> deserializer(wrPayload.get_data(), wrPayload.get_length());
    ara::core::ErrorCode errorCode = deserializer.getValue();
    result.SetError(std::move(errorCode));
}

/// \brief Sets the promise to result
/// \param result ara::com::Promise that hold the result
/// \param response Message response for deserialization
template <typename R>
void SetResult(ara::core::Promise<R>&& result, const std::shared_ptr<wrapper::WrsomeipMessage>& response)
{
    wrapper::WrsomeipPayload& wrPayload = *response->get_payload();
    types::SomeIpPayload payload = wrPayload.cast_to_wrsomeip_payload(wrPayload);
    common::Deserializer<R> deserializer(payload->pData, payload->size);
    result.set_value(deserializer.getValue());
}
// also to accept void result ->promise
inline void SetResult(ara::core::Promise<void>&& result, const std::shared_ptr<wrapper::WrsomeipMessage>& response)
{
    static_cast<void>(response);
    result.set_value();
}

/// \brief Move response to ara::com::Promise and deserialize it
/// \param result Holds the response if vsome return code is E_OK
/// \param response Message response to set promise for deserialization
template <typename R>
void DeserializeAndSetPromise(ara::core::Promise<R>&& result, const std::shared_ptr<wrapper::WrsomeipMessage>& response)
{
    if (response->get_return_code() == E_OK) {
        SetResult(std::move(result), response);
    } else {
        SetError(std::move(result), response);
    }
}

/// \brief AddPayload create the payload data after marshalling
/// \param connection WrSomeip connection used for creating the request
/// \param request Message sent before marshalling
/// \param args Variadic arguments for creating the request
template <typename... Args>
void AddPayload(internal::wrsomeip::runtime::WrSomeIPConnection& connection,
    std::shared_ptr<wrapper::WrsomeipMessage>& request,
    Args&&... args)
{
    // Note: create_payload() returns pointer to WrsomeipPayload object
    std::shared_ptr<wrapper::WrsomeipPayload> payload = connection.getRuntime().create_payload();
    ara::core::Vector<types::byte_t> its_payload_data;
    common::Marshaller(its_payload_data).marshal(std::forward<Args>(args)...);

    payload->set_data(its_payload_data.data(), its_payload_data.size());
    request->set_payload(payload);
}

/// \brief Creates an empty payload
/// \param connection WrSomeIP connection used for the request
/// \param request Message sent as request
inline void AddPayload(internal::wrsomeip::runtime::WrSomeIPConnection& connection,
    std::shared_ptr<wrapper::WrsomeipMessage>& request)
{
    static_cast<void>(connection);
    static_cast<void>(request);
}

}  // namespace detail

// Template specialization for MethodImpl using a method descriptor and a function signature
template <typename MethodDescriptor, typename ResultType>
class MethodImplDelegate
{
public:
    explicit MethodImplDelegate(types::InstanceId instance)
        : instance_(instance)
        , sessionId_(0)
    { }

    template <typename... Args>
    ara::core::Future<ResultType> startCall(Args&&... args)
    {
        using runtime::WrSomeIPConnection;

        wrapper::WrsomeipApplication wrs_app;
        WrSomeIPConnection& connection = WrSomeIPConnection::getInstance();
        std::shared_ptr<wrapper::WrsomeipMessage> request
            = CreateRequest(connection, instance_, std::forward<Args>(args)...);

        ara::core::Promise<ResultType> promise;
        ara::core::Future<ResultType> future = promise.get_future();

        std::lock_guard<std::mutex> lock_guard(pending_requests_lock_);
        types::ServiceApplication* inst = WrSomeIPConnection::getInstance().pClientApp;
        wrs_app = connection.getApplication();
        wrs_app.send(inst, MethodDescriptor::service_id, instance_, request);
        Request r = std::make_pair(request, std::move(promise));
        addPendingRequest(std::move(r));

        return future;
    }

    void handleCallResult(SERVICE_APPLICATION* srvApp, SOMEIP_MESSAGE* msg)
    {
        std::lock_guard<std::mutex> lock_guard(pending_requests_lock_);
        onMessage(srvApp, msg);
    }

    types::InstanceId instance() const
    {
        return instance_;
    }

private:
    // Promise and request
    using Request = std::pair<std::shared_ptr<wrapper::WrsomeipMessage>, ara::core::Promise<ResultType>>;
    using PendingRequestMap = std::unordered_map<types::request_t, Request>;
    PendingRequestMap pending_requests_;

    std::mutex pending_requests_lock_;
    types::InstanceId instance_;
    types::session_t sessionId_;

    template <typename E>
    static constexpr auto toUnderlyingType(E e) -> std::underlying_type_t<E>
    {
        return static_cast<std::underlying_type_t<E>>(e);
    }

    // TODO: Check if the SERVICE_APPLICATION pointer is needed.
    void onMessage(__attribute__((unused)) SERVICE_APPLICATION* srvApp, SOMEIP_MESSAGE* msg)
    {
        types::request_t request_id = CONVERT_WORD_TO_LONG(msg->pHdr->client, msg->pHdr->session);
        typename PendingRequestMap::iterator it = pending_requests_.find(request_id);
        if (it != pending_requests_.end()) {
            // TODO: Validate incoming message
            std::shared_ptr<wrapper::WrsomeipPayload> payload = std::make_shared<wrapper::WrsomeipPayload>();
            payload->set_data(msg->pPld->pData, msg->pPld->size);
            std::shared_ptr<wrapper::WrsomeipMessage> response = std::make_shared<wrapper::WrsomeipMessage>();
            response->set_payload(payload);
            detail::DeserializeAndSetPromise(std::move(it->second.second), response);
            pending_requests_.erase(it);
        }
    }

    /// \brief  Store the request in the PendingRequestMap to be processed
    ///
    /// Add the request so that \ref onMessage can find it to forward the result to the promise that finally sets the
    /// future to ready.
    /// \param request Request sends
    /// \param promise Shall be set if the response arrives
    void addPendingRequest(Request&& request)
    {
        types::request_t request_id = request.first->get_request();
        pending_requests_.emplace(request_id, std::move(request));
    }

    /// \brief Create request messsage for methods
    /// \param connection WrSomeIP connection used for creating request
    /// \param instance Service instance the request shall be sent to
    /// \param args  It's the request's arguments and it is variadic as it depends on the method signature
    /// \return someiprequest message
    template <typename... Args>
    std::shared_ptr<wrapper::WrsomeipMessage> CreateRequest(internal::wrsomeip::runtime::WrSomeIPConnection& connection,
        types::InstanceId instance,
        Args&&... args)
    {
        common::abort(MethodDescriptor::method_id != types::UndefinedMethodId);

        std::shared_ptr<wrapper::WrsomeipMessage> request = connection.getRuntime().create_request();

        request->set_service(MethodDescriptor::service_id);
        request->set_instance(instance);
        request->set_method(MethodDescriptor::method_id);
        request->set_interface_version(MethodDescriptor::service_version);
        request->set_session(++sessionId_);

        detail::AddPayload(connection, request, std::forward<Args>(args)...);
        return request;
    }
};

}  // namespace proxy
}  // namespace wrsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // WRSOMEIP_PROXY_METHOD_IMPL_DELEGATE_H
