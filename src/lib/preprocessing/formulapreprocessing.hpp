#pragma once

#include "subs.hpp"
#include "theory.hpp"

class AbstractFormulaPreprocessor {

protected:

    Bools::Expr in;

    explicit AbstractFormulaPreprocessor(const Bools::Expr&);

public:
    virtual ~AbstractFormulaPreprocessor() = default;

    virtual Bools::Expr process() = 0;
    virtual ModelPtr transform_model(const ModelPtr& model) = 0;

};

class EquivalencePropagator: public AbstractFormulaPreprocessor {

    Subs subs;

public:
    explicit EquivalencePropagator(const Bools::Expr&);

    Bools::Expr process() override;
    ModelPtr transform_model(const ModelPtr& model) override;

};

class EqualityPropagator: public AbstractFormulaPreprocessor {

    Subs subs;
    std::function<bool(const Var&)> allow;

public:
    explicit EqualityPropagator(const Bools::Expr& in, const std::function<bool(const Var&)>& allow);

    Bools::Expr process() override;
    ModelPtr transform_model(const ModelPtr& model) override;

};

class AndSimplifier: public AbstractFormulaPreprocessor {

public:
    explicit AndSimplifier(const Bools::Expr&);

    Bools::Expr process() override;
    ModelPtr transform_model(const ModelPtr& model) override;

};

class OrSimplifier: public AbstractFormulaPreprocessor {

public:
    explicit OrSimplifier(const Bools::Expr&);

    Bools::Expr process() override;
    ModelPtr transform_model(const ModelPtr& model) override;

};

class IntegerFourierMotzkin: public AbstractFormulaPreprocessor {

    std::vector<std::pair<ArithVarPtr, std::vector<Arith::Expr>>> lower_bound_map;
    std::function<bool(const Var&)> allow;

public:
    explicit IntegerFourierMotzkin(const Bools::Expr&, const std::function<bool(const Var&)>& allow);

    Bools::Expr process() override;
    ModelPtr transform_model(const ModelPtr& model) override;

};

class FormulaPreprocessor: public AbstractFormulaPreprocessor {

    std::vector<std::unique_ptr<AbstractFormulaPreprocessor>> procs;
    std::function<bool(const Var&)> allow;

public:
    explicit FormulaPreprocessor(const Bools::Expr& in, const std::function<bool(const Var&)>& allow);

    Bools::Expr process() override;
    ModelPtr transform_model(const ModelPtr& model) override;
};

namespace Preprocess {
    Bools::Expr preprocessFormula(
        Bools::Expr,
        const std::function<bool(const Var&)>& allow = theory::isTempVar);

    std::tuple<Bools::Expr, Renaming, Renaming> chain(const Bools::Expr &fst, const Bools::Expr &snd);
}
