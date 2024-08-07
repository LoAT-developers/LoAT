#include "arithexpr.hpp"
#include "sexpresso.hpp"

#include <assert.h>

int ArithVar::last_tmp_idx {0};
int ArithVar::last_prog_idx {1};

ConsHash<ArithExpr, ArithVar, ArithVar::CacheHash, ArithVar::CacheEqual, int> ArithVar::cache {};

ArithExprPtr arith::mkVar(const int idx) {
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

ArithVarPtr ArithVar::next() {
    --last_tmp_idx;
    return (*arith::mkVar(last_tmp_idx)->someVar())->toPtr();
}

ArithVarPtr ArithVar::nextProgVar() {
    last_prog_idx += 2;
    return (*arith::mkVar(last_prog_idx)->someVar())->toPtr();
}

ArithVarPtr ArithVar::postVar(const ArithVarPtr &x) {
    return (*arith::mkVar(x->getIdx() + 1)->someVar())->toPtr();
}

ArithVarPtr ArithVar::progVar(const ArithVarPtr &x) {
    return (*arith::mkVar(x->getIdx() - 1)->someVar())->toPtr();
}

bool ArithVar::isTempVar() const {
    return idx < 0;
}

bool ArithVar::isProgVar() const {
    return idx > 0 && idx % 2 == 1;
}

bool ArithVar::isPostVar() const {
    return idx > 0 && idx % 2 == 0;
}

size_t ArithVar::hash() const {
    return std::hash<int>{}(idx);
}

std::size_t hash_value(const ArithVar &x) {
    return x.hash();
}

ArithVarPtr ArithVar::toPtr() const {
    return cpp::assume_not_null(std::static_pointer_cast<const ArithVar>(shared_from_this()));
}

ArithExprPtr ArithVar::toExpr() const {
    return cpp::assume_not_null(shared_from_this());
}

sexpresso::Sexp ArithVar::to_smtlib() const {
    return sexpresso::Sexp(getName());
}

bool ArithVar::CacheEqual::operator()(const std::tuple<int> &args1, const std::tuple<int> &args2) const noexcept {
    return args1 == args2;
}

size_t ArithVar::CacheHash::operator()(const std::tuple<int> &args) const noexcept {
    return std::hash<int>{}(std::get<0>(args));
}

