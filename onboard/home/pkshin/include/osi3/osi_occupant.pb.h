// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: osi_occupant.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_osi_5foccupant_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_osi_5foccupant_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "osi_common.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_osi_5foccupant_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_osi_5foccupant_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_osi_5foccupant_2eproto;
namespace osi3 {
class Occupant;
class OccupantDefaultTypeInternal;
extern OccupantDefaultTypeInternal _Occupant_default_instance_;
class Occupant_Classification;
class Occupant_ClassificationDefaultTypeInternal;
extern Occupant_ClassificationDefaultTypeInternal _Occupant_Classification_default_instance_;
}  // namespace osi3
PROTOBUF_NAMESPACE_OPEN
template<> ::osi3::Occupant* Arena::CreateMaybeMessage<::osi3::Occupant>(Arena*);
template<> ::osi3::Occupant_Classification* Arena::CreateMaybeMessage<::osi3::Occupant_Classification>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace osi3 {

enum Occupant_Classification_Seat : int {
  Occupant_Classification_Seat_SEAT_UNKNOWN = 0,
  Occupant_Classification_Seat_SEAT_OTHER = 1,
  Occupant_Classification_Seat_SEAT_FRONT_LEFT = 2,
  Occupant_Classification_Seat_SEAT_FRONT_RIGHT = 3,
  Occupant_Classification_Seat_SEAT_FRONT_MIDDLE = 4,
  Occupant_Classification_Seat_SEAT_BACK_LEFT = 5,
  Occupant_Classification_Seat_SEAT_BACK_RIGHT = 6,
  Occupant_Classification_Seat_SEAT_BACK_MIDDLE = 7,
  Occupant_Classification_Seat_SEAT_THIRD_ROW_LEFT = 8,
  Occupant_Classification_Seat_SEAT_THIRD_ROW_RIGHT = 9,
  Occupant_Classification_Seat_SEAT_THIRD_ROW_MIDDLE = 10
};
bool Occupant_Classification_Seat_IsValid(int value);
constexpr Occupant_Classification_Seat Occupant_Classification_Seat_Seat_MIN = Occupant_Classification_Seat_SEAT_UNKNOWN;
constexpr Occupant_Classification_Seat Occupant_Classification_Seat_Seat_MAX = Occupant_Classification_Seat_SEAT_THIRD_ROW_MIDDLE;
constexpr int Occupant_Classification_Seat_Seat_ARRAYSIZE = Occupant_Classification_Seat_Seat_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Occupant_Classification_Seat_descriptor();
template<typename T>
inline const std::string& Occupant_Classification_Seat_Name(T enum_t_value) {
  static_assert(::std::is_same<T, Occupant_Classification_Seat>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function Occupant_Classification_Seat_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    Occupant_Classification_Seat_descriptor(), enum_t_value);
}
inline bool Occupant_Classification_Seat_Parse(
    const std::string& name, Occupant_Classification_Seat* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<Occupant_Classification_Seat>(
    Occupant_Classification_Seat_descriptor(), name, value);
}
enum Occupant_Classification_SteeringControl : int {
  Occupant_Classification_SteeringControl_STEERING_CONTROL_UNKNOWN = 0,
  Occupant_Classification_SteeringControl_STEERING_CONTROL_OTHER = 1,
  Occupant_Classification_SteeringControl_STEERING_CONTROL_NO_HAND = 2,
  Occupant_Classification_SteeringControl_STEERING_CONTROL_ONE_HAND = 3,
  Occupant_Classification_SteeringControl_STEERING_CONTROL_BOTH_HANDS = 4,
  Occupant_Classification_SteeringControl_STEERING_CONTROL_LEFT_HAND = 5,
  Occupant_Classification_SteeringControl_STEERING_CONTROL_RIGHT_HAND = 6
};
bool Occupant_Classification_SteeringControl_IsValid(int value);
constexpr Occupant_Classification_SteeringControl Occupant_Classification_SteeringControl_SteeringControl_MIN = Occupant_Classification_SteeringControl_STEERING_CONTROL_UNKNOWN;
constexpr Occupant_Classification_SteeringControl Occupant_Classification_SteeringControl_SteeringControl_MAX = Occupant_Classification_SteeringControl_STEERING_CONTROL_RIGHT_HAND;
constexpr int Occupant_Classification_SteeringControl_SteeringControl_ARRAYSIZE = Occupant_Classification_SteeringControl_SteeringControl_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Occupant_Classification_SteeringControl_descriptor();
template<typename T>
inline const std::string& Occupant_Classification_SteeringControl_Name(T enum_t_value) {
  static_assert(::std::is_same<T, Occupant_Classification_SteeringControl>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function Occupant_Classification_SteeringControl_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    Occupant_Classification_SteeringControl_descriptor(), enum_t_value);
}
inline bool Occupant_Classification_SteeringControl_Parse(
    const std::string& name, Occupant_Classification_SteeringControl* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<Occupant_Classification_SteeringControl>(
    Occupant_Classification_SteeringControl_descriptor(), name, value);
}
// ===================================================================

class Occupant_Classification :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:osi3.Occupant.Classification) */ {
 public:
  Occupant_Classification();
  virtual ~Occupant_Classification();

  Occupant_Classification(const Occupant_Classification& from);
  Occupant_Classification(Occupant_Classification&& from) noexcept
    : Occupant_Classification() {
    *this = ::std::move(from);
  }

  inline Occupant_Classification& operator=(const Occupant_Classification& from) {
    CopyFrom(from);
    return *this;
  }
  inline Occupant_Classification& operator=(Occupant_Classification&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Occupant_Classification& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Occupant_Classification* internal_default_instance() {
    return reinterpret_cast<const Occupant_Classification*>(
               &_Occupant_Classification_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Occupant_Classification& a, Occupant_Classification& b) {
    a.Swap(&b);
  }
  inline void Swap(Occupant_Classification* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Occupant_Classification* New() const final {
    return CreateMaybeMessage<Occupant_Classification>(nullptr);
  }

  Occupant_Classification* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Occupant_Classification>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Occupant_Classification& from);
  void MergeFrom(const Occupant_Classification& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Occupant_Classification* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "osi3.Occupant.Classification";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_osi_5foccupant_2eproto);
    return ::descriptor_table_osi_5foccupant_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  typedef Occupant_Classification_Seat Seat;
  static constexpr Seat SEAT_UNKNOWN =
    Occupant_Classification_Seat_SEAT_UNKNOWN;
  static constexpr Seat SEAT_OTHER =
    Occupant_Classification_Seat_SEAT_OTHER;
  static constexpr Seat SEAT_FRONT_LEFT =
    Occupant_Classification_Seat_SEAT_FRONT_LEFT;
  static constexpr Seat SEAT_FRONT_RIGHT =
    Occupant_Classification_Seat_SEAT_FRONT_RIGHT;
  static constexpr Seat SEAT_FRONT_MIDDLE =
    Occupant_Classification_Seat_SEAT_FRONT_MIDDLE;
  static constexpr Seat SEAT_BACK_LEFT =
    Occupant_Classification_Seat_SEAT_BACK_LEFT;
  static constexpr Seat SEAT_BACK_RIGHT =
    Occupant_Classification_Seat_SEAT_BACK_RIGHT;
  static constexpr Seat SEAT_BACK_MIDDLE =
    Occupant_Classification_Seat_SEAT_BACK_MIDDLE;
  static constexpr Seat SEAT_THIRD_ROW_LEFT =
    Occupant_Classification_Seat_SEAT_THIRD_ROW_LEFT;
  static constexpr Seat SEAT_THIRD_ROW_RIGHT =
    Occupant_Classification_Seat_SEAT_THIRD_ROW_RIGHT;
  static constexpr Seat SEAT_THIRD_ROW_MIDDLE =
    Occupant_Classification_Seat_SEAT_THIRD_ROW_MIDDLE;
  static inline bool Seat_IsValid(int value) {
    return Occupant_Classification_Seat_IsValid(value);
  }
  static constexpr Seat Seat_MIN =
    Occupant_Classification_Seat_Seat_MIN;
  static constexpr Seat Seat_MAX =
    Occupant_Classification_Seat_Seat_MAX;
  static constexpr int Seat_ARRAYSIZE =
    Occupant_Classification_Seat_Seat_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  Seat_descriptor() {
    return Occupant_Classification_Seat_descriptor();
  }
  template<typename T>
  static inline const std::string& Seat_Name(T enum_t_value) {
    static_assert(::std::is_same<T, Seat>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function Seat_Name.");
    return Occupant_Classification_Seat_Name(enum_t_value);
  }
  static inline bool Seat_Parse(const std::string& name,
      Seat* value) {
    return Occupant_Classification_Seat_Parse(name, value);
  }

  typedef Occupant_Classification_SteeringControl SteeringControl;
  static constexpr SteeringControl STEERING_CONTROL_UNKNOWN =
    Occupant_Classification_SteeringControl_STEERING_CONTROL_UNKNOWN;
  static constexpr SteeringControl STEERING_CONTROL_OTHER =
    Occupant_Classification_SteeringControl_STEERING_CONTROL_OTHER;
  static constexpr SteeringControl STEERING_CONTROL_NO_HAND =
    Occupant_Classification_SteeringControl_STEERING_CONTROL_NO_HAND;
  static constexpr SteeringControl STEERING_CONTROL_ONE_HAND =
    Occupant_Classification_SteeringControl_STEERING_CONTROL_ONE_HAND;
  static constexpr SteeringControl STEERING_CONTROL_BOTH_HANDS =
    Occupant_Classification_SteeringControl_STEERING_CONTROL_BOTH_HANDS;
  static constexpr SteeringControl STEERING_CONTROL_LEFT_HAND =
    Occupant_Classification_SteeringControl_STEERING_CONTROL_LEFT_HAND;
  static constexpr SteeringControl STEERING_CONTROL_RIGHT_HAND =
    Occupant_Classification_SteeringControl_STEERING_CONTROL_RIGHT_HAND;
  static inline bool SteeringControl_IsValid(int value) {
    return Occupant_Classification_SteeringControl_IsValid(value);
  }
  static constexpr SteeringControl SteeringControl_MIN =
    Occupant_Classification_SteeringControl_SteeringControl_MIN;
  static constexpr SteeringControl SteeringControl_MAX =
    Occupant_Classification_SteeringControl_SteeringControl_MAX;
  static constexpr int SteeringControl_ARRAYSIZE =
    Occupant_Classification_SteeringControl_SteeringControl_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  SteeringControl_descriptor() {
    return Occupant_Classification_SteeringControl_descriptor();
  }
  template<typename T>
  static inline const std::string& SteeringControl_Name(T enum_t_value) {
    static_assert(::std::is_same<T, SteeringControl>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function SteeringControl_Name.");
    return Occupant_Classification_SteeringControl_Name(enum_t_value);
  }
  static inline bool SteeringControl_Parse(const std::string& name,
      SteeringControl* value) {
    return Occupant_Classification_SteeringControl_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kIsDriverFieldNumber = 2,
    kSeatFieldNumber = 3,
    kSteeringControlFieldNumber = 4,
  };
  // optional bool is_driver = 2;
  bool has_is_driver() const;
  private:
  bool _internal_has_is_driver() const;
  public:
  void clear_is_driver();
  bool is_driver() const;
  void set_is_driver(bool value);
  private:
  bool _internal_is_driver() const;
  void _internal_set_is_driver(bool value);
  public:

  // optional .osi3.Occupant.Classification.Seat seat = 3;
  bool has_seat() const;
  private:
  bool _internal_has_seat() const;
  public:
  void clear_seat();
  ::osi3::Occupant_Classification_Seat seat() const;
  void set_seat(::osi3::Occupant_Classification_Seat value);
  private:
  ::osi3::Occupant_Classification_Seat _internal_seat() const;
  void _internal_set_seat(::osi3::Occupant_Classification_Seat value);
  public:

  // optional .osi3.Occupant.Classification.SteeringControl steering_control = 4;
  bool has_steering_control() const;
  private:
  bool _internal_has_steering_control() const;
  public:
  void clear_steering_control();
  ::osi3::Occupant_Classification_SteeringControl steering_control() const;
  void set_steering_control(::osi3::Occupant_Classification_SteeringControl value);
  private:
  ::osi3::Occupant_Classification_SteeringControl _internal_steering_control() const;
  void _internal_set_steering_control(::osi3::Occupant_Classification_SteeringControl value);
  public:

  // @@protoc_insertion_point(class_scope:osi3.Occupant.Classification)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  bool is_driver_;
  int seat_;
  int steering_control_;
  friend struct ::TableStruct_osi_5foccupant_2eproto;
};
// -------------------------------------------------------------------

class Occupant :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:osi3.Occupant) */ {
 public:
  Occupant();
  virtual ~Occupant();

  Occupant(const Occupant& from);
  Occupant(Occupant&& from) noexcept
    : Occupant() {
    *this = ::std::move(from);
  }

  inline Occupant& operator=(const Occupant& from) {
    CopyFrom(from);
    return *this;
  }
  inline Occupant& operator=(Occupant&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Occupant& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Occupant* internal_default_instance() {
    return reinterpret_cast<const Occupant*>(
               &_Occupant_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Occupant& a, Occupant& b) {
    a.Swap(&b);
  }
  inline void Swap(Occupant* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Occupant* New() const final {
    return CreateMaybeMessage<Occupant>(nullptr);
  }

  Occupant* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Occupant>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Occupant& from);
  void MergeFrom(const Occupant& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Occupant* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "osi3.Occupant";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_osi_5foccupant_2eproto);
    return ::descriptor_table_osi_5foccupant_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  typedef Occupant_Classification Classification;

  // accessors -------------------------------------------------------

  enum : int {
    kSourceReferenceFieldNumber = 3,
    kIdFieldNumber = 1,
    kClassificationFieldNumber = 2,
  };
  // repeated .osi3.ExternalReference source_reference = 3;
  int source_reference_size() const;
  private:
  int _internal_source_reference_size() const;
  public:
  void clear_source_reference();
  ::osi3::ExternalReference* mutable_source_reference(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::osi3::ExternalReference >*
      mutable_source_reference();
  private:
  const ::osi3::ExternalReference& _internal_source_reference(int index) const;
  ::osi3::ExternalReference* _internal_add_source_reference();
  public:
  const ::osi3::ExternalReference& source_reference(int index) const;
  ::osi3::ExternalReference* add_source_reference();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::osi3::ExternalReference >&
      source_reference() const;

  // optional .osi3.Identifier id = 1;
  bool has_id() const;
  private:
  bool _internal_has_id() const;
  public:
  void clear_id();
  const ::osi3::Identifier& id() const;
  ::osi3::Identifier* release_id();
  ::osi3::Identifier* mutable_id();
  void set_allocated_id(::osi3::Identifier* id);
  private:
  const ::osi3::Identifier& _internal_id() const;
  ::osi3::Identifier* _internal_mutable_id();
  public:

  // optional .osi3.Occupant.Classification classification = 2;
  bool has_classification() const;
  private:
  bool _internal_has_classification() const;
  public:
  void clear_classification();
  const ::osi3::Occupant_Classification& classification() const;
  ::osi3::Occupant_Classification* release_classification();
  ::osi3::Occupant_Classification* mutable_classification();
  void set_allocated_classification(::osi3::Occupant_Classification* classification);
  private:
  const ::osi3::Occupant_Classification& _internal_classification() const;
  ::osi3::Occupant_Classification* _internal_mutable_classification();
  public:

  // @@protoc_insertion_point(class_scope:osi3.Occupant)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::osi3::ExternalReference > source_reference_;
  ::osi3::Identifier* id_;
  ::osi3::Occupant_Classification* classification_;
  friend struct ::TableStruct_osi_5foccupant_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Occupant_Classification

// optional bool is_driver = 2;
inline bool Occupant_Classification::_internal_has_is_driver() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool Occupant_Classification::has_is_driver() const {
  return _internal_has_is_driver();
}
inline void Occupant_Classification::clear_is_driver() {
  is_driver_ = false;
  _has_bits_[0] &= ~0x00000001u;
}
inline bool Occupant_Classification::_internal_is_driver() const {
  return is_driver_;
}
inline bool Occupant_Classification::is_driver() const {
  // @@protoc_insertion_point(field_get:osi3.Occupant.Classification.is_driver)
  return _internal_is_driver();
}
inline void Occupant_Classification::_internal_set_is_driver(bool value) {
  _has_bits_[0] |= 0x00000001u;
  is_driver_ = value;
}
inline void Occupant_Classification::set_is_driver(bool value) {
  _internal_set_is_driver(value);
  // @@protoc_insertion_point(field_set:osi3.Occupant.Classification.is_driver)
}

// optional .osi3.Occupant.Classification.Seat seat = 3;
inline bool Occupant_Classification::_internal_has_seat() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool Occupant_Classification::has_seat() const {
  return _internal_has_seat();
}
inline void Occupant_Classification::clear_seat() {
  seat_ = 0;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::osi3::Occupant_Classification_Seat Occupant_Classification::_internal_seat() const {
  return static_cast< ::osi3::Occupant_Classification_Seat >(seat_);
}
inline ::osi3::Occupant_Classification_Seat Occupant_Classification::seat() const {
  // @@protoc_insertion_point(field_get:osi3.Occupant.Classification.seat)
  return _internal_seat();
}
inline void Occupant_Classification::_internal_set_seat(::osi3::Occupant_Classification_Seat value) {
  assert(::osi3::Occupant_Classification_Seat_IsValid(value));
  _has_bits_[0] |= 0x00000002u;
  seat_ = value;
}
inline void Occupant_Classification::set_seat(::osi3::Occupant_Classification_Seat value) {
  _internal_set_seat(value);
  // @@protoc_insertion_point(field_set:osi3.Occupant.Classification.seat)
}

// optional .osi3.Occupant.Classification.SteeringControl steering_control = 4;
inline bool Occupant_Classification::_internal_has_steering_control() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool Occupant_Classification::has_steering_control() const {
  return _internal_has_steering_control();
}
inline void Occupant_Classification::clear_steering_control() {
  steering_control_ = 0;
  _has_bits_[0] &= ~0x00000004u;
}
inline ::osi3::Occupant_Classification_SteeringControl Occupant_Classification::_internal_steering_control() const {
  return static_cast< ::osi3::Occupant_Classification_SteeringControl >(steering_control_);
}
inline ::osi3::Occupant_Classification_SteeringControl Occupant_Classification::steering_control() const {
  // @@protoc_insertion_point(field_get:osi3.Occupant.Classification.steering_control)
  return _internal_steering_control();
}
inline void Occupant_Classification::_internal_set_steering_control(::osi3::Occupant_Classification_SteeringControl value) {
  assert(::osi3::Occupant_Classification_SteeringControl_IsValid(value));
  _has_bits_[0] |= 0x00000004u;
  steering_control_ = value;
}
inline void Occupant_Classification::set_steering_control(::osi3::Occupant_Classification_SteeringControl value) {
  _internal_set_steering_control(value);
  // @@protoc_insertion_point(field_set:osi3.Occupant.Classification.steering_control)
}

// -------------------------------------------------------------------

// Occupant

// optional .osi3.Identifier id = 1;
inline bool Occupant::_internal_has_id() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || id_ != nullptr);
  return value;
}
inline bool Occupant::has_id() const {
  return _internal_has_id();
}
inline const ::osi3::Identifier& Occupant::_internal_id() const {
  const ::osi3::Identifier* p = id_;
  return p != nullptr ? *p : *reinterpret_cast<const ::osi3::Identifier*>(
      &::osi3::_Identifier_default_instance_);
}
inline const ::osi3::Identifier& Occupant::id() const {
  // @@protoc_insertion_point(field_get:osi3.Occupant.id)
  return _internal_id();
}
inline ::osi3::Identifier* Occupant::release_id() {
  // @@protoc_insertion_point(field_release:osi3.Occupant.id)
  _has_bits_[0] &= ~0x00000001u;
  ::osi3::Identifier* temp = id_;
  id_ = nullptr;
  return temp;
}
inline ::osi3::Identifier* Occupant::_internal_mutable_id() {
  _has_bits_[0] |= 0x00000001u;
  if (id_ == nullptr) {
    auto* p = CreateMaybeMessage<::osi3::Identifier>(GetArenaNoVirtual());
    id_ = p;
  }
  return id_;
}
inline ::osi3::Identifier* Occupant::mutable_id() {
  // @@protoc_insertion_point(field_mutable:osi3.Occupant.id)
  return _internal_mutable_id();
}
inline void Occupant::set_allocated_id(::osi3::Identifier* id) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(id_);
  }
  if (id) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      id = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, id, submessage_arena);
    }
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  id_ = id;
  // @@protoc_insertion_point(field_set_allocated:osi3.Occupant.id)
}

// optional .osi3.Occupant.Classification classification = 2;
inline bool Occupant::_internal_has_classification() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  PROTOBUF_ASSUME(!value || classification_ != nullptr);
  return value;
}
inline bool Occupant::has_classification() const {
  return _internal_has_classification();
}
inline void Occupant::clear_classification() {
  if (classification_ != nullptr) classification_->Clear();
  _has_bits_[0] &= ~0x00000002u;
}
inline const ::osi3::Occupant_Classification& Occupant::_internal_classification() const {
  const ::osi3::Occupant_Classification* p = classification_;
  return p != nullptr ? *p : *reinterpret_cast<const ::osi3::Occupant_Classification*>(
      &::osi3::_Occupant_Classification_default_instance_);
}
inline const ::osi3::Occupant_Classification& Occupant::classification() const {
  // @@protoc_insertion_point(field_get:osi3.Occupant.classification)
  return _internal_classification();
}
inline ::osi3::Occupant_Classification* Occupant::release_classification() {
  // @@protoc_insertion_point(field_release:osi3.Occupant.classification)
  _has_bits_[0] &= ~0x00000002u;
  ::osi3::Occupant_Classification* temp = classification_;
  classification_ = nullptr;
  return temp;
}
inline ::osi3::Occupant_Classification* Occupant::_internal_mutable_classification() {
  _has_bits_[0] |= 0x00000002u;
  if (classification_ == nullptr) {
    auto* p = CreateMaybeMessage<::osi3::Occupant_Classification>(GetArenaNoVirtual());
    classification_ = p;
  }
  return classification_;
}
inline ::osi3::Occupant_Classification* Occupant::mutable_classification() {
  // @@protoc_insertion_point(field_mutable:osi3.Occupant.classification)
  return _internal_mutable_classification();
}
inline void Occupant::set_allocated_classification(::osi3::Occupant_Classification* classification) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete classification_;
  }
  if (classification) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      classification = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, classification, submessage_arena);
    }
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  classification_ = classification;
  // @@protoc_insertion_point(field_set_allocated:osi3.Occupant.classification)
}

// repeated .osi3.ExternalReference source_reference = 3;
inline int Occupant::_internal_source_reference_size() const {
  return source_reference_.size();
}
inline int Occupant::source_reference_size() const {
  return _internal_source_reference_size();
}
inline ::osi3::ExternalReference* Occupant::mutable_source_reference(int index) {
  // @@protoc_insertion_point(field_mutable:osi3.Occupant.source_reference)
  return source_reference_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::osi3::ExternalReference >*
Occupant::mutable_source_reference() {
  // @@protoc_insertion_point(field_mutable_list:osi3.Occupant.source_reference)
  return &source_reference_;
}
inline const ::osi3::ExternalReference& Occupant::_internal_source_reference(int index) const {
  return source_reference_.Get(index);
}
inline const ::osi3::ExternalReference& Occupant::source_reference(int index) const {
  // @@protoc_insertion_point(field_get:osi3.Occupant.source_reference)
  return _internal_source_reference(index);
}
inline ::osi3::ExternalReference* Occupant::_internal_add_source_reference() {
  return source_reference_.Add();
}
inline ::osi3::ExternalReference* Occupant::add_source_reference() {
  // @@protoc_insertion_point(field_add:osi3.Occupant.source_reference)
  return _internal_add_source_reference();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::osi3::ExternalReference >&
Occupant::source_reference() const {
  // @@protoc_insertion_point(field_list:osi3.Occupant.source_reference)
  return source_reference_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace osi3

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::osi3::Occupant_Classification_Seat> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::osi3::Occupant_Classification_Seat>() {
  return ::osi3::Occupant_Classification_Seat_descriptor();
}
template <> struct is_proto_enum< ::osi3::Occupant_Classification_SteeringControl> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::osi3::Occupant_Classification_SteeringControl>() {
  return ::osi3::Occupant_Classification_SteeringControl_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_osi_5foccupant_2eproto