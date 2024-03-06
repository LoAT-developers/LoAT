/** @file diag_decentralizeddiagnosis.h
Functions to check a system's decentralized diagnosability.
*/

#ifndef DIAG_DECENTRALIZEDDIAGNOSIS_H
#define DIAG_DECENTRALIZEDDIAGNOSIS_H

#include <vector>
#include "corefaudes.h"
#include "op_include.h"
#include "diag_generator.h"
#include "diag_languagediagnosis.h"
#include "diag_attrdiagstate.h"
#include "diag_attrfailureevents.h"
#include "diag_attrfailuretypes.h"
#include "diag_attrlabelset.h"

#include "diag_debug.h"

namespace faudes {

//////////////////////////////////////////////////////////////////////////////////
// Verifier State for Co-diagnosability
/////////////////////////////////////////////////////////////////////////////////

struct CoVerifierState{
	std::vector<Idx> mSpec1State;
	Idx mSpec2State;
	Idx mPlantState;
	VerifierStateLabel mLabel;
	
	
	CoVerifierState(Idx number = 0, Idx state2 = 0, Idx state3 = 0, VerifierStateLabel label = NORMAL){ mSpec1State = std::vector<Idx>(number); mSpec2State = state2; mPlantState = state3; mLabel = label; }
	CoVerifierState(const CoVerifierState& rOther){ mSpec1State = rOther.mSpec1State; mSpec2State = rOther.mSpec2State; mPlantState = rOther.mPlantState; mLabel = rOther.mLabel;}

	bool operator<  (const CoVerifierState&   rOther) const{
		for(Idx i = 0; i < mSpec1State.size(); i++){
			if(mSpec1State.at(i) < rOther.mSpec1State.at(i) )
				return true;
			else if(mSpec1State.at(i) > rOther.mSpec1State.at(i) )
				return false;
		}
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


///////////////////////////////////////////////////////////////////////////////
// Functions for decentralized diagnosability
///////////////////////////////////////////////////////////////////////////////

/** @name Functions (decentralized diagnosability) */
/** @{ doxygen group */


/**
Checks co-diagnosability for a system G with respect to the specification K  and the local observation alphabets rAlphabets. 
@param rGen
  Plant automaton.
@param rSpec
  Specification automaton.
@param rAlphabets
  Local observation alphabets (for decentralized diagnosis)
@param rReportString
  User-readable information of violating condition (in case of negative test result). 
@return
  True if system G is co-diagnosable.
@ingroup DiagnosisPlugIn
*/
extern FAUDES_API bool IsCoDiagnosable(const System& rGen, const Generator& rSpec, const std::vector<const EventSet*>& rAlphabets, std::string& rReportString);

/** @} doxygen group */



/**
Computes decentralized diagnosers for multiple local sites. 
@param rGen
  Plant automaton.
@param rSpec
  Specification automaton.
@param rAlphabets
  Observable events of the local sites. 
@param rDiags
  Decentralized diagnosers
@param rReportString
  User-readable information of violating condition (in case of negative test result). 
@exception Exception
  - Number of alphabets does not equal number of local sites (id 305).
@return
  True if system G is co-diagnosable.
  The result is allocated on the heap, ownership is with the calling function.
@ingroup DiagnosisPlugIn
*/
extern FAUDES_API bool DecentralizedDiagnoser(const System& rGen, const Generator& rSpec, const std::vector<const EventSet*>& rAlphabets, std::vector<Diagnoser*>& rDiags, std::string& rReportString);

/** @name Functions (modular diagnoser computation) */
/** @{ doxygen group */

/** Function that computes decentralized diagnosers for the respective subsystems of a composed (modular) system
  * @param rGens
  *	Local subsystem automata
@param rSpec
  Specification automaton.
@param rDiags
  Decentralized diagnosers
@param rReportString
  User-readable information of violating condition (in case of negative test result). 
@exception Exception
  - Number of modular components does not equal number of decentralized diagnosers (id 306).
 @ingroup DiagnosisPlugIn
  */
extern FAUDES_API void DecentralizedModularDiagnoser(const std::vector<const System*>& rGens, const Generator& rSpec, std::vector<Diagnoser*>& rDiags, std::string& rReportString);

/** @} doxygen group */

/**
 * Function definition for run-time interface 
 */
extern FAUDES_API bool IsCoDiagnosable(const System& rGen, const Generator& rSpec, const EventSetVector& rAlphabets);

/**
 * Function definition for run-time interface 
 */
extern FAUDES_API bool DecentralizedDiagnoser(const System& rGen, const Generator& rSpec, const EventSetVector& rAlphabets, GeneratorVector& rDiags);

/**
 * Function definition for run-time interface 
 */
extern FAUDES_API void DecentralizedModularDiagnoser(const SystemVector& rGens, const Generator& rSpec, GeneratorVector& rDiags);


///////////////////////////////////////////////////////////////////////////////
// Further Auxiliary Functions  
///////////////////////////////////////////////////////////////////////////////

/**
Parallel composition of multiple generators.
@param rGens
  STL-vector of generators.
@param rResGen
  Output variable for the resulting product generator.
*/
void cParallel(const std::vector<const System*>& rGens, System& rResGen);


} // namespace faudes

#endif
