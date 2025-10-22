#include "loatintexpr.hpp"
#include "optional.hpp"
#include "vector.hpp"

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/functional/hash.hpp>
#include <numeric>
#include <sstream>
#include <string>
#include <utility>

// Hash function for expression pointers
std::size_t hash_value(const LoatIntExprPtr &x)
{
    return std::hash<std::shared_ptr<const LoatIntExpr>>{}(x.as_nullable());
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
LoatIntExprPtr operator-(const LoatIntExprPtr& x)
{
    return LoatIntExpression::mkTimes(LoatIntExpression::mkConst(Rational(-1)), x);
}

LoatIntExprPtr operator-(const LoatIntExprPtr& x, const LoatIntExprPtr& y)
{
    return LoatIntExpression::mkPlus(x, -y);
}

LoatIntExprPtr operator+(const LoatIntExprPtr& x, const LoatIntExprPtr& y)
{
    return LoatIntExpression::mkPlus(x, y);
}

LoatIntExprPtr operator*(const LoatIntExprPtr& x, const LoatIntExprPtr& y)
{
    return LoatIntExpression::mkTimes(x, y);
}

LoatIntExprPtr operator^(const LoatIntExprPtr& x, const LoatIntExprPtr& y)
{
    return LoatIntExpression::mkExp(x, y);
}

// Divide the expression by a rational number
LoatIntExprPtr LoatIntExpr::divide(const Rational &d) const
{
    return LoatIntExpression::mkTimes(LoatIntExpression::mkConst(Rational(
                                          boost::multiprecision::denominator(d),
                                          boost::multiprecision::numerator(d))),
                                      toPtr());
}

// Stream output for expressions
std::ostream &operator<<(std::ostream &s, const LoatIntExprPtr& e)
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
        return s << v->getName() << (v->isPost() ? "'" : "");
    }
    default:
        return s << "<unknown expr>";
    }
}

// Add
ConsHash<LoatIntExpr, LoatIntAdd, LoatIntAdd::CacheHash, LoatIntAdd::CacheEqual, LoatIntExprSet> LoatIntAdd::cache;

LoatIntAdd::LoatIntAdd(LoatIntExprSet args) : LoatIntExpr(LoatIntExpression::Kind::Plus), m_args(std::move(args)) {}

LoatIntAdd::~LoatIntAdd()
{
    cache.erase(m_args);
}

bool LoatIntAdd::CacheEqual::operator()(const std::tuple<LoatIntExprSet> &args1, const std::tuple<LoatIntExprSet> &args2) const noexcept
{
    return args1 == args2;
}

size_t LoatIntAdd::CacheHash::operator()(const std::tuple<LoatIntExprSet> &args) const noexcept
{
    size_t hash{42};
    const auto &children{std::get<0>(args)};
    boost::hash_combine(hash, boost::hash_unordered_range(children.begin(), children.end()));
    return hash;
}

LoatIntExprPtr LoatIntExpression::mkPlus(LoatIntExprPtr fst, LoatIntExprPtr snd)
{
    return mkPlus({std::move(fst), std::move(snd)});
}

LoatIntExprPtr LoatIntExpression::mkPlus(std::vector<LoatIntExprPtr> &&args)
{
    if (args.empty())
    {
        return mkConst(0);
    }
    if (args.size() == 1)
    {
        return args[0];
    }
    const LoatIntExprSet arg_set{args.begin(), args.end()};
    return LoatIntAdd::cache.from_cache(arg_set);
}

const LoatIntExprSet &LoatIntAdd::getArgs() const
{
    return m_args;
}

// Const
ConsHash<LoatIntExpr, LoatIntConst, LoatIntConst::CacheHash, LoatIntConst::CacheEqual, Rational> LoatIntConst::cache;

LoatIntConst::LoatIntConst(Rational t) : LoatIntExpr(LoatIntExpression::Kind::Constant), m_value(std::move(t)) {}

LoatIntConst::~LoatIntConst()
{
    cache.erase(m_value);
}

const Rational &LoatIntConst::operator*() const
{
    return m_value;
}

const Rational &LoatIntConst::getValue() const
{
    return m_value;
}

bool LoatIntConst::CacheEqual::operator()(const std::tuple<Rational> &args1, const std::tuple<Rational> &args2) const noexcept
{
    return std::get<0>(args1) == std::get<0>(args2);
}

size_t LoatIntConst::CacheHash::operator()(const std::tuple<Rational> &args) const noexcept
{
    return std::hash<Rational>{}(std::get<0>(args));
}

LoatIntExprPtr LoatIntExpression::mkConst(const Rational &r)
{
    return LoatIntConst::cache.from_cache(r);
}

LoatIntExprPtr LoatIntExpression::mkConst(const Rational &&r)
{
    return mkConst(r);
}

// Exp
ConsHash<LoatIntExpr, LoatIntExp, LoatIntExp::CacheHash, LoatIntExp::CacheEqual, LoatIntExprPtr, LoatIntExprPtr> LoatIntExp::cache;

LoatIntExp::LoatIntExp(LoatIntExprPtr base, LoatIntExprPtr exponent)
    : LoatIntExpr(LoatIntExpression::Kind::Exp), m_base(std::move(base)), m_exponent(std::move(exponent)) {}

LoatIntExp::~LoatIntExp()
{
    cache.erase(m_base, m_exponent);
}

LoatIntExprPtr LoatIntExp::getBase() const
{
    return m_base;
}

LoatIntExprPtr LoatIntExp::getExponent() const
{
    return m_exponent;
}

bool LoatIntExp::CacheEqual::operator()(const std::tuple<LoatIntExprPtr, LoatIntExprPtr> &a,
                                        const std::tuple<LoatIntExprPtr, LoatIntExprPtr> &b) const noexcept
{
    return a == b;
}

size_t LoatIntExp::CacheHash::operator()(const std::tuple<LoatIntExprPtr, LoatIntExprPtr> &a) const noexcept
{
    size_t hash = {0};
    boost::hash_combine(hash, std::get<0>(a));
    boost::hash_combine(hash, std::get<1>(a));
    return hash;
}

LoatIntExprPtr LoatIntExpression::mkExp(const LoatIntExprPtr& base, const LoatIntExprPtr& exponent)
{
    return LoatIntExp::cache.from_cache(base, exponent)->toPtr();
}

// Mod
ConsHash<LoatIntExpr, LoatIntMod, LoatIntMod::CacheHash, LoatIntMod::CacheEqual, LoatIntExprPtr, LoatIntExprPtr> LoatIntMod::cache;

LoatIntMod::LoatIntMod(LoatIntExprPtr lhs, LoatIntExprPtr rhs)
    : LoatIntExpr(LoatIntExpression::Kind::Mod), m_lhs(std::move(lhs)), m_rhs(std::move(rhs)) {}

LoatIntMod::~LoatIntMod()
{
    cache.erase(m_lhs, m_rhs);
}

LoatIntExprPtr LoatIntMod::getLhs() const {
    return m_lhs;
}

LoatIntExprPtr LoatIntMod::getRhs() const {
    return m_rhs;
}

bool LoatIntMod::CacheEqual::operator()(const std::tuple<LoatIntExprPtr, LoatIntExprPtr> &args1,
                                        const std::tuple<LoatIntExprPtr, LoatIntExprPtr> &args2) const noexcept
{
    return args1 == args2;
}

size_t LoatIntMod::CacheHash::operator()(const std::tuple<LoatIntExprPtr, LoatIntExprPtr> &args) const noexcept
{
    size_t hash = 23;
    const auto &lhs = std::get<0>(args);
    const auto &rhs = std::get<1>(args);
    boost::hash_combine(hash, lhs);
    boost::hash_combine(hash, rhs);
    return hash;
}

LoatIntExprPtr LoatIntExpression::mkMod(const LoatIntExprPtr& x, const LoatIntExprPtr& y)
{
    return LoatIntMod::cache.from_cache(x, y)->toPtr();
}

// Mult
ConsHash<LoatIntExpr, LoatIntMult, LoatIntMult::CacheHash, LoatIntMult::CacheEqual, LoatIntExprSet> LoatIntMult::cache;

LoatIntMult::LoatIntMult(LoatIntExprSet args) : LoatIntExpr(LoatIntExpression::Kind::Times), m_args(std::move(args)) {}

LoatIntMult::~LoatIntMult()
{
    cache.erase(m_args);
}

const LoatIntExprSet &LoatIntMult::getArgs() const
{
    return m_args;
}

bool LoatIntMult::CacheEqual::operator()(const std::tuple<LoatIntExprSet> &args1, const std::tuple<LoatIntExprSet> &args2) const noexcept
{
    return args1 == args2;
}

size_t LoatIntMult::CacheHash::operator()(const std::tuple<LoatIntExprSet> &args) const noexcept
{
    size_t hash = {23};
    const auto &children{std::get<0>(args)};
    boost::hash_combine(hash, boost::hash_unordered_range(children.begin(), children.end()));
    return hash;
}

LoatIntExprPtr LoatIntExpression::mkTimes(LoatIntExprVec &&args)
{
    if (args.empty())
        return mkConst(1);
    if (args.size() == 1)
        return args[0];
    return LoatIntMult::cache.from_cache(LoatIntExprSet(args.begin(), args.end()))->toPtr();
}

LoatIntExprPtr LoatIntExpression::mkTimes(const LoatIntExprPtr& a, const LoatIntExprPtr& b)
{
    return mkTimes(LoatIntExprVec{a, b});
}

// Var
ConsHash<LoatIntExpr, LoatIntVar, LoatIntVar::CacheHash, LoatIntVar::CacheEqual, std::string, bool> LoatIntVar::cache;

LoatIntVar::LoatIntVar(std::string name, const bool isPost) : LoatIntExpr(LoatIntExpression::Kind::Variable), m_name(std::move(name)), m_isPost(isPost) {}

LoatIntVar::~LoatIntVar()
{
    cache.erase(m_name, m_isPost);
}

std::string LoatIntVar::getName() const
{
    return m_name;
}

bool LoatIntVar::isPost() const
{
    return m_isPost;
}

bool LoatIntVar::CacheEqual::operator()(const std::tuple<std::string, bool> &a, const std::tuple<std::string, bool> &b) const noexcept
{
    return a == b;
}

size_t LoatIntVar::CacheHash::operator()(const std::tuple<std::string, bool> &a) const noexcept
{
    size_t hash = 0;
    boost::hash_combine(hash, std::get<0>(a));
    boost::hash_combine(hash, std::get<1>(a));
    return hash;
}

LoatIntExprPtr LoatIntExpression::mkVar(const std::string &name, const bool isPost)
{
    return LoatIntVar::cache.from_cache(name, isPost)->toPtr();
}

LoatIntExprPtr LoatIntExpression::mkPreVar(const std::string &name)
{
    return mkVar(name, false);
}

LoatIntExprPtr LoatIntExpression::mkPostVar(const std::string &name)
{
    return mkVar(name, true);
}
