/** @file cfl_agenerator.h Attributed generator class TaGenerator */

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
MERCHANTABILITY or FITNES FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA */


#ifndef FAUDES_AGENERATOR_H
#define FAUDES_AGENERATOR_H

#include "cfl_definitions.h"
#include "cfl_exception.h"
#include "cfl_symboltable.h"
#include "cfl_indexset.h"
#include "cfl_nameset.h"
#include "cfl_transset.h"
#include "cfl_token.h"
#include "cfl_tokenreader.h"
#include "cfl_tokenwriter.h"
#include "cfl_generator.h"
#include <map>
#include <set>
#include <sstream>
#include <cstdlib>
#include <assert.h>

namespace faudes {

/**
 * Generator with specified attribute types.
 *
 * @section AGeneratorOverview Overview
 *
 * The TaGenerator takes four template parameters to specify attribute classes for
 * the global attribute and state-, event- and transition-attributes. 
 *
 * In the context of a TaGenerator, attributes still have only minimal sematics: they can be 
 * accessed in a per event, state and transition manner and they can have default or non-default value. 
 * The minimum interface that an attribute template parameter must provide, is given in 
 * faudes::AttributeVoid. Derived attribute classes are meant to provide addtional semantics, eg 
 * faudes::AttributeFlags for boolean flags and faudes::AttributeCFlags for controllability properties. 
 * The TaGenerator transparently supports extended attribute semantics, but does not provide 
 * taylored access functions. This is done in TaGenerator
 * derivates eg TcGenerator.
 *
 * Technical detail: Attributes data types must be derived from AttributeVoid, which in turn is derived from 
 * the general purpose base faudes::Type. For your derived attribute class to be fully functional, 
 * you must reimplement the faudes::Type::New().
 *
 * @ingroup GeneratorClasses
 */

template <class GlobalAttr, class StateAttr, class EventAttr, class TransAttr>
class FAUDES_API TaGenerator : public vGenerator {
 public:
    
  /** Convenience typdef for member transiton set */
  typedef TaTransSet<TransAttr> ATransSet;


  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Constructors & Destructor */
  /** @{ doxygen group */

  /**
   * Construct an emtpy Generator
   */
  TaGenerator(void);

  /** 
   * Copy-constructor (from TaGenerator, incl attributes)
   *
   * @param rOtherGen
   */
  TaGenerator(const TaGenerator& rOtherGen);

  /** 
   * Copy-constructor (from vGenerator, set attributes to default)
   *
   * @param rOtherGen
   */
  TaGenerator(const vGenerator& rOtherGen);

  /**
   * Construct from file. This constructor
   * effectively uses the Read(TokenReader&) function to read.
   *
   * @param rFileName
   *   Name of file
   *
   * @exception Exception
   *   - IO errors (id 1)
   *   - Token mismatch (id 50, 51, 52, 80, 85)
   */
  TaGenerator(const std::string& rFileName);

  /**
   * Construct on heap. 
   * Technically not a constructor, this function creates a TaGenerator with the
   * same event symboltable and the same attribute types. It is the callers reponsebilty to
   * delete the object when no longer needed.
   *
   * @return 
   *   new Generator 
   */
  virtual TaGenerator* New(void) const;

  /**
   * Construct copy on heap. 
   * Technically not a constructor, this function creates a TaGenerator with the
   * same event symboltable and the same attribute types. It is the callers reponsebilty to
   * delete the object when no longer needed.
   *
   * @return 
   *   new Generator 
   */
  virtual TaGenerator* Copy(void) const;

  /**
   * Construct on stack.
   * Technically not a constructor, this function creates a TaGenerator with the
   * same event symboltable and the same attribute type. 
   *
   * @return 
   *   new Generator 
   */
  virtual TaGenerator NewAGen(void) const;

  /**
   * Type test.
   * Uses C++ dynamic cast to test whether the specified object
   * casts to a Generator.
   *
   * @return 
   *   TcGenerator reference if dynamic cast succeeds, else NULL 
   */
  virtual const Type* Cast(const Type* pOther) const;


  /**
   * Destructor
   */
  virtual ~TaGenerator(void);

  /** @} doxygen group */

  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Copy and Assignment */
  /** @{ doxygen group */


  /**
   * Copy from other faudes Type (try to cast to agenerator or pass to base)
   *
   * @param rSrc
   *   Source for copy operation.
   */
  virtual TaGenerator& Assign(const Type& rSrc); 

  /**
   * Assignment operator (uses Assign(Generator&) )
   *
   * @param rOtherGen
   *   Other generator
   */
  virtual TaGenerator& operator= (const TaGenerator& rOtherGen);

  /**
   * Destructive copy to other TaGenerator 
   * Copy method with increased performance at the cost of invalidating
   * the source data. This version will copy attributes 1:1.
   * 
   *
   * @param rGen
   *   Destination for copy operation.
   */
  virtual void Move(TaGenerator& rGen); 

  /**
   * Destructive copy to other Generator. 
   * Copy method with increased performance at the cost of invalidating
   * the source data. Convert attributes if possible.
   * 
   *
   * @param rGen
   *   Destination for copy operation.
   */
  virtual void Move(Generator& rGen); 


  /** @} doxygen group */

  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Basic Maintenance */
  /** @{ doxygen group */

  /** 
   * Check if generator is valid 
   *
   * @return 
   *   Success
   */
  bool Valid(void) const;


  /**
   * Clear generator data. 
   * Clears state set, alphabet and transitionrealtion. Behavioural flags
   * eg StateNamesEnabled are maintained.
   */
  virtual void Clear(void);



  /** @} doxygen group */



  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Read Access to Core Members */
  /** @{ doxygen group */

  /**
   * Return const reference to alphabet 
   *
   * @return EventSet
   *   Reference to mpAlphabet
   */
  const TaEventSet<EventAttr>& Alphabet(void) const;

  /**
   * Return reference to state set
   *
   * @return 
   *   StateSet reference incl actual attribute type
   */
  const TaStateSet<StateAttr>& States(void) const;

  /**
   * Return reference to transition relation
   *
   * @return TransRel
   */
  const ATransSet& TransRel(void) const;

  /**
   * Get copy of trantision relation  sorted by other compare 
   * operator, e.g. "x2,ev,x1"
   * 
   * @param res
   *   resulting transition relation 
   */
  void TransRel(TransSetX1EvX2& res) const;
  void TransRel(TransSetEvX1X2& res) const;
  void TransRel(TransSetEvX2X1& res) const;
  void TransRel(TransSetX2EvX1& res) const;
  void TransRel(TransSetX2X1Ev& res) const;
  void TransRel(TransSetX1X2Ev& res) const;

  /** @} doxygen group */



  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Write Access to Core Members */
  /** @{ doxygen group */


  /**
   * Add an existing event to alphabet by index. It is an error to insert
   * an event index that is not known to the mpEventSymbolTable.
   *
   * @param index
   *   Event index
   * @return
   *   True, if event was new to alphabet
   */
  bool InsEvent(Idx index);

  /**
   * Add named event to generator. An entry in the mpEventSymbolTable will
   * be made if event name is not known so far.
   *
   * @param rName
   *   Name of the event to add
   *
   * @return 
   *   New unique index
   */
  Idx InsEvent(const std::string& rName);

  /**
   * Add an existing event to alphabet by index, incl. attribute
   * If the index allready exists, the attribute is overwritten by rAttr.
   *
   * @param rAttr
   *   Attribute of event
   * @param index
   *   Event index
   * @return
   *   True, if event was new to alphabet
   */
  bool InsEvent(Idx index, const EventAttr& rAttr);

  /**
   * Add named event with attribute to generator. An entry in the 
   * mpEventSymbolTable will be made if event is not kown so far.
   * If the event allready exits in the generator, the attribute will be
   * overwritten by rAttr.
   *
   * @param rName
   *   Name of the event to add
   * @param rAttr
   *   Attribute of event
   *
   * @return 
   *   New unique index
   */
  Idx InsEvent(const std::string& rName, const EventAttr& rAttr);

  /**
   * Set mpAlphabet without consistency check.
   * Attributes will be casted if possible or silently ignored.
   *
   * @param rNewalphabet
   *   EventSet with new alphabet
   */
  void InjectAlphabet(const EventSet& rNewalphabet);

  /**
   * Set mpAlphabet without consistency check.
   *
   * @param rNewalphabet
   *   EventSet with new alphabet
   */
  void InjectAlphabet(const TaEventSet<EventAttr>& rNewalphabet);

  /** 
   * Add new anonymous state to generator 
   * 
   * @return 
   *   Index of new unique state
   */
  Idx InsState(void);

  /** 
   * Add new anonymous state with attribute to generator 
   * 
   * @param attr
   *   attribute of new state
   *
   * @return 
   *   Index of new unique state
   */
  Idx InsState(const StateAttr& attr);

  /** 
   * Add (perhaps new) state to generator 
   * 
   * @return 
   *   true to indicate that state was new to generator
   */
  bool InsState(Idx index);

  /** 
   * Add new named state to generator. 
   *
   * @param rName
   *   Name of the state to add
   *
   * @return 
   *   Index of new unique state
   *
   * @exception Exception
   *   Name already exists (id 44)
   */
  Idx InsState(const std::string& rName);

  /** 
   * Add new named state with attribute to generator. 
   *
   * @param rName
   *   Name of the state to add
   * @param attr
   *   attribute of new state
   *
   * @return 
   *   Index of new unique state
   * @exception Exception
   *   Name already exists (id 44)
   */
  Idx InsState(const std::string& rName, const StateAttr& attr);

  /** 
   * Add (perhaps new) state with attribute to generator. 
   *
   * @param index
   *   Index of state to add
   * @param attr
   *   Attribute of new state
   *
   * @return
   *   True, if event was new to alphabet
   *
   */
  bool InsState(Idx index, const StateAttr& attr);

  /**
   * Inject a complete state set without consistency checks.
   * Attributes will be casted if possible or silently ignored.
   *
   * @param rNewStates
   *    StateSet
   */
  void InjectStates(const StateSet& rNewStates);


  /**
   * Inject a complete state set without consistency checks.
   *
   * @param rNewStates
   *    StateSet
   */
  void InjectStates(const TaStateSet<StateAttr>& rNewStates);


  /** 
   * Add a transition to generator by indices. States and event
   * must already exist!
   *
   * Define FAUDES_CHECKED for consistency checks.
   *
   * @param x1 
   *   Predecessor state index 
   * @param ev 
   *   Event index 
   * @param x2
   *   Successor state index
   *
   * @return
   *   True, if the transition was new the generator
   *
   * @exception Exception
   *   - state or event not in generator (id 95)
   */
  bool SetTransition(Idx x1, Idx ev, Idx x2);

  /** 
   * Add a transition to generator by names. Statename and eventname
   * must already exist!
   *
   * @param rX1
   *   Predecessor state name
   * @param rEv
   *   Event name
   * @param rX2
   *   Successor state name
   *
   * @return
   *   True, if the transition was new the generator
   *
   * @exception Exception
   *   - state or event not in generator (id 95)
   *   - state name not known (id 90)
   *   - event name not known (id 66)
   */
  bool SetTransition(const std::string& rX1, const std::string& rEv, 
				   const std::string& rX2);

  /** 
   * Add a transition to generator. States and event
   * must already exist!
   *
   *
   * @param rTransition
   *   Transition
   *
   * @return
   *   True, if the transition was new the generator
   * @exception Exception
   *   - state or event not in generator (id 95)
   */
  bool SetTransition(const Transition& rTransition);

  /** 
   * Add a transition with attribute to generator. States and event
   * must already exist!
   *
   *
   * @param rTransition
   *   transition
   * @param rAttr
   *   attribute
   * @return
   *   True, if the transition was new the generator
   * @exception Exception
   *   - state or event not in generator (id 95)
   *
   */
  bool SetTransition(const Transition& rTransition, const TransAttr& rAttr);

  /**
   * Set transition relation without consistency check.
   * Attributes will be casted if possible or silently ignored.
   *
   * @param rNewtransrel
   *   TransRel to insert
   */
  void InjectTransRel(const TransSet& rNewtransrel);

  /**
   * Set transition relation without consistency check.
   *
   * @param rNewtransrel
   *   TransRel to insert
   */
  void InjectTransRel(const ATransSet& rNewtransrel);

  /** @} doxygen group */



  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Attributes */
  /** @{ doxygen group */


  /**
   * Set attribute for existing event
   *
   * @param index
   *   Event index
   * @param rAttr
   *   New attribute
   *
   * @exception Exception
   *   Index not found in alphabet (id 60)
   */
   void EventAttribute(Idx index, const EventAttr& rAttr);

  /**
   * Set attribute for existing event. 
   * This version uses a dynamic cast
   * to test the actual type of the provided attribute. An exception is
   * thrown for an invalid attribute type.
   *
   * @param index
   *   Event index
   * @param rAttr
   *   New attribute
   *
   * @exception Exception
   *   - Index not found in alphabet (id 60)
   *   - Cannot cast attribute (id 63)
   */
   void EventAttribute(Idx index, const Type& rAttr);

  /** 
   * Event attribute lookup 
   *
   * @param index
   *
   * @return 
   *   reference to attribute
   */
  const EventAttr& EventAttribute(Idx index) const;

  /** 
   * Event attribute lookup 
   *
   * @param rName
   *
   * @return 
   *   reference to attribute
   */
  const EventAttr& EventAttribute(const std::string& rName) const;

  /** 
   * Event attribute pointer (to access Attribute methods)
   * note: may insert explicit default attribute
   *
   * @param index
   *
   * @return 
   *   pointer to attribute
   */
  EventAttr* EventAttributep(Idx index);

  /** 
   * Event attribute pointer (to access Attribute methods)
   * note: may insert explicit default attribute
   *
   * @param rName
   *
   * @return 
   *   pointer to attribute
   */
  EventAttr* EventAttributep(const std::string& rName);


  /** 
   * Set attribute for existing state
   *
   * @param index
   *   Index
   * @param rAttr
   *   attriute
   *
   * @exception Exception
   *   Name already associated with another index (id 44)
   */
  void StateAttribute(Idx index, const StateAttr& rAttr);

  /**
   * Set attribute for existing state. 
   * This version uses a dynamic cast
   * to test the actual type of the provided attribute. An exception is
   * thrown for an invalid attribute type.
   *
   * @param index
   *   State index
   * @param rAttr
   *   New attribute
   *
   * @exception Exception
   *   - Index not found in Stateset (id 60)
   *   - Cannot cast attribute (id 63)
   */
  void StateAttribute(Idx index, const Type& rAttr);

  /** 
   * State attribute lookup 
   *
   * @param index
   *
   * @return ref to attribute of state
   */
  const StateAttr& StateAttribute(Idx index) const;

  /** 
   * State attribute pointer (to access Attribute methods) 
   * note: may insert explicit default attribute
   *
   * @param index
   *
   * @return pointer to attribute of state
   */
  StateAttr* StateAttributep(Idx index);

  /**
   * Set attribute for existing transition
   *
   * @param rTrans
   *   transition
   * @param rAttr
   *   New attribute
   *
   */
  void TransAttribute(const Transition& rTrans, const TransAttr& rAttr);

  /**
   * Set attribute for existing transition.
   * This version uses a dynamic cast
   * to test the actual type of the provided attribute. An exception is
   * thrown for an invalid attribute type.
   *
   * @param rTrans
   *   transition
   * @param rAttr
   *   New attribute
   *
   * @exception Exception
   *   - Transition not found in transition relation(id 60)
   *   - Cannot cast attribute (id 63)
   */
   void TransAttribute(const Transition& rTrans, const Type& rAttr);


  /**
   * Get attribute for existing transition
   *
   * @return 
   *   attribute
   *
   */
  const TransAttr& TransAttribute(const Transition& rTrans) const;

  /**
   * Get attribute pointer for existing transition
   * note: may insert explicit default attribute
   *
   * @return 
   *   attribute pointer
   *
   */
  TransAttr* TransAttributep(const Transition& rTrans);

  /** 
   * Set global attribute 
   *
   * @param rAttr
   *   attribute
   */
  void GlobalAttribute(const GlobalAttr& rAttr) {*pGlobalAttribute=rAttr;};
  void GlobalAttribute(const Type& rAttr) { const GlobalAttr* ap= dynamic_cast<const GlobalAttr*>(&rAttr); if(ap) *pGlobalAttribute=*ap;};

  /** 
   * Get global attribute ref
   */
  const GlobalAttr& GlobalAttribute(void) const {return *pGlobalAttribute;};


  /** 
   * Get global attribute pointer 
   */
  GlobalAttr* GlobalAttributep(void) {return pGlobalAttribute;};


  /** @} doxygen group */




 protected:

  /** Alphabet, pointer with actual attribute type */
  TaNameSet<EventAttr>* pAlphabet;

  /** State set, pointer with actual attribute type */
  TaIndexSet<StateAttr>* pStates;

  /** Transition relation, pointer with actual attribute type */
  ATransSet* pTransRel;

  /** Global attribute, pointer with actual attribute type */
  GlobalAttr* pGlobalAttribute;

  /** Static default alphabet prototype (incl. attribute type) */
  static const TaNameSet<EventAttr>& AlphabetTaGen(void);

  /** Static default state set prototype (incl. attribute type) */
  static const TaIndexSet<StateAttr>& StatesTaGen(void);

  /** Static default transition relation prototype (incl. attribute type) */
  static const ATransSet& TransRelTaGen(void);

  /** Static default global attribute prototype (configures global attribute type) */
  static const GlobalAttr& GlobalTaGen(void);

  /** Allocate my heap members (attribute dependent types) */
  virtual void NewCore(void);

  /** Update my secondary pointers for new core */
  virtual void UpdateCore(void);

  /** Assignment */
  void DoAssign(const TaGenerator& rGen); 


};



/* convenience access to relevant scopes */
#define THIS TaGenerator<GlobalAttr, StateAttr, EventAttr, TransAttr>
#define TEMP template <class GlobalAttr, class StateAttr, class EventAttr, class TransAttr>
#define BASE vGenerator

// static default prototypes (construct on first use design pattern)
TEMP const TaNameSet<EventAttr>& THIS::AlphabetTaGen(void) {
  static TaNameSet<EventAttr> fls;
  return fls;
}
TEMP const  TaIndexSet<StateAttr>& THIS::StatesTaGen(void) {
  static  TaIndexSet<StateAttr> fls;
  return fls;
}
TEMP const TaTransSet<TransAttr>& THIS::TransRelTaGen(void) {
  static TaTransSet<TransAttr> fls;
  return fls;
}
TEMP const GlobalAttr& THIS::GlobalTaGen(void) {
  static GlobalAttr fls;;
  return fls;
}


// TaGenerator::Generator(void)
TEMP THIS::TaGenerator(void) : 
  // init base 
  vGenerator() 
{  
  FD_DG("TaGenerator(" << this << ")::TaGenerator()");
  // re-allocate core members with nontrivial attribute types
  ConfigureAttributeTypes(&GlobalTaGen(),&StatesTaGen(),&AlphabetTaGen(),&TransRelTaGen());
  NewCore();
  FD_DG("TaGenerator(" << this << ")::TaGenerator(): done");
}

// TaGenerator::Generator(rOtherGen)
TEMP THIS::TaGenerator(const TaGenerator& rOtherGen) : 
  // init base
  vGenerator()
{
  FD_DG("TaGenerator(" << this << ")::TaGenerator(" << &rOtherGen << ")");
  // re-allocate core members with nontrivial attribute types
  ConfigureAttributeTypes(&GlobalTaGen(),&StatesTaGen(),&AlphabetTaGen(),&TransRelTaGen());
  NewCore();
  // have  a 1:1 copy (incl sym tables)
  DoAssign(rOtherGen);
}


// TaGenerator::Generator(rOtherGen)
TEMP THIS::TaGenerator(const vGenerator& rOtherGen) : 
  // init base
  vGenerator()
{
  FD_DG("TaGenerator(" << this << ")::TaGenerator([v]" << &rOtherGen << ")");
  // re-allocate core members with nontrivial attribute types
  ConfigureAttributeTypes(&GlobalTaGen(),&StatesTaGen(),&AlphabetTaGen(),&TransRelTaGen());
  NewCore();
  // have  a 1:1 copy (incl sym tables)
  Assign(rOtherGen);
  FD_DG("TaGenerator(" << this << ")::TaGenerator([v]" << &rOtherGen << "): ok");
}

// TaGenerator::Generator(rFileName)
TEMP THIS::TaGenerator(const std::string& rFileName) : 
  // init base
  vGenerator()
{
  FD_DG("TaGenerator(" << this << ")::TaGenerator(" << rFileName << ")");
  // re-allocate core members with nontrivial attribute types
  ConfigureAttributeTypes(&GlobalTaGen(),&StatesTaGen(),&AlphabetTaGen(),&TransRelTaGen());
  NewCore();
  // set some defaults
  mStateNamesEnabled=true;
  // do read
  Read(rFileName);
  // get original statenames default
  mStateNamesEnabled=msStateNamesEnabledDefault;
}

// allocate core on heap
TEMP void THIS::NewCore(void) {
  FD_DG("TaGenerator(" << this << ")::NewCore()");

  // MS Compilers did somehow mess up upcast with diamond inheritance of TaNameSet-member New()
  // call base, incl virtual call back of UpdateCore
  //BASE::NewCore();

  DeleteCore();
  // allocate by our typed prototypes
  mpAlphabet= AlphabetTaGen().New();
  mpStates=StatesTaGen().New();
  mpTransRel=TransRelTaGen().New();
  mpGlobalAttribute=GlobalTaGen().New();
  // update callback
  UpdateCore();
}
  
// indicate new core
TEMP void THIS::UpdateCore(void) {
  // let base do an update (fixes names)
  BASE::UpdateCore(); 
  // have pointer with my attribute
  pGlobalAttribute = dynamic_cast< GlobalAttr* >(mpGlobalAttribute);
  pAlphabet = dynamic_cast< TaNameSet<EventAttr>* >(mpAlphabet);
  pStates = dynamic_cast< TaIndexSet<StateAttr>* >(mpStates);
  pTransRel = dynamic_cast< ATransSet* >(mpTransRel);
  // check for type mismatch
  bool tmm=false;
  if(pGlobalAttribute==0 && mpGlobalAttribute!=0) tmm=true;
  if(pAlphabet==0 && mpAlphabet!=0) tmm=true;
  if(pStates==0 && mpStates!=0) tmm=true;
  if(pTransRel==0 && mpTransRel!=0) tmm=true;
  if(tmm) { 
    std::stringstream errstr;
    errstr << "cannot cast attributes for generator type " << typeid(*this).name();
    errstr << " ptrs " << pGlobalAttribute << "-" << pAlphabet << "-" << pStates << "-" << pTransRel;
    throw Exception("Generator::UpdateCore", errstr.str(), 63);
  }
}


// Copy(gen) from identical type
TEMP void THIS::DoAssign(const TaGenerator& rGen) {
  FD_DG("TaGenerator(" << this << ")::DoAssign(" << &rGen << ")");
  FD_DG("TaGenerator(" << this << ")::DoAssign(..): types " << typeid(*this).name() << " <= " << typeid(rGen).name());
  // prepare result (call clear for virtual stuff)
  Clear();
  // have same event symboltable
  EventSymbolTablep(rGen.mpEventSymbolTable);
  // copy state symboltable
  StateSymbolTable(rGen.mStateSymbolTable);
  // set other members
  Name(rGen.Name());
  *pGlobalAttribute=*rGen.pGlobalAttribute;
  *pStates= *rGen.pStates;
  *pAlphabet = *rGen.pAlphabet;
  *pTransRel= *rGen.pTransRel;
  mInitStates = rGen.mInitStates;
  mMarkedStates = rGen.mMarkedStates;
  mStateNamesEnabled=rGen.mStateNamesEnabled;
  mReindexOnWrite=rGen.mReindexOnWrite;
  // copy add on stuff
  mMinStateIndexMap=rGen.mMinStateIndexMap;
#ifdef FAUDES_DEBUG_CODE
  if(!Valid()) {
    FD_DG("TaGenerator()::DoAssign(): invalid generator");
    DWrite(); 
    abort();
  }
#endif
  FD_DG("TaGenerator(" << this << ")::DoAssign(" << &rGen << "): done");
} 

// copy from other faudes type
TEMP THIS& THIS::Assign(const Type& rSrc) {
  FD_DG("TaGenerator(" << this << ")::Assign([type] " << &rSrc << ")");
  FD_DG("TaGenerator(" << this << ")::Assign(..): types \n" << typeid(*this).name() << " <= \n" << typeid(rSrc).name());
  FD_DG("TaGenerator(" << this << ")::Assign(..): match str " << (typeid(*this).name() == typeid(rSrc).name()));
  FD_DG("TaGenerator(" << this << ")::Assign(..): match id  " << (typeid(*this) == typeid(rSrc)));
  // cast to this class  
  const TaGenerator* agen=dynamic_cast<const THIS*>(&rSrc);
  FD_DG("TaGenerator(" << this << ")::Assign(..): agen " << agen);
  // bail out on object match
  if(this==agen) return *this;
  // assign on type match
  if(agen) {
    FD_DG("TaGenerator(" << this << ")::Assign([type] " << &rSrc << "):: call aGenerator DoAssign");
    DoAssign(*agen);
    return *this;
  }
  FD_DG("TaGenerator(" << this << ")::Assign([type] " << &rSrc << "):: call vGenerator base");
  // pass on to base
  BASE::Assign(rSrc);
  return *this;
}


// Move(gen) destructive copy
TEMP void THIS::Move(TaGenerator& rGen) {
  FD_DG("TaGenerator(" << this << ")::Move(" << &rGen << ")");
  // call base
  BASE::Move(rGen);
}


// Move(gen) destructive copy
TEMP void THIS::Move(Generator& rGen) {
  FD_DG("TaGenerator(" << this << ")::Move([v]" << &rGen << ")");
  // call base
  BASE::Move(rGen);
}

// TaGenerator::~Generator
TEMP THIS::~TaGenerator(void) {
  FD_DG("TaGenerator(" << this << ")::~TaGenerator()");
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

// NewAGen()
TEMP THIS THIS::NewAGen(void) const {
  THIS res;
  // fix base data
  res.EventSymbolTablep(BASE::mpEventSymbolTable);
  //res.mStateNamesEnabled=BASE::mStateNamesEnabled;
  //res.ReindexOnWrite=BASE::mReindexOnWrite;  
  res.StateNamesEnabled(BASE::mStateNamesEnabled);  
  res.ReindexOnWrite(BASE::mReindexOnWrite);  
  return res;
}


// CAST
TEMP const Type* THIS::Cast(const Type* pOther) const {
  return dynamic_cast< const THIS* > (pOther);
}


// operator=
TEMP TaGenerator<GlobalAttr,StateAttr,EventAttr,TransAttr>& THIS::operator= (const TaGenerator& rOtherGen) {
  FD_DG("TaGenerator(" << this << ")::operator = [v]" << &rOtherGen);
  return Assign(rOtherGen);
}

// Valid()
TEMP bool THIS::Valid(void) const {
  FD_DG("TaGenerator(" << this << ")::Valid()");
  if(!BASE::Valid()) return false;
  // test types
  bool tmm=false;
  if(typeid(Alphabet().AttributeType())!=typeid(const EventAttr*)) tmm=true;
  if(typeid(States().AttributeType())!=typeid(const StateAttr*)) tmm=true;
  if(typeid(TransRel().AttributeType())!=typeid(const TransAttr*)) tmm=true;
  if(typeid(GlobalAttribute())!=typeid(const GlobalAttr&)) tmm=true;
  if(tmm) { 
    return false;
    //std::stringstream errstr;
    //errstr << "attribute type mismatch in generator " << Name();
    //throw Exception("Generator::Valid", errstr.str(), 63);
  }
  return true;
}

// Clear()
TEMP void THIS::Clear(void) {
  FD_DG("TaGenerator(" << this << ")::Clear()");
  BASE::Clear();
}


// InjectAlphabet(newalphabet)
TEMP void THIS::InjectAlphabet(const EventSet& rNewAlphabet) {
  FD_DG("TaGenerator::InjectAlphabet()  " << rNewAlphabet.ToString());
  BASE::InjectAlphabet(rNewAlphabet);
}

// InjectAlphabet(newalphabet)
TEMP void THIS::InjectAlphabet(const TaEventSet<EventAttr>& rNewAlphabet) {
  FD_DG("TaGenerator::InjectAlphabet(TaEventSet<EventAttr>)  " << rNewAlphabet.ToString());
#ifdef FAUDES_CHECKED
  if(rNewAlphabet.SymbolTablep()!=mpEventSymbolTable) {
    std::stringstream errstr;
    errstr << "symboltable mismatch aka not implemented" << std::endl;
    throw Exception("TaGenerator::InjectAlphabet", errstr.str(), 88);
  }
#endif
  *pAlphabet=rNewAlphabet;
  mpAlphabet->Name("Alphabet");
}

// InsEvent(index)
TEMP bool THIS::InsEvent(Idx index) {
  FD_DG("TaGenerator(" << this << ")::InsEvent(" << index << ")");
  return pAlphabet->Insert(index);
}

// InsEvent(rName)
TEMP Idx THIS::InsEvent(const std::string& rName) {
  FD_DG("TaGenerator(" << this << ")::InsEvent(\"" << rName << "\")");
  return pAlphabet->Insert(rName);
}

// InsEvent(index, attr)
TEMP bool THIS::InsEvent(Idx index, const EventAttr& attr) {
  FD_DG("TaGenerator(" << this << ")::InsEvent(" << index << " " << attr.ToString() << ")");
  return pAlphabet->Insert(index, attr);
}

// InsEvent(rName)
TEMP Idx THIS::InsEvent(const std::string& rName, const EventAttr& attr) {
  FD_DG("TaGenerator(" << this << ")::InsEvent(\"" << rName << attr.ToString() << "\")");
  return pAlphabet->Insert(rName, attr);
}

// InsState()
TEMP Idx THIS::InsState(void) {
  FD_DG("TaGenerator(" << this << ")::InsState()");
  return pStates->Insert();
}

// InsState(attr)
TEMP Idx THIS::InsState(const StateAttr& attr) {
  FD_DG("TaGenerator(" << this << ")::InsState(attr)");
  return pStates->Insert(attr);
}

// InsState(index)
TEMP bool THIS::InsState(Idx index) {
  FD_DG("TaGenerator(" << this << ")::InsState(" << index << ")");
  return pStates->Insert(index);
}

// InsState(index, attr)
TEMP bool THIS::InsState(Idx index, const StateAttr& rAttr) {
  FD_DG("TaGenerator(" << this << ")::InsState(" << index << ",rAttr)");
  return pStates->Insert(index,rAttr);
}

// InsState(rName)
TEMP Idx THIS::InsState(const std::string& rName) {
  FD_DG("TaGenerator(" << this << ")::InsState(\"" << rName << "\")");
  Idx index=pStates->Insert();
  StateName(index,rName);
  return index;
}

// InsState(rName, attr)
TEMP Idx THIS::InsState(const std::string& rName, const StateAttr& attr) {
  FD_DG("TaGenerator(" << this << ")::InsState(\"" << rName << "\", attr)");
  Idx index=pStates->Insert();
  StateName(index,rName);
  StateAttribute(index,attr);
  return index;
}


// InjectStates(rNewStates)
TEMP void THIS::InjectStates(const StateSet& rNewStates) {
  FD_DG("TaGenerator(" << this << ")::InjectStates(" 
	<< rNewStates.ToString() << ")");
  BASE::InjectStates(rNewStates);
}

// InjectStates(rNewStates)
TEMP void THIS::InjectStates(const TaStateSet<StateAttr>& rNewStates) {
  FD_DG("TaGenerator(" << this << ")::InjectStates(" 
	<< rNewStates.ToString() << ")");
  *pStates=rNewStates;
   pStates->Name("States");
   mpStateSymbolTable->RestrictDomain(*mpStates);
}



// InjectTransRel(rNewtransrel)
TEMP void THIS::InjectTransRel(const TransSet& rNewTransRel) {
  FD_DG("TaGenerator::InjectTransRel(...)");
  *pTransRel=rNewTransRel;
}

// InjectTransRel(rNewtransrel)
TEMP void THIS::InjectTransRel(const ATransSet& rNewTransRel) {
  FD_DG("TaGenerator::InjectTransRel(...)");
  *pTransRel=rNewTransRel;
}


// SetTransition(rX1, rEv, rX2)
TEMP bool THIS::SetTransition(const std::string& rX1, const std::string& rEv, const std::string& rX2) {
  return BASE::SetTransition(rX1,rEv,rX2);
}


// SetTransition(x1, ev, x2)
TEMP bool THIS::SetTransition(Idx x1, Idx ev, Idx x2) {
  return SetTransition(Transition(x1,ev,x2));
}

// SetTransition(rTransition)
TEMP bool THIS::SetTransition(const Transition& rTransition) {
  FD_DG("TaGenerator(" << this << ")::SetTransition(" << rTransition.X1 << "," 
	<< rTransition.Ev << "," << rTransition.X2 << ")");
#ifdef FAUDES_CHECKED
  if (! mpStates->Exists(rTransition.X1)) {
    std::stringstream errstr;
    errstr << "TaGenerator::SetTransition: state " << rTransition.X1 
	   << " not in stateset";
    throw Exception("TaGenerator::SetTransition(..)", errstr.str(), 95);
  }
  if (! mpAlphabet->Exists(rTransition.Ev)) {
    std::stringstream errstr;
    errstr << "TaGenerator::SetTransition: event " << rTransition.Ev 
	   << " not in alphabet ";
    throw Exception("TaGenerator::SetTransition(..)", errstr.str(), 95);
  }
  if (! mpStates->Exists(rTransition.X2)) {
    std::stringstream errstr;
    errstr << "TaGenerator::SetTransition: state " << rTransition.X2 
	   << " not in stateset";
    throw Exception("TaGenerator::SetTransition(..)", errstr.str(), 95);
  }
#endif
  return pTransRel->Insert(rTransition);
}

// SetTransition(rTransition, rAttr)
TEMP bool THIS::SetTransition(const Transition& rTransition, const TransAttr& rAttr) {
  FD_DG("TaGenerator(" << this << ")::SetTransition(" << rTransition.X1 << "," 
	<< rTransition.Ev << "," << rTransition.X2 << ", [attr:]" << rAttr.ToString() << ")");
#ifdef FAUDES_CHECKED
  if (! mpStates->Exists(rTransition.X1)) {
    std::stringstream errstr;
    errstr << "TaGenerator::SetTransition: state " << rTransition.X1 
	   << " not in stateset";
    throw Exception("TaGenerator::SetTransition(..)", errstr.str(), 95);
  }
  if (! mpAlphabet->Exists(rTransition.Ev)) {
    std::stringstream errstr;
    errstr << "TaGenerator::SetTransition: event " << rTransition.Ev 
	   << " not in alphabet ";
    throw Exception("TaGenerator::SetTransition(..)", errstr.str(), 95);
  }
  if (! mpStates->Exists(rTransition.X2)) {
    std::stringstream errstr;
    errstr << "TaGenerator::SetTransition: state " << rTransition.X2 
	   << " not in stateset";
    throw Exception("TaGenerator::SetTransition(..)", errstr.str(), 95);
  }
#endif
  return pTransRel->Insert(rTransition,rAttr);
}

// TransAttribute(trans, attr)
TEMP void THIS::TransAttribute(const Transition& rTrans, const TransAttr& rAttr)  {
  FD_DG("TaGenerator(" << this << ")::TransAttribute(" 
	<< TStr(rTrans) << ",\"" << rAttr.ToString() << "\")");
  pTransRel->Attribute(rTrans, rAttr);
}

// TransAttribute(index, attr)
TEMP void THIS::TransAttribute(const Transition& rTrans, const Type& rAttr) {
  FD_DG("TaGenerator(" << this << ")::TransAttribute(" 
	<< TStr(rTrans) << ",\"" << rAttr.ToString() << "\")");
  const TransAttr* attrp = dynamic_cast<const TransAttr*>(&rAttr);
  if(!attrp) {
    std::stringstream errstr;
    errstr << "cannot cast event attribute " << rAttr.ToString() << " for generator " << Name();
    throw Exception("TaGenerator::TransAttribute", errstr.str(), 63);
  }
  pTransRel->Attribute(rTrans, *attrp);
}

// TransAttributep(trans)
TEMP TransAttr* THIS::TransAttributep(const Transition& rTrans)  {
  return pTransRel->Attributep(rTrans);
}


// TransAttribute(trans)
TEMP const TransAttr& THIS::TransAttribute(const Transition& rTrans) const {
  return pTransRel->Attribute(rTrans);
}

// EventAttribute(index, attr)
TEMP void THIS::EventAttribute(Idx index, const EventAttr& rAttr) {
  FD_DG("TaGenerator(" << this << ")::EventAttribute(" 
	<< EStr(index) << ",\"" << rAttr.ToString() << "\")");
  pAlphabet->Attribute(index, rAttr);
}

// EventAttribute(index, attr)
TEMP void THIS::EventAttribute(Idx index, const Type& rAttr) {
  FD_DG("TaGenerator(" << this << ")::EventAttribute(" 
	<< EStr(index) << ",\"" << rAttr.ToString() << "\")");
  const EventAttr* attrp = dynamic_cast<const EventAttr*>(&rAttr);
  if(!attrp) {
    std::stringstream errstr;
    errstr << "cannot cast event attribute " << rAttr.ToString() << " for generator " << Name();
    throw Exception("TaGenerator::EventAttribute", errstr.str(), 63);
  }
  pAlphabet->Attribute(index, *attrp);
}

// EventAttribute(index)
TEMP const EventAttr&  THIS::EventAttribute(Idx index) const {
  return pAlphabet->Attribute(index);
}

// EventAttributep(index)
TEMP EventAttr* THIS::EventAttributep(Idx index) {
  return pAlphabet->Attributep(index);
}

// EventAttribute(rName)
TEMP const EventAttr&  THIS::EventAttribute(const std::string& rName) const {
  return EventAttribute(EventIndex(rName));
}

// EventAttributep(rName)
TEMP EventAttr* THIS::EventAttributep(const std::string& rName) {
  return EventAttributep(EventIndex(rName));
}

// StateAttribute(index, attr)
TEMP void THIS::StateAttribute(Idx index, const StateAttr& rAttr) {
  FD_DG("TaGenerator(" << this << ")::StateAttribute(" 
	<< index << ",\"" << rAttr.ToString() << "\")");
  pStates->Attribute(index, rAttr);
}

// StateAttribute(index, attr)
TEMP void THIS::StateAttribute(Idx index, const Type& rAttr) {
  FD_DG("TaGenerator(" << this << ")::StateAttribute(" 
	<< SStr(index) << ",\"" << rAttr.ToString() << "\")");
  const StateAttr* attrp = dynamic_cast<const StateAttr*>(&rAttr);
  if(!attrp) {
    std::stringstream errstr;
    errstr << "cannot cast event attribute " << rAttr.ToString() << " for generator " << Name();
    throw Exception("TaGenerator::StateAttribute", errstr.str(), 63);
  }
  pStates->Attribute(index, *attrp);
}


// StateAttribute(index)
TEMP const StateAttr&  THIS::StateAttribute(Idx index) const {
  return pStates->Attribute(index);
}

// StateAttributep(index)
TEMP StateAttr*  THIS::StateAttributep(Idx index) {
  return pStates->Attributep(index);
}

// Alphabet()
TEMP const TaEventSet<EventAttr>& THIS::Alphabet(void) const {
  return *pAlphabet;
}

// States()
TEMP const TaStateSet<StateAttr>& THIS::States(void) const {
  return *pStates;
}

// TransRel()
TEMP const typename THIS::ATransSet& THIS::TransRel(void) const {
  return *pTransRel;
}

// TransRel(res)
TEMP void THIS::TransRel(TransSetX1EvX2& res) const { mpTransRel->ReSort(res); }
TEMP void THIS::TransRel(TransSetEvX1X2& res) const { mpTransRel->ReSort(res); }
TEMP void THIS::TransRel(TransSetEvX2X1& res) const { mpTransRel->ReSort(res); }
TEMP void THIS::TransRel(TransSetX2EvX1& res) const { mpTransRel->ReSort(res); }
TEMP void THIS::TransRel(TransSetX2X1Ev& res) const { mpTransRel->ReSort(res); }
TEMP void THIS::TransRel(TransSetX1X2Ev& res) const { mpTransRel->ReSort(res); }


#undef THIS
#undef TEMP
#undef BASE



} // namespace faudes

#endif

