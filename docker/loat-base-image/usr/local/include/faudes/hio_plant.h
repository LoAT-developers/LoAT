/** @file hio_plant.h Generator with I/O-plant attributes */

/* Hierarchical IO Systems Plug-In for FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2006  Sebastian Perk 
   Copyright (C) 2006  Thomas Moor 
   Copyright (C) 2006  Klaus Schmidt

*/

#ifndef FAUDES_HIO_PLANT_H
#define FAUDES_HIO_PLANT_H

#include "corefaudes.h"
#include "hio_attributes.h"

namespace faudes {


/**
 * Generator with I/O-plant attributes. The HioPlant is a variant of the 
 * Generator to add an interface for events and states with I/O-plant attributes,
 * built from HioEvent- and HioStateFlags
 * - event attributes: YP   = Y && P
 *                     UP   = U && P
 *                     YE   = Y && E
 *                     UE   = U && E
 * - state attributes: QYpYe = QY && QP && QE
 *                               QUp  = QU && QP
 *                               QUe  = QU && QE
 *
 * Technically, the construct is based on the specialized attribute classes
 * faudes::HioEventFlags and faudes::HioStateFlags that provide attributes with
 * semantics for hierarchical I/O properties. The THioPlant expects attribute template
 * parameters with the minimum interface defined in HioEventFlags and HioStateFlags.
 * Thus, you can add further semantics by deriving a class HioEventFlagsAndMore  from
 * HioEventFlags (same for HioStateFlags) and use this as event attribute parameter for
 * THioPlant. To model a plain finite state machine plus I/O-plant properties, use THioPlant
 * with HioEventFlags and HioStateFlags for the event and state attribute parameters
 * and AttributeVoid for the other parameters.
 * For convenience, this has been typedefed as HioPlant.
 * 
 * @ingroup hiosysplugin 
 */

template <class GlobalAttr, class StateAttr, class EventAttr, class TransAttr>
class THioPlant : public TaGenerator<GlobalAttr, StateAttr, EventAttr, TransAttr> {    
  public:
    /**
     * Creates an empty HioPlant object 
     */
    THioPlant(void);

    /** 
     * HioPlant from a std Generator. Copy constructor 
     *
     * @param rOtherGen
     */
   THioPlant(const Generator& rOtherGen);
   
    /** 
     * HioPlant from a std Generator and event sets. Copy constructor 
     *
     * @param rOtherGen
     *	 Generator
     * @param rYp
     *	 alphabet Yp
     * @param rUp
     *	 alphabet Up
     * @param rYe
     *	 alphabet Ye
     * @param rUe
     *	 alphabet Ue
     */
   THioPlant(
   const Generator& rOtherGen,
   const EventSet& rYp,
   const EventSet& rUp,
   const EventSet& rYe,
   const EventSet& rUe
   );
        
    /** 
     * HioPlant from a HioPlant. Copy constructor 
     *
     * @param rOtherGen
     */
    THioPlant(const THioPlant& rOtherGen);

    /**
     * construct a HioPlant from file
     *
     * @param rFileName
     *   Filename
     *
     * @exception Exception
     *   If opening/reading fails an Exception object is thrown (id 1, 50, 51)
     */
    THioPlant(const std::string& rFileName);

    /**
     * Construct on heap
     *
     * @return 
     *   new Generator 
     */
    virtual THioPlant* New(void) const;

    /**
     * Construct copy on heap
     *
     * @return 
     *   new Generator 
     */
    virtual THioPlant* Copy(void) const;

    /**
     * Create empty HioPlant with same symboltable as this
     *
     * @return
     *   New Generator
     */
    THioPlant NewHioPlant(void) const;

    /**
     * Assignment operator (uses copy )
     *
     * @param rOtherGen
     *   Other generator
     */
     virtual THioPlant& operator= (const THioPlant& rOtherGen) {this->Assign(rOtherGen); return *this;};
    
//**************** I/O plant event attributes ********************/

    /**
     * Add an existing Yp-event to generator. 
     * An entry in the global event table will be made.
     *
     * @param index
     *   Event index
     */
    void InsYpEvent(Idx index);

    /**
     * Add new named Yp-event to generator. 
     * An entry in the global event table will be made if event is new.
     *
     * @param rName
     *   Name of the event to add
     *
     * @return 
     *   New global unique index
     */
    Idx InsYpEvent(const std::string& rName);
    
    /**
     * Add an existing Up-event to generator. 
     * An entry in the global event table will be made.
     *
     * @param index
     *   Event index
     */
    void InsUpEvent(Idx index);

    /**
     * Add new named Up-event to generator. 
     * An entry in the global event table will be made if event is new.
     *
     * @param rName
     *   Name of the event to add
     *
     * @return 
     *   New global unique index
     */
    Idx InsUpEvent(const std::string& rName);
        
    /**
     * Mark event as Yp-event (by index)
     *
     * @param index
     *   Event index
     */
    void SetYp(Idx index);

    /** 
     * Mark event as Yp-event(by name)
     *
     * @param rName
     *   Event name    
     */
    void SetYp(const std::string& rName);

    /**
     * Mark set of events as Yp-events
     *
     * @param rEvents
     *   EventSet
     */
    void SetYp(const EventSet& rEvents);
        
    /**
     * Mark event Up-event(by index)
     * 
     * @param index
     *   Event index
     */
    void SetUp(Idx index);

    /**
     * Mark event Up-event(by name)
     * 
     * @param rName
     *   Event name
     */
    void SetUp(const std::string& rName);

    /**
     * Mark set of events as Up-events
     *
     * @param rEvents
     *   EventSet
     */
    void SetUp(const EventSet& rEvents);
          
    /**
     * Is event Yp-event(by index)
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     */
    bool IsYp(Idx index) const;

    /**
     * Is event Yp-event(by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool IsYp(const std::string& rName) const;
    
    /**
     * Is event Up-event(by index)
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     */
    bool IsUp(Idx index) const;

    /**
     * Is event Up-event(by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool IsUp(const std::string& rName) const;

    /** 
     * Get EventSet with Yp-events
     *
     * @return
     *   EventSet of Yp-events
     */
    EventSet YpEvents(void) const;

    /**
     * Get EventSet with Up-events
     *
     * @return 
     *   EventSet of Up-events
     */
    EventSet UpEvents(void) const;

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
     * Mark event as Ye-event (by name)
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
     * Mark event as Ue-event (by index)
     * 
     * @param index
     *   Event index
     */
    void SetUe(Idx index);

    /**
     * Mark event as Ue-event (by name)
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
     * Is event Ye-event (by index)
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     */
    bool IsYe(Idx index) const;

    /**
     * Is event Ye-event (by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool IsYe(const std::string& rName) const;

    /**
     * Is event Ue-event (by index)
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     */
    bool IsUe(Idx index) const;

    /**
     * Is event Ue-event (by name)
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
    bool IsP(Idx index) const;

    /**
     * Is event P-event? (by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool IsP(const std::string& rName) const;

    /** 
     * Get EventSet with P-events
     *
     * @return
     *   EventSet of P-events
     */
    EventSet PEvents(void) const;
    
    /**
     * Is event E-event? (by index)
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     */
    bool IsE(Idx index) const;

    /**
     * Is event E-event? (by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool IsE(const std::string& rName) const;    

    /**
     * Get EventSet with E-events
     *
     * @return 
     *   EventSet of E-events
     */
    EventSet EEvents(void) const;
/******************************************************/


/*************** I/O plant state attributes **********************/

    /**
     * Mark state as QYpYe-state (by index)
     *
     * @param index
     *   State index
     */
    void SetQYpYe(Idx index);

    /** 
     * Mark state as QYpYe-state (by name)
     *
     * @param rName
     *   State name    
     */
    void SetQYpYe(const std::string& rName);

    /**
     * Mark set of states as QYpYe-states
     *
     * @param rStates
     *   StateSet
     */
    void SetQYpYe(const StateSet& rStates);
    
    /** Mark state as NOT QYpYe-state (by index)
     * 
     * @param index
     *   State index
     */
    void ClrQYpYe(Idx index);

    /**
     * Mark state as NOT QYpYe-state (by name)
     * 
     * @param rName
     *   State name
     */
    void ClrQYpYe(const std::string& rName);

    /** 
     * Mark set of states as NOT QYpYe-states (by index)
     *
     * @param rStates
     *   StateSet
     */
    void ClrQYpYe(const StateSet& rStates);

    /** Is state QYpYe-state (by index)
     *
     * @param index
     *   State index
     *
     * @return
     *   True / false
     */
    bool IsQYpYe(Idx index) const;

    /**
     * Is state QYpYe-state (by name)
     *
     * @param rName
     *   State name
     *
     * @return
     *   True / false
     */
    bool IsQYpYe(const std::string& rName) const;

    /**
     * Get StateSet with QYpYe-states
     *
     * @return 
     *   StateSet of QYpYe-states
     */
    StateSet QYpYeStates(void) const;
    
    /**
     * Mark state as QUp-state (by index)
     *
     * @param index
     *   State index
     */
    void SetQUp(Idx index);

    /** 
     * Mark state as QUp-state (by name)
     *
     * @param rName
     *   State name    
     */
    void SetQUp(const std::string& rName);

    /**
     * Mark set of states as QUp-states
     *
     * @param rStates
     *   StateSet
     */
    void SetQUp(const StateSet& rStates);
    
    /** Mark state as NOT QUp-state (by index)
     * 
     * @param index
     *   State index
     */
    void ClrQUp(Idx index);

    /**
     * Mark state as NOT QUp-state (by name)
     * 
     * @param rName
     *   State name
     */
    void ClrQUp(const std::string& rName);

    /** 
     * Mark set of states as NOT QUp-states (by index)
     *
     * @param rStates
     *   StateSet
     */
    void ClrQUp(const StateSet& rStates);

    /** Is state QUp-state (by index)
     *
     * @param index
     *   State index
     *
     * @return
     *   True / false
     */
    bool IsQUp(Idx index) const;

    /**
     * Is state QUp-state (by name)
     *
     * @param rName
     *   State name
     *
     * @return
     *   True / false
     */
    bool IsQUp(const std::string& rName) const;
    
    /**
     * Get StateSet with QUp-states
     *
     * @return 
     *   StateSet of QUp-states
     */
    StateSet QUpStates(void) const;

    /**
     * Mark state as QUe-state (by index)
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
    virtual bool UpdateAttributes(void) {IsHioPlantForm(*this); return true;};

  private:

  protected:
}; // end class THioPlant

    
// convenience typedef for std HioPlant
typedef THioPlant<AttributeVoid, HioStateFlags, HioEventFlags, AttributeVoid> HioPlant;

/* convenience access to relevant scopes */
#define THIS THioPlant<GlobalAttr, StateAttr, EventAttr, TransAttr>
#define BASE TaGenerator<GlobalAttr, StateAttr, EventAttr, TransAttr>
#define TEMP template <class GlobalAttr, class StateAttr, class EventAttr, class TransAttr>


// THioPlant(void)
TEMP THIS::THioPlant(void) : BASE() {
  FD_DG("HioPlant(" << this << ")::HioPlant()");
}

// THioPlant(rOtherGen)
TEMP THIS::THioPlant(const THioPlant& rOtherGen) : BASE(rOtherGen) {
  FD_DG("HioPlant(" << this << ")::HioPlant(rOtherGen)");
}

// THioPlant(rOtherGen)
TEMP THIS::THioPlant(const Generator& rOtherGen) : BASE(rOtherGen) {
  FD_DG("HioPlant(" << this << ")::HioPlant(rOtherGen)");
}

// THioPlant(rOtherGen,rYp,rUp,rYe,rUe)
TEMP THIS::THioPlant(
const Generator& rOtherGen,
   const EventSet& rYp,
   const EventSet& rUp,
   const EventSet& rYe,
   const EventSet& rUe
) : BASE(rOtherGen) {
  FD_DG("HioPlant(" << this << ")::HioPlant(rOtherGen)");
  SetYp(rYp);
  SetUp(rUp);
  SetYe(rYe);
  SetUe(rUe);
}

// THioPlant(rFileName)
TEMP THIS::THioPlant(const std::string& rFileName) : BASE(rFileName) {
  FD_DG("HioPlant(" << this << ")::HioPlant(rFilename) : done");
}

// New()
TEMP THIS* THIS::New(void) const {
  // allocate
  THIS* res = new THIS();
  // fix base data
  res->EventSymbolTablep(BASE::mpEventSymbolTable);
  res->mStateNamesEnabled=BASE::mStateNamesEnabled;
  return res;
}

// Copy()
TEMP THIS* THIS::Copy(void) const {
  return new THIS(*this);
}

// NewHioPlant()
TEMP THIS THIS::NewHioPlant(void) const {
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
    FD_DG("HioPlant(" << this << ")::YEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsY(*it)) res.Insert(*it);
    }
    return res;
  }
  
  //UEvents()
  TEMP EventSet THIS::UEvents(void) const {
    FD_DG("HioPlant(" << this << ")::UEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsU(*it)) res.Insert(*it);
    }
    return res;
  }
  
/*****************************************************************/

  // InsYpEvent(index)
  TEMP void THIS::InsYpEvent(Idx index) {
    FD_DG("HioPlant(" << this << ")::InsYpEvent(" << index << ")");
    EventAttr attr;
    attr.SetY();
    attr.SetP();
    BASE::InsEvent(index,attr);
  } 

  // InsYpEvent(rName)
  TEMP Idx THIS::InsYpEvent(const std::string& rName) {
    FD_DG("HioPlant(" << this << ")::InsYpEvent(" << rName << ")");
    EventAttr attr;
    attr.SetY();
    attr.SetP();
    return BASE::InsEvent(rName,attr);
  } 

  // InsUpEvent(index)
  TEMP void THIS::InsUpEvent(Idx index) {
    FD_DG("HioPlant(" << this << ")::InsUpEvent(" << index << ")");
    EventAttr attr;
    attr.SetU();
    attr.SetP();
    BASE::InsEvent(index,attr);
  } 

  // InsUpEvent(rName)
  TEMP Idx THIS::InsUpEvent(const std::string& rName) {
    FD_DG("HioPlant(" << this << ")::InsUpEvent(" << rName << ")");
    EventAttr attr;
    attr.SetU();
    attr.SetP();
    return BASE::InsEvent(rName,attr);
  } 
    
  // SetYp(index)
  TEMP void THIS::SetYp(Idx index) {
    FD_DG("HioPlant(" << this << ")::SetYp(" << index << ")");
    EventAttr attr=BASE::EventAttribute(index);
    attr.SetY();
    attr.SetP();
    BASE::pAlphabet->Attribute(index,attr);
  } 

  // SetYp(rName)
  TEMP void THIS::SetYp(const std::string& rName) {
    FD_DG("HioPlant(" << this << ")::SetYp(" << rName << ")");
    Idx index = BASE::EventIndex(rName);
    SetYp(index);
  }

  //SetYp(rEvents)
  TEMP void THIS::SetYp(const EventSet& rEvents) {
    FD_DG("HioPlant(" << this << ")::SetYp(rEvents)");
    EventSet::Iterator it;
    for(it=rEvents.Begin(); it!=rEvents.End(); it++) {
      SetYp(*it);
    }
  }
    
  // SetUp(index)
  TEMP void THIS::SetUp(Idx index) {
    FD_DG("HioPlant(" << this << ")::SetUp(" << index << ")");
    EventAttr attr=BASE::EventAttribute(index);
    attr.SetU();
    attr.SetP();
    BASE::pAlphabet->Attribute(index,attr);
  } 

  // SetUp(rName)
  TEMP void THIS::SetUp(const std::string& rName) {
    FD_DG("HioPlant(" << this << ")::SetUp(" << rName << ")");
    Idx index = BASE::EventIndex(rName);
    SetUp(index);
  }

  //SetUp(rEvents)
  TEMP void THIS::SetUp(const EventSet& rEvents) {
    FD_DG("HioPlant(" << this << ")::SetUp(rEvents)");
    EventSet::Iterator it;
    for(it=rEvents.Begin(); it!=rEvents.End(); it++) {
      SetUp(*it);
    }
  }

// IsYp(index)
  TEMP bool THIS::IsYp(Idx index) const {
    EventAttr attr=BASE::EventAttribute(index);
    return (attr.IsY() && attr.IsP());
  } 
	
  // IsYp(rName)
  TEMP bool THIS::IsYp(const std::string& rName) const {
    EventAttr attr=BASE::EventAttribute(rName);
    return (attr.IsY() && attr.IsP());
  } 

// IsUp(index)
  TEMP bool THIS::IsUp(Idx index) const {
    EventAttr attr=BASE::EventAttribute(index);
    return (attr.IsU() && attr.IsP());
  } 
	
  // IsUp(rName)
  TEMP bool THIS::IsUp(const std::string& rName) const {
    EventAttr attr=BASE::EventAttribute(rName);
    return (attr.IsU() && attr.IsP());
  } 
  
  //YpEvents()
  TEMP EventSet THIS::YpEvents(void) const {
    FD_DG("HioPlant(" << this << ")::YpEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsYp(*it)) res.Insert(*it);
    }
    return res;
  }
  
  //UpEvents()
  TEMP EventSet THIS::UpEvents(void) const {
    FD_DG("HioPlant(" << this << ")::UpEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsUp(*it)) res.Insert(*it);
    }
    return res;
  }

/*******************************************************************/

  // InsYeEvent(index)
  TEMP void THIS::InsYeEvent(Idx index) {
    FD_DG("HioPlant(" << this << ")::InsYeEvent(" << index << ")");
    EventAttr attr;
    attr.SetY();
    attr.SetE();
    BASE::InsEvent(index,attr);
  } 

  // InsYeEvent(rName)
  TEMP Idx THIS::InsYeEvent(const std::string& rName) {
    FD_DG("HioPlant(" << this << ")::InsYeEvent(" << rName << ")");
    EventAttr attr;
    attr.SetY();
    attr.SetE();
    return BASE::InsEvent(rName,attr);
  } 

  // InsUeEvent(index)
  TEMP void THIS::InsUeEvent(Idx index) {
    FD_DG("HioPlant(" << this << ")::InsUeEvent(" << index << ")");
    EventAttr attr;
    attr.SetU();
    attr.SetE();
    BASE::InsEvent(index,attr);
  } 

  // InsUeEvent(rName)
  TEMP Idx THIS::InsUeEvent(const std::string& rName) {
    FD_DG("HioPlant(" << this << ")::InsUeEvent(" << rName << ")");
    EventAttr attr;
    attr.SetU();
    attr.SetE();
    return BASE::InsEvent(rName,attr);
  } 
    
  // SetYe(index)
  TEMP void THIS::SetYe(Idx index) {
    FD_DG("HioPlant(" << this << ")::SetYe(" << index << ")");
    EventAttr attr=BASE::EventAttribute(index);
    attr.SetY();
    attr.SetE();
    BASE::pAlphabet->Attribute(index,attr);
  } 

  // SetYe(rName)
  TEMP void THIS::SetYe(const std::string& rName) {
    FD_DG("HioPlant(" << this << ")::SetYe(" << rName << ")");
    Idx index = BASE::EventIndex(rName);
    SetYe(index);
  }

  //SetYe(rEvents)
  TEMP void THIS::SetYe(const EventSet& rEvents) {
    FD_DG("HioPlant(" << this << ")::SetYe(rEvents)");
    EventSet::Iterator it;
    for(it=rEvents.Begin(); it!=rEvents.End(); it++) {
      SetYe(*it);
    }
  }
    
  // SetUe(index)
  TEMP void THIS::SetUe(Idx index) {
    FD_DG("HioPlant(" << this << ")::SetUe(" << index << ")");
    EventAttr attr=BASE::EventAttribute(index);
    attr.SetU();
    attr.SetE();
    BASE::pAlphabet->Attribute(index,attr);
  } 

  // SetUe(rName)
  TEMP void THIS::SetUe(const std::string& rName) {
    FD_DG("HioPlant(" << this << ")::SetUe(" << rName << ")");
    Idx index = BASE::EventIndex(rName);
    SetUe(index); 
  }

  //SetUe(rEvents)
  TEMP void THIS::SetUe(const EventSet& rEvents) {
    FD_DG("HioPlant(" << this << ")::SetUe(rEvents)");
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
    FD_DG("HioPlant(" << this << ")::YeEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsYe(*it)) res.Insert(*it);
    }
    return res;
  }
  
  //UeEvents()
  TEMP EventSet THIS::UeEvents(void) const {
    FD_DG("HioPlant(" << this << ")::UeEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsUe(*it)) res.Insert(*it);
    }
    return res;
  }

/*****************************************************************/

  // IsP(index)
  TEMP bool THIS::IsP(Idx index) const {
    EventAttr attr=BASE::EventAttribute(index);
    return attr.IsP();
  } 
	
  // IsP(rName)
  TEMP bool THIS::IsP(const std::string& rName) const {
    EventAttr attr=BASE::EventAttribute(rName);
    return attr.IsP();
  } 

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

  //PEvents()
  TEMP EventSet THIS::PEvents(void) const {
    FD_DG("HioPlant(" << this << ")::PEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsP(*it)) res.Insert(*it);
    }
    return res;
  }
  
  //EEvents()
  TEMP EventSet THIS::EEvents(void) const {
    FD_DG("HioPlant(" << this << ")::EEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsE(*it)) res.Insert(*it);
    }
    return res;
  }
  
/*******************************************************************/

/*******************************************************************
 *****************Implementation of the state attributes*************
*******************************************************************/

  // SetQYpYe(index)
  TEMP void THIS::SetQYpYe(Idx index) {
    FD_DG("HioPlant(" << this << ")::SetQYpYe(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.SetQY();
    attr.SetQP();
    attr.SetQE();
    attr.ClrQU();
    attr.ClrQC();
    attr.ClrQL();
    attr.ClrQYcUp();
    attr.ClrQYlUe();
    BASE::pStates->Attribute(index,attr);
  } 

  // SetQYpYe(rName)
  TEMP void THIS::SetQYpYe(const std::string& rName) {
    FD_DG("HioPlant(" << this << ")::SetQYpYe(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    SetQYpYe(index);
  }

  //SetQYpYe(rStates)
  TEMP void THIS::SetQYpYe(const StateSet& rStates) {
    FD_DG("HioPlant(" << this << ")::SetQYpYe(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      SetQYpYe(*sit);
    }
  }

  // ClrQYpYe(index)
  TEMP void THIS::ClrQYpYe(Idx index) {
    FD_DG("HioPlant(" << this << ")::ClrQYpYe(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.ClrQY();
    attr.ClrQP();
    attr.ClrQE();
    BASE::pStates->Attribute(index,attr);
  } 

  // ClrQYpYe(rName)
  TEMP void THIS::ClrQYpYe(const std::string& rName) {
    FD_DG("HioPlant(" << this << ")::ClrQYpYe(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    ClrQYpYe(index);
  }

  //ClrQYpYe(rStates)
  TEMP void THIS::ClrQYpYe(const StateSet& rStates) {
    FD_DG("HioPlant(" << this << ")::ClrQYpYe(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      ClrQYpYe(*sit);
    }
  }

  // IsQYpYe(index)
  TEMP bool THIS::IsQYpYe(Idx index) const {
    StateAttr attr=BASE::StateAttribute(index);
    return attr.IsQY() && attr.IsQP() && attr.IsQE();
  } 
	
  // IsQYpYe(rName)
  TEMP bool THIS::IsQYpYe(const std::string& rName) const {
    Idx index = BASE::StateIndex(rName);
    return IsQYpYe(index);
  }

  //QYpYeStates()
  TEMP StateSet THIS::QYpYeStates(void) const {
    FD_DG("HioPlant(" << this << ")::QYpYeStates()");
    StateSet res;
    StateSet::Iterator sit;
    for(sit=BASE::StatesBegin(); sit!=BASE::StatesEnd(); sit++) {
      if(IsQYpYe(*sit)) res.Insert(*sit);
    }
    return res;
  }
/***************************************************************************/

  // SetQUp(index)
  TEMP void THIS::SetQUp(Idx index) {
    FD_DG("HioPlant(" << this << ")::SetQUp(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.SetQU();
    attr.SetQP();
    attr.ClrQY();
    attr.ClrQC();
    attr.ClrQE();
    attr.ClrQL();
    attr.ClrQYcUp();
    attr.ClrQYlUe();
    BASE::pStates->Attribute(index,attr);
  } 

  // SetQUp(rName)
  TEMP void THIS::SetQUp(const std::string& rName) {
    FD_DG("HioPlant(" << this << ")::SetQUp(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    SetQUp(index);
  }

  //SetQUp(rStates)
  TEMP void THIS::SetQUp(const StateSet& rStates) {
    FD_DG("HioPlant(" << this << ")::SetQUp(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      SetQUp(*sit);
    }
  }

  // ClrQUp(index)
  TEMP void THIS::ClrQUp(Idx index) {
    FD_DG("HioPlant(" << this << ")::ClrQUp(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.ClrQU();
    attr.ClrQP();
    BASE::pStates->Attribute(index,attr);
  } 

  // ClrQUp(rName)
  TEMP void THIS::ClrQUp(const std::string& rName) {
    FD_DG("HioPlant(" << this << ")::ClrQUp(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    ClrQUp(index);
  }

  //ClrQUp(rStates)
  TEMP void THIS::ClrQUp(const StateSet& rStates) {
    FD_DG("HioPlant(" << this << ")::ClrQUp(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      ClrQUp(*sit);
    }
  }

  // IsQUp(index)
  TEMP bool THIS::IsQUp(Idx index) const {
    StateAttr attr=BASE::StateAttribute(index);
    return attr.IsQU() && attr.IsQP();
  } 
	
  // IsQUp(rName)
  TEMP bool THIS::IsQUp(const std::string& rName) const {
    Idx index = BASE::StateIndex(rName);
    return IsQUp(index);
  }

  //QUpStates()
  TEMP StateSet THIS::QUpStates(void) const {
    FD_DG("HioPlant(" << this << ")::QUpStates()");
    StateSet res;
    StateSet::Iterator sit;
    for(sit=BASE::StatesBegin(); sit!=BASE::StatesEnd(); sit++) {
      if(IsQUp(*sit)) res.Insert(*sit);
    }
    return res;
  }
/***************************************************************************/

/***************************************************************************/

  // SetQUe(index)
  TEMP void THIS::SetQUe(Idx index) {
    FD_DG("HioPlant(" << this << ")::SetQUe(" << index << ")");
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
    FD_DG("HioPlant(" << this << ")::SetQUe(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    SetQUe(index);
  }

  //SetQUe(rStates)
  TEMP void THIS::SetQUe(const StateSet& rStates) {
    FD_DG("HioPlant(" << this << ")::SetQUe(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      SetQUe(*sit);
    }
  }

  // ClrQUe(index)
  TEMP void THIS::ClrQUe(Idx index) {
    FD_DG("HioPlant(" << this << ")::ClrQUe(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.ClrQU();
    attr.ClrQE();
    BASE::pStates->Attribute(index,attr);
  } 

  // ClrQUe(rName)
  TEMP void THIS::ClrQUe(const std::string& rName) {
    FD_DG("HioPlant(" << this << ")::ClrQUe(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    ClrQUe(index);
  }

  //ClrQUe(rStates)
  TEMP void THIS::ClrQUe(const StateSet& rStates) {
    FD_DG("HioPlant(" << this << ")::ClrQUe(rStates)");
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
    FD_DG("HioPlant(" << this << ")::QUeStates()");
    StateSet res;
    StateSet::Iterator sit;
    for(sit=BASE::StatesBegin(); sit!=BASE::StatesEnd(); sit++) {
      if(IsQUe(*sit)) res.Insert(*sit);
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
     * IsHioPlantForm: check if rHioPlant is in I/O-plant form and assign state
     * attributes.
     * This function tests if rHioPlant meets the I/O-plant form that has been formally
     * defined by S.Perk. If so, then the alphabet of and the language marked by
     * rHioPlant formally describe an I/O plant. During the test, the HioStateFlags are
     * set according to the active event set or the respective state, for example:
     * The QYpYe flag is assigned to a state if its active even set is a subset of the
     * union of the YP- and the YE-Alphabet.
     * The assignment of HioStateFlags is complete only if IsHioPlantForm() returns true.
     * Method: all conditions in the formal I/O-plant form definition are checked
     * individually. If crucial conditions are violated, the test of remaining
     * conditions is omitted.
     *
     * @param rHioPlant
     *   HioPlant to check, HioStateFlags are set
     * @param rQYpYe
     *   State set containing all QYpYe states
     * @param rQUp
     *   State set containing all QUp states
     * @param rQUe
     *   State set containing all QUe states
     * @param rErrEvSet
     *   Event set for possible 'bad' events
     * @param rErrTrSet
     *   Event set for possible 'bad' transition relations
     * @param rErrStSet
     *   Event set for possible 'bad' states
     * @param rReportStr
     *   Information about test results
     * @return
     *   true if rHioPlant is in I/O-plant form
     */
extern FAUDES_API bool IsHioPlantForm(HioPlant& rHioPlant,
                StateSet& rQYpYe,
                StateSet& rQUp,
                StateSet& rQUe,
                EventSet& rErrEvSet,
                TransSet& rErrTrSet,
                StateSet& rErrStSet,
                std::string& rReportStr);

/**
     * IsHioPlantForm: check if rHioPlant is in I/O-plant form and assign state
     * attributes.
     * This function tests if rHioPlant meets the I/O-plant form that has been formally
     * defined by S.Perk. If so, then the alphabet of and the language marked by
     * rHioPlant formally describe an I/O plant. During the test, the HioStateFlags are
     * set according to the active event set or the respective state, for example:
     * The QYpYe flag is assigned to a state if its active even set is a subset of the
     * union of the YP- and the YE-Alphabet.
     * The assignment of HioStateFlags is complete only if IsHioPlantForm() returns true.
     * Method: all conditions in the formal I/O-plant form definition are checked
     * individually. If crucial conditions are violated, the test of remaining
     * conditions is omitted.
     *
     * @param rHioPlant
     *   HioPlant to check, HioStateFlags are set
     * @param rReportStr
     *   Information about test results
     * @return
     *   true if rHioPlant is in I/O-plant form
     */
extern FAUDES_API bool IsHioPlantForm(HioPlant& rHioPlant,std::string& rReportStr);

/**
     * IsHioPlantForm: check if rHioPlant is in I/O-plant form and assign state
     * attributes.
     * This function tests if rHioPlant meets the I/O-plant form that has been formally
     * defined by S.Perk. If so, then the alphabet of and the language marked by
     * rHioPlant formally describe an I/O plant. During the test, the HioStateFlags are
     * set according to the active event set or the respective state, for example:
     * The QYpYe flag is assigned to a state if its active eventset is a subset of the
     * union of the YP- and the YE-Alphabet.
     * The assignment of HioStateFlags is complete only if IsHioPlantForm() returns true.
     * Method: all conditions of the formal I/O-plant form definition are checked
     * individually. If crucial conditions are violated, the test of remaining
     * conditions is omitted.
     *
     * @param rHioPlant
     *   HioPlant to check, HioStateFlags are set
     * @return
     *   true if rHioPlant is in I/O-plant form
     */
extern FAUDES_API bool IsHioPlantForm(HioPlant& rHioPlant);


/**
 * Function definition for run-time interface 
 */
extern FAUDES_API bool IsHioPlantForm(HioPlant& rHioPlant, std::string& rReportStr);

/**
 * Function definition for run-time interface 
 */
extern FAUDES_API bool IsHioPlantForm(HioPlant& rHioPlant);

/**
 * Function definition for run-time interface 
 */
extern FAUDES_API bool IsHioPlantForm(HioPlant& rHioPlant,
       StateSet& rQYpYe,
       StateSet& rQUp,
       StateSet& rQUe,
       EventSet& rErrEvSet,
       TransSet& rErrTrSet,
       StateSet& rErrStSet,
       std::string& rReportStr);


/**
 * Function definition for run-time interface 
 *
 * @param rPlant
 *   HioPlant
 */  
extern FAUDES_API void HioStatePartition(HioPlant& rPlant);





} // namespace faudes

#endif
