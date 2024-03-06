/** @file cfl_nameset.h @brief Classes NameSet, TaNameSet */

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


#ifndef FAUDES_NAMESET_H
#define FAUDES_NAMESET_H

#include "cfl_definitions.h"
#include "cfl_exception.h"
#include "cfl_basevector.h"
#include "cfl_attrmap.h"
#include "cfl_symboltable.h"
#include "cfl_registry.h"

namespace faudes {

/** @addtogroup Container Classes */
/** @{ */

// Forward declaration for the attributed version of nameset
template<class Attr> class TaNameSet;


/**
 * Set of indices with symbolic names. 
 * In a NameSet, symbolic names are mandatory.
 * The class is derived from IndexSet and uses a pointer to a SymbolTable 
 * to maintain the symbolic names. The static SymbolTable is used as default,
 * which in the context of libfaudes becomes the global event symbol table.
 * It is an error to refer to an unknown symbolic name or to an index
 * with no name associated. When FAUDES_CHECKED is defined, an exception will
 * be thrown. It is also considered an error to relate two NameSets that refer to
 * different SymbolTables (using e.g. SetUnion).  
 *
 *
 * Since symbolic names are mandatory, file IO uses names rather than indices.
 * Technically, file IO is done by TaNameSet functions. This requires a copy and for
 * that reason may be reimplemented in a future versions.
 * The format is demonstrated by the following example
 * of a set with name "Alphabet" consisting of events "alpha", "beta" and "gamma":
 * \code
 * <Alphabet> 
 * "alpha" "beta" "gamma"
 * <\Alphabet> 
 * \endcode
 * Note that when reading a file, indices will be associated with the symbolic names
 * based on availability. Within one libfaudes session, each individual event will
 * be referred to by a unique index.
 */

class FAUDES_API NameSet : public TBaseSet<Idx> {

FAUDES_TYPE_DECLARATION(EventSet,NameSet,TBaseSet<Idx>)

public:

  /** 
   * We implement "protected privacy for template classes" by friendship.
   * This is used for the pragmatic implemention of conversion constructors.
   */
  template<class Attr> friend class TaNameSet;

  /**
   * Constructor for NameSet referring to the static SymbolTable. 
   */
  NameSet(void);
         
  /**
   * Copy-constructor from other NameSet.
   * This also copies the SymbolTable reference, hence the new NameSet
   * will use the same SymbolTable as rOtherSet.
   *
   * @param rOtherSet
   *   Set to copy
   */
  NameSet(const NameSet& rOtherSet);


  /**
   * Constructor from file.
   * This constructor reads a NameSet from a file using the DoRead(TokenReader&, const std::string&)
   * function. The section is specified by rLabel and the static SymbolTable is used.
   *
   *
   * @param rFilename
   *   Name of file
   * @param rLabel
   *   Section for the set in the file; 
   */
  NameSet(const std::string& rFilename, const std::string& rLabel = "");

  /**
   * Virtual destructor
   */
  virtual ~NameSet(void);

  /**
   * Get Pointer mpSymbolTable.
   *
   * @return
   *   Pointer mpSymbolTable
   */
  SymbolTable* SymbolTablep(void) const;

  /**
   * Set SymbolTable reference.
   * This function sets the reference to the SymbolTable. The current implementation
   * clears the set, future versions may implement a re-indexing.
   *
   * @param pSymTab
   *   Pointer to SymbolTable
   */
  void SymbolTablep(SymbolTable* pSymTab);

  /** 
   * Iterators on nameset. 
   */
  using TBaseSet<Idx>::Iterator;

  /**
   * Add an element by index. 
   * Index must be already known to the global SymbolTable. 
   *
   * @param rIndex
   *   Index to add
   * @return 
   *   True, if element was new to set
   * @exception Exception
   *   - no symbolic name for index (id 65)
   */
  bool Insert(const Idx& rIndex);

  /** 
   * Add an element by its symbolic name. If the name is unknown, 
   * a new index will be generated and recorded in the symboltable.
   * If the name is known, the corresponding index will be added to the set.
   *
   * @param rName
   *   Symbolic name of element to add
   *
   * @return 
   *   Index of (new) element
   */
  Idx Insert(const std::string& rName);

  /**
   * Inserts all elements of rOtherSet.
   *
   * @param rOtherSet
   *   Other NameSet
   * @exception Exception
   *   - symboltable mismatch (id 67) 
   */
  virtual void InsertSet(const NameSet& rOtherSet);

  /**
   * Inserts all elements of rOtherSet.
   *
   * This variant requires a runtime cast to access the synboltable.
   * An expection is thrown if the cast fails.
   *
   * @param rOtherSet
   *   Other NameSet
   * @exception Exception
   *   - symboltable mismatch (id 67) 
   *   - cast to nameset failed (id 67) 
   */
  virtual void InsertSet(const TBaseSet<Idx>& rOtherSet);

  /**
   * Delete element by index. The symbolic name is not removed from the SymbolTable.
   *
   * @param rIndex
   *   Index
   * @return
   *   True if element did exist
   */
  virtual bool Erase(const Idx& rIndex);

  /**
   * Delete element by symbolic name. The symbolic name is not removed from the SymbolTable
   *
   * @param rName
   *   symbolic name
   * @return
   *    True if element did exist
   * @exception Exception
   *   - unknown symbolic name (id 66)
   */
  virtual bool Erase(const std::string& rName);

  /**
   * Delete element by iterator. Symbolic nam is not removed from SymbolTable.
   *
   * @param pos
   *   NameSet::iterator
   * @return
   *  iterator to next element
   * @exception Exception
   *   - invalid iterator (id 62)
   */
  virtual NameSet::Iterator Erase(const Iterator& pos);

  /**
   * Erase elements specified by rOtherSet
   *
   * @param rOtherSet
   *   Other StateSet
   * @exception Exception
   *   - symboltable mismatch (id 67) 
   */
   void EraseSet(const NameSet& rOtherSet);

  /**
   * Erase elements specified by rOtherSet
   *
   * This function requires a runtime cast to access the synboltable.
   * An expection is thrown if the cast fails.
   *
   * @param rOtherSet
   *   Other NameSet
   * @exception Exception
   *   - symboltable mismatch (id 67) 
   *   - cast to nameset failed (id 67) 
   */
  virtual void EraseSet(const TBaseSet<Idx>& rOtherSet);

  /**
   * Restrict to elements specified by rOtherSet
   *
   * @param rOtherSet
   *   Other StateSet
   * @exception Exception
   *   - symboltable mismatch (id 67) 
   */
   void RestrictSet(const NameSet& rOtherSet);

  /**
   * Restrict to elements specified by rOtherSet
   *
   * This function requires a runtime cast to access the synboltable.
   * An expection is thrown if the cast fails.
   *
   * @param rOtherSet
   *   Other NameSet
   * @exception Exception
   *   - symboltable mismatch (id 67) 
   *   - cast to nameset failed (id 67) 
   */
  virtual void RestrictSet(const TBaseSet<Idx>& rOtherSet);

  /**
   * Set new name for existing index.
   * FAUDES_CHECKED checks if index exists in NameSet. 
   *
   * @param index
   *   Index to edit
   * @param rName
   *   New name
   *
   * @exception Exception
   *   - index not in this set (id 60)
   *   - index not found in SymbolTable (id 42)
   *   - name already associated with another index (id 44)
   */
  void SymbolicName(Idx index, const std::string& rName);

        
  /**
   * Set new name for existing name
   * FAUDES_CHECKED checks if the specified name exists in NameSet. 
   *
   * @param rName
   *   Symbolic name to edit
   * @param rNewName
   *   New name
   *
   * @exception Exception
   *   - symbolic name not in this set (id 60)
   *   - new name already associated with another index (id 44)
   */
  void SymbolicName(const std::string& rName, const std::string& rNewName);

  /**
   * Name lookup
   *
   * @param index
   *   Index to lookup
   *
   * @return
   *   Corresponding name or empty std::string if non-existent
   */
  std::string SymbolicName(Idx index) const;

  /**
   * Index lookup
   *
   * @param rName
   *   Symbolic name to look up
   *
   * @return 
   *   Corresponding index or 0 for non-existent
   */
  Idx Index(const std::string& rName) const;

  /**
   * Test existence of index
   *
   * @param rIndex
   *   Index to test
   *
   * @return 
   *   True if index is in this set
   */
  bool Exists(const Idx& rIndex) const;

  /** 
   * Test existence of name
   *
   * @param rName
   *   Symbolic name to test
   *
   * @return 
   *   True if index is in this set
   */
  bool Exists(const std::string& rName) const;

  /**
   * Find iterator for index. Returns either a valid iterator
   * or End() for non-existent.
   *
   * @param rIndex
   *   Index to find
   *
   * @return
   *   NameSet::Iterator
   */
  NameSet::Iterator Find(const Idx& rIndex) const;

  /**
   * Find iterator for name. Returns either a valid iterator
   * or End() for non-existent.
   *
   * @param rName
   *   Name to find
   *
   * @return
   *   NameSet::Iterator
   */
  NameSet::Iterator Find(const std::string& rName) const;


  /**
   * Set union operator
   *
   * @return 
   *   Union Set
   *
   * @exception Exception
   *   - symboltable mismatch (id 67) 
   */
  NameSet operator + (const NameSet& rOtherSet) const;

  /**
   * Set difference operator
   *
   * @return 
   *   Difference NameSet
   *
   * @exception Exception
   *   - symboltable mismatch (id 67) 
   */
  NameSet operator - (const NameSet& rOtherSet) const;

  /**
   * Set intersection operator
   *
   * @return 
   *   Intersection NameSet
   *
   * @exception Exception
   *   - symboltable mismatch (id 67) 
   */
  NameSet operator * (const NameSet& rOtherSet) const;


  /** Test for subset  */
  bool operator<= (const NameSet& rOtherSet) const;

  /** Test for superset */
  bool operator>= (const NameSet& rOtherSet) const;


  /**
   * Return pretty printable symbolic name for index.
   * Primary meant for debugging messages.
   *
   * @param rIndex
   *   Index to print
   *
   * @return
   *   String
   */
  std::string Str(const Idx& rIndex) const;


 protected:

  /** Pointer to local SymbolTable */
  SymbolTable* mpSymbolTable;

  /**
   * Assign from other name set. Performs a fake copy, see TBaseSet.
   *
   * @param rSourceSet
   *   Source to copy from
   * @return
   *   ref to this set
   */
  void DoAssign(const NameSet& rSourceSet);


  /**
   * Test equality of configuration data.
   * Ignore name of the set, insist in matching symboltables.
   *
   * @param rOtherSet 
   *    Other object to compare with.
   * @return 
   *   True on match.
   */
  bool DoEqual(const NameSet& rOtherSet) const;

  /**
   * Write to TokenWriter, see Type::Write for public wrappers
   * This function will also do the token IO of attributes in derived classes.
   *
   * @param tw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of the section to write, defaults to name of set or "NameSet"
   * @param pContext
   *   Write context to provide contextual information
   *
   * @exception Exception
   *   - IO errors (id 2)
   */
  virtual void DoWrite(TokenWriter& tw, const std::string& rLabel="", const Type* pContext=0) const;
        
  /** Write debug info to TokenWriter, see Type::DWrite for public wrapper.
   * The debug version writes a format that includes symbolic names and indices. 
   *
   * @param tw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of the section to write, defaults to name of set or "NameSet"
   * @param pContext
   *   Write context to provide contextual information
   *
   * @exception Exception 
   *   - IO errors (id 2)
   */
  virtual void DoDWrite(TokenWriter& tw, const std::string& rLabel="", const Type* pContext=0) const;

  /**
   * Write to TokenWriter XML format, see Type::XWrite for public wrappers
   * This function will also do the token IO of attributes in derived classes.
   *
   * @param tw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of the section to write, defaults to name of set or "NameSet"
   * @param pContext
   *   Write context to provide contextual information
   *
   * @exception Exception
   *   - IO errors (id 2)
   */
  virtual void DoXWrite(TokenWriter& tw, const std::string& rLabel="", const Type* pContext=0) const;
        
  /**
   * Read from TokenReader, see Type::Read for public wrappers. 
   * It is an error if the file contains a plain index (id 52).
   * The method invokes TokenReader::ReadBegin() to seek the specified
   * section, reads subsequent symbols, and calls matching TokenReader::ReadEnd(). 
   * If no section is specified, the section is assumed to start at the current position
   * of the token stream. If the current position is no begin token, 
   * the section "NameSet" is read.
   * When used by a derived class with attributes, attributes are read, too. 
   *
   * @param tr
   *   Reference to TokenReader
   * @param rLabel
   *   Label to read, defaults to current begin label or else "NameSet"
   * @param pContext
   *   Write context to provide contextual information
   *
   * @exception Exception
   *   - IO errors (id 1)
   *   - token mismatch (id 50, 51, 52)
   */
  virtual void DoRead(TokenReader& tr, const std::string& rLabel = "", const Type* pContext=0);


};


/** 
 * Convenience typedef for plain event sets
 *
 * @ingroup ContainerClasses
 */
typedef  NameSet EventSet;  

/* convenience typedef for eventset vectors*/
typedef  TBaseVector<EventSet> EventSetVector; 

/* RTI convenience function */
extern FAUDES_API void SetIntersection(const EventSetVector& rSetVector, EventSet& rRes);
extern FAUDES_API void SetUnion(const EventSetVector& rSetVector, EventSet& rRes);



/**
 * Set of indices with symbolic names and attributes. 
 *
 * This class is derived from NameSet and the interface  TAttrMap.
 *
 * The file format is demonstrated by the following example
 * of a set "Alphabet" consisting of events "alpha", "beta" and "gamma"
 * with "gamma" having some attribute (see eg AtributeFlags)
 * \code
 * <Alphabet> 
 * "alpha" 
 * "beta" 
 * "gamma" 0x0f
 * <\Alphabet> 
 * \endcode
 * As with TBAseSet, reading a file silently ignores unknown attributes. Thus, the above example
 * may also be read as NameSet.
 */



template<class Attr>
class FAUDES_API TaNameSet : public NameSet, public TAttrMap<Idx,Attr> {

FAUDES_TYPE_TDECLARATION(Void,TaNameSet,NameSet)

  /** 
   * We implement "protected privacy for template classes" by friendship.
   * This is used for the pragmatic implemention conversion constructors.
   */
  friend class NameSet;


 public:
  /**
   * Constructor for NameSet referring to the static SymbolTable. 
   */
  TaNameSet(void);
         
  /**
   * Copy-constructor from other TaNameSet (incl attributes and symboltable) 
   *
   * @param rOtherSet
   *   Set to copy
   */
  TaNameSet(const TaNameSet& rOtherSet);

  /**
   * Constructor from NameSet (sets default attributes, same symboltable) 
   *
   * @param rOtherSet
   *   Set to copy
   */
  TaNameSet(const NameSet& rOtherSet);

  /**
   * Constructor from file.
   * This constructor reads a NameSet from a file using the DoRead(TokenReader&, const std::String&)
   * function. The section is specified by rLabel and the static SymbolTable is used.
   *
   * @param rFilename
   *   Name of File
   * @param rLabel
   *   Section for the set in the file; 
   */
  TaNameSet(const std::string& rFilename, const std::string& rLabel = "");

  /**
   * Virtual destructor
   */
  virtual ~TaNameSet(void) {};

  /** Relaxed assignment method (uses base class to maintain attributes)
   *
   * Runtimetype check for TransSet, maintains attributes provided they can be casted.
   *
   * @param rSrc 
   *    Source from which to assign
   * @return
   *    Ref to this set
   */
  virtual TaNameSet& Assign(const TBaseSet<Idx>& rSrc);

  /** Relaxed assignment operator 
(uses base class to maintain attributes)
   *
   * @param rSrc 
   *    Source from which to assign
   * @return
   *    Ref to this set
   */
  virtual TaNameSet& operator=(const NameSet& rSrc) { return Assign(rSrc); };

  /** 
   * Iterators on nameset. 
   */
  using NameSet::Iterator;

  /**
   * Add an element by index. 
   * Index must be already known to the global SymbolTable. If the element already
   * exists in the set, the attribute is maintained. Otherwise, the element
   * is inserted with default attribute.
   *
   * @param rIndex
   *   Index to add
   * @return 
   *   True, if element was new to set
   * @exception Exception
   *   - no symbolic name for index (id 65)
   */
  virtual bool Insert(const Idx& rIndex);


  /**
   * Add an element by index incl. attribute 
   *
   * @param rIndex
   *   Index to add
   * @param rAttr
   *   Attribute to add
   * @return 
   *   True, if index was new to set
   * @exception Exception
   *   - no symbolic name for index (id 65)
   *
   */
  virtual bool Insert(const Idx& rIndex, const Attr& rAttr);

  /** 
   * Add an element by its  symbolic name. If the name is unknown, 
   * a new index will be generated and recorded in the symboltable.
   * If the name is known, the corresponding index will be added to the set.
   * If the element already exists in the set, the attribute is maintained. 
   * Otherwise, the element is inserted with default attribute.
   *
   * @param rName
   *   symbolic name of element to add
   *
   * @return 
   *   Index of (new) element
   */
  virtual Idx Insert(const std::string& rName);

  /** 
   * Add an element by its symbolic name.
   * If the name is unknown, 
   * a new index will be generated and recorded in the symboltable.
   * If the name is known, the corresponding index will be added to the set.
   *
   * @param rName
   *   symbolic name of element to add
   * @param rAttr
   *   Attribute
   *
   * @return 
   *   Index of (new) element
   */
  virtual Idx Insert(const std::string& rName, const Attr& rAttr);

  /**
   * Inserts elements of rOtherSet.
   *
   * Attributes of this set are maintained, newly inserted elements obtain the attribute
   * from rOtherSet provided they can be casted appropriately.
   *
   * @param rOtherSet
   *   Other StateSet
   * @exception Exception 
   *   - symboltable mismatch (id 67)
   */
  virtual void InsertSet(const NameSet& rOtherSet);

  /**
   * Inserts all elements of rOtherSet.
   *
   * This variant requires a runtime cast to access the synboltable.
   * An expection is thrown if the cast fails.
   *
   * @param rOtherSet
   *   Other NameSet
   * @exception Exception
   *   - symboltable mismatch (id 67) 
   *   - cast to nameset failed (id 67) 
   */
  virtual void InsertSet(const TBaseSet<Idx>& rOtherSet);

  /**
   * Delete element by index. Symbolic name is not removed from SymbolTable.
   *
   * @param rIndex
   *   Index to delete
   * @return
   *   True if element did exist
   * 
   */
  virtual bool Erase(const Idx& rIndex);

  /**
   * Delete element by symbolic name. Symbolic name is not removed from SymbolTable
   *
   * @param rName
   *   Symbolic name of element to dlete
   * @return
   *    True if element did exist
   * @exception Exception 
   *   - name not found in Symboltable (id 66)
   */
  virtual bool Erase(const std::string& rName);

  /**
   * Delete element by iterator. Symbolic name is not removed from SymbolTable.
   *
   * @param pos
   *   TaNameSet::iterator
   * @return
   *   Iterator to next element
   * @exception Exception 
   *   - invalid iterator (id 62)
   */
  virtual typename NameSet::Iterator Erase(const Iterator& pos);

  /**
   * Erase elements indicated by rOtherSet
   *
   * @exception Exception 
   *   - symboltable mismatch (id 67)
   *
   * @param rOtherSet
   *   Other StateSet
   */
  virtual void EraseSet(const NameSet& rOtherSet);

  /**
   * Erase elements specified by rOtherSet
   *
   * This function requires a runtime cast to access the synboltable.
   * An expection is thrown if the cast fails.
   *
   * @param rOtherSet
   *   Other NameSet
   * @exception Exception
   *   - symboltable mismatch (id 67) 
   *   - cast to nameset failed (id 67) 
   */
  virtual void EraseSet(const TBaseSet<Idx>& rOtherSet);

  /**
   * Restrict elements indicated by rOtherSet
   *
   * @exception Exception 
   *   - symboltable mismatch (id 67)
   *
   * @param rOtherSet
   *   Other EventSet
   */
  virtual void RestrictSet(const NameSet& rOtherSet);

  /**
   * Restrict to elements specified by rOtherSet
   *
   * This function requires a runtime cast to access the synboltable.
   * An expection is thrown if the cast fails.
   *
   * @param rOtherSet
   *   Other NameSet
   * @exception Exception
   *   - symboltable mismatch (id 67) 
   *   - cast to nameset failed (id 67) 
   */
  virtual void RestrictSet(const TBaseSet<Idx>& rOtherSet);

  /**
   * Set attributes. Provided that rOtherSet has attributes that can be
   * casted to the appropriate type, attributes are copied per element from rOtherSet. 
   * Elements of this set which are not in rOtherSet maintain their attribute. 
   *
   * @param rOtherSet
   *   Other IndexSet
   * @exception Exception
   *   - Element does not exist (63)
   *   - Cannot cast attribute type (63)
   *   - Cannot cast to NameSet (63)
   */
   virtual void Attributes(const TBaseSet<Idx>& rOtherSet);


  /**
   * Return pretty printable symbolic name for index.
   * Primary meant for debugging messages.
   *
   * @param rIndex
   *   Index to print
   *
   * @return
   *   String
   */
  std::string Str(const Idx& rIndex) const;

  /** resolve ambiguities from attribute interface ("using" wont do the job)*/
  const Attr* AttributeType(void) const { return TAttrMap<Idx,Attr>::AttributeType(); };
  Attr* Attributep(const Idx& rElem) { return TAttrMap<Idx,Attr>::Attributep(rElem); };
  const Attr& Attribute(const Idx& rElem) const { return TAttrMap<Idx,Attr>::Attribute(rElem); };
  void Attribute(const Idx& rElem, const Attr& rAttr) { return TAttrMap<Idx,Attr>::Attribute(rElem,rAttr); };
  void Attribute(const Idx& rElem, const Type& rAttr) { return TAttrMap<Idx,Attr>::Attribute(rElem,rAttr); };
  void AttributeTry(const Idx& rElem, const Type& rAttr) { return TAttrMap<Idx,Attr>::AttributeTry(rElem,rAttr); };


 protected:

  /**
   * Assign to other name set. Performs a fake copy, see TBaseSet.
   * This function maintains attributes.
   *
   * @param rSourceSet
   *   Destination to copy from
   * @return
   *   ref to this set
   */
  void DoAssign(const TaNameSet& rSourceSet);

  /**
   * Test equality of configuration data, ignore attributes
   * Ignore name of the set, insist in matching symboltables.
   *
   * @param rOtherSet 
   *    Other object to compare with.
   * @return 
   *   True on match.
   */
  bool DoEqual(const NameSet& rOtherSet) const;



};


/** Convenience Macro */
#define TaEventSet TaNameSet  

/** @} doxygen group */

/*
*************************************************************************************
*************************************************************************************
 Implementation
*************************************************************************************
*************************************************************************************
*/


// std faudes type (cannot do New() with macro)
FAUDES_TYPE_TIMPLEMENTATION_COPY(Void,TaNameSet<Attr>,NameSet,template<class Attr>)
FAUDES_TYPE_TIMPLEMENTATION_CAST(Void,TaNameSet<Attr>,NameSet,template<class Attr>)
FAUDES_TYPE_TIMPLEMENTATION_ASSIGN(Void,TaNameSet<Attr>,NameSet,template<class Attr>)
FAUDES_TYPE_TIMPLEMENTATION_EQUAL(Void,TaNameSet<Attr>,NameSet,template<class Attr>)

// empty constructor 
template<class Attr>
TaNameSet<Attr>::TaNameSet(void) :
  NameSet(),
  TAttrMap<Idx,Attr>(this)
{
  FD_DC("TaNameSet(" << this << ")::TaNameSet()");
  //mpSymbolTable = SymbolTable::GlobalEventSymbolTablep();
  this->Name("NameSet");
}

// constructor form other nameset
template<class Attr>
TaNameSet<Attr>::TaNameSet(const TaNameSet& rOtherSet) :
  NameSet(),
  TAttrMap<Idx,Attr>(this)
{
  FD_DC("TaNameSet(" << this << ")::TaNameSet(rOtherSet " << &rOtherSet << ")");
  DoAssign(rOtherSet);
}

// constructor form other nameset
template<class Attr>
TaNameSet<Attr>::TaNameSet(const NameSet& rOtherSet) :
  NameSet(),
  TAttrMap<Idx,Attr>(this)
{
  FD_DC("TaNameSet(" << this << ")::TaNameSet(rOtherSet " << &rOtherSet << ")");
  Assign(rOtherSet);
}


// read file constructor
template<class Attr>
TaNameSet<Attr>::TaNameSet(const std::string& rFilename, const std::string& rLabel) :
  NameSet(),
  TAttrMap<Idx,Attr>(this)
{
  FD_DC("TaNameSet(" << this << ")::TaNameSet(" << rFilename << ")");
  mpSymbolTable = SymbolTable::GlobalEventSymbolTablep();
  Read(rFilename, rLabel);
}

// New() (std faudes type, cannot use macro because we need to fix symboltable)
template<class Attr>
TaNameSet<Attr>* TaNameSet<Attr>::New(void) const {
  TaNameSet* res = new TaNameSet();
  res->mpSymbolTable=mpSymbolTable;
  return res;
}

// DoAssign()
template<class Attr>
void TaNameSet<Attr>::DoAssign(const TaNameSet<Attr>& rSourceSet) {
  FD_DC("TaNameSet(" << this << ")::DoAssign( [a] " << &rSourceSet << ")");
  // base does the job
  NameSet::DoAssign(rSourceSet);
}

// DoEqual()
template<class Attr>
bool TaNameSet<Attr>::DoEqual(const NameSet& rOtherSet) const {
  FD_DC("TaNAMESet::DoEqual()");
  // base does the job, equality does not refer to attributes
  return NameSet::DoEqual(rOtherSet);
}

// Relaxed Assign()
template<class Attr>
TaNameSet<Attr>& TaNameSet<Attr>::Assign(const TBaseSet<Idx>& rSourceSet) {
  FD_DC("TaNameSet(" << this << ")::Assign( [v] " << &rSourceSet << ")");
  const NameSet* nset = dynamic_cast<const NameSet*>(&rSourceSet);
#ifdef FAUDES_CHECKED
  if(!nset) {
    std::stringstream errstr;
    errstr << "cannot cast to nameset" << std::endl;
    throw Exception("TaNameSet::Assign", errstr.str(), 67);
  }
#endif
  // name set specific data
  mpSymbolTable=nset->mpSymbolTable;
  // attribute interface does relaxed assignment
  TAttrMap<Idx,Attr>::AssignWithAttributes(rSourceSet);
  // done
  return *this;
}

// Insert(index)
template<class Attr>
bool TaNameSet<Attr>::Insert(const Idx& rIndex) { 
#ifdef FAUDES_CHECKED
  if(!mpSymbolTable->Exists(rIndex)) {
    std::stringstream errstr;
    errstr << "index " << rIndex << " has no symbolic name" << std::endl;
    throw Exception("TaNameSet::Insert", errstr.str(), 65);
  }
#endif
  return TAttrMap<Idx,Attr>::Insert(rIndex);
}

        
// Insert(index,attr)
template<class Attr>
bool TaNameSet<Attr>::Insert(const Idx& rIndex, const Attr& attr) { 
#ifdef FAUDES_CHECKED
  if(!mpSymbolTable->Exists(rIndex)) {
    std::stringstream errstr;
    errstr << "index " << rIndex << " has no symbolic name" << std::endl;
    throw Exception("TaNameSet::Insert", errstr.str(), 65);
  }
#endif
  return TAttrMap<Idx,Attr>::Insert(rIndex,attr);
}

        
// Insert(rName)
template<class Attr>
Idx TaNameSet<Attr>::Insert(const std::string& rName) {
  FD_DC("TaNameSet(" << this << ")::Insert(" << rName <<")");
  Idx index= NameSet::Insert(rName); // automatic: keep attribute if exists
  return index;
}

// Insert(rName, attr)
template<class Attr>
Idx TaNameSet<Attr>::Insert(const std::string& rName, const Attr& attr) {
  FD_DC("TaNameSet(" << this << ")::Insert(" << rName <<")");
  Idx index= NameSet::Insert(rName);
  TAttrMap<Idx,Attr>::Attribute(index,attr);
  return index;
}

// InsertSet(set)
template<class Attr>
void TaNameSet<Attr>::InsertSet(const NameSet& rOtherSet) {
  FD_DC("TaNameSet(" << this << ")::InsertSet(" << &rOtherSet << ")");
#ifdef FAUDES_CHECKED
  if(rOtherSet.mpSymbolTable!=mpSymbolTable) {
    std::stringstream errstr;
    errstr << "symboltable mismach aka not implemented" << std::endl;
    throw Exception("TaNameSet::InsertSet", errstr.str(), 67);
  }
#endif
  TAttrMap<Idx,Attr>::InsertSet(rOtherSet);
}

// InsertSet(set)
template<class Attr>
void TaNameSet<Attr>::InsertSet(const TBaseSet<Idx>& rOtherSet) {
  FD_DC("TaNameSet(" << this << ")::InsertSet(" << &rOtherSet << "):: downcast");
#ifdef FAUDES_CHECKED
  const NameSet* nset = dynamic_cast<const NameSet*>(&rOtherSet);
  if(!nset) {
    std::stringstream errstr;
    errstr << "cannot cast to nameset" << std::endl;
    throw Exception("TaNameSet::InsertSet", errstr.str(), 67);
  }
  if(nset->mpSymbolTable!=mpSymbolTable) {
    std::stringstream errstr;
    errstr << "symboltable mismatch aka not implemented" << std::endl;
    throw Exception("TaNameSet::InsertSet", errstr.str(), 67);
  }
#endif
  TAttrMap<Idx,Attr>::InsertSet(rOtherSet);
}
		
// Erase(index)
template<class Attr>
bool TaNameSet<Attr>::Erase(const Idx& rIndex) {
  FD_DC("TaNameSet(" << this << ")::Erase(" << rIndex <<")");
  return TAttrMap<Idx,Attr>::Erase(rIndex);
}

// Erase(rName)
template<class Attr>
bool TaNameSet<Attr>::Erase(const std::string& rName) {
  FD_DC("TaNameSet(" << this << ")::Erase(" << rName <<")");
  Idx index = mpSymbolTable->Index(rName);
#ifdef FAUDES_CHECKED
  if (index == 0) {
    std::stringstream errstr;
    errstr << "name \"" << rName << "\" not found in TaNameSet" << std::endl;
    throw Exception("TaNameSet::Erase", errstr.str(), 60);
  }
#endif
  return TAttrMap<Idx,Attr>::Erase(index);
}

// Erase(pos)
template<class Attr>
typename NameSet::Iterator TaNameSet<Attr>::Erase(const Iterator& pos) {
  return TAttrMap<Idx,Attr>::Erase(pos);
}

// EraseSet(set)
template<class Attr>
void TaNameSet<Attr>::EraseSet(const NameSet& rOtherSet) {
  FD_DC("TaNameSet(" << this << ")::EraseSet(" << rOtherSet.ToString() << ")");
#ifdef FAUDES_CHECKED
  if(rOtherSet.mpSymbolTable!=mpSymbolTable) {
    std::stringstream errstr;
    errstr << "symboltable mismach aka not implemented" << std::endl;
    throw Exception("TaNameSet::EraseSet", errstr.str(), 67);
  }
#endif
  TAttrMap<Idx,Attr>::EraseSet(rOtherSet);
}

		
// EraseSet(set)
template<class Attr>
void TaNameSet<Attr>::EraseSet(const TBaseSet<Idx>& rOtherSet) {
#ifdef FAUDES_CHECKED
  const NameSet* nset = dynamic_cast<const NameSet*>(&rOtherSet);
  if(!nset) {
    std::stringstream errstr;
    errstr << "cannot cast to nameset" << std::endl;
    throw Exception("TaNameSet::EraseSet", errstr.str(), 67);
  }
  if(nset->mpSymbolTable!=mpSymbolTable) {
    std::stringstream errstr;
    errstr << "symboltable mismatch aka not implemented" << std::endl;
    throw Exception("TaNameSet::EraseSet", errstr.str(), 67);
  }
#endif
  TAttrMap<Idx,Attr>::EraseSet(rOtherSet);
}


// RestrictSet(set)
template<class Attr>
void TaNameSet<Attr>::RestrictSet(const NameSet& rOtherSet) {
  FD_DC("TaNameSet(" << this << ")::RestrictSet(" << rOtherSet.ToString() << ")");
#ifdef FAUDES_CHECKED
  if(rOtherSet.mpSymbolTable!=mpSymbolTable) {
    std::stringstream errstr;
    errstr << "symboltable mismach aka not implemented" << std::endl;
    throw Exception("TaNameSet::RestrictSet", errstr.str(), 67);
  }
#endif
  TAttrMap<Idx,Attr>::RestrictSet(rOtherSet);
}

// RestrictSet(set)
template<class Attr>
void TaNameSet<Attr>::RestrictSet(const TBaseSet<Idx>& rOtherSet) {
#ifdef FAUDES_CHECKED
  const NameSet* nset = dynamic_cast<const NameSet*>(&rOtherSet);
  if(!nset) {
    std::stringstream errstr;
    errstr << "cannot cast to nameset" << std::endl;
    throw Exception("TaNameSet::EraseSet", errstr.str(), 67);
  }
  if(nset->mpSymbolTable!=mpSymbolTable) {
    std::stringstream errstr;
    errstr << "symboltable mismatch aka not implemented" << std::endl;
    throw Exception("TaNameSet::EraseSet", errstr.str(), 67);
  }
#endif
  TAttrMap<Idx,Attr>::RestrictSet(rOtherSet);
}

		
// Attributes(set)
template<class Attr>
void TaNameSet<Attr>::Attributes(const TBaseSet<Idx>& rOtherSet) {
  FD_DC("TaNameSet(" << this << ")::Attributes(otherset) with type " << typeid(*rOtherSet.AttributeType()).name());
#ifdef FAUDES_CHECKED
  const NameSet* nset = dynamic_cast<const NameSet*>(&rOtherSet);
  if(!nset) {
    std::stringstream errstr;
    errstr << "cannot cast to nameset" << std::endl;
    throw Exception("TaNameSet::Attributes(otherset)", errstr.str(), 67);
  }
  if(nset->mpSymbolTable!=mpSymbolTable) {
    std::stringstream errstr;
    errstr << "symboltable mismatch aka not implemented" << std::endl;
    throw Exception("TaNameSet::Attributes(otherset)", errstr.str(), 67);
  }
#endif
  TBaseSet<Idx>::Attributes(rOtherSet);
}


// Str()
template<class Attr>
std::string TaNameSet<Attr>::Str(const Idx& rIndex) const {
  return NameSet::Str(rIndex);
}



} // namespace faudes

#endif 

