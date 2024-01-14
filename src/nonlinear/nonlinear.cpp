#include "nonlinear.hpp"
#include "booltheory.hpp"
#include "config.hpp"
#include "expr.hpp"
#include "itsproblem.hpp"
#include "reachability.hpp"
#include "linearizingsolver.hpp"
#include "linearsolver.hpp"
#include "smt.hpp"
#include "smtfactory.hpp"
#include <stdexcept>

/*

c1)  fib(0, 1)
c2)  fib(2, 3)
c3)  fib(x1, y1) /\ fib(x2, y2) /\ x1+1 = x2 ==> fib(x2+1, y1+y2)


res(c1,c3)  =  fib(x2, y2) /\ 0+1 = x2 ==> fib(x2+1, 1+y2)
            =  fib(1, y) ==> fib(2, y+1)

res(c2,c3)  =  fib(x1, y1) /\ x1+1 = 2 ==> fib(2+1, y1+3)
            =  fib(1, y) ==> fib(3, y+3)

fib(2,4)
fib(2,4)


fib(2,4)
fib(2,7)

trace :

    [c2, res(c1, c3)] = [f(1,1), fib(1, y) ==> fib(2, y+1)] = fib(2,2)

    [c1, res(c2, c3)] = [f(0,1), fib(0, y) ==> fib(2, y+1)] = fib(2,2)

*/

void NonLinearSolver::analyze(const std::vector<Clause>& initial_chcs) {
    const std::set<Clause> chcs_preprocessed = presolve(normalize_all_preds(initial_chcs));

    // Setup ITS and linear solver:
    ITSPtr its = ITSProblem::fromClauses(chcs_preprocessed);
    // TODO: why cant we give `linear_solver` the type `ILinearSolver` ?
    auto linear_solver = reachability::Reachability(*its, true);

    auto [linear_chcs, non_linear_chcs] = partitionByDegree(chcs_preprocessed);

    // For the first loop iteration, the list of facts is composed of the original facts 
    // given in the CHC problem. In subsequent iterations, the facts are whatever
    // the linear solver managed to derive.
    std::set<Clause> facts; 
    for (const auto &chc: linear_chcs) {
        if (chc.isFact()) {
            facts.insert(chc);
        }
    }

    for (const auto max_constraint_tier: LinearSolver::constraint_tiers) {
        while (true) {
            if (Config::Analysis::log) {
                std::cout << "============= non-linear solver main loop =============" << std::endl;
            }

            // Do resolution with all combinations of facts and non-linear clauses to 
            // get every possible linear clause that we can derive in this iteration.
            std::list<Clause> resolvents;
            for (const auto& non_linear_chc: non_linear_chcs) {
                const auto res(all_resolvents(non_linear_chc, facts));           
                resolvents.insert(
                    resolvents.end(),
                    res.begin(),
                    res.end()
                );
            }

            // Filter-out syntactially redundant resolvents:
            const std::set<Clause> resolvents_distinct(resolvents.begin(), resolvents.end());
            if (Config::Analysis::log) {
                std::cout 
                    << (resolvents.size() - resolvents_distinct.size())
                    << " of "
                    << resolvents.size()
                    << " resolvents are syntactially redundant"                
                    << std::endl;
            }            

            // Add linear resolvents to linear solver and store non-linear resolvents for the next resolutions round:
            const auto [linear_resolvents, non_linear_resolvents] = partitionByDegree(resolvents_distinct);
            linear_solver.add_clauses(linear_resolvents);
            non_linear_chcs.insert(non_linear_resolvents.begin(), non_linear_resolvents.end());

            // Hand over to linear solver and let it derive new facts:
            facts.clear();
            facts = linear_solver.derive_new_facts(max_constraint_tier);
            if (Config::Analysis::log) {
                for (const auto &fact: facts) {
                    std::cout << "new fact: " << fact << std::endl;
                }
            }

            // If the linear solver proved Unsat, we can terminate. Otherwise, we use the derived facts to in the next
            // resolution round to derive more linear clauses, that we can feed back into the linear solver. Unless 
            // the set of derived facts is empty, then we have explored the entire search space and can also terminate:
            const auto result = linear_solver.get_analysis_result();     
            if (result == LinearSolver::Result::Unsat) {
                break;
            } else if ((result == LinearSolver::Result::Sat || result == LinearSolver::Result::Unknown) && facts.empty()) {
                break;
            }
        }

        if (linear_solver.get_analysis_result() == LinearSolver::Result::Unsat) {
            break;
        }
    }

    switch (linear_solver.get_analysis_result()) {
        case LinearSolver::Result::Sat:
            std::cout << "sat" << std::endl;
            break;
        case LinearSolver::Result::Unsat:
            std::cout << "unsat" << std::endl;
            break;
        case LinearSolver::Result::Unknown:
            std::cout << "unknown" << std::endl;
            break;
        case LinearSolver::Result::Pending:
            throw std::logic_error("exited main loop, although linear solver is still pending");
    }
}


/**
 * Compute all resolvents of `chc` with `facts`, while trying to avoid redundant derivations.
 * For example, let `F(1)` be the only fact and `chc` be `F(x) /\ F(y) /\ F(z) ==> G(x,y,z)`
 * then a redundant derivation would be:
 *  
 *              F(x) /\ F(y) /\ F(z) ==> G(x,y,z)
 *
 *              /                               \
 *
 *  F(x) /\ F(y) ==> G(x,y,1)         F(x) /\ F(z) ==> G(x,1,z)
 *
 *             |                                 |
 *
 *     F(x) ==> G(x,1,1)                  F(x) ==> G(x,1,1)
 * 
 * The returned clause list should not contain any redundant clauses as long as the given 
 * `facts` are not redundant. The returned list should also not contain `chc` itself and
 * no facts (i.e. clauses with no LHS predicates).
 */
const std::vector<Clause> all_resolvents(const Clause& chc, const std::set<Clause>& facts) {
    std::vector<Clause> resolvents;
    all_resolvents_aux(chc, chc.lhs.begin(), facts, resolvents);
    return resolvents;
}
void all_resolvents_aux(const Clause& chc, const std::set<FunApp>::iterator preds, const std::set<Clause>& facts, std::vector<Clause>& resolvents) {
    // === Running example ===
    // `chc`   : F(x) /\ F(y) /\ F(z) ==> G(x,y,z)
    // `preds` :  ^---- iterator pointing on first predicate of `chc`
    // `facts` : [F(1), F(2)]

    if (preds == chc.lhs.end() || chc.isLinear()) {
        return; 
    } else {
        const auto current_pred = *preds; // == F(x)

        // All resolvents that DONT eliminate F(x)
        all_resolvents_aux(chc, std::next(preds), facts, resolvents);
        // F(x) /\ F(y) ==> G(x,y,1)
        // F(x) /\ F(y) ==> G(x,y,2)
        //
        // F(x) /\ F(z) ==> G(x,1,z)
        // F(x) ==> G(x,1,1)
        // F(x) ==> G(x,1,2)
        //
        // F(x) /\ F(z) ==> G(x,2,z)
        // F(x) ==> G(x,2,1)
        // F(x) ==> G(x,2,2)

        // All resolvents that DO eliminate F(x)
        // std::list<Clause> res_without_head;
        for (const auto& fact: facts) {             
            const auto optional_resolvent = fact.resolutionWith(chc, current_pred);

            if (optional_resolvent.has_value()) {    
                const auto resolvent = optional_resolvent.value();
                // for fact = F(1) :      F(y) /\ F(z) ==> G(1,y,z)
                //
                // for fact = F(2) :      F(y) /\ F(z) ==> G(2,y,z)

                if (SmtFactory::check(resolvent.guard) == Sat) {
                    resolvents.push_back(resolvent);
                    // if (Config::Analysis::log) {
                    //     std::cout << "new resolvent: " << resolvent << std::endl;
                    // }


                    // const auto res(all_resolvents_aux(resolvent, resolvent.lhs.begin(), facts));
                    all_resolvents_aux(resolvent, resolvent.lhs.begin(), facts, resolvents);
                    // for fact = F(1) :       F(y) ==> G(1,y,1)
                    //                         F(y) ==> G(1,y,2)
                    //                         F(z) ==> G(1,1,z)
                    //                         F(z) ==> G(1,2,z)
                    //
                    // for fact = F(2) :       F(y) ==> G(2,y,1)
                    //                         F(y) ==> G(2,y,2)
                    //                         F(z) ==> G(2,1,z)
                    //                         F(z) ==> G(2,2,z)

                    // res_without_head.push_back(resolvent);
                    // res_without_head.insert(
                    //     res_without_head.begin(),
                    //     res.begin(),
                    //     res.end()
                    // );
                }
            }
        }

        // join all collected resolvents and return:
        // res_without_head.insert(
        //     res_without_head.end(),
        //     res_with_head.begin(), 
        //     res_with_head.end()
        // );
        // return res_without_head;
    }
}

const FunApp normalize_pred(unsigned int_var_count, unsigned bool_var_count, const FunApp &pred) {
    std::vector<Var> int_args;
    int_args.reserve(int_var_count);
    std::vector<Var> bool_args;
    bool_args.reserve(bool_var_count);

    for (const Var &arg: pred.args) {
        if (std::holds_alternative<NumVar>(arg)) {
            int_args.push_back(arg);
        } else {
            bool_args.push_back(arg);
        }
    }

    while (int_args.size() < int_var_count) {
        int_args.push_back(NumVar::next());
    }

    while (bool_args.size() < bool_var_count) {
        bool_args.push_back(BoolVar::next());
    }

    int_args.insert(int_args.end(), bool_args.begin(), bool_args.end());
    return FunApp(pred.name, int_args);
}

/**
 * Add and reorder int/bool arguments of each predicate in each clause in `chc_problem` until all
 * of them have the same number of int/bool variables, that is: 
 *
 *    F(int_1, int_2, ..., int_n, bool_1, bool_2, ..., bool_m)
 * 
 * This is necessary because the facts dervied by the linear solver (at least Reachability) have this shape.
 * And to correctly resolve the facts with non-linear clauses, it's easier if all clauses have this shape to
 * begin with.
 */
const std::vector<Clause> normalize_all_preds(const std::vector<Clause>& initial_chcs) {
    std::vector<Clause> chcs_normalized; 

    auto [ max_int_arity, max_bool_arity ] = maxArity(initial_chcs);

    for (const auto& chc: initial_chcs) {
        std::set<FunApp> lhs_normalized;

        for (const FunApp &pred: chc.lhs) {
            const auto pred_normalized = normalize_pred(
                max_int_arity, 
                max_bool_arity, 
                pred
            );
            lhs_normalized.insert(pred_normalized);
        }            

        if (chc.rhs.has_value()) {
            chcs_normalized.push_back(Clause(
                lhs_normalized, 
                normalize_pred(max_int_arity, max_bool_arity, chc.rhs.value()),
                chc.guard->simplify()
            ));
        } else {
            chcs_normalized.push_back(Clause(
                lhs_normalized, 
                {},
                chc.guard->simplify()
            ));
        }   
    }

    return chcs_normalized;
}

/**
 * Returns a clause in `chcs`, whose RHS predicate has the name `pred_name`, but only if
 * this clause is the ONLY instance with this RHS predicate. For example, in the set of CHCs:
 *
 *     (c1)  F ==> G
 *     (c2)  F ==> H
 *     (c3)  G ==> H
 *
 * the predicate `G` occurs on the RHS of exactly one clause (namely c1), while the 
 * predicate `F` never occurs on the RHS and `H` occurs twice. Thus:
 * 
 *     unilaterally_resolvable_with(F, {c1,c2,c3}) == null
 *     unilaterally_resolvable_with(G, {c1,c2,c3}) == c1
 *     unilaterally_resolvable_with(H, {c1,c2,c3}) == null
 *     
 */
const std::optional<Clause> unilaterally_resolvable_with(const FunApp& pred, const std::set<Clause>& chcs) {
    auto candidate = chcs.end(); // Initialize to end iterator, indicating no candidate found

    for (auto it = chcs.begin(); it != chcs.end(); ++it) {
        if (it->rhs.has_value() && it->rhs.value().name == pred.name) {
            if (candidate != chcs.end()) {
                // Predicate occurs on RHS of multiple clauses.
                return {};
            } else {
                candidate = it;
            }
        }
    }

    if (candidate != chcs.end()) {
        return *candidate;
    } else {
        return {};
    }
}

/**
 * Compute resolvent of `left` and `right`. If the RHS predicate of `left` occurs 
 * multiple times on the LHS of `right`, then keep resolving until all predicates 
 * are eliminated. For example for
 *
 *     (left)   F ==> G
 *     (right)  G /\ G ==> H
 *  
 * we would resolve `left` with `right` twice, until `G` is completely eliminated.
 */
const Clause eliminate_pred(const Clause& left, const Clause& right) {
    if (left.isQuery()) {
        return right;
    }

    const auto& left_pred = left.rhs.value();
    const auto& right_pred = right.getLHSPredicate(left_pred.name);    

    if (right_pred.has_value()) {
        return eliminate_pred(left, left.resolutionWith(right, right_pred.value()).value());
    } else {
        return right;
    }
}

/**
 * If a predicate only occurs on the RHS of a single CHC, then there is only one 
 * choice how to eliminate the predicate on the LHS of other CHCs. Thus, we can 
 * precompute all resolvents where one of parent clauses has a unique RHS. 
 *
 * This reduces the number of clauses the CHC problem and has propagation effects.
 * This can turn a non-linear CHC problem into a linear one, or even make it trivially 
 * UNSAT/SAT. For example, consider the non-linear CHC problem:
 *
 *     (c1)  X>0 ==> F(X)
 *     (c2)  X<0 ==> G(X)
 *     (c3)  F(X) /\ G(X) ==> H
 *     (c4)  F(X) ==> H
 *     (c5)  H ==> false
 *
 * The predicate `F(X)` occurs uniquely on the RHS of `c1` so we can precompute the 
 * resolvents of `c1` with any all clauses that have `F(X)` on the LHS (namely c3`, `c4`).
 * We obtain:
 *
 *     (c2)     X<0 ==> G(X)
 *     (c1+c3)  G(X) /\ X>0 ==> H
 *     (c1+c4)  X>0 ==> H
 *     (c5)     H ==> false
 *
 * Note that we can remove `c1` since it cannot be used for any future resolution steps
 * anymore. Analogously, the predicate `G(X)` also occurs uniquely on the RHS of `c2`,
 * so we eliminate `G(X)` as well:
 *
 *     (c1+c2+c3)  X<0 /\ X>0 ==> H
 *     (c1+c4)     X>0 ==> H
 *     (c5)        H ==> false
 * 
 * The constraint of `c1+c2+c3` become UNSAT so this CHC can not be used in any 
 * reachability proof and we can remove it:
 *
 *     (c1+c4)     X>0 ==> H
 *     (c5)        H ==> false
 *
 * Due to this removal the predicate `H` now also uccurs uniquely on the RHS of
 * a CHC, so we can eliminate it as well:
 *
 *     (c1+c4+c5)  X>0 ==> false
 * 
 * Thus, we are left with a trivial CHC problem.
 */
const std::set<Clause> presolve(const std::vector<Clause>& initial_chcs) {
    // first collect all RHS predicate that occur in the CHC problem.
    std::set<FunApp> rhs_preds;
    for (const auto& chc: initial_chcs) {
        if (chc.rhs.has_value()) {
            rhs_preds.insert(chc.rhs.value());
        }
    }

    std::set<Clause> chcs(initial_chcs.begin(), initial_chcs.end());

    // iterate over each RHS predicate and ...
    while (!rhs_preds.empty()) {
        if (Config::Analysis::log) {
            std::cout << "eliminating predicates: " << std::endl;
        }

        for (const auto& pred: rhs_preds) {
            // ... check whether it occur uniquely on the RHS of one CHC
            const auto optional_uni_chc = unilaterally_resolvable_with(pred, chcs);
            if (optional_uni_chc.has_value()) {
                const Clause& uni_chc = optional_uni_chc.value();
                chcs.erase(uni_chc);

                if (Config::Analysis::log) {
                    std::cout << " - " << pred.name << std::endl;
                }

                // An edge case to consider: if we have the clause set
                //
                //     (c1) F ==> F
                //     (c2) F ==> false
                //
                // then `F` uniquely occurs on the RHS of `c1`. But after eliminating `c1` we get:
                //
                //     (c1+c2) F ==> false
                //
                // We can't completely eliminate `F` because it also occurs on the LHS of `c1`.
                // In fact, any clause that has `F` on the its LHS is "unreachable" so we can remove
                // them all from the CHC problem. 
                if (uni_chc.getLHSPredicate(pred.name).has_value()) {
                    std::set<Clause> chcs_without_pred;
                    for (const Clause& chc: chcs) {
                        if (!chc.getLHSPredicate(pred.name).has_value()) {
                            chcs_without_pred.insert(chc);
                        }
                    }

                    chcs = chcs_without_pred;
                } else {               
                    std::set<Clause> resolvents;
                    for (const Clause& chc: chcs) {
                        const Clause& resolvent = eliminate_pred(uni_chc, chc);
                        resolvents.insert(resolvent);
                    }

                    chcs = resolvents;
                }
            }
        }

        rhs_preds.clear();

        if (Config::Analysis::log) {
            std::cout << "remove resolvents with UNSAT constraint: " << std::endl;
        }
        // Checking resolvents for satisfiability in a separate loop here, 
        // because it reduces the number of calls to the SMT solver.
        std::set<Clause> chcs_with_sat_guard;
        for (const auto& chc: chcs) {
            if (SmtFactory::check(chc.guard) == Sat) {               
                chcs_with_sat_guard.insert(chc);
            } else if (chc.rhs.has_value()) {
                // Assume we have the resolvents:
                //
                //    (r1) F /\ (X>0 /\ X<0) ==> G
                //    (r2) F ==> G
                //
                // We can remove `r1` because the constraint is UNSAT. After that 
                // removal, `r2` is now unilaterally resolvable because we removed the
                // only other clause, which had `G` as its RHS predicate. Thus, whenever
                // we remove a resolvent, we add its RHS predicate into `rhs_preds`
                // to re-check it in the next while-loop iteration.
                rhs_preds.insert(chc.rhs.value());
            }
        }

        chcs = chcs_with_sat_guard;
    }

    if (Config::Analysis::log) {
        std::cout << std::endl;
    }

    return chcs;
}
