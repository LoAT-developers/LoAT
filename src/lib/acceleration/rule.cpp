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

#include "rule.hpp"
#include "substitution.hpp"

using namespace std;

Rule::Rule(const BoolExpr guard, const Subs &update): guard(guard), update(update) {}

void Rule::collectVars(VarSet &vars) const {
    guard->collectVars(vars);
    substitution::collectVars(update, vars);
}

VarSet Rule::vars() const {
    VarSet res;
    collectVars(res);
    return res;
}

Rule Rule::subs(const Subs &subs) const {
    return Rule(guard->subs(subs), substitution::concat(update, subs));
}

Rule Rule::withGuard(const BoolExpr guard) const {
    return Rule(guard, update);
}

Rule Rule::withUpdate(const Subs &update) const {
    return Rule(guard, update);
}

Rule Rule::chain(const Rule &that) const {
    return Rule(guard & that.getGuard()->subs(update), substitution::compose(that.getUpdate(), update));
}

unsigned Rule::hash() const {
    unsigned hash = 7;
    hash = hash * 31 + guard->hash();
    hash = hash * 31 + update.hash();
    return hash;
}

ostream& operator<<(ostream &s, const Rule &rule) {
    return s << rule.getGuard() << " /\\ " << rule.getUpdate();
}
