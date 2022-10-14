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

#include "analysis.hpp"

#include "smt.hpp"
#include "asymptoticbound.hpp"

#include "timeout.hpp"
#include "merger.hpp"
#include "prune.hpp"
#include "preprocess.hpp"
#include "chain.hpp"
#include "chainstrategy.hpp"
#include "accelerator.hpp"
#include "export.hpp"
#include "yices.hpp"
#include "redlog.hpp"

#include <future>

using namespace std;



void Analysis::analyze(ITSProblem &its) {
    Analysis analysis(its);
    analysis.run();
}


Analysis::Analysis(ITSProblem &its)
        : its(its) {}


// ##############################
// ## Main Analysis Algorithm  ##
// ##############################

void Analysis::simplify(RuntimeResult &res, Proof &proof) {

    proof.majorProofStep("Initial ITS", its);

    if (Config::Analysis::complexity()) {
        const ResultViaSideEffects subProof = ensureNonnegativeCosts();
        if (subProof) {
            proof.minorProofStep("Ensure Cost >= 0", its);
            proof.storeSubProof(subProof.getProof());
        }
    }

    if (ensureProperInitialLocation()) {
        proof.minorProofStep("Added a fresh start location without incoming rules", its);
    }

    string eliminatedLocation; // for proof output of eliminateALocation
    bool acceleratedOnce = false; // whether we did at least one acceleration step
    bool nonlinearProblem = !its.isLinear(); // whether the ITS is (still) nonlinear

    // Check if we have at least constant complexity (i.e., at least one rule can be taken with cost >= 1)
    if (Config::Analysis::complexity()) {
        checkConstantComplexity(res, proof);
    }

    if (Pruning::removeLeafsAndUnreachable(its)) {
        proof.minorProofStep("Removed unreachable rules and leafs", its);
    }

    if (removeUnsatRules()) {
        proof.minorProofStep("Removed rules with unsatisfiable guard", its);
    }

    if (Pruning::removeLeafsAndUnreachable(its)) {
        proof.minorProofStep("Removed unreachable rules and leafs", its);
    }

    option<Proof> subProof = preprocessRules();
    if (subProof) {
        proof.concat(subProof.get());
        proof.minorProofStep("Simplified rules", its);
    }

    Proof mergingProof = Merger::mergeRules(its);
    if (!mergingProof.empty()) {
        proof.concat(mergingProof);
        proof.majorProofStep("Merged rules", its);
    }

    // We cannot prove any lower bound for an empty ITS
    if (its.isEmpty()) {
        return;
    }

    while (!isFullySimplified()) {

        // Repeat linear chaining and simple loop acceleration
        bool changed;
        do {
            changed = false;
            set<TransIdx> acceleratedRules;

            // Special handling of nonlinear rules
            if (nonlinearProblem && Pruning::removeSinkRhss(its)) {
                changed = true;
                proof.majorProofStep("Removed sinks", its);
            }

            ResultViaSideEffects accelerationProof = accelerateSimpleLoops(acceleratedRules);
            if (accelerationProof) {
                changed = true;
                acceleratedOnce = true;
                proof.majorProofStep("Accelerated simple loops", its);
                proof.storeSubProof(accelerationProof.getProof());
            }

            ResultViaSideEffects acceleratedChainingProof = Chaining::chainAcceleratedRules(its, acceleratedRules);;
            if (acceleratedChainingProof) {
                changed = true;
                proof.majorProofStep("Chained accelerated rules with incoming rules", its);
                proof.storeSubProof(acceleratedChainingProof.getProof());
            }

            if (Pruning::removeLeafsAndUnreachable(its)) {
                changed = true;
                proof.majorProofStep("Removed unreachable locations and irrelevant leafs", its);
            }

            ResultViaSideEffects linearChainingProof = Chaining::chainLinearPaths(its);
            if (linearChainingProof) {
                changed = true;
                proof.majorProofStep("Eliminated locations on linear paths", its);
                proof.storeSubProof(linearChainingProof.getProof());
            }

            // Check if the ITS is now linear (we accelerated all nonlinear rules)
            if (changed && nonlinearProblem) {
                nonlinearProblem = !its.isLinear();
            }
        } while (changed);

        // Avoid wasting time on chaining/pruning if we are already done
        if (isFullySimplified()) {
            break;
        }

        // Try more involved chaining strategies if we no longer make progress
        ResultViaSideEffects treeChainingProof = Chaining::chainTreePaths(its);
        if (treeChainingProof) {
            proof.majorProofStep("Eliminated locations on tree-shaped paths", its);
            proof.storeSubProof(treeChainingProof.getProof());

        } else {
            ResultViaSideEffects eliminationProof = eliminateALocation(eliminatedLocation);
            proof.majorProofStep("Eliminated location " + eliminatedLocation, its);
            proof.storeSubProof(eliminationProof.getProof());
        }
        if (isFullySimplified()) break;

        Proof mergingProof = Merger::mergeRules(its);
        if (!mergingProof.empty()) {
            proof.concat(mergingProof);
            proof.majorProofStep("Merged rules", its);
        }

        if (acceleratedOnce) {

            // Try to avoid rule explosion (often caused by chainTreePaths).
            // Since pruning relies on the rule's complexities, we only do this after the first acceleration.
            if (pruneRules()) {
                proof.majorProofStep("Applied pruning (of leafs and parallel rules):", its);
            }
        }

    }
}

void Analysis::finalize(RuntimeResult &res) {
    its.lock();
    if (!Timeout::soft()) {
        // Remove duplicate rules (ignoring updates) to avoid wasting time on asymptotic bounds
        std::set<TransIdx> removed = Pruning::removeDuplicateRules(its, its.getTransitionsFrom(its.getInitialLocation()), false);
        if (!removed.empty()) {
            res.majorProofStep("Removed duplicate rules (ignoring updates)", its);
        }
    }

    if (Config::Analysis::complexity()) {
        res.headline("Computing asymptotic complexity");
    } else {
        res.headline("Proving reachability");
    }

    if (Timeout::soft()) {
        // A timeout occurred before we managed to complete the analysis.
        // We try to quickly extract at least some complexity results.
        // Reduce the number of rules to avoid z3 invocations
        removeConstantPathsAfterTimeout();
        // Try to find a high complexity in the remaining problem (with chaining, but without acceleration)
        getMaxPartialResult(res);
    } else {
        // No timeout, fully simplified, find the maximum runtime
        getBestResult(res);
    }
}

void Analysis::run() {
    yices::init();
    Redlog::init();

    Proof *proof = new Proof();
    RuntimeResult *res = new RuntimeResult();
    auto simp = std::async([this, res, proof]{this->simplify(*res, *proof);});
    if (Timeout::enabled()) {
        if (simp.wait_for(Timeout::remainingSoft()) == std::future_status::timeout) {
            std::cerr << "Aborted simplification due to soft timeout" << std::endl;
        }
    } else {
        simp.wait();
    }
    auto finalize = std::async([this, res]{this->finalize(*res);});
    if (Timeout::enabled()) {
        std::chrono::seconds remaining = Timeout::remainingHard();
        if (remaining.count() > 0) {
            if (finalize.wait_for(remaining) == std::future_status::timeout) {
                std::cerr << "Aborted analysis of simplified ITS due to timeout" << std::endl;
            }
        }
    } else {
        finalize.wait();
    }
    res->lock();
    proof->concat(res->getProof());
    printResult(*proof, *res);
    // WST style proof output
    cout << res->getCpx().toWstString() << std::endl;
    proof->print();

    delete res;
    delete proof;

    Redlog::exit();
    yices::exit();

    bool simpDone = simp.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
    bool finalizeDone = finalize.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
    // propagate exceptions
    if (simpDone) {
        simp.get();
    }
    if (finalizeDone) {
        finalize.get();
    }
    if (!simpDone || !finalizeDone) {
        std::cerr << "some tasks are still running, calling std::terminate" << std::endl;
        std::terminate();
    }
}

// ############################
// ## Preprocessing, Output  ##
// ############################

bool Analysis::ensureProperInitialLocation() {
    if (its.hasTransitionsTo(its.getInitialLocation())) {
        LocationIdx newStart = its.addLocation();
        its.addRule(Rule::dummyRule(newStart, its.getInitialLocation()));
        its.setInitialLocation(newStart);
        return true;
    }
    return false;
}


ResultViaSideEffects Analysis::ensureNonnegativeCosts() {
    ResultViaSideEffects proof;
    std::vector<TransIdx> del;
    std::vector<Rule> add;
    for (TransIdx trans : its.getAllTransitions()) {
        const Rule rule = its.getRule(trans);
        // Add the constraint unless it is trivial (e.g. if the cost is 1).
        Rel costConstraint = rule.getCost() >= 0;
        if (!costConstraint.isTriviallyTrue()) {
            del.push_back(trans);
            const Rule &r = rule.withGuard(rule.getGuard() & costConstraint);
            add.push_back(r);
            proof.ruleTransformationProof(rule, "strengthening", r, its);
            proof.succeed();
        }
    }
    its.replaceRules(del, add);
    return proof;
}


bool Analysis::removeUnsatRules() {
    bool changed = false;

    for (TransIdx rule : its.getAllTransitions()) {
        if (SmtFactory::check<IntTheory, BoolTheory>(its.getRule(rule).getGuard(), its) == Unsat) {
            its.removeRule(rule);
            changed = true;
        }
    }

    return changed;
}


Proof Analysis::preprocessRules() {
    Proof proof;
    std::vector<TransIdx> del;
    std::vector<Rule> add;
    // update/guard preprocessing
    for (TransIdx idx : its.getAllTransitions()) {
        const Rule rule = its.getRule(idx);
        const Result<Rule> newRule = Preprocess::preprocessRule(its, rule);
        if (newRule) {
            del.push_back(idx);
            add.push_back(*newRule);
            proof.ruleTransformationProof(rule, "preprocessing", newRule.get(), its);
            proof.storeSubProof(newRule.getProof());
        }
    }
    its.replaceRules(del, add);
    return proof;
}


bool Analysis::isFullySimplified() const {
    for (LocationIdx node : its.getLocations()) {
        if (its.isInitialLocation(node)) continue;
        if (its.hasTransitionsFrom(node)) return false;
    }
    return true;
}


void Analysis::printResult(Proof &proof, RuntimeResult &res) {
    proof.newline();
    proof.result("Proved the following lower bound");
    proof.result(stringstream() << "Complexity:  " << res.getCpx());
    proof.result(stringstream() << res);
}


// ##############################
// ## Acceleration & Chaining  ##
// ##############################

ResultViaSideEffects Analysis::eliminateALocation(string &eliminatedLocation) {
    return Chaining::eliminateALocation(its, eliminatedLocation);
}

ResultViaSideEffects Analysis::accelerateSimpleLoops(set<TransIdx> &acceleratedRules) {
    ResultViaSideEffects proof;
    for (LocationIdx node : its.getLocations()) {
        option<Proof> subProof = Accelerator::accelerateSimpleLoops(its, node, acceleratedRules);
        if (subProof) {
            proof.concat(*subProof);
            proof.succeed();
        }
    }
    return proof;
}


bool Analysis::pruneRules() {
    // Always remove unreachable rules
    bool changed = Pruning::removeLeafsAndUnreachable(its);

    // Prune parallel transitions if enabled
    if (Config::Analysis::Pruning) {
        changed = Pruning::pruneParallelRules(its) || changed;
    }

    return changed;
}


// #############################
// ## Complexity Computation  ##
// #############################


void Analysis::checkConstantComplexity(RuntimeResult &res, Proof &proof) const {

    for (TransIdx idx : its.getTransitionsFrom(its.getInitialLocation())) {
        const Rule rule = its.getRule(idx);
        BoolExpr guard = rule.getGuard() & (rule.getCost() >= 1);

        if (SmtFactory::check(guard, its) == Sat) {
            proof.newline();
            proof.result("Proved Omega(1)");
            Proof subProof;
            subProof.append("The following rule witnesses the lower bound Omega(1):");
            stringstream s;
            ITSExport::printLabeledRule(idx, its, s);
            subProof.append(s);
            proof.storeSubProof(subProof);
            res.update(rule.getGuard(), rule.getCost(), rule.getCost(), Complexity::Const);
        }
    }
}

void Analysis::getBestResultOf(const std::set<TransIdx> &rules, RuntimeResult &res) {
    if (Config::Analysis::complexity()) {
        getMaxRuntimeOf(rules, res);
    } else {
        proveReachabilityOf(rules, res);
    }
}

void Analysis::proveReachabilityOf(const std::set<TransIdx> &rules, RuntimeResult &res) {
    for (TransIdx i: rules) {
        const Rule r = its.getRule(i);
        if (r.getCost().isNontermSymbol() && SmtFactory::check(r.getGuard(), its) == Sat) {
            res.update(r.getGuard(), Expr::NontermSymbol, Expr::NontermSymbol, Complexity::Nonterm);
            Proof proof;
            proof.result(stringstream() << "Proved reachability of sink via rule " << i << " with SMT.");
            res.concat(proof);
            break;
        }
    }
}

void Analysis::getMaxRuntimeOf(const set<TransIdx> &rules, RuntimeResult &res) {
    auto isTempVar = [&](const Var &var){ return its.isTempVar(var); };

    // Only search for runtimes that improve upon the current runtime
    vector<TransIdx> todo(rules.begin(), rules.end());

    // sort the rules before analyzing them
    // non-terminating rules first
    // non-polynomial (i.e., most likely exponential) rules second (preferring rules with temporary variables)
    // rules with temporary variables (sorted by their degree) third
    // rules without temporary variables (sorted by their degree) last
    // if rules are equal wrt. the criteria above, prefer those with less constraints in the guard
    auto comp = [this, isTempVar](const TransIdx &fst, const TransIdx &snd) {
        Rule fstRule = its.getRule(fst);
        Rule sndRule = its.getRule(snd);
        Expr fstCpxExp = fstRule.getCost().expand();
        Expr sndCpxExp = sndRule.getCost().expand();
        if (!fstCpxExp.equals(sndCpxExp)) {
            if (fstCpxExp.isNontermSymbol()) return true;
            if (sndCpxExp.isNontermSymbol()) return false;
            bool fstIsNonPoly = !fstCpxExp.isPoly();
            bool sndIsNonPoly = !sndCpxExp.isPoly();
            if (fstIsNonPoly > sndIsNonPoly) return true;
            if (fstIsNonPoly < sndIsNonPoly) return false;
            bool fstHasTmpVar = fstCpxExp.hasVarWith(isTempVar);
            bool sndHasTmpVar = sndCpxExp.hasVarWith(isTempVar);
            if (fstHasTmpVar > sndHasTmpVar) return true;
            if (fstHasTmpVar < sndHasTmpVar) return false;
            Complexity fstCpx = toComplexity(fstCpxExp);
            Complexity sndCpx = toComplexity(sndCpxExp);
            if (fstCpx > sndCpx) return true;
            if (fstCpx < sndCpx) return false;
        }
        unsigned long fstGuardSize = fstRule.getGuard()->size();
        unsigned long sndGuardSize = sndRule.getGuard()->size();
        return fstGuardSize < sndGuardSize;
    };

    sort(todo.begin(), todo.end(), comp);

    for (TransIdx ruleIdx : todo) {
        Rule rule = its.getRule(ruleIdx);
        Proof proof;

        // getComplexity() is not sound, but gives an upperbound, so we can avoid useless asymptotic checks.
        // We have to be careful with temp variables, since they can lead to unbounded cost.
        const Expr &cost = rule.getCost();
        bool hasTempVar = !cost.isNontermSymbol() && cost.hasVarWith(isTempVar);

        if (toComplexity(cost) <= max(res.getCpx(), Complexity::Const) && !hasTempVar) {
            continue;
        }

        proof.section(stringstream() << "Computing asymptotic complexity for rule " << ruleIdx);

        option<AsymptoticBound::Result> checkRes;
        bool isPoly = rule.getCost().isPoly() && !rule.getCost().isNontermSymbol() && rule.getGuard()->isPoly();
        unsigned int timeout = Timeout::soft() ? Config::Smt::LimitTimeoutFinalFast : Config::Smt::LimitTimeoutFinal;
        if (isPoly && Config::Limit::PolyStrategy->smtEnabled()) {
            checkRes = AsymptoticBound::determineComplexityViaSMT(
                        its,
                        rule.getGuard()->transform<IntTheory>(),
                        rule.getCost(),
                        true,
                        res.getCpx(),
                        timeout);
        }

        if (checkRes && checkRes->cpx > res.getCpx()) {
            proof.newline();
            proof.result(stringstream() << "Proved lower bound " << checkRes->cpx << ".");
            proof.storeSubProof(checkRes->proof);

            res.update(rule.getGuard(), rule.getCost(), checkRes->solvedCost, checkRes->cpx);
            res.concat(proof);

            if (res.getCpx() >= Complexity::Unbounded) {
                break;
            }
        }

        if ((!checkRes || checkRes->cpx == Complexity::Unknown) && Config::Limit::PolyStrategy->calculusEnabled()) {
            auto toCheck = rule.getGuard()->transform<IntTheory>()->dnf();
            if (toCheck.empty()) {
                // guard == True
                toCheck.push_back({});
            }
            for (const auto &guard: toCheck) {
                checkRes = AsymptoticBound::determineComplexity(
                            its,
                            guard,
                            rule.getCost(),
                            true,
                            res.getCpx(),
                            timeout);

                if (checkRes && checkRes->cpx > res.getCpx()) {
                    proof.newline();
                    proof.result(stringstream() << "Proved lower bound " << checkRes->cpx << ".");
                    proof.storeSubProof(checkRes->proof);

                    res.update(rule.getGuard(), rule.getCost(), checkRes->solvedCost, checkRes->cpx);
                    res.concat(proof);

                    if (res.getCpx() >= Complexity::Unbounded) {
                        break;
                    }
                }
            }
        }
    }
}


void Analysis::getBestResult(RuntimeResult &res) {
    auto rules = its.getTransitionsFrom(its.getInitialLocation());
    getBestResultOf(rules, res);
}


// ###############################
// ## Complexity After Timeout  ##
// ###############################

/**
 * Helper for removeConstantRulesAfterTimeout.
 * Returns true if there are no non-constant rules reachable from curr.
 */
static bool removeConstantPathsImpl(ITSProblem &its, LocationIdx curr, set<LocationIdx> &visited) {
    if (visited.insert(curr).second == false) return true; //already seen, remove any transitions forming a loop

    for (LocationIdx next : its.getSuccessorLocations(curr)) {
        // Check if all rules reachable from next have constant cost.
        // In this case, all constant rules leading to next are not interesting and can be removed.
        if (removeConstantPathsImpl(its, next, visited)) {
            for (TransIdx rule : its.getTransitionsFromTo(curr, next)) {
                if (toComplexity(its.getRule(rule).getCost()) <= Complexity::Const) {
                    its.removeRule(rule);
                }
            }
        }
    }

    // If all rules have been deleted, no non-constant rules are reachable and curr is not of any interest.
    return its.getTransitionsFrom(curr).empty();
}


void Analysis::removeConstantPathsAfterTimeout() {
    set<LocationIdx> visited;
    removeConstantPathsImpl(its, its.getInitialLocation(), visited);
}


void Analysis::getMaxPartialResult(RuntimeResult &res) {
    LocationIdx initial = its.getInitialLocation(); // just a shorthand

    // contract and always compute the maximum complexity to allow abortion at any time
    while (true) {


        // check runtime of all rules from the start state
        getBestResultOf(its.getTransitionsFrom(initial), res);

        // handle special cases to ensure termination in time
        if (res.getCpx() >= Complexity::Unbounded) return;

        // contract next level (if there is one), so we get new rules from the start state
        auto succs = its.getSuccessorLocations(initial);
        if (succs.empty()) break;

        for (LocationIdx succ : succs) {
            for (TransIdx first : its.getTransitionsFromTo(initial,succ)) {
                const Rule firstRule = its.getRule(first);
                std::vector<Rule> replacement;
                for (TransIdx second : its.getTransitionsFrom(succ)) {
                    auto chained = Chaining::chainRules(its, firstRule, its.getRule(second));
                    if (chained) {
                        replacement.push_back(chained.get());
                    }
                }
                its.replaceRules({first}, replacement);
            }
        }
    }
    res.headline("Performed chaining from the start location:");

}
