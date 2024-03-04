/** @file cfl_exception.h Class Exception */

/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2006  Bernd Opitz
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


#ifndef FAUDES_EXCEPTION_H
#define FAUDES_EXCEPTION_H

#include "cfl_definitions.h"
#include "cfl_helper.h"
#include <exception>
#include <string>

namespace faudes {

/**
 * Faudes exception class. libFAUDES uses the C++ exception mechanism to
 * report errors on file IO and all sorts of invalid arguments. Members are
 *
 * @param Function
 *   Function name (where did the exception happen)
 * @param Description
 *   Detailed description (human readable comment)
 * @param ErrorId
 *   Error id (numeric id, see below)

 * Define the compiletime option FAUDES_DEBUG_EXCEPTIONS  
 * to enable verbose output when exceptions are thrown, including those that are catched
 * on another level. Define the compiletime option FAUDES_CHECKED to turn
 * on argument validation on both internal and user functions.   
 *
 *
 *
 * (File-) System Errors
 *
 *    - 0: Error not defined or no error id given
 *    - 1: ios::failure thrown while opening/reading/seeking file
 *    - 2: ios::failure thrown while opening/writing file
 *    - 3: error on in systemcall (eg dot)
 *
 * Symboltable Errors
 *
 *   - 40: SymbolTable - overflow
 *   - 41: SymbolTable - attempt to insert or set name which already exists
 *   - 42: SymbolTable - attempt to insert or set index which already exists
 *   - 43: SymbolTable - attempt to insert or set invalid name 
 *
 * Runtime interface error
 *
 *   - 45: Registry - attempt to insert invalid entry
 *   - 46: Registry - attempt to access non existent entry
 *   - 47: Registry - parameter index out of range
 *   - 48: Registry - type check error
 *   - 49: Registry - function execution error
 *
 * Token IO Errors
 *
 *   - 50: TokenReader: token mismatch 
 *   - 51: TokenReader: label not found
 *   - 52: TokenReader: unbalanced SeekEnd() 
 *
 * Container Classes Errors
 *
 *   - 60: IndexSet:   index not found (eg. when accessing attribute)
 *   - 61: IndexSet:   attempt to insert invalid index 0
 *   - 62: BaseSet:    invalid iterator
 *   - 63: BaseSet:    invalid attribute access
 *   - 65: NameSet:    referring to index with no symbolic name
 *   - 66: NameSet:    referring unknown symbolic name
 *   - 67: NameSet:    symboltable mismatch
 *   - 68: TransSet:   order mismatch
 *   - 69: BaseVector: invalid index
 *
 * Core Generator Classes Errors
 *
 *   - 80: Generator: reading invalid stateset 
 *   - 85: Generator: reading invalid transition set 
 *   - 88: Generator: symbol table mismatch
 *   - 89: Generator: referring to unkown event name
 *   - 90: Generator: referring to unkown state name
 *   - 91: Generator: setting transition/initial/marked property for unkown state
 *   - 92: Generator: initial state does not exist uniquely
 *   - 95: Generator: transition referring to unknown states/event
 *   - 96: Generator: source must not match destination
 *   - 99: Generator: internal validity check failed
 *
 *  
 * Generator Operation Errors
 *
 *   - 100: Alphabet mismatch
 *   - 101: Nondeterministic argument
 *   - 110: Break on application request
 *   - 1xx  See respective functions
 *   - 2xx  See respective functions
 *
 * Exception ids between 300 and 999 are used by LRT plugins. 
 *
 *   - 55x IODevice
 *
 */
class FAUDES_API Exception : public std::exception {
	public:
		/**
		 * Constructor
		 *
		 * Writes an error message on stderr and throws an exception.
		 * 
		 * @param rFunctionName
		 *   Function name (where did the exception happen)
		 * @param rDescription
		 *   Detailed error description
		 * @param errorId
		 *   Error id
		 * @param mute
		 *   when true, mute console output
                 *   (this is meant for threaded applications where console out may be an issue)
		 */
		explicit Exception(const std::string& rFunctionName, 
				   const std::string& rDescription, unsigned int errorId, bool mute=false);

		/** Destructor */
		virtual ~Exception() throw();

		/** Returns Function */
		virtual const char* Where() const throw();

		/** Returns error description */
		virtual const char* What() const throw();

		/** Returns error description */
		virtual const char* Message() const throw();

		/** Returns error id */
		virtual unsigned int Id() const throw();

	private:
		/** Function name */
		std::string mFunctionName;

		/** Error description */
		std::string mDescription;

		/** Error message */
		std::string mMessage;

		/** Error id */
		unsigned int mErrorId;
};
		
} // namespace faudes

#endif 
