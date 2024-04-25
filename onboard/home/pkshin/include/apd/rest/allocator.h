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

#ifndef LIB_APDREST_INCLUDE_APD_REST_ALLOCATOR_H_
#define LIB_APDREST_INCLUDE_APD_REST_ALLOCATOR_H_

#include <atomic>
#include <cstddef>
#include <memory>
#include <new>
#include <type_traits>

namespace apd
{

namespace rest
{

/*

  apd::rest::Allocator is interface compatible with std::memory_resource which
  is a runtime polymorphic allocator concept newly added to C++17(!).

  Therefore, as long as our compiler is sufficiently new, just reusing the PMR (polymorphic memory
  region) stuff from C++ would be fine. For completeness, I added the bare minimum here that is
  needed to implement this on our own.

  For now, we only need to support Allocator in the component signatures.
  At some later point all internals will need to perform their allocations
  through this interface.

  Note that there exists std::polymorphic_allocator<> as an adapter which
  enables the use of a PMR allocators within standard containers that rely
  on std::allocator<> arguments. In apd::rest this adapter is called StdAllocator (see below).
  Note also that G/SetDefaultAllocator are also aliases for their std versions.

  Long story short, if std PMR is available we could just use type aliases here.

 */

/**
 * apd::rest::Allocator is interface compatible with std::memory_resource which
 * is a runtime polymorphic allocator concept added to C++17.
 *
 * All types related to apd::rest::Allocator are fully standard compliant
 *
 * If std::pmr is available these types may be simple type aliases.
 *
 */
class Allocator
{
public:
    /** \brief
     *
     *  Detailed description
     *
     */
    Allocator() = default;

    virtual ~Allocator();

    /** \brief Allocates a memory area
     *
     *  \param bytes desired size of the memory area to be allocated
     *  \param alignment alignment of the memory area
     *  \return a pointer to the allocated memory area
     */
    void* allocate(std::size_t bytes, std::size_t alignment = alignof(std::max_align_t));

    /** \brief Releases a memory area
     *
     *  \param p pointer to the allocated memory area
     *  \param bytes size of the allocated memory area
     *  \param alignment
     */
    void deallocate(void* p, std::size_t bytes, std::size_t alignment = alignof(std::max_align_t));

    /** \brief Tests whether two allocators are equal
     *
     *  Allocators are equal if memory allocated by one can be deallocated by the other.
     *
     *  \param alloc an allocator to compare against
     *  \return true if the two allocators compare equal
     */
    bool is_equal(const Allocator& alloc) const noexcept;

private:
    virtual void* do_allocate(std::size_t bytes, std::size_t alignment) = 0;
    virtual void do_deallocate(void* p, std::size_t bytes, std::size_t alignment = alignof(std::max_align_t)) = 0;
    virtual bool do_is_equal(const Allocator& other) const noexcept = 0;
};

namespace allocator
{

// put this in some cpp file; initialize to &NewDeleteAllocator
extern std::atomic<Allocator*> DefaultAllocator;

/**
 * needs documentation
 */
class NewDelete : public Allocator
{
public:
    NewDelete() = default;
    virtual ~NewDelete()
    { }

    /**
     * TODO
     *
     * \param size TODO
     * \param alignment TODO
     */
    void* do_allocate(std::size_t size, std::size_t alignment) override
    {
        return aligned_alloc(size, alignment);
    }

    /**
     * TODO
     *
     * \param p TODO
     */
    void do_deallocate(void* p, std::size_t /*bytes*/, std::size_t /*alignment*/ = alignof(std::max_align_t)) override
    {
        free(p);
    }

    /**
     * TODO
     *
     * \return TODO
     */
    bool do_is_equal(const Allocator&) const noexcept override
    {
        return true;
    }
};
}  // namespace allocator

static inline Allocator* GetDefaultAllocator() noexcept
{
    return allocator::DefaultAllocator;
}

/** \brief Adapter that turns an apd::rest::Allocator into a standard-compliant allocator
 *
 *  This adapter type enables application of apd::rest::Allocator in standard container types.
 *
 */
template <typename T>
class StdAllocator
{
public:
    using value_type = T;  ///< Type this allocator is bound to

    /** \brief Default constructs this allocator
     *  See std::pmr::polymorphic_allocator documentation for details
     *
     */
    StdAllocator() noexcept
        : alloc_(GetDefaultAllocator())
    { }

    /** \brief Default constructs this allocator
     *  See std::pmr::polymorphic_allocator documentation for details
     *
     * \param a TODO
     */
    explicit StdAllocator(Allocator* a) noexcept
        : alloc_(a)
    { }

    /**
     * This function exists only for the sake of 'noexcept'. never invoked directly.
     */
    template <typename U>
    StdAllocator(StdAllocator<U> const&) noexcept
    { }

    /** Allocate
     * See std::pmr::polymorphic_allocator documentation for details
     * \param n TODO
     *
     * \return TODO
     */
    value_type* allocate(std::size_t n)
    {
        return static_cast<value_type*>(alloc_->allocate(n, alignof(value_type)));
    }

    /** \brief Deallocate
     *
     *  See std::pmr::polymorphic_allocator documentation for details
     *
     * \param p TODO
     * \param s TODO
     */
    void deallocate(value_type* p, std::size_t s) noexcept
    {
        alloc_->deallocate(p, s, alignof(value_type));
    }

    /** \brief Returns the allocator to use when a standard container using it is copied.
     *
     *  See std::pmr::polymorphic_allocator documentation for details
     *  \return TODO
     */
    StdAllocator select_on_container_copy_construction() const;

    /** \brief Returns the Allocator behind this adapter
     *
     *  See std::pmr::polymorphic_allocator documentation for details
     * \return TODO
     */
    Allocator* resource() const noexcept;

private:
    Allocator* alloc_;
};

/** \brief Tests allocators for equality
 *
 */
template <typename T, typename U>
bool operator==(const StdAllocator<T>& a, const StdAllocator<U>& b) noexcept
{
    return a.is_equal(b);
}

/** \brief Tests allocators for inequality
 *
 */
template <typename T, typename U>
bool operator!=(StdAllocator<T> const& x, StdAllocator<U> const& y) noexcept
{
    return !(x == y);
}

// specialize for a type and its "domain class"
template <typename T, typename C>
struct SBOTraits
{
    static constexpr std::size_t BufferSize = 0;
};

}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_ALLOCATOR_H_
