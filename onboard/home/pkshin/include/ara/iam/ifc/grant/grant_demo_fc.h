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
/// @brief Implementation for the grant GrantDemoFC

#ifndef ARA_IAM_IFC_GRANT_GRANT_DEMO_FC_H_
#define ARA_IAM_IFC_GRANT_GRANT_DEMO_FC_H_

#include "ara/core/result.h"
#include "ara/core/optional.h"
#include "ara/core/instance_specifier.h"
#include "ara/iam/ifc/grant/grant_process.h"

namespace ara
{
namespace iam
{
namespace ifc
{
namespace grant
{
/// @brief Implementation of a Grant fpr testing and demonstration purposes
class GrantDemoFC final : public GrantProcess
{
public:
    /// @brief Construct a new GrantDemoFC object
    ///
    /// @param process Process InstanceSpecifier
    /// @param demoFile DemoFile InstanceSpecifier
    GrantDemoFC(const ara::exec::ProcessSpecifier& process, const ara::core::InstanceSpecifier demoFile);

    /// @brief Copy constructor
    ///
    /// @param other GrantDemoFC
    GrantDemoFC(const GrantDemoFC& other) = default;

    /// @brief Move constructor
    ///
    /// @param other GrantDemoFC
    GrantDemoFC(GrantDemoFC&& other) = default;

    /// @brief Assignment
    ///
    /// @param other GrantDemoFC
    /// @returns *this
    GrantDemoFC& operator=(const GrantDemoFC& other);

    /// @brief Assignment
    ///
    /// @param other GrantDemoFC
    /// @returns *this
    GrantDemoFC& operator=(GrantDemoFC&& other);

    /// @brief Get the demo file InstanceSpecifier
    ///
    /// @returns Const reference to demo file InstanceSpecifier
    const ara::core::InstanceSpecifier& GetDemoFile() const
    {
        // demoFile can only be nullopt in case of serialization.
        // In this case the serialization fails an empty ara::core::Result
        // is returned.
        return *demoFile_;
    }

    /// @brief ToString method for logging and debugging purposes
    ///
    /// @returns String
    ara::core::String ToString() const override;

    /// @brief Comparison operator
    ///
    /// @param other GrantDemoFC
    /// @returns true, if this and other are instances of GrantDemoFC and contain the same values
    bool operator==(const GrantDemoFC& other) const;

    /// @brief Inherited virtual serialize write method
    ///
    /// @param buf Buffer to write to
    /// @param buf_length Length of buf in bytes
    /// @returns number of bytes written or an GrantSerializationErrc error code
    ara::core::Result<std::size_t> Write(char* buf, const std::size_t buf_length) const override;

    /// @brief Binary serialization (write)
    ///
    /// @param buf Buffer to write to
    /// @param buf_length Length of buf in bytes
    /// @returns number of bytes written or an GrantSerializationErrc error code
    ara::core::Result<std::size_t> SerializeWrite(char* buf, const std::size_t buf_length) const;

    /// @brief Binary serialization (read)
    ///
    /// @param buf Buffer to read from
    /// @param buf_length Length of buf in bytes
    /// @param bytes_read Bytes read
    /// @returns GrantDemoFC or an GrantSerializationErrc error code.
    static ara::core::Result<GrantDemoFC> SerializeRead(const char* buf,
        const std::size_t buf_length,
        std::size_t* bytes_read = nullptr);

    /// @brief Parse from Json
    ///
    /// @param grantNode json node
    /// @returns GrantDemoFC or an GrantSerializationErrc error code.
    static ara::core::Result<GrantDemoFC> ParseJson(const apd::manifestreader::ManifestNode& grantNode);

    /// @brief Comparsion with other Grant instance
    ///
    /// @param other Grant
    /// @returns -1 if less; 0 if identical and +1 otherwise
    std::int32_t Compare(const Grant& other) const override;

    static const char* kTypeStr;  ///< constant type string used for the json parsing

private:
    /// @brief Construct a new GrantDemoFC object (only used internally)
    ///
    GrantDemoFC();

    ara::core::Result<void> Serialize(Poco::BasicMemoryBinaryReader<char>& reader);
    ara::core::Result<void> Serialize(Poco::BasicMemoryBinaryWriter<char>& writer) const;

    static constexpr EGrantType kGrantType = EGrantType::kGrantDemoFC;  ///< Constant identifier for this type of grant

    /// @brief Instance specifier for demo file.
    /// The demoFile may be nullopt for the serialization.
    /// However, in this case the serialize function should newer return a valid GrantDemoFC instance.
    /// Instead an ara::core::Result with an error code should be returned.
    ara::core::Optional<ara::core::InstanceSpecifier> demoFile_;
};

}  // namespace grant
}  // namespace ifc
}  // namespace iam
}  // namespace ara

#endif  // ARA_IAM_IFC_GRANT_GRANT_DEMO_FC_H_
