/** @file cfl_registry.h Runtime interface, registry for faudes-types and functions */

/* FAU Discrete Event Systems Library (libfaudes)

Copyright (C) 2009 Ruediger Berndt
Copyright (C) 2009 Thomas Moor

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


#ifndef FAUDES_RTIREGISTRY_H
#define FAUDES_RTIREGISTRY_H

#include "cfl_types.h"
#include "cfl_functions.h"
 
namespace faudes{


/**
 * The TypeRegistry registers faudes-types. A faudes-type may be
 * any class derived from faudes::Type, e.g. EventSet and generator.
 * The registry maintains a mapping from faudes-type names to registred 
 * faudes::TypeDefinition. It provides an interface to inspect 
 * TypeDefinitions or to construct faudes-type objects by their type name. 
 *
 * Technical note: the class is implemented according to the \"Singleton\" design 
 * pattern, ie, only one global instance of the registry can exist.
 *
 *
 * @ingroup RunTimeInterface
 */


class FAUDES_API TypeRegistry : public Type {

public:

  /** Convenience typedef to access registry entries */     
  typedef std::map<std::string, TypeDefinition*>::const_iterator Iterator;

  /**
   * Method to access the single global instance of the registry.
   */
  static TypeRegistry* G();

  /** 
   * Clear all registered type definitions. This will also delete the
   * correponsing prototype objects. It will, however, not delete
   * C++-autoregistered registry entries.
   */
  void Clear();

  /** 
   * Clear all registered type definitions. This will also delete the
   * correponsing prototype objects. This version will also
   * delete C++-autoregistered registry entries.
   */
  void ClearAll();

  /**
   * Return number of registered type definitions.
   *
   * @return
   * 	Size of map.
   */
  int Size() const;

  /**
   * Test existence of a faudes-type by its name.
   *
   * @param rName
   * 	Name of type to look up
   *
   * @return
   * 	True, if a corresponding definition is registered.
   */
  bool Exists(const std::string& rName) const;

  /**
   * Test existence of a faudes-type by faudes object
   *
   * @param rType
   * 	Object of type to look up
   *
   * @return
   * 	True, if a corresponding definition is registered.
   */
  bool Exists(const Type& rType) const;

  /**
   * STL interator to the internal type-name map.
   *
   * @return
   * 	Iterator to the first element.
   */
  Iterator Begin(void) const;

  /**
   * STL interator to the internal type-name map.
   *
   * @return
   * 	Iterator to the end of the map.
   */
  Iterator End(void) const;

  /**
   * Add another type definition to the registry.
   *
   * The registry takes the ownership pf the provided
   * type definition. It will be deleted either in Clear() or 
   * when the registry is destructed. The insertion of an allready registered
   * type is ignored as long as the ctype matches. If the ctype
   * fails to match, an exception is thrown.
   *
   * @param pTypeDef
   * 	Type definition to insert
   *
   * @exception Exception
   * 	- Identical name found (id 46)
   */
  void Insert(TypeDefinition* pTypeDef);

  /**
   * Register a faudes-type with specified type name.
   *
   * This is a convenience function: it uses the template parameter to
   * construct the new instance of TypeDefinition to be registered. However,
   * no documentation is added. See also MergeDocumentation.
   *
   * @tparam T
   *   Template parameter to specify c++ type to register
   * @param rTypeName
   *   Specify the faudes-type name 
   * @exception Exception
   * 	- Identical name found (id 46)
   */
  template<class T>
  void Insert(const std::string& rTypeName="") {
    FD_DRTI("TypeRegistry::Insert<" << typeid(T).name() << ">(" << rTypeName << ")");
    TypeDefinition* td = TypeDefinition::Constructor<T>(rTypeName);
    Insert(td);
  }

  /**
   * Register a faudes-type with specified type name.
   *
   * This is a convenience function: it uses the specified object as a
   * a prototype and registers it under the given name. The registry takes 
   * ownership of the prototype. However,
   * no documentation is added. See also MergeDocumentation.
   *
   * @param pProto
   *   Prototype object
   * @param rTypeName
   *   Specify the faudes-type name 
   * @exception Exception
   * 	- Identical name found (id 46)
   */
  void Insert(Type* pProto, const std::string& rTypeName) {
    FD_DRTI("TypeRegistry::Insert(prototype, " << rTypeName << ")");
    TypeDefinition* td = TypeDefinition::Constructor(pProto, rTypeName);
    Insert(td);
  }

  /**
   * Scan token input for type documentation.
   * This function scans the entire token stream for sections
   * with label "TypeDefinition". Any such section that refers to a type name
   * which is known to the registry, will be applied to the corresponding 
   * registry entry. Typical invokation is as follows
   *
   * @code
   * TypeRegistry::G()->Insert<EventSet>("EventSet");
   * TypeRegistry::G()->Insert<Generator>("Generator");
   * TypeRegistry::G()->MergeDocumentation("alldocufile.rti");
   * @endcode
   *
   * @param rTr
   *  Token stream.
   * @exception Exception
   *  - Token mismatch (id 50, 51, 52)
   *  - IO Error (id 1)
   */
  void MergeDocumentation(TokenReader& rTr);

  /**
   * Scan file for type documentation.
   * Convenience method, see also MergeDocumentation(TokenReader& rTr)
   *
   * @param rFileName
   *  Name of file to scan.
   * @exception Exception
   *  - Token mismatch (id 50, 51, 52)
   *  - IO Error (id 1)
   */
  void MergeDocumentation(const std::string& rFileName);


  /**
   * Set Xml element tag for given faudes-type.
   *
   * Access to the XElementTag of a type definition. The latter is
   * used for Xml token IO of sets and vectors.
   * Unregistered types are silently ignored.
   *
   * @param rTypeName
   * 	Name of faudes-type
   * @param rTag
   *    New value of tag
   */
  void XElementTag(const std::string& rTypeName, const std::string& rTag);

  /**
   * Get Xml element tag for given faudes-type.
   *
   * Access to the XElementTag of a type definition. The latter is
   * used for Xml token IO of sets and vectors.
   * Unregistered types return the empty string.
   *
   * @param rTypeName
   * 	Name of faudes-type
   * @return
   *    Xml element tag
   */
  const std::string& XElementTag(const std::string& rTypeName) const;

  /**
   * Get AutoRegister flag for given faudes-type.
   *
   * Access the AutoRegister flag of a type definition. 
   * The flag is true for entries which were instantiated 
   * automatically by static constructor objects. AutoRegistered flags
   * will not be cleared.
   *
   * @param rTypeName
   * 	Name of faudes-type
   * @return
   *    AutoRegister flag
   */
  bool AutoRegistered(const std::string& rTypeName) const;

  /**
   * Set AutoRegistered flag for given faudes-type.
   *
   * Access the AutoRegister flag of a type definition. 
   * The flag is true for entries with were instantiated by
   * automatically by static constructor objects. AutoRegistered flags
   * will not be cleared.
   *
   * @param rTypeName
   * 	Name of faudes-type
   * @param flag
   *    New value of flag
   */
  void AutoRegistered(const std::string& rTypeName, bool flag);

  /**
   * Construct a faudes object by type name
   *
   * Uses the internal prototype object to construct
   * an object of the same c type on the heap. 
   *
   * @param rTypeName
   * 	Label of TypeDefinition to search for.
   * @return
   * 	Pointer to new faudes::Type instance 
   * @exception Exception
   * 	- Unknown type (id 47)
   */
  Type* NewObject(const std::string& rTypeName) const;

  /**
   * Construct a faudes object by prototype object.
   *
   * Depreciated: use new on the faudes object instead.
   *
   * @param rType
   * 	Prototype object.
   *
   * @return
   * 	Pointer to new faudes::Type instance
   * @exception Exception
   * 	- Unknown type (id 47)
   */
  Type* NewObject(const Type& rType) const;


  /**
   * Look up the type definition by faudes-type name
   *
   * @param rTypeName
   * 	Faudes-tyep name to search for.
   *
   * @return
   * 	Reference to faudes::TypeDefinition
   *
   * @exception Exception
   * 	- Unknown type (id 46)
   */
  const TypeDefinition& Definition(const std::string& rTypeName) const;

  /**
   * Look up the type definition by faudes object
   *
   * @param rType
   * 	Reference to faudes::Type to search for.
   *
   * @return
   * 	Reference to faudes::TypeDefinition
   *
   * @exception Exception
   * 	- Unknown type (id 46)
   */
  const TypeDefinition& Definition(const Type& rType) const;

  /**
   * Look up the type definition by faudes-type name
   *
   * @param rTypeName
   * 	Faudes-tyep name to search for.
   *
   * @return
   * 	Pointer to faudes::TypeDefinition, NULL for unknoen type.
   *
   */
  const TypeDefinition* Definitionp(const std::string& rTypeName) const;

  /**
   * Look up the type definition by faudes object
   *
   * @param rType
   * 	Reference to faudes::Type to search for.
   *
   * @return
   * 	Pointer to faudes::TypeDefinition, NULL for unknoen type.
   *
   */
  const TypeDefinition* Definitionp(const Type& rType) const;


  /**
   * Look up the prototype object by faudes-type name
   *
   * @param rTypeName
   * 	Label of faudes::TypeDefinition to search for.
   *
   * @return
   * 	Reference to faudes::Type object, Null for unknown type
   *
   */
  const Type* Prototype(const std::string& rTypeName) const;

  /**
   * Look up the type name by faudes object
   *
   * @param rType
   * 	Reference to faudes::Type to search for.
   *
   * @return
   * 	Type name as string or "" if unknown.
   *
   */
  const std::string& TypeName(const Type& rType) const;

  /**
   * Cosmetic: fix compile warning for recent LLVM/clang++
   */
  using Type::TypeName;

  /** 
   * Test type compatibility.
   * Test whether the provided object
   * can be casted to the specified type name,
   * 
   * @param rTypeName
   *  Faudes type name
   * @param rObject
   *  Faudes object instance
   * @return
   *  True, if object can be casted to specified faudes type.
   *
   */
   bool TypeTest(const std::string& rTypeName, const Type& rObject) const;


 protected:

  /**
   * Write registry data of this to TokenWriter.
   *
   * Since the registry cannot reconfigure itself from a token stream,
   * this output is informative only. However, MergeDocumentation will 
   * accept the format to extract documentation.
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

  /** Convenience typedef to access registry entries */     
  typedef std::map<std::string, TypeDefinition*>::iterator iterator;

  /** Singleton instance */
  static TypeRegistry* mpInstance;

  /** Constructor */
  TypeRegistry(){}

  /** Destructor */
  virtual ~TypeRegistry(){
    Clear();
  }

  /** Map to associate labels and faudes::TypeDefinitions. */
  std::map<std::string, TypeDefinition*> mNameToTypeDef;
  std::map<std::string, TypeDefinition*> mIdToTypeDef;

}; // TypeRegistry


/**
 * Auto register faudes-type with specified type name.
 *
 * This is a convenience class template to automize faudes type registration.
 * It uses the Insert template of the type registry. If the type name 
 * is already registered, no registration will take place and the old
 * configuration is maintained. Also registration with faudes-type name "Void" 
 * will be silently ignored.
 * Type documentation is not supported but may
 * be added via MergeDocumentation. 
 *
 * @tparam T
 *   Template parameter to specify the C++ type to register
 * @param rTypeName
 *   Specify the faudes-type name 
 */
template<class T>
class AutoRegisterType {
 public:
  AutoRegisterType(const std::string& rTypeName="Void") {
    if(rTypeName=="Void") return;
    if(TypeRegistry::G()->Exists(rTypeName)) return;
    FD_DREG("AutoRegisterType(" << rTypeName << "): by prototype template with " << typeid(T).name());
    TypeRegistry::G()->Insert<T>(rTypeName);
    TypeRegistry::G()->AutoRegistered(rTypeName,true);
  };
};

template<class T>
class AutoRegisterXElementTag {
 public:
  AutoRegisterXElementTag(const std::string& rTypeName, const std::string& rTag) {
    static AutoRegisterType<T> srego(rTypeName);
    TypeRegistry::G()->XElementTag(rTypeName,rTag);
  };
};




/**
 * The FunctionRegistry registers faudes-functions. A faudes-functions
 * operates on faudes objects, eg the parallel composition of two 
 * generators is available as faudes-function. The registry maintains a
 * mapping between function names and a coresponding function::Definition.
 * The latter provides signatures, ie parameter types the function can 
 * take. The registry provides an interface to inspect 
 * TypeDefinitions or to construct function objects by their type name. 
 *
 * Technical note: the class is implemented according to the \"Singleton\" design 
 * pattern, ie, only one global instance of the registry can exist.
 *
 * @ingroup RunTimeInterface
 */

class FAUDES_API FunctionRegistry : public Type {

public:

  /** Convenience typedef to access registry entries */     
  typedef std::map<std::string, FunctionDefinition*>::const_iterator Iterator;

  /**
   * Method to access the single global instance of the registry.
   */
  static FunctionRegistry* G();

  /** 
   * Clear all registered function definitions. This will also delete the
   * correponsing prototype objects.
   */
  void Clear();

  /**
   * Return number of registered function definitions.
   *
   * @return
   * 	Size of map.
   */
  int Size() const;

  /**
   * Test existence of a faudes-function by its name.
   *
   * @param rName
   * 	Name of function to look up
   *
   * @return
   * 	True, if a corresponding definition is registered.
   */
  bool Exists(const std::string& rName) const;

  /**
   * Test existence of a faudes-function by faudes object
   *
   * @param rFunction
   * 	Object of function to look up
   *
   * @return
   * 	True, if a corresponding definition is registered.
   */
  bool Exists(const Function& rFunction) const;

  /**
   * STL interator to the internal function-name map.
   *
   * @return
   * 	Iterator to the first element.
   */
  Iterator Begin(void) const;

  /**
   * STL interator to the internal function-name map.
   *
   * @return
   * 	Iterator to the end of the map.
   */
  Iterator End(void) const;

  /**
   * Add another function definition to the registry.
   *
   * The registry takes the ownership pf the provided
   * function definition. It will be deleted either in Clear() or 
   * when the registry is destructed.
   *
   * @param pFunctionDef
   * 	Function definition to insert
   *
   * @exception Exception
   * 	- Identical name found (id 46)
   */
  void Insert(FunctionDefinition* pFunctionDef);

  /**
   * Register a faudes-function with specified function name.
   *
   * This is a convenience function: it uses the template parameter to
   * construct the new instance of FunctionDefinition to be registered. However,
   * no documentation is added. See also MergeDocumentation.
   *
   * @tparam T
   *   Template parameter to specify c++ function to register
   * @param rFunctionName
   *   Specify the faudes-function name 
   * @exception Exception
   * 	- Identical name found (id 46)
   */
  template<class T>
  void Insert(const std::string& rFunctionName="") {
    FD_DRTI("FunctionRegistry::Insert<>(" << rFunctionName << ")");
    FunctionDefinition* td = FunctionDefinition::Constructor<T>(rFunctionName);
    Insert(td);
  }

  /**
   * Scan token input for function documentation.
   * This function scans the entire token stream for sections
   * with label "FunctionDefinition". Any such section that refers to a function name
   * which is known to the registry, will be applied to the corresponding 
   * registry entry.
   *
   *
   * @param rTr
   *  Token stream.
   * @exception Exception
   *  - Token mismatch (id 50, 51, 52)
   *  - IO Error (id 1)
   */
  void MergeDocumentation(TokenReader& rTr);

  /**
   * Scan file for function documentation.
   * Convenience method, see also MergeDocumentation(TokenReader& rTr)
   *
   * @param rFileName
   *  Name of file to scan.
   * @exception Exception
   *  - Token mismatch (id 50, 51, 52)
   *  - IO Error (id 1)
   */
  void MergeDocumentation(const std::string& rFileName);

  /**
   * Construct a faudes object by function name
   *
   * Uses the internal prototype object to construct
   * an object of the same c function on the heap. 
   *
   * @param rFunctionName
   * 	Label of FunctionDefinition to search for.
   * @return
   * 	Pointer to new faudes::Function instance 
   * @exception Exception
   * 	- Unknown function (id 47)
   */
  Function* NewFunction(const std::string& rFunctionName) const;

  /**
   * Construct a faudes object by protofunction object.
   *
   * Depreciated: use new on the faudes object instead.
   *
   * @param rFunction
   * 	Protofunction object.
   *
   * @return
   * 	Pointer to new faudes::Function instance 
   * @exception Exception
   * 	- Unknown function (id 47)
   */
  Function* NewFunction(const Function& rFunction) const;


  /**
   * Look up the function definition by faudes-function name
   *
   * @param rFunctionName
   * 	Label of faudes::FunctionDefinition to search for.
   *
   * @return
   * 	Reference to faudes::FunctionDefinition
   *
   * @exception Exception
   * 	- Unknown function (id 46)
   */
  const FunctionDefinition& Definition(const std::string& rFunctionName) const;

  /**
   * Look up the function definition by faudes object
   *
   * Techcal note: this implementation is slow, we should
   * use a function id map. 
   *
   * @param rFunction
   * 	Reference to faudes::Function to search for.
   *
   * @return
   * 	Reference to faudes::FunctionDefinition
   *
   * @exception Exception
   * 	- Unknown function (id 46)
   */
  const FunctionDefinition& Definition(const Function& rFunction) const;

  /**
   * Look up the function name by faudes object
   *
   * @param rFunction
   * 	Reference to faudes::Function to search for.
   *
   * @return
   * 	Function name as string or "" if unknown.
   *
   */
  const std::string& FunctionName(const Function& rFunction) const;

 protected:

  /**
   * Write registry data of this to TokenWriter.
   *
   * Since the registry cannot reconfigure itself from a token stream,
   * this output is informative only. However, MergeDocumentation will 
   * accept the format to insert/extract documentation.
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

  /** Convenience typedef to access registry entries */     
  typedef std::map<std::string, FunctionDefinition*>::iterator iterator;

  /** Singleton instance */
  static FunctionRegistry* mpInstance;

  /** Constructor */
  FunctionRegistry(){}

  /** Destructor */
  virtual ~FunctionRegistry(){
    Clear();
  }

  /** Map to associate labels and faudes::FunctionDefinitions. */
  std::map<std::string, FunctionDefinition*> mNameToFunctionDef;
  std::map<std::string, FunctionDefinition*> mIdToFunctionDef;

}; // FunctionRegistry


/** 
 * Load all registered types and functions.
 *
 * The default file is some not so educated guess, so you
 * should specify it explicitely.
 *
 * @param rPath
 *   Source file
 *
 * @ingroup RunTimeInterface
 */

extern FAUDES_API void LoadRegistry(const std::string& rPath="");


/** 
 * Dump all registered types and functions
 *
 * The destinations defaults to stdout.
 *
 * @param rPath
 *   Destination file
 *
 * @ingroup RunTimeInterface
 */

extern FAUDES_API void SaveRegistry(const std::string& rPath="");


/** 
 * Clear all registry
 *
 * @ingroup RunTimeInterface
 */

extern FAUDES_API void ClearRegistry(void);


/** 
 * Instantiate faudes typed objects by type name.
 * Convenience function to access registry singleton.
 * 
 * @param rTypeName
 *  Type to instantiate
 *
 * @ingroup RunTimeInterface
 */

extern FAUDES_API Type* NewFaudesObject(const std::string& rTypeName);

/** 
 * Query type name.
 * Convenience function to access registry singleton.
 * 
 * @param rObject
 *  Faudes object instance
 * @return
 *  Faudes type name or "" if unkown.
 *
 * @ingroup RunTimeInterface
 */

extern FAUDES_API const std::string& FaudesTypeName(const Type& rObject);


/** 
 * Test type compatibility.
 * Convenience function to access registry singleton.
 * 
 * @param rTypeName
 *  Faudes type name
 * @param rObject
 *  Faudes object instance
 * @return
 *  True, if object can be casted to specified faudes type.
 *
 * @ingroup RunTimeInterface
 */
extern FAUDES_API bool FaudesTypeTest(const std::string& rTypeName, const Type& rObject);


/** 
 * Instantiate faudes function objects by function name.
 * Convenience function to access registry singleton.
 *
 * @param rFunctName
 *  Function to instantiate
 *
 * @ingroup RunTimeInterface
 */
extern FAUDES_API Function* NewFaudesFunction(const std::string& rFunctName);

/** 
 * Query function name.
 * Convenience function to access registry singleton.
 * 
 * @param rObject
 *  Faudes object instance
 * @return
 *  Faudes function name or "" if unkown.
 *
 * @ingroup RunTimeInterface
 */
extern FAUDES_API const std::string& FaudesFunctionName(const Type& rObject);



/**********************************************************************************************
***********************************************************************************************
***********************************************************************************************

Implemention of template members functions

***********************************************************************************************
***********************************************************************************************
**********************************************************************************************/





} // namespace

#endif /* FAUDES_RTIREGISTRY_H */
