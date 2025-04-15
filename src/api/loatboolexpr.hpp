#pragma once

#include <memory>
#include <string>
#include <vector>
#include <ostream>
#include "notnull.hpp"
#include "loatintexpr.hpp"
#include "linkedhashset.hpp"
#include "conshash.hpp"

class LoatBoolExpr;

using LoatBoolExprPtr = cpp::not_null<std::shared_ptr<const LoatBoolExpr>>;
using LoatBoolExprSet = linked_hash_set<LoatBoolExprPtr>;
using LoatBoolExprVec = std::vector<LoatBoolExprPtr>;

namespace LoatBoolExpression
{
    // Kind of expression
    enum class Kind
    {
        Variable,
        And,
        Or,
        Not,
        Compare
    };

    // Compare / Literals
    enum class CmpOp
    {
        Eq,
        Neq,
        Lt,
        Le,
        Gt,
        Ge
    };

    // Factory methods to create expressions
    LoatBoolExprPtr mkVar(const std::string &name);
    LoatBoolExprPtr mkAnd(const LoatBoolExprVec &&args);
    LoatBoolExprPtr mkOr(const LoatBoolExprVec &&args);
    LoatBoolExprPtr mkNot(const LoatBoolExprPtr arg);

    // Factory methods to create Literals
    LoatBoolExprPtr mkCmp(const LoatIntExprPtr lhs, CmpOp op, const LoatIntExprPtr rhs);
    LoatBoolExprPtr mkEq(const LoatIntExprPtr lhs, const LoatIntExprPtr rhs);
    LoatBoolExprPtr mkNeq(const LoatIntExprPtr lhs, const LoatIntExprPtr rhs);
    LoatBoolExprPtr mkLt(const LoatIntExprPtr lhs, const LoatIntExprPtr rhs);
    LoatBoolExprPtr mkLe(const LoatIntExprPtr lhs, const LoatIntExprPtr rhs);
    LoatBoolExprPtr mkGt(const LoatIntExprPtr lhs, const LoatIntExprPtr rhs);
    LoatBoolExprPtr mkGe(const LoatIntExprPtr lhs, const LoatIntExprPtr rhs);
}

/**
 * Base class for all expression types.
 */
class LoatBoolExpr : public std::enable_shared_from_this<LoatBoolExpr>
{
private:
    LoatBoolExpression::Kind m_kind;

protected:
    explicit LoatBoolExpr(LoatBoolExpression::Kind kind);
    virtual ~LoatBoolExpr() = default;

public:
    // Returns the kind of the expression
    LoatBoolExpression::Kind getKind() const;

    // Returns this expression as a pointer
    LoatBoolExprPtr toPtr() const;
};

/**
 * Represents a Variable
 */
class LoatBoolVar : public LoatBoolExpr
{
    friend LoatBoolExprPtr LoatBoolExpression::mkVar(const std::string &name);

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
    static ConsHash<LoatBoolExpr, LoatBoolVar, CacheHash, CacheEqual, std::string> cache;

public:
    explicit LoatBoolVar(const std::string &name);
    std::string getName() const;
};

/**
 * Represents a disconjunction (OR)
 */
class LoatBoolOr : public LoatBoolExpr
{
    friend LoatBoolExprPtr LoatBoolExpression::mkOr(const LoatBoolExprVec &&args);

private:
    LoatBoolExprVec m_args;

    struct CacheEqual
    {
        bool operator()(const std::tuple<LoatBoolExprVec> &a, const std::tuple<LoatBoolExprVec> &b) const noexcept;
    };
    struct CacheHash
    {
        size_t operator()(const std::tuple<LoatBoolExprVec> &a) const noexcept;
    };
    static ConsHash<LoatBoolExpr, LoatBoolOr, CacheHash, CacheEqual, LoatBoolExprVec> cache;

public:
    explicit LoatBoolOr(const LoatBoolExprVec &args);
    ~LoatBoolOr();
    const LoatBoolExprVec &getArgs() const;
};

/**
 * Represents a conjunction (AND)
 */
class LoatBoolAnd : public LoatBoolExpr
{
    friend LoatBoolExprPtr LoatBoolExpression::mkAnd(const LoatBoolExprVec &&args);

private:
    LoatBoolExprVec m_args;

    struct CacheEqual
    {
        bool operator()(const std::tuple<LoatBoolExprVec> &a, const std::tuple<LoatBoolExprVec> &b) const noexcept;
    };

    struct CacheHash
    {
        size_t operator()(const std::tuple<LoatBoolExprVec> &a) const noexcept;
    };

    static ConsHash<LoatBoolExpr, LoatBoolAnd, CacheHash, CacheEqual, LoatBoolExprVec> cache;

public:
    explicit LoatBoolAnd(const LoatBoolExprVec &args);
    ~LoatBoolAnd();
    const LoatBoolExprVec &getArgs() const;
};

/**
 * Represents a negation (NOT)
 */
class LoatBoolNot : public LoatBoolExpr
{
    friend LoatBoolExprPtr LoatBoolExpression::mkNot(const LoatBoolExprPtr arg);

private:
    LoatBoolExprPtr m_arg;

    struct CacheEqual
    {
        bool operator()(const std::tuple<LoatBoolExprPtr> &a, const std::tuple<LoatBoolExprPtr> &b) const noexcept;
    };

    struct CacheHash
    {
        size_t operator()(const std::tuple<LoatBoolExprPtr> &a) const noexcept;
    };

    static ConsHash<LoatBoolExpr, LoatBoolNot, CacheHash, CacheEqual, LoatBoolExprPtr> cache;

public:
    explicit LoatBoolNot(const LoatBoolExprPtr &arg);
    ~LoatBoolNot();
    const LoatBoolExprPtr &getArg() const;
};

/**
 * Represents a comparison literal (e.g. x < y)
 */
class LoatBoolCmp : public LoatBoolExpr
{
    friend LoatBoolExprPtr LoatBoolExpression::mkCmp(const LoatIntExprPtr lhs, LoatBoolExpression::CmpOp op, const LoatIntExprPtr rhs);

private:
    LoatIntExprPtr m_lhs;
    LoatIntExprPtr m_rhs;
    LoatBoolExpression::CmpOp m_op;

    struct CacheEqual
    {
        bool operator()(const std::tuple<LoatIntExprPtr, LoatBoolExpression::CmpOp, LoatIntExprPtr> &a,
                        const std::tuple<LoatIntExprPtr, LoatBoolExpression::CmpOp, LoatIntExprPtr> &b) const noexcept;
    };

    struct CacheHash
    {
        size_t operator()(const std::tuple<LoatIntExprPtr, LoatBoolExpression::CmpOp, LoatIntExprPtr> &a) const noexcept;
    };

    static ConsHash<LoatBoolExpr, LoatBoolCmp, CacheHash, CacheEqual, LoatIntExprPtr, LoatBoolExpression::CmpOp, LoatIntExprPtr> cache;

public:
    LoatBoolCmp(const LoatIntExprPtr lhs, LoatBoolExpression::CmpOp op, const LoatIntExprPtr rhs);
    ~LoatBoolCmp();

    const LoatIntExprPtr &getLhs() const;
    const LoatIntExprPtr &getRhs() const;
    LoatBoolExpression::CmpOp getOp() const;
};

// Stream output
std::ostream &operator<<(std::ostream &os, const LoatBoolExprPtr &expr);

// Operator Overloads for comparisons / literals
LoatBoolExprPtr operator&&(const LoatBoolExprPtr a, const LoatBoolExprPtr b);

LoatBoolExprPtr operator||(const LoatBoolExprPtr a, const LoatBoolExprPtr b);

LoatBoolExprPtr operator!(const LoatBoolExprPtr a);

// Operator Overloads for comparisons / literals
LoatBoolExprPtr operator==(const LoatIntExprPtr &lhs, const LoatIntExprPtr &rhs);
LoatBoolExprPtr operator!=(const LoatIntExprPtr &lhs, const LoatIntExprPtr &rhs);
LoatBoolExprPtr operator<(const LoatIntExprPtr &lhs, const LoatIntExprPtr &rhs);
LoatBoolExprPtr operator<=(const LoatIntExprPtr &lhs, const LoatIntExprPtr &rhs);
LoatBoolExprPtr operator>(const LoatIntExprPtr &lhs, const LoatIntExprPtr &rhs);
LoatBoolExprPtr operator>=(const LoatIntExprPtr &lhs, const LoatIntExprPtr &rhs);