#pragma once

#ifndef EOF
#define EOF (-1)
#endif

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <memory>

namespace sexpresso {
struct Sexp;
}

template <class T, class... Args>
class ConsHash;

namespace cpp::inline bitwizeshift {
template <typename T>
class not_null;
}

template <class T> class linked_hash_set;
template <class S, class T> class linked_hash_map;

template <class T>
using ptr = cpp::not_null<std::shared_ptr<const T>>;

namespace theory {

    enum class Type {
        Int,
        Bool,
        IntArray,
    };
    std::string abbrev(Type t);
}

class ArithLit;
class ArithExpr;

using ArithLitPtr = ptr<ArithLit>;
using ArithExprPtr = ptr<ArithExpr>;

namespace mp = boost::multiprecision;
using Int = mp::cpp_int;
using Rational = mp::cpp_rational;

class BoolVar;
class BoolExpr;
class BoolSubs;
using BoolExprPtr = ptr<BoolExpr>;
using BoolVarPtr = ptr<BoolVar>;

template <class T>
class ArrayVar;

template <class T>
using ArrayVarPtr = ptr<ArrayVar<T>>;

template <class T>
using array_var_map = boost::bimap<boost::bimaps::unordered_set_of<ArrayVarPtr<T>>, boost::bimaps::unordered_set_of<ArrayVarPtr<T>>>;

template <class T>
class ArraySubs;

class Subs;
class Renaming;

class Model;
using ModelPtr = cpp::not_null<std::shared_ptr<Model>>;

struct Arith;

template <class>
class ArrayRead;

template <class T>
using ArrayReadPtr = ptr<ArrayRead<T>>;

using ArithVarPtr = ArrayReadPtr<Arith>;

template <class... T>
class VariantSet;
using VarSet = VariantSet<ArrayVarPtr<Arith>, BoolVarPtr>;

using CellSet = VariantSet<ArrayReadPtr<Arith>, BoolVarPtr>;
