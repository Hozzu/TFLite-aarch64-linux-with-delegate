/* -*- C++ -*- */
/* Generated by /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/aarch64-oe-linux/opendds/1.0+gitAUTOINC+0810ffc3f5-r7/recipe-sysroot-native/usr/bin/DDS_HOST_ROOT/bin/opendds_idl version 3.13 (ACE version 6.5.12) running on input file CorbaSeq/WCharSeq.idl */
#ifndef OPENDDS_IDL_GENERATED_WCHARSEQTYPESUPPORTIMPL_H_GU6KKO
#define OPENDDS_IDL_GENERATED_WCHARSEQTYPESUPPORTIMPL_H_GU6KKO
#include "tao/WCharSeqC.h"
#include "dds/DCPS/Definitions.h"
#include "dds/DdsDcpsC.h"
#include "dds/DCPS/Serializer.h"
#include "dds/DCPS/dcps_export.h"


/* Begin MODULE: CORBA */


/* End MODULE: CORBA */


/* Begin MODULE: CORBA */



/* Begin TYPEDEF: WCharSeq */

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

OpenDDS_Dcps_Export
void gen_find_size(const CORBA::WCharSeq& seq, size_t& size, size_t& padding);

OpenDDS_Dcps_Export
bool operator<<(Serializer& strm, const CORBA::WCharSeq& seq);

OpenDDS_Dcps_Export
bool operator>>(Serializer& strm, CORBA::WCharSeq& seq);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

OpenDDS_Dcps_Export
bool gen_skip_over(Serializer& ser, CORBA::WCharSeq*);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#endif

/* End TYPEDEF: WCharSeq */

/* End MODULE: CORBA */
#endif /* OPENDDS_IDL_GENERATED_WCHARSEQTYPESUPPORTIMPL_H_GU6KKO */