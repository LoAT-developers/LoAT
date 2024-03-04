/** @file cfl_parallel.h parallel composition */

/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2006  Bernd Opitz
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


#ifndef FAUDES_PARALLEL_H
#define FAUDES_PARALLEL_H

#include "cfl_agenerator.h"
#include <stack>
#include <map>
#include <set>

namespace faudes {


/** 
 * Rti-wrapper for composition maps
 *
 * Parallel-composition and related functions provide an optional
 * argument to record a mapping from original state-indicees to 
 * result state-indicees. In order to support this data type in the
 * run-time interface, we provide a wrapper class that is derived
 * from faudes Type. The curent implementation is minimal (no token io).
 */   
class FAUDES_API ProductCompositionMap : public Type {
  FAUDES_TYPE_DECLARATION(ProductCompositionMap,ProductCompositionMap,Type)
public:
  // std faudes type
  ProductCompositionMap(void);
  ProductCompositionMap(const ProductCompositionMap& rOther);
  virtual ~ProductCompositionMap(void);
  virtual void Clear(void);
  // access C++/STL data
  const std::map< std::pair<Idx,Idx> , Idx >& StlMap(void) const;
  std::map< std::pair<Idx,Idx> , Idx >& StlMap(void);
  void StlMap(const std::map< std::pair<Idx,Idx> , Idx >& rMap);
  // translate states (return 0 on out-of-range)
  Idx CompState(Idx s1, Idx s2) const;
  Idx Arg1State(Idx s12) const;
  Idx Arg2State(Idx s12) const;
protected:
  // std faudes type
  void DoAssign(const ProductCompositionMap& rSrc);
  bool DoEqual(const ProductCompositionMap& rOther) const;
  // my data (primary)
  std::map< std::pair<Idx,Idx> , Idx > mCompositionMap; 
  // my data (derived)
  mutable bool mCompiled;
  mutable std::map<Idx,Idx> mArg1Map; 
  mutable std::map<Idx,Idx> mArg2Map; 
};



/**
 * Parallel composition.
 *
 * Constructs the parallel composition of two generators, where shared events
 * are synchronised while non-shared events are executed independantly. 
 * The resulting generators alphabet is the union of the argument alphabets.
 * In this implementation, only accessible states are generated. 
 * On deterministic input this functions constructs a deterministic output.
 * See also Parallel(const Generator&,std::map< std::pair<Idx,Idx>, Idx>&,const Generator&, Generator&).
 *
 * @param rGen1
 *   First generator
 * @param rGen2
 *   Second generator
 * @param rResGen
 *   Reference to resulting parallel composition generator
 *
 * <h4>Example:</h4>
 * <table border=0> <tr> <td> <table>
 * <tr> <td> Generator G1 </td> <td> Generator G2 </td> </tr>
 * <tr>
 * <td> @image html tmp_parallel_g1.png </td>
 * <td> @image html tmp_parallel_g2.png </td>
 * </tr>
 * </table> </td> </tr> <tr> <td> <table width=100%>
 * <tr> <td> G1 || G2 </td> </tr>
 * <tr> <td> @image html tmp_parallel_g1g2.png </td> </tr>
 * </table> </td> </tr> </table>
 *
 * @ingroup GeneratorFunctions
 *
 */
extern FAUDES_API void Parallel(const Generator& rGen1, const Generator& rGen2, Generator& rResGen);


/**
 * Parallel composition.
 *
 * See also Parallel(const Generator&, const Generator&, Generator&).
 * This version tries to be transparent on event attributes: if
 * argument attributes match and if the result can take the respective
 * attributes, then they are copied; it is considered an error if 
 * argument attributes do not match.
 *
 * @param rGen1
 *   First generator
 * @param rGen2
 *   Second generator
 * @param rResGen
 *   Reference to resulting composition generator
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void aParallel(const Generator& rGen1, const Generator& rGen2, Generator& rResGen);

/**
 * Parallel composition.
 *
 * See also aParallel(const Generator&, const Generator&, Generator&).
 * This version takes a vector of generators as argument to perform
 * a synchronous composition of multiple generators. The implementation
 * calls the std aParallel multiple times, future implementations may
 * explore the overall reachable state set.
 *
 * @param rGenVec
 *   Vector of input generators
 * @param rResGen
 *   Reference to resulting composition generator
 *
 */
extern FAUDES_API void aParallel(const GeneratorVector& rGenVec, Generator& rResGen);



/**
 * Parallel composition.
 *
 * See also Parallel(const Generator&, const Generator&, Generator&).
 * This version fills a composition map to map pairs of old states
 * to new states.
 *
 * @param rGen1
 *   First generator
 * @param rGen2
 *   Second generator
 * @param rCompositionMap
 *   Composition map
 * @param rResGen
 *   Reference to resulting composition generator
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void aParallel(const Generator& rGen1, const Generator& rGen2, ProductCompositionMap& rCompositionMap, Generator& rResGen);




/**
 * Parallel composition.
 *
 * See Parallel(const Generator&, const Generator&, Generator&).
 * This version fills a composition map to map pairs of old states
 * to new states.
 *
 * @param rGen1
 *   First generator
 * @param rGen2
 *   Second generator
 * @param rCompositionMap
 *   Composition map (map< pair<Idx,Idx>, Idx>)
 * @param rResGen
 *   Reference to resulting parallel composition generator
 */
extern FAUDES_API void Parallel(
    const Generator& rGen1, const Generator& rGen2,
    std::map< std::pair<Idx,Idx>, Idx>& rCompositionMap, 
    Generator& rResGen);


/**
 * Parallel composition.
 *
 * See also Parallel(const Generator&, const Generator&, Generator&).
 * This version fills a composition map to map pairs of old states
 * to new states.
 *
 * @param rGen1
 *   First generator
 * @param rGen2
 *   Second generator
 * @param rCompositionMap
 *   Composition map
 * @param rResGen
 *   Reference to resulting composition generator
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void Parallel(const Generator& rGen1, const Generator& rGen2, ProductCompositionMap& rCompositionMap, Generator& rResGen);



/**
 * Parallel composition.
 *
 * See Parallel(const Generator&, const Generator&, Generator&).
 * This version fills a composition map to map pairs of old states
 * to new states. It also returns the sets of states marked w.r.t. the
 * argument generators.
 *
 * @param rGen1
 *   First generator
 * @param rGen2
 *   Second generator
 * @param rCompositionMap
 *   Composition map (map< pair<Idx,Idx>, Idx>)
 * @param rMark2
 *   States maked in first generator
 * @param rMark1
 *   States maked in second generator
 * @param rResGen
 *   Reference to resulting parallel composition generator
 */
extern FAUDES_API void Parallel(
    const Generator& rGen1, const Generator& rGen2,
    ProductCompositionMap& rCompositionMap,
    StateSet& rMark1,
    StateSet& rMark2,
    Generator& rResGen);


/**
 * Product composition.
 * 
 * The product composition executes shared events only. The resulting
 * generators alphabet is the interscetion of the argument alphabets.
 * In this implementation, only accessible states are generated. 
 * Assumes deterministic input generators, result is deterministic.
 *
 * @param rGen1
 *   First generator
 * @param rGen2
 *   Second generator
 * @param rResGen
 *   Reference to resulting product composition generator
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void Product(const Generator& rGen1, const Generator& rGen2, Generator& rResGen);


/**
 * Product composition.
 * 
 * See Product(const Generator&, const Generator&, Generator&).
 * This version fills given composition map to map pairs of old states
 * to new states.
 *
 * @param rGen1
 *   First generator
 * @param rGen2
 *   Second generator
 * @param rCompositionMap
 *   Composition map (map< pair<Idx,Idx>, Idx>)
 * @param rResGen
 *   Reference to resulting product composition generator
 */
extern FAUDES_API void Product(
    const Generator& rGen1, const Generator& rGen2,
    std::map< std::pair<Idx,Idx>, Idx>& rCompositionMap, 
    Generator& rResGen);


/**
 * Product composition.
 * 
 * See Product(const Generator&, const Generator&, Generator&).
 * This version fills given composition map to map pairs of old states
 * to new states. It also returns the sets of states marked w.r.t. the
 * argument generators.
 *
 * @param rGen1
 *   First generator
 * @param rGen2
 *   Second generator
 * @param rCompositionMap
 *   Composition map (map< pair<Idx,Idx>, Idx>)
 * @param rMark2
 *   States maked in first generator
 * @param rMark1
 *   States maked in second generator
 * @param rResGen
 *   Reference to resulting product composition generator
 */
extern FAUDES_API void Product(
    const Generator& rGen1, const Generator& rGen2,
    std::map< std::pair<Idx,Idx>, Idx>& rCompositionMap, 
    StateSet& rMark1,
    StateSet& rMark2,
    Generator& rResGen);


/**
 * Product composition.
 *
 * See also Product(const Generator&, const Generator&, Generator&).
 * This version tries to be transparent on event attributes: if
 * argument attributes match and if the result can take the respective
 * attributes, then they are copied; it is considered an error if 
 * argument attributes do not match.
 *
 * @param rGen1
 *   First generator
 * @param rGen2
 *   Second generator
 * @param rResGen
 *   Reference to resulting product composition generator
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void aProduct(const Generator& rGen1, const Generator& rGen2, Generator& rResGen);


/**
 * Product composition.
 *
 * See also Product(const Generator&, const Generator&, Generator&).
 * This version fills a omposition map to map pairs of old states
 * to new states.
 *
 * @param rGen1
 *   First generator
 * @param rGen2
 *   Second generator
 * @param rCompositionMap
 *   Composition map
 * @param rResGen
 *   Reference to resulting composition generator
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void aProduct(const Generator& rGen1, const Generator& rGen2, ProductCompositionMap& rCompositionMap, Generator& rResGen);

/**
 * Helper: uses composition map to track state names
 * in a paralell composition. Purely cosmetic.
 *
 * @param rGen1
 *   First generator
 * @param rGen2
 *   Second generator
 * @param rCompositionMap
 *   Composition map (map< pair<Idx,Idx>, Idx>)
 * @param rGen12
 *   Reference to resulting parallel composition generator
 */
extern FAUDES_API void SetComposedStateNames(
    const Generator& rGen1, const Generator& rGen2,
    const std::map< std::pair<Idx,Idx>, Idx>& rCompositionMap, 
    Generator& rGen12);

} // namespace faudes


#endif 

