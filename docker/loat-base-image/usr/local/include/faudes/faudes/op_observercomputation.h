/** @file op_observercomputation.h 

Methods to compute natural projections that exhibit the observer property.
The observer algorithm is elaborated in
K. C. Wong and W. M. Wonham, "On the Computation of Observers in Discrete Event
Systems," Discrete Event Dynamic Systems, vol. 14, no. 1, pp. 55-107, 2004. 
In addition, methods to compute natural projections that exhibit
output control consistency (OCC) and local control consistency (LCC) are provided. See for example
K. Schmidt and C. Breindl, "On Maximal Permissiveness of Hierarchical and Modular Supervisory
Control Approaches for Discrete Event Systems," Workshop on Discrete Event Systems, 2008. 
Furthermore, an algorithm for computing natural observers without changing event labels as 
presented in 
Lei Feng; Wonham, W.M., "On the Computation of Natural Observers in Discrete-Event Systems," 
Decision and Control, 2006 45th IEEE Conference on , vol., no., pp.428-433, 13-15 Dec. 2006
is implemented.
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


#ifndef FAUDES_OP_OBSERVERCOMPUTATION_H
#define FAUDES_OP_OBSERVERCOMPUTATION_H

#include "corefaudes.h"
#include "op_debug.h"
#include <map>
#include <vector>
#include <stack>




namespace faudes {

// ================================================================================================
// Functions that compute dynamic systems for different properties related to nonblocking and 
// maximally permissive hierarchical control
// ================================================================================================


/**
 * Computation of the dynamic system for Delta_sigma (reachable states after the occurrence of one high-level event).
 * This function computes the part of the dynamic system that is needed for evaluating the observer 
 * algorithm for closed languages.
 *
 * The alphabet rHighAlph has to be a subset of the alphabet of rGen.
 * rGen must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGen
 *    Generator for which the dynamic system is computed
 * @param rHighAlph
 *    Abstraction alphabet
 * @param rGenDyn
 *    Generator representing the dynamic system
 */
extern FAUDES_API void calculateDynamicSystemClosedObs(const Generator& rGen, EventSet& rHighAlph, Generator& rGenDyn);

/**
 * Computation of the dynamic system for Delta_obs (local reachability of a marked state). 
 * This function computes the part of the dynamic system that is needed for evaluating the observer 
 * algorithm for marked languages.
 *
 * The alphabet rHighAlph has to be a subset of the alphabet of rGen.
 * rGen must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGen
 *    Generator for which the dynamic system is computed
 * @param rHighAlph
 *    Abstraction alphabet
 * @param rGenDyn
 *    Generator representing the dynamic system
 */
void calculateDynamicSystemObs(const Generator& rGen, EventSet& rHighAlph, Generator& rGenDyn);

/**
 * Computation of the dynamic system for Delta_msa (local fulfillment of the msa-observer property). 
 * This function computes the part of the dynamic system that is needed for evaluating the observer 
 * algorithm for msa-observers.
 *
 * The alphabet rHighAlph has to be a subset of the alphabet of rGen.
 * rGen must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGen
 *    Generator for which the dynamic system is computed
 * @param rHighAlph
 *    Abstraction alphabet
 * @param rGenDyn
 *    Generator representing the dynamic system
 */
extern FAUDES_API void calculateDynamicSystemMSA(const Generator& rGen, EventSet& rHighAlph, Generator& rGenDyn);

/**
 * Check if the msa-observer conditions is fulfilled for a given state.
 * This function performs a forward reachability computation to determine 
 * if the msa-observer condition is fulfilled for a given state. 
 *
 * The alphabet rHighAlph has to be a subset of the alphabet of rGen.
 * rGen must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGen
 *    Generator for which the dynamic system is computed
 * @param rHighAlph
 *    Abstraction alphabet
 * @param currentState
 *    Index of the state to be checked
 * @param rDoneStates
 *	   Set of already investigated states
 * @return 
 *	   True if the condition is fulfilled, false otherwise 
 */ 
bool recursiveCheckMSAForward(const Generator& rGen, const EventSet& rHighAlph, Idx currentState, StateSet& rDoneStates);

/**
 * Check if the msa-observer conditions is fulfilled for a given state.
 * This function performs a backward reachability computation to determine 
 * if the msa-observer condition is fulfilled for a given state. 
 *
 * The alphabet rHighAlph has to be a subset of the alphabet of rGen.
 * rGen must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGen
 *    Generator for which the dynamic system is computed
 * @param rRevTransSet
 *    Reversely ordered transition relation
 * @param rHighAlph
 *    Abstraction alphabet
 * @param currentState
 *    Index of the state to be checked
 * @param rDoneStates
 *	   Set of already investigated states
 * @return 
 *	   True if the condition is fulfilled, false otherwise 
 */ 
extern FAUDES_API bool recursiveCheckMSABackward(const Generator& rGen, const TransSetX2EvX1& rRevTransSet, const EventSet& rHighAlph, Idx currentState, StateSet& rDoneStates);

/**
 * Computation of the dynamic system for Delta_lcc (fulfillment of the local control consistency property). 
 * This function computes the part of the dynamic system that is needed for evaluating the observer 
 * algorithm for local control consistency
 *
 * The alphabet rHighAlph has to be a subset of the alphabet of rGen.
 * rGen must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGen
 *    Generator for which the dynamic system is computed
 * @param rControllableEvents
 *    Set of controllable events
 * @param rHighAlph
 *    Abstraction alphabet
 * @param rGenDyn
 *    Generator representing the dynamic system
 */
void calculateDynamicSystemLCC(const Generator& rGen, const EventSet& rControllableEvents, const EventSet& rHighAlph, Generator& rGenDyn);

/**
 * Find states that fulfill the lcc condition.
 * This function performs a backward reachability computation to determine 
 * states where the lcc condition is fulfilled
 *
 * The alphabet rHighAlph has to be a subset of the alphabet of rGen.
 * rGen must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rRevTransSet
 *    Reversely ordered transition relation
 * @param rControllableEvents
 *    Set of controllable events
 * @param rHighAlph
 *    Abstraction alphabet
 * @param currentState
 *    Index of the start state of the backward reachability computation
 * @param rDoneStates
 *	   Set of already investigated states
 * @return 
 *	   True if the condition is fulfilled, false otherwise 
 */ 
extern FAUDES_API void recursiveCheckLCC(const TransSetX2EvX1& rRevTransSet, const EventSet& rControllableEvents, const EventSet& rHighAlph, Idx currentState, StateSet& rDoneStates);

// ================================================================================================
// Functions that extend a given abstraction alphabet to achieve the observer property
// ================================================================================================


// \section ObserverF2 Functions that extend a given abstraction alphabet


/**
 * L(G)-observer computation by adding events to the high-level alphabet.
 * This function extends a given high-level alphabet such that the resulting natural projection
 * is an L(G)-observer for the prefix-closed language of the given generator. 
 * This function evaluates the natural observer algorithm as described in 
 * Lei Feng; Wonham, W.M., "On the Computation of Natural Observers in Discrete-Event Systems," 
 * Decision and Control, 2006 45th IEEE Conference on , vol., no., pp.428-433, 13-15 Dec. 2006
 *
 * The alphabet rHighAlph has to be a subset of the alphabet of rGenObs.
 * rGenObs must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGenObs
 *    Low-level generator. It is modified by the algorithm by relabeling transitions and events
 * @param rHighAlph
 *    Reference to the initial abstraction alphabet that is modified by the algorithm
 * @return
 *    number of states of the high-level generator
 *
 * <h4>Example: Computation of an L(G)-observer</h4>
 * <table class="large_image_table"> <tr> <td> <table>
 * <tr> <td> Original generator </td>  </tr>
 * <tr>
 * <td> @image html ex_natural_all.png </td>
 * </tr>
 * <tr>
 * <td> Original high-level alphabet (rHighAlph): alpha, gamma </td> </tr>
 * </table> </td> </tr> <tr> <td> <table width=100%>
 * <tr> <td> Result of calcClosedObserver(rGenObs, rHighAlph); </td> </tr>
 * <tr> <td> New high-level alphabet (rHighAlph): alpha, beta, gamma, h </td> </tr>
 * <tr> <td> @image html ex_natural_closed_proj.png </td> </tr>
 * </table> </td> </tr> </table>
 *
 * @ingroup ObserverPlugin
 */
extern FAUDES_API  Idx calcClosedObserver(const Generator& rGenObs, EventSet& rHighAlph);

/**
 * Lm(G)-observer computation by adding events to the high-level alphabet.
 * This function extends a given high-level alphabet such that the resulting natural projection
 * is an Lm(G)-observer for the marked language of the given generator. 
 * This function evaluates the natural observer algorithm as described in 
 * Lei Feng; Wonham, W.M., "On the Computation of Natural Observers in Discrete-Event Systems," 
 * Decision and Control, 2006 45th IEEE Conference on , vol., no., pp.428-433, 13-15 Dec. 2006
 *
 * The alphabet rHighAlph has to be a subset of the alphabet of rGenObs.
 * rGenObs must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGenObs
 *    Low-level generator. It is modified by the algorithm by relabeling transitions and events
 * @param rHighAlph
 *    Reference to the initial abstraction alphabet that is modified by the algorithm
 * @return
 *    number of states of the high-level generator
 *
 * <h4>Example: Computation of an Lm(G)-observer</h4>
 * <table class="large_image_table"> <tr> <td> <table>
 * <tr> <td> Original generator </td>  </tr>
 * <tr>
 * <td> @image html ex_natural_all.png </td>
 * </tr>
 * <tr>
 * <td> Original high-level alphabet (rHighAlph): alpha, gamma </td> </tr>
 * </table> </td> </tr> <tr> <td> <table width=100%>
 * <tr> <td> Result of calcNaturalObserver(rGenObs, rHighAlph); </td> </tr>
 * <tr> <td> New high-level alphabet (rHighAlph): alpha, beta, gamma, delta, h </td> </tr>
 * <tr> <td> @image html ex_natural_obs_proj.png </td> </tr>
 * </table> </td> </tr> </table>
 *
 * @ingroup ObserverPlugin
 */	
extern FAUDES_API Int calcNaturalObserver(const Generator& rGenObs, EventSet& rHighAlph);
 
/**
 * Lm(G)-observer computation including local control consistency (LCC) by adding events to the high-level alphabet.
 * This function extends a given high-level alphabet such that the resulting natural projection
 * is an Lm(G)-observer and locally control consistent (lcc) for the marked language of the given generator. 
 * This function evaluates the natural observer algorithm as described in 
 * Lei Feng; Wonham, W.M., "On the Computation of Natural Observers in Discrete-Event Systems," 
 * Decision and Control, 2006 45th IEEE Conference on , vol., no., pp.428-433, 13-15 Dec. 2006
 * and uses LCC as defined in 
 * K. Schmidt and C. Breindl, "On Maximal Permissiveness of Hierarchical and 
 * Modular Supervisory Control Approaches for Discrete Event Systems
 *
 * The alphabet rHighAlph has to be a subset of the alphabet of rGenObs.
 * rGenObs must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGen
 *    Low-level generator. It is modified by the algorithm by relabeling transitions and events
 * @param rHighAlph
 *    Reference to the initial abstraction alphabet that is modified by the algorithm
 * @param rControllableEvents
 * @return
 *    number of states of the high-level generator
 *
 * <h4>Example: Computation of an Lm(G)-observer with LCC</h4>
 * <table class="large_image_table"> <tr> <td> <table>
 * <tr> <td> Original generator </td>  </tr>
 * <tr>
 * <td> @image html ex_natural_all.png </td>
 * </tr>
 * <tr>
 * <td> Original high-level alphabet (rHighAlph): alpha, gamma; controllable events: a, f, g, h </td> </tr>
 * </table> </td> </tr> <tr> <td> <table width=100%>
 * <tr> <td> Result of calcNaturalObserverLCC(rGenObs, rControllableEvents, rHighAlph); </td> </tr>
 * <tr> <td> New high-level alphabet (rHighAlph): alpha, beta, gamma, delta, a, e, f, g, h </td> </tr>
 * <tr> <td> @image html ex_natural_obslcc_proj.png </td> </tr>
 * </table> </td> </tr> </table>
 *
 * @ingroup ObserverPlugin
 */	
extern FAUDES_API Int calcNaturalObserverLCC(const Generator& rGen, const EventSet& rControllableEvents, EventSet& rHighAlph);

/**
 * MSA-observer computation by adding events to the high-level alphabet.
 * This function extends a given high-level alphabet such that the resulting natural projection
 * is an MSA-observer for the marked language of the given generator. 
 * This function adapts the natural observer algorithm as described in 
 * Lei Feng; Wonham, W.M., "On the Computation of Natural Observers in Discrete-Event Systems," 
 * Decision and Control, 2006 45th IEEE Conference on , vol., no., pp.428-433, 13-15 Dec. 2006
 * to the msa-obsever property. 
 *
 * The alphabet rHighAlph has to be a subset of the alphabet of rGenObs.
 * rGenObs must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGen
 *    Low-level generator. It is modified by the algorithm by relabeling transitions and events
 * @param rHighAlph
 *    Reference to the initial abstraction alphabet that is modified by the algorithm
 * @return
 *    number of states of the high-level generator
 *
 * <h4>Example: Computation of an msa-observer</h4>
 * <table class="large_image_table"> <tr> <td> <table>
 * <tr> <td> Original generator </td>  </tr>
 * <tr>
 * <td> @image html ex_natural_all.png </td>
 * </tr>
 * <tr>
 * <td> Original high-level alphabet (rHighAlph): alpha, gamma </td> </tr>
 * </table> </td> </tr> <tr> <td> <table width=100%>
 * <tr> <td> Result of calcMSAObserver(rGenObs, rHighAlph); </td> </tr>
 * <tr> <td> New high-level alphabet (rHighAlph): alpha, beta, gamma, h </td> </tr>
 * <tr> <td> @image html ex_natural_msa_proj.png </td> </tr>
 * </table> </td> </tr> </table>
 *
 * @ingroup ObserverPlugin
 */	
extern FAUDES_API Int calcMSAObserver(const Generator& rGen, EventSet& rHighAlph);

/**
 * MSA-observer computation including local control consistency (LCC) by adding events to the high-level alphabet.
 * This function extends a given high-level alphabet such that the resulting natural projection
 * is an MSA-observer and locally control consistent (lcc) for the marked language of the given generator. 
 * This function adapts the natural observer algorithm as described in 
 * Lei Feng; Wonham, W.M., "On the Computation of Natural Observers in Discrete-Event Systems," 
 * Decision and Control, 2006 45th IEEE Conference on , vol., no., pp.428-433, 13-15 Dec. 2006
 * to the msa-obsever property and uses LCC as defined in 
 * K. Schmidt and C. Breindl, "On Maximal Permissiveness of Hierarchical and 
 * Modular Supervisory Control Approaches for Discrete Event Systems,
 * Workshop on Discrete Event Systems, 2008. 
 *
 * The alphabet rHighAlph has to be a subset of the alphabet of rGenObs.
 * rGenObs must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGen
 *    Low-level generator. It is modified by the algorithm by relabeling transitions and events
 * @param rControllableEvents
 * @param rHighAlph
 *    Reference to the initial abstraction alphabet that is modified by the algorithm
 * @return
 *    number of states of the high-level generator
 *
 * <h4>Example: Computation of an msa-observer with LCC</h4>
 * <table class="large_image_table"> <tr> <td> <table>
 * <tr> <td> Original generator </td>  </tr>
 * <tr>
 * <td> @image html ex_natural_all.png </td>
 * </tr>
 * <tr>
 * <td> Original high-level alphabet (rHighAlph): alpha, gamma; controllable events: a, f, g, h </td> </tr>
 * </table> </td> </tr> <tr> <td> <table width=100%>
 * <tr> <td> Result of calcMSAObserverLCC(rGenObs, rControllableEvents, rHighAlph); </td> </tr>
 * <tr> <td> New high-level alphabet (rHighAlph): alpha, beta, gamma, a, e, f, g, h </td> </tr>
 * <tr> <td> @image html ex_natural_msalcc_proj.png </td> </tr>
 * </table> </td> </tr> </table>
 *
 * @ingroup ObserverPlugin
 */	  
extern FAUDES_API Int calcMSAObserverLCC(const Generator& rGen, const EventSet& rControllableEvents, EventSet& rHighAlph);

/*

   obsolet?

    * Computation of the dynamic system for Delta_occ (fulfillment of the output control consistency property). 
    * This function computes the part of the dynamic system that is needed for evaluating the observer 
    * algorithm for output control consistency
    *
    * The alphabet rHighAlph has to be a subset of the alphabet of rGen.
    * rGen must be a deterministic generator.
    * There are no further restrictions on parameters.
    *
    * @param rGen
    *    Generator for which the dynamic system is computed
    * @param rControllableEvents
    *    Set of controllable events
    * @param rHighAlph
    *    Abstraction alphabet
    * @param rGenDyn
    *    Generator representing the dynamic system

    void calculateDynamicSystemOCC(const Generator& rGen, EventSet& rControllableEvents, EventSet& rHighAlph, Generator& rGenDyn);

*/    

/**
 * Extension of the high-level alphabet to achieve the Lm-observer property.
 * This algorithm extends the given high-level alphabet such that nondeterminism and unobservable
 * transitions in the quotient automaton computed with the current high-level alphabet are removed.
 * The function is called by calcNaturalObserver. 
 *
 * The alphabet rHighAlph has to be a subset of the alphabet of rGenObs.
 * rGenObs must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGenObs
 *    Low-level generator. It is modified by the algorithm by relabeling transitions and events
 * @param rHighAlph
 *    Reference to the initial abstraction alphabet that is modified by the algorithm
 * @param rMapStateToPartition
 *    Map from states in rGenObs to states (partitions) in the computed quotient automaton
 *
 * @ingroup ObserverPlugin
 */
extern FAUDES_API void ExtendHighAlphabet(const Generator& rGenObs, EventSet& rHighAlph,  std::map<Idx,Idx>& rMapStateToPartition);


/**
 * Check if the current alphabet splits all local automata with nondeterminims or unobservable transitions. 
 * This algorithm verifies if nondetermisisms or unobservable transitions are resolved if the given events in 
 * are added to the high-level alphabet. The function is called by ExtendHighAlphabet, 
 *
 * The alphabet rHighAlph has to be a subset of the alphabet of rGenObs.
 * rGenObs must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGenObs
 *    Low-level generator. It is modified by the algorithm by relabeling transitions and events
 * @param rSplitAlphabet
 *    Reference to the current alphabet for splitting verification
 * @param rNondeterministicStates
 *    vector with states where nondeterminism has to be resolved and the related event
 * @param entryState
 *    current state that is investigated
 */
extern FAUDES_API bool CheckSplit(const Generator& rGenObs, const EventSet& rSplitAlphabet, const std::vector<std::pair<StateSet, Idx> >& rNondeterministicStates, Idx entryState);

 
// ================================================================================================
// Functions that modify the alphabet/transitions of the generator to achieve the observer property
// ================================================================================================

//  \section ObserverF3 Functions that modify a given abstraction alphabet
 

/**
 * L(G)-observer computation.
 * This function modifies a given generator and an associated natural projection
 * such that the resulting natural projection is an L(G)-observer for the prefix-closed language of
 * the resulting generator. 
 * This function evaluates the observer algorithm as described in 
 * K. C. Wong and W. M. Wonham, "On the Computation of Observers in Discrete Event Systems," 
 * Discrete Event Dynamic Systems, vol. 14, no. 1, pp. 55-107, 2004. 
 *
 * The alphabet rHighAlph has to be a subset of the alphabet of rGenObs.
 * rGenObs must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGenObs
 *    Low-level generator. It is modified by the algorithm by relabeling transitions and events
 * @param rHighAlph
 *    Initial abstraction alphabet
 * @param rNewHighAlph
 *    Modified abstraction alphabet such that the abstraction is an Lm-observer
 * @param rMapRelabeledEvents
 *    Maps the original events to sets of newly introduced events (accumulatoive, call clear before)
 *
 * <h4>Example: Computation of an L(G)-observer</h4>
 * <table class="large_image_table"> <tr> <td> <table>
 * <tr> <td> Generator with relabeled events </td>  </tr>
 * <tr>
 * <td> @image html ex_relabel_closed_result.png </td>
 * </tr>
 * <tr>
 * <td> Original high-level alphabet (rHighAlph): alpha, beta, gamma </td> </tr>
 * </table> </td> </tr> <tr> <td> <table width=100%>
 * <tr> <td> Result of calcAbstAlphClosed(rGenObs, rHighAlph, rNewHighAlph, rMapRelabeledEvents); </td> </tr>
 * <tr> <td> New high-level alphabet (rNewHighAlph): alpha, beta, gamma, aNewHLevent_1, eNewHLevent_1, hNewHLevent_1 </td> </tr>
 * <tr> <td> @image html ex_relabel_closed_high.png</td> </tr>
 * </table> </td> </tr> </table>
 *
 * @ingroup ObserverPlugin
 */
extern FAUDES_API void calcAbstAlphClosed(System& rGenObs, EventSet& rHighAlph, EventSet& rNewHighAlph, std::map<Idx, std::set<Idx> >&  rMapRelabeledEvents);

/**
 * L(G)-observer computation.
 * This function is called by calcAbstAlphClosed(System& rGenObs, EventSet& rHighAlph, EventSet& rNewHighAlph, map<Idx, set<Idx> >&  rMapRelabeledEvents).
 * It modifies a given generator and an associated natural projection
 * such that the resulting natural projection is an L(G)-observer for the prefix-closed language of 
 * the resulting generator. 
 * This function evaluates the observer algorithm as described in 
 * K. C. Wong and W. M. Wonham, "On the Computation of Observers in Discrete Event Systems," 
 * Discrete Event Dynamic Systems, vol. 14, no. 1, pp. 55-107, 2004. 
 *
 * the alphabets rHighAlph and rControllableEvents have to be subsets of the alphabet of rGenObs
 * rGenObs must be a deterministic generator
 * no further restrictions on parameters.
 *
 * @param rGenObs
 *    Low-level generator. It is modified by the algorithm by relabeling transitions and events
 * @param rControllableEvents
 *    Set of controllable events 
 * @param rHighAlph
 *    Initial abstraction alphabet
 * @param rNewHighAlph
 *    Modified abstraction alphabet such that the abstraction is an Lm-observer
 * @param rMapRelabeledEvents
 *    Maps the original events to sets of newly introduced events (accumulatoive, call clear before)
 */
extern FAUDES_API void calcAbstAlphClosed(Generator& rGenObs, EventSet& rControllableEvents, EventSet& rHighAlph, EventSet& rNewHighAlph, std::map<Idx, std::set<Idx> >&  rMapRelabeledEvents);

/**
 * L(G)-observer computation.
 * This function is called by void calcAbstAlphClosed(Generator& rGenObs, EventSet& rControllableEvents, EventSet& rHighAlph, EventSet& rNewHighAlph, map<Idx, set<Idx> >&  rMapRelabeledEvents).
 * It modifies a given generator and an associated natural projection
 * such that the resulting natural projection is an Lm-observer for the prefix-closed language of
 * the resulting generator. 
 * This function evaluates the observer algorithm as described in 
 * K. C. Wong and W. M. Wonham, "On the Computation of Observers in Discrete Event Systems," 
 * Discrete Event Dynamic Systems, vol. 14, no. 1, pp. 55-107, 2004. 
 *
 * The alphabets rHighAlph and rControllableEvents have to be subsets of the alphabet of rGenObs.
 * rGenObs must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGenObs
 *    Low-level generator. It is modified by the algorithm by relabeling transitions and events
 * @param rControllableEvents
 *    Set of controllable events 
 * @param rHighAlph
 *    Initial abstraction alphabet
 * @param rNewHighAlph
 *    Modified abstraction alphabet such that the abstraction is an Lm-observer
 * @param rMapChangedTrans
 *    Maps the original relabeled transitions to the new events
 */
extern FAUDES_API void calcAbstAlphClosed(Generator& rGenObs, EventSet& rControllableEvents, EventSet& rHighAlph, EventSet& rNewHighAlph, std::map<Transition,Idx>& rMapChangedTrans);


/**
 * Lm-observer computation.
 * This function modifies a given generator and an associated natural projection
 * such that the resulting natural projection is an Lm-observer for the language marked by 
 * the resulting generator. 
 * This function evaluates the observer algorithm as described in 
 * K. C. Wong and W. M. Wonham, "On the Computation of Observers in Discrete Event Systems," 
 * Discrete Event Dynamic Systems, vol. 14, no. 1, pp. 55-107, 2004. 
 *
 * The alphabet rHighAlph has to be a subset of the alphabet of rGenObs.
 * rGenObs must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGenObs
 *    Low-level generator. It is modified by the algorithm by relabeling transitions and events
 * @param rHighAlph
 *    Initial abstraction alphabet
 * @param rNewHighAlph
 *    Modified abstraction alphabet such that the abstraction is an Lm-observer
 * @param rMapRelabeledEvents
 *    Maps the original events to sets of newly introduced events (accumulatoive, call clear before)
 *
 * <h4>Example: Computation of an Lm(G)-observer</h4>
 * <table class="large_image_table"> <tr> <td> <table>
 * <tr> <td> Generator with relabeled events </td>  </tr>
 * <tr>
 * <td> @image html ex_relabel_obs_result.png </td>
 * </tr>
 * <tr>
 * <td> Original high-level alphabet (rHighAlph): alpha, beta, gamma </td> </tr>
 * </table> </td> </tr> <tr> <td> <table width=100%>
 * <tr> <td> Result of calcAbstAlphObs(rGenObs, rHighAlph, rNewHighAlph, rMapRelabeledEvents); </td> </tr>
 * <tr> <td> New high-level alphabet (rNewHighAlph): alpha, beta, gamma, aNewHLevent_1, eNewHLevent_1, hNewHLevent_1 </td> </tr>
 * <tr> <td> @image html ex_relabel_obs_high.png </td> </tr>
 * </table> </td> </tr> </table>
 *
 * @ingroup ObserverPlugin
 */
extern FAUDES_API void calcAbstAlphObs(System& rGenObs, EventSet& rHighAlph, EventSet& rNewHighAlph, std::map<Idx, std::set<Idx> >&  rMapRelabeledEvents);

/**
 * Lm-observer computation.
 * This function is called by calcAbstAlphObs(System& rGenObs, EventSet& rHighAlph, EventSet& rNewHighAlph, map<Idx, set<Idx> >&  rMapRelabeledEvents).
 * It modifies a given generator and an associated natural projection
 * such that the resulting natural projection is an Lm-observer for the language marked by 
 * the resulting generator. 
 * This function evaluates the observer algorithm as described in 
 * K. C. Wong and W. M. Wonham, "On the Computation of Observers in Discrete Event Systems," 
 * Discrete Event Dynamic Systems, vol. 14, no. 1, pp. 55-107, 2004. 
 *
 * the alphabets rHighAlph and rControllableEvents have to be subsets of the alphabet of rGenObs
 * rGenObs must be a deterministic generator
 * no further restrictions on parameters.
 *
 * @param rGenObs
 *    Low-level generator. It is modified by the algorithm by relabeling transitions and events
 * @param rControllableEvents
 *    Set of controllable events 
 * @param rHighAlph
 *    Initial abstraction alphabet
 * @param rNewHighAlph
 *    Modified abstraction alphabet such that the abstraction is an Lm-observer
 * @param rMapRelabeledEvents
 *    Maps the original events to sets of newly introduced events (accumulatoive, call clear before)
 */
extern FAUDES_API void calcAbstAlphObs(Generator& rGenObs, EventSet& rControllableEvents, EventSet& rHighAlph, EventSet& rNewHighAlph, std::map<Idx, std::set<Idx> >&  rMapRelabeledEvents);

/**
 * Lm-observer computation.
 * This function is called by void calcAbstAlphObs(Generator& rGenObs, EventSet& rControllableEvents, EventSet& rHighAlph, EventSet& rNewHighAlph, map<Idx, set<Idx> >&  rMapRelabeledEvents).
 * It modifies a given generator and an associated natural projection
 * such that the resulting natural projection is an Lm-observer for the language marked by 
 * the resulting generator. 
 * This function evaluates the observer algorithm as described in 
 * K. C. Wong and W. M. Wonham, "On the Computation of Observers in Discrete Event Systems," 
 * Discrete Event Dynamic Systems, vol. 14, no. 1, pp. 55-107, 2004. 
 *
 * The alphabets rHighAlph and rControllableEvents have to be subsets of the alphabet of rGenObs.
 * rGenObs must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGenObs
 *    Low-level generator. It is modified by the algorithm by relabeling transitions and events
 * @param rControllableEvents
 *    Set of controllable events 
 * @param rHighAlph
 *    Initial abstraction alphabet
 * @param rNewHighAlph
 *    Modified abstraction alphabet such that the abstraction is an Lm-observer
 * @param rMapChangedTrans
 *    Maps the original relabeled transitions to the new events
 */
extern FAUDES_API void calcAbstAlphObs(Generator& rGenObs, EventSet& rControllableEvents, EventSet& rHighAlph, EventSet& rNewHighAlph, std::map<Transition,Idx>& rMapChangedTrans);

/**
 * MSA-observer computation.
 * This function modifies a given generator and an associated natural projection
 * such that the resulting natural projection is an msa-observer for the language marked by 
 * the resulting generator. 
 * This function evaluates the msa-observer algorithm as described in 
 * K. Schmidt and Th. Moor, "Marked String Accepting Observers for the Hierarchical and Decentralized Control of Discrete Event Systems," 
 * Workshop on Discrete Event Systems, 2006. 
 *
 * The alphabet rHighAlph has to be a subset of the alphabet of rGenObs.
 * rGenObs must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGenObs
 *    Low-level generator. It is modified by the algorithm by relabeling transitions and events
 * @param rHighAlph
 *    Initial abstraction alphabet
 * @param rNewHighAlph
 *    Modified abstraction alphabet such that the abstraction is an Lm-observer
 * @param rMapRelabeledEvents
 *    Maps the original events to sets of newly introduced events (accumulatoive, call clear before)
 *
 * <h4>Example: Computation of an MSA-observer</h4>
 * <table class="large_image_table"> <tr> <td> <table>
 * <tr> <td> Generator with relabeled events </td>  </tr>
 * <tr>
 * <td> @image html ex_relabel_msa_result.png </td>
 * </tr>
 * <tr>
 * <td> Original high-level alphabet (rHighAlph): alpha, beta, gamma </td> </tr>
 * </table> </td> </tr> <tr> <td> <table width=100%>
 * <tr> <td> Result of calcAbstAlphObs(rGenObs, rHighAlph, rNewHighAlph, rMapRelabeledEvents); </td> </tr>
 * <tr> <td> New high-level alphabet (rNewHighAlph): alpha, beta, gamma, aNewHLevent_1, eNewHLevent_1, hNewHLevent_1 </td> </tr>
 * <tr> <td> @image html ex_relabel_msa_high.png </td> </tr>
 * </table> </td> </tr> </table>
 *
 * @ingroup ObserverPlugin
 */
extern FAUDES_API void calcAbstAlphMSA(System& rGenObs, EventSet& rHighAlph, EventSet& rNewHighAlph, std::map<Idx, std::set<Idx> >&  rMapRelabeledEvents);

/**
 * MSA-observer computation.
 * This function is called by calcAbstAlphMSA(System& rGenObs, EventSet& rHighAlph, EventSet& rNewHighAlph, map<Idx, set<Idx> >&  rMapRelabeledEvents).
 * It modifies a given generator and an associated natural projection
 * such that the resulting natural projection is an MSA-observer for the language marked by 
 * the resulting generator. 
 * This function evaluates the observer algorithm as described in 
 * K. Schmidt and Th. Moor, "Marked String Accepting Observers for the Hierarchical and Decentralized Control of Discrete Event Systems," 
 * Workshop on Discrete Event Systems, 2006. 
 *
 * the alphabets rHighAlph and rControllableEvents have to be subsets of the alphabet of rGenObs
 * rGenObs must be a deterministic generator
 * no further restrictions on parameters.
 *
 * @param rGenObs
 *    Low-level generator. It is modified by the algorithm by relabeling transitions and events
 * @param rControllableEvents
 *    Set of controllable events 
 * @param rHighAlph
 *    Initial abstraction alphabet
 * @param rNewHighAlph
 *    Modified abstraction alphabet such that the abstraction is an Lm-observer
 * @param rMapRelabeledEvents
 *    Maps the original events to sets of newly introduced events (accumulatoive, call clear before)
 */
void calcAbstAlphMSA(Generator& rGenObs, EventSet& rControllableEvents, EventSet& rHighAlph, EventSet& rNewHighAlph, std::map<Idx, std::set<Idx> >&  rMapRelabeledEvents);

/**
 * MSA-observer computation.
 * This function is called by void calcAbstAlphMSA(Generator& rGenObs, EventSet& rControllableEvents, EventSet& rHighAlph, EventSet& rNewHighAlph, map<Idx, set<Idx> >&  rMapRelabeledEvents).
 * It modifies a given generator and an associated natural projection
 * such that the resulting natural projection is an MSA-observer for the language marked by 
 * the resulting generator. 
 * This function evaluates the observer algorithm as described in 
 * K. Schmidt and Th. Moor, "Marked String Accepting Observers for the Hierarchical and Decentralized Control of Discrete Event Systems," 
 * Workshop on Discrete Event Systems, 2006. 
 *
 * The alphabets rHighAlph and rControllableEvents have to be subsets of the alphabet of rGenObs.
 * rGenObs must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGenObs
 *    Low-level generator. It is modified by the algorithm by relabeling transitions and events
 * @param rControllableEvents
 *    Set of controllable events 
 * @param rHighAlph
 *    Initial abstraction alphabet
 * @param rNewHighAlph
 *    Modified abstraction alphabet such that the abstraction is an Lm-observer
 * @param rMapChangedTrans
 *    Maps the original relabeled transitions to the new events
 */
extern FAUDES_API void calcAbstAlphMSA(Generator& rGenObs, EventSet& rControllableEvents, EventSet& rHighAlph, EventSet& rNewHighAlph, std::map<Transition,Idx>& rMapChangedTrans);

// /**
//  * Lm-observer computation including output control consistency (OCC).
//  * This function modifies a given generator and an associated natural projection
//  * such that the resulting natural projection is an Lm-observer for the language marked by 
//  * the resulting generator and at the same time fulfills the output control consistency 
//  * condition (OCC). 
//  * This function evaluates the observer algorithm as described in 
//  * K. C. Wong and W. M. Wonham, "On the Computation of Observers in Discrete Event Systems," 
//  * Discrete Event Dynamic Systems, vol. 14, no. 1, pp. 55-107, 2004. 
//  * with an extension to OCC as indicated in
//  * K. Schmidt and C. Breindl, "On Maximal Permissiveness of Hierarchical and Modular Supervisory
//  * Control Approaches for Discrete Event Systems," Workshop on Discrete Event Systems, 2008. 
//  *
//  * The alphabet rHighAlph has to be a subset of the alphabet of rGenObs.
//  * rGenObs must be a deterministic generator.
//  * There are no further restrictions on parameters.
//  *
//  * @param rGenObs
//  *    Low-level generator. It is modified by the algorithm by relabeling transitions and events
//  * @param rHighAlph
//  *    Initial abstraction alphabet
//  * @param rNewHighAlph
//  *    Modified abstraction alphabet such that the abstraction is an Lm-observer
//  * @param rMapRelabeledEvents
//  *    Maps the original events to sets of newly introduced events (accumulatoive, call clear before)
//  *
//  * <h4>Example: Computation of an Lm-observer with output control consistency (OCC)</h4>
//  * <table class="large_image_table"> <tr> <td> <table>
//  * <tr> <td> Generator with relabeled events </td>  </tr>
//  * <tr>
//  * <td> @image html ex_observer_all.png </td>
//  * </tr>
//  * <tr>
//  * <td> Original high-level alphabet (rHighAlph): alpha, beta, gamma </td> </tr>
//  * </table> </td> </tr> <tr> <td> <table width=100%>
//  * <tr> <td> Result of calcAbstAlphObsOCC(rGenObs, rHighAlph, rNewHighAlph, rMapRelabeledEvents); </td> </tr>
//  * <tr> <td> New high-level alphabet (rNewHighAlph): alpha, beta, gamma, d, f, h, aNewHLevent_3, bNewHLevent_2, 
//  * cNewHLevent_2, eNewHLevent_3 </td> </tr>
//  * <tr> <td> @image html ex_synthesis_occ_result.png </td> </tr>
//  * </table> </td> </tr> </table>
//  *
//  * @ingroup ObserverPlugin
//  */
// void calcAbstAlphObsOCC(System& rGenObs, EventSet& rHighAlph, EventSet& rNewHighAlph, std::map<Idx*/,std::set<Idx > > &  rMapRelabeledEvents);

/*

 * Lm-observer computation including output control consistency (OCC).
 * This function is called by calcAbstAlphObsOCC(System& rGenObs, EventSet& rHighAlph, EventSet& rNewHighAlph, map<Idx,set<Idx > > &  rMapRelabeledEvents).
 * It modifies a given generator and an associated natural projection
 * such that the resulting natural projection is an Lm-observer for the language marked by 
 * the resulting generator and at the same time fulfills the output control consistency 
 * condition (OCC). 
 * This function evaluates the observer algorithm as described in 
 * K. C. Wong and W. M. Wonham, "On the Computation of Observers in Discrete Event Systems," 
 * Discrete Event Dynamic Systems, vol. 14, no. 1, pp. 55-107, 2004. 
 * with an extension to OCC as indicated in
 * K. Schmidt and C. Breindl, "On Maximal Permissiveness of Hierarchical and Modular Supervisory
 * Control Approaches for Discrete Event Systems," Workshop on Discrete Event Systems, 2008. 
 *
 * The alphabets rHighAlph and rControllableEvents have to be subsets of the alphabet of rGenObs.
 * rGenObs must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGenObs
 *    Low-level generator. It is modified by the algorithm by relabeling transitions and events
 * @param rControllableEvents
 *    Set of controllable events 
 * @param rHighAlph
 *    Initial abstraction alphabet
 * @param rNewHighAlph
 *    Modified abstraction alphabet such that the abstraction is an Lm-observer
 * @param rMapChangedTrans
 *    Maps the original relabeled transitions to the new events

 	void calcAbstAlphObsOCC(Generator& rGenObs, EventSet& rControllableEvents, EventSet& rHighAlph, EventSet& rNewHighAlph, std::map<Transition,Idx>& rMapChangedTrans);
*/

/**
 * Lm-observer computation including local control consistency (LCC).
 * This function modifies a given generator and an associated natural projection
 * such that the resulting natural projection is an Lm-observer for the language marked by 
 * the resulting generator and at the same time fulfills the local control consistency 
 * condition (LCC). 
 * The function evaluates the observer algorithm as described in 
 * K. C. Wong and W. M. Wonham, "On the Computation of Observers in Discrete Event Systems," 
 * Discrete Event Dynamic Systems, vol. 14, no. 1, pp. 55-107, 2004. 
 * with an extension to LCC as indicated in
 * K. Schmidt and C. Breindl, "On Maximal Permissiveness of Hierarchical and Modular Supervisory
 * Control Approaches for Discrete Event Systems," Workshop on Discrete Event Systems, 2008. 
 *
 * The alphabet rHighAlph has to be a subset of the alphabet of rGenObs.
 * rGenObs must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGenObs
 *    Low-level generator. It is modified by the algorithm by relabeling transitions and events
 * @param rHighAlph
 *    Initial abstraction alphabet
 * @param rNewHighAlph
 *    Modified abstraction alphabet such that the abstraction is an Lm-observer
 * @param rMapRelabeledEvents
 *    Maps the original events to sets of newly introduced events (accumulatoive, call clear before)
 *
 * <h4>Example: Computation of an Lm(G)-observer with local control consistency (LCC)</h4>
 * <table class="large_image_table"> <tr> <td> <table>
 * <tr> <td> Generator with relabeled events </td>  </tr>
 * <tr>
 * <td> @image html ex_relabel_obslcc_result.png </td>
 * </tr>
 * <tr>
 * <td> Original high-level alphabet (rHighAlph): alpha, beta, gamma </td> </tr>
 * </table> </td> </tr> <tr> <td> <table width="100%">
 * <tr> <td> Result of calcAbstAlphObsLCC(rGenObs, rHighAlph, rNewHighAlph, rMapRelabeledEvents); </td> </tr>
 * <tr> <td> New high-level alphabet (rNewHighAlph): alpha, beta, gamma, d, f, h, aNewHLevent_2, bNewHLevent_1, 
 * cNewHLevent_1, eNewHLevent_2, hNewHLevent_2 </td> </tr>
 * <tr> <td> @image html ex_relabel_obslcc_high.png </td> </tr>
 * </table> </td> </tr> </table>
 *
 * @ingroup ObserverPlugin
 */
extern FAUDES_API void calcAbstAlphObsLCC(System& rGenObs, EventSet& rHighAlph, EventSet& rNewHighAlph, std::map<Idx,std::set<Idx > > &  rMapRelabeledEvents);

/**
 * Lm-observer computation including local control consistency (LCC).
 * This function is called by calcAbstAlphObsLCC(System& rGenObs, EventSet& rHighAlph, EventSet& rNewHighAlph, map<Idx,set<Idx > > &  rMapRelabeledEvents).
 * It modifies a given generator and an associated natural projection
 * such that the resulting natural projection is an Lm-observer for the language marked by 
 * the resulting generator and at the same time fulfills the local control consistency 
 * condition (LCC). 
 * This function evaluates the observer algorithm as described in 
 * K. C. Wong and W. M. Wonham, "On the Computation of Observers in Discrete Event Systems," 
 * Discrete Event Dynamic Systems, vol. 14, no. 1, pp. 55-107, 2004. 
 * with an extension to LCC as indicated in
 * K. Schmidt and C. Breindl, "On Maximal Permissiveness of Hierarchical and Modular Supervisory
 * Control Approaches for Discrete Event Systems," Workshop on Discrete Event Systems, 2008. 
 *
 * The alphabets rHighAlph and rControllableEvents have to be subsets of the alphabet of rGenObs.
 * rGenObs must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGenObs
 *    Low-level generator. It is modified by the algorithm by relabeling transitions and events
 * @param rControllableEvents
 *    Set of controllable events 
 * @param rHighAlph
 *    Initial abstraction alphabet
 * @param rNewHighAlph
 *    Modified abstraction alphabet such that the abstraction is an Lm-observer
 * @param rMapChangedTrans
 *    Maps the original relabeled transitions to the new events
 */
extern FAUDES_API void calcAbstAlphObsLCC(Generator& rGenObs, EventSet& rControllableEvents, EventSet& rHighAlph, EventSet& rNewHighAlph, std::map<Transition,Idx>& rMapChangedTrans);

/**
 * MSA-observer computation including local control consistency (LCC).
 * This function modifies a given generator and an associated natural projection
 * such that the resulting natural projection is an MSA-observer for the language marked by 
 * the resulting generator and at the same time fulfills the local control consistency 
 * condition (LCC). 
 * This function evaluates the msa-observer algorithm as described in 
 * K. Schmidt and C. Breindl, "On Maximal Permissiveness of Hierarchical and 
 * Modular Supervisory Control Approaches for Discrete Event Systems,
 * Workshop on Discrete Event Systems, 2008. 
 * with an extension to LCC as indicated in
 * K. Schmidt and C. Breindl, "On Maximal Permissiveness of Hierarchical and Modular Supervisory
 * Control Approaches for Discrete Event Systems," Workshop on Discrete Event Systems, 2008. 
 *
 * The alphabet rHighAlph has to be a subset of the alphabet of rGenObs.
 * rGenObs must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGenObs
 *    Low-level generator. It is modified by the algorithm by relabeling transitions and events
 * @param rHighAlph
 *    Initial abstraction alphabet
 * @param rNewHighAlph
 *    Modified abstraction alphabet such that the abstraction is an Lm-observer
 * @param rMapRelabeledEvents
 *    Maps the original events to sets of newly introduced events (accumulatoive, call clear before)
 *
 * <h4>Example: Computation of an MSA-observer with local control consistency (LCC)</h4>
 * <table class="large_image_table"> <tr> <td> <table>
 * <tr> <td> Generator with relabeled events </td>  </tr>
 * <tr>
 * <td> @image html ex_relabel_msalcc_result.png </td>
 * </tr>
 * <tr>
 * <td> Original high-level alphabet (rHighAlph): alpha, beta, gamma </td> </tr>
 * </table> </td> </tr> <tr> <td> <table width=100%>
 * <tr> <td> Result of calcAbstAlphObsLCC(rGenObs, rHighAlph, rNewHighAlph, rMapRelabeledEvents); </td> </tr>
 * <tr> <td> New high-level alphabet (rNewHighAlph): alpha, beta, gamma, d, f, h, aNewHLevent_2, bNewHLevent_1, 
 * cNewHLevent_1, eNewHLevent_2, hNewHLevent_2 </td> </tr>
 * <tr> <td> @image html ex_relabel_msalcc_high.png </td> </tr>
 * </table> </td> </tr> </table>
 *
 * @ingroup ObserverPlugin
 */
extern FAUDES_API void calcAbstAlphMSALCC(System& rGenObs, EventSet& rHighAlph, EventSet& rNewHighAlph, std::map<Idx,std::set<Idx > > &  rMapRelabeledEvents);

/**
 * MSA-observer computation including local control consistency (LCC).
 * This function is called by calcAbstAlphMSALCC(System& rGenObs, EventSet& rHighAlph, EventSet& rNewHighAlph, map<Idx,set<Idx > > &  rMapRelabeledEvents).
 * It modifies a given generator and an associated natural projection
 * such that the resulting natural projection is an MSA-observer for the language marked by 
 * the resulting generator and at the same time fulfills the local control consistency 
 * condition (LCC). 
 * This function evaluates the observer algorithm as described in 
 * K. Schmidt and C. Breindl, "On Maximal Permissiveness of Hierarchical and 
 * Modular Supervisory Control Approaches for Discrete Event Systems,
 * Workshop on Discrete Event Systems, 2008. 
 * with an extension to LCC as indicated in
 * K. Schmidt and C. Breindl, "On Maximal Permissiveness of Hierarchical and Modular Supervisory
 * Control Approaches for Discrete Event Systems," Workshop on Discrete Event Systems, 2008. 
 *
 * The alphabets rHighAlph and rControllableEvents have to be subsets of the alphabet of rGenObs.
 * rGenObs must be a deterministic generator.
 * There are no further restrictions on parameters.
 *
 * @param rGenObs
 *    Low-level generator. It is modified by the algorithm by relabeling transitions and events
 * @param rControllableEvents
 *    Set of controllable events 
 * @param rHighAlph
 *    Initial abstraction alphabet
 * @param rNewHighAlph
 *    Modified abstraction alphabet such that the abstraction is an Lm-observer
 * @param rMapChangedTrans
 *    Maps the original relabeled transitions to the new events
 */
extern FAUDES_API void calcAbstAlphMSALCC(Generator& rGenObs, EventSet& rControllableEvents, EventSet& rHighAlph, EventSet& rNewHighAlph, std::map<Transition,Idx>& rMapChangedTrans);

/**
 * Relabeling algorithm for the computation of an Lm-observer.
 * This function checks the termination criterion of the observer algorithm. If required, transitions of
 * the input generator are relabeled.
 *
 * The alphabets rHighAlph and rControllableEvents have to be subsets of the alphabet of rGenRelabel.
 * There are no further restrictions on parameters.
 *
 * @param rGenRelabel
 *    Generator whose transitions are modified
 * @param rControllableEvents
 *    Set of controllable events
 * @param rHighAlph
 *    Abstraction alphabet
 * @param rMapStateToPartition
 *    Maps each state of rGenRelabel to an equivalence class 
 * @param rMapChangedTransReverse
 *    Maps the relabeled transitions to the original transitions
 * @param rMapChangedTrans
 *    Maps the the modified original transitions to its new events
 * @param rMapRelabeledEvents
 *    Maps the original events to the set of new events they were relabeled with
 */
bool relabel(Generator& rGenRelabel, EventSet& rControllableEvents, EventSet& rHighAlph, std::map<Idx,Idx>& rMapStateToPartition, std::map<Transition,Transition>& rMapChangedTransReverse, std::map<Transition,Idx>& rMapChangedTrans, std::map<Idx, EventSet>& rMapRelabeledEvents);

/**
 * Convenience function for relabeling events in a given generator.
 * This function inserts new events and respective transitions given by a relableing map
 * into a given generator. The function is used to adjust plant components to the relableing
 * from another plant component. 
 *
 * Technical note:  This version records newly inserted events incl. their respective controllability attribute
 * in the third parameter. T
 *
 * There are no restrictions on parameters.
 *
 * @param rGenPlant
 *    Plant component automaton
 * @param rMapRelabeledEvents
 *    Maps the original events to sets of newly introduced events
 * @param rNewEvents
 *    Returns the newly inserted events (accumulative, call clear before)
 */
extern FAUDES_API void insertRelabeledEvents(System& rGenPlant, const std::map<Idx, std::set<Idx> >&  rMapRelabeledEvents, Alphabet& rNewEvents);

/**
 * Convenience function for relabeling events in a given generator.
 * This function inserts new events and respective transitions given by a relableing map
 * into a given generator. 
 *
 * Technical note:  Recording of new events includes attributes, provided that the third parameter has a
 * compatible attribute type.
 *
 * There are no restrictions on parameters.
 *
 * @param rGenPlant
 *    Plant component automaton
 * @param rMapRelabeledEvents
 *    Maps the original events to sets of newly introduced events
 * @param rNewEvents
 *    Returns the newly inserted events (accumulative, call clear before)
 */
extern FAUDES_API void insertRelabeledEvents(Generator& rGenPlant, const std::map<Idx, std::set<Idx> >&  rMapRelabeledEvents, EventSet& rNewEvents);

/**
 * Convenience function for relabeling events in a given generator.
 * See insertRelabeledEvents(System&, const std::map<Idx, std::set<Idx> >&, Alphabet&)
 *
 * There are no restrictions on parameters.
 *
 * @param rGenPlant
 *    Plant component automaton
 * @param rMapRelabeledEvents
 *    maps the original events to sets of newly introduced events
 */
extern FAUDES_API void insertRelabeledEvents(System& rGenPlant, const std::map<Idx, std::set<Idx> >&  rMapRelabeledEvents);


/**
 * Convenience function for relabeling events in a given generator.
 * See insertRelabeledEvents(Generator&, const std::map<Idx, std::set<Idx> >&, EventSet&)
 *
 * There are no restrictions on parameters.
 *
 * @param rGenPlant
 *    Plant component automaton
 * @param rMapRelabeledEvents
 *    maps the original events to sets of newly introduced events
 */
void insertRelabeledEvents(Generator& rGenPlant, const std::map<Idx, std::set<Idx> >&  rMapRelabeledEvents);



/** 
 * Rti convenience wrapper for relabeling maps.
 *
 * The observer plugin uses an STL map from integers to sets of integers
 * as re-labeling map. In order to support this data type in the libfaudes 
 * run-time interface, we provide a wrapper class that is derived
 * from faudes Type. The implementation is minimla (no token io).
 * Later revisions may use a faudes set with set valued attributes.
 */   
class FAUDES_API EventRelabelMap : public Type {
  FAUDES_TYPE_DECLARATION(EventRelabelMap,EventRelabelMap,Type)
public:
  // std faudes type
  EventRelabelMap(void);
  EventRelabelMap(const EventRelabelMap& rOther);
  virtual ~EventRelabelMap(void);
  virtual void Clear(void);
  // access data
  const std::map<Idx, std::set<Idx> >& StlMap(void) const;
  std::map<Idx, std::set<Idx> >& StlMap(void);
  void StlMap(const std::map<Idx, std::set<Idx> >& rMap);
protected:
  // std faudes type
  virtual void DoAssign(const EventRelabelMap& rSrc);
  virtual bool DoEqual(const EventRelabelMap& rOther) const;
  // my data
  std::map<Idx, std::set<Idx> > mMap; 
};


/** 
 * Rti convenience wrapper
 */   
extern FAUDES_API void calcAbstAlphObs(
		     System& rGenObs, 
		     EventSet& rHighAlph, 
		     EventSet& rNewHighAlph, 
		     EventRelabelMap&  rMapRelabeledEvents);


/** 
 * Rti convenience wrapper
 */   
extern FAUDES_API void insertRelabeledEvents(Generator& rGenPlant, const EventRelabelMap& rMapRelabeledEvents, EventSet& rNewEvents);

/** 
 * Rti convenience wrapper
 */   
extern FAUDES_API void insertRelabeledEvents(Generator& rGenPlant, const EventRelabelMap& rMapRelabeledEvents);




} // namespace

#endif 
 
