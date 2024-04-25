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

#ifndef SRC_ARA_PHM_NAMED_PIPE_HPP_
#define SRC_ARA_PHM_NAMED_PIPE_HPP_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
#include <cstring>
#include <unistd.h>

static constexpr char serverFIFO[] = "/usr/run/ara-phm/phm-server-fifo";
static constexpr char clientFIFO[] = "/usr/run/ara-phm/phm-client-fifo";
static constexpr char safetyFIFO[] = "/usr/run/ara-phm/safety_fifo";

namespace ara
{
namespace phm
{
namespace internal
{

/**
 * \brief Class to abstract operations on a named pipe.
 */
class NamedPipe
{
public:
    /**
     * \brief An ENUM stating the direction (read/write) for the named pipe.
     */
    enum Direction
    {
        READ,
        WRITE
    };

    /**
     * \brief Constructor that opens the given named pipe.
     *
     * Note that this constructor does not verify whether the file exists or whether it is in fact a named pipe.
     */
    NamedPipe(const std::string& pathname);

    ssize_t bytesRead;
    ssize_t bytesWritten;
    std::size_t NamedPipeWrite(const void* buff, std::size_t buffSize);
    std::size_t NamedPipeRead(void* buff, std::size_t buffSize);
    void NamedPipeOpen(const std::string& pathname, Direction direction);

    ~NamedPipe();

    static constexpr int kInvalidFD{-1};
    const std::string pathname_;

    int pipe_;
    /**
     * \brief Constructor that opens the given named pipe.
     *
     * Note that this constructor does not verify whether the file exists or whether it is in fact a named pipe.
     * The file will be opened in blocking mode.
     *
     * Note that when opening a named pipe for writing, this call will block until the named pipe is also opened for
     * reading.
     *
     * \param pathname The path to the file to be opened.
     * \param direction Whether to open the file for reading or writing.
     */
    NamedPipe(NamedPipe&& other);

    /**
     * \brief Getter for the raw filedescriptor
     */
    int getFd() const
    {
        return pipe_;
    }

    /**
     * \brief Getter for the path to the named pipe.
     */
    const std::string& getPathname() const
    {
        return pathname_;
    }
};

} /* namespace internal */
} /* namespace phm */
} /* namespace ara */

#endif /* SRC_ARA_PHM_NAMED_PIPE_HPP_ */
