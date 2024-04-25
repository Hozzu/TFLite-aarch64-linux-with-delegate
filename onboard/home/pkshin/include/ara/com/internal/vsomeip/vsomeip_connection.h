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

#ifndef ARA_VSOMEIP_BINDING_INCLUDES_LIBARA_INTERNAL_RUNTIME_VSOMEIP_CONNECTION_H_
#define ARA_VSOMEIP_BINDING_INCLUDES_LIBARA_INTERNAL_RUNTIME_VSOMEIP_CONNECTION_H_

#include "ara/core/string.h"
#include <thread>
#include "ara/core/map.h"

#include "ara/com/internal/mutex_wrapper.h"

#include "vsomeip_types.h"
#include "vsomeip_common.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace vsomeip
{
namespace runtime
{

/**
 * \addtogroup vsomeipcommon
 *
 * @{
 */

/**
 * \brief Manages the lifecycle of the vsomeipd connection and provides access to the public interface of vsomeipd.
 *
 * This class is used like a singleton.
 */
class VSomeIPConnection
{
public:
    /**
     * \brief This class helps managing the refcount of requested services by monitoring ownership.
     *
     * It calls private methods of VSomeIPConnection in order to maintain a count that tells how many components
     * (proxies,
     * FindService and StartFindService) need a certain service.
     */
    class RequestedServiceInstance
    {
    public:
        /**
         * \brief Default constructor.
         */
        RequestedServiceInstance()
            : service_instance_(common::NullServiceInstance)
        { }

        /**
         * \brief Initialize with a service instance and request the service.
         * \param service_instance Service instance to request.
         */
        explicit RequestedServiceInstance(const common::ServiceInstance& service_instance)
            : service_instance_(service_instance)
        {
            VSomeIPConnection::DoRequestService(service_instance_);
        }

        /**
         * \brief Copy constructor, increasing the refcount
         * \param other Service instance to request.
         */
        RequestedServiceInstance(const RequestedServiceInstance& other)
            : service_instance_(other.service_instance_)
        {
            VSomeIPConnection::DoRequestService(service_instance_);
        }

        /**
         * \brief Move constructor, transferring ownership.
         * \param other Service instance to request.
         */
        RequestedServiceInstance(RequestedServiceInstance&& other)
            : service_instance_(std::move(other.service_instance_))
        {
            other.service_instance_ = common::NullServiceInstance;
        }

        /**
         * \brief Copy assignment, increasing the refcount
         * \param other Service instance to request.
         * \return *this
         */
        RequestedServiceInstance& operator=(const RequestedServiceInstance& other)
        {
            // Avoid calling DoRegisterService in case of self-assignment
            if (this != &other) {
                DropServiceInstance();
                service_instance_ = other.service_instance_;
                VSomeIPConnection::DoRequestService(service_instance_);
            }
            return *this;
        }

        /**
         * \brief Move assignment, increasing the refcount
         * \param other Service instance to request.
         * \return *this
         */
        RequestedServiceInstance& operator=(RequestedServiceInstance&& other)
        {
            DropServiceInstance();
            service_instance_ = other.service_instance_;
            other.service_instance_ = common::NullServiceInstance;
            return *this;
        }

        /**
         * \brief Destructor. It will also decrease the reference count if it is owning a service reference.
         */
        ~RequestedServiceInstance()
        {
            DropServiceInstance();
        }

        /**
         * \brief Returns the contained service instance.
         * \return
         */
        const common::ServiceInstance& GetServiceInstance() const
        {
            return service_instance_;
        }

        /**
         * \brief Returns the contained service instance.
         * \return
         */
        types::ServiceId GetServiceInstanceId() const
        {
            return GetServiceInstance().GetService();
        }

        /**
         * \brief Less than operator. Defines a partial ordering over RequestedServiceInstance.
         * \param other RequestedServiceInstance object to compare to.
         * \return true if *this is before other, false otherwise.
         */
        bool operator<(const RequestedServiceInstance& other) const
        {
            return service_instance_ < other.service_instance_;
        }

    private:
        void DropServiceInstance()
        {
            if (service_instance_ != common::NullServiceInstance) {
                VSomeIPConnection::DoReleaseService(service_instance_);
                service_instance_ = common::NullServiceInstance;
            }
        }

        common::ServiceInstance service_instance_;  ///< Service instance to be requested, or NullServiceInstance.
    };

    friend class RequestedServiceInstance;

    /**
     * \brief shortcut for list of vsomeip instances
     */
    using InstanceList = ara::core::Vector<::vsomeip::instance_t>;

    /**
     * \brief Returns the application wide singleton.
     * \return Singleton instance
     */
    static VSomeIPConnection& getInstance()
    {
        return instance_;
    }

    ~VSomeIPConnection();

    /**
     * \return Application wide interface to the vsomeip daemon (Runtime part).
     */
    ::vsomeip::runtime& getRuntime()
    {
        return *runtime_;
    }
    /**
     * \return Application wide interface to the vsomeip daemon (Applciation part).
     */
    ::vsomeip::application& getApplication()
    {
        return *application_;
    }
    static constexpr ::vsomeip::client_t getClientId()
    {
        return 0;
    }

    /**
     * \brief Needs to be called once before vsomeipd can be used to register the application with the daemon.
     *
     * The application's name has to be the same as specified in the vsomeipd configuration file.
     *
     * \param name Application's name.
     */
    void init(const ara::core::String& name);

    /**
     * \brief Determines if a given service instance was announced via service discovery.
     * \param service_id SOMEIP service ID of the service instance.
     * \param instance_id SOMEIP instance ID of the service instance. Can be 0xFFFF (== any)
     * \param required_major_version SOMEIP required major service version
     * \param required_minor_version SOMEIP required minor service version
     * \param is_minumum_minor_policy_enabled SOMEIP version driven find behavior
     * \param num_of_blacklisted_versions SOMEIP number of blacklisted versions
     * \param blacklisted_versions SOMEIP blacklisted versions
     * \return A list of instances matching the given service/instance combination
     */
    std::set<::vsomeip::instance_t> QueryAvailableInstances(::vsomeip::service_t service_id,
        ::vsomeip::instance_t instance_id,
        ::vsomeip::major_version_t required_major_version,
        ::vsomeip::minor_version_t required_minor_version,
        bool is_minimum_minor_policy_enabled,
        uint32_t num_of_blacklisted_versions,
        const types::BlacklistedVersion* blacklisted_versions);

    RequestedServiceInstance RequestService(const common::ServiceInstance& service_instance)
    {
        return RequestedServiceInstance(service_instance);
    }

    /// \brief Query available services based on input params and validate it against a required version.
    /// \param service_id SOMEIP service ID of the service instance.
    /// \param instance_id SOMEIP instance ID of the service instance. Cannot be 0xFFFF (== any)
    /// \param required_major_version SOMEIP required major service version
    /// \param required_minor_version SOMEIP required minor service version
    /// \param is_minumum_minor_policy_enabled SOMEIP version driven find behavior
    /// \param num_of_blacklisted_versions SOMEIP number of blacklisted versions
    /// \param blacklisted_versions SOMEIP blacklisted versions
    /// \return true if valid, false otherwise
    bool ValidateAvailableServiceVersion(::vsomeip::service_t service_id,
        ::vsomeip::instance_t instance_id,
        ::vsomeip::major_version_t required_major_version,
        ::vsomeip::minor_version_t required_minor_version,
        bool is_minumum_minor_policy_enabled,
        uint32_t num_of_blacklisted_versions,
        const types::BlacklistedVersion* blacklisted_versions);

private:
    static VSomeIPConnection instance_;  ///< Singleton instance

    std::shared_ptr<::vsomeip::runtime> runtime_;  ///< Interface to the vsomeipd runtime interface
    std::shared_ptr<::vsomeip::application> application_;  ///< Interface to the vsomeipd application interface

    std::thread dispatchThread_;  ///< The thread the vsomeip client library runs in.

    using RequestServiceRefcountList = ara::core::Map<common::ServiceInstance, std::size_t>;
    using GuardedRequestServiceRefcountList = internal::common::MutexWrapper<RequestServiceRefcountList, std::mutex>;
    GuardedRequestServiceRefcountList request_service_refcounts_;  ///< List of refcounted requested services.

    /**
     * \brief Create a connection to vsomeipd. This object is used application wide.
     */
    VSomeIPConnection();

    /**
     * \brief This method runs in a different thread and serves as the thread for the main loop for the vsomeip client
     * library.
     */
    void dispatch();

    /**
     * \brief Request a service, increasing the refcount and issuing a request_service to VSOMEIPD if necessary.
     *
     * These methods should be used through RequestedServiceInstance.
     *
     * \param service_instance Service instance to request.
     */
    static void DoRequestService(const common::ServiceInstance& service_instance);

    /**
     * \brief Releasing a service, decreasing the refcount and issuing a release_service to VSOMEIPD if the refcount
     * reaches 0.
     *
     * These methods should be used through RequestedServiceInstance.
     *
     * \param service_instance Service instance to release.
     */
    static void DoReleaseService(const common::ServiceInstance& service_instance);

    /// \brief Validate an available major and minor version.
    /// \param required_major_version SOMEIP required major service version
    /// \param required_minor_version SOMEIP required minor service version
    /// \param is_minumum_minor_policy_enabled SOMEIP version driven find behavior
    /// \param num_of_blacklisted_versions SOMEIP number of blacklisted versions
    /// \param blacklisted_versions SOMEIP blacklisted versions
    /// \return true if valid, false otherwise
    bool ValidateServiceVersion(::vsomeip::major_version_t available_major_version,
        ::vsomeip::minor_version_t available_minor_version,
        ::vsomeip::major_version_t required_major_version,
        ::vsomeip::minor_version_t required_minor_version,
        bool is_minumum_minor_policy_enabled,
        uint32_t num_of_blacklisted_versions,
        const types::BlacklistedVersion* blacklisted_versions);
};

/** @}*/
}  // namespace runtime
}  // namespace vsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_VSOMEIP_BINDING_INCLUDES_LIBARA_INTERNAL_RUNTIME_VSOMEIP_CONNECTION_H_
