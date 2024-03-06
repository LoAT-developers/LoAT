/** @file diag_modulardiagnosis.h
Functions to check a system's decentralized diagnosability.
*/

#ifndef DIAG_MODULARDIAGNOSIS_H
#define DIAG_MODULARDIAGNOSIS_H

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

///////////////////////////////////////////////////////////////////////////////
// Functions for decentralized diagnosability
///////////////////////////////////////////////////////////////////////////////

/** @name Functions (modular diagnosability) */
/** @{ doxygen group */

/**
Checks modular diagnosability for a system G (which consists of the subsystems rGsubs) with respect to the specification K (consisting of local specifications rKsubs) and the local abstraction alphabets rHighAlphSubs. 
@param rGsubs
  Local subsystem automata.
@param rKsubs
  Local specification automata of the subsystems.
@param rReportString
  User-readable information of violating condition (in case of negative test result). 
@exception Exception
  - Number of specifications does not equal number of subsystems (id 304).
@return
  True if system G is modular diagnosable.
@ingroup DiagnosisPlugIn
*/
extern FAUDES_API bool IsModularDiagnosable(const SystemVector& rGsubs, const GeneratorVector& rKsubs, std::string& rReportString);

/** @} doxygen group */


/**
Checks modular diagnosability for a system G (which consists of the subsystems rGsubs) with respect to the specification K (consisting of local specifications rKsubs) and the local abstraction alphabets rHighAlphSubs. 
@param rGsubs
  Local subsystem automata.
@param rKsubs
  Local specification automata of the subsystems.
@param rReportString
  User-readable information of violating condition (in case of negative test result). 
@exception Exception
  - Number of specifications does not equal number of subsystems (id 304).
@return
  True if system G is modular diagnosable.
@ingroup DiagnosisPlugIn
*/
extern FAUDES_API bool IsModularDiagnosable(const std::vector< const System* >& rGsubs, const std::vector< const Generator* >& rKsubs,  std::string& rReportString);

/**
Checks modular diagnosability for a system G (which consists of the subsystems rGsubs) with respect to the specification K (consisting of local specifications rKsubs) and the local abstraction alphabets rHighAlphSubs. 
@param rGsubs
  Local subsystem automata.
@param rKsubs
  Local specification automata of the subsystems.
@param rDiagsubs
  Modular diagnosers
@param rReportString
  User-readable information of violating condition (in case of negative test result). 
@exception Exception
  - Number of specifications does not equal number of subsystems (id 304).
@return
  True if system G is modular diagnosable.
  The result is allocated on the heap, ownership is with the calling function.
@ingroup DiagnosisPlugIn
*/
extern FAUDES_API bool ModularDiagnoser(const std::vector< const System* >& rGsubs, const std::vector<const Generator* >& rKsubs, std::vector<Diagnoser*>& rDiagsubs, std::string& rReportString);

/** @name Functions (modular diagnoser computation) */
/** @{ doxygen group */

/** Function that computes diagnosers for the respective subsystems of a composed system
  * @param rGsubs
  *	Local subsystem automata
@param rKsubs
  Local specification automata of the subsystems.
@param rDiagSubs
  Modular diagnosers
@param rReportString
  User-readable information of violating condition (in case of negative test result). 
@exception Exception
  - Number of specifications does not equal number of subsystems (id 304).
@return
  True if system G is modular diagnosable.
 @ingroup DiagnosisPlugIn
  */
extern FAUDES_API bool ModularDiagnoser(const SystemVector& rGsubs, const GeneratorVector& rKsubs, GeneratorVector& rDiagSubs,std::string& rReportString);

/** @} doxygen group */


/**
 * Function definition for run-time interface 
 */
extern FAUDES_API bool IsModularDiagnosable(const SystemVector& rGsubs, const GeneratorVector& rKsubs);


/**
 * Function definition for run-time interface 
 */
extern FAUDES_API bool ModularDiagnoser(const SystemVector& rGsubs, const GeneratorVector& rKsubs, GeneratorVector& rDiagsubs);

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
void cParallel(const std::vector<System>& rGens, System& rResGen);


} // namespace faudes

#endif
