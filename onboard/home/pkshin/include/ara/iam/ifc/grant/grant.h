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
/// @brief Base class for all grants

#ifndef ARA_IAM_IFC_GRANT_GRANT_H_
#define ARA_IAM_IFC_GRANT_GRANT_H_

#include "ara/core/result.h"
#include "ara/core/string.h"
#include "ara/iam/ifc/grant/grant_constants.h"
#include "ara/iam/ifc/grant/grant_serialization_error_domain.h"

namespace ara
{
namespace iam
{
namespace ifc
{
namespace grant
{

/// @brief Base class of all grants
///
/// Instances of this class should implement the following non virtual methods and/or
/// private the following contants.
/// - static ara::core::Result<GrantDemoFC> ParseJson(const apd::manifestreader::ManifestNode& grantNode);
/// - ara::core::Result<std::size_t> SerializeWrite(char* buf, const std::size_t buf_length) const
/// - static ara::core::Result<GrantDemoFC> SerializeRead(const char* buf, const std::size_t buf_length, std::size_t*
///       bytes_read)
/// - static const char* kTypeStr;
///
/// By using these names and interfaces the same function names can be used in case switches / if-else comparisons
/// are needed to distinguish between different class types.

class Grant
{
public:
    /// @brief Destroy the Grant object
    virtual ~Grant() = default;

    /// @brief Virtual serialize write method
    ///
    /// @param buf Buffer to write to
    /// @param buf_length Length of buf in bytes
    /// @returns number of bytes written or an GrantSerializationErrc error code
    virtual ara::core::Result<std::size_t> Write(char* buf, const std::size_t buf_length) const = 0;

    /// @brief Comparison with other Grant instance
    ///
    /// @param other Grant
    /// @returns -1 if less; 0 if identical and +1 otherwise
    virtual int32_t Compare(const Grant& other) const;

    /// @brief Comparison
    ///
    /// @param other Grant
    /// @returns true, if *this and other are from the same type and its values are identical
    bool IsEqual(const Grant& other) const
    {
        return (0 == this->Compare(other));
    }

    /// @brief Get the Grant Type object
    ///
    /// @returns EGrantType
    inline EGrantType GetGrantType() const
    {
        return kGrandType_;
    }

    /// @brief ToString method for logging and debugging purposes
    ///
    /// @returns String
    virtual ara::core::String ToString() const = 0;

    static const char* kJsonTypeAttributeName;  ///< Static constant for the name containing the type of grant

    /// @brief Helper method to obtain the type from a data stream
    ///
    /// @param buf Buffer to read from
    /// @param buf_length Length of buf in bytes
    /// @returns EGrantType or an GrantSerializationErrc error code
    static ara::core::Result<EGrantType> ParseGrantType(const char* buf, const std::size_t buf_length);

protected:
    /// @brief Construct a new Grant object
    ///
    /// @param kGrandType EGrantType. Each child of Grant must have its own unique identifer
    Grant(const EGrantType kGrandType);

    /// @brief Copy constructor
    ///
    /// @param other Grant
    Grant(const Grant& other);

    /// @brief Move constructor
    ///
    /// @param other Grant
    Grant(Grant&& other);

    /// @brief Comparison operator
    ///
    /// @param other Grant
    /// @returns true, if this and other are instances of GrantProcess and contain the same values
    bool operator==(const Grant& other) const;

    /// @brief Binary serialization (write)
    ///
    /// @param buf Buffer to write to
    /// @param buf_length Length of buf in bytes
    /// @returns number of bytes written or an GrantSerializationErrc error code
    ara::core::Result<std::size_t> SerializeWriteHeader(char*& buf, std::size_t& buf_length) const;

    /// @brief Parses the header information
    ///
    /// @param buf Buffer to read from
    /// @param buf_length Length of buf in bytes
    /// @returns EGrantType and the bytes read to obtain the header information.
    ///          In case of an error a GrantSerializationErrc error code is returned
    static ara::core::Result<std::pair<EGrantType, std::size_t>> SerializeReadHeader(const char* buf,
        const std::size_t buf_length);

private:
    const EGrantType
        kGrandType_;  ///< Type of this grant. Value must be unique among each of the child classes of Grant
};

}  // namespace grant
}  // namespace ifc
}  // namespace iam
}  // namespace ara

#endif  // ARA_IAM_IFC_GRANT_GRANT_H_
