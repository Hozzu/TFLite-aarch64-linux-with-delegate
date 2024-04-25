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

#ifndef ARA_PER_MANIFEST_ACCESS_MANIFEST_CONSTANTS_H_
#define ARA_PER_MANIFEST_ACCESS_MANIFEST_CONSTANTS_H_

namespace ara
{
namespace per
{
namespace manifest_constants
{

constexpr auto kManifestName = "MANIFEST";
constexpr auto kManifestFileName = "./etc/MANIFEST.json";
constexpr auto kPersistencyKVSPortTag = "persistency_port_prototype_to_key_value_database_mapping";
constexpr auto kPersistencyKVSInterfacePortTag = "persistency_key_value_database_interface";
constexpr auto kSpecifierTag = "instance_specifier";
constexpr auto kPortTypeTag = "port_type";
constexpr auto kDatabaseInfoTag = "key_value_database";
constexpr auto kDatabaseNameTag = "name";
constexpr auto kDatabaseKeyValuePairTag = "key_value_pair";
constexpr auto kDatabasePathTag = "uri";
constexpr auto kRedundancyConfigurationTag = "redundancy_handlings";
constexpr auto kRedundancyMNTag = "redundancy_m_out_of_n";
constexpr auto kRedundancyMTag = "M";
constexpr auto kRedundancyNTag = "N";
constexpr auto kRedundancyCRCTag = "redundancy_crc";
constexpr auto kRedundancyCrcFamilyTag = "algorithm_family";
constexpr auto kRedundancyCrcLengthTag = "length";

constexpr auto kEncryptionTag = "database_encryption";
constexpr auto kUpdateStrategyTag = "updatestrategy";

constexpr auto kPersistencyFileStoragePortTag = "persistency_port_prototype_to_file_array_mapping";
constexpr auto kPersistencyFileStorageInterfacePortTag = "persistency_file_proxy_interface";
constexpr auto kFileStorageInfoTag = "file_array";
constexpr auto kFileInitTag = "file";
constexpr auto kInitContentTag = "content_uri";
constexpr auto kFileNameTag = "file_name";

constexpr auto kMinimumSizeTag = "minimum_sustained_size";
constexpr auto kMaximumSizeTag = "maximum_allowed_size";

constexpr auto kReadOnlyPortType = "required-port";

}  // namespace manifest_constants
}  // namespace per
}  // namespace ara

#endif  // ARA_PER_MANIFEST_ACCESS_MANIFEST_CONSTANTS_H_
