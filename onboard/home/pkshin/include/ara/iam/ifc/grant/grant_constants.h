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
/// @brief Constants for the grant implemenation

#ifndef ARA_IAM_IFC_GRANT_GRANT_CONSTANTS_H_
#define ARA_IAM_IFC_GRANT_GRANT_CONSTANTS_H_

#include <cstdint>

namespace ara
{
namespace iam
{
namespace ifc
{
namespace grant
{
/// @brief Limits in for  for the serialsation of a grant
///
/// Maximum amount of data which shall be supported by the ipc connection
/// of the grant_query_client and the access manager. Other limits for
/// an ipc connection may also apply.
static constexpr std::size_t kMaxSizeBytesGrantIPC = 2048;

/// @brief Enum to identify specific grant types
enum class EGrantType : std::uint16_t
{
    kGrantDemoFC = 0,  ///< Grant type for class GrantDemoFC
    kGrantCount  ///< Counter for all possible grant types
};

}  // namespace grant
}  // namespace ifc
}  // namespace iam
}  // namespace ara

#endif  // ARA_IAM_IFC_GRANT_GRANT_CONSTANTS_H_