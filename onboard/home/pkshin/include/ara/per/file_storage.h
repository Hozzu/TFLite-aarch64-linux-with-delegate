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

#ifndef ARA_PER_FILE_STORAGE_H_
#define ARA_PER_FILE_STORAGE_H_

#include "ara/core/result.h"
#include "ara/core/string_view.h"
#include "ara/core/instance_specifier.h"
#include "ara/core/string.h"

#include "ara/per/per_error_domain.h"
#include "ara/per/read_write_accessor.h"
#include "ara/per/shared_handle.h"
#include "ara/per/unique_handle.h"

///
/// @uptrace{SWS_PER_00002, fb49f277ba9a813303ba248e2a7970b903647cd7}
namespace ara
{
namespace per
{

/// @brief This enumeration defines how a file shall be opened. The values can be combined (using | and |=) as long
/// as they do not contradict each other.
///
/// @uptrace{SWS_PER_00147, 4b4fe61ccbc2e89c97c74805cf304f0ad61c69ce}
enum class OpenMode : uint32_t
{
    kAtTheBeginning = 1 << 0,  // Sets the seek pointer to the beginning of the file when the file is opened. This
                               // mode cannot be combined with kAtTheEnd.
    kAtTheEnd = 1 << 1,  // Sets the seek pointer to the end of the file when the file is opened. This mode cannot
                         // be combined with kAtTheBeginning or kTruncate.
    kTruncate
    = 1 << 2,  // Removes existing content when the file is opened. This mode cannot be combined with kAtTheEnd.
    kAppend = 1 << 3,  // Append to the end. Always seeks to the end of the file before writing.
    kText = 1 << 4,  // Opens the file as text. The encoding is specified during design time for the whole file
                     // storage by PersistencyFileProxyInterface.encoding.
    kBinary = 1 << 5  // Opens the file as binary. If not set, the file will be opened as configured by
                      // PersistencyFileProxyInterface.category or, if that is not configured, as text.
};

/// @brief This enumeration describes how and when a file was created.
///
/// @uptrace{SWS_PER_00435, a718bd43b80880b2794f5477bdf401f8fb9d8e1e}
enum class FileCreationState : uint32_t
{
    kCreatedDuringInstallion = 1,  // The file was created by Persistency after
    // installation of the application or after ResetPersistency.
    kCreatedDuringUpdate = 2,  // The file was created by Persistency during an update.
    kCreatedDuringReset = 3,  // The file was re-created due to a call to ResetFile or ResetAllFiles.
    kCreatedDuringRecovery = 4,  // The file was re-created by Persistency after a corruption was detected.
    kCreatedByApplication = 5  // The file was created by the application.
};

/// @brief This enumeration describes how and when a file was last modified.
///
/// @uptrace{SWS_PER_00436, c8e7408c237a18522eca796eff2edec3c2d4434b}
enum class FileModificationState : uint32_t
{
    kModifiedDuringUpdate = 2,  // The file was last modified by Persistency during an update.
    kModifiedDuringReset = 3,  // The file was last modified by Persistency due to a call to ResetFile or ResetAllFiles.
    kModifiedDuringRecovery = 4,  // The file was last modified by Persistency after a corruption was detected.
    kModifiedByApplication = 5  // The file was last modified by the application.
};

/// @brief Merges two OpenMode modifiers into one.
///
/// @uptrace{SWS_PER_00144, fdd9ca780a5c2a52dc182869d4e8fd6189531265}
/// @uptrace{SWS_PER_00514, b3aa067d51c88b8038ec5cbb7584d79de1dc9160}
/// @threadsafety{re-entrant}
/// @param[in] left First OpenMode modifiers.
/// @param[in] right Second OpenMode modifiers.
/// @returns returns Merged OpenMode modifiers.
constexpr OpenMode operator|(OpenMode left, OpenMode right) noexcept;

/// @brief Merges an OpenMode modifier into this OpenMode.
///
/// @uptrace{SWS_PER_00434, 6a069fbdcd83d85e815f25382c642e40d9b9ef85}
/// @uptrace{SWS_PER_00514, b3aa067d51c88b8038ec5cbb7584d79de1dc9160}
/// @threadsafety{re-entrant}
/// @param[in] left Left OpenMode modifiers.
/// @param[in] right Right OpenMode modifiers.
/// @returns returns The modified OpenMode.
OpenMode& operator|=(OpenMode& left, OpenMode& right) noexcept;

/// @brief Intersect two OpenMode modifiers into one.
///
/// @threadsafety{no}
/// @param[in] left First OpenMode modifiers.
/// @param[in] right Second OpenMode modifiers,
/// @returns returns Intersected OpenMode modifiers.
inline OpenMode operator&(OpenMode left, OpenMode right) noexcept
{
    return ara::per::OpenMode(static_cast<std::uint32_t>(left) & static_cast<std::uint32_t>(right));
}

/// @brief This structure contains additional information on a file returned by GetFileInfo.
///
/// @uptrace{SWS_PER_00437, 14c1695caf981b009ba263430d63233088fc10fc}
/// @uptrace{SWS_PER_00441, 528547d0d9f6fc0b19df3b8f9f5e0a3d6d1e59af}
/// @uptrace{SWS_PER_00442, cb74892ad241fef5cd4b932e52fa9272443a9b0e}
/// @uptrace{SWS_PER_00443, dd37bda0f39d3eeadf4677195795905167a0507c}
/// @uptrace{SWS_PER_00444, 3f77b842dbe1358af1a0e3fc1574d023f8879d92}
/// @uptrace{SWS_PER_00445, 774dc5da716fef155b08100057f0dfa66e21fb9d}
/// @uptrace{SWS_PER_00458, adfd267c1a473655ac2d06642d5aec686aec5ed4}

struct FileInfo
{
    std::uint64_t creationTime = 0;
    std::uint64_t modificationTime = 0;
    std::uint64_t accessTime = 0;
    FileCreationState fileCreationState;
    FileModificationState fileModificationState;
};

/// @brief The File Storage contains a set of files identified by their names.
///
/// @uptrace{SWS_PER_00340, 0000000000000000000000000000000000000000}
class FileStorage
{
public:
    /// @brief Constructor for FileStorage.
    ///
    /// @uptrace{SWS_PER_00460, 0000000000000000000000000000000000000000}
    FileStorage() = default;

    /// @brief Move constructor for FileStorage.
    ///
    /// @uptrace{SWS_PER_00326, 7a8aca806e5913d4cb05c62c7d592b25e317b8e4}
    /// @threadsafety{no}
    /// @param[in] fp The FileStorage object to be moved.
    FileStorage(FileStorage&& fp) noexcept = delete;

    /// @brief Move assignment operator for FileStorage.
    ///
    /// @uptrace{SWS_PER_00327, e6f9bc23bebc632cf67cf4f10d6b87934293f5db}
    /// @threadsafety{no}
    /// @param[in] fp The FileStorage object to be moved.
    /// @returns The moved FileStorage object.
    FileStorage& operator=(FileStorage&& fp) & noexcept = delete;

    /// @brief The copy constructor for FileStorage shall not be used.
    ///
    /// @uptrace{SWS_PER_00328, 780cfa5a54b10fdad7e5bad1569218afc6155bba}
    /// @threadsafety{no}
    FileStorage(const FileStorage&) = delete;

    /// @brief The copy assignment operator for FileStorage shall not be used.
    ///
    /// @uptrace{SWS_PER_00329, 83b8072019168a37a950daf7480827b376184de7}
    /// @threadsafety{no}
    FileStorage& operator=(const FileStorage&) = delete;

    /// @brief Destructor for FileStorage.
    ///
    /// @uptrace{SWS_PER_00330, 0d033263d10cb4c91c569251f2358713b368b958}
    /// @threadsafety{no}
    virtual ~FileStorage() noexcept = default;

    /// @brief Returns a list of available files within this file storage.
    ///
    /// @uptrace{SWS_PER_00110, 90fdcc1257b99a772eed51278735a1da09c97159}
    /// @uptrace{SWS_PER_00509, 77caa85969cff5ad1b81dd03586401c5ed297e27}
    /// @threadsafety{re-entrant}
    /// @returns A Result, containing a list of availables files,
    /// or one of the errors defined for Persistency in PerErrc.
    virtual ara::core::Result<ara::core::Vector<ara::core::String>> GetAllFileNames() const noexcept = 0;

    /// @brief Recovers a file of this File Storage.
    ///
    /// @uptrace{SWS_PER_00337, 48ebcf4dfae8959d0cb224231e987ffce08cb92a}
    /// @uptrace{SWS_PER_00455, 90b12e036fb589ee7fc15cf5269c94c003fdf295}
    /// @threadsafety{re-entrant}
    /// @param[in] fileName The identifier of the file.
    /// @returns A Result of void
    virtual ara::core::Result<void> RecoverFile(ara::core::StringView fileName) noexcept = 0;

    /// @brief Resets a file to its initial content in manifest.
    ///
    /// @uptrace{SWS_PER_00338, 766dff4bbe819e31347eaf14ee989e17c9bb973a}
    /// @uptrace{SWS_PER_00479, 1cf64117eeeec32a2385e097c06df0561893678f}
    /// @threadsafety{no}
    /// @param[in] key The identifier of the file.
    /// @returns The success of the operation.
    virtual ara::core::Result<void> ResetFile(ara::core::StringView key) noexcept = 0;

    /// @brief Deletes a file from this proxy.
    ///
    /// @uptrace{SWS_PER_00111, 01f41293a2b7d0fb6d8a74f6ace147c846975975}
    /// @uptrace{SWS_PER_00510, 5991835806035d876ee8f1b68d039fd7a0e41452}
    /// @uptrace{SWS_PER_00511, 092667e1b25ba39517f24be1a60a76e7c584d187}
    /// @threadsafety{no}
    /// @param[in] key The identifier of the file.
    /// @returns The success of the operation.
    virtual ara::core::Result<void> DeleteFile(ara::core::StringView key) noexcept = 0;

    /// @brief Queries if a file is available in this file storage.
    ///
    /// @uptrace{SWS_PER_00112, 0834cd41e7febdcc5f422ba7c04c4c78f8343f9a}
    /// @uptrace{SWS_PER_00508, b21c16c82ff60b8628f75d2e39184e303c09ef7a}
    /// @threadsafety{re-entrant}
    /// @param[in] file Identifier of the file.
    /// @returns A Result, containing true if the file exists or false if it does not,
    /// or one of the errors defined for Persistency in PerErrc.
    virtual ara::core::Result<bool> FileExists(ara::core::StringView file) const noexcept = 0;

    /// @brief Returns the space in bytes currently occupied by a file of this File Storage.
    ///
    /// @uptrace{SWS_PER_00407, 4ccf9001a4a4a1721d9bb78a890c4319ad257094}
    /// @threadsafety{re-entrant}
    /// @param[in] Name of the file. May correspond to the PersistencyFile.fileName of a configured file.
    /// @returns Returns the space in bytes currently occupied by the content of a file of this File Storage.
    virtual ara::core::Result<std::uint64_t> GetCurrentFileSize(ara::core::StringView fileName) const noexcept = 0;

    /// @brief Opens a file of this File Storage for reading and writing with a user provided buffer.
    ///
    /// @uptrace{SWS_PER_00429, 9687326a94235ac582626bb5899324470f28f2fc}
    /// @uptrace{SWS_PER_00513, d49650ad7232cdd52ce5abca7a7edf118eaf2904}
    /// @threadsafety{re-entrant}
    /// @param[in] fileName Name of the file. May correspond to the PersistencyFile.fileName of a configured file.
    /// @param[in] mode Mode with which the file shall be opened.
    /// @param[in] buffer Memory to be used for block-wise reading/writing.
    /// @returns A Result containing a UniqueHandle for the file.
    virtual ara::core::Result<UniqueHandle<ReadWriteAccessor>> OpenFileReadWrite(ara::core::StringView fileName,
        OpenMode mode,
        ara::core::Span<ara::core::Byte> buffer) noexcept = 0;

    /// @brief Opens a file of this File Storage for reading and writing with a defined mode.
    ///
    /// @uptrace{SWS_PER_00113, 8a5354e95a683437033e0b2d28d31c6483e4e44d}
    /// @uptrace{SWS_PER_00513, d49650ad7232cdd52ce5abca7a7edf118eaf2904}
    /// @threadsafety{re-entrant}
    /// @param[in] fileName Name of the file. May correspond to the PersistencyFile.fileName of a configured file.
    /// @param[in] mode Mode with which the file shall be opened.
    /// @returns A Result, containing a UniqueHandle, or one of the errors defined for Persistency in PerErrc.
    ara::core::Result<UniqueHandle<ReadWriteAccessor>> OpenFileReadWrite(ara::core::StringView fileName,
        OpenMode mode) noexcept
    {
        ara::core::Span<ara::core::Byte> nullbuffer;
        return OpenFileReadWrite(fileName, mode, nullbuffer);
    }

    /// @brief Opens a file of the file storage for reading and writing.
    ///
    /// @uptrace{SWS_PER_00375, 3605bd090fa616d6d651644ef173dfc2717e46af}
    /// @uptrace{SWS_PER_00513, d49650ad7232cdd52ce5abca7a7edf118eaf2904}
    /// @threadsafety{re-entrant}
    /// @param[in] fileName Name of the file. May correspond to the PersistencyFile.fileName of a configured file.
    /// @returns A Result, containing a UniqueHandle, or one of the errors defined for Persistency in PerErrc.
    ara::core::Result<UniqueHandle<ReadWriteAccessor>> OpenFileReadWrite(ara::core::StringView fileName) noexcept
    {
        return OpenFileReadWrite(fileName, OpenMode::kAtTheBeginning);
    }

    /// @brief Opens a file of this File Storage for reading with a user provided buffer.
    ///
    /// @uptrace{SWS_PER_00430, e13d72f89b78897884fc53d7987f46a28f77b41b}
    /// @threadsafety{re-entrant}
    /// @param[in] fileName Name of the file. May correspond to the PersistencyFile.fileName of a configured file.
    /// @param[in] mode Mode with which the file shall be opened.
    /// @param[in] buffer Memory to be used for block-wise reading.
    /// @returns A Result containing a UniqueHandle for the file.
    virtual ara::core::Result<UniqueHandle<ReadAccessor>> OpenFileReadOnly(ara::core::StringView fileName,
        OpenMode mode,
        ara::core::Span<ara::core::Byte> buffer) noexcept = 0;

    /// @brief Opens a file of this File Storage for reading with a defined mode.
    ///
    /// @uptrace{SWS_PER_00114, 8cde5d43aa3258542ee69d5b3a4969a8aff20090}
    /// @threadsafety{re-entrant}
    /// @param[in] fileName Name of the file. May correspond to the PersistencyFile.fileName of a configured file.
    /// @param[in] mode Mode with which the file shall be opened.
    /// @returns A Result, containing a UniqueHandle, or one of the errors defined for Persistency in PerErrc.
    ara::core::Result<UniqueHandle<ReadAccessor>> OpenFileReadOnly(ara::core::StringView fileName,
        OpenMode mode) noexcept
    {
        ara::core::Span<ara::core::Byte> nullbuffer;
        return OpenFileReadOnly(fileName, mode, nullbuffer);
    }

    /// @brief Opens a file of the file storage for reading.
    ///
    /// @uptrace{SWS_PER_00376, 328f08a14817c2efb54a1fa4b196775d866bce75}
    /// @uptrace{SWS_PER_00512, 3e166c888927986373c49afea673e2bbb077e112}
    /// @threadsafety{re-entrant}
    /// @param[in] fileName Name of the file. May correspond to the PersistencyFile.fileName of a configured file.
    /// @returns A Result, containing a UniqueHandle, or one of the errors defined for Persistency in PerErrc.
    ara::core::Result<UniqueHandle<ReadAccessor>> OpenFileReadOnly(ara::core::StringView fileName) noexcept
    {
        return OpenFileReadOnly(fileName, OpenMode::kAtTheBeginning);
    }

    /// @brief Opens a file of this File Storage for writing with a user provided buffer.
    ///
    /// @uptrace{SWS_PER_00431, 8a6358165ce561e7ae39cd33e8ef548dd98f257b}
    /// @uptrace{SWS_PER_00513, d49650ad7232cdd52ce5abca7a7edf118eaf2904}
    /// @threadsafety{re-entrant}
    /// @param[in] fileName Name of the file. May correspond to the PersistencyFile.fileName of a configured file.
    /// @param[in] mode Mode with which the file shall be opened.
    /// @param[in] buffer Memory to be used for block-wise writing.
    /// @returns A Result containing a UniqueHandle for the file.
    virtual ara::core::Result<UniqueHandle<ReadWriteAccessor>> OpenFileWriteOnly(ara::core::StringView fileName,
        OpenMode mode,
        ara::core::Span<ara::core::Byte> buffer) noexcept = 0;

    /// @brief Opens a file of this File Storage for writing with a defined mode.
    ///
    /// @uptrace{SWS_PER_00115, d406185bc77dcdf6e135c0370494fffae7c1ec48}
    /// @uptrace{SWS_PER_00513, d49650ad7232cdd52ce5abca7a7edf118eaf2904}
    /// @threadsafety{re-entrant}
    /// @param[in] fileName Name of the file. May correspond to the PersistencyFile.fileName of a configured file.
    /// @param[in] mode Mode with which the file shall be opened.
    /// @returns A Result, containing a UniqueHandle, or one of the errors defined for Persistency in PerErrc.
    ara::core::Result<UniqueHandle<ReadWriteAccessor>> OpenFileWriteOnly(ara::core::StringView fileName,
        OpenMode mode) noexcept
    {
        ara::core::Span<ara::core::Byte> nullbuffer;
        return OpenFileWriteOnly(fileName, mode, nullbuffer);
    }

    /// @brief Opens a file of the file storage for writing.
    ///
    /// @uptrace{SWS_PER_00377, 68cafc6b663a18006f41fd283726562ba8345743}
    /// @uptrace{SWS_PER_00513, d49650ad7232cdd52ce5abca7a7edf118eaf2904}
    /// @threadsafety{re-entrant}
    /// @param[in] fileName Name of the file. May correspond to the PersistencyFile.fileName of a configured file.
    /// @returns A Result, containing a UniqueHandle, or one of the errors defined for Persistency in PerErrc.
    ara::core::Result<UniqueHandle<ReadWriteAccessor>> OpenFileWriteOnly(ara::core::StringView fileName) noexcept
    {
        return OpenFileWriteOnly(fileName, OpenMode::kTruncate);
    }

    /// @brief Returns additional information on a file of this File Storage
    ///
    /// @uptrace{SWS_PER_00438, 7347939fed8ebb9575aee4f1199452e9e2463bf4}
    /// @threadsafety{re-entrant}
    /// @param[in] fileName Name of the file. May correspond to the PersistencyFile.fileName of a configured file.
    /// @returns A Result containing a FileInfo struct. In case of an error, it contains any of the errors defined
    /// below, or a vendor specific error.
    virtual ara::core::Result<FileInfo> GetFileInfo(ara::core::StringView fileName) const noexcept = 0;
};

/// @brief Opens a file storage.
///
/// @uptrace{SWS_PER_00116, 2af376e1f8817c4885281459ace3f4d571b22845}
/// @uptrace{SWS_PER_00507, 6a529547166610d303371b4c5fffd5e628f9d3b1}
/// @threadsafety{re-entrant}
/// @param[in] proxy Identifier of the file proxy.
/// @returns A Result, containing a SharedHandle, or one of the errors defined for Persistency in PerErrc.
ara::core::Result<SharedHandle<FileStorage>> OpenFileStorage(const ara::core::InstanceSpecifier& port) noexcept;

/// @brief Returns the space in bytes currently occupied by a File Storage.
///
/// @uptrace{SWS_PER_00406, b850508e222440e3cfb4b81fb67367e0160dbcf0}
/// @uptrace{SWS_PER_00492, e51e4714df2dd209647a945356be82acd528f8fa}
/// @threadsafety{re-entrant}
/// @param[in] The shortName path of a PortPrototype typed by a PersistencyFileProxyInterface.
/// @returns A Result, containing the occupied space in bytes, or one of the errors defined for Persistency in PerErrc.
ara::core::Result<std::uint64_t> GetCurrentFileStorageSize(const ara::core::InstanceSpecifier& port) noexcept;

/// @brief Resets the whole File Storage with initial content from manifest file.
///
/// @uptrace{SWS_PER_00336, 0627ec445337ba6b64929c2bdebdf293548ca80d}
/// @uptrace{SWS_PER_00478, 80c353f31d0019b7db6391d6f5d3d1a67dd5bc61}
/// @threadsafety{re-entrant}
/// @param[in] The shortName path of a PortPrototype typed by a PersistencyFileProxyInterface.
/// @returns The success of the operation.
ara::core::Result<void> ResetAllFiles(const ara::core::InstanceSpecifier& port) noexcept;

/// @brief Recovers a File Storage, including all files.
///
/// @uptrace{SWS_PER_00335, 2f3e8b1fd98b56f6ade4c36ae955a8c93e699eae}
/// @uptrace{SWS_PER_00454, 0ea446a0c74eea34d28c044336b98e7dc0d9aebe}
/// @threadsafety{re-entrant}
/// @param[in] fs The shortName path of a PortPrototype typed by a PersistencyFileStorageInterface.
/// @returns A Result of void
ara::core::Result<void> RecoverAllFiles(const ara::core::InstanceSpecifier& fs) noexcept;

}  // namespace per
}  // namespace ara

#endif  // ARA_PER_FILE_STORAGE_H_
