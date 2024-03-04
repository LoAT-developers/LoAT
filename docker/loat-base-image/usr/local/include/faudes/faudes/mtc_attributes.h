/** @file mtc_attributes.h

Color attributes for states

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


#ifndef MTC_ATTRIBUTES_H
#define MTC_ATTRIBUTES_H

#include "corefaudes.h"
#include "mtc_colorset.h"

namespace faudes {

/**
 * 
 * State attributes for multitasking automata
 *
 * @ingroup MultitaskingPlugin
 */
class FAUDES_API AttributeColoredState : public AttributeFlags {

FAUDES_TYPE_DECLARATION(Void,AttributeColoredState,AttributeFlags)


  public:

    /** Default constructor */
   AttributeColoredState(void) : AttributeFlags() {
      mpColorSymbolTable=mColors.SymbolTablep(); };

    virtual ~AttributeColoredState(void) {};

    /**
    * Test for default value
    *
    * @return
    *   True for defaultvalue
    */
    bool  IsDefault(void) const {return (mColors.Empty() && (mFlags==mDefFlags)); };

   /**
    * Iterator for first entry in mColors
    */
    NameSet::Iterator ColorsBegin() const;

   /**
    * Iterator for last entry in mColors 
    */
    NameSet::Iterator ColorsEnd() const;

    /**
     * Read access to color set
     *
     * @return
     *   Reference to attribute data
     */
    const ColorSet& Colors(void) const { return mColors;};


    /**
     * Writable access to color set
     *
     * @return
     *   Reference to attribute data
     */
    ColorSet& Colors(void) { return mColors;};

    /**
     * Set the color set
     *
     * @param rColors
     *   New color set
     */
    void Colors(const ColorSet& rColors) { mColors=rColors;};

    /**
    * Set pointer to color symbol table
    *
    * @param pSymTab
    *   New color symbol table
    */
    void ColorSymTab(SymbolTable *pSymTab);

    /**
    * Get pointer to color symbol table
    *
    * @return
    *   Pointer to current color symbol table
    */
    SymbolTable *ColorSymTabp(void) const;

protected:

    /** Colorset */
    ColorSet mColors;

   /** Pointer to colorsymboltable */
    SymbolTable* mpColorSymbolTable;

  /**
   * Assignment method. 
   *
   * @param rSrcAttr
   *    Source to assign from
   */
   virtual void DoAssign(const AttributeColoredState& rSrcAttr);


  /**
   * Test equality of configuration data.
   *
   * @param rOther 
   *    Other attribute to compare with.
   * @return 
   *   True on match.
   */
  virtual bool DoEqual(const AttributeColoredState& rOther) const;

   /**
    * Write attributes to tokenwriter
    *
    * @param rTw
    *   Tokenreader to write to
    * @param rLabel
    *   Section to write
    * @param pContext
    *   Write context to provide contextual information
    *
    * @exception Exception
    *   I/O errors
    */
    virtual void DoWrite(TokenWriter& rTw, const std::string& rLabel="", const Type* pContext=0) const;

   /**
    * Write attributes to tokenwriter
    *
    * @param rTw
    *   Tokenreader to write to
    * @param rLabel
    *   Section to write
    * @param pContext
    *   Write context to provide contextual information
    *
    * @exception Exception
    *   I/O errors
    */
    virtual void DoXWrite(TokenWriter& rTw, const std::string& rLabel="", const Type* pContext=0) const;

    /**
    * Read attributes from tokenreader
    *
    * @param rTr
    *   Tokenreader to read from
    * @param rLabel
    *   Section to read
    * @param pContext
    *   Read context to provide contextual information
    *
    * @exception Exception
    *   Thrown on file format errors (ids 50, 51)
    */
    virtual void DoRead(TokenReader& rTr,const std::string& rLabel="", const Type* pContext=0);



}; // class AttributeColoredState

} // namespace faudes

#endif
