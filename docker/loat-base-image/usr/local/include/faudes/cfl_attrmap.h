/** @file cfl_attrmap.h @brief Class TAttrMap */


/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2008, 2016  Thomas Moor
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



#ifndef FAUDES_ATTRMAP_H
#define FAUDES_ATTRMAP_H

#include "cfl_baseset.h"

namespace faudes {

/** @addtogroup ContainerClasses */
/** @{*/

/**
 * Attribute interface for TBaseSet.
 *
 * TAttrMap provides a typed interface to access the attributes associated with
 * elements of a TBaseSet. It is meant to faciltate classes derived from TBaseSet 
 * that use non-trivial attributes. Note that the actual attribute map is hosted by
 * TBaseSet itself.
 *
 * Note: technically, the TAttrMap holds a reference to the associated TBaseSet.
 * When deriving from a child of TBaseSet, the interface is introduced 
 * by additional inheritance of TAttrMap. Effectively, this avoids the diomand-shape 
 * inheritance we used to have in pre 2.30 versions of libFAUDES and which caused various 
 * issues with the MS Visual Studio compilers regarding covaraint return values in the
 * context of templates.
 */


template<class T, class Attr, class Cmp=std::less<T> >
class FAUDES_API TAttrMap {


public:

  /**
   * Constructor. 
   *
   * Record associated set.
   */
  TAttrMap(TBaseSet<T,Cmp>* pBaseSetRef);

  /**
   * Virtual destructor
   */
  virtual ~TAttrMap(void);

  /**
   * Copy from a TBaseSet to the associated TBaseSet, with attributes,
   * provided that they can be casted accordingly.
   *
   * @param rSourceSet 
   *    Set to copy from
   */
  void AssignWithAttributes(const TBaseSet<T,Cmp>& rSourceSet);

  /**
   * Attribute typeinfo.
   *
   * @return
   *    Pointer to some attribute of this sets attribute type.
   */
  const Attr* AttributeType(void) const;


  /** 
   * Get attribute reference by element. Note that in order to produce a non-const 
   * reference this method will insert an explicit default attribute if necessary. 
   * If a const reference is sufficient, you should use Attribute(rElem) const instead.
   *
   * @param rElem
   *    Specify element
   * @exception Exception
   *   - Element does not exist (60)
   * @return 
   *    Pointer to attribute
   */
  Attr* Attributep(const T& rElem);

  /** 
   * Get attribute by element. This function returns a const reference to the attribute
   * of the specified element. 
   * @param rElem
   *    Specify element
   * @exception Exception
   *   - Element does not exist (63)
   * @return 
   *    Reference to attribute
   */
  const Attr& Attribute(const T& rElem) const;

  /** 
   * Set attribute. Provided that the attribute can be casted to the
   * appropriate type, this method sets the attribute of the sepcified element to the given value. 
   *
   * @param rElem
   *    Specify element
   * @param attr
   *    Attribute value.
   * @exception Exception
   *   - Element does not exist (60)
   *   - Cannot cast attribute type (63)
   */
  void Attribute(const T& rElem, const Type& attr);

  /** 
   * Set attribute. This method sets the attribute of the sepcified element to the given value. 
   *
   * @param rElem
   *    Specify element
   * @param attr
   *    Attribute value.
   * @exception Exception
   *   - Element does not exist (60)
   *   - Cannot cast attribute type (63)
   */
  void Attribute(const T& rElem, const Attr& attr);

  /** 
   * Set attribute. Provided that the attribute can be casted to the
   * appropriate type, this method sets the attribute of the sepcified element to the given value. 
   * If the cast fails, this method does nothing.
   *
   * @param rElem
   *    Specify element
   * @param attr
   *    Attribute value.
   * @exception Exception
   *   - Element does not exist (60)
   */
  void AttributeTry(const T& rElem, const Type& attr);

  /**
   * Insert element. If the element exists, the attribute is maintained.
   * If the element does not exist, it is inserted with default attribute.
   *
   * @param rElem
   *   Specify element
   * @return
   *   True if element was new to set 
   */
  bool Insert(const T& rElem);

  /** 
   * Insert element with attribute. 
   *
   * @param rElem
   *   Specify element
   * @param attr
   *   Specify attribute of (new) element
   * @return
   *   True if element was new to set 
   */
  bool Insert(const T& rElem, const Attr& attr);

  /**
   * Inserts elements from rOtherSet.
   *
   * Attributes of this set are maintained, newly inserted elements receive attributes
   * from rOtherSet, provided that can be casted appropriately.
   *
   *
   * @param rOtherSet
   *   Other BaseSet
   */
  void InsertSet(const TBaseSet<T,Cmp>& rOtherSet);

 
  /** 
   * Erase Element (incl its attribute) 
   *
   * @param rElem
   *    Specify element
   * @return
   *    True if element used to exist
   */
  bool Erase(const T& rElem);

  /** 
   * Erase element by iterator (incl attribute) 
   *
   * @param pos
   *    Iterator to specify element
   * @return 
   *    Iterator to next element or End()
   */
  // opt: use declare&define for cl_win issues
  typename TBaseSet<T,Cmp>::Iterator Erase(const typename TBaseSet<T,Cmp>::Iterator& pos);
  

  /** 
   * Erase elements given by other set. This function
   * ignores the attributes of the other set and maintains the attributes 
   * of the remaining elements in this set.
   *
   * @param rOtherSet 
   *    Elements to erase
   */
  void EraseSet(const TBaseSet<T,Cmp>& rOtherSet);

  /** 
   * Restrict to specified subset. Erases any elements not in
   * the specified set. This function
   * ignores the attributes of the other set and maintains the attributes 
   * of the remaining elements in this set.
   *
   * @param rOtherSet 
   *    Elements to erase
   */
   void RestrictSet(const TBaseSet<T,Cmp>& rOtherSet);



protected:

  /** use TBaseSet STL iterators */
  typedef typename TBaseSet<T,Cmp>::iterator iterator;

  /** use TBaseSet STL iterators */
  typedef typename TBaseSet<T,Cmp>::const_iterator const_iterator;

  /** use TBaseSet STL iterators */
  typedef typename TBaseSet<T,Cmp>::aiterator aiterator;

  /** use TBaseSet STL iterators */
  typedef typename TBaseSet<T,Cmp>::const_aiterator const_aiterator;

  /** reference to associated TBaseSet */
  TBaseSet<T,Cmp>* pBaseSet;

};



/** @} doxygen group */



/*
******************************************************************************************
******************************************************************************************
******************************************************************************************

Implementation of TAttrMap

******************************************************************************************
******************************************************************************************
******************************************************************************************
*/

/* convenience access to relevant scopes */
#define THIS TAttrMap<T,Attr,Cmp> 
#define TEMP template<class T, class Attr, class Cmp>

// TAttrMap()
TEMP THIS::TAttrMap(TBaseSet<T,Cmp>* pBaseSetRef) :
  pBaseSet(pBaseSetRef)
{
  FD_DC("TAttrMap(" << this << ")::TAttrMap(): set at " << pBaseSet);
}

  
// destructor
TEMP THIS::~TAttrMap(void) {
  FD_DC("TAttrMap(" << this << ")::~TAttrMap()");
}



// assign, try attributes
TEMP void THIS::AssignWithAttributes(const TBaseSet<T,Cmp>& rSourceSet) {
  FD_DC("TAttrMap(" << pBaseSet << ")::Assign(..): dst map type " << typeid(*this).name());
  FD_DC("TAttrMap(" << pBaseSet << ")::Assign(..): src type " << typeid(rSourceSet).name());
  // call base (fake copy, this will incl attributes on exact type match or ref to empty attributes else)
  pBaseSet->DoAssign(rSourceSet);
  // sense the exact match and bail out
  if(pBaseSet->AttributesSize()==rSourceSet.AttributesSize()) return;
  // if we have void attributes, we can not cast 
  FD_DC("TAttrMap(" << this << ")::Assign(..): dst attribute type " << typeid(*AttributeType()).name());
  if( typeid(*AttributeType()) == typeid(const AttributeVoid) ) return;
  // if source has void attributes, we can not cast
  FD_DC("TAttrMap(" << this << ")::Assign(..): src attribute type " << typeid(*rSourceSet.AttributeType()).name());
  if( typeid(*rSourceSet.AttributeType()) == typeid(const AttributeVoid) ) return;
  // ifattributes cannot be casted, we dont need to loop either
  FD_DC("TAttrMap(" << this << ")::Assign(..): try attribute cast");
  if(!AttributeType()->Cast(rSourceSet.AttributeType())) return;
  // detach, since we will write to attributes
  pBaseSet->Detach();
  FD_DC("TAttrMap(" << this << ")::Assign(..): mind attributes");
  const_aiterator ait=rSourceSet.pAttributes->begin();
  for(;ait!=rSourceSet.pAttributes->end(); ++ait) {
    Attr* attr= new Attr;
    attr->Assign(*ait->second);
    (*pBaseSet->pAttributes)[ait->first]=attr;
  }
  // done
  FD_DC("TAttrMap(" << pBaseSet << ")::Assign(..): done");
}


//Insert(elem)
TEMP bool THIS::Insert(const T& rElem) {
  FD_DC("TAttrMap(" << pBaseSet << ")::Insert(elem)");
  pBaseSet->Detach();
  bool ret=pBaseSet->pSet->insert(rElem).second;
  return ret;
}

//Insert(idx,attr)
TEMP bool THIS::Insert(const T& rElem, const Attr& rAttr) {
  FD_DC("TAttrMap(" << pBaseSet << ")::Insert(elem,attr)");
  pBaseSet->Detach();
  bool ret=pBaseSet->pSet->insert(rElem).second;
  pBaseSet->DoAttribute(rElem,&rAttr);
  return ret;
}

// InsertSet(set)
TEMP void THIS::InsertSet(const TBaseSet<T,Cmp>& rOtherSet) {
  bool doattr=pBaseSet->AttributeTest(*rOtherSet.AttributeType()); 
  FD_DC("TAttrMap(" << pBaseSet << ")::InsertSet( [v] " << &rOtherSet << "): doattr=" << doattr);
  pBaseSet->Detach();
  iterator it1 = pBaseSet->pSet->begin();
  iterator it2 = rOtherSet.pSet->begin();
  while ((it1 != pBaseSet->pSet->end()) && (it2 != rOtherSet.pSet->end())) {
    if (*it1 < *it2) {
      ++it1;
    }
    else if (*it1 == *it2) {
      ++it1;
      ++it2;
    }
    else { // (*it1 > *it2)
      pBaseSet->pSet->insert(*it2);
      if(doattr) pBaseSet->DoAttribute(*it2,&rOtherSet.Attribute(*it2));
      ++it2;
    }
  }
  while(it2 != rOtherSet.pSet->end()) {
    pBaseSet->pSet->insert(*it2);
    if(doattr) pBaseSet->DoAttribute(*it2,&rOtherSet.Attribute(*it2));
    ++it2;
  }
  FD_DC("TAttrMap(" << pBaseSet << ")::InsertSet( [v] " << &rOtherSet << "): done");
}

//Erase(idx)
TEMP bool THIS::Erase(const T& rElem) {
  pBaseSet->Detach();
  pBaseSet->DoAttribute(rElem,(const AttributeVoid*) 0);
  return (pBaseSet->pSet->erase(rElem)!=0);
}

//Erase(it)
TEMP  typename TBaseSet<T,Cmp>::Iterator THIS::Erase(const typename TBaseSet<T,Cmp>::Iterator& pos) {
  pBaseSet->Detach();
  iterator del= pos.StlIterator(); 
  pBaseSet->DoAttribute(*pos,(const AttributeVoid*) 0);
  pBaseSet->pSet->erase(del++);
  return pBaseSet->ThisIterator(del); 
}


//EraseSet(set)
TEMP void THIS::EraseSet(const TBaseSet<T,Cmp>& rOtherSet) {
  FD_DC("TAttrMap(" << pBaseSet << ")::EraseSet(" << &rOtherSet << ")");
  pBaseSet->Detach();
  // todo: test and optimize 
  iterator it = pBaseSet->pSet->begin();
  iterator oit = rOtherSet.pSet->begin();
  while ((it != pBaseSet->pSet->end()) && (oit != rOtherSet.pSet->end())) {
    if (*it < *oit) {
      it=pBaseSet->pSet->lower_bound(*oit); // alt: ++it;
    }
    else if (*it == *oit) { 
      pBaseSet->DoAttribute(*it,(const AttributeVoid*) 0);
      ++oit;
      pBaseSet->pSet->erase(it++);
    }
    else { // (*it > *oit)
      oit=rOtherSet.pSet->lower_bound(*it); // ++it2;
    }
  }
}


//RestrictSet(set)
TEMP void THIS::RestrictSet(const TBaseSet<T,Cmp>& rOtherSet) {
  FD_DC("TAttrMap(" << pBaseSet << ")::RestrictSet(" << &rOtherSet << ")");
  pBaseSet->Detach();
  // todo: test and optimize 
  iterator it = pBaseSet->pSet->begin();
  iterator oit = rOtherSet.pSet->begin();
  while ((it != pBaseSet->pSet->end()) && (oit != rOtherSet.pSet->end())) {
    if (*it < *oit) {
      pBaseSet->DoAttribute(*it,(const AttributeVoid*) 0);
      pBaseSet->pSet->erase(it++);
    }
    else if (*it == *oit) { 
      ++it;
      ++oit;
    }
    else { // (*it > *oit)
      ++oit;
    }
  }
  while(it != pBaseSet->pSet->end()) {
    pBaseSet->DoAttribute(*it,(const AttributeVoid*) 0);
    pBaseSet->pSet->erase(it++);
  }

}



// attribute typeinfo
TEMP const Attr* THIS::AttributeType(void) const { 
  static Attr attr;
  FD_DC("TAttrMap::AttributeType(): accessing non trivial type");
  return &attr;
}


// get attribute wrapper
TEMP Attr* THIS::Attributep(const T& rElem) {
#ifdef FAUDES_CHECKED
  if(!pBaseSet->Exists(rElem)) {
    std::stringstream errstr;
    errstr << "element \"" << pBaseSet->Str(rElem) << "\" not member of set " << pBaseSet->Name() << std::endl;
    throw Exception("TAttrMap::Attributep(elem)", errstr.str(), 60);
  }
#endif
  // must detach
  pBaseSet->Detach();
  // find in map (incl insert explicit default)
  Attr* attr=dynamic_cast<Attr*>(pBaseSet->DoAttributeExplicit(rElem));
  FD_DC("TAttrMap::Attributep(): found " << attr << " type " << typeid(*attr).name() );
  // done
  return attr;
}

// get attribute wrapper
TEMP const Attr& THIS::Attribute(const T& rElem) const {
#ifdef FAUDES_CHECKED
  if(!pBaseSet->Exists(rElem)) {
    std::stringstream errstr;
    errstr << "element \"" << pBaseSet->Str(rElem) << "\" not member of set " << pBaseSet->Name() << std::endl;
    throw Exception("TAttrMap::Attribute(elem)", errstr.str(), 60);
  }
#endif
  // find in map
  const Attr* attr=dynamic_cast<const Attr*>(pBaseSet->DoAttribute(rElem));
  // use default
  if(!attr) attr=this->AttributeType();
  // done
  return *attr;
}

// set attribute wrapper
TEMP void THIS::Attribute(const T& rElem, const Type& attr) {
#ifdef FAUDES_CHECKED
  if (!pBaseSet->Exists(rElem)) {
    std::stringstream errstr;
    errstr << "element \"" << pBaseSet->Str(rElem) << "\" not member of set " << pBaseSet->Name() << std::endl;
    throw Exception("TAttrMap::Attribute(elem,attr [t])", errstr.str(), 60);
  }
#endif
  if(!pBaseSet->AttributeTest(attr)) {
    std::stringstream errstr;
    errstr << "cannot cast attribute " << std::endl;
    throw Exception("TAttrMap::Attribute(elem,attr [t])", errstr.str(), 63);
  }
  pBaseSet->Detach();
  pBaseSet->DoAttribute(rElem,&attr); 
}

// set attribute wrapper
TEMP void THIS::AttributeTry(const T& rElem, const Type& attr) {
  FD_DC("TAttrMap::Attribute(elem,attr) [t]");
#ifdef FAUDES_CHECKED
  if(!pBaseSet->Exists(rElem)) {
    std::stringstream errstr;
    errstr << "element \"" << pBaseSet->Str(rElem) << "\" not member of set " << pBaseSet->Name() << std::endl;
    throw Exception("TAttrMap::AttributeTry(elem,attr [t])", errstr.str(), 60);
  }
#endif
  if(!pBaseSet->AttributeTest(attr)) return;
  pBaseSet->Detach();
  pBaseSet->DoAttribute(rElem,&attr); 
}

// set attribute wrapper
TEMP void THIS::Attribute(const T& rElem, const Attr& attr) {
  FD_DC("TAttrMap::Attribute(elem,attr) [a]");
#ifdef FAUDES_CHECKED
  if(!pBaseSet->Exists(rElem)) {
    pBaseSet->DWrite();
    std::stringstream errstr;
    errstr << "element \"" << pBaseSet->Str(rElem) << "\" not member of set " << pBaseSet->Name() << std::endl;
    throw Exception("TAttrMap::Attribute(elem,attr [a])", errstr.str(), 60);
  }
#endif
  pBaseSet->Detach();
  pBaseSet->DoAttribute(rElem, &attr); 
}


/* undefine local shortcuts */
#undef THIS
#undef TEMP


} // namespace faudes

#endif 
