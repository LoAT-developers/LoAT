#pragma once

#include <optional>

#include "rule.hpp"
#include "variablemanager.hpp"
#include "proof.hpp"
#include "smt.hpp"
#include "accelerationtechnique.hpp"
#include "theory.hpp"

class AccelerationProblem {

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
    Subs up;
    const std::optional<Recurrence::Result> closed;
    BoolExpr guard;
    std::unique_ptr<Smt<IntTheory, BoolTheory>> solver;
    VarMan &its;
    bool isConjunction;
    std::optional<Rel> bound;
    const AccelConfig config;

    bool monotonicity(const Lit &lit, Proof &proof);
    bool recurrence(const Lit &lit, Proof &proof);
    bool eventualWeakDecrease(const Lit &lit, Proof &proof);
    bool eventualIncrease(const Lit &lit, const bool strict, Proof &proof);
    bool fixpoint(const Lit &lit, Proof &proof);
    LitSet findConsistentSubset(const BoolExpr e) const;
    std::optional<unsigned int> store(const Lit &lit, const LitSet &deps, const BoolExpr formula, bool exact = true, bool nonterm = false);

    struct ReplacementMap {
        bool acceleratedAll;
        bool nonterm;
        bool exact;
        std::map<Lit, BoolExpr> map;
    };

    ReplacementMap computeReplacementMap(bool nontermOnly) const;

    AccelerationProblem(
            const BoolExpr guard,
            const Subs &up,
            const std::optional<Recurrence::Result> &closed,
            VarMan &its,
            const AccelConfig &config);

public:

    static AccelerationProblem init(const Rule &rule, const std::optional<Recurrence::Result> &closed, VarMan &its, const AccelConfig &config);

    AcceleratorPair computeRes();
    std::pair<BoolExpr, bool> buildRes(const Model<IntTheory, BoolTheory> &model, const std::map<Lit, std::vector<BoolExpr>> &entryVars);

private:

    bool depsWellFounded(const Lit& lit, bool nontermOnly) const;
    bool depsWellFounded(const Lit& lit, std::map<Lit, const AccelerationProblem::Entry*> &entryMap, bool nontermOnly, LitSet seen = {}) const;

};
