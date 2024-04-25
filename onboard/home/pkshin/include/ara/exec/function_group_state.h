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

/// @file Function Group State class models state of prescribed Function Groups.
#ifndef ARA_EXEC_FUNCTION_GROUP_STATE_H_
#define ARA_EXEC_FUNCTION_GROUP_STATE_H_

#include "ara/exec/function_group.h"
#include "ara/core/result.h"
#include "ara/core/future.h"
#include "ara/core/string.h"
#include "ara/core/string_view.h"

namespace ara
{
namespace exec
{
namespace
{
const char kDelimiter = 3;
}
///
/// @brief Class representing Function Group State defined in the meta-model (ARXML).
///
/// @note Once created based on ARXML path, it's internal value stay bounded to it
///       for entire lifetime of an object.
///
/// @uptrace{SWS_EM_02269, 1d03ed769cbb176cc56c19ca217d051de7e74730}
///
class FunctionGroupState final
{
public:
    ///
    /// @brief Named constructor for FunctionGroupState.
    ///
    /// This method shall validate/verify meta-model path passed and perform FunctionGroupState object creation.
    ///
    /// @param functionGroup - the Function Group instance the state shall be connected with.
    /// @param metaModelIdentifier - stringified meta model identifier.
    /// @returns an instance of FunctionGroupState, or ExecErrorDomain error.
    /// @retval ExecErrc::kMetaModelError - if metaModelIdentifier passed is incorrect (e.g. FunctionGroup
    ///                                     identifier has been passed).
    /// @retval ExecErrc::kGeneralError - if any other error occurs.
    ///
    /// @uptrace{SWS_EM_02326, e3f3cce67b44aada1166c0b3e4a260ac3eb5d99a}
    ///
    static ara::core::Result<FunctionGroupState> Create(const FunctionGroup& functionGroup,
        ara::core::StringView metaModelIdentifier) noexcept;

    ///
    /// @brief Default constructor.
    /// @note Default constructor is deleted in favor of named constructor (Create).
    ///
    /// @uptrace{SWS_EM_02324, dab900008498f6a1b9b365112a460f6baa275b09}
    FunctionGroupState() = delete;

    ///
    /// @brief Destructor of the FunctionGroupState instance.
    ///
    /// @uptrace{SWS_EM_02272, c2c6277daf77213eec1f9e92108a0f10682999e2}
    ///
    ~FunctionGroupState() noexcept;

    ///
    /// @brief Copy constructor.
    /// @note To prevent problems with resource allocations during copy operation, this class is non-copyable.
    ///
    /// @uptrace{SWS_EM_02325, 908e32320b0ce9f4884578bd22b6b261e43a9e64}
    FunctionGroupState(const FunctionGroupState&) = delete;

    ///
    /// @brief Copy assignment operator.
    /// @note To prevent problems with resource allocations during copy operation, this class is non-copyable.
    ///
    /// @uptrace{SWS_EM_02330, 24199029d99c332fa84989f21e50e9e2b10a49a4}
    FunctionGroupState& operator=(const FunctionGroupState&) = delete;

    ///
    /// @brief Move constructor.
    /// @param[in] other FunctionGroupState instance to be moved to a newly constructed object.
    /// @uptrace{SWS_EM_02331, 5a902bc83d2a14aba3cf3287f229d82a327b4196}
    FunctionGroupState(FunctionGroupState&& other) noexcept;

    ///
    /// @brief Move assignment operator.
    /// @param[in] other FunctionGroupState instance to move to this object.
    /// @uptrace{SWS_EM_02332, 1709f4b195f1ea25873e460c43b300b38e596f03}
    FunctionGroupState& operator=(FunctionGroupState&& other) noexcept;

    ///
    /// @brief EQ operator to compare with other FunctionGroupState instance.
    ///
    /// @param other - FunctionGroupState instance to compare this one with.
    /// @returns true in case both FunctionGroupStates are representing exactly the same meta-model element,
    ///          false otherwise.
    ///
    /// @uptrace{SWS_EM_02273, 4225469cb65c81fc26e98496cd1f2fe99ec1ceea}
    ///
    bool operator==(const FunctionGroupState& other) const noexcept;

    ///
    /// @brief UNEQ operator to compare with other FunctionGroupState instance.
    ///
    /// @param other - FunctionGroupState instance to compare this one with.
    /// @returns false in case both FunctionGroupStates are representing
    ///          exactly the same meta-model element, true otherwise.
    ///
    /// @uptrace{SWS_EM_02274, 8a968fe8a821736cb3a4a9e845f001e24e1a6a17}
    ///
    bool operator!=(const FunctionGroupState& other) const noexcept;

private:
    /// @brief Private constructor used in Create method.
    explicit FunctionGroupState(FunctionGroup&& functionGroup, ara::core::StringView metaModelIdentifier) noexcept;

    FunctionGroup group_;
    ara::core::String metaModelIdentifier_;

    /// @brief Allow stringification of the FunctionGroupState by printing the group and the state's
    /// metaModelIdentifier.
    friend std::ostream& operator<<(std::ostream& os, const FunctionGroupState& state)
    {
        os << state.group_ << kDelimiter << state.metaModelIdentifier_;
        return os;
    }
};

}  // namespace exec

}  // namespace ara

#endif  // ARA_EXEC_FUNCTION_GROUP_STATE_H
