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

#ifndef ARA_PER_MANIFEST_ACCESS_MANIFEST_HELPER_H_
#define ARA_PER_MANIFEST_ACCESS_MANIFEST_HELPER_H_

#include "ara/core/string.h"
#include "ara/core/string_view.h"
#include "ara/core/instance_specifier.h"
#include "ara/core/vector.h"
#include "ara/per/kvstype/kvs_type.h"
#include "ara/per/manifestaccess/manifest_constants.h"
#include "ara/per/manifestaccess/manifest_instance.h"

using ara::per::manifest_interface::FileInitData;

namespace ara
{
namespace per
{

/// @brief Helper for parsing json manifest file
class ManifestHelper
{
public:
    ManifestHelper() = delete;

    static ara::core::Result<ara::core::String> GetPortPath(const ara::core::InstanceSpecifier& port)
    {
        return ManifestInstance::get()->GetPortPath(port);
    }

    static std::size_t GetMinimumSustainedSize(const ara::core::InstanceSpecifier& port)
    {
        return ManifestInstance::get()->GetMinimumSustainedSize(port);
    }

    static std::size_t GetMaximumAllowedSize(const ara::core::InstanceSpecifier& port)
    {
        return ManifestInstance::get()->GetMaximumAllowedSize(port);
    }

    static ara::core::String GetExecutableVersion()
    {
        return ManifestInstance::get()->GetExecutableVersion();
    }

    static ara::core::String GetSoftwareClusterVersion()
    {
        return ManifestInstance::get()->GetSoftwareClusterVersion();
    }

    static ara::core::String GetPerDataRequiredComSpec()
    {
        return ManifestInstance::get()->GetPerDataRequiredComSpec();
    }

    static ara::core::Vector<ara::core::InstanceSpecifier> GetKvsInstanceSpecifiers()
    {
        return ManifestInstance::get()->GetKvsInstanceSpecifiers();
    }

    static ara::core::Vector<ara::core::InstanceSpecifier> GetKvsInterfaceInstanceSpecifiers()
    {
        return ManifestInstance::get()->GetKvsInstanceSpecifiers();
    }

    static ara::core::Vector<ara::core::InstanceSpecifier> GetFileStorageInstanceSpecifiers()
    {
        return ManifestInstance::get()->GetFileStorageInstanceSpecifiers();
    }

    static ara::core::Vector<ara::core::InstanceSpecifier> GetFileStorageInterfaceInstanceSpecifiers()
    {
        return ManifestInstance::get()->GetFileStorageInstanceSpecifiers();
    }

    static std::uint32_t GetUpdateStrategy(const ara::core::InstanceSpecifier& port)
    {
        return ManifestInstance::get()->GetUpdateStrategy(port);
    }

    static ara::core::String GetKeyValuePairs(const ara::core::InstanceSpecifier& port)
    {
        return ManifestInstance::get()->GetKeyValuePairs(port);
    }

    static ara::core::String GetInterfaceKeyValuePairs(const ara::core::InstanceSpecifier& port)
    {
        return ManifestInstance::get()->GetInterfaceKeyValuePairs(port);
    }

    static ara::core::Vector<FileInitData> GetFileInitialData(const ara::core::InstanceSpecifier& port)
    {
        return ManifestInstance::get()->GetFileInitialData(port);
    }

    static ara::core::Vector<FileInitData> GetInterfaceFileInitialData(const ara::core::InstanceSpecifier& port)
    {
        return ManifestInstance::get()->GetInterfaceFileInitialData(port);
    }

    static bool IsPortReadOnly(const ara::core::InstanceSpecifier& port)
    {
        return ManifestInstance::get()->IsPortReadOnly(port);
    }

    static ara::core::String GetCypherParameters(const ara::core::InstanceSpecifier& port)
    {
        return ManifestInstance::get()->GetDatabaseCypherParameters(port);
    }

    static std::size_t GetRedundantCopiesCount(const ara::core::InstanceSpecifier& port)
    {
        return ManifestInstance::get()->GetRedundantCopiesCount(port);
    }

    static bool UseCRCForPort(const ara::core::InstanceSpecifier& port)
    {
        return ManifestInstance::get()->UseCRCForPort(port);
    }

    ///
    /// @uptrace{SWS_PER_00317, 7bd79e12bfc2b6f571f9f5eb1cd59a35c44db367}
    static bool UseRedundantCopiesForPort(const ara::core::InstanceSpecifier& port)
    {
        return ManifestInstance::get()->UseRedundantDatabases(port);
    }

    static std::size_t GetMinimumNumberOfValidRedundantDatabases(const ara::core::InstanceSpecifier& port)
    {
        return ManifestInstance::get()->GetMinimumNumberOfValidRedundantDatabases(port);
    }
};

}  // namespace per
}  // namespace ara

#endif  // ARA_PER_MANIFEST_ACCESS_MANIFEST_HELPER_H_
