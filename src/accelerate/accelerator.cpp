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

#include "accelerator.hpp"

#include "../analysis/preprocess.hpp"
#include "recurrence/recurrence.hpp"
#include "meter/metering.hpp"
#include "../smt/smt.hpp"

#include "../its/rule.hpp"
#include "../its/export.hpp"

#include "../analysis/chain.hpp"
#include "../analysis/prune.hpp"

#include "loopacceleration.hpp"

#include <queue>
#include "../asymptotic/asymptoticbound.hpp"
#include <stdexcept>
#include <numeric>
#include "../smt/z3/z3.hpp"

using namespace std;

Accelerator::Accelerator(ITSProblem &its, LocationIdx loc, std::set<TransIdx> &resultingRules)
    : its(its), targetLoc(loc), resultingRules(resultingRules)
{
    // We need a sink location for INF rules and nonlinear rules
    // To avoid too many parallel rules (which would then be pruned), we use a new one for each run
    sinkLoc = its.addLocation();
}


option<TransIdx> Accelerator::addResultingRule(Rule rule) {
    option<TransIdx> idx = its.addRule(rule);
    if (idx) {
        resultingRules.insert(idx.get());
    }
    return idx;
}


// #####################
// ##  Preprocessing  ##
// #####################

bool Accelerator::simplifySimpleLoops() {
    bool res = false;
    vector<TransIdx> loops = its.getSimpleLoopsAt(targetLoc);

    // Simplify all simple loops.
    // This is especially useful to eliminate temporary variables before metering.
    if (Config::Accel::SimplifyRulesBefore) {
        for (auto it = loops.begin(), end = loops.end(); it != end; ++it) {
            const Rule rule = its.getRule(*it);
            Result<Rule> simplified = Preprocess::simplifyRule(its, rule, false);
            if (simplified) {
                this->proof.ruleTransformationProof(rule, "simplification", simplified.get(), its);
                std::vector<TransIdx> newIdx = its.replaceRules({*it}, {simplified.get()});
                for (TransIdx i: newIdx) {
                    *it = i;
                    res = true;
                }
            }
        }
    }
    if (res) {
        this->proof.minorProofStep("Simplified simple loops", its);
    }

    return res;
}


// ########################
// ##  Nesting of Loops  ##
// ########################

void Accelerator::nestRules(const NestingCandidate &fst, const NestingCandidate &snd) {
    // Avoid nesting a loop with its original transition or itself
    if (fst.oldRule == snd.oldRule) {
        return;
    }
    const LinearRule first = its.getLinearRule(fst.newRule);
    const LinearRule second = its.getLinearRule(snd.newRule);

    if (first.getGuard()->size() > 20 || second.getGuard()->size() > 20) return;

    if (first.getCost().isNontermSymbol() || second.getCost().isNontermSymbol()) {
        return;
    }

    auto optNested = Chaining::chainRules(its, first, second);
    if (optNested) {
        // Simplify the rule again (chaining can introduce many useless constraints)
        Result<Rule> simplified = Preprocess::simplifyRule(its, optNested.get(), true);
        LinearRule nestedRule = simplified ? simplified.get().toLinear() : optNested.get();

        // Note that we do not try all heuristics or backward accel to keep nesting efficient
        Complexity currentCpx = fst.cpx > snd.cpx ? fst.cpx : snd.cpx;
        const Acceleration::Result &accel = LoopAcceleration::accelerate(its, nestedRule, sinkLoc, currentCpx);
        Proof proof;
        proof.chainingProof(first, second, nestedRule, its);
        proof.concat(accel.proof);
        bool success = false;
        for (const auto &accelRule: accel.rules) {
            if (Config::Analysis::nonTermination() && !accelRule.getCost().isNontermSymbol()) continue;
            success = true;
            // Add the new rule
            addResultingRule(accelRule);
            // Try to combine chain and the accelerated loop
            auto chained = Chaining::chainRules(its, second, accelRule);
            if (chained) {
                addResultingRule(chained.get());
                proof.chainingProof(second, accelRule, chained.get(), its);
            }
        }
        if (success) {
            this->proof.concat(proof);
        }
    }
}


void Accelerator::performNesting(std::unordered_map<TransIdx, NestingCandidate> origRules, std::vector<NestingCandidate> todo) {
    for (const auto &in : origRules) {
        for (const auto &out : origRules) {
            nestRules(in.second, out.second);
        }
    }
    for (const auto &in : origRules) {
        for (const NestingCandidate &out : todo) {
            nestRules(in.second, out);
            nestRules(out, in.second);
        }
    }
}


// ############################
// ## Removal (cleaning up)  ##
// ############################

void Accelerator::removeOldLoops(const vector<TransIdx> &loops) {
    // Remove all old loops, unless we have decided to keep them
    std::set<TransIdx> deleted;
    for (TransIdx loop : loops) {
        if (keepRules.count(loop) == 0) {
            deleted.insert(loop);
            its.removeRule(loop);
        }
    }
    this->proof.deletionProof(deleted);
}

const option<LinearRule> Accelerator::chain(const LinearRule &rule) const {
    bool chained = false;
    LinearRule res = rule;
    // chain if there are updates like x = -x + p
    for (const auto &p: rule.getUpdate()) {
        const Var var = p.first;
        const Expr up = p.second.expand();
        const VarSet upVars = up.vars();
        if (upVars.find(var) != upVars.end()) {
            if (up.isPoly() && up.degree(var) == 1) {
                const Expr coeff = up.coeff(var);
                if (coeff.isRationalConstant() && coeff.toNum().is_negative()) {
                    res = Chaining::chainRules(its, res, res, false).get();
                    chained = true;
                    break;
                }
            }
        }
    }
    // chain if there are updates like x = y; y = x
    VarMap<unsigned> cycleLength;
    auto up = res.getUpdate();
    for (const auto &p: up) {
        VarSet vars = p.second.vars();
        unsigned oldSize = 0;
        unsigned count = 0;
        while (oldSize != vars.size() && vars.find(p.first) == vars.end()) {
            oldSize = vars.size();
            count++;
            for (const auto& var: vars) {
                const auto it = up.find(var);
                if (it != up.end()) {
                    const auto newVars = it->second.vars();
                    vars.insert(newVars.begin(), newVars.end());
                }
            }
        }
        if (vars.find(p.first) != vars.end() && count > 0) {
            cycleLength[p.first] = count;
        }
    }
    if (!cycleLength.empty()) {
        chained = true;
        unsigned lcm = 1;
        for (const auto &e: cycleLength) {
            lcm = std::lcm(lcm, e.second);
        }
        for (unsigned i = 0; i < lcm; ++i) {
            res = Chaining::chainRules(its, res, res, false).get();
        }
    }
    // chain if it eliminates variables from an update
    bool changed;
    do {
        changed = false;
        up = res.getUpdate();
        for (const auto &p: up) {
            VarSet varsOneStep = p.second.vars();
            VarSet varsTwoSteps;
            for (const auto &var: varsOneStep) {
                const auto it = up.find(var);
                if (it != up.end()) {
                    const auto newVars = it->second.vars();
                    varsTwoSteps.insert(newVars.begin(), newVars.end());
                } else {
                    varsTwoSteps.insert(var);
                }
            }
            if (varsTwoSteps.size() < varsOneStep.size() && std::includes(varsOneStep.begin(), varsOneStep.end(), varsTwoSteps.begin(), varsTwoSteps.end())) {
                res = Chaining::chainRules(its, res, res, false).get();
                chained = true;
                changed = true;
                break;
            }
        }
    } while (changed);
    if (chained) {
        return res;
    } else {
        return {};
    }
}

unsigned int Accelerator::numNotInUpdate(const Subs &up) const {
    unsigned int res = 0;
    for (auto const &p: up) {
        const Var &x = p.first;
        const VarSet &vars = p.second.vars();
        if (!vars.empty() && vars.find(x) == vars.end()) {
            res++;
        }
    }
    return res;
}

// ###################
// ## Acceleration  ##
// ###################

const Acceleration::Result Accelerator::strengthenAndAccelerate(const LinearRule &rule, Complexity cpx) const {
    Acceleration::Result res;
    res.status = PartialSuccess;
    // chain rule if necessary
    const option<LinearRule> &optR = chain(rule);
    if (optR) {
        res.proof.ruleTransformationProof(rule, "unrolling", optR.get(), its);
    }
    LinearRule r = optR ? optR.get() : rule;
    bool sat = Smt::check(r.getGuard(), its) == Smt::Sat;
    // only proceed if the guard is sat
    if (sat) {
        Acceleration::Result accelRes = LoopAcceleration::accelerate(its, r, sinkLoc, cpx);
        if (!accelRes.rules.empty()) {
            res.status = accelRes.status;
            res.proof.concat(accelRes.proof);
            for (const auto &r: accelRes.rules) {
                res.rules.emplace_back(r);
            }
        }
    }
    if (res.rules.empty()) {
        res.status = Failure;
    }
    return res;
}

Acceleration::Result Accelerator::tryAccelerate(const Rule &rule, Complexity cpx) const {
    // Forward acceleration
    if (!rule.isLinear()) {
        return RecursionAcceleration::accelerate(its, rule, sinkLoc);
    } else {
        return strengthenAndAccelerate(rule.toLinear(), cpx);
    }

}


Acceleration::Result Accelerator::accelerateOrShorten(const Rule &rule, Complexity cpx) const {
    using namespace RecursionAcceleration;

    // Accelerate the original rule
    auto res = tryAccelerate(rule, cpx);

    // Stop if heuristic is not applicable or acceleration was already successful
    if (!Config::Accel::PartialDeletionHeuristic || rule.isLinear()) {
        return res;
    }
    if (res.status != Failure) {
        return res;
    }

    // Remember the original result (we return this in case shortening fails)
    auto originalRes = res;

    // Helper lambda that calls tryAccelerate and adds to the proof output.
    // Returns true if accelerating was successful.
    auto tryAccel = [&](const Rule &newRule) {
        res = tryAccelerate(newRule, cpx);
        if (res.status != Failure) {
            Proof proof;
            proof.ruleTransformationProof(rule, "partial deletion", newRule, its);
            proof.concat(res.proof);
            res.proof = proof;
            return true;
        }
        return false;
    };

    // If metering failed, we remove rhss to ease metering.
    // To keep the code efficient, we only try all pairs and each single rhs.
    // We start with pairs of rhss, since this can still yield exponential complexity.
    const vector<RuleRhs> rhss = rule.getRhss();

    for (unsigned int i=0; i < rhss.size(); ++i) {
        for (unsigned int j=i+1; j < rhss.size(); ++j) {
            vector<RuleRhs> newRhss{ rhss[i], rhss[j] };
            Rule newRule(rule.getLhs(), newRhss);
            if (tryAccel(newRule)) {
                return res;
            }
        }
    }

    for (RuleRhs rhs : rhss) {
        if (tryAccel(Rule(rule.getLhs(), rhs))) {
            return res;
        }
    }

    return originalRes;
}


// #####################
// ## Main algorithm  ##
// #####################

option<Proof> Accelerator::run() {
    // Simplifying rules might make it easier to find metering functions
    simplifySimpleLoops();

    // Since we might add accelerated loops, we store the list of loops before acceleration
    vector<TransIdx> loops = its.getSimpleLoopsAt(targetLoc);
    if (loops.empty()) {
        return {}; // may happen if rules get removed in simplifySimpleLoops
    }

    // While accelerating, collect rules that might be feasible for nesting
    // Inner candidates are accelerated rules, since they correspond to a loop within another loop.
    // Outer candidates are loops that cannot be accelerated on their own (because they are missing their inner loop)
    std::unordered_map<TransIdx, NestingCandidate> origRules;
    vector<NestingCandidate> nestingCandidates;
    for (TransIdx loop : loops) {
        const Rule r = its.getRule(loop);
        if (r.isLinear()) {
            Complexity cpx =
                    Config::Analysis::nonTermination() ?
                        Complexity::Unknown :
                        AsymptoticBound::determineComplexityViaSMT(
                            its,
                            r.getGuard(),
                            r.getCost()).cpx;
            origRules.emplace(loop, NestingCandidate{loop, loop, cpx});
        }
    }

    // Try to accelerate all loops
    for (TransIdx loop : loops) {
        // Forward and backward accelerate (and partial deletion for nonlinear rules)
        const Rule r = its.getRule(loop);
        Complexity cpx = r.isLinear() ? origRules[loop].cpx : Complexity::Unknown;
        Acceleration::Result res = accelerateOrShorten(r, cpx);

        if (res.status != Success) {
            keepRules.insert(loop);
        }

        // Interpret the results, add new rules
        if  (res.status != Failure) {
            // Add accelerated rules, also mark them as inner nesting candidates
            this->proof.concat(res.proof);
            for (const auto &accel : res.rules) {
                option<TransIdx> added = addResultingRule(accel);

                if (accel.isSimpleLoop() && added) {
                    Complexity cpx =
                            Config::Analysis::nonTermination() ?
                                Complexity::Unknown :
                                AsymptoticBound::determineComplexityViaSMT(
                                    its,
                                    accel.getGuard(),
                                    accel.getCost()).cpx;
                    // accel.rule is a simple loop iff the original was linear and not non-terminating.
                    nestingCandidates.push_back(NestingCandidate(loop, added.get(), cpx));
                }
            }
        }

    }

    // Nesting
    if (Config::Accel::TryNesting) {
        performNesting(std::move(origRules), std::move(nestingCandidates));
    }

    // Chaining accelerated rules amongst themselves would be another heuristic.
    // Although it helps in certain examples, it is currently not implemented
    // as it would most probably result in too many rules (and would thus be expensive).
    // It can easily be added in this place in the future, if desired.

    // Simplify the guards of accelerated rules.
    // Especially backward acceleration and nesting can introduce superfluous constraints.
    bool changed = false;
    std::set<TransIdx> toAdd;
    for (auto it = resultingRules.begin(); it != resultingRules.end();) {
        const Rule r = its.getRule(*it);
        const BoolExpr simplified = Z3::simplify(r.getGuard(), its);
        if (r.getGuard() != simplified) {
            const Rule &newR = r.withGuard(simplified);
            this->proof.ruleTransformationProof(r, "simplification", newR, its);
            std::vector<TransIdx> newIdx = its.replaceRules({*it}, {newR});
            toAdd.insert(newIdx.begin(), newIdx.end());
            it = resultingRules.erase(it);
        } else {
            ++it;
        }
    }

    resultingRules.insert(toAdd.begin(), toAdd.end());

    // Keep rules for which acceleration failed (maybe these rules are in fact not loops).
    // We add them to resultingRules so they are chained just like accelerated rules.
    for (TransIdx rule : keepRules) {
        resultingRules.insert(rule);
    }

    // Remove old rules
    removeOldLoops(loops);

    // Remove sink location if we did not need it
    if (!its.hasTransitionsTo(sinkLoc)) {
        its.removeOnlyLocation(sinkLoc);
    }

    if (changed) {
        this->proof.minorProofStep("Simplified guards", its);
    }
    return {this->proof};
}


// #######################
// ## Public interface  ##
// #######################

option<Proof> Accelerator::accelerateSimpleLoops(ITSProblem &its, LocationIdx loc, std::set<TransIdx> &resultingRules) {
    if (its.getSimpleLoopsAt(loc).empty()) {
        return {};
    }

    // Accelerate all loops (includes optimizations like nesting)
    Accelerator accel(its, loc, resultingRules);
    return accel.run();
}
