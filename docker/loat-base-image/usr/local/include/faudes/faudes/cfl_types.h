/** @file cfl_types.h Runtime interface, faudes types */

/* FAU Discrete Event Systems Library (libfaudes)

Copyright (C) 2009 Ruediger Berndt
Copyright (C) 2010 Thomas Moor

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


#ifndef FAUDES_RTITYPES_H
#define FAUDES_RTITYPES_H

#include <list>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <string>
#include <iostream>
#include <typeinfo>
#include <algorithm>

#include "cfl_definitions.h"
#include "cfl_token.h"
#include "cfl_tokenreader.h"
#include "cfl_tokenwriter.h"
#include "cfl_exception.h"



namespace faudes {


/************************************************
 ************************************************
 ************************************************/


/** @defgroup RunTimeInterface  Run-Time Interface

The libFAUDES run-time interface (RTI) facilitates the development 
of applications that are transparent to libFAUDES extensions, e.g.,
the libFAUDES version of the Lua interpreter luafaudes and the 
graphical user interface  DESTool.

The run-time interface  provides a TypeRegistry for the application 
to instantiate objects by specifying their type as a std::string. 
The TypeRegistry is accompanied by the FunctionRegistry for 
the application to execute functions by their name. Thus, a libFAUDES
application can query both registries and provide the 
supported types and functions to the user. 
The <a href="../reference/index.html">libFAUDES user-reference</a> 
is set up by the build system to represent the contents of both
registries.

The run-time interface is implemented
by the following components:
- base class faudes::Type for RTI enabled classes (faudes-types)
- documentation class faudes::TypeDefinition to accompany faudes-types;
- container class faudes::TypeRegistry to hold faudes::TypeDefintiion objects;
- base class faudes::Function for RTI enabled function wrappers (faudes-functions);
- documentation class faudes::FunctionDefinition to accompany faudes-functions;
- container class faudes::FunctionRegistry to hold FunctionDefintiion objects.

@section RunTimeInterfaceSec2 Faudes-Types

Classes that participate in the run-time interface are referred to
as faudes-types, instances are so called faudes-objects. Any faudes-type must
be derived from the base class faudes::Type. A faudes-type inherits
the convenience interface for token IO from Type, and, most relevent for the run-time 
interface, the factory function New(): each faudes-types must reimplement New() 
to allocate a new object of their respective type on heap. For a fully functional
faudes-type, also an appropriate assignment operator and a copy constructor
are required.


@section RunTimeInterfaceSec3 Faudes-Type Definitions

A faudes-type is accompanied by an instance of faudes::TypeDefinition. It holds
a name (std::string) to identify the faudes-type,
documentation (short text and html reference), 
and one faudes-object of the respective faudes-type.
The latter is referred to as the prototype object and its New() method is used to construct 
new faudes-objects of the respective faudes-type. Thus, given a TypeDefinition,
one can instantiate a corresponding faudes-object. To setup a
TypeDefinition, you are meant to provide the faudes-type name, the protototype
and a file from which to read the documentation.


@section RunTimeInterfaceSec4 Faudes-Functions and Faudes-Function Definitions

Functions that participate in the run-time interface are organized similar
to faudes-types. There is a base class faudes::Function from which to derive 
particular faudes-functions. The base class provides an interface to set
function parameter values and to actually  execute the function on the parameters. 
To derive a class from Function, you must reimplement the methods New(), DoTypeCheck(), 
and DoExecute(). The DoTypeCheck method is supposed to use a dynamic cast
to initialize typed references to the function parameters. The DoExecute method
then executes the function, typically by invoking a function via its
C++ API. Each Function class is accompanied by a faudes::FunctionDefinition instance
which holds a prototype, basic documentation and a list of valid signatures. Each signature
represents a valid parameter type configurations in terms of faudes-types. 

@section RunTimeInterfaceSec5 Type- and Function-Registry 

The faudes::TypeRegistry and the faudes::FunctionRegistry are containers for TypeDefinition
and FunctionDefinition instances, respectively. Applications access the registries via
faudes-type names and faudes-function names, see e.g. the global functions NewObject() and
NewFunction(). There is also in interface to iterate through the regsitries and
to test for the existence of an entry. However, while both registries inherit the std token-io
interface, neither registry can be fully configured by reading from file. This is because
each entry requires not only data (documentation, signature, etc) but also a prototype
instance. The std C++ run-time type information (RTTI) does not provide a mechanism
to instantiate an object of a class that is specified at runtime. Thus, each protototype
must be defined at compiletime. The global function LoadRegistry() is automatically
set-up by the build system to gather all relevant prototypes, insert them in the 
registries and to subsequently read further documentation from a configuration 
file.

@section RunTimeInterfaceSec6 RTI and the Build System

At stage <tt>make configure</tt>, the build system sets up the function LoadRegistry()
by  
- setting the macro FAUDES_PLUGINS_RTILOAD to a list of function calls in order to invoke
  one load function per plugin;
- running the tool <tt>rti2code</tt> to generate c code to register faudes-types and-functions 
  found in the configuration file ("libfaudes.rti").

Code generation should work for all types and functions with documentation entry "CType()" specified. 
Since there is only one CType() entry, all signatures of a function must be implemented by a single
c-function. The generated code is placed at "./include/rtiautoload.*". The build system also provides 
support to merge the configuration "libfaudes.rti" file from various sources, incl. plugins.

To have your C++ class participate in the libFAUDES run-time interface:

-# derive your class from faudes::Type;
-# make sure your class has a public default constructor and a public copy constructor;
-# use the provided macros to reimplement the virtual functions FType(), New(), Copy(), Cast(), 
   Assign(), Equal(), and the acording operators =, == and !=;
-# reimplement the virtual functions DoAssign(), DoEqual(), DoRead(), DoWrite() and Clear();
-# optionally, reimplement the alternative output formats DoDWrite(), DoSWrite(), DoXWrite()
-# provide an .rti file for the formal TypeDefinition; 
-# supplement your .rti file by an html formated documentation text;  
 
You will need to inspect and edit the main Makefile or your plugin's Makefile
to advertise your additional sources. A <tt>make configure</tt> will then
assemble all the bits and pieces.

To have your C++ function participate in the libFAUDES run-time interface:

-# make sure all your parameters are faudes-types (exceptions being
   the elementary types bool, string and integer, which are converted automatically);
-# provide an .rti file for the formal FunctionDefinition, advertise this file;
   either in the main Makefile or in the Makefile of your plugin;
-# supplement yout .rti file by an html formated documentation text;  


*/

// forward
class TypeDefinition;

/**
 * Base class of all libFAUDES objects that participate in
 * the run-time interface. Eg, generator, alphabet, attributes etc.
 * The class is designed to impose as little overhead as possible, and
 * hence, does not hold any data. It does, however, provide a
 * uniform interface for assignment, factory functions, and token IO.
 *
 * We think of a faudes-typed object to be configured by defining
 * data and, in due course, manipulated via its public interface 
 * by faudes-functions. Any faudes-type must provide a Clear() method that
 * resets the object configuration to a unique default value.
 * It is the configuration data that can be read from and written to token
 * streams, and it is the configuration data that is used for assigments.
 * Any additional data a faudes-typed object may host, is ignored by the
 * interface inherited from the the base faudes::Type. Examples for such
 * additional data is the unique id of a Generator, and the deferred copy
 * pointers in faudes sets derived from faudes::TBaseSet.
 *
 * The faudes::Type assignment semantics are not meant to create exact copies
 * of a given source object. Thogether with the uniquely defined default value,
 * we can have assignments by both up- and downcasts. A faudes::Generator can be
 * assigned from the derived faudes::System (a Generator with controllability 
 * attributes) by dropping the extra features. Vice versa, when a System is assigned
 * from a plain Generator, any extra features take their respective default values.
 * This relaxed interpretation of assignments is implemented by the method
 * Assign().  The token format for file IO is organised in a similar fashion: any generator 
 * derivate can be configured from the token stream produced by any other generator class. 
 * In contrast, faudes-typed objects also implement an assignment operator
 * that uses the standard C++ conventions.
 *
 * The following methods are used to implement the faudes::Type interface:
 * 
 * - DoRead() to read the defining data from a token stream
 * - DoWrite() to write the defining data to a token stream
 * - DoXWrite() to write the defining data to a token stream in an alternative XML format
 * - DoSWrite() and DoDWrite for alternative output formats (statistical summary and debugging)
 *
 * - Name() to get/set the name of an optional (and purely cosmetic) object name
 * - Clear() to reset all configuration data,
 * - New() to construct an object of identical type on heap (factory method),
 * - Copy() to construct an object of identical type and configuration on heap (factory method),
 * - Cast() to dynamically cast another object to this type (type check method)
 * - Assign() to do an assignment from any castable Type derivate
 * - DoAssign(), or the operator "=", to assign from an object with identical type.
 * - Equal() to test relaxed equality with any castable Type derivate
 * - DoEqual(), or the operators "==" and "!=", to test exact equality of configuration data
 * 
 * In most cases, only DoRead(), DoWrite(), DoAssign(), DoEqual() and Clear() need to be implemented
 * manualy. The other methods can be declared and implemented by macros
 * FAUDES_TYPE_DELARATION and FAUDES_TYPE_IMPLEMENTATION, respectively. The various
 * attribute classes illustrate their ussage; see e.g. AttributeFlags.
 *
 *
 * Note on token IO: In libFAUDES 2.16e, implementation of a new file format is prepared 
 * by the virtual function interface DoXWrite(). The intention is to better support advanced 
 * XML editors, in particular for configuration files. When implementing DoXWrite() for a 
 * derived class, make sure that DoRead() will gracefully accept tokens written by both DoWrite() 
 * and DoXWrite(), as a basis for a fileformat conversion tool. Future versions of libFAUDES will drop 
 * compatibility with the old token format, except for model data (generators, alphabets). 
 *
 * @ingroup RunTimeInterface
 */
   
class FAUDES_API Type {

 public:

  /** Constructor */
  Type(void);

  /** Copy constructor */
  Type(const Type& rType);

  /** Destructor */
  virtual ~Type(void);

  /**
   * Construct on heap. 
   * Technically not a constructor, this function creates an object with the
   * same type Type. New() is defined as a virtual function and derived
   * classes are meant to re-implement with the appropiate constructor.
   * This can be done via the provided macros FAUDES_TYPE_DECLARATION and
   * FAUDES_TYPE_IMPLEMENTATION.
   * As with new, it is the callers reponsabilty to delete the object when no longer needed.
   *
   * @return 
   *   Pointer to new Type object
   */
  virtual Type* New(void) const;

  /**
   * Construct on heap. 
   * Technically not a constructor, this function creates an object with the
   * same type Type and the same configuration. Copy() is defined as a virtual function and derived
   * classes are meant to re-implement with the appropiate copy constructor.
   * This can be done via the provided macros FAUDES_TYPE_DECLARATION and
   * FAUDES_TYPE_IMPLEMENTATION.
   * As with new, it is the callers reponsabilty to delete the object when no longer needed.
   *
   * @return 
   *   Pointer to new Type object
   */
  virtual Type* Copy(void) const;

  /**
   * Cast other object to this type.
   * Enables the run-time interface to test whether pObject is derived
   * from this object. This feature is used e.g. in the faudes container
   * classes to test attributes. Derived classes must reimplement this
   * function using the appropriate dynamic cast.
   *
   * Re-implementation can be done via the convenience macros
   * FAUDES_TYPE_DECLARATION and FAUDES_TYPE_IMPLEMENTATION.
   *
   * @return 
   *   Typed pointer object
   */
  virtual const Type* Cast(const Type* pOther) const;

  /**
   * Clear configuration data.  Derived classes should re-implement this
   * method to ensure some consistent configuration data.
   */
  virtual void Clear(void);

  /**
   * Assign configuration data from other object. 
   * Derived classes should reimplement this method to first try to cast
   * the source to the respective class. If successful, the protected 
   * function DoAssign is invoked to perform the actual assignment. If the cast fails,
   * the Assign method of the parent class is called. Thus, faudes
   * objects are up- and downcatsed for assignment, maintaining as much of
   * the source data as digestable by the destination object. On the downside,
   * there is no sensible typechecking at compile-time.
   *
   * Re-implementation can be done via the convenience macros
   * FAUDES_TYPE_DECLARATION and FAUDES_TYPE_IMPLEMENTATION.
   * 
   * @param rSrc 
   *    Source to copy from
   * @return Reference to this object.
   */
  virtual Type& Assign(const Type& rSrc);


  /**
   * Assign configurationdata from other object. 
   * Derived classes should implement the operator form for the assignment
   * for each source type which allows for a non-trivial assignment. This includes
   * the particular case were the source and destination types match exactly. In the
   * latter case the DoAssign method should be invoked. In contrast to
   * the Assign function, the operator form must not be reimplemented for
   * missmatched source types: the operator form only accepts sensible source types.
   * This allows for compiletime typeckecking. However, the downside is that
   * when the type is not known at compiletime, configuration is not properly
   * assigned.
   *
   * Re-implementation can be done via the convenience macros
   * FAUDES_TYPE_DECLARATION and FAUDES_TYPE_IMPLEMENTATION.
   * 
   * @param rSrc 
   *    Source to copy from
   * @return Reference to this object.
   */
  virtual Type& operator=(const Type& rSrc);

  /**
   * Test equality of configuration data.
   * Derived classes should reimplement this method to return true
   * if both actual types and configuration data match.
   * The object name or id  (if any) is not considered in the test.
   *
   * This method calls the virtual method DoEqual(). Re-implementation can 
   * be done via the convenience macros
   * FAUDES_TYPE_DECLARATION and FAUDES_TYPE_IMPLEMENTATION.
   * 
   * @param rOther 
   *    Other object to compare with.
   * @return 
   *   True on match.
   */
  virtual bool Equal(const Type& rOther) const;

  /**
   * Test equality of configuration data.
   * The operator form of the equality test is only defined for matching
   * types, no cast will be performed. Thus, the test will be optimistic
   * if the type is not known at compiletime.
   * The object name or id  is not considered in the test.
   *
   * This methoc calls the virtual method DoEqual(). Re-implementation can 
   * be done via the convenience macros
   * FAUDES_TYPE_DECLARATION and FAUDES_TYPE_IMPLEMENTATION.
   * 
   * @param rOther 
   *    Other object to compare with.
   * @return 
   *   True on match.
   */
  virtual bool operator==(const Type& rOther) const;


  /**
   * Test equality of configuration data.
   * See operator==(const Type&).
   *
   * This method calls the virtual method DoEqual(). Re-implementation can 
   * be done via the convenience macros
   * FAUDES_TYPE_DECLARATION and FAUDES_TYPE_IMPLEMENTATION.
   * 
   * @param rOther 
   *    Other objevt to compare with.
   * @return 
   *   True on mismatch.
   */
  virtual bool operator!=(const Type& rOther) const;


  /** 
   * Set the objects's name.
   *
   * The base class Type does not implement an object name,
   * derivatives usually do so, except for attributes. 
   *
   * @param rName
   *   Name
   */
  virtual void Name(const std::string& rName);

  /** 
   * Get objects's name.
   *
   * The base class Type does not implement an object name,
   * derivatives usually do so, except for attributes. 
   * @return 
   *   Name of generator
   */
  virtual const std::string& Name(void) const;

  /** 
   * Get objects's type name. 
   *
   * Retrieve the faudes-type name from the type registry.
   * This method silently returns the empty string if the type is 
   * not (yet) registered.
   *
   * @return 
   *   Faudes-type name or empty string.
   */
  virtual const std::string& TypeName(void) const;

  /**
   * Write configuration data to console.
   * Note: this write function uses the virtual function DoWrite(), to be 
   * reimplemented by derived classes.
   *
   * @param pContext
   *   Write context to provide contextual information
   *
   */
  void Write(const Type* pContext=0) const;

  /**
   * Write configuration data to a file. 
   * Note: this write function uses the virtual function DoWrite(), to be 
   * reimplemented by derived classes.
   *
   * @param pFileName
   *   Name of file
   * @param rLabel
   *   Label of section to write
   * @param pContext
   *   Write context to provide contextual information
   * @param openmode
   *   ios::openmode 
   *
   * @exception Exception
   *   - IO errors (id 2)
   */
  void Write(const std::string& pFileName, const std::string& rLabel="",
	     const Type* pContext=0, std::ios::openmode openmode = std::ios::out|std::ios::trunc) const;

  /**
   * Write configuration data to a file. 
   * Note: this write function uses the virtual function DoWrite(), to be 
   * reimplemented by derived classes.
   *
   * @param pFileName
   *   Name of file
   * @param openmode
   *   ios::openmode 
   *
   * @exception Exception
   *   - IO errors (id 2)
   */
  void Write(const std::string& pFileName, std::ios::openmode openmode) const;

  /**
   * Write configuration data to TokenWriter.
   * Note: this write function uses the virtual function DoWrite(), to be 
   * reimplemented by derived classes.
   *
   * @param rTw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of section to write
   * @param pContext
   *   Write context to provide contextual information
   *
   * @exception Exception 
   *   - IO errors (id 2)
   */
  void Write(TokenWriter& rTw, const std::string& rLabel="",const Type* pContext=0) const;

  /**
   * Write configuration data to an XML file. 
   * Note: this method uses the faudes type to set a DOCTYPE markup; for derived classes
   * which do not report their faudes type, you should reimplement this
   * function. Actual token io is done via DoXWrite().
   *
   * @param pFileName
   *   Name of file
   * @param rLabel
   *   Label of section to write
   * @param pContext
   *   Write context to provide contextual information
   *
   * @exception Exception
   *   - IO errors (id 2)
   */
  virtual void XWrite(const std::string& pFileName, const std::string& rLabel="",
	     const Type* pContext=0) const;

  /**
   * Write configuration data in XML format to concole
   * Note: this write function uses the virtual function DoXWrite(), to be 
   * reimplemented by derived classes. No DOCTYPE markup will be written.
   *
   * @param pContext
   *   Write context to provide contextual information
   *
   */
  void XWrite(const Type* pContext=0) const;

  /**
   * Write configuration data in XML format to TokenWriter.
   * Note: this write function uses the virtual function DoXWrite(), to be 
   * reimplemented by derived classes.
   *
   * @param rTw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of section to write
   * @param pContext
   *   Write context to provide contextual information
   *
   * @exception Exception 
   *   - IO errors (id 2)
   */
  void XWrite(TokenWriter& rTw, const std::string& rLabel="",const Type* pContext=0) const;

  /**
   * Write configuration data to a string.
   * Note: this write function uses the virtual function DoWrite(), to be 
   * reimplemented by derived classes.
   *
   * @param rLabel
   *   Label of section to write
   * @param pContext
   *   Write context to provide contextual information
   * @return
   *   output string
   * @exception Exception
   *   - IO errors (id 2)
   */
  std::string ToString(const std::string& rLabel="", const Type* pContext=0) const;

  /**
   * Write configuration data to a formated string.
   * In contrast to ToString, ToText does not suppress comments and
   * End-Of-Line marks. 
   * Note: this write function uses the virtual function DoWrite(), to be 
   * reimplemented by derived classes.
   *
   * @param rLabel
   *   Label of section to write
   * @param pContext
   *   Write context to provide contextual information
   * @return
   *   output string
   * @exception Exception
   *   - IO errors (id 2)
   */
  std::string ToText(const std::string& rLabel="", const Type* pContext=0) const;

  /**
   * Write configuration data to console, debugging format.
   * Note: this write function uses the virtual function DoDWrite(), to be 
   * reimplemented by derived classes.
   *
   * @param pContext
   *   Write context to provide contextual information
   *
   */
  void DWrite(const Type* pContext=0) const;

  /**
   * Write configuration data to a file, debugging format. 
   * Note: this write function uses the virtual function DoDWrite(), to be 
   * reimplemented by derived classes.
   *
   * @param pFileName
   *   Name of file
   * @param rLabel
   *   Label of section to write
   * @param pContext
   *   Write context to provide contextual information
   * @param openmode
   *   ios::openmode 
   *
   * @exception Exception
   *   - IO errors (id 2)
   */
  void DWrite(const std::string& pFileName, const std::string& rLabel="",
	      const Type* pContext=0, std::ios::openmode openmode = std::ios::out|std::ios::trunc) const;

  /**
   * Write configuration data in debug format to TokenWriter.
   * Note: this write function uses the virtual function DoWrite(), to be 
   * reimplemented by derived classes.
   *
   * @param rTw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of section to write
   * @param pContext
   *   Write context to provide contextual information
   *
   * @exception Exception 
   *   - IO errors (id 2)
   */
  void DWrite(TokenWriter& rTw, const std::string& rLabel="",const Type* pContext=0) const;

  /**
   * Write statistics comment to TokenWriter.
   * Note: this write function use the virtual function DoSWrite(), to be 
   * reimplemented by derived classes.
   *
   * @param rTw
   *   Reference to TokenWriter
   *
   * @exception Exception 
   *   - IO errors (id 2)
   */
  void SWrite(TokenWriter& rTw) const;

  /**
   * Write statistics comment to console.
   * Note: this write function uses the virtual function DoSWrite(), to be 
   * reimplemented by derived classes.
   *
   */
  void SWrite(void) const;

  /**
   * Write statistics to a string.
   * Note: this write function uses the virtual function DoSWrite(), to be 
   * reimplemented by derived classes.
   *
   * @return
   *   output string
   * @exception Exception
   *   - IO errors (id 2)
   */
  std::string ToSText(void) const;

  /**
   * Read configuration data from file with label specified.
   * Note: all read functions use the virtual function DoRead(), to be 
   * reimplemented for by derived classes.
   *
   * @param rFileName
   *   Name of file
   * @param rLabel
   *   Section to read from 
   * @param pContext
   *   Read context to provide contextual information
   *
   * @exception Exception
   *   - IO errors (id 1)
   *   - token mismatch from DoRead()
   */
  void Read(const std::string& rFileName, const std::string& rLabel = "", const Type* pContext=0);

  /**
   * Read configuration data from a string.
   * Note: this read function uses the virtual function DoRead(), to be 
   * reimplemented by derived classes.
   *
   * @param rString
   *   String to read from
   * @param rLabel
   *   Section to read
   * @param pContext
   *   Read context to provide contextual information
   * @exception Exception
   *   - IO errors (id 1)
   *   - token mismatch from DoRead()
   */
  void FromString(const std::string& rString, const std::string& rLabel="", const Type* pContext=0);

  /**
   * Read configuration data from TokenReader with label sepcified.
   * Note: all read functions use the virtual function DoRead(), to be 
   * reimplemented for by derived classes.
   *
   * @param rTr
   *   Reference to tokenreader
   * @param rLabel
   *   Section to read
   * @param pContext
   *   Read context to provide contextual information
   *
   * @exception Exception
   *   - IO errors (id 1)
   *   - token mismatch from DoRead()
   */
  void Read(TokenReader& rTr, const std::string& rLabel = "", const Type* pContext=0);


 protected:

  /**
   * Assign configuration data from other object. 
   *
   * Reimplement this function to copy all configuration data from
   * another faudes object. Typically, you will first call the base class'
   * DoAssign, which includes a Clear(). Then, you will set up any additional members.
   *
   * @param rSrc 
   *    Source to copy from
   */
  void DoAssign(const Type& rSrc);

  /**
   * Test equality of configuration data.
   * Derived classes should reimplement this method to compare all relevant 
   * configuration, except the name.
   * 
   * @param rOther 
   *    Other object to compare with.
   * @return 
   *   True on match.
   */
  bool DoEqual(const Type& rOther) const;


  /**
   * Read configuration data of this object from TokenReader.
   *
   * Reimplement this method in derived classes to provide the std token io
   * interface defined in the public section of Type.
   *
   * @param rTr
   *   TokenReader to read from
   * @param rLabel
   *   Section to read
   * @param pContext
   *   Read context to provide contextual information
   *
   * @exception Exception
   *   - IO error (id 1)
   */
  virtual void DoRead(TokenReader& rTr,  const std::string& rLabel = "", const Type* pContext=0);
 
  /**
   * Write configuration data of this object to TokenWriter.
   *
   * Reimplement this method in derived classes to provide the std token io
   * interface defined in the public section of Type.
   *
   * @param rTw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of section to write
   * @param pContext
   *   Write context to provide contextual information
   *
   * @exception Exception 
   *   - IO errors (id 2)
   */
  virtual void DoWrite(TokenWriter& rTw, const std::string& rLabel="",const Type* pContext=0) const;

  /**
   * Write configuration data of this object to TokenWriter in XML format.
   *
   * Reimplement this method in derived classes to provide the XML
   * token io interface defined in the public section of Type. The default implementation
   * invokes the std token output via 
   * DoWrite(TokenWriter&, const std::string&,const Type* )
   *
   * @param rTw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of section to write
   * @param pContext
   *   Write context to provide contextual information
   *
   * @exception Exception 
   *   - IO errors (id 2)
   */
  virtual void DoXWrite(TokenWriter& rTw, const std::string& rLabel="",const Type* pContext=0) const;

  /**
   * Write configuration data in debugging format to TokenWriter.
   *
   * Reimplement this method in derived classes to provide the std token io
   * interface defined in the public section of Type.
   *
   * @param rTw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of section to write
   * @param pContext
   *   Write context to provide contextual information
   *
   * @exception Exception 
   *   - IO errors (id 2)
   */
  virtual void DoDWrite(TokenWriter& rTw, const std::string& rLabel="",const Type* pContext=0) const;

  /**
   * Write statistical data as a comment to TokenWriter.
   *
   * Reimplement this method in derived classes to provide the std token io
   * interface defined in the public section of Type.
   *
   * @param rTw
   *   Reference to TokenWriter
   *
   * @exception Exception 
   *   - IO errors (id 2)
   */
  virtual void DoSWrite(TokenWriter& rTw) const;

  /** 
   * Get objects's type definition. 
   *
   * Returns the type definition corresponding to this object, or
   * NULL if the object is not of a registered type.
   *
   * Technical note: for minimal memory requirement, the type definition
   * is not cached but retrieved on every invokation of this method.
   * Derived classes may reimplement this method for performance 
   * reasons. Options include a look-up cache or a static member 
   * for the actual type definition. The latter variant will make the
   * type independant from the type registry.
   *
   * @return 
   *   Type definition reference.
   */
  virtual const TypeDefinition* TypeDefinitionp(void) const;


  /*
   * Convenience function to set up std begin token
   * for XML mode token I/O.
   *
   *
   * @param rLabel
   *   User specified label
   * @param rFallbackLabel 
   *   Class defined  fallback label
   * @return
   *   Configured begin token
   */
  virtual Token XBeginTag(const std::string& rLabel="", const std::string& rFallbackLabel="") const;


private:

  // static string constant
  static std::string msStringVoid;
  static std::string msStringEmpty;

};




/** faudes type declaration macro */
#define FAUDES_TYPE_DECLARATION(ftype,ctype,cbase)   \
  public: virtual ctype* New(void) const;             \
  public: virtual ctype* Copy(void) const;            \
  public: virtual const Type* Cast(const Type* pOther) const; \
  public: virtual ctype& Assign(const Type& rSrc);      \
  public: virtual bool Equal(const Type& rOther) const; \
  public: virtual ctype& operator=(const ctype& rSrc);  \
  public: virtual bool operator==(const ctype& rOther) const; \
  public: virtual bool operator!=(const ctype& rOther) const; 

/** faudes type declaration macro, template version */
#define FAUDES_TYPE_TDECLARATION(ftype,ctype,cbase)   \
  public: virtual ctype* New(void) const;             \
  public: virtual ctype* Copy(void) const;            \
  public: virtual const Type* Cast(const Type* pOther) const; \
  public: virtual ctype& Assign(const Type& rSrc);      \
  public: virtual bool Equal(const Type& rOther) const; \
  public: virtual ctype& operator=(const ctype& rSrc);  \
  public: virtual bool operator==(const ctype& rOther) const; \
  public: virtual bool operator!=(const ctype& rOther) const; 

/** faudes type implementation macros */
#define FAUDES_TYPE_IMPLEMENTATION_NEW(ftype,ctype,cbase)	\
  ctype* ctype::New(void) const { return new ctype(); } 
#define FAUDES_TYPE_IMPLEMENTATION_COPY(ftype,ctype,cbase)	\
  ctype* ctype::Copy(void) const { return new ctype(*this); } 
#define FAUDES_TYPE_IMPLEMENTATION_CAST(ftype,ctype,cbase)	\
  const Type* ctype::Cast(const Type* pOther) const { \
    return dynamic_cast< const ctype * >(pOther); } 
#define FAUDES_TYPE_IMPLEMENTATION_ASSIGN(ftype,ctype,cbase)	\
  ctype& ctype::Assign(const Type& rSrc) { \
    if(const ctype* csattr=dynamic_cast< const ctype * >(&rSrc)) {	\
      this->Clear(); DoAssign(*csattr);} \
    else {    \
      cbase::Assign(rSrc);};  \
    return *this;} \
  ctype& ctype::operator=(const ctype& rSrc) { this->Clear(); DoAssign(rSrc); return *this; }
#define FAUDES_TYPE_IMPLEMENTATION_EQUAL(ftype,ctype,cbase)	\
  bool ctype::Equal(const Type& rOther) const { \
    if(&rOther==this) return true; \
    if(typeid(rOther) != typeid(*this)) return false; \
    const ctype* csattr=dynamic_cast<const ctype*>(&rOther); \
    if(!csattr) return false; \
    if(!DoEqual(*csattr)) return false;		\
    return true;} \
  bool ctype::operator==(const ctype& rOther) const { return DoEqual(rOther); } \
  bool ctype::operator!=(const ctype& rOther) const { return !DoEqual(rOther); }

/** faudes type implementation macros, template version */
#define FAUDES_TYPE_TIMPLEMENTATION_NEW(ftype,ctype,cbase,ctemp)	\
  ctemp ctype* ctype::New(void) const {			\
    return new ctype(); } 
#define FAUDES_TYPE_TIMPLEMENTATION_COPY(ftype,ctype,cbase,ctemp)	\
  ctemp ctype* ctype::Copy(void) const {			\
    return new ctype(*this); } 
#define FAUDES_TYPE_TIMPLEMENTATION_CAST(ftype,ctype,cbase,ctemp)	\
  ctemp const Type* ctype::Cast(const Type* pOther) const { \
    return dynamic_cast< const ctype * >(pOther); } 
#define FAUDES_TYPE_TIMPLEMENTATION_ASSIGN(ftype,ctype,cbase,ctemp)	\
  ctemp ctype& ctype::Assign(const Type& rSrc) { \
    if(const ctype* csattr=dynamic_cast< const ctype * >(&rSrc)) {	\
      this->Clear(); DoAssign(*csattr);} \
    else {    \
      cbase::Assign(rSrc);};  \
    return *this;} \
  ctemp ctype& ctype::operator=(const ctype& rSrc) { this->Clear(); DoAssign(rSrc); return *this; }
#define FAUDES_TYPE_TIMPLEMENTATION_EQUAL(ftype,ctype,cbase,ctemp)	\
  ctemp bool ctype::Equal(const Type& rOther) const { \
    if(&rOther==this) return true; \
    if(typeid(rOther) != typeid(*this)) return false; \
    const ctype* csattr=dynamic_cast<const ctype*>(&rOther); \
    if(!csattr) return false; \
    if(!DoEqual(*csattr)) return false;		\
    return true;} \
  ctemp bool ctype::operator==(const ctype& rOther) const { return DoEqual(rOther); } \
  ctemp bool ctype::operator!=(const ctype& rOther) const { return !DoEqual(rOther); }


/** faudes type implementation macros, overall */
#define FAUDES_TYPE_IMPLEMENTATION(ftype,ctype,cbase)	\
  ctype* ctype::New(void) const {			\
    return new ctype(); }  \
  ctype* ctype::Copy(void) const {			\
    return new ctype(*this); } \
  const Type* ctype::Cast(const Type* pOther) const { \
    return dynamic_cast< const ctype * >(pOther); } \
  ctype& ctype::Assign(const Type& rSrc) { \
    if(const ctype* csattr=dynamic_cast< const ctype * >(&rSrc)) {	\
      this->Clear(); this->DoAssign(*csattr);} \
    else {    \
      cbase::Assign(rSrc);};  \
    return *this;} \
  ctype& ctype::operator=(const ctype& rSrc) { this->Clear(); this->DoAssign(rSrc); return *this; } \
  bool ctype::Equal(const Type& rOther) const { \
    if(&rOther==this) return true; \
    if(typeid(rOther) != typeid(*this)) return false; \
    const ctype* csattr=dynamic_cast<const ctype*>(&rOther); \
    if(!csattr) return false; \
    if(!this->DoEqual(*csattr)) return false;		\
    return true;} \
  bool ctype::operator==(const ctype& rOther) const { return this->DoEqual(rOther); } \
  bool ctype::operator!=(const ctype& rOther) const { return !this->DoEqual(rOther); }


/** faudes type implementation macros, overall */
#define FAUDES_TYPE_TIMPLEMENTATION(ftype,ctype,cbase,ctemp)	\
  ctemp ctype* ctype::New(void) const {			\
    return new ctype(); }  \
  ctemp ctype* ctype::Copy(void) const {			\
    return new ctype(*this); } \
  ctemp const Type* ctype::Cast(const Type* pOther) const { \
    return dynamic_cast< const ctype * >(pOther); } \
  ctemp ctype& ctype::Assign(const Type& rSrc) { \
    if(const ctype* csattr=dynamic_cast< const ctype * >(&rSrc)) {	\
      this->Clear(); this->DoAssign(*csattr);} \
    else {    \
      cbase::Assign(rSrc);};  \
    return *this;} \
  ctemp ctype& ctype::operator=(const ctype& rSrc) { this->Clear(); this->DoAssign(rSrc); return *this; } \
  ctemp bool ctype::Equal(const Type& rOther) const { \
    if(&rOther==this) return true; \
    if(typeid(rOther) != typeid(*this)) return false; \
    const ctype* csattr=dynamic_cast<const ctype*>(&rOther); \
    if(!csattr) return false; \
    if(!this->DoEqual(*csattr)) return false;		\
    return true;} \
  ctemp bool ctype::operator==(const ctype& rOther) const { return this->DoEqual(rOther); } \
  ctemp bool ctype::operator!=(const ctype& rOther) const { return !this->DoEqual(rOther); }


/** faudes type implementation macros, overall */
/*
#define FAUDES_TYPE_IMPLEMENTATION(ftype,ctype,cbase)	\
  ctype* ctype::New(void) const {			\
    return new ctype(); }  \
  ctype* ctype::Copy(void) const {			\
    return new ctype(*this); }			\
  const Type* ctype::Cast(const Type* pOther) const { \
    return dynamic_cast<const ctype*>(pOther); } \
  ctype& ctype::Assign(const Type& rSrc) { \
    if(const ctype* csattr=dynamic_cast<const ctype*>(&rSrc)) \
      { this->Clear(); DoAssign(*csattr); return *this;}      \
    cbase::Assign(rSrc); \
    return *this;} \
  ctype& ctype::operator=(const ctype& rSrc) { this->Clear(); DoAssign(rSrc); return *this;} \
  bool ctype::Equal(const Type& rOther) const { \
    if(&rOther==this) return true; \
    if(typeid(rOther) != typeid(*this)) return false; \
    const ctype* csattr=dynamic_cast<const ctype*>(&rOther);	\
    if(!csattr) return false; \
    if(!DoEqual(*csattr)) return false;		\
    return true;} \
  bool ctype::operator==(const ctype& rOther) const { return DoEqual(rOther); } \
  bool ctype::operator!=(const ctype& rOther) const { return !DoEqual(rOther); } 
*/



/** faudes type implementation macros, individual, template version */
/*
#define FAUDES_TYPE_TIMPLEMENTATION_NEW(ftype,ctype,cbase,ctemp)	\
  ctemp ctype* ctype::New(void) const {			\
    return new ctype(); } 
#define FAUDES_TYPE_TIMPLEMENTATION_COPY(ftype,ctype,cbase,ctemp)	\
  ctemp ctype* ctype::Copy(void) const {			\
    return new ctype(*this); } 
#define FAUDES_TYPE_TIMPLEMENTATION_CAST(ftype,ctype,cbase,ctemp)	\
  ctemp const Type* ctype::Cast(const Type* pOther) const { \
    return dynamic_cast<const ctype*>(pOther);} 
#define FAUDES_TYPE_TIMPLEMENTATION_ASSIGN(ftype,ctype,cbase,ctemp)	\
  ctemp ctype& ctype::Assign(const Type& rSrc) { \
    if(const ctype* csattr=dynamic_cast<const ctype*>(&rSrc)) { \
      this->Clear(); DoAssign(*csattr); return *this;}		\
    cbase::Assign(rSrc); \
    return *this;} \
  ctemp ctype& ctype::operator=(const ctype& rSrc) { this->Clear(); DoAssign(rSrc); return *this; }
#define FAUDES_TYPE_TIMPLEMENTATION_EQUAL(ftype,ctype,cbase,ctemp)	\
  ctemp bool ctype::Equal(const Type& rOther) const { \
    if(&rOther==this) return true; \
    if(typeid(rOther) != typeid(*this)) return false; \
    const ctype* csattr=dynamic_cast<const ctype*>(&rOther); \
    if(!csattr) return false; \
    if(!this->DoEqual(*csattr)) return false;		\
    return true;} \
  ctemp bool ctype::operator==(const ctype& rOther) const { return this->DoEqual(rOther); } \
  ctemp bool ctype::operator!=(const ctype& rOther) const { return !this->DoEqual(rOther); }
*/


/** faudes type implementation macros, overall, template version */
/*
#define FAUDES_TYPE_TIMPLEMENTATION(ftype,ctype,cbase,ctemp)	\
  ctemp ctype* ctype::New(void) const {		\
    return new ctype(); }  \
  ctemp ctype* ctype::Copy(void) const {			\
    return new ctype(*this); }  \
  ctemp const Type* ctype::Cast(const Type* pOther) const { \
    return dynamic_cast<const ctype*>(pOther);} \
  ctemp ctype& ctype::Assign(const Type& rSrc) { \
    if(const ctype* csattr=dynamic_cast<const ctype*>(&rSrc)) \
      { this->Clear(); DoAssign(*csattr); return *this;}      \
    cbase::Assign(rSrc); \
    return *this;} \
  ctemp ctype& ctype::operator=(const ctype& rSrc) { this->Clear(); DoAssign(rSrc); return *this; } \
  ctemp bool ctype::Equal(const Type& rOther) const { \
    if(&rOther==this) return true; \
    if(typeid(rOther) != typeid(*this)) return false; \
    const ctype* csattr=dynamic_cast<const ctype*>(&rOther);	\
    if(!csattr) return false; \
    if(!this->DoEqual(*csattr)) return false;		\
    return true;} \
  ctemp bool ctype::operator==(const ctype& rOther) const { return this->DoEqual(rOther); } \
  ctemp bool ctype::operator!=(const ctype& rOther) const { return !this->DoEqual(rOther); } 
*/

/** faudes type implementation macros, overall, debug version */
/*
#define FAUDES_TYPE_IMPLEMENTATION(ctype,cbase,ctemp)	\
  ctemp ctype* ctype::New(void) const {			\
    return new ctype(); }  \
  ctemp const ctype* ctype::Cast(const Type* pOther) const { \
    return dynamic_cast<const ctype*>(pOther);} \
  ctemp ctype& ctype::Assign(const Type& rSrc) { \
    FD_WARN("RTI "<< typeid(ctype).name() << "::ASSIGN() V: " << typeid(*this).name() << \
      " from " << typeid(rSrc).name()); \
    if(const ctype* csattr=dynamic_cast<const ctype*>(&rSrc)) { this->Clear(); return DoAssign(*csattr);} \
    cbase::Assign(rSrc); \
    return *this;} \
  ctemp ctype& ctype::operator=(const ctype& rSrc) { \
    FD_WARN("RTI "<< typeid(ctype).name() << "::ASSIGN() O: " << typeid(*this).name() << \
      " from " << typeid(rSrc).name()); \
    this->Clear(); \
    return DoAssign(rSrc); }
*/



/**
 * Structure to hold documentation data relating to a faudes-type or -function. 
 * This class is the common base for faudes::TypeDefinition and faudes::FunctionDefinition. 
 * It supports token io as demonstrated by the follwoing example for a type defintion:
 *
 * @code
 *	<TypeDefinition name="CoreFaudes::Generator" ctype="faudes::Generator">
 *
 *	<Documentation ref="generators.html#plain"> 
 *      The common 5 tuple G=(Sigma, Q, delta, Qo, Qm).
 *	<Documentation/>
 *
 *	<Keywords> "generator" "language" </Keywords>
 *
 *	</TypeDefinition>
 * @endcode
 *
 * Technical detail: Documentation is derived from Type for the purpose of token IO. We
 * still implement the faudes type interface to make it a fully qualified faudes data type.
 *
 * Technical detail: To facilitate inheritance, token io of member data and token io of
 * the section tags is separated.
 */

class FAUDES_API Documentation : public Type {

  // std faudes type interface
  FAUDES_TYPE_DECLARATION(Void,Documentation,Type)
  
public:
  /** Constructor */
  Documentation(void);

  /** Copy constructor */
  Documentation(const Documentation& rOther);

  /** Destructor */
  virtual ~Documentation(void){};

  /**
   * Clear 
   */
  void Clear(void);

  /**
   * Get name of the entety to document (aka faudes-type or faudes-function).
   *
   * @return
   * 	Name
   */
  const std::string& Name(void) const;

  /**
   * Get name of plugin.
   * The plugin name defaults to CoreFaudes.
   *
   * @return
   * 	Name
   */
  const std::string& PlugIn(void) const;

  /**
   * Get corresponding C++ type
   *
   * @return
   * 	CType, or "" if no such
   */
  const std::string& CType(void) const;

  /**
   * @return
   * 	Short textual documentation.
   */
  const std::string& TextDoc(void) const;

  /**
   * @return
   * 	Filename pointing to the html documentation.
   */
  const std::string& HtmlDoc(void) const;

  /**
   * @return
   * 	CSV-string containing keywords.
   */
  const std::string& Keywords(void) const;

  /**
   * Search comma-seperated keywords for a substring. This should be
   * extended to regular expressions in a future release.
   *
   * @param rPattern
   * 	String-pattern.
   *
   * @return
   * 	Matching keyword or "" if no match
   */
  std::string MatchKeyword(const std::string& rPattern) const;

  /**
   * Not implemented
   * @return
   * 	Number of keywords.
   */
  int KeywordsSize(void) const;

  /**
   * @param pos
   *   Position of keyword
   * @return
   * 	Keyword at specified position (or "" if pos out of range)
   */
  std::string KeywordAt(int pos) const;

  /**
   * Get auto-register flag.
   *
   * This flag indicated that the respective type  was (will be)
   * registered by a libFAUDES static initialisation protorype.
   *
   * @return
   * 	True <> C++-automatic-registration
   */
  bool AutoRegistered(void) const;

  /**
   * Get application-registered flag.
   *
   * @return
   * 	True <> registered by application
   */
  bool ApplicationRegistered(void) const;

  /**
   * Merge documentation from token stream.
   * An exception is thrown if the current type name differs from the one in the documentation.
   *
   * @param rTr
   * 	TokenReader to read from.
   *
   * @exception Exception
   *  - Type mismatch (id )
   *  - Token mismatch (id 50, 51, 52)
   *  - IO Error (id 1)
   */
  virtual void MergeDocumentation(TokenReader& rTr);



 protected:

  /**
   * Set name.
   *
   * @param name
   * 	New name.
   */
  void Name(const std::string& name);

  /**
   * Set name of plugin
   *
   * @param plugin
   * 	New name.
   */
  void PlugIn(const std::string& plugin);

  /**
   * Set C++ type
   *
   * @param name
   * 	New ctype.
   */
  void CType(const std::string& name);

  /**
   * Set a short textual documentation.
   *
   * @param textdoc
   * 	New textual documentation.
   */
  void TextDoc(const std::string& textdoc);

  /**
   * Set auto-register flag.
   * 
   * See also AutoRegistered(void)
   *
   * @param flag
   * 	Flag value.
   */
  void AutoRegistered(bool flag);

  /**
   * Set application-registered flag.
   * 
   * See also AutoRegistered(void)
   *
   * @param flag
   * 	Flag value.
   */
  void ApplicationRegistered(bool flag);

  /**
   * Set name of file pointing to the html documentation.
   *
   * @param fname
   * 	Filename
   */
  void HtmlDoc(const std::string& fname);

  /**
   * Append keyword.
   *
   * @param rKeyword
   * 	Keyword
   */
  void AddKeyword(const std::string& rKeyword);

  /**
   * Std faudes type interface: assignment.
   *
   * @param rSrc 
   *    Source to copy from
   * @return Reference to this object.
   */
  void DoAssign(const Documentation& rSrc);

  /**
   * Std faudes type interface: test equality
   * 
   * @param rOther 
   *    Other object to compare with.
   * @return 
   *   True on match.
   */
  bool DoEqual(const Documentation& rOther) const;

  /**
   * Read configuration data of this object from TokenReader.
   *
   * This virtual function reads documentation from a token stream. 
   * The section defaults to Documentation. It invokes DoReadCore to
   * do the member data token reading. 
   *
   * @param rTr
   *   TokenReader to read from
   * @param rLabel
   *   Section to read
   * @param pContext
   *   Read context to provide contextual information (ignored)
   *
   * @exception Exception
   *  - Token mismatch (id 50, 51, 52)
   *  - IO Error (id 1)
   */
  virtual void DoRead(TokenReader& rTr,  const std::string& rLabel = "", const Type* pContext=0);
 
  /**
   * Read configuration data of this object from TokenReader.
   *
   * This virtual function reads documentation member data only. 
   * It does NOT read the enclosing begin and end tokens.
   *
   * @param rTr
   *   TokenReader to read from
   *
   * @exception Exception
   *  - Token mismatch (id 50, 51, 52)
   *  - IO Error (id 1)
   */
  virtual void DoReadCore(TokenReader& rTr);
 


  /**
   * Write configuration data of this object to TokenWriter.
   *
   * This virtual function writes documentation to a token stream. 
   * The section defaults to Documentation. It invokes DoWriteCore to
   * do the actual member data writing. 
   *
   * @param rTw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of section to write
   * @param pContext
   *   Write context to provide contextual information
   *
   * @exception Exception 
   *   - IO errors (id 2)
   */
  virtual void DoWrite(TokenWriter& rTw, const std::string& rLabel="",const Type* pContext=0) const;


  /**
   * Write configuration data of this object to TokenWriter.
   *
   * This virtual function reads documentation members only. 
   * It does NOT write enclosing begin and end tokens.
   *
   * @param rTw
   *   Reference to TokenWriter
   *
   * @exception Exception 
   *   - IO errors (id 2)
   */
  virtual void DoWriteCore(TokenWriter& rTw) const;


  /** Faudes name. */
  std::string mName;

  /** Faudes plugin. */
  std::string mPlugIn;

  /** Corresponing C++ type, or "" if no such. */
  std::string mCType;

  /** String containing the text-documentation. */
  std::string mTextDoc;

  /** String containing the filename of the corresponding html-documentation. */
  std::string mHtmlDoc;

  /** Comma-seperated string containing all keywords. */
  std::string mKeywords;

  /** Constant characted used to seperate keywords */
  static const char mDelim = ';';

  /** Flag to indicate automated registration */
  bool mAutoRegistered;

  /** Flag to indicate application registration */
  bool mApplicationRegistered;

}; // Documentation



/**
 * A TypeDefinition defines a faudes-type in that it specifies
 * a faudes-type name to identify the type and a method
 * NewObject() to instantiate objects of the respective type. 
 * In this sense, TypeDefinition is a so called factory class.
 * Technically, the TypeDefinition holds one instance of the faude type,
 * the so called prototype object, and NewObject() invokes the New() method
 * of the prototype. Notebly, there is only one class TypeDefinition that by
 * parametrisation defins all derivates of Type.
 * 
 * TypeDefinition is derived from faudes::Documentation and therefore additional
 * documentation-data can be associated.
 *
 *
 * @ingroup RunTimeInterface
 */

class FAUDES_API TypeDefinition : public Documentation {

 // std faudes type interface
 FAUDES_TYPE_DECLARATION(Void,TypeDefinition,Documentation)

 // regisry is friend to set protected values
 friend class TypeRegistry;

 public:

  /** 
   * Constructor 
   *
   * The default constructor instantiates an invalid type definition
   * without prototype. To construct
   * a valid type definition, use the static Constructor() template
   * function.
   */
  TypeDefinition(const std::string& name="") : Documentation(), mpType(NULL) {Name(name);};

  /**
   * Destructor.
   *
   * Delete prototype object.
   */
  virtual ~TypeDefinition(void){ Prototype(NULL); };

  /**
   * Construct empty TypeDefinition object.
   * The given template parameter denotes any libFAUDES class derived from faudes::Type
   * A new instance of this class is assigned to member variable (pType)
   * whereas the name is set as specified.
   *
   * @tparam T
   *   Actual c class, derived from Type
   * @param rTypeName
   *   Name to identify this faudes-type<; defaults to the plattform
   *   dependand typeid from the c++ runtime type information system.
   * @return
   *   Newly constructed type definition.
   *
   */
  template<class T>
  static TypeDefinition* Constructor(const std::string& rTypeName="");

  /**
   * Construct empty TypeDefinition object.
   * The given prototype is assigned to the member variable pType,
   *
   * @param pProto
   *   Prototype, derived from Type
   * @param rTypeName
   *   Name to identify this faudes-type<; defaults to the plattform
   *   dependand typeid from the c++ runtime type information system.
   * @return
   *   Newly constructed type definition.
   *
   */
  static TypeDefinition* Constructor(Type* pProto, const std::string& rTypeName="");

  /**
   * Construct TypeDefinition object and read name and
   * documentation-data from TokenReader.
   *
   * @tparam T
   *   Actual c class, derived from Type
   * @param rFileName
   *   Name of file to read.
   * @return
   *   Newly constructed type definition.
   *
   * @exception Exception
   *  - Token mismatch (id 50, 51, 52)
   *  - IO Error (id 1)
   */
  template<class T>
  static TypeDefinition* FromFile(const std::string& rFileName);


  /**
   * Return pointer to faudes-object prototype 
   *
   * Note: this method is meant for inspection only, control over
   * the prototype remains with the TypeDefinition. Use
   * NewObject() to instantiate a new faudes-object.
   *
   * @return
   *   Reference to prototype object
   */
  const Type* Prototype(void) const;


  /**
   * Construct faudes-object on heap.
   * Return pointer to new instance of assigned Type class.
   *
   * Note: If no prototype is installed, NULL is returned.
   *
   * @return
   * 	Pointer to new Type instance.
   */
  Type* NewObject(void) const;


  /** 
   * Parameter access: Xml Element Tag
   *
   * This parameter is used for Xml IO of sets and vectors. It determines
   * the tag to used for individual elments.
   *
   * @return
   *   Tag parameter.
   */
  const std::string& XElementTag(void) const; 

  /** 
   * Parameter access: Xml Element Tag
   *
   * @param rTag
   *   New tag parameter
   */
  void XElementTag(const std::string& rTag); 

protected:


  /**
   * Std faudes type interface: assignment.
   *
   * @param rSrc 
   *    Source to copy from
   * @return Reference to this object.
   */
  void DoAssign(const TypeDefinition& rSrc);

  /**
   * Std faudes type interface: test equality
   * 
   * @param rOther 
   *    Other object to compare with.
   * @return 
   *   True on match.
   */
  bool DoEqual(const TypeDefinition& rOther) const;

  /** Disable copy constructor */
 TypeDefinition(const TypeDefinition& rOther) : Documentation(rOther) {}; // todo: implement ?? for stl maps ?

  /**
   * Clear documentation-data; do *NOT* delete prototype  (this is for using Read to 
   * merge/overwrite documentation)
   */
  void Clear(void);

  /**
   * Use given object as prototype.
   *
   * The TypeDefinition takes ownership of the
   * provided object.
   *
   * @param pType
   * 	Any class that inherits Type.
   */
  virtual void Prototype(Type* pType);

  /**
   * Read configuration data of this object from TokenReader.
   *
   * The section defaults to "TypeDefinition", context ignored.
   * Actual reading is done by DoReadCore.
   *
   * @param rTr
   *   TokenReader to read from
   * @param rLabel
   *   Section to read
   * @param pContext
   *   Read context to provide contextual information (ignored)
   *
   * @exception Exception
   *   - Token mismatch (id 50, 51, 52)
   *   - IO error (id 1)
   */
  virtual void DoRead(TokenReader& rTr,  const std::string& rLabel = "", const Type* pContext=0);
 
  /**
   * Read configuration data of this object from TokenReader.
   *
   * This method reads members only, it does not read the section.
   *
   * @param rTr
   *   TokenReader to read from
   *
   * @exception Exception
   *   - Token mismatch (id 50, 51, 52)
   *   - IO error (id 1)
   */
  virtual void DoReadCore(TokenReader& rTr);
 
  /**
   * Write configuration data of this object to TokenWriter.
   *
   * The section defaults to "TypeDefinition", context ignored.
   * Actual writing is done by DoWriteCore.
   *
   * @param rTw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of section to write
   * @param pContext
   *   Write context to provide contextual information
   *
   * @exception Exception 
   *   - IO errors (id 2)
   */
  virtual void DoWrite(TokenWriter& rTw, const std::string& rLabel="",const Type* pContext=0) const;

  /**
   * Write configuration data of this object to TokenWriter.
   *
   * This method wrtite plain member data, the section lables are not
   * written.
   *
   * @param rTw
   *   Reference to TokenWriter
   *
   * @exception Exception 
   *   - IO errors (id 2)
   */
  virtual void DoWriteCore(TokenWriter& rTw) const;

  /** Type-pointer tp prototype instance */
  Type* mpType;

  /** Extra documentation/parameter: Xml Element Tag */
  std::string mXElementTag;

}; //TypeDefinition




/**********************************************************************************************
***********************************************************************************************
***********************************************************************************************

Implemention of template members functions

***********************************************************************************************
***********************************************************************************************
**********************************************************************************************/


// Typedefinition constructor function
template<class T>
TypeDefinition* TypeDefinition::Constructor(const std::string& rTypeName){
  FD_DRTI("TypeDefinition::Construct<" << typeid(T).name() << ">(" << rTypeName << ")");
  return Constructor(new T, rTypeName);
}


// Type definition constructor function
template<class T>
TypeDefinition* TypeDefinition::FromFile(const std::string& rFileName){
  FD_DRTI("TypeDefinition::FromFile<" << typeid(T).name() << ">()");
  // construct with fallback name
  TypeDefinition* td = Constructor<T>();
  // read docu, incl actual name
  td->Read(rFileName);
  // done
  return(td);
}





} // namespace

#endif /* FAUDES_RTITYPES_H */
