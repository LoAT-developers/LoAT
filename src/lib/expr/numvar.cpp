#include "numvar.hpp"
#include "numconstant.hpp"

#include <purrs.hh>
#include <assert.h>

int NumVar::last_tmp_idx {0};
int NumVar::last_prog_idx {1};

const NumVarPtr NumVar::loc_var {nextProgVar()};

ConsHash<Expr, NumVar, NumVar::CacheHash, NumVar::CacheEqual, int> NumVar::cache {};

ExprPtr num_expression::buildVar(const int idx) {
    return NumVar::cache.from_cache(idx);
}

NumVar::NumVar(const int idx): idx(idx) {}

int NumVar::getIdx() const {
    return idx;
}

std::string NumVar::getName() const {
    if (idx > 0) {
        return "i" + std::to_string(idx);
    } else {
        return "it" + std::to_string(-idx);
    }
}

std::ostream& operator<<(std::ostream &s, const NumVar &x) {
    return s << x.getName();
}

NumVarPtr NumVar::next() {
    --last_tmp_idx;
    return (*ne::buildVar(last_tmp_idx)->someVar())->toPtr();
}

NumVarPtr NumVar::nextProgVar() {
    ++last_prog_idx;
    return (*ne::buildVar(last_prog_idx)->someVar())->toPtr();
}

bool NumVar::isTempVar() const {
    return idx < 0;
}

size_t NumVar::hash() const {
    return std::hash<int>{}(idx);
}

std::size_t hash_value(const NumVar &x) {
    return x.hash();
}

bool NumVar::isLinear(const std::optional<linked_hash_set<NumVarPtr>> &vars) const {
    return true;
}

bool NumVar::isPoly() const {
    return true;
}

std::optional<Int> NumVar::totalDegree() const {
    return 1;
}

NumVarPtr NumVar::toPtr() const {
    return std::enable_shared_from_this<NumVar>::shared_from_this();
}

ExprPtr NumVar::toExpr() const {
    return Expr::shared_from_this();
}

void NumVar::collectVars(linked_hash_set<NumVarPtr> &res) const {
    res.emplace(toPtr());
}

bool NumVar::hasVarWith(const std::function<bool(const NumVarPtr)> predicate) const {
    return predicate(toPtr());
}

std::optional<Int> NumVar::degree(const NumVarPtr var) const {
    return toPtr() == var ? 1 : 0;
}

Int NumVar::denomLcm() const {
    return 1;
}

std::optional<Int> NumVar::isInt() const {
    return {};
}

std::optional<Rational> NumVar::isRational() const {
    return {};
}

std::optional<NumVarPtr> NumVar::isVar() const {
    return toPtr();
}

std::optional<std::pair<ExprPtr, ExprPtr>> NumVar::isPow() const {
    return {};
}

const linked_hash_set<ExprPtr>* NumVar::isMul() const {
    return nullptr;
}

const linked_hash_set<ExprPtr>* NumVar::isAdd() const {
    return nullptr;
}

bool NumVar::isPoly(const NumVarPtr n) const {
    return true;
}

std::optional<NumVarPtr> NumVar::someVar() const {
    return toPtr();
}

std::optional<ExprPtr> NumVar::coeff(const NumVarPtr var, const Int &degree) const {
    return degree == 1 && var == toPtr() ? num_expression::buildConstant(1) : num_expression::buildConstant(0);
}

std::optional<ExprPtr> NumVar::lcoeff(const NumVarPtr var) const {
    return coeff(var);
}

bool NumVar::isUnivariate(std::optional<NumVarPtr> &var) const {
    if (!var) {
        var = toPtr();
    }
    return *var == toPtr();
}

bool NumVar::isNotMultivariate(std::optional<NumVarPtr> &var) const {
    return !isUnivariate(var);
}

bool NumVar::isMultivariate(std::optional<NumVarPtr> &var) const {
    return !isUnivariate(var);
}

bool NumVar::CacheEqual::operator()(const std::tuple<int> &args1, const std::tuple<int> &args2) const noexcept {
    return args1 == args2;
}

size_t NumVar::CacheHash::operator()(const std::tuple<int> &args) const noexcept {
    return std::hash<int>{}(std::get<0>(args));
}

std::pair<Rational, std::optional<ExprPtr>> NumVar::decompose() const {
    return {1, {toExpr()}};
}

bool NumVar::isIntegral() const {
    return true;
}

Rational NumVar::eval(const std::function<Rational(const NumVarPtr)> &valuation) const {
    return valuation(toPtr());
}

Purrs::Expr NumVar::toPurrs(purrs_var_map &map) const {
    const auto res {map.left.find(toPtr())};
    if (res == map.left.end()) {
        Purrs::Symbol s {getName()};
        map.left.insert(purrs_var_map::left_value_type(toPtr(), s));
        return s;
    }
    return res->second;
}
