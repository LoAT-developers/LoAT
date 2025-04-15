#include "loatintexpr.hpp"
#include "optional.hpp"
#include "linkedhashmap.hpp"

#include <numeric>
#include <sstream>

// Hash function for expression pointers
std::size_t hash_value(const LoatIntExprPtr &x)
{
    return std::hash<std::shared_ptr<const LoatIntExpr>>{}(x.as_nullable());
}
std::size_t hash_value(const LoatIntVarPtr &x)
{
    return std::hash<std::shared_ptr<const LoatIntVar>>{}(x.as_nullable());
}

// Constructor for base expression with specificInt kind
LoatIntExpr::LoatIntExpr(const LoatIntExpression::Kind kind) : m_kind(kind) {}

// Default constructor assumes varIntiable
LoatIntExpr::LoatIntExpr() : m_kind(LoatIntExpression::Kind::Variable) {}

// Return kind of the expression
LoatIntExpression::Kind LoatIntExpr::getKind() const
{
    return m_kind;
}

// Convert this expression to shared pointer
LoatIntExprPtr LoatIntExpr::toPtr() const
{
    return cpp::assume_not_null(shared_from_this());
}

// Overload operators +,-,*,^
LoatIntExprPtr operator-(const LoatIntExprPtr x)
{
    return LoatIntExpression::mkTimes(LoatIntExpression::mkConst(Rational(-1)), x);
}

LoatIntExprPtr operator-(const LoatIntExprPtr x, const LoatIntExprPtr y)
{
    return LoatIntExpression::mkPlus(x, -y);
}

LoatIntExprPtr operator+(const LoatIntExprPtr x, const LoatIntExprPtr y)
{
    return LoatIntExpression::mkPlus(x, y);
}

LoatIntExprPtr operator*(const LoatIntExprPtr x, const LoatIntExprPtr y)
{
    return LoatIntExpression::mkTimes(x, y);
}

LoatIntExprPtr operator^(const LoatIntExprPtr x, const LoatIntExprPtr y)
{
    return LoatIntExpression::mkExp(x, y);
}

// Divide the expression by a rational number
LoatIntExprPtr LoatIntExpr::divide(const Rational &y) const
{
    return LoatIntExpression::mkTimes(LoatIntExpression::mkConst(Rational(
                                          boost::multiprecision::denominator(y),
                                          boost::multiprecision::numerator(y))),
                                      toPtr());
}

// Stream output for variable
std::ostream &operator<<(std::ostream &s, const LoatIntVarPtr e)
{
    return s << e->getName();
}

// Stream output for expressions
std::ostream &operator<<(std::ostream &s, const LoatIntExprPtr e)
{
    switch (e->getKind())
    {
    case LoatIntExpression::Kind::Plus:
    {
        s << "(";
        const auto add = std::static_pointer_cast<const LoatIntAdd>(e.as_nullable());
        bool first = true;
        for (const auto &arg : add->getArgs())
        {
            if (!first)
                s << " + ";
            s << arg;
            first = false;
        }
        return s << ")";
    }
    case LoatIntExpression::Kind::Times:
    {
        s << "(";
        const auto mult = std::static_pointer_cast<const LoatIntMult>(e.as_nullable());
        bool first = true;
        for (const auto &arg : mult->getArgs())
        {
            if (!first)
                s << " * ";
            s << arg;
            first = false;
        }
        return s << ")";
    }
    case LoatIntExpression::Kind::Mod:
    {
        const auto mod = std::static_pointer_cast<const LoatIntMod>(e.as_nullable());
        return s << "(" << mod->getLhs() << " % " << mod->getRhs() << ")";
    }
    case LoatIntExpression::Kind::Exp:
    {
        const auto exp = std::static_pointer_cast<const LoatIntExp>(e.as_nullable());
        return s << "(" << exp->getBase() << " ^ " << exp->getExponent() << ")";
    }
    case LoatIntExpression::Kind::Constant:
    {
        const auto c = std::static_pointer_cast<const LoatIntConst>(e.as_nullable());
        return s << c->getValue();
    }
    case LoatIntExpression::Kind::Variable:
    {
        const auto v = std::static_pointer_cast<const LoatIntVar>(e.as_nullable());
        return s << v->getName();
    }
    default:
        return s << "<unknown expr>";
    }
}