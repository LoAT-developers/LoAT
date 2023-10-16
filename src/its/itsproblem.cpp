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
#include "expr.hpp"
#include "smtfactory.hpp"
#include "chain.hpp"

using namespace std;

bool ITSProblem::isEmpty() const {
    return rules.empty();
}

LocationIdx ITSProblem::getInitialLocation() const {
    return initialLocation;
}

bool ITSProblem::isInitialLocation(LocationIdx loc) const {
    return loc == initialLocation;
}

void ITSProblem::setInitialLocation(LocationIdx loc) {
    initialLocation = loc;
}

LocationIdx ITSProblem::getSink() const {
    return sink;
}

const std::set<Rule>& ITSProblem::getAllTransitions() const {
    return rules;
}

std::set<TransIdx> ITSProblem::getSuccessors(const TransIdx loc) const {
    std::set<TransIdx> res;
    for (const auto &idx: graph.getSuccessors(loc)) {
        res.insert(idx);
    }
    return res;
}

std::set<TransIdx> ITSProblem::getPredecessors(const TransIdx loc) const {
    std::set<TransIdx> res;
    for (const auto &idx: graph.getPredecessors(loc)) {
        res.insert(idx);
    }
    return res;
}

bool ITSProblem::areAdjacent(const TransIdx first, const TransIdx second) const {
    return graph.hasEdge(first, second);
}

void ITSProblem::removeRule(TransIdx transition) {
    graph.removeNode(transition);
    startAndTargetLocations.erase(transition);
    initialTransitions.erase(transition);
    sinkTransitions.erase(transition);
    rules.erase(*transition);
}

TransIdx ITSProblem::addRule(const Rule &rule, const LocationIdx start, const LocationIdx target, const std::set<TransIdx> &preds, const std::set<TransIdx> &succs) {
    const auto idx {&*rules.emplace(rule).first};
    startAndTargetLocations.emplace(idx, std::pair<LocationIdx, LocationIdx>(start, target));
    graph.addNode(idx, preds, succs, start == target);
    if (start == initialLocation) {
        initialTransitions.insert(idx);
    }
    if (target == sink) {
        sinkTransitions.insert(idx);
    }
    return idx;
}

TransIdx ITSProblem::addRule(const Rule &rule, const TransIdx same_preds, const TransIdx same_succs) {
    const auto start = getLhsLoc(same_preds);
    const auto target = getRhsLoc(same_succs);
    const auto preds = graph.getPredecessors(same_preds);
    const auto succs = graph.getSuccessors(same_succs);
    return addRule(rule, start, target, preds, succs);
}

TransIdx ITSProblem::addLearnedRule(const Rule &rule, const TransIdx same_preds, const TransIdx same_succs) {
    const auto res = addRule(rule, same_preds, same_succs);
    graph.removeEdge(res, res);
    return res;
}

TransIdx ITSProblem::addQuery(const BoolExpr &guard, const TransIdx same_preds) {
    const auto start = getLhsLoc(same_preds);
    const auto preds = graph.getPredecessors(same_preds);
    return addRule(Rule(guard, Subs::build<IntTheory>(NumVar::loc_var, sink)), start, sink, preds, {});
}

TransIdx ITSProblem::addRule(const Rule &rule, const LocationIdx start) {
    const auto target_opt = getRhsLoc(rule);
    const auto target = target_opt ? *target_opt : start;
    std::set<TransIdx> preds, succs;
    for (const auto &e: startAndTargetLocations) {
        if (e.second.first == target) {
            succs.insert(e.first);
        }
        if (e.second.second == start) {
            preds.insert(e.first);
        }
    }
    return addRule(rule, start, target, preds, succs);
}

TransIdx ITSProblem::replaceRule(const TransIdx toReplace, const Rule &replacement) {
    const auto idx {&*rules.emplace(replacement).first};
    startAndTargetLocations.emplace(idx, startAndTargetLocations.at(toReplace));
    startAndTargetLocations.erase(toReplace);
    graph.replaceNode(toReplace, idx);
    if (isInitialTransition(toReplace)) {
        initialTransitions.insert(idx);
        initialTransitions.erase(toReplace);
    }
    if (isSinkTransition(toReplace)) {
        sinkTransitions.insert(idx);
        sinkTransitions.erase(toReplace);
    }
    rules.erase(*toReplace);
    return idx;
}

void ITSProblem::removeEdge(const TransIdx from, const TransIdx to) {
    graph.removeEdge(from, to);
}

LocationIdx ITSProblem::addLocation() {
    LocationIdx loc = nextUnusedLocation++;
    locations.insert(loc);
    return loc;
}

LocationIdx ITSProblem::addNamedLocation(std::string name) {
    LocationIdx loc = addLocation();
    locationNames.emplace(loc, name);
    return loc;
}

set<LocationIdx> ITSProblem::getLocations() const {
    return locations;
}

const std::map<LocationIdx, std::string>& ITSProblem::getLocationNames() const {
    return locationNames;
}

std::optional<LocationIdx> ITSProblem::getLocationIdx(const std::string &name) const {
    for (const auto &p: locationNames) {
        if (p.second == name) {
            return p.first;
        }
    }
    return {};
}

string ITSProblem::getPrintableLocationName(LocationIdx idx) const {
    auto it = locationNames.find(idx);
    if (it != locationNames.end()) {
        return it->second;
    }
    return (stringstream() << "[" << idx << "]").str();
}

VarSet ITSProblem::getVars() const {
    VarSet res;
    for (const auto &r: rules) {
        r.collectVars(res);
    }
    return res;
}

void ITSProblem::print(std::ostream &s) const {
    ITSExport::printForProof(*this, s);
}

Expr ITSProblem::getCost(const Rule &rule) const {
    const auto up {rule.getUpdate().get<IntTheory>()};
    const auto it {up.find(cost)};
    if (it == up.end()) {
        return 0;
    } else {
        return it->second - cost;
    }
}

NumVar ITSProblem::getCostVar() const {
    return cost;
}

std::optional<LocationIdx> ITSProblem::getRhsLoc(const Rule &rule) const {
    const auto up = rule.getUpdate().get<IntTheory>();
    const auto it = up.find(NumVar::loc_var);
    if (it == up.end()) {
        return {};
    } else {
        return it->second.toNum().to_int();
    }
}

LocationIdx ITSProblem::getLhsLoc(const TransIdx idx) const {
    return startAndTargetLocations.at(idx).first;
}

LocationIdx ITSProblem::getRhsLoc(const TransIdx idx) const {
    return startAndTargetLocations.at(idx).second;
}

const std::set<TransIdx>& ITSProblem::getInitialTransitions() const {
    return initialTransitions;
}

const std::set<TransIdx>& ITSProblem::getSinkTransitions() const {
    return sinkTransitions;
}

bool ITSProblem::isSimpleLoop(const TransIdx idx) const {
    return graph.hasEdge(idx, idx);
}

bool ITSProblem::isSinkTransition(const TransIdx idx) const {
    return sinkTransitions.find(idx) != sinkTransitions.end();
}

bool ITSProblem::isInitialTransition(const TransIdx idx) const {
    return initialTransitions.find(idx) != initialTransitions.end();
}

const ITSProblem::DG& ITSProblem::getDependencyGraph() const {
    return graph;
}

std::set<ITSProblem::DG::Edge> ITSProblem::refineDependencyGraph() {
    const auto is_edge = [](const TransIdx fst, const TransIdx snd){
        return SmtFactory::check(Chaining::chain(*fst, *snd).first.getGuard()) == Sat;
    };
    return graph.refine(is_edge);
}

size_t ITSProblem::size() const {
    return graph.size();
}

const std::vector<Var> ITSProblem::getProgVars() const {
    std::vector<Var> prog_vars;
    prog_vars.reserve(numProgVars.size() + boolProgVars.size());
    for (const auto &var: numProgVars) {
        prog_vars.push_back(var);
    }
    for (const auto &var: boolProgVars) {
        prog_vars.push_back(var);
    }
    return prog_vars;
}

/** 
 * Converts an ITS rule (identified by a TransIdx) back to CHC representation.
 * This does not restore the original representation after parsing perfectly,
 * since number and order of predicate arguments is lost.
 */
const Clause ITSProblem::clauseFrom(TransIdx rule) const {
    const auto prog_vars = getProgVars();

    const auto guard = rule->getGuard();

    const LocationIdx lhs_loc = getLhsLoc(rule);
    const LocationIdx rhs_loc = getRhsLoc(rule);

    const auto rhs = FunApp(rhs_loc, prog_vars).renameWith(rule->getUpdate());

    if (lhs_loc == getInitialLocation()) {     
        // rule is a linear CHC with no LHS predicates, ie a "fact"
        return Clause({}, rhs, guard);
    } else {
        // rule is a linear CHC with exactly one LHS predicates, ie a "rule"
        return Clause({ FunApp(lhs_loc, prog_vars) }, rhs, guard);  
    }
}

/**
 * TODO docs
 */
const FunApp normalizePredicate(unsigned int_var_count, unsigned bool_var_count, const FunApp &pred) {   
    std::vector<Var> int_args;
    int_args.reserve(int_var_count);
    std::vector<Var> bool_args;
    bool_args.reserve(bool_var_count);

    for (const Var &arg: pred.args) {
        if (std::holds_alternative<NumVar>(arg)) {
            int_args.push_back(arg);
        } else {
            bool_args.push_back(arg);
        }
    }

    while (int_args.size() < int_var_count) {
        int_args.push_back(NumVar::next());
    }

    while (bool_args.size() < bool_var_count) {
        bool_args.push_back(BoolVar::next());
    }

    int_args.insert(int_args.end(), bool_args.begin(), bool_args.end());
    return FunApp(pred.loc, int_args);
}

/**
 * Adds a clause to the ITS problem. If the clause is linear, it's converted to an ITS rule.
 * If the clause is non-linear it's separately stored in `nonLinearCHCs`.
 */
void ITSProblem::addClause(const Clause &c) {    
    if (c.isLinear()) {       
        // If the clause is linear, extract the single LHS predicate. Or in case there are zero
        // LHS predicates, construct a dummy predicate with the initial ITS location as the 
        // predicate symbol.
        const FunApp lhs = c.lhs.size() == 1 ? *c.lhs.begin() : FunApp(getInitialLocation(), {});
    
        Subs ren;
        // replace the arguments of the body predicate with the corresponding program variables
        unsigned bool_arg {0};
        unsigned int_arg {0};
        for (unsigned i = 0; i < lhs.args.size(); ++i) {
            if (std::holds_alternative<NumVar>(lhs.args[i])) {
                ren.put<IntTheory>(
                    std::get<NumVar>(lhs.args[i]), 
                    numProgVars[int_arg]
                );
                ++int_arg;
            } else {
                ren.put<BoolTheory>(
                    std::get<BoolVar>(lhs.args[i]), 
                    std::get<BoolExpr>(expr::toExpr(boolProgVars[bool_arg]))
                );
                ++bool_arg;
            }
        }
        VarSet cVars;
        for (const auto &var: c.rhs.args) {
            cVars.insert(var);
        }
        c.guard->collectVars(cVars);
        // replace all other variables from the clause with temporary variables
        for (const auto &x: cVars) {
            if (!ren.contains(x)) {
                ren.put(x, expr::toExpr(expr::next(x)));
            }
        }
        bool_arg = 0;
        int_arg = 0;
        Subs up;
        for (unsigned i = 0; i < c.rhs.args.size(); ++i) {
            if (std::holds_alternative<NumVar>(c.rhs.args[i])) {
                up.put<IntTheory>(numProgVars[int_arg], ren.get<IntTheory>(std::get<NumVar>(c.rhs.args[i])));
                ++int_arg;
            } else if (std::holds_alternative<BoolVar>(c.rhs.args[i])) {
                up.put<BoolTheory>(boolProgVars[bool_arg], ren.get<BoolTheory>(std::get<BoolVar>(c.rhs.args[i])));
                ++bool_arg;
            } else {
                throw std::logic_error("unsupported theory in CHCParseVisitor");
            }
        }
        for (unsigned i = int_arg; i < numProgVars.size(); ++i) {
            up.put<IntTheory>(numProgVars[i], NumVar::next());
        }
        for (unsigned i = bool_arg; i < boolProgVars.size(); ++i) {
            up.put<BoolTheory>(boolProgVars[i], std::get<BoolExpr>(expr::toExpr(BoolVar::next())));
        }
        up.put(NumVar::loc_var, c.rhs.loc);
        const BoolExpr guard = c.guard->subs(ren)->simplify() & Rel::buildEq(NumVar::loc_var, lhs.loc);
        addRule(Rule(guard, up), lhs.loc);
    } else {
        std::set<FunApp> lhs_normalized;

        for (const FunApp &pred: c.lhs) {
            const auto pred_normalized = normalizePredicate(numProgVars.size(), boolProgVars.size(), pred);
            lhs_normalized.insert(pred_normalized);
        }            
    
        nonLinearCHCs.push_back(Clause(
            lhs_normalized, 
            normalizePredicate(numProgVars.size(), boolProgVars.size(), c.rhs),
            c.guard->simplify()
        ));       
    } 
}
