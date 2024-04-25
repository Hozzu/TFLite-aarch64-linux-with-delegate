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

#ifndef ARA_COM_SKELETON_EVENT_H
#define ARA_COM_SKELETON_EVENT_H

#include "ara/com/types.h"
#include "ara/core/result.h"
#include "event_base.h"

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
 * \brief Provides all methods an event is required to offer to the application software.
 *
 * An event is a typed data packet that is sent to all clients that have an active subscription to that event. There is
 * no feedback if the packet arrived to all or any destination(s).
 */
template <typename T>
class Event : public bits::EventBase
{
public:
    using const_reference = ConstBaseRef<T>;
    using value_type = BaseType<T>;
    using reference = value_type&;
    using pointer_type = value_type*;
    using SampleType = value_type;  ///< concrete data type for events

    /**
     * \brief Sends the referenced data.
     *
     * This version of Send is memory intensive if the event data is large and sending occurs quite
     * frequent due to the time needed to copy the data to the output buffers. However, it does not require a call to
     * \ref Allocate and it can send arbitrary data buffers allocated by the user.
     * \param data Data to send
     *
     * @uptrace{SWS_CM_00162, 85c935c302eecc4040caa642553e9a83e606a28a}
     */
    virtual ara::core::Result<void> Send(const_reference data) = 0;
    /**
     * \brief Method to allocate memory for one sample of event data
     *
     * This version of Send() along with Allocate() may be used to directly write to preallocated buffers and thus avoid
     * excess copies as the allocation happens at a location where both writer (service/event provider) and reader
     * (service/event consumer) have direct access to it.
     *
     * \return Unique pointer to the data that shall be used to write output data to.
     *
     * @uptrace{SWS_CM_90438, bdf7f8e57972dd9a11697f9031071855dd3b1b3d}
     */
    virtual ara::core::Result<ara::com::SampleAllocateePtr<T>> Allocate() = 0;
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
     *
     * @uptrace{SWS_CM_90437, 02436e182657f9f2fb53cdb7b92a2ea63219981f}
     **/
    virtual ara::core::Result<void> Send(ara::com::SampleAllocateePtr<T> data) = 0;
};

/**
 * @}
 */

}  // namespace skeleton
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_SKELETON_EVENT_H
