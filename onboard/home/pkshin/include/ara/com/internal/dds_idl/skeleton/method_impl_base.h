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

#ifndef ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SKELETON_METHOD_IMPL_BASE_H_
#define ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SKELETON_METHOD_IMPL_BASE_H_

#include "ara/com/internal/dds_idl/common.h"
#include "ara/com/internal/dds_idl/domain_participant.h"

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

class MethodImplBase
{
public:
    using requestId_t = std::uint32_t;
    typedef std::function<void(MethodImplBase*, requestId_t)> OnRequestType;

    virtual ~MethodImplBase()
    { }

    virtual void Offer(common::HandleInfo handle, OnRequestType onRequest) = 0;
    virtual void StopOffer() = 0;
    virtual bool IsOffered() const = 0;

    virtual bool ProcessRequest(requestId_t id) = 0;
    virtual std::vector<requestId_t> GetPendingRequestsIds() = 0;

protected:
    requestId_t GetNextId() const
    {
        static requestId_t lastId = 0;
        return ++lastId;
    }
};

}  // namespace skeleton
}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SKELETON_METHOD_IMPL_BASE_H_
