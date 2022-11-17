#include "cvccontext.hpp"

CVCContext::CVCContext(cvc5::Solver& ctx): ctx(ctx) {}

CVCContext::~CVCContext() {}

cvc5::Term CVCContext::getInt(long val) {
    return ctx.mkInteger(val);
}

cvc5::Term CVCContext::getReal(long num, long denom) {
    return ctx.mkReal(num, denom);
}

cvc5::Term CVCContext::pow(const cvc5::Term &base, const cvc5::Term &exp) {
    return ctx.mkTerm(cvc5::POW, {base, exp});
}

cvc5::Term CVCContext::plus(const cvc5::Term &x, const cvc5::Term &y) {
    return ctx.mkTerm(cvc5::ADD, {x, y});
}

cvc5::Term CVCContext::times(const cvc5::Term &x, const cvc5::Term &y) {
    return ctx.mkTerm(cvc5::MULT, {x, y});
}

cvc5::Term CVCContext::eq(const cvc5::Term &x, const cvc5::Term &y) {
    return ctx.mkTerm(cvc5::EQUAL, {x, y});
}

cvc5::Term CVCContext::lt(const cvc5::Term &x, const cvc5::Term &y) {
    return ctx.mkTerm(cvc5::LT, {x, y});
}

cvc5::Term CVCContext::le(const cvc5::Term &x, const cvc5::Term &y) {
    return ctx.mkTerm(cvc5::LEQ, {x, y});
}

cvc5::Term CVCContext::gt(const cvc5::Term &x, const cvc5::Term &y) {
    return ctx.mkTerm(cvc5::GT, {x, y});
}

cvc5::Term CVCContext::ge(const cvc5::Term &x, const cvc5::Term &y) {
    return ctx.mkTerm(cvc5::GEQ, {x, y});
}

cvc5::Term CVCContext::neq(const cvc5::Term &x, const cvc5::Term &y) {
    return ctx.mkTerm(cvc5::NOT, {ctx.mkTerm(cvc5::EQUAL, {x, y})});
}

cvc5::Term CVCContext::bAnd(const cvc5::Term &x, const cvc5::Term &y) {
    return ctx.mkTerm(cvc5::AND, {x, y});
}

cvc5::Term CVCContext::bOr(const cvc5::Term &x, const cvc5::Term &y) {
    return ctx.mkTerm(cvc5::OR, {x, y});
}

cvc5::Term CVCContext::bTrue() const {
    return ctx.mkTrue();
}

cvc5::Term CVCContext::bFalse() const {
    return ctx.mkFalse();
}

cvc5::Term CVCContext::negate(const cvc5::Term &x) {
    return ctx.mkTerm(cvc5::NOT, {x});
}

bool CVCContext::isTrue(const cvc5::Term &e) const {
    return e.isBooleanValue() && e.getBooleanValue();
}

bool CVCContext::isFalse(const cvc5::Term &e) const {
    return e.isBooleanValue() && !e.getBooleanValue();
}

bool CVCContext::isNot(const cvc5::Term &e) const {
    return e.getOp().getKind() == cvc5::NOT;
}

std::vector<cvc5::Term> CVCContext::getChildren(const cvc5::Term &e) const {
    return std::vector<cvc5::Term>(e.begin(), e.end());
}

bool CVCContext::isAnd(const cvc5::Term &e) const {
    return e.getOp().getKind() == cvc5::AND;
}

bool CVCContext::isAdd(const cvc5::Term &e) const {
    return e.getOp().getKind() == cvc5::ADD;
}

bool CVCContext::isMul(const cvc5::Term &e) const {
    return e.getOp().getKind() == cvc5::MULT;
}

bool CVCContext::isPow(const cvc5::Term &e) const {
    return e.getOp().getKind() == cvc5::POW;
}

bool CVCContext::isVar(const cvc5::Term &e) const {
    return e.isUninterpretedSortValue();
}

bool CVCContext::isRationalConstant(const cvc5::Term &e) const {
    return e.isRealValue();
}

bool CVCContext::isInt(const cvc5::Term &e) const {
    return e.isIntegerValue();
}

long CVCContext::toInt(const cvc5::Term &e) const {
    // TDOD overflow?
    return e.getInt64Value();
}

cvc5::Term CVCContext::lhs(const cvc5::Term &e) const {
    switch (e.getOp().getKind()) {
    case cvc5::EQUAL:
    case cvc5::LEQ:
    case cvc5::LT:
    case cvc5::GEQ:
    case cvc5::GT:
        return e[0];
    default:
        throw std::logic_error("not a relation");
    }
}

cvc5::Term CVCContext::rhs(const cvc5::Term &e) const {
    switch (e.getOp().getKind()) {
    case cvc5::EQUAL:
    case cvc5::LEQ:
    case cvc5::LT:
    case cvc5::GEQ:
    case cvc5::GT:
        return e[1];
    default:
        throw std::logic_error("not a relation");
    }
}

Rel::RelOp CVCContext::relOp(const cvc5::Term &e) const {
    switch (e.getOp().getKind()) {
    case cvc5::EQUAL:
        return Rel::eq;
    case cvc5::LEQ:
        return Rel::leq;
    case cvc5::LT:
        return Rel::lt;
    case cvc5::GEQ:
        return Rel::geq;
    case cvc5::GT:
        return Rel::gt;
    default:
        throw std::logic_error("not a relation");
    }
}

std::string CVCContext::getName(const cvc5::Term &x) const {
    if (x.hasSymbol()) {
        return x.getSymbol();
    } else {
        throw std::logic_error("does not have a name");
    }
}

cvc5::Term CVCContext::buildVar(const std::string &basename, Expr::Type type) {
    cvc5::Sort sort;
    switch (type) {
    case Expr::Bool:
        sort = ctx.getBooleanSort();
        break;
    case Expr::Int:
        sort = ctx.getIntegerSort();
        break;
    case Expr::Rational:
        sort = ctx.getRealSort();
        break;
    }
    return ctx.mkConst(sort, basename);
}

void CVCContext::printStderr(const cvc5::Term &e) const {
    std::cerr << e << std::endl;
}
