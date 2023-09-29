#include "rule.hpp"
#include "theory.hpp"
#include "types.hpp"
#include <vector>

class FunApp {

public:
    const LocationIdx loc;
    const std::vector<Var> args;

    FunApp(const LocationIdx loc, const std::vector<Var> args): loc(loc), args(args) {}

    const FunApp renameWith(const Subs &renaming) const;

    const VarSet vars() const;
};

class Clause {

public:
    const std::set<FunApp> lhs;
    const FunApp rhs;
    const BoolExpr guard;

    /**
     * Constructor for a Constrained Horn Clause (CHC). For example:
     * 
     *    F(x1) /\ G(x2,x3) /\ (x1 < x2 /\ x2 < x3)   ==>   H(x1,x2,x3)
     *    
     *    ^^^^^^^^^^^^^^^^^    ^^^^^^^^^^^^^^^^^^^^         ^^^^^^^^^^^
     *           lhs                  guard                     rhs
     *
     * @param lhs - a set of predicates on the left-hand-side (LHS) of the implication.
     * @param rhs - a single predicate on the right-hand-side (RHS) of the implication.
     * @param guard - a boolean expression describing the clause constraint.
     */
    Clause(const std::set<FunApp> &lhs, const FunApp &rhs, const BoolExpr &guard) 
        : lhs(lhs), rhs(rhs), guard(guard) {}

    const Clause renameWith(const Subs &renaming) const;

    const std::optional<Clause> resolutionWith(const Clause &chc, const FunApp &pred) const;

    bool isLinear() const;
    
    const VarSet vars() const;

};

// implement comparison operator for FunApp so we can store them in std::set
bool operator<(const FunApp &fun1, const FunApp &fun2);

std::ostream& operator<<(std::ostream &s, const FunApp &fun_app);

std::ostream& operator<<(std::ostream &s, const Clause &chc);
