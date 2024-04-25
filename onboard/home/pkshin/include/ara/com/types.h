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
 *
 * The ARA::COM API uses certain specific types in its standardized proxy-/skeleton and runtime interfaces. The idea
 * here is that the API only expects a certain behaviour/interfaces of those types. ARA:COM does NOT fully
 * define/implement those types.
 *
 */

/**
 * @brief General types used in ARA::COM API.
 */

#ifndef ARA_COM_TYPES_H
#define ARA_COM_TYPES_H

#include <functional>
#include <memory>
#include "ara/core/vector.h"

#include "sample_ptr.h"
#include "internal/proxy/event_data_container.h"
#include "ara/com/instance_identifier.h"

namespace ara
{
namespace com
{

/**
 * @defgroup commontypes Common types
 *
 * @brief Defines common types used throughout ara::com.
 *
 * These types are either strictly defined by the specification or they are at least constrained since the're exposed
 * to the application developer and thus are part of the API.
 *
 * @{
 */

// Forward declaration of ara::com::internal::proxy::ProxyFactory so that we can
// declare the callback function below.
namespace internal
{
namespace proxy
{

class ProxyFactory;
}
}  // namespace internal

/**
 * @brief Method call processing modes for the service implementation side (skeleton).
 *
 * @uptrace{SWS_CM_00301, e89274588bcbcfe30899498f982624f776b46fda}
 */
enum class MethodCallProcessingMode
{
    kPoll,
    kEvent,
    kEventSingleThread
};

/**
 * @brief Identifier for a triggered FindService request.
 *
 * This identifier is needed to later cancel the FindService request.
 *
 * @uptrace{SWS_CM_00303, 74731364104a5921eb782e7e2f78c97f58f6d07f}
 */
struct FindServiceHandle
{
    FindServiceHandle()
        : instance_id{InstanceIdentifier::MakeAny()}
    { }

    FindServiceHandle(internal::ServiceId srvc_id, ara::com::InstanceIdentifier instnc_id, std::uint32_t id)
        : service_id{srvc_id}
        , instance_id{instnc_id}
        , uid{id}
    { }

    internal::ServiceId service_id;
    ara::com::InstanceIdentifier instance_id;
    std::uint32_t uid;
};

/**
 * Container for a list of service handles.
 *
 * @see ara::com::FindService
 *
 * @uptrace{SWS_CM_00304, a7102bff2fcb74d867526a0d8453553a44093f95}
 */
template <typename Handle>
using ServiceHandleContainer = ara::core::Vector<Handle>;

/**
 * @brief Definition of the subscription state of an Event.
 *
 * @uptrace{SWS_CM_00310, 3ba05e291006b0aa49d2ba952b4c01e3fb5aa429}
 */
enum class SubscriptionState
{
    kSubscribed,
    kNotSubscribed,
    kSubscriptionPending
};

/**
 * @brief Receive handler method, which is semantically a void(void) function.
 *
 * @uptrace{SWS_CM_00309, 8a0cb42b9da93e91a92c5276a6575d3cec747f17}
 */
using EventReceiveHandler = std::function<void()>;

/**
 * @brief Definition of the subscription state of an Event.
 *
 * @uptrace{SWS_CM_00311, 22a3b3d4615d6e6ed3d5063d5711ad5b1a9e7333}
 */
using SubscriptionStateChangeHandler = std::function<void(ara::com::SubscriptionState)>;

/**
 * @brief Pointer to allocated sample on service side.
 *
 * @uptrace{SWS_CM_00308, da5eb18dc5a888434ea0b882750c7261e2dd1eca}
 */
template <typename T>
using SampleAllocateePtr = std::unique_ptr<T>;

/**
 * @brief Handler that gets called in case service availability for services which have been searched for via
 * FindService() has changed.
 *
 * @uptrace{SWS_CM_00383, 764585622e1ef2d3ecef2a3602ef648155c5fe9d}
 */
template <typename T>
using FindServiceHandler = std::function<void(ServiceHandleContainer<T>, FindServiceHandle)>;

/**
 * @brief Callback from a binding's proxy factory to the general proxy factory.
 *
 * This callback differs from the @see FindServiceHandler callback in that it has type erasure applied. As can be seen,
 * the callback only names the base class instead of the concrete HandleType and thus is not a template.
 *
 */
using ProxyFactoryCallback
    = std::function<void(ServiceHandleContainer<std::shared_ptr<ara::com::internal::proxy::ProxyFactory>>,
        FindServiceHandle)>;

/**
 * @}
 */

}  // namespace com
}  // namespace ara

#endif  // ARA_COM_TYPES_H
