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

#ifndef ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_THREADSAFE_QUEUE_H_
#define ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_THREADSAFE_QUEUE_H_

#include <mutex>
#include <queue>

/// @brief Thread-safe queue
template <typename T>
class ThreadsafeQueue
{
public:
    /// @brief Pushes new value to queue and reports if
    ///        queue was empty before pushing
    /// @param new_value value to be pushed to queue
    /// @return true if queue was empty before push,
    ///         otherwise false
    bool empty_and_push(T new_value)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        auto isEmpty = dataQueue_.empty();
        dataQueue_.push(std::move(new_value));
        return isEmpty;
    }

    /// @brief Try to pop value from queue
    /// @param value refernce holding value if pop was
    ///        successful
    /// @return true if pop was successful, otherwise false
    bool try_pop(T& value)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        if (dataQueue_.empty())
            return false;
        value = std::move(dataQueue_.front());
        dataQueue_.pop();
        return true;
    }

    /// @brief Get current size of queue.
    ///
    /// @return size of queue
    size_t get_size() const
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return dataQueue_.size();
    }

    /// @brief Clear the queue.
    /// All elements the queue is currently holding are removed and destroyed
    void clear_queue()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        std::queue<T>().swap(dataQueue_);
    }

private:
    /// @brief data queue
    std::queue<T> dataQueue_;

    /// @brief Mutex for thread-safe access
    mutable std::mutex mutex_;
};

#endif  // ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_THREADSAFE_QUEUE_H_
