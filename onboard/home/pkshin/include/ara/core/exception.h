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

#ifndef APD_ARA_CORE_EXCEPTIONS_H
#define APD_ARA_CORE_EXCEPTIONS_H

#include "ara/core/error_code.h"

#include <exception>
#include <system_error>
#include <utility>
#include <ostream>

namespace ara
{
namespace core
{

/// @uptrace{SWS_CORE_00601, 64be84472d4bdfd9a012e47fdef2cb6699c4aabe}
class Exception : public std::exception
{
    ErrorCode const mErrorCode;

public:
    /// @uptrace{SWS_CORE_00611, 53d0a953918fae1b9b476425081b8e4e599851db}
    explicit Exception(ErrorCode err) noexcept
        : mErrorCode(std::move(err))
    { }

    /// @uptrace{SWS_CORE_00613, f6770a2cb5c8fd164078ef41a778b7e6bfac3b81}
    ErrorCode const& Error() const noexcept
    {
        return mErrorCode;
    }

    /// @uptrace{SWS_CORE_00612, 4100797be96e718be1cfc1051c85f56200b7cd35}
    char const* what() const noexcept override
    {
        return std::exception::what();
    }

protected:
    /// @uptrace{SWS_CORE_00614, c18c5ecbe110678475fb82034c3064cb93700488}
    Exception& operator=(Exception const& other) = default;
};

}  // namespace core
}  // namespace ara

#endif  // APD_ARA_CORE_EXCEPTIONS_H
