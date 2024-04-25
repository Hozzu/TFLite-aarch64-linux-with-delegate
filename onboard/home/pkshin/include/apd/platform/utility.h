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
 * \file
 */

#ifndef APD_PLATFORM_UTILITY_H_
#define APD_PLATFORM_UTILITY_H_

#include <sys/types.h>
#include <string>
#include <utility>
#include <vector>

namespace apd
{
namespace platform
{
namespace utility
{

typedef std::vector<std::string> StringVector;
typedef std::pair<std::string, std::string> KeyValuePair;

/**
 * \brief Sends the current process to sleep
 *
 * It calls the nanosleep() POSIX api.
 *
 * \param time to sleep in ms
 * \returns A string containing the current working directory.
 */
void Sleep(uint32_t time_ms);

/**
 * \brief Retrives the current working directory
 *
 * It get teh current working directory by calling getcwd().
 *
 * \returns A string containing the current working directory.
 */
std::string getWorkingDirectory();

/**
 * \brief Eliminate characters from the left and right end of a string.
 *
 * Trims all characters occuring in chars_to_trim from the left and right end of text. text is modified.
 */
const std::string WHITESPACE(" \t");

/**
 * \brief Eliminate characters from the left and right end of a string.
 *
 * Trims all characters occuring in chars_to_trim from the left and right end of text. text is modified.
 *
 * More formally: At either end of text the longest substring consisting only of characters listed in chars_to_trim is
 * removed.
 *
 * \param[inout] text The string to be trimmed
 * \param[in] chars_to_trim the character to remove.
 */
void trim(std::string& text, const std::string& chars_to_trim);

/**
 * \brief Extends strings with leading and trailing whitespace
 *
 * For each input string given, adds prefixes of 0..max_space_count spaces and postfixes of 0..max_space_count spaces to
 * the string. Produces all combinations of prefixes and postfixes. Returns a vector of the newly constructed strings,
 * i.e., not containing the given input.
 *
 * Note: If input contains a value that is the result of adding spaces to another value in the input, that value will
 * not be stripped from the output.
 *
 * \param[in] input The set of strings to extend with whitespace
 * \param[in] max_space_count The number of spaces to add at either end of the string.
 * \returns A vector of all input strings extended with 0..max_space_count spaces at either end, not containing the
 * original values listed in input.
 */
StringVector addSpaces(const StringVector& input, size_t max_space_count);

/**
 * \brief Returns the system time in us
 *
 */
uint64_t getSystemTimeUS();

} /* namespace utility */
} /* namespace platform */
} /* namespace apd */

#endif /* APD_PLATFORM_UTILITY_H_ */
