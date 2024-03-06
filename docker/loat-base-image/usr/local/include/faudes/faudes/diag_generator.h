/** @file diag_generator.h
    Structure of diagnosers and methods to handle them.
*/


#ifndef DIAG_GENERATOR_H
#define DIAG_GENERATOR_H

#include "corefaudes.h"
#include "diag_attrdiagstate.h"
#include "diag_attrfailuretypes.h"
#include "diag_attrfailureevents.h"

#include "diag_debug.h"

namespace faudes {

/**
   Provides the structure and methods to build and handle diagnosers. 
   The diagnoser states carry state estimates for the generator under observation, which are 
   implemented using state attributes.

   @ingroup DiagnosisPlugIn
*/
template <class GlobalAttr, class StateAttr, class EventAttr, class TransAttr>
class FAUDES_API TdiagGenerator : public TcGenerator <GlobalAttr, StateAttr, EventAttr, TransAttr> {

 private:
    /** Pointer to static LabelSymbolTable of DiagLabelSet. */
    SymbolTable* mpLabelSymbolTable;

 public:  
 
    /** @name Constructor, Destructor */ // and Copy-Methods */
    /** @{ doxygen group */

    /**
     * Creates an emtpy diagnoser 
     */
    TdiagGenerator(void);

    /** 
     * Construct diagnoser from std generator.
     *
     * @param rOtherGen
     */
    TdiagGenerator(const Generator& rOtherGen);
   
    /** 
     * Copy constructor.
     *
     * @param rOtherGen
     */
    TdiagGenerator(const TdiagGenerator& rOtherGen);
   
    /**
     * Construct from file
     *
     * @param rFileName
     *   Filename
     *
     * @exception Exception
     *   If opening/reading fails an Exception object is thrown (id 1, 50, 51)
     */
    TdiagGenerator(const std::string& rFileName);

    /**
     * Construct on heap
     *
     * @return 
     *   new Generator 
     */
    virtual TdiagGenerator* New(void) const;

    /**
     * Construct copy on heap
     *
     * @return 
     *   new Generator 
     */
    virtual TdiagGenerator* Copy(void) const;

    /** Default destructor. */
    ~TdiagGenerator(void) {
      FD_DG("TdiagGenerator(" << this << ")::~TdiagGenerator()");
    }

    /**
     * Assignment operator (uses copy )
     *
     * Note: you must reimplement this operator in derived 
     * classes in order to handle internal pointers correctly
     *
     * @param rOtherGen
     *   Other generator
     */
     virtual TdiagGenerator& operator= (const Generator& rOtherGen) {this->Assign(rOtherGen); return *this;};
    
    /** @} doxygen group */
  
    /**
       Adds a failure type with associated failure events to the global attribute.
       If failure type does already exists the failure events are overridden.
       @param failureType
       Name of failure type.
       @param rfailureEvents
       Associated failure events.
       @return
       Index of failure type in msLabelSymbolTable of DiagLabelSet  
    */
    Idx InsFailureTypeMapping(const std::string& failureType, const EventSet& rfailureEvents);

    /**
       Insert entire failure type map in the diagnoser.
       @param rFailureMap
       Map of failure type names to failure events.
    */  
    void InsFailureTypeMap(const std::map<std::string,EventSet>& rFailureMap);
  
    /**
       Returns the failure type of a particular failure events.
       @param failureEvent
       A failure event.
       @return  
       Index of failure type in msLabelSymbolTable.
    */
    Idx GetFailureType(Idx failureEvent) const;
  
    /**
       Returns the all failure events of the failure partition.
       @return  
       EventSet containing all failure events.
    */
    EventSet GetAllFailureEvents(void) const;
  
    /**
       Inserts a generator state estimate to a diagnoser state.
       @param dStateIndex
       Index of diagnoser state.
       @param gStateIndex
       Index of generator state estimate.
       @param labelIndex
       Index of associated label.
    */
    void InsStateLabelMapping(Idx dStateIndex, Idx gStateIndex, Idx labelIndex);
  
    /**
       Inserts a DiagLabelSet containing a complete set of generator state estimates to a diagnoser state.
       @param dStateIndex
       Index of diagnoser state.
       @param gState
       Index of generator state estimate.
       @param labels
       Associated DiagLabelSet containing the generator state estimates.
    */
    void InsStateLabelMap(Idx dStateIndex, Idx gState, const DiagLabelSet& labels);
  
    /**
       Set a diagnoser state attribute.
       @param dStateIndex
       Index of diagnoser state.
       @param newAttr
       The new attribute.
    */  
    void SetStateAttr(Idx dStateIndex, const AttributeDiagnoserState& newAttr);
  
    /**
       Prints all generator state estimates of a diagnoser state to a string.
       @param dStateIndex
       Index of diagnoser state.
       @return
       String containing state estimates.
    */  
    std::string SAStr(Idx dStateIndex) const;

    /**
       Writes generator to dot input format.
       The dot file format is specified by the graphiz package; see http://www.graphviz.org.
       The package includes the dot command line tool to generate a graphical representation 
       of the generators graph.
       See also Generator::GraphWrite(). This functions sets the re-indexing to minimal indices.
       @param rFileName
       File to write
       @exception Exception
       - IO errors (id 2)
    */
    void DotWrite(const std::string& rFileName) const;
    
 protected:
 

}; // class TdiagGenerator



// convenience typedef for standard diagnoser
typedef TdiagGenerator<AttributeFailureTypeMap, AttributeDiagnoserState, AttributeCFlags, AttributeVoid> Diagnoser;

/** Compatibility: pre 2.20b used diagGenerator as C++ class name*/
#ifdef FAUDES_COMPATIBILITY
typedef TdiagGenerator<AttributeFailureTypeMap, AttributeDiagnoserState, AttributeCFlags, AttributeVoid> diagGenerator;
#endif


/*
 ***********************************************************************
 ***********************************************************************
 ***********************************************************************
 ***********************************************************************

 TdiagGenerator implementation

 ***********************************************************************
 ***********************************************************************
 ***********************************************************************
 ***********************************************************************
 */

// convenient scope macors
#define THIS TdiagGenerator<GlobalAttr, StateAttr, EventAttr, TransAttr>
#define BASE TcGenerator<GlobalAttr, StateAttr, EventAttr, TransAttr>
#define TEMP template<class GlobalAttr, class StateAttr, class EventAttr, class TransAttr>


// TdiagGenerator() - default constructor
TEMP THIS::TdiagGenerator(void) : BASE() {
  FD_DG("TdiagGenerator(" << this << ")::TdiagGenerator()");
  mpLabelSymbolTable = DiagLabelSet::StaticLabelSymbolTablep();
  BASE::mReindexOnWrite=false;
}

// TdiagGenerator(rOtherGen)
TEMP THIS::TdiagGenerator(const TdiagGenerator& rOtherGen) : BASE(rOtherGen) {
  FD_DG("TdiagGenerator(" << this << ")::TdiagGenerator(rOtherGen)");
  mpLabelSymbolTable = DiagLabelSet::StaticLabelSymbolTablep();
  BASE::mReindexOnWrite=false;
}

// TdiagGenerator(rOtherGen)
TEMP THIS::TdiagGenerator(const Generator& rOtherGen) : BASE(rOtherGen) {
  FD_DG("TdiagGenerator(" << this << ")::TdiagGenerator(rOtherGen)");
  mpLabelSymbolTable = DiagLabelSet::StaticLabelSymbolTablep();
  BASE::mReindexOnWrite=false;
}

// TdiagGenerator(rFileName)
TEMP THIS::TdiagGenerator(const std::string& rFileName) : BASE() {
  FD_DG("TDiagGenerator(" << this << ")::TdiagGenerator(rFilename) : done");
  mpLabelSymbolTable = DiagLabelSet::StaticLabelSymbolTablep();
  BASE::mReindexOnWrite=false;
  BASE::Read(rFileName);
}

// New()
TEMP THIS* THIS::New(void) const {
  // allocate
  THIS* res = new THIS();
  // fix base data
  res->EventSymbolTablep(BASE::mpEventSymbolTable);
  res->mStateNamesEnabled=BASE::mStateNamesEnabled;
  res->mReindexOnWrite=BASE::mReindexOnWrite;  
  // fix my data
  res->mpLabelSymbolTable=mpLabelSymbolTable;
  return res;
}

// Copy()
TEMP THIS* THIS::Copy(void) const {
  // allocate
  THIS* res = new THIS(*this);
  // done
  return res;
}


// InsFailureTypeMapping()
TEMP Idx THIS::InsFailureTypeMapping(const std::string& failureType, const EventSet& rfailureEvents) {
  return BASE::pGlobalAttribute->AddFailureTypeMapping(failureType, rfailureEvents);
}

// InsFailureTypeMap()
TEMP void THIS::InsFailureTypeMap(const std::map<std::string,EventSet>& rFailureMap) {
  BASE::pGlobalAttribute->AddFailureTypeMap(rFailureMap);
}

// GetFailureType()
// not used
TEMP Idx THIS::GetFailureType(Idx failureEvent) const {
  return BASE::pGlobalAttribute->FailureType(failureEvent);
}

// GetAllFailureEvents()
TEMP EventSet THIS::GetAllFailureEvents(void) const{
  return BASE::pGlobalAttribute->AllFailureEvents();
}

// InsStateLabelMapping()
TEMP void THIS::InsStateLabelMapping(Idx dStateIndex, Idx gStateIndex, Idx labelIndex) {
  BASE::StateAttributep(dStateIndex)->AddStateLabelMapping(gStateIndex, labelIndex);
}

// InsStateLabelMap()
// not used
TEMP void THIS::InsStateLabelMap(Idx dStateIndex, Idx gState, const DiagLabelSet& labels) {
  BASE::StateAttributep(dStateIndex)->AddStateLabelMap(gState, labels);
}

// SetStateAttr()
// not used
TEMP void THIS::SetStateAttr(Idx dStateIndex, const AttributeDiagnoserState& newAttr) {
  BASE::StateAttribute(dStateIndex,newAttr);
}

// PrettyPrintStateAttr()
TEMP std::string THIS::SAStr(Idx dStateIndex) const {
  return BASE::StateAttribute(dStateIndex).Str();
}

// DotWrite()
TEMP void THIS::DotWrite(const std::string& rFileName) const {
  FD_DG("TdiagGenerator(" << this << ")::DotWrite(" << rFileName << ")");
  BASE::SetMinStateIndexMap();
  StateSet::Iterator lit;
  typename BASE::ATransSet::Iterator tit;
  try {
    std::ofstream stream;
    stream.exceptions(std::ios::badbit|std::ios::failbit);
    stream.open(rFileName.c_str());
    stream << "digraph \"" << BASE::Name() << "\" {" << std::endl;
    stream << "  rankdir=LR" << std::endl;
    stream << "  node [shape=box];" << std::endl;
    stream << std::endl;
    stream << "  // initial states" << std::endl;
    int i = 1;
    for (lit = BASE::InitStatesBegin(); lit != BASE::InitStatesEnd(); ++lit) {
      //std::string xname = BASE::StateName(*lit);
      std::string xname = SAStr(*lit);
      if(xname=="") xname=ToStringInteger(BASE::MinStateIndex(*lit));
      stream << "  dot_dummyinit_" << i << " [shape=none, label=\"\" ];" << std::endl;
      stream << "  dot_dummyinit_" << i << " -> \"" << xname << "\";" << std::endl; 
      i++;
    }
    stream << std::endl;
    stream << "  // marked states" << std::endl;
    for (lit = BASE::MarkedStatesBegin(); lit != BASE::MarkedStatesEnd(); ++lit) {
      //std::string xname= BASE::StateName(*lit);
      std::string xname = SAStr(*lit);
      if(xname=="") xname=ToStringInteger(BASE::MinStateIndex(*lit));
      stream << "  \"" << xname << "\" [shape=doubleoctagon];" << std::endl;
    }
    stream << std::endl;
    stream << "  // rest of stateset" << std::endl;
    for (lit = BASE::StatesBegin(); lit != BASE::StatesEnd(); ++lit) {
      if (! (BASE::ExistsInitState(*lit) || BASE::ExistsMarkedState(*lit)) ) {
  //std::string xname = BASE::StateName(*lit);
  std::string xname = SAStr(*lit);
  if(xname=="") xname=ToStringInteger(BASE::MinStateIndex(*lit));
  stream << "  \"" << xname << "\";" << std::endl;
  //cout << "Label of state " << xname << ": " << PrettyPrintStateAttr(*lit) << endl;
      }
    }
    stream << std::endl;
    stream << "  // transition relation" << std::endl;
    for (tit = BASE::TransRelBegin(); tit != BASE::TransRelEnd(); ++tit) {
      //std::string x1name= BASE::StateName(tit->X1);
      std::string x1name = SAStr(tit->X1);
      if(x1name=="") x1name=ToStringInteger(BASE::MinStateIndex(tit->X1));
      //std::string x2name= BASE::StateName(tit->X2);
      std::string x2name = SAStr(tit->X2);
      if(x2name=="") x2name=ToStringInteger(BASE::MinStateIndex(tit->X2));
      stream << "  \"" << x1name  << "\" -> \"" << x2name
       << "\" [label=\"" << BASE::EventName(tit->Ev) << "\"];" << std::endl;
    }
    stream << "}" << std::endl;
    stream.close();
  }
  catch (std::ios::failure&) {
    throw Exception("TdiagGenerator::DotWrite", 
        "Exception opening/writing dotfile \""+rFileName+"\"", 2);
  } 
  BASE::ClearMinStateIndexMap();
}



#undef THIS
#undef BASE
#undef TEMP

}  // namespace faudes

#endif
