#pragma once

#include "qelim.hpp"
#include "theory.hpp"
#include "proof.hpp"
#include "smt.hpp"

class QeProblem : public Qelim
{

private:

    struct Entry {
        std::set<Theory<IntTheory>::Lit> dependencies;
        BExpr<IntTheory> formula;
        bool exact;
    };

    using Res = RelMap<std::vector<Entry>>;

    Res res;
    option<RelMap<Entry>> solution;
    std::set<Theory<IntTheory>::Lit> todo;
    std::unique_ptr<Smt<IntTheory>> solver;
    option<QuantifiedFormula<IntTheory>> formula;
    VariableManager &varMan;

    bool monotonicity(const Rel &rel, const NumVar &n, Proof &proof);
    bool recurrence(const Rel &rel, const NumVar &n, Proof &proof);
    bool eventualWeakDecrease(const Rel &rel, const NumVar &n, Proof &proof);
    bool eventualWeakIncrease(const Rel &rel, const NumVar &n, Proof &proof);
    option<BExpr<IntTheory>> strengthen(const Rel &rel, const NumVar &n, Proof &proof);
    bool fixpoint(const Rel &rel, const NumVar &x, Proof &proof);
    std::set<Theory<IntTheory>::Lit> findConsistentSubset(const BExpr<IntTheory> e, const NumVar &var) const;
    option<unsigned int> store(const Rel &rel, const std::set<Theory<IntTheory>::Lit> &deps, const BExpr<IntTheory> formula, bool exact = true);
    BExpr<IntTheory> boundedFormula(const NumVar &var) const;

    struct ReplacementMap {
        bool exact;
        std::map<Theory<IntTheory>::Lit, BExpr<IntTheory>> map;
    };

    ReplacementMap computeReplacementMap() const;
    Quantifier getQuantifier() const;

    bool depsWellFounded(const Rel& rel) const;
    bool depsWellFounded(const Rel& rel, RelMap<const QeProblem::Entry*> &entryMap, RelSet seen = {}) const;

public:

    struct Result {
        BoolExpr qf;
        bool exact;

        Result(const BoolExpr &qf, bool exact): qf(qf), exact(exact) {}

    };

    QeProblem(VariableManager &varMan): varMan(varMan){}
    option<Qelim::Result> qe(const QuantifiedFormula<IntTheory> &qf) override;

};
