/** @file cfl_determin.h powersetset construction */

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


#ifndef FAUDES_DETERMIN_H
#define FAUDES_DETERMIN_H


#include "cfl_definitions.h"
#include "cfl_agenerator.h"

namespace faudes {


/**
 * Make initial states unique.
 * If the argument generator has precisely one initial state, this function does nothing. 
 * Else, this function introduces a new and unique initial state and relinks transitions
 * accordinly. If the argument generator used to have more than one initial state, this operation
 * may render the output nondeterministic. If the argument generator used to have no
 * initial state, the output generator will generate the empty string language as opposed to
 * the empty language. Otherwise, generated and marked languages are preserved. 
 *
 * Note: call this function followed by determine to convert the generator to a
 * deterministic generator with exactly one initial state.
 *
 *
 * @param rGen
 *   Reference to generator
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void UniqueInit(Generator& rGen);

/**
 * Make initial states unique.
 *
 * Convenience wrapper for UniqueInit(Generator&).
 *
 *
 * @param rGen
 *   Reference to generator
 * @param rResGen
 *   Reference to resulting generator
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void UniqueInit(const Generator& rGen, Generator& rResGen);


/**
 * Make generator deterministic.
 * Constructs a deterministic generator while preserving the generated and marked languages.
 * The implementation is based on the so called multiway merge variant of subset construction, 
 * in which the new state set becomes a subset of the power set og the given state set. It is of
 * exponential complexity. For details on the multiway merge algorithm see
 * "Ted Leslie, Efficient Approaches to Subset Construction, 
 *  Computer Science, University of Waterloo, 1995".
 *
 * See also 
 * Deterministic(const Generator&,std::map<Idx,StateSet>&,Generator& rResGen) and
 * Deterministic(const Generator&,std::vector<StateSet>&,std::vector<Idx>&,Generator& rResGen).
 *
 * Technical detail: if the input has no initial state, then so has the output. 
 * 
 * @param rGen
 *   Reference to generator
 * @param rResGen
 *   Reference to resulting deterministic generator
 *
 * <h4>Example:</h4>
 * <table>
 * <tr> <td> Generator G </td> <td> Deterministic(G,Result) </td> </tr>
 * <tr>
 * <td> @image html tmp_deterministic_nondet.png </td>
 * <td> @image html tmp_deterministic_det.png </td>
 * </tr>
 * </table> 
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void Deterministic(const Generator& rGen, Generator& rResGen);

/**
 * Make generator deterministic.
 *
 * See also Deterministic(const Generator&, Generator&).
 * This version maintains event attributes provided they can be castes
 * to the result type.
 *
 * @param rGen
 *   Reference to generator
 * @param rResGen
 *   Reference to resulting deterministic generator
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void aDeterministic(const Generator& rGen, Generator& rResGen);

/**
 * Make generator deterministic.
 *
 * Constructs a deterministic generator while preserving the generated and marked languages.
 * See Deterministic(const Generator&,Generator& rResGen) for the intended
 * api. This version provides as a second parameter the resulting map from new states to
 * their respective original state set. It is used as a so called "entry state map" 
 * for deterministic projected generators.
 *
 * @param rGen
 *   Reference to generator
 * @param rEntryStatesMap
 *   Entry state map
 * @param rResGen
 *   Reference to resulting deterministic generator
 */
extern FAUDES_API void Deterministic(const Generator& rGen, std::map<Idx,StateSet>& rEntryStatesMap,
			 Generator& rResGen);

/**
 * Make generator deterministic. 
 *
 * Constructs a deterministic generator while preserving the generated and marked languages.
 * See Deterministic(const Generator&,Generator& rResGen) for the intended api. 
 * This version provides as second and third parameters the correspondence 
 * between new states and the original state sets.
 * in vectors
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
extern FAUDES_API void Deterministic(const Generator& rGen, std::vector<StateSet>& rPowerStates, 
			 std::vector<Idx>& rDetStates, Generator& rResGen);



} // namespace faudes

#endif 

