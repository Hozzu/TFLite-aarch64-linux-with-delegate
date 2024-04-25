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

/**
 * \file
 */

#ifndef ARA_COM_SKELETON_DISPATCHER_BASE_H
#define ARA_COM_SKELETON_DISPATCHER_BASE_H
#include <list>
#include <mutex>

namespace ara
{
namespace com
{
namespace internal
{
namespace skeleton
{

/**
 * \addtogroup frontendskeletonbase
 *
 * @{
 */

/**
 * \brief Base class for all dispatchers on server side.
 *
 * A dispatcher distributes method calls to all of its clients aka delegates. This base class provides functions to add
 * and remove delegates.
 */
template <typename T>
class DispatcherBase
{
public:
    /**
     * \brief Adds a delegate. The given delegate must outlive the dispatcher.
     *
     * \param delegate Delegate to add
     */
    void AddDelegate(T& delegate)
    {
        std::lock_guard<std::mutex> lock(delegates_mutex_);
        delegates_.push_back(&delegate);
    }
    /**
     * Removes a delegate.
     *
     * The function does nothing if the deleate wasn't added before.
     *
     * \param delegate Delegate to remove.
     */
    void RemoveDelegate(T& delegate)
    {
        std::lock_guard<std::mutex> lock(delegates_mutex_);
        delegates_.remove(&delegate);
    }

protected:
    std::list<T*> delegates_;  ///< Hold the list of registered delegates.
    std::mutex delegates_mutex_;
};

/**
 * @{
 */

}  // namespace skeleton
}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // ARA_COM_SKELETON_DISPATCHER_BASE_H
