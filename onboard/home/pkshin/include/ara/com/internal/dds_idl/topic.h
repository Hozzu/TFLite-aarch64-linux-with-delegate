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

#ifndef ARA_COM_INTERNAL_DDS_IDL_TOPIC_H_
#define ARA_COM_INTERNAL_DDS_IDL_TOPIC_H_

#include "ara/core/string.h"
#include "ara/com/internal/dds_idl/types.h"
#include "ara/com/internal/dds_idl/common.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace dds
{

struct TopicInfo
{
    ara::core::String type_name;
    ara::core::String topic_name;
};

class Topic
{
public:
    explicit Topic(::DDS::Topic_var topic)
        : topic_(topic)
    { }
    Topic() = delete;
    virtual ~Topic() = default;

    inline TopicInfo GetInfo() const;
    inline ::DDS::Topic_var Get();

private:
    ::DDS::Topic_var topic_;
};

template <class T>
class TypedTopic : public Topic
{
public:
    explicit TypedTopic(::DDS::Topic_var topic)
        : Topic(topic)
    { }
};

inline bool operator<(TopicInfo const& l, TopicInfo const& r)
{
    if (l.type_name < r.type_name) {
        return true;
    }

    return l.type_name == r.type_name ? l.topic_name < r.topic_name : false;
}

TopicInfo Topic::GetInfo() const
{
    return {topic_->get_type_name(), topic_->get_name()};
}

inline ::DDS::Topic_var Topic::Get()
{
    return topic_;
}

}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_INTERNAL_DDS_IDL_TOPIC_H_
