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

#ifndef ARA_COM_INTERNAL_DDS_IDL_DATA_WRITER_H_
#define ARA_COM_INTERNAL_DDS_IDL_DATA_WRITER_H_

#include <functional>
#include <memory>

#include <dds/DdsDcpsSubscriptionC.h>

#include "ara/com/internal/dds_idl/dds_idl_types_binding.h"
#include "ara/com/internal/dds_idl/types.h"
#include "ara/com/internal/dds_idl/common.h"
#include "ara/com/internal/dds_idl/topic.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace dds
{

class DataWriterBase
{
public:
    virtual ~DataWriterBase() = default;
};

template <typename T>
class DataWriter : public DataWriterBase
{
public:
    DataWriter(DDS::DataWriter_ptr writer, std::shared_ptr<TypedTopic<T>> topic);

    bool IsValid() const;

    /// @brief Write data to topic
    ///
    /// @uptrace{SWS_CM_11017, f9b1a84d30ae3fa961b627f6fc730a8d63941926}
    /// @uptrace{SWS_CM_11132, fea2b57ea9916d57c7b0d741c4da6b4d26494419}
    bool Write(typename DDSTypeInfo<T>::dds_type_t const& data);

private:
    using writer_t = typename DDSTypeInfo<T>::dds_data_writer_t;
    typename writer_t::_var_type writer_;

    std::shared_ptr<TypedTopic<T>> topic_;
};

template <typename T>
DataWriter<T>::DataWriter(DDS::DataWriter_ptr writer, std::shared_ptr<TypedTopic<T>> topic)
    : writer_(writer_t::_nil())
    , topic_(topic)
{
    if (CORBA::is_nil(writer)) {
        common::logger().LogError() << "DataWriter::DataWriter(): input parameter is nil";
        return;
    }

    writer_ = writer_t::_narrow(writer);
    if (CORBA::is_nil(writer_.in())) {
        common::logger().LogError() << "DataWriter::DataWriter(): input parameter convertation error";
        return;
    }
}

template <typename T>
bool DataWriter<T>::IsValid() const
{
    return !CORBA::is_nil(writer_.in());
}

template <typename T>
bool DataWriter<T>::Write(typename DDSTypeInfo<T>::dds_type_t const& data)
{
    if (!IsValid()) {
        common::logger().LogError() << "DataWriter::Write(): this is not valid";
        return false;
    }

    auto result = writer_->write(data, DDS::HANDLE_NIL);
    return DDS::RETCODE_OK == result;
}

}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_INTERNAL_DDS_IDL_DATA_WRITER_H_
