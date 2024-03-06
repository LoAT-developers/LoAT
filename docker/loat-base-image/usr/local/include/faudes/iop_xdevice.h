/** @file iop_xdevice.h Virtual device for interface definition  */

/*
   FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2008, Thomas Moor
   Exclusive copyright is granted to Klaus Schmidt

*/



#ifndef FAUDES_XDEVICE_H
#define FAUDES_XDEVICE_H

#include "corefaudes.h"
#include "tp_include.h"
#include "iop_vdevice.h"





namespace faudes {




/**
 * Container of devices.
 *
 * The xDevices is a container of vDevices. Input readings are
 * combined in a union fashion over all participating devices,
 * output writings are dispatched to the relevant device. Formally,
 * the xDevice class is derived from the vDevice class to provide the
 * same interaface to a simulator. Ie, the application does not
 * need to know whether is acts on a single vDevice or an xDevice. This
 * is also true for configuration from file, but of cause not for programatical
 * configuration. An xDevice may not be configured to have individual
 * outputs or inputs, but to hold particular vDevices.
 *
 * Technical detail: the xDevice uses the vDevice interface to register a
 * common event fifo buffer and a common condition variable. Thus, the xDevice only works
 * with devices that support this configuration feature.
 *
 * @ingroup IODevicePlugin
 */

class FAUDES_API xDevice : public vDevice {

FAUDES_TYPE_DECLARATION(DeviceContainer,xDevice,vDevice)


 public:


  /** Iterator for const access to individual devices*/
  typedef std::vector<vDevice*>::const_iterator Iterator;


  /**
   * Default constructor
   */
  xDevice(void);

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
  static xDevice* FromTokenReader(TokenReader& rTr);

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
  static xDevice* FromFile(const std::string& rFileName);

  /**
   * Explicit destructor.
   */
  virtual ~xDevice(void);


  /**
   * Set Iterator to first device
   *
   * @return
   *   Iterator to first device
   */
  Iterator Begin(void) const { return mDevices.begin() ; };

  /**
   * Set Iterator to last device
   *
   * @return
   *   Iterator to last device
   */
  Iterator End(void) const { return mDevices.end() ; };

  /**
   *
   * Get number of devices
   */
  Idx Size(void) const { return (Idx) mDevices.size(); };


  /**
   *  Insert a new device.
   *  An xDevice is configured by inserting vDevices. An xDevice cannot be
   *  configured by individual output/sensro events.
   *
   *  Note: by inserting a device into an xdevice its ownership
   *  will be assumed by the xdevice and therewith the right to destoy
   *  it.
   *
   *  @param device
   *    Pointer to vDevice
   */
  void Insert(vDevice* device);
  
  /**
   * Insert a new device by Filename
   *
   * An xDevice is configured by inserting vDevices. An xDevice cannot be
   * configured by individual output/sensro events.
   *
   * Note: by inserting a device into an xdevice its ownership
   * will be assumed by the xdevice and therewith the right to destoy
   * 
   * For information on how to write such a file see the "iodevice" - tutorial
   *
   * @param rFileName
   *   Configuration-file to build up device
   */
 
  void Insert(const std::string& rFileName);

  

  /** 
   * Dummy. An xDevice does not provide event based configuration. Use Insert instead. This function
   * will throw an execption
   */
  void Configure(Idx event, const AttributeDeviceEvent& attr);

  /** 
   * An xDevice does not provide event based configuration. Use Insert instead. 
   * This function will throw an execption
   */
  void Configure(const EventSet& rEvents);

   /**
    *
    *  Build up internal data structures. I.e. (event-idx,int) - map
    */
  void Compile(void) ;


  /**
   * Clear all configuarations and destroy existing devices
   *
   */
  void Clear(void);


  /** reset all dynamic state, i.e. call reset on each device */
  void Reset(void);

  /** Test for reset request */
  bool ResetRequest(void);

  /**
   * Activate the devices. This function enables output execution and input reading.
   *
   * @exception Exception
   *   - Not yet configured (id 551)
   */
  void Start(void);

  /**
   * Deactivate the device. This function disables output execution and input reading.
   *
   */
  void Stop(void);

  /**
   * Get status. This function returns the current status of the device.
   * In derived classes that use background threads for input reading etc,
   * a device may change its status without notice. Dont forget to reimplement
   * this method with an appropriate mutex.
   *
   */
  DeviceState Status(void);

  /**
   * Run output command on relevant device.
   *
   * @exception Exception
   *   - unknown output event (id 65)
   *
   */
  void WriteOutput(Idx output);

  /**
   * Flush any pending IO Operations.
   *
   * Pass on flush output buffers to participating devices.
   *
   */
  virtual void FlushOutputs(void);


  /**
   * Report global fauDES-time
   * Note: per convention we take the time of the first
   * device inserted in xDevice as global time
   *
   * @return
   *   fauDES-time
   */
  Time::Type CurrentTime(void);

  /**
   * Report global fauDES-time
   * Note: per convention we take the time of the first
   * device inserted in xDevice as global time
   *
   * @return
   *   fauDES-time
   */
  long int CurrentTimeMs(void);

  /**
   * Set physical time in ftu.
   *
   * @param now
   *   now in faudes time units (ftu).
   */
  virtual void CurrentTime(Time::Type now);

  /**
   * Set physical time in ms.
   *
   * @param nowms
   *   now in msec
   */
  virtual void CurrentTimeMs(long int nowms);



protected:

  // internal iterator type
  typedef std::vector<vDevice*>::iterator iterator;


  /**
   * Actual method to read device configuration from tokenreader.
   *
   * DoRead basically calls the DoWrite-function of all devices which are part of xDevice
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
  virtual void DoReadConfiguration(TokenReader& rTr,  const std::string& rLabel = "", const Type* pContext=0);

  /**
   * Write the device patrameters to a TokenWriter.
   *
   *
   * @param rTw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of section to write
   * @param pContext
   *   Read context to provide contextual information
   * @exception Exception
   *   - IO errors (id 2)
   */
  virtual void DoWriteConfiguration(TokenWriter& rTw, const std::string& rLabel="", const Type* pContext=0) const;

  /** Return first Device */
  iterator Begin(void) { return mDevices.begin() ; };

  /** Return last Device */
  iterator End(void) { return mDevices.end() ; };

  /** Vector of member-devices */
  std::vector<vDevice*> mDevices;

  /** Vector of member-device-names*/
  std::vector<std::string> mDeviceNames;

  /** Compiled data: Input map to map input idx to device no */
  std::map<Idx,int> mInputToDevice;

  /** Compiled data: Output Map to map input idx to device no */
  std::map<Idx,int> mOutputToDevice;

  /** Current device state: remember last stop/down command */
  bool lastCommandWasStart;


};



} 


#endif

