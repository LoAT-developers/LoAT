/** @file tp_include.h Include timed plugin headers */

/*
 **************************************************** 
 Convenience header file that includes all headers 
 relevant to the timed plugin. The make system will 
 append an include directive for this file to the 
 "allplugins.h" include file.

 (c) Thomas Moor 2007
 ****************************************************
 */

#ifndef FAUDES_TP_INCLUDE_H
#define FAUDES_TP_INCLUDE_H

#include "tp_timeinterval.h"
#include "tp_timeconstraint.h"
#include "tp_attributes.h"
#include "tp_tgenerator.h"
#include "tp_tparallel.h"



#endif



/**
 

@defgroup TimedPlugin Timed Automata PlugIn


@ingroup AllPlugins

@section Overview

<p>
This plugin extends libFAUDES to model timed automata as discussed
by R. Alur and D.L. Dill. It defines a class to represent time constraints and 
attribute classes to model guards, invariants and clocksets. Functionality
is restricted to basic maintenance inclusive file IO and parallel composition.
The motivation of this plugin is to extend the expressiveness 
of plant and controller models for simulation. It forms the basis for
both, our interpreter (aka simulator) as well an Berno Schlein's IEC
code generator.
</p>

<p>
Literature:
<br>
<i> 
R. Alur, D.L. Dill,
A Theory of Timed Automata,
Theoretical Computer Science,
vol 126, pp 183-235, 1994.
</i>
</p>

@section License

<p>
The current implementation of the timed plugin is a re-design based 
on Berno Schlein's student projects in the course of migrating from 
libFAUDES 1.0 to 2.xx. It is distributed with libFAUDES and under the terms of the LGPL.
</p>

<br>
<br>
<br>


<p>
Copyright (c) 2007, Thomas Moor.
</p>


*/


