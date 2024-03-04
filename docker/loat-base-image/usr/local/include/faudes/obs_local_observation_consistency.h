/** @file obs_local_observation_consistency.h Local Observation Consistency */

/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2006  Bernd Opitz
   Copyright (C) 2007  Thomas Moor
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

#ifndef FAUDES_LOC_H
#define FAUDES_LOC_H

#include "corefaudes.h"
#include "op_include.h"
#include <vector>

namespace faudes {
  

/**
 * Supervisor Reduction algorithm
 *
 * Computes a reduced supervisor from a given potentially non-reduced supervisor and the plant. 
 * This algorithm implements the results obtained in 
 *
 * R. Su and W. M. Wonham. Supervisor Reduction for Discrete-Event Systems.
 * Discrete Event Dynamic Systems vol. 14, no. 1, January 2004.
 *
 * Both, plant and supervisor MUST be deterministic and share the same alphabet!!!
 *
 * @param rPlantGen
 *   Plant generator
 * @param rSpecGen
 *   Specification generator
 * @param rHighAlph
 *   high-level alphabet
 * @param rObsAlph
 *   observable alphabet
 *
 * @return
 *   True if a reduction was achieved
 *
 * @exception Exception
 *   - alphabets of generators don't match (id 100)
 *   - plant nondeterministic (id 201)
 *   - supervisor nondeterministic (id 203)
 *   - plant and supervisor nondeterministic (id 204)
 *
 * @ingroup ObservabilityPlugin
 */
extern FAUDES_API bool LocalObservationConsistency(const System& rPlantGen, const System& rSpecGen, const EventSet& rHighAlph, const EventSet& rObsAlph);

		 

} // namespace faudes

#endif 
