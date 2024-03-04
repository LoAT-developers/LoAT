/** @file cfl_statemin.h state space minimization */

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


#ifndef FAUDES_STATEMIN_H
#define FAUDES_STATEMIN_H

#include "cfl_definitions.h"
#include "cfl_agenerator.h"
#include <vector>
#include <string>
#include <sstream>

namespace faudes {

/**
 * State set minimization.
 * Constructs a generator with minimal stateset while preserving the generated und marked languages.
 * This function implements the (n*log n) set partitioning algorithm by
 * John E. Hopcroft.  The algorithm expects an accessible input generator. To have a const
 * interface, the argument is copied. See also StateMin(Generator&,Generator&).
 *
 * @param rGen
 *   Generator
 * @param rResGen
 *   Minimized generator (result)
 *
 * @exception Exception
 *   Input automaton nondeterministic (id 101)
 *
 * <h4>Example:</h4>
 * <table>
 * <tr> <td> Generator G </td> <td> StateMin(G,Result) </td> </tr>
 * <tr>
 * <td> @image html tmp_minimal_nonmin.png </td>
 * <td> @image html tmp_minimal_min.png </td>
 * </tr>
 * </table> 
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void StateMin(const Generator& rGen, Generator& rResGen);

/**
 * State set minimization.
 *
 * See also StateMin(const Generator&, Generator&).
 * This version maintains event attributes provided 
 * they can be casted to the result type.
 *
 * @param rGen
 *   Generator
 * @param rResGen
 *   Minimized generator (result)
 *
 * @exception Exception
 *   Input automaton nondeterministic (id 101)
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void aStateMin(const Generator& rGen, Generator& rResGen);

/**
 * State set minimization.
 *
 * See also StateMin(const Generator&, Generator&).
 * This version maintains event attributes provided 
 * they can be casted to the result type.
 *
 * @param rGen
 *   Generator
 *
 * @exception Exception
 *   Input automaton nondeterministic (id 101)
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void aStateMin(Generator& rGen);

/**
 * State set minimization.
 * This function implements the (n*log n) set partitioning algorithm by
 * John E. Hopcroft. Given generator will be made accessible before computing
 * minimized generator.
 * See also StateMin(Generator&,Generator&).
 *
 * @param rGen
 *   Generator
 * @param rResGen
 *   Minimized generator (result)
 * @param rSubsets
 *   Vector of subsets that will be constructed during running the algorithm
 *   (optional parameter)
 * @param rNewIndices
 *   Vector of new state indices corresponding to the subsets
 *   (optional parameter)
 *
 * @exception Exception
 *   Input automaton nondeterministic (id 101)
 */
extern FAUDES_API void StateMin(const Generator& rGen, Generator& rResGen, 
	      std::vector< StateSet >& rSubsets, std::vector<Idx>& rNewIndices);

} // namespace faudes

#endif 
