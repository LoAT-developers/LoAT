/** @file op_observercomputation.h 

Methods to compute natural projections that exhibit the obsrver property.
The observer algorithm is elaborated in
K. C. Wong and W. M. Wonham, "On the Computation of Observers in Discrete Event
Systems," Discrete Event Dynamic Systems, vol. 14, no. 1, pp. 55-107, 2004. 
and the natural observer algorithm is presented in
Feng, Lei   and Wonham, W., "On the Computation of Natural Observers in Discrete-Event Systems", Discrete Event Dynamic Systems, 2009. 
In addition, methods to compute natural projections that exhibit
output control consistency (OCC) and local control consistency (LCC) are provided. See for example
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

#ifndef FAUDES_MTCOBSERVERVERCOMPUTATION_H
#define FAUDES_MTCOBSERVERVERCOMPUTATION_H

#include "corefaudes.h"
#include "op_include.h"
#include "mtc_generator.h"
//#include "mtc_debug.h"




namespace faudes {
	/**
	* Calculate a colored natural observer by extending a given high-level alphabet.
	* This function extends a given high-level alphabet such that the corresponding natural
	* projection becomes a colored observer for a given colored marking generator. 
	* The function calls the function ExtendHighAlphabet in the Observer plugin. 
	*
	* @param rGen
	*  input colored marking generator
	* @param rHighAlph
	*  high-level alphabet that is extended towards a colored observer
	* @return
	*  number of states of the high-level colored marking generator
	*
	* <h4>Example: Computation of an Lm-observer</h4>
	* <table border=0> <tr> <td> <table>
	* <tr> <td> Original generator </td>  </tr>
	* <tr>
	* <td> @image html tmp_mtc_cb4mh1d1_1_sup.png </td>
	* </tr>
	* <tr>
      * <td> Original high-level alphabet (rHighAlph): cb4-cb12, cb12-cb4, cb11-cb4, cb4-cb11 </td> </tr>
	* </table> </td> </tr> <tr> <td> <table width=100%>
	* <tr> <td> Result of calcNaturalObserver(rGenObs, rHighAlph); </td> </tr>
	* <tr> <td> New high-level alphabet (rNewHighAlph): cb4-cb12, cb12-cb4, cb11-cb4, cb4-cb11, mh1end </td> </tr>
	* <tr> <td> @image html tmp_mtc_cb4mh1d1_2.png </td> </tr>
	* </table> </td> </tr> </table>
	*
	* @ingroup MultitaskingPlugin 
	*/
	extern FAUDES_API Idx calcNaturalObserver(const MtcSystem& rGen, EventSet& rHighAlph);

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
	* @ingroup ObserverPlugin
	*/
	void calcAbstAlphObs(MtcSystem& rGenObs, EventSet& rHighAlph, EventSet& rNewHighAlph, std::map<Idx, std::set<Idx> >&  rMapRelabeledEvents);

   /**
	* Lm-observer computation.
	* This function is called by calcAbstAlphObs(System& rGenObs, EventSet& rHighAlph, EventSet& rNewHighAlph, std::map<Idx, std::set<Idx> >&  rMapRelabeledEvents).
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
    extern FAUDES_API void calcAbstAlphObs(MtcSystem& rGenObs, EventSet& rControllableEvents, EventSet& rHighAlph, EventSet& rNewHighAlph, std::map<Idx, std::set<Idx> >&  rMapRelabeledEvents);

   /**
	* Lm-observer computation.
	* This function is called by void calcAbstAlphObs(Generator& rGenObs, EventSet& rControllableEvents, EventSet& rHighAlph, EventSet& rNewHighAlph, std::map<Idx, std::set<Idx> >&  rMapRelabeledEvents).
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
    extern FAUDES_API void calcAbstAlphObs(MtcSystem& rGenObs, EventSet& rControllableEvents, EventSet& rHighAlph, EventSet& rNewHighAlph, std::map<Transition,Idx>& rMapChangedTrans);

   /**
    * Computation of the dynamic system for an Lm-observer.
    * This function computes the dynamic system that is needed for evaluating the observer 
    * algorithm.
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
    extern FAUDES_API void calculateDynamicSystemObs(const MtcSystem& rGen, EventSet& rHighAlph, Generator& rGenDyn);


}


#endif 
 
