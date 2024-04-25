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

#ifndef ARA_PER_MANIFEST_ACCESS_MANIFEST_INTERFACE_H_
#define ARA_PER_MANIFEST_ACCESS_MANIFEST_INTERFACE_H_

#include <memory>

#include "ara/core/string.h"
#include "ara/core/vector.h"
#include "ara/core/string_view.h"
#include "ara/core/instance_specifier.h"

namespace ara
{
namespace per
{
namespace manifest_interface
{

struct FileInitData
{
    ara::core::String initContent;
    ara::core::String fileName;
    std::int64_t updateStrategy = -1; /*0,1,2 are valid value of updataStrategy*/
};

/// @brief Helper for parsing json manifest file
class IManifest
{
public:
    virtual ~IManifest() = default;

    /// @brief get file path from port name (aka /persistancy/application/port)
    ///
    /// #returns file path or empty string in case of wrong port name
    virtual ara::core::Result<ara::core::String> GetPortPath(const ara::core::InstanceSpecifier& port) const = 0;

    /// if not found, -1 by default
    virtual std::size_t GetMinimumSustainedSize(const ara::core::InstanceSpecifier& port) const = 0;

    /// if not found, -1 by default
    virtual std::size_t GetMaximumAllowedSize(const ara::core::InstanceSpecifier& port) const = 0;

    /// #returns executable version of the application
    virtual ara::core::String GetExecutableVersion() const = 0;

    /// #returns softwarecluster version of the application
    virtual ara::core::String GetSoftwareClusterVersion() const = 0;

    /// #returns persintency data required com spec which contains key-value pairs
    virtual ara::core::String GetPerDataRequiredComSpec() const = 0;

    /// #returns instance specifiers of key-value-storages
    virtual ara::core::Vector<ara::core::InstanceSpecifier> GetKvsInstanceSpecifiers() const = 0;

    /// #returns instance specifiers of key-value-storages in interface data
    virtual ara::core::Vector<ara::core::InstanceSpecifier> GetKvsInterfaceInstanceSpecifiers() const = 0;

    /// #returns instance specifiers of file storages
    virtual ara::core::Vector<ara::core::InstanceSpecifier> GetFileStorageInstanceSpecifiers() const = 0;

    /// #returns instance specifiers of file storages in application data
    virtual ara::core::Vector<ara::core::InstanceSpecifier> GetFileStorageInterfaceInstanceSpecifiers() const = 0;

    /// #returns update strategy or -1 in case of wrong port name
    virtual std::int32_t GetUpdateStrategy(const ara::core::InstanceSpecifier& port) const = 0;

    /// #returns key-value pairs or empty string in case of wrong port name
    virtual ara::core::String GetKeyValuePairs(const ara::core::InstanceSpecifier& port) const = 0;

    /// #returns key-value pairs from interface data or empty string in case of wrong port name
    virtual ara::core::String GetInterfaceKeyValuePairs(const ara::core::InstanceSpecifier& port) const = 0;

    /// #returns Initial file contents or empty struct in case of wrong port name
    virtual ara::core::Vector<FileInitData> GetFileInitialData(const ara::core::InstanceSpecifier& port) const = 0;

    /// #returns Initial file contents from interface data or empty struct in case of wrong port name
    virtual ara::core::Vector<FileInitData> GetInterfaceFileInitialData(
        const ara::core::InstanceSpecifier& port) const = 0;

    /// TODO: ara::core::Result. Now if not found, false by default
    virtual bool IsPortReadOnly(const ara::core::InstanceSpecifier& port) const = 0;

    /// TODO: ara::core::Result. Now if not found, false by default
    virtual ara::core::String GetDatabaseCypherParameters(const ara::core::InstanceSpecifier& port) const = 0;

    /// TODO: ara::core::Result. Now if not found, 0 by default
    virtual std::size_t GetRedundantCopiesCount(const ara::core::InstanceSpecifier& port) const = 0;

    /// TODO: ara::core::Result. Now if not found, 0 by default
    virtual std::size_t GetMinimumNumberOfValidRedundantDatabases(const ara::core::InstanceSpecifier& port) const = 0;

    /// TODO: ara::core::Result. Now if not found, false by default
    virtual bool UseCRCForPort(const ara::core::InstanceSpecifier& port) const = 0;

    /// TODO: ara::core::Result. Now if not found, false by default
    virtual bool UseRedundantDatabases(const ara::core::InstanceSpecifier& port) const = 0;
};

std::unique_ptr<IManifest> CreateManifest();

void OverrideManifestPath(ara::core::StringView overridedPath);

}  // namespace manifest_interface
}  // namespace per
}  // namespace ara

#endif  // ARA_PER_MANIFEST_ACCESS_MANIFEST_INTERFACE_H_
