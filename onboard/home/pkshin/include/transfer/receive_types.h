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

#ifndef ARA_UCM_LIBS_TRANSFER_RECEIVE_TYPES_H_
#define ARA_UCM_LIBS_TRANSFER_RECEIVE_TYPES_H_

#include <cstdint>
#include "types/impl_type_bytevectortype.h"
#include "types/impl_type_transferidtype.h"  // TransferIdType

namespace ara
{
namespace ucm
{
namespace libs
{

enum class TransferStartSuccessType : std::uint32_t
{
    kSuccess = 0U,
    kInsufficientMemory = 1U
};

struct TransferStartReturnType
{
    TransferIdType transferId;
    TransferStartSuccessType transferStartSuccess;
};

enum class TransferDataReturnType : std::uint32_t
{
    kSuccess = 0U,
    kIncorrectBlock = 1U,
    kIncorrectSize = 2U,
    kInsufficientMemory = 3U,
    kInvalidTransferId = 4U,
    kOperationNotPermitted = 5U,
};

enum class GeneralResponseType : std::uint32_t
{
    kSuccess = 0U,
    kGeneralReject = 1U,
    kGeneralMemoryError = 2U,
    kTransferIdInvalid = 3U,
    kOperationNotPermitted = 4U
};

using DeleteTransferReturnType = GeneralResponseType;

enum class TransferExitReturnType : std::uint32_t
{
    kSuccess,
    kInsufficientData,
    kPackageInconsistent,
    kInvalidTransferId,
    kOperationNotPermitted,
};

}  // namespace libs
}  // namespace ucm
}  // namespace ara

#endif  // ARA_UCM_LIBS_TRANSFER_RECEIVE_TYPES_H_
