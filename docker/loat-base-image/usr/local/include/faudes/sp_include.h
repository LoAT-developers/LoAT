/** @file sp_include.h Includes all simulator plugin headers */

/*
 **************************************************** 
 Convenience header file that includes all headers
 relevant to the simulator plugin. 

 (c) Thomas Moor 2008
 ****************************************************
 */


#ifndef FAUDES_SP_INCLUDE_H
#define FAUDES_SP_INCLUDE_H

#include "sp_random.h"
#include "sp_densityfnct.h"
#include "sp_executor.h"
#include "sp_pexecutor.h"
#include "sp_lpexecutor.h"
#include "sp_plpexecutor.h"
#include "sp_dplpexecutor.h"
#include "sp_simeventset.h"
#include "sp_simconditionset.h"

#endif



/**
 
@defgroup SimulatorPlugin Simulator PlugIn


@ingroup AllPlugins


<p>
This plug-in provides classes to support the simulation of faudes generators. It is organized in
a hierarchical fashion to introduce the following features:
</p>

- the faudes::Executor is a timed generator that tracks its current state and indicates 
  which events are currently enabled and/or how much time may pass
- the faudes::ParallelExecutor is a vector of Executors with synchronized shared events
  and provides the same interface as the Executor regarding enabled events
- the faudes::LoggingExecutor is a ParallelExecutor that logs state and event 
  data for statistical analysis
- the faudes::ProposingExecutor is a LoggingExecutor that proposes which event to 
  execute based on stochastic event properties or priorities
- the faudes::DeviceExecutor is a ProposingExecutor that synchronizes with physical time
  and invokes callbacks for hardware-in-the-loop simulation (IO Device plugin required)

<p>
The tutorial simfaudes.cpp demonstrates the use of the ProposingExecutor in a simple 
interactive simulator for the synchronous product of faudes generators.
</p>


@section SpLicense License

<p>
The current implementation of the simulator plugin is a re-design based 
on Ruediger Berndt's and Christoph Doerr's student projects. 
It is distributed with libFAUDES and under the terms of the LGPL.
</p>
<br>
<br>
<br>


<p>
Copyright (c) 2008, Thomas Moor.
</p>


*/

