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

#ifndef ARA_COM_INTERNAL_DDS_IDL_METHOD_DATA_READER_H_
#define ARA_COM_INTERNAL_DDS_IDL_METHOD_DATA_READER_H_

#include "ara/com/internal/dds_idl/data_reader.h"
#include "ara/com/internal/dds_idl/method_data_reader_listener.h"
#include "ara/com/internal/dds_idl/method_data_dispatcher.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace dds
{

template <typename T>
class MethodDataReader : public DataReader<T>
{
public:
    using TypedMethodDataDispatcher = MethodDataDispatcher<DataReader<T>, typename DDSTypeInfo<T>::dds_type_t>;

    MethodDataReader(DDS::DataReader_ptr reader, std::shared_ptr<TypedTopic<T>> topic);

    void AddMethodHandler(typename TypedMethodDataDispatcher::MethodId const methodId,
        typename TypedMethodDataDispatcher::Handler const& handler);
    void RemoveMethodHandler(typename TypedMethodDataDispatcher::MethodId const methodId);

private:
    void UpdateStatusMask();

    TypedMethodDataDispatcher methodDispatcher_;
};

template <typename T>
MethodDataReader<T>::MethodDataReader(DDS::DataReader_ptr reader, std::shared_ptr<TypedTopic<T>> topic)
    : DataReader<T>(reader, topic)
    , methodDispatcher_(*this)
{
    if (!this->IsValid()) {
        common::logger().LogError() << "MethodDataReader::MethodDataReader(): this is not valid";
        return;
    }

    auto listener = new MethodDataReaderListener(methodDispatcher_);
    this->reader_->set_listener(listener, this->listenerStatusMask_);
}

template <typename T>
void MethodDataReader<T>::AddMethodHandler(typename TypedMethodDataDispatcher::MethodId const methodId,
    typename TypedMethodDataDispatcher::Handler const& handler)
{
    methodDispatcher_.AddMethodHandler(methodId, handler);
    UpdateStatusMask();
}

template <typename T>
void MethodDataReader<T>::RemoveMethodHandler(typename TypedMethodDataDispatcher::MethodId const methodId)
{
    methodDispatcher_.RemoveMethodHandler(methodId);
    UpdateStatusMask();
}

template <typename T>
void MethodDataReader<T>::UpdateStatusMask()
{
    auto newMask = this->listenerStatusMask_;
    if (methodDispatcher_.IsEmpty()) {
        newMask &= ~(::DDS::DATA_AVAILABLE_STATUS);
    } else {
        newMask |= ::DDS::DATA_AVAILABLE_STATUS;
    }

    if (this->listenerStatusMask_ != newMask) {
        this->listenerStatusMask_ = newMask;
        this->reader_->set_listener(this->reader_->get_listener(), newMask);
    }
}

}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_INTERNAL_DDS_IDL_METHOD_DATA_READER_H_
