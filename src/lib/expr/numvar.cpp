#include "arithexpr.hpp"

#include <purrs.hh>
#include <assert.h>

int ArithVar::last_tmp_idx {0};
int ArithVar::last_prog_idx {1};

const NumVarPtr ArithVar::loc_var {nextProgVar()};

ConsHash<ArithExpr, ArithVar, ArithVar::CacheHash, ArithVar::CacheEqual, int> ArithVar::cache {};

ExprPtr arith::mkVar(const int idx) {
    return ArithVar::cache.from_cache(idx);
}

ArithVar::ArithVar(const int idx): ArithExpr(arith::Kind::Variable), idx(idx) {}

int ArithVar::getIdx() const {
    return idx;
}

std::string ArithVar::getName() const {
    if (idx > 0) {
        return "i" + std::to_string(idx);
    } else {
        return "it" + std::to_string(-idx);
    }
}

std::ostream& operator<<(std::ostream &s, const ArithVar &x) {
    return s << x.getName();
}

NumVarPtr ArithVar::next() {
    --last_tmp_idx;
    return (*arith::mkVar(last_tmp_idx)->someVar())->toPtr();
}

NumVarPtr ArithVar::nextProgVar() {
    ++last_prog_idx;
    return (*arith::mkVar(last_prog_idx)->someVar())->toPtr();
}

bool ArithVar::isTempVar() const {
    return idx < 0;
}

size_t ArithVar::hash() const {
    return std::hash<int>{}(idx);
}

std::size_t hash_value(const ArithVar &x) {
    return x.hash();
}

NumVarPtr ArithVar::toPtr() const {
    return std::enable_shared_from_this<ArithVar>::shared_from_this();
}

ExprPtr ArithVar::toExpr() const {
    return ArithExpr::shared_from_this();
}

bool ArithVar::CacheEqual::operator()(const std::tuple<int> &args1, const std::tuple<int> &args2) const noexcept {
    return args1 == args2;
}

size_t ArithVar::CacheHash::operator()(const std::tuple<int> &args) const noexcept {
    return std::hash<int>{}(std::get<0>(args));
}

