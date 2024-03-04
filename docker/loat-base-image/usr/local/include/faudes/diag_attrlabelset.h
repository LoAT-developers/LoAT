/** @file diag_attrlabelset.h
    Label representation for state estimates.
*/

#ifndef DIAG_LABELSET_H
#define DIAG_LABELSET_H

#include "corefaudes.h"
#include "diag_debug.h"

namespace faudes {

/** 
 * Implements the label representation for state estimates. 
 * This class has its own static SymbolTable and label names are stored in mDiagLabels.
 *
 *   @ingroup DiagnosisPlugIn
 */
class FAUDES_API DiagLabelSet : public AttributeFlags {

FAUDES_TYPE_DECLARATION(Void,DiagLabelSet,AttributeFlags)

 private:
  /** Static global symbol table for possible labels of the diagnoser attribute, e.g.,
      N, A, and specific failure labels. */
  static SymbolTable msLabelSymbolTable;
  /** Static index of label "normal". */
  static Idx msLabelN;
  /** Static index of label "ambiguous". */
  static Idx msLabelA;
  /** Static index of label "relatively normal" (only for diagnoser building purpose).  */
  static Idx msLabelRelN;
  /** Static index of label "specification violated". */
  static Idx msLabelSpecViolated;

 public:
  /** Set of diagnoser label names. */
  NameSet mDiagLabels;
  
 public:

  /** Convenience definition of NameSet::Iterator. */
  typedef NameSet::Iterator Iterator;

  /** Constructor for DiagLabelSet with static LabelSymbolTable. */
  DiagLabelSet(void);

  /** Constructor for DiagLabelSet with specified SymbolTable. */
  DiagLabelSet(SymbolTable *pSymTab);

  /**
     Constructor for DiagLabelSet with static LabelSymbolTable.
     This version reads a file with given label to find the labels
     inside the file.
     @param rFilename
     Filename
     @param rLabel
     Token label for the labels in the file; default value "DiagLabels"
  */
  DiagLabelSet(const std::string& rFilename, const std::string& rLabel = "DiagLabels") {
    mDiagLabels.SymbolTablep(&msLabelSymbolTable);
    mDiagLabels.Read(rFilename,rLabel);
  };

  /**
   *  Test for default value
   *
   *  @return
   *    True for default value
   */
  bool IsDefault(void) const;
  
  /**
     Get pointer to static LabelSymbolTable
     @return
     Pointer to static LabelSymbolTable
  */
  static SymbolTable* StaticLabelSymbolTablep(void);

  /**
     Reset pointer mpSymbolTable
     @param pSymTab
     Pointer to new symbol table
  */
  void LabelSymbolTablep(SymbolTable* pSymTab);

  /**
     Check if mDiagLabels is empty.
     @return
     true if empty
  */
  bool Empty(void) const;

  /**
     Get size of mDiagLabels.
     @return
     Number of indices in mDiagLabels.
  */
  Idx Size(void) const;
  
  /**
     Test existence of index.
     @param index
     Index to test
     @return
     True if index is in this set
  */  
  bool Exists(Idx index) const;

  /**
     Add an element by index. 
     Index must be already known to the global SymbolTable. 
     @param index
     Index to add
     @return 
     True, if element was new to set
  */
  bool Insert(Idx index);
  
  /**
     Insert elements of rSet
     @param rSet
     Indices of elements to add
  */
  void InsertSet(const DiagLabelSet& rSet);
  
  /**
     Delete element by index. The symbolic name is not removed from the SymbolTable.
     @param index
     Index to delete.
     @return 
     True if element did exist.
  */  
  bool Erase(Idx index);

  /**
     Clear mDiagLabels.
  */  
  void Clear(void);
  
  /**
     Return index label "normal".
     @return
     Index of static msLabelN.
  */
  static Idx IndexOfLabelN(void);
  
  /**
     Return index label "ambiguous".
     @return
     Index of static msLabelA.
  */  static Idx IndexOfLabelA(void);
  
  /**
     Return index label "relatively normal".
     @return
     Index of static msLabelRelN.
  */
  static Idx IndexOfLabelRelN(void);
  
  /**
     Return index label "specification violated".
     @return
     Index of static msLabelSpecViolated.
  */
  static Idx IndexOfLabelSpecViolated(void);
  
  /**
     Symbolic name lookup of element in SymbolTable.
     @param index
     Index to look up.
     @return
     Symbolic name of index, or empty string "" for non-existent index.
  */
  static std::string Symbol(Idx index);
  
  /**
     Prints mDiagLabels to a string.
     @return
     String representation of mDiagLabels.
  */  
  std::string Str(void) const;
  
  /**
     Set intersection operator.
     @return
     Intersection DiagLabelSet
  */
  DiagLabelSet operator * (const DiagLabelSet& rOtherSet) const;

  /**
     Set union operator.
     @return 
     Union DiagLabelSet
  */
  DiagLabelSet operator + (const DiagLabelSet& rOtherSet) const;

  /**
     Set difference operator.
     @return 
     Difference DiagLabelSet
  */
  DiagLabelSet operator - (const DiagLabelSet& rOtherSet) const;

  /** Test for subset. */
  bool operator <= (const DiagLabelSet& rOtherSet) const;

  /** Test for superset. */
  bool operator >= (const DiagLabelSet& rOtherSet) const;


 protected:

  /**
     Write mDiagLabels to TokenWriter.
     @param rTw
     Reference to TokenWriter
     @param rLabel
     Is ignored. Label of the section is "DiagLabels".
     @param pContext
     Write context to provide contextual information
  */  
  void DoWrite(TokenWriter& rTw, const std::string& rLabel, const Type* pContext) const;
     
  /**
     Write mDiagLabels to TokenWriter.
     @param rTw
     Reference to TokenWriter
     @param rLabel
     Is ignored. Label of the section is "DiagLabels".
     @param pContext
     Write context to provide contextual information
  */  
  void DoXWrite(TokenWriter& rTw, const std::string& rLabel, const Type* pContext) const;
     
  /**
     Read mDiagLabels from TokenReader.
     @param rTr
     Reference to TokenReader
     @param rLabel
     Is ignored. Label of the section is "DiagLabels".
     @param pContext
     Write context to provide contextual information
  */
  void DoRead(TokenReader &rTr, const std::string &rLabel, const Type *pContext);

  /**
   *  Copy attribute members
   *
   *  @param rSrcAttr 
   *    Source to copy from
   */
  void DoAssign(const DiagLabelSet& rSrcAttr); 
  
  /**
   *  Test equality
   *  @param rOther 
   *    Attribute to compare with
   */
  bool DoEqual(const DiagLabelSet& rOther) const; 

}; // class DiagLabelSet

} // namespace faudes

#endif
