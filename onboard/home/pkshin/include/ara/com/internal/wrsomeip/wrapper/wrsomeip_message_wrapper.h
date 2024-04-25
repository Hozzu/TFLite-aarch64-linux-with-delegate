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

#include <memory>
#include <functional>
#include "ara/com/internal/wrsomeip/wrsomeip_types.h"
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

#define CONVERT_WORD_TO_LONG(x0, x1) (uint32_t((x0) << 16 | (x1)))
using namespace types;

class WrsomeipMessage
{

public:
    typedef std::function<void(const std::shared_ptr<WrsomeipMessage>&)> message_handler_t;

    WrsomeipMessage();

    virtual ~WrsomeipMessage();

    SomeIPMessage* cast_to_someip_message(std::shared_ptr<wrapper::WrsomeipMessage> _message);

    // Returns a pointer to the message payload.
    std::shared_ptr<WrsomeipPayload> get_payload();
    // SomeIpPayload get_payload();

    // Set the message payload.
    void set_payload(std::shared_ptr<WrsomeipPayload> _payload);

    ServiceId get_service() const;

    // Set the service identifier in the message header.
    void set_service(ServiceId _service);

    InstanceId get_instance();

    // Set the instance identifier in the message header.
    void set_instance(InstanceId _instance);

    // Get the method/event identifier from the message header.
    method_t get_method() const;

    // Set the method/event identifier in the message header.
    void set_method(method_t _method);

    // Get the payload length from the message header.
    length_t get_length() const;

    // virtual length_t get_length(std::shared_ptr<wrapper::WrsomeipMessage> _message) const;

    // Get the request identifier from the message header.
    request_t get_request() const;

    interface_version_t get_interface_version();

    // Set the interface version in the message header.
    void set_interface_version(interface_version_t _version);

    // Set someip protocol version
    void set_protocol_version(protocol_version_t _version);

    //  Set the message type in the message header.
    void set_message_type(MESSAGE_TYPE _type);

    //  Set the transport mode that will be used to send the message.
    void set_reliable(bool _is_reliable);

    bool is_reliable();

    // Get the return code from the message header.
    return_code_t get_return_code();

    // Set the return code in the message header.
    void set_return_code(return_code_e _code);

    client_t get_client();

    void set_client(client_t _client);

    session_t get_session();

    void set_session(session_t _session);

    // setter for someip header
    void set_header(SomeIpHeader header);

    // getter for someip header
    SomeIpHeader get_header();

    void set_message_data(message_t* message_data);
    message_t* get_message_data();

    void set_message_size(message_size_t message_size);
    message_size_t get_message_size();

    void set_message_length(length_t message_length);
    length_t get_message_length();

    void set_message_serializer(message_serial_t* serializer);
    message_serial_t* get_message_serializer();

private:  // members
    bool is_reliable_;
    message_t* message_data_;
    message_size_t message_size_;
    length_t message_length_;
    message_serial_t* serializer_;
    std::shared_ptr<WrsomeipPayload> payload_;
    SomeIpHeader header_;
    SomeIPMessage* message_;
};

}  // namespace wrapper
}  // namespace wrsomeip
}  // namespace internal
}  // namespace com
}  // namespace ara
