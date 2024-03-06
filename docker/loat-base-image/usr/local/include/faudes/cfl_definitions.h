/** @file cfl_definitions.h 

Compiletime options. This file configures the runtime bahaviour of
libFAUDES, in particular informative output on stderr and stdout; see
also the Makefile. 

*/


/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2006  Bernd Opitz
   Copyright (C) 2008-2021  Thomas Moor
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



#ifndef FAUDES_DEFINITIONS_H
#define FAUDES_DEFINITIONS_H

#include <iostream>
#include <sstream>
#include <inttypes.h>
#include "configuration.h"

namespace faudes {

/** Type definition for index type (allways 32bit) */
typedef uint32_t Idx;
#define FAUDES_IDX_MAX 0xFFFFFFFFU

/** Type definition for integer type (let target system decide, minimum 32bit) */
typedef long int Int;
#define FAUDES_INT_MIN (std::numeric_limits<int>::min())
#define FAUDES_INT_MAX (std::numeric_limits<Type>::max())

/** Type definition for real type */
typedef double Float;

/** Length of strings for text fields in token output*/
#define FD_NAMELEN 13

/** Max length of automatic container names (set to -1 for unlimited) */
#define FD_MAXCONTAINERNAME 70

/** Max size of transrel for state name output */
#define FD_SMALLTRANSREL 100

/** Min number of states to use consecutive section in file output */
#define FD_CONSECUTIVE 6

/** Max number of automatic signatures */
#define FD_RTIMAXSIG 5

#ifndef FAUDES_VERSION
/** Fallback version string (should define version in Makefile) */
#define FAUDES_VERSION "undefined version"
#endif

/** Debug: console output, no redirection */
#define FAUDES_WRITE_DIRECT(message) \
  { if(!faudes::ConsoleOut::G()->Mute()) { std::cout << message << std::endl;} }

/** Debug: output macro for optional redirection of all console output */
#define FAUDES_WRITE_CONSOLE(message) \
  { if(!faudes::ConsoleOut::G()->Mute()) {				\
      std::ostringstream cfl_line; cfl_line << message << std::endl; faudes::ConsoleOut::G()->Write(cfl_line.str());} }

/** Debug: always report warnings */
#define FD_WARN(message) FAUDES_WRITE_CONSOLE("FAUDES_WARNING:   " << message)

/** Debug: report more errors with file/line info */
#ifdef FAUDES_DEBUG_CODE
#define FD_ERR(message) \
 FAUDES_WRITE_CONSOLE("FAUDES_CODE: "  << message << " in " << __FILE__ << ":" << __LINE__ )
#else
#define FD_ERR(message)
#endif

/** Application callback: optional write progress report to console or application */
#ifdef FAUDES_WRITE_PROGRESS 
#define FD_WP(message) {FAUDES_WRITE_CONSOLE("FAUDES_PROGRESS:  " << message); LoopCallback();}
#else
#define FD_WP(message)
#endif

/** Application callback: optional write progress report to console or application, incl count  */
#ifdef FAUDES_WRITE_PROGRESS 
#define FD_WPC(cntnow, cntdone, message)					\
  { std::ostringstream cfl_line; cfl_line << "FAUDES_PROGRESS:  " << message << std::endl; \
    faudes::ConsoleOut::G()->Write(cfl_line.str(),(cntnow),(cntdone)); LoopCallback(); }
#else
#define FD_WPC(cntnow, contdone, message)
#endif

/** Alternative progessreport for development */
#define FD_WPD(cntnow, cntdone, message)  { \
  static faudes_systime_t start; \
  static faudes_systime_t now; \
  static faudes_mstime_t lap;  \
  static Int prog;  \
  static bool init(false);  \
  if(!init) { faudes_gettimeofday(&start); prog=cntnow;}  \
  faudes_gettimeofday(&now);  \
  faudes_diffsystime(now,start,&lap); \
  if(!init) lap=10000;                  \
  if(lap>=10000) {			\
    Int cps = (cntnow-prog)/(lap/1000); \
    std::ostringstream cfl_line; \
    cfl_line << "FAUDES_PROGRESS:  " << message;			\
    if(cntnow>0) cfl_line << " (#/sec: " << cps << ")";\
    cfl_line << std::endl; \
    faudes::ConsoleOut::G()->Write(cfl_line.str(),(cntnow),(cntdone)); LoopCallback(); \
    faudes_gettimeofday(&start); \
    prog=cntnow; \
  } \
  init=true; } 


/** Debug: optional report on user functions */
#ifdef FAUDES_DEBUG_FUNCTION
#define FD_DF(message)  FAUDES_WRITE_CONSOLE("FAUDES_FUNCTION:  " << message)
#else
#define FD_DF(message)
#endif


/** Debug: optional report on generator operations */
#ifdef FAUDES_DEBUG_GENERATOR
#define FD_DG(message) FAUDES_WRITE_CONSOLE("FAUDES_GENERATOR: " << message)
#else
#define FD_DG(message)
#endif

/** Debug: optional report on container operations */
#ifdef FAUDES_DEBUG_CONTAINER
#define FD_DC(message) FAUDES_WRITE_CONSOLE("FAUDES_CONTAINER: " << message)
#else
#define FD_DC(message)
#endif

/** Debug: optional on function and type definition */
#ifdef FAUDES_DEBUG_RUNTIMEINTERFACE
#define FD_DRTI(message) FAUDES_WRITE_CONSOLE("FAUDES_RTI:     " << message)
#else
#define FD_DRTI(message)
#endif

/** Debug: optional report registry operations */
#ifdef FAUDES_DEBUG_REGISTRY
#define FD_DREG(message) FAUDES_WRITE_CONSOLE("FAUDES_REG:     " << message)
#else
#define FD_DREG(message)
#endif

/** Debug: optional low-level report on iterations and  token IO */
#ifdef FAUDES_DEBUG_VERBOSE
#define FD_DV(message) FAUDES_WRITE_CONSOLE("FAUDES_VERBOSE:   " <<  message)
#else
#define FD_DV(message)
#endif

/** Debug: count objects, report on exit */
#ifdef FAUDES_DEBUG_CODE
#define FAUDES_OBJCOUNT_INC(type) ObjectCount::Inc(type)
#define FAUDES_OBJCOUNT_DEC(type) ObjectCount::Dec(type)
#else
#define FAUDES_OBJCOUNT_INC(type)
#define FAUDES_OBJCOUNT_DEC(type)
#endif

/** Debug: timing */
#define FAUDES_TIMER_START(msg) {   \
 FD_WARN("timer start " << msg );  \
 faudes_gettimeofday(& gPerfTimer1 ); } 
#define FAUDES_TIMER_LAP(msg) {  \
 faudes_systime_t now; \
 faudes_mstime_t lap;  \
 faudes_gettimeofday(&now);  \
 faudes_diffsystime(now,gPerfTimer1,&lap); \
 FD_WARN("timer lap " << msg << " " << lap << "ms");} 


/** Tutorial/debugging mark */
#define FD_DLINE(message) FD_WARN( \
  std::endl << "################################################ " << \
  std::endl << message << " at file " << __FILE__ << ", line " << __LINE__ << endl << \
  std::endl << "################################################ " << std::endl );


/** Doxygen: exclude this from doxygen */
#ifndef FAUDES_DOXYGEN
#define FAUDES_NODOC(a) a
#else
#define FAUDES_NODOC(a)
#endif

/* Doxygen: include group definitions */
#ifdef FAUDES_DOXYGEN
#include "doxygen_groups.h"
#endif

} // namespace faudes

#endif 

