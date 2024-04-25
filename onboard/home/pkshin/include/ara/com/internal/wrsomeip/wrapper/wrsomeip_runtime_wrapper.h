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
#include <string>
#include <vector>
#include <mutex>
#include "ara/com/internal/wrsomeip/wrapper/wrsomeip_application_wrapper.h"
#include "ara/com/internal/wrsomeip/wrapper/wrsomeip_message_wrapper.h"
#include "ara/com/internal/wrsomeip/wrapper/wrsomeip_payload_wrapper.h"

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

class WrsomeipRuntime
{
public:
    static std::shared_ptr<WrsomeipRuntime> get();

    virtual ~WrsomeipRuntime()
    { }

    // Creates a wrsomeip wrapper application object.
    virtual std::shared_ptr<WrsomeipApplication> create_application(const std::string& _name = "");

    // Constructs an empty request message.
    virtual std::shared_ptr<WrsomeipMessage> create_request(bool _reliable = false) const;

    // Constructs an empty response message from a given request message
    virtual std::shared_ptr<WrsomeipMessage> create_response(const std::shared_ptr<WrsomeipMessage>& _request) const;

    // Creates an empty payload object.
    virtual std::shared_ptr<WrsomeipPayload> create_payload() const;

    // Creates a payload object filled with the given data.
    virtual std::shared_ptr<WrsomeipPayload> create_payload(const byte_t* _data, uint32_t _size) const;

    // Creates a payload object filled with the given data.
    virtual std::shared_ptr<WrsomeipPayload> create_payload(const std::vector<byte_t>& _data) const;

private:
    mutable std::mutex applications_mutex_;
    static std::shared_ptr<WrsomeipRuntime> the_runtime_;
    std::map<std::string, std::weak_ptr<WrsomeipApplication>> applications_;
};

}  // namespace wrapper
}  // namespace wrsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara
