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

/// @file
/// @brief Implementation for the string to grant conversion

#ifndef ARA_IAM_IFC_GRANT_GRANT_PARSER_H_
#define ARA_IAM_IFC_GRANT_GRANT_PARSER_H_

#include <boost/variant.hpp>
#include "ara/core/result.h"
#include "ara/iam/ifc/grant/grant.h"
#include "ara/iam/ifc/grant/grant_demo_fc.h"

namespace ara
{
namespace iam
{
namespace ifc
{
namespace grant
{
typedef boost::variant<GrantDemoFC> tGrantVariant;  ///< Type for boost::variant of all grants

static_assert(static_cast<std::underlying_type<ara::iam::ifc::grant::EGrantType>::type>(
                  ara::iam::ifc::grant::EGrantType::kGrantCount)
        == 1,
    "Type tGrantVariant needs to be extended to additional grants");

/// @brief Parse a single grant from a string
///
/// @param buf string
/// @param buf_length length of the string
/// @return tGrantVariant contining the parsed variant or an appropriate error code
ara::core::Result<tGrantVariant> ParseGrant(const char* buf, const std::size_t buf_length);

}  // namespace grant
}  // namespace ifc
}  // namespace iam
}  // namespace ara

#endif  // ARA_IAM_IFC_GRANT_GRANT_PARSER_H_
