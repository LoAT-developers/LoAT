#include "crabcontext.hpp"

bool CrabConjunction::isTrue() const {
    return constraints.empty() && positive_lits.empty() && negative_lits.empty();
}

size_t CrabConjunction::size() const {
    return constraints.size() + positive_lits.size() + negative_lits.size();
}

CrabContext::CrabContext() {}

CrabContext::~CrabContext() {}

z_lin_exp_t CrabContext::getInt(const Int &val) {
    return ikos::z_number(toString(val));
}

z_lin_exp_t CrabContext::getReal(const Int &num, const Int &denom) {
    throw std::invalid_argument("crabcontext::getReal not supported");
}

z_lin_exp_t CrabContext::pow(const z_lin_exp_t &base, const z_lin_exp_t &exp) {
    throw std::invalid_argument("crabcontext::pow not supported");
}

z_lin_exp_t CrabContext::plus(const z_lin_exp_t &x, const z_lin_exp_t &y) {
    return x + y;
}

z_lin_exp_t CrabContext::times(const z_lin_exp_t &x, const z_lin_exp_t &y) {
    if (x.is_constant()) {
        return x.constant() * y;
    } else if (y.is_constant()) {
        return x * y.constant();
    } else {
        throw std::invalid_argument("crabcontext::times with non-constant arguments not supported");
    }
}

z_lin_exp_t CrabContext::mod(const z_lin_exp_t &x, const z_lin_exp_t &y) {
    throw std::invalid_argument("crabcontext::mod not supported");
}

CrabConjunction CrabContext::eq(const z_lin_exp_t &x, const z_lin_exp_t &y) {
    return {.constraints = {x == y}};
}

CrabConjunction CrabContext::lt(const z_lin_exp_t &x, const z_lin_exp_t &y) {
    return {.constraints = {x < y}};
}

CrabConjunction CrabContext::le(const z_lin_exp_t &x, const z_lin_exp_t &y) {
    return {.constraints = {x <= y}};
}

CrabConjunction CrabContext::gt(const z_lin_exp_t &x, const z_lin_exp_t &y) {
    return {.constraints = {x > y}};
}

CrabConjunction CrabContext::ge(const z_lin_exp_t &x, const z_lin_exp_t &y) {
    return {.constraints = {x >= y}};
}

CrabConjunction CrabContext::neq(const z_lin_exp_t &x, const z_lin_exp_t &y) {
    return {.constraints = {x != y}};
}

CrabConjunction CrabContext::bAnd(const CrabConjunction &x, const CrabConjunction &y) {
    CrabConjunction res{.constraints = x.constraints, .positive_lits = x.positive_lits, .negative_lits = x.negative_lits};
    res.constraints.insert(res.constraints.end(), y.constraints.begin(), y.constraints.end());
    res.positive_lits.insert(res.positive_lits.end(), y.positive_lits.begin(), y.positive_lits.end());
    res.negative_lits.insert(res.negative_lits.end(), y.negative_lits.begin(), y.negative_lits.end());
    return res;
}

CrabConjunction CrabContext::bOr(const CrabConjunction &x, const CrabConjunction &y) {
    throw std::invalid_argument("crabcontext::bOr not supported");
}

CrabConjunction CrabContext::bTrue() const {
    return {};
}

CrabConjunction CrabContext::bFalse() const {
    return {.constraints = {z_lin_cst_t::get_false()}};
}

CrabConjunction CrabContext::negate(const CrabConjunction &x) {
    if (x.isTrue()) {
        return bFalse();
    } else if (x.size() == 1) {
        if (x.constraints.size() == 1) {
            return {.constraints = {x.constraints.begin()->negate()}};
        } else {
            return {.positive_lits = x.negative_lits, .negative_lits = x.positive_lits};
        }
    } else {
        throw std::invalid_argument("crabcontext::negate with more than one argument not supported");
    }
}

void CrabContext::printStderr(const z_lin_exp_t &e) const {
    e.write(crab::errs());
}

z_lin_exp_t CrabContext::buildVar(const Arith::Var &x) {
    const auto name{vfac[x->getName()]};
    return z_lin_exp_t(z_var(name, crab::INT_TYPE, 32));
}

CrabConjunction CrabContext::buildVar(const Bools::Var &x) {
    const auto name{vfac[x->getName()]};
    return {.positive_lits = {z_var(name, crab::BOOL_TYPE)}};
}

variable_factory_t& CrabContext::getVfac() {
    return vfac;
}