#include "pair.hpp"
#include "dependencygraph.hpp"
#include "preprocessing.hpp"
#include "config.hpp"
#include "formulapreprocessing.hpp"
#include "loopacceleration.hpp"
#include "rulepreprocessing.hpp"
#include "chcpreprocessing.hpp"
#include "smtfactory.hpp"
#include "theory.hpp"

#include <numeric>
#include <unordered_set>

bool remove_irrelevant_clauses(ITSProblem &its, bool forward) {
    std::unordered_set<TransIdx> keep;
    std::stack<TransIdx> todo;
    for (const auto x : forward ? its.getInitialTransitions() : its.getSinkTransitions()) {
        todo.push(x);
    }
    do {
        const TransIdx current = todo.top();
        todo.pop();
        keep.insert(current);
        for (const auto p : forward ? its.getSuccessors(current) : its.getPredecessors(current)) {
            if (keep.find(p) == keep.end()) {
                todo.push(p);
            }
        }
    } while (!todo.empty());
    std::vector<TransIdx> to_delete;
    for (const auto &r : its.getAllTransitions()) {
        if (keep.find(&r) == keep.end()) {
            to_delete.push_back(&r);
        }
    }
    linked_hash_set<TransIdx> deleted;
    for (const auto idx : to_delete) {
        its.removeRule(idx);
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

bool remove_irrelevant_clauses(ITSProblem &its) {
    return remove_irrelevant_clauses(its, true) || remove_irrelevant_clauses(its, false);
}

bool chainLinearPaths(ITSProblem &its) {
    auto success{false};
    bool changed{false};
    do {
        changed = false;
        for (const auto &first : its.getAllTransitions()) {
            const auto succ{its.getSuccessors(&first)};
            if (succ.size() == 1 && !succ.contains(&first)) {
                const auto second_idx{*succ.begin()};
                if (!its.isSimpleLoop(second_idx)) {
                    success = true;
                    const auto chained{Preprocess::chain(first, *second_idx).first};
                    its.addRule(chained, &first, second_idx);
                    linked_hash_set<TransIdx> deleted;
                    deleted.insert(&first);
                    if (its.getPredecessors(second_idx).size() == 1) {
                        deleted.insert(second_idx);
                    }
                    if (Config::Analysis::doLogPreproc()) {
                        std::cout << "chaining\n\trule 1: " << first << "\n\trule 2: " << *second_idx << "\n\tresult: " << chained << std::endl;
                        std::cout << "removed the following rules after chaining: " << deleted << std::endl;
                    }
                    for (const auto &idx : deleted) {
                        its.removeRule(idx);
                    }
                    changed = true;
                    break;
                }
            }
        }
    } while (changed);
    return success;
}

bool Preprocess::chainLinearPaths(CHCProblem &chcs) {
    auto success{false};
    DependencyGraph<const Clause *> dg;
    const auto &clauses{chcs.get_clauses()};
    for (auto it1 = clauses.begin(); it1 != clauses.end(); ++it1) {
        for (auto it2 = it1; it2 != clauses.end(); ++it2) {
            if (it1->get_conclusion() && it1->get_conclusion()->get_pred() == it2->get_premise()->get_pred()) {
                dg.addEdge(&*it1, &*it2);
            }
            if (it2->get_conclusion() && it2->get_conclusion()->get_pred() == it1->get_premise()->get_pred()) {
                dg.addEdge(&*it2, &*it1);
            }
        }
    }
    bool changed{false};
    do {
        changed = false;
        for (const auto &first : chcs.get_clauses()) {
            const auto succ{dg.getSuccessors(&first)};
            if (succ.size() == 1 && !succ.contains(&first)) {
                const auto second_idx{*succ.begin()};
                if (!dg.hasEdge(second_idx, second_idx)) {
                    success = true;
                    const auto chained{chcs.add_clause(Preprocess::chain(first, *second_idx))};
                    for (const auto &s : dg.getSuccessors(second_idx)) {
                        dg.addEdge(chained, s);
                    }
                    for (const auto &p : dg.getPredecessors(&first)) {
                        dg.addEdge(p, chained);
                    }
                    linked_hash_set<const Clause *> deleted;
                    deleted.insert(&first);
                    if (dg.getPredecessors(second_idx).size() == 1) {
                        deleted.insert(second_idx);
                    }
                    for (const auto idx : deleted) {
                        dg.removeNode(idx);
                        chcs.remove_clause(*idx);
                    }
                    changed = true;
                    break;
                }
            }
        }
    } while (changed);
    return success;
}

bool preprocessRules(ITSProblem &its) {
    auto success{false};
    linked_hash_map<TransIdx, Rule> replacements;
    for (const auto &r : its.getAllTransitions()) {
        if (const auto res {Preprocess::preprocessRule(r)}) {
            success = true;
            replacements.emplace(&r, *res);
        }
    }
    for (const auto &[idx, replacement] : replacements) {
        its.replaceRule(idx, replacement);
    }
    return success;
}

/**
 * Motivating example: f(x,y) -> f(-x,z) :|: (y=0 /\ z=1) \/ (y=1 /\ z=0)
 * In contrast to its implicants, it can be unrolled to obtain simpler closed forms.
 */
bool unroll(ITSProblem &its) {
    auto success{false};
    for (const auto &r : its.getAllTransitions()) {
        if (its.isSimpleLoop(&r) && !r.getGuard()->isConjunction()) {
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
                its.addRule(res, &r, &r);
            }
        }
    }
    return success;
}

bool refine_dependency_graph(ITSProblem &its) {
    const auto is_edge = [](const TransIdx fst, const TransIdx snd) {
        return SmtFactory::check(Preprocess::chain(*fst, *snd).first.getGuard()) == Sat;
    };
    const auto removed{its.refineDependencyGraph(is_edge)};
    if (removed.empty()) {
        return false;
    } else {
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "removed the following edges from the dependency graph: " << removed << std::endl;
        }
        return true;
    }
}

bool Preprocess::preprocess(ITSProblem &its) {
    auto success {false};
    if (Config::Analysis::doLogPreproc()) {
        std::cout << "starting preprocesing..." << std::endl;
    }
    if (Config::Analysis::reachability()) {
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
    success |= chainLinearPaths(its);
    if (Config::Analysis::doLogPreproc()) {
        std::cout << "finished chaining linear paths" << std::endl;
    }
    if (Config::Analysis::doLogPreproc()) {
        std::cout << "preprocessing rules..." << std::endl;
    }
    success |= preprocessRules(its);
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
        if (its.size() <= 1000) {
            if (Config::Analysis::doLogPreproc()) {
                std::cout << "refining the dependency graph..." << std::endl;
            }
            success |= refine_dependency_graph(its);
            if (Config::Analysis::doLogPreproc()) {
                std::cout << "finished refining the dependency graph" << std::endl;
            }
        }
    }
    return success;
}

bool Preprocess::preprocess(SafetyProblem &p) {
    auto success {false};
    const auto init{Preprocess::preprocessFormula(p.init(), theory::isTempVar)};
    if (init != p.init()) {
        success = true;
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "preprocessed initial states\n\told: " << p.init() << "\n\tnew: " << init << std::endl;
        }
        p.set_init(init);
    }
    linked_hash_map<Bools::Expr, Bools::Expr> replacements;
    for (const auto &t : p.trans()) {
        const auto trans{Preprocess::preprocessFormula(t, theory::isTempVar)};
        if (trans != t) {
            replacements.emplace(t, trans);
        }
    }
    if (!replacements.empty()) {
        success = true;
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "preprocessed transitions\n";
        }
        for (const auto &[o,n]: replacements) {
            if (Config::Analysis::doLogPreproc()) {
               std::cout << "\told: " << o << "\n\tnew: " << n << std::endl;
            }
            p.replace_transition(o, n);
        }
    }
    const auto err{Preprocess::preprocessFormula(p.err(), theory::isTempVar)};
    if (err != p.err()) {
        success = true;
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "preprocessed error states\n\told: " << p.err() << "\n\tnew: " << err << std::endl;
        }
        p.set_err(err);
    }
    return success;
}
