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

#ifndef ARA_UCM_LIBS_TRANSFER_SOFTWARE_PACKAGE_DATA_FACTORY_H_
#define ARA_UCM_LIBS_TRANSFER_SOFTWARE_PACKAGE_DATA_FACTORY_H_

#include "software_package_data.h"
#include "per_transfer_status_storage.h"
#include "ara/core/string.h"

namespace ara
{
namespace ucm
{
namespace libs
{

/// @brief An interface for creating SoftwarePackageData implementations of
/// SoftwarePackageData interface.
///
class SoftwarePackageDataFactory
{
public:
    SoftwarePackageDataFactory(TransferStatusKvs& storage, log::Logger& log)
        : storage_{storage}
        , log_{log}
    { }

    virtual ~SoftwarePackageDataFactory() = default;

    virtual std::unique_ptr<SoftwarePackageData> Create(ara::core::String directory, TransferIdType id)
    {
        return std::make_unique<SoftwarePackageData>(id, directory, storage_, log_);
    }

private:
    TransferStatusKvs& storage_;
    ara::log::Logger& log_;
};

}  // namespace libs
}  // namespace ucm
}  // namespace ara

#endif  // ARA_UCM_LIBS_TRANSFER_SOFTWARE_PACKAGE_DATA_FACTORY_H_
