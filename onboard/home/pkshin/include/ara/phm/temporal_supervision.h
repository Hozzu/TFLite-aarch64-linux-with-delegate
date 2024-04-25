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

#ifndef ARA_PHM_TEMPORAL_SUPERVISION_H_
#define ARA_PHM_TEMPORAL_SUPERVISION_H_

#include <chrono>

#include <boost/asio.hpp>

#include "ara/phm/local_supervision.h"
#include "ara/phm/async_handler_service.h"

// non-generated code
namespace ara
{
namespace phm
{

class TemporalSupervision
    : public LocalSupervision
    , public std::enable_shared_from_this<TemporalSupervision>
{
protected:
    using Clock = std::chrono::high_resolution_clock;
    using HighResolutionTimePoint = std::chrono::time_point<Clock>;
    using HighResolutionTimer = boost::asio::basic_waitable_timer<Clock>;
    using DurationMillis = std::chrono::milliseconds;

public:
    TemporalSupervision() = delete;
    virtual ~TemporalSupervision();

    TemporalSupervision(ara::log::Logger& logger);

protected:
    HighResolutionTimePoint supervisionCycleStartTime_;
    HighResolutionTimer timer_;

    virtual void TimerHandler(const boost::system::error_code& error) = 0;

    inline std::size_t CancelTimer()
    {
        return timer_.expires_from_now(DurationMillis(0));
    }

    inline void SetTimer(DurationMillis duration)
    {
        std::weak_ptr<TemporalSupervision> self(shared_from_this());

        boost::system::error_code ec;
        // return value indicates number of canceled async operations
        timer_.expires_from_now(duration, ec);

        // only set handler if timer was set successfully
        if (!ec) {
            // a member function is used as callback handler
            // 1) pass the this-pointer of the object to the async handler
            //    -> member to function pointer, member function available for callback
            // 2) handle object lifetime
            //    a) timer expiry -> handler is pushed into callback queue
            //    b) execution of callback member function
            //       -> if the object was deleted in the meantime (smart pointer out of scope)
            //       -> invalid / dangling pointer would occur
            //    Solution: smart pointers
            //       a) capture a shared pointer to the object
            //          -> forces the object to stay alive until the callback was executed
            //       b) capture a weak pointer to the object
            //          -> object can be deleted, but the weak pointer allows to check the existence
            //
            //    This is why this AND self are in the capture of this closure
            timer_.async_wait([this, self](const boost::system::error_code& error) {
                if (auto s = self.lock()) {
                    s->TimerHandler(error);
                } else {
                    // object already out of scope
                }
            });
        } else {  // failed to set timer
            // nothing
        }
    }

private:
    static AsyncHandlerService handlerService_;
};

}  // namespace phm
}  // namespace ara

#endif  // ARA_PHM_TEMPORAL_SUPERVISION_H_
