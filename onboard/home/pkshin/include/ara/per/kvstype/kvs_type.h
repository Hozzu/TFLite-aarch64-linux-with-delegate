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

#ifndef ARA_PER_KVSTYPE_KVS_TYPE_H_
#define ARA_PER_KVSTYPE_KVS_TYPE_H_

#include <iostream>
#include <memory>
#include <type_traits>
#include <utility>
#include <vector>

#include "ara/core/result.h"
#include "ara/core/string.h"
#include "ara/core/string_view.h"
#include "ara/core/vector.h"

namespace ara
{
namespace per
{
namespace kvstype
{

/// @brief A container class for storing any of the POD types, plus some additional complex types.
class KvsType
{
public:
    /// @brief Status of the KVS access.
    enum class Status : std::uint8_t
    {
        kSuccess = 0,  ///< kSuccess, indicates that the value was successfully restored from the KVS-storage.
        kNotFound,  ///< kNotfound, requested key was not found
        kIntegrityCorrupted,  ///< kIntegrityCorrupted, the key-value pair was found, but the checksum of it is
                              ///< incorrect.
        kGeneralError  ///< kGeneralError, any other failure.
    };

    /// @brief Supported types.
    ///
    /// @uptrace{SWS_PER_00302, 5096fdb50aa8fd4c32814055d3eb3ffb8bf818ab}
    enum class Type : std::uint8_t
    {
        kNotSupported = 0,
        kFloat,
        kDouble,
        kSInt8,
        kSInt16,
        kSInt32,
        kSInt64,
        kUInt8,
        kUInt16,
        kUInt32,
        kUInt64,
        kString,
        kBinary,
        kBoolean,
        kObject,
        kNotSet
    };

    /// @brief Copy constructor.
    ///
    /// @param src the source KvsType object that shall be copied
    KvsType(const KvsType& src) noexcept;

    /// @brief Copy assignment operator.
    ///
    /// @param src the source KvsType object that shall be copied
    /// @returns a copy of given KvsType object
    KvsType& operator=(const KvsType& src) noexcept;

    /// @brief Move constructor.
    KvsType(KvsType&&) noexcept;

    /// @brief Move assignment operator.
    ///
    /// @returns the moved-to object
    KvsType& operator=(KvsType&&) noexcept;

    /// @brief Destructor.
    virtual ~KvsType() noexcept;

    /// @brief Basic constructor which creates a "not found"-state object.
    KvsType() noexcept;

    // ####################################
    // # Constructors for supported types #
    // ####################################

    /// @brief Constructor for bool.
    ///
    /// @param value the initial bool value
    KvsType(bool value) noexcept;

    /// @brief Constructor for 8-bit signed integer.
    ///
    /// @param value the initial std::int8_t value
    KvsType(std::int8_t value) noexcept;

    /// @brief Constructor for 16-bit signed integer.
    ///
    /// @param value the initial std::int16_t value
    KvsType(std::int16_t value) noexcept;

    /// @brief Constructor for 32-bit signed integer.
    ///
    /// @param value the initial std::int32_t value
    KvsType(std::int32_t value) noexcept;

    /// @brief Constructor for 64-bit signed integer.
    ///
    /// @param value the initial std::int64_t value
    KvsType(std::int64_t value) noexcept;

    /// @brief Constructor for 8-bit unsigned integer.
    ///
    /// @param value the initial std::uint8_t value
    KvsType(std::uint8_t value) noexcept;

    /// @brief Constructor for 16-bit unsigned integer.
    ///
    /// @param value the initial std::uint16_t value
    KvsType(std::uint16_t value) noexcept;

    /// @brief Constructor for 32-bit unsigned integer.
    ///
    /// @param value the initial std::uint32_t value
    KvsType(std::uint32_t value) noexcept;

    /// @brief Constructor for 64-bit unsigned integer.
    ///
    /// @param value the initial std::uint64_t value
    KvsType(std::uint64_t value) noexcept;

    /// @brief Constructor for float.
    ///
    /// @param value the initial float value
    KvsType(float value) noexcept;

    /// @brief Constructor for double.
    ///
    /// @param value the initial double value
    KvsType(double value) noexcept;

    /// @brief Constructor for ara::core::String.
    ///
    /// @param value the initial string value
    KvsType(const ara::core::String& value) noexcept;

    /// @brief Constructor for const char*.
    ///
    /// @param value the initial char value
    KvsType(const char* value) noexcept;

    /// @brief Generic constructor for any POD-type.
    ///
    /// @param data the address of the the data to be stored
    /// @param len the lenght of the data to be stored
    ///
    /// @deprecated Usage of this is not safe an not recommended!
    /// As there are some users for this type, this is still here.
    KvsType(void* data, std::size_t len) noexcept;

    /// @brief Accesses the internal presentation as a boolean
    ///
    /// @throws std::logic_error is thrown if the requested conversion is not supported
    /// @returns the internal presentation as a boolean
    ara::core::Result<bool> GetBool() const noexcept;

    /// @brief Accesses the internal presentation as integer.
    ///
    /// @throws std::logic_error is thrown if the requested conversion is not supported
    /// @returns the internal presentation as integer
    ara::core::Result<std::int32_t> GetSInt() const noexcept;

    /// @brief Accesses the internal presentation as 64-bit integer.
    ///
    /// @throws std::logic_error is thrown if the requested conversion is not supported
    /// @returns the internal presentation as 64-bit integer
    ara::core::Result<std::int64_t> GetSInt64() const noexcept;

    /// @brief Accesses the internal presentation as unsigned integer.
    ///
    /// @throws std::logic_error is thrown if the requested conversion is not supported
    /// @returns the internal presentation as unsigned integer
    ara::core::Result<std::uint32_t> GetUInt() const noexcept;

    /// @brief Accesses the internal presentation as 64-bit unsigned integer.
    ///
    /// @throws std::logic_error is thrown if the requested conversion is not supported
    /// @returns the internal presentation as 64-bit unsigned integer
    ara::core::Result<std::uint64_t> GetUInt64() const noexcept;

    /// @brief Accesses the internal presentation as float.
    ///
    /// @throws std::logic_error is thrown if the requested conversion is not supported
    /// @returns the internal presentation as float
    ara::core::Result<float> GetFloat() const noexcept;

    /// @brief Accesses the internal presentation as double.
    ///
    /// @throws std::logic_error is thrown if the requested conversion is not supported
    /// @returns the internal presentation as double
    ara::core::Result<double> GetDouble() const noexcept;

    /// @brief Accesses the internal presentation as string.
    ///
    /// @throws std::logic_error is thrown if the requested conversion is not supported
    /// @returns the internal presentation as string
    ara::core::Result<ara::core::String> GetString() const noexcept;

    /// @brief Restores the stored value to the given memory address.
    ///
    /// Usage example:
    ///
    /// @code
    /// struct MyStructureWithPodData { .... };
    /// KeyValueStorage db("databasename.json");
    ///
    /// MyStructureWithPodData mystruct;
    ///
    /// KvsType binary = db.getValue("my-binary-key");
    /// binary.GetBinary(&mystruct, sizeof(mystruct));
    /// // Error handling missing from the example.
    /// @endcode
    ///
    /// @param data Pointer to the memory, where the data is to be restored to.
    /// @param len number of bytes to be restored.
    /// @throws std::logic_error is thrown if the requested conversion is not supported.
    ara::core::Result<void> GetBinary(void* data, std::size_t len) const noexcept;

    /// @brief Returns a vector of requested type.
    ///
    /// Supported types are [integral, floating point, ara::core::String and KVSType].
    /// Restores the items in same order as they were saved with StoreArray
    /// This is specialized for integer types and booleans.
    ///
    /// @tparam T the expected underlying type of the array to be returned
    /// @returns a vector of the requested type
    /// @throws std::logic_error is thrown if the requested conversion is not supported.
    /// @throws ara::per::physical_storage_error is thrown if internal memory allocation fails.
    template <class T, typename std::enable_if<std::is_integral<T>::value, T>::type* = nullptr>
    ara::core::Result<ara::core::Vector<T>> GetArray() noexcept
    {
        using my_result_t = ara::core::Result<ara::core::Vector<T>>;

        ara::core::Vector<T> return_vector;
        ResetArrayItemGetter();

        for (std::size_t i = 0; i < this->GetNumberOfArrayItems(); i++) {
            auto next = this->GetNextArrayItem();
            if (!next) {
                return my_result_t::FromError(next.Error());
            }

            if (std::is_signed<T>::value) {
                auto value = next.Value().GetSInt64();
                if (!value) {
                    return my_result_t::FromError(value.Error());
                }
                return_vector.push_back(static_cast<T>(value.Value()));
            } else if (std::is_same<T, bool>::value) {
                auto value = next.Value().GetBool();
                if (!value) {
                    return my_result_t::FromError(value.Error());
                }
                return_vector.push_back(static_cast<T>(value.Value()));
            } else {
                auto value = next.Value().GetUInt64();
                if (!value) {
                    return my_result_t::FromError(value.Error());
                }
                return_vector.push_back(static_cast<T>(value.Value()));
            }
        }

        return my_result_t::FromValue(std::move(return_vector));
    }

    /// @brief GetArray() specialized for floating point types.
    template <class T, typename std::enable_if<std::is_floating_point<T>::value, T>::type* = nullptr>
    ara::core::Result<ara::core::Vector<T>> GetArray() noexcept
    {
        using my_result_t = ara::core::Result<ara::core::Vector<T>>;

        ara::core::Vector<T> return_vector;
        ResetArrayItemGetter();
        for (std::size_t i = 0; i < this->GetNumberOfArrayItems(); i++) {
            auto next = this->GetNextArrayItem();
            if (!next) {
                return my_result_t::FromError(next.Error());
            }

            auto value = next.Value().GetDouble();
            if (!value) {
                return my_result_t::FromError(value.Error());
            }

            return_vector.push_back(static_cast<T>(value.Value()));
        }

        return my_result_t::FromValue(std::move(return_vector));
    }

    /// @brief GetArray() specialized for KvsType.
    template <class T, typename std::enable_if<std::is_same<T, KvsType>::value, T>::type* = nullptr>
    ara::core::Result<ara::core::Vector<T>> GetArray() noexcept
    {
        using my_result_t = ara::core::Result<ara::core::Vector<T>>;

        ara::core::Vector<T> return_vector;
        ResetArrayItemGetter();
        for (std::size_t i = 0; i < this->GetNumberOfArrayItems(); i++) {
            auto next = this->GetNextArrayItem();
            if (!next) {
                return my_result_t::FromError(next.Error());
            }
            return_vector.push_back(next.Value());
        }

        return my_result_t::FromValue(std::move(return_vector));
    }

    /// @brief GetArray() specialized for ara::core::String.
    template <class T, typename std::enable_if<std::is_same<T, ara::core::String>::value, T>::type* = nullptr>
    ara::core::Result<ara::core::Vector<T>> GetArray() noexcept
    {
        using my_result_t = ara::core::Result<ara::core::Vector<T>>;

        ara::core::Vector<T> return_vector;
        ResetArrayItemGetter();
        for (std::size_t i = 0; i < this->GetNumberOfArrayItems(); i++) {
            auto next = this->GetNextArrayItem();
            if (!next) {
                return my_result_t::FromError(next.Error());
            }
            auto value = next.Value().GetString();
            if (!value) {
                my_result_t::FromError(next.Error());
            }
            return_vector.push_back(std::move(value.Value()));
        }

        return my_result_t::FromValue(std::move(return_vector));
    }

    /// @brief Adds an element to the internal array container.
    ///
    /// @param kvs the element to be added
    ara::core::Result<void> AddArrayItem(const KvsType& kvs) noexcept;

    /// @brief Accesses the key of the KVS-pair object.
    ///
    /// @returns the key of the KVS-pair object
    ara::core::String GetKey() const noexcept;

    /// @brief Accesses the status of the KVS-pair object.
    ///
    /// @returns the status of the KVS-pair object
    /// @note The status should be checked before trying to use the stored KVS-pair.
    Status GetStatus() const noexcept;

    /// @brief Accesses the type of the value stored to the internal presentation.
    ///
    /// @returns the type of the value stored to the internal presentation
    Type GetType() const noexcept;

    /// @brief Convenience function for checking if the internal type is any of
    /// the signed integer types.
    ///
    /// @returns whether the internal type is a signed integer
    /// @note Types might be 8,16,32, or 64bit.
    bool IsSignedInteger() const noexcept;

    /// @brief Convenience function for checking if the internal type is any of
    /// the unsigned integer types.
    ///
    /// @returns whether the internal type is an unsigned integer
    /// @note Types might be 8,16,32, or 64bit.
    bool IsUnsignedInteger() const noexcept;

    /// @brief Logs the internal variables of the object.
    ///
    /// This is useful only for debugging the KVSType.
    ///
    /// @note The ara::log log level must be set to kDebug for this to be visible in the logs.
    void LogState() const noexcept;

    /// @brief Sets the key of the KVS-pair object.
    ///
    /// @param name the key to be used for the KVS-pair object
    void SetKey(const ara::core::String& name) noexcept;

    /// @brief Stores an array of [integer, floating point, or KvsType].
    ///
    /// The elements are stored in the iteration order to the KVS internal data structure.
    ///
    /// @tparam Array the underlying type of the array to be stored
    /// @param array the actual Array that is to be stored
    /// @throws std::logic_error is thrown if the requested conversion is not supported.
    /// @throws ara::per::physical_storage_error is thrown if internal memory allocation fails.
    /// @note The container must be iterable!
    template <class Array>
    ara::core::Result<void> StoreArray(const Array& array) noexcept
    {
        static_assert((std::is_integral<typename Array::value_type>::value)
                || (std::is_floating_point<typename Array::value_type>::value)
                || (std::is_same<typename Array::value_type, ara::core::String>::value)
                || (std::is_same<typename Array::value_type, KvsType>::value),
            "Storing of array template supports only iterable containers, which contain  "
            "one of fundamental types (int,float, etc.) or ara::core::Strings or KvsType-objects");

        auto current = array.cbegin();
        auto end = array.cend();

        std::size_t counter = 0;
        while (current != end) {
            // If already have an iterable container of KvsType objects, just
            // pass them.
            if (std::is_same<typename Array::value_type, KvsType>::value) {
                auto added = this->AddArrayItem(*current);
                if (!added) {
                    return ara::core::Result<void>::FromError(added.Error());
                }
            } else {
                // Otherwise, construct KVSType-object from the value
                KvsType temp(*current);
                // unfortunately this is necessary for successful validation against schema
                temp.SetKey(std::to_string(counter++));
                // Add it to the internal presentation
                auto added = this->AddArrayItem(temp);
                if (!added) {
                    return ara::core::Result<void>::FromError(added.Error());
                }
            }
            current++;
        }

        return ara::core::Result<void>::FromValue();
    }

    /// @brief Constructs a KVSObject from a string.
    ///
    /// This is implementation specific.
    /// For the demonstrator, the  example chosen is JSON.
    ///
    /// @param kvsStrObj the string representation of a KvsType
    /// @returns the deserialized KvsType
    /// @throws std::logic_error is thrown if the KVSType cannot be constructed from the input.
    static ara::core::Result<KvsType> DeSerializeKvsData(const ara::core::String& kvsStrObj) noexcept;

    /// @brief Serializes a KVSObject to a string.
    ///
    /// This is implementation specific.
    /// For the demonstrator, the  example chosen is JSON.
    ///
    /// @returns the string representation of this object.
    ara::core::Result<ara::core::String> SerializeKvsData() const noexcept;

private:
    /// @brief Application specific implementation.
    class Impl;

    /// @brief Pointer to the actual implementation.
    std::unique_ptr<Impl> implPtr_;

    /// @brief Implementation specific serialization helper class.
    ///
    /// The actual serialization support depends on the internal implementation
    /// of Impl-class.
    friend class InternalAccess;

    /// @brief Accesses the next item in the array.
    ///
    /// @returns the next item in the array
    ara::core::Result<KvsType> GetNextArrayItem() noexcept;

    /// @brief Accesses the number of items currently stored.
    ///
    /// @returns the number of items currently stored
    std::size_t GetNumberOfArrayItems() const noexcept;

    /// @brief Resets the kvs array getter.
    ///
    /// The next value will be the first in the internal data structure
    void ResetArrayItemGetter() noexcept;
};

template <typename... Args>
KvsType CreateKvsType(ara::core::StringView key, Args&&... args)
{
    KvsType result(std::forward<Args>(args)...);
    result.SetKey(ara::core::String(key));
    return result;
}

bool operator==(const KvsType& l, const KvsType& r) noexcept;

}  // namespace kvstype
}  // namespace per
}  // namespace ara

#endif  // ARA_PER_KVSTYPE_KVS_TYPE_H_
