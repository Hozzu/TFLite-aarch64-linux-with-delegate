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

#ifndef LIB_APDREST_INCLUDE_APD_REST_CONFIG_H_
#define LIB_APDREST_INCLUDE_APD_REST_CONFIG_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <vector>
#include <stdexcept>
#include <fstream>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/pointer.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/schema.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

#include "apd/rest/string.h"
#include "ara/log/logger.h"

namespace apd
{
namespace rest
{
namespace config
{

namespace test
{

class Configuration_ConstructConfigurationHandler_Test; /**> forward declaration for testing */
class Configuration_ConfigurationFunctions_Test; /**> forward declaration for testing */

}  // namespace test

namespace additional
{
/**
 * Checks if the given String is a ipv4 or ipv6 address and alters the ipv6 address to url notation (if it is not
 * already in url notation)
 * @param address A string which represents an ip adress
 * @return The ipv4 adress as given or the ipv6 adress in url notation
 */
String DetermineAddressVersion(String address);
}  // namespace additional

/**
 * Typedef for Transportprotocol
 */
typedef String TransportProtocol_t;

/**
 * \brief Configuration parameters for host authorization
 *
 * This value represents the default authorization part of a Uri for all
 * client requests. An authorization component within a given Uri shall
 * override these values.
 */
struct Authorization_t
{
    String Adress_;  ///< Denotes an an IP address or FQDN of a proxy
    int Port_;  ///< Denotes an IP port number of a server
};

/**
 * \brief Configuration parameters for proxy authorization
 *
 * This value represent the configuration parameters for a proxy.
 * A trusted environment is assumed. Therefore authentication credentials
 * are not required.
 */
typedef Authorization_t Proxy_t;

/** \brief Base type for protocol- and end-point specific
 *
 * A binding represents all the configuration parameters for either a
 * client or a server endpoint.
 */
struct Binding
{
    /**
     * Default CTOR
     */
    Binding() = default;
    /**
     * Constructor
     * \param id Identifier for the binding
     * \param type The type of the binding (server/client)
     * \param tp The Transportprotocol of the binding (e.g. Http)
     */
    Binding(String id, String type, TransportProtocol_t tp);
    /**
     * \brief Uniquely identifes a binding configuration block
     */
    String Id_;

    /**
     * \brief Type of the binding (client or server)
     */
    String type_;

    /**
     * \brief Denotes the transport protocol of the given binding
     *
     * When a client is instantiated, it shall also instantiate
     * a suitable transport protocol binding which is uniquely identified
     * by this parameter.
     *
     * The protocol binding shall give access to the subsequent configuration
     * paramaters upon instantiation.
     */
    TransportProtocol_t transport_protocol_;
};

/**
 * Specific binding for clients
 */
struct ClientBinding : Binding
{
    /**
     * Default CTOR
     */
    ClientBinding() = default;

    /**
     * Constructor
     * \param id Identifier for the binding
     * \param type The type of the binding (server/client)
     * \param tp The Transportprotocol of the binding (e.g. Http)
     * \param auth The Authorization, containing address and port
     * \param proxy The proxy,containing address and port
     */
    ClientBinding(String id, String type, TransportProtocol_t tp, Authorization_t auth, Proxy_t proxy);
    Authorization_t authorization_;  ///<  Configuration parameters for host authorization
    Proxy_t proxy_;  ///<  Configuration parameters for proxy authorization
};

/**
 * Binding configuration for a server
 */
struct ServerBinding : Binding
{
    /**
     * Default CTOR
     */
    ServerBinding() = default;
    /**
     * Constructor
     * \param id Identifier for the binding
     * \param type The type of the binding (server/client)
     * \param tp The Transportprotocol of the binding (e.g. Http)
     * \param address The address of the server
     * \param port The port of the server
     */
    ServerBinding(String id, String type, TransportProtocol_t tp, String address, int port);
    String address_;  ///<  Configuration parameters for server adress
    int port_;  ///<  Configuration parameters for server port
};

/**
 * \brief Represents the configuration for a HTTP-based client or server endpoint
 *
 *  A binding is uniquely identified by its Id.
 */
struct HttpBinding : Binding
{ };

/** \brief Represents endpoint configurations
 *
 *  Endpoints configurations are uniquely identified by means of an identifier.  Depending on
 *  whether an endpoint is a client or server, a respective configuration record shall be looked-up.
 */
struct Configuration
{
public:
    /**
     * Constructor
     * \param id Identifier of the configuration
     * \param type
     */
    Configuration(String id, String type);

    /**
     * Default destructor
     */
    ~Configuration()
    { }

    /**
     * Unique identifier of a configuration record
     */
    String Id_;

    /**
     * Type of the configuration (server or client)
     */
    String type_;
};

/**
 * \brief Represents a client configuration record
 *
 * Only ClientConfiguration records are valid for client endpoints
 *
 */
struct ClientConfiguration : Configuration
{
    /**
     * Constructor
     * \param id Identifier for the Client configuration
     * \param type Type of the configuration (client/server)
     * \param binding_id The binding id, determining which binding belongs to this configuration
     */
    ClientConfiguration(String id, String type, String binding_id);
    /**
     * The binding id, determining which binding belongs to this configuration
     */
    String BindingId_;
};

/**
 * \brief Represents a client configuration record
 *
 * Only ClientConfiguration records are valid for server endpoints
 *
 */
struct ServerConfiguration : Configuration
{
    /**
     * Constructor
     * \param id Identifier for the Server configuration
     * \param type Type of the configuration (client/server)
     * \param binding_ids The binding ids (vector of binding identifier), determining which bindings belong to this
     * configuration
     */
    ServerConfiguration(String id, String type, std::vector<String> binding_ids);

    /**
     * The binding ids (vector of binding identifier), determining which bindings belong to this configuration
     */
    std::vector<String> BindingIds_;
};

/**
 * Configuration handler handles parsing of the config-json file and saves all available bindings and configs
 */
class ConfigurationHandler
{
public:
    /**
     * Creates a singelton instance of ConfigurationHanlder if not already existing
     * \return
     */
    static ConfigurationHandler& Instance()
    {
        static ConfigurationHandler configHandlerInstance("etc/configuration.json");

        return configHandlerInstance;
    }

    /**
     * Returns all ServerBindings read in from the configuration file
     * \param config_id
     * \return
     */
    std::vector<String> GetServerBindingIds(const String& config_id);

    /**
     * Returns the ServerBinding object linked to the given binding id
     * \param binding_id
     * \return
     */
    ServerBinding GetServerBinding(const String& binding_id);

    /**
     * TODO
     * @param config_id
     * @return
     */
    String GetClientBindingIds(const String& config_id);

    /**
     * TODO
     * @param binding_id
     * @return
     */
    ClientBinding GetClientBinding(const String& binding_id);

    // delete copy and move constructors and assign operators
    ConfigurationHandler(ConfigurationHandler const&) = delete;  // Copy construct deleted
    ConfigurationHandler(ConfigurationHandler&&) = delete;  // Move construct deleted
    ConfigurationHandler& operator=(ConfigurationHandler const&) = delete;  // Copy assign deleted
    ConfigurationHandler& operator=(ConfigurationHandler&&) = delete;  // Move assign deleted

protected:
    /**
     * Constructor
     * \param path The path to the config-json file plus the name of the file
     */
    explicit ConfigurationHandler(String path);

    /**
     * Destructor
     */
    virtual ~ConfigurationHandler() = default;

private:
    /**
     * All available client configurations
     */
    std::vector<ClientConfiguration> client_configs_;

    /**
     * All available client bindings
     */
    std::vector<ClientBinding> client_bindings_;

    /**
     * All available server configurations
     */
    std::vector<ServerConfiguration> server_configs_;

    /**
     * All available server bindings
     */
    std::vector<ServerBinding> server_bindings_;

    friend class test::Configuration_ConstructConfigurationHandler_Test;  //< Friend decleration for testing
    friend class test::Configuration_ConfigurationFunctions_Test;  //< Friend decleration for testing

    /**
     * \brief logging context instance
     */
    ara::log::Logger& log_{
        ara::log::CreateLogger("LCH", "Logger for Configuration Handler", ara::log::LogLevel::kVerbose)};
};

rapidjson::Document LoadFile(const std::string& path);

}  // namespace config
}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_CONFIG_H_
