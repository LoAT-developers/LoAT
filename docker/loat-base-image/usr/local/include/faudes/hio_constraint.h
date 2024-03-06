/** @file hio_constraint.h Generator with I/O-constraint attributes */

/* Hierarchical IO Systems Plug-In for FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2006  Sebastian Perk 
   Copyright (C) 2006  Thomas Moor 
   Copyright (C) 2006  Klaus Schmidt

*/

#ifndef FAUDES_HIO_CONSTRAINT_H
#define FAUDES_HIO_CONSTRAINT_H

#include "corefaudes.h"
#include "hio_attributes.h"

namespace faudes {


/**
 * Generator with I/O-constraint attributes. The HioConstraint is a variant of the 
 * Generator to add an interface for events and states with I/O-constraint attributes,
 * built from HioEvent- and HioStateFlags
 * - event attributes: Y,U 
 *
 * - state attributes: QY,QU
 *
 * Technically, the construct is based on the specialized attribute classes
 * faudes::HioEventFlags and faudes::HioStateFlags that provide attributes with
 * semantics for hierarchical I/O properties. The THioConstraint expects attribute template
 * parameters with the minimum interface defined in HioEventFlags and HioStateFlags.
 * Thus, you can add further semantics by deriving a class HioEventFlagsAndMore  from
 * HioEventFlags (same for HioStateFlags) and use this as event attribute parameter for
 * THioConstraint. To model a plain finite state machine plus I/O-constraint properties, use THioConstraint
 * with HioEventFlags and HioStateFlags for the event and state attribute parameters
 * and AttributeVoid for the other parameters.
 * For convenience, this has been typedefed as HioConstraint.
 * 
 * @ingroup hiosysplugin 
 */

template <class GlobalAttr, class StateAttr, class EventAttr, class TransAttr>
class THioConstraint : public TaGenerator<GlobalAttr, StateAttr, EventAttr, TransAttr> {    
public:
    /**
     * Creates an empty HioConstraint object 
     */
    THioConstraint(void);

    /** 
     * HioConstraint from a std Generator. Copy constructor 
     *
     * @param rOtherGen
     */
   THioConstraint(const Generator& rOtherGen);

    /** 
     * HioConstraint from a std Generator and event sets. Copy constructor 
     *
     * @param rOtherGen
     *	 Generator
     * @param rY
     *	 Output alphabet
     * @param rU
     * 	 Input alphabet
     */
   THioConstraint(
   const Generator& rOtherGen,
   const EventSet& rY,
   const EventSet& rU
   );
   
    /** 
     * HioConstraint from a HioConstraint. Copy constructor 
     *
     * @param rOtherGen
     */
    THioConstraint(const THioConstraint& rOtherGen);

    /**
     * construct a HioConstraint from file
     *
     * @param rFileName
     *   Filename
     *
     * @exception Exception
     *   If opening/reading fails an Exception object is thrown (id 1, 50, 51)
     */
    THioConstraint(const std::string& rFileName);
	
    /**
     * Construct on heap
     *
     * @return 
     *   new Generator 
     */
    THioConstraint* New(void) const;

    /**
     * Construct copy on heap
     *
     * @return 
     *   new Generator 
     */
    virtual THioConstraint* Copy(void) const;

    /**
     * Create empty HioConstraint with same symboltable as this
     *
     * @return
     *   New Generator
     */
    THioConstraint NewHioConstraint(void) const;
	
    /**
     * Assignment operator (uses copy)
     *
     * @param rOtherGen
     *   Other generator
     */
     virtual THioConstraint& operator= (const THioConstraint& rOtherGen) {this->Assign(rOtherGen); return *this;};
    
    
//**************** I/O constraint event attributes ********************/

    /**
     * Add an existing Y-event to generator. 
     * An entry in the global event table will be made.
     *
     * @param index
     *   Event index
     */
    void InsYEvent(Idx index);

    /**
     * Add new named Y-event to generator. 
     * An entry in the global event table will be made if event is new.
     *
     * @param rName
     *   Name of the event to add
     *
     * @return 
     *   New global unique index
     */
    Idx InsYEvent(const std::string& rName);
    
    /**
     * Add an existing U-event to generator. 
     * An entry in the global event table will be made.
     *
     * @param index
     *   Event index
     */
    void InsUEvent(Idx index);

    /**
     * Add new named U-event to generator. 
     * An entry in the global event table will be made if event is new.
     *
     * @param rName
     *   Name of the event to add
     *
     * @return 
     *   New global unique index
     */
    Idx InsUEvent(const std::string& rName);
        
    /**
     * Mark event as Y-event (by index)
     *
     * @param index
     *   Event index
     */
    void SetY(Idx index);

    /** 
     * Mark event as Y-event(by name)
     *
     * @param rName
     *   Event name    
     */
    void SetY(const std::string& rName);

    /**
     * Mark set of events as Y-events
     *
     * @param rEvents
     *   EventSet
     */
    void SetY(const EventSet& rEvents);
        
    /**
     * Mark event U-event(by index)
     * 
     * @param index
     *   Event index
     */
    void SetU(Idx index);

    /**
     * Mark event U-event(by name)
     * 
     * @param rName
     *   Event name
     */
    void SetU(const std::string& rName);

    /**
     * Mark set of events as U-events
     *
     * @param rEvents
     *   EventSet
     */
    void SetU(const EventSet& rEvents);
          
    /**
     * Is event Y-event(by index)
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     */
    bool IsY(Idx index) const;

    /**
     * Is event Y-event(by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool IsY(const std::string& rName) const;
    
    /**
     * Is event U-event(by index)
     *
     * @param index
     *   Event index
     *
     * @return
     *   True / false
     */
    bool IsU(Idx index) const;

    /**
     * Is event U-event(by name)
     *
     * @param rName
     *   Event name
     *
     * @return
     *   True / false
     */
    bool IsU(const std::string& rName) const;

    /** 
     * Get EventSet with Y-events
     *
     * @return
     *   EventSet of Y-events
     */
    EventSet YEvents(void) const;

    /**
     * Get EventSet with U-events
     *
     * @return 
     *   EventSet of U-events
     */
    EventSet UEvents(void) const;

/*************** I/O constraint state attributes **********************/

    /**
     * Mark event as QY-state (by index)
     *
     * @param index
     *   State index
     */
    void SetQY(Idx index);

    /** 
     * Mark state as QY-state (by name)
     *
     * @param rName
     *   State name    
     */
    void SetQY(const std::string& rName);

    /**
     * Mark set of states as QY-states
     *
     * @param rStates
     *   StateSet
     */
    void SetQY(const StateSet& rStates);
    
    /** Mark state as NOT QY-state (by index)
     * 
     * @param index
     *   State index
     */
    void ClrQY(Idx index);

    /**
     * Mark state as NOT QY-state (by name)
     * 
     * @param rName
     *   State name
     */
    void ClrQY(const std::string& rName);

    /** 
     * Mark set of states as NOT QY-states (by index)
     *
     * @param rStates
     *   StateSet
     */
    void ClrQY(const StateSet& rStates);

    /** Is state QY-state (by index)
     *
     * @param index
     *   State index
     *
     * @return
     *   True / false
     */
    bool IsQY(Idx index) const;

    /**
     * Is state QY-state (by name)
     *
     * @param rName
     *   State name
     *
     * @return
     *   True / false
     */
    bool IsQY(const std::string& rName) const;

    /**
     * Get StateSet with QY-states
     *
     * @return 
     *   StateSet of QY-states
     */
    StateSet QYStates(void) const;
    
    /**
     * Mark event as QU-state (by index)
     *
     * @param index
     *   State index
     */
    void SetQU(Idx index);

    /** 
     * Mark state as QU-state (by name)
     *
     * @param rName
     *   State name    
     */
    void SetQU(const std::string& rName);

    /**
     * Mark set of states as QU-states
     *
     * @param rStates
     *   StateSet
     */
    void SetQU(const StateSet& rStates);
    
    /** Mark state as NOT QU-state (by index)
     * 
     * @param index
     *   State index
     */
    void ClrQU(Idx index);

    /**
     * Mark state as NOT QU-state (by name)
     * 
     * @param rName
     *   State name
     */
    void ClrQU(const std::string& rName);

    /** 
     * Mark set of states as NOT QU-states (by index)
     *
     * @param rStates
     *   StateSet
     */
    void ClrQU(const StateSet& rStates);

    /** Is state QU-state (by index)
     *
     * @param index
     *   State index
     *
     * @return
     *   True / false
     */
    bool IsQU(Idx index) const;

    /**
     * Is state QU-state (by name)
     *
     * @param rName
     *   State name
     *
     * @return
     *   True / false
     */
    bool IsQU(const std::string& rName) const;
    
    /**
     * Get StateSet with QU-states
     *
     * @return 
     *   StateSet of QU-states
     */
    StateSet QUStates(void) const;

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
    virtual bool UpdateAttributes(void) {IsHioConstraintForm(*this); return true;};

  private:

  protected:
  
}; // end class THioConstraint

    
// convenience typedef for std HioConstraint
typedef THioConstraint<AttributeVoid, HioStateFlags, HioEventFlags, AttributeVoid> HioConstraint;

/* convenience access to relevant scopes */
#define THIS THioConstraint<GlobalAttr, StateAttr, EventAttr, TransAttr>
#define BASE TaGenerator<GlobalAttr, StateAttr, EventAttr, TransAttr>
#define TEMP template <class GlobalAttr, class StateAttr, class EventAttr, class TransAttr>


// THioConstraint(void)
TEMP THIS::THioConstraint(void) : BASE() {
  FD_DG("HioConstraint(" << this << ")::HioConstraint()");
}

// THioConstraint(rOtherGen)
TEMP THIS::THioConstraint(const THioConstraint& rOtherGen) : BASE(rOtherGen) {
  FD_DG("HioConstraint(" << this << ")::HioConstraint(rOtherGen)");
}

// THioConstraint(rOtherGen)
TEMP THIS::THioConstraint(const Generator& rOtherGen) : BASE(rOtherGen) {
  FD_DG("HioConstraint(" << this << ")::HioConstraint(rOtherGen)");
}

// THioConstraint(rOtherGen,rY,rU)
TEMP THIS::THioConstraint(
const Generator& rOtherGen,
   const EventSet& rY,
   const EventSet& rU
) : BASE(rOtherGen) {
  FD_DG("HioConstraint(" << this << ")::HioConstraint(rOtherGen)");
  SetY(rY);
  SetU(rU);
}

// THioConstraint(rFileName)
TEMP THIS::THioConstraint(const std::string& rFileName) : BASE(rFileName) {
  FD_DG("HioConstraint(" << this << ")::HioConstraint(rFilename) : done");
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

// NewHioConstraint()
TEMP THIS THIS::NewHioConstraint(void) const {
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
    FD_DG("HioConstraint(" << this << ")::YEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsY(*it)) res.Insert(*it);
    }
    return res;
  }
  
  //UEvents()
  TEMP EventSet THIS::UEvents(void) const {
    FD_DG("HioConstraint(" << this << ")::UEvents()");
    EventSet res;
    EventSet::Iterator it;
    for(it=BASE::AlphabetBegin(); it!=BASE::AlphabetEnd(); it++) {
      if(IsU(*it)) res.Insert(*it);
    }
    return res;
  }
  
/*****************************************************************/

  // InsYEvent(index)
  TEMP void THIS::InsYEvent(Idx index) {
    FD_DG("HioConstraint(" << this << ")::InsYEvent(" << index << ")");
    EventAttr attr;
    attr.SetY();
    BASE::InsEvent(index,attr);
  } 

  // InsYEvent(rName)
  TEMP Idx THIS::InsYEvent(const std::string& rName) {
    FD_DG("HioConstraint(" << this << ")::InsYEvent(" << rName << ")");
    EventAttr attr;
    attr.SetY();
    return BASE::InsEvent(rName,attr);
  } 

  // InsUEvent(index)
  TEMP void THIS::InsUEvent(Idx index) {
    FD_DG("HioConstraint(" << this << ")::InsUEvent(" << index << ")");
    EventAttr attr;
    attr.SetU();
    BASE::InsEvent(index,attr);
  } 

  // InsUEvent(rName)
  TEMP Idx THIS::InsUEvent(const std::string& rName) {
    FD_DG("HioConstraint(" << this << ")::InsUEvent(" << rName << ")");
    EventAttr attr;
    attr.SetU();
    return BASE::InsEvent(rName,attr);
  } 
    
  // SetY(index)
  TEMP void THIS::SetY(Idx index) {
    FD_DG("HioConstraint(" << this << ")::SetY(" << index << ")");
    EventAttr attr=BASE::EventAttribute(index);
    attr.SetY();
    BASE::pAlphabet->Attribute(index,attr);
  } 

  // SetY(rName)
  TEMP void THIS::SetY(const std::string& rName) {
    FD_DG("HioConstraint(" << this << ")::SetY(" << rName << ")");
    Idx index = BASE::EventIndex(rName);
    SetY(index);
  }

  //SetY(rEvents)
  TEMP void THIS::SetY(const EventSet& rEvents) {
    FD_DG("HioConstraint(" << this << ")::SetY(rEvents)");
    EventSet::Iterator it;
    for(it=rEvents.Begin(); it!=rEvents.End(); it++) {
      SetY(*it);
    }
  }
    
  // SetU(index)
  TEMP void THIS::SetU(Idx index) {
    FD_DG("HioConstraint(" << this << ")::SetU(" << index << ")");
    EventAttr attr=BASE::EventAttribute(index);
    attr.SetU();
    BASE::pAlphabet->Attribute(index,attr);
  } 

  // SetU(rName)
  TEMP void THIS::SetU(const std::string& rName) {
    FD_DG("HioConstraint(" << this << ")::SetU(" << rName << ")");
    Idx index = BASE::EventIndex(rName);
    SetU(index);
  }

  //SetU(rEvents)
  TEMP void THIS::SetU(const EventSet& rEvents) {
    FD_DG("HioConstraint(" << this << ")::SetU(rEvents)");
    EventSet::Iterator it;
    for(it=rEvents.Begin(); it!=rEvents.End(); it++) {
      SetU(*it);
    }
  }

/*******************************************************************
 *****************Implementation of the state attributes*************
*******************************************************************/

  // SetQY(index)
  TEMP void THIS::SetQY(Idx index) {
    FD_DG("HioConstraint(" << this << ")::SetQY(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.SetQY();
    attr.ClrQU();
    attr.ClrQC();
    attr.ClrQP();
    attr.ClrQE();
    attr.ClrQL();
    attr.ClrQYcUp();
    attr.ClrQYlUe();
    BASE::pStates->Attribute(index,attr);
  } 

  // SetQY(rName)
  TEMP void THIS::SetQY(const std::string& rName) {
    FD_DG("HioConstraint(" << this << ")::SetQY(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    SetQY(index);
  }

  //SetQY(rStates)
  TEMP void THIS::SetQY(const StateSet& rStates) {
    FD_DG("HioConstraint(" << this << ")::SetQY(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      SetQY(*sit);
    }
  }

  // ClrQY(index)
  TEMP void THIS::ClrQY(Idx index) {
    FD_DG("HioConstraint(" << this << ")::ClrQY(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.ClrQY();
    BASE::pStates->Attribute(index,attr);
  } 

  // ClrQY(rName)
  TEMP void THIS::ClrQY(const std::string& rName) {
    FD_DG("HioConstraint(" << this << ")::ClrQY(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    ClrQY(index);
  }

  //ClrQY(rStates)
  TEMP void THIS::ClrQY(const StateSet& rStates) {
    FD_DG("HioConstraint(" << this << ")::ClrQY(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      ClrQY(*sit);
    }
  }

  // IsQY(index)
  TEMP bool THIS::IsQY(Idx index) const {
    StateAttr attr=BASE::StateAttribute(index);
    return attr.IsQY();
  } 
	
  // IsQY(rName)
  TEMP bool THIS::IsQY(const std::string& rName) const {
    Idx index = BASE::StateIndex(rName);
    return IsQY(index);
  }

  //QYStates()
  TEMP StateSet THIS::QYStates(void) const {
    FD_DG("HioConstraint(" << this << ")::QYStates()");
    StateSet res;
    StateSet::Iterator sit;
    for(sit=BASE::StatesBegin(); sit!=BASE::StatesEnd(); sit++) {
      if(IsQY(*sit)) res.Insert(*sit);
    }
    return res;
  }
/***************************************************************************/

  // SetQU(index)
  TEMP void THIS::SetQU(Idx index) {
    FD_DG("HioConstraint(" << this << ")::SetQU(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.SetQU();
    attr.ClrQY();
    attr.ClrQC();
    attr.ClrQP();
    attr.ClrQE();
    attr.ClrQL();
    attr.ClrQYcUp();
    attr.ClrQYlUe();
    BASE::pStates->Attribute(index,attr);
  } 

  // SetQU(rName)
  TEMP void THIS::SetQU(const std::string& rName) {
    FD_DG("HioConstraint(" << this << ")::SetQU(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    SetQU(index);
  }

  //SetQU(rStates)
  TEMP void THIS::SetQU(const StateSet& rStates) {
    FD_DG("HioConstraint(" << this << ")::SetQU(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      SetQU(*sit);
    }
  }

  // ClrQU(index)
  TEMP void THIS::ClrQU(Idx index) {
    FD_DG("HioConstraint(" << this << ")::ClrQU(" << index << ")");
    StateAttr attr=BASE::StateAttribute(index);
    attr.ClrQU();
    BASE::pStates->Attribute(index,attr);
  } 

  // ClrQU(rName)
  TEMP void THIS::ClrQU(const std::string& rName) {
    FD_DG("HioConstraint(" << this << ")::ClrQU(" << rName << ")");
    Idx index = BASE::StateIndex(rName);
    ClrQU(index);
  }

  //ClrQU(rStates)
  TEMP void THIS::ClrQU(const StateSet& rStates) {
    FD_DG("HioConstraint(" << this << ")::ClrQU(rStates)");
    StateSet::Iterator sit;
    for(sit=rStates.Begin(); sit!=rStates.End(); sit++) {
      ClrQU(*sit);
    }
  }

  // IsQU(index)
  TEMP bool THIS::IsQU(Idx index) const {
    StateAttr attr=BASE::StateAttribute(index);
    return attr.IsQU();
  } 
	
  // IsQU(rName)
  TEMP bool THIS::IsQU(const std::string& rName) const {
    Idx index = BASE::StateIndex(rName);
    return IsQU(index);
  }

  //QUStates()
  TEMP StateSet THIS::QUStates(void) const {
    FD_DG("HioConstraint(" << this << ")::QUStates()");
    StateSet res;
    StateSet::Iterator sit;
    for(sit=BASE::StatesBegin(); sit!=BASE::StatesEnd(); sit++) {
      if(IsQU(*sit)) res.Insert(*sit);
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
     * IsHioConstraintForm: check if rHioConstraint is in I/O-constraint form and assign state
     * attributes.
     * This function tests if rHioConstraint meets the I/O-constraint form that has been formally
     * defined by S.Perk. If so, then the alphabet of and the language marked by
     * rHioConstraint formally describe an I/O constraint. During the test, the HioStateFlags are
     * set according to the active event set or the respective state, for example:
     * The QY flag is assigned to a state if its active eventset is a subset of the Y-Alphabet.
     * The assignment of HioStateFlags is complete only if IsHioConstraintForm() returns true.
     * Method: all conditions in the formal I/O-constraint form definition are checked
     * individually. If crucial conditions are violated, the test of remaining
     * conditions is omitted.
     *
     * @param rHioConstraint
     *   HioConstraint to check, HioStateFlags are set
     * @param rQY
     *   State set containing all QY states
     * @param rQU
     *   State set containing all QU states
     * @param rErrEvSet
     *   Event set for possible 'bad' events
     * @param rErrTrSet
     *   Event set for possible 'bad' transition relations
     * @param rErrStSet
     *   Event set for possible 'bad' states
     * @param rReportStr
     *   Information about test results
     * @return
     *   true if rHioConstraint is in I/O-constraint form
     */

extern FAUDES_API bool IsHioConstraintForm(HioConstraint& rHioConstraint,
                StateSet& rQY,
                StateSet& rQU,
                EventSet& rErrEvSet,
                TransSet& rErrTrSet,
                StateSet& rErrStSet,
                std::string& rReportStr);

/**
     * IsHioConstraintForm: check if rHioConstraint is in I/O-constraint form and assign state
     * attributes.
     * This function tests if rHioConstraint meets the I/O-constraint form that has been formally
     * defined by S.Perk. If so, then the alphabet of and the language marked by
     * rHioConstraint formally describe an I/O constraint. During the test, the HioStateFlags are
     * set according to the active event set or the respective state, for example:
     * The QY flag is assigned to a state if its active eventset is a subset of the Y-Alphabet.
     * The assignment of HioStateFlags is complete only if IsHioConstraintForm() returns true.
     * Method: all conditions in the formal I/O-constraint form definition are checked
     * individually. If crucial conditions are violated, the test of remaining
     * conditions is omitted.
     *
     * @param rHioConstraint
     *   HioConstraint to check, HioStateFlags are set
     * @param rReportStr
     *   Information about test results
     * @return
     *   true if rHioConstraint is in I/O-constraint form
     */
extern FAUDES_API bool IsHioConstraintForm(HioConstraint& rHioConstraint,std::string& rReportStr);

/**
     * IsHioConstraintForm: check if rHioConstraint is in I/O-constraint form and assign state
     * attributes.
     * This function tests if rHioConstraint meets the I/O-constraint form that has been formally
     * defined by S.Perk. If so, then the alphabet of and the language marked by
     * rHioConstraint formally describe an I/O constraint. During the test, the HioStateFlags are
     * set according to the active event set or the respective state, for example:
     * The QY flag is assigned to a state if its active eventset is a subset of the Y-Alphabet.
     * The assignment of HioStateFlags is complete only if IsHioConstraintForm() returns true.
     * Method: all conditions of the formal I/O-constraint form definition are checked
     * individually. If crucial conditions are violated, the test of remaining
     * conditions is omitted.
     *
     * @param rHioConstraint
     *   HioConstraint to check, HioStateFlags are set
     * @return
     *   true if rHioConstraint is in I/O-constraint form
     */
extern FAUDES_API bool IsHioConstraintForm(HioConstraint& rHioConstraint);

/**
 * Function definition for run-time interface 
 *
 * @param rConstraint
 *   HioConstraint
 */  
extern FAUDES_API void HioStatePartition(HioConstraint& rConstraint);

} // namespace faudes

#endif
