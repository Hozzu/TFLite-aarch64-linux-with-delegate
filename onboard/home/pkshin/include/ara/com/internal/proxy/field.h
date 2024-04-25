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

#ifndef ARA_COM_PROXY_FIELD_H
#define ARA_COM_PROXY_FIELD_H

#include "method.h"
#include "event.h"
#include "field_base.h"
#include "ara/core/promise.h"
#include "ara/core/future.h"
#include <thread>

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

/**
 * \brief Defines the typed interface of all field elements on proxy side.
 *
 * A field is basically an event that may or may not send the data by itself. In addition, a field also has a getter
 * method that can be used to fetch the field's current value.
 *
 */
template <typename T>
class Field
    : public virtual Event<T>
    , public bits::FieldBase
{
public:
    /**
     * \brief shortcut for result type of a Get method call of all fields.
     */
    using typename Event<T>::const_reference;
    using MethodGet = Method<T()>;

    /**
     * \brief Initializes the field using the provided reference to the Get method implementation.
     *
     * The implementation of the getter has to be provided by the binding code.
     *
     * \param get_impl Getter method implementation to be used for Get() calls.
     */
    Field(MethodGet& get_impl)
        : m_get_method_body_ref(get_impl)
    { }

    /**
     * \brief Get() method call that retrieves the current data the field is set to.
     * @uptrace{SWS_CM_00112, fc5959c3a3e1e39c8172629de0c472f22435d29e}
     */
    ara::core::Future<T> Get()
    {
        return m_get_method_body_ref();
    }

private:
    MethodGet& m_get_method_body_ref;
};

/**
 * @}
 */

}  // namespace proxy
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_PROXY_FIELD_H
