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

#include "itsproblem.hpp"
#include "export.hpp"
#include <eigen3/Eigen/Dense>
#include "../util/relevantvariables.hpp"
#include "../accelerate/recurrence/dependencyorder.hpp"

using namespace std;

std::recursive_mutex ITSProblem::mutex;

ITSProblem::ITSProblem(VariableManager &&varMan) : VariableManager(varMan) {}

bool ITSProblem::isEmpty() const {
    std::lock_guard guard(mutex);
    return rules.empty();
}

bool ITSProblem::isLinear() const {
    std::lock_guard guard(mutex);
    for (const auto &it : rules) {
        if (!it.second.isLinear()) {
            return false;
        }
    }
    return true;
}

LocationIdx ITSProblem::getInitialLocation() const {
    std::lock_guard guard(mutex);
    return initialLocation;
}

bool ITSProblem::isInitialLocation(LocationIdx loc) const {
    std::lock_guard guard(mutex);
    return loc == initialLocation;
}

void ITSProblem::setInitialLocation(LocationIdx loc) {
    std::lock_guard guard(mutex);
    initialLocation = loc;
}

bool ITSProblem::hasRule(TransIdx transition) const {
    std::lock_guard guard(mutex);
    return rules.find(transition) != rules.end();
}

const Rule ITSProblem::getRule(TransIdx transition) const {
    std::lock_guard guard(mutex);
    assert(rules.count(transition) > 0);
    return rules.at(transition);
}

void ITSProblem::lock() {
    mutex.lock();
}

void ITSProblem::unlock() {
    mutex.unlock();
}

LinearRule ITSProblem::getLinearRule(TransIdx transition) const {
    std::lock_guard guard(mutex);
    return rules.at(transition).toLinear();
}

const std::set<LocationIdx> ITSProblem::getTransitionTargets(TransIdx idx) const {
    std::lock_guard guard(mutex);
    return graph.getTransTargets(idx);
}

std::set<TransIdx> ITSProblem::getTransitionsFrom(LocationIdx loc) const {
    std::lock_guard guard(mutex);
    return graph.getTransFrom(loc);
}

std::vector<TransIdx> ITSProblem::getTransitionsFromTo(LocationIdx from, LocationIdx to) const {
    std::lock_guard guard(mutex);
    return graph.getTransFromTo(from, to);
}

std::set<TransIdx> ITSProblem::getTransitionsTo(LocationIdx loc) const {
    std::lock_guard guard(mutex);
    return graph.getTransTo(loc);
}

std::vector<TransIdx> ITSProblem::getAllTransitions() const {
    std::lock_guard guard(mutex);
    return graph.getAllTrans();
}

bool ITSProblem::hasTransitionsFrom(LocationIdx loc) const {
    std::lock_guard guard(mutex);
    return graph.hasTransFrom(loc);
}

bool ITSProblem::hasTransitionsFromTo(LocationIdx from, LocationIdx to) const {
    std::lock_guard guard(mutex);
    return graph.hasTransFromTo(from, to);
}

bool ITSProblem::hasTransitionsTo(LocationIdx loc) const {
    std::lock_guard guard(mutex);
    return graph.hasTransTo(loc);
}

std::vector<TransIdx> ITSProblem::getSimpleLoopsAt(LocationIdx loc) const {
    std::lock_guard guard(mutex);
    vector<TransIdx> res;
    for (TransIdx rule : getTransitionsFromTo(loc, loc)) {
        if (getRule(rule).isSimpleLoop()) {
            res.push_back(rule);
        }
    }
    return res;
}

std::set<LocationIdx> ITSProblem::getSuccessorLocations(LocationIdx loc) const {
    std::lock_guard guard(mutex);
    return graph.getSuccessors(loc);
}

std::set<LocationIdx> ITSProblem::getPredecessorLocations(LocationIdx loc) const {
    std::lock_guard guard(mutex);
    return graph.getPredecessors(loc);
}

void ITSProblem::removeRule(TransIdx transition) {
    std::lock_guard guard(mutex);
    graph.removeTrans(transition);
    auto it = rules.find(transition);
    if (it != rules.end()) {
        rulesBwd.erase(it->second);
    }
    rules.erase(transition);
}

option<TransIdx> ITSProblem::addRule(Rule rule) {
    std::lock_guard guard(mutex);
    auto it = rulesBwd.find(rule);
    if (it != rulesBwd.end()) {
        return {};
    }
    // gather target locations
    set<LocationIdx> rhsLocs;
    for (auto it = rule.rhsBegin(); it != rule.rhsEnd(); ++it) {
        rhsLocs.insert(it->getLoc());
    }

    // add transition and store mapping to rule
    TransIdx idx = graph.addTrans(rule.getLhsLoc(), rhsLocs);
    rules.emplace(idx, rule);
    rulesBwd.emplace(rule, idx);
    return idx;
}

std::vector<TransIdx> ITSProblem::replaceRules(const std::vector<TransIdx> &toReplace, const std::vector<Rule> replacement) {
    std::vector<TransIdx> keep;
    std::vector<TransIdx> result;
    for (const Rule& r: replacement) {
        option<TransIdx> added = addRule(r);
        if (added) {
            result.push_back(added.get());
        } else {
            keep.push_back(rulesBwd.find(r)->second);
        }
    }
    for (TransIdx idx: toReplace) {
        if (std::find(keep.begin(), keep.end(), idx) == keep.end()) {
            removeRule(idx);
        }
    }
    return result;
}

LocationIdx ITSProblem::addLocation() {
    std::lock_guard guard(mutex);
    LocationIdx loc = nextUnusedLocation++;
    locations.insert(loc);
    return loc;
}

LocationIdx ITSProblem::addNamedLocation(std::string name) {
    std::lock_guard guard(mutex);
    LocationIdx loc = addLocation();
    locationNames.emplace(loc, name);
    return loc;
}

set<LocationIdx> ITSProblem::getLocations() const {
    std::lock_guard guard(mutex);
    return locations;
}

option<string> ITSProblem::getLocationName(LocationIdx idx) const {
    std::lock_guard guard(mutex);
    auto it = locationNames.find(idx);
    if (it != locationNames.end()) {
        return it->second;
    }
    return {};
}

string ITSProblem::getPrintableLocationName(LocationIdx idx) const {
    std::lock_guard guard(mutex);
    auto it = locationNames.find(idx);
    if (it != locationNames.end()) {
        return it->second;
    }
    return "[" + to_string(idx) + "]";
}


void ITSProblem::removeOnlyLocation(LocationIdx loc) {
    std::lock_guard guard(mutex);
    // The initial location must not be removed
    assert(loc != initialLocation);

    locations.erase(loc);
    locationNames.erase(loc);
    set<TransIdx> removed = graph.removeNode(loc);

    // Check that all rules from/to loc were removed before
    assert(removed.empty());
}

std::set<TransIdx> ITSProblem::removeLocationAndRules(LocationIdx loc) {
    std::lock_guard guard(mutex);
    // The initial location must not be removed
    assert(loc != initialLocation);

    locations.erase(loc);
    locationNames.erase(loc);
    set<TransIdx> removed = graph.removeNode(loc);

    // Also remove all rules from/to loc
    for (TransIdx t : removed) {
        removeRule(t);
    }
    return removed;
}

void ITSProblem::print(std::ostream &s) const {
    std::lock_guard guard(mutex);
    ITSExport::printDebug(*this, s);
}

void ITSProblem::categorize_loops() const {
    cout.precision(20);
    for (auto idx: getAllTransitions()) {
        auto t = getRule(idx);
        if (t.isSimpleLoop()) {
//            std::cout << t << std::endl;
            auto guard = t.getGuard();
            auto up = t.getUpdate(0);
            if (!guard->isLinear()) {
                printf("non-linear\n");
                goto NEXT;
            }
            Subs all_zero;
            auto vars = util::RelevantVariables::find(guard->vars(), t.getUpdates(), guard);
            for (auto x: vars) {
                if (up.contains(x) && !up.get(x).isLinear()) {
                    printf("non-linear\n");
                    goto NEXT;
                }
                all_zero.put(x, 0);
            }
            auto has_cst = false;
            for (auto x: vars) {
                if (up.contains(x) && !up.get(x).subs(all_zero).isZero()) {
                    has_cst = true;
                    break;
                }
            }
            for (auto x: vars) {
                if (isTempVar(x)) {
                    printf("non-deterministic\n");
                    goto NEXT;
                }
            }
            auto order = DependencyOrder::findOrder(up);
            if (!order) {
                printf("non-triangular\n");
                goto NEXT;
            }
            std::vector<Var> var_vec;
            for (auto x: order.get()) {
                if (vars.find(x) != vars.end()) {
                    var_vec.push_back(x);
                }
            }
            for (auto x: vars) {
                if (!up.contains(x)) {
                    var_vec.push_back(x);
                }
            }
            auto n = var_vec.size() + has_cst;
            if (n == 0) {
                printf("empty\n");
                goto NEXT;
            }
            Eigen::MatrixXd A(n, n);
            Eigen::MatrixXd I = Eigen::MatrixXd::Identity(n, n);
            for (unsigned int i = 0; i < var_vec.size(); ++i) {
                auto x = var_vec[i];
                if (up.contains(x)) {
                    auto rhs = up.get(x);
                    for (unsigned int j = 0; j < var_vec.size(); ++j) {
                        auto coeff = rhs.coeff(var_vec[j]).toNum().to_double();
                        A(i + has_cst, j + has_cst) = coeff;
                    }
                } else {
                    for (unsigned int j = 0; j < var_vec.size(); ++j) {
                        A(i + has_cst, j + has_cst) = 0.0;
                    }
                    A(i + has_cst, i + has_cst) = 1.0;
                }
            }
            if (has_cst) {
                for (unsigned int i = 0; i < var_vec.size(); ++i) {
                    auto x = var_vec[i];
                    if (up.contains(x)) {
                        auto cst = up.get(x).subs(all_zero).toNum().to_double();
                        A(i + 1, 0) = cst;
                    } else {
                        A(i + 1, 0) = 0.0;
                    }
                }
                for (unsigned int i = 0; i < var_vec.size(); ++i) {
                    A(0, i + 1) = 0.0;
                }
                A(0, 0) = 1.0;
            }
            Eigen::EigenSolver<Eigen::MatrixXd> es(A, false);
            if (es.info() == Eigen::Success) {
                for (unsigned int i = 0; i < n; ++i) {
                    auto ev = A(i,i);
                    if (ev == 0.0) continue;
                    auto rank = (A - (ev * I)).jacobiSvd().rank();
                    if (n - rank != 1) {
                        printf("fail\n");
                        goto NEXT;
                    }
                }
                if (order) {
                    for (unsigned int i = 0; i < n; ++i) {
                        auto ev = A(i,i);
                        if (ev < 0.0) {
                            printf("negative\n");
                            goto NEXT;
                        }
                    }
                    printf("uniform\n");
                }
            } else {
                printf("numerical issues");
            }
        }
        NEXT: continue;
    }
}
