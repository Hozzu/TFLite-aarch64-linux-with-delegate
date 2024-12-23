/* -*- C++ -*- */
/* Generated by /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/aarch64-oe-linux/opendds/1.0+gitAUTOINC+0810ffc3f5-r7/recipe-sysroot-native/usr/bin/DDS_HOST_ROOT/bin/opendds_idl version 3.13 (ACE version 6.5.12) running on input file DdsDcpsGuid.idl */
#ifndef OPENDDS_IDL_GENERATED_DDSDCPSGUIDTYPESUPPORTIMPL_H_YVK7DR
#define OPENDDS_IDL_GENERATED_DDSDCPSGUIDTYPESUPPORTIMPL_H_YVK7DR
#include "DdsDcpsGuidC.h"
#include "dds/DCPS/Definitions.h"
#include "dds/DdsDcpsC.h"
#include "dds/DCPS/Serializer.h"
#include "dds/DCPS/dcps_export.h"


/* Begin MODULE: CORBA */


/* End MODULE: CORBA */


/* Begin MODULE: OpenDDS */



/* Begin MODULE: DCPS */



/* Begin TYPEDEF: GuidVendorId_t */

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

OpenDDS_Dcps_Export
void gen_find_size(const OpenDDS::DCPS::GuidVendorId_t_forany& arr, size_t& size, size_t& padding);

OpenDDS_Dcps_Export
bool operator<<(Serializer& strm, const OpenDDS::DCPS::GuidVendorId_t_forany& arr);

OpenDDS_Dcps_Export
bool operator>>(Serializer& strm, OpenDDS::DCPS::GuidVendorId_t_forany& arr);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

OpenDDS_Dcps_Export
bool gen_skip_over(Serializer& ser, OpenDDS::DCPS::GuidVendorId_t_forany*);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#endif

/* End TYPEDEF: GuidVendorId_t */


/* Begin TYPEDEF: GuidPrefix_t */

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

OpenDDS_Dcps_Export
void gen_find_size(const OpenDDS::DCPS::GuidPrefix_t_forany& arr, size_t& size, size_t& padding);

OpenDDS_Dcps_Export
bool operator<<(Serializer& strm, const OpenDDS::DCPS::GuidPrefix_t_forany& arr);

OpenDDS_Dcps_Export
bool operator>>(Serializer& strm, OpenDDS::DCPS::GuidPrefix_t_forany& arr);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

OpenDDS_Dcps_Export
bool gen_skip_over(Serializer& ser, OpenDDS::DCPS::GuidPrefix_t_forany*);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#endif

/* End TYPEDEF: GuidPrefix_t */


/* Begin TYPEDEF: EntityKey_t */

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

OpenDDS_Dcps_Export
void gen_find_size(const OpenDDS::DCPS::EntityKey_t_forany& arr, size_t& size, size_t& padding);

OpenDDS_Dcps_Export
bool operator<<(Serializer& strm, const OpenDDS::DCPS::EntityKey_t_forany& arr);

OpenDDS_Dcps_Export
bool operator>>(Serializer& strm, OpenDDS::DCPS::EntityKey_t_forany& arr);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

OpenDDS_Dcps_Export
bool gen_skip_over(Serializer& ser, OpenDDS::DCPS::EntityKey_t_forany*);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#endif

/* End TYPEDEF: EntityKey_t */


/* Begin STRUCT: EntityId_t */

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

OpenDDS_Dcps_Export
void gen_find_size(const OpenDDS::DCPS::EntityId_t& stru, size_t& size, size_t& padding);

OpenDDS_Dcps_Export
bool operator<<(Serializer& strm, const OpenDDS::DCPS::EntityId_t& stru);

OpenDDS_Dcps_Export
bool operator>>(Serializer& strm, OpenDDS::DCPS::EntityId_t& stru);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

class MetaStruct;

template<typename T>
const MetaStruct& getMetaStruct();

template<>
OpenDDS_Dcps_Export
const MetaStruct& getMetaStruct<OpenDDS::DCPS::EntityId_t>();
OpenDDS_Dcps_Export
bool gen_skip_over(Serializer& ser, OpenDDS::DCPS::EntityId_t*);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#endif

/* End STRUCT: EntityId_t */


/* Begin CONST: ENTITYKIND_BUILTIN_UNKNOWN */


/* End CONST: ENTITYKIND_BUILTIN_UNKNOWN */


/* Begin CONST: ENTITYKIND_BUILTIN_PARTICIPANT */


/* End CONST: ENTITYKIND_BUILTIN_PARTICIPANT */


/* Begin CONST: ENTITYKIND_BUILTIN_WRITER_WITH_KEY */


/* End CONST: ENTITYKIND_BUILTIN_WRITER_WITH_KEY */


/* Begin CONST: ENTITYKIND_BUILTIN_WRITER_NO_KEY */


/* End CONST: ENTITYKIND_BUILTIN_WRITER_NO_KEY */


/* Begin CONST: ENTITYKIND_BUILTIN_READER_NO_KEY */


/* End CONST: ENTITYKIND_BUILTIN_READER_NO_KEY */


/* Begin CONST: ENTITYKIND_BUILTIN_READER_WITH_KEY */


/* End CONST: ENTITYKIND_BUILTIN_READER_WITH_KEY */


/* Begin CONST: ENTITYKIND_BUILTIN_TOPIC */


/* End CONST: ENTITYKIND_BUILTIN_TOPIC */


/* Begin CONST: ENTITYKIND_USER_UNKNOWN */


/* End CONST: ENTITYKIND_USER_UNKNOWN */


/* Begin CONST: ENTITYKIND_USER_WRITER_WITH_KEY */


/* End CONST: ENTITYKIND_USER_WRITER_WITH_KEY */


/* Begin CONST: ENTITYKIND_USER_WRITER_NO_KEY */


/* End CONST: ENTITYKIND_USER_WRITER_NO_KEY */


/* Begin CONST: ENTITYKIND_USER_READER_NO_KEY */


/* End CONST: ENTITYKIND_USER_READER_NO_KEY */


/* Begin CONST: ENTITYKIND_USER_READER_WITH_KEY */


/* End CONST: ENTITYKIND_USER_READER_WITH_KEY */


/* Begin CONST: ENTITYKIND_OPENDDS_SUBSCRIBER */


/* End CONST: ENTITYKIND_OPENDDS_SUBSCRIBER */


/* Begin CONST: ENTITYKIND_OPENDDS_PUBLISHER */


/* End CONST: ENTITYKIND_OPENDDS_PUBLISHER */


/* Begin CONST: ENTITYKIND_OPENDDS_TOPIC */


/* End CONST: ENTITYKIND_OPENDDS_TOPIC */


/* Begin CONST: ENTITYKIND_OPENDDS_USER */


/* End CONST: ENTITYKIND_OPENDDS_USER */


/* Begin CONST: ENTITYKIND_OPENDDS_NIL_WRITER */


/* End CONST: ENTITYKIND_OPENDDS_NIL_WRITER */


/* Begin STRUCT: GUID_t */

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

OpenDDS_Dcps_Export
void gen_find_size(const OpenDDS::DCPS::GUID_t& stru, size_t& size, size_t& padding);

OpenDDS_Dcps_Export
bool operator<<(Serializer& strm, const OpenDDS::DCPS::GUID_t& stru);

OpenDDS_Dcps_Export
bool operator>>(Serializer& strm, OpenDDS::DCPS::GUID_t& stru);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

template<>
OpenDDS_Dcps_Export
const MetaStruct& getMetaStruct<OpenDDS::DCPS::GUID_t>();
OpenDDS_Dcps_Export
bool gen_skip_over(Serializer& ser, OpenDDS::DCPS::GUID_t*);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#endif

/* End STRUCT: GUID_t */


/* Begin TYPEDEF: GUIDSeq */

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

OpenDDS_Dcps_Export
void gen_find_size(const OpenDDS::DCPS::GUIDSeq& seq, size_t& size, size_t& padding);

OpenDDS_Dcps_Export
bool operator<<(Serializer& strm, const OpenDDS::DCPS::GUIDSeq& seq);

OpenDDS_Dcps_Export
bool operator>>(Serializer& strm, OpenDDS::DCPS::GUIDSeq& seq);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

OpenDDS_Dcps_Export
bool gen_skip_over(Serializer& ser, OpenDDS::DCPS::GUIDSeq*);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#endif

/* End TYPEDEF: GUIDSeq */

/* End MODULE: DCPS */

/* End MODULE: OpenDDS */
#endif /* OPENDDS_IDL_GENERATED_DDSDCPSGUIDTYPESUPPORTIMPL_H_YVK7DR */
