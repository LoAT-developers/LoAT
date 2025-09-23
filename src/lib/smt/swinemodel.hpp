#pragma once

#include "model.hpp"
#include "swinecontext.hpp"
#include "exprconverter.hpp"

class SwineModel final : public Model {

    using Converter = ExprConverter<z3::expr, z3::expr, z3::expr_vector, z3::expr_vector>;

public:

    SwineModel(const SwineContext&, const z3::model&);

    void put(const Arith::Var&, const Arith::Const&) override;

    bool contains(const Arith::Var&) const override;
    bool contains(const Bools::Var&) const override;
    bool contains(const Arrays<Arith>::Var&) const override;


    bool eval(const Lit&) override;

    Bools::Const eval(const Bools::Expr&) override;
    Rational evalToRational(const Arith::Expr&) override;

    ModelPtr clone() const override {
        return std::make_shared<SwineModel>(*this);
    }

protected:

    Arith::Const getImpl(const Arith::Var&) override;
    Bools::Const getImpl(const Bools::Var&) override;
    Arith::Const getImpl(const ArrayReadPtr<Arith>&)override;
    void print(std::ostream&) const override;

private:
    SwineContext m_ctx;
    z3::model m_model;
};
