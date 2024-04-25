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

#ifndef ARA_PER_SERIALIZER_H
#define ARA_PER_SERIALIZER_H

#include <algorithm>
#include <cstdint>
#include <set>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "ara/core/array.h"
#include "ara/core/optional.h"
#include "ara/core/map.h"
#include "ara/core/string.h"
#include "ara/core/vector.h"
#include "ara/core/utility.h"
#include "ara/per/per_error_domain.h"

namespace ara
{
namespace per
{
namespace serialization
{

template <typename T, typename Tagged = void>
struct is_enumerable
{
    static const bool value = false;  ///< Indicates if T::IsEnumerableTag exists.
};

template <typename T>
struct is_enumerable<T, typename T::IsEnumerableTag>
{
    static const bool value = true;
};

template <typename T, typename Tagged = void>
struct is_tlv
{
    static const bool value = false;
};

template <typename T>
struct is_tlv<T, typename T::Is_TLV_tag>
{
    static const bool value = true;
};

template <typename T>
using is_string = std::is_same<T, ara::core::String>;

template <typename T>
using is_byte = std::is_same<T, ara::core::Byte>;

template <typename T>
using EnableIfBaseType = typename std::enable_if<std::is_scalar<T>::value>::type;

template <typename T>
using EnableIfEnumerable = typename std::enable_if<is_enumerable<T>::value>::type;

template <typename T>
using EnableIfTlv = typename std::enable_if<is_tlv<T>::value>::type;

template <typename T>
using EnableIfEnumerableOrTlv = typename std::enable_if<is_enumerable<T>::value || is_tlv<T>::value>::type;

template <typename T>
using EnableIfOptional = typename std::enable_if<ara::core::is_optional<T>::value>::type;

template <typename T>
constexpr bool IsSerializable()
{
    return std::is_scalar<T>::value || is_enumerable<T>::value || is_tlv<T>::value || is_string<T>::value
        || is_byte<T>::value;
}

template <typename Container>
class SerializingEnumerator;

template <typename T>
class Serializer
{
public:
    using value_type = typename std::decay<T>::type;

    Serializer(const value_type& value)
        : value_(value)
    {
        static_assert(IsSerializable<value_type>(), "Type not serializable!");
    }

    template <typename Container>
    void pushbackTo(Container& c)
    {
        pushbackToHelper(c);
    }

private:
    const value_type& value_;

    template <typename Container, typename U = value_type>
    void pushbackToHelper(Container& c, EnableIfBaseType<U>* = nullptr)
    {
        const std::uint8_t* data = reinterpret_cast<const std::uint8_t*>(&value_);
        std::copy(data, data + sizeof(value_), std::back_inserter(c));
    }

    template <typename Container, typename U = value_type>
    void pushbackToHelper(Container& c, EnableIfEnumerableOrTlv<U>* = nullptr)
    {
        SerializingEnumerator<Container> enumerator(c);
        const_cast<value_type&>(value_).enumerate(enumerator);
    }
};

template <typename Container>
class SerializingEnumerator
{
public:
    SerializingEnumerator(Container& payload_data)
        : payload_data_(payload_data)
    { }

    template <typename T>
    void operator()(const T& value, std::uint32_t = 0)
    {
        Serializer<T> serializer(value);
        serializer.pushbackTo(payload_data_);
    }

    template <typename T>
    void operator()(const ara::core::Optional<T>& value, std::uint32_t = 0)
    {
        if (value) {
            // value presence indicator
            Serializer<bool>(true).pushbackTo(payload_data_);
            operator()(*value);
        } else {
            constexpr static T empty_value = {0};
            Serializer<bool>(false).pushbackTo(payload_data_);
            operator()(empty_value);
        }
    }

private:
    Container& payload_data_;
};

template <>
class Serializer<ara::core::String>
{
public:
    using value_type = ara::core::String;

    Serializer(const value_type& value)
        : str_(value)
    { }

    template <typename Container>
    void pushbackTo(Container& c)
    {
        const typename Container::value_type* nullTerminatedStringBegin
            = reinterpret_cast<const typename Container::value_type*>(str_.c_str());
        const typename Container::value_type* nullTerminatedStringEnd  // past the null terminator
            = nullTerminatedStringBegin + str_.size() + sizeof('\0');
        std::copy(nullTerminatedStringBegin, nullTerminatedStringEnd, std::back_inserter(c));
    }

private:
    const ara::core::String& str_;
};

template <>
class Serializer<ara::core::Byte>
{
public:
    using value_type = ara::core::Byte;

    Serializer(const value_type& value)
        : value_(value)
    { }

    template <typename Container>
    void pushbackTo(Container& c)
    {
        c.push_back(static_cast<std::uint8_t>(static_cast<unsigned char>(value_)));
    }

private:
    value_type value_;
};

template <typename First, typename Second>
class Serializer<std::pair<First, Second>>
{
public:
    using value_type = std::pair<First, Second>;

    Serializer(const value_type& value)
        : value_(value)
    { }

    template <typename Container>
    void pushbackTo(Container& c)
    {
        Serializer<typename std::decay<First>::type> first_serializer(value_.first);
        Serializer<typename std::decay<Second>::type> second_serializer(value_.second);
        first_serializer.pushbackTo(c);
        second_serializer.pushbackTo(c);
    }

private:
    const value_type& value_;
};

template <typename T, std::size_t N>
class Serializer<ara::core::Array<T, N>>
{
public:
    using value_type = ara::core::Array<T, N>;

    Serializer(const value_type& value)
        : value_(value)
    { }

    template <typename Container>
    void pushbackTo(Container& c)
    {
        for (std::size_t i = 0; i < N; ++i) {
            Serializer<T> serializer(value_[i]);
            serializer.pushbackTo(c);
        }
    }

private:
    const value_type& value_;
};

template <typename Sequence>
class SequenceContainerSerializer
{
public:
    using value_type = Sequence;

    SequenceContainerSerializer(const Sequence& container)
        : container_(container)
    { }

    template <typename TargetContainer>
    void pushbackTo(TargetContainer& c)
    {
        for (const typename Sequence::value_type& item : container_) {
            Serializer<typename Sequence::value_type> serializer(item);
            serializer.pushbackTo(c);
        }
    }

private:
    const Sequence& container_;  ///< Container to be serialized.
};

/// @uptrace{SWS_PER_00303, 1169080e8a2d20e9322073c0984069899f7f132f}
template <typename T>
class Serializer<ara::core::Vector<T>>
{
public:
    using value_type = ara::core::Vector<T>;

    Serializer(const value_type& value)
        : container_(value)
    { }

    template <typename Container>
    void pushbackTo(Container& c)
    {
        pushbackToHelper(c);
    }

private:
    const value_type& container_;

    template <typename Container, typename U = T>
    void pushbackToHelper(Container& c)
    {
        SequenceContainerSerializer<ara::core::Vector<T>> serializer(container_);
        serializer.pushbackTo(c);
    }
};

template <typename K, typename V, typename Compare, typename Allocator>
class Serializer<ara::core::Map<K, V, Compare, Allocator>>
    : public SequenceContainerSerializer<ara::core::Map<K, V, Compare, Allocator>>
{
public:
    using SequenceContainerSerializer<ara::core::Map<K, V, Compare, Allocator>>::SequenceContainerSerializer;
};

template <typename K, typename V, typename Hash, typename KeyEqual, typename Allocator>
class Serializer<std::unordered_map<K, V, Hash, KeyEqual, Allocator>>
    : public SequenceContainerSerializer<std::unordered_map<K, V, Hash, KeyEqual, Allocator>>
{
public:
    using SequenceContainerSerializer<std::unordered_map<K, V, Hash, KeyEqual, Allocator>>::SequenceContainerSerializer;
};

template <typename K, typename Compare, typename Allocator>
class Serializer<std::set<K, Compare, Allocator>> : public SequenceContainerSerializer<std::set<K, Compare, Allocator>>
{
public:
    using SequenceContainerSerializer<std::set<K, Compare, Allocator>>::SequenceContainerSerializer;
};

template <typename K, typename Hash, typename KeyEqual, typename Allocator>
class Serializer<std::unordered_set<K, Hash, KeyEqual, Allocator>>
    : public SequenceContainerSerializer<std::unordered_set<K, Hash, KeyEqual, Allocator>>
{
public:
    using SequenceContainerSerializer<std::unordered_set<K, Hash, KeyEqual, Allocator>>::SequenceContainerSerializer;
};

/* ------------------------------------------------------------------------------------------------------------------------------------------------
 */

template <typename T>
class Deserializer;

class DeserializingEnumerator
{
public:
    DeserializingEnumerator(const std::uint8_t* data, std::size_t size)
        : data_(data)
        , size_(size)
        , pos_(0)
    { }

    template <typename T>
    void operator()(T& value, std::uint32_t = 0)
    {
        Deserializer<T> deserializer(data_ + pos_, size_ - pos_);
        pos_ += deserializer.getSize();
        if (pos_ > size_) {
            throw std::runtime_error("Insufficient arguments from remote end");
        } else {
            value = deserializer.getValue();
        }
    }

private:
    const std::uint8_t* data_;  ///< Array to deserialize from.
    std::size_t size_;  ///< Size of the input array.
    std::size_t pos_;  ///< Current position at which the next deserialization will happen.
};

class SizeCounter
{
public:
    SizeCounter(const std::uint8_t* data, std::size_t buf_size)
        : buf_size_(buf_size)
        , data_(data)
    { }

    template <typename T>
    void operator()(const T&, std::uint32_t = 0)
    {
        Deserializer<T> deserializer(data_, buf_size_);
        std::size_t size = deserializer.getSize();
        size_ += size;
        data_ += size;
        buf_size_ -= size;
    }

    std::size_t GetSize() const
    {
        return size_;
    }

private:
    std::size_t size_{0};  ///< Size counter. Updated by the call operator.
    std::size_t buf_size_;  ///< Maximum buffer size.
    const std::uint8_t* data_;  ///< Array to use as input for the deserialization of the length information.
};

template <typename T>
class Deserializer
{
public:
    using value_type = typename std::decay<T>::type;
    using result_type = value_type;

    Deserializer(const std::uint8_t* data, std::size_t size)
        : data_(data)
        , size_(size)
    {
        static_assert(IsSerializable<value_type>(), "Unable to deserialize type!");
    }

    explicit Deserializer(const std::vector<std::uint8_t>& v)
        : Deserializer(v.data(), v.size())
    { }

    result_type getValue() const
    {
        return getValueHelper();
    }

    std::size_t getSize() const
    {
        return getSizeHelper();
    }

private:
    const std::uint8_t* data_;
    std::size_t size_;

    template <typename U = value_type, typename = EnableIfBaseType<U>>
    result_type getValueHelper() const
    {
        result_type result{};

        if (sizeof(value_type) > size_) {
            throw std::runtime_error("Deserialization of basetype failed, insufficient data!");
        }

        result = *reinterpret_cast<const value_type*>(data_);

        return result;
    }

    template <typename U = value_type>
    result_type getValueHelper(EnableIfEnumerableOrTlv<U>* = nullptr) const
    {
        result_type result;
        DeserializingEnumerator deserializer(data_, size_);

        result.enumerate(deserializer);
        return result;
    }

    template <typename U = value_type, typename = EnableIfBaseType<U>>
    std::size_t getSizeHelper() const
    {
        return sizeof(T);
    }

    template <typename U = value_type>
    std::size_t getSizeHelper(EnableIfEnumerableOrTlv<U>* = nullptr) const
    {
        SizeCounter size_counter(data_, size_);
        value_type* x = nullptr;
        x->enumerate(size_counter);
        return size_counter.GetSize();
    }
};

template <typename T>
class Deserializer<ara::core::Optional<T>>
{
public:
    using result_type = ara::core::Optional<T>;
    using content_type = T;

    Deserializer(const std::uint8_t* data, std::size_t size)
        : data_(data)
        , size_(size)
    {
        static_assert(IsSerializable<content_type>(), "Unable to deserialize type!");
    }

    explicit Deserializer(const std::vector<std::uint8_t>& v)
        : Deserializer(v.data(), v.size())
    { }

    result_type getValue() const
    {
        result_type result{ara::core::nullopt};
        auto present = Deserializer<bool>(data_, sizeof(bool)).getValue();
        if (present) {
            result = Deserializer<content_type>(data_ + sizeof(bool), size_ - sizeof(bool)).getValue();
        }
        return result;
    }

    std::size_t getSize() const
    {
        auto result = Deserializer<content_type>(data_ + sizeof(bool), size_ - sizeof(bool)).getSize();
        return result + sizeof(bool);
    }

private:
    const std::uint8_t* data_;
    const std::size_t size_;
};

template <>
class Deserializer<ara::core::String>
{
public:
    using result_type = ara::core::String;
    using char_type = ara::core::String::value_type;

    Deserializer(const std::uint8_t* data, std::size_t size)
        : data_(data)
        , len_(0)
    {
        if (size < sizeof(char_type)) {  // at least '\0' must be always present
            throw std::runtime_error("Deserialization of ara::core::String failed, insufficient data.");
        }

        for (; len_ < size / sizeof(char_type) - 1 && data[len_]; ++len_)
            ;
    }

    explicit Deserializer(const std::vector<std::uint8_t>& v)
        : Deserializer(v.data(), v.size())
    { }

    result_type getValue() const
    {
        const char_type* c = reinterpret_cast<const char_type*>(data_);
        return {c, len_};
    }

    std::size_t getSize() const
    {
        return (len_ + 1) * sizeof(char_type);
    }

private:
    const std::uint8_t* data_;
    std::size_t len_;
};

template <>
class Deserializer<ara::core::Byte>
{
public:
    using result_type = ara::core::Byte;

    Deserializer(const std::uint8_t* data, std::size_t size)
        : data_(data)
    {
        if (size < 1) {
            throw std::runtime_error("Deserialization of ara::core::Byte failed, insufficient data.");
        }
    }

    explicit Deserializer(const std::vector<std::uint8_t>& v)
        : Deserializer(v.data(), v.size())
    { }

    result_type getValue() const
    {
        return result_type(static_cast<unsigned char>(data_[0]));
    }

    std::size_t getSize() const
    {
        return 1;
    }

private:
    const std::uint8_t* data_;
    std::size_t len_;
};

template <typename Sequence>
class SequenceContainerDeserializer
{
public:
    using result_type = Sequence;

    SequenceContainerDeserializer(const std::uint8_t* data, std::size_t size, std::size_t len)
        : data_(data)
        , size_(size)
        , len_(len)
    { }

    result_type getValue() const
    {
        result_type result{};

        const std::uint8_t* current_pos = data_;
        const std::uint8_t* end_pos = current_pos + len_;
        std::size_t remaining_size = size_;
        for (; current_pos < end_pos;) {
            Deserializer<typename Sequence::value_type> item_deserializer(current_pos, remaining_size);
            result.push_back(item_deserializer.getValue());

            std::size_t s = item_deserializer.getSize();
            if (remaining_size >= s) {
                current_pos += s;
                remaining_size -= s;
            } else {
                throw std::runtime_error("Deserialization of sequence container failed, insufficient data.");
            }
        }

        return result;
    }

    std::size_t getSize() const
    {
        return len_;
    }

private:
    const std::uint8_t* data_;
    std::size_t size_;
    std::size_t len_;
};

template <typename T>
class Deserializer<ara::core::Vector<T>>
{
public:
    using result_type = ara::core::Vector<T>;

    Deserializer(const std::uint8_t* data, std::size_t size)
        : data_(data)
        , size_(size)
        , len_(size)
    { }

    explicit Deserializer(const std::vector<std::uint8_t>& v)
        : Deserializer(v.data(), v.size())
    { }

    result_type getValue() const
    {
        return getValueHelper();
    }

    std::size_t getSize() const
    {
        return getSizeHelper();
    }

private:
    const std::uint8_t* data_;
    std::size_t size_;
    std::size_t len_;

    result_type getValueHelper(void) const
    {
        return SequenceContainerDeserializer<ara::core::Vector<T>>(data_, size_, len_).getValue();
    }

    std::size_t getSizeHelper(void) const
    {
        return SequenceContainerDeserializer<ara::core::Vector<T>>(data_, size_, len_).getSize();
    }
};

template <typename T, std::size_t N>
class Deserializer<ara::core::Array<T, N>>
{
public:
    using result_type = ara::core::Array<T, N>;

    Deserializer(const std::uint8_t* data, std::size_t size)
        : data_(data)
        , size_(size)
    { }

    explicit Deserializer(const std::vector<std::uint8_t>& v)
        : Deserializer(v.data(), v.size())
    { }

    result_type getValue() const
    {
        result_type result{};

        std::size_t pos = 0;
        for (std::size_t i = 0; i < N; ++i) {
            Deserializer<T> deserializer(data_ + pos, size_ - pos);
            result[i] = deserializer.getValue();
            pos += deserializer.getSize();
        }

        return result;
    }

    std::size_t getSize() const
    {
        std::size_t pos = 0;
        for (std::size_t i = 0; i < N; ++i) {
            Deserializer<T> deserializer(data_ + pos, size_ - pos);
            pos += deserializer.getSize();
        }

        return pos;
    }

private:
    const std::uint8_t* data_;
    std::size_t size_;
};

template <typename First, typename Second>
class Deserializer<std::pair<First, Second>>
{
public:
    using result_type = std::pair<First, Second>;

    Deserializer(const std::uint8_t* data, std::size_t size)
        : data_(data)
        , size_(size)
    { }

    explicit Deserializer(const std::vector<std::uint8_t>& v)
        : Deserializer(v.data(), v.size())
    { }

    result_type getValue() const
    {
        Deserializer<typename std::decay<First>::type> first_deserializer(data_, size_);
        std::size_t first_size = first_deserializer.getSize();
        if (first_size < size_) {
            Deserializer<typename std::decay<Second>::type> second_deserializer(data_ + first_size, size_ - first_size);
            return result_type(first_deserializer.getValue(), second_deserializer.getValue());
        } else {
            throw std::runtime_error("Deserialization of pair failed, insufficient data.");
        }
    }

    std::size_t getSize() const
    {
        Deserializer<typename std::decay<First>::type> first_deserializer(data_, size_);
        std::size_t first_size = first_deserializer.getSize();
        if (first_size < size_) {
            Deserializer<typename std::decay<Second>::type> second_deserializer(data_ + first_size, size_ - first_size);
            return first_size + second_deserializer.getSize();
        } else {
            throw std::runtime_error("Deserialization of pair failed, insufficient data.");
        }
    }

private:
    const std::uint8_t* data_;
    std::size_t size_;
};

template <typename AssociativeContainer>
class AssociativeContainerDeserializer
{
public:
    using result_type = AssociativeContainer;

    AssociativeContainerDeserializer(const std::uint8_t* data, std::size_t size)
        : data_(data)
        , size_(size)
        , len_(size)
    { }

    result_type getValue() const
    {
        result_type result{};

        const std::uint8_t* pos = data_;
        const std::uint8_t* end_pos = data_ + len_;
        std::size_t remaining = size_;

        for (; pos < end_pos;) {
            Deserializer<typename AssociativeContainer::value_type> key_deserializer(pos, remaining);
            result.insert(key_deserializer.getValue());

            std::size_t size_entry = key_deserializer.getSize();
            if (remaining >= size_entry) {
                pos += size_entry;
                remaining -= size_entry;
            } else {
                throw std::runtime_error("Deserialization of sequence container failed, insufficient data.");
            }
        }

        return result;
    }

    std::size_t getSize() const
    {
        return len_;
    }

private:
    const std::uint8_t* data_;  ///< Pointer to the first data item.
    std::size_t size_;  ///< Maximum length of the array.
    std::size_t len_;  ///< Number of items within the container.
};

template <typename K, typename V, typename Compare, typename Allocator>
class Deserializer<ara::core::Map<K, V, Compare, Allocator>>
    : public AssociativeContainerDeserializer<ara::core::Map<K, V, Compare, Allocator>>
{
public:
    using AssociativeContainerDeserializer<ara::core::Map<K, V, Compare, Allocator>>::AssociativeContainerDeserializer;
};

template <typename K, typename V, typename Hash, typename KeyEqual, typename Allocator>
class Deserializer<std::unordered_map<K, V, Hash, KeyEqual, Allocator>>
    : public AssociativeContainerDeserializer<std::unordered_map<K, V, Hash, KeyEqual, Allocator>>
{
public:
    using AssociativeContainerDeserializer<
        std::unordered_map<K, V, Hash, KeyEqual, Allocator>>::AssociativeContainerDeserializer;
};

template <typename K, typename Compare, typename Allocator>
class Deserializer<std::set<K, Compare, Allocator>>
    : public AssociativeContainerDeserializer<std::set<K, Compare, Allocator>>
{
public:
    using AssociativeContainerDeserializer<std::set<K, Compare, Allocator>>::AssociativeContainerDeserializer;
};

template <typename K, typename Hash, typename KeyEqual, typename Allocator>
class Deserializer<std::unordered_set<K, Hash, KeyEqual, Allocator>>
    : public AssociativeContainerDeserializer<std::unordered_set<K, Hash, KeyEqual, Allocator>>
{
public:
    using AssociativeContainerDeserializer<
        std::unordered_set<K, Hash, KeyEqual, Allocator>>::AssociativeContainerDeserializer;
};

}  // namespace serialization
}  // namespace per
}  // namespace ara

#endif  // ARA_PER_SERIALIZER_H
