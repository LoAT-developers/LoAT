/** @file cfl_functions.h Runtime interface, operations on faudes types */

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


#ifndef FAUDES_RTIFNCTS_H
#define FAUDES_RTIFNCTS_H

// todo: fix/hide copy constructor

#include "cfl_types.h"

namespace faudes{

/**
 * Structure to model a parameter type within the Signature of a 
 * Function.
 * A Parameter is made of a descriptive name, a faudes type and
 * an io-attribute. The latter specifies whether the parameter 
 * is a const argument (<tt>In</tt>), a result (<tt>Out</tt>) or a both-ways 
 * parameter (<tt>InOut</tt>). To support the code generators of the run-time-interface,
 * you may use the CReturn  flag to indicate that the parameter is implemented 
 * as the return value in the corresponding C function. The current version of the
 * code generators will handle this case for the elementary types Integer, Boolean and
 * String. They will, however, fail on any other faudes types. 
 */

class FAUDES_API Parameter {

 public:

  /**
   * A function parameter has has one out of four so called io-attrributes;
   */
  enum ParamAttr{
    In,    //// Input parameter, aka argument, remains constant while execution
    Out,   //// Output parameter, aka result, is generated during function execution
    InOut, //// InOut parameter, is interpreted and possibly altered during execution
    UnDef  //// UnDef parameter indicates unconfigured signature
  };

  /** Constructor, default */
  Parameter(void);

  /** Constructor, by member values */
  Parameter(const std::string& rName, const std::string& rTypeName, 
	    ParamAttr attr=UnDef, bool cret=false);

  /** Desctructor */
  ~Parameter(void);

  /** 
   * Get name
   *
   * @return
   *   Name of parameter
   */
  const std::string& Name(void) const;

  /** 
   * Set name
   *
   * @param rName
   *   New name of parameter
   */
  void Name(const std::string& rName);

  /** 
   * Get type
   *
   * @return
   *   Faudes type  of parameter
   */
  const std::string& Type(void) const;

  /** 
   * Set type
   *
   * @param rTypeName
   *   New faudes type  of parameter
   */
  void Type(const std::string& rTypeName);

  /** 
   * Get Attribute
   *
   * @return
   *   In/Out/InOut attribute of parameter.
   */
  const ParamAttr& Attribute(void) const;

  /** 
   * Set Attribute
   *
   * @param rAttr
   *   In/Out/InOut attribute of parameter.
   */
  void Attribute(const ParamAttr& rAttr);

  /** 
   * Set Attribute by string.
   * Convenience method, defaults to UnDef.
   *
   * @param rAttrStr
   *   In/Out/InOut attribute of parameter.
   */
  void Attribute(const std::string& rAttrStr);

  /** 
   * Get C-Return flag.
   *
   * @return
   *   C-Return flag
   */
  bool CReturn(void) const;

  /** 
   * Set C-Return flag.
   *
   * @param cret
   *   New value of C-Return flag.
   */
  void CReturn(bool cret);

  /**
   * Convenience method to produce a textual representation of an io attribute.
   *
   * @param attr
   * 	Enum value denoting the attribute.
   * @return
   * 	Parameter IO attribute as std::string
   */
  static std::string AStr(Parameter::ParamAttr attr);

  /**
   * Convenience method to produce a textual representation of a parameter.
   *
   */
  std::string Str(void) const;

  /**
   * Set to "undefined"
   */
  void Clear();

  /**
   * Test equality
   *
   * @param rOther
   *   Other signature to compare with.
   */  
  bool operator==(const Parameter& rOther) const;

protected:

  /** Name */
  std::string mName;

  /** Faudes type */
  std::string mTDName;

  /** IO-Attribute */
  ParamAttr mAttr;

  /** C-Return flag */
  bool mCReturn;

}; // Parameter




/**
 * Signature of a Function.
 * 
 * A Signature describes the faudes types of the positional
 * parameters. Tecnically, a Signature is a vector of Parameters.
 * Each Function may execute serveral variants indicated by setting
 * a particular Signature. A list of valid Signatures is maintained in 
 * the coresponding FunctionDefinition.
 *
 * Core members are
 * - mName: string to identify ths signature
 * - mParameters: vector of Paramters. 
 *
 * The Signature is formally derived from Type to inherit the std token io
 * interface. It is not meant to be registered as a faudes type.
 * The token io format is demonstrated by the following example:
 *
 * @code
 *	<Signature name="Sum of two integers">
 *	<Parameter name="arg1" ftype="Integer"   access="InOut"/>
 *	<Parameter name="arg2" ftype="Integer"   access="In"/>
 *	<Parameter name="res"  ftype="String"    access="Out" creturn="true"/>
 *	</Signature>
 * @endcode
 *
 * Technical note: the variable parameter feature offered by FunctionDefinition is a purely
 * cosmetic hack implemented in FunctionDefinition:MergeDocumentation. It is superseeded
 * by vector parameters and will hence disappear in a future implementation.
 */

class FAUDES_API Signature : public Type {

  // std faudes type interface 
  FAUDES_TYPE_DECLARATION(Void,Signature,Type)

public:

  /** Constructor */
  Signature(void);

  /** Copy constructor */
  Signature(const Signature& rSrc);

  /** Destructor */
  ~Signature(void){};

  /**
   * Return signature name.
   *
   * @return
   * 	Name
   */
  const std::string& Name(void) const;

  /**
   * Set signature name.
   *
   * @param
   * 	rName
   */
  void Name(const std::string& rName);

  /**
   * Clear signature
   */
  void Clear(void);

  /**
   * Return number of parameters.
   *
   * @return
   * 	int
   */
  int Size(void) const;

  /**
   * Get parameter type by position.
   *
   * @param n
   * 	Position of patameter.
   *
   * @exception Exception
   * 	- Index out of range
   */
  const Parameter& At(int n) const;

  /**
   * Set parameter type by position.
   *
   * @param n
   * 	Position of patameter.
   * @param rParam
   * 	Paraeter value
   *
   * @exception Exception
   * 	- Index out of range
   */
  void At(int n,const Parameter& rParam);

  /**
   * Append positional parameter.
   *
   * @param rParam
   * 	Parameter to append
   */
  void Append(const Parameter& rParam);


 protected:

  /**
   * Std faudes type interface: assignment.
   *
   * @param rSrc 
   *    Source to copy from
   * @return Reference to this object.
   */
  void DoAssign(const Signature& rSrc);

  /**
   * Std faudes type interface: test equality
   * 
   * @param rOther 
   *    Other object to compare with.
   * @return 
   *   True on match.
   */
  bool DoEqual(const Signature& rOther) const;

  /**
   * Read signature from from TokenReader.
   *
   * The section is hardcoded to "Signature", context is ignored.
   *
   * @param rTr
   *   TokenReader to read from
   * @param rLabel
   *   Section to read
   * @param pContext
   *   Read context to provide contextual information (ignored)
   *
   * @exception Exception
   *   - IO error (id 1)
   *   - Token mismatch (id 50, 51, 52)
   */
  virtual void DoRead(TokenReader& rTr,  const std::string& rLabel = "", const Type* pContext=0);
 
  /**
   * Write configuration data of this object to TokenWriter.
   *
   * The section is hardcoded to "Signature", context is ignored.
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

  /** Variable to store name */
  std::string mName;

  /** Vector of Parameter-objects */
  std::vector<Parameter> mParameters;

}; // Signature



// forward 
class Function;


/**
 * A FunctionDefinition defines the interface to a faudes-function.
 * The latter consists of a descriptive name to identify the function and 
 * a list of Signatures the function can operate on. 
 * Technically, the class FunctionDefinition is derived from Documentation and 
 * thereby inherits members for additional
 * documentation-data.
 *
 * Similar to Type and TypeDefinition, a FunctionDefinition uses a prototype object to
 * provide the method NewFunction() which instantiates the corresponding Function object.
 *
 * FunctionDefinition inherits the token io interface from Type, however, the class is
 * not intended to register as a faudes type. The token io format is demonstrated by the
 * following example:
 *
 * @code
 * <FunctionDefinition name="CoreFaudes::IntegerSum" ctype="faudes::IntegerSum">
 *
 * <Documentation ref="integersum.html">
 * Returns the sum of integer arguments. 
 * <Documentation/>
 *
 * <Keywords> "integer" "elemetary types" </Keywords>
 *
 * <VariantSignatures>
 *
 * <Signature name="Two arguments">
 * <Parameter name="Arg1" ftype="Integer" access="In">
 * <Parameter name="Arg2" ftype="Integer" access="In">
 * <Parameter name="Res"  ftype="Integer" access="Out" creturn="true">
 * </Signature>
 *
 * <Signature name="Three arguments">
 * <Parameter name="Arg1" ftype="Integer" access="In">
 * <Parameter name="Arg2" ftype="Integer" access="In">
 * <Parameter name="Arg3" ftype="Integer" access="In">
 * <Parameter name="Res"  ftype="Integer" access="Out" creturn="true">
 * </Signature>
 *
 * </VariantSignatures>
 *
 * </FunctionDefinition>
 * @endcode
 *
 *
 * @ingroup RunTimeInterface
 */

class FAUDES_API FunctionDefinition : public Documentation {

 // std faudes type interface
 FAUDES_TYPE_DECLARATION(Void,FunctionDefinition,Documentation)

public:

  /** 
   * Constructor 
   *
   * The default constructor instantiates an invalid function definition
   * without prototype. To construct a valid function definition, use the static 
   * Constructor() template function.
   */
  FunctionDefinition(const std::string& name="");

  /** 
   * Copy Constructor 
   *
   * The copy constructor copies all members one-to-one, except for
   * the prototype object. The latter is re-created using its factory function.
   */
  FunctionDefinition(const FunctionDefinition& rSrc);

  /**
   * Destructor
   */
  virtual ~FunctionDefinition(){ Prototype(NULL);};

  /**
   * Construct empty FunctionDefinition object.
   * The given template parameter denotes a Function class.
   * Member variable (mpFunction) is set to a new instance of that class
   * whereas the name is set as specified. No further documentation
   * or signatures are recorded.
   *
   * @tparam T
   *   Actual function class, derived from Function
   * @param rFunctName
   *   Name to identify this faudes-function
   * @return
   *   Newly constructed function definition.
   */
  template<class T>
  static FunctionDefinition* Constructor(const std::string& rFunctName="");

  /**
   * Construct FunctionDefinition object and get name and docu from file.
   *
   * The member variable mpFunction is set to a new instance of class T.
   * which must be derived from Function. The function name, any documentation
   * as well as supported signatures are read from the specified file.
   *
   * @tparam T
   *   Actual function class, derived from Function
   * @param rFileName
   *   File to read documentation and signatures from.
   * @return
   *   Newly constructed function definition.
   */
  template<class T>
  static FunctionDefinition* FromFile(const std::string& rFileName);

  /**
   * Clear documentation-data and signature (keep prototype)
   */
  virtual void Clear(void);


  /**
   * Clear variants (keep docu and prototype)
   */
  virtual void ClearVariants(void);

  /**
   * Return pointer to function object prototype 
   *
   * Note: this method is meant for inspection only, control over
   * the prototype remains with the FunctionDefinition. Use
   * NewFunction() to instantiate a new function object.
   *
   * @return
   * 	Reference to prototype function.
   */
  const Function* Prototype(void) const;

  /**
   * Construct function on heap.
   * Return pointer to new instance of assigned Function class.
   *
   * Note: If no prototype is installed, NULL is returned.
   *
   * @return
   * 	Pointer to new Function instance.
   */
  Function* NewFunction() const;


  /**
   * Return number of supported Signature instances.
   *
   * @return
   * 	Size of signature vector.
   */
  int VariantsSize(void) const;

  /**
   * Test existence of variant by its name.
   *
   * @return
   * 	True if variant exists
   */
  bool ExistsVariant(const std::string& varname) const;

  /**
   * Return index of Signature by name.
   *
   * @param rName
   * 	Name of signature to search.
   * @return
   * 	Index of signature, or -1 if not existant
   */
  int VariantIndex(const std::string& rName) const;

  /**
   * Return reference to Signature by name.
   *
   * @param rName
   * 	Name of signature to search.
   * @return
   * 	Reference to Signature 
   * @exception Exception
   * 	- No such signature (id 47)
   */
  const Signature& Variant(const std::string& rName) const;

  /**
   * Return reference to Signature by index.
   *
   * @param n
   * 	Index to look up
   * @return
   * 	Reference to Signature 
   * @exception Exception
   * 	- Index out of range (id 47)
   */
  const Signature& Variant(int n) const;

  /**
   * Add Signature to function definition.
   *
   * @param pVar
   * 	Signature to insert
   * @exception Exception 
   *   - Signature with same name exists (id 47)
   */
  virtual void AppendVariant(const Signature& pVar);

protected:

  /**
   * Std faudes type interface: assignment.
   *
   * @param rSrc 
   *    Source to copy from
   * @return Reference to this object.
   */
  void DoAssign(const FunctionDefinition& rSrc);

  /**
   * Std faudes type interface: test equality
   * 
   * @param rOther 
   *    Other object to compare with.
   * @return 
   *   True on match.
   */
  bool DoEqual(const FunctionDefinition& rOther) const;

  /**
   * Read configuration data of this object from TokenReader.
   * Actual reading is done by DoReadCore.
   *
   * The section defaults to "FunctionDefinition", context ignored.
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
   * The section defaults to "FunctionDefinition", context ignored.
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
   * This method writes plain member data, the section lables are not
   * written.
   *
   * @param rTw
   *   Reference to TokenWriter
   *
   * @exception Exception 
   *   - IO errors (id 2)
   */
  virtual void DoWriteCore(TokenWriter& rTw) const;

  /**
   * Assign prototype object
   *
   * @param pFunc
   * 	Function instance
   *
   */
  virtual void Prototype(Function* pFunc);

  /** Prototype instance */
  Function* mpFunction;

  /** Vector containing all supported Signatures */
  std::vector<faudes::Signature> mVariants;

  /** Variant name to index map */
  std::map<std::string,int> mVariantIndexMap;

}; // FunctionDefinition



/**
 * A faudes-function hosts parameter values of some faudes type and provides 
 * a method to perform an operation on the specified paramters, e.g. the 
 * parallel composition on two generators. The class Function is the base
 * for all faudes-functions, which essenitally differ in the operation method.
 *
 * The base class provides an application interface to
 * - select a variant signature, see Variant(); 
 * - set and get parameter values of any faudes type, see ParamValue();
 * - type check the provided parameter values, see TypeCheck(); 
 * - perform the operation, see Execute().
 *
 * Derivates of the base class, that acually implement an operation,
 * are required to cast the parameter values to the corresponding c types and then
 * call the respective c function. To derive a class from Function, one will
 * reimplment three virtual functions:
 * - DoTypeCheck() to perform the cast
 * - DoExecute() to call the c function.
 * - the constructor New() to replicate the function object.
 *
 * See IntegerSum in the autogenerated ./include/rtiautoload.h" for a simple example 
 * of a derived faudes-function.
 * 
 *
 * Technichal note: In contrast to faudes objects (derivates from Type), a faudes-function
 * must be provided a reference to the corresponding FunctionDefinition. This is because
 * a function must be aware of its signature(s). You must not delete 
 * the FunctionDefinition object during the lifetime of a faudes-function.
 *
 *
 * @ingroup RunTimeInterface
 */  

class FAUDES_API Function : public Type {

 public:
  /** 
   * Constructor 
   * For the function to be operational, a valid reference to the corresponding 
   * FunctionDefinition is required. The only exception is the prototype function
   * object used in the FunctionDefinition itself. 
   */
  Function(const FunctionDefinition* fdef);

  /** Destructor */
  ~Function(){}

  /**
   * Construct on heap.
   * Create a new instance of this function class and return pointer.
   * The new instance will use the same function definition as this instance.
   *
   * @return
   * 	Pointer to faudes::Function instance.
   *
   */
  virtual Function* New() const = 0;


  /**
   * Set function definition.
   * Normally, functions are provided with a function definition on construction.
   * The only exception are prototype objects used in function definitions themselfs 
   * and in the function registry.
   *
   * @param fdef
   * 	Function definition to set.
   *
   */
  virtual void Definition(const FunctionDefinition* fdef);


  /**
   * Get function definition.
   *
   * @return 
   * 	Function definition used by this function.
   *
   */
  const FunctionDefinition* Definition(void) const;


  /**
   * Return number of variants.
   *
   * @return
   * 	Size of vector.
   */
  int VariantsSize(void) const;

  /**
   * Set signature from function definition.
   *
   * The index n refers this function's FunctionDefinition.
   * An exception is thrown if no such FunctionDefinition is set, as it
   * is the case for prototype instances.
   *
   * @param n
   * 	Variant index 
   *
   * @exception Exception
   * 	- No function definition available (id 47)
   * 	- No such variant (id 48)
   */
   void Variant(int n);


  /**
   * Set signature from function definition.
   *
   * The name refers to this function's FunctionDefinition.
   * An exception is thrown if no such FunctionDefinition is set, as it
   * is the case for prototype instances.
   *
   * @param rVariantName
   * 	Variant name
   *
   * @exception Exception
   * 	- No function definition available (id 47)
   * 	- No such variant (id 48)
   */
  void Variant(const std::string& rVariantName);


  /**
   * Return pointer to assigned faudes::Signature.
   *
   * @return
   * 	Pointer to faudes::Signature.
   */
  const Signature* Variant(void) const;


  /**
   * Return number of parameters with current signature.
   *
   * @return
   * 	Size of vector.
   */
  int ParamsSize(void) const;

  /**
   * Set parameter at certain position.
   *
   * Sets the internal refernce of the parameter value
   * at the spcefied index. The ownership of the value remains with
   * the caller, ie it will not be deleted in the destructor of the 
   * function object.
   * You may set the parameter value to any faudes type
   * (classes derived from Type). A type check will be performed before the function
   * is executed.
   *
   * @param n
   * 	Position index of parameter 
   * @param param
   * 	Pointer to faudes object.
   *
   * @exception Exception
   * 	- Index out of range (id 47)
   * 	- No variant set (id 47)
   */
  void ParamValue(int n, Type* param);

  /**
   * Get parameter value.
   * Returns a reference to the parameter value at the specified position.
   *
   * @param n
   * 	Position index of parameter.
   *
   * @exception Exception
   * 	- Index out of range (id 47)
   */
  Type* ParamValue(int n) const;

  /**
   * Construct parameter values.
   *
   * This is a convenience method to allocate faudes objects for 
   * parameter values with the type specified by the current signature.
   * Note that the function does not take ownetship of the parameter values and
   * it is the callers responsibility to delete them when no longer required.
   *
   */
  void AllocateValues(void);
  void AllocateValue(int i);

  /**
   * Destruct parameter values.
   *
   * This is a convenience method to delete the assigned paramer values.
   *
   */
  void FreeValues(void);

  /**
   * Perform a type check one parameter value.
   * 
   * The type check is based on c type cast and should accept any types
   * derived from the type given in the signature.
   *
   * @param n
   *   Position of parameter to check
   * @return
   *   True if type matches  
   *
   * @exception Exception
   *  - No variant specified (id 48)
   *  - Number of parameter is outside the specified signature (id 48)
   *
   */
  bool TypeCheck(int n);

  /**
   * Perform a type check on the list of current parameter values.
   * 
   * The type check is based on c type cast and should accept any types
   * derived from those given in the signature.
   *
   * @return
   *   True if all parameter types matche the signature
   *
   * @exception Exception
   *  - No variant specified (id 48)
   *  - Number of parameters does not match signature (id 48)
   *
   */
  bool TypeCheck(void);

  /**
   * Perform operation.
   *
   * Runs a type check and then the actual function.
   *
   * @exception Exception
   *  - No variant specified (id 48)
   *  - Parameter position out of range (id 48)
   *  - Type mismatch (id 48)
   *  - Any other exception thrown ba the actual function (id xxx)
   */
  void Execute(void);


 protected:

  /**
   * Helper: generate typed reference for parameter.
   *
   * @param n
   *   Parameter position to cast
   * @param rTypedRef
   *   Typed reference to generyte
   * @tparam T
   *   c type to use for cast
   * @return
   *   True if cast succeeded.
   * @exception Exception
   *  - No variant specified (id 48)
   *  - Parameter position out of range (id 48)
   */  
   template<class T>
   bool DoTypeCast(int n, T*& rTypedRef) {
    if(!Variant()) {
       std::stringstream err;
       err << "No variant specified";
       throw Exception("Function::DoTypeCast()", err.str(), 48);
    }
    if(n<0 || n >= ParamsSize()) {
       std::stringstream err;
       err << "Parameter position out of range";
       throw Exception("Function::DoTypeCast()", err.str(), 48);
    }
    rTypedRef=dynamic_cast<T*>(ParamValue(n));
    return rTypedRef!=NULL;
  }

  /*
   * Do set variant from function definition.
   *
   * The index n refers this function's FunctionDefinition.
   * An exception is thrown if no FunctionDefinition is set, as it
   * is the case for prototype instances.
   *
   * @param n
   * 	Variant index 
   *
   * @exception Exception
   * 	- No function definition available (id 47)
   * 	- No such variant (id 48)
   */
   virtual void DoVariant(int n);

  /**
   * Method to test the type of an assigned parameter with the
   * specified faudes::Signature (i.e. their TypeDefinition label).
   *
   * Note: this method is called by Function::Execute() before actual function 
   * execution via DoExecute(). It may be used to perform a dynamic cast in 
   * preparation of DoExecute(). The latter is only called, if all types match.
   * 
   * @param n
   *   Position of parameter to check
   * @return
   *   True if type matches signature.
   *
   * @exception Exception
   * 	- Signature undefined (id 48)
   * 	- Parameter number out of range (id 48)
   */
  virtual bool DoTypeCheck(int n) = 0;

  /**
   * Executes code of reimplemented method of child class(es).
   */
  virtual void DoExecute() = 0;

  /**
   * Write function-data (typeid-name of arguments) to TokenWriter.
   *
   * @param rTw
   * 	Reference to Tokenwriter.
   * @param rLabel
   * 	Label of section to write.
   * @param pContext
   * 	Context pointer, ignored
   *
   * @exception Exception
   * 	- IO Error
   */
  void DoWrite(TokenWriter& rTw, const std::string& rLabel = "", const Type* pContext=0) const;

  /** corresponding function definition */
  const FunctionDefinition* pFuncDef;

  /** current variant aka signature as index w.r.t. the function definition */
  int mVariantIndex;

  /** Vector of arguments. */
  std::vector<Type*> mParameterValues;

}; // Function



/**********************************************************************************************
***********************************************************************************************
***********************************************************************************************

Implemention of template members functions

***********************************************************************************************
***********************************************************************************************
**********************************************************************************************/


// typedefinition constructor function
template<class T>
FunctionDefinition* FunctionDefinition::Constructor(const std::string& rFunctionName){
  FD_DRTI("FunctionDefinition::Construct<" << typeid(T).name() << ">()");
  // construct void definition
  FunctionDefinition* td = new FunctionDefinition();
  // set its prototype object (note the 0 param in the new constructor)
  td->Prototype(new T(0));
  // set minmum values ie the function name
  std::string name=rFunctionName;
  if(name=="") name=typeid(T).name();
  td->Name(name);
  FD_DRTI("FunctionDefinition::Constructor<" << typeid(T).name() << ">(): done");
  return(td);
}


// function definition constructor function
template<class T>
FunctionDefinition* FunctionDefinition::FromFile(const std::string& rFileName){
  FD_DRTI("FunctionDefinition::FromFile<" << typeid(T).name() << ">()");
  // construct with fallback name
  FunctionDefinition* td = Constructor<T>();
  // read docu, incl actual name
  td->Read(rFileName);
  // done
  FD_DRTI("FunctionDefinition::FromFile<" << typeid(T).name() << ">(): done");
  return(td);
}


} // namespace


#endif /* FAUDES_FUNCTIONS_H */
