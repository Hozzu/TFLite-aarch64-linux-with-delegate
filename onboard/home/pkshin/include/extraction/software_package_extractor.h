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

#ifndef ARA_UCM_LIBS_EXTRACTION_SOFTWARE_PACKAGE_EXTRACTOR_H_
#define ARA_UCM_LIBS_EXTRACTION_SOFTWARE_PACKAGE_EXTRACTOR_H_

#include "ara/core/string.h"

namespace ara
{
namespace ucm
{
namespace libs
{

/// @brief Interface for software package extraction.
///
/// @uptrace{SWS_UCM_00001, 9da6dc21e02d92b81d6f3b264ab6b54301c0811b}
class SoftwarePackageExtractor
{
public:
    virtual ~SoftwarePackageExtractor() = default;

    /// @brief Extract provided archive into the provided directory.
    ///
    /// If the extraction was unsuccessful any partially extracted files/folders are deleted.
    ///
    /// @param archivePath The full file path to the archive
    /// @param extractionDirectory The full path to the target directory.
    ///
    /// @returns True if archive was successfully extracted, else false
    virtual bool Extract(const ara::core::String& archivePath,
        const ara::core::String& extractionDirectory,
        const ara::core::String& id)
        = 0;

    /// @brief Cleanup of extracted files.
    ///
    /// This deletes any files or folders which have been created as part of the last extraction
    virtual void Cleanup(const ara::core::String& id) = 0;
};

}  // namespace libs
}  // namespace ucm
}  // namespace ara

#endif  // ARA_UCM_LIBS_EXTRACTION_SOFTWARE_PACKAGE_EXTRACTOR_H_
