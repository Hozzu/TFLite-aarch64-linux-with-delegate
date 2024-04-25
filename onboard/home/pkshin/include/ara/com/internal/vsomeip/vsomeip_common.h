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

/// \file
/// \brief vsomeip common utilities

#ifndef ARA_VSOMEIP_BINDING_INCLUDES_LIBARA_INTERNAL_COMMON_VSOMEIP_COMMON_H_
#define ARA_VSOMEIP_BINDING_INCLUDES_LIBARA_INTERNAL_COMMON_VSOMEIP_COMMON_H_

#include "ara/com/types.h"
#include "ara/com/instance_identifier.h"
#include "ara/core/optional.h"
#include "ara/log/logger.h"
#include "vsomeip_types.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace vsomeip
{
namespace common
{

/// \defgroup vsomeipcommon VSOMEIP Commons
/// \brief Common functionality used by both the VSOMEIP proxy and the skeleton implementations.
///@{

/// \brief Get a logger
/// \return A logger instance

static inline ara::log::Logger& logger()
{
    static ara::log::Logger& loggerInstance
        = ara::log::CreateLogger("VSOMEIP", "VSOMEIP debug context", ara::log::LogLevel::kVerbose);
    return loggerInstance;
}

/// \brief Register a Callback for a method with the vsomeip runtime
/// \param service_id Service ID of the service interface
/// \param instance_id Instance ID of the service instance
/// \param method_id Method ID of the method
/// \param callback Callback that is invoked whenever the specified method was called
void registerMethodHandler(types::ServiceId service_id,
    types::InstanceId instance_id,
    types::MethodId method_id,
    std::function<void(const std::shared_ptr<::vsomeip::message>&)> callback);

/// \brief Unregister a method callback from vsomeip runtime
/// \param service_id Service ID of the service interface
/// \param instance_id Instance ID of the service instance
/// \param method_id ID of the method to unregister
void unregisterMethodHandler(types::ServiceId service_id, types::InstanceId instance_id, types::MethodId method_id);

/// \brief Check whether event is defined or not
/// \param event_id ID of the event to check
/// \return true in case event is undefined, otherwise false
bool isEventUndefined(types::EventId event_id) noexcept;

/// \brief Check whether method is defined or not
/// \param method_id ID of the method to check
/// \return true in case method is undefined, otherwise false
bool isMethodUndefined(types::MethodId method_id) noexcept;

/// \brief Perform std::abort in case condition is false
/// \param condition Condition to check
void abort(bool condition);

/// \brief Check whether a message is valid or not
/// \param message Message content to be checked
/// \param message_type Type of the message to check
/// \param service_id ID of the service to check
/// \param method_id ID of the method to check
/// \param interface_version Version of the interface to check
/// \param allowed_msg_type1 Message type to check
/// \param allowed_msg_type2 Optional message type to check
/// \param check_protocol_version Check against pre-defined value of types::ProtocolVersion if true
/// \param check_return_code Check against vsomeip::return_code_e::E_OK if true
/// \return true in case message meets the conditions, otherwise false
/// \remark Message length is always checked against the value of types::MinMessageLength
bool checkMessageMetaData(const ::vsomeip::message& message,
    types::ServiceId service_id,
    types::MethodId method_id,
    types::InterfaceVersion interface_version,
    types::MessageType allowed_msg_type1,
    types::MessageType allowed_msg_type2 = types::MessageType::MT_UNKNOWN,
    bool check_protocol_version = false,
    bool check_return_code = false);

/// \brief Represents a tuple of service ID and instance ID with a total ordering.
class ServiceInstance
{
public:
    /// \brief Creates an instance from the service and instance ID.
    /// \param service_id SOMEIP service ID.
    /// \param instance_id SOMEIP client ID.
    constexpr ServiceInstance(types::ServiceId service_id,
        types::InstanceId instance_id,
        types::ServiceVersionMajor service_version_major,
        types::ServiceVersionMinor service_version_minor)
        : service_id_(service_id)
        , instance_id_(instance_id)
        , service_version_major_(service_version_major)
        , service_version_minor_(service_version_minor)
    { }

    /// \brief Copy constructor.
    ServiceInstance(const ServiceInstance&) = default;

    /// \brief Copy assignment.
    /// \return *this
    ServiceInstance& operator=(const ServiceInstance&) = default;

    /// \brief Comparison operator
    /// \param other ServiceInstance object to compare to.
    /// \return true of the other object represents the same service, false otherwise.
    bool operator==(const ServiceInstance& other) const;

    /// \brief Inequality operator.
    /// \param other ServiceInstance object to compare to.
    /// \return false of the other object represents the same service, true otherwise.
    bool operator!=(const ServiceInstance& other) const
    {
        return !operator==(other);
    }

    /// \brief Less than operator. Defines a partial ordering over ServiceInstance.
    /// \param other ServiceInstance object to compare to.
    /// \return true if *this is before other, false otherwise.
    bool operator<(const ServiceInstance& other) const;

    /// \brief Retrieves the SOMEIP service ID.
    /// \return SOMEIP service ID
    types::ServiceId GetService() const noexcept
    {
        return service_id_;
    }

    /// \brief Retrieves the SOMEIP instance ID.
    /// \return SOMEIP instance ID
    types::InstanceId GetInstance() const noexcept
    {
        return instance_id_;
    }

    /// \brief Retrieves the SOMEIP major version.
    /// \return SOMEIP instance ID
    types::ServiceVersionMajor GetMajor() const noexcept
    {
        return service_version_major_;
    }

    /// \brief Retrieves the SOMEIP minor version.
    /// \return SOMEIP instance ID
    types::ServiceVersionMinor GetMinor() const noexcept
    {
        return service_version_minor_;
    }

private:
    types::ServiceId service_id_;  ///< SOMEIP service ID.
    types::InstanceId instance_id_;  ///< SOMEIP instance ID.
    types::ServiceVersionMajor service_version_major_;  ///< SOMEIP major version.
    types::ServiceVersionMinor service_version_minor_;  ///< SOMEIP minor version.
};

/// \brief This value represents an unknown or uninitialized service instance.
static constexpr const ServiceInstance NullServiceInstance{0xFFFF, 0xFFFF, 0xFF, 0xFFFFFFFF};

/// Conversion functions between ara::core::InstanceIdentifier and VSOME/IP id
/// Actually ::vsomeip::instance_t is of type uint16_t
ara::core::Optional<::vsomeip::instance_t> ToTransportIdentifier(const InstanceIdentifier& id);
InstanceIdentifier FromTransportIdentifier(const ::vsomeip::instance_t& id);

///@}
}  // namespace common
}  // namespace vsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_VSOMEIP_BINDING_INCLUDES_LIBARA_INTERNAL_COMMON_VSOMEIP_COMMON_H_
