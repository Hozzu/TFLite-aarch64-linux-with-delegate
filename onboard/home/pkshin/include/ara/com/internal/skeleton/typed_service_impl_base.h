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

#ifndef COMMUNICATIONMIDDLEWARE_TYPED_SERVICE_IMPL_BASE_H
#define COMMUNICATIONMIDDLEWARE_TYPED_SERVICE_IMPL_BASE_H

#include "service_impl_base.h"
#include "ara/com/internal/runtime.h"

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
 * \brief Defines the methods for all skeletons that require knowledge about the service type that they offer.
 *
 */
template <typename Service>
class TypedServiceImplBase : public ServiceImplBase
{
public:
    /**
     * @uptrace{SWS_CM_00130, 4e955786ada8287ec07a290cebafd2be29ee3fde}
     * @uptrace{SWS_CM_00198, 7ad0b3322274e3e5f67b1c834e9ec2ba95c54bb4}
     */
    TypedServiceImplBase(ara::com::InstanceIdentifier instance, ara::com::MethodCallProcessingMode mode)
        : ServiceImplBase(instance)
    {
        SetMethodCallProcessingMode(mode);
    }

    /**
     * @uptrace{SWS_CM_00152, 1259be4e527aa8726c310aa14e83ed368c964fed}
     * @uptrace{SWS_CM_00198, 7ad0b3322274e3e5f67b1c834e9ec2ba95c54bb4}
     */
    TypedServiceImplBase(ara::core::InstanceSpecifier instanceSpec, ara::com::MethodCallProcessingMode mode)
        : ServiceImplBase(instanceSpec)
    {
        SetMethodCallProcessingMode(mode);
    }

    /**
     * @uptrace{SWS_CM_00153, 0b96a5306e0c4ffe31c40ccd91e8a33ed50fe2bc}
     * @uptrace{SWS_CM_00198, 7ad0b3322274e3e5f67b1c834e9ec2ba95c54bb4}
     */
    TypedServiceImplBase(ara::com::InstanceIdentifierContainer instanceIDs, ara::com::MethodCallProcessingMode mode)
        : ServiceImplBase(instanceIDs)
    {
        SetMethodCallProcessingMode(mode);
    }

    /**
     * \brief Offer service to all bindings that are able to offer the service.
     *
     * It is OK to call this method repeatedly.
     *
     * @uptrace{SWS_CM_00101, c6c279ace86c0392aaff6207c6ecbdcfd79a5d73}
     */
    void OfferService()
    {
        Runtime::OfferService(static_cast<Service&>(*this));
    }

    /**
     * \brief Stop offering the service instance.
     *
     * It is OK to call this method repeatedly.
     *
     * If the service instance gets destroyed, it is expected that the middleware calls \ref StopOfferService() itself.
     *
     * @uptrace{SWS_CM_00111, 0f6014e1d80aa763a338017fe7046d6f76784c80}
     */
    void StopOfferService()
    {
        Runtime::StopOfferService(static_cast<Service&>(*this));
    };

private:
    /**
     * \brief Make the inherited SetMethodCallProcessing private.
     */
    virtual void SetMethodCallProcessingMode(ara::com::MethodCallProcessingMode mode) override
    {
        ServiceImplBase::SetMethodCallProcessingMode(mode);
    }
};

/**
 * @}
 */

}  // namespace skeleton
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // COMMUNICATIONMIDDLEWARE_TYPED_SERVICE_IMPL_BASE_H
