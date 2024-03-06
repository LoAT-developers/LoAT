/** @file con_decomposability.h Conditional Decomposability */

/*
 *
 * Copyright (C) 2011, 2015 Tomas Masopust
 *
 */

#ifndef FAUDES_ISCD_H
#define FAUDES_ISCD_H

#include "corefaudes.h"

namespace faudes {
  
/**
 * Conditionaldecomposability Checking Algorithm
 *
 * Checks whether a given language K over the union of alphabets is conditionally decomposable
 * with respect to these alphabets and ek.
 * This algorithm implements the results obtained in 
 *
 * J. Komenda, T. Masopust, J. H. van Schuppen.
 * On Nonblockingness and Conditional Decomposability
 * Manuscript
 *
 * The generator gen must be deterministic, and
 * ek must contain the intersection of all subalphabets and be included in their union.
 *
 * @param gen
 *   Generator representing the language K, i.e., Lm(gen)=K
 * @param ee
 *   A vector of alphabets (at least two alphabets are required)
 * @param ek
 *   The alhabet Ek that contains intersection of other alphabets and is included in their union
 * @param proof
 *   A generator which gives the proof that the language K is NOT conditionally decomposable
 *
 * @return
 *   True if K is conditionaly decomposible
 *
 * @exception Exception
 *   - alphabets of generators don't match (id 100)
 *   - plant nondeterministic (id 201)
 *
 * @ingroup CoordinationControlPlugIn
 */
extern FAUDES_API bool IsConditionalDecomposable(const Generator& gen, const EventSetVector& ee, const EventSet& ek, Generator& proof);
extern FAUDES_API bool IsCD(const Generator& gen, const EventSetVector& ee, const EventSet& ek, const EventSet& unionset, Generator& proof);

} // namespace faudes

#endif 
