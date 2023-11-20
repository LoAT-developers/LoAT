#include "nonlinear.hpp"
#include "booltheory.hpp"
#include "config.hpp"
#include "expr.hpp"
#include "linearizingsolver.hpp"
#include "linearsolver.hpp"
#include "smt.hpp"
#include "smtfactory.hpp"
#include <stdexcept>

void NonLinearSolver::analyze(ILinearSolver &linear_solver) {
    LinearizingSolver<IntTheory, BoolTheory> smt(4294967295u);

    // For the first loop iteration, the list of facts is composed of the original facts 
    // given in the CHC problem. In subsequent iterations, the facts are whatever
    // the linear solver managed to derive.
    std::set<Clause> facts(linear_solver.get_initial_facts());    

    for (const auto max_constraint_tier: linear_solver.constraint_tiers) {
        while (true) {
            if (Config::Analysis::log) {
                std::cout << "============= non-linear solver main loop =============" << std::endl;
            }

            const std::set<Clause> non_linear_chcs(linear_solver.get_non_linear_chcs());

            // Do resolution with all combinations of facts and non-linear clauses to 
            // get every possible linear clause that we can derive in this iteration.
            std::list<Clause> resolvents;
            for (const auto& non_linear_chc: linear_solver.get_non_linear_chcs()) {
                const auto res(all_resolvents(non_linear_chc, facts));           
                resolvents.insert(
                    resolvents.end(),
                    res.begin(),
                    res.end()
                );
            }

            // for (const auto& res: resolvents) {
            //     std::cout << "Res: " << res << std::endl;
            // }

            const std::set<Clause> resolvents_distinct(resolvents.begin(), resolvents.end());

            if (Config::Analysis::log) {
                std::cout 
                    << (resolvents.size() - resolvents_distinct.size())
                    << " of "
                    << resolvents.size()
                    << " resolvents are syntactially redundant"                
                    << std::endl;
            }

            linear_solver.add_clauses(resolvents_distinct);

            // std::cout << "facts      : " << facts.size() << std::endl;
            // std::cout << "non linear : " << non_linear_chcs.size() << std::endl;

            facts.clear();
            const auto new_facts = linear_solver.derive_new_facts(max_constraint_tier);
            facts.insert(new_facts.begin(), new_facts.end());

            if (Config::Analysis::log) {
                for (const auto &fact: new_facts) {
                    std::cout << "new fact: " << fact << std::endl;
                }
            }

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
const std::list<Clause> all_resolvents(const Clause& chc, const std::set<Clause>& facts) {
    std::list<Clause> resolvents;
    all_resolvents_aux(chc, chc.lhs.begin(), facts, resolvents);
    return resolvents;
}
void all_resolvents_aux(const Clause& chc, const std::set<FunApp>::iterator preds, const std::set<Clause>& facts, std::list<Clause>& resolvents) {
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
