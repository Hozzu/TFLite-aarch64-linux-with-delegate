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

#ifndef LIB_APDREST_INCLUDE_APD_REST_HEADER_H_
#define LIB_APDREST_INCLUDE_APD_REST_HEADER_H_

#include "apd/rest/endpoint.h"
#include "apd/rest/types.h"
#include "apd/rest/uri.h"
#include "ara/core/map.h"

namespace apd
{
namespace rest
{

/** \brief Iterator range of header fields
 *
 *  \uptrace{SWS_REST_02515}
 */
using FieldIteratorRange = IteratorRange<ara::core::Map<StringView, StringView>::iterator>;
/** \brief Const iterator range of header fields
 *
 *  \uptrace{SWS_REST_02516}
 */
using ConstFieldIteratorRange = IteratorRange<ara::core::Map<StringView, StringView>::const_iterator>;

class Header
{
public:
    /**
     * Default CTOR
     */
    Header() = default;
    /**
     * Constructor
     * \param uri
     */
    Header(Uri uri);
    /**
     * Constructor
     * \param status
     * \param uri
     */
    Header(int status, Uri uri);
    /** \brief Returns a Uri
     *
     *  It is binding-specific how Uri map to the transport protocol format.
     *
     *  \return a Uri
     *  \uptrace{SWS_REST_02167}
     *  \uptrace{SWS_REST_02178}
     */
    const Uri& GetUri() const noexcept;
    /** \brief Allows to set a Uri
     *
     *  It is binding-specific how Uri map to the transport protocol format.
     *  \param uri a Uri
     *  \uptrace{SWS_REST_02168}
     *  \uptrace{SWS_REST_02179}
     */
    void SetUri(const Uri& uri);
    /** \brief Allows to set a Uri
     *
     *  It is binding-specific how Uri map to the transport protocol format.
     *  Same as before, just with move semantics
     *  \param uri a Uri
     */
    void SetUri(Uri&& uri);
    /** \brief Returns the current message status code
     *
     *  Status codes are binding-specific
     *
     *  \return a status code
     *  \uptrace{SWS_REST_02165}
     *  \uptrace{SWS_REST_02507}
     */
    int GetStatus() const noexcept;
    /** \brief Sets a message status code
     *
     *  Status codes are binding-specific
     *
     *  \param code an integral status code
     *  \uptrace{SWS_REST_02166}
     *  \uptrace{SWS_REST_02508}
     */
    void SetStatus(int code) noexcept;
    /** \brief Denotes whether a field exists
     *
     *  \param key the key of the field
     *  \return true if the field exist
     *  \uptrace{SWS_REST_02489}
     *  \uptrace{SWS_REST_02498}
     */
    bool HasField(const StringView& key) const;
    /** \brief Inserts a field if it does not exist
     *
     *  \param key key of the field
     *  \param value value of the field
     *  \return true if a new field has been inserted
     *  \uptrace{SWS_REST_02490}
     *  \uptrace{SWS_REST_02499}
     */
    bool InsertField(const StringView& key, const StringView& value);
    /** \brief Erases a field from the header
     *
     *  \param key key of the field to be erased
     *  \return true if field has been erased otherwise false
     *  \uptrace{SWS_REST_02492}
     *  \uptrace{SWS_REST_02501}
     */
    bool EraseField(const StringView& key) noexcept;
    /** \brief Accesses a field value
     *
     *  \param key key of the field to be accessed
     *  \return Value of the field
     *  \uptrace{SWS_REST_02493}
     *  \uptrace{SWS_REST_02502}
     */
    StringView GetField(const StringView& key) const;
    /** \brief Sets a fields value. If field does not exist, it is inserted.
     *
     *  \param key key of the field to be set
     *  \param value value of the field to be set
     *  \uptrace{SWS_REST_02494}
     *  \uptrace{SWS_REST_02503}
     */
    void SetField(const StringView& key, const StringView& value) noexcept;
    /** \brief Returns the number of fields in this header
     *
     *  \return the number of fields
     *  \uptrace{SWS_REST_02496}
     *  \uptrace{SWS_REST_02505}
     */
    std::size_t NumFields() const noexcept;
    /** \brief Erases all fields in this header
     *
     *  \uptrace{SWS_REST_02497}
     *  \uptrace{SWS_REST_02506}
     */
    void ClearFields() noexcept;
    /** \brief Returns an iterator to a field
     *
     *  \param key key of the field to be found
     *  \return an iterator to field
     *  \uptrace{SWS_REST_02517}
     *  \uptrace{SWS_REST_02511}
     */
    FieldIteratorRange FindField(StringView key) noexcept;
    /** \brief Returns an iterator to a field
     *
     *  \param key key of the field to be found
     *  \return an iterator to field
     *  \uptrace{SWS_REST_02518}
     *  \uptrace{SWS_REST_02512}
     */
    ConstFieldIteratorRange FindField(StringView key) const noexcept;
    /** \brief Returns a range of header fields
     *
     *  \return an IteratorRange of header fields
     *  \uptrace{SWS_REST_02519}
     *  \uptrace{SWS_REST_02513}
     */
    FieldIteratorRange GetFields() noexcept;
    /** \brief Returns a range of header fields
     *
     *  \return an IteratorRange of header fields
     *  \uptrace{SWS_REST_02520}
     *  \uptrace{SWS_REST_02514}
     */
    ConstFieldIteratorRange GetFields() const noexcept;

protected:
    /**
     * StatusCode for the header
     */
    int status_;
    /**
     * Member to save the Uri
     */
    Uri uri_;
    /**
     * Fields for the Request
     */
    ara::core::Map<StringView, StringView> fields_;
};

/** \brief Represents the message header of a request
 *
 *  Request header is used in both client and server messages.
 *  \uptrace{SWS_REST_02175}
 */
class RequestHeader : public Header
{
public:
    /**
     * Default CTOR
     */
    RequestHeader() = default;
    /**
     * Constructor
     * \param request_method
     * \param uri
     */
    RequestHeader(RequestMethod request_method, Uri uri);

    /** \brief Returns the request method
     *
     *  \return a request method
     *  \uptrace{SWS_REST_02176}
     */
    RequestMethod GetMethod() const noexcept;
    /** \brief Allows to set the request method
     *
     *  \param met a RequestMethod
     *  \uptrace{SWS_REST_02177}
     */
    void SetMethod(RequestMethod met);

private:
    /**
     * Member to save the RequestMethod
     */
    RequestMethod request_method_;
};

/** \brief Represents the message header of a reply
 *
 *  Reply header is used in both client and server messages.
 * \uptrace{SWS_REST_02164}
 */
class ReplyHeader : public Header
{
public:
    /**
     * Default CTOR
     */
    ReplyHeader() = default;
    /**
     * Constructor
     * \param status
     * \param uri
     */
    ReplyHeader(int status, Uri uri);

private:
};

}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_HEADER_H_
