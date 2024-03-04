/** @file cfl_transset.h @brief Classes Transition, TTransSet and TaTransSet */

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


#ifndef FAUDES_TRANSSET_H
#define FAUDES_TRANSSET_H


#include <sstream>
#include <map>
#include <iostream>
#include <typeinfo>

#include "cfl_definitions.h"
#include "cfl_baseset.h"
#include "cfl_attrmap.h"
#include "cfl_indexset.h"
#include "cfl_nameset.h"
#include "cfl_attributes.h"
#include "cfl_tokenreader.h"


namespace faudes {

/** @addtogroup ContainerClasses */
/** @{*/

/**
 * Triple (X1,Ev,X2) to represent current state, event and next state.
 * This class provides the triple in struct like fashion where the components
 * are of type faudes::Idx. While default order is lexographic, the transition
 * container TTransSet allows for alternative sorting. Since technically a
 * Transition is just a triple of indices, it is only the context of a generator
 * that actually makes it a transition (eg by providing mandatory symbolic event
 * names). 
 */
class FAUDES_API Transition {

 public:

  /** Construct invalid Transition */
  Transition(void) : X1(0), Ev(0), X2(0) {};
    
  /**
   * Construct from values.
   * @param x1
   *   Index of current state
   * @param ev
   *   Index of Event
   * @param x2
   *   Index of next state
   */
  Transition(Idx x1, Idx ev,Idx x2) :
    X1(x1), Ev(ev), X2(x2) {}

  /** Default order for sorting container of Transition (lexographic) */
  inline bool operator < (const Transition& othertrans) const {
    if (X1 < othertrans.X1) return true;
    if (X1 > othertrans.X1) return false;
    if (Ev < othertrans.Ev) return true;
    if (Ev > othertrans.Ev) return false;
    if (X2 < othertrans.X2) return true;
    return false;
  } 

  /** Equality operator */
  inline bool operator == (const Transition& othertrans) const {
    return ((X1 == othertrans.X1) && (Ev == othertrans.Ev) && (X2 == othertrans.X2));
  };
      
  /** Inequality operator */
  inline bool operator != (const Transition& othertrans) const {
    return ((X1 != othertrans.X1) || (Ev != othertrans.Ev) || (X2 != othertrans.X2));
  };

  /** Test validity (all indices !=0) */
  inline bool Valid(void) const {
    return (X1!=0) && (Ev!=0) && (X2!=0);
  };
   
  /** Current state */
  Idx X1;
    
  /** Event */
  Idx Ev; 
    
  /** Next state */
  Idx X2;

  /** Pretty print to string */
  std::string Str(void) const {
    return ToStringInteger(X1)+"--("+ToStringInteger(Ev) + ")->" + ToStringInteger(X2);}
};




/**
 * Alternative ordering of Transitions. This class provides binary predicates
 * for sorting transition containers by variant lexographic order.
 */

class FAUDES_API TransSort {

 public:

  /** Binary predicate for sorting transitions in order Ev, X1, X2 */
  struct EvX1X2 {
    inline bool operator () (const Transition& left, const Transition& right) const {
      if (left.Ev < right.Ev) return true;
      if (left.Ev > right.Ev) return false;
      if (left.X1 < right.X1) return true;
      if (left.X1 > right.X1) return false;
      if (left.X2 < right.X2) return true;
      return false;
    }
  };

  /** Binary predicate for sorting transitions in order Ev, X2, X1 */
  struct EvX2X1 {
    inline bool operator () (const Transition& left, const Transition& right) const {
      if (left.Ev < right.Ev) return true;
      if (left.Ev > right.Ev) return false;
      if (left.X2 < right.X2) return true;
      if (left.X2 > right.X2) return false;
      if (left.X1 < right.X1) return true;
      return false;
    }
  };

  /** Binary predicate for sorting transitions in order X2, Ev, X1 */
  struct X2EvX1 {
    inline bool operator () (const Transition& left, const Transition& right) const {
      if (left.X2 < right.X2) return true;
      if (left.X2 > right.X2) return false;
      if (left.Ev < right.Ev) return true;
      if (left.Ev > right.Ev) return false;
      if (left.X1 < right.X1) return true;
      return false;
    }
  };

  /** Binary predicate for sorting transitions in order X2, X1, Ev */
  struct X2X1Ev {
    inline bool operator () (const Transition& left, const Transition& right) const {
      if (left.X2 < right.X2) return true;
      if (left.X2 > right.X2) return false;
      if (left.X1 < right.X1) return true;
      if (left.X1 > right.X1) return false;
      if (left.Ev < right.Ev) return true;
      return false;
    }
  };

  /** Binary predicate for sorting transitions in order X1, X2, Ev */
  struct X1X2Ev {
    inline bool operator () (const Transition& left, const Transition& right) const {
      if (left.X1 < right.X1) return true;
      if (left.X1 > right.X1) return false;
      if (left.X2 < right.X2) return true;
      if (left.X2 > right.X2) return false;
      if (left.Ev < right.Ev) return true;
      return false;
    }
  };

  /** Binary predicate for sorting transitions in order X1, Ev, X2 */
  struct X1EvX2 {
    inline bool operator () (const Transition& left, const Transition& right) const {
      if (left.X1 < right.X1) return true;
      if (left.X1 > right.X1) return false;
      if (left.Ev < right.Ev) return true;
      if (left.Ev > right.Ev) return false;
      if (left.X2 < right.X2) return true;
      return false;
    }
  };

};



/** 
 * Set of Transitions.
 *
 * This container class provides similar functionality and interface as BaseSet, but
 * for Transitions rather than indices. The additional feature is a template parameter 
 * that allows to specify alternative sorting. For algorithms that examine a transition 
 * relation by e.g. the successor state X2, it may be worthwhile to copy a given 
 * TTransRel<TransSort::X1EvX2> to a TTransRel<TransSort::X2EvX1>. Example,
 * assuming some transition relation is given in default order 
 *
 * \code
 * TransSet transrel;                         // transrel default order X1-Ev-X2
 *
 * // ... some operation to set up transrel
 *
 * TTransSet<TransSort::X2EvX1> transByX2;    // alternative order X2-Ev-X1
 * transrel.ReSort(transByX2);                // copy and re-order transrel
 * Iterator tit    =transByX2.BeginByX2(x2)   // begin iterator, X2 specified 
 * Iterator tit_end=transByX2.EndByX2(x2)     // end iterator, X2 specified
 * for(; tit!=tit_end; ++tit) {               // loop over all transitions with specified x2
 *
 * // ... code to examine tramsitions with specified x2
 *
 * }
 *   
 * \endcode
 *
 * Note: it is the context of a Generator that
 * actually allows to interpret a TTransSet as a set of transitions as opposed to
 * a set of triples of indices. In particular, file IO of transitions is provided
 * by the generator class (although TTransSet provides basic output functions for debugging)
 */

// tweak: this appears to be a g++ 4.2 (OsX) issue --- fails at dynamic cast if this symbol is not explicitly exposed
#ifdef __GNUC__
template <class Cmp=TransSort::X1EvX2>
class FAUDES_API TTransSet : public TBaseSet<Transition,Cmp> {
#else
template <class Cmp=TransSort::X1EvX2>
class TTransSet : public TBaseSet<Transition,Cmp> {
#endif

FAUDES_TYPE_DECLARATION(TransSet,TTransSet,(TBaseSet<Transition,Cmp>))


  public:

  /** @name Constructors & Destructor */ 
  /** @{ doxygen group */

  /** Construct an empty TTransSet object */
  TTransSet(void); 

  /**
   * Copy-constructor
   */
  //TTransSet(const TBaseSet<Transition,Cmp>& rOtherSet);
  TTransSet(const TTransSet<Cmp>& rOtherSet);

  /**
   * Re-Sort Copy-constructor
   */
  template<class OtherCmp>
  TTransSet(const TTransSet<OtherCmp>& res);

  /** Virtual destructor */
  virtual ~TTransSet() {};


  /** @} doxygen group */
    

  /** Iterator on transition */
  typedef typename TBaseSet<Transition, Cmp>::Iterator Iterator;


  /** @name Accessing individual transitions */ 
  /** @{ doxygen group */

  /** 
   * Add a Transition. 
   * 
   * @param rTransition 
   *   Reference to transition object
   * @return
   *   True if the transition was new to the set
   *
   */
  bool Insert(const Transition& rTransition);
    
  /** 
   * Add a Transition by indices
   *
   * @param x1
   *   Predecessor state
   * @param ev
   *   Event
   * @param x2
   *   Successor state
   * @return
   *   True if the transition was new to the set
   *
   */
  bool Insert(Idx x1, Idx ev, Idx x2);
    
  /** 
   * Add a Transition. 
   * 
   * @param pos
   *   Insertion hint passed to STL
   * @param rTransition 
   *   Reference to transition object
   * @return
   *   Insertion position
   *
   */
  Iterator Inject(const Iterator& pos, const Transition& rTransition);
    
  /** 
   * Add a Transition. 
   * 
   * @param rTransition 
   *   Reference to transition object
   * @return
   *   Insertion position
   *
   */
  void Inject(const Transition& rTransition);
    
  /** 
   * Remove a Transition
   *
   * @return
   *   True if transition did exist
   */
  bool Erase(const Transition& t);
    
  /** 
   * Remove a Transition by x1, ev, x2
   *
   * @return
   *   True if transition did exist
   */
  bool Erase(Idx x1, Idx ev, Idx x2);

  /**
   * Remove a Transition by iterator
   *
   * @return
   *   Iterator to next transition
   */
  Iterator Erase(const Iterator& it);

  /**
   * Remove all transitions containing predecessor state x1.
   *
   * @param x1
   *   State index
   * @exception Exception
   *   - sorting mismatch (id 68)
   */
  void EraseByX1(Idx x1);

  /**
   * Remove all transitions containing predecessor state x1 and event ev.
   *
   * @param x1
   *   State index
   * @param ev
   *   Event index
   * @exception Exception
   *   - sorting mismatch (id 68)
   */
  void EraseByX1Ev(Idx x1, Idx ev);

  /**
   * Remove all transitions containing successor state x2.
   * This function iterates over all transitions to work with any sorting.
   * 
   * @param x2
   *   State index
   */
  void EraseByX2(Idx x2);

  /**
   * Remove all transitions containing event ev.
   * This function iterates over all transitions to work with any sorting.
   *
   * @param ev
   *   Event index
   */
  void EraseByEv(Idx ev);
    
  /**
   * Remove all transitions containing state x,
   * This function iterates over all transitions to work with any sorting.
   * 
   * @param x
   *   State index
   */
  void EraseByX1OrX2(Idx x);

  /**
   * Remove all transitions containing a specified state. 
   * This function iterates over all transitions to work with any sorting.
   * 
   * @param rStates
   *   Set of states to remore
   */
  void EraseByX1OrX2(const StateSet& rStates);

  /**
   * Restrict to transitions with states as specified.
   * Erases any transition with X1 or X2 not in the specified state set.
   * 
   * @param rStateSet
   *   Set of states to keep.
   */
  void RestrictStates(const StateSet& rStateSet);

  /**
   * Restrict to transitions with events as specified.
   * Erases any transition with event not in the specified state set.
   * 
   * @param rEventSet
   *   Set of events to keep.
   */
  void RestrictEvents(const EventSet& rEventSet);

  /**
   * Find transition given by x1, ev, x2
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
   *   Iterator to transition or End() if not exists
   */
  Iterator Find(Idx x1, Idx ev, Idx x2) const;

  /**
   * Find specified transition
   *
   * 
   * @param t
   *   Transition
   *
   * @return
   *   Iterator to transition or End() if not exists
   */
  Iterator Find(const Transition& t) const;


  /**
   * Test existence
   *
   * @param t
   *   Transition
   *
   * @return
   *   bool
   */
  bool Exists(const Transition& t) const;

  /**
   * Test existence
   *
   * @param x1
   *   Predecessor state Idx
   * @param ev
   *   Event Idx
   * @param x2
   *   Successor state Idx
   *
   * @return
   *   bool
   */
  bool Exists(Idx x1, Idx ev, Idx x2) const;

  /**
   * Test existence
   *
   * @param x1
   *   Predecessor state Idx
   * @param ev
   *   Event Idx
   *
   * @return
   *   bool
   */
   bool ExistsByX1Ev(Idx x1, Idx ev) const;

  /**
   * Test existence
   *
   * @param x1
   *   Predecessor state Idx
   *
   * @return
   *   bool
   */
   bool ExistsByX1(Idx x1) const;

  /**
   * Tests if a transition with specified predecessor or successor state
   * exists.
   *
   * @param x
   *   State Idx
   *
   * @return
   *   bool
   */
  bool ExistsByX1OrX2(Idx x) const;

  /** @} doxygen group */


  /** @name Transition iterators 
   *
   *  A variaty of iterators are provided to examine specified
   *  segments of the transition relation, e.g. all transitions starting
   *  from a given state. Note that implemetation of these iterators
   *  requires the transition set to be of sorted accordingly. Eg.
   *  scanning all transitions that are labled with a particular event
   *  requires a sorting TransSOrt::EvX1X2 orT ransSOrt::EvX2X1.
   *
   *
   */
 
  /** @{ doxygen group: iterators */

  /** 
   * Iterator to begin of set 
   *
   * @return
   *   TTransSet<Cmp>::Iterator
   */
  Iterator Begin(void) const;

  /** 
   * Iterator to end of set 
   *
   * @return
   *   TTransSet<Cmp>::Iterator
   */
  Iterator End(void) const;  

  
  /** 
   * Iterator to first Transition specified by current state.
   *
   * @param x1
   *   Predecessor state index
   *
   * @return
   *   TTransSet<Cmp>::Iterator
   *
   * @exception Exception
   *   - Sorting mismatch (id 68)
   */
  Iterator Begin(Idx x1) const;

  /** 
   * Iterator to end or Transitions with specified current state.
   *
   * @param x1
   *   Predecessor state index
   *
   * @return
   *   TTransSet<Cmp>::Iterator
   *
   * @exception Exception
   *   - Sorting mismatch (id 68)
   */
  Iterator End(Idx x1) const;

  /** 
   * Iterator to first Transitions specified by current state and event.
   *
   * @param x1
   *   Predecessor state index
   * @param ev
   *   Event index
   *
   * @return
   *   TTransSet<Cmp>::Iterator 
   *
   * @exception Exception
   *   - Sorting mismatch (id 68)
   */
  Iterator Begin(Idx x1, Idx ev) const;

  /** 
   * Iterator to first Transition after spcified current state and event. 
   *
   * @param x1
   *   Predecessor state index
   * @param ev
   *   Event index
   *
   * @return
   *   TTransSet<Cmp>::Iterator
   *
   * @exception Exception
   *   - sorting mismatch (id 68)
   */
  Iterator End(Idx x1, Idx ev) const;

  /**
   * Iterator to first Transition specified by event.
   * This function requires sorting TransSort::EvX1X2 or TransSort::EvX2X1. 
   * 
   * @param ev
   *   Event index
   *   
   * @return
   *   TTransSet<Cmp>::iterator
   *
   * @exception Exception
   *   - sorting mismatch (id 68)
   */
  Iterator BeginByEv(Idx ev) const;

  /**
   * Iterator to first Transition after specified by event.
   * This function requires sorting TransSort::EvX1X2 or TransSort::EvX2X1 
   *
   * @param ev
   *   Predecessor state index
   *   
   * @return
   *   TTransSet<Cmp>::Iterator
   *
   * @exception Exception
   *   - sorting mismatch (id 68)
   */
  Iterator EndByEv(Idx ev) const;

  /**
   * Iterator to first Transition specified by event and current state.
   * This function requires sorting TransSort::EvX1X2. 
   * 
   * @param ev
   *   Event index
   * @param x1
   *   Predecessor state index
   *   
   * @return
   *   TTransSet<Cmp>::iterator
   *
   * @exception Exception
   *   - sorting mismatch (id 68)
   */
  Iterator BeginByEvX1(Idx ev, Idx x1) const;

  /**
   * Iterator to first Transition after specified ev and current state.
   * This function requires sorting TransSort::EvX1X2. 
   * 
   * @param ev
   *   Event index
   * @param x1
   *   Predecessor state index
   *   
   * @return
   *   TTransSet<Cmp>::Iterator
   *
   * @exception Exception
   *   - sorting mismatch (id 68)
   */
  Iterator EndByEvX1(Idx ev, Idx x1) const;

  /**
   * Iterator to first Transition specified by event and next state.
   * This function requires sorting TransSort::EvX2X1. 
   * 
   * @param ev
   *   Event index
   * @param x2
   *   Predecessor state index
   *   
   * @return
   *   TTransSet<Cmp>::Iterator
   *
   * @exception Exception
   *   - sorting mismatch (id 68)
   */
  Iterator BeginByEvX2(Idx ev, Idx x2) const;

  /**
   * Iterator to first Transition after specified event and next state.
   * This function requires sorting TransSort::EvX2X1. 
   * 
   * @param ev
   *   Event index
   * @param x2
   *   Predecessor state index
   *   
   * @return
   *   TTransSet<Cmp>::Iterator
   *
   * @exception Exception
   *   - sorting mismatch (id 68)
   */
  Iterator EndByEvX2(Idx ev, Idx x2) const;

  /**
   * Iterator to first Transition specified by successor state x2.
   * This function requires sorting TransSort::X2EvX1 or TransSort::X2X1Ev.  
   * 
   * @param x2
   *   Predecessor state index
   *   
   * @return
   *   TTransSet<Cmp>::iterator
   *
   * @exception Exception
   *   - sorting mismatch (id 68)
   */
  Iterator BeginByX2(Idx x2) const;

  /**
   * Iterator to first Transition after specified successor state x2.
   * This function requires sorting TransSort::X2EvX1 or TransSort::X2X1Ev  
   * 
   * @param x2
   *   Predecessor state index
   *   
   * @return
   *   TTransSet<Cmp>::Iterator
   *
   * @exception Exception
   *   - sorting mismatch (id 68)
   */
  Iterator EndByX2(Idx x2) const;

  /**
   * Iterator to first Transition specified by successor x2  and ev.
   * This function requires sorting TransSort::X2EvX1.
   * 
   * @param x2
   *   Predecessor state index
   * @param ev
   *   Event index
   *   
   * @return
   *   TTransSet<Cmp>::Iterator
   *
   * @exception Exception
   *   - sorting mismatch (id 68)
   */
  Iterator BeginByX2Ev(Idx x2, Idx ev) const;

  /**
   * Iterator to first Transition after specified  successor x2  and ev.
   * This function requires sorting TransSort::X2EvX1.
   * 
   * @param x2
   *   Predecessor state index
   * @param ev
   *   Event index
   *   
   * @return
   *   TTransSet<Cmp>::Iterator
   *
   * @exception Exception
   *   - sorting mismatch (id 68)
   */
  Iterator EndByX2Ev(Idx x2, Idx ev) const;

  /** @} doxygen group */

  /** @name Set Operators
   *
   * Reimplement boolean operators.
   *
   */
 
  /** @{ doxygen group: operators */


  /**
   * Set union operator
   *
   * @return 
   *   Union Set
   *
   */
  TTransSet<Cmp> operator + (const TTransSet<Cmp>& rOtherSet) const;

  /**
   * Set difference operator
   *
   * @return 
   *   Set Difference NameSet
   *
   */
  TTransSet<Cmp> operator - (const TTransSet<Cmp>& rOtherSet) const;

  /**
   * Set intersection operator
   *
   * @return 
   *   Set Intersection
   *
   */
  TTransSet<Cmp> operator * (const TTransSet<Cmp>& rOtherSet) const;

  /** @} doxygen group */

  /** @name Misc */
  /** @{ doxygen group */

  /**
   * Get copy of trantision relation  sorted by other compare 
   * operator, e.g. TSort::X2EvX1
   * 
   * @return
   *   Transition relation
   */
  template<class OtherCmp>
  void ReSort(TTransSet<OtherCmp>& res) const;

  /** 
   * Get state set covered by transition set 
   *
   * @return
   *   Set of state indices used by some transition
   */
  StateSet States(void) const;

  /**
   * Get set of successor states for specified current state
   * 
   * @param x1
   *   Current state
   *
   * @return
   *   Set of state indices
   */
  StateSet SuccessorStates(Idx x1) const;

  /**
   * Get set of successor states for specified current states
   * 
   * @param rX1Set
   *   Current state
   *
   * @return
   *   Set of state indices
   */
  StateSet SuccessorStates(const StateSet& rX1Set) const;

  /**
   * Get set of successor states for specified current state and event
   * 
   * @param x1
   *   Current state
   * @param ev
   *   Event
   *
   * @return
   *   Set of state indices
   */
  StateSet SuccessorStates(Idx x1, Idx ev) const;

  /**
   * Get set of successor states for specified current states and events
   * 
   * @param rX1Set
   *   Current states
   * @param rEvSet
   *   Events
   *
   * @return
   *   Set of state indices
   */
  StateSet SuccessorStates(const StateSet& rX1Set, const EventSet&  rEvSet) const;


  /**
   * Get set of events that are active for a specified current state
   * Since a transition set does not refer to a SymbolTable, this function
   * returns a set of plain indices. In order to interpret the set as an EventSet, 
   * the relevant SymbolTable must be supplied as second argument. If obmitting the second
   * argument, the defult SymbolTable is used.
   *
   * @param x1
   *   Current state
   * @param pSymTab
   *   SymbolTable to refer to
   *
   * @return 
   *   Set of events. 
   */
  EventSet ActiveEvents(Idx x1, SymbolTable* pSymTab=NULL) const;

  /**
   * Return pretty printable string representation.
   * Primary meant for debugging messages.
   *
   * @param rTrans
   *   Transition to print
   *
   * @return
   *   String
   */
  std::string Str(const Transition& rTrans) const;


  /** @} doxygen group */

  protected:


  /**
   * Assign my members. 
   *
   * @param rSource 
   *    Source to copy from
   * @return
   *    Ref to this set
   */
  void DoAssign(const TTransSet& rSource);

  /** 
   * Write to TokenWriter, see Type::Write for public wrappers.
   *
   * @param rTw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of section to write, defaults to name of set
   * @param pContext
   *   Write context eg symboltables
   *
   * @exception Exception
   *   - IO errors (id 2)
   */

  virtual void DoWrite(TokenWriter& rTw, const std::string& rLabel="", const Type* pContext=0) const;


};

/** Type definition for default sorted TTransSet */
typedef TTransSet<TransSort::X1EvX2> TransSet;

/** Type definition for default sorted TTransSet */
typedef TTransSet<TransSort::X1EvX2> TransSetX1EvX2;

/** Type definition for ev, x1, x2 sorted TTransSet */
typedef TTransSet<TransSort::EvX1X2> TransSetEvX1X2;

/** Type definition for ev, x2, x1 sorted TTransSet */
typedef TTransSet<TransSort::EvX2X1> TransSetEvX2X1;

/** Type definition for x2, ev, x1 sorted TTransSet */
typedef TTransSet<TransSort::X2EvX1> TransSetX2EvX1;

/** Type definition for x2, x1, ev sorted TTransSet */
typedef TTransSet<TransSort::X2X1Ev> TransSetX2X1Ev;

/** Type definition for x1, x2, ev sorted TTransSet */
typedef TTransSet<TransSort::X1X2Ev> TransSetX1X2Ev;


/** 
 * Set of Transitions with attributes.
 *
 * This container class is derived from TTransSet to provide attributes as an
 * additional feature. The template parameter specifies the attribute class,
 * which in turn must provide some basic funtionality. In contrast to the TTransSet, the TaTransSet
 * is restricted to standard ordering. 
 *
 * Note that it is the context of a Generator that
 * actually allows to interpret a TaTransSet as a set of transitions as opposed to
 * a set of triples of indices with attributes. In particular, file IO of transitions is provided
 * by the generator class (although TaTransSet provides output functions for debugging)
 */


template <class Attr>
class FAUDES_API TaTransSet : public TransSet, public TAttrMap<Transition,Attr,TransSort::X1EvX2> {

FAUDES_TYPE_DECLARATION(Void,TaTransSet,TransSet)

public:


  /** @name Constructors & Destructor */ 
  /** @{ doxygen group */

  /** Construct an empty TaTransSet object */
  TaTransSet(void); 

  /**
   * Copy-constructor (incl attributes) 
   */
  TaTransSet(const TaTransSet& rOtherSet);

  /**
   * Copy-Constructor (set attributes to default)
   */
  TaTransSet(const TTransSet<TransSort::X1EvX2>& rOtherSet);

  /** Virtual destructor */
  virtual ~TaTransSet() {}
    
  /** Relaxed assignment method. 
   *
   * Runtime typecheck for TransSet, maintains attributes provided they can be casted.
   *
   * @param rSrc 
   *    Source from which to assign
   * @return
   *    Ref to this set
   */
  virtual TaTransSet& Assign(const TBaseSet<Transition,TransSort::X1EvX2>& rSrc);

  /** Relaxed assignment operator. 
   *
   * @param rSrc 
   *    Source from which to assign
   * @return
   *    Ref to this set
   */
  virtual TaTransSet& operator=(const TransSet& rSrc) {return Assign(rSrc);}

  /** @} doxygen group */



  /** @name Accessing individual transitions */ 
  /** @{ doxygen group */
    
  /** Iterator on transition */
  typedef typename TTransSet<TransSort::X1EvX2>::Iterator Iterator;

  /** 
   * Add a Transition by indices
   *
   * @param x1
   *   Predecessor state
   * @param ev
   *   Event
   * @param x2
   *   Successor state
   *
   * @return
   *   True if the transition was new to the set
   */
  bool Insert(Idx x1, Idx ev, Idx x2);
    
  /** 
   * Add a Transition directly. If the transition already
   * exists, the attribute is maintained. Otherwise, the transition
   * is inserted with default attribute.
   * 
   * @param rTransition 
   *   Reference to transition object
   *
   * @return
   *   True if the transition was new to the set
   */
  bool Insert(const Transition& rTransition);
    
  /** 
   * Add a Transition with attribute.
   * 
   * @param rTransition 
   *   Reference to transition object
   * @param rAttr 
   *   Reference to attribute
   *
   * @return
   *   True if the transition was new to the set
   */
  bool Insert(const Transition& rTransition, const Attr& rAttr);
    
  /**
   * Inserts elements of rOtherSet.
   *
   * Attributes of this set are maintained, newly inserted elements attain the
   * attribute from rOtherSet if it can be casted appropriately.
   *
   *
   * @param rOtherSet
   *   Other IndexSet
   */
   virtual void InsertSet(const TransSet& rOtherSet);

  /**
   * Inserts elements of rOtherSet.
   *
   * This variant uses a runtime cast to access attributes.
   *
   * @param rOtherSet
   *     Other IndexSet
   * @exception Exception
   *   - cast failed (id 67)
   */
   virtual void InsertSet(const TBaseSet<Transition,TransSort::X1EvX2>& rOtherSet);

  /** 
   * Remove a Transition
   *
   * @return
   *   True if transition did exist
   */
  bool Erase(const Transition& t);
    
  /** 
   * Remove a Transition
   *
   * @return
   *   True if transition did exist
   */
  bool Erase(Idx x1, Idx ev, Idx x2);

  /**
   * Remove a Transition by iterator 
   *
   * @return
   *   Iterator to next transition
   */
  Iterator Erase(const Iterator& it);

  /**
   * Inserts elements of rOtherSet.
   *
   * Attributes of this set are maintained.
   *
   *
   * @param rOtherSet
   *   Other IndexSet
   */
   virtual void EraseSet(const TransSet& rOtherSet);

  /**
   * Inserts elements of rOtherSet.
   *
   * This variant uses a runtime cast to access attributes.
   *
   * @param rOtherSet
   *     Other IndexSet
   * @exception Exception
   *   - cast failed (id 67)
   */
   virtual void EraseSet(const TBaseSet<Transition,TransSort::X1EvX2>& rOtherSet);


  /** 
   * Restrict to specified subset. 
   *
   * Erases any elements no in the specified set. This function
   * ignores the attributes of the other set and maintains the attributes 
   * of the remaining elements in this set.
   *
   * @param rOtherSet 
   *    Elements to erase
   */
   void RestrictSet(const TransSet& rOtherSet);


  /** 
   * Restrict to specified subset. 
   *
   * This variant uses a runtime cast to access attributes.
   *
   * @param rOtherSet 
   *    Elements to erase
   */
   void RestrictSet(const TBaseSet<Transition,TransSort::X1EvX2>& rOtherSet);



 
  /** resolve ambiguities from attribute interface ("using" wont do the job) */
  const Attr* AttributeType(void) const { return TAttrMap<Transition,Attr,TransSort::X1EvX2>::AttributeType(); };
  Attr* Attributep(const Transition& rElem) { return TAttrMap<Transition,Attr,TransSort::X1EvX2>::Attributep(rElem); };
  const Attr& Attribute(const Transition& rElem) const { return TAttrMap<Transition,Attr,TransSort::X1EvX2>::Attribute(rElem); };
  void Attribute(const Transition& rElem, const Attr& rAttr) { return TAttrMap<Transition,Attr,TransSort::X1EvX2>::Attribute(rElem,rAttr); };
  void Attribute(const Transition& rElem, const Type& rAttr) { return TAttrMap<Transition,Attr,TransSort::X1EvX2>::Attribute(rElem,rAttr); };
  void AttributeTry(const Transition& rElem, const Type& rAttr) { return TAttrMap<Transition,Attr,TransSort::X1EvX2>::AttributeTry(rElem,rAttr); };
     

  /** @} doxygen group */


 protected:

  /**
   * Assign my members. Maintain attributes.
   *
   * @param rSource 
   *    Source to copy from
   * @return
   *    Ref to this set
   */
  void DoAssign(const TaTransSet& rSource);

};

/** @} doxygen group*/


/*
*************************************************************************************************
*************************************************************************************************
* Implementation of transset without attributes
*************************************************************************************************
*************************************************************************************************
*/


/* convenience access to relevant scopes */
#define THIS TTransSet<Cmp>
#define TEMP template<class Cmp> 			
#define BASE TBaseSet<Transition,Cmp>

// std faudes type
FAUDES_TYPE_TIMPLEMENTATION(TransSet,THIS,BASE,TEMP)

// TTransSet(void)
TEMP THIS::TTransSet(void) : BASE()
{
  FD_DC("TTransSet(" << this << ")::TTransSet()");
}

// TTransSet(othertransrel)
//TEMP THIS::TTransSet(const TBaseSet<Transition,Cmp>& rOtherSet) : 
 TEMP THIS::TTransSet(const TTransSet<Cmp>& rOtherSet) :
  BASE()
{
  FD_DC("TTransSet(" << this << ")::TTransSet(rOtherSet "<< &rOtherSet <<")");
  Assign(rOtherSet);
}

// TTransSet(othertransrel othersort)
TEMP template<class OtherCmp>
THIS::TTransSet(const TTransSet<OtherCmp>& rOtherSet) : 
  BASE() 
{
  FD_DC("TTransSet(" << this << ")::TTransSet(rOtherSet/ReSort "<< &rOtherSet <<")");
  rOtherSet.ReSort(*this);
}

// assignment  (maintain attributes)
TEMP void THIS::DoAssign(const TTransSet& rSourceSet) {
  FD_DC("TTransSet(" << this << ")::DoAssign(..)");
  // call base (incl attributes if the have identival type)
  BASE::DoAssign(rSourceSet);
} 

// iterator Begin() const
TEMP typename THIS::Iterator THIS::Begin(void) const {
  return BASE::Begin();
}

// iterator End() const
TEMP typename THIS::Iterator THIS::End(void) const {
  return BASE::End();
}


// Convenience macro for order typecheck
#define SORT_EXCEPTION  { std::stringstream errstr; \
  errstr << "Transition set order mismatch " << std::endl; \
  throw Exception("TransSet::Iterator()", errstr.str(), 68); }


// iterator Begin(x1) const
TEMP typename THIS::Iterator THIS::Begin(Idx x1) const {
#ifdef FAUDES_CHECKED
  if(typeid(Cmp)!=typeid(TransSort::X1EvX2)) 
    if(typeid(Cmp)!=typeid(TransSort::X1X2Ev)) 
      SORT_EXCEPTION;
#endif
  Transition tlx(x1,0,0);
  return THIS::ThisIterator(BASE::pSet->lower_bound(tlx));
}

// iterator End(x1) const
TEMP typename THIS::Iterator THIS::End(Idx x1) const {
#ifdef FAUDES_CHECKED
  if(typeid(Cmp)!=typeid(TransSort::X1EvX2)) 
    if(typeid(Cmp)!=typeid(TransSort::X1X2Ev)) 
      SORT_EXCEPTION;
#endif
  Transition tlx(x1+1,0,0);
  return THIS::ThisIterator(BASE::pSet->lower_bound(tlx));
}

// iterator Begin(x1,ev) const
TEMP typename THIS::Iterator THIS::Begin(Idx x1, Idx ev) const {
#ifdef FAUDES_CHECKED
  if(typeid(Cmp)!=typeid(TransSort::X1EvX2)) 
    SORT_EXCEPTION;
#endif
  Transition tlx(x1,ev,0);
  return THIS::ThisIterator(BASE::pSet->lower_bound(tlx));
}

// iterator End(x1,ev) const
TEMP typename THIS::Iterator THIS::End(Idx x1, Idx ev) const {
#ifdef FAUDES_CHECKED
  if(typeid(Cmp)!=typeid(TransSort::X1EvX2)) 
    SORT_EXCEPTION;
#endif
  Transition tlx(x1,ev+1, 0);
  return THIS::ThisIterator(BASE::pSet->lower_bound(tlx));
}

// iterator BeginByEv(ev) const
TEMP typename THIS::Iterator THIS::BeginByEv(Idx ev) const {
#ifdef FAUDES_CHECKED
  if(typeid(Cmp)!=typeid(TransSort::EvX1X2)) 
    if(typeid(Cmp)!=typeid(TransSort::EvX2X1)) 
      SORT_EXCEPTION;
#endif
  Transition tlx(0,ev,0);
  return THIS::ThisIterator(BASE::pSet->lower_bound(tlx));
}

// iterator EndByEv(ev) const
TEMP typename THIS::Iterator THIS::EndByEv(Idx ev) const {
#ifdef FAUDES_CHECKED
  if(typeid(Cmp)!=typeid(TransSort::EvX1X2)) 
    if(typeid(Cmp)!=typeid(TransSort::EvX2X1)) 
      SORT_EXCEPTION;
#endif
  Transition tlx(0,ev+1,0);
  return THIS::ThisIterator(BASE::pSet->lower_bound(tlx));
}

// iterator BeginByEvX1(ev,x1) const
TEMP typename THIS::Iterator THIS::BeginByEvX1(Idx ev, Idx x1) const {
#ifdef FAUDES_CHECKED
  if(typeid(Cmp)!=typeid(TransSort::EvX1X2)) 
    SORT_EXCEPTION;
#endif
  Transition tlx(x1,ev,0);
  return THIS::ThisIterator(BASE::pSet->lower_bound(tlx));
}

// iterator EndByEvX1(ev,x1) const
TEMP typename THIS::Iterator THIS::EndByEvX1(Idx ev, Idx x1) const {
#ifdef FAUDES_CHECKED
  if(typeid(Cmp)!=typeid(TransSort::EvX1X2)) 
    SORT_EXCEPTION;
#endif
  Transition tlx(x1+1,ev,0);
  return THIS::ThisIterator(BASE::pSet->lower_bound(tlx));
}

// iterator BeginByEvX2(ev,x2) const
TEMP typename THIS::Iterator THIS::BeginByEvX2(Idx ev, Idx x2) const {
#ifdef FAUDES_CHECKED
  if(typeid(Cmp)!=typeid(TransSort::EvX2X1)) 
    SORT_EXCEPTION;
#endif
  Transition tlx(0,ev,x2);
  return THIS::ThisIterator(BASE::pSet->lower_bound(tlx));
}

// iterator EndByEvX2(ev,x2) const
TEMP typename THIS::Iterator THIS::EndByEvX2(Idx ev, Idx x2) const {
#ifdef FAUDES_CHECKED
  if(typeid(Cmp)!=typeid(TransSort::EvX2X1)) 
    SORT_EXCEPTION;
#endif
  Transition tlx(0,ev,x2+1);
  return THIS::ThisIterator(BASE::pSet->lower_bound(tlx));
}

// iterator BeginByX2(x2) const
TEMP typename THIS::Iterator THIS::BeginByX2(Idx x2) const {
#ifdef FAUDES_CHECKED
  if(typeid(Cmp)!=typeid(TransSort::X2EvX1)) 
    if(typeid(Cmp)!=typeid(TransSort::X2X1Ev)) 
      SORT_EXCEPTION;
#endif
  Transition tlx(0,0,x2);
  return THIS::ThisIterator(BASE::pSet->lower_bound(tlx));
}

// iterator EndByX2(x2) const
TEMP typename THIS::Iterator THIS::EndByX2(Idx x2) const {
#ifdef FAUDES_CHECKED
  if(typeid(Cmp)!=typeid(TransSort::X2EvX1)) 
    if(typeid(Cmp)!=typeid(TransSort::X2X1Ev)) 
      SORT_EXCEPTION;
#endif
  Transition tlx(0,0,x2+1);
  return THIS::ThisIterator(BASE::pSet->lower_bound(tlx));
}

// iterator BeginByX2Ev(x2,ev) const
TEMP typename THIS::Iterator THIS::BeginByX2Ev(Idx x2, Idx ev) const {
#ifdef FAUDES_CHECKED
  if(typeid(Cmp)!=typeid(TransSort::X2EvX1)) 
    SORT_EXCEPTION;
#endif
  Transition tlx(0,ev,x2);
  return THIS::ThisIterator(BASE::pSet->lower_bound(tlx));
}

// iterator EndByX2Ev(x2,ev) const
TEMP typename THIS::Iterator THIS::EndByX2Ev(Idx x2, Idx ev) const {
#ifdef FAUDES_CHECKED
  if(typeid(Cmp)!=typeid(TransSort::X2EvX1)) 
    SORT_EXCEPTION;
#endif
  Transition tlx(0,ev+1,x2);
  return THIS::ThisIterator(BASE::pSet->lower_bound(tlx));
}

// operator+
TEMP THIS THIS::operator+ (const TTransSet<Cmp>& rOtherSet) const {
  TTransSet<Cmp> res(*this);
  res.InsertSet(rOtherSet);
  return res;
}

// operator-
TEMP THIS THIS::operator- (const TTransSet<Cmp>& rOtherSet) const {
  TTransSet<Cmp> res(*this);
  res.EraseSet(rOtherSet);
  return res;
}

     
// operator*
TEMP TTransSet<Cmp> THIS::operator* (const TTransSet<Cmp>& rOtherSet) const {
  TTransSet<Cmp> res(*this);
  res.RestrictSet(rOtherSet);
  return res;
}


// DoWrite(rw,label)
TEMP void THIS::DoWrite(TokenWriter& rTw, const std::string& rLabel, const Type* pContext) const
{
  (void) pContext;
  std::string label=rLabel;
  if(label=="") label=BASE::Name(); 
  rTw.WriteBegin(label);
  int oldcolumns = rTw.Columns();
  rTw.Columns(3);

  Iterator tit;
  for (tit = Begin(); tit != End(); ++tit) {
    rTw << tit->X1; rTw << tit->Ev; rTw << tit->X2;
  }

  rTw.WriteEnd(label);
  rTw.Columns(oldcolumns);
}


// Insert(transition)
TEMP bool THIS::Insert(const Transition& t) {
  return BASE::Insert(t);
}

// Insert(x1,ev,x2)
TEMP bool  THIS::Insert(Idx x1, Idx ev, Idx x2) {
  FD_DC("TTransSet(" << this << ")::Insert(" << x1 << "-" << ev << "-" << x2 << ")");
  return BASE::Insert(Transition(x1, ev, x2));
}

// Inject(transition)
TEMP typename THIS::Iterator THIS::Inject(const Iterator& pos, const Transition& t) {
  return BASE::Inject(pos,t);
}

// Inject(transition)
TEMP void THIS::Inject(const Transition& t) {
  BASE::Inject(t);
}


// Erase(transition)
TEMP bool THIS::Erase(const Transition& t) {
  FD_DC("TTransSet(" << this << ")::Erase(" << t.Str() << " [t])");
  return BASE::Erase(t);  
}
    
// Erase(x1,ev,x2)
TEMP bool THIS::Erase(Idx x1, Idx ev, Idx x2) {
  FD_DC("TTransSet(" << this << ")::Erase(" << x1 << "-" << ev << "-" << x2 << ")");
  return BASE::Erase(Transition(x1, ev, x2));
}

// Erase(it)
TEMP typename THIS::Iterator THIS::Erase(const Iterator& it) {
  FD_DC("TTransSet(" << this << ")::Erase(" << this->Str(*it)  << " [it])");
  return BASE::Erase(it);
}

// EraseByX1(x)
TEMP void THIS::EraseByX1(Idx x1) {
  FD_DC("TTransSet(" << this << ")::EraseByX1(" << x1 << ")");
#ifdef FAUDES_CHECKED
  if(typeid(Cmp)!=typeid(TransSort::X1EvX2)) 
    if(typeid(Cmp)!=typeid(TransSort::X1X2Ev)) 
      SORT_EXCEPTION;
#endif
  this->Detach();
  typename BASE::iterator lower, upper, it;
  Transition tl(x1,0,0);
  Transition tu(x1+1,0,0);
  lower = BASE::pSet->lower_bound(tl);
  upper = BASE::pSet->upper_bound(tu);
  if(this->AttributesSize()!=0) 
    for(it=lower; it!=upper; ++it)
      BASE::ClrAttribute(*it);
  BASE::pSet->erase(lower, upper);
}

// EraseByX1Ev(x,e)
TEMP void THIS::EraseByX1Ev(Idx x1, Idx ev) {
  FD_DC("TTransSet(" << this << ")::EraseByX1Ev(" << x1 << "," << ev << ")");
#ifdef FAUDES_CHECKED
  if(typeid(Cmp)!=typeid(TransSort::X1EvX2)) 
    SORT_EXCEPTION;
#endif
  this->Detach();
  typename BASE::iterator lower, upper, it;
  Transition tl(x1,ev,0);
  Transition tu(x1,ev+1,0);
  lower = BASE::pSet->lower_bound(tl);
  upper = BASE::pSet->upper_bound(tu);
  if(this->AttributesSize()!=0) 
    for(it=lower; it!=upper; ++it)
      BASE::ClrAttribute(*it);
  BASE::pSet->erase(lower, upper);
}

// EraseByX2(x)
TEMP void THIS::EraseByX2(Idx x2) {
  FD_DC("TTransSet(" << this << ")::EraseByX2(" << x2 << ")");
  this->Detach();
  bool doattr = (this->AttributesSize()!=0); 
  typename BASE::iterator it;
  for(it = BASE::pSet->begin(); it != BASE::pSet->end();) {
    if(it->X2 == x2) {
      if(doattr) BASE::ClrAttribute(*it);
      BASE::pSet->erase(it++);
      continue;
    }
    it++;
  }
}

// EraseByEv(ev)
TEMP void THIS::EraseByEv(Idx ev) {
  FD_DC("TTransSet(" << this << ")::EraseByEv(" << ev << ")");
  this->Detach();
  bool doattr = (this->AttributesSize()!=0); 
  typename BASE::iterator it;
  for(it = BASE::pSet->begin(); it != BASE::pSet->end();) {
    if (it->Ev == ev) {
      if(doattr) BASE::ClrAttribute(*it);
      BASE::pSet->erase(it++);
      continue;
    }
    it++;
  }
}


// EraseByX1OrX2(x)
TEMP void THIS::EraseByX1OrX2(Idx x) {
  FD_DC("TTransSet(" << this << ")::EraseByX1OrX2(" << x << ")");
  this->Detach();
  bool doattr = (this->AttributesSize()!=0); 
  typename BASE::iterator it;
  for(it = BASE::pSet->begin(); it != BASE::pSet->end();) {
    if ((it->X1 == x) || (it->X2 == x)) {
      if(doattr) BASE::ClrAttribute(*it);
      BASE::pSet->erase(it++);
      continue;
    }
    it++;
  }
  FD_DC("TTransSet(" << this << ")::EraseByX1OrX2(" << x << "): done");
}


// EraseByX1OrX2(xset)
TEMP void THIS::EraseByX1OrX2(const StateSet& rStates) {
  FD_DC("TTransSet(" << this << ")::EraseByX1OrX2(#" << rStates.Size() <<")");
  this->Detach();
  bool doattr = (this->AttributesSize()!=0); 
  typename BASE::iterator it=BASE::pSet->begin(); 
  while(it != BASE::pSet->end()) {
    if(!rStates.Exists(it->X1) &&  !rStates.Exists(it->X2)) { ++it; continue;} 
    if(doattr) BASE::ClrAttribute(*it);
    BASE::pSet->erase(it++);
  }
  FD_DC("TTransSet(" << this << ")::EraseByX1OrX2(): done");
}


// RestrictStates(xset)
TEMP void THIS::RestrictStates(const StateSet& rStates) {
  FD_DC("TTransSet(" << this << ")::RestrictByX1AndX2(#" << rStates.Size() <<")");
  this->Detach();
  bool doattr = (this->AttributesSize()!=0); 
  typename BASE::iterator it;
  it = BASE::pSet->begin(); 
  while(it != BASE::pSet->end()) {
    if(rStates.Exists(it->X1) && rStates.Exists(it->X2)) { ++it; continue;} 
    if(doattr) BASE::ClrAttribute(*it);
    BASE::pSet->erase(it++);
  }
  FD_DC("TTransSet(" << this << ")::EraseByX1OrX2(): done");
}


// RestrictEvents(eset)
TEMP void THIS::RestrictEvents(const EventSet& rEvents) {
  FD_DC("TTransSet(" << this << ")::RestrictEvents(#" << rEvents.Size() <<")");
  this->Detach();
  bool doattr = (this->AttributesSize()!=0);
  typename BASE::iterator it;
  it = BASE::pSet->begin(); 
  while(it != BASE::pSet->end()) {
    if(rEvents.Exists(it->Ev)) { ++it; continue;} 
    if(doattr) BASE::ClrAttribute(*it);
    BASE::pSet->erase(it++);
  }
  FD_DC("TTransSet(" << this << ")::RestrictEvents(): done");
}


// iterator Find(x1,ev,x2)
TEMP typename THIS::Iterator THIS::Find(Idx x1, Idx ev, Idx x2) const {
  return BASE::Find(Transition(x1,ev,x2));
}


// iterator Find(t)
TEMP typename THIS::Iterator THIS::Find(const Transition& t) const{
  return BASE::Find(t);
}

// Exists(t)
TEMP bool THIS::Exists(const Transition& t) const {
  return BASE::Exists(t);
}

// Exists(x1, ev, x2)
TEMP bool THIS::Exists(Idx x1, Idx ev, Idx x2) const {
  return BASE::Exists(Transition(x1,ev,x2));
}

// Exists(x)
TEMP bool THIS::ExistsByX1OrX2(Idx x) const {
  typename BASE::iterator it;
  for(it = BASE::pSet->begin(); it != BASE::pSet->end(); ++it) {
    if ((it->X1 == x) || (it->X2 == x)) {
      return true;
    }
  }
  return false;
}

// ExistsByX1Ev(x,e)
TEMP bool THIS::ExistsByX1Ev(Idx x1, Idx ev) const {
  FD_DC("TTransSet(" << this << ")::ExistsByX1Ev(" << x1 << "," << ev << ")");
#ifdef FAUDES_CHECKED
  if(typeid(Cmp)!=typeid(TransSort::X1EvX2)) 
    SORT_EXCEPTION;
#endif
  this->Detach();
  typename BASE::iterator lower, upper, it;
  Transition tl(x1,ev,0);
  Transition tu(x1,ev+1,0);
  lower = BASE::pSet->lower_bound(tl);
  upper = BASE::pSet->upper_bound(tu);
  return lower != upper;
}

// ExistsByX1(x)
TEMP bool THIS::ExistsByX1(Idx x1) const {
  FD_DC("TTransSet(" << this << ")::ExistsByX1(" << x1  << ")");
#ifdef FAUDES_CHECKED
  if(typeid(Cmp)!=typeid(TransSort::X1EvX2)) 
  if(typeid(Cmp)!=typeid(TransSort::X1X2Ev)) 
    SORT_EXCEPTION;
#endif
  this->Detach();
  typename BASE::iterator lower, upper, it;
  Transition tl(x1,0,0);
  Transition tu(x1+1,0,0);
  lower = BASE::pSet->lower_bound(tl);
  upper = BASE::pSet->upper_bound(tu);
  return lower != upper;
}


// ReSort(res)
TEMP template<class OtherCmp>
void THIS::ReSort(TTransSet<OtherCmp>& res) const {
  Iterator it;
  res.Clear();
  for (it = Begin(); it != End(); ++it) {
    res.Insert(*it);
  }
}

// States()
TEMP StateSet THIS::States(void) const {
  StateSet states;
  Iterator it;
  for (it=Begin(); it!=End(); ++it) {
    states.Insert(it->X1);
    states.Insert(it->X2);
  }
  return states;
}

// SuccessorStates(x1)
TEMP StateSet THIS::SuccessorStates(Idx x1) const {
#ifdef FAUDES_CHECKED
  if(typeid(Cmp)!=typeid(TransSort::X1EvX2)) 
    if(typeid(Cmp)!=typeid(TransSort::X1X2Ev)) 
      SORT_EXCEPTION;
#endif
  StateSet states;
  Iterator it = Begin(x1);
  Iterator it_end = End(x1);
  while (it != it_end) {
    states.Insert(it->X2);
    ++it;
  }
  return states;
}

// SuccessorStates(x1set)
TEMP StateSet THIS::SuccessorStates(const StateSet&  rX1Set) const {
#ifdef FAUDES_CHECKED
  if(typeid(Cmp)!=typeid(TransSort::X1EvX2)) 
    if(typeid(Cmp)!=typeid(TransSort::X1X2Ev)) 
      SORT_EXCEPTION;
#endif
  StateSet states;
  StateSet::Iterator sit= rX1Set.Begin();
  StateSet::Iterator sit_end= rX1Set.End();
  for(;sit!=sit_end; ++sit) {
    Iterator tit = Begin(*sit);
    Iterator tit_end = End(*sit);
    while(tit!=tit_end) {
      states.Insert(tit->X2);
      ++tit;
    }
  }
  return states;
}

// SuccessorStates(x1, ev)
TEMP StateSet THIS::SuccessorStates(Idx x1, Idx ev) const {
#ifdef FAUDES_CHECKED
  if(typeid(Cmp)!=typeid(TransSort::X1EvX2)) 
    SORT_EXCEPTION;
#endif
  StateSet states;
  Iterator it = Begin(x1, ev);
  Iterator it_end = End(x1, ev);
  while (it != it_end) {
    states.Insert(it->X2);
    ++it;
  }
  return states;
}

// SuccessorStates(x1set, evset)
TEMP StateSet THIS::SuccessorStates(const StateSet&  rX1Set, const EventSet& rEvSet) const {
#ifdef FAUDES_CHECKED
  if(typeid(Cmp)!=typeid(TransSort::X1EvX2)) 
    SORT_EXCEPTION;
#endif
  StateSet states;
  if(rEvSet.Empty()) return states;
  StateSet::Iterator sit= rX1Set.Begin();
  StateSet::Iterator sit_end= rX1Set.End();
  for(;sit!=sit_end; ++sit) {
    EventSet::Iterator eit= rEvSet.Begin();
    EventSet::Iterator eit_end= rEvSet.End();
    Iterator tit = Begin(*sit,*eit);
    Iterator tit_end = End(*sit);
    while(tit!=tit_end) {
      // match
      if(tit->Ev == *eit) {
        states.Insert(tit->X2);
        ++tit;
        continue;
      }
      // tit behind
      if(tit->Ev < *eit) {
        ++tit;
        continue;
      }
      // tit upfront
      ++eit;
      if(eit==eit_end) break;
    }
  }
  return states;
}

// ActiveEvents(x1,pSymTab)
TEMP EventSet THIS::ActiveEvents(Idx x1, SymbolTable* pSymTab) const {
  Iterator it = Begin(x1);
  Iterator it_end = End(x1);
  EventSet result;
  if(pSymTab!=NULL) result.SymbolTablep(pSymTab);
  for (; it != it_end; ++it) {
    result.Insert(it->Ev);
  }
  return result;
}

// Prettz printable sring
TEMP std::string THIS::Str(const Transition& rTrans) const { 
  return rTrans.Str();
} 



#undef THIS
#undef TEMP
#undef BASE

/*
*************************************************************************************************
*************************************************************************************************
* Implementation of transset with attributes
*************************************************************************************************
*************************************************************************************************
*/


/* convenience access to relevant scopes */
#define THIS TaTransSet<Attr>
#define TEMP template <class Attr>
#define BASE TTransSet<TransSort::X1EvX2>
#define ABASE TAttrMap<Transition,Attr,TransSort::X1EvX2>        

// std faudes type
FAUDES_TYPE_TIMPLEMENTATION(Void,THIS,BASE,TEMP)

// TaTransSet(void)
TEMP THIS::TaTransSet(void) : 
  BASE(),
  ABASE(this) 
{
  FD_DC("TaTransSet(" << this << ")::TaTransSet()");
}

// TaTransSet(othertransrel)
TEMP THIS::TaTransSet(const TaTransSet& rOtherSet) : 
  BASE(),
  ABASE(this)
{
  FD_DC("TaTransSet(" << this << ")::TaTransSet(rOtherSet "<< &rOtherSet <<")");
  DoAssign(rOtherSet);
}


// TaTransSet(othertransrel)
TEMP THIS::TaTransSet(const BASE& rOtherSet) :
  BASE(),
  ABASE(this) 
{
  FD_DC("TaTransSet(" << this << ")::TaTransSet(rOtherSet "<< &rOtherSet <<")");
  Assign(rOtherSet);
}


// copy to known same attributes
TEMP void THIS::DoAssign(const THIS& rSourceSet) {  
  // call base incl attributes
  BASE::DoAssign(rSourceSet);
}

// Relaxed Assign()
TEMP THIS& THIS::Assign(const TBaseSet<Transition,TransSort::X1EvX2>& rSourceSet) {
  FD_DC("TaTransSet(" << this << ")::Assign([v] " << &rSourceSet<<")");
#ifdef FAUDES_CHECKED
  FD_DC("TaTransSet(" << this << ")::Assign(): src at " << &rSourceSet);
  FD_DC("TaTransSet(" << this << ")::Assign(): src type " << typeid(rSourceSet).name());
  FD_DC("TaTransSet(" << this << ")::Assign(): dst type " << typeid(*this).name());
  const TransSet* tset = dynamic_cast<const TransSet*>(&rSourceSet);
  if(!tset) {
    std::stringstream errstr;
    errstr << "cannot cast " << typeid(rSourceSet).name() << " to TransSet" << std::endl;
    throw Exception("TaTransSet::Assign", errstr.str(), 67);
  }
#endif
  // call attribute smart base
  ABASE::AssignWithAttributes(rSourceSet);
  // done
  return *this;
}


// Insert(transition)
TEMP bool THIS::Insert(const Transition& t) {
  FD_DC("TaTransSet(" << this << ")::Insert(" << t.Str() << ")");
  return ABASE::Insert(t);
}

// Insert(x1,ev,x2)
TEMP bool THIS::Insert(Idx x1, Idx ev, Idx x2) {
  FD_DC("TaTransSet(" << this << ")::Insert(" << x1 << "-" << ev << "-" << x2 << ")");
  Transition t(x1, ev, x2);
  return ABASE::Insert(t);
}

// Insert(transition,attr)
TEMP bool THIS::Insert(const Transition& t, const Attr& attr) {
  return ABASE::Insert(t,attr);
}


// InsertSet(set)
TEMP void THIS::InsertSet(const TransSet& rOtherSet) {
  FD_DC("TaTransSet(" << this << ")::InsertSet( [a] " << &rOtherSet << ")");
  ABASE::InsertSet(rOtherSet);
}

// InsertSet(set)
TEMP void THIS::InsertSet(const TBaseSet<Transition,TransSort::X1EvX2>& rOtherSet) {
#ifdef FAUDES_CHECKED
  FD_DC("TaTransSet(" << this << ")::InsertSet(" << rOtherSet.ToString() << ")");
  const TransSet* tset = dynamic_cast<const TransSet*>(&rOtherSet);
  if(!tset) {
    std::stringstream errstr;
    errstr << "cannot cast " << typeid(rOtherSet).name() << " to TransSet" << std::endl;
    throw Exception("TaTransSet::InsertSet", errstr.str(), 67);
  }
#endif
  ABASE::InsertSet(rOtherSet);
}


// Erase(transition)
TEMP bool THIS::Erase(const Transition& t) {
  return ABASE::Erase(t);
}
    
// Erase(x1,ev,x2)
TEMP bool THIS::Erase(Idx x1, Idx ev, Idx x2) {
  FD_DC("TaTransSet(" << this << ")::Erase(" << x1 << "-" << ev << "-" << x2 << ")");
  Transition t(x1, ev, x2);
  return ABASE::Erase(t);
}

// Erase(it)
TEMP typename THIS::Iterator THIS::Erase(const Iterator& it) {
#ifdef FAUDES_CHECKED
  if (it == End()) {
    std::stringstream errstr;
    errstr << "iterator out of range " << std::endl;
    throw Exception("TTransSet::Erase", errstr.str(), 69);
  }
#endif
  return ABASE::Erase(it);
}

// EraseSet(set)
TEMP void THIS::EraseSet(const TransSet& rOtherSet) {
  FD_DC("TaTransSet(" << this << ")::RestrictSet( [a] " << &rOtherSet << ")");
  ABASE::EraseSet(rOtherSet);
}

// EraseSet(set)
TEMP void THIS::EraseSet(const TBaseSet<Transition,TransSort::X1EvX2>& rOtherSet) {
#ifdef FAUDES_CHECKED
  FD_DC("TaTransSet(" << this << ")::EraseSet(" << rOtherSet.ToString() << ")");
  const TransSet* tset = dynamic_cast<const TransSet*>(&rOtherSet);
  if(!tset) {
    std::stringstream errstr;
    errstr << "cannot cast " << typeid(rOtherSet).name() << " to TransSet" << std::endl;
    throw Exception("TaTransSet::EraseSet", errstr.str(), 67);
  }
#endif
  ABASE::EraseSet(rOtherSet);
}

// RestrictSet(set)
TEMP void THIS::RestrictSet(const TransSet& rOtherSet) {
  FD_DC("TaTransSet(" << this << ")::RestrictSet( [a] " << &rOtherSet << ")");
  ABASE::RestrictSet(rOtherSet);
}


// RestrictSet(set)
TEMP void THIS::RestrictSet(const TBaseSet<Transition,TransSort::X1EvX2>& rOtherSet) {
#ifdef FAUDES_CHECKED
  FD_DC("TaTransSet(" << this << ")::RestrictSet(" << rOtherSet.ToString() << ")");
  const TransSet* tset = dynamic_cast<const TransSet*>(&rOtherSet);
  if(!tset) {
    std::stringstream errstr;
    errstr << "cannot cast " << typeid(rOtherSet).name() << " to TransSet" << std::endl;
    throw Exception("TaTransSet::RestrictSet", errstr.str(), 67);
  }
#endif
  ABASE::RestrictSet(rOtherSet);
}



#undef THIS
#undef TEMP
#undef BASE
#undef ABASE

#undef SORT_EXECPTION

} // namespace faudes




#endif

