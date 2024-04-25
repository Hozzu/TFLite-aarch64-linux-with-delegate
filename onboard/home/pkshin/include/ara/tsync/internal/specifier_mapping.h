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

#ifndef ARA_TSYNC_INTERNAL_SPECIFIER_MAPPING_H
#define ARA_TSYNC_INTERNAL_SPECIFIER_MAPPING_H

#include "ara/core/string.h"
#include "ara/core/vector.h"
#include "ara/core/instance_specifier.h"
#include <cstdint>
#include <memory>
#include <functional>

namespace ara
{
namespace tsync
{
namespace internal
{

struct SpecifierMapping
{
    using mapping_type_orig = ara::core::Vector<ara::core::InstanceSpecifier>;

    SpecifierMapping(){};
    explicit SpecifierMapping(const ara::core::InstanceSpecifier& specifier);
    ara::core::String GetLocation(const ara::core::InstanceSpecifier& instanceSpecifier);

protected:
    /// @brief The file descriptor used to interact with shared memory.
    int fd_{-1};

    struct DataSharedMemory;
    /// @brief Pointer that is going to be mapped to the shared memory location where the actual clock data is being
    /// stored. There is also a custom deallocator involved, which takes care that the shared memory is unmapped and the
    /// file descriptor is closed.
    std::unique_ptr<SpecifierMapping::DataSharedMemory, std::function<void(SpecifierMapping::DataSharedMemory*)>>
        clockData_{nullptr};

    void OpenSharedMemory(ara::core::StringView path, std::uint32_t flags, std::uint32_t accessFlags);
    void AllocateSharedMemory(ara::core::StringView path);
    void InitSharedMemory();
    void MapSharedMemory(ara::core::StringView identifier, std::uint32_t accessFlags);
};

}  // namespace internal
}  // namespace tsync
}  // namespace ara

#endif  // ARA_TSYNC_INTERNAL_SPECIFIER_MAPPING_H
