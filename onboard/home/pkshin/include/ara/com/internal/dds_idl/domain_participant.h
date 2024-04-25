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

#ifndef ARA_COM_INTERNAL_DDS_IDL_DOMAIN_PARTICIPANT_H_
#define ARA_COM_INTERNAL_DDS_IDL_DOMAIN_PARTICIPANT_H_

#include <functional>
#include <memory>
#include <string>

#include <dds/DdsDcpsSubscriptionC.h>

#include "ara/core/map.h"
#include "ara/com/types.h"
#include "ara/com/internal/dds_idl/types.h"
#include "ara/com/internal/dds_idl/common.h"
#include "ara/com/internal/dds_idl/dds_idl_types_binding.h"
#include "ara/com/internal/dds_idl/data_reader.h"
#include "ara/com/internal/dds_idl/data_writer.h"
#include "ara/com/internal/dds_idl/publisher.h"
#include "ara/com/internal/dds_idl/subscriber.h"
#include "ara/com/internal/dds_idl/shared_registry.h"
#include "ara/com/internal/dds_idl/topic.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace dds
{

class ParticipantFactory;
class UserDataObserver;

class DomainParticipant
{
private:
    struct PrivateTag
    { };

public:
    using ParticipantRegistry = ara::com::internal::dds::WeakRegistry<types::DomainId, DomainParticipant>;
    using UserDataChangedCallback = std::function<void(const ara::core::Vector<ara::core::StringView>&)>;

    /// @brief Get DomainParticipant
    ///
    /// @param domainId DDS Domain ID
    /// @return DomainParticipant
    ///
    /// @uptrace{SWS_CM_11002, b714b8c99d0fadfe45732780cb3b16632e24a1bd}
    /// @uptrace{SWS_CM_11007, 20a7681ce814e9bdc68387da5fa8eaf111077be3}
    /// @uptrace{SWS_CM_11008, 67c93166ecf18baa297bd3d9c15ab572f1f8b00e}
    static std::shared_ptr<DomainParticipant> get(types::DomainId domainId, ara::core::StringView qosProfile);

    DomainParticipant(PrivateTag, types::DomainId domainId, ara::core::StringView qosProfile);
    DomainParticipant(DomainParticipant const&) = delete;
    DomainParticipant(DomainParticipant&&) = delete;

    DomainParticipant& operator=(DomainParticipant const&) = delete;
    DomainParticipant& operator=(DomainParticipant&&) = delete;

    ~DomainParticipant();

    /// @brief Get USER_DATA QoS Policy of the DDS DomainParticipant
    ///
    /// @return USER_DATA QoS Policy
    ///
    /// @uptrace{SWS_CM_09004, 81b4a1b42d7401f595c66bdb4cf83b2a8401119d}
    ara::core::String GetUserData() const;

    /// @brief Set new value for USER_DATA QoS Policy
    ///
    /// @param newData New USER_DATA
    ///
    /// @uptrace{SWS_CM_09004, 81b4a1b42d7401f595c66bdb4cf83b2a8401119d}
    void SetUserData(ara::core::StringView newData);

    /// @brief Set callback for UserDataObserver
    ///
    /// @param callback Callback function
    ///
    /// @uptrace{SWS_CM_11009, 660643ce96fadd1c3552e58d88c332470c9542a3}
    /// @uptrace{SWS_CM_11012, da4be7ef4b26cedaef4a995af699edb9bf813895}
    /// @uptrace{SWS_CM_11014, 43fb9c0326197a1a6fef1f0b6a5cd2d9b6a6df0b}
    void SetUserDataChangedCallback(UserDataChangedCallback callback);

    /// @brief Check is UserDataObserver callback configured
    ///
    /// @return callback setting state
    bool IsUserDataChangedCallbackSet() const;

    /// @brief Get Topic from registry
    ///
    /// @param topicName Topic name
    /// @return Topic
    ///
    /// @uptrace{SWS_CM_11003, cea0644db853e28cd6c794842d816e2cdac63fad}
    /// @uptrace{SWS_CM_11029, 1cf92d267e656deefc6d06777a1e5469f3ace869}
    /// @uptrace{SWS_CM_11030, bc97e2020f54303315c9f5366c7475b8ebbfa653}
    /// @uptrace{SWS_CM_11031, 88dc48d361a716ef56de9f71332a8257d5158b40}
    template <typename T>
    std::shared_ptr<TypedTopic<T>> GetTopic(char const* topicName);

    /// @brief Get Publisher from registry
    ///
    /// @param info service ID and instance ID
    /// @return Publisher
    ///
    /// @uptrace{SWS_CM_11002, b714b8c99d0fadfe45732780cb3b16632e24a1bd}
    std::shared_ptr<Publisher> GetPublisher(const common::ServiceInfo info);

    /// @brief Get Subscriber from registry
    ///
    /// @param info service ID and instance ID
    /// @return Subscriber
    ///
    /// @uptrace{SWS_CM_11002, b714b8c99d0fadfe45732780cb3b16632e24a1bd}
    std::shared_ptr<Subscriber> GetSubscriber(const common::ServiceInfo info);

private:
    template <typename T>
    bool RegisterType();
    void UnregisterTypes();

    template <typename T>
    std::shared_ptr<TypedTopic<T>> CreateTopic(ara::core::String const& topicName);

    std::shared_ptr<Publisher> CreatePublisher(const common::ServiceInfo info);
    std::shared_ptr<Subscriber> CreateSubscriber(const common::ServiceInfo info);

    ara::core::String MakeServicePartitionName(const common::ServiceInfo info);
    void SetPartition(const common::ServiceInfo info, DDS::PartitionQosPolicy& partition);

    types::DomainId domainId_;

    ::DDS::DomainParticipant_var participant_;
    ::DDS::DataReaderListener_var userDataObserver_;

    std::shared_ptr<ParticipantFactory> factory_;
    ara::core::Map<ara::core::String, OpenDDS::DCPS::TypeSupport_var> registeredTypes_;
    SharedRegistry<ara::core::String, Topic> topics_;
    SharedRegistry<common::ServiceInfo, Publisher> publishers_;
    SharedRegistry<common::ServiceInfo, Subscriber> subscribers_;
};

template <typename T>
std::shared_ptr<TypedTopic<T>> DomainParticipant::GetTopic(const char* topicName)
{
    if (!RegisterType<T>()) {
        return nullptr;
    }

    auto topic = topics_.Get(topicName, [this, &topicName]() { return CreateTopic<T>(topicName); });
    return std::dynamic_pointer_cast<TypedTopic<T>>(topic);
}

template <typename T>
std::shared_ptr<TypedTopic<T>> DomainParticipant::CreateTopic(ara::core::String const& topicName)
{
    DDS::TopicQos defaultQos;
    participant_->get_default_topic_qos(defaultQos);

    ::DDS::Topic_var topic = participant_->create_topic(topicName.c_str(),
        DDSTypeInfo<T>::type_name(),
        defaultQos,
        DDS::TopicListener::_nil(),
        ::OpenDDS::DCPS::DEFAULT_STATUS_MASK);
    if (CORBA::is_nil(topic)) {
        common::logger().LogError() << "DomainParticipant::CreateTopic(): created topic is nil";
    }

    return std::make_shared<TypedTopic<T>>(topic);
}

template <typename T>
bool DomainParticipant::RegisterType()
{
    using dds_type_support_t = typename DDSTypeInfo<T>::dds_type_support_t;
    auto typeName = dds_type_support_t::TraitsType::type_name();
    if (registeredTypes_.find(typeName) == registeredTypes_.end()) {
        OpenDDS::DCPS::TypeSupport_var type = new dds_type_support_t();
        auto result = type->register_type(participant_.in(), typeName);
        if (::DDS::RETCODE_OK != result) {
            common::logger().LogError() << "DomainParticipant::RegisterType(): failed to register type " << typeName;
            return false;
        }
        registeredTypes_[typeName] = type;
    }

    return true;
}

}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_INTERNAL_DDS_IDL_DOMAIN_PARTICIPANT_H_
