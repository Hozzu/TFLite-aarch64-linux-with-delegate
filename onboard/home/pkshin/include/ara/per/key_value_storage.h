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

#ifndef ARA_PER_KEY_VALUE_STORAGE_H_
#define ARA_PER_KEY_VALUE_STORAGE_H_

#include "ara/core/result.h"
#include "ara/core/string.h"
#include "ara/core/string_view.h"
#include "ara/core/vector.h"
#include "ara/core/instance_specifier.h"

#include "ara/per/shared_handle.h"
#include "ara/per/serializer.h"

///
/// @uptrace{SWS_PER_00002, fb49f277ba9a813303ba248e2a7970b903647cd7}
namespace ara
{
namespace per
{

/// @brief The Key-Value Storage contains a set of keys with associated values.
///
/// @uptrace{SWS_PER_00339, 0000000000000000000000000000000000000000}
class KeyValueStorage
{
public:
    /// @brief Default constructor for KeyValueStorage.
    ///
    /// @uptrace{SWS_PER_00459, 8c443c416934013d43b6197577a4748b0ed0002d}
    /// @threadsafety{tbd}
    KeyValueStorage() = default;

    /// @brief The move constructor for KeyValueStorage shall not be used.
    ///
    /// @uptrace{SWS_PER_00322, 2d501e5a1d459644807771c4927ca287e3c0bf99}
    /// @threadsafety{tbd}
    KeyValueStorage(KeyValueStorage&& kvs) = delete;

    /// @brief Move assignment operator for KeyValueStorage.
    ///
    /// @uptrace{SWS_PER_00323, 3d8779bb458a87e82f04c422a7e8ee65f38c2f4f}
    /// @threadsafety{tbd}
    /// @returns The moved KeyValueStorage object.
    KeyValueStorage& operator=(KeyValueStorage&& kvs) & = delete;

    /// @brief The copy constructor for KeyValueStorage shall not be used.
    ///
    /// @uptrace{SWS_PER_00324, 880dc5f47a3604eb3b0d7a7c771a9f963cc6f84e}
    /// @threadsafety{tbd}
    KeyValueStorage(const KeyValueStorage&) = delete;

    /// @brief The copy assignment operator for KeyValueStorage shall not be used.
    ///
    /// @uptrace{SWS_PER_00325, 859123ae48bb9825ab794a087d2bb8bc9148c229}
    /// @threadsafety{re-entrant}
    KeyValueStorage& operator=(const KeyValueStorage&) = delete;

    /// @brief Destructor for KeyValueStorage.
    ///
    /// @uptrace{SWS_PER_00050, 0af8e4ccb6320d5d6a346fe421d073c8becdc006}
    /// @threadsafety{no}
    virtual ~KeyValueStorage() noexcept = default;

    /// @brief Returns a list of all currently available keys of the KeyValueStorage.
    ///
    /// @uptrace{SWS_PER_00042, 07d1a79fc2937858b2df8a4ffc33507f82d0bcec}
    /// @uptrace{SWS_PER_00505, 7a546a8f2dc4c311184f316e0f3f41248a4d1c92}
    /// @threadsafety{re-entrant}
    /// @returns A Result, containing a list of available keys, or one of the errors
    /// defined for Persistency in PerErrc.
    virtual ara::core::Result<ara::core::Vector<ara::core::String>> GetAllKeys() const noexcept = 0;

    /// @brief Checks if a key exists in the KeyValueStorage.
    ///
    /// @uptrace{SWS_PER_00043, 6d1cca3f7489afbe6658a360f2d2228efc9d4046}
    /// @uptrace{SWS_PER_00504, 0bced56c29a5a5181755db6c03f75bb646ed32a9}
    /// @threadsafety{re-entrant}
    /// @param[in] key The key that shall be checked.
    /// @returns A Result, containing true if the key could be located or false if it could not,
    /// or one of the errors defined for Persistency in PerErrc.
    virtual ara::core::Result<bool> KeyExists(ara::core::StringView key) const noexcept = 0;

    /// @brief Returns the value assigned to a key of the KeyValueStorage.
    ///
    /// @uptrace{SWS_PER_00332, d7ded56c7f34ec1c475332024aaa051a95304512}
    /// @threadsafety{re-entrant}
    /// @tparam T The type of the value that shall be retrieved.
    /// @param[in] key The key to look up.
    /// @param[out] value The retrieved value.
    /// @returns The success of the operation.
    template <typename T>
    ara::core::Result<T> GetValue(ara::core::StringView key) const noexcept;

    /// @brief Stores a key in the KeyValueStorage.
    ///
    /// @uptrace{SWS_PER_00046, 524bf5a1007c8f5fb5849105012b97c89b79e50d}
    /// @uptrace{SWS_PER_00331, 9716769eb375ec7f2b8d587523c6498c84cde332}
    /// @uptrace{SWS_PER_00534, 3a8410b3bd3f849895530074f946c9610ab55a8a}
    /// @threadsafety{re-entrant}
    /// @tparam T The type of the value that shall be set.
    /// @param[in] key The key to assign the value to.
    /// @param[in] value The value to store.
    /// @returns The success of the operation.
    template <typename T>
    ara::core::Result<void> SetValue(ara::core::StringView key, const T& value) noexcept;

    /// @brief Resets a key and the associated value in the KeyValueStorage.
    ///
    /// @uptrace{SWS_PER_00426, 30730ea1a803955553b01c63a57465e74bc95c66}
    /// @uptrace{SWS_PER_00477, 8950637a89e8934baf9b1b7a4f445d8e082bfbc8}
    /// @threadsafety{re-entrant}
    /// @param[in] key The key to be reset.
    /// @returns The success of the operation.
    virtual ara::core::Result<void> ResetKey(ara::core::StringView key) noexcept = 0;

    /// @brief Removes a key and the associated value from the KeyValueStorage.
    ///
    /// @uptrace{SWS_PER_00047, 92040d1af3ec9014f942150a6a8faa3c8b285a82}
    /// @uptrace{SWS_PER_00535, 285b335d10b15ae2fa10259570b94659c1db82b6}
    /// @uptrace{SWS_PER_00502, 6ee7da23343e78adad5f6f54db78aa2d116866f6}
    /// @threadsafety{re-entrant}
    /// @param[in] key The key to be removed.
    /// @returns The success of the operation.
    virtual ara::core::Result<void> RemoveKey(ara::core::StringView key) noexcept = 0;

    /// @brief Recover a key and the associated value.
    ///
    /// @uptrace{SWS_PER_00427, b7b3b0a5b0534511de6d615486f0b0ac1a74f087}
    /// @uptrace{SWS_PER_00453, c600e860f56588c47a6d438436e5a096084dd0ae}
    /// @threadsafety{re-entrant}
    /// @param[in] key The key to be removed.
    /// @returns The success of the operation.
    virtual ara::core::Result<void> RecoverKey(ara::core::StringView key) noexcept = 0;

    /// @brief Removes all keys and associated values from the KeyValueStorage.
    ///
    /// @uptrace{SWS_PER_00048, a28b27afbfe79db94674c43e47510e2aaa9d2d40}
    /// @uptrace{SWS_PER_00331, 9716769eb375ec7f2b8d587523c6498c84cde332}
    /// @uptrace{SWS_PER_00503, 475ca1e412f9ca939ba835617d165bc11e2a4cc3}
    /// @threadsafety{re-entrant}
    /// @returns The success of the operation.
    virtual ara::core::Result<void> RemoveAllKeys() noexcept = 0;

    /// @brief Triggers flushing of key-value pairs to the physical storage of the KeyValueStorage.
    ///
    /// @uptrace{SWS_PER_00049, 37bcc3a32423b4cbc071680f7e8bf55c1b115008}
    /// @uptrace{SWS_PER_00494, 9caab3118d0cd2fe0919ab1781a5c419eb423906}
    /// @threadsafety{re-entrant}
    virtual ara::core::Result<void> SyncToStorage() noexcept = 0;

    /// @brief Triggers rollback of all changes made to storage.
    ///
    /// @uptrace{SWS_PER_00365, be108b50da9fab1d96ebc8cc534b3a4a0d132a8f}
    /// @uptrace{SWS_PER_00495, 34c26d75f92130f0ce61c62babfe027672c53349}
    /// @threadsafety{re-entrant}
    virtual ara::core::Result<void> DiscardPendingChanges() noexcept = 0;

protected:
    virtual bool IsReadOnly() const noexcept = 0;
    virtual ara::core::Result<ara::core::Vector<std::uint8_t>> ReadByteStream(
        ara::core::StringView key) const noexcept = 0;
    virtual ara::core::Result<void> StoreByteStream(ara::core::StringView key,
        const ara::core::Vector<std::uint8_t>& value) noexcept = 0;
};

/// @brief Creates an instance of KeyValueStorage which configures the storage location.
///
/// @uptrace{SWS_PER_00052, 5d937205e031674ebce8585ccdff96bf50c21005}
/// @uptrace{SWS_PER_00506, 59f3b689bf80de92cd8bbca969bba49dd2af4560}
/// @threadsafety{re-entrant}
/// @param[in] databasePortPrototype The shortName of a PortPrototype typed by a PersistencyKeyValueDatabaseInterface.
/// @returns A Result, containing an instance of KeyValueStorage, or one of the errors defined for Persistency in
/// PerErrc.
ara::core::Result<SharedHandle<KeyValueStorage>> OpenKeyValueStorage(
    const ara::core::InstanceSpecifier& databasePortPrototype) noexcept;

/// @brief Recover an instance of KeyValueStorage which configures the storage location.
///
/// @uptrace{SWS_PER_00333, 17bc6258588e5891dcec9358a74f2a0435bde095}
/// @uptrace{SWS_PER_00452, 7903ba8b013a33af7a69b89630e05e18badd80eb}
/// @threadsafety{re-entrant}
/// @param[in] database The shortName of a PortPrototype typed by a PersistencyKeyValueDatabaseInterface.
/// @returns A Result, being either empty or one of the errors defined for Persistency in
/// PerErrc.
ara::core::Result<void> RecoverKeyValueStorage(const ara::core::InstanceSpecifier& port) noexcept;

/// @brief Reset an instance of KeyValueStorage to initial state.
///
/// @uptrace{SWS_PER_00334, c3819bd132a554ff28c4e221eb00313c333268f9}
/// @uptrace{SWS_PER_00456, 45643275c3e5ed05b65509704898e4c10a7cc3aa}
/// @threadsafety{re-entrant}
/// @param[in] database The shortName of a PortPrototype typed by a PersistencyKeyValueDatabaseInterface.
/// @returns A Result, being either empty or one of the errors defined for Persistency in
/// PerErrc.
ara::core::Result<void> ResetKeyValueStorage(const ara::core::InstanceSpecifier& port) noexcept;

/// @brief Returns the space in bytes currently occupied by a Key-Value Storage.
///
/// @uptrace{SWS_PER_00405, 720f2e4024dab2e78871f7205e067d1552a14423}
/// @threadsafety{re-entrant}
/// @param[in] The shortName path of a PortPrototype typed by a PersistencyKeyValueDatabaseInterface.
/// @returns A Result, containing the occupied space in bytes, or one of the errors defined for Persistency in PerErrc.
ara::core::Result<std::uint64_t> GetCurrentKeyValueStorageSize(const ara::core::InstanceSpecifier& kvs) noexcept;

/// @uptrace{SWS_PER_00496, e95acdff348da1c7577a11b7410196d0ab9c4fc6}
/// @uptrace{SWS_PER_00497, 37ef6c4ac71533eef9cddc575035768105bfca9d}
/// @uptrace{SWS_PER_00498, 8b1806911930d2eb487a18476fc8548aa8d9f68f}
template <typename T>
ara::core::Result<T> KeyValueStorage::GetValue(ara::core::StringView key) const noexcept
{
    auto data = ReadByteStream(key);
    if (!data) {
        return ara::core::Result<T>::FromError(data.Error());
    }

    try {
        ara::per::serialization::Deserializer<T> deserializer(data.Value());
        T value = deserializer.getValue();
        return ara::core::Result<T>::FromValue(std::move(value));
    } catch (std::runtime_error& e) {
        return ara::core::Result<T>::FromError(PerErrc::kDataTypeMismatch);
    }
}

/// @uptrace{SWS_PER_00499, fdf5ad179d858b7f5fedfb28d993d81d9754cb91}
/// @uptrace{SWS_PER_00501, 35bf9dea23132baba75b37bf726ead6ccd942202}
template <typename T>
ara::core::Result<void> KeyValueStorage::SetValue(ara::core::StringView key, const T& value) noexcept
{
    if (IsReadOnly()) {
        return ara::core::Result<void>::FromError(PerErrc::kIllegalWriteAccess);
    }

    try {
        ara::core::Vector<std::uint8_t> bytestream;
        ara::per::serialization::Serializer<T> serializer(value);
        serializer.pushbackTo(bytestream);
        return StoreByteStream(key, std::move(bytestream));
    } catch (std::runtime_error& e) {
        return ara::core::Result<void>::FromError(PerErrc::kDataTypeMismatch);
    }
}

}  // namespace per
}  // namespace ara

#endif  // ARA_PER_KEY_VALUE_STORAGE_H_
