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

/// @file Wrapper class to identify a process

#ifndef ARA_EXEC_INTERNAL_PROCESS_SPECIFIER_H_
#define ARA_EXEC_INTERNAL_PROCESS_SPECIFIER_H_

#include "ara/core/optional.h"
#include "ara/core/result.h"
#include "ara/core/string.h"
#include "ara/exec/find_process_error_domain.h"

namespace ara
{
namespace exec
{

/// @brief Wrapper class to identify a process
///
/// The class ProcessSpecifier is used to identify a process and has
/// similar interface like the InstanceSpecifier class.
/// Processes are identified by a string value.
/// An empty string value is not allowed.
class ProcessSpecifier
{
public:
    /// @brief Construct a new Process Specifier object
    ///
    ProcessSpecifier() = default;

    /// @brief Validates a name
    ///
    /// @param name Name of the process
    /// @return ara::core::Result<void> An error is returned if the name is empty
    static ara::core::Result<void> Validate(ara::core::StringView name) noexcept
    {
        if (0 < name.length()) {
            return ara::core::Result<void>();
        }
        return ara::core::Result<void>::FromError(ara::exec::FindProcessErrc::kInvalidArgument);
    }

    /// @brief Creates and validates a ProcessSpecifier instance
    ///
    /// @param name Name of the process
    /// @return ara::core::Result<ProcessSpecifier> An error is returned if the name is not valid
    static ara::core::Result<ProcessSpecifier> Create(ara::core::StringView name)
    {
        ara::core::Result<void> ret = Validate(name);
        if (!ret) {
            return ara::core::Result<ProcessSpecifier>::FromError(ret.Error());
        }

        ProcessSpecifier result;
        result.name_ = name;
        return result;
    }

    /// @brief Construct a new Process Specifier object
    ///
    /// @param name Name of the process
    /// @throw FindProcessException if the name is not valid
    explicit ProcessSpecifier(ara::core::StringView name)
        : ProcessSpecifier(Create(name).ValueOrThrow())
    { }

    /// @brief Destroy the Process Specifier object
    ///
    ~ProcessSpecifier() = default;

    /// @brief Returns the name
    ///
    /// @return ara::core::StringView name
    ara::core::StringView ToString() const noexcept
    {
        return name_;
    }

    /// @brief Comparison to other ProcessSpecifier
    ///
    /// @param other ProcessSpecifier
    /// @return bool true, if identical
    bool operator==(ProcessSpecifier const& other) const noexcept
    {
        return (name_ == other.ToString());
    }

    /// @brief Comparison to other ProcessSpecifier
    ///
    /// @param other ProcessSpecifier
    /// @return bool true, if not identical
    bool operator!=(ProcessSpecifier const& other) const noexcept
    {
        return (name_ != other.ToString());
    }

    /// @brief Comparison
    ///
    /// @param other ProcessSpecifier
    /// @return bool true, if less
    bool operator<(ProcessSpecifier const& other) const noexcept
    {
        return (name_ < other.ToString());
    }

private:
    ara::core::String name_;  ///< Name of the process
};

}  // namespace exec
}  // namespace ara

#endif  // ARA_EXEC_INTERNAL_FIND_PROCESS_H_
