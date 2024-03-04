/** @file mtc_project.h

Methods for computing the natural projection of multitasking generators

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


#ifndef FAUDES_MTCPROJECT_H
#define FAUDES_MTCPROJECT_H

#include "corefaudes.h"
#include "mtc_generator.h"
#include "mtc_statemin.h"

namespace faudes {


/**
 * Make generator deterministic. (function wrapper)
 *
 * @param rGen
 *   Reference to generator
 * @param rResGen
 *   Reference to resulting deterministic generator
 *
 * <h4>Example: Converting a nondeterministic MtcSystem to a deterministic one </h4>
 * <table border=0> <tr> <td>
 *   <table width=100%>
 *     <tr> <td> <center> Original MtcSystem gen</center> </td> </tr>
 *     <tr> <td> @image html tmp_mtc_functions_2a_nondet.png </td> </tr>
 *     <tr> <td> <center> The MtcSystem contains two initial states and, leaving from state 2, it has two transitions containing the same event b which are leading to two separate states. </center> </td> </tr>
 *   </table>
 *   </td> </tr>
 *   <tr> <td>
 *   <table width=100%>
 *     <tr> <td> <center> Result of the deterministic operation </center> </td> </tr>
 *     <tr> <td> @image html tmp_mtc_functions_2b_det.png </td> </tr>
 *     <tr> <td> <center> Both initial states are combined to a single one. All color labels appearing in all original states are adapted to the new initial state. Furthermore, states are merged in that way that the generator's language stays the same, but the generator gets deterministic. </center> </td> </tr>
 *   </table>
 *   </td> </tr>
 * </table>
 *
 * @ingroup MultitaskingPlugin
 */
extern FAUDES_API void mtcDeterministic(const MtcSystem& rGen, MtcSystem& rResGen);

/**
 * Make generator deterministic. (function wrapper)
 *
 * The second parameter is an empty std::map<Idx,StateSet> which holds all
 * the pairs of new states and their respective power states set. This
 * is used as a so called "entry state map" for deterministic projected
 * generators.
 *
 * @param rGen
 *   Reference to generator
 * @param rEntryStatesMap
 *   Entry state map
 * @param rResGen
 *   Reference to resulting deterministic generator
 */
extern FAUDES_API void mtcDeterministic(const MtcSystem& rGen, std::map<Idx,StateSet>& rEntryStatesMap,
    MtcSystem& rResGen);

/**
 * Make generator deterministic. (real function)
 *
 * Second and third parameter hold the subsets + deterministic states
 * in vectors
 *
 * The multiway merge algorithm is based on a propsal in
 * "Ted Leslie, Efficient Approaches to Subset Construction, 
 *  Computer Science, University of Waterloo, 1995"
 *
 * @param rGen
 *   Reference to generator
 * @param rPowerStates
 *   Vector that holds the power states
 * @param rDetStates 
 *   Vector that holds the corresponding deterministic states
 * @param rResGen
 *   Reference to resulting deterministic generator
 */
extern FAUDES_API void mtcDeterministic(const MtcSystem& rGen, std::vector<StateSet>& rPowerStates,
    std::vector<Idx>& rDetStates, MtcSystem& rResGen);

/**
 * Project generator to alphabet rProjectAlphabet
 *
 * @param rGen
 *   Reference to generator
 * @param rProjectAlphabet
 *   Projection alphabet
 *
 * @ingroup MultitaskingPlugin
 */
extern FAUDES_API void mtcProjectNonDet(MtcSystem& rGen, const EventSet& rProjectAlphabet);

/**
 * Project generator to alphabet rProjectAlphabet
 *
 * @param rGen
 *   Reference to generator
 * @param rProjectAlphabet
 *   Projection alphabet
 * @param rResGen
 *   Reference to result
 *
 * @ingroup MultitaskingPlugin
 */
extern FAUDES_API void mtcProjectNonDet(const MtcSystem& rGen, const EventSet& rProjectAlphabet, MtcSystem& rResGen);

/**
 * Minimized Deterministic projection. This function does not modify the MtcSystem. It calls project, determine and statemin.
 *
 * @param rGen
 *   Reference to generator
 * @param rProjectAlphabet
 *   Projection alphabet
 * @param rResGen
 *   Reference to resulting deterministic generator
 *
 * <h4>Example: Projection of an MtcSystem to a specified alphabet </h4>
 * <table border=0> <tr> <td>
 *   <table width=100%>
 *     <tr> <td> <center> Original MtcSystem gen</center> </td> </tr>
 *     <tr> <td> @image html tmp_mtc_functions_3a_system.png </td> </tr>
 *     <tr> <td> <center> The projection alphabet contains the events {a, b, d}. </center> </td> </tr>
 *   </table>
 *   </td> </tr>
 *   <tr> <td>
 *   <table width=100%>
 *     <tr> <td> <center> Result of the projection </center> </td> </tr>
 *     <tr> <td> @image html tmp_mtc_functions_3b_projected.png </td> </tr>
 *     <tr> <td> <center> The resulting MtcSystem contains all events that appear in the oringinal MtcSystem and in the specified alphabet. Moreover, the resulting MtcSystem is deterministic. </center> </td> </tr>
 *   </table>
 *   </td> </tr>
 * </table>
 *
 * @ingroup MultitaskingPlugin
 */
extern FAUDES_API void mtcProject(const MtcSystem& rGen, const EventSet& rProjectAlphabet, MtcSystem& rResGen);

/**
 * Minimized Deterministic projection. Does not modify generator.
 * Calls project, determine and statemin. See functions for details.
 *
 * @param rGen
 *   Reference to generator
 * @param rProjectAlphabet
 *   Projection alphabet
 * @param rEntryStatesMap
 *   Reference to entry states map, see Deterministic(..) (result)
 * @param rResGen
 *   Reference to resulting deterministic generator (result)
 */
extern FAUDES_API void mtcProject(const MtcSystem& rGen, const EventSet& rProjectAlphabet,
		std::map<Idx,StateSet>& rEntryStatesMap, MtcSystem& rResGen);

/**
 * Inverse projection. This adds selfloop transition at every state for
 * all missing events.
 *
 * @param rGen
 *   Reference to generator
 * @param rProjectAlphabet
 *   Alphabet for inverse projection
 *
 * <h4>Example: Inverse projection of an MtcSystem for a specified alphabet which is larger than the MtcSystem's one. </h4>
 * <table border=0> <tr> <td>
 *   <table width=100%>
 *     <tr> <td> <center> Original MtcSystem </center> </td> </tr>
 *     <tr> <td> @image html tmp_mtc_functions_5_spec.png </td> </tr>
 *     <tr> <td> <center> The projection alphabet contains the events {a, b, c}. </center> </td> </tr>
 *   </table>
 *   </td> </tr>
 *   <tr> <td>
 *   <table width=100%>
 *     <tr> <td> <center> Result of the projection </center> </td> </tr>
 *     <tr> <td> @image html tmp_mtc_functions_5_spec_invpro.png </td> </tr>
 *     <tr> <td> <center> Events, that are not part of the MtcSystem's alphabet are inserted as self-loops into every state. </center> </td> </tr>
 *   </table>
 *   </td> </tr>
 * </table>
 *
 * @ingroup MultitaskingPlugin
 */
extern FAUDES_API void mtcInvProject(MtcSystem& rGen, const EventSet& rProjectAlphabet);

/**
 * RTI wrapper. See mtcInvProject(MtcSystem&, const EventSet&).
 */
extern FAUDES_API void mtcInvProject(const MtcSystem& rGen, const EventSet& rProjectAlphabet, MtcSystem& rResGen);

} // namespace faudes

#endif
