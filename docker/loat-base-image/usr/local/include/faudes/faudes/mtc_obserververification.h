/** @file mtc_obserververification.h 

Methods to verify the obsrver condition for natural projections.
The observer condition is, e.g., defined in 
K. C. Wong and W. M. Wonham, “Hierarchical control of discrete-event
systems,” Discrete Event Dynamic Systems: Theory and Applications, 1996.
In addition, methods to verify output control consistency (OCC) and 
local control consistency (LCC) are provided. See for example
K. Schmidt and C. Breindl, "On Maximal Permissiveness of Hierarchical and Modular Supervisory
Control Approaches for Discrete Event Systems," Workshop on Discrete Event Systems, 2008. 
*/

/* FAU Discrete Event Systems Library (libfaudes)

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

#ifndef FAUDES_MTCOBSERVERVERIFICATION_H
#define FAUDES_MTCOBSERVERVERIFICATION_H

#include "corefaudes.h"
//#include "op_debug.h"
#include "op_include.h"
#include "mtc_generator.h"


namespace faudes {


/**
 * Verification of the observer property.
 * For verifying if a natural projection has the observer property, one step in the observer
 * algorithm is evaluated. If the resulting generator equals the input generator, then the 
 * natural projection on the abstraction alphabet is an observer. 
 *
 * @param rLowGen
 *   Input generator
 * @param rHighAlph
 *   High level alphabet
 *
 * @return
 *	true if the observer property holds
 *
 * @ingroup MTCPlugin
 *
 */
 extern FAUDES_API bool IsMtcObs(const MtcSystem& rLowGen, const EventSet& rHighAlph);

} // namespace faudes



#endif

