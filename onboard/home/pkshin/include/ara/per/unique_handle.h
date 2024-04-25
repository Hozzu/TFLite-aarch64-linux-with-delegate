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

#ifndef ARA_PER_UNIQUE_HANDLE_H_
#define ARA_PER_UNIQUE_HANDLE_H_

#include <memory>

///
/// @uptrace{SWS_PER_00002, fb49f277ba9a813303ba248e2a7970b903647cd7}
namespace ara
{
namespace per
{

/// @brief The unique handle is used to provide non-shared access to
//
/// @uptrace{SWS_PER_00359, 31d2879048747da3e731c31e3b10aecd235438b0}
/// ReadAccessors and ReadWriteAccessors of the File Storage.
///
/// Handle to a ReadAccessor or ReadWriteAccessor. This is returned by the
/// functions OpenFileReadOnly(), OpenFileReadWrite(), and OpenFileReadWrite().
template <typename T>
class UniqueHandle final
{
public:
    explicit UniqueHandle(std::unique_ptr<T>&& object)
        : object_(std::move(object))
    { }

    /// @brief The copy constructor for UniqueHandle shall not be used.
    ///
    /// @uptrace{SWS_PER_00373, 48f615eca35f39b83b255e1a6d68f16c132e634f}
    /// @threadsafety{tbd}
    UniqueHandle(const UniqueHandle& other) = delete;

    /// @brief Move constructor for UniqueHandle. The source handle object is invalidated
    /// and cannot be used anymore. The operator bool() shall be used to check the state of
    /// a handle object before using any other operators of the handle object.
    ///
    /// @uptrace{SWS_PER_00371, 8c90d96015528a2e82f87cc6eaceaf7dcd2d002b}
    /// @threadsafety{tbd}
    /// @param[out] other The UniqueHandle object to be moved.
    UniqueHandle(UniqueHandle&& other) = default;

    /// @brief The copy assignment operator for UniqueHandle shall not be used.
    ///
    /// @uptrace{SWS_PER_00374, 25a28e7f916acab0d80460eef888dd32d0dee043}
    /// @threadsafety{tbd}
    UniqueHandle& operator=(const UniqueHandle& other) = delete;

    /// @brief Move assignment operator for UniqueHandle. The source handle object is invalidated
    /// and cannot be used anymore. The operator bool() shall be used to check the state of
    /// a handle object before using any other operators of the handle object.
    ///
    /// @uptrace{SWS_PER_00372, 0b27e298d8794f06177dccfe93dc29d2f7508e58}
    /// @threadsafety{tbd}
    /// @param[out] other The moved UniqueHandle object.
    UniqueHandle& operator=(UniqueHandle&& other) & = default;

    /// @brief Non-constant arrow operator.
    ///
    /// @uptrace{SWS_PER_00360, 5d2332c5e1b6d366bc15e87c627c6dce780b0e22}
    /// @threadsafety{tbd}
    /// @returns T *
    T* operator->() noexcept
    {
        return object_.get();
    }

    /// @brief Constant arrow operator.
    ///
    /// @uptrace{SWS_PER_00361, 6a5ff56d8d3115cdff911472c8ca85bf514f1e73}
    /// @threadsafety{tbd}
    /// @returns const T*
    const T* operator->() const noexcept
    {
        return object_.get();
    }

    /// @brief Non-constant dereference operator.
    ///
    /// @uptrace{SWS_PER_00400, 01d9d5cd98bbec13ecc10f9f7ad054e533f658c7}
    /// @threadsafety{tbd}
    /// @returns T &
    T& operator*() noexcept
    {
        return *object_.get();
    }

    /// @brief Constant dereference operator.
    ///
    /// @uptrace{SWS_PER_00401, ea3e22b23d973afa19e733ff902f3d239b4048ab}
    /// @threadsafety{tbd}
    /// @returns const T&
    const T& operator*() const noexcept
    {
        return *object_.get();
    }

    /// @brief Boolean operator. True if the handle represents a valid object of the templated class,
    /// False if the handle is empty (e.g. after a move operation). Using other operators than bool() of
    /// an empty handle will result in undefined behavior.
    ///
    /// @uptrace{SWS_PER_00399, 173b7741ed14df8f8e6430a3d788ca181a9f80f0}
    /// @threadsafety{re-entrant}
    explicit operator bool() const noexcept
    {
        return !!object_;
    }

private:
    std::unique_ptr<T> object_;
};

}  // namespace per
}  // namespace ara

#endif  // ARA_PER_UNIQUE_HANDLE_H_
