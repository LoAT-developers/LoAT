/** @file  sp_random.h  Evaluating random variables */

/* 
   FAU Discrete Event System Simulator 

   Copyright (C) 2007  Christoph Doerr
   Exclusive copyright is granted to Thomas Moor

*/

#ifndef FAUDES_SP_RANDOM_H
#define FAUDES_SP_RANDOM_H

#include "tp_timeinterval.h"
#include "sp_executor.h"


namespace faudes {

/** 

@defgroup SimRandomVariables Random Variables

@ingroup SimulatorPlugin 

Sampling or evaluating random variables for simulation

This module implements the evaluation (also known as sampling) of random 
variables with various distributions. It specialises on restricted support
PDFs, since this is required for the ProposingExecutor. 

Random variables and their simulation is a highly involved topic and we give credit
to the sources from which this module stems:

1) 
Implementation of a random number generator from Stave Park and Dave Geyer, which
we use in original form up to minor cosmetic changes.

2)  
Inverse gaussian CDF by rational approxomation coefficients, presumably by Peter J, Acjlam,
which we use in its original form up to minor cosmetic changes.


3)
Gaussian CDF by an aproximation that we found in "Handbook of Mathematical Functions" by
Abromowitz and Stegun.

All sources were available freely and we did not find any restricting licensing terms. 
Thanks!


---------------------------------------------------------------------

Regarding 1), from the header of rngs.c
 
This is an ANSI C library for multi-stream random number generation.  
The use of this library is recommended as a replacement for the ANSI C 
rand() and srand() functions, particularly in simulation applications 
where the statistical 'goodness' of the random number generator is 
important.  The library supplies 256 streams of random numbers; use 
SelectStream(s) to switch between streams indexed s = 0,1,...,255.

The streams must be initialized.  The recommended way to do this is by
using the function PlantSeeds(x) with the value of x used to initialize 
the default stream and all other streams initialized automatically with
values dependent on the value of x.  The following convention is used 
to initialize the default stream: \n
if x > 0 then x is the state \n
if x < 0 then the state is obtained from the system clock \n
if x = 0 then the state is to be supplied interactively. \n

The generator used in this library is a so-called 'Lehmer random number
generator' which returns a pseudo-random number uniformly distributed
0.0 and 1.0.  The period is (m - 1) where m = 2,147,483,647 and the
smallest and largest possible values are (1 / m) and 1 - (1 / m)
respectively.  For more details see:

      "Random Number Generators: Good Ones Are Hard To Find"         \n
                  Steve Park and Keith Miller                        \n
             Communications of the ACM, October 1988                 \n

Name            : rngs.c  (Random Number Generation - Multiple Streams) \n
Authors         : Steve Park & Dave Geyer                               \n
Language        : ANSI C                                                \n
Latest Revision : 09-22-98

---------------------------------------------------------------------

Regarding 2), from the header of rngs.c

This function returns an approximation of the inverse cumulative
standard normal distribution function.  I.e., given P, it returns
an approximation to the X satisfying P = Pr{Z <= X} where Z is a
random variable from the standard normal distribution.
 
The algorithm uses a minimax approximation by rational functions
and the result has a relative error whose absolute value is less
than 1.15e-9.

Author:      Peter J. Acklam                                   \n
Time-stamp:  2002-06-09 18:45:44 +0200                         \n
E-mail:      jacklam at math dot uio dor no                    \n
WWW URL:     http www dot math dot uio dot no /~jacklam        \n
 
C implementation adapted from Peter's Perl version             \n

---------------------------------------------------------------------

Regarding 3) found as code example in Wikipedia

---------------------------------------------------------------------

{@

*/

/** 
 * Use this function to set the state of all the random number generator 
 * streams by "planting" a sequence of states (seeds), one per stream, 
 * with all states dictated by the state of the default stream. 
 * The sequence of planted states is separated one from the next by 
 * 8,367,782 calls to ran().
 */
void ran_plant_seeds(long x);

/**
 * Use this function to set the current random number generator
 * stream -- that stream from which the next random number will come.
 */
void ran_select_stream(int index);

/**
* Put a seed 
*   @param seed
*      Random generator seed	
*/
void ran_put_seed(long seed);

/**
* Initialize random generator 
*	@param seed
*	    Random generator seed
*/
void ran_init(long seed);

/**
* Run random generator 
*	Random Number Generator 
*	(for more details see "Random Number Generators: Good Ones Are Hard To Find"
*                   Steve Park and Keith Miller
*              Communications of the ACM, October 1988)
*	@return
*		Random value in [0,1) ( excluding 1 (?)) 
*/
double ran(void);


/**
* Sample a random variable uniformly on interval [a;b)
*    Distribution: f(t) dt= {1/(b-a)} dt  for t, a <=t< b, else 0
*	@param a
*		Lower bound
*	@param b 
*		Upper bound
*	@return 
*		Random value
*/
double ran_uniform(double a, double b);

/**
* Sample a discrete random variable uniformly on interval [a;b)
*    Distribution: p(n) = 1/(b-a-1)
*	@param a
*		Lower bound
*	@param b 
*		Upper bound
*	@return 
*		Random value
*/
long ran_uniform_int(long a, long b);

/**
* Sample a random variable exponentially 
*     Distribution: f(t) dt = 1/mu  exp(-t/mu) dt  for t>=0
*	@param mu
*		mu
*	@return 
*		Random variabe
*/
double ran_exponential(double mu);
	
/**
* Sample a random variable exponentially on a restricted interval
*     Distribution: f(t) dt = 1/mu  exp(-t/mu) dt  for t>=0
*	@param mu
*		mu
*	@param tossLB
*		Lower interval bound
*	@param tossUB
*		Upper interval bound
*/
double ran_exponential(double mu, Time::Type tossLB, Time::Type tossUB);

/**
* Sample a random variable gaussian distributed on a restricted interval
*     Distribution: f(t)  = 1 / sqrt(2 pi sigma^2) * exp( -1/2 ((t-mu)/sigma)^2) for  t>=0
*	@param mu
*		mu
*	@param sigma
*		sigma
*	@param tossLB
*		Lower interval bound
*	@param tossUB
*		Upper interval bound
*/
double ran_gauss(double mu, double sigma, Time::Type tossLB, Time::Type tossUB);

/**
* Help function: calculate gaussian CDF 
*	using an approximation from 
*	Abromowitz and Stegun: Handbook of Mathematical Functions 
*	@param x
*	@return CDF(x)
*/
double ran_gaussian_cdf_P(double x);

/** @} doxygen group */


} // namespace


#define FAUDES_STOCHRAN_H
#endif
