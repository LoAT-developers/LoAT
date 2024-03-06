/** @file cfl_project.h language projection */

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


#ifndef FAUDES_PROJECT_H
#define FAUDES_PROJECT_H

#include "cfl_definitions.h"
#include "cfl_agenerator.h"

namespace faudes {


/**
 * Language projection.
 *
 * Projects the generated and marked languages to another alphabet.
 * Transitions with events not in the projection alphabet are considered 
 * invisible and therefor acordingly relinked with a visible lable to the appropriate 
 * successor state. The projection alphabet is intended (but not required) to be 
 * a subset of the original alphabet. 
 *
 * The default implementation is based on a local forward reachability analysis per state. 
 * It known to suffer from performance issues for certain large automata. This was 
 * in particular the case for the variation used in libFAUDES 2.14 up to 2.23. A number of 
 * alternatives are now available in "cfl_project.cpp" and can bet set as the default by adjusting 
 * the respective wrapper function (grep for "wrapper" in "cfl_project.cpp"). If you experience
 * trouble with the current revision, you can set the default to revert to pre libFAUDES 2.24 behaviour --
 * and please report back to us. The candidate for future releases is available for testing,
 * see ProjectNonDetScc(Generator&, const EventSet&).
 *
 * The results in general is nondeterministic. The input generator does not need to 
 * be deterministic. See Project(const Generator&,const EventSet&, Generator&) for
 * a version with deterministic result. 
 *
 *
 * @param rGen
 *   Reference to generator
 * @param rProjectAlphabet
 *   Projection alphabet
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void ProjectNonDet(Generator& rGen, const EventSet& rProjectAlphabet);



/**
 * Language projection.
 *
 * Projects the generated and marked languages to another alphabet, see
 * also ProjectNonDetScc(Generator&, const EventSet&). This implementation
 * first eliminates silent strongly connected components and then applies a
 * local backward reachability analysis. Performance benefits are significant for
 * certain large generators.
 *
 * The input generator does not need to be deterministic. The results in general 
 * is nondeterministic. You may manually invoke Deterministic() to convert the result.
 *
 *
 * @param rGen
 *   Reference to generator
 * @param rProjectAlphabet
 *   Projection alphabet
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void ProjectNonDetScc(Generator& rGen, const EventSet& rProjectAlphabet);

/**
 * Deterministic projection. 
 *
 * Projects the generated and marked languages to a subalphabet of the original alphabet, 
 * and subsequently calls Deterministic to construct a deterministic 
 * realisation of the result. The input generator does not need to be deterministic.
 *
 * @param rGen
 *   Reference to generator
 * @param rProjectAlphabet
 *   Projection alphabet
 * @param rResGen
 *   Reference to resulting deterministic generator
 *
 * <h4>Example:</h4>
 * <table>
 * <tr> <td> Generator G </td> <td> Project(G,(a,c,g,e),Result) </td> </tr>
 * <tr>
 * <td> @image html tmp_project_g.png </td>
 * <td> @image html tmp_project_prog.png </td>
 * </tr>
 * </table> 
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void Project(const Generator& rGen, const EventSet& rProjectAlphabet, Generator& rResGen);

/**
 * Deterministic projection. 
 *
 * See also Project(const Generator&, const EventSet&, Generator&).
 * This version tries to be transparent on event attributes: if
 * argument attributes match and if the result can take the respective
 * attributes, then they are copied; it is considered an error if 
 * argument attributes do not match.
 *
 * @param rGen
 *   Reference to generator
 * @param rProjectAlphabet
 *   Projection alphabet
 * @param rResGen
 *   Reference to resulting deterministic generator
 *
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void aProject(const Generator& rGen, const EventSet& rProjectAlphabet, Generator& rResGen);

/**
 * Language projection.
 *
 * See also ProjectNonDet(const Generator&, const EventSet&).
 * This version tries to be transparent on event attributes: result maintains
 * its attributes. 
 *
 * @param rGen
 *   Reference to generator
 * @param rProjectAlphabet
 *   Projection alphabet
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void aProjectNonDet(Generator& rGen, const EventSet& rProjectAlphabet);


/**
 * Deterministic projection. 
 * 
 * Projects the generated and marked languages to a subalphabet of the original alphabet, 
 * and subsequently calls Deterministic to construct a deterministic minimal
 * realisation of the result. The input generator does not need to be deterministic.
 *
 * @param rGen
 *   Reference to generator
 * @param rProjectAlphabet
 *   Projection alphabet
 * @param rEntryStatesMap
 *   Reference to entry states map, see Deterministic(..) (result)
 * @param rResGen
 *   Reference to resulting deterministic generator (result)
 */
extern FAUDES_API void Project(const Generator& rGen, const EventSet& rProjectAlphabet,
		      std::map<Idx,StateSet>& rEntryStatesMap, Generator& rResGen);

/**
 * Inverse projection. This adds selfloop transition at every state for
 * all missing events.
 *
 * @param rGen
 *   Reference to generator
 * @param rProjectAlphabet
 *   Alphabet for inverse projection
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void InvProject(Generator& rGen, const EventSet& rProjectAlphabet);

/**
 * Inverse projection. This adds selfloop transition at every state for
 * all missing events. This version tries to be transparent to attributes.
 *
 * @param rGen
 *   Reference to generator
 * @param rProjectAlphabet
 *   Alphabet for inverse projection
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void aInvProject(Generator& rGen, const EventSet& rProjectAlphabet);


/**
 * Inverse projection. This adds selfloop transition at every state for
 * all missing events. This version tries to be transparent to attributes.
 *
 * @param rGen
 *   Reference to argumant generator
 * @param rProjectAlphabet
 *   Alphabet for inverse projection
 * @param rResGen
 *   Alphabet to result.
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void aInvProject(const Generator& rGen, const EventSet& rProjectAlphabet, Generator& rResGen);


} // namespace faudes

#endif 

