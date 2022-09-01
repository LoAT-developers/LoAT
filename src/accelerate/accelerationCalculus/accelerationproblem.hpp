#pragma once

#include "types.hpp"
#include "rule.hpp"
#include "option.hpp"
#include "itsproblem.hpp"
#include "proof.hpp"
#include "smt.hpp"
#include "accelerationtechnique.hpp"

class AccelerationProblem {

private:

    struct Entry {
        RelSet dependencies;
        BoolExpr formula;
        bool exact;
        bool nonterm;
    };

    using Res = RelMap<std::vector<Entry>>;

    Res res;
    option<RelMap<Entry>> solution;
    RelSet todo;
    Subs up;
    const option<Recurrence::Result> closed;
    Expr cost;
    BoolExpr guard;
    std::unique_ptr<Smt> solver;
    ITSProblem &its;
    bool isConjunction;
    option<Rel> bound;

    bool monotonicity(const Rel &rel, Proof &proof);
    bool recurrence(const Rel &rel, Proof &proof);
    bool eventualWeakDecrease(const Rel &rel, Proof &proof);
    bool eventualWeakIncrease(const Rel &rel, Proof &proof);
    bool fixpoint(const Rel &rel, Proof &proof);
    RelSet findConsistentSubset(const BoolExpr e) const;
    option<unsigned int> store(const Rel &rel, const RelSet &deps, const BoolExpr formula, bool exact = true, bool nonterm = false);

    struct ReplacementMap {
        bool acceleratedAll;
        bool nonterm;
        bool exact;
        RelMap<BoolExpr> map;
    };

    ReplacementMap computeReplacementMap(bool nontermOnly) const;

    AccelerationProblem(
            const BoolExpr guard,
            const Subs &up,
            const option<Recurrence::Result> &closed,
            const Expr &cost,
            ITSProblem &its);

public:

    static AccelerationProblem init(const LinearRule &rule, const option<Recurrence::Result> &closed, ITSProblem &its);

    std::vector<AccelerationTechnique::Accelerator> computeRes();
    std::pair<BoolExpr, bool> buildRes(const Model &model, const std::map<Rel, std::vector<BoolExpr>> &entryVars);

private:

    bool depsWellFounded(const Rel& rel, bool nontermOnly) const;
    bool depsWellFounded(const Rel& rel, RelMap<const AccelerationProblem::Entry*> &entryMap, bool nontermOnly, RelSet seen = {}) const;

};
