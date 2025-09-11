#include "swinecontext.hpp"

SwineContext::SwineContext(swine::Swine &solver): ctx(solver.get_ctx()), solver(solver) {}

z3::expr SwineContext::pow(const z3::expr &base, const z3::expr &exp) {
    return solver.get_exp()(base, exp);
}

z3::expr SwineContext::buildVar(const Arith::Var &var) {
    return ctx.int_const(var->getName().c_str());
}

z3::expr SwineContext::buildVar(const Bools::Var &var) {
    return ctx.bool_const(var->getName().c_str());
}

z3::expr SwineContext::buildVar(const Arrays<Arith>::Var &var) {
    const auto ints {ctx.int_sort()};
    auto sort {ctx.array_sort(ints, ints)};
    const auto dim {var->dim()};
    for (unsigned i = 1; i < dim; ++i) {
        sort = ctx.array_sort(ints, sort);
    }
    return ctx.constant(var->getName().c_str(), sort);
}

z3::expr SwineContext::getInt(const Int &val) {
    return ctx.int_val(val.str().c_str());
}

z3::expr SwineContext::getReal(const Int &num, const Int &denom) {
    return ctx.real_val((num.str() + " / " + denom.str()).c_str());
}

z3::expr SwineContext::plus(const z3::expr_vector &args) {
    return z3::sum(args);
}

z3::expr SwineContext::times(const z3::expr_vector &args) {
    auto it {args.begin()};
    z3::expr res {*it};
    for (++it; it != args.end(); ++it) {
        res = res * *it;
    }
    return res;
}

z3::expr SwineContext::mod(const z3::expr &x, const z3::expr &y) {
    return x % y;
}

z3::expr SwineContext::eq(const z3::expr &x, const z3::expr &y) {
    return x == y;
}

z3::expr SwineContext::lt(const z3::expr &x, const z3::expr &y) {
    return x < y;
}

z3::expr SwineContext::le(const z3::expr &x, const z3::expr &y) {
    return x <= y;
}

z3::expr SwineContext::gt(const z3::expr &x, const z3::expr &y) {
    return x > y;
}

z3::expr SwineContext::ge(const z3::expr &x, const z3::expr &y) {
    return x >= y;
}

z3::expr SwineContext::neq(const z3::expr &x, const z3::expr &y) {
    return x != y;
}

z3::expr SwineContext::bAnd(z3::expr_vector &args) {
    return z3::mk_and(args);
}

z3::expr SwineContext::bOr(z3::expr_vector &args) {
    return z3::mk_or(args);
}

z3::expr SwineContext::bTrue() const {
    return ctx.bool_val(true);
}

z3::expr SwineContext::bFalse() const {
    return ctx.bool_val(false);
}

z3::expr SwineContext::negate(const z3::expr &x) {
    return !x;
}

z3::expr_vector SwineContext::exprVec() {
    return {ctx};
}

z3::expr_vector SwineContext::formulaVec() {
    return {ctx};
}

z3::expr SwineContext::arrayRead(const z3::expr& arr, const z3::expr_vector& indices) {
    return z3::select(arr, indices);
}

z3::expr SwineContext::arrayWrite(const z3::expr& arr, const z3::expr_vector& indices, const z3::expr &value) {
    return z3::store(arr, indices, value);
}

void SwineContext::printStderr(const z3::expr &e) const {
    std::cerr << e << std::endl;
}
