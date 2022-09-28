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

#include "dependencyorder.hpp"

using namespace std;

struct PartialResult {
    std::vector<Var> ordering; // might not contain all variables (hence partial)
    VarSet ordered; // set of all variables occurring in ordering
};


/**
 * The core implementation.
 * Successively adds variables to the ordering for which all dependencies are
 * already ordered. Stops if this is no longer possible (we are either done
 * or there are conflicting variables depending on each other).
 */
static void findOrderUntilConflicting(const ExprSubs &update, PartialResult &res) {
    bool changed = true;

    while (changed && res.ordering.size() < update.size()) {
        changed = false;

        for (const auto &up : update) {
            if (res.ordered.count(up.first) > 0) continue;

            //check if all variables on update rhs are already processed
            bool ready = true;
            for (const Var &var : up.second.vars()) {
                if (var != up.first && update.contains(var) && res.ordered.count(var) == 0) {
                    ready = false;
                    break;
                }
            }

            if (ready) {
                res.ordered.insert(up.first);
                res.ordering.push_back(up.first);
                changed = true;
            }
        }
    }
}

option<vector<Var>> DependencyOrder::findOrder(const ExprSubs &update) {
    PartialResult res;
    findOrderUntilConflicting(update, res);

    if (res.ordering.size() == update.size()) {
        return res.ordering;
    }

    return {};
}
