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


option<Recurrence::RecurrenceSolution> Recurrence::findUpdateRecurrence(const Expr &updateRhs, Var updateLhs, const VarMap<unsigned int> &validitybounds) {
    Expr last = Purrs::x(Purrs::Recurrence::n - 1).toGiNaC();
    Purrs::Expr rhs = Purrs::Expr::fromGiNaC(updateRhs.subs(updatePreRecurrences).subs(Subs(updateLhs, last)).ex);
    Purrs::Expr exact;

    const VarSet &vars = updateRhs.vars();
    if (vars.find(updateLhs) == vars.end()) {
        unsigned int validitybound = 1;
        for (const Var &x: vars) {
            if (validitybounds.find(x) != validitybounds.end() && validitybounds.at(x) + 1 > validitybound) {
                validitybound = validitybounds.at(x) + 1;
            }
        }
        return {{updateRhs.subs(updatePreRecurrences), validitybound}};
    }
    Purrs::Recurrence rec(rhs);
    Purrs::Recurrence::Solver_Status res = Purrs::Recurrence::Solver_Status::TOO_COMPLEX;
    try {
        rec.set_initial_conditions({ {0, Purrs::Expr::fromGiNaC(updateLhs)} });
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


option<Expr> Recurrence::iterateCost(const Expr &c) {
    Expr cost = c.subs(updatePreRecurrences); //replace variables by their recurrence equations

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

    return {Expr(sol.toGiNaC())};
}


option<Recurrence::RecurrenceSystemSolution> Recurrence::iterateUpdate(const Subs &update) {
    assert(dependencyOrder.size() == update.size());
    Subs newUpdate;

    //in the given order try to solve the recurrence for every updated variable
    unsigned int validityBound = 0;
    VarMap<unsigned int> validityBounds;
    for (Var target : dependencyOrder) {
        const Expr &rhs = update.get(target);
        option<Recurrence::RecurrenceSolution> updateRec = findUpdateRecurrence(rhs, target, validityBounds);
        if (!updateRec) {
            return {};
        }

        validityBounds[target] = updateRec.get().validityBound;
        validityBound = max(validityBound, updateRec.get().validityBound);

        //remember this recurrence to replace vi in the updates depending on vi
        //note that updates need the value at n-1, e.g. x(n) = x(n-1) + vi(n-1) for the update x=x+vi
        updatePreRecurrences.put(target, updateRec.get().res.subs(Subs(ginacN, ginacN-1)));

        //calculate the final update using the loop's runtime
        newUpdate.put(target, updateRec.get().res);
    }

    return {{newUpdate, validityBound}};
}

option<Recurrence::Result> Recurrence::iterate(const Subs &update, const Expr &cost) {
    auto newUpdate = iterateUpdate(update);
    if (!newUpdate) {
        return {};
    }

    auto newCost = iterateCost(cost);
    if (!newCost) {
        return {};
    }

    Recurrence::Result res;
    res.n = varMan.addFreshTemporaryVariable("n");
    Subs subs = {ginacN, res.n};
    res.cost = newCost.get().subs(subs);
    res.update = newUpdate.get().update.compose(subs);
    res.validityBound = newUpdate.get().validityBound;
    return {res};
}


option<Recurrence::Result> Recurrence::iterateRule(VarMan &varMan, const LinearRule &rule) {
    // This may modify the rule's guard and update
    auto order = DependencyOrder::findOrder(rule.getUpdate());
    if (!order) {
        return {};
    }

    Recurrence rec(varMan, order.get());
    return rec.iterate(rule.getUpdate(), rule.getCost());
}

