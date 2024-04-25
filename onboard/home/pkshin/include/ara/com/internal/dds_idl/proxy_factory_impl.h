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

#ifndef ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_PROXY_FACTORY_IMPL_H_
#define ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_PROXY_FACTORY_IMPL_H_

#include <set>
#include <mutex>
#include <memory>

#include "ara/com/types.h"
#include "ara/com/instance_identifier.h"
#include "ara/com/internal/proxy_factory_builder.h"
#include "ara/com/internal/proxy/proxy_factory.h"
#include "ara/com/internal/proxy/proxy_binding_base.h"

#include "ara/com/internal/dds_idl/common.h"
#include "ara/com/internal/dds_idl/domain_participant.h"
#include "ara/com/internal/dds_idl/service_mapping.h"
#include "ara/com/internal/dds_idl/service_instance_manifest.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace dds
{
namespace runtime
{

class DomainObserver;

template <typename ProxyImpl>
class ProxyFactoryImpl : public internal::proxy::ProxyFactory
{
public:
    /// \brief Creates a factory instance by binding it to the instance for which proxies shall be created.
    /// \param instance The instance the created proxies shall be bound to.
    ProxyFactoryImpl(InstanceIdentifier instance, common::HandleInfo handle)
        : ProxyFactory(instance)
        , handle_(handle)
    { }

    std::unique_ptr<internal::proxy::ProxyBindingBase> Create() const override
    {
        return std::make_unique<ProxyImpl>(instance_, handle_);
    }

private:
    common::HandleInfo handle_;
};

/// @uptrace{SWS_CM_11011, e05421c3a256fd09ae40b473ca6dff0fbd9cb0d8}
class DdsProxyFactoryImpl : public internal::runtime::ProxyFactoryBuilder
{
public:
    DdsProxyFactoryImpl(ServiceInstanceManifest& manifest);
    virtual ~DdsProxyFactoryImpl();

    // For FindService
    /// @uptrace{SWS_CM_11006, 935b8d68a612b196fe394dc47c0b8a6eb0de7b00}
    /// @uptrace{SWS_CM_11007, 20a7681ce814e9bdc68387da5fa8eaf111077be3}
    /// @uptrace{SWS_CM_11009, 660643ce96fadd1c3552e58d88c332470c9542a3}
    virtual ara::core::Vector<std::shared_ptr<internal::proxy::ProxyFactory>> createInstance(ServiceId serviceId,
        InstanceIdentifier instanceId) override;

    // For StartFindService
    /// @uptrace{SWS_CM_11007, 20a7681ce814e9bdc68387da5fa8eaf111077be3}
    /// @uptrace{SWS_CM_11010, 1173d66d90f976e996a71a9d8be11fa4a803217c}
    /// @uptrace{SWS_CM_11012, da4be7ef4b26cedaef4a995af699edb9bf813895}
    virtual void RegisterFindServiceHandle(FindServiceHandle handle, ProxyFactoryCallback callback) override;

    // For StopFindService
    /// @uptrace{SWS_CM_11013, 5e989f24bdef39ae44fcaaccc48d8b7be7b8e7da}
    /// @uptrace{SWS_CM_11014, 43fb9c0326197a1a6fef1f0b6a5cd2d9b6a6df0b}
    virtual void UnregisterFindServiceHandle(FindServiceHandle handle) override;

private:
    void OnAvailableServicesChanged(std::set<common::ExtendedServiceInfo> const& services);
    void OnServiceAvailabilityChanged(std::set<common::ServiceInfo> const& availableServices,
        common::ServiceInfo info,
        bool available);
    ServiceHandleContainer<std::shared_ptr<internal::proxy::ProxyFactory>> GenerateAnyFactoryList(
        std::set<common::ServiceInfo> const& availableServices,
        DdsServiceMapping::Mapping const& mapping);

    std::shared_ptr<internal::proxy::ProxyFactory> GenerateAvailableInstanceFactory(
        const DdsServiceMapping::Mapping& mapping,
        const types::ServiceId serviceId,
        const types::InstanceId instanceId,
        std::shared_ptr<DomainParticipant> participant);

    std::shared_ptr<DomainParticipant> SubscribeOnParticipantUpdates(types::DomainId domainId,
        ara::core::StringView qosProfile);
    std::shared_ptr<internal::proxy::ProxyFactory> GetProxy(const DdsServiceMapping::Mapping& mapping,
        const types::ServiceId serviceId,
        const types::InstanceId instanceId,
        std::shared_ptr<DomainParticipant> participant);
    bool ValidateServiceVersion(common::ExtendedServiceInfo service,
        types::ServiceVersionMajor majorServiceVersion,
        types::ServiceVersionMinor minorServiceVersion,
        uint32_t numOfBlacklistedVersions,
        const types::BlacklistedVersion* blacklistedVersions);

    // TODO: using of 4-byte integer as key is dangerous because of overlapping
    ara::core::Map<std::uint32_t, common::FindServiceInfo> findHandles_;

    // We need a recursive mutex as the handlers aren't thread safe AND may call any method of ara::com during callback
    // processing.
    using Mutex = std::recursive_mutex;
    Mutex mutex_;

    ara::core::Map<types::DomainId, std::shared_ptr<DomainParticipant>> domains_;
    std::set<common::ServiceInfo> availableServices_;
    ServiceInstanceManifest& manifest_;
};

}  // namespace runtime
}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_PROXY_FACTORY_IMPL_H_
