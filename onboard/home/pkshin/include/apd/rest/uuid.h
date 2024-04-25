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

#ifndef LIB_APDREST_INCLUDE_APD_REST_UUID_H_
#define LIB_APDREST_INCLUDE_APD_REST_UUID_H_

#include <cstdint>
#include <ostream>
#include <tuple>

#include "apd/rest/allocator.h"
#include "apd/rest/exception.h"
#include "apd/rest/string.h"

namespace apd
{
namespace rest
{

/**
 * \brief UUID representation class, according to RFC 4122
 * \see https://tools.ietf.org/html/rfc4122
 * \uptrace{SWS_REST_02331}
 */
class Uuid
{
public:
    /**
     * \brief default ctor
     * \uptrace{SWS_REST_02332}
     */
    Uuid() noexcept
        : time_low_(0)
        , time_mid_(0)
        , time_high_and_version_(0)
        , clock_seq_(0)
        , node_(0)
    { }
    /** \brief Constructs a Uuid from a string representation
     *
     *  Throws an IllformedUuidException if parsing fails.
     *
     *  \param id a UUID in RFC4122 format
     *  \uptrace{SWS_REST_02333}
     */
    explicit Uuid(StringView id)
        : Uuid()
    {
        if (!FromString(id)) {
            throw IllformedUuidException("UUID string is invalid.");
        }
    }

    /**
     * \brief constructor taking value parts
     *
     * \param time_low
     * \param time_mid
     * \param time_high_and_version
     * \param clock_seq
     * \param node
     * \uptrace{SWS_REST_02334}
     */
    Uuid(std::uint32_t time_low,
        std::uint16_t time_mid,
        std::uint16_t time_high_and_version,
        std::uint16_t clock_seq,
        std::uint64_t node) noexcept
        : time_low_(time_low)
        , time_mid_(time_mid)
        , time_high_and_version_(time_high_and_version)
        , clock_seq_(clock_seq)
        , node_(node)
    { }

    /**
     * \brief get time low
     * \return time low
     * \uptrace{SWS_REST_02335}
     */
    std::uint32_t GetTimeLow() const noexcept
    {
        return time_low_;
    }

    /**
     * \brief get time mid
     * \return time mid
     * \uptrace{SWS_REST_02336}
     */
    std::uint16_t GetTimeMid() const noexcept
    {
        return time_mid_;
    }

    /**
     * \brief get time high and version
     * \return time high and version
     * \uptrace{SWS_REST_02337}
     */
    std::uint16_t GetTimeHighAndVersion() const noexcept
    {
        return time_high_and_version_;
    }

    /**
     * \brief get clock seq
     * \return clock seq
     * \uptrace{SWS_REST_02338}
     */
    std::uint16_t GetClockSeq() const noexcept
    {
        return clock_seq_;
    }

    /**
     * \brief get node
     * \return node
     * \uptrace{SWS_REST_02339}
     */
    std::uint64_t GetNode() const noexcept
    {
        return node_;
    }

    /**
     * \brief convert Uuid object to string
     *
     * \param alloc TODO
     * \return string containing UUID
     */
    String ToString(Allocator* alloc = GetDefaultAllocator()) const;

    /**
     * \brief equal operator
     * \param a uuid left side operator
     * \param b uuid right side operator
     * \return true if both uuids are the same, false otherwise
     * \uptrace{SWS_REST_02340}
     */
    friend bool operator==(const Uuid& a, const Uuid& b) noexcept
    {
        return (a.time_low_ == b.time_low_ && a.time_mid_ == b.time_mid_
            && a.time_high_and_version_ == b.time_high_and_version_ && a.clock_seq_ == b.clock_seq_
            && a.node_ == b.node_);
    }

    /**
     * \brief not equal operator
     * \param a uuid left side operator
     * \param b uuid right side operator
     * \return true if both uuids are different, false otherwise
     * \uptrace{SWS_REST_02341}
     */
    friend bool operator!=(const Uuid& a, const Uuid& b) noexcept
    {
        return !(a == b);
    }

    /**
     * \brief smaller than operator
     * \param a uuid left side operator
     * \param b uuid right side operator
     * \return true if first uuids is lexically smaller than second, false otherwise
     * \uptrace{SWS_REST_02342}
     */
    friend bool operator<(const Uuid& a, const Uuid& b) noexcept
    {
        auto aa = std::make_tuple(a.time_low_, a.time_mid_, a.time_high_and_version_, a.clock_seq_, a.node_);
        auto bb = std::make_tuple(b.time_low_, b.time_mid_, b.time_high_and_version_, b.clock_seq_, b.node_);
        return aa < bb;
    }

private:
    /**
     * \brief convert string to uuid
     * \param str_uuid
     * \return true if conversion was successful, false otherwise
     */
    bool FromString(const StringView& str_uuid) noexcept;

    std::uint32_t time_low_;
    std::uint16_t time_mid_;
    std::uint16_t time_high_and_version_;
    std::uint16_t clock_seq_;
    std::uint64_t node_;
};

}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_UUID_H_
