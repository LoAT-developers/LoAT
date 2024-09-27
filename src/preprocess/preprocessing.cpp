#include "pair.hpp"
#include "dependencygraph.hpp"
#include "preprocessing.hpp"
#include "config.hpp"
#include "formulapreprocessing.hpp"
#include "loopacceleration.hpp"
#include "rulepreprocessing.hpp"
#include "smtfactory.hpp"
#include "theory.hpp"

#include <numeric>
#include <unordered_set>

Preprocessor::Preprocessor(ITSPtr its): its(its), chain(its), rule_preproc(its), cex(its) {}

bool Preprocessor::successful() const {
    return success;
}

ITSModel Preprocessor::transform_model(const ITSModel &model) const {
    return chain.transform_model(model);
}

ITSCex Preprocessor::transform_cex(const ITSCex &cex) const {
    auto transformed {chain.transform_cex(cex)};
    transformed = rule_preproc.transform_cex(transformed);
    return transformed;
}

ITSModel Preprocessor::get_model() const {
    ITSModel model;
    model.set_invariant(its->getInitialLocation(), top());
    return model;
}

const ITSCex& Preprocessor::get_cex() const {
    return cex;
}

bool remove_irrelevant_clauses(ITSPtr its, bool forward) {
    std::unordered_set<RulePtr> keep;
    std::stack<RulePtr> todo;
    for (const auto &x : forward ? its->getInitialTransitions() : its->getSinkTransitions()) {
        todo.push(x);
    }
    do {
        const auto current {todo.top()};
        todo.pop();
        keep.insert(current);
        for (const auto &p : forward ? its->getSuccessors(current) : its->getPredecessors(current)) {
            if (keep.find(p) == keep.end()) {
                todo.push(p);
            }
        }
    } while (!todo.empty());
    std::vector<RulePtr> to_delete;
    for (const auto &r : its->getAllTransitions()) {
        if (keep.find(r) == keep.end()) {
            to_delete.push_back(r);
        }
    }
    linked_hash_set<RulePtr> deleted;
    for (const auto &idx : to_delete) {
        its->removeRule(idx);
        deleted.insert(idx);
    }
    if (deleted.empty()) {
        return false;
    } else {
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "removed the following irrelevant transitions: " << deleted << std::endl;
        }
        return true;
    }
}

bool remove_irrelevant_clauses(ITSPtr its) {
    return remove_irrelevant_clauses(its, true) || remove_irrelevant_clauses(its, false);
}

/**
 * Motivating example: f(x,y) -> f(-x,z) :|: (y=0 /\ z=1) \/ (y=1 /\ z=0)
 * In contrast to its implicants, it can be unrolled to obtain simpler closed forms.
 */
bool unroll(ITSPtr its) {
    auto success{false};
    for (const auto &r : its->getAllTransitions()) {
        if (its->isSimpleLoop(r) && !r->getGuard()->isConjunction()) {
            const auto [res, period] = LoopAcceleration::chain(r);
            if (period > 1) {
                success = true;
                if (Config::Analysis::doLogPreproc()) {
                    std::cout
                        << "unrolled the following rule " << period << " times:\n"
                        << r
                        << "\nresult:\n"
                        << res << std::endl;
                }
                its->addRule(res, r, r);
            }
        }
    }
    return success;
}

bool refine_dependency_graph(ITSPtr its) {
    const auto is_edge = [](const RulePtr fst, const RulePtr snd) {
        return SmtFactory::check(Preprocess::chain({fst, snd->renameTmpVars()})->getGuard()) == SmtResult::Sat;
    };
    const auto removed{its->refineDependencyGraph(is_edge)};
    if (removed.empty()) {
        return false;
    } else {
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "removed the following edges from the dependency graph: " << removed << std::endl;
        }
        return true;
    }
}

std::optional<SmtResult> Preprocessor::check_empty_clauses(ITSPtr its) {
    std::vector<RulePtr> remove;
    for (const auto &r: its->getInitialTransitions()) {
        if (its->isSinkTransition(r)) {
            const auto solver {SmtFactory::modelBuildingSolver(Logic::QF_LA)};
            solver->add(r->getGuard());
            const auto smt_res {solver->check()};
            if (smt_res == SmtResult::Sat) {
                if (Config::Analysis::model) {
                cex.set_initial_state(solver->model());
                    if (!cex.try_final_transition(r)) {
                        throw std::logic_error("constructing cex failed");
                    }
                }
                return SmtResult::Unsat;
            } else if (smt_res == SmtResult::Unsat) {
                remove.emplace_back(r);
            }
        }
    }
    for (const auto &r: remove) {
        its->removeRule(r);
    }
    if (its->isEmpty()) {
        return SmtResult::Sat;
    } else if (remove.empty()) {
        return std::optional<SmtResult>{};
    } else {
        return SmtResult::Unknown;
    }
}

std::optional<SmtResult> check_bot(ITSPtr its) {
    std::vector<RulePtr> remove;
    for (const auto &r: its->getAllTransitions()) {
        if (r->getGuard() == bot()) {
            remove.emplace_back(r);
        }
    }
    for (const auto &r: remove) {
        its->removeRule(r);
    }
    if (its->isEmpty()) {
        return SmtResult::Sat;
    } else if (remove.empty()) {
        return std::optional<SmtResult>{};
    } else {
        return SmtResult::Unknown;
    }
}

SmtResult Preprocessor::preprocess() {
    if (Config::Analysis::doLogPreproc()) {
        std::cout << "starting preprocesing..." << std::endl;
    }
    if (Config::Analysis::safety()) {
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "removing irrelevant clauses..." << std::endl;
        }
        success |= remove_irrelevant_clauses(its);
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "finished removing irrelevant clauses" << std::endl;
        }
    }
    if (Config::Analysis::doLogPreproc()) {
        std::cout << "chaining linear paths..." << std::endl;
    }
    success |= chain.chainLinearPaths();
    if (Config::Analysis::doLogPreproc()) {
        std::cout << "finished chaining linear paths" << std::endl;
    }
    if (Config::Analysis::doLogPreproc()) {
        std::cout << "checking empty clauses..." << std::endl;
    }
    auto sat_res {check_empty_clauses(its)};
    if (Config::Analysis::doLogPreproc()) {
        std::cout << "finished checking empty clauses" << std::endl;
    }
    if (sat_res && sat_res != SmtResult::Unknown) {
        success = true;
        return *sat_res;
    }
    success |= bool(sat_res);
    if (Config::Analysis::doLogPreproc()) {
        std::cout << "preprocessing rules..." << std::endl;
    }
    sat_res = rule_preproc.run();
    if (sat_res && sat_res != SmtResult::Unknown) {
        success = true;
        return *sat_res;
    }
    success |= bool(sat_res);
    if (Config::Analysis::doLogPreproc()) {
        std::cout << "finished preprocessing rules" << std::endl;
    }
    if (Config::Analysis::engine == Config::Analysis::ADCL) {
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "unrolling..." << std::endl;
        }
        success |= unroll(its);
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "finished unrolling" << std::endl;
        }
        if (its->size() <= 1000) {
            if (Config::Analysis::doLogPreproc()) {
                std::cout << "refining the dependency graph..." << std::endl;
            }
            success |= refine_dependency_graph(its);
            if (Config::Analysis::doLogPreproc()) {
                std::cout << "finished refining the dependency graph" << std::endl;
            }
        }
    }
    return SmtResult::Unknown;
}
