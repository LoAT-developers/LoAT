/** @file ios_attributes.h I/O-system attributes */

/* 
   IO Systems Plug-In 
   for FAU Discrete Event Systems Library (libFAUDES)

   Copyright (C) 2010, Thomas Wittmann, Thomas Moor

*/

#ifndef FAUDES_IOS_ATTRIBUTES_H
#define FAUDES_IOS_ATTRIBUTES_H

// debugging: 
#ifdef FAUDES_DEBUG_IOSYS
#define FD_DIO(message) FAUDES_WRITE_CONSOLE("FAUDES_IOSYS: " << message)
#else
#define FD_DIO(message)
#endif

#include "corefaudes.h"

namespace faudes {

    
/** 
 * Attributes for events in DES with in- and outputs
 * 
 * The class AttributeIosEvent holds a bitarray to handle an event's io-properties 
 *
 * In order to envolve the event's io-properties during file-io 
 * the DoRead/DoWrite methods were overwritten. Use Attributes
 * +I+ and +O+ in .gen file to make sure an event will be inserted in
 * Iput or OTput event set.
 *
 * @ingroup iosysplugin  
 */

class FAUDES_API AttributeIosEvent : public AttributeFlags {

FAUDES_TYPE_DECLARATION(Void,AttributeIosEvent,AttributeFlags )

  public:
  
   
  /** 
   *  Default constructor 
   */
  AttributeIosEvent(void) : AttributeFlags() {
      mFlags=mDefIosFlags;
  }

  /** 
   *  Copy constructor 
   */ 
  AttributeIosEvent(const AttributeIosEvent& rSrc) : AttributeFlags()  {
      mFlags=rSrc.mFlags;
  };

  /** 
   *  Destructor 
   */
  virtual ~AttributeIosEvent(void) {
  };

  /**
   * Set output flag
   *
   * Note: this will clear the input flag.
   *
   */  
  void SetOutput(void) {
    mFlags |= mOutputFlag;
  }

  /**
   * Clear output flag
   *
   * Note: this will clear the input flag.
   *
   */  
  void ClrOutput(void) {
    mFlags &= ~mOutputFlag; 
  };

  /**
   * Set input flag
   *
   * Note: this will clear the output flag.
   *
   */  
  void SetInput(void) {
    mFlags |= mInputFlag;
  }


  /**
   * Clear input flag
   *
   * Note: this will clear the input flag.
   *
   */  
  void ClrInput(void) {
    mFlags &= ~mInputFlag; 
  };

  /**
   * Test output flag
   *
   * @return
   *   true:  state is an output state
   *   false: state is not an output state
   */
  bool Output(void) const {
    return (mFlags & mOutputFlag) != 0 ; 
  }

     
  /**
   * Test input flag
   *
   * @return
   *   true:  state is an input state
   *   false: state is not an input state
   */
  bool Input(void) const {
    return (mFlags & mInputFlag) != 0; 
  }

 
     
  /** 
   * Check an event's io-properties for default value.
   *
   * If an event has default properties, it's wether an input
   * nor to output event.
   * 
   * @return
   *   true:  event has default properties
   *   false: event has non-default properties
   */
  bool  IsDefault(void) const {
        return mFlags==mDefIosFlags;
  }

 protected:

  // flag masks for the event properties
  const static fType mInputFlag =0x010;  
  const static fType mOutputFlag =0x020; 
   
  // overall default value
  const static fType mDefIosFlags        =0x000 ; 

  // all flags
  const static fType mAllIosFlags        =0x030; 


  /**
   * Assignment method. 
   *
   * @param rSrcAttr
   *    Source to assign from
   */
  void DoAssign(const AttributeIosEvent& rSrcAttr);


  /**
   * Reads attribute from TokenReader, see AttributeVoid for public wrappers.
   * Reads a single token if it can be interpreted as IosEventFlag, that is, if
   * it is a respective option string or hex number. Label and Context
   * argument are ignored. No token mismatch exceptions are thrown on error.
   *
   * @param rTr
   *   TokenReader to read from
   * @param rLabel
   *   Section to read
   * @param pContext
   *   Read context to provide contextual information
   * @exception Exception
   *   - IO error (id 1)
   */
  virtual void DoRead(TokenReader& rTr, 
		      const std::string& rLabel="", 
		      const Type* pContext=0);
 
  /**
   * Writes attribute to TokenWriter, see AttributeVoid for public wrappers.
   * Label and Context argument are ignored.  
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
  virtual void DoWrite(TokenWriter& rTw,
		       const std::string& rLabel="", 
		       const Type* pContext=0) const;

  /**
   * Writes attribute to TokenWriter, see AttributeVoid for public wrappers.
   * Label and Context argument are ignored.  
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
  virtual void DoXWrite(TokenWriter& rTw,
		       const std::string& rLabel="", 
		       const Type* pContext=0) const;

}; // class AttributeIosEvent


// Convenience typedef
typedef TaNameSet<AttributeIosEvent> IosEventSet;



/** 
 * Attributes for states in DESs with in- and outputs 
 *
 * The class AttributeIosState holds a bitarray to handle a state's io-properties.
 * A state is said to be an in- or output state if the set of active events
 * contains only in- or output events.
 *
 * In order to envolve the state's io-properties during file-io
 * the DoRead/DoWrite methods were overwritten. Use +I+ for input, +O+ for 
 * output states. 
 *
 * @ingroup iosysplugin 
 */

class FAUDES_API AttributeIosState : public AttributeFlags 
{

  FAUDES_TYPE_DECLARATION(Void,AttributeIosState,AttributeFlags)

  public:

  /**
   * Default constructor 
   */
  AttributeIosState(void) : AttributeFlags() {
    mFlags=mDefIosFlags;
  };

  /** 
   * Copy constructor 
   */ 
  AttributeIosState(const AttributeIosState& rSrc) : AttributeFlags() { 
    mFlags=rSrc.mFlags;
  };

  /** 
   * Destructor 
   */
  virtual ~AttributeIosState(void) {};

  /**
   * Set output flag
   *
   * Note: this will clear the input flag.
   *
   */  
  void SetOutput(void) {
    mFlags |= mOutputFlag;
  };

  /**
   * Clear output flag
   *
   * Note: this will clear the input flag.
   *
   */  
  void ClrOutput(void) {
    mFlags &= ~mOutputFlag; 
  };

  /**
   * Set input flag
   *
   * Note: this will clear the output flag.
   *
   */  
  void SetInput(void) {
    mFlags |= mInputFlag;
  };


  /**
   * Clear input flag
   *
   * Note: this will clear the input flag.
   *
   */  
  void ClrInput(void) {
    mFlags &= ~mInputFlag; 
  };


  /**
   * Set error flag
   *
   */  
  void SetError(void) {
    mFlags |= mErrorFlag;
  };


  /**
   * Clear error flag
   *
   */  
  void ClrError(void) {
    mFlags &= ~mErrorFlag; 
  };

  /**
   * Test output flag
   *
   * @return
   *   true:  state is an output state
   *   false: state is not an output state
   */
  bool Output(void) const {
    return (mFlags & mOutputFlag) != 0 ; 
  };

     
  /**
   * Test input flag
   *
   * @return
   *   true:  state is an input state
   *   false: state is not an input state
   */
  bool Input(void) const {
    return (mFlags & mInputFlag) != 0; 
  };

 
     
  /**
   * Check error flag
   *
   * @return
   *   true:  state is an error state
   *   false: state is not an error state
   */
  bool Error(void) const {
    return (mFlags & mErrorFlag) != 0; 
  };

  /** 
   * Check a state's io-properties for default value.
   *
   * If a state has default properties, it's neither an input
   * nor to output state.
   * 
   * @return
   *   true:  event has default properties
   *   false: event has non-default properties
   */
  bool  IsDefault(void) const {
    return mFlags==mDefIosFlags;
  };

  // Flag masks for the 10 properties 
  const static fType mInputFlag   = 0x10;  
  const static fType mOutputFlag  = 0x20;  
  const static fType mErrorFlag   = 0x40;  

  /**
   * Write attribute to string
   *
   * @return
   *  string representation of attributes
   *
   */
  virtual std::string ToString(void) const;


 protected:

  // Overall default value
  const static fType mDefIosFlags = 0x00; 
  // All flags
  const static fType mAllIosFlags = 0x70;  


  /**
   * Assignment method. 
   *
   * @param rSrcAttr
   *    Source to assign from
   */
  void DoAssign(const AttributeIosState& rSrcAttr);

  /**
   * Reads attribute from TokenReader, see AttributeVoid for public wrappers.
   * Reads a single token if it can be interpreted as IosStateFlag, that is, if
   * it is a respective option string or hex number. Label and Context
   * argument are ignored. No token mismatch exceptions are thrown on error.
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
   * Writes attribute to TokenWriter, see AttributeVoid for public wrappers.
   * Label and Context argument are ignored.  
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

  /**
   * Writes attribute to TokenWriter, see AttributeVoid for public wrappers.
   * Label and Context argument are ignored.  
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
  virtual void DoXWrite(TokenWriter& rTw,
		       const std::string& rLabel="", 
		       const Type* pContext=0) const;

};


// convenience typedef
typedef TaIndexSet<AttributeIosState> IosStateSet;





}// end namespace faudes
#endif
