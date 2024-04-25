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

#ifndef ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SERVICE_MAPPING_IMPL_H_
#define ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SERVICE_MAPPING_IMPL_H_

#include "ara/com/illegal_state_exception.h"

#include "service_mapping.h"
#include "proxy_factory_impl.h"

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

struct NoProxy
{ };

struct NoAdapter
{ };

template <typename Adapter>
struct AdapterBuilder
{
    std::unique_ptr<Adapter> make(internal::skeleton::ServiceBase& service,
        types::InstanceId instance_id,
        common::HandleInfo handle)
    {
        try {
            typename Adapter::ServiceInterface& interface = dynamic_cast<typename Adapter::ServiceInterface&>(service);
            std::unique_ptr<Adapter> adapter = std::make_unique<Adapter>(interface, instance_id, handle);
            return adapter;
        } catch (std::bad_cast&) {
            throw IllegalStateException("Given service interface does not fit to the binding adapter!");
        }
    }
};

template <>
struct AdapterBuilder<NoAdapter>
{
    std::unique_ptr<internal::skeleton::ServiceBase> make(internal::skeleton::ServiceBase&,
        types::InstanceId,
        common::HandleInfo)
    {
        return nullptr;
    }
};

template <typename ProxyType>
struct ProxyBuilder
{
    std::shared_ptr<internal::proxy::ProxyFactory> make(types::InstanceId instance_id, common::HandleInfo handle)
    {
        return std::make_shared<ProxyFactoryImpl<ProxyType>>(instance_id, handle);
    }
};

template <>
struct ProxyBuilder<NoProxy>
{
    std::shared_ptr<internal::proxy::ProxyFactory> make(types::InstanceId, common::HandleInfo)
    {
        return nullptr;
    }
};

template <typename Impl>
struct ServiceDescriptorInterface
{
    static types::ServiceId GetDeploymentId()
    {
        return Impl::ServiceDescriptor::kServiceId;
    }

    static types::ServiceVersionMajor GetServiceVersionMajor()
    {
        return Impl::ServiceDescriptor::kMajorVersion;
    }

    static types::ServiceVersionMinor GetServiceVersionMinor()
    {
        return Impl::ServiceDescriptor::kMinorVersion;
    }

    static uint32_t GetNumberOfBlacklistedVersions()
    {
        return Impl::ServiceDescriptor::blacklisted_versions_length;
    }

    static const types::BlacklistedVersion* GetBlacklistedVersions()
    {
        return Impl::ServiceDescriptor::blacklisted_versions;
    }
};

template <>
struct ServiceDescriptorInterface<NoProxy>
{ };

template <>
struct ServiceDescriptorInterface<NoAdapter>
{ };

template <typename First, typename... Rest>
struct ServiceDescriptor
    : public ServiceDescriptorInterface<First>
    , public ServiceDescriptor<Rest...>
{ };

template <typename First>
struct ServiceDescriptor<First> : public ServiceDescriptorInterface<First>
{ };

/// @todo Figure out if it is possible to have only one class for multiple transports (VSOMEIP, OpenDDS)
template <ServiceId ARACOMServiceId, typename ProxyType, typename SkeletonType>
class ServiceMappingImpl : public DdsServiceMapping::Mapping
{
public:
    /// @brief Get the service ID for the service the mapping represents.
    ///
    /// @return Service ID
    ServiceId GetServiceId() const override
    {
        return ARACOMServiceId;
    }

    /// @brief Get the deployment ID for the service the mapping represents.
    ///
    /// @return Deployment ID
    types::ServiceId GetDeploymentId() const override
    {
        return ServiceDescriptor<ProxyType, SkeletonType>::GetDeploymentId();
    }

    /// @brief Get the major version for the service the mapping represents.
    ///
    /// @return Major version
    types::ServiceVersionMajor GetServiceVersionMajor() const override
    {
        return ServiceDescriptor<ProxyType, SkeletonType>::GetServiceVersionMajor();
    }

    /// @brief Get the minor version for the service the mapping represents.
    ///
    /// @return Minor version
    types::ServiceVersionMinor GetServiceVersionMinor() const override
    {
        return ServiceDescriptor<ProxyType, SkeletonType>::GetServiceVersionMinor();
    }

    /// @brief Get the number of blacklisted versions for the service the mapping represents.
    ///
    /// @return Blacklisted versions list length
    uint32_t GetNumberOfBlacklistedVersions() const override
    {
        return ServiceDescriptor<ProxyType, SkeletonType>::GetNumberOfBlacklistedVersions();
    }

    /// @brief Get the blacklisted versions for the service the mapping represents.
    ///
    /// @return Pointer to the blacklisted versions list
    const types::BlacklistedVersion* GetBlacklistedVersions() const override
    {
        return ServiceDescriptor<ProxyType, SkeletonType>::GetBlacklistedVersions();
    }

    /// @brief Get the proxy factory that creates proxies for the given service instance.
    ///
    /// @param instance_id Instance ID of the service
    /// @return Proxy factory
    std::shared_ptr<internal::proxy::ProxyFactory> GetProxy(types::InstanceId instance_id,
        common::HandleInfo handle) const override
    {
        return ProxyBuilder<ProxyType>().make(instance_id, handle);
    }

    /// @brief Get the skeleton binding class for the given service instance.
    ///
    /// @param service Service implementation from the application layer that shall be exported using the DDS binding.
    /// @param instance_id Instance ID of the service
    /// @return Binding instance.
    std::unique_ptr<internal::skeleton::ServiceBase> GetSkeleton(internal::skeleton::ServiceBase& service,
        types::InstanceId instance_id,
        common::HandleInfo handle) const override
    {
        return AdapterBuilder<SkeletonType>().make(service, instance_id, handle);
    }
};

}  // namespace runtime
}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_SERVICE_MAPPING_IMPL_H_
