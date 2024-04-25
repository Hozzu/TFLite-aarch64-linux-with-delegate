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

#ifndef ARA_UCM_LIBS_SAFE_MAP_OF_SHARED_POINTERS_H_
#define ARA_UCM_LIBS_SAFE_MAP_OF_SHARED_POINTERS_H_

#include <algorithm>
#include <type_traits>

#include <boost/thread/shared_mutex.hpp>

#include "ara/com/types.h"
#include "ara/core/map.h"
#include "ara/core/vector.h"
#include "ara/core/optional.h"

#include "transfer/serial_id_generator.h"  // SerialIDGenerator
#include "transfer/software_package_data_factory.h"  // SoftwarePackageDataFactory
#include "types/impl_type_transferidtype.h"  // TransferIdType

namespace ara
{
namespace ucm
{
namespace libs
{

/// @brief This class is a general thread-safe map/factory
///
/// It creates a new record (id, value) as follows:
/// 1) generates a new id using provided 'KeyFactory' functor class
/// 2) creates new item using provided 'ValueFactory' functor class
/// 3) adds the created pair into the internal container.
/// This class is a factory (the new item is created by this class and is not provided from outside). For testing
/// purposes there is an 'AddItem' function though.
///
/// @uptrace{SWS_UCM_00075, 4c6a267bff27ac47201bbf396bf6ee3e4cbc4cf3}
template <typename KeyType, typename ValueType>
class ThreadSafeMapOfSharedPtrs
{
public:
    using ValueSharedPtr = std::shared_ptr<ValueType>;

    /// @brief add item to the container
    ///
    /// @param id where to insert a new value
    /// @param data to insert
    void AddItem(KeyType id, ValueSharedPtr data)
    {
        boost::unique_lock<boost::shared_mutex> lock{access_};

        NonBlockingAddItem(id, data);
    }

    /// @brief Get item from the container assotiated with the key
    ///
    /// @param id identifier of an item to get
    ///
    /// @return ValueSharedPtr or nullptr in case of an error
    ValueSharedPtr GetItem(KeyType id) const
    {
        boost::shared_lock<boost::shared_mutex> lock{access_};

        auto iter = data_.find(id);

        if (iter == data_.end()) {
            // re-enable when debugging. One may pull the logger in this function to be to log
            // std::cerr << __func__ << " missing id=" << static_cast<int>(id) << std::endl;
            // std::cerr << __func__ << " totally " << data_.size() << " items in storage" << std::endl;
            return nullptr;
        }

        return iter->second;
    }

    /// @brief Create and store new item
    ///
    /// @return Newly inserted pair or error
    template <typename ValueFactory, typename KeyFactory>
    ara::core::Optional<std::pair<KeyType, ValueSharedPtr>> AddNewItemWithId(KeyFactory& idGenerator,
        ValueFactory& valueFactory,
        ara::core::String directory)
    {
        static_assert(std::is_same<typename KeyFactory::ResultType, KeyType>::value,
            "Generated Result Type shall be equal to KeyType");

        boost::unique_lock<boost::shared_mutex> lock{access_};

        const auto key = idGenerator(data_);

        if (!key) {
            return {};
        }

        const std::shared_ptr<ValueType> item = valueFactory.Create(directory, *key);
        NonBlockingAddItem(*key, item);

        return {std::make_pair(item->GetID(), item)};
    }

    /// @brief delete item from the container
    ///
    /// @param id of a value to delete
    void DeleteItem(KeyType id)
    {
        boost::unique_lock<boost::shared_mutex> lock{access_};

        data_.erase(id);
    }

    /// @brief Apply function to every item in caontainer
    ///
    /// @param processor Function to apply to key-value pairs
    void IterateItems(std::function<void(const std::pair<KeyType, ValueSharedPtr const&>)> processor) const
    {
        boost::unique_lock<boost::shared_mutex> lock{access_};

        for (auto const& pair : data_) {
            processor(pair);
        }
    }

private:
    mutable boost::shared_mutex access_;
    ara::core::Map<KeyType, ValueSharedPtr> data_;

    void NonBlockingAddItem(KeyType id, ValueSharedPtr data)
    {
        data_.emplace(std::make_pair(id, data));
    }

};  // namespace ucm

using TransferIdToSoftwarePackageFactory = ThreadSafeMapOfSharedPtrs<  //
    ara::ucm::TransferIdType,  // key
    ara::ucm::libs::SoftwarePackageData  // value
    >;

}  // namespace libs
}  // namespace ucm
}  // namespace ara

#endif  // ARA_UCM_LIBS_SAFE_MAP_OF_SHARED_POINTERS_H_
