#include "nonlinear.hpp"
#include "booltheory.hpp"
#include "linearizingsolver.hpp"
#include "linearsolver.hpp"
#include "smt.hpp"
#include <stdexcept>

void NonLinearSolver::analyze(ILinearSolver &linear_solver) {
    std::unique_ptr<Smt<IntTheory, BoolTheory>> smt(new LinearizingSolver<IntTheory, BoolTheory>(4294967295u));
    smt->enableModels();

    // For the first loop iteration, the list of facts is composed of the original facts 
    // given in the CHC problem. In subsequent iterations, the facts are whatever
    // the linear solver managed to derive.
    std::list<Clause> facts(linear_solver.get_initial_facts());    

    while (true) {
        std::list<Clause> resolvents;
        std::list<Clause> non_linear_chcs = linear_solver.get_non_linear_chcs();

        // Do resolution with all combinations of facts and non-linear clauses to 
        // get every possible linear clause that we can derive in this iteration.
        for (const Clause &non_linear_chc: non_linear_chcs) {
            for (const auto &fact: facts) {
                for (const auto &pred: non_linear_chc.lhs) {
                    const auto optional_resolvent = fact.resolutionWith(non_linear_chc, pred);

                    if (optional_resolvent.has_value()) {
                        const auto resolvent = optional_resolvent.value();
                        // TODO: check for redundancy

                        // TODO: Is SMT a singleton? Does this reset influence the linear solver?
                        // Filter out resolvents, where guard is UNSAT 
                        smt->resetSolver();
                        smt->add(resolvent.guard);
                        if (smt->check() != Unsat) {                           
                            resolvents.push_back(resolvent);
                            if (!resolvent.isLinear()) {
                                // Note that we append items to `non_linear_chcs` while iterating over it.
                                // That means we also iterate over all added items.
                                non_linear_chcs.push_back(resolvent);
                            }
                        }
                    }
                }
            }
        }

        linear_solver.add_clauses(resolvents);

        facts.clear();
        const auto new_facts = linear_solver.derive_new_facts();
        facts.insert(facts.end(), new_facts.begin(), new_facts.end());

        const auto result = linear_solver.get_analysis_result();     
        if (result == LinearSolver::Result::Unsat) {
            break;
        } else if ((result == LinearSolver::Result::Sat || result == LinearSolver::Result::Unknown) && facts.empty()) {
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
