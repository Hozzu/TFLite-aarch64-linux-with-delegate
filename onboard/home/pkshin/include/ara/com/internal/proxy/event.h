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
 * \brief Test
 */

#ifndef ARA_COM_PROXY_EVENT_H
#define ARA_COM_PROXY_EVENT_H

#include "ara/com/types.h"
#include "event_base.h"
#include "event_data_container.h"
#include <ara/com/internal/e2e/is_e2e_enabled.h>
#include "ara/com/e2e/e2e_types.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace proxy
{

/**
 * \addtogroup frontendproxybase
 *
 * @{
 */

/**
 * \class Event
 *
 * \brief Defines the typed interface of all event elements on proxy side.
 *
 * Implementations of this interface have an internal cache that holds actual values to the current set of data the
 * application may work on. This set can be accessed via sample pointers created by \ref GetNewSamples().
 * It will change this data set by updating the cache with new values that were received from the communications
 * partner.
 *
 * One parameter exist to tune the cache:
 * - Cache size
 *
 *   This parameter determines a count N that sets a maximum number of packages that are held inside the cache at a
 *   given time.
 *
 */
template <typename T, bool E2E = ara::com::internal::e2e::is_e2e_enabled<T>::value>
class Event : public virtual bits::EventBase
{
public:
    using const_reference = ConstBaseRef<T>;
    using value_type = BaseType<T>;
    using const_value_type = const BaseType<T>;

    using container_type = EventDataContainer<ara::com::SamplePtr<T>>;
    using container_value_type = typename container_type::value_type;

    using pointer_type = SamplePtr<T>;
    using const_pointer_type = SamplePtr<const T>;
    using SampleType = value_type;
    /// @uptrace{SWS_CM_00702, c27a0ff50103e20664d46b367de06b720d5f5994}
    using NewSamplesCallback = std::function<void(const_pointer_type)>;

    Event() = default;
    Event(const Event& e) = delete;
    Event(Event&& e) = delete;
    Event& operator=(const Event& e) = delete;
    Event& operator=(Event&& e) = delete;

    virtual ~Event()
    { }

    /// @brief Update the event cache with newly received data samples
    ///
    /// @param f Callback to call on each new data sample
    /// @param maxNumberOfSamples max number of samples to fetch with this call of GetNewSamples()
    /// @return ara::core::Result containing number of data samples passed to f or
    /// ara::core::ErrorCode::kMaxSamplesReached in case of maxSampleCount of samples were reached in event cache
    ///
    /// @uptrace{SWS_CM_00701, d32ab6ff0ba8ee038f6ee578fe05d666cde6e2c6}
    /// @uptrace{SWS_CM_00704, 9155c846685608ed3dc0c62076d0b5d20ee81ef8}
    virtual ara::core::Result<size_t> GetNewSamples(NewSamplesCallback&& f,
        size_t maxNumberOfSamples = std::numeric_limits<size_t>::max())
        = 0;

    /// @brief Get number of free data slots in internal cache
    ///
    /// @return size_t number of free slots
    ///
    /// @uptrace{SWS_CM_00705, 0c4f947931c51b8f81d4eefa504425b336752ade}
    /// @uptrace{SWS_CM_00706, d1f8027ac08f37fac3c7ddfcff3beeb7ad271dd1}
    /// @uptrace{SWS_CM_11024, 12a44e6ea67f12da64edc5210e94d3c5ee51cfa3}
    virtual size_t GetFreeSampleCount() = 0;

    /// @uptrace{SWS_CM_90424, 5f3bada774cf5db0a00b3ed572a862f1e022e068}
    template <typename U = T, typename = std::enable_if_t<E2E, U>>
    ara::com::e2e::Result GetResult() const noexcept
    {
        return DoCheckResult();
    }

    /// @uptrace{SWS_CM_10475, 77ac264cdae2e7743b83eea01f8fc73a85b526a8}
    /// @uptrace{SWS_CM_90431, 33b9091dcd4b23ffbc08c8be59b913e34c7a6ea2}
    template <typename U = T, typename = std::enable_if_t<E2E, U>>
    ara::com::e2e::SMState GetSMState() const noexcept
    {
        return DoCheckSMState();
    }

protected:
    virtual ara::com::e2e::Result DoCheckResult() const noexcept
    {
        return ara::com::e2e::Result{};
    }

    virtual ara::com::e2e::SMState DoCheckSMState() const noexcept
    {
        return ara::com::e2e::SMState{};
    }
};

/**
 * @}
 */

}  // namespace proxy
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_PROXY_EVENT_H
