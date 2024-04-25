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

#ifndef ARA_COM_PROXY_METHOD_H
#define ARA_COM_PROXY_METHOD_H

#include "ara/core/future.h"
#include "ara/com/types.h"
#include "method_base.h"

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
 * \brief Defines the typed interface of all method elements on proxy side.
 *
 * This is just the general template declaration that is actually unused because we're always using specializations,
 * either for methods with in- and out-parameters or for void(...) methods.
 */
template <typename T>
class Method;

/**
 * \brief This is the template specialization for void(...) methods.
 *
 * \see \ref Method for a general description.
 */
template <typename... Args>
class Method<void(Args...)> : public virtual bits::MethodBase
{
public:
    /**
     * \brief shortcut for template parameter pack for void(args...)
     */
    using signature_type = void(Args...);
    using result_type = void;

    /**
     * \brief Call the method at the server side.
     *
     * \param args Arguments that are passed to the method. It depends on the generated code what types they have and
     * how
     * many they are.
     *
     * \return Future that is ready as soon as the method has finished.
     *
     * @uptrace{SWS_CM_00192, 72856b42dcba99bfdf48d00b3cf529d759b2047e}
     * @uptrace{SWS_CM_00193, 9dd585ec6ab124da81a685e3d461346a17a0ae38}
     * @uptrace{SWS_CM_00195, 79f6fa3eda4879f4ec29b4e02867fdc7e3f648d5}
     * @uptrace{SWS_CM_00196, facd2b9a65e9248179670b694ae43b51492d0226}
     * @uptrace{SWS_CM_00197, eecdc71d6250f489ad512ed78fd73c5d8e5c6983}
     */
    virtual ara::core::Future<void> operator()(Args&&... args) = 0;
};

/*
 * This is the common template specialization for methods with return parameter.
 */
template <typename R, typename... Args>
class Method<R(Args...)> : public virtual bits::MethodBase
{
public:
    using const_reference_result = ConstBaseRef<R>;
    using result_type = BaseType<R>;
    /**
     * \brief This defines the required 'Output' struct of the method call.
     * @uptrace{SWS_CM_00196, facd2b9a65e9248179670b694ae43b51492d0226}
     */
    using Output = result_type;
    using signature_type = R(Args...);

    /**
     * \brief Call the method at the server side.
     *
     * \param args Arguments that are passed to the method. It depends on the generated code what types they have and
     * how
     * many they are.
     *
     * \return Future that contains the result as soon as the method has finished.
     *
     * @uptrace{SWS_CM_00192, 72856b42dcba99bfdf48d00b3cf529d759b2047e}
     * @uptrace{SWS_CM_00193, 9dd585ec6ab124da81a685e3d461346a17a0ae38}
     * @uptrace{SWS_CM_00195, 79f6fa3eda4879f4ec29b4e02867fdc7e3f648d5}
     * @uptrace{SWS_CM_00196, facd2b9a65e9248179670b694ae43b51492d0226}
     * @uptrace{SWS_CM_00197, eecdc71d6250f489ad512ed78fd73c5d8e5c6983}
     */
    virtual ara::core::Future<Output> operator()(Args&&... args) = 0;
};

/**
 * @}
 */

}  // namespace proxy
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_PROXY_METHOD_H
