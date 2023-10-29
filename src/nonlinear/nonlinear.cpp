#include "nonlinear.hpp"
#include "booltheory.hpp"
#include "config.hpp"
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
    std::list<Clause> facts(linear_solver.get_initial_facts());    

    while (true) {

        if (Config::Analysis::log) {
            std::cout << "============= non-linear solver main loop =============" << std::endl;
        }

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
                        // maybe later dont reject resolvent on `Unknown`?
                        if (SmtFactory::check(resolvent.guard) == Sat) {                           
                            resolvents.push_back(resolvent);
                            if (!resolvent.isLinear()) {
                                // std::cout << "new non-linear: " << resolvent << std::endl;
                                // Note that we append items to `non_linear_chcs` while iterating over it.
                                // That means we also iterate over all added items.
                                non_linear_chcs.push_back(resolvent);
                            }

                            if (Config::Analysis::log) {
                                if (resolvent.isLinear()) {
                                    std::cout << "new linear: " << resolvent << std::endl;
                                } else {
                                    std::cout << "new non-linear: " << resolvent << std::endl;
                                }
                            }
                        }
                    }
                }
            }
        }

        // TODO: saw this constraint: (-2+i3 == 0 /\ 2-i3 == 0). Could be simplified more.

        linear_solver.add_clauses(resolvents);

        facts.clear();
        const auto new_facts = linear_solver.derive_new_facts();
        facts.insert(facts.end(), new_facts.begin(), new_facts.end());

        if (Config::Analysis::log) {
            for (const auto &fact: new_facts) {
                std::cout << "new fact: " << fact << std::endl;
                // NOTE: seeing facts that are redundant up to renaming:
                // new fact: (-1+i1 == 0 /\ -1+it15 < 0 /\ -3+it59 == 0 /\ -2+it60-it15 == 0) ==> F2(it59,it60)
                // new fact: (-1+i1 == 0 /\ -2+it35 < 0 /\ -1+it66-it35 == 0 /\ -3+it65 == 0) ==> F2(it65,it66)
            }
        }

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
