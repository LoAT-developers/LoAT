/** @file syn_wsupcon.h Supremal controllable sublanguage for infinite time behaviours */

/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2010  Thomas Moor

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

 
#ifndef FAUDES_WSUPCON_H
#define FAUDES_WSUPCON_H

#include "corefaudes.h"
#include <stack>

namespace faudes {
    



/**
 * Test omega controllability
 *
 * Tests whether the candidate supervisor H is omega controllable w.r.t.
 * the plant G. This implementation invokes IsControllable and IsRelativelyOmegaClosed.
 * A future implementation may be more efficient.
 * 
 * Parameter restrictions: both generators must be deterministic, omega-trim and 
 * have the same alphabet.
 *
 *
 * @param rPlantGen
 *   Plant G
 * @param rCAlph
 *   Controllable events
 * @param rSupCandGen
 *   Supervisor candidate H
 *
 * @exception Exception
 *   - Alphabets of generators don't match (id 100)
 *   - Arguments are not omega trim (id 201, only if FAUDES_CHECKED is set)
 *   - Arguments are non-deterministic (id 202, only if FAUDES_CHECKED is set)
 *
 * @return 
 *   true / false
 *
 * @ingroup SynthesisPlugIn
 */
extern FAUDES_API bool IsOmegaControllable(
  const Generator& rPlantGen, 
  const EventSet&  rCAlph, 
  const Generator& rSupCandGen);


/**
 * Test omega-controllability. 
 *
 * Tests whether the candidate supervisor h is omega controllable w.r.t.
 * the plant g; this is a System wrapper for IsOmegaControllable.
 *
 * @param rPlantGen
 *   Plant g generator
 * @param rSupCandGen
 *   Supervisor candidate h generator 
 *
 * @exception Exception
 *   - Alphabets of generators don't match (id 100)
 *   - Arguments are not omega trim (id 201, only if FAUDES_CHECKED is set)
 *   - Arguments are non-deterministic (id 202, only if FAUDES_CHECKED is set)
 *
 * @return 
 *   true / false
 *
 * @ingroup SynthesisPlugIn
 */
extern FAUDES_API bool IsOmegaControllable(
  const System& rPlantGen, 
  const Generator& rSupCandGen);


/**
 * Supremal controllable and complete sublanguage
 *
 * Given a plant and a specification, this function computes a realisation of 
 * the supremal controllable and complete sublange. This version consideres the
 * generated languages (ignores the marking). In particular, this implies that
 * the result is prefix closed. It is returned as generated language.
 * 
 * Starting with a product composition of plant and specification, the implementation
 * iteratively remove states that either contradict controllability or completeness.
 * Removal of states is continued until no contradicting states are left. 
 * Thus, the result is indeed controllable and complete. The algorithm was
 * proposed in 
 *
 * R. Kumar, V. Garg, and S.I. Marcus. On supervisory control of
 * sequential behaviors. IEEE Transactions on Automatic Control,
 * Vol. 37: pp.1978-1985, 1992.
 *
 * The paper proves supremality of the result. Provided that the corresponding 
 * omega language of the specification is closed, the result of the above algorithm 
 * also realises the least restrictive closed loop behaviour of the corresponding 
 * omega language control problem.
 *
 * Parameter restrictions: both generators must be deterministic and 
 * have the same alphabet. The result will be accessible and deterministic.
 *
 *
 * @param rPlantGen
 *   Plant G
 * @param rCAlph
 *   Controllable events
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
extern FAUDES_API void SupConCmplClosed(
  const Generator& rPlantGen, 
  const EventSet&  rCAlph,
  const Generator& rSpecGen, 
  Generator& rResGen);



/**
 * Supremal controllable and complete sublanguage.
 *
 * This is the RTI wrapper for   
 * SupConCmplClosed(const Generator&, const EventSet&, const Generator&, Generator&).
 * Controllability attributes are taken from the plant argument.
 * If the result is specified as a System, attributes will be copied
 * from the plant argument.
 *
 *
 * @param rPlantGen
 *   Plant System
 * @param rSpecGen
 *   Specification Generator
 * @param rResGen
 *   Reference to resulting Generator
 *
 * @exception Exception
 *   Alphabets of generators don't match (id 100)
 *   plant nondeterministic (id 201)
 *   spec nondeterministic (id 203)
 *   plant and spec nondeterministic (id 204)
 *
 * @ingroup SynthesisPlugIn
 */
extern FAUDES_API void SupConCmplClosed(
  const System& rPlantGen, 
  const Generator& rSpecGen, 
  Generator& rResGen);


/**
 * Supremal controllable and complete sublanguage
 *
 *
 * Given a plant and a specification, this function computes a realisation of 
 * the supremal controllable and complete sublange. This version consideres the
 * marked languages. 
 *
 * Starting with a product composition of plant and specification, the implementation
 * iteratively remove states that contradict controllability  or completeness or that
 * are not coaccessible. Removal of states is continued until no contradicting states are left. 
 * Thus, the result is indeed controllable, complete and coaccessible. 
 *
 * Considering the marked languages implies that only strings that simultanuosly 
 * reach a marking can survive the above procedure. From an omega-languages perspective, 
 * this is of limited use. However, in the special situation that the specification
 * is relatively closed w.r.t. the plant, we can replace the specification by its
 * prefix closure befor invoking SupConComplNB. In this situation we claim that
 * the procedure returns a realisation of the the least restrictive closed loop behaviour 
 * of the corresponding omega language control problem. 
 *
 *
 * @param rPlantGen
 *   Plant G
 * @param rCAlph
 *   Controllable events
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
extern FAUDES_API void SupConCmplNB(
  const Generator& rPlantGen, 
  const EventSet&  rCAlph,
  const Generator& rSpecGen, 
  Generator& rResGen);



/**
 * Supremal controllable and complete sublanguage.
 *
 * This is the RTI wrapper for   
 * SupConCmplNB(const Generator&, const EventSet&, const Generator&, Generator&).
 * Controllability attributes are taken from the plant argument.
 * If the result is specified as a System, attributes will be copied
 * from the plant argument.
 *
 *
 * @param rPlantGen
 *   Plant System
 * @param rSpecGen
 *   Specification Generator
 * @param rResGen
 *   Reference to resulting Generator
 *
 * @exception Exception
 *   Alphabets of generators don't match (id 100)
 *   plant nondeterministic (id 201)
 *   spec nondeterministic (id 203)
 *   plant and spec nondeterministic (id 204)
 *
 * @ingroup SynthesisPlugIn
 */
extern FAUDES_API void SupConCmplNB(
  const System& rPlantGen, 
  const Generator& rSpecGen, 
  Generator& rResGen);


/**
 * Supremal controllable, normal and complete sublanguage.
 *
 *
 * SupConNormCmplNB computes the supremal sublanguage
 * of language K (marked by rSpecGen) that 
 * - is controllable w.r.t. the language L (marked by rPlantGen);
 * - has a prefix closure that is normal w.r.t. the closure of L
 * - is complete
 *
 * The implementation is based on an iteration by Yoo, Lafortune and Lin 
 * "A uniform approach for computing supremal sublanguages arising 
 * in supervisory control theory", 2002, further developped in 
 * Moor, Baier, Yoo, Lin, and Lafortune "On the computation of supremal 
 * sublanguages relevant to supervisory control, WODES 2012. The relationship 
 * to the supervision of omega languages under partial observation is discussed
 * as an example in the WODES 2012 paper.
 *
 * Parameters have to be deterministic, result is deterministic.
 *
 *
 * @param rPlantGen
 *   Plant L
 * @param rCAlph
 *   Controllable events
 * @param rOAlph
 *   Observable events
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
extern FAUDES_API void SupConNormCmplNB(
  const Generator& rPlantGen, 
  const EventSet&  rCAlph,
  const EventSet&  rOAlph,
  const Generator& rSpecGen, 
  Generator& rResGen);


/**
 * Supremal controllable, normal and complete sublanguage.
 *
 * This is the RTI wrapper for   
 * SupConNormCmplNB(const Generator&, const EventSet&, const EventSet&, const Generator&, Generator&).
 * Event attributes are taken from the plant argument.
 * If the result is specified as a System, attributes will be copied
 * from the plant argument.
 *
 * @param rPlantGen
 *   Plant System
 * @param rSpecGen
 *   Specification Generator
 * @param rResGen
 *   Reference to resulting Generator
 *
 * @exception Exception
 *   Alphabets of generators don't match (id 100)
 *   plant nondeterministic (id 201)
 *   spec nondeterministic (id 203)
 *   plant and spec nondeterministic (id 204)
 *
 * @ingroup SynthesisPlugIn
 */
extern FAUDES_API void SupConNormCmplNB(
  const System& rPlantGen, 
  const Generator& rSpecGen, 
  Generator& rResGen);




/**
 * Omega-synthesis
 *
 * Computation of the supremal oemga-controllable sublanguage as proposed by 
 * Thistle/Wonham in "Control of w-Automata, Church's Problem, and the Emptiness 
 * Problem for Tree w-Automata", 1992, and, here, applied to the specific case 
 * of deterministic Buechi automata. In the given setting, the result matches the 
 * limit of the controllable prefix intersected with the plant and specification 
 * omega-languages.
 *
 * Parameter restrictions: both generators must be deterministic and 
 * refer to the same alphabet.
 *
 *
 * @param rPlantGen
 *   Plant G
 * @param rCAlph
 *   Controllable events
 * @param rSpecGen
 *   Specification Generator E
 * @param rResGen
 *   Reference to resulting Generator to realize
 *   the supremal closed-loop behaviour.
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
extern FAUDES_API void OmegaSupConNB(
  const Generator& rPlantGen, 
  const EventSet&  rCAlph,
  const Generator& rSpecGen, 
  Generator& rResGen);



/**
 * Omega-synthesis 
 *
 * This is the RTI wrapper for   
 * OmegaSupConNB(const Generator&, const EventSet&, const Generator&, Generator&).
 * Controllability attributes are taken from the plant argument.
 * If the result is specified as a System, attributes will be copied
 * from the plant argument.
 *
 *
 * @param rPlantGen
 *   Plant System
 * @param rSpecGen
 *   Specification Generator
 * @param rResGen
 *   Reference to resulting Generator to realize
 *   the supremal closed-loop behaviour.
 *
 * @exception Exception
 *   Alphabets of generators don't match (id 100)
 *   plant nondeterministic (id 201)
 *   spec nondeterministic (id 203)
 *   plant and spec nondeterministic (id 204)
 *
 * @ingroup SynthesisPlugIn
 */
extern FAUDES_API void OmegaSupConNB(
  const System& rPlantGen, 
  const Generator& rSpecGen, 
  Generator& rResGen);


/**
 * Omega-synthesis
 *
 * This procedure first computes the supremal omega-controllable sublanguage as proposed by
 * J. Thistle, 1992, applied to the specific case of deterministoc Buechi automata.
 * It then applies a control pattern to obtain a relatively topologically-closed result,
 * i.e., the topological closure of the result can be used as a supervisor.
 *
 * Parameter restrictions: both generators must be deterministic and 
 * have the same alphabet.
 *
 *
 * @param rPlantGen
 *   Plant G
 * @param rCAlph
 *   Controllable events
 * @param rSpecGen
 *   Specification Generator E
 * @param rResGen
 *   Reference to resulting Generator to realize
 *   the closed-loop behaviour.
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
extern FAUDES_API void OmegaConNB(
  const Generator& rPlantGen, 
  const EventSet&  rCAlph,
  const Generator& rSpecGen, 
  Generator& rResGen);



/**
 * Omega-synthesis 
 *
 * This is the RTI wrapper for   
 * OmegaConNB(const Generator&, const EventSet&, const Generator&, Generator&).
 * Controllability attributes are taken from the plant argument.
 * If the result is specified as a System, attributes will be copied
 * from the plant argument.
 *
 *
 * @param rPlantGen
 *   Plant System
 * @param rSpecGen
 *   Specification Generator
 * @param rResGen
 *   Reference to resulting Generator to realize
 *   the closed-loop behaviour.
 *
 * @exception Exception
 *   Alphabets of generators don't match (id 100)
 *   plant nondeterministic (id 201)
 *   spec nondeterministic (id 203)
 *   plant and spec nondeterministic (id 204)
 *
 * @ingroup SynthesisPlugIn
 */
extern FAUDES_API void OmegaConNB(
  const System& rPlantGen, 
  const Generator& rSpecGen, 
  Generator& rResGen);


/**
 * Omega-synthesis for partial observation (experimental!)
 *
 * Variation of supremal omega-controllable sublanguage to address 
 * normality requirements in the context of partial observation. The test
 * used in this implementation is sufficient but not known to be necessary.
 * Thus, the function may return only a subset of the relevant controllable 
 * prefix.
 *
 * Parameter restrictions: both generators must be deterministic and 
 * have the same alphabet.
 *
 *
 * @param rPlantGen
 *   Plant G
 * @param rCAlph
 *   Controllable events
 * @param rOAlph
 *   Observable events
 * @param rSpecGen
 *   Specification Generator E
 * @param rResGen
 *   Reference to resulting Generator to realize
 *   the supremal closed-loop behaviour.
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
extern FAUDES_API void OmegaSupConNormNB(
  const Generator& rPlantGen, 
  const EventSet&  rCAlph,
  const EventSet&  rOAlph,
  const Generator& rSpecGen, 
  Generator& rResGen);



/**
 * Omega-synthesis for partial observation
 *
 *
 * This is the RTI wrapper for   
 * OmegaSupConNormNB(const Generator&, const EventSet&, const Generator&, Generator&).
 * Controllability attributes and observability attributes are taken from the plant argument.
 * If the result is specified as a System, attributes will be copied
 * from the plant argument.
 *
 *
 * @param rPlantGen
 *   Plant System
 * @param rSpecGen
 *   Specification Generator
 * @param rResGen
 *   Reference to resulting Generator to realize
 *   the supremal closed-loop behaviour.
 *
 * @exception Exception
 *   Alphabets of generators don't match (id 100)
 *   plant nondeterministic (id 201)
 *   spec nondeterministic (id 203)
 *   plant and spec nondeterministic (id 204)
 *
 * @ingroup SynthesisPlugIn
 */
extern FAUDES_API void OmegaSupConNormNB(
  const System& rPlantGen, 
  const Generator& rSpecGen, 
  Generator& rResGen);



/**
 * Omega-synthesis for partial observation (experimental!)
 *
 * Variation of supremal controllable prefix under partial observation.
 * This variation applies a control pattern to obtain a relatively closed and 
 * omega-normal result. The latter properties are validated and an exception
 * is thrown on an error. Thus, this function should not produce "false-positives".
 * However, since it is derived from OmegaSupConNormNB(), is may return the
 * empty languages even if a non-empty controller exists.
 *
 * Parameter restrictions: both generators must be deterministic and 
 * have the same alphabet.
 *
 *
 * @param rPlantGen
 *   Plant G
 * @param rCAlph
 *   Controllable events
 * @param rOAlph
 *   Observable events
 * @param rSpecGen
 *   Specification Generator E
 * @param rResGen
 *   Reference to resulting Generator to realize
 *   the supremal closed-loop behaviour.
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
extern FAUDES_API void OmegaConNormNB(
  const Generator& rPlantGen, 
  const EventSet&  rOAlph,
  const EventSet&  rCAlph,
  const Generator& rSpecGen, 
  Generator& rResGen);



/**
 * Omega-synthesis for partial observation (experimental!)
 *
 * This is the RTI wrapper for   
 * OmegaConNormNB(const Generator&, const EventSet&, const Generator&, Generator&).
 * Controllability attributes are taken from the plant argument.
 * If the result is specified as a System, attributes will be copied
 * from the plant argument.
 *
 *
 * @param rPlantGen
 *   Plant System
 * @param rSpecGen
 *   Specification Generator
 * @param rResGen
 *   Reference to resulting Generator to realize
 *   the closed-loop behaviour.
 *
 * @exception Exception
 *   Alphabets of generators don't match (id 100)
 *   plant nondeterministic (id 201)
 *   spec nondeterministic (id 203)
 *   plant and spec nondeterministic (id 204)
 *
 * @ingroup SynthesisPlugIn
 */
extern FAUDES_API void OmegaConNormNB(
  const System& rPlantGen, 
  const Generator& rSpecGen, 
  Generator& rResGen);




} // namespace faudes

#endif 


