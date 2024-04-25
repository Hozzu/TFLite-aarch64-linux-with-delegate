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

#ifndef ARA_COM_E2E_E2E_TYPES_H
#define ARA_COM_E2E_E2E_TYPES_H

#include <cstdint>

namespace ara
{
namespace com
{
namespace e2e
{

/// @brief Enumeration represents in what state is the e2e check of the sample(s) of the event
///
/// @uptrace{SWS_CM_90422, 30108c9507571dc0f114bda355b048154e3794d4}
enum class SMState : std::uint8_t
{

    kValid,  ///< Communication of the samples of this event functioning properly according to e2e checks, sample(s) can
             ///< be used
    kNoData,  ///< No data from the publisher is available since the initialization, sample(s) cannot be used
    kInit,  ///< State before ara::e2e is initialized, sample cannot be used
    kInvalid,  ///< Communication of the sample of this event not functioning properly, sample(s) cannot be used
    kStateMDisabled  ///< No E2E state machine available ( no statemachine is configured).

};

/// @brief Result of the check of a single sample
///
/// @uptrace{SWS_CM_90421, d7e246e57f12c1fb6ade72899d25d8efe2710edf}
enum class ProfileCheckStatus : std::uint8_t
{
    kOk,  ///< the checks of the sample in this cycle were successful (including counter check).
    kRepeated,  ///< sample has a repeated counter
    kWrongSequence,  ///< the checks of the sample in this cycle were successful, with the exception of counter jump,
                     ///< which changed more than the allowed delta.
    kError,  ///< error not related to counters occurred (e.g. wrong crc, wrong length, wrong Data ID)
    kNotAvailable,  ///< No value has been received yet (e.g. during initialization). This is used as the initialization
                    ///< value for the buffer.
    kNoNewData,  ///< No new data is available (assuming a sample has already been received since the initialization)
    kCheckDisabled  ///< No E2E check status available (no E2E protection is configured).

};

/// @brief Result (e2eResult) of the E2E check containing SMState (e2eState) and ProfileCheckStatus (e2eStatus)
///
/// @uptrace{SWS_CM_90411, 9976d035dab40f3827aa7efa81621a6c10dd8b58}
/// @uptrace{SWS_CM_90416, 697bb3ee38648362954570f58976e372d48bfd6c}
/// @uptrace{SWS_CM_90461, bed2c6e7dc77c7355cf1057eaef41f6576a98daf}
/// @uptrace{SWS_CM_90478, 7ffca6cb3d9ca51693fa453a79ebb8d932847f1f}
struct Result
{
    /// @brief Constructs default result with e2eState set to kNoData and e2eStatus set to NotAvailable
    Result() noexcept
        : Result(SMState::kNoData, ProfileCheckStatus::kNotAvailable)
    { }

    /// @brief Constructs result of E2E check
    ///
    /// @param e2eState provides the state of the E2E state machine
    /// @param e2eStatus provides the status of the E2E check
    Result(SMState e2eState, ProfileCheckStatus e2eStatus) noexcept
        : smState{e2eState}
        , profileCheckStatus{e2eStatus}
    { }

    SMState smState;
    ProfileCheckStatus profileCheckStatus;
};

}  // namespace e2e
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_E2E_E2E_TYPES_H
