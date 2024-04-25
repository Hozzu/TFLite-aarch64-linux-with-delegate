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

#ifndef LIB_APDREST_INCLUDE_APD_REST_HTTPCLIENT_H_
#define LIB_APDREST_INCLUDE_APD_REST_HTTPCLIENT_H_

#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "apd/rest/allocator.h"
#include "apd/rest/client.h"
#include "apd/rest/client_interface.h"
#include "apd/rest/config.h"

#include "ara/log/logger.h"

namespace apd
{
namespace rest
{
namespace test
{
class HttpClient_ConvertReply_Test;
}  // namespace test

namespace internal
{

class HttpClientSessionAuthorityGuard
{
    Poco::Net::HTTPClientSession& session_;
    std::string host_;
    Poco::UInt16 port_;

public:
    HttpClientSessionAuthorityGuard(Poco::Net::HTTPClientSession& session,
        const std::string& host,
        Poco::UInt16 port = Poco::Net::HTTPSession::HTTP_PORT);
    ~HttpClientSessionAuthorityGuard();
};

}  // namespace internal

/**
 * TODO
 */
class HttpClient : public ClientInterface
{
    friend class test::HttpClient_ConvertReply_Test;  /// for testing

public:
    /**
     * TODO
     * \param config
     * \param allocator
     */
    explicit HttpClient(const String& config, Allocator* allocator = GetDefaultAllocator());

    /**
     * TODO
     * @param req
     * @return
     * \uptrace{SWS_REST_01859}
     */
    Task<Pointer<Reply>> Send(const Request& req) override;

    /**
     * TODO
     * @param policy
     * @return
     */
    Task<void> Stop(ShutdownPolicy policy = ShutdownPolicy::kGraceful) override;

    /**
     * \brief Performs an event subscription
     *
     *  \param uri the event to subscribe to
     *  \param policy the notification policy
     *  \param time time bound as a parameter of the notification policy
     *  \param notify user-defined event notification handler function
     *  \param state user-define subscription state observer function
     *  \return a task waiting for the Event construction and subscription Reply.
     */
    Task<Event> Subscribe(const Uri& uri,
        EventPolicy policy,
        duration_t time,
        const Function<Client::NotificationHandlerType>& notify,
        const Function<Client::SubscriptionStateHandlerType>& state = {}) override;

private:
    /**
     * Instance of an Poco Http Session
     */
    Pointer<Poco::Net::HTTPClientSession> poco_http_session_;
    /**
     * Converts an apd::rest::RequestMethod to poco request method representation
     * \param req_method RequestMethod to convert
     * \return String representation
     */
    String DeterminePocoHttpRequestMethod(RequestMethod req_method);

    /**
     * \brief
     */
    config::ClientBinding client_binding_;

    /**
     * convert poco response to apd::rest:Response
     * \param from
     * \param uri
     * \param obj_serialized
     * \returns a Pointer to the apd::rest:Reply
     */
    Pointer<Reply> ConvertResponse(const Poco::Net::HTTPResponse& from, const Uri& uri, std::istream& obj_serialized);

    /**
     * \brief logging context instance
     */
    ara::log::Logger& log_{ara::log::CreateLogger("HCLR", "Logger for Http Client REST", ara::log::LogLevel::kVerbose)};
};

}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_HTTPCLIENT_H_
