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

#ifndef ARA_COM_SKELETON_FIELD_H
#define ARA_COM_SKELETON_FIELD_H

#include <functional>

#include "ara/core/future.h"
#include "ara/core/result.h"

#include "event.h"
#include "field_base.h"

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
 * \brief Provides all methods a field is required to offer to the application software.
 *
 * A field is just an event that offers a Get method as well. Notice that the current implementation does not allow
 * for the full combination of notification/get/set that the ara::com specification requires.
 *
 */
template <typename T>
class Field
    : public virtual Event<T>
    , bits::FieldBase
{
public:
    using const_reference = ConstBaseRef<T>;
    using typename Event<T>::reference;
    using typename Event<T>::value_type;

    virtual ~Field()
    { }
    /**
     * \brief Register getter for a field on skeleton side.
     *
     * The callback is called whenever a client calls the \ref Get() method. The callback shall set the provided
     * reference
     * to the value the client shall receive as the current value.
     *
     * Any previously registered callback is replaced by the given callback.
     *
     * \param handler Callback to be registered.
     *
     * @uptrace{SWS_CM_00114, 248dfdc41f6ada4f341c2d8d789c79f7f5e9ad9b}
     */
    virtual void RegisterGetHandler(std::function<ara::core::Future<T>()> handler) = 0;

    /**
     * \brief Sends the referenced data.
     *
     * This version of Update is memory intensive if the event data is large and sending occurs quite
     * frequent due to the time needed to copy the data to the output buffers. However, it does not require a call to
     * \ref Allocate and it can send arbitrary data buffers allocated by the user.
     * \param data Data to send
     *
     * @uptrace{SWS_CM_00119, d0060a11bd70be594a52f55a2b56a07648597f87}
     */
    virtual ara::core::Result<void> Update(const_reference data) = 0;
};

/**
 * @}
 */

}  // namespace skeleton
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_SKELETON_FIELD_H
