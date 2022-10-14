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

#pragma once

#include "option.hpp"
#include "theory.hpp"

/**
 * Functions to compute an ordering on updated variables,
 * such that we can solve recurrences in this order.
 *
 * For an update A := B+C, the recurrences for B and C must be known before
 * we can compute the recurrence for A. So B,C come before A in the ordering.
 *
 * Note that such an ordering does not always exist,
 * e.g., A := B+1, B := A+2.
 */
namespace DependencyOrder {

template <ITheory Th>
struct PartialResult {
    std::vector<typename Th::Var> ordering; // might not contain all variables (hence partial)
    theory::VarSet<Th> ordered; // set of all variables occurring in ordering
};

/**
 * The core implementation.
 * Successively adds variables to the ordering for which all dependencies are
 * already ordered. Stops if this is no longer possible (we are either done
 * or there are conflicting variables depending on each other).
 */
template <ITheory Th>
static void findOrderUntilConflicting(const typename Th::Subs &update, PartialResult<Th> &res) {
    bool changed = true;

    while (changed && res.ordering.size() < update.size()) {
        changed = false;

        for (const auto &up : update) {
            if (res.ordered.find(up.first) != res.ordered.end()) continue;

            //check if all variables on update rhs are already processed
            bool ready = true;
            for (const auto &var : up.second.vars()) {
                if (var != up.first && update.contains(var) && res.ordered.find(var) == res.ordered.end()) {
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


/**
 * Tries to find an order to calculate recurrence equations.
 * Fails if there is a nontrivial set of variables whose updates depend on each other.
 * @return list indicating the order (if successful)
 */
template <ITheory Th>
option<std::vector<typename Th::Var>> findOrder(const typename Th::Subs &update) {
    PartialResult<Th> res;
    findOrderUntilConflicting(update, res);

    if (res.ordering.size() == update.size()) {
        return res.ordering;
    }

    return {};
}

}
