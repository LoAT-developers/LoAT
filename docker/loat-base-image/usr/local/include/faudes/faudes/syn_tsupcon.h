/** @file syn_supcon.h Supremal tdes-controllable sublanguage */

/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2013 Thomas Moor
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

 
#ifndef FAUDES_TSUPCON_H
#define FAUDES_TSUPCON_H

#include "corefaudes.h"
#include "syn_supcon.h"

namespace faudes {
    


/**
 * Nonblocking Supremal TDES-Controllable Sublanguage
 *
 * Controllable sublanguage w.r.t. specified forcible and preemptable
 * events. When the set of preemptable events consist exclusively of the <tt>tick</tt> event, 
 * this corresponds to TDES-controllability.
 *
 * (!) Interface most likely to change --- needs more testing/proper design (!)
 *
 * @param rPlantGen
 *   Plant G
 * @param rCAlph
 *   Controllable events
 * @param rFAlph
 *   Forcible events
 * @param rPAlph
 *   Premptable events
 * @param rSpecGen
 *   Specification Generator E
 * @param rResGen
 *   Reference to resulting Generator
 *
 * @exception Exception
 *   - alphabets of generators don't match (id 100)
 *   - plant nondeterministic (id 201)
 *   - spec nondeterministic (id 203)
 *   - plant and spec nondeterministic (id 204)
 *
 * @ingroup SynthesisPlugIn
 *
 */
extern FAUDES_API void SupTconNB(
  const Generator& rPlantGen, 
  const EventSet&  rCAlph,
  const EventSet&  rFAlph,
  const EventSet&  rPAlph,
  const Generator& rSpecGen, 
  Generator& rResGen);



/**
 * Nonblocking Supremal TDES-Controllable Sublanguage 
 *
 * This is the RTI wrapper for   
 * SupTconNB(const Generator&, const EventSet&, const Generator&, Generator&).
 * Controllability attributes are taken from the plant argument and
 * tick is the only preemptable event.
 * If the result is specified as a System, attributes will be copied
 * from the plant argument.
 *
 * (!) Interface most likely to change --- needs more testing/ proper design (!)
 *
 *
 * @param rPlantGen
 *   Plant System
 * @param rSpecGen
 *   Specification Generator
 * @param rResGen
 *   Reference to resulting Generator, the
 *   minimal restrictive nonblocking supervisor
 *
 * @exception Exception
 *   Alphabets of generators don't match (id 100)
 *   plant nondeterministic (id 201)
 *   spec nondeterministic (id 203)
 *   plant and spec nondeterministic (id 204)
 *
 * @ingroup SynthesisPlugIn
 */
extern FAUDES_API void SupTconNB(
  const System& rPlantGen, 
  const Generator& rSpecGen, 
  Generator& rResGen);


} // namespace faudes

#endif 


