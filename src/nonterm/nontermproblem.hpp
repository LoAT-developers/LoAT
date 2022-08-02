#ifndef NONTERM_PROBLEM
#define NONTERM_PROBLEM

#include "../its/types.hpp"
#include "../its/rule.hpp"
#include "../util/option.hpp"
#include "../its/itsproblem.hpp"
#include "../util/proof.hpp"
#include "../smt/smt.hpp"

class NontermProblem {

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
    Subs up;
    Expr cost;
    BoolExpr guard;
    Proof proof;
    std::unique_ptr<Smt> solver;
    VariableManager &varMan;
    bool isConjunction;

    NontermProblem(
            const BoolExpr guard,
            const Subs &up,
            const Expr &cost,
            VariableManager &varMan);

    bool recurrence(const Rel &rel);
    bool eventualWeakIncrease(const Rel &rel);
    bool fixpoint(const Rel &rel);
    RelSet findConsistentSubset(const BoolExpr e) const;
    option<unsigned int> store(const Rel &rel, const RelSet &deps, const BoolExpr formula, bool exact);

    struct ReplacementMap {
        bool exact;
        RelMap<BoolExpr> map;
    };

    ReplacementMap computeReplacementMap() const;

public:

    struct Result {
        BoolExpr newGuard;
        bool exact;

        Result(const BoolExpr &newGuard, bool exact): newGuard(newGuard), exact(exact) {}

    };

    static NontermProblem init(const BoolExpr& guard, const Subs &up, const Expr &cost, VariableManager &varMan);
    option<Result> computeRes();
    std::pair<BoolExpr, bool> buildRes(const Model &model, const std::map<Rel, std::vector<BoolExpr>> &entryVars);
    Proof getProof() const;

private:

    bool depsWellFounded(const Rel& rel) const;
    bool depsWellFounded(const Rel& rel, RelMap<const NontermProblem::Entry*> &entryMap, RelSet seen = {}) const;

};

#endif
