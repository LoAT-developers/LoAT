
/** @file cfl_regular.h 

Operations on regular languages.
See [Cassandras and Lafortune. Introduction to Discrete Event Systems] for an
introduction to regular language operations.
Operations are always performed on language(s) marked by the passed generator(s),
resulting in the language(s) marked by the resulting generator(s).
Only if mentioned extra, the same is done for the involved generated (prefix-closed)
languages.

*/

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


#ifndef FAUDES_REGULAR_H
#define FAUDES_REGULAR_H

#include "cfl_definitions.h"
#include "cfl_parallel.h"
#include "cfl_project.h" 

namespace faudes {

/**
 * Language union, nondeterministic version.
 *
 * This function performs the union of two languages marked by two generators;
 * the resulting generator marks the resulting language.
 * Moreover, the same is done for the involved generated (prefix-closed) languages.
 * Method:
 * This function implements the textbook version in taking unions of all generator
 * entities (alphabets, initial states, ...) of rGen1 and rGen2. State sets are taken
 * as disjoint by definition and thus reindexed and renamed to achieve disjoint union.
 * The resulting language is defined over the union of the alphabets of the original
 * languages; original languages defined over different alphabets are treated as if
 * they were defined over the union of both alphabets.
 * 
 * Determinism:
 * Input parameters may be nondeterministic.
 * This function is more economical than the deterministic version, but likely to
 * produce a non-deterministic result; see also LanguageUnion().
 *
 * No restrictions on parameters.
 *
 * @param rGen1
 *   generator generating/marking L1/Lm1
 * @param rGen2
 *   generator generating/marking L2/Lm2
 * @param rResGen
 *   resulting generator generating/marking the language union of L1 and L2/of Lm1 and Lm2
 *
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void LanguageUnionNonDet(const Generator& rGen1, const Generator& rGen2, 
    Generator& rResGen);

/**
 * Language union, deterministic version.
 *
 * This function performs the union of two languages marked by two generators;
 * the resulting generator marks the resulting language.
 * Moreover, the same is done for the involved generated (prefix-closed) |languages.
 * Method:
 * This function implements the textbook version (which textbook??) in taking unions
 * of all generator entities (alphabets, initial states, ...). State sets are taken
 * as disjoint by definition and thus reindexed and renamed to achieve disjoint union.
 * The resulting language is defined over the union of the alphabets of the original
 * languages.
 *
 * Determinism:
 * Input parameters may be nondeterministic.
 * This function calls LanguageUnionNonDet() and then Deterministic() to convert the 
 * result into a deterministic generator. Note that this conversion is usually
 * straightforward, but there exist theoretical worst-case examples of exponential complexity.
 *
 * No restrictions on parameters.
 *
 * ToDo: a version similar to parallel composition that produces a deterministic result by construction. (?)
 *
 * @param rGen1
 *   generator generating/marking L1/Lm1
 * @param rGen2
 *   generator generating/marking L2/Lm2
 * @param rResGen
 *   resulting generator generating/marking the language union of L1 and L2/of Lm1 and Lm2
 * 
 * <h4>Example:</h4>
 * <table border=0> <tr> <td> <table>
 * <tr> <td> Generator G1 </td> <td> Generator G2 </td> </tr>
 * <tr>
 * <td> @image html tmp_boolean_g1.png </td>
 * <td> @image html tmp_boolean_g2.png </td>
 * </tr>
 * </table> </td> </tr> <tr> <td> <table width=100%>
 * <tr> <td> LanguageUnion(G1,G2,Result) </td> </tr>
 * <tr> <td> @image html tmp_union_g1g2.png </td> </tr>
 * </table> </td> </tr> </table>
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void LanguageUnion(const Generator& rGen1, const Generator& rGen2,
		Generator& rResGen);

/**
 * Language union.
 *
 * See also LanguageUnion(const Generator&, const Generator&, Generator&);
 * This version takes a vector of generators as argument to perform
 * the union for multiple languages. The implementation
 * calls the std union multiple times, future implementations may
 * do better.
 *
 * @param rGenVec
 *   Vector of input generators
 * @param rResGen
 *   Reference to resulting generator
 *
 */
extern FAUDES_API void LanguageUnion(const GeneratorVector& rGenVec, Generator& rResGen);


/**
 * Language intersection.
 *
 * This function performs the intersection of two languages marked by two generators;
 * the resulting generator marks the resulting language.
 * Moreover, the same is done for the involved generated (prefix-closed) languages.
 * The resulting languages are defined over the intersection of the involved alphabets.
 * Method:
 * This function calls Product(). In the product of two automata, an event occurs if
 * and only if it occurs in both automata rGen1 and rGen2. The result generates/marks
 * the intersection of the involved languages, see e.g.
 * [Cassandras, Lafortune. Introduction to Discrete Event Systems, p.84]
 *
 * Determinism:
 * Input parameters may be nondeterministic.
 * Result can be nondeterministic only if input parameters are nondeterministic.
 *
 * No restrictions on parameters.
 *
 * @param rGen1
 *   generator generating/marking L1/Lm1
 * @param rGen2
 *   generator generating/marking L2/Lm2
 * @param rResGen
 *   resulting generator generating/marking the language intersection of L1 and L2/of Lm1 and Lm2
 *
 * <h4>Example:</h4>
 *
 * <table border=0> <tr> <td> <table>
 * <tr> <td> Generator G1 </td> <td> Generator G2 </td> </tr>
 * <tr>
 * <td> @image html tmp_boolean_g1.png </td>
 * <td> @image html tmp_boolean_g2.png </td>
 * </tr>
 * </table> </td> </tr> <tr> <td> <table width=100%>
 * <tr> <td> LanguageIntersection(G1,G2,Result) </td> </tr>
 * <tr> <td> @image html tmp_intersection_g1g2.png </td> </tr>
 * </table> </td> </tr> </table>
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void LanguageIntersection(const Generator& rGen1, const Generator& rGen2, 
		Generator& rResGen);
        
/**
 * Language intersection.
 *
 * See also LanguageUnion(const Generator&, const Generator&, Generator&);
 * This version takes a vector of generators as argument to perform
 * the intersection for multiple languages. The implementation
 * calls the std intersection multiple times, future implementations may
 * do better.
 *
 * @param rGenVec
 *   Vector of input generators
 * @param rResGen
 *   Reference to resulting generator
 *
 */
extern FAUDES_API void LanguageIntersection(const GeneratorVector& rGenVec, Generator& rResGen);


/**
 * Test for empty language intersection  (same as Disjoind()).
 *
 * This function checks if the intersection of two languages marked by two generators
 * is empty that is the two languages are disjoint.
 * The involved generated (prefix-closed) languages are not considered. This function
 * is identical to Disjoint().
 *
 * No restrictions on parameters.
 *
 * @param rGen1
 *   generator marking Lm1
 * @param rGen2
 *   generator marking Lm2
 *
 * @return
 *   true if language intersection is empty, false if not.
 *
 * @ingroup GeneratorFunctions
 */  
extern FAUDES_API bool EmptyLanguageIntersection(const Generator& rGen1, const Generator& rGen2);

/**
 * Test whether two languages are disjoint.
 *
 * This function tests whether the intersection of two languages marked by two generators
 * is empty, ie the two languages are disjoint.
 * The involved generated (prefix-closed) languages are not considered. This function
 * is identical to EmptyLanguageIntersection().
 *
 * No restrictions on parameters.
 *
 * @param rGen1
 *   generator marking Lm1
 * @param rGen2
 *   generator marking Lm2
 *
 * @return
 *   true if language intersection is empty, false if not.
 *
 * @ingroup GeneratorFunctions
 */  
extern FAUDES_API bool LanguageDisjoint(const Generator& rGen1, const Generator& rGen2);

/**
 * Convert generator to automaton.
 *
 * Convert a generator marking the language Lm into a formal automaton recognizing Lm
 * with a dump state representing Sigma*-PrefixClosure(Lm). In this function, Sigma is
 * given by the alphabet of rGen; see also Automaton(rGen,rAlphabet).
 * For information about automata, see [Wonham. Supervisory Control of Discrete Event
 * Systems].
 * The original generated language is ignored.
 * Note: An automaton is a deterministic transition structure according to the formal
 *       definition; see also "Determinism" below.
 * Method:
 * Uncoaccessible states are erased, as the language generated by rGen is not examined
 * in this function. A dump state representing "Sigma*-PrefixClosure(Lm)" is created.
 * Then, the transition relation is completed such that it is fully defined for each
 * state and each event. Formerly undefined transitions lead to the dump state.
 *
 * Determinism:
 * Input parameter has to be deterministic for correct result. If not, then the 
 * (also nondeterministic) result recognizes the correct language, but the dump state
 * does not represent "Sigma*-PrefixClosure(Lm)" as it should;
 * see also example ExAutomaton_basic().
 * If FAUDES_CHECKED is defined a warning on non-deterministic input is issued.
 * 
 * No further restrictions on parameter.
 * 
 * @param rGen
 *   generator that is converted to automaton
 *
 * <h4>Example:</h4>
 * <table>
 * <tr> <td> Generator G </td> <td> Automaton(G) </td> </tr>
 * <tr>
 * <td> @image html tmp_automaton_g.png </td>
 * <td> @image html tmp_automaton_gRes.png </td>
 * </tr>
 * </table> 
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void Automaton(Generator& rGen);

/**
 * Convert generator to automaton wrt specified alphabet.
 *
 * Convert a generator marking the language Lm into a formal automaton recognizing Lm
 * with a dump state representing Sigma*-PrefixClosure(Lm(rGen)). In this function,
 * Sigma is given by the parameter rAlphabet.
 * For information about automata, see [Wonham. Supervisory Control of Discrete Event
 * Systems].
 * The original generated language is ignored.
 * Note: An automaton is a deterministic transition structure according to the formal
 *       definition; see also "Determinism" below.
 * Method:
 * Uncoaccessible states are erased, as the language generated by rGen is not examined
 * in this function. A dump state representing "Sigma*-PrefixClosure(Lm)" is created.
 * Then, the transition relation is completed such that it is fully defined for each
 * state of rGen and each event of rAlphabet. Formerly undefined transitions lead to
 * the dump state.
 *
 * Determinism:
 * Input parameter has to be deterministic for correct result. If not, then the 
 * (also nondeterministic) result recognizes the correct language, but the dump state
 * does not represent "Sigma*-PrefixClosure(Lm)" as it should;
 * see also example ExAutomaton_basic().
 * If FAUDES_CHECKED is defined a warning on non-deterministic input is issued.
 * 
 * No further restrictions on parameters.
 * 
 * @param rGen
 *   generator that is converted to automaton
 *
 * @param rAlphabet
 *   the dump state of the resulting automaton represents the
 *   language L_dump=rAlphabet*-PrefixClosure(Lm(rGen))
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void Automaton(Generator& rGen, const EventSet& rAlphabet);

/**
 * Language complement.
 *
 * Convert generator marking the language Lm into generator marking the language
 * complement of Lm which is defined as Sigma*-Lm. In this function, Sigma is
 * given by the alphabet of rGen; see also LanguageComplement(rGen,rAlphabet).
 * The original generated language is ignored.
 * Method:
 * This function calls Automaton() first and then inverts the marking of the states
 * of the result.
 *
 * Determinism:
 * Input parameter has to be deterministic for correct result, see Automaton() for
 * explanations.
 * If FAUDES_CHECKED is defined a warning on non-deterministic input is issued.
 * (by function Automaton()).
 *
 * No further restrictions on parameter.
 *
 * @param rGen
 *   generator on which the language complement is performed
 *
 * <h4>Example:</h4>
 * <table>
 * <tr> <td> Generator G </td> <td> LanguageComplement(G) </td> </tr>
 * <tr>
 * <td> @image html tmp_boolean_g1.png </td>
 * <td> @image html tmp_complement_g1.png </td>
 * </tr>
 * </table> 
 *
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void LanguageComplement(Generator& rGen);

/**
 * Language complement wrt specified alphabet.
 *
 * Convert generator marking the language Lm into generator marking the language
 * complement of Lm which is defined as Sigma*-Lm. In this function, Sigma is
 * given by the parameter rAlphabet.
 * The original generated language is ignored.
 * Method:
 * This function calls Automaton() first and then inverts the marking of the states
 * of the result.
 *
 * Determinism:
 * Input parameter has to be deterministic for correct result, see Automaton() for
 * explanations.
 * If FAUDES_CHECKED is defined a warning on non-deterministic input is issued.
 * (by function Automaton()).
 *
 * No further restrictions on parameter.
 *
 * @param rGen
 *   generator on which the language complement is performed
 *
 * @param rAlphabet
 *   reference alphabet to build the complement
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void LanguageComplement(Generator& rGen, const EventSet& rAlphabet);


/** 
 * Language Complement (uniform API wrapper). 
 *
 * @param rGen
 *   generator on which the language complement is performed
 *
 * @param rRes
 *   resulting generator
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void LanguageComplement(const Generator& rGen, Generator& rRes);

/** 
 * Language Complement (uniform API wrapper).
 *
 * @param rGen
 *   generator on which the language complement is performed
 *
 * @param rSigma
 *   reference alphabet to build the complement
 *
 * @param rRes
 *   resulting generator
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void LanguageComplement(const Generator& rGen, const EventSet& rSigma, Generator& rRes);



/**
 * Language difference (set-theoretic difference).
 *
 * This function calculates Lm1-Lm2 (sometimes also denoted by Lm1\\Lm2), that is the
 * set of all strings included in Lm1 but not in Lm2.
 * Method:
 * The language difference is computed by taking the intersection of Lm1 with the
 * complement of Lm2.
 * 
 * Determinism:
 * Due to the use of LanguageComplement(), rGen2 has to be deterministic.
 * Result can be nondeterministic only if rGen1 is nondeterministic.
 *
 * Restrictions on prameters:
 * rGen2 has to be deterministic.
 *
 * @param rGen1 
 *  generator marking the language Lm1
 * @param rGen2
 *  generator marking the language Lm2 
 * @param rResGen
 *  generator marking the language difference Lm1-Lm2 
 *
 * @exception Exception
 *   - nondeterministic parameter rGen2 (id 101). 
 *
  * <h4>Example:</h4>
 * <table border=0> <tr> <td> <table>
 * <tr> <td> Generator G1 </td> <td> Generator G2 </td> </tr>
 * <tr>
 * <td> @image html tmp_difference_g1.png </td>
 * <td> @image html tmp_difference_g2.png </td>
 * </tr>
 * </table> </td> </tr> <tr> <td> <table width=100%>
 * <tr> <td> LanguageDifference(G1,G2,Result) </td> </tr>
 * <tr> <td> @image html tmp_difference_g1minusg2.png </td> </tr>
 * </table> </td> </tr> </table>
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void LanguageDifference(const Generator& rGen1, const Generator& rGen2,
                 Generator& rResGen);

/**
 * Language concatenation, nondeterministic version.
 *
 * With the languages Lm1 and Lm2 marked by rGen1 and rGen2, respectively, the result
 * rResGen marks the concatenation LmRes=Lm1Lm2.
 * The languages generated by rGen1 and rGen2 are ignored. It would be possible to let
 * the result also generate the concatenation of the generated languages; however, this can
 * produce disproportionate computational overhead, if only the marked languages shall be
 * concatenated.
 * Method:
 * rGen2 is appended to rGen1: first, the initial states of rGen2 are erased. Then,
 * transitions, that formerly started from the initial state(s) of rGen2, are redirected 
 * and multiplied such that they start from each marked state of rGen1. The marked states
 * corresponding to rGen2 remain marked. The marked states of rGen1 remain marked only if
 * rGen2 has at least one marked initial state (i.e. if epsilon is concatenated to Lm1.)
 * 
 * Determinism:
 * Input parameters may be nondeterministic. Result can be nondeterministic even if input
 * parameters are deterministic; see also LanguageConcatenate().
 *
 * No restrictions on parameters.
 * 
 * @param rGen1
 *   generator marking Lm1
 * @param rGen2
 *   generator marking Lm2
 * @param rResGen
 *   resulting generator marking the language concatenation Lm1Lm2
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void LanguageConcatenateNonDet(const Generator& rGen1, const Generator& rGen2,
		Generator& rResGen);

/**
 * Language concatenation, deterministic version.
 *
 * With the languages Lm1 and Lm2 marked by rGen1 and rGen2, respectively, the result
 * rResGen marks the concatenation LmRes=Lm1Lm2.
 * The languages generated by rGen1 and rGen2 are ignored. It would be possible to let
 * the result also generate the concatenation of the generated languages; however, this can
 * produce disproportionate computational overhead, if only the marked languages shall be
 * concatenated.
 * Method:
 * rGen2 is appended to rGen1: first, the initial states of rGen2 are erased. Then,
 * transitions, that formerly started from the initial state(s) of rGen2, are redirected 
 * and multiplied such that they start from each marked state of rGen1. The marked states
 * corresponding to rGen2 remain marked. The marked states of rGen1 remain marked only if
 * rGen2 has at least one marked initial state (i.e. if epsilon is concatenated to Lm1.)
 * 
 * Determinism:
 * Input parameters may be nondeterministic.
 * This function calls LanguageUnionNonDet() and then Deterministic() to convert the 
 * result into a deterministic generator. Note that this conversion is usually
 * straightforward, but there exist theoretical worst-case examples of exponential complexity.
 *
 * No restrictions on parameters.
 * 
 * @param rGen1
 *   generator marking Lm1
 * @param rGen2
 *   generator marking Lm2
 * @param rResGen
 *   Resulting generator marking the language concatenation Lm1Lm2
 *
 * <h4>Example:</h4>
 * <table border=0> <tr> <td> <table>
 * <tr> <td> Generator G1 </td> <td> </td> <td> LanguageConcatenate(G1,G3,Result) </td> </tr>
 * <tr>
 * <td> @image html tmp_concat_g1.png </td>
 * <td> </td>
 * <td> @image html tmp_concat_g1g3.png </td>
 * </tr>
 * <tr> <td> Generator G2 </td> <td> </td> <td> LanguageConcatenate(G1,G4,Result) </td> </tr>
 * <tr>
 * <td> @image html tmp_concat_g2.png </td>
 * <td> </td> 
 * <td> @image html tmp_concat_g1g4.png </td>
 * </tr>
 * </tr>
 * <tr> <td> Generator G3 </td> <td> </td> <td> LanguageConcatenate(G2,G3,Result) </td> </tr>
 * <tr>
 * <td> @image html tmp_concat_g3.png </td>
 * <td> </td> 
 * <td> @image html tmp_concat_g2g3.png </td>
 * </tr>
 * </tr>
 * <tr> <td> Generator G4 </td> <td> </td> <td> LanguageConcatenate(G2,G4,Result) </td> </tr>
 * <tr>
 * <td> @image html tmp_concat_g4.png </td>
 * <td> </td> 
 * <td> @image html tmp_concat_g2g4.png </td>
 * </tr>
 * </table> </td> </tr> </table>
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void LanguageConcatenate(const Generator& rGen1, const Generator& rGen2,
		Generator& rResGen);

/**
 * Full Language, L(G)=Lm(G)=Sigma*.
 *
 * Construct generator generating and marking full language Sigma* from alphabet Sigma.
 * Method: this function creates a generator with one state that is marked and init state. This
 * state is selflooped with all events from rAlphabet.
 *
 * @param rAlphabet
 *   Alphabet Sigma from which full language Sigma* is built
 * @param rResGen
 *   Generator generating and marking full language Sigma*
 *
 * <h4>Example:</h4>
 * <table>
 * <tr> <td> FullLanguage(Sigma={a,b},Result) </td> </tr>
 * <tr>
 * <td> @image html tmp_languagesFull_result.png </td>
 * </tr>
 * </table> 
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void FullLanguage(const EventSet& rAlphabet, Generator& rResGen);

/**
 * Alphabet Language, L(G)=Lm(G)=Sigma
 *
 * Construct generator generating and marking an alphabet as languages, that is L(G)=Lm(G)=Sigma.
 * Method: this function creates a generator with one init state and one marked state. For each
 * event from rAlphabet, a transition is inserted leading from the init state to the marked state.
 *
 * No restrictions on parameters.
 * 
 * @param rAlphabet
 *   alphabet from which alphabet language is built
 * @param rResGen
 *   generator with languages Lm(G)=Sigma
 *
 * <h4>Example:</h4>
 * <table>
 * <tr> <td> AlphabetLanguage(Sigma={a,b},Result) </td> </tr>
 * <tr>
 * <td> @image html tmp_languagesAlphabet_result.png </td>
 * </tr>
 * </table> 
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void AlphabetLanguage(const EventSet& rAlphabet, Generator& rResGen);

/**
 * Empty string language, L(G)=Lm(G)={epsilon}.
 *
 * Construct generator generating and marking the empty string, that is L(G)=Lm(G)={epsilon}.
 * Method: this function creates a generator with one marked init state and the alphabet rAlphabet.
 *
 * No restrictions on parameters.
 * 
 * @param rAlphabet
 *   alphabet of the resulting generator
 * @param rResGen
 *   generator with languages L(G)=Lm(G)={epsilon} and alphabet rAlphabet
 *
 * <h4>Example:</h4>
 * <table>
 * <tr> <td> EmptyStringLanguage(Sigma={a,b},Result) </td> </tr>
 * <tr>
 * <td> @image html tmp_languagesEmptyString_result.png </td>
 * </tr>
 * </table> 
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void EmptyStringLanguage(const EventSet& rAlphabet, Generator& rResGen);

/**
 * Empty language Lm(G)={}.
 *
 * Construct generator and marking the empty language, that is Lm(G)={}.
 * Method: this function creates a deterministic generator with one initial state that is not marked. 
 * The alphabet is set as specified. 
 *
 * No restrictions on parameters.
 * 
 * @param rAlphabet
 *   Alphabet of the resulting generator
 * @param rResGen
 *   Generator with language Lm(G)={}
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void EmptyLanguage(const EventSet& rAlphabet, Generator& rResGen);

/**
 * Test for Empty language Lm(G)=={}.
 *
 * Tests if the language marked by rGen is empty, that is if Lm(G)=={}. The generated
 * language L(G) is not considered.
 * Method:
 * This function tests if 
 * a) the set of marked states is empty or else
 * b) the intersection of the set of accessible states and the set of marked states
 * is empty, i.e. if there is no marked state or if no marked state is accessible (reachable).
 *
 * No restrictions on parameter.
 *
 * @param rGen
 *   generator to be tested for empty marked language
 *
 * @return
 *   true on empty marked language, false on nonempty marked language
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API bool IsEmptyLanguage(const Generator& rGen);

/**
 * Test language inclusion, Lm1<=Lm2.
 *
 * Test if language Lm1 marked by rGen1 is included in language Lm2 marked by rGen2. The
 * generated languages are not considered.
 * Method:
 * This function checks if there is no string in Lm1 that is not in Lm2 by testing if
 * the intersection of Lm1 and the language complement of Lm2 is empty.
 *
 * Restrictions on parameters: rGen2 has to be deterministic!
 * If FAUDES_CHECKED is defined a warning on non-deterministic input is issued.
 * (by function Automaton()).
 *
 * Determinism: correctness in case of nondeterministic parameter rGen1 has been tested with an
 *              example (see ExInclusion_simple), but not proven.
 *
 * ToDo: implement faster version using a variant of Product():
 * compute product without storing result, return false as soon as some event is
 * possible in Lm2 but not in Lm1.
 *
 * @param rGen1
 *   generator marking Lm1
 * @param rGen2
 *   generator marking Lm2
 *
 * @return
 *   true if language marked by rGen1 is included in language marked by rGen2
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API bool LanguageInclusion(const Generator& rGen1, const Generator& rGen2);

/**
 * Language equality, Lm1==Lm2.
 *
 * Test if the language Lm1 marked by rGen1 equals the language Lm2 marked by rGen2. The
 * generated languages are not considered.
 * Method:
 * This function checks mutual inclusion of Lm1 in Lm2 and of Lm2 in Lm1 using the
 * function LanguageInclusion().
 *
 * Restrictions on parameters: rGen1 and rGen2 have to be deterministic!
 * If FAUDES_CHECKED is defined a warning on non-deterministic input is issued.
 * (by function Automaton()).
 *
 * ToDo: implement faster, version using a variant of Product():
 * compute product without storing result, return false as soon as rGen1 and rGen2
 * "disagree" on the occurrence of some event.
 *
 * @param rGen1
 *   generator marking Lm1
 * @param rGen2
 *   generator marking Lm2
 *
 * @return
 *   true if the language marked by rGen1 equals the language marked by rGen2
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API bool LanguageEquality(const Generator& rGen1, const Generator& rGen2);

/**
 * Kleene Closure.
 *
 * This function computes the Kleene Closure ( ()* - operator) of the
 * language marked by rGen. The generated language is not considered.
 * Method: KleeneClosureNonDet() is called, which, for all transitions
 * leading from a state x to a marked state, inserts a transition with the
 * same event starting from x and leading to (one of) the initial state(s).
 * As this step causes nondeterminism, the function Deterministic() is called.
 * See also KleeneClosureNonDet().
 *
 * No restrictions on parameter.
 *
 * @param rGen
 *   generator marking the language Lm to which the Kleene Closure is applied
 *
 * <h4>Example:</h4>
 * <table>
 * <tr> <td> Generator G </td> <td> KleeneClosure(G) </td> </tr>
 * <tr>
 * <td> @image html tmp_kleene_g.png </td>
 * <td> @image html tmp_kleene_gRes.png </td>
 * </tr>
 * </table> 
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void KleeneClosure(Generator& rGen);

/**
 * Kleene Closure.
 *
 * This function is a convenience wrapper for KleeneClosure(Generator&).
 *
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void KleeneClosure(const Generator& rGen, Generator& rResGen);

/**
 * Kleene Closure, nondeterministic version.
 *
 * This function computes the Kleene Closure ( ()* - operator) of the
 * language marked by rGen. The generated language is not considered.
 * Method: KleeneClosureNonDet() is called, which, for all transitions
 * leading from a state x to a marked state, inserts a transition with the
 * same event starting from x and leading to (one of) the initial state(s).
 *
 * @param rGen
 *   generator marking the language Lm to which Kleene Closure is applied
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void KleeneClosureNonDet(Generator& rGen);

/**
 * Prefix Closure.
 *
 * This function computes the prefix closure the language Lm marked by rGen. A
 * language Lm is prefix closed if each string of Lm implies that all its
 * prefixes are also element of Lm. The prefix closure of a language marked by
 * a generator is always a subset of the generated language and is represented
 * by the set of coaccessible states of the generator.
 * Method:
 * First, Coaccessible() is called to erase all states of rGen that do not
 * represent prefixes of marked strings. Then, all remaining states are marked.
 *
 * No restrictions on parameter.
 *
 * ToDo: (slightly) more efficient version: implement generator function
 * CoAccessibleSet() similar to AccessibleSet() and call
 * InjectMarkedStates(AccessibleSet()).
 *
 * @param rGen
 *   generator marking the language Lm to which prefix closure is applied
 *
 * <h4>Example:</h4>
 * <table>
 * <tr> <td> Generator G </td> <td> PrefixClosure(G) </td> </tr>
 * <tr>
 * <td> @image html tmp_prefixclosure_g.png </td>
 * <td> @image html tmp_prefixclosure_gRes.png </td>
 * </tr>
 * </table>
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void PrefixClosure(Generator& rGen);


/**
 * Test for prefix closed marked language.
 *
 * This function tests whether the language Lm(G) marked by the specified generator G
 * is prefix closed. It does so by testing whether all accessible and coaccessible
 * states are marked. 
 *
 * The specified generator must be deterministic.
 *
 * @param rGen
 *   generator G marking the Lm(G) to test
 * @return
 *   True <> Lm(G) is prefix closed
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API bool IsPrefixClosed(const Generator& rGen);


/**
 * Test for nonblocking generator
 *
 * A generator G is nonblocking if closure(Lm(G)) = L(G), i.e.
 * if every accessible state is coacessile.
 *
 * The specified generator must be deterministic.
 *
 * @param rGen
 *   generator G marking to test
 * @return
 *   True <> G is nonblocking
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API bool IsNonblocking(const Generator& rGen);

/**
 * Test for nonblocking marked languages.
 *
 * Two languages L1 and L2 are nonblocking, if
 * closure(L1 || L2) == closure(L1) || closure(L2).
 *
 * This function performs the parallel composition of the two
 * specified generators and tests it for nonblockingness. Provided
 * that both generators are trim, this is equivalent to the
 * respective marked languages being nonblocking.
 *
 * The specified generators must be trim.
 *
 * @param rGen1
 *   Generator G1
 * @param rGen2
 *   Generator G2
 * @return
 *   True <> Lm(G1) and Lm(G2) are nonblocking
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API bool IsNonblocking(const Generator& rGen1, const Generator& rGen2);


/**
 * Self-loop all states.
 *
 * This function selfoops all states of rGen with the events from rAlphabet.
 * Method:
 * The alphabet of rGen is extended by rAlphabet. For each state x of rGen
 * and each event alpha of rAlphabet, a transition (x,alpha,x) is inserted,
 * irrespective of whether this event was already active in x before.
 * See also SelfLoop(rGen,rAlphabet,rStates) and SelfLoopMarkedStates(rGen,rAlphabet).
 *
 * No restrictions on parameter.
 *
 * Determinism: resulting generator is nondeterministic, if it was nondeterministic
 * before, or if rGen already contains one or more (non selfloop) transitions with
 * events from rAlphabet.
 *
 * @param rGen
 *   generator to be selflooped with events from rAlphabet
 * @param rAlphabet
 *   alphabet with selfloop events
 *
 * <h4>Example:</h4>
 * <table>
 * <tr> <td> Generator G </td> <td> SelfLoop(G,Sigma={e,f}) </td> </tr>
 * <tr>
 * <td> @image html tmp_selfloop_g.png </td>
 * <td> @image html tmp_selfloop_gRes.png </td>
 * </tr>
 * </table>
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void SelfLoop(Generator& rGen,const EventSet& rAlphabet);

/**
 * Self-loop all marked states.
 *
 * This function selfoops all marked states of rGen with the events from rAlphabet.
 * Method:
 * The alphabet of rGen is extended by rAlphabet. For each marked state x of rGen
 * and each event alpha of rAlphabet, a transition (x,alpha,x) is inserted,
 * irrespective of whether this event was already active in x before.
 * See also SelfLoop(rGen,rAlphabet) and SelfLoop(rGen,rAlphabet,rStates).
 *
 * No restrictions on parameter.
 *
 * Determinism: resulting generator is nondeterministic, if it was nondeterministic
 * before, or if rGen already contains one or more (non selfloop) transitions
 * starting from a marked state with events from rAlphabet.
 *
 * @param rGen
 *   generator with marked states to be selflooped with events from rAlphabet
 * @param rAlphabet
 *   alphabet with selfloop events
 *
 * <h4>Example:</h4>
 * <table>
 * <tr> <td> Generator G </td> <td> SelfLoopMarkedStates(G,Sigma={e,f}) </td> </tr>
 * <tr>
 * <td> @image html tmp_selfloop_g.png </td>
 * <td> @image html tmp_selfloopMarked_gRes.png </td>
 * </tr>
 * </table>
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void SelfLoopMarkedStates(Generator& rGen,const EventSet& rAlphabet);

/**
 * Self-loop specified states.
 *
 * This function selfoops the states rStates of rGen with the events from rAlphabet.
 * Method:
 * The alphabet of rGen is extended by rAlphabet. For each state x of rStates
 * and each event alpha of rAlphabet, a transition (x,alpha,x) is inserted,
 * irrespective of whether this event was already active in x before.
 * See also SelfLoop(rGen,rAlphabet) and SelfLoopMarkedStates(rGen,rAlphabet).
 *
 * No restrictions on parameter.
 *
 * Determinism: resulting generator is nondeterministic, if it was nondeterministic
 * before, or if rGen already contains one or more (non selfloop) transitions
 * starting from a state of rState with events from rAlphabet.
 *
 * @param rGen
 *   generator with marked states to be selflooped with events from rAlphabet
 * @param rAlphabet
 *   alphabet with selfloop events
 * @param rStates
 *   states to apply selfloop
 *
 * @exception Exception
 *   - rStates is not a subset of rGen.States() (id 100). 
 *
 * <h4>Example:</h4>
 * <table>
 * <tr> <td> Generator G </td> <td> SelfLoop(G,Sigma={e,f},G.InitStates()) </td> </tr>
 * <tr>
 * <td> @image html tmp_selfloop_g.png </td>
 * <td> @image html tmp_selfloopInit_gRes.png </td>
 * </tr>
 * </table>
 *
 * @ingroup GeneratorFunctions
 */
extern FAUDES_API void SelfLoop(Generator& rGen,const EventSet& rAlphabet,const StateSet& rStates);




} // namespace faudes

#define FAUDES_REGULAR_H
#endif 

