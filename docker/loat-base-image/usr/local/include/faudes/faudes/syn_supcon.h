/** @file syn_supcon.h Supremal controllable sublanguage */

/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2006  Bernd Opitz
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

 
#ifndef FAUDES_SUPCON_H
#define FAUDES_SUPCON_H

#include "corefaudes.h"
#include <stack>

namespace faudes {
    


/**
 * Test controllability
 *
 * Tests whether the candidate supervisor H is controllable w.r.t.
 * the plant G. This implementation does not require the supervisor H to 
 * represent a sublanguage of the plant G. 
 * 
 * Parameter restrictions: both generators must be deterministic and 
 * share the same alphabet.
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
 *   - alphabets of generators don't match (id 100)
 *   - plant generator nondeterministic (id 201)
 *   - specification generator nondeterministic (id 203)
 *   - plant and Spec generator nondeterministic (id 204)
 *
 * @return 
 *   true / false
 *
 * @ingroup SynthesisPlugIn
 */
extern FAUDES_API bool IsControllable(const Generator& rPlantGen, const EventSet&  rCAlph, const Generator& rSupCandGen);


/**
 * Test controllability.
 *
 * Tests whether the candidate supervisor H is controllable w.r.t.
 * the plant G. This implementation does not require the supervisor H to 
 * represent a sublanguage of the plant G. 
 * 
 *
 * If the candidate fails to be controllable, this version will return a set of 
 * "critical" states of the candidate supervisor. These states are characterised by 
 *  (a) being reachable in the parallel composition of plant and supervisor 
 *  (b) disabeling an uncontrollable transition of the plant
 * Note: this was reimplemented in libFAUDES 2.20b.
 *
 * Parameter restrictions: both generators must be deterministic and 
 * have the same alphabet.
 *
 * @param rPlantGen
 *   Plant G 
 * @param rCAlph
 *   Controllable events
 * @param rSupCandGen
 *   Supervisor candicate H 
 * @param rCriticalStates
 *   Set of critical states
 *
 * @exception Exception
 *   - alphabets of generators don't match (id 200)
 *   - plant generator nondeterministic (id 201)
 *   - specification generator nondeterministic (id 203)
 *   - plant and Spec generator nondeterministic (id 204)
 *
 * @return 
 *   true / false
 *
 * @ingroup SynthesisPlugIn
 */
extern FAUDES_API bool IsControllable(
  const Generator& rPlantGen, 
  const EventSet&  rCAlph,
  const Generator& rSupCandGen, 
  StateSet& rCriticalStates);


/**
 * Test controllability. 
 *
 * Tests whether the candidate supervisor h is controllable w.r.t.
 * the plant g; this is a System wrapper for IsControllable
 *
 * @param rPlantGen
 *   Plant g generator
 * @param rSupCandGen
 *   Supervisor candidate h generator 
 *
 * @exception Exception
 *   Alphabets of generators don't match (id 500)
 *   Plant generator nondeterministic (id 501)
 *   Specification generator nondeterministic (id 503)
 *   Plant & Spec generator nondeterministic (id 504)
 *
 * @return 
 *   true / false
 *
 * @ingroup SynthesisPlugIn
 */
extern FAUDES_API bool IsControllable(
  const System& rPlantGen, 
  const Generator& rSupCandGen);


/**
 * Nonblocking Supremal Controllable Sublanguage
 *
 * Given a generator G (argument rPlantGen) and a specification language E (marked by argument rSpecGen), 
 * this procedures computes an automaton S such that
 *  Lm(S) is the supremal controllable sublanguage of Lm(G) ^ Lm(E) w.r.t. L(G).
 * The result is given as a trim deterministic generator that 
 * may be used to supervise G in order to enforce E. 
 *
 * See "C.G CASSANDRAS AND S. LAFORTUNE. Introduction to Discrete Event 
 * Systems. Kluwer, 1999." for base algorithm.
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
 *   Specification Generator to mark E
 * @param rResGen
 *   Reference to resulting Generator, the
 *   minimal restrictive nonblocking supervisor
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
extern FAUDES_API void SupConNB(
  const Generator& rPlantGen, 
  const EventSet&  rCAlph,
  const Generator& rSpecGen, 
  Generator& rResGen);



/**
 * Nonblocking Supremal Controllable Sublanguage 
 *
 * This is the RTI wrapper for   
 * SupConNB(const Generator&, const EventSet&, const Generator&, Generator&).
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
extern FAUDES_API void SupConNB(
  const System& rPlantGen, 
  const Generator& rSpecGen, 
  Generator& rResGen);



/**
 * Supremal Controllable and Closed Sublanguage
 *
 * Given a closed plant language L and a closed specification E, this function
 * computes a realisation of the supremal controllable and closed sublanguage
 * of L^E. Arguments and result generate the respective language (i.e. marked
 * languages are not considered.)
 *
 * Parameter restrictions: both generators must be deterministic and 
 * have the same alphabet.
 *
 * @param rPlantGen
 *   Plant L generated by rPlantGen 
 * @param rCAlph
 *   Controllable events
 * @param rSpecGen
 *   Specification E generated rSpecGen
 * @param rResGen
 *   Reference to resulting Generator, the
 *   minimal restrictive supervisor
 *
 * @exception Exception
 *   - alphabets of generators don't match (id 100)
 *   - plant nondeterministic (id 201)
 *   - spec nondeterministic (id 203)
 *   - plant and spec nondeterministic (id 204)
 *
 * @ingroup SynthesisPlugIn
 */
extern FAUDES_API void SupConClosed(
  const Generator& rPlantGen, 
  const EventSet&  rCAlph,
  const Generator& rSpecGen, 
  Generator& rResGen);


/** 
 * Supremal Controllable and Closed Sublanguage.
 * 
 * This is the RTI wrapper for   
 * SupCon(const Generator&, const EventSet&, const Generator&, Generator&).
 *
 * Controllability attributes are taken from the plant argument.
 * If the result is specified as a System, attributes will be copied
 * from the plant argument.
 *
 * @param rPlantGen
 *   Plant System 
 * @param rSpecGen
 *   Specification Generator 
 * @param rResGen
 *   Reference to resulting Generator, the
 *   minimal restrictive supervisor
 *
 * @exception Exception
 *   Alphabets of generators don't match (id 100)
 *   plant nondeterministic (id 201)
 *   spec nondeterministic (id 203)
 *   plant and spec nondeterministic (id 204)
 *
 * @ingroup SynthesisPlugIn
 */
extern FAUDES_API void SupConClosed(
  const System& rPlantGen, 
  const Generator& rSpecGen, 
  Generator& rResGen);

/** 
 * Supremal Controllable and Closed Sublanguage.
 * 
 * Implementation of  SupConClosed.
 *
 * See "C.G CASSANDRAS AND S. LAFORTUNE. Introduction to Discrete Event 
 * Systems. Kluwer, 1999." for base algorithm.
 *
 * This version sets up a "composition map" provided as a reference parameter.
 * The map is restricted such that its range matches the resulting supervisor.
 * 
 * @param rPlantGen
 *   Plant Generator 
 * @param rCAlph
 *   Controllable events
 * @param rSpecGen
 *   Specification Generator 
 * @param rReverseCompositionMap
 *   std::map< std::pair<Idx,Idx>, Idx> as in the parallel composition function
 * @param rResGen
 *   Reference to resulting Generator, the
 *   minimal restrictive supervisor
 *
 * @exception Exception
 *   - alphabets of generators don't match (id 100)
 *   - plant nondeterministic (id 201)
 *   - spec nondeterministic (id 203)
 *   - plant and spec nondeterministic (id 204)
 */
extern FAUDES_API void SupConClosed(
  const Generator& rPlantGen, 
  const EventSet&  rCAlph,
  const Generator& rSpecGen, 
  std::map< std::pair<Idx,Idx>,Idx >& rReverseCompositionMap, 
  Generator& rResGen);



/** 
 * Nonblocking Supremal Controllable Sublanguage (internal function)
 * 
 * This version of SupConNB performs no consistency test of the given parameter.
 * It set's up a "composition map" as in the parallel composition, however,
 * the map may still contain states that have been removed from the result
 * to obtain controllability.
 * 
 * @param rPlantGen
 *   Plant Generator 
 * @param rCAlph
 *   Controllable events
 * @param rSpecGen
 *   Specification Generator 
 * @param rReverseCompositionMap
 *   std::map< std::pair<Idx,Idx>, Idx> as in the parallel composition function
 * @param rResGen
 *   Reference to resulting System, the
 *   minimal restrictive nonblocking supervisor
 *
 * @exception Exception
 *   - alphabets of generators don't match (id 100)
 *   - plant nondeterministic (id 201)
 *   - spec nondeterministic (id 203)
 *   - plant and spec nondeterministic (id 204)
 */
extern FAUDES_API void SupConNBUnchecked(
  const Generator& rPlantGen, 
  const EventSet&  rCAlph,
  const Generator& rSpecGen, 
  std::map< std::pair<Idx,Idx>,Idx >& rReverseCompositionMap, 
  Generator& rResGen);



/**
 * Supremal Controllable Sublangauge (internal function)
 *
 * Indentifies and deletes "critical" states in the supervisor candidate,
 * in order to achieve controllability. 
 * This version of SupConClosed performs no consistency test of the given parameter.
 * In order to obtain indeed the supremal sublanguage, the state space of the candidate
 * must be rich enough to discriminate plant states. This can be done by e.g. setting
 * up the candidate SupConParallel. 
 *
 * In general, the result is blocking.
 *
 * @param rPlantGen
 *   Plant generator
 * @param rCAlph
 *   Controllable events
 * @param rSupCandGen
 *   Supervisor candidate generator
 *
 *
 */
extern FAUDES_API void SupConClosedUnchecked(
   const Generator& rPlantGen, 
   const EventSet&  rCAlph,
   Generator& rSupCandGen);


/** 
 * Parallel composition optimized for the purpose of SupCon (internal function)
 * 
 * Composition stops at transition paths that violate the specification
 * by uncontrollable plant transitions. 
 *
 * This internal function performs no consistency test of the given parameter.
 * It set's up a "composition map" as in the product composition, however,
 * the map may still contain states that have been removed from the result
 * to obtain controllability.
 * 
 * @param rPlantGen
 *   Plant Generator 
 * @param rCAlph
 *   Uncontrollable Events
 * @param rSpecGen
 *   Specification Generator 
 * @param rReverseCompositionMap
 *   std::map< std::pair<Idx,Idx>, Idx> as in the parallel composition function
 * @param rResGen
 *   Reference to resulting Generator, the
 *   less restrictive supervisor
 */
extern FAUDES_API void SupConProduct(
  const Generator& rPlantGen, 
  const EventSet& rCAlph, 
  const Generator& rSpecGen,
  std::map< std::pair<Idx,Idx>, Idx>& rReverseCompositionMap, 
  Generator& rResGen);

/**
 * Controllability (internal function)
 *
 * Checks if language of specification h is controllable with respect to
 * language of generator g.  Only for deterministic plant + spec. 
 * Controllable event set has to be given as parameter.
 *
 * This internal function performs no consistency test of the given parameter.
 *
 * @param rPlantGen
 *   Plant generator
 * @param rCAlph
 *   Controllable events
 * @param rSpecGen
 *   Specification generator
 * @param rCriticalStates
 *   Set of critical states
 *
 * @exception Exception
 *   - alphabets of generators don't match (id 100)
 *   - plant generator nondeterministic (id 201)
 *   - specification generator nondeterministic (id 203)
 *   - plant & spec generator nondeterministic (id 204)
 *
 * @return 
 *   true / false
 */
extern FAUDES_API bool IsControllableUnchecked(
  const Generator& rPlantGen, 
  const EventSet& rCAlph, 
  const Generator& rSpecGen, 
  StateSet& rCriticalStates);


/**
 * Helper function for IsControllable. The state given as "current" is
 * considered critical. Itself and all uncontrollable predecessor states 
 * are added to the set "rCriticalStates". 
 *
 * @param rCAlph
 *   Set of controllable events
 * @param rtransrel
 *   Reverse sorted transition relation
 * @param rCriticalStates
 *   Set of critical states in composition generator
 * @param current
 *   Current state
 */
extern FAUDES_API void TraverseUncontrollableBackwards(
  const EventSet& rCAlph, 
  TransSetX2EvX1& rtransrel, 
  StateSet& rCriticalStates, 
  Idx current);



/**
 * Consistency check for controlproblem input data.
 * Tests whether alphabets match and generators are deterministic.
 *
 * @param rPlantGen
 *   Plant generator
 * @param rCAlph
 *   Controllable events
 * @param rSpecGen
 *   Specification generator
 *
 * @exception Exception
 *   - lphabets of generators don't match (id 100)
 *   - plant generator nondeterministic (id 201)
 *   - specification generator nondeterministic (id 203)
 *   - plant and spec generator nondeterministic (id 204)
 */
extern FAUDES_API void ControlProblemConsistencyCheck(
  const Generator& rPlantGen, 
  const EventSet&  rCAlph,
  const Generator& rSpecGen);

/**
 * Consistency check for controlproblem input data.
 * Tests whether alphabets match and generators are deterministic.
 *
 * @param rPlantGen
 *   Plant generator
 * @param rCAlph
 *   Controllable events
 * @param rOAlph
 *   Observable events
 * @param rSpecGen
 *   Specification generator
 *
 * @exception Exception
 *   - lphabets of generators don't match (id 100)
 *   - plant generator nondeterministic (id 201)
 *   - specification generator nondeterministic (id 203)
 *   - plant and spec generator nondeterministic (id 204)
 */
extern FAUDES_API void ControlProblemConsistencyCheck(
  const Generator& rPlantGen, 
  const EventSet&  rCAlph,
  const EventSet&  rOAlph,
  const Generator& rSpecGen);







} // namespace faudes

#endif 


