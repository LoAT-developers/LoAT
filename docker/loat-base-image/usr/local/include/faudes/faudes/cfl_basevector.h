/** @file cfl_basevector.h @brief Class TBaseVector */


/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2009  Thomas Moor

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



#ifndef FAUDES_BASEVECTOR_H
#define FAUDES_BASEVECTOR_H

#include "cfl_definitions.h"
#include "cfl_tokenwriter.h"
#include "cfl_tokenreader.h"
#include "cfl_types.h"
#include "cfl_attributes.h"
#include <vector>
#include <algorithm>

namespace faudes {

/** @addtogroup ContainerClasses */
/** @{*/

/**
 * Vector bass class.
 *
 * This class is designed as a random access container for a small number of 
 * comperatively large objects, eg a vector of generators to model a decentralized DES. 
 * The API is restricted to simple positional access and there are no explicit 
 * iterators nor is there a deferred copy mechanism. As with other faudes containers,
 * vBaseVector is the universal base class for all faudes vector data types. The latter
 * explicitely refer to the element data type and are implemented as templates.
 *
 * Internally, the vBaseVector template uses STL vector of pointers to the individual entries. 
 * When adding an entry, you may either do so be refernce or by pointer. When setting
 * by reference, the vector takes a copy and owns the new entry. When setting by a pointer,
 * the vector only records the reference. The vector tracks ownership of each entry in order
 * to properly destruct entries. 
 *
 * vBaseVector serves as a base class for all libFaudes vectors: 
 * - GeneratorVector (vector or generators) 
 * - EventSetVector (vector of event sets) 
 *
 * Token io assumes that the type parameter is a faudes type, ie. entries of the vector
 * provide token io themselfs. To derive a vector class with non-faudes-type entries,
 * you will need to reimplement token io. As a convenience feature, the vector keeps a record
 * of filenames associated with individual entries. You can inspect and edit this record via
 * the FilenameAt members. When writing the vector to a file and all entries have an associated filename,
 * output will be to the individual files.
 *
 */

class FAUDES_API vBaseVector : public Type {

FAUDES_TYPE_DECLARATION(Void,vBaseVector,Type)

public:

  /**
   * Constructor. 
   */
  vBaseVector(void);

  /**
   * Copy-constructor. 
   *
   * @param rOtherVector 
   *    Source to copy from
   */
  vBaseVector(const vBaseVector& rOtherVector);

  /**
   * Constructor from file.
   *
   * @param rFilename
   *   Name of File
   * @param rLabel
   *   Section for the set in the file; 
   */
  vBaseVector(const std::string& rFilename, const std::string& rLabel = "BaseVector");

  /**
   * Virtual destructor
   */
  virtual ~vBaseVector(void);

  /**
   * Prototype for vector entries.
   * The virtual base vBaseVector will provide a plain Type object.
   * Derived vector classes are meant to reimplement this function.
   * 
   * @return 
   *    Element protoype
   */
  virtual const Type* Elementp(void) const;


  /**
   * Prototype for vector entries.
   * This is a convenience wrapper for Elementp.
   *
   * @return 
   *    Element protoype
   */
  virtual const Type& Element(void) const;


  /**
   * Factory method for vector entries.
   * This is a convenience wrapper using Elementp.
   *
   * @return 
   *    New element allocated on heap
   */
  virtual Type* NewElement(void);

  /**
   * Test whether the specified element is acceptebla for this vector.
   * This is a convenience wrapper for Elementp.
   *
   * @param rElement
   *   Element to type check.
   * @return 
   *   True, if provided element is accepted by this vector.
   */
  virtual bool ElementTry(const Type& rElement) const;


  /** 
   * Return name of vBaseVector 
   * 
   * @return
   *   Name of vBaseVector
   */
  const std::string& Name(void) const;
        
  /**
   * Set name of vBaseVector
   *
   * @param rName
   *   Name to set
   */
  void Name(const std::string& rName);

  /** 
   * Clear all vector
   */
  virtual void Clear(void);
      
    /**
   * Get size of vector.
   *
   * @return 
   *   Number of entries.
   */
  Idx Size(void) const;

  /**
   * Set size of vector.
   * If the new size is smaller than the current size,
   * the vector is truncated. If it is larger, default members
   * are inserted at the end.
   *
   * @param len
   *   Number of entries in vector
   */
  void Size(Idx len);

  /** 
   * Check if the vBaseVector ist Empty 
   *
   * @return 
   *   True if empty
   */
  bool Empty(void) const;

  /**
   * convenience typedef for positions (must be unsigned)
   */
  typedef size_t Position;

  /** 
   * Access element.
   *
   * @param pos
   *    Specify entry to access
   * @exception Exception
   *   - Position out of range (id 69)
   */
  virtual const Type& At(const Position& pos) const; 

  /** 
   * Access element.
   *
   * @param pos
   *    Specify entry to access
   * @exception Exception
   *   - Position out of range (id 69)
   */
  virtual Type& At(const Position& pos); 


  /** 
   * Replace specified entry.
   * This method takes a copy of the entry to replace and the
   * vector becomes the owner of the copy.
   *
   * @param pos
   *    Position to replace
   * @param rElem
   *    New entry 
   * @exception Exception
   *   - Position out of range (id 69)
   *   - Cannot cast element type (63)
   */
  virtual void Replace(const Position& pos, const Type& rElem);

  /** 
   * Replace specified entry.
   * This method avoids to copy the entry to replace and only records the reference.
   * The vector does not take ownership of the new entry. I.e., when the vector is destroyed, or the
   * entry is deleted from the vector, the entry itself remains allocated.
   *
   * @param pos
   *    Position to replace
   * @param pElem
   *    New entry
   * @exception Exception
   *   - Position out of range (id 69)
   *   - Cannot cast element type (63)
   */
  virtual void Replace(const Position& pos, Type* pElem);

  /** 
   * Replace specified entry.
   * This method reads the sepcified entry from file and the
   * vector becomes the owner of the new entry.
   *
   * @param pos
   *    Position to replace
   * @param rFileName
   *    New entry to be read from file
   * @exception Exception
   *   - Position out of range (id 69)
   */
  virtual void Replace(const Position& pos, const std::string& rFileName);


  /** 
   * Erase entry by position. 
   * If the vector owns the entry, it will be destructed.
   *
   * @param pos
   *    Specify entry to erase
   * @exception Exception
   *   - Position out of range (id 69)
   */
  virtual void Erase(const Position& pos); 

  /** 
   * Insert specified entry.
   * This method takes a copy of the entry to replace and the
   * vector becomes the owner of the copy.
   *
   * @param pos
   *    Position at which to insert
   * @param rElem
   *    Element to insert
   * @exception Exception
   *   - Position out of range (id 69)
   *   - Cannot cast element type (63)
   */
  virtual void Insert(const Position& pos, const Type& rElem);

  /** 
   * Insert specified entry.
   * This method avoids to copy the entry to replace and only records the reference.
   * The vector does not take ownership of the new entry. I.e., when the vector is destroyed, or the
   * entry is deleted from the vector, the entry itself remains allocated.
   *
   *
   * @param pos
   *    Position at which to insert
   * @param rElem
   *    Element to insert
   * @exception Exception
   *   - Position out of range (id 69)
   *   - Cannot cast element type (63)
   */
  virtual void Insert(const Position& pos, Type* rElem);

  /** 
   * Insert specified entry.
   * This method reads the sepcified entry from file and the
   * vector becomes the owner of the new entry.
   *
   * @param pos
   *    Position at which to insert
   * @param rFileName
   *    Element to insert
   * @exception Exception
   *   - Position out of range (id 69)
   */
  virtual void Insert(const Position& pos, const std::string& rFileName);

  /** 
   * Append specified entry.
   * This method takes a copy of the entry to replace and the
   * vector becomes the owner of the copy.
   *
   * @param rElem
   *    Element to append
   * @exception Exception
   *   - Cannot cast element type (63)
   */
  virtual void PushBack(const Type& rElem);

  /** 
   * Append specified entry.
   * This method avoids to copy the entry to replace and only records the reference.
   * The vector does not take ownership of the new entry. I.e., when the vector is destroyed, or the
   * entry is deleted from the vector, the entry itself remains allocated.
   *
   *
   * @param rElem
   *    Element to insert
   * @exception Exception
   *   - Cannot cast element type (63)
   */
  virtual void PushBack(Type* rElem);

  /** 
   * Append specified entry.
   * This method reads the sepcified entry from file and the
   * vector becomes the owner of the new entry.
   *
   * @param rFileName
   *    Element to insert
   */
  virtual void PushBack(const std::string& rFileName);

  /** 
   * Append specified entry.
   * Synonymous for PushBack.
   * This method takes a copy of the entry to replace and the
   * vector becomes the owner of the copy.
   *
   * @param rElem
   *    Element to append
   * @exception Exception
   *   - Cannot cast element type (63)
   */
  virtual void Append(const Type& rElem);

  /** 
   * Append specified entry.
   * Synonymous for PushBack.
   * This method avoids to copy the entry to replace and only records the reference.
   * The vector does not take ownership of the new entry. I.e., when the vector is destroyed, or the
   * entry is deleted from the vector, the entry itself remains allocated.
   *
   *
   * @param rElem
   *    Element to insert
   * @exception Exception
   *   - Cannot cast element type (63)
   */
  virtual void Append(Type* rElem);

  /** 
   * Append specified entry.
   * Synonymous for PushBack.
   * This method reads the sepcified entry from file and the
   * vector becomes the owner of the new entry.
   *
   * @param rFileName
   *    Element to insert
   */
  virtual void Append(const std::string& rFileName);

  /** 
   * Specify a filename.
   * When each entry has a filenam specified,
   * file io of the vector will be to indivudual files.
   *
   * @param pos
   *    Position of entry
   * @param rFileName
   *    Filename relative to vector file
   * @exception Exception
   *   - Position out of range (id 69)
   */
  void FilenameAt(const Position& pos, const std::string& rFileName);

  /** 
   * Get filename of entry.
   *
   * @param pos
   *    Position of entry
   * @return 
   *    Filename assoiated with entry
   * @exception Exception
   *   - Position out of range (id 69)
   */
  const std::string& FilenameAt(const Position& pos) const;

  /**
   * Take ownership of all entries.
   * Thsi method will take ownership of all entries, including those, that
   * have been set by pointer reference. When the vector is destructed, all
   * entries will be destructed, too. However, write access may invalidate 
   * element pointers.
   *
   */
  void TakeOwnership(void);

  /**
   * Take local copies of all entries.
   * This method will construct local copies of all entries not previously
   * owned. 
   */
  void TakeCopies(void);

protected:


  /** 
   * Token output, debugging see Type::DWrite for public wrappers.
   * The method assumes that the type parameter is a faudes type and uses
   * the provide write method per entry. Reimplement this function in derived 
   * classes for non-faudes type vectors.
   * @param rTw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of section to write, defaults to name of set
   * @param pContext
   *   Write context to provide contextual information
   */
  virtual void DoDWrite(TokenWriter& rTw,const std::string& rLabel="", const Type* pContext=0) const;

  /**
   * Token output, see Type::SWrite for public wrappers.
   * The method assumes that the type parameter is a faudes type and uses
   * the provide write method per entry. Reimplement this function in derived 
   * classes for non-faudes type vectors.
   *
   * @param rTw
   *   Reference to TokenWriter
   *
   * @exception Exception 
   *   - IO errors (id 2)
   */
  virtual void DoSWrite(TokenWriter& rTw) const;

  /** 
   * Token output, see Type::Write for public wrappers.
   * The method assumes that the type parameter is a faudes type and uses
   * the provide write method per entry. Reimplement this function in derived 
   * classes for non-faudes type vectors.
   *
   * @param rTw
   *   Reference to TokenWriter
   * @param rLabel
   *   Label of section to write, defaults to name of set
   * @param pContext
   *   Write context to provide contextual information
   */
  virtual void DoWrite(TokenWriter& rTw, const std::string& rLabel="", const Type* pContext=0) const;

  /**
   * Token input, see Type::Read for public wrappers.
   * The method assumes that the type parameter is a faudes type and uses
   * the provide read method per entry. Reimplement this function in derived 
   * classes for non-faudes type vectors.
   * By convention, the default label "" should be translated to some meaningful default, 
   * eg "GeneratorVector" for a vector of generators. The pContext pointer can be type-checked
   * and interpreted, ie as a symboltable to provide symbolic names. It is also
   * passed on to vector entries.
   *
   * @param rTr
   *   Reference to TokenReader
   * @param rLabel
   *   Label of section to read, defaults to name of set
   * @param pContext
   *   Read context to provide contextual information
   */
  virtual void DoRead(TokenReader& rTr, const std::string& rLabel = "", const Type* pContext=0);

  /** Assignment method  */
  void DoAssign(const vBaseVector& rSourceVector);

  /** Internal entry data type */
  class ElementRecord {
  public:
    Type* pElement;
    std::string mFileName;
    bool mMine;
  };

  /** STL vector of element */
  std::vector<ElementRecord> mVector;

  /** convenience typedef */
  typedef std::vector<ElementRecord>::iterator iterator;

private:

  /** Name of TBaseVector */
  std::string mMyName;

};


/** @} doxygen group */


/** @addtogroup ContainerClasses */
/** @{*/

/**
 * Vector template.
 *
 * The vector templates specializes the bass vBaseVector in that it uses the template
 * paremeter to specify the type of its entries. See vBaseVector for element access
 * methods.
 *
 * TVectorSet serves is used to implement the libFaudes vectors
 * - GeneratorVector (vector or generators) 
 * - SytemVector     (vector or generators) 
 * - EventSetVector  (vector of event sets) 
 * - AlphabetVector  (vector of event sets) 
 *
 *
 */

template<class T>
class TBaseVector : public vBaseVector {

FAUDES_TYPE_TDECLARATION(Void,TBaseVector,vBaseVector)

public:

  /**
   * Constructor. 
   */
  TBaseVector(void);

  /**
   * Copy-constructor. 
   *
   * @param rOtherSet 
   *    Source to copy from
   */
  TBaseVector(const TBaseVector& rOtherSet);

  /**
   * Copy-constructor. This version takes any vector as source,
   * but throughs an exception, if element types dont match.
   *
   * @param rOtherSet 
   *    Source to copy from
   * @exception Exception
   *   - Cannot cast elements (63)
   */
  TBaseVector(const vBaseVector& rOtherSet);

  /**
   * Constructor from file.
   *
   * @param rFilename
   *   Name of File
   * @param rLabel
   *   Section for the set in the file; 
   */
  TBaseVector(const std::string& rFilename, const std::string& rLabel = "BaseVector");

  /**
   * Virtual destructor
   */
  virtual ~TBaseVector(void);


  /**
   * Prototype for vector entries.
   * This template class uses the virtual function to know its element type.
   * 
   * @return 
   *    Element protoype
   */
  virtual const T* Elementp(void) const;

  /**
   * Test whether the specified element is acceptebla for this vector.
   * This is a convenience wrapper for Elementp.
   *
   * @param rElement
   *   Element to type check.
   * @return 
   *   True, if provided element is accepted by this vector.
   */
  virtual bool ElementTry(const Type& rElement) const;

  /**
   * convenience typedef for positions
   */
  typedef std::vector<int>::size_type Position;

  /** 
   * Access element.
   *
   * @param pos
   *    Specify entry to access
   * @exception Exception
   *   - Position out of range (id 69)
   */
  virtual const T& At(const Position& pos) const; 

  /** 
   * Access element.
   *
   * @param pos
   *    Specify entry to access
   * @exception Exception
   *   - Position out of range (id 69)
   */
  virtual T& At(const Position& pos); 

protected:

  /** Assignment method  */
  void DoAssign(const TBaseVector<T>& rSourceVector);


};


/** @} doxygen group */



/*
******************************************************************************************
******************************************************************************************
******************************************************************************************

Implementation of TBaseVector

******************************************************************************************
******************************************************************************************
******************************************************************************************
*/

/* convenience access to relevant scopes */
#define THIS TBaseVector<T> 
#define TEMP template<class T>
#define BASE vBaseVector


// faudes type std
FAUDES_TYPE_TIMPLEMENTATION(Void,THIS,vBaseVector,TEMP)

// TBaseVector()
TEMP THIS::TBaseVector(void) :
  vBaseVector()
{
  FD_DC("TBaseVector(" << this << ")::TBaseVector()");
}

  
// TBaseVector(filename)
TEMP THIS::TBaseVector(const std::string& rFileName, const std::string& rLabel)  :
  vBaseVector()
{
  FD_DC("TBaseVector(" << this << ")::TBaseVector()");
  // do read;
  Read(rFileName,rLabel);  
}


// TBaseVector(rOtherSet)
TEMP THIS::TBaseVector(const TBaseVector& rOtherVector) : 
  vBaseVector()
{
  FD_DC("TBaseVector(" << this << ")::TBaseVector(rOtherVector " << &rOtherVector << "): copy construct");
  DoAssign(rOtherVector);
}

// TBaseVector(rOtherSet)
TEMP THIS::TBaseVector(const vBaseVector& rOtherVector) : 
  vBaseVector()
{
  FD_DC("TBaseVector(" << this << ")::TBaseVector([v] rOtherVector " << &rOtherVector << "): copy construct");
  Assign(rOtherVector);
}

// destructor
TEMP THIS::~TBaseVector(void) {
  FD_DC("TBaseVector(" << this << ")::~TBaseVector()");
}


// element prototype
TEMP const T* THIS::Elementp(void) const {
  static T tproto;
  return &tproto;
}

// test element type
TEMP bool THIS::ElementTry(const Type& rElement) const {
  FD_DC("TBaseVector::ElementTry(): casting from " << typeid(rElement).name() << " to " << typeid(*Elementp()).name());
  return Elementp()->Cast(&rElement)!=NULL;
}


// assignment
TEMP void THIS::DoAssign(const THIS& rSourceVector) {
  FD_DC("TBaseVector(" << this << ")::DoAssign(rOtherVector " << &rSourceVector << ")");
  // base can do it
  BASE::DoAssign(rSourceVector);
  // done
  FD_DC("TBaseVector(" << this << ")::DoAssign(rOtherVector " << &rSourceVector << "): done");
}

// At()
TEMP const T& THIS::At(const Position& pos) const {
#ifdef FAUDES_CHECKED
  if(pos >= mVector.size()) {
    std::stringstream errstr;
    errstr << "index out of range" << std::endl;
    throw Exception("TBaseVector::At", errstr.str(), 62);
  }
#endif
#ifdef FAUDES_DEBUG_CODE
  if(!dynamic_cast<T*>(mVector[pos].pElement)){
    std::stringstream errstr;
    errstr << "internal type error" << std::endl;
    throw Exception("TBaseVector::At", errstr.str(), 63);
  }
#endif
  return *dynamic_cast<T*>(mVector[pos].pElement);
}

// At()
TEMP T& THIS::At(const Position& pos) {
#ifdef FAUDES_CHECKED
  if(pos >= mVector.size()) {
    std::stringstream errstr;
    errstr << "index out of range" << std::endl;
    throw Exception("TBaseVector::At", errstr.str(), 62);
  }
#endif
#ifdef FAUDES_DEBUG_CODE
  if(!dynamic_cast<T*>(mVector[pos].pElement)){
    std::stringstream errstr;
    errstr << "internal type error" << std::endl;
    throw Exception("TBaseVector::At", errstr.str(), 63);
  }
#endif
  return *dynamic_cast<T*>(mVector[pos].pElement);
}





/* undefine local shortcuts */
#undef THIS
#undef TEMP
#undef BASE


} // namespace faudes

#endif 
