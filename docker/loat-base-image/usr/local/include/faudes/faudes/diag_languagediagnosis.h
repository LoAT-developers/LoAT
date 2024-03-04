/** @file diag_languagediagnosis.h
Functions to check a system's diagnosability with respect to a specification automaton and compute a language-diagnoser.
*/

#ifndef DIAG_LANGUAGEDIAGNOSIS_H
#define DIAG_LANGUAGEDIAGNOSIS_H

#include <vector>
#include "corefaudes.h"
#include "diag_generator.h"
#include "diag_eventdiagnosis.h"
#include "op_obserververification.h"

#include "diag_debug.h"

namespace faudes {

///////////////////////////////////////////////////////////////////////////////
// Functions for specification framework
///////////////////////////////////////////////////////////////////////////////
/** @name Functions (diagnosability with respect to a specification) */
/** @{ doxygen group */

/**
Tests a system's diagnosability with respect to a given specification. 
@param rGen
  Input generator.
@param rSpec 
  Specification automaton. 
@param rReportString
  User-readable information of violating condition (in case of negative test result).
@return
  True if input generator is diagnosable.
@ingroup DiagnosisPlugIn
*/
extern FAUDES_API bool IsLanguageDiagnosableX(const System& rGen, const System& rSpec, std::string& rReportString);

/** @} doxygen group */

/**
Compute G_o for a generator that marks the faulty behaviour of a plant. 
Every specification violation will be labelled with label "F".
@param rGenMarkedNonSpecBehaviour
  Input generator that specifies specification violations by marked states. 
@param rGobs
  Output variable for G_o.
*/
extern FAUDES_API void ComputeGobs(const System& rGenMarkedNonSpecBehaviour, Diagnoser& rGobs);

/**
Compute the reachability from a state of a generator that marks its faulty behaviour. 
States are said to be reachable if they can be reached through a trace that consists 
of arbitrarily many unobservable events followed by one observable event. 
@param rGen
  Input generator.
@param rUnobsEvents
  Unobservable events in the generators alphabet.
@param State
  A state of the generators state set.
@param rReachabilityMap
  Output variable for the reachability. Maps occurring observable events to the reachable generator states and a label that contains information about specification violations.
*/
extern FAUDES_API void ComputeReachability(const System& rGen, const EventSet& rUnobsEvents, Idx State, 
                std::map<Idx,std::multimap<Idx,DiagLabelSet> >& rReachabilityMap);

/**
Auxiliary function for ComputeReachability(const System&, const EventSet&, Idx State,  std::map<Idx,std::multimap< Idx,DiagLabelSet> >&). Is recursively called for every occurring state on the trace (that consists of arbitrarily many unobservable events followed by one observable event).
@param rGen
  Input generator.
@param rUnobsEvents
  Unobservable events in the generators alphabet. 
@param State
  The current state within the trace. 
@param done
  Progress.
@param rReachabilityMap
  Output variable for the reachability. Maps occurring observable events to the reachable generator states and a label that contains information about specification violations. 
 */                      
void ComputeReachabilityRecursive(const System& rGen, const EventSet& rUnobsEvents, Idx State, StateSet done, 
                     std::map<Idx,std::multimap<Idx,DiagLabelSet> >& rReachabilityMap);


/**
 * Function definition for run-time interface 
 */
extern FAUDES_API bool IsLanguageDiagnosable(const System& rGen, const System& rSpec);

enum VerifierStateLabel{NORMAL,CONFUSED,BLOCK};

struct VerifierState{
	Idx mSpec1State;
	Idx mSpec2State;
	Idx mPlantState;
	VerifierStateLabel mLabel;
	
	
	VerifierState(Idx state1 = 0, Idx state2 = 0, Idx state3 = 0, VerifierStateLabel label = NORMAL){ mSpec1State = state1; mSpec2State = state2; mPlantState = state3; mLabel = label; }

	bool operator<  (const VerifierState&   rOther) const{
		if(mSpec1State < rOther.mSpec1State)
			return true;
		else if(mSpec1State > rOther.mSpec1State)
			return false;
		if(mSpec2State < rOther.mSpec2State)
			return true;
		else if(mSpec2State > rOther.mSpec2State)
			return false;
		if(mPlantState < rOther.mPlantState)
			return true;
		else 
			return false;
	}
};

/** 
  * Test function to verify language-diagnosability
  */
extern FAUDES_API bool IsLanguageDiagnosable(const System& rGen, const System rSpec, std::string& rReportString);

/** @name Functions (verification and computation of loop-preserving observers) */
/** @{ doxygen group */

/**
  * Verifies a loop-preserving observer. 
  * @param rGen
  *		Original generator.
  * @param rHighAlph
  *		Abstraction alphabet. 
  * @return 
  *		True if natural projection is a loop-preserving observer
  * @ingroup DiagnosisPlugIn
*/
extern FAUDES_API bool IsLoopPreservingObserver(const System& rGen, const EventSet& rHighAlph);

/** 
  * Computes a loop-preserving observer with minimal state size of the abstraction
  * @param rGen
  *	Original generator
  * @param rInitialHighAlph
  % Initial abstraction alphabet
  * @param rHighAlph
  *	Resulting abstraction alphabet
  * @ingroup DiagnosisPlugIn
  */
extern FAUDES_API void LoopPreservingObserver(const System& rGen, const EventSet& rInitialHighAlph, EventSet& rHighAlph);

/** @} doxygen group */

/** rec_ComputeLoopPreservingObserver(rGen, rInitialHighAlph, rHighAlph, rDdffVector,  numberEvents,  currentNumberEvents,  currentLocation, hosenEvents) */
extern FAUDES_API bool rec_ComputeLoopPreservingObserver(const System& rGen, const EventSet& rInitialHighAlph, EventSet& rHighAlph, 
	const std::vector<Idx>& rDdffVector, Idx numberEvents, Idx currentNumberEvents, Idx currentLocation, EventSet chosenEvents);

	
/** @name Functions (diagnoser computation) */
/** @{ doxygen group */

/**
 * Compute a standard diagnoser from an input generator and a specification.
  * @param rGen
  *		Input plant
  * @param rSpec
  * 	Specification generator.
  * @param rDiagGen
  *		Diagnoser generator for output. 
  * @ingroup DiagnosisPlugIn
*/
extern FAUDES_API void LanguageDiagnoser(const System& rGen, const System& rSpec, Diagnoser& rDiagGen);

/** @} doxygen group */

} // namespace faudes

#endif
