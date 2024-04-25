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

#ifndef ARA_PER_READ_WRITE_ACCESSOR_H_
#define ARA_PER_READ_WRITE_ACCESSOR_H_

#include <cstddef>
#include <cstdint>
#include <string>

#include "ara/core/result.h"

#include "ara/per/read_accessor.h"

///
/// @uptrace{SWS_PER_00002, fb49f277ba9a813303ba248e2a7970b903647cd7}
namespace ara
{
namespace per
{

/// @brief ReadWriteAccessor is used to read and write file data.
///
/// For unformatted reading it provides the read() method and for formatted
/// reading it provides the operator>>
///
/// For unformatted writing it provides the write() method and for formatted
/// writing it provides the operator<<. It also provides the ability to force an
/// fsync to flush the buffer of the operating system to the storage.
///
/// @uptrace{SWS_PER_00343, 0000000000000000000000000000000000000000}
class ReadWriteAccessor : public ReadAccessor
{
public:
    /// @brief Destructor for ReadWriteAccessor.
    virtual ~ReadWriteAccessor() = default;

    /// @brief Triggers flushing of the current file content to the physical storage.
    ///
    /// @uptrace{SWS_PER_00122, 357185c49bee0fbc5c940fda214bf66181283215}
    /// @uptrace{SWS_PER_00533, c461f71383a758d11278be8fc05201bd4c34c1d8}
    /// @threadsafety{no}
    /// @returns A Result of void. In case of an error, it contains any of the errors defined below, or a vendor
    /// specific error.
    virtual ara::core::Result<void> SyncToFile() noexcept = 0;

    /// @brief Reduces the size of the file to ’size’, effectively removing the current content of the file beyond this
    /// size.
    ///
    /// @uptrace{SWS_PER_00428, 19a0c522f9c5491deaa7554977910de9f7d7bbf8}
    /// @uptrace{SWS_PER_00532, a42339c8cce1544d87d7a35f45c519947e8472d2}
    /// @threadsafety{no}
    /// @returns A Result of void
    virtual ara::core::Result<void> SetFileSize(std::uint64_t size) noexcept = 0;

    /// @brief Writes the content of a StringView to the file.
    ///
    /// @uptrace{SWS_PER_00166, b7f292e667bcc5084a9c5178361c676d3b0c1834}
    /// @uptrace{SWS_PER_00529, eb7d12493da25e4e8c7b02c277417bee14543296}
    /// @threadsafety{no}
    /// @param[in] s A StringView containing the characters to be written.
    /// @returns A Result of void.
    virtual ara::core::Result<void> WriteText(ara::core::StringView s) noexcept = 0;

    /// @brief Writes the content of a Span of Byte to the file.
    ///
    /// @uptrace{SWS_PER_00423, 9e8343e5c81b4f9290f91b49e14cfbb8cc96f199}
    /// @uptrace{SWS_PER_00531, a0a039f5a404da21f77ed198c64125b037f37642}
    /// @threadsafety{no}
    /// @param[in] b A Span of Byte containing the bytes to be written.
    /// @returns A Result of void.
    virtual ara::core::Result<void> WriteBinary(ara::core::Span<const ara::core::Byte> b) noexcept = 0;

    /// @brief Writes the content of a StringView to the file.
    ///
    /// @uptrace{SWS_PER_00125, d83c5c95b5e5911562a026c727d4391a5006fca9}
    /// @uptrace{SWS_PER_00530, af7055e42183d2c9bb0fcedbbed804e67f66150c}
    /// @threadsafety{no}
    /// @param[in] s The StringView containing the characters to be written.
    /// @returns The ReadWriteAccessor object.
    virtual ReadWriteAccessor& operator<<(ara::core::StringView s) noexcept = 0;

    /// @brief Executes endl or flush operations on the file.
    ///
    /// @threadsafety{no}
    /// @param[in] op The operation to be executed on the file.
    /// @returns returns The WriteAccessor object.
    virtual ReadWriteAccessor& operator<<(ReadWriteAccessor& (*op)(ReadWriteAccessor&)) noexcept = 0;

    /// @brief Flushes the write buffer to the file.
    ///
    /// @threadsafety{no}
    virtual void flush() noexcept = 0;
};

/// @brief Writes a newline to the file and calls flush().
/// the WriteAccessor class.
///
/// @threadsafety{no}
/// @param[in] rwa The WriteAccessor object.
/// @returns The WriteAccessor object.
ReadWriteAccessor& endl(ReadWriteAccessor&) noexcept;

/// @brief Calls flush() on the file.
///
/// @threadsafety{no}
/// @param[in] rwa The WriteAccessor object.
/// @returns The WriteAccessor object.
ReadWriteAccessor& flush(ReadWriteAccessor&) noexcept;

}  // namespace per
}  // namespace ara

#endif  // ARA_PER_READ_WRITE_ACCESSOR_H_
