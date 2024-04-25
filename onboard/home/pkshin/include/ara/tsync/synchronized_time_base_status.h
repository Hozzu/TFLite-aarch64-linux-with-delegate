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

#ifndef ARA_TSYNC_SYNCHRONIZED_TIME_BASE_STATUS_H_
#define ARA_TSYNC_SYNCHRONIZED_TIME_BASE_STATUS_H_

#include "ara/tsync/timestamp.h"

namespace ara
{
namespace tsync
{

class SynchronizedTimeBaseConsumer;

/// @brief Enumeration that is used to express the communication state of a time base.
/// @uptrace{SWS_TS_01050, 0ef084076572e03a17118be31b2f5102ef8acff8}
enum class SynchronizationStatus : std::uint32_t
{
    kNotSynchronizedUntilStartup = 0,  ///< The TB is not synchronized until startup (inital state)
    kTimeOut = 0x1,  ///< The TB was not synchronized within a certain time frame.
    kSynchronized = 0x2,  ///< The TB is in sync with the time master.
    kSynchToGateway = 0x3  ///< The TB is in sync with the gateway.
};

/// @brief Enumeration that is used to express the leap jump of a time base.
/// @uptrace{SWS_TS_01051, ac894a8607665075966c48e51cc8650ad8f04802}
enum class LeapJump : std::uint32_t
{
    /// @brief No adjustment back or greater than a certain threshold has been made
    kTimeLeapNone = 0,

    /// @brief An adjustment greater than a certain threshold has been made
    kTimeLeapFuture = 1,

    /// @brief An adjustment back in time greater than a certain threshold has been made
    kTimeLeapPast = 2,
};

/// @brief The class represents a snapshot of a time point including its states.
/// @note Uptrace missing as class is not fully implemented.
class SynchronizedTimeBaseStatus final
{
public:
    /// @brief A method that returns the synchronization state the object was created.
    /// @returns The TimeBaseStatus of the underlying time base at creation time of the object.
    /// @uptrace{SWS_TS_01053, 5d5a97caacbdc8116f9006b469e0ee9d0f6b9d47}
    SynchronizationStatus GetSynchronizationStatus() const noexcept
    {
        return syncStatus_;
    }

    /// @brief Method that can be used to determine the direction of a Leap jump.
    /// Only the jump until the previous object creation is included.
    /// @return LeapJump value.
    /// @uptrace{SWS_TS_01054, 8ebe9b07f95db6da13e987027764dc43e6d04a6c}
    LeapJump GetLeapJump() const noexcept
    {
        return leapJump_;
    }

    /// @brief A method to obtain the creation time of this object.
    /// @returns The point in time at which this object was created. Time point is expressed in context of the clock
    /// that created this object.
    /// @uptrace{SWS_TS_01055, 96087bd3c8a01b00afc36039e72cf20fcd009103}
    Timestamp GetCreationTime() const noexcept
    {
        return creationTime_;
    }

    /// @brief Constructor of SynchronizedTimeBaseStatus cannot be used.
    /// @uptrace{SWS_TS_01061}
    SynchronizedTimeBaseStatus() = delete;

    /// @brief Move constructor of SynchronizedTimeBaseStatus.
    /// @uptrace{SWS_TS_01057, 4106fe2441c72ea693ed1c610b4f6315f1c2ece2}
    SynchronizedTimeBaseStatus(SynchronizedTimeBaseStatus&& stbs) noexcept
        : syncStatus_(std::move(stbs.syncStatus_))
        , creationTime_(std::move(stbs.creationTime_))
    { }

    /// @brief Copy constructor of SynchronizedTimeBaseStatus (needed for return by value).
    /// @uptrace{SWS_TS_01058, d335d485be7d3e05fd2cc289264c7aed90818d4e}
    SynchronizedTimeBaseStatus(const SynchronizedTimeBaseStatus& stbs) noexcept
        : syncStatus_(stbs.syncStatus_)
        , creationTime_(stbs.creationTime_)
    { }

    /// @brief Move assignment operator of SynchronizedTimeBaseStatus.
    /// @uptrace{SWS_TS_01059, cef475c8c07c268d36de7edbe968b317def101cc}
    SynchronizedTimeBaseStatus& operator=(SynchronizedTimeBaseStatus&& stbs) & noexcept
    {
        syncStatus_ = std::move(stbs.syncStatus_);
        creationTime_ = std::move(stbs.creationTime_);
        return *this;
    }

    /// @brief Copy assignment operator of SynchronizedTimeBaseStatus.
    /// @uptrace{SWS_TS_01060, 9643bde45939cc0a1a05b4cb3cf1333e59608ca7}
    SynchronizedTimeBaseStatus& operator=(const SynchronizedTimeBaseStatus& stbs) noexcept
    {
        syncStatus_ = stbs.syncStatus_;
        creationTime_ = stbs.creationTime_;
        return *this;
    }

    /// @brief Destructor of SynchronizedTimeBaseStatus.
    /// @uptrace{SWS_TS_01062}
    ~SynchronizedTimeBaseStatus() = default;

private:
    /// @brief Constructor that is available to SynchronizedTimeConsumer for construction of SynchronizedTimeBaseStatus
    /// for the purpose of providing Time with sync status - GetTimeWithStatus().
    SynchronizedTimeBaseStatus(const SynchronizationStatus& syncStatus, const Timestamp& creationTime)
        : syncStatus_(syncStatus)
        , creationTime_(creationTime)
    { }

    friend class SynchronizedTimeBaseConsumer;

    SynchronizationStatus syncStatus_;
    Timestamp creationTime_{Timestamp(std::chrono::nanoseconds::zero())};

    /// @brief LeapJump value.
    LeapJump leapJump_;
};

}  // namespace tsync
}  // namespace ara

#endif  // ARA_TSYNC_SYNCHRONIZED_TIME_BASE_STATUS_H_
