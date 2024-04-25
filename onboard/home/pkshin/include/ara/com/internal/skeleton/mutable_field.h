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

#ifndef ARA_COM_SKELETON_MUTABLE_FIELD_H
#define ARA_COM_SKELETON_MUTABLE_FIELD_H

#include "field.h"

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
 * \brief Provides all methods a mutable field is required to offer to the application software.
 *
 * A mutable field has the same properties like a field. In addition to a field, however, a mutable field also offers
 * a setter method so that a client can alter the field's current value. Notice that the current implementation does
 * not allow for the full combination of notification/get/set that the ara::com specification requires.
 *
 */
template <typename T>
class MutableField : public virtual Field<T>
{
public:
    using typename Field<T>::const_reference;
    using SetMethodSignature = ara::core::Future<T>(const_reference);

    virtual ~MutableField()
    { }
    /**
     * \brief Registers a set callback with the middleware.
     *
     * The callback is called whenever a client uses the \ref Set() method to set the field's value. The clists expect
     * the next \ref Get() method to return the value that was just set.
     *
     * Any previously registered callback is replaced by the given callback.
     *
     * \param handler Callback to be registered.
     *
     * @uptrace{SWS_CM_00116, be99f767b7c29efc5dc14d9359b96181596c7b56}
     */
    virtual void RegisterSetHandler(std::function<SetMethodSignature> handler) = 0;
};

/**
 * @}
 */

}  // namespace skeleton
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_SKELETON_MUTABLE_FIELD_H
