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

class LoatConst;
class LoatExp;
class LoatAdd;
class LoatMult;
class LoatMod;
class LoatVar;

using LoatIntExprPtr = cpp::not_null<std::shared_ptr<const LoatIntExpr>>;
using LoatVarPtr = cpp::not_null<std::shared_ptr<const LoatVar>>;
using LoatConstPtr = cpp::not_null<std::shared_ptr<const LoatConst>>;
using LoatAddPtr = cpp::not_null<std::shared_ptr<const LoatAdd>>;
using LoatMultPtr = cpp::not_null<std::shared_ptr<const LoatMult>>;
using LoatModPtr = cpp::not_null<std::shared_ptr<const LoatMod>>;
using LoatExpPtr = cpp::not_null<std::shared_ptr<const LoatExp>>;
using LoatIntExprSet = linked_hash_set<LoatIntExprPtr>;
using LoatIntExprVec = std::vector<LoatIntExprPtr>;

using Int = boost::multiprecision::cpp_int;
using Rational = boost::multiprecision::cpp_rational;

using loat_var_map = boost::bimap<boost::bimaps::unordered_set_of<LoatVarPtr>, boost::bimaps::unordered_set_of<LoatVarPtr>>;

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
class LoatConst : public LoatIntExpr
{
    friend LoatIntExprPtr LoatIntExpression::mkConst(const Rational &r);
    friend LoatIntExprPtr LoatIntExpression::mkConst(const Rational &&r);
    friend class LoatIntExpr;

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
    static ConsHash<LoatIntExpr, LoatConst, CacheHash, CacheEqual, Rational> cache;
};

/**
 * Represents an addition expression.
 */
class LoatAdd : public LoatIntExpr
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
    static ConsHash<LoatIntExpr, LoatAdd, CacheHash, CacheEqual, LoatIntExprSet> cache;

public:
    LoatAdd(const LoatIntExprSet &args);
    ~LoatAdd();
};

/**
 * Represents a multiplication expression.
 */
class LoatMult : public LoatIntExpr
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

    static ConsHash<LoatIntExpr, LoatMult, CacheHash, CacheEqual, LoatIntExprSet> cache;

public:
    LoatMult(const LoatIntExprSet &args);
    ~LoatMult();
};

/**
 * Represents a modulo expression: (a mod b)
 */
class LoatMod : public LoatIntExpr
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

    static ConsHash<LoatIntExpr, LoatMod, CacheHash, CacheEqual, LoatIntExprPtr, LoatIntExprPtr> cache;

public:
    LoatMod(const LoatIntExprPtr lhs, const LoatIntExprPtr rhs);
    ~LoatMod();
};

/**
 * Represents an exponential expression: (a ^ b)
 */
class LoatExp : public LoatIntExpr
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

    static ConsHash<LoatIntExpr, LoatExp, CacheHash, CacheEqual, LoatIntExprPtr, LoatIntExprPtr> cache;

public:
    LoatExp(const LoatIntExprPtr base, const LoatIntExprPtr exponent);
    ~LoatExp();

    LoatIntExprPtr getBase() const;
    LoatIntExprPtr getExponent() const;
};

/**
 * Represents a Variable
 */
class LoatVar : public LoatIntExpr
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

    static ConsHash<LoatIntExpr, LoatVar, CacheHash, CacheEqual, std::string> cache;

public:
    explicit LoatVar(const std::string &name);
    ~LoatVar();

    std::string getName() const;
};

// Hash functions for expression pointers
std::size_t hash_value(const LoatIntExprPtr &);
std::size_t hash_value(const LoatVarPtr &);

// Stream output
std::ostream &operator<<(std::ostream &s, const LoatVarPtr x);
std::ostream &operator<<(std::ostream &s, const LoatIntExprPtr e);