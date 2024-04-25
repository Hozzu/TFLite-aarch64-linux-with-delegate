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

#include <functional>

#include "ara/core/instance_specifier.h"
#include "ara/core/string.h"
#include "ara/core/vector.h"

namespace ara
{
namespace per
{

/// @brief Defines the reported recovery actions.
///
/// @uptrace{SWS_PER_00432, 810c02c1f12b2783f95c5e39318d4aab76b67ed8}
enum class RecoveryReportKind : uint32_t
{
    /// A Key-Value Storage was corrupted, an insufficient number of valid copies existed.
    /// storage contains the short-name path of the Key-Value Storage,
    /// reportedElements is empty,
    /// reportedInstances contains the indices of the affected Key-Value Storage copies.
    kKeyValueStorageRecoveryFailed = 1,
    /// A Key-Value Storage was corrupted, but a sufficient number of valid copies existed.
    /// storage contains the short-name path of the Key-Value Storage,
    /// reportedElements is empty,
    /// reportedInstances contains the indices of the affected Key-Value Storage copies.
    kKeyValueStorageRecovered = 2,
    /// A set of Key-Value Pairs was corrupted, an insufficient number of valid copies existed.
    /// storage contains the short-name path of the Key-Value Storage,
    /// reportedElements contains the list of affected keys,
    /// reportedInstances contains the indices of the affected Key-Value Storage or key copies.
    kKeyRecoveryFailed = 3,
    /// A set of Key-Value Pairs was corrupted, but a sufficient number of valid copies existed.
    /// storage contains the short-name path of the Key-Value Storage,
    /// reportedElements contains the list of affected keys,
    /// reportedInstances contains the indices of the affected Key-Value Storage or key copies.
    kKeyRecovered = 4,
    /// A File Storage was corrupted, an insufficient number of valid copies existed.
    /// storage contains the short-name path of the File Storage,
    /// reportedElements is empty,
    /// reportedInstances contains the indices of the affected File Storage copies.
    kFileStorageRecoveryFailed = 5,
    /// A File Storage was corrupted, but a sufficient number of valid copies existed.
    /// storage contains the short-name path of the File Storage,
    /// reportedElements is empty,
    /// reportedInstances contains the indices of the affected File Storage copies.
    kFileStorageRecovered = 6,
    /// A set of files was corrupted, an insufficient number of valid copies existed.
    /// storage contains the short-name path of the File Storage,
    /// reportedElements contains the list of affected file names,
    /// reportedInstances contains the indices of the affected File Storage or file copies.
    kFileRecoveryFailed = 7,
    /// A set of files was corrupted, but a sufficient number of valid copies existed.
    /// storage contains the short-name path of the File Storage,
    /// reportedElements contains the list of affected file names,
    /// reportedInstances contains the indices of the affected File Storage or file copies.
    kFileRecovered = 8
};

/// @brief Register a recovery reporting callback with persistency.
///
/// This callback can be used in safety-aware applications to detect actions of the Persistency that are related to the
/// correctness of the persisted data and the reliability of the storage.
///
/// @uptrace{SWS_PER_00433, 3f9b80ad880746150ab781bcb23278d3f662abfa}
/// @threadsafety{no}
/// @param recoveryReportCallback The callback function to be called by Persistency to report errors in the stored data
///                               that were corrected using the available redundancy. The function will be called with
///                               the shortName path of the affected Key-Value Storage or File Storage in storage and
///                               information on what has been corrected, placed in the parameters recoveryReportKind,
///                               reportedElements, and reportedInstances.
void RegisterRecoveryReportCallback(std::function<void(const ara::core::InstanceSpecifier& storage,
        ara::per::RecoveryReportKind recoveryReportKind,
        ara::core::Vector<ara::core::String> reportedElements,
        ara::core::Vector<std::uint8_t> reportedInstances)> recoveryReportCallback) noexcept;

}  // namespace per
}  // namespace ara
