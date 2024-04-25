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

#ifndef ARA_TSYNC_INTERNAL_CLOCK_DATA_H_
#define ARA_TSYNC_INTERNAL_CLOCK_DATA_H_

#include "ara/core/vector.h"
#include "ara/core/string.h"
#include "ara/core/instance_specifier.h"
#include "ara/tsync/internal/time_base_type.h"
#include "ara/tsync/timestamp.h"
#include "ara/tsync/synchronized_time_base_status.h"
#include <atomic>
#include <chrono>
#include <memory>
#include <mutex>

namespace ara
{
namespace tsync
{
namespace internal
{

struct RawClock;
struct RawClockData;

/// @brief This class provides the template unspecific parts of the ClockData<>. With this approach it is possible to
/// easily mock these parts.
struct ClockDataImpl
{
    /// @brief Method to obtain the value of the update counter.
    /// @returns The value of the update counter.
    std::uint8_t GetUpdateCounter() const;

    /// @brief Method to obtain the status flags that are currently active.
    /// @returns The current status flags.
    SynchronizationStatus GetSyncStatusFlag() const;

    /// @brief Method to set the value of the update counter.
    void SetUpdateCounter(std::uint8_t updateCounter);

    /// @brief Method to set one single status flag.
    void SetSyncStatusFlag(const SynchronizationStatus& statusFlag);

    /// @brief Method to update the internal buffer to the latest values provided via the shared resource.
    void lock();

    /// @brief Method to update the shared resource with the data from the internal buffer.
    void unlock();

    /// @brief Constructor.
    ClockDataImpl();

    /// @brief Destructor.
    ~ClockDataImpl();

protected:
    /// @brief  A thread local static variable used to count the depth of nested lock calls. Lock happens only when
    /// counter is zero. Each additional lock just increases the counter. Once the counter reaches zero again, the
    /// resource is unlocked.
    thread_local static std::atomic_uchar counter_;

    /// @brief Mutex to protect the internal RawClockData buffer from simultaneous access.
    std::mutex lock_;

    /// @brief RawClock object to interact with the memory.
    std::unique_ptr<RawClock> rawClock_;

    /// @brief Plain data container that holds the unspecific clock data.
    std::unique_ptr<RawClockData> rawClockData_;

    /// @brief A flag to indicate whether the internal RawClockData copy has been modified and needs to be written back
    /// when the object is unlocked.
    bool dataPending_{false};

    // wrappers to ease the mocking of ClockData<>
    std::int64_t GetLatestClockUpdate() const;
    std::int64_t GetLatestClockValue() const;
    void SetLatestClockValue(std::int64_t updateTimePoint, std::int64_t clockValue);

    template <typename T>
    bool Configure(const ara::core::InstanceSpecifier& instanceSpecifier);
};

/// @brief Clock specific abstraction of clock data stored somewhere in the system. PODs are translated into clock
/// specific time_points and strongly typed enums.
/// @details Instances of this class should be passed to an std::lock_guard, before any member function is called. By
/// doing so, the guard will lock the resource and update the internal buffer to the contents of the shared resource.
/// All API calls *are then based on this snapshot. Nested calls will not lead to data being re-read.
/// Once the lock_guard goes out of scope, it will release the snapshot and data gets written to the shared storage, in
/// case the internal buffer has been *modified.*
/// @tparam Clock The clock type to which raw data shall be converted to.
/// @tparam LocalClock The local reference clock type that is used to measure progress in time.
struct ClockData : public ClockDataImpl
{
    /// @brief Default Constructor.
    ClockData() = default;

    /// @brief Move Constructor for ClockData
    ClockData(ClockData&& cd) noexcept;

    /// @brief Move assignment operator for ClockData
    ClockData& operator=(ClockData&& cd) & noexcept;

    /// @brief Method to obtain the point in time at which the clock was updated the last time.
    /// @returns Reference clock time point that indicates when the clock data was updated the last time.
    ara::tsync::Timestamp GetLatestClockUpdate() const
    {
        return ara::tsync::Timestamp(std::chrono::duration<int64_t, std::nano>(ClockDataImpl::GetLatestClockUpdate()));
    }

    /// @brief Method to obtain the last known clock value as it was set on the last update.
    /// @returns Time point that expresses the value of the clock.
    ara::tsync::Timestamp GetLatestClockValue() const
    {
        return ara::tsync::Timestamp(std::chrono::duration<int64_t, std::nano>(ClockDataImpl::GetLatestClockValue()));
    }

    /// @brief Method to set the time point of the last update.
    /// @param updateTimePoint - Reference clock time point of the last update.
    /// @param clockValue - Clock value at the time of the given updateTimePoint.
    void SetLatestClockValue(ara::tsync::Timestamp updateTimePoint, ara::tsync::Timestamp clockValue)
    {
        ClockDataImpl::SetLatestClockValue(
            std::chrono::duration_cast<std::chrono::duration<int64_t, std::nano>>(updateTimePoint.time_since_epoch())
                .count(),
            std::chrono::duration_cast<std::chrono::duration<int64_t, std::nano>>(clockValue.time_since_epoch())
                .count());
    }

    /// @brief Method that can be used to configure where the clock data will be stored.
    /// @details SynchMasterTBs and PureLocalTBs will be able to read and write to that storage. All other TBs will only
    /// have read access.
    /// @returns True if setup was successful, otherwise false.
    template <TimeBaseType T>
    typename std::enable_if<T == TimeBaseType::kSyncTimeProvider, bool>::type Configure(
        const ara::core::InstanceSpecifier& instanceSpecifier)
    {
        return ClockDataImpl::Configure<std::true_type>(instanceSpecifier);
    }

    /// @brief Method that can be used to configure where the clock data will be stored.
    /// @details SynchronizedTimeBaseProviders will be able to read and write to that storage. All other TBs will only
    /// have read access.
    /// @returns True if setup was successful, otherwise false.
    template <TimeBaseType T>
    typename std::enable_if<T != TimeBaseType::kSyncTimeProvider, bool>::type Configure(
        const ara::core::InstanceSpecifier& instanceSpecifier)
    {
        return ClockDataImpl::Configure<std::false_type>(instanceSpecifier);
    }
};
}  // namespace internal
}  // namespace tsync
}  // namespace ara

#endif  // ARA_TSYNC_INTERNAL_CLOCK_DATA_H_
