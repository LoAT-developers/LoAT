/** @file con_controllability.h Conditional Controllability */

/*
 *
 * Copyright (C) 2012 Tomas Masopust
 *
 */

#ifndef FAUDES_SUPCC_H
#define FAUDES_SUPCC_H

#include "corefaudes.h"
#include "con_include.h"
#include "op_include.h"
#include "syn_include.h"

namespace faudes {
  
/**
 * Conditionalcontrollability Checking Algorithm
 *
 * Computation of the supremal conditionally controllable sublanguage of a given language K 
 * with respect to the plant G.
 * This algorithm implements the results obtained in 
 *
 * J. Komenda, T. Masopust, J. H. van Schuppen.
 * Synthesis of Safe Sublanguages satisfying Global Specification using Coordination Scheme for Discrete-Event Systems 
 * WODES 2010 (and its Automatica version)
 *
 * @param gen
 *   Generator for the specification language K
 * @param genVector
 *   Vector of generators for the plants G1,G2,..,Gn
 * @param ACntrl
 *   Controllable events
 * @param InitEk
 *   evenset
 * @param supVector
 *   Vector of generators; 
 *   supervisors supC_{i+k} such that ||supC_{i+k} is the supremal
 *   conditionally controllable sublanguage of K are returned in this vector
 * @param Coord
 *   a generator;
 *   computed coordinator is returned in this parameter
 * @return
 *   Returns the supVector of supervisors and the computer coordinator
 *
 * @exception Exception
 *   - alphabets of generators don't match (id 100)
 *   - plant nondeterministic (id 201)
 *
 * @ingroup CoordinationControlPlugIn
 */
extern FAUDES_API bool SupConditionalControllable(
	const Generator& gen, 
	const GeneratorVector& genVector, 
	const EventSet& ACntrl,
	const EventSet& InitEk,
	GeneratorVector& supVector,
	Generator& Coord);

} // namespace faudes

#endif 
