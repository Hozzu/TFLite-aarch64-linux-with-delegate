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

#ifndef ARA_COM_SKELETON_EVENT_DISPATCHER_H
#define ARA_COM_SKELETON_EVENT_DISPATCHER_H

#include "ara/com/types.h"
#include "ara/com/illegal_state_exception.h"
#include "ara/core/result.h"
#include "ara/com/com_error_domain.h"

#include "event.h"
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
 * \brief Dispatches all methods of an event on skeleton side to the registered delegates.
 *
 * The methods in this dispatcher are the same as the methods of \ref Event and \ref EventBase.
 */
template <typename T, template <typename> class Element = Event>
class EventDispatcher : public DispatcherBase<Element<T>>
{
public:
    using const_reference = typename Element<T>::const_reference;
    using Dispatcher = DispatcherBase<Element<T>>;

    /**
     * \brief Sends the referenced data.
     *
     * This version of Send is memory intensive if the event data is large and sending occurs quite
     * frequent due to the time needed to copy the data to the output buffers. However, it does not require a call to
     * \ref Allocate and it can send arbitrary data buffers allocated by the user.
     * \param data Data to send
     */
    ara::core::Result<void> Send(const_reference data)
    {
        ara::core::Result<void> res = {};
        for (Event<T>* delegate : Dispatcher::delegates_) {
            auto send_result = delegate->Send(data);
            if (!send_result) {
                res = send_result;
            }
        }
        // either of success, or error from last send.
        return res;
    }

    /**
     * \brief Method to allocate memory for one sample of event data
     *
     * This version of Send() along with Allocate() may be used to directly write to preallocated buffers and thus avoid
     * excess copies as the allocation happens at a location where both writer (service/event provider) and reader
     * (service/event consumer) have direct access to it.
     *
     * \return Unique pointer to the data that shall be used to write output data to.
     *
     */
    ara::core::Result<ara::com::SampleAllocateePtr<T>> Allocate()
    {
        // A decission should be made here which delegate should be used to allocate something, this mights be done by
        // magic
        // or any other haggish method.
        //
        using ReturnType = ara::core::Result<ara::com::SampleAllocateePtr<T>>;
        if (Dispatcher::delegates_.size() == 1) {
            return Dispatcher::delegates_.front()->Allocate();
        } else {
            return ReturnType::FromError({ara::com::ComErrorDomainErrc::kNetworkBindingFailure});
        }
    }

    /**
     * \brief Sends the data the smart pointer points to.
     *
     * After sending data you loose ownership and can't access
     * the data through the SampleAllocateePtr anymore.
     * Implementation of SampleAllocateePtr will be with the
     * semantics of std::unique_ptr.
     *
     * \see \ref SampleAllocateePtr in types.h
     *
     * \param data Data to be sent. The parameter has to be std::move'd into the method.
     **/
    ara::core::Result<void> Send(ara::com::SampleAllocateePtr<T> data)
    {
        // The magic also must be applied here, for the delegate the allocation has been performed before
        // should be able to handle the element, for all the other elements, the data shall be sent before
        if (Dispatcher::delegates_.size() == 1) {
            return Dispatcher::delegates_.front()->Send(std::move(data));
        } else {
            return Send(*data);
        }
    }
};

/**
 * @}
 */

}  // namespace skeleton
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_SKELETON_EVENT_DISPATCHER_H
