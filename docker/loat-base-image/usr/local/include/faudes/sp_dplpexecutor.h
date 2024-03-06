/** @file sp_dplpexecutor.h Executor with IO device  */

/* 
   FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2008  Thomas Moor

*/


#ifndef FAUDES_SP_DPLPEXECUTOR_H
#define FAUDES_SP_DPLPEXECUTOR_H

#include "corefaudes.h"
#include "tp_include.h"
#include "sp_plpexecutor.h" 
#include "sp_simeventset.h"
#include <ctime>


// use iodevice or dummy if not available
#ifdef FAUDES_PLUGIN_IODEVICE
#include "iop_include.h"
#else
namespace faudes {
/** Dummy typedef in the absence of the IO Device plugin */
typedef void vDevice; 
}
#endif

namespace faudes {
	
/**
 * Executer with IO device to handle external/physical events
 *
 * \section SecSimulatorDPLPEX1 External/Physical Events and Time
 *
 * This executor class is derived from the ProposingExecutor and uses a vDevice
 * from the IO Device Plugin to handle input and output events and physical time. 
 * Technically, the class provides the routine SyncStep() that has to be called periodically to
 * synchronize executor clock time with physical time and to perform input readings and
 * output writings. There is also a convenience routine SyncRun() which runs a loop
 * with SyncStep().
 *
 * The SyncStep() procedure implements the below stages. It returns true, if indeed
 * a transition was executed. It returns false on synchronistion errors or when the specified
 * duration expired.
 *    
 *  -  get a proposal from ProposingEcexutor
 *  -  if physical time is ahead of the genartors current clock time, sync time by
 *      ExecuteTime; in the case that this is not consistent with the proposal, 
 *      an error is reported;
 *  -  if the generators current clock time is ahead of physical time, an error is reported
 *  -  if a input event has been reported that can be executed at generators current time, execute it
 *  -  if the proposal schedules an event for the generators current time, execute it
 *  -  if a input event has been reported, execute it now; if this event is not accepted by the generator, report an error
 *  -  if the proposals time is not yet executed, wait for that amount of time to pass
 *       or a input event to be delivered.
 *
 *
 *
 * Naturally, the DeviceExecutor requires the IO Device plugin in order to be functional.
 * In the absence of the plugin, the DeviceExecutor will behave like a ProposingExecutor.
 *
 * \section SecSimulatorDPLPEX2 File IO
 *
 * The DeviceExecutor inherits file IO from the ProposingExecutor. The device itself 
 * is initialized by vDevice methods (eg configured from File) and then passed to the 
 * DeviceExecutor by the method Devicep(). Thus, the DeviceExecutor does not need to
 * implement additional token io facilities.
 *
 * @ingroup SimulatorPlugin 
 */

class FAUDES_API DeviceExecutor : public ProposingExecutor {  

FAUDES_TYPE_DECLARATION(DeviceExecutor,DeviceExecutor,LoggingExecutor)

 public:
		
  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Constructors & Destructor */
  /** @{ doxygen group */

  /**
   * Creates an emtpy DeviceExecutor
   */
  DeviceExecutor();

  /**
   * Copy constructor
   */
  DeviceExecutor(const DeviceExecutor&);

  /**
   * Explicit destructor
   */
  ~DeviceExecutor();


 /**
   * Dummy factory method.
   *
   * Note: the executor classes currently do not implement
   * faudes Type RTI related function. This factory method
   * is only to prevent registry error messages.
   */
  DeviceExecutor* New(void) { return new DeviceExecutor();};


  /** @} doxygen group */

  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Re-implemenented from ParallelExecutor */
  /** @{ doxygen group */

  /**
   * Reset the DeviceExecutor.
   *
   * Reset the executor to its initial state and reset the device, ie clear queued
   * input event set outputs to a passive state
   *
   * @param seed
   *     Seed for PropossingExecutor random generator, 0<>system time
   */
  virtual void Reset(long int seed=0);

  /**
   * Clear all data (generators, simulation attributes etc)
   *
   * This includes the "HardwareReset" event.
   *
   */
  virtual void Clear(void);


  /**
   * Execute event.
   *
   * Programmatically override any internal schedules and execute the specified event.
   * This routine will neither synchronize generator time nor events.
   *
   * @param event
   *   Event by index
   * @return 
   *   True on success
   */
  bool ExecuteEvent(Idx event);
		

  /** @} doxygen group */

  /** @name Application Interface */
  /** @{ doxygen group */

  /**
   * Set tolerance for time synchonisation.
   *
   * @param maxgap
   *   Max acceptable amount of faudes-time units by which the generators 
   *   global clock may be behind physical time
   *
   */
  void ToleranceTime(Time::Type maxgap) {mMaxSyncGap=maxgap; mSyncMode |= SyncStrictTime;};

  /**
   * Modes of synchronisation
   */
  typedef enum {
    SyncStrictTime   =0x01,
    SyncStrictEvents =0x02
  } SyncMode;     

  /**
   * Set synchronisation flags.
   *
   * Semantics are defined via the enum typedef SyncMode.
   *
   * @param flag
   *   Flag word to set mode
   *
   */
  void ToleranceMode(int flag) {mSyncMode=flag;};

  /**
   * Execute generator clock time to sync with device time.
   *
   * If possible, execute the amount of clock time required for an
   * exact match. Otherwise, accept the specified tolerance. As a
   * last resort, issue a sync error. 
   *
   * @return
   *   True, on success ie synchron within tolerance.
   */
  bool SyncTime(void);

  /**
   * Execute scheduled or input events now
   *
   * If an event is scheduled for now, execute it.
   * Otherwise, execute a input event if such is ready.
   * Otherwise execute do nothing.
   *
   * @return
   *   Idx of event executed, 0 for no execution or error
   */
  Idx SyncEvents();


  /**
   * Wait for input events
   *
   * Wait the specified amount of time, for the proposed time to elaps,
   * or a input event to occur - whatever comes first.
   * This function will *not* synchronise with generator time. You may 
   * call SyncTime afterwards.
   *
   * @param duration
   *   Max duration to wait for
   * @return
   *   True, if input events are available
   */
  bool SyncWait(Time::Type duration=Time::Max());

  /**
   * Wait for input events
   *
   * Wait the specified amount of time, for the proposed time to elaps,
   * or a input event to occur - whatever comes first.
   * This function will *not* synchronise with generator time. You may 
   * call SyncTime afterwards.
   * 
   * Note that the executor does not know about msecs, and thus the core interface
   * referc to faudes-time units only. This function is an exception of this rule
   * and is for convenience only.
   *
   * @param durationms
   *   Max duration in msecs to wait for
   * @return
   *   True, if input events are available
   */
  bool SyncWaitMs(int durationms);

  /**
   * Execute one transition with synchronous physical signals.
   *
   * Calls SyncTime, SyncEvents and SyncWait to execute one transition.
   * It will, however, not pass more than the specified duration. 
   *
   * @param duration
   *   Max duration of execution wrt generator time, Time::Max for unlimited
   * @return
   *   Idx of executed event or 0 for time out or error
   */
  Idx SyncStep(Time::Type duration=Time::Max());

  /**
   * Run execution with synchronous physical signals.
   *
   * Loops SyncStep until the specified amount on time expired.
   *
   * @param duration
   *   Duration of execution wrt generator time, Time::Max for infinite
   * @return
   *  True, for no error
   */
  bool SyncRun(Time::Type duration=Time::Max());

  /**
   * Test Syncronisation
   *
   * @return True, if device time and events are in sync with
   *   generator time and events.
   *
   */
  bool IsSynchronous(void) const { return ! mSyncError; };

  /**
   * Set device.
   *
   * The device must be configured. You must start
   * the device befor the first call to SyncRun. Ownership of 
   * the device stays with the caller.
   *
   * @param dev
   *   IO Device to use
   *
   */
  void Devicep(vDevice* dev);

  /**
   * Get device.
   *
   * Retturn a refernce to the device for inspection. Note: you must not
   * interfear with the device during synchronuous execution.
   *
   * @return dev
   *   IO Device to use
   *
   */
  vDevice* Devicep() { return pDevice; };

  /**
   * Convenience: Reset the device.
   *
   */
  void DeviceReset(void);

  /**
   * Convenience: Start the device.
   *
   */
  void DeviceStart(void);

  /**
   * Convenience: Stop the device.
   *
   */
  void DeviceStop(void);

  /**
   * Query the device whther it has received an external reset request.
   * This method will reset the request.
   *
   * @return 
   *  True, if there is such a reset request
   */
  virtual bool DeviceResetRequest(void);

  /** @} doxygen group */

 protected:


  /** Sync error flag */
  bool mSyncError;

  /** Max gap between physical and generator clock time  */
  Time::Type mMaxSyncGap;
 
  /** Mode flags for synchronisation */
  int mSyncMode;
 
  /** Device reference */
  vDevice* pDevice;

  /**
   * Assignment method
   *
   * @param rSrc
   *    Source to assign from
   */
  void DoAssign(const DeviceExecutor& rSrc);



}; // end class DeviceExecutor



} // namespace faudes


#endif // .h

