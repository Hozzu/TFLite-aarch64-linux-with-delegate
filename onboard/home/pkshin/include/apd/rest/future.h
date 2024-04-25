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

#ifndef LIB_APDREST_INCLUDE_APD_REST_FUTURE_H_
#define LIB_APDREST_INCLUDE_APD_REST_FUTURE_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <chrono>
#include <future>
#include <utility>

#include "apd/rest/types.h"

namespace apd
{
namespace rest
{

/**
 * \brief Operation status for timed wait functions
 */
enum class FutureStatus : uint8_t
{
    ready,
    timeout
};

/**
 * \brief ara::com specific Future
 */
template <typename T>
class Future
{
public:
    /** \brief Default constructor
     *
     */
    Future()
    { }
    /**
     * \brief Default constructor
     */
    explicit Future(std::future<T>&& delegate_future) noexcept
        : delegate_future_(std::move(delegate_future))
    { }

    /**
     * \brief Move constructor
     */
    Future(Future&&) noexcept = default;
    /**
     * \brief Default copy constructor deleted
     */
    Future(const Future&) = delete;
    /**
     * \brief Specialized unwrapping constructor
     */
    explicit Future(Future<Future<T>>&&) noexcept;
    /**
     * \brief Destructor
     */
    ~Future() = default;
    /**
     * \brief Move assignment operator
     */
    Future& operator=(Future&&) noexcept;
    /**
     * \brief Default copy assignment operator deleted
     */
    Future& operator=(const Future&) = delete;
    /**
     * \brief Returns the result
     */
    T get()
    {
        return delegate_future_.get();
    }
    /**
     * \brief Check if the Future has any shared state
     */
    bool valid() const noexcept
    {
        return delegate_future_.valid();
    }
    /**
     * \brief Block until the shared state is ready
     */
    void wait() const
    {
        delegate_future_.wait();
    }
    /**
     * \brief Wait for a specified relative time
     */
    template <class Rep, class Period>
    FutureStatus wait_for(const std::chrono::duration<Rep, Period>& timeout_duration) const
    {
        FutureStatus retval;
        auto f_stat = delegate_future_.wait_for(timeout_duration);
        if (std::future_status::ready == f_stat) {
            retval = FutureStatus::ready;
        } else if (std::future_status::timeout == f_stat) {
            retval = FutureStatus::timeout;
        }
        return retval;
    }
    /**
     * \brief Wait until a specified absolute time
     */
    template <class Clock, class Duration>
    FutureStatus wait_until(const std::chrono::time_point<Clock, Duration>& abs_time) const
    {
        FutureStatus retval;
        auto f_stat = delegate_future_.wait_until(abs_time);
        if (std::future_status::ready == f_stat) {
            retval = FutureStatus::ready;
        } else if (std::future_status::timeout == f_stat) {
            retval = FutureStatus::timeout;
        }
        return retval;
    }
    /**
     * \brief Set a continuation for when the shared state is ready
     */
    template <typename F>
    auto then(F&& func) -> Future<decltype(func(std::move(*this)))>;
    /**
     * \brief Return true only when the shared state is ready
     */
    bool is_ready() const;

private:
    std::future<T> delegate_future_;
};

}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_FUTURE_H_
