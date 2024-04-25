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

#ifndef dds_idl_type_converter_ara_core_idl
#define dds_idl_type_converter_ara_core_idl

#include "ara/core/error_code.h"
#include "ara/com/types.h"
#include "ara/com/internal/dds_idl/dds_idl_types_binding.h"
#include "ara/com/internal/dds_idl/error_domains.h"

// Headers generated from IDL
#include "dds_idl/ara_coreTypeSupportS.h"
#include "dds_idl/ara_coreTypeSupportImpl.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace dds
{

inline auto ConvertToIdl(ara::core::ErrorCode const& source)
{
    ::dds_types::ara::core::ErrorCode result;
    result.error_domain_value = source.Domain().Id();
    result.error_code = source.Value();
    return result;
}

inline auto ConvertFromIdl(::dds_types::ara::core::ErrorCode const& source)
{
    return ara::core::ErrorCode(source.error_code,
        ara::com::internal::dds::common::error_domains::Registry::getDomain(source.error_domain_value));
}

}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // dds_idl_type_converter_ara_core_idl
