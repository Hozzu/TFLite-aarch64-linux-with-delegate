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

#ifndef ARA_COM_SKELETON_SERVICE_IMPL_BASE_H
#define ARA_COM_SKELETON_SERVICE_IMPL_BASE_H

#include <stdexcept>

#include "ara/com/instance_identifier.h"
#include "ara/core/future.h"
#include "ara/core/promise.h"

#include "service_base.h"
#include "dispatcher_base.h"

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
 *
 * \brief Base class for all generated skeleton classes.
 *
 * This class dispatches the methods of the skeleton to all bindings the service is offered to.
 *
 */
class ServiceImplBase
    : public DispatcherBase<ServiceBase>
    , public ServiceBase
{
public:
    using Dispatcher = DispatcherBase<ServiceBase>;

    ServiceImplBase(ara::com::InstanceIdentifier instance)
        : ServiceImplBase(ara::com::InstanceIdentifierContainer{instance})
    { }

    ServiceImplBase(ara::core::InstanceSpecifier instanceSpec)
        : ServiceImplBase(::ara::com::runtime::ResolveInstanceIDs(instanceSpec))
    { }

    ServiceImplBase(ara::com::InstanceIdentifierContainer instanceIDs)
        : instanceIDs_(std::move(instanceIDs))
        , it_(Dispatcher::delegates_.end())
    {
        // Passing an empty container is treated as a Violation
        // unless otherwise stated in SWS
        if (instanceIDs_.empty()) {
            throw std::invalid_argument("Unable to create service, instance identifier container is empty");
        }
    }

    /*
     * Copying a service doesn't make sense, so declare the respective class members as deleted.
     */
    ServiceImplBase(const ServiceImplBase&) = delete;
    ServiceImplBase& operator=(const ServiceImplBase&) = delete;

    /*
     * Moving would make sense and is in fact mandated by the spec. However, we currently do not support this due to the
     * reference from the binding classes to the service class. This reference is not updated on a move and thus we
     * would
     * have a dangling reference.
     *
     * In order to fix this, we'd need to call all our bindings to give them the opportunity to fix their references.
     */
    ServiceImplBase(ServiceImplBase&&) = delete;
    ServiceImplBase& operator=(ServiceImplBase&&) = delete;

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
     *   The service owner is responsible to process events by calling \ref ProcessNextMethodCall() in a proper cycle.
     * No
     *   asynchronous events will be delivered for this service.
     *
     * \param mode New processing mode
     *
     */
    virtual void SetMethodCallProcessingMode(ara::com::MethodCallProcessingMode mode) override
    {
        mode_ = mode;
        for (ServiceBase* delegate : Dispatcher::delegates_) {
            delegate->SetMethodCallProcessingMode(mode);
        }
    }

    /**
     * \brief Fetch the next call from the middleware and execute it.
     *
     * This call shall only be used in polling mode. In event mode it shall throw an exception.
     *
     * Expectations:
     *
     * - Dependent on the implementation and optimization of the middleware, the call that results from the request may
     * be
     *   handled within the context of ProcessNextEvent or asynchronous.
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
     */
    virtual ara::core::Future<bool> ProcessNextMethodCall() override
    {
        if (delegates_.size() != 0) {
            std::list<ServiceBase*>::iterator last_iterator = it_;
            do {
                if (it_ == delegates_.end()) {
                    it_ = delegates_.begin();
                }

                ara::core::Future<bool> result = (*it_)->ProcessNextMethodCall();
                it_++;

                if (!result.is_ready()) {
                    return result;
                } else if (result.get()) {
                    ara::core::Promise<bool> promise;
                    promise.set_value(true);
                    return promise.get_future();
                }
            } while (it_ != last_iterator);
        }

        ara::core::Promise<bool> promise;
        promise.set_value(false);
        return promise.get_future();
    }

    /**
     * \brief Adds a delegate. The given delegate must outlive the dispatcher.
     *
     * In addition, the request processing mode of the registered delegate is updated to match the current overall mode.
     *
     * \param delegate Delegate to add
     */
    void AddDelegate(ServiceBase& delegate)
    {
        Dispatcher::AddDelegate(delegate);
        delegate.SetMethodCallProcessingMode(mode_);
    }

    /**
     * \brief Getter for a container of instances of a service
     *
     * \return Container that contains instance identifiers of a service.
     *
     */
    const ara::com::InstanceIdentifierContainer& GetInstanceIDs() const
    {
        return instanceIDs_;
    }

private:
    const ara::com::InstanceIdentifierContainer instanceIDs_;
    /**
     * \brief Current common method call processing mode.
     *
     * The class enforces the same request processing mode for all bindings the service is offered to.
     *
     */
    ara::com::MethodCallProcessingMode mode_{ara::com::MethodCallProcessingMode::kEvent};
    std::list<ServiceBase*>::iterator it_;
};

/**
 * @}
 */

}  // namespace skeleton
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_SKELETON_SERVICE_IMPL_BASE_H
