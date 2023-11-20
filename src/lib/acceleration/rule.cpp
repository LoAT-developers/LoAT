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
#include "expr.hpp"

using namespace std;

unsigned Rule::next_id {0};

Rule::Rule(const BoolExpr guard, const Subs &update): guard(guard), update(update), id(next_id++) {}

void Rule::collectVars(VarSet &vars) const {
    guard->collectVars(vars);
    expr::collectVars(update, vars);
}

VarSet Rule::vars() const {
    VarSet res;
    collectVars(res);
    return res;
}

Rule Rule::subs(const Subs &subs) const {
    return Rule(guard->subs(subs), expr::concat(update, subs));
}

Rule Rule::withGuard(const BoolExpr guard) const {
    return Rule(guard, update);
}

Rule Rule::withUpdate(const Subs &update) const {
    return Rule(guard, update);
}

Rule Rule::chain(const Rule &that) const {
    return Rule(guard & that.getGuard()->subs(update), expr::compose(that.getUpdate(), update));
}

const BoolExpr Rule::getGuard() const {
    return guard;
}

const Subs& Rule::getUpdate() const {
    return update;
}

unsigned Rule::getId() const {
    return id;
}

ostream& operator<<(ostream &s, const Rule &rule) {
    return s << rule.getId() << ": " << rule.getGuard() << " /\\ " << rule.getUpdate();
}

bool Rule::isPoly() const {
    return guard->isPoly() && update.isPoly();
}

bool Rule::isLinear() const {
    return guard->isLinear() && update.isLinear();
}

std::strong_ordering Rule::operator<=>(const Rule &that) const {
    if (id == that.id) {
        return std::strong_ordering::equivalent;
    }
    auto res {guard <=> that.guard};
    if (res != std::weak_ordering::equivalent) {
        return res;
    }
    return update <=> that.update;
}

std::ostream& operator<<(std::ostream &s, const TransIdx &idx) {
    return s << idx->getId();
}

std::ostream& operator<<(std::ostream &s, const Implicant &imp) {
    s << imp.first->getId() << ": ";
    const auto &up {imp.first->getUpdate()};
    if (!imp.second->isTriviallyTrue()) {
        s << imp.second;
        if (!up.empty()) {
            s << " /\\ " << up;
        }
    } else if (!up.empty()) {
        s << up;
    } else {
        s << top();
    }
    return s;
}

bool Rule::isDeterministic() const {
    for (const auto &x: vars()) {
        if (expr::isTempVar(x)) {
            return false;
        }
    }
    return true;
}

size_t Rule::hash() const {
    size_t hash {0};
    boost::hash_combine(hash, std::hash<BoolExpr>{}(guard));
    boost::hash_combine(hash, update.hash());
    return hash;
}
