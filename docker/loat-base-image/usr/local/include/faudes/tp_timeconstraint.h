/** @file tp_timeconstraint.h  Classes ClockSet, ElemConstraint and TimeConstraint */



/* Timeplugin for FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2006  B Schlein
   Copyright (C) 2007  Thomas Moor
   Exclusive copyright is granted to Klaus Schmidt

*/

#ifndef FAUDES_TP_TIMECONSTRAINT_H
#define FAUDES_TP_TIMECONSTRAINT_H

#include "corefaudes.h"
#include "tp_timeinterval.h"
#include <list>


namespace faudes {



/**
 * Container class to model a set of clocks. 
 * Technically, this is a NameSet with a static SymbolTable to map
 * symbolic clock names to clock indices. Thus, clock names are
 * global similar to event names. Note that clocksets of individual
 * TtGenerators are assumed to be disjoint. 
 *
 * Todo: explicitely inherit other constructors (!)
 *
 * @ingroup TimedPlugin 
 *
 */

class FAUDES_API ClockSet : public NameSet {

FAUDES_TYPE_DECLARATION(ClockSet,ClockSet,NameSet)

  public:

  /**
   * Constructor 
   */
  ClockSet(void);

  /**
   * Copy-constructor.
   *
   * @param rOtherSet
   *   Set to copy
   */
  ClockSet(const ClockSet& rOtherSet);

    /**
     * Construct from file.
     * Uses the NameSet's Read() function to scan a file for a 
     * specified clockset.
     *
     * @param rFilename
     *   File to read
     * @param rLabel
     *   Section label for the clocks in the file; default value "Clocks"
     */
   ClockSet(const std::string& rFilename, const std::string& rLabel = "Clocks");
 
    /**
     * Get pointer to static clock SymbolTable
     * (init on first use pattern)
     * @return
     *   Pointer to static clock SymbolTable
     */
    static SymbolTable* GlobalClockSymbolTablep(void);

  protected:

  /**
   * Assign from other clock set.
   *
   * @param rSourceSet
   *   Destination to copy from
   * @return
   *   ref to this set
   */
  virtual void DoAssign(const ClockSet& rSourceSet);

  /**
   * Test equality with other clock set.
   *
   * @param rOtherSet
   *   Set to compare with
   * @return
   *   True/false
   */
  virtual bool DoEqual(const ClockSet& rOtherSet) const;

}; // end class ClockSet



/**
 * Model of an elementary clock constraint formula.  The constraint consists of an index
 * of a clock, a comperative operator and a constant time value.
 * Semantically, an elementary contraint is satisfied at a time t if at that time
 * the clock value compares true with the constant time.
 * The clock index 0 is used to indicate an invalid contraint. It is only the 
 * context of the more general TimeContraint that provides
 * a reference to a clock SymbolTable.   
 * 
 * @param mClock
 *    Clock index
 *
 * @param mCompOperator
 *    Symbolic integer value for comperative operator
 *
 * @param mTimeConstant
 *    Time constant for comparison
 *
 * @ingroup TimedPlugin 
 *
 */

class FAUDES_API ElemConstraint {

  public:

    /**
     *  Typedef for comparison operators in elementary clock constraints
     * 
     */
    typedef enum {GreaterEqual, GreaterThan, LessThan, LessEqual} Operator;

    /**
     *  Conversion from symbolic operator to string
     */
    static std::string OperatorName(Operator op);

    /**
     * Construct an (invalid) elementary clock constraint (clockindex 0)
     * 
     */
    ElemConstraint(void);

    /**
     * Construct an elementary clock constraint from values 
     *
     * @param clockindex
     *    Clock by index.
     * @param op
     *    Symbolic value for operator
     * @param timeconst
     *    Value for time constant
     */
    ElemConstraint(Idx clockindex, Operator op, Time::Type timeconst);

    /**
     * Set all values
     *
     * @param clockindex
     *    Clock by index.
     * @param op
     *    Symbolic value for operator
     * @param timeconst
     *    Value for time constant
     */
    void Set(Idx clockindex, Operator op, Time::Type timeconst);

    /**
     * Set clock by index
     */
    Idx Clock(Idx newClock);

    /**
     * Get clock by index
     *
     * @return clock index
     */
    Idx Clock(void) const;

    /**
     * Set operator.
     *
     * @param newOp
     *    Symbolic value of new operator
     */
    void CompOperator(Operator newOp);

    /**
     * Get operator
     * @return Operator
     */
    Operator CompOperator(void) const;

    /**
     * Set time constant.
     *
     * @param newTimeConst
     *    Value of new time constant
     */
    void TimeConstant(Time::Type newTimeConst);

    /**
     * Get time constant
     * @return Time constant
     */
    Time::Type TimeConstant(void) const;

    /**
     * Writes ElemConstraint to std::string
     *
     * @return std::string
     */
    std::string Str(void) const;

    /**
     * Test for equality.
     *
     * @param otherElemConstraint
     *    Other elementary constraint
     * @return 
     *  True if mClockIndex, mTimeConstant and mCompOperator are equal. Else false.
     */
    bool operator== (const ElemConstraint & otherElemConstraint) const;

    /**
     * Test for equality.
     *
     * @param otherElemConstraint
     *    Other elementary constraint
     * @return 
     *  True if not equal; see operator==.
     */
    bool operator!= (const ElemConstraint & otherElemConstraint) const;

    /**
     * Less operator for ordering in container classes
     *
     * @param otherElemConstraint
     *   Other ElemConstraint
     *
     * @return True  when clock index of left constraint is less
     *   than the one of right constraint. Else false.
     */
    bool operator < (const ElemConstraint& otherElemConstraint) const;


  protected:

    /** Index of clock. */
    Idx mClockIndex;

    /** Comparative operator */
    Operator mCompOperator;

    /** Time constant to compare with clock value */
    Time::Type mTimeConstant;

}; // ElemConstraint



/**
 * A TimeConstraint is a set of elementary clock constraints. Semantically,
 * the elementary constraints are combibed by conjunction, ie the TimeConstraint is
 * satisfied if all ElemConstraint s are satisfied. This implementation also maintains
 * the clock symboltable to may cloc indices to symbolic names.
 *
 * @param ClockConstraints
 *    Set of elementary clock constraints
 *
 *  @ingroup TimedPlugin 
 */

class FAUDES_API TimeConstraint {

  public:

    /** Iterator to access ElemConstraints */
    typedef std::set<ElemConstraint>::const_iterator Iterator;

    /** Reverse iterator to access ElemConstraints */
    typedef std::set<ElemConstraint>::const_reverse_iterator RIterator;

    /** Convenience typedef for operators */
    typedef ElemConstraint::Operator Operator;

    /**
     * Construct an empty TimeConstraint (allways satisfied)
     */
    TimeConstraint(void);

    /**
     * Copy constructor
     *
     * @param rOtherTimeConstraint
     *    Time constraint to copy
     */
    TimeConstraint(const TimeConstraint& rOtherTimeConstraint);

    /**
     * Constructor from file.
     *
     * Uses Read() to scan a file for specified label to read the constraint. 
     *
     * @param rFilename
     *   File to read
     * @param rLabel
     *   Section label for the set in the file. 
     */
    TimeConstraint(const std::string& rFilename, const std::string& rLabel = "TimeConstraint");

    /**
     * Destructor
     */
    ~TimeConstraint(void);


    /**
     * Get Pointer to mpClockSymbolTable.
     *
     * @return
     *   Pointer to mpClockSymbolTable
     */
    SymbolTable* ClockSymbolTablep(void) const;


    /**
     * Set Pointer to mpClockSymbolTable.
     *
     */
    void ClockSymbolTablep(SymbolTable* pSymTab);

    /**
     * Write to console
     */
    void Write(void) const;

    /**
     * Write to file with label (default: "TimeConstraint") and 
     * openmode (default: truncate file).
     *
     * @param rFileName
     *   Filename
     * @param rLabel
     *   Label for set in file
     * @param openmode
     *   std::ios::openmode
     *
     * @exception Exception
     *   If opening/writing fails an Exception object is thrown (id 2)
     */
    void Write(const std::string& rFileName, const std::string& rLabel = "TimeConstraint",
	       std::ios::openmode openmode = std::ios::out|std::ios::trunc) const;


    /**
     * Write to TokenWriter. The name of the constraint is used
     * as the label in the file.
     *
     * @param tw
     *   Reference to TokenWriter
     *
     * @exception std::ios::failure     
     *   Thrown on i/o error.
     */
    void Write(TokenWriter& tw) const;
        
    /**
     * Write to TokenWriter with a given label
     *
     * @param tw
     *   Reference to TokenWriter
     * @param rLabel
     *   Label for set in file
     *
     * @exception std::ios::failure
     *   Thrown on i/o error.
     */
    void Write(TokenWriter& tw, const std::string& rLabel) const;
        
    /**
     * Write to a std::string
     *
     * @return
     *   String containing all elements
     */
    std::string ToString(void) const;

    /**
     * Write NameSet to console, debug version
     */
    void DWrite(void) const;

    /** Write to TokenWriter, debug version
     *
     * @param tw
     *   Reference to TokenWriter
     *
     * @exception std::ios::failure
     *   Thrown on i/o error.
     */
    void DWrite(TokenWriter& tw) const;

    /**
     * Read from file. Reads specified label by creating a tokenreader and
     * calling read(tr)
     *
     * @param rFileName
     *   Filename
     * @param rLabel
     *   token label to read from file
     *
     * @exception Exception
     *   If opening/reading fails an Exception object is thrown (id 1, 50, 51, 56)
     */
    void Read(const std::string& rFileName, const std::string& rLabel = "TimeConstraint");
    
    
    /**
     * Read from tokenreader. Clears before. It is an error
     * if the file contains an index
     *
     * @param tr
     *   Reference to tokenreader
     * @param rLabel
     *   Label to read
     *
     * @exception std::ios::failure
     *   Thrown on i/o error.
     */
    void Read(TokenReader& tr, const std::string& rLabel = "TimeConstraint");


    /** 
     * Return name of Constraint 
     * 
     * @return
     *   Name 
     */
    std::string Name(void) const { return mName;};
        
    /**
     * Set name of Constraint
     *
     * @param rName
     *   BaseSet name
     */
    void Name(const std::string& rName) { mName=rName; };


    /**
     * Checks if TimeConstraint containts no ElemConstraints
     * 
     * @return
     *     True if TimeConstraint is empty. Else false.
     */
    bool Empty(void) const;

    /**
     * Returns number of ElemConstraint s.
     *
     * @return Number of ElemConstraint s.
     */
    Idx Size(void) const;

    /**
     * Adds an elementary clock constraint to the time constraint.
     *
     * @param rElemConstr
     *    Elementary clock constraint that is to be added to time constraint
     * @return
     *   iterator to new constraint
     */
    Iterator Insert(const ElemConstraint& rElemConstr);

    /**
     * Adds an elementary clock constraint to the time constraint.
     *
     * @param clockname
     *    Clock for new ElemConstraint
     * @param op
     *    Operator for new ElemConstraint
     * @param timeconst
     *    Time constant for new ElemConstraint
     * @return
     *   iterator to new constraint
     */
    Iterator Insert(const std::string clockname, Operator op, const Time::Type timeconst);

    /**
     * Adds an elementary clock constraint to the time constraint.
     *
     * @param clockindex
     *    Clock for new ElemConstraint
     * @param op
     *    Operator for new ElemConstraint
     * @param timeconst
     *    Time constant for new ElemConstraint
     * @return
     *   iterator to new constraint
     */
    Iterator Insert(Idx clockindex, Operator op, const Time::Type timeconst);

    /**
     * Adds a list of elementary clock constraints to the time constraint.
     *
     * @param rNewConstraints
     *    Set of elementary clock constraints that is to be added to time constraint.
     */
    void Insert(const std::list<ElemConstraint>& rNewConstraints);

    /**
     * Adds elementary clock constraints from other TimeConstant to the time constraint.
     *
     * @param rOtherTimeConstraint
     *    Time constraint whos clock constraints are to be added to time constraint.
     */
    void Insert(const TimeConstraint& rOtherTimeConstraint);

    /**
     * Convenience operator to combine a TimeConstraint with another TimeConstraint.
     *
     * @param rOtherTimeConstraint
     *   other TimeConstraint
     *
     * @return TimeConstraint object containing all ElemConstraints of both TimeConstraints.
     */
    TimeConstraint& operator << (const TimeConstraint& rOtherTimeConstraint) {
      this->Insert(rOtherTimeConstraint); return *this; };

    /**
     * Convenience operator to combines a TimeConstraint with an elementary TimeConstraint.
     *
     * @param rElemConstr
     *   extra elemtary constraint
     *
     * @return TimeConstraint object containing all ElemConstraints of both TimeConstraints.
     */
    TimeConstraint& operator << (const ElemConstraint& rElemConstr) {
      this->Insert(rElemConstr); return *this; };

    /**
     * Returns copy of ClockConstraints
     */
    std::set<ElemConstraint> ClockConstraints(void) const;

    /**
     * Advertise clock to ClockSymbolTable and retrive index
     *
     * @param rClockName
     *   symbolic name of clock
     *
     * @return
     *   index of clock
     */
    Idx InsClock(const std::string& rClockName) const;

    /**
     * Lookup clock name 
     *
     * @param clockindex
     *   index of clock
     *
     * @return
     *   name of clock
     */
    std::string ClockName(Idx clockindex) const;

    /**
     * Lookup clock index 
     *
     * @param rClockName
     *   Symbolic name of clock
     *
     * @return
     *   Index of clock
     */
    Idx ClockIndex(const std::string& rClockName) const;

    /**
     * Pretty printable string of elem. constraint
     *
     * @param rElemConstr
     *   ref to elem constraint
     *
     * @return
     *   output string
     */
    std::string EStr(const ElemConstraint& rElemConstr) const;

    /**
     * Removes all elementary clock constraints refering to a specified clock.
     *
     * @param clock 
     *   Clock whos constraints are to be removed.
     * @return
     *   True, if constraints(s) have been erased
     */
    bool EraseByClock(Idx clock);

    /**
     * Calls std::set::erase(iterator). ElemConstraint refered by it is removed from constraint.
     *
     * @param it
     *    TimeConstraint::Iterator pointing to ElemConstraint that is removed.
     *
     * @return 
     *   Iterator pointing to next ElemConstraint.
     */
    Iterator Erase(Iterator it);

    /**
     * Removes elementary clock constraint.
     *
     * @param rElemConstr
     *   Constraint to be removed.
     * @return
     *   True, if constraint has been removed
     */
    bool Erase(const ElemConstraint& rElemConstr);

    /**
     * Removes elementary clock constraint.
     *
     * @param rClockName
     *    Clock 
     * @param op
     *    Operator 
     * @param timeconst
     *    Time constant 
     * @return
     *   True, if constraint has been removed
     */
    bool Erase(const std::string& rClockName, Operator op, const Time::Type timeconst);

    /**
     * Removes elementary clock constraint.
     *
     * @param clockindex
     *    Clock 
     * @param op
     *    Operator 
     * @param timeconst
     *    Time constant 
     * @return
     *   True, if constraint has been removed
     */
    bool Erase(Idx clockindex, Operator op, const Time::Type timeconst);

    /**
     * Clear all
     */
    void Clear(void);


    /**
     * Checks if elementary clock constraint is contained in constraint
     *
     * @param rElemConstr
     *    elementary constraint
     */
    bool Exists(const ElemConstraint& rElemConstr) const;

    /** 
     * Iterator to begin of set 
     *
     * @return
     *   TimeConstraint::Iterator
     */
    Iterator Begin(void) const;
    
    /** 
     * Iterator to end of set
     *
     * @return
     *   TimeConstraint::Iterator
     */
    Iterator End(void) const;  
    
    /**
     * Reverse iterator that yields the ElemConstraints in reverse order starting at
     * the last element and ending after the first. See set<...>::rbegin(void).
     * Returns the "End". 
     *
     * @return
     *   TimeConstraint::RIterator
     */
    RIterator RBegin(void) const;
    
    /**
     * Reverse iterator that yields the ElemConstraints in reverse order starting at
     * the last element and ending after the first. See set<...>::rend(void).
     * Returns the "Begin".
     *
     * @return
     *   TimeConstraint::RIterator
     */
    RIterator REnd(void) const;

    /** 
     * Iterator to first constraint with specified clock 
     *
     * @return
     *   TimeConstraint::iterator
     */
    Iterator Begin(Idx clock) const;
    
    /** 
     * Iterator to first constraint just behind specified clock 
     *
     * @return
     *   TimeConstraint::Iterator
     */
    Iterator End(Idx clock) const;

    /**
     * Returns a Clockset containing all clocks used 
     * by the TimeConstraint.
     *
     * @return Clockset containing all clocks used by the TimeConstraint.
     */
    ClockSet ActiveClocks(void) const;

    /**
     * Given a clock, compute the timeinterval in which
     * the constraint is satisfied
     *
     * @return TimeInterval
     */
    TimeInterval Interval(Idx clockindex) const;

    /**
     * Given a clock, compute the timeinterval in which
     * the constraint is satisfied
     *
     * @return TimeInterval
     */
    TimeInterval Interval(const std::string& clockname) const;

    /**
     * Given a clock and an interval, set up the constraint such 
     * that it is valid in the given interval.  
     *
     * @param clockindex
     *    specifies the clock
     * @param rInterval
     *    reference to time interval
     */
    void Interval(Idx clockindex, const TimeInterval& rInterval);


    /**
     * Given a clock and an interval, set up the constraint such 
     * that it is valid in the given interval.  
     *
     * @param rClockName
     *    specifies the clock
     * @param rInterval
     *    reference to time interval
     */
    void Interval(const std::string& rClockName, const TimeInterval& rInterval);

    /**
     * Minimize by eliminating redundant elementary constraints. The current implemantation
     * retrieves the time constraints as intervals per clock and then converts back to 
     * a time constraint.
     */
    void Minimize(void);


    /**
     * Test for equality.
     * The implementation converts both constraints to intervals and then
     * performs the comparison.
     *
     * @param rOther
     *    Constraint to compare with.
     * @return 
     *  True if constraints are semantically identical.
     */
    bool operator== (const TimeConstraint& rOther) const;

    /**
     * Test for equality.
     *
     * @param rOther
     *    Constraint to compare with.
     * @return 
     *  True if not equal; see operator==.
     */
    bool operator!= (const TimeConstraint & rOther) const;

  protected:

    /** My name */
    std::string mName;

    /** Set of elementary clock constraints */
    std::set<ElemConstraint> mClockConstraints;

    /** SymbolTable for clock names */
    SymbolTable* mpClockSymbolTable;

    /** nonconst iterator to access ElemConstraints */
    typedef std::set<ElemConstraint>::iterator iterator;

}; //TimeConstraint


} // namespace faudes


#endif 

