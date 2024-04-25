// Copyright (C) 2013-2017 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#error "Only <CommonAPI/CommonAPI.hpp> can be included directly, this file may disappear or change contents."
#endif

#ifndef COMMONAPI_DBUS_DBUS_SERIALIZABLEARGUMENTS_HPP_
#define COMMONAPI_DBUS_DBUS_SERIALIZABLEARGUMENTS_HPP_

#include <CommonAPI/SerializableArguments.hpp>
#include <CommonAPI/DBus/DBusInputStream.hpp>
#include <CommonAPI/DBus/DBusOutputStream.hpp>

namespace CommonAPI {
namespace DBus {

template<typename... Arguments_>
using DBusSerializableArguments = CommonAPI::SerializableArguments<
                                        DBusInputStream,
                                        DBusOutputStream,
                                        Arguments_...
                                  >;

} // namespace DBus
} // namespace CommonAPI

#endif // COMMONAPI_DBUS_DBUSSERIALIZABLEARGUMENTS_HPP_
