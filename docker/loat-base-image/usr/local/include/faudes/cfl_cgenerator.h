/** @file cfl_cgenerator.h Classes TcGenerator, System and AttributeCFlags */

/* FAU Discrete Event Systems Library (libfaudes)

Copyright (C) 2006  Bernd Opitz
Copyright (C) 2007  Thomas Moor
Exclusive copyright is granted to Klaus Schmidt

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA */


#ifndef FAUDES_CGENERATOR_H
#define FAUDES_CGENERATOR_H

#include "cfl_definitions.h"
#include "cfl_agenerator.h"
#include "cfl_parallel.h"
#include "cfl_project.h"


namespace faudes {


/**
 * Attribute class to model event controllability properties.
 *
 * This attribute is meant to be an event attribute and can distinguish between
 * controllable, observable, forcible and abstraction events. It is based on faudes::AttributeFlags
 * and uses the lower four bits in the flag word to store the respective boolean values.
 * The AttributeCFlags class adds convenience functions to access these bits and a default-value 
 * that corresponds to observable and neiter controllable nor forcible.
 *
 * Presuming that only controllability flags are uses (different from default), the
 * token representation is by an Option String consisting of the initials <tt>c</tt>,<tt>o</tt>,<tt>f</tt> 
 * and <tt>a</tt>, where initials are capitatised for set flags and default values 
 * are not written; eg <tt>+C+</tt> 
 * for a controllable event that is observable (default),  not forcible (default) and  
 * an abstraction event (default).
 * If other than the four controllability bits are used, std. hex format is used.
 * 
 */


class FAUDES_API AttributeCFlags : public AttributeFlags {

FAUDES_TYPE_DECLARATION(Void,AttributeCFlags,AttributeFlags)

 public:
  /**
   * Default constructor 
   */
  AttributeCFlags(void) : AttributeFlags() { mFlags=mDefCFlags; };

  /** Destructor */
  virtual ~AttributeCFlags(void) {};

  /**
   * Set controllable flag 
   */
  void SetControllable(void) { mFlags |= mControllableFlag; }

  /**
   * Clear controllable flag 
   */

  void ClrControllable(void) { mFlags &= ~mControllableFlag; };
     
  /**
   * Query controllablility 
   */
  bool Controllable(void) const {return ( (mFlags & mControllableFlag) != 0 ); }


  /**
   * Set observable flag 
   */
  void SetObservable(void) { mFlags |= mObservableFlag; }

  /**
   * Clear observable flag 
   */
  void ClrObservable(void) { mFlags &= ~mObservableFlag; };
     
  /**
   * Query observablility 
   */
  bool Observable(void) const {return ( (mFlags & mObservableFlag) != 0 ); }


  /**
   * Set forcible flag 
   */
  void SetForcible(void) { mFlags |= mForcibleFlag; }

  /**
   * Clear forcible flag 
   */

  void ClrForcible(void) { mFlags &= ~mForcibleFlag; };
     
  /**
   * Query forcibility 
   */
  bool Forcible(void) const {return ( (mFlags & mForcibleFlag) != 0 ); }


  /**
   * Set abstraction flag 
   */
  void SetHighlevel(void) { mFlags |= mAbstractionFlag; }

  /**
   * Clear abstraction flag 
   */
  void SetLowlevel(void) { mFlags &= ~mAbstractionFlag; };
     
  /**
   * Query abstaction flag
   */
  bool Highlevel(void) const {return ( (mFlags & mAbstractionFlag) != 0 ); }

  /**
   * Query abstaction flag
   */
  bool Lowlevel(void) const {return ( (mFlags & mAbstractionFlag) == 0 ); }


  /** 
   * Test for default value
   */
  virtual bool  IsDefault(void) const {return mFlags==mDefCFlags;};

  // flag masks for the three properties
  const static fType mControllableFlag =0x01;
  const static fType mObservableFlag   =0x02;
  const static fType mForcibleFlag     =0x04;
  const static fType mAbstractionFlag  =0x08;

 private:
  /** Overall default value */
  const static fType mDefCFlags         =0x0a;

  /** All flags used by CFlags */
  const static fType mAllCFlags         =0x0f;

 protected:

  /**
   * Assignment method. 
   *
   * @param rSrcAttr
   *    Source to assign from
   */
  void DoAssign(const AttributeCFlags& rSrcAttr);

  /**
   * Test equality of configuration data.
   *
   * @param rOther 
   *    Other attribute to compare with.
   * @return 
   *   True on match.
   */
  bool DoEqual(const AttributeCFlags& rOther) const;

  /**
   * Reads attribute from TokenReader, see AttributeVoid for public wrappers.
   * Reads a single token if it can be interpreted as AttributeCFlag, that is, if
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
   * Writes attribute to TokenWriter (XML format), see AttributeVoid for public wrappers.
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
  virtual void DoXWrite(TokenWriter& rTw,const std::string& rLabel="", const Type* pContext=0) const;



}; // class AttributeCFlags



/** 
 * Convenience typedef for event sets with controllability attributes. 
 *
 * @ingroup ContainerClasses
 */
typedef TaNameSet<AttributeCFlags> Alphabet;

/** Convenience typedef */
typedef TBaseVector<Alphabet> AlphaberVector;  

/** Compatibility: pre 2.20b used cEventSet as C++ class name*/
#ifdef FAUDES_COMPATIBILITY
typedef TaNameSet<AttributeCFlags> cEventSet;
typedef TBaseVector<cEventSet>     cEventSetVector;  
#endif


/**
 * Generator with controllability attributes. 
 * 
 * @section CGeneratorOverview Overview
 * 
 * The TcGenerator is a variant of the TaGenerator to add an interface for events with 
 * controllabilty attributes, ie an event may be controllable, observable or forcible. 
 *
 * Technically, the construct is based on the specialized attribute class faudes::AttributeCFlags
 * that provides attributes with semantics for controllability properties. The TcGenerator
 * expects an event attribute template parameter with the minimum interface defined in AttribueCFlags.
 * Thus, you can add further semantics by deriving a class AttributeCFlagsAndMore  from
 * AttribueeCFlags and use this as event attribute parameter for TcGenerator. To model
 * a plain finite state machine plus controllability properties, use TcGenerator with
 * AttributeCFlags for the event attribute parameter and AttributeVoid for the other
 * parameters. For convenience, this has been typedef-ed as System.
 *
 * @ingroup GeneratorClasses
 */

template <class GlobalAttr, class StateAttr, class EventAttr, class TransAttr>
    class FAUDES_API TcGenerator : public TaGenerator<GlobalAttr, StateAttr, EventAttr, TransAttr> {    
  public:
    /**
     * Creates an emtpy System object 
     */
    TcGenerator(void);

    /** 
     * System from a std Generator. Copy constructor 
     *
     * @param rOtherGen
     */
    TcGenerator(const vGenerator& rOtherGen);
        
    /** 
     * System from a System. Copy constructor 
     *
     * @param rOtherGen
     */
    TcGenerator(const TcGenerator& rOtherGen);

    /**
     * construct a System from file
     *
     * @param rFileName
     *   Filename
     *
     * @exception Exception
     *   If opening/reading fails an Exception object is thrown (id 1, 50, 51)
     */
    TcGenerator(const std::string& rFileName);

    /**
     * Construct on heap
     *
     * @return 
     *   new Generator 
     */
     TcGenerator* New(void) const;

    /**
     * Construct copy on heap
     *
     * @return 
     *   new Generator 
     */
     TcGenerator* Copy(void) const;

    /**
     * Type test.
     * Uses C++ dynamic cast to test whether the specified object
     * casts to a System.
     *
     * @param pOther
     *   poinetr to object to test
     *
     * @return 
     *   TcGenerator reference if dynamic cast succeeds, else NULL 
     */
     virtual const Type* Cast(const Type* pOther) const {
       return dynamic_cast< const TcGenerator* > (pOther); };


    /**
     * Construct on stack
     *
     * @return 
     *   new Generator 
     */
     TcGenerator NewCGen(void) const;

    /**
     * Assignment operator (uses Assign)
     *
     * Note: you must reimplement this operator in derived 
     * classes in order to handle internal pointers correctly
     *
     * @param rOtherGen
     *   Other generator
     */
     virtual TcGenerator& operator= (const TcGenerator& rOtherGen);
  
    /**
     * Assignment method
     *
     * Note: you must reimplement this method in derived 
     * classes in order to handle internal pointers correctly
     *
     * @param rSource
     *   Other generator
     */
     virtual TcGenerator& Assign(const Type& rSource);
   
    /**
     * Add an existing controllable event to generator. 
     * An entry in the global eventtable will be made.
     *
     * @param index
     *   Event index
     */
    void InsControllableEvent(Idx index);

    /**
     * Add new named controllable event to generator. 
     * An entry in the global eventtable will be made if event is new.
     *
     * @param rName
     *   Name of the event to add
     *
     * @return 
     *   New global unique index
     */
    Idx InsControllableEvent(const std::string& rName);
    
    /**
     * Add an existing uncontrollable event to generator. 
     * An entry in the global eventtable will be made.
     *
     * @param index
     *   Event index
     */
    void InsUncontrollableEvent(Idx index);

    /**
     * Add new named uncontrollable event to generator. 
     * An entry in the global eventtable will be made if event is new.
     *
     * @param rName
     *   Name of the event to add
     *
     * @return 
     *   New global unique index
     */
    Idx InsUncontrollableEvent(const std::string& rName);
        
    /**
     * Mark event controllable (by index)
     *
     * @param index
     *   Event index
     */
    void SetControllable(Idx index);

    /** 
     * Mark event controllable (by name)
     *
     * @param rName
     *   Event name    
     */
    void SetControllable(const std::string& rName);

    /** 
     * Mark set of events controllable (by index)
     *
     * @param rEvents
     *   EventSet
     */
    void SetControllable(const EventSet& rEvents);
        
    /**
     * Mark event uncontrollable (by index)
     * 
     * @param index
     *   Event index
     */
    void ClrControllable(Idx index);

    /**
     * Mark event uncontrollable (by name)
     * 
     * @param rName
     *   Event name
     */
    void ClrControllable(const std::string& rName);

    /** 
     * Mark set of events uncontrollable (by index)
     *
     * @param rEvents
     *   EventSet
     */
    void ClrControllable(const EventSet& rEvents);
          
    /**
     * Is event controllable (by index)
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     */
    bool Controllable(Idx index) const;

    /**
     * Is event controllable (by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool Controllable(const std::string& rName) const;

    /** 
     * Get EventSet with controllable events
     *
     * @return
     *   EventSet of controllable events
     */
    EventSet ControllableEvents(void) const;

    /**
     * Get EventSet with uncontrollable events
     *
     * @return 
     *   EventSet of uncontrollable events
     */
    EventSet UncontrollableEvents(void) const;

    /**
     * Add an existing observable event to generator. 
     * An entry in the global eventtable will be made.
     *
     * @param index
     *   Event index
     */
    void InsObservableEvent(Idx index);

    /**
     * Add new named observable event to generator. 
     * An entry in the global eventtable will be made if event is new.
     *
     * @param rName
     *   Name of the event to add
     *
     * @return 
     *   New global unique index
     */
    Idx InsObservableEvent(const std::string& rName);
    
    /**
     * Add an existing unobservable event to generator. 
     * An entry in the global eventtable will be made.
     *
     * @param index
     *   Event index
     */
    void InsUnobservableEvent(Idx index);

    /**
     * Add new named unobservable event to generator. 
     * An entry in the global eventtable will be made if event is new.
     *
     * @param rName
     *   Name of the event to add
     *
     * @return 
     *   New global unique index
     */
    Idx InsUnobservableEvent(const std::string& rName);
        
    /**
     * Mark event observable (by index)
     *
     * @param index
     *   Event index
     */
    void SetObservable(Idx index);

    /** 
     * Mark event observable (by name)
     *
     * @param rName
     *   Event name    
     */
    void SetObservable(const std::string& rName);

    /**
     * Mark set of events observable 
     *
     * @param rEvents
     *   EventSet
     */
    void SetObservable(const EventSet& rEvents);
        
    /**
     * Mark event unobservable (by index)
     * 
     * @param index
     *   Event index
     */
    void ClrObservable(Idx index);

    /**
     * Mark event unobservable (by name)
     * 
     * @param rName
     *   Event name
     */
    void ClrObservable(const std::string& rName);

    /**
     * Mark set of events unobservable 
     *
     * @param rEvents
     *   EventSet
     */
    void ClrObservable(const EventSet& rEvents);
          
    /**
     * Is event observable (by index)
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     */
    bool Observable(Idx index) const;

    /**
     * Is event observable (by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool Observable(const std::string& rName) const;

    /** 
     * Get EventSet with observable events
     *
     * @return
     *   EventSet of controllable events
     */
    EventSet ObservableEvents(void) const;

    /**
     * Get EventSet with unobservable events
     *
     * @return 
     *   EventSet of uncontrollable events
     */
    EventSet UnobservableEvents(void) const;

    /**
     * Add an existing forcible event to generator. 
     * An entry in the global eventtable will be made.
     *
     * @param index
     *   Event index
     */
    void InsForcibleEvent(Idx index);

    /**
     * Add new named forcible event to generator. 
     * An entry in the global eventtable will be made if event is new.
     *
     * @param rName
     *   Name of the event to add
     *
     * @return 
     *   New global unique index
     */
    Idx InsForcibleEvent(const std::string& rName);
    
    /**
     * Add an existing unforcible event to generator. 
     * An entry in the global eventtable will be made.
     *
     * @param index
     *   Event index
     */
    void InsUnforcibleEvent(Idx index);

    /**
     * Add new named unforcible event to generator. 
     * An entry in the global eventtable will be made if event is new.
     *
     * @param rName
     *   Name of the event to add
     *
     * @return 
     *   New global unique index
     */
    Idx InsUnforcibleEvent(const std::string& rName);
        
    /**
     * Mark event forcible (by index)
     *
     * @param index
     *   Event index
     */
    void SetForcible(Idx index);

    /** 
     * Mark event forcible (by name)
     *
     * @param rName
     *   Event name    
     */
    void SetForcible(const std::string& rName);

    /**
     * Mark set of events forcible
     *
     * @param rEvents
     *   EventSet
     */
    void SetForcible(const EventSet& rEvents);
        
    /**
     * Mark event unforcible (by index)
     * 
     * @param index
     *   Event index
     */
    void ClrForcible(Idx index);

    /**
     * Mark event unforcible (by name)
     * 
     * @param rName
     *   Event name
     */
    void ClrForcible(const std::string& rName);

    /**
     * Mark set of events unforcible 
     *
     * @param rEvents
     *   EventSet
     */
    void ClrForcible(const EventSet& rEvents);
          
    /**
     * Is event forcible (by index)
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     */
    bool Forcible(Idx index) const;

    /**
     * Is event forcible (by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool Forcible(const std::string& rName) const;

    /** 
     * Get EventSet with forcible events
     *
     * @return
     *   EventSet of controllable events
     */
    EventSet ForcibleEvents(void) const;

    /**
     * Get EventSet with unforcible events
     *
     * @return 
     *   EventSet of uncontrollable events
     */
    EventSet UnforcibleEvents(void) const;

    /**
     * Add an existing abstraction event to generator. 
     * An entry in the global eventtable will be made.
     *
     * @param index
     *   Event index
     */
    void InsHighlevelEvent(Idx index);

    /**
     * Add new named abstraction event to generator. 
     * An entry in the global eventtable will be made if event is new.
     *
     * @param rName
     *   Name of the event to add
     *
     * @return 
     *   New global unique index
     */
    Idx InsHighlevelEvent(const std::string& rName);
    
    /**
     * Add an existing low-level event to generator. 
     * An entry in the global eventtable will be made.
     *
     * @param index
     *   Event index
     */
    void InsLowlevelEvent(Idx index);

    /**
     * Add new named low-level event to generator. 
     * An entry in the global eventtable will be made if event is new.
     *
     * @param rName
     *   Name of the event to add
     *
     * @return 
     *   New global unique index
     */
    Idx InsLowlevelEvent(const std::string& rName);
        
    /**
     * Mark event as highlevel event (by index)
     *
     * @param index
     *   Event index
     */
    void SetHighlevel(Idx index);

    /** 
     * Mark event as highlevel event (by name)
     *
     * @param rName
     *   Event name    
     */
    void SetHighlevel(const std::string& rName);

    /**
     * Mark set of events as high-level events
     *
     * @param rEvents
     *   EventSet
     */
    void SetHighlevel(const EventSet& rEvents);
        
    /**
     * Mark event as low-level event (by index)
     * 
     * @param index
     *   Event index
     */
    void SetLowlevel(Idx index);

    /**
     * Mark event as low-level event (by name)
     * 
     * @param rName
     *   Event name
     */
    void SetLowlevel(const std::string& rName);

    /**
     * Mark set of events as low-level events.
     *
     * @param rEvents
     *   EventSet
     */
    void SetLowlevel(const EventSet& rEvents);
          
    /**
     * Test for high-level event  (by index)
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     */
    bool Highlevel(Idx index) const;

    /**
     * Test for high-level event  (by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool Highlevel(const std::string& rName) const;

    /**
     * Test for low-level event  (by index)
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     */
    bool Lowlevel(Idx index) const;

    /**
     * Test for low-level event  (by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool Lowlevel(const std::string& rName) const;

    /** 
     * Get EventSet of all high-level events
     *
     * @return
     *   EventSet of high-level events
     */
    EventSet HighlevelEvents(void) const;

    /**
     * Get EventSet of all low-level events
     *
     * @return 
     *   EventSet of low-level events
     */
    EventSet LowlevelEvents(void) const;


  private:

  protected:

}; // end class TcGenerator

    
/** 
 * Convenience typedef for std System. 
 *
 * @ingroup GeneratorClasses
 */
typedef TcGenerator<AttributeVoid, AttributeVoid, AttributeCFlags,AttributeVoid> System;

/** 
 * Convenience typedef for vectors of systems
 * \ingroup GeneratorClasses
 */
typedef  TBaseVector<System> SystemVector;  

/** Compatibility: pre 2.20b used cGenerator as C++ class name*/
#ifdef FAUDES_COMPATIBILITY
typedef TcGenerator<AttributeVoid, AttributeVoid, AttributeCFlags,AttributeVoid> cGenerator;
typedef TBaseVector<cGenerator> cGeneratorVector;  
#endif



/*
***************************************************************************
***************************************************************************
***************************************************************************

Implementation cgenerator

***************************************************************************
***************************************************************************
***************************************************************************
*/

/* convenience access to relevant scopes */
#define THIS TcGenerator<GlobalAttr, StateAttr, EventAttr, TransAttr>
#define BASE TaGenerator<GlobalAttr, StateAttr, EventAttr, TransAttr>
#define TEMP template <class GlobalAttr, class StateAttr, class EventAttr, class TransAttr>


// TcGenerator(void)
TEMP THIS::TcGenerator(void) : BASE() {
  FD_DG("TcGenerator(" << this << ")::TcGenerator()");
}

// TcGenerator(rOtherGen)
TEMP THIS::TcGenerator(const TcGenerator& rOtherGen) : BASE(rOtherGen) {
  FD_DG("TcGenerator(" << this << ")::TcGenerator(rOtherGen)");
}

// TcGenerator(rOtherGen)
TEMP THIS::TcGenerator(const vGenerator& rOtherGen) : BASE(rOtherGen) {
  FD_DG("TcGenerator(" << this << ")::TcGenerator(rOtherGen)");
}

// TcGenerator(rFilename)
TEMP THIS::TcGenerator(const std::string& rFileName) : BASE(rFileName) {
  FD_DG("TcGenerator(" << this << ")::TcGenerator(rFilename) : done");
}

// operator=
TEMP THIS& THIS::operator= (const TcGenerator& rOtherGen) {
  FD_DG("TcGenerator(" << this << ")::operator = [v]" << &rOtherGen);
  return Assign(rOtherGen);
}

// copy from other faudes type
TEMP THIS& THIS::Assign(const Type& rSrc) {
  FD_DG("TcGenerator(" << this << ")::Assign([type] " << &rSrc << ")");
  // bail out on match
  if(&rSrc==static_cast<const Type*>(this)) return *this;

  // cast tests (clang 8.0.0 issues, 2017)
  /*
  const THIS* cgen=dynamic_cast<const THIS*>(&rSrc);
  FD_WARN("TcGenerator(" << this << ")::Assign(..): cgen " << cgen);
  const BASE* agen=dynamic_cast<const BASE*>(&rSrc);
  FD_WARN("TcGenerator(" << this << ")::Assign(..): agen " << agen);
  const vGenerator* vgen=dynamic_cast<const vGenerator*>(&rSrc);
  FD_WARN("TcGenerator(" << this << ")::Assign(..): vgen " << vgen);
  const BASE* agen2=dynamic_cast<const BASE*>(cgen);
  FD_WARN("TcGenerator(" << this << ")::Assign(..): agen2 " << agen);
  */

  // pass on to base
  FD_DG("TcGenerator(" << this << ")::Assign([type] " << &rSrc << "): call base");
  BASE::Assign(rSrc);  
  return *this;
}

// New
TEMP THIS* THIS::New(void) const {
  // allocate
  THIS* res = new THIS;
  // fix base data
  res->EventSymbolTablep(BASE::mpEventSymbolTable);
  res->mStateNamesEnabled=BASE::mStateNamesEnabled;
  res->mReindexOnWrite=BASE::mReindexOnWrite;  
  return res;
}

// Copy
TEMP THIS* THIS::Copy(void) const {
  // allocate
  THIS* res = new THIS(*this);
  // done
  return res;
}

// NewCGen
TEMP THIS THIS::NewCGen(void) const {
  // call base (fixes by assignment constructor)
  THIS res= BASE::NewAGen();
  return res;
}


// CAST
//TEMP const Type* THIS::Cast(const Type* pOther) const {
//  return dynamic_cast< const THIS* > (pOther);
//}



  // Controllable(index)
  TEMP bool THIS::Controllable(Idx index) const {
    EventAttr attr=BASE::EventAttribute(index);
    return attr.Controllable();
  } 
	
  // Controllable(rName)
  TEMP bool THIS::Controllable(const std::string& rName) const {
    EventAttr attr=BASE::EventAttribute(rName);
    return attr.Controllable();
  } 
	
  // InsControllableEvent(index)
  TEMP void THIS::InsControllableEvent(Idx index) {
    FD_DG("TcGenerator(" << this << ")::InsControllableEvent(" << index << ")");
    EventAttr attr;
    attr.SetControllable();
    BASE::InsEvent(index,attr);
  } 

  // InsControllableEvent(rName)
  TEMP Idx THIS::InsControllableEvent(const std::string& rName) {
    FD_DG("TcGenerator(" << this << ")::InsControllableEvent(" << rName << ")");
    EventAttr attr;
    attr.SetControllable();
    return BASE::InsEvent(rName,attr);
  } 

  // InsUncontrollableEvent(index)
  TEMP void THIS::InsUncontrollableEvent(Idx index) {
    FD_DG("TcGenerator(" << this << ")::InsUncontrollableEvent(" << index << ")");
    EventAttr attr;
    attr.ClrControllable();
    BASE::InsEvent(index,attr);
  } 

  // InsUncontrollableEvent(rName)
  TEMP Idx THIS::InsUncontrollableEvent(const std::string& rName) {
    FD_DG("TcGenerator(" << this << ")::InsUncontrollableEvent(" << rName << ")");
    EventAttr attr;
    attr.ClrControllable();
    return BASE::InsEvent(rName,attr);
  } 
    
  // SetControllable(index)
  TEMP void THIS::SetControllable(Idx index) {
    FD_DG("TcGenerator(" << this << ")::SetControllable(" << index << ")");
    EventAttr attr=BASE::EventAttribute(index);
    attr.SetControllable();
    BASE::pAlphabet->Attribute(index,attr);
  } 

  // SetControllable(rName)
  TEMP void THIS::SetControllable(const std::string& rName) {
    FD_DG("TcGenerator(" << this << ")::SetControllable(" << rName << ")");
    Idx index = BASE::EventIndex(rName);
    SetControllable(index);
  }

  //SetControllable(rEvents)
  TEMP void THIS::SetControllable(const EventSet& rEvents) {
    FD_DG("TcGenerator(" << this << ")::SetControllable(rEvents)");
    EventSet::Iterator it;
    for(it=rEvents.Begin(); it!=rEvents.End(); it++) {
      SetControllable(*it);
    }
  }
    
  // ClrControllable(index)
  TEMP void THIS::ClrControllable(Idx index) {
    FD_DG("TcGenerator(" << this << ")::ClrControllable(" << index << ")");
    EventAttr attr=BASE::EventAttribute(index);
    attr.ClrControllable();
    BASE::pAlphabet->Attribute(index,attr);
  } 

  // ClrControllable(rName)
  TEMP void THIS::ClrControllable(const std::string& rName) {
    FD_DG("TcGenerator(" << this << ")::ClrControllable(" << rName << ")");
    Idx index = BASE::EventIndex(rName);
    ClrControllable(index);
  }

  //ClrControllable(rEvents)
  TEMP void THIS::ClrControllable(const EventSet& rEvents) {
    FD_DG("TcGenerator(" << this << ")::ClrControllable(rEvents)");
    EventSet::Iterator it;
    for(it=rEvents.Begin(); it!=rEvents.End(); it++) {
      ClrControllable(*it);
    }
  }

  //ControllableEvents()
  TEMP EventSet THIS::ControllableEvents(void) const {
    FD_DG("TcGenerator(" << this << ")::ControllableEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(Controllable(*it)) res.Insert(*it);
    }
    return res;
  }
  
  //UncontrollableEvents()
  TEMP
    EventSet THIS::UncontrollableEvents(void) const {
    FD_DG("TcGenerator(" << this << ")::UncontrollableEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(!Controllable(*it)) res.Insert(*it);
    }
    return res;
  }
  
  // Observable(index)
  TEMP bool THIS::Observable(Idx index) const {
    EventAttr attr=BASE::EventAttribute(index);
    return attr.Observable();
  } 
	
  // Observable(rName)
  TEMP bool THIS::Observable(const std::string& rName) const {
    EventAttr attr=BASE::EventAttribute(rName);
    return attr.Observable();
  } 
	
  // InsObservableEvent(index)
  TEMP void THIS::InsObservableEvent(Idx index) {
    FD_DG("TcGenerator(" << this << ")::InsObservableEvent(" << index << ")");
    EventAttr attr;
    attr.SetObservable();
    BASE::InsEvent(index,attr);
  } 

  // InsObservableEvent(rName)
  TEMP Idx THIS::InsObservableEvent(const std::string& rName) {
    FD_DG("TcGenerator(" << this << ")::InsObservableEvent(" << rName << ")");
    EventAttr attr;
    attr.SetObservable();
    return BASE::InsEvent(rName,attr);
  } 

  // InsUnobservableEvent(index)
  TEMP void THIS::InsUnobservableEvent(Idx index) {
    FD_DG("TcGenerator(" << this << ")::InsUnobservableEvent(" << index << ")");
    EventAttr attr;
    attr.ClrObservable();
    BASE::InsEvent(index,attr);
  } 

  // InsUnobservableEvent(rName)
  TEMP Idx THIS::InsUnobservableEvent(const std::string& rName) {
    FD_DG("TcGenerator(" << this << ")::InsUnobservableEvent(" << rName << ")");
    EventAttr attr;
    attr.ClrObservable();
    return BASE::InsEvent(rName,attr);
  } 
    
  // SetObservable(index)
  TEMP void THIS::SetObservable(Idx index) {
    FD_DG("TcGenerator(" << this << ")::SetObservable(" << index << ")");
    EventAttr attr=BASE::EventAttribute(index);
    attr.SetObservable();
    BASE::pAlphabet->Attribute(index,attr);
  } 

  // SetObservable(rName)
  TEMP void THIS::SetObservable(const std::string& rName) {
    FD_DG("TcGenerator(" << this << ")::SetObservable(" << rName << ")");
    Idx index = BASE::EventIndex(rName);
    SetObservable(index);
  }

  //SetObservable(rEvents)
  TEMP void THIS::SetObservable(const EventSet& rEvents) {
    FD_DG("TcGenerator(" << this << ")::SetObservable(rEvents)");
    EventSet::Iterator it;
    for(it=rEvents.Begin(); it!=rEvents.End(); it++) {
      SetObservable(*it);
    }
  }
    
  // ClrObservable(index)
  TEMP void THIS::ClrObservable(Idx index) {
    FD_DG("TcGenerator(" << this << ")::ClrObservable(" << index << ")");
    EventAttr attr=BASE::EventAttribute(index);
    attr.ClrObservable();
    BASE::pAlphabet->Attribute(index,attr);
  } 

  // ClrObservable(rName)
  TEMP void THIS::ClrObservable(const std::string& rName) {
    FD_DG("TcGenerator(" << this << ")::ClrObservable(" << rName << ")");
    Idx index = BASE::EventIndex(rName);
    ClrObservable(index);
  }

  //ClrObservable(rEvents)
  TEMP void THIS::ClrObservable(const EventSet& rEvents) {
    FD_DG("TcGenerator(" << this << ")::ClrObservable(rEvents)");
    EventSet::Iterator it;
    for(it=rEvents.Begin(); it!=rEvents.End(); it++) {
      ClrObservable(*it);
    }
  }

  //ObservableEvents()
  TEMP EventSet THIS::ObservableEvents(void) const {
    FD_DG("TcGenerator(" << this << ")::ObservableEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(Observable(*it)) res.Insert(*it);
    }
    return res;
  }
  
  //UnobservableEvents()
  TEMP
    EventSet THIS::UnobservableEvents(void) const {
    FD_DG("TcGenerator(" << this << ")::UnobservableEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(!Observable(*it)) res.Insert(*it);
    }
    return res;
  }
  

  //Forcible(index)
  TEMP bool THIS::Forcible(Idx index) const {
    EventAttr attr=BASE::EventAttribute(index);
    return attr.Forcible();
  } 
	
  // Forcible(rName)
  TEMP bool THIS::Forcible(const std::string& rName) const {
    EventAttr attr=BASE::EventAttribute(rName);
    return attr.Forcible();
  } 
	
  // InsForcibleEvent(index)
  TEMP void THIS::InsForcibleEvent(Idx index) {
    FD_DG("TcGenerator(" << this << ")::InsForcibleEvent(" << index << ")");
    EventAttr attr;
    attr.SetForcible();
    BASE::InsEvent(index,attr);
  } 

  // InsForcibleEvent(rName)
  TEMP Idx THIS::InsForcibleEvent(const std::string& rName) {
    FD_DG("TcGenerator(" << this << ")::InsForcibleEvent(" << rName << ")");
    EventAttr attr;
    attr.SetForcible();
    return BASE::InsEvent(rName,attr);
  } 

  // InsUnforcibleEvent(index)
  TEMP void THIS::InsUnforcibleEvent(Idx index) {
    FD_DG("TcGenerator(" << this << ")::InsUnforcibleEvent(" << index << ")");
    EventAttr attr;
    attr.ClrForcible();
    BASE::InsEvent(index,attr);
  } 

  // InsUnforcibleEvent(rName)
  TEMP Idx THIS::InsUnforcibleEvent(const std::string& rName) {
    FD_DG("TcGenerator(" << this << ")::InsUnforcibleEvent(" << rName << ")");
    EventAttr attr;
    attr.ClrForcible();
    return BASE::InsEvent(rName,attr);
  } 
    
  // SetForcible(index)
  TEMP void THIS::SetForcible(Idx index) {
    FD_DG("TcGenerator(" << this << ")::SetForcible(" << index << ")");
    EventAttr attr=BASE::EventAttribute(index);
    attr.SetForcible();
    BASE::pAlphabet->Attribute(index,attr);
  } 

  // SetForcible(rName)
  TEMP void THIS::SetForcible(const std::string& rName) {
    FD_DG("TcGenerator(" << this << ")::SetForcible(" << rName << ")");
    Idx index = BASE::EventIndex(rName);
    SetForcible(index);
  }

  //SetForcible(rEvents)
  TEMP void THIS::SetForcible(const EventSet& rEvents) {
    FD_DG("TcGenerator(" << this << ")::SetForcible(rEvents)");
    EventSet::Iterator it;
    for(it=rEvents.Begin(); it!=rEvents.End(); it++) {
      SetForcible(*it);
    }
  }
    
  // ClrForcible(index)
  TEMP void THIS::ClrForcible(Idx index) {
    FD_DG("TcGenerator(" << this << ")::ClrForcible(" << index << ")");
    EventAttr attr=BASE::EventAttribute(index);
    attr.ClrForcible();
    BASE::pAlphabet->Attribute(index,attr);
  } 

  // ClrForcible(rName)
  TEMP void THIS::ClrForcible(const std::string& rName) {
    FD_DG("TcGenerator(" << this << ")::ClrForcible(" << rName << ")");
    Idx index = BASE::EventIndex(rName);
    ClrForcible(index);
  }

  //ClrForcible(rEvents)
  TEMP void THIS::ClrForcible(const EventSet& rEvents) {
    FD_DG("TcGenerator(" << this << ")::ClrForcible(rEvents)");
    EventSet::Iterator it;
    for(it=rEvents.Begin(); it!=rEvents.End(); it++) {
      ClrForcible(*it);
    }
  }

  //ForcibleEvents()
  TEMP EventSet THIS::ForcibleEvents(void) const {
    FD_DG("TcGenerator(" << this << ")::ForcibleEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(Forcible(*it)) res.Insert(*it);
    }
    return res;
  }
  
  //UnforcibleEvents()
  TEMP
    EventSet THIS::UnforcibleEvents(void) const {
    FD_DG("TcGenerator(" << this << ")::UnforcibleEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(!Forcible(*it)) res.Insert(*it);
    }
    return res;
  }
  

  //Highlevel(index)
  TEMP bool THIS::Highlevel(Idx index) const {
    EventAttr attr=BASE::EventAttribute(index);
    return attr.Highlevel();
  } 
	
  // Highlevel(rName)
  TEMP bool THIS::Highlevel(const std::string& rName) const {
    EventAttr attr=BASE::EventAttribute(rName);
    return attr.Highlevel();
  } 
	
  //Lowlevel(index)
  TEMP bool THIS::Lowlevel(Idx index) const {
    EventAttr attr=BASE::EventAttribute(index);
    return attr.Lowlevel();
  } 
	
  // Lowlevel(rName)
  TEMP bool THIS::Lowlevel(const std::string& rName) const {
    EventAttr attr=BASE::EventAttribute(rName);
    return attr.Lowlevel();
  } 
	
  // InsHighlevelEvent(index)
  TEMP void THIS::InsHighlevelEvent(Idx index) {
    FD_DG("TcGenerator(" << this << ")::InsHighlevelEvent(" << index << ")");
    EventAttr attr;
    attr.SetHighlevel();
    BASE::InsEvent(index,attr);
  } 

  // InsHighlevelEvent(rName)
  TEMP Idx THIS::InsHighlevelEvent(const std::string& rName) {
    FD_DG("TcGenerator(" << this << ")::InsHighlevelEvent(" << rName << ")");
    EventAttr attr;
    attr.SetHighlevel();
    return BASE::InsEvent(rName,attr);
  } 

  // InsLowlevelEvent(index)
  TEMP void THIS::InsLowlevelEvent(Idx index) {
    FD_DG("TcGenerator(" << this << ")::InsLowlevelEvent(" << index << ")");
    EventAttr attr;
    attr.SetLowlevel();
    BASE::InsEvent(index,attr);
  } 

  // InsLowlevelEvent(rName)
  TEMP Idx THIS::InsLowlevelEvent(const std::string& rName) {
    FD_DG("TcGenerator(" << this << ")::InsLowlevelEvent(" << rName << ")");
    EventAttr attr;
    attr.SetLowlevel();
    return BASE::InsEvent(rName,attr);
  } 
    
  // SetHighlevel(index)
  TEMP void THIS::SetHighlevel(Idx index) {
    FD_DG("TcGenerator(" << this << ")::SetHighlevel(" << index << ")");
    EventAttr attr=BASE::EventAttribute(index);
    attr.SetHighlevel();
    BASE::pAlphabet->Attribute(index,attr);
  } 

  // SetHighlevel(rName)
  TEMP void THIS::SetHighlevel(const std::string& rName) {
    FD_DG("TcGenerator(" << this << ")::SetHighlevel(" << rName << ")");
    Idx index = BASE::EventIndex(rName);
    SetHighlevel(index);
  }

  //SetHighlevel(rEvents)
  TEMP void THIS::SetHighlevel(const EventSet& rEvents) {
    FD_DG("TcGenerator(" << this << ")::SetHighlevel(rEvents)");
    EventSet::Iterator it;
    for(it=rEvents.Begin(); it!=rEvents.End(); it++) {
      SetHighlevel(*it);
    }
  }
    
  // SetLowlevel(index)
  TEMP void THIS::SetLowlevel(Idx index) {
    FD_DG("TcGenerator(" << this << ")::SetLowlevel(" << index << ")");
    EventAttr attr=BASE::EventAttribute(index);
    attr.SetLowlevel();
    BASE::pAlphabet->Attribute(index,attr);
  } 

  // SetLowlevel(rName)
  TEMP void THIS::SetLowlevel(const std::string& rName) {
    FD_DG("TcGenerator(" << this << ")::SetLowlevel(" << rName << ")");
    Idx index = BASE::EventIndex(rName);
    SetLowlevel(index);
  }

  //SetLowlevel(rEvents)
  TEMP void THIS::SetLowlevel(const EventSet& rEvents) {
    FD_DG("TcGenerator(" << this << ")::SetLowlevel(rEvents)");
    EventSet::Iterator it;
    for(it=rEvents.Begin(); it!=rEvents.End(); it++) {
      SetLowlevel(*it);
    }
  }

  //HighlevelEvents()
  TEMP EventSet THIS::HighlevelEvents(void) const {
    FD_DG("TcGenerator(" << this << ")::HighlevelEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(Highlevel(*it)) res.Insert(*it);
    }
    return res;
  }
  
  //LowlevelEvents()
  TEMP
    EventSet THIS::LowlevelEvents(void) const {
    FD_DG("TcGenerator(" << this << ")::LowlevelEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(Lowlevel(*it)) res.Insert(*it);
    }
    return res;
  }
  


#undef TEMP
#undef BASE
#undef THIS

 
} // namespace faudes

#endif

