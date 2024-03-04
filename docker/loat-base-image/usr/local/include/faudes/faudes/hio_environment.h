/** @file hio_environment.h Generator with I/O-environment attributes */

/* Hierarchical IO Systems Plug-In for FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2006  Sebastian Perk 
   Copyright (C) 2006  Thomas Moor 
   Copyright (C) 2006  Klaus Schmidt

*/

#ifndef FAUDES_HIO_ENVIRONMENT_H
#define FAUDES_HIO_ENVIRONMENT_H

#include "corefaudes.h"
#include "hio_attributes.h"

namespace faudes {

/**
 * Generator with I/O-environment attributes. The HioEnvironment is a variant of the 
 * Generator to add an interface for events and states with I/O-environment attributes,
 * built from HioEvent- and HioStateFlags
 * - event attributes: YE   = Y && E
 *                     UE   = U && E
 *                     YL   = Y && L
 *                     UL   = U && L
 * - state attributes: QYe = QY && QE
 *                     QUe  = QU && QE
 *                     QUl  = QU && QL
 *                     QYlUe
 *
 * Technically, the construct is based on the specialized attribute classes
 * faudes::HioEventFlags and faudes::HioStateFlags that provide attributes with
 * semantics for hierarchical I/O properties. The THioEnvironment expects attribute template
 * parameters with the minimum interface defined in HioEventFlags and HioStateFlags.
 * Thus, you can add further semantics by deriving a class HioEventFlagsAndMore  from
 * HioEventFlags (same for HioStateFlags) and use this as event attribute parameter for
 * THioEnvironment. To model a plain finite state machine plus I/O-environment properties, use THioEnvironment
 * with HioEventFlags and HioStateFlags for the event and state attribute parameters
 * and AttributeVoid for the other parameters.
 * For convenience, this has been typedefed as HioEnvironment.
 * 
 * @ingroup hiosysplugin 
 */

template <class GlobalAttr, class StateAttr, class EventAttr, class TransAttr>
class THioEnvironment : public TaGenerator<GlobalAttr, StateAttr, EventAttr, TransAttr> {    
  public:
    /**
     * Creates an empty HioEnvironment object 
     */
    THioEnvironment(void);

    /** 
     * HioEnvironment from a std Generator. Copy constructor 
     *
     * @param rOtherGen
     */
   THioEnvironment(const Generator& rOtherGen);

    /** 
     * HioEnvironment from a std Generator and event sets. Copy constructor 
     *
     * @param rOtherGen
     *	 Generator
     * @param rYl
     *	 alphabet Yl
     * @param rUl
     *	 alphabet Ul
     * @param rYe
     *	 alphabet Ye
     * @param rUe
     *	 alphabet Ue
     */
   THioEnvironment(
   const Generator& rOtherGen,
   const EventSet& rYl,
   const EventSet& rUl,
   const EventSet& rYe,
   const EventSet& rUe
   );
   
    /** 
     * HioEnvironment from a HioEnvironment. Copy constructor 
     *
     * @param rOtherGen
     */
    THioEnvironment(const THioEnvironment& rOtherGen);

    /**
     * construct a HioEnvironment from file
     *
     * @param rFileName
     *   Filename
     *
     * @exception Exception
     *   If opening/reading fails an Exception object is thrown (id 1, 50, 51)
     */
    THioEnvironment(const std::string& rFileName);

    /**
     * Construct on heap
     *
     * @return 
     *   new Generator 
     */
    THioEnvironment* New(void) const;
	
    /**
     * Construct copy on heap
     *
     * @return 
     *   new Generator 
     */
    virtual THioEnvironment* Copy(void) const;

    /**
     * Create empty HioEnvironment with same symboltable as this
     *
     * @return
     *   New Generator
     */
    THioEnvironment NewHioEnvironment(void) const;
	
    /**
     * Assignment operator (uses copy )
     *
     * @param rOtherGen
     *   Other generator
     */
     virtual THioEnvironment& operator= (const THioEnvironment& rOtherGen) {this->Assign(rOtherGen); return *this;};
    
//**************** I/O environment event attributes ********************/

    /**
     * Add an existing Ye-event to generator. 
     * An entry in the global event table will be made.
     *
     * @param index
     *   Event index
     */
    void InsYeEvent(Idx index);

    /**
     * Add new named Ye-event to generator. 
     * An entry in the global event table will be made if event is new.
     *
     * @param rName
     *   Name of the event to add
     *
     * @return 
     *   New global unique index
     */
    Idx InsYeEvent(const std::string& rName);
    
    /**
     * Add an existing Ue-event to generator. 
     * An entry in the global event table will be made.
     *
     * @param index
     *   Event index
     */
    void InsUeEvent(Idx index);

    /**
     * Add new named Ue-event to generator. 
     * An entry in the global event table will be made if event is new.
     *
     * @param rName
     *   Name of the event to add
     *
     * @return 
     *   New global unique index
     */
    Idx InsUeEvent(const std::string& rName);
        
    /**
     * Mark event as Ye-event (by index)
     *
     * @param index
     *   Event index
     */
    void SetYe(Idx index);

    /** 
     * Mark event as Ye-event(by name)
     *
     * @param rName
     *   Event name    
     */
    void SetYe(const std::string& rName);

    /**
     * Mark set of events as Ye-events
     *
     * @param rEvents
     *   EventSet
     */
    void SetYe(const EventSet& rEvents);
        
    /**
     * Mark event Ue-event(by index)
     * 
     * @param index
     *   Event index
     */
    void SetUe(Idx index);

    /**
     * Mark event Ue-event(by name)
     * 
     * @param rName
     *   Event name
     */
    void SetUe(const std::string& rName);

    /**
     * Mark set of events as Ue-events
     *
     * @param rEvents
     *   EventSet
     */
    void SetUe(const EventSet& rEvents);
          
    /**
     * Is event Ye-event(by index)
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     */
    bool IsYe(Idx index) const;

    /**
     * Is event Ye-event(by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool IsYe(const std::string& rName) const;
    
    /**
     * Is event Ue-event(by index)
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     */
    bool IsUe(Idx index) const;

    /**
     * Is event Ue-event(by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool IsUe(const std::string& rName) const;

    /** 
     * Get EventSet with Ye-events
     *
     * @return
     *   EventSet of Ye-events
     */
    EventSet YeEvents(void) const;

    /**
     * Get EventSet with Ue-events
     *
     * @return 
     *   EventSet of Ue-events
     */
    EventSet UeEvents(void) const;

    /**
     * Add an existing Yl-event to generator. 
     * An entry in the global event table will be made.
     *
     * @param index
     *   Event index
     */
    void InsYlEvent(Idx index);
   
   /**
     * Add new named Yl-event to generator. 
     * An entry in the global event table will be made if event is new.
     *
     * @param rName
     *   Name of the event to add
     *
     * @return 
     *   New global unique index
     */
    Idx InsYlEvent(const std::string& rName);
    
    /**
     * Add an existing Ul-event to generator. 
     * An entry in the global event table will be made.
     *
     * @param index
     *   Event index
     */
    void InsUlEvent(Idx index);

    /**
     * Add new named Ul-event to generator. 
     * An entry in the global event table will be made if event is new.
     *
     * @param rName
     *   Name of the event to add
     *
     * @return 
     *   New global unique index
     */
    Idx InsUlEvent(const std::string& rName);
        
    /**
     * Mark event as Yl-event (by index)
     *
     * @param index
     *   Event index
     */
    void SetYl(Idx index);

    /** 
     * Mark event as Yl-event (by name)
     *
     * @param rName
     *   Event name    
     */
    void SetYl(const std::string& rName);

    /**
     * Mark set of events as Yl-events
     *
     * @param rEvents
     *   EventSet
     */
    void SetYl(const EventSet& rEvents);
        
    /**
     * Mark event as Ul-event (by index)
     * 
     * @param index
     *   Event index
     */
    void SetUl(Idx index);

    /**
     * Mark event as Ul-event (by name)
     * 
     * @param rName
     *   Event name
     */
    void SetUl(const std::string& rName);

    /**
     * Mark set of events as Ul-events 
     *
     * @param rEvents
     *   EventSet
     */
    void SetUl(const EventSet& rEvents);
          
    /**
     * Is event Yl-event (by index)
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     */
    bool IsYl(Idx index) const;

    /**
     * Is event Yl-event (by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool IsYl(const std::string& rName) const;

    /**
     * Is event Ul-event (by index)
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     */
    bool IsUl(Idx index) const;

    /**
     * Is event Ul-event (by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool IsUl(const std::string& rName) const;

    /** 
     * Get EventSet with Yl-events
     *
     * @return
     *   EventSet of Yl-events
     */
    EventSet YlEvents(void) const;

    /**
     * Get EventSet with Ul-events
     *
     * @return 
     *   EventSet of Ul-events
     */
    EventSet UlEvents(void) const;


//************** query elementary event attributes ****************************/
    /**
     * Is event Y-event? (by index)
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     */
    bool IsY(Idx index) const;

    /**
     * Is event Y-event? (by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool IsY(const std::string& rName) const;

    /** 
     * Get EventSet with Y-events
     *
     * @return
     *   EventSet of Y-events
     */
    EventSet YEvents(void) const;

    /**
     * Is event U-event? (by index)
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     */
    bool IsU(Idx index) const;

    /**
     * Is event U-event? (by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool IsU(const std::string& rName) const;

    /**
     * Get EventSet with U-events
     *
     * @return 
     *   EventSet of U-events
     */
    EventSet UEvents(void) const;
          
    /**
     * Is event P-event? (by index)
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     */
    bool IsE(Idx index) const;

    /**
     * Is event P-event? (by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool IsE(const std::string& rName) const;

    /** 
     * Get EventSet with P-events
     *
     * @return
     *   EventSet of P-events
     */
    EventSet EEvents(void) const;
    
    /**
     * Is event E-event? (by index)
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     */
    bool IsL(Idx index) const;

    /**
     * Is event E-event? (by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool IsL(const std::string& rName) const;    

    /**
     * Get EventSet with E-events
     *
     * @return 
     *   EventSet of E-events
     */
    EventSet LEvents(void) const;
/******************************************************/


/*************** I/O environment state attributes **********************/

    /**
     * Mark event as QYe-state (by index)
     *
     * @param index
     *   State index
     */
    void SetQYe(Idx index);

    /** 
     * Mark state as QYe-state (by name)
     *
     * @param rName
     *   State name    
     */
    void SetQYe(const std::string& rName);

    /**
     * Mark set of states as QYe-states
     *
     * @param rStates
     *   StateSet
     */
    void SetQYe(const StateSet& rStates);
    
    /** Mark state as NOT QYe-state (by index)
     * 
     * @param index
     *   State index
     */
    void ClrQYe(Idx index);

    /**
     * Mark state as NOT QYe-state (by name)
     * 
     * @param rName
     *   State name
     */
    void ClrQYe(const std::string& rName);

    /** 
     * Mark set of states as NOT QYe-states (by index)
     *
     * @param rStates
     *   StateSet
     */
    void ClrQYe(const StateSet& rStates);

    /** Is state QYe-state (by index)
     *
     * @param index
     *   State index
     *
     * @return
     *   True / false
     */
    bool IsQYe(Idx index) const;

    /**
     * Is state QYe-state (by name)
     *
     * @param rName
     *   State name
     *
     * @return
     *   True / false
     */
    bool IsQYe(const std::string& rName) const;

    /**
     * Get StateSet with QYe-states
     *
     * @return 
     *   StateSet of QYe-states
     */
    StateSet QYeStates(void) const;
    
    /**
     * Mark event as QUe-state (by index)
     *
     * @param index
     *   State index
     */
    void SetQUe(Idx index);

    /** 
     * Mark state as QUe-state (by name)
     *
     * @param rName
     *   State name    
     */
    void SetQUe(const std::string& rName);

    /**
     * Mark set of states as QUe-states
     *
     * @param rStates
     *   StateSet
     */
    void SetQUe(const StateSet& rStates);
    
    /** Mark state as NOT QUe-state (by index)
     * 
     * @param index
     *   State index
     */
    void ClrQUe(Idx index);

    /**
     * Mark state as NOT QUe-state (by name)
     * 
     * @param rName
     *   State name
     */
    void ClrQUe(const std::string& rName);

    /** 
     * Mark set of states as NOT QUe-states (by index)
     *
     * @param rStates
     *   StateSet
     */
    void ClrQUe(const StateSet& rStates);

    /** Is state QUe-state (by index)
     *
     * @param index
     *   State index
     *
     * @return
     *   True / false
     */
    bool IsQUe(Idx index) const;

    /**
     * Is state QUe-state (by name)
     *
     * @param rName
     *   State name
     *
     * @return
     *   True / false
     */
    bool IsQUe(const std::string& rName) const;
    
    /**
     * Get StateSet with QUe-states
     *
     * @return 
     *   StateSet of QUe-states
     */
    StateSet QUeStates(void) const;

    /**
     * Mark event as QUl-state (by index)
     *
     * @param index
     *   State index
     */
    void SetQUl(Idx index);

    /** 
     * Mark state as QUl-state (by name)
     *
     * @param rName
     *   State name    
     */
    void SetQUl(const std::string& rName);

    /**
     * Mark set of states as QUl-states
     *
     * @param rStates
     *   StateSet
     */
    void SetQUl(const StateSet& rStates);
    
    /** Mark state as NOT QUl-state (by index)
     * 
     * @param index
     *   State index
     */
    void ClrQUl(Idx index);

    /**
     * Mark state as NOT QUl-state (by name)
     * 
     * @param rName
     *   State name
     */
    void ClrQUl(const std::string& rName);

    /** 
     * Mark set of states as NOT QUl-states (by index)
     *
     * @param rStates
     *   StateSet
     */
    void ClrQUl(const StateSet& rStates);

    /** Is state QUl-state (by index)
     *
     * @param index
     *   State index
     *
     * @return
     *   True / false
     */
    bool IsQUl(Idx index) const;

    /**
     * Is state QUl-state (by name)
     *
     * @param rName
     *   State name
     *
     * @return
     *   True / false
     */
    bool IsQUl(const std::string& rName) const;
    
    /**
     * Get StateSet with QUl-states
     *
     * @return 
     *   StateSet of QUl-states
     */
    StateSet QUlStates(void) const;

    /**
     * Mark event as QYlUe-state (by index)
     *
     * @param index
     *   State index
     */
    void SetQYlUe(Idx index);

    /** 
     * Mark state as QYlUe-state (by name)
     *
     * @param rName
     *   State name    
     */
    void SetQYlUe(const std::string& rName);

    /**
     * Mark set of states as QYlUe-states
     *
     * @param rStates
     *   StateSet
     */
    void SetQYlUe(const StateSet& rStates);
    
    /** Mark state as NOT QYlUe-state (by index)
     * 
     * @param index
     *   State index
     */
    void ClrQYlUe(Idx index);

    /**
     * Mark state as NOT QYlUe-state (by name)
     * 
     * @param rName
     *   State name
     */
    void ClrQYlUe(const std::string& rName);

    /** 
     * Mark set of states as NOT QYlUe-states (by index)
     *
     * @param rStates
     *   StateSet
     */
    void ClrQYlUe(const StateSet& rStates);

    /** Is state QYlUe-state (by index)
     *
     * @param index
     *   State index
     *
     * @return
     *   True / false
     */
    bool IsQYlUe(Idx index) const;

    /**
     * Is state QYlUe-state (by name)
     *
     * @param rName
     *   State name
     *
     * @return
     *   True / false
     */
    bool IsQYlUe(const std::string& rName) const;
    
    /**
     * Get StateSet with QYlUe-states
     *
     * @return 
     *   StateSet of QYlUe-states
     */
    StateSet QYlUeStates(void) const;

  /**
     * Mark state as Err-state (by index)
     *
     * @param index
     *   State index
     */
    void SetErr(Idx index);

    /** 
     * Mark state as Err-state (by name)
     *
     * @param rName
     *   State name    
     */
    void SetErr(const std::string& rName);

    /**
     * Mark set of states as Err-states
     *
     * @param rStates
     *   StateSet
     */
    void SetErr(const StateSet& rStates);
    
    /** Mark state as NOT Err-state (by index)
     * 
     * @param index
     *   State index
     */
    void ClrErr(Idx index);

    /**
     * Mark state as NOT Err-state (by name)
     * 
     * @param rName
     *   State name
     */
    void ClrErr(const std::string& rName);

    /** 
     * Mark set of states as NOT Err-states (by index)
     *
     * @param rStates
     *   StateSet
     */
    void ClrErr(const StateSet& rStates);

    /** Is state Err-state (by index)
     *
     * @param index
     *   State index
     *
     * @return
     *   True / false
     */
    bool IsErr(Idx index) const;

    /**
     * Is state Err-state (by name)
     *
     * @param rName
     *   State name
     *
     * @return
     *   True / false
     */
    bool IsErr(const std::string& rName) const;

    /**
     * Get StateSet with Err-states
     *
     * @return 
     *   StateSet of Err-states
     */
    StateSet ErrStates(void) const;
    
    /**
     * Updates internal attributes. 
     * This method sets the state partition attributes.
     * 
     * @return True if value changed
     */
    virtual bool UpdateAttributes(void) {IsHioEnvironmentForm(*this); return true;};
   
  private:

  protected:
}; // end class THioEnvironment

    
// convenience typedef for std HioEnvironment
typedef THioEnvironment<AttributeVoid, HioStateFlags, HioEventFlags, AttributeVoid> HioEnvironment;

/* convenience access to relevant scopes */
#define THIS THioEnvironment<GlobalAttr, StateAttr, EventAttr, TransAttr>
#define BASE TaGenerator<GlobalAttr, StateAttr, EventAttr, TransAttr>
#define TEMP template <class GlobalAttr, class StateAttr, class EventAttr, class TransAttr>


// THioEnvironment(void)
TEMP THIS::THioEnvironment(void) : BASE() {
  FD_DG("HioEnvironment(" << this << ")::HioEnvironment()");
}

// THioEnvironment(rOtherGen)
TEMP THIS::THioEnvironment(const THioEnvironment& rOtherGen) : BASE(rOtherGen) {
  FD_DG("HioEnvironment(" << this << ")::HioEnvironment(rOtherGen)");
}

// THioEnvironment(rOtherGen)
TEMP THIS::THioEnvironment(const Generator& rOtherGen) : BASE(rOtherGen) {
  FD_DG("HioEnvironment(" << this << ")::HioEnvironment(rOtherGen)");
}

// THioEnvironment(rOtherGen,rYe,rUe,rYl,rUl)
TEMP THIS::THioEnvironment(
const Generator& rOtherGen,
   const EventSet& rYl,
   const EventSet& rUl,
   const EventSet& rYe,
   const EventSet& rUe
) : BASE(rOtherGen) {
  FD_DG("HioEnvironment(" << this << ")::HioEnvironment(rOtherGen)");
  SetYe(rYe);
  SetUe(rUe);
  SetYl(rYl);
  SetUl(rUl);
}

// THioEnvironment(rFileName)
TEMP THIS::THioEnvironment(const std::string& rFileName) : BASE(rFileName) {
  FD_DG("HioEnvironment(" << this << ")::HioEnvironment(rFilename) : done");
}

// New()
TEMP THIS* THIS::New(void) const {
  // allocate
  THIS* res = new THIS;
  // fix base data
  res->EventSymbolTablep(BASE::mpEventSymbolTable);
  res->mStateNamesEnabled=BASE::mStateNamesEnabled;
  return res;
}

// Copy()
TEMP THIS* THIS::Copy(void) const {
  return new THIS(*this);
}

// NewHioEnvironment()
TEMP THIS THIS::NewHioEnvironment(void) const {
  // call base (fixes by assignment constructor)
  THIS res= BASE::NewAGen();
  return res;
}

/******************************************************/

  // IsY(index)
  TEMP bool THIS::IsY(Idx index) const {
    EventAttr attr=BASE::EventAttribute(index);
    return attr.IsY();
  } 
	
  // IsY(rName)
  TEMP bool THIS::IsY(const std::string& rName) const {
    EventAttr attr=BASE::EventAttribute(rName);
    return attr.IsY();
  } 

  // IsU(index)
  TEMP bool THIS::IsU(Idx index) const {
    EventAttr attr=BASE::EventAttribute(index);
    return attr.IsU();
  } 
	
  // IsU(rName)
  TEMP bool THIS::IsU(const std::string& rName) const {
    EventAttr attr=BASE::EventAttribute(rName);
    return attr.IsU();
  } 

  //YEvents()
  TEMP EventSet THIS::YEvents(void) const {
    FD_DG("HioEnvironment(" << this << ")::YEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsY(*it)) res.Insert(*it);
    }
    return res;
  }
  
  //UEvents()
  TEMP EventSet THIS::UEvents(void) const {
    FD_DG("HioEnvironment(" << this << ")::UEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsU(*it)) res.Insert(*it);
    }
    return res;
  }
  
/*****************************************************************/

  // InsYeEvent(index)
  TEMP void THIS::InsYeEvent(Idx index) {
    FD_DG("HioEnvironment(" << this << ")::InsYeEvent(" << index << ")");
    EventAttr attr;
    attr.SetY();
    attr.SetE();
    BASE::InsEvent(index,attr);
  } 

  // InsYeEvent(rName)
  TEMP Idx THIS::InsYeEvent(const std::string& rName) {
    FD_DG("HioEnvironment(" << this << ")::InsYeEvent(" << rName << ")");
    EventAttr attr;
    attr.SetY();
    attr.SetE();
    return BASE::InsEvent(rName,attr);
  } 

  // InsUeEvent(index)
  TEMP void THIS::InsUeEvent(Idx index) {
    FD_DG("HioEnvironment(" << this << ")::InsUeEvent(" << index << ")");
    EventAttr attr;
    attr.SetU();
    attr.SetE();
    BASE::InsEvent(index,attr);
  } 

  // InsUeEvent(rName)
  TEMP Idx THIS::InsUeEvent(const std::string& rName) {
    FD_DG("HioEnvironment(" << this << ")::InsUeEvent(" << rName << ")");
    EventAttr attr;
    attr.SetU();
    attr.SetE();
    return BASE::InsEvent(rName,attr);
  } 
    
  // SetYe(index)
  TEMP void THIS::SetYe(Idx index) {
    FD_DG("HioEnvironment(" << this << ")::SetYe(" << index << ")");
    EventAttr attr=BASE::EventAttribute(index);
    attr.SetY();
    attr.SetE();
    BASE::pAlphabet->Attribute(index,attr);
  } 

  // SetYe(rName)
  TEMP void THIS::SetYe(const std::string& rName) {
    FD_DG("HioEnvironment(" << this << ")::SetYe(" << rName << ")");
    Idx index = BASE::EventIndex(rName);
    SetYe(index);
  }

  //SetYe(rEvents)
  TEMP void THIS::SetYe(const EventSet& rEvents) {
    FD_DG("HioEnvironment(" << this << ")::SetYe(rEvents)");
    EventSet::Iterator it;
    for(it=rEvents.Begin(); it!=rEvents.End(); it++) {
      SetYe(*it);
    }
  }
    
  // SetUe(index)
  TEMP void THIS::SetUe(Idx index) {
    FD_DG("HioEnvironment(" << this << ")::SetUe(" << index << ")");
    EventAttr attr=BASE::EventAttribute(index);
    attr.SetU();
    attr.SetE();
    BASE::pAlphabet->Attribute(index,attr);
  } 

  // SetUe(rName)
  TEMP void THIS::SetUe(const std::string& rName) {
    FD_DG("HioEnvironment(" << this << ")::SetUe(" << rName << ")");
    Idx index = BASE::EventIndex(rName);
    SetUe(index);
  }

  //SetUe(rEvents)
  TEMP void THIS::SetUe(const EventSet& rEvents) {
    FD_DG("HioEnvironment(" << this << ")::SetUe(rEvents)");
    EventSet::Iterator it;
    for(it=rEvents.Begin(); it!=rEvents.End(); it++) {
      SetUe(*it);
    }
  }

// IsYe(index)
  TEMP bool THIS::IsYe(Idx index) const {
    EventAttr attr=BASE::EventAttribute(index);
    return (attr.IsY() && attr.IsE());
  } 
	
  // IsYe(rName)
  TEMP bool THIS::IsYe(const std::string& rName) const {
    EventAttr attr=BASE::EventAttribute(rName);
    return (attr.IsY() && attr.IsE());
  } 

// IsUe(index)
  TEMP bool THIS::IsUe(Idx index) const {
    EventAttr attr=BASE::EventAttribute(index);
    return (attr.IsU() && attr.IsE());
  } 
	
  // IsUe(rName)
  TEMP bool THIS::IsUe(const std::string& rName) const {
    EventAttr attr=BASE::EventAttribute(rName);
    return (attr.IsU() && attr.IsE());
  } 
  
  //YeEvents()
  TEMP EventSet THIS::YeEvents(void) const {
    FD_DG("HioEnvironment(" << this << ")::YeEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsYe(*it)) res.Insert(*it);
    }
    return res;
  }
  
  //UeEvents()
  TEMP EventSet THIS::UeEvents(void) const {
    FD_DG("HioEnvironment(" << this << ")::UeEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsUe(*it)) res.Insert(*it);
    }
    return res;
  }

/*******************************************************************/

  // InsYlEvent(index)
  TEMP void THIS::InsYlEvent(Idx index) {
    FD_DG("HioEnvironment(" << this << ")::InsYlEvent(" << index << ")");
    EventAttr attr;
    attr.SetY();
    attr.SetL();
    BASE::InsEvent(index,attr);
  } 

  // InsYlEvent(rName)
  TEMP Idx THIS::InsYlEvent(const std::string& rName) {
    FD_DG("HioEnvironment(" << this << ")::InsYlEvent(" << rName << ")");
    EventAttr attr;
    attr.SetY();
    attr.SetL();
    return BASE::InsEvent(rName,attr);
  } 

  // InsUlEvent(index)
  TEMP void THIS::InsUlEvent(Idx index) {
    FD_DG("HioEnvironment(" << this << ")::InsUlEvent(" << index << ")");
    EventAttr attr;
    attr.SetU();
    attr.SetL();
    BASE::InsEvent(index,attr);
  } 

  // InsUlEvent(rName)
  TEMP Idx THIS::InsUlEvent(const std::string& rName) {
    FD_DG("HioEnvironment(" << this << ")::InsUlEvent(" << rName << ")");
    EventAttr attr;
    attr.SetU();
    attr.SetL();
    return BASE::InsEvent(rName,attr);
  } 
    
  // SetYl(index)
  TEMP void THIS::SetYl(Idx index) {
    FD_DG("HioEnvironment(" << this << ")::SetYl(" << index << ")");
    EventAttr attr=BASE::EventAttribute(index);
    attr.SetY();
    attr.SetL();
    BASE::pAlphabet->Attribute(index,attr);
  } 

  // SetYl(rName)
  TEMP void THIS::SetYl(const std::string& rName) {
    FD_DG("HioEnvironment(" << this << ")::SetYl(" << rName << ")");
    Idx index = BASE::EventIndex(rName);
    SetYl(index);
  }

  //SetYl(rEvents)
  TEMP void THIS::SetYl(const EventSet& rEvents) {
    FD_DG("HioEnvironment(" << this << ")::SetYl(rEvents)");
    EventSet::Iterator it;
    for(it=rEvents.Begin(); it!=rEvents.End(); it++) {
      SetYl(*it);
    }
  }
    
  // SetUl(index)
  TEMP void THIS::SetUl(Idx index) {
    FD_DG("HioEnvironment(" << this << ")::SetUl(" << index << ")");
    EventAttr attr=BASE::EventAttribute(index);
    attr.SetU();
    attr.SetL();
    BASE::pAlphabet->Attribute(index,attr);
  } 

  // SetUl(rName)
  TEMP void THIS::SetUl(const std::string& rName) {
    FD_DG("HioEnvironment(" << this << ")::SetUl(" << rName << ")");
    Idx index = BASE::EventIndex(rName);
    SetUl(index); 
  }

  //SetUl(rEvents)
  TEMP void THIS::SetUl(const EventSet& rEvents) {
    FD_DG("HioEnvironment(" << this << ")::SetUl(rEvents)");
    EventSet::Iterator it;
    for(it=rEvents.Begin(); it!=rEvents.End(); it++) {
      SetUl(*it);
    }
  }

  // IsYl(index)
  TEMP bool THIS::IsYl(Idx index) const {
    EventAttr attr=BASE::EventAttribute(index);
    return (attr.IsY() && attr.IsL());
  } 
	
  // IsYl(rName)
  TEMP bool THIS::IsYl(const std::string& rName) const {
    EventAttr attr=BASE::EventAttribute(rName);
    return (attr.IsY() && attr.IsL());
  } 

  // IsUl(index)
  TEMP bool THIS::IsUl(Idx index) const {
    EventAttr attr=BASE::EventAttribute(index);
    return (attr.IsU() && attr.IsL());
  } 
	
  // IsUl(rName)
  TEMP bool THIS::IsUl(const std::string& rName) const {
    EventAttr attr=BASE::EventAttribute(rName);
    return (attr.IsU() && attr.IsL());
  } 

  //YlEvents()
  TEMP EventSet THIS::YlEvents(void) const {
    FD_DG("HioEnvironment(" << this << ")::YlEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsYl(*it)) res.Insert(*it);
    }
    return res;
  }
  
  //UlEvents()
  TEMP EventSet THIS::UlEvents(void) const {
    FD_DG("HioEnvironment(" << this << ")::UlEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsUl(*it)) res.Insert(*it);
    }
    return res;
  }

/*****************************************************************/

  // IsE(index)
  TEMP bool THIS::IsE(Idx index) const {
    EventAttr attr=BASE::EventAttribute(index);
    return attr.IsE();
  } 
	
  // IsE(rName)
  TEMP bool THIS::IsE(const std::string& rName) const {
    EventAttr attr=BASE::EventAttribute(rName);
    return attr.IsE();
  } 

  // IsL(index)
  TEMP bool THIS::IsL(Idx index) const {
    EventAttr attr=BASE::EventAttribute(index);
    return attr.IsL();
  } 
	
  // IsL(rName)
  TEMP bool THIS::IsL(const std::string& rName) const {
    EventAttr attr=BASE::EventAttribute(rName);
    return attr.IsL();
  } 

  //EEvents()
  TEMP EventSet THIS::EEvents(void) const {
    FD_DG("HioEnvironment(" << this << ")::EEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsE(*it)) res.Insert(*it);
    }
    return res;
  }
  
  //LEvents()
  TEMP EventSet THIS::LEvents(void) const {
    FD_DG("HioEnvironment(" << this << ")::EEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsL(*it)) res.Insert(*it);
    }
    return res;
  }
  
/*******************************************************************/

/*******************************************************************
 *****************Implementation of the state attributes*************
*******************************************************************/

  // SetQYe(index)
  TEMP void THIS::SetQYe(Idx index) {
    FD_DG("HioEnvironment(" << this << ")::SetQYe(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.SetQY();
    attr.SetQE();
    attr.ClrQU();
    attr.ClrQC();
    attr.ClrQP();
    attr.ClrQL();
    attr.ClrQYcUp();
    attr.ClrQYlUe();
    BASE::pStates->Attribute(index,attr);
  } 

  // SetQYe(rName)
  TEMP void THIS::SetQYe(const std::string& rName) {
    FD_DG("HioEnvironment(" << this << ")::SetQYe(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    SetQYe(index);
  }

  //SetQYe(rStates)
  TEMP void THIS::SetQYe(const StateSet& rStates) {
    FD_DG("HioEnvironment(" << this << ")::SetQYe(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      SetQYe(*sit);
    }
  }

  // ClrQYe(index)
  TEMP void THIS::ClrQYe(Idx index) {
    FD_DG("HioEnvironment(" << this << ")::ClrQYe(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.ClrQY();
    attr.ClrQE();
    BASE::pStates->Attribute(index,attr);
  } 

  // ClrQYe(rName)
  TEMP void THIS::ClrQYe(const std::string& rName) {
    FD_DG("HioEnvironment(" << this << ")::ClrQYe(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    ClrQYe(index);
  }

  //ClrQYe(rStates)
  TEMP void THIS::ClrQYe(const StateSet& rStates) {
    FD_DG("HioEnvironment(" << this << ")::ClrQYe(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      ClrQYe(*sit);
    }
  }

  // IsQYe(index)
  TEMP bool THIS::IsQYe(Idx index) const {
    StateAttr attr=BASE::StateAttribute(index);
    return attr.IsQY() && attr.IsQE() && attr.IsQL();
  } 
	
  // IsQYe(rName)
  TEMP bool THIS::IsQYe(const std::string& rName) const {
    Idx index = BASE::StateIndex(rName);
    return IsQYe(index);
  }

  //QYeStates()
  TEMP StateSet THIS::QYeStates(void) const {
    FD_DG("HioEnvironment(" << this << ")::QYeStates()");
    StateSet res;
    StateSet::Iterator sit;
    for(sit=BASE::StatesBegin(); sit!=BASE::StatesEnd(); sit++) {
      if(IsQYe(*sit)) res.Insert(*sit);
    }
    return res;
  }
/***************************************************************************/

  // SetQUe(index)
  TEMP void THIS::SetQUe(Idx index) {
    FD_DG("HioEnvironment(" << this << ")::SetQUe(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.SetQU();
    attr.SetQE();
    attr.ClrQY();
    attr.ClrQC();
    attr.ClrQP();
    attr.ClrQL();
    attr.ClrQYcUp();
    attr.ClrQYlUe();
    BASE::pStates->Attribute(index,attr);
  } 

  // SetQUe(rName)
  TEMP void THIS::SetQUe(const std::string& rName) {
    FD_DG("HioEnvironment(" << this << ")::SetQUe(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    SetQUe(index);
  }

  //SetQUe(rStates)
  TEMP void THIS::SetQUe(const StateSet& rStates) {
    FD_DG("HioEnvironment(" << this << ")::SetQUe(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      SetQUe(*sit);
    }
  }

  // ClrQUe(index)
  TEMP void THIS::ClrQUe(Idx index) {
    FD_DG("HioEnvironment(" << this << ")::ClrQUe(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.ClrQU();
    attr.ClrQE();
    BASE::pStates->Attribute(index,attr);
  } 

  // ClrQUe(rName)
  TEMP void THIS::ClrQUe(const std::string& rName) {
    FD_DG("HioEnvironment(" << this << ")::ClrQUe(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    ClrQUe(index);
  }

  //ClrQUe(rStates)
  TEMP void THIS::ClrQUe(const StateSet& rStates) {
    FD_DG("HioEnvironment(" << this << ")::ClrQUe(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      ClrQUe(*sit);
    }
  }

  // IsQUe(index)
  TEMP bool THIS::IsQUe(Idx index) const {
    StateAttr attr=BASE::StateAttribute(index);
    return attr.IsQU() && attr.IsQE();
  } 
	
  // IsQUe(rName)
  TEMP bool THIS::IsQUe(const std::string& rName) const {
    Idx index = BASE::StateIndex(rName);
    return IsQUe(index);
  }

  //QUeStates()
  TEMP StateSet THIS::QUeStates(void) const {
    FD_DG("HioEnvironment(" << this << ")::QUeStates()");
    StateSet res;
    StateSet::Iterator sit;
    for(sit=BASE::StatesBegin(); sit!=BASE::StatesEnd(); sit++) {
      if(IsQUe(*sit)) res.Insert(*sit);
    }
    return res;
  }
/***************************************************************************/

/***************************************************************************/

  // SetQUl(index)
  TEMP void THIS::SetQUl(Idx index) {
    FD_DG("HioEnvironment(" << this << ")::SetQUl(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.SetQU();
    attr.SetQL();
    attr.ClrQY();
    attr.ClrQC();
    attr.ClrQP();
    attr.ClrQE();
    attr.ClrQYcUp();
    attr.ClrQYlUe();
    BASE::pStates->Attribute(index,attr);
  } 

  // SetQUl(rName)
  TEMP void THIS::SetQUl(const std::string& rName) {
    FD_DG("HioEnvironment(" << this << ")::SetQUl(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    SetQUl(index);
  }

  //SetQUl(rStates)
  TEMP void THIS::SetQUl(const StateSet& rStates) {
    FD_DG("HioEnvironment(" << this << ")::SetQUl(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      SetQUl(*sit);
    }
  }

  // ClrQUl(index)
  TEMP void THIS::ClrQUl(Idx index) {
    FD_DG("HioEnvironment(" << this << ")::ClrQUl(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.ClrQU();
    attr.ClrQL();
    BASE::pStates->Attribute(index,attr);
  } 

  // ClrQUl(rName)
  TEMP void THIS::ClrQUl(const std::string& rName) {
    FD_DG("HioEnvironment(" << this << ")::ClrQUl(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    ClrQUl(index);
  }

  //ClrQUl(rStates)
  TEMP void THIS::ClrQUl(const StateSet& rStates) {
    FD_DG("HioEnvironment(" << this << ")::ClrQUl(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      ClrQUl(*sit);
    }
  }

  // IsQUl(index)
  TEMP bool THIS::IsQUl(Idx index) const {
    StateAttr attr=BASE::StateAttribute(index);
    return attr.IsQU() && attr.IsQL();
  } 
	
  // IsQUl(rName)
  TEMP bool THIS::IsQUl(const std::string& rName) const {
    Idx index = BASE::StateIndex(rName);
    return IsQUl(index);
  }

  //QUlStates()
  TEMP StateSet THIS::QUlStates(void) const {
    FD_DG("HioEnvironment(" << this << ")::QUlStates()");
    StateSet res;
    StateSet::Iterator sit;
    for(sit=BASE::StatesBegin(); sit!=BASE::StatesEnd(); sit++) {
      if(IsQUl(*sit)) res.Insert(*sit);
    }
    return res;
  }

/***************************************************************************/

  // SetQYlUe(index)
  TEMP void THIS::SetQYlUe(Idx index) {
    FD_DG("HioEnvironment(" << this << ")::SetQYlUe(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.SetQYlUe();
    attr.ClrQY();
    attr.ClrQU();
    attr.ClrQC();
    attr.ClrQP();
    attr.ClrQE();
    attr.ClrQL();
    attr.ClrQYcUp();
    BASE::pStates->Attribute(index,attr);
  } 

  // SetQYlUe(rName)
  TEMP void THIS::SetQYlUe(const std::string& rName) {
    FD_DG("HioEnvironment(" << this << ")::SetQYlUe(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    SetQYlUe(index);
  }

  //SetQYlUe(rStates)
  TEMP void THIS::SetQYlUe(const StateSet& rStates) {
    FD_DG("HioEnvironment(" << this << ")::SetQYlUe(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      SetQYlUe(*sit);
    }
  }

  // ClrQYlUe(index)
  TEMP void THIS::ClrQYlUe(Idx index) {
    FD_DG("HioEnvironment(" << this << ")::ClrQYlUe(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.ClrQYlUe();
    BASE::pStates->Attribute(index,attr);
  } 

  // ClrQYlUe(rName)
  TEMP void THIS::ClrQYlUe(const std::string& rName) {
    FD_DG("HioEnvironment(" << this << ")::ClrQYlUe(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    ClrQYlUe(index);
  }

  //ClrQYlUe(rStates)
  TEMP void THIS::ClrQYlUe(const StateSet& rStates) {
    FD_DG("HioEnvironment(" << this << ")::ClrQYlUe(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      ClrQYlUe(*sit);
    }
  }

  // IsQYlUe(index)
  TEMP bool THIS::IsQYlUe(Idx index) const {
    StateAttr attr=BASE::StateAttribute(index);
    return attr.IsQYlUe();
  } 
	
  // IsQYlUe(rName)
  TEMP bool THIS::IsQYlUe(const std::string& rName) const {
    Idx index = BASE::StateIndex(rName);
    return IsQYlUe(index);
  }

  //QYlUeStates()
  TEMP StateSet THIS::QYlUeStates(void) const {
    FD_DG("HioEnvironment(" << this << ")::QYlUeStates()");
    StateSet res;
    StateSet::Iterator sit;
    for(sit=BASE::StatesBegin(); sit!=BASE::StatesEnd(); sit++) {
      if(IsQYlUe(*sit)) res.Insert(*sit);
    }
    return res;
  }

  // SetErr(index)
  TEMP void THIS::SetErr(Idx index) {
    FD_DG("HioPlant(" << this << ")::SetErr(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.SetErr();
    BASE::pStates->Attribute(index,attr);
  } 

  // SetErr(rName)
  TEMP void THIS::SetErr(const std::string& rName) {
    FD_DG("HioPlant(" << this << ")::SetErr(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    SetErr(index);
  }

  //SetErr(rStates)
  TEMP void THIS::SetErr(const StateSet& rStates) {
    FD_DG("HioPlant(" << this << ")::SetErr(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      SetErr(*sit);
    }
  }

  // ClrErr(index)
  TEMP void THIS::ClrErr(Idx index) {
    FD_DG("HioPlant(" << this << ")::ClrErr(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.ClrErr();
    BASE::pStates->Attribute(index,attr);
  } 

  // ClrErr(rName)
  TEMP void THIS::ClrErr(const std::string& rName) {
    FD_DG("HioPlant(" << this << ")::ClrErr(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    ClrErr(index);
  }

  //ClrErr(rStates)
  TEMP void THIS::ClrErr(const StateSet& rStates) {
    FD_DG("HioPlant(" << this << ")::ClrErr(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      ClrErr(*sit);
    }
  }

  // IsErr(index)
  TEMP bool THIS::IsErr(Idx index) const {
    StateAttr attr=BASE::StateAttribute(index);
    return attr.IsErr();
  } 
	
  // IsErr(rName)
  TEMP bool THIS::IsErr(const std::string& rName) const {
    Idx index = BASE::StateIndex(rName);
    return IsErr(index);
  }

  //ErrStates()
  TEMP StateSet THIS::ErrStates(void) const {
    FD_DG("HioPlant(" << this << ")::ErrStates()");
    StateSet res;
    StateSet::Iterator sit;
    for(sit=BASE::StatesBegin(); sit!=BASE::StatesEnd(); sit++) {
      if(IsErr(*sit)) res.Insert(*sit);
    }
    return res;
  }

/***************************************************************************/

#undef TEMP
#undef BASE
#undef THIS

/**
     * IsHioEnvironmentForm: check if rHioEnvironment is in I/O-environment form and assign state
     * attributes.
     * This function tests if rHioEnvironment meets the I/O-environment form that has been formally
     * defined by S.Perk. If so, then the alphabet of and the language marked by
     * rHioEnvironment formally describe an I/O environment. During the test, the HioStateFlags are
     * set according to the active event set or the respective state, for example:
     * The QYlUe flag is assigned to a state if its active eventset is a subset of the
     * union of the YL- and the UE-Alphabet.
     * The assignment of HioStateFlags is complete only if IsHioEnvironmentForm() returns true.
     * Method: all conditions in the formal I/O-environment form definition are checked
     * individually. If crucial conditions are violated, the test of remaining
     * conditions is omitted.
     *
     * @param rHioEnvironment
     *   HioEnvironment to check, HioStateFlags are set
     * @param rQYe
     *   State set containing all QYe states
     * @param rQUe
     *   State set containing all QUe states
     * @param rQUl
     *   State set containing all QUl states
     * @param rQYlUe
     *   State set containing all QYlUe states
     * @param rErrEvSet
     *   Event set for possible 'bad' events
     * @param rErrTrSet
     *   Event set for possible 'bad' transition relations
     * @param rErrStSet
     *   Event set for possible 'bad' states
     * @param rReportStr
     *   Information about test results
     * @return
     *   true if rHioEnvironment is in I/O-environment form
     */
extern FAUDES_API bool IsHioEnvironmentForm(HioEnvironment& rHioEnvironment,
                StateSet& rQYe,
                StateSet& rQUe,
                StateSet& rQUl,
                StateSet& rQYlUe,
                EventSet& rErrEvSet,
                TransSet& rErrTrSet,
                StateSet& rErrStSet,
                std::string& rReportStr);

/**
     * IsHioEnvironmentForm: check if rHioEnvironment is in I/O-environment form and assign state
     * attributes.
     * This function tests if rHioEnvironment meets the I/O-environment form that has been formally
     * defined by S.Perk. If so, then the alphabet of and the language marked by
     * rHioEnvironment formally describe an I/O environment. During the test, the HioStateFlags are
     * set according to the active event set or the respective state, for example:
     * The QYlUe flag is assigned to a state if its active eventset is a subset of the
     * union of the YL- and the UE-Alphabet.
     * The assignment of HioStateFlags is complete only if IsHioEnvironmentForm() returns true.
     * Method: all conditions in the formal I/O-environment form definition are checked
     * individually. If crucial conditions are violated, the test of remaining
     * conditions is omitted.
     *
     * @param rHioEnvironment
     *   HioEnvironment to check, HioStateFlags are set
     * @param rReportStr
     *   Information about test results
     * @return
     *   true if rHioEnvironment is in I/O-environment form
     */
extern FAUDES_API bool IsHioEnvironmentForm(HioEnvironment& rHioEnvironment,std::string& rReportStr);

/**
     * IsHioEnvironmentForm: check if rHioEnvironment is in I/O-environment form and assign state
     * attributes.
     * This function tests if rHioEnvironment meets the I/O-environment form that has been formally
     * defined by S.Perk. If so, then the alphabet of and the language marked by
     * rHioEnvironment formally describe an I/O environment. During the test, the HioStateFlags are
     * set according to the active event set or the respective state, for example:
     * The QYlUe flag is assigned to a state if its active eventset is a subset of the
     * union of the YL- and the UE-Alphabet.
     * The assignment of HioStateFlags is complete only if IsHioEnvironmentForm() returns true.
     * Method: all conditions of the formal I/O-environment form definition are checked
     * individually. If crucial conditions are violated, the test of remaining
     * conditions is omitted.
     *
     * @param rHioEnvironment
     *   HioEnvironment to check, HioStateFlags are set
     * @return
     *   true if rHioEnvironment is in I/O-environment form
     */
extern FAUDES_API bool IsHioEnvironmentForm(HioEnvironment& rHioEnvironment);

/**
 * Function definition for run-time interface 
 *
 * @param rEnvironment
 *   HioEnvironment
 */  
extern FAUDES_API void HioStatePartition(HioEnvironment& rEnvironment);

} // namespace faudes

#define HIOENVIRONMENT_H
#endif
