/** @file ios_algorithms.h Algorithms addressing I/O-systems */

/* 
   IO Systems Plug-In 
   for FAU Discrete Event Systems Library (libFAUDES)

   Copyright (C) 2010, Thomas Wittmann, Thomas Moor
   Copyright (C) 2015, Thomas Moor

*/

#ifndef FAUDES_IOS_ALGORITHMS
#define FAUDES_IOS_ALGORITHMS

#include "ios_system.h"

namespace faudes {

/**
 * Test whether the system satisfies basic I/O conditions.
 *
 * The I/O conditions tested are
 * - Lm(G) is complete (each string can be extended);
 * - U and Y are a disjoint decomposition of Sigma;
 * - neither U nor Y is empty;
 * - U and Y events alternate;
 *
 * To test the last propertie, the procedure partitions the state 
 * set in states QU that enable input events and states QY that enables
 * output-put events. The latter two state sets are returned in rQY and rQU. 
 * States that either block or enable both input and outputs are
 * return in rQErr.
 *
 * Note: this procedure is not concerned with whether the first event
 * should be an input or an output; neither does it require the input
 * to be free; see  bool IsInputLocallyFree(IoSystem&).
 *
 * Note: this procedure does not set the state attributes;
 * see also bool IsIoSystem(IoSystem&).
 * 
 * @param rIoSystem
 *   Generator to test.
 * @param rQY
 *    Output states
 * @param rQU
 *    Input states
 * @param rQErr
 *    Undecided states
 * @return
 *   True <> system is an io system.
 *
 * @ingroup IoSysPlugin 
 */
extern FAUDES_API bool IsIoSystem(const IoSystem& rIoSystem,
  StateSet& rQU,
  StateSet& rQY,
  StateSet& rQErr);


/**
 * Test whether the system satisfies the IO conditions.
 *
 * Performs the same tests as 
 * bool IsIoSystem(const IoSystem&,StateSet&,StateSet&,StateSet&), but
 * does set the state attributes accordingly.
 *
 * @param rIoSystem
 *   Generator to test.
 * @return
 *   True <> system is an io system.
 *
 * @ingroup IoSysPlugin 
 */
extern FAUDES_API bool IsIoSystem(IoSystem& rIoSystem);


/**
 * Construct io state partition.
 *
 * This is an rti wrapper for  bool IsIoSystem(IoSystem&).
 *
 *
 * @param rIoSystem
 *   Generator to test.
 *
 */
extern FAUDES_API void IoStatePartition(IoSystem& rIoSystem);


/**
 * Test whether the system has a locally free input.
 *
 * The procedure returns True, if every state that enables some
 * input event enables all input events. If the system in addition
 * satisfies the basic I/O properties, a locally free input implies
 * that the behaviour induced by the generated closed language 
 * exhibits a free input in the behavioural sense. This implication
 * does not hold for the behaviour induced by the marked language. 
 *
 * If the test fails, any critical states are returned in rQErr.
 *
 * @param rIoSystem
 *   Generator to test.
 * @param rQErr
 *   Error states.
 * @return
 *   True <> system has an omega-free input
 *
 * @ingroup IoSysPlugin 
 */
extern FAUDES_API  bool IsInputLocallyFree(const IoSystem& rIoSystem, StateSet& rQErr);


/**
 * Test whether the system has a locally free input.
 *
 * See also bool IsInputLocallyFree(const IoSystem&,StateSet&).
 * This version will set the state error attribute to the set
 * of critical states.
 *
 * @param rIoSystem
 *   Generator to test.
 * @return
 *   True <> system has a locally-free input
 *
 * @ingroup IoSysPlugin 
 */
extern FAUDES_API bool IsInputLocallyFree(IoSystem& rIoSystem);


/**
 * Enable all input events for each input state.
 *
 * If this procedure detetecs a state with some but not all 
 * input events enabled, an error state is introduced
 * and transitions with the missing input events are inserted.
 * The error state is setup to allow any alternating sequence 
 * of input and output events.
 *
 * Note that his procedure only ensures a locally free input. It does
 * not guarantee a free input in the behavioural sense.
 *
 * It is considered an error if the specified set of input events
 * is not contained in the generator alphabet.
 *
 * @param rIoSystem
 *   Generator argument.
 * @param rUAlph
 *   Input alphabet
 *
 * @exception Exception
 *   - Alphabets don't match (id 100)
 *
 * @ingroup IoSysPlugin 
 */
extern FAUDES_API void IoFreeInput(Generator& rIoSystem, const EventSet& rUAlph);


/**
 * Enable all input events for each input state.
 *
 * Alternative interface to IoFreeInput(Generator&, const EventSet&),
 * which extracts the input alphabet from the given IO System.
 *
 * @param rIoSystem
 *   Generator argument.
 * @ingroup IoSysPlugin 
 */
extern FAUDES_API void IoFreeInput(IoSystem& rIoSystem);


/**
 * Remove dummy states.
 *
 *
 * @param rIoSystem
 *   Generator argument.
 * @ingroup IoSysPlugin 
 */
extern FAUDES_API void RemoveIoDummyStates(IoSystem& rIoSystem);


/**
 * Test whether the system behaviour exhibits a free input.
 *
 * The procedure assumes that the specified system satisfies
 * the basic I/O properties. It returns True, if it has a locally
 * free input and additionally can allways control its output to
 * reach a marked state. Technically, the latter condition can be stated
 * as a controllability condition, referring to the notion of omega-controllabilaty
 * in the definition of Thistle/Wonham.
 * 
 * This implementation performs the test in that it iteratively constructs
 * a set of "good" states: a state is good, if
 *
 * - it is marked, or
 * - it can be controlled to a good state by disableing output events
 *
 * If all reachable states are good, the test is passed. Else, all other state
 * are reported as error states.
 *
 * @param rIoSystem
 *   Generator to test.
 * @param rQErr
 *   Error states.
 * @return
 *   True <> system has an omega-free input
 *
 * @ingroup IoSysPlugin 
 */
extern FAUDES_API bool IsInputOmegaFree(const IoSystem& rIoSystem, StateSet& rQErr);


/**
 * Test whether the system behaviour has exhibits a free input.
 *
 * See also bool IsInputOmegaFree(const IoSystem&,StateSet&).
 * This version will set the error flag for stytes that conflict with
 * a free input.
 *
 * @param rIoSystem
 *   Generator to test.
 * @return
 *   True <> system has an omega-free input
 *
 * @ingroup IoSysPlugin 
 */
extern FAUDES_API bool IsInputOmegaFree(IoSystem& rIoSystem);



/**
 * IO system synthesis. 
 * 
 * This method esentially is a wrapper for SupConComplete(), which implements
 * a synthesis procedure to compute the supremal controllable and complete
 * sublanguage for a given plant and specification. Input events are regarded
 * controllable. marking is ignored, i.e., synthesis refers to the generated
 * langugaes rather than the the marked languages. For a version
 * thet refers to Buchi acceptance condition, see 
 * IoSynthesisNB(const IoSystem&, const Generator&, IoSystem&).
 *
 * The resulting supervisor is an IO System with
 * the plant input events as outputs and vice versa. 
 *
 * Note that this routine does not test whether the plant has a locally 
 * free input U, nor does it ensure that the resulting supervisor has a
 * free input Y.
 *
 * @param rPlant
 *   IO-System - plant model
 * @param rSpec
 *   Generator - specification
 * @param rSup
 *   IO-System - supervisor
 *
 * @exception Exception
 *   - Any exceptions passed on from SupConComplete
 *
 */
extern FAUDES_API void IoSynthesis(const IoSystem& rPlant, const Generator& rSpec, IoSystem& rSup);

/**
 * IO system synthesis. 
 * 
 * This method esentially is a wrapper for SupConOmegaNB(), which implements
 * a synthesis procedure to compute the supremal omega-controllable.
 * sublanguage for a given plant and specification. Input events are regarded
 * controllable. In contrast to IoSynthesis(const IoSystem&, const Generator&, IoSystem&),
 * this procedure refers to the Bucji acceptance condition and ensures
 * a omega-nonblocking closed-loop behaviour.
 *
 * The resulting supervisor is an IO System with
 * the plant input events as outputs and vice versa. 
 *
 * Note that this routine does not test whether the plant has a locally 
 * free input U, nor does it ensure that the resulting supervisor has a
 * free input Y.
 *
 * @param rPlant
 *   IO-System - plant model
 * @param rSpec
 *   Generator - specification
 * @param rSup
 *   IO-System - supervisor
 *
 * @exception Exception
 *   - Any exceptions passed on from SupConOmegaNB
 *
 */
extern FAUDES_API void IoSynthesisNB(const IoSystem& rPlant, const Generator& rSpec, IoSystem& rSup);

}
#endif
