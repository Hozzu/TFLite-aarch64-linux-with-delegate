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

#ifndef ARA_PER_MANIFEST_ACCESS_SERIALIZER_H
#define ARA_PER_MANIFEST_ACCESS_SERIALIZER_H

#include <type_traits>

#include "ara/per/kvstype/kvs_type.h"
#include "ara/core/string.h"
#include "ara/core/string_view.h"
#include "ara/core/result.h"
#include "ara/per/per_error_domain.h"

namespace ara
{
namespace per
{
namespace serialization
{
namespace internal
{

template <typename Type>
class Serializer;

#define BEGIN_SERIALIZE_INFO(Type)                                                   \
    namespace ara                                                                    \
    {                                                                                \
    namespace per                                                                    \
    {                                                                                \
    namespace serialization                                                          \
    {                                                                                \
    namespace internal                                                               \
    {                                                                                \
    template <>                                                                      \
    class Serializer<Type>                                                           \
    {                                                                                \
        Type* data = nullptr;                                                        \
        Type const* constData = nullptr;                                             \
                                                                                     \
    public:                                                                          \
        Serializer(Type* value, Type const* constValue)                              \
            : data(value)                                                            \
            , constData(constValue)                                                  \
        { }                                                                          \
                                                                                     \
        template <typename DataType, typename Handler>                               \
        static ara::core::Result<void> ProcessData(DataType* data, Handler& handler) \
        {                                                                            \
            ara::core::Result<void> res;

#define FIELD(KEY, FIELDNAME)                                          \
    res = handler.Handle(ara::core::StringView(KEY), data->FIELDNAME); \
    if (!res) {                                                        \
        return res;                                                    \
    }

#define END_SERIALIZE_INFO                                    \
    return ara::core::Result<void>::FromValue();              \
    }                                                         \
    ara::core::Result<void> Process(KvsReader& handler)       \
    {                                                         \
        return ProcessData(data, handler);                    \
    }                                                         \
    ara::core::Result<void> Process(KvsWriter& handler) const \
    {                                                         \
        return ProcessData(constData, handler);               \
    }                                                         \
    }                                                         \
    ;                                                         \
    }                                                         \
    }                                                         \
    }                                                         \
    }

class KvsWriter
{
    ara::per::kvstype::KvsType result;

public:
    explicit KvsWriter(ara::core::StringView key)
    {
        result.SetKey(ara::core::String(key));
    }

    ara::per::kvstype::KvsType const& GetValue() const
    {
        return result;
    }

    template <class T,
        typename std::enable_if<std::is_same<T, ara::core::String>::value || std::is_integral<T>::value
                || std::is_floating_point<T>::value,
            T>::type* = nullptr>
    ara::core::Result<void> Handle(ara::core::StringView name, const T& value)
    {
        ara::per::kvstype::KvsType element(value);
        element.SetKey(ara::core::String(name));
        return result.AddArrayItem(element);
    }

    template <class T,
        typename std::enable_if<std::is_constructible<Serializer<T>, T*, T const*>::value, T>::type* = nullptr>
    ara::core::Result<void> Handle(ara::core::StringView name, T const& value)
    {
        KvsWriter writer(name);
        Serializer<T> s(nullptr, &value);
        auto res = s.Process(writer);
        return res ? result.AddArrayItem(writer.GetValue()) : res;
    }
};

class KvsReader
{

    ara::per::kvstype::KvsType parent;

public:
    KvsReader(ara::per::kvstype::KvsType& parentElement)
        : parent(parentElement){};

    template <class T, typename std::enable_if<std::is_same<T, ara::core::String>::value, T>::type* = nullptr>
    ara::core::Result<void> Handle(ara::core::StringView name, T& value)
    {
        // firstly find needed element in parent child elements
        auto resChildElements = parent.GetArray<ara::per::kvstype::KvsType>();
        if (!resChildElements) {
            return ara::core::Result<void>::FromError(resChildElements.Error());
        }

        ara::per::kvstype::KvsType foundChild;
        auto it = std::find_if(resChildElements.Value().begin(),
            resChildElements.Value().end(),
            [&name](const ara::per::kvstype::KvsType& child) { return child.GetKey() == ara::core::String(name); });
        if (it != resChildElements.Value().end()) {
            foundChild = *it;
        }
        // if child element not found, just return - not an error
        if (foundChild.GetStatus() != ara::per::kvstype::KvsType::Status::kSuccess) {
            return ara::core::Result<void>::FromValue();
        }

        if (foundChild.GetType() != ara::per::kvstype::KvsType::Type::kString) {
            return ara::core::Result<void>::FromError(PerErrc::kDataTypeMismatch);
        }

        auto kvsVal = foundChild.GetString();
        if (kvsVal) {
            value = kvsVal.Value();
            return ara::core::Result<void>::FromValue();
        } else {
            return ara::core::Result<void>::FromError(kvsVal.Error());
        }
    }

    template <class T, typename std::enable_if<std::is_floating_point<T>::value, T>::type* = nullptr>
    ara::core::Result<void> Handle(ara::core::StringView name, T& value)
    {
        using ara::per::kvstype::KvsType;
        // firstly find needed element in parent child elements
        auto resChildElements = parent.GetArray<KvsType>();
        if (!resChildElements) {
            return ara::core::Result<void>::FromError(resChildElements.Error());
        }

        KvsType foundChild;
        auto it = std::find_if(resChildElements.Value().begin(),
            resChildElements.Value().end(),
            [&name](const ara::per::kvstype::KvsType& child) { return child.GetKey() == ara::core::String(name); });
        if (it != resChildElements.Value().end()) {
            foundChild = *it;
        }

        // if child element not found, just return - not an error
        if (foundChild.GetStatus() != KvsType::Status::kSuccess) {
            return ara::core::Result<void>::FromValue();
        }

        if (foundChild.GetType() != KvsType::Type::kDouble && foundChild.GetType() != KvsType::Type::kFloat) {
            return ara::core::Result<void>::FromError(PerErrc::kDataTypeMismatch);
        }

        auto kvsVal = foundChild.GetDouble();
        if (kvsVal) {
            value = kvsVal.Value();
            return ara::core::Result<void>::FromValue();
        } else {
            return ara::core::Result<void>::FromError(kvsVal.Error());
        }
    }

    template <class T, typename std::enable_if<std::is_integral<T>::value, T>::type* = nullptr>
    ara::core::Result<void> Handle(ara::core::StringView name, T& value)
    {
        using ara::per::kvstype::KvsType;
        // firstly find needed element in parent child elements
        auto resChildElements = parent.GetArray<KvsType>();
        if (!resChildElements) {
            return ara::core::Result<void>::FromError(resChildElements.Error());
        }

        KvsType foundChild;
        auto it = std::find_if(resChildElements.Value().begin(),
            resChildElements.Value().end(),
            [&name](const KvsType& child) { return child.GetKey() == ara::core::String(name); });
        if (it != resChildElements.Value().end()) {
            foundChild = *it;
        }
        // if child element not found, just return - not an error
        if (foundChild.GetStatus() != KvsType::Status::kSuccess) {
            return ara::core::Result<void>::FromValue();
        }

        switch (foundChild.GetType()) {
        case KvsType::Type::kSInt8:
        case KvsType::Type::kSInt16:
        case KvsType::Type::kSInt32:
        case KvsType::Type::kSInt64: {
            auto kvsVal = foundChild.GetSInt64();
            if (kvsVal) {
                value = kvsVal.Value();
                return ara::core::Result<void>::FromValue();
            } else {
                return ara::core::Result<void>::FromError(kvsVal.Error());
            }
        }
        case KvsType::Type::kUInt8:
        case KvsType::Type::kUInt16:
        case KvsType::Type::kUInt32:
        case KvsType::Type::kUInt64: {
            auto kvsVal = foundChild.GetUInt64();
            if (kvsVal) {
                value = kvsVal.Value();
                return ara::core::Result<void>::FromValue();
                ;
            } else {
                return ara::core::Result<void>::FromError(kvsVal.Error());
            }
        }
        case KvsType::Type::kBoolean: {
            auto kvsVal = foundChild.GetBool();
            if (kvsVal) {
                value = kvsVal.Value();
                return ara::core::Result<void>::FromValue();
            } else {
                return ara::core::Result<void>::FromError(kvsVal.Error());
            }
        }
        default:
            break;
        }

        return ara::core::Result<void>::FromError(PerErrc::kDataTypeMismatch);
    }

    template <class T,
        typename std::enable_if<std::is_constructible<Serializer<T>, T*, T const*>::value, T>::type* = nullptr>
    ara::core::Result<void> Handle(ara::core::StringView name, T& value)
    {
        using ara::per::kvstype::KvsType;
        KvsType foundChild;
        ara::core::Vector<KvsType> childElements = parent.GetArray<KvsType>().Value();

        auto it = std::find_if(childElements.begin(), childElements.end(), [&name](const KvsType& child) {
            return child.GetKey() == ara::core::String(name);
        });
        if (it != childElements.end()) {
            foundChild = *it;
        }

        // if child element not found, just return - not an error
        if (foundChild.GetStatus() != KvsType::Status::kSuccess) {
            return ara::core::Result<void>::FromValue();
        }

        KvsReader reader(foundChild);
        Serializer<T> ds(&value, nullptr);
        return ds.Process(reader);
    }
};

}  // namespace internal
}  // namespace serialization
}  // namespace per
}  // namespace ara

#endif  // ARA_PER_MANIFEST_ACCESS_SERIALIZER_H
