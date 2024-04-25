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

#ifndef APD_PLATFORM_NAMED_PIPE_CLIENT_H_
#define APD_PLATFORM_NAMED_PIPE_CLIENT_H_

#include <string>
#include <memory>

#include "named_input_pipe.h"
#include "named_output_pipe.h"
#include "named_pipe_server.h"

namespace apd
{
namespace platform
{

/**
 * \brief Class to abstract operations on a named pipe client.
 */
class NamedPipeClient
{
protected:
    /**
     * \brief The client's input NamedPipe.
     */
    std::unique_ptr<NamedInputPipe> client_pipe_;

    /**
     * \brief The client's output NamedPipe. Server output pipe.
     */
    std::unique_ptr<NamedOutputPipe> server_pipe_;

public:
    /**
     * \brief Constructor that opens the given named pipe client.
     *
     * \param pathname The path to the file to be opened.
     * \param message_size Size of the message.
     * \param mesage_count Number of messages in buffer
     */
    NamedPipeClient(const std::string& pathname, size_t message_size, size_t message_count)
        : client_pipe_(new NamedInputPipe(pathname, message_size * message_count))
    { }

    /**
     * \brief Default constructor provided when no input pipe creation required
     *
     */
    NamedPipeClient() = default;

    ~NamedPipeClient();

    /**
     * \brief Method to connect to the server.
     *
     * The method opens for writing the server's pipe
     *
     * \param pathname The path to the server's pipe
     */
    void connect(const std::string& pathname);

    /**
     * \brief Method to send message to the server.
     *
     * \param message Reference to the message to be sent
     */
    template <typename SourceType>
    bool send(SourceType& message)
    {
        if (server_pipe_ == nullptr)
            return false;

        ServerRequest<SourceType> request;
        request.pid = ::getpid();
        request.message = message;

        try {
            server_pipe_->write(request);
        } catch (...) {
            return false;
        }

        return true;
    }

    /**
     * \brief Read the message received to the input pipe.
     *
     * \param message Reference to the message to be received
     *
     * \return true - if success reading the message
     *         false - otherwise
     */
    template <typename DestinationType>
    bool receive(DestinationType& message)
    {
        if (client_pipe_ == nullptr) {
            return false;
        }

        return client_pipe_->read(message);
    }
};

} /* namespace platform */
} /* namespace apd */

#endif /* APD_PLATFORM_NAMED_PIPE_CLIENT_H_ */
