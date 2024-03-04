/** @file diag_attrdiagstate.h State estimates for the current status of the generator (as state attributes). */

#ifndef DIAG_ATTRDIAGSTATE_H
#define DIAG_ATTRDIAGSTATE_H

#include <vector>
#include <map>
#include <set>
#include "corefaudes.h"
#include "diag_attrlabelset.h"
#include "diag_attrfailureevents.h"
#include "diag_debug.h"

namespace faudes {

/** 
 * Implements state estimates for the current status of the generator.
 *  @ingroup DiagnosisPlugIn
 */

class FAUDES_API AttributeDiagnoserState : public AttributeFlags {

FAUDES_TYPE_DECLARATION(Void,AttributeDiagnoserState,AttributeFlags)

private:
  /**
     The diagnoser state attribute is a map of state indices of the original generator
     to their failure label sets. The whole map represents one state label of one particular state.
  */
  TaIndexSet<DiagLabelSet> mDiagnoserStateMap;
  
public:
  /** Default constructor. */
  AttributeDiagnoserState(void);
  
  /** Destructor. */
  ~AttributeDiagnoserState(void);

  /**
   * Test for default value.
   *
   * @return
   *   True for default value.
   */
  bool IsDefault(void) const;
  
  /**
   * Delete the mDiagnoserStateMap.
   */
  virtual void Clear(void);
  
  /**
   * Get mDiagnoserStateMap.
   * @return
   *  mDiagnoserStateMap
   */
  const TaIndexSet<DiagLabelSet>& DiagnoserStateMap(void) const;
  
  /**
   *  Get pointer to mDiagnoserStateMap.
   *
   *  @return
   *    Pointer to mDiagnoserStateMap
   */
  const TaIndexSet<DiagLabelSet>* DiagnoserStateMapp(void) const;
  
  /**
   *  Set mDiagnoserStateMap.
   *
   *  @param newDiagStateMap
   *    New DiagnoserStateMap
   */
  void DiagnoserStateMap(const TaIndexSet<DiagLabelSet>& newDiagStateMap);
  
  /**
   * Add single value of state estimate to mDiagnoserStateMap.
   *
   * @param state
   *   Index of generator state estimate.
   * @param label
   *   Index of associated failure label.
   */
  void AddStateLabelMapping(Idx state, Idx label);

  /**
   * Add state estimates to mDiagnoserStateMap. 
   *
   * @param gstate
   *   Index of generator state estimate.
   * @param labels
   *    Index of associated failure labels.
   */
  void AddStateLabelMap(Idx gstate, const DiagLabelSet& labels);
  
  /**
   *  Pretty printable string of mDiagnoserStateMap.
   *
   *  @return
   *    String representation of mDiagnoserStateMap.
   */
  std::string Str(void) const;

  /**
   *  Check whether state estimate exists in mDiagnoserStateMap.
   *
   *  @param state
   *    Index of state to check.
   *  @return
   *    True if state exists.  
   */
  bool ExistsState(Idx state) const;
  

 protected:

  /**
   *  Copy attribute members
   *  @param rSrc 
   *    Source to copy from
   */
  void DoAssign(const AttributeDiagnoserState& rSrc); 

  /**
   *  Test equality
   *  @param rOther 
   *    Attribute to compare with
   */
  bool DoEqual(const AttributeDiagnoserState& rOther) const; 

  /**
   *  Write mDiagnoserStateMap to TokenWriter.
   *
   *  @param rTw
   *    Reference to TokenWriter
   *  @param rLabel
   *    Is ignored. Label of the section is "StateEstimates".
   *  @param pContext
   *    Write context to provide contextual information
   */  
  void DoWrite(TokenWriter& rTw, const std::string& rLabel, const Type* pContext) const;

  /**
   *  Write mDiagnoserStateMap to TokenWriter.
   *
   *  @param rTw
   *    Reference to TokenWriter
   *  @param rLabel
   *    Is ignored. Label of the section is "StateEstimates".
   *  @param pContext
   *    Write context to provide contextual information
   */  
  void DoXWrite(TokenWriter& rTw, const std::string& rLabel, const Type* pContext) const;

  /**
   *  Read mDiagnoserStateMap from TokenReader.
   *
   *  @param rTr
   *    Reference to TokenReader
   *  @param rLabel
   *    Is ignored. Label of the section is "StateEstimates".
   *  @param pContext
   *    Read context to provide contextual information
   */  
  void DoRead(TokenReader &rTr, const std::string &rLabel, const Type *pContext);
  
}; // class DiagnoserAttribute

} // namespace faudes

#endif
