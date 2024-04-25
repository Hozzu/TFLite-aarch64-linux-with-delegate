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

#ifndef ARA_COM_PROXY_EVENT_BASE_H
#define ARA_COM_PROXY_EVENT_BASE_H

#include "ara/com/types.h"
#include "ara/core/result.h"

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

namespace bits
{
/**
 * \brief Base class that defines the interface for all methods of Event that do not rely on the Event type.
 */
class EventBase
{
public:
    virtual ~EventBase(){};

    /**
     * \brief  The application expects the middleware to subscribe the event.
     *
     * The middleware shall try to subscribe and re-subscribe until \ref Unsubscribe() is called explicitly.
     * The error handling shall be kept within the middleware.
     *
     * The function returns immediately. If the user wants to get notified, when subscription has succeeded, he needs
     * to register a handler via \ref SetSubscriptionStateChangeHandler(). This handler gets then called after
     * subscription was successful.
     *
     * \param cacheSize Defines the size of the application local cache.
     *
     * @uptrace{SWS_CM_00141, 3e130e46499d6d859ac16f82375bc20a1cd7d907}
     */
    virtual ara::core::Result<void> Subscribe(size_t maxSampleCount) = 0;
    /**
     * \brief Check if the subscription of the event is valid.
     *
     * \return true is the subscription is valid else false.
     */
    virtual bool IsSubscribed() const = 0;

    /**
     * \brief Get the subscription state of the event
     *
     * \return the subscription state
     *
     * @uptrace{SWS_CM_00316, d18cf84f0dce6bd2c850dafaa6aec7ff2d7bd649}
     */
    virtual ara::com::SubscriptionState GetSubscriptionState() const = 0;

    /**
     * \brief  Unsubscribe from the service.
     *
     * @uptrace{SWS_CM_00151, 8c254acbfe32fd3de626f8203cbf01da37f6823c}
     */
    virtual void Unsubscribe() = 0;

    /**
     *
     * \brief Registers a receive handler that is called whenever new data was received.
     *
     * Setting a receive handler signals the middleware implementation to use event style mode.
     * I.e. the registered handler gets called asynchronously by the middleware as soon as new event data
     * arrives for that event. If the user wants to have strict polling behaviour where he decides when to check for
     * new data via Update() he should NOT register a handler.
     *
     * You can only register one handler at a time. The handler may be changed anytime during runtime by calling
     * SetReceiveHandler again.
     *
     * The provided handler needs not to be re-entrant since the middleware implementation serializes calls
     * to the handler so that it gets called once by the MW when new events arrived since the last call to Update().
     * When an application calls Update() again in the context of the receive handler, MW will - in case new events
     * arrived
     * in the meantime - defer the next call to the receive handler until after the previous call to receive handler has
     * been completed.
     *
     * \param handler Hander that shall receive events asynchronously.
     *
     * @uptrace{SWS_CM_00181, c211a486c8d232b8959e6b9cc60583c4ba889b00}
     */
    virtual void SetReceiveHandler(ara::com::EventReceiveHandler handler) = 0;

    /**
     * \brief Remove handler set by SetReceiveHandler().
     *
     * @uptrace{SWS_CM_00183, 0cf46011bd4f414c25ba25add99c817d17423c6b}
     */
    virtual void UnsetReceiveHandler() = 0;

    /**
     *
     * \brief Registers a handler that is called whenever the subscription state changes.
     *
     * This handler is called whenever \ref IsSubscribed() of this event has changed. The handler may be overwritten
     * during runtime by calling SetSubscriptionStateChangeHandler again.
     *
     * \param handler Handler that shall receive the state changes.
     *
     * @uptrace{SWS_CM_00333, 0777d586619de5a632b8f754680901c19b83b742}
     */
    virtual void SetSubscriptionStateChangeHandler(ara::com::SubscriptionStateChangeHandler handler) = 0;

    /**
     * \brief Remove handler set by SetSubscriptionStateChangeHandler()
     *
     * @uptrace{SWS_CM_00334, 336d88f263cab4dbcb949c1c6c329ac1fec70694}
     */
    virtual void UnsetSubscriptionStateChangeHandler() = 0;
};

}  // namespace bits

/**
 * @}
 */

}  // namespace proxy
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_PROXY_EVENT_BASE_H
