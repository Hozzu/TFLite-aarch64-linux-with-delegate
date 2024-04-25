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

#ifndef ARA_UCM_LIBS_TEST_HELPER_H_
#define ARA_UCM_LIBS_TEST_HELPER_H_

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <iostream>
#include <fstream>

#include "ara/core/vector.h"
#include "ara/core/string.h"

#include "transfer/software_package_data.h"  // SoftwarePackageData
#include "transfer/software_package_data_factory.h"  // SoftwarePackageDataFactory
#include "transfer/per_transfer_status_storage.h"

#include "crypto/crypto.h"
#include "extraction/filesystem.h"

namespace ara
{
namespace ucm
{
namespace libs
{

static const ara::core::String kTestDataPath = "/usr/share/apdtest/ucm";
static const ara::core::String kTestWorkingDir = "/usr/var/apdtest/ucm";
static const ara::core::String kTestOptPath = "/usr/var/apdtest/ucm/opt";
static const ara::core::String kTestTemporaryDir = "/var/lib/apd_ucm/tmp";
static const ara::core::String kTestInstallSwPackagePath = kTestDataPath + "/SWP_TEST1_INS.zip";
static const ara::core::String kTestUninstallSwPackagePath = kTestDataPath + "/SWP_TEST1_REM.zip";
static const ara::core::String kTestUpdateSwPackagePath = kTestDataPath + "/SWP_TEST1_UPD.zip";

static const ara::core::String kSwclManifestName = "SWCL_MANIFEST.json";
static const ara::core::String kSwclDir = kTestOptPath + "/updateDir/swcls";
static const ara::core::String kSwcl_A_Dir = kSwclDir + "/swcl_a/1_0_0_0";
static const ara::core::String kSwcl_A_App1Proc1Dir = kSwcl_A_Dir + "/app1/process1";
static const ara::core::String kSwcl_A_App1Proc2Dir = kSwcl_A_Dir + "/app1/process2";
static const ara::core::String kSwcl_A_App2Proc1Dir = kSwcl_A_Dir + "/app2/process1";
static const ara::core::String kSwcl_B_Dir = kSwclDir + "/swcl_b/1_0_0_2";
static const ara::core::String kSwcl_B_App1Proc1Dir = kSwcl_B_Dir + "/app1/process1";
static const ara::core::String kSwcl_C_Dir = kSwclDir + "/swcl_c/1_0_0_5";
static const ara::core::String kSwcl_C_App1Proc1Dir = kSwcl_C_Dir + "/app1/process1";

class TransferStatusKvsMock : public TransferStatusKvs
{
public:
    MOCK_METHOD(void,
        StoreStatus,
        ((ara::core::StringView key), (const ara::core::Array<std::uint64_t, 4> status)),
        (override));
    MOCK_METHOD((ara::core::Optional<value_type>), GetStatus, (ara::core::StringView key), (const, override));
    MOCK_METHOD(void, RemoveStatus, (ara::core::StringView key), (override));
};

class SoftwarePackageDataMock : public SoftwarePackageData
{
public:
    SoftwarePackageDataMock(ara::log::Logger& log)
        : SoftwarePackageData(1, kTestTemporaryDir, unusedKvs, log)
        , defaultID(1)
    {
        ON_CALL(*this, GetID()).WillByDefault(::testing::ReturnRef(defaultID));
    }

    MOCK_METHOD((TransferIdType const&), GetID, (), (const, override));
    MOCK_METHOD(TransferStartReturnType, TransferStart, (std::uint64_t size), (override));
    MOCK_METHOD(TransferExitReturnType, TransferExit, (), (override));

    TransferStartReturnType CallTransferStart(std::uint64_t size)
    {
        return SoftwarePackageData::TransferStart(size);
    }

    TransferStatusKvs unusedKvs;
    TransferIdType defaultID;
};

class SoftwarePackageDataFactoryStub : public SoftwarePackageDataFactory
{
public:
    SoftwarePackageDataFactoryStub(ara::core::String const& logPrefix, ara::log::Logger& log)
        : SoftwarePackageDataFactory(kvsMock, log)
        , swPackageMock(std::make_unique<::testing::NiceMock<SoftwarePackageDataMock>>(log))
    {
        static_cast<void>(logPrefix);
    }

    std::unique_ptr<SoftwarePackageData> Create(ara::core::String, TransferIdType) override
    {
        return std::move(swPackageMock);
    }

    TransferStatusKvsMock kvsMock;
    std::unique_ptr<::testing::NiceMock<SoftwarePackageDataMock>> swPackageMock;
};

class TransferInstanceMock : public TransferInstance
{
    TransferStatusKvs unusedKvs;

public:
    TransferInstanceMock()
        : TransferInstance(0, "", unusedKvs)
    { }

    MOCK_METHOD(TransferStartReturnType, TransferStart, (std::uint64_t size), (override));
    MOCK_METHOD(TransferDataReturnType,
        TransferData,
        (const ByteVectorType& data, const std::uint64_t& blockCounter),
        (override));
    MOCK_METHOD(TransferExitReturnType, TransferExit, (), (override));
    MOCK_METHOD(ara::core::String, GetPackageFilename, (), (const, override));
    MOCK_METHOD(DeleteTransferReturnType, DeleteTransfer, (), (const, override));
};

class CryptoMock : public libs::Crypto
{
public:
    CryptoMock()
    { }

    MOCK_METHOD(bool,
        CheckSignature,
        (const ara::core::String&, const ara::core::String&, const ara::core::String&),
        (const, override));
    MOCK_METHOD(ara::core::String, GetFileHash, (const ara::core::String&), (const, override));
};

class FilesystemMock : public libs::Filesystem
{
public:
    FilesystemMock()
    { }

    MOCK_METHOD(ara::core::Vector<ara::core::String>, GetFilesRecursive, (const ara::core::String&), (const, override));
    MOCK_METHOD(ara::core::Vector<ara::core::String>,
        GetFilesRecursiveRelative,
        (const ara::core::String&),
        (const, override));
    MOCK_METHOD((ara::core::Vector<ara::core::String>),
        GetSubdirectories,
        (const ara::core::String&),
        (const, override));
    MOCK_METHOD(ara::core::Result<uint64_t>, GetFreeDiskSpace, (const ara::core::String&), (const, override));
    MOCK_METHOD(bool, CreateDirectory, (const ara::core::String&), (const, override));
    MOCK_METHOD(bool, DoesDirectoryExist, (const ara::core::String&), (const, override));
    MOCK_METHOD(ara::core::Result<void>,
        CopyDirectory,
        (const ara::core::String&, const ara::core::String&),
        (const, override));
    MOCK_METHOD(ara::core::Result<void>,
        MoveDirectory,
        (const ara::core::String&, const ara::core::String&),
        (const, override));
    MOCK_METHOD(ara::core::Result<void>, RemoveDirectory, (const ara::core::String&), (const, override));
    MOCK_METHOD(ara::core::Result<uint64_t>, GetDirectorySize, (const ara::core::String&), (const, override));
    MOCK_METHOD(bool, DoesFileExist, (const ara::core::String&), (const, override));
};

}  // namespace libs
}  // namespace ucm
}  // namespace ara

#endif  // ARA_UCM_LIBS_TEST_HELPER_H_
