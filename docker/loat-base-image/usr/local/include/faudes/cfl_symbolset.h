/** @file cfl_symbolset.h @brief Class SymbolSet, TaSymbolSet */


/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2006  Bernd Opitz
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



#ifndef FAUDES_SYMBOLSET_H
#define FAUDES_SYMBOLSET_H


#include "cfl_definitions.h"
#include "cfl_attributes.h"
#include "cfl_symboltable.h"
#include "cfl_baseset.h"
#include <set>
#include <map>
#include <algorithm>

namespace faudes {

/** @addtogroup ContainerClasses */
/** @{  */

/**
 * Set of symbols. 
 * 
 * The class is built on top of the faudes version
 * TBaseSet of STL sets. It provides the essentials of the STL interface and 
 * plus token based file IO.
 * Invalid iterators throw an exception (id 62) when used as an argument to a SymbolSet function. 
 * If the macro FAUDES_CHECKED is defined, the attempt to insert an invalid symbol
 * an exception (id 61). 
 *
 * Note that a symbol set holds a plain set of valid faudes symbols with no indices
 * or symboltable associated. If you are looking for a set of items with 
 * mandatory symbolic names you most likely are better of with a NameSet or  a 
 * TaNameSet. Currently, there is no attributed version of a SymbolSet.
 *
 * The token IO format is demonstrated by the following example
 * of a set with name "MySymbols" 
 * \code
 * <MySymbols> 
 * "ASymbol"
 * "AnotherSymbol" 
 * </MySymbols> 
 * \endcode
 * Note that you can read SymbolSet files to NameSets and vice versa.
 *
 */

class FAUDES_API SymbolSet : public TBaseSet<std::string> {

FAUDES_TYPE_DECLARATION(SymbolSet,SymbolSet,TBaseSet<std::string>)

public:

  /**
   * Constructor. 
   */
  SymbolSet(void);

  /**
   * Copy-constructor. 
   */
  SymbolSet(const TBaseSet<std::string>& rOtherSet);

  /**
   * Construct from file. Uses the Read(TokenReader&, const std::string&) function to read.
   * a SymbolSet from section rLabel in file rFilename.
   *
   * @param rFilename
   *   Name of file to read
   * @param rLabel
   *   Section to read
   *
   * @exception Exception
   *   - IO Errors (id 1)
   *   - token musmatch (id 50, 51, 52)
   */
  SymbolSet(const std::string& rFilename, const std::string& rLabel = "SymbolSet");

  /**
   * Virtual destructor
   */
  virtual ~SymbolSet(void) {};

  /**
   * Test whether the given string is a valid faudes symbol
   * @param symbol
   *    Symbol to test
   * @return
   *    True if valid
   */
   bool Valid(const std::string& symbol) const;
   
  /** 
   * Iterators on indexset. 
   */
  typedef TBaseSet<std::string>::Iterator Iterator;

  /** 
   * Insert specified symbol
   *
   * @param symbol
   *    Symbol to insert
   * @return
   *   True if symbol was new to set 
   */
  bool Insert(const std::string& symbol);

  /**
   * Compute an Idx type signature for a Set. This method
   * is currently not implemented.
   *
   * @return
   *   Idx type set signature
   */
  Idx Signature(void) const {return 0;};

  /**
   * Return pretty printable symbol. 
   *
   * @param symbol
   *   Symbol to print
   *
   * @return
   *   String
   */
  std::string Str(const std::string& symbol) const {return symbol; };

 protected:



  /**
   * Assign my members. This method calls the base class to assign its members.
   *
   * @param rSource 
   *    Source to copy from
   * @return
   *    Ref to this set
   */
  void DoAssign(const SymbolSet& rSource);

  /** 
   * Write to TokenWriter, see TBaseSet for public wrappers.
   *
   * @param tw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of section to write, defaults to name of set
   * @param pContext
   *   Write context for contextual information
   *
   * @exception Exception
   *   - IO errors (id 2)
   */
  void DoWrite(TokenWriter& tw, const std::string& rLabel="", const Type* pContext=0) const;

  /**
   * Read from TokenReader, see TBaseSet for public wrappers. 
   *
   * @param rTr
   *   Reference to tokenreader
   * @param rLabel
   *   Section to read
   * @param pContext
   *   Read context for contextual information
   *
   * @exception Exception
   *   - IO errors (id 1)
   *   - token mismatch (id 50, 51, 52)
   */
  void DoRead(TokenReader& rTr, const std::string& rLabel = "", const Type* pContext=0);


};


/** @} doxygen group */


} // namespace faudes

#endif 
