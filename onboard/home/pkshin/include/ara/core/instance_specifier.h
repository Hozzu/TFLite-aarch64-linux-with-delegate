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

/// @file

#ifndef ARA_CORE_INSTANCE_SPECIFIER_H
#define ARA_CORE_INSTANCE_SPECIFIER_H

#include "ara/core/result.h"
#include "ara/core/string_view.h"
#include "ara/core/string.h"
#include "ara/core/core_error_domain.h"

#include <algorithm>

namespace ara
{
namespace core
{

/**
 * class representing an AUTOSAR Instance Specifier, which is basically an AUTOSAR shortname-path wrapper.
 *
 * @uptrace{SWS_CORE_08001, 23e83ae88156cfe904839d50c43de1ae44bdeba3}
 */
class InstanceSpecifier final
{
    ara::core::String mMetaModelIdentifier;

    /// @uptrace{SWS_CORE_10200, 6343e9298641485864ce2142ccf679a1814f9643}
    /// @uptrace{SWS_CORE_10201, 84e92ca3495ba5fbcd2faf838f0c405b036a37bb}
    static Result<void> Validate(StringView metaModelIdentifier) noexcept
    {
        std::size_t endOffset = static_cast<std::size_t>(-1);  // point this to a "virtual leading '/'"
        do {
            size_t const currentOffset = endOffset + 1;  // skip the '/'
            endOffset = metaModelIdentifier.find('/', currentOffset);
            size_t const len = (endOffset == StringView::npos) ? StringView::npos : endOffset - currentOffset;
            StringView const pathComponent = metaModelIdentifier.substr(currentOffset, len);

            if (pathComponent.empty()) {
                return Result<void>::FromError(CoreErrc::kInvalidMetaModelPath);
            }
            if (!IsValidMetamodelIdentifierPart(pathComponent)) {
                return Result<void>::FromError(CoreErrc::kInvalidMetaModelShortname);
            }
        } while (endOffset != StringView::npos);

        return Result<void>();
    }

    constexpr static bool IsValidStartChar(char ch) noexcept
    {
        return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
    }

    constexpr static bool IsValidChar(char ch) noexcept
    {
        return IsValidStartChar(ch) || (ch >= '0' && ch <= '9') || (ch == '_');
    }

    constexpr static bool IsValidMetamodelIdentifierPart(StringView text) noexcept
    {
        if (text.empty()) {
            return false;
        }
        return IsValidStartChar(text[0]) && std::all_of(text.begin() + 1, text.end(), IsValidChar);
    }

    InstanceSpecifier(StringView metaModelIdentifier, bool /*tag*/)
        : mMetaModelIdentifier(metaModelIdentifier)
    { }

public:
    /**
     * @uptrace{SWS_CORE_08032}
     * @uptrace{SWS_CORE_10202, f87c9a74240a9c073810b1cc09a34370697d962d}
     */
    static Result<InstanceSpecifier> Create(StringView metaModelIdentifier)
    {
        Result<void> ret = Validate(metaModelIdentifier);
        if (!ret) {
            return Result<InstanceSpecifier>::FromError(ret.Error());
        }

        return InstanceSpecifier(metaModelIdentifier, true);
    }

    /**
     * @brief throwing ctor from meta-model string
     * @param metaModelIdentifier  stringified meta model identifier (short name path) where path separator is '/'.
     *        Lifetime of underlying string has to exceed the lifetime of the constructed InstanceSpecifier.
     * @throws InstanceSpecifierException in case the given metamodel_identifier isn't a valid meta-model
     * identifier/short name path.
     *
     * @uptrace{SWS_CORE_08021, 66346b224270df5b8839071073c2095eaaa5ddb6}
     * @uptrace{SWS_CORE_10202, f87c9a74240a9c073810b1cc09a34370697d962d}
     */
    explicit InstanceSpecifier(StringView metaModelIdentifier)
        : InstanceSpecifier(Create(metaModelIdentifier).ValueOrThrow())
    { }

    /// @uptrace{SWS_CORE_08022, db22c063d58a140facbc6e22e40df05b810577c1}
    InstanceSpecifier(InstanceSpecifier const& other) = default;

    /// @uptrace{SWS_CORE_08023, b8732143587cc59308656faca4a4168a7e23bc3c}
    InstanceSpecifier(InstanceSpecifier&& other) noexcept = default;

    /// @uptrace{SWS_CORE_08024, ee8c0f65ddf7b67c41840163bd4e7c8e8833f1be}
    InstanceSpecifier& operator=(InstanceSpecifier const& other) = default;

    /// @uptrace{SWS_CORE_08025, e2d91af3ac927f9790a481a113f62e8708afcfe2}
    InstanceSpecifier& operator=(InstanceSpecifier&& other) = default;

    /**
     * @brief Destructor
     *
     * @uptrace{SWS_CORE_08029}
     */
    ~InstanceSpecifier() = default;

    /**
     * @brief method to return the stringified form of InstanceSpecifier
     * @return stringified form of InstanceSpecifier. Lifetime of the underlying string is only guaranteed for the
     * lifetime of the underlying string of the StringView passed to the constructor.
     *
     * @uptrace{SWS_CORE_08041, 971fc5b9296cf56836c09a364ff20db408ca10df}
     */
    StringView ToString() const noexcept
    {
        return mMetaModelIdentifier;
    }

    /**
     * @brief eq operator to compare with other InstanceSpecifier instance.
     * @param other InstanceSpecifier instance to compare this one with.
     * @return true in case both InstanceSpecifiers are denoting exactly the same model element, false else.
     *
     * @uptrace{SWS_CORE_08042, 5d1301cd000778a8bd82716c7debdcce498c4b27}
     */
    bool operator==(InstanceSpecifier const& other) const noexcept
    {
        return mMetaModelIdentifier == other.ToString();
    }

    /**
     * @brief eq operator to compare with other InstanceSpecifier instance.
     * @param other string representation to compare this one with.
     * @return true in case this InstanceSpecifiers is denoting exactly the same model element as other, false else.
     *
     * @uptrace{SWS_CORE_08043, 126e40cc2a1f33d632437c5f6c357fc44bcd8638}
     */
    bool operator==(StringView other) const noexcept
    {
        return mMetaModelIdentifier == other;
    }

    /**
     * @brief uneq operator to compare with other InstanceSpecifier instance.
     * @param other InstanceSpecifier instance to compare this one with.
     * @return false in case both InstanceSpecifiers are denoting exactly the same model element, true else.
     *
     * @uptrace{SWS_CORE_08044, 4685e6f77df993994c9ba552fba5d829e10e8dea}
     */
    bool operator!=(InstanceSpecifier const& other) const noexcept
    {
        return mMetaModelIdentifier != other.ToString();
    }

    /**
     * @brief uneq operator to compare with other InstanceSpecifier string representation.
     * @param other string representation to compare this one with.
     * @return false in case this InstanceSpecifiers is denoting exactly the same model element as other, true else.
     *
     * @uptrace{SWS_CORE_08045, 15beb960af5795113f75cba834495d873f54b00e}
     */
    bool operator!=(StringView other) const noexcept
    {
        return mMetaModelIdentifier != other;
    }

    /**
     * @brief lower than operator to compare with other InstanceSpecifier for ordering purposes (f.i. when collecting
     * identifiers in maps).
     * @param other InstanceSpecifier instance to compare this one with.
     * @return true in case this InstanceSpecifiers is lexically lower than other, false else.
     *
     * @uptrace{SWS_CORE_08046, 6eda674c5e3adcc23886362906fbdd96c43c514a}
     */
    bool operator<(InstanceSpecifier const& other) const noexcept
    {
        return mMetaModelIdentifier < other.mMetaModelIdentifier;
    }
};

/**
 * @brief non-member function op to allow char* on lhs.
 *
 * @param lhs  stringified form of a InstanceSpecifier
 * @param rhs  an InstanceSpecifier
 * @returns true in case rhs string representation equals lhs
 *
 * @uptrace{SWS_CORE_08081, a4e4d478d509a36cbd4f18fc059e04345294cae5}
 */
inline bool operator==(StringView lhs, InstanceSpecifier const& rhs) noexcept
{
    return lhs == rhs.ToString();
}

/**
 * @brief non-member function op to allow char* on lhs.
 *
 * @param lhs  stringified form of a InstanceSpecifier
 * @param rhs  an InstanceSpecifier
 * @returns true in case rhs string representation not equals lhs
 *
 * @uptrace{SWS_CORE_08082, cd5ccd095e3b45b007dbaed324a7ff1bd9528588}
 */
inline bool operator!=(StringView lhs, InstanceSpecifier const& rhs) noexcept
{
    return lhs != rhs.ToString();
}

}  // namespace core
}  // namespace ara

#endif  // ARA_CORE_INSTANCE_SPECIFIER_H
