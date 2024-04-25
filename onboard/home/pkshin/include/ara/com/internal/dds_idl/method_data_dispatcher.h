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

#ifndef ARA_COM_SRC_LIBARA_DDSIDLBINDING_METHOD_DATA_DISPATCHER_H_
#define ARA_COM_SRC_LIBARA_DDSIDLBINDING_METHOD_DATA_DISPATCHER_H_

#include <functional>

#include "ara/com/internal/dds_idl/types.h"
#include "ara/com/internal/dds_idl/common.h"

#include "ara/core/map.h"

namespace ara
{
namespace com
{
namespace internal
{
namespace dds
{

class MethodDataDispatcherBase
{
public:
    virtual ~MethodDataDispatcherBase() = default;
    virtual void Dispatch() = 0;
};

template <typename Reader, typename SampleType>
class MethodDataDispatcher : public MethodDataDispatcherBase
{
public:
    using MethodId = int32_t;
    using Handler = std::function<void(SampleType&)>;

    explicit MethodDataDispatcher(Reader& reader)
        : reader_(reader)
    { }

    void AddMethodHandler(MethodId const methodId, Handler const& handler)
    {
        auto registered = handlers_.find(methodId);
        if (registered != handlers_.end()) {
            common::logger().LogError()
                << "MethodDataDispatcher::Dispatch(): Method is already registered. discriminator: " << methodId;
            return;
        }

        handlers_[methodId] = handler;
    }

    void RemoveMethodHandler(MethodId const methodId)
    {
        auto registered = handlers_.find(methodId);
        if (registered == handlers_.end()) {
            common::logger().LogError()
                << "MethodDataDispatcher::RemoveMethodHandler(): Method is not found. discriminator: " << methodId;
            return;
        }

        handlers_.erase(registered);
    }

    void Dispatch() override
    {
        auto samples = reader_.Read(std::numeric_limits<size_t>::max());
        for (auto& sample : samples) {
            auto discriminator = sample.data._d();
            auto handler = handlers_.find(discriminator);
            if (handler == handlers_.end()) {
                common::logger().LogError()
                    << "MethodDataDispatcher::Dispatch(): Method not found for sample with discriminator "
                    << discriminator;
            } else {
                handler->second(sample);
            }
        }
    }

    bool IsEmpty()
    {
        return handlers_.empty();
    }

private:
    ara::core::Map<MethodId, Handler> handlers_;
    Reader& reader_;
};

}  // namespace dds
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_SRC_LIBARA_DDSIDLBINDING_METHOD_DATA_DISPATCHER_H_
