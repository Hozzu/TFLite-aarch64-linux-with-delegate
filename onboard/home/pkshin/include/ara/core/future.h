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

/**
 * @file
 * @brief Interface to class ara::core::Future
 *
 * ara::core::Future is a composition of basic features of std::future
 * and methods borrowed from the C++ proposal N3857.
 */

#ifndef APD_ARA_CORE_FUTURE_HPP_
#define APD_ARA_CORE_FUTURE_HPP_

#include <chrono>
#include <future>
#include <system_error>
#include <cassert>

#include "ara/core/future_error_domain.h"
#include "ara/core/error_code.h"
#include "ara/core/result.h"
#include "ara/core/core_error_domain.h"
#include "ara/core/exception.h"
#include "internal/state.h"

#if !defined(ATTR_NODISCARD)
#    if __cplusplus >= 201703L
#        define ar_attribute_nodiscard [[nodiscard]]
#    else
#        if defined(__GNUC__) || defined(__clang__)
#            define ar_attribute_nodiscard __attribute__((warn_unused_result))
#        else
#            define ar_attribute_nodiscard /* nothing */
#        endif
#    endif
#    define ATTR_NODISCARD ar_attribute_nodiscard
#endif

namespace ara
{
namespace core
{

/* Forward declaration */
template <typename, typename>
class Promise;

/**
 * @brief Specifies the state of a Future as returned by wait_for() and wait_until().
 *
 * These definitions are equivalent to the ones from std::future_status. However, the
 * item std::future_status::deferred is not supported here.
 *
 * @uptrace{SWS_CORE_00361, 217b721919fb6c9d5a89b330e5792efc13d26c2e}
 */
enum class future_status : uint8_t
{
    ready = 1,  ///< the shared state is ready
    timeout,  ///< the shared state did not become ready before the specified timeout has passed
};

inline std::ostream& operator<<(std::ostream& out, FutureException const& ex)
{
    return (out << "FutureException: " << ex.Error() << " (" << ex.what() << ")");
}

/**
 * @brief Provides ara::core specific Future operations to collect the results of an asynchronous call.
 *
 * Much of its functionality is delegated to std::future and all methods that resemble std::future are guaranteed to
 * behave the same.
 *
 * If the valid() member function of an instance returns true, all other methods are guaranteed to work on that
 * instance. Otherwise, they may fail with or without an exception. A thrown exception will be of type
 * std::future_error.
 *
 * Having an invalid future will usually happen when the future was moved from using the move constructor or move
 * assignment.
 *
 * @uptrace{SWS_CORE_00321, 57d51609e3c5ef69e671f664a30b56e55e9eda6e}
 */
template <typename T, typename E = ErrorCode>
class Future final
{
    using R = Result<T, E>;

    using Lock = std::unique_lock<std::mutex>;

public:
    /// Alias type for T
    using ValueType = T;
    /// Alias type for the Promise type collaborating with this Future type
    using PromiseType = Promise<T, E>;

    /**
     * @brief Default constructor
     *
     * @uptrace{SWS_CORE_00322, 17264a4134a43d1afc39ee5c563e1dcf241530ce}
     */
    Future() noexcept = default;

    /**
     * @brief Destructor for Future objects
     *
     * This will also disable any callback that has been set.
     *
     * @uptrace{SWS_CORE_00333}
     */
    ~Future()
    {
        Lock lock(mutex_);

        if (extra_state_) {
            extra_state_->SetCallback(nullptr);
        }
    }

    /// @uptrace{SWS_CORE_00334, 5db38a096493a9a60b4a66b3c0130185dcb7f81b}
    Future(Future const&) = delete;

    /// @uptrace{SWS_CORE_00335, 53ac5754497537a1d3bacedd3c3b310aead221f6}
    Future& operator=(Future const&) = delete;

    /**
     * @uptrace{SWS_CORE_00323, 48c6d46c350b7d231e3ae40ffd5f043df631a427}
     */
    Future(Future&& other) noexcept
        : lock_(other.mutex_)
        , delegate_future_(std::move(other.delegate_future_))
        , extra_state_(std::move(other.extra_state_))
    {
        lock_.unlock();
    }

    /**
     * @uptrace{SWS_CORE_00325, 0c47307d973b035f4bfc51972a1d49045ac222e0}
     */
    Future& operator=(Future&& other) noexcept
    {
        if (this != &other) {
            Lock lhsLock(mutex_, std::defer_lock);
            Lock rhsLock(other.mutex_, std::defer_lock);
            std::lock(lhsLock, rhsLock);

            delegate_future_ = std::move(other.delegate_future_);
            extra_state_ = std::move(other.extra_state_);
        }
        return *this;
    }

    // Stop defining noexcept in order to let other exception be propageted to upper levels and fix some crashes
    /// @uptrace{SWS_CORE_00336, 0000000000000000000000000000000000000000}
    ATTR_NODISCARD R GetResult()
    {
#ifndef ARA_NO_EXCEPTIONS
        try {
            return delegate_future_.get();
        } catch (std::future_error const& ex) {
            std::error_code const& ec = ex.code();
            future_errc err;
            if (ec == std::future_errc::broken_promise) {
                err = future_errc::broken_promise;
            } else if (ec == std::future_errc::future_already_retrieved) {
                err = future_errc::future_already_retrieved;
            } else if (ec == std::future_errc::promise_already_satisfied) {
                err = future_errc::promise_already_satisfied;
            } else if (ec == std::future_errc::no_state) {
                err = future_errc::no_state;
            } else {
                // Should rather use a vendor/demonstrator-specific ErrorDomain here?
                return R::FromError(CoreErrc::kInvalidArgument);
            }
            R r = R::FromError(err);
            return r;
        }
#else
        // TODO: Somehow query the future object whether it contains an exception,
        // and if so, translate it into a Result<...>
        // This does not seem possible with C++14's std::future, because it lacks boost::future's
        // has_exception() method. Unfortunately, boost::future cannot be compiled with
        // -fno-exceptions, so that one is out as well.
        return delegate_future_.get();
#endif
    }

#ifndef ARA_NO_EXCEPTIONS
    /**
     * @brief Get the value.
     *
     * This call blocks until the result or an exception is available.
     *
     * @returns value of type T
     *
     * @uptrace{SWS_CORE_00326, da9e7863c13d930e324a59e04b1ef75f76871fb2}
     */
    T get()
    {
        return GetResult().ValueOrThrow();
    }
#endif

    /**
     * @brief Checks if the future is valid, i.e. if it has a shared state.
     *
     * @returns true if the future is usable, false otherwise
     *
     * @uptrace{SWS_CORE_00327, b12b6ab4d0b48025e316108f7a275708b8addb52}
     */
    bool valid() const noexcept
    {
        return delegate_future_.valid();
    }

    /**
     * @brief Waits for a value or an exception to be available.
     *
     * After this method returns, get() is guaranteed to not block and is_ready() will return true.
     *
     * @uptrace{SWS_CORE_00328, cbac36d05ef1e0101026410261beddc3c9cc9d35}
     */
    void wait() const
    {
        delegate_future_.wait();
    }

    /**
     * @brief Wait for the given period.
     *
     * If the Future becomes ready or the timeout is reached, the method returns.
     *
     * @param timeout_duration maximal duration to wait for
     * @returns status that indicates whether the timeout hit or if a value is available
     *
     * @uptrace{SWS_CORE_00329, 99961998f9f93f857b6c7369f12c1e9a1a1e82e0}
     */
    template <typename Rep, typename Period>
    future_status wait_for(std::chrono::duration<Rep, Period> const& timeout_duration) const
    {
        switch (delegate_future_.wait_for(timeout_duration)) {
        case std::future_status::ready:
            return future_status::ready;
        case std::future_status::timeout:
            return future_status::timeout;
        default:
            assert(!"this std::future_status should not occur in our setup");
        }
    }

    /**
     * @brief Wait until the given time.
     *
     * If the Future becomes ready or the time is reached, the method returns.
     *
     * @param deadline latest point in time to wait
     * @returns status that indicates whether the time was reached or if a value is available
     *
     * @uptrace{SWS_CORE_00330, bb116c9f4d0e03491372ff50d2705798e4c4d5d4}
     */
    template <typename Clock, typename Duration>
    future_status wait_until(std::chrono::time_point<Clock, Duration> const& deadline) const
    {
        switch (delegate_future_.wait_until(deadline)) {
        case std::future_status::ready:
            return future_status::ready;
        case std::future_status::timeout:
            return future_status::timeout;
        default:
            assert(!"this std::future_status should not occur in our setup");
        }
    }

    /**
     * @brief Register a function that gets called when the future becomes ready.
     *
     * When @a func is called, it is guaranteed that get() will not block.
     *
     * @a func may be called in the context of this call or in the context of Promise::set_value()
     * or Promise::set_exception() or somewhere else.
     *
     * @param func a Callable to register to get the Future result or an exception
     *
     * @uptrace{SWS_CORE_00331, 0000000000000000000000000000000000000000}
     */
    template <typename F>
    void then(F&& func)
    {
        Lock lock(mutex_);

        extra_state_->SetCallback_NoLock(std::forward<F>(func));
        if (is_ready()) {
            extra_state_->FireCallback_NoLock();
        }
    }

    /**
     * True when the future contains either a result or an exception.
     *
     * If is_ready() returns true, get() and the wait calls are guaranteed to not block.
     *
     * @returns true if the Future contains data, false otherwise
     *
     * @uptrace{SWS_CORE_00332, 770c91fdfc7ec430908c5a292d9ff31db9f75b99}
     */
    bool is_ready() const
    {
        return std::future_status::ready == delegate_future_.wait_for(std::chrono::seconds::zero());
    }

private:
    /**
     * @brief Constructs a Future from a given std::future and a pointer to the extra state.
     *
     * @param delegate_future std::future instance
     * @param extra_state state that is shared with the Promise
     */
    Future(std::future<R>&& delegate_future, internal::State::Ptr extra_state)
        : delegate_future_(std::move(delegate_future))
        , extra_state_(extra_state)
    { }

    std::mutex mutex_;
    Lock lock_;  // this Lock is only necessary for the move constructor

    std::future<R> delegate_future_;
    internal::State::Ptr extra_state_;

    template <typename, typename>
    friend class Promise;
};

/// @brief Specialization of class Future for "void" values
/// @tparam E  the type of error
///
/// @uptrace{SWS_CORE_06221, 6b3dbc886bd27f701520b327007dbd5d92beb544}
template <typename E>
class Future<void, E> final
{
    using R = Result<void, E>;

    using Lock = std::unique_lock<std::mutex>;

public:
    /// Alias type for T
    using ValueType = void;
    /// Alias type for the Promise type collaborating with this Future type
    using PromiseType = Promise<void, E>;
    /// Alias type for the future_status type
    using Status = future_status;

    /// @uptrace{SWS_CORE_06222, 64d2479891b3647c979828e26798c321ae173068}
    Future() noexcept = default;

    /// @uptrace{SWS_CORE_06233, c2f010cb39114a1c99b846862f0007542f9b2d02}
    ~Future()
    {
        Lock lock(mutex_);

        if (extra_state_) {
            extra_state_->SetCallback(nullptr);
        }
    }

    /// @uptrace{SWS_CORE_06234, cb6a6c4b094559af88448ff516a88f69d46d9a78}
    Future(Future const&) = delete;

    /// @uptrace{SWS_CORE_06235, 3ff39414bfc3f839e82cf982cc433575d9e6af99}
    Future& operator=(Future const&) = delete;

    /// @uptrace{SWS_CORE_06223, 0507273744b85e446f1c29256bbbb608e3dfee37}
    Future(Future&& other) noexcept
        : lock_(other.mutex_)
        , delegate_future_(std::move(other.delegate_future_))
        , extra_state_(std::move(other.extra_state_))
    {
        lock_.unlock();
    }

    /// @uptrace{SWS_CORE_06225, 4b88cdf79518f88e75627970a9e5d01266ed87f8}
    Future& operator=(Future&& other) noexcept
    {
        if (this != &other) {
            Lock lhsLock(mutex_, std::defer_lock);
            Lock rhsLock(other.mutex_, std::defer_lock);
            std::lock(lhsLock, rhsLock);

            delegate_future_ = std::move(other.delegate_future_);
            extra_state_ = std::move(other.extra_state_);
        }
        return *this;
    }

#ifndef ARA_NO_EXCEPTIONS
    /// @uptrace{SWS_CORE_06226, acd77102eb4efed22a0206aea6af280e2599f462}
    void get()
    {
        return GetResult().ValueOrThrow();
    }
#endif

    /// @uptrace{SWS_CORE_06236, bcb54cd72652ce3fc9426e0c40277dd495a52327}
    ATTR_NODISCARD Result<void, E> GetResult() noexcept
    {
#ifndef ARA_NO_EXCEPTIONS
        try {
            return delegate_future_.get();
        } catch (std::future_error const& ex) {
            std::error_code const& ec = ex.code();
            future_errc err;
            if (ec == std::future_errc::broken_promise) {
                err = future_errc::broken_promise;
            } else if (ec == std::future_errc::future_already_retrieved) {
                err = future_errc::future_already_retrieved;
            } else if (ec == std::future_errc::promise_already_satisfied) {
                err = future_errc::promise_already_satisfied;
            } else if (ec == std::future_errc::no_state) {
                err = future_errc::no_state;
            } else {
                // Should rather use a vendor/demonstrator-specific ErrorDomain here?
                return R::FromError(CoreErrc::kInvalidArgument);
            }
            R r = R::FromError(err);
            return r;
        }
#else
        return delegate_future_.get();
#endif
    }

    /// @uptrace{SWS_CORE_06227, 876d738210854afa73924bd7117401f9aaaa41ef}
    bool valid() const noexcept
    {
        return delegate_future_.valid();
    }

    /// @uptrace{SWS_CORE_06228, df908a242ca4058ab18cea66c74fc2aba860f68d}
    void wait() const
    {
        delegate_future_.wait();
    }

    /// @uptrace{SWS_CORE_06229, be9a2393411de3a89afd361deb3c0f2b24c555c5}
    template <typename Rep, typename Period>
    future_status wait_for(std::chrono::duration<Rep, Period> const& timeoutDuration) const
    {
        switch (delegate_future_.wait_for(timeoutDuration)) {
        case std::future_status::ready:
            return future_status::ready;
        case std::future_status::timeout:
            return future_status::timeout;
        default:
            assert(!"this std::future_status should not occur in our setup");
        }
    }

    /// @uptrace{SWS_CORE_06230, 3bf7946725773942c6f2928af9defa37633dd08c}
    template <typename Clock, typename Duration>
    future_status wait_until(std::chrono::time_point<Clock, Duration> const& deadline) const
    {
        switch (delegate_future_.wait_until(deadline)) {
        case std::future_status::ready:
            return future_status::ready;
        case std::future_status::timeout:
            return future_status::timeout;
        default:
            assert(!"this std::future_status should not occur in our setup");
        }
    }

    // not yet implemented, because the current general implementation above is nonsense anyway
    // @uptrace{SWS_CORE_06231, 0000000000000000000000000000000000000000}
    // template <typename F>
    // auto then(F&& func) -> Future<SEE_BELOW>;

    /// @uptrace{SWS_CORE_06232, a59ae4b24aa36e4045ef6c1823309fa82c35fe0a}
    bool is_ready() const
    {
        return std::future_status::ready == delegate_future_.wait_for(std::chrono::seconds::zero());
    }

private:
    Future(std::future<R>&& delegate_future, internal::State::Ptr extra_state)
        : delegate_future_(std::move(delegate_future))
        , extra_state_(extra_state)
    { }

    std::mutex mutex_;
    Lock lock_;  // this Lock is only necessary for the move constructor

    std::future<R> delegate_future_;
    internal::State::Ptr extra_state_;

    template <typename, typename>
    friend class Promise;
};

}  // namespace core
}  // namespace ara

#endif  // APD_ARA_CORE_FUTURE_HPP_
