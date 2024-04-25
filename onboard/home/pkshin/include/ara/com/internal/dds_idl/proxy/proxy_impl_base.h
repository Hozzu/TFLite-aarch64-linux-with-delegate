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

#ifndef DDS_IDL_PROXY_PROXY_IMPL_BASE_H
#define DDS_IDL_PROXY_PROXY_IMPL_BASE_H

#include "ara/com/internal/dds_idl/types.h"
#include "ara/com/internal/dds_idl/common.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace dds
{
namespace proxy
{

/// @brief Proxy base implementation for OpenDDS proxy interface
class ProxyImplBase
{
public:
    /// @brief Construct a specific ProxyImplBase
    ///
    /// @param service_id Service id used to construct the object
    /// @param instance_id Instance id used to construct the object
    /// @param service_version Service version used to construct the object
    /// @param handle Handle object with references on assigned to proxy instance DDS resources
    ///
    /// @uptrace{SWS_CM_11001, a8b217d7530f842552026107a953e190978303a5}
    /// @uptrace{SWS_CM_11002, b714b8c99d0fadfe45732780cb3b16632e24a1bd}
    ProxyImplBase(types::ServiceId serviceId,
        types::InstanceId instanceId,
        types::ServiceVersionMajor serviceVersionMajor,
        types::ServiceVersionMinor serviceVersionMinor,
        common::HandleInfo handle)
        : serviceId_(serviceId)
        , instanceId_(instanceId)
        , serviceVersionMajor_(serviceVersionMajor)
        , serviceVersionMinor_(serviceVersionMinor)
        , handle_(handle)
    { }

    virtual ~ProxyImplBase()
    { }

protected:
    /// @brief Return the service instance id
    ///
    /// @return Instance id
    InstanceIdentifier getInstanceId() const
    {
        return instanceId_;
    }

private:
    types::ServiceId serviceId_;
    types::InstanceId instanceId_;
    types::ServiceVersionMajor serviceVersionMajor_;
    types::ServiceVersionMinor serviceVersionMinor_;
    common::HandleInfo handle_;
};

}  // namespace proxy
}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // DDS_IDL_PROXY_PROXY_IMPL_BASE_H
