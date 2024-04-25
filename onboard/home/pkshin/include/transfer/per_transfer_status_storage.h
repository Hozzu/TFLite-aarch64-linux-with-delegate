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

#ifndef ARA_UCM_LIBS_TRANSFER_STATUS_KVS_H_
#define ARA_UCM_LIBS_TRANSFER_STATUS_KVS_H_

#include "ara/per/key_value_storage.h"

namespace ara
{
namespace ucm
{
namespace libs
{

/// @brief A class represents a persistency storage (key-value database)
/// that is used to store and get the transfer status.
class TransferStatusKvs
{
public:
    /// @brief Stored status type
    using value_type = ara::core::Array<std::uint32_t, 4>;

    /// @brief Creates a persistency KVS with a given model identifier
    ///
    /// @param modelIdentifier Identifier used to access KVS
    explicit TransferStatusKvs(ara::core::String modelIdentifier);

    /// @brief Creates empty storage (not connected to kvs) for testing purposes.
    TransferStatusKvs();

    /// @brief Move constructor
    TransferStatusKvs(TransferStatusKvs&&);

    virtual ~TransferStatusKvs() = default;

    /// @brief Stores transfer status with the given key
    ///
    /// @param key Associated Key
    /// @param status Transfer Status to store
    virtual void StoreStatus(ara::core::StringView key, const ara::core::Array<std::uint64_t, 4> status);

    /// @brief Retrieves stored state with given key
    ///
    /// @param key Associated Key
    /// @return Optional Transfer Status
    virtual ara::core::Optional<value_type> GetStatus(ara::core::StringView key) const;

    /// @brief Removes stored status from the storage by a given key`
    ///
    /// @param key Associated key
    virtual void RemoveStatus(ara::core::StringView key);

private:
    /// @brief A shared handle to access key-value storage
    // ara::per::SharedHandle<ara::per::KeyValueStorage> kvs_;
};

}  // namespace libs
}  // namespace ucm
}  // namespace ara

#endif  // ARA_UCM_LIBS_TRANSFER_STATUS_KVS_H_
