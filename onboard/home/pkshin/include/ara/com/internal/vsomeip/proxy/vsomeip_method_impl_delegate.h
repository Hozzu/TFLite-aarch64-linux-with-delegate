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

#ifndef VSOMEIP_PROXY_METHOD_IMPL_DELEGATE_H
#define VSOMEIP_PROXY_METHOD_IMPL_DELEGATE_H

#include <exception>
#include <mutex>
#include <utility>
#include <unordered_map>
#include <vsomeip/vsomeip.hpp>
#include <type_traits>

#include "ara/com/internal/proxy/method.h"
#include "ara/core/future.h"
#include "ara/core/promise.h"
#include "ara/com/com_error_domain.h"
#include "ara/com/internal/vsomeip/vsomeip_connection.h"
#include "ara/com/internal/vsomeip/vsomeip_common.h"
#include "ara/com/internal/vsomeip/vsomeip_marshalling.h"

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

namespace detail
{

/// \brief Call the method when response is an excepton
///
/// If the response status code is an exception rather a valid result
/// then it deserialize the exception and set it.
/// \param result Result set for ara::core::Promise
/// \param response Response recieved from vsomeip daemon
template <typename R>
void SetError(ara::core::Promise<R>&& result, const std::shared_ptr<::vsomeip::message>& response)
{
    ::vsomeip::payload& payload = *response->get_payload();
    common::Deserializer<ara::core::ErrorCode> deserializer(payload.get_data(), payload.get_length());
    ara::core::ErrorCode errorCode = deserializer.getValue();
    result.SetError(std::move(errorCode));
}

/// \brief Sets the promise to result
/// \param result ara::core::Promise that hold the result
/// \param response Message response for deserialization
template <typename R>
void SetResult(ara::core::Promise<R>&& result, const std::shared_ptr<::vsomeip::message>& response)
{
    // This section applies the functor "DeserializingEnumerator" to all members of the result struct via it's
    // 'enumerate' method, which is generated by aragen.
    // Since DeserializingEnumerator's operator() obtains references to the struct member, it is able
    // to assign them the deserialized values.
    ::vsomeip::payload& payload = *response->get_payload();
    common::Deserializer<R> deserializer(payload.get_data(), payload.get_length());
    result.set_value(deserializer.getValue());
}
inline void SetResult(ara::core::Promise<void>&& result, const std::shared_ptr<::vsomeip::message>& response)
{
    static_cast<void>(response);
    result.set_value();
}

/// \brief Move response to ara::core::Promise and deserialize it
/// \param result Holds the response if vsome return code is E_OK
/// \param response Message response to set promise for deserialization
template <typename R>
void DeserializeAndSetPromise(ara::core::Promise<R>&& result, const std::shared_ptr<::vsomeip::message>& response)
{
    if (response->get_return_code() == ::vsomeip::return_code_e::E_OK) {
        SetResult(std::move(result), response);
    } else {
        SetError(std::move(result), response);
    }
}

/// \brief AddPayload create the payload data after marshalling
/// \param connection VSomeIP connection used for creating the request
/// \param request Message sent before marshalling
/// \param args Variadic arguments for creating the request
template <typename... Args>
void AddPayload(internal::vsomeip::runtime::VSomeIPConnection& connection,
    std::shared_ptr<::vsomeip::message>& request,
    Args&&... args)
{
    std::shared_ptr<::vsomeip::payload> payload = connection.getRuntime().create_payload();
    ara::core::Vector<::vsomeip::byte_t> its_payload_data;
    common::Marshaller(its_payload_data).marshal(std::forward<Args>(args)...);

    payload->set_data(its_payload_data);
    request->set_payload(payload);
}

/// Creates an empty payload
/// \param connection VSomeIP connection used for the request
/// \param request Message sent as request
inline void AddPayload(internal::vsomeip::runtime::VSomeIPConnection& connection,
    std::shared_ptr<::vsomeip::message>& request)
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
        using internal::vsomeip::runtime::VSomeIPConnection;

        VSomeIPConnection& connection = VSomeIPConnection::getInstance();
        std::shared_ptr<::vsomeip::message> request = CreateRequest(connection, instance_, std::forward<Args>(args)...);

        ara::core::Promise<ResultType> promise;
        auto future = promise.get_future();

        std::lock_guard<std::mutex> lock_guard(pending_requests_lock_);
        connection.getApplication().send(request, true);
        Request r = std::make_pair(request, std::move(promise));
        addPendingRequest(std::move(r));

        return future;
    }

    void handleCallResult(const std::shared_ptr<::vsomeip::message>& response)
    {
        std::lock_guard<std::mutex> lock_guard(pending_requests_lock_);
        onMessage(response);
    }

    types::InstanceId instance() const
    {
        return instance_;
    }

private:
    // Promise and request
    using Request = std::pair<std::shared_ptr<::vsomeip::message>, ara::core::Promise<ResultType>>;
    using PendingRequestMap = std::unordered_map<types::RequestId, Request>;
    PendingRequestMap pending_requests_;

    std::mutex pending_requests_lock_;
    types::InstanceId instance_;
    types::SessionId sessionId_;

    template <typename E>
    static constexpr auto toUnderlyingType(E e) -> std::underlying_type_t<E>
    {
        return static_cast<std::underlying_type_t<E>>(e);
    }

    /// @uptrace{SWS_CM_10312, 6e2c76ceb2f09f52f1b3c416aac2e0e6c086f14f}
    /// @uptrace{SWS_CM_10313, bab2988e7ab4b6c195deb763750aeb9eee9fe109}
    /// @uptrace{SWS_CM_10345, 995b3e4c18963db99763d8bdd77795815cca6126}
    static bool validateMessage(const ::vsomeip::message& request, const ::vsomeip::message& response)
    {
        bool result = common::checkMessageMetaData(response,
            MethodDescriptor::service_id,
            MethodDescriptor::method_id,
            MethodDescriptor::service_version_major,
            ::ara::com::internal::vsomeip::types::MessageTypeResponse,
            ::ara::com::internal::vsomeip::types::MessageTypeError,
            true);

        if (response.get_client() != request.get_client()) {
            result = false;
            common::logger().LogWarn() << "Incorrect client id:" << response.get_client() << " Vs "
                                       << request.get_client();
        }
        if (response.get_session() != request.get_session()) {
            result = false;
            common::logger().LogWarn() << "Incorrect session id:" << response.get_session() << " Vs "
                                       << request.get_session();
        }
        return result;
    }

    /// \brief This is a callback function
    ///
    /// On message arrival checks if the message already in the map and remove
    /// if match. Also process the response.
    /// \param response Message received as response from vsomeip
    /// @uptrace{SWS_CM_10358, b8515e4e70f7b90ac62dd3589d78aa8236175bce}
    void onMessage(const std::shared_ptr<::vsomeip::message>& response)
    {
        types::RequestId request_id = response->get_request();
        typename PendingRequestMap::iterator it = pending_requests_.find(request_id);
        if (it != pending_requests_.end()) {
            if (validateMessage(*it->second.first, *response)) {
                detail::DeserializeAndSetPromise(std::move(it->second.second), response);
            } else {
                common::logger().LogWarn() << "Discarding invalid message";
                it->second.second.SetError(ara::core::ErrorCode{ara::com::ComErrorDomainErrc::kNetworkBindingFailure});
            }
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
        types::RequestId request_id = request.first->get_request();
        pending_requests_.emplace(request_id, std::move(request));
    }

    /// \brief Create request messsage for methods
    /// \param connection VSomeIP connection used for creating request
    /// \param instance Service instance the request shall be sent to
    /// \param args  It's the request's arguments and it is variadic as it depends on the method signature
    /// \return vsomeip request message
    /// @uptrace{SWS_CM_10345, 995b3e4c18963db99763d8bdd77795815cca6126}
    template <typename... Args>
    std::shared_ptr<::vsomeip::message> CreateRequest(internal::vsomeip::runtime::VSomeIPConnection& connection,
        types::InstanceId instance,
        Args&&... args)
    {
        common::abort(!common::isMethodUndefined(MethodDescriptor::method_id));

        std::shared_ptr<::vsomeip::message> request
            = connection.getRuntime().create_request(MethodDescriptor::is_reliable);

        request->set_service(MethodDescriptor::service_id);
        request->set_instance(instance);
        request->set_method(MethodDescriptor::method_id);
        request->set_interface_version(MethodDescriptor::service_version_major);
        request->set_session(++sessionId_);
        // request->set_client(...); // No need do this, vsomeip will handle it

        detail::AddPayload(connection, request, std::forward<Args>(args)...);
        return request;
    }
};

}  // namespace proxy
}  // namespace vsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // VSOMEIP_PROXY_METHOD_IMPL_DELEGATE_H
