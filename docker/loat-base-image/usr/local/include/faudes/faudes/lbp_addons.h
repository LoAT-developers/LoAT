/** @file lbp_addons.cpp add-ons for Lua integration */

/* 
FAU Discrete Event Systems Library (libfaudes)

Copyright (C) 2023 Thomas Moor

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
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA 

*/

#ifndef FAUDES_LBP_ADDONS_H
#define FAUDES_LBP_ADDONS_H

// incl faude base for FAUDES_API
#include "corefaudes.h"

// forward
struct lua_State;

namespace faudes{

// overall loader to initialize kernel
extern FAUDES_API void faudes_initialize(lua_State* pL);

// track last line in interpreter 
extern FAUDES_API std::string faudes_lastline;

// register faudes console variant for print
extern FAUDES_API void faudes_print_register(lua_State* L);

// register faudes LoopCallback() as line hook
extern FAUDES_API void faudes_hook_register(lua_State* L);

// load extension
extern int FAUDES_API faudes_loadext(lua_State* pL, const char* filename);
extern int FAUDES_API faudes_loaddefext(lua_State* pL, const char* arg0);

// interface to completer
extern FAUDES_API char **faudes_complete(lua_State* pL, const char *text, int start, int end);

}// namespace
#endif


