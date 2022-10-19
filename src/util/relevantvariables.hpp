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

#pragma once

#include "rule.hpp"

namespace util {

    template <ITheory... Th>
    class RelevantVariables {

        using VS = theory::VarSet<Th...>;
        using S = theory::Subs<Th...>;

    public:

        static const VS find(
                const VS &varsOfInterest,
                const std::vector<S> &updates,
                const BExpr<Th...> guard) {
            VS res = varsOfInterest;
            // Compute the closure of res under all updates and the guard
            VS todo = res;
            while (!todo.empty()) {
                VS next;
                for (const auto &x : todo) {
                    for (const auto &up: updates) {
                        std::visit([&up, &next](const auto &x) {
                            auto it = up.find(x);
                            if (it != up.end()) {
                                expression::collectVars<Th...>(theory::second<Th...>(*it), next);
                            }
                        }, x);
                    }
                    for (const auto &lit: guard->lits()) {
                        VS relVars;
                        literal::collectVars<Th...>(lit, relVars);
                        if (relVars.find(x) != relVars.end()) {
                            for (const auto &x: relVars) {
                                next.insert(x);
                            }
                        }
                    }
                }
                todo.clear();
                for (const auto &var : next) {
                    if (res.find(var) == res.end()) {
                        todo.insert(var);
                    }
                }
                // collect all variables from every iteration
                res.insertAll(todo);
            }
            VS symbols;
            for (const auto &x: res) {
                symbols.insert(x);
            }
            return symbols;
        }

        static const VS find(
                const Conjunction<Th...> &constraints,
                const std::vector<S> &updates,
                const BExpr<Th...> guard) {
            VS varsOfInterest;
            for (const Lit &rel: constraints) {
                varsOfInterest.collectVars(rel);
            }
            return find(varsOfInterest, updates, guard);
        }

        static const VarSet find(
                const Guard &constraints,
                const std::vector<RuleRhs> &rhss,
                const BoolExpr guard) {
            std::vector<Subs> updates;
            for (const RuleRhs &rhs: rhss) {
                updates.push_back(rhs.getUpdate());
            }
            return RelevantVariables::find(constraints, updates, guard);
        }

    };

}
