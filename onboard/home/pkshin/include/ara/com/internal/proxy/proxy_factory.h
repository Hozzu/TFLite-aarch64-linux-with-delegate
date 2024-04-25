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

#ifndef COMMUNICATIONMIDDLEWARE_PROXY_FACTORY_H
#define COMMUNICATIONMIDDLEWARE_PROXY_FACTORY_H

#include <memory>

#include "proxy_binding_base.h"
#include "ara/com/instance_identifier.h"

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
 * \brief Creates instances of the service specific binding implementation.
 *
 * Instances of this class already contain the instance information as well so that the returned object is instance
 * specific as well. This class is used by \ref ProxyFactoryWrapper to support the generated proxy classes during
 * class instantiation.
 */
class ProxyFactory
{
public:
    /**
     * \brief Constructor based on \a InstanceIdentifier.
     *
     * \param the \a InstanceIdentifier to use for the created proxies.
     */
    explicit ProxyFactory(const InstanceIdentifier& instance)
        : instance_(instance)
    { }

    virtual ~ProxyFactory()
    { }

    /**
     * \brief Creates instances of the service specific binding implementation.
     *
     * The returned instances are linked to one proxy forntend class and provides references to all interface elements
     * via getters.
     *
     * \return Proxy binding instance.
     */
    virtual std::unique_ptr<ProxyBindingBase> Create() const = 0;

    /**
     * \brief Retrieve the associated \a InstanceIdentifier.
     * @uptrace{SWS_CM_00312, 98c0354860b00d1dd80a4b202c5e16978e539f83}
     *
     * \return the \a InstanceIdentifier
     */
    virtual const InstanceIdentifier& GetInstanceIdentifier() const
    {
        return instance_;
    }

    /**
     * \brief Set the associated \a InstanceIdentifier to the supplied one.
     * @uptrace{SWS_CM_00312, 98c0354860b00d1dd80a4b202c5e16978e539f83}
     *
     * \param instance the supplied \a InstanceIdentifier.
     */
    virtual void SetInstanceIdentifier(const InstanceIdentifier& instance)
    {
        instance_ = instance;
    }

protected:
    /**
     * \brief Instance for which the proxies shall be created.
     */
    InstanceIdentifier instance_;
};

/**
 * @}
 */

}  // namespace proxy
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // COMMUNICATIONMIDDLEWARE_PROXY_FACTORY_H
