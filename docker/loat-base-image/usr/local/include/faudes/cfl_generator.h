/** @file cfl_generator.h Class vGenerator */

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
MERCANTABILITY or FITNES FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA */


#ifndef FAUDES_VGENERATOR_H
#define FAUDES_VGENERATOR_H

#include "cfl_definitions.h"
#include "cfl_exception.h"
#include "cfl_types.h"
#include "cfl_symboltable.h"
#include "cfl_indexset.h"
#include "cfl_nameset.h"
#include "cfl_transset.h"
#include "cfl_token.h"
#include "cfl_tokenreader.h"
#include "cfl_tokenwriter.h"

#include <map>
#include <set>
#include <sstream>
#include <cstdlib>
#include <cassert>

namespace faudes {

/**
 * Base class of all FAUDES generators.
 * 
 * \section GeneratorMembers Overview
 *
 * The faudes::vGenerator models the plain five-tupel G = (X, Sigma, Delta, X_0, X_m) to represent
 * the marked language L(G) and closed language L_m(G), respectively. It provides read and write
 * access to core menbers, e.g. methods for inserting/deleting events, states 
 * and transitions. 
 *
 *
 * States, events and transitions in a generator can be addressed in three alternative methods:
 *
 * - by index, involves a search on a sorted set (efficient)
 * - by name, involves two searches on sorted sets (not quite so efficient)
 * - by iterator, involves pointer dereferencing  (very efficient)
 *
 * For read access, const refererences to sets are provided. In order to allow for consistency checks,
 * write access is via generator methods only. When the compiletime option FAUDES_CHECKED is 
 * defined, write methods throw an exception on inconsistent data, eg. setting an initial state
 * that is not an element of the state set, or introducing a transition with an event label that
 * is not in the alphabet. 
 *
 *
 * \section SecEventsVersusStates Events Versus States
 *
 * While both, events and states, are represented by the integer type faudes::Idx, there
 * is a fundamental distinction between both, which stems from the design choice to use generators
 * as a tool to represent formal languages. From this perspective, events are global enteties while states
 * are local to the respective generator. Any two events within libFAUDES are related while states only 
 * compare within a generator. 
 *
 * In consequence, there is global sybmoltable for event name resolution, 
 * while there is one local state symboltable for 
 * each generator. Furthermore, state names are considered cosmetic and hence are optional, while
 * event names are mandatory. 
 *
 * Example: two machines both refer to the event name "alpha" that models the process of passing 
 * a workpiece from one machine to the other. In libFAUDES this is indeed modelled as one event 
 * which is represented by one index. However, both machines may have a state "Idle" which indicates
 * that the respective machine is idle. In libFAUDES the two states are treated locally to the
 * generators and whether or not they have the same index is regarded irrelevant.
 * 
 * The generator class carries a flag to indicate that functions with result type
 * generator shall attach names to the newly created states, based on the state names
 * of the respective arguments. Turning of this feature and avoiding state names alltogether
 * considerably increases libFAUDES performance.
 *
 * \section GeneratorFileFormat File I/O (default format)
 *
 * Generators inherit the standard token IO interface from the libFAUDES general purpose base Type, 
 * so you may use Read and Write functions for generators. The file-format consists of a generator 
 * section that includes one subsection for each core member. It is illustrated by the below example
 * 
 * @code
 * <Generator name="simple machine">
 * % libFAUDES Generator for the simple machine                   
 *
 * <Alphabet>                         
 * alpha beta mue lambda      
 * </Alphabet>
 *
 * <States>                           
 * idle busy down
 * </States>
 *
 * <TransRel>
 * idle  alpha  busy
 * busy  beta   idle
 * busy  mue    down
 * down  lambda idle
 * </TransRel>
 * 
 * <InitStates>
 * idle
 * </InitStates>
 * 
 * <MarkedStates>
 * idle
 * </MarkedStates>
 * </Generator>
 * @endcode
 *
 * Technical Detail: Since symbolic state names are optional, states may alternatively be represented
 * by their index. In order to consitently read a generator from a token stream, the convention
 * was that states are indexed consecutively starting from 1. This convention produces nice and human-readable output. 
 * However, it requires a re-indexing when writing the generator. As of libFAUDES 2.20j, the token format was extended to 
 * allow for explicit symbol table entries in the format "symbolic_state_name#index". Whether or not re-indexing
 * is applied can be configured via ReindexOnWrite(bool). The default is not to re-index. If you want to read your token 
 * stream with libFAUDES pre 2.20j, you must turn re-index on.
 *
 *
 * Technical Detail: The generator name, the alphabet and the state set are optional. The generator
 * name defaults to "generator"; the alphabet and the state set are extracted from the transition relation. 
 * Furthermore, there alternative short labels "A" for "Alphabet", "S" for "States" etc. are accepted.
 * This short format has been introduced in 2.24e and is meant for embedding data concisely into luafaudes scripts.
 * In general, the full format is preferable.
 *
 * @code
 * <Generator>
 * <T>
 * idle  alpha  busy
 * busy  beta   idle
 * busy  mue    down
 * down  lambda idle
 * </T>
 * <I> idle </I>
 * <M> idle </M>
 * </Generator>
 * @endcode
 * 
 * \section GeneratorFileFormatXML File I/O (XML file-format)
 *
 * The alternative file file format prodiced by XWrite() is meant to accomodate
 * for additional attributes attached to states, events and transitions, including e.g.
 * graph data for a graphical representation. It starts with the outer element "Generator" with
 * name attribute (optionally) and type attribute (mandatory).
 *
 *
 * @code
 * <Generator name="simpla machine" ftype="Generator">
 * <Alphabet>                         
 * <Event name="alpha"/>
 * <Event name="beta"/>
 * <Event name="mue"/>
 * <Event name="lambda"/>
 * </Alphabet>
 *
 * <StateSet>                           
 * <State name="idle" id="1">
     <Marked/><Initial/>
   <State/>
 * <State name="busy" id="2"/>
 * <State name="down" id="3"/>
 * </StateSet>
 *
 * <TransitionRelation>
 * <Transition x1="1" event="alphs" x2="2"/>
 * <Transition x1="2" event="beta" x2="2"/>
 * <Transition x1="2" event="mue" x2="3"/>
 * <Transition x1="3" event="lambda" x2="1"/>
 * <TransitionRelation/>
 *
 * </Generator>
 * @endcode
 *
 *
 * \section GeneratorAttributes Attributes
 *
 * libFAUDES generators provide an interface to access so called attributes, ie data that 
 * is optionally attached to individual states, events, transitions, or globally to the generator.
 *
 * The faudes::Generator's interface to attributes is abstract in the sense that a generator 
 * is not aware of the actual type of its attributes. 
 * Instances of the class Generator indeed have trivial attributes that hold no data at all. 
 * To use attributes, you are meant to instantiate objects of the derived class TaGenerator 
 * with template parameters to specify attribute types. Basic algorithms 
 * implemented for plain generators will accept attributed generators as arguments. Such algorithms may 
 * occasionally inspect or set attributes using the abstract interface and C++ dynamic casts. For
 * specialised algorithms that refer to extended generator semantics, we recommend derived 
 * generator classes as argument type.
 *
 *
 * @ingroup GeneratorClasses
 */


class FAUDES_API vGenerator : public Type  {

 public:
    
  /** @name Constructors & Destructor */
  /** @{ doxygen group */

  /**
   * Default constructor
   */
  vGenerator(void);

  /**
   * Copy-constructror
   */
  vGenerator(const vGenerator& rOtherGen);

  /**
   * Construct from file. This constructor
   * effectively uses the DoRead(TokenReader&) function to read.
   *
   * @param rFileName
   *   Name of file
   *
   * @exception Exception
   *   - IO errors (id 1)
   *   - Token mismatch (id 50, 51, 52, 80, 85)
   */
  vGenerator(const std::string& rFileName);

  /**
   * Construct on heap. 
   * Technically not a constructor, this function creates a vGenerator with the
   * same event symboltable. It is the callers responsebilty to delete the object 
   * when no longer needed. Derived classes must reimplement
   * this function to create an object of the same class and the same event 
   * symboltable. 
   *
   * @return 
   *   New vGenerator 
   */
  virtual vGenerator* New(void) const;

  /**
   * Construct copy on heap. 
   * Technically not a constructor, this function creates a vGenerator with the
   * same event symboltable. It is the callers responsebilty to delete the object 
   * when no longer needed. Derived classes must reimplement
   * this function to create an object of the same class and the same event 
   * symboltable. 
   *
   * @return 
   *   New vGenerator 
   */
  virtual vGenerator* Copy(void) const;

  /**
   * Type test.
   * Uses C++ dynamic cast to test whether the specified object
   * casts to a vGenerator.
   *
   * @return 
   *   vGenerator reference if dynamic cast succeeds, else NULL 
   */
  virtual const Type* Cast(const Type* pOther) const;

  /**
   * Destructor 
   */
  virtual ~vGenerator(void);

  /** @} doxygen group */

  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Copy and Assignment */
  /** @{ doxygen group */


  /**
   * Copy from other faudes type.
   * The current implementation tests whether the source
   * object can be casted to a generator and then performs
   * the according assignment. 
   *
   * @param rSrc
   *   Source to copy from.
   */
  virtual vGenerator& Assign(const Type& rSrc); 

  /**
   * Copy from other vGenerator, ignore attributes. 
   *
   * @param rGen
   *   Source to copy from.
   */
  virtual vGenerator& AssignWithoutAttributes(const vGenerator& rGen); 

  /**
   * Destructive copy to other vGenerator. 
   * Copy method with increased performance at the cost of invalidating
   * the source data. If attribute types of source and destination differ,
   * a std copy is invoked.
   * 
   *
   * @param rGen
   *   Destination for copy operation.
   */
  virtual void Move(vGenerator& rGen); 

  /**
   * Assignment operator (uses Assign method)
   *
   * Note: you must reimplement this operator in derived 
   * classes in order to handle internal pointers correctly.
   *
   * @param rOtherGen
   *   Other generator
   */
  virtual vGenerator& operator= (const vGenerator& rOtherGen);

  /**
   * Create another version of this generator.
   * Assembles a copy of this generator, however, with versioned events.
   * The new event names are created by appending an underscore and a specified string.
   * State names and indices as well as any attributes are maintained.
   *
   * @param rVersion
   *   String value to be appended to event names
   * @param rResGen
   *   Resulting versioned generator
   *
   * @exception Exception
   *   - Source must not match destination (id 96)
   */
  virtual void Version(const std::string& rVersion, vGenerator& rResGen) const;

  /**
   * Create another version of this generator.
   * Assembles a copy of this generator, however, with versioned events.
   * The new event names are created by appending an underscore and a numeric index.
   * State names and indices as well as any attributes are maintained.
   *
   * @param version
   *   Numeric value to be appended to event names
   * @param rResGen
   *   Resulting versioned generator
   * @exception Exception
   *   - Source must not match destination (id 96)
   */
  virtual void Version(Idx version, vGenerator& rResGen) const;

  /**
   * Create another version of this generator.
   * Assembles a copy of this generator, however, with versioned events.
   * The new event names are created by replacing all substrings matching
   * a specified string pattern by a replacement string.
   * State names and indices as well as any attributes are maintained.
   *
   * @param rPattern
   *   String value to be replaced in event names
   * @param rReplacement
   *   String value to be inserted in event names in place of rPattern
   * @param rResGen
   *   Resulting versioned generator
   * @exception Exception
   *   - Source must not match destination (id 96)
   */
  virtual void Version(const std::string& rPattern,const std::string& rReplacement, vGenerator& rResGen) const;



  /** @} doxygen group */


  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Basic Maintenance */
  /** @{ doxygen group */


  /** 
   * Set the generator's name 
   *
   * @param rName
   *   Generator name
   */
  void Name(const std::string& rName);

  /** 
   * Get generator's name 
   *
   * @return 
   *   Name of generator
   */
  const std::string& Name(void) const;

 /** 
   * Check if generator is valid. 
   * Performs internal consistency tests, This method is intendend
   * to test generators that have been manipulated by methods without
   * consistency tests, eg InjectAlphabet.
   *
   * @return 
   *   True for success
   */
  virtual bool Valid(void) const;

  /**
   * Clear generator data. 
   * Clears state set, alphabet and transitionrealtion. Behavioural flags
   * eg StateNamesEnabled are maintained.
   */
  virtual void Clear(void);


  /**
   * Clear all states and transitions, maintain alphabet.
   */
  void ClearStates(void);

  /**
   * Get number of events in alphabet
   *
   * @return
   *   Number of events
   */
  Idx AlphabetSize(void) const;

  /** 
   * Get generator size (number of states) 
   * 
   * @return 
   *   Number of states
   */
  Idx Size(void) const;

  /**
   * Get number of transitions
   *
   * @return
   *   Number of transitions
   */
  Idx TransRelSize(void) const;

  /**
   * Get number of initial states
   *
   * @return
   *   Number of initial states
   */
  Idx InitStatesSize(void) const;

  /**
   * Get number of marked states
   *
   * @return
   *   Number of marked states
   */
  Idx MarkedStatesSize(void) const;

  /** 
   * Check if generator is empty (no states)
   *
   * @return 
   *   True if state set is empty
   */
  bool Empty(void) const;

  /**
   * Check if alphabet is Empty
   *
   * @return
   *   True if mpAlphabet is empty
   */
  bool AlphabetEmpty(void) const;

  /**
   * Check if transition relation is empty
   *
   * @return
   *   True if transition relation is empty
   */
  bool TransRelEmpty(void) const;

  /**
   * Check if set of initial states are empty
   *
   * @return
   *   True if mInitStates is empty
   */
  bool InitStatesEmpty(void) const;

  /**
   * Check if set of marked states are empty
   *
   * @return
   *   True if mMarkedStates is empty
   */
  bool MarkedStatesEmpty(void) const;


  /** @} doxygen group */

  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Event Symboltable */
  /** @{ doxygen group */

  /**
   * Get Pointer to EventSymbolTable currently used
   * by this vGenerator. 
   *
   * @return
   *   Pointer to EventSymbolTable
   */
  SymbolTable* EventSymbolTablep(void) const;

  /**
   * Set EventSymbolTable to be used by this vGenerator. 
   * This function sets the reference to the event symboltable. The current implementation
   * in derived classes clears the generator, future versions may implement a re-indexing.
   *
   * @param pSymTab
   *   Pointer to SymbolTable
   */
  virtual void EventSymbolTablep(SymbolTable* pSymTab);

  /**
   * Set EventSymbolTable as given by rOtherGen. 
   * This function sets the reference to the event symboltable. The current implementation
   * clears the generator, future versions may implement a re-indexing.
   *
   * @param rOtherGen
   *   Other generator 
   *   
   */
  virtual void EventSymbolTablep(const vGenerator& rOtherGen);

  /**
   * Create EventSet with generator's EventSymbolTable (on stack).
   *
   * @return
   *   New empty EventSet on stack
   */
  EventSet NewEventSet(void) const;

  /**
   * Create EventSet with generator's EventSymbolTable (on heap). 
   *
   * @return
   *   Pointer to new empty EventSet on heap
   */
  EventSet* NewEventSetp(void) const;

  /**
   * Event index lookup 
   * 
   * @param rName
   *    Name of event to lookup
   *
   * @return 
   *   Valid index or 0 if name unknown to symboltable
   */
  Idx EventIndex(const std::string& rName) const;

  /** 
   * Event name lookup 
   *
   * @param index
   *   Index of event to look up
   *
   * @return 
   *   Name or empty std::string if non-existent
   */
  std::string EventName(Idx index) const;

  /**
   * Set name for existing event
   *
   * Note: since the event symboltable is global, this affect all
   * generators that refer to the specified event.
   *
   * @param index
   *   Event index
   * @param rName
   *   New name
   *
   * @exception Exception
   *   - index not found in EventSymbolMap (id 42)
   *   - name already associated with another index (id 44)
   *   - event does not exist in generator (id 89)
   */
  void EventName(Idx index, const std::string& rName);

  /** 
   * Create a new unique symbolic event name.
   * See also SymbolTable::UniqueSymbol().
   *
   * @param rName
   *   suggestion for new state name
   */
  std::string UniqueEventName(const std::string& rName) const;


  /** 
   * Rename event in this generator.
   * This method renames the specified event. It does so by
   * removing and adding transitions. This does not
   * effect other generators. 
   *
   * @param event
   *   Event to rename
   * @param rNewName
   *   New name
   * @return
   *   True, if the new name did already exist
   *
   * @exception Exception
   *   - specified event does not exist (id 89)
   */
  bool EventRename(Idx event, const std::string& rNewName);


  /** 
   * Rename event in this generator.
   * Convenience wrapper for EventRename(Idx, const std::string&).
   *
   * @param rOldName
   *   Event to rename
   * @param rNewName
   *   New name
   * @return
   *   True, if the new name did already exist
   *
   * @exception Exception
   *   - specified event does not exist (id 89)
   */
  bool EventRename(const std::string& rOldName, const std::string& rNewName);


  /** @} doxygen group */

  /* statics outside doxygen group */

  /**
   * Get Pointer to global EventSymbolTable. This is
   * a static member of SymbolTable and used as default
   * for all derived generator classes and instantiated objects.
   *
   * @return
   *   Pointer to global EventSymbolTable
   */
  static SymbolTable* GlobalEventSymbolTablep(void);


  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name State Symboltable */
  /** @{ doxygen group */


  /**
   * Get StateSymbolTable. 
   *
   * @return
   *   ref to state-symboltable
   */
  const SymbolTable& StateSymbolTable(void) const;

  /**
   * Set StateSymbolTable.
   *
   * By convention, state names and indices are local to the
   * respective generator. It is most unlikely that you want to use
   * this function.
   *
   * @return
   *   Pointer to mpStateSymbolTable
   */
  void StateSymbolTable(const SymbolTable& rSymTab);

  /**
   * State index lookup. 
   *
   * @param rName
   *
   * @return
   *  Valid index (or 0 for non-existent)
   */
  Idx StateIndex(const std::string& rName) const;

  /** 
   * State name lookup 
   *
   * @param index
   *
   * @return name (or empty string if no such exists) 
   */
  std::string StateName(Idx index) const;

  /** 
   * Set name of state
   *
   * @param index
   *   Index
   * @param rName
   *   Name
   *
   * @exception Exception
   *   - name already associated with another index (id 44)
   *   - state does not exist in generator (id 90)
   */
  void StateName(Idx index, const std::string& rName);

  /**
   * Remove all names from generator's StateSymbolTable
   */
  void ClearStateNames(void);

  /**
   * Clear name for individual state
   *
   * @param index
   *   State index
   * @exception Exception
   *   - state does not exist in generator (id 90)
   */
  void ClrStateName(Idx index);

  /**
   * Clear name for individual  state
   *
   * @param rName
   *   State name
   */
  void ClrStateName(const std::string& rName);

  /**
   * Whether libFAUEDS functions are requested to generate state names.
   * Most libFAUDES functions that introduce new states to a generator can be enabled
   * to also assign (more or less sensible) names to those states. This feature is
   * purely cosmetic and may be disabled for performance reasons. 
   * 
   *
   * @return
   *   True, if generation of statenames is enabled.
   */
  bool StateNamesEnabled(void) const;

  /**
   * Enable/disable libFAUEDS functions to automatically generate state names.
   * Disabling state name generation implies ClearStateNames().
   *
   * @param flag
   *   True enables statenames / false disables them
   */
  void StateNamesEnabled(bool flag);

  /**
   * Assign each state a default name based on its index.
   */
  void SetDefaultStateNames(void);

  /**
   * For all states without a symbolic name, assign a name 
   * based on suggested template and the index.
   *
   * @param rTemplate
   *   Basis for name generation
   */
  void EnforceStateNames(const std::string& rTemplate);

  /** 
   * Create a new unique symbolic state name.
   * See also SymbolTable::UniqueSymbol().
   *
   * @param rName
   *   suggestion for new state name
   */
  std::string UniqueStateName(const std::string& rName) const;


  /** @} doxygen group */

  /* statics outside doxygen group */

  /**
   * Sets the default for automatic state name generation.
   * This flag takes effect only on generators newly created by the default
   * constructor. The copy constructor copies the state name flag from the 
   * source generator. See also StateNamesEnabled(bool).
   *
   * @param flag
   *   True enables statenames / false disables them
   */
  static void StateNamesEnabledDefault(bool flag);


  /*****************************************
   *****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Read Access to Core Members */
  /** @{ doxygen group */

  /**
   * Iterator to Begin() of alphabet
   *
   * @return
   *   Iterator to begin of mpAlphabet
   */
  EventSet::Iterator AlphabetBegin(void) const;

  /**
   * Iterator to End() of alphabet
   *
   * @return
   *   Iterator to end of mpAlphabet
   */
  EventSet::Iterator AlphabetEnd(void) const;

  /** 
   * Test existence of event in alphabet
   *
   * @param index
   *   Event index
   *
   * @return
   *   True / false
   */
  bool ExistsEvent(Idx index) const;

  /** 
   * Test existence of event in alphabet
   *
   * @param rName
   *   Event name
   *
   * @return
   *   True / false
   */
  bool ExistsEvent(const std::string& rName) const;

  /**
   * Returns a iterator to event index in alphabet
   *
   * @param index
   *   Index to find
   *
   * @return
   *   Iterator to event index
   */
  EventSet::Iterator FindEvent(Idx index) const;

  /**
   * Returns a iterator to event index in alphabet
   *
   * @param rName
   *   Event name of index to find
   *
   * @return
   *   Iterator to event index
   */
  EventSet::Iterator FindEvent(const std::string& rName) const;

  /**
   * Return const reference to alphabet 
   *
   * @return EventSet
   *   Reference to mpAlphabet
   */
  const EventSet& Alphabet(void) const;

  /**
   * Iterator to Begin() of state set
   *
   * @return
   *   Iterator to begin of state set
   */
  StateSet::Iterator StatesBegin(void) const;

  /**
   * Iterator to End() of state set
   *
   * @return
   *   Iterator to end of state set
   */
  StateSet::Iterator StatesEnd(void) const;

  /**
   * Test existence of state in state set
   * 
   * @param index
   *   State index
   *
   * @return
   *   true / false
   */
  bool ExistsState(Idx index) const;

  /**
   * Test existence of state in state set
   * 
   * @param name
   *   State name
   *
   * @return
   *   true / false
   */
  bool ExistsState(const std::string& name) const;

  /**
   * Returns a iterator to state index in state set 
   *
   * @param index
   *   Index to find
   *
   * @return
   *   StateSet::Iterator to state index
   */
  StateSet::Iterator FindState(Idx index) const;

  /**
   * Returns a iterator to state with specified name
   *
   * @param rName
   *   name of state to find
   *
   * @return
   *   StateSet::Iterator to state 
   */
  StateSet::Iterator FindState(const std::string& rName) const;


  /**
   * Return reference to state set
   *
   * @return 
   *   StateSet reference incl actual attribute type
   */
  const StateSet& States(void) const;

  /**
   * Return initial state 
   * 
   * If the initial state is not unique, this function
   * returns 0.
   *
   * @return
   *   Index of initial state
   *
   */
  Idx InitState(void) const;

  /**
   * Iterator to Begin() of mInitStates
   *
   * @return
   *   Iterator to begin of mInitStates
   */
  StateSet::Iterator InitStatesBegin(void) const;

  /**
   * Iterator to End() of mInitStates
   * 
   * @returns
   *   Iterator to end of mInitStates
   */
  StateSet::Iterator InitStatesEnd(void) const;

  /**
   * Test existence of state in mInitStates
   * 
   * @param index
   *   State index
   *
   * @return
   *   true / false
   */
  bool ExistsInitState(Idx index) const;

  /**
   * Iterator to state index in mInitStates 
   *
   * @param index
   *   Index to find
   *
   * @return
   *   StateSet::Iterator to state index
   */
  StateSet::Iterator FindInitState(Idx index) const;

  /**
   * Const ref to initial states
   *
   * @return StateSet
   */
  const StateSet& InitStates(void) const;

  /**
   * Iterator to Begin() of mMarkedStates
   *
   * @returns
   *   iterator to Begin of mMarkedStates
   */
  StateSet::Iterator MarkedStatesBegin(void) const;

  /**
   * Iterator to End() of mMarkedStates
   * 
   * @returns
   *   iterator to End of mMarkedStates
   */
  StateSet::Iterator MarkedStatesEnd(void) const;

  /**
   * Test existence of state in mMarkedStates
   * 
   * @param index
   *   State index
   *
   * @return
   *   true / false
   */
  bool ExistsMarkedState(Idx index) const;

  /**
   * Returns a iterator to state index in mMarkedStates
   *
   * @param index
   *   Index to find
   *
   * @return
   *   StateSet::Iterator to state index
   */
  StateSet::Iterator FindMarkedState(Idx index) const;

  /**
   * Return const ref of marked states
   *
   * @return StateSet
   */
  const StateSet& MarkedStates(void) const;

  /**
   * Iterator to Begin() of transition relation
   *
   * @return
   *   Iterator to Begin of mpTransRel
   */
  TransSet::Iterator TransRelBegin(void) const;

  /**
   * Iterator to End() of transition relation
   * 
   * @return
   *   Iterator to End of mpTransRel
   */
  TransSet::Iterator TransRelEnd(void) const;

  /**
   * Iterator to begin of transitions with x1 as predecessor state.
   *
   * @param x1
   *   Predecessor state
   *
   * @return
   *   iterator to begin of transitions with x1
   */
  TransSet::Iterator TransRelBegin(Idx x1) const;

  /**
   * iterator to end of transitions with x1 as predecessor state. 
   *
   * Note: Set the End(x1) iterator to a variable, so it won't be 
   * recalculated every iteration.
   *
   * @param x1
   *   Predecessor state
   *
   * @return 
   *   iterator to end of transitions with x1 
   *   (one after last matching transition)
   */
  TransSet::Iterator TransRelEnd(Idx x1) const;

  /**
   * iterator to begin of transitions with x1 as predecessor state and
   * event ev. 
   *
   * @param x1
   *   Predecessor state
   * @param ev
   *   Event
   *
   * @return
   *   iterator to begin of transitions with x1 and ev
   */
  TransSet::Iterator TransRelBegin(Idx x1, Idx ev) const;

  /**
   * Iterator to end of transitions with x1 as predecessor state and
   * event ev.
   *
   * Note: Set the End(x1,ev) iterator to a variable, so it won't be 
   * recalculated every iteration.
   * 
   * @param x1
   *   Predecessor state
   * @param ev
   *   Event
   *
   * @return
   *   iterator to end of transitions with x1 and ev 
   *   (one after last matching transition)
   */
  TransSet::Iterator TransRelEnd(Idx x1, Idx ev) const;

  /**
   * iterator to transition given by x1, ev, x2
   *
   * 
   * @param rX1
   *   name of Predecessor state
   * @param rEv
   *   name of Event
   * @param rX2
   *   name of Successor state
   *
   * @return
   *   iterator to transition or end() if not exists
   */
  TransSet::Iterator FindTransition(
    const std::string& rX1, const std::string& rEv, const std::string& rX2) const;

  /**
   * Iterator to transition given by x1, ev, x2
   *
   * 
   * @param x1
   *   Predecessor state
   * @param ev
   *   Event
   * @param x2
   *   Successor state
   *
   * @return
   *   iterator to transition or End() if not exists
   */
  TransSet::Iterator FindTransition(Idx x1, Idx ev, Idx x2) const;

  /**
   * Iterator to transition 
   *
   * 
   * @param rTrans
   *   transition
   *
   * @return
   *   iterator to transition or end() if not exists
   */
  TransSet::Iterator FindTransition(const Transition& rTrans) const;

  /**
   * Test for transition given by x1, ev, x2
   *
   * 
   * @param rX1
   *   name of Predecessor state
   * @param rEv
   *   name of Event
   * @param rX2
   *   name of Successor state
   *
   * @return
   *   true / false
   */
  bool ExistsTransition(
    const std::string& rX1, const std::string& rEv, const std::string& rX2) const;

  /**
   * Test for transition given by x1, ev, x2
   * 
   * @param x1
   *   Predecessor state
   * @param ev
   *   Event
   * @param x2
   *   Successor state
   *
   * @return
   *   true / false
   */
  bool ExistsTransition(Idx x1, Idx ev, Idx x2) const;

  /**
   * test for transition 
   *
   * 
   * @param rTrans
   *   transition
   *
   * @return
   *   true / false
   */
  bool ExistsTransition(const Transition& rTrans) const;

  /**
   * Test for transition given by x1, ev
   * 
   * @param x1
   *   Predecessor state
   * @param ev
   *   Event
   *
   * @return
   *   true / false
   */
  bool ExistsTransition(Idx x1, Idx ev) const;

  /**
   * Test for transition given by x1
   * 
   * @param x1
   *   Predecessor state
   *
   * @return
   *   true / false
   */
  bool ExistsTransition(Idx x1) const;

  /**
   * Return reference to transition relation
   *
   * @return TransRel
   */
  const TransSet& TransRel(void) const;

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

  /**
   * Convebience function.
   * 
   * @param rX1
   *   Name of Predecessor state
   * @param rEv
   *   Name of Event
   * @param rX2
   *   Name of Successor state
   *
   * @return
   *   Transition as specified.
   */
  Transition TransitionByNames(
    const std::string& rX1, const std::string& rEv, const std::string& rX2) const;

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
   * Add new named events to generator.
   * If the event allready exists, the attribute is maintained.
   *
   * @param events
   *   EventSet
   */
  void InsEvents(const EventSet& events);

  /**
   * Delete event from generator by index. mpEventSymbolTable stays untouched.
   * Transitions containing event will be removed too.
   *
   * @param index
   *   Index of event
   * @return
   *   True, if event was in alphabet
   *
   */
  bool DelEvent(Idx index);

  /**
   * Delete event from generator by name. mpEventSymbolTable stays untouched.
   * Transitions containing event will be removed too.
   *
   * @param rName
   *    Name of event
   * @return
   *   True, if event was in alphabet
   *
   */
  bool DelEvent(const std::string& rName);

  /** 
   * Delete a set of events from generator. mpEventSymbolTable stays untouched.
   * Transitions containing events will be removed too.
   * 
   * @param rEvents
   *   EventSet containing events to remove
   */
  void DelEvents(const EventSet& rEvents);

  /** 
   * Delete event from alphabet without consistency check. The event is only
   * deleted from mpAlphabet but not from transition relation.
   *
   * @param index
   *   Index of event
   * @return
   *   True, if event was in alphabet
   *
   */
  bool DelEventFromAlphabet(Idx index);

  /**
   * Set mpAlphabet without consistency check.
   * Sets the alphabet incl attributes, if provided.
   *
   * @param rNewalphabet
   *   EventSet with new alphabet
   */
  void InjectAlphabet(const EventSet& rNewalphabet);

  /**
   * Restricts mpAlphabet incl removing resp. transition.
   * Maintains attributes if any.
   *
   * Note: before libFAUDES 2.23, this method did not remove
   * transitions. Use InjectAlphabet(const EventSet&) for direct
   * write acces to the alphabet.
   *
   * @param rNewalphabet
   *   EventSet with alphabet
   */
  void RestrictAlphabet(const EventSet& rNewalphabet);

  /** 
   * Add new anonymous state to generator 
   * 
   * @return 
   *   Index of new unique state
   */
  Idx InsState(void);

  /** 
   * Add (perhaps new) state to generator 
   * 
   * @return 
   *   True to indicate that state was new to generator
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
   * Add anonymous states to generator 
   * 
   * @param rStates
   *   Set of states to add
   */
  void InsStates(const StateSet& rStates);

  /** 
   * Delete a state from generator by index. 
   * Cleans mpStates, mInitStates, mMarkedStates, mpTransRel and mpStateSymbolTable.
   *
   * @param index
   *   Index of state to delete. 
   * @return
   *   True, if state was in stateset
   */
  bool DelState(Idx index);

  /** 
   * Delete a state from generator by name.
   * Cleans mpStates, mInitStates, mMarkedStates, mpTransRel and mpStateSymbolTable.
   *
   * @param rName
   *   Name of state to delete. Will be erased in mpStateSymbolTable too
   * @return
   *   True, if state was in stateset
   *
   * @exception Exception
   *   - Symbolic name not known (id 90)
   */
  bool DelState(const std::string& rName);

  /**
   * Delete a set of states 
   * Cleans mpStates, mInitStates, mMarkedStates, mpTransrel, and mpStateSymboltable
   *
   * @param rDelStates
   *   StateSet containing states aka indicees to delete
   */
  void DelStates(const StateSet& rDelStates);


  /**
   * Delete a state from generator without consistency check. This removes the
   * state from mpStates and mpStateSymbolTable but doesn't touch mpTransRel,
   * mInitStates and mMarkedStates.
   *
   * @param index
   *   Index of state to delete. 
   * @return
   *   True, if state was in stateset
   *
   */
  bool DelStateFromStates(Idx index);

  /**
   * Delete a state from generator without consistency check. This removes the
   * state from mpStates and mpStateSymbolTable but doesn't touch mpTransRel,
   * mInitStates and mMarkedStates.
   * Index to delete is given by iterator. 
   *
   * @param pos
   *   StateSet::Iterator
   * @return
   *   Iteraror to next state
   */
  StateSet::Iterator DelStateFromStates(StateSet::Iterator pos);

  /**
   * Restrict states 
   * Cleans mpStates, mInitStates, mMarkedStates, mpTransrel, and mpStateSymboltable
   *
   * @param rStates
   *   StateSet containing valid states
   */
  void RestrictStates(const StateSet& rStates);


  /** 
   * Inject an existing state index into generators mStates
   * Use with care! For use in performance optimized functions.
   *
   * @param index
   *   State index to inject
   */
  void InjectState(Idx index);

  /**
   * Inject a complete state set without consistency checks (without attributes)
   *
   * @param rNewStates
   *    StateSet
   */
  void InjectStates(const StateSet& rNewStates);


  /**
   * Create new anonymous state and set as initial state
   *
   * @return 
   *   Index of new unique
   */
  Idx InsInitState(void);

  /** 
   * Add (perhaps new) state to generator and turn it
   * into a initial state. 
   * 
   * @param index
   *   State to insert
   * @return 
   *   True to indicate that state was new to generator
   */
  bool InsInitState(Idx index);

  /**
   * Create a new named state and set as initial state
   *
   * @param rName
   *   Name of the state to add
   *
   * @return 
   *   Index of new unique state
   */
  Idx InsInitState(const std::string& rName);

  /** 
   * Add (perhaps new) anonymous initial states to generator  
   * 
   * @param rStates
   *   Set of states to add
   */
  void InsInitStates(const StateSet& rStates);

  /**
   * Create new anonymous state and set as marked state
   *
   * @return 
   *   Index of new unique state
   */
  Idx InsMarkedState(void);

  /** 
   * Add (perhaps new) state to generator and turn it
   * into a marked state. 
   * 
   * @param index
   *   State to insert
   * @return 
   *   True to indicate that state was new to generator
   */
  bool InsMarkedState(Idx index);

  /**
   * Create a new named state and set as marked state
   *
   * @param rName
   *   Name of the state to add
   *
   * @return 
   *   Index of new unique state
   */
  Idx InsMarkedState(const std::string& rName);

  /** 
   * Add (perhaps new) anonymous initial states to generator  
   * 
   * @param rStates
   *   Set of states to add
   */
  void InsMarkedStates(const StateSet& rStates);

  /**
   * Set an existing state as initial state by index.
   *
   * @param index
   *   Index of state to set as initial state
   * @exception Exception
   *   - State index not found in generator (id 91)
   */
  void SetInitState(Idx index);

  /**
   * Set an existing state as initial state by name. 
   *
   * @param rName
   *   Name of state to set as initial state
   *
   * @exception Exception
   *   - State name not known in generator (id 90)
   */
  void SetInitState(const std::string& rName);

  /**
   * Replace mInitStates with StateSet given as parameter without consistency checks.
   *
   * @param rNewInitStates
   *   StateSet containing new mInitStates
   */
  void InjectInitStates(const StateSet& rNewInitStates);

  /**
   * Unset an existing state as initial state by index
   *
   * Define FAUDES_CHECKED for consistency checks.
   *
   * @param index
   *   State index
   *
   * @exception Exception
   *   - State index not found in generator (id 91)
   */
  void ClrInitState(Idx index);

  /**
   * Unset an existing state as initial state by name 
   *
   * @param rName
   *   State name
   *
   * @exception Exception
   *   - State name not known in generator (id 90)
   */
  void ClrInitState(const std::string& rName);

  /**
   * Unset an existing state as initial state by iterator
   *
   * @param pos
   *   StateSet::iterator
   * @return 
   *   Iterator to next init state
   */
  StateSet::Iterator ClrInitState(StateSet::Iterator pos);

  /**
   * Clear all mInitStates
   */
  void ClearInitStates(void); 

  /**
   * Set an existing state as marked state by index
   *
   * @param index
   *   Index of state to set as initial state
   * @exception Exception
   *   - State index not found in generator (id 91)
   */
  void SetMarkedState(Idx index);

  /**
   * Set an existing state as marked state by name. 
   *
   * @param rName
   *   Name of state to set as marked state
   *
   * @exception Exception
   *   - State name not known in generator (id 90)
   */
  void SetMarkedState(const std::string& rName);

  /**
   * Unset an existing state as marked state by index
   *
   * @param index
   *   State index
   *
   * @exception Exception
   *   - State index not found in generator (id 91)
   */
  void ClrMarkedState(Idx index);

  /**
   * Unset an existing state as marked state by name
   *
   * @param rName
   *   State name
   *
   * @exception Exception
   *   - State index not found in generator (id 91)
   */
   void ClrMarkedState(const std::string& rName);

  /**
   * Unset an existing state as marked state by iterator
   *
   * @param pos
   *   StateSet::iterator
   * @return 
   *   Iterator to next marked state
   */
  StateSet::Iterator ClrMarkedState(StateSet::Iterator pos);

  /**
   * Clear all marked states
   */
  void ClearMarkedStates(void);

  /**
   * Replace mMarkedStates with StateSet given as parameter without consistency checks.
   *
   * @param rNewMarkedStates
   *   StateSet containing new marked states
   */
  void InjectMarkedStates(const StateSet& rNewMarkedStates);

  /** 
   * Add a transition to generator by indices. States and event
   * must already exist.
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
   * must already exist.
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
   * must already exist.
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
   * Remove a transition by indices
   *
   * @param x1
   *   Predecessor state index
   * @param ev
   *   Event index
   * @param x2
   *   Successor state index
   */
  void ClrTransition(Idx x1, Idx ev, Idx x2);

  /**
   * Remove a transition by transition object
   *
   * @param rTrans
   *   Transition object
   */
  void ClrTransition(const Transition& rTrans);

  /**
   * Remove a transition by iterator
   *
   * @param it
   *   TransSet::iterator 
   * @return
   *   Iterator to next transition
   */
  TransSet::Iterator ClrTransition(TransSet::Iterator it);

  /**
   * Remove a transitions by state and event
   *
   * @param x1
   *   Predecessor state index
   * @param ev
   *   Event index
   */
  void ClrTransitions(Idx x1, Idx ev);

  /**
   * Remove a transitions by state
   *
   * @param x1
   *   Predecessor state index
   */
  void ClrTransitions(Idx x1);

  /**
   * Clear all transitions
   */
  void ClearTransRel(void);

  /**
   * Set transition without consistency check.
   *
   * @param rTrans
   *   Transition to insert
   */
  void InjectTransition(const Transition& rTrans);

  /**
   * Set transition relation without consistency check (no attributes)
   *
   * @param rNewtransrel
   *   TransRel to insert
   */
  void InjectTransRel(const TransSet& rNewtransrel);

  /** @} doxygen group */



  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Attributes */
  /** @{ doxygen group */


  /**
   * Clear Attributes
   */
  virtual void ClearAttributes(void);

  /**
   * Updates internal attributes. 
   * This method does nothing and may be reimplemented 
   * by a any class that adds semantics to attributes
   * Eg. you may set a particular state flag, if this state 
   * is reachable.
   * 
   * @return True if value changed
   */
  virtual bool UpdateAttributes(void) {return false;};

  /**
   * Clear event attributes
   */
  virtual void ClearEventAttributes(void);

  /**
   * Clear attribute for existing event
   *
   * @param index
   *   Event index
   */
  virtual void ClrEventAttribute(Idx index);

  /**
   * Set attribute for existing event. 
   * This version uses a dynamic cast
   * to test the actual type of the provided attribute. An exception is
   * thrown for an invalid attribute type. 
   * In a context where
   * the attribute type is known, you may prefer the TaGenerator method.
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
   virtual void EventAttribute(Idx index, const Type& rAttr);

  /**
   * Set attributes for existing events. 
   * This version uses a dynamic cast
   * to test the actual type of the provided attributes. An exception is
   * thrown for an invalid attribute type. 
   *
   * @param rEventSet
   *   Set of attributed events
   * @exception Exception
   *   - Element not found in alphabet (id 60)
   *   - Cannot cast attribute (id 63)
   */
   virtual void EventAttributes(const EventSet& rEventSet);

  /** 
   * Event attribute lookup. 
   * In a context where
   * the attribute type is known, you may prefer the TaGenerator method.
   *
   * @param index
   *
   * @return 
   *   reference to attribute
   */
  virtual const AttributeVoid& EventAttribute(Idx index) const;

  /** 
   * Event attribute lookup. 
   * In a context where the attribute type is known, 
   * you may prefer the TaGenerator method.
   *
   * @param rName
   *
   * @return 
   *   reference to attribute
   */
  virtual const AttributeVoid& EventAttribute(const std::string& rName) const;

  /** 
   * Event attribute pointer to access Attribute methods.
   * If there are no attributes (plain vGenerator) this method
   * returs 0. If there are attributes, an explicit default value
   * may be inserted. 
   * In a context where the attribute type is known, 
   * you may prefer the TaGenerator method.
   *
   * @param index
   *
   * @return 
   *   pointer to attribute
   */
  virtual AttributeVoid* EventAttributep(Idx index);

  /** 
   * Event attribute pointer to access Attribute methods.
   * If there are no attributes (plain vGenerator) this method
   * returs 0. If there are attributes, an explicit default value
   * may be inserted. 
   * In a context where the attribute type is known, 
   * you may prefer the TaGenerator method.
   *
   * @param rName
   *
   * @return 
   *   pointer to attribute
   */
  virtual AttributeVoid* EventAttributep(const std::string& rName);


  /**
   * Clear state attributes
   */
  virtual void ClearStateAttributes(void);

  /**
   * Clear attribute for existing state
   *
   * @param index
   *   State index
   */
  virtual void ClrStateAttribute(Idx index);

  /**
   * Set attribute for existing state. 
   * This version uses a dynamic cast
   * to test the actual type of the provided attribute. An exception is
   * thrown for an invalid attribute type. 
   * In a context where
   * the attribute type is known, you may prefer the TaGenerator method.
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
  virtual void StateAttribute(Idx index, const Type& rAttr);

  /** 
   * State attribute lookup. 
   * In a context where the attribute type is known, 
   * you may prefer the TaGenerator method.
   *
   * @param index
   *   State index
   *
   * @return Ref to attribute of state
   */
  virtual const AttributeVoid& StateAttribute(Idx index) const;

  /** 
   * State attribute pointer to access Attribute methods.
   * If there are no attributes (plain vGenerator) this method
   * returns 0. If there are attributes, an explicit default value
   * may be inserted. 
   * In a context where the attribute type is known, 
   * you may prefer the TaGenerator method.
   *
   * @param index
   *   State index
   *
   * @return Pointer to attribute of state
   */
  virtual AttributeVoid* StateAttributep(Idx index);

  /**
   * Clear transition attributes
   */
  virtual void ClearTransAttributes(void);

  /**
   * Set attribute for existing transition.
   * This version uses a dynamic cast
   * to test the actual type of the provided attribute. An exception is
   * thrown for an invalid attribute type. 
   * In a context where
   * the attribute type is known, you may prefer the TaGenerator method.
   *
   * @param rTrans
   *   Transition
   * @param rAttr
   *   New attribute
   *
   * @exception Exception
   *   - Transition not found in transition relation(id 60)
   *   - Cannot cast attribute (id 63)
   */
   virtual void TransAttribute(const Transition& rTrans, const Type& rAttr);


  /**
   * Clear attribute for existing transition
   *
   * @param rTrans
   *   transition
   */
  virtual void ClrTransAttribute(const Transition& rTrans);

  /**
   * Transition attribute lookup.
   * In a context where the attribute type is known, 
   * you may prefer the TaGenerator method.
   *
   * @return 
   *   Attribute
   *
   */
  virtual const AttributeVoid& TransAttribute(const Transition& rTrans) const;

  /**
   * Transition attribute pointer to access Attribute methods.
   * If there are no attributes (plain vGenerator) this method
   * returns 0. If there are attributes, an explicit default value
   * may be inserted. 
   * In a context where the attribute type is known, 
   * you may prefer the TaGenerator method.
   *
   * @return 
   *   Attribute pointer
   *
   */
  virtual AttributeVoid* TransAttributep(const Transition& rTrans);

  /**
   * Clear global attribute
   */
  virtual void ClearGlobalAttribute(void);

  /** 
   * Set global attribute. 
   * The vGenerator does not have attributes, so this function throws an exception for
   * any specified attribute different to AttributeVoid.
   * The TaGenarator provides a re-implementation to actually set the global attribute.
   *
   * @param rAttr
   *   Attribute
   * @exception Exception
   *   - Cannot cast attribute (id 63)
   */
  virtual void GlobalAttribute(const Type& rAttr);

  /** 
   * Set global attribute. 
   * The vGenerator does not have attributes, so this function does nothing.
   * The TaGenarator provides a re-implementation to actually set the global attribute.
   *
   * @param rAttr
   *   Attribute
   */
  virtual void GlobalAttributeTry(const Type& rAttr);

  /** 
   * Global attribute lookup.
   * In a context where the attribute type is known, 
   * you may prefer the TaGenerator method.
   */
  virtual const AttributeVoid& GlobalAttribute(void) const;


  /** 
   * Get attribute pointer 
   * The global attribute allways exits. For the vGenerator its of
   * type AttributeVoid, the TaGenerator sets a nontrivial type.
   * In a context where the attribute type is known, 
   * you may prefer the TaGenerator method.
   */
  virtual AttributeVoid* GlobalAttributep(void);


  /** @} doxygen group */



  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Reachability */
  /** @{ doxygen group */


  /**
   * Compute set of accessible states
   */
  StateSet AccessibleSet(void) const;

  /**
   * Make generator accessible.
   *
   * @return
   *   True if generator contains at least one initial state
   */
  bool Accessible(void);

  /**
   * Check if generator is accessible
   *
   * @return
   *   True if generator is accesssible
   */
  bool IsAccessible(void) const;

  /**
   * Compute set of Coaccessible states
   */
  StateSet CoaccessibleSet(void) const;

  /**
   * Make generator Coaccessible
   *
   * @return
   *   True if generator contains at least one marked state
   */
  bool Coaccessible(void);

  /**
   * Check if generator is Coaccessible
   *
   * @return
   *   True if generator is coaccessible
   */
  bool IsCoaccessible(void) const;

  /**
   * Compute set of blocking states.
   *
   * A state is considered blocking if it is accessible but not coaccessible.
   */
  StateSet BlockingStates(void) const;


  /**
   * Compute set of terminal states.
   *
   * A terminal state is a state with no successor state.
   * If and only if the set of terminal states is empty, the generator is complete.
   * @return
   *   Set of terminal states.
   */
  StateSet TerminalStates(void) const;


  /**
   * Compute set of terminal states.
   *
   * A terminal state is a state with no successor state.
   * This function returns the the set terminal states contained
   * in the specified state ste.
   *
   * @param rStates
   *   Set of state indices to restrict the search
   * @return
   *   Set of terminal states.
   */
  StateSet TerminalStates(const StateSet& rStates) const;

  /**
   * Check if generator is complete.
   *
   * A generator is considered complete, if each state has at least
   * one successor state. 
   *
   * If the generator is accessible, completeness
   * is equivalent to completeness of the generated language, ie 
   * forall s in L(G) there exists r>s such that r in L(G)
   *
   * If the generator is trim, completeness is equivalent to 
   * completeness of the markede language, ie forall s in Lm(G) there exists 
   * r>s such that r in Lm(G)
   *
   * @return
   *   True if generator is complete
   */
  bool IsComplete(void) const;

  /**
   * Check if generator is complete.
   *
   * Same as IsComplete(void), however, only the specified
   * states are considered. The rational is to e.g. apply the test
   * to accessible (resp. trim) states only. Then, test is equivalent
   * to completeness of the generated (resp. marked) language.
   *
   * @param rStates
   *   Set of state indices to restrict the completeness test
   * @return
   *   True if generator is relatively complete
   */
  bool IsComplete(const StateSet& rStates) const;


  /**
   * Check if generator is complete w.r.t. an alphabet
   *
   * A generator is considered complete w.r.t. an alphabet Sigma_o, 
   * if each state can be continued to a state in which a symbol
   * of Sigma_c is enabled.
   *
   * If the generator is accessible, completeness w.r.t. Sigma_o
   * is equivalent to:
   *
   * forall s in L(G) there exists t in (Sigma*)Sigma_u such that st in L(G)
   *
   * @param rSigmaO
   *   Specified alphabet Sigma_o
   *
   * @return
   *   True if generator is complete
   */
   bool IsComplete(const EventSet& rSigmaO) const;


  /**
   * Make generator Complete.
   *
   * This procedure removes all states that are guaranteed to evolve
   * into a terminal state within a finite number of transitios. 
   * The current implementations is initialized by
   * the set of terminal states and then performs a backward 
   * reachability analysis.
   *
   * @return
   *   True if generator contains at least one initial state
   */
   bool Complete(void);

  /**
   * Make generator Complete w.r.t. an alphabet
   *
   * This procedure removes all states that conflict with
   * completes w.r.t. the specified alphabet Sigma_o until 
   * a fixpoint is reached. The current implementation consists of
   * an outer iteration to restrict a domain of states and an inner iteration
   * for abcakwar reachability analyis.
   *
   * THIS IS EXPERIMENTAL / NEEDS TESTING
   *
   * @param rSigmaO
   *   Specified alphabet Sigma_o
   *
   * @return
   *   True if generator contains at least one initial state
   */
   bool Complete(const EventSet& rSigmaO);




  /**
   * Compute set of trim states
   */
  StateSet TrimSet(void) const;

  /**
   * Make generator trim
   *
   * This function removes all states are not accessible or not
   * coaccessible. In other words: only those states are kept, that
   * contribute to that marked language.
   *
   * @return 
   *   True if resulting generator contains at least one initial state and at least one marked state.
   */
  bool Trim(void);

  /**
   * Check if generator is trim.
   *
   * Returns true if all states are rechable and coreachale.
   *
   * @return
   *   True if generator is trim
   */
  bool IsTrim(void) const;


  /**
   * Make generator omega-trim
   *
   * This function removes states such that the generator becomes
   * omega trim while not affecting the induced omega language. 
   *
   * The implementation first makes the generator accessible
   * and then iteratively removes state that either 
   * never reach a marked state or that are guaranteed to eventually
   * reach a terminal state. There might be a more efficient 
   * approach.
   *
   * @return 
   *   True if resulting generator contains at least one initial state and at least one marked state.
   */
  bool OmegaTrim(void);


  /**
   * Check if generator is omega-trim.
   *
   * Returns true if all states are accessible, coacessible, and
   * have a successor state.
   *
   * @return
   *   True if generator is omega-trim
   */
  bool IsOmegaTrim(void) const;



  /** @} doxygen group */

  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name File IO */
  /** @{ doxygen group */
 
  /**
   * Write generators alphabet to console
   */
  void WriteAlphabet(void) const;

  /**
   * Write generators alphabet to string
   *
   * @return
   *   std::string
   * @exception Exception
   *   - IO errors (id 2)
   */
  std::string AlphabetToString(void) const;

  /**
   * Write generators alphabet to tokenwriter
   *
   * @param rTw
   *   Reference to TokenWriter
   *
   * @exception Exception
   *   - IO errors (id 2)
   */
  void WriteAlphabet(TokenWriter& rTw) const;

  /**
   * Write a stateset to console (no re-indexing).
   * Uses WriteStateSet(TokenWriter& rTw, const StateSet&) const to write
   * the specified state set to console  referring to this generators state names.
   *
   * @param rStateSet
   *   Reference to stateset
   */
  void WriteStateSet(const StateSet& rStateSet) const;

  /**
   * Write a stateset to string (no re-indexing). 
   * Uses WriteStateSet(TokenWriter& rTw, const StateSet&) const to write
   * the specified state set to a string  referring to this generators state names.
   *
   * @param rStateSet
   *   Reference to stateset
   * @return
   *   std::string
   * @exception Exception
   *   - IO errors (id 2)
   */
  std::string StateSetToString(const StateSet& rStateSet) const;

  /**
   * Write a stateset to formated text (no re-indexing). 
   * Uses WriteStateSet(TokenWriter& rTw, const StateSet&) const to write
   * the specified state set to a string  referring to this generators state names.
   *
   * @param rStateSet
   *   Reference to stateset
   * @return
   *   std::string
   * @exception Exception
   *   - IO errors (id 2)
   */
  std::string StateSetToText(const StateSet& rStateSet) const;

  /**
   * Write a stateset to TokenWriter. 
   * All native output of external state sets done with this function.
   * Technically, a StateSet is a set of plain indices with no references 
   * to symbolic names. Thus, it is only the context of a Generator that provides
   * the symbolic names for file output. 
   * 
   * Output of state sets always uses the mMinStateIndexMap to re-index states. 
   * However, this map is only set up automatically for file output. If You require
   * re-indexed output to e.g. a string, you must set up the map by calling SetMinStateIndexMap().
   * To ensure that no re-indexing takes place, call ClearMinStateIndexMap().
   *
   * @param rTw
   *   Reference to TokenWriter
   * @param rStateSet
   *   Reference to stateset
   *
   * @exception Exception
   *   - IO errors (id 2)
   */
  void WriteStateSet(TokenWriter& rTw, const StateSet& rStateSet) const;

  /**
   * Write a stateset to TokenWriter (debug version, no re-indexing)
   * 
   * @param rTw
   *   Reference to TokenWriter
   * @param rStateSet
   *   Reference to stateset
   *
   * @exception Exception
   *   - IO errors (id 2)
   */
   void DWriteStateSet(TokenWriter& rTw, const StateSet& rStateSet) const;

  /**
   * Write stateset of this generator to a string (no  re-indexing)
   *
   * @return
   *   std::string
   * @exception Exception
   *   - IO errors (id 2)
   */
  std::string StatesToString(void) const;

  /**
   * Write stateset of this generator to formated text (no  re-indexing)
   *
   * @return
   *   std::string
   * @exception Exception
   *   - IO errors (id 2)
   */
  std::string StatesToText(void) const;

  /**
   * Write set of marked states to a string (no  re-indexing)
   *
   * @return
   *   std::string
   * @exception Exception
   *   - IO errors (id 2)
   */
  std::string MarkedStatesToString(void) const;

  /**
   * Write set of initial states to a string (no  re-indexing)
   *
   * @return
   *   std::string
   * @exception Exception
   *   - IO errors (id 2)
   */
  std::string InitStatesToString(void) const;

  /**
   * Write transition relation to console (no re-indexing)
   */
  void WriteTransRel(void) const;

  /**
   * Write transition relation to string (no re-indexing)
   */
  std::string TransRelToString(void) const;

  /**
   * Write transition relation to formated text (no re-indexing)
   */
  std::string TransRelToText(void) const;

  /**
   * Write transition relation to tokenwriter.
   * Re-indexing and symbolic state names are handled in the same way
   * as with state sets: this function refers to the generators state symboltable to
   * obtain state names and  uses the mMinStateIndexMap to re-index the output.
   *
   * @param rTw
   *   Reference to TokenWriter
   *
   * @exception Exception
   *   - IO errors (id 2)
   */
  void WriteTransRel(TokenWriter& rTw) const;

  /**
   * Write transition relation to tokenwriter (debug version)
   * @param rTw
   *   Reference to TokenWriter
   *
   * @exception Exception
   *   - IO errors (id 2)
   */
  void DWriteTransRel(TokenWriter& rTw) const;

 
  /**
   * Writes generator to dot input format.
   * The dot file format is specified by the graphiz package; see http://www.graphviz.org.
   * The package includes the dot command line tool to generate a graphical 
   * representation of the generators graph. See also GraphWrite().
   * This functions sets the re-indexing to minimal indices.
   *
   * @param rFileName
   *   File to write
   *
   * @exception Exception
   *   - IO errors (id 2)
   */
  virtual void DotWrite(const std::string& rFileName) const;

  /**
   * Writes generator to dot input format (no re-indexing).
   * Variant of DotWrite() without re-indexing.
   *
   * @param rFileName
   *   File to write
   *
   * @exception Exception
   *   - IO errors (id 2)
   */
  virtual void DDotWrite(const std::string& rFileName) const;

  /**
   * Writes generator to dot input format for export to VioLib.
   * Variant of DotWrite() using strategic state and event names
   * to simplify import to VioLib (qt widget for graphical representation
   * of FAUDES generators).
   *
   * @param rFileName
   *   File to write
   * @exception Exception
   *   - IO errors (id 2)
   */
  virtual void XDotWrite(const std::string& rFileName) const;

  /**
   * Read a state set.
   * Refer to the generators state symboltable while reading a state set.
   * Ignore any attributes.
   *
   * @param rTr
   *   Reference to TokenReader
   * @param rLabel
   *   Label of set in source
   * @param rStateSet
   *   Destination state set 
   *
   * @exception Exception
   *   - IO errors (id 1)
   *   - token mismatch (id 50, 51, 52, 80, 85)
   */
  void ReadStateSet(TokenReader& rTr, const std::string& rLabel, StateSet& rStateSet) const;


  /**
   * Test whether file-i/o uses minimal state indicees.
   * 
   * @return
   *   True when minimal state indicees are enabled
   */
  bool ReindexOnWrite(void) const;

  /**
   * Enable/disable minimal state indicees for file-i/o.
   *
   * @param flag
   *   True enables reindexing.
   */
  void ReindexOnWrite(bool flag);


  /**
   * Enable/disable reindexing states for file-i/o.
   *
   * Set default value for re-indexing. Initially, the default
   * is set to "false".
   *
   * @param flag
   *   True enables reindexing.
   */
  static void ReindexOnWriteDefault(bool flag);


  /**
   * Enable/disable reindexing states for file-i/o.
   *
   * Set default value for re-indexing.
   *
   * @return
   *   True for reindexing enabled.
   */
  static bool ReindexOnWriteDefault(void);


  /** @} doxygen group */


  /*****************************************
   *****************************************
   *****************************************
   *****************************************/

  /** @name Misc */
  /** @{ doxygen group */

  /**
   * Return used events (executed in transitions)
   *
   * @return EventSet
   */
  EventSet UsedEvents(void) const;

  /**
   * Return unused events
   *
   * @return EventSet
   */
  EventSet UnusedEvents(void) const;

  /**
   * Set the alphabet to used events
   */
  void MinimizeAlphabet(void);

  /**
   * Return active event set at state x1
   *
   * @param x1
   *   Index of x1
   *
   * @return EventSet
   */
  EventSet ActiveEventSet(Idx x1) const;

  /**
   * Return active transition set at state x1
   *
   * @param x1
   *   Index of x1
   *
   * @return EventSet
   */
  TransSet ActiveTransSet(Idx x1) const;

  /**
   * Return the states covered by transitions
   *
   * @return StateSet
   */
  StateSet TransRelStates(void) const;

  /**
   * Return the successor state of state x1 with event ev.
   * If no such transition exists, return 0.
   * If multiple such transitions exit, through expection.
   *
   * A more egeneral set valued interface is provided by TransSet
   *
   * @return next state
   * @exception Exception
   *  - Successor state does not exist uniquely (id 92)
   */
   Idx SuccessorState(Idx x1, Idx ev) const;

  /**
   * Return the successor states of state x1
   *
   * @return StateSet
   */
  StateSet SuccessorStates(Idx x1) const;

  /**
   * Return the successor states of state x1 with event ev
   *
   * @return StateSet
   */
  StateSet SuccessorStates(Idx x1, Idx ev) const;

  /**
   * Check if generator is deterministic.
   *
   * We require the transition relation to be a partial function
   * and at most one initial state.
   * 
   * Note: pre 2.19 libFAUDES also insisted in exactly one initial state.
   * 
   *
   * @return
   *   True if generator is deterministic
   */
  bool IsDeterministic(void) const;

  /**
   * Set minimal index map for file io of generator states
   *
   * This function is implemented as fake-const to allow for
   * const Write function.
   *
   */
  void SetMinStateIndexMap(void) const;

  /**
   * Clear minimal index map for 1:1 file io 
   *
   */
  void ClearMinStateIndexMap(void) const;

  /**
   * Get state index as is it will be written to file.
   *
   * @param index
   *   state index
   * @return
   *   minimal index
   */
  Idx MinStateIndex(Idx index) const;


  /**
   * Re-enumerate states.
   *
   * This method re-enumerates states such that the resulting
   * state set consist of consecutive indexes; i.e. Size()=MaxStateIndex().
   * The current implementation sets up the minimal-state-index map used for
   * file i/o and applies it to the state set and the transition relation.
   *
   * Note: libFAUDES does not maintain consecutive state indices.
   * This was a design decision and it comes pros and cons. The method MinStateIndex()
   * was implemented to provide some limited support for the implementation of algorithms in a 
   * consecutive state enumeration paradigm. However, mixing both paradigms most likely
   * involves an overall performace penalty.
   */
  void MinStateIndex(void);


  /**
   * Get maximum state index used in this generator.
   * Returns 0 if no states at all.
   * @return
   *   maximal index
   */
  Idx MaxStateIndex(void) const;


  /**
   * Get state index translation map
   *
   * @return
   *   minimal index map
   */
  const std::map<Idx,Idx>& MinStateIndexMap(void) const;


  /**
   * Pretty printable event name for index (eg for debugging).
   *
   * @param index
   *   Event index
   *
   * @return
   *   std::string
   */
  std::string EStr(Idx index) const;

  /**
   * Return pretty printable state name for index (eg for debugging)
   *
   * @param index
   *   State index
   *
   * @return
   *   std::string
   */
  std::string SStr(Idx index) const;

  
  /**
   * Return pretty printable transition (eg for debugging)
   *
   * @param rTrans
   *   Transition
   *
   * @return
   *   std::string
   */
  std::string TStr(const Transition& rTrans) const;

  
  /**
   * Produce graphical representation of this generator.
   * This method calls the generator's DotWrite function and then processes the output
   * with the dot tool from graphiz package.  If no output format is given,
   * try to guess from filename extension.  See also ProcessDot().
   *
   * @param rFileName
   *   Name of output file
   * @param rOutFormat
   *   Graphics file format, eg "png", "jpg", "svg"
   * @param rDotExec
   *   path/name of executable
   * @exception Exception
   *   - IO errors (id 2)
   *   - error during systemcall for dot (id 3)
   */
  void GraphWrite(const std::string& rFileName, const std::string& rOutFormat="", 
    const std::string& rDotExec="dot") const;

  /** 
   * Order for sorting containers of generators 
   */
  bool operator < (const vGenerator& rOtherGen) const {
    return (mId < rOtherGen.mId);
  }

 
  /** @} doxygen group */


 protected:

  /** Name of generator */
  std::string mMyName;

  /** Number of generator */
  Idx mId;

  /** Number of generator objects */
  static Idx msObjectCount;

  /** State symbol table (local per Generator)*/
  SymbolTable mStateSymbolTable;

  /** Pointer to State symbol table */
  SymbolTable* mpStateSymbolTable;

  /** Pointer to Event symbol table */
  SymbolTable* mpEventSymbolTable;

  /** Automatic state names */
  bool mStateNamesEnabled;
  
  /** Default for automatic statenames */
  static bool msStateNamesEnabledDefault;

  /** Reindex states on file-i/o */
  bool mReindexOnWrite;

  /** Default for automatic statenames */
  static bool msReindexOnWriteDefault;

  /** Pointer to alphabet (actual type depends on attributes) */
  EventSet* mpAlphabet;

  /** Pointer to state set (actual type depends on attributes) */
  StateSet* mpStates;

  /** Pointer to ransition relation (actual type depends on attributes) */
  TransSet* mpTransRel;

  /** Pointer to lobal attribute (actual type depends on attributes) */
  AttributeVoid* mpGlobalAttribute;

  /** Pointer to alphabet prototype (incl. attribute type) */
  const EventSet* pAlphabetPrototype;

  /** Pointer to state set prototype (incl. attribute type) */
  const StateSet* pStatesPrototype;

  /** Pointer to transition relation prototype (incl. attribute type) */
  const TransSet* pTransRelPrototype;

  /** Pointer to global attribute prototype (configures global attribute type) */
  const AttributeVoid* pGlobalPrototype;

  /** Static default alphabet prototype (incl. attribute type) */
  static const EventSet& AlphabetVoid(void);

  /** Static default state set prototype (incl. attribute type) */
  static const StateSet& StatesVoid(void);

  /** Static default transition relation prototype (incl. attribute type) */
  static const TransSet& TransRelVoid(void);

  /** Static default global attribute prototype (configures global attribute type) */
  static const AttributeVoid& GlobalVoid(void);

  /** Initial states */
  StateSet mInitStates;

  /** Marked states */
  StateSet mMarkedStates;

  /** Map State indices to consecutive indices */
  std::map<Idx,Idx> mMinStateIndexMap;

  /** Allocate my heap members (attribute dependent types) */
  virtual void NewCore(void);
  
  /** Free my heap members (attribute dependent types) */
  virtual void DeleteCore(void);

  /** Callback for core update */
  virtual void UpdateCore(void);

  /** Configure attribute types */
  void ConfigureAttributeTypes(const AttributeVoid* pNewGlobalPrototype, 
    const StateSet* pNewStatesPrototype, const EventSet* pNewAlphabetPrototype, 
    const TransSet* pNewTransRelPrototype);

  /** Assignment for matching type */
  void DoAssign(const vGenerator& rSrc); 

 /**
   * Read generator object from TokenReader, see Type::Read for public wrappers.
   *
   * Virtual function for std token io interface. Context is ignored,
   * label defaults to "Generator".
   *
   * @param rTr
   *   TokenReader to read from
   * @param rLabel
   *   Section to read
   * @param pContext
   *   Read context to provide contextual information (ignored)
   *
   * @exception Exception
   *   - token mismatch (id 50, 51, 52, 80, 85)
   *   - IO error (id 1)
   */
  virtual void DoRead(TokenReader& rTr,  const std::string& rLabel = "", const Type* pContext=0);
 
  /**
   * Write generator to TokenWriter, see Type::Write for public wrappers.
   *
   * Virtual function for std token io interface. Context is ignored,
   * label defaults to "Generator". If the tokenwriter writes to a file,
   * state indices will be re-indext to start from 1.
   *
   * @param rTw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of section to write
   * @param pContext
   *   Write context to provide contextual information (ignored)
   *
   * @exception Exception 
   *   - IO errors (id 2)
   */
  virtual void DoWrite(TokenWriter& rTw, const std::string& rLabel="",const Type* pContext=0) const;

  /**
   * Write generator in debugging format to TokenWriter, see Type::DWrite for public wrappers.
   *
   * Reimplement this method in derived classes to provide the std token io
   * interface defined in the public section of Type.
   *
   * @param rTw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of section to write
   * @param pContext
   *   Write context to provide contextual information (ignored)
   *
   * @exception Exception 
   *   - IO errors (id 2)
   */
  virtual void DoDWrite(TokenWriter& rTw, const std::string& rLabel="",const Type* pContext=0) const;

  /**
   * Write generator statistics as comment to TokenWriter, see Type::SWrite for public wrappers.
   *
   * Reimplement this method in derived classes to provide the std token io
   * interface defined in the public section of Type.
   *
   * @param rTw
   *   Reference to TokenWriter
   *
   * @exception Exception 
   *   - IO errors (id 2)
   */
  virtual void DoSWrite(TokenWriter& rTw) const;

  /**
   * Write generator to TokenWriter, see Type::XWrite for public wrappers.
   *
   * Virtual function for std token io interface. Context is ignored,
   * label defaults to "Generator". 
   *
   * @param rTw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of section to write
   * @param pContext
   *   Write context to provide contextual information (ignored)
   *
   * @exception Exception 
   *   - IO errors (id 2)
   */
  virtual void DoXWrite(TokenWriter& rTw, const std::string& rLabel="",const Type* pContext=0) const;

  /**
   * Read the generator's alphabet from a TokenReader.
   * As of 2.24e, this method returns silently if no alphabet-tag is found.
   *
   * @param rTr
   *   Reference to TokenReader
   *
   * @exception Exception
   *   - IO errors (id 1)
   *   - token mismatch (id 50, 51, 52)
   */
  void ReadAlphabet(TokenReader& rTr);

  /**
   * Write generators stateset to TokenWriter. 
   *
   * This method differs from the general purpos version 
   * WriteStateSet(TokenWriter&, const StateSet&) in that it
   * can optionally write an explicit symbol table for state names.
   * This will happen whenever writing is done without re-indexing
   * states. 
   *
   * @param rTw
   *   Reference to TokenWriter
   *
   * @exception Exception
   *   - IO errors (id 2)
   */
  void WriteStates(TokenWriter& rTw) const;

  /**
   * Read the generator's stateset from a TokenReader. 
   * This sets up the StateSymbolTable.
   * As of 2.24e, this method returns silently if no alphabet-tag is found.
   *
   * @param rTr
   *   Reference to TokenReader
   * @exception Exception
   *   - IO errors (id 1)
   *   - token mismatch (id 50, 51, 52)
   */
  void ReadStates(TokenReader& rTr);

  /**
   * Read a stateset from TokenReader in XML format.
   *
   * This version for file IO supports the XML format introduced with libFAUDES 2.20.
   * Note that for Generators and derived classes, the native libFAUDES token
   * format is considered the default. To read  XML fromated data,
   * use the XRead() interface.
   *
   * @param rTr
   *   Reference to TokenReader
   * @param rStateSet
   *   Reference to stateset
   * @param rLabel
   *   Section name, defaults to name of set
   *
   * @exception Exception
   *   - IO errors (id 1)
   *   - token mismatch (id 50, 51, 52)
   */
  void XReadStateSet(TokenReader& rTr, StateSet& rStateSet, const std::string& rLabel="") const;

  /**
   * Read the generator's transition relation from a file. 
   *
   * @param rFileName
   *   File to read from
   *
   * @exception Exception
   *   - IO errors (id 1)
   *   - token mismatch (id 50, 51, 52)
   */
  void ReadTransRel(const std::string& rFileName);

  /**
   * Read the generator's transition relation from a TokenReader. 
   *
   * @param rTr
   *   Reference to TokenReader
   *
   * @exception Exception
   *   - IO errors (id 1)
   *   - token mismatch (id 50, 51, 52)
   */
  void ReadTransRel(TokenReader& rTr);

  /**
   * Read the generator's transition relation from a TokenReader. 
   *
   * @param rTr
   *   Reference to TokenReader
   *
   * @exception Exception
   *   - IO errors (id 1)
   *   - token mismatch (id 50, 51, 52)
   */
  void XReadTransRel(TokenReader& rTr);

  /**
   * Write a stateset to TokenWriter in XML format.
   *
   * This version for file IO supports the XML format introduced with libFAUDES 2.20.
   * Note that for Generators and derived classes, the native libFAUDES token
   * format is considered the default. To obtain XML fromated output of a Generator,
   * use the XWrite() interface.
   *
   * @param rTw
   *   Reference to TokenWriter
   * @param rStateSet
   *   Reference to stateset
   * @param rLabel
   *   Section name, defaults to name of set
   *
   * @exception Exception
   *   - IO errors (id 2)
   */
  void XWriteStateSet(TokenWriter& rTw, const StateSet& rStateSet, const std::string& rLabel="") const;

  /**
   * Write transition relation to tokenwriter in XML format.
   *
   * This version for file IO supports the XML format introduced with libFAUDES 2.20.
   * Note that for Generators and derived classes, the native libFAUDES token
   * format is considered the default. To obtain XML fromated output of a Generator,
   * use the XWrite() interface.
   *
   *
   * @param rTw
   *   Reference to TokenWriter
   *
   * @exception Exception
   *   - IO errors (id 2)
   */
  void XWriteTransRel(TokenWriter& rTw) const;


};

/** 
 * Plain generator, api typedef for generator with no attributes. 
 * \ingroup GeneratorClasses
 */
typedef vGenerator Generator; 

/** 
 * Convenience typedef for vectors og generators
 * \ingroup GeneratorClasses
 */
typedef  TBaseVector<Generator> GeneratorVector;  


/** 
 * RTI wrapper function. See also vGenerator::IsAccessible().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API bool IsAccessible(const vGenerator& rGen);

/** 
 * RTI wrapper function. See also vGenerator::IsCoaccessible().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API bool IsCoaccessible(const vGenerator& rGen);

/** 
 * RTI wrapper function. See also vGenerator::IsTrim().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API bool IsTrim(const vGenerator& rGen);

/** 
 * RTI wrapper function. See also vGenerator::IsOmegaTrim().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API bool IsOmegaTrim(const vGenerator& rGen);

/** 
 * RTI wrapper function. See also vGenerator::IsComplete().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API bool IsComplete(const vGenerator& rGen);

/** 
 * RTI wrapper function. See also vGenerator::IsComplete().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API bool IsComplete(const vGenerator& rGen, const EventSet& rSigmaO);

/** 
 * RTI wrapper function. See also vGenerator::IsDeterministic().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API bool IsDeterministic(const vGenerator& rGen);


/** 
 * RTI wrapper function. See also vGenerator::Accessible().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API void Accessible(vGenerator& rGen);

/** 
 * RTI wrapper function. See also vGenerator::Accessible().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API void Accessible(const vGenerator& rGen, vGenerator& rRes);

/** 
 * RTI wrapper function. See also vGenerator::Coaccessible().
 * \ingroup GeneratorFunctions 
 */
extern FAUDES_API void Coaccessible(vGenerator& rGen);

/** 
 * RTI wrapper function. See also vGenerator::Coaccessible().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API void Coaccessible(const vGenerator& rGen, vGenerator& rRes);

/** 
 * RTI wrapper function. See also vGenerator::Complete().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API void Complete(vGenerator& rGen);

/** 
 * RTI wrapper function. See also vGenerator::Complete().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API void Complete(const vGenerator& rGen, vGenerator& rRes);

/** 
 * RTI wrapper function. See also vGenerator::Complete().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API void Complete(vGenerator& rGen, const EventSet& rSigmaO);

/** 
 * RTI wrapper function. See also vGenerator::Complete().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API void Complete(const vGenerator& rGen, const EventSet& rSigmaO, vGenerator& rRes);

/** 
 * RTI wrapper function. See also vGenerator::Trim().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API void Trim(vGenerator& rGen);

/** 
 * RTI wrapper function. See also vGenerator::Trim().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API void Trim(const vGenerator& rGen, vGenerator& rRes);

/** 
 * RTI wrapper function. See also vGenerator::OmegaTrim().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API void OmegaTrim(vGenerator& rGen);

/** 
 * RTI wrapper function. See also vGenerator::OmegaTrim().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API void OmegaTrim(const vGenerator& rGen, vGenerator& rRes);

/** 
 * RTI wrapper function. 
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API void MarkAllStates(vGenerator& rGen);

/** 
 * RTI wrapper function. 
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API void AlphabetExtract(const vGenerator& rGen, EventSet& rRes);


/** 
 * RTI convenience function. 
 */
extern FAUDES_API void SetIntersection(const vGenerator& rGenA, const vGenerator& rGenB, EventSet& rRes);

/** 
 * RTI convenience function. 
 */
extern FAUDES_API void SetIntersection(const GeneratorVector& rGenVec, EventSet& rRes);

/** 
 * RTI convenience function. 
 */
extern FAUDES_API void SetUnion(const vGenerator& rGenA, const vGenerator& rGenB, EventSet& rRes);

/** 
 * RTI convenience function. 
 */
extern FAUDES_API void SetUnion(const GeneratorVector& rGenVec, EventSet& rRes);

/** 
 * RTI convenience function. 
 */
extern FAUDES_API void SetDifference(const vGenerator& rGenA, const vGenerator& rGenB, EventSet& rRes);




} // namespace faudes

/*

#define FAUDES_GENERATOR_DECLARATION(gtype,GlobalAttr,StateAttr,EventAttr,TransAttr) \
  public:                                                                     \
  virtual void EventAttribute(Idx index, const EventAttr& rAttr);             \
  virtual void EventAttributes(const TaEventSet<EventAttr>& rEventSet);       \
  virtual const EventAttr& EventAttribute(Idx index) const;                   \
  virtual const EventAttr& EventAttribute(const std::string& rName) const;    \
  virtual EventAttr* EventAttributep(Idx index);                              \
  virtual EventAttr* EventAttributep(const std::string& rName);               \
  virtual void StateAttribute(Idx index, const StateAttr& rAttr);             \
  virtual const StateAttr& StateAttribute(Idx index) const;                   \
  virtual StateAttr* StateAttributep(Idx index);                              \
  virtual void TransAttribute(const Transition& rTrans, const TransAttr& rAttr); \
  virtual const TransAttr& TransAttribute(const Transition& rTrans) const;     \
  virtual TransAttr* TransAttributep(const Transition& rTrans);               \
  virtual void GlobalAttribute(const GlobalAttr& rAttr);                      \
  virtual void GlobalAttributeTry(const Type& rAttr);                         \
  virtual const GlobalAttr& GlobalAttribute(void) const;                      \
  virtual GlobalAttr* GlobalAttributep(void);                       

#define FAUDES_GENERATOR_IMPLEMENTATION(gtype,GlobalAttr,StateAttr,EventAttr,TransAttr) \
  public:                                                                     \
  virtual void EventAttribute(Idx index, const EventAttr& rAttr);             \
  virtual void EventAttributes(const TaEventSet<EventAttr>& rEventSet);       \
  virtual const EventAttr& EventAttribute(Idx index) const;                   \
  virtual const EventAttr& EventAttribute(const std::string& rName) const;    \
  virtual EventAttr* EventAttributep(Idx index);                              \
  virtual EventAttr* EventAttributep(const std::string& rName);               \
  virtual void StateAttribute(Idx index, const StateAttr& rAttr);             \
  virtual const StateAttr& StateAttribute(Idx index) const;                   \
  virtual StateAttr* StateAttributep(Idx index);                              \
  virtual void TransAttribute(const Transition& rTrans, const TransAttr& rAttr); \
  virtual const TransAttr& TransAttribute(const Transition& rTrans) const;     \
  virtual TransAttr* TransAttributep(const Transition& rTrans);               \
  virtual void GlobalAttribute(const GlobalAttr& rAttr);                      \
  virtual void GlobalAttributeTry(const Type& rAttr);                         \
  virtual const GlobalAttr& GlobalAttribute(void) const;                      \
  virtual GlobalAttr* GlobalAttributep(void);                       

*/


#endif

