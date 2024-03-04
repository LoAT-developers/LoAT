/** @file mtc_generator.h

Methods for handling multitasking generators

*/

/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2008  Matthias Singer
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


#ifndef FAUDES_MTCGENERATOR_H
#define FAUDES_MTCGENERATOR_H

#include "corefaudes.h"
#include "mtc_attributes.h"
#include <map>

namespace faudes {


/**
 * Allows to create colored marking generators (CMGs) as the common
 * five tupel consisting  of alphabet, stateset, transition relation,
 * initial states, marked states, and attributes for state and event
 * properties. Thus, it is possible to set a control status for
 * events and to add or delete colored markings to single states.
 * Doing so, multitasking generators can be computed and their
 * behaviour be analysed.Methods for examining the color status are
 * included as well as those for making a CMG accessible or strongly
 * coaccessible.  Furthermore, input and output methods for
 * MtcSystems are included.
 *
 * @ingroup MultitaskingPlugin
 */

template <class GlobalAttr, class StateAttr, class EventAttr, class TransAttr>
class FAUDES_API TmtcGenerator : public TcGenerator<GlobalAttr, StateAttr, EventAttr, TransAttr> {

 public:

    /** @name Constructor, Destructor and Copy-Methods */
    /** @{ doxygen group */

    /**
     * Creates an emtpy MtcSystem
     */
    TmtcGenerator(void);
  
    /**
     * Creates an mtcgenerator from another mtcgenerator - copy constructor:
     *
     * If the other MtcSystem uses a local color symbol table, the new
     * generator also creates a local symbol table. This new one is empty! If
     * you use a local symbol table, you should implement a copy mechanism
     * for the entries of the original generator's symbol table.
     *
     * @param rOtherGen
     *   Other mtcgenerator to copy
     */
    TmtcGenerator(const TmtcGenerator& rOtherGen);
  
    /**
     * Creates an mtcgenerator from another generator - copy constructor 
     *
     * @param rOtherGen
     *   Other generator to copy
     */
    TmtcGenerator(const vGenerator& rOtherGen);
  
    /**
     * Constructs an MtcSystem from file
     *
     * Define FAUDES_CHECKED for consistency checks
     *
     * @param rFileName
     *   Filename
     *
     * @exception Exception
     *   - Opening/reading failed (ids 1, 50, 51)
     */
    TmtcGenerator(const std::string& rFileName);

    /**
     * Destructor for MtcSystem
     *
     */
    ~TmtcGenerator(void) { FD_DG("TmtcGenerator(" << this << ")::~TmtcGenerator()");};

    /**
     * Construct on heap. 
     *
     * @return 
     *   New Generator 
     */
    virtual TmtcGenerator* New(void) const;

    /**
     * Construct copy on heap. 
     *
     * @return 
     *   New Generator 
     */
    virtual TmtcGenerator* Copy(void) const;


    /**
     * Assignment
     *
     * @param rSrc
     *   MtcSystem to copy from
     */
    virtual TmtcGenerator& Assign(const Type& rSrc);

    /**
     * Assignment operator (uses Assign)
     *
     * Note: you must reimplement this operator in derived 
     * classes in order to handle internal pointers correctly
     *
     * @param rOtherGen
     *   Other generator
     */
     virtual TmtcGenerator& operator= (const TmtcGenerator& rOtherGen) {return this->Assign(rOtherGen);};

    /** @} doxygen group */

    /** @name Color Symbol Table */
    /** @{ doxygen group */

    /**
     * Get Pointer to global ColorSymbolTable. This is
     * a static member of ColorSet and used as default
     * for all derived classes and instantiated objects.
     *
     * @return
     *   Pointer to global ColorSymbolTable
     */
    SymbolTable* GlobalColorSymbolTablep(void) const;

    /**
     * Get Pointer to ColorSymbolTable currently used
     * by this MtcSystem.
     *
     * @return
     *   Pointer to ColorSymbolTable
     */
    SymbolTable* ColorSymbolTablep(void) const;

    /**
     * Set ColorSymbolTable to be used by this MtcSystem.
     * Note: the managemnt of local color symbol tables needs
     * a re-design. Dont use thus feature.
     *
     * @param pSymTab
     *   Pointer to SymbolTable
     */
    void ColorSymbolTable(SymbolTable* pSymTab);

    /**
     * Set ColorSymbolTable as given by rOtherGen.
     *
     * @param rOtherGen
     *   Other generator 
     */
    void ColorSymbolTable(const TmtcGenerator& rOtherGen);

    /** @} doxygen group */

    /** @name Editing Colored States */
    /** @{ doxygen group */

    /**
     * Create a new named state and set the color rColorName
     *
     * Define FAUDES_CHECKED for consistency checks
     *
     * @param  rStateName
     *   Name of the state to add
     *
     * @param rColorName
     *   Name of the state color
     *
     * @return
     *   Index of new unique state
     *
     * @exception Exception
     *   - Name already exists (id 104)
     *   - Index not member of set (id 200)
     */
    Idx InsColoredState(const std::string& rStateName, const std::string& rColorName);

    /**
     * Create a new named state and set the color colorIndex
     *
     * Define FAUDES_CHECKED for consistency checks
     *
     * @param  rStateName
     *   Name of the state to add
     *
     * @param colorIndex
     *   Index of the state color, must already exist in symbol table
     *
     * @return
     *   Index of new unique state
     *
     * @exception Exception
     *   - Color index not known to symbol table (id 200)
     */
    Idx InsColoredState(const std::string& rStateName, Idx colorIndex);

    /**
     * Create a new named state and set the colors from rColors
     *
     * @param  rStateName
     *   Name of the state to add
     *
     * @param rColors
     *   Color set
     *
     * @return
     *   Index of new unique state
     */
    Idx InsColoredState(const std::string& rStateName, const ColorSet& rColors);

    /**
     * Create a new unnamed state and set the colors from rColors
     *
     * @param rColors
     *   Color set
     *
     * @return
     *   Index of new unique state
     */
    Idx InsColoredState(const ColorSet& rColors);

    /**
     * Insert a color by name into an existing state 
     *
     * Define FAUDES_CHECKED for consistency checks
     *
     * @param stateIndex
     *   Index of state to be set as colored state
     *
     * @param rColorName
     *   Name of state color to be added
     *
     * @return Index of inserted color
     *
     * @exception Exception
     *   - Index not member of set (id 200)
     *   - Name already exists / invalid name (id 104)
     */
    Idx InsColor(Idx stateIndex, const std::string& rColorName);

    /**
     * Insert a color by index into an existing state 
     *
     * Define FAUDES_CHECKED for consistency checks
     *
     * @param stateIndex
     *   Index of state to be set as colored state
     *
     * @param colorIndex
     *   Index of color to be added to state, must already exist in symbol table
     *
     * @exception Exception
     *   - State index not member of set (id 200)
     *   - Color index not known to symbol table (id 200)
     */
    void InsColor(Idx stateIndex, Idx colorIndex);

    /**
     * Insert multiple colors from a color set into an existing state 
     *
     * Define FAUDES_CHECKED for consistency checks
     *
     * @param stateIndex
     *   Index of state to be set as colored state
     *
     * @param rColors
     *   Reference to color set with colors to set for state, colors must already exist in symbol table
     *
     * @exception Exception
     *   - State index not member of set (id 200)
     *   - Symbol table mismach (id 200)
     *   - Symbol table mismatch (id 88)
     */
    void InsColors(Idx stateIndex, const ColorSet& rColors);

    /**
     * Remove color by name from an existing state specified by index
     *
     * Define FAUDES_CHECKED for consistency checks.
     *
     * @param stateIndex
     *   State index
     *
     * @param rColorName
     *   Name of the state color
     *
     * @exception Exception
     *   - Index not member of set (id 200)
     *   - Name not found in NameSet (id 202)
     */
    void DelColor(Idx stateIndex, const std::string& rColorName);
  
    /**
     * Remove color by index form an existing state specified by index
     *
     * Define FAUDES_CHECKED for consistency checks.
     *
     * @param stateIndex
     *   State index
     *
     * @param colorIndex
     *   Index of the state color
     *
     * @exception Exception
     *   - Index not member of set (id 200)
     *   - Color index not found in generator (id 205)
     */
    void DelColor(Idx stateIndex, Idx colorIndex);

    /**
     * Remove color by name from all states
     *
     * @param rColorName
     *   Name of state color
     */
    void DelColor(const std::string& rColorName);

    /**
     * Remove color by index from all states
     *
     * @param colorIndex
     *   Index of state color
     */
    void DelColor(Idx colorIndex);

    /**
     * Remove all colors from a particular state. If symbol table
     * is local, unused colors are deleted from it, global symbol
     * table stays untouched.
     *
     * Define FAUDES_CHECKED for consistency checks
     *
     * @param stateIndex
     *   State where colors should be removed
     *
     * @exception Exception
     *   - Index not member of set (id 200)
     */
    void ClrColors(Idx stateIndex);

    /**
     * Clear all the generator's state attributes. The current implementation
     * also clears the color symbol table if it is local. This behaviour may
     * change in future.
     */
    void ClearStateAttributes();

    /** @} doxygen group */

    /** @name Analyse Colored States and State Colors */
    /** @{ doxygen group */

    /**
     * Insert all colors used in the generator to a given ColorSet.
     *
     * @param rColors
     *   Color set in which all colors of the generator will be inserted
     *
     * @exception Exception
     *   - Symbol table mismatch (id 88)
     */
    void Colors(ColorSet& rColors) const;

    /**
     * Returns a color set containing all the generator's colors.
     *
     * @return
     *   Color set with generators colors
     */
    ColorSet Colors(void) const;

    /**
     * Return a color set which contains all colors of one state.
     *
     * @return
     *   Color set with state's colors
     *
     * @exception Exception
     *   - Index not member of set (id 200)
     */
    const ColorSet& Colors(Idx stateIndex) const;

    /**
     * Returns a state set containing all states that are colored with the color given by index.
     *
     * @param colorIndex
     *    Color whose corresponding states shall be returned
     *
     * @return
     *    State set containing appropriate states
     */
    StateSet ColoredStates(Idx colorIndex) const;
  
    /**
     * Returns a state set containing all states that are colored with the color given by name.
     *
     * @param rColorName
     *    Color whose corresponding states shall be returned
     *
     * @return
     *    State set containing appropriate states
     */
    StateSet ColoredStates(const std::string& rColorName) const;
  
    /**
     * Returns a state set containing all colored states of the MtcSystem.
     *
     * @return
     *    State set containing colored states
     */
    StateSet ColoredStates() const;
  
    /**
     * Returns a state set containing all states that are not colored.
     *
     * @return
     *    State set containing uncolored states
     */
    StateSet UncoloredStates() const;
  
    /**
     * Check if color exists in generator.
     *
     * @param colorIndex
     *   Index which will be examined regarding existence in the generator
     *
     * @return
     *   true if color exists
     */
    bool ExistsColor(Idx colorIndex) const;
  
    /**
     * Check if color exists in generator.
     *
     * Define FAUDES_CHECKED for consistency checks
     *
     * @param rColorName
     *   Color name which will be examined regarding existence in the generator
     *
     * @return
     *   true if color exists
     *
     * @exception Exception
     *   - Color name not found in symbol table (id 202)
     */
    bool ExistsColor(const std::string& rColorName) const;
  
    /**
     * Check if color exists in a given state of the MtcSystem.
     *
     * Define FAUDES_CHECKED for consistency checks
     *
     * @param stateIndex
     *   Index which determines the generator's state
     *
     * @param colorIndex
     *   Color index to look for in given state
     *
     * @return
     *   true if color exists in state
     *
     * @exception Exception
     *   - Index not member of set (id 200)
     */
    bool ExistsColor(Idx stateIndex, Idx colorIndex) const;
  
    /**
     * Check if there is at least one colored state in the MtcSystem.
     *
     * @return
     *    True if there is at least one colored state
     */
    bool IsColored(void) const;
  
    /**
     * Check if the given state is colored or not.
     *
     * Define FAUDES_CHECKED for consistency checks
     *
     * @param stateIndex
     *    State to examine
     *
     * @return
     *    True if given state is colored
     *
     * @exception Exception
     *    - State index not member of set (id 200)
     */
    bool IsColored(Idx stateIndex) const;
  
    /** @} doxygen group */

    /** @name Symbol Table */
    /** @{ doxygen group */

    /**
     * Finally deletes a color name and its index from the currently used symbol table.
     *
     * @param colorIndex
     *   Index of color to delete from symbol table
     */
    void DelColorName(Idx colorIndex);
  
    /**
     * Delete the given color from the symbol table if it is not used anymore in the generator by calling DelColorName.
     *
     * @param colorIndex
     *   Color which will be deleted from symbol table if not used anymore
     */
    void CheckSymbolTable(Idx colorIndex);
  
    /**
     * Delete all colors from the given color set from the color symbol table by calling DelColorName if they are not used anymore. rColors must use the same symbol table as the MtcSystem!
     *
     * @param rColors
     *   Color set with all colors that will be deleted from symbol table if not used anymore
     *
     * @exception Exception
     *   - Symbol table mismatch (id 88)
     */
    void CheckSymbolTable(ColorSet& rColors);
  
    /**
     * Look up the color name for a given color index.
     *
     * @param colorIndex
     *
     * @return 
     *   Color name
     */
    std::string ColorName(Idx colorIndex) const;
  
    /**
     * Look up the color index for a given color name.
     *
     * @param rColorName
     *
     * @return 
     *   Color index
     */
    Idx ColorIndex(const std::string& rColorName) const;
  
    /** @} doxygen group */

    /** @name Output Methods */
    /** @{ doxygen group */

    /**
     * Writes generator to dot input format.

     * The dot file format is specified by the graphiz package; see http://www.graphviz.org. The package includes the dot command 
     * line tool to generate a graphical representation of the generators graph. See also Generator::GraphWrite(). 
     * This functions sets the re-indexing to minimal indices.
     *
     * @param rFileName
     *    Name of file to save result
     */
    virtual void DotWrite(const std::string& rFileName) const;
  
    /**
     * Return pretty printable color name for index. Primary meant for debugging messages.
     *
     * @param index
     *
     * @return std::string
     *   Color name
     */
    std::string CStr(Idx index) const;

    /** @} doxygen group */

    /** @name Reachability */
    /** @{ doxygen group */

    /**
     * Generate a state set with all strongly coaccessible states.
     *
     * @return StateSet
     *    Coaccessible states
     */
    StateSet StronglyCoaccessibleSet(void) const;

    /**
     * Make generator strongly coaccessible. Forbidden states are deleted.
     *
     * @return
     *    True if generator is strongly coaccessible
     *
     * <h4>Example: Computation of the strongly coaccessible form of an MtcSystem </h4>
     * <table border=0> <tr> <td> 
     *   <table width=100%>
     *     <tr> <td> <center> Original MtcSystem gen</center> </td> </tr>
     *     <tr> <td> @image html tmp_mtc_functions_1b_acc.png </td> </tr>
     *     <tr> <td> <center> From state 3 states with other colored markings cannot be reached. So, this generator is weakly coaccessible w.r.t. its color set, but not strongly coaccessible w.r.t. it. </center> </td> </tr>
     *   </table>
     *   </td> </tr>
     *   <tr> <td>
     *   <table width=100%>
     *     <tr> <td> <center> Result of gen.StronglyCoaccessible(); </center> </td> </tr>
     *     <tr> <td> @image html tmp_mtc_functions_1d_str_trim.png </td> </tr>
     *     <tr> <td> <center> Resulting MtcSystem is strongly coaccessible w.r.t its new color set where the color of the primary state 3 is missing </center> </td> </tr>
     *   </table>
     *   </td> </tr>
     * </table>
     */
    bool StronglyCoaccessible(void);

    /**
     * Check if MtcSystem is strongly coaccessible.
     *
     * @return
     *    True if generator is strongly coaccessible
     */
    bool IsStronglyCoaccessible(void) const;

    /**
     * Generate a state set with all the strongly trim generator's states.
     *
     * @return StateSet
     *    All states for which generator is strongly trim
     */
    StateSet StronglyTrimSet(void) const;

    /**
     * Make generator strongly trim. Therefore, the forbidden states are deleted.
     *
     * @return
     *    True if generator is strongly trim
     *
     * <h4>Example: Computation of the strongly trim form of an MtcSystem</h4>
     * <table border=0> <tr> <td>
     *   <table width=100%>
     *     <tr> <td> <center> Original MtcSystem gen</center> </td> </tr>
     *     <tr> <td> @image html tmp_mtc_functions_1a_not_trim.png </td> </tr>
     *     <tr> <td> <center> State 5 is not accessible and from state 3 other states with other colored markings cannot be reached. So, this generator is not accessible and weakly coaccessible w.r.t. its color set. </center> </td> </tr>
     *   </table>
     *   </td> </tr>
     *   <tr> <td>
     *   <table width=100%>
     *     <tr> <td> <center> Result of gen.StronglyTrim(); </center> </td> </tr>
     *     <tr> <td> @image html tmp_mtc_functions_1d_str_trim.png </td> </tr>
     *     <tr> <td> <center> Resulting MtcSystem is strongly trim, which means accessible and strongly coaccessible w.r.t its color set </center> </td> </tr>
     *   </table>
     *   </td> </tr>
     * </table>
     */
    bool StronglyTrim(void);

    /**
     * Check if the MtcSystem is strongly trim.
     *
     * @return
     *    True if generator is strongly trim
     */
    bool IsStronglyTrim(void) const; 

    /** @} doxygen group */

    
    /** @name Further Methods */
    /** @{ doxygen group */

    /**
     * Insert a new local color symbol table. mpColorSymbolTable is reset.
     * The color symbol table pointer in every state attribute's mColors is
     * also reset to the new symbol table. If there already exist color entries
     * in the current symbol table, they are copied to the new local one.
     *
     * Define FAUDES_CHECKED for consistency checks
     *
     * @exception Exception
     *   - Could not insert index and symbol to symbol table (id 44)
     */
    void NewColorSymbolTable();

    /**
     * Return a color map with state indices and their corresponding colors. 
     * Only states with asociated colors are part of this list.
     *
     * @return color map
     *    Standard library map where states and corresponding colors are saved
     */
    std::map<Idx,ColorSet> StateColorMap(void) const;

    /** @} doxygen group */

 protected:
    /**
     * Pointer to currently used symbol table
     */
    SymbolTable *mpColorSymbolTable;

    /** Assignment */
    void DoAssign(const TmtcGenerator& rSrc);

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


}; // end class TmtcGeneraator



// convenience typedef for std MtcSystem
typedef TmtcGenerator<AttributeVoid,AttributeColoredState,AttributeCFlags,AttributeVoid> MtcSystem;


/** Compatibility: pre 2.20b used mtcGenerator as C++ class name*/
#ifdef FAUDES_COMPATIBILITY
typedef TmtcGenerator<AttributeVoid,AttributeColoredState,AttributeCFlags,AttributeVoid> mtcGenerator;
#endif

// convenient scope macors
#define THIS TmtcGenerator<GlobalAttr, StateAttr, EventAttr, TransAttr>
#define BASE TcGenerator<GlobalAttr, StateAttr, EventAttr, TransAttr>
#define TEMP template<class GlobalAttr, class StateAttr, class EventAttr, class TransAttr>


/** 
 * RTI wrapper function. See also MtcSystem::IsStronglyCoaccessible().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API bool IsStronglyCoaccessible(const MtcSystem& rGen);

/** 
 * RTI wrapper function. See also MtcSystem::IsStronglyTrim().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API bool IsStronglyTrim(const MtcSystem& rGen);

/** 
 * RTI wrapper function. See also MtcSystem::Coaccessible().
 * \ingroup GeneratorFunctions 
 */
extern FAUDES_API void StronglyCoaccessible(MtcSystem& rGen);

/** 
 * RTI wrapper function. See also MtcSystem::Coaccessible().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API void StronglyCoaccessible(const MtcSystem& rGen, MtcSystem& rRes);

/** 
 * RTI wrapper function. See also MtcSystem::Trim().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API void StronglyTrim(MtcSystem& rGen);

/** 
 * RTI wrapper function. See also MtcSystem::Trim().
 * \ingroup GeneratorFunctions
 */
extern FAUDES_API void StronglyTrim(const MtcSystem& rGen, MtcSystem& rRes);



// TmtcGenerator(void)
TEMP THIS::TmtcGenerator(void) : BASE() {
  FD_DG("MtcSystem(" << this << ")::MtcSystem()");
  mpColorSymbolTable = GlobalColorSymbolTablep();
}

// TmtcGenerator(rOtherGen)
TEMP THIS::TmtcGenerator(const TmtcGenerator& rOtherGen) : BASE() {
  FD_DG("MtcSystem(" << this << ")::MtcSystem(rOtherGen)");
  if (rOtherGen.ColorSymbolTablep() != ColorSet::StaticSymbolTablep()) 
    NewColorSymbolTable();
  else ColorSymbolTable(GlobalColorSymbolTablep());
  DoAssign(rOtherGen);
}

// TmtcGenerator(rOtherGen)
TEMP THIS::TmtcGenerator(const vGenerator& rOtherGen) : BASE() {
  FD_DG("MtcSystem(" << this << ")::MtcSystem(rOtherGen)");
  ColorSymbolTable(GlobalColorSymbolTablep());
  Assign(rOtherGen);
}

// TmtcGenerator(rFilename)
 TEMP THIS::TmtcGenerator(const std::string& rFileName) : BASE() {
  FD_DG("MtcSystem(" << this << ")::MtcSystem(" << rFileName << ")");
  ColorSymbolTable(GlobalColorSymbolTablep());
  BASE::Read(rFileName);
}

// New/Copy
TEMP THIS* THIS::New(void) const {
  // allocate
  THIS* res = new THIS;
  // fix base data
  res->EventSymbolTablep(BASE::mpEventSymbolTable);
  res->mStateNamesEnabled=BASE::mStateNamesEnabled;
  res->mReindexOnWrite=BASE::mReindexOnWrite;  
  // fix my data
  res->ColorSymbolTable(GlobalColorSymbolTablep());
  // done
  return res;
}

// Copy
TEMP THIS* THIS::Copy(void) const {
  // allocate
  THIS* res = new THIS(*this);
  // done
  return res;
}




// DoAssign(gen)
TEMP void THIS::DoAssign(const TmtcGenerator& rSrc) {
  FD_DG("MtcSystem(" << this << ")::DoAssign(gen&)");
  // call base method
  BASE::DoAssign(rSrc);
  // my members
  ColorSymbolTable(rSrc.ColorSymbolTablep());
  // fix non std symboltable (broken)
  /*
  if (rSrc.ColorSymbolTablep() != ColorSet::StaticSymbolTablep()) {
    NewColorSymbolTable();

    ColorSet mycolors(mpColorSymbolTable);
    Colors(mycolors);
    ColorSet::Iterator cit;
    ColorSet::Iterator cit_end = mycolors.End();

    for (cit = mycolors.Begin(); cit != cit_end; cit++) {
      ColorSymbolTablep()->SetEntry(*cit, ColorName(*cit));
    }
  }
  */
}

// copy from other faudes type
TEMP THIS& THIS::Assign(const Type& rSrc) {
  FD_DG("TmtcGenerator(" << this << ")::Assign([type] " << &rSrc << ")");
  // bail out on match
  if(&rSrc==static_cast<Type*>(this)) return *this;
  // clear to default
  this->Clear();
  // try to cast to this class
  const TmtcGenerator* mtcgen=dynamic_cast<const TmtcGenerator*>(&rSrc);
  if(mtcgen) {
    DoAssign(*mtcgen);
    return *this;
  }  
  // pass on to base
  BASE::Assign(rSrc);
  return *this;
}

// GlobalColorSymbolTablep()
TEMP SymbolTable* THIS::GlobalColorSymbolTablep(void) const {
  return ColorSet::StaticSymbolTablep();
}

// ColorSymbolTablep()
TEMP SymbolTable* THIS::ColorSymbolTablep(void) const {
  return mpColorSymbolTable;
}

// ColorSymbolTable(SymbolTable*)
TEMP void THIS::ColorSymbolTable(SymbolTable* pSymTab) {
  mpColorSymbolTable=pSymTab;
}

// ColorSymbolTable(rOtherGen)
TEMP void THIS::ColorSymbolTable(const TmtcGenerator& rOtherGen) {
  ColorSymbolTable(rOtherGen.ColorSymbolTablep());
}

// InsColoredState(rStateName, rColorName)
TEMP Idx THIS::InsColoredState(const std::string& rStateName, const std::string& rColorName) {
  FD_DG("MtcSystem(" << this << ")::InsColoredState(rStateName, colorName)");
  StateAttr *attr;
  Idx index;
#ifdef FAUDES_CHECKED
  try {
    index = BASE::InsState(rStateName);
  }
  catch (faudes::Exception& exception){
    std::stringstream errstr;
    errstr << "Name \"" << rStateName << "\" already exists" << std::endl;
    throw Exception("MtcSystem::InsColoredState(rStateName, rColorName)", errstr.str(), 104);
  }
  try {
    attr = BASE::StateAttributep(index);
  }
  catch (faudes::Exception& exception){
    std::stringstream errstr;
    errstr << "Index " << index << " not member of set" << std::endl;
    throw Exception("MtcSystem::InsColoredState(stateIndex, colorIndex)", errstr.str(), 200);
  }
  try {
    attr->Colors().Insert(rColorName);
  }
  catch (faudes::Exception& exception){
    std::stringstream errstr;
    errstr << "Name already exists / invalid name: " << rColorName << std::endl;
    throw Exception("MtcSystem::InsColoredState(stateIndex, rColorName)", errstr.str(), 104);
  }
#else
  index = BASE::InsState(rStateName);
  attr = Attributep(index);
  attr->Colors().Insert(rColorName);
#endif
  return index;
}

// InsColoredState(rStateName, colorIndex)
TEMP Idx THIS::InsColoredState(const std::string& rStateName, const Idx colorIndex) {
  Idx index = BASE::InsState(rStateName);
  StateAttr *attr = BASE::StateAttributep(index);
#ifdef FAUDES_CHECKED
  try {
    attr->Colors().Insert(colorIndex);
  }
  catch (faudes::Exception& exception){
    std::stringstream errstr;
    errstr << "Color index " << colorIndex << " not known to symbol table" << std::endl;
    throw Exception("MtcSystem::InsColoredState(rStateName, colorIndex)", errstr.str(), 200);
  }
#else
  attr->Colors().Insert(colorIndex);
#endif
  return index;
}

// InsColoredState(rStateName, rColors)
TEMP Idx THIS::InsColoredState(const std::string& rStateName, const ColorSet& rColors) {
  Idx index = BASE::InsState(rStateName);
  InsColors(index, rColors);
  return index;
}

// InsColoredState(rColors)
TEMP Idx THIS::InsColoredState(const ColorSet& rColors) {
  Idx index = BASE::InsState();
  InsColors(index, rColors);
  return index;
}

// InsColor(stateIndex, rColorName)
TEMP Idx THIS::InsColor(Idx stateIndex, const std::string& rColorName) {
  StateAttr *attr;
  Idx index;
#ifdef FAUDES_CHECKED
  try {
    attr = BASE::StateAttributep(stateIndex);
  }
  catch (faudes::Exception& exception){
    std::stringstream errstr;
    errstr << "State index " << stateIndex << " not member of set" << std::endl;
    throw Exception("MtcSystem::InsColor(stateIndex, colorIndex)", errstr.str(), 200);
  }
  try {
    index = attr->Colors().Insert(rColorName);
  }
  catch (faudes::Exception& exception){
    std::stringstream errstr;
    errstr << "Name already exists / invalid name: " << rColorName << std::endl;
    throw Exception("MtcSystem::InsColor(stateIndex, rColorName)", errstr.str(), 104);
  }
#else
  attr = Attributep(stateIndex);
  index = attr->Colors().Insert(rColorName);
#endif
  return index;
}

// InsColor(stateIndex, colorIndex)
TEMP void THIS::InsColor(Idx stateIndex, Idx colorIndex) {
  StateAttr *attr;
#ifdef FAUDES_CHECKED
  try {
    attr = BASE::StateAttributep(stateIndex);
  }
  catch (faudes::Exception& exception){
    std::stringstream errstr;
    errstr << "State index " << stateIndex << " not member of set" << std::endl;
    throw Exception("MtcSystem::InsColor(stateIndex, colorIndex)", errstr.str(), 200);
  }
  try {
    attr->Colors().Insert(colorIndex);
  }
  catch (faudes::Exception& exception){
    std::stringstream errstr;
    errstr << "Color index " << colorIndex << " not known to symbol table" << std::endl;
    throw Exception("MtcSystem::InsColor(stateIndex, colorIndex)", errstr.str(), 200);
  }
#else
  attr = Attributep(stateIndex);
  attr->Colors().Insert(colorIndex);
#endif
}

// InsColors(stateIndex, rColors)
TEMP void THIS::InsColors(Idx stateIndex, const ColorSet& rColors) {
#ifdef FAUDES_CHECKED
  if(rColors.SymbolTablep() != mpColorSymbolTable) {
    std::stringstream errstr;
    errstr << "Symbol table mismatch" << std::endl;
    throw Exception("MtcSystem::InsColors(stateIndex, rColors)", errstr.str(), 88);
  }
#endif
  StateAttr *attr;
#ifdef FAUDES_CHECKED
  try {
    attr = BASE::StateAttributep(stateIndex);
  }
  catch (faudes::Exception& exception){
    std::stringstream errstr;
    errstr << "State index " << stateIndex << " not member of set" << std::endl;
    throw Exception("MtcSystem::InsColors(stateIndex, rColors)", errstr.str(), 200);
  }
  try {
    attr->Colors().InsertSet(rColors);
  }
  catch (faudes::Exception& exception){
    std::stringstream errstr;
    errstr << "Symbol table mismach" << std::endl;
    throw Exception("MtcSystem::InsColors(stateIndex, rColors)", errstr.str(), 200);
  }
#else
  attr = Attributep(stateIndex);
  attr->Colors().InsertSet(rColors);
#endif
}

// DelColor(stateIndex, rColorName)
TEMP void THIS::DelColor(Idx stateIndex, const std::string& rColorName) {
  StateAttr *attr;
  Idx index;
#ifdef FAUDES_CHECKED
  try {
    attr = BASE::StateAttributep(stateIndex);
  }
  catch (faudes::Exception& exception){
    std::stringstream errstr;
    errstr << "State index " << stateIndex << " not member of set" << std::endl;
    throw Exception("MtcSystem::DelColor(stateIndex, rColorName)", errstr.str(), 200);
  }
  index = ColorIndex(rColorName);
  try {
    attr->Colors().Erase(index);
  }
  catch (faudes::Exception& exception){
    std::stringstream errstr;
    errstr << "Color name \"" << rColorName << "\" not found in NameSet" << std::endl;
    throw Exception("MtcSystem::DelColor(stateIndex, rColorName)", errstr.str(), 202);
  }
#else
  attr = Attributep(stateIndex);
  index = ColorIndex(rColorName);
  attr->Colors().Erase(index);
#endif
  CheckSymbolTable(index);
}

// DelColor(stateIndex, colorIndex)
TEMP void THIS::DelColor(Idx stateIndex, Idx colorIndex) {
  StateAttr *attr;
  bool res;
#ifdef FAUDES_CHECKED
  try {
    attr = BASE::StateAttributep(stateIndex);
  }
  catch (faudes::Exception& exception){
    std::stringstream errstr;
    errstr << "State index " << stateIndex << " not member of set" << std::endl;
    throw Exception("MtcSystem::DelColor(stateIndex, colorIndex)", errstr.str(), 200);
  }
#else
  attr = BASE::StateAttributep(stateIndex);
#endif
  res = attr->Colors().Erase(colorIndex);
  if (!res) {
    std::stringstream errstr;
    errstr << "Color index " << colorIndex << " not found in generator" << std::endl;
    throw Exception("MtcSystem::DelColor(stateIndex, colorIndex)", errstr.str(), 205);
  }
  CheckSymbolTable(colorIndex);
}

// DelColor(rColorName)
TEMP void THIS::DelColor(const std::string& rColorName) {
  StateSet::Iterator lit;
  StateAttr *attr;

  Idx index = ColorIndex(rColorName);

  for (lit = BASE::pStates->Begin(); lit != BASE::pStates->End(); lit++) {
    attr = BASE::StateAttributep(*lit);
    attr->Colors().Erase(index);
  }
  CheckSymbolTable(index);
}

// DelColor(colorIndex)
TEMP void THIS::DelColor(Idx colorIndex) {
  StateSet::Iterator lit;
  StateAttr *attr;
  for (lit = BASE::pStates->Begin(); lit != BASE::pStates->End(); lit++) {
    attr = BASE::StateAttributep(*lit);
    attr->Colors().Erase(colorIndex);
  }
  CheckSymbolTable(colorIndex);
}

// ClrColors(stateIndex)
TEMP void THIS::ClrColors(Idx stateIndex) {
  StateAttr *attr;
  ColorSet::Iterator cit;
  ColorSet delColors(mpColorSymbolTable);
#ifdef FAUDES_CHECKED
  try {
    attr = BASE::StateAttributep(stateIndex);
  }
  catch (faudes::Exception& exception){
    std::stringstream errstr;
    errstr << "State index " << stateIndex << " not member of set" << std::endl;
    throw Exception("MtcSystem::ClrColors(stateIndex)", errstr.str(), 200);
  }
#else
  attr = BASE::StateAttributep(stateIndex);
#endif
  delColors.InsertSet(attr->Colors());
  attr->Colors().Clear();
  CheckSymbolTable(delColors);
}

// DelColorName(colorIndex)
TEMP void THIS::DelColorName(Idx colorIndex) {
  ColorSymbolTablep()->ClrEntry(colorIndex);
}

// Colors(rColors)
TEMP void THIS::Colors(ColorSet& rColors) const {
#ifdef FAUDES_CHECKED
  if(rColors.SymbolTablep() != mpColorSymbolTable) {
    std::stringstream errstr;
    errstr << "Symbol table mismatch" << std::endl;
    throw Exception("MtcSystem::Colors", errstr.str(), 88);
  }
#endif
  StateSet::Iterator lit;
  for (lit = BASE::pStates->Begin(); lit != BASE::pStates->End(); lit++) {
    const StateAttr& attr = BASE::pStates->Attribute(*lit);
    rColors.InsertSet(attr.Colors());
  }
}

// Colors()
TEMP ColorSet THIS::Colors(void) const {
  StateSet::Iterator lit;
  ColorSet colors(mpColorSymbolTable);
  for (lit = BASE::pStates->Begin(); lit != BASE::pStates->End(); lit++) {
    const StateAttr& attr = BASE::pStates->Attribute(*lit);
    colors.InsertSet(attr.Colors());
  }
  return colors;
}

// Colors(stateIndex)
TEMP const ColorSet& THIS::Colors(Idx stateIndex) const {
  const StateAttr* attrp;
#ifdef FAUDES_CHECKED
  try {
    attrp = &BASE::pStates->Attribute(stateIndex);
  }
  catch (faudes::Exception& exception){
    std::stringstream errstr;
    errstr << "State index " << stateIndex << " not member of set" << std::endl;
    throw Exception("MtcSystem::Colors(stateIndex)", errstr.str(), 200);
  }
#else
  attrp = &BASE::pStates->Attribute(stateIndex);
#endif
  return attrp->Colors();
}

// CheckSymbolTable(colorIndex)
TEMP void THIS::CheckSymbolTable(Idx colorIndex) {
  if (ColorSymbolTablep() != ColorSet::StaticSymbolTablep()) {
    ColorSet colors(mpColorSymbolTable);
    Colors(colors);
    if (!colors.Exists(colorIndex))
      DelColorName(colorIndex);
  }
}

// CheckSymbolTable(rColors)
TEMP void THIS::CheckSymbolTable(ColorSet& rColors) {
#ifdef FAUDES_CHECKED
  if(rColors.SymbolTablep() != mpColorSymbolTable) {
    std::stringstream errstr;
    errstr << "Symbol table mismatch" << std::endl;
    throw Exception("MtcSystem::CheckSymbolTable", errstr.str(), 88);
  }
#endif
  if (ColorSymbolTablep() != ColorSet::StaticSymbolTablep()) {
    ColorSet colors(mpColorSymbolTable);
    // all generator's colors are inserted
    Colors(colors);
    ColorSet::Iterator cit;
    for(cit = rColors.Begin(); cit != rColors.End(); cit++) {
      // are colors from rColors still in use?
      if(!colors.Exists(*cit)) DelColorName(*cit);
    }
  }
}

// ExistsColor(colorIndex)
TEMP bool THIS::ExistsColor(Idx colorIndex) const {
  StateSet::Iterator lit;
  for (lit = BASE::StatesBegin(); lit != BASE::StatesEnd(); lit++) {
    if (ExistsColor(*lit, colorIndex)) return true;
  }
  return false;
}

// ExistsColor(colorName)
TEMP bool THIS::ExistsColor(const std::string& rColorName) const {
  Idx colorIndex = ColorIndex(rColorName);
#ifdef FAUDES_CHECKED
  if (colorIndex == 0) {
    std::stringstream errstr;
    errstr << "Color name \"" << rColorName << "\" not found in symbol table  " << std::endl;
    throw Exception("MtcSystem::ExistsColor(rColorName)", errstr.str(), 202);
  }
#endif
  return ExistsColor(colorIndex);
}

// ColorName(index)
TEMP std::string THIS::ColorName(Idx colorIndex) const {
  return ColorSymbolTablep()->Symbol(colorIndex);
}

// ColorIndex(rColorName)
TEMP Idx THIS::ColorIndex(const std::string& rColorName) const {
  return ColorSymbolTablep()->Index(rColorName);
}

// CStr(index)
TEMP std::string THIS::CStr(Idx index) const {
  return ColorName(index);
}

// ExistsColor(stateIndex, colorIndex)
TEMP bool THIS::ExistsColor(Idx stateIndex, Idx colorIndex) const {
#ifdef FAUDES_CHECKED
  try {
    return BASE::pStates->Attribute(stateIndex).Colors().Exists(colorIndex);
  }
  catch (faudes::Exception& exception){
    std::stringstream errstr;
    errstr << "State index " << stateIndex << " not member of set" << std::endl;
    throw Exception("MtcSystem::ExistsColor(stateIndex, colorIndex)", errstr.str(), 200);
  }
#else
  return BASE::pStates->Attribute(stateIndex).Colors().Exists(colorIndex);
#endif
}

// DotWrite(rFileName)
TEMP void THIS::DotWrite(const std::string& rFileName) const {
  FD_DG("TmtcGenerator(" << this << ")::DotWrite(" << rFileName << ")");
  TaIndexSet<StateAttr> coloredStates;
  StateSet::Iterator it;
  BASE::SetMinStateIndexMap();
  typename TransSet::Iterator tit;
  try {
    std::ofstream stream;
    stream.exceptions(std::ios::badbit|std::ios::failbit);
    stream.open(rFileName.c_str());
    stream << "// dot output generated by libFAUDES TmtcGenerator" << std::endl;
    stream << "digraph \"" << BASE::Name() << "\" {" << std::endl;
    stream << "  rankdir=LR" << std::endl;
    stream << "  node [shape=circle];" << std::endl;
    stream << std::endl;
    stream << "  // initial states" << std::endl;
    int i = 1;
    for (it = BASE::InitStatesBegin(); it != BASE::InitStatesEnd(); ++it) {
      std::string xname= BASE::StateName(*it);
      if(xname=="") xname=ToStringInteger(static_cast<long int>(BASE::MinStateIndex(*it)));
      stream << "  dot_dummyinit_" << i << " [shape=none, label=\"\" ];" << std::endl;
      stream << "  dot_dummyinit_" << i << " -> \"" << xname << "\";" << std::endl; 
      i++;
    }
    stream << std::endl;

    // uncolored states - output
    stream << "  // uncolored states" << std::endl;
    for (it = BASE::pStates->Begin(); it != BASE::pStates->End(); ++it) {
      // does the state have a colored attribute?
      const StateAttr& attr = BASE::StateAttribute(*it);
      // handling colored states - copy to coloredStates
      if (!attr.IsDefault()) {
        coloredStates.Insert(*it, attr);
      }
      else {
        std::string xname=BASE::StateName(*it);
        if(xname=="") xname=ToStringInteger(BASE::MinStateIndex(*it));
        stream << "  \"" << xname << "\";" << std::endl;
      }
    }

    // colored states - output
    std::vector<std::string> ColorVector;
    ColorVector.push_back("blue");
    ColorVector.push_back("red");
    ColorVector.push_back("magenta");
    ColorVector.push_back("green");
    ColorVector.push_back("darkorange");
    ColorVector.push_back("cyan");
    ColorVector.push_back("navy");
    ColorVector.push_back("brown");
    ColorVector.push_back("green4");
    ColorVector.push_back("yellow");
    ColorVector.push_back("darkviolet");
    ColorVector.push_back("firebrick");
    ColorVector.push_back("greenyellow");
    ColorVector.push_back("peru");
    ColorVector.push_back("skyblue");
    ColorVector.push_back("darkgreen");
    ColorVector.push_back("violetred");
    ColorVector.push_back("lightsalmon");
    ColorVector.push_back("seagreen");
    ColorVector.push_back("saddlebrown");
    ColorVector.push_back("slateblue");
    ColorVector.push_back("thistle");
    ColorVector.push_back("turquoise4");
    ColorVector.push_back("gold2");
    ColorVector.push_back("sandybrown");
    ColorVector.push_back("aquamarine3");
    ColorVector.push_back("darkolivegreen");
    ColorVector.push_back("yellow4");

    stream << std::endl;
    stream << "  // colored states" << std::endl;
    int clustNr = 0;
    for (it = coloredStates.Begin(); it != coloredStates.End(); it++) {
      int count = 0;
      std::string xname=BASE::StateName(*it);
      if(xname=="") xname=ToStringInteger(static_cast<long int>(BASE::MinStateIndex(*it)));
      const StateAttr& attr = coloredStates.Attribute(*it);
      if (attr.Colors().Size() > 1) {
        for(ColorSet::Iterator cit = attr.ColorsBegin(); cit != attr.ColorsEnd(); cit++) {
          stream << "  subgraph cluster_" << clustNr++ << " {color=" << ColorVector.at(*cit-1) << ";" << std::endl;
          count++;
        }
        stream << "    \"" << xname << "\" " << std::endl << "  ";
        for (int i=0; i<count; i++) {
          stream << "}";
        }
        stream << std::endl;
      }
      else if (attr.Colors().Size() == 1) {
        ColorSet::Iterator cit;
        if ((cit = attr.ColorsBegin()) != attr.ColorsEnd())
          stream << "  \"" << xname << "\" " << "[color=" << ColorVector.at(*cit-1) << "]" << std::endl;
      }
    }
    stream << std::endl;

    // marked states
    stream << "  // marked states" << std::endl;
    for (it = BASE::MarkedStatesBegin(); it != BASE::MarkedStatesEnd(); ++it) {
      std::string xname= BASE::StateName(*it);
      if(xname=="") xname=ToStringInteger(static_cast<long int>(BASE::MinStateIndex(*it)));
      stream << "  \"" << xname << "\";" << std::endl; 
      i++;
    }

    // transitions
    stream << std::endl;
    stream << "  // transition relation" << std::endl;
    for (tit = BASE::TransRelBegin(); tit != BASE::TransRelEnd(); ++tit) {
      std::string x1name= BASE::StateName(tit->X1);
      if(x1name=="") x1name=ToStringInteger(BASE::MinStateIndex(tit->X1));
      std::string x2name= BASE::StateName(tit->X2);
      if(x2name=="") x2name=ToStringInteger(BASE::MinStateIndex(tit->X2));
      stream << "  \"" << x1name  << "\" -> \"" << x2name << "\" [label=\"" << BASE::EventName(tit->Ev) << "\"];" << std::endl;
    }
    stream << "}" << std::endl;
    stream.close();
  }
  catch (std::ios::failure&) {    
    throw Exception("TaGenerator::DotWrite", 
		    "Exception opening/writing dotfile \""+rFileName+"\"", 3);
  }
  BASE::ClearMinStateIndexMap();
}

// StateColorMap()
TEMP 
typename std::map<Idx,ColorSet> 
THIS::StateColorMap(void) const {
  StateSet::Iterator lit;
  std::map<Idx,ColorSet> map;
  StateSet cstates = ColoredStates();
  for (lit = cstates.Begin(); lit != cstates.End(); lit++) {
    map.insert(std::make_pair(*lit, Colors(*lit)));
    FD_DF("make_pair(" << ToStringInteger(*lit) << ", " << (THIS::Colors(*lit).ToString()) << ")");
  }
  return map;
}

// ColoredStates(ColorIndex)
TEMP StateSet THIS::ColoredStates(Idx colorIndex) const {
  StateSet::Iterator lit;
  StateSet coloredStates;
  for (lit = BASE::StatesBegin(); lit != BASE::StatesEnd(); lit++) {
    if(ExistsColor(*lit, colorIndex)) coloredStates.Insert(*lit);
  }
  return coloredStates;
}

// ColoredStates(ColorName)
TEMP StateSet THIS::ColoredStates(const std::string& rColorName) const{
  Idx colorIndex = ColorIndex(rColorName);
  return ColoredStates(colorIndex);
}

// ColoredStates()
TEMP StateSet THIS::ColoredStates() const {
  StateSet::Iterator lit;
  StateSet coloredStates;
  for(lit = BASE::StatesBegin(); lit != BASE::StatesEnd(); lit++) {
    if(IsColored(*lit)) coloredStates.Insert(*lit);
  }
  return coloredStates;
}

// UncoloredStates()
TEMP StateSet THIS::UncoloredStates() const {
  StateSet::Iterator lit;
  StateSet uncoloredStates;
  for (lit = BASE::StatesBegin(); lit != BASE::StatesEnd(); lit++) {
    if (!IsColored(*lit)) uncoloredStates.Insert(*lit);
  }
  return uncoloredStates;
}

// IsColored()
TEMP bool THIS::IsColored(void) const {
  StateSet::Iterator lit;
  for(lit = BASE::StatesBegin(); lit != BASE::StatesEnd(); lit++) {
    if(IsColored(*lit)) return true;
  }
  return false;
}

// IsColored(stateIndex)
TEMP bool THIS::IsColored(Idx stateIndex) const {
#ifdef FAUDES_CHECKED
  try {
    return !BASE::pStates->Attribute(stateIndex).Colors().Empty();
  }
  catch (faudes::Exception& exception){
    std::stringstream errstr;
    errstr << "State index " << stateIndex << " not member of set" << std::endl;
    throw Exception("MtcSystem::IsColored(stateIndex)", errstr.str(), 200);
  }
#else
  return !BASE::pStates->Attribute(stateIndex).Colors().Empty();
#endif
}

TEMP StateSet THIS::StronglyCoaccessibleSet(void) const {
  MtcSystem tmp(*this);
  StateSet stronglyCoac, notStronglyCoac;
  ColorSet colors;
  stronglyCoac = BASE::States();
  Colors(colors);

  ColorSet::Iterator cit = colors.Begin();
  ColorSet::Iterator cit_end = colors.End();

  for (; cit != cit_end; cit++) {
    StateSet tmp1, tmp2;
    StateSet states = ColoredStates(*cit);
    tmp.InjectMarkedStates(states);
    tmp1 = tmp.CoaccessibleSet();
    tmp2 = stronglyCoac * tmp1;
    stronglyCoac = tmp2;
  }
  tmp.ClearMarkedStates();
  return stronglyCoac;
}

TEMP bool THIS::StronglyCoaccessible(void) {
  StateSet stronglyCoacSet = StronglyCoaccessibleSet();
  StateSet notStronglyCoac = BASE::States() - stronglyCoacSet;
  BASE::DelStates(notStronglyCoac);
  return (StronglyCoaccessibleSet() == BASE::States());
}

TEMP bool THIS::IsStronglyCoaccessible(void) const {
  return (StronglyCoaccessibleSet() == BASE::States());
}

// StronglyTrimSet()
TEMP StateSet THIS::StronglyTrimSet(void) const {
  FD_DF("TmtcGenerator::StronglyTrimSet: trim states: "
	<< StateSet(BASE::AccessibleSet() * StronglyCoaccessibleSet()).ToString());
  return BASE::AccessibleSet() * StronglyCoaccessibleSet();
}

// StronglyTrim()
TEMP bool THIS::StronglyTrim(void) {
  // better: compute sets and do one state delete
  bool accessiblebool = BASE::Accessible();
  bool coaccessiblebool = StronglyCoaccessible();
  FD_DF("TmtcGenerator::StronglyTrim: trim states: " <<  (THIS::mpStates->ToString()));
  if (accessiblebool && coaccessiblebool) {
    FD_DF("TmtcGenerator::StronglyTrim: generator is trim");
    return true;
  }
  FD_DF("TmtcGenerator::StronglyTrim: generator is not trim");
  return false;
}

// IsStronglyTrim()
TEMP bool THIS::IsStronglyTrim(void) const {
  if (BASE::IsAccessible() && IsStronglyCoaccessible()) {
    FD_DF("TmtcGenerator::IsStronglyTrim: generator is strongly trim");
    return true;
  }
  else {
    FD_DF("TmtcGenerator::IsStronglyTrim: generator is not strongly trim");
    return false;
  }
}

// NewColorSymbolTable()
TEMP void THIS::NewColorSymbolTable() {

  StateSet::Iterator lit;
  StateAttr *attr;

  StateSet coloredStates = ColoredStates();
  coloredStates.Write();
  SymbolTable *tmp;
  tmp = new SymbolTable;

  // iterate over all colored states
  for (lit = coloredStates.Begin(); lit != coloredStates.End(); lit++) {
    // get attributes for current state
    attr = BASE::pStates->Attributep(*lit);
    ColorSet::Iterator cit, cit_end;
    cit_end = attr->ColorsEnd();
    // iterate over all colors of the current state
    for (cit = attr->ColorsBegin(); cit != cit_end; cit++) {
#ifdef FAUDES_CHECKED
      try {
        // insert color indices and color names to new color symbol table
        tmp->InsEntry(*cit, attr->Colors().SymbolicName(*cit));
      }
      catch (faudes::Exception& exception){
        std::stringstream errstr;
        errstr << "Could not insert index \"" << *cit << "\" and symbol \"" << 
	  attr->Colors().SymbolicName(*cit) << "\" to symbol table" << std::endl;
        throw Exception("MtcSystem::NewColorSymbolTable()", errstr.str(), 44);
      }
#else
      tmp->InsEntry(*cit, attr->Colors().SymbolicName(*cit));
#endif
    }
    // reset color symbol table pointers
    mpColorSymbolTable = tmp;
    attr->ColorSymTab(tmp);
  }
}

// ClearStateAttributes()
TEMP void THIS::ClearStateAttributes() {
  if(ColorSet::StaticSymbolTablep() != mpColorSymbolTable) mpColorSymbolTable->Clear();
  BASE::ClearStateAttributes();
}


// DoSWrite(rTw&)
TEMP void THIS::DoSWrite(TokenWriter& rTw) const {
  // set up color statistics
  std::set<Idx> colcount;
  StateSet::Iterator sit;
  for(sit = BASE::StatesBegin(); sit != BASE::StatesEnd(); sit++) {
    colcount.insert(Colors(*sit).Size());
  }
  // convert to string
  std::multiset<Idx>::iterator cit;
  std::stringstream countstr;
  for(cit = colcount.begin(); cit != colcount.end(); cit++) {
    countstr << *cit << " ";
  }
  // write
  BASE::DoSWrite(rTw);
  rTw.WriteComment(" Colors (all):  " + ToStringInteger(Colors().Size()) );
  rTw.WriteComment(" Colors (dist): " + countstr.str());
  rTw.WriteComment("");
}

#undef BASE
#undef THIS
#undef TEMP

} // namespace faudes

#endif
