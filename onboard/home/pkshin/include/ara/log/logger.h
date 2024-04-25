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
 * @brief This file contains the DLT context abstraction for the logging API.
 *
 * @attention Due to limitation of the C++ language, some internal implementation
 * (e.g. the function bodies) are coded directly into this header file.
 * Such code is NOT meant to be used or referred to by a user directly,
 * and is subject to CHANGE WITHOUT NOTICE.
 * Therefore DO NOT DEPEND ON any implementation details!
 */

#ifndef ARA_LOG_LOGGER_H
#define ARA_LOG_LOGGER_H

#include "ara/core/string_view.h"
#include "ara/log/common.h"
#include "ara/log/log_stream.h"
#include <memory>

namespace ara
{
namespace log
{
namespace internal
{
class LogManager;
}  // namespace internal

/**
 * @brief The high-level logging API for AUTOSAR adaptive applications.
 *
 * It is based on the _Genivi DLT back-end_ and provides simple to use log methods and additional
 * formatting utilities. It also abstracts the de-/registration phases as well as the DLT back-end
 * resource handling.
 *
 * This logging API supports the Genivi DLT version __2.16.0__ and newer.
 *
 * @sa <a href="https://github.com/GENIVI/dlt-daemon">DLT-Daemon at Github</a> and
 *     <a href="https://github.com/GENIVI/dlt-viewer">DLT-Viewer at Github</a>
 *
 * The logging API supports the concept of _logging contexts_ as defined by DLT. This means that each log
 * message is associated with a particular log context. The <a href="https://github.com/GENIVI/dlt-viewer">
 * DLT-Viewer</a> application allows for filtering of such contexts as well as adjusting log severity
 * per context during runtime.
 *
 * It is up to the application developer whether he want to use multiple contexts, categorized by
 * sub-functionality, classes/modules, threads or whatever, or whether he just want to use a single
 * default context for the whole application.
 *
 * The logging API offers ready-to-use stream based calls that already supports all primitive data types.
 * The advantage is that applications can extend the logging framework to understand new/custom
 * types simply by providing the relevant stream operators as overloads, without having to touch the
 * framework's code itself.
 *
 * @sa Read description of @c LogStream for how-to write custom type handlers.
 *
 * @par Initialization
 * In order to distinguish the logs from different applications, every application in the system
 * a particular ID (_up to four-character_) and a description has to be assigned.
 * @par
 * These values has to be provided to the internal logging manager in order to register with the
 * DLT back-end. The user also has to specify the application's default log level. Only log messages
 * that have a higher log severity level will be processed. The log level is adjustable during runtime
 * via some client (e.g. <a href="https://github.com/GENIVI/dlt-viewer">DLT-Viewer</a>).
 *
 * @note It is highly recommended to assign system-wide unique IDs per application and even per process,
 * in case same application is started multiple times. If multiple processes registers with the same ID,
 * the logs will be mixed up, and the log output will be hardly to filter and to read. It is advised to
 * keep and maintain a central list of _ID to application/instance_.
 *
 * @attention If some application is allowed to fork, which is normally forbidden in AUTOSAR adaptive,
 * except for a very few special applications, the init call must be done __AFTER__ forking, otherwise
 * we will end up in undefined behavior. Apart from that, the logging API and the DLT back-end is thread
 * safe. That means, logging can be done asynchronous from multiple threads, within one registered
 * application and within same logging contexts.
 *
 * @par Logging contexts
 * To be able to log at least one context needs to be available per application. Logging contexts are
 * represented by the class @c Logger. Hereafter _logger_ or _DLT context_ are used as synonyms
 * for _logging context_.
 * @par
 * If the application requires only trivial logging setup, meaning if there is no need to have more
 * than one context at all, it is not necessary to create a context manually. The logging API will
 * provide one default context, based on lazy-init at the very first attempt to do a message log via
 * the convenience methods _Log<LogLevel>()_.
 * @par
 * Contexts are identified similarly like the application by an _up to four-character_ ID and
 * a description. They can either be defined scoped (within class or function or compilation unit),
 * or just globally. The default context provided by the logging framework, will get the ID _DFLT_.
 *
 * @warning Creating loggers __MUST__ be done via the convenience method @c CreateLogger().
 * Don't call @c Logger's @link
 * Logger::Logger(const std::string& ctxId, const std::string& ctxDescription, LogLevel ctxDefLogLevel)
 * @c ctor @endlink by yourself unless you know what you do.
 *
 * @note For runtime critical applications, it might be of interest to prevent any side effects
 * caused by the lazy-init of the default logger (if used at all) when doing the very first message
 * log. To achieve this, just do a log of some informal nature within your application init-phase.
 * However, this is optional.
 *
 * This is all that needs to be done in order to be able to start logging. Everything else is setup
 * and handled automatically in background.
 *
 * @par Early logging
 * All messages logged before the initialization is done will be stored inside a ring-buffer
 * with a limited size. That means, oldest entries are lost if the buffer exceeds.
 *
 * @note In DLT every context has its own severity level. To make the usage of the API less complex
 * an application-wide log level (that one specified in the init-phase) applies to all contexts until
 * they are changed by some DLT client, remotely. Since the loggers can be created before the
 * initialization call, they are created per default with most verbose level, to enable early logging.
 * That means, until the logging framework is not initialized, it is possible to log already into the
 * globally defined loggers with most verbose severity. As soon as the the logging framework becomes
 * up and running, all contexts are settled to the application-wide log level. This ensures that no
 * messages are lost before the init-phase.
 *
 * @par Usage
 * Only the main public header needs to be included and the logging namespace to shortcut the usage
 * (optional but recommended):
 * @code
 * #include <ara/log/logger.h>
 * using namespace ara::log;
 * @endcode
 * @par
 * Init the application against the logging framework and create one or more contexts (optionally).
 * Then simply create a message using one of the provided log methods _Log<LogLevel>()_ and then
 * use the insert stream operator to build up your log content:
 * @code
 * InitLogging("ABCD", "my awesome app.", LogLevel::kVerbose, LogMode::kRemoteConsole);
 *
 * Logger& g_loggerCtx0{CreateLogger(CTX0, "some context of application ABCD")}
 *
 * g_loggerCtx0.LogDebug() << "The answer is" << 42;
 * LogDebug() << "log into default context provided by the framework";
 * @endcode
 *
 * Behind the scenes, these methods creates a @c LogStream temporary object and prepares it for the
 * given log level. Every passed stream argument is getting copied to the internal message buffer
 * as payload with evaluated type information. There is no need to put spaces in between the single
 * arguments as client applications will represent the arguments anyway one-by-one.
 *
 * @par Message length
 * The maximum size of one single message that can be sent out depends on the underlying
 * _Genivi DLT back-end_ implementation, which is defined in @c DLT_USER_BUF_MAX_SIZE (inside
 * <dlt/dlt_user.h>). So, theoretically developers can add as much arguments as they want to the
 * message stream, if a message exceeds the buffer length, it will be simply cut-off by the back-end.
 * This needs to be kept in mind when dealing with big data that is to be logged, especially in
 * conjunction with the @c LogStream's @link
 * LogStream::operator<<(ara::core::Span<const ara::core::Byte> data)
 * stream handler.
 *
 * @warning Do not log in code triggered by the destruction of global/static objects. As the destruction
 * order of static objects is unspecified, your application may crash due to the fact that the logging
 * framework itself, or other relevant instances, having been already deregistered from DLT and killed
 * prior to your own instances. It is good practice to completely avoid logging in destructors unless
 * you can be absolutely sure that the object in question is destroyed during the runtime of the
 * application, rather than during the cleanup phase for static objects (after exiting @c main()).
 */

/**
 * @defgroup logging Logging API
 * @brief The high-level logging API.
 *
 * Accumulation of function and utilities for using the logging framework.
 */

/// @addtogroup logging
/// @{
/* -------- High-level API -------- */

/**
 * @brief Creates a Logger instance.
 *
 * Holds the DLT context which is registered in the DLT back-end.
 *
 * @code
 * Logger& g_loggerCtx0{CreateLogger(CTX0, "the default context of application ABCD")}
 * @endcode
 *
 * @param[in] ctxId             The _up to four-character_ ID
 * @param[in] ctxDescription    Some description
 * @param[in] ctxDefLogLevel    The default log level, set to Warning severity if not explicitly specified.
 * @return                      @c Logger object of type @c Logger&
 *
 * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
 * @uptrace{SWS_LOG_00005, 5df8819ade89b7f6b0184618074e7ff668b38a81}
 * @uptrace{SWS_LOG_00006, 34e26625b7b6213ae27ba7609aa0db135f0084d9}
 * @uptrace{SWS_LOG_00021, 4f7c4c676c60b0d020dd1fb935aded0f5a783bc4}
 */
Logger& CreateLogger(ara::core::StringView ctxId,
    ara::core::StringView ctxDescription,
    LogLevel ctxDefLogLevel = LogLevel::kWarn) noexcept;

/**
 * @brief  Logs decimal numbers in hexadecimal format.
 *
 * Negatives are represented in 2's complement. The number of represented digits depends on the
 * overloaded parameter type length.
 *
 * @code
 * uint16_t num = 42;
 * LogInfo() << "This is some number in hex:" << HexFormat(num);
 * LogInfo() << "This is some negative number in hex:" << HexFormat(-num);
 * @endcode
 *
 * @param[in] value Decimal number to be represented in 8 digits
 * @return          @c LogHex8 type that has a built-in stream handler
 *
 * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
 * @uptrace{SWS_LOG_00015, aa03a5230e4bfbf293c178ce0e8601f2da403a1b}
 * @uptrace{SWS_LOG_00016, 9aa6644bfca6800b0d6fdb34d8b72a46d7256043}
 * @uptrace{SWS_LOG_00022, f3cc497f0db67248cd8f419b77e8f56329749100}
 */
constexpr LogHex8 HexFormat(uint8_t value) noexcept
{
    return LogHex8{value};
}

/**
 * @brief Same as @c HexFormat(uint8_t value).
 *
 * @param[in] value Decimal number to be represented in 8 digits
 * @return          @c LogHex8 type that has a built-in stream handler
 *
 * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
 * @uptrace{SWS_LOG_00015, aa03a5230e4bfbf293c178ce0e8601f2da403a1b}
 * @uptrace{SWS_LOG_00016, 9aa6644bfca6800b0d6fdb34d8b72a46d7256043}
 * @uptrace{SWS_LOG_00023, cf3e865e9339848049ec4d5f92237d13cf343fc2}
 */
constexpr LogHex8 HexFormat(int8_t value) noexcept
{
    return LogHex8{static_cast<uint8_t>(value)};
}

/**
 * @brief Same as @c HexFormat(uint8_t value).
 *
 * @param[in] value Decimal number to be represented in 16 digits
 * @return          @c LogHex16 type that has a built-in stream handler
 *
 * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
 * @uptrace{SWS_LOG_00015, aa03a5230e4bfbf293c178ce0e8601f2da403a1b}
 * @uptrace{SWS_LOG_00016, 9aa6644bfca6800b0d6fdb34d8b72a46d7256043}
 * @uptrace{SWS_LOG_00024, 26733f3301789cfb78ed0c9d77fc5ecd9733d73b}
 */
constexpr LogHex16 HexFormat(uint16_t value) noexcept
{
    return LogHex16{value};
}

/**
 * @brief Same as @c HexFormat(uint8_t value).
 *
 * @param[in] value Decimal number to be represented in 16 digits
 * @return          @c LogHex16 type that has a built-in stream handler
 *
 * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
 * @uptrace{SWS_LOG_00015, aa03a5230e4bfbf293c178ce0e8601f2da403a1b}
 * @uptrace{SWS_LOG_00016, 9aa6644bfca6800b0d6fdb34d8b72a46d7256043}
 * @uptrace{SWS_LOG_00025, f90f430dcb5fcdaee5008fe7893c44e8917c72fd}
 */
constexpr LogHex16 HexFormat(int16_t value) noexcept
{
    return LogHex16{static_cast<uint16_t>(value)};
}

/**
 * @brief Same as @c HexFormat(uint8_t value).
 *
 * @param[in] value Decimal number to be represented in 32 digits
 * @return          @c LogHex32 type that has a built-in stream handler
 *
 * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
 * @uptrace{SWS_LOG_00015, aa03a5230e4bfbf293c178ce0e8601f2da403a1b}
 * @uptrace{SWS_LOG_00016, 9aa6644bfca6800b0d6fdb34d8b72a46d7256043}
 * @uptrace{SWS_LOG_00026, 22b8761be3dfe583599076da7881360c75b9b008}
 */
constexpr LogHex32 HexFormat(uint32_t value) noexcept
{
    return LogHex32{value};
}

/**
 * @brief Same as @c HexFormat(uint8_t value).
 *
 * @param[in] value Decimal number to be represented in 32 digits
 * @return          @c LogHex32 type that has a built-in stream handler
 *
 * @uptrace{SWS_LOG_00015, aa03a5230e4bfbf293c178ce0e8601f2da403a1b}
 * @uptrace{SWS_LOG_00016, 9aa6644bfca6800b0d6fdb34d8b72a46d7256043}
 * @uptrace{SWS_LOG_00027, 7be59e06392fea25a22cd586ba5a6efadcc67d60}
 */
constexpr LogHex32 HexFormat(int32_t value) noexcept
{
    return LogHex32{static_cast<uint32_t>(value)};
}

/**
 * @brief Same as @c HexFormat(uint8_t value).
 *
 * @param[in] value Decimal number to be represented in 64 digits
 * @return          @c LogHex64 type that has a built-in stream handler
 *
 * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
 * @uptrace{SWS_LOG_00015, aa03a5230e4bfbf293c178ce0e8601f2da403a1b}
 * @uptrace{SWS_LOG_00016, 9aa6644bfca6800b0d6fdb34d8b72a46d7256043}
 * @uptrace{SWS_LOG_00028, e16ff400b5ffd6d7a78457d10e0405301638b55d}
 */
constexpr LogHex64 HexFormat(uint64_t value) noexcept
{
    return LogHex64{value};
}

/**
 * @brief Same as @c HexFormat(uint8_t value).
 *
 * @param[in] value Decimal number to be represented in 64 digits
 * @return          @c LogHex64 type that has a built-in stream handler
 *
 * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
 * @uptrace{SWS_LOG_00015, aa03a5230e4bfbf293c178ce0e8601f2da403a1b}
 * @uptrace{SWS_LOG_00016, 9aa6644bfca6800b0d6fdb34d8b72a46d7256043}
 * @uptrace{SWS_LOG_00029, e2210b5332828450a72e2ceae98b76d72520c521}
 */
constexpr LogHex64 HexFormat(int64_t value) noexcept
{
    return LogHex64{static_cast<uint64_t>(value)};
}

/**
 * @brief Logs decimal numbers in binary format.
 *
 * Negatives are represented in 2's complement. The number of represented digits depends on the
 * overloaded parameter type length.
 *
 * @code
 * LogInfo() << "This is some number in bin:" << BinFormat(42);
 * LogInfo() << "This is some negative number in bin:" << BinFormat(-42);
 * @endcode
 *
 * @param[in] value Decimal number to be represented in 8 digits
 * @return          @c LogBin8 type that has a built-in stream handler
 *
 * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
 * @uptrace{SWS_LOG_00017, 1f05f1cb8821eb21a17cc03608caaa568beb8548}
 * @uptrace{SWS_LOG_00030, 4bf00d754df4581edc82f7ae0a38e47b3f2c4a41}
 */
constexpr LogBin8 BinFormat(uint8_t value) noexcept
{
    return LogBin8{value};
}

/**
 * @brief Same as @c BinFormat(uint8_t value).
 *
 * @param[in] value Decimal number to be represented in 8 digits
 * @return          @c LogBin8 type that has a built-in stream handler
 *
 * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
 * @uptrace{SWS_LOG_00017, 1f05f1cb8821eb21a17cc03608caaa568beb8548}
 * @uptrace{SWS_LOG_00031, 7969dad7eb017eb6743605b0bf6fe81541209018}
 */
constexpr LogBin8 BinFormat(int8_t value) noexcept
{
    return LogBin8{static_cast<uint8_t>(value)};
}

/**
 * @brief Same as @c BinFormat(uint8_t value).
 *
 * @param[in] value Decimal number to be represented in 16 digits
 * @return          @c LogBin16 type that has a built-in stream handler
 *
 * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
 * @uptrace{SWS_LOG_00017, 1f05f1cb8821eb21a17cc03608caaa568beb8548}
 * @uptrace{SWS_LOG_00032, a510c1b341fc5d888a416253af8c29da7699b558}
 */
constexpr LogBin16 BinFormat(uint16_t value) noexcept
{
    return LogBin16{value};
}

/**
 * @brief Same as @c BinFormat(uint8_t value).
 *
 * @param[in] value Decimal number to be represented in 16 digits
 * @return          @c LogBin16 type that has a built-in stream handler
 *
 * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
 * @uptrace{SWS_LOG_00017, 1f05f1cb8821eb21a17cc03608caaa568beb8548}
 * @uptrace{SWS_LOG_00033, 4ef0ea63da33bc75e1364d67c513e7337ca8bb2d}
 */
constexpr LogBin16 BinFormat(int16_t value) noexcept
{
    return LogBin16{static_cast<uint16_t>(value)};
}

/**
 * @brief Same as @c BinFormat(uint8_t value).
 *
 * @param[in] value Decimal number to be represented in 32 digits
 * @return          @c LogBin32 type that has a built-in stream handler
 *
 * @uptrace{SWS_LOG_00017, 1f05f1cb8821eb21a17cc03608caaa568beb8548}
 * @uptrace{SWS_LOG_00034, 967ec36066da61a9eb7792c0ca8674e110e20868}
 */
constexpr LogBin32 BinFormat(uint32_t value) noexcept
{
    return LogBin32{value};
}

/**
 * @brief Same as @c BinFormat(uint8_t value).
 *
 * @param[in] value Decimal number to be represented in 32 digits
 * @return          @c LogBin32 type that has a built-in stream handler
 *
 * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
 * @uptrace{SWS_LOG_00017, 1f05f1cb8821eb21a17cc03608caaa568beb8548}
 * @uptrace{SWS_LOG_00035, f868ef6b6e2e4cd841ade814a9b62c764b4f40a9}
 */
constexpr LogBin32 BinFormat(int32_t value) noexcept
{
    return LogBin32{static_cast<uint32_t>(value)};
}

/**
 * @brief Same as @c BinFormat(uint8_t value).
 *
 * @param[in] value Decimal number to be represented in 64 digits
 * @return          @c LogBin64 type that has a built-in stream handler
 *
 * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
 * @uptrace{SWS_LOG_00017, 1f05f1cb8821eb21a17cc03608caaa568beb8548}
 * @uptrace{SWS_LOG_00036, 53ffe08eb1716a0130a6ffc863e32888fc1a3192}
 */
constexpr LogBin64 BinFormat(uint64_t value) noexcept
{
    return LogBin64{value};
}

/**
 * @brief Same as @c BinFormat(uint8_t value).
 *
 * @param[in] value Decimal number to be represented in 64 digits
 * @return          @c LogBin64 type that has a built-in stream handler
 *
 * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
 * @uptrace{SWS_LOG_00017, 1f05f1cb8821eb21a17cc03608caaa568beb8548}
 * @uptrace{SWS_LOG_00037, b0a89c0ec75483170515c7ad1f5f63456ebf2eb5}
 */
constexpr LogBin64 BinFormat(int64_t value) noexcept
{
    return LogBin64{static_cast<uint64_t>(value)};
}

/* -------- END of API -------- */
/// @}

/**
 * @ingroup logger
 * @class Logger
 *
 * @brief Class representing a DLT logger context.
 *
 * DLT defines so called _contexts_ which can be seen as logger instances within one application
 * or process scope. Contexts have the same properties to be set up as for the application:
 *  -# ID (_up to four-character_)
 *  -# description text (opt.)
 *  -# default log severity level
 *
 * A context will be automatically registered against the DLT back-end during creation phase, as well
 * as automatically deregistered during process shutdown phase. So the end user does not care for the
 * objects life time.
 */
class Logger final
{
public:
    /**
     * @brief Creates a @c LogStream object.
     *
     * Returned object will accept arguments via the _insert stream operator_ "@c <<".
     *
     * @note In the normal usage scenario, the object's life time of the created @c LogStream is scoped
     * within one statement (ends with @c ; after last passed argument). If one wants to extend the
     * @c LogStream object's life time, the object might be assigned to a named variable.
     * @see Refer to the @c LogStream class documentation for further details.
     *
     * @return  @c LogStream object of Fatal severity.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00008, 9e6a1765072cc656f605b70f0fcb4e3138ec5916}
     * @uptrace{SWS_LOG_00064, dd1eb7d8bb635dd8bf03d362bb103da3994a1889}
     */
    LogStream LogFatal() const noexcept;
    /**
     * @brief Same as @c Logger::LogFatal().
     * @return  @c LogStream object of Error severity.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00009, c7cd18ff9a8e174cdcd4d7b7dd5b89fa16842d19}
     * @uptrace{SWS_LOG_00065, 28064c16099837ae2cf300e0f5de826b3bdbcf2f}
     */
    LogStream LogError() const noexcept;
    /**
     * @brief Same as @c Logger::LogFatal().
     * @return  @c LogStream object of Warn severity.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00010, 44f35417a0ab49650efeab0e2b2a5589e08b791f}
     * @uptrace{SWS_LOG_00066, 5eb680e72165f8f1415d46bb26532145771c3967}
     */
    LogStream LogWarn() const noexcept;
    /**
     * @brief Same as @c Logger::LogFatal().
     * @return  @c LogStream object of Info severity.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00011, 0d0b177e347b0f3f2ed8533ca0a7fa2663aba412}
     * @uptrace{SWS_LOG_00067, 0c4e464f9419c94bd66a5fda0fa02544b3e5ac85}
     */
    LogStream LogInfo() const noexcept;
    /**
     * @brief Same as @c Logger::LogFatal().
     * @return  @c LogStream object of Debug severity.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00012, 995feb25905d77bfe23016e16ea153984b135b70}
     * @uptrace{SWS_LOG_00068, 5bdb5e0ef6c3daf86294417f0db4396d6cc376eb}
     */
    LogStream LogDebug() const noexcept;
    /**
     * @brief Same as @c Logger::LogFatal().
     * @return  @c LogStream object of Verbose severity.
     *
     * @uptrace{SWS_LOG_00002, 9664bc28e7ea1c9a1af220ece565e32c19577919}
     * @uptrace{SWS_LOG_00013, 2765d9a205b7f83a7e6a25c89fab33e4f814f7a9}
     * @uptrace{SWS_LOG_00069, f5b09e69db337794ebbb081820eba6352f5cf66d}
     */
    LogStream LogVerbose() const noexcept;
    /**
     * @brief Log message with a programmatically determined log level can be written.
     * @param logLevel the log level to use for this LogStream instance
     * @return a new LogStream instance with the given log level
     *
     * @uptrace{SWS_LOG_00130, 06a9468bafa78fd6e3cd09b35fc33979e56c6555}
     * @uptrace{SWS_LOG_00131, d99a8a3017eb90c0ef03e36246363a258a873764}
     */
    LogStream WithLevel(LogLevel logLevel) const noexcept;
    /**
     * @brief Check current configured log reporting level.
     *
     * Applications may want to check the actual configured reporting log level of certain loggers
     * before doing log data preparation that is runtime intensive.
     *
     * @param[in] logLevel  The to be checked log level.
     * @return              True if desired log level satisfies the configured reporting level.
     *
     * @uptrace{SWS_LOG_00007, 03d9719d8aae5e93fa1971414fb3c07d4b3f9783}
     * @uptrace{SWS_LOG_00070, 7aa6e6d582b0d7f2c49baa5e312a71fadeca9938}
     */
    bool IsEnabled(LogLevel logLevel) const noexcept;

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(Logger&&) = delete;

private:
    /**
     * @brief Creates a @c Logger object.
     *
     * Holds the DLT context which is registered in the DLT back-end.
     *
     * @param[in] ctxId             The _up to four-character_ ID
     * @param[in] ctxDescription    Some description
     * @param[in] ctxDefLogLevel    The context's default log reporting level
     */
    Logger(ara::core::StringView ctxId, ara::core::StringView ctxDescription, LogLevel ctxDefLogLevel);

    /**
     * @brief Deregisters the DLT context from the DLT back-end.
     */
    ~Logger();

    friend class internal::LogManager;
    friend LogStream::LogStream(LogLevel, const Logger&);

    void* getContext() const noexcept;
    void deinitialize() noexcept;

    class Impl;
    std::unique_ptr<Impl> pImpl;
};

/**
 * @brief Creates wrapper object with provided name and unit attributes for
 *        all arithmetic types except bool, including their reference types
 *
 * @uptrace{SWS_LOG_00201, 18897fb606020c149b342fd769b73bf44cadf30a}
 */
template <typename T,
    typename
    = std::enable_if_t<std::is_arithmetic<std::decay_t<T>>::value and not std::is_same<std::decay_t<T>, bool>::value>>
Argument<T> Arg(T&& arg, const char* name, const char* unit, Format format = Dflt()) noexcept
{
    return {std::forward<T>(arg), name, unit, format};
}

/**
 * @brief Creates wrapper object with provided name attribute for
 *        all arithmetic types including their reference types,
 *        types convertible to ara::core::StringView
 *        and types convertible to ara::core::Span
 *
 * @uptrace{SWS_LOG_00201, 18897fb606020c149b342fd769b73bf44cadf30a}
 */
template <typename T,
    typename = std::enable_if_t<std::is_arithmetic<std::decay_t<T>>::value
        or std::is_convertible<T, ara::core::StringView>::value
        or std::is_convertible<T, ara::core::Span<const ara::core::Byte>>::value>>
Argument<T> Arg(T&& arg, const char* name) noexcept
{
    return {std::forward<T>(arg), name, nullptr, Dflt()};
}

/**
 * @brief Creates wrapper object without attributes for
 *        all arithmetic types including their reference types,
 *        types convertible to ara::core::StringView
 *        and types convertible to ara::core::Span
 *
 * @uptrace{SWS_LOG_00201, 18897fb606020c149b342fd769b73bf44cadf30a}
 */
template <typename T,
    typename = std::enable_if_t<std::is_arithmetic<std::decay_t<T>>::value
        or std::is_convertible<T, ara::core::StringView>::value
        or std::is_convertible<T, ara::core::Span<const ara::core::Byte>>::value>>
Argument<T> Arg(T&& arg) noexcept
{
    return {std::forward<T>(arg), nullptr, nullptr, Dflt()};
}

/**
 * @brief Fetches the connection state from the DLT back-end of a possibly available remote client.
 *
 * @returns The current client state
 *
 * @uptrace{SWS_LOG_00101, e47f0691d6d8467019da7b58b7bc5fc24a55a5d3}
 */
ClientState remoteClientState() noexcept;

} /* namespace log */
} /* namespace ara */

#endif  // ARA_LOG_LOGGER_H
