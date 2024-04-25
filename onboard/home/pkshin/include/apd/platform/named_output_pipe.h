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

#ifndef APD_PLATFORM_NAMED_OUTPUT_PIPE_H_
#define APD_PLATFORM_NAMED_OUTPUT_PIPE_H_

#include <string>
#include "named_pipe.h"
#include "errno_exception.h"

namespace apd
{
namespace platform
{

/**
 * \brief Refinement of NamedPipe to perform write operations on a named pipe.
 */
class NamedOutputPipe : public NamedPipe
{
public:
    explicit NamedOutputPipe(const std::string& pathname)
        : NamedPipe(pathname, WRITE)
    { }
    NamedOutputPipe(NamedOutputPipe&& other)
        : NamedPipe(std::move(other))
    { }
    virtual ~NamedOutputPipe()
    { }

public:
    template <typename SourceType>
    void write(const SourceType& data);
};

template <>
void NamedOutputPipe::write<std::string>(const std::string& data);

template <typename SourceType>
void NamedOutputPipe::write(const SourceType& data)
{
    ssize_t bytes_written(::write(pipe_, &data, sizeof(SourceType)));
    if (-1 == bytes_written) {
        throw exception::ErrnoException(errno);
    }
}

} /* namespace platform */
} /* namespace apd */

#endif /* APD_PLATFORM_NAMED_OUTPUT_PIPE_H_ */
