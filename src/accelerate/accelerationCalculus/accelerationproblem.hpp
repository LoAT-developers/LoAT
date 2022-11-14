#pragma once

#include "rule.hpp"
#include "option.hpp"
#include "itsproblem.hpp"
#include "proof.hpp"
#include "smt.hpp"
#include "accelerationtechnique.hpp"
#include "theory.hpp"
#include "approx.hpp"

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
    option<std::map<Lit, Entry>> solution;
    LitSet todo;
    Subs up;
    const option<Recurrence::Result> closed;
    Expr cost;
    BoolExpr guard;
    std::unique_ptr<Smt<IntTheory, BoolTheory>> solver;
    ITSProblem &its;
    bool isConjunction;
    option<Rel> bound;
    const Approx approx;

    bool monotonicity(const Lit &lit, Proof &proof);
    bool recurrence(const Lit &lit, Proof &proof);
    bool eventualWeakDecrease(const Lit &lit, Proof &proof);
    bool eventualWeakIncrease(const Lit &lit, Proof &proof);
    bool fixpoint(const Lit &lit, Proof &proof);
    LitSet findConsistentSubset(const BoolExpr e) const;
    option<unsigned int> store(const Lit &lit, const LitSet &deps, const BoolExpr formula, bool exact = true, bool nonterm = false);

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
            const option<Recurrence::Result> &closed,
            const Expr &cost,
            ITSProblem &its,
            const Approx approx);

public:

    static AccelerationProblem init(const LinearRule &rule, const option<Recurrence::Result> &closed, ITSProblem &its, Approx approx);

    AcceleratorPair computeRes();
    std::pair<BoolExpr, bool> buildRes(const Model<IntTheory, BoolTheory> &model, const std::map<Lit, std::vector<BoolExpr>> &entryVars);

private:

    bool depsWellFounded(const Lit& lit, bool nontermOnly) const;
    bool depsWellFounded(const Lit& lit, std::map<Lit, const AccelerationProblem::Entry*> &entryMap, bool nontermOnly, LitSet seen = {}) const;

};
