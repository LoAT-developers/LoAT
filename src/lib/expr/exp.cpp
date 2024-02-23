#include "exp.hpp"
#include "numconstant.hpp"

#include <purrs.hh>

Exp::Exp(const ExprPtr base, const ExprPtr exponent): base(base), exponent(exponent) {}

bool Exp::isLinear(const std::optional<linked_hash_set<NumVarPtr>> &vars) const {
    const auto contains {[&vars](const auto &x) {
            return !vars || vars->contains(x);
    }};
    return !base->hasVarWith(contains) && !exponent->hasVarWith(contains);
}

bool Exp::isPoly() const {
    return exponent->isInt().has_value();
}

std::optional<Int> Exp::totalDegree() const {
    const auto exp {exponent->isInt()};
    if (exp) {
        const auto base_degree {base->totalDegree()};
        if (base_degree) {
            return *base_degree * *exp;
        }
    }
    return {};
}

void Exp::collectVars(linked_hash_set<NumVarPtr> &res) const {
    base->collectVars(res);
    exponent->collectVars(res);
}

bool Exp::hasVarWith(const std::function<bool(const NumVarPtr)> predicate) const {
    return base->hasVarWith(predicate) || exponent->hasVarWith(predicate);
}

std::optional<Int> Exp::degree(const NumVarPtr var) const {
    if (!has(var)) {
        return 0;
    }
    const auto exp {exponent->isInt()};
    if (exp) {
        const auto base_degree {base->degree(var)};
        if (base_degree) {
            return *base_degree * *exp;
        }
    }
    return {};
}

Int Exp::denomLcm() const {
    return 1;
}

std::optional<Int> Exp::isInt() const {
    return {};
}

std::optional<Rational> Exp::isRational() const {
    return {};
}

std::optional<NumVarPtr> Exp::isVar() const {
    return {};
}

std::optional<std::pair<ExprPtr, ExprPtr>> Exp::isPow() const {
    return {{base, exponent}};
}

const linked_hash_set<ExprPtr>* Exp::isMul() const {
    return nullptr;
}

const linked_hash_set<ExprPtr>* Exp::isAdd() const {
    return nullptr;
}

bool Exp::isPoly(const NumVarPtr n) const {
    return exponent->isInt() || !base->has(n);
}

std::optional<NumVarPtr> Exp::someVar() const {
    auto res {base->someVar()};
    return res ? res : exponent->someVar();
}

std::optional<ExprPtr> Exp::coeff(const NumVarPtr var, const Int &degree) const {
    if (base->isVar() == std::optional{var} && exponent->isInt() == std::optional{degree}) {
        return num_expression::buildConstant(1);
    }
    if (isPoly(var)) {
        return num_expression::buildConstant(0);
    }
    return {};
}

std::optional<ExprPtr> Exp::lcoeff(const NumVarPtr var) const {
    if (isPoly(var)) {
        return num_expression::buildConstant(1);
    }
    return {};
}

bool Exp::isUnivariate(std::optional<NumVarPtr> &x) const {
    return base->isUnivariate(x) && exponent->isUnivariate(x);
}

bool Exp::isNotMultivariate(std::optional<NumVarPtr> &x) const {
    return base->isNotMultivariate(x) && exponent->isNotMultivariate(x);
}

bool Exp::isMultivariate(std::optional<NumVarPtr> &x) const {
    return base->isMultivariate(x) || exponent->isMultivariate(x);
}

bool Exp::CacheEqual::operator()(const std::tuple<ExprPtr, ExprPtr> &args1, const std::tuple<ExprPtr, ExprPtr> &args2) const noexcept {
    return args1 == args2;
}

size_t Exp::CacheHash::operator()(const std::tuple<ExprPtr, ExprPtr> &args) const noexcept {
    size_t hash {0};
    boost::hash_combine(hash, std::get<0>(args));
    boost::hash_combine(hash, std::get<1>(args));
    return hash;
}

std::pair<Rational, std::optional<ExprPtr>> Exp::decompose() const {
    return {1, {shared_from_this()}};
}

ExprPtr num_expression::buildExp(const ExprPtr base, const ExprPtr exponent) {
    const auto b_val {base->isInt()};
    const auto e_val {exponent->isInt()};
    if (b_val && e_val) {
        return buildConstant(mp::pow(*b_val, std::stoi(e_val->str())));
    }
    if (exponent->is(0) || base->is(1)) {
        return buildConstant(1);
    }
    if (exponent->is(1)) {
        return base;
    }
    auto b {base->isPow()};
    if (b) {
        return buildExp(b->first, b->second * exponent);
    }
    if (!base->isIntegral() || !exponent->isIntegral()) {
        throw std::invalid_argument("attempt to create exp with non-int arguments");
    }
    return Exp::cache.from_cache(base, exponent);
}

bool Exp::isIntegral() const {
    return true;
}

Rational Exp::eval(const std::function<Rational(const NumVarPtr)> &valuation) const {
    return mp::pow(mp::numerator(base->eval(valuation)), std::stoi(exponent->eval(valuation).str()));
}

Purrs::Expr Exp::toPurrs(purrs_var_map &map) const {
    return Purrs::pwr(base->toPurrs(map), exponent->toPurrs(map));
}
