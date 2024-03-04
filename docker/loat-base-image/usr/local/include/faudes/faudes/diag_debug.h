/** @file diag_debug.h
Includes debugging to diagnosis plug-in.
*/

#ifndef DIAG_DEBUG_H
#define DIAG_DEBUG_H


// debugging: optional console report
#ifdef FAUDES_DEBUG_DIAGNOSIS
#define FD_DD(message) FAUDES_WRITE_CONSOLE("FAUDES_DIAGNOSIS: " << message)
#else
#define FD_DD(message)
#endif

#endif

