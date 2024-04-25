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

/**
 * @file
 * @brief This file contains the stream based message handler.
 *
 * @attention Due to limitation of the C++ language, some internal implementation
 * (e.g. the function bodies) are coded directly into this header file.
 * Such code is NOT meant to be used or referred to by a user directly,
 * and is subject to CHANGE WITHOUT NOTICE.
 * Therefore DO NOT DEPEND ON any implementation details!
 */

#ifndef APD_ARA_LOG_LOG_STREAM_H_
#define APD_ARA_LOG_LOG_STREAM_H_

#include "ara/core/string_view.h"
#include "ara/core/error_code.h"
#include "ara/core/string.h"
#include "ara/core/instance_specifier.h"
#include "ara/core/span.h"

#include "ara/log/common.h"

#include <chrono>
#include <iomanip>
#include <sstream>
#include <type_traits>
#include <utility>

namespace ara
{
namespace log
{

/// @uptrace{SWS_LOG_00206, 988f4369fdaefc2c8027fbc296b75d04c99be63d}
enum class Fmt : std::uint16_t
{
    kDefault = 0,  ///< implementation-defined formatting
    kDec = 1,  ///< decimal (signed/unsigned)
    kOct = 2,  ///< octal
    kHex = 3,  ///< hexadecimal
    kBin = 4,  ///< binary
    kDecFloat = 5,  ///< decimal float (like printf "%f")
    kEngFloat = 6,  ///< engineering float (like printf "%e")
    kHexFloat = 7,  ///< hex float (like printf "%a")
    kAutoFloat = 8,  ///< automatic "shortest" float (like printf "%g")
};

/// @uptrace{SWS_LOG_00207, 4f80715e4a4b85564506626e0a4addd2f41d94d6}
struct Format final
{
    /// @uptrace{SWS_LOG_00225, c75ba103268046b591dcecb4f48fa5a46095d2b3}
    Fmt fmt;

    /// @uptrace{SWS_LOG_00226, 209b7ca700b9fa468d64882ca0460e9d52d35ec4}
    std::uint16_t precision;
};

/// @uptrace{SWS_LOG_00208, 47d211edb36067f78850e01d8248e766fd2ce37f}
constexpr Format Dflt() noexcept
{
    return Format{Fmt::kDefault, 0};
}

/// @uptrace{SWS_LOG_00209, 8598d2fef49b1b149d0b23f80d624a8c45f6556a}
constexpr Format Hex() noexcept
{
    return Format{Fmt::kHex, 65535};
}

/// @uptrace{SWS_LOG_00210, 056fc577e73e7c13cb97a08e51f6c5866c9f5f22}
constexpr Format Hex(std::uint16_t precision) noexcept
{
    return Format{Fmt::kHex, precision};
}

/// @uptrace{SWS_LOG_00211, 363b77099758afb6c66cde3a61bbcf4f5980a5d2}
constexpr Format Dec() noexcept
{
    return Format{Fmt::kDec, 65535};
}

/// @uptrace{SWS_LOG_00212, 68aef4bb59a0269a9288e58d5e8bfb64425c2afd}
constexpr Format Dec(std::uint16_t precision) noexcept
{
    return Format{Fmt::kDec, precision};
}

/// @uptrace{SWS_LOG_00213, b1f8f28f54292a0c66e44274cdd1f98254484fc4}
constexpr Format Oct() noexcept
{
    return Format{Fmt::kOct, 65535};
}

/// @uptrace{SWS_LOG_00214, 9679b7cbc8c709df40913bdfea680d0dacdb3d1c}
constexpr Format Oct(std::uint16_t precision) noexcept
{
    return Format{Fmt::kOct, precision};
}

/// @uptrace{SWS_LOG_00215, f8fafe40c4435c5c295adc141e3c36c4227cc83d}
constexpr Format Bin() noexcept
{
    return Format{Fmt::kBin, 65535};
}

/// @uptrace{SWS_LOG_00216, 51685f8dcdf683031c01084b69a75a218377eb9b}
constexpr Format Bin(std::uint16_t precision) noexcept
{
    return Format{Fmt::kBin, precision};
}

/// @uptrace{SWS_LOG_00217, 10217eef94cd6bff12997de7d407c8d66f8789f1}
constexpr Format DecFloat(std::uint16_t precision = 6) noexcept
{
    return Format{Fmt::kDecFloat, precision};
}

/// @uptrace{SWS_LOG_00218, a34e821bcfb1a40a83f2b350c2ba90a996fae187}
constexpr Format DecFloatMax() noexcept
{
    return Format{Fmt::kDecFloat, 65535};
}

/// @uptrace{SWS_LOG_00219, 1ad908ee031fb70c725848d44ab11548b4dce962}
constexpr Format EngFloat(std::uint16_t precision = 6) noexcept
{
    return Format{Fmt::kEngFloat, precision};
}

/// @uptrace{SWS_LOG_00220, f595f0ed85810d07ac7b9a78e1daf03db0c892d6}
constexpr Format EngFloatMax() noexcept
{
    return Format{Fmt::kEngFloat, 65535};
}

/// @uptrace{SWS_LOG_00221, 938d5ee9eb784ca0f2419fbdeaf726b11b75d5d3}
constexpr Format HexFloat(std::uint16_t precision) noexcept
{
    return Format{Fmt::kHexFloat, precision};
}

/// @uptrace{SWS_LOG_00222, 0772b3e81d7c60b6d34212d91516f1a053723b20}
constexpr Format HexFloatMax() noexcept
{
    return Format{Fmt::kHexFloat, 65535};
}

/// @uptrace{SWS_LOG_00223, 09e02ece9f9eaf88862b689198c9209553336bc4}
constexpr Format AutoFloat(std::uint16_t precision = 6) noexcept
{
    return Format{Fmt::kAutoFloat, precision};
}

/// @uptrace{SWS_LOG_00224, 788cf6a339e124a01bc530d04c9b7ede68367b71}
constexpr Format AutoFloatMax() noexcept
{
    return Format{Fmt::kAutoFloat, 65535};
}

/**
 * @defgroup logstream Log Stream
 * @brief Stream based message handler.
 */

/**
 * @ingroup logstream
 * @class LogStream
 *
 * @brief Class representing a log message.
 *
 * Insert stream operators are to be used for appending data.
 *
 * @note Normally, you would not use this class directly, but use one of the log methods provided in
 * the main logging API or an instance of the Logger class instead. Those methods automatically setup
 * an object of this class with the given log severity level. The only reason to get in touch with this
 * class directly is if you want to hold a @c LogStream object longer than the default one-statement scope.
 * This is useful in order to create log messages that are distributed over multiple code lines.
 * See @c Flush() method for further information.
 *
 * Every call on the insert stream operator against this object will be processed as a call to the
 * underlying DLT back-end, which means that the message buffer is going to be filled with payload data.
 *
 * Once this object gets out of scope (in normal usage as soon as the statement ends), its @c dtor is
 * calling the message flush command on the DLT back-end which marks the message buffer as ready to be
 * sent out remotely.
 *
 * @c LogStream supports all of the primitive data types (PoDs) natively. However, it can be easily extended
 * for your own complex types by providing a stream operator that makes use of already supported types.
 *
 * @code
 * struct MyCustomType {
 *   int8_t foo;
 *   std::string bar;
 * };
 *
 * LogStream& operator<<(LogStream& out, const MyCustomType& value) {
 *     return (out << value.foo << value.bar);
 * }
 *
 * g_loggerCtx0.LogDebug() << MyCustomType{42, "The answer is"};
 * @endcode
 */

class Logger;  // forward declare Logger class

/**
 * Helper struct that is utilized as custom type.
 * Holds an integer value that will be logged with a special format.
 */
struct LogHex8
{
    uint8_t value;
};

struct LogHex16
{
    uint16_t value;
};

struct LogHex32
{
    uint32_t value;
};

struct LogHex64
{
    uint64_t value;
};

struct LogBin8
{
    uint8_t value;
};

struct LogBin16
{
    uint16_t value;
};

struct LogBin32
{
    uint32_t value;
};

struct LogBin64
{
    uint64_t value;
};

/// @uptrace{SWS_LOG_00261, d562bf54a25dba4427b7b528fb57969ded5b6eed}
template <typename T>
struct Argument
{
    const T& value;
    const char* const name;
    const char* const unit;
    Format fmt;
};

/// @uptrace{SWS_LOG_00173, f19da8699a6c98f7b82bc3dcf4415378fd9caa42}
class LogStream final
{
public:
    LogStream() = delete;

    /**
     * @brief Creates the message stream object.
     *
     * Initiates it with the given log level directly on the back-end.
     *
     * @param[in] logLevel  The severity level of this message
     * @param[in] logger    The associated logger context
     */
    LogStream(LogLevel logLevel, const Logger& logger) noexcept;

    /**
     * @brief Flushes the log message before destroying the stream object.
     *
     * Unless it was not explicitly flushed before, by calling @c Flush().
     */
    ~LogStream();

    /*
     * The big five.
     *
     * We actually don't want this class movable or copyable, but enforce RVO instead.
     * Since "Guaranteed copy elision" will be supported up from C++17, declaring the move ctor
     * without definition is a workaround and is necessary because we have a custom dtor.
     * With the missing move ctor implementation, explicit calls of std::move() on objects
     * of this class, will be prevented by a compile error.
     */
    LogStream(const LogStream&) = delete;
    LogStream& operator=(const LogStream&) = delete;
    LogStream(LogStream&&);
    LogStream& operator=(LogStream&&) = delete;

    /**
     * @brief Processes the current log buffer.
     *
     * And prepares the object for new message in one go. Further usage of the @c LogStream object
     * after calling this method will end up in a new message. Use this method in case you want to
     * build your message distributed over multiple code lines.
     *
     * @code
     * LogStream logInfoBuilder{g_loggerCtx0.LogInfo()};
     * logInfoBuilder << "message builder...";
     *
     * logInfoBuilder << 123;
     * logInfoBuilder << "one more param.";
     * logInfoBuilder << 4.56;
     * logInfoBuilder << "we're done...";
     * logInfoBuilder.Flush(); // sends out what is in the buffer as one single message
     *
     * logInfoBuilder << "new message initiated...";
     * @endcode
     *
     * @note Calling @c Flush() is only necessary if the @c LogStream object is going to be re-used within
     * the same scope. Otherwise, if the object goes out of scope (e.g. end of function block), than
     * flush operation will be anyway done internally by the @c dtor.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00039, 1c4ee74f10912046afb1e4a31fba90dd5770a6fc}
     */
    void Flush() noexcept;

    /// @name DLT primitive types
    /// Build-in support for DLT native types.
    /// @{
    /**
     * @brief Writes boolean parameter into message.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00040, dd4ce402458424c101c832b53b04f8768c67f004}
     * @uptrace{SWS_LOG_00230, 79d255233e4d65c09bccbef7eb72944dd5a66290}
     * @uptrace{SWS_LOG_00235, 175178ccfbbb1ffcec786f9d02d4215fd191b30c}
     */
    LogStream& operator<<(bool value) noexcept;
    /**
     * @brief Writes unsigned int 8 bit parameter into message.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00041, d38285f52fc70cad30ac34e5ca25e9018ba2941c}
     */
    LogStream& operator<<(uint8_t value) noexcept;
    /**
     * @brief Writes unsigned int 16 bit parameter into message.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00042, c75c9b2e10e7a80101e9293e414da3e53df328a2}
     */
    LogStream& operator<<(uint16_t value) noexcept;
    /**
     * @brief Writes unsigned int 32 bit parameter into message.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00043, 721fd4577e4a814ec9be9367d68a4bb1a3268f70}
     */
    LogStream& operator<<(uint32_t value) noexcept;
    /**
     * @brief Writes unsigned int 64 bit parameter into message.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00044, a33ceb200458f47d488a360bbf0c3034d4709427}
     */
    LogStream& operator<<(uint64_t value) noexcept;
    /**
     * @brief Writes signed int 8 bit parameter into message.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00045, b231539f51d9c5bb31e1e09489bb33d4c8d1cdbf}
     */
    LogStream& operator<<(int8_t value) noexcept;
    /**
     * @brief Writes signed int 16 bit parameter into message.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00046, 47ffcf7ded7b81d76868e95f4bae5274b7af92c7}
     */
    LogStream& operator<<(int16_t value) noexcept;
    /**
     * @brief Writes signed int 32 bit parameter into message.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00047, f685e98f60acf0eede86060c3c29028cc483a761}
     */
    LogStream& operator<<(int32_t value) noexcept;
    /**
     * @brief Writes signed int 64 bit parameter into message.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00048, d0f4ecf0577c5ed8795f35e0ae473c82bda86e6a}
     */
    LogStream& operator<<(int64_t value) noexcept;
    /**
     * @brief Writes float 32 bit parameter into message.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00049, 707d6f81923fba412ca67635c618817660977cda}
     */
    LogStream& operator<<(float value) noexcept;
    /**
     * @brief Writes float 64 bit parameter into message.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00050, 45120e9baa9665f562a4ce37e13423d2614390b6}
     */
    LogStream& operator<<(double value) noexcept;
    /// @}

    /// @name DLT special types
    /// Build-in support for DLT special format types.
    /// @{

    /**
     * @brief Writes unsigned int parameter into message, formatted as hexadecimal 8 digits.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00053, 4eff54bb1c4b76ed7305f339207dd95d77b6241c}
     */
    LogStream& operator<<(const LogHex8& value) noexcept;

    /**
     * @brief Writes unsigned int parameter into message, formatted as hexadecimal 16 digits.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00054, ad7ac021bbe7bb139eacae5843fd4aa0388f837e}
     */
    LogStream& operator<<(const LogHex16& value) noexcept;

    /**
     * @brief Writes unsigned int parameter into message, formatted as hexadecimal 32 digits.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00055, dc9396ae3afae043923d5db60992666ab5c27fdc}
     */
    LogStream& operator<<(const LogHex32& value) noexcept;

    /**
     * @brief Writes unsigned int parameter into message, formatted as hexadecimal 64 digits.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00056, d729c4f9a31565851f1cc6d9da4c5c1b41f6f3bb}
     */
    LogStream& operator<<(const LogHex64& value) noexcept;

    /**
     * @brief Writes unsigned int parameter into message, formatted as binary 8 digits.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00057, 1c1f2cc9e7f1acfb6f9db0b3d896bc2aa665b91b}
     */
    LogStream& operator<<(const LogBin8& value) noexcept;

    /**
     *  @brief Writes unsigned int parameter into message, formatted as binary 16 digits.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00058, 6b5b2636b868b25e07b83a2722f222dd01eaa763}
     */
    LogStream& operator<<(const LogBin16& value) noexcept;

    /**
     *  @brief Writes unsigned int parameter into message, formatted as binary 32 digits.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00059, 49fce8e5bc863b4640d3a1095c7386938e396f16}
     */
    LogStream& operator<<(const LogBin32& value) noexcept;

    /**
     *  @brief Writes unsigned int parameter into message, formatted as binary 64 digits.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00060, 3628b35904da885df2f444178c4b1fb798fea412}
     */
    LogStream& operator<<(const LogBin64& value) noexcept;

    /**
     *  @brief Writes ara::core::StringView into message.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00062, 3855d739b1372c9fcf6939b44873b5c700fc5ffa}
     * @uptrace{SWS_LOG_00236, d9c429310123e9ab93b0ff9131b8563b2f0e052d}
     */
    LogStream& operator<<(const ara::core::StringView value) noexcept;

    /**
     *  @brief Writes null terminated UTF8 string into message. (NOT sPECIFIED. WILL BE REMOVED IN FUTURE!)
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00051, bf7602643bdc4a6a6b57580f77baf3fdbd9f3d53}
     * @uptrace{SWS_LOG_00236, d9c429310123e9ab93b0ff9131b8563b2f0e052d}
     */
    LogStream& operator<<(const char* const value) noexcept;

    /**
     * @brief Add source file location into the message
     *
     * This function has no effect if another member function that adds
     * content to the current message has already been called.
     *
     * @param file the source file identifier
     * @param line the source file line number
     * @returns *this
     *
     * @uptrace{SWS_LOG_00129, 8d4d22896776b7e5d78fa51a16fae152525a0d79}
     */
    LogStream& WithLocation(ara::core::StringView file, int line) noexcept;

    /// @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
    /// @uptrace{SWS_LOG_00124, a81802d12e4f462ccd39e3ca255ac41844e52000}
    friend LogStream& operator<<(LogStream& out, const ara::core::ErrorCode& value) noexcept;

    /**
     * @brief Write a byte sequence into message
     *
     * This call shall copy the sequence of core::Byte objects as-is into the message.
     *
     * When output to the console, this byte sequence shall be shown
     * as a sequence of apostrophe-separated list of hexadecimal octet-pairs,
     * for instance: "48'65'6c'6c'6f"
     *
     * @param data a Span<const Byte> covering the range to be logged
     * @returns *this
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00128, fd2458a7fae970dd90ffa55a992e251d21b7a3f5}
     * @uptrace{SWS_LOG_00231, 97611acdc260f6050a935da6425c777011f6234f}
     * @uptrace{SWS_LOG_00237, 014bd8538af0dd7d5de4734aa535e6e5c53c8853}
     */
    LogStream& operator<<(ara::core::Span<const ara::core::Byte> data) noexcept;
    /// @}

    /**
     * @brief Writes an argument with attributes into the message
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00203, b365b09dd8f9b467900ea7e8a175bd5764f79a02}
     * @uptrace{SWS_LOG_00229, efe16309df388a46e8b7149db44408f9cf2b216c}
     */
    template <typename T>
    LogStream& operator<<(const Argument<T>& arg) noexcept
    {
        if (isInitialized()) {
            putValue(arg.value, arg.name, arg.unit, arg.fmt);
        }
        return *this;
    }

private:
    bool isInitialized() const noexcept;
    std::size_t getBufSize() const noexcept;

    void putValue(bool value, const char* name, const char* /*ignore*/, Format const& fmt) noexcept;
    void putValue(uint8_t value, const char* name, const char* unit, Format const& fmt) noexcept;
    void putValue(uint16_t value, const char* name, const char* unit, Format const& fmt) noexcept;
    void putValue(uint32_t value, const char* name, const char* unit, Format const& fmt) noexcept;
    void putValue(uint64_t value, const char* name, const char* unit, Format const& fmt) noexcept;
    void putValue(int8_t value, const char* name, const char* unit, Format const& fmt) noexcept;
    void putValue(int16_t value, const char* name, const char* unit, Format const& fmt) noexcept;
    void putValue(int32_t value, const char* name, const char* unit, Format const& fmt) noexcept;
    void putValue(int64_t value, const char* name, const char* unit, Format const& fmt) noexcept;
    void putValue(float value, const char* name, const char* unit, Format const& fmt) noexcept;
    void putValue(double value, const char* name, const char* unit, Format const& fmt) noexcept;
    void putValue(const ara::core::StringView& value,
        const char* name,
        const char* /*ignore*/,
        Format const& fmt) noexcept;
    void putValue(const char* value, const char* name, const char* /*ignore*/, Format const& fmt) noexcept;
    void putValue(const ara::core::Span<const ara::core::Byte>& value,
        const char* name,
        const char* /*ignore*/,
        Format const& fmt) noexcept;

    internal::LogReturnValue logRet_{internal::LogReturnValue::kReturnOk};
    void* logLocalData_;
};

// Support for LogStream objects as rvalue reference. Enables custom type <<operator overload as first call
template <typename T>
LogStream& operator<<(LogStream&& out, T&& value) noexcept
{
    return (out << std::forward<T>(value));
}

// Support for signed long long (transforms into int64_t on 64 bit platforms)
template <typename T = void,
    typename std::enable_if<((!std::is_same<long long, int64_t>::value) && (sizeof(long long) == sizeof(int64_t))),
        T>::type* = nullptr>
inline LogStream& operator<<(LogStream& out, long long value) noexcept
{
    return (out << static_cast<int64_t>(value));
}

// Support for signed long (transforms into int32_t on 32 bit platforms)
template <typename T = void,
    typename std::enable_if<((!std::is_same<long, int32_t>::value) && (sizeof(long) == sizeof(int32_t))),
        T>::type* = nullptr>
inline LogStream& operator<<(LogStream& out, long value) noexcept
{
    return (out << static_cast<int32_t>(value));
}

// Support for unsigned long long (transforms into uint64_t on 64 bit platforms)
template <typename T = void,
    typename std::enable_if<((!std::is_same<unsigned long long, uint64_t>::value)
                                && (sizeof(unsigned long long) == sizeof(uint64_t))),
        T>::type* = nullptr>
inline LogStream& operator<<(LogStream& out, unsigned long long value) noexcept
{
    return (out << static_cast<uint64_t>(value));
}

// Support for unsigned long (transforms into uint32_t on 32 bit platforms)
template <typename T = void,
    typename std::enable_if<((!std::is_same<unsigned long, uint32_t>::value)
                                && (sizeof(unsigned long) == sizeof(uint32_t))),
        T>::type* = nullptr>
inline LogStream& operator<<(LogStream& out, unsigned long value) noexcept
{
    return (out << static_cast<uint32_t>(value));
}

/// @brief Writes LogLevel enum parameter as text into message.
///
/// @uptrace{SWS_LOG_00063, fb6d224a38bdec6dc431463e5fe6d9b773f0726c}
LogStream& operator<<(LogStream& out, LogLevel value) noexcept;

constexpr LogHex32 loghex(uint32_t val) noexcept
{
    return LogHex32{val};
}
constexpr LogHex64 loghex(uint64_t val) noexcept
{
    return LogHex64{val};
}

/// @brief Writes pointer address into message, formatted as hexadecimal.
/// @uptrace{SWS_LOG_00127, 4992e547f72ebae55b6be2ec37aaca3cf49c6239}
inline LogStream& operator<<(LogStream& out, const void* const value) noexcept
{
    return (out << loghex(reinterpret_cast<std::uintptr_t>(value)));
}

/// @brief Writes std::string into message.
inline LogStream& operator<<(LogStream& out, const std::string& value) noexcept
{
    return (out << value.c_str());
}

/// @uptrace{SWS_LOG_00125, 315099f15a8963d3b0c762f904ad635fd41ff8ef}
template <typename Rep, typename Period>
inline LogStream& operator<<(LogStream& out, const std::chrono::duration<Rep, Period>& value) noexcept
{
    auto getUnit = []() -> std::string {
        if (std::is_same<typename Period::type, std::nano>::value)
            return "ns";
        if (std::is_same<typename Period::type, std::micro>::value)
            return "us";
        if (std::is_same<typename Period::type, std::milli>::value)
            return "ms";
        if (std::is_same<typename Period::type, std::ratio<1>>::value)
            return "s";
        if (std::is_same<typename Period::type, std::centi>::value)
            return "cs";
        if (std::is_same<typename Period::type, std::deci>::value)
            return "ds";

        std::ostringstream otherUnit;
        otherUnit << "(" << Period::num << "/" << Period::den << ")s";
        return otherUnit.str();
    };

    std::ostringstream s;
    s << std::fixed;
    s << value.count() << getUnit();

    return out << s.str();
}

/**
 * @brief Write a core::InstanceSpecifier into the message
 *
 * The InstanceSpecifier shall be shown as the result of calling InstanceSpecifier::ToString.
 *
 * @param out the LogStream object into which to add the value
 * @param value the InstanceSpecifier to log
 * @returns out
 *
 * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
 * @uptrace{SWS_LOG_00126, 7911e0a2c22eaebcbf170ae38c3f23ae9dad7fba}
 * @uptrace{SWS_LOG_00232, 7911e0a2c22eaebcbf170ae38c3f23ae9dad7fba}
 * @uptrace{SWS_LOG_00238, ea2e64d107f0d0912f09255209fad67b7dfeffca}
 */
LogStream& operator<<(LogStream& out, const ara::core::InstanceSpecifier& value) noexcept;
/// @}

}  // namespace log
}  // namespace ara

#endif  // APD_ARA_LOG_LOG_STREAM_H_
