/** @file cfl_indexset.h @brief Classes IndexSet, TaIndexSet */


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



#ifndef FAUDES_INDEXSET_H
#define FAUDES_INDEXSET_H

#include "cfl_definitions.h"
#include "cfl_exception.h"
#include "cfl_attrmap.h"
#include "cfl_symboltable.h"
#include "cfl_registry.h"
#include "cfl_basevector.h"
#include <algorithm>


namespace faudes {



/** @addtogroup ContainerClasses */
/** @{*/

// Forward declaration for the attributed version of indexset
template<class Attr> class TaIndexSet;

/**
 * Set of indices. This class is built on top of the faudes version
 * TBaseSet of STL sets. It provides the essentials of the STL interface
 * and inherits the standard token IO interface from Type, so you may 
 * use Read and Write for file/string/console IO.
 *
 * IndexSet is used as common base for TaIndexSet (indices with attributes),
 * NameSet (indices with symbolic names) and TaNameSet (indices with
 * attributes and symbolic names).
 *
 * The index of value 0 is reserved to indicate the invalid index. If the macro FAUDES_CHECKED
 * is defined, the attempt to insert an index 0 triggers an exception (id 61). Invalid
 * iterators throw an exception (id 62) when used as an argument to a IndexSet function. 
 *
 * Technically, file IO is done by TaIndexSet functions. This requires a copy and for
 * that reason may be reimplemented in a future versions.
 * The format is demonstrated by the following example
 * of a set with name "MySet" consisting of indices 17, 25, 26, 27, 28, 40:
 * \code
 * <Myset> 
 * 17 
 * <Consecutive> 25 4 </Consecutive> 
 * 40 
 * </MySet>  
 * \endcode
 * Theere is a minimum number of consecutive indices for the use of the consecutive
 * section defined in definitions.h.
 *
 */

class FAUDES_API IndexSet : public TBaseSet<Idx> {

FAUDES_TYPE_DECLARATION(IndexSet,IndexSet,TBaseSet<Idx>)

public:

  /** 
   * We implement "protected privacy for template classes" by friendship.
   * This is used for the pragmatic implemention conversion constructors.
   */
  template<class Attr> friend class TaIndexSet;


  /**
   * Constructor. 
   */
  IndexSet(void);

  /**
   * Copy-constructor. 
   */
  IndexSet(const IndexSet& rOtherSet);

  /**
   * Copy-constructor. 
   */
  IndexSet(const TBaseSet<Idx>& rOtherSet);

  /**
   * Construct from file. Uses the Read(TokenReader&, const std::string&) function to read.
   * a IndexSet from section rLabel in file rFilename.
   *
   * @param rFilename
   *   Name of file to read
   * @param rLabel
   *   Section to read
   *
   * @exception Exception
   *   - IO Errors (id 1)
   *   - Token mismatch (id 50, 51, 52)
   */
  IndexSet(const std::string& rFilename, const std::string& rLabel = "");

  /**
   * Virtual destructor
   */
  virtual ~IndexSet(void) {};

  /**
   * Get maximum index used in this set (0 for emptyset)
   *
   * @return 
   *   max  indices 
   */
  Idx MaxIndex(void) const;

  /**
   * Test whether index is not 0
   * @param rIndex
   *    Index to test
   * @return
   *    True if idx!=0
   */
   bool Valid(const Idx& rIndex) const;
   
  /** 
   * Iterators on indexset. 
   */
  using TBaseSet<Idx>::Iterator;

  /**
   * Insert new index to set
   *
   * @return
   *   New index 
   */
  Idx Insert(void);

  /** 
   * Insert specified index
   *
   * @param rIndex
   *    Index to insert
   * @return
   *   True if index was new to set 
   */
  bool Insert(const Idx& rIndex);

  /**
   * Compute an Idx type signature for a Set. The value is computed by 
   * summing up the product of every index with an integer starting at
   * 1 (for the first index) and ending at Size() (for the last index).
   *
   * @return
   *   Idx type set signature
   */
  Idx Signature(void) const;

  /**
   * Return pretty printable index. 
   *
   * @param rIndex
   *   Index to print
   *
   * @return
   *   String
   */
  std::string Str(const Idx& rIndex) const {return ToStringInteger(rIndex); };

 protected:

  /**
   * Assign my members. This method maintains attributes
   * provided that the type can be appropriately casted.
   *
   * @param rSource 
   *    Source to copy from
   * @return
   *    Ref to this set
   */
  void DoAssign(const IndexSet& rSource);

  /** 
   * Write to TokenWriter, see Type::Write for public wrappers.
   * Appends the IndexSet to 
   * TokenWriter. This will write a section with label as specified that holds
   * integer tokens to represent the IndexSet. For non-default attribute values,
   * the respective index is followed by the attribute value. The latter may 
   * consist of sections (or tokens different from integer or string) to allow
   * for transparent reading; see AttributeVoid and AttributeFlags. Example for
   * a set with name "MySet" consisting of indices 17, 25, 40, where index 25 has a
   * nontrivial attribute attached:
   * \code
   * <Myset> 
   * 17 
   * 25 <AValue> "Some Value" </AValue> 
   * 40 
   * </MySet>  
   * \endcode
   *
   * @param tw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of section to write, defaults to name of set or "IndexSet"
   * @param pContext
   *   Write context to provide contextual information
   *
   * @exception Exception
   *   - IO errors (id 2)
   */
  virtual void DoWrite(TokenWriter& tw, const std::string& rLabel="", const Type* pContext=0) const;

  /** 
   * Write to TokenWriter, see Type::Write for public wrappers. Appends the IndexSet to 
   * TokenWriter using XML format. 
   *
   * @param tw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of section to write, defaults to name of set or "IndexSet"
   * @param pContext
   *   Write context to provide contextual information
   *
   * @exception Exception
   *   - IO errors (id 2)
   */
  virtual void DoXWrite(TokenWriter& tw, const std::string& rLabel="", const Type* pContext=0) const;

  /**
   * Read from TokenReader, see Type::Read for public wrappers. 
   * This method invokes TokenReader::ReadBegin() to seek the specified
   * section, reads subsequent integer tokens as indexes, and calls matching TokenReader::ReadEnd(). 
   * If no section is specified, the section is assumed to start at the current position
   * of the token stream. If the current position is no begin token, 
   * the section "IndexSet" is read.
   * When used by a derived class with attributes, attributes are read, too. 
   *
   * @param rTr
   *   Reference to tokenreader
   * @param rLabel
   *   Section to read, defaults to current begin label or else "IndexSet"
   * @param pContext
   *   Read context to provide contextual information
   *
   * @exception Exception
   *   - IO errors (id 1)
   *   - token mismatch (id 50, 51, 52)
   */
  virtual void DoRead(TokenReader& rTr, const std::string& rLabel="", const Type* pContext=0);

};

/* convenience typedef for stateset */
typedef IndexSet StateSet;


/** 
 * Convenience typedef for vectors og generators
 * \ingroup GeneratorClasses
 */
typedef  TBaseVector<IndexSet> IndexSetVector;  


/**
 * Set of indices with attributes. A TaIndexSet<Attr> is a template derived from IndexSet,
 * such that  each set element has an Attribute of class Attr.
 * The template parameter Attr must provide basic functions for file IO and must define a default
 * value, see AttributeVoid and AttributeFlags for an examples.
 * Attributes are maintained by an STL map to associate indices
 * with attributes different from the default value. Thus, attributes with default value 
 * do not take up any memeory.
 *
 * @param mAttributeMap
 *   STL map of type std::map<Idx,Attr> to hold attributes
 *
 * The copy constructor copies attributes; the methods InsertSet(), EraseSet() and
 * RestrictSet() maintain attributes; all other set operations derived from IndexSet  
 * either return a IndexSet (no attributes) or set all attributes to the dafault value.
 * To set or get an attribute of an index that does not exist in the set is considered
 * as an error and triggers an exception (id 60) when the macro FAUDES_CHECKED is defined. 
 *
 * The format for token IO is demonstrated by the following example
 * of a set with name "MySet" consisting of indices 17, 25, 40, where index 25 has a
 * nontrivial attribute attached:
 * \code
 * <Myset> 
 * 17 
 * 25 <AValue> "Some Value" </AValue> 
 * 40 
 * </MySet>  
 * \endcode
 * Note that attributes may be either subsections or tokens of type different from integer and string.
 * This is to allow reading a token stream to a class with incompatible (or no) attributes. 
 */



template<class Attr>
class FAUDES_API TaIndexSet : public IndexSet, public TAttrMap<Idx,Attr> {

FAUDES_TYPE_TDECLARATION(Void,TaIndexSet,IndexSet)

public:

  /** 
   * We implement "protected privacy for template classes" by friendship.
   * This is used for the pragmatic implemention conversion constructors.
   */
  friend class IndexSet;


  /**
   * Constructor. 
   */
  TaIndexSet(void);

  /**
   * Copy-constructor (from TaIndexSet, incl attributes) 
   */
  TaIndexSet(const TaIndexSet& rOtherSet);

  /**
   * Copy-constructor (from IndexSet, sets attributes to default) 
   */
  TaIndexSet(const IndexSet& rOtherSet);

  /**
   * Construct from file. 
   * This constructor uses the Read(TokenReader&, const std::string&) function to read.
   *
   * @param rFilename
   *   Name of file
   * @param rLabel
   *   Section for the set in file
   *
   * @exception Exception
   *   - IO errors (id 1)
   *   - token mismatch (id 50, 51, 52)
   */
  TaIndexSet(const std::string& rFilename, const std::string& rLabel = "");

  /**
   * Virtual destructor
   */
  virtual ~TaIndexSet(void) {};

  /** Relaxed assignment method. Maintain attributes provided they can be casted.
   *
   * @param rSrc 
   *    Source from which to assign
   * @return
   *    Ref to this set
   */
  virtual TaIndexSet& Assign(const TBaseSet<Idx>& rSrc);

  /** Relaxed assignment operator. Maintain attributes provided they can be casted.
   *
   * @param rSrc 
   *    Source from which to assign
   * @return
   *    Ref to this set
   */
  virtual TaIndexSet& operator=(const IndexSet& rSrc) { return Assign(rSrc); };

  /** 
   * Iterators on indexset. 
   */
  using IndexSet::Iterator;

  /**
   * Insert new index to set using default attribute.
   *
   * @return
   *   New index 
   */
  Idx Insert(void);

  /** 
   * Insert new index with attribute. 
   * If the index allready exists, the
   * attribute is overwritten by rAttr.
   *
   * @param rAttr
   *   Specify attribute of new element
   * @return
   *   new index 
   */
  Idx Insert(const Attr& rAttr);

  /** 
   * Insert element. If the element exists, the attribute is maintained.
   * If the element does not exist, it is inserted with default attribute.
   *
   * @param rIndex
   *   Index to specify element
   * @return
   *   True if element was new to set 
   */
  bool Insert(const Idx& rIndex);

  /** 
   * Insert element with attribute. 
   *
   * @param rIndex
   *   Index to specify element
   * @param attr
   *   Specify attribute of (new) element
   * @return
   *   True if element was new to set 
   */
  bool Insert(const Idx& rIndex, const Attr& attr);

  /**
   * Inserts elements of rOtherSet.
   *
   * Attributes of this set are maintained, newly inserted elements attain the
   * attribute from rOtherSet if it can be casted appropriately.
   *
   *
   * @param rOtherSet
   *   Other IndexSet
   */
   virtual void InsertSet(const IndexSet& rOtherSet);

  /**
   * Inserts elements of rOtherSet.
   *
   * This variant uses a runtime cast to access attributes.
   *
   * @param rOtherSet
   *     Other IndexSet
   * @exception Exception
   *   - cast failed (id 67)
   */
   virtual void InsertSet(const TBaseSet<Idx>& rOtherSet);


  /** 
   * Erase Element (incl its attribute) 
   *
   * @param rIndex
   *    Index to specify element
   * @return
   *    True if element used to exist
   */
  bool Erase(const Idx& rIndex);


  /** 
   * Erase element by iterator (incl attribute) 
   *
   * @param pos
   *    Iterator to specify element
   * @return 
   *    Iterator to next element or End()
   */
  IndexSet::Iterator Erase(const Iterator& pos); 


  /** 
   * Erase elements given by other set. 
   *
   * This function ignores the attributes of the other set 
   * and maintains the attributes of the remaining elements in this set.
   *
   * @param rOtherSet 
   *    Elements to erase
   */
   void EraseSet(const IndexSet& rOtherSet);

  /**
   * Erase elements given by other set. 
   *
   * This variant uses a runtime cast to access attributes.
   *
   * @param rOtherSet
   *     Other IndexSet
   * @exception Exception
   *   - cast failed (id 67)
   */
   virtual void EraseSet(const TBaseSet<Idx>& rOtherSet);

  /** 
   * Restrict to specified subset. 
   *
   * Erases any elements no in the specified set. This function
   * ignores the attributes of the other set and maintains the attributes 
   * of the remaining elements in this set.
   *
   * @param rOtherSet 
   *    Elements to erase
   */
   void RestrictSet(const IndexSet& rOtherSet);

  /**
   * Restrict to specified subset. 
   *
   * This variant uses a runtime cast to access attributes.
   *
   * @param rOtherSet
   *     Other IndexSet
   * @exception Exception
   *   - cast failed (id 67)
   */
   virtual void RestrictSet(const TBaseSet<Idx>& rOtherSet);


  /** resolve ambiguities from attribute interface ("using" wont do the job)*/
  const Attr* AttributeType(void) const { return TAttrMap<Idx,Attr>::AttributeType(); };
  Attr* Attributep(const Idx& rElem) { return TAttrMap<Idx,Attr>::Attributep(rElem); };
  const Attr& Attribute(const Idx& rElem) const { return TAttrMap<Idx,Attr>::Attribute(rElem); };
  void Attribute(const Idx& rElem, const Attr& rAttr) { return TAttrMap<Idx,Attr>::Attribute(rElem,rAttr); };
  void Attribute(const Idx& rElem, const Type& rAttr) { return TAttrMap<Idx,Attr>::Attribute(rElem,rAttr); };
  void AttributeTry(const Idx& rElem, const Type& rAttr) { return TAttrMap<Idx,Attr>::AttributeTry(rElem,rAttr); };
     
 
 protected:

  /**
   * Assign my members. This method maintains attributes.
   *
   * @param rSource 
   *    Source to copy from
   * @return
   *    Ref to this set
   */
  void DoAssign(const TaIndexSet& rSource);


};

/** Convenience Macro */
//template<class Attr> typedef TaStateSet<class Attr> TaIndexSet<class Attr>
#define TaStateSet TaIndexSet




/** @} doxygen group */


/*
*************************************************************************************
*************************************************************************************
 Implementation
*************************************************************************************
*************************************************************************************
*/


// std faudes type
FAUDES_TYPE_TIMPLEMENTATION(Void,TaIndexSet<Attr>,IndexSet,template<class Attr>)


// TaIndexSet()
template<class Attr>
TaIndexSet<Attr>::TaIndexSet(void) : 
  IndexSet(),
  TAttrMap<Idx,Attr>(this)
{
  FD_DC("TaIndexSet(" << this << ")::TaIndexSet()");
}

// TaIndexSet(rOtherSet)
template<class Attr>
TaIndexSet<Attr>::TaIndexSet(const TaIndexSet& rOtherSet) : 
  IndexSet(),
  TAttrMap<Idx,Attr>(this)
{
  FD_DC("TaIndexSet(" << this << ")::TaIndexSet(rOtherSet " << &rOtherSet << ")");
  // copy my members
  DoAssign(rOtherSet);
}

// TaIndexSet(rOtherSet)
template<class Attr>
TaIndexSet<Attr>::TaIndexSet(const IndexSet& rOtherSet) :
  IndexSet(),
  TAttrMap<Idx,Attr>(this)
{
  FD_DC("TaIndexSet(" << this << ")::TaIndexSet(rOtherSet " << &rOtherSet << ")");
  // copy my members
  Assign(rOtherSet);
}


// File constructor
template<class Attr>
  TaIndexSet<Attr>::TaIndexSet(const std::string& rFilename, const std::string& rLabel) :
  IndexSet(),
  TAttrMap<Idx,Attr>(this)
{
  FD_DC("TaIndexSet(" << this << ")::TaIndexSet(" << rFilename << ")");
  Read(rFilename, rLabel);
}


// DoAssign (attributes known and match)
template<class Attr>
void TaIndexSet<Attr>::DoAssign(const TaIndexSet<Attr>& rSourceSet) {
  FD_DC("TaIndexSet(" << this << ")::DoAssign( [a] " << &rSourceSet<<")");
  // call base incl attributes
  IndexSet::DoAssign(rSourceSet);
}  

// Relaxed Assign()
template<class Attr>
TaIndexSet<Attr>& TaIndexSet<Attr>::Assign(const TBaseSet<Idx>& rSourceSet) {
  FD_DC("TaIndexSet(" << this << ")::Assign([v] " << &rSourceSet<<")");
  FD_DC("TaIndexSet(" << this << ")::Assign(): src type " << typeid(rSourceSet).name());
  FD_DC("TaIndexSet(" << this << ")::Assign(): dst type " << typeid(*this).name());
#ifdef FAUDES_CHECKED
  const IndexSet* iset = dynamic_cast<const IndexSet*>(&rSourceSet);
  if(!iset) {
    std::stringstream errstr;
    errstr << "cannot cast to indexset" << std::endl;
    throw Exception("TaIndexSet::InsertSet", errstr.str(), 67);
  }
#endif
  // call attribute smart base
  TAttrMap<Idx,Attr>::AssignWithAttributes(rSourceSet);
  // done
  return *this;
}



// Insert()
template<class Attr>
Idx TaIndexSet<Attr>::Insert(void) {
  FD_DC("TaIndexSet(" << this << ")::Insert()");
  Idx index=MaxIndex()+1;
  TAttrMap<Idx,Attr>::Insert(index);
  return index;
}

//Insert(idx)
template<class Attr>
bool TaIndexSet<Attr>::Insert(const Idx& rIndex) {
  FD_DC("TaIndexSet(" << this << ")::Insert("<< rIndex <<")");
  return TAttrMap<Idx,Attr>::Insert(rIndex);
}

// Insert(attr)
template<class Attr>
Idx TaIndexSet<Attr>::Insert(const Attr& attr) {
  FD_DC("TaIndexSet(" << this << ")::Insert(" << attr.ToString() << ")");
  Idx index = Insert();
  if(!attr.IsDefault()) {
    TAttrMap<Idx,Attr>::Attribute(index,attr);
  }
  return index;
}

//Insert(idx,attr)
template<class Attr>
bool TaIndexSet<Attr>::Insert(const Idx& rIndex, const Attr& attr) {
  FD_DC("TaIndexSet(" << this << ")::Insert("<< rIndex <<",attr)");
  return TAttrMap<Idx,Attr>::Insert(rIndex,attr);
}


// InsertSet(set)
template<class Attr>
void TaIndexSet<Attr>::InsertSet(const IndexSet& rOtherSet) {
  FD_DC("TaIndexSet(" << this << ")::InsertSet(" << &rOtherSet << ")");
  TAttrMap<Idx,Attr>::InsertSet(rOtherSet);
}

//InsertSet(set)
template<class Attr>
void TaIndexSet<Attr>::InsertSet(const TBaseSet<Idx>& rOtherSet) {
#ifdef FAUDES_CHECKED
  FD_DC("TaIndexSet(" << this << ")::InsertSet(" << rOtherSet.ToString() << ")");
  const IndexSet* iset = dynamic_cast<const IndexSet*>(&rOtherSet);
  if(!iset) {
    std::stringstream errstr;
    errstr << "cannot cast to indexset" << std::endl;
    throw Exception("TaIndexSet::InsertSet", errstr.str(), 67);
  }
#endif
  TAttrMap<Idx,Attr>::InsertSet(rOtherSet);
}

//Erase(idx)
template<class Attr>
bool TaIndexSet<Attr>::Erase(const Idx& rIndex) {
  return TAttrMap<Idx,Attr>::Erase(rIndex);
}

//Erase(pos)
template<class Attr>
typename IndexSet::Iterator TaIndexSet<Attr>::Erase(const Iterator& pos) { 
  return TAttrMap<Idx,Attr>::Erase(pos);
}


//EraseSet(set)
template<class Attr>
void TaIndexSet<Attr>::EraseSet(const IndexSet& rOtherSet) {
  FD_DC("TaIndexSet(" << this << ")::EraseSet(" << rOtherSet.ToString() << ")");
  TAttrMap<Idx,Attr>::EraseSet(rOtherSet);
}

//EraseSet(set)
template<class Attr>
void TaIndexSet<Attr>::EraseSet(const TBaseSet<Idx>& rOtherSet) {
#ifdef FAUDES_CHECKED
  FD_DC("TaIndexSet(" << this << ")::EraseSet(" << rOtherSet.ToString() << ")");
  const IndexSet* iset = dynamic_cast<const IndexSet*>(&rOtherSet);
  if(!iset) {
    std::stringstream errstr;
    errstr << "cannot cast to indexset" << std::endl;
    throw Exception("TaIndexSet::EraseSet", errstr.str(), 67);
  }
#endif
  TAttrMap<Idx,Attr>::EraseSet(rOtherSet);
}

//RestrictSet(set)
template<class Attr>
void TaIndexSet<Attr>::RestrictSet(const IndexSet& rOtherSet) {
  FD_DC("TaIndexSet(" << this << ")::RestrictSet(" << rOtherSet.ToString() << ")");
  TAttrMap<Idx,Attr>::EraseSet(rOtherSet);
}

//RestrictSet(set)
template<class Attr>
void TaIndexSet<Attr>::RestrictSet(const TBaseSet<Idx>& rOtherSet) {
#ifdef FAUDES_CHECKED
  FD_DC("TaIndexSet(" << this << ")::RestrictSet(" << rOtherSet.ToString() << ")");
  const IndexSet* iset = dynamic_cast<const IndexSet*>(&rOtherSet);
  if(!iset) {
    std::stringstream errstr;
    errstr << "cannot cast to indexset" << std::endl;
    throw Exception("TaIndexSet::RestrictSet", errstr.str(), 67);
  }
#endif
  TAttrMap<Idx,Attr>::RestrictSet(rOtherSet);
}




} // namespace faudes



#endif 

