// Copyright (C) 2013-2017 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#error "Only <CommonAPI/CommonAPI.hpp> can be included directly, this file may disappear or change contents."
#endif

#ifndef COMMONAPI_DBUS_DBUS_DAEMON_PROXY_HPP_
#define COMMONAPI_DBUS_DBUS_DAEMON_PROXY_HPP_

#include <functional>
#include <string>
#include <vector>

#include <CommonAPI/Address.hpp>

#include <CommonAPI/DBus/DBusAttribute.hpp>
#include <CommonAPI/DBus/DBusEvent.hpp>
#include <CommonAPI/DBus/DBusProxyBase.hpp>

namespace CommonAPI {
namespace DBus {

class StaticInterfaceVersionAttribute: public InterfaceVersionAttribute {
 public:
    StaticInterfaceVersionAttribute(const uint32_t& majorValue, const uint32_t& minorValue);

    void getValue(CommonAPI::CallStatus& callStatus, Version &_version, const CommonAPI::CallInfo *_info) const;
    std::future<CommonAPI::CallStatus> getValueAsync(AttributeAsyncCallback _callback, const CommonAPI::CallInfo *_info);

 private:
    Version version_;
};

#ifndef DBUS_DAEMON_PROXY_DEFAULT_SEND_TIMEOUT
#define DBUS_DAEMON_PROXY_DEFAULT_SEND_TIMEOUT 10000
#endif

static const CommonAPI::CallInfo daemonProxyInfo(DBUS_DAEMON_PROXY_DEFAULT_SEND_TIMEOUT);

class DBusDaemonProxy : public DBusProxyBase,
                        public std::enable_shared_from_this<DBusDaemonProxy> {
 public:
    typedef Event<std::string, std::string, std::string> NameOwnerChangedEvent;

    typedef std::unordered_map<std::string, int> PropertyDictStub;
    typedef std::unordered_map<std::string, PropertyDictStub> InterfaceToPropertyDict;
    typedef std::unordered_map<std::string, InterfaceToPropertyDict> DBusObjectToInterfaceDict;

    typedef std::function<void(const CommonAPI::CallStatus&, std::vector<std::string>)> ListNamesAsyncCallback;
    typedef std::function<void(const CommonAPI::CallStatus&, bool)> NameHasOwnerAsyncCallback;
    typedef std::function<void(const CommonAPI::CallStatus&, DBusObjectToInterfaceDict)> GetManagedObjectsAsyncCallback;
    typedef std::function<void(const CommonAPI::CallStatus&, std::string)> GetNameOwnerAsyncCallback;

    COMMONAPI_EXPORT DBusDaemonProxy(const std::shared_ptr<DBusProxyConnection>& dbusConnection);
    COMMONAPI_EXPORT virtual ~DBusDaemonProxy() {}

    COMMONAPI_EXPORT virtual bool isAvailable() const;
    COMMONAPI_EXPORT virtual bool isAvailableBlocking() const;
    COMMONAPI_EXPORT virtual std::future<AvailabilityStatus> isAvailableAsync(
            isAvailableAsyncCallback _callback,
            const CallInfo *_info) const;

    COMMONAPI_EXPORT virtual ProxyStatusEvent& getProxyStatusEvent();

    COMMONAPI_EXPORT virtual InterfaceVersionAttribute& getInterfaceVersionAttribute();

    COMMONAPI_EXPORT void init();

    COMMONAPI_EXPORT static const char* getInterfaceId();

    COMMONAPI_EXPORT NameOwnerChangedEvent& getNameOwnerChangedEvent();

    COMMONAPI_EXPORT void listNames(CommonAPI::CallStatus& callStatus, std::vector<std::string>& busNames) const;

    template <typename DelegateObjectType>
    COMMONAPI_EXPORT std::future<CallStatus> listNamesAsync(typename DBusProxyAsyncCallbackHandler<DelegateObjectType,
                                                            std::vector<std::string>>::Delegate& delegate) const {
        DBusMessage dbusMessage = createMethodCall("ListNames", "");

        auto dbusMessageReplyAsyncHandler = std::move(DBusProxyAsyncCallbackHandler<
                DelegateObjectType, std::vector< std::string > >::create(delegate, std::tuple<std::vector<std::string>>()));

        std::future<CallStatus> callStatusFuture;
        try {
            callStatusFuture = dbusMessageReplyAsyncHandler->getFuture();
        } catch (std::exception& e) {
            COMMONAPI_ERROR("getNameOwnerAsync: messageReplyAsyncHandler future failed(", e.what(), ")");
        }

        if(getDBusConnection()->sendDBusMessageWithReplyAsync(
                        dbusMessage,
                        std::move(dbusMessageReplyAsyncHandler),
                        &daemonProxyInfo)) {
            return callStatusFuture;
        } else  {
            return std::future<CallStatus>();
        }
    }

    COMMONAPI_EXPORT void nameHasOwner(const std::string& busName, CommonAPI::CallStatus& callStatus, bool& hasOwner) const;

    template <typename DelegateObjectType>
    COMMONAPI_EXPORT std::future<CallStatus> nameHasOwnerAsync(const std::string& busName,
                                                               typename DBusProxyAsyncCallbackHandler<DelegateObjectType,
                                                               bool>::Delegate& delegate) const {
        DBusMessage dbusMessage = createMethodCall("NameHasOwner", "s");

        DBusOutputStream outputStream(dbusMessage);
        const bool success = DBusSerializableArguments<std::string>::serialize(outputStream, busName);
        if (!success) {
            std::promise<CallStatus> promise;
            promise.set_value(CallStatus::OUT_OF_MEMORY);
            return promise.get_future();
        }
        outputStream.flush();

        auto dbusMessageReplyAsyncHandler = std::move(DBusProxyAsyncCallbackHandler<
                DelegateObjectType, bool >::create(delegate, std::tuple< bool >()));

        std::future<CallStatus> callStatusFuture;
        try {
            callStatusFuture = dbusMessageReplyAsyncHandler->getFuture();
        } catch (std::exception& e) {
            COMMONAPI_ERROR("getNameOwnerAsync: messageReplyAsyncHandler future failed(", e.what(), ")");
        }

        if (getDBusConnection()->sendDBusMessageWithReplyAsync(
                        dbusMessage,
                        std::move(dbusMessageReplyAsyncHandler),
                        &daemonProxyInfo)) {
            return callStatusFuture;
        } else {
            return std::future<CallStatus>();
        }
    }

    template <typename DelegateObjectType>
    COMMONAPI_EXPORT std::future<CallStatus> getManagedObjectsAsync(const std::string& forDBusServiceName,
                                                                    typename DBusProxyAsyncCallbackHandler<DelegateObjectType,
                                                                    DBusObjectToInterfaceDict>::Delegate& delegate) const {
        static DBusAddress address(forDBusServiceName, "/", "org.freedesktop.DBus.ObjectManager");
        auto dbusMethodCallMessage = DBusMessage::createMethodCall(address, "GetManagedObjects", "");

        return getDBusConnection()->sendDBusMessageWithReplyAsync(
                        dbusMethodCallMessage,
                        DBusProxyAsyncCallbackHandler<DelegateObjectType, DBusObjectToInterfaceDict>::create(
                            delegate, std::tuple<DBusObjectToInterfaceDict>()
                        ),
                        &daemonProxyInfo);
    }

    /**
     * Get the unique connection/bus name of the primary owner of the name given
     *
     * @param busName Name to get the owner of
     * @param getNameOwnerAsyncCallback callback functor
     *
     * @return CallStatus::REMOTE_ERROR if the name is unknown, otherwise CallStatus::SUCCESS and the uniq name of the owner
     */
    template <typename DelegateObjectType>
    std::future<CallStatus> getNameOwnerAsync(const std::string& busName,
                                              typename DBusProxyAsyncCallbackHandler<DelegateObjectType,
                                              std::string>::Delegate& delegate) const {
        DBusMessage dbusMessage = createMethodCall("GetNameOwner", "s");

        DBusOutputStream outputStream(dbusMessage);
        const bool success = DBusSerializableArguments<std::string>::serialize(outputStream, busName);
        if (!success) {
            std::promise<CallStatus> promise;
            promise.set_value(CallStatus::OUT_OF_MEMORY);
            return promise.get_future();
        }
        outputStream.flush();

        auto dbusMessageReplyAsyncHandler = std::move(DBusProxyAsyncCallbackHandler<
               DelegateObjectType, std::string>::create(delegate, std::tuple<std::string>()));

        std::future<CallStatus> callStatusFuture;
        try {
            callStatusFuture = dbusMessageReplyAsyncHandler->getFuture();
        } catch (std::exception& e) {
            COMMONAPI_ERROR("getNameOwnerAsync: messageReplyAsyncHandler future failed(", e.what(), ")");
        }

        if (getDBusConnection()->sendDBusMessageWithReplyAsync(
                        dbusMessage,
                        std::move(dbusMessageReplyAsyncHandler),
                        &daemonProxyInfo)) {
            return callStatusFuture;
        } else {
            return std::future<CallStatus>();
        }
    }

 private:
    DBusEvent<NameOwnerChangedEvent, std::string, std::string, std::string> nameOwnerChangedEvent_;
    StaticInterfaceVersionAttribute interfaceVersionAttribute_;
};

} // namespace DBus
} // namespace CommonAPI

#endif // COMMONAPI_DBUS_DBUS_DAEMON_PROXY_HPP_
