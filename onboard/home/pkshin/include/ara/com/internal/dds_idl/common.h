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

#ifndef ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_COMMON_H_
#define ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_COMMON_H_

#include "ara/core/string.h"
#include "ara/core/string_view.h"
#include "ara/core/vector.h"
#include "ara/core/optional.h"
#include "ara/com/types.h"
#include "ara/com/internal/dds_idl/types.h"
#include "ara/log/logger.h"
#include "types.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace dds
{

class DomainParticipant;
class Publisher;
class Subscriber;

namespace common
{

/// @brief Get a logger
///
/// @returns logger instance
static inline ara::log::Logger& logger()
{
    static ara::log::Logger& loggerInstance = ara::log::CreateLogger("DDS", "DDS context");
    return loggerInstance;
}

/// \brief Prefix service description string.
/// ara.com://services/<s_id>_<i_id>&<s_id>_<i_id>...
constexpr auto PREFIX = "ara.com://services/";

struct FindServiceInfo
{
    FindServiceHandle findHandle;
    ProxyFactoryCallback callback;
    std::shared_ptr<DomainParticipant> participant;
};

struct ServiceInfo
{
    types::ServiceId serviceId;
    types::InstanceId instanceId;
};

struct ExtendedServiceInfo
{
    types::ServiceId serviceId;
    types::InstanceId instanceId;
    types::ServiceVersionMajor majorServiceVersion;
    types::ServiceVersionMinor minorServiceVersion;
};

struct HandleInfo
{
    std::shared_ptr<DomainParticipant> participant;
    std::shared_ptr<Publisher> publisher;
    std::shared_ptr<Subscriber> subscriber;
};

inline bool operator<(ServiceInfo const& l, ServiceInfo const& r)
{
    if (l.serviceId < r.serviceId) {
        return true;
    }

    return l.serviceId == r.serviceId ? l.instanceId < r.instanceId : false;
}

inline bool operator<(ExtendedServiceInfo const& l, ExtendedServiceInfo const& r)
{
    bool sameServiceId = l.serviceId == r.serviceId;
    bool sameInstanceId = l.instanceId == r.instanceId;
    bool sameMajorVersion = l.majorServiceVersion == r.majorServiceVersion;

    if (sameServiceId && sameInstanceId && sameMajorVersion) {
        return l.minorServiceVersion < r.minorServiceVersion;
    }

    if (sameServiceId && sameInstanceId) {
        return l.majorServiceVersion < r.majorServiceVersion;
    }

    if (sameServiceId) {
        return l.instanceId < r.instanceId;
    }

    return l.serviceId < r.serviceId;
}

/// @uptrace{SWS_CM_09004, 81b4a1b42d7401f595c66bdb4cf83b2a8401119d}
/// @brief Make service description string.
ara::core::String makeServiceString(const ExtendedServiceInfo info);
ara::core::String makeServiceString(const ServiceInfo info);
ara::core::Vector<ExtendedServiceInfo> parseServiceString(ara::core::StringView s);

/// Conversion functions between ara::core::InstanceIdentifier and OpenDDS id
ara::core::Optional<uint16_t> ToTransportIdentifier(const InstanceIdentifier& id);
InstanceIdentifier FromTransportIdentifier(const uint16_t& id);

}  // namespace common
}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_DDS_BINDING_INCLUDES_LIBARA_INTERNAL_DDS_IDL_COMMON_H_
