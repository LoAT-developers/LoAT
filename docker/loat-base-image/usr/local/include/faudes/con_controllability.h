/** @file con_controllability.h Conditional Controllability */

/*
 *
 * Copyright (C) 2011 Tomas Masopust
 *
 */

#ifndef FAUDES_ISCC_H
#define FAUDES_ISCC_H

#include "corefaudes.h"
#include "syn_include.h"

namespace faudes {
  
/**
 * Conditionalcontrollability Checking Algorithm
 *
 * Checks whether a given language K over the union of alphabets is conditionally controllable
 * with respect to the plant G.
 * This algorithm implements the results obtained in 
 *
 * J. Komenda, T. Masopust, J. H. van Schuppen.
 * Synthesis of Safe Sublanguages satisfying Global Specification using Coordination Scheme for Discrete-Event Systems 
 * WODES 2010
 *
 * K must be conditionally decomposable
 *
 * @param specVect
 *   Vector of generators representing the specification languages P_{i+k}(K), i=1,2,..,n
 * @param pk
 *   Generator for the coordinator part P_k(K)
 * @param genVect
 *   Vecotr of generators for the plants G1,G2,..,Gn
 * @param gk
 *   Generator for the coordinator Gk
 * @param ACntrl
 *   Event set of all controllable events
 * @return
 *   True if K is conditionaly controllable
 *
 * @exception Exception
 *   - alphabets of generators don't match (id 100)
 *   - plant nondeterministic (id 201)
 *
 * @ingroup CoordinationControlPlugIn
 */
extern FAUDES_API bool IsConditionalControllable(const GeneratorVector& specVect, const Generator& pk, const GeneratorVector& genVect, const Generator& gk, const EventSet& ACntrl);

} // namespace faudes

#endif 
