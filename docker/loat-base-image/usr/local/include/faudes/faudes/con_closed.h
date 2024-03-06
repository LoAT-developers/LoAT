/** @file con_closed.h Conditional Closedness */

/*
 *
 * Copyright (C) 2011 Tomas Masopust
 *
 */

#ifndef FAUDES_ISCCl_H
#define FAUDES_ISCCl_H

#include "corefaudes.h"
#include "syn_include.h"

namespace faudes {
  
/**
 * Conditionalclosedness Checking Algorithm
 *
 * Checks whether a given language K is conditionally closed
 * with respect to plants G_i, i=1,2,..,n.
 * This algorithm implements the results obtained in 
 *
 * J. Komenda, T. Masopust, J. H. van Schuppen.
 * Synthesis of controllable and normal sublanguages for discrete-event systems using a coordinator
 * Systems & Control Letters 60(7), 492-502, 2011
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
 * @return
 *   True if K is conditionaly closed
 *
 * @exception Exception
 *   - alphabets of generators don't match (id 100)
 *   - plant nondeterministic (id 201)
 *
 * @ingroup CoordinationControlPlugIn
 */
extern FAUDES_API bool IsConditionalClosed(const GeneratorVector& specVect, const Generator& pk, const GeneratorVector& genVect, const Generator& gk);

} // namespace faudes

#endif 
