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
 */

#ifndef ARA_COM_SKELETON_SERVICE_BASE_H
#define ARA_COM_SKELETON_SERVICE_BASE_H

#include "ara/core/future.h"
#include "ara/com/types.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace skeleton
{

/**
 * \addtogroup frontendskeletonbase
 *
 * @{
 */

/**
 * \brief Defines the interface for skeleton implementations.
 *
 * In addition to the methods declared below, generated subclasses will also add pure virtual methods that have to be
 * implemented by the server to implement the method calls defined in the model.
 *
 */
class ServiceBase
{
public:
    /**
     * destructor
     */
    virtual ~ServiceBase(){};
    /**
     *
     * \brief Set the mode that determines when and how incoming method calls are processed by the server.
     *
     * The middleware currently offers these modes:
     *
     * - Mode: kEvent
     *
     *   All requests will be handled automatically and the middleware triggers the application without further
     *   interaction. The part of the middleware within the application does the data collection and calls the related
     *   function. It is up to the middleware implementation how many threads are used to dispatch events to the
     * skeleton.
     *   Concurrent calls to the service implementation might happen.
     *
     * - Mode: kEventSingleThread
     *
     *   All requests will be handled automatically and the middleware triggers the application. The part of the
     *   middleware within the application does the data collection and calls the related function. It is assured by the
     *   middleware implementation, that for this service instance (skeleton) events are dispatched in a serialized
     * manner
     *   (single threaded).
     *
     * - Mode: kPoll
     *
     *   The service owner is responsible to process method calls by calling \ref ProcessNextMethodCall() in a proper
     * cycle.
     *   No asynchronous method calls will be delivered for this service.
     *
     * \param mode New processing mode
     *
     */
    virtual void SetMethodCallProcessingMode(ara::com::MethodCallProcessingMode mode) = 0;

    /**
     * \brief Fetch the next call from the middleware and execute it.
     *
     * This call shall only be used in polling mode. In event mode it shall throw an exception.
     *
     * Expectations:
     *
     * - Dependent on the implementation and optimization of the middleware, the call that results from the request may
     * be
     *   handled within the context of ProcessNextMethodCall or asynchronous.
     *
     * - The application can decide when and how often the processing is done and if the calls shall be done in parallel
     *   (if possible, see above) or in sequence (by waiting for the future to be set).
     *
     * - The middleware implementation shall set the bool result in the future when the method related to the event has
     *   been completely processed. I.e. the method implementation done by the user has set the result in its
     *   corresponding returned future. The middleware implementation shall set the bool result to true in case there
     * was
     *   an event to dispatch. If the middleware implementation detects that there was no outstanding event to process,
     * it
     *   shall set the bool result to false.
     *
     * \return Future that is set as soon as event processing has finished. Value is set to true if there is an event to
     * dispatch else it is set to false.
     *
     * @uptrace{SWS_CM_00199, 5838e2eea5c8d0132f9b95c42926319371496144}
     */
    virtual ara::core::Future<bool> ProcessNextMethodCall() = 0;
};

/**
 * @}
 */

}  // namespace skeleton
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_SKELETON_SERVICE_BASE_H
