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
#include "inttheory.hpp"

#include <purrs.hh>

using namespace std;
namespace Purrs = Parma_Recurrence_Relation_Solver;



Recurrence::Recurrence(VarMan &varMan, const std::vector<Var> &dependencyOrder)
    : varMan(varMan),
      ginacN(GiNaC::ex_to<GiNaC::symbol>(Purrs::Expr(Purrs::Recurrence::n).toGiNaC())),
      dependencyOrder(dependencyOrder)
{}

std::optional<Recurrence::RecurrenceSolution<IntTheory>> Recurrence::solve(const NumVar &updateLhs, const Expr &updateRhs, const std::map<Var, unsigned int> &validitybounds) {
    const auto updated = updateRhs.subs(updatePreRecurrences.get<IntTheory>());
    const std::set<NumVar> &vars = updateRhs.vars();
    if (vars.find(updateLhs) == vars.end()) {
        unsigned int validitybound = 1;
        for (const NumVar &x: vars) {
            if (validitybounds.find(x) != validitybounds.end() && validitybounds.at(x) + 1 > validitybound) {
                validitybound = validitybounds.at(x) + 1;
            }
        }
        return {{updated, validitybound}};
    }
    Expr last = Purrs::x(Purrs::Recurrence::n - 1).toGiNaC();
    Purrs::Expr rhs = Purrs::Expr::fromGiNaC(updated.subs(ExprSubs{{updateLhs, last}}).ex);
    Purrs::Expr exact;
    Purrs::Recurrence rec(rhs);
    Purrs::Recurrence::Solver_Status res = Purrs::Recurrence::Solver_Status::TOO_COMPLEX;
    try {
        rec.set_initial_conditions({ {0, Purrs::Expr::fromGiNaC(*updateLhs)} });
        res = rec.compute_exact_solution();
    } catch (...) {
        //purrs throws a runtime exception if the recurrence is too difficult
    }
    if (res == Purrs::Recurrence::SUCCESS) {
        rec.exact_solution(exact);
        return {{exact.toGiNaC(), 0}};
    }
    return {};
}

std::optional<Recurrence::RecurrenceSolution<BoolTheory>> Recurrence::solve(const BoolVar &updateLhs, const BoolExpr &updateRhs, const std::map<Var, unsigned int> &validitybounds) {
    const auto updated = updateRhs->subs(updatePreRecurrences);
    const VarSet &vars = updated->vars();
    if (vars.find(updateLhs) == vars.end() || vars.size() == vars.get<BoolVar>().size()) {
        unsigned int validitybound = 1;
        for (const auto &x: vars) {
            if (validitybounds.find(x) != validitybounds.end() && validitybounds.at(x) + 1 > validitybound) {
                validitybound = validitybounds.at(x) + 1;
            }
        }
        return {{updated, validitybound}};
    }
    return {};
}

std::optional<GiNaC::ex> Recurrence::iterateCost(const Expr &c) {
    const auto cost = c.subs(updatePreRecurrences.get<IntTheory>()); //replace variables by their recurrence equations

    //Example: if cost = y, the result is x(n) = x(n-1) + y(n-1), with x(0) = 0
    Purrs::Expr rhs = Purrs::x(Purrs::Recurrence::n - 1) + Purrs::Expr::fromGiNaC(cost.ex);
    Purrs::Expr sol;

    try {
        Purrs::Recurrence rec(rhs);
        rec.set_initial_conditions({ {0, 0} }); // 0 iterations have 0 costs

        auto res = rec.compute_exact_solution();
        if (res != Purrs::Recurrence::SUCCESS) {
            // try lower bound as fallback, since it is sound to under-approximate costs
            res = rec.compute_lower_bound();
            if (res != Purrs::Recurrence::SUCCESS) {
                return {};
            } else {
                rec.lower_bound(sol);
            }
        } else {
            rec.exact_solution(sol);
        }
    } catch (...) {
        //purrs throws a runtime exception if the recurrence is too difficult
        return {};
    }

    return {sol.toGiNaC()};
}


std::optional<Recurrence::RecurrenceSystemSolution> Recurrence::iterateUpdate(const Subs &update) {
    assert(dependencyOrder.size() == update.size());
    Subs newUpdate;

    //in the given order try to solve the recurrence for every updated variable
    unsigned validityBound = 0;
    std::map<Var, unsigned> validityBounds;
    for (const Var &target : dependencyOrder) {
        int vb = std::visit(
                    Overload{
                        [&](const NumVar &target) {
                            const auto updateRec = solve(target, update.get<IntTheory>(target), validityBounds);
                            if (!updateRec) {
                                return -1;
                            }
                            //remember this recurrence to replace vi in the updates depending on vi
                            //note that updates need the value at n-1, e.g. x(n) = x(n-1) + vi(n-1) for the update x=x+vi
                            updatePreRecurrences.put<IntTheory>(target, updateRec->res.ex.subs({{ginacN, ginacN-1}}));
                            //calculate the final update
                            newUpdate.put<IntTheory>(target, updateRec->res);
                            return static_cast<int>(updateRec->validityBound);
                        },
                        [&](const BoolVar &target) {
                            const auto updateRec = solve(target, update.get<BoolTheory>(target), validityBounds);
                            if (!updateRec) {
                                return -1;
                            }
                            updatePreRecurrences.put<BoolTheory>(target, updateRec->res);
                            newUpdate.put<BoolTheory>(target, updateRec->res);
                            return static_cast<int>(updateRec->validityBound);
                        }
                    }, target);
        if (vb < 0) {
            return {};
        }
        validityBounds[target] = vb;
        validityBound = max(validityBound, static_cast<unsigned>(vb));
    }

    return {{newUpdate, validityBound}};
}

Recurrence::Result::Result(const NumVar &n): n(n) {}

std::optional<Recurrence::Result> Recurrence::iterate(const Subs &update, const Expr &cost) {
    auto newUpdate = iterateUpdate(update);
    if (!newUpdate) {
        return {};
    }
    auto newCost = iterateCost(cost);
    if (!newCost) {
        return {};
    }
    Recurrence::Result res(varMan.addFreshTemporaryVariable<IntTheory>("n"));
    GiNaC::exmap subs {{ginacN, *res.n}};
    for (const auto &p: newUpdate->update.get<IntTheory>()) {
        res.update.put<IntTheory>(p.first, p.second.ex.subs(subs));
    }
    res.update.get<BoolTheory>() = newUpdate->update.get<BoolTheory>();
    res.cost = newCost->subs(subs);
    res.validityBound = newUpdate->validityBound;
    return {res};
}


std::optional<Recurrence::Result> Recurrence::iterateRule(VarMan &varMan, const Rule &rule) {
    // This may modify the rule's guard and update
    auto order = DependencyOrder::findOrder(rule.getUpdate());
    if (!order) {
        return {};
    }

    Recurrence rec(varMan, *order);
    return rec.iterate(rule.getUpdate(), rule.getCost());
}
