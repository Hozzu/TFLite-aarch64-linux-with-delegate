// -*- C++ -*-
/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.5.12
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       https://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     https://www.dre.vanderbilt.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_codegen.cpp:777

#ifndef _TAO_IDL_STRINGVALUEA_LRUFQT_H_
#define _TAO_IDL_STRINGVALUEA_LRUFQT_H_

#include /**/ "ace/pre.h"

#include /**/ "tao/Valuetype/valuetype_export.h"
#include "tao/AnyTypeCode/Any.h"

#include "tao/Valuetype/StringValueC.h"


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_module/module_ch.cpp:45

namespace CORBA
{

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_typecode/typecode_decl.cpp:34

  extern TAO_Valuetype_Export ::CORBA::TypeCode_ptr const _tc_StringValue;

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_typecode/typecode_decl.cpp:34

  extern TAO_Valuetype_Export ::CORBA::TypeCode_ptr const _tc_WStringValue;

// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_module/module_ch.cpp:72

} // module CORBA


// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_valuebox/any_op_ch.cpp:43



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace CORBA
{
  TAO_Valuetype_Export void operator<<= ( ::CORBA::Any &, StringValue *); // copying
  TAO_Valuetype_Export void operator<<= ( ::CORBA::Any &, StringValue **); // non-copying
  TAO_Valuetype_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, StringValue *&);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Valuetype_Export void operator<<= (::CORBA::Any &, CORBA::StringValue *); // copying
TAO_Valuetype_Export void operator<<= (::CORBA::Any &, CORBA::StringValue **); // non-copying
TAO_Valuetype_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, CORBA::StringValue *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_valuebox/any_op_ch.cpp:43



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace CORBA
{
  TAO_Valuetype_Export void operator<<= ( ::CORBA::Any &, WStringValue *); // copying
  TAO_Valuetype_Export void operator<<= ( ::CORBA::Any &, WStringValue **); // non-copying
  TAO_Valuetype_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, WStringValue *&);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Valuetype_Export void operator<<= (::CORBA::Any &, CORBA::WStringValue *); // copying
TAO_Valuetype_Export void operator<<= (::CORBA::Any &, CORBA::WStringValue **); // non-copying
TAO_Valuetype_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, CORBA::WStringValue *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

TAO_END_VERSIONED_NAMESPACE_DECL



#include /**/ "ace/post.h"

#endif /* ifndef */