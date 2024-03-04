/** @file lbp_include.h Includes all luabindings plug-in headers */

/*
 **************************************************** 
 Convenience header file that includes all headers
 relevant to the luabindings plug-in. 

 (c) Thomas Moor 2008
 ****************************************************
 */


#ifndef FAUDES_LBP_INCLUDE_H
#define FAUDES_LBP_INCLUDE_H

#endif



/**
 
@defgroup LuabindingsPlugin Lua Bindings PlugIn


@ingroup AllPlugins

<p>
This plug-in generates libFAUDES bindings for the scripting language Lua; 
see http://www.lua.org. 
With this plug-in, a Lua interpreter may serve as 
an interactive user interface to libFAUDES data types and functions. 
The tutorial section includes a number of example scripts to demonstrate
libFAUDES access from Lua. 
</p>

<p>
The luabindings plug-in also includes the application luafaudes, a variation of 
the std Lua interpreter that runs FAUDES extended lua scripts. If your target platform 
is Linux, you really want to re-compile with LBP_LUAGOAL=linux in the Makefile.plug-in 
in order to enable advanced readline support (tab key completion, command history etc).
</p>

@section SecLuabindingsIntro1 Example Script

The following script runs a simple synthesis procedure to
synthesise a supervisor - sic - for our two simple machines.
For examples, see "./plugins/luabindings/tutorial/_*_.lua" and the 
introduction given on http://www.rt.eei.uni-erlangen.de/FGdes/faudes/luafaudes 

@code

-- read original machine
machine  = faudes.Generator("data/verysimplemachine.gen")

-- prepare two copies
machine1 = faudes.Generator();
machine2 = faudes.Generator();
faudes.Version(machine,"1",machine1);
faudes.Version(machine,"2",machine2);

-- compose overall plant
plant = faudes.Generator();
faudes.Parallel(machine1,machine2,plant);

-- load specification
spec = faudes.Generator("data/buffer12.gen");

-- run synthesis
super = faudes.Generator();
faudes.SupConNB(plant,spec,super);


-- report result
plant:Write();
spec:Write();
super:Write();
@endcode

@section SecLuabindingsIntro2 Extending Luabindings


When you use the libFAUDES plug-in mechanism to implement your algorithms,
you may find it useful to include your extensions in the Lua based 
interface. The wrapper code is automatically generated from so called interface
definition files using the tool SWIG; see http://www.swig.org. 

For data types with a tailored user interface, you will need to provide
interface definitions directly to define the way a user may interact with
variables of the respective type. For functions that are registered with
the faudes run-time interface, the interface definitions will be generated
by the build system. In both cases, the additional
code required to integrate your plug-in into luafaudes is minimal. 

The below is from the example plug-in and directly defines the interface for the
AlternativeAccessible function. For more detailed information,
see the <a href="../faudes_algorithm_example.html">Plug-In Example</a>


@code
// Set SWIG module name
// Note: must match libFAUDES plug-in name
%module example
#ifndef SwigModule
#define SwigModule "SwigExample"
#endif

// Load std faudes interface
%include "faudesmodule.i"

// Include rti generated functioninterface 
#if SwigModule=="SwigExample"
%include "../../../include/rtiautoload.i"
#endif

// Define interface to additional functions
void OtherFunction(Generator& rGen, rEventSet& rAlph);
bool IsGoodTest(Generator& rGen, rEventSet& rAlph);
...

@endcode



@section SecLuabindingsIntro3 Build System

Since not every libFAUDES based application requires luabindings,
the luabindings plug-in does not add code to libFAUDES itself but compiles
to a seperate archive named libluafaudes (.a,.so,.dll) 

The build system organises the compilation of the luabindings plug-in in two stages:
- At stage one, SWIG is used to generate the wrapper code. Since the plug-in ships
  with appropriate wrapper code, this stage only needs to be processed if you want to 
  generate additional bindings for you plug-in. You will need SWIG version 1.3.36 installed on your system; see http://www.swig.org. 
  Use <tt>make luabindings-clean</tt> and <tt>make luabindings-prepare</tt> to re-build the wrapper code. 
  This stage is also processed by the configuration procedure, e.g. <tt>make dist-clean</tt> and <tt>make configure</tt>.
- At stage two, the wrapper code and Lua is compiled to the archive
  <tt>libluafaudes.a</tt>. The plug-in includes the lua sources, no additional software requirements
  are imposed. This stage is processed by the std build procedure, eg <tt>make clean</tt> and <tt>make</tt>.


@section SecLuabindingsIntro4 Advanced Topic: RTI extensions by Lua functions

The Lua environment is designed to support both calling C code from a Lua script
as well as calling Lua code from a C application. The latter direction is used
by faudes::LuaFunction and faudes::LuaFunctionDefinition objects to extend libFAUDES 
by Lua scripts that register with the libFAUDES run-time interface. Thus, libFAUDES applications 
that interface to libFAUDES via the RTI can be transparently extended by Lua scripts. 


@section License

The luabindings plug-in is distributed with libFAUDES. 
All code except Lua sources are provided under terms of the LGPL. 


Copyright (c) 2008, 2023 Thomas Moor.


Lua sources are included for convenience and come under terms of the following MIT License:

License for Lua 5.0 and later versions
Copyright (c) 1994-2008 Lua.org, PUC-Rio.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions ofthe Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. 


The luabindings plug-in also provides a variation of
the advanced readline support, which is Copyright (C) 2004-2006 Mike Pall,
with the same license as Lua. See also the file lbp_completion.cpp



*/


#ifndef FAUDES_LIBLUAFAUDES_H
#define FAUDES_LIBLUAFAUDES_H


// lua essentials
#define lua_c


// lua essentials
extern "C" {
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"
}


// std streams 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// c libs since we dont use lua.h
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// luafaudes: include faudes plus lua addons
#include "corefaudes.h"
#include "lbp_addons.h"
#include "lbp_function.h"

// include declarations for SWIG generated module loaders 
#include "lbp_load.h"


// SWIG interface std: programatic exception, see coreaddons.i
namespace faudes {
extern FAUDES_API void faudes_throw_exception(const std::string& msg);
extern FAUDES_API void faudes_dict_insert_topic(const std::string& topic, const std::string& text);
extern FAUDES_API void faudes_dict_insert_entry(const std::string& topic, const std::string& key, const std::string& entry);
extern FAUDES_API void faudes_mute(bool on);
extern FAUDES_API void faudes_console(const std::string& message);
extern FAUDES_API void faudes_debug(const std::string& message);
} 

// luafaudes debugging facilities
#ifdef FAUDES_DEBUG_LUABINDINGS
#define FD_DLB(message) FAUDES_WRITE_CONSOLE("FAUDES_LUA_ERROR: " << message);
#else
#define FD_DLB(message)
#endif



#endif
