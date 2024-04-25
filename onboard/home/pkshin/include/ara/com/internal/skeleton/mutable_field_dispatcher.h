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

#ifndef ARA_COM_SKELETON_MUTABLE_FIELD_DISPATCHER_H
#define ARA_COM_SKELETON_MUTABLE_FIELD_DISPATCHER_H

#include "ara/com/types.h"
#include "ara/com/internal/mutex_wrapper.h"

#include "field_dispatcher.h"
#include "mutable_field.h"

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
 * \brief Dispatches all methods of a mutable field on skeleton side to the registered delegates.
 *
 * The methods in this dispatcher are the same as the methods of \ref Event, \ref MutableField, \ref Field and
 * \ref FieldBase.
 */
template <typename T>
class MutableFieldDispatcher : public FieldDispatcher<T, MutableField>
{
public:
    using Base = FieldDispatcher<T, MutableField>;
    using Dispatcher = typename Base::Dispatcher;
    using SetMethodSignature = std::function<typename MutableField<T>::SetMethodSignature>;
    using reference = typename MutableField<T>::reference;
    using const_reference = typename MutableField<T>::const_reference;

    MutableFieldDispatcher()
        : set_handler_(MakeDefaultSetHandler())
    { }

    /**
     * \brief Register setter for a field on skeleton side.
     *
     * \param handler Callback to be registered.
     * @uptrace{SWS_CM_00116, be99f767b7c29efc5dc14d9359b96181596c7b56}
     */
    void RegisterSetHandler(SetMethodSignature handler)
    {
        typename SynchronizedSetHandler::LockedPtr set_handler{set_handler_.Get()};
        if (handler) {
            *set_handler = handler;
        } else {
            *set_handler = MakeDefaultSetHandler();
        }

        for (MutableField<T>* delegate : Dispatcher::delegates_) {
            delegate->RegisterSetHandler(*set_handler);
        }
    }

    void AddDelegate(MutableField<T>& delegate)
    {
        Base::AddDelegate(delegate);

        SetMethodSignature handler{*set_handler_.Get()};
        delegate.RegisterSetHandler(handler);
    }

private:
    using SynchronizedSetHandler = internal::common::MutexWrapper<SetMethodSignature, std::mutex>;

    SynchronizedSetHandler set_handler_;

    SetMethodSignature MakeDefaultSetHandler()
    {
        return [](const_reference value) { return ara::core::Future<T>(); };
    }
};
/**
 * @}
 */

}  // namespace skeleton
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_SKELETON_MUTABLE_FIELD_DISPATCHER_H
