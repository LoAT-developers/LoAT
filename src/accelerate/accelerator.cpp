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
#include "vareliminator.hpp"
#include "preprocess.hpp"
#include "recursionacceleration.hpp"
#include "rule.hpp"
#include "chain.hpp"
#include "loopacceleration.hpp"
#include "asymptoticbound.hpp"

#include <queue>
#include <stdexcept>

using namespace std;

Accelerator::Accelerator(ITSProblem &its, LocationIdx loc, std::set<TransIdx> &resultingRules)
    : its(its), targetLoc(loc), resultingRules(resultingRules)
{
    // We need a sink location for INF rules and nonlinear rules
    // To avoid too many parallel rules (which would then be pruned), we use a new one for each run
    sinkLoc = its.addLocation();
}


option<TransIdx> Accelerator::addResultingRule(Rule rule) {
    TransIdx idx = its.addRule(rule);
    resultingRules.insert(idx);
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

Result<std::vector<Rule>> Accelerator::instantiate(const NumVar &n, const Rule &rule) const {
    Result<std::vector<Rule>> res;
    // gather all upper bounds (if possible)
    VarEliminator ve(rule.getGuard(), n, its);
    // avoid rule explosion (by not instantiating N if there are too many bounds)
    if (ve.getRes().empty() || ve.getRes().size() > Config::LoopAccel::MaxUpperboundsForPropagation) {
        return res;
    }
    // create one rule for each upper bound, by instantiating N with this bound
    for (const auto &s : ve.getRes()) {
        if (s.get<IntTheory>(n).isRationalConstant()) continue;
        const auto instantiated = rule.subs(Subs::build<IntTheory>(s.get<IntTheory>()));
        res->push_back(instantiated);
        res.ruleTransformationProof(rule, "instantiation", instantiated, its);
        res.succeed();
    }
    return res;
}

Result<std::vector<Rule>> Accelerator::accelerate(const LinearRule &rule, Complexity cpx) const {
    const auto accelRes = LoopAcceleration::accelerate(its, rule, sinkLoc, cpx);
    Result<std::vector<Rule>> res;
    if (accelRes.rule && accelRes.n) {
        res.succeed();
        res.storeSubProof(accelRes.proof);
        res->push_back(*accelRes.rule);
        const auto instantiationRes = instantiate(*accelRes.n, *accelRes.rule);
        if (instantiationRes) {
            res.concat(instantiationRes);
        }
    }
    if (accelRes.nontermRule) {
        res.succeed();
        res->push_back(*accelRes.nontermRule);
        res.storeSubProof(accelRes.nontermProof);
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
        const auto accel = accelerate(nestedRule, currentCpx);
        if (accel) {
            proof.chainingProof(first, second, nestedRule, its);
            proof.concat(accel.getProof());
            for (const auto &accelRule: *accel) {
                if (Config::Analysis::nonTermination() && !accelRule.getCost().isNontermSymbol()) {
                    continue;
                }
                // Add the new rule
                addResultingRule(accelRule);
                // Try to combine chain and the accelerated loop
                auto chained = Chaining::chainRules(its, second, accelRule);
                if (chained) {
                    addResultingRule(chained.get());
                    proof.chainingProof(second, accelRule, chained.get(), its);
                }
            }
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
        deleted.insert(loop);
        its.removeRule(loop);
    }
    this->proof.deletionProof(deleted);
}

unsigned int Accelerator::numNotInUpdate(const Subs &up) const {
    unsigned int res = 0;
    for (auto const &p: up.get<IntTheory>()) {
        const auto &x = p.first;
        const auto &vars = p.second.vars();
        if (!vars.empty() && vars.find(x) == vars.end()) {
            res++;
        }
    }
    return res;
}

// ###################
// ## Acceleration  ##
// ###################

Result<std::vector<Rule>> Accelerator::tryAccelerate(const Rule &rule, Complexity cpx) const {
    // Forward acceleration
    if (!rule.isLinear()) {
        Result<std::vector<Rule>> res;
        const auto accel = RecursionAcceleration::accelerate(its, rule, sinkLoc);
        if (accel.rule) {
            res.succeed();
            res->push_back(*accel.rule);
            res.storeSubProof(accel.proof);
        }
        if (accel.nontermRule) {
            res.succeed();
            res->push_back(*accel.nontermRule);
            res.storeSubProof(accel.nontermProof);
        }
        return res;
    } else {
        return accelerate(rule.toLinear(), cpx);
    }
}


Result<std::vector<Rule>> Accelerator::accelerateOrShorten(const Rule &rule, Complexity cpx) const {
    using namespace RecursionAcceleration;

    // Accelerate the original rule
    auto res = tryAccelerate(rule, cpx);

    // Stop if heuristic is not applicable or acceleration was already successful
    if (!Config::Accel::PartialDeletionHeuristic || rule.isLinear()) {
        return res;
    }
    if (res) {
        return res;
    }

    // Remember the original result (we return this in case shortening fails)
    auto originalRes = res;

    // Helper lambda that calls tryAccelerate and adds to the proof output.
    // Returns true if accelerating was successful.
    auto tryAccel = [&](const Rule &newRule) {
        const auto subRes = tryAccelerate(newRule, cpx);
        if (subRes) {
            res.ruleTransformationProof(rule, "partial deletion", newRule, its);
            res.concat(subRes);
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
                            r.getGuard()->transform<IntTheory>(),
                            r.getCost()).cpx;
            origRules.emplace(loop, NestingCandidate{loop, loop, cpx});
        }
    }

    // Try to accelerate all loops
    for (TransIdx loop : loops) {
        // Forward and backward accelerate (and partial deletion for nonlinear rules)
        const Rule r = its.getRule(loop);
        Complexity cpx = r.isLinear() ? origRules[loop].cpx : Complexity::Unknown;
        const auto res = accelerateOrShorten(r, cpx);

        // Interpret the results, add new rules
        if  (res) {
            // Add accelerated rules, also mark them as inner nesting candidates
            this->proof.concat(res.getProof());
            for (const auto &accel : *res) {
                option<TransIdx> added = addResultingRule(accel);

                if (accel.isSimpleLoop() && added) {
                    Complexity cpx =
                            Config::Analysis::nonTermination() ?
                                Complexity::Unknown :
                                AsymptoticBound::determineComplexityViaSMT(
                                    its,
                                    accel.getGuard()->transform<IntTheory>(),
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

    // Remove old rules
    removeOldLoops(loops);

    // Remove sink location if we did not need it
    if (!its.hasTransitionsTo(sinkLoc)) {
        its.removeOnlyLocation(sinkLoc);
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
