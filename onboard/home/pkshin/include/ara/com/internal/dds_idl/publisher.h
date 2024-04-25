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

#ifndef ARA_COM_INTERNAL_DDS_IDL_PUBLISHER_H_
#define ARA_COM_INTERNAL_DDS_IDL_PUBLISHER_H_

#include <memory>

#include "ara/core/map.h"
#include "ara/core/string.h"
#include "ara/com/types.h"
#include "ara/com/internal/dds_idl/types.h"
#include "ara/com/internal/dds_idl/topic.h"
#include "ara/com/internal/dds_idl/data_writer.h"
#include "ara/com/internal/dds_idl/shared_registry.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace dds
{

class Publisher
{
public:
    using Deleter = std::function<void(::DDS::Publisher_ptr)>;

    /// @brief Constructor
    ///
    /// @param publisher DDS Publisher variable
    /// @param deleter Deleter for DDS Publisher variable
    Publisher(::DDS::Publisher_var publisher, Deleter deleter);
    ~Publisher();

    /// @brief Get DataWriter
    ///
    /// @param topic Topic
    /// @return DataWritter
    ///
    /// @uptrace{SWS_CM_11003, cea0644db853e28cd6c794842d816e2cdac63fad}
    /// @uptrace{SWS_CM_11029, 1cf92d267e656deefc6d06777a1e5469f3ace869}
    /// @uptrace{SWS_CM_11030, bc97e2020f54303315c9f5366c7475b8ebbfa653}
    /// @uptrace{SWS_CM_11031, 88dc48d361a716ef56de9f71332a8257d5158b40}
    template <typename T>
    std::shared_ptr<DataWriter<T>> GetDataWriter(std::shared_ptr<TypedTopic<T>> topic,
        ara::core::StringView qosProfile);

private:
    template <typename T>
    std::shared_ptr<DataWriter<T>> CreateDataWriter(std::shared_ptr<TypedTopic<T>> topic,
        ara::core::StringView qosProfile);

    ::DDS::Publisher_var publisher_;
    Deleter deleter_;
    WeakRegistry<TopicInfo, DataWriterBase> writers_;
};

template <typename T>
std::shared_ptr<DataWriter<T>> Publisher::GetDataWriter(std::shared_ptr<TypedTopic<T>> topic,
    ara::core::StringView qosProfile)
{
    if (!topic) {
        common::logger().LogError() << "Publisher::GetDataWriter(): input topic is nil";
        return nullptr;
    }

    auto writer = writers_.Get(
        topic->GetInfo(), [this, topic, qosProfile]() { return CreateDataWriter<T>(topic, qosProfile); });

    return std::dynamic_pointer_cast<DataWriter<T>>(writer);
}

template <typename T>
std::shared_ptr<DataWriter<T>> Publisher::CreateDataWriter(std::shared_ptr<TypedTopic<T>> topic,
    ara::core::StringView qosProfile)
{
    // For current realization, the only allowed qos profile is "default". Feel free to change profile processing if you
    // need this
    if (qosProfile != "default") {
        common::logger().LogError() << "Subscriber::CreateDataWriter(): QoS string is not an expected one";
        return nullptr;
    }

    ::DDS::DataWriterQos writerQos;
    publisher_->get_default_datawriter_qos(writerQos);
    writerQos.durability.kind = ::DDS::TRANSIENT_LOCAL_DURABILITY_QOS;

    ::DDS::DataWriter_ptr writer = publisher_->create_datawriter(
        topic->Get(), writerQos, ::DDS::DataWriterListener::_nil(), ::OpenDDS::DCPS::NO_STATUS_MASK);
    if (CORBA::is_nil(writer)) {
        common::logger().LogError() << "Publisher::CreateDataWriter(): created writer is nil";
        return nullptr;
    }

    return std::make_shared<DataWriter<T>>(writer, topic);
}

}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_INTERNAL_DDS_IDL_PUBLISHER_H_
