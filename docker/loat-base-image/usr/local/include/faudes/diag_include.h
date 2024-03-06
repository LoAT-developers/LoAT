/** @file diag_include.h
Includes all header files of the diagnosis plug-in.
*/
  
/*
 **************************************************** 
 Convenience header file that includes all headers 
 relevant to the diagnosis plug-in. When the plugin is
 enabled, libfaudes.h will include this file automatically.
 ****************************************************
*/

#ifndef DIAG_INCLUDE_H
#define DIAG_INCLUDE_H

#include "diag_generator.h"
#include "diag_decentralizeddiagnosis.h"
#include "diag_modulardiagnosis.h"
#include "diag_eventdiagnosis.h"
#include "diag_languagediagnosis.h"
#include "diag_attrdiagstate.h"
#include "diag_attrfailureevents.h"
#include "diag_attrfailuretypes.h"
#include "diag_attrlabelset.h"
#include "diag_debug.h"

#endif


/**
@defgroup DiagnosisPlugIn Fault Diagnosis Plug-In 
@ingroup AllPlugins
@section DiagnosisOverview Overview

This plug-in implements failure diagnosis for discrete-event systems in libFAUDES.

Failures are assumed to be unobservable events in DES that might lead to an undesired or unpredictable behaviour of the system. In order to be able to react to occurring failures, fault detection and isolation became an active area of research since the 1990s. In [1], Sampath et al. introduced the notion of diagnosability and diagnosers which observe the on-line behaviour of the system under investigation.

Diagnoser automata are FSMs that estimate the occurrence of certain failure events by tracking the observable events triggered by the plant 
under observation.

Diagnosability is a system property that states a system to be diagnosable with respect to a failure partition or specification, if the occurrence of a failure or violation of the specification can be determined within a bounded number of transitions.

The basic structure and handling of diagnoser automata is realized in faudes::TdiagGenerator according to [1] and a diagnoser can be computed from the failure-based model of the observed plant using the function ComputeDiagnoser().

Additionally, several functions are provided to determine the diagnosability of a system with respect to a given failure %partition or specification:
- The test for standard diagnosability with respect to a failure partition is implemented in IsDiagnosable(const System&, const AttributeFailureTypeMap&, std::string&) according to [2].
- Testing I-diagnosability (which is a special case of diagnosability where failures only have to be detected after the occurrence of associated indicator events) is done by IsIdiagnosable(const System&, const AttributeFailureTypeMap&, std::string&) that is an enhancement of the algorithm presented in [2].
- Diagnosability with respect to a specification (which we also refer to as language diagnosability) is tested by IsDiagnosable(const System&, const System&, std::string&) by attributing it to the known diagnosability problem in [2].
- Decentralized diagnosability is handled by the function IsDecentralizedDiagnosable(const std::vector<System>&, const std::vector<System>&, const std::vector<EventSet>&, std::string&) that tests a modular system's diagnosability from the models of its local subsystems and specifications as presented in [3].

[1] "Diagnosability of discrete-event systems" by Sampath, M. and Sengupta, R. and Lafortune, S. and Sinnamohideen, K. and Teneketzis, D. Automatic Control, IEEE Transactions on, 40(9):1555-1575,
Sep 1995.<br>
[2] "A polynomial algorithm for testing diagnosability of discrete-event systems" by Jiang, S. and Huang, Z. Chandra, V. and Kumar, R. Automatic Control, IEEE Transactions on, 46(8):1318-1321, Aug 2001.<br>
[3] "Hierarchical Fault Diagnosis for Discrete Event Systems: Theoretical Development and Application" by Tobias Barthel, Lehrstuhl f&uuml;r Regelungstechnik, Universit&auml;t Erlangen-N&uuml;rnberg, 2009 (associated diploma thesis). <br>

@section DiagnosisLicense License
The initial implementation of this plug-in was part of Tobias Barthel's 
diploma thesis [3], supervised by Klaus Schmidt.
The code is distributed with libFAUDES and under the terms of the LGPL.
<br>
<br>
<br>
Copyright (c) 2009, Tobias Barthel, Klaus Schmidt, Thomas Moor.
<br>
Copyright (c) 2009, Klaus Schmidt, Thomas Moor.

*/
