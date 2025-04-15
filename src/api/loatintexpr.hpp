#pragma once

#include <optional>
#include <boost/multiprecision/cpp_int.hpp>
#include <functional>
#include <boost/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <string>

#include "linkedhashset.hpp"
#include "linkedhashmap.hpp"
#include "string.hpp"
#include "conshash.hpp"
#include "notnull.hpp"
#include "var.hpp"

class LoatIntExpr;

class LoatIntConst;
class LoatIntExp;
class LoatIntAdd;
class LoatIntMult;
class LoatIntMod;
class LoatIntVar;

using LoatIntExprPtr = cpp::not_null<std::shared_ptr<const LoatIntExpr>>;
using LoatIntVarPtr = cpp::not_null<std::shared_ptr<const LoatIntVar>>;
using LoatIntConstPtr = cpp::not_null<std::shared_ptr<const LoatIntConst>>;
using LoatIntAddPtr = cpp::not_null<std::shared_ptr<const LoatIntAdd>>;
using LoatIntMultPtr = cpp::not_null<std::shared_ptr<const LoatIntMult>>;
using LoatIntModPtr = cpp::not_null<std::shared_ptr<const LoatIntMod>>;
using LoatIntExpPtr = cpp::not_null<std::shared_ptr<const LoatIntExp>>;
using LoatIntExprSet = linked_hash_set<LoatIntExprPtr>;
using LoatIntExprVec = std::vector<LoatIntExprPtr>;

using Int = boost::multiprecision::cpp_int;
using Rational = boost::multiprecision::cpp_rational;

using loat_var_map = boost::bimap<boost::bimaps::unordered_set_of<LoatIntVarPtr>, boost::bimaps::unordered_set_of<LoatIntVarPtr>>;

namespace LoatIntExpression
{
    // Type of expression
    enum class Kind
    {
        Plus,
        Times,
        Mod,
        Exp,
        Constant,
        Variable
    };

    // Factory methods to create expressions
    LoatIntExprPtr mkPlus(LoatIntExprVec &&args);
    LoatIntExprPtr mkPlus(LoatIntExprPtr, LoatIntExprPtr);
    LoatIntExprPtr mkTimes(LoatIntExprVec &&args);
    LoatIntExprPtr mkTimes(const LoatIntExprPtr, const LoatIntExprPtr);
    LoatIntExprPtr mkMod(LoatIntExprPtr x, LoatIntExprPtr y);
    LoatIntExprPtr mkConst(const Rational &r);
    LoatIntExprPtr mkConst(const Rational &&r);
    LoatIntExprPtr mkExp(const LoatIntExprPtr base, const LoatIntExprPtr exponent);
    LoatIntExprPtr mkVar(const std::string &name);
}

/**
 * Base class for all expression types.
 */
class LoatIntExpr : public std::enable_shared_from_this<LoatIntExpr>
{
protected:
    // Constructs an expression with a specific kind.
    explicit LoatIntExpr(LoatIntExpression::Kind kind);
    LoatIntExpr();

private:
    LoatIntExpression::Kind m_kind;

public:
    // Returns the kind of the expression (Plus, Times, etc.)
    LoatIntExpression::Kind getKind() const;

    // Returns this expression as a pointer
    LoatIntExprPtr toPtr() const;

    // Divides this expression by a rational constant
    LoatIntExprPtr divide(const Rational &d) const;

    // Operator overloads for symbolic math
    friend LoatIntExprPtr operator^(const LoatIntExprPtr x, const LoatIntExprPtr y);
    friend LoatIntExprPtr operator-(const LoatIntExprPtr x);
    friend LoatIntExprPtr operator-(const LoatIntExprPtr x, const LoatIntExprPtr y);
    friend LoatIntExprPtr operator+(const LoatIntExprPtr x, const LoatIntExprPtr y);
    friend LoatIntExprPtr operator*(const LoatIntExprPtr x, const LoatIntExprPtr y);
};

/**
 * Represents a constant rational expression.
 */
class LoatIntConst : public LoatIntExpr
{
    friend LoatIntExprPtr LoatIntExpression::mkConst(const Rational &r);
    friend LoatIntExprPtr LoatIntExpression::mkConst(const Rational &&r);
    friend class LoatIntExpr;

public:
    LoatIntConst(const Rational &t);
    ~LoatIntConst();
    const Rational &operator*() const;
    const Rational &getValue() const;

private:
    Rational m_value;

    struct CacheEqual
    {
        bool operator()(const std::tuple<Rational> &args1, const std::tuple<Rational> &args2) const noexcept;
    };
    struct CacheHash
    {
        size_t operator()(const std::tuple<Rational> &args) const noexcept;
    };
    static ConsHash<LoatIntExpr, LoatIntConst, CacheHash, CacheEqual, Rational> cache;
};

/**
 * Represents an addition expression.
 */
class LoatIntAdd : public LoatIntExpr
{
    friend LoatIntExprPtr LoatIntExpression::mkPlus(LoatIntExprPtr, LoatIntExprPtr);
    friend LoatIntExprPtr LoatIntExpression::mkPlus(LoatIntExprVec &&args);
    friend class LoatIntExpr;

public:
    const LoatIntExprSet &getArgs() const;

private:
    LoatIntExprSet m_args;

    struct CacheEqual
    {
        bool operator()(const std::tuple<LoatIntExprSet> &args1, const std::tuple<LoatIntExprSet> &args2) const noexcept;
    };
    struct CacheHash
    {
        size_t operator()(const std::tuple<LoatIntExprSet> &args) const noexcept;
    };
    static ConsHash<LoatIntExpr, LoatIntAdd, CacheHash, CacheEqual, LoatIntExprSet> cache;

public:
    LoatIntAdd(const LoatIntExprSet &args);
    ~LoatIntAdd();
};

/**
 * Represents a multiplication expression.
 */
class LoatIntMult : public LoatIntExpr
{
    friend LoatIntExprPtr LoatIntExpression::mkTimes(LoatIntExprPtr, LoatIntExprPtr);
    friend LoatIntExprPtr LoatIntExpression::mkTimes(LoatIntExprVec &&args);
    friend class LoatIntExpr;

public:
    const LoatIntExprSet &getArgs() const;

private:
    LoatIntExprSet m_args;

    struct CacheEqual
    {
        bool operator()(const std::tuple<LoatIntExprSet> &args1, const std::tuple<LoatIntExprSet> &args2) const noexcept;
    };

    struct CacheHash
    {
        size_t operator()(const std::tuple<LoatIntExprSet> &args) const noexcept;
    };

    static ConsHash<LoatIntExpr, LoatIntMult, CacheHash, CacheEqual, LoatIntExprSet> cache;

public:
    LoatIntMult(const LoatIntExprSet &args);
    ~LoatIntMult();
};

/**
 * Represents a modulo expression: (a mod b)
 */
class LoatIntMod : public LoatIntExpr
{
    friend LoatIntExprPtr LoatIntExpression::mkMod(LoatIntExprPtr x, LoatIntExprPtr y);
    friend class LoatIntExpr;

public:
    const LoatIntExprPtr getLhs() const;
    const LoatIntExprPtr getRhs() const;

private:
    LoatIntExprPtr m_lhs;
    LoatIntExprPtr m_rhs;

    struct CacheEqual
    {
        bool operator()(const std::tuple<LoatIntExprPtr, LoatIntExprPtr> &a,
                        const std::tuple<LoatIntExprPtr, LoatIntExprPtr> &b) const noexcept;
    };

    struct CacheHash
    {
        size_t operator()(const std::tuple<LoatIntExprPtr, LoatIntExprPtr> &a) const noexcept;
    };

    static ConsHash<LoatIntExpr, LoatIntMod, CacheHash, CacheEqual, LoatIntExprPtr, LoatIntExprPtr> cache;

public:
    LoatIntMod(const LoatIntExprPtr lhs, const LoatIntExprPtr rhs);
    ~LoatIntMod();
};

/**
 * Represents an exponential expression: (a ^ b)
 */
class LoatIntExp : public LoatIntExpr
{
    friend LoatIntExprPtr LoatIntExpression::mkExp(const LoatIntExprPtr base, const LoatIntExprPtr exponent);
    friend class LoatIntExpr;

private:
    LoatIntExprPtr m_base;
    LoatIntExprPtr m_exponent;

    struct CacheEqual
    {
        bool operator()(const std::tuple<LoatIntExprPtr, LoatIntExprPtr> &a,
                        const std::tuple<LoatIntExprPtr, LoatIntExprPtr> &b) const noexcept;
    };

    struct CacheHash
    {
        size_t operator()(const std::tuple<LoatIntExprPtr, LoatIntExprPtr> &a) const noexcept;
    };

    static ConsHash<LoatIntExpr, LoatIntExp, CacheHash, CacheEqual, LoatIntExprPtr, LoatIntExprPtr> cache;

public:
    LoatIntExp(const LoatIntExprPtr base, const LoatIntExprPtr exponent);
    ~LoatIntExp();

    LoatIntExprPtr getBase() const;
    LoatIntExprPtr getExponent() const;
};

/**
 * Represents a Variable
 */
class LoatIntVar : public LoatIntExpr
{
    friend LoatIntExprPtr LoatIntExpression::mkVar(const std::string &name);
    friend class LoatIntExpr;

private:
    std::string m_name;

    struct CacheEqual
    {
        bool operator()(const std::tuple<std::string> &a, const std::tuple<std::string> &b) const noexcept;
    };

    struct CacheHash
    {
        size_t operator()(const std::tuple<std::string> &a) const noexcept;
    };

    static ConsHash<LoatIntExpr, LoatIntVar, CacheHash, CacheEqual, std::string> cache;

public:
    explicit LoatIntVar(const std::string &name);
    ~LoatIntVar();

    std::string getName() const;
};

// Hash functions for expression pointers
std::size_t hash_value(const LoatIntExprPtr &);
std::size_t hash_value(const LoatIntVarPtr &);

// Stream output
std::ostream &operator<<(std::ostream &s, const LoatIntVarPtr x);
std::ostream &operator<<(std::ostream &s, const LoatIntExprPtr e);