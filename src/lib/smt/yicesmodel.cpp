#include "yicesmodel.hpp"

YicesModel::YicesModel(const YicesContext& p_ctx, const std::shared_ptr<model_t>& p_model, const Subs& subs) :
    Model(subs),
    m_ctx(p_ctx),
    m_model(p_model) {}

void YicesModel::put(const Arith::Var& x, const Arith::Const& y) {
    mpz_t val;
    mpz_init(val);
    const auto str {y.str()};
    mpz_set_str(val, str.c_str(), str.size());
    yices_model_set_mpz(m_model.get(), m_ctx.getVariable(x), val);
    mpz_clear(val);
}

Rational YicesModel::toRational(const term_t t) const {
    mpq_t val;
    mpz_t num;
    mpz_t denom;
    mpq_init(val);
    mpz_init(num);
    mpz_init(denom);
    yices_get_mpq_value(m_model.get(), t, val);
    mpq_get_num(num, val);
    mpq_get_den(denom, val);
    char num_str[32];
    char denom_str[32];
    mpz_get_str(num_str, 32, num);
    mpz_get_str(denom_str, 32, denom);
    Rational res{num_str, denom_str};
    mpq_clear(val);
    mpz_clear(num);
    mpz_clear(denom);
    return res;
}

Int YicesModel::toInt(const term_t t) const {
    mpz_t val;
    mpz_init(val);
    yices_get_mpz_value(m_model.get(), t, val);
    char val_str[32];
    mpz_get_str(val_str, 32, val);
    Int res{val_str};
    mpz_clear(val);
    return res;
}

Rational YicesModel::evalToRational(const Arith::Expr& e) {
    return toRational(Converter::convert(e, m_ctx));
}

ModelPtr YicesModel::withSubs(const Subs& subs) const {
    return cpp::assume_not_null(std::make_shared<YicesModel>(m_ctx, m_model, subs));
}

bool YicesModel::evalImpl(const Lit& lit) {
    return evalImpl(bools::mkLit(lit));
}

Bools::Const YicesModel::evalImpl(const Bools::Expr& e) {
    const auto t {Converter::convert(e, m_ctx)};
    int32_t res;
    yices_get_bool_value(m_model.get(), t, &res);
    return res;
}

Arith::Const YicesModel::getImpl(const Arith::Var& e) {
    return toInt(Converter::convert(e, m_ctx));
}

Bools::Const YicesModel::getImpl(const Bools::Var& e) {
    int32_t res;
    const auto t {m_ctx.getVariable(e)};
    yices_get_bool_value(m_model.get(), t, &res);
    return res;
}

Arith::Const YicesModel::getImpl(const ArrayReadPtr<Arith>& cell) {
    return toInt(Converter::convert(cell, m_ctx));
}

void YicesModel::print(std::ostream& s, const Expr& e) {
    theory::apply(e, [&](const auto& e) {
        const auto t{Converter::convert(e, m_ctx)};
        char* str{yices_term_to_string(t, 120, 40, 0)};
        s << str;
        yices_free_string(str);
    });
}
