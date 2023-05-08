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

#include "preprocess.hpp"
#include "expr.hpp"
#include "guardtoolbox.hpp"
#include "expr.hpp"
#include "chain.hpp"
#include "config.hpp"

#include <numeric>

using namespace std;

/**
 * Returns the set of all variables that appear in the rhs of some update.
 * For an update x := a and x := x+a, this is {a} and {x,a}, respectively.
 */
static VarSet collectVarsInUpdateRhs(const Rule &rule) {
    VarSet varsInUpdate;
    for (const auto &it : rule.getUpdate()) {
        expr::collectVars(expr::second(it), varsInUpdate);
    }
    return varsInUpdate;
}

Result<Rule> eliminateTempVars(const Rule &rule) {
    Result<Rule> res(rule);

    //declare helper lambdas to filter variables, to be passed as arguments
    auto isTemp = [&](const Var &sym) {
        return expr::isTempVar(sym);
    };
    auto isTempInUpdate = [&](const Var &sym) {
        VarSet varsInUpdate = collectVarsInUpdateRhs(*res);
        return isTemp(sym) && varsInUpdate.find(sym) != varsInUpdate.end();
    };
    auto isTempOnlyInGuard = [&](const Var &sym) {
        VarSet varsInUpdate = collectVarsInUpdateRhs(*res);
        return isTemp(sym) && varsInUpdate.find(sym) == varsInUpdate.end();
    };

    //equalities allow easy propagation, thus transform x <= y, x >= y into x == y
    res.concat(GuardToolbox::makeEqualities(*res));
    res.fail(); // *just* finding implied equalities does not suffice for success

    res.concat(GuardToolbox::propagateBooleanEqualities(*res));

    //try to remove temp variables from the update by equality propagation (they are removed from guard and update)
    res.concat(GuardToolbox::propagateEqualities(*res, ResultMapsToInt, isTempInUpdate));

    //try to remove all remaining temp variables (we do 2 steps to prioritize removing vars from the update)
    res.concat(GuardToolbox::propagateEqualities(*res, ResultMapsToInt, isTemp));

    BoolExpr guard = res->getGuard();
    BoolExpr newGuard = guard->simplify();
    if (newGuard.get() != guard.get()) {
        const Rule newRule = res->withGuard(newGuard);
        res.ruleTransformationProof(res.get(), "Simplified Guard", newRule);
        res = newRule;
    }

    //now eliminate a <= x and replace a <= x, x <= b by a <= b for all free variables x where this is sound
    //(not sound if x appears in update or cost, since we then need the value of x)
    res.concat(GuardToolbox::eliminateByTransitiveClosure(*res, true, isTempOnlyInGuard));

    return res;
}

bool removeTrivialUpdates(Subs &update) {
    stack<Var> remove;
    for (const auto &it : update) {
        const auto first = expr::first(it);
        const auto second = expr::second(it);
        if (TheTheory::varToExpr(first) == second) {
            remove.push(first);
        }
    }
    if (remove.empty()) return false;
    while (!remove.empty()) {
        update.erase(remove.top());
        remove.pop();
    }
    return true;
}

Result<Rule> removeTrivialUpdates(const Rule &rule) {
    bool changed = false;
    Subs up = rule.getUpdate();
    changed |= removeTrivialUpdates(up);
    Result<Rule> res{Rule(rule.getGuard(), up), changed};
    if (res) {
        res.ruleTransformationProof(rule, "Removed Trivial Updates", res.get());
    }
    return res;
}

Result<Rule> simplifyRule(const Rule &rule) {
    Result<Rule> res(rule);
    res.concat(eliminateTempVars(*res));
    res.concat(removeTrivialUpdates(*res));
    return res;
}

Result<Rule> Preprocess::preprocessRule(const Rule &rule) {
    Result<Rule> res(rule);

    // The other steps are repeated (might not help very often, but is probably cheap enough)
    bool changed = false;
    do {
        Result<Rule> tmp {simplifyRule(*res)};
        changed = bool(tmp);
        res.concat(tmp);
    } while (changed);
    return res;
}

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

ResultViaSideEffects Preprocess::preprocessRules(ITSProblem &its) {
    ResultViaSideEffects ret;
    for (const TransIdx idx: its.getAllTransitions()) {
        const auto res = preprocessRule(its.getRule(idx));
        if (res) {
            ret.succeed();
            its.replaceRule(idx, *res);
            ret.concat(res.getProof());
        }
    }
    return ret;
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
    sub_res = Preprocess::preprocessRules(its);
    if (res) {
        res.succeed();
        res.majorProofStep("Preprocessed Transitions", sub_res.getProof(), its);
    }
    return res;
}
