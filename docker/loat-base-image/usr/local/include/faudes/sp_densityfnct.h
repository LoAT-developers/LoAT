/** @file sp_densityfnct.h  Discrete density function approximation */

/*
   Copyright (C) 2008  Thomas Moor
   Exclusive copyright is granted to Klaus Schmidt
*/


#ifndef FAUDES_SP_DENSITYFNCT_H
#define FAUDES_SP_DENSITYFNCT_H

#include "corefaudes.h"
#include "tp_include.h"


namespace faudes {

/**

Density Function

A DiscreteDensityFnction models a piecewise constant
map with non-negative support. It consists of a
sorted vector (aka map) of disjoint time intervals
with one associated value each.

The current implementation is rather incomplete,
inefficient, and buggy. The ToDo list  includes
- we assume consecutive right open intervals, so either
  assert the restriction or implement more general
- we assume an integer time type, so either assert the restriction
  or implement more general
- fix token io 
- need proper access methods
- implement method to evaluate random variable with given density
- generalise to class DensityFunction to include some continuous functions 
  eg exponential, gauss
- have this a proper faudes type


*/
class FAUDES_API DiscreteDensityFunction {
     
 public:

  // construct destruct
  DiscreteDensityFunction(void);
  virtual ~DiscreteDensityFunction(void) {};

  // clear all
  virtual void Clear(void);

  // get values  
  double Value(Time::Type time) const;
  const TimeInterval& TimeInt(Time::Type time) const;

  // data per support interval
  typedef struct { 
    TimeInterval timeint;  // support
    double value;          // value
  } Entry;

  // convenience typedef 
  typedef std::map<Time::Type,Entry>::const_iterator CIterator;
  typedef std::map<Time::Type,Entry>::iterator Iterator;

  // access map
  CIterator Begin(void) const     { return mValueMap.begin();} ;
  CIterator End(void)   const     { return mValueMap.end();} ;
  CIterator At(Time::Type time) const { return mValueMap.lower_bound(time);} ;
  const TimeInterval& TimeInt(CIterator mit) const { return mit->second.timeint;};  
  const double& Value(CIterator mit) const { return mit->second.value;};  

  // access map (should be protected)
  Iterator Begin(void)            { return mValueMap.begin();} ;
  Iterator End(void)              { return mValueMap.end();} ;
  Iterator At(Time::Type time)        { return mValueMap.lower_bound(time);} ;
  const Entry& EntryAt(Time::Type time) const;

  // get/set name
  const std::string& Name(void) const { return mName;};
  void Name(const std::string& rName) { mName=rName;};

  // get/set count (-1 for not avail)
  int Count(void) const { return mCount;};
  void Count(int count) { mCount= count;};

  // get characteristics (set by compile)
  double MaxValue(void) const { return mMaxValue; };
  double MinValue(void) const { return mMinValue; };
  Time::Type MaxTime(void) const  { return mMaxTime; };
  Time::Type MinTime(void) const  { return mMinTime; };
  double Sum(void) const  { return mSum; };
  double SquareSum(void) const  { return mSquareSum; };
  double Average(void) const  { return mAverage; };
  double Variance(void) const  { return mVariance; };
  double Quantile05(void) const  { return mQuantile05; };
  double Quantile95(void) const  { return mQuantile95; };

  // file io
  void Write(TokenWriter& rTw) const;
  void Write(void) const;
  std::string ToString(void) const;
  void Read(TokenReader& rTr);

  // compute characteristics
  void Compile(void) const;
  
  // pretty string
  std::string Str(void) const;

 protected:

  // map of all support intervals
  std::map<Time::Type,Entry> mValueMap;

  // user data
  std::string mName;
  int mCount;

  // characteristics
  double mMaxValue;
  double mMinValue;
  Time::Type mMaxTime;
  Time::Type mMinTime;
  double mSum;
  double mSquareSum;
  double mAverage;
  double mVariance;
  double mQuantile05;
  double mQuantile95;

  // compute characteristics (non const version)
  virtual void CompileNonConst(void);

  // pseudo static zero entry
  Entry mEntryZero;
};



/*

Sampled Density Function

A SampledDensityFunction is a DiscreteDensityFunction that
is set up by sampling experiment outcome. This implementation
attempts to be smart in choosing sampling intervals and, hence,
requires minimal configuration. 

The current implementation is rather incomplete,
inefficient, and buggy. The ToDo list  includes
- interface incomplete
- compilation faulty
- no token io
- need to improve automatic sampling interval selection

*/

class FAUDES_API SampledDensityFunction : public DiscreteDensityFunction {

 public:

  // construct destruct
  SampledDensityFunction(void);
  virtual ~SampledDensityFunction(void) {};

  // set/get dimension
  void Dim(Idx dim) { mDim=dim; Clear();};
  Idx Dim(void) const { return mDim;};

  // clear all
  void Clear(void);

  // add sample
  void Sample(Time::Type time);
  
  // pretty string
  std::string SStr(void) const;

 protected:

  // data per support interval
  typedef struct { 
    TimeInterval timeint;  // support
    Idx  count;            // count
  } CountEntry;

  // convenience typedef 
  typedef std::map<Time::Type,CountEntry>::iterator CountIterator;
  typedef std::map<Time::Type,CountEntry>::const_iterator CCountIterator;

  // map of all support intervals
  std::map<Time::Type,CountEntry> mCountMap;

  // my target dimension;
  Idx mDim;

  // overall count
  double mCountSum;
  double mCountSquareSum;

  // compute characteristics (non const version)
  virtual void CompileNonConst(void);

};





} // namespace

#endif
