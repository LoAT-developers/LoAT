#pragma once

#include <optional>

#include "rule.hpp"
#include "variablemanager.hpp"
#include "proof.hpp"
#include "smt.hpp"
#include "accelerationtechnique.hpp"
#include "theory.hpp"

class AccelerationProblem: public AccelerationTechnique<IntTheory, BoolTheory>  {

    using AcceleratorPair = AccelerationTechnique<IntTheory, BoolTheory>::AcceleratorPair;

    struct Entry {
        LitSet dependencies;
        BoolExpr formula;
        bool exact;
        bool nonterm;
    };

    using Res = std::map<Lit, std::vector<Entry>>;

    Res res;
    std::optional<std::map<Lit, Entry>> solution;
    LitSet todo;
    const Subs &samplePoint;
    std::unique_ptr<Smt<IntTheory, BoolTheory>> solver;
    std::optional<Rel> bound;

    BoolExpr polynomial(const Lit &lit, Proof &proof);
    BoolExpr monotonicity(const Lit &lit, Proof &proof);
    BoolExpr recurrence(const Lit &lit, Proof &proof);
    BoolExpr eventualWeakDecrease(const Lit &lit, Proof &proof);
    BoolExpr eventualIncrease(const Lit &lit, const bool strict, Proof &proof);
    BoolExpr fixpoint(const Lit &lit, Proof &proof);
    std::optional<unsigned int> store(const Lit &lit, const LitSet &deps, const BoolExpr formula, bool exact = true, bool nonterm = false);

    struct ReplacementMap {
        bool nonterm;
        bool exact;
        std::map<Lit, BoolExpr> map;
    };

    std::optional<ReplacementMap> computeReplacementMap(bool nontermOnly) const;

public:

    AccelerationProblem(
            const Rule &rule,
            const std::optional<Recurrence::Result> &closed,
            const Subs &samplePoint,
            VarMan &its,
            const AccelConfig &config);

    AcceleratorPair computeRes();
    std::pair<BoolExpr, bool> buildRes(const Model<IntTheory, BoolTheory> &model, const std::map<Lit, std::vector<BoolExpr>> &entryVars);

private:

    bool depsWellFounded(const Lit& lit, bool nontermOnly) const;
    bool depsWellFounded(const Lit& lit, std::map<Lit, const AccelerationProblem::Entry*> &entryMap, bool nontermOnly, LitSet seen = {}) const;

};
