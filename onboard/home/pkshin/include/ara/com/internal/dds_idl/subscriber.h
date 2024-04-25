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

#ifndef ARA_COM_INTERNAL_DDS_IDL_SUBSCRIBER_H_
#define ARA_COM_INTERNAL_DDS_IDL_SUBSCRIBER_H_

#include <memory>

#include "ara/core/map.h"
#include "ara/core/string.h"
#include "ara/core/optional.h"
#include "ara/com/types.h"
#include "ara/com/internal/dds_idl/shared_registry.h"
#include "ara/com/internal/dds_idl/types.h"
#include "ara/com/internal/dds_idl/topic.h"
#include "ara/com/internal/dds_idl/event_data_reader.h"
#include "ara/com/internal/dds_idl/method_data_reader.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace dds
{

class Subscriber
{
public:
    using Deleter = std::function<void(::DDS::Subscriber_ptr)>;

    /// @brief Constructor
    ///
    /// @param subscriber DDS Subscriber variable
    /// @param deleter Deleter for DDS Subscriber variable
    Subscriber(::DDS::Subscriber_var subscriber, Deleter deleter);
    ~Subscriber();

    /// @brief Get DataReader
    ///
    /// @param topic Topic
    /// @return DataReader
    ///
    /// @uptrace{SWS_CM_11003, cea0644db853e28cd6c794842d816e2cdac63fad}
    /// @uptrace{SWS_CM_11029, 1cf92d267e656deefc6d06777a1e5469f3ace869}
    /// @uptrace{SWS_CM_11030, bc97e2020f54303315c9f5366c7475b8ebbfa653}
    /// @uptrace{SWS_CM_11031, 88dc48d361a716ef56de9f71332a8257d5158b40}
    template <typename T>
    std::shared_ptr<EventDataReader<T>> GetEventDataReader(std::shared_ptr<TypedTopic<T>> topic,
        ara::core::StringView qosProfile,
        ara::core::Optional<std::size_t> maxSampleCount);

    template <typename T>
    std::shared_ptr<MethodDataReader<T>> GetMethodDataReader(std::shared_ptr<TypedTopic<T>> topic,
        ara::core::StringView qosProfile);

private:
    template <typename DataReaderType>
    std::shared_ptr<DataReaderType> CreateDataReader(
        std::shared_ptr<TypedTopic<typename DataReaderType::ValueType>> topic,
        ara::core::StringView qosProfile,
        ara::core::Optional<std::size_t> maxSampleCount);

    ::DDS::Subscriber_var subscriber_;
    Deleter deleter_;
    WeakRegistry<TopicInfo, DataReaderBase> readers_;
};

template <typename T>
std::shared_ptr<EventDataReader<T>> Subscriber::GetEventDataReader(std::shared_ptr<TypedTopic<T>> topic,
    ara::core::StringView qosProfile,
    ara::core::Optional<std::size_t> maxSampleCount)
{
    if (!topic) {
        common::logger().LogError() << "Subscriber::GetEventDataReader(): input topic is nil";
        return nullptr;
    }

    auto reader = readers_.Get(topic->GetInfo(), [this, topic, qosProfile, maxSampleCount]() {
        return CreateDataReader<EventDataReader<T>>(topic, qosProfile, maxSampleCount);
    });

    return std::dynamic_pointer_cast<EventDataReader<T>>(reader);
}

template <typename T>
std::shared_ptr<MethodDataReader<T>> Subscriber::GetMethodDataReader(std::shared_ptr<TypedTopic<T>> topic,
    ara::core::StringView qosProfile)
{
    if (!topic) {
        common::logger().LogError() << "Subscriber::GetMethodDataReader(): input topic is nil";
        return nullptr;
    }

    auto reader = readers_.Get(topic->GetInfo(),
        [this, topic, qosProfile]() { return CreateDataReader<MethodDataReader<T>>(topic, qosProfile, {}); });

    return std::dynamic_pointer_cast<MethodDataReader<T>>(reader);
}

/// @brief create data reader object
///
/// @tparam T data type of topic and future reader
/// @param topic pointer to a target topic to create reader for
/// @param qosProfile string with QoS profile to use
/// @returns pointer to a newly created DataReader<T> object
///
/// @uptrace{SWS_CM_11019, 5d377bd8ec9f9c428df6d19ea3b9f60630cf911c}
template <typename DataReaderType>
std::shared_ptr<DataReaderType> Subscriber::CreateDataReader(
    std::shared_ptr<TypedTopic<typename DataReaderType::ValueType>> topic,
    ara::core::StringView qosProfile,
    ara::core::Optional<std::size_t> maxSampleCount)
{
    // For current realization, the only allowed qos profile is "default". Feel free to change profile processing if you
    // need this
    if (qosProfile != "default") {
        common::logger().LogError() << "Subscriber::CreateDataReader(): QoS string is not an expected one";
        return nullptr;
    }

    DDS::DataReaderQos dataReaderQos;
    subscriber_->get_default_datareader_qos(dataReaderQos);
    dataReaderQos.history.kind = ::DDS::HistoryQosPolicyKind::KEEP_LAST_HISTORY_QOS;
    // Use provided or default history depth
    dataReaderQos.history.depth = maxSampleCount.value_or(dataReaderQos.history.depth);

    dataReaderQos.durability.kind = ::DDS::TRANSIENT_LOCAL_DURABILITY_QOS;
    dataReaderQos.reliability.kind = ::DDS::RELIABLE_RELIABILITY_QOS;

    ::DDS::DataReader_ptr reader = subscriber_->create_datareader(
        topic->Get(), dataReaderQos, DDS::DataReaderListener::_nil(), ::OpenDDS::DCPS::NO_STATUS_MASK);
    if (CORBA::is_nil(reader)) {
        common::logger().LogError() << "Subscriber::CreateDataReader(): created reader is nil";
        return nullptr;
    }

    return std::make_shared<DataReaderType>(reader, topic);
}

}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_INTERNAL_DDS_IDL_SUBSCRIBER_H_
