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

/// @file Defines Function Groups used in the StateClient API.
#ifndef ARA_EXEC_FUNCTION_GROUP_H_
#define ARA_EXEC_FUNCTION_GROUP_H_

#include "ara/core/result.h"
#include "ara/core/future.h"
#include "ara/core/string.h"
#include "ara/core/string_view.h"

#include <fstream>

namespace ara
{
namespace exec
{
///
/// @brief Class representing Function Group defined in meta-model (ARXML).
///
/// @note Once created based on ARXML path, it's internal value stay bounded to it for entire lifetime of an object.
///
/// @uptrace{SWS_EM_02263, 46e65247008ce5f9a32a1eeab24457f177d73ba4}
///
class FunctionGroup final
{
public:
    /// @brief Named constructor FunctionGroup.
    ///
    /// This method shall validate/verify meta-model path passed and perform FunctionGroup object creation.
    ///
    /// @param metaModelIdentifier stringified meta model identifier (short name path) where path separator is '/'.
    /// @returns an instance of FunctionGroup, or ExecErrc error.
    /// @error ara::exec::ExecErrc::kMetaModelError if metaModelIdentifier passed is incorrect (e.g. FunctionGroupState
    /// identifier has been passed).
    /// @error ara::exec::ExecErrc::kGeneralError if any other error occurs.
    ///
    /// @uptrace{SWS_EM_02323, 731c44820c7923133f03bee1d1eb34ce0a8e8798}
    ///
    static ara::core::Result<FunctionGroup> Create(ara::core::StringView metaModelIdentifier) noexcept;

    ///
    /// @brief Default constructor.
    ///
    /// @note DEfault constructor is deleted in favor of named constructor (Create).
    ///
    /// @uptrace{SWS_EM_02321, 969f32910c0488e931a49d14814fddcfc915a96b}
    ///
    FunctionGroup() = delete;

    ///
    /// @brief Copy constructor.
    /// @note To prevent problems with resource allocations during copy operation, this class is non-copyable.
    ///
    /// @uptrace{SWS_EM_02322, 3f8e6a90e92b7f4f47a9acfd7d79a8c549720a8a}
    FunctionGroup(const FunctionGroup& other) = delete;

    ///
    /// @brief Copy assignment operator.
    /// @note To prevent problems with resource allocations during copy operation, this class is non-copyable.
    ///
    /// @uptrace{SWS_EM_02327, 240bb260e7a452fecb38f658afd0ec3296a8e7a2}
    FunctionGroup& operator=(const FunctionGroup& other) = delete;

    ///
    /// @brief Move constructor.
    /// @param[in] other FunctionGroup instance to move to a newly constructed object.
    /// @uptrace{SWS_EM_02328, 1c1ce1da841358db1f67732bb694e203eb1bed99}
    FunctionGroup(FunctionGroup&& other) noexcept;

    ///
    /// @brief Move assignment operator.
    /// @param[in] other FunctionGroup instance to move to this object.
    /// @uptrace{SWS_EM_02329, 91c65ca70580fb899adf93cf6d7628da6002ca7a}
    FunctionGroup& operator=(FunctionGroup&& other) noexcept;

    ///
    /// @brief Destructor of the FunctionGroup instance.
    ///
    /// @uptrace{SWS_EM_02266, 492d107212480da763a6a3b7c9bbb7b781da5a9f}
    ///
    ~FunctionGroup() noexcept;

    ///
    /// @brief EQ operator to compare with other FunctionGroup instance.
    ///
    /// @param other - FunctionGroup instance to compare this one with.
    /// @returns true in case both FunctionGroups are representing exactly
    ///          the same meta-model element, false otherwise.
    ///
    /// @uptrace{SWS_EM_02267, 72abefc6490dba933542fd8dd0cfa3cb219cf2e4}
    ///
    bool operator==(const FunctionGroup& other) const noexcept;

    ///
    /// @brief UNEQ operator to compare with other FunctionGroup instance.
    ///
    /// @param other - FunctionGroup instance to compare this one with.
    /// @returns false in case both FunctionGroups are representing
    ///          exactly the same meta-model element, true otherwise.
    ///
    /// @uptrace{SWS_EM_02268, 33fe16caa9b26901d8ed436cdd20c52f165ab427}
    ///
    bool operator!=(const FunctionGroup& other) const noexcept;

private:
    /// @brief Private constructor used in Create method.
    explicit FunctionGroup(ara::core::StringView metaModelIdentifier) noexcept;

    /// @brief the metaModelIdentifier of the group.
    ara::core::String metaModelIdentifier_;

    /// @brief Allow stringification of the FunctionGroup by printing the metaModelIdentifier.
    friend std::ostream& operator<<(std::ostream& os, const FunctionGroup& group)
    {
        os << group.metaModelIdentifier_;
        return os;
    }
};
}  // namespace exec

}  // namespace ara

#endif  // ARA_EXEC_FUNCTION_GROUP_H
