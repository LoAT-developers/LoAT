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

#include <map>
#include <vector>

#include "theory.hpp"

/**
 * A general rule, consisting of a left-hand side with location, guard and cost
 * and several (but at least one) right-hand sides, each with location and update.
 *
 * The lhs/rhs locations must not (and cannot) be changed, as they are tied to the graph in ITSProblem.
 * The content of the rule (guard/cost/update) may be modified (e.g. via getGuardMut()).
 */
class Rule {
private:
    BoolExpr guard;
    Subs update;
    unsigned id;

    static unsigned next_id;

public:

    Rule(const BoolExpr guard, const Subs &update);

    const BoolExpr getGuard() const;

    template <ITheory Th>
    const typename Th::Subs& getUpdate() const {
        return update.get<Th>();
    }

    const Subs& getUpdate() const;

    Rule subs(const Subs &subs) const;

    Rule withGuard(const BoolExpr guard) const;

    Rule withUpdate(const Subs &up) const;

    VarSet vars() const;

    void collectVars(VarSet &vars) const;

    Rule chain(const Rule &that) const;

    bool isPoly() const;

    auto operator<=>(const Rule &that) const = default;

    unsigned getId() const;

    bool isDeterministic() const;

    size_t hash() const;

};

/**
 * For debugging output (not very readable)
 */
std::ostream& operator<<(std::ostream &s, const Rule &rule);

using TransIdx = const Rule*;
using Implicant = std::pair<TransIdx, BoolExpr>;

std::ostream& operator<<(std::ostream &s, const TransIdx &idx);
std::ostream& operator<<(std::ostream &s, const Implicant &imp);
