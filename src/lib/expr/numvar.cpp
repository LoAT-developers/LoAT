#include "numexpression.hpp"

#include <purrs.hh>
#include <assert.h>

int NumVar::last_tmp_idx {0};
int NumVar::last_prog_idx {1};

const NumVarPtr NumVar::loc_var {nextProgVar()};

ConsHash<Expr, NumVar, NumVar::CacheHash, NumVar::CacheEqual, int> NumVar::cache {};

ExprPtr num_expression::buildVar(const int idx) {
    return NumVar::cache.from_cache(idx);
}

NumVar::NumVar(const int idx): Expr(ne::Kind::Variable), idx(idx) {}

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

NumVarPtr NumVar::toPtr() const {
    return std::enable_shared_from_this<NumVar>::shared_from_this();
}

ExprPtr NumVar::toExpr() const {
    return Expr::shared_from_this();
}

bool NumVar::CacheEqual::operator()(const std::tuple<int> &args1, const std::tuple<int> &args2) const noexcept {
    return args1 == args2;
}

size_t NumVar::CacheHash::operator()(const std::tuple<int> &args) const noexcept {
    return std::hash<int>{}(std::get<0>(args));
}

