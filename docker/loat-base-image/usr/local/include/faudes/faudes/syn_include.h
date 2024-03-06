/** @file syn_include.h
Includes all header files of the synthesis plug-in.
*/
	
/*
 **************************************************** 
 Convenience header file that includes all headers 
 relevant to the synthesis plug-in. When the plugin is
 enabled, libfaudes.h will include this file automatically.
 ****************************************************
*/


#ifndef SYN_INCLUDE_H
#define SYN_INCLUDE_H

#include "syn_supcon.h"
#include "syn_supnorm.h"
#include "syn_wsupcon.h"
#include "syn_tsupcon.h"
#include "syn_functions.h"
#include "syn_sscon.h"
#include "syn_supreduce.h"
#include "syn_synthequiv.h"
#include "syn_compsyn.h"

#endif


/**
@defgroup SynthesisPlugIn Synthesis Plug-In 
@ingroup AllPlugins

<p>
This plug-in implements functions that are related to controllability and normality,
as originally proposed by W.M. Wonham et al in the 1980s and selected extensions thereof. 
Examples are provided in the user reference, 
section <a href="../reference/synthesis_index.html">Synthesis</a>.
</p>

@section SynthesisLicense License
This plug-in is distributed with libFAUDES and under the terms of the LGPL.
<br>
<br>
Copyright (c) 2006, Bernd Opitz
<br>
Copyright (c) 2009, Thomas Moor, Sebastian Perk, Klaus Schmidt.
<br>
Copyright (c) 2010 - 2014, Thomas Moor.

*/
