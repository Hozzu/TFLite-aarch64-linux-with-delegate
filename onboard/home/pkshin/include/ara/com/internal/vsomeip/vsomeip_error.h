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

/**
 * \file
 * \brief vsomeip error utilities
 */

#ifndef ARA_VSOMEIP_BINDING_INCLUDES_LIBARA_INTERNAL_COMMON_VSOMEIP_ERROR_H_
#define ARA_VSOMEIP_BINDING_INCLUDES_LIBARA_INTERNAL_COMMON_VSOMEIP_ERROR_H_

#include "ara/com/types.h"
#include "ara/com/exception.h"
#include "vsomeip_types.h"
#include "vsomeip_marshalling.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace vsomeip
{
namespace common
{
namespace error
{

/**
 *  \defgroup vsomeiperror VSOMEIP application errors
 *
 *  \brief Common error functionality used by both the VSOMEIP proxy and the skeleton implementations.
 *
 *  @{
 */

/**
 * \brief Enumerator for iterating over error fields.
 */
class Enumerator
{
    ara::core::Vector<::vsomeip::byte_t>& dst_;

public:
    /**
     * \brief Construct Enumerator for given destination.
     *
     * \param dst Destination to data to.
     */
    Enumerator(ara::core::Vector<::vsomeip::byte_t>& dst)
        : dst_(dst)
    { }

    template <typename T>
    void operator()(const T& value)
    {
        ara::com::internal::vsomeip::common::Serializer<T> serializer(value);
        serializer.pushbackTo(dst_);
    }
};

using SerializeFunction
    = std::function<void(const ara::com::ApplicationErrorException& error, ara::core::Vector<::vsomeip::byte_t>& dst)>;
using DeserializeFunction = std::function<std::exception_ptr(::vsomeip::payload& payload)>;

/**
 * \brief Error factory.
 */
class Factory
{
public:
    static ara::core::Map<ara::core::String, SerializeFunction> serializationFunctions;
    static ara::core::Map<std::uint8_t, DeserializeFunction> deserializationFunctions;

    /**
     * \brief Register serialization function for a given error.
     *
     * \param error Error to register serialization function for.
     * \param serialize Serialization function.
     */
    static void registerSerializationFoo(
        // const ara::com::ApplicationErrorException& error,
        const ara::core::String& errorTypeName,
        SerializeFunction serialize);

    /**
     * \brief Register deserialization function for a given error code.
     *
     * \param errorCode Error code to register deserialization functon for.
     * \param deserialize Deserialization function.
     */
    static void registerDeserializationFoo(std::uint8_t errorCode, DeserializeFunction deserialize);

    /**
     * \brief Serialize a given error into dst.
     *
     * \param error Error to serialize.
     * \param dst Destination to serialize the error to.
     */
    static void serialize(const ara::com::ApplicationErrorException& error, ara::core::Vector<::vsomeip::byte_t>& dst);

    /**
     * \brief Create(deserialize) an error from a given payload.
     *
     * \param errorCode Error code to deserialize.
     * \param payload Data source to deserialize from.
     * \return An error for given errorCode.
     */
    static std::exception_ptr deserialize(std::uint8_t errorCode, ::vsomeip::payload& payload);
};

template <typename Error>
class ErrorEntry
{
public:
    ErrorEntry(std::uint8_t errorCode, SerializeFunction serialize, DeserializeFunction deserialize)
    {
        Factory::registerSerializationFoo(typeid(Error).name(), serialize);
        Factory::registerDeserializationFoo(errorCode, deserialize);
    }
};

/** @}*/
}  // namespace error
}  // namespace common
}  // namespace vsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_VSOMEIP_BINDING_INCLUDES_LIBARA_INTERNAL_COMMON_VSOMEIP_ERROR_H_
