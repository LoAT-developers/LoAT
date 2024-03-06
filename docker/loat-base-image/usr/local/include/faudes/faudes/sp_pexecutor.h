/** @file sp_pexecutor.h Executor for multiple synchronized timed generators  */

/* 
   FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2007, 2008 Thomas Moor
   Copyright (C) 2007 Ruediger Berndt
   Exclusive copyright is granted to Klaus Schmidt

*/



#ifndef FAUDES_PEXECUTOR_H
#define FAUDES_PEXECUTOR_H

#include "corefaudes.h"
#include "tp_include.h"
#include "sp_executor.h"
#include "sp_simconditionset.h"


namespace faudes {

/**
 * Synchronized parallel execution of TimedGenerators
 *
 * \section SecSimulatorPEX1 Synchronisation
 *
 * The ParallelExecutor executes a family of timed generators with synchronized shared
 * events according to Alur semantics. That is, we assume disjoint clock sets and synchronize 
 * shared events w.r.t. occurence at clock time. 
 *
 * \section SecSimulatorPEX2 Implementation
 *
 * The external interface of a ParallelExecutor is the same as the single Executor, in that 
 * it indicats enabled events and in that it provides methods for executing
 * events or letting time pass.
 *
 * Technically, a ParallelExecutor is a vector of executors. Clocks 
 * are treated on a per executor basis. That is,  values of clocks in one generator are
 * not effected by the reset of another generator, even if the respestive clock variables 
 * have the same index and name.
 *
 * \section SecSimulatorPEX3 File IO
 *
 * For token IO, the ParallelExecutor reads and writes the generators to execute within a
 * section with default label "Executor". For disk space efficiency, the token IO 
 * format will use refernces by (relative) filename if the latter is known. Since TimedGenerators
 * read any generator type from file, so does the ParallelExecutor. Example:
 *
 * \code
 * <Executor>
 * <Generators>
 * "./some_generator.gen"
 * "./other_generator.gen"
 * </Generators>
 * </Executor>
 * \endcode
 *
 * @ingroup SimulatorPlugin 
 */

class FAUDES_API ParallelExecutor : public Type {    

FAUDES_TYPE_DECLARATION(ParallelExecutor,ParallelExecutor,Type)

 public:
  /** Typedef for parallel discrete state*/
  typedef std::vector<Idx> ParallelState;
	
  /** Typedef for parallel clock values */
  typedef std::vector< std::map<Idx,Time::Type> > ParallelClock;

  /** Typedef for parallel timed state, incl token io */
  class FAUDES_API ParallelTimedState : public Type {
  public:
    ParallelState State;
    ParallelClock Clock;
  protected:
    virtual void DoRead(TokenReader& rTr,  const std::string& rLabel = "", const Type* pContext=0);
    virtual void DoWrite(TokenWriter& rTw, const std::string& rLabel="",const Type* pContext=0) const;
  };

  /** Provide typedef from Executor */
  typedef Executor::TimedState TimedState;

  /**
   * Construct an emtpy ParallelExecuter
   */
  ParallelExecutor(void);

  /**
   * Copy constructor
   */
  ParallelExecutor(const ParallelExecutor& rOther);

  /**
   * Construct from file.
   *
   * This constructor uses the DoRead method to initialize from file.
   *
   * @param rFileName
   *   Filename
   *
   * @exception Exception
   *   - non-deteministic generator (id 501)
   *   - token mismatch (id 502)
   *   - IO errors (id 1)
   */
  ParallelExecutor(const std::string& rFileName);


  /**
   * Explicit destructor.
   */
  virtual ~ParallelExecutor(void);

  /**
   * Clear all data. Removes  all generators/executors and resets the
   * current state to a void value.
   *
   */
  virtual void Clear(void);

  /**
   * Number of TimedGenerators
   *
   */
  Idx Size(void) const;

        
  /**
   * Add a TimedGenerator from file.  This method uses the TimedGenerator's read to
   * find the first generator in the file. If the generator found is not a TimedGenerator,
   * timing data defaults to infinite invariants/guards and empty resets.
   * After inserting generators and before starting to execute, you must call Reset() to update
   * internal datastructures.
   *
   * @param rFileName
   *   File to read
   *
   * @exception Exception
   *   - non-deteministic generator (id 501)
   *   - token mismatch (id 502)
   *   - IO errors (id 1)
   */
  void Insert(const std::string& rFileName);

  /**
   * Add a TimedGenerator. 
   * After inserting generators and before starting to execute, you must call Reset() to update
   * internal datastructures.
   *
   * @param rGen
   *   Generator to add
   *
   * @exception Exception
   *   - non-deteministic generator (id 501)
   */
  void Insert(const TimedGenerator& rGen);

  /** 
   * Overall alphabet. 
   *
   */
  const EventSet& Alphabet(void) const;

  /** 
   * Goto initial state. Reset all clock values to zero, assign initial states to each executor. 
   */
  virtual void Reset(void);



  /** 
   * Read-only access to individual executors. 
   * 
   */	
  typedef std::vector<Executor>::const_iterator Iterator;
  Iterator       Begin(void) const       { return mExecutors.begin(); };
  Iterator       End(void)   const      { return mExecutors.end(); };
  const Executor& At(int i)  const { return mExecutors.at(i); };


  /**
   * Event index lookup.
   *
   * This convenience method refers to the global event symbol table.
   * 
   * @param rName
   *    Name of event to lookup
   *
   * @return 
   *   Valid index or 0 if non-existent
   */
  Idx EventIndex(const std::string& rName) const { return mAlphabet.Index(rName); };

  /** 
   * Event name lookup 
   *
   * This convenience method refers to the global event symbol table.
   *
   * @param index
   *   Index of event to look up
   *
   * @return 
   *   Name or empty std::string if non-existent
   */
  std::string EventName(Idx index) const { return mAlphabet.SymbolicName(index); };
   
  /** 
   * Get clock time.
   *
   */
  Time::Type CurrentTime(void) const;

  /** 
   * Get logical time, ie number of transitions so far,
   *
   */
  int CurrentStep(void) const;

  /** 
   * Test for deadlocked.
   *
   * The parallel executor is deadlocked if neither time can pass nor an event can
   * be executed. Prototypical examples for such a situation is that the indvidual
   * executers fail to agree on a common time interval, at which shaered events are
   * enabled.
   *
   *	@return True/false
   */
  bool IsDeadlocked() const;

  /** 
   * Check validity of executors.
   *
   * This is currently not implemented.
   *
   * @return 
   *   True on success
   */
   virtual bool Valid(void) const {return true;};

  /**	
   * Get current state of the ParallelExecutor.
   *
   * With "the current state" w refer to all data relevant for 
   * events generated in future. This data consists of a discrete
   * state vector and a mapping from clocks to closk values. 
   *
   *  @return 
   *    Discrete state vector and clock value maps
   */
  const ParallelTimedState& CurrentParallelTimedState(void) const;

  /**	
   * Get current discrete state vector of the ParallelExecutor 
   *
   * By "the current discrete state" we refer to a vector of indices
   * that indicate the current state of the untimed transition structure.
   *
   *   @return 
   *      Discrete state vector
   */
  const ParallelState& CurrentParallelState(void) const;

  /** 
   * Set clock time. 
   * This does not affect clocks and, hence, is purely cosmetic.
   * The trace buffer will record an invalid event.
   *
   *  @param time
   *	New clock time 
   */
  virtual void CurrentTime(Time::Type time);

  /** 
   * Set logical time (# of steps)
   *
   * This does not affect clocks and, hence, is purely cosmetic.
   * Note that, in contrast to clock time, the individual
   * generators do not agree in logical time. 
   * The trace buffer will get out of order and should be cleared.
   *
   *  @param step
   *	 New logical time 
   */
  virtual void CurrentStep(int step);

  /**	
   * Set current state of the ParallelExecutor.
   *
   * This resets the parallel executor to the given state, incl clock values.
   * Both, clock time and logical time is also reset (to 0).
   *
   *  @return 
   *    True for success
   */
   virtual bool CurrentParallelTimedState(const ParallelTimedState& ptstate);

  /** 
   * Let time pass without executing a transition. Return false if the duration specified  
   * cannot elapse without an event being executed.
   *
   * @param duration
   *	  Amount of time that shall elapse.
   * @return
   *   True for success
   */
  virtual bool ExecuteTime(Time::Type duration);

  /** 
   * Execute transition.
   *
   * Returns false if the transition
   * cannot be executed at the current time.
   *
   * @param event
   *   Indicate transition to execute
   * @return
   *   True on success
   */
  virtual bool ExecuteEvent(Idx event);

  /**
   * Get maximal duration that can pass without executing an event.
   *
   *	@return TimeInterval 
   *	
   */
  const TimeInterval& EnabledTime() const;

  /**
   *  Get events that are enabled at current (timed) state.
   *   
   *  By "enabled" we refer to the synchronizes timed generators,
   * that is, we do care about clock values, invariants and guards.
   *
   *
   *  @return 
   *     Set of enabled events
   */
  const EventSet& EnabledEvents() const;

  /**
   * Get events that are disabled at current (timed) state
   *
   *  By "disabled" we refer to the synchronizes timed generators,
   * that is, we do care about clock values, invariants and guards.
   *
   *  @return 
   *     Set of disabled events
   */
  const EventSet& DisabledEvents() const;

  /**
   *  Get an interval on which the set of enabled events is constant.
   *  Note: while this implementation tries to come up with a potentially large
   *  interval, it is not guaranteed to be maximal.
   *
   *	@return TimeInterval 
   *	
   */
  const TimeInterval& EnabledInterval() const;

  /**
   *  Get interval on which the specified event is enabled.
   *
   *  Returns empty, if the event is not active or never 
   *  simultanuosly enabled in all executors.
   *
   *	@param event
   *
   *	@return TimeInterval 
   *	
   */
  TimeInterval EnabledEventTime(Idx event) const;

  /**
   *  Get interval on which the respective guard is satisfied.
   *
   *  Returns empty, if the event is not active or if the guards  
   *  are never simultanuosly satisfied in all executors.
   *
   *	@param event
   *
   *	@return TimeInterval 
   *	
   */
  TimeInterval EnabledGuardTime(Idx event) const;

  /** 
   * Get events that are active in all TimedGenerators.
   *
   * By "active" we refer to the untimed transition structure,
   * that is, we ignore clock values etc.
   *
   *	@param stateVec
   *	   Discrete state
   *	@return 
   *	   Active EventSet
   */
  EventSet ActiveEventSet(const ParallelState& stateVec) const;

  /**  
   * Test whether an event is active in a given discrete state.
   *
   * By "active" we refer to the untimed transition structure,
   * that is, we ignore clock values etc.
   *
   *   @param ev
   *     Event to test 
   *   @param stateVec
   *     ParallelState
   *
   *   @return 
   *     True for active in all generators
   */
  bool Active(Idx ev, const ParallelState& stateVec) const;   

  /**
   * Test whether an event is active at current (discrete) state.
   *
   * By "active" we refer to the untimed transition structure,
   * that is, we ignore clock values etc.
   *
   *   @param ev
   *      Event ro test
   *
   *   @return 
   *      True for active in all generators
   */
  bool Active(Idx ev) const;

  /** 
   * Pretty printable string of timed parallel state
   */
  std::string PTSStr(const ParallelTimedState& ptstate) const;

  /** 
   * Pretty printable string of parallel state
   */
  std::string PSStr(const ParallelState& pstate) const;

  /** 
   * Pretty printable string of timed event
   */
  std::string TEStr(const TimedEvent& tevent) const;

  /** 
   * Pretty printable string of clock name
   */
  std::string CStr(Idx clock) const;

  /** 
   * Pretty printable string of event
   */
  std::string EStr(Idx event) const;

  /** 
   * Pretty printable string of current state
   */
  std::string CurrentParallelTimedStateStr(void) const; 

  /** 
   * Pretty printable string of parallel state          
   */
  std::string CurrentParallelStateStr(void) const;

  /** Compute enabled events and enabled interval (fake const) */
  /** this is public only for performance experiments --- dont use */
  void ComputeEnabled(void) const;

  /** Compute enabled core routine (non const) */
  void ComputeEnabledNonConst(void);



protected:

  /**
   * Reads parallel executor from TokenReader, see also public wrappers Read() in faudes::Type.
   *
   * @param rTr
   *   TokenReader to read from
   * @param rLabel
   *   Section to read, defaults to "Executor"
   * @param pContext
   *   Read context to provide contextual information (ignored)
   *
   * @exception Exception
   *   - non-deterministic generator(s) (id 501)
   *   - token mismatch (id 502)
   *   - IO error (id 1)
   */
  virtual void DoRead(TokenReader& rTr,  const std::string& rLabel = "",  const Type* pContext=0);
 
  /**
   * Write to TokenWriter, see also public wrappers Write() in faudes::Type.
   *
   * @param rTw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of section to write, defaults to "Executor"
   * @param pContext
   *   Write context to provide contextual information (ignored)
   *
   * @exception Exception 
   *   - IO errors (id 2)
   */
  virtual void DoWrite(TokenWriter& rTw, const std::string& rLabel="", const Type* pContext=0) const;

  // /**
  //  * Write to TokenWriter, see also public wrappers XWrite() in faudes::Type.
  //  *
  //  * @param rTw
  //  *   Reference to TokenWriter
  //  * @param rLabel
  //  *   Label of section to write, defaults to "Executor"
  //  * @param pContext
  //  *   Write context to provide contextual information (ignored)
  //  *
  //  * @exception Exception 
  //  *   - IO errors (id 2)
  //  */
  // virtual void DoXWrite(TokenWriter& rTw, const std::string& rLabel="", const Type* pContext=0) const;

  /**
   * Reads generator files section from TokenReader
   *
   * @param rTr
   *   TokenReader to read from
   *
   * @exception Exception
   *   - non-deterministic generator(s) (id 501)
   *   - token mismatch (id 502)
   *   - IO error (id 1)
   */
  virtual void DoReadGenerators(TokenReader& rTr);
 
  /**
   * Write generator files section to TokenWriter
   *
   * @param rTw
   *   Reference to TokenWriter
   *
   * @exception Exception 
   *   - IO errors (id 2)
   */
  virtual void DoWriteGenerators(TokenWriter& rTw) const;


  /**
   * Assignment method
   *
   * @param rSrc
   *    Source to assign from
   */
  void DoAssign(const ParallelExecutor& rSrc);

  /** compile internal data (eg overall alphabet) */
  virtual void Compile();

  /** recent event */
  Idx mRecentEvent;

private:
     
  /** list of executors */
  std::vector<Executor> mExecutors;

  /** list of executors */
  std::vector<std::string> mExecutorNames;

  /** Internal non-const iterator */
  typedef std::vector<Executor>::iterator iterator;

  /** overall alphabet */
  EventSet mAlphabet;

  /** global time (real) */
  Time::Type mCurrentTime;

  /** global time (step)*/
  int mCurrentStep;

  /** enabled time */
  TimeInterval mETime;

  /** enabled events */
  EventSet mEEvents;

  /** disabled events */
  EventSet mDEvents;

  /** enabled interval */
  TimeInterval mEInterval;

  /** validity flag for fevents and ftime */
  bool mEValid;

  /** current state */
  ParallelTimedState mCurrentParallelTimedState;

  /** update parallel timed state() */
  void UpdateParallelTimedState(void);




}; // end class ParallelExecutor



} // namespace faudes


#endif

