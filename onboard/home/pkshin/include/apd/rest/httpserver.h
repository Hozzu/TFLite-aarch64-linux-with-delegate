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

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#ifndef LIB_APDREST_INCLUDE_APD_REST_HTTPSERVER_H_
#define LIB_APDREST_INCLUDE_APD_REST_HTTPSERVER_H_

#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/NetException.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/WebSocket.h>
#include <Poco/Util/ServerApplication.h>

#include <condition_variable>
#include <memory>
#include <mutex>
#include <string>
#include <utility>
#include <vector>

#include "apd/rest/config.h"
#include "apd/rest/cpp14_backport.h"
#include "apd/rest/endpoint.h"
#include "apd/rest/function.h"
#include "apd/rest/header.h"
#include "apd/rest/serialize/serialize.h"
#include "apd/rest/server_interface.h"
#include "apd/rest/server_reply_interface.h"
#include "apd/rest/server_types.h"

#include "ara/log/logger.h"

namespace apd
{
namespace rest
{

class ServerRequest;  //< fwd
class ServerReply;  //< fwd

class HttpServer;  //< fwd

/**********************************************************************************************************************
 *  HttpServerReply
 *********************************************************************************************************************/

/**
 * Implementation of ServerReplyInterface
 */
class HttpServerReply : public ServerReplyInterface
{
public:
    /**
     * Default CTOR
     */
    HttpServerReply() = default;

    /**
     * CTOR
     * \param poco_response
     */
    explicit HttpServerReply(Poco::Net::HTTPServerResponse* poco_response);

    explicit HttpServerReply(const HttpServerReply&) = delete;  ///< Non-copyable
    HttpServerReply& operator=(const HttpServerReply&) = delete;  ///< Non-copy-assignable

    /**
     * Destructor
     */
    ~HttpServerReply() = default;

    /** \brief Send a reply to the peer that has issued the request
     *
     *  If this function is not invoked explicitly, the endpoint will transmit a default reply.
     *  If Redirect() has been before called, these functions must be used.
     *
     * \param data payload to be transmitted
     * \param status
     * \return a task waiting for the transmission to complete
     * \uptrace{SWS_REST_01859}
     */
    Task<void> Send(const Pointer<ogm::Object>& data = {}, int status = 200);

    /** \brief Send a reply to the peer that has issued the request
     *
     *  Same a other Send(), only with move semantics
     *
     * \param data payload to be transmitted
     * \param status
     * \return a task waiting for the transmission to complete
     * \uptrace{SWS_REST_01859}
     */
    Task<void> Send(Pointer<ogm::Object>&& data, int status);

    /** \brief Send a reply with binary data to the peer that has issued the request.
     *
     * \param data payload to be transmitted
     * \param header header to be transmitted
     * \return a task waiting for the transmission to complete
     */
    Task<void> Send(const StringView& data, ReplyHeader& header);

    /** \brief Issues a redirect command to the connected client
     *
     * Must not be called after Send().
     *
     * \param uri location to redirect to
     */
    Task<void> Redirect(const Uri& uri);

    /**
     * \brief Set the pointer to the corrospending  Poco::Net::HTTPServerResponse
     * \param poco_response
     */
    void SetPocoResponse(Poco::Net::HTTPServerResponse* poco_response);

    /**
     * \brief Helper function to asynchronously send a reply
     * \param data_string
     * \param status
     */
    void SendTask(String data_string, int status);

    /**
     * \brief Helpfer function to asynchronously redirect a request
     * \param uri
     */
    void RedirectTask(String uri);

    /**
     * \brief Get boolean member variable which determines if the server application already has send the reply
     * \return The boolean member variable already_send_
     */
    bool GetAlreadySend();

private:
    /**
     * \brief Pointer the the associated poco response object
     */
    Poco::Net::HTTPServerResponse* poco_response_;

    /**
     * \brief Boolean to mark if send has already been called, so the server will not send a reply if the application
     * has
     * already send it
     */
    bool already_send_;

    /**
     * \brief logging context instance
     */
    ara::log::Logger& log_{
        ara::log::CreateLogger("HSRI", "Logger for Http Server Reply Interface REST", ara::log::LogLevel::kVerbose)};
};

/**********************************************************************************************************************
 *  WebSocketRequestHandler
 *********************************************************************************************************************/

/**
 * TODO
 */
class WebSocketRequestHandler : public Poco::Net::HTTPRequestHandler
{
public:
    /**
     * TODO
     * @param request
     * @param response
     */
    void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);

private:
    /**
     * \brief logging context instance
     */
    ara::log::Logger& log_{
        ara::log::CreateLogger("WSRH", "Logger for Web Socket Request Handler REST", ara::log::LogLevel::kVerbose)};
};

/**********************************************************************************************************************
 *  HttpServerRequestHandler
 *********************************************************************************************************************/

/**
 * Executes the handleRequest Method imidiatly to handle a http server request
 */
class HttpServerRequestHandler : public Poco::Net::HTTPRequestHandler
{
public:
    /**
     * \brief Default Constructor
     */
    HttpServerRequestHandler() = default;

    /**
     * Constructor
     * @param hnd Handler function given by the application
     */
    explicit HttpServerRequestHandler(Function<RequestHandlerType> hnd);

    /**
     * \brief Performs the complete handling of the HTTP request connection. As soon as the handleRequest() method
     * returns, the request handler object is destroyed. A new HTTPRequestHandler object will be created for each new
     * HTTP
     * request that is received by the HTTPServer.
     * \param request represents a server-side HTTP request
     * \param response represents a server-side HTTP response
     */
    void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);

    /**
     * \brief Determines the corresponding RequestMethod from a given string
     * \param request_method_string The request method as a string
     * \return A RequestMethod object
     */
    RequestMethod DetermineRequestMethod(String request_method_string);

    /**
     * \brief Creates the apd::rest::ServerRequest and apd::rest:ServerReply objects and fills the ServerRequest with
     * content from the Poco::Net::HTTPServerRequest. The ServerReply object will be filled from an application.
     *
     * \param request The Poco::Net::HTTPServerRequest to get content from for the apd::rest::ServerRequest
     * \param response
     */
    void CreateAraRestReqRep(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);

    /**
     * \brief Pointer to the corrospending apd::rest::HttpServerReply
     */
    std::shared_ptr<ServerReply> rest_http_server_reply_;

    /**
     * \brief Pointer to the corrospending apd::rest::HttpServerRequest
     */
    std::shared_ptr<ServerRequest> rest_http_server_request_;

    /**
     * \brief Pointer to the corresponding HTTPServerReply Object
     */
    Pointer<HttpServerReply> http_server_reply_;

    /**
     * Handler function given by the application
     */
    Function<RequestHandlerType> hnd_;

    /**
     * Stores the request body as a string
     */
    String request_body_;

private:
    /**
     * \brief logging context instance
     */
    ara::log::Logger& log_{
        ara::log::CreateLogger("HSRL", "Logger for Http Server Request REST", ara::log::LogLevel::kVerbose)};
};

/**********************************************************************************************************************
 *  HttpServerRequestHandlerFactory
 *********************************************************************************************************************/

/**
 * \brief Creates new HttpServerRequestHandler to handle new HTTP requests
 */
class HttpServerRequestHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory
{
public:
    /**
     * \brief  Creates the HttpServerRequestHandlerFactory and saves given HttpServer Pointer
     * \param http_server
     */
    explicit HttpServerRequestHandlerFactory(HttpServer* http_server);

    /**
     * Constructor
     * @param hnd Handler function given by the application
     */
    explicit HttpServerRequestHandlerFactory(Function<RequestHandlerType> hnd);

    /**
     * \brief  Creates a new request handler for the given HTTP request. The method should inspect the given
     * HTTPServerRequest object (e.g., method and URI) and create an appropriate HTTPRequestHandler object to handle the
     * request.
     * \param request represents a server-side HTTP request
     * \return Pointer to an request handler
     */
    virtual Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest& request);

    /**
     * Handler function given by the application
     */
    Function<RequestHandlerType> hnd_;
};

/**********************************************************************************************************************
 *  HttpServer
 *********************************************************************************************************************/

/**
 * \brief Implements the HTTP Server as proposed by the http server impl interface
 */
class HttpServer : public ServerInterface
{
public:
    /**
     * Deleted default constructor
     */
    HttpServer() = delete;

    /**
     * \brief Constructor
     * \param binding Server binding with configuration informations
     * \param hnd Custom handler function to handle a request
     * \param alloc
     */
    HttpServer(config::ServerBinding binding,
        Function<RequestHandlerType> hnd,
        Allocator* alloc = GetDefaultAllocator());
    /**
     * \brief Destructor
     */
    ~HttpServer() = default;

    /**
     * \brief Start the HttpServer with respect to given policy
     * \param policy Determines wheter to start  a server in a separate execution context or in the execution context of
     * the endpoint owner
     * \return Returns a task
     */
    Task<void> Start(StartupPolicy policy = StartupPolicy::kDetached);

    /**
     * \brief Stop the HttpServer with respect to given policy
     * \param policy Determines whether to stop gracefully or forced
     * \return Returns a Task containing the ServerStatus response of HttpServer::StopServer()
     */
    Task<void> Stop(ShutdownPolicy policy = ShutdownPolicy::kGraceful);

    /**
     * TODO
     * @param shnd
     * @param sshnd
     */
    void ObserveSubscriptions(const Function<SubscriptionHandlerType>& shnd,
        const Function<SubscriptionStateHandlerType>& sshnd);

    /** \brief Obtain server status
     * \return a reference to the server Status
     */
    std::error_code GetError() const noexcept;

    /** \brief Observe status changes
     *
     *  \param hnd user-defined handler function to to called on status changes
     */
    void ObserveError(const Function<void(std::error_code)>& hnd);

    /**
     * \brief Holds the custom request handler function given in the Constructor
     */
    Function<RequestHandlerType> hnd_;

private:
    /**
     * \brief Instance of an Poco Http Server
     */
    Pointer<Poco::Net::HTTPServer> poco_http_server_;

    /**
     * \brief Mutex for the condition variable
     */
    std::mutex m_;

    /**
     * \brief A conidition variable to notify about Stop beeing called
     */
    std::condition_variable cv_;

    /**
     * \brief Boolean to determine if Stop was called
     */
    bool stop_called_;

    /**
     * \brief logging context instance
     */
    ara::log::Logger& log_{ara::log::CreateLogger("HSLR", "Logger for Http Server REST", ara::log::LogLevel::kVerbose)};
};

}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_HTTPSERVER_H_
