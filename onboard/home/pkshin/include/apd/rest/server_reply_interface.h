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

#ifndef LIB_APDREST_INCLUDE_APD_REST_SERVER_REPLY_INTERFACE_H_
#define LIB_APDREST_INCLUDE_APD_REST_SERVER_REPLY_INTERFACE_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "apd/rest/server.h"
#include "apd/rest/task.h"

namespace apd
{
namespace rest
{

class ServerRequest;  //< fwd

/**
 * Interface for generic ServerReply implementations
 */
class ServerReplyInterface
{
public:
    /**
     * Default CTOR
     */
    ServerReplyInterface() = default;

    ServerReplyInterface(const ServerReplyInterface&) = delete;  ///< Non-copyable
    ServerReplyInterface& operator=(const ServerReplyInterface&) = delete;  ///< Non-copy-assignable

    /**
     * Virtual Destructor
     */
    virtual ~ServerReplyInterface() = default;

    /**
     * \brief Send a reply to the peer that has issued the request
     *
     *  If this function is not invoked explicitly, the endpoint will transmit a default reply.
     *  If Redirect() has been before called, these functions must be used.
     *
     * \param data payload to be transmitted
     * \param status
     * \return a task waiting for the transmission to complete
     */
    virtual Task<void> Send(const Pointer<ogm::Object>& data = {}, int status = 200) = 0;

    /**
     *  \brief Send a reply to the peer that has issued the request
     *
     *  Same a other Send(), only with move semantics
     *
     * \param data payload to be transmitted
     * \param status
     * \return a task waiting for the transmission to complete
     */
    virtual Task<void> Send(Pointer<ogm::Object>&& data, int status) = 0;

    /**
     *  \brief Send a reply to the peer that has issued the request
     *
     *
     * \param data payload to be transmitted
     * \param header custom header to be used
     * \return a task waiting for the transmission to complete
     */
    virtual Task<void> Send(const StringView& data, ReplyHeader& header) = 0;

    /**
     * \brief Issues a redirect command to the connected client
     *
     * Must not be called after Send().
     *
     * \param uri location to redirect to
     */
    virtual Task<void> Redirect(const Uri& uri) = 0;
};

}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_SERVER_REPLY_INTERFACE_H_
