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

#ifndef LIB_APDREST_INCLUDE_APD_REST_SERVER_FACTORY_H_
#define LIB_APDREST_INCLUDE_APD_REST_SERVER_FACTORY_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <memory>

#include "apd/rest/config.h"
#include "apd/rest/server.h"
#include "apd/rest/server_interface.h"

namespace apd
{
namespace rest
{

/**
 * TODO
 */
class ServerFactory
{
public:
    /**
     * Destructor
     */
    ~ServerFactory() = default;

    /**
     * Singelton Get
     * @return Singelton instance of Server Factory
     */
    static ServerFactory* Get()
    {
        static ServerFactory instance;
        return &instance;
    }

    /**
     * TODO
     * @param protocol
     * @param binding
     * @param hnd
     * @param alloc
     * @return
     */
    std::unique_ptr<ServerInterface> CreateServer(String protocol,
        config::ServerBinding binding,
        const Function<RequestHandlerType>& hnd,
        Allocator* alloc);

protected:
    ServerFactory() = default;  //< Default constructor protected

private:
    ServerFactory(ServerFactory const&) = delete;  // Copy construct deleted
    ServerFactory(ServerFactory&&) = delete;  // Move construct deleted
    ServerFactory& operator=(ServerFactory const&) = delete;  // Copy assign deleted
    ServerFactory& operator=(ServerFactory&&) = delete;  // Move assign deleted
};

}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_SERVER_FACTORY_H_
