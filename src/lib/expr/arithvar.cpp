#include "arithexpr.hpp"
#include "arrayexpr.hpp"
#include "sexpresso.hpp"

ConsHash<ArithExpr, ArithVar, ArithVar::CacheHash, ArithVar::CacheEqual, int> ArithVar::cache {};

ArithExprPtr arith::mkVar(const int idx) {
    return ArithVar::cache.from_cache(idx);
}

ArithVar::ArithVar(const int idx): ArithExpr(arith::Kind::Variable), arr(arrays::mkArrayRead(arrays::mkVar<Arith>(idx, 0), {})) {}

ArithVar::~ArithVar() {
    cache.erase(getIdx());
}

int ArithVar::getIdx() const {
    return arr->arr()->var()->idx();
}

std::string ArithVar::getName() const {
    return arr->arr()->var()->getName();
}

std::ostream& operator<<(std::ostream &s, const ArithVar &x) {
    return s << x.getName();
}

ArithVarPtr ArithVar::next() {
    --ArrayVar<Arith>::last_tmp_idx;
    return (*arith::mkVar(ArrayVar<Arith>::last_tmp_idx)->someVar())->toVarPtr();
}

ArithVarPtr ArithVar::nextProgVar() {
    ArrayVar<Arith>::last_prog_idx += 2;
    return (*arith::mkVar(ArrayVar<Arith>::last_prog_idx)->someVar())->toVarPtr();
}

ArithVarPtr ArithVar::postVar(const ArithVarPtr &x) {
    return (*arith::mkVar(x->getIdx() + 1)->someVar())->toVarPtr();
}

ArithVarPtr ArithVar::progVar(const ArithVarPtr &x) {
    return (*arith::mkVar(x->getIdx() - 1)->someVar())->toVarPtr();
}

bool ArithVar::isTempVar() const {
    return getIdx() < 0;
}

bool ArithVar::isProgVar() const {
    return getIdx() > 0 && getIdx() % 2 == 1;
}

bool ArithVar::isPostVar() const {
    return getIdx() > 0 && getIdx() % 2 == 0;
}

std::size_t hash_value(const ArithVar &x) {
    return std::hash<int>{}(x.getIdx());
}

ArithVarPtr ArithVar::toVarPtr() const {
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

