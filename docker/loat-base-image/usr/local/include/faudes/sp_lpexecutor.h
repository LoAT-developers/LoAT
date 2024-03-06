/** @file sp_lpexecutor.h Executor with logging facilities  */

/* 
   FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2007, 2008 Thomas Moor
   Copyright (C) 2007 Ruediger Berndt
   Exclusive copyright is granted to Klaus Schmidt

*/


#ifndef FAUDES_LPEXECUTOR_H
#define FAUDES_LPEXECUTOR_H


#include "corefaudes.h"
#include "tp_include.h"
#include "sp_pexecutor.h"
#include "sp_simconditionset.h"


namespace faudes {

/**
 * Executor with logging facilities.
 *
 * \section SecSimulatorLPEX1 Logging to Token IO
 *
 * Logging destination in general is a TokenWriter, which may be initialised to a
 * file or console output.
 * Logging can be configured to include
 * - the external behaviour (timed event sequence), 
 * - the internal behaviour (state sequence) and/or 
 * - timing statistics of conditions specified by AttributeSimCondition. 
 *
 *
 * \section SecSimulatorLPEX2 Logging to Internal FIFO Buffer
 *
 * The state- and event-sequence can be logged to a internal FIFO Buffer.
 * Methods to revert to a previous state are provided. This feature is meant to
 * facilitate user interaction in simulator applications. 
 *
 * Technical detail: since the trace buffer only covers the dynamic state of the parallel executor,
 * the RevertToStep method cannot recover the condition status. Including stochastic states
 * with the trace buffer is considered to expensive. 
 *
 * \section SecSimulatorLPEX3 File IO
 *
 * For token IO, the LoggingExecutor reads and writes a section with default label 
 * "Executor". It contains a ParallelExecutor section to define a vector of generators and
 * a SimConditionSet section to define the relevant conditions. Example:
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
 * </Executor> 
 * \endcode
 *
 *
 * @ingroup SimulatorPlugin 
 */

class FAUDES_API LoggingExecutor : public ParallelExecutor {    

FAUDES_TYPE_DECLARATION(LogginExecutor,LoggingExecutor,ParallelExecutor)

 public:

  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Constructors & Destructor */
  /** @{ doxygen group */


  /**
   * Construct an emtpy LoggingExecuter
   */
  LoggingExecutor(void);

  /**
   * Copy constructor
   */
  LoggingExecutor(const LoggingExecutor& rOther);

  /**
   * Construct from file.
   *
   * See ParallelExecutor::Insert(const std::string& rFileName) for details.
   *
   * @param rFileName
   *   Filename
   *
   * @exception Exception
   *   - Non-deteministic generator (id 501)
   *   - IO errors (id 1)
   *   - token mismatch (id see TimedGenerator)
   */
  LoggingExecutor(const std::string& rFileName);


  /**
   * Explicit destructor.
   */
  virtual ~LoggingExecutor(void);


   /** @} doxygen group */

  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Re-implemenented from ParallelExecutor */
  /** @{ doxygen group */

  /**
   * Clear all data. Removes  all generators/executors, all conditions, and resets the
   * current state to a void value.
   *
   */
  virtual void Clear(void);

  /** 
   * Goto initial state. Reset all clock values to zero, assign initial states to each executor, 
   * reset condition states to not-satisfied, invalidate timing samples.
   */
  virtual void Reset(void);

  /** 
   * Check validity of executors.
   *
   * This is currently not implemented. It should
   * include tests on the state based conditions.
   *
   * @return 
   *   True on success
   */
   virtual bool Valid(void) const {return true;};

  /** 
   * Let time pass without executing a transition. 
   * Return false if the specified duration   
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
   * Get clock time.
   *
   */
   Time::Type CurrentTime(void) const { return ParallelExecutor::CurrentTime();} ;

  /** 
   * Set clock time. 
   * This does not affect clocks and, hence, is purely cosmetic.
   * The trace buffer is cleared. You should pause/resume logging
   * befor/after interfering with the executors state.
   *
   *  @param time
   *	New clock time 
   */
  void CurrentTime(Time::Type time);

  /** 
   * Get logical time, ie number of transitions so far,
   *
   */
  int CurrentStep(void) const { return ParallelExecutor::CurrentStep();};

  /** 
   * Set logical time (# of steps)
   *
   * This does not affect clocks and, hence, is purely cosmetic.
   * Note that, in contrast to clock time, the individual
   * generators do not agree in logical time. 
   * The trace buffer is cleared. You should pause/resume logging
   * befor/after interfering with the executors state.
   *
   *  @param step
   *	 New logical time 
   */
  void CurrentStep(int step);

  /**	
   * Set current state of the ParallelExecutor.
   *
   * This resets the parallel executor to the given state, incl clock values.
   * The trace buffer is cleared. You should pause/resume logging
   * befor/after interfering with the executors state.
   *
   *  @return 
   *    True for success
   */
   bool CurrentParallelTimedState(const ParallelTimedState& ptstate);

  /**	
   * Get current state of the ParallelExecutor.
   *
   *
   *  @return 
   *    Discrete state vector and clock value maps
   */
  const ParallelTimedState& CurrentParallelTimedState(void) const
  { return ParallelExecutor::CurrentParallelTimedState();};

  /** @} doxygen group */

  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Simulation Conditions */
  /** @{ doxygen group */

  /** Read-only access to simulation conditions */
  const SimConditionSet& Conditions(void) const;

  /** Set all simulation conditions */
  void Conditions(const SimConditionSet&);

  /** Read-only access to a simulation condition by name */
  const AttributeSimCondition& Condition(const std::string& rName) const;

  /** Read-only access to a simulation condition by index */
  const AttributeSimCondition& Condition(Idx cond) const;

  /** Set (or add) a condition by name */
  Idx SetCondition(const std::string& rName, const AttributeSimCondition& rCondition);

  /** Set a condition by index  */
  void SetCondition(Idx cond, const AttributeSimCondition& rCondition);

  /** Remove a condition by name  */
  void ClrCondition(const std::string& rName);

  /** Remove a condition by index  */
  void ClrCondition(Idx cond);

  /** Write conditions so labled section  */
  void ConditionsWrite(TokenWriter& rTw, const std::string& rLabel="SimConditions") const;

  /** Read conditions from labled section  */
  void ConditionsRead(TokenReader& rTr, const std::string& rLabel="SimConditions");
            
  /** Condition iterator: typedef */
  typedef SimConditionSet::Iterator ConditionIterator;

  /** Condition iterator: begin */
  ConditionIterator ConditionsBegin(void) const;

  /** Condition iterator: end  */
  ConditionIterator ConditionsEnd(void) const;

  /** Simulation state: true if some break condition is currently satisfied */
  bool BreakCondition(void) const {return mBreakCondition;};

  /** @} doxygen group */

  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Logging to Token I/O */
  /** @{ doxygen group */

  /** Logging mode flags, to specify what data to log */
  typedef enum { LogStatistics=0x01, LogStates=0x02, LogEvents=0x04, LogTime=0x08} LogMode;

  /** Start logging to TokenWriter */
  void LogOpen(TokenWriter& rTw, int mode);   

  /** Start logging to file */
  void LogOpen(const std::string& rFileName, int logmode, std::ios::openmode openmode = std::ios::out|std::ios::trunc);

  /** Stop logging */
  void LogClose(void);

  /** @} doxygen group */
 
  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Trace to FIFO buffer */
  /** @{ doxygen group */

  /** 
   * Clear buffer and set max buffer 
   *
   * @param length
   *   Max length of buffer, or: -2 <> keep length, -1<>infinite, 0<> no buffer
   */
  void TraceClear(int length=-2);

  /** Buffer data entry */
  typedef struct {
    ParallelTimedState mState;   //// state of pexecutor
    Idx mStep;                   //// faudes step (no of event to occur)
    Time::Type mTime;          //// faudes time (when entered mState)
    Time::Type mDuration;      //// faudes duration (how long we reside mState);
    Idx mEvent;                  //// event index (if an event occured, else 0)
  } TraceSample;

  /** Access buffer: current length */
  int TraceLength(void) const;

  /** Access buffer: iterator */
  typedef std::deque<TraceSample>::const_iterator TraceIterator;

  /** Condition iterator: begin */
  TraceIterator TraceBegin(void) const;

  /** Condition iterator: end  */
  TraceIterator TraceEnd(void) const;

  /** Access buffer: sample by faudes time (returns first sample) */
  const TraceSample* TraceAtTime(Time::Type time) const;

  /** Access buffer: sample by step */
  const TraceSample* TraceAtStep(int step) const;

  /** Access buffer: first sample */
  const TraceSample* TraceFirst(void) const;

  /** Access buffer: recent sample */
  const TraceSample* TraceRecent(void) const;

  /** Access buffer: current sample */
  const TraceSample* TraceCurrent(void) const;

  /** Access buffer: tokenwriter output */
  void TraceWrite(TokenWriter& rTw, const TraceSample& sample) const;

  /** Access buffer: console output */
  void TraceWrite(const TraceSample& sample) const;

  /** Access buffer: convert to string */
  std::string TraceToString(const TraceSample& sample) const;

  /** Access buffer: console output (list all) */
  void TraceWrite(void) const;

  /** Revert executors state to past step from buffer */
  virtual bool RevertToStep(Idx step);
  

  /** @} doxygen group */

protected:

  /** Compile internal data (all) */
  virtual void Compile();

  /**
   * Reads logging executor from TokenReader, see also public wrappers in faudes::Type.
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
  virtual void DoRead(TokenReader& rTr,  const std::string& rLabel = "", const Type* pContext=0);
 
  /**
   * Write to TokenWriter, see also public wrappers in faudes::Type.
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

  /**
   * Assignment method
   *
   * @param rSrc
   *    Source to assign from
   */
  void DoAssign(const LoggingExecutor& rSrc);


private:
     

  /** Simulation conditions */
  SimConditionSet mConditions;

  /** Enabled simulation conditions */
  std::vector<AttributeSimCondition*> mEnabledConditions;

  /** Indicate break */
  bool mBreakCondition;

  /** Compile condition internal data */
  void CompileConditions(void);

  /** Reset condition simulation state */
  void ConditionsReset(void);

  /** Process condition hook */
  void ConditionsProcess(void);
        
  /** Logging: tokenwriter ref */
  TokenWriter* pLogTokenWriter;

  /** Logging: file name */
  std::string mLogFile;

  /** Logging: mode */
  int mLogMode;
  
  /** Logging hook: dump statistics */
  void LogWriteStatistics(void);

  /** Logging hook: dump current state */
  void LogWriteState(void);

  /** Logging hook: dump recent event */
  void LogWriteEvent(void);

  /** Logging hook: dump current time */
  void LogWriteTime(void);

  /** Logging hook: halt simulation */
  void LogWritePause(void);

  /** Logging hook: continue simulation */
  void LogWriteResume(void);

  /** Trace data: max fifo length */
  int mTraceMax;

  /** Trace data: step no of first sample */
  int mTraceFirstStep;

  /** Trace data: fifo buffer */
  std::deque<TraceSample> mTraceBuffer;

  /** Trace data: time to step mapping (first step) */
  std::map<Time::Type,int> mTraceTimeToStep;

  /** Trace: helper, append one void sample */
  void TraceAddSample(void);

  /** Trace: append sample (if necessary) and update to current time  */
  void TraceUpdateTime(void);

  /** Trace: append sample (if necessary) and update to current state via given event  */
  void TraceUpdateTransition(Idx event);


}; // end class LoggingExecutor



} // namespace faudes


#endif

