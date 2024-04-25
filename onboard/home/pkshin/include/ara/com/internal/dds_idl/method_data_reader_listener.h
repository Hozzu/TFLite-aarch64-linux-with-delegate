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

#ifndef ARA_COM_INTERNAL_DDS_IDL_DATA_METHOD_READER_LISTENER_H_
#define ARA_COM_INTERNAL_DDS_IDL_DATA_METHOD_READER_LISTENER_H_

#include <dds/DdsDcpsSubscriptionC.h>

#include "ara/com/types.h"
#include "ara/com/internal/dds_idl/types.h"
#include "ara/com/internal/dds_idl/data_reader_listener.h"
#include "ara/com/internal/dds_idl/method_data_dispatcher.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace dds
{

/// @uptrace{SWS_CM_11110, 5f6bd1ead9de4eba9065f1c70d06251c88f97874}
class MethodDataReaderListener : public DataReaderListener
{
public:
    explicit MethodDataReaderListener(MethodDataDispatcherBase& dispatcher)
        : dispatcher_(dispatcher)
    { }

protected:
    /// @uptrace{SWS_CM_11020, 95ae0a0855d8338d23a058118b07bda90315d478}
    inline void on_data_available(::DDS::DataReader_ptr reader) override
    {
        static_cast<void>(reader);
        dispatcher_.Dispatch();
    }

private:
    MethodDataDispatcherBase& dispatcher_;
};

}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_INTERNAL_DDS_IDL_DATA_METHOD_READER_LISTENER_H_
