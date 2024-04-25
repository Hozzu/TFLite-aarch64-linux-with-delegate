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
 * \brief Identifier of a certain instance of a service.
 *
 * This is needed to distinguish different instances of exactly the same service in the system. Only contains instance
 * information. Does NOT contain a fully qualified name, which also contains service type information.
 *
 */
#ifndef ARA_COM_INSTANCE_IDENTIFIER_H
#define ARA_COM_INSTANCE_IDENTIFIER_H

#include <functional>
#include <string>
#include <iostream>

#include "ara/core/string.h"
#include "ara/core/vector.h"  // For InstanceIdentifierContainer definition
#include "ara/core/string_view.h"
#include "ara/core/instance_specifier.h"  // For ResolveInstanceIDs function
#include "ara/com/internal/definitions.h"

namespace ara
{
namespace com
{
/**
 * \addtogroup runtime
 *
 * @{
 */

/**
 * \brief Identifier of a certain instance of a service.
 *
 * @uptrace{SWS_CM_00302, ac412cdc2866dae8bc837170348119dccb6dfbb3}
 */
class InstanceIdentifier
{
public:
    /**
     * \brief Explicit constructor to avoid implicit type conversion for instance ID
     * \param value Used for instance ID
     *
     * @uptrace{SWS_CM_00302, ac412cdc2866dae8bc837170348119dccb6dfbb3}
     */
    explicit InstanceIdentifier(ara::core::StringView value)
        : instance_id_(value)
    { }

    /**
     * \brief Converts the contents of the InstanceIdentifier to an implementation-defined string representation.
     * \return String representing the service instance.
     *
     * @uptrace{SWS_CM_00302, ac412cdc2866dae8bc837170348119dccb6dfbb3}
     */
    ara::core::StringView ToString() const
    {
        return instance_id_;
    }

    /**
     * \brief Compare the equality of two instance IDs.
     * \param other InstanceIdentifier to compare to.
     * \return true if equal else false
     *
     * @uptrace{SWS_CM_00302, ac412cdc2866dae8bc837170348119dccb6dfbb3}
     */
    bool operator==(const InstanceIdentifier& other) const
    {
        return instance_id_ == other.instance_id_;
    }
    /**
     * \brief Establishes a total order over InstanceIdentifier so that it's usable inside an ara::core::Map or std::set
     * \param other InstanceIdentifier to compare to.
     * \return true if *this < other else false
     *
     * @uptrace{SWS_CM_00302, ac412cdc2866dae8bc837170348119dccb6dfbb3}
     */
    bool operator<(const InstanceIdentifier& other) const
    {
        return instance_id_ < other.instance_id_;
    }

    InstanceIdentifier(const InstanceIdentifier&) = default;
    InstanceIdentifier(InstanceIdentifier&&) = default;

    /**
     * @uptrace{SWS_CM_00302, ac412cdc2866dae8bc837170348119dccb6dfbb3}
     */
    InstanceIdentifier& operator=(const InstanceIdentifier&) = default;
    InstanceIdentifier& operator=(InstanceIdentifier&&) = default;

    ~InstanceIdentifier() = default;

    bool IsAny() const noexcept
    {
        return instance_id_.size() >= 3 && instance_id_.substr(instance_id_.size() - 3, 3) == ANY();
    }

    static InstanceIdentifier MakeAny() noexcept
    {
        static const InstanceIdentifier any(ANY());
        return any;
    }

    // Due to limitations of C++14 use static const method ANY() instead of defining class constant:
    // static constexpr char ANY[] = "ANY";
    // Reason: every transport implements it's own cpp files, and in one of them it will have to add string:
    // constexpr char InstanceIdentifier::ANY[];
    //
    // This is used during service discovery for \see FindService or \see StartFindService.
    static const char* ANY()
    {
        static const char any[] = "ANY";
        return any;
    }

private:
    ara::core::String instance_id_;
};

/// @uptrace{SWS_CM_00319, 1c9255a8d0edd16e6f4e53f4515e5af43d136167}
using InstanceIdentifierContainer = ara::core::Vector<InstanceIdentifier>;

namespace runtime
{
/// @uptrace{SWS_CM_00118, 9d4e6b67ceb600eacfce14cd317e8378921af6e2}
InstanceIdentifierContainer ResolveInstanceIDs(ara::core::InstanceSpecifier modelName);
}  // namespace runtime

/**
 * @}
 */

}  // namespace com
}  // namespace ara

namespace std
{

template <>
struct hash<ara::com::InstanceIdentifier>
{
public:
    using result_type = std::size_t;
    using argument_type = ara::com::InstanceIdentifier;
    /**
     * \brief function-call operator to retrieve the hash value of InstanceIdentifier.
     *
     * By providing this, InstanceIdentifier can be used in std::unordered_map and std::unordered_set.
     *
     * \param id InstanceIdentifier to be hashed.
     * \return Hash value.
     */
    std::size_t operator()(const ara::com::InstanceIdentifier& id) const
    {
        ara::core::String s(id.ToString());
        return std::hash<ara::core::String>()(s);
    }
};

}  // namespace std

#endif  // ARA_COM_INSTANCE_IDENTIFIER_H
