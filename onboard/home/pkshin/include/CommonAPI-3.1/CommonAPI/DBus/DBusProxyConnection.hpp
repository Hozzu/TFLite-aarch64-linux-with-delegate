// Copyright (C) 2013-2017 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#error "Only <CommonAPI/CommonAPI.hpp> can be included directly, this file may disappear or change contents."
#endif

#ifndef COMMONAPI_DBUS_DBUSPROXYCONNECTION_HPP_
#define COMMONAPI_DBUS_DBUSPROXYCONNECTION_HPP_

#include <cstdint>
#include <functional>
#include <future>
#include <memory>
#include <set>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

#include <CommonAPI/Attribute.hpp>
#include <CommonAPI/Event.hpp>
#include <CommonAPI/Types.hpp>
#include <CommonAPI/DBus/DBusConfig.hpp>
#include <CommonAPI/DBus/DBusError.hpp>
#include <CommonAPI/DBus/DBusMessage.hpp>
#include <CommonAPI/DBus/DBusFunctionalHash.hpp>

namespace CommonAPI {
namespace DBus {

typedef std::function<void(const DBusMessage&)> DBusMessageHandler;

class DBusDaemonProxy;
class DBusServiceRegistry;
class DBusObjectManager;
class DBusProxy;

class DBusProxyConnection {
 public:
    class DBusMessageReplyAsyncHandler {
     public:
       virtual ~DBusMessageReplyAsyncHandler() {}
       virtual std::future<CallStatus> getFuture() = 0;
       virtual void onDBusMessageReply(const CallStatus&, const DBusMessage&) = 0;
       virtual void setExecutionStarted() = 0;
       virtual bool getExecutionStarted() = 0;
       virtual void setExecutionFinished() = 0;
       virtual bool getExecutionFinished() = 0;
       virtual void setTimeoutOccurred() = 0;
       virtual bool getTimeoutOccurred() = 0;
       virtual void setHasToBeDeleted() = 0;
       virtual bool hasToBeDeleted() = 0;
       virtual void lock() = 0;
       virtual void unlock() = 0;
    };

    class DBusSignalHandler;

    // objectPath, interfaceName, interfaceMemberName, interfaceMemberSignature
    typedef std::tuple<std::string, std::string, std::string, std::string> DBusSignalHandlerPath;
    typedef std::unordered_map<DBusSignalHandlerPath,
                                std::map<const DBusSignalHandler*,
                                    std::weak_ptr<DBusProxyConnection::DBusSignalHandler>>> DBusSignalHandlerTable;
    typedef std::unordered_multimap<std::string, std::pair<const DBusSignalHandler*,
                                        std::weak_ptr<DBusSignalHandler>>> DBusOMSignalHandlerTable;
    typedef DBusSignalHandlerPath DBusSignalHandlerToken;

    class DBusSignalHandler {
     public:
        virtual ~DBusSignalHandler() {}
        virtual void onSignalDBusMessage(const DBusMessage&) = 0;
        virtual void onInitialValueSignalDBusMessage(const DBusMessage&, const uint32_t) {};
        virtual void onSpecificError(const CommonAPI::CallStatus, const uint32_t ) {};
        virtual void setSubscriptionToken(const DBusSignalHandlerToken, const uint32_t) {};
    };

    typedef Event<AvailabilityStatus> ConnectionStatusEvent;

    virtual ~DBusProxyConnection() {}

    virtual bool isConnected() const = 0;

    virtual ConnectionStatusEvent& getConnectionStatusEvent() = 0;

    virtual bool sendDBusMessage(const DBusMessage& dbusMessage) const = 0;

    virtual bool sendDBusMessageWithReplyAsync(
            const DBusMessage& dbusMessage,
            std::unique_ptr<DBusMessageReplyAsyncHandler> dbusMessageReplyAsyncHandler,
            const CommonAPI::CallInfo *_info) const = 0;

    virtual DBusMessage sendDBusMessageWithReplyAndBlock(
            const DBusMessage& dbusMessage,
            DBusError& dbusError,
            const CommonAPI::CallInfo *_info) const = 0;

    virtual DBusSignalHandlerToken addSignalMemberHandler(
            const std::string& objectPath,
            const std::string& interfaceName,
            const std::string& interfaceMemberName,
            const std::string& interfaceMemberSignature,
            std::weak_ptr<DBusSignalHandler> dbusSignalHandler,
            const bool justAddFilter = false) = 0;

    virtual void subscribeForSelectiveBroadcast(const std::string& objectPath,
                                                                  const std::string& interfaceName,
                                                                  const std::string& interfaceMemberName,
                                                                  const std::string& interfaceMemberSignature,
                                                                  std::weak_ptr<DBusSignalHandler> dbusSignalHandler,
                                                                  DBusProxy* callingProxy,
                                                                  uint32_t tag) = 0;

    virtual void unsubscribeFromSelectiveBroadcast(const std::string& eventName,
                                                  DBusProxyConnection::DBusSignalHandlerToken subscription,
                                                  DBusProxy* callingProxy,
                                                  const DBusSignalHandler* dbusSignalHandler) = 0;

    virtual bool removeSignalMemberHandler(const DBusSignalHandlerToken& dbusSignalHandlerToken,
                                           const DBusSignalHandler* dbusSignalHandler = NULL) = 0;

    virtual bool addObjectManagerSignalMemberHandler(const std::string& dbusBusName,
                                                     std::weak_ptr<DBusSignalHandler> dbusSignalHandler) = 0;
    virtual bool removeObjectManagerSignalMemberHandler(const std::string& dbusBusName,
                                                        const DBusSignalHandler* dbusSignalHandler) = 0;

    virtual const std::shared_ptr<DBusObjectManager> getDBusObjectManager() = 0;

    virtual void registerObjectPath(const std::string& objectPath) = 0;
    virtual void unregisterObjectPath(const std::string& objectPath) = 0;

    virtual bool requestServiceNameAndBlock(const std::string& serviceName) const = 0;
    virtual bool releaseServiceName(const std::string& serviceName) const = 0;

    typedef std::function<bool(const DBusMessage&)> DBusObjectPathMessageHandler;

    virtual void setObjectPathMessageHandler(DBusObjectPathMessageHandler) = 0;
    virtual bool isObjectPathMessageHandlerSet() = 0;

    virtual bool hasDispatchThread() = 0;

    virtual void sendPendingSelectiveSubscription(
            DBusProxy* proxy, std::string interfaceMemberName,
            std::weak_ptr<DBusSignalHandler> dbusSignalHandler, uint32_t tag,
            std::string interfaceMemberSignature) = 0;

    virtual void pushDBusMessageReplyToMainLoop(const DBusMessage& reply,
                             std::unique_ptr<DBusMessageReplyAsyncHandler> dbusMessageReplyAsyncHandler) = 0;

    template<class DBusConnection, class Function, class... Arguments>
    void proxyPushFunctionToMainLoop(Function&& _function, Arguments&& ... _args) {
        static_cast<DBusConnection*>(this)->proxyPushFunctionToMainLoop(std::forward<Function>(_function), std::forward<Arguments>(_args) ...);
    }

    virtual void addSignalStateHandler(
            std::shared_ptr<DBusProxyConnection::DBusSignalHandler> _handler,
            const uint32_t _subscription) = 0;

    virtual void removeSignalStateHandler(
                std::shared_ptr<DBusProxyConnection::DBusSignalHandler> _handler,
                const uint32_t _tag, bool _remove_all) = 0;

    virtual void handleSignalStates() = 0;
};

} // namespace DBus
} // namespace CommonAPI

#endif // COMMONAPI_DBUS_DBUSPROXYCONNECTION_HPP_
