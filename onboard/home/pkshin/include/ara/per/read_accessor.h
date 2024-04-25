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

#ifndef ARA_PER_READ_ACCESSOR_H_
#define ARA_PER_READ_ACCESSOR_H_

#include <cstddef>
#include <cstdint>
#include <string>
#include <exception>

#include "ara/core/result.h"
#include "ara/core/string.h"
#include "ara/core/span.h"
#include "ara/per/char_traits_wrapper.h"
#include "ara/core/vector.h"

///
/// @uptrace{SWS_PER_00002, fb49f277ba9a813303ba248e2a7970b903647cd7}
namespace ara
{
namespace per
{
/// @brief Specification of origin used in MovePosition.
///
/// @uptrace{SWS_PER_00146, cac6ec3fca014ef10df08e165d6a181f86987ddd}
enum class Origin : uint32_t
{
    /// Seek from the beginning of the file.
    kBeginning = 0,
    /// Seek from the current position.
    kCurrent = 1,
    /// Seek from the end of the file.
    kEnd = 2,
};

/// @brief ReadAccessor is used to read file data.
///
/// It provides binary and text mode methods for checking or getting the current byte/character
/// (PeekByte/PeekChar, GetByte/GetChar) methods for reading a section of a binary/text file
/// (ReadBinary/ReadText), a method to read a line of text (ReadLine), and methods for checking
/// and setting the current position in the file (GetPosition, SetPosition, MovePosition, IsEof) and
/// for checking the current size of the file (GetSize).
///
/// @uptrace{SWS_PER_00342, 0000000000000000000000000000000000000000}
class ReadAccessor
{
public:
    /// @brief Destructor for ReadAccessor.
    ///
    /// @uptrace{SWS_PER_00417, d90ece1147ea5021685c3d257f8a1b93fd28bc73}
    virtual ~ReadAccessor() = default;

    /// @brief Returns the current position relative to the beginning of the file.
    ///
    /// @uptrace{SWS_PER_00162, 283706b07985015aae217fcb14942aa0f2ad81d8}
    /// @uptrace{SWS_PER_00517, 1ae94372179139dda043e2091f7f83ea63ef2c64}
    /// @threadsafety{no}
    /// @returns The current position in the file in bytes from the beginning of the file.
    virtual uint64_t GetPosition() const noexcept = 0;

    /// @brief Sets the current position relative to the beginning of the file.
    ///
    /// @uptrace{SWS_PER_00163, 23afe12a4277bbd0ff887c818e2981febcbf23f6}
    /// @uptrace{SWS_PER_00515, 80c9dee01572062a73547de332dca63897216307}
    /// @threadsafety{no}
    /// @param[in] position Current position in the file in bytes from the beginning of the file.
    virtual ara::core::Result<void> SetPosition(uint64_t position) noexcept = 0;

    /// @brief Moves the current position in the file relative to the Origin.
    ///
    /// @uptrace{SWS_PER_00164, eaee1fc18fd67b4d6d76a3c9bae05499f89b1862}
    /// @uptrace{SWS_PER_00516, bd5671c7a87badf282586ce677de7c10d950e846}
    /// @threadsafety{no}
    /// @param[in] origin Starting point from which to move ’offset’ bytes.
    /// @param[in] offset Offset in bytes relative to 'origin'. Can be positive in case of kBeginning and kCurrent and
    /// negative in case of kCurrent and kEnd.
    /// @returns A Result containing the new position in bytes from the beginning of the file.
    virtual ara::core::Result<uint64_t> MovePosition(Origin origin, int64_t offset) noexcept = 0;

    /// @brief Reads a number of characters into a String, starting from the current position.
    ///
    /// @uptrace{SWS_PER_00165, fbfe68580ec0f71900585e6cdefa0762afb8756a}
    /// @uptrace{SWS_PER_00523, 86cf6c7695a22934895fa5f9c3a58ad4a3265b16}
    /// @threadsafety{no}
    /// @param[in] n Number of characters to read.
    /// @returns A Result containing a String.
    virtual ara::core::Result<ara::core::String> ReadText(uint64_t n) noexcept = 0;

    /// @brief Returns the character at the current position of the file. The current position is not changed.
    ///
    /// @uptrace{SWS_PER_00167, 2730c98e86d19cd1c07ceb1df8d584f6a2eab071}
    /// @uptrace{SWS_PER_00520, 9fd87286583ce2c4810701f8ef6bf982a8c079fc}
    /// @threadsafety{no}
    /// @returns A Result containing a character.
    virtual ara::core::Result<char> PeekChar() const noexcept = 0;

    /// @brief Returns the character at the current position of the file, advancing the current position.
    ///
    /// @uptrace{SWS_PER_00168, 25a16be7533727de841e60dfc94811a549e8c538}
    /// @uptrace{SWS_PER_00521, 580aaed494d3e7a8e0140c47dc6f0cd643e3c3ec}
    /// @threadsafety{no}
    /// @returns A Result containing a character.
    virtual ara::core::Result<char> GetChar() noexcept = 0;

    /// @brief Returns the byte at the current position of the file. The current position is not changed.
    ///
    /// @uptrace{SWS_PER_00418, 798446fe244c0f1b18d46888d85f97c4743244b7}
    /// @uptrace{SWS_PER_00525, 891711f80f18656f5e0f62681b3cf944824b08af}
    /// @threadsafety{no}
    /// @returns A Result containing a byte.
    virtual ara::core::Result<ara::core::Byte> PeekByte() const noexcept = 0;

    /// @brief Returns the byte at the current position of the file, advancing the current position.
    ///
    /// @uptrace{SWS_PER_00419, b7dd5eab46e890863e6997ea24a9990b40baac78}
    /// @uptrace{SWS_PER_00526, 58a2377e98c40a7b9f8042efef1f678bb00d0730}
    /// @threadsafety{no}
    /// @returns A Result containing a byte.
    virtual ara::core::Result<ara::core::Byte> GetByte() noexcept = 0;

    /// @brief Reads all remaining characters into a String, starting from the current position.
    ///
    /// @uptrace{SWS_PER_00420, 046c8cdb617983699e4beafd78b53c9027044068}
    /// @uptrace{SWS_PER_00522, 97250cee74fe4454601116ff3c39c87dd9eb4e73}
    /// @threadsafety{no}
    /// @returns A Result containing a String.
    virtual ara::core::Result<ara::core::String> ReadText() noexcept = 0;

    /// @brief Reads all remaining bytes into a Vector of Byte, starting from the current position.
    ///
    /// @uptrace{SWS_PER_00421, befc18249666256799cc983769275f5b99a6cdb9}
    /// @uptrace{SWS_PER_00527, b9c43b6e07e39de686b69d5ebe0ff13a9cdaa02f}
    /// @threadsafety{no}
    /// @returns A Result containing a Vector of Byte.
    virtual ara::core::Result<ara::core::Vector<ara::core::Byte>> ReadBinary() noexcept = 0;

    /// @brief Reads a number of bytes into a Vector of Byte, starting from the current position.
    ///
    /// @uptrace{SWS_PER_00422, 656d205dad09d9265e210bdd8c2272ed33f570b4}
    /// @uptrace{SWS_PER_00528, 8b76831e5ba4f9935985c1b126e1622e6bca537f}
    /// @threadsafety{no}
    /// @param[in] n Number of bytes to read.
    /// @returns A Result containing a Vector of Byte.
    virtual ara::core::Result<ara::core::Vector<ara::core::Byte>> ReadBinary(uint64_t n) noexcept = 0;

    /// @brief Returns the current size of a file in bytes.
    ///
    /// @uptrace{SWS_PER_00424, 69a7a6bd7ada8adf65965531a4ef72a095905996}
    /// @uptrace{SWS_PER_00519, 7fb58a8df0d3e03afe4c50ebea8546b4fb32fa54}
    /// @threadsafety{no}
    /// @returns The current size of the file in bytes.
    virtual uint64_t GetSize() const noexcept = 0;

    /// @brief Reads a complete line of characters into a String, advancing the current position accordingly.
    ///
    /// @uptrace{SWS_PER_00119, fcc44e19bbb4083d7d86e67fb2e3bdd6f26541a8}
    /// @uptrace{SWS_PER_00524, 59276c5e5b9dbfa0272dab5881708a3863476ff6}
    /// @threadsafety{no}
    /// @param[in] delimiter The character that is used as delimiter.
    /// @returns A Result containing a String.
    virtual ara::core::Result<ara::core::String> ReadLine(char delimiter = '\n') noexcept = 0;

    /// @brief Checks if the current position is at end of file.
    ///
    /// @uptrace{SWS_PER_00107, 55970f3929cebb3103e2c23a5ca656d2a655a4a9}
    /// @uptrace{SWS_PER_00518, b27d69337708628b9f2461ebaf84e5683d752cf7}
    /// @threadsafety{no}
    /// @returns True if the current position is at the end of the file, false otherwise.
    virtual bool IsEof() const noexcept = 0;

    /// @brief Checks if no error occurred during an operation.
    ///
    /// @threadsafety{no}
    /// @returns True if no error occurred, false otherwise.
    virtual bool good() const noexcept = 0;

    /// @brief Checks if an error occurred during an operation.
    ///
    /// @threadsafety{no}
    /// @returns True if an error occurred, false otherwise.
    virtual bool fail() const noexcept = 0;

    /// @brief Checks if an error occurred during an operation which destroyed the integrity of the stream.
    ///
    /// @threadsafety{no}
    /// @returns True if an error occurred and the integrity of the stream was lost, false otherwise.
    virtual bool bad() const noexcept = 0;

    /// @brief Checks if an error occurred during an operation which destroyed the integrity of the stream.
    ///
    /// @threadsafety{no}
    /// @returns True if an error occurred and the integrity of the stream was lost, false otherwise.
    virtual bool operator!() const noexcept = 0;

    /// @brief Checks if no error occurred during operation, functionally equivalent to
    /// good().
    ///
    /// @threadsafety{no}
    /// @returns True if no error occurred, false otherwise.
    explicit virtual operator bool() const noexcept = 0;

    /// @brief Clears all error flags.
    ///
    /// @threadsafety{no}
    virtual void clear() noexcept = 0;
};

}  // namespace per
}  // namespace ara

#endif  // ARA_PER_READ_ACCESSOR_H_
