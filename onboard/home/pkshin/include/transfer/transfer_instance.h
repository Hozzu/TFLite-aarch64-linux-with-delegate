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

#ifndef ARA_UCM_LIBS_TRANSFER_TRANSFER_INSTANCE_H_
#define ARA_UCM_LIBS_TRANSFER_TRANSFER_INSTANCE_H_

#include <memory>

#include "ara/core/instance_specifier.h"

#include "per_transfer_status_storage.h"
#include "transfer/receive_types.h"  // TransferStartReturnType TransferDataReturnType TransferExitReturnType DeleteTransferReturnType
#include "types/impl_type_transferidtype.h"  // TransferIdType

namespace ara
{
namespace ucm
{
namespace libs
{

/// @brief This class composes a file from vectors of bytes according to initially passed size.
/// It also check errors
///
class TransferInstance
{
public:
    TransferInstance(TransferIdType id, const ara::core::String& path, TransferStatusKvs& storage);
    virtual ~TransferInstance() = default;

    /// @brief Start the transfer of a Software/Vehicle Package.
    /// Transfer Id for subsequent calls to TransferData will be generated
    /// and returned as a part of TransferStartOutput.
    ///
    /// @param size Size (in bytes) of the Software Package to be transferred.
    ///
    /// @return The struct which contains the result of the transfer start operation
    /// and transfer id generated for this operation.
    virtual TransferStartReturnType TransferStart(std::uint64_t size);

    /// @brief Block-wise transfer of a Software Package.
    ///
    /// @param data Data block of the Software Package.
    /// @param blockCounter Block counter of the current block.
    ///
    /// @return The result of transferring current data block, which specifies if the
    /// sw package has been successfully transferred.
    virtual TransferDataReturnType TransferData(const ByteVectorType& data, const std::uint64_t& blockCounter);

    /// @brief Finish the transfer of a Software Package.
    ///
    /// @return The result of finishing this sw package transfer, which specifies if the
    /// sw package has been successfully transferred.
    virtual TransferExitReturnType TransferExit();

    virtual ara::core::String GetPackageFilename() const;

    /// @brief Delete a Software Package.
    ///
    /// @return The result of deleting sw package, which specifies if the
    /// sw package has been successfully deleted.
    virtual DeleteTransferReturnType DeleteTransfer() const;

    virtual TransferIdType const& getId() const
    {
        return transferId_;
    }
    /// @brief Get the transferred bytes of a Software Package.
    ///
    /// @return The number of transferred bytes of a Software Package.
    virtual std::uint64_t GetReceivedBytes() const;

    /// @brief Get the transferred blocks of a Software Package.
    ///
    /// @return The number of transferred blocks of a Software Package.
    virtual std::uint64_t GetReceivedBlocks() const;

private:
    enum class TransferState : uint32_t
    {
        Idle = 0,
        Transferring = 1,
    };

    void InitPath();

    ara::log::Logger& log_;
    TransferIdType transferId_;
    uint64_t receivedBytes_;
    ara::core::String transferDirectory_;
    uint64_t expectedBytes_;
    TransferState state_;
    uint64_t expectedBlock_;
    int fd_;
    ara::core::String key_;
    TransferStatusKvs& statusStorage_;
};

}  // namespace libs
}  // namespace ucm
}  // namespace ara

#endif  // ARA_UCM_LIBS_TRANSFER_TRANSFER_INSTANCE_H_
