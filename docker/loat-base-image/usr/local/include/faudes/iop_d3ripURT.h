/** @file iop_d3ripURT.h iodevice for d3ripURT protocol and friends */

/*
  FAU Discrete Event Systems Library (libfaudes)

  Copyright (C) 2011 Ece Schmidt, Klaus Schmidt, Ulas Turan

*/




#ifndef FAUDES_IOP_D3RIP_URT_H
#define FAUDES_IOP_D3RIP_URT_H



#include "corefaudes.h"

//only compile with D3RIP-URT protocol operation
#ifdef FAUDES_IODEVICE_D3RIP_URT


#include "iop_vdevice.h"
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <mqueue.h>
#include <sys/stat.h>
#include <vector>
#include <map>

namespace faudes {

#define D3RIP_RT_MESSAGE_MAX_LENGTH 186
#define D3RIP_URT_MAX_PARAMETERS_COUNT 5
#define D3RIP_URT_MAX_EVENT_COUNT 5

enum {
D3RIP_URT_EVENT_ID=0,
D3RIP_URT_CHANNEL_TO_TRANSMIT,
D3RIP_URT_PARAMETER_COUNT,
D3RIP_URT_HEADER_SIZE
};

enum {
D3RIP_URT_DESTIONATION_NODE=0,
D3RIP_URT_DESTIONATION_CHANNEL,
D3RIP_URT_ELIGIBILITY_TIME,
D3RIP_URT_DEADLINE_TIME,
D3RIP_URT_PARAMETER_SIZE
};

typedef struct {
  int destinationNode;
  int destinationChannel;
  int eligibilityTime;
  int deadlineTime;  
}ParameterRecord;

/**
 * Configuration of D3RIP_URT Output Event parameters
 * 
 * This class assists to extract the content of Ouput Event specification by using TokenReader. 
 * Note that D3RIP related parameters should be attached to each Ouput Event.
 *
 */

class AttributeD3ripURTOutput : public AttributeVoid {

FAUDES_TYPE_DECLARATION(Void,AttributeD3ripURTOutput,AttributeVoid)

public:

  /** Default constructor (no triggers) */
  AttributeD3ripURTOutput(void) : AttributeVoid() {};

  /** Copy - constructor */
  AttributeD3ripURTOutput(const AttributeD3ripURTOutput& rOtherAttr) : AttributeVoid() 
      { DoAssign(rOtherAttr); };

  /** Test for default value (never) */
  virtual bool IsDefault(void) const {return false;};

  /** Clear */
  virtual void Clear(void) { 
    mChannelToTransmit=0;
  };

  /** Channel number for transmitting the event */
  int mChannelToTransmit;
  
  /** Consistent event IDs should be given at all controllers */
  int mEventId;

  /** Bunch of D3RIP related parameters  */
  std::vector<ParameterRecord> mParameterRecords;

 protected:

  /**
   * Copy method
   *
   * @param rSrcAttr
   *   Source to copy from
   * @return
   *   Ref to this attribute
   */
  void DoAssign(const AttributeD3ripURTOutput& rSrcAttr);

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

}; // end class AttributeD3ripURTOutput






/**
 * Configuration of D3RIP_URT Input Event parameters
 * 
 * This class assists to extract the content of Input Event specification by using TokenReader.
 * It should be noted that only mEventId is required for Input Events. It is not necessary to specify 
 * D3RIP related parameters for Input Events
 *
 */

class AttributeD3ripURTInput : public AttributeVoid {

FAUDES_TYPE_DECLARATION(Void,AttributeD3ripURTInput,AttributeVoid)

public:

  /** Default constructor (no triggers) */
  AttributeD3ripURTInput(void) : AttributeVoid() {};

  /** Copy constructor */
  AttributeD3ripURTInput (const AttributeD3ripURTInput& rOtherAttr) : AttributeVoid() 
      { DoAssign(rOtherAttr); };

  /** Test for default value (never) */
  virtual bool IsDefault(void) const {return false;};

  /** Clear */
  virtual void Clear(void) { /* set myself to default values */;};
  
  /** Consistent event IDs should be given at all controllers */
  int mEventId;

 protected:

  /**
   * Copy method
   *
   * @param rSrcAttr
   *   Source to copy from
   * @return
   *   Ref to this attribute
   */
  void DoAssign(const AttributeD3ripURTInput& rSrcAttr);

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

}; // end class AttributeD3ripURTInput




/**
 * Configuration of an d3ripURT event as input or output
 *
 * This class is derived from the AttributeDeviceEvent to specialise
 * for d3ripURT based input and output mapping.
 *
 */

class AttributeD3ripURTEvent : public AttributeDeviceEvent {

FAUDES_TYPE_DECLARATION(Void,AttributeD3ripURTEvent,AttributeDeviceEvent)

 public:

  /** Default constructor (no mapping at all) */
  AttributeD3ripURTEvent(void);

  /** Copy constructor */
  AttributeD3ripURTEvent(const AttributeD3ripURTEvent& rOtherAttr); 

  /** Test for default value (never) */
  virtual bool IsDefault(void) const {return false;};

  /** Clear */
  virtual void Clear(void)  { AttributeDeviceEvent::Clear(); };

  /**  Get output mapping */
  const AttributeD3ripURTOutput*  Outputp(void) const {
    return static_cast<AttributeD3ripURTOutput*>(mpOutputAttribute); };

  /**  Get input mapping */
  const AttributeD3ripURTInput*  Inputp(void) const {
    return static_cast<AttributeD3ripURTInput*>(mpInputAttribute); };

 protected:

  /** DoAssign */
  void DoAssign(const AttributeD3ripURTEvent& rSrc)  
  { AttributeDeviceEvent::DoAssign(rSrc);};

  /** Prototype, input (construct on first use static) */
  static const AttributeD3ripURTInput* InputPrototypep(void);

  /** Prototype, output (construct on first use static) */
  static const AttributeD3ripURTOutput* OutputPrototypep(void);

}; // class AttributeD3ripURTEvent


/**
 * Provides the interface between simfaudes and D3RIP protocol running on the same host
 *
 * @section SecIodeviceD3RipUrtDev1 Networking
 * The d3ripURTDevice assists in the exchange of the logical events belonged to the 
 * controllers over network utilizing D3RIP. It is similar to the SimpleNet device 
 * in some manner, however, d3ripURTDevice provides deterministic time bounds for 
 * the transmission of logical events through Ethernet. This device just provides 
 * required access to the underlying D3RIP implementation from the libFAUDES simulator. 
 * Note that D3RIP implementation and IEEE 1588 Synchronization deamon should be seperately
 * provided for the desired operation. 
 * 
 * @section SecIodeviceD3RipUrtDev1 Protocol Details
 * Though d3ripURTDevice does not implement the D3RIP, it should be aware of the corresponding 
 * protocol parameters assigned for each output logical event. Token IO is used in section 
 * "D3ripURTDevice" while extracting those parameters. Detailed information about protocol related 
 * parameters can be obtained by referring to the D3RIP specification. A simple controller may have:
 * 
 * @code
 * <D3ripURTDevice name="ControllerB_Net"> 
 * <!-- Time scale in ms/ftiu -->
 * <TimeScale value="1000"/> 
 *
 * <!-- Event configuration -->
 * <EventConfiguration> 
 * 
 * <Event name="?lambda" iotype="output">
 * <EventId value="1"/>
 * <ChannelToTransmit value="1"/>
 * <ParameterRecord name="11">
 * <DestinationNode value="1"/>
 * <DestinationChannel value="1"/>
 * <EligibilityTime value="2" />
 * <DeadlineTime value="5"/>
 * </ParameterRecord>
 * </Event>
 * 
 * <Event name="!lambda" iotype="input">
 * <EventId value="2"/>
 * </Event>
 * 
 * <Event name="lambda" iotype="output">
 * <EventId value="3"/>
 * <ChannelToTransmit value="1"/>
 * <ParameterRecord name="11">
 * <DestinationNode value="2"/>
 * <DestinationChannel value="1"/>
 * <EligibilityTime value="2" />
 * <DeadlineTime value="5"/>
 * </ParameterRecord>
 * </Event>
 * 
 * </EventConfiguration> 
 * 
 * </D3ripURTDevice> 
 * @endcode
 *
 * 
 * @section SecIodeviceD3RipUrtDev1 Notes
 * This device compiles flags under Linux only and should be linked to realtime library (-lrt). 
 *
 * @ingroup IODevicePlugin
 */

class d3ripURTDevice : public vDevice {

  // provide access to background tasks
  friend void* DoListenCLModule(void*);

FAUDES_TYPE_DECLARATION(D3RipUrtDevice,d3ripURTDevice,vDevice)



public:

  /**
  * Array to store Event parameters statically in the form:
  * ||| EventID | Channel To Transmit | Parameter Count || DESTIONATION_NODE | DESTIONATION_CHANNEL | ELIGIBILITY_TIME | DEADLINE_TIME | ... |||
  */
  unsigned char mEventParameters[D3RIP_URT_MAX_EVENT_COUNT][D3RIP_URT_HEADER_SIZE+D3RIP_URT_PARAMETER_SIZE*D3RIP_URT_MAX_PARAMETERS_COUNT]; 
  
  /** Status for receiving events from D3RIP */
  int mContinueListening;
  
  /** Used for sending events to D3RIP */
  mqd_t mMQueueToSend;
  
  /** Used for receiving events from D3RIP */
  mqd_t mMQueueToReceive;
  
  /** Thread created for listening incoming events */
  pthread_t mThreadListenModule;
  
  /** will be modified by WriteOutput and send by FlushOutput */
  unsigned char mCommunicationRequestCount;
  
  /** Buffer for outgoing  events */
  ParameterRecord mCommunicationRequests[D3RIP_URT_MAX_EVENT_COUNT*D3RIP_URT_MAX_PARAMETERS_COUNT];
  
  /** Stores the total number of events in the system configuration */
  unsigned char mEventCount;
  
  /** Stores the total number of events to be send over D3RIP */
  unsigned char mEventsToSendCount;
  
  /** Stores the Ids for outgoing events */
  unsigned char mEventIdsToSend[D3RIP_URT_MAX_EVENT_COUNT];

  /** It is needed to assign a common Ids to the logical events at all controller nodes for the sake of consistency */
  std::map<std::string, int> mEventIdMap;

  /**
   * Default constructor
   */
  d3ripURTDevice(void);

  /**
   * Copy constructor [not functional, since DoAssign is not implemented]
   */
  d3ripURTDevice(const d3ripURTDevice& rSrc) : vDevice() 
      { DoAssign(rSrc); };

  /**
   * Explicit destructor.
   */
  virtual ~d3ripURTDevice(void);


  /**
   * Clear all configuration.
   * This implies Stop().
   */
  virtual void Clear(void);

  /**
   * 
   * Build up internal data-structure(e.g. signal-event - mapping and extract D3RIP parameters)
   *
   */
  virtual void Compile(void);


  /**
   * Activate the device. This function enables output execution and input reading.
   *
   * Configure for real-time operation and create D3RIP listener thread.
   *
   * @exception Exception
   *   - Not yet configured (id 551)
   */
  virtual void Start(void);

  /**
   * Deactivate the device. This function disables output execution and input reading.
   */
  virtual void Stop(void);

  /** Clear dynamic data and restart device */
  virtual void Reset(void);


  /**
   * Prepare the outgoing buffer regarding D3RIP specifications
   *
   * @exception Exception
   *   - unknown output event (id 65)
   */
  virtual void WriteOutput(Idx output);

  /**
  * Forward all ready-to-send events to the D3RIP for tranmission to other controllers
  *
  * @exception Exception
  *   - unknown output event (id 65)
  */
  void FlushOutput(unsigned char channel);

 protected:

  /** Overall configuration (with actual type) */
  TaNameSet<AttributeD3ripURTEvent>* pConfiguration;


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

  /**  Reads non-event-related configuration from TokenReader
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

  // dummies
  void DoAssign(const d3ripURTDevice& rSrcAttr){};
  virtual bool DoEqual(const d3ripURTDevice& rSrcAttr) const { return false;};

 private:

}; 

void* DoListenCLModule(void* pD3ripURTDevice);
}

#endif // configure
#endif // include

