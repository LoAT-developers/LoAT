/** @file iop_modbus.h Process image via modbus/tcp */

/*
   FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2011, Thomas Moor.

*/



#ifndef FAUDES_IOP_MODBUS_H
#define FAUDES_IOP_MODBUS_H


// Include core-libary and iodevice
#include "corefaudes.h"
#include "iop_vdevice.h"
#include "iop_sdevice.h"
#include "iop_simplenet.h"


// If configured to have a modbus device 
#ifdef FAUDES_IODEVICE_MODBUS

 

namespace faudes {



/**
 * Processimage synchronisation via Modbus/TCP
 *
 * This device is derived from the signal based sDevice to
 * read and write line levels via ethernet using the Modbus/TCP
 * protocol; see also the <a href="http://www.modbus.org">Modbus Organization</a>.  
 * When configured as master, the mbDevice
 * initiates commucation with a specified list of slaves in order
 * to retrieve input line levels and to set output line levels. The latter are
 * locally buffered and are propagated to the event-based interface
 * inherited via the base class sDevice. 
 * When configured as slave, the mbDevice accepts connections from any Modbus
 * master, will response to their request sand update the local line-level buffer accordingly.
 *
 * Further dedatils on the configuration, incl. an example, are provided
 * by the <a href="../reference/simulator_devices.html#ModbusDevice">ModbusDevice user-reference</a>
 *
 * Technical details.
 * - The mbDevice slave implements reading and writing bits/coils/registers/holding registers,
 *   incl. the multi-read/write variants; regardless which commads you use, they all refer
 *   to the one process image implicitly defined by the event configuration.
 * - The mbDevice matser usees the commands read multiple bits and write multiple coils
 *   for process image synchonisation.
 * - All network communication come with quite relaxed timeouts. Please let us know, if
 *   you require more strict timeout behaviour.  
 * - Network communication is currently implemented synchronous with the edge detection
 *   background task; this is restrictive and may be changed in future revisions.
 * - Communication uses an additional line-level buffer; a better solution would be
 *   to share the line buffer with the sDevice; however, this is not supported by the  current 
 *   sDevice interface.
 * - Programatic configuration is still incomplete.
 * - The mbDevice compiles with MinGW/Windows, however, it was not properly tested
 *   in this configuration; please let us know, if you plan to use mbDevice in a
 *   Windows context.
 *
 * Note: This device must be explicitely enabled in Makefile.plugin.
 * 
 * @ingroup  IODevicePlugin
 */

class FAUDES_API mbDevice : public sDevice {

FAUDES_TYPE_DECLARATION(ModbusDevice,mbDevice,mbDevice)

 public:

  /**
   * Default constructor
   */
  mbDevice(void);

  /**
   * Copy constructor (not implemented!)
   */
  mbDevice(const mbDevice&) : sDevice() {};

  /**
   * Explicit destructor.
   */
  virtual ~mbDevice(void);


  /**
   * Clear all configuration (implies Stop)
   */
  virtual void Clear(void);


  /**
   * 
   * Compile to internal data-structures.
   * 
   * Exception in misconfiguration/inconsistencies
   *
   */
  virtual void Compile(void);


  /**
   * Append remotely implemented outputs.
   * You must
   * (re-)compile the mbDevice after adding remote outputs.
   *
   * @param mbid
   *    Remote device id
   * @param mbaddr
   *    bitaddress within the remote device
   * @param cnt
   *    number of output bits to bw written
   * @param fdaddr 
   *    address within local process image
   */
   void AppendRemoteOutputs(int mbid, int mbaddr, int cnt, int fdaddr);


  /**
   * Append remotely implemented inputs.
   * You must
   * (re-)compile the mbDevice after adding remote inputs.
   *
   * @param mbid
   *    Remote device id
   * @param mbaddr
   *    bitaddress within the remote device
   * @param cnt
   *    number of input bits to bw read
   * @param fdaddr 
   *    address within local process image
   */
   void AppendRemoteInputs(int mbid, int mbaddr, int cnt, int fdaddr);

  /**
   * Set server address of this node.
   * Note: you can only set th server address while the
   * device is down.
   *
   * @param rAddr 
   *   IP address of the remote Modbus device, e.g. "localhost:1502"
   * @exception Exception
   *   - No valid address (id 551) (NOT IMPLEMENTED)
   */
  void SlaveAddress(const std::string& rAddr);


  /**
   * Activate the device. 
   * This function opens/initializes a network connection and
   * starts the -background thread for communication and edge detection.
   *
   * @exception Exception
   *   - not yet configured (id not configured)
   *   - failed to network connection (id not configured)
   */
  virtual void Start(void);


  /**
   * Deactivate the device. This function shuts down the network,
   * stops the background thread and sets all output signals to 0.
   */
  virtual void Stop(void);


protected:
   

  /**
   * IO Hook, inputs
   *
   * @return 
   *  True on success.
   *
   */
  virtual bool DoReadSignalsPre(void);

  /**
   * IO Hook, inputs
   */
  virtual void DoReadSignalsPost(void);

  /**
   * Get input signal.
   *
   * Extract bit value from image.
   *
   * @param bitaddr
   *   Abstract bit address
   * @return
   *  True for logic level high;
   */
  virtual bool DoReadSignal(int bitaddr);
  
  /**
   * IO Hook, outputs
   *
   * @return 
   *  True on success
   *
   */
  virtual bool DoWriteSignalsPre(void);

  /**
   * IO Hook, outputs
   *
   */
  virtual void DoWriteSignalsPost(void);

  /**
   * Set output signal.
   *
   * Set value of bit in process image.
   *
   * @param bitaddr
   *   Abstract bit address
   * @param value
   *   True for logic level high;
   *
   */
  virtual void DoWriteSignal(int bitaddr, bool value);


  /**
   * Loop hook.
   *
   * This function is called once during each cycle of the
   * backgroud thread. It implements the actual communication via Modbus/TCP.
   *
   */
  virtual void DoLoopCallback(void);

  /** 
   * Read non-event-related configuration data from tokenreader
   *
   * @param rTr
   *   TokenReader to read from
   * @param rLabel
   *   Section to read
   * @param pContext
   *   Read context to provide contextual information
   *
   */
  void DoReadPreface(TokenReader& rTr,const std::string& rLabel="", const Type* pContext=0);

  /**  
   * Write non-event-related configuration data to tokenreader
   *
   * @param rTw
   *   TokenWriter to write
   * @param rLabel
   *   Section to write
   * @param pContext
   *   Context to provide contextual information
   * 
   */
  void DoWritePreface(TokenWriter& rTw, const std::string& rLabel,  const Type* pContext) const ;


  /** Role: master/slave */
  bool mMasterRole;

  /** IP addresses */
  SimplenetAddress mSlaveAddress;

  /** Modbus address ranges */
  typedef struct {
    bool mInputs;
    int mMbId;
    int mMbAddress;
    int mFdAddress;
    int mCount;
  } IoRange;
  std::vector< IoRange > mSlaveIoRanges;    

  /** Remote process image buffer */
  int mImageSize;
  char* mpImage;
  char* pInputImage;
  char* pOutputImage;
  char* mpOutputMask;

  /** Background thread: tcp connection to remote slave */
  int mSlaveSocket;
  int mRequestCount;
  char* mMessage;
  int   mMessageLen;
  int   mRequestId;

  /** Background thread: tcp connection to remote masters */
  std::vector<int> mMasterSockets;

  /** I/O helper */
  int  MbFlushBuffers(void);
  int  MbSendRequest(int id);
  int  MbReceiveResponse(void);
  int  MbReceiveRequest(int mastersock);
  int  MbSendResponse(int mastersock);


}; //class spiDevice

} //namespace 


#endif // configured

#endif // include
