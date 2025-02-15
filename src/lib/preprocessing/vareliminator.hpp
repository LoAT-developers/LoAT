#pragma once

#include "theory.hpp"

#include <functional>
#include <stack>

/**
 * Computes substitutions that are suitable to eliminate the given temporary variable from the rule by replacing it with its bounds.
 */
class VarEliminator
{

public:

    VarEliminator(const Bools::Expr guard, const Arith::Var N, const std::function<bool(Arith::Var)> &keep);

    const linked_hash_set<ArithSubs> getRes() const;

private:

    /**
     * Dependencies are other temporary variables that render a bound on N useless.
     * For example, if we have N * M <= X, then we cannot instantiate N with X/M, as the bound must always evaluate to an integer.
     * Thus, in this case M is a dependency of N.
     */
    void findDependencies(const Bools::Expr guard);

    /**
     * Tries to eliminate a single dependency by instantiating it with a constant bound.
     * Creates a new branch (i.e., a new entry in todoDeps) for every possible instantiation.
     */
    const std::vector<std::pair<ArithSubs, Bools::Expr>> eliminateDependency(const ArithSubs &subs, const Bools::Expr guard) const;

    /**
     * Eliminates as many dependencies as possible by instantiating them with constant bounds.
     */
    void eliminateDependencies();

    /**
     * First eliminates as many dependencies as possible, then eliminates N, if possible.
     */
    void eliminate();

    Arith::Var N;

    /**
     * Each entry represents one branch in the search for suitable instantiations of dependencies.
     * Entries that do not allow for further instantiation are moved to todoN.
     */
    std::stack<std::pair<ArithSubs, Bools::Expr>> todoDeps {};

    /**
     * Each entry represents one possibility to instantiate dependencies exhaustively.
     * N still needs to be eliminated.
     */
    std::vector<std::pair<ArithSubs, Bools::Expr>> todoN {};

    /**
     * Substitutions that are suitable to eliminate N.
     */
    linked_hash_set<ArithSubs> res {};

    linked_hash_set<Arith::Var> dependencies {};

    const std::function<bool(Arith::Var)> keep;

};
