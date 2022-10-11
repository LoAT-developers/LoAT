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
#include "theory.hpp"

namespace util {

    const VarSet RelevantVariables::find(
            const Guard &constraints,
            const std::vector<Subs> &updates,
            const BoolExpr guard) {
        VarSet varsOfInterest;
        for (const Lit &rel: constraints) {
            varsOfInterest.insertAll(Th::vars(rel));
        }
        return find(varsOfInterest, updates, guard);
    }

    const VarSet RelevantVariables::find(const VarSet &varsOfInterest, const std::vector<Subs> &updates, const BoolExpr guard) {
        VarSet res = varsOfInterest;
        // Compute the closure of res under all updates and the guard
        VarSet todo = res;
        while (!todo.empty()) {
            VarSet next;
            for (const Var &x : todo) {
                for (const auto &up: updates) {
                    std::visit(Overload{
                                   [&up, &next](const BoolVar &x){
                                       auto it = up.find(x);
                                       if (it != up.getBoolSubs().end()) {
                                           next.insertAll(it->second->vars());
                                       }
                                   },
                                   [&up, &next](const auto &x) {
                                       auto it = up.find(x);
                                       if (it != up.getThSubs().end()) {
                                           next.insertAll(Th::second(*it).vars());
                                       }
                                   }
                               }, x);
                }
                for (const Lit &lit: guard->lits()) {
                    const VarSet &relVars = Th::vars(lit);
                    if (relVars.find(x) != relVars.end()) {
                        for (const auto &x: relVars) {
                            next.insert(x);
                        }
                    }
                }
            }
            todo.clear();
            for (const Var &var : next) {
                if (res.find(var) == res.end()) {
                    todo.insert(var);
                }
            }
            // collect all variables from every iteration
            res.insertAll(todo);
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
        std::vector<Subs> updates;
        for (const RuleRhs &rhs: rhss) {
            updates.push_back(rhs.getUpdate());
        }
        return RelevantVariables::find(constraints, updates, guard);
    }

}
