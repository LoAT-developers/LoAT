/** @file op_include.h Includes all observer plugin headers */

/*
 **************************************************** 
 Convenience header file that includes all headers 
 relevant to the observer plugin. The make system will 
 append an include directive for this file to the 
 "allplugins.h" include file.

 (c) Klaus Schmidt 2008
 ****************************************************
 */

/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) Klaus Schmidt

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

#ifndef FAUDES_OP_INCLUDE_H
#define FAUDES_OP_INCLUDE_H


#include "op_mc.h"
#include "op_debug.h"
#include "op_observercomputation.h"
#include "op_obserververification.h"

#endif


/**
 

@defgroup ObserverPlugin Observer PlugIn


@ingroup AllPlugins

@section OpOverview Overview

<p>
This plugin offers algorithms for the verification and synthesis 
of natural projections that are observers according to 
</p>

<p><i>
K. C. Wong and W. M. Wonham, "On the Computation of Observers in Discrete Event
Systems," Discrete Event Dynamic Systems, vol. 14, no. 1, pp. 55-107, 2004.
</i></p>
 
<p>
and that fulfill the output control consistency (OCC) or local
control consistency (LCC) condition for maximally permissive
hierarchical control according to 
</p>

<p><i>
K. Schmidt and C. Breindl, "On Maximal Permissiveness of Hierarchical and Modular Supervisory
Control Approaches for Discrete Event Systems," Workshop on Discrete Event Systems, 2008. 
</i></p>

@section OpLicense License

<p>
The initial version of the observer plug-in was implemented 
by Bernd Opitz together with the initial version of libFAUDES.
A major revision and extension was part of Christian Breindl's student project,
supervised by Klaus Schmidt.
The observer plugin is distributed with libFAUDES and under the terms of
the LGPL.
</p>



<br>
<br>
<br>


<p>
Copyright (c) 2006,  Bernd Opitz
<br>
Copyright (c) 2008,  Christian Breindl, Klaus Schmidt.
</p>

*/
