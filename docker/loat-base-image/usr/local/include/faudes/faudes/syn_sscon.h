/** @file syn_sscon.h Standard syntheis consistency test */

/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2014  Matthias Leinfelder, Thomas Moor

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
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA 
*/

 
#ifndef FAUDES_SSCON_H
#define FAUDES_SSCON_H

#include "corefaudes.h"
#include "syn_supcon.h"
#include "syn_functions.h"

namespace faudes {
    

/**
 * Test consistency of an abstractions w.r.t. standard controller synthesis.
 *
 * Test whether abstraction-based supervisory controller design is guaranteed to
 * lead to a non-blocking and controllable closed loop. This function implements
 * the test proposed in  "Moor, T.: Natural projections for the synthesis of 
 * non-conflicting supervisory controllers, Workshop on Discrete Event Systems (WODES), Paris, 2014". 
 *
 * Parameter restrictions: the generator has to be deterministic and the alphabets must match (see below for exceptions).
 *
 *
 * @param rPlantGen
 *   plant G
 * @param rCAlph
 *   controllable events
 * @param rPlant0Gen
 *   plant abstraction G0
 *
 * @exception Exception
 *   - the abstraction rPlant0Gen must have been obtained from the plant rPlantGen by natural projection (not tested)
 *   - the abstraction alphabet given by rPlant0Gen fails to be a subset of the overall alphabet given by rPlantGen (id 506)
 *   - alphabet with controllable Events fails be a subset of the abstraction alphabet given by rAbstrGen (id 506)
 *   - generators fail to be deterministic (id 501)
 *
 * @return 
 *   true / false
 *
 * @ingroup SynthesisPlugIn
 */

extern FAUDES_API bool IsStdSynthesisConsistent(
  const Generator& rPlantGen, 
  const EventSet&  rCAlph, 
  const Generator&  rPlant0Gen);


/**
 * Test consistency of an abstraction w.r.t standard synthesis.
 *
 * This is a convenience wrapprt for IsStdSynthesisConsistent(const Generator&, const EventSet&, const Generator&).
 *
 *
 *
 * @param rPlantGen
 *   plant G incl. controllable events
 * @param rPlant0Gen
 *   plant abstraction G0
 *
 * @exception Exception
 *   - the abstraction rPlant0Gen must have been obtained from the plant rPlantGen by natural projection (not tested)
 *   - the abstraction alphabet given by rPlant0Gen fails to be a subset of the overall alphabet given by rPlantGen (id 506)
 *   - alphabet with controllable Events fails be a subset of the abstraction alphabet given by rAbstrGen (id 506)
 *   - generators fail to be deterministic (id 501)
 *
 * @return 
 *   true / false
 *
 * @ingroup SynthesisPlugIn
 */
bool IsStdSynthesisConsistent(
  const System& rPlantGen, 
  const Generator& rPlant0Gen);

}// namespace faudes

#endif 


