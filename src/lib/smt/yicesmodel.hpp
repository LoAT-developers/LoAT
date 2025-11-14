#pragma once

#include "model.hpp"
#include "yicescontext.hpp"
#include "exprconverter.hpp"

class YicesModel final: public Model {

    using Converter = ExprConverter<term_t, term_t, std::vector<term_t>, std::vector<term_t>>;

    Rational evalToRationalImpl(const Arith::Expr&) override;
    ModelPtr withSubs(const Subs&) const override;

public:

    YicesModel(const YicesContext&, const std::shared_ptr<model_t>&, const Subs&);

protected:

    bool evalImpl(const Lit&) override;
    Bools::Const evalImpl(const Bools::Expr&) override;
    Bools::Const getImpl(const Bools::Var&) override;
    std::string toString(const Expr&) override;

private:

    Rational toRational(term_t t) const;
    Int toInt(term_t t) const;

    YicesContext m_ctx;
    std::shared_ptr<model_t> m_model;

};
