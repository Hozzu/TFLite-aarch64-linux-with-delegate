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

#ifndef ARA_COM_INTERNAL_DDS_IDL_SHARED_REGISTRY_H_
#define ARA_COM_INTERNAL_DDS_IDL_SHARED_REGISTRY_H_

#include <functional>
#include <memory>

#include "ara/core/map.h"
#include "ara/com/internal/dds_idl/common.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace dds
{

template <class T>
struct SharedPolicy
{
    using EntryType = std::shared_ptr<T>;

    static inline bool IsValid(const EntryType& entry)
    {
        return (nullptr != entry);
    }

    static inline std::shared_ptr<T> Get(EntryType& entry)
    {
        return entry;
    }
};

template <class T>
struct WeakPolicy
{
    using EntryType = std::weak_ptr<T>;

    static inline bool IsValid(const EntryType& entry)
    {
        return !entry.expired();
    }

    static inline std::shared_ptr<T> Get(EntryType& entry)
    {
        return entry.lock();
    }
};

template <typename Key, typename Value, template <typename> class SharePolicy>
class TypeRegistry
{
public:
    using Constructor = std::function<std::shared_ptr<Value>()>;
    std::shared_ptr<Value> Get(const Key& key, Constructor ctr);
    void clear();

private:
    using Policy = SharePolicy<Value>;
    ara::core::Map<Key, typename Policy::EntryType> data_;
};

template <typename Key, typename Value, template <typename> class SharePolicy>
void TypeRegistry<Key, Value, SharePolicy>::clear()
{
    data_.clear();
}

template <typename Key, typename Value, template <typename> class SharePolicy>
std::shared_ptr<Value> TypeRegistry<Key, Value, SharePolicy>::Get(const Key& key,
    TypeRegistry<Key, Value, SharePolicy>::Constructor ctr)
{
    auto& entry = data_[key];
    if (Policy::IsValid(entry)) {
        return Policy::Get(entry);
    }

    if (!ctr) {
        common::logger().LogError() << "TypeRegistry::Get(): input constructor is nullptr";
        return nullptr;
    }

    auto newcomer = ctr();
    if (!newcomer) {
        common::logger().LogError() << "TypeRegistry::Get(): created newcomer is nullptr";
        return nullptr;
    }

    entry = newcomer;
    return newcomer;
}

template <typename Key, typename Value>
using SharedRegistry = TypeRegistry<Key, Value, SharedPolicy>;

template <typename Key, typename Value>
using WeakRegistry = TypeRegistry<Key, Value, WeakPolicy>;

}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_INTERNAL_DDS_IDL_SHARED_REGISTRY_H_
