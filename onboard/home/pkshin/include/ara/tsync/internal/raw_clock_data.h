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

#ifndef ARA_TSYNC_INTERNAL_RAW_CLOCK_DATA_H_
#define ARA_TSYNC_INTERNAL_RAW_CLOCK_DATA_H_

#include <cstdint>

namespace ara
{
namespace tsync
{
namespace internal
{

struct RawClockData
{
    std::int64_t GetLatestClockUpdate() const;
    std::int64_t GetLatestClockValue() const;
    std::uint8_t GetUpdateCounter() const;
    std::uint32_t GetSyncStatusFlag() const;
    void SetLatestClockValue(std::int64_t updateTimePoint, std::int64_t clockValue);
    void SetUpdateCounter(std::uint8_t updateCounter);
    void SetSyncStatusFlag(const std::uint32_t& statusFlag);

    RawClockData();

    bool operator==(const RawClockData& other) const
    {
        if (this == &other) {
            return true;
        }
        if (other.latestClockUpdate_ != latestClockUpdate_) {
            return false;
        }
        if (other.latestClockValue_ != latestClockValue_) {
            return false;
        }
        if (other.syncStatusFlag_ != syncStatusFlag_) {
            return false;
        }
        if (other.updateCounter_ != updateCounter_) {
            return false;
        }
        return true;
    }

private:
    std::int64_t latestClockUpdate_;
    std::int64_t latestClockValue_;
    std::uint8_t updateCounter_;
    std::uint32_t syncStatusFlag_;
};

}  // namespace internal
}  // namespace tsync
}  // namespace ara

#endif  // ARA_TSYNC_INTERNAL_RAW_CLOCK_DATA_H_
