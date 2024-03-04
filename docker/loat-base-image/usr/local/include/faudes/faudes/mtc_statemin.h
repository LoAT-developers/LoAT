/** @file mtc_statemin.h

State space minimization

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


#ifndef FAUDES_MTCSTATEMIN_H
#define FAUDES_MTCSTATEMIN_H

#include "corefaudes.h"
#include "mtc_generator.h"
#include <vector>
#include <string>
#include <sstream>

namespace faudes {

/**
 * State Minimization
 * This function implements the (n*log n) set partitioning algorithm by
 * John E. Hopcroft extended to colored marking. Given generator will be made accessible before computing
 * minimized generator.
 *
 * @param rGen
 *   MtcSystem
 * @param rResGen
 *   Minimized MtcSystem (result)
 *
 * @exception Exception
 *   - Input automaton nondeterministic (id 505)
 */
extern FAUDES_API void mtcStateMin(MtcSystem& rGen, MtcSystem& rResGen);

/**
 * State Minimization
 * This function implements the (n*log n) set partitioning algorithm by
 * John E. Hopcroft extended to colored marking. Given generator will be made accessible before computing
 * minimized generator.
 *
 * @param rGen
 *   MtcSystem
 * @param rResGen
 *   Minimized MtcSystem (result)
 * @param rSubsets
 *   Vector of subsets that will be constructed during running the algorithm
 *   (optional parameter)
 * @param rNewIndices
 *   Vector of new state indices corresponding to the subsets
 *   (optional parameter)
 *
 * @exception Exception
 *   - Input automaton nondeterministic (id 505)
 */
extern FAUDES_API void mtcStateMin(MtcSystem& rGen, MtcSystem& rResGen, 
		std::vector<StateSet>& rSubsets, std::vector<Idx>& rNewIndices);

/**
 * RTI wrapper. See also mtcStateMin(MtcSystem&, MtcSystem&).
 */
extern FAUDES_API void mtcStateMin(const MtcSystem& rGen, MtcSystem& rResGen);


} // namespace faudes

#endif 
