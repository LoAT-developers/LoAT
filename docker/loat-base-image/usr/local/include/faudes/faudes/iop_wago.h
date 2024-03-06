/** @file iop_wago.h Hardware access via comedi */

/*
   FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2009, Thomas Wittmann, Thomas Moor.
   Copyright (C) 2010, Thomas Moor.

*/



#ifndef FAUDES_IOW_WAGO_H
#define FAUDES_IOW_WAGO_H

// include core-libary and iodevice
#include "corefaudes.h"
#include "iop_include.h"

// only compile for use with wago-ipc
#ifdef FAUDES_IODEVICE_WAGO

namespace faudes {



/**
 * Signal-based I/O for WAGO IPC with kBus interface.
 *
 * The wDevice provides access to the kBus (Klemmenbus) used by WAGO to read and write
 * the process-image of the respective IPC configuration. 
 * 
 * Note: the current implementation of wDevice uses the bit addressing in the
 * IEC process image according to WAGO specifications. For the LRT lab experient,
 * digital inputs and outputs range from bitaddress 0 to 15, respectively. You may use
 * the <tt>iomonitor</tt> to identify the address scheme of your kbus configuration.
 *
 * Note: this device compiles under Linux only. Compilation requires WAGO supplied
 * libraries that can be obtained from WAGO; see also the tutorial README.
 * This device must be explicitely anabled 
 * Makefile.plugin.
 * 
 * @ingroup  IODevicePlugin
 */

class FAUDES_API wDevice : public sDevice {

FAUDES_TYPE_DECLARATION(WagoDevice,wDevice,sDevice)

 public:

  /**
   * Default constructor
   */
  wDevice(void);

  /**
   * Copy constructor (TODO!)
   */
  wDevice(const wDevice&) : sDevice() {};

  /**
   * Explicit destructor.
   */
  virtual ~wDevice(void);


  /**
   * Activate the device. This function opens/initializes the kbus support libraries and 
   * sets up the internal kbus-thread. Furthermore it invalidates the io-images. 
   * During the actual read- and write-process this will be reversed if admissable. 
   *
   * In oder to enable signal-edge detection the faudes-background thread will be started
   *
   * @exception Exception
   *   - not yet configured (id not configured)
   *   - failed to open kbus (id not configured)
   */
  virtual void Start(void);

  /**
   * Deactivate the device. This function shuts the kbus and related mechanisms down 
   * and disables output execution and input reading.
   * It stops the background thread and resets all output signals to 0.
   */
  virtual void Stop(void);

protected:
  
  /**
   * wago API access
   *
   **/

  // Initialze kbus
  int kbusInit(void);
  // Shutdown kbus
  void kbusShutdown(void);
  // Get pointer to the kbus-info structure
  struct kbus_info* kbusGetInfo(void);

  
 

  /**
   * IO Hook, inputs
   *
   * The Wago device uses the pre hook to lock the process image.
   *
   * @return 
   *  True on success, false on KBUS error
   *
   */
  virtual bool DoReadSignalsPre(void);

  /**
   * IO Hook, inputs
   *
   * The Wago device uses the post hook to release the process image.
   *
   *
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
   * The Wago device uses the pre hook to lock the process image.
   *
   * @return 
   *  True on success, false on KBUS error
   *
   */
  virtual bool DoWriteSignalsPre(void);

  /**
   * IO Hook, outputs
   *
   * The Wago device uses the post hook to release the process image.
   *
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
   *  True for logic level high;
   *
   */
  virtual void DoWriteSignal(int bitaddr, bool value);

  /** Read non-event-related configuration data from tokenreader
   *
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

  /**  Write non-event-related configuration data to tokenreader
     *
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

  // process image pointers
  char* pInputImage;
  char* pOutputImage;

  // kbus api error flag
  bool mKbusOk;

}; //class wDevice

} //namespace 


#endif // configured

#endif // include
