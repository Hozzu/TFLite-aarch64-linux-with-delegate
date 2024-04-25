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
/// @brief Implementation for the grant GrantProcess

#ifndef ARA_IAM_IFC_GRANT_GRANT_PROCESS_H_
#define ARA_IAM_IFC_GRANT_GRANT_PROCESS_H_

#include "ara/core/result.h"
#include "ara/exec/process_specifier.h"
#include "ara/iam/ifc/grant/grant.h"
#include "apd/manifestreader/manifest_node.h"
#include "Poco/BinaryReader.h"
#include "Poco/BinaryWriter.h"

namespace ara
{
namespace iam
{
namespace ifc
{
namespace grant
{
/// @brief Implementation of a abstract base class for a grant for with the process
///        will be automatically updated.
///
/// This class only acts as a helper class from which real grants can inherit. Constructors
/// and most
///
/// The process information for a Grant inheriting from this class will be automatically
/// updated based on the location of the file specifying the grants to be loaded.
/// Child classes must implement a (private) emtpy constructor in order to be able to
/// use the Serialize and ParseJson methods.
///
/// Base classes must implement specialisations of the following methods:
/// * operator=
/// * operator==
/// * Serialize
/// * ParseJson
/// * Compare
///
/// These specialisations shall internally call the according functionality of the GrantProcess
/// class.
///
/// Furthormore child classes may also implement a specialized ToString-Method. This method may or
/// may not use the ToStringInternal-Method of the base class.

class GrantProcess : public Grant
{
public:
    /// @brief Get the Process ProcessSpecifier
    ///
    /// @returns Const reference to process ProcessSpecifier
    const ara::exec::ProcessSpecifier& GetProcess() const noexcept
    {
        return process_;
    }

    /// @brief Set the Process object
    ///
    /// @param proc Process
    void SetProcess(const ara::exec::ProcessSpecifier& proc)
    {
        this->process_ = proc;
    }

protected:
    /// @brief Construct a new Grant Process object
    ///
    GrantProcess() = delete;

    /// @brief Destroy the Grant Process object
    ///
    ~GrantProcess() = default;

    /// @brief Construct a new GrantProcess object
    ///
    /// @param kGrandType EGrantType
    GrantProcess(const EGrantType kGrandType);

    /// @brief Construct a new GrantProcess object
    ///
    /// @param kGrandType EGrantType
    /// @param process Process InstanceSpecifier
    GrantProcess(const EGrantType kGrandType, const ara::exec::ProcessSpecifier& process);

    /// @brief Copy constructor
    ///
    /// @param other GrantProcess
    GrantProcess(const GrantProcess& other) = default;

    /// @brief Move constructor
    ///
    /// @param other GrantProcess. The caller needs to ensure that *this and other are of the same child class.
    GrantProcess(GrantProcess&& other) = default;

    /// @brief Assignment
    ///
    /// @param other GrantProcess. The caller needs to ensure that *this and other are of the same child class.
    /// @returns *this
    GrantProcess& operator=(const GrantProcess& other);

    /// @brief Assignment
    ///
    /// @param other GrantProcess. The caller needs to ensure that *this and other are of the same child class.
    /// @returns *this
    GrantProcess& operator=(GrantProcess&& other);

    /// @brief ToString method for logging and debugging purposes
    ///
    /// @returns String
    ara::core::String ToStringInternal() const;

    /// @brief Comparison operator
    ///
    /// @param other GrantProcess
    /// @returns true, if this and other are instances of GrantProcess and contain the same values
    bool operator==(const GrantProcess& other) const;

    /// @brief Serialize
    ///
    /// @param reader BasicMemoryBinaryReader
    /// @return ara::core::Result<void>  Error on failure
    ara::core::Result<void> Serialize(Poco::BasicMemoryBinaryReader<char>& reader);

    /// @brief Serialize
    ///
    /// @param writer BasicMemoryBinaryWriter
    /// @return ara::core::Result<void> Error on failure
    ara::core::Result<void> Serialize(Poco::BasicMemoryBinaryWriter<char>& writer) const;

    /// @brief ParseJson
    ///
    /// @param grantNode Json nodes values
    /// @return ara::core::Result<void> Error on failure
    ara::core::Result<void> ParseJson(const apd::manifestreader::ManifestNode& grantNode);

    /// @brief Comparsion with other Grant
    ///
    /// @param other GrantDemoFC
    /// @returns -1 if less; 0 if identical and +1 otherwise
    virtual std::int32_t Compare(const Grant& other) const override;

private:
    ara::exec::ProcessSpecifier process_;  ///< Instance specifier for process
};

}  // namespace grant
}  // namespace ifc
}  // namespace iam
}  // namespace ara

#endif  // ARA_IAM_IFC_GRANT_GRANT_PROCESS_H_
