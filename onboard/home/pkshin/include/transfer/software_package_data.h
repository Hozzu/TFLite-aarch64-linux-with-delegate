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

#ifndef ARA_UCM_LIBS_TRANSFER_SOFTWARE_PACKAGE_DATA_H_
#define ARA_UCM_LIBS_TRANSFER_SOFTWARE_PACKAGE_DATA_H_

#include <mutex>  // std::mutex

#include "ara/log/logger.h"  // ara::log::... ara::core::String

#include "transfer/per_transfer_status_storage.h"  // TransferStatusKvs
#include "transfer/transfer_instance.h"  //TransferInstance
#include "transfer/receive_types.h"  // TransferStartSuccessType TransferStartReturnType TransferDataReturnType GeneralResponseType TransferExitReturnType
#include "types/impl_type_swpackagestatetype.h"  // SwPackageStateType
#include "types/impl_type_transferidtype.h"  // TransferIdType

namespace ara
{
namespace ucm
{
namespace libs
{

/// @brief Class for storing data about software package in work
///
/// @uptrace{SWS_UCM_00007, 1f06ff0dbb62befd08052e7695c09b0f3a05cbbf}
/// @uptrace{SWS_UCM_00088, 2c554af2e9b7d2245f4a77c537c6c6c98f81081a}
/// @uptrace{SWS_UCM_00140, 8ba576dd3ad228763c55cc3014c1a2ee89b38a4e}
/// @uptrace{SWS_UCM_00008, f400298ac5a56430ea4e5109cab7425b31a15126}
/// @uptrace{SWS_UCM_00010, 51f4427c62246fc8068bbe5f948197df0b597cb5}
/// @uptrace{SWS_UCM_00145, 26d26578fd6c3efc2b626f95b59b7101b02c8cdc}
/// @uptrace{SWS_UCM_00087, a01a04a920f994d23cd806fb74c1efad271ef3e9}
/// @uptrace{SWS_UCM_00148, 154ed889ea52a64786a624b64755514fff7e86c4}
///

/// TODO: the only value of this class is SetProcessProgressValue()/GetProcessProgressValue() functions
/// It is only valid and interesting during processing, otherwise TransferInstance has all data.
class SoftwarePackageData
{
public:
    SoftwarePackageData(TransferIdType, const ara::core::String&, TransferStatusKvs&, log::Logger& log);

    virtual ~SoftwarePackageData() = default;

    /// @brief get id of the object
    ///
    /// @returns id of the object
    virtual TransferIdType const& GetID() const
    {
        return transfer_->getId();
    }

    /// @brief set new state to this object
    ///
    /// @param state new state to set
    virtual void SetState(SwPackageStateType state)
    {
        std::lock_guard<std::mutex> guard(access_);

        log_.LogInfo() << ara::core::String("id=") + std::to_string(transfer_->getId()) << "state changes:" <<
            [&](::ara::ucm::SwPackageStateType const& swPackageState) {
                switch (swPackageState) {
                case ara::ucm::SwPackageStateType::kTransferring:
                    return ara::core::String{"Transferring"};
                    break;
                case ara::ucm::SwPackageStateType::kTransferred:
                    return ara::core::String{"Transferred"};
                    break;
                case ara::ucm::SwPackageStateType::kProcessing:
                    return ara::core::String{"Processing"};
                    break;
                case ara::ucm::SwPackageStateType::kProcessed:
                    return ara::core::String{"Processed"};
                    break;
                default:
                    return ara::core::String{"UNKNOWN("} + std::to_string(static_cast<int>(state)) + ")";
                    break;
                }
            }(state_) << "->"
                       << [&](::ara::ucm::SwPackageStateType const& swPackageState) {
                              switch (swPackageState) {
                              case ara::ucm::SwPackageStateType::kTransferring:
                                  return ara::core::String{"Transferring"};
                                  break;
                              case ara::ucm::SwPackageStateType::kTransferred:
                                  return ara::core::String{"Transferred"};
                                  break;
                              case ara::ucm::SwPackageStateType::kProcessing:
                                  return ara::core::String{"Processing"};
                                  break;
                              case ara::ucm::SwPackageStateType::kProcessed:
                                  return ara::core::String{"Processed"};
                                  break;
                              default:
                                  return ara::core::String{"UNKNOWN("} + std::to_string(static_cast<int>(state)) + ")";
                                  break;
                              }
                          }(state);

        state_ = state;
    }

    /// @brief get state of the package (e.g. kTransferring, kProcessed)
    ///
    /// @returns state of the object
    virtual SwPackageStateType const& GetState() const
    {
        std::lock_guard<std::mutex> guard(access_);

        return state_;
    }

    /// @brief Start the transfer of a Software Package (or a Vehicle Package)
    /// Transfer Id for subsequent calls to TransferData will be generated
    /// and returned as a part of TransferStartOutput.
    ///
    /// @param size Size (in bytes) of the Software Package to be transferred.
    ///
    /// @return The struct which contains the result of the transfer start operation
    /// and transfer id generated for this operation.
    virtual TransferStartReturnType TransferStart(std::uint64_t size)
    {
        std::lock_guard<std::mutex> guard(access_);
        log_.LogDebug() << ara::core::String(__func__) + "(" + std::to_string(transfer_->getId()) + ")";
        const auto result = transfer_->TransferStart(size);
        return result;
    }

    /// @brief Block-wise transfer of a Software Package.
    ///
    /// @param data Data block of the Software Package.
    /// @param blockCounter Block counter of the current block.
    ///
    /// @return The result of transferring current data block, which specifies if the
    /// sw package has been successfully transferred.
    virtual TransferDataReturnType TransferData(const ByteVectorType& data, const std::uint64_t& blockCounter)
    {
        std::lock_guard<std::mutex> guard(access_);
        const auto result = transfer_->TransferData(data, blockCounter);
        return result;
    }

    /// @brief Finish the transfer of a Software Package.
    ///
    /// @return The result of finishing this sw package transfer, which specifies if the
    /// sw package has been successfully transferred.
    virtual TransferExitReturnType TransferExit()
    {
        std::lock_guard<std::mutex> guard(access_);
        log_.LogDebug() << ara::core::String(__func__) + "(" + std::to_string(transfer_->getId()) + ")";
        const auto result = transfer_->TransferExit();
        return result;
    }

    virtual ara::core::String GetPackageFilename() const
    {
        return transfer_->GetPackageFilename();
    }

    /// @brief Delete a Software Package.
    ///
    /// @return The result of deleting sw package, which specifies if the
    /// sw package has been successfully deleted.
    virtual DeleteTransferReturnType DeleteTransfer()
    {
        std::lock_guard<std::mutex> guard(access_);
        log_.LogDebug() << ara::core::String(__func__) + "(" + std::to_string(transfer_->getId()) + ")";
        const auto result = transfer_->DeleteTransfer();
        return result;
    }

    virtual void SetProcessProgressValue(std::uint8_t value)
    {
        // prevent setting of values larger than max allowed value
        processProgressValue = value > 100 ? processProgressValue : value;
    }

    virtual std::uint8_t GetProcessProgressValue() const
    {
        return processProgressValue;
    }
    /// @brief Get the transferred bytes of a Software Package.
    ///
    /// @return The number of transferred bytes of a Software Package.
    virtual std::uint64_t GetReceivedBytes() const
    {
        return transfer_->GetReceivedBytes();
    }
    /// @brief Get the transferred blocks of a Software Package.
    ///
    /// @return The number of transferred blocks of a Software Package.
    virtual std::uint64_t GetReceivedBlocks() const
    {
        return transfer_->GetReceivedBlocks();
    }

    virtual void markToBeCancelled()
    {
        std::lock_guard<std::mutex> guard(access_);
        cancelMark = CancelState::TO_BE_CANCELLED;
    }

    virtual bool isMarkedToBeCancelled() const
    {
        std::lock_guard<std::mutex> guard(access_);
        return cancelMark == CancelState::TO_BE_CANCELLED;
    }

    virtual void markAsCancelled()
    {
        std::lock_guard<std::mutex> guard(access_);
        cancelMark = CancelState::CANCEL_DONE;
    }

    virtual bool isMarkedAsCancelled() const
    {
        std::lock_guard<std::mutex> guard(access_);
        return cancelMark == CancelState::CANCEL_DONE;
    }

private:
    // the default value 0xff is used as "no information available"
    uint8_t processProgressValue = 0xff;

    /// @brief state of the object
    SwPackageStateType state_;

    /// @brief part of package responsible for receiving transferring data
    std::unique_ptr<TransferInstance> transfer_;

    /// @brief protect transfer_ and state_ from simultaneous access
    mutable std::mutex access_;

    enum class CancelState
    {
        NO_CANCEL_REQUESTED,
        TO_BE_CANCELLED,
        CANCEL_DONE
    };

    /// @brief flag to be raised if Cancel is called. Consumed in Process call
    CancelState cancelMark;

    /// @brief Logger for logging errors
    ara::log::Logger& log_;
};

}  // namespace libs
}  // namespace ucm
}  // namespace ara

#endif  // ARA_UCM_LIBS_TRANSFER_SOFTWARE_PACKAGE_DATA_H_
