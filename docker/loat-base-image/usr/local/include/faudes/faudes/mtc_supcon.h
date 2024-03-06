/** @file mtc_supcon.h

Supremal controllable sublanguage and controllablity

*/

/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2008  Matthias Singer
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


#ifndef MTC_SUPCON_H
#define MTC_SUPCON_H

#include "corefaudes.h"
#include "mtc_generator.h"
#include "mtc_project.h"
#include "mtc_parallel.h"
#include <stack>


namespace faudes {

/**
 * Nonblocking Supremal Controllable Sublanguage (wrapper function)
 *
 * Computes symbolic state names in resulting supervisor automaton
 * if symbolic state names are enabled in rPlantGen and rSpecGen
 *
 * @param rPlantGen
 *   Plant MtcSystem
 * @param rSpecGen
 *   Specification MtcSystem
 * @param rResGen
 *   Reference to resulting MtcSystem, the
 *   minimal restrictive nonblocking supervisor
 *
 * @exception Exception
 *   - Alphabets of generators don't match (id 500)
 *   - plant nondeterministic (id 501)
 *   - spec nondeterministic (id 503)
 *   - plant and spec nondeterministic (id 504)
 *
 * <h4>Example: Synthesis of a strongly nonblocking supervisor for a model and a corresponding specification </h4>
 * <table border=0> <tr> <td>
 *   <table width=100%>
 *     <tr> <td> <center> Model MtcSystem </center> </td> </tr>
 *     <tr> <td> @image html tmp_mtc_functions_5_plant.png </td> </tr>
 *     <tr> <td> <center> The model contains one state that results in a blocking behavior. </center> </td> </tr>
 *   </table>
 *   </td> </tr>
 *   <table width=100%>
 *     <tr> <td> <center> Specification MtcSystem </center> </td> </tr>
 *     <tr> <td> @image html tmp_mtc_functions_5_spec.png </td> </tr>
 *     <tr> <td> <center> The specification expresses, that after an event b an event c has to occur before b can happen again. Furthermore, it forbids that event c occurs before event b has taken place.
 *
 * Before being able to compute a supervisor, an inverse projection step has to be applied on the specification. It inserts self-loops for event a in both states, as the alphabets of model and specification must be identical. </center> </td> </tr>
 *   </table>
 *   </td> </tr>
 *   <tr> <td>
 *   <table width=100%>
 *     <tr> <td> <center> Strongly nonblocking supervisor </center> </td> </tr>
 *     <tr> <td> @image html tmp_mtc_functions_5_supernb.png </td> </tr>
 *     <tr> <td> <center> The synthesized supervisor ensures that the specification condition is fulfilled. That is why state 5 of the model and the corresponding transitions are erased. Observe that the operation does not make a generator nonblocking, as is shown in the example where state 3 is still existing. </center> </td> </tr>
 *   </table>
 *   </td> </tr>
 * </table>
 *
 * @ingroup MultitaskingPlugin
 */
extern FAUDES_API void mtcSupConNB(const MtcSystem& rPlantGen, const MtcSystem& rSpecGen, 
    MtcSystem& rResGen);


/** 
 * Nonblocking Supremal Controllable Sublanguage.
 * 
 * Only for deterministic plant + spec. Throws exception if plant or
 * spec is nondeterministic.
 *
 * Real mtcSupConNB function
 *
 * Finds the "largest" sublanguage of h for that language of g is
 * controllable with respect to h. Differing from theory the marked
 * language of h may not be a sublanguage of g but both must share the
 * same alphabet.
 *
 * See "C.G CASSANDRAS AND S. LAFORTUNE. Introduction to Discrete Event 
 * Systems. Kluwer, 1999." for base algorithm.
 *
 * This version creates a "reverse composition map" given as reference
 * parameter.
 * 
 * @param rPlantGen
 *   Plant MtcSystem 
 * @param rSpecGen
 *   Specification MtcSystem 
 * @param rReverseCompositionMap
 *   std::map< std::pair<Idx,Idx>, Idx> as in the parallel composition function
 * @param rResGen
 *   Reference to resulting MtcSystem, the
 *   minimal restrictive nonblocking supervisor
 *
 * @exception Exception
 *   - Alphabets of generators don't match (id 500)
 *   - plant nondeterministic (id 501)
 *   - spec nondeterministic (id 503)
 *   - plant and spec nondeterministic (id 504)
 */
extern FAUDES_API void mtcSupConNB(const MtcSystem& rPlantGen, const MtcSystem& rSpecGen, 
    std::map< std::pair<Idx,Idx>,Idx >& rReverseCompositionMap, MtcSystem& rResGen);


/**
 * Supremal Controllable Sublanguage (wrapper function)
 *
 * @param rPlantGen
 *   Plant MtcSystem
 * @param rSpecGen
 *   Specification MtcSystem
 * @param rResGen
 *   Reference to resulting MtcSystem, the
 *   minimal restrictive supervisor
 *
 * @exception Exception
 *   - Alphabets of generators don't match (id 500)
 *   - plant nondeterministic (id 501)
 *   - spec nondeterministic (id 503)
 *   - plant and spec nondeterministic (id 504)
 *
 * <h4>Example: Synthesis of a multitasking supervisor for a model and a corresponding specification. Supervisor does not take care of nonblocking behavior. </h4>
 * <table border=0> <tr> <td>
 *   <table width=100%>
 *     <tr> <td> <center> Model MtcSystem </center> </td> </tr>
 *     <tr> <td> @image html tmp_mtc_functions_5_plant.png </td> </tr>
 *     <tr> <td> <center> The model contains one state that results in a blocking behavior. </center> </td> </tr>
 *   </table>
 *   </td> </tr>
 *   <table width=100%>
 *     <tr> <td> <center> Specification MtcSystem </center> </td> </tr>
 *     <tr> <td> @image html tmp_mtc_functions_5_spec.png </td> </tr>
 *     <tr> <td> <center> The specification expresses, that after an event b an event c has to occur before b can happen again. Furthermore, it forbids that event c occurs before event b has taken place.
 *
 * Before being able to compute a supervisor, an inverse projection step has to be applied on the specification. It inserts self-loops for event a in both states, as the alphabets of model and specification must be identical. </center> </td> </tr>
 *   </table>
 *   </td> </tr>
 *   <tr> <td>
 *   <table width=100%>
 *     <tr> <td> <center> Strongly nonblocking supervisor </center> </td> </tr>
 *     <tr> <td> @image html tmp_mtc_functions_5_super.png </td> </tr>
 *     <tr> <td> <center> The supervisor synthesized by this function is strongly nonblocking. Of course, it ensures that the specification condition is fulfilled. </center> </td> </tr>
 *   </table>
 *   </td> </tr>
 * </table>
 *
 * @ingroup MultitaskingPlugin
 */
extern FAUDES_API void mtcSupConClosed(const MtcSystem& rPlantGen, const MtcSystem& rSpecGen, 
    MtcSystem& rResGen);


/** 
 * Supremal Controllable Sublanguage.
 * 
 * Only for deterministic plant + spec. Throws exception if plant or
 * spec is nondeterministic.
 *
 * Real mtcSupCon function
 *
 * Finds the "largest" sublanguage of h for that language of g is
 * controllable with respect to h. Differing from theory the marked
 * language of h may not be a sublanguage of g but both must share the
 * same alphabet.
 *
 * See "C.G CASSANDRAS AND S. LAFORTUNE. Introduction to Discrete Event 
 * Systems. Kluwer, 1999." for base algorithm.
 *
 * This version creates a "reverse composition map" given as reference
 * parameter.
 * 
 * @param rPlantGen
 *   Plant MtcSystem 
 * @param rSpecGen
 *   Specification MtcSystem 
 * @param rReverseCompositionMap
 *   std::map< std::pair<Idx,Idx>, Idx> as in the parallel composition function
 * @param rResGen
 *   Reference to resulting MtcSystem, the
 *   minimal restrictive supervisor
 *
 * @exception Exception
 *   - Alphabets of generators don't match (id 500)
 *   - plant nondeterministic (id 501)
 *   - spec nondeterministic (id 503)
 *   - plant and spec nondeterministic (id 504)
 */
extern FAUDES_API void mtcSupConClosed(const MtcSystem& rPlantGen, const MtcSystem& rSpecGen, 
    std::map< std::pair<Idx,Idx>,Idx >& rReverseCompositionMap, MtcSystem& rResGen);

/** 
 * Fast parallel composition for computation for the mtcSupConNB. 
 * Composition stops at transition paths that leave the specification
 * by uncontrollable events in plant.
 * 
 * @param rPlantGen
 *   Plant MtcSystem 
 * @param rSpecGen
 *   Specification MtcSystem 
 * @param rUAlph
 *   Uncontrollable Events
 * @param rReverseCompositionMap
 *   std::map< std::pair<Idx,Idx>, Idx> as in the parallel composition function
 * @param rResGen
 *   Reference to resulting MtcSystem, the
 *   less restrictive supervisor
 */
extern FAUDES_API void mtcSupConParallel(const MtcSystem& rPlantGen, const MtcSystem& rSpecGen,
    const EventSet& rUAlph, std::map< std::pair<Idx,Idx>, Idx>& rReverseCompositionMap, 
    MtcSystem& rResGen);

/*

  obsolete

 * Helper function for supermal controllable sublanguage computation
 * the colors of a state in the shared behavior are determined
 * 
 * @param rPlantGen
 *   Plant MtcSystem 
 * @param rSpecGen
 *   Specification MtcSystem 
 * @param SharedColors
 *   colors shared between rPlantGen and rSpecGen
 * @param currentstates
 *   std::pair<Idx,Idx> contains the current states of both generators
 * @param ComposedSet
 *   Contains the Composed ColorSet
 void ComposedColorSet(const ColorSet& SharedColors,const std::pair<Idx,Idx>& currentstates,
    const MtcSystem& rPlantGen,const MtcSystem& rSpecGen,ColorSet& ComposedSet);
*/

/**
 * Supremal Controllable Sublangauge (Real SupCon function; unchecked)
 *
 * Both, plant and spec MUST be deterministic and share the same alphabet!!!
 *
 * Most likely will result in blocking states.
 *
 * @param rPlantGen
 *   Plant generator
 * @param rCAlph
 *   Controllable events
 * @param rSupGen
 *   Specification generator
 *
 *
 * @exception Exception
 *   - Alphabets of generators don't match (id 500)
 *   - Plant generator nondeterministic (id 501)
 *   - Specification generator nondeterministic (id 503)
 *   - Plant & Spec generator nondeterministic (id 504)
 */
extern FAUDES_API void mtcSupConUnchecked(const MtcSystem& rPlantGen, const EventSet& rCAlph, MtcSystem& rSupGen);

} // namespace faudes

#endif 

