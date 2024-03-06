/** @file lbp_function.h luafaudes class to run scripts as rti functions */

/* FAU Discrete Event Systems Library (libfaudes)

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


#ifndef FAUDES_LBPFUNCTION_H
#define FAUDES_LBPFUNCTION_H

#include "corefaudes.h"

// forward
struct lua_State;

namespace faudes{

// forward
class LuaFunction;
class LuaState;

/**
 * A LuaFunctionDefinition is derived from FunctionDefinition to
 * define a faudes-function by a Lua script. It has
 * the Lua code as an additional member variable and uses a LuaFunction as a
 * prototype object. In particular, LuaFunctionDefinitions are allways
 * valid in the sense that hey have a prototype. The LuaFunction object 
 * implements DoTypeCheck and DoExecute to run the specifed Lua code. 
 * Thus, a LuaFunction can be tranparently accessed via the run-time interface
 * and bahves like any other registered faudes function. 
 *
 * Alternatively, 
 * you can use the Install() method to install a LuaFunctionDefinition to
 * a LuaState. Then, the function can be accessed by the Lua interpreter. 
 * Install() will generate code to dispatch the function variants with the 
 * same semantics as the SWIG generated interface for other faudes functions.
 * Again, integeration is transparent from the perspective of the Lua interpreter.
 *  
 *
 * The token io format is demonstrated by the
 * following example:
 *
 * @code
 * <LuaFunctionDefinition name="LuaExtension::LargeGenerator">
 * 
 * <Documentation> 
 * Construct a generator by random.
 * </Documentation>
 * <Keywords> "luaextension" "example" </Keywords>
 *
 * <VariantSignatures>
 * <Signature name="LargeGen(#Q,#Sigma,GRes)">
 * <Parameter name="SizeQ"      ftype="Integer"   access="In"/>
 * <Parameter name="SizeSigma"  ftype="Integer"   access="In"/>
 * <Parameter name="Res"        ftype="Generator" access="Out" />
 * </Signature>
 * </VariantSignatures>
 * 
 * <LuaCode> 
 * <[CDATA[
 * 
 * -- Extension reports on loading
 * print('loading luaextension "LargeGenerator"')
 *
 * -- Define my function (mangled version of variant name)
 * function faudes.LargeGen_Q_Sigma_GRes(qn,sn,gen)
 *
 * -- Function reports on execution 
 * print(string.format('LargeGen(...): qn=%d sn=%d',qn,sn))
 *
 * -- Exeution code
 * gen:Clear()
 * for i=1,qn do
 *   gen:InsState(i)
 * end
 * for i=1,sn do 
 *   gen:InsEvent(string.format('ev_%d',i))
 * end
 *
 * -- Done
 * return 
 * 
 * -- End of function definition
 * end
 * 
 * -- Extension reports on loading
 * print('loading luaextension: done')
 * 
 * ]]>
 * </LuaCode>
 * 
 * </LuaFunctionDefinition>
 * @endcode
 *
 * Restrictions and conventions:
 * - Type-checking is done via the Cast() function of the faudes Type interface. As a 
 *   consequence, you may only use types that are registered with the run-time-interface.
 * - On execution, the LuaFunction instance has to locate the respective function 
 *   in the supplied lua code. In order to allow for multiple variants, the convention is
 *   to have one lua function each with the name of the corresponding variant. Since
 *   variant names may contain funny characters, name matching is performed after
 *   so called mangeling: any sequence of non-alpha-numerics is replaced by a single "_",
 *   a trailing "_" is dropped. E.g. the variant <tt>res=a+b</tt> matches the Lua function <tt>res_a_b</tt>.
 * - Parameters other than elementary (integer, boolean and string) are passed to 
 *   the Lua function by reference. However, Lua will consistently interpret the reference itself 
 *   as a parameter value. Thus, to assign a value to an <tt>access="Out"</tt> or <tt>access="InOut"</tt>
 *   parameter, you must use the assigment memberfunction Assign (as opposed to the assignment operator "=").
 * - Elementary types (i.e. integers, booleans and strings) are passed to the Lua function by value.
 *   Thus, it would be pointless to have an elementary typed parameter with access attribute other than 
 *   <tt>access="In"</tt>. In order to implement elementary typed return values, the respective 
 *   Lua function must return the corresponding values by an approriate return statement. The signature
 *   should indicate this by the attribute <tt>creturn="true"</tt>. The current implementation
 *   will automatically imply <tt>creturn="true"</tt> for any <tt>access="Out"</tt> or 
 *   <tt>access="InOut"</tt>.
 * - Since luafaudes has no concept of const references, it is the responsability of the
 *   script programer to respect parameter <tt>access</tt> attributes. 
 * - When using Install() to install the function to a LuaState, a single wrapper function will be
 *   defined to dispatch variants. By convention, this function is located in <tt>faudes.name_of_fdef</tt>,
 *   where <tt>name_of_fdef</tt> is the name of the respective LuaFunctionDefinition.
 *
 *
 *
 * @ingroup LuabindingsPlugin
 */

class FAUDES_API LuaFunctionDefinition : public FunctionDefinition {

  // faudes type
  FAUDES_TYPE_DECLARATION(LuaFunctionDefinition,LuaFunctionDefinition,FunctionDefinition)

public:

  /** 
   * Constructor. 
   *
   * In contrast to the std FunctionDefinition, the default constructor 
   * sets up a valid lua function definition with a newly created LuaFunction 
   * as prototype.
   * Of course, you will need to set the signatures and the lua code
   * to obtain an operational function.
   */
  LuaFunctionDefinition(const std::string& name="");

  /** 
   * Copy constructor 
   */
  LuaFunctionDefinition(const LuaFunctionDefinition& rSrc);

  /**
   * Destructor
   */
  virtual ~LuaFunctionDefinition(void){};


  /**
   * Clear documentation-data, signature and script (keep prototype)
   */
  void Clear(void);

  /**
   * Get Lua code
   * 
   * @return
   *   Lua code as std string
   */
  const std::string& LuaCode(void) const;

  /**
   * Set Lua code
   * 
   * @param rCode
   *   Lua code as std string
   */
  void LuaCode(const std::string& rCode);

  /**
   * Set default lua state.
   *
   * Sets the default lua state on which functions that refer to
   * this function definition will use for execution. 
   * If set to NULL (e.g. on consruction), the
   * global state is used. However, the function object
   * itself may overwrite the default.
   * 
   * @param pL
   *   Lua state
   */
  void DefaultL(LuaState* pL);

  /**
   * Get default lua state.
   * 
   * @return
   *   Lua state
   */
  LuaState* DefaultL(void) const;

  /**
   * Syntax check lua code.
   *
   * This routine instantiates a LuaFunction from this function definition
   * and does all it needs to run the script, except to invoke the any of the
   * variant functions. The reasoning is, that the script may hang and, thus, 
   * never return. Errors are indicated returned as an error string.
   * 
   * @return
   *   Error message as string, or empty string on success
   */
  std::string SyntaxCheck(void);

  /**
   * Evaluate lua code.
   *
   * This routine evaluates the LuaCode literally. This method is used to execute
   * LuaCode that is not part of any particular variant. To execute a
   * particular variant, instantiate a LuaFunction and invoke Execute().
   * 
   * If you pass NULL as destination state, the global state will be used.
   *
   * @param pL
   *   Reference to the Lua state
   * @return
   *   Error message as string, or empty string on success
   */
  std::string Evaluate(LuaState* pL=NULL);

  /**
   * Install this function to a Lua state
   * 
   * This routine installs the Lua code of this function
   * definition to the table "faudes" of the specified Lua state.
   * It also constructs a wrapper function
   * to dispatch signatures and palces this in the table "faudes".
   * Effectively, the resulting Lua state is prepared to execute the
   * Lua function with the same semantics as used for SWIG generated wrappers
   * of C++ functions.
   *
   * If you pass NULL as destination state, the global state will be used.
   *
   * @param pL
   *   Reference to the Lua state
   */
  void Install(LuaState* pL=NULL) const;

  /**
   * Install this function to a Lua state.
   *
   * Alternative signature for applications that do not use the
   * the LuaState wrapper class. See also Install(LuaState*).
   *
   * @param pLL
   *   Reference to the Lua state
   */
  void Install(lua_State* pLL) const;


  /*
   * Register LuaExtension with the run-time-interface.
   *
   * This static convenience method registers all LuaFunctionDefinitions found  
   * in an extension file with the FunctionRegistry. Thus, after registration
   * you can use the Lua function via the run-time-interface as if they
   * where C++ functions.
   *
   * Note: if you also want to use the provided functions within a Lua interpreter,
   * you must also install the extension to a lua state. This can be done on
   * a per-file basis by LuaState::Install(const std::string&) or for the any
   * functions registered by LuaState::Reset().
   *
   *
   * @param rFilename
   *   Source file (typically .flx)
   */
  static void Register(const std::string& rFilename);
  

protected:

  /**
   * Std faudes type interface: assignment.
   *
   * @param rSrc 
   *    Source to copy from
   * @return Reference to this object.
   */
  virtual void DoAssign(const LuaFunctionDefinition& rSrc);

  /**
   * Std faudes type interface: test equality
   * 
   * @param rOther 
   *    Other object to compare with.
   * @return 
   *   True on match.
   */
  virtual bool DoEqual(const LuaFunctionDefinition& rOther) const;

  /**
   * Read configuration data of this object from TokenReader.
   * Actual reading is done by DoReadCore.
   *
   * The section defaults to "LuaFunctionDefinition", context ignored.
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
   * The section defaults to "LuaFunctionDefinition", context ignored.
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

  /** Typed prototype instance */
  LuaFunction* pLuaFunction;

  /** Lua code */
  std::string mLuaCode;

  /** Lua file */
  std::string mLuaFile;

  /** Default lua state*/
  LuaState* pDefaultL;

}; 


/**
 * Wrapper class to maintain a Lua state.
 *
 * This class is still under construction. It aims for a sensible collection
 * of operations that we may want to execute on a Lua state from the libFAUDES
 * perspective. The current implementation provides static members that directly
 * operate on a lua_State as well as a more comfortable interface that
 * operates on thre wrapped faudes::LusState. 
 *
 * @ingroup LuabindingsPlugin
 */

class FAUDES_API LuaState {
public:
  /**
   * Constructor 
   */
  LuaState(void);   

  /**
   * Destructor
   */
  ~LuaState(void);   

  /**
   * Access Lua state.
   */
  lua_State* LL(void);

  /**
   * Convenience global Lua state.
   */
  static LuaState* G(void);

  /**
   * Reinitialize Lua state.
   *
   * This method reconstructs the internal Lua state.
   * Any references become invalid. Any LuaFunctiondefinitions from
   * the FunctionRegistry will be (re-)installed to the new state.
   */
  void Reset(void);

  /**
   * Install LuaExtension to Lua state.
   * 
   * This function instantiates a LuaFunctionDefinition objects from
   * the file and uses the Install member function to install each function
   * to the specified lua state. Thus, after the extension has been installed,
   * the respective Lua functions can be invoked within Lua as if they where
   * C++ function with SWIG generated wrappers. 
   *
   * Note: if you want to use the extension via the run-time-interface, you
   * must also register them with the FunctionRegistry; see also the static method
   * LuaFunctionDefinition::Register(const std::string&).
   *
   * @param rFilename
   *    Source file (typically .flx)
   */
  void Install(const std::string& rFilename);

  /**
   * Initialze.
   * 
   * Loads std libraries and libFAUDES wrappers.
   *
   * Note: this static version is provided for applications
   * that maintain their lua state themselves. If yo use
   * the wrapper class LuaState, you dont need explicit 
   * initialisation.
   *
   * @param pLL
   *    Lua state
   */
  static void Initialize(lua_State* pLL);

  /**
   * Install LuaExtension to Lua state.
   *
   * Note: this static version is provided for applications
   * that maintain their lua state themselves. If yo use
   * the wrapper class LuaState, you should use the Install(const std::string&) method.
   *
   * @param pLL
   *   Target lua state
   * @param rFilename
   *   Source file
   * @ingroup LuabindingsPlugin
   */
  static void Install(lua_State* pLL, const std::string& rFilename);

  /**
   * Push faudes typed object on the Lua stack.
   *
   * This method uses SWIG generated constructors to instantiate new Lua userdata 
   * object of the same type as the specified data. It than invokes
   * the faudes Assign method to assign a copy. 
   *
   * @param fdata
   *  Data to push
   * @exception Exception
   *   - Lua Error (id 49)
   *
   */
  void Push(const Type* fdata);

  /**
   * Push faudes typed object on the Lua stack.
   *
   * This static version is meant for applications that maintain
   * their Lus state themselves.  See also Push(const Type&)
   *
   * @param pLL
   *  Lua state
   * @param fdata
   *  Data to push
   * @exception Exception
   *   - Lua Error (id 49)
   *
   */
  static void Push(lua_State* pLL, const Type* fdata);

  /**
   * Pop faudes typed object from Lua stack.
   *
   * This method uses SWIG generated type casts to retrieve the
   * faudes object from the userdata on the top of the stack.
   * It then uses the faudes Copy() method to instantiate a copy,
   * to be owned by the caller.
   *
   *
   * @return 
   *   Destination for pop data
   * @exception Exception
   *   - Lua Error (id 49)
   *
   */
  Type* Pop(void);

  /**
   * Pop faudes typed object from Lua stack.
   *
   * This static version is meant for applications that maintain
   * their Lua state themselves.  See also Pop(const Type&)
   *
   * @param pLL
   *  Lua state
   * @return 
   *  Destination for pop data
   * @exception Exception
   *   - Lua Error (id 49)
   *
   */
  static Type* Pop(lua_State* pLL);

  /**
   * Get/set global data
   *
   * This method provides access to global variables.
   * To set a variable, provide a non-NULL fdata parameter.
   * If you obmitt the fdata paraneter, the default will indicate a 
   * get operation. Here, the value is returned as a copy and 
   * owned by the caller.
   *
   * An expection is thrown if the variable either does not exist,
   * or cannot be converted to a faudes::Type.
   *
   * @param gname
   *  Name of global variable
   * @param fdata
   *  Data to set
   * @exception Exception
   *   - Lua Error (id 49)
   *
   */
  Type* Global(const std::string& gname, const Type* fdata=0);

  /**
   * Get/set global data
   *
   * This static version is meant for applications that maintain
   * their Lua state themselves.  See also Globat(const std::string&, const Type*)
   *
   * @param pLL
   *  Lua state
   * @param gname
   *  Name of global variable
   * @param fdata
   *  Data to set
   * @exception Exception
   *   - Lua Error (id 49)
   *
   */
  static Type* Global(lua_State* pLL, const std::string& gname, const Type* fdata=0);

  /**
   * Evaluate Lua expression.
   *
   * This method runs the Lua-interpreter on the specified expression.
   * In the case of an error, an exception will be thrown.
   *
   * @exception Exception
   *   - Lua Error (id 49)
   *
   */
  void Evaluate(const std::string& expr);

  /**
   * Evaluate Lua expression.
   *
   * This static version is meant for applications that maintain
   * their Lua state themselves.  See also Evaluate(const std::string&)
   *
   * @param pLL
   *  Lua state
   * @param expr
   *  Expression to evaluate
   * @exception Exception
   *   - Lua Error (id 49)
   *
   */
  static void Evaluate(lua_State* pLL, const std::string& expr);

  /**
   * Complete Lua identifier
   *
   * This method uses a variation of Mike Pall's advaced readline
   * support patch to fugure possible completions if a string
   * to match a valid identifyer.
   *
   * @param word
   *  String to complete
   * @return
   *  List of completions, first entry is longest common prefix.
   */
  std::list< std::string > Complete(const std::string& word);

  /**
   * Complete Lua identifier
   *
   * This static version is meant for applications that maintain
   * their Lua state themselves.  See also Evaluate(const std::string&)
   *
   * @param pLL
   *  Lua state
   * @param word
   *  String to complete
   * @return
   *  List of completions, first entry is longest common prefix.
   */
  static std::list< std::string > Complete(lua_State* pLL, const std::string& word);


private:
 
  // disable copy constructor
  LuaState(const LuaState&){};
  // lua state
  lua_State* mpLL;
  // open/close lua state
  void Open(void);
  void Close(void);
};


/**
 * A LuaFunction is a faudes-function that executes a luafaudes script. 
 *
 * LuaFunction is derived from Function and implements the DoTypeCheck and DoExecute
 * interface to run the lua code as supplied by the corresponding function defintion.
 * Thus, it is considered an error to set the function definition to an object that
 * does not cast to a LuaFunctionDefinition.
 *
 * @ingroup LuabindingsPlugin
 */  

class FAUDES_API LuaFunction : public Function {

 public:
  /** 
   * Constructor. 
   * For the function to be operational, a valid reference to the corresponding 
   * LuaFunctionDefinition is required. The only exception is the prototype function
   * object used in the LuaFunctionDefinition itself. 
   */
  LuaFunction(const LuaFunctionDefinition* fdef);

  /** Destructor */
  ~LuaFunction(void){};

  /**
   * Construct on heap.
   * Create a new instance of this function class and return pointer.
   * The new instance will use the same function definition as this instance.
   *
   * @return
   * 	Pointer to faudes::Function instance.
   *
   */
  virtual LuaFunction* New() const;


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
  void Definition(const FunctionDefinition* fdef);


  /**
   * Get function definition.
   *
   * @return 
   * 	Function definition used by this function.
   *
   */
  const LuaFunctionDefinition* Definition(void) const;


  /**
   * Syntax check lua code.
   *
   * This routine does all it needs to run the script,
   * except to invoke the specified function. The reasoning is, that
   * the script may hang and, thus, never return. A consequence
   * is, that you must set a variant and you must supply parameter 
   * values befor checking. You may use AllocateValues() and FreeValues() 
   * for this purpose. Errors are indicated by an exception.
   *
   * Note that the LuaFunctionDefinition provides a convenience wrapper
   * that runs the check on all variants and cares about value allocation.
   * 
   * @exception Exception
   *   - No such variant (id 47)
   *   - Error in Lua script (id 49)
   */
  void SyntaxCheck(void);

  /**
   * Evaluate lua code.
   *
   * This routine avaluates the associated Lua code literally, i.e.
   * no arguments are passed, no specific function is invoked.
   * See also Execute().
   * 
   * @exception Exception
   *   - Error in Lua script (id 49)
   */
  void Evaluate(void);


  /**
   * Set lua state
   *
   * Sets the lua state which this function will use for execution. 
   * If set to NULL (e.g. on consruction), the
   * function definition's default state will be used. If
   * this is not set either, the global state is used.
   * 
   * @param l
   *   Lua state
   */
  void L(LuaState* l);

  /**
   * Get default lua state
   *
   * @return
   *   Lua state
   */
  LuaState* L(void);

 protected:

  /*
   * Do set variant from function definition.
   *
   * For LuaFunctions, we accept the special variant -1 for
   * as "no variant", just run the script on execution.
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
  virtual bool DoTypeCheck(int n);

  /**
   * Executes code as supplied by FunctionDefinition
   *
   * @exception Exception
   * 	- Exception during lua setup (id 49)
   * 	- Any exception during execution of script
   */
  virtual void DoExecute();

  /**
   * Execute stages
   *
   * @exception Exception
   * 	- Exception during lua setup (id 49)
   */
  virtual void DoExecuteA();

  /**
   * Execute stages
   *
   * @exception Exception
   * 	- Exception during lua setup (id 49)
   */
  virtual void DoExecuteB();

  /**
   * Execute stages
   *
   * @exception Exception
   * 	- Exception during lua setup (id 49)
   * 	- Any exception during execution of script
   */
  virtual void DoExecuteC();

  /**
   * Execute stages
   *
   * @exception Exception
   * 	- Exception during lua setup (id 49)
   */
  virtual void DoExecuteD();


  /**
   * Execute stages
   *
   * @exception Exception
   * 	- Exception during lua setup (id 49)
   */
  virtual void DoExecuteE();


  /** Typed reference to definition */
  const LuaFunctionDefinition* pLuaFuncDef;

  /** State of Lua interpreter */
  LuaState* pL;
  lua_State* pLL;
  int mFtable;
  int mEntryStack;
  void* mFType;
  std::vector<bool> mLReturn;
  std::vector<bool> mLParameter;
  int mLReturnCount;
  int mLParameterCount;
}; 





} // namespace
#endif 
