/** @file op_obserververification.h 

Methods to verify the obsrver condition for natural projections.
The observer condition is, e.g., defined in 
K. C. Wong and W. M. Wonham, “Hierarchical control of discrete-event
systems,” Discrete Event Dynamic Systems: Theory and Applications, 1996.
In addition, methods to verify output control consistency (OCC) and 
local control consistency (LCC) are provided. See for example
K. Schmidt and C. Breindl, "On Maximal Permissiveness of Hierarchical and Modular Supervisory
Control Approaches for Discrete Event Systems," Workshop on Discrete Event Systems, 2008. 
*/

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

#ifndef FAUDES_OP_OBSERVERVERIFICATION_H
#define FAUDES_OP_OBSERVERVERIFICATION_H

#include "corefaudes.h"
#include "op_debug.h"
#include "op_observercomputation.h"
#include <map>
#include <vector>
#include <stack>


namespace faudes {


/**
 * Verification of the natural observer property.
 * For verifying if a natural projection has the observer property, one step in the observer
 * algorithm is evaluated. If the resulting generator equals the input generator, then the 
 * natural projection on the abstraction alphabet is an observer. 
 *
 * @param rLowGen
 *   Input generator
 * @param rHighAlph
 *   High level alphabet
 *
 * @return
 *	true if the observer property holds
 *
 * @ingroup ObserverPlugin
 *
 */
extern FAUDES_API bool IsObs(const Generator& rLowGen, const EventSet& rHighAlph);


/**
 * Verification of the MSA observer property.
 * For verifying if a natural projection has the marked string accepting 
 * observer property, one step in the MSA observer
 * algorithm is evaluated. If the resulting generator equals the input generator, then the 
 * natural projection on the abstraction alphabet is an MSA observer. 
 *
 * @param rLowGen
 *   Input generator
 * @param rHighAlph
 *   High level alphabet
 *
 * @return
 *	true if the MSA observer property holds
 *
 * @ingroup ObserverPlugin
 *
 */
extern FAUDES_API  bool IsMSA(const Generator& rLowGen, const EventSet& rHighAlph);


/**
 * Verification of output control consistency (OCC).
 * For verifying if a natural projection fulfills the output control consistency condition,
 * a backward reachability is conducted. If starting from a state, where an uncontrollable
 * high-level event is feasible, a controllable event can be reached on a local backward path,
 * OCC is violated.
 *
 * @param rLowGen
 *   Input System
 * @param rHighAlph
 *   High level alphabet
 *
 * @return
 *	true if OCC holds
 *
 * @ingroup ObserverPlugin
 *
 */
extern FAUDES_API bool IsOCC(const System& rLowGen, const EventSet& rHighAlph);

/**
 * Verification of output control consistency (OCC).
 * For verifying if a natural projection fulfills the output control consistency condition,
 * a backward reachability is conducted. If starting from a state, where an uncontrollable
 * high-level event is feasible, a controllable event can be reached on a local backward path,
 * OCC is violated.
 *
 * @param rLowGen
 *   Input generator
 * @param rControllableEvents
 *   set of controllable events
 * @param rHighAlph
 *   High level alphabet
 *
 * @return
 *	true if OCC holds
 *
 */
extern FAUDES_API  bool IsOCC(const Generator& rLowGen, const EventSet& rControllableEvents, const EventSet& rHighAlph);

/**
 * Function that supports the verification of output control consistency (OCC).
 * This function performs a backward reachability to find if an uncontrollable 
 * high-level event is preemted by an uncontrollable low-level event. If this is 
 * the case, OCC is violated. 
 *
 * @param rLowGen
 *   Input generator
 * @param rControllableEvents
 *   set of controllable events
 * @param rHighAlph
 *   High level alphabet
 * @param currentState
 *   start state for backward reachability
 *
 * @return
 *	true if no controllable low-level event has been found
 *
 */
extern FAUDES_API bool backwardVerificationOCC(const Generator& rLowGen, const EventSet& rControllableEvents, const EventSet& rHighAlph, Idx currentState);

/**
 * Verification of local control consistency (LCC).
 * For verifying if a natural projection fulfills the local control consistency condition,
 * a backward reachability is conducted. If starting from a state, where an uncontrollable
 * high-level event is feasible, at least one local state cannot be reached by an uncontrollable path, LCC is violated.
 *
 * @param rLowGen
 *   Input System
 * @param rHighAlph
 *   High level alphabet
 *
 * @return
 *	true if LCC holds
 *
 * @ingroup ObserverPlugin
 *
 */
extern FAUDES_API bool IsLCC(const System& rLowGen, const EventSet& rHighAlph);

/**
 * Verification of local control consistency (LCC).
 * For verifying if a natural projection fulfills the local control consistency condition,
 * a backward reachability is conducted. If starting from a state, where an uncontrollable
 * high-level event is feasible, at least one local state cannot be reached by an uncontrollable path, LCC is violated.
 *
 * @param rLowGen
 *   Input generator
 * @param rControllableEvents
 *   set of controllable events
 * @param rHighAlph
 *   High level alphabet
 *
 * @return
 *	true if LCC holds
 *
 */
extern FAUDES_API bool IsLCC(const Generator& rLowGen, const EventSet& rControllableEvents, const EventSet& rHighAlph);

/**
 * Function that supports the verification of local control consistency (LCC).
 * This function performs a recursive backward reachability to find if from a state where
 * an uncontrollable high-level event is possible, another state is only reachable
 * by local strings that contaion at least one controllable event. If this is 
 * the case, LCC is violated. 
 *
 * @param rTransSetX2EvX1
 *   reverse transition relation of the input generator
 * @param rControllableEvents
 *   set of controllable events
 * @param rHighAlph
 *   High level alphabet
 * @param exitState
 *   start state for backward reachability
 * @param currentState
 *   current state for backward reachability
 * @param controllablePath
 *   false if at least one uncontrollable path to the currentState exists
 * @param rLocalStatesMap
 *   map for states and their controllability property
 * @param rDoneStates
 *   states that have already been visited
 *
 */
extern FAUDES_API void backwardVerificationLCC(const TransSetX2EvX1& rTransSetX2EvX1, const EventSet& rControllableEvents, const EventSet& rHighAlph, Idx exitState, Idx currentState, bool controllablePath, std::map<Idx, bool>& rLocalStatesMap, StateSet& rDoneStates);





} // namespace faudes



#endif

