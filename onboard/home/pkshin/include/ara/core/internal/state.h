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
 */

#ifndef APD_ARA_CORE_INTERNAL_STATE_H
#define APD_ARA_CORE_INTERNAL_STATE_H

#include <memory>
#include <mutex>

namespace ara
{
namespace core
{
namespace internal
{
/**
 * @brief Class State maintains the action (Set, Get,Fire or Execute) on callback
 *
 * @private
 */
class State
{
public:
    typedef std::shared_ptr<State> Ptr;
    State()
    { }

    ~State()
    { }

    /**
     * @brief Executes the stored callback.
     *
     * @note The callback is never exposed outside this object so that no one may have a dangling pointer to the stored
     * callback.
     */
    void FireCallback()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        if (HasCallback_NoLock()) {
            callback_();
        }
    }

    /**
     * @brief Executes the stored callback without mutex lock.
     *
     * @note As the name suggests, this is a version which is not doing the mutex lock when running
     * callback.
     */
    void FireCallback_NoLock()
    {
        if (HasCallback_NoLock()) {
            callback_();
        }
    }

    /**
     * @brief Sets the callback.
     *
     * any callback that was set before is removed and replaced by the new callback.
     *
     * @param callback The callback to be set.
     */
    template <typename F>
    void SetCallback(F&& callback)
    {
        std::unique_lock<std::mutex> lock(mutex_);
        SetCallback_NoLock(std::forward<F>(callback));
    }

    /**
     * @brief Returns if a callback was set previously.
     *
     * @return true if a callback is set, false otherwise.
     */
    bool HasCallback()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        return HasCallback_NoLock();
    }

    /**
     * @brief Sets the callback.
     *
     * any callback that was set before is removed and replaced by the new callback.
     *
     * note A mutex lock should be set before calling this function
     * @param callback The callback to be set.
     */
    template <typename F>
    void SetCallback_NoLock(F&& callback)
    {
        callback_ = std::forward<F>(callback);
    }

private:
    /**
     * @brief Returns if a callback was set previously.
     *
     * @note This function assumes a mutex lock is already set
     * @return true if a callback is set, false otherwise.
     */
    bool HasCallback_NoLock() const
    {
        return static_cast<bool>(callback_);
    }

    std::function<void(void)> callback_;
    std::mutex mutex_;
};

} /* namespace internal */
} /* namespace core */
} /* namespace ara */

#endif /* APD_ARA_CORE_INTERNAL_STATE_H */
