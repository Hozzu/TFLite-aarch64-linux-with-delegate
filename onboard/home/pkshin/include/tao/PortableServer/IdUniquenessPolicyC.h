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

#ifndef _TAO_PIDL_IDUNIQUENESSPOLICYC_HZ1EJZ_H_
#define _TAO_PIDL_IDUNIQUENESSPOLICYC_HZ1EJZ_H_

#include /**/ "ace/pre.h"


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "tao/PortableServer/portableserver_export.h"
#include "tao/Basic_Types.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Arg_Traits_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/Any_Insert_Policy_T.h"
#include "tao/Basic_Argument_T.h"
#include "tao/Fixed_Size_Argument_T.h"
#include "tao/Var_Size_Argument_T.h"
#include "tao/Object_Argument_T.h"
#include /**/ "tao/Version.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "tao/PolicyC.h"

#if TAO_MAJOR_VERSION != 2 || TAO_MINOR_VERSION != 5 || TAO_MICRO_VERSION != 12
#error This file should be regenerated with TAO_IDL
#endif

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_module/module_ch.cpp:35

namespace PortableServer
{

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_enum/enum_ch.cpp:44

  enum IdUniquenessPolicyValue
  {
    UNIQUE_ID,
    MULTIPLE_ID
  };

  typedef IdUniquenessPolicyValue &IdUniquenessPolicyValue_out;

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_interface.cpp:748

#if !defined (_PORTABLESERVER_IDUNIQUENESSPOLICY__VAR_OUT_CH_)
#define _PORTABLESERVER_IDUNIQUENESSPOLICY__VAR_OUT_CH_

  class IdUniquenessPolicy;
  typedef IdUniquenessPolicy *IdUniquenessPolicy_ptr;
  typedef TAO_Objref_Var_T<IdUniquenessPolicy> IdUniquenessPolicy_var;
  typedef TAO_Objref_Out_T<IdUniquenessPolicy> IdUniquenessPolicy_out;
  

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:40

  class TAO_PortableServer_Export IdUniquenessPolicy
    : public virtual ::CORBA::Policy
  
  {
  public:

    // TAO_IDL - Generated from
    // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_type.cpp:304

    typedef IdUniquenessPolicy_ptr _ptr_type;
    typedef IdUniquenessPolicy_var _var_type;
    typedef IdUniquenessPolicy_out _out_type;

    // The static operations.
    static IdUniquenessPolicy_ptr _duplicate (IdUniquenessPolicy_ptr obj);

    static void _tao_release (IdUniquenessPolicy_ptr obj);

    static IdUniquenessPolicy_ptr _narrow (::CORBA::Object_ptr obj);
    static IdUniquenessPolicy_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static IdUniquenessPolicy_ptr _nil (void);

    virtual ::PortableServer::IdUniquenessPolicyValue value (
      void) = 0;

    virtual ::CORBA::Policy_ptr copy (
      void) = 0;

    virtual void destroy (
      void) = 0;

    // TAO_IDL - Generated from
    // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:137

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    IdUniquenessPolicy (void);

    

    virtual ~IdUniquenessPolicy (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ACE_UNIMPLEMENTED_FUNC (IdUniquenessPolicy (const IdUniquenessPolicy &))
#if defined (ACE_HAS_CPP11)
    ACE_UNIMPLEMENTED_FUNC (IdUniquenessPolicy (IdUniquenessPolicy &&))
#endif /* ACE_HAS_CPP11 */
    ACE_UNIMPLEMENTED_FUNC (IdUniquenessPolicy &operator= (const IdUniquenessPolicy &))
#if defined (ACE_HAS_CPP11)
    ACE_UNIMPLEMENTED_FUNC (IdUniquenessPolicy &operator= (IdUniquenessPolicy &&))
#endif /* ACE_HAS_CPP11 */
  };

// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_module/module_ch.cpp:64

} // module PortableServer

// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:66


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:902

  template<>
  class Arg_Traits< ::PortableServer::IdUniquenessPolicyValue>
    : public
        Basic_Arg_Traits_T<
            ::PortableServer::IdUniquenessPolicyValue,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };
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

#if !defined (_PORTABLESERVER_IDUNIQUENESSPOLICY__TRAITS_)
#define _PORTABLESERVER_IDUNIQUENESSPOLICY__TRAITS_

  template<>
  struct TAO_PortableServer_Export Objref_Traits< ::PortableServer::IdUniquenessPolicy>
  {
    static ::PortableServer::IdUniquenessPolicy_ptr duplicate (
        ::PortableServer::IdUniquenessPolicy_ptr p);
    static void release (
        ::PortableServer::IdUniquenessPolicy_ptr p);
    static ::PortableServer::IdUniquenessPolicy_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::PortableServer::IdUniquenessPolicy_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_enum/cdr_op_ch.cpp:34



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_PortableServer_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &strm, PortableServer::IdUniquenessPolicyValue _tao_enumerator);
TAO_PortableServer_Export ::CORBA::Boolean operator>> (TAO_InputCDR &strm, PortableServer::IdUniquenessPolicyValue &_tao_enumerator);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_codegen.cpp:1686


TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ifndef */
