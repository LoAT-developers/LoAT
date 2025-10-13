#include "swinemodel.hpp"
#include "exprconverter.hpp"

SwineModel::SwineModel(const SwineContext& p_ctx, const z3::model& p_model, const Subs& subs) :
    Model(subs),
    m_ctx(p_ctx),
    m_model(p_model) {}

void SwineModel::put(const Arith::Var &var, const Arith::Const& value) {
    const auto converted_var {m_ctx.getArithSymbolMap().at(var)};
    auto decl {converted_var.decl()};
    auto converted_value {m_ctx.getInt(value)};
    m_model.add_const_interp(decl, converted_value);
}

// bool SwineModel::contains(const Arith::Var &var) const {
//     const auto converted_var {m_ctx.getArithSymbolMap().at(var)};
//     const auto decl {converted_var.decl()};
//     return m_model.has_interp(decl);
// }
//
// bool SwineModel::contains(const Bools::Var &var) const {
//     const auto converted_var {m_ctx.getBoolSymbolMap().at(var)};
//     const auto decl {converted_var.decl()};
//     return m_model.has_interp(decl);
// }
//
// bool SwineModel::contains(const Arrays<Arith>::Var &var) const {
//     const auto converted_var {m_ctx.getIntArraySymbolMap().at(var)};
//     const auto decl {converted_var.decl()};
//     return m_model.has_interp(decl);
// }


bool SwineModel::evalImpl(const Lit &lit) {
    return evalImpl(bools::mkLit(lit));
}

Bools::Const SwineModel::evalImpl(const Bools::Expr &e) {
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

std::string SwineModel::toString(const Expr& e) {
    return theory::apply(e, [&](const auto &e) {
        const auto converted {Converter::convert(e, m_ctx)};
        return ::toString(m_model.eval(converted));
    });
}

ModelPtr SwineModel::withSubs(const Subs& subs) const {
    return cpp::assume_not_null(std::make_shared<SwineModel>(m_ctx, m_model, subs));
}
