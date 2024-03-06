/** @file iop_sdevice.h Virtual device for signal based io  */

/*
  FAU Discrete Event Systems Library (libfaudes)

  Copyright (C) 2008, Thomas Moor
  Exclusive copyright is granted to Klaus Schmidt

*/



#ifndef FAUDES_SDEVICE_H
#define FAUDES_SDEVICE_H

#include "corefaudes.h"
#include "iop_vdevice.h"



namespace faudes {


/**
 * Configuration of a signal based output mapping.
 *
 * An output mapping consists of a list of actions that to be performed when the
 * event is executed. Each action may set or clear the physical output line
 * specified by an abstract bitaddress.
 *
 */

class FAUDES_API AttributeSignalOutput : public AttributeVoid {

FAUDES_TYPE_DECLARATION(Void,AttributeSignalOutput,AttributeVoid)

public:

  /** Default constructor (no actions at all) */
  AttributeSignalOutput(void) : AttributeVoid() {};

  /** Copy - constructor */
  AttributeSignalOutput(const AttributeSignalOutput& rOtherAttr) : AttributeVoid() 
      { DoAssign(rOtherAttr); };

  /** Test for default value (never) */
  virtual bool IsDefault(void) const {return false;};

  /** Clear */
  virtual void Clear(void) {mActions.clear();};

  /** Enum for action  */
  typedef enum { Set, Clr, Inv } Value;

  /** Typedef for a single output action */
  class Action {
  public:
    Action(void) {mBit=0;mValue=Clr;};
    int  mBit;         //// Bitaddress (numeric)
    Value mValue;      //// Value to set (enum: set,clr,inv)
  };

  /** List of actions to perform */
  std::vector<Action> mActions;

 protected:

  /**
   * Copy method
   *
   * @param rSrcAttr
   *   Source to copy from
   * @return
   *   Ref to this attribute
   */
  void DoAssign(const AttributeSignalOutput& rSrcAttr);

  /**
   * Reads the attribute from TokenReader, see AttributeVoid for public wrappers.
   *
   * If the current token indicates an output mapping, the method reads that
   * section. Else it does nothing. Exceptions may only be thrown
   * on invalid data within the section. The label argument is ignored, we the hardcoded
   * output for output device attributes. The context argument is ignored.
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
  virtual void DoRead(TokenReader& rTr,const std::string& rLabel="", const Type*  pContext=0);

  /**
   * Writes the attribute to TokenWriter, see AttributeVoid for public wrappers.
   *
   * Writes the output mapping data. The label argument is ignored, we use
   * the hardcoded section "Output". The context argument is ignored.
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

}; // end class AttributeSignalOutput






/**
 * Configuration of a signal based input mapping.
 *
 * A input mapping consists of a list of abstract bitaddresses with an
 * edge polarity each. When on one of respecive physical input lines an edge
 * with matching priority is sensed, the logical event is triggered.
 *
 */

class FAUDES_API AttributeSignalInput : public AttributeVoid {

FAUDES_TYPE_DECLARATION(Void,AttributeSignalInput,AttributeVoid)

public:

  /** Default constructor (no triggers) */
  AttributeSignalInput(void) : AttributeVoid() {};

  /** Copy constructor */
  AttributeSignalInput (const AttributeSignalInput& rOtherAttr) : AttributeVoid() 
      { DoAssign(rOtherAttr); };

  /** Test for default value (never) */
  virtual bool IsDefault(void) const {return false;};

  /** Clear */
  virtual void Clear(void) {mTriggers.clear();};

  /** Typedef for a single input trigger */
  class Trigger {
  public:
    Trigger(void) {mBit=0; mPos=false; mNeg=false;};
    int mBit;          //// Bitaddress
    bool  mPos;        //// Positive edge triggers event
    bool  mNeg;        //// Negative edge triggers event
  };

  /** List of triggers */
  std::vector<Trigger> mTriggers;

 protected:

  /**
   * Copy method
   *
   * @param rSrcAttr
   *   Source to copy from
   * @return
   *   Ref to this attribute
   */
  void DoAssign(const AttributeSignalInput& rSrcAttr);

  /**
   * Reads the attribute from TokenReader, see AttributeVoid for public wrappers.
   *
   * If the current token indicates a input mapping, the method reads that
   * section. Else it does nothing. Exceptions may only be thrown
   * on invalid data within the section. The label argument is ignored, we use the
   * hardcoded section "Input" for input attributes. The context argument is ignored.
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
   * Writes the input mapping data.The label argument is ignored, we use the
   * hardcoded section "Input". The context argument is ignored.
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

}; // end class AttributeSignalInput




/**
 * Configuration of a signal based input or output
 *
 * This class is derived from the AttributeDeviceEvent to specialise
 * for signal based input and output mapping.
 *
 */

class FAUDES_API AttributeSignalEvent : public AttributeDeviceEvent {

FAUDES_TYPE_DECLARATION(Void,AttributeSignalEvent,AttributeDeviceEvent)

 public:

  /** Default constructor (no mapping at all) */
  AttributeSignalEvent(void);

  /** Copy constructor */
  AttributeSignalEvent(const AttributeSignalEvent& rOtherAttr); 

  /** Test for default value (never) */
  virtual bool IsDefault(void) const {return false;};

  /** Clear */
  virtual void Clear(void)  { AttributeDeviceEvent::Clear(); };

  /**  Get output mapping */
  const AttributeSignalOutput*  Outputp(void) const {
    return static_cast<AttributeSignalOutput*>(mpOutputAttribute); };
  AttributeSignalOutput*  Outputp(void) {
    return static_cast<AttributeSignalOutput*>(mpOutputAttribute); };

  /**  Get input mapping */
  const AttributeSignalInput*  Inputp(void) const {
    return static_cast<AttributeSignalInput*>(mpInputAttribute); };
  AttributeSignalInput*  Inputp(void) {
    return static_cast<AttributeSignalInput*>(mpInputAttribute); };

 protected:

  /** DoAssign */
  void DoAssign(const AttributeSignalEvent& rSrc)  
  { AttributeDeviceEvent::DoAssign(rSrc);};

  /** Prototype, input (construct on first use static) */
  static const AttributeSignalInput* InputPrototypep(void);

  /** Prototype, output (construct on first use static) */
  static const AttributeSignalOutput* OutputPrototypep(void);

}; // class AttributeSignalEvent



/**
 * An sDevice implements signal based semantics for faudes events.
 *
 * The class is configured by AttributeSignalEvents, which in turn consist of
 * either a AttributeSignalInput or a AttributeSignalOutput. Thus,
 * we set and clear output signals for output events, while edges on input
 * signals trigger input events.
 *
 * Sensing edges is done by separate thread that is started by Start().
 *
 * This class is still virtual in that it does not provide the code for actually
 * reading or writing signals. See cDevice and pDevice for derived device classes
 * that implement digital io via comedi or the parallel printer port, respectively.
 *
 * @ingroup IODevicePlugin
 */

class FAUDES_API sDevice : public vDevice {

  // provide all access to background task
  friend void* SDeviceSynchro(void*);

 public:

  // have my types
  typedef AttributeSignalInput::Trigger Trigger;
  typedef AttributeSignalOutput::Action Action;
  typedef AttributeSignalOutput::Value Value;

  /**
   * Default constructor
   */
  sDevice(void);

  /**
   * copy-constructor
   */
  sDevice(const sDevice& rOtherDevice);

  /**
   * Explicit destructor.
   */
  virtual ~sDevice(void);


  /**
   * Clear all configuration.
   * This implies Stop().
   */
  virtual void Clear(void);

  /**
   * 
   * Build up internal data-structure (e.g. signal-event - mapping)
   *
   */
  virtual void Compile(void);

  /**
   * Insert event as input event.
   * Note: you can only configure events
   * while the device is down.
   *
   * @param event
   *   Event by name.
   */
  void InsInputEvent(const std::string& event);


  /**
   * Add a trigger condition.
   * Note: you can only add a trigger condition to an
   * input event; you can only (re)-configure events
   * while the device is down.
   *
   * @param event
   *   Event 
   * @param trigger
   *   Trigger to append
   */
  void AppendTrigger(const std::string& event, const Trigger& trigger);

  /**
   * Insert event as output event.
   * Note: you can only configure event
   * while the device is down.
   *
   * @param event
   *   Event by name.
   */
  void InsOutputEvent(const std::string& event);

  /**
   * Add an action.
   * Note: you can only add a actions to an
   * output event; you can only (re)-configure events
   * while the device is down.
   *
   * @param event
   *   Event 
   * @param action
   *   Action to append
   */
  void AppendAction(const std::string& event, const Action& action);

  /**
   * Report max bit address.
   *
   * @return
   *   Set of all configured inputs
   */
  int MaxBitAddress(void) const { return mMaxBitAddress;};


  /**
   * Activate the device. This function enables output execution and input reading.
   * It starts the background thread for edge detection and input event buffer.
   *
   * @exception Exception
   *   - Not yet configured (id 551)
   */
  virtual void Start(void);

  /**
   * Deactivate the device. This function disables output execution and input reading.
   * It stops the backhround thread and resets all output signals to 0.
   */
  virtual void Stop(void);


  /** 
   * Clear dynamic data and restart device 
   */
  virtual void Reset(void);


  /**
   * Run output command.
   *
   * @exception Exception
   *   - unknown output event (id 65)
   */
  virtual void WriteOutput(Idx output);



  /**
   * Set output signal.
   *
   *
   * This function provides user level access to output signals. 
   * It executes the virtual pre and post hook methods 
   * and the virtual actual harware access to set the signal level 
   * via DoWriteSignal(int,bool). 
   *
   * @param bitaddr
   *   Abstract bit address
   * @param value
   *   True for active/high/1/set;
   *   false for passive/low/0/clr;
   *
   */
   void WriteSignal(int bitaddr, bool value);

  /**
   * Get input signal.
   *
   * This function provides user level access to input signals. 
   * It executes the virtual pre and post hook methods 
   * and the virtual actual harware access to sample an input signal via DoReadSignal(int). 
   *
   * @param bitaddr
   *   Abstract bit address
   * @return
   *  True for logic level high;
   */
   bool ReadSignal(int bitaddr);


  /**
   * Report cycle time
   *
   * @return
   *   Actual cycle time in ussecs
   */

  virtual int CycleTime() const;

  /**
   * Set cycle time
   *
   * @param cycleTime
   *   Desired cycle time in usecs
   */

  virtual void CycleTime(int cycleTime);

 protected:

  /** Overall configuration (with actual type) */
  TaNameSet<AttributeSignalEvent>* pConfiguration ;

  /** Reverse input map: map signal edges to logical event sets */
  std::map<int, EventSet> mInputPosEdgeIndexMap;

  /** Reverse input map: map signal edges to logical event sets */
  std::map<int, EventSet> mInputNegEdgeIndexMap;

  /** Reverse output map: map signal addres to events that affect the resp. line */
  std::map<int, EventSet> mOutputLevelIndexMap;

  /** Address range */
  int mMaxBitAddress;

  /**  
   * Writes non-event-related configuration to TokenWriter
   *
   * Device data will be written bottom-to-top along the class-hierarchy,
   * see also vDevice::DoWritePreface.
   *
   * Note: in order to keep the outputfile-layout as simple as possible no label will 
   * be used to separate this data-section. 
   *
   * @param rTw
   *   TokenWriter to write
   * @param rLabel
   *   Section to write
   * @param pContext
   *   Context to provide contextual information
   *
   * */
  void DoWritePreface(TokenWriter& rTw, const std::string& rLabel,  const Type* pContext=0) const;

  /**  
   * Reads non-event-related configuration from TokenReader
   *
   * Device date is read bottom-to-top along the class-hierarchy; 
   * see also vDevice::DoReadPreface.
   *
   *
   * Note: in order to keep the inputfile-layout as simple as possible no label will 
   * be used to separate this data-section. 
   *
   * @param rTr
   *   TokenReader to read from
   * @param rLabel
   *   Section to read
   * @param pContext
   *   Read context to provide contextual information
   *
   * */
  virtual void DoReadPreface(TokenReader& rTr,const std::string& rLabel="", const Type* pContext=0);

  /**
   * IO Hook, inputs
   *
   * The background thread calls this hook before reading input signals.
   * You may reimplement this method to e.g. prepare a process image.
   *
   * @return 
   *  True on success, false on error
   *
   */
  virtual bool DoReadSignalsPre(void) {return true;};

  /**
   * IO Hook, inputs
   *
   * The background thread calls this hook after reading input signals.
   * You may reimplement this method to e.g. release a process image.
   *
   *
   */
  virtual void DoReadSignalsPost(void) {};

  /**
   * Sample input signal.
   *
   * Reimplement this function to implements actual harware access to sample an input signal. 
   * This function gets
   * called from the periodic background thread to sense edges. 
   * It is guaranteed that the pre-hook was called befor and returned "true".
   * The post-hook will be invoked after relevant signals have been sampled.
   *
   * @param bitaddr
   *   Abstract bit address
   * @return
   *  True for logic level high;
   */
  virtual bool DoReadSignal(int bitaddr)=0;

  /**
   * IO Hook, outputs
   *
   * This hook is invoked before writing a signal value.
   * You may reimplement this method to e.g. assemble a process image.
   *
   * @return 
   *  True on success, false on error
   *
   */
  virtual bool DoWriteSignalsPre(void) {return true;};

  /**
   * IO Hook, output
   *
   * This hook is invoked after writing a signal value.
   * You may reimplement this method to e.g. assemble a process image.
   *
   *
   */
  virtual void DoWriteSignalsPost(void) {};

  /**
   * Reimplement this function in a derived class for actual harware access
   * to set or clear an output signal. Hooks are executed appropriately.
   * If the device is configured for synchronous write, the background task
   * is used to write signals. Otherwise, signal values are written instantly.
   *
   * @param bitaddr
   *   Abstract bit address
   * @param value
   *   True for active/high/1/set;
   *   false for passive/low/0/clr;
   *
   */
  virtual void DoWriteSignal(int bitaddr, bool value)=0;


  /**
   * Loop hook.
   * This function is called once during each cycle of the
   * backgroud thread
   *
   */
  virtual void DoLoopCallback(void) {};


  /** Background: mutex for below shared variables*/
  faudes_mutex_t mMutex;

  /** True for synchronous output writes */
  bool mSyncWrite;

 private:

  /** Background: thread handle (global) */
  faudes_thread_t mThreadSynchro;

  /** Cycle time of background thread in nsecs (shared) */
  int mCycleTime;

  /** Background: cycle counter (shared) */
  int mCycleCount;

  /** Background: cycle count  (global only) */
  int mRecentCycleCount;

  /** Background: type def for edge detection  */
  typedef struct {
    bool current;  //// current value (most recent reading)
    bool past;     //// past value (reading before)
    bool posrel;   //// positive edge is relevant for some input event
    bool negrel;   //// negative edge is relevant for some input event
    bool pos;      //// positive edge detected
    bool neg;      //// negative edge detected
    bool lost;     //// relevant edge has been lost
  } Edges;

  /** Background: accumulated edges (shared)   */
  Edges* mpInputEdges;

  /** Background: recently accumulated edges (global only)   */
  Edges* mpRecentInputEdges;

  /** Background: some input event did occur (shared) */
  bool mInputReady;

  /** Background: type def output values  */
  typedef struct {
    bool current;  //// current value (actual line level)
    bool next;     //// next value (buffered line level, flush on sync write)
    bool edge;     //// value  will change
    bool lost;     //// edgle will be lost
    bool rel;      //// relevant to some output event
  } Levels;

  /** Background: accumulated output values (shared) */
  Levels* mpOutputLevels;

  /** Background: terminate-flag for background task */
  bool mCancelRequest;

  /** clear all input states */
  void ClrInputSignals(void);

  /** clear all output values */
  void ClrOutputSignals(void);

}; 

// declare background thread
void* SDeviceSynchro(void*);

}


#endif

