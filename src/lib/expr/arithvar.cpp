#include "arithexpr.hpp"
#include "arrayexpr.hpp"
#include "sexpresso.hpp"

ConsHash<ArithExpr, ArithVar, ArithVar::CacheHash, ArithVar::CacheEqual, ArrayReadPtr<Arith>> ArithVar::cache {};

ArithExprPtr arith::mkVar(const ArrayReadPtr<Arith>& p_arr) {
    return ArithVar::cache.from_cache(p_arr);
}

ArithVar::ArithVar(const ArrayReadPtr<Arith>& p_arr): ArithExpr(arith::Kind::Variable), m_arr(p_arr) {}

ArithVar::~ArithVar() {
    cache.erase(m_arr);
}

ArithVarPtr ArithVar::next() {
    return *arith::mkVar(arrays::mkArrayRead<Arith>(ArrayVar<Arith>::next(0), {}))->someVar();
}

ArithVarPtr ArithVar::nextProgVar() {
    return *arith::mkVar(arrays::mkArrayRead<Arith>(ArrayVar<Arith>::nextProgVar(0), {}))->someVar();
}

ArithVarPtr ArithVar::postVar() const {
    return *arith::mkVar(m_arr->withVar(m_arr->arr()->var()->postVar()))->someVar();
}

ArithVarPtr ArithVar::progVar() const {
    return *arith::mkVar(m_arr->withVar(m_arr->arr()->var()->progVar()))->someVar();
}

bool ArithVar::isTempVar() const {
    return m_arr->arr()->var()->isTempVar();
}

bool ArithVar::isProgVar() const {
    return m_arr->arr()->var()->isProgVar();
}

bool ArithVar::isPostVar() const {
    return m_arr->arr()->var()->isPostVar();
}

ArithVarPtr ArithVar::toVarPtr() const {
    return cpp::assume_not_null(std::static_pointer_cast<const ArithVar>(shared_from_this()));
}

ArithExprPtr ArithVar::toExpr() const {
    return cpp::assume_not_null(shared_from_this());
}

sexpresso::Sexp ArithVar::to_smtlib() const {
    return m_arr->to_smtlib();
}

unsigned ArithVar::dim() const {
    return m_arr->arr()->var()->dim();
}

ArrayReadPtr<Arith> ArithVar::arr() const {
    return m_arr;
}

std::string ArithVar::getName() const {
    return m_arr->arr()->var()->getName();
}

bool ArithVar::CacheEqual::operator()(const std::tuple<ArrayReadPtr<Arith>> &args1, const std::tuple<ArrayReadPtr<Arith>> &args2) const noexcept {
    return args1 == args2;
}

size_t ArithVar::CacheHash::operator()(const std::tuple<ArrayReadPtr<Arith>> &args) const noexcept {
    return std::hash<ArrayReadPtr<Arith>>{}(std::get<0>(args));
}
