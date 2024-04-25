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

/// @file Execution Client API provides the functionality for a Process to report its state to the Execution Management.
#ifndef ARA_EXEC_EXECUTION_CLIENT_H_
#define ARA_EXEC_EXECUTION_CLIENT_H_

#include "ara/core/result.h"

#include <cstdint>

namespace ara
{
namespace exec
{

///
/// @brief Defines the internal states of a Process
///
/// @uptrace{SWS_EM_02000, 284890d6534cc0ae716282fe8fc21536413aa332}
///
enum class ExecutionState : uint8_t
{
    ///
    /// @brief After a Process has been started by Execution Management, it reports ExecutionState kRunning
    ///
    kRunning = 0,
};

///
/// @brief Defines the status of EM's response to the ExecutionClient
///        after a ReportExecutionState call has been processed by EM
///
/// @note Implementation detail
///
enum class ExecutionStateResponseStatus : std::uint8_t
{
    kSuccess = 0,
    kInvalidTransition = 1,
    kInvalidReport = 2,
    kReportNotAllowed = 3
};

///
/// @brief Class to implement operations on Execution Client.
///
/// @uptrace{SWS_EM_02001, 18d8506e9e934dcd7a9962dcb777692c3225c5cc}
///
class ExecutionClient final
{

public:
    ///
    /// @brief Constructor that creates the Execution Client.
    ///
    /// @uptrace{SWS_EM_02030, a21838143955eacae1b01904700e6e5f2eff526c}
    ///
    ExecutionClient() noexcept;

    ///
    /// @brief Destructor of the Execution Client instance.
    ///
    /// @uptrace{SWS_EM_02002, c77fe53fb3b3b982984f95c86dc596985f6fc259}
    ///
    ~ExecutionClient() noexcept;

    ///
    /// @brief Interface for a Process to report its internal state to Execution Management.
    ///
    /// @param state Value of the Execution State
    /// @returns An instance of ara::core::Result. The instance holds an ErrorCode containing either one of the
    ///          specified errors or a void-value.
    ///
    /// @error ara::exec::ExecErrc::kGeneralError if some unspecified error occurred
    /// @error ara::exec::ExecErrc::kCommunicationError Communication error between Application and Execution
    ///        Management, e.g. unable to report state for Non-reporting Process.
    /// @error ara::exec::ExecErrc::kInvalidTransition Invalid transition request (e.g. to Running when already in
    /// Running state)
    ///
    /// @uptrace{SWS_EM_02003, e75ba5eac2161b1aed0ead0eedacc7401fee4f6f}
    ///
    ara::core::Result<void> ReportExecutionState(ExecutionState state) const noexcept;
};

}  // namespace exec
}  // namespace ara

#endif  // ARA_EXEC_EXECUTION_CLIENT_H_
