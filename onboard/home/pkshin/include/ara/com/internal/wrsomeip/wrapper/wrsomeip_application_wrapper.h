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
#include <memory>
#include <map>
#include <set>
#include <string>

#include "ara/com/internal/wrsomeip/wrsomeip_types.h"
#include "ara/com/internal/wrsomeip/wrapper/wrsomeip_message_wrapper.h"
#include "ara/com/internal/wrsomeip/wrapper/wrsomeip_payload_wrapper.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace wrsomeip
{
namespace wrapper
{

using namespace types;

class WrsomeipApplication
{

public:
    WrsomeipApplication()
    { }

    // constructor with string param is used when initialized from WrsomeipRuntime::create_application
    WrsomeipApplication(std::string)
    { }

    virtual ~WrsomeipApplication()
    { }

    // Offers a SOME/IP service instance.
    STATUS offer_service(types::ServiceApplication* _service_app,
        types::SomeIpService _sd_service,
        types::SDInstance _instance,
        types::major_version_t _major = DEFAULT_MAJOR,
        types::minor_version_t _minor = DEFAULT_MINOR);

    // Stops offering a SOME/IP service instance.
    STATUS stop_offer_service(types::ServiceApplication* _service_app,
        types::SomeIpService _sd_service,
        types::SDInstance _instance,
        types::major_version_t _major = DEFAULT_MAJOR,
        types::minor_version_t _minor = DEFAULT_MINOR);

    void offer_event(types::ServiceApplication* _service_app,
        types::ServiceId _service,
        types::InstanceId _instance,
        types::EventId _event,
        const std::set<types::EventGroup>& _eventGroup,
        bool is_field);

    // Stop offering an event wrapper
    void stop_offer_event(types::ServiceApplication* _service,
        types::ServiceId _sd_service,
        types::InstanceId _instance,
        types::event_t _event,
        const std::set<types::EventGroup>& _eventGroup);

    // Registers the application as client of a service instance.
    STATUS request_service(types::ServiceApplication* _service,
        types::ServiceId _service_id,
        types::SDInstance _instance,
        types::major_version_t _major = SOMEIP_ANY_MAJOR,
        types::minor_version_t _minor = SOMEIP_ANY_MINOR);

    STATUS release_service(types::ServiceApplication* _service_app,
        types::ServiceId _service_id,
        types::InstanceId _instance,
        types::major_version_t _major,
        types::minor_version_t _minor);

    // Request an event
    void request_event(types::ServiceApplication* service_app,
        types::ServiceId service,
        types::instance_t instance,
        types::EventId event,
        const types::EventGroup ev_group,
        bool is_field);

    // Realease an event
    void release_event(types::ServiceApplication* serviceApp,
        types::ServiceId service_id,
        types::instance_t instance_id,
        types::EventId event_id,
        const types::EventGroup ev_group);

    // Subscribe to an event group
    void subscribe(types::ServiceApplication* service_app,
        types::ServiceId service_id,
        types::InstanceId instance,
        const types::EventGroup ev_group,
        types::major_version_t service_major_version,
        types::EventId event);

    // Unsubscribes from an eventgroup.
    void unsubscribe(types::ServiceApplication* service_app,
        types::ServiceId service_id,
        types::InstanceId instance,
        const types::EventGroup ev_group);

    // Sends a message
    STATUS send(types::ServiceApplication* serviceApp,
        types::ServiceId _service_id,
        types::InstanceId _instance_id,
        std::shared_ptr<WrsomeipMessage> requestMsg);

    STATUS send_response(types::ServiceApplication* serviceApp, std::shared_ptr<WrsomeipMessage> responseMsg);

    // Trigger an event or field notification.
    STATUS notify(types::ServiceApplication* service_app,
        types::ServiceId _sd_service,
        types::InstanceId _instance_id,
        types::EventId _event,
        SOMEIP_PAYLOAD* _payload);

    // Registers a handler for the specified method or event.
    typedef void (*message_cbk_handler_t)(types::ServiceApplication*, types::SomeIPMessage*);
    void register_message_handler(types::ServiceApplication* service_app,
        types::ServiceId id_service,
        types::InstanceId _instance,
        types::MethodId _method,
        message_cbk_handler_t _handler);

    // Registers a subscription handler for the specified event.
    typedef void (*subscription_cbk_handler_t)(types::ServiceApplication*,
        types::ServiceId,
        types::InstanceId,
        types::EventGroup,
        types::SubscriptionState);
    void register_subscription_handler(types::ServiceApplication* service_app,
        types::ServiceId id_service,
        types::InstanceId _instance,
        types::EventGroup ev_group,
        subscription_cbk_handler_t _handler);

    // Unregisters the message handler for the specified service method/event notification.
    void unregister_message_handler(types::ServiceApplication* service_app,
        types::ServiceId id_service,
        types::InstanceId _instance,
        types::MethodId _method);

    // unregister service availability handler callback
    void unregister_avail_handler(types::ServiceApplication* service_app,
        types::ServiceId id_service,
        types::InstanceId _instance);

    // unregister subscription handler for the specified event.
    void unregister_subscription_handler(types::ServiceApplication* _service,
        types::ServiceId id_service,
        types::InstanceId _instance,
        types::EventGroup ev_group);
};

}  // namespace wrapper
}  // namespace wrsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara
