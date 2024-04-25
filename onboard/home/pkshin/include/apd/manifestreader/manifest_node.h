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

#ifndef APD_MANIFESTREADER_INCLUDE_PUBLIC_APD_MANIFESTREADER_MANIFEST_NODE_H_
#define APD_MANIFESTREADER_INCLUDE_PUBLIC_APD_MANIFESTREADER_MANIFEST_NODE_H_

#include "apd/manifestreader/manifestreader_error_domain.h"

#include "ara/core/string_view.h"
#include "ara/core/string.h"
#include "ara/core/result.h"
#include "ara/core/vector.h"
#include "ara/core/optional.h"

#include <utility>
#include <cstdint>
#include <functional>
#include "rapidjson/document.h"

#define MR_HEADER(TYPE)                                                                               \
    namespace apd                                                                                     \
    {                                                                                                 \
    namespace manifestreader                                                                          \
    {                                                                                                 \
    template <>                                                                                       \
    struct Helper<TYPE>                                                                               \
    {                                                                                                 \
        static ara::core::Result<TYPE> Get(const rapidjson::Value& v)                                 \
        {                                                                                             \
            if (!v.IsObject()) {                                                                      \
                return ara::core::Result<TYPE>::FromError(ManifestReaderErrc::kInvalidTypeRequested); \
            }                                                                                         \
            TYPE result;

#define MR_FIELD(KEY, FIELDNAME)                                                                     \
    {                                                                                                \
        if (!v.HasMember(KEY)) {                                                                     \
            return ara::core::Result<decltype(result)>::FromError(ManifestReaderErrc::kKeyNotFound); \
        }                                                                                            \
        auto getRes = Helper<decltype(result.FIELDNAME)>::Get(v[KEY]);                               \
        if (!getRes) {                                                                               \
            return ara::core::Result<decltype(result)>::FromError(getRes.Error());                   \
        }                                                                                            \
        result.FIELDNAME = std::move(getRes).Value();                                                \
    }

#define MR_OPTIONAL_FIELD(KEY, FIELDNAME)                                              \
    {                                                                                  \
        if (v.HasMember(KEY)) {                                                        \
            auto getRes = Helper<decltype(result.FIELDNAME)>::Get(v[KEY]);             \
            if (!getRes) {                                                             \
                return ara::core::Result<decltype(result)>::FromError(getRes.Error()); \
            }                                                                          \
            result.FIELDNAME = std::move(getRes).Value();                              \
        }                                                                              \
    }

#define MR_FOOTER  \
    return result; \
    }              \
    }              \
    ;              \
    }              \
    }

namespace apd
{
namespace manifestreader
{

template <typename T>
struct Helper
{
    // Template user expects the next function:
    // ara::core::Result<T> Get(const rapidjson::Value& v);
};

template <typename T>
struct Helper<ara::core::Optional<T>>
{
    static ara::core::Result<ara::core::Optional<T>> Get(const rapidjson::Value& v)
    {
        auto res = Helper<T>::Get(v);

        if (!res) {
            return ara::core::Result<ara::core::Optional<T>>::FromError(ManifestReaderErrc::kInvalidTypeRequested);
        }

        return ara::core::Optional<T>(std::move(res).Value());
    }
};

template <typename T>
struct Helper<ara::core::Vector<T>>
{
    static ara::core::Result<ara::core::Vector<T>> Get(const rapidjson::Value& v)
    {
        ara::core::Vector<T> result;

        if (!v.IsArray()) {
            return ara::core::Result<ara::core::Vector<T>>::FromError(ManifestReaderErrc::kInvalidTypeRequested);
        }
        result.reserve(v.Size());

        for (rapidjson::SizeType i = 0; i < v.Size(); i++) {
            auto getRes = Helper<T>::Get(v[i]);

            if (!getRes) {
                return ara::core::Result<ara::core::Vector<T>>::FromError(getRes.Error());
            }
            result.push_back(std::move(getRes).Value());
        }

        return result;
    }
};

template <>
struct Helper<ara::core::String>
{
    static ara::core::Result<ara::core::String> Get(const rapidjson::Value& v)
    {
        if (!v.IsString()) {
            return ara::core::Result<ara::core::String>::FromError(ManifestReaderErrc::kInvalidTypeRequested);
        }

        return ara::core::String(v.GetString());
    }
};

template <>
struct Helper<uint64_t>
{
    static ara::core::Result<uint64_t> Get(const rapidjson::Value& v)
    {
        if (!v.IsUint()) {
            return ara::core::Result<uint64_t>::FromError(ManifestReaderErrc::kInvalidTypeRequested);
        }

        return v.GetUint();
    }
};

template <>
struct Helper<uint32_t>
{
    static ara::core::Result<uint32_t> Get(const rapidjson::Value& v)
    {
        if (!v.IsUint()) {
            return ara::core::Result<uint32_t>::FromError(ManifestReaderErrc::kInvalidTypeRequested);
        }

        return v.GetUint();
    }
};

template <>
struct Helper<int64_t>
{
    static ara::core::Result<int64_t> Get(const rapidjson::Value& v)
    {
        if (!v.IsInt()) {
            return ara::core::Result<int64_t>::FromError(ManifestReaderErrc::kInvalidTypeRequested);
        }

        return v.GetInt();
    }
};

template <>
struct Helper<double>
{
    static ara::core::Result<double> Get(const rapidjson::Value& v)
    {
        if (!v.IsDouble()) {
            return ara::core::Result<double>::FromError(ManifestReaderErrc::kInvalidTypeRequested);
        }

        return v.GetDouble();
    }
};

template <>
struct Helper<bool>
{
    static ara::core::Result<bool> Get(const rapidjson::Value& v)
    {
        if (!v.IsBool()) {
            return ara::core::Result<bool>::FromError(ManifestReaderErrc::kInvalidTypeRequested);
        }

        return v.GetBool();
    }
};
class ArrayProxy
{
public:
    explicit ArrayProxy(const rapidjson::Value& v) noexcept
        : arrayNode_(v)
    { }

    const rapidjson::Value* begin() const noexcept
    {
        auto beginIt = arrayNode_.Begin();
        if (beginIt == arrayNode_.End()) {
            const rapidjson::Value* arrayNodePtr = &arrayNode_;
            return arrayNodePtr;
        }
        return &arrayNode_[0];
    }

    const rapidjson::Value* end() const noexcept
    {
        auto beginIt = arrayNode_.Begin();
        if (beginIt == arrayNode_.End()) {
            const rapidjson::Value* arrayNodePtr = &arrayNode_;
            return arrayNodePtr;
        }
        const rapidjson::SizeType size = arrayNode_.Size();
        return &arrayNode_[0] + size;
    }

private:
    const rapidjson::Value& arrayNode_;
};

class ManifestNode
{
public:
    /// @brief receive value of type T by key
    ///
    /// Supported standard types are: bool, float, ara::core::String, int64_t, uint64_t
    /// Also usable with MR_FIELD_HEADER/_INFO/_FOOTER for parsing of custom structures
    /// Examples of acceptable keys:
    /// "some_key"
    /// "some_key.some_other.target"
    /// "some_array[1].some_key"
    ///
    /// @tparam type of expected result
    /// @param key path to find the value
    /// @returns result with the data or error
    ///
    /// @note possible errors are: kParsing, kKeyNotFound and kInvalidTypeRequested
    template <typename T>
    ara::core::Result<T> GetValue(ara::core::StringView key) const noexcept
    {
        auto valueRes = GetValueByPath(key);
        if (!valueRes) {
            return ara::core::Result<T>::FromError(valueRes.Error());
        }
        const rapidjson::Value& v = *valueRes.Value();

        return Helper<T>::Get(v);
    }

    /// @brief receive array of values of type T by key
    ///
    /// Supported standard types are: bool, float, ara::core::String, int64_t, uint64_t
    /// Also usable with MR_FIELD_HEADER/_INFO/_FOOTER for parsing of custom structures
    /// Examples of acceptable keys:
    /// "some_key"
    /// "some_key.some_other.target"
    /// "some_array[1].some_key"
    ///
    /// @tparam type of expected result
    /// @param key path to find the value
    /// @returns result with the data array or error
    ///
    /// @note possible errors are: kParsing, kKeyNotFound and kInvalidTypeRequested
    template <typename T>
    ara::core::Result<ara::core::Vector<T>> GetArray(ara::core::StringView key) const noexcept
    {
        ara::core::Vector<T> result;

        auto valueRes = GetValueByPath(key);
        if (!valueRes) {
            return ara::core::Result<ara::core::Vector<T>>::FromError(valueRes.Error());
        }

        const rapidjson::Value& v = *valueRes.Value();

        return Helper<ara::core::Vector<T>>::Get(v);
    }

    ara::core::Result<void> Iterate(ara::core::StringView key, std::function<void(ManifestNode const&)>) const noexcept;

    ara::core::Result<ArrayProxy> ArrayIterate(ara::core::StringView key) const noexcept
    {
        auto valueRes = GetValueByPath(key);
        if (!valueRes) {
            return ara::core::Result<ArrayProxy>::FromError(valueRes.Error());
        }
        const rapidjson::Value& v = *valueRes.Value();

        if (!v.IsArray()) {
            return ara::core::Result<ArrayProxy>::FromError(ManifestReaderErrc::kInvalidTypeRequested);
        }
        return ArrayProxy(v);
    }

protected:
    ManifestNode(const rapidjson::Value& node)
        : node_(node)
    { }
    virtual ~ManifestNode() = default;

private:
    const rapidjson::Value& node_;

    ara::core::Result<const rapidjson::Value*> GetValueByPath(ara::core::StringView key) const noexcept;
};

}  // namespace manifestreader
}  // namespace apd

#endif  // APD_MANIFESTREADER_INCLUDE_PUBLIC_APD_MANIFESTREADER_MANIFEST_NODE_H_
