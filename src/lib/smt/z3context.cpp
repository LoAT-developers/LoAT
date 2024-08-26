#include "z3context.hpp"
#include "theory.hpp"

Z3Context::Z3Context(z3::context& ctx): ctx(ctx) {}

Z3Context::~Z3Context() { }

z3::expr Z3Context::buildVar(const Arith::Var &var) {
    return ctx.int_const(var->getName().c_str());
}

z3::expr Z3Context::buildVar(const Bools::Var &var) {
    return ctx.bool_const(var->getName().c_str());
}

z3::expr Z3Context::getInt(const Int &val) {
    return ctx.int_val(val.str().c_str());
}

z3::expr Z3Context::getReal(const Int &num, const Int &denom) {
    return ctx.real_val((num.str() + " / " + denom.str()).c_str());
}

z3::expr Z3Context::pow(const z3::expr &base, const z3::expr &exp) {
    return z3::pw(base, exp);
}

z3::expr Z3Context::plus(const z3::expr &x, const z3::expr &y) {
    return x + y;
}

z3::expr Z3Context::times(const z3::expr &x, const z3::expr &y) {
    return x * y;
}

z3::expr Z3Context::mod(const z3::expr &x, const z3::expr &y) {
    return x % y;
}

z3::expr Z3Context::eq(const z3::expr &x, const z3::expr &y) {
    return x == y;
}

z3::expr Z3Context::lt(const z3::expr &x, const z3::expr &y) {
    return x < y;
}

z3::expr Z3Context::le(const z3::expr &x, const z3::expr &y) {
    return x <= y;
}

z3::expr Z3Context::gt(const z3::expr &x, const z3::expr &y) {
    return x > y;
}

z3::expr Z3Context::ge(const z3::expr &x, const z3::expr &y) {
    return x >= y;
}

z3::expr Z3Context::neq(const z3::expr &x, const z3::expr &y) {
    return x != y;
}

z3::expr Z3Context::bAnd(const z3::expr &x, const z3::expr &y) {
    return x && y;
}

z3::expr Z3Context::bOr(const z3::expr &x, const z3::expr &y) {
    return x || y;
}

z3::expr Z3Context::bTrue() const {
    return ctx.bool_val(true);
}

z3::expr Z3Context::bFalse() const {
    return ctx.bool_val(false);
}

z3::expr Z3Context::negate(const z3::expr &x) {
    return !x;
}

void Z3Context::printStderr(const z3::expr &e) const {
    std::cerr << e << std::endl;
}
