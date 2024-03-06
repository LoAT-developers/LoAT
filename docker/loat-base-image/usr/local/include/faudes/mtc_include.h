/** @file mtc_include.h

Includes all multitasking plug-in headers

*/

/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2008  Matthias Singer
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


#ifndef MTC_INCLUDE_H
#define MTC_INCLUDE_H

#include "mtc_attributes.h"
#include "mtc_generator.h"
#include "mtc_parallel.h"
#include "mtc_supcon.h"
#include "mtc_statemin.h"
#include "mtc_project.h"
#include "mtc_observercomputation.h"
#include "mtc_obserververification.h"
#include "mtc_redundantcolors.h"

#endif

/**

@defgroup MultitaskingPlugin Multitasking PlugIn

@ingroup AllPlugins


<p>
The multitasking plug-in allows to examine colored marking generators
(CMGs). Generators can be created in the same way as in the standard
implementation, the identifier is MtcSystem. In addition to
the standard implementation that is based on the classical theory,
colored markings can be applied to single states. The class
faudes::TmtcGenerator implements various methods to handle CMGs. Furthermore,
functions for making CMGs deterministic or strongly
coaccessible, for computing the parallel composition or an
projection, are provided.
</p>

<p>
The libFAUDES multitasking plugin allows to develop descrete event systems using the classical, 
monolithic approach. Additionally, it is suitable for their modular or hierarchical development. 
For more information to the modular proceeding see 
</p>

<p><i>
"Modular Multi-tasking Supervisory Control of Composite Discrete Event Systems", 
M.H. de Queiroz and J.E.R. Cury, IFAC World Congress, 2005.
</i></p>


<p>
Further information to the hierarchical proceeding can be found in
</p>

<p><i>
"Hierarchical and Decentralized Multitasking Control of Discrete Event Systems", K. Schmidt, M. H. Queiroz, and 
J. E. R. Cury, IEEE Conference on Decision and Control, 2007.
</i></p>


@section MtcLicense License

<p>
The implementation of the multitasking plug-in was part
of Matthias Singers' student project, supervised by Klaus Schmidt.
The code is distributed with libFAUDES and under the terms of
the LGPL.
</p>

<br>
<br>
<br>


<p>
Copyright (c) 2008,  Matthias Singer.
</p>

*/
