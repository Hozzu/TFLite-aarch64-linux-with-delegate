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
 * \brief General types used in ARA::COM API
 */

#ifndef COMMUNICATIONMIDDLEWARE_SAMPLE_PTR_H
#define COMMUNICATIONMIDDLEWARE_SAMPLE_PTR_H

#include <memory>
#include <functional>
#include <utility>
#include <cstddef>

#include "ara/com/e2e/e2e_types.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace proxy
{
template <typename>
class EventDataContainer;
}  // namespace proxy
}  // namespace internal

/**
 * \brief Pointer to a sample
 *
 * The semantics of a SamplePtr are the same as for an std::unique_ptr<T>.
 *
 * \note This implementation might be changed by product vendor.
 *
 * @uptrace{SWS_CM_00306, 85cf5642cdfeac228bb30e0d625cf9807dfb5ccd}
 */

template <typename T>
class SamplePtr
{
private:
    class Deleter
    {
    public:
        using Function = std::function<void(T*)>;

        Deleter()
            : f_([](T* ptr) { delete ptr; })
        { }

        explicit Deleter(const Function& f)
            : f_(f)
        { }

        void operator()(T* ptr) const
        {
            f_(ptr);
        }

    private:
        Function f_;
    };

    std::unique_ptr<T, Deleter> dataPtr_;
    ara::com::e2e::ProfileCheckStatus profileCheckStatus_;

    // Constructs a SamplePtr that owns ptr
    explicit SamplePtr(T* ptr) noexcept
        : dataPtr_(ptr)
    { }

    // Constructor that is invoked when the sample needs to be placed in the local cache
    SamplePtr(T* ptr,
        const typename Deleter::Function& deleteFunction,
        const ara::com::e2e::ProfileCheckStatus profileCheckStatus)
        : dataPtr_(ptr, Deleter(deleteFunction))
        , profileCheckStatus_(profileCheckStatus)
    { }

    template <typename>
    friend class internal::proxy::EventDataContainer;

    template <typename T1, typename... Args>
    friend SamplePtr<T1> make_sample_ptr(Args&&... args);

public:
    // Default constructor
    constexpr SamplePtr() noexcept
        : dataPtr_()
    { }

    // Semantically equivalent to Default constructor
    constexpr SamplePtr(std::nullptr_t) noexcept
        : SamplePtr()
    { }

    // Copy constructor is deleted
    SamplePtr(const SamplePtr& r) = delete;

    // Move constructor
    SamplePtr(SamplePtr&& r) noexcept
        : dataPtr_(std::move(r.dataPtr_))
        , profileCheckStatus_(std::move(r.profileCheckStatus_))
    { }

    // Copy assignment operator is deleted
    SamplePtr& operator=(const SamplePtr& r) = delete;

    // Assignment of nullptr_t
    SamplePtr& operator=(std::nullptr_t) noexcept
    {
        dataPtr_ = nullptr;
        return *this;
    }

    // Move assignment operator
    SamplePtr& operator=(SamplePtr&& r) noexcept
    {
        dataPtr_ = std::move(r.dataPtr_);
        profileCheckStatus_ = std::move(r.profileCheckStatus_);
        return *this;
    }

    // Dereferences the stored pointer
    T& operator*() const noexcept
    {
        return dataPtr_.operator*();
    }

    // Dereferences the stored pointer
    T* operator->() const noexcept
    {
        return dataPtr_.operator->();
    }

    // Checks if the stored pointer is null
    explicit operator bool() const noexcept
    {
        return bool(dataPtr_);
    }

    // Swaps the managed object
    void Swap(SamplePtr& other) noexcept
    {
        using std::swap;
        swap(dataPtr_, other.dataPtr_);
        swap(profileCheckStatus_, other.profileCheckStatus_);
    }

    // Replaces the managed object
    void Reset(std::nullptr_t) noexcept
    {
        dataPtr_.reset();
    }

    // Returns the stored object
    T* Get() const noexcept
    {
        return dataPtr_.get();
    }

    // Returns the E2E protection check result
    ara::com::e2e::ProfileCheckStatus GetProfileCheckStatus() const noexcept
    {
        return profileCheckStatus_;
    }
};

template <typename T, typename... Args>
SamplePtr<T> make_sample_ptr(Args&&... args)
{
    return SamplePtr<T>(new T(std::forward<Args>(args)...));
}

}  // namespace com
}  // namespace ara

#endif  // COMMUNICATIONMIDDLEWARE_SAMPLE_PTR_H
