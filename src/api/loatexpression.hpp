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

class LoatExpr;

class LoatConst;
class LoatExp;
class LoatAdd;
class LoatMult;
class LoatMod;
class LoatVar;

using LoatExprPtr = cpp::not_null<std::shared_ptr<const LoatExpr>>;
using LoatVarPtr = cpp::not_null<std::shared_ptr<const LoatVar>>;
using LoatConstPtr = cpp::not_null<std::shared_ptr<const LoatConst>>;
using LoatAddPtr = cpp::not_null<std::shared_ptr<const LoatAdd>>;
using LoatMultPtr = cpp::not_null<std::shared_ptr<const LoatMult>>;
using LoatModPtr = cpp::not_null<std::shared_ptr<const LoatMod>>;
using LoatExpPtr = cpp::not_null<std::shared_ptr<const LoatExp>>;
using LoatExprSet = linked_hash_set<LoatExprPtr>;
using LoatExprVec = std::vector<LoatExprPtr>;

using Int = boost::multiprecision::cpp_int;
using Rational = boost::multiprecision::cpp_rational;

using loat_var_map = boost::bimap<boost::bimaps::unordered_set_of<LoatVarPtr>, boost::bimaps::unordered_set_of<LoatVarPtr>>;

namespace LoatExpression
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
    LoatExprPtr mkPlus(LoatExprVec &&args);
    LoatExprPtr mkPlus(LoatExprPtr, LoatExprPtr);
    LoatExprPtr mkTimes(LoatExprVec &&args);
    LoatExprPtr mkTimes(const LoatExprPtr, const LoatExprPtr);
    LoatExprPtr mkMod(LoatExprPtr x, LoatExprPtr y);
    LoatExprPtr mkConst(const Rational &r);
    LoatExprPtr mkConst(const Rational &&r);
    LoatExprPtr mkExp(const LoatExprPtr base, const LoatExprPtr exponent);
    LoatExprPtr mkVar(const std::string &name);
}

/**
 * Base class for all expression types.
 */
class LoatExpr : public std::enable_shared_from_this<LoatExpr>
{
protected:
    // Constructs an expression with a specific kind.
    explicit LoatExpr(LoatExpression::Kind kind);
    LoatExpr();

private:
    LoatExpression::Kind m_kind;

public:
    // Returns the kind of the expression (Plus, Times, etc.)
    LoatExpression::Kind getKind() const;

    // Returns this expression as a pointer
    LoatExprPtr toPtr() const;

    // Divides this expression by a rational constant
    LoatExprPtr divide(const Rational &d) const;

    // Operator overloads for symbolic math
    friend LoatExprPtr operator^(const LoatExprPtr x, const LoatExprPtr y);
    friend LoatExprPtr operator-(const LoatExprPtr x);
    friend LoatExprPtr operator-(const LoatExprPtr x, const LoatExprPtr y);
    friend LoatExprPtr operator+(const LoatExprPtr x, const LoatExprPtr y);
    friend LoatExprPtr operator*(const LoatExprPtr x, const LoatExprPtr y);
};

/**
 * Represents a constant rational expression.
 */
class LoatConst : public LoatExpr
{
    friend LoatExprPtr LoatExpression::mkConst(const Rational &r);
    friend LoatExprPtr LoatExpression::mkConst(const Rational &&r);
    friend class LoatExpr;

public:
    LoatConst(const Rational &t);
    ~LoatConst();
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
    static ConsHash<LoatExpr, LoatConst, CacheHash, CacheEqual, Rational> cache;
};

/**
 * Represents an addition expression.
 */
class LoatAdd : public LoatExpr
{
    friend LoatExprPtr LoatExpression::mkPlus(LoatExprPtr, LoatExprPtr);
    friend LoatExprPtr LoatExpression::mkPlus(LoatExprVec &&args);
    friend class LoatExpr;

public:
    const LoatExprSet &getArgs() const;

private:
    LoatExprSet m_args;

    struct CacheEqual
    {
        bool operator()(const std::tuple<LoatExprSet> &args1, const std::tuple<LoatExprSet> &args2) const noexcept;
    };
    struct CacheHash
    {
        size_t operator()(const std::tuple<LoatExprSet> &args) const noexcept;
    };
    static ConsHash<LoatExpr, LoatAdd, CacheHash, CacheEqual, LoatExprSet> cache;

public:
    LoatAdd(const LoatExprSet &args);
    ~LoatAdd();
};

/**
 * Represents a multiplication expression.
 */
class LoatMult : public LoatExpr
{
    friend LoatExprPtr LoatExpression::mkTimes(LoatExprPtr, LoatExprPtr);
    friend LoatExprPtr LoatExpression::mkTimes(LoatExprVec &&args);
    friend class LoatExpr;

public:
    const LoatExprSet &getArgs() const;

private:
    LoatExprSet m_args;

    struct CacheEqual
    {
        bool operator()(const std::tuple<LoatExprSet> &args1, const std::tuple<LoatExprSet> &args2) const noexcept;
    };

    struct CacheHash
    {
        size_t operator()(const std::tuple<LoatExprSet> &args) const noexcept;
    };

    static ConsHash<LoatExpr, LoatMult, CacheHash, CacheEqual, LoatExprSet> cache;

public:
    LoatMult(const LoatExprSet &args);
    ~LoatMult();
};

/**
 * Represents a modulo expression: (a mod b)
 */
class LoatMod : public LoatExpr
{
    friend LoatExprPtr LoatExpression::mkMod(LoatExprPtr x, LoatExprPtr y);
    friend class LoatExpr;

public:
    const LoatExprPtr getLhs() const;
    const LoatExprPtr getRhs() const;

private:
    LoatExprPtr m_lhs;
    LoatExprPtr m_rhs;

    struct CacheEqual
    {
        bool operator()(const std::tuple<LoatExprPtr, LoatExprPtr> &a,
                        const std::tuple<LoatExprPtr, LoatExprPtr> &b) const noexcept;
    };

    struct CacheHash
    {
        size_t operator()(const std::tuple<LoatExprPtr, LoatExprPtr> &a) const noexcept;
    };

    static ConsHash<LoatExpr, LoatMod, CacheHash, CacheEqual, LoatExprPtr, LoatExprPtr> cache;

public:
    LoatMod(const LoatExprPtr lhs, const LoatExprPtr rhs);
    ~LoatMod();
};

/**
 * Represents an exponential expression: (a ^ b)
 */
class LoatExp : public LoatExpr
{
    friend LoatExprPtr LoatExpression::mkExp(const LoatExprPtr base, const LoatExprPtr exponent);
    friend class LoatExpr;

private:
    LoatExprPtr m_base;
    LoatExprPtr m_exponent;

    struct CacheEqual
    {
        bool operator()(const std::tuple<LoatExprPtr, LoatExprPtr> &a,
                        const std::tuple<LoatExprPtr, LoatExprPtr> &b) const noexcept;
    };

    struct CacheHash
    {
        size_t operator()(const std::tuple<LoatExprPtr, LoatExprPtr> &a) const noexcept;
    };

    static ConsHash<LoatExpr, LoatExp, CacheHash, CacheEqual, LoatExprPtr, LoatExprPtr> cache;

public:
    LoatExp(const LoatExprPtr base, const LoatExprPtr exponent);
    ~LoatExp();

    LoatExprPtr getBase() const;
    LoatExprPtr getExponent() const;
};

/**
 * Represents an Variable
 */
class LoatVar : public LoatExpr
{
    friend LoatExprPtr LoatExpression::mkVar(const std::string &name);
    friend class LoatExpr;

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

    static ConsHash<LoatExpr, LoatVar, CacheHash, CacheEqual, std::string> cache;

public:
    explicit LoatVar(const std::string &name);
    ~LoatVar();

    std::string getName() const;
};

// Hash functions for expression pointers
std::size_t hash_value(const LoatExprPtr &);
std::size_t hash_value(const LoatVarPtr &);

// Stream output
std::ostream &operator<<(std::ostream &s, const LoatVarPtr x);
std::ostream &operator<<(std::ostream &s, const LoatExprPtr e);