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

#ifndef ARA_PER_ERROR_DOMAIN_H_
#define ARA_PER_ERROR_DOMAIN_H_

#include <ostream>
#include <utility>
#include <iostream>
#include <cstdint>

#include "ara/core/error_domain.h"
#include "ara/core/error_code.h"
#include "ara/core/exception.h"

///
/// @uptrace{SWS_PER_00002, fb49f277ba9a813303ba248e2a7970b903647cd7}
namespace ara
{
namespace per
{

/// @brief Defines the errors for Persistency.
///
/// @uptrace{SWS_PER_00311, 2f2feaa458f35189e003198a8e07f884d3a7b38c}
/// @uptrace{SWS_PER_00472, 86b2da90f71ea1812b5852a0d631a06ef27c6381}
enum class PerErrc : ara::core::ErrorDomain::CodeType
{
    /// The requested Key-Value Storage or File Storage is not configured in the AUTOSAR model.
    kStorageNotFound = 1,
    /// The provided key cannot be not found in the Key-Value Storage.
    kKeyNotFound = 2,
    /// Opening a file for writing or changing, or synchronizing a key failed, because the storage is configured
    /// read-only.
    kIllegalWriteAccess = 3,
    /// An error occurred when accessing the physical storage, e.g. because of a corrupted file system or
    /// corrupted hardware, or because of insufficient access rights.
    kPhysicalStorageFailure = 4,
    /// The structural integrity of the storage could not be established. This can happen when the internal
    /// structure of a Key-Value Storage or the meta data of a File Storage is corrupted.
    kIntegrityCorrupted = 5,
    /// The validation of redundancy measures failed for a single key, for the whole Key-Value Storage,
    /// for a single file, or for the whole File Storage.
    kValidationFailed = 6,
    /// The encryption or decryption failed for a single key, for the whole Key-Value Storage, for a single file,
    /// or for the whole File Storage.
    kEncryptionFailed = 7,
    /// The provided data type does not match the stored data type.
    kDataTypeMismatch = 8,
    /// The operation could not be performed because no initial value is available.
    kInitValueNotAvailable = 9,
    /// The operation could not be performed because the resource is currently busy.
    kResourceBusy = 10,
    /// The allocated storage quota was exceeded.
    kOutOfStorageSpace = 12,
    /// The requested file cannot be not found in the File Storage.
    kFileNotFound = 13,
    /// SetPosition tried to move to a position that is not reachable (i.e. which is smaller than zero or
    /// greater than the current size of the file).
    kInvalidPosition = 15,
    /// The application tried to read from the end of the file or from an empty file.
    kIsEof = 16,
    /// Opening a file failed because the requested combination of OpenModes is invalid.
    kInvalidOpenMode = 17,
    /// SetFileSize tried to set a new size that is bigger than the current file size
    kInvalidSize = 18
};

///
/// @brief Exception type thrown by persistency classes
///
/// @uptrace{SWS_PER_00354, b8838a168fe87b26579f593e4812accd53bee90a}
class PerException : public ara::core::Exception
{
public:
    ///
    /// @brief Construct a new persistency exception object containing an Error object.
    ///
    /// @uptrace{SWS_PER_00355, f4e8ac095f9b21f4d62f62a8c916ecdb8d0174cc}
    explicit PerException(ara::core::ErrorCode errorCode) noexcept
        : ara::core::Exception(std::move(errorCode))
    { }
};

/// @brief Defines the error domain for Persistency.
///
/// @uptrace{SWS_PER_00312, 1d0be166af493a7dcda106a88654372afd4f35fe}
class PerErrorDomain final : public ara::core::ErrorDomain
{
    /// @brief Key ID for persistency error domain.
    ///
    static const ErrorDomain::IdType kId{0x8000000000000101};

public:
    /// @brief Defines an alias for the error code value enumeration.
    ///
    /// @uptrace{SWS_PER_00411, 148098629ea59e97c71cc06bf517586aba9dcbd2}
    using Errc = PerErrc;

    /// @brief Defines an alias for the exception base class.
    ///
    /// @uptrace{SWS_PER_00412, 2b04c157c7a67bfb36c736f02b5dd6ed13d38693}
    using Exception = PerException;

    /// @brief Creates a PerErrorDomain instance.
    ///
    /// @uptrace{SWS_PER_00313, 73e87f3db563e4a80b68c22aa878694054fff4ed}
    PerErrorDomain() noexcept
        : ErrorDomain(kId)
    { }

    /// @brief Returns the name of the error domain
    ///
    /// @uptrace{SWS_PER_00314, a33b8e2c9df4eff24527c51b2c0d60394106058e}
    /// @uptrace{SWS_PER_00353, 3da1e6d265c2592b7e8c8e609908fcd73b181400}
    /// @returns The name of the error domain
    const char* Name() const noexcept override
    {
        return "Per";
    }

    /// @brief Returns the message associated with the error code.
    ///
    /// @uptrace{SWS_PER_00315, 03fb1610d5c79bcf51f0bdcf2dc36ef855212cf9}
    /// @uptrace{SWS_PER_00475, 8ec06e623ee6b5e47b4fcf51d185eafc1774551e}
    /// @param[in] errorCode The error code number
    /// @returns The message associated with the error code.
    const char* Message(CodeType errorCode) const noexcept override
    {
#if defined(__GNUC__)
#    pragma GCC diagnostic push
#    pragma GCC diagnostic error "-Wswitch-enum"
#endif
        Errc const code = static_cast<Errc>(errorCode);
        switch (code) {
        case PerErrc::kStorageNotFound:
            return "The requested Key-Value Storage or File Storage is not configured in the AUTOSAR model";
        case PerErrc::kKeyNotFound:
            return "The provided key cannot be not found in the Key-Value Storage";
        case PerErrc::kIllegalWriteAccess:
            return "Opening a file for writing or changing, or synchronizing a key failed, because the storage is "
                   "configured read-only";
        case PerErrc::kPhysicalStorageFailure:
            return "An error occurred when accessing the physical storage";
        case PerErrc::kIntegrityCorrupted:
            return "The structural integrity of the storage could not be established";
        case PerErrc::kValidationFailed:
            return "The validation of redundancy measures failed";
        case PerErrc::kEncryptionFailed:
            return "The encryption or decryption failed";
        case PerErrc::kDataTypeMismatch:
            return "The provided data type does not match the stored data type";
        case PerErrc::kInitValueNotAvailable:
            return "The operation could not be performed because no initial value is available";
        case PerErrc::kResourceBusy:
            return "The operation could not be performed because the resource is currently busy";
        case PerErrc::kOutOfStorageSpace:
            return "The allocated storage quota was exceeded";
        case PerErrc::kFileNotFound:
            return "The file was not found";
        case PerErrc::kInvalidPosition:
            return "SetPosition tried to move to a position that is not reachable";
        case PerErrc::kIsEof:
            return "The application tried to read from the end of the file or from an empty file";
        case PerErrc::kInvalidOpenMode:
            return "Opening a file failed because the requested combination of OpenModes is invalid";
        case PerErrc::kInvalidSize:
            return "SetFileSize tried to set a new size that is bigger than the current file size";
        default:
            return "Unknown error";
        }

#if defined(__GNUC__)
#    pragma GCC diagnostic pop
#endif
    }

    /// @brief Throws the exception associated with the error code.
    ///
    /// @uptrace{SWS_PER_00350, c45f7e4224bbad1ce10dd709f2889533b43e3752}
    /// @uptrace{SWS_PER_00476, e4294a2d61035538fc1dcd1b6aa9c6b4d47358af}
    void ThrowAsException(const ara::core::ErrorCode& errorCode) const noexcept(false) override
    {
        ara::core::ifc::ThrowOrTerminate<Exception>(errorCode);
    }
};

#if defined(__GNUC__)
#    pragma GCC diagnostic pop
#endif

namespace internal
{
static const PerErrorDomain g_perErrorDomain;
}

/// @brief Returns the global PerErrorDomain object.
///
/// @uptrace{SWS_PER_00352, 95da8a66a619be786264ee4ba5786a5a18d1c7f7}
/// @uptrace{SWS_PER_00473, efe36f7fb5d4e0c231fd3c927dafc4c5fe0063d5}
inline constexpr const ara::core::ErrorDomain& GetPerDomain()
{
    return internal::g_perErrorDomain;
}

/// @brief Creates an error code.
///
/// @uptrace{SWS_PER_00351, a7cdd515f6ae2c1afac72df296b43f137dfff5ac}
/// @uptrace{SWS_PER_00474, 41fd5fc331ccc06519bc91f2b8af044a06d6f763}
inline constexpr ara::core::ErrorCode MakeErrorCode(PerErrc code, ara::core::ErrorDomain::SupportDataType data)
{
    return ara::core::ErrorCode(static_cast<ara::core::ErrorDomain::CodeType>(code), GetPerDomain(), data);
}

}  // namespace per
}  // namespace ara

#endif  // ARA_PER_ERROR_DOMAIN_H_
