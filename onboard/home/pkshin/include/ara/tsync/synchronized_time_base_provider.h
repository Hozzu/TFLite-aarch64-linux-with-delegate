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

#ifndef ARA_TSYNC_SYNCHRONIZED_TIME_BASE_PROVIDER_H
#define ARA_TSYNC_SYNCHRONIZED_TIME_BASE_PROVIDER_H

#include "ara/tsync/timestamp.h"
#include "ara/tsync/internal/clock.h"
#include "ara/tsync/synchronized_time_base_status.h"
#include "ara/core/vector.h"
#include "ara/core/instance_specifier.h"
#include "ara/core/string.h"
#include "ara/tsync/internal/clock_data.h"
#include "ara/tsync/internal/time_base_type.h"
#include "ara/tsync/internal/specifier_mapping.h"
#include "ara/core/instance_specifier.h"
#include "ara/core/span.h"

#include <memory>

namespace ara
{
namespace tsync
{
/// @brief Class SynchronizedTimeBaseProvider is the access to the synchronized timebase referenced by the
/// InstanceSpecifier.
/// @details It allows to get the current time_point, the rate deviation, the current status and the received user data.
/// @note Uptrace is not set as class is not fully implemented.
class SynchronizedTimeBaseProvider
{
public:
    /// @brief SynchronizedTimeBaseProvider constructor.
    /// @param specifier to an PortPrototype of an Time Synchronization Interface
    /// @uptrace{SWS_TS_01101, 7f269c07d64da2c16977e0ee7c1c4d7fa90553e4}
    explicit SynchronizedTimeBaseProvider(const ara::core::InstanceSpecifier& specifier) noexcept
        : rateCorrection_(1.0)
    {
        internal::SpecifierMapping mapping(specifier);
        clockData_.Configure<internal::TimeBaseType::kSyncTimeProvider>(specifier);
        clockData_.SetSyncStatusFlag(SynchronizationStatus::kNotSynchronizedUntilStartup);
    }

    /// @brief Move constructor for SynchronizedTimeBaseProvider.
    /// @uptrace{SWS_TS_01102, 8e89203a27abd284769068fe1946fa8b77ae9920}
    SynchronizedTimeBaseProvider(SynchronizedTimeBaseProvider&& stbc) noexcept
        : clockData_(std::move(stbc.clockData_))
        , rateCorrection_(std::move(stbc.rateCorrection_))
    { }

    /// @brief Move assignment operator for SynchronizedTimeBaseProvider.
    /// @uptrace{SWS_TS_01103, 7bcbf20b90ca8fc258fe30a048c7a5fbc56c79b1}
    SynchronizedTimeBaseProvider& operator=(SynchronizedTimeBaseProvider&& stbc) & noexcept
    {
        clockData_ = std::move(stbc.clockData_);
        rateCorrection_ = std::move(stbc.rateCorrection_);
        return *this;
    }

    /// @brief The copy constructor for SynchronizedTimeBaseProvider shall not be used.
    /// @uptrace{SWS_TS_01104, 87aebcabb294a1d87fc0c91f7c7aa8e8ef43bfaf}
    SynchronizedTimeBaseProvider(const SynchronizedTimeBaseProvider&) = delete;

    /// @brief The copy assignment operator for SynchronizedTimeBaseProvider shall not be used.
    /// @uptrace{SWS_TS_01105, 320ec75a3201da16d81cbc2ee4663d8b53d16f62}
    SynchronizedTimeBaseProvider& operator=(const SynchronizedTimeBaseProvider&) = delete;

    /// TODO: Delete the SynchronizedTimeBaseProvider members here.
    /// @brief SynchronizedTimeBaseProvider destructor.
    /// @uptrace{SWS_TS_01106, 206b1daa2d7ce7c61031e183318470e825449b40}
    ~SynchronizedTimeBaseProvider() = default;

    /// @brief A method that can be used to set a new time value for the clock.
    /// @details Setting a new time also triggers transmission on the bus.
    /// @param[in] timePoint The time information to be set.
    /// @param[in] userData The user data to be set.
    /// @note uptrace is not set as spec item is not implemented properly.
    ara::core::Result<void> SetTime(ara::tsync::Timestamp timePoint,
        ara::core::Span<const ara::core::Byte> userData = {}) noexcept
    {
        static_cast<void>(userData);
        return UpdateTime(timePoint);
        // TODO: trigger ara_tsync_daemon to transmit PTP messages on the bus
    }

    /// @brief A method that can be used to set a new time value for the clock.
    /// @details The clock value is only updated locally, transmission on the bus will happen in the next cycle.
    /// @param[in] timePoint The time information to be set.
    /// @note uptrace is not set as spec item is not implemented properly.
    ara::core::Result<void> UpdateTime(ara::tsync::Timestamp timePoint)
    {
        // FIXME: check the implementation to see when and why an error should be returned.
        std::lock_guard<internal::ClockData> lock(clockData_);
        clockData_.SetLatestClockValue(internal::Clock::now(), timePoint);
        clockData_.SetUpdateCounter(static_cast<std::uint8_t>(clockData_.GetUpdateCounter() + 1));
        clockData_.SetSyncStatusFlag(SynchronizationStatus::kSynchronized);
        return ara::core::Result<void>{};
    }

    /// @brief Method to obtain the current time (regardless of the current sync status).
    /// @returns The current time as clock specific time point.
    /// @uptrace{SWS_TS_01109, a3c38d5ad438c00e8dbcb88a27ce83fa7ff67fc6}
    ara::tsync::Timestamp GetCurrentTime() const noexcept
    {
        std::lock_guard<internal::ClockData> lock(clockData_);
        ara::tsync::Timestamp retVal = clockData_.GetLatestClockValue();
        std::chrono::nanoseconds elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(
            internal::Clock::now() - clockData_.GetLatestClockUpdate());
        std::chrono::nanoseconds correctedTime = std::chrono::nanoseconds(
            static_cast<std::chrono::nanoseconds::rep>(static_cast<double>(elapsedTime.count()) * rateCorrection_));
        return retVal + correctedTime;
    }

    /// @brief This method can be used to set the rate correction that will be applied to time values.
    /// @param[in] rateCorrection The rate correction to be applied. 0.5 is two times slower, whilst 2.0 is 2 times
    /// faster.
    /// @note Uptrace is not set as spec item is not fully implemented (no error returned).
    ara::core::Result<void> SetRateCorrection(double rateCorrection) noexcept
    {
        rateCorrection_ = rateCorrection;
        return ara::core::Result<void>{};
    }

    /// @brief Method to obtain the current rate deviation of the clock.
    /// @returns The current rate deviation.
    /// @uptrace{SWS_TS_01111, d5f06018cd4fa2c600e3e2fabae56340fb8b84bf}
    double GetRateDeviation() const noexcept
    {
        return (1.0 - rateCorrection_);
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

#endif  // ARA_TSYNC_SYNCHRONIZED_TIME_BASE_PROVIDER_H
