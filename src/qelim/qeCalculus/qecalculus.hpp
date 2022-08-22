#ifndef QECALCULUS_HPP
#define QECALCULUS_HPP

#include "qelim.hpp"
#include "proof.hpp"
#include "smt.hpp"

class QeProblem : public Qelim
{

private:

    struct Entry {
        RelSet dependencies;
        BoolExpr formula;
        bool exact;
    };

    using Res = RelMap<std::vector<Entry>>;

    Res res;
    option<RelMap<Entry>> solution;
    RelSet todo;
    std::unique_ptr<Smt> solver;
    option<QuantifiedFormula> formula;
    VariableManager &varMan;

    bool monotonicity(const Rel &rel, const Var &n, Proof &proof);
    bool recurrence(const Rel &rel, const Var &n, Proof &proof);
    bool eventualWeakDecrease(const Rel &rel, const Var &n, Proof &proof);
    bool eventualWeakIncrease(const Rel &rel, const Var &n, Proof &proof);
    option<BoolExpr> strengthen(const Rel &rel, const Var &n, Proof &proof);
    bool fixpoint(const Rel &rel, const Var &x, Proof &proof);
    RelSet findConsistentSubset(const BoolExpr e, const Var &var) const;
    option<unsigned int> store(const Rel &rel, const RelSet &deps, const BoolExpr formula, bool exact = true);
    BoolExpr boundedFormula(const Var &var) const;

    struct ReplacementMap {
        bool exact;
        RelMap<BoolExpr> map;
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
    option<Qelim::Result> qe(const QuantifiedFormula &qf) override;

};

#endif // QECALCULUS_HPP
