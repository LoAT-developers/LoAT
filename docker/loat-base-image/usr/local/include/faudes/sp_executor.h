/** @file sp_executor.h Execute transitions in a timed generator  */


/* 
   FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2007  Ruediger Berndt
   Copyright (C) 2007  Thomas Moor
   Exclusive copyright is granted to Klaus Schmidt


*/



#ifndef FAUDES_SP_EXECUTOR_H
#define FAUDES_SP_EXECUTOR_H

#include "corefaudes.h"
#include "tp_include.h"


// debugging: executor level
#ifdef FAUDES_DEBUG_EXECUTOR
#define FD_DX(message) FAUDES_WRITE_CONSOLE("FAUDES_EXECUTOR: " << message)
#else
#define FD_DX(message)
#endif

// debugging: proposing executor level
#ifdef FAUDES_DEBUG_SIMULATOR
#define FD_DS(message) FAUDES_WRITE_CONSOLE("FAUDES_SIMULATOR: " << message)
#else
#define FD_DS(message)
#endif

// debugging: device synchronization level
#ifdef FAUDES_DEBUG_SIMULATOR_SYNC
#define FD_DS_SYNC(message) FAUDES_WRITE_CONSOLE("FAUDES_RUNSYNC: " << message)
#else
#define FD_DS_SYNC(message)
#endif



namespace faudes {


/** Global Tyoedefs */
   

/** typedef for external trace */
class FAUDES_API TimedEvent {
public:
  Idx mEvent;
  Time::Type mTime;
};

/**
 * An Executor is a timed generator that maintains a current state. 
 * 
 * The Executor is the lowest level building block for the libFAUDES simulator plugin.
 * It maintains a current state that consists of 
 *  - the discrete state;
 *  - a value map that assigns values to clock variables;
 *  - the current step aka logical time;
 *  - the current global clock aka clock time; as with faudes timed automata,
 *    clock time is in faudes-time units which may be mapped to physical time by a fixed
 *    conversion factor; see also DeviceExecutor.
 * The state can be retrieved by the method Executor::CurrentState(void), 
 * and it is updated whenever time or transitions are executed via Executor::ExecuteTime(Time::Type) 
 * or Executor::ExecuteEvent(Idx). If you plan to execute multiple generators with synchronized shared 
 * events, you will find the class ParallelExecutor with a very similar interface more appropriate.
 *
 * The Executor provides Methods that indicate which transitions currently are enabled, referring to the
 * current state, the current clock values and the guard and invariant data from the TimedGenerator.
 * In contrast to enabled events, there is also the notion of active events, which refers to
 * the discrete state only, ignoring guards and invariants.
 * 
 * Technically, the Executor class is derived from the TimedGenerator, however inheritence is private.
 * The common way to initialise an Executor object is to construct it from a const ref to a TimedGenerator,
 * which sets up additional internal data structures. Read-only access to the underlying generator
 * is given by the faudes::Executor::Generator() method.
 *
 * Note: a prequisit of the current implementation is that the underlying generator
 * is deterministic ie the current discrete state is uniquely determind by the external
 * sequence of discrete events.
 *
 *
 * @ingroup SimulatorPlugin 
 */

class FAUDES_API Executor : protected TimedGenerator {      

FAUDES_TYPE_DECLARATION(Executor,Executor,TimedGenerator)

    public:
           

    /** Typedef for timed state */
    typedef struct {
      Idx State;                       // discrete state
      std::map<Idx,Time::Type> ClockValue; // map clockindex to value
    } TimedState;


   /**
    * Creates an emtpy Executer
    */
    Executor(void);

   /** 
    * Construct from tgenerator. 
    *
    * Construction from a TimedGenerator will copy all given TimedGenerator data and complie it to
    * some additional Executor specific data. Thus, if the original TimedGenerator changes
    * the Executor will not reflect these changes.
    *
    * @param rGen
    *   Input generator
    *
    * @exception Exception
    *   - Nondetrministic input generator (id 501)
    */
    Executor(const TimedGenerator& rGen);

   /**
    * Construct from TimedGenerator file.
    *
    * @param rFileName
    *   File to read
    *
    * @exception Exception
    *   - IO errors (id 1)
    *   - token mismatch (id 50, 51, 52, 80, 85)
    *   - nondetrministic generator (id 501)
    */
    Executor(const std::string& rFileName);

    /**
     * Initialise from TimedGenerator.
     *
     *	@param rGen 
     *    Input generator
     */
    void Generator(const TimedGenerator& rGen);
	

    /**
     * Reference to the internal generator for inspection
     *
     *	@return 
     * const reference of mTGen
     */
    const TimedGenerator& Generator(void) const;
			
    /**
     * Generator name (for convenience)
     *
     */
    const std::string& Name(void) const {return TimedGenerator::Name();} ;

    /**
     * State name (for convenience)
     *
     */
    std::string StateName(Idx idx) const {return TimedGenerator::StateName(idx);} ;

	
    /**
     * Event name (for convenience)
     *
     */
    std::string EventName(Idx idx) const {return TimedGenerator::EventName(idx);} ;

	
    /**
     * Clear all data incl TimedGenerator
     *
     */
    void Clear(void);


    /** 
     * Reset all clocks and assign initial state.
     */
    void Reset();

    /**
     * Get maximal interval of time that can pass without executing an event.
     * This corresponds to the inveriant of the current timed state.
     *
     *	@return TimeInterval 
     *	
     */
    const TimeInterval& EnabledTime() const;

    /**
     *	Get set of events that are enabled at current (timed) state
     *
     *  @return 
     *     Set of enabled events
     */
    const EventSet& EnabledEvents() const;

    /**
     *	Get set of events that are disabled at current (timed) state
     *
     *  @return 
     *     Set of disabled events
     */
    const EventSet& DisabledEvents() const;

    /**
     *  Get maximal interval on which set of enabled events is constant
     *
     *	@return TimeInterval 
     *	
     */
    const TimeInterval& EnabledInterval() const;
	

    /**
     *  Get interval on which an active event is enabled. 
     *
     *	@param event
     *     Active event
     *
     *	@return TimeInterval 
     *     (empty if event not active or active with guard violated) 
     *	
     */
    TimeInterval EnabledEventTime(Idx event) const;


    /**
     *  Get interval on which an active event satisfies its guard. 
     *
     *	@param event
     *     Active event
     *
     *	@return TimeInterval 
     *     (empty if event not active or active with guard violated) 
     *	
     */
    TimeInterval EnabledGuardTime(Idx event) const;


    /**
     *	Get set of events that are active at current (untimed) state.
     *
     *  @return 
     *     Set of active events
     */
    const EventSet& ActiveEventSet(void) const;

    /**
     *	Get set of transitions that are active at current (untimed) state
     *
     *  @return 
     *     Set of active trans
     */
    const TransSet& ActiveTransSet(void) const;

    /** 
     * Let time pass. Returns false if the specified amount 
     * of time cannot elapse without an event being executed
     *
     * @param time
     *	  Amount of time that shall elapse.
     * @return
     *   True/false -- success
     */
     bool ExecuteTime(Time::Type time);

    /** 
     * Execute transition. Returns false if the transition
     * is not enabled and hence cannot be executed at the current time
     *
     * @param event
     *	  Indicate transition to execute
     * @return
     *   True/false -- success
     */
     bool ExecuteEvent(Idx event);

     /** 
      * Set timed state. Returns false if state or clock values are invalid.
      *
      * @param tstate
      *  State to set. 
      *
      * @return
      *   True/false -- success
      */
     bool CurrentTimedState(const TimedState& tstate);
 
     /** 
      * Get timed state.
      *
      * @return
      *   Current discrete state and clock values. 
      */
     const TimedState& CurrentTimedState(void) const;
 
     /** 
      * Set discrete state. Returns false if state is not 
      * in state set.
      *
      * @param index
      *  State index
      *
      * @return
      *   True/false -- success
      */
     bool CurrentState(Idx index);
 
     /** 
      * Get discrete state. 
      *
      * @return
      *   Discret state by index
      */
     Idx CurrentState(void) const;
 
     /** 
      * Set value of clock variable.
      * Returns false if clock not in clockset. 
      *
      *	@param clock
      *	   Index of clock variable to set 
      *	@param time
      *	   Time to set 
      * @return
      *   True/false -- success
      */
      bool CurrentClockValue(Idx clock, Time::Type time);
 			
     /** 
      * Get value of clock
      *
      *	@param clock
      *	   Index of clock variable
      *	@return time
      *	   Value of clock variable 
      */
      Time::Type CurrentClockValue(Idx clock) const;
 		          			
     /** 
      * Set current time.
      *
      *	@param time
      *	   New current time 
      */
      void CurrentTime(Time::Type time);

     /** 
      * Get current time
      *
      *	@return time
      *	   Current time
      */
      Time::Type CurrentTime(void) const;

     /** 
      * Set logic time (# of steps)
      *
      *	@param step
      *	   New logic time 
      */
      void CurrentStep(int step);

    
      /** 
       * Get logic time ie numer of transitions so far.
       *
       */
      int CurrentStep(void) const;

      /** 
       * Returns true if timed generator is in a deadlocked state.
       *
       *	@return true/false
       */
      bool IsDeadlocked() const;
			
			
      /** 
       * Check if Executor is valid. 
       * Not implemented, should check for determinism and consitency of current state and clock values.
       *
       * @return 
       *   Success
       */
      virtual bool Valid(void) const {return true;};


      /** 
       * Pretty printable string of current state
       */
      std::string CurrentTimedStateStr(void) const;
			
      /** 
       * Pretty printable string of timed state
       */
      std::string TSStr(const TimedState& tstate) const;

      /** 
       * Pretty printable string of timed event
       */
      std::string TEStr(const TimedEvent& tevent) const;

      /** 
       * Pretty printable string of clock name
       */
      std::string CStr(Idx idx) const;

      /** 
       * Pretty printable string of event
       */
      std::string EStr(Idx idx) const;

      /** 
       * Pretty printable string of state
       */
      std::string SStr(Idx idx) const;

      // std faudes type interface
      using TimedGenerator::Read;
      using TimedGenerator::Write;

 protected:

  /**
   * Assignment method. 
   *
   * @param rSrc
   *    Source to assign from
   */
  void DoAssign(const Executor& rSrc);

  /**
   * Reads configuration from TokenReader, see Typefor public wrappers.
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
   * Writes configuration to TokenWriter, see Type for public wrappers.
   *
   * @param rTw
   *   TokenWriter to write to
   * @param rLabel
   *   Section to write
   * @param pContext
   *   Write context to provide contextual information
   *
   * @exception Exception
   *   - IO error (id 2)
   */
  virtual void DoWrite(TokenWriter& rTw,const std::string& rLabel="", const Type* pContext=0) const;




 private:
     
    /** Current state incl clock values */
    TimedState mCurrentTimedState;

    /** Current clock time */
    Time::Type mCurrentTime;

    /** Current logic time */
    int mCurrentStep;

    /** Prepare internal data structurs from generator */
    void Compile(void);

    /** Compute enabled events and enabled interval (fake const) */
    void ComputeEnabled(void) const;

    /** Compute enabled core routine (non const) */
    void ComputeEnabledNonConst(void);

    /** Record enabled time */
    TimeInterval mETime;

    /** Record enabled events */
    EventSet mEEvents;

    /** Record rime on shich mEEvents is constant  */
    TimeInterval mEInterval;

    /** Record interval in which each guard is enabled  */
    std::map<Idx,TimeInterval> mEGuardInterval;

    /** Record disabled events */
    EventSet mDEvents;

    /** Record active events (ie regardles time) */
    EventSet mAEvents;

    /** Record active transitions (regardles time) */
    TransSet mATrans;

    /** Validity flag for the above data */
    bool mEValid;

    /** Compiled generator data: map transition to clock to interval constraint */
    std::map<Transition, std::map<Idx,TimeInterval> > mTransClockIntervalMap;

    /** Compiled generator data: map state to clock to interval constraint */
    std::map<Idx, std::map<Idx,TimeInterval> > mStateClockIntervalMap;

}; // end class Executor



} // namespace faudes


#endif

