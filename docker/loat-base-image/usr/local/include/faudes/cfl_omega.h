/** @file cfl_omega.h 

Operations on omega languages.

*/

/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2010 Thomas Moor

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


#ifndef FAUDES_OMEGA_H
#define FAUDES_OMEGA_H

#include "cfl_definitions.h"
#include "cfl_generator.h"

namespace faudes {


/**
 * Product composition for Buechi automata
 *
 * Referring to the Buechi acceptance condition, the resulting genarator 
 * accepts all those inifinite words that are accepted by both, G1 and G2.
 * This implementation extends the usual product state space by a flag to indentify 
 * executions with alternating marking.
 *
 * @param rGen1
 *   First generator
 * @param rGen2
 *   Second generator
 * @param rResGen
 *   Reference to resulting product composition generator
 *
 *
 * @ingroup GeneratorFunctions
 *
 */
extern FAUDES_API void OmegaProduct(const Generator& rGen1, const Generator& rGen2, Generator& rResGen);


/**
 * Product composition for Buechi automata
 *
 * See also OmegaProduct(const Generator&, const Generator&, Generator&).
 * This version tries to be transparent on event attributes: if
 * argument attributes match and if the result can take the respective
 * attributes, then they are copied; it is considered an error if 
 * argument attributes do not match.
 *
 * @param rGen1
 *   First generator
 * @param rGen2
 *   Second generator
 * @param rResGen
 *   Reference to resulting product composition generator
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void aOmegaProduct(const Generator& rGen1, const Generator& rGen2, Generator& rResGen);


/**
 * Parallel composition with relaxed acceptance condition.
 *
 * This version of the parallel composition relaxes the synchronisation of the acceptance
 * condition (marking). It requires that the omega extension of the generated language
 * has infinitely many prefixes that comply to the marked languages of G1 and G2, referring
 * to the projection on the respective alphabet.
 * It does however not require the synchronous acceptance. 
 *
 * @param rGen1
 *   First generator
 * @param rGen2
 *   Second generator
 * @param rResGen
 *   Reference to resulting parallel composition generator
 *
 *
 * @ingroup GeneratorFunctions
 *
 */
extern FAUDES_API void OmegaParallel(const Generator& rGen1, const Generator& rGen2, Generator& rResGen);


/**
 * Parallel composition with relaxed acceptance condition.
 *
 * See also OmegaParallel(const Generator&, const Generator&, Generator&).
 * This version tries to be transparent on event attributes: if
 * argument attributes match and if the result can take the respective
 * attributes, then they are copied; it is considered an error if 
 * argument attributes do not match.
 *
 * @param rGen1
 *   First generator
 * @param rGen2
 *   Second generator
 * @param rResGen
 *   Reference to resulting composition generator
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void aOmegaParallel(const Generator& rGen1, const Generator& rGen2, Generator& rResGen);


/**
 * Topological closure.
 *
 * This function computes the topological closure the omega language 
 * Bm realized by rGen. 
 *
 * Method:
 * First, OmegaTrim is called to erase all states of rGen that do not
 * contribute to Bm. Then, all remaining states are marked.
 *
 * No restrictions on parameter.
 *
 *
 * @param rGen
 *   Generator that realizes Bm to which omega closure is applied
 *
 * <h4>Example:</h4>
 * <table>
 * <tr> <td> Generator G </td> <td> PrefixClosure(G) </td> </tr>
 * <tr>
 * <td> @image html tmp_omegaclosure_g.png </td>
 * <td> @image html tmp_omegaclosure_gRes.png </td>
 * </tr>
 * </table>
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void OmegaClosure(Generator& rGen);


/**
 * Test for  topologically closed omega language.
 *
 * This function tests whether the omega language Bm(G) realized by the specified generator G
 * is topologically closed. 
 *
 * Method:
 * First, compute the omega-trim state set and restrict the discussion to that set.
 * Then, omega-closedness is equivalent to the non-existence on a non-trivial SCC 
 * with no marked states. 
 *
 * @param rGen
 *   Generator that realizes Bm to which omega closure is applied
 * @return
 *   True <> Bm(G) is omega closed
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API bool IsOmegaClosed(const Generator& rGen);




} // namespace faudes

#endif 

