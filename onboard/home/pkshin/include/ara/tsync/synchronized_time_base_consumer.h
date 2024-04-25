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

#ifndef ARA_TSYNC_SYNCHRONIZED_TIME_BASE_CONSUMER_H
#define ARA_TSYNC_SYNCHRONIZED_TIME_BASE_CONSUMER_H

#include "ara/tsync/timestamp.h"
#include "ara/tsync/internal/clock.h"
#include "ara/tsync/synchronized_time_base_status.h"
#include "ara/core/vector.h"
#include "ara/core/instance_specifier.h"
#include "ara/core/string.h"
#include "ara/tsync/internal/clock_data.h"
#include "ara/tsync/internal/time_base_type.h"
#include <chrono>
#include <memory>

namespace ara
{
namespace tsync
{

/// @brief Class SynchronizedTimeBaseConsumer is the access to the synchronized timebase referenced
/// by the InstanceSpecifier.
/// It allows to get the current time_point, the rate deviation, the current status and the received user data.
/// @note Missing uptrace because class is not fully implemented!
class SynchronizedTimeBaseConsumer
{
public:
    /// @brief SynchronizedTimeBaseConsumer constructor.
    /// @param specifier to an PortPrototype of an Time Synchronization Interface
    /// @uptrace{SWS_TS_01001, 28d3580bc93dc4a54462d61760903747c120587f}
    explicit SynchronizedTimeBaseConsumer(const ara::core::InstanceSpecifier& specifier) noexcept
        : rateCorrection_(1.0)
    {
        clockData_.Configure<internal::TimeBaseType::kSyncTimeConsumer>(specifier);
    }

    /// TODO: Delete the SynchronizedTimeBaseConsumer members here.
    /// @brief SynchronizedTimeBaseConsumer destructor.
    /// @uptrace{SWS_TS_01002, eb68427109a3b1f1ce084559ed7baaedbfc14db7}
    ~SynchronizedTimeBaseConsumer() = default;

    /// @brief Move constructor for SynchronizedTimeBaseConsumer.
    /// @uptrace{SWS_TS_01003, e84fb4fea1405910012151a22abcb26fb628130c}
    SynchronizedTimeBaseConsumer(SynchronizedTimeBaseConsumer&& stbc) noexcept
        : clockData_(std::move(stbc.clockData_))
        , rateCorrection_(std::move(stbc.rateCorrection_))
    { }

    /// @brief Move assignment operator for SynchronizedTimeBaseConsumer.
    /// @uptrace{SWS_TS_01004, 81a97053ff9a721fe375bf1a77094f8cba57a8ad}
    SynchronizedTimeBaseConsumer& operator=(SynchronizedTimeBaseConsumer&& stbc) & noexcept
    {
        clockData_ = std::move(stbc.clockData_);
        rateCorrection_ = std::move(stbc.rateCorrection_);
        return *this;
    }

    /// @brief The copy constructor for SynchronizedTimeBaseConsumer shall not be used.
    /// @uptrace{SWS_TS_01005, efa5b640dd73776175a26a907898347df3de317e}
    SynchronizedTimeBaseConsumer(const SynchronizedTimeBaseConsumer&) = delete;

    /// @brief The copy assignment operator for SynchronizedTimeBaseConsumer shall not be used.
    /// @uptrace{SWS_TS_01006, 0b060c33a40b2178d0b68e732c4d8c679455dc59}
    SynchronizedTimeBaseConsumer& operator=(const SynchronizedTimeBaseConsumer&) = delete;

    /// @brief Method to obtain the current time (regardless of the current sync status).
    /// @returns The current time of the synchronized clock.
    /// @uptrace{SWS_TS_01007, 81f24ed8563f8abbbe25d08d4d522d3fccfe7b59}
    ara::tsync::Timestamp GetCurrentTime() const noexcept
    {
        std::lock_guard<internal::ClockData> lock(clockData_);
        Timestamp ret_val = clockData_.GetLatestClockValue();
        std::chrono::nanoseconds elapsed_time = std::chrono::duration_cast<std::chrono::nanoseconds>(
            internal::Clock::now() - clockData_.GetLatestClockUpdate());
        return ret_val + elapsed_time;
    }

    /// @brief Method to obtain the current rate deviation of the clock.
    /// @returns The current rate deviation.
    /// @uptrace{SWS_TS_01008, f0763c8c4066326a3cd6ba5761c2fd4f3ba0adf0}
    double GetRateDeviation() const noexcept
    {
        return (1.0 - rateCorrection_);
    }

    /// @brief Method to obtain a snapshot of the current state of the clock.
    /// @details This includes status flags, clock configuration and the actual time value of the created status object.
    /// @returns A clock specific TimeBaseStatus that contains all the relevant clock information.
    /// @uptrace{SWS_TS_01009, f293e28b73ef9ba8e5f32055b9e0285d21f73276}
    SynchronizedTimeBaseStatus GetTimeWithStatus() const noexcept
    {
        SynchronizationStatus syncStatus;
        {
            std::lock_guard<internal::ClockData> lock(clockData_);
            syncStatus = clockData_.GetSyncStatusFlag();
        }
        return SynchronizedTimeBaseStatus(syncStatus, GetCurrentTime());
    }

private:
    /// @brief Member object used to abstract the clock data that is stored somewhere in the system.
    mutable internal::ClockData clockData_;

    /// @brief The rate correction that is currently applied to compensate rate differences between master and slave
    /// clock.
    double rateCorrection_;
};

}  // namespace tsync
}  // namespace ara

#endif  // ARA_TSYNC_SYNCHRONIZED_TIME_BASE_CONSUMER_H
