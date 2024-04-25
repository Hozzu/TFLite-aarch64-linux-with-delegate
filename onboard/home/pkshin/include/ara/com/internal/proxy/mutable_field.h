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

#ifndef ARA_COM_PROXY_MUTABLE_FIELD_H
#define ARA_COM_PROXY_MUTABLE_FIELD_H

#include "field.h"

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
 * \brief Defines the typed interface of all field elements on proxy side that have a setter.
 *
 * This class adds a Set() method to a fileld, allowing a client to change the current data the field holds. A
 * MutableField may or may not distribute the newly set data to its clients.
 *
 */
template <typename T>
class MutableField : public virtual Field<T>
{
public:
    using typename Field<T>::const_reference;
    using MethodSet = Method<T(const_reference)>;

    virtual ~MutableField()
    { }

    /**
     * \brief Initializes the field using the provided reference to the Get method implementation.
     *
     * The implementation of the getter has to be provided by the binding code.
     *
     * \param get_impl Getter method implementation to be used for Get() calls.
     * \param set_impl Setter method implementation to be used for Set() calls.
     */
    MutableField(typename Field<T>::MethodGet& get_impl, MethodSet& set_impl)
        : Field<T>(get_impl)
        , m_set_method_body_ref(set_impl)
    { }

    /**
     * \brief Set() method call that sets the current data of the field.
     * @uptrace{SWS_CM_00113, 943291d8b502cf4d2610e14ad1b9a55ed6c85483}
     */
    ara::core::Future<T> Set(const_reference val)
    {
        return m_set_method_body_ref(val);
    }

private:
    MethodSet& m_set_method_body_ref;
};

/**
 * @}
 */

}  // namespace proxy
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_PROXY_MUTABLE_FIELD_H
