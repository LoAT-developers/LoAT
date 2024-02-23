#include "numconstant.hpp"

#include <purrs.hh>

NumConstant::NumConstant(const Rational &t): t(t) {}

bool NumConstant::isLinear(const std::optional<linked_hash_set<NumVarPtr>> &vars) const {
    return true;
}

bool NumConstant::isPoly() const {
    return true;
}

std::optional<Int> NumConstant::totalDegree() const {
    return 0;
}

void NumConstant::collectVars(linked_hash_set<NumVarPtr> &res) const {
    return;
}

bool NumConstant::hasVarWith(const std::function<bool(const NumVarPtr)> predicate) const {
    return false;
}

std::optional<Int> NumConstant::degree(const NumVarPtr var) const {
    return 0;
}

Int NumConstant::denomLcm() const {
    return mp::denominator(t);
}

std::optional<Int> NumConstant::isInt() const {
    if (mp::denominator(t) == 1) {
        return mp::numerator(t);
    } else {
        return {};
    }
}

std::optional<Rational> NumConstant::isRational() const {
    return t;
}

std::optional<NumVarPtr> NumConstant::isVar() const {
    return {};
}

std::optional<std::pair<ExprPtr, ExprPtr>> NumConstant::isPow() const {
    return {};
}

const linked_hash_set<ExprPtr>* NumConstant::isMul() const {
    return nullptr;
}

const linked_hash_set<ExprPtr>* NumConstant::isAdd() const {
    return nullptr;
}

bool NumConstant::isPoly(const NumVarPtr n) const {
    return true;
}

std::optional<NumVarPtr> NumConstant::someVar() const {
    return {};
}

std::optional<ExprPtr> NumConstant::coeff(const NumVarPtr var, const Int &degree) const {
    return num_expression::buildConstant(0);
}

std::optional<ExprPtr> NumConstant::lcoeff(const NumVarPtr var) const {
    return num_expression::buildConstant(0);
}

bool NumConstant::isUnivariate(std::optional<NumVarPtr> &) const {
    return false;
}

bool NumConstant::isNotMultivariate(std::optional<NumVarPtr> &) const {
    return true;
}

bool NumConstant::isMultivariate(std::optional<NumVarPtr> &) const {
    return false;
}

bool NumConstant::CacheEqual::operator()(const std::tuple<Rational> &args1, const std::tuple<Rational> &args2) const noexcept {
    return args1 == args2;
}

size_t NumConstant::CacheHash::operator()(const std::tuple<Rational> &args) const noexcept {
    return std::hash<Rational>{}(std::get<0>(args));
}

ExprPtr num_expression::buildConstant(const Rational &r) {
    return NumConstant::cache.from_cache(r);
}

std::pair<Rational, std::optional<ExprPtr>> NumConstant::decompose() const {
    return {t, {}};
}

Rational NumConstant::eval(const std::function<Rational(const NumVarPtr)> &valuation) const {
    return t;
}

bool NumConstant::isIntegral() const {
    return isInt().has_value();
}

Purrs::Expr NumConstant::toPurrs(purrs_var_map &map) const {
    return Purrs::Number(mp::numerator(t).str().c_str()) / Purrs::Number(mp::denominator(t).str().c_str());
}
