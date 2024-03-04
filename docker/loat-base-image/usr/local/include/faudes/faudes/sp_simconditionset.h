/** @file sp_simconditionset.h  Set of named simulation conditions */

/*
   Copyright (C) 2008  Thomas Moor
   Exclusive copyright is granted to Klaus Schmidt
*/


#include "corefaudes.h"
#include "sp_densityfnct.h"


#ifndef FAUDES_SP_SIMCONDITIONSET_H
#define FAUDES_SP_SIMCONDITIONSET_H

namespace faudes {

/** 

@defgroup SimConditionAttributes Simulation Condition Attributes 

@ingroup SimulatorPlugin 

Attributes to define simulation conditions used for statistic analysis
of simulation runs.

@copydoc faudes::AttributeSimCondition

@{ 

*/

/**  
 * Defining data of event based simulation condition
 *
 * An event based condition has a set of start events and a set of
 * stop events. It becomes satisfied when a start event occurs and it 
 * becomes unsatisfied when a stop event occurs. Thus, when start or stop
 * events fail to alternate, the first event of the respective type is relevant.
 *
 */
class FAUDES_API SimEventCondition {
 public:
  EventSet mStart;
  EventSet mStop;
  bool operator==(const SimEventCondition rOther) const { 
    return mStart==rOther.mStart && mStop==rOther.mStop;}; 
};

/**  
 * Defining data of state based simulation condition
 *
 * A state based condition has a set of states per generator an is satisfied
 * while the components of the current discrete state vector are within the
 * respective set. A flag indicates whether each or some component 
 * must comply with the state set to satisfy the condition.
 * 
 * Note: Since state indices are local to generators, a SimStateCondition 
 * is only meaningful in the context of a particular ParallelExecutor. 
 *
 */

// state based condition
class  FAUDES_API SimStateCondition {
public:
  bool mAllFlag;
  std::vector<StateSet> mStateSets;
  bool operator==(const SimStateCondition rOther) const { 
    return mAllFlag==rOther.mAllFlag && mStateSets==rOther.mStateSets;}; 
};


/**
 * Attribute for a simulation condition
 *
 * In order to extract statistical data from a simulation by a LoggingExecutor
 * or some derived class, so called simulation conditions
 * are defined. At any instance of time, a condition is satisfied or
 * dissatisfied. Statistical data can then be requested regarding 
 * the period and duration of each condition. Currently, two
 * types of conditions are available:
 *
 * - SimStateCondition addresses conditions of the current state
 * - SimEventCondition addresses the external event sequence.
 *
 * A Condition may be flagged as a break condition to halt simulation
 * when satisfied. A condition may be enabled for tracking or not.
 *
 * The class AttributeSimCondition summarizes all data to represent
 * faudes simulation conditions. It also holds some state of the condition
 * wrt execution and provides an interface for sampling. The latter 
 * may be seperated to a different class in a future revision. The class
 * AttributeSimCondition does, however, not implement any test whether
 * or not a condition is satisfied. This is done by the LoggingExecutor.
 *
 * As a faudes attribute, conditions can be referenced by 
 * names via the std faudes container TaNameSet. For token io, a
 * ParallelExecutor should be provided as context to access symbolic
 * state names. The file format of a set of
 * events equipped with condition attributes is illustrated by the below example
 * to monitor some performance aspects of one simple machine:
 * 
 * @code
 *
 * <Conditions>
 *
 * % monitor when the machine is idle
 * "IdleCond"      
 * <StateCondition>
 * <StateSet> "idle" </StateSet>
 * </StateCondition>
 *
 * % halt simulation  when the machine is down
 * % however, the condition is disabled
 * "DownCond"      
 * +Break+     
 * +Disabled+     
 * <StateCondition>
 * <StateSet> "down" </StateSet>
 * </StateCondition>
 *
 * % monitor how long the prozessing one work piece takes
 * "OperationCond"     
 * <EventCondition>
 * <StartEvents>  "alpha" </StartEvents>
 * <StopEvents>   "beta"  </StopEvents>
 * </EventCondition>
 *
 * </Conditions>
 *
 * @endcode
 */

class FAUDES_API AttributeSimCondition : public AttributeFlags {

FAUDES_TYPE_DECLARATION(Void,AttributeSimCondition,AttributeFlags)

  public:

  /** Convenience typedef */
  typedef std::vector<StateSet>::iterator Iterator;
  typedef std::vector<StateSet>::const_iterator CIterator;

  /** 
   * Default constructor. Constructs a AttributeSimCondition of 
   * with no type ie neither state condition nor event condition.
   */
  AttributeSimCondition(void);

  /** 
   * Copy constructor.
   * with no type ie neither state condition nor event condition.
   */
  AttributeSimCondition(const AttributeSimCondition& rOther);

  /** 
   * Test for default value 
   * 
   * @return
   *   True, if this attribute has its default value
   */
  virtual bool IsDefault(void) const {
    return !mEventCondition && !mStateCondition && (mFlags==mDefSCFlags); };


  /** 
   * Test for state condition.
   *
   * @return
   *   True, if this attribute defines a state condition
   */
  bool IsStateCondition(void) const {return mStateCondition; };

  /** 
   * Test for event condition.
   *
   * @return
   *   True, if this attribute defines an event condition
   */
  bool IsEventCondition(void) const {return mEventCondition; };

  /** 
   * Test for break condition.
   *
   * @return
   *   True, if this condition halts simulation.
   */
  bool Breakpoint(void) const {return ((mFlags & mBreakpointFlag) != 0); };

  /** 
   * Test whether condition is enabled.
   *
   * @return
   *   True, if this condition is monitored during simulation.
   */
  bool Enabled(void) const { return ((mFlags & mEnabledFlag) != 0); };

  /** 
   * Set state condition attribute. Define this attribute to
   * represent the specified state condition.
   *
   * @param rStateConditionAttribute
   *     Define state condition
   */
  void StateCondition(const SimStateCondition&  rStateConditionAttribute) 
    {mStateConditionAttribute=rStateConditionAttribute; mStateCondition=true; mEventCondition=false;
    for(Idx i=0; i<mStateConditionAttribute.mStateSets.size(); i++) 
      mStateConditionAttribute.mStateSets.at(i).Name("StateSet");
  };

  /** 
   * Set event condition attribute. Define this attribute to
   * represent the specified event condition.
   *
   * @param rEventConditionAttribute
   *     Define event condition
   */
  void EventCondition(const SimEventCondition&  rEventConditionAttribute) 
    {mEventConditionAttribute=rEventConditionAttribute; mEventCondition=true; mStateCondition=false;};

  /** 
   * Set break flag.
   * 
   * @param on
   *   True, to indicate that this condition halts simulation.
   */
  void Breakpoint(bool on) { if(on) mFlags |= mBreakpointFlag; else mFlags &= ~mBreakpointFlag; };

  /** 
   * Set enabled flag.
   * 
   * @param on
   *   True, to indicate that this condition is to be monitored during simulation.
   */
  void Enabled(bool on) { if(on) mFlags |= mEnabledFlag; else mFlags &= ~mEnabledFlag; };

  /**  
   * Get event condition. Note that the attribute can only return
   * meaningful data if it actually is an event condition.  
   *
   *  @return
   *    Defining data of this attribute's event condition.
   *
   */
  const SimEventCondition& EventCondition(void) const {return mEventConditionAttribute; };

  /**  
   * Get state condition. Note that the attribute can only return
   * meaningful data if it actually is an state condition.  
   *
   *  @return
   *    Defining data of this attribute's state condition.
   *
   */
  const SimStateCondition& StateCondition(void) const {return mStateConditionAttribute; };

  /**
   *  Reset conditions execution state. The execution state of a condition
   *  consists of all data accumulated during simulation eg statistical data
   *  and whether or not the condition is currently satisfied. The execution state
   *  resides in the attribute for pragmatic reasons only.
   */
  void Reset(void) 
  { mSatisfied=false; mActivationTime=-1; mSamplesPeriod.Clear(); mSamplesDuration.Clear(); };

  /** 
   * Test whether the condition is currently satisfied. This is part
   * of the condition execution state. 
   *
   * @return
   *   True, if the conditions is considered satisfied
   */
  bool Satisfied(void) const { return mSatisfied; };

  /** 
   * Set the condition to be satisfied. This is part
   * of the condition execution state. Since it is the executor
   * that determines whether a condition is satisfied, and since
   * the condition state resides in the attribute, the executor
   * is meant to notify state changes.
   *
   * @param on
   *   True, if the conditions is considered satisfied
   * @param now
   *   Time at which the state change occures
   */
  void Satisfied(bool on, Time::Type now);
   
  /** 
   * Sampled period, at which this condition becomes satisfied. 
   */
  SampledDensityFunction mSamplesPeriod;

  /** 
   * Sampled durations, for which this condition remains satisfied. 
   */
  SampledDensityFunction mSamplesDuration;

  // flag masks for the three properties
  const static fType mEnabledFlag      =0x01;
  const static fType mBreakpointFlag   =0x02;

protected:
 
  /** Indicate precense of a event condition */
  bool mEventCondition;

  /** Indicate precense of a state condition */
  bool mStateCondition;

  /** Event based condition data */
  SimEventCondition mEventConditionAttribute;

  /** State based condition data */
  SimStateCondition mStateConditionAttribute;

  /** Condotion state: recorded as satisfied */
  bool mSatisfied;

  /** Condition state: when last satisfied became true */
  Time::Type mActivationTime;
   

 protected:

  /**
   * Assignment method. 
   *
   * @param rSrcAttr
   *    Source to assign from
   */
  void DoAssign(const AttributeSimCondition& rSrcAttr);

  /**
   * Equality method. 
   *
   * @param rAttr
   *    Source to compare with
   */
  bool DoEqual(const AttributeSimCondition& rAttr) const;

  /**
   * Reads the attribute from TokenReader, see AttributeVoid for public wrappers.
   * 
   * If the current token indicates a condition section, the method reads the  
   * condition data from that section. Else it does nothing. Exceptions may only be thrown
   * on invalid data within the condition section. The label argiment is ignored, we 
   * use hardcoded labled "EventCondition" and "StateCondition" to figure the type of 
   * condition. When a ParallelExecutor is provided as context, it is used to interpret
   * symbolc state names of a state condition.
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
  virtual void DoRead(TokenReader& rTr, const std::string& rLabel="", const Type* pContext=0);
 
  /**
   * Writes the attribute to TokenWriter, see AttributeVoid for public wrappers.
   *
   * Writes a condition section to include data on state- or event-condition. The label argument
   * is ignored, we use hardcoded keywords "EventCondition" and StateCondition". When a 
   * ParallelExecutor is provided as context, it state conditions are written with 
   * symbolic state names.
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

private:

  /** Overall default value */
  const static fType mDefSCFlags  =0x01;

  /** All flags used by CFlags */
  const static fType mAllSCFlags  =0x03;



}; // class AttributeSimCondition


/**
 * Set of simulation named conditions. 
 *
 * Note: we currently share a symboltabel with the global
 * event set. This will definitely change in a future revision.
 */

class FAUDES_API SimConditionSet : public TaNameSet<AttributeSimCondition> {

FAUDES_TYPE_DECLARATION(Void,SimConditionSet,TaNameSet<AttributeSimCondition>)

 public:

  /** Default constructor */
  SimConditionSet(void);

  /** Copy constructor */
  SimConditionSet(const SimConditionSet& rOtherSet);

  /**  Virtual destructor */
  virtual ~SimConditionSet(void) {};

  /** Test condition for enabled */
  bool Enabled(Idx cond) const { return Attribute(cond).Enabled(); };

  /** Set condition enabled */
  void Enabled(Idx cond, bool on) { Attributep(cond)->Enabled(on); };

  /** Get set of enabled conditions */
  SimConditionSet EnabledConditions(void);

  /** Reset all condition states */
  void Reset(void);

protected:

 /**
  * Assign from other condition set. 
  *
  * @param rSourceSet
  *   Destination to copy from
  * @return
  *   ref to this set
  */
 void DoAssign(const SimConditionSet& rSourceSet) {
   TaNameSet<AttributeSimCondition>::DoAssign(rSourceSet); };


 

};



/** @} doxygen group */

} // namespace

#endif
