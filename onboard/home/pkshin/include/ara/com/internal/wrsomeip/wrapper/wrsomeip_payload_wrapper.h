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

#pragma once

#include <vector>
#include <memory>
#include "ara/com/internal/wrsomeip/wrsomeip_types.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace wrsomeip
{
namespace wrapper
{

using namespace types;

class WrsomeipPayload
{
public:
    // We need 3 constructors with 3 data params that are initialized from runtime wrapper
    // create_payload()
    WrsomeipPayload();

    WrsomeipPayload(const byte_t* _data, length_t _size);

    WrsomeipPayload(const std::vector<types::byte_t>& _data);

    virtual ~WrsomeipPayload()
    { }

    // Overloading == op ->returns true if the given payload is equal to this one.
    virtual bool operator==(const WrsomeipPayload& _other);

    static SomeIpPayload cast_to_wrsomeip_payload(WrsomeipPayload& wrapped_payload);

    // Returns pointer to the payload content
    virtual byte_t* get_data();

    // Copies the given data array to the payload object.
    virtual void set_data(const byte_t* _data, size_t _length);

    void set_data(const std::vector<byte_t>& _data);

    void set_data(std::vector<byte_t>&& _data);

    // Returns the length of the payload content.
    virtual length_t get_length() const;

private:
    std::vector<byte_t> data_;
    size_t _size;
};

}  // namespace wrapper
}  // namespace wrsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara
