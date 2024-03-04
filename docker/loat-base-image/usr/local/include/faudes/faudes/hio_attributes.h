/** @file hio_attributes.h Event and state attributes for hierarchical I/O systems */

/* Hierarchical IO Systems Plug-In for FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2006-2009  Sebastian Perk, Thomas Moor, Klaus Schmidt

*/


#ifndef FAUDES_HIO_ATTRIBUTES_H
#define FAUDES_HIO_ATTRIBUTES_H

#include "corefaudes.h"


namespace faudes {

/******************************************************************
******************* hio Event Attribute ***************************
******************************************************************/
    
/** 
 * Event attributes for hierarchical discrete event systems with inputs and outputs.
 * These Attributes are:
 *    - the input/output flag U and Y.
 *    - the flags C, P, E and L that designate membership in one
 *      or the union of more alphabets.
 *
 * @ingroup hiosysplugin  
 */

class FAUDES_API HioEventFlags : public AttributeFlags {

FAUDES_TYPE_DECLARATION(Void,HioEventFlags,AttributeFlags)

 public:
     
  /** Default constructor */
  HioEventFlags(void) : AttributeFlags() {mFlags=mDefHioEventFlags;}

  /** Copy constructor */ 
  HioEventFlags(const HioEventFlags& rSrc) : AttributeFlags() {mFlags=rSrc.mFlags;};

  /* Destructor */
  virtual ~HioEventFlags(void) {};

  /**
   * Set Y-flag 
   */
  
  void SetY(void) { mFlags |= mYFlag; };

  /**
   * Clear Y-flag 
   */

  void ClrY(void) { mFlags &= ~mYFlag; };

  /**
   * Set U-flag 
   */

  void SetU(void) { mFlags |= mUFlag; };
  
  /**
   * Clear U-flag 
   */

  void ClrU(void) { mFlags &= ~mUFlag; };
     
  /**
   * Query Y-flag 
   */

  bool IsY(void) const {return ( (mFlags & mYFlag) != 0 ); }
     
  /**
   * Query U-flag 
   */

  bool IsU(void) const {return ( (mFlags & mUFlag) != 0 ); }

  /**
   * Set P-flag 
   */

  void SetP(void) { mFlags |= mPFlag; }

  /**
   * Clear P-flag 
   */

  void ClrP(void) { mFlags &= ~mPFlag; };
     
  /**
   * Query P-flag 
   */

  bool IsP(void) const {return ( (mFlags & mPFlag) != 0 ); }
  
  /**
   * Set E-flag 
   */
  
  void SetE(void) { mFlags |= mEFlag; }

  /**
   * Clear E-flag 
   */

  void ClrE(void) { mFlags &= ~mEFlag; };
     
  /**
   * Query E-flag 
   */

  bool IsE(void) const {return ( (mFlags & mEFlag) != 0 ); }
  
  /**
   * Set C-flag 
   */
  void SetC(void) { mFlags |= mCFlag; }

  /**
   * Clear C-flag 
   */

  void ClrC(void) { mFlags &= ~mCFlag; };
     
  /**
   * Query C-flag 
   */

  bool IsC(void) const {return ( (mFlags & mCFlag) != 0 ); }
  

  /**
   * Set L-flag 
   */

  void SetL(void) { mFlags |= mLFlag; }

  /**
   * Clear L-flag 
   */

  void ClrL(void) { mFlags &= ~mLFlag; };
     
  /**
   * Query L-flag 
   */

  bool IsL(void) const {return ( (mFlags & mLFlag) != 0 ); }
   
  /** 
   * Test for default value (ie input and membership in neither P-,E-,C-, nor L-alphabet)
   */
  bool  IsDefault(void) const {return mFlags==mDefHioEventFlags;};

  // flag masks for the event properties
  
  const static fType mUFlag              =0x04;  //0000 0100
  const static fType mYFlag              =0x08;  //0000 1000
  const static fType mPFlag              =0x10;  //0001 0000
  const static fType mEFlag              =0x20;  //0010 0000
  const static fType mCFlag              =0x40;  //0100 0000
  const static fType mLFlag              =0x80;  //1000 0000
  
 private:
  // overall default value
  const static fType mDefHioEventFlags        =0x00 ; // 0000 0000

  // all flags
  const static fType mAllHioEventFlags        =0xFC;   // 1111 1100

 protected:

  /**
   * Assignment method. 
   *
   * @param rSrcAttr
   *    Source to assign from
   */
  void DoAssign(const HioEventFlags& rSrcAttr);

  /**
   * Reads attribute from TokenReader, see AttributeVoid for public wrappers.
   * Reads a single token if it can be interpreted as HioEventFlag, that is, if
   * it is a respective option string or hex number. Label and Context
   * argument are ignored. No token mismatch exceptions are thrown on error.
   *
   * @param rTr
   *   TokenReader to read from
   * @param rLabel
   *   Section to read
   * @param pContext
   *   Read context to provide contextual information
   * @exception Exception
   *   - IO error (id 1)
   */
  virtual void DoRead(TokenReader& rTr, const std::string& rLabel="", const Type* pContext=0);
 
  /**
   * Writes attribute to TokenWriter, see AttributeVoid for public wrappers.
   * Label and Context argument are ignored.  
   *
   * @param rTw
   *   TokenWriter to write to
   * @param rLabel
   *   Section to write
   * @param pContext
   *   Write context to provide contextual information
   *
   * @exception Exception
   *   - IO error (id 2)
   */
  virtual void DoWrite(TokenWriter& rTw,const std::string& rLabel="", const Type* pContext=0) const;

}; // class HioEventFlags

/******************************************************************
******************* hio State Attribute ***************************
******************************************************************/

/** 
 * State attributes for hierarchical discrete event systems with inputs and outputs.
 *    The flags are used by eg assertion functions to describe membership
 *    of the active events of a given state in a certain alphabet:
 *    - QY: only output (Y-) events are active.
 *    - QU: only input (U-) events are active.
 *    - additional flags QC,QP,QE,QL can be set/cleared to designate
 *      membership of the active events in the C-,P-,E-,L-alphabet,
 *      respectively. Membership in the union of several alphabets is
 *      possible by setting more than one of these flags.
 *    - states with active input- as well as active output-events are
 *      provided with the exclusive flags QYcUp, meaning that only
 *      events of the alphabet YC or UP are active, and QYlUe, meaning
 *      that only events of the alphabet YL or UE are active.
 *      QY,QU,QYcUp and QYlUe are exclusive by construction of  the
 *      Set() operations.
 *    - Err: with public read/write access in all hiogenerators, this
 *      flag enables to specify so-called "Error behaviour" that is
 *      typically entered after unexpected input events, for example
 *      malfunction of a HioPlant after faulty operator input. The flag can
 *      be used by the model designer; also the hio function FreeInput() uses
 *      this flag when extending a hio generator by error behaviour in order
 *      to make an input free in this generator.  Err is not bound to any formal
 *      definition  and does  not effect / can be combined with any of the remaining
 *      flags.  Hence, Err remains untouched by the functions IsIoPlant(),
 *      IsIoController(), IsIoEnvironment(), IsIoConstraint() and
 *      UpdateStateAttributes().
 *
 * @ingroup hiosysplugin 
 */

class FAUDES_API HioStateFlags : public AttributeFlags {

FAUDES_TYPE_DECLARATION(Void,HioStateFlags,AttributeFlags)

 public:
     
  /**
   * Default constructor 
   */
  HioStateFlags(void) : AttributeFlags() {mFlags=mDefHioStateFlags;}

  /** Copy constructor */ 
  HioStateFlags(const HioStateFlags& rSrc) : AttributeFlags() {mFlags=rSrc.mFlags;};

  /* Destructor */
  virtual ~HioStateFlags(void) {};

  /**
   * Write attribute to string
   *
   * @return
   *  string representation of attributes
   *
   */
  virtual std::string ToString(void) const;


  /**
   * Set QY-state flag 
   */
  
  void SetQY(void) {
      mFlags |= mQYFlag;
      mFlags &= ~mQUFlag;
      mFlags &= ~mQYcUpFlag;
      mFlags &= ~mQYlUeFlag;
      }

  /**
   * Clear QY-state flag 
   */

  void ClrQY(void) { mFlags &= ~mQYFlag; };
     
  /**
   * Query QY-state flag 
   */

  bool IsQY(void) const {return ( (mFlags & mQYFlag) != 0 ); }

  /**
   * Set QU-state flag 
   */
  
  void SetQU(void) {
      mFlags |= mQUFlag;
      mFlags &= ~mQYFlag;
      mFlags &= ~mQYcUpFlag;
      mFlags &= ~mQYlUeFlag;
      }

  /**
   * Clear QU-state flag 
   */

  void ClrQU(void) { mFlags &= ~mQUFlag; };
     
  /**
   * Query QU-state flag 
   */

  bool IsQU(void) const {return ( (mFlags & mQUFlag) != 0 ); }

  /**
   * Set QC-state flag 
   */
  
  void SetQC(void) { mFlags |= mQCFlag; }

  /**
   * Clear QC-state flag 
   */

  void ClrQC(void) { mFlags &= ~mQCFlag; };
     
  /**
   * Query QC-state flag 
   */

  bool IsQC(void) const {return ( (mFlags & mQCFlag) != 0 ); }

  /**
   * Set QP-state flag 
   */
  
  void SetQP(void) { mFlags |= mQPFlag; }

  /**
   * Clear QP-state flag 
   */

  void ClrQP(void) { mFlags &= ~mQPFlag; };
     
  /**
   * Query QP-state flag 
   */

  bool IsQP(void) const {return ( (mFlags & mQPFlag) != 0 ); }

  /**
   * Set QE-state flag 
   */
  
  void SetQE(void) { mFlags |= mQEFlag; }

  /**
   * Clear QE-state flag 
   */

  void ClrQE(void) { mFlags &= ~mQEFlag; };
     
  /**
   * Query QE-state flag 
   */

  bool IsQE(void) const {return ( (mFlags & mQEFlag) != 0 ); }
  
  /**
   * Set QL-state flag 
   */
  
  void SetQL(void) { mFlags |= mQLFlag; }

  /**
   * Clear QL-state flag 
   */

  void ClrQL(void) { mFlags &= ~mQLFlag; };
     
  /**
   * Query QL-state flag 
   */

  bool IsQL(void) const {return ( (mFlags & mQLFlag) != 0 ); }

  /**
   * Set QYcUp-state flag 
   */
  
  void SetQYcUp(void) {
      mFlags |= mQYcUpFlag;
      mFlags &= ~mQYFlag;
      mFlags &= ~mQUFlag;
      mFlags &= ~mQYlUeFlag;
      }

  /**
   * Clear QYcUp-state flag 
   */

  void ClrQYcUp(void) { mFlags &= ~mQYcUpFlag; };
     
  /**
   * Query QYcUp-state flag 
   */

  bool IsQYcUp(void) const {return ( (mFlags & mQYcUpFlag) != 0 ); }

  /**
   * Set QYlUe-state flag 
   */
  
  void SetQYlUe(void) {
      mFlags |= mQYlUeFlag;
      mFlags &= ~mQYFlag;
      mFlags &= ~mQUFlag;
      mFlags &= ~mQYcUpFlag;
      }

  /**
   * Clear QYlUe-state flag 
   */

  void ClrQYlUe(void) { mFlags &= ~mQYlUeFlag; };
     
  /**
   * Query QYlUe-state flag 
   */

  bool IsQYlUe(void) const {return ( (mFlags & mQYlUeFlag) != 0 ); }

  /**
   * Set Err-state flag 
   */
  
  void SetErr(void) { mFlags |= mErrFlag; }

  /**
   * Clear Err-state flag 
   */

  void ClrErr(void) { mFlags &= ~mErrFlag; };
     
  /**
   * Query Err-state flag 
   */

  bool IsErr(void) const {return ( (mFlags & mErrFlag) != 0 ); }
  
  /** 
   * Test for default value
   */
  bool  IsDefault(void) const {return mFlags==mDefHioStateFlags;};

  // Flag masks for the 10 properties
  
  const static fType mQYFlag     =0x01;  //0000 0000 0001
  const static fType mQUFlag     =0x02;  //0000 0000 0010
  const static fType mQCFlag     =0x04;  //0000 0000 0100
  const static fType mQPFlag     =0x08;  //0000 0000 1000
  const static fType mQEFlag     =0x10;  //0000 0001 0000
  const static fType mQLFlag     =0x20;  //0000 0010 0000
  const static fType mQYcUpFlag  =0x40;  //0000 0100 0000
  const static fType mQYlUeFlag  =0x80;  //0000 1000 0000
  const static fType mErrFlag   =0x100;  //0001 0000 0000

 private:
  // Overall default value
  const static fType mDefHioStateFlags      =0x000 ; //0000 0000

  // All flags
  const static fType mAllHioStateFlags      =0x1FF;  //1 1111 1111

 protected:

  /**
   * Assignment method. 
   *
   * @param rSrcAttr
   *    Source to assign from
   */
  void DoAssign(const HioStateFlags& rSrcAttr);

  /**
   * Reads attribute from TokenReader, see AttributeVoid for public wrappers.
   * Reads a single token if it can be interpreted as HioStateFlag, that is, if
   * it is a respective option string or hex number. Label and Context
   * argument are ignored. No token mismatch exceptions are thrown on error.
   *
   * @param rTr
   *   TokenReader to read from
   * @param rLabel
   *   Section to read
   * @param pContext
   *   Read context to provide contextual information
   *
   * @exception Exception
   *   - IO error (id 1)
   */
  virtual void DoRead(TokenReader& rTr, const std::string& rLabel="", const Type* pContext=0);
 
  /**
   * Writes attribute to TokenWriter, see AttributeVoid for public wrappers.
   * Label and Context argument are ignored.  
   *
   * @param rTw
   *   TokenWriter to write to
   * @param rLabel
   *   Section to write
   * @param pContext
   *   Write context to provide contextual information
   *
   * @exception Exception
   *   - IO error (id 2)
   */
  virtual void DoWrite(TokenWriter& rTw,const std::string& rLabel="", const Type* pContext=0) const;
}; // class HioStateFlags


} // end of namespace faudes

#endif
