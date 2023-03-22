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

#include "chainstrategy.hpp"
#include "substitution.hpp"

Subs computeVarRenaming(const Rule &first, const Rule &second, ITSProblem &its) {
    Subs sigma;
    auto first_vars {first.vars()};
    for (const auto &x: second.vars()) {
        if (its.isTempVar(x) && first_vars.find(x) != first_vars.end()) {
            if (std::holds_alternative<NumVar>(x)) {
                const auto &var = std::get<NumVar>(x);
                sigma.put<IntTheory>(var, its.addFreshTemporaryVariable<IntTheory>(var.getName()));
            } else if (std::holds_alternative<BoolVar>(x)) {
                const auto &var = std::get<BoolVar>(x);
                sigma.put<BoolTheory>(var, BExpression::buildTheoryLit(its.addFreshTemporaryVariable<BoolTheory>(var.getName())));
            }
        }
    }
    return sigma;
}

ResultViaSideEffects Chaining::chainLinearPaths(ITSProblem &its) {
    ResultViaSideEffects res;
    for (const auto first_idx: its.getAllTransitions()) {
        const auto succ {its.getSuccessors(first_idx)};
        if (succ.size() == 1 && succ.find(first_idx) == succ.end()) {
            const auto second_idx {*succ.begin()};
            const auto &first {its.getRule(first_idx)};
            auto second {its.getRule(second_idx)};
            const auto chained {chain(first, second, its)};
            res.succeed();
            res.chainingProof(first, second, chained);
            its.addRule(chained, first_idx, second_idx);
            its.removeRule(first_idx);
            res.deletionProof({first_idx});
        }
    }
    return res;
}

Rule Chaining::chain(const Rule &fst, const Rule &snd, ITSProblem &its) {
    const auto sigma {computeVarRenaming(fst, snd, its)};
    const auto guard {fst.getGuard() & snd.getGuard()->subs(substitution::compose(sigma, fst.getUpdate()))};
    const auto up {substitution::compose(substitution::concat(snd.getUpdate(), sigma), fst.getUpdate())};
    return Rule(guard, up);
}
