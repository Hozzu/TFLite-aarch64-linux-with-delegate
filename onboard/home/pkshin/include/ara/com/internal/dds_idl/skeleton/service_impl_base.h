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

#ifndef ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_SKELETON_SERVICE_IMPL_BASE_H_
#define ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_SKELETON_SERVICE_IMPL_BASE_H_

#include "ara/com/types.h"

#include "ara/com/internal/dds_idl/common.h"
#include "ara/com/internal/dds_idl/skeleton/event_impl.h"
#include "ara/com/internal/dds_idl/skeleton/field_impl_base.h"
#include "ara/com/internal/dds_idl/skeleton/method_impl_base.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace dds
{
namespace skeleton
{

/// @brief Service base implementation for Skeleton interface
class ServiceImplBase
{
public:
    virtual ~ServiceImplBase() = default;

    /// @brief OfferService
    ///
    /// @param domainId DDS Domain Id this service shall belong to
    ///
    /// @uptrace{SWS_CM_11001, a8b217d7530f842552026107a953e190978303a5}
    /// @uptrace{SWS_CM_11002, b714b8c99d0fadfe45732780cb3b16632e24a1bd}
    /// @uptrace{SWS_CM_09004, 81b4a1b42d7401f595c66bdb4cf83b2a8401119d}
    virtual void OfferService(const ::ara::com::internal::dds::types::ServiceId serviceId,
        const ::ara::com::InstanceIdentifier& instanceIdentifier,
        const ::ara::com::internal::dds::types::ServiceVersionMajor majorServiceVersion,
        const ::ara::com::internal::dds::types::ServiceVersionMinor minorServiceVersion)
        = 0;

    /// @brief StopOfferService
    ///
    /// @uptrace{SWS_CM_11005, 12be17fbde385fa184bca353ab0078a00f31ac5b}
    virtual void StopOfferService() = 0;

    /// @uptrace{SWS_CM_11003, cea0644db853e28cd6c794842d816e2cdac63fad}
    /// @uptrace{SWS_CM_11015, abf5b30ea99445b3ed18b9a31c6375d03c558fb2}
    virtual void OfferEvent(EventImplBase& event) = 0;
    virtual void StopOfferEvent(EventImplBase& event) = 0;

    virtual void OfferMethod(MethodImplBase& method) = 0;
    virtual void StopOfferMethod(MethodImplBase& method) = 0;

    /// @uptrace{SWS_CM_11130, 97718522516f96d52b15251e5de6990d2e03b67b}
    virtual void OfferField(FieldImplBase& field) = 0;
    virtual void StopOfferField(FieldImplBase& field) = 0;
};

}  // namespace skeleton
}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_SKELETON_SERVICE_IMPL_BASE_H_
