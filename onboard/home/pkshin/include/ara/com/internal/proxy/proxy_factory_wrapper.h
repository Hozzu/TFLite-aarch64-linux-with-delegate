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

#ifndef COMMUNICATIONMIDDLEWARE_PROXY_FACTORY_WRAPPER_H
#define COMMUNICATIONMIDDLEWARE_PROXY_FACTORY_WRAPPER_H

#include "proxy_binding_base.h"
#include "ara/com/illegal_state_exception.h"
#include "proxy_factory.h"

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

template <typename V, typename U>
/**
 * \brief Downcasts a unique_ptr with a default deleter to another type with a default deleter.
 *
 * This is used to restore the type of the proxy binding object that is returned by the proxy factory. If the dynamic
 * cast fails, the returned pointer is unset and the original pointer stays untouched.
 *
 * \param base The unique_ptr that shall be casted.
 * \return unique_ptr with the downcasted type.
 */
inline std::unique_ptr<V> dynamic_unique_cast(std::unique_ptr<U, std::default_delete<U>>&& base)
{
    std::unique_ptr<V> result;
    V* derived = dynamic_cast<V*>(base.get());
    if (derived) {
        base.release();
        result.reset(derived);
    }
    return result;
}

/**
 * \brief Wrapper class for the proxy factory.
 *
 * This class holds a reference to the proxy factory and provides all methods that are required for a HandleType of a
 * particular proxy class. All generated classes will contain a template instantiation of this class called HandleType.
 * In contrast to the wrapped ProxyFactory, this type is typed with the expected proxy binding class.
 *
 */
template <typename ProxyBinding>
class ProxyFactoryWrapper
{
public:
    /**
     * \brief Initializes the class with the factory that shall be used to create instances of the proxy binding.
     *
     * \param factory Factory that shall be used to create instances of the proxy binding.
     */
    ProxyFactoryWrapper(std::shared_ptr<ProxyFactory> factory)
        : factory_(std::move(factory))
    { }

    /**
     * \brief Copy assignment operator.
     * @uptrace{SWS_CM_00312, 98c0354860b00d1dd80a4b202c5e16978e539f83}
     *
     * Assign the instance id of \a other to this handle's instance id.
     *
     * \param other ProxyFactoryWrapper to assign from.
     *
     * \return reference to this handle.
     */
    ProxyFactoryWrapper& operator=(const ProxyFactoryWrapper& other)
    {
        factory_->SetInstanceIdentifier(other.GetInstanceId());
        return *this;
    }

    /**
     * \brief Compare two instances for equality.
     * @uptrace{SWS_CM_00312, 98c0354860b00d1dd80a4b202c5e16978e539f83}
     *
     * Two instances are considered equal if they represent the same service instance.
     *
     * \param other ProxyFactoryWrapper to compare to.
     *
     * \return true if the same instance is referenced, false otherwise.
     */
    bool operator==(const ProxyFactoryWrapper& other) const
    {
        return GetInstanceId() == other.GetInstanceId();
    }

    /**
     * \brief Less-than comparison.
     * @uptrace{SWS_CM_00312, 98c0354860b00d1dd80a4b202c5e16978e539f83}
     *
     * A handle is less-than the \a other if its instance id
     * is less-than the instance id of the \a other.
     *
     * \param other ProxyFactoryWrapper to compare to.
     *
     * \return true if this handle is less-than the \a other.
     */
    bool operator<(const ProxyFactoryWrapper& other) const
    {
        return GetInstanceId() < other.GetInstanceId();
    }

    /**
     * \brief Returns the instance identifier the instance of this class references.
     * @uptrace{SWS_CM_00312, 98c0354860b00d1dd80a4b202c5e16978e539f83}
     *
     * \return Instance identifier the instance of this class references.
     */
    const InstanceIdentifier& GetInstanceId() const
    {
        return factory_->GetInstanceIdentifier();
    }

    /**
     *
     * \brief Creates an instance of the proxy binding class that connects the frontend class with the server.
     *
     * If the returned instance does not fit to what the user expects, an exception is thrown.
     *
     * \return Typed pointer to the proxy binding class.
     */
    std::unique_ptr<ProxyBinding> Create() const
    {
        std::unique_ptr<ProxyBinding> derived = dynamic_unique_cast<ProxyBinding>(factory_->Create());
        if (derived) {
            return derived;
        } else {
            throw IllegalStateException("Proxy factory returned proxy that doesn't fit to the interface!");
        }
    }

private:
    std::shared_ptr<ProxyFactory> factory_;  ///< Wrapped proxy factory object.
};

/**
 * @}
 */

}  // namespace proxy
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // COMMUNICATIONMIDDLEWARE_PROXY_FACTORY_WRAPPER_H
