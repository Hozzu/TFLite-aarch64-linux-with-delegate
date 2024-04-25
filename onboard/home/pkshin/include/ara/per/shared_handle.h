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

#ifndef ARA_PER_SHARED_HANDLE_H_
#define ARA_PER_SHARED_HANDLE_H_

#include <memory>

///
/// @uptrace{SWS_PER_00002, fb49f277ba9a813303ba248e2a7970b903647cd7}
namespace ara
{
namespace per
{

/// @brief The shared handle is used to provide shared access to the Key-Value
/// Storage and File Storage
///
/// @uptrace{SWS_PER_00362, a8e4937a498ff53b477350b19c2ea907abc8bd3f}
///
/// Handle to a file storage or key-value storage. This is returned by the functions
/// OpenFileStorage() and OpenKeyValueStorage() and can be passed between threads as
/// needed. It provides the abstraction that is necessary to allow thead-safe
/// implementation of OpenFileStorage() and OpenKeyValueStorage().
template <typename T>
class SharedHandle final
{
public:
    explicit SharedHandle(std::shared_ptr<T> object)
        : object_(object)
    { }

    /// @brief Copy constructor for SharedHandle.
    ///
    /// @uptrace{SWS_PER_00369, cc1c259f87e2cc91a8f30d62523739f8e1352c5a}
    /// @threadsafety{tbd}
    /// @param[out] other The SharedHandle object to be copied.
    SharedHandle(const SharedHandle& other) = default;

    /// @brief Move constructor for SharedHandle. The source handle object is invalidated
    /// and cannot be used anymore. The operator bool() shall be used to check the state of
    /// a handle object before using any other operators of the handle object.
    ///
    /// @uptrace{SWS_PER_00367, 37a8cdeef0f0f93c6673e888d88b78de85974553}
    /// @threadsafety{tbd}
    /// @param[out] other The SharedHandle object to be moved.
    SharedHandle(SharedHandle&& other) = default;

    /// @brief Copy assignment operator for SharedHandle.
    ///
    /// @uptrace{SWS_PER_00370, 376b8f93f2a44131173f1118c3aa6b5dc331c8b3}
    /// @threadsafety{tbd}
    /// @param[out] other The copied SharedHandle object.
    SharedHandle& operator=(const SharedHandle& other) & = default;

    /// @brief Move assignment operator for SharedHandle. The source handle object is invalidated
    /// and cannot be used anymore. The operator bool() shall be used to check the state of
    /// a handle object before using any other operators of the handle object.
    ///
    /// @uptrace{SWS_PER_00368, 969844f0785f5d5cb665ea98db70320902882a72}
    /// @threadsafety{tbd}
    /// @param[out] other The moved SharedHandle object.
    SharedHandle& operator=(SharedHandle&& other) & = default;

    /// @brief Non-constant arrow operator.
    ///
    /// @uptrace{SWS_PER_00363, 6ef225f122f931829583385ee35de6114066acfe}
    /// @threadsafety{tbd}
    /// @returns T *
    T* operator->() noexcept
    {
        return object_.get();
    }

    /// @brief Constant arrow operator.
    ///
    /// @uptrace{SWS_PER_00364, 85e5fd3f9d945a76b795bc44bfa710d569266b6e}
    /// @threadsafety{tbd}
    /// @returns const T*
    const T* operator->() const noexcept
    {
        return object_.get();
    }

    /// @brief Non-constant dereference operator.
    ///
    /// @uptrace{SWS_PER_00402, 720e9002fcbb1f15e170744985d0b9cb64bfabe1}
    /// @threadsafety{re-entrant}
    /// @returns T &
    T& operator*() noexcept
    {
        return *object_.get();
    }

    /// @brief Constant dereference operator.
    ///
    /// @uptrace{SWS_PER_00403, f55faa569ac6d2ee3c13055a305b8efa72e41bc7}
    /// @threadsafety{re-entrant}
    /// @returns const T&
    const T& operator*() const noexcept
    {
        return *object_.get();
    }

    /// @brief Boolean operator. True if the handle represents a valid object of the templated class,
    /// False if the handle is empty (e.g. after a move operation). Using other operators than bool() of
    /// an empty handle will result in undefined behavior.
    ///
    /// @uptrace{SWS_PER_00398, 7d28f11072b627d399ad9b64c4410d079566ba0e}
    /// @threadsafety{re-entrant}
    explicit operator bool() const noexcept
    {
        return !!object_;
    }

private:
    /// @brief When a File Storage is closed, because all related ara::per::SharedHandles go out of scope, any files
    /// which are still open are also closed.
    ///
    /// @uptrace{SWS_PER_00425, b81415deaf9ae7331293316e3b4caf755cf879e4}
    std::shared_ptr<T> object_;
};

}  // namespace per
}  // namespace ara

#endif  // ARA_PER_SHARED_HANDLE_H_
