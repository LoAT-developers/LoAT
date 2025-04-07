#include "loatexpression.hpp"
#include "optional.hpp"
#include "linkedhashmap.hpp"

#include <numeric>
#include <sstream>

// Hash function for expression pointers
std::size_t hash_value(const LoatExprPtr &x)
{
    return std::hash<std::shared_ptr<const LoatExpr>>{}(x.as_nullable());
}
std::size_t hash_value(const LoatVarPtr &x)
{
    return std::hash<std::shared_ptr<const LoatVar>>{}(x.as_nullable());
}

// Constructor for base expression with specific kind
LoatExpr::LoatExpr(const LoatExpression::Kind kind) : m_kind(kind) {}

// Default constructor assumes variable
LoatExpr::LoatExpr() : m_kind(LoatExpression::Kind::Variable) {}

// Return kind of the expression
LoatExpression::Kind LoatExpr::getKind() const
{
    return m_kind;
}

// Convert this expression to shared pointer
LoatExprPtr LoatExpr::toPtr() const
{
    return cpp::assume_not_null(shared_from_this());
}

LoatExprPtr operator-(const LoatExprPtr x)
{
    return LoatExpression::mkTimes(LoatExpression::mkConst(Rational(-1)), x);
}

LoatExprPtr operator-(const LoatExprPtr x, const LoatExprPtr y)
{
    return LoatExpression::mkPlus(x, -y);
}

LoatExprPtr operator+(const LoatExprPtr x, const LoatExprPtr y)
{
    return LoatExpression::mkPlus(x, y);
}

LoatExprPtr operator*(const LoatExprPtr x, const LoatExprPtr y)
{
    return LoatExpression::mkTimes(x, y);
}

// ADD WHEN WE HAVE EXP
//  LoatExprPtr operator^(const LoatExprPtr x, const LoatExprPtr y)
//  {
//      return LoatExpression::mkExp(x, y);
//  }

// Divide the expression by a rational number
LoatExprPtr LoatExpr::divide(const Rational &y) const
{
    return LoatExpression::mkTimes(LoatExpression::mkConst(Rational(
                                       boost::multiprecision::denominator(y),
                                       boost::multiprecision::numerator(y))),
                                   toPtr());
}

// Convert variable pointer to expression pointer
LoatExprPtr LoatExpression::toExpr(const LoatVarPtr &x)
{
    return cpp::assume_not_null(x->shared_from_this());
}

// Stream output for variable
std::ostream &operator<<(std::ostream &s, const LoatVarPtr e)
{
    return s << e->getName();
}

// Stream output for expressions
std::ostream &operator<<(std::ostream &s, const LoatExprPtr e)
{
    switch (e->getKind())
    {
    case LoatExpression::Kind::Plus:
    {
        s << "(";
        const auto add = std::static_pointer_cast<const LoatAdd>(e.as_nullable());
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
    case LoatExpression::Kind::Times:
    {
        s << "(";
        const auto mult = std::static_pointer_cast<const LoatMult>(e.as_nullable());
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
    // case LoatExpression::Kind::Mod:
    // {
    //     const auto mod = std::static_pointer_cast<const LoatMod>(e.as_nullable());
    //     return s << "(" << mod->getLhs() << " % " << mod->getRhs() << ")";
    // }
    // case LoatExpression::Kind::Exp:
    // {
    //     const auto exp = std::static_pointer_cast<const LoatExp>(e.as_nullable());
    //     return s << "(" << exp->getBase() << " ^ " << exp->getExponent() << ")";
    // }
    case LoatExpression::Kind::Constant:
    {
        const auto c = std::static_pointer_cast<const LoatConst>(e.as_nullable());
        return s << c->getValue();
    }
    // case LoatExpression::Kind::Variable:
    // {
    //     const auto v = std::static_pointer_cast<const LoatVar>(e.as_nullable());
    //     return s << v->getName();
    // }
    default:
        return s << "<unknown expr>";
    }
}