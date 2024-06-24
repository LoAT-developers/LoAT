#include "nonlinear.hpp"
#include "boolexpr.hpp"
#include "itsproblem.hpp"
#include "reachability.hpp"
#include "linearsolver.hpp"
#include "smt.hpp"
#include "smtfactory.hpp"
#include "theory.hpp"
#include <stdexcept>
#include <tuple>

// for debugging: activate logging only in this file
const bool dbg = false;

bool has_entry(const std::set<Clause>& chcs) {
    for (const auto& chc: chcs) {
        // Not necessarily a fact, because RHS predicate is not required. 
        // For example `true ==> false` is an entry but not a fact.
        if (chc.lhs.empty()) { 
            return true;
        }
    }
    return false;
}

bool has_sink(const std::set<Clause>& chcs) {
    for (const auto& chc: chcs) {
        if (!chc.rhs.has_value()) {
            return true;
        }
    }
    return false;
}

bool is_trivially_sat(const std::set<Clause>& chc_problem) {
    // TODO: could check more generally: if no sink is reachable from an entry:
    return chc_problem.empty() || !has_entry(chc_problem) || !has_sink(chc_problem);
}

void NonLinearSolver::analyze(const std::vector<Clause>& initial_chcs) {
    const std::set<Clause> chcs_preprocessed = presolve(normalize_all_preds(initial_chcs));

    if (is_trivially_sat(chcs_preprocessed)) {
        // If preprocessing manages to eliminate all clauses or at least all facts/queries 
        // we can terminate with SAT.
        std::cout << "sat" << std::endl;
        return;    
    } else if (allLinear(chcs_preprocessed)) {
        ITSPtr its = ITSProblem::fromClauses(chcs_preprocessed);
        reachability::Reachability::analyze(*its);
        return;
    }

    auto [linear_chcs, non_linear_chcs] = partitionByDegree(chcs_preprocessed);

    // Setup ITS and linear solver:
    ITSPtr its = ITSProblem::fromClauses(chcs_preprocessed);
    // TODO: why cant we give `linear_solver` the type `ILinearSolver` ?
    auto linear_solver = reachability::Reachability(*its, true);

    // First only derive "easy" to handle rules with linear guard. If that's not enough
    // also try rules with polynomial guard. Otherwise also consider exponential 
    // (arbitrary) guards.
    for (const auto max_constraint_tier: LinearSolver::constraint_tiers) {
        while (true) {
            if (dbg || Config::Analysis::log) {
                std::cout << "============= non-linear solver main loop =============" << std::endl;
            }

            // Hand over to linear solver to derive new facts:
            const auto& derived_facts = linear_solver.derive_new_facts(max_constraint_tier);

            // If the linear solver proved Unsat, we can terminate. Otherwise, we use the derived facts to in the next
            // resolution round to derive more linear clauses, that we can feed back into the linear solver. Unless 
            // the set of derived facts is empty, then we have explored the entire search space and can also terminate:
            const auto result = linear_solver.get_analysis_result();     
            if (result == LinearSolver::Result::Unsat) {
                break;
            } else if ((result == LinearSolver::Result::Sat || result == LinearSolver::Result::Unknown) && derived_facts.empty()) {
                break;
            }

            // reduce number of facts by merging facts with the same RHS predicate:
            std::set<Clause> facts;
            for (const auto& [_, fact_group]: partitionByRHS(derived_facts)) {
                const auto& merged_fact = merge_facts(fact_group);
                facts.insert(merged_fact);
            }
            if (dbg || Config::Analysis::log) {
                std::cout 
                    << "total new facts: " 
                    << derived_facts.size() 
                    << " / after merge: "
                    << facts.size() 
                    << std::endl;
            }

            // Do resolution with all combinations of facts and non-linear clauses to 
            // get every possible linear clause that we can derive in this iteration.
            const auto resolvents = all_resolvents(non_linear_chcs, facts);

            // Add linear resolvents to linear solver and store non-linear resolvents for the next resolutions round:
            const auto [linear_resolvents, non_linear_resolvents] = partitionByDegree(resolvents);

            // If there are no new linear resolvents the linear solver can't derive new facts
            // in the next iteration, so we can exit here. This can happen if all linear resolvents
            // had UNSAT constraints or the CHC problem contains only linear clauses (because all 
            // non-linear clauses got eliminated in the preprocessing step).
            if (linear_resolvents.empty()) {
                break;
            }

            linear_solver.add_clauses(linear_resolvents);
            non_linear_chcs.insert(non_linear_resolvents.begin(), non_linear_resolvents.end());
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
 * Compute all resolvents of `non_linear_chcs` with `facts`, while trying to avoid redundant derivations.
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
 * The returned clause set should not contain any redundant clauses as long as the given 
 * `facts` and `non_linear_chcs` are not redundant. The returned clauses should also not 
 * include `non_linear_chcs` themselves and no facts (i.e. clauses with no LHS predicates).
 */
const std::set<Clause> all_resolvents(const std::set<Clause>& non_linear_chcs, const std::set<Clause>& facts) {
    std::set<Clause> resolvents;

    unsigned redundant_resolvent_count = 0;

    if (dbg || Config::Analysis::log) {
        std::cout 
            << "resolving "
            << non_linear_chcs.size()
            << " non-linear CHCs"
            << std::endl;       
    }

    std::unique_ptr<Smt<IntTheory, BoolTheory>> solver {SmtFactory::solver<IntTheory, BoolTheory>()};

    for (const auto& chc: non_linear_chcs) {
        if (dbg || Config::Analysis::log) {
            std::cout 
                << "resolving non-linear CHC with "
                << chc.lhs.size()
                << " LHS predicates with "
                << facts.size()
                << " facts"                
                << std::endl;

            printSimple(std::cout << "NL: ", chc) << std::endl;
        }

        solver->push();
        solver->add(chc.guard);
        all_resolvents_aux(chc, 0, facts, resolvents, redundant_resolvent_count, *solver);
        solver->pop();
    }

    if (dbg || Config::Analysis::log) {
        std::cout 
            << "computed "
            << resolvents.size()
            << " resolvents ("
            << redundant_resolvent_count 
            << " redundant)"
            << std::endl;
    }

    // TODO: check comp23 069
    // for (const auto& res: resolvents) {
    //     const std::set<FunApp> lhs_unique(res.lhs.begin(), res.lhs.end());
    //     int red_count = res.lhs.size() - lhs_unique.size();
    //     if (red_count != 0) {
    //         std::cout << "redundant lhs preds: " << red_count << std::endl;
    //     }
    // }

    return resolvents;
}
void all_resolvents_aux(
    const Clause& chc, 
    unsigned pred_index, 
    const std::set<Clause>& facts,
    std::set<Clause>& resolvents, 
    unsigned& redundant_resolvent_count,
    Smt<IntTheory, BoolTheory>& solver
) {
    // === Running example ===
    // `chc`        : F(x) /\ F(y) /\ F(z) ==> G(x,y,z)
    // `pred_index` :   ^---- index on first LHS predicate of `chc`
    // `facts`      : [F(1), F(2)]

    if (pred_index >= chc.lhs.size() || chc.isLinear()) {
        return;
    } else {
        // All resolvents that DO eliminate F(x)
        for (const auto& fact: facts) {
            // printSimple(std::cout << "fact: ", fact) << std::endl;
            const auto optional_resolvent = fact.resolutionWith(chc, pred_index);

            if (optional_resolvent.has_value()) {
                // const auto resolvent = optional_resolvent.value();
                const auto [resolvent, extra_constraints] = optional_resolvent.value();
                // for fact = F(1) :      F(y) /\ F(z) ==> G(1,y,z)
                //
                // for fact = F(2) :      F(y) /\ F(z) ==> G(2,y,z)

                if (resolvents.contains(resolvent)) {
                    // There are still many ways how we can get syntactically redundant resolvents.
                    // For example, with facts G,H and rules
                    //
                    //     G /\ F ==> false
                    //     H /\ F ==> false
                    //
                    // we derive `F ==> false` in two different ways. However, when we encouter a 
                    // redundant resolvent we can prune the recursive call, because all following
                    // resolvents are also redundant. 
                    redundant_resolvent_count++;
                } else {
                    solver.push();
                    solver.add(extra_constraints);
                    
                    // if (SmtFactory::check(resolvent.guard) == Sat) {
                    if (solver.check() == Sat) {
                        resolvents.insert(resolvent);

                        all_resolvents_aux(resolvent, pred_index, facts, resolvents, redundant_resolvent_count, solver);
                        // for fact = F(1) :       F(y) ==> G(1,y,1)
                        //                         F(y) ==> G(1,y,2)
                        //                         F(z) ==> G(1,1,z)
                        //                         F(z) ==> G(1,2,z)
                        //
                        // for fact = F(2) :       F(y) ==> G(2,y,1)
                        //                         F(y) ==> G(2,y,2)
                        //                         F(z) ==> G(2,1,z)
                        //                         F(z) ==> G(2,2,z)
                    }

                    solver.pop();
                } 
            }
        }
        
        // All resolvents that DONT eliminate F(x)
        all_resolvents_aux(chc, pred_index+1, facts, resolvents, redundant_resolvent_count, solver);
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
        std::vector<FunApp> lhs_normalized;

        for (const FunApp &pred: chc.lhs) {
            const auto pred_normalized = normalize_pred(
                max_int_arity, 
                max_bool_arity, 
                pred
            );
            lhs_normalized.push_back(pred_normalized);
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
const std::optional<Clause> unilaterally_resolvable_with(const std::string& pred_name, const std::set<Clause>& chcs) {
    auto candidate = chcs.end(); // Initialize to end iterator, indicating no candidate found

    for (auto it = chcs.begin(); it != chcs.end(); ++it) {
        if (it->rhs.has_value() && it->rhs.value().name == pred_name) {
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
    const auto& right_pred_index = right.indexOfLHSPred(left_pred.name);

    if (right_pred_index.has_value()) {
        const auto [resolvent, _] = left.resolutionWith(right, right_pred_index.value()).value();
        return eliminate_pred(left, resolvent);
    } else {
        return right;
    }
}

/**
 * Merges a collection of `facts` by building the disjunct of all constraints.
 * For example, merging the facts:
 *
 *     x=0 ==> F(x)
 *
 *     y=1 ==> F(y)
 *
 *     z>5 ==> F(z)
 *
 * results in: 
 *
 *     (x=0 \/ x=1 \/ x>5) ==> F(x)
 *
 * Notice, that the RHS predicates have to be unified for that. It's assumed that `facts`: 
 *
 *   1) contains at least one item
 *   2) contains only clauses that are indeed facts
 *   3) all facts share the same RHS predicate
 *
 * Otherwise, this function throws an error.
 */
const Clause merge_facts(const std::vector<Clause> facts) {
    if (facts.size() == 0) {
        throw std::logic_error("merge_facts: expect at least one fact");
    } 

    std::unique_ptr<const Clause> fact_accum = std::make_unique<const Clause>(facts.at(0));

    if (!fact_accum->isFact()) {
        throw std::logic_error("merge_facts: got non-fact clause");
    }

    for (unsigned i=1; i < facts.size(); i++) {
        const auto& fact_current = facts.at(i);

        if (!fact_current.isFact()) {
            throw std::logic_error("merge_facts: got non-fact clause");
        }

        const auto& rhs_pred_accum = fact_accum->rhs.value();
        const auto& rhs_pred_current = fact_current.rhs.value();

        if (rhs_pred_accum.name != rhs_pred_current.name) {
            throw std::logic_error("merge_facts: all facts must have matching RHS");
        }       

        const auto& unifier = computeUnifier(rhs_pred_current, rhs_pred_accum);

        if (!unifier.has_value()) {
            throw std::logic_error("merge_facts: cannot unify RHS predicates");
        }

        const std::vector<BoolExpr> guards({ 
            fact_current.renameWith(unifier.value()).guard, 
            fact_accum->guard 
        });
        const auto& guard_disjunct = BExpression::buildOr(guards);

        fact_accum = std::make_unique<const Clause>(
            Clause({}, rhs_pred_accum, guard_disjunct)
        );
    }

    return *fact_accum;
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
    // first collect all RHS predicates of all CHCs
    std::set<std::string> todo_rhs_preds;
    for (const auto& chc: initial_chcs) {
        if (chc.rhs.has_value()) {
            todo_rhs_preds.insert(chc.rhs.value().name);
        }
    }

    std::set<Clause> result_chcs(initial_chcs.begin(), initial_chcs.end());

    // iterate over each RHS predicate and ...
    while (!todo_rhs_preds.empty()) {
        if (dbg || Config::Analysis::log) {
            std::cout << "eliminating predicates: " << std::endl;
        }

        for (const auto& pred: todo_rhs_preds) {
            // ... check whether it occurs uniquely on the RHS of one CHC
            const auto optional_uni_chc = unilaterally_resolvable_with(pred, result_chcs);
            if (optional_uni_chc.has_value()) {
                const Clause& uni_chc = optional_uni_chc.value();
                result_chcs.erase(uni_chc);

                if (dbg || Config::Analysis::log) {
                    std::cout << " - " << pred << std::endl;
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
                if (uni_chc.indexOfLHSPred(pred).has_value()) {
                    std::set<Clause> chcs_without_pred;
                    for (const Clause& chc: result_chcs) {
                        if (!chc.indexOfLHSPred(pred).has_value()) {
                            chcs_without_pred.insert(chc);
                        }
                    }

                    result_chcs = chcs_without_pred;
                } else {               
                    std::set<Clause> resolvents;
                    for (const Clause& chc: result_chcs) {
                        const Clause& resolvent = eliminate_pred(uni_chc, chc);
                        resolvents.insert(resolvent);
                    }

                    result_chcs = resolvents;
                }
            }
        }

        todo_rhs_preds.clear();

        if (dbg || Config::Analysis::log) {
            std::cout << "remove resolvents with UNSAT constraint: " << std::endl;
        }
        // Checking resolvents for satisfiability in a separate loop here, 
        // because it reduces the number of calls to the SMT solver.
        std::set<Clause> chcs_with_sat_guard;
        for (const auto& chc: result_chcs) {
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
                todo_rhs_preds.insert(chc.rhs.value().name);
            }
        }

        // We can eliminate even more predicates by merging facts. For example, the
        // facts:
        //
        //     x=0 ==> F(x)
        //
        //     x>0 ==> F(x)
        //
        // can be merged to:
        //
        //     (x=0 \/ x>0) ==> F(x)
        //
        // This can make all facts unilaterally resolvable as long as the RHS predicate 
        // does not also occur on the RHS of a rule. 
        //
        // Arguably, that just off-loads dealing with disjunctions to the linear solver. 
        // We also loose some CHC structure pushing disjunctions into the clause constraint. 
        // However, ADCL is designed to deal with disjunctions. And computing all resolvents 
        // in the non-linear solver is worst-case exponential in the number of LHS predicates,
        // so it's probably worth it to eliminate as many LHS predicate as possible.
        //
        // For that we filter-out all the facts we currently have and partition them by their
        // RHS predicates. Then we merge every group into a single fact. Notice, that we have
        // to do this step repeatedly because some clauses might only later turn into facts.
        // For example, here `G(x)` can not completely be merged into a single fact in the
        // beginning:
        //
        //     x=0 ==> F(x)
        //    
        //     x=1 ==> F(x)
        //
        //     x=2 ==> G(x)
        //
        //     F(x) ==> G(x)
        //
        // We merge all `F(x)` facts which makes the result unilaterally resolvable: 
        //
        //     (x=0 \/ x=1) ==> F(x)
        //    
        //     x=2 ==> G(x)
        //
        //     F(x) /\ ==> G(x)
        //
        // We eliminate `F(x)` and get:
        //    
        //     x=2 ==> G(x)
        //
        //     (x>0 \/ x=0) ==> G(x)
        //
        // Now, `G(x)` can be merged into a single fact:
        //
        //     (x=0 \/ x=1 \/ x=2) ==> G(x)
        //
        const auto& [ facts, rest_chcs ] = partitionFacts(chcs_with_sat_guard);
        result_chcs = rest_chcs;
        for (const auto& [_, fact_group]: partitionByRHS(facts)) {
            const Clause& merged_fact = merge_facts(fact_group);           

            // If `fact_group.size() == 1` then `merge_facts` has nothing to merge and just 
            // returns the single fact unchanged. Thus, no facts where eliminated and nothing
            // new became unilaterally resolvable. On the other hand, if `fact_group.size() > 1`  
            // then facts got eliminated, so the resulting clause might now be unilaterally 
            // resolvable and we add its RHS predicate back into `todo_rhs_preds`.
            if (fact_group.size() > 1) {
                todo_rhs_preds.insert(merged_fact.rhs.value().name);
            }

            result_chcs.insert(merged_fact);
        }
    }

    if (dbg || Config::Analysis::log) {
        std::cout << std::endl;
    }

    // Use all facts and non-linear clauses that are already known at this point and 
    // do one round of resolution with them to derive all possible linear clauses that 
    // we can get at this point to give the linear solver as much information as possible
    // for the first iteration.
    const auto& [ linear_chcs, non_linear_chcs ] = partitionByDegree(result_chcs);
    const auto& [ facts, _ ] = partitionFacts(linear_chcs);
    std::set<Clause> resolvents = all_resolvents(non_linear_chcs, facts);
    result_chcs.insert(resolvents.begin(), resolvents.end());

    return result_chcs;
}
