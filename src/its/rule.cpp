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

using namespace std;


Rule::Rule(RuleLhs lhs, RuleRhs rhs) : lhs(lhs), rhs(rhs) {
    if (getCost().isNontermSymbol()) {
        rhs = {RuleRhs(rhs.getLoc(), {})};
    }
}

Rule::Rule(LocationIdx lhsLoc, BoolExpr guard, Expr cost, LocationIdx rhsLoc, Subs update)
        : lhs(lhsLoc, guard, cost), rhs(RuleRhs(rhsLoc, update)) {
    if (getCost().isNontermSymbol()) {
        rhs = {RuleRhs(rhs.getLoc(), {})};
    }
}

void Rule::collectVars(VarSet &vars) const {
    lhs.collectVars(vars);
    rhs.collectVars(vars);
}

VarSet Rule::vars() const {
    VarSet res;
    collectVars(res);
    return res;
}

Rule Rule::dummyRule(LocationIdx lhsLoc, LocationIdx rhsLoc) {
    return Rule(lhsLoc, {}, 0, rhsLoc, {});
}

bool Rule::isDummyRule() const {
    return getCost().isZero() && getGuard() == True && getUpdate().empty();
}

bool Rule::isSimpleLoop() const {
    return rhs.getLoc() == lhs.getLoc();
}

Rule Rule::subs(const Subs &subs) const {
    return Rule(RuleLhs(getLhsLoc(), getGuard()->subs(subs), getCost().subs(subs.get<IntTheory>())), RuleRhs(rhs.getLoc(), substitution::concat(rhs.getUpdate(), subs)));
}

Rule Rule::replaceRhsBySink(LocationIdx sink) const {
    return Rule(getLhs(), RuleRhs(sink, {}));
}

Rule Rule::withGuard(const BoolExpr guard) const {
    return Rule(RuleLhs(getLhsLoc(), guard, getCost()), getRhs());
}

Rule Rule::withCost(const Expr &cost) const {
    return Rule(RuleLhs(getLhsLoc(), getGuard(), cost), getRhs());
}

Rule Rule::withUpdate(const Subs &up) const {
    return Rule(RuleLhs(getLhsLoc(), getGuard(), getCost()), RuleRhs(rhs.getLoc(), up));
}

unsigned Rule::hash() const {
    unsigned hash = 7;
    hash = hash * 31 + lhs.hash();
    hash = hash * 31 + rhs.hash();
    return hash;
}

bool operator ==(const RuleRhs &fst, const RuleRhs &snd) {
    return fst.getLoc() == snd.getLoc() && fst.getUpdate() == snd.getUpdate();
}

ostream& operator<<(ostream &s, const Rule &rule) {
    s << "Rule(";

    // lhs (loc, guard, cost)
    s << rule.getLhsLoc() << " | ";
    s << rule.getGuard();
    s << "| ";
    s << rule.getCost();

    // rhs (loc, update)*
    s << " |";

    s << "| " << rule.getRhs().getLoc() << " | ";
    s << rule.getRhs().getUpdate();

    s << ")";
    return s;
}
