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

#ifndef LIB_APDREST_INCLUDE_APD_REST_URI_H_
#define LIB_APDREST_INCLUDE_APD_REST_URI_H_

#include <cstddef>
#include <cstring>
#include <limits>
#include <memory>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>

#include "apd/rest/allocator.h"
#include "apd/rest/cpp14_backport.h"
#include "apd/rest/exception.h"
#include "apd/rest/iterator.h"
#include "apd/rest/string.h"
#include "apd/rest/types.h"

namespace apd
{

namespace rest
{

/** \brief Uri is a generic URI container compliant to RFC 3986
 *
 * Uri is immutable and does not throw (unless StringView throws). A new Uri can be constructed via
 * Uri::Builder from an empty Uri or an existing one. No member access to Uri causes dynamic memory
 * allocation. This includes the copy- and copy-assignment constructors too.
 *
 * Uri is not allowed to perform any kind of dynamic memory allocation.
 *
 * For conversion into textual representations of URI components, accessor functions accept a
 * template argument T that specified the type conversion. Type T must must be "InputStreamable"
 * which means that an operator>>() must be defined that takes a std::istream object on the left
 * hand side and an instance of the result type on the right.
 *
 * A URI is always non-percent-encoded. When parsed percent-encoded charaters are replaced.
 * Accordingly, Uri comparison is also only performed in non-encoded representations.
 * Percent-encoding applied by ToString() only. All member functions that perform string
 * conversion  return non-percent-encoded representations.
 *
 * Uri must be efficiently movable.
 * \uptrace{SWS_REST_02307}
 */
class Uri
{
public:
    /**
     * \brief The maximum length of a URI.
     *
     * The suggested length maximum is around 2000 characters which roughly conforms to the
     * typical limit that mainstream webbrowsers support. A bound is specified to enable
     * optimization potential in the internal encoding.
     * \uptrace{SWS_REST_02309}
     */
    static constexpr std::size_t LENGTH_MAX = 2048;  // 10 bits will do

    /**
     * \brief Return value of Uri::GetPort() when no port is found
     */
    static constexpr char PORT_NOT_FOUND = -1;

    /** \brief Used to specify a subset of a URI.
     *
     * Part defines components of a Uri. This is typically used to convert Uri into a texttual
     * representation.
     * \uptrace{SWS_REST_02308}
     */
    enum class Part : std::uint32_t
    {
        Scheme = 1 << 1,  ///< Denotes URI scheme according to RFC 3986
        UserInfo = 1 << 2,  ///< Denotes URI user info according to RFC 3986
        Host = 1 << 3,  ///< Denotes URI authority host according to RFC 3986
        Port = 1 << 4,  ///< Denotes URI authority port according to RFC 3986
        Path = 1 << 5,  ///< Denotes URI path according to RFC 3986
        Query = 1 << 6,  ///< Denotes URI query according to RFC 3986
        Fragment = 1 << 7,  ///< Denotes URI fragment according to RFC 3986
        PathAndQuery = Part::Path | Part::Query,  ///< Denotes URI path and query
        PathEtc = Part::Path | Part::Query | Part::Fragment,  ///< Dentes URI path, query and fragment
        All = ~std::underlying_type<Part>::type{0}  ///< Denotes all known URI components
    };

    /** \brief Computes a set of Part enumerators
     *  \param a
     *  \param b
     *  \uptrace{SWS_REST_02310}
     */
    friend constexpr Part operator|(Part a, Part b) noexcept
    {
        using T = std::underlying_type<Part>::type;
        return static_cast<Part>(static_cast<T>(a) | static_cast<T>(b));
    }

    /** \brief Composes Part enumerators
     *  \param a
     *  \param b
     */
    friend constexpr Part operator&(Part a, Part b) noexcept
    {
        using T = std::underlying_type<Part>::type;
        return static_cast<Part>(static_cast<T>(a) & static_cast<T>(b));
    }

    class Builder;

    /**
     * \brief Constructor
     */
    explicit Uri(Allocator* = GetDefaultAllocator());

    /**
     * \brief Copy constructor
     */
    Uri(const Uri& other) noexcept;

    /**
     * \brief Move constructor
     */
    Uri(Uri&& other) noexcept;

    /**
     * \brief Copy assignment operator
     */
    Uri& operator=(Uri& other) noexcept;

    /**
     * \brief Move assignment operator
     */
    Uri& operator=(Uri&& other) noexcept;

    // parse string
    /**
     * \brief Constructor with parameter.
     */
    explicit Uri(const StringView&, Allocator* = GetDefaultAllocator());

    /**
     * \brief Has scheme.
     * \uptrace{SWS_REST_02312}
     */
    bool HasScheme() const noexcept;

    /**
     * \brief gets scheme.
     * \uptrace{SWS_REST_02313}
     */
    StringView GetScheme() const noexcept(std::is_nothrow_constructible<StringView>::value);

    /**
     * \brief has user info.
     * \uptrace{SWS_REST_02314}
     */
    bool HasUserInfo() const noexcept;

    /**
     * \brief get user info.
     * \uptrace{SWS_REST_02315}
     */
    StringView GetUserinfo() const noexcept(std::is_nothrow_constructible<StringView>::value);

    /**
     * \brief has host.
     * \uptrace{SWS_REST_02316}
     */
    bool HasHost() const noexcept;

    /**
     * \brief get host.
     * \uptrace{SWS_REST_02317}
     */
    StringView GetHost() const noexcept(std::is_nothrow_constructible<StringView>::value);

    /**
     * \brief has host.
     * \uptrace{SWS_REST_02318}
     */
    bool HasPort() const noexcept;
    /**
     * \brief get port.
     * \uptrace{SWS_REST_02319}
     */
    int GetPort() const;

    class Path;
    /**
     * \brief has path.
     * \uptrace{SWS_REST_02320}
     */
    bool HasPath() const noexcept;
    /**
     * \brief get path.
     * \uptrace{SWS_REST_02321}
     */
    const Path& GetPath() const noexcept;

    class Query;
    /**
     * \brief has query.
     * \uptrace{SWS_REST_02322}
     */
    bool HasQuery() const noexcept;
    /**
     * \brief get query.
     * \uptrace{SWS_REST_02323}
     */
    const Query& GetQuery() const noexcept;

    /**
     * \brief Has Fragment.
     * \uptrace{SWS_REST_02324}
     */
    bool HasFragment() const noexcept;
    /**
     * \brief Get Fragment.
     * \uptrace{SWS_REST_02325}
     */
    StringView GetFragment() const;
    /**
     * \brief Get Fragment as.
     * \uptrace{SWS_REST_02326}
     */
    template <typename T>
    T GetFragmentAs() const;

    /**
     * \brief Is URI empty.
     * \uptrace{SWS_REST_02327}
     */
    bool IsEmpty() const noexcept;
    /**
     * \brief Is URI relative. An URI is relative if it does not starts with a scheme.
     * \uptrace{SWS_REST_02328}
     */
    bool IsRelative() const noexcept;

protected:
    friend class Uri_parser_Test;

    /**
     * \brief Parse and Extract uri into its parts.
     */
    void ParseUri(const StringView& uri);
    /**
     * \brief Pointer to scheme of Uri.
     */
    std::unique_ptr<StringView> scheme_;

    /**
     * \brief Pointer to user info of Uri.
     */
    std::unique_ptr<StringView> user_info_;

    /**
     * \brief Pointer to host of Uri.
     */
    std::unique_ptr<StringView> host_;

    /**
     * \brief Pointer to port of Uri.
     */
    std::unique_ptr<StringView> port_;

    /**
     * \brief Pointer to path of Uri.
     */
    std::unique_ptr<Path> path_;

    /**
     * \brief Pointer to query of Uri.
     */
    std::unique_ptr<Query> query_;

    /**
     * \brief Pointer to fragment of Uri.
     */
    std::unique_ptr<StringView> fragment_;

    /**
     * \brief True if uri does not begin with scheme information.
     */
    bool is_relative_;
};

/** \brief Represents the path component of a URI
 * \uptrace{SWS_REST_2287}
 */
class Uri::Path
{
public:
    /**
     * \brief Constructor
     */
    explicit Path(StringView& path);

    /**
     * \brief Iterator range of path segments
     * \uptrace{SWS_REST_2288}
     */
    using IteratorRange = apd::rest::IteratorRange<unspecified_iterator_type>;

    /** \brief Represents a path segment
     *
     */
    class Segment;

    /** \brief Returns the number of path segments
     *  \return a number of path segmeents
     *  \uptrace{SWS_REST_2289}
     */
    std::size_t NumSegments() const noexcept;

    /**
     * \brief TODO
     */
    const std::vector<Segment>& GetSegmentsVector() const
    {
        return segments_;
    }

    /**
     * \brief Get Path as String
     */
    String GetAsString() const;

    /**
     * \brief Needs documentation.
     * \uptrace{SWS_REST_2290}
     */
    IteratorRange GetSegments() const;

protected:
    /**
     * \brief Vector with the segments of path.
     */
    std::vector<Segment> segments_;
};

/**! forward declaration */
inline bool operator==(const Uri::Path::Segment& left, const Uri::Path::Segment& right);
/**! forward declaration */
inline bool operator<(const Uri::Path::Segment& left, const Uri::Path::Segment& right);
/**! forward declaration */
inline bool operator!=(const Uri::Path::Segment& left, const Uri::Path::Segment& right);

/**
 * \brief Compares to Uri::Path objects
 * \param left Object to compare with.
 * \param right Object to compare with.
 * \return true if equal otherwise false.
 * \uptrace{SWS_REST_02291}
 */
inline bool operator==(const Uri::Path& left, const Uri::Path& right)
{
    return (left.GetSegmentsVector().size() == right.GetSegmentsVector().size()
        && std::equal(
            left.GetSegmentsVector().begin(), left.GetSegmentsVector().end(), right.GetSegmentsVector().begin()));
}

/**
 * \brief Compares to Uri::Path objects
 * \param left Object to compare with.
 * \param right Object to compare with.
 * \return true if unequal otherwise false.
 * \uptrace{SWS_REST_02292}
 */
inline bool operator!=(const Uri::Path& left, const Uri::Path& right)
{
    return !(left == right);
}

/**
 * \brief Does A lexicographical comparison of the segmens of two Uri::Path objects.
 * Therefore all segments of the Uri::Path objects are compared element by element. If one Uri::path is a prefix of the
 * other, the shorter Uri::path is lexicographically less than the other. If both objects have equivalent elements and
 * are of the same length, then the ranges are lexicographically equal. An empty Uri::Path object is lexicographically
 * less than any non-empty range.
 * \param left Object to compare with.
 * \param right Object to compare with.
 * \return true if first operand is lexicographically smaller than the second operand otherwise false.
 * \uptrace{SWS_REST_02293}
 */
inline bool operator<(const Uri::Path& left, const Uri::Path& right)
{
    return (std::lexicographical_compare(left.GetSegmentsVector().begin(),
        left.GetSegmentsVector().end(),
        right.GetSegmentsVector().begin(),
        right.GetSegmentsVector().end()));
}

/** \brief Need documentation
 * \uptrace{SWS_REST_02281}
 */
class Uri::Path::Segment
{
public:
    /** \brief Returns a string representation of this path segment
     *
     *  The representation is non-percent-encoded
     *
     *  \return a string representation of this path segment
     *  \uptrace{SWS_REST_02282}
     */
    StringView Get() const;
    /** \brief Returns this segment converted to a user-defined type
     *
     *  The conversion result is assigned to the function argument which is subsequently returned.  If
     *  conversion fails the function argument is returned unchanged. So either form is valid:
     *  GetAs<string>(), GetAs(string{my_allocator}), GetAs<string>("conversion failed")
     *
     *  \tparam T type to convert to. T must be InputStreamable.
     *  \tparam Ts arguments passed to the constructor of type T
     *  \param ...
     *  \returns
     *  \uptrace{SWS_REST_02283}
     */
    template <typename T, typename... Ts>
    T GetAs(Ts&&...) const;

    /**
     * \brief Constructor
     */
    explicit Segment(const StringView& segment)
        : segment_(segment)
    { }

private:
    /**
     * \brief The segment content.
     */
    StringView segment_;
};

/**
 * \brief Comparsion of two Uri::Path::Segment objects on non-equality.
 * \param left
 * \param right
 * \uptrace{SWS_REST_02285}
 */
inline bool operator!=(const Uri::Path::Segment& left, const Uri::Path::Segment& right)
{
    return !(left == right);
}

/**
 * \brief Comparsion of two Uri::Path::Segment objects on equality.
 * \param left
 * \param right
 * \uptrace{SWS_REST_02284}
 */
inline bool operator==(const Uri::Path::Segment& left, const Uri::Path::Segment& right)
{
    return (left.Get().size() == right.Get().size() && left.Get() == right.Get());
}

/**
 * \brief Does A lexicographical comparison of the Uri::Path::Segment objects.
 * \param left
 * \param right
 * \uptrace{SWS_REST_02286}
 */
inline bool operator<(const Uri::Path::Segment& left, const Uri::Path::Segment& right)
{
    return (left.Get().size() < right.Get().size() || left.Get() < right.Get());
}

/**
 * \brief Query of an Uri.
 * \uptrace{SWS_REST_02300}
 */
class Uri::Query
{
public:
    /**
     * \brief Constructor
     */
    explicit Query(const StringView&);
    /**
     * \brief Needs documentation.
     * \uptrace{SWS_REST_02301}
     */
    using IteratorRange = apd::rest::IteratorRange<unspecified_iterator_type>;

    class Parameter;
    /** \brief Returns the number of query parameters
     *  \return the number of query parameters
     * \uptrace{SWS_REST_02302}
     */
    std::size_t NumParameters() const noexcept;
    /** \brief Returns the range of all query parameters
     * \return an iterator range of query parameters
     * \uptrace{SWS_REST_02303}
     */
    IteratorRange GetParameters() const noexcept;
    /** \brief Returns a specific query parameter by index
     *
     *  If the index is out-of-bound, the result is undefined.
     *  \param i
     *  \return a reference to the query parameter
     * \uptrace{SWS_REST_02304}
     */
    const Parameter& GetParameter(std::size_t i) const noexcept;
    /** Searches for a query parameter by key
     *
     *  If no such key is found, returns Query::GetParameters.end()
     *  \param key The key to find
     *  \return an iterator to the respective query parameter
     * \uptrace{SWS_REST_02305}
     */
    IteratorRange::Iterator Find(StringView key) const noexcept;
    /** Tests whether a query parameter of a given key exists
     * \param key The key to look-up
     * \return true of key exists
     * \uptrace{SWS_REST_02306}
     */
    bool HasKey(StringView key) noexcept;

protected:
    /**
     * \brief The parameters of the query.
     */
    std::vector<Parameter> parameters_;
};

/** \brief Represents a parameter of URI::Query.
 *
 *  A query parameter is either a pair ("key=value") or a singleton ("key").
 * \uptrace{SWS_REST_02294}
 */
class Uri::Query::Parameter
{
public:
    /**
     * \brief Constructor.
     */
    explicit Parameter(const StringView&);

    /**
     * \brief Needs documentation.
     * \uptrace{SWS_REST_02295}
     */
    StringView GetKey() const;
    /**
     * \brief Needs documentation.
     * \uptrace{SWS_REST_02296}
     */
    template <typename T>
    T GetKeyAs() const;

    /**
     * \brief Needs documentation.
     * \uptrace{SWS_REST_02297}
     */
    bool HasValue() const noexcept;
    /**
     * \brief Needs documentation.
     * \uptrace{SWS_REST_02298}
     */
    StringView GetValue() const;
    /** \brief Converts a query parameter value to the specified type
     *
     *  The conversion result is assigned to the function argument which is subsequently returned.  If
     *  conversion fails the function argument is returned unchanged. So either form is valid:
     *  GetAs<string>(), GetAs(string{my_allocator}), GetAs<string>("conversion failed")
     *
     *  \tparam T type to convert to. T must be InputStreamable.
     *  \return an instance of type T that represents this URI component.
     *  \uptrace{SWS_REST_02299}
     */
    template <typename T>
    T GetValueAs() const;

protected:
    /**
     * \brief The key of the parameter.
     */
    StringView key_;
    /**
     * \brief The value of the parameter.
     */
    StringView value_;
};

// NOTE(!): "T&&" is a universal reference; neither rvalue nor lvalue. treat accordingly.

/** \brief Builder to modify an Uri.
 *
 *  Uri is an immutable data structure for reasons of efficiency and resource control.
 *  For URI construction Uri::Builder must be used. Builder is allowed to perform dynamic
 *  memory allocation and its member functions may throw. Builder::ToUri() can be used
 *  to derive an (optimized) URI representation from the builder.
 *
 *  The member functions for URI composition accept arbitrary types which must be
 *  "OutputStreamable".  It means that an operator<<() must be defined that takes a std::ostream
 *  object on the left hand side and an instance of the argument type on the right.
 *
 *  To erase elements call constructor functions with an empty argument.
 *  \uptrace{SWS_REST_02259}
 *
 */
class Uri::Builder
{
public:
    /** \brief Default-constructs a builder
     *  \uptrace{SWS_REST_02260}
     */
    explicit Builder(Allocator* = GetDefaultAllocator());
    /**
     * \brief Parses a URI in string format
     * \param uri
     * \param alloc
     *
     * Throws std::invalid_argument of URI parsing fails.
     * \uptrace{SWS_REST_02261}
     */
    explicit Builder(StringView uri, Allocator* alloc = GetDefaultAllocator());

    /**
     *  \brief Initializes this builder with an existing Uri
     *  \param uri
     *  \param alloc
     *  \uptrace{SWS_REST_02262}
     */
    explicit Builder(const Uri& uri, Allocator* alloc = GetDefaultAllocator());

    /** \brief Initializes this builder with an existing Uri
     *  \uptrace{SWS_REST_02263}
     */
    explicit Builder(Uri&&, Allocator* = GetDefaultAllocator());

    /**
     * \brief Set scheme by parsing the given argument
     * Throws std::invalid_argument if parsing fails
     * \param data
     * \return a reference to this builder
     * \uptrace{SWS_REST_02264}
     */
    template <typename T>
    Builder& Scheme(T&& data)
    {
        StringView str(data);
        uri_.scheme_ = apd::rest::language::make_unique<StringView>(str.begin(), str.end());
        return *this;
    }

    /**
     * \brief Set user info by parsing the given argument
     * Throws std::invalid_argument if parsing fails
     * \param data
     * \return a reference to this builder
     * \uptrace{SWS_REST_02265}
     */
    template <typename T>
    Builder& UserInfo(T&& data)
    {
        StringView str(data);
        uri_.user_info_ = apd::rest::language::make_unique<StringView>(str.begin(), str.end());
        return *this;
    }

    /** \brief Sets host by parsing the given argument
     * Throws std::invalid_argument if parsing fails
     * \param data
     * \return a reference to this builder
     * \uptrace{SWS_REST_02266}
     */
    template <typename T>
    Builder& Host(T&& data)
    {
        StringView str(data);
        uri_.host_ = apd::rest::language::make_unique<StringView>(str.begin(), str.end());
        return *this;
    }

    /** \brief Sets the the Uri port from the given argument
     *  Throws std::invalid_argument if parsing fails
     * \param data
     * \return a reference to this builder
     * \uptrace{SWS_REST_02267}
     */
    template <typename T>
    Builder& Port(T&& data)
    {
        StringView str(data);
        uri_.port_ = apd::rest::language::make_unique<StringView>(str.begin(), str.end());
        return *this;
    }

    /** \brief Sets the URI path by parsing the given argument
     *  Throws std::invalid_argument, if parsing fails.
     * \param data
     * \return a reference to this builder
     * \uptrace{SWS_REST_02268}
     */

    Builder& Path(const Uri::Path& data)
    {
        uri_.path_ = apd::rest::language::make_unique<Uri::Path>(data);
        return *this;
    }

    /**
     * \brief Needs documentation.
     * \uptrace{SWS_REST_02424}
     */
    // append
    template <typename Ts>
    Builder& PathSegment(Ts&&...);

    /**
     * \brief Needs documentation.
     * \uptrace{SWS_REST_02426}
     */
    // insert, overwrite
    template <typename Ts>
    Builder& PathSegmentAt(std::size_t pos, Ts&&...);

    /** \brief Needs documentation.
     *
     * Throws std::invalid_argument if parsing fails
     * \return a reference to this builder
     * \param data
     * \uptrace{SWS_REST_02272}
     */
    Builder& Query(const Uri::Query& data)
    {
        uri_.query_ = apd::rest::language::make_unique<Uri::Query>(data);
        return *this;
    }

    /** \brief Inserts a query parameter (key only)
     *
     * If the given key already exists, no action is performed.
     *
     * Throws std::invalid_argument if parsing fails
     * \return a reference to this builder
     * \param data
     * \uptrace{SWS_REST_02273}
     */
    template <typename T>
    Builder& QueryParameter(T&& data)
    {
        if (uri_.query_) {
        }
        return *this;
    }

    /**If the given key already exists, no action is performed.
     * Throws std::invalid_argument if parsing fails
     * \return a reference to this builder
     * \uptrace{SWS_REST_02274}
     */
    template <typename T, typename U>
    Builder& QueryParameter(T&&, U&&);

    /**
     * \brief Search for key 't', replace by key 'u'
     */
    // key lookup, no 'value'; if not exists, does nothing
    template <typename T, typename U>
    Builder& QueryParameterAt(T&& t, U&& u)
    {
        if (uri_.query_) {
            if (auto param_it = uri_.query_->Find(t)) {
                // replace key
                param_it.key_ = u;
            }
        }
        return *this;
    }

    /**
     * \brief Search for key 't', replace key by 'u' and its value by 'v'
     * \uptrace{SWS_REST_02277}
     */
    // key lookup; if not exists, does nothing
    template <typename T, typename U, typename V>
    Builder& QueryParameterAt(T&& t, U&& u, V&& v)
    {
        if (uri_.query_) {
            if (auto param_it = uri_.query_->Find(t)) {
                // replace key
                param_it.key_ = u;
                param_it.value_ = v;
            }
        }
        return *this;
    }

    /**
     * \brief Needs documentation.
     */
    template <typename T>
    Builder& Fragment(T&& data)
    {
        uri_.fragment_ = apd::rest::language::make_unique<StringView>(data);
        return *this;
    }

    /**
     * \brief Returns a Uri
     */
    Uri ToUri() const
    {
        return uri_;
    }

protected:
    /**
     * \brief the uri_ object constructed by the builder.
     */
    Uri uri_;
};

// For these, see https://www.ietf.org/rfc/rfc3986.txt

Uri Resolve(const Uri&, const Uri&, Allocator* = GetDefaultAllocator());
Uri Resolve(const Uri&, Uri&&, Allocator* = GetDefaultAllocator());
Uri Resolve(Uri&&, const Uri&, Allocator* = GetDefaultAllocator());
Uri Resolve(Uri&&, Uri&&, Allocator* = GetDefaultAllocator());

/** \brief Normalizes a given URI
 *
 *  \param uri URI to normalize
 *  \return a noralized URI
 */
Uri Normalize(const Uri&, Allocator* = GetDefaultAllocator());
Uri Normalize(Uri&&, Allocator* = GetDefaultAllocator());
/** \brief Relativizes a URI with respect to a given base URI
 *
 * The relativization of the given URI against this URI is computed as follows:
 *
 * If either the base URI or the given URI are opaque, or if the scheme and authority components of the
 * two URIs are not identical, or if the path of the base URI is not a prefix of the path of the given
 * URI, then the given URI is returned.
 *
 * Otherwise a new relative hierarchical URI is constructed with query and fragment components taken
 * from the given URI and with a path component computed by removing this URI's path from the
 * beginning of the given URI's path.
 *
 *  \param base a base URI as reference
 *  \param uri a URI to relativize
 *  \return a relative URI
 */
Uri Relativize(const Uri&, const Uri&, Allocator* = GetDefaultAllocator());
Uri Relativize(const Uri&, Uri&&, Allocator* = GetDefaultAllocator());
Uri Relativize(Uri&&, const Uri&, Allocator* = GetDefaultAllocator());
Uri Relativize(Uri&&, Uri&&, Allocator* = GetDefaultAllocator());

/** \brief Returns a string representation of a Uri
 *
 *  \param uri URI to encode
 *  \param part denotes which components of a URI should be encoded
 *  \param encode if true, then the string will be percent-encoded. If false, the string must not be string encoded.
 *  \param alloc a user-defined allocator passed to the string object being returned
 *  \return the encoded URI
 */
String ToString(const Uri& uri, Uri::Part part, bool encode, Allocator* alloc = GetDefaultAllocator());

/**
 *  \brief Returns a string representation of a Uri
 *  \param uri URI to encode
 *  \param part denotes which components of a URI should be encoded
 *  \param alloc a user-defined allocator passed to the string object being returned
 *  \return the encoded URI
 */
String ToString(const Uri& uri, Uri::Part part, Allocator* alloc = GetDefaultAllocator());

/**
 *  \brief Returns a string representation of a Uri
 *  \param uri URI to encode
 *  \param alloc a user-defined allocator passed to the string object being returned
 *  \return the encoded URI
 */
String ToString(const Uri& uri, Allocator* alloc = GetDefaultAllocator());

/**
 *  \brief Returns a string representation of a Uri
 *  \param uri URI to encode
 *  \param part denotes which components of a URI should be encoded
 *  \param encode if true, then the string will be percent-encoded. If false, the string must not be string encoded.
 *  \param alloc a user-defined allocator passed to the string object being returned
 *  \return the encoded URI
 */
String ToString(Uri&& uri, Uri::Part part, bool encode, Allocator* alloc = GetDefaultAllocator());

/**
 *  \brief Returns a string representation of a Uri
 *  \param uri URI to encode
 *  \param part denotes which components of a URI should be encoded
 *  \param alloc a user-defined allocator passed to the string object being returned
 *  \return the encoded URI
 */
String ToString(Uri&& uri, Uri::Part part, Allocator* alloc = GetDefaultAllocator());

/**
 *  \brief Returns a string representation of a Uri
 *  \param uri URI to encode
 *  \param alloc a user-defined allocator passed to the string object being returned
 *  \return the encoded URI
 */
String ToString(Uri&& uri, Allocator* alloc = GetDefaultAllocator());

/**
 * \brief Decode string
 * \param value The string to decode
 * \return The decode string
 */
String Decode(const String& value);

/**
 * \brief Encode string
 * \param value The string to encode
 * \return The encoded string
 */
String Encode(const String& value);

}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_URI_H_
