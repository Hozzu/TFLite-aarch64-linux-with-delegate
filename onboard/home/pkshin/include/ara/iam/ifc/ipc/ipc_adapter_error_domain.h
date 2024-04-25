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

/// @file
/// @brief Error domain for the ip error domain

#ifndef ARA_IAM_IFC_IPC_ERROR_DOMAIN_H_
#define ARA_IAM_IFC_IPC_ERROR_DOMAIN_H_

#include "ara/core/error_code.h"
#include "ara/core/error_domain.h"
#include "ara/core/exception.h"

namespace ara
{
namespace iam
{
namespace ifc
{
namespace ipc
{
/// @brief @brief Error cordes for the IPC communication
enum class IPCAdapterErrc : ara::core::ErrorDomain::CodeType
{
    kNoIpcConnection = 1,  ///< The IPC channel has not been established yet.
    kAccessError,  ///< The local IPC path could not be opened.
    kInvalidParameters,  ///< The provided parameters are malformed.
    kCommunicationError,  ///< Either the Access Manager or the client received invalid data.
    kTimeout,  ///< The given operation took too long.
    kEPIPE,  ///< Connected to a pipe with a closed receiving end
    kEWOULDBLOCK,  ///< The file descriptor fd refers to a socket and has been marked nonblocking (O_NONBLOCK), and the
                   ///< read would block
    kError  ///< Unspecified error
};

/// @brief Exception class
class IPCAdapterException : public ara::core::Exception
{
public:
    /// @brief Construct a new IPCAdapterException object
    ///
    /// @param err See ara::core::Exception
    IPCAdapterException(ara::core::ErrorCode&& err)
        : ara::core::Exception(std::move(err))
    { }
};

#if defined(__GNUC__)
#    pragma GCC diagnostic push
#    pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#endif

/// @brief Error domain for IPCAdapterErrc and IPCAdapterException
class IPCAdapterErrorDomain : public ara::core::ErrorDomain
{
    constexpr static ara::core::ErrorDomain::IdType kId = 0x8000000000000502;

public:
    using Errc = IPCAdapterErrc;  ///< Errc for this ErrorDomain
    using Exception = IPCAdapterException;  ///< Exception class for this ErrorDomain

    /// @brief Constructor
    constexpr IPCAdapterErrorDomain() noexcept
        : ara::core::ErrorDomain(kId)
    { }

    /// @brief See base class ara::core::ErrorDomain
    ///
    /// @return IPCAdapter
    char const* Name() const noexcept override
    {
        return "IPCAdapter";
    }

    /// @brief See base class ara::core::ErrorDomain
    ///
    /// @param errorCode CodeType
    /// @return Message
    char const* Message(ara::core::ErrorDomain::CodeType errorCode) const noexcept override
    {
        IPCAdapterErrc const code = static_cast<IPCAdapterErrc>(errorCode);
        switch (code) {
        case IPCAdapterErrc::kNoIpcConnection:
            return "NoIpcConnection";
        case IPCAdapterErrc::kAccessError:
            return "AccessError";
        case IPCAdapterErrc::kInvalidParameters:
            return "InvalidParameters";
        case IPCAdapterErrc::kCommunicationError:
            return "CommunicationError";
        case IPCAdapterErrc::kTimeout:
            return "Timeout";
        case IPCAdapterErrc::kEPIPE:
            return "EPIPE";
        case IPCAdapterErrc::kEWOULDBLOCK:
            return "EWOULDBLOCK";
        case IPCAdapterErrc::kError:
            return "Error";
        default:
            return "Unknown error";
        }
    }

    /// @brief See base class ara::core::ErrorDomain
    ///
    /// @param errorCode ErrorCode
    void ThrowAsException(ara::core::ErrorCode const& errorCode) const noexcept(false) override
    {
        ara::core::ifc::ThrowOrTerminate<IPCAdapterException>(errorCode);
    }
};

#if defined(__GNUC__)
#    pragma GCC diagnostic pop
#endif

namespace internal
{
constexpr IPCAdapterErrorDomain g_ipcAdapterErrorDomain;  ///< Member for IPCAdapterErrorDomain
}
/// @brief Obtain IPCAdapterErrorDomain
///
/// @return IPCAdapterErrorDomain
inline constexpr ara::core::ErrorDomain const& GetIPCAdapterErrorDomain()
{
    return internal::g_ipcAdapterErrorDomain;
}

/// @brief See base class
///
/// @param code IPCAdapterErrc
/// @param data SupportDataType
/// @return See ara::core::ErrorCode
inline constexpr ara::core::ErrorCode MakeErrorCode(IPCAdapterErrc code, ara::core::ErrorDomain::SupportDataType data)
{
    return ara::core::ErrorCode(static_cast<ara::core::ErrorDomain::CodeType>(code), GetIPCAdapterErrorDomain(), data);
}

}  // namespace ipc
}  // namespace ifc
}  // namespace iam
}  // namespace ara

#endif  // ARA_IAM_IFC_IPC_ERROR_DOMAIN_H_
