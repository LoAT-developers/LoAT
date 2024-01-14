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
#include "inttheory.hpp"
#include "smtfactory.hpp"
#include "chain.hpp"
#include <memory>

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
 * Note that `clauseFrom(TransIdx rule)` can only be used for rules that are stored
 * in the ITS. Not to turn an entire trace into a clause, because `ITSProblem::getLhsLoc`
 * and `ITSProblem::getRhsLoc` are only defined for rules that are actually in the ITS.
 * Thus, here is a generalized version of `clauseFrom` that accepts the lhs/rhs location
 * explicitly.
 */
const Clause ITSProblem::clauseFrom(const LocationIdx lhs_loc, const LocationIdx rhs_loc, const Rule& rule) const {
    const auto prog_vars = getProgVars();
    const auto update = rule.getUpdate();

    // First we eliminate the location variable from the guard. In the ITS context,
    // the location variable encoded the lhs predicate. But in clauses the lhs
    // predicate is carried explicitly. Thus, the location variable turns into 
    // a superfluous temporary variable in the constraint, which causes subsequent
    // calls of Clause::resolutionWith to give different results even on same 
    // arguments. For example, computing the resolvent of
    //
    //     (fact_F) i1=0 ==> F(y)
    //     (rule_F) i1=1 /\ F(x) ==> F(x)
    //
    // where `i1` is the location variable, gives:
    //
    //     F(x) /\ i1=0 /\ i2=0 ==> F(x)
    //
    // because `i1` appeared in both clauses and had to be renamed in `fact_F` to 
    // make the variables in the clauses disjoint. If we do the same computation 
    // again we get:
    //
    //     F(x) /\ i1=0 /\ i3=0 ==> F(x)
    //
    // with `i3` instead of `i2`, because new variables are created using a global
    // counter and `i2` already exists. Thus, the resolvents are not syntactially 
    // equal, which leads to otherwise trivially detectable redundancy.
    //
    // To eliminate the location variable, we substitute `i1` with it's value to 
    // make the literate trivially true, which simplifies away when we later call
    // `simplify()` on the guard, i.e. we substitute
    //
    //    (i1=0 ==> F(y))[i1/0]
    //  = ( 0=0 ==> F(y)) 
    //  = (true ==> F(y))
    //
    const auto eliminate_loc_var = Subs::build<IntTheory>(NumVar::loc_var, lhs_loc);
    const auto guard_without_loc_var = rule.getGuard()->subs(eliminate_loc_var);

    // `update` might map vars to non-var compound expressions or literals. 
    // The `Clause` representation only allows variable arguments though for the
    // RHS predicate. So we extract those expressions and put them back into the 
    // clause guard. This is a bit ad-hoc and also un-does work of the linear 
    // solver and the preprocessing, so it might be worth optimizing later. 
    std::vector<BoolExpr> guard_conj = { guard_without_loc_var };
    std::vector<Var> rhs_args;
    for (const Var &var: prog_vars) {
        auto it = update.find(var);

        if (it == update.end()) { 
            // If `var` is not contained in `update` it's implicitly mapped to itself,
            // i.e. `update` does not change the value of `var`. Thus, we add `var` 
            // directly into `rhs_args`.
            rhs_args.push_back(var);
        } else {
            const auto optional_var = expr::toVar(expr::second(*it));

            if (optional_var.has_value()) {
                rhs_args.push_back(optional_var.value());
            } else {
                const auto new_var = expr::next(var);
                rhs_args.push_back(new_var);
                guard_conj.push_back(expr::mkEq(expr::toExpr(new_var), update.get(var)));
            }
        }                   
    }

    const auto final_guard = BExpression::buildAnd(guard_conj)->simplify();
    const auto rhs_pred_name = getLocationNames().at(rhs_loc);

    const std::optional<FunApp> rhs = rhs_loc == getSink() 
        ? std::optional<FunApp>() 
        : FunApp(rhs_pred_name, rhs_args);

    if (lhs_loc == getInitialLocation()) {     
        // rule is a linear CHC with no LHS predicates, ie a "fact"
        return Clause({}, rhs, final_guard).normalize();
    } else {
        // rule is a linear CHC with exactly one LHS predicates, ie a "rule"
        const auto lhs_pred_name = getLocationNames().at(lhs_loc);
        return Clause({ FunApp(lhs_pred_name, prog_vars) }, rhs, final_guard).normalize();  
    }
}

/** 
 * Converts an ITS rule (identified by a TransIdx) back to Clause representation.
 * This does not restore the original representation after parsing perfectly,
 * since number and order of predicate arguments is lost.
 */
const Clause ITSProblem::clauseFrom(TransIdx rule) const {
    const LocationIdx lhs_loc = getLhsLoc(rule);
    const LocationIdx rhs_loc = getRhsLoc(rule);
    return clauseFrom(lhs_loc, rhs_loc, *rule);
}

/**
 * Adds a linear clause to the ITS problem by converting it to an ITS rule. 
 * Throws an error if the given clause is non-linear.
 */
void ITSProblem::addClause(const Clause &c) {    
    if (!c.isLinear()) {
        throw std::logic_error("Tried to add non-linear clause to ITS");
    }

    // If the clause is linear, extract the single LHS predicate. Or in case there are zero
    // LHS predicates, construct a dummy predicate with the initial ITS location as the 
    // predicate symbol.
    const auto initial_loc_name = getLocationNames().at(getInitialLocation());
    const FunApp lhs = c.lhs.size() == 1 ? *c.lhs.begin() : FunApp(initial_loc_name, {});

    const std::vector<Var> rhs_args = c.rhs.has_value() 
        ? c.rhs.value().args 
        : std::vector<Var>();

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
    for (const auto &var: rhs_args) {
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
    for (unsigned i = 0; i < rhs_args.size(); ++i) {
        if (std::holds_alternative<NumVar>(rhs_args[i])) {
            up.put<IntTheory>(numProgVars[int_arg], ren.get<IntTheory>(std::get<NumVar>(rhs_args[i])));
            ++int_arg;
        } else if (std::holds_alternative<BoolVar>(rhs_args[i])) {
            up.put<BoolTheory>(boolProgVars[bool_arg], ren.get<BoolTheory>(std::get<BoolVar>(rhs_args[i])));
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

    const auto lhs_loc = getLocationIdx(lhs.name);
    const auto rhs_pred_name = c.rhs.has_value() ? c.rhs.value().name : "LoAT_sink";
    const auto rhs_loc = c.rhs.has_value() ? getLocationIdx(c.rhs.value().name) : getSink();

    if (!rhs_loc.has_value()) {
        throw std::logic_error("tried to add clause with unknown RHS predicate called " + rhs_pred_name);
    }
    if (!lhs_loc.has_value()) {
        throw std::logic_error("tried to add clause with unknown LHS predicate called " + lhs.name);
    }

    up.put(NumVar::loc_var, rhs_loc.value());
    const BoolExpr guard = c.guard->subs(ren)->simplify() & Rel::buildEq(NumVar::loc_var, lhs_loc.value());
    addRule(Rule(guard, up), lhs_loc.value());
}

/**
 * Construct an ITS instance from a set of clauses. Non-linear clauses are ignored in the sense that 
 * they don't contribute ITS rules. However, predicates that only occur in non-linear rules are added
 * as locations, because if we later add new rules to the ITS via `addClause` that are derived from 
 * non-linear clauses, we expect all locations to already be known.
 */
ITSPtr ITSProblem::fromClauses(const std::set<Clause>& chcs) {
    std::vector<Clause> chc_vec(chcs.begin(), chcs.end());
    return fromClauses(chc_vec);
}
ITSPtr ITSProblem::fromClauses(const std::vector<Clause>& chc_problem) {
    ITSPtr its = std::make_shared<ITSProblem>();

    auto [max_int_arity, max_bool_arity] = maxArity(chc_problem);

    its->setInitialLocation(its->addNamedLocation("LoAT_init"));
    // Collect all predicate that appear in `chc_problem`, add them as 
    // locations to the ITS :
    std::map<std::string, LocationIdx> locations;
    for (const auto &chc: chc_problem) {
        if (chc.rhs.has_value()) {
            const auto& rhs = chc.rhs.value();

            bool location_already_added = its->getLocationIdx(rhs.name).has_value();
            if (!location_already_added) {
                locations[rhs.name] = its->addNamedLocation(rhs.name);
            }
        }

        for (const auto &pred: chc.lhs) {
            bool location_already_added = its->getLocationIdx(pred.name).has_value();
            if (!location_already_added) {
                locations[pred.name] = its->addNamedLocation(pred.name);
            }
        }
    }

    // Construct "normalized" vectors of bool/int program variables, 
    // because in ITS rules must all have the same argument vector.
    std::vector<NumVar> int_vars;
    for (unsigned i = 0; i < max_int_arity; ++i) {
        int_vars.emplace_back(NumVar::nextProgVar());
    }
    its->numProgVars = int_vars;

    std::vector<BoolVar> bool_vars;
    for (unsigned i = 0; i < max_bool_arity; ++i) {
        bool_vars.emplace_back(BoolVar::nextProgVar());
    }
    its->boolProgVars = bool_vars;

    for (const auto &chc: chc_problem) {
        if (chc.isLinear()) {
            its->addClause(chc);
        }
    }

    return its;
}
