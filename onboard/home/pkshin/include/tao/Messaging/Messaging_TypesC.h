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
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_codegen.cpp:149

#ifndef _TAO_PIDL_MESSAGING_TYPESC_8RHL0M_H_
#define _TAO_PIDL_MESSAGING_TYPESC_8RHL0M_H_

#include /**/ "ace/pre.h"


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "tao/Messaging/messaging_export.h"
#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/Basic_Types.h"
#include "tao/AnyTypeCode/Policy_ForwardA.h"
#include "tao/Arg_Traits_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/Any_Insert_Policy_T.h"
#include "tao/Fixed_Size_Argument_T.h"
#include "tao/Var_Size_Argument_T.h"
#include "tao/Object_Argument_T.h"
#include /**/ "tao/Version.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "tao/Policy_ForwardC.h"

#if TAO_MAJOR_VERSION != 2 || TAO_MINOR_VERSION != 5 || TAO_MICRO_VERSION != 12
#error This file should be regenerated with TAO_IDL
#endif

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_module/module_ch.cpp:35

namespace Messaging
{

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_constant/constant_ch.cpp:35

  const CORBA::ULong REBIND_POLICY_TYPE = 23U;

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_constant/constant_ch.cpp:35

  const CORBA::ULong SYNC_SCOPE_POLICY_TYPE = 24U;

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_constant/constant_ch.cpp:35

  const CORBA::ULong REQUEST_PRIORITY_POLICY_TYPE = 25U;

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_constant/constant_ch.cpp:35

  const CORBA::ULong REPLY_PRIORITY_POLICY_TYPE = 26U;

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_constant/constant_ch.cpp:35

  const CORBA::ULong REQUEST_START_TIME_POLICY_TYPE = 27U;

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_constant/constant_ch.cpp:35

  const CORBA::ULong REQUEST_END_TIME_POLICY_TYPE = 28U;

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_constant/constant_ch.cpp:35

  const CORBA::ULong REPLY_START_TIME_POLICY_TYPE = 29U;

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_constant/constant_ch.cpp:35

  const CORBA::ULong REPLY_END_TIME_POLICY_TYPE = 30U;

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_constant/constant_ch.cpp:35

  const CORBA::ULong RELATIVE_REQ_TIMEOUT_POLICY_TYPE = 31U;

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_constant/constant_ch.cpp:35

  const CORBA::ULong RELATIVE_RT_TIMEOUT_POLICY_TYPE = 32U;

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_constant/constant_ch.cpp:35

  const CORBA::ULong ROUTING_POLICY_TYPE = 33U;

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_constant/constant_ch.cpp:35

  const CORBA::ULong MAX_HOPS_POLICY_TYPE = 34U;

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_constant/constant_ch.cpp:35

  const CORBA::ULong QUEUE_ORDER_POLICY_TYPE = 35U;

// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_module/module_ch.cpp:64

} // module Messaging

// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:66


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{
}

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_traits.cpp:60


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_codegen.cpp:1686


TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ifndef */
