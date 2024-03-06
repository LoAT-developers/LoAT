/** @file tp_tgenerator.h  Timed generator class TtGenerator */

/* 
   Timeplugin for FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2007  Thomas Moor
   Exclusive copyright is granted to Klaus Schmidt

*/


#ifndef FAUDES_TP_TGENERATOR_H
#define FAUDES_TP_TGENERATOR_H

#include "corefaudes.h"
#include "tp_attributes.h"

namespace faudes {



/**
 * Generator with timing extensions. 
 *
 * \section SecTimedAlur Alur's Timed Automata 
 *
 * The TtGenerator implements a timed automaton as 
 * introduced by Alur et al. Thus, a TtGenerator is equipped with a number of clock
 * variables to express conditions on timing, so called time constraints. Each state has a 
 * TimeConstraint called the invariant, which must be satisfied while the generator
 * resides in the respective state. Similarly, each transition has a timeconstraint called the
 * guard, which must be satisfied at the moment in which the transition is executed. Transitions
 * may also reset clock variables.
 *
 *
 * \section SecTimedAlusImplement Implementation
 *
 * The TimedGenerator is derived from the System and requires 
 * adequate attribute parameters that implement the timing constraints. Suitable
 * attribute classes are provided by AttributeTimedState, AttributeTimedTrans and AttributeTimedGlobal
 * which may be used either directly or as base classes for further derivatives.
 * For the event attribute, the TimedGenerator assumes the AttributeCFlags interface. A convenience
 * definition faudes::TimedGenerator is used for a minimal version with the above mentioned attribute parameters.
 *
 *
 * \section TimedGeneratorFileFormat File IO
 *
 * The TtGenerator calsses use the TaGenerator file IO, i.e. the file format is the 
 * same up to timing related  requirements from the attribute parameters. The below
 * example is from the basic version TimedGenerator and represents a simplemachine with a
 * busy cycle of at least 5 and at most 10 time units.
 * @code
 * <Generator name="tc simple machine"> 
 *
 * <Alphabet>
 * "alpha" +C+       "beta"        "mue"         "lambda" +C+      
 * </Alphabet>
 *
 * <States>
 * "idle"        
 * "busy"     <Invariant> "cBusy"   "LT" 10 </Invariant>   
 * "down"
 * </States>
 *
 * <TransRel>
 *
 * "idle"        "alpha"       "busy"    
 * <Timing>
 * <Resets>
 * "cBusy"
 * </Resets>
 * </Timing>
 * 
 * "busy"        "beta"        "idle"        
 * <Timing>
 * <Guard>    
 * "cBusy" "GT" 5
 * </Guard>
 * </Timing>
 *
 * "busy"        "mue"         "down"        
 *
 * "down"        "lambda"      "idle"        
 *
 * </TransRel>
 *
 * <InitStates>   "idle"  </InitStates>
 * <MarkedStates> "idle"  </MarkedStates>
 *
 * <Clocks> "cBusy" </Clocks>
 * 
 * </Generator>
 * @endcode
 * 
 *
 * @ingroup TimedPlugin
 */

template <class GlobalAttr, class StateAttr, class EventAttr, class TransAttr>
class FAUDES_API TtGenerator : public TcGenerator<GlobalAttr, StateAttr, EventAttr, TransAttr> {    
    public:
   /**
    * Constructor
    */
    TtGenerator(void);

   /** 
    * Copy constructor 
    *
    * @param rOtherGen
    */
    TtGenerator(const TtGenerator& rOtherGen);

   /** 
    * Copy constructor (no attributes)
    *
    * @param rOtherGen
    */
    TtGenerator(const vGenerator& rOtherGen);

    /**
     * Assignment operator (uses Assign)
     * Note: you must reimplement this operator in derived 
     * classes in order to handle internal pointers correctly
     *
     * @param rOtherGen
     *   Other generator
     */
    virtual TtGenerator& operator= (const TtGenerator& rOtherGen) {this->Assign(rOtherGen); return *this;};

   /**
    * Construct from file
    *
    * @param rFileName
    *   Name of file
    *
    * @exception Exception
    *   - file format errors (id 1, 50, 51, 52)
    */
    TtGenerator(const std::string& rFileName);

   /**
    * Construct on heap. 
    * Constructs a TtGenerator on heap with the same attribute types and the same event- and clock-symboltable.
    *
    * @return 
    *   new Generator 
    */
    TtGenerator* New(void) const;

   /**
    * Construct copy on heap. 
    * Constructs a TtGenerator on heap with the same attribute types and the same event- and clock-symboltable.
    *
    * @return 
    *   new Generator 
    */
    TtGenerator* Copy(void) const;

    /**
     * Type test.
     * Uses C++ dynamic cast to test whether the specified object
     * casts to a TimedGenerator.
     *
     * @return 
     *   TtGenerator reference if dynamic cast succeeds, else NULL 
     */
     virtual const Type* Cast(const Type* pOther) const {
       return dynamic_cast< const TtGenerator* > (pOther); };


   /**
    * Construct on stack.
    * Constructs a TtGenerator on stack with the same attribute types and the same event- and clock-symboltable.
    *
    * @return 
    *   new Generator 
    */
    TtGenerator NewTGen(void) const;


   /**
    * Get Pointer to mpClockSymbolTable.
    *
    * @return Pointer mpClockSymbolTable
    */
    SymbolTable* ClockSymbolTablep(void) const;

   /**
    * Set ClockSymbolTable.
    *
    * @param pClockSymTab
    *    Pointer SymbolTable
    */
    void ClockSymbolTablep(SymbolTable* pClockSymTab);


   /**
    * Number of clocks in mClocks
    *
    * @return Number of clocks in mClocks
    */
    Idx ClocksSize(void) const;

   /**
    * Get clockset as const reference
    *
    * @return mClocks
    */
    const ClockSet& Clocks(void) const;


   /**
    * Get clockset as pointer
    *
    * @return mClocks
    */
    ClockSet* Clocksp(void);

   /**
    * Overwrites mClocks with newclocks without consistency check
    *
    * @param newclocks
    *    New clocks that are written to mClocks
    */
    void InjectClocks(const ClockSet& newclocks);

   /**
    * Looks up clock name for given index
    *
    * @param index
    *    Clock index
    *
    * @return Clock name
    */
    std::string ClockName(Idx index) const;
    
    /**
    * Looks up clock index for given name
    *
    * @param rName
    *    Clock name
    *
    * @return Clock index or 0 for nonexistent
    */
    Idx ClockIndex(const std::string& rName) const;

    /**
    * Add an existing clock to mClcoks by index
    *
    * @param index
    *   Clock index
    * @return 
    *   True if clock was new to clockset
    */
    bool InsClock(Idx index);
    
    /**
    * Add named clock to generator. An entry in the mpClockSymbolTable will
    * be made if clock is new.
    *
    * @param rName
    *   Name of the clock to add
    *
    * @return 
    *   New unique index
    */
    Idx InsClock(const std::string& rName);
    
    /**
    * Add new named clocks to generator.
    *
    * @param rClockSet
    *   ClockSet
    */
    void InsClocks(const ClockSet& rClockSet);

    /**
    * Delete clock from generator by index. This also removes
    * any constraints and resets that refer to that clock. 
    *
    * @param index
    *   Index of clock
    * @return
    *   True if clock did exist
    *
    */
    bool DelClock(Idx index);
    
    /**
    * Delete clock from generator by name. mpClockSymbolTable stays untouched.
    * Also removes constraints and resets that refer to this clock
    *
    * @param rName
    *    Name of clock
    * @return
    *    True if clock did exist
    */
    bool DelClock(const std::string& rName);
    
    /** 
    * Delete a set of clocks from generator. 
    * 
    * @param rClocks
    *   ClockSet containing clocks to remove
    */
    void DelClocks(const ClockSet& rClocks);
    
   /** 
    * Test existence of clock in mClocks
    *
    * @param index
    *   Clock index
    *
    * @return
    *   true / false
    */
    bool ExistsClock(Idx index) const;

   /** 
    * Test existence of clock in mClock
    *
    * @param rName
    *   Clock name
    *
    * @return
    *   True if clock exists
    */
    bool ExistsClock(const std::string& rName) const;

   /**
    * Returns a niterator to clock index in mClock
    *
    * @param index
    *   Index to find
    *
    * @return
    *   ClockSet::Iterator to clock index
    */
    ClockSet::Iterator FindClock(Idx index) const;

   /**
    * Returns an iterator to clock index in mClock
    *
    * @param rName
    *   Clock name of index to find
    *
    * @return
    *   ClockSet::Iterator to clock index
    */
    ClockSet::Iterator FindClock(const std::string& rName) const;

   /**
    * Returns all clocks used by all TimeConstraints and Resets.
    * Should be a subset of Clocks()
    *
    * @return 
    *   ClockSet containing all clocks 
    */
    ClockSet ActiveClocks(void) const;

   /**
    * Returns all clocks not used by any TimeConstraints or Reset.
    *
    * @return 
    *   ClockSet containing all unused clocks 
    */
    ClockSet InactiveClocks(void) const;

   /**
    * Update Clocks to include all active clocks
    *
    */
    void InsActiveClocks(void);

   /**
    * Update Clocks not to include any inactive clocks
    *
    */
    void DelInactiveClocks(void);

   /**
    * Iterator to Begin() of mClocks
    *
    * @return iterator to begin of mClocks
    */
    ClockSet::Iterator ClocksBegin(void) const;
    
    /**
    * Iterator to End() of mClocks
    *
    * @return iterator to end of mClocks
    */
    ClockSet::Iterator ClocksEnd(void) const;

   /**
    * Throw exception if timeconstraint refers to clocks not
    * in clockset or symboltable mismatch
    *
    * @exception Exception
    *   - invalid cock (id 200)
    */
    void ConsistentTimeConstraint(const TimeConstraint& rTimeConstr) const;

   /**
    * Throw exception if clocksset contains clocks not
    * in generators clockset or symboltable mismatch 
    *
    * @exception Exception
    *   - invalid cock (id 200)
    */
    void ConsistentClocks(const ClockSet& rClocks) const;


    /**
    * Get invariant of state by index
    *
    * @param idx
    *    State index
    * @return  
    *    Const ref to invariant
    */
    const TimeConstraint& Invariant(Idx idx) const;

   /**
    * Get invariant of state by index
    *
    * @param idx
    *    State index
    * @return  
    *    Pointer to invariant
    */
    TimeConstraint* Invariantp(Idx idx);

    /**
    * Get invariant of state by name
    *
    * @param name
    *    State name
    * @return
    *    Const ref to invariant
    */
    const TimeConstraint& Invariant(const std::string& name) const;


   /**
    * Get invariant of state by name
    *
    * @param name
    *    State index
    * @return  
    *    Pointer to invariant
    */
    TimeConstraint* Invariantp(const std::string&  name);

    /**
    * Set invariant of state by index
    *
    * @param index
    *    State index
    * @param rConstraints
    *    New constraints
    */
    void Invariant(Idx index, const TimeConstraint& rConstraints);


    /**
    * Set invariant of state by name
    *
    * @param name
    *    State name
    * @param rConstraints
    *    New constraints
    */
    void Invariant(const std::string& name, const TimeConstraint& rConstraints);


    /**
    * Ins invariant of state by name
    *
    * @param name
    *    State name
    * @param rConstraints
    *    New constraints
    */
    void InsInvariant(const std::string& name, const TimeConstraint& rConstraints);


    /**
    * Ins invariant of state by name
    *
    * @param index
    *    State index
    * @param rConstraints
    *    New constraints
    */
    void InsInvariant(Idx index, const TimeConstraint& rConstraints);


    /**
    * Clear invariant of state by index
    *
    * @param idx
    *    State index
    */
    void ClrInvariant(Idx idx);

    /**
    * Clear invariant of state by name
    *
    * @param name
    *    State name
    */
    void ClrInvariant(const std::string& name);

   /**
    * Clear all invariants
    *
    */
    void ClearInvariants(void);

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
     * Add a transition with attribute to generator. States and event
     * must already exist!
     *
     * Define FAUDES_CHECKED for consistency checks.
     *
     * @param rTransition
     *   transition
     * @param rAttr
     *   attribute
     *
     * @return
     *   True, if the transition was new the generator
     *
     */
    bool SetTransition(const Transition& rTransition, const TransAttr& rAttr);

    /**
    * Inserts new TimedTransition constructed from parameters.
    * Performs consistency checks for x1, x2, ev and all clocks in rguard and rResetClocks.
    *
    * @param rTrans
    *    new transition 
    * @param rGuard
    *    Guard of new TimedTransition.
    * @param rResets
    *    Reset clocks of new TimedTransition.
    * @return
    *   True, if the transition was new the generator
    */
    bool SetTransition(const Transition& rTrans,
      const TimeConstraint& rGuard = TimeConstraint(), const ClockSet& rResets = ClockSet());

    /**
    * Inserts new TimedTransition constructed from parameters.
    * Performs consistency checks for x1, x2, ev and all clocks in rguard and rResetClocks.
    *
    * @param x1
    *    Start state of new TimedTransition.
    * @param ev
    *    Event of new TimedTransition.
    * @param x2
    *    Goal state of new TimedTransition.
    * @param rguard
    *    Guard of new TimedTransition.
    * @param rResetClocks
    *    Reset clocks of new TimedTransition.
    */
    bool SetTransition(Idx x1, Idx ev, Idx x2,
              const TimeConstraint& rguard, const ClockSet& rResetClocks = ClockSet());

    /**
    * Inserts new TimedTransition constructed from parameters.
    * Performs consistency checks for x1, x2, ev and all clocks in rguard and rResetClocks.
    *
    * @param rX1
    *    Start state of new TimedTransition.
    * @param rEv
    *    Event of new TimedTransition.
    * @param rX2
    *    Goal state of new TimedTransition.
    * @param rGuard
    *    Guard of new TimedTransition.
    * @param rResets
    *    Reset clocks of new TimedTransition.
    *
    * @return
    *   True, if the transition was new the generator
    */
    bool SetTransition(const std::string& rX1, const std::string& rEv, const std::string& rX2,
       const TimeConstraint& rGuard = TimeConstraint(), const ClockSet& rResets = ClockSet());


    /**
    * Sets Guard of a transition
    *
    * @param rTrans
    *    transition to manupilate
    * @param rGuard
    *    new Guard of transition.
    */
    void Guard(const Transition& rTrans, const TimeConstraint& rGuard);

    /**
    * adds constraints to Guard of a transition
    *
    * @param rTrans
    *    transition to manupilate
    * @param rConstraints
    *    new constraints for Guard 
    */
    void InsGuard(const Transition& rTrans, const TimeConstraint& rConstraints);

    /**
    * Gets Guard refernce of a transition
    *
    * @param rTrans
    *    transition to inspect
    *
    * @return 
    *    Guard of transition.
    */
    const TimeConstraint&  Guard(const Transition& rTrans) const;

    /**
    * Gets Guard pointer of ransition
    *
    * @param rTrans
    *    transition to inspect
    *
    * @return 
    *    Guard of transition.
    */
    TimeConstraint*  Guardp(const Transition& rTrans);


    /**
    * Clears Guard of a transition
    *
    * @param rTrans
    *    transition to manupilate
    */
    void ClrGuard(const Transition& rTrans);

    /**
    * Sets Resets of a transition
    *
    * @param rTrans
    *    transition to manupilate
    * @param rResets
    *    new Resets of transition.
    */
    void Resets(const Transition& rTrans, const ClockSet& rResets);

    /**
    * adds Resets of a transition
    *
    * @param rTrans
    *    transition to manupilate
    * @param rMoreResets
    *    new Resets of transition.
    */
    void InsResets(const Transition& rTrans, const ClockSet& rMoreResets);

    /**
    * Gets Resets refernce of a transition
    *
    * @param rTrans
    *    transition to inspect
    *
    * @return 
    *    Resets of transition.
    */
    const ClockSet&  Resets(const Transition& rTrans) const;

    /**
    * Gets Resets pointer of ransition
    *
    * @param rTrans
    *    transition to inspect
    *
    * @return 
    *    Resets of transition.
    */
    ClockSet*  Resetsp(const Transition& rTrans);

    /**
    * Clears Resets of a transition
    *
    * @param rTrans
    *    transition to manupilate
    */
    void ClrResets(const Transition& rTrans);

    /**
     * Return pretty printable clock name for index.
     * Primary meant for debugging messages
     *
     * @param index
     *   Event index
     *
     * @return
     *   std::string
     */
    std::string CStr(Idx index) const;

    /** 
     * Check if generator is valid 
     *
     * @return 
     *   Success
     */
    virtual bool Valid(void) const;


    /**
     * Updates internal attributes. As a demo, we set
     * state flag 0x20000000 for blocking states.
     * Reimplement to your needs.
     *
     * @return true if value changed
     */
    virtual bool UpdateAttributes(void);



}; // end class TtGeneraator

    
/** Convenience typedef for std TimedGenerator */
typedef TtGenerator<AttributeTimedGlobal, AttributeTimedState, AttributeCFlags,AttributeTimedTrans> 
  TimedGenerator;

/** Compatibility: pre 2.20b used tGenerator as C++ class name*/
#ifdef FAUDES_COMPATIBILITY
typedef TtGenerator<AttributeTimedGlobal, AttributeTimedState, AttributeCFlags,AttributeTimedTrans> 
  tGenerator;
#endif



// convenient scope macors  
#define THIS TtGenerator<GlobalAttr, StateAttr, EventAttr, TransAttr>
#define BASE TcGenerator<GlobalAttr, StateAttr, EventAttr, TransAttr>
#define TEMP template <class GlobalAttr, class StateAttr, class EventAttr, class TransAttr>


// TtGenerator(void)
TEMP THIS::TtGenerator(void) : BASE() {
  // set basic members (cosmetic)
  BASE::pGlobalAttribute->mClocks.Name("Clocks");
  BASE::pGlobalAttribute->mpClockSymbolTable=ClockSet::GlobalClockSymbolTablep();
  FD_DG("TimedGenerator(" << this << ")::TimedGenerator() with csymtab " 
    << (BASE::pGlobalAttribute->mpClockSymbolTable ));
}

// TtGenerator(rOtherGen)
TEMP THIS::TtGenerator(const TtGenerator& rOtherGen) : BASE(rOtherGen) {
  FD_DG("TimedGenerator(" << this << ")::TimedGenerator(rOtherGen) with csymtab" 
    << (BASE::pGlobalAttribute->mpClockSymbolTable) );
}

// TtGenerator(rOtherGen)
TEMP THIS::TtGenerator(const vGenerator& rOtherGen) : BASE(rOtherGen) {
  // set basic members (cosmetic)
  BASE::pGlobalAttribute->mClocks.Name("Clocks");
  BASE::pGlobalAttribute->mpClockSymbolTable=ClockSet::GlobalClockSymbolTablep();
  FD_DG("TimedGenerator(" << this << ")::TimedGenerator(rOtherGen) with csymtab" 
    << (BASE::pGlobalAttribute->mpClockSymbolTable) );
}

// TtGenerator(rFilename)
TEMP THIS::TtGenerator(const std::string& rFileName) : BASE(rFileName) {
  FD_DG("TimedGenerator(" << this << ")::TimedGenerator(" << rFileName << ") with csymtab" 
    << (BASE::pGlobalAttribute->mpClockSymbolTable) );
}


// ClockSymbolTablep()
TEMP SymbolTable* THIS::ClockSymbolTablep(void) const {
  return BASE::pGlobalAttribute->mpClockSymbolTable;
}

// ClockSymbolTablep(pSymTab)
TEMP void THIS::ClockSymbolTablep(SymbolTable* pSymTab) {
   BASE::Clear(); // TODO: relax this
   BASE::pGlobalAttribute->mpClockSymbolTable=pSymTab;
}


// New
TEMP THIS* THIS::New(void) const {
  // allocate
  THIS* res = new THIS;
  // fix base data
  res->EventSymbolTablep(BASE::mpEventSymbolTable);
  res->mStateNamesEnabled=BASE::mStateNamesEnabled;
  res->mReindexOnWrite=BASE::mReindexOnWrite;  
  // fix my data
  res->ClockSymbolTablep(ClockSymbolTablep());
  return res;
}

// Copy
TEMP THIS* THIS::Copy(void) const {
  // allocate
  THIS* res = new THIS(*this);
  // done
  return res;
}

// NewTGen
TEMP THIS THIS::NewTGen(void) const {
  // call base (fixes by assignment constructor)
  THIS res= BASE::NewCGen();
  // fix my data
  res.ClockSymbolTablep(ClockSymbolTablep());
  return res;
}

// ClockSize() const
TEMP Idx THIS::ClocksSize(void) const {
  return BASE::pGlobalAttribute->mClocks.Size();
}

// Clocks()
TEMP const ClockSet& THIS::Clocks(void) const {
  return BASE::pGlobalAttribute->mClocks;
}

// Clocksp()
TEMP ClockSet* THIS::Clocksp(void) {
  return &BASE::pGlobalAttribute->mClocks;
}

// InjectClocks(set)
TEMP void THIS::InjectClocks(const ClockSet& clockset) {
  BASE::pGlobalAttribute->mClocks=clockset;
  BASE::pGlobalAttribute->mClocks.Name("Clocks");
}

// InsClock(index)
TEMP bool THIS::InsClock(Idx clockindex) {
  return BASE::pGlobalAttribute->mClocks.Insert(clockindex);
}

// InsClock(name)
TEMP Idx THIS::InsClock(const std::string& clockname) {
  return BASE::pGlobalAttribute->mClocks.Insert(clockname);
}

// InsClocks(set)
TEMP void THIS::InsClocks(const ClockSet& clockset) {
  BASE::pGlobalAttribute->mClocks.InsertSet(clockset);
}


// DelClock(index)
TEMP bool THIS::DelClock(Idx clockindex) {
  FD_DG("TimedGenerator(" << this << ")::DelClock(" << clockindex << ")");
  TransSet::Iterator tit;
  for(tit=BASE::TransRelBegin(); tit!=BASE::TransRelEnd(); tit++) {
    if(!BASE::pTransRel->Attribute(*tit).IsDefault()) {
      BASE::pTransRel->Attributep(*tit)->mGuard.EraseByClock(clockindex);
      BASE::pTransRel->Attributep(*tit)->mResets.Erase(clockindex);
    }
  }
  StateSet::Iterator it;
  for(it=BASE::StatesBegin(); it!=BASE::StatesEnd(); it++) { 
    if(!BASE::pStates->Attribute(*it).IsDefault()) {
      BASE::pStates->Attributep(*it)->mInvariant.EraseByClock(clockindex);
    }
  }
  return BASE::pGlobalAttribute->mClocks.Erase(clockindex);
}

// DelClock(name)
TEMP bool THIS::DelClock(const std::string& clockname) {
  Idx index=BASE::pGlobalAttribute->mClocks.Index(clockname);
  return DelClock(index);
}

// DelClocks(set)
TEMP void THIS::DelClocks(const ClockSet& clockset) {
  ClockSet::Iterator it, tmpit;
  for(it=clockset.Begin(); it!=clockset.End(); ) {
    tmpit=it;
    it++;
    DelClock(*tmpit);
  }
}

// ExistsClock(index)
TEMP bool THIS::ExistsClock(Idx clockindex) const {
  return BASE::pGlobalAttribute->mClocks.Exists(clockindex);
}

// ExistsClock(name)
TEMP bool THIS::ExistsClock(
  const std::string& clockname) const {
  return BASE::pGlobalAttribute->mClocks.Exists(clockname);
}

// FindClock(index)
TEMP ClockSet::Iterator THIS::FindClock(Idx clockindex) const {
  return BASE::pGlobalAttribute->mClocks.Find(clockindex);
}

// FindClock(name)
TEMP ClockSet::Iterator THIS::FindClock(const std::string& clockname) const {
  return BASE::pGlobalAttribute->mClocks.Find(clockname);
}

// ClockName(index)
TEMP std::string THIS::ClockName(Idx clockindex) const {
  return BASE::pGlobalAttribute->mClocks.SymbolicName(clockindex);
}

// ClockIndex(name)
TEMP Idx THIS::ClockIndex(const std::string& clockname) const {
  return BASE::pGlobalAttribute->mClocks.Index(clockname);
}

// ActiveClocks() const
TEMP ClockSet THIS::ActiveClocks(void) const {
  FD_DG("TimedGenerator(" << this << ")::ActiveClocks() const");
  ClockSet res;
  TransSet::Iterator tit;
  for(tit=BASE::TransRelBegin(); tit!=BASE::TransRelEnd(); tit++) {
    res.InsertSet(Guard(*tit).ActiveClocks());
    res.InsertSet(Resets(*tit));
  }
  StateSet::Iterator it;
  for(it=BASE::StatesBegin(); it!=BASE::StatesEnd(); it++) { 
    res.InsertSet(Invariant(*it).ActiveClocks());
  }
  res.Name("AcitiveClocks");
  return res;
}

// InactiveClocks() const
TEMP ClockSet THIS::InactiveClocks(void) const {
  FD_DG("TtaGenerator(" << this << ")::InactiveClocks() const");
  ClockSet res =  BASE::pGlobalAttribute->mClocks;
  res.EraseSet(ActiveClocks());
  res.Name("InactiveClocks");
  return res;
}

// InsActiveClocks() 
TEMP void THIS::InsActiveClocks(void) {
  FD_DG("TimedGenerator(" << this << ")::InsActiveClocks()");
  ClockSet aclocks=ActiveClocks();
  InsClocks(aclocks);
}

// DelInactiveClocks() 
TEMP void THIS::DelInactiveClocks(void) {
  FD_DG("TimedGenerator(" << this << ")::InsActiveClocks()");
  ClockSet iaclocks=InactiveClocks();
  BASE::pGlobalAttribute->mClocks.EraseSet(iaclocks);
}

// iterator ClocksBegin() const
TEMP ClockSet::Iterator THIS::ClocksBegin(void) const {
  return BASE::pGlobalAttribute->mClocks.Begin();
}

// iterator ClocksEnd() const
TEMP ClockSet::Iterator THIS::ClocksEnd(void) const {
  return BASE::pGlobalAttribute->mClocks.End();
}

// ConsistentTimeConstraint(constraint)
TEMP void THIS::ConsistentTimeConstraint(const TimeConstraint& rTimeConstr) const {
  FD_DG("TimedGenerator(" << this << ")::ConsistentTimeConstraint(constr)");
  if( rTimeConstr.ClockSymbolTablep() != ClockSymbolTablep()) {
    std::stringstream errstr;
    errstr << "clocksymboltable mismatch" << std::endl;
    throw Exception("TimedGenerator::ConsistentTimeConstraint)", errstr.str(), 200);
  }
  if(!( rTimeConstr.ActiveClocks() <= Clocks() )) {
    std::stringstream errstr;
    errstr << "time constraint refers to clocks not in clockset: " << 
      rTimeConstr.ActiveClocks().ToString() << " versus " << Clocks().ToString() << std::endl;
    throw Exception("TimedGenerator::ConsistentTimeConstraint)", errstr.str(), 200);
  }
  FD_DG("TimedGenerator(" << this << ")::ConsistentTimeConstraint(constr): ok");
}

// ConsistentClocks(clocks)
TEMP void THIS::ConsistentClocks(const ClockSet& rClocks) const {
  if(!( rClocks <= Clocks() )) {
    std::stringstream errstr;
    errstr << "clocksset contains clocks not in clockset" << std::endl;
    throw Exception("TimedGenerator::ConsistentClocks)", errstr.str(), 200);
  }
  if( rClocks.SymbolTablep() != ClockSymbolTablep()) {
    std::stringstream errstr;
    errstr << "clocksymboltable mismatch" << std::endl;
    throw Exception("TimedGenerator::ConsistentClocks)", errstr.str(), 200);
  }
}


// Invariant(index)
TEMP const TimeConstraint& THIS::Invariant(Idx stateindex) const {
  if(!BASE::ExistsState(stateindex)) {
      std::stringstream errstr;
      errstr << "state index " << stateindex << " not found in StateSet" << std::endl;
      throw Exception("TimedGenerator::Invariant", errstr.str(), 200);
  }
  return BASE::pStates->Attribute(stateindex).mInvariant;
}

// Invariantp(index)
TEMP TimeConstraint* THIS::Invariantp(Idx stateindex) {
  if(!BASE::ExistsState(stateindex)) {
      std::stringstream errstr;
      errstr << "state index " << stateindex << " not found in StateSet" << std::endl;
      throw Exception("TimedGenerator::Invariant", errstr.str(), 200);
  }
  return &BASE::pStates->Attributep(stateindex)->mInvariant;
}

// Invariant(name)
TEMP const TimeConstraint& THIS::Invariant(const std::string&  statename) const {
  Idx idx=BASE::StateIndex(statename);
  return Invariant(idx);
}

// Invariantp(name)
TEMP TimeConstraint* THIS::Invariantp(const std::string&  statename) {
  Idx idx=BASE::StateIndex(statename);
  return Invariantp(idx);
}

// Invariant(index,invariant)
TEMP void THIS::Invariant(Idx stateindex, const TimeConstraint& rInv) {
  FD_DG("TimedGenerator(" << this << ")::Invariant("<<stateindex<<",inv)");
#ifdef FAUDES_CHECKED
  ConsistentTimeConstraint(rInv);
  if(!BASE::ExistsState(stateindex)) {
      std::stringstream errstr;
      errstr << "state index " << stateindex << " not found in StateSet" << std::endl;
      throw Exception("TimedGenerator::Invariant", errstr.str(), 200);
  }
#endif
  BASE::pStates->Attributep(stateindex)->mInvariant=rInv;
  BASE::pStates->Attributep(stateindex)->mInvariant.Name("Invariant");
}

// Invariant(name,invariant)
TEMP void THIS::Invariant(const std::string&  statename, const TimeConstraint& rInv) {
  FD_DG("TimedGenerator(" << this << ")::Invariant("<<statename<<",inv)");
  Idx idx=BASE::StateIndex(statename);
  Invariant(idx,rInv);
}

// InsInvariant(index,invariant)
TEMP void THIS::InsInvariant(Idx stateindex, const TimeConstraint& rInv) {
  FD_DG("TimedGenerator(" << this << ")::InsInvariant("<<stateindex<<",inv)");
#ifdef FAUDES_CHECKED
  ConsistentTimeConstraint(rInv);
  if(!BASE::ExistsState(stateindex)) {
      std::stringstream errstr;
      errstr << "state index " << stateindex << " not found in StateSet" << std::endl;
      throw Exception("TimedGenerator::InsInvariant", errstr.str(), 200);
  }
#endif
  if(!rInv.Empty()) {
    BASE::pStates->Attributep(stateindex)->mInvariant.Insert(rInv);
  }
}

// InsInvariant(name,invariant)
TEMP void THIS::InsInvariant(const std::string&  statename, const TimeConstraint& rInv) {
  FD_DG("TimedGenerator(" << this << ")::InsInvariant("<<statename<<",inv)");
  Idx idx=BASE::StateIndex(statename);
  InsInvariant(idx,rInv);
}

// ClrInvariant(index)
TEMP void THIS::ClrInvariant(Idx stateindex) {
  if(!BASE::pStates->Attribute(stateindex).IsDefault()) 
     BASE::pStates->Attributep(stateindex)->mInvariant.Clear();
}

// ClrInvariant(name)
TEMP void THIS::ClrInvariant(const std::string&  statename) {
  Idx idx=BASE::StateIndex(statename);
  ClrInvariant(idx);
}

// ClearInvariants()
TEMP void THIS::ClearInvariants(void) {
  // FIXME: should iterate, there could be other attributes
  BASE::pStates->ClearAttributes(); 
}


// SetTransition(rX1, rEv, rX2)
TEMP bool THIS::SetTransition(const std::string& rX1, const std::string& rEv, const std::string& rX2) {
  return BASE::SetTransition(rX1,rEv,rX2);
}


// SetTransition(x1, ev, x2)
TEMP bool THIS::SetTransition(Idx x1, Idx ev, Idx x2) {
  return BASE::SetTransition(Transition(x1,ev,x2));
}

// SetTransition(rTransition, rAttr)
TEMP bool THIS::SetTransition(const Transition& rTransition, const TransAttr& rAttr) {
  return BASE::SetTransition(rTransition,rAttr);
}

// SetTransition(trans,....)
TEMP bool THIS::SetTransition(const Transition& rTrans,
    const TimeConstraint& rGuard, const ClockSet& rResets) {
  FD_DG("TimedGenerator(" << this << ")::SetTransition(" << (BASE::TStr(rTrans)) <<", " <<
    rGuard.ToString() << ", " << rResets.ToString() << ") const");
  if(rResets.Empty() && rGuard.Empty()) { 
    return BASE::SetTransition(rTrans);
  }
  TransAttr attr;
  attr.mGuard=rGuard;
  attr.mResets=rResets;
  attr.mGuard.Name("Guard");
  attr.mResets.Name("Resets");
#ifdef FAUDES_CHECKED
  ConsistentTimeConstraint(rGuard);
  ConsistentClocks(rResets);
#endif
  return BASE::SetTransition(rTrans,attr);
}

// SetTransition(x1,ev,x2, ...)
TEMP bool THIS::SetTransition(Idx x1, Idx ev, Idx x2,
    const TimeConstraint& rGuard, const ClockSet& rResets) {
  return SetTransition(Transition(x1,ev,x2),rGuard,rResets);
}

// SetTransition(X1,Ev,X2, ...)
TEMP bool THIS::SetTransition(
    const std::string& rX1, const std::string& rEv, const std::string& rX2,
    const TimeConstraint& rGuard, const ClockSet& rResets) {
    FD_DG("TimedGenerator(" << this << ")::SetTransition(" << rX1 << " " << rEv <<" " << rX2 <<
      rGuard.ToString() << ", " << rResets.ToString() << ") const");
  Idx x1=this->StateIndex(rX1); 
  Idx ev=this->EventIndex(rEv);
  Idx x2=this->StateIndex(rX2); 
  bool res=BASE::SetTransition(x1,ev,x2);
  if(rResets.Empty() && rGuard.Empty()) { 
    return res;
  }
  TransAttr attr;
  attr.mResets=rResets;
  attr.mGuard=rGuard;
  attr.mGuard.Name("Guard");
  attr.mResets.Name("Resets");
#ifdef FAUDES_CHECKED
  ConsistentTimeConstraint(rGuard);
  ConsistentClocks(rResets);
#endif
  BASE::TransAttribute(Transition(x1,ev,x2),attr);
  return res;
}

// Guard(trans)
TEMP const TimeConstraint& THIS::Guard(const Transition& rTrans) const {
#ifdef FAUDES_CHECKED
  if(!BASE::ExistsTransition(rTrans)) {
      std::stringstream errstr;
      errstr << "transition " << BASE::TStr(rTrans) << " not found " << std::endl;
      throw Exception("TimedGenerator::Guard(trans)", errstr.str(), 200);
  }
#endif
  return BASE::pTransRel->Attribute(rTrans).mGuard;
}


// Guardp(trans)
TEMP TimeConstraint* THIS::Guardp(const Transition& rTrans) {
#ifdef FAUDES_CHECKED
  if(!BASE::ExistsTransition(rTrans)) {
      std::stringstream errstr;
      errstr << "transition " << BASE::TStr(rTrans) << " not found " << std::endl;
      throw Exception("TimedGenerator::Guardp(trans)", errstr.str(), 200);
  }
#endif
  return &BASE::pTransRel->Attributep(rTrans)->mGuard;
}


// Guard(trans,guard)
TEMP void THIS::Guard(const Transition& rTrans, const TimeConstraint& rGuard) {
#ifdef FAUDES_CHECKED
  ConsistentTimeConstraint(rGuard);
  if(!BASE::ExistsTransition(rTrans)) {
      std::stringstream errstr;
      errstr << "transition " << BASE::TStr(rTrans) << " not found " << std::endl;
      throw Exception("TimedGenerator::Guard(trans,guard)", errstr.str(), 200);
  }
#endif
  BASE::pTransRel->Attributep(rTrans)->mGuard=rGuard;
  BASE::pTransRel->Attributep(rTrans)->mGuard.Name("Guard");
}

// InsGuard(trans,guard)
TEMP void THIS::InsGuard(const Transition& rTrans, const TimeConstraint& rGuard) {
#ifdef FAUDES_CHECKED
  ConsistentTimeConstraint(rGuard);
  if(!BASE::ExistsTransition(rTrans)) {
      std::stringstream errstr;
      errstr << "transition " << BASE::TStr(rTrans) << " not found " << std::endl;
      throw Exception("TimedGenerator::InsGuard(trans,guard)", errstr.str(), 200);
  }
#endif
  if(!rGuard.Empty()) {
    BASE::pTransRel->Attributep(rTrans)->mGuard.Insert(rGuard);
  }
}

// ClrGuard(trans)
TEMP void THIS::ClrGuard(const Transition& rTrans) {
#ifdef FAUDES_CHECKED
  if(!BASE::ExistsTransition(rTrans)) {
      std::stringstream errstr;
      errstr << "transition " << BASE::TStr(rTrans) << " not found " << std::endl;
      throw Exception("TimedGenerator::ClrGuard(trans)", errstr.str(), 200);
  }
#endif
  if(!BASE::pTransRel->Attribute(rTrans).IsDefault()) 
    BASE::pTransRel->Attributep(rTrans)->mGuard.Clear();
}


// Resets(trans)
TEMP const ClockSet& THIS::Resets(const Transition& rTrans) const {
#ifdef FAUDES_CHECKED
  if(!BASE::ExistsTransition(rTrans)) {
      std::stringstream errstr;
      errstr << "transition " << BASE::TStr(rTrans) << " not found " << std::endl;
      throw Exception("TimedGenerator::Resets(trans)", errstr.str(), 200);
  }
#endif
  return BASE::pTransRel->Attribute(rTrans).mResets;
}


// Resetsp(trans)
TEMP ClockSet* THIS::Resetsp(const Transition& rTrans) {
#ifdef FAUDES_CHECKED
  if(!BASE::ExistsTransition(rTrans)) {
      std::stringstream errstr;
      errstr << "transition " << BASE::TStr(rTrans) << " not found " << std::endl;
      throw Exception("TimedGenerator::Resetsp(trans)", errstr.str(), 200);
  }
#endif
  return &BASE::pTransRel->Attributep(rTrans)->mResets;
}


// Resets(trans,guard)
TEMP void THIS::Resets(const Transition& rTrans, const ClockSet& rResets) {
#ifdef FAUDES_CHECKED
  ConsistentClocks(rResets);
  if(!BASE::ExistsTransition(rTrans)) {
      std::stringstream errstr;
      errstr << "transition " << BASE::TStr(rTrans) << " not found " << std::endl;
      throw Exception("TimedGenerator::Resets(trans,guard)", errstr.str(), 200);
  }
#endif
  BASE::pTransRel->Attributep(rTrans)->mResets=rResets;
  BASE::pTransRel->Attributep(rTrans)->mResets.Name("Resets");
}

// InsResets(trans,guard)
TEMP void THIS::InsResets(const Transition& rTrans, const ClockSet& rResets) {
#ifdef FAUDES_CHECKED
  ConsistentClocks(rResets);
  if(!BASE::ExistsTransition(rTrans)) {
      std::stringstream errstr;
      errstr << "transition " << BASE::TStr(rTrans) << " not found " << std::endl;
      throw Exception("TimedGenerator::InsResets(trans,guard)", errstr.str(), 200);
  }
#endif
  if(!rResets.Empty()) {
    BASE::pTransRel->Attributep(rTrans)->mResets.InsertSet(rResets);
  }
}


// ClrResets(trans)
TEMP void THIS::ClrResets(const Transition& rTrans) {
#ifdef FAUDES_CHECKED
  if(!BASE::ExistsTransition(rTrans)) {
      std::stringstream errstr;
      errstr << "transition " << BASE::TStr(rTrans) << " not found " << std::endl;
      throw Exception("TimedGenerator::ClrResets(trans)", errstr.str(), 200);
  }
#endif
  if(!BASE::pTransRel->Attribute(rTrans).IsDefault()) 
    BASE::pTransRel->Attributep(rTrans)->mGuard.Clear();
}


// Valid()
TEMP bool THIS::Valid(void) const {
    FD_DV("TimedGenerator(" << this << ")::Valid()");
    //call base
    if(!BASE::Valid()) return false;
    // check my names
    TransSet::Iterator tit;
    StateSet::Iterator sit;
    for(sit = BASE::StatesBegin(); sit!= BASE::StatesEnd(); ++sit) {
      if(Invariant(*sit).Name()!="Invariant") return false;
    }
    for(tit = BASE::TransRelBegin(); tit!= BASE::TransRelEnd(); ++tit) {
      if(Guard(*tit).Name()!="Guard") return false;
      if(Resets(*tit).Name()!="Resets") return false;
    }
    if(Clocks().Name()!="Clocks") return false;
    // check my clockset
    ClockSet aclocks=ActiveClocks();
    if(!(aclocks <= Clocks())) return false;
    // check all clocksymboltables
    for(sit = BASE::StatesBegin(); sit!= BASE::StatesEnd(); ++sit) {
      if(Invariant(*sit).ClockSymbolTablep()!=ClockSymbolTablep()) return false;
    }
    for(tit = BASE::TransRelBegin(); tit!= BASE::TransRelEnd(); ++tit) {
      if(Guard(*tit).ClockSymbolTablep()!=ClockSymbolTablep()) return false;
      if(Resets(*tit).SymbolTablep()!=ClockSymbolTablep()) return false;
    }
    if(Clocks().SymbolTablep()!=ClockSymbolTablep()) return false;

    return true;
}


// UpdateAttributes()
TEMP bool THIS::UpdateAttributes(void) {
    FD_DG("TimedGenerator(" << this << ")::UpdateAttributes()");

    // debugging example: flag blocking states
    // btw: need efficient methods to set/clr flags by sets
    StateSet blockstates=BASE::BlockingStates();
    StateSet::Iterator sit;
    for(sit=BASE::StatesBegin(); sit!= BASE::StatesEnd(); sit++) {
      StateAttr attr=BASE::StateAttribute(*sit);
      if(blockstates.Exists(*sit)) {
        attr.Set(0x20000000);
      } else {
        attr.Clr(0x20000000);
      }
      BASE::StateAttribute(*sit,attr);
    };

    return true;
}



// CStr(index)
TEMP std::string THIS::CStr(Idx index) const {
  return BASE::pGlobalAttribute->mClocks.Str(index);
}



#undef BASE
#undef THIS
#undef TEMP



} // namespace faudes


#endif

