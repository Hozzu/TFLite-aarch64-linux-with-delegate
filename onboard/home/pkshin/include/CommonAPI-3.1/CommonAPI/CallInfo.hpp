// Copyright (C) 2015-2017 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef COMMONAPI_CALLINFO_HPP_
#define COMMONAPI_CALLINFO_HPP_

#include <CommonAPI/Config.hpp>
#include <CommonAPI/Types.hpp>

namespace CommonAPI {

struct COMMONAPI_EXPORT CallInfo {
    CallInfo()
        : timeout_(DEFAULT_SEND_TIMEOUT_MS), sender_(0) {
    }
    CallInfo(Timeout_t _timeout)
        : timeout_(_timeout), sender_(0) {
    }
    CallInfo(Timeout_t _timeout, Sender_t _sender)
        : timeout_(_timeout), sender_(_sender) {
    }
    CallInfo(const CallInfo &_other)
        : timeout_(_other.timeout_), sender_(_other.sender_) {
    }

    Timeout_t timeout_;
    Sender_t sender_;
};

} // namespace CommonAPI

#endif // COMMONAPI_ADDRESS_HPP_
