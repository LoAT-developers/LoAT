#pragma once

#include "model.hpp"
#include "swinecontext.hpp"
#include "exprconverter.hpp"

class SwineModel final : public Model {

    using Converter = ExprConverter<z3::expr, z3::expr, z3::expr_vector, z3::expr_vector>;

public:

    SwineModel(const SwineContext&, const z3::model&, const Subs&);

    void put(const Arith::Var&, const Arith::Const&) override;

    bool evalImpl(const Lit&) override;

    Bools::Const evalImpl(const Bools::Expr&) override;
    Rational evalToRational(const Arith::Expr&) override;

    ModelPtr withSubs(const Subs&) const override;

protected:

    Arith::Const getImpl(const Arith::Var&) override;
    Bools::Const getImpl(const Bools::Var&) override;
    Arith::Const getImpl(const ArrayReadPtr<Arith>&) override;
    std::string toString(const Expr&) override;

private:
    SwineContext m_ctx;
    z3::model m_model;
};
