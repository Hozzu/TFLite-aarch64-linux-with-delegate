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

#ifndef APD_PLATFORM_NAMED_INPUT_PIPE_H_
#define APD_PLATFORM_NAMED_INPUT_PIPE_H_

#include "named_pipe.h"

#include <sys/types.h>
#include <linux/limits.h>
#include <vector>
#include <string>
#include <apd/platform/errno_exception.h>

namespace apd
{
namespace platform
{

/**
 * \brief Constant for the size of NamedInputPipe::buffer_.
 */
static const size_t INPUT_BUFFER_LENGTH(PATH_MAX);

/**
 * \brief Refinement of NamedPipe to perform read operations on a named pipe.
 */
class NamedInputPipe : public NamedPipe
{
    friend class NamedInputPipeTest;

private:
    /**
     * \brief Intermediate buffer to read larger data structures (e.g., strings)
     *
     * TODO: Replace the buffer with a ring buffer for better efficiency
     */
    std::vector<char> buffer_;

    /**
     * \brief Indicate how many bytes from the start of buffer_ currently contain valid data.
     */
    size_t bytes_in_buffer_;

    /**
     * \brief Indicate whether this is a blocking pipe.
     */
    bool blocking_;

    /**
     * \brief Removes num_bytes bytes from the beginning of buffer_.
     *
     * The remaining valid content of buffer_ is copied to the beginning of buffer_.
     * If num_bytes >= bytes_in_buffer_, the buffer is emptied.
     *
     * \param num_bytes The number of bytes to pop.
     */
    void pop_bytes(size_t num_bytes);

    /**
     * \brief Read max_bytes from the pipe into the buffer.
     *
     * This repeatedly calls ::read() on the pipe, i.e., this method will block until max_bytes have arrived.
     * If there are less than max_bytes bytes free in the buffer, this call will only read from the pipe until the
     * buffer is full.
     *
     * \param max_bytes The number of bytes to be read from the pipe.
     *
     */
    void read_bytes(size_t max_bytes);

public:
    /**
     * \brief Open the given named pipe for reading.
     */
    NamedInputPipe(const std::string& pathname, bool blocking = true)
        : NamedPipe(pathname, READ)
        , buffer_(INPUT_BUFFER_LENGTH)
        , bytes_in_buffer_(0)
        , blocking_(blocking)
    { }

    /**
     * \brief Open the given named pipe for reading.
     */
    NamedInputPipe(const std::string& pathname, size_t bufferSize, bool blocking = true)
        : NamedPipe(pathname, READ, blocking)
        , buffer_(bufferSize)
        , bytes_in_buffer_(0)
        , blocking_(blocking)
    { }

    NamedInputPipe(NamedInputPipe&& other);
    virtual ~NamedInputPipe()
    { }

    /**
     * \brief Read a value of type DestinationType from the pipe.
     *
     * This method will block until enough data for the given data type has been read. No conversions are performed on
     * the received data.
     *
     * \param buffer A reference to an instance of DestinationType where the received data will be stored.
     */
    template <typename DestinationType>
    bool read(DestinationType& buffer);
};

template <>
bool NamedInputPipe::read<std::string>(std::string& buffer);

template <typename DestinationType>
bool NamedInputPipe::read(DestinationType& buffer)
{
    // See if there is enough data in the buffer
    if (bytes_in_buffer_ < sizeof(DestinationType)) {
        // Try to read as many bytes as are missing from socket
        read_bytes(sizeof(DestinationType) - bytes_in_buffer_);
    }

    if (bytes_in_buffer_ >= sizeof(DestinationType)) {
        // Copy received object to destination buffer
        std::memcpy(&buffer, &buffer_[0], sizeof(DestinationType));
        pop_bytes(sizeof(DestinationType));
        return true;
    } else {
        return false;
    }
}

} /* namespace platform */
} /* namespace apd */

#endif /* APD_PLATFORM_NAMED_INPUT_PIPE_H_ */
