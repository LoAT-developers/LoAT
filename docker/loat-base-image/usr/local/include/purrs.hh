/* This is the header file of the Parma Recurrence Relation Solver.
   Copyright (C) 2001-2008 Roberto Bagnara <bagnara@cs.unipr.it>

This file is part of the Parma University's Recurrence Relation
Solver (PURRS).

The PURRS is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 2 of the License, or (at your
option) any later version.

The PURRS is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301,
USA.

For the most up-to-date information see the PURRS site:
http://www.cs.unipr.it/purrs/ . */

#ifndef PURRS_purrs_hh
#define PURRS_purrs_hh 1

#ifdef NDEBUG
#define PURRS_SAVE_NDEBUG 1
#undef NDEBUG
#endif

/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */


#ifndef _purrs_config_h
#define _purrs_config_h 1


/* Define if building universal (internal helper macro) */
/* #undef AC_APPLE_UNIVERSAL_BUILD */

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the `getrlimit' function. */
#define HAVE_GETRLIMIT 1

/* Define to 1 if you have the `getrusage' function. */
#define HAVE_GETRUSAGE 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `nice' function. */
#define HAVE_NICE 1

/* Define to 1 if you have the <readline/history.h> header file. */
#define HAVE_READLINE_HISTORY_H 1

/* Define to 1 if you have the <readline/readline.h> header file. */
#define HAVE_READLINE_READLINE_H 1

/* Define to 1 if you have the `setrlimit' function. */
#define HAVE_SETRLIMIT 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/resource.h> header file. */
#define HAVE_SYS_RESOURCE_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* Assertions are disabled when this is defined */
/* #undef NDEBUG */

/* Name of package */
#define PACKAGE "purrs"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "purrs-devel@cs.unipr.it"

/* Define to the full name of this package. */
#define PACKAGE_NAME "the Parma Recurrence Relation Solver"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "the Parma Recurrence Relation Solver 0.0.3"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "purrs"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "0.0.3"

/* Not zero if GMP has been compiled with support for exceptions. */
#define PPL_GMP_SUPPORTS_EXCEPTIONS 1

/* The size of `mp_limb_t', as computed by sizeof. */
#define SIZEOF_MP_LIMB_T 8

/* Define to 1 if all of the C90 standard headers exist (not just the ones
   required in a freestanding environment). This macro is provided for
   backward compatibility; new code need not use it. */
#define STDC_HEADERS 1

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. This
   macro is obsolete. */
#define TIME_WITH_SYS_TIME 1

/* The readline library is used if this is defined */
#define USE_READLINE 1

/* Version number of package */
#define VERSION "0.0.3"

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
/* #  undef WORDS_BIGENDIAN */
# endif
#endif

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif



// Neutralize relops for GCC 2.96.
#ifndef __SGI_STL_INTERNAL_RELOPS
#define __SGI_STL_INTERNAL_RELOPS
#endif

#if __GNUC__ >= 3
// Flexible array members at the end of a struct
// are defined as in
//   Type array[];
#define PURRS_FLEXIBLE_ARRAY
#else
// Flexible array members at the end of a struct
// are defined as in
//   Type array[0];
#define PURRS_FLEXIBLE_ARRAY 0
#endif

#ifndef LITTLE_ENDIAN
#define LITTLE_ENDIAN 1234
#define BIG_ENDIAN 4321
#endif

#ifndef __BYTE_ORDER
#ifdef WORDS_BIGENDIAN
#define __BYTE_ORDER BIG_ENDIAN
#else
#define __BYTE_ORDER LITTLE_ENDIAN
#endif
#endif

#define BOUNDARY_TYPE_IS_DOUBLE 1

#define INLINE inline

#endif


#if __GNUC__ < 3
// Get around a bug in GCC versions prior to 3 whereby the <cassert>
// header is wrongly guarded against multiple inclusion.
#ifdef __CASSERT__
#undef __CASSERT__
#endif

#endif

#include <algorithm>
#include <cassert>
#include <climits>
#include <deque>
#include <ginac/ginac.h>
#include <iosfwd>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
namespace Parma_Recurrence_Relation_Solver {
typedef unsigned int index_type;
}
namespace Parma_Recurrence_Relation_Solver {
enum Bool3 { ALWAYS, NEVER, MAYBE };
}
namespace Parma_Recurrence_Relation_Solver {
class Expr;
}
namespace Parma_Recurrence_Relation_Solver {
  class Constant;
}
namespace Parma_Recurrence_Relation_Solver {
class Symbol;
}
namespace Parma_Recurrence_Relation_Solver {
  class Number;
}
namespace Parma_Recurrence_Relation_Solver {
  class Expr_List;
}
namespace Parma_Recurrence_Relation_Solver {
class Init;
}
namespace Parma_Recurrence_Relation_Solver {
  class Matrix;
}
namespace Parma_Recurrence_Relation_Solver {
class Finite_Order_Info;
}
namespace Parma_Recurrence_Relation_Solver {
class Functional_Equation_Info;
}
namespace Parma_Recurrence_Relation_Solver {
class Blackboard;
}
namespace Parma_Recurrence_Relation_Solver {
class Cached_Expr;
}
namespace Parma_Recurrence_Relation_Solver {
class Non_Linear_Info;
}
namespace Parma_Recurrence_Relation_Solver {
class Weighted_Average_Info;
}
namespace Parma_Recurrence_Relation_Solver {
class Recurrence;
}
namespace Parma_Recurrence_Relation_Solver {
class Symbol {
public:
  Symbol();
  Symbol(const char* n);
  explicit Symbol(const std::string& str);
  Symbol(const Symbol& y);
  ~Symbol();
  Symbol& operator=(const Symbol& y);
  std::string get_name() const;
  bool is_system_generated() const;
  struct NameCompare {
    bool operator()(const Symbol& x, const Symbol& y) const;
  };
  typedef std::set<Symbol, Symbol::NameCompare> SymbolSet;
private:
  friend class Expr;
  friend class Expr_List;
  friend Expr quo(const Expr& a, const Expr& b, const Symbol& x);
  friend Expr rem(const Expr& a, const Expr& b, const Symbol& x);
  friend Expr prem(const Expr& a, const Expr& b, const Symbol& x);
  friend bool operator==(const Expr& e, const Symbol& s);
  GiNaC::symbol s;
  Symbol(const GiNaC::symbol& gs);
};
}
namespace Parma_Recurrence_Relation_Solver {
inline
Symbol::Symbol() {
}
inline
Symbol::Symbol(const char* n)
  : s(n) {
}
inline
Symbol::Symbol(const std::string& str)
  : s(str) {
}
inline
Symbol::Symbol(const Symbol& y)
  : s(y.s) {
};
inline Symbol&
Symbol::operator=(const Symbol& y) {
  s = y.s;
  return *this;
};
inline
Symbol::Symbol(const GiNaC::symbol& gs)
  : s(gs) {
}
inline
Symbol::~Symbol() {
}
inline std::string
Symbol::get_name() const {
  return s.get_name();
}
inline bool
Symbol::NameCompare::operator()(const Symbol& x, const Symbol& y) const {
  return x.get_name() < y.get_name();
}
}
namespace Parma_Recurrence_Relation_Solver {
Number operator+(const Number& x);
Number operator-(const Number& x);
Number operator+(const Number& x, const Number& y);
Number operator-(const Number& x, const Number& y);
Number operator*(const Number& x, const Number& y);
Number operator/(const Number& x, const Number& y);
Number& operator+=(Number& x, const Number& y);
Number& operator-=(Number& x, const Number& y);
Number& operator*=(Number& x, const Number& y);
Number& operator/=(Number& x, const Number& y);
bool operator==(const Number& x, const Number& y);
bool operator!=(const Number& x, const Number& y);
bool operator==(const Number& x, long i);
bool operator>(const Number& x, const Number& y);
bool operator<(const Number& x, const Number& y);
bool operator>=(const Number& x, const Number& y);
bool operator<=(const Number& x, const Number& y);
Number abs(const Number& x);
Number gcd(const Number& x, const Number& y);
Number lcm(const Number& x, const Number& y);
Number exact_pwr(const Number& x, const Number& y);
Number mod(const Number& x, const Number& y);
class Number {
public:
  Number();
  Number(int i);
  Number(unsigned int i);
  Number(long i);
  Number(unsigned long i);
  Number(const char* s);
  Number(long n, long d);
  Number(const Number& y);
  ~Number();
  Number& operator=(const Number& y);
  Number& operator=(int i);
  Number& operator=(unsigned int i);
  Number& operator=(long i);
  Number& operator=(unsigned long i);
  Number& operator=(const char* s);
  Number& operator++();
  Number& operator--();
  Number operator++(int);
  Number operator--(int);
  bool is_zero() const;
  bool is_positive() const;
  bool is_negative() const;
  bool is_integer() const;
  bool is_positive_integer() const;
  bool is_nonnegative_integer() const;
  bool is_even() const;
  bool is_odd() const;
  bool is_prime() const;
  bool is_rational() const;
  bool is_real() const;
  bool is_complex_integer() const;
  bool is_complex_rational() const;
  int to_int() const;
  unsigned int to_unsigned_int() const;
  long to_long() const;
  double to_double() const;
  Number real() const;
  Number imaginary() const;
  Number numerator() const;
  Number denominator() const;
  static Number I();
private:
  friend class Expr;
  friend Number operator+(const Number& x);
  friend Number operator-(const Number& x);
  friend Number operator+(const Number& x, const Number& y);
  friend Number operator-(const Number& x, const Number& y);
  friend Number operator*(const Number& x, const Number& y);
  friend Number operator/(const Number& x, const Number& y);
  friend Number& operator+=(Number& x, const Number& y);
  friend Number& operator-=(Number& x, const Number& y);
  friend Number& operator*=(Number& x, const Number& y);
  friend Number& operator/=(Number& x, const Number& y);
  friend bool operator==(const Number& x, const Number& y);
  friend bool operator!=(const Number& x, const Number& y);
  friend bool operator>(const Number& x, const Number& y);
  friend bool operator<(const Number& x, const Number& y);
  friend bool operator>=(const Number& x, const Number& y);
  friend bool operator<=(const Number& x, const Number& y);
  friend bool operator==(const Number& x, long i);
  friend Number abs(const Number& x);
  friend Number gcd(const Number& x, const Number& y);
  friend Number lcm(const Number& x, const Number& y);
  friend Number exact_pwr(const Number& x, const Number& y);
  friend Number mod(const Number& x, const Number& y);
private:
  friend bool operator==(const Expr& e, const Number& n);
  GiNaC::numeric n;
  Number(const GiNaC::numeric& gn);
};
}
namespace Parma_Recurrence_Relation_Solver {
inline
Number::Number() {
}
inline
Number::Number(int i)
  : n(i) {
}
inline
Number::Number(unsigned int i)
  : n(i) {
}
inline
Number::Number(long i)
  : n(i) {
}
inline
Number::Number(unsigned long i)
  : n(i) {
}
inline
Number::Number(const char* s)
  : n(s) {
}
inline
Number::Number(long n, long d)
  : n(n, d) {
}
inline
Number::Number(const Number& y)
  : n(y.n) {
}
inline
Number::Number(const GiNaC::numeric& gn)
  : n(gn) {
}
inline
Number::~Number() {
}
inline Number&
Number::operator=(const Number& y) {
  n = y.n;
  return *this;
}
inline Number&
Number::operator=(int i) {
  n = i;
  return *this;
}
inline Number&
Number::operator=(unsigned int i) {
  n = i;
  return *this;
}
inline Number&
Number::operator=(long i) {
  n = i;
  return *this;
}
inline Number&
Number::operator=(unsigned long i) {
  n = i;
  return *this;
}
inline Number&
Number::operator=(const char* s) {
  n = s;
  return *this;
}
inline Number&
operator+=(Number& x, const Number& y) {
  x.n += y.n;
  return x;
}
inline Number&
operator-=(Number& x, const Number& y) {
  x.n -= y.n;
  return x;
}
inline Number&
operator*=(Number& x, const Number& y) {
  x.n *= y.n;
  return x;
}
inline Number&
operator/=(Number& x, const Number& y) {
  x.n /= y.n;
  return x;
}
inline Number
operator+(const Number& x) {
  return x;
}
inline Number
operator-(const Number& x) {
  return -x.n;
}
inline Number
operator+(const Number& x, const Number& y) {
  return x.n + y.n;
}
inline Number
operator-(const Number& x, const Number& y) {
  return x.n - y.n;
}
inline Number
operator*(const Number& x, const Number& y) {
  return x.n * y.n;
}
inline Number
operator/(const Number& x, const Number& y) {
  return x.n / y.n;
}
inline Number&
Number::operator++() {
  ++n;
  return *this;
}
inline Number&
Number::operator--() {
  --n;
  return *this;
}
inline Number
Number::operator++(int) {
  return n++;
}
inline Number
Number::operator--(int) {
  return n--;
}
inline bool
operator==(const Number& x, const Number& y) {
  return x.n == y.n;
}
inline bool
operator!=(const Number& x, const Number& y) {
  return x.n != y.n;
}
inline bool
operator==(const Number& x, long i) {
  return x.n.operator==(i);
}
inline bool
operator>(const Number& x, const Number& y) {
  return x.n > y.n;
}
inline bool
operator<(const Number& x, const Number& y) {
  return x.n < y.n;
}
inline bool
operator>=(const Number& x, const Number& y) {
  return x.n >= y.n;
}
inline bool
operator<=(const Number& x, const Number& y) {
  return x.n <= y.n;
}
inline Number
abs(const Number& x) {
  return GiNaC::abs(x.n);
}
inline Number
gcd(const Number& x, const Number& y) {
  return GiNaC::gcd(x.n, y.n);
}
inline Number
lcm(const Number& x, const Number& y) {
  return GiNaC::lcm(x.n, y.n);
}
inline Number
exact_pwr(const Number& x, const Number& y) {
  assert(x.is_complex_rational() && y.is_integer());
  assert((!x.is_zero() || !y.is_zero())
  && ((!x.is_zero()) || (x.is_zero() && y.is_positive())));
  return GiNaC::pow(x.n, y.n);
}
inline bool
Number::is_zero() const {
  return n.is_zero();
}
inline bool
Number::is_positive() const {
  return n.is_positive();
}
inline bool
Number::is_negative() const {
  return n.is_negative();
}
inline bool
Number::is_integer() const {
  return n.is_integer();
}
inline bool
Number::is_positive_integer() const {
  return n.is_pos_integer();
}
inline bool
Number::is_nonnegative_integer() const {
  return n.is_nonneg_integer();
}
inline bool
Number::is_even() const {
  return n.is_even();
}
inline bool
Number::is_odd() const {
  return n.is_odd();
}
inline bool
Number::is_prime() const {
  if (!is_positive_integer())
    return false;
  return n.is_prime();
}
inline bool
Number::is_rational() const {
  return n.is_rational();
}
inline bool
Number::is_real() const {
  return n.is_real();
}
inline bool
Number::is_complex_integer() const {
  return n.is_cinteger();
}
inline bool
Number::is_complex_rational() const {
  return n.is_crational();
}
inline int
Number::to_int() const {
  if (!is_integer() || (n > 0 && n > INT_MAX) || (n < 0 && n < INT_MIN))
    throw std::domain_error("Cannot convert to an `int' "
       "in PURRS::Number::to_int()");
  return n.to_int();
}
inline unsigned int
Number::to_unsigned_int() const {
  if (!is_integer() || (n > 0 && n > INT_MAX) || (n < 0 && n < INT_MIN))
    throw std::domain_error("Cannot convert to an `int' "
       "in PURRS::Number::to_int()");
  return unsigned(n.to_int());
}
inline long
Number::to_long() const {
  if (!is_integer() || (n > 0 && n > LONG_MAX) || (n < 0 && n < LONG_MIN))
    throw std::domain_error("Cannot convert to a `long' "
       "in PURRS::Number::to_long()");
  return n.to_long();
}
inline double
Number::to_double() const {
  return n.to_double();
}
inline Number
Number::real() const {
  return n.real();
}
inline Number
Number::imaginary() const {
  return n.imag();
}
inline Number
Number::numerator() const {
  return n.numer();
}
inline Number
Number::denominator() const {
  return n.denom();
}
inline Number
mod(const Number& x, const Number& y) {
  if (y.is_zero())
    throw std::runtime_error("Division by zero in PURRS::Number::mod()");
  return GiNaC::mod(x.n, y.n);
}
inline Number
Number::I() {
  return GiNaC::I;
}
}
namespace Parma_Recurrence_Relation_Solver {
class Constant {
public:
  Constant();
  Constant(const Constant& k);
  ~Constant();
  Constant& operator=(const Constant& k);
  static Constant Pi();
private:
  friend class Expr;
  friend bool operator==(const Expr& e, const Constant& c);
  GiNaC::constant c;
  Constant(const GiNaC::constant& gc);
};
}
namespace Parma_Recurrence_Relation_Solver {
inline
Constant::Constant() {
}
inline
Constant::Constant(const Constant& k)
  : c(k.c) {
};
inline Constant&
Constant::operator=(const Constant& k) {
  c = k.c;
  return *this;
};
inline
Constant::Constant(const GiNaC::constant& gc)
  : c(gc) {
}
inline
Constant::~Constant() {
}
inline
Constant Constant::Pi() {
  return GiNaC::Pi;
}
}
namespace GiNaC {
  ex max_eval(const ex&, const ex&);
  ex min_eval(const ex&, const ex&);
}
namespace Parma_Recurrence_Relation_Solver {
typedef unsigned int Functor;
std::ostream& operator<<(std::ostream& s, const Expr& x);
Expr operator+(const Expr& x);
Expr operator-(const Expr& x);
Expr operator+(const Expr& x, const Expr& y);
Expr operator-(const Expr& x, const Expr& y);
Expr operator*(const Expr& x, const Expr& y);
Expr operator/(const Expr& x, const Expr& y);
Expr& operator+=(Expr& x, const Expr& y);
Expr& operator-=(Expr& x, const Expr& y);
Expr& operator*=(Expr& x, const Expr& y);
Expr& operator/=(Expr& x, const Expr& y);
bool operator==(const Expr& e, const Symbol& s);
bool operator!=(const Expr& e, const Symbol& s);
bool operator==(const Symbol& s, const Expr& e);
bool operator!=(const Symbol& s, const Expr& e);
bool operator==(const Expr& e, const Constant& c);
bool operator!=(const Expr& e, const Constant& c);
bool operator==(const Constant& c, const Expr& e);
bool operator!=(const Constant& c, const Expr& e);
bool operator==(const Expr& e, const Number& n);
bool operator==(const Number& n, const Expr& e);
bool operator==(const Expr& e, long i);
bool operator==(const Expr& x, const Expr& y);
bool operator!=(const Expr& x, const Expr& y);
int compare(const Expr& x, const Expr& y);
Functor find_functor(const std::string& name, unsigned int num_args = 1);
Expr apply(Functor f, const Expr& x);
Expr apply(Functor f, const Expr& x1, const Expr& x2);
Expr apply(Functor f, const Expr& x1, const Expr& x2, const Expr& x3);
Expr apply(Functor f,
    const Expr& x1, const Expr& x2, const Expr& x3, const Expr& x4);
Expr apply(Functor f, const std::vector<Expr>& x);
Expr pwr(const Expr& x, const Expr& y);
Expr sqrt(const Expr& x);
Expr sin(const Expr& x);
Expr cos(const Expr& x);
Expr acos(const Expr& x);
Expr tan(const Expr& x);
Expr exp(const Expr& x);
Expr log(const Expr& x);
Expr factorial(const Expr& x);
Expr gamma(const Expr& x);
Expr binom(const Expr& m, const Expr& k);
Expr quo(const Expr& a, const Expr& b, const Symbol& x);
Expr rem(const Expr& a, const Expr& b, const Symbol& x);
Expr prem(const Expr& a, const Expr& b, const Symbol& x);
Expr gcd(const Expr& a, const Expr& b);
Expr lcm(const Expr& a, const Expr& b);
Expr sqrfree(const Expr& x, const Expr_List& y);
Expr lsolve(const Expr_List& x, const Expr_List& y);
Expr x(const Expr& y);
Expr floor(const Expr& x);
Expr Sc(const Expr& x, const Expr& y);
Expr mod(const Expr& x, const Expr& y);
Expr sum(const Expr& index, const Expr& lower, const Expr& upper,
  const Expr& summand);
Expr prod(const Expr& index, const Expr& lower, const Expr& upper,
   const Expr& factor);
Expr max(const Expr& first, const Expr& second);
class Expr : private GiNaC::ex {
private:
  typedef GiNaC::ex Base;
public:
  Expr();
  static Expr fromGiNaC(const Base &b) { return Expr(b); }
  inline Base toGiNaC() const { return (GiNaC::ex)*this; }
  Expr(int i);
  Expr(unsigned int i);
  Expr(long i);
  Expr(unsigned long i);
  Expr(const Number& y);
  Expr(const Symbol& y);
  Expr(const Constant& y);
  Expr(const std::string& s, const Expr_List& y);
  Expr(const Expr& x, const Expr& y);
  Expr(const Expr& y);
  ~Expr();
  Expr& operator=(const Expr& y);
  bool is_a_symbol() const;
  bool is_a_symbol(Symbol& s) const;
  bool is_a_number() const;
  bool is_a_number(Number& n) const;
  bool is_a_constant() const;
  bool is_a_add() const;
  bool is_a_mul() const;
  bool is_a_power() const;
  bool is_a_constant_power(const Symbol& x) const;
  bool is_a_function() const;
  bool is_a_constant_function(const Symbol& x) const;
  bool is_a_matrix() const;
  bool is_a_Expr_List() const;
  bool is_a_relational() const;
  bool is_the_abs_function() const;
  bool is_the_exp_function() const;
  bool is_the_log_function() const;
  bool is_the_sin_function() const;
  bool is_the_cos_function() const;
  bool is_the_tan_function() const;
  bool is_the_acos_function() const;
  bool is_the_factorial_function() const;
  bool is_the_gamma_function() const;
  bool is_the_binom_function() const;
  bool is_the_x_function() const;
  bool is_the_x1_function() const;
  bool is_the_x2_function() const;
  bool is_the_floor_function() const;
  bool is_the_Sc_function() const;
  bool is_the_mod_function() const;
  bool is_the_sum_function() const;
  bool is_the_prod_function() const;
  bool is_the_max_function() const;
  Number ex_to_number() const;
  Symbol ex_to_symbol() const;
  bool is_relation_equal() const;
  Functor functor() const;
  std::string get_function_name() const;
  unsigned int nops() const;
  Expr op(unsigned int i) const;
  Expr arg(unsigned int i) const;
  bool is_zero() const;
  Expr substitute(const Expr& s, const Expr& r) const;
  bool has(const Expr& x) const;
  Expr distribute_mul_over_add() const;
  Expr expand() const;
  bool is_expanded() const;
  Expr collect(const Expr_List& x) const;
  unsigned int degree(const Symbol& x) const;
  unsigned int ldegree(const Symbol& x) const;
  Expr coeff(const Symbol& x, int k) const;
  Expr lcoeff(const Symbol& x) const;
  Expr tcoeff(const Symbol& x) const;
  Expr primpart(const Symbol& x) const;
  Expr content(const Symbol& x) const;
  Expr numerator() const;
  Expr denominator() const;
  void numerator_denominator(Expr& x, Expr& y) const;
  Expr lhs() const;
  Expr rhs() const;
  Expr diff(const Symbol& x, unsigned int nth = 1);
  void latex_print(std::ostream& s);
  void mathml_output(std::ostream& s) const;
  bool is_scalar_representation(const Symbol& x) const;
  bool is_integer_scalar_representation(const Symbol& x) const;
  bool is_rational_scalar_representation(const Symbol& x) const;
  bool is_scalar_representation() const;
  bool is_polynomial(const Symbol& x) const;
  bool is_integer_polynomial(const Symbol& x) const;
  bool is_rational_polynomial(const Symbol& x) const;
  bool is_multivariate_polynomial() const;
  bool is_rational_function(const Symbol& x) const;
  bool has_non_rational_numbers() const;
  bool has_x_function() const;
  bool has_x_function(const Expr& y) const;
  bool has_sum_or_prod_function() const;
  bool preserves_nonnegativity() const;
  Expr collect_term(const Expr& x, Expr& coeff_x) const;
  Expr unsafe_fp_approximation() const;
  void collect_symbols(Symbol::SymbolSet& system_generated_symbols,
         Symbol::SymbolSet& new_symbols) const;
private:
  friend class Number;
  friend class Symbol;
  friend class Constant;
  friend class Expr_List;
  friend class Matrix;
  friend std::ostream& operator<<(std::ostream& s, const Expr& x);
  friend Expr operator+(const Expr& x);
  friend Expr operator-(const Expr& x);
  friend Expr operator+(const Expr& x, const Expr& y);
  friend Expr operator-(const Expr& x, const Expr& y);
  friend Expr operator*(const Expr& x, const Expr& y);
  friend Expr operator/(const Expr& x, const Expr& y);
  friend Expr& operator+=(Expr& x, const Expr& y);
  friend Expr& operator-=(Expr& x, const Expr& y);
  friend Expr& operator*=(Expr& x, const Expr& y);
  friend Expr& operator/=(Expr& x, const Expr& y);
  friend bool operator==(const Expr& e, const Symbol& s);
  friend bool operator==(const Expr& e, const Constant& c);
  friend bool operator==(const Expr& e, const Number& n);
  friend bool operator==(const Expr& e, long i);
  friend bool operator==(const Expr& x, const Expr& y);
  friend int compare(const Expr& x, const Expr& y);
  friend Expr apply(Functor f, const Expr& x);
  friend Expr apply(Functor f, const Expr& x1, const Expr& x2);
  friend Expr apply(Functor f, const Expr& x1, const Expr& x2, const Expr& x3);
  friend Expr apply(Functor f,
      const Expr& x1, const Expr& x2,
      const Expr& x3, const Expr& x4);
  friend Expr apply(Functor f, const std::vector<Expr>& x);
  friend Expr pwr(const Expr& x, const Expr& y);
  friend Expr sqrt(const Expr& x);
  friend Expr sin(const Expr& x);
  friend Expr cos(const Expr& x);
  friend Expr acos(const Expr& x);
  friend Expr tan(const Expr& x);
  friend Expr exp(const Expr& x);
  friend Expr log(const Expr& x);
  friend Expr factorial(const Expr& x);
  friend Expr gamma(const Expr& x);
  friend Expr binom(const Expr& m, const Expr& k);
  friend Expr quo(const Expr& a, const Expr& b, const Symbol& x);
  friend Expr rem(const Expr& a, const Expr& b, const Symbol& x);
  friend Expr prem(const Expr& a, const Expr& b, const Symbol& x);
  friend Expr gcd(const Expr& a, const Expr& b);
  friend Expr lcm(const Expr& a, const Expr& b);
  friend Expr sqrfree(const Expr& x, const Expr_List& y);
  friend Expr lsolve(const Expr_List& x, const Expr_List& y);
  friend Expr x(const Expr& y);
  friend Expr floor(const Expr& x);
  friend Expr Sc(const Expr& x, const Expr& y);
  friend Expr mod(const Expr& x, const Expr& y);
  friend Expr sum(const Expr& index, const Expr& lower, const Expr& upper,
    const Expr& summand);
  friend Expr prod(const Expr& index, const Expr& lower, const Expr& upper,
     const Expr& factor);
  friend Expr max(const Expr& x, const Expr& y);
  friend Expr min(const Expr& x, const Expr& y);
  friend GiNaC::ex GiNaC::max_eval(const GiNaC::ex& x, const GiNaC::ex& y);
  friend GiNaC::ex GiNaC::min_eval(const GiNaC::ex& x, const GiNaC::ex& y);
  Expr(const Base& ge);
  Expr(const GiNaC::function& gf);
};
template <typename SymbolHandler>
unsigned int
generic_size_norm(const Expr& e, const SymbolHandler& sh);
void mathml_print(const GiNaC::ex& e, std::ostream& s);
}
namespace Parma_Recurrence_Relation_Solver {
class Expr_List {
public:
  Expr_List();
  explicit Expr_List(const Symbol& x);
  explicit Expr_List(const Expr& e);
  Expr_List(const Expr& x1, const Expr& x2);
  Expr_List(const Expr& x1, const Expr& x2, const Expr& x3,
     const Expr& x4, const Expr& x5);
  Expr_List(const Expr& x1, const Expr& x2, const Expr& x3,
     const Expr& x4, const Expr& x5, const Expr& x6);
  Expr_List(const Expr_List& x);
  ~Expr_List();
  Expr_List& operator=(const Expr_List& x);
  unsigned nops() const;
  Expr op(unsigned i) const;
  Expr_List& append(const Expr& x);
  Expr_List& prepend(const Expr& x);
  Expr_List& remove_first();
private:
  friend class Expr;
  friend class Matrix;
  friend Expr sqrfree(const Expr& x, const Expr_List& y);
  friend Expr lsolve(const Expr_List& x, const Expr_List& y);
  GiNaC::lst l;
  Expr_List(const GiNaC::lst& gl);
};
}
namespace GiNaC {
DECLARE_FUNCTION_1P(floor);
DECLARE_FUNCTION_2P(Sc);
DECLARE_FUNCTION_2P(mod);
DECLARE_FUNCTION_2P(binom);
DECLARE_FUNCTION_4P(sum);
DECLARE_FUNCTION_4P(prod);
DECLARE_FUNCTION_2P(max);
DECLARE_FUNCTION_2P(min);
class x1_SERIAL { public: static unsigned serial; };
template<typename T1>
inline function x(const T1& p1) {
  return function(x1_SERIAL::serial, ex(p1));
}
class x2_SERIAL { public: static unsigned serial; };
  template<typename T1, typename T2>
  inline function x(const T1& p1, const T2& p2) {
    return function(x2_SERIAL::serial, ex(p1), ex(p2));
  }
template<> inline bool is_the_function<class x_SERIAL>(const ex& e)
  {
    return is_the_function<x1_SERIAL>(e) || is_the_function<x2_SERIAL>(e);
  }
}
namespace Parma_Recurrence_Relation_Solver {
inline
Expr::Expr() {
}
inline
Expr::Expr(int i)
  : Base(i) {
}
inline
Expr::Expr(unsigned int i)
  : Base(i) {
}
inline
Expr::Expr(long i)
  : Base(i) {
}
inline
Expr::Expr(unsigned long i)
  : Base(i) {
}
inline
Expr::Expr(const Number& y)
  : Base(y.n) {
}
inline
Expr::Expr(const Symbol& y)
  : Base(y.s) {
}
inline
Expr::Expr(const Constant& y)
  : Base(y.c) {
}
inline
Expr::Expr(const std::string& s, const Expr_List& y)
  : Base(s, y.l) {
}
inline
Expr::Expr(const Expr& x, const Expr& y)
  : Base(GiNaC::relational(static_cast<const Base&>(x),
       static_cast<const Base&>(y))) {
}
inline
Expr::Expr(const Expr& y)
  : Base(y) {
}
inline Expr&
Expr::operator=(const Expr& y) {
  Base::operator=(y);
  return *this;
}
inline
Expr::Expr(const Base& ge)
  : Base(ge) {
}
inline
Expr::Expr(const GiNaC::function& gf)
  : Base(gf) {
}
inline
Expr::~Expr() {
}
inline bool
Expr::is_a_symbol() const {
  return GiNaC::is_a<GiNaC::symbol>(*this);
}
inline bool
Expr::is_a_symbol(Symbol& s) const {
  if (GiNaC::is_a<GiNaC::symbol>(*this)) {
    s = GiNaC::ex_to<GiNaC::symbol>(*this);
    return true;
  }
  return false;
}
inline bool
Expr::is_a_number() const {
  return GiNaC::is_a<GiNaC::numeric>(*this);
}
inline bool
Expr::is_a_number(Number& n) const {
  if (GiNaC::is_a<GiNaC::numeric>(*this)) {
    n = GiNaC::ex_to<GiNaC::numeric>(*this);
    return true;
  }
  return false;
}
inline bool
Expr::is_a_constant() const {
  return GiNaC::is_a<GiNaC::constant>(*this);
}
inline bool
Expr::is_a_add() const {
  return GiNaC::is_a<GiNaC::add>(*this);
}
inline bool
Expr::is_a_mul() const {
  return GiNaC::is_a<GiNaC::mul>(*this);
}
inline bool
Expr::is_a_power() const {
  return GiNaC::is_a<GiNaC::power>(*this);
}
inline bool
Expr::is_a_function() const {
  return GiNaC::is_a<GiNaC::function>(*this);
}
inline bool
Expr::is_a_matrix() const {
  return GiNaC::is_a<GiNaC::matrix>(*this);
}
inline bool
Expr::is_a_Expr_List() const {
  return GiNaC::is_a<GiNaC::lst>(*this);
}
inline bool
Expr::is_a_relational() const {
  return GiNaC::is_a<GiNaC::relational>(*this);
}
inline Number
Expr::ex_to_number() const {
  assert(GiNaC::is_a<GiNaC::numeric>(*this));
  return GiNaC::ex_to<GiNaC::numeric>(*this);
}
inline Symbol
Expr::ex_to_symbol() const {
  assert(GiNaC::is_a<GiNaC::symbol>(*this));
  return GiNaC::ex_to<GiNaC::symbol>(*this);
}
inline bool
Expr::is_relation_equal() const {
  return info(GiNaC::info_flags::relation_equal);
}
inline std::ostream&
operator<<(std::ostream& s, const Expr& x) {
  s << static_cast<const Expr::Base&>(x);
  return s;
}
inline Expr
operator+(const Expr& x) {
  return x;
}
inline Expr
operator-(const Expr& x) {
  return -static_cast<const Expr::Base&>(x);
}
inline Expr
operator+(const Expr& x, const Expr& y) {
  return static_cast<const Expr::Base&>(x) + static_cast<const Expr::Base&>(y);
}
inline Expr
operator-(const Expr& x, const Expr& y) {
  return static_cast<const Expr::Base&>(x) - static_cast<const Expr::Base&>(y);
}
inline Expr
operator*(const Expr& x, const Expr& y) {
  return static_cast<const Expr::Base&>(x) * static_cast<const Expr::Base&>(y);
}
inline Expr
operator/(const Expr& x, const Expr& y) {
  return static_cast<const Expr::Base&>(x) / static_cast<const Expr::Base&>(y);
}
inline Expr&
operator+=(Expr& x, const Expr& y) {
  static_cast<Expr::Base&>(x) += static_cast<const Expr::Base&>(y);
  return x;
}
inline Expr&
operator-=(Expr& x, const Expr& y) {
  static_cast<Expr::Base&>(x) -= static_cast<const Expr::Base&>(y);
  return x;
}
inline Expr&
operator*=(Expr& x, const Expr& y) {
  static_cast<Expr::Base&>(x) *= static_cast<const Expr::Base&>(y);
  return x;
}
inline Expr&
operator/=(Expr& x, const Expr& y) {
  static_cast<Expr::Base&>(x) /= static_cast<const Expr::Base&>(y);
  return x;
}
inline bool
operator==(const Expr& e, const Symbol& s) {
  return e.is_a_symbol() && GiNaC::ex_to<GiNaC::symbol>(e).is_equal(s.s);
}
inline bool
operator!=(const Expr& e, const Symbol& s) {
  return !(e == s);
}
inline bool
operator==(const Symbol& s, const Expr& e) {
  return e == s;
}
inline bool
operator!=(const Symbol& s, const Expr& e) {
  return !(s == e);
}
inline bool
operator==(const Expr& e, const Constant& c) {
  return e.is_a_constant() && GiNaC::ex_to<GiNaC::constant>(e).is_equal(c.c);
}
inline bool
operator!=(const Expr& e, const Constant& c) {
  return !(e == c);
}
inline bool
operator==(const Constant& c, const Expr& e) {
  return e == c;
}
inline bool
operator!=(const Constant& c, const Expr& e) {
  return !(c == e);
}
inline bool
operator==(const Expr& e, const Number& n) {
  return e.is_a_number() && GiNaC::ex_to<GiNaC::numeric>(e).is_equal(n.n);
}
inline bool
operator==(const Number& n, const Expr& e) {
  return e == n;
}
inline bool
operator==(const Expr& e, long i) {
  return e.is_a_number()
    && GiNaC::ex_to<GiNaC::numeric>(e).operator==(i);
}
inline bool
operator==(const Expr& x, const Expr& y) {
  return x.Base::is_equal(y);
}
inline bool
operator!=(const Expr& x, const Expr& y) {
  return !(x == y);
}
inline Functor
Expr::functor() const {
  assert(is_a_function());
  return GiNaC::ex_to<GiNaC::function>(*this).get_serial();
}
inline std::string
Expr::get_function_name() const {
  assert(is_a_function());
  return GiNaC::ex_to<GiNaC::function>(*this).get_name();
}
inline unsigned int
Expr::nops() const {
  return Base::nops();
}
inline Expr
Expr::op(unsigned int i) const {
  assert(!is_a_function() && !is_a_power());
  if (i > nops()-1)
    throw std::out_of_range("PURRS::Expr::op(): the index of `op()' "
       "must be between 0 and `nops()-1'");
  return Base::op(i);
}
inline Expr
Expr::arg(unsigned int i) const {
  assert(is_a_function() || is_a_power());
  if (i > nops()-1)
    throw std::out_of_range("PURRS::Expr::arg(): the index of `arg()' "
       "must be between 0 and `nops()-1'");
  return Base::op(i);
}
inline bool
Expr::is_zero() const {
  return Base::is_zero();
}
inline bool
Expr::has(const Expr& x) const {
  return Base::has(x);
}
inline Expr
Expr::expand() const {
  return Base::expand();
}
inline bool
Expr::is_expanded() const {
  return *this == expand();
}
inline Expr
Expr::collect(const Expr_List& x) const {
  return Base::collect(x.l);
}
inline unsigned int
Expr::degree(const Symbol& x) const {
  assert(is_expanded());
  assert(is_polynomial(x.s));
  int d = Base::degree(x.s);
  assert(d >= 0);
  return unsigned(d);
}
inline unsigned int
Expr::ldegree(const Symbol& x) const {
  assert(is_expanded());
  assert(is_polynomial(x.s));
  int d = Base::ldegree(x.s);
  assert(d >= 0);
  return unsigned(d);
}
inline Expr
Expr::coeff(const Symbol& x, int k) const {
  assert(is_expanded());
  assert(is_polynomial(x.s));
  return Base::coeff(x.s, k);
}
inline Expr
Expr::lcoeff(const Symbol& x) const {
  assert(is_expanded());
  assert(is_polynomial(x.s));
  return Base::lcoeff(x.s);
}
inline Expr
Expr::tcoeff(const Symbol& x) const {
  assert(is_expanded());
  assert(is_polynomial(x.s));
  return Base::tcoeff(x.s);
}
inline Expr
Expr::primpart(const Symbol& x) const {
  assert(is_expanded());
  assert(is_polynomial(x.s));
  return Base::primpart(x.s);
}
inline Expr
Expr::content(const Symbol& x) const {
  assert(is_expanded());
  assert(is_polynomial(x.s));
  return Base::content(x.s);
}
inline Expr
Expr::numerator() const {
  return Base::numer();
}
inline Expr
Expr::denominator() const {
  return Base::denom();
}
inline void
Expr::numerator_denominator(Expr& x, Expr& y) const {
  const Expr& tmp = Base::numer_denom();
  x = tmp.op(0);
  y = tmp.op(1);
}
inline Expr
Expr::lhs() const {
  return Base::lhs();
}
inline Expr
Expr::rhs() const {
  return Base::rhs();
}
inline Expr
Expr::diff(const Symbol& x, unsigned int nth) {
  return Base::diff(x.s, nth);
}
inline Expr
Expr::unsafe_fp_approximation() const {
  return Base::evalf();
}
inline Functor
find_functor(const std::string& name, unsigned int num_args) {
  return GiNaC::function::find_function(name, num_args);
}
inline Expr
apply(Functor f, const Expr& x) {
  return GiNaC::function(f, static_cast<const Expr::Base>(x));
}
inline Expr
apply(Functor f, const Expr& x1, const Expr& x2) {
  return GiNaC::function(f,
    static_cast<const Expr::Base>(x1),
    static_cast<const Expr::Base>(x2));
}
inline Expr
apply(Functor f, const Expr& x1, const Expr& x2, const Expr& x3) {
  return GiNaC::function(f,
    static_cast<const Expr::Base>(x1),
    static_cast<const Expr::Base>(x2),
    static_cast<const Expr::Base>(x3));
}
inline Expr
apply(Functor f,
      const Expr& x1, const Expr& x2, const Expr& x3, const Expr& x4) {
  return GiNaC::function(f,
    static_cast<const Expr::Base>(x1),
    static_cast<const Expr::Base>(x2),
    static_cast<const Expr::Base>(x3),
    static_cast<const Expr::Base>(x4));
}
inline Expr
apply(Functor f, const std::vector<Expr>& x) {
  unsigned int x_size = x.size();
  assert(x_size > 1);
  switch (x_size) {
  case 2:
    return apply(f, x[0], x[1]);
    break;
  case 3:
    return apply(f, x[0], x[1], x[2]);
    break;
  case 4:
    return apply(f, x[0], x[1], x[2], x[3]);
    break;
  default:
    {
      std::vector<GiNaC::ex> tmp_x(x_size);
      for (unsigned int i = 0; i < x_size; ++i)
 tmp_x[i] = static_cast<const Expr::Base>(x[i]);
      return GiNaC::function(f, tmp_x);
    }
  }
}
inline Expr
pwr(const Expr& x, const Expr& y) {
  return GiNaC::pow(static_cast<const Expr::Base>(x),
      static_cast<const Expr::Base>(y));
}
inline Expr
sqrt(const Expr& x) {
  return GiNaC::sqrt(static_cast<const Expr::Base>(x));
}
inline Expr
sin(const Expr& x) {
  return GiNaC::sin(static_cast<const Expr::Base>(x));
}
inline Expr
cos(const Expr& x) {
  return GiNaC::cos(static_cast<const Expr::Base>(x));
}
inline Expr
acos(const Expr& x) {
  return GiNaC::acos(static_cast<const Expr::Base>(x));
}
inline Expr
tan(const Expr& x) {
  return GiNaC::tan(static_cast<const Expr::Base>(x));
}
inline Expr
exp(const Expr& x) {
  return GiNaC::exp(static_cast<const Expr::Base>(x));
}
inline Expr
log(const Expr& x) {
  return GiNaC::log(static_cast<const Expr::Base>(x));
}
inline Expr
factorial(const Expr& x) {
  return GiNaC::factorial(static_cast<const Expr::Base>(x));
}
inline Expr
binom(const Expr& n, const Expr& k) {
  return binom(static_cast<const Expr::Base>(n),
        static_cast<const Expr::Base>(k));
}
inline Expr
gamma(const Expr& x) {
  return GiNaC::tgamma(static_cast<const Expr::Base>(x));
}
inline Expr
quo(const Expr& a, const Expr& b, const Symbol& x) {
  assert(a.is_polynomial(x.s));
  assert(b.is_polynomial(x.s));
  return GiNaC::quo(a, b, x.s);
}
inline Expr
rem(const Expr& a, const Expr& b, const Symbol& x) {
  assert(a.is_polynomial(x.s));
  assert(b.is_polynomial(x.s));
  return GiNaC::rem(a, b, x.s);
}
inline Expr
prem(const Expr& a, const Expr& b, const Symbol& x) {
  assert(a.is_polynomial(x.s));
  assert(b.is_polynomial(x.s));
  return GiNaC::prem(a, b, x.s);
}
inline Expr
gcd(const Expr& a, const Expr& b) {
  assert(a.is_multivariate_polynomial());
  assert(b.is_multivariate_polynomial());
  return GiNaC::gcd(a, b);
}
inline Expr
lcm(const Expr& a, const Expr& b) {
  assert(a.is_multivariate_polynomial());
  assert(b.is_multivariate_polynomial());
  return GiNaC::lcm(a, b);
}
inline Expr
lsolve(const Expr_List& x, const Expr_List& y) {
  return GiNaC::lsolve(x.l, y.l);
}
inline Expr
x(const Expr& y) {
  Number num;
  if (y.is_a_number(num))
    assert(num.is_nonnegative_integer());
  return x(static_cast<const Expr::Base>(y));
}
inline Expr
floor(const Expr& x) {
  return floor(static_cast<const Expr::Base>(x));
}
inline Expr
Sc(const Expr& x, const Expr& y) {
  return Sc(static_cast<const Expr::Base>(x),
     static_cast<const Expr::Base>(y));
}
inline Expr
mod(const Expr& x, const Expr& y) {
  return mod(static_cast<const Expr::Base>(x),
      static_cast<const Expr::Base>(y));
}
inline Expr
sum(const Expr& index, const Expr& lower, const Expr& upper,
    const Expr& summand) {
  return sum(static_cast<const Expr::Base>(index),
      static_cast<const Expr::Base>(lower),
      static_cast<const Expr::Base>(upper),
      static_cast<const Expr::Base>(summand));
}
inline Expr
prod(const Expr& index, const Expr& lower, const Expr& upper,
     const Expr& factor) {
  return prod(static_cast<const Expr::Base>(index),
       static_cast<const Expr::Base>(lower),
       static_cast<const Expr::Base>(upper),
       static_cast<const Expr::Base>(factor));
}
inline Expr
max(const Expr& x, const Expr& y) {
  return max(static_cast<const Expr::Base>(x),
      static_cast<const Expr::Base>(y));
}
inline Expr
min(const Expr& x, const Expr& y) {
  return min(static_cast<const Expr::Base>(x),
      static_cast<const Expr::Base>(y));
}
inline bool
Expr::is_the_abs_function() const {
  using namespace GiNaC;
  return is_ex_the_function(*this, abs);
}
inline bool
Expr::is_the_exp_function() const {
  using namespace GiNaC;
  return is_ex_the_function(*this, exp);
}
inline bool
Expr::is_the_log_function() const {
  using namespace GiNaC;
  return is_ex_the_function(*this, log);
}
inline bool
Expr::is_the_sin_function() const {
  using namespace GiNaC;
  return is_ex_the_function(*this, sin);
}
inline bool
Expr::is_the_cos_function() const {
  using namespace GiNaC;
  return is_ex_the_function(*this, cos);
}
inline bool
Expr::is_the_tan_function() const {
  using namespace GiNaC;
  return is_ex_the_function(*this, tan);
}
inline bool
Expr::is_the_acos_function() const {
  using namespace GiNaC;
  return is_ex_the_function(*this, acos);
}
inline bool
Expr::is_the_factorial_function() const {
  using namespace GiNaC;
  return is_ex_the_function(*this, factorial);
}
inline bool
Expr::is_the_gamma_function() const {
  using namespace GiNaC;
  return is_ex_the_function(*this, tgamma);
}
inline bool
Expr::is_the_binom_function() const {
  using namespace GiNaC;
  return is_ex_the_function(*this, binom);
}
inline bool
Expr::is_the_x_function() const {
  using namespace GiNaC;
  return is_ex_the_function(*this, x);
}
inline bool
Expr::is_the_x1_function() const {
  using namespace GiNaC;
  return is_ex_the_function(*this, x) && ((*this).nops() == 1);
}
inline bool
Expr::is_the_x2_function() const {
  using namespace GiNaC;
  return is_ex_the_function(*this, x) && ((*this).nops() == 2);
}
inline bool
Expr::is_the_floor_function() const {
  using namespace GiNaC;
  return is_ex_the_function(*this, floor);
}
inline bool
Expr::is_the_Sc_function() const {
  using namespace GiNaC;
  return is_ex_the_function(*this, Sc);
}
inline bool
Expr::is_the_mod_function() const {
  using namespace GiNaC;
  return is_ex_the_function(*this, mod);
}
inline bool
Expr::is_the_sum_function() const {
  using namespace GiNaC;
  return is_ex_the_function(*this, sum);
}
inline bool
Expr::is_the_prod_function() const {
  using namespace GiNaC;
  return is_ex_the_function(*this, prod);
}
inline bool
Expr::is_the_max_function() const {
  using namespace GiNaC;
  return is_ex_the_function(*this, max);
}
inline void
Expr::latex_print(std::ostream& s) {
  print(GiNaC::print_latex(s));
}
}
namespace Parma_Recurrence_Relation_Solver {
inline
Expr_List::Expr_List() {
}
inline
Expr_List::Expr_List(const Symbol& x)
  : l({x.s}) {
}
inline
Expr_List::Expr_List(const Expr& e)
  : l({static_cast<const GiNaC::ex>(e)}) {
}
inline
Expr_List::Expr_List(const Expr& e1, const Expr& e2)
  : l({static_cast<const GiNaC::ex>(e1), static_cast<const GiNaC::ex>(e2)}) {
};
inline
Expr_List::Expr_List(const Expr& e1, const Expr& e2, const Expr& e3,
       const Expr& e4, const Expr& e5)
  : l({static_cast<const GiNaC::ex>(e1),
      static_cast<const GiNaC::ex>(e2),
      static_cast<const GiNaC::ex>(e3),
      static_cast<const GiNaC::ex>(e4),
      static_cast<const GiNaC::ex>(e5)}) {
};
inline
Expr_List::Expr_List(const Expr& e1, const Expr& e2, const Expr& e3,
       const Expr& e4, const Expr& e5, const Expr& e6)
  : l({static_cast<const GiNaC::ex>(e1),
      static_cast<const GiNaC::ex>(e2),
      static_cast<const GiNaC::ex>(e3),
      static_cast<const GiNaC::ex>(e4),
      static_cast<const GiNaC::ex>(e5),
      static_cast<const GiNaC::ex>(e6)}) {
};
inline
Expr_List::Expr_List(const Expr_List& x)
  : l(x.l) {
};
inline Expr_List&
Expr_List::operator=(const Expr_List& x) {
  l = x.l;
  return *this;
};
inline
Expr_List::Expr_List(const GiNaC::lst& gl)
  : l(gl) {
}
inline
Expr_List::~Expr_List() {
}
inline unsigned
Expr_List::nops() const {
  return l.nops();
}
inline Expr
Expr_List::op(unsigned i) const {
  return l.op(i);
}
inline Expr_List&
Expr_List::append(const Expr& x) {
  l.append(static_cast<const GiNaC::ex>(x));
  return *this;
}
inline Expr_List&
Expr_List::prepend(const Expr& x) {
  l.prepend(static_cast<const GiNaC::ex>(x));
  return *this;
}
inline Expr_List&
Expr_List::remove_first() {
  l.remove_first();
  return *this;
}
}
namespace Parma_Recurrence_Relation_Solver {
Bool3 lor(Bool3 a, Bool3 b);
Bool3 land(Bool3 a, Bool3 b);
Bool3 lnot(Bool3 a);
Bool3 operator&&(Bool3 a, Bool3 b);
Bool3 operator||(Bool3 a, Bool3 b);
Bool3 operator!(Bool3 a);
bool is_strong(Bool3 a);
bool stronger(Bool3 a, Bool3 b);
bool stronger_eq(Bool3 a, Bool3 b);
std::ostream& operator<<(std::ostream& s, Bool3 a);
}
namespace Parma_Recurrence_Relation_Solver {
inline Bool3
lor(Bool3 a, Bool3 b) {
  return
    (a == ALWAYS || b == ALWAYS) ? ALWAYS
    : (a == NEVER && b == NEVER) ? NEVER
    : MAYBE;
}
inline Bool3
operator||(Bool3 a, Bool3 b) {
  return lor(a, b);
}
inline Bool3
land(Bool3 a, Bool3 b) {
  return
    (a == NEVER || b == NEVER) ? NEVER
    : (a == ALWAYS && b == ALWAYS) ? ALWAYS
    : MAYBE;
}
inline Bool3
operator&&(Bool3 a, Bool3 b) {
  return land(a, b);
}
inline Bool3
lnot(Bool3 a) {
  return
    a == NEVER ? ALWAYS
    : a == ALWAYS ? NEVER
    : MAYBE;
}
inline Bool3
operator!(Bool3 a) {
  return lnot(a);
}
inline bool
is_strong(Bool3 a) {
  return a == ALWAYS || a == NEVER;
}
inline bool
stronger(Bool3 a, Bool3 b) {
  return b == MAYBE && (a == ALWAYS || a == NEVER);
}
inline bool
stronger_eq(Bool3 a, Bool3 b) {
  return a == b || (b == MAYBE && (a == ALWAYS || a == NEVER));
}
}
namespace Parma_Recurrence_Relation_Solver {
class Blackboard {
public:
  Blackboard();
  Blackboard(const Blackboard& y);
  ~Blackboard();
  Blackboard& operator=(const Blackboard& y);
  Symbol insert_definition(const Expr& e);
  Expr get_definition(const Symbol& z) const;
  Symbol find_symbol(const Expr& e);
  void substitute(const Symbol& system_generated_symbol,
    const Symbol& new_symbol);
  Expr rewrite(const Expr& e) const;
  unsigned int size_norm(const Expr& e) const;
  unsigned int size_norm(const Symbol& s) const;
  void dump(std::ostream& s) const;
private:
  template <typename T>
  class Cached {
  public:
    Cached();
    unsigned long timestamp;
    T value;
  };
  class Definition {
  public:
    explicit Definition(const Expr& e);
    Expr rhs;
    Cached<unsigned int> size;
    Cached<Expr> expansion;
  };
  Expr rewrite(Definition& d) const;
  unsigned int size_norm(Definition& d) const;
  std::map<Symbol, unsigned int, Symbol::NameCompare> index;
  mutable std::deque<Definition> definitions;
  mutable unsigned long timestamp;
};
}
namespace Parma_Recurrence_Relation_Solver {
template <typename T>
inline
Blackboard::Cached<T>::Cached()
  : timestamp(0) {
}
inline
Blackboard::Definition::Definition(const Expr& e)
  : rhs(e) {
}
inline
Blackboard::Blackboard()
  : timestamp(1) {
}
inline
Blackboard::Blackboard(const Blackboard& y)
  : index(y.index), definitions(y.definitions), timestamp(y.timestamp) {
}
inline
Blackboard::~Blackboard() {
}
inline Blackboard&
Blackboard::operator=(const Blackboard& y) {
  index = y.index;
  definitions = y.definitions;
  timestamp = y.timestamp;
  return *this;
}
inline Symbol
Blackboard::insert_definition(const Expr& e) {
  Symbol new_symbol;
  index.insert(std::map<Symbol, unsigned int>::value_type(new_symbol,
         definitions.size()));
  definitions.push_back(Definition(e));
  ++timestamp;
  return new_symbol;
}
inline Expr
Blackboard::get_definition(const Symbol& z) const {
  std::map<Symbol, unsigned int>::const_iterator i = index.find(z);
  if (i != index.end())
    return definitions[i->second].rhs;
  else
    return z;
}
inline Symbol
Blackboard::find_symbol(const Expr& e) {
  std::map<Symbol, unsigned int>::const_iterator j = index.begin();
  for (std::deque<Definition>::const_iterator i = definitions.begin(),
  definitions_end = definitions.end(); i != definitions_end; ++i, ++j) {
    if ((*i).rhs == e)
      return j->first;
  }
  return insert_definition(e);
}
inline void
Blackboard::substitute(const Symbol& system_generated_symbol,
         const Symbol& new_symbol) {
  std::map<Symbol, unsigned int>::const_iterator i
    = index.find(system_generated_symbol);
  if (i != index.end()) {
    index.insert(std::map<Symbol, unsigned int>::value_type(new_symbol,
           definitions.size()));
    definitions.push_back(Definition(definitions[i->second].rhs));
    ++timestamp;
    index.erase(system_generated_symbol);
  }
}
}
namespace Parma_Recurrence_Relation_Solver {
class Matrix {
public:
  Matrix();
  Matrix(unsigned int i, unsigned int j);
  Matrix(unsigned int i, unsigned int j, const Expr_List& y);
  Matrix(const Matrix& y);
  ~Matrix();
  Matrix& operator=(const Matrix& y);
  unsigned int num_rows() const;
  unsigned int num_columns() const;
  const Expr& operator()(unsigned int r, unsigned int c) const;
  Expr& operator()(unsigned int r, unsigned int c);
  Expr determinant() const;
  Matrix solve(const Matrix& vars, const Matrix& rhs) const;
private:
  friend class Expr;
  GiNaC::matrix m;
  Matrix(const GiNaC::matrix& gm);
};
}
namespace Parma_Recurrence_Relation_Solver {
inline
Matrix::Matrix() {
}
inline
Matrix::Matrix(unsigned int i, unsigned int j)
  : m(i, j) {
};
inline
Matrix::Matrix(unsigned int i, unsigned int j, const Expr_List& y)
  : m(i, j, y.l) {
};
inline
Matrix::Matrix(const Matrix& y)
  : m(y.m) {
};
inline Matrix&
Matrix::operator=(const Matrix& y) {
  m = y.m;
  return *this;
};
inline
Matrix::Matrix(const GiNaC::matrix& gm)
  : m(gm) {
}
inline
Matrix::~Matrix() {
}
inline unsigned int
Matrix::num_rows() const {
  return m.rows();
};
inline unsigned int
Matrix::num_columns() const {
  return m.cols();
};
inline const Expr&
Matrix::operator()(unsigned int r, unsigned int c) const {
  return static_cast<const Expr&>(m(r, c));
};
inline Expr&
Matrix::operator()(unsigned int r, unsigned int c) {
  return static_cast<Expr&>(m(r, c));
};
inline Expr
Matrix::determinant() const {
  return m.determinant();
}
inline Matrix
Matrix::solve(const Matrix& vars, const Matrix& rhs) const {
  return m.solve(vars.m, rhs.m, GiNaC::solve_algo::gauss);
}
}
class Parma_Recurrence_Relation_Solver::Init {
private:
  static unsigned int count;
public:
  Init();
  ~Init();
};
namespace Parma_Recurrence_Relation_Solver {
inline
Init::Init() {
  if (count++ == 0) {
  }
}
inline
Init::~Init() {
  if (--count == 0)
    ;
}
}
static
Parma_Recurrence_Relation_Solver::Init
Parma_Recurrence_Relation_Solver_initializer;
namespace Parma_Recurrence_Relation_Solver {
unsigned int
size_norm(const Expr& e);
unsigned int
size_norm(const Matrix& m);
}
namespace Parma_Recurrence_Relation_Solver {
template <typename SymbolHandler>
inline unsigned int
generic_size_norm(const Expr& e, const SymbolHandler& sh) {
  int count = 1;
  if (e.is_a_add() || e.is_a_mul())
    for (unsigned int i = e.nops(); i-- > 0; )
      count += generic_size_norm(e.op(i), sh);
  else if (e.is_a_power())
    count += generic_size_norm(e.arg(0), sh) + generic_size_norm(e.arg(1), sh);
  else if (e.is_a_function())
    for (unsigned int i = e.nops(); i-- > 0; )
      count += generic_size_norm(e.arg(i), sh);
  else if (e.is_a_symbol())
    count = sh.size_norm(e.ex_to_symbol());
  return count;
}
}
namespace Parma_Recurrence_Relation_Solver {
enum Number_Type {
  RATIONAL,
  NON_RATIONAL
};
class Polynomial_Root {
private:
  Expr value_;
  Number_Type type_;
  unsigned int multiplicity_;
public:
  Polynomial_Root(const Expr& e, Number_Type t, unsigned int m = 1)
    : value_(e), type_(t), multiplicity_(m) {
  }
  const Expr& value() const {
    return value_;
  }
  Expr& value() {
    return value_;
  }
  unsigned int multiplicity() const {
    return multiplicity_;
  }
  void set_multiplicity(unsigned int m) {
    multiplicity_ = m;
  }
  Number_Type type() const {
    return type_;
  }
  bool is_rational() const {
    return type() == RATIONAL;
  }
  bool is_non_rational() const {
    return type() == NON_RATIONAL;
  }
  void set_type(Number_Type t) {
    type_ = t;
  }
};
std::ostream& operator<<(std::ostream& s, const Polynomial_Root& r);
bool
find_roots(const Expr& p, const Symbol& x,
    std::vector<Polynomial_Root>& roots, bool& all_distinct);
}
namespace Parma_Recurrence_Relation_Solver {
int
poly_factor(const Expr& p, const Symbol& x, std::vector<Expr>& factors);
}
namespace Parma_Recurrence_Relation_Solver {
bool
gosper_algorithm(const Symbol& m, const Expr& t_n,
   const Number& lower, const Expr& upper, Expr& solution);
}
namespace Parma_Recurrence_Relation_Solver {
enum Sum_Simplification_Kind {
  REWRITE_UPPER_LIMIT,
  COMPUTE_SUM
};
Expr
simplify_ex_for_input(const Expr& e, bool input);
Expr
simplify_ex_for_output(const Expr& e, bool input);
Expr
simplify_numer_denom(const Expr& e);
Expr
simplify_binomials_factorials_exponentials(const Expr& e);
Expr
simplify_sum(const Expr& e, const Sum_Simplification_Kind simplification);
Expr
simplify_collect_sums(const Expr& e);
Expr
simplify_logarithm(const Expr& e);
Expr
simplify_all(const Expr& e);
}
namespace Parma_Recurrence_Relation_Solver {
void
factorize_no_ratio_ex(const Expr& e,
        Expr& common_factor, Expr& remainder);
void
factorize(const Expr& e, Expr& common_factor, Expr& remainder);
}
namespace Parma_Recurrence_Relation_Solver {
Expr
compute_product(const Symbol& index, const Number& lower, const Expr& e);
}
namespace Parma_Recurrence_Relation_Solver {
void
exp_poly_decomposition(const Expr& e, const Symbol& x,
         std::vector<Expr>& alpha,
         std::vector<Expr>& p,
         std::vector<Expr>& q);
}
namespace Parma_Recurrence_Relation_Solver {
void factorial_decomposition(const Expr& e, const Symbol& x,
        std::vector<Number>& arg,
        std::vector<Expr>& coeff);
}
namespace Parma_Recurrence_Relation_Solver {
Expr
sum_poly_times_exponentials(const Expr& p, const Symbol& x,
       const Symbol& N, const Expr& alpha);
Expr
sum_poly_times_exponentials_times_cos(const Expr& p, const Symbol& x,
          const Symbol& N, const Expr& alpha,
          const Expr& theta);
Expr
sum_poly_times_exponentials_times_sin(const Expr& p, const Symbol& x,
          const Symbol& N, const Expr& alpha,
          const Expr& theta);
Expr
sum_poly_alt(const Expr& p, const Symbol& x, const Symbol& N);
}
namespace Parma_Recurrence_Relation_Solver {
bool
characteristic_equation_and_its_roots(index_type order,
          const std::vector<Expr>& coefficients,
          std::vector<Number>& num_coefficients,
          Expr& characteristic_eq,
          std::vector<Polynomial_Root>& roots,
          bool& all_distinct);
void
compute_symbolic_sum(const Symbol& alpha, const Symbol& lambda,
       const std::vector<Polynomial_Root>& roots,
       const std::vector<Expr>& base_of_exps,
       const std::vector<Expr>& exp_poly_coeff,
       unsigned lower_bound_sum,
       std::vector<Expr>& symbolic_sum_distinct,
       std::vector<Expr>& symbolic_sum_no_distinct);
Expr
subs_to_sum_roots_and_bases(const Symbol& alpha, const Symbol& lambda,
       const std::vector<Polynomial_Root>& roots,
       const std::vector<Expr>& base_of_exps,
       std::vector<Expr>& symbolic_sum_distinct,
       std::vector<Expr>& symbolic_sum_no_distinct);
Matrix
solve_system(bool all_distinct,
      const std::vector<Number>& coefficients,
      const std::vector<Polynomial_Root>& roots);
Expr
find_g_n(bool all_distinct, const Matrix& sol,
  const std::vector<Polynomial_Root>& roots);
void
prepare_for_symbolic_sum(const Expr& g_n,
    const std::vector<Polynomial_Root>& roots,
    const std::vector<Expr>& exp_poly_coeff,
    std::vector<Expr>& poly_coeff_tot);
Expr
compute_non_homogeneous_part(const Expr& g_n, index_type order,
        const std::vector<Expr>& base_of_exps,
        const std::vector<Expr>& exp_poly_coeff);
Expr
compute_sum_with_transcendental_method(const Number& lower, const Expr& upper,
           const std::vector<Expr>& base_of_exps,
           const std::vector<Expr>&
           exp_no_poly_coeff,
           const std::vector<Polynomial_Root>&
           roots);
Expr
write_reduced_order_recurrence(const Expr& e, const Symbol& r,
          unsigned gcd_among_decrements,
          const std::vector<Expr>& coefficients,
          std::vector<Expr>& new_coefficients,
          Expr& inhomogeneous);
Expr
come_back_to_original_variable(const Expr& e, const Symbol& r, const Expr& m,
          unsigned gcd_among_decrements);
void
substitute_non_rational_roots(const Recurrence& rec,
         std::vector<Polynomial_Root>& roots);
}
namespace Parma_Recurrence_Relation_Solver {
bool
is_non_negative_non_decreasing(const Number& base, const Expr& coefficient,
          bool poly, const Symbol& x, bool first_time,
          Number& condition);
}
namespace Parma_Recurrence_Relation_Solver {
bool
vector_not_all_zero(const std::vector<Expr>& v);
int
gcd(int n, int m);
Expr
general_gcd(const Expr& p, const Expr& q, const Symbol& x);
Number
lcm(const std::vector<Number>& v);
void
partial_factor(const Number& n,
        std::vector<Number>& bases, std::vector<int>& exponents);
bool
find_divisors(Number n, std::vector<Number>& divisors);
void
split_bases_exponents(const Expr& e,
        std::vector<Expr>& bases, std::vector<Expr>& exponents);
Expr
cubic_root(const Expr& e);
void
isolate_polynomial_part(const Expr& p, const Symbol& var,
   Expr& poly, Expr& no_poly);
Expr
convert_to_integer_polynomial(const Expr& p, const Symbol& x);
Expr
convert_to_integer_polynomial(const Expr& p, const Symbol& x,
         Expr& factor);
Expr
sylvester_matrix_resultant(const Expr& p, const Expr& q, const Symbol& x);
Expr
resultant(const Expr& p, const Expr& q, const Symbol& x);
bool
find_domain_in_N(const Expr& e, const Symbol& x, Number& z);
bool
has_parameters(const Expr& e);
enum Mode_Subs {
  EXPONENT,
  ARGUMENT_LOG,
};
Expr
substitute_x_function(const Expr& e, const Expr& k,
        const Mode_Subs mode_subs_x);
bool has_only_symbolic_initial_conditions(const Expr& e);
bool has_at_least_a_symbolic_initial_condition(const Expr& e);
}
namespace Parma_Recurrence_Relation_Solver {
class Cached_Expr {
public:
  Cached_Expr();
  Cached_Expr(const Cached_Expr& y);
  ~Cached_Expr();
  Cached_Expr& operator=(const Cached_Expr& y);
  bool has_expression() const;
  const Expr& expression() const;
  void set_expression(const Expr& e);
  void unset_expression();
  Expr replace_system_generated_symbols(const Recurrence& rec) const;
  void set_size(unsigned long n);
  unsigned long size();
  bool has_size() const;
private:
  bool has_expression_;
  Expr expression_;
  bool has_size_;
  unsigned long size_;
};
}
namespace Parma_Recurrence_Relation_Solver {
inline
Cached_Expr::Cached_Expr()
  : has_expression_(false),
    expression_(),
    has_size_(false),
    size_(0) {
}
inline
Cached_Expr::Cached_Expr(const Cached_Expr& y)
  : has_expression_(y.has_expression_),
    expression_(y.expression_),
    has_size_(y.has_size_),
    size_(y.size_) {
}
inline
Cached_Expr::~Cached_Expr() {
}
inline Cached_Expr&
Cached_Expr::operator=(const Cached_Expr& y) {
  has_expression_ = y.has_expression_;
  expression_ = y.expression_;
  has_size_ = y.has_size_;
  size_ = y.size_;
  return *this;
}
inline bool
Cached_Expr::has_expression() const {
  return has_expression_;
}
inline const Expr&
Cached_Expr::expression() const {
  return expression_;
}
inline void
Cached_Expr::set_expression(const Expr& e) {
  expression_ = e;
  has_expression_ = true;
}
inline void
Cached_Expr::unset_expression() {
  expression_ = 0;
  has_expression_ = false;
}
}
namespace Parma_Recurrence_Relation_Solver {
typedef unsigned int index_type;
bool less_than(const Recurrence& x, const Recurrence& y);
class Recurrence {
public:
  Recurrence();
  explicit Recurrence(const Expr& e);
  Recurrence(const Recurrence& y);
  ~Recurrence();
  Recurrence& operator=(const Recurrence& y);
  void approximate_union_assign(const Recurrence& y);
  void approximate_intersection_assign(const Recurrence& y);
  void replace_recurrence(const Expr& e);
  void replace_recurrence(unsigned int k, const Expr& e);
  Symbol insert_auxiliary_definition(const Expr& e) const;
  Expr substitute_auxiliary_definitions(const Expr& e) const;
  unsigned int number_initial_conditions() const;
  index_type first_valid_initial_condition() const;
  index_type first_valid_index_for_solution() const;
  std::string definition_Sc() const;
  void
  set_initial_conditions(const std::map<index_type, Expr>& initial_conditions);
  void reset_initial_conditions();
  const std::map<index_type, Expr>& get_initial_conditions() const;
  Expr evaluate_exact_solution(const Number& x) const;
  template <class OutputIterator>
  void
  evaluate_exact_solution(const Number& begin, const Number& end,
     OutputIterator oi) const;
  Expr evaluate_lower_bound(const Number& x) const;
  template <class OutputIterator>
  void
  evaluate_lower_bound(const Number& begin, const Number& end,
         OutputIterator oi) const;
  Expr evaluate_upper_bound(const Number& x) const;
  template <class OutputIterator>
  void
  evaluate_upper_bound(const Number& begin, const Number& end,
         OutputIterator oi) const;
  Expr evaluate_rhs(const Number& x) const;
  template <class OutputIterator>
  void
  evaluate_rhs(const Number& begin, const Number& end,
        OutputIterator oi) const;
  bool OK() const;
private:
  enum Bound {
    UPPER,
    LOWER
  };
  Expr get_auxiliary_definition(const Symbol& z) const;
  void set_inhomogeneous_term(const Expr& e) const;
  Expr get_initial_condition(unsigned int k) const;
  unsigned int get_max_index_initial_condition() const;
  Expr evaluate(unsigned int kind, const Number& num) const;
  void check_number_for_evaluation(const char* method, const char* name,
       const Number& num) const;
  void
  throw_invalid_argument(const char* method, const char* reason) const;
public:
  enum Solver_Status {
    SUCCESS,
    INDETERMINATE_RECURRENCE,
    UNSOLVABLE_RECURRENCE,
    MALFORMED_RECURRENCE,
    DOMAIN_ERROR,
    TOO_COMPLEX
  };
  enum Verify_Status {
    PROVABLY_CORRECT,
    PARTIAL_PROVABLY_CORRECT,
    PROVABLY_INCORRECT,
    INCONCLUSIVE_VERIFICATION
  };
  Solver_Status compute_exact_solution() const;
  void exact_solution(Expr& e) const;
  Solver_Status compute_lower_bound() const;
  void lower_bound(Expr& e) const;
  Solver_Status compute_upper_bound() const;
  void upper_bound(Expr& e) const;
  Verify_Status verify_exact_solution(bool partial_verification = false) const;
  Verify_Status verify_lower_bound() const;
  Verify_Status verify_upper_bound() const;
  static const Symbol& n;
  void dump(std::ostream& s) const;
public:
  enum Classifier_Status {
    CL_SUCCESS,
    CL_INDETERMINATE_RECURRENCE,
    CL_UNSOLVABLE_RECURRENCE,
    CL_MALFORMED_RECURRENCE,
    CL_DOMAIN_ERROR,
    CL_HAS_NON_INTEGER_DECREMENT,
    CL_HAS_HUGE_DECREMENT,
    CL_TOO_COMPLEX,
    CL_HAS_NEGATIVE_DECREMENT,
    CL_HAS_NULL_DECREMENT,
    NOT_CLASSIFIED_YET
  };
  mutable Classifier_Status classifier_status_;
private:
  static Solver_Status map_status(Classifier_Status classifier_status);
public:
  Classifier_Status classify_and_catch_special_cases() const;
private:
  Classifier_Status classification_summand(const Expr& r, Expr& rhs,
        Expr& e, index_type& order,
        std::vector<Expr>& coefficients,
        int& gcd_among_decrements,
        int num_term,
        std::map<Number, Expr>&
        homogeneous_terms) const;
  Solver_Status compute_exact_solution_finite_order() const;
  Solver_Status compute_exact_solution_functional_equation() const;
  Solver_Status compute_exact_solution_non_linear() const;
  Solver_Status compute_exact_solution_weighted_average() const;
  Solver_Status compute_exact_solution_max() const;
  Solver_Status
  compute_bound_functional_equation(Bound kind_of_bound) const;
  Solver_Status
  compute_bound_non_linear(Bound kind_of_bound) const;
  Solver_Status apply_order_reduction() const;
  Solver_Status compute_non_linear_recurrence(Expr& solution_or_bound,
           unsigned int type) const;
  Solver_Status compute_weighted_average_recurrence(Expr& solution) const;
  Expr
  compute_solution_linear_finite_order_on_i_c(const Expr& solution) const;
  Expr
  compute_solution_non_linear_finite_order_on_i_c(const Expr& solution) const;
  Expr
  compute_bound_functional_equation_on_i_c(const Expr& bound) const;
  Expr
  compute_solution_weighted_average_on_i_c(const Expr& solution) const;
  Expr compute_solution_or_bound_on_i_c(const Expr& solution_or_bound) const;
  Classifier_Status classify() const;
  Solver_Status solve_linear_finite_order() const;
  Expr solve_constant_coeff_order_1(const std::vector<Polynomial_Root>&
        roots) const;
  Solver_Status
  solve_variable_coeff_order_1(const std::vector<Expr>& coefficients,
          Expr& solution) const;
  Expr solve_constant_coeff_order_2(Expr& g_n, bool all_distinct,
        const std::vector<Number>& coefficients,
        const std::vector<Polynomial_Root>&
        roots) const;
  Expr solve_constant_coeff_order_k(Expr& g_n, bool all_distinct,
        const std::vector<Number>& coefficients,
        const std::vector<Polynomial_Root>&
        roots) const;
  Verify_Status
  validate_initial_conditions(bool symbolic_solution, index_type order,
         const std::vector<Expr>& coefficients_i_c,
         const Expr& summands_with_i_c,
         const Expr& summands_without_i_c) const;
  Verify_Status
  traditional_step_3(index_type order_rec,
       const Expr& summands_with_i_c) const;
  bool verify_new_method_const_coeff(index_type order_rec, const Expr& e,
         const std::vector<Polynomial_Root> roots,
         bool inhomogeneous_part) const;
  bool verify_new_method_var_coeff(index_type order_rec,
       const Expr& summands_without_i_c) const;
  Verify_Status verify_finite_order(bool partial_verification) const;
  Verify_Status verify_weighted_average() const;
  Verify_Status validate_initial_conditions(Bound kind_of_bound,
         const Expr& bound,
         unsigned int index) const;
  Verify_Status verify_bound(Bound kind_of_bound) const;
  Solver_Status approximate_functional_equation(Bound kind_of_bound) const;
  Expr recurrence_rhs;
  bool recurrence_rewritten;
  mutable Expr inhomogeneous_term;
  std::map<unsigned int, Expr> system_rhs;
public:
  enum Type {
    ORDER_ZERO,
    LINEAR_FINITE_ORDER_CONST_COEFF,
    LINEAR_FINITE_ORDER_VAR_COEFF,
    NON_LINEAR_FINITE_ORDER,
    WEIGHTED_AVERAGE,
    FUNCTIONAL_EQUATION,
    MAX_FUNCTION,
    UNKNOWN
  };
  mutable Type type_;
private:
  mutable Finite_Order_Info* finite_order_p;
  mutable Functional_Equation_Info* functional_eq_p;
  mutable Non_Linear_Info* non_linear_p;
  mutable Weighted_Average_Info* weighted_average_p;
  const Type& type() const;
  Type& type();
  void set_type(const Type& t) const;
  void set_order_zero() const;
  bool is_linear_finite_order_const_coeff() const;
  void set_linear_finite_order_const_coeff() const;
  bool is_linear_finite_order_var_coeff() const;
  void set_linear_finite_order_var_coeff() const;
  bool is_linear_finite_order() const;
  bool is_non_linear_finite_order() const;
  void set_non_linear_finite_order() const;
  bool is_functional_equation() const;
  void set_functional_equation() const;
  bool is_weighted_average() const;
  void set_weighted_average() const;
  index_type order() const;
  const std::vector<Expr>& coefficients() const;
  std::vector<Expr>& coefficients();
public:
  unsigned int gcd_among_decrements() const;
private:
  const Expr& product_factor() const;
  Expr& product_factor();
  void set_product_factor(const Expr& x) const;
  bool applied_order_reduction() const;
  void set_order_reduction() const;
  void unset_order_reduction() const;
  index_type applicability_condition() const;
  void set_applicability_condition(index_type c) const;
  index_type rank() const;
  void set_definition_Sc() const;
  const Recurrence& associated_linear_rec() const;
  Recurrence& associated_linear_rec();
  const Number& coeff_simple_non_linear_rec() const;
  Number& coeff_simple_non_linear_rec();
  const Expr& base_exp_log() const;
  Expr& base_exp_log();
  const std::vector<Symbol>& auxiliary_symbols() const;
  std::vector<Symbol>& auxiliary_symbols();
  const Recurrence& associated_first_order_rec() const;
  Recurrence& associated_first_order_rec();
  const Expr& weight() const;
  Expr& weight();
  const Expr& original_weight() const;
  Expr& original_weight();
  const Expr& original_inhomogeneous() const;
  Expr& original_inhomogeneous();
  unsigned int lower_limit() const;
  void set_original_rhs(const Expr& weight, const Expr& inhomogeneous,
   unsigned int lower, const Expr& upper) const;
  mutable index_type first_valid_index;
  mutable index_type first_valid_index_for_solution_;
  void set_first_valid_index(index_type i) const;
  void set_first_valid_index_for_solution() const;
  mutable Cached_Expr exact_solution_;
  mutable Cached_Expr lower_bound_;
  mutable Cached_Expr upper_bound_;
  mutable Cached_Expr evaluated_exact_solution_;
  mutable Cached_Expr evaluated_lower_bound_;
  mutable Cached_Expr evaluated_upper_bound_;
  mutable bool tried_to_compute_exact_solution;
  mutable Blackboard blackboard;
  std::map<index_type, Expr> initial_conditions_;
private:
  static Classifier_Status
  compute_order(const Number& decrement, index_type& order,
  unsigned long& index, unsigned long max_size);
  static Expr
  write_expanded_solution(const Recurrence& rec,
     unsigned int gcd_among_decrements);
  friend Expr Cached_Expr::
  replace_system_generated_symbols(const Recurrence& rec) const;
};
}
namespace Parma_Recurrence_Relation_Solver {
class Finite_Order_Info {
public:
  Finite_Order_Info(index_type k, const std::vector<Expr>& coeffs,
      unsigned int gcd);
  Finite_Order_Info(const Finite_Order_Info& y);
  ~Finite_Order_Info();
  Finite_Order_Info& operator=(const Finite_Order_Info& y);
  index_type order() const;
  const std::vector<Expr>& coefficients() const;
  std::vector<Expr>& coefficients();
  unsigned int gcd_among_decrements() const;
  const Expr& product_factor() const;
  Expr& product_factor();
  void set_product_factor(const Expr& x);
  bool applied_order_reduction() const;
  void set_order_reduction();
  void unset_order_reduction();
private:
  index_type order_;
  std::vector<Expr> coefficients_;
  unsigned int gcd_among_decrements_;
  Expr product_factor_;
  bool applied_order_reduction_;
};
}
namespace Parma_Recurrence_Relation_Solver {
inline
Finite_Order_Info::Finite_Order_Info(index_type k,
         const std::vector<Expr>& coeffs,
         unsigned int gcd)
  : order_(k),
    coefficients_(coeffs),
    gcd_among_decrements_(gcd),
    product_factor_(0),
    applied_order_reduction_(false) {
}
inline
Finite_Order_Info::Finite_Order_Info(const Finite_Order_Info& y)
  : order_(y.order_),
    coefficients_(y.coefficients_),
    gcd_among_decrements_(y.gcd_among_decrements_),
    product_factor_(y.product_factor_),
    applied_order_reduction_(y.applied_order_reduction_) {
}
inline
Finite_Order_Info::~Finite_Order_Info() {
}
inline Finite_Order_Info&
Finite_Order_Info::operator=(const Finite_Order_Info& y) {
  order_ = y.order_;
  coefficients_ = y.coefficients_;
  gcd_among_decrements_ = y.gcd_among_decrements_;
  product_factor_ = y.product_factor_;
  applied_order_reduction_ = y.applied_order_reduction_;
  return *this;
}
inline index_type
Finite_Order_Info::order() const {
  return order_;
}
inline const std::vector<Expr>&
Finite_Order_Info::coefficients() const {
  return coefficients_;
}
inline std::vector<Expr>&
Finite_Order_Info::coefficients() {
  return coefficients_;
}
inline unsigned int
Finite_Order_Info::gcd_among_decrements() const {
  return gcd_among_decrements_;
}
inline const Expr&
Finite_Order_Info::product_factor() const {
  return product_factor_;
}
inline Expr&
Finite_Order_Info::product_factor() {
  return product_factor_;
}
inline void
Finite_Order_Info::set_product_factor(const Expr& x) {
  product_factor_ = x;
}
inline bool
Finite_Order_Info::applied_order_reduction() const {
  return applied_order_reduction_;
}
inline void
Finite_Order_Info::set_order_reduction() {
  applied_order_reduction_ = true;
}
inline void
Finite_Order_Info::unset_order_reduction() {
  applied_order_reduction_ = false;
}
}
namespace Parma_Recurrence_Relation_Solver {
class Functional_Equation_Info {
public:
  Functional_Equation_Info(const std::map<Number, Expr>& hom_terms);
  Functional_Equation_Info(const Functional_Equation_Info& y);
  ~Functional_Equation_Info();
  Functional_Equation_Info& operator=(const Functional_Equation_Info& y);
  index_type applicability_condition() const;
  void set_applicability_condition(index_type c);
private:
  typedef std::map<Number, Expr> Homogeneous_Terms;
public:
  typedef Homogeneous_Terms::iterator ht_iterator;
  typedef Homogeneous_Terms::const_iterator ht_const_iterator;
  ht_iterator ht_begin();
  ht_iterator ht_end();
  ht_const_iterator ht_begin() const;
  ht_const_iterator ht_end() const;
  index_type rank() const;
  std::string definition_Sc() const;
  void set_definition_Sc();
private:
  std::map<Number, Expr> homogeneous_terms;
  index_type applicability_condition_;
  std::string definition_Sc_;
public:
  void dump_homogeneous_terms(std::ostream& s) const;
};
}
namespace Parma_Recurrence_Relation_Solver {
inline
Functional_Equation_Info::
Functional_Equation_Info(const std::map<Number, Expr>& hom_terms)
  : homogeneous_terms(hom_terms),
    applicability_condition_(1),
    definition_Sc_() {
}
inline
Functional_Equation_Info::
Functional_Equation_Info(const Functional_Equation_Info& y)
  : homogeneous_terms(y.homogeneous_terms),
    applicability_condition_(y.applicability_condition_),
    definition_Sc_(y.definition_Sc_) {
}
inline
Functional_Equation_Info::~Functional_Equation_Info() {
}
inline Functional_Equation_Info&
Functional_Equation_Info::operator=(const Functional_Equation_Info& y) {
  homogeneous_terms = y.homogeneous_terms;
  applicability_condition_ = y.applicability_condition_;
  definition_Sc_ = y.definition_Sc_;
  return *this;
}
inline index_type
Functional_Equation_Info::applicability_condition() const {
  return applicability_condition_;
}
inline void
Functional_Equation_Info::set_applicability_condition(index_type c) {
  applicability_condition_ = c;
}
inline Functional_Equation_Info::ht_iterator
Functional_Equation_Info::ht_begin() {
  return homogeneous_terms.begin();
}
inline Functional_Equation_Info::ht_iterator
Functional_Equation_Info::ht_end() {
  return homogeneous_terms.end();
}
inline Functional_Equation_Info::ht_const_iterator
Functional_Equation_Info::ht_begin() const {
  return homogeneous_terms.begin();
}
inline Functional_Equation_Info::ht_const_iterator
Functional_Equation_Info::ht_end() const {
  return homogeneous_terms.end();
}
inline index_type
Functional_Equation_Info::rank() const {
  return homogeneous_terms.size();
}
inline std::string
Functional_Equation_Info::definition_Sc() const {
  return definition_Sc_;
}
inline void
Functional_Equation_Info::set_definition_Sc() {
  assert(!homogeneous_terms.empty());
  assert(homogeneous_terms.size() == 1);
  const Number& divisor = ht_begin()->first;
  std::ostringstream s;
  if (divisor != 2)
    s << "Sc(n, " << divisor
      << ") = floor(n/" << divisor <<"^floor(log(n)/log(" << divisor << ")))";
  definition_Sc_ = s.str();
}
}
namespace Parma_Recurrence_Relation_Solver {
class Non_Linear_Info {
public:
  Non_Linear_Info(const Recurrence& associated_linear_rec,
    const std::pair<Number, Expr>& coeff_and_base,
    const std::vector<Symbol> auxiliary_symbols);
  Non_Linear_Info(const Non_Linear_Info& y);
  ~Non_Linear_Info();
  Non_Linear_Info& operator=(const Non_Linear_Info& y);
  const Recurrence& associated_linear_rec() const;
  Recurrence& associated_linear_rec();
  const Number& coeff_simple_non_linear_rec() const;
  Number& coeff_simple_non_linear_rec();
  const Expr& base_exp_log() const;
  Expr& base_exp_log();
  const std::vector<Symbol>& auxiliary_symbols() const;
  std::vector<Symbol>& auxiliary_symbols();
private:
  Recurrence associated_linear_rec_;
  std::pair<Number, Expr> coeff_and_base_;
  std::vector<Symbol> auxiliary_symbols_;
};
}
namespace Parma_Recurrence_Relation_Solver {
inline
Non_Linear_Info::Non_Linear_Info(const Recurrence& associated_linear_rec,
     const std::pair<Number, Expr>& coeff_and_base,
     const std::vector<Symbol> auxiliary_symbols)
  : associated_linear_rec_(associated_linear_rec),
    coeff_and_base_(coeff_and_base),
    auxiliary_symbols_(auxiliary_symbols) {
}
inline
Non_Linear_Info::Non_Linear_Info(const Non_Linear_Info& y)
  : associated_linear_rec_(y.associated_linear_rec_),
    coeff_and_base_(y.coeff_and_base_),
    auxiliary_symbols_(y.auxiliary_symbols_) {
}
inline
Non_Linear_Info::~Non_Linear_Info() {
}
inline Non_Linear_Info&
Non_Linear_Info::operator=(const Non_Linear_Info& y) {
  associated_linear_rec_ = y.associated_linear_rec_;
  coeff_and_base_ = y.coeff_and_base_;
  auxiliary_symbols_ = y.auxiliary_symbols_;
  return *this;
}
inline const Recurrence&
Non_Linear_Info::associated_linear_rec() const {
  return associated_linear_rec_;
}
inline Recurrence&
Non_Linear_Info::associated_linear_rec() {
  return associated_linear_rec_;
}
inline const Number&
Non_Linear_Info::coeff_simple_non_linear_rec() const {
  return coeff_and_base_.first;
}
inline Number&
Non_Linear_Info::coeff_simple_non_linear_rec() {
  return coeff_and_base_.first;
}
inline const Expr&
Non_Linear_Info::base_exp_log() const {
  return coeff_and_base_.second;
}
inline Expr&
Non_Linear_Info::base_exp_log() {
  return coeff_and_base_.second;
}
inline const std::vector<Symbol>&
Non_Linear_Info::auxiliary_symbols() const {
  return auxiliary_symbols_;
}
inline std::vector<Symbol>&
Non_Linear_Info::auxiliary_symbols() {
  return auxiliary_symbols_;
}
}
namespace Parma_Recurrence_Relation_Solver {
struct Components_Original_Rec {
  Expr weight_;
  Expr inhomogeneous_;
  unsigned int lower_limit_;
  Expr upper_limit_;
};
class Weighted_Average_Info {
public:
  Weighted_Average_Info(const Recurrence& associated_first_order_rec,
   const Expr& weight);
  Weighted_Average_Info(const Weighted_Average_Info& y);
  ~Weighted_Average_Info();
  Weighted_Average_Info& operator=(const Weighted_Average_Info& y);
  const Recurrence& associated_first_order_rec() const;
  Recurrence& associated_first_order_rec();
  const Expr& weight() const;
  Expr& weight();
  const Expr& original_weight() const;
  Expr& original_weight();
  const Expr& original_inhomogeneous() const;
  Expr& original_inhomogeneous();
  unsigned int lower_limit() const;
  void set_original_rhs(const Expr& weight, const Expr& inhomogeneous,
   unsigned int lower, const Expr& upper);
private:
  Recurrence associated_first_order_rec_;
  Expr weight_;
  Components_Original_Rec* components_original_rec_p;
};
}
namespace Parma_Recurrence_Relation_Solver {
inline Weighted_Average_Info::
Weighted_Average_Info(const Recurrence& associated_first_order_rec,
        const Expr& weight)
  : associated_first_order_rec_(associated_first_order_rec),
    weight_(weight),
    components_original_rec_p(0) {
}
inline
Weighted_Average_Info::Weighted_Average_Info(const Weighted_Average_Info& y)
  : associated_first_order_rec_(y.associated_first_order_rec_),
    weight_(y.weight_),
    components_original_rec_p(y.components_original_rec_p) {
}
inline
Weighted_Average_Info::~Weighted_Average_Info() {
  delete components_original_rec_p;
}
inline Weighted_Average_Info&
Weighted_Average_Info::operator=(const Weighted_Average_Info& y) {
  associated_first_order_rec_ = y.associated_first_order_rec_;
  weight_ = y.weight_;
  components_original_rec_p = y.components_original_rec_p;
  return *this;
}
inline const Recurrence&
Weighted_Average_Info::associated_first_order_rec() const {
  return associated_first_order_rec_;
}
inline Recurrence&
Weighted_Average_Info::associated_first_order_rec() {
  return associated_first_order_rec_;
}
inline const Expr&
Weighted_Average_Info::weight() const {
  return weight_;
}
inline Expr&
Weighted_Average_Info::weight() {
  return weight_;
}
inline const Expr&
Weighted_Average_Info::original_weight() const {
  assert(components_original_rec_p);
  return components_original_rec_p->weight_;
}
inline Expr&
Weighted_Average_Info::original_weight() {
  assert(components_original_rec_p);
  return components_original_rec_p->weight_;
}
inline const Expr&
Weighted_Average_Info::original_inhomogeneous() const {
  assert(components_original_rec_p);
  return components_original_rec_p->inhomogeneous_;
}
inline Expr&
Weighted_Average_Info::original_inhomogeneous() {
  assert(components_original_rec_p);
  return components_original_rec_p->inhomogeneous_;
}
inline unsigned int
Weighted_Average_Info::lower_limit() const {
  assert(components_original_rec_p);
  return components_original_rec_p->lower_limit_;
}
inline void
Weighted_Average_Info::set_original_rhs(const Expr& weight,
     const Expr& inhomogeneous,
     unsigned int lower,
     const Expr& upper) {
  components_original_rec_p = new Components_Original_Rec;
  components_original_rec_p->weight_ = weight;
  components_original_rec_p->inhomogeneous_ = inhomogeneous;
  components_original_rec_p->lower_limit_ = lower;
  components_original_rec_p->upper_limit_ = upper;
}
}
namespace Parma_Recurrence_Relation_Solver {
inline
Recurrence::Recurrence()
  : classifier_status_(CL_SUCCESS),
    recurrence_rhs(0),
    recurrence_rewritten(false),
    inhomogeneous_term(0),
    type_(ORDER_ZERO),
    finite_order_p(0),
    functional_eq_p(0),
    non_linear_p(0),
    weighted_average_p(0),
    first_valid_index(0),
    first_valid_index_for_solution_(0),
    tried_to_compute_exact_solution(false) {
}
inline
Recurrence::Recurrence(const Expr& e)
  : classifier_status_(NOT_CLASSIFIED_YET),
    recurrence_rhs(e),
    recurrence_rewritten(false),
    inhomogeneous_term(0),
    type_(UNKNOWN),
    finite_order_p(0),
    functional_eq_p(0),
    non_linear_p(0),
    weighted_average_p(0),
    first_valid_index(0),
    first_valid_index_for_solution_(0),
    tried_to_compute_exact_solution(false) {
}
inline
Recurrence::Recurrence(const Recurrence& y)
  : classifier_status_(y.classifier_status_),
    recurrence_rhs(y.recurrence_rhs),
    recurrence_rewritten(y.recurrence_rewritten),
    inhomogeneous_term(y.inhomogeneous_term),
    system_rhs(y.system_rhs),
    type_(y.type_),
    finite_order_p(y.finite_order_p),
    functional_eq_p(y.functional_eq_p),
    non_linear_p(y.non_linear_p),
    weighted_average_p(y.weighted_average_p),
    first_valid_index(y.first_valid_index),
    first_valid_index_for_solution_(y.first_valid_index_for_solution_),
    exact_solution_(y.exact_solution_),
    lower_bound_(y.lower_bound_),
    upper_bound_(y.upper_bound_),
    tried_to_compute_exact_solution(y.tried_to_compute_exact_solution),
    blackboard(y.blackboard),
    initial_conditions_(y.initial_conditions_) {
}
inline Recurrence&
Recurrence::operator=(const Recurrence& y) {
  classifier_status_ = y.classifier_status_;
  recurrence_rhs = y.recurrence_rhs;
  recurrence_rewritten = y.recurrence_rewritten;
  inhomogeneous_term = y.inhomogeneous_term;
  system_rhs = y.system_rhs;
  type_ = y.type_;
  finite_order_p = y.finite_order_p;
  functional_eq_p = y.functional_eq_p;
  non_linear_p = y.non_linear_p;
  weighted_average_p = y.weighted_average_p;
  first_valid_index = y.first_valid_index;
  first_valid_index_for_solution_ = y.first_valid_index_for_solution_;
  exact_solution_ = y.exact_solution_;
  lower_bound_ = y.lower_bound_;
  upper_bound_ = y.upper_bound_;
  tried_to_compute_exact_solution = y.tried_to_compute_exact_solution;
  blackboard = y.blackboard;
  initial_conditions_ = y.initial_conditions_;
  return *this;
}
inline
Recurrence::~Recurrence() {
  delete finite_order_p;
  delete functional_eq_p;
  delete non_linear_p;
  delete weighted_average_p;
}
inline void
Recurrence::replace_recurrence(const Expr& e) {
  recurrence_rhs = e;
  classifier_status_ = NOT_CLASSIFIED_YET;
}
inline void
Recurrence::replace_recurrence(unsigned int k, const Expr& e) {
  std::pair<std::map<unsigned int, Expr>::iterator, bool> stat
    = system_rhs.insert(std::map<unsigned int, Expr>::value_type(k, e));
  if (!stat.second)
    stat.first->second = e;
}
inline index_type
Recurrence::first_valid_index_for_solution() const {
  if (!exact_solution_.has_expression()
      && !lower_bound_.has_expression() && !upper_bound_.has_expression())
    throw
      std::logic_error("PURRS::Recurrence::first_valid_index_for_solution() "
         "called, but no exact solution, no lower bound "
         "and no upper bound were computed");
  return first_valid_index_for_solution_;
}
inline void
Recurrence::reset_initial_conditions() {
  initial_conditions_.clear();
  evaluated_exact_solution_.unset_expression();
  evaluated_lower_bound_.unset_expression();
  evaluated_upper_bound_.unset_expression();
}
inline const std::map<index_type, Expr>&
Recurrence::get_initial_conditions() const {
  return initial_conditions_;
}
inline Expr
Recurrence::get_initial_condition(unsigned int k) const {
  std::map<index_type, Expr>::const_iterator i = initial_conditions_.find(k);
  if (i != initial_conditions_.end())
    return (*i).second;
  else
    return x(k);
}
inline unsigned int
Recurrence::get_max_index_initial_condition() const {
  unsigned int max_index;
  if (initial_conditions_.empty())
    max_index = 0;
  else
    max_index = initial_conditions_.rbegin()->first;
  return max_index;
}
inline Expr
Recurrence::evaluate_exact_solution(const Number& x) const {
  return evaluate(0, x);
}
template <class OutputIterator>
void
Recurrence::evaluate_exact_solution(const Number& begin, const Number& end,
        OutputIterator oi) const {
  if (begin > end)
    throw_invalid_argument("PURRS::Recurrence::evaluate_exact_solution()",
      "the numbers represent an interval and the first\n"
      "must be smaller or equal to the second");
  for (Number i = begin; i < end; ++i) {
    *oi = evaluate(0, i);
    ++oi;
  }
}
inline Expr
Recurrence::evaluate_lower_bound(const Number& x) const {
  return evaluate(1, x);
}
template <class OutputIterator>
void
Recurrence::evaluate_lower_bound(const Number& begin, const Number& end,
     OutputIterator oi) const {
  if (begin > end)
    throw_invalid_argument("PURRS::Recurrence::evaluate_lower_bound()",
      "the numbers represent an interval and the first\n"
      "must be smaller or equal to the second");
  for (Number i = begin; i < end; ++i) {
    *oi = evaluate(1, i);
    ++oi;
  }
}
inline Expr
Recurrence::evaluate_upper_bound(const Number& x) const {
  return evaluate(2, x);
}
template <class OutputIterator>
void
Recurrence::evaluate_upper_bound(const Number& begin, const Number& end,
     OutputIterator oi) const {
  if (begin > end)
    throw_invalid_argument("PURRS::Recurrence::evaluate_upper_bound()",
      "the numbers represent an interval and the first\n"
      "must be smaller or equal to the second");
  for (Number i = begin; i < end; ++i) {
    *oi = evaluate(2, i);
    ++oi;
  }
}
inline void
Recurrence::set_inhomogeneous_term(const Expr& e) const {
  inhomogeneous_term = e;
}
inline const Recurrence::Type&
Recurrence::type() const {
  assert(classifier_status_ != NOT_CLASSIFIED_YET);
  return type_;
}
inline Recurrence::Type&
Recurrence::type() {
  assert(classifier_status_ != NOT_CLASSIFIED_YET);
  return type_;
}
inline void
Recurrence::set_type(const Type& t) const {
  type_ = t;
  classifier_status_ = CL_SUCCESS;
}
inline void
Recurrence::set_order_zero() const {
  type_ = ORDER_ZERO;
  classifier_status_ = CL_SUCCESS;
}
inline bool
Recurrence::is_linear_finite_order_const_coeff() const {
  assert(classifier_status_ != NOT_CLASSIFIED_YET);
  return type_ == LINEAR_FINITE_ORDER_CONST_COEFF;
}
inline void
Recurrence::set_linear_finite_order_const_coeff() const {
  type_ = LINEAR_FINITE_ORDER_CONST_COEFF;
  classifier_status_ = CL_SUCCESS;
}
inline bool
Recurrence::is_linear_finite_order_var_coeff() const {
  assert(classifier_status_ != NOT_CLASSIFIED_YET);
  return type_ == LINEAR_FINITE_ORDER_VAR_COEFF;
}
inline void
Recurrence::set_linear_finite_order_var_coeff() const {
  type_ = LINEAR_FINITE_ORDER_VAR_COEFF;
  classifier_status_ = CL_SUCCESS;
}
inline bool
Recurrence::is_linear_finite_order() const {
  assert(classifier_status_ != NOT_CLASSIFIED_YET);
  return (type_ == ORDER_ZERO
   || type_ == LINEAR_FINITE_ORDER_CONST_COEFF
   || type_ == LINEAR_FINITE_ORDER_VAR_COEFF);
}
inline bool
Recurrence::is_non_linear_finite_order() const {
  assert(classifier_status_ != NOT_CLASSIFIED_YET);
  return type_ == NON_LINEAR_FINITE_ORDER;
}
inline void
Recurrence::set_non_linear_finite_order() const {
  type_ = NON_LINEAR_FINITE_ORDER;
  classifier_status_ = CL_SUCCESS;
}
inline bool
Recurrence::is_functional_equation() const {
  assert(classifier_status_ != NOT_CLASSIFIED_YET);
  return type_ == FUNCTIONAL_EQUATION;
}
inline void
Recurrence::set_functional_equation() const {
  type_ = FUNCTIONAL_EQUATION;
  classifier_status_ = CL_SUCCESS;
}
inline bool
Recurrence::is_weighted_average() const {
  assert(classifier_status_ != NOT_CLASSIFIED_YET);
  return type_ == WEIGHTED_AVERAGE;
}
inline void
Recurrence::set_weighted_average() const {
  type_ = WEIGHTED_AVERAGE;
  classifier_status_ = CL_SUCCESS;
}
inline index_type
Recurrence::order() const {
  assert(is_linear_finite_order());
  assert(finite_order_p);
  return finite_order_p->order();
}
inline const std::vector<Expr>&
Recurrence::coefficients() const {
  assert(is_linear_finite_order());
  assert(finite_order_p);
  return finite_order_p->coefficients();
}
inline std::vector<Expr>&
Recurrence::coefficients() {
  assert(is_linear_finite_order());
  assert(finite_order_p);
  return finite_order_p->coefficients();
}
inline unsigned int
Recurrence::gcd_among_decrements() const {
  assert(is_linear_finite_order());
  assert(finite_order_p);
  return finite_order_p->gcd_among_decrements();
}
inline const Expr&
Recurrence::product_factor() const {
  assert(is_linear_finite_order_var_coeff());
  assert(finite_order_p);
  return finite_order_p->product_factor();
}
inline Expr&
Recurrence::product_factor() {
  assert(is_linear_finite_order_var_coeff());
  assert(finite_order_p);
  return finite_order_p->product_factor();
}
inline void
Recurrence::set_product_factor(const Expr& x) const {
  assert(is_linear_finite_order_var_coeff());
  assert(finite_order_p);
  return finite_order_p->set_product_factor(x);
}
inline bool
Recurrence::applied_order_reduction() const {
  assert(is_linear_finite_order());
  assert(finite_order_p);
  return finite_order_p->applied_order_reduction();
}
inline void
Recurrence::set_order_reduction() const {
  assert(is_linear_finite_order());
  assert(finite_order_p);
  return finite_order_p->set_order_reduction();
}
inline void
Recurrence::unset_order_reduction() const {
  assert(is_linear_finite_order());
  assert(finite_order_p);
  return finite_order_p->unset_order_reduction();
}
inline index_type
Recurrence::applicability_condition() const {
  assert(is_functional_equation());
  assert(functional_eq_p);
  return functional_eq_p->applicability_condition();
}
inline void
Recurrence::set_applicability_condition(index_type c) const {
  assert(is_functional_equation());
  assert(functional_eq_p);
  return functional_eq_p->set_applicability_condition(c);
}
inline index_type
Recurrence::rank() const {
  assert(is_functional_equation());
  assert(functional_eq_p);
  return functional_eq_p->rank();
}
inline std::string
Recurrence::definition_Sc() const {
  if (!lower_bound_.has_expression() && !upper_bound_.has_expression())
    throw std::logic_error("PURRS::Recurrence::definition_Sc() called, "
      "but no lower bound and no upper bound were "
      "computed");
  assert(is_functional_equation());
  assert(functional_eq_p);
  return functional_eq_p->definition_Sc();
}
inline void
Recurrence::set_definition_Sc() const {
  assert(is_functional_equation()
  || (is_non_linear_finite_order()
      && associated_linear_rec().is_functional_equation()));
  if (is_functional_equation()) {
    assert(functional_eq_p);
    functional_eq_p->set_definition_Sc();
  }
  else {
    assert(is_non_linear_finite_order()
    && associated_linear_rec().is_functional_equation());
    assert(associated_linear_rec().functional_eq_p);
    associated_linear_rec().functional_eq_p->set_definition_Sc();
  }
}
inline const Recurrence&
Recurrence::associated_linear_rec() const {
  assert(is_non_linear_finite_order());
  assert(non_linear_p);
  return non_linear_p->associated_linear_rec();
}
inline Recurrence&
Recurrence::associated_linear_rec() {
  assert(is_non_linear_finite_order());
  assert(non_linear_p);
  return non_linear_p->associated_linear_rec();
}
inline const Number&
Recurrence::coeff_simple_non_linear_rec() const {
  assert(is_non_linear_finite_order());
  assert(non_linear_p);
  return non_linear_p->coeff_simple_non_linear_rec();
}
inline Number&
Recurrence::coeff_simple_non_linear_rec() {
  assert(is_non_linear_finite_order());
  assert(non_linear_p);
  return non_linear_p->coeff_simple_non_linear_rec();
}
inline const Expr&
Recurrence::base_exp_log() const {
  assert(is_non_linear_finite_order());
  assert(non_linear_p);
  return non_linear_p->base_exp_log();
}
inline Expr&
Recurrence::base_exp_log() {
  assert(is_non_linear_finite_order());
  assert(non_linear_p);
  return non_linear_p->base_exp_log();
}
inline const std::vector<Symbol>&
Recurrence::auxiliary_symbols() const {
  assert(is_non_linear_finite_order());
  assert(non_linear_p);
  return non_linear_p->auxiliary_symbols();
}
inline std::vector<Symbol>&
Recurrence::auxiliary_symbols() {
  assert(is_non_linear_finite_order());
  assert(non_linear_p);
  return non_linear_p->auxiliary_symbols();
}
inline const Recurrence&
Recurrence::associated_first_order_rec() const {
  assert(is_weighted_average());
  return weighted_average_p->associated_first_order_rec();
}
inline Recurrence&
Recurrence::associated_first_order_rec() {
  assert(is_weighted_average());
  return weighted_average_p->associated_first_order_rec();
}
inline const Expr&
Recurrence::weight() const {
  assert(is_weighted_average());
  assert(weighted_average_p);
  return weighted_average_p->weight();
}
inline Expr&
Recurrence::weight() {
  assert(is_weighted_average());
  assert(weighted_average_p);
  return weighted_average_p->weight();
}
inline const Expr&
Recurrence::original_weight() const {
  assert(is_weighted_average());
  return weighted_average_p->original_weight();
}
inline Expr&
Recurrence::original_weight() {
  assert(is_weighted_average());
  return weighted_average_p->original_weight();
}
inline const Expr&
Recurrence::original_inhomogeneous() const {
  assert(is_weighted_average());
  return weighted_average_p->original_inhomogeneous();
}
inline Expr&
Recurrence::original_inhomogeneous() {
  assert(is_weighted_average());
  return weighted_average_p->original_inhomogeneous();
}
inline unsigned int
Recurrence::lower_limit() const {
  assert(is_weighted_average());
  assert(weighted_average_p);
  return weighted_average_p->lower_limit();
}
inline void
Recurrence::set_original_rhs(const Expr& weight, const Expr& inhomogeneous,
        unsigned int lower, const Expr& upper) const {
  assert(is_weighted_average());
  assert(weighted_average_p);
  weighted_average_p->set_original_rhs(weight, inhomogeneous, lower, upper);
}
inline void
Recurrence::set_first_valid_index(index_type i) const {
  first_valid_index = i;
}
inline Symbol
Recurrence::insert_auxiliary_definition(const Expr& e) const {
  return blackboard.insert_definition(e);
}
inline Expr
Recurrence::get_auxiliary_definition(const Symbol& z) const {
  return blackboard.get_definition(z);
}
inline Expr
Recurrence::substitute_auxiliary_definitions(const Expr& e) const {
  return blackboard.rewrite(e).expand();
}
}

#ifdef PURRS_SAVE_NDEBUG
#define NDEBUG 1
#undef PURRS_SAVE_NDEBUG
#endif

#undef PURRS_FLEXIBLE_ARRAY
#undef PACKAGE
#undef VERSION

#endif // !defined(PURRS_purrs_hh)
