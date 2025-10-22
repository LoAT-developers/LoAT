#pragma once

#include <memory>
#include <string>
#include <vector>
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
    LoatBoolExprPtr mkVar(const std::string &name, bool isPost);
    LoatBoolExprPtr mkPreVar(const std::string &name);
    LoatBoolExprPtr mkPostVar(const std::string &name);
    LoatBoolExprPtr mkAnd(const LoatBoolExprVec &&args);
    LoatBoolExprPtr mkOr(const LoatBoolExprVec &&args);
    LoatBoolExprPtr mkNot(const LoatBoolExprPtr& arg);

    // Factory methods to create Literals
    LoatBoolExprPtr mkCmp(const LoatIntExprPtr& lhs, CmpOp op, const LoatIntExprPtr& rhs);
    LoatBoolExprPtr mkEq(const LoatIntExprPtr& lhs, const LoatIntExprPtr& rhs);
    LoatBoolExprPtr mkNeq(const LoatIntExprPtr& lhs, const LoatIntExprPtr& rhs);
    LoatBoolExprPtr mkLt(const LoatIntExprPtr& lhs, const LoatIntExprPtr& rhs);
    LoatBoolExprPtr mkLe(const LoatIntExprPtr& lhs, const LoatIntExprPtr& rhs);
    LoatBoolExprPtr mkGt(const LoatIntExprPtr& lhs, const LoatIntExprPtr& rhs);
    LoatBoolExprPtr mkGe(const LoatIntExprPtr& lhs, const LoatIntExprPtr& rhs);
}

/**
 * Base class for all expression types.
 */
class LoatBoolExpr : public std::enable_shared_from_this<LoatBoolExpr>
{
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
class LoatBoolVar final : public LoatBoolExpr
{
    friend LoatBoolExprPtr LoatBoolExpression::mkVar(const std::string &name, bool isPost);
    friend LoatBoolExprPtr LoatBoolExpression::mkPreVar(const std::string &name);
    friend LoatBoolExprPtr LoatBoolExpression::mkPostVar(const std::string &name);
    friend class ConsHash<LoatBoolVar, std::string, bool>;

    std::string m_name;
    bool m_isPost;

    struct CacheEqual
    {
        bool operator()(const std::tuple<std::string, bool> &a, const std::tuple<std::string, bool> &b) const noexcept;
    };
    struct CacheHash
    {
        size_t operator()(const std::tuple<std::string, bool> &a) const noexcept;
    };
    static ConsHash<LoatBoolVar, std::string, bool> cache;

public:
    explicit LoatBoolVar(std::string name, bool isPost);
    ~LoatBoolVar() override;
    std::string getName() const;
    bool isPost() const;
};

/**
 * Represents a disconjunction (OR)
 */
class LoatBoolOr final : public LoatBoolExpr
{
    friend LoatBoolExprPtr LoatBoolExpression::mkOr(const LoatBoolExprVec &&args);
    friend class ConsHash<LoatBoolOr, LoatBoolExprVec>;

    LoatBoolExprVec m_args;

    struct CacheEqual
    {
        bool operator()(const std::tuple<LoatBoolExprVec> &a, const std::tuple<LoatBoolExprVec> &b) const noexcept;
    };
    struct CacheHash
    {
        size_t operator()(const std::tuple<LoatBoolExprVec> &a) const noexcept;
    };
    static ConsHash<LoatBoolOr, LoatBoolExprVec> cache;

public:
    explicit LoatBoolOr(LoatBoolExprVec args);
    ~LoatBoolOr() override;
    const LoatBoolExprVec &getArgs() const;
};

/**
 * Represents a conjunction (AND)
 */
class LoatBoolAnd final : public LoatBoolExpr
{
    friend LoatBoolExprPtr LoatBoolExpression::mkAnd(const LoatBoolExprVec &&args);
    friend class ConsHash<LoatBoolAnd, LoatBoolExprVec>;

    LoatBoolExprVec m_args;

    struct CacheEqual
    {
        bool operator()(const std::tuple<LoatBoolExprVec> &a, const std::tuple<LoatBoolExprVec> &b) const noexcept;
    };

    struct CacheHash
    {
        size_t operator()(const std::tuple<LoatBoolExprVec> &a) const noexcept;
    };

    static ConsHash<LoatBoolAnd, LoatBoolExprVec> cache;

public:
    explicit LoatBoolAnd(LoatBoolExprVec args);
    ~LoatBoolAnd() override;
    const LoatBoolExprVec &getArgs() const;
};

/**
 * Represents a negation (NOT)
 */
class LoatBoolNot final : public LoatBoolExpr
{
    friend LoatBoolExprPtr LoatBoolExpression::mkNot(const LoatBoolExprPtr& arg);
    friend class ConsHash<LoatBoolNot, LoatBoolExprPtr>;

    LoatBoolExprPtr m_arg;

    struct CacheEqual
    {
        bool operator()(const std::tuple<LoatBoolExprPtr> &a, const std::tuple<LoatBoolExprPtr> &b) const noexcept;
    };

    struct CacheHash
    {
        size_t operator()(const std::tuple<LoatBoolExprPtr> &a) const noexcept;
    };

    static ConsHash<LoatBoolNot, LoatBoolExprPtr> cache;

public:
    explicit LoatBoolNot(LoatBoolExprPtr arg);
    ~LoatBoolNot() override;
    const LoatBoolExprPtr &getArg() const;
};

/**
 * Represents a comparison literal (e.g. x < y)
 */
class LoatBoolCmp final : public LoatBoolExpr
{
    friend LoatBoolExprPtr LoatBoolExpression::mkCmp(const LoatIntExprPtr& lhs, LoatBoolExpression::CmpOp op, const LoatIntExprPtr& rhs);
    friend class ConsHash<LoatBoolCmp, LoatIntExprPtr, LoatBoolExpression::CmpOp, LoatIntExprPtr>;

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

    static ConsHash<LoatBoolCmp, LoatIntExprPtr, LoatBoolExpression::CmpOp, LoatIntExprPtr> cache;

public:
    LoatBoolCmp(LoatIntExprPtr  lhs, LoatBoolExpression::CmpOp op, LoatIntExprPtr  rhs);
    ~LoatBoolCmp() override;

    const LoatIntExprPtr &getLhs() const;
    const LoatIntExprPtr &getRhs() const;
    LoatBoolExpression::CmpOp getOp() const;
};

// Stream output
std::ostream &operator<<(std::ostream &os, const LoatBoolExprPtr &expr);

// Operator Overloads for comparisons / literals
LoatBoolExprPtr operator&&(const LoatBoolExprPtr& a, const LoatBoolExprPtr& b);

LoatBoolExprPtr operator||(const LoatBoolExprPtr& a, const LoatBoolExprPtr& b);

LoatBoolExprPtr operator!(const LoatBoolExprPtr& a);

// Operator Overloads for comparisons / literals
LoatBoolExprPtr operator!=(const LoatIntExprPtr &lhs, const LoatIntExprPtr &rhs);
LoatBoolExprPtr operator<(const LoatIntExprPtr &lhs, const LoatIntExprPtr &rhs);
LoatBoolExprPtr operator<=(const LoatIntExprPtr &lhs, const LoatIntExprPtr &rhs);
LoatBoolExprPtr operator>(const LoatIntExprPtr &lhs, const LoatIntExprPtr &rhs);
LoatBoolExprPtr operator>=(const LoatIntExprPtr &lhs, const LoatIntExprPtr &rhs);