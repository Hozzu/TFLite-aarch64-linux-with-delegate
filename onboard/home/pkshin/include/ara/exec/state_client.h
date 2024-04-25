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

/// @file State Client API provides the functionality for a SM to report EM to change FG's states.
#ifndef ARA_EXEC_STATE_CLIENT_H_
#define ARA_EXEC_STATE_CLIENT_H_

#include "ara/exec/execution_error_event.h"
#include "ara/exec/function_group.h"
#include "ara/exec/function_group_state.h"
#include "ara/core/result.h"
#include "ara/core/future.h"
#include "ara/core/string.h"
#include "ara/core/string_view.h"

#include <functional>

namespace ara
{
namespace exec
{

///
/// @brief Class implements State Client.
///
/// Class representing connection to Execution Management that is used
/// to request Function Group state transitions (or other operations).
///
/// @note StateClient opens communication channel to Execution Management (e.g. POSIX FIFO). Each
///       Process that intends to perform state management, shall create an instance of this class and it
///       shall have rights to use it.
///
/// @uptrace{SWS_EM_02275, f454aabf8aee55a6b07e122d5c61d3a4ddcccf28}
///
class StateClient final
{
public:
    ///
    /// @brief Constructor that creates State Client instance.
    ///
    /// Registers given callback which is called in case a Function Group changes its state unexpectedly to an Undefined
    /// Function Group State.
    ///
    /// @param undefinedStateCallback - callback to be invoked by StateClient library if a FunctionGroup changes its
    /// state unexpectedly to an Undefined Function Group State, i.e. without previous request by SetState(). The
    /// affected FunctionGroup and ExecutionError is provided as an argument to the callback in form of
    /// ExecutionErrorEvent.
    ///
    /// @uptrace{SWS_EM_02276, 15f1ce310f92373447c7efdc93b0beacc5453483}
    ///
    explicit StateClient(std::function<void(const ExecutionErrorEvent&)> undefinedStateCallback) noexcept;

    ///
    /// @brief Destructor of the State Client instance.
    ///
    /// @uptrace{SWS_EM_02277, 9c5af11b0e4f196765bb512a548e9f09c6998af8}
    ///
    ~StateClient() noexcept;

    StateClient(const StateClient&) = delete;
    StateClient(StateClient&&) = delete;
    StateClient& operator=(const StateClient&) = delete;
    StateClient& operator=(StateClient&&) = delete;

    ///
    /// @brief Request state transition for a single Function Group.
    ///
    /// This method will request Execution Management to perform state transition and return
    /// immediately. Returned ara::core::Future can be used to determine result of requested
    /// transition.
    ///
    /// @param state - representing meta-model definition of a state inside a specific
    ///                Ref{Function Group}. Execution Management will perform state transition
    ///                from the current state to the state identified by this parameter.
    ///
    /// @returns void if requested transition is successful, otherwise it returns ExecErrorDomain error.
    /// @retval ExecErrc::kCancelled - if transition to the requested Function Group state was cancelled
    ///                                by a newer request.
    /// @retval ExecErrc::kFailed - if transition to the requested Function Group state failed.
    /// @retval ExecErrc::kFailedUnexpectedTerminationOnEnter - if Unexpected Termination in Process of target Function
    /// Group State happened.
    /// @retval ExecErrc::kCommunicationError - if StateClient can't communicate with
    ///                                         Execution Management (e.g. IPC link is down).
    /// @retval ExecErrc::kInvalidTransition - if transition to the requested state is prohibited (e.g. Off state for
    /// MachineFG) or the requested Function Group State is invalid (e.g. does not exist anymore after a software
    /// update).
    /// @retval ExecErrc::kGeneralError - if any other error occurs.
    ///
    /// @uptrace{SWS_EM_02278}
    ///
    ara::core::Future<void> SetState(const FunctionGroupState& state) const noexcept;

    ///
    /// @brief Method to retrieve result of Machine State initial transition to Startup state.
    ///
    /// @returns void if requested transition is successful, otherwise it returns ExecErrorDomain error.
    /// @retval ExecErrc::kCancelled - if transition to the requested Function Group state was cancelled
    ///                                by a newer request.
    /// @retval ExecErrc::kFailed - if transition to the requested Function Group state failed.
    /// @retval ExecErrc::kCommunicationError - if StateClient can't communicate with
    ///                                         Execution Management (e.g. IPC link is down).
    /// @retval ExecErrc::kGeneralError - if any other error occurs.
    ///
    /// @uptrace{SWS_EM_02279}
    ///
    ara::core::Future<void> GetInitialMachineStateTransitionResult() const noexcept;

    ///
    /// @brief Returns the execution error which changed the given Function Group to an Undefined FunctionGroup
    /// State.This function will return with error and will not return an ExecutionErrorEvent object, if the
    /// given Function Group is in a defined Function Group state again.
    ///
    /// @param[in] functionGroup - Function Group of interest.
    /// @returns The execution error which changed the givenFunction Group to an Undefined Function GroupState.
    /// @retval ExecErrc::kFailed - if given Function Group is not in an UndefinedFunction Group State.
    /// @retval ExecErrc::kCommunicationError - if StateClient can't communicate with Execution Management (e.g. IPC
    /// link is down)
    ///
    /// @uptrace{SWS_EM_02542, f870388b6504542b0a550e3fb5d009ac94e3d53b}
    ///
    ara::core::Result<ExecutionErrorEvent> GetExecutionError(const FunctionGroup& functionGroup) noexcept;
};

}  // namespace exec
}  // namespace ara

#endif  // ARA_EXEC_STATE_CLIENT_H_
