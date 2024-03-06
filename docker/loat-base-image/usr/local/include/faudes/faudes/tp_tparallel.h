/** @file tp_tparallel.h  Parallel composition for timed automata */

/* Timeplugin for FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2007  Thomas Moor
   Exclusive copyright is granted to Klaus Schmidt

*/


// TODO: this code needs testing!
// TODO: use cparallel for contr. attribs

#ifndef FAUDES_TP_TPARALLEL_H
#define FAUDES_TP_TPARALLEL_H

#include "tp_tgenerator.h"

namespace faudes {


// convenience defs for template functions
#define TEMP template < \
  class GlobalAttr1, class StateAttr1, class EventAttr1, class TransAttr1, \
  class GlobalAttr2, class StateAttr2, class EventAttr2, class TransAttr2, \
  class GlobalAttrR, class StateAttrR, class EventAttrR, class TransAttrR >

#define TGEN1 TtGenerator<GlobalAttr1,StateAttr1,EventAttr1,TransAttr1>
#define TGEN2 TtGenerator<GlobalAttr2,StateAttr2,EventAttr2,TransAttr2>
#define TGENR TtGenerator<GlobalAttrR,StateAttrR,EventAttrR,TransAttrR>


/**
 * Parallel composition of timed generators. 
 * Arguments rGen1 and rGen2 are assumed to have disjoind clocksets.
 * This implementation considers accessible states only. 
 *
 * Technically, this function is a template, but timed attribute interfaces
 * are assumed.
 *
 * @param rGen1
 *   First generator
 * @param rGen2
 *   Second generator
 * @param rResGen
 *   Reference to resulting parallel composition generator
 *
 * @ingroup TimedPlugin
 */
TEMP void TParallel(const TGEN1& rGen1, const TGEN2& rGen2, TGENR& rResGen);


/**
 * Parallel composition of timed generators. 
 * Arguments rGen1 and rGen2 are assumed to have disjoind clocksets.
 * This implementation considers accessible states only. 
 *
 * Technically, this function is a template, but timed attribute interfaces
 * are assumed.  This version fills given reverse composition map with indices. 
 *
 * @param rGen1
 *   First generator
 * @param rGen2
 *   Second generator
 * @param rReverseCompositionMap
 *   Reverse composition map (map< pair<Idx,Idx>, Idx>)
 * @param rResGen
 *   Reference to resulting parallel composition generator
 *
 * @ingroup TimedPlugin
 * @ingroup TimedPlugin
 */
TEMP void TParallel(
    const TGEN1& rGen1, const TGEN2& rGen2,
    std::map< std::pair<Idx,Idx>, Idx>& rReverseCompositionMap, 
    TGENR& rResGen);



/*
 **************************************************************************************
 **************************************************************************************
 implementation
 **************************************************************************************
 **************************************************************************************
 */


// TParallel(rGen1, rGen2, res) (wrapper)
TEMP void TParallel(const TGEN1& rGen1, const TGEN2& rGen2, TGENR& rResGen) {
  std::map< std::pair<Idx,Idx>, Idx> rcmap;
  TParallel(rGen1, rGen2, rcmap, rResGen);
}
 

// TParallel(rGen1, rGen2, rReverseCompositionMap, res)
TEMP void TParallel(
  const TGEN1& rGen1, const TGEN2& rGen2, 
  std::map< std::pair<Idx,Idx>, Idx>& rReverseCompositionMap, 
  TGENR& rResGen)
{
  FD_DF("TParallel(" << &rGen1 << "," << &rGen2 << ")");
  // todo: exception for non-disjoint clocksets
  // call untimed parallel composition, incl virtual clear
  Parallel( rGen1, rGen2, rReverseCompositionMap, rResGen);
  // 1. union clockset
  ClockSet clocks12;
  clocks12.InsertSet(rGen1.Clocks());
  clocks12.InsertSet(rGen2.Clocks());
  FD_DF("TParallel(" << &rGen1 << "," << &rGen2 << "): clocks:" << clocks12.ToString());
  FD_DF("TParallel(" << &rGen1 << "," << &rGen2 << "): clocks:" << rGen1.Clocks().ToString());
  rResGen.InjectClocks(clocks12);
  // 2. intersect invariants
  std::map< std::pair<Idx,Idx>, Idx>::const_iterator rcit;
  for(rcit=rReverseCompositionMap.begin(); rcit!=rReverseCompositionMap.end(); rcit++) {
    Idx x1=rcit->first.first;
    Idx x2=rcit->first.second;
    Idx x12=rcit->second;
    if(!rResGen.ExistsState(x12)) continue;
    TimeConstraint invariant12;
    invariant12 << rGen1.Invariant(x1);
    invariant12 <<  rGen2.Invariant(x2);
    FD_DF("TParallel(" << &rGen1 << "," << &rGen2 << "): invariant " << x1 << "|" << x2 
       << " :" << invariant12.ToString());
    rResGen.Invariant(x12,invariant12);
  }
  // 3. set up composition map (todo: avoid this)
  std::map< Idx, std::pair<Idx,Idx> > compositionmap; 
  for(rcit=rReverseCompositionMap.begin(); rcit!=rReverseCompositionMap.end(); rcit++) 
    compositionmap[rcit->second]=rcit->first;
  // 4. resets and guards
  TransSet::Iterator tit;
  for(tit=rResGen.TransRelBegin(); tit!=rResGen.TransRelEnd(); tit++) {
    // hypothesis: unconstraint guard, no resets
    TimeConstraint guard;
    ClockSet resets;
    // if event is in Gen1, intersect with gurad of Gen1
    if(rGen1.ExistsEvent(tit->Ev)) {
       Transition t1;
       t1.X1=compositionmap[tit->X1].first;
       t1.Ev=tit->Ev;
       t1.X2=compositionmap[tit->X2].first;
       FD_DF("TParallel(" << &rGen1 << "," << &rGen2 << "): guard/resets in Gen1 for " << t1.Str());  
       guard.Insert(rGen1.Guard(t1));
       resets.InsertSet(rGen1.Resets(t1));
    }
    // if event is in Gen2, intersect with gurad of Gen2
    if(rGen2.ExistsEvent(tit->Ev)) {
       Transition t2;
       t2.X1=compositionmap[tit->X1].second;
       t2.Ev=tit->Ev;
       t2.X2=compositionmap[tit->X2].second;
       FD_DF("TParallel(" << &rGen1 << "," << &rGen2 << "): guard/resets in Gen2 for " << t2.Str());  
       guard.Insert(rGen2.Guard(t2));
       resets.InsertSet(rGen2.Resets(t2));
    }
    FD_DF("TParallel(" << &rGen1 << "," << &rGen2 << "): guard " << tit->Str()  
       << " :" << guard.ToString());
    rResGen.Guard(*tit,guard);
    FD_DF("TParallel(" << &rGen1 << "," << &rGen2 << "): resets " << tit->Str()  
       << " :" << resets.ToString());
    rResGen.Resets(*tit,resets);
  }
  FD_DF("TParallel: done ");
}




#undef TEMP
#undef GEN1
#undef GEN2
#undef GENR


} // namespace faudes

#endif 

