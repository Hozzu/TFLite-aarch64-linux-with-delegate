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

#ifndef ARA_COM_INTERNAL_DDS_IDL_DATA_READER_H_
#define ARA_COM_INTERNAL_DDS_IDL_DATA_READER_H_

#include <functional>

#include "ara/core/vector.h"
#include "ara/com/internal/dds_idl/types.h"
#include "ara/com/internal/dds_idl/common.h"
#include "ara/com/internal/dds_idl/dds_idl_types_binding.h"
#include "ara/com/internal/dds_idl/topic.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace dds
{

class DataReaderBase
{
public:
    virtual ~DataReaderBase() = default;
};

template <typename T>
class DataReader : public DataReaderBase
{
public:
    using ValueType = T;
    using ContainerType = ara::core::Vector<typename DDSTypeInfo<T>::dds_type_t>;

    DataReader(DDS::DataReader_ptr reader, std::shared_ptr<TypedTopic<T>> topic);

    bool IsValid() const;

    /// @brief Extract incoming messages from DDS
    ///
    /// @uptrace{SWS_CM_11023, 491ddca91e9f3b48ee575f7cb0ab12e6112f31ee}
    ContainerType Read(size_t maxNumberOfSamples);

protected:
    using reader_t = typename DDSTypeInfo<T>::dds_data_reader_t;
    typename reader_t::_var_type reader_;

    ::DDS::StatusMask listenerStatusMask_;
    std::shared_ptr<TypedTopic<T>> topic_;
};

template <typename T>
DataReader<T>::DataReader(DDS::DataReader_ptr reader, std::shared_ptr<TypedTopic<T>> topic)
    : listenerStatusMask_(::OpenDDS::DCPS::NO_STATUS_MASK)
    , topic_(topic)
{
    if (CORBA::is_nil(reader)) {
        common::logger().LogError() << "DataReader::DataReader(): input parameter is nil";
        return;
    }

    reader_ = reader_t::_narrow(reader);
    if (CORBA::is_nil(reader_)) {
        common::logger().LogError() << "DataReader::DataReader(): input parameter convertation error";
    }
}

template <typename T>
bool DataReader<T>::IsValid() const
{
    return !CORBA::is_nil(reader_) && !CORBA::is_nil(reader_.in());
}

/// @uptrace{SWS_CM_11023, 491ddca91e9f3b48ee575f7cb0ab12e6112f31ee}
template <typename T>
typename DataReader<T>::ContainerType DataReader<T>::Read(size_t maxNumberOfSamples)
{
    ContainerType result;

    if (!IsValid()) {
        return result;
    }

    typename DDSTypeInfo<T>::dds_type_seq_t samples;
    ::DDS::SampleInfoSeq samplesInfo;

    ::DDS::ReturnCode_t status = reader_->take(samples,
        samplesInfo,
        maxNumberOfSamples,
        ::DDS::NOT_READ_SAMPLE_STATE,
        ::DDS::ANY_VIEW_STATE,
        ::DDS::ANY_INSTANCE_STATE);

    // no new samples
    if (status == ::DDS::RETCODE_NO_DATA) {
        return result;
    }

    if (status != ::DDS::RETCODE_OK) {
        common::logger().LogError() << "DataReader::Read(): reading failed with status " << status;
        return result;
    }

    for (int i = 0; i < samples.length(); i++) {
        if (samplesInfo[i].valid_data) {
            result.push_back(samples[i]);
        }
    }

    reader_->return_loan(samples, samplesInfo);

    return result;
}

}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_INTERNAL_DDS_IDL_DATA_READER_H_
