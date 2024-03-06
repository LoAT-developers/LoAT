/** @file cfl_graphfncts.h Operations on (directed) graphs. */

/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2009  Thomas Moor, Klaus Schmidt, Sebastian Perk
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


#ifndef FAUDES_GRAPHFNCTS_H
#define FAUDES_GRAPHFNCTS_H

#include "cfl_definitions.h"
#include "cfl_generator.h"
#include <stack>

namespace faudes {


/**
 * Filter for strictly connected components (SCC) search/compute routines.
 *
 * When ComputeScc()/HasScc()/NextScc()  traverse a specified transition sytem in their
 * search, a SccFilter parameter can mute certain transitions. The respective
 * filter conditions are set by the constructor and consist of a flag word (mMode)
 * and additional parameters (depending on the flags). The Flags can be combined
 * from the following: 
 *
 * - NoFilter: std textbook beheviour;
 * - FindFirst: stop the search after one SCC has been found;
 * - IgnoreTrivial: dont report singleton SCCs without selfloop;
 * - StatesAvoid: mute specified states from trasition structure;
 * - StatesRequire: dont report SCCs that fail to contain at least one state from the specified set;
 * - EventsAvoid: mute any transitions with an event label from the specified set.
 *
 * Convenience modes set up the state related filter conditions from the set of marked states:
 *
 * - IgnoreLiveLocks: set StatesRequire to the marked states of a specified Generator;
 * - LiveLocksOnly: set StatesAvoid to the marked states of a specified Generator;
 * - IgnoreUnaccessible: initialise todo list with accessible states only.
 *
 * Technical note: SccFilters interally use references to condition 
 * parameters that are required to exist during the life time of the filter object. 
 *
 * Technical note: currently, there is no EventsRequire filter because the implementation 
 * interprets the transition relation primarily from a directed graph perspective; while StatesRequire
 * makes sense for marked states semantics, we are not aware of any applications for
 * a corresponding version of EventsRequire; please let us know if you require such an extension. 
 *
 * @ingroup GeneratorFunctions
 */
class FAUDES_API SccFilter {

  // Allow search function access
  friend FAUDES_API void SearchScc(
    const Idx vState,           
    int& vRcount,               
    const Generator& rGen,      
    const SccFilter& rFilter,
    StateSet&  rTodo,           
    std::stack<Idx>& rStack,    
    StateSet& rStackStates,     
    std::map<const Idx, int>& rDfn,
    std::map<const Idx, int>& rLowLnk, 
    std::list<StateSet>& rSccList,  
    StateSet& rRoots);       
  friend FAUDES_API bool ComputeNextScc(
    const Generator& rGen,
    SccFilter& rFilter,
    StateSet& rScc
  );

public:

  /** Typedef for filter modes */
  typedef enum { 
    FmNoFilter=0x00,             //// no filters at all (default)
    FmFindFirst=0x01,            //// only report first valid SCC
    FmIgnoreTrivial=0x02,        //// ignore non-cycles, aka singletons without selfloop
    FmStatesAvoid=0x10,          //// filter by avoiding specified states
    FmStatesRequire=0x20,        //// filter by requireing specified states
    FmEventsAvoid=0x40,          //// filter by avoiding specified events
    FmIgnoreLiveLocks=0x1000,    //// ignore cycles with unmarked states only
    FmLiveLocksOnly =0x2000,     //// ignore cycles with one or more marked states
    FmIgnoreUnaccessible=0x4000  //// only inspect accessible part
  } FMode;

  /** Constructor (no filter) */
  SccFilter(void);

  /** Constructor (copy constructor) */
  SccFilter(const SccFilter& rSrc);

  /** Constructor (from flags w.r.t. Generator) */
  SccFilter(int mode, const Generator& rGen);

  /** Constructor (from flags and state set, either avoid or require) */
  SccFilter(int mode, const StateSet& rStatesAvoidRequire);

  /** Constructor (from flags and state sets) */
  SccFilter(int mode, const StateSet& rStatesAvoid, const StateSet& rStatesRequire);

  /** Constructor (from flags and event sets) */
  SccFilter(int mode, const EventSet& rEventsAvoid);

  /** Constructor (from flags and sets) */
  SccFilter(int mode, const StateSet& rStatesAvoid, const StateSet& rStatesRequire, 
     const EventSet& rEventsAvoid);

  /** Destructor */
  ~SccFilter(void);

  /** Member access */
  int Mode(void) const { return mMode;};

  /** Member access */
  const StateSet& StatesAvoid(void) const { return *pStatesAvoid;};

  /** Member access */
  const StateSet& StatesRequire(void) const { return *pStatesRequire;};

  /** Edit filter (RTI): no filter */
  void Clear(void);

  /** Edit filter (RTI): set avoid states */
  void StatesAvoid(const StateSet& rStatesAvoid);

  /** Edit filter (RTI): set required states */
  void StatesRequire(const StateSet& rStatesRequire);

  /** Edit filter (RTI): set avoid events */
  void EventsAvoid(const EventSet& rEventsAvoid);

  /** Edit filter (RTI): ignore trivial */
  void IgnoreTrivial(bool flag);  

  /** Edit filter (RTI): find first */
  void FindFirst(bool flag);  


protected:

  /** Edit filter (RTI): avoid states */
  void MergeStatesAvoid(const StateSet& rStatesAvoid);

  /** Flag, combining bit masks from Mode */
  int mMode; 
  /** States to avoid (if flag StatesAvoid is set) */
  const StateSet* pStatesAvoid;
  /** States to require (if flag StatesRequire is set) */
  const StateSet* pStatesRequire;
  /** Events to avoid (if flag EventssAvoid is set) */
  const EventSet* pEventsAvoid;

  /** Local sets (optional) */
  StateSet* mpStatesAvoid;
  StateSet* mpStatesRequire;
  EventSet* mpEventsAvoid;

  /** Static emptysets */
  const static StateSet msEmptyStates;
  const static EventSet msEmptyEvents;
};


/**
 *
 * Search for strongly connected components (SCC). 
 * 
 * This function partitions the stateset of a generator into equivalent 
 * classes such that states x1 and x2 are equivalent iff there is a path from x1
 * to x2 AND a path from x2 to x1. 
 *
 * This function implements the algorithm based on a recursive depth first search
 * presented in:
 *
 * -- Aho, Hopcroft, Ullman: The Design and Analysis of Computer Algorithms --
 *
 * While the original algorithm works on a directed graph, this
 * implementation adds some features that refer to transition systems and
 * allow to filter SCCs on the run. The filter condition is specified by the
 * SccFilter parameter rFilter.
 *
 * Note: this version is derived from earlier implementations used in 
 * various plug-ins; in due course, this version will replace earlier versions. 
 *
 * Note: Due to the recursive implementation, this function requires a stack 
 * size proportional to the largest SCC. We have experienced typical default
 * configurations to be good for a depth of about 80000 (Mac OSX 10.6, Debian 7.4). 
 * For SCCs exceeding the default stack size, you may adjust the operating system 
 * parameters accordingly. On Unix/Linux/MacOsX this is done by the shell command 
 * "ulimit -s hard". A future revision of SearchSCC() may be re-designed to
 * circumvent this inconvenient issue.
 *
 * Note: for a convenience API see also ComputeScc()
 *
 * @param vState
 *   State, from which the current recursion is started.
 * @param vRcount
 *   Denotes the current depth of the recursion.
 * @param rGen
 *   Transition system to investigate
 * @param rFilter
 *   Filter out specified transitions
 * @param rTodo
 *   Set of states that up to now were not found by the
 *   depth first search.
 * @param rStack
 *   Stack of states to represent current path.
 * @param rStackStates
 *   Set of states that are in rStack
 * @param rDfn
 *   Map assigning to each state idx its Depth-First Number.
 * @param rLowLnk
 *   Map assigning to each state its LOWLINK Number.
 * @param rSccList
 *   Set SCCs (accumulative result).
 * @param rRoots
 *   Set of states that each are root of some SCC (accumulative result).
 *
 * 
 */
extern FAUDES_API void SearchScc(
  const Idx vState,           
  int& vRcount,               
  const Generator& rGen,      
  const SccFilter& rFilter,
  StateSet&  rTodo,           
  std::stack<Idx>& rStack,    
  StateSet& rStackStates,     
  std::map<const Idx, int>& rDfn,
  std::map<const Idx, int>& rLowLnk, 
  std::list<StateSet>& rSccList,  
  StateSet& rRoots);       


/**
 * Compute strongly connected components (SCC) 
 *
 * This function is a API wrapper that calls the recursive implementation
 * SearchScc().
 *
 * 
 * @param rGen
 *   Generator under investigation
 * @param rFilter
 *   Filter specified transitions
 * @param rSccList
 *   List of SCCs (result)
 * @param rRoots
 *   Set of states that each are root of some SCC (result).
 *
 * @return
 *   True if SCCs have been found, false if not.
 *
 * @ingroup GeneratorFunctions
 * 
 */
extern FAUDES_API bool ComputeScc(
  const Generator& rGen,
  const SccFilter& rFilter,
  std::list<StateSet>& rSccList,
  StateSet& rRoots);


/**
 * Compute strongly connected components (SCC) 
 *
 * This function is a API wrapper that calls the recursive implementation
 * SearchScc().
 *
 * @param rGen
 *   Generator under investigation
 * @param rSccList
 *   List of SCCs (result)
 * @param rRoots
 *   Set of states that each are root of some SCC (result).
 *
 * @return
 *   True if SCCs have been found, false if not.
 *   Since there are no filters, true is returned iff the
 *   the state set is non-empty.
 *
 * @ingroup GeneratorFunctions
 * 
 */
extern FAUDES_API bool ComputeScc(
  const Generator& rGen,
  std::list<StateSet>& rSccList,
  StateSet& rRoots);
  

  
/**
 * Compute strongly connected component (SCC) 
 *
 * This function is a API wrapper that calls the recursive implementation
 * SearchScc(). It internally edits the filter to require the specified
 * initial state and to stop on the first SCC found. In particular, any
 * other state requirement will be ignored.
 *
 * @param rGen
 *   Generator under investigation
 * @param rFilter
 *   Filter specified transitions
 * @param q0
 *   Initial state for SCC.
 * @param rScc
 *   SCC (result)
 *
 * @return
 *   True if an SCC has been found, false if not.
 *
 * @ingroup GeneratorFunctions
 * 
 */
extern FAUDES_API bool ComputeScc(
  const Generator& rGen,
  const SccFilter& rFilter,
  Idx q0, 
  StateSet& rScc
);



/**
 * Compute one strongly connected component (SCC) 
 *
 * This functions searchs for the first SCC of the generator rGen 
 * while applying the filter rFilter; see SCCFilter for details.
 *
 * Technically, this function is a API wrapper that calls the recursive implementation
 * SearchScc() as presented in 
 *
 * -- Aho, Hopcroft, Ullman: The Design and Analysis of Computer Algorithms --
 * 
 * @param rGen
 *   Generator under investigation
 * @param rFilter
 *   Filter out specified transitions
 * @param rScc
 *   First SCC that has been found, empty if no such.
 *
 * @return
 *   True if SCCs have been found, false if not.
 *
 * @ingroup GeneratorFunctions
 * 
 */

extern FAUDES_API bool ComputeScc(
  const Generator& rGen,
  const SccFilter& rFilter,
  StateSet& rScc
);

/**
 * Test for strongly connected components (SCC) 
 *
 * This functions searchs for the first SCC of the generator rGen 
 * while applying the filter rFilter; see SCCFilter for details.
 *
 * Technically, this function is an API wrapper that calls the recursive implementation
 * SearchScc() as presented in 
 * 
 * -- Aho, Hopcroft, Ullman: The Design and Analysis of Computer Algorithms --
 *
 * @param rGen
 *   Generator under investigation
 * @param rFilter
 *   Filter out specified transitions
 *
 * @return
 *   True if SCCs have been found, false if not.
 *
 * @ingroup GeneratorFunctions
 * 
 */
extern FAUDES_API bool HasScc(
  const Generator& rGen,
  const SccFilter& rFilter
);


/**
 * Compute next SCC
 *
 * This function provides an API for the iterative computation
 * of SCCs. It invokes SearchScc() to find the next SCC and then
 * adds the SCC to the StatesAvoid Filter. This approach is 
 * not computationally efficient but it allows for simple Lua wrappers.
 *    
 * @param rGen
 *   Generator under investigation
 * @param rFilter
 *   Filter out specified transitions
 * @param rScc
 *   First SCC that has been found, empty if no such.
 *
 * @return
 *   True if an SCC has been found, false if not.
 *
 * @ingroup GeneratorFunctions
 * 
 */
extern FAUDES_API bool ComputeNextScc(
  const Generator& rGen,
  SccFilter& rFilter,
  StateSet& rScc
);

} // namespace
#endif
