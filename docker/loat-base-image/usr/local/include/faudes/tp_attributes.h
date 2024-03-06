/** @file tp_attributes.h  Attributes for timed automata */


/* Timeplugin for FAU Discrete Event Systems Library (libfaudes)

Copyright (C) 2006       Berno Schlein
Copyright (C) 2007,2014  Thomas Moor
Exclusive copyright is granted to Klaus Schmidt

*/


#ifndef FAUDES_TP_ATTRIBUTES_H
#define FAUDES_TP_ATTRIBUTES_H

#include "corefaudes.h"
#include "tp_timeconstraint.h"

namespace faudes {


/** 
 * Transition Attribute with guard and resets. 
 *
 * @ingroup TimedPlugin  
 */

class FAUDES_API AttributeTimedTrans : public AttributeFlags {

FAUDES_TYPE_DECLARATION(Void,AttributeTimedTrans,AttributeFlags)

 public:

  /** Constructor */
  AttributeTimedTrans(void) : AttributeFlags() { mGuard.Name("Guard"); mResets.Name("Resets"); };

  /** 
   * Test for default value (ie empty constraint and default flags)
   *
   * @return
   *  True for default value
   */
  virtual bool  IsDefault(void) const {return mGuard.Empty() && mResets.Empty() && AttributeFlags::IsDefault(); };

  /** Guard  */
  TimeConstraint mGuard;

  /** Resets */
  ClockSet mResets;

 protected:

  /**
   * Assignment method. 
   *
   * @param rSrcAttr
   *    Source to assign from
   */
  void DoAssign(const AttributeTimedTrans& rSrcAttr);

  /**
   * Test eaulity. 
   *
   * @param rOther
   *    Other attribute to compare with.
   */
  bool DoEqual(const AttributeTimedTrans& rOther) const;

  /**
   * Reads the attribute from TokenReader, see AttributeVoid for public wrappers.
   * 
   * If the current token indicates a timing section, the method reads the guard and reset 
   * timing data from that section. Else it does nothing. Exceptions may only be thrown
   * on invalid data within the timing section. The context argument is ignored, the
   * label argument can be used to override the default section name Timing.
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
   * Writes a Timing section to include data on the guard and resets. The label argument
   * can be used to set a section label different the the default Timing. 
   * Th context argument is ignored.  
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
  virtual void DoWrite(TokenWriter& rTw, const std::string& rLabel="", const Type* pContext=0) const;



}; // class AttributeTimedTrans


/**
 * 
 * State attribute with invariant.
 *
 * @ingroup TimedPlugin  
 *
 */

class FAUDES_API AttributeTimedState : public AttributeFlags {

FAUDES_TYPE_DECLARATION(Void,AttributeTimedState,AttributeFlags)

 public:

  /** Constructor */
  AttributeTimedState(void) : AttributeFlags() {
    mInvariant.Name("Invariant");
  };

  /** Copy Constructor */
  AttributeTimedState(const AttributeTimedState& rSrcAttr) : AttributeFlags() {
    mInvariant.Name("Invariant");
    DoAssign(rSrcAttr);
  };

  /** 
   * Test for default value (ie empty invariant and default flags)
   *
   * @return
   *  True for default value
   */
  virtual bool IsDefault(void) const {return mInvariant.Empty() && AttributeFlags::IsDefault(); };

  /** Invariant  */
  TimeConstraint mInvariant;
 
 protected:


  /**
   * Assignment method. 
   *
   * @param rSrcAttr
   *    Source to assign from
   */
  void DoAssign(const AttributeTimedState& rSrcAttr);


  /**
   * Test eaulity. 
   *
   * @param rOther
   *    Other attribute to compare with.
   */
  bool DoEqual(const AttributeTimedState& rOther) const;

  /**
   * Reads the attribute from TokenReader, see AttributeVoid for public wrappers.
   * 
   * If the current token indicates a invariant section, the method reads the invariant
   * from that section. Else, it does nothing. Exceptions may only be thrown
   * on invalid data within the timing section. The context argument is ignored, the
   * label argument can be used to override the default section name Invariant.
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
   * Writes the attribute to TokenWriter, see AttributeVoid for public wrappers.
   *
   * Writes am Invariant section to include data on the invariant. The label argument
   * can be used to set a section label different the the default Invariant. 
   * Th context argument is ignored.  
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
  virtual void DoWrite(TokenWriter& rTw, const std::string& rLabel="", const Type* pContext=0) const;


}; // class AttributeTimedState


/**
 *
 * Globat attribute with clockset.
 *
 * @ingroup TimedPlugin  
 *
 */

class FAUDES_API AttributeTimedGlobal : public AttributeVoid {

FAUDES_TYPE_DECLARATION(Void,AttributeTimedGlobal,AttributeVoid)

 public:

  /** Constructor */
  AttributeTimedGlobal(void) {
    mpClockSymbolTable=mClocks.SymbolTablep(); };

  /** 
   * Test for default value (ie empty clockset)
   *
   * @return
   *  True for default value
   */
  virtual bool IsDefault(void) const {return mClocks.Empty(); };

  /** Clocks */
  ClockSet mClocks;

  /** Pointer to clock symboltable */
  SymbolTable* mpClockSymbolTable;

 protected:

  /**
   * Assignment method. 
   *
   * @param rSrcAttr
   *    Source to assign from
   */
  void DoAssign(const AttributeTimedGlobal& rSrcAttr);

  /**
   * Test eaulity. 
   *
   * @param rOther
   *    Other attribute to compare with.
   */
  bool DoEqual(const AttributeTimedGlobal& rOther) const;

  /**
   * Reads the attribute from TokenReader, see AttributeVoid for public wrappers.
   * 
   * If the current token indicates a Clocks section, the method reads the global
   * timing data from that section. Else, it does nothing. Exceptions may only be thrown
   * on invalid data within the timing section. The context argument is ignored, the
   * label argument can be used to override the default section name Clocks.
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
   * Writes a Clocks section to include global timing data. The label argument
   * can be used to set a section label different the the default Clocks. 
   * Th context argument is ignored.  
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
  virtual void DoWrite(TokenWriter& rTw, const std::string& rLabel="", const Type* pContext=0) const;




}; // class AttributeTimedGlobal


} // namespace faudes

#endif
