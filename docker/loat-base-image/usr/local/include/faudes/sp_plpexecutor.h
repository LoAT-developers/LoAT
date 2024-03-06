/** @file sp_plpexecutor.h Executor that proposes transitions to execute */

/* 
   FAU Discrete Event Systems Library (libfaudes)

   The proposing executor is based on the stochastic executor, which
   has been developped by Christoph Doerr as part of his thesis project.
  
   Copyright (C) 2008  Thomas Moor
   Copyright (C) 2007  Christoph Doerr
   Exclusive copyright is granted to Thomas Moor

   todo:
   - compile simevent set to one vector per type to speed up iterations
   - fix vector pdfs  
   - test with elementary examples
   - use compiled interval time constraints

*/

#ifndef FAUDES_SP_PLPEXECUTOR_H
#define FAUDES_SP_PLPEXECUTOR_H

#include "corefaudes.h"
#include "tp_include.h"
#include "sp_lpexecutor.h" 
#include "sp_simeventset.h"
#include "sp_random.h"


namespace faudes {
	
/**
 * Executer that proposes which transition to execute.
 *
 * \section SecSimulatorPLPEX1 Priority and Stochastic Semantics
 *
 * Whilst the LoggingExecutor (and all lower level executors) is aware of which transitions are
 * enabled, the ProposingExecutor actually proposes either one particular transition for execution or
 * a particular amount of time to let pass. The proposal refers to additional semantics
 * parametrised by data from SimEventAttribute. The decision procedure is organized in four stages, 
 * were the first stage that yields a proposal wins:
 * 
 * 1.) SimPriorityEventAttribute, positive priority
 * - if one or more events with positive priority are enabled, those with maximum priority
 *   form the candidate set
 * - if the candidate set is non-emty propose one event by random (uniformly distributed) to
 *   be executed immediately
 *
 * 2.) SimStochasticEventAttribute, stochastic timing
 * - if within the interval at which the set of enabled events remains constant (EnabledInterval)
 *   an event with stochastic timing is scheduled to occur, the earliest of such events form the candidate set.
 * - if the candidate set is non-emty propose one event by random (uniformly distributed) to be
 *   executed at the scheduled clock time.
 * 
 * 3.) passing by clock time
 * - if the EnabledInterval is of positive duration, let this duration pass by.
 * - if the EnabledInterval is of infinite duration, let all clock time pass and stop the simulation
 *
 * 4.) SimPriorityEventAttribute, negative priority
 * - if one or more events with negative priority are enabled, those with maximum priority
 *   form the candidate set
 * - if the candidate set is non-emty propose one event by random (uniformly distributed) to
 *   be executed immediately
 * 
 * Note that the above procedure will never come up with a proposal that fails to satisfy
 * invariant and guard conditions. In this sense, the above procedure is compliant with Alur semantics
 * of timed automata. 
 *
 * If the above procedure fails to indicate a transition to execute or clock time to let pass, the
 * system is deadlocked. If the procedure sticks with case 3) and infinite duration, it might be
 * either life locked (no enabled events) or just unwilling/unable to execute a negative priority event.
 * The latter case can be used for sensor events in a hardware-in-the-loop simulation.
 *
 *
 * \section SecSimulatorPLPEX2 Scheduling Stochastic Events
 *
 * The mechnism to schedule events with stochastic timing comes in three flavors.
 * - SimStochasticEventAttribute::Extern 
 * The random variable models an external stochastic process. A sample is taken
 * when the executor is reset to determine the first scheduled occurence. The schedule expires
 * when it matched the current clock time, regardless whether the event is executed or not. When the
 * schedule expires, a new sample is taken to determine the next scheduled occurence. 
 * -  SimStochasticEventAttribute::Trigger  
 * The random variable is used to narrow down the effective guard interval to a
 * point. By "effective guard interval" we refer to the interval of time in which the guard is satisfied 
 * w.r.t. the current timed state.
 * A sample is taken when the executor enters a timed state with a non-empty the effective guard 
 * interval. In order to guarantee that the scheduled occurence lies within the guard, the density function
 * is shaped accordingly. The schedule expires when either the event is actually executed or when the
 * effective guard interval changes due to a transition.
 * -  SimStochasticEventAttribute::Delay
 * The random variable models a delay relative to the clock time when the event is
 * enabled. A sample is taken when the executor is reset to determine the initial amount of delay. 
 * During the execution sequence the executor accumulates the durations for which the event is enabled. The event
 * is scheduled when the accumulated durations matches the delay. When the event is
 * executed the schedule expires and the random variable is sampled to re-initialised the delay.
 *
 * Note that type Extern or Delay schedules can disable the respective event in a way that
 * potentially leads to blocking behaviour even if the timed automata is non-blocking by Alur semantics.
 * This is a consequence of the fact that both types model additional phenomena that are
 * synchronized with the timed automata, and it is perferctly reasonable that this synchronisation
 * introduces blocking situations.
 * In contrast, events of type Trigger are not affected by the blocking issue provided that  guards lie 
 * within the respective invariant.  
 *
 * \section SecSimulatorPLPEX3 File IO
 *
 * For token IO, the ProposingExecutor reads and writes a section with default label 
 * "Executor". It contains a ParallelExecutor section to define a vector of generators,
 * a SimConditionSet section to define relevant conditions, and a SimEventSet section to define
 * the above event attributes. Example:
 *
 * \code
 * <Executor> 
 *
 * <Generators> 
 * "./some_generator.gen"
 * "./other_generator.gen" 
 * </Generators> 
 *
 * <Conditions> 
 *
 * "IdleCond"      
 * <EventCondition>
 * <StartEvents> "beta" "mue" </StartEvents>
 * <StopEvents>  "alpha"      </StopEvents>
 * </EventCondition>
 *
 * "DownCond"     
 * <StateCondition>
 * <StateSet> "down" </StateSet>           % refers to first generator
 * <StateSet> "down" "repair" </StateSet>  % refers to second generator
 * </StateCondition>
 *
 * </Conditions> 
 *
 * <SimEvents> 
 *
 * "alpha"    
 * <Priority> 100  </Priority>  
 *
 * "beta"   
 * <Stochastic> +Trigger+  +Gauss+  <Parameter> 10  5  </Parameter> </Stochastic>
 *
 * "mue"   
 * <Stochastic> +Delay+  +Gauss+  <Parameter> 20  5  </Parameter> </Stochastic>
 *
 * "lambda"    
 * <Priority> 100  </Priority>  
 *
 * </SimEvents> 
 *
 * </Executor> 
 * \endcode
 *
 * Technical detail: since the trace buffer only covers the dynamic state of the parallel executor,
 * the RevertToStep method cannot recover the stochastic event states. Including stochastic states
 * with the trace buffer is considered to expensive. 
 *
 * @ingroup SimulatorPlugin 
 */


class FAUDES_API ProposingExecutor : public LoggingExecutor {  

FAUDES_TYPE_DECLARATION(ProposingExecutor, ProposingExecutor, ParallelExecutor)

 public:
		
  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Constructors & Destructor */
  /** @{ doxygen group */


  /**
   * Creates an emtpy ProposingExecutor
   */
  ProposingExecutor();


  /**
   * Copy constrcutor
   */
  ProposingExecutor(const ProposingExecutor&);



  /** @} doxygen group */

  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Simulation Event Attributes  */
  /** @{ doxygen group */


  /** 
   * Simulation event attribute lookup 
   *
   * @param index
   *
   * @return 
   *   reference to attribute
   */
  const SimEventAttribute& EventAttribute(Idx index) const;

  /**
   * Set simulation event attribute. Requires Reset().
   *
   * @param index
   *   Event index
   * @param rAttr
   *   New attribute
   * @exception Exception
   *   Index not found in EventSymbolMap (id 42)
   *
   */
  void EventAttribute(Idx index, const SimEventAttribute& rAttr);


  /**
   * Set all simulation event attributes. 
   * Any previous attributes are removed.
   * Any events not in rAlphabet become the default attribute attached (which is priority 0)
   * Requires Reset().
   *
   *	@param rAlphabet 
   *	    EventSet with SimEventAttrute data
   */
  void Alphabet(const sEventSet& rAlphabet);

  /** 
   * Access alphabet (incl simulation event attributes) 
   *
   * @return
   *    Overall alphabet
   */
  const sEventSet& Alphabet(void) const { return mSimEvents; };

  /** @} doxygen group */

  /** @name Execution Proposal  */
  /** @{ doxygen group */


  /**
   * Execute next transition.
   *
   * Choose the transition to execute by priorities and   
   * stochastic properties.
   *
   *	@return 
   *	    Executed TimedEvent
   */
  TimedEvent ExecuteNextTransition();
		
  /**
   * Propose next transition.
   * 
   * Propose a transition to execute by priorities and   
   * stochastic properties.
   *
   *	@return 
   *	    Proposed TimedEvent
   */
  const TimedEvent& ProposeNextTransition();
		
  /**
   * Inspect stochastic event states (debugging)
   *
   *   return EventInfoMap string
   */
  std::string EventStatesToString(void) const;


  /** @} doxygen group */

  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Re-implemenented from ParallelExecutor */
  /** @{ doxygen group */

  /**
   * Reset the ProposingExecutor.
   * This includes a reset of the ParallelExecutor and the simulation event states.
   * @param seed
   *     Seed for random generator
   */
  virtual void Reset(long int seed);

  /**
   * Reset the ProposingExecutor.
   *
   * This method uses the systemtime as seed.
   */
  
  virtual void Reset(void) { Reset(0); };

  /**
   * Clear all data (generators, simulation attributes etc)
   */
  virtual void Clear(void);


  /**
   * Execute time duration.
   *
   *	@return 
   *  	 True on success
   */
  bool ExecuteTime(Time::Type duration);
		
  /**
   * Execute event.
   *
   *	@return 
   *  	 True on success
   */
  bool ExecuteEvent(Idx event);
		

  /**
   * Execute event by transition
   *
   *	@return 
   *  	 True on success
   */
  bool ExecuteTransition(const TimedEvent& tevent);
		
  /**
   * Revert executor to past step.
   *
   * This will revert only the executor dynamic state (incl clock values, current time).
   * The condition and event states, however, will not be reverted.
   *
   *	@return 
   *  	 True on success
   */
  bool RevertToStep(Idx step);

  /** @} doxygen group */

  /*****************************************
   *****************************************
   *****************************************
   *****************************************/


 private:

  /**
   * Simulation event attributes, incl stochastic and priority data
   */
  sEventSet mSimEvents;

  /** 
   * Valid proposal available 
   */
  bool mPValid;

  /** 
   * Available proposal 
   */
  TimedEvent mProposal; 

  /**
   * Reset stochastic state of events.
   */
  void ResetProposer(long int seed=0);

  /**
   * Evaluate random variable to schedule event.
   * Referring to the specified stochastic attribute, take a random sample to
   * schedule the next occurence of the event. The result is given as return value and is
   * also recorded in the simulation state of the event attribute. 
   *
   *  
   *	@param event
   *	   Event to schedule, by index
   *	@param pattr
   *	   Pointer to event attribute  
   *	@return 
   *	   Time of next event occurrence 
   */
  Time::Type Schedule(Idx event, SimEventAttribute* pattr);

protected:

  /**
   * Reads proposing executor from TokenReader, see also public wrappers Type::Read.
   *
   * @param rTr
   *   TokenReader to read from
   * @param rLabel
   *   Section to read, defaults to "LoggingExecutor"
   * @param pContext
   *   Read context to provide contextual information (ignored)
   *
   * @exception Exception
   *   - non-deterministic generator(s) (id 501)
   *   - token mismatch (id 502)
   *   - IO error (id 1)
   */
  virtual void DoRead(TokenReader& rTr,  const std::string& rLabel = "", const Type* pContext=0);
 
  /**
   * Write to TokenWriter, see also public wrappers Type::Write.
   *
   * @param rTw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of section to write, defaults to "LoggingExecutor"
   * @param pContext
   *   Write context to provide contextual information (ignored)
   *
   * @exception Exception 
   *   - IO errors (id 2)
   */
  virtual void DoWrite(TokenWriter& rTw, const std::string& rLabel="", const Type* pContext=0) const;

  /**
   * Assignment method
   *
   * @param rSrc
   *    Source to assign from
   */
  void DoAssign(const ProposingExecutor& rSrc);


}; // end class ProposingExecutor



} // namespace faudes


#endif
