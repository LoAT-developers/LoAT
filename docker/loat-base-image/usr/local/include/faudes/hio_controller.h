/** @file hio_controller.h Generator with I/O-controller attributes */

/* Hierarchical IO Systems Plug-In for FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2006  Sebastian Perk 
   Copyright (C) 2006  Thomas Moor 
   Copyright (C) 2006  Klaus Schmidt

*/

#ifndef FAUDES_HIO_CONTROLLER_H
#define FAUDES_HIO_CONTROLLER_H

#include "corefaudes.h"
#include "hio_attributes.h"

namespace faudes {


/**
 * Generator with I/O-controller attributes. The HioController is a variant of the 
 * Generator to add an interface for events and states with I/O-controller attributes,
 * built from HioEvent- and HioStateFlags
 * - event attributes: YC   = Y && C
 *                     UC   = U && C
 *                     YP   = Y && P
 *                     UP   = U && P
 * - state attributes: QYP = QY && QP
 *                     QUp  = QU && QP
 *                     QUc  = QU && QC
 *                     QYcUp
 *
 * Technically, the construct is based on the specialized attribute classes
 * faudes::HioEventFlags and faudes::HioStateFlags that provide attributes with
 * semantics for hierarchical I/O properties. The THioController expects attribute template
 * parameters with the minimum interface defined in HioEventFlags and HioStateFlags.
 * Thus, you can add further semantics by deriving a class HioEventFlagsAndMore  from
 * HioEventFlags (same for HioStateFlags) and use this as event attribute parameter for
 * THioController. To model a plain finite state machine plus I/O-controller properties, use THioController
 * with HioEventFlags and HioStateFlags for the event and state attribute parameters
 * and AttributeVoid for the other parameters.
 * For convenience, this has been typedefed as HioController.
 * 
 * @ingroup hiosysplugin 
 */

template <class GlobalAttr, class StateAttr, class EventAttr, class TransAttr>
    class THioController : public TaGenerator<GlobalAttr, StateAttr, EventAttr, TransAttr> {    
  public:
    /**
     * Creates an empty HioController object 
     */
    THioController(void);

    /** 
     * HioController from a std Generator. Copy constructor 
     *
     * @param rOtherGen
     */
   THioController(const Generator& rOtherGen);

    /** 
     * HioController from a std Generator and event sets. Copy constructor 
     *
     * @param rOtherGen
     *	 Generator
     * @param rYc
     *	 alphabet Yc
     * @param rUc
     *	 alphabet Uc
     * @param rYp
     *	 alphabet Yp
     * @param rUp
     *	 alphabet Up
     */
   THioController(
   const Generator& rOtherGen,
   const EventSet& rYc,
   const EventSet& rUc,
   const EventSet& rYp,
   const EventSet& rUp
   );
   
    /** 
     * HioController from a HioController. Copy constructor 
     *
     * @param rOtherGen
     */
    THioController(const THioController& rOtherGen);

    /**
     * construct a HioController from file
     *
     * @param rFileName
     *   Filename
     *
     * @exception Exception
     *   If opening/reading fails an Exception object is thrown (id 1, 50, 51)
     */
    THioController(const std::string& rFileName);
	
    /**
     * Construct on heap
     *
     * @return 
     *   new Generator 
     */
    THioController* New(void) const;

    /**
     * Construct copy on heap
     *
     * @return 
     *   new Generator 
     */
    virtual THioController* Copy(void) const;

    /**
     * Create empty HioController with same symboltable as this
     *
     * @return
     *   New Generator
     */
    THioController NewHioController(void) const;
	
    /**
     * Assignment operator (uses copy )
     *
     * @param rOtherGen
     *   Other generator
     */
     virtual THioController& operator= (const THioController& rOtherGen) {this->Assign(rOtherGen); return *this;};
    
//**************** I/O controller event attributes ********************/

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
     * Add an existing Yc-event to generator. 
     * An entry in the global event table will be made.
     *
     * @param index
     *   Event index
     */
    void InsYcEvent(Idx index);
   
   /**
     * Add new named Yc-event to generator. 
     * An entry in the global event table will be made if event is new.
     *
     * @param rName
     *   Name of the event to add
     *
     * @return 
     *   New global unique index
     */
    Idx InsYcEvent(const std::string& rName);
    
    /**
     * Add an existing Uc-event to generator. 
     * An entry in the global event table will be made.
     *
     * @param index
     *   Event index
     */
    void InsUcEvent(Idx index);

    /**
     * Add new named Uc-event to generator. 
     * An entry in the global event table will be made if event is new.
     *
     * @param rName
     *   Name of the event to add
     *
     * @return 
     *   New global unique index
     */
    Idx InsUcEvent(const std::string& rName);
        
    /**
     * Mark event as Yc-event (by index)
     *
     * @param index
     *   Event index
     */
    void SetYc(Idx index);

    /** 
     * Mark event as Yc-event (by name)
     *
     * @param rName
     *   Event name    
     */
    void SetYc(const std::string& rName);

    /**
     * Mark set of events as Yc-events
     *
     * @param rEvents
     *   EventSet
     */
    void SetYc(const EventSet& rEvents);
        
    /**
     * Mark event as Uc-event (by index)
     * 
     * @param index
     *   Event index
     */
    void SetUc(Idx index);

    /**
     * Mark event as Uc-event (by name)
     * 
     * @param rName
     *   Event name
     */
    void SetUc(const std::string& rName);

    /**
     * Mark set of events as Uc-events 
     *
     * @param rEvents
     *   EventSet
     */
    void SetUc(const EventSet& rEvents);
          
    /**
     * Is event Yc-event (by index)
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     */
    bool IsYc(Idx index) const;

    /**
     * Is event Yc-event (by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool IsYc(const std::string& rName) const;

    /**
     * Is event Uc-event (by index)
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     */
    bool IsUc(Idx index) const;

    /**
     * Is event Uc-event (by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool IsUc(const std::string& rName) const;

    /** 
     * Get EventSet with Yc-events
     *
     * @return
     *   EventSet of Yc-events
     */
    EventSet YcEvents(void) const;

    /**
     * Get EventSet with Uc-events
     *
     * @return 
     *   EventSet of Uc-events
     */
    EventSet UcEvents(void) const;


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
    bool IsC(Idx index) const;

    /**
     * Is event E-event? (by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool IsC(const std::string& rName) const;    

    /**
     * Get EventSet with E-events
     *
     * @return 
     *   EventSet of E-events
     */
    EventSet CEvents(void) const;
/******************************************************/


/*************** I/O controller state attributes **********************/

    /**
     * Mark state as QYP-state (by index)
     *
     * @param index
     *   State index
     */
    void SetQYp(Idx index);

    /** 
     * Mark state as QYP-state (by name)
     *
     * @param rName
     *   State name    
     */
    void SetQYp(const std::string& rName);

    /**
     * Mark set of states as QYP-states
     *
     * @param rStates
     *   StateSet
     */
    void SetQYp(const StateSet& rStates);
    
    /** Mark state as NOT QYP-state (by index)
     * 
     * @param index
     *   State index
     */
    void ClrQYP(Idx index);

    /**
     * Mark state as NOT QYP-state (by name)
     * 
     * @param rName
     *   State name
     */
    void ClrQYP(const std::string& rName);

    /** 
     * Mark set of states as NOT QYP-states (by index)
     *
     * @param rStates
     *   StateSet
     */
    void ClrQYP(const StateSet& rStates);

    /** Is state QYP-state (by index)
     *
     * @param index
     *   State index
     *
     * @return
     *   True / false
     */
    bool IsQYP(Idx index) const;

    /**
     * Is state QYP-state (by name)
     *
     * @param rName
     *   State name
     *
     * @return
     *   True / false
     */
    bool IsQYP(const std::string& rName) const;

    /**
     * Get StateSet with QYP-states
     *
     * @return 
     *   StateSet of QYP-states
     */
    StateSet QYPStates(void) const;
    
    /**
     * Mark event as QUp-state (by index)
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
     * Mark event as QUc-state (by index)
     *
     * @param index
     *   State index
     */
    void SetQUc(Idx index);

    /** 
     * Mark state as QUc-state (by name)
     *
     * @param rName
     *   State name    
     */
    void SetQUc(const std::string& rName);

    /**
     * Mark set of states as QUc-states
     *
     * @param rStates
     *   StateSet
     */
    void SetQUc(const StateSet& rStates);
    
    /** Mark state as NOT QUc-state (by index)
     * 
     * @param index
     *   State index
     */
    void ClrQUc(Idx index);

    /**
     * Mark state as NOT QUc-state (by name)
     * 
     * @param rName
     *   State name
     */
    void ClrQUc(const std::string& rName);

    /** 
     * Mark set of states as NOT QUc-states (by index)
     *
     * @param rStates
     *   StateSet
     */
    void ClrQUc(const StateSet& rStates);

    /** Is state QUc-state (by index)
     *
     * @param index
     *   State index
     *
     * @return
     *   True / false
     */
    bool IsQUc(Idx index) const;

    /**
     * Is state QUc-state (by name)
     *
     * @param rName
     *   State name
     *
     * @return
     *   True / false
     */
    bool IsQUc(const std::string& rName) const;
    
    /**
     * Get StateSet with QUc-states
     *
     * @return 
     *   StateSet of QUc-states
     */
    StateSet QUcStates(void) const;

    /**
     * Mark event as QYcUp-state (by index)
     *
     * @param index
     *   State index
     */
    void SetQYcUp(Idx index);

    /** 
     * Mark state as QYcUp-state (by name)
     *
     * @param rName
     *   State name    
     */
    void SetQYcUp(const std::string& rName);

    /**
     * Mark set of states as QYcUp-states
     *
     * @param rStates
     *   StateSet
     */
    void SetQYcUp(const StateSet& rStates);
    
    /** Mark state as NOT QYcUp-state (by index)
     * 
     * @param index
     *   State index
     */
    void ClrQYcUp(Idx index);

    /**
     * Mark state as NOT QYcUp-state (by name)
     * 
     * @param rName
     *   State name
     */
    void ClrQYcUp(const std::string& rName);

    /** 
     * Mark set of states as NOT QYcUp-states (by index)
     *
     * @param rStates
     *   StateSet
     */
    void ClrQYcUp(const StateSet& rStates);

    /** Is state QYcUp-state (by index)
     *
     * @param index
     *   State index
     *
     * @return
     *   True / false
     */
    bool IsQYcUp(Idx index) const;

    /**
     * Is state QYcUp-state (by name)
     *
     * @param rName
     *   State name
     *
     * @return
     *   True / false
     */
    bool IsQYcUp(const std::string& rName) const;
    
    /**
     * Get StateSet with QYcUp-states
     *
     * @return 
     *   StateSet of QYcUp-states
     */
    StateSet QYcUpStates(void) const;

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
    virtual bool UpdateAttributes(void) {IsHioControllerForm(*this); return true;};
    
  private:

  protected:
}; // end class THioController

    
// convenience typedef for std HioController
typedef THioController<AttributeVoid, HioStateFlags, HioEventFlags, AttributeVoid> HioController;

/* convenience access to relevant scopes */
#define THIS THioController<GlobalAttr, StateAttr, EventAttr, TransAttr>
#define BASE TaGenerator<GlobalAttr, StateAttr, EventAttr, TransAttr>
#define TEMP template <class GlobalAttr, class StateAttr, class EventAttr, class TransAttr>


// THioController(void)
TEMP THIS::THioController(void) : BASE() {
  FD_DG("HioController(" << this << ")::HioController()");
}

// THioController(rOtherGen)
TEMP THIS::THioController(const THioController& rOtherGen) : BASE(rOtherGen) {
  FD_DG("HioController(" << this << ")::HioController(rOtherGen)");
}

// THioController(rOtherGen)
TEMP THIS::THioController(const Generator& rOtherGen) : BASE(rOtherGen) {
  FD_DG("HioController(" << this << ")::HioController(rOtherGen)");
}

// THioController(rOtherGen,rYc,rUc,rYp,rUp)
TEMP THIS::THioController(
const Generator& rOtherGen,
   const EventSet& rYc,
   const EventSet& rUc,
   const EventSet& rYp,
   const EventSet& rUp
) : BASE(rOtherGen) {
  FD_DG("HioController(" << this << ")::HioController(rOtherGen)");
  SetYc(rYc);
  SetUc(rUc);
  SetYp(rYp);
  SetUp(rUp);
}

// THioController(rFileName)
TEMP THIS::THioController(const std::string& rFileName) : BASE(rFileName) {
  FD_DG("HioController(" << this << ")::HioController(rFilename) : done");
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

// NewHioController()
TEMP THIS THIS::NewHioController(void) const {
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
    FD_DG("HioController(" << this << ")::YEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsY(*it)) res.Insert(*it);
    }
    return res;
  }
  
  //UEvents()
  TEMP EventSet THIS::UEvents(void) const {
    FD_DG("HioController(" << this << ")::UEvents()");
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
    FD_DG("HioController(" << this << ")::InsYpEvent(" << index << ")");
    EventAttr attr;
    attr.SetY();
    attr.SetP();
    BASE::InsEvent(index,attr);
  } 

  // InsYpEvent(rName)
  TEMP Idx THIS::InsYpEvent(const std::string& rName) {
    FD_DG("HioController(" << this << ")::InsYpEvent(" << rName << ")");
    EventAttr attr;
    attr.SetY();
    attr.SetP();
    return BASE::InsEvent(rName,attr);
  } 

  // InsUpEvent(index)
  TEMP void THIS::InsUpEvent(Idx index) {
    FD_DG("HioController(" << this << ")::InsUpEvent(" << index << ")");
    EventAttr attr;
    attr.SetU();
    attr.SetP();
    BASE::InsEvent(index,attr);
  } 

  // InsUpEvent(rName)
  TEMP Idx THIS::InsUpEvent(const std::string& rName) {
    FD_DG("HioController(" << this << ")::InsUpEvent(" << rName << ")");
    EventAttr attr;
    attr.SetU();
    attr.SetP();
    return BASE::InsEvent(rName,attr);
  } 
    
  // SetYp(index)
  TEMP void THIS::SetYp(Idx index) {
    FD_DG("HioController(" << this << ")::SetYp(" << index << ")");
    EventAttr attr=BASE::EventAttribute(index);
    attr.SetY();
    attr.SetP();
    BASE::pAlphabet->Attribute(index,attr);
  } 

  // SetYp(rName)
  TEMP void THIS::SetYp(const std::string& rName) {
    FD_DG("HioController(" << this << ")::SetYp(" << rName << ")");
    Idx index = BASE::EventIndex(rName);
    SetYp(index);
  }

  //SetYp(rEvents)
  TEMP void THIS::SetYp(const EventSet& rEvents) {
    FD_DG("HioController(" << this << ")::SetYp(rEvents)");
    EventSet::Iterator it;
    for(it=rEvents.Begin(); it!=rEvents.End(); it++) {
      SetYp(*it);
    }
  }
    
  // SetUp(index)
  TEMP void THIS::SetUp(Idx index) {
    FD_DG("HioController(" << this << ")::SetUp(" << index << ")");
    EventAttr attr=BASE::EventAttribute(index);
    attr.SetU();
    attr.SetP();
    BASE::pAlphabet->Attribute(index,attr);
  } 

  // SetUp(rName)
  TEMP void THIS::SetUp(const std::string& rName) {
    FD_DG("HioController(" << this << ")::SetUp(" << rName << ")");
    Idx index = BASE::EventIndex(rName);
    SetUp(index);
  }

  //SetUp(rEvents)
  TEMP void THIS::SetUp(const EventSet& rEvents) {
    FD_DG("HioController(" << this << ")::SetUp(rEvents)");
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
    FD_DG("HioController(" << this << ")::YpEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsYp(*it)) res.Insert(*it);
    }
    return res;
  }
  
  //UpEvents()
  TEMP EventSet THIS::UpEvents(void) const {
    FD_DG("HioController(" << this << ")::UpEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsUp(*it)) res.Insert(*it);
    }
    return res;
  }

/*******************************************************************/

  // InsYcEvent(index)
  TEMP void THIS::InsYcEvent(Idx index) {
    FD_DG("HioController(" << this << ")::InsYcEvent(" << index << ")");
    EventAttr attr;
    attr.SetY();
    attr.SetC();
    BASE::InsEvent(index,attr);
  } 

  // InsYcEvent(rName)
  TEMP Idx THIS::InsYcEvent(const std::string& rName) {
    FD_DG("HioController(" << this << ")::InsYcEvent(" << rName << ")");
    EventAttr attr;
    attr.SetY();
    attr.SetC();
    return BASE::InsEvent(rName,attr);
  } 

  // InsUcEvent(index)
  TEMP void THIS::InsUcEvent(Idx index) {
    FD_DG("HioController(" << this << ")::InsUcEvent(" << index << ")");
    EventAttr attr;
    attr.SetU();
    attr.SetC();
    BASE::InsEvent(index,attr);
  } 

  // InsUcEvent(rName)
  TEMP Idx THIS::InsUcEvent(const std::string& rName) {
    FD_DG("HioController(" << this << ")::InsUcEvent(" << rName << ")");
    EventAttr attr;
    attr.SetU();
    attr.SetC();
    return BASE::InsEvent(rName,attr);
  } 
    
  // SetYc(index)
  TEMP void THIS::SetYc(Idx index) {
    FD_DG("HioController(" << this << ")::SetYc(" << index << ")");
    EventAttr attr=BASE::EventAttribute(index);
    attr.SetY();
    attr.SetC();
    BASE::pAlphabet->Attribute(index,attr);
  } 

  // SetYc(rName)
  TEMP void THIS::SetYc(const std::string& rName) {
    FD_DG("HioController(" << this << ")::SetYc(" << rName << ")");
    Idx index = BASE::EventIndex(rName);
    SetYc(index);
  }

  //SetYc(rEvents)
  TEMP void THIS::SetYc(const EventSet& rEvents) {
    FD_DG("HioController(" << this << ")::SetYc(rEvents)");
    EventSet::Iterator it;
    for(it=rEvents.Begin(); it!=rEvents.End(); it++) {
      SetYc(*it);
    }
  }
    
  // SetUc(index)
  TEMP void THIS::SetUc(Idx index) {
    FD_DG("HioController(" << this << ")::SetUc(" << index << ")");
    EventAttr attr=BASE::EventAttribute(index);
    attr.SetU();
    attr.SetC();
    BASE::pAlphabet->Attribute(index,attr);
  } 

  // SetUc(rName)
  TEMP void THIS::SetUc(const std::string& rName) {
    FD_DG("HioController(" << this << ")::SetUc(" << rName << ")");
    Idx index = BASE::EventIndex(rName);
    SetUc(index); 
  }

  //SetUc(rEvents)
  TEMP void THIS::SetUc(const EventSet& rEvents) {
    FD_DG("HioController(" << this << ")::SetUc(rEvents)");
    EventSet::Iterator it;
    for(it=rEvents.Begin(); it!=rEvents.End(); it++) {
      SetUc(*it);
    }
  }

  // IsYc(index)
  TEMP bool THIS::IsYc(Idx index) const {
    EventAttr attr=BASE::EventAttribute(index);
    return (attr.IsY() && attr.IsC());
  } 
	
  // IsYc(rName)
  TEMP bool THIS::IsYc(const std::string& rName) const {
    EventAttr attr=BASE::EventAttribute(rName);
    return (attr.IsY() && attr.IsC());
  } 

  // IsUc(index)
  TEMP bool THIS::IsUc(Idx index) const {
    EventAttr attr=BASE::EventAttribute(index);
    return (attr.IsU() && attr.IsC());
  } 
	
  // IsUc(rName)
  TEMP bool THIS::IsUc(const std::string& rName) const {
    EventAttr attr=BASE::EventAttribute(rName);
    return (attr.IsU() && attr.IsC());
  } 

  //YcEvents()
  TEMP EventSet THIS::YcEvents(void) const {
    FD_DG("HioController(" << this << ")::YcEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsYc(*it)) res.Insert(*it);
    }
    return res;
  }
  
  //UcEvents()
  TEMP EventSet THIS::UcEvents(void) const {
    FD_DG("HioController(" << this << ")::UcEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsUc(*it)) res.Insert(*it);
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

  // IsC(index)
  TEMP bool THIS::IsC(Idx index) const {
    EventAttr attr=BASE::EventAttribute(index);
    return attr.IsC();
  } 
	
  // IsC(rName)
  TEMP bool THIS::IsC(const std::string& rName) const {
    EventAttr attr=BASE::EventAttribute(rName);
    return attr.IsC();
  } 

  //PEvents()
  TEMP EventSet THIS::PEvents(void) const {
    FD_DG("HioController(" << this << ")::PEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsP(*it)) res.Insert(*it);
    }
    return res;
  }
  
  //CEvents()
  TEMP EventSet THIS::CEvents(void) const {
    FD_DG("HioController(" << this << ")::EEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsC(*it)) res.Insert(*it);
    }
    return res;
  }
  
/*******************************************************************/

/*******************************************************************
 *****************Implementation of the state attributes*************
*******************************************************************/

  // index)
  TEMP void THIS::SetQYp(Idx index) {
    FD_DG("HioController(" << this << ")::" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.SetQY();
    attr.SetQP();
    attr.ClrQU();
    attr.ClrQC();
    attr.ClrQE();
    attr.ClrQL();
    attr.ClrQYcUp();
    attr.ClrQYlUe();
    BASE::pStates->Attribute(index,attr);
  } 

  // rName)
  TEMP void THIS::SetQYp(const std::string& rName) {
    FD_DG("HioController(" << this << ")::" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    SetQYp(index);
  }

  //rStates)
  TEMP void THIS::SetQYp(const StateSet& rStates) {
    FD_DG("HioController(" << this << ")::rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      SetQYp(*sit);
    }
  }

  // ClrQYP(index)
  TEMP void THIS::ClrQYP(Idx index) {
    FD_DG("HioController(" << this << ")::ClrQYP(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.ClrQY();
    attr.ClrQP();
    BASE::pStates->Attribute(index,attr);
  } 

  // ClrQYP(rName)
  TEMP void THIS::ClrQYP(const std::string& rName) {
    FD_DG("HioController(" << this << ")::ClrQYP(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    ClrQYP(index);
  }

  //ClrQYP(rStates)
  TEMP void THIS::ClrQYP(const StateSet& rStates) {
    FD_DG("HioController(" << this << ")::ClrQYP(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      ClrQYP(*sit);
    }
  }

  // IsQYP(index)
  TEMP bool THIS::IsQYP(Idx index) const {
    StateAttr attr=BASE::StateAttribute(index);
    return attr.IsQY() && attr.IsQP() && attr.IsQC();
  } 
	
  // IsQYP(rName)
  TEMP bool THIS::IsQYP(const std::string& rName) const {
    Idx index = BASE::StateIndex(rName);
    return IsQYP(index);
  }

  //QYPStates()
  TEMP StateSet THIS::QYPStates(void) const {
    FD_DG("HioController(" << this << ")::QYPStates()");
    StateSet res;
    StateSet::Iterator sit;
    for(sit=BASE::StatesBegin(); sit!=BASE::StatesEnd(); sit++) {
      if(IsQYP(*sit)) res.Insert(*sit);
    }
    return res;
  }
/***************************************************************************/

  // SetQUp(index)
  TEMP void THIS::SetQUp(Idx index) {
    FD_DG("HioController(" << this << ")::SetQUp(" << index << ")");
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
    FD_DG("HioController(" << this << ")::SetQUp(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    SetQUp(index);
  }

  //SetQUp(rStates)
  TEMP void THIS::SetQUp(const StateSet& rStates) {
    FD_DG("HioController(" << this << ")::SetQUp(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      SetQUp(*sit);
    }
  }

  // ClrQUp(index)
  TEMP void THIS::ClrQUp(Idx index) {
    FD_DG("HioController(" << this << ")::ClrQUp(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.ClrQU();
    attr.ClrQP();
    BASE::pStates->Attribute(index,attr);
  } 

  // ClrQUp(rName)
  TEMP void THIS::ClrQUp(const std::string& rName) {
    FD_DG("HioController(" << this << ")::ClrQUp(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    ClrQUp(index);
  }

  //ClrQUp(rStates)
  TEMP void THIS::ClrQUp(const StateSet& rStates) {
    FD_DG("HioController(" << this << ")::ClrQUp(rStates)");
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
    FD_DG("HioController(" << this << ")::QUpStates()");
    StateSet res;
    StateSet::Iterator sit;
    for(sit=BASE::StatesBegin(); sit!=BASE::StatesEnd(); sit++) {
      if(IsQUp(*sit)) res.Insert(*sit);
    }
    return res;
  }
/***************************************************************************/

/***************************************************************************/

  // SetQUc(index)
  TEMP void THIS::SetQUc(Idx index) {
    FD_DG("HioController(" << this << ")::SetQUc(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.SetQU();
    attr.SetQC();
    attr.ClrQY();
    attr.ClrQP();
    attr.ClrQE();
    attr.ClrQL();
    attr.ClrQYcUp();
    attr.ClrQYlUe();
    BASE::pStates->Attribute(index,attr);
  } 

  // SetQUc(rName)
  TEMP void THIS::SetQUc(const std::string& rName) {
    FD_DG("HioController(" << this << ")::SetQUc(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    SetQUc(index);
  }

  //SetQUc(rStates)
  TEMP void THIS::SetQUc(const StateSet& rStates) {
    FD_DG("HioController(" << this << ")::SetQUc(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      SetQUc(*sit);
    }
  }

  // ClrQUc(index)
  TEMP void THIS::ClrQUc(Idx index) {
    FD_DG("HioController(" << this << ")::ClrQUc(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.ClrQU();
    attr.ClrQC();
    BASE::pStates->Attribute(index,attr);
  } 

  // ClrQUc(rName)
  TEMP void THIS::ClrQUc(const std::string& rName) {
    FD_DG("HioController(" << this << ")::ClrQUc(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    ClrQUc(index);
  }

  //ClrQUc(rStates)
  TEMP void THIS::ClrQUc(const StateSet& rStates) {
    FD_DG("HioController(" << this << ")::ClrQUc(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      ClrQUc(*sit);
    }
  }

  // IsQUc(index)
  TEMP bool THIS::IsQUc(Idx index) const {
    StateAttr attr=BASE::StateAttribute(index);
    return attr.IsQU() && attr.IsQC();
  } 
	
  // IsQUc(rName)
  TEMP bool THIS::IsQUc(const std::string& rName) const {
    Idx index = BASE::StateIndex(rName);
    return IsQUc(index);
  }

  //QUcStates()
  TEMP StateSet THIS::QUcStates(void) const {
    FD_DG("HioController(" << this << ")::QUcStates()");
    StateSet res;
    StateSet::Iterator sit;
    for(sit=BASE::StatesBegin(); sit!=BASE::StatesEnd(); sit++) {
      if(IsQUc(*sit)) res.Insert(*sit);
    }
    return res;
  }

/***************************************************************************/

  // SetQYcUp(index)
  TEMP void THIS::SetQYcUp(Idx index) {
    FD_DG("HioController(" << this << ")::SetQYcUp(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.SetQYcUp();
    attr.ClrQY();
    attr.ClrQU();
    attr.ClrQC();
    attr.ClrQP();
    attr.ClrQE();
    attr.ClrQL();
    attr.ClrQYlUe();
    BASE::pStates->Attribute(index,attr);
  } 

  // SetQYcUp(rName)
  TEMP void THIS::SetQYcUp(const std::string& rName) {
    FD_DG("HioController(" << this << ")::SetQYcUp(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    SetQYcUp(index);
  }

  //SetQYcUp(rStates)
  TEMP void THIS::SetQYcUp(const StateSet& rStates) {
    FD_DG("HioController(" << this << ")::SetQYcUp(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      SetQYcUp(*sit);
    }
  }

  // ClrQYcUp(index)
  TEMP void THIS::ClrQYcUp(Idx index) {
    FD_DG("HioController(" << this << ")::ClrQYcUp(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.ClrQYcUp();
    BASE::pStates->Attribute(index,attr);
  } 

  // ClrQYcUp(rName)
  TEMP void THIS::ClrQYcUp(const std::string& rName) {
    FD_DG("HioController(" << this << ")::ClrQYcUp(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    ClrQYcUp(index);
  }

  //ClrQYcUp(rStates)
  TEMP void THIS::ClrQYcUp(const StateSet& rStates) {
    FD_DG("HioController(" << this << ")::ClrQYcUp(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      ClrQYcUp(*sit);
    }
  }

  // IsQYcUp(index)
  TEMP bool THIS::IsQYcUp(Idx index) const {
    StateAttr attr=BASE::StateAttribute(index);
    return attr.IsQYcUp();
  } 
	
  // IsQYcUp(rName)
  TEMP bool THIS::IsQYcUp(const std::string& rName) const {
    Idx index = BASE::StateIndex(rName);
    return IsQYcUp(index);
  }

  //QYcUpStates()
  TEMP StateSet THIS::QYcUpStates(void) const {
    FD_DG("HioController(" << this << ")::QYcUpStates()");
    StateSet res;
    StateSet::Iterator sit;
    for(sit=BASE::StatesBegin(); sit!=BASE::StatesEnd(); sit++) {
      if(IsQYcUp(*sit)) res.Insert(*sit);
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
     * IsHioControllerForm: check if rHioController is in I/O-controller form and assign state
     * attributes.
     * This function tests if rHioController meets the I/O-controller form that has been formally
     * defined by S.Perk. If so, then the alphabet of and the language marked by
     * rHioController formally describe an I/O controller. During the test, the HioStateFlags are
     * set according to the active event set or the respective state, for example:
     * The QYcUp flag is assigned to a state if its active eventset is a subset of the
     * union of the YC- and the UP-Alphabet.
     * The assignment of HioStateFlags is complete only if IsHioControllerForm() returns true.
     * Method: all conditions in the formal I/O-controller form definition are checked
     * individually. If crucial conditions are violated, the test of remaining
     * conditions is omitted.
     *
     * @param rHioController
     *   HioController to check, HioStateFlags are set
     * @param rQUc
     *   State set containing all QUc states
     * @param rQYP
     *   State set containing all QYP states
     * @param rQUp
     *   State set containing all QUp states
     * @param rQYcUp
     *   State set containing all QYcUp states
     * @param rErrEvSet
     *   Event set for possible 'bad' events
     * @param rErrTrSet
     *   Event set for possible 'bad' transition relations
     * @param rErrStSet
     *   Event set for possible 'bad' states
     * @param rReportStr
     *   Information about test results
     * @return
     *   true if rHioController is in I/O-controller form
     */
extern FAUDES_API bool IsHioControllerForm(HioController& rHioController,
                StateSet& rQUc,
                StateSet& rQYP,
                StateSet& rQUp,
                StateSet& rQYcUp,
                EventSet& rErrEvSet,
                TransSet& rErrTrSet,
                StateSet& rErrStSet,
                std::string& rReportStr);

/**
     * IsHioControllerForm: check if rHioController is in I/O-controller form and assign state
     * attributes.
     * This function tests if rHioController meets the I/O-controller form that has been formally
     * defined by S.Perk. If so, then the alphabet of and the language marked by
     * rHioController formally describe an I/O controller. During the test, the HioStateFlags are
     * set according to the active event set or the respective state, for example:
     * The QYcUp flag is assigned to a state if its active eventset is a subset of the
     * union of the YC- and the UP-Alphabet.
     * The assignment of HioStateFlags is complete only if IsHioControllerForm() returns true.
     * Method: all conditions in the formal I/O-controller form definition are checked
     * individually. If crucial conditions are violated, the test of remaining
     * conditions is omitted.
     *
     * @param rHioController
     *   HioController to check, HioStateFlags are set
     * @param rReportStr
     *   Information about test results
     * @return
     *   true if rHioController is in I/O-controller form
     */
extern FAUDES_API bool IsHioControllerForm(HioController& rHioController,std::string& rReportStr);

/**
     * IsHioControllerForm: check if rHioController is in I/O-controller form and assign state
     * attributes.
     * This function tests if rHioController meets the I/O-controller form that has been formally
     * defined by S.Perk. If so, then the alphabet of and the language marked by
     * rHioController formally describe an I/O controller. During the test, the HioStateFlags are
     * set according to the active event set or the respective state, for example:
     * The QYcUp flag is assigned to a state if its active eventset is a subset of the
     * union of the YC- and the UP-Alphabet.
     * The assignment of HioStateFlags is complete only if IsHioControllerForm() returns true.
     * Method: all conditions of the formal I/O-controller form definition are checked
     * individually. If crucial conditions are violated, the test of remaining
     * conditions is omitted.
     *
     * @param rHioController
     *   HioController to check, HioStateFlags are set
     * @return
     *   true if rHioController is in I/O-controller form
     */
extern FAUDES_API bool IsHioControllerForm(HioController& rHioController);

/**
 * Function definition for run-time interface 
 *
 * @param rController
 *   HioController
 */  
extern FAUDES_API void HioStatePartition(HioController& rController);


} // namespace faudes

#endif

