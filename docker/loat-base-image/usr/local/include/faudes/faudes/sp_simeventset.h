/** @file sp_simeventset.h  Eventsets with execution data for simulation */

/*
   Copyright (C) 2008  Thomas Moor
   Exclusive copyright is granted to Klaus Schmidt
*/


#ifndef FAUDES_SP_SIMEVENTSET_H
#define FAUDES_SP_SIMEVENTSET_H

#include "corefaudes.h"
#include "tp_include.h"

namespace faudes {


/** 

@defgroup SimEventAttributes Simulation Event Attributes 

@ingroup SimulatorPlugin 

Attributes to define stochastic and priority properties.

@copydoc faudes::SimEventAttribute

@{ 


*/


/**  
 * Defining data to prioritise events.
 *
 * There are both prefer and avoid priorities. See ProposingExecutor for details.
 * - Positive priority: preferred execution of event, larger number wins
 * - Negative priority: avoid execution of event, smaller number wins
 *
 */
class FAUDES_API SimPriorityEventAttribute {
  public:
  long int mPriority;
  bool operator==(const SimPriorityEventAttribute& rOther) const {
    return mPriority==rOther.mPriority;}
};

/**  
 * Defining data of stochastic behaviour.
 *
 * The occurence of events with stochastic behaviour is scheduled by sampling a random variable.
 * While the attribute class only holds the defining data,  actual semantics 
 * are implemented in the ProposingExecutor.
 *
 * The type indicates the mechanism for sampling the random variable and for scheduling the event.
 * - Extern: the random variable models an external stochastic process.
 * - Trigger:  the random variable is used to narrow down the effective guard interval to a
 *           point. 
 * - Delay:  the random variable models a delay relative to the time while the event is
 *           enabled. 
 *
 * The propability density function may be one of
 * - Exponential
 * - Uniform
 * - Gauss
 * - Vector (arbitrary discrete density, not implemented)
 *
 */
class FAUDES_API SimStochasticEventAttribute {
  public:

  /** When to re-evaluate the random variable */
  typedef enum {Extern, Trigger, Delay} Type;  
  Type mType;             

  /** Convert type to string */
  std::string static TStr(Type type) { 
   if(type == Extern) return "extern"; 
   if(type == Trigger) return "trigger"; 
   if(type == Delay) return "delay"; 
    return "unknown"; 
  };

  /** Pdf to use when evaluating the random variable */
  typedef enum {Exponential,  Uniform, Gauss, Vector} Pdf;  
  Pdf mPdf;              

  /** Pdf parameters */
  std::vector<Float> mParameter; 

  /** Equality operator */
  bool operator==(const SimStochasticEventAttribute& rOther) const {
    return (mType==rOther.mType) && (mPdf==rOther.mPdf) && (mParameter==rOther.mParameter);}

};




/**
 * Attribute for an event in the context of simulation.
 *
 * When simulating one or more generators, at each instance of time 
 * there will be one or more transitions enabled. In order resolve this non-determinism
 * in a defined way, each event may be equipped with either one of the following 
 * properties. 
 *
 * - a SimPriorityEventAttribute to prioritise events
 * - a SimStochasticEventAttribute to determine timing by random variables
 * 
 *
 * Note that the SimEventAttribute just holds the data to define the properties, 
 * a semantic implementation is in faudes::ProposingExecutor. The current implementation
 * also stores simulation state data (ie evaluations of random variables), but
 * this is likely to change in a future revision.
 *
 * As a faudes attribute, SimEventAttribute provides token io and is prepared 
 * for the use in the context of a faudes container. The file format of a set of
 * events equipped with simulation attributes is illustrated by the below example
 * for the simulation of a simple machine:
 * 
 * @code
 *
 * <SimEvents>
 *
 * % machine start: prioritised event with priority 100
 * "alpha"    
 * <Priority> 100  </Priority>  
 *
 * % machine finsh: gauss distributed event with mue=10 and sigma=5, relative to guard
 * "beta"   
 * <Stochastic> +Trigger+  +Gauss+  <Parameter> 10  5  </Parameter> </Stochastic>
 *
 * % break down: gauss distributed event with mue=20 and sigma=5, relative to enabled time
 * "mue"   
 * <Stochastic> +Delay+  +Gauss+  <Parameter> 20  5  </Parameter> </Stochastic>
 *
 * % machine repair: prioritised event with priority 100
 * "lambda"    
 * <Priority> 100  </Priority>  
 *
 * </SimEvents>
 *
 * @endcode
 *
 */

class FAUDES_API SimEventAttribute : public AttributeCFlags {

FAUDES_TYPE_DECLARATION(Void,SimEventAttribute,AttributeCFlags)

  public:

  /** 
   * Default constructor. Construct a SimEventAttribute with 
   * priority 0. 
   */
  SimEventAttribute(void) : AttributeCFlags() { 
    mStochastic=false; mPriority=true; mPriorityAttribute.mPriority=0;};

  /** 
   * Copy constructor.
   */
  SimEventAttribute(const SimEventAttribute& rSrc) : AttributeCFlags() { 
    DoAssign(rSrc); }

  /** 
   * Test for default value 
   * 
   * @return
   *   True, if this attribute has its default value
   */
   virtual bool IsDefault(void) const {return (!mStochastic) &&
     (mPriority && mPriorityAttribute.mPriority==0) && AttributeCFlags::IsDefault(); };

  /** 
   * Test for stochastic property.
   *
   * @return
   *   True, if this attribute defines stochastic behaviour
   */
   bool IsStochastic(void) const {return mStochastic; };

  /** 
   * Test for priority property.
   *
   * @return
   *   True, if this attribute defines priority  behaviour
   */
  bool IsPriority(void) const {return mPriority; };

  /** 
   * Set stochastic behaviour. Define this attribute to
   * indicate the specified stochastic bahaviour.
   *
   * @param rStochasticAttribute
   *     Define stochastic behaviour
   */
  void Stochastic(const SimStochasticEventAttribute&  rStochasticAttribute) {
    mStochasticAttribute= rStochasticAttribute; mStochastic=true; mPriority=false;};


  /** 
   * Set priority behaviour. Define this attribute to
   * indicate execution with the specified priority.
   *
   * @param rPriorityAttribute
   *     Define stochastic behaviour
   */
  void Priority(const SimPriorityEventAttribute& rPriorityAttribute) {
      mPriorityAttribute = rPriorityAttribute; mPriority=true; mStochastic=false; }


  /**  
   * Get priority attribute. Note that the return value
   * is only meaningful if the attribute actually is a priority attribute.
   *
   *  @return
   *    Defining data of this attribute's priority behaviour
   *
   */
  const SimPriorityEventAttribute& Priority(void) const {return mPriorityAttribute; };

  /**  
   * Get stochastic attribute. Note that the return value
   * is only meaningful if the attribute defines stochastic behaviour.
   *
   *  @return
   *    Defining data of this attribute's stochastic behaviour
   *
   */
  const SimStochasticEventAttribute&  Stochastic(void) const {return mStochasticAttribute; };

  /** 
   * Next scheduled occurence of this event relative to current time. This is part of the
   * execution state. It indicates the instance of time for which the respective event is scheduled
   * to occur. Schedules, however, may expire or otherwise become invalid.
   */
  Time::Type mScheduledFor;

  /** 
   * Time at which the recent schedule expires. This is part of the
   * execution state. Once a schedule expires, the event is re-scheduled.
   */
  Time::Type mExpiresAt;

  /** 
   * Amount of time to defer the event. This is part of the
   * execution state. It is used for events of delay type and is a count down type
   * alarm to trigger the event.
   */
  Time::Type mDelayFor;

  /** 
   * Time domain on which the recent schedule was computed. This is part of the
   * execution state. It is used to invalidate schedules for events of trigger type.
   */
  TimeInterval mReferenceInterval;

  /**
   * Debug string, incl state
   *
   */
  std::string Str(void) const; 

protected:

  /** Indicate precense of stochastic behaviour */
  bool mStochastic;

  /** Indicate precense of priority property */
  bool mPriority;

  /** Priority definition data  */
  SimPriorityEventAttribute mPriorityAttribute;

  /** Stochastic definition data  */
  SimStochasticEventAttribute mStochasticAttribute;

  /**
   * Assignment method. 
   *
   * @param rSrcAttr
   *    Source to assign from
   */
  void DoAssign(const SimEventAttribute& rSrcAttr);

  /**
   * Test equality
   *
   * @param rOther
   *    Attribute to compare with
   * @return
   *    True/False
   */
  bool DoEqual(const SimEventAttribute& rOther) const;

  /**
   * Reads the attribute from TokenReader, see AttributeVoid for public wrappers.
   * 
   * If the current token indicates a simulation event section, the method reads all
   * consecutive simulation attributes. Else it does nothing. Exceptions may only be thrown
   * on invalid data within the section. The label argument is ignored, we use hardcoded
   * keywords for the four attributes. The context argument is ignored.
   *
   * @param rTr
   *   TokenReader to read from
   * @param rLabel
   *   Section to read
   * @param pContext
   *   Read context to provide contextual information
   *
   * @exception Exception
   *   - IO error (id 1)
   */
   virtual void DoRead(TokenReader& rTr,const std::string& rLabel="", const Type* pContext=0);
 
  /**
   * Writes the attribute to TokenWriter, see AttributeVoid for public wrappers.
   *
   * Writes all present simulation event attributes to include the defining data. 
   * The label argument is ignored, we use hardcoded keywords. The context argument is ignored.  
   *
   * @param rTw
   *   TokenWriter to write to
   * @param rLabel
   *   Section to write
   * @param pContext
   *   Read context to provide contextual information
   *
   * @exception Exception
   *   - IO error (id 2)
   */
   virtual void DoWrite(TokenWriter& rTw,const std::string& rLabel="", const Type* pContext=0) const;




}; // class SimEventAttribute


/**
 * Typedef for events with simulation attributes.
 */

typedef TaNameSet<SimEventAttribute> sEventSet;

/** @} doxygen group */

} // namespace

#endif
