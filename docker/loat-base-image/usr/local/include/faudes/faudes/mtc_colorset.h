/** @file mtc_colorset.h

Implements color sets for multitasking automata

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


#ifndef FAUDES_MTCCOLORSET_H
#define FAUDES_MTCCOLORSET_H

#include "corefaudes.h"


namespace faudes {

/**
 * Container for colors: this is a NameSet with its own static symboltable
 *
 * @ingroup MultitaskingPlugin
 */

class FAUDES_API ColorSet : public NameSet {

FAUDES_TYPE_DECLARATION(ColorSet,ColorSet,NameSet)

  public:

    /**
     * Constructor for ColorSet with static ColorSymbolTable. 
     */
    ColorSet(void) : NameSet() { 
      mpSymbolTable= &msSymbolTable; NameSet::Name("Colors"); 
      FD_DC("ColorSet("<<this<<")::ColorSet() with colorsymtab "<< SymbolTablep()); 
    };

    /**
     * Constructor for ColorSet with specified symbol table.
     */
    ColorSet(SymbolTable *pSymTab) : NameSet() { 
      mpSymbolTable= pSymTab; NameSet::Name("Colors"); 
      FD_DC("ColorSet("<<this<<")::ColorSet() with colorsymtab "<< SymbolTablep()); 
    };

    /**
     * Constructor for ColorSet with static ColorSymbolTable.
     * This version reads a file with given label to find the colors
     * inside the file.
     *
     * @param rFilename
     *   Filename
     * @param rLabel
     *   Token label for the colors in the file; default value "Colors"
     */
    ColorSet(const std::string& rFilename, const std::string& rLabel = "Colors") : NameSet()
      { mpSymbolTable= &msSymbolTable; NameSet::Read(rFilename,rLabel);};

    /* Destructor, virtual */
    virtual  ~ColorSet(void) {};

    /**
     * Get pointer to static ColorSymbolTable
     *
     * @return
     *   Pointer to static ColorSymbolTable
     */
    static SymbolTable* StaticSymbolTablep(void);

    /**
     * Reset pointer mpSymbolTable
     *
     * @param pSymTab
     *   Pointer to new symbol table
     */
    void ColorSymbolTablep(SymbolTable *pSymTab);

    /**
     * Set intersection operator
     *
     * @return
     *   Intersection ColorSet
     */
    ColorSet operator * (const ColorSet& rOtherSet) const;

    /**
     * Set union operator
     *
     * @return 
     *   Union Set
     */
    ColorSet operator + (const ColorSet& rOtherSet) const;

    /**
     * Set difference operator
     *
     * @return 
     *   Difference ColorSet
     */
    ColorSet operator - (const ColorSet& rOtherSet) const;

    /** Test for subset
     */
    bool operator <= (const ColorSet& rOtherSet) const;

    /** Test for superset
     */
    bool operator >= (const ColorSet& rOtherSet) const;

  protected:

    /** Static global symbol table for color names */
    static SymbolTable msSymbolTable;

  /**
   * Assign from other color set.
   *
   * @param rSourceSet
   *   Destination to copy from
   * @return
   *   ref to this set
   */
  virtual void DoAssign(const ColorSet& rSourceSet);

}; // end class ColorSet

} // namespace faudes

#endif
