/** @file cfl_baseset.h @brief Class TBaseSet */


/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2008  Thomas Moor
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



#ifndef FAUDES_BASESET_H
#define FAUDES_BASESET_H

#include "cfl_definitions.h"
#include "cfl_tokenwriter.h"
#include "cfl_tokenreader.h"
#include "cfl_registry.h"
#include "cfl_types.h"
#include "cfl_attributes.h"
#include <set>
#include <algorithm>

namespace faudes {

/** @addtogroup ContainerClasses */
/** @{*/

// Forward declaration for the attribute interface class
template<class T, class Attr, class Cmp> class TAttrMap;

/**
 * STL style set template.
 * This class template is built on top of the STL set template. It provides essentials of 
 * the STL interface relevant to libFAUDES plus a deferred copy mechanism, aka copy-on-write. 
 * TBaseSet serves as a base class for all libFaudes containers: 
 * - IndexSet (indices), 
 * - TaIndexSet (indices with attributes), 
 * - SymbolSet (symbolic names), 
 * - NameSet (indices with symbolic names), 
 * - TaNameSet (indices with attributes and symbolic names), 
 * - TTransSet (transitions in a sepcific order),
 * - TaTransSet (transitions in std order with attribute).
 *
 * The public functions of a TBaseSet provide the high-level api, with the intention
 * to organize the deferred copy machanism in a transparent manner. Since STL iterators
 * refer to a particular STL container, they become invalid when the internal container 
 * is copied. Therefor, TBaseSet tracks iterators and fixes them when the actual copy takes place.
 * This introduces some runtime overhead, in particular when your application represents
 * subsets as sets of iterators. You may use the public method Lock() to enforce 
 * a full copy and to prevent any further re-allocation.
 *
 * Alternatively to the high-level api, a protected low-level api is provided with direct 
 * access to the internal STL set. When using this api, it is up to the derived class to ensure
 * that the BaseSet gets detached from its refernces befor write operations can take
 * place. 
 *
 * The virtual function TBaseSet<T>::Valid() is used to indicate whether a candidate
 * element is valid as a set member. If the macro FAUDES_CHECKED
 * is defined, the attempt to insert an invalid element triggers an exception (id 61). Invalid
 * iterators throw an exception (id 62) when used as an argument to a BaseSet function. 
 *
 * The TBaseSet also hosts a container to associate an attribute with each set element. However,
 * in the plain TBAseSey the attribute type is set to void and member methods only deal 
 * with attributes when this does not invilve too much overhead. To make effective use of attributes, 
 * one is meant to derive a class from TBaseSet that encodes the actual attribute type and 
 * that provides appropriate access methods. This is facilitated by the class TAttrMap. 
 *
 * Note on a boring technical detail: 
 * since STL sets are sorted, effectively all set iterators should be const.
 * However, there is a minor issue whether or not the erase function should use a 
 * const iterator as argument. SGI derived STL implementations (as used on most GNU systems) 
 * avoid this issue by defining const and non-const iterators on sets as identical types. 
 * MS implementation (used in VS C++ by default, as of 2006) differ in this aspect. The class 
 * TBaseSet::Iterator hides the issue from the faudes API but it is still present internaly. 
 *
 */

template<class T, class Cmp=std::less<T> >
class FAUDES_API TBaseSet : public Type {       

  FAUDES_TYPE_TDECLARATION(Void,TBaseSet,Type)

public:

  /** allow access to attribute interface class */
  template<class TP, class AP, class CP> friend class TAttrMap;


  /**
   * Constructor. 
   */
  TBaseSet(void);

  /**
   * Copy-constructor. 
   *
   * @param rOtherSet 
   *    Source to copy from
   */
  TBaseSet(const TBaseSet& rOtherSet);

  /**
   * Constructor from file.
   * This constructor indicates the intended interface for derived classes. The base set 
   * itself cannot read from token streams.
   *
   * @param rFilename
   *   Name of File
   * @param rLabel
   *   Section for the set in the file; 
   */
  TBaseSet(const std::string& rFilename, const std::string& rLabel = "BaseSet");

  /**
   * Virtual destructor
   */
  virtual ~TBaseSet(void);

  /** 
   * Return name of TBaseSet 
   * 
   * @return
   *   Name of TBaseSet
   */
  const std::string& Name(void) const;
        
  /**
   * Set name of TBaseSet
   *
   * @param rName
   *   Name to set
   */
  void Name(const std::string& rName);


  /** 
   * Clear all set
   */
  virtual void Clear(void);
      
  /**
   * Get Size of TBaseSet
   *
   * @return 
   *   Number of indices in TBaseSet
   */
  Idx Size(void) const;

  /** 
   * Test whether if the TBaseSet is Empty 
   *
   * @return 
   *   True if empty
   */
  bool Empty(void) const;

  /**
   * Return pretty printable element. 
   * Reimplement this method for derived classes.
   *
   * @param rElem
   *   Element to print
   *
   * @return
   *   String
   */
  virtual std::string Str(const T& rElem) const;

  /** 
   * Iterator class for high-level api to TBaseSet.
   *
   */
  class Iterator;

  /** 
   * Iterator to the begin of set
   *
   * @return 
   *   Iterator
   */
  Iterator Begin(void) const;
        
  /** 
   * Iterator to the end of set
   *
   * @return 
   *   Iterator
   */
  Iterator End(void) const;

  /**
   * Test validty of candidate element.
   *
   * Reimplement this function for particular type T of elements,
   * eg for an index set with T=Idx indicate 0 an invalid index.
   *
   * @param rElem
   *    Candidate to test
   * @return
   *    True if element is valid
   */
  virtual bool Valid(const T& rElem) const;
   

  /** 
   * Erase element by reference
   *
   * @param rElem
   *    Element to erase
   * @return
   *    True if element used to exist
   */
  virtual bool Erase(const T& rElem);


  /** 
   * Erase element by iterator 
   *
   * @param pos
   *    Iterator to specify element
   * @return 
   *    Iterator to next element (or End if no such)
   */
  virtual Iterator Erase(const Iterator& pos); 


  /** 
   * Erase elements given by other set 
   *
   * @param rOtherSet 
   *    Set of elements to erase
   */
  virtual void EraseSet(const TBaseSet& rOtherSet);

  /** 
   * Restrict elements given by other set 
   *
   * @param rOtherSet 
   *    Set of elements to keep
   */
  virtual void RestrictSet(const TBaseSet& rOtherSet);

  /** 
   * Test for this set to be disjoint witg other set 
   *
   * @param rOtherSet 
   *    Set of elements to keep
   */
  virtual bool Disjoint(const TBaseSet& rOtherSet) const;

  /** 
   * Insert specified element
   *
   * @param rElem
   *    Element to insert
   * @return
   *   True if index was new to set 
   */
  virtual bool Insert(const T& rElem);

  /** 
   * Insert specified element
   *
   * @param pos
   *   Insertion hint passed to STL
   * @param rElem
   *    Element to insert
   * @return
   *   Insertion position
   *
   */
  virtual Iterator Inject(const Iterator& pos, const T& rElem);
    
  /** 
   * Insert specified element
   *
   * @param rElem
   *    Element to insert
   *
   */
  virtual void Inject(const T& rElem);
    
  /**
   * Insert elements given by rOtherSet 
   *
   *
   * @param rOtherSet
   *   Set of elements to insert
   */
  virtual void InsertSet(const TBaseSet& rOtherSet);


  /**
   * Test existence of element
   *
   * @param rElem
   *   Element to test
   *
   * @return 
   *   True if element exists in set
   */
  bool Exists(const T& rElem) const;

  /**
   * Find element and return iterator.
   *
   * @param rElem
   *   Element to find
   *
   * @return 
   *   Iterator to element or End() if nonexistent
   */
  Iterator Find(const T& rElem) const;

  /**
   * Set union operator
   *
   * @return 
   *   Union Set
   */
  TBaseSet operator+ (const TBaseSet& rOtherSet) const;

  /**
   * Set difference operator
   *
   * @return 
   *   Difference Set
   */
  TBaseSet operator- (const TBaseSet& rOtherSet) const;

  /**
   * Set intersection operator
   *
   * @return 
   *   Intersection Set
   */
  TBaseSet operator* (const TBaseSet& rOtherSet) const;


  /** Test for subset  */
  bool operator<= (const TBaseSet& rOtherSet) const;

  /** Test for superset */
  bool operator>= (const TBaseSet& rOtherSet) const;

  /** Order for sorting containers of TBaseSet */
  bool operator< (const TBaseSet& rOtherSet) const;

  /** Some validation of deferred copy mechanism (provoke abort)*/
  void DValid(const std::string& rMessage="") const;

  /** Detach from extern storage (incl allocation and true copy) */
  enum DetachMode { SetOnly, AttrIncl };  
  void Detach(DetachMode flag=AttrIncl) const;

  /** Detach and lock any further reallocation */
  void Lock(void) const;

  /** 
   * Iterator class for high-level api to TBaseSet.
   * This class is derived from STL iterators to additionally provide
   * a reference of the container to iterate on. This feature
   * is used to adjust iterators when the actual set gets reallocated due to a Detach()
   * operation. Inheritance is private to ensure that all high-level api functions maintain
   * iteretor refernces consistently. Currently, high-level api iterators support
   * the operators -&gt; ,*,  =, ++, --, ==, !=.
   * 
   * Technical detail: the private inheritance prohibits the direct use of stl algorithms on
   * faudes Iterators. If you need direct access to stl algorithms from outside the faudes set
   * class, you may turn to public inheritance. Make sure to Lock the relevant sets befor
   * applying any stl algorithms.
   */
   class Iterator : private std::set<T,Cmp>::const_iterator {
     public: 
     /** Default constructor, container unknown */
     Iterator() : 
       std::set<T,Cmp>::const_iterator() , 
       pBaseSet(NULL),
       mAttached(false) 
     {};

     /** Construct by members (used by TBaseSet to create temporary iterators) */
     Iterator(
       const TBaseSet<T,Cmp>* pBaseSet,
       const typename std::set<T,Cmp>::const_iterator& sit,
       bool att=false) : 
       std::set<T,Cmp>::const_iterator(sit), 
       pBaseSet(pBaseSet),
       mAttached(false)  
     {
       if(pBaseSet && att) {
          pBaseSet->AttachIterator(this);
          mAttached=true;
       }
     };

     /** Copy constructor, copies container reference, incl attach */
     Iterator(const Iterator& fit) : 
       std::set<T,Cmp>::const_iterator(fit),
       pBaseSet(fit.pBaseSet), 
       mAttached(false) 
     {
       if(pBaseSet) {
          pBaseSet->AttachIterator(this);
          mAttached=true;
       }
     };  

     /** Destructor */
     ~Iterator(void) { 
       if(mAttached) pBaseSet->DetachIterator(this);
     }; 

     /** report (debugging) */
     std::string DStr(void) const {
       std::stringstream rstr;
       rstr << "[dit base " << pBaseSet << " a" << mAttached << " data " << pBaseSet->pSet;
       if(pBaseSet) rstr << " elem " << pBaseSet->Str(**this);
       rstr << "]";
       return rstr.str();
     }

     /** Assigment, tracks container */
     const Iterator& operator= (const Iterator& rSrc) {
#ifdef FAUDES_DEBUG_CODE
       if(rSrc.pBaseSet==NULL) {
         FD_ERR("TBaseSet<T,Cmp>::Iterator(" << this << "):operator= invalid iterator: no baseset");
         abort();
       }
#endif
       // performance relevant std case 
       if(mAttached) if(pBaseSet==rSrc.pBaseSet) {
         std::set<T,Cmp>::const_iterator::operator= (rSrc);
         return *this;
       }
       // general case
       if(mAttached) pBaseSet->DetachIterator(this);
       std::set<T,Cmp>::const_iterator::operator= (rSrc);
       pBaseSet = rSrc.pBaseSet;
       if(pBaseSet) {
         pBaseSet->AttachIterator(this);
         mAttached=true;
       } else {
  	 mAttached=false;
       }
       return *this;
     };

     /** Assign STL iterator only */
     void  StlIterator(const typename std::set<T,Cmp>::const_iterator& sit) {
       std::set<T,Cmp>::const_iterator::operator= (sit);
     };

     /** Get STL iterator only */
     const typename std::set<T,Cmp>::const_iterator& StlIterator(void) const {
       return *this;
     };

     /** Invalidate */
     void  Invalidate(void) {
       pBaseSet=NULL;
       mAttached=false;
     }; 

     /** Detach */
     void  Detach(void) {
       mAttached=false;
     }; 


     /** Check validity (provoke abort error) */
     void DValid(void) const {
      if(pBaseSet==NULL) {
         FD_ERR("TBaseSet<T,Cmp>::Iterator(" << this << "):DValid(): invalid iterator: no baseset");
         abort();
       }
       pBaseSet->DValid("Iterator");
     }; 

    /** Reimplement dereference */
     const T* operator-> (void) const {
#ifdef FAUDES_DEBUG_CODE
       if(pBaseSet==NULL) {
         FD_ERR("TBaseSet<T,Cmp>::Iterator(" << this << "):operator->: invalid iterator: no baseset");
         abort();
       }
#endif
       return std::set<T,Cmp>::const_iterator::operator-> ();
     };

     /** Reimplement derefernce */
     const T& operator* (void) const {
#ifdef FAUDES_DEBUG_CODE
       if(pBaseSet==NULL) {
         FD_ERR("TBaseSet<T,Cmp>::Iterator(" << this << "):operator*: invalid iterator: no baseset");
         abort();
       }
#endif
       return std::set<T,Cmp>::const_iterator::operator* ();
     };

     /** Reimplement == */
     bool operator== (const Iterator& rOther) const {
#ifdef FAUDES_DEBUG_CODE
       if(pBaseSet==NULL) {
         FD_ERR("TBaseSet<T,Cmp>::Iterator(" << this << "):operator==: invalid iterator: no baseset");
         abort();
       }
#endif
       return *static_cast< const typename std::set<T,Cmp>::const_iterator *>(this) == rOther;
     };

     /** Reimplement != */
     bool operator!= (const Iterator& rOther) const {
#ifdef FAUDES_DEBUG_CODE
       if(pBaseSet==NULL) {
         FD_ERR("TBaseSet<T,Cmp>::Iterator(" << this << "):operator!=: invalid iterator: no baseset");
         abort();
       }
#endif
       return *static_cast< const typename std::set<T,Cmp>::const_iterator *>(this) != rOther;
     };

     /** Reimplement postfix ++ */
     Iterator operator++ (int step) {
#ifdef FAUDES_DEBUG_CODE
       if(pBaseSet==NULL) {
         FD_ERR("TBaseSet<T,Cmp>::Iterator(" << this << "):operator++: invalid iterator: no baseset");
         abort();
       }
#endif
       Iterator old(pBaseSet,*this, true); // (tmoor 201308: very tricky issue in "erase(it++)" construct)
       std::set<T,Cmp>::const_iterator::operator++ (step);
       return old;
     };

     /** Reimplement prefix ++ */
     const Iterator& operator++ (void) {
#ifdef FAUDES_DEBUG_CODE
       if(pBaseSet==NULL) {
         FD_ERR("TBaseSet<T,Cmp>::Iterator(" << this << "):operator++: invalid iterator: no baseset");
         abort();
       }
#endif
       std::set<T,Cmp>::const_iterator::operator++ ();
       return *this;
     };

     /** Reimplement postfix -- */
     Iterator operator-- (int step) {
#ifdef FAUDES_DEBUG_CODE
       if(pBaseSet==NULL) {
         FD_ERR("TBaseSet<T,Cmp>::Iterator(" << this << "):operator--: invalid iterator: no baseset");
         abort();
       }
#endif
       Iterator old(pBaseSet, *this, true);
       std::set<T,Cmp>::const_iterator::operator-- (step);
       return old;
     };

     /** Reimplement prefix -- */
     const Iterator& operator-- (void) {
#ifdef FAUDES_DEBUG_CODE
       if(pBaseSet==NULL) {
         FD_ERR("TBaseSet<T,Cmp>::Iterator(" << this << "):operator--: invalid iterator: no baseset");
         abort();
       }
#endif
       std::set<T,Cmp>::const_iterator::operator-- ();
       return *this;
     };


     /** Order by reference for containers of Iterators < */
     /*
     bool operator< (const Iterator& rOther) const {
       return this < &rOther;
     };
     */

     /** Maintaine container reference */
     const TBaseSet<T,Cmp>* pBaseSet;

     /** Indicate that this iterator is attached to some baseset */
     bool mAttached;
   };

#ifdef DONT_TRACK_REFERENCES

  /** 
   * Iterator class for high-level api to TBaseSet.
   * This version is a dummy and does not provide any additional features.
   */
   class Iterator : public std::set<T,Cmp>::const_iterator {
     public:

     /** Default contructor */
     Iterator(void) : 
       std::set<T,Cmp>::const_iterator()  
     {}; 

     /** Copy constructor  */
     Iterator(const Iterator& fit) : 
       std::set<T,Cmp>::const_iterator(fit)
     {};

     /** Copy constructor  */
     Iterator(const typename std::set<T,Cmp>::const_iterator& sit) : 
       std::set<T,Cmp>::const_iterator(sit)
     {};

     /** Copy constructor, compatibility  */
     Iterator(
       const TBaseSet<T,Cmp>* pBaseSet,
       const typename std::set<T,Cmp>::const_iterator& sit) : 
       std::set<T,Cmp>::const_iterator(sit) 
     {};

     /** Assign STL iterator only, compatibility */
     void  StlIterator(const typename std::set<T,Cmp>::const_iterator& sit) {
       std::set<T,Cmp>::const_iterator::operator= (sit);
     }; 

     /** Get STL iterator only, compatibility */
     const typename std::set<T,Cmp>::const_iterator& StlIterator(void) const {
       return *this;
     };

     /** Invalidate, compatibility */
     void  Invalidate(void) {};

   };

#endif


  /** 
   * Attribute typeinfo.
   * This virtual function provides an interface for derived container classes with attributes 
   * eg TaIndexSet. When not re-implemented, it returns an attribute with type AttributeVoid to
   * indicate the absence of nontrivial attributes
   */
  virtual const AttributeVoid* AttributeType(void) const;

  /** 
   * Attribute typeinfo.
   * This virtual function provides an interface for derived classes with attributes eg TaIndexSet. 
   * It tests whether this set accepts the specified attribute type ie whether it can be casted.
   * The test is performned by the Cast function of the attribute type returned by AttributeType().
   * @param rAttr
   *     Attribute type to test.
   * @return True, if attribute type is accepted.
   */
  virtual bool AttributeTest(const Type& rAttr) const;

  /**
   * Attribute access.
   * This virtual function provides an interface for derived classes with attributes eg TaIndexSet. 
   * The current implementation uses the DoAssign method and clears any attributes afterwards.
   * Future implementations may be more efficient.
   *
   * @param rSourceSet 
   *    Set to copy from
   */
  virtual TBaseSet& AssignWithoutAttributes(const TBaseSet& rSourceSet);

  /**
   * Attributes access. 
   * This virtual function provides an interface for derived classes with attributes eg TaIndexSet. 
   * It copies attributes from the specified set, provided that they can be casted appropriately.
   * Elements of this set which are not in rOtherSet maintain their attribute. 
   *
   * @param rOtherSet
   *   Other BaseSet
   * @exception Exception
   *   - Cannot cast attribute type (63)
   */
  virtual void Attributes(const TBaseSet& rOtherSet);



  /** 
   * Attribute access.
   * This virtual function provides an interface for derived classes with attributes eg TaIndexSet. 
   * Provide the number of explicit attributes.
   * The TBaseSet itself has no attributes and thus this function returns 0.
   */
  Idx AttributesSize(void) const;

  /** 
   * Attribute access.
   * This virtual function provides an interface for derived classes with attributes eg TaIndexSet. 
   * The TBaseSet itself has no attributes and thus this function does nothing.
   */
  void ClearAttributes(void);

  /**
   * Attribute access.
   * Test whether attributes match with other set,
   * and return true if attributes match for shared elements. It uses
   * the equality test of individual attributes and, hence, requires the attribute type
   * match too.
   * @param rOtherSet 
   *    Other set to compare with.
   * @return 
   *   True on match.
   */
  bool EqualAttributes(const TBaseSet& rOtherSet) const;

  /** 
   * Attribute access.
   * This virtual function provides an interface for derived classes with attributes eg TaIndexSet. 
   * The TBaseSet has no attributes and thus throws an exception. 
   * Derived classes that provide attributes are meant to return a pointer to the attribute specified by rElem.
   *
   * @param rElem
   *     Element of which the attribute is requested
   * @return 
   *     Attribute of specified element
   * @exception Exception
   *   - No attributes provided (id 63)
   */
  virtual AttributeVoid* Attributep(const T& rElem);

  /** 
   * Attribute access.
   * This virtual function provides an interface for derived classes with attributes eg TaIndexSet. 
   * The TBaseSet has no attributes and thus returns a void attribute.
   * Derived classes that provide attributes are meant to return the attribute specified by rElem.
   * @param rElem
   *     Element of which the attribute is requested
   * @return 
   *     Attribute of specified element
   */
  virtual const AttributeVoid& Attribute(const T& rElem) const;

  /** 
   * Attribute access.
   * This virtual function provides an interface for derived classes with attributes eg TaIndexSet. 
   * The TBaseSet itself has void attributes and thus formally accepts any nontrivial attribute, 
   * however, ignoring any value.
   * Derived classes that provide attributes are meant to set the attribute as specified. Only if the
   * required cast to the actual attribute type fails an exception is thrown.
   * @param rElem
   *     Element of which the attribute is to be set
   * @param rAttr
   *     Attribute value to set.
   * @exception Exception
   *   - Element does not exist (60)
   *   - Cannot cast attribute type (63)
   */
  virtual void Attribute(const T& rElem, const Type& rAttr);

  /** 
   * Attribute access.
   * This virtual function provides an interface for derived classes with attributes eg TaIndexSet. 
   * It is meant to try to set the attribute as specified if the type can be casted. Otherwise it does nothing.
   * @param rElem
   *     Element of which the attribute is to be set
   * @param rAttr
   *     Attribute value to set.
   */
   virtual void AttributeTry(const T& rElem, const Type& rAttr) { (void) rElem; (void) rAttr; };

  /** 
   * Attribute access.
   * Cleras an explicit attribute associated with the specified element if sucht attribute exists.
   * The TBaseSet itself has no attributes and thus this function will do nothing.
   * @param rElem
   *     Element of which the attribute is to be cleared
   */
   virtual void ClrAttribute(const T& rElem);

  /**
   * Configure the element name tag.
   * This method allows to overwrite the tag used for elements
   * in XML IO. For usual, you will register derived class with
   * the run-time-interface and set the elemen tag for XML IO.
   *
   * @param rTag
   *   Name to set
   */
  virtual void XElementTag(const std::string& rTag);

  /** 
   * Get objects's type name. 
   *
   * Retrieve the faudes-type name from the type registry.
   * Sets allow to overwrite the faudes-type identifier. This is allows
   * for light-weight derived classes that do not need to be registered.
   *
   * @return 
   *   Faudes-type name or empty string.
   */
  virtual const std::string& TypeName(void) const;

  /**
   * Overwrite faudes-type name.
   * This method is used to overwrite the faudes-type identifyer.
   *
   * @param rType
   *   Faudes-type name to set
   */
  virtual void TypeName(const std::string& rType);




protected:


  /** 
   * Token output, see Type::DWrite for public wrappers.
   * Reimplement this function in derived classes for specific
   * specific template parameters. By convention, the default label ""
   * should be translated to a) the name of the set or b) some meaningful default, 
   * eg "IndexSet" for a set of indices. The pContext pointer can de type-checked
   * and interpreted, ie as a symboltable to provide symbolic names. It is also
   * passed on to attributes.
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
   * Token output, debugging see Type::DWrite for public wrappers.
   * Reimplement this function in derived classes for specific
   * specific template parameters.
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
   * Statistics include size, name and attributey type. The latter
   * is retrieved from the RTI, if initialized. Dereived sets may reimplement
   * this method.
   *
   * @param rTw
   *   Reference to TokenWriter
   */
  virtual void DoSWrite(TokenWriter& rTw) const;

  /**
   * Token input, see Type::Read for public wrappers.
   * Reimplement this function in derived classes for specific
   * specific template parameters.
   * By convention, the default label "" should be translated to some meaningful default, 
   * eg "IndexSet" for a set of indices". The pContext pointer can de type-checked
   * and interpreted, ie as a symboltable to provide symbolic names. It is also
   * passed on to attributes.
   *
   * @param rTr
   *   Reference to TokenReader
   * @param rLabel
   *   Label of section to read, defaults to name of set
   * @param pContext
   *   Read context to provide contextual information
   */
  virtual void DoRead(TokenReader& rTr, const std::string& rLabel = "", const Type* pContext=0);

  /** assign my members */
  void DoAssign(const TBaseSet& rSourceSet);

  /** test equality */
  bool DoEqual(const TBaseSet& rOtherSet) const;


  /** set attribute in map (assume elem exists in set, NULL <=> set to default) */
  void DoAttribute(const T& rElem, const Type* pAttr);

  /** get attribute from map (return null if elem does not exist in map) */
  const AttributeVoid* DoAttribute(const T& rElem) const;

  /** get attribute from map (insert explicit default if elem does not exist in map) */
  AttributeVoid* DoAttributeExplicit(const T& rElem);

protected:


  /** Name of this BaseSet */
  std::string mMyName;

  /** Pointer on STL set to operate on */
  std::set<T,Cmp>* pSet;

  /** STL set, if this object hosts data (else NULL) */
  std::set<T,Cmp>* mpSet;

  /** STL iterator, non-const version */
  typedef typename std::set<T,Cmp>::iterator iterator;

  /** STL iterator, const version */
  typedef typename std::set<T,Cmp>::const_iterator const_iterator;

  /** Convert STL iterator to API iterator*/
  typename TBaseSet<T,Cmp>::Iterator ThisIterator(const typename std::set<T,Cmp>::const_iterator& sit) const;



  /** Pointer to attribute map to operate on */
  std::map<T,AttributeVoid*>* pAttributes;

  /** Attribute map, if this object hosts data (else NULL). */
  std::map<T,AttributeVoid*>* mpAttributes;

  /** STL attribute iterator, non-const version */
  typedef typename std::map<T,AttributeVoid*>::iterator aiterator;

  /** STL attribute iterator, const version */
  typedef typename std::map<T,AttributeVoid*>::const_iterator const_aiterator;




  /** Pointer on BaseSet that hosts our data (THIS if we host) */
  TBaseSet<T,Cmp>* pHostSet;

  /** Iterator to the client list that hosts our data (maintained by host)*/
  typename std::list< TBaseSet<T,Cmp>* >::iterator mClientRecord; 

  /** BaseSets, that use data hosted by us (NULL if we dont host data, emptyset if we host to ourself excl.) */
  std::list< TBaseSet<T,Cmp>* >* mpClients;

  /** Indicate "hosts data to myself only" */
  bool mDetached;

  /** Indicate "dont re-allocate the STL set ever again" */
  bool mLocked;

  /** Ensure that we do not host contents to anyone else */
  void RelinkClients(void);

  /** Record that we provide contents to some other BaseSet */
  void AttachClient(TBaseSet* pRef) const;

  /** Record that we stop providing data for some TBaseSet */
  void DetachClient(TBaseSet* pRef) const;

  /** Iterators that refer to this TBaseSet */
  std::set< Iterator* > mIterators;

  /** Record that an iterator refers to this TBaseSet */
  void AttachIterator(Iterator* pFit) const;

  /** Record that an iterator stops to refer to this TBaseSet */
  void DetachIterator(Iterator* pFit) const;



  /** Reimplment from type to use chache */
  virtual const TypeDefinition* TypeDefinitionp(void) const;

  /** Get name of elements (used for XML IO) */
  virtual const std::string& XElementTag(void) const;

  /** static empty STL set for default constructor */
  static std::set<T,Cmp> msEmptySet;

  /** static empty STL map for default constructor */
  static std::map<T,AttributeVoid*> msEmptyAttributes;

  /** static empty STL client list */
  // std::list< TBaseSet<T,Cmp>* >* msEmptyClients;

private:

  /** TypeDefinition cache (should use guarded pointer here) */
  const TypeDefinition* pTypeDefinition;

  /** Current/cached name of elements (used protected accessor method) */
  std::string  mXElementTag;

  /** Current/cached faudes type-name */
  std::string  mFaudesTypeName;


};



/* 
 * Set union, rti wrapper
 *
 * @param rSetA
 *  Set A
 * @param rSetB
 *  Set B
 * @return
 *  Union of set A and set B
 */

template<class T, class Cmp>
void SetUnion(const TBaseSet<T,Cmp>& rSetA, const TBaseSet<T,Cmp>& rSetB, TBaseSet<T,Cmp>& rRes) {
  FD_DC("FAUDES_DEBUG_CONTAINER: SetUnion(TBaseSet<T,Cmp>): res at " << &rRes);
  // fix name
  std::string name=CollapsString(rSetA.Name() + "+" + rSetB.Name());
  // all the same
  if(&rSetA==&rSetB && &rSetA==&rRes) {rRes.Name(name); return;}
  // a and b ths same, res different
  if(&rSetA==&rSetB) {rRes.Assign(rSetA); rRes.Name(name); return;}
  // a and res the same, b different 
  if(&rSetA==&rRes) {rRes.InsertSet(rSetB); rRes.Name(name); return;};
  // b and res the same, a different 
  if(&rSetB==&rRes) {rRes.InsertSet(rSetA); rRes.Name(name); return;};
  // else
  rRes.Assign(rSetA);
  rRes.InsertSet(rSetB);
  rRes.Name(name); 
  FD_DC("FAUDES_DEBUG_CONTAINER: SetUnion(TBaseSet<T,Cmp>): done, res at " << &rRes << " #" << rRes.Size());
}

/* 
 * Set intersection, rti wrapper
 *
 * @param rSetA
 *  Set A
 * @param rSetB
 *  Set B
 * @return
 *  Set A intersected with set B
 */
template< class T, class Cmp >
void SetIntersection(const TBaseSet<T,Cmp>& rSetA, const TBaseSet<T,Cmp>& rSetB, TBaseSet<T,Cmp>& rRes) {
  // fix name
  std::string name=CollapsString(rSetA.Name() + "*" + rSetB.Name());
  // all the same
  if(&rSetA==&rSetB && &rSetA==&rRes) {rRes.Name(name); return;}
  // a and b ths ame, res different
  if(&rSetA==&rSetB) { rRes.Assign(rSetA); rRes.Name(name); return;}
  // a and res the same, b different 
  if(&rSetA==&rRes) {rRes.RestrictSet(rSetB); rRes.Name(name); return;};
  // b and res the same, a different 
  if(&rSetB==&rRes) {rRes.RestrictSet(rSetA); rRes.Name(name); return;};
  // else
  rRes.Assign(rSetA);
  rRes.RestrictSet(rSetB);
  rRes.Name(name); 
}


/* 
 * Set difference, rti wrapper
 *
 * @param rSetA
 *  Set A
 * @param rSetB
 *  Set B
 * @return
 *  Set A minus set B
 */
template< class T, class Cmp >
void SetDifference(const TBaseSet<T,Cmp>& rSetA, const TBaseSet<T,Cmp>& rSetB, TBaseSet<T,Cmp>& rRes) {
  // fix name
  std::string name=CollapsString(rSetA.Name() + "-" + rSetB.Name());
  // a and b the same
  if(&rSetA==&rSetB) { rRes.Clear(); rRes.Name(name); return;}
  // a and res the same, b different 
  if(&rSetA==&rRes) {rRes.EraseSet(rSetB); rRes.Name(name); return;};
  // b and res the same, a different ... need buffer?
  if(&rSetB==&rRes) {
    TBaseSet<T,Cmp>* buffb=rSetB.Copy();
    rRes.Assign(rSetA);
    rRes.EraseSet(*buffb); 
    rRes.Name(name); 
    delete buffb;
    return;
  }; 
  // else: std
  rRes.Assign(rSetA);
  rRes.EraseSet(rSetB);
  rRes.Name(name); 
}

/* 
 * Set equality, rti wrapper
 * This method ignores attributes.
 *
 * @param rSetA
 *  Set A
 * @param rSetB
 *  Set B
 * @return
 *  True for matching sets.
 */
template< class T, class Cmp >
bool SetEquality(const TBaseSet<T,Cmp>& rSetA, const TBaseSet<T,Cmp>& rSetB) {
  return rSetA==rSetB;
}

/* 
 * Set inclusion, rti wrapper
 * This method ignores attributes.
 *
 * @param rSetA
 *  Set A
 * @param rSetB
 *  Set B
 * @return
 *  True for matching sets.
 */
template< class T, class Cmp >
bool SetInclusion(const TBaseSet<T,Cmp>& rSetA, const TBaseSet<T,Cmp>& rSetB) {
  return rSetA<=rSetB;
}







/*
******************************************************************************************
******************************************************************************************
******************************************************************************************

Implementation of TBaseSet

******************************************************************************************
******************************************************************************************
******************************************************************************************
*/

/* convenience access to relevant scopes */
#define THIS TBaseSet<T,Cmp> 
#define TEMP template<class T, class Cmp>
#define BASE Type


// faudes type std: new and cast
FAUDES_TYPE_TIMPLEMENTATION_NEW(Void,THIS,Type,TEMP)
FAUDES_TYPE_TIMPLEMENTATION_COPY(Void,THIS,Type,TEMP)
FAUDES_TYPE_TIMPLEMENTATION_CAST(Void,THIS,Type,TEMP)

// faudes type std: assignemnt (break cast)
//TEMP THIS& THIS::Assign(const Type& rSrc) { this->Clear(); return *this;};
//TEMP THIS& THIS::Assign(const THIS& rSrc) { DoAssign(rSrc); return *this;};

// faudes type std: assignemnt (keep cast)
FAUDES_TYPE_TIMPLEMENTATION_ASSIGN(Void,THIS,Type,TEMP)
FAUDES_TYPE_TIMPLEMENTATION_EQUAL(Void,THIS,Type,TEMP)


// template statics: empty set
TEMP std::set<T,Cmp>  THIS::msEmptySet=std::set<T,Cmp>();
TEMP std::map<T,AttributeVoid*> THIS::msEmptyAttributes=std::map<T,AttributeVoid*>();

// TBaseSet()
TEMP THIS::TBaseSet(void) :
  Type(),
  pSet(&msEmptySet),  
  mpSet(NULL),
  pAttributes(&msEmptyAttributes),
  mpAttributes(NULL),
  pHostSet(this),
  mpClients(new std::list< TBaseSet<T,Cmp>* >),
  mDetached(false), 
  mLocked(false),
  pTypeDefinition(NULL)
{
  FAUDES_OBJCOUNT_INC("BaseSet");
  FD_DC("TBaseSet(" << this << ")::TBaseSet()");
  // other members
  mMyName="BaseSet";
}

// TBaseSet(filename)
TEMP THIS::TBaseSet(const std::string& rFileName, const std::string& rLabel)  :
  Type(),
  pSet(&msEmptySet),  
  mpSet(NULL),
  pAttributes(&msEmptyAttributes),
  mpAttributes(NULL),
  pHostSet(this),
  mpClients(new std::list< TBaseSet<T,Cmp>* >),
  mDetached(false), 
  mLocked(false), 
  pTypeDefinition(NULL)
{
  FAUDES_OBJCOUNT_INC("BaseSet");
  FD_DC("TBaseSet(" << this << ")::TBaseSet()");
  // other members
  mMyName="BaseSet";
  // do read etc ... this is a dummy anyway
  Read(rFileName,rLabel);  
}

// TBaseSet(rOtherSet)
TEMP THIS::TBaseSet(const TBaseSet& rOtherSet) : 
  Type(rOtherSet),
  pSet(&msEmptySet),  
  mpSet(NULL),  
  pAttributes(&msEmptyAttributes),
  mpAttributes(NULL),
  pHostSet(this),
  mpClients(new std::list< TBaseSet<T,Cmp>* >), // small detour ... for readability
  mDetached(false), 
  mLocked(false),
  pTypeDefinition(NULL)
{
  FAUDES_OBJCOUNT_INC("BaseSet");
  FD_DC("TBaseSet(" << this << ")::TBaseSet(rOtherSet " << &rOtherSet << "): fake copy construct");
  // run assignment
  DoAssign(rOtherSet);
#ifdef FAUDES_DEBUG_CODE
  DValid("CopyConstruct");
#endif
}

// destructor
TEMP THIS::~TBaseSet(void) {
  FAUDES_OBJCOUNT_DEC("BaseSet");
  FD_DC("TBaseSet(" << this << ")::~TBaseSet()");
  // maintain deferred copy 
  RelinkClients();
  pHostSet->DetachClient(this);
  if(mpClients) delete mpClients;
  mpClients=NULL;
  // unlink iterators (mandatory, since referenced object will be destructed)
  typename std::set< Iterator* >::const_iterator iit;
  for(iit=mIterators.begin(); iit!=mIterators.end(); ++iit) {
    (**iit).Invalidate();
  }
  // delete if we still own data
  if(mpSet) delete mpSet;
  if(mpAttributes) {
    for(aiterator ait=mpAttributes->begin(); ait!=mpAttributes->end(); ++ait)
       delete ait->second;
    delete mpAttributes;
  }
}


// fake copy
TEMP void THIS::DoAssign(const THIS& rSourceSet) {
  FD_DC("TBaseSet(" << this << "/" << this->Name() << ")::DoAssign(rOtherSet " << &rSourceSet << "): shallow copy -- src attr# " << rSourceSet.pAttributes->size());
  FD_DC("TBaseSet():DoAssign(): " << typeid(*this->AttributeType()).name()  << " <== "  << typeid(*rSourceSet.AttributeType()).name()); 
  // bail out on selfref
  if(this==&rSourceSet) return;
  // other members 
  mMyName=rSourceSet.mMyName;
  // bail out on common shared data
  if(pHostSet==rSourceSet.pHostSet) return;
  // become independant
  RelinkClients();
  pHostSet->DetachClient(this);
  // delete own old data
  if(mpSet) { 
     delete mpSet;
     mpSet=NULL;
  }
  if(mpAttributes) {
    for(aiterator ait=mpAttributes->begin(); ait!=mpAttributes->end(); ++ait)
       delete ait->second;
    delete mpAttributes;
    mpAttributes=NULL;
  }
  if(mpClients) {
    delete mpClients;
    mpClients=NULL;
  }

  // if attribute type matches, use source as host
  if(typeid(*rSourceSet.AttributeType())==typeid(*this->AttributeType())) {
    pHostSet=rSourceSet.pHostSet; 
    pHostSet->AttachClient(this);
    pSet=rSourceSet.pSet;
    pAttributes=rSourceSet.pAttributes;
  }
  // else do a deep copy (avoid mixed typed attributeb maps)
  else {
    mpSet = new std::set<T,Cmp>();
    *mpSet = *rSourceSet.pSet;     
    pSet = mpSet;
    mpAttributes = new std::map<T,AttributeVoid*>();
    if(typeid(*this->AttributeType()) != typeid(const AttributeVoid)) {
      for(aiterator ait=rSourceSet.pAttributes->begin(); ait!=rSourceSet.pAttributes->end(); ++ait) {
        AttributeVoid* attr= ait->second->Copy();
        (*mpAttributes)[ait->first]=attr;
      }
    }
    pAttributes = mpAttributes;
    pHostSet = this;
  }
  // fix iterators (invalidate)
  typename std::set< Iterator* >::iterator iit;
  for(iit=mIterators.begin(); iit!=mIterators.end(); ++iit) {
    (**iit).Invalidate();
  }
  mIterators.clear();
  // record state
  mDetached=false; 
  // if we were locked, relock (i.e. do the copy)
  if(mLocked) {
    mLocked=false;
    Lock();
  };
#ifdef FAUDES_DEBUG_CODE
  DValid("PostFakeAssignment");
#endif
  FD_DC("TBaseSet(" << this << ")::DoAssign(rOtherSet " << &rSourceSet << "): fake copy -- done with attr# " << pAttributes->size());
}

// Detach()
TEMP void THIS::Detach(DetachMode flag) const {
  FD_DC("TBaseSet(" << this << ")::Detach(void)");
#ifdef FAUDES_DEBUG_CODE
  DValid("PreDetach");
#endif

  // clear attributes for consistent behaviour
  if(mDetached) {
    if(flag==SetOnly) pAttributes->clear();
    return;
  }

  // provide fake const
  THIS* fake_const = const_cast< THIS* >(this);

#ifdef FAUDES_DEBUG_CODE
  // might have missed reference detach
  if(pHostSet==this)
  if(pSet!=&msEmptySet)
  if(mpClients)
  if(mpClients->empty()) {
    FD_ERR("TBaseSet(" << this << ")::Detach(): missed detach (?)");
    abort();                     // strict
    fake_const->mDetached=true;  // fix
  }
#endif

  // prepare: construct a copy of my data -- the set
  std::set<T,Cmp>* scopy = new std::set<T,Cmp>();
  *scopy = *pSet;     

  // prepare: construct a copy of my data -- the attribute map (optional)
  std::map<T,AttributeVoid*>* acopy = new std::map<T,AttributeVoid*>();
  if(flag==AttrIncl) {
    for(aiterator ait=pAttributes->begin(); ait!=pAttributes->end(); ++ait) {
      AttributeVoid* attr= ait->second->Copy();
      (*acopy)[ait->first]=attr;
    }
  }

  // stragie A: clients get the new copy; thus, the baseset data does
  // not get reallocated and we dont need to track iterators; on the
  // downside, fixing the references iterators may be more effort.
  if(mLocked==true) {
   
    FD_DC("TBaseSet(" << this << ")::Detach(): allocate and copy, strategie A");
    // first of my clients gets the new data 
    THIS* newhost = *mpClients->begin();
#ifdef FAUDES_DEBUG_CODE
    if(newhost->mpClients)
      FD_ERR("TBaseSet(" << this << ")::Detach(): new host used to heve clients (?)");
#endif
    newhost->pHostSet=newhost;
    newhost->mpSet=scopy; 
    newhost->pSet=scopy;
    newhost->mpAttributes=acopy;
    newhost->pAttributes=acopy;
    newhost->mpClients=mpClients;
    newhost->DetachClient(newhost);
    // set other users to use the new host
    typename std::list< THIS* >::const_iterator rit;
    for(rit=newhost->mpClients->begin();rit!=newhost->mpClients->end(); ++rit) {
      (*rit)->pHostSet=newhost;
      (*rit)->pSet=newhost->pSet;
      (*rit)->pAttributes=newhost->pAttributes;
    }
    // fix newhost clients iterators 
    typename std::set< Iterator* >::iterator iit;
    for(rit=newhost->mpClients->begin(); rit!=newhost->mpClients->end(); ++rit) {
      for(iit=(*rit)->mIterators.begin(); iit!=(*rit)->mIterators.end(); ++iit) {
        if((**iit).StlIterator()==pSet->end()) 
          **iit=Iterator(this, scopy->end());
        else
          **iit=Iterator(this, scopy->find(***iit));
      }
    }
    // fix newhost iterators 
    for(iit=newhost->mIterators.begin(); iit!=newhost->mIterators.end(); ++iit) {
      if((**iit).StlIterator()==pSet->end()) 
        **iit=Iterator(this, scopy->end());
      else
        **iit=Iterator(this, scopy->find(***iit));
    }
    // make myself own the old data 
    fake_const->mpSet=pSet;
    fake_const->mpAttributes=pAttributes;
    fake_const->mpClients= new std::list< TBaseSet<T,Cmp>* >;
    fake_const->mDetached=true;    
    // stop tracking my iterators
    for(iit=mIterators.begin(); iit!=mIterators.end(); ++iit) 
      (**iit).Detach();
    fake_const->mIterators.clear();


  // stragie B: this baseset gets the copy; thus, the clients iterators
  // remain valid and dont need to be fixed; on the downside, we need to
  // continue to track our iterators.
  } else {

    FD_DC("TBaseSet(" << this << ")::Detach(): allocate and copy, strategie B");
    // make someone else handle original data
    fake_const->RelinkClients(); 
    pHostSet->DetachClient(fake_const);
    // own the copied data
    fake_const->mpSet = scopy;
    fake_const->mpAttributes=acopy;  
    // fix my iterators
    typename std::set< Iterator* >::iterator iit;
    for(iit=mIterators.begin(); iit!=mIterators.end(); ++iit) {
      if((**iit).StlIterator()==pSet->end()) 
        **iit=Iterator(this, mpSet->end());
      else
        **iit=Iterator(this, mpSet->find(***iit));
    }
    // record myself as my newhost
    fake_const->pHostSet=fake_const;
    fake_const->pSet=mpSet;
    fake_const->pAttributes=mpAttributes;
    fake_const->mDetached=true;
    if(fake_const->mpClients) delete fake_const->mpClients;  // memeory leak fixed 20121004
    fake_const->mpClients= new std::list< TBaseSet<T,Cmp>* >;
  }


#ifdef FAUDES_DEBUG_CODE
  DValid("PostDetach");
#endif
  FD_DC("TBaseSet(" << this << ")::Detach(): done");
}

// Lock()
TEMP  void THIS::Lock(void) const {
  FD_DC("TBaseSet(" << this << ")::Lock(void)");
#ifdef FAUDES_DEBUG_CODE
  DValid("PreLock");
#endif
  // if we are locked: fine
  if(mLocked) return;

  // trigger actual copy (this set getting the copy)
  Detach(AttrIncl);

  // provide fake const
  THIS* fake_const = const_cast< THIS* >(this);

  // stop tracking iterators
  typename std::set< Iterator* >::const_iterator iit;
  for(iit=mIterators.begin(); iit!=mIterators.end(); ++iit) {
    (**iit).Detach();
  }
  fake_const->mIterators.clear();

  // stop detach from reallocating
  fake_const->mLocked=true;

#ifdef FAUDES_DEBUG_CODE
  DValid("PostLock");
#endif
}


// if i am a host to others, make someone else the host
TEMP inline void THIS::RelinkClients(void) {
  FD_DC("TBaseSet::RelinkClients(" << this << ")")
#ifdef FAUDES_DEBUG_CODE
  DValid("PreRelink");
#endif

  // no clients record, so i dont host any data 
  if(!mpClients) return;
  // empty clients, so i only host to myself
  if(mpClients->empty()) return;

  FD_DC("TBaseSet::RelinkClients(" << this << "): doit")

  // make first client the new host
  THIS* newhost = *mpClients->begin();
#ifdef FAUDES_DEBUG_CODE
  if(newhost->pHostSet!=this) 
    FD_ERR("BaseSet::RelinkRefernces: old reference must have this as provider");
  if(newhost->mpClients)
    FD_ERR("TBaseSet(" << this << ")::RelinkClients(void): client is a host (?)");
#endif
  newhost->pHostSet=newhost;
  newhost->mpSet=mpSet; 
  newhost->pSet=pSet;
  newhost->mpAttributes=mpAttributes; 
  newhost->pAttributes=pAttributes;
  newhost->mpClients=mpClients;
  newhost->DetachClient(newhost);
  // set other users to new newhost
  typename std::list< THIS* >::const_iterator rit;
  for(rit=newhost->mpClients->begin();rit!=newhost->mpClients->end(); ++rit) {
    (*rit)->pHostSet=newhost;
  }
  // make myself a reference to the new source
  pHostSet=newhost;
  pSet=newhost->pSet;
  mpSet=NULL;
  pAttributes=newhost->pAttributes;
  mpAttributes=NULL;
  newhost->AttachClient(this);
  mpClients=NULL;
#ifdef FAUDES_DEBUG_CODE
  DValid("PostRelink");
#endif
  FD_DC("TBaseSet::RelinkClients(" << this << "): done")
}


// record fake copy
TEMP inline void THIS::AttachClient(TBaseSet* pRef) const {
  if(!mpClients) const_cast< THIS* >(this)->mpClients=new std::list< TBaseSet<T,Cmp>* >;
  const_cast< THIS* >(this)->mpClients->push_back(pRef);
  pRef->mClientRecord= -- mpClients->end();
  const_cast< THIS* >(this)->mDetached=false;
}

// discard fake copy
TEMP inline void THIS::DetachClient(TBaseSet* pRef) const {
  FD_DC("TBaseSet::DetachClient(" << this << "):" << pRef);
  // bail out on trivials
  if(!mpClients) return;
  if(mpClients->empty()) return;
  if(pRef->pHostSet!=this) return;
  // provide fake const
  THIS* fake_const = const_cast< THIS* >(this);
#ifdef FAUDES_DEBUG_CODE
  // find and remove that client
  typename std::list< TBaseSet<T,Cmp>* >::iterator cit;
  bool cf=false;
  for(cit=fake_const->mpClients->begin(); cit!=fake_const->mpClients->end(); ++cit) {
    if(*cit==pRef) cf=true;
  }
  if(!cf) {
    FD_ERR("TBaseSet::DetachClient(" << this << "): client not found " << pRef);
    abort();
  }
#endif  
  /*
  use recorded client index: performant, and fine when last tested ...
  ... however, this really is asking for segfaults.

  // remove from client list
  FD_DC("TBaseSet::DetachClient(" << this << "):" << pRef << " must match " << *pRef->mClientRecord);
  fake_const->mpClients->erase(pRef->mClientRecord);
  */
  // remove from client list
  typename std::list< TBaseSet<T,Cmp>* >::iterator rit; 
  for(rit=fake_const->mpClients->begin(); rit!=fake_const->mpClients->end(); ++rit) {
    if(*rit!=pRef) continue;
    fake_const->mpClients->erase(rit);
    break; 
  }
  // figure detached status
  if(mpClients->empty() && (pSet!=&msEmptySet)) fake_const->mDetached=true;
  FD_DC("TBaseSet::DetachClient(" << this << "): done.");
}


// record an iterator
TEMP inline void THIS::AttachIterator(Iterator* pFit) const {
  if(mLocked) return;
  FD_DC("TBaseSet::AttachIterator(" << this << "):" << pFit)
  const_cast< THIS* >(this)->mIterators.insert(pFit);
}

// discard an iterator
TEMP inline void THIS::DetachIterator(Iterator* pFit) const {
  if(mLocked) return;
  FD_DC("TBaseSet::DetachIterator(" << this << "):" << pFit)
  const_cast< THIS* >(this)->mIterators.erase(pFit);
}

// test some validity
TEMP void THIS::DValid(const std::string& rMessage) const {
  typename std::set< Iterator* >::const_iterator iit;
  typename std::list< THIS* >::const_iterator rit;
#ifdef FAUDES_DEBUG_CONTAINER
  std::cerr << "TBaseSet(" << this << ")::DValid(): " << rMessage << " source " 
     << pHostSet << " " << (pHostSet->pSet==&msEmptySet ? "+e+" : "+f+") << 
        (mLocked ? " +l+" : " ") << (mDetached ? " +d+" : " ") << " -- refs ";
  if(pHostSet->mpClients)
  for(rit=pHostSet->mpClients->begin(); rit!=pHostSet->mpClients->end(); ++rit)
    std::cerr << *rit << " ";
  std::cerr << "-- its ";
  for(iit=mIterators.begin(); iit!=mIterators.end(); ++iit)
    std::cerr << *iit << " ";
  std::cerr << "-- attr #" << pAttributes->size();
  if(mpAttributes) std::cerr << "(" << mpAttributes->size() << ") ";
  else std::cerr << " ";
  std::cerr << (pAttributes==&msEmptyAttributes ? "+e+ " : "+f+ ") << std::endl;
#endif
  // iterators, that dont refer to me as basset
  for(iit=mIterators.begin(); iit!=mIterators.end(); ++iit) {
    if((*iit)->pBaseSet!=this) {
      FD_WARN("BaseSet("<< this << "," << rMessage <<"): invalid iterator (baseset): "<< *iit);
      abort();
    }
  }
  // iterators, that are not marked as attached
  for(iit=mIterators.begin(); iit!=mIterators.end(); ++iit) {
    if(!(*iit)->mAttached) {
      FD_WARN("BaseSet("<< this << "," << rMessage <<"): invalid iterator (attached): "<< *iit);
      abort();
    }
  }
  // iterators, that are invalid stl iterators
  for(iit=mIterators.begin(); iit!=mIterators.end(); ++iit) {
    typename std::set<T,Cmp>::const_iterator vit;
    for(vit=pSet->begin(); vit!= pSet->end(); ++vit) {
      if(vit==(**iit).StlIterator()) break;
    }
    if(vit!=(**iit).StlIterator()) { // end-iterator is fine, too
      FD_WARN("BaseSet("<< this << "," << rMessage <<"): invalid iterator (stl) "<< *iit);
      (**iit).StlIterator(pSet->end()); // fix invalid iterator to refer to end()
      abort(); // strict version: abort
    }
  }
  // must have some base 
  if(pHostSet==NULL) {
    FD_WARN("BaseSet(" << this << "," << rMessage << "): no host found");
    abort();
  }
  // hosts mut be consistent
  if(pHostSet->pHostSet != pHostSet) {
    FD_WARN("BaseSet(" << this << "," << rMessage << "): inconsistent host");
    abort();
  }
  // refers to other base and own data
  if((mpSet!=NULL) && (pHostSet != this)) {
    FD_WARN("BaseSet(" << this << "," << rMessage << "): double data");
    abort();
  }
  // refers to other base and has references
  if(pHostSet!=this && mpClients!=NULL) {
    FD_WARN("BaseSet(" << this << "," << rMessage << "): cannot be client and have clients oneself");
    abort();
  }
  // refers to invalid base 
  if(pHostSet->mpClients==NULL) {
    FD_WARN("BaseSet(" << this << "," << rMessage << "): refers to invalid host (a)");
    abort();
  }
  // refers to invalid base 
  if(pHostSet!=this && pHostSet->mpClients->empty()) {
    FD_WARN("BaseSet(" << this << "," << rMessage << "): refers to invalid host (b)");
    abort();
  }
  // is base but has no own data
  if((pHostSet == this) && (mpSet==NULL) && (pSet!=&msEmptySet)) {
    FD_WARN("BaseSet(" << this << "," << rMessage << "): no data");
    abort();
  }
  // is base, but has no client list
  if((pHostSet==this) && (pSet!=&msEmptySet) && (mpClients==NULL)) {
    FD_WARN("BaseSet(" << this << "," << rMessage << "): host with no client list");
    abort();
  }
  // is base but own data pointer mismatch
  if((pHostSet == this) && (pSet != mpSet) && (pSet!=&msEmptySet)) {
    FD_WARN("BaseSet(" << this << "," << rMessage << "): data pointer mismatch A");
    abort();
  }
  // refers to base with data pointer mismatch
  if(pSet != pHostSet->pSet) {
    FD_WARN("BaseSet(" << this << "," << rMessage << "): data pointer mismatch B");
    abort();
  }
  // test all clients from hosts list
  bool hf=false;
  for(rit=pHostSet->mpClients->begin(); rit!=pHostSet->mpClients->end(); ++rit) {
    if((*rit)== this) hf=true;
    if((*rit)->pHostSet== pHostSet) continue;
    FD_WARN("BaseSet(" << this << "," << rMessage << "): invalid client " << (*rit));
    abort();
  }
  if(!hf && (pHostSet!=this)) {
    FD_WARN("BaseSet(" << this << "," << rMessage << "): client not registered with host");
    abort();
  }
  // refers to invalid base 
  if(pHostSet!=this && *mClientRecord!=this) {
    FD_WARN("BaseSet(" << this << "," << rMessage << "): refers to invalid host (c)");
    abort();
  } 
  // error in detached flag
  if(mDetached && mpClients==NULL) {
    FD_WARN("BaseSet(" << this << "," << rMessage << "): invalid detached flag A");
    abort();
  }
  // error in detached flag
  if(mDetached && !mpClients->empty()) {
    FD_WARN("BaseSet(" << this << "," << rMessage << "): invalid detached flag B");
    abort();
  }
  // error in detached flag
  if(mDetached && (pSet==&msEmptySet)) {
    FD_WARN("BaseSet(" << this << "," << rMessage << "): detached empty set");
    abort();
  }
  // error in lock flag
  if(mLocked && (mpClients==NULL)) {
    FD_WARN("BaseSet(" << this << "," << rMessage << "): locked reference (a)");
    abort();
  }
  // invalid emptyset
  if(!msEmptySet.empty()) {
    FD_WARN("BaseSet(" << this << "," << rMessage << "): invalid empty set");
    abort();
  }
  // invalid emptyset
  if(!msEmptyAttributes.empty()) {
    FD_WARN("BaseSet(" << this << "," << rMessage << "): invalid empty attributes");
    abort();
  }
#ifdef FAUDES_DEBUG_CONTAINER
  std::cerr << "TBaseSet(" << this << ")::DValid(): passed" << std::endl;
#endif
}



// Name
TEMP const std::string& THIS::Name(void) const {
  return mMyName;
}
		
// Name
TEMP void THIS::Name(const std::string& rName) {
  mMyName = rName;
}
  

// TypeDefinitionp()
// Note: fake const construct
TEMP const TypeDefinition* THIS::TypeDefinitionp(void) const {
  if(!pTypeDefinition) {
    // provide fake const
    THIS* fake_const = const_cast< THIS* >(this);
    fake_const->pTypeDefinition=TypeRegistry::G()->Definitionp(*this);
  }
  return pTypeDefinition;
}

// ElementTag
TEMP const std::string& THIS::XElementTag(void) const {
  if(mXElementTag.empty()) {
    // provide fake const
    THIS* fake_const = const_cast< THIS* >(this);
    fake_const->mXElementTag="Element";
    const TypeDefinition* fdp=TypeDefinitionp();
    if(fdp) fake_const->mXElementTag=fdp->XElementTag();
  }
  return mXElementTag;
}

// ElementTag
TEMP void THIS::XElementTag(const std::string& rTag) {
  mXElementTag=rTag;
}


// Faudes Type
TEMP const std::string& THIS::TypeName(void) const {
  if(mFaudesTypeName.empty()) {
    // provide fake const
    THIS* fake_const = const_cast< THIS* >(this);
    const TypeDefinition* fdp=TypeDefinitionp();
    if(fdp) fake_const->mFaudesTypeName=fdp->Name();
  }
  return mFaudesTypeName;
}

// ElementTag
TEMP void THIS::TypeName(const std::string& rType) {
  mFaudesTypeName=rType;
}


// Str
TEMP std::string THIS::Str(const T& rElem) const { 
  (void) rElem;
  std::string res=""; 
  return res; 
}

// Size()
TEMP Idx THIS::Size(void) const {
  return (Idx) pSet->size();
}

// Empty()
TEMP bool THIS::Empty(void) const {
  return pSet->empty();
}


// DoWrite(tw,rLabel,cpntext)
TEMP void THIS::DoWrite(TokenWriter& rTw,const std::string& rLabel, const Type* pContext) const {
  (void) pContext;
  std::string label=rLabel;
  if(label=="") label=Name(); 
  if(label=="") label="BaseSet"; 
  FD_DC("TBaseSet(" << this << ")::DoWrite(..): section " << label << " #" << Size());
  rTw.WriteBegin(label);
  rTw.WriteEnd(label);
}


// DoDWrite(tw, label, context)
TEMP void THIS::DoDWrite(TokenWriter& rTw, const std::string& rLabel, const Type* pContext) const {
  (void) pContext;
  (void) rLabel;
  BASE::DoSWrite(rTw);
  size_t shares=0;
  if(pHostSet->mpClients) shares=pHostSet->mpClients->size();
  rTw.WriteComment("");
  rTw.WriteComment(" Size/Attributes: " + ToStringInteger(this->Size()) 
		   + "/" + ToStringInteger((Idx) pHostSet->pAttributes->size()));
  rTw.WriteComment(" Shares/Iterators: " + ToStringInteger((Idx) shares) 
		   + "/" + ToStringInteger((Idx) mIterators.size()));
  rTw.WriteComment("");
#ifdef FAUDES_DEBUG_CODE
  DValid();
#endif
}

// DoSWrite()
TEMP void THIS::DoSWrite(TokenWriter& rTw) const {
  BASE::DoSWrite(rTw);
  size_t shares=0;
  if(pHostSet->mpClients) shares=pHostSet->mpClients->size();
  rTw.WriteComment(" Size: " + ToStringInteger(this->Size()));
  rTw.WriteComment(" Shared Data: #" + ToStringInteger((Idx) shares) + " clients");
  if(pAttributes->size()!=0)
    rTw.WriteComment(" Attributes: " +ToStringInteger((Idx) pAttributes->size()));
  if(pAttributes->size()!=0) {
    AttributeVoid* attr = pAttributes->begin()->second;
    rTw.WriteComment(" Attribute Type: " +FaudesTypeName(*attr));
  } 
}

// DoRead(rTr, rLabel, pContext)
TEMP void THIS::DoRead(TokenReader& rTr, const std::string& rLabel, const Type* pContext) {
  (void) pContext;
  std::string label=rLabel;
  if(label=="") label=Name(); 
  if(label=="") label="BaseSet"; 
  Name(label);
  rTr.ReadBegin(label); 
  rTr.ReadEnd(label); 
}

// ThisIterator (tmoor 201308: this is by default an attached iterator)
TEMP typename THIS::Iterator THIS::ThisIterator(const typename std::set<T,Cmp>::const_iterator& sit) const {
  return Iterator(this,sit,true);
}

// Begin() const
TEMP inline typename THIS::Iterator THIS::Begin(void) const {
  return ThisIterator(pSet->begin());
}
		
// End() const
TEMP inline typename THIS::Iterator THIS::End(void) const {
  return ThisIterator(pSet->end());
}


//Clear
TEMP void THIS::Clear(void) {
  FD_DC("TBaseSet(" << this << ")::Clear()");
#ifdef FAUDES_DEBUG_CODE
  DValid("PreClear");
#endif
  // special case: empty anyway
  if(pSet==&msEmptySet) return;

  FD_DC("TBaseSet(" << this << ")::Clear(): doit");
  FD_DC("TBaseSet(" << this << ")::Clear(): type " << typeid(*this).name());
  // special case: locked requires a copy (not efficient!)
  if(mLocked) Detach(SetOnly);
  // make someone else handle the data
  RelinkClients();
  pHostSet->DetachClient(this);
  // make myself host
  pHostSet=this;
  if(!mpClients) mpClients= new std::list< TBaseSet<T,Cmp>* >;
  mpClients->clear();
  // if we hold data, clear it
  if(mpSet) {
    delete mpSet;
    mpSet=NULL;
  }
  // if we hold data, clear it
  if(mpAttributes) {
    for(aiterator ait=mpAttributes->begin(); ait!=mpAttributes->end(); ++ait) {
       FD_DC("TBaseSet(" << this << ")::Clear(): del attr " << ait->second);
       delete ait->second;
    }
    delete mpAttributes;
    mpAttributes=NULL;
  }
  // set to empty set
  pSet=&msEmptySet;
  pAttributes=&msEmptyAttributes;
  // fix iterators (invalidate)
  typename std::set< Iterator* >::iterator iit;
  for(iit=mIterators.begin(); iit!=mIterators.end(); ++iit) {
    (**iit).Invalidate();
  }
  mIterators.clear();
  mDetached=false;
  mLocked=false;
#ifdef FAUDES_DEBUG_CODE
  DValid("PostClear");
#endif
  FD_DC("TBaseSet(" << this << ")::Clear(): done");
}


//Valid(elem)
TEMP inline bool  THIS::Valid(const T& rElem) const {
  (void) rElem;
  return true;
}

//Insert(elem)
TEMP bool THIS::Insert(const T& rElem) {
#ifdef FAUDES_CHECKED
  if(!Valid(rElem)) {
    std::stringstream errstr;
    errstr << "refuse to insert invalid element" << std::endl;
    throw Exception("BaseSet::Insert", errstr.str(), 61);
  }
#endif
  if(!mDetached) Detach();
  return pSet->insert(rElem).second;
}

//Inject(elem)
TEMP typename THIS::Iterator  THIS::Inject(const Iterator& pos, const T& rElem) {
  if(!mDetached) Detach();
  iterator dst= pos.StlIterator(); 
  return ThisIterator(pSet->insert(dst,rElem));
}


//Inject(elem)
TEMP void THIS::Inject(const T& rElem) {
  if(!mDetached) Detach();
  pSet->insert(pSet->end(),rElem);
}

// InsertSet(set)
TEMP void THIS::InsertSet(const TBaseSet& rOtherSet) {
  FD_DC("TBaseSet(" << this << ")::InsertSet(" << &rOtherSet << ")");
  if(!mDetached) Detach();
  /*
  rm: cannot use stl since result overlaps with arguments

  std::insert_iterator< std::set<T,Cmp> > insit(*pSet, rpSet->begin());
  std::set_union(pSet->begin(), pSet->end(), rOtherSet.pSet->begin(), rOtherSet.pSet->end(), insit);
  */
  iterator it1 = pSet->begin();
  iterator it2 = rOtherSet.pSet->begin();
  while ((it1 != pSet->end()) && (it2 != rOtherSet.pSet->end())) {
    if (*it1 < *it2) {
      ++it1;
    }
    else if (*it1 == *it2) {
      ++it1;
      ++it2;
    }
    else { // (*it1 > *it2)
      pSet->insert(*it2);
      ++it2;
    }
  }
  while (it2 != rOtherSet.pSet->end()) {
    pSet->insert(*it2);
    ++it2;
  }
}

		
//Erase(rElem)
TEMP bool THIS::Erase(const T& rElem) {
  if(!mDetached) Detach();
  return (pSet->erase(rElem)!=0);
}


//Erase(pos)
TEMP typename THIS::Iterator THIS::Erase(const Iterator& pos) { 
#ifdef FAUDES_CHECKED
  if (pos == End()) {
    std::stringstream errstr;
    errstr << "iterator out of range " << std::endl;
    throw Exception("BaseSet::Erase", errstr.str(), 62);
  }
#endif
  Detach();
  iterator del= pos.StlIterator(); 
  pSet->erase(del++);
  return ThisIterator(del); 
}


//EraseSet(set)
TEMP void THIS::EraseSet(const TBaseSet& rOtherSet) {
  FD_DC("TBaseSet(" << this << ")::EraseSet(" << &rOtherSet << ")");
  if(!mDetached) Detach();
  // TODO: test and optimize 
  iterator it = pSet->begin();
  iterator oit = rOtherSet.pSet->begin();
  while ((it != pSet->end()) && (oit != rOtherSet.pSet->end())) {
    if (*it < *oit) {
      it=pSet->lower_bound(*oit); // alt: ++it;
    }
    else if (*it == *oit) { 
      ++oit;
      pSet->erase(it++);
    }
    else { // (*it > *oit)
      oit=rOtherSet.pSet->lower_bound(*it); // ++it2;
    }
  }
}


//RestrictSet(set)
TEMP void THIS::RestrictSet(const TBaseSet& rOtherSet) {
  FD_DC("TBaseSet(" << this << ")::RestrictSet(" << &rOtherSet << ")");
  if(!mDetached) Detach();
  // TODO: test and optimize 
  iterator it = pSet->begin();
  iterator oit = rOtherSet.pSet->begin();
  while ((it != pSet->end()) && (oit != rOtherSet.pSet->end())) {
    if (*it < *oit) {
      pSet->erase(it++);
    }
    else if (*it == *oit) { 
      ++it;
      ++oit;
    }
    else { // (*it > *oit)
      oit=rOtherSet.pSet->lower_bound(*it); 
    }
  }
  while(it != pSet->end()) {
    pSet->erase(it++);
  }
}


//Disjoint(set)
TEMP bool THIS::Disjoint(const TBaseSet& rOtherSet) const {
  FD_DC("TBaseSet(" << this << ")::Disjoint(" << &rOtherSet << ")");
  // trivial cases
  if(pSet->empty()) return true;
  if(rOtherSet.pSet->empty()) return true;
  if(*pSet->rbegin()<*rOtherSet.pSet->begin()) return true;
  if(*rOtherSet.pSet->rbegin()<*pSet->begin()) return true;
  if(rOtherSet.pSet==pSet) return false;
  // iterate
  iterator it = pSet->begin();
  iterator oit = rOtherSet.pSet->begin();
  while ((it != pSet->end()) && (oit != rOtherSet.pSet->end())) {
    if (*it < *oit) { it++; continue;}
    if (*it == *oit) { return false; }
    // if (*it > *oit)
    oit++;
  }
  return true;
}

//Find(elem)
TEMP typename THIS::Iterator THIS::Find(const T& rElem) const {
  return ThisIterator(pSet->find(rElem));
}

//Exists(elem)
TEMP bool  THIS::Exists(const T& rElem) const {
  return pSet->find(rElem) != pSet->end();
}


// operator+
TEMP THIS THIS::operator+ (const TBaseSet& rOtherSet) const {
  TBaseSet res(*this);
  res.InsertSet(rOtherSet);
  return res;
}

// operator-
TEMP THIS THIS::operator- (const TBaseSet& rOtherSet) const {
  TBaseSet res(*this);
  res.EraseSet(rOtherSet);
  return res;
}

     
// operator*
TEMP THIS THIS::operator* (const TBaseSet& rOtherSet) const {
  TBaseSet res(*this);
  res.RestrictSet(rOtherSet);
  return res;
}


// operator==
TEMP bool THIS::DoEqual(const TBaseSet& rOtherSet) const {
  FD_DC("TBaseSet::DoEqual()");
  // true if we share anyway
  if(pSet == rOtherSet.pSet) return true;
  // compare sets
  return  ( *pSet == *rOtherSet.pSet );
}

// operator<=
TEMP bool THIS::operator<= (const TBaseSet& rOtherSet) const {
  FD_DC("BaseSet::op<=()");
  return ( std::includes(rOtherSet.pSet->begin(), rOtherSet.pSet->end(), pSet->begin(), pSet->end()) ) ;
}

// operator>=
TEMP bool THIS::operator>= (const TBaseSet& rOtherSet) const {
  FD_DC("BaseSet::op>=()");
  return ( std::includes(pSet->begin(), pSet->end(), rOtherSet.pSet->begin(), rOtherSet.pSet->end()) );
}

// operator<
TEMP bool THIS::operator< (const TBaseSet& rOtherSet) const {
  return *pSet < *rOtherSet.pSet;
}


// attribute typeinfo
TEMP const AttributeVoid* THIS::AttributeType(void) const { 
  static AttributeVoid attr; 
  return & attr; 
}

// test attribute type
TEMP bool THIS::AttributeTest(const Type& rAttr) const {
  return AttributeType()->Cast(&rAttr)!=NULL;
}

// number of attributes
TEMP Idx THIS::AttributesSize(void) const {
  return (Idx) pAttributes->size();
}

// clear attributes
TEMP void THIS::ClearAttributes(void) {
  // bail out if there are no attributes anyway
  if(this->pAttributes->size()==0) return;
  // detach (this will copy the set if required and return with empty attributes)
  this->Detach(SetOnly);
}


// Implement attributes: equality
TEMP bool THIS::EqualAttributes(const TBaseSet<T,Cmp>& rOtherSet) const {
  FD_DC("TBaseSet::EqualAttributes(TBaseSet)");
  // false, if type does not match
  FD_DC("TBaseSet::EqualAttributes(TBaseSet): 1");
  if(typeid(*rOtherSet.AttributeType())!=typeid(*this->AttributeType())) 
    return false;
  // true, if we share attribute data
  FD_DC("TBaseSet::EqualAttributes(TBaseSet): 2");
  if(pAttributes==rOtherSet.pAttributes)
    return true;
  // true if there are no attributes
  FD_DC("TBaseSet::EqualAttributes(TBaseSet): 3");
  if(rOtherSet.AttributesSize()==0)
  if(this->AttributesSize()==0)
    return true;
  // figure shared elements and test for equal attributes
  aiterator ait1 = pAttributes->begin();
  aiterator ait2 = rOtherSet.pAttributes->begin();
  while ((ait1 != pAttributes->end()) && (ait2 != rOtherSet.pAttributes->end())) {
    if (ait1->first < ait2->first) {
      ++ait1;
    }
    else if (ait1->first == ait2->first) {
      FD_DC("TBaseSet::EqualAttributes(TBaseSet): cmp " << ait1->second->ToString() 
	      << " vs " << ait2->second->ToString());
      if( ! ait1->second->Equal(*ait2->second)) return false;
      ++ait1;
      ++ait2;
    }
    else { // (*it1 > *it2)
      ++ait2;
    }
  }
  // passed
  FD_DC("TBaseSet::EqualAttributes(TBaseSet): pass");
  return true;
}



// public wrapper
TEMP THIS& THIS::AssignWithoutAttributes(const TBaseSet<T,Cmp>& rSourceSet) {
  // call virtual (fake copy, will only copy attributes on type match)
  this->DoAssign(rSourceSet);
  // detach, effectively clears attributes
  this->Detach(SetOnly);
  return *this;
}

// set attribute wrapper
TEMP void THIS::Attributes(const TBaseSet<T,Cmp>& rOtherSet) {
  FD_DC("TBaseSet::Attributes("<<this<<")");
  // type mismatch
  if(!this->AttributeTest(*rOtherSet.AttributeType())) {
    std::stringstream errstr;
    errstr << "cannot cast attribute " << std::endl;
    throw Exception("TBaseSet::Attributes(otherset)", errstr.str(), 63);
  }
  // can not hold attributes anyway
  if(typeid(*this->AttributeType())== typeid(const AttributeVoid)) return;
  // do assign 
  this->Detach(AttrIncl);
  iterator it1 = pSet->begin();
  iterator it2 = rOtherSet.pSet->begin();
  while ((it1 != pSet->end()) && (it2 != rOtherSet.pSet->end())) {
    if (*it1 < *it2) {
      ++it1;
    }
    else if (*it1 == *it2) {
      DoAttribute(*it1,&rOtherSet.Attribute(*it2)); 
      ++it1;
      ++it2;
    }
    else { // (*it1 > *it2)
      ++it2;
    }
  }
  FD_DC("TBaseSet::Attributes(): copy ok");
}



// attribute access
TEMP AttributeVoid* THIS::Attributep(const T& rElem) { 
  (void) rElem;
  std::stringstream errstr;
  errstr << "cannot get attribute for TBaseSet \"" << mMyName  << "\" type " << typeid(*this).name();
  throw Exception("TBaseSet::Attributep(rElem)", errstr.str(), 63);  
  // dummy: will through exception before
  static AttributeVoid attr; 
  return &attr; 
}

// attribute access
TEMP const AttributeVoid& THIS::Attribute(const T& rElem) const { 
  (void) rElem;
  static AttributeVoid attr; 
  return attr;
}

// attribute access
TEMP void THIS::Attribute(const T& rElem, const Type& rAttr) {
  (void) rElem;
  /* its pointless to test existence of the element since we wont set any attribute anyway */
#ifdef FAUDES_CHECKED
  if (!Exists(rElem)) {
    std::stringstream errstr;
    errstr << "element not member of set" << std::endl;
    throw Exception("TBaseSet::Attribute(elem,attr)", errstr.str(), 60);
  }
#endif
  if(!AttributeTest(rAttr)) {
    std::stringstream errstr;
    errstr << "cannot cast attribute " << std::endl;
    throw Exception("TBaseSet::Attribute(elem,attr)", errstr.str(), 63);
  }
  // passes test for all childs of AttributeVoid
}


// clr attributes wrapper  
TEMP void THIS::ClrAttribute(const T& rElem) {
  this->Detach();
  DoAttribute(rElem,(const AttributeVoid*) NULL);
}


// implement attributes: get pointer, NULL for implicit default
TEMP const AttributeVoid* THIS::DoAttribute(const T& rElem) const {
  const_aiterator ait;
  ait=this->pAttributes->find(rElem);
  if(ait==this->pAttributes->end()) return NULL;
  return ait->second;
} 

// implement attributes: get pointer (assume detached)
TEMP AttributeVoid* THIS::DoAttributeExplicit(const T& rElem) {
  FD_DC("TBaseSet::DoAttributeExplicit(elem)");
#ifdef FAUDES_DEBUG_CODE
  if(this->pAttributes!=this->::mpAttributes) {
    FD_ERR("TBaseSet::DoAttributeExplicit(elem): attributes not detached");
    abort();
  }
#endif
  aiterator ait;
  ait=this->pAttributes->find(rElem);
  if(ait!=this->pAttributes->end())
  return ait->second;
  // instantiate explicit default
  AttributeVoid* attr = this->AttributeType()->Copy();
  FD_DC("TBaseSet::DoAttributeExplicit(Elem): inserting explicit default " << attr << " type " << typeid(*attr).name());
  (*this->pAttributes)[rElem]=attr;
  return attr;
} 

// implement attributes: set  (assume detached)
TEMP void THIS::DoAttribute(const T& rElem, const Type* pAttr) {
  FD_DC("TBaseSet::DoAttribute([v] " << this->Str(rElem) << ", ...)");
#ifdef FAUDES_DEBUG_CODE
  if(this->pAttributes!=this->mpAttributes) {
    FD_ERR("TBaseSet::DoAttribute([v] set): attributes not detached");
    abort();
  }
#endif
  // type check new attribute
  const AttributeVoid* newattr=dynamic_cast<const AttributeVoid*>(pAttr);
  if(!this->AttributeType()->Cast(pAttr)) newattr=NULL; 
  // find element in map  
  aiterator ait;
  AttributeVoid* oldattr=NULL;
  ait=this->pAttributes->find(rElem);
  if(ait!=this->pAttributes->end() ) 
    oldattr=ait->second;
  // set to default, case 1
  if(newattr==NULL) {
    FD_DC("TBaseSet::DoAttribute([v] " << this->Str(rElem) << ", ...): default 1");
    if(oldattr==NULL) return;
    delete oldattr;
    this->pAttributes->erase(ait);
    return;
  }  
  // set to default, case 2
  if(newattr->IsDefault()) {
    FD_DC("TBaseSet::DoAttribute([v] " << this->Str(rElem) << ", ...): default 2");
    if(oldattr==NULL) return;
    delete oldattr;
    this->pAttributes->erase(ait);
    return;
  }  
  FD_DC("TBaseSet::DoAttribute([v] " << this->Str(rElem) << ", ...): " << newattr->ToString());
  // prepare attribute and set
  if(oldattr==NULL) {
    AttributeVoid* attr = this->AttributeType()->New();
    attr->Assign(*newattr);
    (*this->pAttributes)[rElem]=attr;
    return;
  }
  // plain set     
  FD_DC("TBaseSet::DoAttribute([v] " << this->Str(rElem) << ", ...): " << newattr->ToString());
  oldattr->Assign(*newattr);
}


/* undefine local shortcuts */
#undef THIS
#undef TEMP
#undef BASE

/** @} doxygen group */

} // namespace faudes

#endif 
