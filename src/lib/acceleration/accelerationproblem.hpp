#pragma once

#include <optional>

#include "rule.hpp"
#include "smt.hpp"
#include "theory.hpp"
#include "proof.hpp"
#include "recurrence.hpp"
#include "accelconfig.hpp"

class AccelerationProblem {

public:

    struct Accelerator {
        BoolExpr formula;
        Proof proof;

        Accelerator(const BoolExpr &formula, const Proof &proof):
            formula(formula),
            proof(proof) {}

    };

    struct AcceleratorPair {
        std::optional<Accelerator> term;
        std::optional<Accelerator> nonterm;
    };

    std::optional<Recurrence::Result> getClosed() const;

private:

    struct Entry {
        LitSet dependencies;
        BoolExpr formula;
        bool nonterm;
    };

    using Res = std::map<Lit, std::vector<Entry>>;

    const std::optional<Recurrence::Result> closed;
    Subs update;
    BoolExpr guard;
    const AccelConfig config;
    Proof proof;
    Res res;
    std::optional<std::map<Lit, Entry>> solution;
    LitSet todo;
    const std::optional<Subs> &samplePoint;
    std::unique_ptr<Smt<IntTheory, BoolTheory>> solver;
    std::optional<Rel> bound;

    bool trivial(const Lit &lit);
    bool unchanged(const Lit &lit);
    bool polynomial(const Lit &lit);
    bool monotonicity(const Lit &lit);
    bool recurrence(const Lit &lit);
    bool eventualWeakDecrease(const Lit &lit);
    bool eventualIncrease(const Lit &lit, const bool strict);
    bool fixpoint(const Lit &lit);
    unsigned store(const Lit &lit, const LitSet &deps, const BoolExpr formula, bool nonterm = false);

    struct ReplacementMap {
        bool nonterm;
        std::map<Lit, BoolExpr> map;
    };

    std::optional<ReplacementMap> computeReplacementMap(bool nontermOnly) const;

public:

    AccelerationProblem(
            const Rule &rule,
            const std::optional<Recurrence::Result> &closed,
            const std::optional<Subs> &samplePoint,
            const AccelConfig &config);

    AcceleratorPair computeRes();
    std::pair<BoolExpr, bool> buildRes(const Model<IntTheory, BoolTheory> &model, const std::map<Lit, std::vector<BoolExpr>> &entryVars);

private:

    bool depsWellFounded(const Lit& lit, bool nontermOnly) const;
    bool depsWellFounded(const Lit& lit, std::map<Lit, const AccelerationProblem::Entry*> &entryMap, bool nontermOnly, LitSet seen = {}) const;

};
