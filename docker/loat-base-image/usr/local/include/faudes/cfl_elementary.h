/** @file cfl_elementary.h Runtime interface, elementary types */

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


#ifndef FAUDES_ELEMENTARY_H
#define FAUDES_ELEMENTARY_H

#include "cfl_types.h"
#include "cfl_functions.h"
#include "cfl_basevector.h"



namespace faudes {



/*
********************************************************************
********************************************************************
********************************************************************

Elementary type, representing an integer value.

********************************************************************
********************************************************************
********************************************************************
*/

/** Elementary type */
class FAUDES_API Integer : public Type {

 public:
  /** Constructor */
  Integer(void);

  /**
   * Constructor provided with initial value.
   *
   * @param val
   * 	Initial value.
   */
  Integer(Int val);

  /** Destructor */
  ~Integer(void){}

  /**
   * Construct on heap.
   * Create new Integer instance and return pointer.
   *
   * @return
   * 	Pointer to Integer instance.
   *
   */
  virtual Integer* New(void) const;

  /**
   * Construct copy on heap.
   * Create new Integer instance and return pointer.
   *
   * @return
   * 	Pointer to Integer instance.
   *
   */
  virtual Integer* Copy(void) const;

  /**
   * Cast the other object to Integer.
   * Returns NULL if the cast is not possible.
   *
   * @param pOther
   *    Pointer to object to cast.
   * @return
   * 	Pointer to Integer instance, or NULL
   *
   */
  virtual const Integer* Cast(const Type* pOther) const;

  /**
   * Set value.
   *
   * @param val
   * 	Value to be set.
   */
  void CValue(Int val);

  /**
   * Get value.
   *
   * @return
   * 	Value of object. (Int)
   */
  Int CValue(void) const;

  /**
   * Get reference.
   *
   * @return
   * 	Reference to c value.
   */
  Int* CReference(void);

  /**
   * Sum operator.
   */
  Integer& operator+ (const Int& clint){
    CValue(mCInteger + clint);
    return *this;
  }

  /**
   * Sum operator.
   */
  Integer& operator+ (const Integer& coint){
    CValue(mCInteger + coint.CValue());
    return *this;
  }

  /**
   * Assignment operator.
   */
  Integer& operator= (const Int& clint){
    CValue(clint);
    return *this;
  }

  /**
   * Assignment operator.
   */
  Integer& operator= (const Integer& coint){
    CValue(coint.CValue());
    return *this;
  }

  /**
   * Assignment/Sum operator
   */
  Integer& operator+= (const Int& clint){
    Int litmp = CValue();
    CValue(litmp + clint);
    return *this;
  }

  /**
   * Assignment/Sum operator
   */
  Integer& operator+= (const Integer& coint){
    Int litmp = CValue() + coint.CValue();
    CValue(litmp);
    return *this;
  }

  /**
   * Conversion to C++ type 
   */
  operator Int() const { return CValue();};


  /**
   * Reimplementation of faudes::Type::DoWrite()
   * Write data to Tokenwriter.
   *
   * @param rTw
   * 	Reference to TokenWriter.
   * @param rLabel
   * 	Label of section to write.
   * @param pContext
   *    Context information
   *
   * @exception Exception
   * 	- IO Error (id 2)
   */
  void DoWrite(TokenWriter& rTw, const std::string& rLabel = "", const Type* pContext=0) const;

  /**
   * Read data from TokenReader.
   *
   * @param rTr
   * 	Reference to TokenReader.
   * @param rLabel
   * 	Section to read.
   * @param pContext
   *    Context information
   *
   * @exception Exception
   * 	- Token mismatch
   * 	- IO Error
   */
  void DoRead(TokenReader& rTr,  const std::string& rLabel = "", const Type* pContext=0);

 protected:

  /** Variable to store current value. */
  Int mCInteger;

}; // Integer

// convenience typedef
typedef TBaseVector<Integer> IntegerVector;

// Sum of two integers, uniform rti api 
extern FAUDES_API long int IntegerSum(const Integer& arg1, const Integer& arg2); 

// Sum of multiple integers, uniform rti api 
extern FAUDES_API long int IntegerSum(const IntegerVector& intvect); 

/*
********************************************************************
********************************************************************
********************************************************************

Elementary type, representing a string value.

********************************************************************
********************************************************************
********************************************************************
*/

/** Elementary type */
class FAUDES_API String : public Type{

 public:
  /** Constructor */
  String(void);

  /**
   * Constructor provided with initial value.
   *
   * @param val
   * 	Initial value.
   */
  String(std::string val);

  /** Destructor */
  ~String(void){}

  /**
   * Construct on heap.
   * Create new String instance and return pointer.
   *
   * NOTE:
   * Calling function takes control.
   *
   * @return
   * 	Pointer to String instance.
   */
  virtual String* New(void) const;

  /**
   * Construct copy on heap.
   * Create new String instance and return pointer.
   *
   * @return
   * 	Pointer to Integer instance.
   *
   */
  virtual String* Copy(void) const;

  /**
   * Cast the other object to String.
   * Returns NULL if the cast is not possible.
   *
   * @param pOther
   *    Pointer to object to cast.
   * @return
   * 	Pointer to String instance, or NULL
   *
   */
  virtual const String* Cast(const Type* pOther) const;

  /**
   * Set value.
   *
   * @param val
   * 	Value to be set. (std::string)
   */
  void CValue(std::string val);

  /**
   * Get value
   *
   * @return
   * 	Value of object. (std::string)
   */
  std::string CValue(void) const;

  /**
   * Get reference.
   *
   * @return
   * 	Reference to c value.
   */
  std::string* CReference(void);

  /**
   * Assignment operator.
   */
  String& operator= (const String& costr){
    CValue(costr.CValue());
    return(*this);
  }

  /*
   * Assignment operator, std::string source
   */
  String& operator= (const std::string& cstr){
    CValue(cstr);
    return(*this);
  }

  /**
   * Conversion to std::string
   */
  operator std::string() const { return CValue();};


  /**
   * Write data to Tokenwriter.
   *
   * @param rTw
   * 	Reference to TokenWriter.
   * @param rLabel
   * 	Label of section to write.
   * @param pContext
   *    Write context to provide contextual information (ignored)
   *
   * @exception Exception
   * 	- IO Error
   */
  void DoWrite(TokenWriter& rTw, const std::string& rLabel = "", const Type* pContext=0) const;


  /**
   * Read data from TokenReader.
   *
   * @param rTr
   * 	Reference to TokenReader.
   * @param rLabel
   * 	Section to read.
   * @param pContext
   *   Read context to provide contextual information (ignored)
   *
   * @exception Exception
   * 	- Token mismatch
   * 	- IO Error
   */
  void DoRead(TokenReader& rTr,  const std::string& rLabel = "", const Type* pContext=0);

 protected:
  /** Variable to store current value. */
  std::string mCString;

}; // String




/*
********************************************************************
********************************************************************
********************************************************************

Elementary type, representing a boolean value.

********************************************************************
********************************************************************
********************************************************************
*/

/** Elementary type */
class FAUDES_API Boolean : public Type{

 public:
  /** Constructor */
  Boolean(void);

  /**
   * Constructor provided with initial value.
   *
   * @param val
   * 	Initial value. (bool)
   */
  Boolean(bool val);

  /** Destructor */
  ~Boolean(void){}

  /**
   * Construct on heap.
   * Create new Boolean instance and return pointer.
   *
   * NOTE:
   * Calling function takes control.
   *
   * @return
   * 	Pointer to Boolean instance.
   */
  virtual Boolean* New(void) const;

  /**
   * Construct copy on heap.
   * Create new Boolean instance and return pointer.
   *
   * @return
   * 	Pointer to Boolean instance.
   *
   */
  virtual Boolean* Copy(void) const;

  /**
   * Cast the other object to Boolean.
   * Returns NULL if the cast is not possible.
   *
   * @param pOther
   *    Pointer to object to cast.
   * @return
   * 	Pointer to Boolean instance, or NULL
   *
   */
  virtual const Boolean* Cast(const Type* pOther) const;

  /**
   * Set value.
   *
   * @param val
   * 	Value to be set.
   */
  void CValue(bool val);

  /**
   * Get value.
   *
   * @return
   * 	Value of object. (bool)
   */
  bool CValue(void) const;

  /**
   * Get reference.
   *
   * @return
   * 	Reference to c value.
   */
  bool* CReference(void);

  /**
   * Assignment operator.
   */
  Boolean& operator= (const bool& bbool){
    CValue(bbool);
    return(*this);
  }

  /**
   * Assignment operator.
   */
  Boolean& operator= (const Boolean& cobool){
    CValue(cobool.CValue());
    return(*this);
  }


  /**
   * Conversion to C++ type bool
   */
  operator bool() const { return CValue();};

  /**
   * Write data to Tokenwriter.
   *
   * NOTE:
   * 0 = false
   * 1 = true
   *
   * @param rTw
   * 	Reference to TokenWriter.
   * @param rLabel
   * 	Label of section to write.
   * @param pContext
   *    Write context to provide contextual information (ignored)
   *
   * @exception Exception
   * 	- IO Error
   */
  void DoWrite(TokenWriter& rTw, const std::string& rLabel = "", const Type* pContext=0) const;

  /**
   * Read data from TokenReader.
   *
   * NOTE:
   * 0 = false
   * 1 = true
   *
   * @param rTr
   * 	Reference to TokenReader.
   * @param rLabel
   * 	Section to read.
   * @param pContext
   *   Read context to provide contextual information (ignored)
   *
   * @exception Exception
   * 	- Token mismatch
   * 	- IO Error
   */
  void DoRead(TokenReader& rTr,  const std::string& rLabel = "", const Type* pContext=0);

 protected:

  /** Variable to store current value. */
  bool mCBool;

}; // Boolean



} // namespace

#endif 
