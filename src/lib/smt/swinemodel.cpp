#include "swinemodel.hpp"

#include <boost/algorithm/string/predicate.hpp>

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

bool SwineModel::evalImpl(const Lit &lit) {
    return evalImpl(bools::mkLit(lit));
}

Bools::Const SwineModel::evalImpl(const Bools::Expr &e) {
    const auto converted {Converter::convert(e, m_ctx)};
    const auto res {m_model.eval(converted, true)};
    assert(res.is_bool());
    return res.is_true();
}

Rational SwineModel::evalToRational(const Arith::Expr &e) {
    const auto converted {Converter::convert(e, m_ctx)};
    const auto res {m_model.eval(converted, true)};
    assert(res.is_numeral());
    auto num_str {res.numerator().to_string()};
    auto den_str {res.denominator().to_string()};
    auto negative {false};
    if (boost::starts_with(num_str, "(-")) {
        negative = true;
        num_str = ((-res.numerator()).simplify()).to_string();
    }
    if (boost::starts_with(den_str, "(-")) {
        negative = !negative;
        den_str = ((-res.denominator()).simplify()).to_string();
    }
    Rational ret {num_str, den_str};
    return negative ? -ret : ret;
}

Arith::Const SwineModel::getImpl(const Arith::Var &var) {
    const auto converted_var {m_ctx.getArithSymbolMap().at(var)};
    const auto res {m_model.eval(converted_var, true)};
    assert(res.is_int());
    return Int(res.to_string());
}

Bools::Const SwineModel::getImpl(const Bools::Var &var) {
    const auto converted_var {m_ctx.getBoolSymbolMap().at(var)};
    const auto res {m_model.eval(converted_var, true)};
    assert(res.is_bool());
    return res.is_true();
}

Arith::Const SwineModel::getImpl(const ArrayReadPtr<Arith> &read) {
    const auto converted {Converter::convert(read, m_ctx)};
    const auto res {m_model.eval(converted, true)};
    assert(res.is_int());
    return Int(res.to_string());
}

std::string SwineModel::toString(const Expr& e) {
    return theory::apply(e, [&](const auto &e) {
        const auto converted {Converter::convert(e, m_ctx)};
        return ::toString(m_model.eval(converted, true));
    });
}

ModelPtr SwineModel::withSubs(const Subs& subs) const {
    return cpp::assume_not_null(std::make_shared<SwineModel>(m_ctx, m_model, subs));
}
