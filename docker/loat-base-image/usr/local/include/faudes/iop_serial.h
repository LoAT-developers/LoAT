/** @file iop_serial.h Process image via serial line */

/*
   FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2011, Thomas Moor.

*/



#ifndef FAUDES_IOP_SERIAL_H
#define FAUDES_IOP_SERIAL_H


// Include core-libary and iodevice
#include "corefaudes.h"
#include "iop_vdevice.h"
#include "iop_sdevice.h"


// If configured to have sspi device 
#ifdef FAUDES_IODEVICE_SERIAL

// Include serial specifics (posix systems)
#include <fcntl.h>  
#include <errno.h>  
#include <termios.h> 



namespace faudes {



/**
 * Processimage synchronisation via serial line interface
 *
 * This device is derived from the signal based sDevice to
 * emulate component interconnection to behave like parallel 
 * digital wiring, however, physically using the 
 * serial interface with a simple commonication protocol.
 *
 * A typical application scenario is to simulate a physical
 * plant on one PC and to implement decentralized controllers 
 * on further PCs. The distributed controllers 
 * may use the rtxx protocol or the simplenet protocol to communicate 
 * via ethernet. The interface with the physical plant 
 * is modelled as a so called process image that indicates 
 * line levels. The spiDevice synchronizes the process images among the 
 * components. In particular, plant simulation incl. the interaction
 * with the controllers will not interfere with the communication among
 * the controllers. This is a requirement for the evaluation of
 * real time communication protocols such as rtxx.
 *
 * The spiDevice distinguishes between one master component 
 * and an arbitrary number of slave components. The master must be
 * connected to each slave via a dedicated serial port. Every input 
 * signal from the master must match an output signal of no more than one slave.
 * Any output signal of the master may be considered as an input of
 * any slave.
 *
 * To configure a spiDevice, you must
 * - specify the role using either the tag 
 *   <tt>&lt;Role value="master"/&gt;</tt> or <tt>&lt;Role value="slave"/&gt;</tt>
 * - specify the serial interface, using tags of the form 
 *   &lt;DeviceFile value="/dev/ttyS0"/&gt, &lt;DeviceFile value="/dev/ttyS1"/&gt etc
 * - setup events to correspond to edges of line levels, see alo faudes::sDevice
 *
 *
 *
 * Note: this device compiles under Linux only. 
 * It must be explicitely enabled Makefile.plugin.
 * 
 * @ingroup  IODevicePlugin
 */

class FAUDES_API spiDevice : public sDevice {

FAUDES_TYPE_DECLARATION(SpiDevice,spiDevice,sDevice)

 public:

  /**
   * Default constructor
   */
  spiDevice(void);

  /**
   * Copy constructor (not implemented!)
   */
  spiDevice(const spiDevice&) : sDevice() {};

  /**
   * Explicit destructor.
   */
  virtual ~spiDevice(void);


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
   * Activate the device. 
   * This function opens/initializes serial lines and 
   * starts the -background thread for edage detection.
   *
   * @exception Exception
   *   - not yet configured (id not configured)
   *   - failed to open serial lines (id not configured)
   */
  virtual void Start(void);


  /**
   * Deactivate the device. This function shuts down the seriale lines,
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
   * backgroud thread. It implements the actual communication via the serial
   * interfaces. To each slave, the master will send its process image and
   * await for the slave to reply by the image. In it's reply, the slave will
   * set/clr its output lines. To keep things simple, the process image is
   * passed on completely, even those lines that are not relevant for the
   * respective client. 
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
  bool mMaster;

  /** Interface(s) */
  std::vector<std::string> mDeviceFiles;
  std::vector<int>         mPorts;

  /** process image from serial line */
  char* mpImage;
  char* pInputImage;
  char* pOutputImage;
  char* mpOutputMask;



}; //class spiDevice

} //namespace 


#endif // configured

#endif // include
