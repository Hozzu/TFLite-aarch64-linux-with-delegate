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

#ifndef ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_SKELETON_SERVICE_IMPL_H_
#define ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_SKELETON_SERVICE_IMPL_H_

#include "ara/com/types.h"

#include "ara/com/internal/dds_idl/common.h"
#include "ara/com/internal/dds_idl/domain_participant.h"
#include "ara/com/internal/dds_idl/skeleton/service_impl_base.h"
#include "ara/com/internal/dds_idl/skeleton/threadsafe_queue.h"

#include "ara/com/internal/skeleton/service_impl_base.h"

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
class ServiceImpl
    : public ServiceImplBase
    , public internal::skeleton::ServiceImplBase
{
public:
    /// @brief ServiceImpl
    ///
    /// @param service
    /// @param serviceId
    /// @param instance
    /// @param handle
    ///
    /// @uptrace{SWS_CM_11001, a8b217d7530f842552026107a953e190978303a5}
    /// @uptrace{SWS_CM_11002, b714b8c99d0fadfe45732780cb3b16632e24a1bd}
    ServiceImpl(::ara::com::internal::skeleton::ServiceBase& service,
        const ::ara::com::internal::dds::types::ServiceId& serviceId,
        const ::ara::com::InstanceIdentifier& instance,
        common::HandleInfo handle);

    virtual ~ServiceImpl();

    /// @brief OfferService
    ///
    /// @param domainId DDS Domain Id this service shall belong to
    ///
    /// @uptrace{SWS_CM_11001, a8b217d7530f842552026107a953e190978303a5}
    /// @uptrace{SWS_CM_11002, b714b8c99d0fadfe45732780cb3b16632e24a1bd}
    /// @uptrace{SWS_CM_09004, 81b4a1b42d7401f595c66bdb4cf83b2a8401119d}
    void OfferService(const ::ara::com::internal::dds::types::ServiceId serviceId,
        const ::ara::com::InstanceIdentifier& instanceIdentifier,
        const ::ara::com::internal::dds::types::ServiceVersionMajor majorServiceVersion,
        const ::ara::com::internal::dds::types::ServiceVersionMinor minorServiceVersion) override;

    /// @brief StopOfferService
    ///
    /// @uptrace{SWS_CM_11005, 12be17fbde385fa184bca353ab0078a00f31ac5b}
    void StopOfferService() override;

    /// @uptrace{SWS_CM_11003, cea0644db853e28cd6c794842d816e2cdac63fad}
    /// @uptrace{SWS_CM_11015, abf5b30ea99445b3ed18b9a31c6375d03c558fb2}
    void OfferEvent(EventImplBase& event) override;
    void StopOfferEvent(EventImplBase& event) override;

    void OfferMethod(MethodImplBase& method) override;
    void StopOfferMethod(MethodImplBase& method) override;

    /// @uptrace{SWS_CM_11130, 97718522516f96d52b15251e5de6990d2e03b67b}
    void OfferField(FieldImplBase& field) override;
    void StopOfferField(FieldImplBase& field) override;

    ara::core::Future<bool> ProcessNextMethodCall() override;
    void SetMethodCallProcessingMode(ara::com::MethodCallProcessingMode mode) override;

protected:
    internal::skeleton::ServiceBase& service_;

private:
    bool IsOffered() const;
    void CollectPendingRequests();

    /// @brief Starts worker threads for event based method call processing mode
    void StartWorkers();

    /// @brief Stops worker threads for event based method call processing mode
    void StopWorkers();

    /// @brief Worker thread task function
    /// @param threadNum number of worker thread
    void ProcessRequestTask(std::uint32_t threadNum);

    /// @brief Callback function to handle incoming method calls according to processing mode
    /// @param method pointer referring to invoked method
    /// @param requestId ID of request
    void Execute(MethodImplBase* method, typename MethodImplBase::requestId_t requestId);

    common::ExtendedServiceInfo serviceInfo_;
    bool offered_;
    common::HandleInfo handle_;
    ara::core::Vector<MethodImplBase*> methods_;

    using request_t = std::pair<typename MethodImplBase::requestId_t, MethodImplBase*>;
    using pending_requests_t = ThreadsafeQueue<request_t>;
    pending_requests_t pendingRequests_;

    std::mutex requestsMutex_;
    MethodCallProcessingMode requestProcessingMode_;

    std::mutex threadLock_;
    bool shutdownWorker_;
    bool startProcessing_;
    std::condition_variable cond_;
    std::vector<std::thread> workerThreads_;
};

}  // namespace skeleton
}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_SKELETON_SERVICE_IMPL_H_
