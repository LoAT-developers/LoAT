#include "swinecontext.hpp"

SwineContext::SwineContext(std::shared_ptr<z3::context> &p_ctx, const z3::func_decl &p_exp): m_ctx(p_ctx), m_exp(p_exp) {}

z3::expr SwineContext::pow(const z3::expr &base, const z3::expr &exp) {
    return m_exp(base, exp);
}

z3::expr SwineContext::buildVar(const Bools::Var &var) {
    return m_ctx->bool_const(var->getName().c_str());
}

z3::expr SwineContext::buildVar(const Arrays<Arith>::Var &var) {
    const auto ints {m_ctx->int_sort()};
    const auto dim {var->dim()};
    if (dim == 0) {
        return m_ctx->constant(var->getName().c_str(), ints);
    }
    z3::sort_vector domain {*m_ctx};
    for (unsigned i = 0; i < dim; ++i) {
        domain.push_back(ints);
    }
    return m_ctx->constant(var->getName().c_str(), m_ctx->array_sort(domain, ints));
}

z3::expr SwineContext::getInt(const Int &val) {
    return m_ctx->int_val(val.str().c_str());
}

z3::expr SwineContext::getReal(const Int &num, const Int &denom) {
    return m_ctx->real_val((num.str() + " / " + denom.str()).c_str());
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
    return m_ctx->bool_val(true);
}

z3::expr SwineContext::bFalse() const {
    return m_ctx->bool_val(false);
}

z3::expr SwineContext::negate(const z3::expr &x) {
    return !x;
}

z3::expr_vector SwineContext::exprVec() {
    return {*m_ctx};
}

z3::expr_vector SwineContext::formulaVec() {
    return {*m_ctx};
}

z3::expr SwineContext::arrayRead(const z3::expr& arr, const z3::expr_vector& indices) {
    return z3::select(arr, indices);
}

z3::expr SwineContext::arrayWrite(const z3::expr& arr, const z3::expr_vector& indices, const z3::expr &value) {
    return z3::store(arr, indices, value);
}

z3::expr SwineContext::ite(const z3::expr& cond, const z3::expr& then_case, const z3::expr& else_case) {
    return z3::ite(cond, then_case, else_case);
}

z3::expr SwineContext::lambda(const z3::expr_vector& args, const z3::expr& body) {
    return z3::lambda(args, body);
}

void SwineContext::printStderr(const z3::expr &e) const {
    std::cerr << e << std::endl;
}
