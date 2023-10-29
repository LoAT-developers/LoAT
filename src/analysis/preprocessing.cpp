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

// FIXME: for trivial ITS with no (reachable) initial locations or no (reachable) sinks, 
// we should return SAT, but due to this preprocessing step we will throw an error instead.
ResultViaSideEffects remove_irrelevant_clauses(ITSProblem &its, bool forward) {
    if (its.getInitialTransitions().size() == 0) {
        throw std::logic_error("remove_irrelevant_clauses: ITS has no initial transitions");
    }
    if (its.getSinkTransitions().size() == 0) {
        throw std::logic_error("remove_irrelevant_clauses: ITS has no sink transitions");
    }
 
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
    std::vector<TransIdx> to_delete;
    for (const auto &r: its.getAllTransitions()) {
        if (keep.find(&r) == keep.end()) {
            to_delete.push_back(&r);
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
        std::set<TransIdx> deleted;
        for (const auto &first: its.getAllTransitions()) {
            const auto succ {its.getSuccessors(&first)};
            if (succ.size() == 1 && succ.find(&first) == succ.end()) {
                const auto second_idx {*succ.begin()};
                if (!its.isSimpleLoop(second_idx)) {
                    deleted.insert(&first);
                    if (its.getPredecessors(second_idx).size() == 1) {
                        deleted.insert(second_idx);
                    }
                    res.succeed();
                    const auto chained {Chaining::chain(first, *second_idx).first};
                    its.addRule(chained, &first, second_idx);
                    res.chainingProof(first, *second_idx, chained);
                    changed = true;
                }
            }
        }
        for (const auto &idx: deleted) {
            its.removeRule(idx);
        }
        res.deletionProof(deleted);
    } while (changed);
    return res;
}

ResultViaSideEffects preprocessRules(ITSProblem &its) {
    ResultViaSideEffects ret;
    std::map<TransIdx, Rule> replacements;
    for (const auto &r: its.getAllTransitions()) {
        const auto res = Preprocess::preprocessRule(r);
        if (res) {
            ret.succeed();
            replacements.emplace(&r, *res);
            ret.concat(res.getProof());
        }
    }
    for (const auto &[idx, replacement]: replacements) {
        its.replaceRule(idx, replacement);
    }
    return ret;
}

ResultViaSideEffects unroll(ITSProblem &its) {
    ResultViaSideEffects ret;
    for (const auto &r: its.getAllTransitions()) {
        if (its.isSimpleLoop(&r)) {
            const auto [res, period] = LoopAcceleration::chain(r);
            if (period > 1) {
                const auto simplified = Preprocess::preprocessRule(res);
                ret.succeed();
                ret.ruleTransformationProof(r, "Unrolling", res);
                if (simplified) {
                    ret.concat(simplified.getProof());
                }
                its.addRule(*simplified, &r, &r);
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
    if (Config::Analysis::reachability() && its.nonLinearCHCs.size() == 0) {
        // In this preprocessing step we remove transitions, that are not "forward reachable"
        // from a initial location or "backward reachable" from a sink. Note, that this step
        // is not valid though, if the ITS contains non-linear CHCs. For example a sink might 
        // only be reachable via a non-linear CHCs, but because non-linear CHCs are not acounted
        // for in the dependency graph, we would remove the sink because it appears to be unreachable.
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

        /* 
            Chaining linear paths is also problematic in incremental mode, because
            we remove the chained rules/facts, which cuts-off paths that might be        
            reachable via a non-linear rule. For example, consider the CHC problem:

                fib(1,1)
                fib(2,1)
                fib(a,c) /\ fib(b,d) /\ b=a+1 ==> f(b+1,c+d)
                fib(5,5) ==> false

            The fact `fib(5,5)` is reachable so the problem should be UNSAT.
            However, when we compute the resolvents of the non-linear clause with 
            all facts we get:

                fib(0,c) ==> fib(2,c+1)              (R1)
                fib(1,c) ==> fib(3,c+1)              (R2)
                fib(2,d) ==> fib(3,d+1)              (R3)
                fib(3,y) ==> fib(4,d+1)              (R4)

            If we now chain linear paths we get:

                [fib(1,1), R2] = fib(3,2)
                [fib(2,1), R3] = fib(3,2)

                [fib(3,2), R4] = fib(4,3)

            At this point we remove all facts except `fib(4,3)` because in the
            linear context we can assume that all paths from these facts lead
            to `fib(4,3)` anyway. However in the non-linear context we need to
            keep `fib(3,2)` to derive `fib(5,5)`.

            QUESTION: We could add the chained rules to the ITS without removing
            the rules that are part of the chain. However, that's potentially a             
            lot of rules and is this really cheaper re-generating these rules 
            during search? Maybe we can just add the maximal paths instead of
            every prefix of every path.
        */
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
        if (!Config::Analysis::safety()) {
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
