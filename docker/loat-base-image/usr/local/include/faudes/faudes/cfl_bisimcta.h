/** @file cfl_bisimcta.h  Bisimulation relations

    Functions to compute bisimulation relations on dynamic systems (represented
    by non-deterministic finite automata). 

    More specifically, we we implement algorithms to obtain ordinary/delayed/weak 
    bisimulations partitions based on change-tracking. In large, these implementations
    are expected to perform better than the classical variants found in cfl_bisimulation.h".

    This code was originally developed by Yiheng Tang in the context of compositional
    verification in 2020/21.

**/

/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2020,23, Yiheng Tang
   Copyright (C) 2021     Thomas Moor
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



#ifndef FAUDES_CFL_BISIMCTA_H
#define FAUDES_CFL_BISIMCTA_H

#include "cfl_definitions.h"
#include "cfl_generator.h"
#include "cfl_nameset.h"
#include "cfl_indexset.h"

#include <vector>
#include <map>
#include <list>


namespace faudes {


/*!
 * \brief FactorTauLoops
 * merge silent loop and then remove silent self loops
 *  \param rGen
 *      input generator
 * \param rSilent
 *      silent event 
 */
extern FAUDES_API void FactorTauLoops(Generator &rGen, const Idx &rSilent);


/*!
 * \brief ExtendTransRel
 * perform transition saturation w.r.t. silent evs. Two different saturation modes are set depending on flag value
 * \param rGen
 *      input gen
 * \param rSilent
 *      silent event set (contains either 0 or 1 event)
 * \param rFlag
 *      flag for saturation mode -- rFlag == 1: delayed transition (half-saturated); rFlag == 2: observed transition (full-saturated)
 */
extern FAUDES_API void ExtendTransRel(Generator &rGen, const EventSet& rSilent, const Idx& rFlag);


/*!
 * \brief InstallSelfloops
 * install selfloops on all states of given event set. intended to install silent event selfloops for saturation
 * \param rGen
 *      input gen
 * \param rEvs
 *      events which will be installed as selfloops
 */
extern FAUDES_API void InstallSelfloops(Generator &rGen, const EventSet& rEvs);



/*!
 * \brief ComputeBisimulationCTA
 * basic bisimulation partition algorithm based on change-tracking algorithm
 * \param rGen
 *      input gen
 * \param rResult
 *      state partition without trivial classes
 */
extern FAUDES_API void ComputeBisimulationCTA(const Generator& rGen, std::list<StateSet>& rResult);

/*!
 * \brief ComputeBisimulationCTA
 * bisimulation partition based on change-tracking algorithm and topo sort
 * \param rGen
 *      input gen
 * \param rSilent
 *      silent event set (contains either 0 or 1 event)
 * \param rResult
 *      state partition without trivial classes
 */
extern FAUDES_API void ComputeBisimulationCTA(const Generator& rGen, const EventSet& rSilent, std::list<StateSet>& rResult);

/*!
 * \brief ComputeWeakBisimulationCTA
 * weak bisimulation (aka observation eq) partition based on change-tracking algorithm and topo sort
 * \param rGen
 *      input gen
 * \param rSilent
 *      silent event set (contains either 0 or 1 event)
 * \param rResult
 *      state partition without trivial classes
 */
extern FAUDES_API void ComputeWeakBisimulationCTA(const Generator& rGen, const EventSet& rSilent, std::list<StateSet>& rResult);

/*!
 * \brief ComputeBisimulationCTA
 * basic bisimulation partition algorithm under prepartition based on change-tracking algorithm
 * \param rGen
 *      input gen
 * \param rResult
 *      state partition without trivial classes
 * \param rPrePartition
 *      prepartition (trivial classes MUST be included)
 */
extern FAUDES_API void ComputeBisimulationCTA(const Generator& rGen, std::list<StateSet>& rResult, const std::vector<StateSet>& rPrePartition);

/*!
 * \brief ComputeDelayedBisimulationCTA
 * delayed bisimulation partition under prepartition based on change-tracking algorithm and topo sort
 * \param rGen
 *      input gen
 * \param rSilent
 *      silent event set (contains either 0 or 1 event)
 * \param rResult
 *      state partition without trivial classes
 * \param rPrePartition
 *      prepartition (trivial classes MUST be included)
 */
extern FAUDES_API void ComputeDelayedBisimulationCTA(const Generator& rGen, const EventSet& rSilent, std::list<StateSet>& rResult, const std::vector<StateSet>& rPrePartition);

/*!
 * \brief ComputeWeakBisimulationCTA
 * weak bisimulation (aka observation eq) partition under prepartition based on change-tracking algorithm and topo sort
 * \param rGen
 *      input gen
 * \param rSilent
 *      silent event set (contains either 0 or 1 event)
 * \param rResult
 *      state partition without trivial classes
 * \param rPrePartition
 *      prepartition (trivial classes MUST be included)
 */
extern FAUDES_API void ComputeWeakBisimulationCTA(const Generator& rGen, const EventSet& rSilent, std::list<StateSet>& rResult, const std::vector<StateSet>& rPrePartition);




/*!
 * \brief ComputeAbstractBisimulationSatCTA
 * saturation and change-tracking based partition algorithm for either delayed or weak bisimulation. This function is intended to be
 * invoked by ComputeDelayedBisimulation_Sat or ComputeWeakBisimulation_Sat, not for direct external usage
 * \param rGen
 *      input gen
 * \param rSilent
 *      silent event set (contains either 0 or 1 event)
 * \param rResult
 *      state partition without trivial classes
 * \param rFlag
 *      rFlag == 1: dalayed bisimulation; rFlag == 2: weak bisimulation
 * \param rPrePartition
 *      prepartition (trivial classes MUST be included)
 */
void ComputeAbstractBisimulationSatCTA(const Generator& rGen, const EventSet& rSilent, std::list<StateSet>& rResult, const Idx& rFlag, const std::vector<StateSet>& rPrePartition);

/*!
 * \brief ComputeDelayedBisimulationSatCTA
 * delayed bisimulation partition based on change-tracking algorithm and saturation
 * \param rGen
 *      input gen
 * \param rSilent
 *      silent event set (contains either 0 or 1 event)
 * \param rResult
 *      state partition without trivial classes
 */
extern FAUDES_API void ComputeDelayedBisimulationSatCTA(const Generator& rGen, const EventSet& rSilent, std::list<StateSet>& rResult);

/*!
 * \brief ComputeWeakBisimulationSatCTA
 * weak bisimulation (aka observation eq) partition based on change-tracking algorithm and saturation
 * \param rGen
 *      input gen
 * \param rSilent
 *      silent event set (contains either 0 or 1 event)
 * \param rResult
 *      state partition without trivial classes
 */
extern FAUDES_API void ComputeWeakBisimulationSatCTA(const Generator& rGen, const EventSet& rSilent, std::list<StateSet>& rResult);


/*!
 * \brief ComputeDelayedBisimulationCTA
 * delayed bisimulation partition under prepartition based on change-tracking algorithm and saturation
 * \param rGen
 *      input gen
 * \param rSilent
 *      silent event set (contains either 0 or 1 event)
 * \param rResult
 *      state partition without trivial classes
 * \param rPrePartition
 *      prepartition (trivial classes MUST be included)
 */
extern FAUDES_API void ComputeDelayedBisimulationCTA(const Generator& rGen, const EventSet& rSilent, std::list<StateSet>& rResult, const std::vector<StateSet>& rPrePartition);

/*!
 * \brief ComputeComputeWeakBisimulationSatCTA
 * weak bisimulation partition under prepartition based on change-tracking algorithm and saturation
 * \param rGen
 *      input gen
 * \param rSilent
 *      silent event set (contains either 0 or 1 event)
 * \param rResult
 *      state partition without trivial classes
 * \param rPrePartition
 *      prepartition (trivial classes MUST be included)
 */
extern FAUDES_API void ComputeComputeWeakBisimulationSatCTA(const Generator& rGen, const EventSet& rSilent, std::list<StateSet>& rResult, const std::vector<StateSet>& rPrePartition);


} // namespace
#endif // BISIMCTA_H
