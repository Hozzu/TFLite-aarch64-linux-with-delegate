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

#ifndef _TAO_IDL_ANYTYPECODE_POLICYA_6BSUME_H_
#define _TAO_IDL_ANYTYPECODE_POLICYA_6BSUME_H_

#include /**/ "ace/pre.h"

#include /**/ "tao/AnyTypeCode/TAO_AnyTypeCode_Export.h"
#include "tao/AnyTypeCode/Any.h"

#include "tao/PolicyC.h"
#include "tao/AnyTypeCode/UShortSeqA.h"
#include "tao/AnyTypeCode/CurrentA.h"
#include "tao/AnyTypeCode/Policy_ForwardA.h"


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_module/module_ch.cpp:45

namespace CORBA
{

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_typecode/typecode_decl.cpp:34

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_PolicyErrorCode;

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_typecode/typecode_decl.cpp:34

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_PolicyError;

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_typecode/typecode_decl.cpp:34

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_InvalidPolicies;

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_typecode/typecode_decl.cpp:34

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_Policy;

// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_module/module_ch.cpp:72

} // module CORBA


// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_exception/any_op_ch.cpp:37

#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace CORBA
{
  

  TAO_AnyTypeCode_Export void operator<<= (::CORBA::Any &, const ::CORBA::PolicyError &); // copying version
  TAO_AnyTypeCode_Export void operator<<= (::CORBA::Any &, ::CORBA::PolicyError*); // noncopying version
  TAO_AnyTypeCode_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ::CORBA::PolicyError *&);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_AnyTypeCode_Export void operator<<= (::CORBA::Any &, const CORBA::PolicyError &); // copying version
TAO_AnyTypeCode_Export void operator<<= (::CORBA::Any &, CORBA::PolicyError*); // noncopying version
TAO_AnyTypeCode_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const CORBA::PolicyError *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_exception/any_op_ch.cpp:37

#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace CORBA
{
  

  TAO_AnyTypeCode_Export void operator<<= (::CORBA::Any &, const ::CORBA::InvalidPolicies &); // copying version
  TAO_AnyTypeCode_Export void operator<<= (::CORBA::Any &, ::CORBA::InvalidPolicies*); // noncopying version
  TAO_AnyTypeCode_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ::CORBA::InvalidPolicies *&);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_AnyTypeCode_Export void operator<<= (::CORBA::Any &, const CORBA::InvalidPolicies &); // copying version
TAO_AnyTypeCode_Export void operator<<= (::CORBA::Any &, CORBA::InvalidPolicies*); // noncopying version
TAO_AnyTypeCode_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const CORBA::InvalidPolicies *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_interface/any_op_ch.cpp:41



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace CORBA
{
  TAO_AnyTypeCode_Export void operator<<= ( ::CORBA::Any &, Policy_ptr); // copying
  TAO_AnyTypeCode_Export void operator<<= ( ::CORBA::Any &, Policy_ptr *); // non-copying
  TAO_AnyTypeCode_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, Policy_ptr &);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_AnyTypeCode_Export void operator<<= (::CORBA::Any &, CORBA::Policy_ptr); // copying
TAO_AnyTypeCode_Export void operator<<= (::CORBA::Any &, CORBA::Policy_ptr *); // non-copying
TAO_AnyTypeCode_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, CORBA::Policy_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

TAO_END_VERSIONED_NAMESPACE_DECL



#include /**/ "ace/post.h"

#endif /* ifndef */