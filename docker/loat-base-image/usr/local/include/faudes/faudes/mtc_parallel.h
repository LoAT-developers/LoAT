/** @file mtc_parallel.h

Methods for parallel composition of multitasking generators

*/

/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2008  Matthias Singer
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


#ifndef FAUDES_MTCPARALLEL_H
#define FAUDES_MTCPARALLEL_H

#include "corefaudes.h"
#include "mtc_generator.h"
#include <stack>

namespace faudes {

/**
 * Parallel composition of two colored marking generators, controllability status is observed
 *
 * @param rGen1
 *   First MtcSystem for parallel composition
 *
 * @param rGen2
 *   Second MtcSystem for parallel composition
 *
 * @param rResGen
 *   MtcSystem in which the result of the parallel composition is saved
 *
 * <h4>Example: Parallel composition of two colored marking generators</h4>
 * <table border=0> <tr> <td>
 *   <table width=100%>
 *     <tr> <td> <center> MtcSystems for composition </center> </td> </tr>
 *     <tr> <td> @image html tmp_mtc_functions_4a_system.png </td> </tr>
       <tr> <td> @image html tmp_mtc_functions_4b_system.png </td> </tr>
 *     <tr> <td> <center> The left MtcSystem contains only one colored state, state 2, whereas the right one possesses two color labels - one for each state. </center> </td> </tr>
 *   </table>
 *   </td> </tr>
 *   <tr> <td>
 *   <table width=100%>
 *     <tr> <td> <center> Result of the parallel composition </center> </td> </tr>
 *     <tr> <td> @image html tmp_mtc_functions_4c_parallel.png </td> </tr>
 *     <tr> <td> <center> The composed MtcSystem contains all colors that appear in both single MtcSystems.

The single states are labeled with a color when both states to combine are labeled with it. A color label is also added when it occurs in one of the two currently regarded states to compose and, at the same time, it does not appear in the second single MtcSystem. </center> </td> </tr>
 *   </table>
 *   </td> </tr>
 * </table>
 *
 * @ingroup MultitaskingPlugin
 */
extern FAUDES_API void mtcParallel(const MtcSystem& rGen1, const MtcSystem& rGen2,
    MtcSystem& rResGen);

/**
 * Parallel composition of two MtcSystems
 *
 * @param rGen1
 *   First MtcSystem for parallel composition
 *
 * @param rGen2
 *   Second MtcSystem for parallel composition
 *
 * @param rReverseCompositionMap
 *
 * @param rResGen
 *   Generator in which the result of the parallel composition is saved
 */
extern FAUDES_API void mtcParallel(const MtcSystem& rGen1, const MtcSystem& rGen2,
    std::map< std::pair<Idx,Idx>, Idx>& rReverseCompositionMap, 
    MtcSystem& rResGen);

/**
 * Compose the color set for a state combined from two states in two distinct automata
 *
 * @param rGen1
 *   First MtcSystem for parallel composition
 *
 * @param stdidx1
 *   Index to first MtcSystem's current state
 *
 * @param colors1
 *   Color set of first MtcSystem
 *
 * @param rGen2
 *   Second MtcSystem for parallel composition
 *
 * @param stdidx2
 *   Index to second MtcSystem's current state
 *
 * @param colors2
 *   Color set of second MtcSystem
 *
 * @param composedSet
 *   Color set where composition colors will be inserted
 *
 * @exception Exception
 *   - Index not member of set (id 200)
 *   - Index not found in set (id 201)
 */
extern FAUDES_API void ComposedColorSet(const MtcSystem& rGen1, const Idx stdidx1, ColorSet& colors1,
                      const MtcSystem& rGen2, const Idx stdidx2, ColorSet& colors2,
                      ColorSet& composedSet);

} // namespace faudes

#endif
