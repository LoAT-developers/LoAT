/** @file syn_synthequiv.h Synthesis-observation equivalence **/

/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2015  Hao Zhou, Thomas Moor
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

 
#ifndef FAUDES_SYNTHEQUIV_H
#define FAUDES_SYNTHEQUIV_H

#include "corefaudes.h"

namespace faudes {
    
/**
 * Synthesis-observation equivalence
 *
 * Function to compute the coarsest synthesis-observation equivalence
 * relation as proposed by  Mohajerani, S., Malik, R. & Fabian, M. (2012). 
 * "Synthesis observation equivalence and weak synthesis observation equivalence",
 * University of Waikato, Department of Computer Science.
 * Compositional synthesis
 *
 * The present implementation was developed by Hao Zhou in course
 * of his Master Thesis "Abstraktion und Komposition fuer den Entwurf 
 * ereignisdiskreter Regler", Erlangen, 2015. Technically, the implementation
 * is based on a previous variant of the bisimulation algorithm from
 * the core library.
 * 
 *
 * @param rGenOrig
 *   Generator under consideration
 * @param rConAlph
 *   Set of controllable events
 * @param rLocAlph
 *   Set of local events
 * @param rMapStateToPartition
 *   Map original state to partition index
 * @param rResGen
 *   Quotient generator
 *
 * @ingroup SynthesisPlugIn
 */
// ComputeSOE(rGenOrig, rLocAlph, rLocAlph, rMapStateToPartition, rGenPart)
extern FAUDES_API void ComputeSynthObsEquiv(const Generator& rGenOrig, 
	      const EventSet& rConAlph, 
	      const EventSet& rLocAlph, 
	      std::map<Idx,Idx>& rMapStateToPartition, 
	      Generator& rResGen);


} // namespace faudes

#endif 


