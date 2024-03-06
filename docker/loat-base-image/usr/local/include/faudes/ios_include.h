/** @file ios_include.h Include iosystem plugin headers */

/*
 **************************************************** 
 Convenience header file that includes all headers 
 relevant to the iosystem plugin.  The make system will append 
 an include directive for this file to the "allplugins.h" 
  include file.

 (C) 2010, Thomas Wittmann, Thomas Moor
 ****************************************************
 */

#ifndef FAUDES_IOS_INCLUDE_H
#define FAUDES_IOS_INCLUDE_H

// activate debug messages
#ifndef FAUDES_DEBUG_IOSYS
#define FAUDES_DEBUG_IOSYS
#endif

#include "ios_attributes.h"
#include "ios_system.h"
#include "ios_algorithms.h"


#endif


/**
 

@defgroup IoSysPlugin I/O System PlugIn


@ingroup AllPlugins

@section IosOverview Overview

<p>
This plug-in implements discrete event systems with alternating 
input and output events that satisfy Willems' conditions on
I/O behaviours. Special attention is payed to non-closed languages
and their not necessarily complete omega extensions.
</p>

<p> 
A detailed discussion on the subject is given in 
Thomas Wittmann's Diploma Thesis, including how the results 
relate to earlier work of Moor/Raisch on abstraction based 
control of hybrid systems. A technical report has been submitted 
for publication and is currently under review.
For a consise introduction, see the libFAUDES user reference, 
section <a href="../reference/iosystem_index.html">IoSystem</a>.
</p>

@section IosLicense License

<p>
This plug-in is distributed with libFAUDES and under the terms of
the LGPL. 
</p>
<br>
<br>
<br>


<p>
Copyright (C) 2010  Thomas Wittmann, Thomas Moor 
</p>




*/
