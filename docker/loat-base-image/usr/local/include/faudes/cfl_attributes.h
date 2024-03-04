/** @file cfl_attributes.h Classes AttributeVoid and AttributeFlags  */


/* FAU Discrete Event Systems Library (libfaudes)

Copyright (C) 2007  Thomas Moor
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


#ifndef FAUDES_ATTRIBUTES_H
#define FAUDES_ATTRIBUTES_H

#include "cfl_types.h"
#include "cfl_registry.h"
#include "cfl_tokenreader.h"
#include "cfl_tokenwriter.h"

namespace faudes {


/**
 * Minimal Attribute. Attributes are used as template parameters for
 * faudes containers and generators and facilitate the modelling of customized  
 * properties of events, states and transitions.  The AttributeVoid class defines
 * the minimal interface of faudes attributes and therefore is the designated
 * base class for all attribute implementations. The AttributeVoid class does
 * not define any actual properties. See AttributeFlags for a non-trivial example.
 *
 * To derive a class from AttributeVoid you should reimplement the virtual
 * interface
 * - virtual methody DoRead and DoWrtie for token io (as in faudes::Type)
 * - virtual methods for DoAssign() (as in faudes::Type) 
 * - the factory method New() (use provided macro from faudes::Type)
 * - the rti typecast method Cast() (use provided macro from faudes::Type)
 * - user level Assign() method (use provided macro from faudes::Type)
 */

class FAUDES_API AttributeVoid : public Type {
 
FAUDES_TYPE_DECLARATION(Void,AttributeVoid,Type)

public:

  /** Constructor */
  AttributeVoid(void);

  /** Copy Constructor */
  AttributeVoid(const AttributeVoid& rSrcAttr);

  /** Destructor */
  virtual ~AttributeVoid(void);

  /** 
   * Test for default value.
   */
  virtual bool IsDefault(void) const {return true;};

  /**
   * Set to default value.
   * Derived classes must reimplement this function for Clear to operate properly.
   */
  virtual void SetDefault(void) {};

  /**
   *   Synonym for SetDefault to match std interface
   */
  virtual void Clear(void) { SetDefault(); };

  /**
   * Skip attribute tokens.
   *
   * Helper method to be called after all sttribute derived classes had their
   * chance to read their data. It skips all tokens and sections until it reaches a 
   * String or decimal Integer.
   *
   * @param rTr
   *   TokenReader to read from
   * @exception Exception
   *   - IO error (id 1)
   */
  static void Skip(TokenReader& rTr);

protected:

  /**
   * Assign attribute members. 
   * Since AttributeVoid has no members, this method does nothing.
   * Derived classes are meant to reimplement DoAssign by first calling
   * their base and then assigning additional member variables.
   *
   * @param rSrcAttr
   *    Source to assign from
   */
  void DoAssign(const AttributeVoid& rSrcAttr) { (void) rSrcAttr; };

  /**
   * Test equality of configuration data.
   * Derived attributes should reimplement this class to compare
   * configuration data. The base AttributeVoid returns true as a default.
   * @param rOther 
   *    Other object to compare with.
   * @return 
   *   True on match.
   */
  bool DoEqual(const AttributeVoid& rOther) const { (void) rOther; return true; }

  /**
   * Actual read method to read attribute from tokenreader.
   *
   * For derived attributue classes, this method must either read all tokens that
   * belong to the respective attribute, or none. It may throw exceptions on token
   * mismatch within the relevant attribute, but it may not throw exceptions when
   * it encounters tokens that possibly belong to another attribute. The latter are
   * to be skipped by the provided Skip method. See Type::Read
   * for public wrappers.
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
   * Actual write method to write the attribute to a TokenWriter.
   *
   * Reimplement this method for derived attribute classes to define the token io 
   * format. See Type::Write for public wrappers.
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
   * Actual write method to write the attribute to a TokenWriter.
   *
   * Reimplement this method for derived attribute classes to define the token io 
   * format. See Type::Write for public wrappers.
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



}; // class AttributeVoid


/** Convenience typdef flag data */
typedef unsigned long int fType;

/**
 * Boolean flags Attribute. This attribute class uses a flag word to represent 
 * boolean values. The current implementation uses a long int type and hence handles
 * up to 32 flags. Each flag is accessed by the according bit mask. 
 *
 * The current version
 * of libFAUDES uses bits 0,1,2 of event attributes for controllability properties 
 * (see AttributeCFlags) and the bits 31 and 32 of state attributes for the Qt based
 * GUI project. Further versions may use the lower 8 bits of the event aflags and the higher 8
 * bits of state flags. You are free to use any flags for your application, but if possible try
 * to avoid the above mentioned. For extensive use of flags, you may also consider to
 * define a separate attribute class, perhaps with a different fType.
 */



class FAUDES_API AttributeFlags : public AttributeVoid {

FAUDES_TYPE_DECLARATION(Void,AttributeFlags,AttributeVoid)

public:

  /** Default constructor */
  AttributeFlags(void) : AttributeVoid(), mFlags(mDefFlags) {};

  /** Copy constructor */
  AttributeFlags(const AttributeFlags& rOther) : AttributeVoid(), mFlags(rOther.mFlags) {};

  /** Destructor */
  virtual ~AttributeFlags(void) {};

  /**
   * Test a flag
   */
  bool Test(fType mask) const { return ( (mFlags & mask) != 0 ); };

  /**
   * Test multible flags, combine by "and"
   */
  bool TestAll(fType mask) const { return ( (mFlags & mask) == mask ); };

  /**
   * Test multible flags, combine by "or"
   */
  bool TestSome(fType mask) const { return ( (mFlags & mask) != 0 ); };

  /**
   * Test multible flags, combine by "not or"
   */
  bool TestNone(fType mask) const { return ( (mFlags & mask) == 0 ); };

  /**
   * Set multiple flags
   */
  void Set(fType mask) {mFlags |= mask; };

  /**
   * Clear multiple flags
   */
  void Clr(fType mask) {mFlags &= ~mask; };

  /** 
   * Test for default value
   */
  virtual bool IsDefault(void) const {return mFlags==mDefFlags;};

  /** Flags (public access for convenience)  */
  fType mFlags;

  /* default flags */
  const static fType mDefFlags=0x0;


protected:

  /**
   * Assignment method. 
   *
   * @param rSrcAttr
   *    Source to assign from
   */
  void DoAssign(const AttributeFlags& rSrcAttr);

  /**
   * Test equality of configuration data.
   *
   * @param rOther 
   *    Other object to compare with.
   * @return 
   *   True on match.
   */
  bool DoEqual(const AttributeFlags& rOther) const;


  /**
   * Reads attribute from TokenReader, see Type for public wrappers.
   *
   * Test whether the current token is an integer with base 16. If so, read the token to the
   * flags value. Else, dont take any tokens. The label and context arguments are ignored.
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
   * Write to TokenWriter, see Type for public wrappers.
   *
   * If not the defult value, write the flag value as base 16 integer token. Else,
   * do nothing. The label and context arguments are ignored.
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
   * Write to TokenWriter, see Type for public wrappers.
   *
   * If not the defult value, write the flags in XML format.
   * Else, do nothing. The label and context arguments are ignored.
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



}; // class AttributeFlags


} // namespace faudes

#endif
