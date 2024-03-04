/** @file iop_vdevice.h Virtual device for interface definition  */

/*
  FAU Discrete Event Systems Library (libfaudes)

  Copyright (C) 2008, Thomas Moor
  Exclusive copyright is granted to Klaus Schmidt

*/



#ifndef FAUDES_VDEVICE_H
#define FAUDES_VDEVICE_H

#include "corefaudes.h"
#include "tp_include.h"
#include "sp_densityfnct.h"



// Note: iodevice debuggung uses direct console output since
// std redirection is not threadsafe.

// Debugging: io level
#ifdef FAUDES_DEBUG_IODEVICE
#define FD_DH(message) FAUDES_WRITE_DIRECT("FAUDES_IODEVICE: " << message)
#else
#define FD_DH(message)
#endif


// Debugging: io level verbose
#ifdef FAUDES_DEBUG_IOVERBOSE
#define FD_DHV(message) FAUDES_WRITE_DIRECT("FAUDES_IODEVICE: " << message)
#else
#define FD_DHV(message)
#endif


// Debugging: io performance  
#ifdef FAUDES_DEBUG_IOPERF
#define FD_DHT(message) FAUDES_WRITE_DIRECT("FAUDES_IOTIMING: " << message)
#else
#define FD_DHT(message)
#endif


// Max number of time stamps for performance monitor
#define FAUDES_DEBUG_IOPERF_SAMPLES 10000



namespace faudes {



/**
 * Attribute for the configuration of a input or output mapping
 *
 * The base class for all device event attributes only distinguishes between
 * output and input events. The actual attribute is of type AttributeVoid.
 * Derived classes are meant to override this type in order to provide the
 * defining data for the actual mapping of physical and logical events.
 *
 */

class FAUDES_API AttributeDeviceEvent : public AttributeVoid {

  FAUDES_TYPE_DECLARATION(Void,AttributeDeviceEvent,AttributeVoid)

    public:

  /** Default constructor (no attributes, aka undefined) */

  AttributeDeviceEvent(void);

  /** Copy constructor */
  AttributeDeviceEvent(const AttributeDeviceEvent& rOtherAttr);

  /** Destructor */
  virtual ~AttributeDeviceEvent(void);

  /** Clear */
  virtual void Clear(void);

  /** Test for default value (undefined) */
  virtual bool IsDefault(void) const {return (!mpOutputAttribute &&  !mpInputAttribute); };

  /** Does this attribute define an output mapping? */
  bool IsOutput(void) const {return mpOutputAttribute!=0; };

  /** Does this attribute define a input mapping? */
  bool IsInput(void) const {return mpInputAttribute!=0; };

  /** Set to default output attribute */
  void DefaultOutput(void) {
    Clear();
    mpOutputAttribute= pOutputPrototype->New();
  };

  /** Set to default input attribute */
  void DefaultInput(void) {
    Clear();
    mpInputAttribute= pInputPrototype->New();
  };

  /** Set output attribute */
  virtual void Output(const AttributeVoid&  rOutputAttribute) {
    DefaultOutput();
    mpOutputAttribute->Assign(rOutputAttribute);
  };

  /** Set input attribute */
  virtual void Input(const AttributeVoid&  rInputAttribute) {
    DefaultInput();
    mpInputAttribute->Assign(rInputAttribute);
  };

  /** Read output attribute */
  virtual void ReadOutput(TokenReader&  rTr) {
    DefaultOutput();
    mpOutputAttribute->Read(rTr);
  };

  /** Read input attribute */
  virtual void ReadInput(TokenReader&  rTr) {
    DefaultInput();
    mpInputAttribute->Read(rTr);
  };

  /**  Get output mapping (return 0 if its not an output) */
  const AttributeVoid*  Outputp(void) const {return mpOutputAttribute; };

  /**  Get input mapping (return 0 if its not a input) */
  const AttributeVoid*  Inputp(void) const {return mpInputAttribute; };


protected:

  /** Output Attribute (use cast in derived classes) */
  AttributeVoid* mpOutputAttribute;

  /** Input Attribute (use cast in derived classes) */
  AttributeVoid* mpInputAttribute;

  /** Output Prototype (set to nontrivial attribute in derived classes) */
  const AttributeVoid* pOutputPrototype;

  /** Input Prototype (set to nontrivial attribute in derived classes) */
  const AttributeVoid* pInputPrototype;

  /** Fallback attribute type (initialize on first use static construct)*/
  static const AttributeVoid* FallbackAttributep(void);

  /**
   * Assignment 
   *
   * @param rSrcAttr
   *   Source to copy from
   * @return
   *   Ref to this attribute
   */
  void DoAssign(const AttributeDeviceEvent& rSrcAttr);


  /**
   * Reads the attribute from TokenReader, see AttributeVoid for public wrappers.
   *
   * If the current token indicates an "Input" or "Output" section, the method reads that
   * section. Else it does nothing. Exceptions may only be thrown
   * on invalid data within the section. The label argument is ignored.
   * The context argument is ignored.
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
   * Writes all present device event attributes to include the defining data.
   * The label argument is ignored, we use hardcoded labels "Input" or "Output".
   * The context argument is ignored.
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



}; // class AttributeDeviceEvent



/**
 * Virtual base class to define the interface for event io.
 *
 * @section IOPvdeviceA Input and Output event IO
 *
 * A vDevice provides an virtual interface to execute output events and sense
 * input events, ie ReadInput() and WriteOutput(). The latter is prepared to
 * be organized as a background thread that accumulates events in an internal fifo buffer.
 * Once a input event has been read by the application, the buffer is cleared.
 * A device is configured by passing an event set with device event attributes. The virtual
 * base class formalls takes void attributes, and uses a dynamic cast to the actual attribute 
 * type that is provided by any derived class.
 *
 * @section IOPvdeviceB Physical Time
 *
 * The vDevice defines an interface to access the current physical time. The default
 * implementation has msec resolution and is based on the system clock. Time may be queried
 * in ms by CurrentTimeMs() or in faudes time unis (ftu) by CurrentTime(). Faudes time units
 * refer to defining data in eg guards and invariants of timed automata or stochastical
 * execution properties. Conversion to physical time is by the factor mTimeScale given in
 * msecs per ftu. There is also a default implementation WaitInputs() for timed waiting
 * for events based on condition variables.
 * This requires a derived class to send the according signal. Both, physical
 * time and waiting for events, may be overwritten in derived classes.
 *
 * @section IOPvdeviceC Operating Status
 *
 * The device may be in one of four operating states Down, StartUp, Up or ShutDown. Once configured
 * you may Start() the device. The device will assychonously allocate required resources
 * and if successful eventually be in state Up. While the device is Up, you can write
 * outputs and read events. You can request the device to release resources by calling
 * Stop(). While Up, you may also Reset() the device, to set outputs in passive state,
 * to reset physical time to zero and tu flush the input fifo buffer.
 *
 * @section IOPvdeviceD File IO
 *
 * The vDevice provides std faudes token io interface via faudes::Type. In addition,
 * there is a static constructor FromTokenreader() to construct a vDevice
 * object of specific type as indentifiesd by the token section.
 * 
 * @section Techical Note
 *
 * The vDevice derived classes implement std faudes type semantics for 
 * token IO plus the New() factory function to support type registration required for 
 * XML formated files. Assignment and comparison are, however, not implemented.
 *
 * @ingroup IODevicePlugin
 */

class FAUDES_API vDevice : public Type {


  friend class xDevice;


 public:

  /** Enum for device stages */
  typedef enum { Down, StartUp, Up , ShutDown } DeviceState;

  /**
   * Default constructor
   */
  vDevice(void);

  /**
   * Construct on heap from token reader.
   *
   * This constructor examines the token strean, determines the coressponding
   * class and constructs the device on the heap. Todo: the implementation
   * of this function is a hack, there must be proper
   * solution to this issue.
   *
   * @param rTr
   *   TokenReader to read from
   * @return
   *  vDevice pointer
   *
   * @exception Exception
   *   - token mismatch (id 552)
   *   - IO errors (id 1)
   */
  static vDevice* FromTokenReader(TokenReader& rTr);

  /**
   * Construct on heap from file.
   *
   * This constructor examines the file, determines the coressponding
   * class and constructs the device on the heap.
   *
   * @param rFileName
   *   Filename
   * @return
   *  vDevice pointer
   *
   * @exception Exception
   *   - token mismatch (id 552)
   *   - IO errors (id 1)
   */
  static vDevice* FromFile(const std::string& rFileName);


  /**
   * Explicit destructor.
   */
  virtual ~vDevice(void);


  /**
   * Set the device name
   *
   * @param rName
   *   Generator name
   */
  void Name(const std::string& rName);

  /**
   * Get device name
   *
   * @return
   *   Name of generator
   */
  const std::string& Name(void) const;


  /**
   * Set tolerance for time synchonisation.
   *
   * @param maxgap
   *   Max acceptable amount of time by which the generator may be behind device time.
   *
   */
  void Tolerance(Time::Type maxgap) {mMaxSyncGap=maxgap;};


  /**
   * Get tolerance.
   *
   * @return
   *   Max acceptable amount of time by which the generator may be behind device time
   *
   */
  Time::Type Tolerance(void) {return mMaxSyncGap;};


  /**
   * Set timescale.
   *
   * @param scale
   *   Conversion factor in msecs/ftu  (faudes time units)
   *
   */
  virtual void TimeScale(unsigned int scale) {mTimeScale=scale; CurrentTime(0); };


  /**
   * Get timescale.
   *
   * @return
   *   Conversion factor in msecs/ftu  (faudes time units)
   *
   */
  virtual int TimeScale(void) {return mTimeScale;};


  /**
   * Clear all configuration.
   * This implies Stop().
   */
  virtual void Clear(void);

  /**
   * Insert/edit input or output configuration
   *
   * For a nontrivial device, a dynamic cast is used to
   * access the attribute parameter.
   *
   * @param event
   *   Input or output event by faudes index
   * @param attr
   *   Configuration attribute
   * @exception Exception
   *   - unknown event (id 65)
   *   - Cannot cast attribute (id 550)
   */
  virtual void Configure(Idx event, const AttributeDeviceEvent& attr);

  /**
   * Configure by alphabet
   *
   * For a nontrivial device, a dynamic cast is used to
   * access atributes of the alphabet parameter.
   *
   * @param rPhysicalEvents
   *   Event set with configuration attributes
   * @exception Exception
   *   - Cannot cast argument (id 550)
   */
  virtual void Configure(const EventSet& rPhysicalEvents);


  /**
   * Compile inner data-structures. 
   *
   * As every derived class may have its own individual inner data-structures to
   * set up, it has to reimplement its own Compile()-function if needed.
   *
   * In the base class Compile() builds up the input- and output event set.
   * 
   */
  virtual void Compile(void);


  /**
   * Get outputs as plain set.
   *
   * @return
   *   Set of all configured outputs
   */
  virtual const EventSet& Outputs(void) const;

  /**
   * Get inputs as plain set.
   *
   * @return
   *   Set of all configured inputs
   */
  virtual const EventSet& Inputs(void) const;


  /**
   * Reset device. Resets any dynamic state such as edge detection.
   * Since the vDevice only provides timing, it only resets the current faudes
   * time to zero. A reset does not stop the device.
   *
   */
  virtual void Reset(void);

  /**
   * A device may ask for a reset by returning true for ResetRequest(). A well behaved
   * simulator application will perform a Reset() and initialise any faudes::Executors,
   * and stop the simulation. The device is meant to cancel any pending WaitInputs() 
   * or WaitInputsMs() when it requests a reset. The default implementation returns 
   * false;
   *
   * @return 
   *   True, if a reset is requested
   *
   */
  virtual bool ResetRequest(void);

  /**
   * Activate the device. This function enables output execution and input reading.
   * It will allocate device specific necessary resources eg start a background thread,
   * initialise operating system device drivers etc.
   *
   * @exception Exception
   *   - Not yet configured (id 551)
   */
  virtual void Start(void);

  /**
   * Deactivate the device. This function disables output execution and input reading.
   * Stop also runs Reset.
   *
   */
  virtual void Stop(void);

  /**
   * Get status. This function returns the current status of the device.
   * In derived classes that use background threads for input reading etc,
   * a device may change its status without notice. Stop runs Reset()
   *
   */
  virtual DeviceState Status(void) { return mState;};

  /**
   * Get status as infromal string.
   *
   */
  virtual std::string StatusString(void);


  /**
   * Run output command.
   *
   * @exception Exception
   *   - unknown output event (id 65)
   *
   */
  virtual void WriteOutput(Idx output)=0;

  /**
   * Flush pending IO Operations
   *
   * A device may implement buffered output operations, i.e. to assemble a process 
   * image befor applying it to the physical plant. 
   * By FlushOutputs() you can ask the device to execute all buffered
   * output operations. FlushOutputs() is called by 
   * WaitInputs() and WaitInputsMs(), so buffers are automatically
   * flushed when the simulation waits for input events.
   * The default impelmentation of FlushOutputs() does nothing.
   *
   */
  virtual void FlushOutputs(void);

  /**
   * Read sensed input events.
   * Report the oldest event from the internal input buffer.
   * The event is removed from the buffer. The function returns
   * 0 if the buffer is empty.
   *
   */
  virtual Idx ReadInput(void);

  /**
   * Peek for sensed events.
   * Report the oldest input-event from the buffer. However,
   * dont remove the event.
   *
   * @return
   *   Input-event index or 0 if no such available.
   */
  virtual Idx PeekInput(void);


  /**
   * Report whether a input-event is ready
   */
  virtual bool InputReady(void);


  /**
   * Wait for input trigger.
   *
   * The default implementation assumes that inputs events are
   * notified via the condition signal. The duration to wait
   * is specified in faudes time units (ftu) and is converted to system time
   * by the scaling factor mTimeScale (ms/ftu).
   *
   * @return
   *   True, if events are available for read.
   */
  virtual bool WaitInputs(Time::Type duration);

  /**
   * Wait for input trigger.
   *
   * Same as WaitInputs, but with the maximum time to wait given in
   * msecs.
   *
   * @return
   *   True, if events are available for read.
   */
  virtual bool WaitInputsMs(long int duration);


  /**
   * Report physical time in ftu.
   *
   * The time elapsed since the last reset is retunred
   * in faudes time units (ftu).
   *
   * @return
   *   Physical time.
   */
  virtual Time::Type CurrentTime(void);

  /**
   * Report physical time in ms
   *
   * The time elapsed since the last reset is returned
   * in msecs.
   *
   * @return
   *   Physical time.
   */
  virtual long int CurrentTimeMs(void);

  /**
   * Set physical time in ftu.
   * @param now
   *   physical time in faudes time units (ftu).
   */
  virtual void CurrentTime(Time::Type now);


  /**
   * Set physical time in ms.
   * @param nowms
   *   physical time in msec
   */
  virtual void CurrentTimeMs(long int nowms);


  /**
   * Convert faudes time unit duration to system time
   *
   * Note: this helper function is not static since it refers to
   * the parameter mTimeScale.
   *
   * @return
   *  Absolut system-time form now + duration in the future
   * @param duration
   *  Time in faudes-time
   */
  virtual faudes_systime_t FtuToSystemTime(Time::Type duration);

  /** Tell the device which condition to use for waiting */
  void UseCondition(faudes_mutex_t* wmutex, faudes_cond_t* wcond);

  /** Tell the device which buffer to use for inputs */
  void UseBuffer(faudes_mutex_t* bmutex, std::deque<Idx>* bbuffer);

  /** Convenience method */
  virtual std::string EStr(Idx ev) {return Inputs().Str(ev);};

  /** Get performance (need compiletime option) */
  SampledDensityFunction Performance(void);

  /** Clear performance (need compiletime option) */
  void ResetPerformance(void);

  /** Convenience method */
  void WritePerformance(void);

  /** 
   * Stop all devices.
   * This function is intended to be called on ungraceful termination of a
   * simulater application. It uses a global variable that tracks all device 
   * instances. 
   *
   */
  static void StopAll(void);

 protected:

  /**
   * Token output, see Type::Write for public wrappers.
   * The vDevice inplements token writing to consist of  DoWritePreface (device name and time scale).
   * and DoWriteConfiguration (device specific event attributes). The default label is taken from the 
   * member variable mDefaultLabel. Derived classes are meant to set mDefaultLabel in their constructor
   * and to reimplement DoWritePreface to add additional data eg cycle time or network address.
   * The parameter pContext is ignored and passed on.
   *
   * @param rTw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of section to write, defaults to name of set
   * @param pContext
   *   Write context to provide contextual information
   */
  virtual void DoWrite(TokenWriter& rTw, const std::string& rLabel="", const Type* pContext=0) const;

  /**  Writes non-event-configuration data from TokenWriter
   *
   * This function is part of the non-event-configuration token-output mechanism. The vDevice will write
   * its name and the time scale, derived classes are meant to first call the base class method and then
   * add additional configuration parameter. 
   *
   * Note: in order to keep the inputfile-layout as easy as possible no label will be used to separate
   * this data-section. Never the less a default-label ("Device") is specified.
   *
   * @param rTw
   *   TokenWriter to write to
   * @param rLabel
   *   Section to read
   * @param pContext
   *   Provide contextual information
   *
   * */
  virtual void DoWritePreface(TokenWriter& rTw, const std::string& rLabel="", const Type* pContext=0) const;


  /** Writes event-configuration to TokenWriter
   *
   * This function is part of the event-configuration token-output mechanism. It writes the device-specific
   * event-configuration to provided TokenWriter. It uses the virtual interface of TBaseSet to figure the
   * actual attribute type.
   *
   * Note: the event-configuration will be labeled by "EventConfiguration"
   *
   * @param rTw
   *   TokenWriter to write to
   * @param rLabel
   *   Section to write
   * @param pContext
   *   Provide contextual information
   *
   */
  virtual void DoWriteConfiguration(TokenWriter& rTw, const std::string& rLabel="", const Type* pContext=0) const;

  /**
   * Token input, see Type::DRead for public wrappers.
   * The vDevice implkements token input to consist of DoReadPreface (name, time scale etc) and DoReadConfiguration
   * (events attributes), followed by Compile (set up internal data structures). The default label is given by
   * the member variable mDefaultLabel. Derived classes arte meant to set mDefaultLabel in their constructor and
   * to reimplement DoReadPreface to cover additional parameters. The pContext parameter is ignored.
   *
   * @param rTr
   *   Reference to TokenReader
   * @param rLabel
   *   Label of section to write, defaults to name of set
   * @param pContext
   *   Write context to provide contextual information
   */
  virtual void DoRead(TokenReader& rTr, const std::string& rLabel = "", const Type* pContext=0);

  /** Default label for token io */
  std::string mDefaultLabel;

  /**  Reads non-event-configuration data from TokenReader
   *
   * This function is part of the non-event-configuration token-input mechanism and located at the top
   * of the class hierarchy. The vDevice will read its name and the time scale, derived classes are meant 
   * to first call the base class method and then read add additional configuration parameters. 
   *
   * Note: in order to keep the inputfile-layout as easy as possible no label will be used to separate
   * 	   this data-section. Never the less a default-label ("Device") is specified.
   *
   * @param rTr
   *   TokenReader to write
   * @param rLabel
   *   Section to read
   * @param pContext
   *   Provide contextual information
   *
   */
  virtual void DoReadPreface(TokenReader& rTr, const std::string& rLabel = "", const Type* pContext=0);

  /** Reads event-configuration data from TokenReader
   *
   * This function is part of the token-input mechanism and reads the device-specific event-configuration.
   * It uses the virtual interface of TBaseSet to figure the actual attribute type. The section defaults to
   * "EventConfiguration".
   *
   * @param rTr
   *   TokenReader to read
   * @param rLabel
   *   Section to read
   * @param pContext
   Provide contextual information
   * */
  virtual void DoReadConfiguration(TokenReader& rTr, const std::string& rLabel = "", const Type* pContext=0);

  /** Name */
  std::string mName;

  /** Overall event configuration (uses cast for type) */
  EventSet* mpConfiguration;

  /** All inputs */
  EventSet mInputs;

  /** All outputs */
  EventSet mOutputs;

  /** Status: running, starting etc */
  DeviceState mState;

  /** Default Wait Condition Mutex */
  faudes_mutex_t mWaitMutex;

  /** Default Wait Condition */
  faudes_cond_t mWaitCondition;

  /** Actual  Wait Condition Mutex*/
  faudes_mutex_t* pWaitMutex;

  /** Actual Wait Condition */
  faudes_cond_t* pWaitCondition;

  /** physical timepoint zero  */
  faudes_systime_t mTimeZero;

  /** FauDES-time: scaling factor in ms/ftu */
  int mTimeScale;

  /** Toleance for time sync */
  Time::Type mMaxSyncGap;

  /** Default Fifo buffer for input readings */
  std::deque<Idx> mInputBuffer;

  /** Actual Fifo buffer for input readings */
  std::deque<Idx>* pInputBuffer;

  /** Default mutex for input buffer (mutexted) */
  faudes_mutex_t mBufferMutex;

  /** Actual mutex for input buffer (mutexted) */
  faudes_mutex_t* pBufferMutex;

  /** Reset request marker (mutexed) */
  bool mResetRequest; 
  
  /**
   * convert duration from fauDES-time units to ms
   *
   */
  virtual long int FtuToMs(Time::Type faudes_time);

  /**
   * convert duration in ms to faudes-time units
   *
   */
  virtual Time::Type MsToFtu(long int real_time);


#ifdef FAUDES_DEBUG_IOPERF

  /** Filename for performance log */
#define FAUDES_DEBUG_IOPERF_LOG "tmp_ioperformance.txt"

  /** Structures to store time-samples in */
  faudes_systime_t* mpPerformanceWaitEnter;
  faudes_systime_t* mpPerformanceWaitExit;

  /** Global iterator */
  int mPerformanceEndIterator;
  int mPerformanceBeginIterator;

#endif

 private:

  // track all devices (initialize on first use construct)
  static std::set<vDevice*>& AllDevices(void);

}; // end class vDevice



} // namespace faudes


#endif

