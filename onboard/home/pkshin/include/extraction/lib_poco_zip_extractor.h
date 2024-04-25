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

#ifndef ARA_UCM_LIBS_EXTRACTION_LIB_POCO_ZIP_EXTRACTOR_H_
#define ARA_UCM_LIBS_EXTRACTION_LIB_POCO_ZIP_EXTRACTOR_H_

#include "extraction/software_package_extractor.h"
#include "extraction/filesystem.h"
#include "ara/core/string.h"
#include <string>
#include <memory>
#include <utility>

// forwarding declaration for Path, Decompress, ZipLocalFileHeader
namespace Poco
{
class Path;
namespace Zip
{
class Decompress;
class ZipLocalFileHeader;
}  // namespace Zip
}  // namespace Poco

namespace ara
{
namespace ucm
{
namespace libs
{

/// @brief Archive extraction using the Poco library (Poco::Zip)
///
/// @uptrace{SWS_UCM_00001, 9da6dc21e02d92b81d6f3b264ab6b54301c0811b}
class LibPocoZipExtractor : public SoftwarePackageExtractor
{
public:
    /// @brief Create a new instance of the extractor.
    ///
    /// @param fs The reference to the filesystem
    explicit LibPocoZipExtractor(Filesystem& fs);

    /// @copybrief SoftwarePackageExtractor::Extract()
    ///
    /// The last folder of the @p extractionDirectory must not yet exist and
    /// will be created during extraction and deleted during cleanup.
    /// If extraction fails (i.e. false is returned) the extraction directory @p
    /// extractionDirectory is deleted.
    ///
    /// @copydetails SoftwarePackageExtractor::Extract()
    bool Extract(const ara::core::String& archivePath,
        const ara::core::String& extractionDirectory,
        const ara::core::String& id) override;

    /// @copybrief SoftwarePackageExtractor::Extract()
    ///
    /// For this implementation the cleanup is simplified to just deleting the
    /// extractionDirectory
    void Cleanup(const ara::core::String& id) override;

private:
    using DecompressOkInfo = std::pair<const Poco::Zip::ZipLocalFileHeader, const Poco::Path>;
    using DecompressErrorInfo = std::pair<const Poco::Zip::ZipLocalFileHeader, const std::string>;

    /// @brief Handles an Ok event
    /// This method is invoked when a file (or a directory) is
    /// successfully extracted from the zip archive
    ///
    /// @param pSender The notifier (should be Decompress object)
    /// @param info The information about successfully extracted file or directory
    void OnDecompressOk(const void* pSender, DecompressOkInfo& info);

    /// @brief Handles an Error event
    /// This method is invoked when an error happens
    /// during the extraction process
    ///
    /// @param pSender The notifier (should be Decompress object)
    /// @param info The information about an error
    void OnDecompressError(const void* pSender, DecompressErrorInfo& info);

    /// @brief Flag to indicate that the archive is actually processed
    /// (an Ok event handler is invoked)
    bool isProcessed_{false};

    /// @brief Flag to indicate that the archive extraction is successful
    /// There are no errors during the extraction process
    bool isSuccessful_{true};

    /// @brief Provides access to the filesystem
    Filesystem& fs_;

    /// @brief Stores the last extraction directory
    ara::core::String lastExtractionDirectory_;

    /// @brief Stores the list of extraction directories for the Cleanup
    ara::core::Vector<ara::core::String> extractionDirectories_;
};

}  // namespace libs
}  // namespace ucm
}  // namespace ara

#endif  // ARA_UCM_LIBS_EXTRACTION_BUSYBOX_ARCHIVE_EXTRACTOR_H_
