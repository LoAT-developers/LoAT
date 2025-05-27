#include "opensmtcontext.hpp"

OpenSmtContext::OpenSmtContext(opensmt::ArithLogic &logic): logic(logic) {}

OpenSmtContext::~OpenSmtContext() {}

opensmt::PTRef OpenSmtContext::getInt(const Int &val) {
    return logic.mkIntConst(opensmt::FastRational(val.str().c_str()));
}

opensmt::PTRef OpenSmtContext::getReal(const Int &num, const Int &denom) {
    return logic.mkIntConst(opensmt::FastRational((num.str() + "/" + denom.str()).c_str()));
}

opensmt::PTRef OpenSmtContext::pow(const opensmt::PTRef &base, const opensmt::PTRef &exp) {
    throw std::invalid_argument("not yet implemented");
}

opensmt::PTRef OpenSmtContext::plus(const std::vector<opensmt::PTRef> &args) {
    return logic.mkPlus(args);
}

opensmt::PTRef OpenSmtContext::times(const std::vector<opensmt::PTRef> &args) {
    return logic.mkTimes(args);
}

opensmt::PTRef OpenSmtContext::mod(const opensmt::PTRef &x, const opensmt::PTRef &y) {
    return logic.mkMod(x, y);
}

opensmt::PTRef OpenSmtContext::eq(const opensmt::PTRef &x, const opensmt::PTRef &y) {
    return logic.mkEq(x, y);
}

opensmt::PTRef OpenSmtContext::lt(const opensmt::PTRef &x, const opensmt::PTRef &y) {
    return logic.mkLt(x, y);
}

opensmt::PTRef OpenSmtContext::le(const opensmt::PTRef &x, const opensmt::PTRef &y) {
    return logic.mkLeq(x, y);
}

opensmt::PTRef OpenSmtContext::gt(const opensmt::PTRef &x, const opensmt::PTRef &y) {
    return logic.mkGt(x, y);
}

opensmt::PTRef OpenSmtContext::ge(const opensmt::PTRef &x, const opensmt::PTRef &y) {
    return logic.mkGeq(x, y);
}

opensmt::PTRef OpenSmtContext::neq(const opensmt::PTRef &x, const opensmt::PTRef &y) {
    return logic.mkDistinct({x, y});
}

opensmt::PTRef OpenSmtContext::bAnd(std::vector<opensmt::PTRef> &args) {
    return logic.mkAnd(args);
}

opensmt::PTRef OpenSmtContext::bOr(std::vector<opensmt::PTRef> &args) {
    return logic.mkOr(args);
}

opensmt::PTRef OpenSmtContext::bTrue() const {
    return logic.getTerm_true();
}

opensmt::PTRef OpenSmtContext::bFalse() const {
    return logic.getTerm_false();
}

opensmt::PTRef OpenSmtContext::negate(const opensmt::PTRef &x) {
    return logic.mkNot(x);
}

std::vector<opensmt::PTRef> OpenSmtContext::exprVec() {
    return std::vector<opensmt::PTRef>{};
}

std::vector<opensmt::PTRef> OpenSmtContext::formulaVec() {
    return std::vector<opensmt::PTRef>{};
}

void OpenSmtContext::printStderr(const opensmt::PTRef &e) const {
    std::cerr << logic.printTerm(e) << std::endl;
}

Arith::Var OpenSmtContext::getArithVar(const opensmt::PTRef x) const {
    return reverseArithVarMap.at(x);
}

Bools::Var OpenSmtContext::getBoolVar(const opensmt::PTRef x) const {
    return reverseBoolVarMap.at(x);
}

opensmt::PTRef OpenSmtContext::buildVar(const Arith::Var &var) {
    const auto res {logic.mkIntVar(var->getName().c_str())};
    reverseArithVarMap.emplace(res, var);
    return res;
}

opensmt::PTRef OpenSmtContext::buildVar(const Bools::Var &var) {
    const auto res {logic.mkBoolVar(var->getName().c_str())};
    reverseBoolVarMap.emplace(res, var);
    return res;
}
