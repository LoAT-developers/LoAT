/*  This file is part of LoAT.
 *  Copyright (c) 2019 Florian Frohn
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

#include "relevantvariables.hpp"

namespace util {

    const VarSet RelevantVariables::find(
            const Guard &constraints,
            const std::vector<ExprSubs> &updates,
            const BoolExpr guard) {
        VarSet varsOfInterest;
        for (const Rel &rel: constraints) {
            const VarSet &relVars = rel.vars();
            varsOfInterest.insert(relVars.begin(), relVars.end());
        }
        return find(varsOfInterest, updates, guard);
    }

    const VarSet RelevantVariables::find(const VarSet &varsOfInterest, const std::vector<ExprSubs> &updates, const BoolExpr guard) {
        VarSet res;
        for (const Var &sym : varsOfInterest) {
            res.insert(sym);
        }
        // Compute the closure of res under all updates and the guard
        VarSet todo = res;
        while (!todo.empty()) {
            VarSet next;
            for (const Var &x : todo) {
                for (const auto &up: updates) {
                    auto it = up.find(x);
                    if (it != up.end()) {
                        const VarSet &rhsVars = it->second.vars();
                        next.insert(rhsVars.begin(), rhsVars.end());
                    }
                }
                for (const Rel &rel: guard->lits()) {
                    const VarSet &relVars = rel.vars();
                    if (relVars.find(x) != relVars.end()) {
                        next.insert(relVars.begin(), relVars.end());
                    }
                }
            }
            todo.clear();
            for (const Var &var : next) {
                if (res.count(var) == 0) {
                    todo.insert(var);
                }
            }
            // collect all variables from every iteration
            res.insert(todo.begin(), todo.end());
        }
        VarSet symbols;
        for (const Var &x: res) {
            symbols.insert(x);
        }
        return symbols;
    }


    const VarSet RelevantVariables::find(
            const Guard &constraints,
            const std::vector<RuleRhs> &rhss,
            const BoolExpr guard) {
        std::vector<ExprSubs> updates;
        for (const RuleRhs &rhs: rhss) {
            updates.push_back(rhs.getUpdate().getExprSubs());
        }
        return RelevantVariables::find(constraints, updates, guard);
    }

}
