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

using namespace std;

ResultViaSideEffects remove_irrelevant_clauses(ITSProblem &its, bool forward) {
    std::set<TransIdx> keep;
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
    std::vector<LocationIdx> to_delete;
    for (const auto idx: its.getAllTransitions()) {
        if (keep.find(idx) == keep.end()) {
            to_delete.push_back(idx);
        }
    }
    std::set<TransIdx> deleted;
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
    bool changed;
    do {
        changed = false;
        for (const auto first_idx: its.getAllTransitions()) {
            const auto succ {its.getSuccessors(first_idx)};
            if (succ.size() == 1 && succ.find(first_idx) == succ.end()) {
                const auto second_idx {*succ.begin()};
                if (!its.isSimpleLoop(second_idx)) {
                    const auto &first {its.getRule(first_idx)};
                    auto second {its.getRule(second_idx)};
                    std::set<TransIdx> deleted {first_idx};
                    if (its.getPredecessors(second_idx).size() == 1) {
                        deleted.insert(second_idx);
                    }
                    res.succeed();
                    const auto chained {Chaining::chain(first, second).first};
                    its.addRule(chained, first_idx, second_idx);
                    res.chainingProof(first, second, chained);
                    for (const auto &idx: deleted) {
                        its.removeRule(idx);
                    }
                    res.deletionProof(deleted);
                    changed = true;
                }
            }
        }
    } while (changed);
    return res;
}

ResultViaSideEffects preprocessRules(ITSProblem &its) {
    ResultViaSideEffects ret;
    for (const TransIdx idx: its.getAllTransitions()) {
        const auto res = Preprocess::preprocessRule(its.getRule(idx));
        if (res) {
            ret.succeed();
            its.replaceRule(idx, *res);
            ret.concat(res.getProof());
        }
    }
    return ret;
}

ResultViaSideEffects unroll(ITSProblem &its) {
    ResultViaSideEffects ret;
    for (const TransIdx idx: its.getAllTransitions()) {
        const Rule &r = its.getRule(idx);
        if (its.isSimpleLoop(idx)) {
            const auto [res, period] = LoopAcceleration::chain(r);
            if (period > 1) {
                const auto simplified = Preprocess::preprocessRule(res);
                ret.succeed();
                ret.ruleTransformationProof(r, "Unrolling", res);
                if (simplified) {
                    ret.concat(simplified.getProof());
                }
                its.addRule(*simplified, idx, idx);
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
    if (Config::Analysis::reachability()) {
        sub_res = remove_irrelevant_clauses(its);
        if (sub_res) {
            res.succeed();
            res.majorProofStep("Removed Irrelevant Clauses", sub_res.getProof(), its);
        }
    }
    sub_res = chainLinearPaths(its);
    if (sub_res) {
        res.succeed();
        res.majorProofStep("Chained Linear Paths", sub_res.getProof(), its);
    }
    sub_res = preprocessRules(its);
    if (res) {
        res.succeed();
        res.majorProofStep("Preprocessed Transitions", sub_res.getProof(), its);
    }
    sub_res = unroll(its);
    if (res) {
        res.majorProofStep("Unrolled Loops", sub_res.getProof(), its);
    }
    if (its.size() <= 1000) {
        sub_res = refine_dependency_graph(its);
        if (res) {
            res.majorProofStep("Refined Dependency Graph", sub_res.getProof(), its);
        }
    }
    return res;
}
