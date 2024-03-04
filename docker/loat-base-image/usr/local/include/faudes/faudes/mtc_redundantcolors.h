/** @file mtc_redundantcolors.h

Methods for removing redundant colors for the supervisor synthesis from MtcSystems

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


#ifndef FAUDES_MTCREDUNDANTCOLORS_H
#define FAUDES_MTCREDUNDANTCOLORS_H

#include "corefaudes.h"
#include "mtc_observercomputation.h"

namespace faudes {

   /** 
   * Search for strongly connected components (SCC)***
   * This function partitions the stateset of a generator into equivalence classes
   * such that states x1 and x2 are equivalent iff there is a path from x1
   * to x2 AND a path from x2 to x1.
   * This function implements the algorithm based on a depth first search
   * presented in:
   * -Aho, Hopcroft, Ullman: The Design and Analysis of Computer Algorithms-
   *
   * Most of the comments in this function have been literally taken from
   * this book!
   *
   * @param state
   *    State, from which the current recursion is started.
   * @param rCount
   *   denotes the current depth of the recursion.
   * @param rGen
   *   Generator under investigation
   * @param rNewStates 
   *   Set of states that up to now were not found by the depth first search
   * @param rSTACK
   *    stack of state indices
   * @param rStackStates
   *    set of states whose indices are on STACK.
   * @param rDFN
   *    map assigning to each state its Depth-First Number
   * @param rLOWLINK
   *    map assigning to each state its LOWLINK Number
   * @param rSccSet
   *    result - the set of strongly connected components
   * @param rRoots: 
   *   result - the set of states that each are root of some SCC.
   */
extern FAUDES_API void SearchScc( const Idx state, int& rCount,  const Generator& rGen, StateSet&  rNewStates,
  std::stack<Idx>& rSTACK, StateSet& rStackStates, std::map<const Idx, int>& rDFN,
  std::map<const Idx, int>& rLOWLINK, std::set<StateSet>& rSccSet, StateSet& rRoots);

/**
 * Computes the strongly connected components (SCCs) of an automaton.
 * This function is the wrapper function for Trajan's algorithm that is implemented
 * in the function SearchSCC. 
 * 
 * @param rGen
 *   investigated generator
 * @param rSccSet
 *   Set of strongly connected components (result).
 * @param rRoots
 *   Set of states that each are root of some SCC (result).
 *
 * @return
 *   true if SCCs have been found, false if not.
 * 
 * @ingroup MultitaskingPlugin 
 *
 */
extern FAUDES_API bool ComputeSCC(const Generator& rGen, std::set<StateSet>& rSccSet, StateSet& rRoots); 

/**
 * Compute all strongly connected components (SCCs) in a colored marking generator (CMG) that are marked with a given set of colors. 
 * This function finds all SCCs in a CMG that contain states with all colors in a given color set.
 * To find all SCCs, first the function ComputeSCC is called. 
 *
 * @param rGen
 *  generator under investigation
 * @param rColors
 *  colors that have to be contained in the SCCs
 * @param rColoredSCCs
 *  SCCs marked with all colors in rColors
 * 
 * @ingroup MultitaskingPlugin 
 */
extern FAUDES_API void ColoredSCC(MtcSystem& rGen, ColorSet& rColors, std::set<StateSet>& rColoredSCCs);

/**
 * Check if a color in a colored marking generator is redundant for the supervisor synthesis.
 * This function determines if a color can be removed from a CMG if it is redundant for 
 * the supervisor synthesis. The algorithm implements the work in 
 * K. Schmidt and J.E.R. Cury, "Redundant Colors in the Multitasking Supervisory Control for Discrete
 * Event Systems", Workshop on Dependable Control of Discrete Event Systems, 2009.  
 *
 * @param rGen
 *   Reference to generator
 * @param redundantColor
 *   Index of the color to be removed
 + @return 
 *   true if the color can be removed, false otherwise
 *
 * 
 * @ingroup MultitaskingPlugin 
 */
extern FAUDES_API bool CheckRedundantColor(MtcSystem rGen, Idx redundantColor);


 /** 
   * Compute an optimal subset of the colors that should be removed.
   * This function tries to find an optimal subset of colors that can be removed from the given
   * colored marking generator without affecting supervisor synthesis. Here, optimality is defined
   * w.r.t. the smallest number of states of a high-level generator after removing the colors. 
   *
   * @param rGen
   *   input colored marking generator
   * @param rOptimalColors
   *   optimal color set to be removed
   * @param rHighAlph
   *    hgh-level alphabet for hierarchical abstraction after color removal. Initially, the alphabet should contain
   *   all events that must be present in the high-level alphabet
   *
   *
   * @ingroup MultitaskingPlugin    
   */
extern FAUDES_API void OptimalColorSet(const MtcSystem& rGen, ColorSet& rOptimalColors, EventSet& rHighAlph);

/**
 * Recursively find an optimal set of colors to be removed.
 * This function recursively enumerates all possible subsets of colors that can be removed without affecting
 * supervisor synthesis and remembers the color set that leads to the smallest hierarchical abstraction. 
 * It is called by the function OptimalColorSet.
 *
 * @param rGen
 *  input colored marking generator
 * @param rColorVector
 *  set of colors of the generator (ordered!)
 * @param colorNumber
 *  number of colors currently removed
 * @param rOptimalColors
 *  current optimal set of colors
 * @param rOptimalNumberStates
 *  current optimal number of states
 * @param rOptimalNumberColors
 *  size of the optimal color set
 * @param rHighAlph
 *  initial high-level alphabet
 * @param rOptimalHighAlph
 *  optimal high-level alphabet
 *
 */
extern FAUDES_API void rec_OptimalColorSet(const MtcSystem& rGen, const std::vector<Idx>& rColorVector, Idx colorNumber, ColorSet& rOptimalColors, 
        Idx& rOptimalNumberStates, Idx& rOptimalNumberColors, const EventSet& rHighAlph, EventSet& rOptimalHighAlph);
} // namespace faudes

#endif
