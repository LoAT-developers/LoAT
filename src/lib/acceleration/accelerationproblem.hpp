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
        BoolExpr covered;
        bool nonterm;
    };

    using Res = std::map<Lit, std::vector<Entry>>;

    Res res;
    std::optional<std::map<Lit, Entry>> solution;
    LitSet todo;
    const Subs &samplePoint;
    std::unique_ptr<Smt<IntTheory, BoolTheory>> solver;
    std::optional<Rel> bound;

    bool trivial(const Lit &lit, Proof &proof);
    bool unchanged(const Lit &lit, Proof &proof);
    bool polynomial(const Lit &lit, Proof &proof);
    bool monotonicity(const Lit &lit, Proof &proof);
    bool recurrence(const Lit &lit, Proof &proof);
    bool eventualWeakDecrease(const Lit &lit, Proof &proof);
    bool eventualIncrease(const Lit &lit, const bool strict, Proof &proof);
    bool fixpoint(const Lit &lit, Proof &proof);
    unsigned store(const Lit &lit, const LitSet &deps, const BoolExpr formula, const BoolExpr covered, bool nonterm = false);

    struct ReplacementMap {
        bool nonterm;
        BoolExpr covered;
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
