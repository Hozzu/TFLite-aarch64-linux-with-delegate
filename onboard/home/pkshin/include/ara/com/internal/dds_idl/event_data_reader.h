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

#ifndef ARA_COM_INTERNAL_DDS_IDL_DATA_EVENT_READER_H_
#define ARA_COM_INTERNAL_DDS_IDL_DATA_EVENT_READER_H_

#include "ara/com/internal/dds_idl/data_reader.h"
#include "ara/com/internal/dds_idl/event_data_reader_listener.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace dds
{

template <typename T>
class EventDataReader : public DataReader<T>
{
public:
    using SubscriptionStateChangeCallback = EventDataReaderListener::SubscriptionStateChangeHandler;

    EventDataReader(DDS::DataReader_ptr reader, std::shared_ptr<TypedTopic<T>> topic);

    void SetSubscriptionStateChangeHandler(ara::com::SubscriptionStateChangeHandler handler);
    void UnsetSubscriptionStateChangeHandler();

    void SetReceiveHandler(ara::com::EventReceiveHandler handler);
    void UnsetReceiveHandler();

    /// @brief Get subscription state from DDS reader
    ///
    /// @returns subscription state: subscribed, not subscribed or pending
    ///
    /// @uptrace{SWS_CM_11023, 491ddca91e9f3b48ee575f7cb0ab12e6112f31ee}
    ara::com::SubscriptionState GetSubscriptionState();

private:
    void ChangeReceiveHandler(ara::com::EventReceiveHandler handler, ::DDS::StatusMask mask);
    void ChangeSubscriptionStateHandler(SubscriptionStateChangeCallback handler, ::DDS::StatusMask mask);
};

template <typename T>
EventDataReader<T>::EventDataReader(DDS::DataReader_ptr reader, std::shared_ptr<TypedTopic<T>> topic)
    : DataReader<T>(reader, topic)
{
    if (!this->IsValid()) {
        common::logger().LogError() << "EventDataReader::EventDataReader(): this is not valid";
        return;
    }

    auto listener = new EventDataReaderListener();
    this->reader_->set_listener(listener, this->listenerStatusMask_);
}

template <typename T>
void EventDataReader<T>::SetReceiveHandler(ara::com::EventReceiveHandler handler)
{
    this->listenerStatusMask_ |= ::DDS::DATA_AVAILABLE_STATUS;
    this->ChangeReceiveHandler(handler, this->listenerStatusMask_);
}

template <typename T>
void EventDataReader<T>::UnsetReceiveHandler()
{
    this->listenerStatusMask_ &= ~(::DDS::DATA_AVAILABLE_STATUS);
    this->ChangeReceiveHandler(nullptr, this->listenerStatusMask_);
}

template <typename T>
void EventDataReader<T>::ChangeReceiveHandler(ara::com::EventReceiveHandler handler, ::DDS::StatusMask mask)
{
    if (!this->IsValid()) {
        common::logger().LogError() << "DataReader::SetReceiveHandler(): this is not valid";
        return;
    }

    ::DDS::DataReaderListener* listener = this->reader_->get_listener();
    auto dListener = dynamic_cast<EventDataReaderListener*>(listener);
    if (!dListener) {
        common::logger().LogError() << "DataReader::SetReceiveHandler(): listener of unexpected type";
        return;
    }

    dListener->set_event_receive_handler(handler);
    this->reader_->set_listener(dListener, mask);
}

template <typename T>
void EventDataReader<T>::SetSubscriptionStateChangeHandler(ara::com::SubscriptionStateChangeHandler handler)
{
    this->listenerStatusMask_ |= ::DDS::SUBSCRIPTION_MATCHED_STATUS;
    auto callback = [handler, this]() { handler(this->GetSubscriptionState()); };

    ChangeSubscriptionStateHandler(callback, this->listenerStatusMask_);
}

template <typename T>
void EventDataReader<T>::UnsetSubscriptionStateChangeHandler()
{
    this->listenerStatusMask_ &= ~(::DDS::SUBSCRIPTION_MATCHED_STATUS);

    ChangeSubscriptionStateHandler(nullptr, this->listenerStatusMask_);
}

template <typename T>
void EventDataReader<T>::ChangeSubscriptionStateHandler(SubscriptionStateChangeCallback handler, ::DDS::StatusMask mask)
{
    if (!this->IsValid()) {
        common::logger().LogError() << "DataReader::SetSubscriptionStateChangeHandler(): this is not valid";
        return;
    }

    ::DDS::DataReaderListener* listener = this->reader_->get_listener();
    auto dListener = dynamic_cast<EventDataReaderListener*>(listener);
    if (!dListener) {
        common::logger().LogError() << "DataReader::SetSubscriptionStateChangeHandler(): listener of unexpected type";
        return;
    }

    dListener->set_subscription_state_change_handler(handler);
    this->reader_->set_listener(dListener, mask);
}

template <typename T>
ara::com::SubscriptionState EventDataReader<T>::GetSubscriptionState()
{
    if (!this->reader_) {
        return ara::com::SubscriptionState::kNotSubscribed;
    }

    DDS::SubscriptionMatchedStatus matches;
    if (this->reader_->get_subscription_matched_status(matches) != DDS::RETCODE_OK) {
        return ara::com::SubscriptionState::kNotSubscribed;
    }

    if (matches.total_count > 0) {
        return ara::com::SubscriptionState::kSubscribed;
    }

    return ara::com::SubscriptionState::kSubscriptionPending;
}

}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_INTERNAL_DDS_IDL_DATA_EVENT_READER_H_
