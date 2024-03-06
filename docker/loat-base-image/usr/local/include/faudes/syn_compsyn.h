/** @file syn_compsyn.h Compositional synthesis */

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

 
#ifndef FAUDES_COMPSYN_H
#define FAUDES_COMPSYN_H

#include "corefaudes.h"

namespace faudes {
    
/**
 * Compositional synthesis
 *
 * This function implements controller synthesis for composed
 * plants and composed specifications as discussed in 
 * "On Compostional Approaches for Discrete Event Systems
 *  Verification and Synthesis" Sahar Mohajerani, PhD, Sweden, 2015.
 *
 * The present implementation was developed by Hao Zhou in course
 * of his Master Thesis "Abstraktion und Komposition fuer den Entwurf 
 * ereignisdiskreter Regler", Erlangen, 2015. This particular variant
 * throughs an exception on invalid input data; see also 
 * CompositionalSynthesisUnchecked(const GeneratorVector&,const EventSet&,const GeneratorVector&,std::map<Idx,Idx>&,GeneratorVector&,GeneratorVector&);
 * 
 *
 * @param rPlantGenVec
 *   Plant components (must be deterministic)
 * @param rConAlph
 *   Overall set of controllable events
 * @param rSpecGenVec 
 *   Specification components (must be deterministic)
 * @param rMapEventsToPlant
 *   Resulting event map
 * @param rDisGenVec
 *   Resulting distinuisher automata 
 * @param rSupGenVec
 *   Resulting supervisor automata
 *
 * @ingroup SynthesisPlugIn
 */
extern FAUDES_API void CompositionalSynthesis(const GeneratorVector& rPlantGenVec, 
	      const EventSet& rConAlph,
	      const GeneratorVector& rSpecGenVec, 
	      std::map<Idx,Idx>& rMapEventsToPlant,
	      GeneratorVector& rDisGenVec,
	      GeneratorVector& rSupGenVec);

/**
 * Compositional synthesis
 *
 * Variant of 
 * CompositionalSynthesis(const GeneratorVector&,const EventSet&,const GeneratorVector&,std::map<Idx,Idx>&,GeneratorVector&,GeneratorVector&);
 * without parameter-consistency test.
 *
 * @param rPlantGenVec
 *   Plant components (must be deterministic)
 * @param rConAlph
 *   Overall set of controllable events
 * @param rSpecGenVec 
 *   Specification components (must be deterministic)
 * @param rMapEventsToPlant
 *   Resulting event map
 * @param rDisGenVec
 *   Resulting distinuisher automata 
 * @param rSupGenVec
 *   Resulting supervisor automata
 *
 */
extern FAUDES_API void CompositionalSynthesisUnchecked(const GeneratorVector& rPlantGenVec, 
	      const EventSet& rConAlph,
	      const GeneratorVector& rSpecGenVec, 
	      std::map<Idx,Idx>& rMapEventsToPlant,
	      GeneratorVector& rDisGenVec,
	      GeneratorVector& rSupGenVec);



/**
 * Compositional synthesis
 *
 * Text consistency of input-data fro compositional synthesis; through exception on error.
 * 
 * @param rPlantGenVec
 *   Plant components (must be deterministic)
 * @param rConAlph
 *   Overall set of controllable events
 * @param rSpecGenVec 
 *   Specification components (must be deterministic)
 *
 */
extern FAUDES_API void ControlProblemConsistencyCheck(const GeneratorVector& rPlantGenVec, 
		   const EventSet& rConAlph,
		   const GeneratorVector& rSpecGenVec);


} // namespace faudes

#endif 


