/** @file ios_system.h Generator with I/O-system attributes */

/* 
   Standart IO Systems Plug-In for FAU Discrete Event Systems 
   Library (libfaudes)

   Copyright (C) 2010, Thomas Wittmann, Thomas Moor

*/

#ifndef FAUDES_IOS_SYSTEM_H
#define FAUDES_IOS_SYSTEM_H

#include "corefaudes.h"				
#include "ios_attributes.h"

namespace faudes {


/**
 * Generator with I/O-system attributes. 
 *
 * An IoSystem is a generator with attributes for the
 * representation of I/O systems, i.e., systems with alternating
 * input events U and output events Y. 
 *
 * The IoSystem template assumes that the StateAttr and EventAttr parameter is
 * derived from AttributeIosState and AttributeIosEvent, respectively.
 *
 * @ingroup IoSysPlugin 
 */

template <class GlobalAttr,class StateAttr,class EventAttr,class TransAttr>
class FAUDES_API TioGenerator : public TaGenerator<GlobalAttr,StateAttr,EventAttr,TransAttr>  {    

 public:

    /** @name Constructors & Destructor */
    /** @{ doxygen group */

    /**
     * Default constructor  
     */
    TioGenerator(void);

    /**
     * Default destructor
     */
    ~TioGenerator(void);

    /**
     * Construtor 
     *
     * Create IoSystem from file 
     *
     * @param rFileName
     *   Filename
     *
     * @exception Exception
     *   - File io error (id 1)
     *   - Token mismatch (id 50, 51, ...)
     */
    TioGenerator(const std::string& rFileName);

    /**
     * Constructor 
     *
     * Create IoSystem on heap
     *
     * @return 
     *   new Generator 
     */
    virtual TioGenerator* New(void) const;


    /** 
     * Copy constructor 
     *
     * Create IoSystem from a std. Generator
     *
     * @param rOtherGen
     */
    TioGenerator(const vGenerator& rOtherGen);


    /** 
     * Copy constructor 
     *
     * Create IoSystem from another IoSystem
     *
     * @param rOtherGen
     */
    TioGenerator(const TioGenerator& rOtherGen);

    
    /**
     * Copy Constructor
     *
     * Construct copy on heap
     *
     * @return 
     *   new Generator 
     */
    virtual TioGenerator* Copy(void) const;


    /**
     * Create empty IoSystem with same symboltable as this
     *
     * @return
     *   New Generator
     */
    TioGenerator NewIoSystem(void) const;


    /** @} */

    /** @name Assignment */
    /** @{ doxygen group */


    /**
     * Assignment operator 
     *
     * Note: you must reimplement this operator in derived 
     * classes in order to handle internal pointers correctly
     *
     * @param rOtherGen
     *   Other generator
     */
    virtual TioGenerator& operator= (const TioGenerator& rOtherGen) {this->Assign(rOtherGen); return *this;};
    

    /** @} */

    /** @name Insertion with attributes */
    /** @{ doxygen group */


    /**
     * Insert an output-event by index
     * 
     * An entry in the global event table will be made.
     *
     * Note: event has to exist in the global event table
     *
     * @param index
     *   Event index
     */
    void InsOutputEvent(Idx index);

    /**
     * Insert output event by name.
     *
     * An entry in the global event table will be made if event is new.
     *
     * @param rName
     *   Name of the event to add
     *
     * @return 
     *   New global unique index
     */
    Idx InsOutputEvent(const std::string& rName);
    
    /**
     * Insert a input event by index.
     *
     * Note: event must to exist in the global event table
     *
     * @param index
     *   Event index
     */
    void InsInputEvent(Idx index);


    /**
     * Insert input event by name.
     *
     * An entry in the global event table will be made if event is new.
     *
     * @param rName
     *   Name of the event to add
     *
     * @return 
     *   New global unique index
     */
    Idx InsInputEvent(const std::string& rName);
        

    /** @} */

    /** @name Event attributes  */
    /** @{ doxygen group */

    /**
     * Retrieve all output events
     *
     * @return
     *   Set of all output events
     */
    EventSet OutputEvents(void) const;
    
    /**
     * Set all output events.
     *
     * Mark given events as output events, unmark
     * any other event.
     *
     * @param rEventSet
     *   Set of all output events
     * @exception Exception
     *   - Event does ot exist in generator (id 60)
     */
    void OutputEvents(const EventSet& rEventSet);
    
    /**
     * Test for output event
     *
     * @param index
     *   Event index
     * @return
     *   True / false
     * @exception Exception
     *   - Event does ot exist in generator(id 60)
     */
    bool OutputEvent(Idx index) const;

    /**
     * Test for output event
     *
     * @param rName
     *   Event name
     * @return
     *   True / false
     * @exception Exception
     *   - Event does ot exist in generator (id 60)
     */
    bool OutputEvent(const std::string& rName) const;
    
    /**
     * Mark event as output event 
     *
     * @param index
     *   Event index
     * @exception Exception
     *   - Event does ot exist in generator (id 60)
     */
    void SetOutputEvent(Idx index);

    /**
     * Mark event as output event 
     *
     * @param rName
     *   Event name
     * @exception Exception
     *   - Event does ot exist in generator (id 60)
     */
    void SetOutputEvent(const std::string& rName);

    /**
     * Mark event as output events 
     *
     * @param rEventSet
     *   Set of events to mark
     * @exception Exception
     *   - Some event does ot exist in generator (id 60)
     */
    void SetOutputEvent(const EventSet& rEventSet);

    /**
     * Unmark event as output event 
     *
     * @param index
     *   Event index
     * @exception Exception
     *   - Event does ot exist in generator (id 60)
     */
    void ClrOutputEvent(Idx index);

    /**
     * Unmark event as output event 
     *
     * @param rName
     *   Event name
     * @exception Exception
     *   - Event does ot exist in generator (id 60)
     */
    void ClrOutputEvent(const std::string& rName);

    /**
     * Unmak events as output events 
     *
     * @param rEventSet
     *   Set of events to unmark
     * @exception Exception
     *   - Some event does ot exist in generator (id 60)
     */
    void ClrOutputEvent(const EventSet& rEventSet);


    /**
     * Retrieve all input events
     *
     * @return
     *   Set of all input events
     */
    EventSet InputEvents(void) const;
    
    /**
     * Set all input events.
     *
     * Mark given events as input events, unmark
     * any other event.
     *
     * @param rEventSet
     *   Set of all input events
     * @exception Exception
     *   - Event does ot exist in generator (id 60)
     */
    void InputEvents(const EventSet& rEventSet);
    
    /**
     * Test for input event
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     * @exception Exception
     *   - Event not found in alphabet (id 60)
     */
    bool InputEvent(Idx index) const;

    /**
     * Test for input event
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     * @exception Exception
     *   - Event not found in alphabet (id 60)
     */
    bool InputEvent(const std::string& rName) const;
    
    /**
     * Mark event as input event 
     *
     * @param index
     *   Event index
     * @exception Exception
     *   - Event not found in alphabet (id 60)
     */
    void SetInputEvent(Idx index);

    /**
     * Mark event as input event 
     *
     * @param rName
     *   Event name
     * @exception Exception
     *   - Event not found in alphabet (id 60)
     */
    void SetInputEvent(const std::string& rName);

    /**
     * Mark event as input events 
     *
     * @param rEventSet
     *   Set of events to mark
     * @exception Exception
     *   - Some event not found in alphabet (id 60)
     */
    void SetInputEvent(const EventSet& rEventSet);

    /**
     * Unmark event as input event 
     *
     * @param index
     *   Event index
     * @exception Exception
     *   - Event not found in alphabet (id 60)
     */
    void ClrInputEvent(Idx index);

    /**
     * Unmark event as input event 
     *
     * @param rName
     *   Event name
     * @exception Exception
     *   - Event not found in alphabet (id 60)
     */
    void ClrInputEvent(const std::string& rName);

    /**
     * Unmak events as input events 
     *
     * @param rEventSet
     *   Set of events to unmark
     * @exception Exception
     *   - Some event not found in alphabet (id 60)
     */
    void ClrInputEvent(const EventSet& rEventSet);


    /** @} */

    /** @name State attributes  */
    /** @{ doxygen group */

    /**
     * Retrieve all output states
     *
     * @return
     *   Set of all output states
     */
    StateSet OutputStates(void) const;
    
    /**
     * Set all output states.
     *
     * Mark given states as output states, unmark
     * any other state.
     *
     * @param rStateSet
     *   Set of all output states
     * @exception Exception
     *   - State does ot exist in generator (id 60)
     */
    void OutputStates(const StateSet& rStateSet);
    
    /**
     * Test for output state
     *
     * @param index
     *   State index
     * @return
     *   True / false
     * @exception Exception
     *   - State does ot exist in generator(id 60)
     */
    bool OutputState(Idx index) const;

    /**
     * Test for output state
     *
     * @param rName
     *   State name
     * @return
     *   True / false
     * @exception Exception
     *   - State does ot exist in generator (id 60)
     */
    bool OutputState(const std::string& rName) const;
    
    /**
     * Mark state as output state 
     *
     * @param index
     *   State index
     * @exception Exception
     *   - State does ot exist in generator (id 60)
     */
    void SetOutputState(Idx index);

    /**
     * Mark state as output state 
     *
     * @param rName
     *   State name
     * @exception Exception
     *   - State does ot exist in generator (id 60)
     */
    void SetOutputState(const std::string& rName);

    /**
     * Mark state as output states 
     *
     * @param rStateSet
     *   Set of states to mark
     * @exception Exception
     *   - Some state does ot exist in generator (id 60)
     */
    void SetOutputState(const StateSet& rStateSet);

    /**
     * Unmark state as output state 
     *
     * @param index
     *   State index
     * @exception Exception
     *   - State does ot exist in generator (id 60)
     */
    void ClrOutputState(Idx index);

    /**
     * Unmark state as output state 
     *
     * @param rName
     *   State name
     * @exception Exception
     *   - State does ot exist in generator (id 60)
     */
    void ClrOutputState(const std::string& rName);

    /**
     * Unmak states as output states 
     *
     * @param rStateSet
     *   Set of states to unmark
     * @exception Exception
     *   - Some state does ot exist in generator (id 60)
     */
    void ClrOutputState(const StateSet& rStateSet);


    /**
     * Retrieve all input states
     *
     * @return
     *   Set of all input states
     */
    StateSet InputStates(void) const;
    
    /**
     * Set all input states.
     *
     * Mark given states as input states, unmark
     * any other state.
     *
     * @param rStateSet
     *   Set of all input states
     * @exception Exception
     *   - State does ot exist in generator (id 60)
     */
    void InputStates(const StateSet& rStateSet);
    
    /**
     * Test for input state
     *
     * @param index
     *   State index
     *
     * @return
     *   True / false
     * @exception Exception
     *   - State not found in alphabet (id 60)
     */
    bool InputState(Idx index) const;

    /**
     * Test for input state
     *
     * @param rName
     *   State name
     *
     * @return
     *   True / false
     * @exception Exception
     *   - State not found in alphabet (id 60)
     */
    bool InputState(const std::string& rName) const;
    
    /**
     * Mark state as input state 
     *
     * @param index
     *   State index
     * @exception Exception
     *   - State not found in alphabet (id 60)
     */
    void SetInputState(Idx index);

    /**
     * Mark state as input state 
     *
     * @param rName
     *   State name
     * @exception Exception
     *   - State not found in alphabet (id 60)
     */
    void SetInputState(const std::string& rName);

    /**
     * Mark state as input states 
     *
     * @param rStateSet
     *   Set of states to mark
     * @exception Exception
     *   - Some state not found in alphabet (id 60)
     */
    void SetInputState(const StateSet& rStateSet);

    /**
     * Unmark state as input state 
     *
     * @param index
     *   State index
     * @exception Exception
     *   - State not found in alphabet (id 60)
     */
    void ClrInputState(Idx index);

    /**
     * Unmark state as input state 
     *
     * @param rName
     *   State name
     * @exception Exception
     *   - State not found in alphabet (id 60)
     */
    void ClrInputState(const std::string& rName);

    /**
     * Unmak states as input states 
     *
     * @param rStateSet
     *   Set of states to unmark
     * @exception Exception
     *   - Some state not found in alphabet (id 60)
     */
    void ClrInputState(const StateSet& rStateSet);


    /**
     * Retrieve all error states
     *
     * @return
     *   Set of all error states
     */
    StateSet ErrorStates(void) const;
    
    /**
     * Set all error states.
     *
     * Mark given states as error states, unmark
     * any other state.
     *
     * @param rStateSet
     *   Set of all error states
     * @exception Exception
     *   - State does ot exist in generator (id 60)
     */
    void ErrorStates(const StateSet& rStateSet);
    
    /**
     * Test for error state
     *
     * @param index
     *   State index
     * @return
     *   True / false
     * @exception Exception
     *   - State does ot exist in generator(id 60)
     */
    bool ErrorState(Idx index) const;

    /**
     * Test for error state
     *
     * @param rName
     *   State name
     * @return
     *   True / false
     * @exception Exception
     *   - State does ot exist in generator (id 60)
     */
    bool ErrorState(const std::string& rName) const;
    
    /**
     * Mark state as error state 
     *
     * @param index
     *   State index
     * @exception Exception
     *   - State does ot exist in generator (id 60)
     */
    void SetErrorState(Idx index);

    /**
     * Mark state as error state 
     *
     * @param rName
     *   State name
     * @exception Exception
     *   - State does ot exist in generator (id 60)
     */
    void SetErrorState(const std::string& rName);

    /**
     * Mark state as error states 
     *
     * @param rStateSet
     *   Set of states to mark
     * @exception Exception
     *   - Some state does ot exist in generator (id 60)
     */
    void SetErrorState(const StateSet& rStateSet);

    /**
     * Unmark state as error state 
     *
     * @param index
     *   State index
     * @exception Exception
     *   - State does ot exist in generator (id 60)
     */
    void ClrErrorState(Idx index);

    /**
     * Unmark state as error state 
     *
     * @param rName
     *   State name
     * @exception Exception
     *   - State does ot exist in generator (id 60)
     */
    void ClrErrorState(const std::string& rName);

    /**
     * Unmak states as error states 
     *
     * @param rStateSet
     *   Set of states to unmark
     * @exception Exception
     *   - Some state does ot exist in generator (id 60)
     */
    void ClrErrorState(const StateSet& rStateSet);



    /** @} */

    /** @name Misc  */
    /** @{ doxygen group */

    /**
     * Updates internal attributes. 
     * This method sets the state partition attributes.
     * 
     * @return True if value changed
     */
   
    virtual bool UpdateAttributes(void);

    /** @} */
 private:

 protected:

}; // end class IoSystem


/*
**********************************************************************
**********************************************************************
**********************************************************************

implementation of IoSystem


**********************************************************************
**********************************************************************
**********************************************************************
*/  
 

// typedef for std IoSystem
    
//   globalAttribute:	Void
//   stateAttribute:	IosStateFlags
//   eventAttribute:	IosEventFlags
//   transAttribute:	Void
typedef TioGenerator<AttributeVoid,AttributeIosState, AttributeIosEvent, AttributeVoid> IoSystem;

// convenience shortcuts for relevant class and template types 
#define THIS TioGenerator<GlobalAttr,StateAttr,EventAttr,TransAttr>
#define BASE TaGenerator<GlobalAttr,StateAttr,EventAttr,TransAttr>
#define TEMP template <class GlobalAttr,class StateAttr,class EventAttr,class TransAttr>


// TioGenerator(void)
TEMP THIS::TioGenerator(void) : BASE() {
  //FD_DIO("IoSystem(" << this << ")::IoSystem()");
}

// ~TIOSystem(void)
TEMP THIS::~TioGenerator(void) {
  //FD_DIO("IoSystem(" << this << "::~IoSystem()");
}

// TioGenerator(rFileName)
TEMP THIS::TioGenerator(const std::string& rFileName) : BASE(rFileName) {
  //FD_DIO("IoSystem(" << this << ")::IoSystem(rFilename) : done");
}


// TioGenerator(rOtherGen)
TEMP THIS::TioGenerator(const TioGenerator& rOtherGen) : BASE(rOtherGen) {
  //FD_DIO("IoSystem(" << this << ")::IoSystem(rOtherGen)");
}

// TioGenerator(rOtherGen)
TEMP THIS::TioGenerator(const vGenerator& rOtherGen) : BASE(rOtherGen) {
  //FD_DIO("IoSystem(" << this << ")::IoSystem(rOtherGen)");
}

// New()
TEMP THIS* THIS::New(void) const {
  //FD_DIO("IoSystem(" << this << ")::New()");
  // allocate
  THIS* res = new THIS();
  // fix base data
  res->EventSymbolTablep(BASE::mpEventSymbolTable);
  res->mStateNamesEnabled=BASE::mStateNamesEnabled;
  res->mReindexOnWrite=BASE::mReindexOnWrite;  
  return res;
}

// Copy()
TEMP THIS* THIS::Copy(void) const {
  return new THIS(*this);
}

// NewIoSystem()
TEMP THIS THIS::NewIoSystem(void) const {
  // call base (fixes by assignment constructor)
  THIS res= BASE::NewAGen();
  return res;
}

// InsOutputEvent(index)
TEMP void THIS::InsOutputEvent(Idx index){
  FD_DIO("IoSystem(" << this << ")::InsOutputEvent(" << index << ")");
  EventAttr attr;
  attr.SetOutput();   
  BASE::InsEvent(index,attr);
}

// InsOutputEvent(rName)
TEMP Idx THIS::InsOutputEvent(const std::string& rName) {
  //FD_DIO("IoSystem(" << this << ")::InsOutputEvent(" << rName << ")");
  EventAttr attr;
  attr.SetOutput();
  return BASE::InsEvent(rName,attr);
} 

// InsInputEvent(index)
TEMP void THIS::InsInputEvent(Idx index){
  //FD_DIO("IoSystem(" << this << ")::InsInputEvent(" << index << ")");
  EventAttr attr;
  attr.SetInput();   
  BASE::InsEvent(index,attr);
}

// InsInputEvent(rName)
TEMP Idx THIS::InsInputEvent(const std::string& rName) {
  //FD_DIO("IoSystem(" << this << ")::InsInputEvent(" << rName << ")");
  EventAttr attr;
  attr.SetInput();
  return BASE::InsEvent(rName,attr);
} 



// OutputEvents()
TEMP EventSet THIS::OutputEvents(void) const {
  //FD_DIO("IoSystem(" << this << ")::OutputEvents()");
  EventSet res;
  res.Name("OutputEvents");
  EventSet::Iterator eit;
  for(eit=BASE::AlphabetBegin(); eit!=BASE::AlphabetEnd(); eit++) 
    if(OutputEvent(*eit)) res.Insert(*eit);
  return res;
}

// OutputEvents(rEventSet)
TEMP void THIS::OutputEvents(const EventSet& rEventSet) {
  //FD_DIO("IoSystem(" << this << ")::OutputEvents(" << rEventSet.Name() << ")");
  EventSet::Iterator eit;
  for(eit=BASE::AlphabetBegin(); eit!=BASE::AlphabetEnd(); eit++) 
    if(rEventSet.Exists(*eit)) SetOutputEvent(*eit);
    else ClrOutputEvent(*eit);
}

// OutputEvent(index)
TEMP bool THIS::OutputEvent(Idx index) const {
  return BASE::EventAttribute(index).Output();
} 

// OutputEvent(rName)
TEMP bool THIS::OutputEvent(const std::string& rName) const {
  return BASE::EventAttribute(rName).Output();
} 

// SetOutputEvent(index)
TEMP void THIS::SetOutputEvent(Idx index) {
  //FD_DIO("IoSystem(" << this << ")::SetOutputEvent(" << index << ")");   
  EventAttr attr=BASE::EventAttribute(index);
  attr.SetOutput();
  BASE::pAlphabet->Attribute(index,attr);
} 

// SetOutputEvent(rName)
TEMP void THIS::SetOutputEvent(const std::string& rName) {
  //FD_DIO("IoSystem(" << this << ")::SetOutputEvent(" << rName << ")");
  Idx index = BASE::EventIndex(rName);
  SetOutputEvent(index);
}

// SetOutputEvent(rEventSet)
TEMP void THIS::SetOutputEvent(const EventSet& rEventSet) {
  //FD_DIO("IoSystem(" << this << ")::SetOutputEvent(" << rEventSet.Name() << ")");
  for(EventSet::Iterator eit=rEventSet.Begin(); eit!=rEventSet.End(); eit++) 
    SetOutputEvent(*eit);
}


// ClrOutputEvent(index)
TEMP void THIS::ClrOutputEvent(Idx index) {
  //FD_DIO("IoSystem(" << this << ")::ClrOutputEvent(" << index << ")");   
  EventAttr attr=BASE::EventAttribute(index);
  attr.ClrOutput();
  BASE::pAlphabet->Attribute(index,attr);
} 

// ClrOutputEvent(rName)
TEMP void THIS::ClrOutputEvent(const std::string& rName) {
  //FD_DIO("IoSystem(" << this << ")::ClrOutputEvent(" << rName << ")");
  Idx index = BASE::EventIndex(rName);
  ClrOutputEvent(index);
}

// ClrOutputEvent(rEventSet)
TEMP void THIS::ClrOutputEvent(const EventSet& rEventSet) {
  //FD_DIO("IoSystem(" << this << ")::ClrOutputEvent(" << rEventSet.Name() << ")");
  for(EventSet::Iterator eit=rEventSet.Begin(); eit!=rEventSet.End(); eit++) 
    ClrOutputEvent(*eit);
}


// InputEvents()
TEMP EventSet THIS::InputEvents(void) const {
  //FD_DIO("IoSystem(" << this << ")::InputEvents()");
  EventSet res;
  res.Name("InputEvents");
  EventSet::Iterator eit;
  for(eit=BASE::AlphabetBegin(); eit!=BASE::AlphabetEnd(); eit++) 
    if(InputEvent(*eit)) res.Insert(*eit);
  return res;
}

// InputEvents(rEventSet)
TEMP void THIS::InputEvents(const EventSet& rEventSet) {
  //FD_DIO("IoSystem(" << this << ")::InputEvents(" << rEventSet.Name() << ")");
  EventSet::Iterator eit;
  for(eit=BASE::AlphabetBegin(); eit!=BASE::AlphabetEnd(); eit++) 
    if(rEventSet.Exists(*eit)) SetInputEvent(*eit);
    else ClrInputEvent(*eit);
}


// InputEvent(index)
TEMP bool THIS::InputEvent(Idx index) const {
  return BASE::EventAttribute(index).Input();
} 

// InputEvent(rName)
TEMP bool THIS::InputEvent(const std::string& rName) const {
  return BASE::EventAttribute(rName).Input();
} 

// SetInputEvent(index)
TEMP void THIS::SetInputEvent(Idx index) {
  //FD_DIO("IoSystem(" << this << ")::SetInputEvent(" << index << ")");   
  EventAttr attr=BASE::EventAttribute(index);
  attr.SetInput();
  BASE::pAlphabet->Attribute(index,attr);
} 

// SetInputEvent(rName)
TEMP void THIS::SetInputEvent(const std::string& rName) {
  //FD_DIO("IoSystem(" << this << ")::SetInputEvent(" << rName << ")");
  Idx index = BASE::EventIndex(rName);
  SetInputEvent(index);
}

// SetInputEvent(rEventSet)
TEMP void THIS::SetInputEvent(const EventSet& rEventSet) {
  //FD_DIO("IoSystem(" << this << ")::SetInputEvent(" << rEventSet.Name() << ")");
  for(EventSet::Iterator eit=rEventSet.Begin(); eit!=rEventSet.End(); eit++) 
    SetInputEvent(*eit);
}


// ClrInputEvent(index)
TEMP void THIS::ClrInputEvent(Idx index) {
  //FD_DIO("IoSystem(" << this << ")::ClrInputEvent(" << index << ")");   
  EventAttr attr=BASE::EventAttribute(index);
  attr.ClrInput();
  BASE::pAlphabet->Attribute(index,attr);
} 

// ClrInputEvent(rName)
TEMP void THIS::ClrInputEvent(const std::string& rName) {
  //FD_DIO("IoSystem(" << this << ")::ClrInputEvent(" << rName << ")");
  Idx index = BASE::EventIndex(rName);
  ClrInputEvent(index);
}

// ClrInputEvent(rEventSet)
TEMP void THIS::ClrInputEvent(const EventSet& rEventSet) {
  //FD_DIO("IoSystem(" << this << ")::ClrInputEvent(" << rEventSet.Name() << ")");
  for(EventSet::Iterator eit=rEventSet.Begin(); eit!=rEventSet.End(); eit++) 
    ClrInputEvent(*eit);
}


// OutputStates()
TEMP StateSet THIS::OutputStates(void) const {
  //FD_DIO("IoSystem(" << this << ")::OutputStates()");
  StateSet res;
  res.Name("OutputStates");
  StateSet::Iterator sit;
  for(sit=BASE::StatesBegin(); sit!=BASE::StatesEnd(); sit++) 
    if(OutputState(*sit)) res.Insert(*sit);
  return res;
}

// OutputStates(rStateSet)
TEMP void THIS::OutputStates(const StateSet& rStateSet) {
  FD_DIO("IoSystem(" << this << ")::OutputStates(" << rStateSet.Name() << ")");
  StateSet::Iterator sit;
  for(sit=BASE::StatesBegin(); sit!=BASE::StatesEnd(); sit++) 
    if(rStateSet.Exists(*sit)) SetOutputState(*sit);
    else ClrOutputState(*sit);
}

// OutputState(index)
TEMP bool THIS::OutputState(Idx index) const {
  return BASE::StateAttribute(index).Output();
} 

// OutputState(rName)
TEMP bool THIS::OutputState(const std::string& rName) const {
  Idx index = BASE::StateIndex(rName);
  return BASE::StateAttribute(index).Output();
} 

// SetOutputState(index)
TEMP void THIS::SetOutputState(Idx index) {
  //FD_DIO("IoSystem(" << this << ")::SetOutputState(" << index << ")");   
  StateAttr attr=BASE::StateAttribute(index);
  attr.SetOutput();
  BASE::pStates->Attribute(index,attr);
} 

// SetOutputState(rName)
TEMP void THIS::SetOutputState(const std::string& rName) {
  //FD_DIO("IoSystem(" << this << ")::SetOutputState(" << rName << ")");
  Idx index = BASE::StateIndex(rName);
  SetOutputState(index);
}

// SetOutputState(rStateSet)
TEMP void THIS::SetOutputState(const StateSet& rStateSet) {
  //FD_DIO("IoSystem(" << this << ")::SetOutputState(" << rStateSet.Name() << ")");
  for(StateSet::Iterator eit=rStateSet.Begin(); eit!=rStateSet.End(); eit++) 
    SetOutputState(*eit);
}


// ClrOutputState(index)
TEMP void THIS::ClrOutputState(Idx index) {
  //FD_DIO("IoSystem(" << this << ")::ClrOutputState(" << index << ")");   
  StateAttr attr=BASE::StateAttribute(index);
  attr.ClrOutput();
  BASE::pStates->Attribute(index,attr);
} 

// ClrOutputStateLRName)
TEMP void THIS::ClrOutputState(const std::string& rName) {
  //FD_DIO("IoSystem(" << this << ")::ClrOutputState(" << rName << ")");
  Idx index = BASE::StateIndex(rName);
  ClrOutputState(index);
}

// ClrOutputState(rStateSet)
TEMP void THIS::ClrOutputState(const StateSet& rStateSet) {
  //FD_DIO("IoSystem(" << this << ")::ClrOutputState(" << rStateSet.Name() << ")");
  for(StateSet::Iterator sit=rStateSet.Begin(); sit!=rStateSet.End(); sit++) 
    ClrOutputState(*sit);
}


// InputStates()
TEMP StateSet THIS::InputStates(void) const {
  //FD_DIO("IoSystem(" << this << ")::InputStates()");
  StateSet res;
  res.Name("InputStates");
  StateSet::Iterator sit;
  for(sit=BASE::StatesBegin(); sit!=BASE::StatesEnd(); sit++) 
    if(InputState(*sit)) res.Insert(*sit);
  return res;
}

// InputStates(rStateSet)
TEMP void THIS::InputStates(const StateSet& rStateSet) {
  //FD_DIO("IoSystem(" << this << ")::InputStates(" << rStateSet.Name() << ")");
  StateSet::Iterator sit;
  for(sit=BASE::StatesBegin(); sit!=BASE::StatesEnd(); sit++) 
    if(rStateSet.Exists(*sit)) SetInputState(*sit);
    else ClrInputState(*sit);
}

// InputState(index)
TEMP bool THIS::InputState(Idx index) const {
  return BASE::StateAttribute(index).Input();
} 

// InputState(rName)
TEMP bool THIS::InputState(const std::string& rName) const {
  Idx index = BASE::StateIndex(rName);
  return BASE::StateAttribute(index).Input();
} 

// SetInputState(index)
TEMP void THIS::SetInputState(Idx index) {
  //FD_DIO("IoSystem(" << this << ")::SetInputState(" << index << ")");   
  StateAttr attr=BASE::StateAttribute(index);
  attr.SetInput();
  BASE::pStates->Attribute(index,attr);
} 

// SetInputState(rName)
TEMP void THIS::SetInputState(const std::string& rName) {
  //FD_DIO("IoSystem(" << this << ")::SetInputState(" << rName << ")");
  Idx index = BASE::StateIndex(rName);
  SetInputState(index);
}

// SetInputState(rStateSet)
TEMP void THIS::SetInputState(const StateSet& rStateSet) {
  //FD_DIO("IoSystem(" << this << ")::SetInputState(" << rStateSet.Name() << ")");
  for(StateSet::Iterator sit=rStateSet.Begin(); sit!=rStateSet.End(); sit++) 
    SetInputState(*sit);
}


// ClrInputState(index)
TEMP void THIS::ClrInputState(Idx index) {
  //FD_DIO("IoSystem(" << this << ")::ClrInputState(" << index << ")");   
  StateAttr attr=BASE::StateAttribute(index);
  attr.ClrInput();
  BASE::pStates->Attribute(index,attr);
} 

// ClrInputState(rName)
TEMP void THIS::ClrInputState(const std::string& rName) {
  //FD_DIO("IoSystem(" << this << ")::ClrInputState(" << rName << ")");
  Idx index = BASE::StateIndex(rName);
  ClrInputState(index);
}

// ClrInputState(rStateSet)
TEMP void THIS::ClrInputState(const StateSet& rStateSet) {
  //FD_DIO("IoSystem(" << this << ")::ClrInputState(" << rStateSet.Name() << ")");
  for(StateSet::Iterator sit=rStateSet.Begin(); sit!=rStateSet.End(); sit++) 
    ClrInputState(*sit);
}




// ErrorStates()
TEMP StateSet THIS::ErrorStates(void) const {
  //FD_DIO("IoSystem(" << this << ")::ErrorStates()");
  StateSet res;
  res.Name("ErrorStates");
  StateSet::Iterator sit;
  for(sit=BASE::StatesBegin(); sit!=BASE::StatesEnd(); sit++) 
    if(ErrorState(*sit)) res.Insert(*sit);
  return res;
}

// ErrorStates(rStateSet)
TEMP void THIS::ErrorStates(const StateSet& rStateSet) {
  //FD_DIO("IoSystem(" << this << ")::ErrorStates(" << rStateSet.Name() << ")");
  StateSet::Iterator sit;
  for(sit=BASE::StatesBegin(); sit!=BASE::StatesEnd(); sit++) 
    if(rStateSet.Exists(*sit)) SetErrorState(*sit);
    else ClrErrorState(*sit);
}

// ErrorState(index)
TEMP bool THIS::ErrorState(Idx index) const {
  return BASE::StateAttribute(index).Error();
} 

// ErrorState(rName)
TEMP bool THIS::ErrorState(const std::string& rName) const {
  Idx index = BASE::StateIndex(rName);
  return BASE::StateAttribute(index).Error();
} 

// SetErrorState(index)
TEMP void THIS::SetErrorState(Idx index) {
  //FD_DIO("IoSystem(" << this << ")::SetErrorState(" << index << ")");   
  StateAttr attr=BASE::StateAttribute(index);
  attr.SetError();
  BASE::pStates->Attribute(index,attr);
} 

// SetErrorState(rName)
TEMP void THIS::SetErrorState(const std::string& rName) {
  //FD_DIO("IoSystem(" << this << ")::SetErrorState(" << rName << ")");
  Idx index = BASE::StateIndex(rName);
  SetErrorState(index);
}

// SetErrorState(rStateSet)
TEMP void THIS::SetErrorState(const StateSet& rStateSet) {
  //FD_DIO("IoSystem(" << this << ")::SetErrorState(" << rStateSet.Name() << ")");
  for(StateSet::Iterator sit=rStateSet.Begin(); sit!=rStateSet.End(); sit++) 
    SetErrorState(*sit);
}


// ClrErrorState(index)
TEMP void THIS::ClrErrorState(Idx index) {
  //FD_DIO("IoSystem(" << this << ")::ClrErrorState(" << index << ")");   
  StateAttr attr=BASE::StateAttribute(index);
  attr.ClrError();
  BASE::pStates->Attribute(index,attr);
} 

// ClrErrorState(rName)
TEMP void THIS::ClrErrorState(const std::string& rName) {
  //FD_DIO("IoSystem(" << this << ")::ClrErrorState(" << rName << ")");
  Idx index = BASE::StateIndex(rName);
  ClrErrorState(index);
}

// ClrErrorState(rStateSet)
TEMP void THIS::ClrErrorState(const StateSet& rStateSet) {
  //FD_DIO("IoSystem(" << this << ")::ClrErrorState(" << rStateSet.Name() << ")");
  for(StateSet::Iterator sit=rStateSet.Begin(); sit!=rStateSet.End(); sit++) 
    ClrErrorState(*sit);
}


// Update faudes attributes
TEMP bool THIS::UpdateAttributes(void) {
  //IsIoSystem(*this); 
 return true;
}

    

#undef TEMP
#undef BASE
#undef THIS


} // namespace faudes

#endif
