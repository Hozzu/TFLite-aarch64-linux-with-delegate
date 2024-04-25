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

/// @file Find Process API provides the functionality to identify a process for a given pid.

#ifndef ARA_EXEC_INTERNAL_FIND_PROCESS_H_
#define ARA_EXEC_INTERNAL_FIND_PROCESS_H_

#include <sys/types.h>
#include <unistd.h>
#include "ara/log/logger.h"
#include "ara/core/optional.h"
#include "ara/core/future.h"
#include "ara/exec/process_specifier.h"
#include "ara/exec/find_process_error_domain.h"

namespace ara
{
namespace exec
{

/// @brief Result class containing the result of a FindProcess call.
struct FindProcessResult
{
    ara::exec::ProcessSpecifier process;  ///< ProcessSpecifier of the found process
    bool isPlatformApplication;  ///< True, if application is a platform application
};

/// @brief Returns the result to identify a given pid.
/// @param pid pid of the process to be identified
/// @param log pointer to log if desired. The log pointer must be valid for the duration of the call.
///            If no logging is desired a nullptr may be passed.
/// @return If the execution is successful and the process can be identified the
///         returned optional contains a value with the requested information.
///         If the execution is successful and the process cannot be identified
///         nullopt is returned. Otherwise (in case of error) the result
///         contains an appropriate error code (FindProcessErrc).
///
ara::core::Future<ara::core::Optional<FindProcessResult> > FindProcess(pid_t pid, ara::log::Logger* const log);

}  // namespace exec
}  // namespace ara

#endif  // ARA_EXEC_INTERNAL_FIND_PROCESS_H_
