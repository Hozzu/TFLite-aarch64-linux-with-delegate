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

#ifndef ARA_PER_UPDATE_H_
#define ARA_PER_UPDATE_H_

#include <functional>

#include "ara/core/instance_specifier.h"
#include "ara/core/result.h"
#include "ara/core/string.h"

#include "ara/per/per_error_domain.h"

namespace ara
{
namespace per
{

/// @brief Registers an application data update callback with Persistency.
///
/// The provided callback function will be called by Persistency if an update of stored application data might be
/// necessary.
///
/// This decision is based on the Executable versions. The version that last accessed Persistency is provided as an
/// argument to the callback, as well as the InstanceSpecifier referring to the updated Key-Value Storage or File
/// Storage.
///
/// The provided function will be called from the context of UpdatePersistency(), OpenKeyValueStorage(), or
/// OpenFileStorage().
///
/// @uptrace{SWS_PER_00356, 87ceb84c35a1948e93061ef2f6f19acaf3a83728}
/// @threadsafety{no}
/// @param appDataUpdateCallback The callback function to be called by Persistency after an update of persistent data
///                              took place. The function will be called with the shortName path of an updated Key-Value
///                              Storage or File Storage, and with the Executable version with which the Persistency was
///                              last accessed.
void RegisterApplicationDataUpdateCallback(
    std::function<void(const ara::core::InstanceSpecifier& storage, ara::core::String version)>
        appDataUpdateCallback) noexcept;

/// @brief Updates all Persistency File Storages and Key-Value Storages after a new manifest was installed.
///
/// This method can be used to update the persistent data of the application during verification phase.
///
/// @uptrace{SWS_PER_00357, 1103f1483d39b4b2513ea061c0eabbfc8901e511}
/// @threadsafety{no}
/// @returns A Result of void. In case of an error, it contains any of the errors defined below, or a vendor specific
///          error.
/// @error PerErrc::kPhysicalStorageFailure Returned if access to the storage fails during the update operation.
/// @error PerErrc::kIntegrityCorrupted Returned if stored data cannot be read because the integrity is corrupted.
/// @error PerErrc::kValidationFailed Returned if the validity of stored data cannot be ensured.
/// @error PerErrc::kEncryptionFailed Returned if the encryption or decryption of stored data fails during the update
///                                   operation.
/// @error PerErrc::kResourceBusy Returned if ResetPersistency is currently being executed, or if RecoverKeyValueStorage
///                               or ResetKeyValueStorage is currently being executed for any Key-Value Storage, or if
///                               RecoverAllFiles or ResetAllFiles is currently being executed for any File Storage, or
///                               a SharedHandle of a Key-Value Storage or a File Storage is currently in use.
/// @error PerErrc::kOutOfStorageSpace Returned if the available storage space is insufficient for the update.
ara::core::Result<void> UpdatePersistency() noexcept;

/// @brief Removes all File Storages and Key-Value Storages.
///
/// This method can be used to restore the initial state or to prepare removal of the application.
///
/// It does not report any problems with the current Key-Value Storages or File Storages and will call ara::core::Abort
/// when the space for the initial state of the Key-Value Storages or File Storages is not available. The latter can be
/// avoided by configuring a suitable minimumSustainedSize.
///
/// @uptrace{SWS_PER_00358, 1bc5dd9d04ffb87e702a98b69ad64f78bee026cd}
/// @threadsafety{no}
/// @returns A Result of void. In case of an error, it contains any of the errors defined below, or a vendor specific
///          error.
/// @error PerErrc::kPhysicalStorageFailure Returned if access to the storage fails during the reset operation.
/// @error PerErrc::kEncryptionFailed Returned if the encryption or decryption of stored data fails during the reset
///                                   operation.
/// @error PerErrc::kResourceBusy Returned if UpdatePersistency is currently being executed, or if
///                               RecoverKeyValueStorage or ResetKeyValueStorage is currently being executed for any
///                               Key-Value Storage, or if RecoverAllFiles or ResetAllFiles is currently being executed
///                               for any File Storage, or a SharedHandle of a Key-Value Storage or a File Storage is
///                               currently in use.
ara::core::Result<void> ResetPersistency() noexcept;

}  // namespace per
}  // namespace ara

#endif  // ARA_PER_UPDATE_H_
