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

#ifndef ARA_COM_INTERNAL_DDS_IDL_DATA_EVENT_READER_LISTENER_H_
#define ARA_COM_INTERNAL_DDS_IDL_DATA_EVENT_READER_LISTENER_H_

#include <functional>
#include <memory>

#include "ara/com/types.h"
#include "ara/com/internal/dds_idl/types.h"
#include "ara/com/internal/dds_idl/data_reader_listener.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace dds
{

class EventDataReaderListener : public DataReaderListener
{
public:
    using EventReceiveHandler = ara::com::EventReceiveHandler;
    using SubscriptionStateChangeHandler = std::function<void()>;

    /// @uptrace{SWS_CM_11020, 95ae0a0855d8338d23a058118b07bda90315d478}
    explicit EventDataReaderListener()
        : dataCallback_(nullptr)
        , subscriptionStateCallback_(nullptr)
    { }

    /// @uptrace{SWS_CM_11020, 95ae0a0855d8338d23a058118b07bda90315d478}
    void set_event_receive_handler(EventReceiveHandler callback)
    {
        dataCallback_ = callback;
    }

    /// @uptrace{SWS_CM_11020, 95ae0a0855d8338d23a058118b07bda90315d478}
    void set_subscription_state_change_handler(SubscriptionStateChangeHandler callback)
    {
        subscriptionStateCallback_ = callback;
    }

protected:
    /// @uptrace{SWS_CM_11020, 95ae0a0855d8338d23a058118b07bda90315d478}
    inline void on_subscription_matched(::DDS::DataReader_ptr reader,
        ::DDS::SubscriptionMatchedStatus const& status) override
    {
        static_cast<void>(reader);
        static_cast<void>(status);

        if (subscriptionStateCallback_) {
            subscriptionStateCallback_();
        }
    }

    /// @uptrace{SWS_CM_11020, 95ae0a0855d8338d23a058118b07bda90315d478}
    inline void on_data_available(::DDS::DataReader_ptr reader) override
    {
        static_cast<void>(reader);
        if (dataCallback_) {
            dataCallback_();
        }
    }

private:
    EventReceiveHandler dataCallback_;
    SubscriptionStateChangeHandler subscriptionStateCallback_;
};

}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_INTERNAL_DDS_IDL_DATA_EVENT_READER_LISTENER_H_
