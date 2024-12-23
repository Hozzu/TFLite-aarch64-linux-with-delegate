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

#ifndef _TAO_IDL_DDSDCPSPUBLICATIONC_NPY6UH_H_
#define _TAO_IDL_DDSDCPSPUBLICATIONC_NPY6UH_H_

#include /**/ "ace/pre.h"


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "dds/DCPS/dcps_export.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Basic_Types.h"
#include "tao/ORB_Constants.h"
#include "dds/DCPS/ZeroCopyInfoSeq_T.h"
#include "tao/Object.h"
#include "tao/String_Manager_T.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/VarOut_T.h"
#include "tao/Arg_Traits_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/Any_Insert_Policy_T.h"
#include "tao/Fixed_Size_Argument_T.h"
#include "tao/Var_Size_Argument_T.h"
#include "tao/UB_String_Arguments.h"
#include /**/ "tao/Version.h"
#include /**/ "tao/Versioned_Namespace.h"
#include /**/ "dds/Versioned_Namespace.h"

#include "dds/DdsDcpsInfrastructureC.h"

#if TAO_MAJOR_VERSION != 2 || TAO_MINOR_VERSION != 5 || TAO_MICRO_VERSION != 12
#error This file should be regenerated with TAO_IDL
#endif

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_module/module_ch.cpp:35

namespace DDS
{

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_interface.cpp:748

#if !defined (_DDS_TOPIC__VAR_OUT_CH_)
#define _DDS_TOPIC__VAR_OUT_CH_

  class Topic;
  typedef Topic *Topic_ptr;
  typedef TAO_Objref_Var_T<Topic> Topic_var;
  typedef TAO_Objref_Out_T<Topic> Topic_out;
  

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_interface.cpp:748

#if !defined (_DDS_DOMAINPARTICIPANT__VAR_OUT_CH_)
#define _DDS_DOMAINPARTICIPANT__VAR_OUT_CH_

  class DomainParticipant;
  typedef DomainParticipant *DomainParticipant_ptr;
  typedef TAO_Objref_Var_T<DomainParticipant> DomainParticipant_var;
  typedef TAO_Objref_Out_T<DomainParticipant> DomainParticipant_out;
  

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_interface.cpp:748

#if !defined (_DDS_DATAWRITER__VAR_OUT_CH_)
#define _DDS_DATAWRITER__VAR_OUT_CH_

  class DataWriter;
  typedef DataWriter *DataWriter_ptr;
  typedef TAO_Objref_Var_T<DataWriter> DataWriter_var;
  typedef TAO_Objref_Out_T<DataWriter> DataWriter_out;
  

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_interface.cpp:748

#if !defined (_DDS_PUBLISHER__VAR_OUT_CH_)
#define _DDS_PUBLISHER__VAR_OUT_CH_

  class Publisher;
  typedef Publisher *Publisher_ptr;
  typedef TAO_Objref_Var_T<Publisher> Publisher_var;
  typedef TAO_Objref_Out_T<Publisher> Publisher_out;
  

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_interface.cpp:748

#if !defined (_DDS_DATAWRITERLISTENER__VAR_OUT_CH_)
#define _DDS_DATAWRITERLISTENER__VAR_OUT_CH_

  class DataWriterListener;
  typedef DataWriterListener *DataWriterListener_ptr;
  typedef TAO_Objref_Var_T<DataWriterListener> DataWriterListener_var;
  typedef TAO_Objref_Out_T<DataWriterListener> DataWriterListener_out;
  

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:40

  class OpenDDS_Dcps_Export DataWriterListener
    : public virtual ::DDS::Listener
  
  {
  public:

    // TAO_IDL - Generated from
    // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_type.cpp:304

    typedef DataWriterListener_ptr _ptr_type;
    typedef DataWriterListener_var _var_type;
    typedef DataWriterListener_out _out_type;

    // The static operations.
    static DataWriterListener_ptr _duplicate (DataWriterListener_ptr obj);

    static void _tao_release (DataWriterListener_ptr obj);

    static DataWriterListener_ptr _narrow (::CORBA::Object_ptr obj);
    static DataWriterListener_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static DataWriterListener_ptr _nil (void);

    virtual void on_offered_deadline_missed (
      ::DDS::DataWriter_ptr writer,
      const ::DDS::OfferedDeadlineMissedStatus & status) = 0;

    virtual void on_offered_incompatible_qos (
      ::DDS::DataWriter_ptr writer,
      const ::DDS::OfferedIncompatibleQosStatus & status) = 0;

    virtual void on_liveliness_lost (
      ::DDS::DataWriter_ptr writer,
      const ::DDS::LivelinessLostStatus & status) = 0;

    virtual void on_publication_matched (
      ::DDS::DataWriter_ptr writer,
      const ::DDS::PublicationMatchedStatus & status) = 0;

    // TAO_IDL - Generated from
    // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:137

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    DataWriterListener (void);

    

    virtual ~DataWriterListener (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ACE_UNIMPLEMENTED_FUNC (DataWriterListener (const DataWriterListener &))
#if defined (ACE_HAS_CPP11)
    ACE_UNIMPLEMENTED_FUNC (DataWriterListener (DataWriterListener &&))
#endif /* ACE_HAS_CPP11 */
    ACE_UNIMPLEMENTED_FUNC (DataWriterListener &operator= (const DataWriterListener &))
#if defined (ACE_HAS_CPP11)
    ACE_UNIMPLEMENTED_FUNC (DataWriterListener &operator= (DataWriterListener &&))
#endif /* ACE_HAS_CPP11 */
  };

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_interface.cpp:748

#if !defined (_DDS_PUBLISHERLISTENER__VAR_OUT_CH_)
#define _DDS_PUBLISHERLISTENER__VAR_OUT_CH_

  class PublisherListener;
  typedef PublisherListener *PublisherListener_ptr;
  typedef TAO_Objref_Var_T<PublisherListener> PublisherListener_var;
  typedef TAO_Objref_Out_T<PublisherListener> PublisherListener_out;
  

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:40

  class OpenDDS_Dcps_Export PublisherListener
    : public virtual ::DDS::DataWriterListener
  
  {
  public:

    // TAO_IDL - Generated from
    // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_type.cpp:304

    typedef PublisherListener_ptr _ptr_type;
    typedef PublisherListener_var _var_type;
    typedef PublisherListener_out _out_type;

    // The static operations.
    static PublisherListener_ptr _duplicate (PublisherListener_ptr obj);

    static void _tao_release (PublisherListener_ptr obj);

    static PublisherListener_ptr _narrow (::CORBA::Object_ptr obj);
    static PublisherListener_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static PublisherListener_ptr _nil (void);

    // TAO_IDL - Generated from
    // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:137

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    PublisherListener (void);

    

    virtual ~PublisherListener (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ACE_UNIMPLEMENTED_FUNC (PublisherListener (const PublisherListener &))
#if defined (ACE_HAS_CPP11)
    ACE_UNIMPLEMENTED_FUNC (PublisherListener (PublisherListener &&))
#endif /* ACE_HAS_CPP11 */
    ACE_UNIMPLEMENTED_FUNC (PublisherListener &operator= (const PublisherListener &))
#if defined (ACE_HAS_CPP11)
    ACE_UNIMPLEMENTED_FUNC (PublisherListener &operator= (PublisherListener &&))
#endif /* ACE_HAS_CPP11 */
  };

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:40

  class OpenDDS_Dcps_Export DataWriter
    : public virtual ::DDS::Entity
  
  {
  public:

    // TAO_IDL - Generated from
    // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_type.cpp:304

    typedef DataWriter_ptr _ptr_type;
    typedef DataWriter_var _var_type;
    typedef DataWriter_out _out_type;

    // The static operations.
    static DataWriter_ptr _duplicate (DataWriter_ptr obj);

    static void _tao_release (DataWriter_ptr obj);

    static DataWriter_ptr _narrow (::CORBA::Object_ptr obj);
    static DataWriter_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static DataWriter_ptr _nil (void);

    virtual ::DDS::ReturnCode_t set_qos (
      const ::DDS::DataWriterQos & qos) = 0;

    virtual ::DDS::ReturnCode_t get_qos (
      ::DDS::DataWriterQos & qos) = 0;

    virtual ::DDS::ReturnCode_t set_listener (
      ::DDS::DataWriterListener_ptr a_listener,
      ::DDS::StatusMask mask) = 0;

    virtual ::DDS::DataWriterListener_ptr get_listener (
      void) = 0;

    virtual ::DDS::Topic_ptr get_topic (
      void) = 0;

    virtual ::DDS::Publisher_ptr get_publisher (
      void) = 0;

    virtual ::DDS::ReturnCode_t wait_for_acknowledgments (
      const ::DDS::Duration_t & max_wait) = 0;

    virtual ::DDS::ReturnCode_t get_liveliness_lost_status (
      ::DDS::LivelinessLostStatus & status) = 0;

    virtual ::DDS::ReturnCode_t get_offered_deadline_missed_status (
      ::DDS::OfferedDeadlineMissedStatus & status) = 0;

    virtual ::DDS::ReturnCode_t get_offered_incompatible_qos_status (
      ::DDS::OfferedIncompatibleQosStatus & status) = 0;

    virtual ::DDS::ReturnCode_t get_publication_matched_status (
      ::DDS::PublicationMatchedStatus & status) = 0;

    virtual ::DDS::ReturnCode_t assert_liveliness (
      void) = 0;

    virtual ::DDS::ReturnCode_t get_matched_subscriptions (
      ::DDS::InstanceHandleSeq & subscription_handles) = 0;

    virtual ::DDS::ReturnCode_t get_matched_subscription_data (
      ::DDS::SubscriptionBuiltinTopicData & subscription_data,
      ::DDS::InstanceHandle_t subscription_handle) = 0;

    // TAO_IDL - Generated from
    // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:137

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    DataWriter (void);

    

    virtual ~DataWriter (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ACE_UNIMPLEMENTED_FUNC (DataWriter (const DataWriter &))
#if defined (ACE_HAS_CPP11)
    ACE_UNIMPLEMENTED_FUNC (DataWriter (DataWriter &&))
#endif /* ACE_HAS_CPP11 */
    ACE_UNIMPLEMENTED_FUNC (DataWriter &operator= (const DataWriter &))
#if defined (ACE_HAS_CPP11)
    ACE_UNIMPLEMENTED_FUNC (DataWriter &operator= (DataWriter &&))
#endif /* ACE_HAS_CPP11 */
  };

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:40

  class OpenDDS_Dcps_Export Publisher
    : public virtual ::DDS::Entity
  
  {
  public:

    // TAO_IDL - Generated from
    // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_type.cpp:304

    typedef Publisher_ptr _ptr_type;
    typedef Publisher_var _var_type;
    typedef Publisher_out _out_type;

    // The static operations.
    static Publisher_ptr _duplicate (Publisher_ptr obj);

    static void _tao_release (Publisher_ptr obj);

    static Publisher_ptr _narrow (::CORBA::Object_ptr obj);
    static Publisher_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static Publisher_ptr _nil (void);

    virtual ::DDS::DataWriter_ptr create_datawriter (
      ::DDS::Topic_ptr a_topic,
      const ::DDS::DataWriterQos & qos,
      ::DDS::DataWriterListener_ptr a_listener,
      ::DDS::StatusMask mask) = 0;

    virtual ::DDS::ReturnCode_t delete_datawriter (
      ::DDS::DataWriter_ptr a_datawriter) = 0;

    virtual ::DDS::DataWriter_ptr lookup_datawriter (
      const char * topic_name) = 0;

    virtual ::DDS::ReturnCode_t delete_contained_entities (
      void) = 0;

    virtual ::DDS::ReturnCode_t set_qos (
      const ::DDS::PublisherQos & qos) = 0;

    virtual ::DDS::ReturnCode_t get_qos (
      ::DDS::PublisherQos & qos) = 0;

    virtual ::DDS::ReturnCode_t set_listener (
      ::DDS::PublisherListener_ptr a_listener,
      ::DDS::StatusMask mask) = 0;

    virtual ::DDS::PublisherListener_ptr get_listener (
      void) = 0;

    virtual ::DDS::ReturnCode_t suspend_publications (
      void) = 0;

    virtual ::DDS::ReturnCode_t resume_publications (
      void) = 0;

    virtual ::DDS::ReturnCode_t begin_coherent_changes (
      void) = 0;

    virtual ::DDS::ReturnCode_t end_coherent_changes (
      void) = 0;

    virtual ::DDS::ReturnCode_t wait_for_acknowledgments (
      const ::DDS::Duration_t & max_wait) = 0;

    virtual ::DDS::DomainParticipant_ptr get_participant (
      void) = 0;

    virtual ::DDS::ReturnCode_t set_default_datawriter_qos (
      const ::DDS::DataWriterQos & qos) = 0;

    virtual ::DDS::ReturnCode_t get_default_datawriter_qos (
      ::DDS::DataWriterQos & qos) = 0;

    virtual ::DDS::ReturnCode_t copy_from_topic_qos (
      ::DDS::DataWriterQos & a_datawriter_qos,
      const ::DDS::TopicQos & a_topic_qos) = 0;

    // TAO_IDL - Generated from
    // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:137

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    Publisher (void);

    

    virtual ~Publisher (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ACE_UNIMPLEMENTED_FUNC (Publisher (const Publisher &))
#if defined (ACE_HAS_CPP11)
    ACE_UNIMPLEMENTED_FUNC (Publisher (Publisher &&))
#endif /* ACE_HAS_CPP11 */
    ACE_UNIMPLEMENTED_FUNC (Publisher &operator= (const Publisher &))
#if defined (ACE_HAS_CPP11)
    ACE_UNIMPLEMENTED_FUNC (Publisher &operator= (Publisher &&))
#endif /* ACE_HAS_CPP11 */
  };

// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_module/module_ch.cpp:64

} // module DDS

// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_module/module_ch.cpp:35

namespace OpenDDS
{

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_module/module_ch.cpp:35

  namespace DCPS
  {

    // TAO_IDL - Generated from
    // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_type.cpp:258

    struct PublicationLostStatus;

    typedef
      ::TAO_Var_Var_T<
          PublicationLostStatus
        >
      PublicationLostStatus_var;

    typedef
      ::TAO_Out_T<
          PublicationLostStatus
        >
      PublicationLostStatus_out;

    // TAO_IDL - Generated from
    // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_structure/structure_ch.cpp:48

    struct OpenDDS_Dcps_Export PublicationLostStatus
    {

      // TAO_IDL - Generated from
      // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_type.cpp:304

      
      typedef PublicationLostStatus_var _var_type;
      typedef PublicationLostStatus_out _out_type;
      
      DDS::InstanceHandleSeq subscription_handles;
    };

    // TAO_IDL - Generated from
    // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_typedef/typedef_ch.cpp:510

    typedef PublicationLostStatus PublicationDisconnectedStatus;
    typedef PublicationLostStatus_var PublicationDisconnectedStatus_var;
    typedef PublicationLostStatus_out PublicationDisconnectedStatus_out;

    // TAO_IDL - Generated from
    // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_typedef/typedef_ch.cpp:510

    typedef PublicationLostStatus PublicationReconnectedStatus;
    typedef PublicationLostStatus_var PublicationReconnectedStatus_var;
    typedef PublicationLostStatus_out PublicationReconnectedStatus_out;

    // TAO_IDL - Generated from
    // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_typedef/typedef_ch.cpp:510

    typedef PublicationLostStatus DisassociationStatus;
    typedef PublicationLostStatus_var DisassociationStatus_var;
    typedef PublicationLostStatus_out DisassociationStatus_out;

    // TAO_IDL - Generated from
    // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_interface.cpp:748

#if !defined (_OPENDDS_DCPS_DATAWRITERLISTENER__VAR_OUT_CH_)
#define _OPENDDS_DCPS_DATAWRITERLISTENER__VAR_OUT_CH_

    class DataWriterListener;
    typedef DataWriterListener *DataWriterListener_ptr;
    typedef TAO_Objref_Var_T<DataWriterListener> DataWriterListener_var;
    typedef TAO_Objref_Out_T<DataWriterListener> DataWriterListener_out;
    

#endif /* end #if !defined */

    // TAO_IDL - Generated from
    // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:40

    class OpenDDS_Dcps_Export DataWriterListener
      : public virtual ::DDS::DataWriterListener
    
    {
    public:

      // TAO_IDL - Generated from
      // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_type.cpp:304

      typedef DataWriterListener_ptr _ptr_type;
      typedef DataWriterListener_var _var_type;
      typedef DataWriterListener_out _out_type;

      // The static operations.
      static DataWriterListener_ptr _duplicate (DataWriterListener_ptr obj);

      static void _tao_release (DataWriterListener_ptr obj);

      static DataWriterListener_ptr _narrow (::CORBA::Object_ptr obj);
      static DataWriterListener_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
      static DataWriterListener_ptr _nil (void);

      virtual void on_publication_disconnected (
        ::DDS::DataWriter_ptr reader,
        const ::OpenDDS::DCPS::PublicationDisconnectedStatus & status) = 0;

      virtual void on_publication_reconnected (
        ::DDS::DataWriter_ptr reader,
        const ::OpenDDS::DCPS::PublicationReconnectedStatus & status) = 0;

      virtual void on_publication_lost (
        ::DDS::DataWriter_ptr writer,
        const ::OpenDDS::DCPS::PublicationLostStatus & status) = 0;

      // TAO_IDL - Generated from
      // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:137

      virtual ::CORBA::Boolean _is_a (const char *type_id);
      virtual const char* _interface_repository_id (void) const;
      virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
    
    protected:
      // Abstract or local interface only.
      DataWriterListener (void);

      

      virtual ~DataWriterListener (void);
    
    private:
      // Private and unimplemented for concrete interfaces.
      ACE_UNIMPLEMENTED_FUNC (DataWriterListener (const DataWriterListener &))
#if defined (ACE_HAS_CPP11)
      ACE_UNIMPLEMENTED_FUNC (DataWriterListener (DataWriterListener &&))
#endif /* ACE_HAS_CPP11 */
      ACE_UNIMPLEMENTED_FUNC (DataWriterListener &operator= (const DataWriterListener &))
#if defined (ACE_HAS_CPP11)
      ACE_UNIMPLEMENTED_FUNC (DataWriterListener &operator= (DataWriterListener &&))
#endif /* ACE_HAS_CPP11 */
    };
  
  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_module/module_ch.cpp:64
  
  } // module OpenDDS::DCPS

// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_module/module_ch.cpp:64

} // module OpenDDS

// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:66


OPENDDS_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:945

  template<>
  class Arg_Traits< ::OpenDDS::DCPS::PublicationLostStatus>
    : public
        Var_Size_Arg_Traits_T<
            ::OpenDDS::DCPS::PublicationLostStatus,
            TAO::Any_Insert_Policy_Noop
          >
  {
  };
}

TAO_END_VERSIONED_NAMESPACE_DECL


OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_traits.cpp:60


OPENDDS_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_DDS_TOPIC__TRAITS_)
#define _DDS_TOPIC__TRAITS_

  template<>
  struct OpenDDS_Dcps_Export Objref_Traits< ::DDS::Topic>
  {
    static ::DDS::Topic_ptr duplicate (
        ::DDS::Topic_ptr p);
    static void release (
        ::DDS::Topic_ptr p);
    static ::DDS::Topic_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::DDS::Topic_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_DDS_DOMAINPARTICIPANT__TRAITS_)
#define _DDS_DOMAINPARTICIPANT__TRAITS_

  template<>
  struct OpenDDS_Dcps_Export Objref_Traits< ::DDS::DomainParticipant>
  {
    static ::DDS::DomainParticipant_ptr duplicate (
        ::DDS::DomainParticipant_ptr p);
    static void release (
        ::DDS::DomainParticipant_ptr p);
    static ::DDS::DomainParticipant_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::DDS::DomainParticipant_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_DDS_DATAWRITERLISTENER__TRAITS_)
#define _DDS_DATAWRITERLISTENER__TRAITS_

  template<>
  struct OpenDDS_Dcps_Export Objref_Traits< ::DDS::DataWriterListener>
  {
    static ::DDS::DataWriterListener_ptr duplicate (
        ::DDS::DataWriterListener_ptr p);
    static void release (
        ::DDS::DataWriterListener_ptr p);
    static ::DDS::DataWriterListener_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::DDS::DataWriterListener_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_DDS_PUBLISHERLISTENER__TRAITS_)
#define _DDS_PUBLISHERLISTENER__TRAITS_

  template<>
  struct OpenDDS_Dcps_Export Objref_Traits< ::DDS::PublisherListener>
  {
    static ::DDS::PublisherListener_ptr duplicate (
        ::DDS::PublisherListener_ptr p);
    static void release (
        ::DDS::PublisherListener_ptr p);
    static ::DDS::PublisherListener_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::DDS::PublisherListener_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_DDS_DATAWRITER__TRAITS_)
#define _DDS_DATAWRITER__TRAITS_

  template<>
  struct OpenDDS_Dcps_Export Objref_Traits< ::DDS::DataWriter>
  {
    static ::DDS::DataWriter_ptr duplicate (
        ::DDS::DataWriter_ptr p);
    static void release (
        ::DDS::DataWriter_ptr p);
    static ::DDS::DataWriter_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::DDS::DataWriter_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_DDS_PUBLISHER__TRAITS_)
#define _DDS_PUBLISHER__TRAITS_

  template<>
  struct OpenDDS_Dcps_Export Objref_Traits< ::DDS::Publisher>
  {
    static ::DDS::Publisher_ptr duplicate (
        ::DDS::Publisher_ptr p);
    static void release (
        ::DDS::Publisher_ptr p);
    static ::DDS::Publisher_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::DDS::Publisher_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_OPENDDS_DCPS_DATAWRITERLISTENER__TRAITS_)
#define _OPENDDS_DCPS_DATAWRITERLISTENER__TRAITS_

  template<>
  struct OpenDDS_Dcps_Export Objref_Traits< ::OpenDDS::DCPS::DataWriterListener>
  {
    static ::OpenDDS::DCPS::DataWriterListener_ptr duplicate (
        ::OpenDDS::DCPS::DataWriterListener_ptr p);
    static void release (
        ::OpenDDS::DCPS::DataWriterListener_ptr p);
    static ::OpenDDS::DCPS::DataWriterListener_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::OpenDDS::DCPS::DataWriterListener_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL


OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_visitor_structure/cdr_op_ch.cpp:43



OPENDDS_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

OpenDDS_Dcps_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const OpenDDS::DCPS::PublicationLostStatus &);
OpenDDS_Dcps_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, OpenDDS::DCPS::PublicationLostStatus &);

TAO_END_VERSIONED_NAMESPACE_DECL


OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// /home/shan/git/bsp/adcm_bsp_sa8195/sources/apps/apps_proc/poky/build/tmp-glibc/work/x86_64-linux/opendds-native/1.0+gitAUTOINC+0810ffc3f5-r7/git/ACE_TAO/TAO/TAO_IDL/be/be_codegen.cpp:1686


OPENDDS_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "DdsDcpsPublicationC.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"

#endif /* ifndef */

