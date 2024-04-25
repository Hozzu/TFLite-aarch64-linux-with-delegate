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
 * \brief vsomeip error_domains to error codes mapping
 */

#ifndef ARA_VSOMEIP_BINDING_INCLUDES_LIBARA_INTERNAL_COMMON_VSOMEIP_ERROR_DOMAINS_H_
#define ARA_VSOMEIP_BINDING_INCLUDES_LIBARA_INTERNAL_COMMON_VSOMEIP_ERROR_DOMAINS_H_

#include "ara/core/error_domain.h"
#include "ara/core/map.h"

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
namespace error_domains
{
class Registry
{
public:
    static void registerDomain(const ara::core::ErrorDomain& domain);
    static const ara::core::ErrorDomain& getDomain(const ara::core::ErrorDomain::IdType& id);

private:
    using domain_id = ara::core::ErrorDomain::IdType;
    using domain_ref = std::reference_wrapper<const ara::core::ErrorDomain>;
    static ara::core::Map<domain_id, domain_ref> known_domains;
};
/** @}*/
}  // namespace error_domains
}  // namespace common
}  // namespace vsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_VSOMEIP_BINDING_INCLUDES_LIBARA_INTERNAL_COMMON_VSOMEIP_ERROR_DOMAINS_H_
