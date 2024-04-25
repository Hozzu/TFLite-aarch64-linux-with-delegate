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
 * \file
 * \brief Provides a class that links data with a mutex.
 *
 * \details The class holds a mutex and the data it shall synchronize. If the data is to be accessed, the mutex is
 * locked and access
 * to the inner data is granted through a pointer-like object.
 */

#ifndef COMMUNICATIONMIDDLEWARE_MUTEX_WRAPPER_H
#define COMMUNICATIONMIDDLEWARE_MUTEX_WRAPPER_H

#include <mutex>
#include <cassert>
#include <functional>

namespace ara
{
namespace com
{
namespace internal
{
namespace common
{

/**
 * \defgroup aracomcommon aracom Commons
 *
 * \brief Common functionality that may be used throughout ara::com
 *
 * @{
 */

/**
 * \brief Wraps a mutex guard object and a reference to the synchronized inner data structure.
 * \tparam T Synchronized data structure.
 * \tparam M Mutex type to be used.
 */
template <typename T, typename M>
class LockedPtrWrapper
{
public:
    /**
     * \brief Constructs a valid guard wrapper using the provided inner type and the guard.
     *
     * It is expected that the guard is already in a locked state.
     *
     * \param inner Reference to the object managed by this guard wrapper.
     * \param guard RAII style mutex guard that is used to manage access to the inner data.
     */
    LockedPtrWrapper(T& inner, std::unique_lock<M>&& guard)
        : inner_(inner)
        , guard_(std::move(guard))
    {
        assert(guard_.owns_lock());
    }
    /**
     * \brief Move constructor.
     * \param other Object to move ownership from.
     */
    LockedPtrWrapper(LockedPtrWrapper&& other)
        : inner_(other.inner_)
        , guard_(std::move(other.guard_))
    { }
    LockedPtrWrapper(const LockedPtrWrapper& other) = delete;

    /**
     * \brief Move assignment.
     * \param other Object to move ownership from.
     * \return *this.
     */
    LockedPtrWrapper& operator=(LockedPtrWrapper&& other)
    {
        inner_ = other.inner_;
        guard_ = std::move(other.guard_);
        return *this;
    }

    LockedPtrWrapper& operator=(const LockedPtrWrapper& other) = delete;

    /**
     * \brief Arrow operator providing access to the contained data structure.
     *
     * The GuardWrapper has to have ownership of the lock. That is, it must not have been constructed/assigned from a
     * non-owning GuardWrapper and unlock() must not have been called.
     *
     * The returned pointer must not be stored to retain the invariants of the class.
     *
     * \return Pointer to inner object.
     */
    T* operator->()
    {
        assert(guard_.owns_lock());
        return &inner_.get();
    }
    /**
     * \brief Asterisk operator providing access to the contained data structure.
     *
     * The GuardWrapper has to have ownership of the lock. That is, it must not have been constructed/assigned from a
     * non-owning GuardWrapper and unlock() must not have been called.
     *
     * The returned reference must not live longer than the GuardWrapper to retain the invariants of the class.
     *
     * \return Reference to inner object.
     */
    T& operator*()
    {
        assert(guard_.owns_lock());
        return inner_.get();
    }

    /**
     * \brief Arrow operator providing access to the contained data structure.
     *
     * The GuardWrapper has to have ownership of the lock. That is, it must not have been constructed/assigned from a
     * non-owning GuardWrapper and unlock() must not have been called.
     *
     * The returned pointer must not be stored to retain the invariants of the class.
     *
     * \return Pointer to inner object.
     */
    const T* operator->() const
    {
        assert(guard_.owns_lock());
        return &inner_.get();
    }
    /**
     * \brief Asterisk operator providing access to the contained data structure.
     *
     * The GuardWrapper has to have ownership of the lock. That is, it must not have been constructed/assigned from a
     * non-owning GuardWrapper and unlock() must not have been called.
     *
     * The returned reference must not live longer than the GuardWrapper to retain the invariants of the class.
     *
     * \return Reference to inner object.
     */
    const T& operator*() const
    {
        assert(guard_.owns_lock());
        return inner_.get();
    }

    /**
     * \brief Release ownership of the lock.
     *
     * After having called this, the GuardWrapper must not be used anymore except reassigning another guard to it.
     */
    void unlock()
    {
        guard_.unlock();
    }

private:
    std::reference_wrapper<T> inner_;  ///< Pointer to inner object living inside a MutexWrapper.
    std::unique_lock<M> guard_;  ///< Guard managing the lock.
};

/**
 * \brief This class provides a wrapper around a data structure such that access is thread safe by managing an internal
 * lock.
 *
 * The inner data structure can be accessed by obtaining a pointer-like helper object that wraps a lock managing
 * the mutex associated with the data structure.
 *
 * Currently, moves or copies aren't supported.
 *
 * \tparam T Synchronized data structure.
 * \tparam M Mutex type to be used.
 * \tparam G Mutex guard to be used. Defaults to std::unique_lock.
 */
template <typename T, typename M>
class MutexWrapper
{
public:
    using LockedPtr = LockedPtrWrapper<T, M>;  ///< Proxy type that manages the associated lock.

    /**
     * \brief Constructor that constructs the inner data structure and an associated mutex.
     * \param args Arguments to provide to the constructor of the inner data structure.
     */
    template <typename... Args>
    explicit MutexWrapper(Args&&... args)
        : inner_(std::forward<Args>(args)...)
    { }

    MutexWrapper(const MutexWrapper&) = delete;
    MutexWrapper(MutexWrapper&&) = delete;
    MutexWrapper& operator=(const MutexWrapper&) = delete;
    MutexWrapper& operator=(MutexWrapper&&) = delete;

    /**
     * \brief Allows accessing the inner data structure through a returned proxy object.
     *
     * This proxy manages concurrent access by locking the associated mutex until the proxy object is destroyed or
     * unlock() is called. Thus, this operator may block until the mutex becomes available.
     *
     * \return Guard object with locked mutex.
     */
    LockedPtr Get()
    {
        return {inner_, std::unique_lock<M>(mutex_)};
    };

    /**
     * \brief Equivalent to \ref Get().
     * \return Guard object with locked mutex.
     */
    LockedPtr operator*()
    {
        return Get();
    }

private:
    T inner_;  ///< Inner data structure .
    M mutex_;  ///< Mutex that manages concurrent access of the data structure.
};

/** @}*/
}  // namespace common
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // COMMUNICATIONMIDDLEWARE_MUTEX_WRAPPER_H
