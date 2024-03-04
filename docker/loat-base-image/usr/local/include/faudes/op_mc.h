/** @file op_mc.h 

Method to verify mutual controllability for two given generators.
A definition of mutual controllability is given in 
S.-H. Lee and K. C. Wong, “Structural decentralised control of concurrent
DES,” European Journal of Control, vol. 35, pp. 1125-1134,2002.
*/

/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2006  Bernd Opitz
   Exclusive copyright is granted to Klaus Schmidt

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have receive a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA */


  
#ifndef FAUDES_OP_MC_H
#define FAUDES_OP_MC_H

#include "corefaudes.h"
#include "syn_include.h"
#include "op_debug.h"




namespace faudes {

/**
 * Verification of mutual controllability.
 * This function checks if two generators are mutually controllable w.r.t. each other.
 * A definition of mutual controllability is given in 
 * S.-H. Lee and K. C. Wong, “Structural decentralised control of concurrent
 * DES,” European Journal of Control, vol. 35, pp. 1125-1134,2002.
 *
 * @param rGen1
 *   Generator 1
 * @param rGen2 
 *   Generator 2
 *
 * @result
 *   True if mutual controllability is fulfilled
 *
 *
 * <h4>Example: </h4>
 * <p> Violation of mutual controllability </p>
 * <table> 
 * <tr> <td> rGen1 </td>  <td>  rGen2 </td> </tr>
 * <tr>
 * <td> @image html ex_mc1.png </td>
 * <td> @image html ex_mc2.png </td>
 * </tr>
 * </table> 
 * <p> Mutual controllability is fulfilled </p>
 * <table>
 * <tr> <td> rGen3 </td>  <td>  rGen2 </td> </tr>
 * <tr>
 * <td> @image html ex_mc3.png </td>
 * <td> @image html ex_mc2.png </td>
 * </tr>
 * </table> 
 *
 * @ingroup ObserverPlugin
 */
extern FAUDES_API bool IsMutuallyControllable(const System& rGen1, const System& rGen2);

/**
 * Verification of mutual controllability.
 * This function checks if two generators are mutually controllable w.r.t. each other.
 * Additionally, this function provides the states where mutual controllability fails
 * in case the condition is violated. 
 *
 * @param rGen1
 *   Generator 1
 * @param rGen2 
 *   Generator 2
 * @param rForbidden1
 *   Forbidden states in Generator 1
 * @param rForbidden2
 *   Forbidden states in Generator 2
 *
 * @result
 *   True if mutual controllability is fulfilled
 */
extern FAUDES_API bool IsMutuallyControllable(const System& rGen1, const System& rGen2, StateSet& rForbidden1, StateSet& rForbidden2);

/**
 * RTI wrapper
 */
extern FAUDES_API void IsMutuallyControllable(const System& rGen1, const System& rGen2, bool& rRes);


} // namespace faudes

#define FAUDES_OP_MC_H
#endif 
