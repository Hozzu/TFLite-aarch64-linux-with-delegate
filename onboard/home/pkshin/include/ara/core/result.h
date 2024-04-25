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

#ifndef APD_ARA_CORE_RESULT_H_
#define APD_ARA_CORE_RESULT_H_

#include "ara/core/error_code.h"
#include "ara/core/optional.h"
#include "ara/core/abort.h"

#include <utility>
#include <memory>
#include <type_traits>

namespace ara
{
namespace core
{

namespace internal
{

// This class holds the actual low-level union, and manage copying, moving, and destruction of it.
template <typename T,
    typename E,
    bool TrivialDestructor = std::is_trivially_destructible<T>::value&& std::is_trivially_destructible<E>::value>
struct ResultStorage final
{
    explicit ResultStorage(T const& t)
        : mValue(t)
        , mIsValue(true)
    { }

    explicit ResultStorage(T&& t)
        : mValue(std::move(t))
        , mIsValue(true)
    { }

    explicit ResultStorage(E const& e)
        : mError(e)
        , mIsValue(false)
    { }

    explicit ResultStorage(E&& e)
        : mError(std::move(e))
        , mIsValue(false)
    { }

    /// @uptrace{SWS_CORE_00725, 2aec6ead29a64379cb64ae193ea9b094ebec80fc}
    /// @uptrace{SWS_CORE_00825, 7d8536c0f57823be3ca7bfd4588884e1e6e54e64}
    ResultStorage(ResultStorage const& other)
        : mIsValue(other.mIsValue)
    {
        if (mIsValue) {
            new (&mValue) T(other.mValue);
        } else {
            new (&mError) E(other.mError);
        }
    }

    /// @uptrace{SWS_CORE_00726, da1100794add8649b79c16e66dae0e9445adb903}
    /// @uptrace{SWS_CORE_00826, 78efc70f2d884280bb063dc9f669164068ed90a9}
    ResultStorage(ResultStorage&& other) noexcept(
        std::is_nothrow_move_constructible<T>::value&& std::is_nothrow_move_constructible<E>::value)
        : mIsValue(other.mIsValue)
    {
        if (mIsValue) {
            new (&mValue) T(std::move(other.mValue));
        } else {
            new (&mError) E(std::move(other.mError));
        }
    }

    /// @uptrace{SWS_CORE_00741, 4e3235da1c8dd15fe570511a40254cd78b78c1c4}
    /// @uptrace{SWS_CORE_00841, 9c49383bda21dad24727949561569e713d2bb59a}
    ResultStorage& operator=(ResultStorage const& other)
    {
        if (mIsValue && other.mIsValue) {
            mValue = other.mValue;
        } else if (!mIsValue && !other.mIsValue) {
            mError = other.mError;
        } else {
            if (other.mIsValue) {
                mError.~E();
                new (&mValue) T(other.mValue);
                mIsValue = true;
            } else {
                mValue.~T();
                new (&mError) E(other.mError);
                mIsValue = false;
            }
        }
        return *this;
    }

    /// @uptrace{SWS_CORE_00742, 32fc1d9776c6283890714907e4b35707cb70e3fc}
    /// @uptrace{SWS_CORE_00842, 8317b7b51873df92752bb9bc25f1b24894695bc6}
    ResultStorage& operator=(ResultStorage&& other) noexcept(
        std::is_nothrow_move_constructible<T>::value&& std::is_nothrow_move_assignable<T>::value&&
            std::is_nothrow_move_constructible<E>::value&& std::is_nothrow_move_assignable<E>::value)
    {
        if (mIsValue && other.mIsValue) {
            mValue = std::move(other.mValue);
        } else if (!mIsValue && !other.mIsValue) {
            mError = std::move(other.mError);
        } else {
            if (other.mIsValue) {
                mError.~E();
                new (&mValue) T(std::move(other.mValue));
                mIsValue = true;
            } else {
                mValue.~T();
                new (&mError) E(std::move(other.mError));
                mIsValue = false;
            }
        }
        return *this;
    }

    /// @uptrace{SWS_CORE_00727}
    /// @uptrace{SWS_CORE_00827}
    ~ResultStorage()
    {
        if (mIsValue) {
            mValue.~T();
        } else {
            mError.~E();
        }
    }

    void Swap(ResultStorage& other) noexcept(
        std::is_nothrow_move_constructible<T>::value&& std::is_nothrow_move_assignable<T>::value&&
            std::is_nothrow_move_constructible<E>::value&& std::is_nothrow_move_assignable<E>::value)
    {
        using std::swap;

        if (mIsValue && other.mIsValue) {
            swap(mValue, other.mValue);
        } else if (!mIsValue && !other.mIsValue) {
            swap(mError, other.mError);
        } else {
            if (other.mIsValue) {
                E tmp(std::move(mError));
                mError.~E();
                new (&mValue) T(std::move(other.mValue));
                other.mValue.~T();
                new (&other.mError) E(std::move(tmp));
            } else {
                E tmp(std::move(other.mError));
                other.mError.~E();
                new (&other.mValue) T(std::move(mValue));
                mValue.~T();
                new (&mError) E(std::move(tmp));
            }
            swap(mIsValue, other.mIsValue);
        }
    }

    union
    {
        T mValue;
        E mError;
    };
    bool mIsValue;
};

template <typename T, typename E>
struct ResultStorage<T,
    E,
    true  // TrivialDestructor
    >
    final
{
    constexpr explicit ResultStorage(T const& t)
        : mValue(t)
        , mIsValue(true)
    { }

    constexpr explicit ResultStorage(T&& t)
        : mValue(std::move(t))
        , mIsValue(true)
    { }

    constexpr explicit ResultStorage(E const& e)
        : mError(e)
        , mIsValue(false)
    { }

    constexpr explicit ResultStorage(E&& e)
        : mError(std::move(e))
        , mIsValue(false)
    { }

    ResultStorage(ResultStorage const& other)
        : mIsValue(other.mIsValue)
    {
        if (mIsValue) {
            new (&mValue) T(other.mValue);
        } else {
            new (&mError) E(other.mError);
        }
    }

    ResultStorage(ResultStorage&& other) noexcept(
        std::is_nothrow_move_constructible<T>::value&& std::is_nothrow_move_constructible<E>::value)
        : mIsValue(other.mIsValue)
    {
        if (mIsValue) {
            new (&mValue) T(std::move(other.mValue));
        } else {
            new (&mError) E(std::move(other.mError));
        }
    }

    ResultStorage& operator=(ResultStorage const& other)
    {
        if (mIsValue && other.mIsValue) {
            mValue = other.mValue;
        } else if (!mIsValue && !other.mIsValue) {
            mError = other.mError;
        } else {
            if (other.mIsValue) {
                mError.~E();
                new (&mValue) T(other.mValue);
                mIsValue = true;
            } else {
                mValue.~T();
                new (&mError) E(other.mError);
                mIsValue = false;
            }
        }
        return *this;
    }

    ResultStorage& operator=(ResultStorage&& other) noexcept(
        std::is_nothrow_move_constructible<T>::value&& std::is_nothrow_move_assignable<T>::value&&
            std::is_nothrow_move_constructible<E>::value&& std::is_nothrow_move_assignable<E>::value)
    {
        if (mIsValue && other.mIsValue) {
            mValue = std::move(other.mValue);
        } else if (!mIsValue && !other.mIsValue) {
            mError = std::move(other.mError);
        } else {
            if (other.mIsValue) {
                mError.~E();
                new (&mValue) T(std::move(other.mValue));
                mIsValue = true;
            } else {
                mValue.~T();
                new (&mError) E(std::move(other.mError));
                mIsValue = false;
            }
        }
        return *this;
    }

    void Swap(ResultStorage& other) noexcept(
        std::is_nothrow_move_constructible<T>::value&& std::is_nothrow_move_assignable<T>::value&&
            std::is_nothrow_move_constructible<E>::value&& std::is_nothrow_move_assignable<E>::value)
    {
        using std::swap;

        if (mIsValue && other.mIsValue) {
            swap(mValue, other.mValue);
        } else if (!mIsValue && !other.mIsValue) {
            swap(mError, other.mError);
        } else {
            if (other.mIsValue) {
                E tmp(std::move(mError));
                mError.~E();
                new (&mValue) T(std::move(other.mValue));
                other.mValue.~T();
                new (&other.mError) E(std::move(tmp));
            } else {
                E tmp(std::move(other.mError));
                other.mError.~E();
                new (&other.mValue) T(std::move(mValue));
                mValue.~T();
                new (&mError) E(std::move(tmp));
            }
            swap(mIsValue, other.mIsValue);
        }
    }

    /// @uptrace{SWS_CORE_00727}
    /// @uptrace{SWS_CORE_00827}
    ~ResultStorage() = default;

    union
    {
        T mValue;
        E mError;
    };
    bool mIsValue;
};

}  // namespace internal

/// @uptrace{SWS_CORE_00701, c3c565d157d171356d1ca3ac19668065ecef9b6e}
template <typename T, typename E = ErrorCode>
class Result final
{
    internal::ResultStorage<T, E> mStorage;

    template <typename U, typename... Args>
    struct has_as_first_checker;

    template <typename U>
    struct has_as_first_checker<U> : std::false_type
    { };

    template <typename U, typename... Args>
    struct has_as_first_checker<U, U, Args...> : std::true_type
    { };

    template <typename U, typename A, typename... Args>
    struct has_as_first_checker<U, A, Args...> : std::false_type
    { };

    template <typename U, typename... Args>
    struct has_as_first
        : public has_as_first_checker<typename std::remove_reference<U>::type,
              typename std::remove_reference<Args>::type...>
    { };

public:
    /// @uptrace{SWS_CORE_00711, 461b680cf676d3b6cd0dda8aa26aff07c0198944}
    using value_type = T;

    /// @uptrace{SWS_CORE_00712, 5b53cc0389f3f6785a85c6288d7ed99eed0e8c8b}
    using error_type = E;

    /// @uptrace{SWS_CORE_00731, 90bbffe7fc7aa1caff5b789c73bcedc8cac1749b}
    static Result FromValue(const T& t)
    {
        return Result(t);
    }

    /// @uptrace{SWS_CORE_00732, 47322b8800c6b18f114ec1f24801fe1dc73e1a14}
    static Result FromValue(T&& t)
    {
        return Result(std::move(t));
    }

    /// @uptrace{SWS_CORE_00733, 675b28d919b02c4b76a04b453d14a52e5e0af3ee}
    template <typename... Args,
        typename = typename std::enable_if<true  //
            && std::is_constructible<T, Args&&...>::value  //
            && !has_as_first<T, Args...>::value  //
            && !has_as_first<Result, Args...>::value  //
            >::type  //
        >
    static Result FromValue(Args&&... args)
    {
        return Result(T{std::forward<Args>(args)...});
    }

    /// @uptrace{SWS_CORE_00734, cf170e35ada8605b64b4495aa91a583f8c6b9af9}
    static Result FromError(const E& e)
    {
        return Result(e);
    }

    /// @uptrace{SWS_CORE_00735, 4bce583952233ebe88606a0a5c556d4a983d2e2b}
    static Result FromError(E&& e)
    {
        return Result(std::move(e));
    }

    /// @uptrace{SWS_CORE_00736, 57117db5b320ab5f445e1fece52150574515c869}
    template <typename... Args,
        typename = typename std::enable_if<true  //
            && std::is_constructible<E, Args&&...>::value  //
            && !has_as_first<E, Args...>::value  //
            && !has_as_first<Result, Args...>::value  //
            >::type  //
        >
    static Result FromError(Args&&... args)
    {
        return Result(E{std::forward<Args>(args)...});
    }

    /// @uptrace{SWS_CORE_00721, 26a3aa666b61d97e7b4ab00725e04c5b70f88682}
    constexpr Result(const T& t)
        : mStorage(t)
    { }

    /// @uptrace{SWS_CORE_00722, 3163f66a1a2f64b8af15a26d2ed304db56ee427b}
    constexpr Result(T&& t)
        : mStorage(std::move(t))
    { }

    /// @uptrace{SWS_CORE_00723, d0c30828bac1c3b970267828af7fb6963f6c0853}
    constexpr explicit Result(const E& e)
        : mStorage(e)
    { }

    /// @uptrace{SWS_CORE_00724, 73b9553e372cdfd166662139ef138aa96e031485}
    constexpr explicit Result(E&& e)
        : mStorage(std::move(e))
    { }

    /// @uptrace{SWS_CORE_00743, 61b6da1418591755439139b87dba203797aa9166}
    template <typename... Args>
    void EmplaceValue(Args&&... args)
    {
        if (HasValue()) {
            mStorage.mValue.~T();
        } else {
            mStorage.mError.~E();
            mStorage.mIsValue = true;
        }
        new (&mStorage.mValue) T(std::forward<Args>(args)...);
    }

    /// @uptrace{SWS_CORE_00744, f136299e5a030fa95c4692aac922f7ce68d6e47a}
    template <typename... Args>
    void EmplaceError(Args&&... args)
    {
        if (HasValue()) {
            mStorage.mValue.~T();
            mStorage.mIsValue = false;
        } else {
            mStorage.mError.~E();
        }
        new (&mStorage.mError) E(std::forward<Args>(args)...);
    }

    /// @uptrace{SWS_CORE_00745, 239f7da9bd489c8cf00216da59ffee3dfbc5db71}
    void Swap(Result& other) noexcept(
        std::is_nothrow_move_constructible<T>::value&& std::is_nothrow_move_assignable<T>::value&&
            std::is_nothrow_move_constructible<E>::value&& std::is_nothrow_move_assignable<E>::value)
    {
        mStorage.Swap(other.mStorage);
    }

    /// @uptrace{SWS_CORE_00751, fe181707d13abb9c305a30f3fae5300dfe01c5fe}
    bool HasValue() const noexcept
    {
        return mStorage.mIsValue;
    }

    /// @uptrace{SWS_CORE_00752, 5aeb57145751640e54ea87f2fb4a552809763cc5}
    explicit operator bool() const noexcept
    {
        return HasValue();
    }

    /// @uptrace{SWS_CORE_00753, a8fe91c9a05023f53f6f2cf5e1e2cc530fa76eeb}
    const T& operator*() const&
    {
        return mStorage.mValue;
    }

    /// @uptrace{SWS_CORE_00759, 50ebc7e56af7bbf09402c2cfa1e30748322e8f30}
    T&& operator*() &&
    {
        return std::move(mStorage.mValue);
    }

    /// @uptrace{SWS_CORE_00754, cbfa0d2dff0966a4e1d4a57479df3a55ccb5bd64}
    const T* operator->() const
    {
        return std::addressof(mStorage.mValue);
    }

    /// @uptrace{SWS_CORE_00755, bc8f14c974fd047ae5730d0317326d794a889b5f}
    const T& Value() const&
    {
        if (mStorage.mIsValue)
            return mStorage.mValue;
        Abort("not a value");
    }

    /// @uptrace{SWS_CORE_00756, 9162fb223cf5cd15e4649fa7134ced5a4daddbda}
    T&& Value() &&
    {
        if (mStorage.mIsValue)
            return std::move(mStorage.mValue);
        Abort("not a value");
    }

    /// @uptrace{SWS_CORE_00757, 598ce730278f87551c351a6299d9c43c177cf0cd}
    const E& Error() const&
    {
        if (!mStorage.mIsValue)
            return mStorage.mError;
        Abort("not an error");
    }

    /// @uptrace{SWS_CORE_00758, 937893c14a25ab10867aad13e7463ea5e9acbcfd}
    E&& Error() &&
    {
        if (!mStorage.mIsValue)
            return std::move(mStorage.mError);
        Abort("not an error");
    }

    /// @uptrace{SWS_CORE_00770, f02fec4e2e16f867d9344a17d56684d9291022ee}
    Optional<T> Ok() const&
    {
        return HasValue() ? Optional<T>(Value()) : nullopt;
    }

    /// @uptrace{SWS_CORE_00771, 8abc9b734cd8b2063cb44283efc8ae76f22dbbbf}
    Optional<T> Ok() &&
    {
        return HasValue() ? Optional<T>(std::move(Value())) : nullopt;
    }

    /// @uptrace{SWS_CORE_00772, 6c41090d8d3b43d2ebbd2c8fce81291301c12f35}
    Optional<E> Err() const&
    {
        return HasValue() ? nullopt : Optional<E>(Error());
    }

    /// @uptrace{SWS_CORE_00773, 9508323ca5519a0552d2e02623ae610f0bec8680}
    Optional<E> Err() &&
    {
        return HasValue() ? nullopt : Optional<E>(std::move(Error()));
    }

    /// @uptrace{SWS_CORE_00761, adf213fee31ad9c7fe4acbc00d550bdced5de4e0}
    template <typename U>
    T ValueOr(U&& defaultValue) const&
    {
        return HasValue() ? Value() : static_cast<T>(std::forward<U>(defaultValue));
    }

    /// @uptrace{SWS_CORE_00762, 97effc300d32f1952a14a33bf837008d81962248}
    template <typename U>
    T ValueOr(U&& defaultValue) &&
    {
        return HasValue() ? std::move(Value()) : static_cast<T>(std::forward<U>(defaultValue));
    }

    /// @uptrace{SWS_CORE_00763, 9c660fc788cba6ecc9305a17be9204f1aa0d88fa}
    template <typename G>
    E ErrorOr(G&& defaultError) const&
    {
        return HasValue() ? static_cast<E>(std::forward<G>(defaultError)) : Error();
    }

    /// @uptrace{SWS_CORE_00764, 587fddb0b8c57035e35289e066e1492c659746e2}
    template <typename G>
    E ErrorOr(G&& defaultError) &&
    {
        return HasValue() ? static_cast<E>(std::forward<G>(defaultError)) : std::move(Error());
    }

    /// @uptrace{SWS_CORE_00765, 8f7e856509ee08fcba12d8426f0af57635f88dee}
    template <typename G>
    bool CheckError(G&& error) const
    {
        return HasValue() ? false : (Error() == static_cast<E>(std::forward<G>(error)));
    }

#ifndef ARA_NO_EXCEPTIONS
    /// @uptrace{SWS_CORE_00766, 9fdd1bcdd259b5641a508cccf305ab8eb528730e}
    const T& ValueOrThrow() const& noexcept(false)
    {
        if (HasValue())
            return Value();
        Error().ThrowAsException();
    }

    /// @uptrace{SWS_CORE_00769, f8ae1998acb604486ab80776641721ab33a3e87f}
    T&& ValueOrThrow() && noexcept(false)
    {
        if (HasValue())
            return std::move(mStorage.mValue);
        Error().ThrowAsException();
    }
#endif

    /// @uptrace{SWS_CORE_00767, 27712b34151287405fdb1714847400f86137444a}
    template <typename F>
    T Resolve(F&& f) const
    {
        return HasValue() ? Value() : std::forward<F>(f)(Error());
    }

private:
    /// @brief Trait that detects whether a type is a Result<...>
    template <typename U>
    struct is_result : std::false_type
    { };

    template <typename U, typename G>
    struct is_result<Result<U, G>> : std::true_type
    { };

    template <typename F>
    using CallableReturnsResult = std::enable_if_t<is_result<std::result_of_t<F(T const&)>>::value>;

    template <typename F>
    using CallableReturnsNoResult = std::enable_if_t<!is_result<std::result_of_t<F(T const&)>>::value>;

public:
    /// @uptrace{SWS_CORE_00768, fd07c0e93a238ad8b662d20ca4f1fc3879e9aa81}
    template <typename F, typename = CallableReturnsResult<F>>
    auto Bind(F&& f) const -> decltype(f(Value()))
    {
        using U = decltype(f(Value()));
        return HasValue() ? std::forward<F>(f)(Value()) : U(Error());
    }

    /// @uptrace{SWS_CORE_00768, fd07c0e93a238ad8b662d20ca4f1fc3879e9aa81}
    template <typename F, typename = CallableReturnsNoResult<F>>
    auto Bind(F&& f) const -> Result<decltype(f(Value())), E>
    {
        using U = decltype(f(Value()));
        using R = Result<U, E>;
        return HasValue() ? std::forward<F>(f)(Value()) : R(Error());
    }

    template <typename, typename>
    friend class Result;
};

/// @uptrace{SWS_CORE_00801, a8f1589336fce52b742c4410760bbb2a981ca69a}
template <typename E>
class Result<void, E> final
{
    struct Dummy
    { };

    using T = Dummy;

    internal::ResultStorage<Dummy, E> mStorage;

public:
    /// @uptrace{SWS_CORE_00811, 6c5f3522bd67251c6bba2d574629dd02d9915de6}
    using value_type = void;

    /// @uptrace{SWS_CORE_00812, 5705bf4a3b655aeda62dac7c3c0d0f16856fa566}
    using error_type = E;

    /// @uptrace{SWS_CORE_00831, 090d373a2a7040939d0b85276d960538d65f1e36}
    static Result FromValue() noexcept
    {
        return Result();
    }

    /// @uptrace{SWS_CORE_00834, feb1b265d7ffb84eae631a6aa14d29bf2bd2130c}
    static Result FromError(const E& e)
    {
        return Result(e);
    }

    /// @uptrace{SWS_CORE_00835, 5cafc5446ffe88815aa658e36387c50f91a39331}
    static Result FromError(E&& e)
    {
        return Result(std::move(e));
    }

    /// @uptrace{SWS_CORE_00836, 47b9d83ffa7194a98ca9f09b7d30f6373cdcc9aa}
    template <typename... Args>
    static Result FromError(Args&&... args)
    {
        return Result(E{std::forward<Args>(args)...});
    }

    /// @uptrace{SWS_CORE_00821, 8a876d6de01012f4f8abeb6519184e824fa404b3}
    Result() noexcept
        : mStorage(Dummy{})
    { }

    /// @uptrace{SWS_CORE_00823, 8363b2769c7a049e27b15817c573085a6844ed43}
    explicit Result(const E& e)
        : mStorage(e)
    { }

    /// @uptrace{SWS_CORE_00824, c301de76486f2ca4fb4d7998872f46814937715b}
    explicit Result(E&& e)
        : mStorage(std::move(e))
    { }

    /// @uptrace{SWS_CORE_00843, d0754b0b1f1af965514227fe48f3486e647c6671}
    template <typename... Args>
    void EmplaceValue(Args&&... args) noexcept
    {
        if (HasValue()) {
            mStorage.mValue.~T();
        } else {
            mStorage.mError.~E();
            mStorage.mIsValue = true;
        }
        new (&mStorage.mValue) T(std::forward<Args>(args)...);
    }

    /// @uptrace{SWS_CORE_00844, 3e130879d80c8d1e447129898db7de8840d7a97b}
    template <typename... Args>
    void EmplaceError(Args&&... args)
    {
        if (HasValue()) {
            mStorage.mValue.~T();
            mStorage.mIsValue = false;
        } else {
            mStorage.mError.~E();
        }
        new (&mStorage.mError) E(std::forward<Args>(args)...);
    }

    /// @uptrace{SWS_CORE_00845, 03161ae3e8967a4aa3f91483960e7c99e8485241}
    void Swap(Result& other) noexcept(
        std::is_nothrow_move_constructible<E>::value&& std::is_nothrow_move_assignable<E>::value)
    {
        mStorage.Swap(other.mStorage);
    }

    /// @uptrace{SWS_CORE_00851, 7049ed0a8ab8ae5c265bdd6c6a3381e95bffd0de}
    bool HasValue() const noexcept
    {
        return mStorage.mIsValue;
    }

    /// @uptrace{SWS_CORE_00852, da678ab72b84065d63cb595e8a2e8c8971e46eac}
    explicit operator bool() const noexcept
    {
        return HasValue();
    }

    /// @uptrace{SWS_CORE_00853, ed9a4216de5d14c9e900d106345c6e611075d0ab}
    void operator*() const
    {
        return;
    }

    /// @uptrace{SWS_CORE_00855, 110b82eada3dc19ea6abf7a0fb21e37312a4e6af}
    void Value() const
    {
        if (!mStorage.mIsValue) {
            Abort("not a value");
        }
    }

    /// @uptrace{SWS_CORE_00857, c4496a201b8526579f58c1301b93c58af44b04d1}
    const E& Error() const&
    {
        if (!mStorage.mIsValue)
            return mStorage.mError;
        Abort("not an error");
    }

    /// @uptrace{SWS_CORE_00858, f9d2630536a21db22cca3278e5cc3b8d9f110f2d}
    E&& Error() &&
    {
        if (!mStorage.mIsValue)
            return std::move(mStorage.mError);
        Abort("not an error");
    }

    /// @uptrace{SWS_CORE_00868, a1f72d8d6149285eab2e00102be27af5eece42a9}
    Optional<E> Err() const&
    {
        return HasValue() ? nullopt : Optional<E>(Error());
    }

    /// @uptrace{SWS_CORE_00869, dda908358d2370c65732357f1643712d6c5b51e2}
    Optional<E> Err() &&
    {
        return HasValue() ? nullopt : Optional<E>(std::move(Error()));
    }

    /// @uptrace{SWS_CORE_00861, 89d7328b246f0bcf4c01ecb4c101c804ab1ac372}
    template <typename U>
    void ValueOr(U&& defaultValue) const
    {
        return HasValue() ? Value() : static_cast<void>(std::forward<U>(defaultValue));
    }

    /// @uptrace{SWS_CORE_00863, b0aa22be1a8b882795ba0dc5c250a3e670367b6a}
    template <typename G>
    E ErrorOr(G&& defaultError) const&
    {
        return HasValue() ? static_cast<E>(std::forward<G>(defaultError)) : Error();
    }

    /// @uptrace{SWS_CORE_00864, d7b5facdccfef8f21d6973908ebdcc31e8e520a3}
    template <typename G>
    E ErrorOr(G&& defaultError) &&
    {
        return HasValue() ? static_cast<E>(std::forward<G>(defaultError)) : std::move(Error());
    }

    /// @uptrace{SWS_CORE_00865, 74fb59535fa8389fd971909dc4be4f0060eaa6b3}
    template <typename G>
    bool CheckError(G&& error) const
    {
        return HasValue() ? false : (Error() == static_cast<E>(std::forward<G>(error)));
    }

#ifndef ARA_NO_EXCEPTIONS
    /// @uptrace{SWS_CORE_00866, ce4b6afb5d664f16189a50adf3eb3c68456c7ce6}
    void ValueOrThrow() const noexcept(false)
    {
        if (!HasValue()) {
            Error().ThrowAsException();
        }
    }
#endif

    /// @uptrace{SWS_CORE_00867, 2b6ac3135a3cbdac9590f3281cd9b8f5d58c39a5}
    template <typename F>
    void Resolve(F&& f) const
    {
        return HasValue() ? Value() : std::forward<F>(f)(Error());
    }

private:
    /// @brief Trait that detects whether a type is a Result<...>
    template <typename U>
    struct is_result : std::false_type
    { };

    template <typename U, typename G>
    struct is_result<Result<U, G>> : std::true_type
    { };

    template <typename F>
    using CallableReturnsResult = std::enable_if_t<is_result<std::result_of_t<F()>>::value>;

    template <typename F>
    using CallableReturnsNoResult = std::enable_if_t<!is_result<std::result_of_t<F()>>::value>;

public:
    /// @uptrace{SWS_CORE_00870, 5548358e3ba4d3a73f7f0c94437ee47d0a214185}
    template <typename F, typename = CallableReturnsResult<F>>
    auto Bind(F&& f) const -> decltype(f())
    {
        using U = decltype(f());
        return HasValue() ? std::forward<F>(f)() : U(Error());
    }

    /// @uptrace{SWS_CORE_00870, 5548358e3ba4d3a73f7f0c94437ee47d0a214185}
    template <typename F, typename = CallableReturnsNoResult<F>>
    auto Bind(F&& f) const -> Result<decltype(f()), E>
    {
        using U = decltype(f());
        using R = Result<U, E>;
        return HasValue() ? std::forward<F>(f)() : R(Error());
    }

    template <typename, typename>
    friend class Result;
};

/// @uptrace{SWS_CORE_00796, cf1e4568c3a060c46368b93c41d6cc7ca7f6b4e2}
template <typename T, typename E>
void swap(Result<T, E>& lhs, Result<T, E>& rhs) noexcept(noexcept(lhs.Swap(rhs)))
{
    lhs.Swap(rhs);
}

// Compare two Result instances

/// @uptrace{SWS_CORE_00780, 05c99ca70fb2f8a6356925e46c32359b774c967f}
template <typename T, typename E>
bool operator==(const Result<T, E>& lhs, const Result<T, E>& rhs)
{
    if (bool(lhs) != bool(rhs))
        return false;
    if (lhs)
        return lhs.Value() == rhs.Value();
    return lhs.Error() == rhs.Error();
}

/// @uptrace{SWS_CORE_00781, 3b51c594eee504852f019491cb70e2d409893323}
template <typename T, typename E>
bool operator!=(const Result<T, E>& lhs, const Result<T, E>& rhs)
{
    if (bool(lhs) != bool(rhs))
        return true;
    if (lhs)
        return lhs.Value() != rhs.Value();
    return lhs.Error() != rhs.Error();
}

// Compare Result with a T

/// @uptrace{SWS_CORE_00782, e6390e7b58295924ae69578ec33c0868083bce86}
template <typename T, typename E>
bool operator==(const Result<T, E>& lhs, const T& rhs)
{
    return lhs ? *lhs == rhs : false;
}

/// @uptrace{SWS_CORE_00783, c08cf4188c55f082f5c181246b46c2778e7b9967}
template <typename T, typename E>
bool operator==(const T& lhs, const Result<T, E>& rhs)
{
    return rhs ? lhs == *rhs : false;
}

/// @uptrace{SWS_CORE_00784, 9756f2d6d3918a1c55240917b1a57cbc57d36fdd}
template <typename T, typename E>
bool operator!=(const Result<T, E>& lhs, const T& rhs)
{
    return lhs ? *lhs != rhs : true;
}

/// @uptrace{SWS_CORE_00785, 4c630e8f345b7330c6a8391d601a943453edf4d6}
template <typename T, typename E>
bool operator!=(const T& lhs, const Result<T, E>& rhs)
{
    return rhs ? lhs != *rhs : true;
}

// Compare Result with an E

/// @uptrace{SWS_CORE_00786, 652d2e072053f9487385b01b3085abddaec40bc3}
template <typename T, typename E>
bool operator==(const Result<T, E>& lhs, const E& rhs)
{
    return lhs ? false : lhs.Error() == rhs;
}

/// @uptrace{SWS_CORE_00787, 9924187feba5aaf034bd4a609400121baeca1015}
template <typename T, typename E>
bool operator==(const E& lhs, const Result<T, E>& rhs)
{
    return rhs ? false : lhs == rhs.Error();
}

/// @uptrace{SWS_CORE_00788, 48f41e5f81be77e217b7a9a2cdf6b59beca16f64}
template <typename T, typename E>
bool operator!=(const Result<T, E>& lhs, const E& rhs)
{
    return lhs ? true : lhs.Error() != rhs;
}

/// @uptrace{SWS_CORE_00789, 5a8cede4b67a71bdf93f40b6c78dcd049eb737b8}
template <typename T, typename E>
bool operator!=(const E& lhs, const Result<T, E>& rhs)
{
    return rhs ? true : lhs != rhs.Error();
}

}  // namespace core
}  // namespace ara

#endif  // APD_ARA_CORE_RESULT_H_
