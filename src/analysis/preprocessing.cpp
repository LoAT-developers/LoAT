/*  This file is part of LoAT.
 *  Copyright (c) 2015-2016 Matthias Naaf, RWTH Aachen University, Germany
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses>.
 */

#include "preprocessing.hpp"
#include "rulepreprocessing.hpp"
#include "loopacceleration.hpp"
#include "chain.hpp"
#include "config.hpp"

#include <numeric>
#include <unordered_set>

using namespace std;

ResultViaSideEffects remove_irrelevant_clauses(ITSProblem &its, bool forward) {
    std::unordered_set<TransIdx> keep;
    std::stack<TransIdx> todo;
    for (const auto x: forward ? its.getInitialTransitions() : its.getSinkTransitions()) {
        todo.push(x);
    }
    do {
        const TransIdx current = todo.top();
        todo.pop();
        keep.insert(current);
        for (const auto p: forward ? its.getSuccessors(current) : its.getPredecessors(current)) {
            if (keep.find(p) == keep.end()) {
                todo.push(p);
            }
        }
    } while (!todo.empty());
    std::vector<TransIdx> to_delete;
    for (const auto &r: its.getAllTransitions()) {
        if (keep.find(&r) == keep.end()) {
            to_delete.push_back(&r);
        }
    }
    linked_hash_set<TransIdx> deleted;
    for (const auto idx: to_delete) {
        its.removeRule(idx);
        deleted.insert(idx);
    }
    ResultViaSideEffects ret;
    if (!deleted.empty()) {
        ret.succeed();
        ret.deletionProof(deleted);
    }
    return ret;
}

ResultViaSideEffects remove_irrelevant_clauses(ITSProblem &its) {
    auto res {remove_irrelevant_clauses(its, true)};
    res.concat(remove_irrelevant_clauses(its, false));
    return res;
}

ResultViaSideEffects chainLinearPaths(ITSProblem &its) {
    ResultViaSideEffects res;
    bool changed {false};
    do {
        changed = false;
        for (const auto &first: its.getAllTransitions()) {
            const auto succ {its.getSuccessors(&first)};
            if (succ.size() == 1 && !succ.contains(&first)) {
                const auto second_idx {*succ.begin()};
                if (!its.isSimpleLoop(second_idx)) {
                    res.succeed();
                    const auto chained {Chaining::chain(first, *second_idx).first};
                    its.addRule(chained, &first, second_idx);
                    res.chainingProof(chained, first, *second_idx);
                    linked_hash_set<TransIdx> deleted;
                    deleted.insert(&first);
                    if (its.getPredecessors(second_idx).size() == 1) {
                        deleted.insert(second_idx);
                    }
                    for (const auto &idx: deleted) {
                        its.removeRule(idx);
                    }
                    res.deletionProof(deleted);
                    changed = true;
                    break;
                }
            }
        }
    } while (changed);
    return res;
}

ResultViaSideEffects preprocessRules(ITSProblem &its) {
    ResultViaSideEffects ret;
    linked_hash_map<TransIdx, Rule> replacements;
    for (const auto &r: its.getAllTransitions()) {
        const auto res = Preprocess::preprocessRule(r);
        if (res) {
            ret.succeed();
            replacements.emplace(&r, *res);
            ret.storeSubProof(res.getProof());
        }
    }
    for (const auto &[idx, replacement]: replacements) {
        its.replaceRule(idx, replacement);
    }
    return ret;
}

/**
 * Motivating example: f(x,y) -> f(-x,z) :|: (y=0 /\ z=1) \/ (y=1 /\ z=0)
 * In contrast to its implicants, it can be unrolled to obtain simpler closed forms.
 */
ResultViaSideEffects unroll(ITSProblem &its) {
    ResultViaSideEffects ret;
    for (const auto &r: its.getAllTransitions()) {
        if (its.isSimpleLoop(&r) && !r.getGuard()->isConjunction()) {
            const auto [res, period] = LoopAcceleration::chain(r);
            if (period > 1) {
                RuleResult rr {res};
                rr.ruleTransformationProof(r, "Unrolling", res);
                rr.concat(Preprocess::preprocessRule(res));
                ret.succeed();
                ret.storeSubProof(rr.getProof());
                its.addRule(*rr, &r, &r);
            }
        }
    }
    return ret;
}

ResultViaSideEffects refine_dependency_graph(ITSProblem &its) {
    ResultViaSideEffects res;
    const auto removed {its.refineDependencyGraph()};
    if (!removed.empty()) {
        res.succeed();
        res.dependencyGraphRefinementProof(removed);
    }
    return res;
}

ResultViaSideEffects Preprocess::preprocess(ITSProblem &its) {
    ResultViaSideEffects res;
    ResultViaSideEffects sub_res;
    if (Config::Analysis::log) {
        std::cout << "starting preprocesing..." << std::endl;
    }
    if (Config::Analysis::reachability()) {
        if (Config::Analysis::log) {
            std::cout << "removing irrelevant clauses..." << std::endl;
        }
        sub_res = remove_irrelevant_clauses(its);
        if (Config::Analysis::log) {
            std::cout << "finished removing irrelevant clauses" << std::endl;
        }
        if (sub_res) {
            res.succeed();
            res.majorProofStep("Removed Irrelevant Clauses", sub_res.getProof(), its);
        }
    }
    if (Config::Analysis::log) {
        std::cout << "chaining linear paths..." << std::endl;
    }
    sub_res = chainLinearPaths(its);
    if (Config::Analysis::log) {
        std::cout << "finished chaining linear paths" << std::endl;
    }
    if (sub_res) {
        res.succeed();
        res.majorProofStep("Chained Linear Paths", sub_res.getProof(), its);
    }
    if (Config::Analysis::log) {
        std::cout << "preprocessing rules..." << std::endl;
    }
    sub_res = preprocessRules(its);
    if (Config::Analysis::log) {
        std::cout << "finished preprocessing rules" << std::endl;
    }
    if (sub_res) {
        res.succeed();
        res.majorProofStep("Preprocessed Transitions", sub_res.getProof(), its);
    }
    if (Config::Analysis::engine == Config::Analysis::ADCL) {
            if (Config::Analysis::log) {
                std::cout << "unrolling..." << std::endl;
            }
            sub_res = unroll(its);
            if (Config::Analysis::log) {
                std::cout << "finished unrolling" << std::endl;
            }
            if (sub_res) {
                res.succeed();
                res.majorProofStep("Unrolled Loops", sub_res.getProof(), its);
            }
        if (its.size() <= 1000) {
            if (Config::Analysis::log) {
                std::cout << "refining the dependency graph..." << std::endl;
            }
            sub_res = refine_dependency_graph(its);
            if (Config::Analysis::log) {
                std::cout << "finished refining the dependency graph" << std::endl;
            }
            if (sub_res) {
                res.succeed();
                res.majorProofStep("Refined Dependency Graph", sub_res.getProof(), its);
            }
        }
    }
    return res;
}

Result<SafetyProblem> Preprocess::preprocess(const SafetyProblem &p) {
    Result<SafetyProblem> res {p};
    auto first {true};
    for (const auto &t: p.trans()) {
        const auto preproc {Preprocess::preprocessTransition(t)};
        if (preproc) {
            if (first) {
                res.append("Preprocessed Transitions");
                first = false;
            }
            res.succeed();
            res->replace_transition(t, *preproc);
            res.storeSubProof(preproc.getProof());
        }
    }
    return res;
}
