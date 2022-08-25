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

#include "recurrence.hpp"
#include "dependencyorder.hpp"

#include <purrs.hh>

using namespace std;
namespace Purrs = Parma_Recurrence_Relation_Solver;



Recurrence::Recurrence(VarMan &varMan, const std::vector<Var> &dependencyOrder)
    : varMan(varMan),
      ginacN(GiNaC::ex_to<GiNaC::symbol>(Purrs::Expr(Purrs::Recurrence::n).toGiNaC())),
      dependencyOrder(dependencyOrder)
{}

option<std::pair<Subs, option<std::string>>> Recurrence::buildSubs(const NondetUpdate &update, const VarSet &vars, const Expr &e, std::function<option<Expr>(const Var&)> inc, std::function<option<Expr>(const Var&)> dec) const {
    Subs subs;
    option<std::string> inexact;
    for (const Var &x: vars) {
//        std::cout << "checking if " << x << " is deterministic" << std::endl;
        if (!varMan.isTempVar(x)) {
            if (update.isDeterministic(x)) {
                subs.put(x, *inc(x));
            } else {
                inexact = "nondet";
                using namespace Monotonicity;
                const T monotonicity = e.monotonicity(x);
                //            std::cout << "monotonicity of " << e << " wrt " << x << ": " << monotonicity << std::endl;
                switch (monotonicity) {
                case Unknown: return option<std::pair<Subs, option<std::string>>>();
                case Constant: continue;
                case Increasing: {
                    const option<Expr> up = inc(x);
                    if (!up) return option<std::pair<Subs, option<std::string>>>();
                    subs.put(x, *up);
                    break;
                }
                case Decreasing: {
                    const option<Expr> up = dec(x);
                    if (!up) return option<std::pair<Subs, option<std::string>>>();
                    subs.put(x, *up);
                    break;
                }
                }
            }
        }
    }
    return {{subs, inexact}};
}

option<Expr> solve(const Purrs::Expr &rhs, const Purrs::Expr &init) {
    Purrs::Recurrence rec(rhs);
    Purrs::Expr exact;
    Purrs::Recurrence::Solver_Status res = Purrs::Recurrence::Solver_Status::TOO_COMPLEX;
    try {
        rec.set_initial_conditions({ {0, init} });
        res = rec.compute_exact_solution();
    } catch (...) {
        //purrs throws a runtime exception if the recurrence is too difficult
    }
    if (res == Purrs::Recurrence::SUCCESS) {
        rec.exact_solution(exact);
        return option<Expr>(exact.toGiNaC());
    } else {
        return option<Expr>{};
    }
}

std::pair<int, option<std::string>> Recurrence::findUpdateRecurrence(const NondetUpdate &update, Var updateLhs, const VarMap<unsigned int> &validitybounds) {
//    std::cout << "processing " << updateLhs << std::endl;
    unsigned validitybound = 0;
    Expr last = Purrs::x(Purrs::Recurrence::n - 1).toGiNaC();
    const auto do_solve = [&](const Expr &e, std::function<option<Expr>(const Var&)> inc, std::function<option<Expr>(const Var&)> dec) {
        VarSet vars = e.vars();
        bool rec = vars.erase(updateLhs) > 0;
        const auto p = buildSubs(update, vars, e, inc, dec);
        if (!p) return option<std::pair<Expr, option<std::string>>>();
        if (rec) {
            const Purrs::Expr rhs = Purrs::Expr::fromGiNaC(e.subs(p->first).subs(Subs(updateLhs, last)).ex);
            const Purrs::Expr init = Purrs::Expr::fromGiNaC(updateLhs);
            auto res = solve(rhs, init);
            return res.map([&](const auto &r){return std::pair<Expr, option<std::string>>(r, p->second);});
        } else {
            unsigned vb = 1;
            for (const Var &x: vars) {
                if (validitybounds.find(x) != validitybounds.end() && validitybounds.at(x) + 1 > vb) {
                    vb = validitybounds.at(x) + 1;
                }
            }
            validitybound = std::max(validitybound, vb);
            return option<std::pair<Expr, option<std::string>>>({e.subs(p->first), p->second});
        }
    };
    const auto getUpper = [&](const Var &x) {
//        std::cout << "looking up " << x << std::endl;
        return updatePreRecurrences.getUpper(x);
    };
    const auto getLower = [&](const Var &x) {
//        std::cout << "looking up " << x << std::endl;
        return updatePreRecurrences.getLower(x);
    };
    const option<Expr> lower = update.getLower(updateLhs);
    option<std::pair<Expr, option<std::string>>> lowerRes, upperRes;
    if (lower) {
        lowerRes = do_solve(*lower, getUpper, getLower);
//        std::cout << "lowerRes: " << lowerRes << std::endl;
        if (!lowerRes) return {-1, {}};
    }
    if (update.isDeterministic(updateLhs)) {
        const VarSet vars = lower->vars();
        bool allDeterministic = std::all_of(vars.begin(), vars.end(), [&](const Var &x){return update.isDeterministic(x);});
        if (allDeterministic) {
            updatePreRecurrences.put(updateLhs, lowerRes->first.subs(Subs(ginacN, ginacN - 1)));
            res.put(updateLhs, lowerRes->first);
            return {validitybound, {}};
        }
    }
    const option<Expr> upper = update.getUpper(updateLhs);
    if (upper) {
        upperRes = do_solve(*upper, getLower, getUpper);
        if (!upperRes) return {-1, {}};
    }
    option<Expr> lr = lowerRes.map([&](const auto &p){return p.first;});
    option<Expr> ur = upperRes.map([&](const auto &p){return p.first;});
    res.put(updateLhs, lr, ur);
    lr = lr.map([&](const auto &e){return e.subs(Subs(ginacN, ginacN - 1));});
    ur = ur.map([&](const auto &e){return e.subs(Subs(ginacN, ginacN - 1));});
    updatePreRecurrences.put(updateLhs, lr, ur);
    auto inexact = lowerRes.flat_map([&](const auto &p){return p.second;});
    if (!inexact) {
        inexact = upperRes.flat_map([&](const auto &p){return p.second;});
    }
    return {validitybound, inexact};
}

option<Expr> Recurrence::iterateCost(const Expr &c) {
    const auto getUpper = [&](const Var &x){
        return updatePreRecurrences.getUpper(x);
    };
    const auto getLower = [&](const Var &x){
        return updatePreRecurrences.getLower(x);
    };
    option<Subs> subs = buildSubs(updatePreRecurrences, c.vars(), c, getLower, getUpper).map([&](const auto &p){return p.first;});
    if (!subs) return {};
    Expr cost = c.subs(*subs); //replace variables by their recurrence equations
    //Example: if cost = y, the result is x(n) = x(n-1) + y(n-1), with x(0) = 0
    Purrs::Expr rhs = Purrs::x(Purrs::Recurrence::n - 1) + Purrs::Expr::fromGiNaC(cost.ex);
    Purrs::Expr init = 0;
    return solve(rhs, init);
}

option<Recurrence::RecurrenceSystemSolution> Recurrence::iterateUpdate(const NondetUpdate &update) {
    assert(dependencyOrder.size() == update.size());

    //in the given order try to solve the recurrence for every updated variable
    unsigned int validityBound = 0;
    VarMap<unsigned int> validityBounds;
    option<std::string> inexact;
    for (Var target : dependencyOrder) {
        const auto p = findUpdateRecurrence(update, target, validityBounds);
        if (p.first < 0) {
            return {};
        }
        validityBounds[target] = p.first;
        validityBound = max(validityBound, (unsigned) p.first);
        if (p.second) inexact = p.second;
    }

    return {{res, validityBound, inexact}};
}

option<Recurrence::Result<NondetUpdate>> Recurrence::iterate(const NondetUpdate &update, const Expr &cost) {
    auto newUpdate = iterateUpdate(update);
    if (!newUpdate) {
        return {};
    }

    auto newCost = iterateCost(cost);
    if (!newCost) {
        return {};
    }

    Recurrence::Result<NondetUpdate> res;
    res.n = varMan.addFreshTemporaryVariable("n");
    Subs subs = {ginacN, res.n};
    res.cost = newCost->subs(subs);
    res.update = newUpdate->update;
    res.update.compose(subs);
    res.validityBound = newUpdate->validityBound;
    res.inexact = newUpdate->inexact;
    return {res};
}

option<Recurrence::Result<NondetUpdate>> Recurrence::iterateRuleDeterministically(VarMan &varMan, const LinearRule &rule) {
    NondetUpdate up;
    for (const auto &e: rule.getUpdate()) {
        up.put(e.first, e.second);
    }
    const auto order = DependencyOrder::findOrder(up);
    return order.flat_map([&](const auto &o){
        return Recurrence(varMan, o).iterate(up, rule.getCost());
    });
}

option<Recurrence::Result<NondetUpdate>> Recurrence::iterateRule(VarMan &varMan, const LinearRule &rule) {
    NondetUpdate up;
    const auto containsTmpVar = [&varMan](const Expr &e) {
        for (const auto &x: e.vars()) {
            if (varMan.isTempVar(x)) {
                return true;
            }
        }
        return false;
    };
    Subs refinement;
    VarSet uniqueTmpVars, seenTmpVars;
    for (const auto &p: rule.getUpdate()) {
        for (const auto &x: p.second.vars()) {
            if (varMan.isTempVar(x)) {
                if (seenTmpVars.find(x) == seenTmpVars.end()) {
                    uniqueTmpVars.insert(x);
                } else {
                    uniqueTmpVars.erase(x);
                }
                seenTmpVars.insert(x);
            }
        }
    }
    option<std::string> inexact;
    for (const auto &p: rule.getUpdate()) {
        Subs lowerSubs, upperSubs;
        bool inf = false, minf = false, deterministic = true;
        for (const auto &x: p.second.vars()) {
            if (uniqueTmpVars.find(x) != uniqueTmpVars.end()) {
                const Boundedness::Kind boundedness = rule.getGuard()->getBoundedness(x);
                if (boundedness == Boundedness::None) {
                    continue;
                }
                if (boundedness == Boundedness::Unknown) {
//                    std::cout << "bad boundedness" << std::endl;
                    inexact = "boundedness";
                    continue;
                }
                const Monotonicity::T monotonicity = p.second.monotonicity(x);
//                std::cout << "eliminating " << x << " from " << p.second << ", monotonicity: " << monotonicity << ", guard: " << rule.getGuard() << std::endl;
                if (monotonicity == Monotonicity::Unknown || monotonicity == Monotonicity::Constant) {
//                    std::cout << "bad monotonicity" << std::endl;
                    inexact = "monotonicity";
                    continue;
                }
                Bounds bounds;
                rule.getGuard()->getBounds(x, bounds);
                if (!bounds.exhaustive) {
//                    std::cout << "bounds not exhaustive" << std::endl;
                    inexact = "exhaustiveness";
                    continue;
                }
                if (bounds.lowerBounds.size() > 1 || bounds.upperBounds.size() > 1) {
//                    std::cout << "too many bounds" << std::endl;
                    inexact = "uniqueness (" + x.get_name() + ")";
                    continue;
                }
                if (std::any_of(bounds.lowerBounds.begin(), bounds.lowerBounds.end(), containsTmpVar) || std::any_of(bounds.upperBounds.begin(), bounds.upperBounds.end(), containsTmpVar)) {
//                    std::cout << "dependent tmp var" << std::endl;
                    inexact = "dependent tmp var";
                    continue;
                }
                if (bounds.lowerBounds.empty()) {
//                    std::cout << "no lower bound" << std::endl;
                    if (monotonicity == Monotonicity::Increasing) {
                        if (inf) {
                            inexact = "unboundedness";
                            continue;
                        }
                        minf = true;
                    } else {
                        if (minf) {
                            inexact = "unboundedness";
                            continue;
                        }
                        inf = true;
                    }
                }
                if (bounds.upperBounds.empty()) {
//                    std::cout << "no upper bound, boundedness: " << boundedness << ", guard: " << rule.getGuard() << std::endl;
                    if (monotonicity == Monotonicity::Increasing) {
                        if (minf) {
                            inexact = "unboundedness";
                            continue;
                        }
                        inf = true;
                    } else {
                        if (inf) {
                            inexact = "unboundedness";
                            continue;
                        }
                        minf = true;
                    }
                }
                deterministic = false;
                if (monotonicity == Monotonicity::Increasing) {
                    if (!bounds.lowerBounds.empty()) lowerSubs.put(x, *bounds.lowerBounds.begin());
                    if (!bounds.upperBounds.empty()) upperSubs.put(x, *bounds.upperBounds.begin());
                } else {
                    if (!bounds.lowerBounds.empty()) upperSubs.put(x, *bounds.lowerBounds.begin());
                    if (!bounds.upperBounds.empty()) lowerSubs.put(x, *bounds.upperBounds.begin());
                }
            }
        }
        if (deterministic) {
//            std::cout << "deterministic" << std::endl;
            up.put(p.first, p.second);
        } else {
            const option<Expr> lower = minf ? option<Expr>() : p.second.subs(lowerSubs);
            const option<Expr> upper = inf ? option<Expr>() : p.second.subs(upperSubs);
            up.put(p.first, lower, upper);
        }
    }
    auto order = DependencyOrder::findOrder(up);
    if (order) {
        auto res = Recurrence(varMan, *order).iterate(up, rule.getCost());
        if (res) {
            res->inexact = inexact;
            return res;
        }
    }
    auto res = iterateRuleDeterministically(varMan, rule);
    if (res) {
        res->inexact = "determinized";
    }
    return res;
}

option<Recurrence::Result<Subs>> Recurrence::toDeterministic(const Recurrence::Result<NondetUpdate> &res) {
    return res.update.toSubs().map([&](const Subs &subs){return Recurrence::Result<Subs>{res.cost, subs, res.validityBound, res.n, res.inexact};});
}
