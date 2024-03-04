/** @file cfl_localgen.h Helper functions for projected generators */

/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2006  Bernd Opitz
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


#ifndef FAUDES_LOCALGEN_H
#define FAUDES_LOCALGEN_H


#include "cfl_agenerator.h"
#include <map>
#include <stack>

namespace faudes {

/**
 * LowExitStates return-copy function:
 *
 * Wrapper for the corresponding call-by-reference function. 
 * Creates new StateSet, calls function and returns StateSet containing low level
 * exit states.
 *
 * @param rLowGen 
 *   Low level generator (just needed for determining statetable)
 * @param rHighAlph
 *   High level events
 * @param rEntryStatesMap
 *   Entry states map (see CreateEntryStatesMap(resmap))
 * @param rLowRevTransRel
 *   Reverse sorted low level transition relation
 * @param highState
 *   Hi level state for which to compute low level exit states
 *
 * @exception Exception
 *   Hi level state not found in entry states map (with FAUDES_CHECKED) (id 502)
 */
extern FAUDES_API StateSet LowExitStates(const Generator& rLowGen, const EventSet& rHighAlph, 
		const std::map<Idx,StateSet>& rEntryStatesMap, const TransSetX2EvX1& rLowRevTransRel, Idx highState);

/**
 * LowExitStates call-by-reference function:
 *
 * Compute the low level exit states for a corresponding hi level state
 *
 * @param rHighAlph
 *   High level events
 * @param rEntryStatesMap
 *   Entry states map (see CreateEntryStatesMap(resmap))
 * @param rLowRevTransRel
 *   Reverse sorted low level transition relation
 * @param highState
 *   Hi level state for which to compute low level exit states
 * @param rLowExitStates
 *   Reference to StateSet for low level exit states (result)
 *
 * @exception Exception
 *   Hi level state not found in entry states map (with FAUDES_CHECKED)
 */
extern FAUDES_API void LowExitStates(const EventSet& rHighAlph, const std::map<Idx,StateSet>& rEntryStatesMap, 
		const TransSetX2EvX1& rLowRevTransRel, Idx highState, StateSet& rLowExitStates);

/**
 * ReachableEvents return-copy function:
 *
 * Wrapper for the corresponding call-by-reference function. 
 * Creates new EventSet, calls function and returns EventSet containing the
 * reachable hi level events.
 *
 * @param rLowGen
 *   Low level generator
 * @param rHighAlph
 *   High level alphabet
 * @param lowState
 *   Low level state 
 */
extern FAUDES_API EventSet ReachableEvents(const Generator& rLowGen, const EventSet& rHighAlph, 
		Idx lowState);

/**
 * ReachableEvents call-by-reference function:
 *
 * Compute the set of hi level events which can be reached from a low
 * level state. Resulting set will be cleared first.
 *
 * @param rLowGen
 *   Low level generator
 * @param rHighAlph
 *   High level alphabet
 * @param lowState
 *   Low level state 
 * @param rReachableEvents
 *   Reference to EventSet which will contain the reachable high level events
 *   (result)
 */
extern FAUDES_API void ReachableEvents(const Generator& rLowGen, const EventSet& rHighAlph, 
		Idx lowState, EventSet& rReachableEvents);

/**
 * Compute the coaccessible reach for a local automaton.
 *
 * @param rRevTransRel
 *   Reverse sorted transition relation
 * @param rHighAlph
 *   High level alphabet
 * @param lowState
 *   Low level exit state
 * @param rCoaccessibleReach
 *   Result 
 */
extern FAUDES_API void LocalCoaccessibleReach(const TransSetX2EvX1& rRevTransRel, 
		const EventSet& rHighAlph, Idx lowState, StateSet& rCoaccessibleReach);

/**
 * Compute the accessible reach for a local automaton
 *
 * @param rLowGen
 *   Low level generator
 * @param rHighAlph
 *   High level alphabet
 * @param lowState
 *   Low level entry state
 * @param rAccessibleReach
 *   Result
 */
extern FAUDES_API void LocalAccessibleReach(const Generator& rLowGen, const EventSet& rHighAlph, 
		Idx lowState, StateSet& rAccessibleReach);

} // namespace faudes

#endif 

