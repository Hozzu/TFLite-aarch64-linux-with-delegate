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
 * \brief Class to construct a Event container
 */

#ifndef COMMUNICATIONMIDDLEWARE_EVENT_DATA_CONTAINER_H
#define COMMUNICATIONMIDDLEWARE_EVENT_DATA_CONTAINER_H

#include <cstdint>
#include <numeric>
#include <mutex>
#include <deque>

#include "ara/core/vector.h"

#include "ara/com/internal/definitions.h"
#include "ara/com/sample_ptr.h"
#include "ara/com/e2e/e2e_types.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace proxy
{

// A Wrapper Class intended for storing boolean values using Vector container
// intentionally does not provide a full set of accessors
// The main purpose is to support boolean values in EventDataContainer
class BoolEventDataWrapper
{
private:
    bool value_{false};

public:
    BoolEventDataWrapper& operator=(const bool& v)
    {
        value_ = v;
        return *this;
    }

    bool* operator&()
    {
        return &value_;
    }
};

template <typename T>
struct event_data_vector
{
    using type = ara::core::Vector<T>;
};

template <>
struct event_data_vector<bool>
{
    using type = ara::core::Vector<BoolEventDataWrapper>;
};

template <typename T>
using event_data_vector_t = typename event_data_vector<T>::type;

/**
 * \addtogroup frontendproxybase
 *
 * @{
 */

/**
 * \class EventDataContainer
 *
 * \brief Defines the event's data container.
 *
 * It can store a given number of data and can provide sample pointer to each of them.
 * If the pointer is destroyed the underlying piece of data is marked as rewritable.
 *
 */
template <typename T>
class EventDataContainer
{
private:
public:
    using const_reference = ConstBaseRef<T>;
    using value_type = BaseType<T>;
    using const_value_type = const value_type;

public:
    void Reserve(size_t size)
    {
        std::lock_guard<std::mutex> guard(lock_);

        data_.resize(size);
        empty_nodes_.resize(size);

        // Initially all nodes are not occupied by data
        std::iota(empty_nodes_.begin(), empty_nodes_.end(), 0);
    }

    /// @uptrace{SWS_CM_00707, 4b2f0ab663f533d8c96336bf1d6b69b9ebe85866}
    SamplePtr<const value_type> Add(const_reference sample, const ara::com::e2e::ProfileCheckStatus profileCheckStatus)
    {
        std::lock_guard<std::mutex> guard(lock_);

        if (empty_nodes_.empty()) {
            return SamplePtr<const value_type>();
        }

        size_t index = *empty_nodes_.begin();
        empty_nodes_.pop_front();
        data_[index] = sample;

        return SamplePtr<const value_type>(
            &data_[index], [this, index](const_value_type* obj) { Remove(index); }, profileCheckStatus);
    }

    size_t AvailableSize()
    {
        std::lock_guard<std::mutex> guard(lock_);

        return empty_nodes_.size();
    }

private:
    std::deque<size_t> empty_nodes_;
    event_data_vector_t<value_type> data_;
    std::mutex lock_;

    void Remove(int index)
    {
        std::lock_guard<std::mutex> guard(lock_);

        empty_nodes_.push_back(index);
    }
};

/**
 * @}
 */

}  // namespace proxy
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // COMMUNICATIONMIDDLEWARE_EVENT_DATA_CONTAINER_H
