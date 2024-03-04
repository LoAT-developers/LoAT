/** @file con_decomposability_extension.h Conditionaldecomposability */

/*
 *
 * Copyright (C) 2012, 2015 Tomas Masopust
 *
 */

#ifndef FAUDES_CDEx_H
#define FAUDES_CDEx_H

#include "corefaudes.h"

namespace faudes {
  
/**
 * Conditionaldecomposability Extension Algorithm
 *
 * Given a language K over the union of alphabets, 
 * the algorithm extends the alphabet ek so that K is conditionally decomposable.
 * This algorithm implements the results obtained in 
 *
 * J. Komenda, T. Masopust, J. H. van Schuppen.
 * On Conditional Decomposability
 * Preprint
 *
 * The generator gen must be deterministic, and
 * ek must contain the intersection of all subalphabets and be included in their union.
 *
 * @param gen
 *   Generator representing the language K, i.e., Lm(gen)=K
 * @param rAlphabets
 *   A vector of alphabets (at least two alphabets are required)
 * @param ek
 *   The alhabet Ek that contains intersection of other alphabets and is included in their union
 *
 * @return
 *   True Ek so that K is conditionally decomposible
 *
 * @exception Exception
 *   - alphabets of generators don't match (id 100)
 *   - plant nondeterministic (id 201)
 *
 * @ingroup CoordinationControlPlugIn
 */
extern FAUDES_API void ConDecExtension(const Generator& gen, const EventSetVector& rAlphabets, EventSet& ek);

extern FAUDES_API void CDExt(const Generator& gen, const EventSetVector& ee, const EventSet& unionset, EventSet& ek);

extern FAUDES_API Generator ComputeTildeG(const EventSet& unionset, const EventSetVector& ee, const EventSet& ek, const Generator& gen);

extern FAUDES_API bool isExtendedEk(const Generator& tildeGen, const Generator& rGen, EventSet& ek);

} // namespace faudes

#endif 
