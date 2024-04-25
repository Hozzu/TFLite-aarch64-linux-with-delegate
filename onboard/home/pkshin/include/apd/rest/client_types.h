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

#ifndef LIB_APDREST_INCLUDE_APD_REST_CLIENT_TYPES_H_
#define LIB_APDREST_INCLUDE_APD_REST_CLIENT_TYPES_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <utility>

#include "apd/rest/cpp14_backport.h"
#include "apd/rest/endpoint.h"
#include "apd/rest/function.h"
#include "apd/rest/header.h"
#include "apd/rest/ogm/copy.h"
#include "apd/rest/ogm/object.h"
#include "apd/rest/pointer.h"
#include "apd/rest/task.h"
#include "apd/rest/uri.h"
#include "boost/variant.hpp"
namespace apd
{
namespace rest
{
namespace ogm
{

class Object;
}  // namespace ogm

class Reply;  // fwd-decl

/** \brief Represents a client-side request message
 *
 * A request encapsulates all context information related to a client-side request
 * to be transmited to a server. A request is composed of at least a RequestMethod
 * and an Uri. Optionally a request payload in form of an object graph may be provided.
 * \uptrace{SWS_REST_02181}
 */
class Request
{
public:
    Request(const Request&) = delete;  ///< Non-copyable
    Request& operator=(const Request&) = delete;  ///< Non-copy-assignable \uptrace{SWS_REST_02182}

    /** \brief Constructs a Request
     *
     * \param met one of RequestMethod
     * \param uri a Uri
     * \uptrace{SWS_REST_02183}
     */
    Request(RequestMethod met, const Uri& uri);
    /** \brief Constructs a Request
     *
     * \param met one of RequestMethod
     * \param uri a Uri
     * \uptrace{SWS_REST_02184}
     */
    Request(RequestMethod met, Uri&& uri);
    /** \brief Constructs a Request
     *
     * \param met one of RequestMethod
     * \param uri a Uri
     * \param obj data payload of request message
     * \uptrace{SWS_REST_02185}
     */
    Request(RequestMethod met, const Uri& uri, const Pointer<ogm::Object>& obj);
    /** \brief Constructs a Request
     *
     * \param met one of RequestMethod
     * \param uri a Uri
     * \param obj data payload of request message
     * \uptrace{SWS_REST_02186}
     */
    Request(RequestMethod met, const Uri& uri, Pointer<ogm::Object>&& obj);
    /** \brief Constructs a Request
     *
     * \param met one of RequestMethod
     * \param uri a Uri
     * \param obj data payload of request message
     * \uptrace{SWS_REST_02187}
     */
    Request(RequestMethod met, Uri&& uri, const Pointer<ogm::Object>& obj);
    /** \brief Constructs a Request
     *
     * \param met one of RequestMethod
     * \param uri a Uri
     * \param obj data payload of request message
     * \uptrace{SWS_REST_02188}
     */
    Request(RequestMethod met, Uri&& uri, Pointer<ogm::Object>&& obj);

    /** \brief Return RequestMethod
     *
     * \return a RequestMethod
     */
    RequestMethod GetRequestMethod() const
    {
        return header_.GetMethod();
    }

    /** \brief Return Uri
     *
     * \return a Uri
     */
    Uri GetUri() const
    {
        return header_.GetUri();
    }

    /**
     * \brief Get a copy of ogm
     */
    Pointer<ogm::Object> GetObject() const
    {
        return std::move(ogm::Copy(obj_));
    }

    /**
     * \brief Has Object
     */
    bool HasObject() const noexcept
    {
        bool retval{false};
        if (obj_) {
            retval = true;
        }
        return retval;
    }

    /** \brief Obtains the message header
     *
     *  Requests the message header from the endpoint.
     *
     *  \return a reference to a RequestHeader
     */
    RequestHeader& GetHeader();

private:
    /**
     * \brief The RequestHeader
     */
    RequestHeader header_;

    /**
     * \brief The Uri
     */
    Pointer<ogm::Object> obj_;
};

/** \brief Represents a client-side reply message
 *
 * A reply encapsulates all context information related to a client-side reply
 * received from a server. A reply is composed of a message header and a message payload.
 * \uptrace{SWS_REST_02169}
 */
class Reply
{
public:
    Reply()
        : obj_(ogm::Object::Make())
    { }  ///< default
    Reply(const ReplyHeader& header)
        : header_(header)
        , obj_(ogm::Object::Make())
    { }  ///< Constructor \uptrace{SWS_REST_02170}
    Reply(const ReplyHeader& header, Pointer<ogm::Object> obj)
        : header_(header)
        , obj_(std::move(obj))
    { }  ///< Constructor
    Reply(const ReplyHeader& header, Pointer<String> str)
        : header_(header)
        , obj_(std::move(str))
    { }  ///< Constructor
    Reply(const Reply&) = delete;  ///< Non-copyable
    Reply& operator=(const Reply&) = delete;  ///< Non-copy-assignable

    /** \brief Obtains the message header
     *
     *  Requests the message header from the endpoint.
     *  Accessing the message header is always synchronous.
     *
     *  \return a reference to a ReplyHeader
     *  \uptrace{SWS_REST_02172}
     */
    ReplyHeader const& GetHeader() const;
    /** \brief Obtains the reply message payload
     *
     *  Asynchronous request for the message payload. A binding may delay reading and parsing.
     *  of a message payload until explicitly requested.
     *  \return returns a task waiting for the message payload to be received.
     *  \uptrace{SWS_REST_02173}
     */
    Task<ogm::Object const&> GetObject() const;  // deserializes lazily

    /** \brief Obtains the reply message payload
     *
     *  Asynchronous request for the message payload. A binding may delay reading and parsing
     *  of a message payload until explicitly requested.
     *  As opposed to GetObject() this function transfers ownership of the payload to the user.
     *  \return returns a task waiting for the message payload to be received.
     *  \uptrace{SWS_REST_02174}
     */
    Task<Pointer<ogm::Object>> ReleaseObject();  // take ownership

    /** \brief Obtains the reply message payload
     *
     *  Asynchronous request for the message payload. A binding may delay reading and parsing
     *  of a message payload until explicitly requested.
     *  This function transfers ownership of the binary payload to the user.
     *  \return returns a task waiting for the message binary payload to be received.
     *  \uptrace{SWS_REST_02973}
     */
    Task<Pointer<String>> ReleaseBinary();  // take ownership

private:
    /**
     * \brief The ReplyHeader
     */
    ReplyHeader header_;

    /**
     * \brief The payload of the Reply
     */
    boost::variant<Pointer<ogm::Object>, Pointer<std::string>> obj_;
};

/** \brief Represents the client-side of a logical event subscription
 *
 *  An Event represents the client-side of a logical event subscription.
 *  An instance of this object owns all resourced necessary to maintain
 *  a logical notification channel.
 *  An event can only be created by means of Client::Subscribe() and is
 *  permanently bound to a user-defined handler function for notification.
 *
 *  Event is copyable, copy-assignable, movable and move-assignable.
 *  \uptrace{SWS_REST_02017}
 */
class Event
{
public:
    Event(const Event&) = delete;  ///< Non-copyable \uptrace{SWS_REST_02018}
    Event& operator=(const Event&) = delete;  ///< Non-copy-assignable \uptrace{SWS_REST_02019}

    /** \brief Cancels an event subscription by issuing a cancelation request
     *
     * A subscription can also be terminated (but not canceled) by destroying the correspond Event
     * object.
     *
     * \return a task waiting for cancellation which returns true on success.
     * \uptrace{SWS_REST_02020}
     */
    Task<bool> Unsubscribe();

    /** \brief Re-subscribes to an event
     *
     * Resubscription to an already subscribed event is valid but has not user-visible effect.
     *
     * \return a task waiting for re-subscription to be finished which returns true on success
     * \uptrace{SWS_REST_02021}
     */
    Task<bool> Resubscribe();

    /** \brief Returns the event Uri
     *
     *  \return the Uri corresponding to this event subscription
     *  \uptrace{SWS_REST_02022}
     */
    const Uri& GetUri() const noexcept;

    /** \brief Returns the current subscription state
     *
     *  \return the current subscription state as perceived by the client
     *  \uptrace{SWS_REST_02023}
     */
    SubscriptionState GetSubscriptionState() const noexcept;

    /** \brief Tests events for equality
     *  \uptrace{SWS_REST_02024}
     */
    friend bool operator==(const Event&, const Event&) noexcept;
    /** \brief Tests events for inequality
     *  \uptrace{SWS_REST_02025}
     */
    friend bool operator!=(const Event&, const Event&) noexcept;
    /** \brief Tests events for their partial order
     *  Order criterion is implementation-defined.
     *  \uptrace{SWS_REST_02026}
     */
    friend bool operator<(const Event&, const Event&) noexcept;
};

namespace client
{
/// Denotes a callback function for notifications
using NotificationHandlerType = void(const ogm::Object&);
/// Denotes a callback to call if subscription status changes
using SubscriptionStateHandlerType = void(const Event&, SubscriptionState);

}  // namespace client

}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_CLIENT_TYPES_H_
