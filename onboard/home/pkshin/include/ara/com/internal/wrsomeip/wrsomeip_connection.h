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

#pragma once
#include <string>
#include <thread>
#include <map>
#include <set>

#include "ara/core/map.h"
#include "ara/com/internal/mutex_wrapper.h"

#include "ara/com/internal/wrsomeip/wrsomeip_types.h"
#include "ara/com/internal/wrsomeip/wrsomeip_common.h"
#include "ara/com/internal/wrsomeip/wrapper/wrsomeip_runtime_wrapper.h"
#include "ara/com/internal/runtime.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace wrsomeip
{
namespace runtime
{

// Manages the lifecycle of the connection
class WrSomeIPConnection
{
public:
    static serviceApplication* pClientApp;  // used for application handling:new->create->stop->delete
    /**
     * This class helps managing the refcount of requested services by monitoring ownership.
     * It calls private methods of WrSomeIPConnection in order to maintain a count that tells how many
     * componentsproxies) FindService and StartFindService) need a certain service.
     */
    class RequestedServiceInstance
    {
    public:
        RequestedServiceInstance()
            : service_instance_(common::NullServiceInstance)
        { }

        explicit RequestedServiceInstance(const common::ServiceInstance& service_instance)
            : service_instance_(service_instance)
        {
            WrSomeIPConnection::DoRequestService(service_instance_);
        }

        // Copy constructor, increasing the refcount
        RequestedServiceInstance(const RequestedServiceInstance& other)
            : service_instance_(other.service_instance_)
        {
            WrSomeIPConnection::DoRequestService(service_instance_);
        }

        // Move constructor
        RequestedServiceInstance(RequestedServiceInstance&& other)
            : service_instance_(std::move(other.service_instance_))
        {
            other.service_instance_ = common::NullServiceInstance;
        }

        // Copy assignment
        RequestedServiceInstance& operator=(const RequestedServiceInstance& other)
        {
            // Avoid calling DoRegisterService in case of self-assignment
            if (this != &other) {
                DropServiceInstance();
                service_instance_ = other.service_instance_;
                WrSomeIPConnection::DoRequestService(service_instance_);
            }
            return *this;
        }

        // Destructor. It will also decrease the reference count if it is owning a service reference.
        ~RequestedServiceInstance()
        {
            DropServiceInstance();
        }

        // Move assignment
        RequestedServiceInstance& operator=(RequestedServiceInstance&& other)
        {
            DropServiceInstance();
            service_instance_ = other.service_instance_;
            other.service_instance_ = common::NullServiceInstance;
            return *this;
        }

        // Returns the contained service instance.
        const common::ServiceInstance& GetServiceInstance() const
        {
            return service_instance_;
        }

        // Returns the contained service instance ID.
        types::ServiceId GetServiceInstanceId() const
        {
            return GetServiceInstance().GetService();
        }

    private:
        common::ServiceInstance service_instance_;  // Service instance to be requested

        void DropServiceInstance()
        {
            if (service_instance_ != common::NullServiceInstance) {
                WrSomeIPConnection::DoReleaseService(service_instance_);
                service_instance_ = common::NullServiceInstance;
            }
        }
    };

    friend class RequestedServiceInstance;
    using InstanceList = ara::core::Vector<types::instance_t>;

    // Returns the application wide singleton. returns singleton instance
    static WrSomeIPConnection& getInstance()
    {
        std::lock_guard<std::mutex> myLock(clientAppMutex_);
        if (pClientApp == nullptr) {
            Runtime::SetDefaultInstanceName("no-name");
            pClientApp = servAppNew(Runtime::GetInstanceName().c_str());
        }

        if (pClientApp == nullptr) {
            logger::log().LogFatal() << "[BINDING][" << __FUNCTION__
                                     << "] Client app is null. Wrsomeip connection cannot be used. Aborting.";
            std::abort();
        }

        return instance_;
    }

    /**
     * \return Application wide interface to the wrvsomeip daemon (Runtime part).
     */
    wrapper::WrsomeipRuntime& getRuntime()
    {
        if (runtime_ == NULL) {
            logger::log().LogDebug() << "[BINDING][" << __FUNCTION__ << "] Runtime is null, get new runtime";
            runtime_ = wrapper::WrsomeipRuntime::get();
        }
        return *runtime_;
    }
    /**
     * \return Application wide interface to the wrsomeip daemon (Applciation part).
     */
    wrapper::WrsomeipApplication& getApplication()
    {
        return *application_;
    }

    /**
     * \return Service Application pointer to wrsomeip SERVICE_APPLICATION struct
     */
    types::ServiceApplication* getServiceApplication()
    {
        return service_application_;
    }

    ~WrSomeIPConnection();

    void init();

    // Determines if a given service instance was announced via service discovery.
    // It returns a list of instances matching the given service/instance combination
    std::set<types::instance_t> QueryAvailableInstances(types::ServiceId service_id, types::InstanceId instance_id);

    RequestedServiceInstance RequestService(const common::ServiceInstance& service_instance)
    {
        return RequestedServiceInstance(service_instance);
    }

private:
    static std::mutex clientAppMutex_;
    static WrSomeIPConnection instance_;  // Singleton instance
    std::shared_ptr<wrapper::WrsomeipRuntime> runtime_;  // Interface to the wrsomeip runtime
    std::shared_ptr<wrapper::WrsomeipApplication> application_;  // Interface to the wrsomeip application
    types::ServiceApplication* service_application_;

    std::thread dispatchThread_;  // The thread the wrsomeip client library runs in.

    using RequestServiceRefcountList = ara::core::Map<common::ServiceInstance, std::size_t>;
    using GuardedRequestServiceRefcountList = internal::common::MutexWrapper<RequestServiceRefcountList, std::mutex>;
    GuardedRequestServiceRefcountList request_service_refcounts_;  // List of refcounted requested services.

    WrSomeIPConnection();

    // This method runs in a different thread and serves as the thread for the main loop for the wrsomeip client
    // library.
    void dispatch();

    // Request a service, increasing the refcount and issuing a request_service to wrsomiep if necessary.
    static void DoRequestService(const common::ServiceInstance& service_instance);

    // Releasing a service, decreasing the refcount and issuing a release_service to wrsomeip daemon if the refcount *
    // reaches 0.
    static void DoReleaseService(const common::ServiceInstance& service_instance);
};

}  // namespace runtime
}  // namespace wrsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara
