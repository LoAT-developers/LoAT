/** @file con_cctrim.h more efficient Trim() operation */

/*
 *
 * Copyright (C) 2011 Tomas Masopust
 *
 * Implements a bit more efficient Trim() operation
 * based on graph algorithms
 *
 */

#ifndef FAUDES_ccTRIM_H
#define FAUDES_ccTRIM_H

#include "corefaudes.h"

namespace faudes {
  
/**
 * A more efficient Trim() operation
 *
 * @param gen
 *   The input generator to be trimmed
 * @param trimGen
 *   The trimmed generator
 *
 * @return
 *   True if the operation is successful
 *
 * @exception Exception
 *   - alphabets of generators don't match (id 100)
 *   - plant nondeterministic (id 201)
 *
 * @ingroup CoordinationControlPlugIn
 */
extern FAUDES_API bool ccTrim(const Generator& gen, Generator& trimGen);

} // namespace faudes

#endif 
