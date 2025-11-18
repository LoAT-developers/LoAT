#include "pair.hpp"
#include "dependencygraph.hpp"
#include "preprocessing.hpp"
#include "config.hpp"
#include "loopacceleration.hpp"
#include "rulepreprocessing.hpp"
#include "smtfactory.hpp"
#include "theory.hpp"

#include <unordered_set>
#include <stack>

Preprocessor::Preprocessor(const ITSPtr& its): its(its), chain(its), rule_preproc(its), cex(its) {}

bool Preprocessor::successful() const {
    return success;
}

ITSModel Preprocessor::transform_model(const ITSModel &model) const {
    return chain.transform_model(model);
}

ITSModel Preprocessor::get_model() const {
    ITSModel model;
    model.set_invariant(its->getInitialLocation(), top());
    return model;
}

const ITSSafetyCex& Preprocessor::get_cex() const {
    return cex;
}

bool remove_irrelevant_clauses(const ITSPtr& its, const bool forward) {
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
            if (!keep.contains(p)) {
                todo.push(p);
            }
        }
    } while (!todo.empty());
    std::vector<RulePtr> to_delete;
    for (const auto &r : its->getAllTransitions()) {
        if (!keep.contains(r)) {
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
    }
    if (Config::Analysis::doLogPreproc()) {
        std::cout << "removed the following irrelevant transitions: " << deleted << std::endl;
    }
    return true;
}

bool remove_irrelevant_clauses(const ITSPtr& its) {
    return remove_irrelevant_clauses(its, true) || remove_irrelevant_clauses(its, false);
}

/**
 * Motivating example: f(x,y) -> f(-x,z) :|: (y=0 /\ z=1) \/ (y=1 /\ z=0)
 * In contrast to its implicants, it can be unrolled to obtain simpler closed forms.
 */
bool unroll(const ITSPtr& its) {
    auto success{false};
    for (const auto &r : its->getAllTransitions()) {
        if (its->isSimpleLoop(r) && !r->getGuard()->isConjunction()) {
            if (const auto [res, period] = LoopAcceleration::chain(r); period > 1) {
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

bool refine_dependency_graph(const ITSPtr& its) {
    const auto is_edge = [](const RulePtr& fst, const RulePtr& snd) {
        return SmtFactory::check(Preprocess::chain({fst, snd->renameTmpVars()})->getGuard()) == SmtResult::Sat;
    };
    if (const auto removed{its->refineDependencyGraph(is_edge)}; removed.empty()) {
        return false;
    } else {
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "removed the following edges from the dependency graph: " << removed << std::endl;
        }
        return true;
    }
}

std::optional<SmtResult> Preprocessor::check_empty_clauses(const ITSPtr& its) {
    std::vector<RulePtr> remove;
    for (const auto &r: its->getInitialTransitions()) {
        if (its->isSinkTransition(r)) {
            const auto solver {SmtFactory::modelBuildingSolver(Smt::chooseLogic(r->getGuard()))};
            solver->add(r->getGuard());
            if (const auto smt_res {solver->check()}; smt_res == SmtResult::Sat) {
                if (Config::Analysis::model) {
                    cex.set_initial_state(solver->model());
                    cex.add_final_transition(r);
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
    }
    if (remove.empty()) {
        return std::optional<SmtResult>{};
    }
    return SmtResult::Unknown;
}

std::optional<SmtResult> check_bot(const ITSPtr& its) {
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
    }
    if (remove.empty()) {
        return std::optional<SmtResult>{};
    }
    return SmtResult::Unknown;
}

bool remove_irrelevant_vars(const ITSPtr& its) {
    const auto vars{its->getVars()};
    const auto trans{its->getAllTransitions()};
    std::unordered_map<RulePtr, VarSet> guard_vars;
    for (const auto& t : trans) {
        guard_vars.emplace(t, t->getGuard()->vars());
    }
    Subs remove;
    for (const auto& x : vars) {
        theory::apply(x, [&](const auto& x) {
            if (!x->isProgVar()) return;
            if (std::ranges::any_of(trans, [&](const auto& t) {
                return !t->isHavoced(x);
            })) {
                for (const auto& t : trans) {
                    if (guard_vars.at(t).contains(x) || std::ranges::any_of(t->getUpdate(), [&](const auto& p) {
                        return Subs::first(p) != Var(x) && theory::apply(Subs::second(p), [&](const auto& e) {
                            return e->vars().contains(x);
                        });
                    })) {
                        return;
                    }
                }
            }
            using T = decltype(theory::theory(x));
            remove.put(x, T::varToExpr(T::next(x->dim())));
            remove.put(x->postVar(), T::varToExpr(T::next(x->dim())));
        });
    }
    if (remove.empty()) {
        return false;
    }
    if (Config::Analysis::logPreproc) {
        std::cout << "removed the following irelevant variables: ";
        for (const auto& [x,_]: remove) {
            std::cout << " " << x;
        }
        std::cout << std::endl;
    }
    for (const auto& t: trans) {
        its->replaceRule(t, Rule::mk(t->getGuard()->subs(remove), t->getUpdate().project([&](const auto& x) {
            return !remove.contains(x);
        })));
    }
    return true;
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
    success |= static_cast<bool>(sat_res);
    if (Config::Analysis::doLogPreproc()) {
        std::cout << "preprocessing rules..." << std::endl;
    }
    bool changed;
    do {
        changed = false;
        sat_res = rule_preproc.run();
        if (sat_res) {
            if (sat_res != SmtResult::Unknown) {
                return *sat_res;
            }
            changed = true;
            success = true;
        }
        if (remove_irrelevant_vars(its)) {
            changed = true;
            success = true;
        }
    } while (changed);
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
