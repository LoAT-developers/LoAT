/** @file cfl_bisimulation.h  Bisimulation relations

    Functions to compute bisimulation relations on dynamic systems (represented
    by non-deterministic finite automata). 

    The relevant algorithms are described in J.-C. Fernandez, "An implementation 
    of an efficient algorithm for bisimulation equivalence", Science of Computer 
    Programming, vol. 13, pp. 219-236, 1990. 

    This code was originally part of the observer-plugin and moved in revised
    form to corefaudes by Version 2.26

**/

/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2009, Christian Breindl
   Copyright (C) 2015, Thomas Moor
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


#ifndef FAUDES_CFL_BISIMULATION_H
#define FAUDES_CFL_BISIMULATION_H

#include "cfl_definitions.h"
#include "cfl_generator.h"

#include <vector>
#include <map>



namespace faudes {

/**
* Computation of the coarsest bisimulation relation for a specified generator. 
*
* This funtcion creates an instance of the class Bisimulation and triggers the computation
* of the coarsest quasi-congruence on the given generator by calling the function Bisimulation::partition. 
* The result is returned as a map from original state idicess to partion indicees.
* The implementation is derived from J.-C. Fernandez, “An implementation of an efficient 
* algorithm for bisimulation equivalence,” Science of Computer Programming, vol. 13, pp. 219-236, 1990.
*
* This interface is neither used nor tested. 
* Use ComputeBisimulation(Generator& , std::map<Idx,Idx>& , Generator& ) instead.
*
* @param rGenOrig
*   Original generator
* @param rMapStateToPartition
*   Maps each state to its equivalence class
*
* @ingroup GeneratorFunctions
*/
extern FAUDES_API void ComputeBisimulation(const Generator& rGenOrig, std::map<Idx,Idx>& rMapStateToPartition);


/**
* Computation of the coarsest bisimulation relation for a specified generator. 
*
* This is a convenience wrapper for ComputeBisimulation(Generator&, std::map<Idx,Idx>&) to
* return the quitient generator to represent the result. 
*
* See ComputeBisimulation(const Generator&, std::map<Idx,Idx>).
*
* @param rGenOrig
*   Original generator
* @param rMapStateToPartition
*   Maps each state to its equivalence class
* @param rGenPart
*   Quotient automaton representing the result of the computation. Each state corresponds to an 
*   equivalence class
*
* @ingroup GeneratorFunctions
*/
extern FAUDES_API void ComputeBisimulation(const Generator& rGenOrig, std::map<Idx,Idx>& rMapStateToPartition, Generator& rGenPart);


/**
* Computation of the coarsest bisimulation relation for a specified generator. 
*
* This is a convenience wrapper for ComputeBisimulation(Generator&, std::map<Idx,Idx>&) to
* return a list of nontrivial equivalence classes (singletons are not reported)
*
* See ComputeBisimulation(const Generator&, std::map<Idx,Idx>).
*
* @param rGenOrig
*   Original generator
* @param rPartitions 
*   list of equivalent states
*
* @ingroup GeneratorFunctions
*/
extern FAUDES_API void ComputeBisimulation(const Generator& rGenOrig, std::list< StateSet >& rPartitions);


}

#endif

