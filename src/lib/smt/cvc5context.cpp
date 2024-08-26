#include "cvc5context.hpp"
#include "theory.hpp"

CVC5Context::CVC5Context(cvc5::Solver& ctx): ctx(ctx), refinement(ctx.mkBoolean(true)) { }

CVC5Context::~CVC5Context() { }

cvc5::Term CVC5Context::buildVar(const Arith::Var &var) {
    const auto res {ctx.mkConst(ctx.getIntegerSort(), var->getName())};
    reverseArithVarMap.emplace(res, var);
    return res;
}

cvc5::Term CVC5Context::buildVar(const Bools::Var &var) {
    const auto res {ctx.mkConst(ctx.getBooleanSort(), var->getName())};
    reverseBoolVarMap.emplace(res, var);
    return res;
}

cvc5::Term CVC5Context::getInt(const Int &val) {
    return ctx.mkInteger(val.str());
}

cvc5::Term CVC5Context::getReal(const Int &num, const Int &denom) {
    return ctx.mkTerm(cvc5::Kind::DIVISION, {getInt(num), getInt(denom)});
}

cvc5::Term CVC5Context::pow(const cvc5::Term &base, const cvc5::Term &exp) {
    if (exp.isIntegerValue()) {
        return ctx.mkTerm(cvc5::Kind::POW, {base, exp});
    } else if (base.isIntegerValue()) {
        const auto log {ctx.mkConst(ctx.getRealSort())};
        refinement = refinement.andTerm(ctx.mkTerm(cvc5::Kind::TO_REAL, {base}).eqTerm(ctx.mkTerm(cvc5::Kind::EXPONENTIAL, {log})));
        return ctx.mkTerm(cvc5::Kind::TO_INTEGER, {ctx.mkTerm(cvc5::Kind::EXPONENTIAL, {ctx.mkTerm(cvc5::Kind::MULT, {log, exp})})});
    } else {
        throw std::invalid_argument((std::stringstream() << "one argument of CVC5Context::pow must be an integer, got " << base << " and " << exp).str());
    }
}

cvc5::Term CVC5Context::plus(const cvc5::Term &x, const cvc5::Term &y) {
    return ctx.mkTerm(cvc5::Kind::ADD, {x, y});
}

cvc5::Term CVC5Context::times(const cvc5::Term &x, const cvc5::Term &y) {
    return ctx.mkTerm(cvc5::Kind::MULT, {x, y});
}

cvc5::Term CVC5Context::mod(const cvc5::Term &x, const cvc5::Term &y) {
    return ctx.mkTerm(cvc5::Kind::INTS_MODULUS, {x, y});
}

cvc5::Term CVC5Context::eq(const cvc5::Term &x, const cvc5::Term &y) {
    if (x.getSort() != y.getSort()
        && (x.getSort() == ctx.getRealSort() || y.getSort() == ctx.getRealSort())
        && (x.getSort() == ctx.getIntegerSort() || y.getSort() == ctx.getIntegerSort())) {
        return ctx.mkTerm(cvc5::Kind::EQUAL, {ctx.mkTerm(cvc5::Kind::TO_REAL, {x}), ctx.mkTerm(cvc5::Kind::TO_REAL, {y})});
    } else {
        return ctx.mkTerm(cvc5::Kind::EQUAL, {x, y});
    }
}

cvc5::Term CVC5Context::lt(const cvc5::Term &x, const cvc5::Term &y) {
    return ctx.mkTerm(cvc5::Kind::LT, {x, y});
}

cvc5::Term CVC5Context::le(const cvc5::Term &x, const cvc5::Term &y) {
    return ctx.mkTerm(cvc5::Kind::LEQ, {x, y});
}

cvc5::Term CVC5Context::gt(const cvc5::Term &x, const cvc5::Term &y) {
    return ctx.mkTerm(cvc5::Kind::GT, {x, y});
}

cvc5::Term CVC5Context::ge(const cvc5::Term &x, const cvc5::Term &y) {
    return ctx.mkTerm(cvc5::Kind::GEQ, {x, y});
}

cvc5::Term CVC5Context::neq(const cvc5::Term &x, const cvc5::Term &y) {
    return ctx.mkTerm(cvc5::Kind::NOT, {eq(x, y)});
}

cvc5::Term CVC5Context::bAnd(const cvc5::Term &x, const cvc5::Term &y) {
    return ctx.mkTerm(cvc5::Kind::AND, {x, y});
}

cvc5::Term CVC5Context::bOr(const cvc5::Term &x, const cvc5::Term &y) {
    return ctx.mkTerm(cvc5::Kind::OR, {x, y});
}

cvc5::Term CVC5Context::bTrue() const {
    return ctx.mkBoolean(true);
}

cvc5::Term CVC5Context::bFalse() const {
    return ctx.mkBoolean(false);
}

cvc5::Term CVC5Context::negate(const cvc5::Term &x) {
    return ctx.mkTerm(cvc5::Kind::NOT, {x});
}

void CVC5Context::printStderr(const cvc5::Term &e) const {
    std::cerr << e << std::endl;
}

cvc5::Term CVC5Context::clearRefinement() {
    const auto res {refinement};
    refinement = bTrue();
    return res;
}

Arith::Var CVC5Context::getArithVar(const cvc5::Term &symbol) const {
    return reverseArithVarMap.at(symbol);
}

Bools::Var CVC5Context::getBoolVar(const cvc5::Term &symbol) const {
    return reverseBoolVarMap.at(symbol);
}
