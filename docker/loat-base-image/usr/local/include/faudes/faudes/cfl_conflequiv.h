/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2015  Michael Meyer and Thomnas Moor.
   Copyright (C) 2021,2023  Yiheng Tang, Thomas Moor.
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

#ifndef FAUDES_CONFLEQUIV_H
#define FAUDES_CONFLEQUIV_H

#include "cfl_generator.h"
#include "cfl_basevector.h"

namespace faudes {

/**
 * Test for conflicts
 *
 * A family of generators is non-blocking, if their parallel composition
 * is non-blocking (all accessible states are co-accessible).
 *
 * This implementation applies a number of conflict equivalent
 * simplifications before finally testing for conflicts in the
 * parallel composition;
 * This approach has been originally proposed by R. Malik  and H. Flordal
 * in "Compositional verification in supervisory
 * control", SIAM Journal of Control and Optimization, 2009.
 *
 * The current implementation is based on Michael Meyer's
 * BSc Thesis and repaired/optimized by Yiheng Tang
 *
 *
 * @param rGenVec
 *   Vector of input generators
 * @return res
 *   true if there are no conflicts
 *
 * @ingroup GeneratorFunctions
 */

extern FAUDES_API bool IsNonconflicting(const GeneratorVector& rGenVec);
extern FAUDES_API bool IsNonblocking(const GeneratorVector& rGvec);

/**
 * Conflict equivalent abstraction.
 *
 * Two generators are conflict equivalent w.r.t. a set of silent events,
 * if, for any test generator defined over the not-silent events, either
 * both or non are conflicting. This functions implements a selection of
 * conflict equivalent transformations proposed by R. Malik  and H. Flordal 
 * in "Compositional verification in supervisory control", SIAM Journal of 
 * Control and Optimization, 2009.
 * 
 * The current implementation is experimental with code based on Michael Meyer's
 * BSc Thesis. 
 *
 * @param rGen
 *   Input generator
 * @param rSilentEvents
 *   Set of silent events, i.e., events not shared
 *   with any other generator to compose with.
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void ConflictEquivalentAbstraction(vGenerator& rGen, EventSet& rSilentEvents);



/**
 * Remove all silent loops in a given automaton. This function is considered as an
 * API not only for its general operational meaning, but most importantly due to the prerequisite for
 * topological sort.
 * @param rGen
 *   input generator
 * @param silent
 *   silent alphabet, contains at most one event
 */
extern FAUDES_API void RemoveTauLoops(Generator& rGen, const EventSet& silent);
 


 
} // namespace 
#endif // FAUDES_CONFLEQUIV_H
