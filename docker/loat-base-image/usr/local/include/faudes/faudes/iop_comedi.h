/** @file iop_comedi.h Hardware access via comedi */

/*
  FAU Discrete Event Systems Library (libfaudes)

  Copyright (C) 2008, Thomas Moor, Sebastian Perk
  Exclusive copyright is granted to Klaus Schmidt

*/



#ifndef FAUDES_COMEDI_H
#define FAUDES_COMEDI_H

#include "corefaudes.h"
#include "iop_sdevice.h"


// comedi support
#ifdef FAUDES_IODEVICE_COMEDI

#include <comedilib.h>

namespace faudes {


/**
 * A cDevice implements signal based io via the comedi framework.
 *
 * The comedi framework provides an abstract interface to all sorts of
 * IO devices in a control and data sampling context. It includes digital
 * IO which faudes uses for physical signals. To use the cDevice class,
 * you need to install the comedi library and load the comedi kernel modul.
 * See www.comedi.org for further details.
 *
 * Note: the current implementation of cDevice is tailored to the lrt
 * lab experiment. it expects the following configuration:
 *  - advantech 1754 device on /dev/comedi0 (64 input signals)
 *  - advantech 1752 device on /dev/comedi1 (64 output signals)
 * You may adapt/use the provided  "comedi_configure" script to set up the
 * comedi framework. Future versions of cDevice will provide a more general support
 * of comedi devices.
 *
 * @ingroup IODevicePlugin
 */

class FAUDES_API cDevice : public sDevice {

FAUDES_TYPE_DECLARATION(ComediDevice,cDevice,sDevice)

 public:
  /**
   * Default constructor
   */
  cDevice(void);

  /**
   * Copy constructor (TODO!)
   */
  cDevice(const cDevice&) : sDevice() {};

  /**
   * Explicit destructor.
   */
  virtual ~cDevice(void);


  /**
   * Activate the device. This function opens relevant comedi devices and enables
   * output execution and input reading.
   * It starts the background thread for edge detection and input event buffer.
   *
   * @exception Exception
   *   - not yet configured (id 551)
   *   - failed to open comedi devices (id 552)
   */
  virtual void Start(void);

  /**
   * Deactivate the device. This function closes the comedi devices
   * and disables output execution and input reading.
   * It stops the background thread and resets all output signals to 0.
   */
  virtual void Stop(void);

 protected:

  /** Reads non-event-configuration data from tokenreader
   *
   * This function is part of the non-event-configuration data input-system. Device data
   * will be read w.r.t the class-hierarchy. Therefore first thing to do is to call the base
   * class. See sDevice::DoReadPreface for further information.
   *
   * After base-class function returned the device-system-file will be read. This file
   * is needed to establish the communication-interface to IO-card provided by the comedi-
   * framework. See www.comedi.org for more information
   *
   * Note: in order to keep the inputfile-layout as easy as possible no label will be used to separate
   * 	   this data-section. Never the less a default-label ("ComediDevice") is specified.
   *
   * @param rTr
   *   TokenReader to read from
   * @param rLabel
   *   Section to read
   * @param pContext
   *   Read context to provide contextual information
   *
   * */
  void DoReadPreface(TokenReader& rTr,const std::string& rLabel="", const Type* pContext=0);

  /**  Writes non-event-configuration data from tokenreader
   *
   * This function is part of the non-event-configuration data output-system. Device data
   * will be written w.r.t the class-hierarchy. Therefore first thing to do is to the base
   * class. See sDevice::DoWritePreface for further information.
   *
   * After base-class function returned the device-system-file will be written to tokenwriter.
   *
   * Note: in order to keep the outputfile-layout as easy as possible no label will be used to separate
   * 	     this data-section. Never the less a default-label ("ComediDevice") is specified.
   *
   * @param rTw
   *   TokenWriter to write
   * @param rLabel
   *   Section to write
   * @param pContext
   *   Context to provide contextual information
   *
   * */
  void DoWritePreface(TokenWriter& rTw, const std::string& rLabel,  const Type* pContext) const ;


  /**
   * IO Hook, outputs
   *
   * Note: the current implementation uses bit write.
   *
   * @return 
   *  True on success, false on KBUS error
   *
   */
  virtual bool DoWriteSignalsPre(void);

  /**
   * IO Hook, outputs
   *
   * Note: the current implementation uses bit write.
   *
   */
  virtual void DoWriteSignalsPost(void);

  /**
   * Set output signal.
   *
   * Hardware output via comedi.
   *
   * @param bitaddr
   *   Abstract bit address
   * @param value
   *  True for logic level high;
   *
   */
  virtual void DoWriteSignal(int bitaddr, bool value);

  /**
   * IO Hook, inputs
   *
   * The comedi device uses a bit image as buffer
   *
   * @return 
   *  True on success, false on KBUS error
   *
   */
  virtual bool DoReadSignalsPre(void);

  /**
   * IO Hook, inputs
   *
   * The comedi device uses a bit image as buffer
   *
   */
  virtual void DoReadSignalsPost(void);

  /**
   * Get input signal.
   *
   * Hardware input via comedi.
   *
   * @param bitaddr
   *   Abstract bit address
   * @return
   *  True for logic level high;
   */
  virtual bool DoReadSignal(int bitaddr);


  /** System file needed for device-initialization */
  std::string mSystemFile;

  /** ComediDevice-handle */
  comedi_t* mDev;

  /** Bit image (must be 32bit datatype) */
  typedef unsigned int ComediInt32;
  int mComediSubdevs;
  ComediInt32 mComediMask[32];
  ComediInt32* mpInputImage;
  ComediInt32* mpOutputImage;

};

} // namespace

#endif // configure

#endif // include
