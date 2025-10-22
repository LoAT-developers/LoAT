#include "loatboolexpr.hpp"
#include <boost/functional/hash.hpp>

// ==============================
// LoatBoolExpr base class
// ==============================

LoatBoolExpr::LoatBoolExpr(const LoatBoolExpression::Kind kind)
    : m_kind(kind) {}

LoatBoolExpression::Kind LoatBoolExpr::getKind() const
{
    return m_kind;
}
LoatBoolExprPtr LoatBoolExpr::toPtr() const
{
    return cpp::assume_not_null(shared_from_this());
}

// ==============================
// LoatBoolVar
// ==============================

ConsHash<LoatBoolExpr, LoatBoolVar, LoatBoolVar::CacheHash, LoatBoolVar::CacheEqual, std::string, bool> LoatBoolVar::cache;

LoatBoolVar::LoatBoolVar(const std::string &name, const bool isPost)
    : LoatBoolExpr(LoatBoolExpression::Kind::Variable), m_name(name), m_isPost(isPost) {}

LoatBoolVar::~LoatBoolVar()
{
    cache.erase(m_name, m_isPost);
}

std::string LoatBoolVar::getName() const { return m_name; }

bool LoatBoolVar::isPost() const { return m_isPost; }

bool LoatBoolVar::CacheEqual::operator()(const std::tuple<std::string, bool> &a, const std::tuple<std::string, bool> &b) const noexcept
{
    return std::get<0>(a) == std::get<0>(b);
}

size_t LoatBoolVar::CacheHash::operator()(const std::tuple<std::string, bool> &a) const noexcept
{
    size_t hash = 0;
    boost::hash_combine(hash, std::get<0>(a));
    boost::hash_combine(hash, std::get<1>(a));
    return hash;
}

LoatBoolExprPtr LoatBoolExpression::mkVar(const std::string &name, const bool isPost)
{
    return LoatBoolVar::cache.from_cache(name, isPost)->toPtr();
}

LoatBoolExprPtr LoatBoolExpression::mkPreVar(const std::string &name)
{
    return mkVar(name, false);
}

LoatBoolExprPtr LoatBoolExpression::mkPostVar(const std::string &name)
{
    return mkVar(name, true);
}

// ==============================
// LoatBoolAnd
// ==============================

ConsHash<LoatBoolExpr, LoatBoolAnd, LoatBoolAnd::CacheHash, LoatBoolAnd::CacheEqual, LoatBoolExprVec> LoatBoolAnd::cache;

LoatBoolAnd::LoatBoolAnd(const LoatBoolExprVec &args)
    : LoatBoolExpr(LoatBoolExpression::Kind::And), m_args(args) {}

LoatBoolAnd::~LoatBoolAnd()
{
    cache.erase(m_args);
}

const LoatBoolExprVec &LoatBoolAnd::getArgs() const { return m_args; }

bool LoatBoolAnd::CacheEqual::operator()(const std::tuple<LoatBoolExprVec> &a, const std::tuple<LoatBoolExprVec> &b) const noexcept
{
    return a == b;
}

size_t LoatBoolAnd::CacheHash::operator()(const std::tuple<LoatBoolExprVec> &a) const noexcept
{
    const auto &[children]{a};
    size_t hash{0};
    boost::hash_combine(hash, boost::hash_unordered_range(children.begin(), children.end()));
    return hash;
}

LoatBoolExprPtr LoatBoolExpression::mkAnd(const LoatBoolExprVec &&args)
{
    return LoatBoolAnd::cache.from_cache(args)->toPtr();
}

// ==============================
// LoatBoolOr
// ==============================

ConsHash<LoatBoolExpr, LoatBoolOr, LoatBoolOr::CacheHash, LoatBoolOr::CacheEqual, LoatBoolExprVec> LoatBoolOr::cache;

LoatBoolOr::LoatBoolOr(const LoatBoolExprVec &args)
    : LoatBoolExpr(LoatBoolExpression::Kind::Or), m_args(args) {}

LoatBoolOr::~LoatBoolOr()
{
    cache.erase(m_args);
}

const LoatBoolExprVec &LoatBoolOr::getArgs() const { return m_args; }

bool LoatBoolOr::CacheEqual::operator()(const std::tuple<LoatBoolExprVec> &a, const std::tuple<LoatBoolExprVec> &b) const noexcept
{
    return a == b;
}

size_t LoatBoolOr::CacheHash::operator()(const std::tuple<LoatBoolExprVec> &a) const noexcept
{
    const auto &[children]{a};
    size_t hash{0};
    boost::hash_combine(hash, boost::hash_unordered_range(children.begin(), children.end()));
    return hash;
}

LoatBoolExprPtr LoatBoolExpression::mkOr(const LoatBoolExprVec &&args)
{
    return LoatBoolOr::cache.from_cache(args)->toPtr();
}

// ==============================
// LoatBoolNot
// ==============================

ConsHash<LoatBoolExpr, LoatBoolNot, LoatBoolNot::CacheHash, LoatBoolNot::CacheEqual, LoatBoolExprPtr> LoatBoolNot::cache;

LoatBoolNot::LoatBoolNot(const LoatBoolExprPtr &arg)
    : LoatBoolExpr(LoatBoolExpression::Kind::Not), m_arg(arg) {}

LoatBoolNot::~LoatBoolNot()
{
    cache.erase(m_arg);
}

const LoatBoolExprPtr &LoatBoolNot::getArg() const { return m_arg; }

bool LoatBoolNot::CacheEqual::operator()(const std::tuple<LoatBoolExprPtr> &a, const std::tuple<LoatBoolExprPtr> &b) const noexcept
{
    return std::get<0>(a) == std::get<0>(b);
}

size_t LoatBoolNot::CacheHash::operator()(const std::tuple<LoatBoolExprPtr> &a) const noexcept
{
    return std::hash<LoatBoolExprPtr>{}(std::get<0>(a));
}

LoatBoolExprPtr LoatBoolExpression::mkNot(const LoatBoolExprPtr& arg)
{
    return LoatBoolNot::cache.from_cache(arg)->toPtr();
}

// ==============================
// LoatBoolCmp
// ==============================

LoatBoolExprPtr LoatBoolExpression::mkCmp(const LoatIntExprPtr& lhs, const CmpOp op, const LoatIntExprPtr& rhs)
{
    return LoatBoolCmp::cache.from_cache(lhs, op, rhs)->toPtr();
}

LoatBoolExprPtr LoatBoolExpression::mkEq(const LoatIntExprPtr& lhs, const LoatIntExprPtr& rhs)
{
    return mkCmp(lhs, CmpOp::Eq, rhs);
}

LoatBoolExprPtr LoatBoolExpression::mkNeq(const LoatIntExprPtr& lhs, const LoatIntExprPtr& rhs)
{
    return mkCmp(lhs, CmpOp::Neq, rhs);
}

LoatBoolExprPtr LoatBoolExpression::mkLt(const LoatIntExprPtr& lhs, const LoatIntExprPtr& rhs)
{
    return mkCmp(lhs, CmpOp::Lt, rhs);
}
LoatBoolExprPtr LoatBoolExpression::mkLe(const LoatIntExprPtr& lhs, const LoatIntExprPtr& rhs)
{
    return mkCmp(lhs, CmpOp::Le, rhs);
}
LoatBoolExprPtr LoatBoolExpression::mkGt(const LoatIntExprPtr& lhs, const LoatIntExprPtr& rhs)
{
    return mkCmp(lhs, CmpOp::Gt, rhs);
}

LoatBoolExprPtr LoatBoolExpression::mkGe(const LoatIntExprPtr& lhs, const LoatIntExprPtr& rhs)
{
    return mkCmp(lhs, CmpOp::Ge, rhs);
}

bool LoatBoolCmp::CacheEqual::operator()(const std::tuple<LoatIntExprPtr, LoatBoolExpression::CmpOp, LoatIntExprPtr> &a,
                                         const std::tuple<LoatIntExprPtr, LoatBoolExpression::CmpOp, LoatIntExprPtr> &b) const noexcept
{
    return std::get<0>(a).get() == std::get<0>(b).get() &&
        std::get<1>(a) == std::get<1>(b) &&
        std::get<2>(a).get() == std::get<2>(b).get();
}

size_t LoatBoolCmp::CacheHash::operator()(const std::tuple<LoatIntExprPtr, LoatBoolExpression::CmpOp, LoatIntExprPtr> &a) const noexcept
{
    size_t hash = 0;
    boost::hash_combine(hash, std::get<0>(a));
    boost::hash_combine(hash, static_cast<int>(std::get<1>(a)));
    boost::hash_combine(hash, std::get<2>(a));
    return hash;
}

ConsHash<LoatBoolExpr, LoatBoolCmp, LoatBoolCmp::CacheHash, LoatBoolCmp::CacheEqual, LoatIntExprPtr, LoatBoolExpression::CmpOp, LoatIntExprPtr> LoatBoolCmp::cache;
LoatBoolCmp::LoatBoolCmp(const LoatIntExprPtr& lhs, const LoatBoolExpression::CmpOp op, const LoatIntExprPtr& rhs)
    : LoatBoolExpr(LoatBoolExpression::Kind::Compare), m_lhs(lhs), m_rhs(rhs), m_op(op) {}
LoatBoolCmp::~LoatBoolCmp()
{
    cache.erase(m_lhs, m_op, m_rhs);
}
const LoatIntExprPtr &LoatBoolCmp::getLhs() const { return m_lhs; }
const LoatIntExprPtr &LoatBoolCmp::getRhs() const { return m_rhs; }
LoatBoolExpression::CmpOp LoatBoolCmp::getOp() const { return m_op; }

std::ostream &operator<<(std::ostream &os, const LoatBoolExprPtr &expr)
{
    using Kind = LoatBoolExpression::Kind;
    switch (expr->getKind())
    {
    case Kind::Variable:
    {
        const auto v = std::static_pointer_cast<const LoatBoolVar>(expr.as_nullable());
        return os << v->getName() << (v->isPost() ? "'" : "");
    }
    case Kind::And:
    {
        const auto a = std::static_pointer_cast<const LoatBoolAnd>(expr.as_nullable());
        os << "(";
        bool first = true;
        for (const auto &arg : a->getArgs())
        {
            if (!first)
                os << " && ";
            os << arg;
            first = false;
        }
        return os << ")";
    }
    case Kind::Or:
    {
        const auto o = std::static_pointer_cast<const LoatBoolOr>(expr.as_nullable());
        os << "(";
        bool first = true;
        for (const auto &arg : o->getArgs())
        {
            if (!first)
                os << " || ";
            os << arg;
            first = false;
        }
        return os << ")";
    }
    case Kind::Not:
    {
        const auto n = std::static_pointer_cast<const LoatBoolNot>(expr.as_nullable());
        return os << "(!" << n->getArg() << ")";
    }
    case Kind::Compare:
    {
        const auto c = std::static_pointer_cast<const LoatBoolCmp>(expr.as_nullable());
        os << "(" << c->getLhs() << " ";

        switch (c->getOp())
        {
        case LoatBoolExpression::CmpOp::Eq:
            os << "==";
            break;
        case LoatBoolExpression::CmpOp::Neq:
            os << "!=";
            break;
        case LoatBoolExpression::CmpOp::Lt:
            os << "<";
            break;
        case LoatBoolExpression::CmpOp::Le:
            os << "<=";
            break;
        case LoatBoolExpression::CmpOp::Gt:
            os << ">";
            break;
        case LoatBoolExpression::CmpOp::Ge:
            os << ">=";
            break;
        }

        return os << " " << c->getRhs() << ")";
    }
    default:
        return os << "<unknown>";
    }
}

// Operator Overloads
LoatBoolExprPtr operator&&(const LoatBoolExprPtr& a, const LoatBoolExprPtr& b)
{
    return LoatBoolExpression::mkAnd({a, b});
}

LoatBoolExprPtr operator||(const LoatBoolExprPtr& a, const LoatBoolExprPtr& b)
{
    return LoatBoolExpression::mkOr({a, b});
}

LoatBoolExprPtr operator!(const LoatBoolExprPtr& a)
{
    return LoatBoolExpression::mkNot(a);
}

LoatBoolExprPtr operator==(const LoatIntExprPtr &lhs, const LoatIntExprPtr &rhs)
{
    return LoatBoolExpression::mkEq(lhs, rhs);
}

LoatBoolExprPtr operator!=(const LoatIntExprPtr &lhs, const LoatIntExprPtr &rhs)
{
    return LoatBoolExpression::mkNeq(lhs, rhs);
}

LoatBoolExprPtr operator<(const LoatIntExprPtr &lhs, const LoatIntExprPtr &rhs)
{
    return LoatBoolExpression::mkLt(lhs, rhs);
}

LoatBoolExprPtr operator<=(const LoatIntExprPtr &lhs, const LoatIntExprPtr &rhs)
{
    return LoatBoolExpression::mkLe(lhs, rhs);
}

LoatBoolExprPtr operator>(const LoatIntExprPtr &lhs, const LoatIntExprPtr &rhs)
{
    return LoatBoolExpression::mkGt(lhs, rhs);
}

LoatBoolExprPtr operator>=(const LoatIntExprPtr &lhs, const LoatIntExprPtr &rhs)
{
    return LoatBoolExpression::mkGe(lhs, rhs);
}
