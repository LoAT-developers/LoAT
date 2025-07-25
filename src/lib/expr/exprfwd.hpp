#pragma once

#ifndef EOF
#define EOF (-1)
#endif

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>

namespace sexpresso {
struct Sexp;
}

template <class Abstract, class Concrete, class Hash, class Eq, class... Args>
class ConsHash;

namespace cpp {
inline namespace bitwizeshift {
template <typename T>
class not_null;
}
} // namespace cpp

namespace std {
template <class T>
class shared_ptr;
}

template <class T> class linked_hash_set;
template <class S, class T> class linked_hash_map;

template <class T>
using ptr = cpp::not_null<std::shared_ptr<const T>>;

namespace theory {

    enum class Type {
        Int,
        Bool
    };
    std::string abbrev(const Type t);
}

class ArithLit;
class ArithExpr;
class ArithSubs;
class ArithVar;

using ArithLitPtr = ptr<ArithLit>;
using ArithExprPtr = ptr<ArithExpr>;
using ArithVarPtr = ptr<ArithVar>;

using arith_var_map = boost::bimap<boost::bimaps::unordered_set_of<ArithVarPtr>, boost::bimaps::unordered_set_of<ArithVarPtr>>;

namespace mp = boost::multiprecision;
using Int = mp::cpp_int;
using Rational = mp::cpp_rational;

class BoolExpr;
using BoolExprPtr = ptr<BoolExpr>;
