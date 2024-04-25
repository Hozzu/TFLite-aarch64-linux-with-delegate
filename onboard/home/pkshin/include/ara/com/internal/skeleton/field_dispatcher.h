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

#ifndef ARA_COM_SKELETON_FIELD_DISPATCHER_H
#define ARA_COM_SKELETON_FIELD_DISPATCHER_H

#include <memory>
#include <tuple>

#include "ara/com/types.h"
#include "ara/com/illegal_state_exception.h"
#include "ara/com/internal/mutex_wrapper.h"

#include "ara/core/future.h"

#include "field.h"
#include "event_dispatcher.h"

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
 * \brief Dispatches all methods of a field on skeleton side to the registered delegates.
 *
 * The methods in this dispatcher are the same as the methods of \ref Event, \ref Field and \ref FieldBase.
 */
template <typename T, template <typename> class Element = Field>
class FieldDispatcher : protected EventDispatcher<T, Element>
{
public:
    using Base = EventDispatcher<T, Element>;
    using typename Base::const_reference;
    using typename Base::Dispatcher;
    using reference = typename Field<T>::reference;
    using value_type = typename Field<T>::value_type;

    FieldDispatcher()
        : last_value_sent_(std::make_shared<LastValueType>(T(), false))
        , get_handler_(MakeDefaultGetHandler())
    { }

    /**
     * @uptrace{SWS_CM_00114, 248dfdc41f6ada4f341c2d8d789c79f7f5e9ad9b}
     * \brief Register getter for a field on skeleton side.
     *
     * \param handler Callback to be registered.
     */
    void RegisterGetHandler(std::function<ara::core::Future<T>()> handler)
    {
        typename SynchronizedGetHandler::LockedPtr get_handler{get_handler_.Get()};
        if (handler) {
            *get_handler = handler;
        } else {
            *get_handler = MakeDefaultGetHandler();
        }

        for (Field<T>* delegate : Dispatcher::delegates_) {
            delegate->RegisterGetHandler(*get_handler);
        }
    }

    /**
     * \brief Sends the referenced data.
     *
     * This version of Update is memory intensive if the event data is large and sending occurs quite
     * frequent due to the time needed to copy the data to the output buffers. However, it does not require a call to
     * \ref Allocate and it can send arbitrary data buffers allocated by the user.
     * \param data Data to send
     *
     * @uptrace{SWS_CM_00116, be99f767b7c29efc5dc14d9359b96181596c7b56}
     */
    ara::core::Result<void> Update(const_reference data)
    {
        typename LastValueType::LockedPtr last_value{last_value_sent_->Get()};
        std::get<0>(*last_value) = data;
        std::get<1>(*last_value) = true;
        return Base::Send(data);
    }

    /**
     * \brief Adds a delegate. The given delegate must outlive the dispatcher.
     *
     * \param delegate Delegate to add
     */
    void AddDelegate(Element<T>& delegate)
    {
        Dispatcher::AddDelegate(delegate);

        std::function<ara::core::Future<T>()> handler{*get_handler_.Get()};
        delegate.RegisterGetHandler(handler);
    }

    /**
     * Removes a delegate.
     *
     * The function does nothing if the deleate wasn't added before.
     *
     * \param delegate Delegate to remove.
     */
    void RemoveDelegate(Element<T>& delegate)
    {
        Dispatcher::RemoveDelegate(delegate);
    }

    bool IsInitialized()
    {
        return std::get<1>(*last_value_sent_->Get());
    }

private:
    using LastValueType = internal::common::MutexWrapper<std::tuple<T, bool>, std::mutex>;

    std::function<ara::core::Future<T>()> MakeDefaultGetHandler()
    {
        return [last_value_sent = last_value_sent_]() {
            typename LastValueType::LockedPtr last_value{last_value_sent->Get()};
            if (std::get<1>(*last_value)) {
                ara::core::Promise<T> promise;
                promise.set_value(std::get<0>(*last_value));
                return promise.get_future();
            } else {
                throw IllegalStateException("Default Get() handler called without initial value!");
            }
        };
    }

    std::shared_ptr<LastValueType> last_value_sent_;
    using SynchronizedGetHandler = internal::common::MutexWrapper<std::function<ara::core::Future<T>()>, std::mutex>;
    SynchronizedGetHandler get_handler_;
};

/**
 * @}
 */

}  // namespace skeleton
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_SKELETON_FIELD_DISPATCHER_H
