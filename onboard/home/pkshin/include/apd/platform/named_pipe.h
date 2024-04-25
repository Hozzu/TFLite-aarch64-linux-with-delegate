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

#ifndef APD_PLATFORM_NAMED_PIPE_H_
#define APD_PLATFORM_NAMED_PIPE_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <string>
#include <cstring>
#include <unistd.h>
#include <vector>

namespace apd
{
namespace platform
{

/**
 * \brief Class to abstract operations on a named pipe.
 */
class NamedPipe
{
protected:
    static const int INVALID_FD{-1};
    /**
     * \brief The path to the named pipe
     */
    const std::string pathname_;

    /**
     * \brief The Filedescriptor where the named pipe is opened.
     */
    int pipe_;

    /**
     * \brief An ENUM stating the direction (read/write) for the named pipe.
     */
    enum Direction
    {
        READ,
        WRITE
    };

protected:
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
    NamedPipe(const std::string& pathname, Direction direction, bool blocking = true);
    NamedPipe(NamedPipe&& other);

public:
    NamedPipe() = delete;
    NamedPipe(const NamedPipe&) = delete;
    NamedPipe& operator=(NamedPipe&&) = delete;
    NamedPipe& operator=(const NamedPipe&) = delete;
    /**
     * \brief Destructor that also closes the named pipe.
     */
    virtual ~NamedPipe();

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

} /* namespace platform */
} /* namespace apd */

#endif /* APD_PLATFORM_NAMED_PIPE_H_ */
