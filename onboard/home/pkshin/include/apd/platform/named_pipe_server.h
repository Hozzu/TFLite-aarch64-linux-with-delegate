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

#ifndef APD_PLATFORM_NAMED_PIPE_SERVER_H_
#define APD_PLATFORM_NAMED_PIPE_SERVER_H_

#include <unistd.h>
#include <memory>
#include <string>
#include "named_input_pipe.h"
#include "named_output_pipe.h"

namespace apd
{
namespace platform
{

/**
 * \brief Struct to abstract the message internal format for client server communication.
 */
template <typename MessageType>
struct ServerRequest
{
    pid_t pid;
    MessageType message;
};

/**
 * \brief Class to abstract operations on a named pipe server.
 */
class NamedPipeServer
{
protected:
    /**
     * \brief Client's pipe suffix
     *
     */
    const std::string pipename_suffix_;

    /**
     * \brief Server's input pipe where all messages are received.
     */
    NamedInputPipe pipe_;

    /**
     * \brief Pointer to the connected client pipe object.
     */
    std::unique_ptr<NamedOutputPipe> client_pipe_;

public:
    /**
     * \brief Constructor that creates the given named pipe server.
     *
     * \param pathname The path to the servers's pipe.
     * \param message_size Size of the message.
     * \param message_count Number of messages in buffer
     * \param client_pathname_template Client's pipe name suffix
     */
    NamedPipeServer(const std::string& pathname,
        size_t message_size,
        size_t message_count,
        const std::string& client_pathname_template)
        : pipename_suffix_(client_pathname_template)
        , pipe_((pathname), message_size * message_count, false)
    { }

    ~NamedPipeServer();

    /**
     * \brief Method to get data received to the server's pipe.
     *
     *
     * \param pid Reference to the client process pid
     * \param message Message received by server
     *
     * \return true - is received successfully
     *         false - otherwise
     */
    template <typename SourceType>
    bool receive(pid_t& pid, SourceType& message)
    {
        ServerRequest<SourceType> newMess;

        if (pipe_.read(newMess) == false)
            return false;

        message = newMess.message;
        pid = newMess.pid;

        return true;
    }

    /**
     * \brief Method to send data back to the connected client.
     *
     *
     * \param pathname Pathname of the client
     * \param message Data to be sent to the client
     *
     */
    template <typename SourceType>
    void send(const std::string& pathname, SourceType& message)
    {
        if (!client_pipe_) {
            client_pipe_ = std::unique_ptr<NamedOutputPipe>(new NamedOutputPipe(pathname + pipename_suffix_));
        }
        client_pipe_->write(message);
    }

    /**
     * \brief Closes connection with the currently connected client.
     *
     */
    void close_connection();
};

} /* namespace platform */
} /* namespace apd */

#endif /* APD_PLATFORM_NAMED_PIPE_SERVER_H_*/
