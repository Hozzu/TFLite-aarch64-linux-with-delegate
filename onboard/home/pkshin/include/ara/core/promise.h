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

/// @file
/// @brief Interface to class ara::core::Promise
///
/// ara::core::Future is a composition of basic features of std::future
/// and methods borrowed from the C++ proposal N3857.
///
/// ara::core::Promise is the corresponding promise that returns an ara::core::Future.

#ifndef APD_ARA_CORE_PROMISE_HPP_
#define APD_ARA_CORE_PROMISE_HPP_

#include <exception>
#include <future>
#include <mutex>
#include <system_error>

#include "internal/state.h"
#include "ara/core/error_code.h"
#include "ara/core/result.h"
#include "future.h"

namespace ara
{
namespace core
{

/// @brief ara::core specific variant of std::promise class
///
/// @uptrace{SWS_CORE_00340, de2250e1e2e2d253de116655c2b051fadd3abf24}
template <typename T, typename E = ErrorCode>
class Promise final
{
    using R = Result<T, E>;

    using Lock = std::unique_lock<std::mutex>;

public:
    /// @uptrace{SWS_CORE_00341, 05dd98c2e125337cbe601e0633df6c58b9ea51ba}
    Promise()
        : extra_state_(std::make_shared<internal::State>())
    { }

    /// @uptrace{SWS_CORE_00349, 5bde75900a71da7c1471ddc274710fc2d012a98e}
    ~Promise()
    { }

    /// @uptrace{SWS_CORE_00350, 775e318b5cb72caec5fd88ac760906297ca6a950}
    Promise(Promise const&) = delete;

    /// @uptrace{SWS_CORE_00351, 776c5c75e5781f443a49c857667ee595695b52cd}
    Promise& operator=(Promise const&) = delete;

    /// @uptrace{SWS_CORE_00342, fdf2e7f1468b08566d40d4a6fb0c04629d9e4a05}
    Promise(Promise&& other) noexcept
        : lock_(other.mutex_)
        , delegate_promise_(std::move(other.delegate_promise_))
        , extra_state_(std::move(other.extra_state_))
    {
        lock_.unlock();
    }

    /// @uptrace{SWS_CORE_00343, 3478ac91c7688826504f22a833e912dd57d833aa}
    Promise& operator=(Promise&& other) noexcept
    {
        if (this != &other) {
            Lock lhsLock(mutex_, std::defer_lock);
            Lock rhsLock(other.mutex_, std::defer_lock);
            std::lock(lhsLock, rhsLock);

            delegate_promise_ = std::move(other.delegate_promise_);
            extra_state_ = std::move(other.extra_state_);
        }
        return *this;
    }

    /// @uptrace{SWS_CORE_00352, 862a0e36d42f8e9b7377ac0fff1f4ba16bff4a43}
    void swap(Promise& other) noexcept
    {
        Lock lhsLock(mutex_, std::defer_lock);
        Lock rhsLock(other.mutex_, std::defer_lock);
        std::lock(lhsLock, rhsLock);

        using std::swap;
        swap(delegate_promise_, other.delegate_promise_);
        swap(extra_state_, other.extra_state_);
    }

    /// @brief Returns an associated Future for type T.
    ///
    /// The returned Future is set as soon as this Promise receives the result or an exception. This method must only be
    /// called once as it is not allowed to have multiple Futures per Promise.
    ///
    /// @returns a Future for type T
    ///
    /// @uptrace{SWS_CORE_00344, 805c1c8e2451e44df817380902511a553b4b6fdf}
    Future<T, E> get_future()
    {
        return Future<T, E>(delegate_promise_.get_future(), extra_state_);
    }

    /// @uptrace{SWS_CORE_00353, a86b858a2d05b93880736845df10dd6c38f13637}
    void SetError(E&& err)
    {
        R r = R::FromError(std::move(err));
        SetResult(std::move(r));
    }

    /// @uptrace{SWS_CORE_00354, cd5e02b81298a08e3314331c7dcaeeea9479dfe4}
    void SetError(E const& err)
    {
        R r = R::FromError(err);
        SetResult(r);
    }

    /// @uptrace{SWS_CORE_00355, b215ce72f174c0448e4ed4261ecb7e639ab4bea7}
    void SetResult(const Result<T, E>& result)
    {
        Lock lock(mutex_);

        delegate_promise_.set_value(result);
        extra_state_->FireCallback_NoLock();
    }

    /// @uptrace{SWS_CORE_00356, efaa567921e1c63a80348ceaa4ae826813a97a3c}
    void SetResult(Result<T, E>&& result)
    {
        Lock lock(mutex_);

        delegate_promise_.set_value(std::move(result));
        extra_state_->FireCallback_NoLock();
    }

    /// @brief Sets an exception.
    ///
    /// Calling Get() on the associated Future will rethrow the exception in the context the Future's method was
    /// called
    /// in.
    ///
    /// @param p exception_ptr to set
    ///
    /// @note This method is DEPRECATED. The exception is defined by the error code.
    void set_exception(std::exception_ptr p)
    {
        Lock lock(mutex_);

        delegate_promise_.set_exception(p);
        extra_state_->FireCallback_NoLock();
    }

    /// @brief Move the result into the future.
    ///
    /// @param value the value to store
    ///
    /// @uptrace{SWS_CORE_00346, 85154d95cfed6935ffd784dd1794fc6dbff72121}
    void set_value(T&& value)
    {
        R r = std::move(value);
        SetResult(std::move(r));
    }

    /// @brief Copy result into the future.
    ///
    /// @param value the value to store
    ///
    /// @uptrace{SWS_CORE_00345, c89fbbc4db278ee44a25552a56d6e9afd07d093f}
    void set_value(T const& value)
    {
        R r = value;
        SetResult(r);
    }

private:
    std::mutex mutex_;
    Lock lock_;  // this Lock is only necessary for the move constructor

    std::promise<R> delegate_promise_;
    internal::State::Ptr extra_state_;
};

/// @brief Specialization of class Promise for "void" values
/// @tparam E  the type of error
///
/// @uptrace{SWS_CORE_06340, 81ff657eaeb850c423d483a349e208d8d4ba14ca}
template <typename E>
class Promise<void, E> final
{
    using R = Result<void, E>;

    using Lock = std::unique_lock<std::mutex>;

public:
    /// @uptrace{SWS_CORE_06341, a58318948120d498df1a2f69096b642bbd6bf751}
    Promise()
        : extra_state_(std::make_shared<internal::State>())
    { }

    /// @uptrace{SWS_CORE_06350, 3b1ea950cec04838d2b254d1761afd1984a598f7}
    Promise(Promise const&) = delete;

    /// @uptrace{SWS_CORE_06342, 0835a228e32d78636c76043ca74e7b2c6920dad6}
    Promise(Promise&& other) noexcept
        : lock_(other.mutex_)
        , delegate_promise_(std::move(other.delegate_promise_))
        , extra_state_(std::move(other.extra_state_))
    {
        lock_.unlock();
    }

    /// @uptrace{SWS_CORE_06349, 1948fa80fd6c721e40dd571b48b9a5f4dbfdc7cd}
    ~Promise()
    { }

    /// @uptrace{SWS_CORE_06351, 71be553159d0bcb484cdf7caeff3888ff0a73c02}
    Promise& operator=(Promise const&) = delete;

    /// @uptrace{SWS_CORE_06343, 2bc80bce18c526fa7aad8c8a3bbfdebd6baa7f7c}
    Promise& operator=(Promise&& other) noexcept
    {
        if (this != &other) {
            Lock lhsLock(mutex_, std::defer_lock);
            Lock rhsLock(other.mutex_, std::defer_lock);
            std::lock(lhsLock, rhsLock);

            delegate_promise_ = std::move(other.delegate_promise_);
            extra_state_ = std::move(other.extra_state_);
        }
        return *this;
    }

    /// @uptrace{SWS_CORE_06352, dccb5c36919458717b06771d56a95dc0363f02a4}
    void swap(Promise& other) noexcept
    {
        Lock lhsLock(mutex_, std::defer_lock);
        Lock rhsLock(other.mutex_, std::defer_lock);
        std::lock(lhsLock, rhsLock);

        using std::swap;
        swap(delegate_promise_, other.delegate_promise_);
        swap(extra_state_, other.extra_state_);
    }

    /// @uptrace{SWS_CORE_06344, 74ba5700ce49a412a7a5349d3f1d5dc4f5ef0222}
    Future<void, E> get_future()
    {
        return Future<void, E>(delegate_promise_.get_future(), extra_state_);
    }

    /// @uptrace{SWS_CORE_06345, 9f242eecdd187c3414719c9969b403e994d83398}
    void set_value()
    {
        R r = R::FromValue();
        SetResult(std::move(r));
    }

    /// @uptrace{SWS_CORE_06353, 59292a8fe954683736e674a796edd50529d10149}
    void SetError(E&& err)
    {
        R r = R::FromError(std::move(err));
        SetResult(std::move(r));
    }

    /// @uptrace{SWS_CORE_06354, b178b1465cd7f362d97abfd95596a7c35ef0a79a}
    void SetError(E const& err)
    {
        R r = R::FromError(err);
        SetResult(r);
    }

    /// @uptrace{SWS_CORE_06355, 613f5f1ac5e848750ce26b561ef23fb14c808645}
    void SetResult(const Result<void, E>& result)
    {
        Lock lock(mutex_);

        delegate_promise_.set_value(result);
        extra_state_->FireCallback_NoLock();
    }

    /// @uptrace{SWS_CORE_06356, 6cdfcb4360b67a6026eb846117e403d4af3d4a68}
    void SetResult(Result<void, E>&& result)
    {
        Lock lock(mutex_);

        delegate_promise_.set_value(std::move(result));
        extra_state_->FireCallback_NoLock();
    }

    // unspecified, remove this!
    void set_exception(std::exception_ptr p)
    {
        Lock lock(mutex_);

        delegate_promise_.set_exception(p);
        extra_state_->FireCallback_NoLock();
    }

private:
    std::mutex mutex_;
    Lock lock_;  // this Lock is only necessary for the move constructor

    std::promise<R> delegate_promise_;
    internal::State::Ptr extra_state_;
};

}  // namespace core
}  // namespace ara

#endif  // APD_ARA_CORE_PROMISE_HPP_
