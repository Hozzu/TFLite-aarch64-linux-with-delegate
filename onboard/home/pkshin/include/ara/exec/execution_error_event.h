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

/// @file Defines structure(s) for an execution error event in a Function Group

#ifndef ARA_EXEC_EXECUTION_ERROR_EVENT_H_
#define ARA_EXEC_EXECUTION_ERROR_EVENT_H_

#include "ara/exec/function_group.h"

#include <cstdint>

namespace ara
{
namespace exec
{
///
/// @brief Represents the execution error.
///
/// @uptrace{SWS_EM_02541, 04986075f2fb680902dfab1fc09044f86a2a9ec1}
///
using ExecutionError = std::uint32_t;

///
/// @brief Represents an execution error event which happens in a Function Group
///
/// @uptrace{SWS_EM_02544, 2c1be3f9eb5193bebaccfa469a9935b0e06e508e}
///
struct ExecutionErrorEvent final
{
    ///
    /// @brief The execution error of the Process which unexpectedly terminated.
    ///
    /// @uptrace{SWS_EM_02545, 8fd70a675293f19cdf20e88bf64dc21aa573525a}
    ///
    ExecutionError executionError;

    ///
    /// @brief The function group in which the error occurred.
    ///
    /// @uptrace{SWS_EM_02546, 077b3feab820e59ef577d66165a5c7b19b8be95c}
    ///
    FunctionGroup functionGroup;
};

}  // namespace exec
}  // namespace ara

#endif  // ARA_EXEC_EXECUTION_ERROR_EVENT_H_
