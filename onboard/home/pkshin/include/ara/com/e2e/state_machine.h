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

#ifndef ARA_COM_E2E_STATE_MACHINE_H
#define ARA_COM_E2E_STATE_MACHINE_H

#include "ara/core/vector.h"
#include "ara/com/e2e/e2e_types.h"
#include <cstdint>
#include <mutex>
#include <ostream>
#include <stdexcept>

namespace ara
{

namespace com
{

namespace e2e
{

/// @brief E2E State Machine configuration
///
/// @uptrace{SWS_CM_90402, ac5c9760109c5970a8359b1980fca28cbbd233e3}
struct Config
{
    /// @brief Size of the monitoring window for the state machine.
    uint8_t windowSize{0U};

    /// @brief Minimal number of checks in which ProfileStatus equal to OK was determined within the last WindowSize
    /// checks (for the state INIT) required to change to state VALID
    uint8_t minOkStateInit{0U};

    /// @brief Maximal number of checks in which ProfileStatus equal to ERROR was determined, within the last WindowSize
    /// checks (for the state INIT).
    uint8_t maxErrorStateInit{0U};

    /// @brief Minimal number of checks in which ProfileStatus equal to OK was determined within the last WindowSize
    /// checks (for the state VALID) required to keep in state VALID.
    uint8_t minOkStateValid{0U};

    /// @brief Maximal number of checks in which ProfileStatus equal to ERROR was determined, within the last WindowSize
    /// checks (for the state VALID)
    uint8_t maxErrorStateValid{0U};

    /// @brief Minimum number of checks in which ProfileStatus equal to OK was determined within the last WindowSize
    /// checks (for the state INVALID) required to change to state VALID
    uint8_t minOkStateInvalid{0U};

    /// @brief Maximal number of checks in which ProfileStatus equal to ERROR was determined, within the last WindowSize
    /// checks (for the state INVALID
    uint8_t maxErrorStateInvalid{0U};

#ifndef E2E_DEVELOPMENT
    Config() = delete;
#else
    Config() = default;
#endif

    /// @brief Construct State Machine configuration object and performs check of input parameters
    ///
    /// @throw std::invalid_argument is thrown if either of windowSize, minOkStateInit, minOkStateValid,
    /// minOkStateInvalid set to 0. It's also thrown if minOkStates and maxErrorStates exceed window size
    ///
    Config(uint8_t in_windowSize,
        uint8_t in_minOkStateInit,
        uint8_t in_maxErrorStateInit,
        uint8_t in_minOkStateValid,
        uint8_t in_maxErrorStateValid,
        uint8_t in_minOkStateInvalid,
        uint8_t in_maxErrorStateInvalid)
        : windowSize(in_windowSize)
        , minOkStateInit(in_minOkStateInit)
        , maxErrorStateInit(in_maxErrorStateInit)
        , minOkStateValid(in_minOkStateValid)
        , maxErrorStateValid(in_maxErrorStateValid)
        , minOkStateInvalid(in_minOkStateInvalid)
        , maxErrorStateInvalid(in_maxErrorStateInvalid)
    {
        if (windowSize == 0U) {
            throw std::invalid_argument{"Wrong specification of E2E: windowSize == 0U"};
        }
        if ((minOkStateInit == 0U) || (minOkStateInit > windowSize)) {
            throw std::invalid_argument{
                "Wrong specification of E2E: (minOkStateInit == 0U) || (minOkStateInit > windowSize)"};
        }
        if (maxErrorStateInit > windowSize) {
            throw std::invalid_argument{"Wrong specification of E2E: maxErrorStateInit > windowSize"};
        }
        if ((minOkStateValid == 0U) || (minOkStateValid > windowSize)) {
            throw std::invalid_argument{
                "Wrong specification of E2E: (minOkStateValid == 0U) || (minOkStateValid > windowSize)"};
        }
        if (maxErrorStateValid > windowSize) {
            throw std::invalid_argument{"Wrong specification of E2E: maxErrorStateValid > windowSize"};
        }
        if ((minOkStateInvalid == 0U) || (minOkStateInvalid > windowSize)) {
            throw std::invalid_argument{
                "Wrong specification of E2E: (minOkStateInvalid == 0U) || (minOkStateInvalid > windowSize)"};
        }
        if (maxErrorStateInvalid > windowSize) {
            throw std::invalid_argument{"Wrong specification of E2E: maxErrorStateInvalid > windowSize"};
        }
        // TODO: any additional constraint
    }

    /// @brief Default copy constructor
    Config(const Config&) = default;
    /// @brief Default copy-assignment operator
    Config& operator=(const Config&) = default;
    /// @brief Default move constructor
    Config(Config&&) noexcept = default;
    /// @brief Default move-assignment operator
    Config& operator=(Config&&) noexcept = default;
    /// @brief Default destructor
    ~Config() noexcept = default;
};

/// @brief E2E state machine
///
/// The state machine builds up a state out of several results of the Check() function
/// within a reception window, which is then provided to the consumer.
/// The state machine is applicable for all E2E profiles.
class StateMachine
{
public:
    /// @brief Default constructor
    StateMachine() = delete;

    /// @brief Constructs state machine using given configuration
    ///
    /// @param config configuration of state machine
    explicit StateMachine(const Config& config);

    /// @brief Constructs state machine from another state machine instance using copy
    ///
    /// @param oth other state machine instance
    StateMachine(const StateMachine& oth);

    /// @brief Move-constructs state machine form another state machine instance
    ///
    /// @param oth other state machine instance
    StateMachine(StateMachine&& oth) noexcept;

    /// @brief copy-assignment operator
    /// copies all state machine fileds except mutex
    ///
    /// @param oth other state machine instance
    StateMachine& operator=(const StateMachine& oth);

    /// @brief move-assignmen operator
    /// moves all state machine fileds except mutex
    ///
    /// @param oth other state machine instance
    StateMachine& operator=(StateMachine&& oth) noexcept;

    /// @brief Default destructor
    ~StateMachine() noexcept = default;

    /// @brief invokes state handlers and
    ///
    /// @param genericProfileCheckStatus  profile check status returned by specific checker
    /// @param smState (out) returns current state machine state
    void Check(const ProfileCheckStatus genericProfileCheckStatus, SMState& smState) noexcept;

private:
    void HandleStateNoData(const ProfileCheckStatus profileStatus) noexcept;
    void HandleStateInit(const ProfileCheckStatus profileStatus) noexcept;
    void HandleStateValid(const ProfileCheckStatus profileStatus) noexcept;
    void HandleStateInvalid(const ProfileCheckStatus profileStatus) noexcept;
    void AddStatus(const ProfileCheckStatus genericProfileCheckStatus) noexcept;

    Config config;
    ara::core::Vector<ProfileCheckStatus> genericProfileCheckStatusWindow;
    uint8_t windowTopIndex;
    uint8_t okCount;
    uint8_t errorCount;
    SMState state;
    std::mutex stateMachineMutex;
};

}  // namespace e2e
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_E2E_STATEMACHINE_H
