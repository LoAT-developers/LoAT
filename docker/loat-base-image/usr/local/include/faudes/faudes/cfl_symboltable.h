/** @file cfl_symboltable.h @brief Class SymbolTable */

/* FAU Discrete Event Systems Library (libfaudes)

Copyright (C) 2006  Bernd Opitz
Copywrite (C) 2007 Thomas Moor
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


#ifndef FAUDES_SYMBOLTABLE_H
#define FAUDES_SYMBOLTABLE_H

#include "cfl_definitions.h"
#include "cfl_types.h"
#include "cfl_exception.h"
#include "cfl_helper.h" 
#include "cfl_indexset.h" 

#include <algorithm>
#include <map>
#include <set>
#include <limits>
#include <iostream>
#include <sstream>



namespace faudes {

// forward
class IndexSet;

/**  
 * A SymbolTable associates sybolic names with indices. 
 *
 * Symbolic names are restricted to printable ascii, no quoatation ("),
 * no hash (#) and and no blanks. Indices are of type faudes Idx aka (long unsigned) 
 * integer and must be positive. Both, indices and symbolic names must
 * be unique within each SymbolTable. Consistency checks on input data
 * are preformed, regardless of the FAUDES_CHECKED compiletime option.
 *
 * Generators refer to a global symboltable for event names and hold a local 
 * symboltable for state names.
 *
 *
 */
class FAUDES_API SymbolTable : public Type {
public:

  /** Creates a new SymbolTable */
  SymbolTable(void);

  /** Copy constructor */
  SymbolTable(const SymbolTable& rSrc);

  /** Return name of SymbolTable */
  const std::string& Name(void) const;
		
  /** Set name of SymbolTable */
  void Name(const std::string& rName);

  /** Size of symboltabel */
  Idx Size(void) const;

  /** Clear all entries */
  void Clear(void);


  /** Get maximum index which this SymbolTable accepts */
  Idx MaxIndex(void) const;

  /** 
   * Set maximum index which this SymbolTable accepts
   *
   * @param index
   *   New maximum index
   * @exception Exception
   *   - symboltable overflow (id 40)
   */
  void MaxIndex(Idx index);

  /** Get the largest index in use */
  Idx LastIndex(void) const;

  /** 
   * Symbolic name lookup
   *
   * @param index
   *   Index to lookup
   * @return
   *   Symbolic name of index, or empty string "" for non-existent index
   */
  std::string Symbol(Idx index) const;

  /** 
   * Index lookup
   *
   * @param rName
   *   Symbolic name to lookup
   * 
   * @return 
   *   Index of symbolic name, or 0 for non-existent name
   */
  Idx Index(const std::string& rName) const;

  /** 
   * Test existence of index 
   *
   * @param index
   *   Index to test
   * @return 
   *   True, if index exists
   */
  bool Exists(Idx index) const;
	
  /** 
   * Test existence of symbol
   *
   * @param rName
   *   Symbolic name to test
   * @return
   *   True, if name exists
   */
  bool Exists(const std::string& rName) const;

  /** 
   * Test validiy of candidate symbol.
   * The current implementation insists in printable ascii,
   * no quotes ("), no hash (#) and no blanks. 
   *
   * @param rName
   *   Symbolic name to test
   * @return
   *   True, if name is a valid symbol
   */
  static bool ValidSymbol(const std::string& rName);
		
  /** 
   * Create unique symbolic name by adding an underscore and extra digits.
   * The current implementation tries to be smart and overwrites
   * any previously added digits. It is also slow.
   *
   * @param rName
   *   Candidate symbolic name
   * @return
   *   Unique symbolic name
   */
  std::string UniqueSymbol(const std::string& rName) const;
		
  /** 
   * Add new entry (aka symbolic name and index) to symboltable, 
   * 
   * @param index
   *   New index
   * @param rName
   *   New symbolic name
   * @return
   *   New index
   * @exception Exception
   *   - name already associated with another index (id 41)
   *   - index already associated with another name (id 42)
   *   - invalid name (id 43)
   */
  Idx InsEntry(Idx index, const std::string& rName);

		
  /** 
   * Merge a symbolic name with symboltable.
   * If the symbol does not exist, find a new index and add the new entry. 
   * If the symbol does exist, lookup its index.
   * 
   * @param rName
   *   Symbolic name to merge
   * @return
   *   Index of rName
   * @exception Exception
   *   - invalid name (id 43)
   */
  Idx InsEntry(const std::string& rName);


  /** 
   * Set symbolic name for existing entry.
   * If the name is the emptystring, an existing entry is cleared.
   * All other invalid names throw an exception.
   *
   * @param index
   *   Index to specify entry
   * @param rName
   *   New esymbolic name for index
   *
   * @exception Exception
   *   - name already associated with another index (id 41)
   *   - invalid name (id 43)
   */
  void SetEntry(Idx index, const std::string& rName);
		
  /**
   * Set default names ("1", "2", "3", ...) for index. 
   *
   * @param index
   *   Index for which to set the default name
   */
  void SetDefaultSymbol(Idx index);

  /** 
   * Delete entry by index 
   *
   * @param index
   *   Index to delete
   *
   */
  void ClrEntry(Idx index);
		
  /** 
   * Delete entry by symbol
   *
   * @param rName
   *   Symbolic name to delete
   * 
   */
  void ClrEntry(const std::string& rName);

  /** 
   * Restrict to specified indicees.
   *
   * @param rDomain
   *   Indicees to keep.
   * 
   */
  void RestrictDomain(const IndexSet& rDomain);

  /**
   * Get Static Symboltable ref
   * (initialize on first use pattern)
   */
  static SymbolTable* GlobalEventSymbolTablep(void);

 protected:
   
  /** assign my members */
  void DoAssign(const SymbolTable& rSrc);

 private:

  /** Name of the SymbolTable */
  std::string mMyName;
		
  /** Index lookup map */
  std::map<std::string,Idx> mIndexMap;
		
  /** Name lookup map */
  std::map<Idx,std::string> mNameMap;

  /** Upper limit (incl) */
  Idx mMaxIndex;
		
  /** Largest used index + 1 */
  Idx mNextIndex;

  /** Symboltable token io */
  void DoRead(TokenReader& rTr,  const std::string& rLabel = "", const Type* pContext=0);

  /** Symboltable token io */
  void DoWrite(TokenWriter& rTw, const std::string& rLabel="",const Type* pContext=0) const;
};


} // namespace faudes

#endif
