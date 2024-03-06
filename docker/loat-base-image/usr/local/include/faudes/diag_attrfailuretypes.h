/** @file diag_attrfailuretypes.h
    Contains the failure and indicator partition for a system (used as global attribute).
*/

#ifndef DIAG_ATTRFAILURETYPES_H
#define DIAG_ATTRFAILURETYPES_H

#include <vector>
#include <map>
#include <set>
#include "corefaudes.h"
#include "diag_attrfailureevents.h"
#include "diag_debug.h"

namespace faudes {

/**
 * Partitions the failure and indicator events.
 * This attribute is a wrapper to a nameset with failuretype attributes.
 *
 * Note: formally derived from AttributeFlags for strategic reasons only
 *
 * @ingroup DiagnosisPlugIn
 */
class FAUDES_API AttributeFailureTypeMap : public AttributeFlags {

FAUDES_TYPE_DECLARATION(Void,AttributeFailureTypeMap,AttributeFlags)

   public:

  /** 
   * Failure and indicator event partition. 
   * Mapping of failure type indices (as defined in GlobalEventSymbolTable) 
   * to associated failure events and indicator events. 
   */
  TaNameSet<AttributeFailureEvents> mFailureTypeMap;
  
  /** Default constructor. */
  AttributeFailureTypeMap(void);

  /** Constructor from file. */
  AttributeFailureTypeMap(const std::string& rFilename);
  
  /** Copyconstructor */
  AttributeFailureTypeMap(const AttributeFailureTypeMap& rOtherAttr);

  /** Destructor. */
  ~AttributeFailureTypeMap(void) {};

  /**
   *  Test for default value.
   *
   *  @return
   *    True for default value
   */
  bool IsDefault(void) const;
  
  /**
   * Test if mFailureTypeMap is empty.
   *
   * @return
   *   True if empty
  */
  bool Empty(void) const;

  /**
   *  Clears mFailureTypeMap.
   */
  void Clear(void);

  /**
   *  Add a set of failure events to failure type map. 
   *  Make sure that you do not insert a failure event which is part of another failure type as well!
   *
   *  @param failureType
   *    Name of failure type
   *  @param rfailureEvents
   *    Associated failure events
   *  @return
   *    Index of entry for failure type name in LabelSymbolTable.
   *  @exception Exception
   *  - Adding failure to LabelSymbolTable failed (id 300).
   */
  Idx AddFailureTypeMapping(const std::string& failureType, const EventSet& rfailureEvents);
  
  /**
   *  Inserts entire failure type map to mFailureTypeMap.
   *
   *  @param rFailureMap
   *    Mapping of failure type names to failure events
   */  
  void AddFailureTypeMap(const std::map<std::string,EventSet>& rFailureMap);
  
  /**
   *  Returns failure type of failure event.
   *
   *  @param failureEvent
   *    Index of failure event.
   *  @return
   *    Index of failure type.
   */
  Idx FailureType(Idx failureEvent) const;
  
  /**
   *  Obtain all failure events in mFailureTypeMap.
   *
   *  @return
   *    EventSet containing all failure events.
   */
  EventSet AllFailureEvents(void) const;
  
 protected:
  
  /**
   *  Write mFailureTypeMap to TokenWriter.
   *
   *  @param rTw
   *    Reference to TokenWriter
   *  @param rLabel
   *    Is ignored. Failure events are written in a section "FailureEvents" and indicator events in a separate section "IndicatorEvents".
   *  @param pContext
   *    Write context to provide contextual information
   */
  void DoWrite(TokenWriter& rTw, const std::string& rLabel = "", const Type* pContext = 0) const;
  
  /**
   *  Write mFailureTypeMap to TokenWriter.
   *
   *  @param rTw
   *    Reference to TokenWriter
   *  @param rLabel
   *    Is ignored. Failure events are written in a section "FailureEvents" and indicator events in a separate section "IndicatorEvents".
   *  @param pContext
   *    Write context to provide contextual information
   */
  void DoXWrite(TokenWriter& rTw, const std::string& rLabel = "", const Type* pContext = 0) const;
  
  /**
   *  Read mFailureTypeMap from TokenReader.
   *
   *  @param rTr
   *    Reference to TokenReader
   *  @param rLabel
   *    Is ignored. Failure events are read from section "FailureEvents" and indicator events from section "IndicatorEvents".
   *  @param pContext
   *    Write context to provide contextual information
   */
  void DoRead(TokenReader &rTr, const std::string &rLabel = "", const Type *pContext = 0);
  
  /**
   *  Copy attribute members.
   *
   *  @param rSrcAttr 
   *    Source to copy from
   */
  void DoAssign(const AttributeFailureTypeMap& rSrcAttr);   

  /**
   *  Test equality
   *
   *  @param rAttr 
   *    Other attribute to compare with
   */
   bool  DoEqual(const AttributeFailureTypeMap& rAttr) const;   

  
}; // class AttributeFailureTypeMap


} // namespace faudes

#endif
