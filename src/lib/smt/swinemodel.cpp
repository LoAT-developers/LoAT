#include "swinemodel.hpp"
#include "exprconverter.hpp"

SwineModel::SwineModel(const SwineContext& p_ctx, const z3::model& p_model): m_ctx(p_ctx), m_model(p_model) {}

void SwineModel::put(const Arith::Var &var, const Arith::Const& value) {
    const auto converted_var {m_ctx.getArithSymbolMap().at(var)};
    auto decl {converted_var.decl()};
    auto converted_value {m_ctx.getInt(value)};
    m_model.add_const_interp(decl, converted_value);
}

bool SwineModel::contains(const Arith::Var &var) const {
    const auto converted_var {m_ctx.getArithSymbolMap().at(var)};
    const auto decl {converted_var.decl()};
    return m_model.has_interp(decl);
}

bool SwineModel::contains(const Bools::Var &var) const {
    const auto converted_var {m_ctx.getBoolSymbolMap().at(var)};
    const auto decl {converted_var.decl()};
    return m_model.has_interp(decl);
}

bool SwineModel::contains(const Arrays<Arith>::Var &var) const {
    const auto converted_var {m_ctx.getIntArraySymbolMap().at(var)};
    const auto decl {converted_var.decl()};
    return m_model.has_interp(decl);
}


bool SwineModel::eval(const Lit &lit) {
    return eval(bools::mkLit(lit));
}

Bools::Const SwineModel::eval(const Bools::Expr &e) {
    const auto converted {Converter::convert(e, m_ctx)};
    const auto res {m_model.eval(converted)};
    assert(res.is_bool());
    return res.is_true();
}

Rational SwineModel::evalToRational(const Arith::Expr &e) {
    const auto converted {Converter::convert(e, m_ctx)};
    const auto res {m_model.eval(converted)};
    assert(res.is_real());
    return Rational(res.numerator().to_string(), res.denominator().to_string());
}

Arith::Const SwineModel::getImpl(const Arith::Var &var) {
    const auto converted_var {m_ctx.getArithSymbolMap().at(var)};
    const auto res {m_model.eval(converted_var)};
    assert(res.is_int());
    return Int(res.to_string());
}

Bools::Const SwineModel::getImpl(const Bools::Var &var) {
    const auto converted_var {m_ctx.getBoolSymbolMap().at(var)};
    const auto res {m_model.eval(converted_var)};
    assert(res.is_bool());
    return res.is_true();
}

Arith::Const SwineModel::getImpl(const ArrayReadPtr<Arith> &read) {
    const auto converted {Converter::convert(read, m_ctx)};
    const auto res {m_model.eval(converted)};
    assert(res.is_int());
    return Int(res.to_string());
}

void SwineModel::print(std::ostream &s) const {
    s << m_model.to_string();
}
